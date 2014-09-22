#!/bin/bash
nl=8
iterations=10

echo nl=$nl
echo iterations=$iterations

#compile folding
chpl folding.chpl --fast -o folding

for n in {100..500..100}
	do
		echo "Cyclic (C) n=$n"
		./folding -nl $nl --dist=C --n=$n --iterations=$iterations --messages --timeit

		echo "Cyclic with modulo unrolling (CM) n=$n"
		./folding -nl $nl --dist=CM --n=$n --iterations=$iterations --correct --messages --timeit
	done