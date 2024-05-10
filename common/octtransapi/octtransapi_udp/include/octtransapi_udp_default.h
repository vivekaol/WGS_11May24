/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_UDP_DEFAULT.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_UDP_DEFAULT_H__
#define __OCTTRANSAPI_UDP_DEFAULT_H__

/*****************************  INCLUDE FILES  *******************************/
#include <memory.h>
#include "octtransapi_udp.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_UDP_OPEN structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_UDP_OPEN_DEF( _f_pParms )									\
{																				\
	tPOCTTRANSAPI_UDP_OPEN pParms = (_f_pParms);								\
	memset( pParms, 0, sizeof(*pParms) );										\
	pParms->UdpAddress.IpAddress.ulIpVersion = cOCTTRANSAPI_IP_VERSION_ENUM_4;	\
}

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_UDP_DEFAULT_H__*/
