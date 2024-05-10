/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi.c

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.16.00-B304 (2018/05/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
#include <stdio.h>
#include <string.h>

/* Porting interface */
#include "../include/transapi_tcp.h"
#include "../include/octtransapi_tcp.h"
#include "../../octtransapi/include/transapi.h"

#include "../../../../sls/inc/octdev_macro.h"

/*********************************  MACROS ************************************/

/* TCP is a stream-oriented protocol, but transapi is datagram-oriented. The
   TCP transport thus works with the following assumptions:
   - All buffers being exchanged are actually datagrams
   - Datagram size is located in the first dword of the datagram
   - Data gram size occupies the 10 least significant bits */
#define cDATAGRAM_LENGTH_MASK	(0x7ff)

/*******************************  STRUCTURE ***********************************/

/****************************  STATIC FUNCTION ********************************/


/*--------------------------------------------------------------------------
	TransApiTcpDestinationRecv
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiTcpDestinationRecv( tOCTTRANSAPI_HANDLE	f_hTransport, tTRANSAPI_DESTINATION_RECV * f_pDestRecv  )
{
	int iRc;
	unsigned ulPacketLength;
	unsigned ulDroppedPacketBytes = 0;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;
	tTRANSAPI_TCP_CTX *pTcpCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pDestRecv ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTcpCtx = (tTRANSAPI_TCP_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( NULL == pTcpCtx )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	/* first, get the header so we know what is the length of the datagram */
	iRc = OctTransApiTcpRecv( f_hTransport, 
						f_pDestRecv->pRecvParms->ulTimeoutMs,
						(char *)f_pDestRecv->pRecvParms->pBuffer, 
						sizeof(tOCT_UINT32) );
	if( iRc < 0 )
		return iRc;

	f_pDestRecv->ulRecvLength = iRc;

	ulPacketLength = mOCT_SWAP32_IF_LE(*(tOCT_UINT32*)f_pDestRecv->pRecvParms->pBuffer) & cDATAGRAM_LENGTH_MASK;
	
	if(ulPacketLength > f_pDestRecv->pRecvParms->ulMaxBufferLength)
	{
		ulDroppedPacketBytes = ulPacketLength - f_pDestRecv->pRecvParms->ulMaxBufferLength;
		ulPacketLength = f_pDestRecv->pRecvParms->ulMaxBufferLength;
	}

	/* Get the datagram's payload */
	/* NO need to lock */
	do
	{
		iRc = OctTransApiTcpRecv( f_hTransport, 
							f_pDestRecv->pRecvParms->ulTimeoutMs,
							(char *)f_pDestRecv->pRecvParms->pBuffer + f_pDestRecv->ulRecvLength, 
							ulPacketLength - f_pDestRecv->ulRecvLength );
		if( iRc < 0 )
			return iRc;

		f_pDestRecv->ulRecvLength += iRc;
	} while ( ulPacketLength != f_pDestRecv->ulRecvLength );

	/* Consume any extra data so that we do not loose sync */
	while( ulDroppedPacketBytes > 0 )
	{
		unsigned aulUnused[32];
		iRc = OctTransApiTcpRecv( f_hTransport, 
							f_pDestRecv->pRecvParms->ulTimeoutMs,
							(char *)aulUnused, 
							sizeof(aulUnused) );
		if( iRc < 0 )
			return iRc;

		ulDroppedPacketBytes -= iRc;
	}

	/* TCP can only have a single destination (a connected socket), so we
	 * directly get the info from destination 0 */
	f_pDestRecv->ulDestinationAddrLength = pTcpCtx->TransCtx.apDestinationCtx[0].ulDestinationAddrSize;
	memcpy( f_pDestRecv->achDestinationAddr,
			pTcpCtx->TransCtx.apDestinationCtx[0].pDestinationAddr,
			pTcpCtx->TransCtx.apDestinationCtx[0].ulDestinationAddrSize );

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	TransApiTcpDestinationAdd
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiTcpDestinationAdd( tTRANSAPI_CTX	*f_pTransCtx,
											  tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination,
											  tOCTTRANSAPI_DESTINATION_ADD_PARMS * f_pAddParms )
{
	tOCTTRANSAPI_RC_ERROR	Result = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_DESTINATION_CTX * pDestinationCtx;
	tOCTDEV_TCP_ADDRESS TcpAddr = {{0}};

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pTransCtx ) ||
		( NULL == f_hDestination ) ||
		( NULL == f_pAddParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */
	

	pDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)f_hDestination;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDestinationCtx->ulMagicId != cTRANSAPI_MAGIC_DESTINATION_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( f_pAddParms->pDestinationAddr )
	{
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
		if(f_pAddParms->ulDestinationAddrSize != sizeof (tOCTDEV_TCP_ADDRESS) )
			return cOCTTRANSAPI_RC_ERROR_DESTINATION_ADDR;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

		memcpy( pDestinationCtx->pDestinationAddr, f_pAddParms->pDestinationAddr, sizeof(tOCTDEV_TCP_ADDRESS) );
		pDestinationCtx->szDestinationAddr[0] = 0;
	}
	else if( f_pAddParms->szDestinationAddr[0] == 0 )	/* See if need broadcast */
	{
		// TODO OctTransApiTcpGetBroadcastAddress( pDestinationCtx->hTransport, &TcpAddr.IpAddress );
		memcpy( pDestinationCtx->pDestinationAddr, &TcpAddr, sizeof(tOCTDEV_TCP_ADDRESS) );
	}
	else
	{
		tOCT_UINT32 ulVal4,ulVal3,ulVal2,ulVal1,ulVal0;

		if(( sscanf( f_pAddParms->szDestinationAddr, "%u.%u.%u.%u:0x%x",
					&ulVal4,&ulVal3,&ulVal2,&ulVal1,&ulVal0 ) != 5 ) &&
			( sscanf( f_pAddParms->szDestinationAddr, "%u.%u.%u.%u:%u",
					&ulVal4,&ulVal3,&ulVal2,&ulVal1,&ulVal0 ) != 5 ) )
		{
			return cOCTTRANSAPI_RC_ERROR_DESTINATION_ADDR;
		}
		TcpAddr.IpAddress.aulIpAddress[0] = ((ulVal4 & 0xff) << 24) |
											((ulVal3 & 0xff) << 16) |
											((ulVal2 & 0xff) <<  8) |
											((ulVal1 & 0xff) <<  0) ;
		TcpAddr.IpAddress.ulIpVersion = cOCTTRANSAPI_IP_VERSION_ENUM_4;
		TcpAddr.ulTcpPort = ulVal0;
		memcpy( pDestinationCtx->pDestinationAddr, &TcpAddr, sizeof(tOCTDEV_TCP_ADDRESS) );
	}

	if( 0 )
	{
		/* TODO1: Adding a destination, when the address is a broadcast, actually means
				  opening a new UDP socket */
	}
	else
	{
		/* Adding a destination, when the address is not a broadcast, actually means
		          connecting to a remote host */
		Result = OctTransApiTcpConnect( f_pTransCtx->hTransport,  (tOCTDEV_TCP_ADDRESS*)pDestinationCtx->pDestinationAddr );
	}


	pDestinationCtx->ulDestinationAddrSize = sizeof(tOCTDEV_TCP_ADDRESS);

	/* Find string representation */
	if( pDestinationCtx->szDestinationAddr[0] == 0 )
	{
		tOCTDEV_TCP_ADDRESS *pTcpAddr = (tOCTDEV_TCP_ADDRESS*)pDestinationCtx->pDestinationAddr;

		sprintf( pDestinationCtx->szDestinationAddr, "%u.%u.%u.%u:%u",
			(pTcpAddr->IpAddress.aulIpAddress[0] >> 24) & 0xff,
			(pTcpAddr->IpAddress.aulIpAddress[0] >> 16) & 0xff,
			(pTcpAddr->IpAddress.aulIpAddress[0] >>  8) & 0xff,
			(pTcpAddr->IpAddress.aulIpAddress[0] >>  0) & 0xff,
			(pTcpAddr->ulTcpPort));
	}

	return Result;
}


