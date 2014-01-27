/* gasnet_config.h.  Generated from gasnet_config.h.in by configure.  */
/* gasnet_config.h.in.  Generated from configure.in by autoheader.  */
/*    $Source: /var/local/cvs/gasnet/acconfig.h,v $ */
/*      $Date: 2013/03/18 02:33:07 $ */
/*  $Revision: 1.187 $ */
/*  Description: GASNet acconfig.h (or config.h)                             */
/*  Copyright 2002, Dan Bonachea <bonachea@cs.berkeley.edu>                  */
/* Terms of use are as specified in license.txt */

#ifndef _INCLUDE_GASNET_CONFIG_H_
#define _INCLUDE_GASNET_CONFIG_H_
#if !defined(_IN_GASNET_H) && !defined(_IN_GASNET_TOOLS_H)
  #error This file is not meant to be included directly- clients should include gasnet.h or gasnet_tools.h
#endif


#define GASNETI_BUILD_ID "Mon Dec  2 20:45:51 EST 2013 aroonsharma"
#define GASNETI_CONFIGURE_ARGS " '--prefix=/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/install/darwin-gnu/seg-everything/nodbg' '--enable-segment-everything' '--enable-allow-gcc4' '--disable-seq' '--enable-par' '--disable-parsync' 'CC=gcc' 'CXX=g++'"
#define GASNETI_SYSTEM_TUPLE "x86_64-apple-darwin13.0.0"
#define GASNETI_SYSTEM_NAME "Aroon-Sharmas-MacBook-Pro.local"
/* #undef GASNETI_CROSS_COMPILING */

/* version identifiers */
#define GASNET_RELEASE_VERSION_MAJOR 1
#define GASNET_RELEASE_VERSION_MINOR 20
#define GASNET_RELEASE_VERSION_PATCH 2
#define GASNETI_RELEASE_VERSION 1.20.2
#define GASNETI_SPEC_VERSION_MAJOR 1
#define GASNETI_SPEC_VERSION_MINOR 8
#define GASNETIT_SPEC_VERSION_MAJOR 1
#define GASNETIT_SPEC_VERSION_MINOR 7

/* configure-detected conduits */
#define GASNETI_CONDUITS " udp smp"

/* CC attributes support */
#define GASNETI_HAVE_CC_ATTRIBUTE 1
#define GASNETI_HAVE_CC_ATTRIBUTE_ALWAYSINLINE 1
#define GASNETI_HAVE_CC_ATTRIBUTE_NOINLINE 1
#define GASNETI_HAVE_CC_ATTRIBUTE_MALLOC 1
#define GASNETI_HAVE_CC_ATTRIBUTE_WARNUNUSEDRESULT 1
#define GASNETI_HAVE_CC_ATTRIBUTE_USED 1
#define GASNETI_HAVE_CC_ATTRIBUTE_UNUSED 1
#define GASNETI_HAVE_CC_ATTRIBUTE_UNUSED_TYPEDEF 1
#define GASNETI_HAVE_CC_ATTRIBUTE_MAYALIAS 1
#define GASNETI_HAVE_CC_ATTRIBUTE_NORETURN 1
#define GASNETI_HAVE_CC_ATTRIBUTE_PURE 1
#define GASNETI_HAVE_CC_ATTRIBUTE_CONST 1
#define GASNETI_HAVE_CC_ATTRIBUTE_FORMAT 1
#define GASNETI_HAVE_CC_ATTRIBUTE_FORMAT_FUNCPTR 1
#define GASNETI_HAVE_CC_ATTRIBUTE_FORMAT_FUNCPTR_ARG 1

/* CXX attributes support */
#define GASNETI_HAVE_CXX_ATTRIBUTE 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_ALWAYSINLINE 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_NOINLINE 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_MALLOC 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_WARNUNUSEDRESULT 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_USED 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_UNUSED 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_UNUSED_TYPEDEF 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_MAYALIAS 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_NORETURN 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_PURE 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_CONST 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_FORMAT 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_FORMAT_FUNCPTR 1
#define GASNETI_HAVE_CXX_ATTRIBUTE_FORMAT_FUNCPTR_ARG 1

