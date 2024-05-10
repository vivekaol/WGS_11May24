#if defined( _LINUX_ ) || defined( __linux__ )

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
#include <string.h>

#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>


#include "../../../include/octosal.h"

/*--------------------------------------------------------------------------
	OctOsalSleepMs
----------------------------------------------------------------------------*/
tOCT_INT32 OctOsalSleepMs( tOCT_UINT32 f_ulSleepMs )
{
	if ( 0 == f_ulSleepMs )
	{
		/* NOTE:
			The usage of the sched_yield() function have concerns in Linux-kernel version 2.2 to at least 2.4.8.
			The function does not yield correclty. Current workaround is to use usleep(0) istead */
		sched_yield();
	}
	else
	{
		usleep( f_ulSleepMs * 1000 );
	}

	return 0;
}


/*--------------------------------------------------------------------------
	OctOsalGetTimeMs
----------------------------------------------------------------------------*/
unsigned int	OctOsalGetTimeMs( void )
{
	struct timespec		CurrentTime;
#ifdef _POSIX_MONOTONIC_CLOCK
	clock_gettime( CLOCK_MONOTONIC, &CurrentTime );
#else
	clock_gettime( CLOCK_REALTIME, &CurrentTime );
#endif
	return( (unsigned int)
		((CurrentTime.tv_sec * 1000)+
		(CurrentTime.tv_nsec / 1000000)) );
}

#endif /* __linux__ */
