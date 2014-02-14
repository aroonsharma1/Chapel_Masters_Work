#!/bin/bash

nl=10
numVectors=10

echo nl=$nl
echo numVectors=10

#compile stream
chpl --fast stream.chpl -o stream

echo 'Block (B)'
./stream -nl $nl --dist=B --numVectors=$numVectors  --messages
./stream -nl $nl --dist=B --numVectors=$numVectors  --timeit

echo 'Cyclic (C)'
./stream -nl $nl --dist=C --numVectors=$numVectors  --messages
./stream -nl $nl --dist=C --numVectors=$numVectors  --timeit

echo 'Cyclic with modulo unrolling (CM)'
./stream -nl $nl --dist=CM --numVectors=$numVectors  --messages
./stream -nl $nl --dist=CM --numVectors=$numVectors  --timeit

echo 'no distribution (NONE)'
./stream -nl $nl --dist=NONE --numVectors=$numVectors --timeit
