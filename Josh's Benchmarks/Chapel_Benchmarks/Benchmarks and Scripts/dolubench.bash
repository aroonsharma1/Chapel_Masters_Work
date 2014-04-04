#!/bin/bash
#standard data set is 1024 but should use 64 or 128

nl=10
N=32

echo nl=$nl
echo N=$N

#compile lu
chpl --fast lu.chpl -o lu

echo 'Cyclic (C)'
./lu -nl $nl --dist=C --N=$N --messages
./lu -nl $nl --dist=C --N=$N --timeit

echo 'Cyclic with modulo unrolling (CM)'
./lu -nl $nl --dist=CM --N=$N --correct
./lu -nl $nl --dist=CM --N=$N --messages
./lu -nl $nl --dist=CM --N=$N --timeit

echo 'Block (B)'
./lu -nl $nl --dist=B --N=$N --messages
./lu -nl $nl --dist=B --N=$N --timeit

echo 'No distribution (NONE)'
./lu -nl $nl --dist=NONE --N=$N --timeit