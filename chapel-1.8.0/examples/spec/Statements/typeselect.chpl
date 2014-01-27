var x = 32, y = 15.5; 
var z: int(8);
var coord = (0.0,0.0);
var yes: bool;

writetype(x);
writetype(y);
writetype(z);
writetype(coord);
writetype(yes);
writetype("no");
writetype(here);

proc writetype(x) {
  type select x {
    when int do writeln("Integer type");
    when uint do writeln("Unsigned integer type");
    when real do writeln("Real type");
    when complex do writeln("Complex type");
    when string do writeln("String type");
    when bool do writeln("Boolean type");
    when imag do writeln("Imag type");
    when locale do writeln("Locale type");
    when void do writeln("Void type");
    otherwise writeln("Non-primitive type");
  }
}
