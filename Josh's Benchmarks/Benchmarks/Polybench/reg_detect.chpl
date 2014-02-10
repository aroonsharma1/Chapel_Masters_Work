use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
	printMatrices: Set to false if you don't want to see the matrices printed
		Default = false
	alpha: constant by which to multiply the D matrix entries by
		Default = 1
	beta: contant by which to multiply the E matrix entries by
		Default = 1
	size: size (square) of the matrices
		Default = 128
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var printGrid: bool = false;
config var grid_size: int = 6;
config var length: int = 64;
config var dist: string = "CM";
config var iterations: int = 10000;

/* Initializes a grid based on a domain distribution (might be mapped) */
proc initialize_grid(distribution, grid_size: int, variety: string) {
    var grid: [distribution] int = 0;
    if (variety == "sum_tang") {
        forall (i,j) in distribution {
            grid[i,j] = (i) * (j);
        }
    } else if (variety == "mean") {
        forall (i,j) in distribution {
            grid[i,j] = (i - j) / grid_size;
        }
    } else {
        forall (i,j) in distribution {
            grid[i,j] = (i-1) * (j - 2) / grid_size;
        }
    }
    return grid;
}

/* The process which runs the benchmark */
proc kernel_reg_detect(distribution_1d, distribution_2d, distribution_3d) {
    var sum_tang = initialize_grid(distribution_2d, grid_size, "sum_tang");
    var mean = initialize_grid(distribution_2d, grid_size, "mean");
    var path = initialize_grid(distribution_2d, grid_size, "path");
/*    var path_new: [distribution_2d] = 0;*/
    var sum_diff: [distribution_3d] int = 0;
    
/*    print_grid(sum_tang, grid_size);*/
/*    print_grid(mean, grid_size);
    print_grid(path, grid_size);*/
    
/*    const 2d_righton = {1..grid_size, 1..grid_size};
    const 3d_righton = {1..grid_size, 1..grid_size, 1..length};
    const one_before = {1..grid_size, 1..grid_size, 1..length-1};
    const one_after = {1..grid_size, 1..grid_size, 2..length};*/

/*    if (printMatrices) {
        writeln("A:");
        print_matrix(A, matrix_size);
        writeln();
        print_locale_data(A, matrix_size);
        writeln();
        writeln("B:");
        print_matrix(B, matrix_size);
        writeln();
        print_locale_data(B, matrix_size);
        writeln();
        writeln("C:");
        print_matrix(C, size);
        writeln();
        print_locale_data(C, matrix_size);
        writeln();
    }*/
    
/*    for a in (sum_diff[1.., grid_size, length]) {
        write(a.locale.id, " ");
    }
    writeln();*/
    
    for i in 1..iterations {
        for (j, k) in distribution_2d {
                var temp: [distribution_1d] int = 0;
/*            sum_diff[j,k,1..length] = [1..length] dmapped CyclicZipOpt(startIdx=1);*/
            if (k >= j) {
                var start_diff = sum_tang[j,k];
                sum_diff[j,k,1] = start_diff;
                temp[1] = start_diff;
                for (a, b) in zip(sum_diff[2..length], sum_diff[1..length-1]) {
/*                    writeln(a.locale.id, " ", b.locale.id);*/
                    a = b + start_diff;
                }
                forall(a, b) in zip(sum_diff[j,k,1..], temp) {
                    a = b;
                }
/*                sum_diff[j,k,1..] = temp;*/
                mean[j,k] = sum_diff[j,k, length];
            }
        }

        forall (a, b) in zip(path[1,..], mean[1,..]) {
            a = b;
        }
        
        for (j, k) in distribution_2d {
            if (j > 1 && k >= j) {
                path[j,k] = path[j-1, k-1] + mean[j,k];
            }
        }
    }
    
    

/*    forall (i,j) in distribution {
        var tempArray: [1..matrix_size] real;
        forall (a, b, k) in zip(A[i, 1..matrix_size], B[1..matrix_size, j], 1..) {
            var temp = a * b;
            tempArray[k] = temp;
        }
        C[i,j] = alpha * (+ reduce (tempArray));
    }
    
    forall (i,j) in distribution {
        var tempArray: [1..matrix_size] real;
        forall (d, c, k) in zip(D[i, 1..matrix_size], C[1..matrix_size, j], 1..) {
            var temp = d * c;
            tempArray[k] = temp;
        }
        E[i,j] = beta * (+ reduce (tempArray));
    }*/

    
    if (printGrid) {
        writeln("Path:");
        print_grid(path, grid_size);
       /* writeln();
        print_locale_data(D, matrix_size);
        writeln();
        writeln("E:");
        print_matrix(E, size);
        writeln();
        print_locale_data(E, matrix_size);
        writeln();*/
    }  
/*    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());*/
}

/* Prints out the square matrix passed in */
proc print_grid(A: [], grid_size: int) {
    for i in 1..grid_size {
        for j in 1..grid_size {
            write(A[i,j], " ");
        }
        writeln();
    }
}

/* Print out locale distribution */
proc print_locale_data(A:[], matrix_size: int) {
    var count: int = 0;
    for a in A {
        count += 1;
        write(a.locale.id);
        if (count == matrix_size) {
            count = 0;
            writeln();
        }
    }
}

proc main() {
    /* Initialize the data */
    var dom_1d = {1..length};
    var dom_2d = {1..grid_size, 1..grid_size};
    var dom_3d = {1..grid_size, 1..grid_size, 1..length};
    
    if dist == "NONE" {
/*        var user_dist = dom;*/
        /* Run the benchmark */
/*        kernel_2mm(alpha, beta, user_dist, size); */
    } else if dist == "CM" {
        var dist_1d = dom_1d dmapped CyclicZipOpt(startIdx=dom_1d.low);
        var dist_2d = dom_2d dmapped CyclicZipOpt(startIdx=dom_2d.low);
        var dist_3d = dom_3d dmapped CyclicZipOpt(startIdx=(1,1,1));
        kernel_reg_detect(dist_1d, dist_2d, dist_3d);   
    } else if dist == "C" {
      /*  var user_dist = dom dmapped Cyclic(startIdx=dom.low);
        kernel_2mm(alpha, beta, user_dist, size);   */
    } else if dist == "B" {
/*        var user_dist = dom dmapped Block(boundingBox=dom);
        kernel_2mm(alpha, beta, user_dist, size);   */
    }       
}