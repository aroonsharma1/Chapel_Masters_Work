#INSTRUCTIONS# Conduit-specific Makefile fragment settings
#INSTRUCTIONS#
#INSTRUCTIONS# The contents of this file are embedded into the 
#INSTRUCTIONS# *-(seq,par,parsync).mak Makefile fragments at conduit build time
#INSTRUCTIONS# The settings in those fragments are used to build GASNet clients
#INSTRUCTIONS# (including the GASNet tests). 
#INSTRUCTIONS# See the conduit-writer instructions in the generated fragments
#INSTRUCTIONS# or $(top_srcdir)/other/fragment-head.mak.in for usage info.

# AMUDP is C++-based, which requires us to link using the C++ compiler
GASNET_LD_OVERRIDE = /usr/bin/g++ 
GASNET_LDFLAGS_OVERRIDE = -O3 -Wno-unused-value  -Wl,-multiply_defined,suppress -Wl,-no_pie 

# hooks for using AMUDP library from within build tree ###NOINSTALL###
# (nothing additional required for installed copy)     ###NOINSTALL###
CONDUIT_INCLUDES = -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/other/amudp          ###NOINSTALL###
CONDUIT_LIBDIRS =  -L/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/build/darwin-gnu/seg-everything/nodbg/other/amudp        ###NOINSTALL###

CONDUIT_LIBS = -lamudp   
