/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_init.c

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
#include <stdlib.h>
#include <memory.h>
#include "../include/transapi.h"

#ifdef OCT_ENV_TYPE_WINDOWS
#ifdef OCT_ENV_MODE_DEBUG
#pragma comment( lib, "octosald.lib" )
#else
#pragma comment( lib, "octosal.lib" )
#endif /* OCT_ENV_MODE_DEBUG */
#endif /* OCT_ENV_TYPE_WINDOWS */

tTRANSAPI_INST *				g_pTransApiInst=NULL;
static tOCT_BOOL32				g_fInitTermBusy = cOCT_FALSE;
tTRANSAPI_TRANSPORT_INSTANCE	g_aTransApiTransportInstance[cTRANSAPI_TRANSPORT_INSTANCE_MAX];

/*--------------------------------------------------------------------------
	OctTransApiInit
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR OctTransApiIsInit( void )
{
	tOCTTRANSAPI_RC_ERROR Rc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	/*  Protect init and terminate requests */
	if ( g_fInitTermBusy == cOCT_TRUE )
	{
		return( cOCTTRANSAPI_RC_ERROR_ALREADY_INIT );
	}
	if( g_pTransApiInst != NULL )
		Rc = cOCTTRANSAPI_RC_ERROR_ALREADY_INIT;

	return Rc;
}
/*--------------------------------------------------------------------------
	OctTransApiInit
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiInit( tOCTTRANSAPI_INIT_PARMS * f_pParms )
{
	tOCTTRANSAPI_RC_ERROR Rc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/*  Protect init and terminate requests */
	if ( g_fInitTermBusy == cOCT_TRUE )
	{
		return( cOCTTRANSAPI_RC_ERROR_ALREADY_INIT );
	}
	if( g_pTransApiInst != NULL )
		Rc = cOCTTRANSAPI_RC_ERROR_ALREADY_INIT;
	else
		g_fInitTermBusy = cOCT_TRUE;

	if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
		int i;
		g_pTransApiInst = (tTRANSAPI_INST*)malloc( sizeof(tTRANSAPI_INST) );
		memset( g_pTransApiInst, 0, sizeof(tTRANSAPI_INST) );
#ifdef OCTOSAL_OPT_MULTI_THREAD
		OctOsalMutexOpen( &g_pTransApiInst->hMutex );
#endif
		mTRANSAPI_MUTEX_SEIZE( g_pTransApiInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

        for( i=0; i<cTRANSAPI_TRANSPORT_INSTANCE_MAX; i++)
		{
#ifdef OCTOSAL_OPT_MULTI_THREAD
			OctOsalMutexOpen( &g_aTransApiTransportInstance[i].hMutex );
#endif

			g_aTransApiTransportInstance[i].ulMagicId = cTRANSAPI_MAGIC_ID;
			g_aTransApiTransportInstance[i].fUsed = cOCT_FALSE;
			g_aTransApiTransportInstance[i].pTransApiCtx = NULL;
			g_aTransApiTransportInstance[i].ulIndex = i;
		}

		TransApiDispatcherInit();

		mTRANSAPI_MUTEX_RELEASE( g_pTransApiInst->hMutex );

		g_fInitTermBusy = cOCT_FALSE;
	}
	return Rc;

}

/*--------------------------------------------------------------------------
	OctTransApiTerminate
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR OctTransApiTerminate( tOCTTRANSAPI_TERMINATE_PARMS * f_pParms )
{
	tOCTTRANSAPI_RC_ERROR Rc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/*  Protect init and terminate requests */
	if ( g_fInitTermBusy == cOCT_TRUE )
	{
		return( cOCTTRANSAPI_RC_ERROR_NOT_INIT );
	}

	if( g_pTransApiInst == NULL )
		Rc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else
		g_fInitTermBusy = cOCT_TRUE;

	if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
#ifdef OCTOSAL_OPT_MULTI_THREAD
		OctOsalMutexSeize( g_pTransApiInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER );
