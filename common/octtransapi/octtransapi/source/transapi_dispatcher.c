/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: transapi_dispatcher.c

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
#include "../../include/octtransapi.h"
#include "../../include/octtransapi_local_default.h"
#include "../../include/octtransapi_default.h"
#include "../include/transapi.h"


typedef struct
{
	tOCT_UINT32							ulMagicId;
	tOCTTRANSAPI_DISPATCHER_STATE_ENUM	ulState;			
	tOCTTRANSAPI_HANDLE					ahTransport[cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX];
#ifdef OCTOSAL_OPT_MULTI_THREAD
	tOCTOSAL_HANDLE_MUTEX				hMutex;
#endif
	tOCTTRANSAPI_HANDLE					hTransLocal;
	tOCT_UINT32							ulRxBufferSize;
	tOCT_UINT8 *						pabyRxBuffer;
	tOCT_UINT32							ulElapseInactivityMs;	
	tPFNTRANSAPI_DISPATCH_INACTIVITY	pfnDispatchInactivity;
	void *								pDispatchInactivityAppContext;			

}tTRANSAPI_DISPACTH_CTX;


typedef struct
{
	tOCT_UINT32					ulDispCtxCnt;
#ifdef OCTOSAL_OPT_MULTI_THREAD
    tOCTOSAL_HANDLE_MUTEX				hMutex;
#endif
	tTRANSAPI_DISPACTH_CTX *	pDispCtx;

}tTRANSAPI_DISPACTH_INST;

static tTRANSAPI_DISPACTH_INST * l_pDispInst=NULL;

/*--------------------------------------------------------------------------
	TransApiDispatcherInit
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiDispatcherInit( void  )
{

#ifndef OCTOSAL_OPT_MULTI_THREAD
    return cOCTTRANSAPI_RC_ERROR_REQUIRES_MULTI_THREAD;

#else /*OCTOSAL_OPT_MULTI_THREAD*/
	tTRANSAPI_DISPACTH_CTX *	pDispCtx;
	tOCTTRANSAPI_RC_ERROR		Rc=cOCTTRANSAPI_RC_ERROR_NONE;

	mOCTOSAL_ASSERT(  l_pDispInst == NULL );
	l_pDispInst	= (tTRANSAPI_DISPACTH_INST *)malloc( sizeof(tTRANSAPI_DISPACTH_INST) + ( cOCTTRANSAPI_DISPATCHER_COUNT * sizeof(tTRANSAPI_DISPACTH_CTX) ) );
	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_MEMORY_ALLOC;

	OctOsalMutexOpen( &l_pDispInst->hMutex );
	mTRANSAPI_MUTEX_SEIZE( l_pDispInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

	l_pDispInst->ulDispCtxCnt = cOCTTRANSAPI_DISPATCHER_COUNT;
	if( l_pDispInst->ulDispCtxCnt )
	{
		unsigned int i;
		tOCTTRANSAPI_LOCAL_OPEN_PARMS LocalOpen;

		mOCTTRANSAPI_LOCAL_OPEN_PARMS_DEF( &LocalOpen );
		l_pDispInst->pDispCtx = (tTRANSAPI_DISPACTH_CTX*)((char *)l_pDispInst+sizeof(tTRANSAPI_DISPACTH_INST));

		pDispCtx = l_pDispInst->pDispCtx;
		for( i=0; i<l_pDispInst->ulDispCtxCnt; i++ )
		{
			memset( pDispCtx, 0, sizeof(tTRANSAPI_DISPACTH_CTX) );
			pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_NONE;

			OctOsalMutexOpen( &pDispCtx->hMutex );
			OctTransApiLocalOpen( &LocalOpen, &pDispCtx->hTransLocal );

			mOCTOSAL_ASSERT( pDispCtx->hMutex != NULL );
			mOCTOSAL_ASSERT( pDispCtx->hTransLocal != NULL );
			pDispCtx->ulMagicId = cTRANSAPI_MAGIC_ID;

			pDispCtx++;
		}
	}
	else
		l_pDispInst->pDispCtx = NULL;



	OctOsalMutexRelease( l_pDispInst->hMutex );

	return Rc;

#endif /*OCTOSAL_OPT_MULTI_THREAD*/
}

