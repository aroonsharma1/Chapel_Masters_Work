/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#define _setjmp setjmp
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */
extern struct { unsigned char array[1552]; } oseg_08048000;
extern struct { unsigned char array[8]; } oseg_0804a010;
extern struct { unsigned char array[8]; } oseg_0804a000;
extern struct { unsigned char array[236]; } oseg_08049f14;
extern struct { unsigned char array[8]; } oseg_0804a008;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
static void _preinit_global_data(void);
unsigned char *main(unsigned int llvm_cbe_memArgInOut_20_0x00_20_, unsigned int llvm_cbe_memArgInOut_20_0x04_20_);
void func_08048492(void);
__attribute__((fastcall)) void callTrans(unsigned int llvm_cbe_indirCallDest_20_1, unsigned char **llvm_cbe_retArg_20_EAX_20__2e_ptr, unsigned int llvm_cbe_memArgInOut_20_0x00_20_);
unsigned int rewritten_foo(unsigned int llvm_cbe_memArgIn_20_0x00_20_, unsigned int llvm_cbe_memArgIn_20_0x04_20_);
__attribute__((fastcall)) void icthunk_func_080483f4(unsigned int llvm_cbe_indirCallDest, unsigned char **llvm_cbe_retArg_20_EAX, unsigned int llvm_cbe_memArgInOut_20_0x00);
void abort(void);


/* Global Variable Definitions and Initialization */


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

static void _preinit_global_data(void)
{
  return;
}


unsigned char *main(unsigned int llvm_cbe_memArgInOut_20_0x00_20_, unsigned int llvm_cbe_memArgInOut_20_0x04_20_)
{
  struct { unsigned int array[2]; } llvm_cbe_argcArgv_20_1_2e_ptr;    /* Address-exposed local */
  struct { unsigned char *array[7]; } llvm_cbe_stackFrame14923_2e_ptr;    /* Address-exposed local */
  unsigned char **llvm_cbe_ESP_20_40_2e_ptr;
  unsigned char *llvm_cbe_ESP_20_1544;
  unsigned int llvm_cbe_tmp__1;
  unsigned char *llvm_cbe_tmp__2;

  CODE_FOR_MAIN();
  *((&llvm_cbe_argcArgv_20_1_2e_ptr.array[((signed int )0u)])) = llvm_cbe_memArgInOut_20_0x00_20_;
  *((&llvm_cbe_argcArgv_20_1_2e_ptr.array[((signed int )1u)])) = llvm_cbe_memArgInOut_20_0x04_20_;
  _preinit_global_data();
  llvm_cbe_ESP_20_40_2e_ptr = (&llvm_cbe_stackFrame14923_2e_ptr.array[((signed int )1u)]);
  *llvm_cbe_ESP_20_40_2e_ptr = ((unsigned char *)(unsigned long)20u);
  *((&llvm_cbe_stackFrame14923_2e_ptr.array[((signed int )0u)])) = ((unsigned char *)(unsigned long)10u);
  llvm_cbe_ESP_20_1544 = *llvm_cbe_ESP_20_40_2e_ptr;
  llvm_cbe_tmp__1 = rewritten_foo(10u, (((unsigned int )(unsigned long)llvm_cbe_ESP_20_1544)));
  llvm_cbe_tmp__2 = ((unsigned char *)(unsigned long)llvm_cbe_tmp__1);
  *((&llvm_cbe_stackFrame14923_2e_ptr.array[((signed int )5u)])) = llvm_cbe_tmp__2;
  return llvm_cbe_tmp__2;
}


void func_08048492(void)
{
  return;
}


