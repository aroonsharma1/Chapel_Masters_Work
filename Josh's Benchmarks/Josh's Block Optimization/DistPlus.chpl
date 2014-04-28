/* 
use this file to query for the subdomain the current locale owns.
Ex) const Space = {1..10};
   const SpaceMap = Space dmapped Block(Space);
   var A : [SpaceMap] int;
   
   for L in Locales do 
     on L do writeln(A.mySubdomain());
--------------------------------------------------
if there are 4 locales, the output will be:

  {1..5, 1..5}
  {1..5, 6..10}
  {6..10, 1..5}
  {6..10, 6..10}
--------------------------------------------------

Note that these features are a work in progress, and are subject 
to change.
*/ 

// currently supported distributions
use BlockDist, CyclicDist, BlockCycDist, ReplicatedDist;
 
// TODO: Replicated doesn't use  targetLocDom. Do we need to have each 
// distribution define its own proc?
proc _array.locGridDom() {
  return _value.dom.dist.targetLocDom;
}

proc _array.locGrid() {
  return _value.dom.dist.targetLocales;
}

// wrapper to hide _value from user
proc _array.subIsSingle() param {
  return _value.dsiSubIsSingle();
}

// allows the user to determine which function they should call
// if true, then the chunk owned by each Locale can be expressed 
//   by a single domain
// if false, then the chunk is expressed as multiple domains (See BlockCyclic)
proc BlockArr.dsiSubIsSingle() param return true;

proc CyclicArr.dsiSubIsSingle() param return true;

proc ReplicatedArr.dsiSubIsSingle() param  return true;

proc BlockCyclicArr.dsiSubIsSingle() param return false;

proc DefaultRectangularArr.dsiSubIsSingle() param return true;

proc DefaultSparseArr.dsiSubIsSingle() param return true;

proc DefaultAssociativeArr.dsiSubIsSingle() param return true;

// wrapper to hide _value from the user
proc _array.mySubdomain(loc : locale = here) {
  if !_value.dsiSubIsSingle() then
    compilerError("Array's local domain is not a single domain");
  return _value.dsiMySubdomain(loc);
}

proc DefaultRectangularArr.dsiMySubdomain(loc : locale) {
  return dom.ranges;
}

proc DefaultSparseArr.dsiMySubdomain(loc : locale) {
  return dom.nnzDom;
}

// cover's Opaque too
proc DefaultAssociativeArr.dsiMySubdomain(loc : locale) {
  return dom.tableDom;
}

// Block and Cyclic are easiest, simply return the single domain
proc BlockArr.dsiMySubdomain(loc : locale) {
  return myLocArr.locDom.myBlock;
}

proc CyclicArr.dsiMySubdomain(loc : locale) {
  return myLocArr.locDom.myBlock;
}

// Replicated ony uses one domain, but there are local copies we should return
proc ReplicatedArr.dsiMySubdomain(loc : locale) {
  return localArrs[here.id].myDom.domLocalRep;
}

iter _array.multiSubdomains(loc : locale = here) {
  if _value.dsiSubIsSingle() then 
    yield _value.dsiMySubdomain(loc);
  else 
    for d in _value.multiSubdomains(loc) do yield d;
}

// essentially enumerateBlocks()
// basically add blocksize to the start indices
iter BlockCyclicArr.multiSubdomains(loc : locale) {
  for i in myLocArr.indexDom.myStarts {
    var temp : rank*range;
    for param j in 1..rank {
      var lo: idxType;
      if rank == 1 then lo = i;
      else lo = i(j);
      temp(j) = lo .. min(lo + myLocArr.indexDom.globDom.dist.blocksize(j)-1, myLocArr.indexDom.globDom.whole.dim(j).high);
    }
    const r : domain(rank, idxType, stridable) = temp;
    yield r; // yield a domain so the user can use procs like expand/exterior/etc.
  }
}
