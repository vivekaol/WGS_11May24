/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_TEST_API.h

Copyright (c) 2016 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the TEST API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.00.00-B212 (2016/12/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_TEST_API_H__
#define __OCTVC1_TEST_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"

#include "octvc1_test_id.h"
#include "octvc1_test_rc.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Test API constant definitions
-------------------------------------------------------------------------------------*/

#define cOCTVC1_TEST_DESCR_MAX_LENGTH						127		 	/* Maximum char in test description string. */
#define cOCTVC1_TEST_USAGE_MAX_LENGTH						511		 	/* Maximum char in test description string. */
#define cOCTVC1_TEST_PARMS_MAX_LENGTH						511		 	/* Maximum char in test parameters string. */
#define cOCTVC1_TEST_RUNNER_TEST_MAX_OBJ					8		 	/* Maximum object handle to pass as test parameter. */
#define cOCTVC1_TEST_RUNNER_TEST_STATS_MAX_LENGTH			1023	 	/* Maximum number of char in szStats. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_TEST_EXEC_PARMS

 Members:
	ahObj
 		Object handle to pass as test parameter.
 		See Test Descriptor Usage for more information.
	szParms
 		String Test parameter.
 		The buffer name can be up to cOCTVC1_TEST_PARMS_MAX_LENGTH characters long,
 		excluding the terminating NULL character.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT	ahObj[cOCTVC1_TEST_RUNNER_TEST_MAX_OBJ];
	tOCT_INT8				szParms[(cOCTVC1_TEST_PARMS_MAX_LENGTH+1)];

} tOCTVC1_TEST_EXEC_PARMS;

/*****************************  METHODS  *************************************/

/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/

#endif /* __OCTVC1_TEST_API_H__ */

