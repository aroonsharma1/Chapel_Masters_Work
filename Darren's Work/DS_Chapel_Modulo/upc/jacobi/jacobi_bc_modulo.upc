//source //http://upc.lbl.gov/publications/Multicore_Performance_with_UPC-SIAMPP10-Zheng.pdf
//http://upc.gwu.edu/~upc/upcworkshop04/bonachea-memcpy-0904-final.pdf

//upcc ourjacobi.upc -nopthreads -T=4 --network=udp && upcrun -n 4 -localhost a.out

//on umiacs export GASNET_SPAWNFN=L , no -localhost

#include <upc.h>

#include <bupc_extensions.h>

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

shared double u[ngrid][ngrid];
shared double unew[ngrid][ngrid];
shared double f[ngrid][ngrid];
	
int main(int argc, char **argv) {
	double buf1[ngrid];
	double buf2[ngrid];
	double tStart, tStop;
	int i,j,iter;


	//init arrays
	for(i=0; i<ngrid; i++) {
		for(j=MYTHREAD; j<ngrid; j+=THREADS) {
			u[i][j]=0;
			unew[i][j]=0;
			f[i][j]=0;
		}
	}
	
	for(i=0; i<ngrid; i++) { buf1[i]=0; buf2[i]=0; }; 
	unew[0][1]=1;

	//init timer
	if (MYTHREAD == 0) {
		timer_clear(1);
		timer_start(1);
		tStart = timer_read(1);
	}
	
	for(int iteration=0; iteration<iterations; iteration++) {		
		
		 // known local copy
		double *ulocal=(double *) u;
		double *unewlocal=(double *) unew;

		memcpy(ulocal, unewlocal, sizeof(double)*(ngrid*ngrid/THREADS));
		
		upc_barrier;
		
		for(i=1; i<ngrid-1; i++) {
			//get buffers
			int ji;			
			bupc_handle_t leftfetch_handle;
			leftfetch_handle = bupc_memget_async(buf1, &u[i][MYTHREAD?MYTHREAD-1:THREADS-1], sizeof(double)*ngrid);
			
			bupc_handle_t rightfetch_handle;
			rightfetch_handle = bupc_memget_async(buf2, &u[i][MYTHREAD?MYTHREAD+1:THREADS+1], sizeof(double)*ngrid);
			
			bupc_waitsync(leftfetch_handle);
			bupc_waitsync(rightfetch_handle);

			double *buf4=(double *) &u[i+1][MYTHREAD?MYTHREAD:THREADS];
			double *buf3=(double *) &u[i-1][MYTHREAD?MYTHREAD:THREADS];
			
			for(iter=0, j=MYTHREAD?MYTHREAD:THREADS; j<ngrid-1; iter++, j+=THREADS) {
				double utmp = 0.25*(buf4[iter]+buf3[iter]+buf2[iter]+buf1[iter]-h*h*f[i][j]);
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
