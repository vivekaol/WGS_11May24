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
#include "../include/transapi_udp.h"
#include "../include/octtransapi_udp.h"
#include "../../octtransapi/include/transapi.h"


/*********************************  MACROS ************************************/
/*******************************  STRUCTURE ***********************************/

/****************************  STATIC FUNCTION ********************************/


/*--------------------------------------------------------------------------
	TransApiUdpDestinationRecv
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiUdpDestinationRecv( tOCTTRANSAPI_HANDLE	f_hTransport, tTRANSAPI_DESTINATION_RECV * f_pDestRecv  )
{
	int iRc;
	tOCTTRANSAPI_UDP_ADDRESS	RemoteUdpAddress;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pDestRecv ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	/* NO need to lock */
	iRc = OctTransApiUdpRecvFrom(	f_hTransport,
									&RemoteUdpAddress,
									f_pDestRecv->pRecvParms->ulTimeoutMs,
									(char *)f_pDestRecv->pRecvParms->pBuffer, 
									f_pDestRecv->pRecvParms->ulMaxBufferLength );


	if( iRc < 0 )
		return iRc;
	if( iRc == 0 )
	{
		f_pDestRecv->ulRecvLength = 0;
		f_pDestRecv->ulDestinationAddrLength = 0;
	}
	else
	{
		f_pDestRecv->ulRecvLength =  (tOCT_UINT32)iRc;

		/* Return the remote address */
		f_pDestRecv->ulDestinationAddrLength = sizeof (RemoteUdpAddress);

		/* Take the source address */
		memcpy( f_pDestRecv->achDestinationAddr, &RemoteUdpAddress, sizeof (RemoteUdpAddress) );

		/* Find if should copy only on broadcast */
		if( f_pDestRecv->pRecvParms->pszDestinationAddr && 
			( f_pDestRecv->pRecvParms->ulMaxDestinationAddrLength > 18 ) )
		{
			sprintf( f_pDestRecv->pRecvParms->pszDestinationAddr, "%u.%u.%u.%u:%u",
				(RemoteUdpAddress.IpAddress.aulIpAddress[0] >> 24) & 0xff,
				(RemoteUdpAddress.IpAddress.aulIpAddress[0] >> 16) & 0xff,
				(RemoteUdpAddress.IpAddress.aulIpAddress[0] >>  8) & 0xff,
				(RemoteUdpAddress.IpAddress.aulIpAddress[0] >>  0) & 0xff,
				RemoteUdpAddress.ulUdpPort );
		}		
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	TransApiUdpDestinationAdd
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiUdpDestinationAdd( tTRANSAPI_CTX	*f_pTransCtx,
											  tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination,
											  tOCTTRANSAPI_DESTINATION_ADD_PARMS * f_pAddParms )
{
	tTRANSAPI_DESTINATION_CTX * pDestinationCtx;
	tOCTDEV_UDP_ADDRESS BroadcastAddr;
	tOCTDEV_UDP_ADDRESS *pUdpAddr;

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

	OctTransApiUdpGetBroadcastAddress( f_pTransCtx->hTransport, &BroadcastAddr );

	pUdpAddr = (tOCTDEV_UDP_ADDRESS*)pDestinationCtx->pDestinationAddr;

	pUdpAddr->IpAddress.ulIpVersion = cOCTDEV_IP_VERSION_ENUM_4;

	if( f_pAddParms->pDestinationAddr )
	{
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
		if(f_pAddParms->ulDestinationAddrSize != sizeof (tOCTDEV_UDP_ADDRESS) )
			return cOCTTRANSAPI_RC_ERROR_DESTINATION_ADDR;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */
		/* only use first uint32 */
		pUdpAddr->IpAddress.aulIpAddress[0] = ((tOCTDEV_UDP_ADDRESS*)f_pAddParms->pDestinationAddr)->IpAddress.aulIpAddress[0];
		pUdpAddr->ulUdpPort = ((tOCTDEV_UDP_ADDRESS*)f_pAddParms->pDestinationAddr)->ulUdpPort;
		
		pDestinationCtx->szDestinationAddr[0] = 0;

	}
	else if( f_pAddParms->szDestinationAddr[0] == 0 )	/* See if need broadcast */
	{
		pUdpAddr->IpAddress.aulIpAddress[0] = BroadcastAddr.IpAddress.aulIpAddress[0];
		pUdpAddr->ulUdpPort = BroadcastAddr.ulUdpPort;
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
		pUdpAddr->IpAddress.aulIpAddress[0] = ((ulVal4 & 0xff) << 24) |
											((ulVal3 & 0xff) << 16) |
											((ulVal2 & 0xff) <<  8) |
											((ulVal1 & 0xff) <<  0) ;

		pUdpAddr->ulUdpPort = ulVal0;
	}
	
	pDestinationCtx->ulDestinationAddrSize = sizeof(tOCTDEV_UDP_ADDRESS);

	/* Find string representation */
	if( pDestinationCtx->szDestinationAddr[0] == 0 )
	{

		sprintf( pDestinationCtx->szDestinationAddr, "%u.%u.%u.%u:%u",
			(pUdpAddr->IpAddress.aulIpAddress[0] >> 24) & 0xff,
			(pUdpAddr->IpAddress.aulIpAddress[0] >> 16) & 0xff,
			(pUdpAddr->IpAddress.aulIpAddress[0] >>  8) & 0xff,
			(pUdpAddr->IpAddress.aulIpAddress[0] >>  0) & 0xff,
			 pUdpAddr->ulUdpPort);
	}

	pDestinationCtx->fIsBroadcast = pUdpAddr->IpAddress.aulIpAddress[0] ==	BroadcastAddr.IpAddress.aulIpAddress[0];

	return cOCTTRANSAPI_RC_ERROR_NONE;
}


/*--------------------------------------------------------------------------
	TransApiUdpDestinationSend
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiUdpDestinationSend( tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_SEND_PARMS *f_pParms )
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
	iRc = OctTransApiUdpSendTo( pTransInst,
								(tOCTDEV_UDP_ADDRESS*)pDestinationCtx->pDestinationAddr,
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
TransApiUdpClose
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiUdpClose( tTRANSAPI_CTX * f_pTransCtx )
{
	tTRANSAPI_UDP_CTX *pUdpCtx = (tTRANSAPI_UDP_CTX *)f_pTransCtx;
	unsigned int i;

	if( ( f_pTransCtx->ulTransportType != cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_UDP ) )
		return cOCTTRANSAPI_RC_ERROR_TRANSPORT_TYPE;

	/* Find if any used destination */
	for( i=0; i<f_pTransCtx->ulMaxDestination; i++ )
	{
		if( f_pTransCtx->apDestinationCtx[i].hTransport )
			return cOCTTRANSAPI_RC_ERROR_BUSY_DESTINATION;
	}

	return OctTransApiUdpClose( pUdpCtx->TransCtx.hTransport );
}




