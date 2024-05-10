/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_VERSION.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the version of the 3G_NODEB API interface.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_3G_NODEB_VERSION_H__
#define __OCTVC1_3G_NODEB_VERSION_H__

#include "../octvc1_api.h"

/* The version ID is separated into the following sections:

      bit[31:27]:    Major version
      bit[26:21]:    Minor version
      bit[20:15]:    Bug fix version
      bit[14:0]:     Build number
*/
#define cOCTVC1_3G_NODEB_VERSION_MAJOR		3
#define cOCTVC1_3G_NODEB_VERSION_MINOR		2
#define cOCTVC1_3G_NODEB_VERSION_MAINTENANCE	0
#define cOCTVC1_3G_NODEB_VERSION_BUILD		489

#define cOCTVC1_3G_NODEB_VERSION_ID             ( (cOCTVC1_3G_NODEB_VERSION_MAJOR << cOCTVC1_API_VERSION_MASK_MAJOR_BIT_OFFSET) + \
                                                  (cOCTVC1_3G_NODEB_VERSION_MINOR << cOCTVC1_API_VERSION_MASK_MINOR_BIT_OFFSET) + \
                                                  (cOCTVC1_3G_NODEB_VERSION_MAINTENANCE << cOCTVC1_API_VERSION_MASK_MAINTENANCE_BIT_OFFSET) + \
                                                  (cOCTVC1_3G_NODEB_VERSION_BUILD << cOCTVC1_API_VERSION_MASK_BUILD_BIT_OFFSET ) )

#endif /* __OCTVC1_3G_NODEB_VERSION_H__ */

