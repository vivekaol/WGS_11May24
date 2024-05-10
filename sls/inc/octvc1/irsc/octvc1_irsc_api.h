/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_IRSC_API.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the IRSC API.
 		OCTVC1 Internal Resources

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_IRSC_API_H__
#define __OCTVC1_IRSC_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_fifo.h"
#include "../octvc1_buffer.h"
#include "../octvc1_eth.h"
#include "../octvc1_mac.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_log.h"
#include "../octvc1_process.h"
#include "../octvc1_radio.h"
#include "../octvc1_api.h"
#include "../octvc1_module.h"
#include "../octvc1_user_id.h"
#include "../octvc1_stream.h"
#include "../octvc1_tap.h"

#include "octvc1_irsc_id.h"
#include "octvc1_irsc_rc.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	IPC related definitions.
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	IPC port type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IRSC_IPC_PORT_TYPE_ENUM						tOCT_UINT32

#define cOCTVC1_IRSC_IPC_PORT_TYPE_ENUM_INVALID				0		
#define cOCTVC1_IRSC_IPC_PORT_TYPE_ENUM_UNIDIR_RECV			1		
#define cOCTVC1_IRSC_IPC_PORT_TYPE_ENUM_UNIDIR_SEND			2		
#define cOCTVC1_IRSC_IPC_PORT_TYPE_ENUM_BIDIR				3		
#define cOCTVC1_IRSC_IPC_PORT_TYPE_ENUM_LOCAL				4		

/*-------------------------------------------------------------------------------------
 	IPC port type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IRSC_IPC_PORT_STATE_ENUM					tOCT_UINT32

#define cOCTVC1_IRSC_IPC_PORT_STATE_ENUM_INVALID			0		
#define cOCTVC1_IRSC_IPC_PORT_STATE_ENUM_ERROR				1		
#define cOCTVC1_IRSC_IPC_PORT_STATE_ENUM_CONFIG				2		
#define cOCTVC1_IRSC_IPC_PORT_STATE_ENUM_WAIT_REMOTE		3		
#define cOCTVC1_IRSC_IPC_PORT_STATE_ENUM_READY				4		

/*-------------------------------------------------------------------------------------
 	IPC port clone state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IRSC_IPC_PORT_CLONE_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_IRSC_IPC_PORT_CLONE_STATE_ENUM_INVALID		0		 	/* Ipc port not part of IPC clone */
#define cOCTVC1_IRSC_IPC_PORT_CLONE_STATE_ENUM_CLONE		1		 	/* Ipc port clone of other port */
#define cOCTVC1_IRSC_IPC_PORT_CLONE_STATE_ENUM_ORIGINAL		2		 	/* Original Ipc port cloned */
#define cOCTVC1_IRSC_IPC_PORT_CLONE_STATE_ENUM_REMOTE		3		 	/* Remote Ipc port connected to a clone port */

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_IPC_PORT_CLONE
 		Ipc port clone context

 Members:
	ulCloneState
 		Port Clone State.
	hProcess
 		When ulCloneState set to CLONE: Process handle of the original port
 		When ulCloneState set to ORIGINAL: Process handle of the clone port
 		When ulCloneState set to REMOTE: Process handle of the original port
	ulPortId
 		When ulCloneState set to CLONE: IPC port identifier of the original port
 		When ulCloneState set to ORIGINAL: IPC port identifier of the clone port
 		When ulCloneState set to REMOTE: IPC port identifier of the original port
	ulUserPortId
 		When ulCloneState set to CLONE: IPC port user id of the original port
 		When ulCloneState set to ORIGINAL: IPC port user id of the clone port
 		When ulCloneState set to REMOTE: IPC port user id of the original port
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_IRSC_IPC_PORT_CLONE_STATE_ENUM	ulCloneState;
	tOCTVC1_HANDLE_OBJECT					hProcess;
	tOCTVC1_SUB_OBJECT_ID					ulPortId;
	tOCT_UINT32								ulUserPortId;

} tOCTVC1_IRSC_IPC_PORT_CLONE;

/*-------------------------------------------------------------------------------------
 	API related definitions
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_API_STATS
 		API stats

 Members:
	ulMaxProcessingTimeUs
 		Max time spent processing the command in micro second.
	ulMinProcessingTimeUs
 		Min time spent processing the command in micro second.
	ulTotalProcessingTimeUs
 		Total time spent processing the command in micro second.
	ulCmdCnt
 		How many time the command is called
	ulL1CacheMissCnt
 		Number of cache miss in L1 memory
	ulTlbCacheMissCnt
 		Number of cache miss in TLB memory
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulMaxProcessingTimeUs;
	tOCT_UINT32	ulMinProcessingTimeUs;
	tOCT_UINT32	ulTotalProcessingTimeUs;
	tOCT_UINT32	ulCmdCnt;
	tOCT_UINT32	ulL1CacheMissCnt;
	tOCT_UINT32	ulTlbCacheMissCnt;

} tOCTVC1_IRSC_API_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_SESSION_STATS
 		API SESSION stats

 Members:
	ulLastCmdTimestamp
 		Timestamp of the last command received
	ulExpTransactionId
 		Next Expected transaction id
	ulAcceptedCmdCnt
 		Total of accepted commands
	ulRejectedCmdCnt
 		Total of rejected commands
	ulRetryCmdCnt
 		Total of retry commands
	ulResyncCnt
 		Total of transaction id resynchronization
	ulSessionCnt
 		Total of time this session index have been used with a different client session
	ulEvtSentCnt
 		Next Expected transaction id
	ulEvtSentErrCnt
 		Next Expected transaction id
	ulLastEvtTimestamp
 		Timestamp of the last event sent
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulLastCmdTimestamp;
	tOCT_UINT32	ulExpTransactionId;
	tOCT_UINT32	ulAcceptedCmdCnt;
	tOCT_UINT32	ulRejectedCmdCnt;
	tOCT_UINT32	ulRetryCmdCnt;
	tOCT_UINT32	ulResyncCnt;
	tOCT_UINT32	ulSessionCnt;
	tOCT_UINT32	ulEvtSentCnt;
	tOCT_UINT32	ulEvtSentErrCnt;
	tOCT_UINT32	ulLastEvtTimestamp;

} tOCTVC1_IRSC_SESSION_STATS;

/*-------------------------------------------------------------------------------------
 	Application related definitions.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_IRSC_APPLICATION_TAP_MAX_DESCRIPTION_BYTE_SIZE	255		 	/* Tap description buffer size, in bytes. */
