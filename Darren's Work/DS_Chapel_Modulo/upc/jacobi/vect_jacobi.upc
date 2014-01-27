//source http://upc.lbl.gov/publications/Multicore_Performance_with_UPC-SIAMPP10-Zheng.pdf
//upcc vect_jacobi.upc -nopthreads -T=4 --network=udp --opt && upcrun -n 4 -localhost a.out
//upcc -nopthreads -T=4 --network=udp --nolines --opt -Wc,"-DRANGER" -Wu,"-Wb,-do-msg-vect" -Ww,-do-msg-vect -Ww,-do-msg-vect vect_jacobi.upc && upcrun -n 4 -localhost a.out

#include <upc.h>
#include <stdio.h>
#include <inttypes.h>
#include <upc_relaxed.h>
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

shared double u[ngrid][ngrid];
shared double unew[ngrid][ngrid];
shared double f[ngrid][ngrid];
	
int main(int argc, char **argv) {
  double tStart, tStop;
  int i,j,jj;


	//init arrays
	for(int i=0; i<ngrid; i++) {
		for(int j=MYTHREAD; j<ngrid; j+=THREADS) {
			u[i][j]=0;
			unew[i][j]=0;
			f[i][j]=0;
		}
	}
	unew[0][1]=1;

	//init timer
	if (MYTHREAD == 0) {
		timer_clear(1);
		timer_start(1);
		tStart = timer_read(1);
	}
	
	for(int iteration=0; iteration<iterations; iteration++) {
		for(i=0; i<ngrid; i++) {
			#pragma bupc ivdep
			for(j=MYTHREAD; j<ngrid; j+=THREADS) {
				u[i][j]=unew[i][j];
			}
		}
		
		upc_barrier;
		
		for(i=1; i<ngrid-1; i++) {
			if(MYTHREAD && MYTHREAD<ngrid-1) {
				j=MYTHREAD;
				double utmp = 0.25*(u[i+1][j]+u[i-1][j]+u[i][j+1]+u[i][j-1]-h*h*f[i][j]);
				unew[i][j] = omega * utmp + (1.0-omega)*u[i][j];
			}
		}
		
		for(i=1; i<ngrid-1; i++) {	
			#pragma bupc ivdep
			for(j=MYTHREAD+THREADS; j<ngrid-1; j+=THREADS) {
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
