use CyclicDist;

const Space = {1..10, 1..10};

var MyLocaleView = {1..2, 0..4};
var MyLocales: [MyLocaleView] locale = reshape(Locales, MyLocaleView);

const CyclicSpace = Space dmapped Cyclic(startIdx=Space.low, targetLocales=MyLocales);
var A: [CyclicSpace] int;

forall a in A {
	a = here.id;
}

writeln(A);
writeln(MyLocales);
writeln(numLocales);