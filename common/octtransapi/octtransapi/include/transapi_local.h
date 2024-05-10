/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: TRANSAPI_LOCAL.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __TRANSAPI_LOCAL_H__
#define __TRANSAPI_LOCAL_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../include/octtransapi_local.h"
#include "transapi.h"


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/


/****************************  STRUCTURE ********************************/
typedef struct
{
	tTRANSAPI_CTX					TransCtx;	/* MUST be first */

} tTRANSAPI_LOCAL_CTX;


/****************************  STATIC FUNCTION ********************************/
extern tOCT_INT32 TransApiLocalInitCtx( tTRANSAPI_LOCAL_CTX *f_pLocalCtx );
extern tOCT_INT32 TransApiLocalClose( tTRANSAPI_CTX * f_pTransCtx );

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __TRANSAPI_LOCAL_H__*/


