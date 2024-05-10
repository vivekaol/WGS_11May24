/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_TEST_BASE.h

Copyright (c) 2016 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.00.00-B212 (2016/12/02)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_TEST_BASE_H__
#define __OCTVC1_TEST_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_TEST_UID                        ( 0x05 )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: TEST */
#define cOCTVC1_TEST_CID_BASE                   ( (cOCTVC1_TEST_UID << 16) + cOCTVC1_CID_BASE )
#define cOCTVC1_TEST_RC_BASE                    ( (cOCTVC1_TEST_UID << 16) + cOCTVC1_RC_BASE )

#endif /* __OCTVC1_TEST_BASE_H__ */

