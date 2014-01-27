//source http://upc.lbl.gov/publications/Multicore_Performance_with_UPC-SIAMPP10-Zheng.pdf
//upcc ourjacobi.upc -nopthreads -T=4 --network=udp
//upcrun -n 4 -localhost a.out

#include <upc.h>
#include <stdio.h>
#include <inttypes.h>
#include <upc_relaxed.h>
#include "../builtin/benchmarks/bupc_timers.h"

//grid size (assume padded)
#define ngrid 80

//iterations
#define iterations 20

#define omega 0.5

#define h 0.1

shared double u[ngrid][ngrid];
shared double unew[ngrid][ngrid];
shared double f[ngrid][ngrid];
	
int main(int argc, char **argv) {
  double tStart, tStop;
  int i,j;


	//init arrays
	for(int i=0; i<ngrid; i++) {
		for(int j=0; j<ngrid; j+=THREADS) {
			u[i][j+MYTHREAD]=0;
			unew[i][j+MYTHREAD]=0;
			f[i][j+MYTHREAD]=0;
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
		for(i=0; i<ngrid; i++ ) {
			for(j=0; j<ngrid; j+=THREADS) {
				u[i][j+MYTHREAD]=unew[i][j+MYTHREAD]; //known to be local
			}
		}
		
		upc_barrier;
		
		for(i=1; i<ngrid-1; i++) {
			double buf1[ngrid];
			double buf2[ngrid];
			//get buffers
			int ji;
			//all these are known to be non local
			//how to actually vectorize in UPC?
			for(j=MYTHREAD, ji=0; j<ngrid; j+=THREADS, ji++) {
				//if(j-1>=0) buf1[ji]=u[i][j-1];
				//if(j+1<ngrid) buf2[ji]=u[i][j+1];
			}
			
			//all these are known to be local
			for(j=0, ji=0; j<ngrid-1; j+=THREADS, ji++) {
				int jj=j+MYTHREAD;
				if(jj<1) continue;
				if(jj>=ngrid-1) break;
//				double utmp = 0.25*(u[i+1][jj]+u[i-1][jj]+u[i][jj+1]+u[i][jj-1]-h*h*f[i][jj]);
				double utmp = 0.25*(u[i+1][jj]+u[i-1][jj]+buf2[ji]+buf1[ji]-h*h*f[i][jj]);
				unew[i][jj] = omega * utmp + (1.0-omega)*u[i][jj];
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
		for(int i=0; i<ngrid; i++) {
			for(int j=0; j<ngrid; j++) {
				//printf("%f ", unew[i][j]);
			}
			//printf("\n");
		}
	}
}
