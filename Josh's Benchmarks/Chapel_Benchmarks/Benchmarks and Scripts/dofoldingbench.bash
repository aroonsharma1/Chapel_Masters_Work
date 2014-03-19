#!/bin/bash
nl=10
iterations=10
n=50400

echo nl=$nl
echo n=$n
echo iterations=$iterations

#compile folding
chpl --fast folding.chpl -o folding

echo 'Block (B)'
./folding -nl $nl --dist=B --n=$n --iterations=$iterations --messages
./folding -nl $nl --dist=B --n=$n --iterations=$iterations --timeit

echo 'Cyclic (C)'
./folding -nl $nl --dist=C --n=$n --iterations=$iterations --messages
./folding -nl $nl --dist=C --n=$n --iterations=$iterations --timeit

echo 'Cyclic with modulo unrolling (CM)'
./folding -nl $nl --dist=CM --n=$n --iterations=$iterations --correct
./folding -nl $nl --dist=CM --n=$n --iterations=$iterations --messages
./folding -nl $nl --dist=CM --n=$n --iterations=$iterations --timeit

echo 'No distribution (NONE)'
./folding -nl $nl --dist=NONE --n=$n --iterations=$iterations --timeit
