#if defined( _WIN32 ) || defined( _WIN64 ) || defined( WIN32 ) || defined( WIN64 )
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
#include <Windows.h>
#include "../../../include/octosal.h"

#ifdef OCTOSAL_OPT_MULTI_THREAD

/*--------------------------------------------------------------------------
	OctOsalMutexOpen
----------------------------------------------------------------------------*/
tOCTOSAL_RC OctOsalMutexOpen( tPOCTOSAL_HANDLE_MUTEX		f_phMutex )
{
	HANDLE			hMutex;

	hMutex = CreateMutex( NULL, FALSE, NULL );

	if ( hMutex != NULL )
	{
		*f_phMutex = (void *)hMutex;
	}
	else
	{
		return cOCTOSAL_RC_OS_PORTING_ERROR;
	}

	return cOCTOSAL_RC_OK;
}

/*--------------------------------------------------------------------------
	OctOsalMutexClose
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalMutexClose(
	tOCTOSAL_HANDLE_MUTEX				f_hMutex )
{
#ifndef OCT_OPT_REMOVE_FNC_PARAM_VALIDATION
	DWORD	dwInf;
	if( ( f_hMutex == NULL ) ||
		!GetHandleInformation( (HANDLE)f_hMutex, &dwInf ) )
	{
		return( cOCTOSAL_RC_BAD_MUTEX );
	}
#endif /* OCT_OPT_REMOVE_FNC_PARAM_VALIDATION */

	if ( TRUE != CloseHandle( (HANDLE)f_hMutex ) )
	{
		return cOCTOSAL_RC_OS_PORTING_ERROR;
	}
	
	return cOCTOSAL_RC_OK;
}

/*--------------------------------------------------------------------------
	OctOsalMutexSeize
----------------------------------------------------------------------------*/
tOCTOSAL_RC	OctOsalMutexSeize( 
	tOCTOSAL_HANDLE_MUTEX				f_hMutex,
	tOCT_UINT32		f_ulTimeoutMs)
{
	DWORD			dwRc;
	tOCTOSAL_RC		Rc = cOCTOSAL_RC_OK;

	dwRc = WaitForSingleObject( (HANDLE)f_hMutex, (cOCTOSAL_TIMEOUT_FOREVER == f_ulTimeoutMs)?INFINITE:f_ulTimeoutMs );

	switch( dwRc )
	{
	case WAIT_OBJECT_0:
		break;
	case WAIT_TIMEOUT:
		Rc = cOCTOSAL_RC_TIMEOUT;
		break;
	default:
		Rc = cOCTOSAL_RC_OS_PORTING_ERROR;
		break;
	}

	return Rc;
}

/*--------------------------------------------------------------------------
	OctOsalMutexRelease
----------------------------------------------------------------------------*/
tOCTOSAL_RC			OctOsalMutexRelease(
	tOCTOSAL_HANDLE_MUTEX				f_hMutex )
{
	if ( TRUE != ReleaseMutex( (HANDLE)f_hMutex ) )
	{
		return cOCTOSAL_RC_OS_PORTING_ERROR;
	}
	return cOCTOSAL_RC_OK;
}

#endif /* OCTOSAL_OPT_MULTI_THREAD */

#endif /* WIN32 */
