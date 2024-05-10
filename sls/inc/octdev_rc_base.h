/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTDEV_RC_BASE.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTDEV_RC_BASE_H__
#define __OCTDEV_RC_BASE_H__


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Gemeric Return Code bases
-------------------------------------------------------------------------------------*/

#define cOCTADF_TARGET_RC_BASE								0x01000000	
#define cOCTVC1_API_RC_BASE									0x0A000000	
#define cOCTCOMMON_API_RC_BASE								0x0E000000	
#define cOCTDEVICE_API_RC_BASE								0x0F000000	

/*-------------------------------------------------------------------------------------
 	Return Code fatal flag
-------------------------------------------------------------------------------------*/

#define cOCTDEV_RC_FATAL_FLAG								0x80000000	

#endif /* __OCTDEV_RC_BASE_H__ */

