set terminal aqua fsize 25
set style data lines 
set xlabel "Block Size"
set ylabel "Normalized Measurement
set y2label "Number of Elements Per Follower Iterator Chunk" rotate by 270
set y2tics
set ytics nomirror
unset key
plot "jacobi-1d.dat" u 1:2 title "BC with MUWU Runtime/BC Runtime" lw 3 axes x1y1, "jacobi-1d.dat" u 1:3 title "BC with MUWU Message Count/BC Message Count" lw 3 axes x1y1, "jacobi-1d.dat" u 1:4 title "BC Follower Iterator" lw 3 axes x1y2