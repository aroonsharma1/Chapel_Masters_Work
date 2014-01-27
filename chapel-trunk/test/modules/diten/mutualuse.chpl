module M1 {
  use M2, Time;
  class C {
    var field: int;
  }
  sleep(3);
  var a = new C(1);
}

module M2 {
  use M1;
  var n = a;
}

module M3 {
  proc main {
    use M1, M2;
    writeln(a);
    writeln(n);
  }
}
