/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_MAIN_EVT.h
Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the MAIN API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_MAIN_EVT_H__
#define __OCTVC1_MAIN_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_main_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
	tOCTVC1_MAIN_EVT_PHY_MASK : 	Phy Events.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_MAIN_EVT_PHY_MASK							tOCT_UINT32

#define cOCTVC1_MAIN_EVT_PHY_MASK_UP						((tOCT_UINT32)(1<<0) )	
#define cOCTVC1_MAIN_EVT_PHY_MASK_DOWN						((tOCT_UINT32)(1<<1) )	

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_MAIN_MSG_PROCESS_CPU_USAGE_REPORT_EVT

 Members:
	Header
	hProcess
	ulProcessUserId
 		Process User identifier. Value INVALID means no process running on this core.
	ulProcessCpuUsagePercent
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER			Header;
	tOCT_UINT32						hProcess;
	tOCTVC1_USER_ID_PROCESS_ENUM	ulProcessUserId;
	tOCT_UINT32						ulProcessCpuUsagePercent;

} tOCTVC1_MAIN_MSG_PROCESS_CPU_USAGE_REPORT_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_MAIN_MSG_PROCESS_DUMP_EVT

 Members:
	Header
	hProcess
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCT_UINT32				hProcess;

} tOCTVC1_MAIN_MSG_PROCESS_DUMP_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_MAIN_MSG_PROCESS_STATE_CHANGE_EVT

 Members:
	Header
 		OCTVC1 Event Header
	hProcess
 		Process handle identifier.
	ulUserId
 		Process user identifier
	ulState
 		Process new state
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER			Header;
	tOCT_UINT32						hProcess;
	tOCTVC1_USER_ID_PROCESS_ENUM	ulUserId;
	tOCTVC1_PROCESS_STATE_ENUM		ulState;

} tOCTVC1_MAIN_MSG_PROCESS_STATE_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_MAIN_MSG_API_SYSTEM_SESSION_HEARTBEAT_EVT

 Members:
	Header
	ulSessionIndex
 		Session index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;
	tOCTVC1_INDEX			ulSessionIndex;

} tOCTVC1_MAIN_MSG_API_SYSTEM_SESSION_HEARTBEAT_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_MAIN_MSG_APPLICATION_STATE_CHANGE_EVT

 Members:
	Header
	ulState
 		Application state
	szAppName
 		Application name
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_MAIN_APPLICATION_STATE_ENUM	ulState;
	tOCT_INT8							szAppName[(cOCTVC1_MAIN_APPLICATION_MAX_NAME_LENGTH+1)];

} tOCTVC1_MAIN_MSG_APPLICATION_STATE_CHANGE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_MAIN_MSG_LICENSING_STATE_CHANGE_EVT

 Members:
	Header
	ulState
 		New licensing state
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_MAIN_LICENSING_STATUS_ENUM	ulState;

} tOCTVC1_MAIN_MSG_LICENSING_STATE_CHANGE_EVT;


#endif /* __OCTVC1_MAIN_EVT_H__ */

