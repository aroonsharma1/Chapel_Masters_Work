//source http://upc.lbl.gov/publications/Multicore_Performance_with_UPC-SIAMPP10-Zheng.pdf
//upcc nomodulo_jacobi.upc -nopthreads -T=4 --network=udp && upcrun -n 4 -localhost a.out

#include <upc.h>
#include <stdio.h>
#include <inttypes.h>
#include <upc_relaxed.h>
//#include "../builtin/benchmarks/bupc_timers.h"
#include "bupc_timers.h"

//grid size (assume padded)
#ifndef ngrid
	#define ngrid 8
#endif
#ifndef debug
	#define debug (ngrid<10)
#endif

//iterations
#ifndef iterations
	#define iterations 20
#endif

#define omega 0.5

#define h 0.1

// block distribution
// shared [*] double u[ngrid][ngrid];
// shared [*] double unew[ngrid][ngrid];
// shared [*] double f[ngrid][ngrid];

//cyclic distribution (slow)
shared double u[ngrid][ngrid];
shared double unew[ngrid][ngrid];
shared double f[ngrid][ngrid];

	
int main(int argc, char **argv) {
  double tStart, tStop;
  int i,j;


	if (MYTHREAD == 0) {
	//init arrays
		upc_forall(int i=0; i<ngrid; i++; &unew[i][0]) {
			for(int j=0; j<ngrid; j++) {
				u[i][j]=0;
				unew[i][j]=0;
				f[i][j]=0;
			}
		}
		unew[0][1]=1;
	}

	//init timer
	if (MYTHREAD == 0) {
		timer_clear(1);
		timer_start(1);
		tStart = timer_read(1);
	}
	
	for(int iteration=0; iteration<iterations; iteration++) {
		upc_forall(i=0; i<ngrid; i++; &unew[i][0] ) {
			for(j=0; j<ngrid; j++) {
				u[i][j]=unew[i][j];
			}
		}
		
		upc_barrier;
		
		upc_forall(i=1; i<ngrid-1; i++; &unew[i][0] ) {
			for(j=1; j<ngrid-1; j++) {
				double utmp = 0.25*(u[i+1][j]+u[i-1][j]+u[i][j+1]+u[i][j-1]-h*h*f[i][j]);
				unew[i][j] = omega * utmp + (1.0-omega)*u[i][j];
			}
		}
		
		upc_barrier;
	}
	
	//show time
	if (MYTHREAD == 0) {
		timer_stop(1);
		tStop = timer_read(1);
		printf("%g seconds\n", tStop-tStart);
	
		//show results
		if (debug) {
			for(int i=0; i<ngrid; i++) {
				for(int j=0; j<ngrid; j++) {
					printf("%f ", unew[i][j]);
				}
				printf("\n");
			}
		}
	}
}
