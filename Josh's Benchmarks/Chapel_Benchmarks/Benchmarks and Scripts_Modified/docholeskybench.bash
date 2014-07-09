#!/bin/bash
nl=10
N=256

echo nl=$nl
echo N=$N

#compile cholesky
chpl --fast cholesky.chpl -o cholesky

echo 'Cyclic (C)'
./cholesky -nl $nl --dist=C --N=$N --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./cholesky -nl $nl --dist=CM --N=$N --correct --messages --timeit

echo 'Block (B)'
./cholesky -nl $nl --dist=B --N=$N --messages --timeit

echo 'No distribution (NONE)'
./cholesky -nl $nl --dist=NONE --N=$N --timeit