#!/bin/bash
nl=4
N=8

echo nl=$nl
echo N=$N

#compile atax
chpl --fast atax.chpl -o atax

echo 'Cyclic (C)'
./atax -nl $nl --dist=C --N=$N --messages
./atax -nl $nl --dist=C --N=$N --timeit

echo 'Cyclic with modulo unrolling (CM)'
./atax -nl $nl --dist=CM --N=$N --correct
./atax -nl $nl --dist=CM --N=$N --messages
./atax -nl $nl --dist=CM --N=$N --timeit

echo 'Block (B)'
./atax -nl $nl --dist=B --N=$N --messages
./atax -nl $nl --dist=B --N=$N --timeit

echo 'No distribution (NONE)'
./atax -nl $nl --dist=NONE --N=$N --timeit