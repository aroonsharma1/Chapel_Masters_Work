class C { }
var c : C;	// c has the class type C, initialized with the value nil.
c = new C();	// Now c refers to an object of type C.
var c2 = new C();	// The type of c2 is also C.
class D : C {}	// Class D is derived from C.
c = new D();	// Now c refers to an object of type D.
