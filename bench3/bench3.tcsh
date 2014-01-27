#!/bin/tcsh
set nl=4
chpl --fast jacobi.chpl -o jacobi
chpl --fast jacobi2.chpl -o jacobi2
chpl --fast jacobi3.chpl -o jacobi3
echo testing correctness
./jacobi3 -nl $nl --n=5 --epsilon=0.1 --debugzipopt=true --testzipopt=true
./jacobi3 -nl $nl --n=50 --epsilon=0.1 --debugzipopt=true --testzipopt=true
./jacobi3 -nl $nl --n=500 --epsilon=0.1 --debugzipopt=true --testzipopt=true
echo jacobi n=5
time ./jacobi -nl $nl --n=5 --epsilon=0.1
echo jacobi n=50
time ./jacobi -nl $nl --n=50 --epsilon=0.1
echo jacobi n=500
time ./jacobi -nl $nl --n=500 --epsilon=0.1
echo jacobi2 n=5
time ./jacobi2 -nl $nl --n=5 --epsilon=0.1
echo jacobi2 n=50
time ./jacobi2 -nl $nl --n=50 --epsilon=0.1
echo jacobi2 n=500
time ./jacobi2 -nl $nl --n=500 --epsilon=0.1
echo jacobi3 n=5
time ./jacobi3 -nl $nl --n=5 --epsilon=0.1
echo jacobi3 n=50
time ./jacobi3 -nl $nl --n=50 --epsilon=0.1
echo jacobi3 n=500
time ./jacobi3 -nl $nl --n=500 --epsilon=0.1
