/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_UMTS_API.h

Copyright (c) 2015 Octasic Inc. All rights reserved.

Description: Contains the definition of the RUS_UMTS API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-02.08.00-B1331 (2015/12/16)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_UMTS_API_H__
#define __OCTVC1_RUS_UMTS_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"

#include "octvc1_rus_umts_id.h"
#include "octvc1_rus_umts_rc.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	RUS API constant definitions
 	TEST
-------------------------------------------------------------------------------------*/

#define cOCTVC1_RUS_UMTS_FILE_NAME_MAX_LENGTH				127		 	/* Filesystem string length restriction. */

/*****************************  METHODS  *************************************/

/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_rus_umts_evt.h"

#endif /* __OCTVC1_RUS_UMTS_API_H__ */