/* MPI_CC attributes support */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_ALWAYSINLINE */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_NOINLINE */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_MALLOC */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_WARNUNUSEDRESULT */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_USED */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_UNUSED */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_UNUSED_TYPEDEF */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_MAYALIAS */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_NORETURN */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_PURE */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_CONST */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_FORMAT */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_FORMAT_FUNCPTR */
/* #undef GASNETI_HAVE_MPI_CC_ATTRIBUTE_FORMAT_FUNCPTR_ARG */

/* identification of the C compiler used at configure time */
#define GASNETI_PLATFORM_COMPILER_IDSTR "|COMPILER_FAMILY:CLANG|COMPILER_VERSION:5.0 (clang-500.2.79)|COMPILER_FAMILYID:19|GNU:4.2.1|STD:__STDC__,__STDC_VERSION__=199901L|misc:4.2.1 Compatible Apple LLVM 5.0 (clang-500.2.79)|"
#define GASNETI_PLATFORM_COMPILER_FAMILYID 19
#define GASNETI_PLATFORM_COMPILER_ID 19
#define GASNETI_PLATFORM_COMPILER_VERSION 327680

/* identification of the C++ compiler used at configure time */
#define GASNETI_PLATFORM_CXX_IDSTR "|COMPILER_FAMILY:CLANG|COMPILER_VERSION:5.0 (clang-500.2.79)|COMPILER_FAMILYID:19|GNU:4.2.1|STD:__STDC__,__cplusplus=199711L|misc:4.2.1 Compatible Apple LLVM 5.0 (clang-500.2.79)|"
#define GASNETI_PLATFORM_CXX_FAMILYID 19
#define GASNETI_PLATFORM_CXX_ID 10019
#define GASNETI_PLATFORM_CXX_VERSION 327680

/* identification of the MPI C compiler used at configure time */
/* #undef GASNETI_PLATFORM_MPI_CC_IDSTR */
/* #undef GASNETI_PLATFORM_MPI_CC_FAMILYID */
/* #undef GASNETI_PLATFORM_MPI_CC_ID */
/* #undef GASNETI_PLATFORM_MPI_CC_VERSION */

/* Defined to be the inline function modifier supported by the C
   compilers (if supported), prefixed by 'static' (if permitted) */
#define GASNET_CC_INLINE_MODIFIER static inline
/* #undef GASNET_MPI_CC_INLINE_MODIFIER */

/* C, C++ and MPI_CC compilers 'restrict' keywords (or empty) */
#define GASNETI_CC_RESTRICT __restrict__
#define GASNETI_CXX_RESTRICT __restrict__
/* #undef GASNETI_MPI_CC_RESTRICT */

/* Does CC support C99-type non-constant initializers for structs? */
#define HAVE_NONCONST_STRUCT_INIT 1
/* Does CC support C99-type constructor expressions? */
#define HAVE_CONSTRUCTOR_EXPR 1

/* true iff GASNETI_RESTRICT may be applied to types which are not pointer types until after typedef expansion */
#define GASNETI_CC_RESTRICT_MAY_QUALIFY_TYPEDEFS 1
#define GASNETI_CXX_RESTRICT_MAY_QUALIFY_TYPEDEFS 1
/* #undef GASNETI_MPI_CC_RESTRICT_MAY_QUALIFY_TYPEDEFS */

/* have mmap() */
#define HAVE_MMAP 1

/* mmap supporting flags */
#define HAVE_MAP_NORESERVE 1
#define HAVE_MAP_ANON 1
/* #undef HAVE_MAP_ANONYMOUS */

/* --with-segment-mmap-max value (if given) */
/* #undef GASNETI_MMAP_MAX_SIZE */

