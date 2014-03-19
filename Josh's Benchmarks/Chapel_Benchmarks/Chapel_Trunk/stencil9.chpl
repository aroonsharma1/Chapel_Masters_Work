use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

config const n = 10;

config const epsilon = 0.01;

config const printArrays = false;

config var dist: string = "CM";

proc kernel_stencil9(dist_little, dist_big) {
    const northWest = {0..n-1, 0..n-1}, north = {0..n-1, 1..n}, northEast = {0..n-1, 2..n+1};
    const west = {1..n, 0..n-1}, center = {1..n, 1..n}, east = {1..n, 2..n+1};
    const southWest = {2..n+1, 0..n-1}, south = {2..n+1, 1..n}, southEast = {2..n+1, 2..n+1};

    var A, B: [dist_big] real;

    A[  n/4+1,   n/4+1] =  1.0;
    A[3*n/4+1, 3*n/4+1] =  1.0;
    A[  n/4+1, 3*n/4+1] = -1.0;
    A[3*n/4+1,   n/4+1] = -1.0;

    if printArrays then
      writeln("Initial A:\n", A[dist_little], "\n");

    var numIters = 0;

    do {
      numIters += 1;

      forall (a,b,c,d,e) in zip (B(dist_little), A(northWest), A(northEast), A(southWest), A(southEast)) {
          a = ((.0625)*(b+c+d+e));
      }
  
      forall(a,b,c,d,e,f) in zip(B(dist_little), A(north), A(west), A(south), A(east), A(center)){
          a += ((.125)*(b+c+d+e) + (.25)*(f));
      }

      const delta = max reduce fabs(B - A);

      B <=> A;

     } while (delta > epsilon);

    if printArrays then
      writeln("Final A:\n", A[dist_little]);

    writeln("# iterations: ", numIters);
}

proc main() {
    
    const    Dom = {1..n  , 1..n},
          BigDom = {0..n+1, 0..n+1};
          
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        const dist_little = Dom;
        const dist_big = BigDom;
        kernel_stencil9(dist_little, dist_big); 
    } else if dist == "CM" {
        const dist_little = Dom dmapped CyclicZipOpt(startIdx=Dom.low);
        const dist_big = BigDom dmapped CyclicZipOpt(startIdx=BigDom.low);
        kernel_stencil9(dist_little, dist_big);
    } else if dist == "C" {
        const dist_little = Dom dmapped Cyclic(startIdx=Dom.low);
        const dist_big = BigDom dmapped Cyclic(startIdx=BigDom.low);
        kernel_stencil9(dist_little, dist_big); 
    } else if dist == "B" {
        const dist_little = Dom dmapped Block(boundingBox=Dom);
        const dist_big = BigDom dmapped Block(boundingBox=BigDom);
        kernel_stencil9(dist_little, dist_big); 
    }      
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics()); 
}