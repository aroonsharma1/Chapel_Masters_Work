#!/usr/bin/env bash
#
# Configure environment for a particular configuration for whitebox testing.

CWD=$(cd $(dirname ${BASH_SOURCE[0]}) ; pwd)
source $CWD/functions.bash

# Ensure module commands are available.
local_bashrc=/etc/bash.bashrc.local
if [ -z "$(type module 2> /dev/null)" -a -f $local_bashrc ] ; then
    log_info "module command not available. Attempting to source ${local_bashrc}"
    source $local_bashrc
    if [ -z "$(type module 2> /dev/null)" ] ; then
        log_error "Could not access module command after sourceing local bashrc (${local_bashrc}). Exiting."
        exit 1
    fi
elif [ -z "$(type module 2> /dev/null)" ] ; then
    log_error "module command not available and local bashrc (${local_bashrc}) does not exist. Exiting."
    exit 2
fi

# Variable set by Jenkins to indicate type of whitebox. If it is not set, assume cray-xc.
platform=${CRAY_PLATFORM_FROM_JENKINS:-cray-xc}
log_info="Using platform: ${platform}"

# Setup vars that will help load the correct compiler module.
case $COMP_TYPE in
    TARGET)
        module_name=PrgEnv-${COMPILER}
        chpl_host_value=""

        export CHPL_TARGET_PLATFORM=$platform
        log_info "Set CHPL_TARGET_PLATFORM to: ${CHPL_TARGET_PLATFORM}"
        ;;
    HOST-TARGET)
        module_name=PrgEnv-${COMPILER}
        chpl_host_value=cray-prgenv-${COMPILER}

        export CHPL_HOST_PLATFORM=$platform
        export CHPL_TARGET_PLATFORM=$platform
        log_info "Set CHPL_HOST_PLATFORM to: ${CHPL_HOST_PLATFORM}"
        log_info "Set CHPL_TARGET_PLATFORM to: ${CHPL_TARGET_PLATFORM}"
        ;;
    HOST-TARGET-no-PrgEnv)
        the_cc=${COMPILER}
        if [ "${COMPILER}" = "gnu" ] ; then
            the_cc=gcc
        fi
        module_name=${the_cc}
        chpl_host_value=${COMPILER}
        ;;
    *)
        log_error "Unknown COMP_TYPE value: ${COMP_TYPE}. Exiting."
        exit 3
        ;;
esac

# Load compiler module.
case $COMPILER in
    cray)
        log_info "Loading module: ${module_name}"
        module load ${module_name}

        # swap out network modules to get "host-only" environment
        log_info "Swap network module for host-only environment."
        module swap craype-network-aries craype-target-local_host

        # TODO: Is this still needed? (thomasvandoren, 2014-07-02)
        log_info "Unloading cray-libsci module."
        module unload cray-libsci
        ;;
    intel|gnu)
        export CHPL_REGEXP=re2
        export CHPL_GMP=gmp

        log_info "Loading module: ${module_name}"
        module load ${module_name}
        ;;
    pgi)
        log_info "Loading module: ${module_name}"
        module load ${module_name}
        ;;
    *)
        log_error "Unknown COMPILER value: ${COMPILER}. Exiting."
        exit 4
        ;;
esac

export CHPL_HOME=$(cd $CWD/../.. ; pwd)

# Set CHPL_HOST_COMPILER.
if [ -n "${chpl_host_value}" ] ; then
    export CHPL_HOST_COMPILER="${chpl_host_value}"
    log_info "Set CHPL_HOST_COMPILER to: ${CHPL_HOST_COMPILER}"
fi

# Disable launchers, comm.
export CHPL_LAUNCHER=none
export CHPL_COMM=none

# Set some vars that nightly cares about.
export CHPL_NIGHTLY_LOGDIR=/data/sea/chapel/Nightly/whitebox/${platform}
export CHPL_NIGHTLY_STATDIR=/data/sea/chapel/Nightly/Stats
export CHPL_NIGHTLY_CRON_LOGDIR="$CHPL_NIGHTLY_LOGDIR"

# Ensure that one of the CPU modules is loaded.
my_arch=$($CHPL_HOME/util/chplenv/chpl_arch.py 2> /dev/null)
if [ "${my_arch}" = "none" ] ; then
    log_info "Loading craype-shanghai module to stifle chpl_arch.py warnings."
    module load craype-shanghai
fi

log_info "Current loaded modules:"
module list

log_info "Chapel environment:"
$CHPL_HOME/util/printchplenv