#define cOCTVC1_IRSC_APPLICATION_TRANSPORT_MAX_DATA_SIZE	0xFFFFFFFF	 	/* Max transport size. Allow adapt tap packet size base the transport. */

/*-------------------------------------------------------------------------------------
 	Tap state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IRSC_APPLICATION_TAP_STATE_ENUM				tOCT_UINT32

#define cOCTVC1_IRSC_APPLICATION_TAP_STATE_ENUM_DISABLE		0		
#define cOCTVC1_IRSC_APPLICATION_TAP_STATE_ENUM_STOP		1		
#define cOCTVC1_IRSC_APPLICATION_TAP_STATE_ENUM_START		2		
#define cOCTVC1_IRSC_APPLICATION_TAP_STATE_ENUM_PAUSE		3		

/*-------------------------------------------------------------------------------------
 	Tap state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IRSC_APPLICATION_TAP_MODE_ENUM				tOCT_UINT32

#define cOCTVC1_IRSC_APPLICATION_TAP_MODE_ENUM_STREAM		0		

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_APPLICATION_TAP_INFO
 		Application Module information

 Members:
	ulModuleId
 		Module Id.
	hProcess
 		Process handle where Tap is instantiate
	ulProcessUserId
 		Process user identifier, connect on this interface
	ulDirection
	ulDataSubType
 		Data sub type cOCTVOCNET_PKT_SUBTYPE_UNSPECIFIED,
 		cOCTVOCNET_PKT_SUBTYPE_MODULE_DATA
	szName
 		Tap Name.
	szDescription
 		Process file name.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulModuleId;
	tOCTVC1_HANDLE_OBJECT			hProcess;
	tOCTVC1_USER_ID_PROCESS_ENUM	ulProcessUserId;
	tOCTVC1_TAP_DIRECTION_ENUM		ulDirection;
	tOCT_UINT32						ulDataSubType;
	tOCT_INT8						szName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_INT8						szDescription[(cOCTVC1_IRSC_APPLICATION_TAP_MAX_DESCRIPTION_BYTE_SIZE+1)];/* NOSWAPMAC */

} tOCTVC1_IRSC_APPLICATION_TAP_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_APPLICATION_TAP_STATS
 		TAP Command stats

 Members:
	ulState
		Default:	cOCTVC1_IRSC_APPLICATION_TAP_STATE_ENUM_DISABLE
	ulFilterIndex
	ulUserId
	Stream
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_IRSC_APPLICATION_TAP_STATE_ENUM	ulState;
	tOCTVC1_INDEX							ulFilterIndex;
	tOCT_UINT32								ulUserId;
	tOCTVC1_STREAM_STATS					Stream;

} tOCTVC1_IRSC_APPLICATION_TAP_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_APPLICATION_TAP_START
 		Activate an application tap

 Members:
	ulMode
		Default:	cOCTVC1_IRSC_APPLICATION_TAP_MODE_ENUM_STREAM
 		Tap handle identifier.
	ulMaxTransportDataSize
		Range:		[128..]
		Default:	cOCTVC1_IRSC_APPLICATION_TRANSPORT_MAX_DATA_SIZE
 		Maximum data byte size supported by transport.
	ulFilterIndex
		Default:	cOCTVC1_INDEX_INVALID
	ulUserId
		Default:	0
	ulRetryEnableFlag
		Default:	cOCT_FALSE
 		If true, Retry events will be sent when blocks are missing.
 		Blocks will be dropped to ensure they are not kept out of sequence.
	ulPauseOnStartFlag
 		May specify to pause the TAP on start.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_IRSC_APPLICATION_TAP_MODE_ENUM	ulMode;
	tOCT_UINT32								ulMaxTransportDataSize;
	tOCTVC1_INDEX							ulFilterIndex;
	tOCT_UINT32								ulUserId;
	tOCT_BOOL32								ulRetryEnableFlag;
	tOCT_BOOL32								ulPauseOnStartFlag;

} tOCTVC1_IRSC_APPLICATION_TAP_START;

/*-------------------------------------------------------------------------------------
 	IRSC Module Tap Id
-------------------------------------------------------------------------------------*/
#define cOCTVC1_IRSC_TAP_TX_LOG								((0x0000)|(cOCTVC1_TAP_DIRECTION_ENUM_TX<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET)|(cOCTVC1_MODULE_APPLICATION_ID_MAIN_SYSTEM<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	IRSC Router
-------------------------------------------------------------------------------------*/
#define cOCTVC1_IRSC_ROUTER_STREAMER_LIMIT_BANDWIDTH_DISABLE	0xFFFFFFFF	
#define cOCTVC1_IRSC_ROUTER_MAX_INTERFACE					24		

