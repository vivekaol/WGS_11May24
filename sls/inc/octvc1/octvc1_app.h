/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_APP.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the OCTVC1 API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_APP_H__
#define __OCTVC1_APP_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
/****************************************************************************
	Generic application definitions
 ****************************************************************************/

#define cOCTVC1_APP_COMPANY_NAME			"Octasic"
#define cOCTVC1_APP_PRODUCT_NAME			"Radio Utility System"
#define cOCTVC1_APP_PRODUCT_SHORT_NAME			"octsdr_rus"
#define cOCTVC1_APP_PRODUCT_GOOSE_ROOT_NAME			"octsdr"
#define cOCTVC1_APP_VERSION_MAJOR			5
#define cOCTVC1_APP_VERSION_MINOR			1
#define cOCTVC1_APP_VERSION_MAINTENANCE			5
#define cOCTVC1_APP_VERSION_BUILD		3782
#define cOCTVC1_APP_VERSION_ID			((cOCTVC1_APP_VERSION_MAJOR << 25) + \
								(cOCTVC1_APP_VERSION_MINOR << 18) + \
								(cOCTVC1_APP_VERSION_MAINTENANCE << 11) + \
								(cOCTVC1_APP_VERSION_BUILD) ) 

#endif /* __OCTVC1_APP_H__ */

