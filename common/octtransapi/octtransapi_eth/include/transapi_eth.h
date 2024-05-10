/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: TRANSAPI_ETH.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __TRANSAPI_ETH_H__
#define __TRANSAPI_ETH_H__

/*****************************  INCLUDE FILES  *******************************/
#include "octtransapi_eth.h"
#include "../../octtransapi/include/transapi.h"


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/
#define cTRANSAPI_ETH_LOOPBACK_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_ETH_LOOPBACK_MSG_SIZE_MAX		(256)
#define cTRANSAPI_ETH_PAYLOAD_ALIGNMENT_PADDING	(2)
#define cTRANSAPI_ETH_MAC_ADDR_SIZE				(6)
#define cTRANSAPI_ETH_ETHERTYPE_SIZE			(2)
#define cTRANSAPI_ETH_II_HEADER_SIZE			((cTRANSAPI_ETH_MAC_ADDR_SIZE*2)+cTRANSAPI_ETH_ETHERTYPE_SIZE)



#define tTRANSAPI_ETH_SOCKET_TYPE_ENUM			tOCT_UINT32
#define cTRANSAPI_ETH_SOCKET_TYPE_ENUM_LOOPBACK	(0)
#define cTRANSAPI_ETH_SOCKET_TYPE_ENUM_RAW		(1)
#define cTRANSAPI_ETH_SOCKET_TYPE_ENUM_INVALID	(2)


/****************************  STRUCTURE ********************************/
typedef struct
{
	unsigned			ulSize;
	unsigned char		abyBuffer[cTRANSAPI_ETH_LOOPBACK_MSG_SIZE_MAX+1];

} tTRANSAPI_ETH_SOCKET_LOOPBACK_MSG;

typedef struct
{
	tTRANSAPI_CTX					TransCtx;	/* MUST be first */
	tTRANSAPI_ETH_SOCKET_TYPE_ENUM	ulType;

	unsigned short					usEtherType;
	tOCTDEV_MAC_ADDRESS				SrcMacAddr;

	unsigned int					fUseSelect;
	unsigned int					fSleepOnRecv;

} tTRANSAPI_ETH_CTX;


extern char l_achBroadcastAddr[];

/****************************  STATIC FUNCTION ********************************/
extern tOCTTRANSAPI_RC_ERROR	TransApiEthInitCtx( tTRANSAPI_ETH_CTX *f_pEthCtx, tOCT_UINT32 f_ulSocketSize, tOCT_UINT32 f_ulMaxRemoteCount);
extern tOCTTRANSAPI_RC_ERROR	TransApiEthPreSelect( tOCTTRANSAPI_HANDLE	f_hTransport );
extern tOCTTRANSAPI_RC_ERROR	TransApiEthClose( tTRANSAPI_CTX *	f_pEthCtx );
extern tOCTTRANSAPI_RC_ERROR	TransApiEthSend( tTRANSAPI_CTX *	f_pTransCtx, void *	f_pBuffer,	unsigned int		f_ulBufferLength );
extern tOCTTRANSAPI_RC_ERROR	TransApiEthDestinationRecv( tOCTTRANSAPI_HANDLE	f_hTransport, tTRANSAPI_DESTINATION_RECV * f_pDestRecv  );
extern tOCTTRANSAPI_RC_ERROR	TransApiEthDestinationAdd( tTRANSAPI_CTX	*f_pTransCtx, tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_ADD_PARMS * f_pTransDestAdd );
extern tOCTTRANSAPI_RC_ERROR	TransApiEthDestinationSend( tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_SEND_PARMS *f_pParms );

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __TRANSAPI_ETH_H__*/


