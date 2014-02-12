#!/bin/bash
nl=10
n=1024

echo nl=$nl
echo n=$n

#compile paracr
chpl --fast paracr.chpl -o paracr

echo 'Block (B)'
./paracr -nl $nl --dist=B --n=$n  --messages
./paracr -nl $nl --dist=B --n=$n  --timeit

echo 'Cyclic (C)'
./paracr -nl $nl --dist=C --n=$n  --messages
./paracr -nl $nl --dist=C --n=$n  --timeit

echo 'Cyclic with modulo unrolling (CM)'
./paracr -nl $nl --dist=CM --n=$n  --messages
./paracr -nl $nl --dist=CM --n=$n  --timeit

echo 'No distribution (NONE)'
./paracr -nl $nl --dist=NONE --n=$n --timeit
