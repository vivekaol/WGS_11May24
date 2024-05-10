/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_UMTS_ID.h

Copyright (c) 2015 Octasic Inc. All rights reserved.

Description: Contains the identifiers for the RUS_UMTS API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-02.08.00-B1331 (2015/12/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_UMTS_ID_H__
#define __OCTVC1_RUS_UMTS_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_rus_umts_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/

#define cOCTVC1_RUS_UMTS_CID_MAX                        (( 0x03a + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/

#define cOCTVC1_RUS_UMTS_EID_MAX                                          (( 0x0001 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_RUS_UMTS_ID_H__ */