/* --with-max-threads value (if given) */
/* #undef GASNETI_MAX_THREADS_CONFIGURE */

/* has usleep() */
#define HAVE_USLEEP 1

/* has nanosleep() */
#define HAVE_NANOSLEEP 1

/* has nsleep() */
/* #undef HAVE_NSLEEP */

/* has sched_yield() */
#define HAVE_SCHED_YIELD 1

/* have sysctl machdep.tsc_freq */
/* #undef GASNETI_HAVE_SYSCTL_MACHDEP_TSC_FREQ */

/* has Portable Linux Processor Affinity */
/* #undef HAVE_PLPA */

/* have ptmalloc's mallopt() options */
/* #undef HAVE_PTMALLOC */

/* have declarations/definitions */
#define HAVE_SETENV_DECL 1
#define HAVE_UNSETENV_DECL 1
#define HAVE_SNPRINTF_DECL 1
#define HAVE_VSNPRINTF_DECL 1
#define HAVE_ISBLANK_DECL 1
#define HAVE_ISASCII_DECL 1
#define HAVE_TOASCII_DECL 1

/* ctype.h needs wrappers */
/* #undef GASNETI_NEED_CTYPE_WRAPPERS */

/* Forbidden to use fork(), popen() and system()? */
/* #undef GASNETI_NO_FORK */

/* building Process SHared Memory support?  For which API? */
/* #undef GASNETI_PSHM_ENABLED */
/* #undef GASNETI_PSHM_POSIX */
/* #undef GASNETI_PSHM_SYSV */
/* #undef GASNETI_PSHM_FILE */
/* #undef GASNETI_PSHM_XPMEM */

/* How many cores/node must we support (255 is default) */
/* #undef GASNETI_CONFIG_PSHM_MAX_NODES */

/* hugetlbfs support available */
/* #undef HAVE_HUGETLBFS */

/* hugetlbfs support enabled */
/* #undef GASNETI_USE_HUGETLBFS */

/* location of FCA installation, if any */
/* #undef GASNET_FCA_HOME */

/* support for backtracing */
#define HAVE_EXECINFO_H 1
#define HAVE_BACKTRACE 1
#define HAVE_BACKTRACE_SYMBOLS 1
/* #undef HAVE_PRINTSTACK */
/* #undef ADDR2LINE_PATH */
#define GDB_PATH "/usr/bin/gdb"
/* #undef PGDBG_PATH */
/* #undef IDB_PATH */
/* #undef LADEBUG_PATH */
/* #undef DBX_PATH */

/* have pthread_setconcurrency */
#define HAVE_PTHREAD_SETCONCURRENCY 1

/* has pthread_kill() */
#define HAVE_PTHREAD_KILL 1

/* has pthread_kill_other_threads_np() */
/* #undef HAVE_PTHREAD_KILL_OTHER_THREADS_NP */

/* has __thread thread-local-storage support */
#define GASNETI_HAVE_TLS_SUPPORT 1

/* pause instruction, if any */
#define GASNETI_PAUSE_INSTRUCTION "pause"

/* How to name MIPS assembler temporary register in inline asm, if at all */
/* #undef GASNETI_HAVE_MIPS_REG_1 */
/* #undef GASNETI_HAVE_MIPS_REG_AT */

/* has ARM kernel-level support for cmpxchg */
/* #undef GASNETI_HAVE_ARM_CMPXCHG */

/* has ARM kernel-level support for membar */
/* #undef GASNETI_HAVE_ARM_MEMBAR */

/* has x86 EBX register (not reserved for GOT) */
#define GASNETI_HAVE_X86_EBX 1

/* has support (toolchain and cpu) for ia64 cmp8xchg16 instruction */
/* #undef GASNETI_HAVE_IA64_CMP8XCHG16 */

/* has support (toolchain and cpu) for x86_64 cmpxchg16b instruction */
#define GASNETI_HAVE_X86_CMPXCHG16B 1

