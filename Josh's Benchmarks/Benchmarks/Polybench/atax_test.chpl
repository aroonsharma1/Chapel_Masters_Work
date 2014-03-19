use CyclicZipOpt;
use BlockDist;

config var dist: string = "CM";
config var N: int = 4;

var dom_square = {1..N, 1..N};
var dom_linear = {dom_square[1, 1..N]};

if dist == "NONE" {
    var user_dist_square = dom_square;
    var user_dist_linear = dom_linear;
	do_test(user_dist_square, user_dist_linear);
} else if dist == "CM" {
    var user_dist_square = dom_square dmapped CyclicZipOpt(startIdx=dom_square.low);
    var user_dist_linear = dom_linear dmapped CyclicZipOpt(startIdx=dom_linear.low);
	do_test(user_dist_square, user_dist_linear);
} else if dist == "C" {
    var user_dist_square = dom_square dmapped Cyclic(startIdx=dom_square.low);
    var user_dist_linear = dom_linear dmapped Cyclic(startIdx=dom_linear.low);
	do_test(user_dist_square, user_dist_linear);
} else if dist == "B" {
    var user_dist_square = dom_square dmapped Block(boundingBox=dom_square);
    var user_dist_linear = dom_linear dmapped Block(boundingBox=dom_linear);
	do_test(user_dist_square, user_dist_linear);
}

proc do_test(user_dist_square, user_dist_linear) {
	var A,X,answer: [user_dist_square] real;
 	var x: [user_dist_linear] real;
	var temp: [user_dist_linear] real;
	
	forall i in user_dist_linear {
		x[i] = (i - 1) * 3.1415926;
	}

	forall (i,j) in user_dist_square {
		A[i,j] = ((i - 1) * (j)):real / N;
		X[i,j] = (j - 1) * 3.1415926;
	}
	
	// writeln(A);
	// writeln();
	// writeln(x);
	// 
	//     forall i in user_dist_linear {
	//         var tempArray: [1..N] real;
	//         forall (a, b, k) in zip(x[1..N], A[i,1..N], 1..) {
	//             var temp1 = a * b;
	//             tempArray[k] = temp1;
	//         }
	//         temp[i] = + reduce(tempArray);
	//     }
	// 
	// for i in user_dist_linear {
	// 	forall (a,b) in zip(A[i,1..N], x) {
	// 		temp[i] += a * b;
	// 	}
	// }
	// writeln(temp);	
	
	var foo: [1..N] real;
	forall (a,b,i) in zip(A[2,user_dist_linear], x, 1..) {
		foo[i] = a * b;
	}
	writeln(foo);
}