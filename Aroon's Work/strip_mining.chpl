var bufsize = 16;
var chunk = 10;

for i in 0..bufsize by chunk {
	writeln(min(chunk, bufsize-i));
	for j in i..min(bufsize, i+chunk)-1 {
		writeln(j+1);		
	}
}

proc min(a: int, b: int): int {
	if(a < b) {
		return a;
	}
	else {
		return b;
	}
}