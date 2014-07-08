#!/bin/bash
nl=10
epsilon=0.05
n=400

echo nl=$nl
echo n=$n
echo epsilon=$epsilon

#compile jacobi-2d
chpl --fast jacobi-2d.chpl -o jacobi-2d

echo 'Block (B)'
./jacobi-2d -nl $nl --dist=B --n=$n --epsilon=$epsilon --messages
./jacobi-2d -nl $nl --dist=B --n=$n --epsilon=$epsilon --timeit

echo 'Cyclic (C)'
./jacobi-2d -nl $nl --dist=C --n=$n --epsilon=$epsilon --messages
./jacobi-2d -nl $nl --dist=C --n=$n --epsilon=$epsilon --timeit

echo 'Cyclic with modulo unrolling (CM)'
./jacobi-2d -nl $nl --dist=CM --n=$n --epsilon=$epsilon --correct
./jacobi-2d -nl $nl --dist=CM --n=$n --epsilon=$epsilon --messages
./jacobi-2d -nl $nl --dist=CM --n=$n --epsilon=$epsilon --timeit

echo 'No distribution (NONE)'
./jacobi-2d -nl $nl --dist=NONE --n=$n --timeit
