use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
    Dimensions are set up by M x N x P. If the data structure is 2D, then M x N.
    M: 1st dimension
        Default = 128
	N: 2nd dimension 
		Default = 128
    P: 3rd dimension
        Default = 128
    
	printData: Set to false if you don't want to see the data printed
		Default = false
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var printData: bool = false;
config var dist: string = "CM";

config var M: int = 128;
config var N: int = 128;
config var P: int = 128;

/* Initializes a 2D structure */
proc initialize_2D(distribution, p_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1) * (j - 1)) / (1.0 * p_dim);
    }
    return matrix;
}

/* Initializes a 3D structure */
proc initialize_3D(distribution, p_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j,k) in distribution {
        matrix[i,j,k] = (((i - 1) * (j - 1)) + (k - 1)) / (1.0 * p_dim);
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

/* Prints out the 3D structure passed in */
proc print_3D(A: [], m_dim: int, n_dim: int, p_dim: int) {
    for k in 1..p_dim {
        writeln("p_dim ", k, ":");
        for i in 1..m_dim {
            write("     ");
            for j in 1..n_dim {
                write(A[i,j,k], " ");
            }
            writeln();
        }
    }
}

/* The process which runs the benchmark */
proc kernel_doitgen(dist_2D, dist_3D, m_dim: int, n_dim: int, p_dim: int) {
    var A = initialize_3D(dist_3D, p_dim);
    var C4 = initialize_2D(dist_2D, p_dim);
    var sum: [dist_3D] real = 0.0;
    
    for (i, j) in dist_2D {
        for (a, b) in zip(sum[i,j,..], 1..) {
            var temp: [1..p_dim] real = 0.0;
            forall(d,e,f) in zip(A[i,j,..], C4[..,b], 1..) {
                temp[f] = d * e;
            }
            a = (+ reduce(temp));
        }
        A[i,j,..] = sum[i,j,..];
    }  
    
    if (printData) {
        writeln("A:");
        print_3D(A, m_dim, n_dim, p_dim);
        writeln("C4:");
        print_2D(C4, m_dim, n_dim);
    }
}

proc main() {
    /* Initialize the domains */
    var dom_2D = {1..M, 1..N};
    var dom_3D = {1..M, 1..N, 1..P};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var dist_2D = dom_2D;
        var dist_3D = dom_3D;
        /* Run the benchmark */
        kernel_doitgen(dist_2D, dist_3D, M, N, P); 
    } else if dist == "CM" {
        var dist_2D = dom_2D dmapped CyclicZipOpt(startIdx=dom_2D.low);
        var dist_3D = dom_3D dmapped CyclicZipOpt(startIdx=dom_3D.low);
        kernel_doitgen(dist_2D, dist_3D, M, N, P); 
    } else if dist == "C" {
        var dist_2D = dom_2D dmapped Cyclic(startIdx=dom_2D.low);
        var dist_3D = dom_3D dmapped Cyclic(startIdx=dom_3D.low);
        kernel_doitgen(dist_2D, dist_3D, M, N, P); 
    } else if dist == "B" {
        var dist_2D = dom_2D dmapped Block(boundingBox=dom_2D);
        var dist_3D = dom_3D dmapped Block(boundingBox=dom_3D);
        kernel_doitgen(dist_2D, dist_3D, M, N, P);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}