use BlockCycDist;
use MyBlockCyclic;
use BlockDist;

config const n = 8;

const Space = {1..n, 1..n};

const BlockSpace = Space dmapped Block(boundingBox=Space);
var BA: [BlockSpace] int;

forall ba in BA do
	ba = here.id;

writeln(BA[1,1..n]);

writeln("Distributed with Block");
writeln(BA);
writeln();

const BlockCyclicSpace = Space dmapped BlockCyclic(startIdx=Space.low, blocksize=(2,2));
var BCA: [BlockCyclicSpace] int;

forall bca in BCA do
	bca = here.id;

//writeln(BCA[1,1..n]);
writeln();

writeln("Distributed with Block Cyclic");
writeln(BCA);
writeln();

/*const MyBlockCyclicSpace = Space dmapped MyBlockCyclic(startIdx=Space.low, blocksize=(2,2));
var MBCA: [MyBlockCyclicSpace] int;

forall mbca in MBCA do
	mbca = here.id;

//writeln("Distributed with My Block Cyclic");
//writeln(MBCA);
//writeln();*/