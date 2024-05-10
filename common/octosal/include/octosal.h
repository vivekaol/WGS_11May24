/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octosal.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description:	Operating System Abstraction Layer

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.16.00-B304 (2018/05/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTOSAL_H__
#define __OCTOSAL_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../../sls/inc/octdev_types.h"
#include "../../include/octcommon_base.h"

#include "octosal_version.h"
#include "octosal_rc.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*----------------------------------------------------------------------------
	OS definitions
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	POINTER DEFINITION.
----------------------------------------------------------------------------*/
#if defined( OCT_ENV_TYPE_WINDOWS )
#include <basetsd.h>

#define tOCTOSAL_UINT_PTR	UINT_PTR
#define tOCTOSAL_INT_PTR	INT_PTR

#else

#include <inttypes.h>


#define tOCTOSAL_UINT_PTR	uintptr_t
#define tOCTOSAL_INT_PTR	intptr_t

#endif /* OCT_ENV_TYPE_WINDOWS */

/*----------------------------------------------------------------------------
	Keep previous compatibility.
----------------------------------------------------------------------------*/
#ifdef OCTVC1_PKT_API_OS_OPT_MULTI_THREAD
#ifndef OCTOSAL_OPT_MULTI_THREAD
#define OCTOSAL_OPT_MULTI_THREAD
#endif /* OCTOSAL_OPT_MULTI_THREAD */	
#endif /* OCTVC1_PKT_API_OS_OPT_MULTI_THREAD */

#ifdef OCTVC1_PKT_API_OS_OPT_ASSERT
#ifndef OCTOSAL_OPT_ASSERT
#define OCTOSAL_OPT_ASSERT
#endif /* OCTOSAL_OPT_ASSERT */
#endif /* OCTVC1_PKT_API_OS_OPT_ASSERT */

/*----------------------------------------------------------------------------
	Make sure we use THREAD and ASSERT option under WIN32
----------------------------------------------------------------------------*/
#ifdef OCT_ENV_TYPE_WINDOWS

#ifndef OCTOSAL_OPT_MULTI_THREAD
#define OCTOSAL_OPT_MULTI_THREAD
#endif /* OCTOSAL_OPT_MULTI_THREAD */

#ifndef OCTOSAL_OPT_ASSERT
#define OCTOSAL_OPT_ASSERT
#endif /* OCTOSAL_OPT_ASSERT */

#if !defined( OCT_ENV_MODE_DEBUG )
/* Disable function validation when compiling release configuration */
#define OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
#endif /* OCT_ENV_MODE_DEBUG */

#endif /* OCT_ENV_TYPE_WINDOWS */


/*----------------------------------------------------------------------------
	Assert related functions
----------------------------------------------------------------------------*/
#ifdef OCTOSAL_OPT_ASSERT
#include <assert.h>
#ifdef OCT_ENV_TYPE_WINDOWS
#include <crtdbg.h>
#define	mOCTOSAL_ASSERT( _f_fCondition ) \
	_ASSERT( _f_fCondition )
#else /* OCT_ENV_TYPE_WINDOWS*/
#define	mOCTOSAL_ASSERT( _f_fCondition ) \
	assert( _f_fCondition )
#endif /* OCT_ENV_TYPE_WINDOWS*/
#else
#define	mOCTOSAL_ASSERT( _f_fCondition ) 
#endif /* OCTOSAL_OPT_ASSERT */

/*----------------------------------------------------------------------------
	Generic definitions
----------------------------------------------------------------------------*/
#define	cOCTOSAL_TIMEOUT_FOREVER	cOCTDEV_TIMEOUT_FOREVER

#define tOCTOSAL_CONTEXT	void *


/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	MUTEX related definitions
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*----------------------------------------------------------------------------
	OctOs Mutex handle
----------------------------------------------------------------------------*/
#define tOCTOSAL_HANDLE_MUTEX			void *
#define tPOCTOSAL_HANDLE_MUTEX			tOCTOSAL_HANDLE_MUTEX *
#define cOCTOSAL_HANDLE_MUTEX_INVALID	NULL

#ifdef OCTOSAL_OPT_MULTI_THREAD
/*--------------------------------------------------------------------------
	OctOsalMutexOpen

		This function opens a system mutex.

  f_phMutex			: OUT Pointer to opened mutex handle.

----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalMutexOpen( tPOCTOSAL_HANDLE_MUTEX f_phMutex );


/*--------------------------------------------------------------------------
	OctOsalMutexClose

		This function close a system mutex.

  f_hMutex			: IN opened mutex handle.

----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalMutexClose( tOCTOSAL_HANDLE_MUTEX f_hMutex );

/*--------------------------------------------------------------------------
	OctOsalMutexSeize

		This function wait a system mutex for a maximum of milliseconds

  f_hMutex		: IN opened mutex handle.
  f_ulTimeoutMs	: Max milliseconds to wait.

----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalMutexSeize( tOCTOSAL_HANDLE_MUTEX f_hMutex, tOCT_UINT32 	f_ulTimeoutMs );


/*--------------------------------------------------------------------------
	OctOsalMutexRelease

		This function release a system mutex 

  f_hMutex		: IN opened mutex handle.
  
----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalMutexRelease( tOCTOSAL_HANDLE_MUTEX f_hMutex );



/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	SYNC_SIGNAL related definitions
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

#define tOCTOSAL_HANDLE_SYNC_SIGNAL			void *
#define tPOCTOSAL_HANDLE_SYNC_SIGNAL		tOCTOSAL_HANDLE_SYNC_SIGNAL *
#define cOCTOSAL_HANDLE_SYNC_SIGNAL_INVALID	NULL

/*--------------------------------------------------------------------------
	OctOsalSyncSignalOpen

		This function opens a system sync signal.

  f_phSyncSignal	: OUT Pointer to opened mutex handle.

----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalSyncSignalOpen( tPOCTOSAL_HANDLE_SYNC_SIGNAL f_phSyncSignal );


/*--------------------------------------------------------------------------
	OctOsalSyncSignalClose

		This function close a system sync signal.

  f_hSyncSignal	: IN opened mutex handle.

----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalSyncSignalClose( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal );

/*--------------------------------------------------------------------------
	OctOsalSyncSignalWait

		This function wait a system sync signal for a maximum of milliseconds

  f_hSyncSignal	: IN opened system sync signal handle.
  f_ulTimeoutMs	: IN Max milliseconds to wait.
		
----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalSyncSignalWait( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal, tOCT_UINT32 	f_ulTimeoutMs );


/*--------------------------------------------------------------------------
	OctOsalSyncSignalWaitMultiple

		This function wait multiple system sync signal for a maximum of milliseconds

  f_ulCount			: IN Number of signal to wait on.
  f_ahSyncSignal	: IN opened system sync signal handles.
  f_ulTimeoutMs		: IN Max milliseconds to wait.
  f_pulIndex		: OUT Index of the set signal in the array.
		
----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalSyncSignalWaitMultiple( 
                        tOCT_UINT32                     f_ulCount,
                        tOCTOSAL_HANDLE_SYNC_SIGNAL*    f_ahSyncSignal,
                        tOCT_UINT32                     f_ulTimeoutMs,
                        tOCT_UINT32	*                   f_pulIndex );

/*--------------------------------------------------------------------------
	OctOsalSyncSignalSet

		This function set a system sync signal 

  f_hSyncSignal		: opened sync signal handle.
  
----------------------------------------------------------------------------*/
extern tOCTOSAL_RC	OctOsalSyncSignalSet( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal );

#endif /* OCTOSAL_OPT_MULTI_THREAD */

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Time related definitions
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

/*--------------------------------------------------------------------------
	OctOsalSleepMs

		This function sleep for number of milliseconds.

  f_ulSleepMs		: IN Number of milliseconds to sleep

----------------------------------------------------------------------------*/
extern tOCT_INT32 OctOsalSleepMs( tOCT_UINT32 f_ulSleepMs );

/*--------------------------------------------------------------------------
	OctOsalGetTimeMs

		This function number of milliseconds since the system start.

Return :	time in milli sec

----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctOsalGetTimeMs( void );

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif


#endif /* __OCTOSAL_H__*/
