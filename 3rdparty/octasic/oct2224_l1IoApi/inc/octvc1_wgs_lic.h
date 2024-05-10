/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_WGS_LIC.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the license ids for the RUS API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit 

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_WGS_LIC_H__
#define OCTVC1_WGS_LIC_H__

#define cOCTVC1_WGS_UID 0x09

/****************************************************************************
	WGS license ids
 ****************************************************************************/
#define cOCTVC1_WGS_LIC_INTERNAL_ENABLE					 ( 0x0001 + (cOCTVC1_WGS_UID << 12) )
#define cOCTVC1_WGS_LIC_LTE_FDD_ENABLE					 ( 0x0002 + (cOCTVC1_WGS_UID << 12) )
#define cOCTVC1_WGS_LIC_LTE_TDD_ENABLE					 ( 0x0003 + (cOCTVC1_WGS_UID << 12) )
#define cOCTVC1_PORTIA_LIC_ACE_ENABLE					 ( 0x0004 + (cOCTVC1_WGS_UID << 12) )
#define cOCTVC1_PORTIA_LIC_PRO_ENABLE					 ( 0x0005 + (cOCTVC1_WGS_UID << 12) )

#endif /* OCTVC1_WGS_LIC_H__ */


