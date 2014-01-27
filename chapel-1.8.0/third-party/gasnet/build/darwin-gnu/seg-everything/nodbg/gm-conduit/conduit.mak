#INSTRUCTIONS# Conduit-specific Makefile fragment settings
#INSTRUCTIONS#
#INSTRUCTIONS# The contents of this file are embedded into the 
#INSTRUCTIONS# *-(seq,par,parsync).mak Makefile fragments at conduit build time
#INSTRUCTIONS# The settings in those fragments are used to build GASNet clients
#INSTRUCTIONS# (including the GASNet tests). 
#INSTRUCTIONS# See the conduit-writer instructions in the generated fragments
#INSTRUCTIONS# or $(top_srcdir)/other/fragment-head.mak.in for usage info.

# When gm-conduit enables MPI compatibility, we must link with MPI compiler
#GASNET_LD_OVERRIDE = mpicc
#GASNET_LDFLAGS_OVERRIDE = -O  -Wl,-multiply_defined,suppress -Wl,-no_pie
#MPI_COMPAT_INCLUDES = -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/other/mpi-spawner ###NOINSTALL### 
#MPI_COMPAT_LIBS = 

CONDUIT_LIBDIRS =  -L/usr/local/gm/lib
CONDUIT_LIBS = -lgm $(MPI_COMPAT_LIBS)
firehose_includes = -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/other/firehose ###NOINSTALL###
CONDUIT_INCLUDES = -I/usr/local/gm/include $(MPI_COMPAT_INCLUDES) $(firehose_includes)

