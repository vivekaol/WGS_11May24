#if defined( _LINUX_ ) || defined( __linux__ )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: signal.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: Operating System Abstraction Layer
				signal related functions

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>


// #define OCT_OPT_REMOVE_OS_LINUX_EVENTFD
// #define OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE

// Last choice is to use MUTEX. 
// May be efficiant only if application is not using OctOsalSyncSignalWaitMultiple
// User must define OCT_OPT_REMOVE_OS_LINUX_EVENTFD and OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE 
// to use mutex
// #define OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX  

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENTFD
// Default is to use EVENTFD when available GLIB > (2.8)
#if !( defined(__GLIBC_PREREQ) && __GLIBC_PREREQ(2,8) )
// Second choice is to use PIPE
#define OCT_OPT_REMOVE_OS_LINUX_EVENTFD
#define OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX
#else
#define OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE
#define OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX
#endif /* __GLIBC_PREREQ */

#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENTFD
#include <sys/eventfd.h>
#ifdef EFD_SEMAPHORE
#define EVENTFD_FLAG (EFD_SEMAPHORE)
#else
#define EVENTFD_FLAG (0)
#endif /* EFD_SEMAPHORE */
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD */


#include "../../../include/octosal.h"


#ifdef OCTOSAL_OPT_MULTI_THREAD
#define cOCTOSAL_MAGIC_NUMBER 0x28071960

#ifndef cOCTOSAL_MAX_SELECTABLE
#define cOCTOSAL_MAX_SELECTABLE (32)
#endif

/* Signal control block */
typedef struct _tOSRHL7X_SIGNAL_CB_
{
    tOCT_UINT32		ulMagic;
#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENTFD
    int             eventfd;
	int             readfd;
	int             writefd;
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD */
#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX
    pthread_mutex_t	PthreadMutex;
    pthread_cond_t	PthreadCond;
    long			lSigCount;
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE
	int 			pipefd[2];
	int             readfd;
	int             writefd;
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE */


} tOSRHL7X_SIGNAL_CB, *tPOSRHL7X_SIGNAL_CB;

/*********************************  MACROS ************************************/
#ifndef mMAX
#define mMAX(x,y) ((x) > (y) ? (x) : (y))
#endif


/*--------------------------------------------------------------------------
	OctOsalSyncSignalOpen
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalOpen( tPOCTOSAL_HANDLE_SYNC_SIGNAL f_phSyncSignal )
{
	tOCTOSAL_RC	Rc;
    tPOSRHL7X_SIGNAL_CB			pSignal = NULL;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( NULL == f_phSyncSignal )
		return cOCTOSAL_RC_BAD_PARAM;
#endif

    /* Allocate memory for mutex object */
    pSignal = (tPOSRHL7X_SIGNAL_CB)malloc( sizeof( *pSignal ) );
    if( NULL == pSignal )
    {
        Rc = cOCTOSAL_RC_NO_MEMORY;
    }
    else
    {
        pSignal->ulMagic			= cOCTOSAL_MAGIC_NUMBER;

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENTFD
        pSignal->eventfd = eventfd(0, EVENTFD_FLAG);
        if( pSignal->eventfd == -1 )
        {
            Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
        }
        else
		{
            fcntl(pSignal->eventfd, F_SETFL, O_NONBLOCK | FD_CLOEXEC | fcntl(pSignal->eventfd, F_GETFL));
			pSignal->readfd = pSignal->eventfd;
			pSignal->writefd = pSignal->eventfd;
            Rc = cOCTOSAL_RC_OK;
		}
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX
        pSignal->lSigCount			= 0;
        /* Init mutex for fast mutex - no recusivity allowed */
        pSignal->PthreadCond		= (pthread_cond_t)PTHREAD_COND_INITIALIZER;
        pSignal->PthreadMutex		= (pthread_mutex_t)PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;
        Rc = cOCTOSAL_RC_OK;
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE
		if( pipe( pSignal->pipefd ) == -1 )
		{
            Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
		}
		else
		{		
			fcntl(pSignal->pipefd[0], F_SETFL, O_NONBLOCK | FD_CLOEXEC | fcntl(pSignal->pipefd[0], F_GETFL));
			fcntl(pSignal->pipefd[1], F_SETFL, O_NONBLOCK | FD_CLOEXEC | fcntl(pSignal->pipefd[1], F_GETFL));

			pSignal->readfd = pSignal->pipefd[0];
			pSignal->writefd = pSignal->pipefd[1];
		
			Rc = cOCTOSAL_RC_OK;
		}
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE */

        /* Return lock */
        *f_phSyncSignal = (void *)pSignal;

    }

    if( cOCTOSAL_RC_OK != Rc )
    {
        /* Free signal memory */
        if( NULL != pSignal )
        {
            free( pSignal );
        }
    }
	return( Rc );
}

