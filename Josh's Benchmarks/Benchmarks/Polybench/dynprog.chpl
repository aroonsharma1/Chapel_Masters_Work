use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
	printMatrices: Set to false if you don't want to see the matrices printed
		Default = false
	alpha: constant by which to multiply the D matrix entries by
		Default = 1
	beta: contant by which to multiply the E matrix entries by
		Default = 1
	size: size (square) of the matrices
		Default = 128
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var printMatrices: bool = false;
config var alpha: int = 1;
config var beta: int = 1;
config var size: int = 128;
config var dist: string = "CM";

/* Map the distribution according to user input. Currently not used */
proc map_distribution(size:int): domain(2) {
    var dom: domain(2) = {1..size, 1..size};
    var user_dist: domain(2);
    if dist == "NONE" {
    	user_dist = dom;
    } else if dist == "CM" {
    	user_dist = dom dmapped CyclicZipOpt(startIdx=dom.low);
    } else if dist == "C" {
    	user_dist = dom dmapped Cyclic(startIdx=dom.low);
    } else if dist == "B" {
    	user_dist = dom dmapped Block(boundingBox=dom);
    }
    return user_dist;
}

/* Initializes a matrix based on a domain distribution (might be mapped) */
proc initialize_matrix(distribution, matrix_size: int, adder: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = i * (j + adder) / matrix_size;
    }
    return matrix;
}

/* The process which runs the benchmark */
proc kernel_2mm(alpha: int, beta: int, distribution, matrix_size: int) {
    var A = initialize_matrix(distribution, matrix_size, 0);
    var B = initialize_matrix(distribution, matrix_size, 1);
    var C = initialize_matrix(distribution, matrix_size, 2);

    /* The matrices that will be the result of the operation */
    var D, E: [distribution] real = 0.0;

    if (printMatrices) {
        writeln("A:");
        print_matrix(A, matrix_size);
        writeln();
        print_locale_data(A, matrix_size);
        writeln();
        writeln("B:");
        print_matrix(B, matrix_size);
        writeln();
        print_locale_data(B, matrix_size);
        writeln();
        writeln("C:");
        print_matrix(C, size);
        writeln();
        print_locale_data(C, matrix_size);
        writeln();
    }
    
    /******* Start the timer: this is where we do work *******/
    var t:Timer;

    t.start();
	resetCommDiagnostics();
	startCommDiagnostics();

    forall (i,j) in distribution {
        var tempArray: [1..matrix_size] real;
        forall (a, b, k) in zip(A[i, 1..matrix_size], B[1..matrix_size, j], 1..) {
            var temp = a * b;
            tempArray[k] = temp;
        }
        C[i,j] = alpha * (+ reduce (tempArray));
    }
    
    forall (i,j) in distribution {
        var tempArray: [1..matrix_size] real;
        forall (d, c, k) in zip(D[i, 1..matrix_size], C[1..matrix_size, j], 1..) {
			var temp = d * c;
			tempArray[k] = temp;
        }
        E[i,j] = beta * (+ reduce (tempArray));
    }
    
	stopCommDiagnostics();
    t.stop();
    /******* End the timer *******/
    
    if (printMatrices) {
        writeln("D:");
        print_matrix(D, matrix_size);
        writeln();
        print_locale_data(D, matrix_size);
        writeln();
        writeln("E:");
        print_matrix(E, size);
        writeln();
        print_locale_data(E, matrix_size);
        writeln();
    }  
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}

/* Prints out the square matrix passed in */
proc print_matrix(A: [], matrix_size: int) {
    for i in 1..matrix_size {
        for j in 1..matrix_size {
            write(A[i,j], " ");
        }
        writeln();
    }
}

/* Print out locale distribution */
proc print_locale_data(A:[], matrix_size: int) {
    var count: int = 0;
    for a in A {
        count += 1;
        write(a.locale.id);
        if (count == matrix_size) {
            count = 0;
            writeln();
        }
    }
}

proc main() {
    /* Initialize the data */
    var dom = {1..size, 1..size};
    
    if dist == "NONE" {
        var user_dist = dom;
        /* Run the benchmark */
        kernel_2mm(alpha, beta, user_dist, size); 
    } else if dist == "CM" {
        var user_dist = dom dmapped CyclicZipOpt(startIdx=dom.low);
        kernel_2mm(alpha, beta, user_dist, size);   
    } else if dist == "C" {
        var user_dist = dom dmapped Cyclic(startIdx=dom.low);
        kernel_2mm(alpha, beta, user_dist, size);   
    } else if dist == "B" {
        var user_dist = dom dmapped Block(boundingBox=dom);
        kernel_2mm(alpha, beta, user_dist, size);   
    }       
}