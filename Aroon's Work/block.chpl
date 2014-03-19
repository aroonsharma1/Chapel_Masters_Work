use BlockDist;
use BlockCycDist;
use MyBlockCyclic;
use CyclicZipOpt;
use CommDiagnostics;
use Time;

config var N = 10;
config var dist: string = "CM";
config var zippered = false;
config var bsize = 3;

var dom = {1..N};

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
	var dist = dom dmapped BlockCyclic(startIdx=dom.low, blocksize=N/numLocales);	
	do_stuff(dist,N);
}
else if dist == "BCM" {
	var dist = dom dmapped MyBlockCyclic(startIdx=dom.low, blocksize=N/numLocales);		
	do_stuff(dist,N);
}

proc do_stuff(dist, N) {
	var timer: Timer = new Timer();
	
	var A, B: [dist] real;
	for i in 1..N {
		A[i] = i;
	}
	//writeln(A);

	//writeln();

	for i in 1..N {
		write(A[i].locale.id);
	}
	writeln();
	
	resetCommDiagnostics();
	startCommDiagnostics();
	
	timer.start();
	
	if zippered {
		forall (a0,a1,b) in zip(A[1..N/2], A[2..N/2+1], B[1..N/2]) {
			b = a0 + a1;
		}
		writeln();	
	}
	
	else {
		forall i in 1..N/2 {
			B[i] = A[i] + A[i+1];
		}
		//writeln();	
	}
	//writeln(B);
	stopCommDiagnostics();
	timer.stop();
	
	var messages = 0;
	var coms = getCommDiagnostics();
	for i in 0..numLocales-1 {
		messages += coms(i).get:int;
		messages += coms(i).put:int;
	}
	writeln("Message count = ", messages);
	writeln("Time Elapsed = ", timer.elapsed());
	//writeln(comms);
}