/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_destination.c

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

#include "../include/transapi.h"

/*--------------------------------------------------------------------------
	OctTransApiDestinationAdd
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationAdd(
								 tOCTTRANSAPI_HANDLE	f_hTransport,
								 tOCTTRANSAPI_DESTINATION_ADD_PARMS * f_pParms )
{
	tTRANSAPI_CTX	*					pTransCtx;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;
	unsigned int i;
	int iRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pParms )  )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	iRc = TransApiInstanceUsed(pTransInst);
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
		return iRc;

	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	
	if( iRc !=  cOCTTRANSAPI_RC_ERROR_NONE )
	{
		TransApiInstanceUnused( pTransInst );
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	for( i=0; i<pTransCtx->ulMaxDestination ;i++ )
	{
		if( pTransCtx->apDestinationCtx[i].hTransport == NULL )
		{
			iRc = pTransCtx->pfnDestinationAdd( pTransCtx, &pTransCtx->apDestinationCtx[i], f_pParms );
			if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
			{
				pTransCtx->apDestinationCtx[i].hTransport = f_hTransport;
				f_pParms->hDestination = (tOCTTRANSAPI_DESTINATION_HANDLE)&pTransCtx->apDestinationCtx[i];
			}
			break;
		}
	}
	if( i== pTransCtx->ulMaxDestination )
		iRc = cOCTTRANSAPI_RC_ERROR_NOMORE_DESTINATION;

	TransApiInstanceUnused( pTransInst );

	return iRc;

}

/*--------------------------------------------------------------------------
	OctTransApiDestinationRemove
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationRemove(
								 tOCTTRANSAPI_DESTINATION_HANDLE  f_hDestination )
{
	tTRANSAPI_DESTINATION_CTX * pDestinationCtx;
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDestination ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)f_hDestination;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDestinationCtx->ulMagicId != cTRANSAPI_MAGIC_DESTINATION_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/* Test if this remote is assigned */
	if( pDestinationCtx->hTransport == NULL )
		iRc = cOCTTRANSAPI_RC_ERROR_DESTINATION_CTX; 
	else /* Remove the remote */		
		pDestinationCtx->hTransport = NULL;

	return iRc;
}

/*--------------------------------------------------------------------------
	OctTransApiDestinationInfo
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationInfo(
								 tOCTTRANSAPI_DESTINATION_HANDLE  f_hDestination,
								 tOCTTRANSAPI_DESTINATION_INFO_PARMS * f_pParms )
{
	tTRANSAPI_DESTINATION_CTX *			pDestinationCtx;
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDestination ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)f_hDestination;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDestinationCtx->ulMagicId != cTRANSAPI_MAGIC_DESTINATION_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)pDestinationCtx->hTransport;
	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

	f_pParms->hTransport = pDestinationCtx->hTransport;
	strncpy( f_pParms->szDestinationAddr, pDestinationCtx->szDestinationAddr, sizeof(f_pParms->szDestinationAddr) );
	f_pParms->szDestinationAddr[sizeof(f_pParms->szDestinationAddr)-1] = 0;
	f_pParms->pDestinationAddr = pDestinationCtx->pDestinationAddr;
	f_pParms->ulDestinationAddrSize = pDestinationCtx->ulDestinationAddrSize;
	f_pParms->fIsBroadcast = pDestinationCtx->fIsBroadcast;
	f_pParms->ulPktHdrType = pTransInst->pTransApiCtx->ulPktHdrType;

    mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

	return iRc;
}
/*--------------------------------------------------------------------------
	OctTransApiDestinationPayloadHeaderInfo
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationPayloadHeaderInfo(
								 tOCTTRANSAPI_DESTINATION_HANDLE  f_hDestination,
								 tOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS * f_pParms )
{
	tTRANSAPI_DESTINATION_CTX *			pDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)f_hDestination;
	tTRANSAPI_TRANSPORT_INSTANCE *		pTransInst;
	tTRANSAPI_CTX *						pTransCtx;
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDestination ) ||
		( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDestinationCtx->ulMagicId != cTRANSAPI_MAGIC_DESTINATION_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)pDestinationCtx->hTransport;

	/* Test if this remote is assigned */
	if( pTransInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_DESTINATION_CTX;

	mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;
		
	f_pParms->ulHeaderLength = pTransCtx->ulPayloadHeaderLength;
	if( f_pParms->ulHeaderLength )
		memcpy( f_pParms->achHeader, pDestinationCtx->achPayloadHeader, f_pParms->ulHeaderLength );

    mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

	return iRc;
}
/*--------------------------------------------------------------------------
	OctTransApiDestinationSend
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDestinationSend(
								 tOCTTRANSAPI_DESTINATION_HANDLE  f_hDestination,
								 tOCTTRANSAPI_DESTINATION_SEND_PARMS * f_pParms )
{
	tTRANSAPI_DESTINATION_CTX * pDestinationCtx;
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE	*	pTransInst;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDestination ) ||
		( NULL == f_pParms ) ||
		( NULL == f_pParms->pBuffer ) ||
		( 0 == f_pParms->ulBufferLength ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)f_hDestination;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDestinationCtx->ulMagicId != cTRANSAPI_MAGIC_DESTINATION_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)pDestinationCtx->hTransport;
	iRc = TransApiInstanceUsed(pTransInst);
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
		return iRc;

	iRc = pDestinationCtx->pfnDestinationSend( f_hDestination, f_pParms );

	TransApiInstanceUnused(pTransInst);
	return iRc;
}

