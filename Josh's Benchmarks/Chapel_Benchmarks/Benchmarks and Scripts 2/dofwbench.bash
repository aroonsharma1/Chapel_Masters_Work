#!/bin/bash
nl=10
N=1024

echo nl=$nl
echo N=$N

#compile fw
chpl --fast floyd-warshall.chpl -o fw

echo 'Cyclic (C)'
./fw -nl $nl --dist=C --N=$N --messages
./fw -nl $nl --dist=C --N=$N --timeit

echo 'Cyclic with modulo unrolling (CM)'
./fw -nl $nl --dist=CM --N=$N --correct
./fw -nl $nl --dist=CM --N=$N --messages
./fw -nl $nl --dist=CM --N=$N --timeit

echo 'Block (B)'
./fw -nl $nl --dist=B --N=$N --messages
./fw -nl $nl --dist=B --N=$N --timeit

echo 'No distribution (NONE)'
./fw -nl $nl --dist=NONE --N=$N --timeit