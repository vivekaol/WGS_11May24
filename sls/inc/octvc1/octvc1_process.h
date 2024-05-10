/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_PROCESS.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_PROCESS_H__
#define __OCTVC1_PROCESS_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_base.h"
#include "octvc1_module.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	PROCESS related definitions.
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	Process type.
 	Process type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_PROCESS_TYPE_ENUM							tOCT_UINT32

#define cOCTVC1_PROCESS_TYPE_ENUM_INVALID					0		
#define cOCTVC1_PROCESS_TYPE_ENUM_CONTROL					1		
#define cOCTVC1_PROCESS_TYPE_ENUM_OCTADF_ROUTER				2		
#define cOCTVC1_PROCESS_TYPE_ENUM_RFFI						2		
#define cOCTVC1_PROCESS_TYPE_ENUM_PLAYER					3		
#define cOCTVC1_PROCESS_TYPE_ENUM_UMTS_SCH					4		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNMSA					5		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNMC					6		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM3GCS				7		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM3GIM0				8		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM3GIM1				9		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM3GOM				10		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM2GIM				11		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM2GOM				12		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_RFFI					13		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM4GCS				14		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM4GIMCH				15		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM4GRX				16		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNM4GRXC				17		
#define cOCTVC1_PROCESS_TYPE_ENUM_TXRFFI					18		
#define cOCTVC1_PROCESS_TYPE_ENUM_RXRFFI					19		
#define cOCTVC1_PROCESS_TYPE_ENUM_BASSC						20		
#define cOCTVC1_PROCESS_TYPE_ENUM_BASS_RFFI					21		
#define cOCTVC1_PROCESS_TYPE_ENUM_BASS_BASSSYNC				22		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNMC2KIM				23		
#define cOCTVC1_PROCESS_TYPE_ENUM_WNM_WNMC2KOM				24		
#define cOCTVC1_PROCESS_TYPE_ENUM_USSMUEC					100		
#define cOCTVC1_PROCESS_TYPE_ENUM_USSMUE_RFFI				101		
#define cOCTVC1_PROCESS_TYPE_ENUM_USSMUE_USSMUE3GL			102		
#define cOCTVC1_PROCESS_TYPE_ENUM_USSMUE_USSMUE3GTM			103		
#define cOCTVC1_PROCESS_TYPE_ENUM_USSMUE_USSMUE2GIM			104		
#define cOCTVC1_PROCESS_TYPE_ENUM_USSMUE_USSMUE2GOM			105	
#define cOCTVC1_PROCESS_TYPE_ENUM_GSM_SCHED					((tOCT_UINT32)(cOCTVC1_PROCESS_LAST_OADF_PROCESS_TYPE_ENUM_ID+1) )	
#define cOCTVC1_PROCESS_TYPE_ENUM_GSM_DL					((tOCT_UINT32)(cOCTVC1_PROCESS_LAST_OADF_PROCESS_TYPE_ENUM_ID+2) )	
#define cOCTVC1_PROCESS_TYPE_ENUM_GSM_ULIM					((tOCT_UINT32)(cOCTVC1_PROCESS_LAST_OADF_PROCESS_TYPE_ENUM_ID+3) )	
#define cOCTVC1_PROCESS_TYPE_ENUM_GSM_ULEQ					((tOCT_UINT32)(cOCTVC1_PROCESS_LAST_OADF_PROCESS_TYPE_ENUM_ID+4) )	
#define cOCTVC1_PROCESS_TYPE_ENUM_GSM_ULOM					((tOCT_UINT32)(cOCTVC1_PROCESS_LAST_OADF_PROCESS_TYPE_ENUM_ID+5) )	
#define cOCTVC1_PROCESS_TYPE_ENUM_GSM_DECOMB				((tOCT_UINT32)(cOCTVC1_PROCESS_LAST_OADF_PROCESS_TYPE_ENUM_ID+6) )	
#define cOCTVC1_PROCESS_IMAGE_NAME_MAX_LENGTH				63		 	/* Process image string length restriction. */

