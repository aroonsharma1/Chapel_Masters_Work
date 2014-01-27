//non-synchronized case
var B: [1..10] int;

writeln("Non-synchronized case: ");

begin forall i in 1..10 {
	B[i] = i;
}

begin forall i in B {
	writeln(i);
}


//synchronized case
var A: [1..10] sync int;

writeln("Synchronized case: ");

begin forall i in 1..10 {
	A[i] = i;
}

begin forall i in A {
	writeln(i.readFE());
}