/* gcc/gas support "LDCW,CO" psuedo-op on PA-RISC */
/* #undef GASNETI_HAVE_PARISC_LDCW_CO */

/* gcc support for "U" and "h" register classes on SPARC32 */
/* #undef GASNETI_HAVE_SPARC32_64BIT_ASM */

/* has __builtin_expect */
#define HAVE_BUILTIN_EXPECT 1

/* has __builtin_prefetch */
#define HAVE_BUILTIN_PREFETCH 1

/* has __func__ function name defined */
#define HAVE_FUNC 1

/* portable inttypes support */
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_SYS_TYPES_H 1
#define COMPLETE_INTTYPES_H 1
#define COMPLETE_STDINT_H 1
/* #undef COMPLETE_SYS_TYPES_H */

/* Linux PR_SET_PDEATHSIG support */
/* #undef HAVE_PR_SET_PDEATHSIG */

/* forcing use of "non-native" implementations: */
/* #undef GASNETI_FORCE_GENERIC_ATOMICOPS */
/* #undef GASNETI_FORCE_OS_ATOMICOPS */
/* #undef GASNETI_FORCE_COMPILER_ATOMICOPS */
/* #undef GASNETI_FORCE_TRUE_WEAKATOMICS */
/* #undef GASNETI_FORCE_GENERIC_SEMAPHORES */
/* #undef GASNETI_FORCE_YIELD_MEMBARS */
/* #undef GASNETI_FORCE_SLOW_MEMBARS */
/* #undef GASNETI_FORCE_GETTIMEOFDAY */
/* #undef GASNETI_FORCE_POSIX_REALTIME */

/* forcing UP build, even if build platform is a multi-processor */
/* #undef GASNETI_UNI_BUILD */

/* force memory barriers on GASNet local (loopback) puts and gets */
/* #undef GASNETI_MEMSYNC_ON_LOOPBACK */

/* throttle polling threads in multi-threaded configurations to reduce contention */
/* #undef GASNETI_THROTTLE_FEATURE_ENABLED */

/* auto-detected mmap data page size */
#define GASNETI_PAGESIZE 4096
#define GASNETI_PAGESHIFT 12

/* auto-detected shared data cache line size */
#define GASNETI_CACHE_LINE_BYTES 64
#define GASNETI_CACHE_LINE_SHIFT 6

/* udp-conduit default custom spawn command */
/* #undef GASNET_CSPAWN_CMD */

/* compiler is Sun's "gccfss" variant of GCC */
/* #undef GASNETI_GCC_GCCFSS */

/* compiler is Apple's variant of GCC */
/* #undef GASNETI_GCC_APPLE */

/* platform is an SGI Altix multiprocessor */
/* #undef GASNETI_ARCH_ALTIX */
/* #undef GASNETI_USE_MMTIMER */

/* platform is a Linux cluster running IBM PE software */
/* #undef GASNETI_ARCH_IBMPE */

/* platform is an IBM BlueGene/P multiprocessor */
/* #undef GASNETI_ARCH_BGP */

/* platform is an IBM BlueGene/Q multiprocessor */
/* #undef GASNETI_ARCH_BGQ */

/* platform is a SiCortex multiprocessor */
/* #undef GASNETI_ARCH_SICORTEX */

/* have (potentially buggy) SiCortex ICE9A CPU */
/* #undef GASNETI_ARCH_ICE9A */

/* have (potentially buggy) MIPS R10000 multiprocessor */
/* #undef GASNETI_ARCH_SGI_IP27 */

/* have working UltraSPARC ISA (lacks an associated builtin preprocessor macro) */
/* #undef GASNETI_ARCH_ULTRASPARC */

/* Have working PPC64 ISA (lacks an associated builtin preprocessor macro) */
/* #undef GASNETI_ARCH_PPC64 */
/* Tune for a PPC970 cpu (should not crash other PPCs) */
/* #undef GASNETI_TUNE_PPC970 */

