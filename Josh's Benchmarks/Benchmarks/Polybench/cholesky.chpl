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
config var printMatrices: bool = false;
config var dist: string = "CM";

config var N: int = 128;

/* Initializes a matrix based on a distribution */
proc initialize_matrix(distribution, n_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = 1.0 / n_dim;
    }
    return matrix;
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

/* The process which runs the benchmark */
proc kernel_cholesky(dist_square, n_dim: int) {
    var A = initialize_matrix(dist_square, n_dim);
    var C: [dist_square] real = 0.0;
    var s: real;
    
  /*  A[1,1] = 18;
    A[1,2] = 22;
    A[1,3] = 54;
    A[1,4] = 42;
    A[2,1] = 22;
    A[2,2] = 70;
    A[2,3] = 86;
    A[2,4] = 62;
    A[3,1] = 54;
    A[3,2] = 86;
    A[3,3] = 174;
    A[3,4] = 134;
    A[4,1] = 42;
    A[4,2] = 62;
    A[4,3] = 134;
    A[4,4] = 106;*/
  
    for i in dist_square[1, 1..n_dim] {
        for j in dist_square[i, 1..i] {
            s = 0.0;
            forall (a,b) in zip(C[i,1..j], C[j,1..j]) {
                s += a * b;
            }                
            if (i == j) {
                C[i,j] = sqrt(A[i,i] - s);
            } else {
                C[i,j] = 1.0/(C[j,j]) * (A[i,j] - s);
            }
        }
    } 
    
    if (printMatrices) {
        writeln("A:");
        print_matrix(A, n_dim);
        writeln();
        writeln("C:");
        print_matrix(C, n_dim);
        writeln();
    }
}

proc main() {
    /* Initialize the domains */
    var dom_square = {1..N, 1..N};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var user_dist_square = dom_square;
        /* Run the benchmark */
        kernel_cholesky(user_dist_square, N); 
    } else if dist == "CM" {
        var user_dist_square = dom_square dmapped CyclicZipOpt(startIdx=dom_square.low);
        kernel_cholesky(user_dist_square, N);   
    } else if dist == "C" {
        var user_dist_square = dom_square dmapped Cyclic(startIdx=dom_square.low);
        kernel_cholesky(user_dist_square, N); 
    } else if dist == "B" {
        var user_dist_square = dom_square dmapped Block(boundingBox=dom_square);
        kernel_cholesky(user_dist_square, N);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}