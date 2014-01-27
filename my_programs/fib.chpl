iter fib(n) {
	var current = 0,
	next = 1;
	
	for i in 1..n {
		yield current;
		current += next;
		current <=> next;
	}
}

var A = [1, 2, 3, 4, 5];

for (i,j) in zip(A,fib(5)) do
	writeln(i+j+1);


		