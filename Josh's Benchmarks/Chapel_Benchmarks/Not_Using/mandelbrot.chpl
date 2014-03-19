use CyclicZipOpt;
config const size : uint = 200;

// for binary output
extern proc putchar(i : int) : int;

proc main() {
    const bytesRequired : uint = (size + 7) / 8;
    const byteRange = 0..#bytesRequired:int(64);
    const sizeRange = 0..#size:int(64);
    
    var dist = {sizeRange, byteRange} dmapped CyclicZipOpt(startIdx=(0,0));
    
    var bytes: [dist] uint(8);
    const limit : real = 4.0;
    const maxIter : int = 50;

    forall (byte,(y,bytex)) in zip(bytes, dist) do {
/*        writeln("(", y, ", ", bytex, ")");*/
        var byte_acc : uint(8) = 0;
        
/*        writeln(byte.locale.id);*/
/*        writeln(y);
        writeln(y.locale.id);*/
        for x in (bytex*8)..#8 do {
/*            writeln(x);*/
            var Zr : real = 0.0;
            var Zi : real = 0.0;
            var Tr : real = 0.0;
            var Ti : real = 0.0;
            const Cr : real = (2.0*x/size - 1.5);
            const Ci : real = (2.0*y/size - 1.0);

            {
                var iterNo : int = maxIter;
                while (iterNo > 0 && (Tr+Ti <= limit)) {
                    Zi = 2.0*Zr*Zi + Ci;
                    Zr = Tr - Ti + Cr;
                    Tr = Zr * Zr;
                    Ti = Zi * Zi;
                    iterNo -= 1;
                }
            }

            byte_acc <<= 1;
            if (Tr+Ti <= limit) {
                byte_acc |= 0x01;
            }
        }

/*        writeln(byte.locale.id);
        writeln(byte_acc.locale.id);
        writeln();*/
        byte = byte_acc;
    }

    writeln("P4");
    writeln(size," ",size);

/*    for (x,y) in bytes.domain do {
        writeln(bytes(x,y));
    }*/
}

