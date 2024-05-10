/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_close.c

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
#include "../include/transapi.h"

/*--------------------------------------------------------------------------
	OctTransApiClose
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiClose( tOCTTRANSAPI_HANDLE  f_hTransport )
{

	int									iRc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_TRANSPORT_INSTANCE*		pTransInst;
	tTRANSAPI_CTX *						pTransCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;

	/* Wait Unused and lock the instance */
	iRc = TransApiInstanceWaitUnused( pTransInst );
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
		return iRc;

	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		iRc = cOCTTRANSAPI_RC_ERROR_PARAM;
	
	if( iRc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
		return iRc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( pTransCtx->pfnClose != NULL )
		iRc = pTransCtx->pfnClose( pTransCtx );

	if( iRc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
		pTransInst->pTransApiCtx = NULL;
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );
		TransApiInstanceRelease( pTransInst );
	}
	else
        mTRANSAPI_MUTEX_RELEASE( pTransInst->hMutex );

	return iRc;
}
