#!/bin/bash
nl=10
N=1000
M=1000

echo nl=$nl
echo N=$N
echo M=$M

#compile covariance
chpl --fast covariance.chpl -o covariance

echo 'Cyclic (C)'
./covariance -nl $nl --dist=C --N=$N --M=$M --messages
./covariance -nl $nl --dist=C --N=$N --M=$M --timeit

echo 'Cyclic with modulo unrolling (CM)'
./covariance -nl $nl --dist=CM --N=$N --M=$M --correct
./covariance -nl $nl --dist=CM --N=$N --M=$M --messages
./covariance -nl $nl --dist=CM --N=$N --M=$M --timeit

echo 'Block (B)'
./covariance -nl $nl --dist=B --N=$N --M=$M --messages
./covariance -nl $nl --dist=B --N=$N --M=$M --timeit

echo 'No distribution (NONE)'
./covariance -nl $nl --dist=NONE --N=$N --M=$M --timeit
