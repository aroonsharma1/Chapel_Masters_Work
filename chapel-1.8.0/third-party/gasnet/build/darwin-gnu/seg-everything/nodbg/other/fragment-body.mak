# $Header: /var/local/cvs/gasnet/other/fragment-body.mak.in,v 1.7 2009/09/18 23:33:36 phargrov Exp $
# ----------------------------------------------------------------------
# Following section other/fragment-body.mak.  Generated from fragment-body.mak.in by configure.

# ----------------------------------------------------------------------
# Directory-based options

GASNET_INCLUDES =  -I###INSTALL_PREFIX###/include -I###INSTALL_PREFIX###/include/#conduit_name#-conduit $(CONDUIT_INCLUDES) $(CONDUIT_INCLUDES_#THREAD_MODEL#)
GASNET_LIBDIRS = -L###INSTALL_PREFIX###/lib $(CONDUIT_LIBDIRS) $(CONDUIT_LIBDIRS_#THREAD_MODEL#)

# Textual lines containing the string "###NOINSTALL###" are removed by the install process
# (must be one continuous line) ###NOINSTALL###
GASNET_INCLUDES =  -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2 -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/#conduit_name#-conduit -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/other $(CONDUIT_INCLUDES) $(CONDUIT_INCLUDES_#THREAD_MODEL#) -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/GASNet-1.20.2/extended-ref -I/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/build/darwin-gnu/seg-everything/nodbg  ###NOINSTALL###
GASNET_LIBDIRS = -L/Users/aroonsharma/Desktop/CHAPEL/chapel-1.8.0/third-party/gasnet/build/darwin-gnu/seg-everything/nodbg/#conduit_name#-conduit $(CONDUIT_LIBDIRS) $(CONDUIT_LIBDIRS_#THREAD_MODEL#) ###NOINSTALL###

# ----------------------------------------------------------------------
# C compiler and options

GASNET_CC = /usr/bin/gcc 

GASNET_OPT_CFLAGS = -O3 -Wno-empty-body -Wno-unused-value $(CONDUIT_OPT_CFLAGS) $(CONDUIT_OPT_CFLAGS_#THREAD_MODEL#)
GASNET_MISC_CFLAGS =  $(CONDUIT_MISC_CFLAGS) $(CONDUIT_MISC_CFLAGS_#THREAD_MODEL#)
GASNET_MISC_CPPFLAGS =  $(CONDUIT_MISC_CPPFLAGS) $(CONDUIT_MISC_CPPFLAGS_#THREAD_MODEL#)

GASNET_EXTRADEFINES_SEQ = 
GASNET_EXTRADEFINES_PAR = -D_REENTRANT
GASNET_EXTRADEFINES_PARSYNC = -D_REENTRANT

GASNET_DEFINES = -DGASNET_#THREAD_MODEL# $(GASNET_EXTRADEFINES_#THREAD_MODEL#) $(CONDUIT_DEFINES) $(CONDUIT_DEFINES_#THREAD_MODEL#)

# ----------------------------------------------------------------------
# Documented compilation convenience aliases

GASNET_CFLAGS = $(GASNET_OPT_CFLAGS) $(GASNET_MISC_CFLAGS) $(MANUAL_CFLAGS)
GASNET_CPPFLAGS = $(GASNET_MISC_CPPFLAGS) $(GASNET_DEFINES) $(GASNET_INCLUDES)

# ----------------------------------------------------------------------
# linker and options

GASNET_LD = $(GASNET_LD_OVERRIDE)

# linker flags that GASNet clients should use 
GASNET_LDFLAGS = $(GASNET_LDFLAGS_OVERRIDE) $(CONDUIT_LDFLAGS) $(CONDUIT_LDFLAGS_#THREAD_MODEL#) $(MANUAL_LDFLAGS)

GASNET_EXTRALIBS_SEQ = 
GASNET_EXTRALIBS_PAR = 
GASNET_EXTRALIBS_PARSYNC = 

# libraries that GASNet clients should append to link line
GASNET_LIBS =                             \
    $(GASNET_LIBDIRS)                     \
    -lgasnet-#conduit_name#-#thread_model# \
    $(CONDUIT_LIBS)                       \
    $(CONDUIT_LIBS_#THREAD_MODEL#)        \
    $(GASNET_EXTRALIBS_#THREAD_MODEL#)    \
                        \
                                  \
                                    \
                                    \
    $(MANUAL_LIBS)

# ----------------------------------------------------------------------
