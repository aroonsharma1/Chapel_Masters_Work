#!/bin/bash
nl=8
blocksize=16

echo "pascal vary input"
echo nl=$nl
echo blocksize=$blocksize

#compile pascal
chpl --fast pascal.chpl -o pascal

for n1 in {100..200..10}
	do
		n2 = $n1+3
		echo n1=$n1
		echo n2=$n2
		
		echo 'Cyclic (C)'
		./pascal -nl $nl --dist=C --n1=$n1 --n2=$n2 --messages --timeit

		echo 'Cyclic with modulo unrolling (CM) aggregation minimum=4'
		./pascal -nl $nl --dist=CM --n1=$n1 --n2=$n2 --messages --timiet

		echo 'Block Cyclic (BC)'
		./pascal -nl $nl --dist=BC --n1=$n1 --n2=$n2 --messages --timeit --blocksize=$blocksize

		echo 'Block Cyclic with modulo unrolling (BCM)'
		./pascal -nl $nl --dist=BCM --n1=$n1 --n2=$n2 --messages --timeit --blocksize=$blocksize
	done