/* Type to use as socklen_t */
#define GASNET_SOCKLEN_T socklen_t

/* GASNet build configuration */
/* #undef GASNET_DEBUG */
#define GASNET_NDEBUG 1
/* #undef GASNET_TRACE */
/* #undef GASNET_STATS */
/* #undef GASNET_DEBUGMALLOC */
/* #undef GASNET_SRCLINES */
/* #undef GASNET_DEBUG_VERBOSE */
/* #undef GASNET_USE_STRICT_PROTOTYPES */

/* GASNet segment definition */
/* #undef GASNET_SEGMENT_FAST */
/* #undef GASNET_SEGMENT_LARGE */
#define GASNET_SEGMENT_EVERYTHING 1

/* Override to disable default segment alignment */
/* #undef GASNETI_DISABLE_ALIGNED_SEGMENTS */

/* GASNet smp-conduit */
/* #undef GASNETC_HAVE_O_ASYNC */
/* #undef GASNETC_USE_SOCKETPAIR */

/* GASNet gm-conduit broken 2.x versions */
/* #undef GASNETC_GM_ENABLE_BROKEN_VERSIONS */
/* #undef GASNETC_GM_MPI_COMPAT */

/* GASNet vapi-conduit features and bug work-arounds */
/* #undef HAVE_VAPI_FMR */
/* #undef GASNETC_VAPI_POLL_LOCK */
/* #undef GASNETC_VAPI_RCV_THREAD */
/* #undef GASNETC_VAPI_CONN_THREAD */
/* #undef GASNETC_VAPI_MAX_HCAS */

/* GASNet ibv-conduit features and bug work-arounds */
/* #undef HAVE_IBV_SRQ */
/* #undef HAVE_IBV_XRC */
/* #undef HAVE_IBV_TRANSPORT_TYPE */
/* #undef GASNETC_IBV_POLL_LOCK */
/* #undef GASNETC_IBV_RCV_THREAD */
/* #undef GASNETC_IBV_CONN_THREAD */
/* #undef GASNETC_IBV_MAX_HCAS */

/* GASNet lapi-conduit specific */
/* #undef GASNETC_LAPI_FEDERATION */
/* #undef GASNETC_LAPI_COLONY */
/* #undef GASNETC_LAPI_GENERIC */
/* #undef GASNETC_LAPI_VERSION_A */
/* #undef GASNETC_LAPI_VERSION_B */
/* #undef GASNETC_LAPI_VERSION_C */
/* #undef GASNETC_LAPI_VERSION_D */
/* #undef GASNETC_LAPI_RDMA */

/* GASNet elan-conduit specific */
/* #undef GASNETC_ELAN3 */
/* #undef GASNETC_ELAN4 */
/* #undef ELAN_VERSION_MAJOR */
/* #undef ELAN_VERSION_MINOR */
/* #undef ELAN_VERSION_SUB */
/* #undef ELAN_DRIVER_VERSION */
/* #undef ELAN4_KERNEL_PATCH */
/* #undef HAVE_RMS_RMSAPI_H */
/* #undef HAVE_RMS_KILLRESOURCE */
/* #undef RMS_RCONTROL_PATH */
/* #undef SLURM_SCANCEL_PATH */
/* #undef HAVE_SLURM_SLURM_H */
/* #undef HAVE_SLURM_KILL_JOB */
/* #undef HAVE_ELAN_QUEUEMAXSLOTSIZE */
/* #undef HAVE_ELAN_DONE */
/* #undef HAVE_ELAN_QUEUETXINIT */

/* GASNet portals-conduit specific */
/* #undef HAVE_PCTMBOX_H */
/* #undef HAVE_PMI_CNOS */
/* #undef GASNETC_PORTALS_MISSING_EQ_HANDLER_T */

