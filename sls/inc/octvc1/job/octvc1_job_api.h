/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_JOB_API.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the JOB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_JOB_API_H__
#define __OCTVC1_JOB_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_user_id.h"

#include "octvc1_job_id.h"
#include "octvc1_job_rc.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Job API constant definitions
-------------------------------------------------------------------------------------*/

#define cOCTVC1_JOB_DESCR_MAX_LENGTH						127		 	/* Maximum char in job description string. */
#define cOCTVC1_JOB_USAGE_MAX_LENGTH						127		 	/* Maximum char in job description string. */
#define cOCTVC1_JOB_PARMS_MAX_LENGTH						511		 	/* Maximum char in job parameters string. */
#define cOCTVC1_JOB_DATA_MAX_LENGTH							511		 	/* Maximum char in job data input string. */
#define cOCTVC1_JOB_DATA_USER_VALUE_MAX_LENGTH				4		 	/* Maximum uint32 in job data user array. */
#define cOCTVC1_JOB_RUNNER_JOB_MAX_OBJ						8		 	/* Maximum object handle to pass as job parameter. */
#define cOCTVC1_JOB_RUNNER_JOB_STATS_MAX_LENGTH				128		 	/* Maximum number of char in szStats. */
#define cOCTVC1_JOB_RUNNER_JOB_RESULT_MAX_LENGTH			128		 	/* Maximum number of char in szStats. */
#define cOCTVC1_JOB_PACKAGE_NAME_MAX_LENGTH					31		
#define cOCTVC1_JOB_SUITE_NAME_MAX_LENGTH					31		
#define cOCTVC1_JOB_RUNNER_CASE_PENDING_PULSE_COUNT_FOREVER	0xFFFFFFFF	 	/* Pending pulse forever */
#define cOCTVC1_JOB_RUNNER_CASE_STATS_MAX_LENGTH			1023	 	/* Maximum number of char in szStats. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_UNITS_SUITE_INFO

 Members:
	szPackageName
 		Job package name.
	szSuiteName
 		Job suite name.
	ulCaseCount
 		Number of job-unit-case in this package-suite.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_INT8	szPackageName[(cOCTVC1_JOB_PACKAGE_NAME_MAX_LENGTH+1)];
	tOCT_INT8	szSuiteName[(cOCTVC1_JOB_SUITE_NAME_MAX_LENGTH+1)];
	tOCT_UINT32	ulCaseCount;

} tOCTVC1_JOB_UNITS_SUITE_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_UNITS_CASE_INFO

 Members:
	szCaseName
 		Job name string (Array of bytes) .
 		The buffer name can be up to cOCTVC1_JOB_NAME_MAX_LENGTH characters long,
 		excluding the terminating NULL character.
	szDescription
 		Job description string (Array of bytes) .
	szUsage
 		Job usage description .
 		The buffer name can be up to cOCTVC1_JOB_USAGE_MAX_LENGTH characters long,
 		excluding the terminating NULL character.
	ulProcessUserId
 		Process User identifier responsible to run this unit-case.
	ulInteractiveFlag
 		Weather or not this job MUST be interactive.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_INT8						szCaseName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];
	tOCT_INT8						szDescription[(cOCTVC1_JOB_DESCR_MAX_LENGTH+1)];
	tOCT_INT8						szUsage[(cOCTVC1_JOB_USAGE_MAX_LENGTH+1)];
	tOCTVC1_USER_ID_PROCESS_ENUM	ulProcessUserId;
	tOCT_BOOL32						ulInteractiveFlag;

} tOCTVC1_JOB_UNITS_CASE_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_UNITS_CASE_EXEC_PARMS

 Members:
	ulPulseModeFlag
		Default:	cOCT_FALSE
 		Pulse enable flag
 		If cOCT_TRUE, the test will be used in pulse mode
 		Host application need to send pulse to make run test process
	szParms
 		NULL terminated string.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_BOOL32	ulPulseModeFlag;
	tOCT_INT8	szParms[(cOCTVC1_JOB_PARMS_MAX_LENGTH+1)];

} tOCTVC1_JOB_UNITS_CASE_EXEC_PARMS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_DATA

 Members:
	aulUserData
 		array 32 bits array allow user pass any value
	szData
 		NULL terminated string.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	aulUserData[cOCTVC1_JOB_DATA_USER_VALUE_MAX_LENGTH];
	tOCT_INT8	szData[(cOCTVC1_JOB_DATA_MAX_LENGTH+1)];

} tOCTVC1_JOB_RUNNER_CASE_DATA;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_ADD_PARMS

 Members:
	hPkgSuite
	ulCaseId
	ExecParms
 		Case execution parameters.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT				hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID				ulCaseId;
	tOCTVC1_JOB_UNITS_CASE_EXEC_PARMS	ExecParms;

} tOCTVC1_JOB_RUNNER_CASE_ADD_PARMS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_INFO

 Members:
	hPkgSuite
	ulCaseId
	ExecParms
 		Case execution parameters.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT				hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID				ulCaseId;
	tOCTVC1_JOB_UNITS_CASE_EXEC_PARMS	ExecParms;

} tOCTVC1_JOB_RUNNER_CASE_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_STATE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_JOB_RUNNER_STATE_ENUM						tOCT_UINT32

