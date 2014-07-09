#!/bin/bash
#standard data set is 1024 but should use 64 or 128

nl=8
N=128

echo nl=$nl
echo N=$N

#compile lu
chpl --fast lu.chpl -o lu

echo 'Cyclic (C)'
./lu -nl $nl --dist=C --N=$N --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./lu -nl $nl --dist=CM --N=$N --correct --messages --timeit

echo 'Block (B)'
./lu -nl $nl --dist=B --N=$N --messages --timeit

echo 'No distribution (NONE)'
./lu -nl $nl --dist=NONE --N=$N --timeit