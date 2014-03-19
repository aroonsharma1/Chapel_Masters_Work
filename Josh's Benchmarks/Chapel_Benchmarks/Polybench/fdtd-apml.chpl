use CyclicZipOpt;
use BlockDist;
use Time;
use CommDiagnostics;

/****************************
    Dimensions are set up by M x N x P. If the data structure is 2D, then M x N. 
    If the data structue is 1D, then M.
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

const mui: int = 2341;
const ch: int = 42;

/* Initializes a 1D structure */
proc initialize_1D(distribution, adder: int, divider:int) {
    var array: [distribution] real = 0.0;
    forall i in distribution {
        array[i] = (i - 1.0 + adder) / divider;
    }
    return array;
}

/* Initializes a 2D structure */
proc initialize_2D(distribution, adder_1: int, adder_2: int, divider: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j) in distribution {
        matrix[i,j] = ((i - 1.0) * ((j - 1.0) + adder_1) + adder_2) / divider;
    }
    return matrix;
}

/* Initializes a 3D structure */
proc initialize_3D(distribution, adder_1: int, adder_2: int, divider: int) {
    var matrix: [distribution] real = 0.0;
    forall (i,j,k) in distribution {
        matrix[i,j,k] = (((i - 1.0) * ((j - 1.0) + adder_1)) + ((k - 1.0) + adder_2)) / divider;
    }
    return matrix;
}

