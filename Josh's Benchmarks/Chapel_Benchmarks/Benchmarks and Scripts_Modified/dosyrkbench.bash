#!/bin/bash
#standard data set is 1024 but should run at 64 or 128
nl=8
M=128
N=128

echo nl=$nl
echo N=$N
echo M=$M

#compile syrk
chpl --fast syrk.chpl -o syrk

echo 'Cyclic (C)'
./syrk -nl $nl --dist=C --M=$M --N=$N --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./syrk -nl $nl --dist=CM --M=$M --N=$N --correct --messages --timeit

echo 'Block (B)'
./syrk -nl $nl --dist=B --M=$M --N=$N --messages --timeit

echo 'No distribution (NONE)'
./syrk -nl $nl --dist=NONE --M=$M --N=$N --timeit