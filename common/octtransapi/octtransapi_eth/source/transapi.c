/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
#include <stdio.h>
#include <string.h>

/* Porting interface */
#include "../include/transapi_eth.h"
#include "../../octtransapi/include/transapi.h"


/*********************************  MACROS ************************************/
/*******************************  STRUCTURE ***********************************/

char l_achBroadcastAddr[] = {0xff,0xff,0xff,0xff,0xff,0xff };

/****************************  STATIC FUNCTION ********************************/


/*--------------------------------------------------------------------------
	TransApiEthDestinationRecv
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiEthDestinationRecv( tOCTTRANSAPI_HANDLE	f_hTransport, tTRANSAPI_DESTINATION_RECV * f_pDestRecv  )
{
	int									iRc;
	tTRANSAPI_CTX	*					pTransCtx;
	tTRANSAPI_TRANSPORT_INSTANCE*		pTransInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pDestRecv ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

	/* NO need to lock */
	iRc = OctTransApiEthRecv( f_hTransport, 
						f_pDestRecv->pRecvParms->ulTimeoutMs,
						(char *)f_pDestRecv->pRecvParms->pBuffer+pTransCtx->ulHeaderBufferPadding, 
						f_pDestRecv->pRecvParms->ulMaxBufferLength-pTransCtx->ulHeaderBufferPadding );
	if( iRc < 0 )
		return iRc;
	if( iRc == 0 )
	{
		f_pDestRecv->ulRecvLength = 0;
		f_pDestRecv->ulDestinationAddrLength = 0;
	}
	else
	{
		tOCTDEV_MAC_ADDRESS MacAddr;

		/* Return adjust the length with the padding */
		f_pDestRecv->ulRecvLength =  (tOCT_UINT32)iRc;

		/* Return the remote address */
		f_pDestRecv->ulDestinationAddrLength = sizeof (tOCTDEV_MAC_ADDRESS);

		MacAddr.abyReserved[0]=0;
		MacAddr.abyReserved[1]=0;

		/* Take the source address */
		memcpy( MacAddr.abyMacAddress, ((char *)f_pDestRecv->pRecvParms->pBuffer)+pTransCtx->ulHeaderBufferPadding+cTRANSAPI_ETH_MAC_ADDR_SIZE, cTRANSAPI_ETH_MAC_ADDR_SIZE );
		memcpy( f_pDestRecv->achDestinationAddr, &MacAddr, sizeof (tOCTDEV_MAC_ADDRESS) );

		/* Find if should copy only on broadcast */
		if( f_pDestRecv->pRecvParms->pszDestinationAddr && 
			( f_pDestRecv->pRecvParms->ulMaxDestinationAddrLength > 18 ) )
		{
			sprintf( f_pDestRecv->pRecvParms->pszDestinationAddr, "%02X:%02X:%02X:%02X:%02X:%02X",
				MacAddr.abyMacAddress[0],
				MacAddr.abyMacAddress[1],
				MacAddr.abyMacAddress[2],
				MacAddr.abyMacAddress[3],
				MacAddr.abyMacAddress[4],
				MacAddr.abyMacAddress[5] );
		}		
	}

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	TransApiEthDestinationAdd
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiEthDestinationAdd( tTRANSAPI_CTX	*f_pTransCtx,
											  tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination,
											  tOCTTRANSAPI_DESTINATION_ADD_PARMS * f_pAddParms )
{
	tTRANSAPI_DESTINATION_CTX * pDestinationCtx;
	tTRANSAPI_ETH_CTX *pEthCtx = (tTRANSAPI_ETH_CTX *)f_pTransCtx;
	tOCTDEV_MAC_ADDRESS MacAddr;
	tOCTDEV_MAC_ADDRESS *pMacAddr;
	char *pchData;

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
		if(f_pAddParms->ulDestinationAddrSize != sizeof (tOCTDEV_MAC_ADDRESS) )
			return cOCTTRANSAPI_RC_ERROR_DESTINATION_ADDR;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

		memcpy( pDestinationCtx->pDestinationAddr, f_pAddParms->pDestinationAddr, sizeof(tOCTDEV_MAC_ADDRESS) );
		/* Make sure reserve is null */
		((tOCTDEV_MAC_ADDRESS*)pDestinationCtx->pDestinationAddr)->abyReserved[0]=0;
		((tOCTDEV_MAC_ADDRESS*)pDestinationCtx->pDestinationAddr)->abyReserved[1]=0;
		pDestinationCtx->szDestinationAddr[0] = 0;

	}
	else if( f_pAddParms->szDestinationAddr[0] == 0 )	/* See if need broadcast */
	{
		MacAddr.abyReserved[0]=0;
		MacAddr.abyReserved[1]=0;
		memcpy( MacAddr.abyMacAddress, l_achBroadcastAddr, sizeof(l_achBroadcastAddr) );
		memcpy( pDestinationCtx->pDestinationAddr, &MacAddr, sizeof(tOCTDEV_MAC_ADDRESS) );
	}
	else
	{
		tOCT_UINT32 ulVal5,ulVal4,ulVal3,ulVal2,ulVal1,ulVal0;

		if(( sscanf( f_pAddParms->szDestinationAddr, "%02X:%02X:%02X:%02X:%02X:%02X",
					&ulVal5,&ulVal4,&ulVal3,&ulVal2,&ulVal1,&ulVal0 ) != 6 ) &&
		   ( sscanf( f_pAddParms->szDestinationAddr, "%02X-%02X-%02X-%02X-%02X-%02X",
					&ulVal5,&ulVal4,&ulVal3,&ulVal2,&ulVal1,&ulVal0 ) != 6 ) )
		{
			return cOCTTRANSAPI_RC_ERROR_DESTINATION_ADDR;
		}
		MacAddr.abyReserved[0]=0;
		MacAddr.abyReserved[1]=0;
		MacAddr.abyMacAddress[0]=(tOCT_UINT8)ulVal5;
		MacAddr.abyMacAddress[1]=(tOCT_UINT8)ulVal4;
		MacAddr.abyMacAddress[2]=(tOCT_UINT8)ulVal3;
		MacAddr.abyMacAddress[3]=(tOCT_UINT8)ulVal2;
		MacAddr.abyMacAddress[4]=(tOCT_UINT8)ulVal1;
		MacAddr.abyMacAddress[5]=(tOCT_UINT8)ulVal0;
		memcpy( pDestinationCtx->pDestinationAddr, &MacAddr, sizeof(tOCTDEV_MAC_ADDRESS) );
	}
	
	pDestinationCtx->ulDestinationAddrSize = sizeof(tOCTDEV_MAC_ADDRESS);

	pDestinationCtx->fIsBroadcast = cOCT_FALSE;
	if( memcmp( ((tOCTDEV_MAC_ADDRESS*)pDestinationCtx->pDestinationAddr)->abyMacAddress, l_achBroadcastAddr, sizeof(l_achBroadcastAddr) ) == 0 )
		pDestinationCtx->fIsBroadcast = cOCT_TRUE;

	/* Find string representation */
	if( pDestinationCtx->szDestinationAddr[0] == 0 )
	{
		pMacAddr = (tOCTDEV_MAC_ADDRESS*)pDestinationCtx->pDestinationAddr;

		sprintf( pDestinationCtx->szDestinationAddr, "%02X:%02X:%02X:%02X:%02X:%02X",
			pMacAddr->abyMacAddress[0],
			pMacAddr->abyMacAddress[1],
			pMacAddr->abyMacAddress[2],
			pMacAddr->abyMacAddress[3],
			pMacAddr->abyMacAddress[4],
			pMacAddr->abyMacAddress[5] );
	}

	/* Set payload Header ..  */
	pchData = &pDestinationCtx->achPayloadHeader[0];

	/* Set Destination MAC */
	pMacAddr = (tOCTDEV_MAC_ADDRESS*)pDestinationCtx->pDestinationAddr;
	memcpy( &pchData[0], pMacAddr->abyMacAddress, cTRANSAPI_ETH_MAC_ADDR_SIZE );

	/* Set Source MAC */

	memcpy( &pchData[cTRANSAPI_ETH_MAC_ADDR_SIZE], pEthCtx->SrcMacAddr.abyMacAddress, cTRANSAPI_ETH_MAC_ADDR_SIZE );

	/* EtherType */
	pchData[12] = (pEthCtx->usEtherType>>8)& 0xFF;
	pchData[13] = (pEthCtx->usEtherType)& 0xFF;

	return cOCTTRANSAPI_RC_ERROR_NONE;
}