#define cOCTVC1_JOB_RUNNER_STATE_ENUM_UNINITIALIZED			0		
#define cOCTVC1_JOB_RUNNER_STATE_ENUM_IDLE					1		
#define cOCTVC1_JOB_RUNNER_STATE_ENUM_STARTED				2		
#define cOCTVC1_JOB_RUNNER_STATE_ENUM_PAUSE					3		
#define cOCTVC1_JOB_RUNNER_STATE_ENUM_ERROR					4		
#define cOCTVC1_JOB_RUNNER_STATE_ENUM_WAIT_NEXT				5		
#define cOCTVC1_JOB_RUNNER_STATE_ENUM_INTERNAL_PROCESSING	6		

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_METRIC_INDEX_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_JOB_RUNNER_CASE_METRIC_INDEX_ENUM			tOCT_UINT32

#define cOCTVC1_JOB_RUNNER_CASE_METRIC_INDEX_ENUM_0			0		
#define cOCTVC1_JOB_RUNNER_CASE_METRIC_INDEX_ENUM_1			1		
#define cOCTVC1_JOB_RUNNER_CASE_METRIC_INDEX_ENUM_2			2		
#define cOCTVC1_JOB_RUNNER_CASE_METRIC_INDEX_ENUM_3			3		

#define cOCTVC1_JOB_RUNNER_CASE_METRIC_STATS_MAX_LENGTH		4		
#define cOCTVC1_JOB_RUNNER_CASE_METRIC_USER_VALUE_MAX_LENGTH	4		

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_METRIC_POINT_STATS

 Members:
	ulUserId
 		User Id
	ulExecCnt
 		Number of times the metric has been executed
	ulTotalExecTimeUs
 		Metric point's total execution time (in microseconds)
	ulLastExecTimeUs
 		Metric point's execution time (in microseconds) of last iteration
	ulMaxExecTimeUs
 		Metric point's longest execution time (in microseconds)
	ulMaxExecTimeIterationNum
 		Metric point's iteration number where ulMaxExecTimeUs was been set
	ulTotalCacheMissCnt
 		Metric point's last execution cache miss count
	ulLastExecCacheMissCnt
 		Metric point's cache miss in the last execution
	ulMaxExecCacheMissCnt
 		Metric point's maximum cache miss in one execution
	ulMaxExecCacheMissIterationNum
 		Metric point's iteration number where ulMaxExecCacheMissCnt was been set
	aulUserValue
 		Array of user value
 		This allow user specify metric for a job
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulUserId;
	tOCT_UINT32	ulExecCnt;
	tOCT_UINT32	ulTotalExecTimeUs;
	tOCT_UINT32	ulLastExecTimeUs;
	tOCT_UINT32	ulMaxExecTimeUs;
	tOCT_UINT32	ulMaxExecTimeIterationNum;
	tOCT_UINT32	ulTotalCacheMissCnt;
	tOCT_UINT32	ulLastExecCacheMissCnt;
	tOCT_UINT32	ulMaxExecCacheMissCnt;
	tOCT_UINT32	ulMaxExecCacheMissIterationNum;
	tOCT_UINT32	aulUserValue[cOCTVC1_JOB_RUNNER_CASE_METRIC_USER_VALUE_MAX_LENGTH];

} tOCTVC1_JOB_RUNNER_CASE_METRIC_POINT_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_STATE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_JOB_RUNNER_CASE_STATE_ENUM					tOCT_UINT32

