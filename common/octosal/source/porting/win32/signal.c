#if defined( _WIN32 ) || defined( _WIN64 ) || defined( WIN32 ) || defined( WIN64 )
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
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

#include "../../../include/octosal.h"


#ifdef OCTOSAL_OPT_MULTI_THREAD

/*--------------------------------------------------------------------------
	OctOsalSyncSignalOpen
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalOpen( tPOCTOSAL_HANDLE_SYNC_SIGNAL f_phSyncSignal )
{
	tOCTOSAL_RC	Rc;
	HANDLE			hEvent;

	hEvent = CreateEvent( NULL, FALSE, FALSE, NULL );

	if ( hEvent != NULL )
	{
		*f_phSyncSignal = (tPOCTOSAL_HANDLE_SYNC_SIGNAL)hEvent;

		Rc = cOCTOSAL_RC_OK;
	}
	else
	{
		Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
	}

	return( Rc );
}

/*--------------------------------------------------------------------------
	OctOsalSyncSignalClose
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalClose( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal )
{
	tOCTOSAL_RC	Rc;
	BOOL			fRc;
	DWORD			dwInf;

	if( !GetHandleInformation( (HANDLE)f_hSyncSignal, &dwInf ) )
		return cOCTOSAL_RC_NOT_FOUND;
		
	fRc = CloseHandle( (HANDLE)f_hSyncSignal );
	if ( fRc )
	{
		Rc = cOCTOSAL_RC_OK;
	}
	else
	{
		Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
	}
	return( Rc ); 
}

/*--------------------------------------------------------------------------
	OctOsalSyncSignalWait
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalWait( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal, 
								tOCT_UINT32 	f_ulTimeoutMs )
{
	tOCTOSAL_RC		Rc;
	DWORD			dwWaitTime;
	DWORD			dwRc;

	if ( f_ulTimeoutMs == cOCTOSAL_TIMEOUT_FOREVER )
	{
		dwWaitTime = INFINITE;
	}
	else
	{
		dwWaitTime = f_ulTimeoutMs;
	}

	dwRc = WaitForSingleObject( (HANDLE)f_hSyncSignal, dwWaitTime );

	switch( dwRc )
	{
	case WAIT_OBJECT_0:
		Rc = cOCTOSAL_RC_OK;
		break;
	case WAIT_TIMEOUT:
		Rc = cOCTOSAL_RC_TIMEOUT;
		break;
	default:
		Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
		break;
	}

	return( Rc );
}


/*--------------------------------------------------------------------------
	OctOsalSyncSignalWaitMultiple
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalWaitMultiple( 
						tOCT_UINT32					f_ulCount,
						tOCTOSAL_HANDLE_SYNC_SIGNAL *f_ahSyncSignal, 
						tOCT_UINT32 				f_ulTimeoutMs,
						tOCT_UINT32	*				f_pulIndex )
{
	tOCTOSAL_RC		Rc = cOCTOSAL_RC_OK;
	DWORD			dwWaitTime;
	DWORD			dwRc;

#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	if( NULL == f_pulIndex )
		return cOCTOSAL_RC_BAD_PARAM;
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if ( f_ulTimeoutMs == cOCTOSAL_TIMEOUT_FOREVER )
	{
		dwWaitTime = INFINITE;
	}
	else
	{
		dwWaitTime = f_ulTimeoutMs;
	}

	dwRc = WaitForMultipleObjects( f_ulCount, 
						f_ahSyncSignal,
						FALSE,
						dwWaitTime );

	if ( WAIT_TIMEOUT == dwRc )
		Rc = cOCTOSAL_RC_TIMEOUT;
	else if ( WAIT_OBJECT_0 <= dwRc && WAIT_OBJECT_0 + f_ulCount > dwRc )
	{
		*f_pulIndex = (tOCT_UINT32)(dwRc - WAIT_OBJECT_0);
	}
	else if ( WAIT_ABANDONED_0 <= dwRc && WAIT_ABANDONED_0 + f_ulCount > dwRc )
	{
		/* Probably a close handle or socket */
		Rc = cOCTOSAL_RC_BAD_SYNC_SIGNAL;
	}
	else
	{
		Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
	}
	return( Rc );
}


/*--------------------------------------------------------------------------
	OctOsalSyncSignalSet
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalSyncSignalSet( tOCTOSAL_HANDLE_SYNC_SIGNAL f_hSyncSignal )
{
	tOCTOSAL_RC		Rc;
	BOOL			fRc;

	fRc = SetEvent( (HANDLE) f_hSyncSignal );
	if ( fRc )
	{
		Rc = cOCTOSAL_RC_OK;
	}
	else
	{
		Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
	}

	return( Rc );

}

#endif /* OCTOSAL_OPT_MULTI_THREAD */

#endif /* WIN32 */
