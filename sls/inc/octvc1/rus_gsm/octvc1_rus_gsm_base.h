/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_GSM_BASE.h

Copyright (c) 2015 Octasic Inc. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-02.08.00-B1331 (2015/12/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_GSM_BASE_H__
#define __OCTVC1_RUS_GSM_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_RUS_GSM_UID                     ( 0x0F )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: RUS_GSM */
#define cOCTVC1_RUS_GSM_CID_BASE                ( (cOCTVC1_RUS_GSM_UID << 16) + cOCTVC1_CID_BASE )
#define cOCTVC1_RUS_GSM_EID_BASE                ( (cOCTVC1_RUS_GSM_UID << 16) + cOCTVC1_EID_BASE )
#define cOCTVC1_RUS_GSM_RC_BASE                 ( (cOCTVC1_RUS_GSM_UID << 16) + cOCTVC1_RC_BASE )

#endif /* __OCTVC1_RUS_GSM_BASE_H__ */

