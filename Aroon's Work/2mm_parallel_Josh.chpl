//Josh's version of 2mm_parallel.chpl
use CyclicZipOpt;
use BlockDist;
use Time;

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

/* Initializes a matrix based on a domain distribution (might be mapped)*/
proc initialize_matrix(distribution, matrix_size: int, adder: int) {
    var array: [distribution] real = 0.0;
    forall i in 1..matrix_size {
        forall j in 1..matrix_size {
            array[i,j] = i * (j + adder) / matrix_size;
        }
    }
    return array;
}

/* The process which runs the benchmark */
proc kernel_2mm(alpha: int, beta: int, distribution, matrix_size: int) {
    var A = initialize_matrix(distribution, matrix_size, 0);
    var B = initialize_matrix(distribution, matrix_size, 1);
    var C = initialize_matrix(distribution, matrix_size, 2);
    
    /* The matrices that will be the result of the operation */
    var D, E: [distribution] real = 0.0;
    
    /* Dimension of the square matrix. Use for slicing the rows and columns */
    var length = {1..matrix_size};

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
/*  Attempt to run everything in one loop: just computes diagonal
      
    forall (i,j) in zip(1..matrix_size, 1..matrix_size) {
        D[i, j] = alpha * (+ reduce (A[i, length] * B[length, j]));
    }
*/
    forall i in 1..matrix_size {
        forall j in 1..matrix_size {
            D[i,j] = alpha * (+ reduce (A[i, length] * B[length,j])); 
        }
    }
    forall i in 1..matrix_size {
        forall j in 1..matrix_size {
            E[i,j] = beta * (+ reduce (C[i, length] * D[length,j])); 
        }
    }
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