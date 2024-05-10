/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_LOCAL_DEFAULT.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_LOCAL_DEFAULT_H__
#define __OCTTRANSAPI_LOCAL_DEFAULT_H__

/*****************************  INCLUDE FILES  *******************************/
#include <memory.h>
#include "octtransapi_local.h"


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  MACROS ************************************/

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_LOCAL_OPEN_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_LOCAL_OPEN_PARMS_DEF( _f_pParms )	\
	{												\
		tPOCTTRANSAPI_LOCAL_OPEN_PARMS pParms = (_f_pParms);	\
		memset( pParms, 0, sizeof(*pParms) );					\
	}



/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_LOCAL_DEFAULT_H__ */


