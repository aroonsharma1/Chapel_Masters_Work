var A : [{1..9, 1..9}] int = [(i,j) in {1..9, 1..9}] i*10 + j;
A[12..11, 12..11] = 0;
A[11..12, 11..12] = 0;
writeln(A);