/*-------------------------------------------------------------------------------------
 	Process utilization type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_PROCESS_STATE_ENUM							tOCT_UINT32

#define cOCTVC1_PROCESS_STATE_ENUM_INVALID					0		
#define cOCTVC1_PROCESS_STATE_ENUM_RESET					1		
#define cOCTVC1_PROCESS_STATE_ENUM_CREATE					2		
#define cOCTVC1_PROCESS_STATE_ENUM_WAITING					3		
#define cOCTVC1_PROCESS_STATE_ENUM_READY					4		
#define cOCTVC1_PROCESS_STATE_ENUM_RUNNING					5		
#define cOCTVC1_PROCESS_STATE_ENUM_ERROR					6		
#define cOCTVC1_PROCESS_STATE_ENUM_HALT						7		

/*-------------------------------------------------------------------------------------
	tOCTVC1_PROCESS_ERROR
 		Process Errors

 Members:
	ulInputOverflowCnt
 		Count of process input overflow
	ulInputUnderflowCnt
 		Count of process input underflow
	ulOutputOverflowCnt
 		Count of process output overflow
	ulOutputUnderflowCnt
 		Count of process output underflow
	ulIpcMsgMissCnt
 		Total number of IPC messages the process missed.
	ulLastErrorRc
 		An error code that should be set when the process has encountered an error
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulInputOverflowCnt;
	tOCT_UINT32	ulInputUnderflowCnt;
	tOCT_UINT32	ulOutputOverflowCnt;
	tOCT_UINT32	ulOutputUnderflowCnt;
	tOCT_UINT32	ulIpcMsgMissCnt;
	tOCT_UINT32	ulLastErrorRc;

} tOCTVC1_PROCESS_ERROR;

/*-------------------------------------------------------------------------------------
 	Process task state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_PROCESS_TASK_STATE_ENUM						tOCT_UINT32

#define cOCTVC1_PROCESS_TASK_STATE_ENUM_INVALID				0		
#define cOCTVC1_PROCESS_TASK_STATE_ENUM_ERROR				1		
#define cOCTVC1_PROCESS_TASK_STATE_ENUM_IDLE				2		
#define cOCTVC1_PROCESS_TASK_STATE_ENUM_PENDING				3		
#define cOCTVC1_PROCESS_TASK_STATE_ENUM_RUNNING				4		
#define cOCTVC1_PROCESS_TASK_STATE_ENUM_WAIT_TIMER			5		

/*-------------------------------------------------------------------------------------
	tOCTVC1_PROCESS_TASK_STATS

 Members:
	ulUserData
 		User data
	ulMaxExecTimeUs
 		Task's longest execution time (in microseconds)
	ulAvgExecTimeUs
 		Task's average execution time (in microseconds)
	ulLastExecTimeUs
 		Task's last execution time (in microseconds)
	ulMaxExecCacheMissCnt
 		Task's maximum cache miss in one execution.
 		Include code and data cache misses.
	ulLastExecCacheMissCnt
 		Task's last execution cache miss count
 		Include code and data cache misses.
	ulTotalCacheMissCnt
 		Task's last execution cache miss count
 		Include code and data cache misses.
	ulMaxExecCodeMissCnt
 		Task's maximum code cache miss in one execution
	ulLastExecCodeMissCnt
 		Task's last execution code cache miss count
	ulTotalCodeMissCnt
 		Task's last execution code cache miss count
	ulExecCnt
 		Number of times the task has been executed
	ulDoneCnt
 		Number of times the task has been completed
	ulReqCnt
 		Task requested count
	ulScratchPadLeakFlag
 		ScratchPad leak happenned during task processing
	ulErrorCnt
 		Number of times the task returned an error
	State
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulUserData;
	tOCT_UINT32						ulMaxExecTimeUs;
	tOCT_UINT32						ulAvgExecTimeUs;
	tOCT_UINT32						ulLastExecTimeUs;
	tOCT_UINT32						ulMaxExecCacheMissCnt;
	tOCT_UINT32						ulLastExecCacheMissCnt;
	tOCT_UINT32						ulTotalCacheMissCnt;
	tOCT_UINT32						ulMaxExecCodeMissCnt;
	tOCT_UINT32						ulLastExecCodeMissCnt;
	tOCT_UINT32						ulTotalCodeMissCnt;
	tOCT_UINT32						ulExecCnt;
	tOCT_UINT32						ulDoneCnt;
	tOCT_UINT32						ulReqCnt;
	tOCT_BOOL32						ulScratchPadLeakFlag;
	tOCT_UINT32						ulErrorCnt;
	tOCTVC1_PROCESS_TASK_STATE_ENUM	State;

} tOCTVC1_PROCESS_TASK_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_PROCESS_CPU_USAGE_STATS

 Members:
	ulProcessCpuUsagePercent
 		Current Process CPU usage value, expressed as a percentage.
	ulProcessCpuUsageMinPercent
 		Minimal Process CPU usage value, since last command request.
	ulProcessCpuUsageMaxPercent
 		Minimal Process CPU usage value, since last command.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulProcessCpuUsagePercent;
	tOCT_UINT32	ulProcessCpuUsageMinPercent;
	tOCT_UINT32	ulProcessCpuUsageMaxPercent;

} tOCTVC1_PROCESS_CPU_USAGE_STATS;


#endif /* __OCTVC1_PROCESS_H__ */

