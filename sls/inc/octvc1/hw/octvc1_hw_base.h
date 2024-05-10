/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_HW_BASE.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_HW_BASE_H__
#define __OCTVC1_HW_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_HW_UID                          ( 0x06 )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: HW */
#define cOCTVC1_HW_CID_BASE                     ( (cOCTVC1_HW_UID << 16) + cOCTVC1_CID_BASE )
#define cOCTVC1_HW_EID_BASE                     ( (cOCTVC1_HW_UID << 16) + cOCTVC1_EID_BASE )
#define cOCTVC1_HW_RC_BASE                      ( (cOCTVC1_HW_UID << 16) + cOCTVC1_RC_BASE )

#endif /* __OCTVC1_HW_BASE_H__ */

