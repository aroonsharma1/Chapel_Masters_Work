/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#ifndef _CONFIG_H_
#define _CONFIG_H_

void checkConfigs(void);
void parseCmdLineConfig(const char *, const char *);
Expr *getCmdLineConfig(const char *);
void useCmdLineConfig(const char *);
bool isUsedCmdLineConfig(const char *);

extern bool mainHasArgs;

#endif
