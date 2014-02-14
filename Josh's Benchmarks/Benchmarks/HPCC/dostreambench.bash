#!/bin/bash

nl=10

echo nl=$nl

#compile stream
chpl --fast stream.chpl -o stream

echo 'Block (B)'
./stream -nl $nl --dist=B --messages
./stream -nl $nl --dist=B --timeit

echo 'Cyclic (C)'
./stream -nl $nl --dist=C --messages
./stream -nl $nl --dist=C --timeit

echo 'Cyclic with modulo unrolling (CM)'
./stream -nl $nl --dist=CM --messages
./stream -nl $nl --dist=CM --timeit

echo 'no distribution (NONE)'
./stream -nl $nl --dist=NONE --timeit
