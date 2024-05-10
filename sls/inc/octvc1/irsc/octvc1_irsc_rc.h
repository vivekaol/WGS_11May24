/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_IRSC_RC.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the return codes for the IRSC API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_IRSC_RC_H__
#define OCTVC1_IRSC_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"
#include "octvc1_irsc_base.h"

/****************************************************************************
	IRSC return codes
 ****************************************************************************/
#define cOCTVC1_IRSC_RC_INVALID_TASK						 ( 0x000A + cOCTVC1_IRSC_RC_BASE )

/****************************************************************************
	OBJMGR return codes
 ****************************************************************************/
#define cOCTVC1_IRSC_OBJMGR_RC_BASE							 ( 0x0450 + cOCTVC1_IRSC_RC_BASE )

#define cOCTVC1_IRSC_RC_OBJMGR_LIST_ERROR					 ( 0x0001 + cOCTVC1_IRSC_OBJMGR_RC_BASE )
#define cOCTVC1_IRSC_RC_OBJMGR_INVALID_OBJECT				 ( 0x0002 + cOCTVC1_IRSC_OBJMGR_RC_BASE )
#define cOCTVC1_IRSC_RC_OBJMGR_INTERNAL_ERROR				 ( 0x0003 + cOCTVC1_IRSC_OBJMGR_RC_BASE )
#define cOCTVC1_IRSC_RC_OBJMGR_NOT_INIT						 ( 0x0004 + cOCTVC1_IRSC_OBJMGR_RC_BASE )

/****************************************************************************
	ROUTER return codes
 ****************************************************************************/
#define cOCTVC1_IRSC_ROUTER_RC_BASE							 ( 0x0460 + cOCTVC1_IRSC_RC_BASE )

#define cOCTVC1_IRSC_RC_ROUTER_ROUTER_IF_INVALID			 ( 0x0001 + cOCTVC1_IRSC_ROUTER_RC_BASE )

/****************************************************************************
	API_COMMAND return codes
 ****************************************************************************/
#define cOCTVC1_IRSC_API_COMMAND_RC_BASE						 ( 0x0550 + cOCTVC1_IRSC_RC_BASE )

#define cOCTVC1_IRSC_RC_API_COMMAND_MONITORING_DISABLE			 ( 0x0002 + cOCTVC1_IRSC_API_COMMAND_RC_BASE )
#define cOCTVC1_IRSC_RC_API_COMMAND_MAX_REACHED					 ( 0x0003 + cOCTVC1_IRSC_API_COMMAND_RC_BASE )
#define cOCTVC1_IRSC_RC_API_COMMAND_MONITORING_ALREADY_START	 ( 0x0004 + cOCTVC1_IRSC_API_COMMAND_RC_BASE )
#define cOCTVC1_IRSC_RC_API_COMMAND_INTERNAL_ERROR				 ( 0x0005 + cOCTVC1_IRSC_API_COMMAND_RC_BASE )

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_IRSC_AUTO_VALIDATE_RC_BASE					 ( 0xF000 + cOCTVC1_IRSC_RC_BASE )

#define cOCTVC1_IRSC_RC_ROUTER_STREAMER_MODIFY_INVALID_LIMIT_BANDWIDTH_MBPS	 ( 0x1 + cOCTVC1_IRSC_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_IRSC_RC_ROUTER_STREAMER_MODIFY_INVALID_TO_HOST_STREAM_SEQUENCE_ID_INTERVAL	 ( 0x2 + cOCTVC1_IRSC_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_IRSC_RC_ROUTER_STREAMER_MODIFY_INVALID_TO_HOST_STREAM_INITIAL_PKT_CNT	 ( 0x3 + cOCTVC1_IRSC_AUTO_VALIDATE_RC_BASE )

#endif /* OCTVC1_IRSC_RC_H__ */

