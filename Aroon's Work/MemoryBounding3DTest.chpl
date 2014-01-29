/* This is a unit test showing how the MemoryBounding module is used 
   in practice. This shows an example of a 3 dimensional memory block
   of 5 x 4 x 3 elements. The memory bound is 20 elements meaning that a 
   single chunk can hold no more than 20 elements. By convention, 
   count(1) is always 1. The unit test prints out the original memory
   block dimensions (count), the bounded memory dimensions 
   (bounded_count), the chunks_tuple, the number of chunks, the source
   stride tuple, and each Chunk object.

   The diagram below shows a graphical interpretation of how the memory
   block of 5 x 4 x 3 elements is chunked after this test. Since we are
   in 3 dimensions, each face of the cube will be drawn separately:

   Front face

   --- --- --- --- ---
  | 1 | 1 | 3 | 3 | 5 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---

   Middle face

   --- --- --- --- ---
  | 1 | 1 | 3 | 3 | 5 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---


   Back face

   --- --- --- --- ---
  | 1 | 1 | 3 | 3 | 5 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---
   --- --- --- --- ---
  | 0 | 0 | 2 | 2 | 4 |
   --- --- --- --- ---


  The source address of this block is the bottom left corner 
  element of the cube. The chunk size can be no bigger than 20 
  elements. After running create_bounded_count(), we come up with 
  a chunk size of 2 x 3 x 3. The first chunk is 2 x 3 x 3 and is 
  labeled 0. Note that the chunk is 3 dimensional and therefore spans 
  across all 3 faces of the cube. The second chunk is 2 x 1 x 3 and 
  labeled 1. Chunk 1 is smaller than 2 x 3 x 3 because a 2 x 3 x 3 
  chunk is too big to cover the remaining elements starting at the 
  location of Chunk 1. This pattern is repeated and shown above. Note
  that some chunks are smaller than 2 x 3 x 3 while others
  are exactly 2 x 3 x 3. Different memory bounds and large memory 
  block sizes result in different chunking patterns. 
*/

use MemoryBounding;

config param rank: int = 3;
config param bound : int = 20;

var count: (rank + 1) * int;

count(1) = 1;	//the first count element should always be 1
count(2) = 5;
count(3) = 4;
count(4) = 3;

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
srcStride(2) = 10;
srcStride(3) = 20;

writeln("srcStride : ");
writeln(srcStride);

for i in go_through_chunks(rank, chunks_tuple, count, bounded_count) {
	i.offset = calculate_offset(rank, i, srcStride, bounded_count);
	writeln(i);
}