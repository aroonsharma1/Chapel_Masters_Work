use BlockDist;
use Time;
use CommDiagnostics;
use DistPlus;

/****************************
    Dimensions are set up to be M.
    M: 1st dimension
        Default = 10000

    TSTEPS: The number of iterations to perform
        Default = 100

	printData: Set to false if you don't want to see the data printed
		Default = false
    dist: the distribution of the domain which the matrices are based on. 
        Default: cyclical with modulo unrolling
*****************************/
config var M: int = 10000;

config var TSTEPS: int = 100;

config var debug: bool = false;

config var printData: bool = false;

/* Initializes a 1D structure */
proc initialize_1D(distribution, adder: int, divider: int) {
    var array: [distribution] real = 0.0;
    forall i in distribution {
        array[i] = (i - 1.0 + adder) / divider;
    }
    return array;
}

/* Prints out the 1D structure passed in */
proc print_1D(A: []) {
    writeln(A);
    for i in A {
        write(i.locale.id, " ");
    }
    writeln();
}

/* Returns if index is in a range */
proc in_range(num, range1): bool {
    if (num >= range1.low && num <= range1.high) {
        return true;
    }
    return false;
}

/* Returns if range1 is a subset of range2 */
proc is_subset(range1, range2): bool {
    var low1 = range1.low;
    var low2 = range2.low;
    var high1 = range1.high;
    var high2 = range2.high;
    
    if (low1 >= low2 && high1 <= high2) {
        return true;
    }
    return false;   
}

/* Returns the low range of range1 that is outside of range2 */
proc outside_low_range(range1, range2) {
    var low1 = range1.low;
    var low2 = range2.low;
    
    if (low1 <= low2) {
        return {low1..low2};
    }
    
    return {-1..0};
}

/* Returns the high range of range1 that is outside of range2 */
proc outside_high_range(range1, range2) {
    var high1 = range1.high;
    var high2 = range2.high;
    
    if (high1 > high2) {
        return {high2..high1};
    }
    
    return {-1..0};
}

/* Determines if two ranges intersect */
proc does_intersect(range1, range2): bool {
    var low1 = range1.low;
    var low2 = range2.low;
    var high1 = range1.high;
    var high2 = range2.high;
    
    if low1 <= low2 {
        if high1 >= low2 {
            return true;
        } else {
            return false;
        }
    } else {
        if high2 >= low1 {
            return true;
        } else {
            return false;
        }
    }
}

/* Computes the intersection of two ranges (in 1 dimension) */
proc compute_intersection(range1, range2) {
    var low1 = range1.low;
    var low2 = range2.low;
    var high1 = range1.high;
    var high2 = range2.high;
    
    var low: int = -1, high: int = -1;
    
    if low1 <= low2 {
        if high1 >= low2 {
            low = low2;
            if (high1 < high2) {
                high = high1;
            } else {
                high = high2;
            }
        }
    } else {
        if high2 >= low1 {
            low = low1;
            if (high1 < high2) {
                high = high1;
            } else {
                high = high2;
            }
        }
    }
    return {low..high};
}

