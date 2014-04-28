use CyclicZipOptAroon;
use MyBlockCyclic;
use BlockDist;
use Time;
use CommDiagnostics;

config var size=9;	//size of the array
config var dist_string: string = "CM";
config var zippered = false;
config var printMatrices = false;

var mydom = {1..size, 1..size};

if dist_string == "CM" {
	var mydist = mydom dmapped CyclicZipOpt(startIdx=mydom.low);
	kernel_2mm(mydist);	
}
else if dist_string == "C" {
	var mydist = mydom dmapped Cyclic(startIdx=mydom.low);
	kernel_2mm(mydist);
}
else if dist_string == "B" {
	var mydist = mydom dmapped Block(boundingBox=mydom);
	kernel_2mm(mydist);
}
/*else if dist_string == "BC" {
	var mydist = mydom dmapped MyBlockCyclic(startIdx=mydom.low, blocksize=(3,3));
	kernel_2mm(mydist);
}*/

proc print_locale_data(A: [] int) {
	for i in 1..size {
		for j in 1..size {
			write(A[i,j].locale.id);			
		}
		writeln();
	}
}
proc kernel_2mm(dist) {
    var t:Timer;

	var A: [dist] int;
	var B: [dist] int;
	var C: [dist] int = 0;

	for i in 1..size {
		for j in 1..size {
			A[i,j] = i + j;
			B[i,j] = i + j;
		}
	}
	
	print_locale_data(A);
    /*t.start();
	resetCommDiagnostics();
	startCommDiagnostics();
	
	if zippered {
		forall (i,j) in dist {
			var tempArray: [1..size] int;
			forall (a, b, i) in zip(A[i, 1..size], B[1..size, j], 1..) {
				var temp = a * b;
				tempArray[i] = temp;
			}
			C[i, j] = (+ reduce (tempArray));
		}	
	}
	else {
		forall (i,j) in dist {
			forall k in 1..size {
				C[i, j] += A[i, k] * B[k, j];
			}
		}
	}
	
	stopCommDiagnostics();
    t.stop();

	if printMatrices {
		writeln("\nA:");
		writeln(A);
		print_locale_data(A);
		writeln();
		writeln("\nB:");
		writeln(B);
		print_locale_data(B);
		writeln();
		writeln("\nC:");
		writeln(C);	
		print_locale_data(C);
		writeln();
	}	
	writeln(t.elapsed(), " seconds elapsed"); 
	var messages = 0;
	var coms = getCommDiagnostics();
	for i in 0..numLocales-1 {
		messages += coms(i).get:int;
		messages += coms(i).put:int;
	}
	writeln("Message count = ", messages);*/
}


