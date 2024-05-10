/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_TCP_DEFAULT.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_TCP_DEFAULT_H__
#define __OCTTRANSAPI_TCP_DEFAULT_H__

/*****************************  INCLUDE FILES  *******************************/
#include <memory.h>
#include "octtransapi_tcp.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_TCP_OPEN structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_TCP_OPEN_DEF( _f_pParms )				\
{																					\
	tPOCTTRANSAPI_TCP_OPEN pParms = (_f_pParms);									\
	memset( pParms, 0, sizeof(*pParms) );											\
	pParms->ulTimeoutMs = 10000;														\
	pParms->LocalTcpAddress.IpAddress.ulIpVersion = cOCTTRANSAPI_IP_VERSION_ENUM_4;	\
	pParms->RemoteTcpAddress.IpAddress.ulIpVersion = cOCTTRANSAPI_IP_VERSION_ENUM_4;\
}

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_TCP_DEFAULT_H__*/
