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

    TMAX: The total number of iterations
        Default = 50

	printData: Set to false if you don't want to see the data printed
		Default = false
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var M: int = 128;
config var N: int = 128;

config var TMAX: int = 50;

config var printData: bool = false;
config var dist: string = "CM";

/* Initializes a 1D structure */
proc initialize_1D(distribution) {
    var array: [distribution] real = 0.0;
    forall i in distribution {
        array[i] = (i - 1.0);
    }
    return array;
}

/* Initializes a 2D structure */
proc initialize_2D(distribution, adder: int, divider: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1.0) * (j + adder)) / divider;
    }
    return matrix;
}

/* Prints out the 1D structure passed in */
proc print_1D(A: []) {
    writeln(A);
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
proc kernel_fdtd2d(dist_1D, dist_2D, m_dim: int, n_dim: int) {
    var X = initialize_2D(dist_2D, 0, m_dim);
    var Y = initialize_2D(dist_2D, 1, n_dim);
    var Z = initialize_2D(dist_2D, 2, m_dim);
    
    var fict = initialize_1D(dist_1D);
    
    const x_stencil = {1..m_dim, 2..n_dim}, x_stencil_offset = {1..m_dim, 1..n_dim - 1};
    const y_stencil = {2..m_dim, 1..n_dim}, y_stencil_offset = {1..m_dim - 1, 1..n_dim};
    const z_stencil = {1..m_dim - 1, 1..n_dim - 1}, z_stencil_xOffset = {2..m_dim, 1..n_dim - 1}, 
        z_stencil_yOffset = {1..m_dim-1, 2..n_dim};
    
    for t in 1..TMAX {
        Y[1,..] = fict[t];
        
        forall(a,b,c) in zip(X(x_stencil), Z(x_stencil), Z(x_stencil_offset)) {
            a -= (0.5 * (b-c));
        }
        
        forall(a,b,c) in zip (Y(y_stencil), Z(y_stencil), Z(y_stencil_offset)) {
            a -= (0.5 * (b-c));
        }
        
        forall(a,b,c,d,e) in zip(Z(z_stencil), X(z_stencil_yOffset), X(z_stencil), 
            Y(z_stencil_xOffset), Y(z_stencil)) {
            a -= (0.7 * (b + d - (c + e)));
        }
    }
    
 
    if (printData) {
        writeln("X:");
        print_2D(X, m_dim, n_dim);
        writeln("Y:");
        print_2D(Y, m_dim, n_dim);
        writeln("Z:");
        print_2D(Z, m_dim, n_dim);
    }
}

proc main() {
    /* Initialize the domains */
    var dom_1D = {1..TMAX};
    var dom_2D = {1..M, 1..M};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var dist_2D = dom_2D;
        var dist_1D = dom_1D;
        /* Run the benchmark */
        kernel_fdtd2d(dist_1D, dist_2D, M, N); 
    } else if dist == "CM" {
        var dist_1D = dom_1D dmapped CyclicZipOpt(startIdx=dom_1D.low);
        var dist_2D = dom_2D dmapped CyclicZipOpt(startIdx=dom_2D.low);
        kernel_fdtd2d(dist_1D, dist_2D, M, N);
    } else if dist == "C" {
        var dist_1D = dom_1D dmapped Cyclic(startIdx=dom_1D.low);
        var dist_2D = dom_2D dmapped Cyclic(startIdx=dom_2D.low);
        kernel_fdtd2d(dist_1D, dist_2D, M, N); 
    } else if dist == "B" {
        var dist_1D = dom_1D dmapped Block(boundingBox=dom_1D);
        var dist_2D = dom_2D dmapped Block(boundingBox=dom_2D);
        kernel_fdtd2d(dist_1D, dist_2D, M, N);
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}