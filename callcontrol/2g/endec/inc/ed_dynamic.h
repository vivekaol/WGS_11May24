/*******************************************************************************
  ed_dynamic.h  Developed by Dafocus - http://www.dafocus.com/
*******************************************************************************/
#ifndef __ED_DYNAMIC_H
#define __ED_DYNAMIC_H

#include "ed_user.h"
#include "ed_data.h"
#include "ed_lib.h"

#ifdef ED_DEBUG_ALLOC
#ifndef EDAlloc
#define EDAlloc EDDebugAlloc
#endif
#ifndef EDFree
#define EDFree  EDDebugFree
#endif
#define EDCheckMemory EDDebugCheckMemory();
#endif

#if !defined(EDAlloc) || !defined(EDFree)
#include <stdlib.h>
#endif

#if !defined(EDAlloc)
#define EDAlloc(sz) malloc(sz)
#endif

#if !defined(EDFree)
#define EDFree(m) free(m)
#endif

#if !defined(EDCheckMemory)
#define EDCheckMemory
#endif


#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------------
	Generic binary dynamic allocation function
------------------------------------------------------------------------------*/
int EDAllocBinary (ED_BYTE** dataPtr, unsigned requiredBits, int* usedBits);


/*------------------------------------------------------------------------------
	By setting ED_DEBUG_ALLOC, Encodix uses an internal extension that keeps
	track of memory leaks.
------------------------------------------------------------------------------*/
#ifdef ED_DEBUG_ALLOC
void* EDDebugAlloc (size_t size);
void  EDDebugFree (void* ptr);
int EDDebugPrintSummary ();
void EDDebugCheckMemory();

#endif

#ifdef __cplusplus
}
#endif

#endif