__attribute__((fastcall)) void callTrans(unsigned int llvm_cbe_indirCallDest_20_1, unsigned char **llvm_cbe_retArg_20_EAX_20__2e_ptr, unsigned int llvm_cbe_memArgInOut_20_0x00_20_)
{
  unsigned int llvm_cbe_memArgInOut_20_0x043;
  unsigned char *llvm_cbe_tmp__3;

  llvm_cbe_memArgInOut_20_0x043 = ((unsigned int )(((unsigned int )llvm_cbe_memArgInOut_20_0x00_20_) + ((unsigned int )4u)));
  goto llvm_cbe_Translator_2e_DEFAULT;

  do {     /* Syntactic loop 'Translator.DEFAULT' to make GCC happy */
llvm_cbe_Translator_2e_DEFAULT:
  if ((llvm_cbe_indirCallDest_20_1 == 134513652u))
  {
    goto llvm_cbe_func_080483f4;
  } else {
    goto llvm_cbe_nomatch;
  }

llvm_cbe_nomatch:
  (((unsigned int  (*) (unsigned int , ...))(unsigned long)llvm_cbe_indirCallDest_20_1))(0u);
  goto llvm_cbe_Translator_2e_DEFAULT;

  } while (1); /* end of syntactic loop 'Translator.DEFAULT' */
llvm_cbe_func_080483f4:
  llvm_cbe_tmp__3 = main(llvm_cbe_memArgInOut_20_0x00_20_, llvm_cbe_memArgInOut_20_0x043);
  *llvm_cbe_retArg_20_EAX_20__2e_ptr = llvm_cbe_tmp__3;
  return;
}


unsigned int rewritten_foo(unsigned int llvm_cbe_memArgIn_20_0x00_20_, unsigned int llvm_cbe_memArgIn_20_0x04_20_)
{
  struct { unsigned char array[20]; } llvm_cbe_stackFrame2_2e_ptr;    /* Address-exposed local */
  unsigned int *llvm_cbe_EBP_20_40_2e_ptr3;
  unsigned int llvm_cbe_PHANTOM64_1_20_65;
  unsigned int llvm_cbe_EAX_20_789;
  unsigned int llvm_cbe_PHANTOM64_1_20_98;
  unsigned int llvm_cbe_EAX_20_1116;
  unsigned int llvm_cbe_storemerge10;

  llvm_cbe_EBP_20_40_2e_ptr3 = ((unsigned int *)((&llvm_cbe_stackFrame2_2e_ptr.array[((signed int )8u)])));
  *llvm_cbe_EBP_20_40_2e_ptr3 = 30u;
  if ((((signed int )llvm_cbe_memArgIn_20_0x00_20_) < ((signed int )41u)))
  {
    goto llvm_cbe_080483dc;
  } else {
    goto llvm_cbe_080483c7;
  }

llvm_cbe_080483dc:
  llvm_cbe_PHANTOM64_1_20_98 = ((unsigned int )(((unsigned int )llvm_cbe_memArgIn_20_0x04_20_) * ((unsigned int )30u)));
  *(((unsigned int *)((&llvm_cbe_stackFrame2_2e_ptr.array[((signed int )12u)])))) = llvm_cbe_PHANTOM64_1_20_98;
  llvm_cbe_EAX_20_1116 = ((unsigned int )(((unsigned int )llvm_cbe_PHANTOM64_1_20_98) + ((unsigned int )25u)));
  llvm_cbe_storemerge10 = llvm_cbe_EAX_20_1116;   /* for PHI node */
  goto llvm_cbe_080483ef;

llvm_cbe_080483ef:
  *llvm_cbe_EBP_20_40_2e_ptr3 = llvm_cbe_storemerge10;
  return llvm_cbe_storemerge10;
llvm_cbe_080483c7:
  llvm_cbe_PHANTOM64_1_20_65 = ((unsigned int )(((unsigned int )llvm_cbe_memArgIn_20_0x00_20_) * ((unsigned int )30u)));
  *(((unsigned int *)((&llvm_cbe_stackFrame2_2e_ptr.array[((signed int )12u)])))) = llvm_cbe_PHANTOM64_1_20_65;
  llvm_cbe_EAX_20_789 = ((unsigned int )(((unsigned int )llvm_cbe_PHANTOM64_1_20_65) + ((unsigned int )5u)));
  llvm_cbe_storemerge10 = llvm_cbe_EAX_20_789;   /* for PHI node */
  goto llvm_cbe_080483ef;

}


__attribute__((fastcall)) void icthunk_func_080483f4(unsigned int llvm_cbe_indirCallDest, unsigned char **llvm_cbe_retArg_20_EAX, unsigned int llvm_cbe_memArgInOut_20_0x00)
{
  unsigned char *llvm_cbe_tmp__4;

  llvm_cbe_tmp__4 = main(llvm_cbe_memArgInOut_20_0x00, (((unsigned int )(unsigned long)((&(((unsigned char *)(unsigned long)llvm_cbe_memArgInOut_20_0x00))[((signed int )4u)])))));
  *llvm_cbe_retArg_20_EAX = llvm_cbe_tmp__4;
  return;
}

