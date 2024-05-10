/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_GSM_VERSION.h

Copyright (c) 2015 Octasic Inc. All rights reserved.

Description: Contains the version of the RUS_GSM API interface.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-02.08.00-B1331 (2015/12/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_GSM_VERSION_H__
#define __OCTVC1_RUS_GSM_VERSION_H__


/* The version ID is separated into the following sections:

      bit[31:25]:    Major version
      bit[24:18]:    Minor version
      bit[17:11]:    Bug fix version
      bit[10:0]:     Build number
*/
#define cOCTVC1_RUS_GSM_VERSION_MAJOR		2
#define cOCTVC1_RUS_GSM_VERSION_MINOR		8
#define cOCTVC1_RUS_GSM_VERSION_MAINTENANCE	0
#define cOCTVC1_RUS_GSM_VERSION_BUILD		1331

#define cOCTVC1_RUS_GSM_VERSION_ID              ( (cOCTVC1_RUS_GSM_VERSION_MAJOR << 25) + \
                                                  (cOCTVC1_RUS_GSM_VERSION_MINOR << 18) + \
                                                  (cOCTVC1_RUS_GSM_VERSION_MAINTENANCE << 11) + \
                                                  cOCTVC1_RUS_GSM_VERSION_BUILD )

#endif /* __OCTVC1_RUS_GSM_VERSION_H__ */

