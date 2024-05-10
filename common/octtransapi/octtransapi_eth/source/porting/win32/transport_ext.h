/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_TRANSPORT_EXT.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: Windows transport extension

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __ETH_TRANSPORT_EXT_H__
#define __ETH_TRANSPORT_EXT_H__

/*****************************  INCLUDE FILES  *******************************/

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/
/* 
	The local context parameter can be NULL or a pointer to a persistant
	tOCTTRANS_API_ETH_CONTEXT_PCAP_ENDPOINT structure.
*/

typedef struct
{
	char *			pszFilter;

} tOCTTRANSAPI_ETH_CONTEXT_PCAP_ENDPOINT, *tPOCTTRANSAPI_ETH_CONTEXT_PCAP_ENDPOINT;


/*****************************  MACROS ************************************/


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __ETH_TRANSPORT_EXT_H__*/


