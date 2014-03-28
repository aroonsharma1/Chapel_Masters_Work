#!/bin/bash
nl=10
M=10000
bsize=4
TSTEPS=100

echo nl=$nl
echo M=$M
echo bsize=$bsize
echo TSTEPS=$TSTEPS

#compile jacobi-1d
chpl --fast jacobi-1d.chpl -o jacobi-1d

echo 'Cyclic (C)'
./jacobi-1d -nl $nl --dist=C --M=$M --TSTEPS=$TSTEPS --messages
./jacobi-1d -nl $nl --dist=C --M=$M --TSTEPS=$TSTEPS --timeit

echo 'Cyclic with modulo unrolling (CM)'
./jacobi-1d -nl $nl --dist=CM --M=$M --TSTEPS=$TSTEPS --correct
./jacobi-1d -nl $nl --dist=CM --M=$M --TSTEPS=$TSTEPS --messages
./jacobi-1d -nl $nl --dist=CM --M=$M --TSTEPS=$TSTEPS --timeit

echo 'Block Cyclic (BC)'
./jacobi-1d -nl $nl --dist=BC --M=$M --TSTEPS=$TSTEPS --bsize=$bsize --messages
./jacobi-1d -nl $nl --dist=BC --M=$M --TSTEPS=$TSTEPS --bsize=$bsize --timeit

echo 'Block Cyclic with modulo unrolling (CM)'
./jacobi-1d -nl $nl --dist=BCM --M=$M --TSTEPS=$TSTEPS --bsize=$bsize --correct
./jacobi-1d -nl $nl --dist=BCM --M=$M --TSTEPS=$TSTEPS --bsize=$bsize --messages
./jacobi-1d -nl $nl --dist=BCM --M=$M --TSTEPS=$TSTEPS --bsize=$bsize --timeit

echo 'Block (B)'
./jacobi-1d -nl $nl --dist=B --M=$M --messages
./jacobi-1d -nl $nl --dist=B --M=$M --timeit

echo 'No distribution (NONE)'
./jacobi-1d -nl $nl --dist=NONE --M=$M --timeit