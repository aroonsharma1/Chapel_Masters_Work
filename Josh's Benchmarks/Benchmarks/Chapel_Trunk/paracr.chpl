/*********************************************************/
/*		ParaCR algorithm in Chapel               */		
/*	Loop unrolled to avoid a deep copy of arrays     */
/* Contributed by Juan Lopez, Alberto Sanz & Rafa Asenjo */
/*********************************************************/

//This code solves a dense tridiagonal system following the PARACR algorithm
use Time;
use BlockDist;
use CyclicZipOpt;
use CommDiagnostics;

//Problem Dimension
config const n:int=16;
config var verbose: bool = false;
config var timeit = false;
config var messages = false;
config var dist: string = "CM";

var stages:int= GetNumStages(n);
writeln("Stages->",stages);

var error:int=0;

config const timer : bool =false;

proc kernel_paracr(Dist1, Dist2, Dstages) {
    var AA,BB,CC,DD: [Dist1] real;
    var A,B,C,D,X: [Dist2] real;
    
    SetExampleMatrix(A, B, C, D);
  
    if (n == 1) {
        X(1) = D(1)/B(1);
        writeln("Done!!. Too easy... bye");
        exit(0);
    }

    /*********************/
    /* Elimination Phase */
    /*********************/
  
    //Unrolled loop: it does two iterations (stages) in the body
    for j in 1..stages-1 by 2 do { 
    //  Odd stage (j)
        ComputeStage(AA,BB,CC,DD,A,B,C,D,j, Dist1);
    //  Even stage (j+1)
        ComputeStage(A,B,C,D,AA,BB,CC,DD,j+1, Dist1);
    }

    if(stages&1) { //If odd number of stages there is one more odd stage missing
        ComputeStage(AA,BB,CC,DD,A,B,C,D,stages, Dist1);
    }

    /**********************/
    /* Substitution Phase */
    /**********************/
	
    if (stages & 1) { //If odd number of stages, diagonal is in BB and RHS in DD
        forall (x,d,b) in zip(X,DD,BB) do x = d/b;
    }
    else { //else, diagonal is in B and RHS in D
        forall (x,d,b) in zip(X,D,B) do x = d/b;
    }
	
    if verbose {
        writeln("Tridiagonal System Solution:");
        PrintV(X, Dist1);
        SetExampleMatrix(A,B,C,D);
        //PrintV(D);
        Check(A,B,C,D, X, Dist1);	 
  
        if (error != 1) {
            writeln("Done!");
        } else {
            writeln("WRONG!!");
        }
    }
}

proc ComputeStage(A,B,C,D,AA,BB,CC,DD,j, Dist1) {
  const TtS:int=1<<(j-1); // TtS stand for "Two to the Stage (minus 1)" which is = 2**(j-1)
  forall (a, aa, b, bb, c, cc, d, dd, i) in zip(A, AA, B, BB, C, CC, D, DD, Dist1) {
      const lo=i-TtS;
      const hi=i+TtS;
      
      if (lo < 1) then {
        if (hi > n) then { // Case 1: out of lower and upper range
  	        a = 0;
  	        b = bb;
  	        c = 0;
  	        d = dd;
        } else { // Case 2: out of lower range
  	        const c_const = cc, bh = BB(hi);		
  	        a = 0;
  	        b = (bb - (c_const*AA(hi)/bh));
  	        c = (-c_const*CC(hi))/bh;
  	        d = dd - (DD(hi)*c_const)/bh;
        }
      } else {
        if (hi > n) then { // Case 3: out of upper range
  	        const a_const = aa, bl = BB(lo);	
  	        a = (-AA(lo)*a_const)/bl;
  	        b = (bb - (CC(lo) * a_const/bl));
  	        c = 0;
  	        d = dd - (a_const*DD(lo))/bl;
        } else { // Case 4: no equation out of range
  	        const a_const=aa,bh=BB(hi),bl=BB(lo),c_const=cc;
  	        a = (-AA(lo)*a_const)/bl;
  	        b = (bb - (CC(lo)*a_const/bl) - (c_const*AA(hi)/bh));
  	        c = (-c_const*CC(hi))/bh;
  	        d = dd - (a_const*DD(lo))/bl - (DD(hi)*c_const)/bh;
        }
      }
    }
}

proc Check(A,B,C,D, X, Dist1) {
    var ERROR: real = 0.00001;
    forall i in Dist1 {
        if (i==1) {
            if (abs(B[i]*X[i] + C[i]*X[i+1] - D[i]) > ERROR) {
                writeln("Case 1 failed"); error = 1;
            }
        } else if (i==n) {
            if (abs(A[i]*X[i-1] + B[i]*X[i] - D[i]) > ERROR) {
                writeln("Case 2 failed"); error = 1;
            }
        } else {
            if(abs(A[i]*X[i-1] + B[i]*X[i] + C[i]*X[i+1]-D[i]) > ERROR) { 
                writeln("Case 3 failed"); 
                error = 1;
            }
        }
    }
}

proc PrintV(X, Dist1) {
  for i in Dist1 do{
    writeln("V[",i,"] = ",X(i));
  }
}

proc SetExampleMatrix(A, B, C, D) {
    A=1.0;
    B=2.0;
    C=1.0;
    A(1)=0;C(n)=0;
    
    forall i in 1..(n+1)/2 do {
        D(i)=i;
        D(n-i+1)=i;
    }
}

proc GetNumStages(n: int) {
  if n-2**log2(n) != 0 then
    return (log2(n)+1);
  else
    return log2(n);
}

proc main() {
    const Space = {1..n};
    var domStages: domain(1, int)= {1..stages};

    var t: Timer;

    /* Start the timer */
	if timeit {
	    t.start();
	}
    
	if messages {
	    resetCommDiagnostics();
	    startCommDiagnostics();	
	}
	
    if dist == "NONE" {
        const Dist_1 = Space;
        const Dist_2 = Space;
        var DStages = domStages;
        kernel_paracr(Dist_1, Dist_2, DStages); 
    } else if dist == "CM" {
        const Dist_1 = Space dmapped CyclicZipOpt(startIdx=Space.low);
        const Dist_2 = Space dmapped CyclicZipOpt(startIdx=Space.low + 1);
        var DStages = domStages dmapped CyclicZipOpt(startIdx=domStages.low);
        kernel_paracr(Dist_1, Dist_2, DStages); 
    } else if dist == "C" {
        const Dist_1 = Space dmapped Cyclic(startIdx=Space.low);
        const Dist_2 = Space dmapped Cyclic(startIdx=Space.low + 1);
        var DStages = domStages dmapped Cyclic(startIdx=domStages.low);
        kernel_paracr(Dist_1, Dist_2, DStages); 
    } else if dist == "B" {
        const Dist_1 = Space dmapped Block(boundingBox=Space);
        const Dist_2 = Space dmapped Block(boundingBox=Space);
        var DStages = domStages dmapped Block(boundingBox=domStages);
        kernel_paracr(Dist_1, Dist_2, DStages); 
    }      
    
	if timeit {
	    t.stop();   
	    writeln(t.elapsed(), " seconds elapsed");
	}
	
	//Print out communication counts (gets and puts)
	if messages {
		stopCommDiagnostics();	
		var messages=0;
		var coms=getCommDiagnostics();
		for i in 0..numLocales-1 {
			messages+=coms(i).get:int;
			messages+=coms(i).put:int;
		}
		writeln('message count=', messages);
	}
}