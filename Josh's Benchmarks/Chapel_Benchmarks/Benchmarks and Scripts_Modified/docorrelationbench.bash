#!/bin/bash
nl=10
N=512
M=512

echo nl=$nl
echo N=$N
echo M=$M

#compile correlation
chpl --fast correlation.chpl -o correlation

echo 'Cyclic (C)'
./correlation -nl $nl --dist=C --N=$N --M=$M --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./correlation -nl $nl --dist=CM --N=$N --M=$M --correct --messages --timeit

echo 'Block (B)'
./correlation -nl $nl --dist=B --N=$N --M=$M --messages --timeit

echo 'No distribution (NONE)'
./correlation -nl $nl --dist=NONE --N=$N --M=$M --timeit