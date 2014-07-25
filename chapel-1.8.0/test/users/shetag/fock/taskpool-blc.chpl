module taskpool {

use blockindices;

// hack: working around lack of sync arr in class issue
var taskarr$ : [0..1000] sync blockIndices;
 
class taskpool {
  const poolSize;
  //  var taskarr$ : [0..poolSize-1] sync blockIndices; 
  var head$, tail$ : sync int = 0;
  proc add(blk: blockIndices) {
    const pos = tail$;
    tail$ = (pos+1)%poolSize;
    taskarr$(pos) = blk;
  }
  proc remove() {
    const pos = head$;
    head$ = (pos+1)%poolSize;
    return taskarr$(pos);
  }
}
}