/*--------------------------------------------------------------------------
	OctOsalSyncSignalClose
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalClose( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal )
{
    tOCTOSAL_RC                 Rc =  cOCTOSAL_RC_OK;
    tPOSRHL7X_SIGNAL_CB			pSignal = ( tPOSRHL7X_SIGNAL_CB )f_hSyncSignal;
    int                         iRc;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if ( !pSignal
        ||
        pSignal->ulMagic != cOCTOSAL_MAGIC_NUMBER )
    {
        return cOCTOSAL_RC_BAD_PARAM;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENTFD
    iRc = close( pSignal->eventfd );
    if( iRc < 0 )
    {
        Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
    }

#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE
    iRc = close( pSignal->pipefd[0] );
    if( iRc < 0 )
    {
        Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
    }
    else
    {
        iRc = close( pSignal->pipefd[1] );
        if( iRc < 0 )
        {
            Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
        }
    }
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE */


#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX
    {
        int	i;

        /* Destroy signal object.
         * Try until noboby holds it or a timeout occurs */
        /* pthread version */
        iRc = pthread_cond_destroy( &pSignal->PthreadCond );
        for( i = 0;
             i < 100 && (EBUSY == iRc);
             i++ )
        {
            usleep( 100 );
            iRc = pthread_cond_destroy( &pSignal->PthreadCond );
        }

        if( 0 != iRc )
        {
            Rc = cOCTOSAL_RC_TIMEOUT;
        }
        else
        {
            iRc = pthread_mutex_destroy( &pSignal->PthreadMutex );
            for( i = 0;
                 i < 100 && (EBUSY == iRc);
                 i++ )
            {
                usleep( 100 );
                iRc = pthread_mutex_destroy( &pSignal->PthreadMutex );
            }

            if( 0 != iRc )
            {
                if( cOCTOSAL_RC_OK == Rc )
                    Rc = cOCTOSAL_RC_TIMEOUT;
            }
        }
    }
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX */

    if ( cOCTOSAL_RC_OK == Rc )
    {
        memset( pSignal, 0x0, sizeof(*pSignal) );
        /* Release mutex memory */
        free( pSignal );
    }
	return( Rc ); 
}

/*--------------------------------------------------------------------------
	OctOsalSyncSignalWait
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalWait( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal, 
								tOCT_UINT32 	f_ulTimeoutMs )
{
    tPOSRHL7X_SIGNAL_CB			pSignal = (tPOSRHL7X_SIGNAL_CB)f_hSyncSignal;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if ( !pSignal
        ||
        pSignal->ulMagic != cOCTOSAL_MAGIC_NUMBER )
    {
        return cOCTOSAL_RC_BAD_PARAM;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#if !defined( OCT_OPT_REMOVE_OS_LINUX_EVENTFD ) || !defined( OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE )
    {
        fd_set			rfds;
        struct timeval	tv = { f_ulTimeoutMs / 1000, (f_ulTimeoutMs % 1000) * 1000 };
        int				iRcSel = 0;
        /* Allow MAX 1ms to send previous packet */

        FD_ZERO(&rfds);
        FD_SET(pSignal->readfd, &rfds);
        iRcSel = select( pSignal->readfd+1, &rfds, NULL, NULL, (cOCTOSAL_TIMEOUT_FOREVER == f_ulTimeoutMs) ? NULL : &tv );
        if( iRcSel < 0)
        {
            return cOCTOSAL_RC_OS_PORTING_ERROR;
        }
        if( FD_ISSET(pSignal->readfd, &rfds))
        {
            uint64_t u;
            ssize_t s = read(pSignal->readfd, &u, sizeof(uint64_t));
            if (s != sizeof(uint64_t))
            {
                return cOCTOSAL_RC_OS_PORTING_ERROR;
            }

            return cOCTOSAL_RC_OK;
        }
        else
            return cOCTOSAL_RC_TIMEOUT;
    }

