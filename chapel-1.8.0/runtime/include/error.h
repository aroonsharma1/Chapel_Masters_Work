/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#ifndef _error_H_
#define _error_H_

#include "chpltypes.h"
#include <stdint.h>

extern int verbosity;

void chpl_warning(const char* message, int32_t lineno, chpl_string filename);
void chpl_error(const char* message, int32_t lineno, chpl_string filename);
void chpl_internal_error(const char* message);
void chpl_msg(int verbose_level, const char* fmt, ...)
  __attribute__((format(printf, 2, 3)));

#ifndef LAUNCHER
void chpl_error_init(void);
#endif

#endif