/*--------------------------------------------------------------------------
	TransApiDispatcherClose
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR TransApiDispatcherClose( tTRANSAPI_DISPACTH_CTX *	f_pDispCtx )
{
	int j;
	tOCTTRANSAPI_RC_ERROR Rc = cOCTTRANSAPI_RC_ERROR_NONE;

	/* Signal to stop */
	if( f_pDispCtx->ulState > cOCTTRANSAPI_DISPATCHER_STATE_ENUM_MUST_WAIT2CLOSE )
	{
		char abyBuffer[] = {"END"};

        mTRANSAPI_MUTEX_SEIZE( f_pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
		{
			f_pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_STOPPING;
            mTRANSAPI_MUTEX_RELEASE( f_pDispCtx->hMutex );

			Rc = OctTransApiLocalSend( f_pDispCtx->hTransLocal, (void *)abyBuffer, sizeof(abyBuffer) );
			if( Rc > 0 )
			{
				tOCT_UINT32 ulTimeStart = OctOsalGetTimeMs();
	
				while( f_pDispCtx->ulState > cOCTTRANSAPI_DISPATCHER_STATE_ENUM_MUST_WAIT2CLOSE )
				{
					OctOsalSleepMs(10);
					/* Allow 5sec to terminate */
					if( TransApiCalcElapsedTimeMs( OctOsalGetTimeMs(), ulTimeStart ) > 5000 )
						break;
				}
				Rc = cOCTTRANSAPI_RC_ERROR_NONE;
			}
		}

	}

	if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
        mTRANSAPI_MUTEX_SEIZE( f_pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
		{
			for( j=0; j<cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX; j++ )
			{
				f_pDispCtx->ahTransport[j] = tOCTTRANSAPI_HANDLE_INVALID;
			}

			f_pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_NONE;
			if( f_pDispCtx->pabyRxBuffer )
				free((void *)f_pDispCtx->pabyRxBuffer);
			f_pDispCtx->pabyRxBuffer = NULL;
			
            mTRANSAPI_MUTEX_RELEASE( f_pDispCtx->hMutex );
		}

	}

	return Rc;
}
/*--------------------------------------------------------------------------
	TransApiDispatcherTerminate
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	TransApiDispatcherTerminate( void )
{	
	tOCTTRANSAPI_RC_ERROR Rc = cOCTTRANSAPI_RC_ERROR_NONE;

	if(l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	mTRANSAPI_MUTEX_SEIZE( l_pDispInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

	if( l_pDispInst->ulDispCtxCnt )
	{
		unsigned int i;
		tTRANSAPI_DISPACTH_CTX *	pDispCtx = l_pDispInst->pDispCtx;

		/* Release all dispacther resource */
		for( i=0; (i<l_pDispInst->ulDispCtxCnt)&& ( Rc == cOCTTRANSAPI_RC_ERROR_NONE ); i++ )
		{
			if( pDispCtx->ulState != cOCTTRANSAPI_DISPATCHER_STATE_ENUM_NONE )
				Rc = TransApiDispatcherClose( pDispCtx );

			if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
			{
                mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )
				{
					if( ( Rc = OctTransApiLocalClose( pDispCtx->hTransLocal ))  == cOCTOSAL_RC_OK )
					{
                        mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );
                        mTRANSAPI_MUTEX_CLOSE(  pDispCtx->hMutex );
						pDispCtx++;
					}
				}				
			}
		}
	}
	if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
        mTRANSAPI_MUTEX_RELEASE(  l_pDispInst->hMutex );
        mTRANSAPI_MUTEX_CLOSE(  l_pDispInst->hMutex );

		free( l_pDispInst );
		l_pDispInst = NULL;

	}

	return Rc;
}

