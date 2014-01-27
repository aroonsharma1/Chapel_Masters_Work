//for each dimension calculate the number of elements in each dimension and multiply each in a total to get the total elements in the n dimensional array. 
proc tile(A: []): int {
	var count: int = 1;
	for i in A {
		count = count * i;
	}
	return count;
}

var A: [1..10, 1..10] int;
for i in 1..10 {
	for j in 1..10 {
		A[i,j] = i;		
	}
}
writeln(A);
writeln(tile(A));