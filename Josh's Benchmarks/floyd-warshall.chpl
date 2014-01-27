use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
	printMatrices: Set to false if you don't want to see the matrices printed
		Default = false
	N: size (square) of the matrices
		Default = 128
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var printMatrices: bool = false;
config var dist: string = "CM";

config var N: int = 128;
var float_n: real = 1.2;

/* Initializes a matrix based on a domain distribution (might be mapped)*/
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
proc kernel_fw(dom_square, dom_linear, n_dim: int) {
    var path = initialize_matrix(dom_square, n_dim);

/*    for k in 1..n_dim {
        forall (a, b) in zip(path[1..n_dim, k], path[1..n_dim, j]) {
            
        }
    }*/
    for (i, j) in dom_square {
        for (a, b) in zip(path[i, 1..n_dim], path[1..n_dim, j]) {
            var temp = a + b;
            if (temp < path[i, j]) {
                path[i, j] = temp;
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
    var dom_linear = dom_square[1, 1..N];
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var user_dist_square = dom_square;
        var user_linear = dom_linear;
        /* Run the benchmark */
        kernel_fw(user_dist_square, user_linear, N); 
    } else if dist == "CM" {
        var user_dist_square = dom_square dmapped CyclicZipOpt(startIdx=dom_square.low);
        var user_linear = dom_linear dmapped CyclicZipOpt(startIdx=dom_linear.low);
        kernel_fw(user_dist_square, user_linear, N);   
    } else if dist == "C" {
        var user_dist_square = dom_square dmapped Cyclic(startIdx=dom_square.low);
        var user_linear = dom_linear dmapped Cyclic(startIdx=dom_linear.low);
        kernel_fw(user_dist_square, user_linear, N); 
    } else if dist == "B" {
        var user_dist_square = dom_square dmapped Block(boundingBox=dom_square);
        var user_linear = dom_linear dmapped Block(boundingBox=dom_linear);
        kernel_fw(user_dist_square, user_linear, N);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}