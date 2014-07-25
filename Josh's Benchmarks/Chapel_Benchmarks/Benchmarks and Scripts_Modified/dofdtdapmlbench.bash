#!/bin/bash
#standard data set is 256 but should run on 32 or 64
nl=8
M=128
N=128
P=128

echo nl=$nl
echo M=$M
echo N=$N
echo P=$P

#compile fdtd-apml
chpl --fast fdtd-apml.chpl -o fdtd-apml

echo 'Cyclic (C)'
./fdtd-apml -nl $nl --dist=C --M=$M --N=$N --P=$P --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./fdtd-apml -nl $nl --dist=CM --M=$M --N=$N --P=$P --correct --messages --timeit

echo 'Block (B)'
./fdtd-apml -nl $nl --dist=B --M=$M --N=$N --P=$P --messages --timeit

echo 'No distribution (NONE)'
./fdtd-apml -nl $nl --dist=NONE --M=$M --N=$N --P=$P --timeit