/*--------------------------------------------------------------------------
	OctTransApiDispatcherOpen
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherOpen( tOCTTRANSAPI_DISPATCHER_OPEN_PARMS * f_pParms )
{
	tOCTTRANSAPI_RC_ERROR Rc = cOCTTRANSAPI_RC_ERROR_NOMORE_DISPATCH;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_pParms ) || ( !f_pParms->ulRxBufferSize ) ||
		( ( 0 == f_pParms->ulElapseInactivityMs ) && ( NULL != f_pParms->pfnDispatchInactivity ) ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#ifndef OCTOSAL_OPT_MULTI_THREAD
    return cOCTTRANSAPI_RC_ERROR_REQUIRES_MULTI_THREAD;
#endif /*OCTOSAL_OPT_MULTI_THREAD*/

	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	f_pParms->hDispatcher = tOCTTRANSAPI_HANDLE_INVALID;

	mTRANSAPI_MUTEX_SEIZE( l_pDispInst->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING; )

	if( l_pDispInst->ulDispCtxCnt )
	{
		unsigned int i;
		tTRANSAPI_DISPACTH_CTX *	pDispCtx = l_pDispInst->pDispCtx;

		for( i=0; i<l_pDispInst->ulDispCtxCnt; i++ )
		{            
			if( pDispCtx->ulState == cOCTTRANSAPI_DISPATCHER_STATE_ENUM_NONE )
			{
                mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, ; )

				if( pDispCtx->ulState == cOCTTRANSAPI_DISPATCHER_STATE_ENUM_NONE )
				{
					pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_USED;
					f_pParms->hDispatcher = (void *)pDispCtx;

					pDispCtx->ulElapseInactivityMs	= f_pParms->ulElapseInactivityMs;
					pDispCtx->pDispatchInactivityAppContext = f_pParms->pInactivityAppContext;
					pDispCtx->pfnDispatchInactivity = f_pParms->pfnDispatchInactivity;
					pDispCtx->ulRxBufferSize = f_pParms->ulRxBufferSize;
					pDispCtx->pabyRxBuffer = (tOCT_UINT8 *)malloc( pDispCtx->ulRxBufferSize );
					mOCTOSAL_ASSERT( pDispCtx->pabyRxBuffer != NULL );

					Rc = cOCTTRANSAPI_RC_ERROR_NONE;

				}
                mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );
				if( f_pParms->hDispatcher != tOCTTRANSAPI_HANDLE_INVALID )
					break;
			}
			pDispCtx++;
		}
	}
    mTRANSAPI_MUTEX_RELEASE( l_pDispInst->hMutex );

	return Rc;
}

