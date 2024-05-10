/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_ETH_DEFAULT.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_ETH_DEFAULT_H__
#define __OCTTRANSAPI_ETH_DEFAULT_H__

/*****************************  INCLUDE FILES  *******************************/
#include <memory.h>
#include "octtransapi_eth.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_ETH_OPEN structure
----------------------------------------------------------------------------*/
#ifdef OCTTRANSAPI_OPT_SELECT
#define mOCTTRANSAPI_ETH_OPEN_DEF( _f_pParms )									\
{																				\
	tPOCTTRANSAPI_ETH_OPEN pParms = (_f_pParms);								\
	memset( pParms, 0, sizeof(*pParms) );										\
	pParms->ulCtrlProtoType = cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_NONE;		\
	pParms->fUseSelect = cOCT_TRUE;												\
}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_ETH_OPEN_BY_NAME structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_ETH_OPEN_BY_NAME_DEF( _f_pParms )							\
{																				\
	tPOCTTRANSAPI_ETH_OPEN_BY_NAME pParms = (_f_pParms);						\
	memset( pParms, 0, sizeof(*pParms) );										\
	pParms->EthOpen.ulCtrlProtoType = cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_NONE;		\
	pParms->EthOpen.fUseSelect = cOCT_TRUE;										\
}
#else
#define mOCTTRANSAPI_ETH_OPEN_DEF( _f_pParms )									\
{																				\
	tPOCTTRANSAPI_ETH_OPEN pParms = (_f_pParms);								\
	memset( pParms, 0, sizeof(*pParms) );										\
	pParms->ulCtrlProtoType = cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_NONE;		\
	pParms->fUseSelect = cOCT_FALSE;											\
}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_ETH_OPEN_BY_NAME structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_ETH_OPEN_BY_NAME_DEF( _f_pParms )							\
{																				\
	tPOCTTRANSAPI_ETH_OPEN_BY_NAME pParms = (_f_pParms);						\
	memset( pParms, 0, sizeof(*pParms) );										\
	pParms->EthOpen.ulCtrlProtoType = cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_NONE;		\
	pParms->EthOpen.fUseSelect = cOCT_FALSE;											\
}

#endif
/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_ETH_DEFAULT_H__*/