/* Prints out the 1D structure passed in */
proc print_1D(A: []) {
    write("     ");
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

/* Prints out the 3D structure passed in */
proc print_3D(A: [], m_dim: int, n_dim: int, p_dim: int) {
    for i in 1..m_dim {
        for j in 1..m_dim {
            write("     ");
            for k in 1..p_dim {
                write(A[i,j,k], " ");
            }
            writeln();
        }
        writeln();
    }
}

/* The process which runs the benchmark */
proc kernel_fdtdapml(dist_1D, dist_2D, dist_3D, m_dim: int, n_dim: int, p_dim: int) {
    /* 1D variables */
    var czm = initialize_1D(dist_1D, 1, m_dim);
    var czp = initialize_1D(dist_1D, 2, m_dim);
    var cxmh = initialize_1D(dist_1D, 3, m_dim);
    var cxph = initialize_1D(dist_1D, 4, m_dim);
    var cymh = initialize_1D(dist_1D, 5, m_dim);
    var cyph = initialize_1D(dist_1D, 6, m_dim);
    
    /* 2D variables */
    var Ax = initialize_2D(dist_2D, 2, 11, m_dim);
    var Ry = initialize_2D(dist_2D, 1, 10, n_dim);
    var clf: [dist_2D] real = 0.0; 
    var tmp: [dist_2D] real = 0.0;
    
    /* 3D variables */
    var Ex = initialize_3D(dist_3D, 3, 1, m_dim);
    var Ey = initialize_3D(dist_3D, 4, 2, n_dim);
    var Hz = initialize_3D(dist_3D, 5, 3, p_dim);
    var Bza: [dist_3D] real = 0.0;
    
    /* Lock */
    var lock: sync bool;
    
    for iz in 1..p_dim {
        for iy in 1..n_dim {
            forall(a, b, c, d, e) in zip(Ex[iz, iy, 1..m_dim], Ex[iz, iy + 1, 1..m_dim],
                Ey[iz, iy, 2..m_dim + 1], Ey[iz, iy, 1..m_dim], 1..) {
                clf[iz, iy] = a - b + c - d;
                tmp[iz, iy] = (cymh[iy] / cyph[iy]) * Bza[iz, iy, e] - (ch / cyph[iy]) * clf[iz, iy];  
            }
            
            forall (a, b, c) in zip(Hz[iz,iy, 1..m_dim], Bza[iz,iy,1..m_dim], 1..) {
                a = (cxmh[c] / cxph[c]) * a + (mui * czp[iz] / cxph[c]) * tmp[iz, iy] - (mui * czm[iz] / cxph[c]) * b;
                b = tmp[iz,iy];
            }    
            
            clf[iz, iy] = Ex[iz, iy, m_dim + 1] - Ex[iz, iy+1, m_dim + 1] + Ry[iz, iy] - Ey[iz, iy, m_dim + 1];
            tmp[iz, iy] = (cymh[iy] / cyph[iy]) * Bza[iz, iy, m_dim + 1] - (ch / cyph[iy]) * clf[iz, iy];
            Hz[iz, iy, m_dim + 1]= (cxmh[m_dim + 1] / cxph[m_dim + 1]) * Hz[iz, iy, m_dim + 1]
              + (mui * czp[iz] / cxph[m_dim + 1]) * tmp[iz, iy]
              - (mui * czm[iz] / cxph[m_dim + 1]) * Bza[iz, iy, m_dim + 1];
            Bza[iz, iy, m_dim + 1] = tmp[iz, iy]; 
            
            forall(a, b, c, d, e, f, g) in zip(Ex[iz, n_dim + 1, 1..m_dim], Ey[iz, n_dim + 1, 2..m_dim + 1],
                Ey[iz, n_dim + 1, 1..m_dim], Ax[iz, 1..], 1.., Hz[iz, n_dim + 1, 1..m_dim], Bza[iz, n_dim + 1, 1..m_dim]) {
                lock = true;
                clf[iz, iy] = a + b - c - d;
                tmp[iz, iy] = (cymh[n_dim + 1] / cyph[iy]) * Bza[iz, iy, e] - (ch / cyph[iy]) * clf[iz, iy];  
                f = (cxmh[e] / cxph[e]) * f + (mui * czp[iz] / cxph[e]) * tmp[iz, iy] - (mui * czm[iz] / cxph[e]) * g;
                g = tmp[iz,iy];
                var unlock = lock;
            }        
            
            clf[iz, iy] = Ex[iz, n_dim + 1, m_dim + 1] - Ax[iz, n_dim + 1] + Ry[iz, n_dim + 1] - Ey[iz, n_dim + 1, m_dim + 1];
            tmp[iz, iy] = (cymh[n_dim + 1] / cyph[n_dim + 1]) * Bza[iz, n_dim + 1, m_dim + 1] - (ch / cyph[n_dim + 1]) * clf[iz, iy];
            Hz[iz, n_dim + 1, m_dim + 1]= (cxmh[m_dim + 1] / cxph[m_dim + 1]) * Hz[iz, n_dim + 1, m_dim + 1]
              + (mui * czp[iz] / cxph[m_dim + 1]) * tmp[iz, iy]
              - (mui * czm[iz] / cxph[m_dim + 1]) * Bza[iz, n_dim + 1, m_dim + 1];
            Bza[iz, n_dim + 1, m_dim + 1] = tmp[iz, iy]; 
        }                  
    }
    
    if (printData) {
        writeln("czm:");
        print_1D(czm);
        writeln("czp:");
        print_1D(czp);
        writeln("cxmh:");
        print_1D(cxmh);
        writeln("cxph:");
        print_1D(cxph);
        writeln("cymh:");
        print_1D(cymh);
        writeln("cyph:");
        print_1D(cyph);
        writeln("Ax:");
        print_2D(Ax, m_dim + 1, n_dim + 1);
        writeln("Ry:");
        print_2D(Ry, m_dim + 1, n_dim + 1);
        writeln("Ex:");
        print_3D(Ex, m_dim + 1, n_dim + 1, p_dim + 1);
        writeln("Ey:");
        print_3D(Ey, m_dim + 1, n_dim + 1, p_dim + 1);
        writeln("Hz:");
        print_3D(Hz, m_dim + 1, n_dim + 1, p_dim + 1);
       writeln("Bza:");
       print_3D(Bza, m_dim + 1, n_dim + 1, p_dim + 1);
    }
}

proc main() {
    /* Initialize the domains */
    var dom_1D = {1..M+1};
    var dom_2D = {1..M+1, 1..N+1};
    var dom_3D = {1..M+1, 1..N+1, 1..P+1};
    
    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    if dist == "NONE" {
        var dist_1D = dom_1D;
        var dist_2D = dom_2D;
        var dist_3D = dom_3D;
        /* Run the benchmark */
        kernel_fdtdapml(dist_1D, dist_2D, dist_3D, M, N, P); 
    } else if dist == "CM" {
        var dist_1D = dom_1D dmapped CyclicZipOpt(startIdx=dom_1D.low);
        var dist_2D = dom_2D dmapped CyclicZipOpt(startIdx=dom_2D.low);
        var dist_3D = dom_3D dmapped CyclicZipOpt(startIdx=dom_3D.low);
        kernel_fdtdapml(dist_1D, dist_2D, dist_3D, M, N, P); 
    } else if dist == "C" {
        var dist_1D = dom_1D dmapped CyclicZipOpt(startIdx=dom_1D.low);
        var dist_2D = dom_2D dmapped Cyclic(startIdx=dom_2D.low);
        var dist_3D = dom_3D dmapped Cyclic(startIdx=dom_3D.low);
        kernel_fdtdapml(dist_1D, dist_2D, dist_3D, M, N, P); 
    } else if dist == "B" {
        var dist_1D = dom_1D dmapped CyclicZipOpt(startIdx=dom_1D.low);
        var dist_2D = dom_2D dmapped Block(boundingBox=dom_2D);
        var dist_3D = dom_3D dmapped Block(boundingBox=dom_3D);
        kernel_fdtdapml(dist_1D, dist_2D, dist_3D, M, N, P); 
    } 
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();   
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics());
}