/*--------------------------------------------------------------------------
	OctTransApiDispatcherClose
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR OctTransApiDispatcherClose( tOCTTRANSAPI_DISPATCHER_HANDLE	f_hDispatcher  )
{
	tOCTTRANSAPI_RC_ERROR Rc = cOCTTRANSAPI_RC_ERROR_NONE;
	tTRANSAPI_DISPACTH_CTX *	pDispCtx = (tTRANSAPI_DISPACTH_CTX *)f_hDispatcher;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDispatcher ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDispCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	Rc = TransApiDispatcherClose( pDispCtx );

	return Rc;
}

/*--------------------------------------------------------------------------
	OctTransApiDispatcherRun
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR OctTransApiDispatcherRun( tOCTTRANSAPI_DISPATCHER_HANDLE	f_hDispatcher,
									tOCTTRANSAPI_DISPATCHER_RUN_PARMS * f_pParms )
{
	tTRANSAPI_DISPACTH_CTX *	pDispCtx = (tTRANSAPI_DISPACTH_CTX *)f_hDispatcher;
	tOCTTRANSAPI_SELECT_PARMS	TransSelect;
	tOCTTRANSAPI_RC_ERROR		Rc = cOCTTRANSAPI_RC_ERROR_NONE;
	tOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS	DispInactivity;
	tOCT_UINT32	ulInactivityMs;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDispatcher ) ||
		( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDispCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING  );
	pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_ADDING;
    mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );

	mOCTTRANSAPI_SELECT_PARMS_DEF( &TransSelect );
	mOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS_DEF( &DispInactivity );

	if( pDispCtx->pfnDispatchInactivity )
	{
		DispInactivity.pInactivityAppContext = pDispCtx->pDispatchInactivityAppContext;
		DispInactivity.hDispatcher = f_hDispatcher;
	}

	ulInactivityMs = pDispCtx->ulElapseInactivityMs;

	while( pDispCtx->ulState > cOCTTRANSAPI_DISPATCHER_STATE_ENUM_KEEP_RUNNING )
	{
		unsigned int i;

		mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING  );

		if( ( pDispCtx->ulState == cOCTTRANSAPI_DISPATCHER_STATE_ENUM_ADDING ) ||
			( Rc == cOCTTRANSAPI_RC_ERROR_SELECT_ABANDON ) )
		{
			TransSelect.ulTransportCnt = 0;
			for( i=0; i<cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX; i++ )
			{
				if( pDispCtx->ahTransport[i] != tOCTTRANSAPI_HANDLE_INVALID )
				{
					TransSelect.ahTransport[TransSelect.ulTransportCnt++] = pDispCtx->ahTransport[i];
				}
			}
			/* Set local */
			TransSelect.ahTransport[TransSelect.ulTransportCnt++] = pDispCtx->hTransLocal;

			pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_RUNNING;
		}
		else if( pDispCtx->ulState ==  cOCTTRANSAPI_DISPATCHER_STATE_ENUM_MODIFY )
		{
			if( pDispCtx->pfnDispatchInactivity )
			{
				ulInactivityMs = pDispCtx->ulElapseInactivityMs;
				DispInactivity.pInactivityAppContext = pDispCtx->pDispatchInactivityAppContext;
				DispInactivity.hDispatcher = f_hDispatcher;
			}
			else
				TransSelect.ulTimeoutMs = cOCTTRANSAPI_TIMEOUT_FOREVER;

			pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_RUNNING;
		}

		if( pDispCtx->pfnDispatchInactivity )
			TransSelect.ulTimeoutMs = ulInactivityMs;

        mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );
		
#ifdef OCTTRANSAPI_OPT_SELECT
		Rc = OctTransApiSelect( &TransSelect );
		mOCTOSAL_ASSERT( Rc != cOCTTRANSAPI_RC_ERROR_TRANSPORT );
#else
		TransSelect.ulSelectedCnt = TransSelect.ulTransportCnt;
#endif

		for( i=0; i<TransSelect.ulSelectedCnt; i++ )
		{
			tOCTTRANSAPI_RECV_PARMS Recv;
			char	szDestinationAddr[cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE];

			mOCTTRANSAPI_RECV_PARMS_DEF( &Recv );
			Recv.ulTimeoutMs = 0;

			Recv.pBuffer = pDispCtx->pabyRxBuffer;
			Recv.ulMaxBufferLength = pDispCtx->ulRxBufferSize;
			Recv.pszDestinationAddr = szDestinationAddr;
			Recv.ulMaxDestinationAddrLength = sizeof( szDestinationAddr );

			Rc = OctTransApiRecv( TransSelect.ahTransSelected[i], &Recv );
			if( ( Rc == cOCTTRANSAPI_RC_ERROR_NONE ) &&	Recv.ulPayloadLength )
			{
				tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE*)TransSelect.ahTransSelected[i];
				tTRANSAPI_CTX	*pTransCtx = (tTRANSAPI_CTX *)TransSelect.ahTransSelected[i];

				/* TEst if local transport */
				if( pDispCtx->hTransLocal == TransSelect.ahTransSelected[i] )
				{
					continue;
				}
				else
				{
					Rc = TransApiInstanceUsed(pTransInst);
					
					if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
					{
						pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
						if( pTransCtx->ulMagicId == cTRANSAPI_MAGIC_ID )
						{
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */
							if( pTransCtx->pfnDispatchPayload )
							{
								Rc = pTransCtx->pfnDispatchPayload( pTransCtx->pAppDispatchCtx, &Recv );
							}
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
						}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

						TransApiInstanceUnused(pTransInst);
					}
				}
			}			
		}
		if( !TransSelect.ulSelectedCnt && pDispCtx->pfnDispatchInactivity )
		{
			Rc = pDispCtx->pfnDispatchInactivity( &DispInactivity );
			if( ( Rc == cOCTTRANSAPI_RC_ERROR_NONE ) &&
				( DispInactivity.ulElapseInactivityMs ) )
			{
				ulInactivityMs = DispInactivity.ulElapseInactivityMs;
			}
		}
	}
	mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING  );
	pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_STOPPED;
    mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );

	return cOCTTRANSAPI_RC_ERROR_NONE;
}