proc BlockArr.TestGetsPuts(src, lloc: int, rloc: int) {
    var stridelevels=1;
    var dststrides:[1..#stridelevels] int(32);
    var srcstrides: [1..#stridelevels] int(32);
    var count: [1..#(stridelevels+1)] int(32);
    var lid=lloc;
    var rid = rloc;

    on Locales[lid] {
        dststrides[1]=1;
        srcstrides[1]=1;
        count[1]=1;
        count[2]=1;
        var dest = locArr[lid].myElems._value.theData;
        var srcr = src._value.locArr[rid].myElems._value.theData;
        var dststr=dststrides._value.theData;
        var srcstr=srcstrides._value.theData;
        var cnt=count._value.theData;
  
        __primitive("chpl_comm_get_strd",
            __primitive("array_get",dest,
                    locArr[lid].myElems._value.getDataIndex(2)),
            __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
            rid,
            __primitive("array_get",srcr,
                    src._value.locArr[rid].myElems._value.getDataIndex(4)),
            __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
            __primitive("array_get",cnt, count._value.getDataIndex(1)),
            stridelevels);
    }
}

proc Wrapper(dest:[], src:[], lloc: int, rloc:int) {
    writeln("lloc: ", lloc, ", rloc: ", rloc);
    dest._value.TestGetsPuts(src,lloc,rloc);

}

/* The process which runs the benchmark */
proc kernel_jacobi1d(dist_1D, m_dim: int) {
    var A = initialize_1D(dist_1D, 2, m_dim);
    var B = initialize_1D(dist_1D, 3, m_dim);

    var loop_space = {2..m_dim - 1};
    
    for t in 1..TSTEPS { //Beginning of TSTEPS for loop
        for loc in Locales do on loc { //Beginning of locale for loop
            if A.subIsSingle() {
                if does_intersect(A.mySubdomain(), loop_space) {
                    var xl_diff_high, xl_diff_low, xr_diff_high, xr_diff_low: int;
                    var left_intersect, right_intersect, left_diff, right_diff: domain(1);
                    var intersection, outside_low, outside_high: domain(1);
                
                    /* Compute the intersection between the current locale and the loop space */
                    intersection = compute_intersection(A.mySubdomain(), loop_space);
                    var left_stencil = {intersection.low - 1..intersection.high - 1};
                    var right_stencil = {intersection.low + 1..intersection.high + 1}; 
                    var buf_l: [left_stencil] real;
                    var buf_r: [right_stencil] real;
                
                    /* 
                     * Compute the difference, the elements that are in the stencils that are not 
                     * in the intersection of the current locale and the loop space
                     * ie. xxxllll-------, where x's l's are in the stencil, l's in intersection, computes the x's
                     */
                    if (does_intersect(intersection, left_stencil) && does_intersect(intersection, right_stencil)) {
                        left_intersect = compute_intersection(left_stencil, intersection);
                        right_intersect = compute_intersection(right_stencil, intersection);
                    
                        xl_diff_high = left_intersect.high - left_stencil.high;
                        xl_diff_low = left_intersect.low - left_stencil.low;
                
                        xr_diff_high = right_intersect.high - right_stencil.high;
                        xr_diff_low = right_intersect.low - right_stencil.low;
                
                        if xl_diff_low != 0 && xl_diff_high == 0 {
                            left_diff = {left_stencil.low..left_intersect.low - 1};
                        }
               
                        if xr_diff_low == 0 && xr_diff_high != 0 {
                            right_diff = {right_intersect.high..right_stencil.high};
                        }
                    } else {
                        left_diff = left_stencil;
                        right_diff = right_stencil;
                    }
 
                    /* Compute the elements in the left difference computed above not on the current locale */
                    if !is_subset(left_diff, A.mySubdomain()) {
                        outside_low = outside_low_range(left_diff, A.mySubdomain());

                        if (outside_low.low != -1) {
                            var diff: int(32) = (outside_low.high - outside_low.low):int(32);
                            var stridelevels=1;
                            var dststrides:[1..#stridelevels] int(32);
                            var srcstrides: [1..#stridelevels] int(32);
                            var count: [1..#(stridelevels+1)] int(32);
                            var lid=loc.id;
                            var rid = lid-1;

                            dststrides[1]=1;
                            srcstrides[1]=1;
                            count[1]=1;
                            count[2]=diff;
                            var dest = buf_l._value.theData;
                            var src = A._value.locArr[rid].myElems._value.theData;
                            var dststr=dststrides._value.theData;
                            var srcstr=srcstrides._value.theData;
                            var cnt=count._value.theData;

                            __primitive("chpl_comm_get_strd",
                                __primitive("array_get",dest,
                                        buf_l._value.getDataIndex(left_stencil.low)),
                                __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
                                rid,
                                __primitive("array_get",src,
                                        A._value.locArr[rid].myElems._value.getDataIndex(left_stencil.low)),
                                __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
                                __primitive("array_get",cnt, count._value.getDataIndex(1)),
                                stridelevels);
                        }
                    }
                
                    /* Compute the elements in the right difference computed above not on the current locale */
                    if !is_subset(right_diff, A.mySubdomain()) {
                        outside_high = outside_high_range(right_diff, A.mySubdomain());
                   
                        if (outside_high.low != -1) {
                            var diff: int(32) = (outside_high.high - outside_high.low):int(32);
                            var stridelevels=1;
                            var dststrides:[1..#stridelevels] int(32);
                            var srcstrides: [1..#stridelevels] int(32);
                            var count: [1..#(stridelevels+1)] int(32);
                            var lid=loc.id;
                            var rid = lid+1;

                            dststrides[1]=1;
                            srcstrides[1]=diff;
                            count[1]=1;
                            count[2]=1;
                            var dest = buf_r._value.theData;
                            var src = A._value.locArr[rid].myElems._value.theData;
                            var dststr=dststrides._value.theData;
                            var srcstr=srcstrides._value.theData;
                            var cnt=count._value.theData;

                            __primitive("chpl_comm_get_strd",
                                __primitive("array_get",dest,
                                        buf_r._value.getDataIndex(right_stencil.high)),
                                __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
                                rid,
                                __primitive("array_get",src,
                                        A._value.locArr[rid].myElems._value.getDataIndex(right_stencil.high)),
                                __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
                                __primitive("array_get",cnt, count._value.getDataIndex(1)),
                                stridelevels);
                        }
                    }
                
                    for (a,b,c) in zip(B(intersection), A(intersection), intersection.low..) {
                        var left, right: real;
                        if (in_range(c-1, A.mySubdomain())) {
                            left = A[c-1];
                        } else {
                            left = buf_l[c-1];
                        }
                        if (in_range(c+1, A.mySubdomain())) {
                            right = A[c+1];
                        } else {
                            right = buf_r[c+1];
                        }
                        if (debug) {
                            writeln("A[", c, "]:", b, ", left: ", left, ", right: ", right);
                            writeln();
                            writeln();
                        }
                        a = (b + left + right) * (0.33333);
                    }
                }   
            } 
        }//End of local for loop 
        A(loop_space) = B(loop_space);
    }//End of TSTEPS for loop

    if (printData) {
        writeln("A:");
        print_1D(A);
    }
}

proc main() {
    /* Initialize the domains */
    var dom_1D = {1..M};

    var t: Timer;

    /* Start measurements */
    t.start();
    resetCommDiagnostics();
    startCommDiagnostics();
    
    var dist_1D = dom_1D dmapped Block(boundingBox=dom_1D);
    kernel_jacobi1d(dist_1D, M);
    
    /* End measurements */ 
    stopCommDiagnostics();
    t.stop();  
    
    writeln(t.elapsed(), " seconds elapsed");  
    writeln(getCommDiagnostics()); 
}