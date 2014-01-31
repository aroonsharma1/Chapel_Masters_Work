//use CyclicZipOpt;
use CyclicZipOptAroon;
use BlockDist;

config var size=30;	//size of the array
config var n=10;	//subset of the array that is being iterated over

var mydom = {0..size-1, 0..size-1};

//var mydist = mydom dmapped Block(boundingBox=mydom);
var mydist = mydom dmapped CyclicZipOpt(startIdx=mydom.low);

var A: [mydist] int;
var B: [mydist] int;

for i in 0..size-1 {
	for j in 0..size-1 {
		A[i, j] = j;
		B[i, j] = j;
	}
}

forall (a1,b1) in zip(A[0..n, 0..n], B[1..(n + 1), 1..(n + 1)]) {
	a1 = b1;
}

writeln();
writeln(A);
