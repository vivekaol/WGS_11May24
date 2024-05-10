#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: ETH_UTIL.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: ETH linux porting transport

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release. 

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __ETH_UTIL_H__
#define __ETH_UTIL_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../../include/octtransapi_eth.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/****************************  STATIC FUNCTION ********************************/
typedef struct
{
	int		 					iIF_GlobalIndex;		
	unsigned 					ulIF_EthIndex;
	tOCTTRANSAPI_MAC_ADDRESS *	pMacAddress;		
	signed char			 		szName[128];
	
}tOCTTRANS_ETH_IF_INFO;

extern tOCTTRANSAPI_RC_ERROR TransApiEthGetInterfaceInfoByIndex(unsigned f_uiIndex, tOCTTRANS_ETH_IF_INFO *f_pEthIfInfo );
extern tOCTTRANSAPI_RC_ERROR TransApiEthGetInterfaceInfoByName(char *f_pszInterfaceName, tOCTTRANS_ETH_IF_INFO *f_pEthIfInfo);
extern tOCTTRANSAPI_RC_ERROR TransApiEthInterfaceInfoByMAC( tOCTTRANSAPI_MAC_ADDRESS *f_pMacAddress, tOCTTRANS_ETH_IF_INFO *f_pEthIfInfo );

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __ETH_UTIL_H__*/
#endif /* __linux__ */
