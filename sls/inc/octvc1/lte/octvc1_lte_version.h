/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LTE_VERSION.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the version of the LTE API interface.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_LTE_APP-04.03.00-B3607 (2019/04/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_LTE_VERSION_H__
#define __OCTVC1_LTE_VERSION_H__

#include "../octvc1_api.h"

/* The version ID is separated into the following sections:

      bit[31:27]:    Major version
      bit[26:21]:    Minor version
      bit[20:15]:    Bug fix version
      bit[14:0]:     Build number
*/
#define cOCTVC1_LTE_VERSION_MAJOR		4
#define cOCTVC1_LTE_VERSION_MINOR		4
#define cOCTVC1_LTE_VERSION_MAINTENANCE	2
#define cOCTVC1_LTE_VERSION_BUILD		3652

#define cOCTVC1_LTE_VERSION_ID                  ( (cOCTVC1_LTE_VERSION_MAJOR << cOCTVC1_API_VERSION_MASK_MAJOR_BIT_OFFSET) + \
                                                  (cOCTVC1_LTE_VERSION_MINOR << cOCTVC1_API_VERSION_MASK_MINOR_BIT_OFFSET) + \
                                                  (cOCTVC1_LTE_VERSION_MAINTENANCE << cOCTVC1_API_VERSION_MASK_MAINTENANCE_BIT_OFFSET) + \
                                                  (cOCTVC1_LTE_VERSION_BUILD << cOCTVC1_API_VERSION_MASK_BUILD_BIT_OFFSET ) )

#endif /* __OCTVC1_LTE_VERSION_H__ */

