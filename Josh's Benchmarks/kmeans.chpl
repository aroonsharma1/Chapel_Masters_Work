use CyclicZipOptAroon;
use BlockDist;
use Random;
use Time;
use CommDiagnostics;

//
// parameter and type declarations: these are set at compile time;
// numdims can be overridden on the compiler's command-line
//
config param numdims = 2;          // the number of dimensions for our points

type coord = numdims*real;         // use numdims-tuples of reals as coords

//
// configuration constants: these can be overridden at execution time
//
config const n = 10,               // the number of points
             k = 3,                // the number of centers
             thresh = 1e-4;        // the threshold for termination
             
config var dist: string = "CM";

config const debug = false;        // controls debug printing

/*config const seed = SeedGenerator.clockMS;*/
config const seed = 5;

config var printData = false;

/* The process which runs the benchmark */
proc kernel_kmeans(dataSpace, centerSpace, centerClusterSpace, centerOffsetSpace) {
    //
    // the main computation
    //
    var t:Timer;
    var prevError = 0.0,      // the error from the previous iteration
        numIters = 0;         // the number of iterations required
        
    var data: [dataSpace] coord = [i in dataSpace] initData(i);
    var centers: [centerSpace] coord = initCenters(data, dataSpace);
    
    //
    // Print initial locations
    //
    if (printData) {
/*        writeln("data points are at: ", data);
        writeln("initial centers are: ", centers);*/
    }
    
    resetCommDiagnostics();
    startCommDiagnostics();
    t.start();
    do {
      if debug then writeln("centers are: ", centers);
      //
      // compute the error of the current solution and the offsets for the
      // new solution
      //
  
      var error:real;
      var clusterSize: [centerClusterSpace] int;
      var offsets: [centerOffsetSpace] coord;
      var lock: sync bool;
  
      forall i in dataSpace {    
          var d = data(i);
          var x = findBestCenter(d, centers, centerSpace);
          var ind = x(2);
          lock = true;
          error += x(1);
          clusterSize(ind) += 1;
          offsets(ind) += (d - centers(ind));
          var unlock = lock;
      }
  
      forall (a,b) in zip(offsets, clusterSize) {
          a = a / b;
      }

      centers += offsets;   // update the centers using the computed offsets

      if debug then writeln("error is: ", error);

      prevError <=> error;  // swap the error and previous error for the next iter

      numIters += 1;        // increment the number of iterations
    } while (abs(error - prevError) > thresh);
    
    stopCommDiagnostics();
    t.stop();

    //
    // Print the result
    //
    if (printData) {
        writeln("converged to < ", thresh, " in ", numIters, " iterations");
        writeln("final centers are: ", centers);
    }
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}

//
// helper function to find the best center for a given coordinate
//
proc findBestCenter(loc: coord, centers: [] coord, centerSpace) {
  return minloc reduce zip(distance(loc, centers), centerSpace);
}

//
// helper function to compute the distance between two coordinates
//
proc distance(x: coord, y:coord): real {
  return sqrt(+ reduce [d in 1..numdims] ((x(d) - y(d))**2));
}

//
// a helper function that, for now, initializes data element i to be
// (i, 0.0, 0.0, 0.0, ...)
//
proc initData(i) {
  var loc: coord;
  var rand = new RandomStream(seed);
  loc(1) = i;
  return loc;
}

//
// compute the initial centers by taking every ceil(n/k)-th element from data[]
//
proc initCenters(data, dataSpace) {
  return data[dataSpace by intCeilDiv(n,k)];
}

//
// a helper function to divide a coordinate by a floating point value
//
proc /(x: coord, y: real) {
  var result: coord;
  for param d in 1..numdims do
    result(d) = x(d) / y;
  return result;
}

//
// a helper function that computes the integer ceiling of x/y
//
proc intCeilDiv(x: integral, y: integral) {
  return (x + (y-1)) / y;
}

proc main() {
    //
    // make sure k is positive because we divide by it
    //
    assert(k > 0, "k must be positive");

    //
    // the index space and array for the data elements
    //
    const dom1 = {1..n};
    
    //
    // the index space and array for the cluster centers
    //
    const dom2 = {1..k};
    
    if dist == "NONE" {
        const dataSpace = dom1;
        const centerSpace = dom2;
        const centerClusterSpace = dom2;
        const centerOffsetSpace = dom2;
        kernel_kmeans(dataSpace, centerSpace, centerClusterSpace, centerOffsetSpace); 
    } else if dist == "CM" {
        const dataSpace = dom1 dmapped CyclicZipOpt(startIdx=dom1.low);
        const centerSpace = dom2 dmapped CyclicZipOpt(startIdx=dom2.low);
        const centerClusterSpace = dom2 dmapped CyclicZipOpt(startIdx=dom2.low + 1);
        const centerOffsetSpace = dom2 dmapped CyclicZipOpt(startIdx=dom2.low + 2);
        kernel_kmeans(dataSpace, centerSpace, centerClusterSpace, centerOffsetSpace); 
    } else if dist == "C" {
        const dataSpace = dom1 dmapped Cyclic(startIdx=dom1.low);
        const centerSpace = dom2 dmapped Cyclic(startIdx=dom2.low);
        const centerClusterSpace = dom2 dmapped Cyclic(startIdx=dom2.low + 1);
        const centerOffsetSpace = dom2 dmapped Cyclic(startIdx=dom2.low + 2);
        kernel_kmeans(dataSpace, centerSpace, centerClusterSpace, centerOffsetSpace); 
    } else if dist == "B" {
        const dataSpace = dom1 dmapped Block(boundingBox=dom1);
        const centerSpace = dom2 dmapped Block(boundingBox=dom2);
        const centerClusterSpace = dom2 dmapped Block(boundingBox=dom2);
        const centerOffsetSpace = dom2 dmapped Block(boundingBox=dom2);
        kernel_kmeans(dataSpace, centerSpace, centerClusterSpace, centerOffsetSpace); 
    }       
}