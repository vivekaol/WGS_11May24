/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTCOMMON_BASE.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the definition of the return code base values for the various
common Octasic APIs.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.16.00-B304 (2018/05/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/
#include "../../sls/inc/octdev_rc_base.h"

#ifndef __OCTCOMMON_BASE_H__
#define __OCTCOMMON_BASE_H__


/****************************************************************************
	Common API unique identifiers
 ****************************************************************************/
#define cOCTOSAL_UID							( 0x01 )	/* Operating System Abstraction Layer */
#define cOCTRS232API_UID						( 0x02 )	/* RS232 Abstraction Layer */
#define cOCTTRANSAPI_UID						( 0x03 )	/* Transport Abstraction Layer */

/****************************************************************************
	Common identifier bases
 ****************************************************************************/

#define cOCTOSAL_RC_BASE						( (cOCTOSAL_UID << 16) + cOCTCOMMON_API_RC_BASE )
#define cOCTRS232API_RC_BASE					( (cOCTRS232API_UID << 16) + cOCTCOMMON_API_RC_BASE )

#endif /* __OCTCOMMON_BASE_H__ */
