/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_CTRL_ID.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the identifiers for the CTRL API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_CTRL_ID_H__
#define __OCTVC1_CTRL_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"
#include "octvc1_ctrl_base.h"

/****************************************************************************
	Supervisory IDs
 ****************************************************************************/
#define cOCTVC1_CTRL_MSG_MODULE_REJECT_SID ( 0x0001 + cOCTVC1_CTRL_SID_BASE )

#define cOCTVC1_CTRL_SID_MAX               (( 0x0001 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_CTRL_ID_H__ */

