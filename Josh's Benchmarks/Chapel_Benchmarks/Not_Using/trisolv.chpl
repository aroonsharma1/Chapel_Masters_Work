use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
    Dimensions are set up to be M x M. 
    M: Default = 128

	printData: Set to false if you don't want to see the data printed
		Default = false
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var M: int = 128;

config var printData: bool = false;
config var dist: string = "CM";

/* Initializes a 1D structure */
proc initialize_1D(distribution, m_dim: int) {
    var array: [distribution] real = 0.0;
    forall i in distribution {
        array[i] = (i + 0.0) / m_dim;
    }
    return array;
}

/* Initializes a 2D structure */
proc initialize_2D(distribution, m_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i + 1) * (j)) / (1.0 * m_dim);
    }
    return matrix;
}

/* Prints out the 1D structure passed in */
proc print_1D(A: []) {
    writeln(A);
}

/* Prints out the 2D structure passed in */
proc print_2D(A: [], m_dim: int) {
    for i in 1..m_dim {
        write("     ");
        for j in 1..m_dim {
            write(A[i,j], " ");
        }
        writeln();
    }
}

/* The process which runs the benchmark */
proc kernel_trisolv(dist_1D, dist_2D, m_dim: int) {
    var A = initialize_2D(dist_2D, m_dim);
    var x = initialize_1D(dist_1D, m_dim);
    var c = initialize_1D(dist_1D, m_dim);

    for i in 1..m_dim {
        x[i] = c[i];
        var temp: real = x[i];
        var tempArray: [1..i-1] real;
        forall (a,b,c) in zip(A[i, 1..i-1], x[1..i-1], 1..) {
            tempArray[c] = a * b;
        }
        x[i] = temp - (+ reduce (tempArray));
        temp = x[i];
        x[i] = temp / A[i, i];
    }
    
    if (printData) {
        writeln("A:");
        print_2D(A, m_dim);
        writeln("c:");
        print_1D(c);
        writeln("x:");
        print_1D(x);
    }
}

proc main() {
    /* Initialize the domains */
    var dom_1D = {1..M};
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
        kernel_trisolv(dist_1D, dist_2D, M); 
    } else if dist == "CM" {
        var dist_1D = dom_1D dmapped CyclicZipOpt(startIdx=dom_1D.low + 1);
        var dist_2D = dom_2D dmapped CyclicZipOpt(startIdx=dom_2D.low);
        kernel_trisolv(dist_1D, dist_2D, M);
    } else if dist == "C" {
        var dist_1D = dom_1D dmapped Cyclic(startIdx=dom_1D.low);
        var dist_2D = dom_2D dmapped Cyclic(startIdx=dom_2D.low);
        kernel_trisolv(dist_1D, dist_2D, M); 
    } else if dist == "B" {
        var dist_1D = dom_1D dmapped Block(boundingBox=dom_1D);
        var dist_2D = dom_2D dmapped Block(boundingBox=dom_2D);
        kernel_trisolv(dist_1D, dist_2D, M);
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}