/*--------------------------------------------------------------------------
	OctTransApiDispatcherAddTransport
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherAddTransport(
							tOCTTRANSAPI_DISPATCHER_HANDLE					f_hDispatcher,
							tOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS *	f_pParms )
{
	tTRANSAPI_DISPACTH_CTX *		pDispCtx = (tTRANSAPI_DISPACTH_CTX *)f_hDispatcher;
	tTRANSAPI_TRANSPORT_INSTANCE *	pTransInst;
	tTRANSAPI_CTX	*				pTransCtx;
	tOCTTRANSAPI_RC_ERROR			Rc = cOCTTRANSAPI_RC_ERROR_NONE;
	int i;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDispatcher ) ||
		( NULL == f_pParms ) ||
		( NULL == f_pParms->hTransport ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDispCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	/* Test the transport */
	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_pParms->hTransport;
	Rc = TransApiInstanceUsed(pTransInst);
	if( Rc != cOCTTRANSAPI_RC_ERROR_NONE )
		return Rc;

	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) || ( 0 == pTransCtx->ulMaxDestination) )
		Rc = cOCTTRANSAPI_RC_ERROR_PARAM;
	if( pTransCtx->hDispatcher != NULL )
		Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_ASSIGNED;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( Rc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		TransApiInstanceUnused(pTransInst);
		return Rc;
	}

	mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING  );

	if( pDispCtx->ulState < cOCTTRANSAPI_DISPATCHER_STATE_ENUM_KEEP_RUNNING )
		Rc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	/* Find empty slot */
	for( i=0; i<cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX; i++ )
	{
		if( pDispCtx->ahTransport[i] == tOCTTRANSAPI_HANDLE_INVALID )
		{
			pDispCtx->ahTransport[i] = f_pParms->hTransport;
			if( f_pParms->pfnDispatchPayload )
			{
				pTransCtx->pfnDispatchPayload = f_pParms->pfnDispatchPayload;
				pTransCtx->pAppDispatchCtx = f_pParms->pAppContext;
			}
			pTransCtx->hDispatcher = f_hDispatcher;
			break;
		}
	}
	if( cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX == i )
		Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_FULL;
	else
	{
		pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_ADDING;
		Rc = OctTransApiLocalSend( pDispCtx->hTransLocal, (void *)"ADDING", 7 );
		if( Rc < 0 )
		{
			if( f_pParms->pfnDispatchPayload )
				pTransCtx->pfnDispatchPayload = NULL;
			pTransCtx->hDispatcher = NULL;
			pDispCtx->ahTransport[i] = NULL;
		}
		else
			Rc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
	TransApiInstanceUnused(pTransInst);
    mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );


	/* Wait for dispathThread to add new transport */
	if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
		tOCT_UINT32 iCnt=0;
		while( pDispCtx->ulState == cOCTTRANSAPI_DISPATCHER_STATE_ENUM_ADDING )
		{
			OctOsalSleepMs(10);
			iCnt++;
			if( iCnt == 10 )
			{
				Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_NO_RSP;
				break;
			}
		}
	}


	return Rc;
}

