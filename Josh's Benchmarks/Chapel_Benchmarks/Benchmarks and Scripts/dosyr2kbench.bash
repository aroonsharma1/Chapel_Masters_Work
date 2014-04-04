#!/bin/bash
#standard sata set is 1024 but should run on 32 or 64 or 128
nl=10
M=128
N=128

echo nl=$nl
echo N=$N
echo M=$M

#compile syr2k
chpl --fast syr2k.chpl -o syr2k

echo 'Cyclic (C)'
./syr2k -nl $nl --dist=C --M=$M --N=$N --messages
./syr2k -nl $nl --dist=C --M=$M --N=$N --timeit

echo 'Cyclic with modulo unrolling (CM)'
./syr2k -nl $nl --dist=CM --M=$M --N=$N --correct
./syr2k -nl $nl --dist=CM --M=$M --N=$N --messages
./syr2k -nl $nl --dist=CM --M=$M --N=$N --timeit

echo 'Block (B)'
./syr2k -nl $nl --dist=B --M=$M --N=$N --messages
./syr2k -nl $nl --dist=B --M=$M --N=$N --timeit

echo 'No distribution (NONE)'
./syr2k -nl $nl --dist=NONE --M=$M --N=$N --timeit