#INSTRUCTIONS# Conduit-specific Makefile fragment settings
#INSTRUCTIONS#
#INSTRUCTIONS# The contents of this file are embedded into the 
#INSTRUCTIONS# *-(seq,par,parsync).mak Makefile fragments at conduit build time
#INSTRUCTIONS# The settings in those fragments are used to build GASNet clients
#INSTRUCTIONS# (including the GASNet tests). 
#INSTRUCTIONS# See the conduit-writer instructions in the generated fragments
#INSTRUCTIONS# or $(top_srcdir)/other/fragment-head.mak.in for usage info.

# When mxm-conduit uses an MPI-based bootstrapper, we must
# link using the system MPI compiler
#GASNET_LD_OVERRIDE = mpicc
#GASNET_LDFLAGS_OVERRIDE = -O  -Wl,-multiply_defined,suppress -Wl,-no_pie
#MPI_COMPAT_LIBS = 
# Some platforms need extra -libs for the socket calls in ssh-spawner:
SSH_LIBS = 
CONDUIT_INCLUDES = -DGASNET_CONDUIT_MXM 
CONDUIT_INCLUDES = -DGASNET_CONDUIT_MXM  -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/mxm-conduit ###NOINSTALL###
CONDUIT_LIBDIRS = -L 
CONDUIT_LIBS =  $(MPI_COMPAT_LIBS) $(SSH_LIBS) 
