use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
    Dimensions are set up to be M x N. 
    M: 1st dimension
        Default = 128
	N: 2nd dimension 
		Default = 128

	printData: Set to false if you don't want to see the data printed
		Default = false
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var M: int = 128;
config var N: int = 128;

config var printData: bool = false;
config var dist: string = "CM";

var alpha: int = 32412;
var beta: int = 2123;

/* Initializes a 2D structure */
proc initialize_2D(distribution, m_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1) * (j - 1)) / (1.0 * m_dim);
    }
    return matrix;
}

/* Prints out the 2D structure passed in */
proc print_2D(A: [], m_dim: int, n_dim: int) {
    for i in 1..m_dim {
        write("     ");
        for j in 1..n_dim {
            write(A[i,j], " ");
        }
        writeln();
    }
}

/* The process which runs the benchmark */
proc kernel_syrk(dist_2D, m_dim: int, n_dim: int) {
    var A = initialize_2D(dist_2D, m_dim);
    var C = initialize_2D(dist_2D, m_dim);
    
    C *= beta;
    
    forall i in 1..m_dim {
        forall j in 1..n_dim {
            var temp: real = C[i,j];
            var tempArray: [1..n_dim] real;
            forall (a,b,c) in zip (A[i,..], A[j,..], 1..) {
                tempArray[c] = alpha * a * b; 
            }
            C[i,j] = temp + (+ reduce (tempArray));
        }
    }
    
    if (printData) {
        writeln("A:");
        print_2D(A, m_dim, n_dim);
        writeln("C:");
        print_2D(C, m_dim, n_dim);
    }
}

proc main() {
    /* Initialize the domains */
    var dom_2D = {1..M, 1..N};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var dist_2D = dom_2D;
        /* Run the benchmark */
        kernel_syrk(dist_2D, M, N); 
    } else if dist == "CM" {
        var dist_2D = dom_2D dmapped CyclicZipOpt(startIdx=dom_2D.low);
        kernel_syrk(dist_2D, M, N); 
    } else if dist == "C" {
        var dist_2D = dom_2D dmapped Cyclic(startIdx=dom_2D.low);
        kernel_syrk(dist_2D, M, N); 
    } else if dist == "B" {
        var dist_2D = dom_2D dmapped Block(boundingBox=dom_2D);
        kernel_syrk(dist_2D, M, N);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}