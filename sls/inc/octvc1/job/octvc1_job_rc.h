/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_JOB_RC.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the return codes for the JOB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_JOB_RC_H__
#define OCTVC1_JOB_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"
#include "octvc1_job_base.h"

/****************************************************************************
	JOB return codes
 ****************************************************************************/
#define cOCTVC1_JOB_RC_OBJECT_INVALID						 ( 0x0001 + cOCTVC1_JOB_RC_BASE )
#define cOCTVC1_JOB_RC_SERVICE_UNINITIALIZED				 ( 0x0002 + cOCTVC1_JOB_RC_BASE )

/****************************************************************************
	UNITS return codes
 ****************************************************************************/
#define cOCTVC1_JOB_UNITS_RC_BASE							 ( 0x0010 + cOCTVC1_JOB_RC_BASE )

#define cOCTVC1_JOB_RC_UNITS_PACKAGE_NOT_FOUND				 ( 0x0001 + cOCTVC1_JOB_UNITS_RC_BASE )
#define cOCTVC1_JOB_RC_UNITS_SUITE_NOT_FOUND				 ( 0x0002 + cOCTVC1_JOB_UNITS_RC_BASE )
#define cOCTVC1_JOB_RC_UNITS_CASE_NOT_FOUND					 ( 0x0003 + cOCTVC1_JOB_UNITS_RC_BASE )
#define cOCTVC1_JOB_RC_UNITS_PACKAGE_NAME_TOO_LONG			 ( 0x0004 + cOCTVC1_JOB_UNITS_RC_BASE )
#define cOCTVC1_JOB_RC_UNITS_CASE_NAME_TOO_LONG				 ( 0x0005 + cOCTVC1_JOB_UNITS_RC_BASE )

/****************************************************************************
	RUNNER return codes
 ****************************************************************************/
#define cOCTVC1_JOB_RUNNER_RC_BASE							 ( 0x0020 + cOCTVC1_JOB_RC_BASE )

#define cOCTVC1_JOB_RC_RUNNER_STATE_INVALID					 ( 0x0001 + cOCTVC1_JOB_RUNNER_RC_BASE )
#define cOCTVC1_JOB_RC_RUNNER_CASE_IS_ACTIVE				 ( 0x0002 + cOCTVC1_JOB_RUNNER_RC_BASE )
#define cOCTVC1_JOB_RC_RUNNER_CASE_IS_NOT_ACTIVE			 ( 0x0003 + cOCTVC1_JOB_RUNNER_RC_BASE )
#define cOCTVC1_JOB_RC_RUNNER_REACH_MAXIMUM_CASE			 ( 0x0004 + cOCTVC1_JOB_RUNNER_RC_BASE )
#define cOCTVC1_JOB_RC_RUNNER_CASE_NOT_RUNNING				 ( 0x0005 + cOCTVC1_JOB_RUNNER_RC_BASE )

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_JOB_AUTO_VALIDATE_RC_BASE					 ( 0xF000 + cOCTVC1_JOB_RC_BASE )

#define cOCTVC1_JOB_RC_RUNNER_CASES_PULSE_INVALID_PULSE_CNT	 ( 0x1 + cOCTVC1_JOB_AUTO_VALIDATE_RC_BASE )

#endif /* OCTVC1_JOB_RC_H__ */