/*--------------------------------------------------------------------------
	TransApiEthDestinationSend
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiEthDestinationSend( tOCTTRANSAPI_DESTINATION_HANDLE f_hDestination, tOCTTRANSAPI_DESTINATION_SEND_PARMS *f_pParms )
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

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	/* Test if remote header is present */
	if( memcmp( f_pParms->pBuffer, pDestinationCtx->achPayloadHeader, cTRANSAPI_ETH_II_HEADER_SIZE ) != 0 )
		return cOCTTRANSAPI_RC_ERROR_DESTINATION_HEADER;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	/* No need to use instance ... already done */
	iRc  =	TransApiEthSend( pTransInst->pTransApiCtx, 
					(char *)f_pParms->pBuffer,
					f_pParms->ulBufferLength );

	if( iRc > 0 )
	{
		f_pParms->ulSentLength = iRc;
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}		

	return iRc;
	
}
/*--------------------------------------------------------------------------
	_TransApiEthInitCtx
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR TransApiEthInitCtx( tTRANSAPI_ETH_CTX *f_pEthCtx, tOCT_UINT32 f_ulSocketSize, tOCT_UINT32 f_ulMaxDestination)
{
	tTRANSAPI_CTX *pTransCtx;

	pTransCtx = &f_pEthCtx->TransCtx;

	/* Just allow minimum test */
	pTransCtx->ulMagicId		= cTRANSAPI_MAGIC_ID;	
	pTransCtx->ulTransportType	= cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_ETH;

	if( f_ulSocketSize == 0 )
		return cOCTTRANSAPI_RC_ERROR_NONE;

	pTransCtx->pfnClose			= TransApiEthClose;
