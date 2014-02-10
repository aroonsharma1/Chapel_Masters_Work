// 
// This test is pulled from intern ii02 in the codes written in the 
// Summer of 2011 to measure increase in productivity using Chapel 
// versus C/MPI.It is a pared down version of the Locally Self-consistent
// Multiple Scattering (LSMS) application. Adapted from the Chapel trunk.
//
use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

config const debug = false;
config const reportFrequency = 1025;
config const perfTest = false;
config const displayLIZ = false;

config var dist: string = "CM";

config const span = 5;

const span_x = span,
	  span_y = span,
	  span_z = span,
	  nAtoms = span_x * span_y * span_z,
	  spanT  = (span, span, span);

config
const atomSpacing = 5.000, //spacing in X, Y, and Z
	  lizRadius   = 7.110, //radius of LIZ sphere
	  nIterations = 10;
/*      nIterations = 1024;*/

const reductionFactor = 1000.0;

param nExtent = 13;
type AtomMatrix = nExtent*real;

proc checkExpected(itr: int, gridDist1) {
    var atoms: [gridDist1] AtomMatrix;
	if span != 5 || nIterations != 1024 {
		writeln("Expected value check disabled...");
		return;
	}
	const first = gridDist1.low,
		  last  = gridDist1.high;

	var ExpectedDom: sparse subdomain(gridDist1);
	ExpectedDom += first; ExpectedDom += last;
	
	var expectedValues: [ExpectedDom] real;
	if itr == 0 {
		expectedValues[first] = 0.775;
		expectedValues[last]  = 125.5;
	} else {
		expectedValues[first] = 5320018409.9;
		expectedValues[last]  = 5324998555.3;
	}

	for i in ExpectedDom {
		var tolerance = max(expectedValues[i] * 1e-9, 0.1);
		var pass = true;
		for param e in 1..nExtent {
			if abs(atoms[i][e] - expectedValues[i]) > tolerance then pass = false;
		}
		if debug { writeln("itr ", format("%4d",itr), " @ ", i, ": ", 
				           format("%12.9g",atoms[i][1]), " ~=~ ", 
						   format("%12.9g",expectedValues[i])); }
		if !pass {
			writeln("Computed values do not match expected values: itr = ", itr, 
					" @ ", i, ": ", atoms[i][1], " != ", expectedValues[i]);
			exit(0);
		} 
	}
}

proc circularDistance(a, b, size: int) {
	if a < b {
		return min(a+size-b, b-a);
	} else {
		return min(a-b, b-a+size);
	}
}

proc kernel_lsms(gridDist1, gridDist2) {
	writeln("[[ LSMS ]]");
	writeln("Problem size = [", span_x, ", ", span_y, ", ", span_z, "]");
    
	var lizDoms: [gridDist1] sparse subdomain(gridDist1);
    for (a, liz, i) in zip(gridDist1, lizDoms, 0..) {
        for ac in gridDist1 do if a != ac {
            //compute dist between 2 points
            var diff: 3*int;
            for param d in 1..3 do diff[d] = circularDistance(a[d], ac[d], spanT[d]);
            var dist = atomSpacing * sqrt(diff[1]**2 + diff[2]**2 + diff[3]**2);
            if dist <= lizRadius {
/*                write(lizDoms[i,i,i]);
                lizDoms[i,i,i] += ac;*/
                liz += ac;
/*                writeln(liz);
                writeln();
                writeln();
                writeln();*/
            }
        }
    }
    
	//calculate Local Interaction Zones

/*    writeln(GridDist);
    writeln();
    writeln(lizDoms);*/
/*    writeln(lizDoms);*/
    
/*    forall (i,j,k) in GridDist {
        var temp: [1..span] {0..#span_x, 0..#span_y, 0..#span_z};
        forall (a, b, c, d) in zip(GridDist[i, j, ..], GridDist[i, .., k], GridDist[.., j, k], 0..) {
            temp[d] = a + b +c;
            writeln(a);
        }
        lizDoms[i,j,k] = (+ reduce (temp));
    }*/
    
	if displayLIZ then writeln("LIZ counts: ", [liz in lizDoms] liz.numIndices);

	//initialize atoms
	var atoms: [gridDist1] AtomMatrix;
/*    forall (i,j,k) in GridDist {
        var temp: [1..span] real;
        forall (a, b, c, d) in zip(GridDist[i,j,0..span_z], GridDist[i, 0..span_y, k], GridDist[0..span_x, j, k], 1..) {
            temp[d] = a + b +c;
        }
        lizDoms[i,j,k] = (+ reduce (temp));
    }*/
	forall (i, atom) in zip(gridDist1, atoms) {
		for param e in 1..nExtent do atom[e] = gridDist1.indexOrder(i);
	}

	for itr in 0..#nIterations {
		if itr % reportFrequency == 0 && reportFrequency <= nIterations {
			writeln("step ", format("####", itr), "...");
		}
		
		//each atom adds up extent values from neighbors (members of its liz sphere)
		var totals: [gridDist2] AtomMatrix;
		forall (liz, total, i) in zip(lizDoms, totals, gridDist1) {
			for ac in liz {
				total += atoms[ac];
			}
		}
		for a in gridDist1 {
			for param e in 1..nExtent {
				atoms[a][e] += totals[a][e] / reductionFactor;
			}
		}
		
		if itr == 0 || itr == nIterations-1 {
			checkExpected(itr, gridDist1);
		}
	}
}

proc main() {
    var t:Timer;
    
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    /* Initialize the data */
    const gridDom = {0..#span_x, 0..#span_y, 0..#span_z};
    const gridDist1  = gridDom dmapped CyclicZipOpt(startIdx=gridDom.low);
    const gridDist2 = gridDom dmapped CyclicZipOpt(startIdx=gridDom.low + 1);
    
    if dist == "NONE" {
        var gridDist1 = gridDom;
        var gridDist2 = gridDom;
        
        /* Run the benchmark */
        kernel_lsms(gridDist1, gridDist2); 
    } else if dist == "CM" {
        var gridDist1 = gridDom dmapped CyclicZipOpt(startIdx=gridDom.low);
        var gridDist2 = gridDom dmapped CyclicZipOpt(startIdx=gridDom.low + 1);
        kernel_lsms(gridDist1, gridDist2);  
    } else if dist == "C" {
        var gridDist1 = gridDom dmapped Cyclic(startIdx=gridDom.low);
        var gridDist2 = gridDom dmapped Cyclic(startIdx=gridDom.low + 1);
        kernel_lsms(gridDist1, gridDist2); 
    } else if dist == "B" {
        var gridDist1 = gridDom dmapped Block(boundingBox=gridDom);
        var gridDist2 = gridDom dmapped Block(boundingBox=gridDom);
        kernel_lsms(gridDist1, gridDist2); 
    }       
    
    t.stop();
    stopCommDiagnostics();
    
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}

