#!/bin/bash

nl=10
X=128
Y=128

echo nl=$nl
echo X=$X
echo Y=$Y

#compile bicg
chpl --fast bicg.chpl -o bicg

echo 'Cyclic (C)'
./bicg -nl $nl --dist=C --X=$X --Y=$Y --messages
./bicg -nl $nl --dist=C --X=$X --Y=$Y --timeit

echo 'Cyclic with modulo unrolling (CM)'
./bicg -nl $nl --dist=CM --X=$X --Y=$Y --correct
./bicg -nl $nl --dist=CM --X=$X --Y=$Y --messages
./bicg -nl $nl --dist=CM --X=$X --Y=$Y --timeit

echo 'Block (B)'
./bicg -nl $nl --dist=B --X=$X --Y=$Y --messages
./bicg -nl $nl --dist=B --X=$X --Y=$Y --timeit

echo 'No distribution (NONE)'
./bicg -nl $nl --dist=NONE --X=$X --Y=$Y --timeit
