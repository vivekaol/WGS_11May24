/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTOSAL_RC.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: OS Abstraction layer API

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.16.00-B304 (2018/05/02)

$Octasic_Revision: 1 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/



#ifndef __OCTOSAL_RC_H__
#define __OCTOSAL_RC_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../../sls/inc/octdev_types.h"
#include "../../include/octcommon_base.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif



/*----------------------------------------------------------------------------
	Return code
----------------------------------------------------------------------------*/
typedef tOCT_UINT32							tOCTOSAL_RC;

#define cOCTOSAL_RC_OK						(0)
#define cOCTOSAL_RC_BAD_PARAM				( 0x0001 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_NO_MEMORY				( 0x0002 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_INTERNAL_ERROR			( 0x0003 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_OS_PORTING_ERROR		( 0x0004 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_NOT_FOUND				( 0x0005 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_BAD_MUTEX				( 0x0006 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_BAD_SYNC_SIGNAL			( 0x0007 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_BUSY					( 0x0008 + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_TIMEOUT					( 0x000A + cOCTOSAL_RC_BASE )
#define cOCTOSAL_RC_QUEUE_CORRUPTED			( 0x000F + cOCTOSAL_RC_BASE )


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTOSAL_RC_H__ */
