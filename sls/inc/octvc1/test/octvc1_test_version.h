/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_TEST_VERSION.h

Copyright (c) 2016 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the version of the TEST API interface.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.00.00-B212 (2016/12/02)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_TEST_VERSION_H__
#define __OCTVC1_TEST_VERSION_H__


/* The version ID is separated into the following sections:

      bit[31:25]:    Major version
      bit[24:18]:    Minor version
      bit[17:11]:    Bug fix version
      bit[10:0]:     Build number
*/
#define cOCTVC1_TEST_VERSION_MAJOR              1
#define cOCTVC1_TEST_VERSION_MINOR		0
#define cOCTVC1_TEST_VERSION_MAINTENANCE	0
#define cOCTVC1_TEST_VERSION_BUILD		212

#define cOCTVC1_TEST_VERSION_ID                 ( (cOCTVC1_TEST_VERSION_MAJOR << 25) + \
                                                  (cOCTVC1_TEST_VERSION_MINOR << 18) + \
                                                  (cOCTVC1_TEST_VERSION_MAINTENANCE << 11) + \
                                                  cOCTVC1_TEST_VERSION_BUILD )

#endif /* __OCTVC1_TEST_VERSION_H__ */

