/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTOSAL_VERSION.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: OS Abstraction layer API

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.16.00-B304 (2018/05/02)

$Octasic_Revision: 1 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/



#ifndef __OCTOSAL_VERSION_H__
#define __OCTOSAL_VERSION_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../../sls/inc/octdev_types.h"


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/* The version ID is separated into the following sections:

      bit[31:25]:    Major version
      bit[24:18]:    Minor version
      bit[17:11]:    Bug fix version
      bit[10:0]:     Build number
*/
#define cOCTOSAL_VERSION_MAJOR              0
#define cOCTOSAL_VERSION_MINOR              0
#define cOCTOSAL_VERSION_MAINTENANCE        0
#define cOCTOSAL_VERSION_BUILD              0

#define cOCTOSAL_VERSION_ID         ( (cOCTOSAL_VERSION_MAJOR << 25) + \
										 (cOCTOSAL_VERSION_MINOR << 18) + \
                                         (cOCTOSAL_VERSION_MAINTENANCE << 11) + \
                                         cOCTOSAL_VERSION_BUILD )


/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTOSAL_VERSION_H__ */
