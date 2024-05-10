/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_local_ctx.c

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
#include <memory.h>
#include "../include/transapi_local.h"

/*--------------------------------------------------------------------------
	TransApiLocalDestinationRecv
----------------------------------------------------------------------------*/
tOCT_INT32	TransApiLocalDestinationRecv( tOCTTRANSAPI_HANDLE	f_hTransport, tTRANSAPI_DESTINATION_RECV * f_pDestRecv  )
{
	int iRc;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pDestRecv ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	/* NO need to lock */
	iRc = OctTransApiLocalRecv( f_hTransport, 
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
		/* Return adjust the length with the padding */
		f_pDestRecv->ulRecvLength =  (tOCT_UINT32)iRc;

		/* Return the remote address */
		f_pDestRecv->ulDestinationAddrLength = 0;
	}
	return cOCTTRANSAPI_RC_ERROR_NONE;
}


/*--------------------------------------------------------------------------
	TransApiLocalInitCtx
----------------------------------------------------------------------------*/
tOCT_INT32 TransApiLocalInitCtx( tTRANSAPI_LOCAL_CTX *f_pLocalCtx )
{
	tTRANSAPI_CTX *pTransCtx;

	memset( f_pLocalCtx, 0, sizeof( tTRANSAPI_LOCAL_CTX ) );

	pTransCtx = &f_pLocalCtx->TransCtx;

	/* Just allow minimum test */
	pTransCtx->ulMagicId		= cTRANSAPI_MAGIC_ID;	
	pTransCtx->ulTransportType	= cOCTTRANSAPI_TRANSPORT_TYPE_ENUM_LOCAL;

	pTransCtx->pfnClose			= TransApiLocalClose;
#ifdef OCTTRANSAPI_OPT_SELECT
	pTransCtx->pfnPreSelect		= NULL;
	pTransCtx->pfnPostSelect	= NULL;
#endif /* OCTTRANSAPI_OPT_SELECT */
	pTransCtx->pfnDestinationRecv	= TransApiLocalDestinationRecv;
	pTransCtx->pfnDestinationAdd	= NULL;
	pTransCtx->ulMaxDestination		= 1;
	pTransCtx->ulPayloadHeaderLength = 0;

	//if( f_ulMaxDestination )
	//{
	//	tTRANSAPI_DESTINATION_CTX *pDestinationCtx;
	//	tOCTDEV_MAC_ADDRESS *pMacAddress;
	//	unsigned int i;

	//	pTransCtx->apDestinationCtx = (tTRANSAPI_DESTINATION_CTX *)((char *)f_pEthCtx + f_ulSocketSize);

	//	/* Locate remote address after all tTRANSAPI_DESTINATION_CTX */
	//	pMacAddress = (tOCTDEV_MAC_ADDRESS *)((char *)(pTransCtx->apDestinationCtx) + (f_ulMaxDestination * sizeof(tTRANSAPI_DESTINATION_CTX)));

	//	for( i=0; i<pTransCtx->ulMaxDestination ;i++ )
	//	{
	//		pDestinationCtx = &pTransCtx->apDestinationCtx[i];
	//		memset( pDestinationCtx, 0, sizeof( tTRANSAPI_DESTINATION_CTX ) );

	//		pDestinationCtx->ulMagicId = cTRANSAPI_MAGIC_DESTINATION_ID;
	//		OctOsalMutexOpen( &pDestinationCtx->hMutex );

	//		pDestinationCtx->hTransport = NULL;
	//		pDestinationCtx->pDestinationAddr = (void *)pMacAddress;
	//		pDestinationCtx->pfnDestinationSend = TransApiEthDestinationSend;
	//		memset( pDestinationCtx->pDestinationAddr, 0, sizeof(tOCTDEV_MAC_ADDRESS));

	//		pMacAddress++;
	//	}
	//}
	
	return cOCTTRANSAPI_RC_ERROR_NONE;
}