/*--------------------------------------------------------------------------
	OctTransApiDispatcherSetInactivity
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherSetInactivity(
							tOCTTRANSAPI_DISPATCHER_HANDLE					f_hDispatcher,
							tOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS *	f_pParms )
{
	tTRANSAPI_DISPACTH_CTX *		pDispCtx = (tTRANSAPI_DISPACTH_CTX *)f_hDispatcher;
	tOCTTRANSAPI_RC_ERROR			Rc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDispatcher ) ||
		( NULL == f_pParms ) ||
		(( 0 == f_pParms->ulElapseInactivityMs ) && ( NULL != f_pParms->pfnDispatchInactivity ) ))
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDispCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING  );

	if( pDispCtx->ulState < cOCTTRANSAPI_DISPATCHER_STATE_ENUM_KEEP_RUNNING )
		Rc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else
	{
		pDispCtx->pDispatchInactivityAppContext = f_pParms->pInactivityAppContext;
		pDispCtx->pfnDispatchInactivity = f_pParms->pfnDispatchInactivity;
		pDispCtx->ulElapseInactivityMs = f_pParms->ulElapseInactivityMs;

		pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_MODIFY;
		Rc = OctTransApiLocalSend( pDispCtx->hTransLocal, (void *)"MODIFY", 6 );
		if( Rc > 0 )
			Rc = cOCTTRANSAPI_RC_ERROR_NONE;
	}
    mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );

	/* Wait for dispathThread to add modify transport */
	if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
		tOCT_UINT32 iCnt=0;
		while( pDispCtx->ulState == cOCTTRANSAPI_DISPATCHER_STATE_ENUM_MODIFY )
		{
			OctOsalSleepMs(10);
			iCnt++;
			if( iCnt == 10 )
			{
				Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_NO_RSP;
				break;
			}
		}
	}



	return Rc;
}

/*--------------------------------------------------------------------------
	OctTransApiDispatcherGetStatus
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherGetStatus(
							tOCTTRANSAPI_DISPATCHER_HANDLE			f_hDispatcher,
							tOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS *	f_pParms )
{
	tTRANSAPI_DISPACTH_CTX *		pDispCtx = (tTRANSAPI_DISPACTH_CTX *)f_hDispatcher;
	tOCTTRANSAPI_RC_ERROR			Rc = cOCTTRANSAPI_RC_ERROR_NONE;
	int i;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hDispatcher ) ||
		( NULL == f_pParms ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pDispCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	f_pParms->ulTransportCnt = 0;

	mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING  );

	f_pParms->ulState = pDispCtx->ulState;

	/* Find empty slot */
	for( i=0; i<cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX; i++ )
	{
		if( pDispCtx->ahTransport[i] != tOCTTRANSAPI_HANDLE_INVALID )
			f_pParms->ulTransportCnt++;
	}
	f_pParms->ulElapseInactivityMs = pDispCtx->ulElapseInactivityMs;
    mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );

	return Rc;
}

/*--------------------------------------------------------------------------
	OctTransApiDispatcherRemoveTransport
----------------------------------------------------------------------------*/

