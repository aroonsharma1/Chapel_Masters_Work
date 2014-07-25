#!/bin/bash
nl=8
N=64

echo nl=$nl
echo N=$N

#compile fw
chpl --fast floyd-warshall.chpl -o fw

echo 'Cyclic (C)'
./fw -nl $nl --dist=C --N=$N --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./fw -nl $nl --dist=CM --N=$N --correct --messages --timeit

echo 'Block (B)'
./fw -nl $nl --dist=B --N=$N --messages --timeit

echo 'No distribution (NONE)'
./fw -nl $nl --dist=NONE --N=$N --timeit