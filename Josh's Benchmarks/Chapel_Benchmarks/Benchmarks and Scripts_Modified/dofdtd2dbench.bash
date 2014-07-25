#!/bin/bash
#standard data set is 1000 but should run this with a size of 300
nl=8
M=1000
N=1000
TMAX=50

echo nl=$nl
echo M=$M
echo N=$N
echo TMAX=$TMAX

#compile fdtd-2d
chpl --fast fdtd-2d.chpl -o fdtd-2d

echo 'Cyclic (C)'
./fdtd-2d -nl $nl --dist=C --M=$M --N=$N --TMAX=$TMAX --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./fdtd-2d -nl $nl --dist=CM --M=$M --N=$N --TMAX=$TMAX --correct --messages --timeit

echo 'Block (B)'
./fdtd-2d -nl $nl --dist=B --M=$M --N=$N --TMAX=$TMAX --messages --timeit

echo 'No distribution (NONE)'
./fdtd-2d -nl $nl --dist=NONE --M=$M --N=$N --TMAX=$TMAX --timeit