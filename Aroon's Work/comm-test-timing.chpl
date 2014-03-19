use Time;
use CommDiagnostics;
//This tests directly call chpl_comm_get_strd to 
// 1.- get some elements from B on locale 1 to A on locale 0
// 2.- get some elements from B on locale 0 to A on locale 0
// 3.- put some elements from A on locale 0 to B on locale 1
// 4.- put some elements from A on locale 0 to B on locale 0

config var numElements: int(32) = 500;
proc TestGetsPuts(A:[], B:[], numElements)
{
  A._value.TestGetsPuts(B, numElements);
}


proc BlockArr.TestGetsPuts(B, numElements)
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
      srcstrides[1]=1;
      count[1]=1;
      count[2]=numElements;
      writeln();
      var dest = locArr[0].myElems._value.theData; // can this be myLocArr?
      var srcl = B._value.locArr[lid].myElems._value.theData;
      var srcr = B._value.locArr[rid].myElems._value.theData;
      var dststr=dststrides._value.theData;
      var srcstr=srcstrides._value.theData;
      var cnt=count._value.theData;

	  resetCommDiagnostics();
  	  var timer: Timer = new Timer();
	  timer.start();
	  startCommDiagnostics();
// 1.- get some elements from B on locale 1 to A on locale 0      
      __primitive("chpl_comm_get_strd",
      		  __primitive("array_get",dest,
      			      locArr[0].myElems._value.getDataIndex(1)),
      		  __primitive("array_get",dststr,dststrides._value.getDataIndex(1)),
      		  rid,
      		  __primitive("array_get",srcr,
      			      B._value.locArr[rid].myElems._value.getDataIndex(501)),
      		  __primitive("array_get",srcstr,srcstrides._value.getDataIndex(1)),
      		  __primitive("array_get",cnt, count._value.getDataIndex(1)),
      		  stridelevels);
			  
		timer.stop();
		stopCommDiagnostics();
		writeln(timer.elapsed(), " seconds with bulk transfer");
	
		var messages = 0;
		var coms = getCommDiagnostics();
		for i in 0..numLocales-1 {
			messages += coms(i).get:int;
			messages += coms(i).put:int;
		}
		writeln("Message count with bulk transfer = ", messages);
/*// 2.- get some elements from B on locale 0 to A on locale 0
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

use BlockDist;

const n: int=500*numLocales;
var Dist = new dmap(new Block({1..n}));

var Dom: domain(1,int) dmapped Dist = {1..n};

var A:[Dom] int(64); //real
var B:[Dom] int(64); //real

proc main(){

  /* write("A Distribution: "); */

  var a,b:int;
  var i:int;
  for (a,i) in zip(A,{1..n}) do a=i;
  for (b,i) in zip(B,{1..n}) do b=i*100;
  /*writeln("Original vector:");
  writeln("===================");
  writeln("A= ", A);
  writeln("B= ", B);*/

  TestGetsPuts(A,B,numElements);
  
  resetCommDiagnostics();
  var timer: Timer = new Timer();
  timer.start();
  startCommDiagnostics();
 
  for (a,b) in zip(A[1..numElements], A[501..501+numElements-1]) {
	  a = b;
  }

  timer.stop();
  stopCommDiagnostics();
  writeln(timer.elapsed(), " seconds without bulk transfer");

  var messages = 0;
  var coms = getCommDiagnostics();
  for i in 0..numLocales-1 {
   	  messages += coms(i).get:int;
	  messages += coms(i).put:int;
  }
  writeln("Message count without bulk transfer= ", messages);

  /*writeln("After gets and puts");

  writeln("A= ", A);
  writeln("B= ", B);

  writeln();*/

}
