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
        matrix[i,j] = (i * j):real / n_dim;
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

/* Print out locale distribution */
/*proc print_locale_data(A:[], n_dim: int) {
    var count: int = 0;
    for a in A {
        count += 1;
        write(a.locale.id);
        if (count == n_dim) {
            count = 0;
            writeln();
        }
    }
}*/

/* The process which runs the benchmark */
proc kernel_fw(dist_square, n_dim: int) {
    var path = initialize_matrix(dist_square, n_dim);

    for k in 1..n_dim {
        forall (i, j) in dist_square {
            var temp = path[k, j];
            forall (a, b) in zip(path[1..i, k], path[1..i, j]) {
                var tempSum = a + temp;
                if (tempSum < b) {
                    b = tempSum;
                }  
            }
        }
    }
    
    if (printMatrices) {
        writeln("path:");
        print_matrix(path, n_dim);
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
        kernel_fw(user_dist_square, N); 
    } else if dist == "CM" {
        var user_dist_square = dom_square dmapped CyclicZipOpt(startIdx=dom_square.low);
        kernel_fw(user_dist_square, N);   
    } else if dist == "C" {
        var user_dist_square = dom_square dmapped Cyclic(startIdx=dom_square.low);
        kernel_fw(user_dist_square, N); 
    } else if dist == "B" {
        var user_dist_square = dom_square dmapped Block(boundingBox=dom_square);
        kernel_fw(user_dist_square, N);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}