#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD */


#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX

    /* pthread version */
    if( cOCTOSAL_TIMEOUT_FOREVER == f_ulTimeoutMs )
    {
        pthread_mutex_lock( &pSignal->PthreadMutex );
        if ( !pSignal->lSigCount )
        {
            pthread_cond_wait( &pSignal->PthreadCond, &pSignal->PthreadMutex );
        }
        pSignal->lSigCount = 0;
        pthread_mutex_unlock( &pSignal->PthreadMutex );
    }
    else
    {
        int iRc;
        struct timespec ts_timeout;
        struct timeval	tv_now;
        long            usec;      /* microseconds of target time */

        /* Fill the timeout structure */
        gettimeofday(&tv_now, NULL);
        usec = tv_now.tv_usec + (f_ulTimeoutMs * 1000); /* milli to micro */
        ts_timeout.tv_sec = tv_now.tv_sec + (usec / 1000000); /* micro to sec */
        ts_timeout.tv_nsec = (usec % 1000000) * 1000;     /* micro to nano */

        iRc = 0;
        pthread_mutex_lock( &pSignal->PthreadMutex );
        if ( !pSignal->lSigCount )
        {
            do
            {
                iRc = pthread_cond_timedwait(
                            &pSignal->PthreadCond,
                            &pSignal->PthreadMutex,
                            &ts_timeout );

            } while ( EINTR == iRc );
        }
        if ( iRc == 0 )
        {
            pSignal->lSigCount = 0;
        }

        pthread_mutex_unlock( &pSignal->PthreadMutex );

        if( ETIMEDOUT == iRc )
        {

            return cOCTOSAL_RC_TIMEOUT;
        }
    }

#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX */
    return cOCTOSAL_RC_OK;
}

