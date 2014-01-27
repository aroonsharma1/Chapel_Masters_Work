extern type c_int = int(32);
extern type c_uint = uint(32);
extern type c_long = int(64);
extern type c_ulong = uint(64);
extern type c_longlong = int(64);
extern type c_ulonglong = uint(64);
extern type c_char = int(8);
extern type c_schar = int(8);
extern type c_uchar = uint(8);
extern type c_short = int(16);
extern type c_ushort = uint(16);
extern type ssize_t = int(64);
extern type size_t = uint(64);
extern type c_void_ptr; // opaque; no ptr arithmetic in Chapel code!

{
  pragma "no prototype"
  extern proc sizeof(type t): size_t;

  assert(sizeof(c_int) == sizeof(int(32)));
  assert(sizeof(c_uint) == sizeof(uint(32)));
  assert(sizeof(c_long) == sizeof(int(64)));
  assert(sizeof(c_ulong) == sizeof(uint(64)));
  assert(sizeof(c_longlong) == sizeof(int(64)));
  assert(sizeof(c_ulonglong) == sizeof(uint(64)));
  assert(sizeof(c_char) == sizeof(int(8)));
  assert(sizeof(c_schar) == sizeof(int(8)));
  assert(sizeof(c_uchar) == sizeof(uint(8)));
  assert(sizeof(c_short) == sizeof(int(16)));
  assert(sizeof(c_ushort) == sizeof(uint(16)));
  assert(sizeof(ssize_t) == sizeof(int(64)));
  assert(sizeof(size_t) == sizeof(uint(64)));
}
