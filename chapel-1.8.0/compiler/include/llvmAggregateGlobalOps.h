/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#ifndef _LLVMAGGREGATEGLOBALOPS_H_
#define _LLVMAGGREGATEGLOBALOPS_H_

#ifdef HAVE_LLVM

#include "llvmUtil.h"

llvm::FunctionPass *createAggregateGlobalOpsOptPass(unsigned globalSpace);

#endif

#endif