/*--------------------------------------------------------------------------
    OctOsalSyncSignalWaitMultiple
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalWaitMultiple(
                        tOCT_UINT32					f_ulCount,
                        tOCTOSAL_HANDLE_SYNC_SIGNAL* f_ahSyncSignal,
                        tOCT_UINT32 				f_ulTimeoutMs,
                        tOCT_UINT32	*				f_pulIndex )
{
    tOCTOSAL_RC		Rc = cOCTOSAL_RC_OK;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if(( NULL == f_pulIndex) || !f_ulCount )
        return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

#if !defined( OCT_OPT_REMOVE_OS_LINUX_EVENTFD ) || !defined( OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE )
    {
        tOCT_UINT32     ulIndex = 0;
        fd_set			rfds;
        struct timeval	tv = { f_ulTimeoutMs / 1000, (f_ulTimeoutMs % 1000) * 1000 };
        int 			iRc;
        int 			nfds = 0;

        FD_ZERO(&rfds);

        for ( ulIndex=0; ulIndex<f_ulCount;ulIndex++ )
        {
            tPOSRHL7X_SIGNAL_CB			pSignal = (tPOSRHL7X_SIGNAL_CB)f_ahSyncSignal[ulIndex];

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
            /* Check lock exist */
            if ( !pSignal
                ||
                pSignal->ulMagic != cOCTOSAL_MAGIC_NUMBER )
            {
                return cOCTOSAL_RC_BAD_PARAM;
            }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

            /* Set FD in preparation of select operation */
            FD_SET(pSignal->readfd, &rfds);
            nfds = mMAX(nfds, pSignal->readfd);

        }
        iRc = select(	nfds+1,
                        &rfds, NULL, NULL,
                        cOCTOSAL_TIMEOUT_FOREVER == f_ulTimeoutMs ? NULL : &tv );

        if( iRc < 0)
        {
            return cOCTOSAL_RC_OS_PORTING_ERROR;
        }

        for ( ulIndex=0; ulIndex<f_ulCount;ulIndex++ )
        {
            tPOSRHL7X_SIGNAL_CB	pSignal = (tPOSRHL7X_SIGNAL_CB)f_ahSyncSignal[ulIndex];

            /* Set FD in preparation of select operation */
            if( FD_ISSET(pSignal->readfd, &rfds) )
            {
                uint64_t u;
                ssize_t s = read(pSignal->readfd, &u, sizeof(uint64_t));
                if (s != sizeof(uint64_t))
                {
                    return cOCTOSAL_RC_OS_PORTING_ERROR;
                }

                *f_pulIndex = ulIndex;
                return cOCTOSAL_RC_OK;
            }
        }
       return cOCTOSAL_RC_TIMEOUT;
    }
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD | OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX
    {
        tOCT_UINT32 ulIndex = 0;
        tOCT_UINT32 ulTiInc = 2;
        tOCT_UINT32 ulTiout = 2;
        tOCT_UINT32 ulTimeoutMs = f_ulTimeoutMs;


        if( f_ulTimeoutMs == cOCTOSAL_TIMEOUT_FOREVER )
        {
            ulTiInc = 0;
            if( f_ulCount == 1 )
                ulTiout = cOCTOSAL_TIMEOUT_FOREVER;
        }

        while( ulTimeoutMs  )
        {
            Rc = OctOsalSyncSignalWait( f_ahSyncSignal[ulIndex % f_ulCount], ulTiout );
            if( Rc == cOCTOSAL_RC_OK )
            {
                *f_pulIndex = (ulIndex % f_ulCount);
                break;
            }
            else if( Rc != cOCTOSAL_RC_TIMEOUT )
                break;

            ulIndex++;
            if( ulTimeoutMs > ulTiInc )
                ulTimeoutMs -= ulTiInc;
            else
                ulTimeoutMs  = 0;
        }
    }
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX */

    return( Rc );
}


/*--------------------------------------------------------------------------
	OctOsalSyncSignalSet
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalSet( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal )
{
    tPOSRHL7X_SIGNAL_CB			pSignal = (tPOSRHL7X_SIGNAL_CB)f_hSyncSignal;


#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
    if ( !pSignal
        ||
        pSignal->ulMagic != cOCTOSAL_MAGIC_NUMBER )
    {
        return cOCTOSAL_RC_BAD_PARAM;
    }
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */



#if !defined( OCT_OPT_REMOVE_OS_LINUX_EVENTFD ) || !defined( OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE )
    {
        uint64_t u=1;
        ssize_t s = write(pSignal->writefd, &u, sizeof(uint64_t));
        if (s != sizeof(uint64_t))
        {
            return cOCTOSAL_RC_OS_PORTING_ERROR;
        }

    }
#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENTFD  | OCT_OPT_REMOVE_OS_LINUX_EVENT_PIPE */

#ifndef OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX

    /* Unlock the mutex */
    pthread_mutex_lock( &pSignal->PthreadMutex );
    pSignal->lSigCount = 1;
    pthread_cond_signal( &pSignal->PthreadCond );
    pthread_mutex_unlock( &pSignal->PthreadMutex );

#endif /* OCT_OPT_REMOVE_OS_LINUX_EVENT_MUTEX */


    return cOCTOSAL_RC_OK;

}
#endif /* OCTOSAL_OPT_MULTI_THREAD */
#endif /* Linux */

