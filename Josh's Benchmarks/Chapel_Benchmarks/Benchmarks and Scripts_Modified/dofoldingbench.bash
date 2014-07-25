#!/bin/bash
nl=8
iterations=10
n=50400

echo nl=$nl
echo n=$n
echo iterations=$iterations

#compile folding
chpl --fast folding.chpl -o folding

echo 'Block (B)'
./folding -nl $nl --dist=B --n=$n --iterations=$iterations --messages --timeit

echo 'Cyclic (C)'
./folding -nl $nl --dist=C --n=$n --iterations=$iterations --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./folding -nl $nl --dist=CM --n=$n --iterations=$iterations --correct --messages --timeit

#won't work for this benchmark because of strided access patterns
#echo 'Block Cyclic (BC)'
#./folding -nl $nl --dist=BC --n=$n --iterations=$iterations --bsize=$bsize --messages
#./folding -nl $nl --dist=BC --n=$n --iterations=$iterations --bsize=$bsize --timeit

#echo 'Block Cyclic with modulo unrolling (CM)'
#./folding -nl $nl --dist=BCM --n=$n --iterations=$iterations --bsize=$bsize --correct
#./folding -nl $nl --dist=BCM --n=$n --iterations=$iterations --bsize=$bsize --messages
#./folding -nl $nl --dist=BCM --n=$n --iterations=$iterations --bsize=$bsize --timeit

echo 'No distribution (NONE)'
./folding -nl $nl --dist=NONE --n=$n --iterations=$iterations --timeit
