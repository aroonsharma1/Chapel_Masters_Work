use CyclicZipOpt;
use BlockDist;

config var size=100;	//size of the array
config var n=10;	//subset of the array that is being iterated over

var mydom = {0..size-1};

//var mydist = mydom dmapped Block(boundingBox=mydom);
var mydist = mydom dmapped CyclicZipOpt(startIdx=mydom.low);

var A: [mydist] int;
var B: [mydist] int;

for i in 0..size-1 {
	A[i] = i;
	B[i] = i;
}

/*writeln("\nA:");
for a in A {
	writeln(a + " on locale " + a.locale.id);
}

writeln("\nB:");

for b in B {
	writeln(b + " on locale " + b.locale.id);
}*/

/*writeln("A = ");
writeln(A);
writeln("B = ");
writeln(B);*/

forall (a1,a2,b1) in zip(A[0..n], A[1..(n + 1)], B[1..(n + 1)]) {
	a1 = a2 + b1;
}

/*writeln("A = ");
writeln(A);
writeln("B = ");
writeln(B);*/
