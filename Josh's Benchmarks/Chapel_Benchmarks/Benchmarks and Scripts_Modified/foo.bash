#script to determine parallel chunk sizes for different input size runs of fdtd-2d
#!/bin/bash
nl=8
TMAX=50

for n in {10..200..5}
	do
		./fdtd-2d -nl $nl --dist=CM --M=$n --N=$n --TMAX=$TMAX > fdtd2d.log
		
		sum=0
		lines=0
		while read line
		do
			sum=$((sum+line))
			lines=$((lines+1))
		done < $1
		echo $((sum/lines))
	done