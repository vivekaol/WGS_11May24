/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_BASE.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_3G_NODEB_BASE_H__
#define __OCTVC1_3G_NODEB_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_UID                    ( 0x0D )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: 3G_NODEB */
#define cOCTVC1_3G_NODEB_CID_BASE               ( (cOCTVC1_3G_NODEB_UID << 16) + cOCTVC1_CID_BASE )
#define cOCTVC1_3G_NODEB_EID_BASE               ( (cOCTVC1_3G_NODEB_UID << 16) + cOCTVC1_EID_BASE )
#define cOCTVC1_3G_NODEB_RC_BASE                ( (cOCTVC1_3G_NODEB_UID << 16) + cOCTVC1_RC_BASE )

#endif /* __OCTVC1_3G_NODEB_BASE_H__ */