#define cOCTVC1_JOB_RUNNER_CASE_STATE_ENUM_IDLE				0		
#define cOCTVC1_JOB_RUNNER_CASE_STATE_ENUM_PENDING			1		
#define cOCTVC1_JOB_RUNNER_CASE_STATE_ENUM_DISABLE			2		
#define cOCTVC1_JOB_RUNNER_CASE_STATE_ENUM_RUNNING			3		
#define cOCTVC1_JOB_RUNNER_CASE_STATE_ENUM_PASS				4		
#define cOCTVC1_JOB_RUNNER_CASE_STATE_ENUM_SKIP				5		
#define cOCTVC1_JOB_RUNNER_CASE_STATE_ENUM_ERROR			6		

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_STATS

 Members:
	ulState
	ulErrorCode
	ulExecCnt
 		Number of times test processing function has been executed
	ulPendingPulseCnt
 		Number of pending times must be call processing function has been executed
 		If egal to cOCTVC1_JOB_RUNNER_CASE_PENDING_ITERATION_CNT_FOREVER, means in
 		standard mode
 		If different from cOCTVC1_JOB_RUNNER_CASE_PENDING_ITERATION_CNT_FOREVER, means
 		in pulse mode
 		Host application need to send cOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CID to make
 		the job run
	szStats
 		String (Array of bytes) containing the parameter of transport remote
 		destination parameter.
 		The buffer name can be up to cOCTVC1_JOB_RUNNER_JOB_STATS_MAX_LENGTH characters
 		long, excluding the terminating NULL character.
	aMetricStats
 		Array of runner job case metric's stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_JOB_RUNNER_CASE_STATE_ENUM			ulState;
	tOCT_UINT32									ulErrorCode;
	tOCT_UINT32									ulExecCnt;
	tOCT_UINT32									ulPendingPulseCnt;
	tOCT_INT8									szStats[(cOCTVC1_JOB_RUNNER_JOB_STATS_MAX_LENGTH+1)];
	tOCTVC1_JOB_RUNNER_CASE_METRIC_POINT_STATS	aMetricStats[cOCTVC1_JOB_RUNNER_CASE_METRIC_STATS_MAX_LENGTH];

} tOCTVC1_JOB_RUNNER_CASE_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_RUNNER_CASE_LEVEL_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_JOB_RUNNER_CASE_LEVEL_ENUM					tOCT_UINT32

#define cOCTVC1_JOB_RUNNER_CASE_LEVEL_ENUM_NORMAL			0		
#define cOCTVC1_JOB_RUNNER_CASE_LEVEL_ENUM_FAST				1		
#define cOCTVC1_JOB_RUNNER_CASE_LEVEL_ENUM_FULL				2		