/* GASNet bug1389 detection/work-around */
/* #undef GASNETI_BUG1389_WORKAROUND */

/* Defaults for GASNET_SSH_* env vars */
#define GASNETI_DEFAULT_SSH_CMD "ssh"
#define GASNETI_DEFAULT_SSH_OPTIONS ""
#define GASNETI_DEFAULT_SSH_NODEFILE ""
#define GASNETI_DEFAULT_SSH_RATE "0"

/* Settings for ssh-spawner */
#define GASNETI_SSH_TOPO_FLAT 1
/* #undef GASNETI_SSH_TOPO_NARY */
/* #undef GASNETI_SSH_NARY_DEGREE */


/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP
   systems. This function is required for `alloca.c' support on those systems.
   */
/* #undef CRAY_STACKSEG_END */

/* Define to 1 if using `alloca.c'. */
/* #undef C_ALLOCA */

/* Define to 1 if you have `alloca', as a function or macro. */
#define HAVE_ALLOCA 1

/* Define to 1 if you have <alloca.h> and it should be used (not on Ultrix).
   */
#define HAVE_ALLOCA_H 1

/* Define to 1 if you have the `backtrace' function. */
#define HAVE_BACKTRACE 1

/* Define to 1 if you have the `backtrace_symbols' function. */
#define HAVE_BACKTRACE_SYMBOLS 1

/* Define to 1 if you have the <catamount/cnos_mpi_os.h> header file. */
/* #undef HAVE_CATAMOUNT_CNOS_MPI_OS_H */

/* Define to 1 if you have the <cnos_mpi_os.h> header file. */
/* #undef HAVE_CNOS_MPI_OS_H */

/* Define to 1 if you have the <execinfo.h> header file. */
#define HAVE_EXECINFO_H 1

/* Define to 1 if you have the <fca/include/fca/fca_api.h> header file. */
/* #undef HAVE_FCA_INCLUDE_FCA_FCA_API_H */

/* Define to 1 if you have the <features.h> header file. */
/* #undef HAVE_FEATURES_H */

/* Define to 1 if you have the `fopen64' function. */
/* #undef HAVE_FOPEN64 */

/* Define to 1 if you have the `fork' function. */
#define HAVE_FORK 1

/* Define to 1 if you have the `gethostid' function. */
#define HAVE_GETHOSTID 1

/* Define to 1 if you have the `getrlimit' function. */
#define HAVE_GETRLIMIT 1

/* Define to 1 if you have the `getrlimit64' function. */
/* #undef HAVE_GETRLIMIT64 */

/* Define to 1 if you have the <gni_pub.h> header file. */
/* #undef HAVE_GNI_PUB_H */

/* Define to 1 if you have the <hugetlbfs.h> header file. */
/* #undef HAVE_HUGETLBFS_H */

/* Define to 1 if you have the `hugetlbfs_unlinked_fd' function. */
/* #undef HAVE_HUGETLBFS_UNLINKED_FD */

/* Define to 1 if you have the `hugetlbfs_unlinked_fd_for_size' function. */
/* #undef HAVE_HUGETLBFS_UNLINKED_FD_FOR_SIZE */

/* Define to 1 if you have the `ibv_create_xrc_rcv_qp' function. */
/* #undef HAVE_IBV_CREATE_XRC_RCV_QP */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `isascii' function. */
#define HAVE_ISASCII 1

/* Define to 1 if you have the `isblank' function. */
#define HAVE_ISBLANK 1

/* Define to 1 if you have the <linux/mmtimer.h> header file. */
/* #undef HAVE_LINUX_MMTIMER_H */

/* Define to 1 if you have the <malloc.h> header file. */
/* #undef HAVE_MALLOC_H */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <mxm/api/mxm_api.h> header file. */
/* #undef HAVE_MXM_API_MXM_API_H */

/* Define to 1 if you have the <netinet/tcp.h> header file. */
#define HAVE_NETINET_TCP_H 1

