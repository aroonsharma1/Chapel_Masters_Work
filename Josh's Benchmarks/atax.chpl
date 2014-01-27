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
var float_n: real = 1.2;

/* Initializes a matrix based on a domain */
proc initialize_matrix(distribution, n_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1) * (j)):real / n_dim;
    }
    return matrix;
}

/* Initializes an array based on a domain */
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

/* The process which runs the benchmark */
proc kernel_atax(dom_square, dom_linear_1, dom_linear_2, n_dim: int) {
    var A = initialize_matrix(dom_square, n_dim);
    var x = initialize_array(dom_linear_1, n_dim);
    var y: [dom_linear_1] real = 0.0;
    var temp: [dom_linear_1] real = 0.0;
    
/*    forall (i, k) in zip(dom_square[1, 1..n_dim], dom_linear_2) {
        forall (a, j) in zip(A[i, 1..n_dim], dom_linear_1) {
            temp[k] += a*x[j];
        }
        forall (a,j) in zip(A[i, 1..n_dim], dom_linear_1) {
            y[j] += a*temp[k];
        }
    }
*/
    
/*    forall (i,j) in dom_square {
        
    }*/
    
    
    forall i in dom_linear_1 {
        var tempArray: [1..n_dim] real;
        forall (a, b, k) in zip(A[i,1..i], x[1..i], 1..) {
            var temp1 = a * b;
            tempArray[k] = temp1;
        }
        temp[i] = + reduce(tempArray);
    }
/*    forall (i,j) in distribution {
        var tempArray: [1..matrix_size] real;
        forall (a, b, k) in zip(A[i, 1..matrix_size], B[1..matrix_size, j], 1..) {
            var temp = a * b;
            tempArray[k] = temp;
        }
        C[i,j] = alpha * (+ reduce (tempArray));
    }*/
/*    for k in 1..n_dim {
        forall (i, j) in dom_square {
            var temp = path[k, j];
            forall (a, b) in zip(path[1..i, k], path[1..i, j]) {
                var tempSum = a + temp;
                if (tempSum < b) {
                    b = tempSum;
                }  
            }
        }
    }*/
    
    if (printMatrices) {
        writeln("A:");
        print_matrix(A, n_dim);
        writeln();
        for i in dom_linear_1 {
            write(y[i] + " ");
        }
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
        var user_linear_1 = dom_linear;
        var user_linear_2 = dom_linear;
        /* Run the benchmark */
        kernel_atax(user_dist_square, user_linear_1, user_linear_2, N); 
    } else if dist == "CM" {
        var user_dist_square = dom_square dmapped CyclicZipOpt(startIdx=dom_square.low);
        var user_linear_1 = dom_linear dmapped CyclicZipOpt(startIdx=dom_linear.low);
        var user_linear_2 = dom_linear dmapped CyclicZipOpt(startIdx=dom_linear.low + 1);
        kernel_atax(user_dist_square, user_linear_1, user_linear_2, N);
    } else if dist == "C" {
        var user_dist_square = dom_square dmapped Cyclic(startIdx=dom_square.low);
        var user_linear_1 = dom_linear dmapped Cyclic(startIdx=dom_linear.low);
        var user_linear_2 = dom_linear dmapped Cyclic(startIdx=dom_linear.low + 1);
        kernel_atax(user_dist_square, user_linear_1, user_linear_2, N);
    } else if dist == "B" {
        var user_dist_square = dom_square dmapped Block(boundingBox=dom_square);
        var user_linear_1 = dom_linear dmapped Block(boundingBox=dom_linear);
        var user_linear_2 = dom_linear dmapped Block(boundingBox=dom_linear);
        kernel_atax(user_dist_square, user_linear_1, user_linear_2, N);
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}