/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octccs.h

$Octasic_Copyright: $

Description:

   Provide cross-plateform definition of dedicated keywords associated to
   a given compiler:
   - PC (WIN32)
   - OCT CC (Lecacy compiler upto V 1.0.1)
   - OCC	 (optimizer compiler upto V 1.0.1)

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: 11280 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTCCS_H__
#define __OCTCCS_H__

#ifdef __cplusplus
extern "C" {
#endif


/*---------------------------------------------------------------------------------------*/
// WIN32 
/*---------------------------------------------------------------------------------------*/
#include "octtypes.h"


#include <assert.h>

//call convention
#define FASTCALL

//Storage type
#define REGISTER

//Use this macro if you need to #define a #pragma
#define DO_PRAGMA(x) _Pragma (#x)
#define mPRAGMA_MUST_ITERATE(min,max,step) 
#define mPRAGMA_UNROLL(x)	
#define mASSERT_CTRAP(condition) { assert(!(condition)); }
#define ATTRIBUTE( str )


#endif  // __OCTCCS_H__
