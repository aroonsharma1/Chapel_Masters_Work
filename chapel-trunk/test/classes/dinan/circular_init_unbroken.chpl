class C {
  var a: int = b+1;
  var b: int = a-1;
}

var c: C = new C();

writeln("a=", c.a, " b=", c.b);
