use BlockDist;
use BlockCycDist;
use MyBlockCyclic;
use CyclicZipOpt;
use CommDiagnostics;

config var N = 10;
config var dist: string = "CM";
config var zippered = false;

var dom = {1..N, 1..N};

if dist == "C" {
	var dist = dom dmapped Cyclic(startIdx=dom.low);
	do_stuff(dist,N);
}
else if dist == "CM" {
	var dist = dom dmapped CyclicZipOpt(startIdx=dom.low);	
	do_stuff(dist,N);
}
else if dist == "B" {
	var dist = dom dmapped Block(boundingBox=dom);
	do_stuff(dist,N);
}
else if dist == "BC" {
	var dist = dom dmapped BlockCyclic(startIdx=dom.low, blocksize=(3,3));	
	do_stuff(dist,N);
}
else if dist == "BCM" {
	var dist = dom dmapped MyBlockCyclic(startIdx=dom.low, blocksize=(3,3));		
	do_stuff(dist,N);
}

proc do_stuff(dist, N) {
	var A: [dist] real;
	for i in 1..N {
		for j in 1..N {
			A[i,j] = i + j;			
		}
	}
	writeln(A);

	writeln();

	resetCommDiagnostics();
	startCommDiagnostics();
	for i in 1..N {
		for j in 1..N {
			write(A[i,j].locale.id);			
		}
		writeln();
	}
	writeln();
	
	//writeln(A[5,2].locale.id);
	var Aslice: [1..3, 1..2] real = A[5..7, 1..2];
	/*forall (a,b) in zip(A[1, 1..N], A[2, 1..N]) {
		writeln(a + b);
	}*/
	/*if zippered {
		forall (a,b) in zip(A[1..N/2], A[2..N/2+1]) {
			write(a + b + " ");
		}
		writeln();	
	}
	
	else {
		forall i in 1..N/2 {
			write(A[i] + A[i+1] + " ");
		}
		writeln();	
	}*/
	stopCommDiagnostics();
	
	var messages = 0;
	var coms = getCommDiagnostics();
	for i in 0..numLocales-1 {
		messages += coms(i).get:int;
		messages += coms(i).put:int;
	}
	writeln("Message count = ", messages);
	//writeln(comms);
}