#!/bin/bash
nl=8
iterations=10

echo nl=$nl
echo iterations=$iterations

#compile folding
chpl folding.chpl --fast -o folding

for n in {100..5000..100}
	do
		echo "$n"
	done