/*-------------------------------------------------------------------------------------
 	Interface type.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IRSC_ROUTER_INTERFACE_TYPE_ENUM				tOCT_UINT32

#define cOCTVC1_IRSC_ROUTER_INTERFACE_TYPE_ENUM_UNUSE		0		
#define cOCTVC1_IRSC_ROUTER_INTERFACE_TYPE_ENUM_LOCAL		1		
#define cOCTVC1_IRSC_ROUTER_INTERFACE_TYPE_ENUM_REMOTE		2		

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_ROUTER_INTERFACE_INFO
 		Router interface info

 Members:
	ulInterfaceIndex
 		Router interface index
	ulProcessUserId
 		Process user identifier, connect on this interface
	ulType
 		Process user identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_INDEX							ulInterfaceIndex;
	tOCTVC1_USER_ID_PROCESS_ENUM			ulProcessUserId;
	tOCTVC1_IRSC_ROUTER_INTERFACE_TYPE_ENUM	ulType;

} tOCTVC1_IRSC_ROUTER_INTERFACE_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_ROUTER_INTERFACE_STATS
 		Router interface stats

 Members:
	ulInterfaceIndex
 		Router interface index
	ulProcessUserId
 		Process user identifier, connect on this interface
	ulSentPktCnt
 		Number of packet sent to ulProcessUserId
	ulRecvPktCnt
 		Number of packet receive from ulProcessUserId
	ulErrSentPktCnt
 		Number error when trying to sent to ulProcessUserId
	ulErrRecvPktCnt
 		Number error when trying to receive from ulProcessUserId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_INDEX					ulInterfaceIndex;
	tOCTVC1_USER_ID_PROCESS_ENUM	ulProcessUserId;
	tOCT_UINT32						ulSentPktCnt;
	tOCT_UINT32						ulRecvPktCnt;
	tOCT_UINT32						ulErrSentPktCnt;
	tOCT_UINT32						ulErrRecvPktCnt;

} tOCTVC1_IRSC_ROUTER_INTERFACE_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_ROUTER_INFO
 		Router interface stats

 Members:
	ulProcessUserId
 		Process user identifier where router is instanciated
	ulSafeModeFlag
 		Indication if router is in safe mode or not
	ulInterfaceMaxNum
 		Maximun number of interface supported by the router
	ulInterfaceNum
 		Number of interface between router and process
	aInterfaceInfo
 		Session event Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_USER_ID_PROCESS_ENUM		ulProcessUserId;
	tOCT_BOOL32							ulSafeModeFlag;
	tOCT_UINT32							ulInterfaceMaxNum;
	tOCT_UINT32							ulInterfaceNum;
	tOCTVC1_IRSC_ROUTER_INTERFACE_INFO	aInterfaceInfo[cOCTVC1_IRSC_ROUTER_MAX_INTERFACE];

} tOCTVC1_IRSC_ROUTER_INFO;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_ROUTER_STATS
 		Router interface stats

 Members:
	ulInterfaceTotalSentPktCnt
 		Total packet sent to Interface (router-> process)
	ulInterfaceTotalRecvPktCnt
 		Total packet receive from Interface (process -> router )
	ulInterfaceTotalErrSentPktCnt
 		Total error when trying to packet (router-> process)
	ulInterfaceTotalErrRecvPktCnt
 		Total error when trying to receive packet (process -> router )
	ulTotalSentPktCnt
 		Total packet sent to external
	ulTotalRecvPktCnt
 		Total packet receive from external
	ulSentEvtPktCnt
 		Number of event sent by router
	ulModuleDataTotalRecvPktCnt
 		Total module_data packet receive from external
	ulModuleDataTotalSentPktCnt
 		Total module_data packet sent to external
	ulInterfaceNum
 		Number of interface between router and process
	aInterfaceStats
 		Session event Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32							ulInterfaceTotalSentPktCnt;
	tOCT_UINT32							ulInterfaceTotalRecvPktCnt;
	tOCT_UINT32							ulInterfaceTotalErrSentPktCnt;
	tOCT_UINT32							ulInterfaceTotalErrRecvPktCnt;
	tOCT_UINT32							ulTotalSentPktCnt;
	tOCT_UINT32							ulTotalRecvPktCnt;
	tOCT_UINT32							ulSentEvtPktCnt;
	tOCT_UINT32							ulModuleDataTotalRecvPktCnt;
	tOCT_UINT32							ulModuleDataTotalSentPktCnt;
	tOCT_UINT32							ulInterfaceNum;
	tOCTVC1_IRSC_ROUTER_INTERFACE_STATS	aInterfaceStats[cOCTVC1_IRSC_ROUTER_MAX_INTERFACE];

} tOCTVC1_IRSC_ROUTER_STATS;

/*-------------------------------------------------------------------------------------
 	Process related definitions.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_IRSC_PROCESS_MEMORY_CACHE_STATS_RECENT_MISSES_NUM	8		 	/* L1 cache misses history number. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_PROCESS_MEMORY_CACHE_STATS
 		Process cache memory stats

 Members:
	ulL1MaxSize
 		Maximum L1 memory size for cache fetching
	ulL1UserLockedSize
 		L1 memory currently locked by user
	ulL1CodeSize
 		Code cache size in bytes
	ulL1DataSize
 		Data cache size in bytes
	ulL1MissCnt
 		Not in L1 memory
	ulTlbMissCnt
 		In L1 memory but not in TLB
	ulL1CodeFetchCnt
 		Code cache line fetch
	ulL1DataReadCnt
 		Data cache line fetch
	ulL1DataWriteCnt
 		Data cache line fetch
	aulRecentMisses
 		The most recent L1 misses
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulL1MaxSize;
	tOCT_UINT32	ulL1UserLockedSize;
	tOCT_UINT32	ulL1CodeSize;
	tOCT_UINT32	ulL1DataSize;
	tOCT_UINT32	ulL1MissCnt;
	tOCT_UINT32	ulTlbMissCnt;
	tOCT_UINT32	ulL1CodeFetchCnt;
	tOCT_UINT32	ulL1DataReadCnt;
	tOCT_UINT32	ulL1DataWriteCnt;
	tOCT_UINT32	aulRecentMisses[cOCTVC1_IRSC_PROCESS_MEMORY_CACHE_STATS_RECENT_MISSES_NUM];

} tOCTVC1_IRSC_PROCESS_MEMORY_CACHE_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_PROCESS_MEMORY_HEAP_STATS
 		Process heap memory stats

 Members:
	ulUsedSize
 		Used heap memory size in bytes
	ulFreeSize
 		Free heap memory size in bytes
	ulFreeLargestSize
 		Free largest heap memory block size
	ulUsedBlocNum
 		Used heap memory block number
	ulFreeBlocNum
 		Free heap memory block number
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulUsedSize;
	tOCT_UINT32	ulFreeSize;
	tOCT_UINT32	ulFreeLargestSize;
	tOCT_UINT32	ulUsedBlocNum;
	tOCT_UINT32	ulFreeBlocNum;

} tOCTVC1_IRSC_PROCESS_MEMORY_HEAP_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_PROCESS_MEMORY_STACK_STATS
 		Process heap memory stats

 Members:
	ulFreeSize
 		Current Free size
	ulUnusedSize
 		Stack size allocation that was never used.
 		Available when called with ulStackScanFlag to true
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulFreeSize;
	tOCT_UINT32	ulUnusedSize;

} tOCTVC1_IRSC_PROCESS_MEMORY_STACK_STATS;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_PROCESS_MEMORY_SCRATCH_PAD_STATS
 		Process heap memory stats

 Members:
	ulTotalSize
 		Total scratch pad size in bytes. Allocate in local memory
	ulMaxUsedSize
 		Max Used scratch pad size in bytes
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulTotalSize;
	tOCT_UINT32	ulMaxUsedSize;

} tOCTVC1_IRSC_PROCESS_MEMORY_SCRATCH_PAD_STATS;

#define cOCTVC1_IRSC_LICENSING_EXTERNAL_PAYLOAD_MAX_LENGTH	280		 	/* Maximum length, */

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_LICENSING_EXTERNAL_PARMS

 Members:
	abyPayload
 		Reserved for padding.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT8	abyPayload[cOCTVC1_IRSC_LICENSING_EXTERNAL_PAYLOAD_MAX_LENGTH];

} tOCTVC1_IRSC_LICENSING_EXTERNAL_PARMS;

