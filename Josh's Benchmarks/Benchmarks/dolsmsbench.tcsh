#!/bin/tcsh

nl=10
nIterations=1024

echo nl=$nl
echo nIterations=$nIterations

#compile lsms
chpl --fast lsms.chpl -o lsms

echo 'Block (B)'
./lsms -nl $nl --dist=B --nIterations=$nIterations  --messages
./lsms -nl $nl --dist=B --nIterations=$nIterations  --timeit

echo 'Cyclic (C)'
./lsms -nl $nl --dist=C --nIterations=$nIterations  --messages
./lsms -nl $nl --dist=C --nIterations=$nIterations  --timeit

echo 'Cyclic with modulo unrolling (CM)'
./lsms -nl $nl --dist=CM --nIterations=$nIterations  --messages
./lsms -nl $nl --dist=CM --nIterations=$nIterations  --timeit

echo 'no distribution (NONE)'
./lsms -nl $nl --dist=nOnE --nIterations=$nIterations --timeit
