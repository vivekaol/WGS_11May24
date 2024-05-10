/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LICENSING_RC.h

Copyright (c) 2016 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the return codes for the LICENSING API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.00.00-B212 (2016/12/02)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_LICENSING_RC_H__
#define OCTVC1_LICENSING_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_base.h"

/****************************************************************************
	LICENSING return codes
 ****************************************************************************/
#define cOCTVC1_LICENSING_RC_DENIED							 ( 0x0001 + cOCTVC1_LICENSING_RC_BASE )
#define cOCTVC1_LICENSING_RC_INVALID_LICENSE				 ( 0x0002 + cOCTVC1_LICENSING_RC_BASE )

#endif /* OCTVC1_LICENSING_RC_H__ */

