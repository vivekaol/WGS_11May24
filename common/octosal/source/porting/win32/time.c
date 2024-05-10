#if defined( _WIN32 ) || defined( _WIN64 ) || defined( WIN32 ) || defined( WIN64 )
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: time.c

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: Operating System Abstraction Layer
				Time related functions

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

#pragma comment( lib, "Winmm.lib" )

/*--------------------------------------------------------------------------
	OctOsalSleepMs
----------------------------------------------------------------------------*/
tOCT_INT32 OctOsalSleepMs( tOCT_UINT32 f_ulSleepMs )
{
	SleepEx( f_ulSleepMs, 0 );
	return 0;
}

/*--------------------------------------------------------------------------
	OctOsalGetTimeMs
----------------------------------------------------------------------------*/
unsigned int	OctOsalGetTimeMs( void )
{
	return timeGetTime();
}
#endif /* WIN32 */