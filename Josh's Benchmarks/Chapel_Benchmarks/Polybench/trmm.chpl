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

config var alpha: int = 323412;

/* Initializes a matrix based on a distribution */
proc initialize_matrix(distribution, dim: int) {
    var matrix: [distribution] real = 0.0;
    for (i,j) in distribution {
        matrix[i,j] = ((i - 1.00) * (j - 1.00)) / dim;
    }
    return matrix;
}

/* Prints out the matrix passed in */
proc print_matrix(A: [], dim: int) {
    for i in 1..dim {
        for j in 1..dim {
            write(A[i,j], " ");
        }
        writeln();
    }
}

/* The process which runs the benchmark */
proc kernel_trmm(dist, dim: int) {
    var A = initialize_matrix(dist, dim);
    var B = initialize_matrix(dist, dim);

    for (i,j) in dist {
        var temp: [1..i] real = 0;
        forall (a,b,c) in zip(A[i,1..i], B[j,1..i],1..) {
            temp[c] = alpha * a * b;
        }
        B[i,j] += (+ reduce temp);
    }
    
    if (printData) {
        print_matrix(B, dim);
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
        kernel_trmm(user_dist, Dim); 
    } else if dist == "CM" {
        var user_dist = dom dmapped CyclicZipOpt(startIdx=dom.low);
        kernel_trmm(user_dist, Dim);   
    } else if dist == "C" {
        var user_dist = dom dmapped Cyclic(startIdx=dom.low);
        kernel_trmm(user_dist, Dim); 
    } else if dist == "B" {
        var user_dist = dom dmapped Block(boundingBox=dom);
        kernel_trmm(user_dist, Dim);  
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}