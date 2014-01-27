#INSTRUCTIONS# Conduit-specific Makefile fragment settings
#INSTRUCTIONS#
#INSTRUCTIONS# The contents of this file are embedded into the 
#INSTRUCTIONS# *-(seq,par,parsync).mak Makefile fragments at conduit build time
#INSTRUCTIONS# The settings in those fragments are used to build GASNet clients
#INSTRUCTIONS# (including the GASNet tests). 
#INSTRUCTIONS# See the conduit-writer instructions in the generated fragments
#INSTRUCTIONS# or $(top_srcdir)/other/fragment-head.mak.in for usage info.

# Explicitly set linker to mpcc_r on SP to get POE library linked into executable

GASNET_LD_OVERRIDE = 
GASNET_MPI_LD =      
GASNET_LDFLAGS_OVERRIDE =  -Wl,-multiply_defined,suppress -Wl,-no_pie

# LAPI is inherently multithreaded and needs threading 
# libs and defines, even in GASNET_SEQ mode

CONDUIT_DEFINES_SEQ = -D_REENTRANT
CONDUIT_LIBS_SEQ =    

# Note: -llapi_r is intentionally omitted from CONDUIT_LIBS, to ensure we get 
# link errors if not using mpcc_r. LAPI fails at runtime in many horrible, 
# intermittent ways if you link without mpcc_r

#CONDUIT_INCLUDES = -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/other/firehose ###NOINSTALL###
