config param rank: int = 2;
config param bound : int = 5;

record chunk {
	var bounded_chunk_count: (rank + 1) * int;
	var chunk_pointer: rank * int;
	var offset: int;
}

var count: (rank + 1) * int;

count(1) = 1;	//the first count element should always be 1
count(2) = 4;
count(3) = 7;

//bounded count tuple containing new dimensions which will be
//used in the communication calls
var bounded_count: (rank + 1) * int = create_bounded_count(count, bound);
writeln("count :");
writeln(count);
writeln("bounded_count :");
writeln(bounded_count);

//tuple specifying
var chunks: (rank + 1) * int = create_number_of_cuts(count, bounded_count);
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

for i in go_through_chunks(chunks, count, bounded_count) {
	i.offset = calculate_offset(i, srcStride, bounded_count);
	writeln(i);
}

//takes in a count tuple and outputs whether the tuple has more 
//elements than bound. the total number of elements in the tuple
//is the product of all the tuple entries
proc create_bounded_count(count: (rank + 1)*int, bound: int) : (rank + 1) * int {
	var totalNumElements: int = 1;
	for i in count {
		totalNumElements *= i;
	}
	
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
		for i in count {
			totalNumElements *= i;
		}
	}
	return count;
}

proc create_number_of_cuts(count: (rank + 1)*int, bounded_count: (rank + 1)*int) : (rank + 1)*int  {
	var chunks: (rank + 1) * int;
	chunks = count/bounded_count + count % bounded_count;
	return chunks;
}

proc min(a: int, b: int): int {
	if(a < b) {
		return a;
	}
	else {
		return b;
	}
}

iter go_through_chunks(chunks: (rank + 1)*int, count: (rank + 1)*int, bounded_count: (rank + 1)*int) {
	var i: rank*int;
	var done = false;
	
	while(!done) {
		var myChunk: chunk;
		myChunk.chunk_pointer = i;
		
		//temporary tuple created to make the following loop possible
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
		while(d >= 1 && i(d) >= chunks(d + 1)) {
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

proc calculate_offset(myChunk: chunk, source_stride: rank*int, bounded_count: (rank+1)*int) {
	var offset: int = 0;
	for i in 1..rank {
		offset += myChunk.chunk_pointer(i)*source_stride(i)*bounded_count(i+1);
	}
	return offset;
}