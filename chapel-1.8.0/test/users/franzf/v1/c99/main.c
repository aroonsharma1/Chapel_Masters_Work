/***************************************************************
This code was generated by  Spiral 5.0 beta, www.spiral.net --
Copyright (c) 2005, Carnegie Mellon University
All rights reserved.
The code is distributed under a BSD style license
(see http://www.opensource.org/licenses/bsd-license.php)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
  notice, reference to Spiral, this list of conditions and the
  following disclaimer.
  * Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the following
  disclaimer in the documentation and/or other materials provided
  with the distribution.
  * Neither the name of Carnegie Mellon University nor the name of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*AS IS* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "libfft.h"
#include "omega64c.h"

#define NUMRUNS			10000000
#define MIN_SIZE		2
#define MAX_SIZE		2048
#define EPS				1E-5

#ifdef __ICL
#define COMPILER "Intel C++ Compiler"
#endif

#ifdef __GNUC__
#define COMPILER "GNU C Compiler"
#endif


int main(int argc, char **argv)
{
  int i, n, numruns = NUMRUNS;
  clock_t start, finish;
  double gflop, duration, runtime;
  _Complex double *x, *y;
  fft_func *fft;

  printf("Spiral 5.0 Chapel FFT example -- C99 version, %s\n", COMPILER);

  for (n = MIN_SIZE; n <= MAX_SIZE; n *= 2, numruns *=0.6) {
    //  initialization
    x = (_Complex double *) malloc(n * sizeof(_Complex double));
    y = (_Complex double *) malloc(n * sizeof(_Complex double));
   
    x[0] = 1 + __I__;	
    for (i = 1; i < n; i++)
      x[i] = 0; 
    fft = init_fft(n);

    //  check computation
    fft(y, x);

    for (i = 0; i < n; i++)
      if (cabs(y[i] - (1 + __I__)) > EPS) {
        printf("Error: result incorrect.\n\n");
        exit(1);
      }

    if (!(fft)) {
      printf("Error: unsupported FFT size.\n\n");
      exit(1);
    }

    //  benchmark computation
    start = clock();
    for (i=0; i< numruns; i++) 
      fft(y, x);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    runtime = 1E9 * duration /numruns;

    gflop = (5.0 * n * log((double)n) / (log(2.0) * runtime));
    printf("fft_%d: %d ns = %.3f Gflop/s\n", n, (int)runtime, gflop);

    free(x);
    free(y);
  }   
}