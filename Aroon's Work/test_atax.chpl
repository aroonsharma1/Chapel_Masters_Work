use CyclicZipOptAroon;

config var dist: string = "CM";
config var size: int = 2;

var dom_vector = {1..size};
var dom_matrix = {1..size, 1..size};

var dist_vector = dom_vector dmapped CyclicZipOpt(startIdx=dom_vector.low);
var dist_matrix = dom_matrix dmapped CyclicZipOpt(startIdx=dom_matrix.low);

var X: [dist_vector] real = 1;
var A: [dist_matrix] real = 2;
var Y: [dist_vector] real;

writeln("x:");
for i in X {
	writeln(i.locale.id);
}
writeln();

writeln("A:");
for i in A {
	writeln(i.locale.id);
}
writeln();

forall i in dist_vector {
	var tempArray: [1..size] real;
	forall (a, x, i) in zip(A[i, 1..size], X[1..size], 1..) {
		var temp1 = a * x;
		tempArray[i] = temp1;
	}
	Y[i] = + reduce(tempArray);
}

writeln("Y = ");
writeln(Y);