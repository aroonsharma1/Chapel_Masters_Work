iter foo {
	writeln("In foo iterator not leader/follower");
	yield 1;
	yield 2;
	yield 3;
}


iter foo(param tag: iterKind) where tag == iterKind.leader {
	writeln("In foo leader");
	yield 1;
	yield 2;
	yield 3;
}

iter foo(param tag: iterKind, followThis) where tag == iterKind.follower {
	writeln("In foo follower");
	yield 1;
	yield 2;
	yield 3;
}

iter fib(n) {
	var current = 0, next = 1;
	
	for i in 1..n {
		yield current;
		current += next;
		current <=> next;	
	}
}
