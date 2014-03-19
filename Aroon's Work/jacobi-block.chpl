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
	
	const DataSpace = {1..N, 1..N};
	const LoopSpace = {2..N-1, 2..N-1};
	var blkDataDist = DataSpace dmapped Block(boundingBox=DataSpace);
	var blkLoopDist = LoopSpace dmapped Block(boundingBox=LoopSpace);
	var A: [blkDataDist] real;
	var Anew: [blkDataDist] real;
	
	//Set boundary conditions to be 1
	A[1, 1..N] = 1.0;
	A[N, 1..N] = 1.0;
	A[1..N, 1] = 1.0;
	A[1..N, N] = 1.0;
	
	//writeln(A);
	resetCommDiagnostics();
	startCommDiagnostics();
	timer.start();
	
	const north = {1..N-2, 2..N-1}, 
		  south = {3..N, 2..N-1}, 
		  east = {2..N-1, 3..N}, 
		  west = {2..N-1, 1..N-1};
		
	
	Anew[LoopSpace] = (A[north] + A[south] + A[east] + A[west])/4.0;
	
	timer.stop();
	stopCommDiagnostics();
	
	var messages = 0;
	var coms = getCommDiagnostics();
	for i in 0..numLocales-1 {
		messages += coms(i).get:int;
		messages += coms(i).put:int;
	}
	writeln("Message count = ", messages);
	writeln(timer.elapsed() + " seconds");
	writeln(coms);
	A[LoopSpace] = Anew[LoopSpace];
	writeln(A);
}