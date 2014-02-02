use CyclicDist;
use BlockDist;
use MemoryBounding;

config param memory_bound: int = 131072;

const n: int=50*numLocales;
var Dist = new dmap(new Block({1..n}));

var Dom: domain(1,int) dmapped Dist = {1..n};

var A:[Dom] int(64); //real
var B:[Dom] int(64); //real

proc TestGetsPuts(A:[], B:[]) {
	A._value.TestGetsPuts(B);
}

proc BlockArr.TestGetsPuts(B)
{
  param stridelevels=1;
  param rank: int = stridelevels;
  //Errors below if stridelevels=0 !!
  var dststrides:[1..#stridelevels] int(32);
  var srcstrides: [1..#stridelevels] int(32);
  var count: [1..#(stridelevels+1)] int(32);
  var rid=1; //remote locale id
  var lid=0; //local locale id
  
  //  writeln("locArr[0]: ", locArr[0].myElems);
  //  writeln("B._value.locArr[",rid,"].myElems ", B._value.locArr[rid].myElems);

  on Locales[0] {
      dststrides[1]=1;
      srcstrides[1]=1;
      count[1]=1;
      count[2]=1;

	  //start of MemoryBounding code
	  var count_tuple: (rank+1)*int;
	  for i in 1..rank+1 {
	   	  count_tuple(i) = count(i);
	  }
	  
	  var srcStride_tuple: rank*int;
	  for i in 1..rank {
		  srcStride_tuple(i) = srcstrides(i);
	  }
	  
	  var bounded_count_tuple : (rank + 1)*int  = create_bounded_count(rank, count_tuple, memory_bound);
	  var chunks_tuple: (rank + 1)*int = create_number_of_cuts(rank, count_tuple, bounded_count_tuple);
	  
	  for i in go_through_chunks(rank, chunks_tuple, count_tuple, bounded_count_tuple) {
		  
		  writeln(i);
		  
		  var bufsize: int = num_elements(rank, i.bounded_chunk_count);
		  
		  //calculate the offset from the src pointer
		  i.offset = calculate_offset(rank, i, srcStride_tuple, bounded_count_tuple);
					
		  //convert bounded_count_tuple back to an array
		  var bounded_count: [1..rank+1] int(32);
		  for j in 1..rank+1 {
		 	  bounded_count[j] = i.bounded_chunk_count[j] : int(32);
		  } 
		
  	      var buf: [1..bufsize] int;
		  var dest = buf._value.theData;
	      //var dest = locArr[0].myElems._value.theData; // can this be myLocArr?
	      var srcl = B._value.locArr[lid].myElems._value.theData;
	      var srcr = B._value.locArr[rid].myElems._value.theData;
	      var dststr=dststrides._value.theData;
	      var srcstr=srcstrides._value.theData;
	      var cnt=count._value.theData;
		  		  
	      // 1.- get some elements from B on locale 1 to A on locale 0      
	      __primitive("chpl_comm_get_strd",
	      		  __primitive("array_get",dest,
	      			      buf._value.getDataIndex(1)),
	      		  __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
	      		  rid,
	      		  __primitive("array_get",srcr,
	      			      B._value.locArr[rid].myElems._value.getDataIndex(100)),
	      		  __primitive("array_get",srcstr,srcstrides._value.getDataIndex(58)),
	      		  __primitive("array_get",cnt, count._value.getDataIndex(1)),
	      		  stridelevels);
			  
		  writeln(buf);
	  }
	  
			/*  
// 2.- get some elements from B on locale 0 to A on locale 0
      __primitive("chpl_comm_get_strd",
      		  __primitive("array_get",dest,
      			      locArr[0].myElems._value.getDataIndex(24)),
      		  __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
      		  lid,
      		  __primitive("array_get",srcl,
      			      B._value.locArr[lid].myElems._value.getDataIndex(8)),
      		  __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
      		  __primitive("array_get",cnt, count._value.getDataIndex(1)),
      		  stridelevels);

      var src = locArr[0].myElems._value.theData; // can this be myLocArr?
      var destl = B._value.locArr[lid].myElems._value.theData;
      var destr = B._value.locArr[rid].myElems._value.theData;
	  
// 3.- put some elements from A on locale 0 to B on locale 1
      __primitive("chpl_comm_put_strd",
      		  __primitive("array_get",destr,
			      B._value.locArr[rid].myElems._value.getDataIndex(76)),
      		  __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
      		  rid,
      		  __primitive("array_get",src,
      			      locArr[0].myElems._value.getDataIndex(26)),
      		  __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
      		  __primitive("array_get",cnt, count._value.getDataIndex(1)),
      		  stridelevels);
			  
// 4.- put some elements from A on locale 0 to B on locale 0
      __primitive("chpl_comm_put_strd",
      		  __primitive("array_get",destl,
			      B._value.locArr[lid].myElems._value.getDataIndex(16)),
      		  __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
      		  lid,
      		  __primitive("array_get",src,
      			      locArr[0].myElems._value.getDataIndex(2)),
      		  __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
      		  __primitive("array_get",cnt, count._value.getDataIndex(1)),
      		  stridelevels);*/

  }
}

proc main(){

  /* write("A Distribution: "); */

  var a,b:int;
  var i:int;
  for (a,i) in zip(A,{1..n}) do a=i;
  for (b,i) in zip(B,{1..n}) do b=i*100;
  writeln("Original vector:");
  writeln("===================");
  writeln("A= ", A);
  writeln();
  writeln("B= ", B);

  TestGetsPuts(A,B);

  writeln("After gets and puts");

  writeln("A= ", A);
  writeln();
  writeln("B= ", B);

  writeln();
}