/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_recv.c

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
	OctTransApiRecv
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiRecv(
								 tOCTTRANSAPI_HANDLE		f_hTransport,
								 tOCTTRANSAPI_RECV_PARMS * f_pParms )
{
	tTRANSAPI_CTX	*					pTransCtx;
	tTRANSAPI_TRANSPORT_INSTANCE*		pTransInst;
	tTRANSAPI_DESTINATION_RECV DestRecv;
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) ||
		( NULL == f_pParms ) ||
		( NULL == f_pParms->pBuffer ) ||
		( 0 == f_pParms->ulMaxBufferLength ) ||
		( f_pParms->pszDestinationAddr && ( 0 == f_pParms->ulMaxDestinationAddrLength) ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	iRc = TransApiInstanceUsed(pTransInst);
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
		return iRc;

	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) || ( 0 == pTransCtx->ulMaxDestination) )
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		TransApiInstanceUnused(pTransInst);
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	DestRecv.pRecvParms = f_pParms;

	iRc = pTransCtx->pfnDestinationRecv( f_hTransport, &DestRecv );
	if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
		f_pParms->hDestination = NULL;

		if( DestRecv.ulRecvLength == 0 )
		{
			f_pParms->ulPayloadLength = 0;
			f_pParms->hDestination = NULL;
		}
		else
		{
			f_pParms->pPayload  = f_pParms->pBuffer + pTransCtx->ulPayloadHeaderLength + pTransCtx->ulHeaderBufferPadding;
			f_pParms->ulPayloadLength = DestRecv.ulRecvLength - pTransCtx->ulPayloadHeaderLength;

			if( DestRecv.ulDestinationAddrLength )
			{
				unsigned int i;

				/* Find remote */
				for( i=0; i<pTransCtx->ulMaxDestination; i++ )
				{
					if( pTransCtx->apDestinationCtx[i].hTransport )
					{
						if( pTransCtx->apDestinationCtx[i].fIsBroadcast ||
							( memcmp( pTransCtx->apDestinationCtx[i].pDestinationAddr, DestRecv.achDestinationAddr, 
								DestRecv.ulDestinationAddrLength ) == 0 ) )
						{
							f_pParms->hDestination =(void *)&pTransCtx->apDestinationCtx[i];
							break;
						}
					}
				}
			}			
		}
	}

	TransApiInstanceUnused(pTransInst);
	return iRc;
	
}
