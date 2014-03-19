use CyclicZipOpt;
use CommDiagnostics;

config var size=9;	//size of the matrix
config var dist_string: string = "CM";
config var zippered = false;

var mydom = {1..size};

if dist_string == "CM" {
	var mydist1 = mydom dmapped CyclicZipOpt(startIdx=mydom.low);
	var mydist2 = mydom dmapped CyclicZipOpt(startIdx=mydom.low + 1);
	do_exp(mydist1, mydist2);
}
else if dist_string == "C" {
	var mydist1 = mydom dmapped Cyclic(startIdx=mydom.low);
	var mydist2 = mydom dmapped Cyclic(startIdx=mydom.low + 1);
	do_exp(mydist1, mydist2);	
}

proc exp(base: int, exp: int): int {
	var answer = 1;
	for i in 1..exp {
		answer *= base;
	}
	return answer;
}

proc do_exp(mydist1, mydist2) {
	var A: [mydist1] int = 3;
	var B: [mydist2] int = 3;
	var C: [mydist1] int;
	
	for i in A {
		write(i.locale.id);
	}
	writeln();
	
	for i in B {
		write(i.locale.id);
	}
	writeln();
	
	if zippered {
		forall (a,b,c) in zip(A, B, C) {
			c = exp(a,b);
		}
	}
	else {
		C = exp(A,B);		
	}
	writeln(C);
}