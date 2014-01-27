#INSTRUCTIONS# Conduit-specific Makefile fragment settings
#INSTRUCTIONS#
#INSTRUCTIONS# The contents of this file are embedded into the 
#INSTRUCTIONS# *-(seq,par,parsync).mak Makefile fragments at conduit build time
#INSTRUCTIONS# The settings in those fragments are used to build GASNet clients
#INSTRUCTIONS# (including the GASNet tests). 
#INSTRUCTIONS# See the conduit-writer instructions in the generated fragments
#INSTRUCTIONS# or $(top_srcdir)/other/fragment-head.mak.in for usage info.

# AMMPI is MPI-based, which requires us to link using the system MPI compiler
GASNET_LD_OVERRIDE = mpicc
GASNET_LDFLAGS_OVERRIDE = -O  -Wl,-multiply_defined,suppress -Wl,-no_pie

# hooks for using AMMPI library from within build tree ###NOINSTALL### 
# (nothing additional required for installed copy)     ###NOINSTALL###
CONDUIT_INCLUDES = -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/other/ammpi          ###NOINSTALL###
CONDUIT_LIBDIRS =  -L/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/build/darwin-gnu/seg-everything/nodbg/other/ammpi        ###NOINSTALL###

CONDUIT_LIBS = -lammpi 
