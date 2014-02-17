use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
printMatrices: Set to false if you don't want to see the matrices printed
	Default = false
N: size (square) of the matrix
	Default = 128
dist: the distribution of the domain which the matrices are based on. 
    Default: cyclical with modulo unrolling
*****************************/
config var correct = false;
config var timeit = false;
config var messages = false;
config var printMatrices: bool = false;
config var dist: string = "CM";

config var N: int = 128;

/* Initializes a matrix based on a distribution */
proc initialize_matrix(distribution, n_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1) * (j)):real / n_dim;
    }
    return matrix;
}

/* Initializes an array based on a distribution */
proc initialize_array(distribution, n_dim: int) {
    var array: [distribution] real = 0.0;
    forall i in distribution {
        array[i] = (i - 1) * 3.1415926; //pi
    }
    return array;
}

/* Prints out the matrix passed in */
proc print_matrix(A: [], n_dim: int) {
    for i in 1..n_dim {
        for j in 1..n_dim {
            write(A[i,j], " ");
        }
        writeln();
    }
}

proc print_locale_data(A:[], n_dim: int) {
    var count: int = 0;
    for a in A {
        count += 1;
        write(a.locale.id);
        if (count == n_dim) {
            count = 0;
            writeln();
        }
    }
}

/* The process which runs the benchmark */
proc kernel_atax(dist_square, dist_linear, n_dim: int) {
    var still_correct = true;
	var t:Timer;
	
	if messages {
		resetCommDiagnostics();
		startCommDiagnostics();
	}
	
    /******* Start the timer: this is where we do work *******/
	if timeit {
		t = new Timer();
		t.start();
	}
	
    var A = initialize_matrix(dist_square, n_dim);
    var x = initialize_array(dist_linear, n_dim);
    var y: [dist_linear] real = 0.0;
    var temp: [dist_linear] real = 0.0;    
    
    forall i in dist_linear {
        var tempArray: [1..n_dim] real;
        forall (a, b, k) in zip(x[1..n_dim], A[i,1..n_dim], 1..) {
            var temp1 = a * b;
            tempArray[k] = temp1;
        }
        temp[i] = + reduce(tempArray);
    }
    
    for i in dist_linear {
        forall (a, b) in zip(y, A[i,1..n_dim]) {
            a += b * temp[i];
        }
    }
	
    /******* End the timer *******/
	if timeit {
	    t.stop();
		writeln("took ", t.elapsed(), " seconds");
	}
	
	//Print out communication counts (gets and puts)
	if messages {
		stopCommDiagnostics();	
		var messages=0;
		var coms=getCommDiagnostics();
		for i in 0..numLocales-1 {
			messages+=coms(i).get:int;
			messages+=coms(i).put:int;
		}
		writeln('message count=', messages);	
	}
	
    var Atest = initialize_matrix({1..n_dim, 1..n_dim}, n_dim);
    var xTest = initialize_array({1..n_dim}, n_dim);
    var yTest: [{1..n_dim}] real = 0.0;
    var tempTest: [{1..n_dim}] real = 0.0;  
	
	if correct {  
	    forall i in {1..n_dim} {
	        var tempArray: [1..n_dim] real;
	        forall (a, b, k) in zip(xTest[1..n_dim], Atest[i,1..n_dim], 1..) {
	            var temp1 = a * b;
	            tempArray[k] = temp1;
	        }
	        tempTest[i] = + reduce(tempArray);
	    }
    
	    for i in {1..n_dim} {
	        forall (a, b) in zip(yTest, Atest[i,1..n_dim]) {
	            a += b * tempTest[i];
	        }
	    }
		
		for ii in 1..n_dim {
			still_correct &&= yTest[ii] == y[ii];
		}
		writeln("Is the calculation correct? ", still_correct);
		writeln("atax computation complete.");
	}
	
    if (printMatrices) {
        writeln("A:");
        print_matrix(A, n_dim);
        writeln();
        write("x:       ");
        for i in x {
            write(i + " ");
        }
        writeln();
        writeln();
        write("temp:    ");
        for i in temp {
            write(i + " ");
        }
        writeln();
        writeln();
        write("y:       ");
        for i in y {
            write(i + " ");
        }
        writeln();
        writeln();
		
        writeln("Atest:");
        print_matrix(Atest, n_dim);
        writeln();
        write("xTest:       ");
        for i in xTest {
            write(i + " ");
        }
        writeln();
        writeln();
        write("tempTest:    ");
        for i in tempTest {
            write(i + " ");
        }
        writeln();
        writeln();
        write("yTest:       ");
        for i in yTest {
            write(i + " ");
        }
        writeln();
        writeln();
    }
}

proc main() {
    /* Initialize the domains */
    var dom_square = {1..N, 1..N};
    var dom_linear = {dom_square[1, 1..N]};
    
    if dist == "NONE" {
        var user_dist_square = dom_square;
        var user_dist_linear = dom_linear;
        /* Run the benchmark */
        kernel_atax(user_dist_square, user_dist_linear, N); 
    } else if dist == "CM" {
        var user_dist_square = dom_square dmapped CyclicZipOpt(startIdx=dom_square.low);
        var user_dist_linear = dom_linear dmapped CyclicZipOpt(startIdx=dom_linear.low);
        kernel_atax(user_dist_square, user_dist_linear, N);
    } else if dist == "C" {
        var user_dist_square = dom_square dmapped Cyclic(startIdx=dom_square.low);
        var user_dist_linear = dom_linear dmapped Cyclic(startIdx=dom_linear.low);
        kernel_atax(user_dist_square, user_dist_linear, N);
    } else if dist == "B" {
        var user_dist_square = dom_square dmapped Block(boundingBox=dom_square);
        var user_dist_linear = dom_linear dmapped Block(boundingBox=dom_linear);
        kernel_atax(user_dist_square, user_dist_linear, N);
    } 
}