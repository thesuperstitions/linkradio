#ifndef ALT_MALLOC_H
#define ALT_MALLOC_H

extern "C" {

// This class is used to provide alternative, instrumented versions of
// the four standard memory-management routines in stdlib.h: malloc,
// free, calloc and realloc. By instantiating this class at initialization,
// the command-processor command "alt_malloc" is registered. This command
// enables tracing of these calls, where each trace point consists of the
// following:
//	Memory address of region malloc'ed
// Alternatively, one can request a core dump when the next memory
// region allocation occurs.
//
// To use this capability, you must follow these steps:
//	1) Add "ALT_MALLOC = 1" to the Makefiles for all the libraries
//	   you are interested in instrumenting.
//	2) In the Makefile for the application you are instrumenting,
//	   you need to also add "ALT_MALLOC = 1".
// Note: to build everything with ALT_MALLOC, set it in the top-level
// Make script.

void Init_Alt_Malloc();

}

#endif
