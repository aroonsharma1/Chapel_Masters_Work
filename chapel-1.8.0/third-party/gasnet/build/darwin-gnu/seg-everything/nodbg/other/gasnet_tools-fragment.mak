# Description: Makefile fragment for GASNet_tools, GASNET_#THREAD_MODEL# mode
# #AUTOGEN#
# other/gasnet_tools-fragment.mak.  Generated from gasnet_tools-fragment.mak.in by configure.
# $Revision: 1.1 $
# Copyright 2011, Dan Bonachea <bonachea@cs.berkeley.edu>
# Terms of use are as specified in license.txt

# ----------------------------------------------------------------------
# Usage instructions:
#
# Clients should include this file in their Makefile, using: (no leading '#')
#     include ###INSTALL_PREFIX###/include/gasnet_tools-#thread_model#.mak  
# or alternatively, just:
#     include gasnet_tools-#thread_model#.mak  
# and use a -I###INSTALL_PREFIX###/include
# command-line option when invoking make
#
# Then in the Makefile, use a compile line something like this:
#  $(GASNETTOOLS_CC) $(GASNETTOOLS_CPPFLAGS) $(GASNETTOOLS_CFLAGS) -c myfile.c
#
# and a link line something like this:
#  $(GASNETTOOLS_LD) $(GASNETTOOLS_LDFLAGS) -o myfile myfile.o $(GASNETTOOLS_LIBS)
# ----------------------------------------------------------------------

GASNETTOOLS_INCLUDES =  -I###INSTALL_PREFIX###/include
GASNETTOOLS_INCLUDES =  -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2 -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/other -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/build/darwin-gnu/seg-everything/nodbg ###NOINSTALL###

GASNETTOOLS_LIBDIR = ###INSTALL_PREFIX###/lib
GASNETTOOLS_LIBDIR = /Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/build/darwin-gnu/seg-everything/nodbg  ###NOINSTALL###

GASNETTOOLS_DEBUGFLAGS = -DNDEBUG

GASNETTOOLS_THREADFLAGS_PAR = -DGASNETT_THREAD_SAFE -D_REENTRANT
GASNETTOOLS_THREADFLAGS_SEQ =
GASNETTOOLS_THREADFLAGS = $(GASNETTOOLS_THREADFLAGS_#THREAD_MODEL#)

GASNETTOOLS_THREADLIBS_PAR =  
GASNETTOOLS_THREADLIBS_SEQ = 
GASNETTOOLS_THREADLIBS = $(GASNETTOOLS_THREADLIBS_#THREAD_MODEL#)

GASNETTOOLS_TOOLLIB_NAME = gasnet_tools-#thread_model#

GASNETTOOLS_CC = /usr/bin/gcc 
GASNETTOOLS_CPPFLAGS = $(GASNETTOOLS_DEBUGFLAGS) $(GASNETTOOLS_THREADFLAGS)  $(GASNETTOOLS_INCLUDES) $(MANUAL_CPPFLAGS)
GASNETTOOLS_CFLAGS = -O3 -Wno-empty-body -Wno-unused-value  $(KEEPTMP_CFLAGS) $(MANUAL_CFLAGS)
GASNETTOOLS_LD = /usr/bin/gcc 
GASNETTOOLS_LDFLAGS = -O3 -Wno-empty-body -Wno-unused-value  -L$(GASNETTOOLS_LIBDIR) $(MANUAL_LDFLAGS)
GASNETTOOLS_LIBS = -l$(GASNETTOOLS_TOOLLIB_NAME) $(GASNETTOOLS_THREADLIBS)   $(MANUAL_LIBS)
GASNETTOOLS_CXX = /usr/bin/g++ 
GASNETTOOLS_CXXFLAGS = -O3 -Wno-unused-value  -Wno-empty-body $(MANUAL_CXXFLAGS)