/*****************************  METHODS  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_LIST_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_JOB_MSG_UNITS_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_LIST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
	ObjectNameList
 		Object32 named list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_NAME_OBJECT32_GET		ObjectNameList;

} tOCTVC1_JOB_MSG_UNITS_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_START_ALL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulStartCount
 		Number of started job-unit-case.
	ulErrorCount
 		Number of started error.
	ulDisableCount
 		Number of disabled job-unit.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulStartCount;
	tOCT_UINT32			ulErrorCount;
	tOCT_UINT32			ulDisableCount;

} tOCTVC1_JOB_MSG_UNITS_START_ALL_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
 		Job Package-Suites identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;

} tOCTVC1_JOB_MSG_UNITS_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
 		Job Descriptor identifier.
	SuiteInfo
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hPkgSuite;
	tOCTVC1_JOB_UNITS_SUITE_INFO	SuiteInfo;

} tOCTVC1_JOB_MSG_UNITS_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_FIND_CMD

 Members:
	Header
 		OCTVC1 Message Header
	szPackageName
 		Job package name.
 		Can be default value if requesting by handle.
	szSuiteName
 		Job suite name.
 		Can be default value if requesting by handle.
	szCaseName
 		Case name string to retreive.
 		Can be empty if only requesting the UNIT_SUITE_INFO.
	hPackSuite
		Default:	cOCTVC1_DO_NOT_MODIFY
 		PkgSuite to retreive.
 		Can be default value if requesting by string.
	ulCaseId
		Default:	cOCTVC1_DO_NOT_MODIFY
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCT_INT8				szPackageName[(cOCTVC1_JOB_PACKAGE_NAME_MAX_LENGTH+1)];
	tOCT_INT8				szSuiteName[(cOCTVC1_JOB_SUITE_NAME_MAX_LENGTH+1)];
	tOCT_INT8				szCaseName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];
	tOCTVC1_HANDLE_OBJECT	hPackSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;

} tOCTVC1_JOB_MSG_UNITS_FIND_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_FIND_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
 		Job Descriptor identifier.
	ulCaseId
	szPackageName
 		Job package name.
	szSuiteName
 		Job suite name.
	szCaseName
 		Case name string to retreive.
 		Can be empty if only requesting the UNIT_SUITE_INFO.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;
	tOCT_INT8				szPackageName[(cOCTVC1_JOB_PACKAGE_NAME_MAX_LENGTH+1)];
	tOCT_INT8				szSuiteName[(cOCTVC1_JOB_SUITE_NAME_MAX_LENGTH+1)];
	tOCT_INT8				szCaseName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];

} tOCTVC1_JOB_MSG_UNITS_FIND_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_START_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
 		Job Package-Suites identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;

} tOCTVC1_JOB_MSG_UNITS_START_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_START_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
 		Job Package-Suites identifier.
	ulStartCount
 		Number of started job-unit-case.
	ulErrorCount
 		Number of started error.
	ulDisableCount
 		Number of disabled job-unit.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCT_UINT32				ulStartCount;
	tOCT_UINT32				ulErrorCount;
	tOCT_UINT32				ulDisableCount;

} tOCTVC1_JOB_MSG_UNITS_START_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;

} tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_LIST_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	ObjectNameList
 		Object List structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID	SubObjectIdGet;
	tOCTVC1_LIST_NAME_OBJECT32_GET					ObjectNameList;

} tOCTVC1_JOB_MSG_UNITS_LIST_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;

} tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_INFO_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
	CaseInfo
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID		ulCaseId;
	tOCTVC1_JOB_UNITS_CASE_INFO	CaseInfo;

} tOCTVC1_JOB_MSG_UNITS_INFO_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;

} tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_STATS_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
	ulEnableStateFlag
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;
	tOCT_BOOL32				ulEnableStateFlag;

} tOCTVC1_JOB_MSG_UNITS_STATS_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
	ulEnableStateFlag
		Default:	cOCTVC1_DO_NOT_MODIFY
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;
	tOCT_BOOL32				ulEnableStateFlag;

} tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;

} tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD
 		This command adds a job in the job runner engine.

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
	ExecParms
 		Case execution parameters.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_HANDLE_OBJECT				hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID				ulCaseId;
	tOCTVC1_JOB_UNITS_CASE_EXEC_PARMS	ExecParms;

} tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_UNITS_START_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hPkgSuite
	ulCaseId
	hRunnerCase
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hPkgSuite;
	tOCTVC1_SUB_OBJECT_ID	ulCaseId;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_UNITS_START_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
	Data
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRunnerCase;
	tOCTVC1_JOB_RUNNER_CASE_DATA	Data;

} tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_BOOL32			ulResetStatsFlag;

} tOCTVC1_JOB_MSG_RUNNER_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulCaseCount
 		Number of job-unit-case to run.
	ulExecutedCount
 		Number of job-unit-case executed.
	ulErrorCount
 		Number of job-unit-case executed with error.
	ulCaseMaxCount
 		Maximum number of job-unit-case to run.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulCaseCount;
	tOCT_UINT32			ulExecutedCount;
	tOCT_UINT32			ulErrorCount;
	tOCT_UINT32			ulCaseMaxCount;

} tOCTVC1_JOB_MSG_RUNNER_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_PAUSE_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_PAUSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_RESUME_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_RESUME_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD
 		Remove all job case.

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_CLEANUP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulRemoveCount
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulRemoveCount;

} tOCTVC1_JOB_MSG_RUNNER_CLEANUP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD
 		This command adds a job in the runner server to the server.

 Members:
	Header
 		OCTVC1 Message Header
	RunnerAddParms
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_JOB_RUNNER_CASE_ADD_PARMS	RunnerAddParms;

} tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
	szDisplayName
 		Descriptor Job name string (Array of bytes) .
 		The buffer name can be up to cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH characters
 		long, excluding the terminating NULL character.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;
	tOCT_INT8				szDisplayName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];

} tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
	ObjectNameList
 		Object List structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_NAME_OBJECT32_GET		ObjectNameList;

} tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD
 		Remove this job case.

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
	Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRunnerCase;
	tOCTVC1_JOB_RUNNER_CASE_INFO	Info;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRunnerCase;
	tOCTVC1_JOB_RUNNER_CASE_STATS	Stats;

} tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_START_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_START_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
	ulPulseCnt
		Range:		[1..(cOCTVC1_JOB_RUNNER_CASE_PENDING_PULSE_COUNT_FOREVER-1)]
		Default:	1
 		Number of pulse job must process will be executed.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;
	tOCT_UINT32				ulPulseCnt;

} tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD
 		Remove all job case.

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulRemoveCount
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulRemoveCount;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
	ObjectNameList
 		Object List structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_NAME_OBJECT32_GET		ObjectNameList;

} tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD
 		Remove this job case.

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
	Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRunnerCase;
	tOCTVC1_JOB_RUNNER_CASE_INFO	Info;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRunnerCase;
	tOCTVC1_JOB_RUNNER_CASE_STATS	Stats;

} tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD
 		Remove all job case.

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulRemoveCount
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulRemoveCount;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
	ObjectNameList
 		Object List structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_NAME_OBJECT32_GET		ObjectNameList;

} tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD
 		Remove this job case.

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
	Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRunnerCase;
	tOCTVC1_JOB_RUNNER_CASE_INFO	Info;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Job case identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hRunnerCase;

} tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hRunnerCase
 		Job case identifier.
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hRunnerCase;
	tOCTVC1_JOB_RUNNER_CASE_STATS	Stats;

} tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD
 		Remove all job case.

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulRemoveCount
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulRemoveCount;

} tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
	ObjectList
 		Object List structure.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hExecutor
		Default:	cOCTVC1_HANDLE_INVALID
 		Executor handle identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hExecutor;

} tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hExecutor
 		Executor handle identifier.
	hProcess
 		Process handle identifier.
	ulUserId
 		Process user identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hExecutor;
	tOCTVC1_HANDLE_OBJECT			hProcess;
	tOCTVC1_USER_ID_PROCESS_ENUM	ulUserId;

} tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hExecutor
		Default:	cOCTVC1_HANDLE_INVALID
 		Executor handle identifier.
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hExecutor;
	tOCT_BOOL32				ulResetStatsFlag;

} tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hExecutor
 		Executor handle identifier.
	ulState
	hActiveCase
		Default:	cOCTVC1_HANDLE_INVALID
 		Current running job case identifier.
	ulExecutedCount
 		Number of job-unit-case executed.
	ulErrorCount
 		Number of job-unit-case executed with error.
	szCaseName
 		Active unit job case.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hExecutor;
	tOCTVC1_JOB_RUNNER_STATE_ENUM	ulState;
	tOCTVC1_HANDLE_OBJECT			hActiveCase;
	tOCT_UINT32						ulExecutedCount;
	tOCT_UINT32						ulErrorCount;
	tOCT_INT8						szCaseName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];

} tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulRunnerCaseLevel
 		Specify the runner level. Some job may change the number of iteration base on
 		this setting.
	ulSendStateChangeEvtFlag
 		Specify to send runner executor state change events.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_JOB_RUNNER_CASE_LEVEL_ENUM	ulRunnerCaseLevel;
	tOCT_BOOL32							ulSendStateChangeEvtFlag;

} tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulRunnerCaseLevel
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Specify the runner level. Some job may change the number of iteration base on
 		this setting.
	ulSendStateChangeEvtFlag
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Specify to send runner executor state change events.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_JOB_RUNNER_CASE_LEVEL_ENUM	ulRunnerCaseLevel;
	tOCT_BOOL32							ulSendStateChangeEvtFlag;

} tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_RSP;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_job_evt.h"

#endif /* __OCTVC1_JOB_API_H__ */

