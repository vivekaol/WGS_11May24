#if defined( _WIN32 ) || defined( _WIN64 ) || defined( WIN32 ) || defined( WIN64 )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_select.c

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
#include "../../../include/transapi.h"

#include <winsock2.h>


#ifdef OCTTRANSAPI_OPT_SELECT

/*--------------------------------------------------------------------------
	OctTransApiSelect
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiSelect( tOCTTRANSAPI_SELECT_PARMS * f_pParms )
{
	int				iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	
	tTRANSAPI_TRANSPORT_INSTANCE*		pTransInst;

	unsigned int		ulIndex;
	tTRANSAPI_TRANSPORT_INSTANCE*	aTransInst[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
	HANDLE							aHandles[cOCTTRANSAPI_SELECT_HANDLE_COUNT_MAX];
	DWORD							dwRc;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( f_pParms == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	memset( aHandles, 0x0, sizeof(aHandles) );
	memset( aTransInst, 0x0, sizeof(aTransInst) );

	f_pParms->ulSelectedCnt = 0;

	for ( ulIndex=0; ulIndex<f_pParms->ulTransportCnt;ulIndex++ )
	{
		pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_pParms->ahTransport[ulIndex];
		if( NULL == pTransInst )
			return cOCTTRANSAPI_RC_ERROR_PARAM;

		mTRANSAPI_MUTEX_SEIZE( pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
		if( ( pTransInst->pTransApiCtx == NULL ) )
			iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
		else if( pTransInst->pTransApiCtx->ulMagicId != cTRANSAPI_MAGIC_ID  )
			iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

		if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
		{
			OctOsalMutexRelease( pTransInst->hMutex );
			return iRc;
		}

		/* May not have pre-select */
		if( pTransInst->pTransApiCtx->pfnPreSelect )
		{
			iRc = pTransInst->pTransApiCtx->pfnPreSelect( f_pParms->ahTransport[ulIndex] );
			if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
			{
				OctOsalMutexRelease( pTransInst->hMutex );
				return iRc;
			}
		}

		/* Store event handle */
		aHandles[ulIndex] = pTransInst->pTransApiCtx->hSelectable;
		aTransInst[ulIndex] = pTransInst;

		OctOsalMutexRelease( pTransInst->hMutex );
	}

	/* Wait for something to happen */
	dwRc = WaitForMultipleObjects(
					f_pParms->ulTransportCnt,
					aHandles,
					FALSE,
					(cOCTTRANSAPI_TIMEOUT_FOREVER == f_pParms->ulTimeoutMs)
						?INFINITE
						:f_pParms->ulTimeoutMs);

	if ( WAIT_TIMEOUT == dwRc )
	{
		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
	else if ( WAIT_OBJECT_0 <= dwRc && WAIT_OBJECT_0 + f_pParms->ulTransportCnt > dwRc )
	{
		ulIndex = dwRc - WSA_WAIT_EVENT_0;

		iRc = cOCTTRANSAPI_RC_ERROR_NONE;
		f_pParms->ahTransSelected[f_pParms->ulSelectedCnt] = f_pParms->ahTransport[ulIndex];
		if( aTransInst[ulIndex]->pTransApiCtx->pfnPostSelect )
			iRc = aTransInst[ulIndex]->pTransApiCtx->pfnPostSelect( f_pParms->ahTransport[ulIndex] );

		if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
			f_pParms->ulSelectedCnt++;

		
	}
	else if ( WAIT_ABANDONED_0 <= dwRc && WAIT_ABANDONED_0 + f_pParms->ulTransportCnt > dwRc )
	{
		/* Probably a close handle or socket */
		iRc = cOCTTRANSAPI_RC_ERROR_SELECT_ABANDON;
	}
	else
	{
		iRc = cOCTTRANSAPI_RC_ERROR_TRANSPORT;
	}

	return iRc;
}


#endif /* OCTTRANSAPI_OPT_SELECT */

#endif /* WIN32 */