/*--------------------------------------------------------------------------
	TransApiTcpDestinationSend
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiTcpDestinationSend( tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_SEND_PARMS *f_pParms )
{
	tTRANSAPI_DESTINATION_CTX * pDestinationCtx;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;
	tOCT_INT32 iRc;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDestination ) ||
		( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)f_hDestination;
	mOCTOSAL_ASSERT( pDestinationCtx->ulMagicId == cTRANSAPI_MAGIC_DESTINATION_ID );

	/* DO NOT LOCK .. Already done by OctTransApiDestinationSend */
	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)pDestinationCtx->hTransport;

	/* No need to use instance ... already done */
	iRc = OctTransApiTcpSend( pTransInst,
								f_pParms->pBuffer,
								f_pParms->ulBufferLength );

	if( iRc > 0 )
	{
		f_pParms->ulSentLength = iRc;
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}		

	return iRc;
	
}

/*--------------------------------------------------------------------------
TransApiTcpClose
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiTcpClose( tTRANSAPI_CTX * f_pTransCtx )
{
	tTRANSAPI_TCP_CTX *pTcpCtx = (tTRANSAPI_TCP_CTX *)f_pTransCtx;
	unsigned int i;

	if( ( f_pTransCtx->ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_TCP ) )
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

	/* Find if any used destination */
	for( i=0; i<f_pTransCtx->ulMaxDestination; i++ )
	{
		if( f_pTransCtx->apDestinationCtx[i].hTransport )
			return cOCTTRANSAPI_RC_ERROR_BUSY_DESTINATION;
	}

	return OctTransApiTcpClose( pTcpCtx->TransCtx.hTransport );
}