/*-------------------------------------------------------------------------------------
 	Licensing MCC status.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IRSC_LICENSING_EXTERNAL_TYPE_ENUM			tOCT_UINT32

#define cOCTVC1_IRSC_LICENSING_EXTERNAL_TYPE_ENUM_INPUT		0x55550000	
#define cOCTVC1_IRSC_LICENSING_EXTERNAL_TYPE_ENUM_OUTPUT	0xAAAA0001	

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_LICENSING_EXTERNAL_HEADER

 Members:
	ulType
		Default:	cOCTVC1_IRSC_LICENSING_EXTERNAL_TYPE_ENUM_INPUT
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_IRSC_LICENSING_EXTERNAL_TYPE_ENUM	ulType;

} tOCTVC1_IRSC_LICENSING_EXTERNAL_HEADER;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_LICENSING_EXTERNAL_INPUT

 Members:
	ulInputValue
		Default:	0
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulInputValue;

} tOCTVC1_IRSC_LICENSING_EXTERNAL_INPUT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_LICENSING_EXTERNAL_OUTPUT

 Members:
	ulInputValue
		Default:	0
	ulOutputValue
		Default:	0
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulInputValue;
	tOCT_UINT32	ulOutputValue;

} tOCTVC1_IRSC_LICENSING_EXTERNAL_OUTPUT;

/*****************************  METHODS  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
		Default:	cOCTVC1_HANDLE_INVALID
 		Process handle identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;

} tOCTVC1_IRSC_MSG_PROCESS_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
	ulUserId
 		Process user identifier
	szName
 		Process Name.
	szProcessImageName
 		Process file name.
	ulModuleId
 		Module Id.
	ulRouterIfEnableFlag
 		Router Interface enable flag
 		if cOCT_TRUE, an router internal is enable between this process and router
 		Router interface allow this core send directly API event, send/receive
 		MODULE_DATA
	ulIpcPortMax
 		Maximum number of ipc port
	ulIpcFifoMax
 		Maximum number of ipc fifo
	ulTaskMax
 		Maximum number of task
	ulUserIpcPortMax
 		Maximum number of user ipc port
	ulUserIpcFifoMax
 		Maximum number of user ipc fifo
	ulUserTaskMax
 		Maximum number of user task
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hProcess;
	tOCTVC1_USER_ID_PROCESS_ENUM	ulUserId;
	tOCT_INT8						szName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_INT8						szProcessImageName[(cOCTVC1_PROCESS_IMAGE_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32						ulModuleId;
	tOCT_BOOL32						ulRouterIfEnableFlag;
	tOCT_UINT32						ulIpcPortMax;
	tOCT_UINT32						ulIpcFifoMax;
	tOCT_UINT32						ulTaskMax;
	tOCT_UINT32						ulUserIpcPortMax;
	tOCT_UINT32						ulUserIpcFifoMax;
	tOCT_UINT32						ulUserTaskMax;

} tOCTVC1_IRSC_MSG_PROCESS_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
		Default:	cOCTVC1_HANDLE_INVALID
 		Process handle identifier.
	ulResetProcessStatsFlag
 		Statistics counters will be reset to zero after the current values are returned.
	ulResetIpcStatsFlag
 		Statistics counters for all IPC ports will be reset to zero after the current
 		values are returned.
	ulResetTaskStatsFlag
 		Statistics counters for all tasks will be reset to zero after the current
 		values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCT_BOOL32				ulResetProcessStatsFlag;
	tOCT_BOOL32				ulResetIpcStatsFlag;
	tOCT_BOOL32				ulResetTaskStatsFlag;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
	State
 		Current process state.
	ulTotalCacheMissCnt
	ulTaskScratchPadLeakCnt
 		Number of tasks with scratchpad leak flag trigged
	Error
 		Process Error
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hProcess;
	tOCTVC1_PROCESS_STATE_ENUM	State;
	tOCT_UINT32					ulTotalCacheMissCnt;
	tOCT_UINT32					ulTaskScratchPadLeakCnt;
	tOCTVC1_PROCESS_ERROR		Error;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_CMD

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

} tOCTVC1_IRSC_MSG_PROCESS_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_RSP

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

} tOCTVC1_IRSC_MSG_PROCESS_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_INFO_IPC_PORT_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulPortId
 		IPC port identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulPortId;

} tOCTVC1_IRSC_MSG_PROCESS_INFO_IPC_PORT_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_INFO_IPC_PORT_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulPortId
 		IPC port identifier
	ulUserId
 		IPC port user identifier
	ulModuleId
 		Module Id.
	hRemoteProcess
 		Remote Process identifier
	ulRemotePortId
 		Remote IPC port identifier
	ulRemoteUserId
 		Remote IPC port user id
	szName
 		IPC Port Name.
	ulPortIdx
 		Process Local Port Idx
	ulType
 		Process Local Port Idx
	ulSystemFlag
 		System Flag
	Clone
 		Ipc Port Clone information.
	ulRecvMsgNum
 		Reception array message number.
	ulRecvMsgSize
 		Reception message size in bytes.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hProcess;
	tOCTVC1_SUB_OBJECT_ID			ulPortId;
	tOCT_UINT32						ulUserId;
	tOCT_UINT32						ulModuleId;
	tOCTVC1_HANDLE_OBJECT			hRemoteProcess;
	tOCTVC1_SUB_OBJECT_ID			ulRemotePortId;
	tOCT_UINT32						ulRemoteUserId;
	tOCT_INT8						szName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];/* NOSWAPMAC */
	tOCT_UINT32						ulPortIdx;
	tOCTVC1_IRSC_IPC_PORT_TYPE_ENUM	ulType;
	tOCT_BOOL32						ulSystemFlag;
	tOCTVC1_IRSC_IPC_PORT_CLONE		Clone;
	tOCT_UINT32						ulRecvMsgNum;
	tOCT_UINT32						ulRecvMsgSize;

} tOCTVC1_IRSC_MSG_PROCESS_INFO_IPC_PORT_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_IPC_PORT_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulPortId
 		IPC port identifier
	ulResetStatsFlag
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulPortId;
	tOCT_BOOL32				ulResetStatsFlag;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_IPC_PORT_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_IPC_PORT_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulPortId
 		IPC port identifier
	ulState
 		IPC port state
	ulSendMsgCnt
 		Count of message send
	ulRecvMsgCnt
 		Count of message received.
	ulRecvMsgMissCnt
 		Number of missing message
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_HANDLE_OBJECT				hProcess;
	tOCTVC1_SUB_OBJECT_ID				ulPortId;
	tOCTVC1_IRSC_IPC_PORT_STATE_ENUM	ulState;
	tOCT_UINT32							ulSendMsgCnt;
	tOCT_UINT32							ulRecvMsgCnt;
	tOCT_UINT32							ulRecvMsgMissCnt;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_IPC_PORT_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_IPC_PORT_CMD

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

} tOCTVC1_IRSC_MSG_PROCESS_LIST_IPC_PORT_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_IPC_PORT_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	ObjectNameList
 		Object32 named list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER									Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID		SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME	ObjectNameList;

} tOCTVC1_IRSC_MSG_PROCESS_LIST_IPC_PORT_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_INFO_TASK_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulTaskIndex
 		Task identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulTaskIndex;

} tOCTVC1_IRSC_MSG_PROCESS_INFO_TASK_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_INFO_TASK_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulTaskIndex
 		Task identifier
	ulModuleId
 		Module Id.
	szName
 		Name given to the task
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulTaskIndex;
	tOCT_UINT32				ulModuleId;
	tOCT_INT8				szName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];

} tOCTVC1_IRSC_MSG_PROCESS_INFO_TASK_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_TASK_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulTaskIndex
 		Task identifier
	ulResetStatsFlag
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulTaskIndex;
	tOCT_BOOL32				ulResetStatsFlag;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_TASK_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_TASK_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulTaskIndex
 		Task identifier
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_HANDLE_OBJECT		hProcess;
	tOCTVC1_SUB_OBJECT_ID		ulTaskIndex;
	tOCTVC1_PROCESS_TASK_STATS	Stats;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_TASK_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_TASK_CMD

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

} tOCTVC1_IRSC_MSG_PROCESS_LIST_TASK_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_TASK_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	ObjectNameList
 		Object32 named list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER									Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID		SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME	ObjectNameList;

} tOCTVC1_IRSC_MSG_PROCESS_LIST_TASK_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_OBJMGR_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulObjType
		Default:	cOCTVC1_HANDLE_INVALID
 		Process handle identifier. Typically retrieved using the
 		cOCTVC1_MAIN_MSG_DEVICE_INFO_CID command.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulObjType;

} tOCTVC1_IRSC_MSG_OBJMGR_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_OBJMGR_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulObjType
 		Type of object contained by the manager, represented as a number
	ulMaxNumObj
 		Max number of objects the manager can hold
	ulObjByteSize
 		Size in bytes of each object
	szName
 		Name given to the object manager
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulObjType;
	tOCT_UINT32			ulMaxNumObj;
	tOCT_UINT32			ulObjByteSize;
	tOCT_INT8			szName[(cOCTVC1_HANDLE_OBJECT32_NAME_MAX_LENGTH+1)];

} tOCTVC1_IRSC_MSG_OBJMGR_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_OBJMGR_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulObjType
 		Type of object contained by the manager, represented as a number
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulObjType;

} tOCTVC1_IRSC_MSG_OBJMGR_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_OBJMGR_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulObjType
 		Type of object contained by the manager, represented as a number
	ulMaxNumObj
 		Max number of objects the manager can hold
	ulNumObj
 		Current number of objects in the manager
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulObjType;
	tOCT_UINT32			ulMaxNumObj;
	tOCT_UINT32			ulNumObj;

} tOCTVC1_IRSC_MSG_OBJMGR_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_OBJMGR_LIST_CMD

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

} tOCTVC1_IRSC_MSG_OBJMGR_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_OBJMGR_LIST_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ObjectCursor
 		Object cursor
	ObjectNameList
 		>Object32 named list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_NAME_OBJECT32_GET		ObjectNameList;

} tOCTVC1_IRSC_MSG_OBJMGR_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_START_MONITORING_CMD
 		Start the Api command timing

 Members:
	Header
 		OCTVC1 Message Header
	ulResetStatsFlag
		Default:	cOCT_TRUE
 		If set to cOCT_TRUE, all statistics counters will be reset to zero.
 		If set to cOCT_FALSE, counters will not be reset.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_BOOL32			ulResetStatsFlag;

} tOCTVC1_IRSC_MSG_API_SYSTEM_START_MONITORING_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_START_MONITORING_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_API_SYSTEM_START_MONITORING_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STOP_MONITORING_CMD
 		Stop the Api command timing

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STOP_MONITORING_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STOP_MONITORING_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STOP_MONITORING_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_COMMAND_CMD
 		List the command since the monitoring is enabled.

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

} tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_COMMAND_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_COMMAND_RSP

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

} tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_COMMAND_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_COMMAND_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hCmdId
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCmdId;
	tOCT_BOOL32				ulResetStatsFlag;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_COMMAND_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_COMMAND_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hCmdId
	CommandStats
 		Monitoring entry asked
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCmdId;
	tOCTVC1_IRSC_API_STATS	CommandStats;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_COMMAND_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_SESSION_CMD
 		List the cmd that are monitored

 Members:
	Header
 		OCTVC1 Message Header
	IndexGet
 		Object cursor
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;

} tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_SESSION_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_SESSION_RSP

 Members:
	Header
 		OCTVC1 Message Header
	IndexGet
 		Object cursor
	IndexList
 		Object name list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_CURSOR_INDEX_GET	IndexGet;
	tOCTVC1_LIST_INDEX_GET		IndexList;

} tOCTVC1_IRSC_MSG_API_SYSTEM_LIST_SESSION_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
		Default:	cOCTVC1_API_SESSION_INDEX_CURRENT_TRANSPORT
 		Session index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulSessionIndex;

} tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
 		Session index
	SessionInfo
 		Session Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_INDEX				ulSessionIndex;
	tOCTVC1_API_SESSION_INFO	SessionInfo;

} tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
		Default:	cOCTVC1_API_SESSION_INDEX_CURRENT_TRANSPORT
 		Session index
	ulResetStatsFlag
		Default:	cOCT_FALSE
 		Statistics counters will be reset to zero after the current values are returned.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulSessionIndex;
	tOCT_BOOL32			ulResetStatsFlag;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
 		Session index
	SessionStats
 		Sessiont statistic asked
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_INDEX				ulSessionIndex;
	tOCTVC1_IRSC_SESSION_STATS	SessionStats;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_EVT_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
		Default:	cOCTVC1_API_SESSION_INDEX_CURRENT_TRANSPORT
 		Session index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulSessionIndex;

} tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_EVT_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_EVT_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
 		Session index
	EvtInfo
 		Session event Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulSessionIndex;
	tOCTVC1_API_SESSION_EVT_INFO	EvtInfo;

} tOCTVC1_IRSC_MSG_API_SYSTEM_INFO_SESSION_EVT_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_EVT_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
		Default:	cOCTVC1_API_SESSION_INDEX_CURRENT_TRANSPORT
 		Session index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCTVC1_INDEX		ulSessionIndex;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_EVT_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_EVT_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulSessionIndex
 		Session index
	Stats
 		Session event stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_INDEX			ulSessionIndex;
	tOCTVC1_IRSC_API_STATS	Stats;

} tOCTVC1_IRSC_MSG_API_SYSTEM_STATS_SESSION_EVT_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_LIST_TAP_CMD

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

} tOCTVC1_IRSC_MSG_APPLICATION_LIST_TAP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_LIST_TAP_RSP

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

} tOCTVC1_IRSC_MSG_APPLICATION_LIST_TAP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_INFO_TAP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
		Default:	cOCTVC1_HANDLE_INVALID
 		Tap identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_INFO_TAP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_INFO_TAP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
	Info
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCT_UINT32							hTapId;
	tOCTVC1_IRSC_APPLICATION_TAP_INFO	Info;

} tOCTVC1_IRSC_MSG_APPLICATION_INFO_TAP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_STATS_TAP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
		Default:	cOCTVC1_HANDLE_INVALID
 		Tap handle identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_STATS_TAP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_STATS_TAP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
	Stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCT_UINT32							hTapId;
	tOCTVC1_IRSC_APPLICATION_TAP_STATS	Stats;

} tOCTVC1_IRSC_MSG_APPLICATION_STATS_TAP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_START_TAP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
		Default:	cOCTVC1_HANDLE_INVALID
 		Tap handle identifier.
	Start
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCT_UINT32							hTapId;
	tOCTVC1_IRSC_APPLICATION_TAP_START	Start;

} tOCTVC1_IRSC_MSG_APPLICATION_START_TAP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_START_TAP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
	hLogicalObj
 		Contains an Object Handle for the Tap that has been started
 		This handle will also be placed in
 		DataHeader.VocNetHeader.hLogicalObj.aulHandle[0]
 		of the tOCTVOCNET_PKT_DATA_FRAGMENT_HEADER at the header of each data packet
 		sent.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCT_UINT32				hTapId;
	tOCTVC1_HANDLE_OBJECT	hLogicalObj;

} tOCTVC1_IRSC_MSG_APPLICATION_START_TAP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_STOP_TAP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
		Default:	cOCTVC1_HANDLE_INVALID
 		Tap handle identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_STOP_TAP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_STOP_TAP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_STOP_TAP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_ROUTER_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	Info
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_IRSC_ROUTER_INFO	Info;

} tOCTVC1_IRSC_MSG_ROUTER_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_STATS_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_ROUTER_STATS_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_STATS_RSP

 Members:
	Header
 		OCTVC1 Message Header
	Stats
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER			Header;
	tOCTVC1_IRSC_ROUTER_STATS	Stats;

} tOCTVC1_IRSC_MSG_ROUTER_STATS_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_INFO_STREAMER_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_ROUTER_INFO_STREAMER_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_INFO_STREAMER_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulLimitBandwidthMbps
 		Maximal limit that target application will stream out data
	ulToHostStreamSequenceIdInterval
 		For stream target to host, define the interval that host by send data packet
 		acknowledgement.
 		Presently, only apply on file stream transfer
	ulToHostStreamInitialPktCnt
 		For stream target to host, define initial number of packet the stream will send
 		to host before waiting acknowledgement.
 		Most be egal or greater that ulToHostStreamSequenceIdInterval .
 		Presently, only apply on file stream transfer
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulLimitBandwidthMbps;
	tOCT_UINT32			ulToHostStreamSequenceIdInterval;
	tOCT_UINT32			ulToHostStreamInitialPktCnt;

} tOCTVC1_IRSC_MSG_ROUTER_INFO_STREAMER_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_STATS_SYSTEM_CMD
 		This command retrieves the system global statistics.

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_APPLICATION_STATS_SYSTEM_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_STATS_SYSTEM_RSP

 Members:
	Header
 		OCTVC1 Message Header
	ulExtMemSizeBytes
 		Total Size of External Memory (Bytes).
	ulExtMemTotalAllocFreeSizeBytes
 		Total Free Size Left of External Memory available for allocation (Bytes).
	ulExtMemLargestFreeBlocSizeBytes
 		Largest free bloc of memory available (Bytes).
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulExtMemSizeBytes;
	tOCT_UINT32			ulExtMemTotalAllocFreeSizeBytes;
	tOCT_UINT32			ulExtMemLargestFreeBlocSizeBytes;

} tOCTVC1_IRSC_MSG_APPLICATION_STATS_SYSTEM_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_MODIFY_STREAMER_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulLimitBandwidthMbps
		Range:		[50..1000],cOCTVC1_IRSC_ROUTER_STREAMER_LIMIT_BANDWIDTH_DISABLE
		Default:	cOCTVC1_DO_NOT_MODIFY
 		Maximal limit that target application will stream out data
 		Set to cOCTVC1_IRSC_ROUTER_STREAMER_LIMIT_BANDWIDTH_DISABLE to disable
 		Bandwidth limitation
	ulToHostStreamSequenceIdInterval
		Range:		[10..500]
		Default:	cOCTVC1_DO_NOT_MODIFY
 		For stream target to host, define the interval that host by send data packet
 		acknowledgement.
 		Presently, only apply on file stream transfer
	ulToHostStreamInitialPktCnt
		Range:		[10..500]
		Default:	cOCTVC1_DO_NOT_MODIFY
 		For stream target to host, initial number of packet the stream will send to
 		host before waiting acknowledgement.
 		Most be egal or greater that ulToHostStreamSequenceIdInterval .
 		Attention, host application must have appropriated ethernet configuration.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			ulLimitBandwidthMbps;
	tOCT_UINT32			ulToHostStreamSequenceIdInterval;
	tOCT_UINT32			ulToHostStreamInitialPktCnt;

} tOCTVC1_IRSC_MSG_ROUTER_MODIFY_STREAMER_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_MODIFY_STREAMER_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_IRSC_MSG_ROUTER_MODIFY_STREAMER_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_MEMORY_CMD
 		Retreive the memory statistics

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
	ulStackScanFlag
		Default:	cOCT_FALSE
 		If true, the stack will be scan to find the maximum amount of stack used in
 		this process.
 		Attention, the stack scan can take more than 1ms of execution in the process.
	ulScratchPadResetFlag
		Default:	cOCT_FALSE
 		If true, the max used size will be reset.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCT_BOOL32				ulStackScanFlag;
	tOCT_BOOL32				ulScratchPadResetFlag;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_MEMORY_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_MEMORY_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
	Stack
 		Stack stats
	Heap
 		Heap stats
	ScratchPad
 		ScratchPad stats
	Cache
 		Cache system stats
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER								Header;
	tOCTVC1_HANDLE_OBJECT							hProcess;
	tOCTVC1_IRSC_PROCESS_MEMORY_STACK_STATS			Stack;
	tOCTVC1_IRSC_PROCESS_MEMORY_HEAP_STATS			Heap;
	tOCTVC1_IRSC_PROCESS_MEMORY_SCRATCH_PAD_STATS	ScratchPad;
	tOCTVC1_IRSC_PROCESS_MEMORY_CACHE_STATS			Cache;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_MEMORY_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_SYSTEM_CMD

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

} tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_SYSTEM_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_SYSTEM_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	ObjectNameList
 		Object32 named list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER									Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID		SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME	ObjectNameList;

} tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_SYSTEM_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_SYSTEM_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulIndex
 		Resource index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulIndex;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_SYSTEM_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_SYSTEM_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulIndex
 		Resource index
	Resource
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulIndex;
	tOCTVC1_RESOURCE		Resource;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_SYSTEM_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_USER_CMD

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

} tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_USER_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_USER_RSP

 Members:
	Header
 		OCTVC1 Message Header
	SubObjectIdGet
 		Object cursor
	ObjectNameList
 		Object32 named list.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER									Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID		SubObjectIdGet;
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME	ObjectNameList;

} tOCTVC1_IRSC_MSG_PROCESS_LIST_RESOURCE_USER_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_USER_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulIndex
 		Resource index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulIndex;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_USER_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_USER_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hProcess
 		Process identifier
	ulIndex
 		Resource index
	Resource
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hProcess;
	tOCTVC1_SUB_OBJECT_ID	ulIndex;
	tOCTVC1_RESOURCE		Resource;

} tOCTVC1_IRSC_MSG_PROCESS_STATS_RESOURCE_USER_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_PAUSE_TAP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
		Default:	cOCTVC1_HANDLE_INVALID
 		Tap handle identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_PAUSE_TAP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_PAUSE_TAP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_PAUSE_TAP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_RESUME_TAP_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
		Default:	cOCTVC1_HANDLE_INVALID
 		Tap handle identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_RESUME_TAP_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_APPLICATION_RESUME_TAP_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hTapId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;
	tOCT_UINT32			hTapId;

} tOCTVC1_IRSC_MSG_APPLICATION_RESUME_TAP_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_LICENSING_EXECUTE_EXTERNAL_CMD

 Members:
	Header
 		OCTVC1 Message Header
	InputParms
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_IRSC_LICENSING_EXTERNAL_PARMS	InputParms;

} tOCTVC1_IRSC_MSG_LICENSING_EXECUTE_EXTERNAL_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_LICENSING_EXECUTE_EXTERNAL_RSP

 Members:
	Header
 		OCTVC1 Message Header
	OutputParms
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER						Header;
	tOCTVC1_IRSC_LICENSING_EXTERNAL_PARMS	OutputParms;

} tOCTVC1_IRSC_MSG_LICENSING_EXECUTE_EXTERNAL_RSP;


/*****************************  MODULE_DATA  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_IRSC_MSG_ROUTER_DATA_REQUEST_STREAMER_MDA

 Members:
	ModuleData
 		OCTVC1 Module Data
	hStream
 		Contains an Object Handle of stream
 		This handle will also be placed in DataHeader.VocNetHeader.hLogicalObj
 		of the tOCTVOCNET_PKT_DATA_FRAGMENT_HEADER at the header of each data packet
 		sent.
	hOwner
 		Contains an Object Handle of the object responsable for the stream object
 		(hLogicalObj)
	ulDataSize
	ulSequenceId
 		In the case of a retry, request data starting from this Sequence ID
	ulRetryFlag
 		Indicates if this event is a retry request
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MODULE_DATA		ModuleData;
	tOCTVC1_HANDLE_OBJECT	hStream;
	tOCTVC1_HANDLE_OBJECT	hOwner;
	tOCT_UINT32				ulDataSize;
	tOCT_UINT32				ulSequenceId;
	tOCT_BOOL32				ulRetryFlag;

} tOCTVC1_IRSC_MSG_ROUTER_DATA_REQUEST_STREAMER_MDA;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_irsc_evt.h"

#endif /* __OCTVC1_IRSC_API_H__ */

