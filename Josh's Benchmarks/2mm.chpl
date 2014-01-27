/* 2 Matrix Multiplications (D=A.B; E=C.D) */

/* Use Time Library*/
use Time;


/****************************
	printMatrices: Set to false if you don't want to see the matrices printed
		Default = true
	alpha: constant by which to multiply the D matrix entries by
		Default = 1
	beta: contant by which to multiply the E matrix entries by
		Default = 1
	size: size (square) of the matrices
		Default = 128
*****************************/
config var printMatrices: bool = true;
config var alpha: int = 1;
config var beta: int = 1;
config var size: int = 128;

/* Initializes the size of the matrix */
proc initialize_matrix(matrix_size: int, adder: int) {
    var array: [1..matrix_size, 1..matrix_size] real;
    forall i in 1..matrix_size {
        forall j in 1..matrix_size {
            array[i,j] = i * (j + adder) / matrix_size;
        }
    }
    return array;
}

/* The process which runs the benchmark */
proc kernel_2mm(A: [], B: [], C: [], alpha: int, beta: int, matrix_size: int) {
    var D: [1..matrix_size, 1..matrix_size] real;
    var E: [1..matrix_size, 1..matrix_size] real; 
    if (printMatrices) {
        writeln("A:");
        print_matrix(A, size);
        writeln();
        writeln("B:");
        print_matrix(B, size);
        writeln();
        writeln("C:");
        print_matrix(C, size);
        writeln();
    }
    
    /******* Start the timer: this is where we do work *******/
    var t:Timer;
    t.start();
    for i in 1..matrix_size {
        for j in 1..matrix_size {
            for k in 1..matrix_size {
                D[i, j] += (alpha * A[i,k] * B[k,j]);
            }
        }
    }
    for i in 1..matrix_size {
        for j in 1..matrix_size {
            for k in 1..matrix_size {
                E[i, j] += (beta * D[i,k] * C[k,j]);
            }
        }
    }  
    t.stop();
    /******* End the timer *******/
    
    if (printMatrices) {
        writeln("D:");
        print_matrix(D, size);
        writeln();
        writeln("E:");
        print_matrix(E, size);
        writeln();
    }  
    writeln(t.elapsed()," seconds elapsed");  
}

/* Prints out a square matrix which is passed in*/
proc print_matrix(A: [], matrix_size: int) {
    for i in 1..matrix_size {
        for j in 1..matrix_size {
            write(A[i,j], " ");
        }
        writeln();
    }
}

proc main() {
    /* Initialize the data */
    var A = initialize_matrix(size, 0);
    var B = initialize_matrix(size, 1);
    var C = initialize_matrix(size, 2);
    
    /* Run the benchmark */
    kernel_2mm(A, B, C, alpha, beta, size);        
}