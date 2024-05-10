/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_BASE.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_BASE_H__
#define __OCTVC1_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_rc_base.h"

/****************************************************************************
	Command identifier base
 ****************************************************************************/
#define cOCTVC1_CID_BASE                        ( 0x01000000 )

/****************************************************************************
	Event identifier base
 ****************************************************************************/
#define cOCTVC1_EID_BASE                        ( 0x02000000 )

/****************************************************************************
	Supervisory identifier base
 ****************************************************************************/
#define cOCTVC1_SID_BASE                        ( 0x03000000 )

/****************************************************************************
	return code identifier base
 ****************************************************************************/
#define cOCTVC1_RC_BASE                         ( cOCTVC1_API_RC_BASE )

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_GENERIC_UID                     ( 0x00 )
#define cOCTVC1_PKT_API_UID                     ( 0x02 )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: GENERIC */
#define cOCTVC1_GENERIC_RC_BASE                 ( (cOCTVC1_GENERIC_UID << 16) + cOCTVC1_RC_BASE )

/* Module: PKT_API */
#define cOCTVC1_PKT_API_RC_BASE                 ( (cOCTVC1_PKT_API_UID << 16) + cOCTVC1_RC_BASE )

#endif /* __OCTVC1_BASE_H__ */

