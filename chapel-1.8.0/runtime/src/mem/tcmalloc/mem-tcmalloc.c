/**************************************************************************
  Copyright (c) 2004-2013, Cray Inc.  (See LICENSE file for more details)
**************************************************************************/


#include "chplrt.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "chpl-comm.h"
#include "chpl-mem.h"
#include "chplmemtrack.h"
#include "chpltypes.h"
#include "error.h"
#include "tcmalloc.h"
#include "tcmalloc-interface.h"


void chpl_mem_layerInit(void)
{
  void*  heap_base;
  size_t heap_size;

  chpl_comm_desired_shared_heap(&heap_base, &heap_size);

  if (heap_base != NULL && heap_size == 0)
    chpl_internal_error("if heap address is specified, size must be also");

  //
  // Do a first allocation, to allow tcmalloc to set up its internal
  // management structures.
  //
  {
    void* p;

    if ((p = tc_malloc(1)) == NULL)
      chpl_internal_error("cannot init heap: tc_malloc() failed");
    tc_free(p);
  }

  //
  // Initialize our tcmalloc system allocator.
  //
  tcmallocChapelInit_c(heap_base, heap_size);

  //
  // If the heap has to come from the memory supplied to us (say, in
  // order that the comm layer be able to depend on all allocations
  // having come from it), use up all the system memory tcmalloc had
  // acquired before we set up our own system allocator just now.
  // All allocations after this will come from the memory supplied
  // to us.
  //
  // Note that this can waste up to twice INITIAL_USE_UP_SIZE bytes
  // of the memory supplied to us, plus overhead.
  //
  if (heap_base != NULL) {
#define INITIAL_USE_UP_SIZE ((size_t) 4 * 1024)

    size_t size;
    char*  p;

    for (size = INITIAL_USE_UP_SIZE; size > 0; size /= 2) {
      do {
        p = tc_malloc(size);
      } while (p != NULL
               && (p < (char*) heap_base
                   || p > (char*) heap_base + heap_size));

#undef INITIAL_USE_UP_SIZE
    }
  }
}


void chpl_mem_layerExit(void) { }
