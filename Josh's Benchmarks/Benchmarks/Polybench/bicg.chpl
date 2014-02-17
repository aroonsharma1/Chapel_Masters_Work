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
config var correct = false;
config var timeit = false;
config var messages = false;
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
    var still_correct = true;
	var t:Timer;
	
	if messages {
		resetCommDiagnostics();
		startCommDiagnostics();
	}
	
    /******* Start the timer: this is where we do work *******/
	if timeit {
		t = new Timer();
		t.start();
	}
	
    var A = initialize_matrix(dist, x_dim);
    var p = initialize_array(dist(1, ..));
    var r = initialize_array(dist(.., 1));
    
    var s: [dist(..,1)] real = 0.0;
    var q: [dist(1,..)] real = 0.0;

    for i in 1..x_dim {
        q[i] = 0.0;
        var q_temp: [dist(..,1)] real = 0.0;
        forall (a, b, c) in zip(s[1..y_dim], A[i, 1..y_dim], 1..y_dim) {
            a += (r[i] * b);
            q_temp[c] = (b * p[c]);
        }
        q[i] += (+ reduce(q_temp));
    } 
    
    /******* End the timer *******/
	if timeit {
	    t.stop();
		writeln("took ", t.elapsed(), " seconds");
	}
	
	//Print out communication counts (gets and puts)
	if messages {
		stopCommDiagnostics();	
		var messages=0;
		var coms=getCommDiagnostics();
		for i in 0..numLocales-1 {
			messages+=coms(i).get:int;
			messages+=coms(i).put:int;
		}
		writeln('message count=', messages);	
	}
	
    var Atest = initialize_matrix({1..x_dim, 1..y_dim}, x_dim);
    var pTest = initialize_array(dist(1, ..));
    var rTest = initialize_array(dist(.., 1));

    var sTest: [dist(..,1)] real = 0.0;
    var qTest: [dist(1,..)] real = 0.0;
	
	if correct {
	    for i in 1..x_dim {
	        qTest[i] = 0.0;
	        var q_temp: [dist(..,1)] real = 0.0;
	        forall (a, b, c) in zip(sTest[1..y_dim], Atest[i, 1..y_dim], 1..y_dim) {
	            a += (rTest[i] * b);
	            q_temp[c] = (b * pTest[c]);
	        }
	        qTest[i] += (+ reduce(q_temp));
	    } 
		
		for ii in 1..x_dim {
			still_correct &&= q[ii]==qTest[ii] && s[ii]==sTest[ii];
		}
		writeln("Is the calculation correct? ", still_correct);
		writeln("bicg computation complete.");
	}
	
    if (printData) {
		writeln("q:");
        writeln(q);
        writeln();
		writeln("s:");
        writeln(s);
        writeln();
		
		writeln("qTest:");
        writeln(qTest);
        writeln();
		writeln("sTest:");
        writeln(sTest);
        writeln();
    }
}

proc main() {
    /* Initialize the domains */
    var dom = {1..X, 1..Y};
    
    var t: Timer;
    
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
}