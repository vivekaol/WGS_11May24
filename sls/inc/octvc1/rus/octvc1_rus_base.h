/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_BASE.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_BASE_H__
#define __OCTVC1_RUS_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_RUS_UID                         ( 0x0E )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: RUS */
#define cOCTVC1_RUS_CID_BASE                    ( (cOCTVC1_RUS_UID << 16) + cOCTVC1_CID_BASE )
#define cOCTVC1_RUS_EID_BASE                    ( (cOCTVC1_RUS_UID << 16) + cOCTVC1_EID_BASE )
#define cOCTVC1_RUS_MID_BASE                    ( (cOCTVC1_RUS_UID << 24) )
#define cOCTVC1_RUS_RC_BASE                     ( (cOCTVC1_RUS_UID << 16) + cOCTVC1_RC_BASE )

#endif /* __OCTVC1_RUS_BASE_H__ */

