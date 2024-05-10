#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: mutex.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: Operating System Abstraction Layer
				mutex related functions

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

/* Porting interface */
#include "../../../include/octosal.h"


/****************************  STATIC FUNCTION ********************************/

/***************************  INTERNAL FUNCTION *******************************/

/****************************  USER INTERFACE *********************************/

#ifdef OCTOSAL_OPT_MULTI_THREAD

#define cOCTOSAL_MAGIC_NUMBER 0x28071960

/* Signal control block */
typedef struct _tOSRHL7X_MUTEX_CB_
{
    tOCT_UINT32		ulMagic;
    pthread_mutex_t	PthreadMutex;

} tOSRHL7X_MUTEX_CB, *tPOSRHL7X_MUTEX_CB;



/*--------------------------------------------------------------------------
	OctOsalMutexOpen
----------------------------------------------------------------------------*/
tOCTOSAL_RC			OctOsalMutexOpen( tPOCTOSAL_HANDLE_MUTEX	f_phMutex )
{
    tPOSRHL7X_MUTEX_CB  	pMutex;
	int						iRc = -1;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
   if ( NULL == f_phMutex )
   {
        return cOCTOSAL_RC_BAD_PARAM;
   }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    pMutex = (tPOSRHL7X_MUTEX_CB)malloc( sizeof( tOSRHL7X_MUTEX_CB ) );

	if ( pMutex != NULL )
	{
        pthread_mutexattr_t Attr;

        pthread_mutexattr_init(&Attr);
        pthread_mutexattr_settype(&Attr, PTHREAD_MUTEX_RECURSIVE);

        pMutex->ulMagic	= cOCTOSAL_MAGIC_NUMBER;
        iRc = pthread_mutex_init( &pMutex->PthreadMutex, &Attr );
	
        pthread_mutexattr_destroy(&Attr);

		if ( iRc == 0 )
		{
			*f_phMutex = (void *)pMutex;
		}
		else
		{
            free ( pMutex ) ;
            return cOCTOSAL_RC_OS_PORTING_ERROR;
		}
	}
    else
        return cOCTOSAL_RC_NO_MEMORY;

    return cOCTOSAL_RC_OK;
}

/*--------------------------------------------------------------------------
	OctOsalMutexClose
----------------------------------------------------------------------------*/
tOCTOSAL_RC			OctOsalMutexClose(
	tOCTOSAL_HANDLE_MUTEX	f_hMutex )
{
    int	i;
    int iRc;
    tPOSRHL7X_MUTEX_CB	pMutex = ( tPOSRHL7X_MUTEX_CB )f_hMutex;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if ( !pMutex
        ||
        pMutex->ulMagic != cOCTOSAL_MAGIC_NUMBER )
    {
        return cOCTOSAL_RC_BAD_MUTEX;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    iRc = pthread_mutex_destroy( &pMutex->PthreadMutex );
    for( i = 0;
         i < 100 && (EBUSY == iRc);
         i++ )
    {
        usleep( 100 );
        iRc = pthread_mutex_destroy( &pMutex->PthreadMutex );
    }

    if( iRc != 0 )
    {
		return (EBUSY == iRc) ? cOCTOSAL_RC_BUSY : cOCTOSAL_RC_OS_PORTING_ERROR;
    }
    pMutex->ulMagic = 0;
    free( pMutex );
	
    return cOCTOSAL_RC_OK;
}

/*--------------------------------------------------------------------------
	OctOsalMutexSeize
----------------------------------------------------------------------------*/
tOCTOSAL_RC			OctOsalMutexSeize(
	tOCTOSAL_HANDLE_MUTEX	f_hMutex,
	tOCT_UINT32		f_ulTimeoutMs)
{
    int iRc;
    tPOSRHL7X_MUTEX_CB	pMutex = ( tPOSRHL7X_MUTEX_CB )f_hMutex;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    /* Check lock exist */
    if ( !pMutex
        ||
        pMutex->ulMagic != cOCTOSAL_MAGIC_NUMBER )
    {
        return cOCTOSAL_RC_BAD_MUTEX;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */


	if ( cOCTOSAL_TIMEOUT_FOREVER == f_ulTimeoutMs )
	{
        iRc = pthread_mutex_lock(  &pMutex->PthreadMutex  );
	}
	else
	{
		struct timespec ts;
		struct timeval tv;
		
		gettimeofday( &tv, NULL);

		tv.tv_usec += ((f_ulTimeoutMs % 1000) * 1000);
		tv.tv_sec += f_ulTimeoutMs / 1000;
		if(tv.tv_usec >= 1000000)
		{
			tv.tv_usec -= 1000000;
			tv.tv_sec++;
		}

		TIMEVAL_TO_TIMESPEC(&tv,&ts)
        iRc = pthread_mutex_timedlock( &pMutex->PthreadMutex, &ts );
	}
    switch( iRc )
    {
        case 0:
        case EDEADLK:   /* already lock */
            return cOCTOSAL_RC_OK;

        case ETIMEDOUT:   /* timeout */
            return cOCTOSAL_RC_TIMEOUT;

        default:
            return cOCTOSAL_RC_OS_PORTING_ERROR;
    }
}

/*--------------------------------------------------------------------------
	OctOsalMutexRelease
----------------------------------------------------------------------------*/
tOCTOSAL_RC			OctOsalMutexRelease(
	tOCTOSAL_HANDLE_MUTEX	f_hMutex )
{
     tPOSRHL7X_MUTEX_CB	pMutex = ( tPOSRHL7X_MUTEX_CB )f_hMutex;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    /* Check lock exist */
    if ( !pMutex
        ||
        pMutex->ulMagic != cOCTOSAL_MAGIC_NUMBER )
    {
        return cOCTOSAL_RC_BAD_MUTEX;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

    int iRc = pthread_mutex_unlock( &pMutex->PthreadMutex );
    if( iRc == 0 )
        return cOCTOSAL_RC_OK;

    return cOCTOSAL_RC_OS_PORTING_ERROR;

}

#endif /* OCTOSAL_OPT_MULTI_THREAD */

#endif /* __linux__ */
