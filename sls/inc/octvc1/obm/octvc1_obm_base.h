/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_BASE.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.5.0-B393 (07/02/2018)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_OBM_BASE_H__
#define __OCTVC1_OBM_BASE_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"

/****************************************************************************
	Module unique identifiers
 ****************************************************************************/
#define cOCTVC1_OBM_UID                         ( 0x08 )

/****************************************************************************
	Module identifier bases
 ****************************************************************************/

/* Module: OBM */
#define cOCTVC1_OBM_CID_BASE                    ( (cOCTVC1_OBM_UID << 16) + cOCTVC1_CID_BASE )
#define cOCTVC1_OBM_EID_BASE                    ( (cOCTVC1_OBM_UID << 16) + cOCTVC1_EID_BASE )
#define cOCTVC1_OBM_RC_BASE                     ( (cOCTVC1_OBM_UID << 16) + cOCTVC1_RC_BASE )

#endif /* __OCTVC1_OBM_BASE_H__ */

