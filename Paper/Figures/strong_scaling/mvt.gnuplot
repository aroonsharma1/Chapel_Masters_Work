set output "mvt.pdf"
set style data lines 
set xlabel "Number of Locales"
set ylabel "Normalized Measurement"
plot "mvt.dat" u 1:2 title "Cyclic with MUWU Runtime/Cyclic Runtime" lw 3, "mvt.dat" u 1:3 title "Cyclic with MUWU Message Count/Cyclic Message Count" lw 3