/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_PKT_API_VERSION.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description:

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_PKT_API_VERSION_H__
#define __OCTVC1_PKT_API_VERSION_H__

/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/
/* The version ID is separated into the following sections:

      bit[31:25]:    Major version
      bit[24:18]:    Minor version
      bit[17:11]:    Bug fix version
      bit[10:0]:     Build number
*/
#define cOCTVC1_PKT_API_VERSION_MAJOR		5
#define cOCTVC1_PKT_API_VERSION_MINOR		2
#define cOCTVC1_PKT_API_VERSION_MAINTENANCE	2
#define cOCTVC1_PKT_API_VERSION_BUILD		3642

#define cOCTVC1_PKT_API_VERSION_ID       ( (cOCTVC1_PKT_API_VERSION_MAJOR << 25) + \
										 (cOCTVC1_PKT_API_VERSION_MINOR << 18) + \
                                         (cOCTVC1_PKT_API_VERSION_MAINTENANCE << 11) + \
                                         cOCTVC1_PKT_API_VERSION_BUILD )

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_PKT_API_VERSION_H__*/