/* Define to 1 if you have the `on_exit' function. */
/* #undef HAVE_ON_EXIT */

/* Define to 1 if you have the <pmi_cray.h> header file. */
/* #undef HAVE_PMI_CRAY_H */

/* Define to 1 if you have the `popen' function. */
#define HAVE_POPEN 1

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the `putenv' function. */
#define HAVE_PUTENV 1

/* Define to 1 if you have the <rms/rmsapi.h> header file. */
/* #undef HAVE_RMS_RMSAPI_H */

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `setrlimit' function. */
#define HAVE_SETRLIMIT 1

/* Define to 1 if you have the `setrlimit64' function. */
/* #undef HAVE_SETRLIMIT64 */

/* Define to 1 if you have the <sgidefs.h> header file. */
/* #undef HAVE_SGIDEFS_H */

/* Define to 1 if you have the `shmem_longlong_cswap' function. */
/* #undef HAVE_SHMEM_LONGLONG_CSWAP */

/* Define to 1 if you have the `shmem_long_cswap' function. */
/* #undef HAVE_SHMEM_LONG_CSWAP */

/* Define to 1 if you have the `shmem_long_finc' function. */
/* #undef HAVE_SHMEM_LONG_FINC */

/* Define to 1 if you have the `sigprocmask' function. */
#define HAVE_SIGPROCMASK 1

/* Define to 1 if you have the <slurm/slurm.h> header file. */
/* #undef HAVE_SLURM_SLURM_H */

/* Define to 1 if you have the <sn/mmtimer.h> header file. */
/* #undef HAVE_SN_MMTIMER_H */

/* Define to 1 if you have the <sn/xpmem.h> header file. */
/* #undef HAVE_SN_XPMEM_H */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `system' function. */
#define HAVE_SYSTEM 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/sockio.h> header file. */
#define HAVE_SYS_SOCKIO_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/table.h> header file. */
/* #undef HAVE_SYS_TABLE_H */

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/uio.h> header file. */
#define HAVE_SYS_UIO_H 1

/* Define to 1 if you have the `toascii' function. */
#define HAVE_TOASCII 1

/* Define to 1 if you have the <ucontext.h> header file. */
/* #undef HAVE_UCONTEXT_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `unsetenv' function. */
#define HAVE_UNSETENV 1

/* Define to 1 if you have the <xpmem.h> header file. */
/* #undef HAVE_XPMEM_H */

/* Define to 1 if you have the </boot/kernel.h> header file. */
/* #undef HAVE__BOOT_KERNEL_H */

/* Define to the address where bug reports for this package should be sent. */

/* Define to the full name of this package. */

/* Define to the full name and version of this package. */

/* Define to the one symbol short name of this package. */

/* Define to the home page for this package. */

/* Define to the version of this package. */

/* The PLPA symbol prefix */
/* #undef PLPA_SYM_PREFIX */

/* The size of `char', as computed by sizeof. */
#define SIZEOF_CHAR 1

/* The size of `double', as computed by sizeof. */
#define SIZEOF_DOUBLE 8

/* The size of `float', as computed by sizeof. */
#define SIZEOF_FLOAT 4

/* The size of `float _Complex', as computed by sizeof. */
#define SIZEOF_FLOAT__COMPLEX 8

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 8

/* The size of `long double', as computed by sizeof. */
#define SIZEOF_LONG_DOUBLE 16

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P 8

/* The size of `_Bool', as computed by sizeof. */
#define SIZEOF__BOOL 1

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* whether byteorder is bigendian */
/* #undef WORDS_BIGENDIAN */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* these get us 64-bit file declarations under several Unixen */
/* they must come before the first include of features.h (included by many system headers) */
/* define them even on platforms lacking features.h */
#define _LARGEFILE64_SOURCE 1
#define _LARGEFILE_SOURCE 1
#ifdef HAVE_FEATURES_H
# include <features.h>
#endif

#endif
