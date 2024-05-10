/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_CTRL_API.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the CTRL API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_CTRL_API_H__
#define __OCTVC1_CTRL_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"

#include "octvc1_ctrl_id.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  SUPERVISORY  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV
 		OCTVC1 Reject Supervisory Command

 Members:
	Header
 		VocalloNet and API header.
	ulExpectedTransactionId
 		Transaction ID expected for this session.
	ulRejectedCmdId
 		Command ID of the command rejected.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCT_UINT32						ulExpectedTransactionId;
	tOCT_UINT32						ulRejectedCmdId;

} tOCTVC1_CTRL_MSG_MODULE_REJECT_SPV;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/

#endif /* __OCTVC1_CTRL_API_H__ */