#ifdef OCTTRANSAPI_OPT_SELECT
/*--------------------------------------------------------------------------
TransApiTcpSelect
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiTcpSelect( tOCTTRANSAPI_HANDLE	f_hTransport )
{
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)f_hTransport;

	/* NO need to lock */
	tTRANSAPI_TCP_CTX *		pTcpCtx = (tTRANSAPI_TCP_CTX*)pTransInst->pTransApiCtx;

	/* test if should use select */
	if( !pTcpCtx->fUseSelect )
		return cOCTTRANSAPI_RC_ERROR_OPEN_WITHOUT_SELECT;

	return cOCTTRANSAPI_RC_ERROR_NONE;
}
#endif /* OCTTRANSAPI_OPT_SELECT */


/*--------------------------------------------------------------------------
	_TransApiTcpInitCtx
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR TransApiTcpInitCtx( tTRANSAPI_TCP_CTX *f_pTcpCtx, tOCT_UINT32 f_ulSocketSize, tOCT_UINT32 f_ulMaxDestination)
{
	tTRANSAPI_CTX *pTransCtx;

	memset( f_pTcpCtx, 0, sizeof( tTRANSAPI_TCP_CTX ) );

	pTransCtx = &f_pTcpCtx->TransCtx;

	/* Just allow minimum test */
	pTransCtx->ulMagicId		= cTRANSAPI_MAGIC_ID;	
	pTransCtx->ulTransportType	= cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_TCP;

	if( f_ulSocketSize == 0 )
		return cOCTTRANSAPI_RC_ERROR_NONE;

	pTransCtx->pfnClose				= TransApiTcpClose;
	pTransCtx->pfnDestinationRecv	= TransApiTcpDestinationRecv;
	pTransCtx->pfnDestinationAdd	= TransApiTcpDestinationAdd;
	pTransCtx->ulMaxDestination		= f_ulMaxDestination;
	pTransCtx->ulPayloadHeaderLength = 0;
	pTransCtx->ulPktHdrType			 = cOCTPKT_HDR_TYPE_ENUM_NORMAL;


	if( f_ulMaxDestination )
	{
		tTRANSAPI_DESTINATION_CTX *pDestinationCtx;
		tOCTDEV_TCP_ADDRESS *pTcpAddress;
		unsigned int i;

		pTransCtx->apDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)((char *)f_pTcpCtx + f_ulSocketSize);

		/* Locate remote address after all tTRANSAPI_DESTINATION_CTX */
		pTcpAddress = (tOCTDEV_TCP_ADDRESS *)((char *)(pTransCtx->apDestinationCtx) + (f_ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX)));

		for( i=0; i<pTransCtx->ulMaxDestination ;i++ )
		{
			pDestinationCtx = &pTransCtx->apDestinationCtx[i];
			memset( pDestinationCtx, 0, sizeof( tTRANSAPI_DESTINATION_CTX ) );

			pDestinationCtx->ulMagicId = cTRANSAPI_MAGIC_DESTINATION_ID;
			pDestinationCtx->hTransport = NULL;
			pDestinationCtx->pDestinationAddr = (void *)pTcpAddress;
			pDestinationCtx->pfnDestinationSend = TransApiTcpDestinationSend;
			memset( pDestinationCtx->pDestinationAddr, 0, sizeof(tOCTDEV_TCP_ADDRESS));

			pTcpAddress++;
		}
	}
	
	return cOCTTRANSAPI_RC_ERROR_NONE;
}
