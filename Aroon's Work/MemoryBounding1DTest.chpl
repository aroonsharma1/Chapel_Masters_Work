/* This is a unit test showing how the MemoryBounding module is used 
   in practice. This shows an example of a 1 dimensional memory block
   of 20 elements. The memory bound is 7 elements meaning that a 
   single chunk can hold no more than 7 elements. By convention, 
   count(1) is always 1. The unit test prints out the original memory
   block dimensions (count), the bounded memory dimensions 
   (bounded_count), the chunks_tuple, the number of chunks, the source
   stride tuple, and each Chunk object.

   The diagram below shows a graphical interpretation of how the memory
   block of 20 elements is chunked after this test:

   --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 2 | 2 | 2 | 2 | 2 | 2 |
   --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

  The chunk size can be no bigger than 7 elements. The first 7 elements
  are in the first chunk labeled 0, the second 7 elements are in the 
  second chunk labeled 1, and the last 6 elements are in the third 
  chunk labeled 2. The chunk labels above correspond to the chunk_pointer
  field in the Chunk object. 
*/

use MemoryBounding;

config param rank: int = 1;
config param bound : int = 7;

var count: (rank + 1) * int;

count(1) = 1;	//the first count element should always be 1
count(2) = 20;

//bounded count tuple containing new dimensions which will be
//used in the communication calls
var bounded_count: (rank + 1) * int = create_bounded_count(rank, count, bound);
writeln("count :");
writeln(count);
writeln("bounded_count :");
writeln(bounded_count);

var chunks_tuple: (rank + 1) * int = create_number_of_cuts(rank, count, bounded_count);
writeln("chunks_tuple :");
writeln(chunks_tuple);

var num_chunks: int = num_elements(rank, chunks_tuple);
writeln("Number of chunks = " + num_chunks);

var srcStride: rank*int;
srcStride(1) = 1;

writeln("srcStride : ");
writeln(srcStride);

for i in go_through_chunks(rank, chunks_tuple, count, bounded_count) {
	i.offset = calculate_offset(rank, i, srcStride, bounded_count);
	writeln(i);
}