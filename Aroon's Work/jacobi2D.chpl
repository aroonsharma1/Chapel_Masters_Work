use BlockDist;
use BlockCycDist;
use CyclicDist;
use Time;
use CommDiagnostics;

config var N: int = 8;

proc print_locale_data(A: [] real, N: int) {
	for i in 1..N {
		for j in 1..N {
			write(A[i,j].locale.id + " ");		
		}
		writeln();
	}
}

proc main() {
	var timer: Timer = new Timer();
	
	const dom = {1..N, 1..N};
	var blkDist = dom dmapped Block(boundingBox=dom);
	var A: [blkDist] real;
	var Anew: [blkDist] real;
	
	const DataSpace = dom;
	const LoopSpace = {2..N-1, 2..N-1};
	
	//Set boundary conditions to be 1
	A[1, 1..N] = 1.0;
	A[N, 1..N] = 1.0;
	A[1..N, 1] = 1.0;
	A[1..N, N] = 1.0;
	
	//writeln(A);
	
	const north = {1..N-2, 2..N-1}, 
		  south = {3..N, 2..N-1}, 
		  east = {2..N-1, 3..N}, 
		  west = {2..N-1, 1..N-1};
		 	  	
	/*writeln("LoopSpace");	  
	writeln(A[LoopSpace]);
	writeln("north");	  
	writeln(A[north]);
	writeln("south");	  
	writeln(A[south]);
	writeln("east");	  
	writeln(A[east]);
	writeln("west");	  
	writeln(A[west]);*/
	/*resetCommDiagnostics();
	startCommDiagnostics();
	timer.start();
	Anew[LoopSpace] = (A[north] + A[south] + A[east] + A[west])/4.0;
	timer.stop();
	stopCommDiagnostics();*/
	//A[LoopSpace] = Anew[LoopSpace];
	
	/*forall (c,n,s,e,w) in zip(Anew[LoopSpace],A[north], A[south], A[east], A[west]) {
		c = (n + s + e + w)/4.0;						  
	}*/
	/*forall (a,b) in zip(Anew[LoopSpace], A[LoopSpace]) {
		b = a;
	}*/
	/*var messages = 0;
	var coms = getCommDiagnostics();
	for i in 0..numLocales-1 {
		messages += coms(i).get:int;
		messages += coms(i).put:int;
	}
	writeln("Message count = ", messages);
	writeln(timer.elapsed() + " seconds");*/
	//writeln(A);
	//print_locale_data(A,N);
		  
		  forall (i,j) in {1..4, 1..4} {
			  writeln((i,j));
		  }
}