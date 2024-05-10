/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_CTRL_BASE.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_CTRL_BASE_H__
#define __OCTVC1_CTRL_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_CTRL_UID                        ( 0x03 )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: CTRL */
#define cOCTVC1_CTRL_SID_BASE                   ( (cOCTVC1_CTRL_UID << 16) + cOCTVC1_SID_BASE )

#endif /* __OCTVC1_CTRL_BASE_H__ */

