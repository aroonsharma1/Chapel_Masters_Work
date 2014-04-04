#!/bin/bash
#standard data set is 1024 but should run on 128
nl=10
Dim=128

echo nl=$nl
echo Dim=$Dim

#compile trmm
chpl --fast trmm.chpl -o trmm

echo 'Cyclic (C)'
./trmm -nl $nl --dist=C --Dim=$Dim --messages
./trmm -nl $nl --dist=C --Dim=$Dim --timeit

echo 'Cyclic with modulo unrolling (CM)'
./trmm -nl $nl --dist=CM --Dim=$Dim --correct
./trmm -nl $nl --dist=CM --Dim=$Dim --messages
./trmm -nl $nl --dist=CM --Dim=$Dim --timeit

echo 'Block (B)'
./trmm -nl $nl --dist=B --Dim=$Dim --messages
./trmm -nl $nl --dist=B --Dim=$Dim --timeit

echo 'No distribution (NONE)'
./trmm -nl $nl --dist=NONE --Dim=$Dim --timeit