#!/bin/bash
#standard sata set is 1024
nl=10
M=32
N=32

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