#ifdef OCTTRANSAPI_OPT_SELECT
	pTransCtx->pfnPreSelect		= TransApiEthPreSelect;
	pTransCtx->pfnPostSelect	= NULL;
#endif /* OCTTRANSAPI_OPT_SELECT */
	pTransCtx->pfnDestinationRecv	= TransApiEthDestinationRecv;
	pTransCtx->pfnDestinationAdd	= TransApiEthDestinationAdd;
	pTransCtx->ulMaxDestination		= f_ulMaxDestination;

	// HDRXL contain a padding on the wire
	if( mIS_TRANSAPI_ETH_OCTPKT_HDRXL_ETHERTYPE(f_pEthCtx->usEtherType )  )
	{
		pTransCtx->ulHeaderBufferPadding = 0;
		pTransCtx->ulPayloadHeaderLength = cTRANSAPI_ETH_PAYLOAD_ALIGNMENT_PADDING + cTRANSAPI_ETH_II_HEADER_SIZE;
		pTransCtx->ulPktHdrType			 = cOCTPKT_HDR_TYPE_ENUM_XL;
	}
	else if( mIS_TRANSAPI_ETH_OCTPKT_HDR_ETHERTYPE(f_pEthCtx->usEtherType )  )
	{
		// HDR add a virtual padding in the recv buffer to allign the payload
		pTransCtx->ulHeaderBufferPadding = cTRANSAPI_ETH_PAYLOAD_ALIGNMENT_PADDING;
		pTransCtx->ulPayloadHeaderLength = cTRANSAPI_ETH_II_HEADER_SIZE;
		pTransCtx->ulPktHdrType			 = cOCTPKT_HDR_TYPE_ENUM_NORMAL;
	}
	else
	{
		// Do not aligned
		pTransCtx->ulHeaderBufferPadding = 0;
		pTransCtx->ulPayloadHeaderLength = cTRANSAPI_ETH_II_HEADER_SIZE;
		pTransCtx->ulPktHdrType			 = cOCTPKT_HDR_TYPE_ENUM_NONE;
	}


	if( f_ulMaxDestination )
	{
		tTRANSAPI_DESTINATION_CTX *pDestinationCtx;
		tOCTDEV_MAC_ADDRESS *pMacAddress;
		unsigned int i;

		pTransCtx->apDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)((char *)f_pEthCtx + f_ulSocketSize);

		/* Locate remote address after all tTRANSAPI_DESTINATION_CTX */
		pMacAddress = (tOCTDEV_MAC_ADDRESS *)((char *)(pTransCtx->apDestinationCtx) + (f_ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX)));

		for( i=0; i<pTransCtx->ulMaxDestination ;i++ )
		{
			pDestinationCtx = &pTransCtx->apDestinationCtx[i];
			memset( pDestinationCtx, 0, sizeof( tTRANSAPI_DESTINATION_CTX ) );

			pDestinationCtx->ulMagicId = cTRANSAPI_MAGIC_DESTINATION_ID;
			pDestinationCtx->hTransport = NULL;
			pDestinationCtx->pDestinationAddr = (void *)pMacAddress;
			pDestinationCtx->pfnDestinationSend = TransApiEthDestinationSend;
			memset( pDestinationCtx->pDestinationAddr, 0, sizeof(tOCTDEV_MAC_ADDRESS));

			pMacAddress++;
		}
	}
	
	return cOCTTRANSAPI_RC_ERROR_NONE;
}
