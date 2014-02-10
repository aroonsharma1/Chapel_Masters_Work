use BlockDist;

const n: int=5*numLocales;
var Dist = new dmap(new Block({1..n,1..n}));

var Dom: domain(2,int) dmapped Dist = {1..n,1..n};

var A:[Dom] int(64); //real
var B:[Dom] int(64); //real

proc TestGetsPuts(A:[], B:[])
{
  A._value.TestGetsPuts(B);
}


proc BlockArr.TestGetsPuts(B)
{
  param stridelevels=1;
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
      srcstrides[1]=5;
      count[1]=5;
      count[2]=5;
	 
	  var srcl = B._value.locArr[lid,0].myElems._value.theData;
      var srcr = B._value.locArr[rid,0].myElems._value.theData;
	  writeln(B._value.locArr[rid,0].myElems[6..8, 1..3]);
      var dststr=dststrides._value.theData;
      var srcstr=srcstrides._value.theData;
      var cnt=count._value.theData;
	  
	 var bufsize: int = 1;
	 for i in count {
		bufsize *= i;
	 }
	  
	 var buf: [1..bufsize] int;
	 var dest = buf._value.theData; // can this be myLocArr?
	  
// 1.- get some elements from B on locale 1 to A on locale 0      
	      __primitive("chpl_comm_get_strd",
      		  __primitive("array_get",dest,
      			      buf._value.getDataIndex(1)),
      		  __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
      		  rid,
      		  __primitive("array_get",srcr,
      			      B._value.locArr[rid,0].myElems._value.getDataIndex((6,1))),
      		  __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
      		  __primitive("array_get",cnt, count._value.getDataIndex(1)),
      		  stridelevels);
			  
		  writeln(buf);
			  
		     __primitive("chpl_comm_get_strd",
	      		  __primitive("array_get",dest,
	      			      buf._value.getDataIndex(1)),
	      		  __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
	      		  rid,
	      		  __primitive("array_get",srcr,
	      			      B._value.locArr[rid,0].myElems._value.getDataIndex((6+2,1+5))),
	      		  __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
	      		  __primitive("array_get",cnt, count._value.getDataIndex(1)),
	      		  stridelevels);
	writeln(buf);
  }
}

proc main(){

  /* write("A Distribution: "); */

  var a,b:int;
  var i:int;
  for i in 1..n {
	  for j in 1..n {
		  A[i,j] = i+j;
	  }
  }
  
  for i in 1..n {
	  for j in 1..n {
		  B[i,j] = 100*(i+j);
	  }
  }
  writeln("Original vector:");
  writeln("===================");
  writeln("A= ", A);
  writeln();
  writeln("B= ", B);
  writeln();
  TestGetsPuts(A,B);

  writeln("After gets and puts");

  writeln("A= ", A);
  writeln();
  writeln("B= ", B);

  writeln();

}