tOCTTRANSAPI_RC_ERROR	OctTransApiDispatcherRemoveTransport(
							tOCTTRANSAPI_HANDLE						f_hTransport )
{
	tTRANSAPI_DISPACTH_CTX *		pDispCtx;
	tTRANSAPI_CTX	*				pTransCtx;
	tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst;
	tOCTTRANSAPI_RC_ERROR			Rc = cOCTTRANSAPI_RC_ERROR_NONE;
	int i;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport )  )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( l_pDispInst == NULL )
		return cOCTTRANSAPI_RC_ERROR_NOT_INIT;

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	Rc = TransApiInstanceUsed(pTransInst);
	if( Rc != cOCTTRANSAPI_RC_ERROR_NONE )
		return Rc;

	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) || ( 0 == pTransCtx->ulMaxDestination) )
		Rc = cOCTTRANSAPI_RC_ERROR_PARAM;
	else if( pTransCtx->hDispatcher == NULL )
		Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_CTX;
	
	if( Rc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		TransApiInstanceUnused(pTransInst);
		return Rc;
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pDispCtx = (tTRANSAPI_DISPACTH_CTX *)pTransCtx->hDispatcher;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( !pDispCtx || ( pDispCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_CTX;
#else
	if( pDispCtx == NULL )
		Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_CTX;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( Rc != cOCTTRANSAPI_RC_ERROR_NONE )
	{
		TransApiInstanceUnused(pTransInst);
		return Rc;
	}

	mTRANSAPI_MUTEX_SEIZE( pDispCtx->hMutex, cOCTOSAL_TIMEOUT_FOREVER, return cOCTTRANSAPI_RC_ERROR_PORTING  );

	if( pDispCtx->ulState < cOCTTRANSAPI_DISPATCHER_STATE_ENUM_KEEP_RUNNING )
		Rc = cOCTTRANSAPI_RC_ERROR_NOT_INIT;
	else
	{
		/* Find empty slot */
		for( i=0; i<cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX; i++ )
		{
			if( pDispCtx->ahTransport[i] == f_hTransport )
			{
				pDispCtx->ahTransport[i] = NULL;
				pTransCtx->hDispatcher = NULL;
				break;
			}
		}
		if( cOCTTRANSAPI_DISPATCHER_TRANSPORT_MAX == i )
			Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_FULL;
		else
		{
			pDispCtx->ulState = cOCTTRANSAPI_DISPATCHER_STATE_ENUM_ADDING;
			Rc = OctTransApiLocalSend( pDispCtx->hTransLocal, (void *)"REMOVING", 9 );
			if( Rc > 0 )
				Rc = cOCTTRANSAPI_RC_ERROR_NONE;
		}
	}
	TransApiInstanceUnused(pTransInst);
    mTRANSAPI_MUTEX_RELEASE(  pDispCtx->hMutex );

    /* Wait for dispathThread to remove transport */
    if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
    {
        tOCT_UINT32 iCnt=0;
        while( pDispCtx->ulState == cOCTTRANSAPI_DISPATCHER_STATE_ENUM_ADDING )
        {
            OctOsalSleepMs(10);
            iCnt++;
            if( iCnt == 10 )
            {
                Rc = cOCTTRANSAPI_RC_ERROR_DISPATCH_NO_RSP;
                break;
            }
        }
    }

	return Rc;
}

/*--------------------------------------------------------------------------
	OctTransApiSetDispatch
----------------------------------------------------------------------------*/
tOCTTRANSAPI_RC_ERROR OctTransApiSetDispatcherCB( tOCTTRANSAPI_HANDLE 	f_hTransport,
							tOCTTRANSAPI_SET_DISPATCHER_CB_PARMS *			f_pParms )
{

	tTRANSAPI_CTX	*				pTransCtx;
	tTRANSAPI_TRANSPORT_INSTANCE*	pTransInst;
	tOCTTRANSAPI_RC_ERROR			Rc = cOCTTRANSAPI_RC_ERROR_NONE;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( NULL == f_hTransport )  )
		return cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	pTransInst = (tTRANSAPI_TRANSPORT_INSTANCE *)f_hTransport;
	Rc = TransApiInstanceUsed(pTransInst);
	if( Rc != cOCTTRANSAPI_RC_ERROR_NONE )
		return Rc;

	pTransCtx = (tTRANSAPI_CTX *)pTransInst->pTransApiCtx;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( ( pTransCtx->ulMagicId != cTRANSAPI_MAGIC_ID ) )
		Rc = cOCTTRANSAPI_RC_ERROR_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if( Rc == cOCTTRANSAPI_RC_ERROR_NONE )
	{
		pTransCtx->pfnDispatchPayload = f_pParms->pfnDispatchPayload;
		pTransCtx->pAppDispatchCtx = f_pParms->pAppContext;
	}

	TransApiInstanceUnused(pTransInst);
	return Rc;
}

