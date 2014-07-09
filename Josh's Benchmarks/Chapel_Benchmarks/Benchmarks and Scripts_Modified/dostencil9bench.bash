#!/bin/bash
nl=10
epsilon=0.05
n=400

echo nl=$nl
echo n=$n
echo epsilon=$epsilon

#compile stencil9
chpl --fast stencil9.chpl -o stencil9

echo 'Block (B)'
./stencil9 -nl $nl --dist=B --n=$n --epsilon=$epsilon --messages --timeit

echo 'Cyclic (C)'
./stencil9 -nl $nl --dist=C --n=$n --epsilon=$epsilon --messages --timeit

echo 'Cyclic with modulo unrolling (CM)'
./stencil9 -nl $nl --dist=CM --n=$n --epsilon=$epsilon --correct --messages --timeit

echo 'No distribution (NONE)'
./stencil9 -nl $nl --dist=NONE --n=$n --timeit
