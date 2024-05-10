/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: TRANSAPI_TCP.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __TRANSAPI_TCP_H__
#define __TRANSAPI_TCP_H__

/*****************************  INCLUDE FILES  *******************************/
#include "octtransapi_tcp.h"
#include "../../octtransapi/include/transapi.h"


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/
#define cTRANSAPI_TCP_LOOPBACK_MSG_BLOCK_MAX	(16)
#define cTRANSAPI_TCP_LOOPBACK_MSG_SIZE_MAX		(256)
#define cTRANSAPI_TCP_IP_ADDR_SIZE		(4)
#define cTRANSAPI_TCP_PORT_SIZE			(2)


#define tTRANSAPI_TCP_SOCKET_TYPE_ENUM			tOCT_UINT32
#define cTRANSAPI_TCP_SOCKET_TYPE_ENUM_LOOPBACK	(0)
#define cTRANSAPI_TCP_SOCKET_TYPE_ENUM_RAW		(1)
#define cTRANSAPI_TCP_SOCKET_TYPE_ENUM_INVALID	(2)


/****************************  STRUCTURE ********************************/
typedef struct
{
	unsigned			ulSize;
	unsigned char		abyBuffer[cTRANSAPI_TCP_LOOPBACK_MSG_SIZE_MAX+1];

} tTRANSAPI_TCP_SOCKET_LOOPBACK_MSG;

typedef struct
{
	tTRANSAPI_CTX					TransCtx;	/* MUST be first */
	tTRANSAPI_TCP_SOCKET_TYPE_ENUM	ulType;

	unsigned int					fUseSelect;
	unsigned int					fAccepted;

} tTRANSAPI_TCP_CTX;


extern char l_achBroadcastAddr[];

/****************************  STATIC FUNCTION ********************************/
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpInitCtx( tTRANSAPI_TCP_CTX *f_pTcpCtx, tOCT_UINT32 f_ulSocketSize, tOCT_UINT32 f_ulMaxRemoteCount);
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpSelect( tOCTTRANSAPI_HANDLE	f_hTransport );
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpClose( tTRANSAPI_CTX *	f_pTcpCtx );
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpSend( tTRANSAPI_CTX *	f_pTransCtx, void *	f_pBuffer,	unsigned int		f_ulBufferLength );
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpDestinationRecv( tOCTTRANSAPI_HANDLE	f_hTransport, tTRANSAPI_DESTINATION_RECV * f_pDestRecv  );
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpDestinationAdd( tTRANSAPI_CTX	*f_pTransCtx, tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_ADD_PARMS * f_pTransDestAdd );
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpDestinationSend( tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_SEND_PARMS *f_pParms );
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpPostSelect( tOCTTRANSAPI_HANDLE	f_hTransport );
extern tOCTTRANSAPI_RC_ERROR	TransApiTcpPreSelect( tOCTTRANSAPI_HANDLE	f_hTransport );


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __TRANSAPI_TCP_H__*/


