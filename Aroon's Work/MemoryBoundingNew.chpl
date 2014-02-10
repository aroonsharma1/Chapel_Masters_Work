module MemoryBoundingNew {
	
	class Chunk {
		param rank: int;
		var bounded_chunk_count: (rank + 1) * int;
		var chunk_pointer: rank * int;
		var offset: int;
	}
	
	iter create_chunk_pointers(param rank: int, count: (rank + 1)*int, memory_bound: int): rank*int {
		var totalNumElements: int = num_elements(rank, count);
		var chunk_pointer: rank*int;
		var done = false;
		var number_of_chunks: int = totalNumElements/memory_bound;
		
		if(number_of_chunks == 0) {
			yield chunk_pointer;
		}
		else {
			for i in 0..number_of_chunks-1 {
				var number_of_elements_so_far: int = i * memory_bound;
				for j in 0..rank-1 {
					totalNumElements /= count(j+1);
					chunk_pointer(rank-j) = number_of_elements_so_far/totalNumElements;
					number_of_elements_so_far -= chunk_pointer(rank-j)*totalNumElements;
				}
				yield chunk_pointer;
			}
		}
	}
	//Takes in a count tuple of the large memory block along with 	     //the memory bound and outputs a tuple that has no more elements     //than the memory bound. To do so, the function successively 
	//subtracts the highest count dimension by 1.
	proc create_bounded_count(param rank: int, count: (rank + 1)*int, bound: int) : (rank + 1) * int {
		var totalNumElements: int = num_elements(rank, count);
	
		while(totalNumElements > bound) {
			totalNumElements = 1;
		
			//find the maximum dimension in count and subtract by 1
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

	//Iterator that yields Chunk objects that make up the original         //large block of data. chunks_tuple is the tuple that is               //passed from create_number_of_cuts().
	iter go_through_chunks(param rank: int, chunks_tuple: (rank + 1)*int, count: (rank + 1)*int, bounded_count: (rank + 1)*int) {
		var i: rank*int;
		var done = false;
	
		while(!done) {
			var myChunk = new Chunk(rank);
			var bounded_count_without_first_entry: rank*int;
			for i in 1..rank {
				bounded_count_without_first_entry(i) = bounded_count(i+1);
			}
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
			myChunk.chunk_pointer = i * bounded_count_without_first_entry;
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

	//Function that uses a Chunk's chunk_pointer to determine the 	       //offset into the original block of data. Not sure if this is          //correct.
	proc calculate_offset(param rank: int, myChunk: Chunk, source_stride: rank*int, bounded_count: (rank+1)*int) {
		var offset: int = 0;
		for i in 1..rank {
			offset += myChunk.chunk_pointer(i)*source_stride(i)*bounded_count(i+1);
		}
		return offset;
	}	
}

use MemoryBoundingNew;

config param rank: int = 1;
config param memory_bound : int = 7;

var count: (rank + 1) * int;

count(1) = 1;	//the first count element should always be 1
count(2) = 20;

for i in create_chunk_pointers(rank, count, memory_bound) {
	writeln(i);
}