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
/*            writeln("i: " + i + ", a: " + a + ", b: " + b);*/
            var temp1 = a * b;
            tempArray[k] = temp1;
        }
      /*  write("tempArray for " + i + " is: ");
        for l in tempArray {
            write(l + " ");
        }
        writeln();
        write("which sum is: " + (+ reduce tempArray));
        writeln();*/
        temp[i] = + reduce(tempArray);
    }
    
    forall i in dist_linear {
        var tempArray: [1..n_dim] real;
        forall (a, b, k) in zip(temp[1..n_dim], A[i,1..n_dim], 1..) {
            var temp1 = a * b;
            tempArray[k] = temp1;
        }
        y[i] = + reduce(tempArray);
    }
	
	//End the times
	if timeit {
		t.stop();
		writeln("took ", t.elapsed(), " seconds");
	}
	
	//Print out the communication counts (gets and puts)
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
    
	//Print out results
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
        /*print_locale_data(A, n_dim);
        writeln();
        print_locale_data(x, n_dim);
        writeln();
        print_locale_data(temp, n_dim);
        writeln();
        print_locale_data(y, n_dim);
        writeln();*/
    }
	
	//confirm the correctness of the calculation
	if correct {
		//Vectors and matrices to test correctness of calculation
		var Atest = initialize_matrix({1..n_dim, 1..n_dim}, n_dim);
		var xtest = initialize_array({1..n_dim}, n_dim);
		var ytest: [1..n_dim] real = 0.0;
		var tempTest: [1..n_dim] real = 0.0; 
		
	    forall i in dist_linear {
	        var tempArrayTest: [1..n_dim] real;
	        forall (a, b, k) in zip(xtest[1..n_dim], Atest[i,1..n_dim], 1..) {
	/*            writeln("i: " + i + ", a: " + a + ", b: " + b);*/
	            var temp1Test = a * b;
	            tempArrayTest[k] = temp1Test;
	        }
	      /*  write("tempArray for " + i + " is: ");
	        for l in tempArray {
	            write(l + " ");
	        }
	        writeln();
	        write("which sum is: " + (+ reduce tempArray));
	        writeln();*/
	        tempTest[i] = + reduce(tempArrayTest);
	    }
    
	    forall i in dist_linear {
	        var tempArrayTest: [1..n_dim] real;
	        forall (a, b, k) in zip(tempTest[1..n_dim], Atest[i,1..n_dim], 1..) {
	            var temp1Test = a * b;
	            tempArrayTest[k] = temp1Test;
	        }
	        ytest[i] = + reduce(tempArrayTest);
	    }	
		
		for i in 1..n_dim {
			still_correct &&= y[i] == ytest[i];
		}
		writeln("Is the calculation correct? ", still_correct);
		writeln("atax computation complete.");
	}
}

proc main() {
    /* Initialize the domains */
    var dom_square = {1..N, 1..N};
    var dom_linear = {dom_square[1, 1..N]};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
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
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}