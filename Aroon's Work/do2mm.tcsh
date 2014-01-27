#!/bin/tcsh
set nl=4
set size=100

echo nl=$nl
echo size=$size

#rm 2mm_parallel
if -e 2mm_parallel then
else
	chpl --fast 2mm_parallel.chpl -o 2mm_parallel
endif

echo 'Block (B)'
./2mm_parallel -nl $nl --dist=B --size=$size

echo 'Cyclic (C)'
./2mm_parallel -nl $nl --dist=C --size=$size

echo 'Cyclic with modulo unrolling (CM)'
./2mm_parallel -nl $nl --dist=CM --size=$size
