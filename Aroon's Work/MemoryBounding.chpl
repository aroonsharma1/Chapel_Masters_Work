/* MemoryBounding is a module to be used with Chapel’s strided get 
and put communication calls. It is a module that splits up a block
of memory of dimension "rank" into smaller blocks of memory such that 
each smaller block contains a bounded number of elements. It is used 
so that a strided get or put message will not flood any single locale 
with an unbounded amount of memory. The large block of memory is 
specified by a two parameters: a tuple specifying the number of 
elements in each dimension of the block and a tuple specifying the 
strides in each dimension. Passing in a memory bound at compile time 
will split the large block of memory into a number of “chunks.” 
Each chunk has a tuple specifying the number of elements in each 
dimension and a tuple containing array-like indices that tell where
 in the larger block that chunk starts. For detailed examples of how 
MemoryBounding is used, see MemoryBounding1DTest.chpl, 
MemoryBounding2DTest.chpl, and MemoryBounding3DTest.chpl. */

module MemoryBounding {
	
	class Chunk {
		param rank: int;
		var bounded_chunk_count: (rank + 1) * int;
		var chunk_pointer: rank * int;
		var offset: int;
	}
	
	//Takes in a count tuple of the large memory block along with 	     //the memory bound and outputs a tuple that has no more elements     //than the memory bound. To do so, the function successively 
	//subtracts the highest count dimension by 1.
	proc create_bounded_count(param rank: int, count: (rank + 1)*int, bound: int) : (rank + 1) * int {
		var totalNumElements: int = num_elements(rank, count);
	
		while(totalNumElements > bound) {
			totalNumElements = 1;
		
			//find the maximum dimension in count and divide by 2
			var max: int = 1;
			for i in 1..rank+1 {
				if(count[i] > count[max]) {
					max = i;
				}
			}
			count[max] -= 1;
		
			//compute the total number of elements in the tuple
			totalNumElements = num_elements(rank, count);
		}
		return count;
	}

	//Returns a tuple that specifies the number of chunks specified 
	//by bounded_count can fit into the large memory block specified 
	//by count. For example, if the large memory block is (1, 3, 3) 
	//and chunk is (1, 2, 2), what will be returned is (1, 2, 2). 
	//This is because 2 chunks no bigger than 2 x 2 can fit in the 
	//horizontal direction of the 3 x 3 block and 2 chunks no bigger 
	//than 2 x 2 can fit in the vertical direction of the 3 x 3 
	//block.
	proc create_number_of_cuts(param rank: int, count: (rank + 1)*int, bounded_count: (rank + 1)*int) : (rank + 1)*int  {
		//tuple describing how many chunks (or blocks no bigger than 		 //a chunk) fit in each dimension
		var chunks: (rank + 1) * int;	
		chunks = count/bounded_count;
		for i in 1..rank+1 {
			if(count(i) % bounded_count(i)) {
				chunks(i) += 1;
			}
		}

		return chunks;
	}

	//Find the minimum between two numbers
	proc min(a: int, b: int): int {
		if(a < b) {
			return a;
		}
		else {
			return b;
		}
	}

	//Calculates the product of a tuple of integers
	proc num_elements(param rank: int, tuple: (rank + 1)*int) : int {
		var product: int = 1;
		for i in tuple {
			product *= i;
		}
		return product;
	}

	//Iterator that yields Chunk objects that make up the original       //large block of data. chunks_tuple is the tuple that is passed      //from create_number_of_cuts().
	iter go_through_chunks(param rank: int, chunks_tuple: (rank + 1)*int, count: (rank + 1)*int, bounded_count: (rank + 1)*int) {
		var i: rank*int;
		var done = false;
	
		while(!done) {
			var myChunk = new Chunk(rank);
			myChunk.chunk_pointer = i;
		
			//temporary tuple created to make the following loop 
			//possible
			var temp: (rank + 1)*int;
			temp(1) = 0;
			for i in 1..rank {
				temp(i + 1) = myChunk.chunk_pointer(i);
			}
		
			for i in 1..rank+1 {
				if(i == 1) {
					myChunk.bounded_chunk_count(i) = 1;
				}
				else {
					myChunk.bounded_chunk_count(i) = min(bounded_count(i), count(i) - bounded_count(i)*temp(i));				
				}
			}
			yield myChunk;
		
			var d = rank;
		
			//add 1 to i
			i(d) += 1;
		
			//handle carry
			while(d >= 1 && i(d) >= chunks_tuple(d + 1)) {
				i(d) = 0;
				if(d - 1 == 0) {
					done = true;
					break;
				}
				i(d - 1) += 1;
				d -= 1;
			}
		}
	}

	//Function that uses a Chunk's chunk_pointer to determine the 	     //offset into the original block of data. Not sure if this is        //correct.
	proc calculate_offset(param rank: int, myChunk: Chunk, source_stride: rank*int, bounded_count: (rank+1)*int) {
		var offset: int = 0;
		for i in 1..rank {
			offset += myChunk.chunk_pointer(i)*source_stride(i)*bounded_count(i+1);
		}
		return offset;
	}	
}