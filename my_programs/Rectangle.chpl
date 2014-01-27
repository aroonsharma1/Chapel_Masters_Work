class Rectangle {
	var length: int;
	var width: int;

	iter these() {
		writeln("Calling serial iterator");
		yield length;
		yield width;
	}
	
	iter these(param tag: iterKind) where tag == iterKind.leader {
		writeln("Calling leader iterator");
		yield length;
		yield width;
		yield length + 1;
		yield width + 1;
	}
	
	iter these(param tag: iterKind, followThis) where tag == iterKind.follower {
		writeln("Calling follower iterator");
		yield length;
		yield width;
		yield length + 1;
		yield width + 1;
	}
}

var r1 = new Rectangle(5, 6);
var r2 = new Rectangle(8, 10);

forall (i, j) in zip(r1, r2) {
	writeln(i,j);
}