#endif

		Rc = TransApiDispatcherTerminate();

		if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
		{
			int i;
#ifdef OCTOSAL_OPT_MULTI_THREAD
			tOCTOSAL_HANDLE_MUTEX hMutex;
			hMutex = g_pTransApiInst->hMutex;
#endif

			/* Close all transport */
            for( i=0; i<cTRANSAPI_TRANSPORT_INSTANCE_MAX; i++)
			{
				if( g_aTransApiTransportInstance[i].fUsed )
					OctTransApiClose( &g_aTransApiTransportInstance[i] );

				g_aTransApiTransportInstance[i].ulMagicId = 0;
				mTRANSAPI_MUTEX_CLOSE( g_aTransApiTransportInstance[i].hMutex );
			}

			free( g_pTransApiInst );
			g_pTransApiInst = NULL;

			mTRANSAPI_MUTEX_RELEASE( hMutex );
			mTRANSAPI_MUTEX_CLOSE( hMutex );
		}
		else
			mTRANSAPI_MUTEX_RELEASE( g_pTransApiInst->hMutex );
		
        g_fInitTermBusy = cOCT_FALSE;
	}
	return Rc;
}
/*--------------------------------------------------------------------------
	TransApiInstanceSeize
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiInstanceSeize( tTRANSAPI_TRANSPORT_INSTANCE ** f_ppTransInst )
{
	int i;


	mTRANSAPI_MUTEX_SEIZE( g_pTransApiInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

    for( i=0; i<cTRANSAPI_TRANSPORT_INSTANCE_MAX; i++)
	{
		if( g_aTransApiTransportInstance[i].fUsed == cOCT_FALSE )
		{
			g_aTransApiTransportInstance[i].pTransApiCtx = NULL;
			g_aTransApiTransportInstance[i].fUsed = cOCT_TRUE;
			g_aTransApiTransportInstance[i].ulUseCnt = 0;
			*f_ppTransInst = &g_aTransApiTransportInstance[i];
			break;
		}
	}
	mTRANSAPI_MUTEX_RELEASE( g_pTransApiInst->hMutex );

    return (i==cTRANSAPI_TRANSPORT_INSTANCE_MAX) ? cOCTTRANSAPI_RC_ERROR_NOMORE_INSTANCE : cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	TransApiInstanceUsed
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiInstanceUsed( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst )
{
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_NONE;

	/* Must check all time ... when from destination */
	if(  f_pTransInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( f_pTransInst->ulMagicId != cTRANSAPI_MAGIC_ID )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    mTRANSAPI_MUTEX_SEIZE( f_pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; );

	if( ( f_pTransInst->pTransApiCtx == NULL ) || !f_pTransInst->fUsed )
		iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else
		f_pTransInst->ulUseCnt++;
	mTRANSAPI_MUTEX_RELEASE( f_pTransInst->hMutex );

	return iRc;
}
/*--------------------------------------------------------------------------
	TransApiInstanceUnused
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiInstanceUnused( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst )
{
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_NONE;

	if( f_pTransInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_PARAM;

    mTRANSAPI_MUTEX_SEIZE( f_pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; );
	if( ( f_pTransInst->pTransApiCtx == NULL ) || !f_pTransInst->fUsed )
		iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else if( f_pTransInst->ulUseCnt )
		f_pTransInst->ulUseCnt--;
	mTRANSAPI_MUTEX_RELEASE( f_pTransInst->hMutex );

	return iRc;
}

/*--------------------------------------------------------------------------
	TransApiInstanceWaitUnused
		Wait until used count back to 0.

		Instance is lock on return 
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiInstanceWaitUnused( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst )
{
	tOCT_INT32 iRc = cOCTTRANSAPI_RC_ERROR_BUSY_INSTANCE;

	while( iRc == cOCTTRANSAPI_RC_ERROR_BUSY_INSTANCE )
	{
		mTRANSAPI_MUTEX_SEIZE( f_pTransInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; );

		if(( f_pTransInst->pTransApiCtx == NULL ) || !f_pTransInst->fUsed )
			iRc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
		else if( f_pTransInst->ulUseCnt == 0 )
		{
			return cOCTTRANSAPI_RC_ERROR_NONE;

		}

		mTRANSAPI_MUTEX_RELEASE( f_pTransInst->hMutex );

		if( iRc == cOCTTRANSAPI_RC_ERROR_BUSY_INSTANCE )
			OctOsalSleepMs(10);
	}

	return iRc;
}


/*--------------------------------------------------------------------------
	TransApiInstanceRelease
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiInstanceRelease( tTRANSAPI_TRANSPORT_INSTANCE * f_pTransInst )
{
	int i;
	mTRANSAPI_MUTEX_SEIZE( g_pTransApiInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

    for( i=0; i<cTRANSAPI_TRANSPORT_INSTANCE_MAX; i++)
	{
		if( &g_aTransApiTransportInstance[i] == f_pTransInst )
		{
			g_aTransApiTransportInstance[i].fUsed = cOCT_FALSE;
            break;
		}
	}
	mTRANSAPI_MUTEX_RELEASE( g_pTransApiInst->hMutex );
	
    return (i==cTRANSAPI_TRANSPORT_INSTANCE_MAX) ? cOCTTRANSAPI_RC_ERROR_PARAM : cOCTTRANSAPI_RC_ERROR_NONE;
}


/*--------------------------------------------------------------------------
	OctTransApiGetLastError
----------------------------------------------------------------------------*/
tOCT_INT32	OctTransApiGetLastError( tOCTTRANSAPI_HANDLE 		f_hTransport,
									tOCTTRANSAPI_GET_LAST_ERROR_PARMS * f_pParms )
{
	tTRANSAPI_CTX	*pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParms )||
		( NULL == f_hTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( g_pTransApiInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	pTransApiCtx = (tTRANSAPI_CTX*)f_hTransport;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( cTRANSAPI_MAGIC_ID == pTransApiCtx->ulMagicId ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	f_pParms->ulLastError = pTransApiCtx->ulLastError;
	if( f_pParms->fClear )
		pTransApiCtx->ulLastError = 0;

	return cOCTTRANSAPI_RC_ERROR_NONE;
}


/*--------------------------------------------------------------------------
	TransApiCalcElapsedTimeMs
		Calculate elapsed time between start time and current
----------------------------------------------------------------------------*/
tOCT_UINT32 TransApiCalcElapsedTimeMs(
	tOCT_UINT32		f_ulCurrentTimeMs,
	tOCT_UINT32		f_ulStartTimeMs )
{
	tOCT_UINT32		ulElapsedMs;

	if ( f_ulCurrentTimeMs >= f_ulStartTimeMs )
	{
		ulElapsedMs = (unsigned int)(f_ulCurrentTimeMs - f_ulStartTimeMs);
	}
	else
	{
		ulElapsedMs = 0xFFFFFFFF - f_ulStartTimeMs;
		ulElapsedMs += (unsigned int)f_ulCurrentTimeMs;
	}
	return ulElapsedMs;
}
