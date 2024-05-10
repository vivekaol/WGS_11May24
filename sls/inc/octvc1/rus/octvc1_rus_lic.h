/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_LIC.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the license ids for the RUS API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_RUS_LIC_H__
#define OCTVC1_RUS_LIC_H__

#include "octvc1_rus_base.h"

/****************************************************************************
	RUS license ids
 ****************************************************************************/
#define cOCTVC1_RUS_LIC_BASS_2G_PHY_ENABLE					 ( 0x0001 + (cOCTVC1_RUS_UID << 16) )
#define cOCTVC1_RUS_LIC_BASS_3G_PHY_ENABLE					 ( 0x0002 + (cOCTVC1_RUS_UID << 16) )
#define cOCTVC1_RUS_LIC_BASS_4G_PHY_ENABLE					 ( 0x0003 + (cOCTVC1_RUS_UID << 16) )
#define cOCTVC1_RUS_LIC_BASS_ALL_PHY_ENABLE					 ( 0x0004 + (cOCTVC1_RUS_UID << 16) )
#define cOCTVC1_RUS_LIC_RF_TOOLS_ENABLE						 ( 0x0005 + (cOCTVC1_RUS_UID << 16) + ( 0x1 << 24 )  )
#define cOCTVC1_RUS_LIC_SCAN_SPEED_FAST_ENABLE				 ( 0x0006 + (cOCTVC1_RUS_UID << 16) )
#define cOCTVC1_RUS_LIC_SCAN_THRESHOLD_VALUE				 ( 0x0007 + (cOCTVC1_RUS_UID << 16) )
#define cOCTVC1_RUS_LIC_SCAN_NR_ENABLE						 ( 0x0008 + (cOCTVC1_RUS_UID << 16) )

#endif /* OCTVC1_RUS_LIC_H__ */