/*--------------------------------------------------------------------------
	_TransApiUdpInitCtx
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR TransApiUdpInitCtx( tTRANSAPI_UDP_CTX *f_pUdpCtx, tOCT_UINT32 f_ulSocketSize, tOCT_UINT32 f_ulMaxDestination)
{
	tTRANSAPI_CTX *pTransCtx;

	memset( f_pUdpCtx, 0, sizeof( tTRANSAPI_UDP_CTX ) );

	pTransCtx = &f_pUdpCtx->TransCtx;

	/* Just allow minimum test */
	pTransCtx->ulMagicId		= cTRANSAPI_MAGIC_ID;	
	pTransCtx->ulTransportType	= cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_UDP;

	if( f_ulSocketSize == 0 )
		return cOCTTRANSAPI_RC_ERROR_NONE;

	pTransCtx->pfnClose			= TransApiUdpClose;

#ifdef OCTTRANSAPI_OPT_SELECT
	pTransCtx->pfnPreSelect		= NULL;
	pTransCtx->pfnPostSelect	= NULL;
#endif /* OCTTRANSAPI_OPT_SELECT */

	pTransCtx->pfnDestinationRecv	= TransApiUdpDestinationRecv;
	pTransCtx->pfnDestinationAdd	= TransApiUdpDestinationAdd;
	pTransCtx->ulMaxDestination		= f_ulMaxDestination;
	pTransCtx->ulPayloadHeaderLength = 0;
	pTransCtx->ulPktHdrType			 = cOCTPKT_HDR_TYPE_ENUM_NORMAL;


	if( f_ulMaxDestination )
	{
		tTRANSAPI_DESTINATION_CTX *pDestinationCtx;
		tOCTDEV_UDP_ADDRESS *pUdpAddress;
		unsigned int i;

		pTransCtx->apDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)((char *)f_pUdpCtx + f_ulSocketSize);

		/* Locate remote address after all tTRANSAPI_DESTINATION_CTX */
		pUdpAddress = (tOCTDEV_UDP_ADDRESS *)((char *)(pTransCtx->apDestinationCtx) + (f_ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX)));

		for( i=0; i<pTransCtx->ulMaxDestination ;i++ )
		{
			pDestinationCtx = &pTransCtx->apDestinationCtx[i];
			memset( pDestinationCtx, 0, sizeof( tTRANSAPI_DESTINATION_CTX ) );

			pDestinationCtx->ulMagicId = cTRANSAPI_MAGIC_DESTINATION_ID;
			pDestinationCtx->hTransport = NULL;
			pDestinationCtx->pDestinationAddr = (void *)pUdpAddress;
			pDestinationCtx->pfnDestinationSend = TransApiUdpDestinationSend;
			memset( pDestinationCtx->pDestinationAddr, 0, sizeof(tOCTDEV_UDP_ADDRESS));

			pUdpAddress++;
		}
	}
	
	return cOCTTRANSAPI_RC_ERROR_NONE;
}
