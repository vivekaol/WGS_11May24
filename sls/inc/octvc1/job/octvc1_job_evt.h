/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_JOB_EVT.h
Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the JOB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_JOB_EVT_H__
#define __OCTVC1_JOB_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_job_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_EXECUTOR_STATE_CHANGE_EVT

 Members:
	Header
 		OCTVC1 Event Header
	hExecutor
 		Executor handle identifier.
	hActiveCase
 		Current running job case identifier.
	szPackageName
 		Job package name.
	szSuiteName
 		Job suite name.
	szCaseName
 		Active unit job case.
	ulOldState
	ulNewState
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT				hExecutor;
	tOCTVC1_HANDLE_OBJECT				hActiveCase;
	tOCT_INT8							szPackageName[(cOCTVC1_JOB_PACKAGE_NAME_MAX_LENGTH+1)];
	tOCT_INT8							szSuiteName[(cOCTVC1_JOB_SUITE_NAME_MAX_LENGTH+1)];
	tOCT_INT8							szCaseName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];
	tOCTVC1_JOB_RUNNER_CASE_STATE_ENUM	ulOldState;
	tOCTVC1_JOB_RUNNER_CASE_STATE_ENUM	ulNewState;

} tOCTVC1_JOB_MSG_RUNNER_EXECUTOR_STATE_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_EXECUTOR_ITERATION_EVT

 Members:
	Header
 		OCTVC1 Event Header
	hExecutor
 		Executor handle identifier.
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCTVC1_HANDLE_OBJECT	hExecutor;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_EXECUTOR_ITERATION_EVT;


#endif /* __OCTVC1_JOB_EVT_H__ */

