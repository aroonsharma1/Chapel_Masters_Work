use MemoryBounding;

config param rank: int = 2;
config param bound : int = 5;

var count: (rank + 1) * int;

count(1) = 1;	//the first count element should always be 1
count(2) = 4;
count(3) = 7;


//bounded count tuple containing new dimensions which will be
//used in the communication calls
var bounded_count: (rank + 1) * int = create_bounded_count(rank, count, bound);
writeln("count :");
writeln(count);
writeln("bounded_count :");
writeln(bounded_count);

//tuple specifying
var chunks: (rank + 1) * int = create_number_of_cuts(rank, count, bounded_count);
writeln("chunks :");
writeln(chunks);

var num_chunks: int = 1;
for i in chunks {
	num_chunks *= i;
}
writeln("Number of chunks = " + num_chunks);

var srcStride: rank*int;
srcStride(1) = 1;
srcStride(2) = 15;

writeln("srcStride : ");
writeln(srcStride);

for i in go_through_chunks(rank, chunks, count, bounded_count) {
	i.offset = calculate_offset(rank, i, srcStride, bounded_count);
	writeln(i);
}