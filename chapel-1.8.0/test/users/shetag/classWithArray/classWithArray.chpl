class C {
  const arr : [1..2] int;
}

const a : [1..2] int = (1, 2);

var c2 = new C(a);

var c1 : C;
c1 = new C(a);

var c3 = new C();

var c4 : C;

writeln("c1 is: ", c1);
writeln("c2 is: ", c2);
writeln("c3 is: ", c3);
writeln("c4 is: ", c4);

delete c1;
delete c2;
delete c3;