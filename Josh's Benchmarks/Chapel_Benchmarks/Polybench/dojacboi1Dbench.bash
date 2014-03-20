#!/bin/bash
nl=10
M=10000
bsize=4

echo nl=$nl
echo M=$M

#compile jacobi-1d
chpl --fast jacobi-1d.chpl -o jacobi-1d

echo 'Cyclic (C)'
./jacobi-1d -nl $nl --dist=C --M=$M --messages
./jacobi-1d -nl $nl --dist=C --M=$M --timeit

echo 'Cyclic with modulo unrolling (CM)'
./jacobi-1d -nl $nl --dist=CM --M=$M --correct
./jacobi-1d -nl $nl --dist=CM --M=$M --messages
./jacobi-1d -nl $nl --dist=CM --M=$M --timeit

echo 'Block Cyclic (BC)'
./jacobi-1d -nl $nl --dist=BC --M=$M --bsize=$bsize --messages
./jacobi-1d -nl $nl --dist=BC --M=$M --bsize=$bsize --timeit

echo 'Block Cyclic with modulo unrolling (CM)'
./jacobi-1d -nl $nl --dist=BCM --M=$M --bsize=$bsize --correct
./jacobi-1d -nl $nl --dist=BCM --M=$M --bsize=$bsize --messages
./jacobi-1d -nl $nl --dist=BCM --M=$M --bsize=$bsize --timeit

echo 'Block (B)'
./jacobi-1d -nl $nl --dist=B --M=$M --messages
./jacobi-1d -nl $nl --dist=B --M=$M --timeit

echo 'No distribution (NONE)'
./jacobi-1d -nl $nl --dist=NONE --M=$M --timeit