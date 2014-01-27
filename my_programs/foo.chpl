use Random;

var r : RandomStream = new RandomStream(SeedGenerator.currentTime);


var A : [1..100] real;
var B : [1..100] real;

for i in A {
	i = 1;
}

for i in B {
	i = 2;
}

writeln("Before operation:");
writeln(A);

//forall i in 1..20 do
//	A[i] = B[i] + B[i+1];

forall (a1, b1, b2) in zip(A[1..20], B[1..20], B[2..21]) do
	a1 = b1 + b2;

writeln("After operation: ");
writeln(A);
	


