use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
	printData: Set to false if you don't want to see the arrays printed
		Default = false
	Dim: dimension (square) of the distribution 
		Default = 128
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var printData: bool = false;
config var dist: string = "CM";

config var Dim: int = 128;

/* Initializes a matrix based on a distribution */
proc initialize_matrix(distribution, dim: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1.00) * (j - 1.00)) / dim;
    }
    return matrix;
}

/* Initializes an array based on a distribution */
proc initialize_array(distribution, dim: int, array_name: string) {
    var array: [distribution] real = 0.0;
    var adder: real;
    
    if (array_name == "x1") {
        adder = -1.0;
    } else if (array_name == "x2") {
        adder = 0.0;
    } else if (array_name == "y1") {
        adder = 2.0;
    } else {
        adder = 3.0;
    }
    for i in distribution {
        array[i] = (i + adder) / dim;
    }
    return array;
}

/* Prints out the matrix passed in */
proc print_matrix(A: [], dim: int) {
    for i in 1..dim {
        for j in 1..dim {
            write(A[i,j].locale.id, " ");
        }
        writeln();
    }
}

/* The process which runs the benchmark */
proc kernel_mvt(dist, dim: int) {
    var A = initialize_matrix(dist, dim);
    var x1 = initialize_array(dist(1, ..), dim, "x1");
    var x2 = initialize_array(dist(1, ..), dim, "x2");
    var y1 = initialize_array(dist(1, ..), dim, "y1");
    var y2 = initialize_array(dist(1, ..), dim, "y2");

/*   print_matrix(A, dim);
   writeln();
    writeln();
    writeln(x1);
    writeln();
    writeln();
    writeln(x2);
    writeln();
    writeln();
    writeln(y1);
    writeln();
    writeln();
    writeln(y2);
    writeln();
    writeln();*/
    for i in 1..dim {
        var x1_temp: [dist(1, ..)] real = 0.0;
        var x2_temp: [dist(1, ..)] real = 0.0;
        forall (a, b, c, d, e) in zip(A[i, 1..dim], A[1..dim, i], y1, y2, 1..dim) {
            x1_temp[e] = a * c;
            x2_temp[e] = b * d;
        }
        x1[i] += (+ reduce(x1_temp));
        x2[i] += (+ reduce(x2_temp));
    } 
    
    if (printData) {
        writeln(x1);
        writeln();
        writeln();
        writeln(x2);
        writeln();
        writeln();
    }
}

proc main() {
    /* Initialize the domains */
    var dom = {1..Dim, 1..Dim};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var user_dist = dom;
        /* Run the benchmark */
        kernel_mvt(user_dist, Dim); 
    } else if dist == "CM" {
        var user_dist = dom dmapped CyclicZipOpt(startIdx=dom.low);
        kernel_mvt(user_dist, Dim);   
    } else if dist == "C" {
        var user_dist = dom dmapped Cyclic(startIdx=dom.low);
        kernel_mvt(user_dist, Dim); 
    } else if dist == "B" {
        var user_dist = dom dmapped Block(boundingBox=dom);
        kernel_mvt(user_dist, Dim);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}