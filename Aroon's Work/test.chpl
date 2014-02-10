use CyclicZipOptAroon;
use MyBlockCyclic;
use BlockDist;
use Time;
use CommDiagnostics;

config var size=2;	//size of the array
config var dist_string: string = "CM";

var mydom = {1..size, 1..size};

if dist_string == "CM" {
	var mydist = mydom dmapped CyclicZipOpt(startIdx=mydom.low);
	kernel_2mm(mydist);	
}
else if dist_string == "C" {
	var mydist = mydom dmapped Cyclic(startIdx=mydom.low);
	kernel_2mm(mydist);
}
else if dist_string == "BC" {
	var mydist = mydom dmapped MyBlockCyclic(startIdx=mydom.low);
	kernel_2mm(mydist);
}


proc kernel_2mm(dist) {
    var t:Timer;

	var A: [dist] int = 1;
	var B: [dist] int = 2;
	var C: [dist] int = 0;


	writeln("\nA:");
	writeln(A);
	writeln("\nB:");
	writeln(B);

    /******* Start the timer: this is where we do work *******/
    t.start();
	resetCommDiagnostics();
	startCommDiagnostics();
	
	forall (i,j) in dist {
		var tempArray: [1..size] int;
		forall (a, b, i) in zip(A[i, 1..size], B[1..size, j], 1..) {
			var temp = a * b;
			tempArray[i] = temp;
		}
		C[i, j] = (+ reduce (tempArray));
	}
	
	stopCommDiagnostics();
    t.stop();
    /******* End the timer *******/

	writeln("\nC:");
	writeln(C);	
	writeln(t.elapsed(), " seconds elapsed"); 
	writeln(getCommDiagnostics());
	writeln("number of gets = " + chpl_numCommGets());
	writeln("number of puts = " + chpl_numCommPuts());
}


