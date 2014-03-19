use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
	printData: Set to false if you don't want to see the arrays printed
		Default = false
	X: x dimension of the distribution 
		Default = 128
    Y: y dimension of the distribution
        Default = 128
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var printData: bool = false;
config var dist: string = "CM";

config var X: int = 128;
config var Y: int = 128;

const pi: real = 3.14159265358979323846;

/* Initializes a matrix based on a distribution */
proc initialize_matrix(distribution, x_dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1.00) * j) / x_dim;
    }
    return matrix;
}

/* Initializes an array based on a distribution */
proc initialize_array(distribution) {
    var array: [distribution] real = 0.0;
    for i in distribution {
        array[i] = (i-1) * pi;
    }
    return array;
}

/* Prints out the matrix passed in */
proc print_matrix(A: [], x_dim: int, y_dim: int) {
    for i in 1..x_dim {
        for j in 1..y_dim {
            write(A[i,j], " ");
        }
        writeln();
    }
}

/* Prints out the array passed in */
proc print_array(array: [], dim: int) {
    for i in dim {
        write(array[i], " ");
    }
}

/* The process which runs the benchmark */
proc kernel_bicg(dist, x_dim: int, y_dim: int) {
    var A = initialize_matrix(dist, x_dim);
    var p = initialize_array(dist(1, ..));
    var r = initialize_array(dist(.., 1));
    
    var s: [dist(..,1)] real = 0.0;
    var q: [dist(1,..)] real = 0.0;

    for i in 1..x_dim {
        q[i] = 0.0;
        var q_temp: [dist(..,1)] real = 0.0;
        forall (a, b, c) in zip(s[dist(1,..)], A[i, dist(1,..)], 1..y_dim) {
            a += (r[i] * b);
            q_temp[c] = (b * p[c]);
        }
        q[i] += (+ reduce(q_temp));
    } 
    
    if (printData) {
        writeln(q);
        writeln();
        writeln();
        writeln(s);
        writeln();
        writeln();
    }
}

proc main() {
    /* Initialize the domains */
    var dom = {1..X, 1..Y};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var user_dist = dom;
        /* Run the benchmark */
        kernel_bicg(user_dist, X, Y); 
    } else if dist == "CM" {
        var user_dist = dom dmapped CyclicZipOpt(startIdx=dom.low);
        kernel_bicg(user_dist, X, Y);   
    } else if dist == "C" {
        var user_dist = dom dmapped Cyclic(startIdx=dom.low);
        kernel_bicg(user_dist, X, Y); 
    } else if dist == "B" {
        var user_dist = dom dmapped Block(boundingBox=dom);
        kernel_bicg(user_dist, X, Y);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}