#!/bin/bash
nl=10
span=128

echo nl=$nl
echo span=128

#compile lsms
chpl --fast lsms.chpl -o lsms

echo 'Block (B)'
./lsms -nl $nl --dist=B --span=$span  --messages
./lsms -nl $nl --dist=B --span=$span  --timeit

echo 'Cyclic (C)'
./lsms -nl $nl --dist=C --span=$span  --messages
./lsms -nl $nl --dist=C --span=$span  --timeit

echo 'Cyclic with modulo unrolling (CM)'
./lsms -nl $nl --dist=CM --span=$span  --messages
./lsms -nl $nl --dist=CM --span=$span  --timeit

echo 'no distribution (NONE)'
./lsms -nl $nl --dist=nOnE --span=$span --timeit
