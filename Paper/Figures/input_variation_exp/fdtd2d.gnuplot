set terminal aqua fsize 25
set style data lines 
set xlabel "Input Size"
set ylabel "Normalized Measurement"
set y2label "Number of Elements Per Follower Iterator Chunk" rotate by 270
set ytics nomirror
set y2tics
unset key 
plot "fdtd2d.dat" u 1:2 title "C with MUWU Runtime/C Runtime" lw 3 axes x1y1, "fdtd2d.dat" u 1:3 title "C with MUWU Message Count/C Message Count" lw 3 axes x1y1, "fdtd2d.dat" u 1:4 title "C with MUWU Follower Iterator" lw 3 axes x1y2
