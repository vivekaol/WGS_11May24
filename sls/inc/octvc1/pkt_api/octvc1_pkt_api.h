/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_PKT_API.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_PKT_API_H__
#define __OCTVC1_PKT_API_H__

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_pkt_api_rc.h"
#include "../../octdev_types.h"
#include "../../octdev_macro.h"
#include "../../../../common/octtransapi/include/octtransapi.h"
#include "../octvc1_generic_rc.h"
#include "../octvc1_fifo.h"
#include "../octvc1_handle.h"
#include "../octvocnet_pkt.h"
#include "../octvc1_msg.h"
#include "../main/octvc1_main_api.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/

/*--------------------------------------------------------------------------
	API Packet Types
----------------------------------------------------------------------------*/
#define	tOCTVC1_PKT_API_PKT_TYPE_ENUM				tOCT_UINT32
#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_INVALID		0xFFFFFFFF
#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP			0
#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT			1
#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_DATA			2
#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_DISCOVER		3
#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD			4

#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_MAX			(cOCTVC1_PKT_API_PKT_TYPE_ENUM_CMD)
#define	cOCTVC1_PKT_API_PKT_TYPE_ENUM_CNT			(cOCTVC1_PKT_API_PKT_TYPE_ENUM_MAX + 1)

#define tOCTVC1_PKT_API_RCV_MASK				tOCT_UINT32
#define cOCTVC1_PKT_API_RCV_MASK_RSP			(1<<cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP)
#define cOCTVC1_PKT_API_RCV_MASK_EVENT			(1<<cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT)
#define cOCTVC1_PKT_API_RCV_MASK_DATA			(1<<cOCTVC1_PKT_API_PKT_TYPE_ENUM_DATA)

#define cOCTVC1_PKT_API_RCV_MASK_ALL			(cOCTVC1_PKT_API_RCV_MASK_RSP	\
												|cOCTVC1_PKT_API_RCV_MASK_EVENT	\
												|cOCTVC1_PKT_API_RCV_MASK_DATA)

/*----------------------------------------------------------------------------
	MAC address size
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_MAC_ADDR_SIZE			(6)

/*----------------------------------------------------------------------------
	Forever value
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_FOREVER					0xFFFFFFFF
#define cOCTVC1_PKT_API_TIMEOUT_FOREVER			(cOCTVC1_PKT_API_FOREVER)

/*--------------------------------------------------------------------------
	Maximum number of connection
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_CNCT_MAX				(40)

/*--------------------------------------------------------------------------
	Maximum number of session per connection
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_SESS_MAX				(10)

/*--------------------------------------------------------------------------
	Maximum number of simultaneous synchronous command
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_CMD_MAX					(255)

/*--------------------------------------------------------------------------
	Maximum number of device
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_DEV_MAX					(16)

/*--------------------------------------------------------------------------
	Maximum number of port per device
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_DEV_PORT_MAX			(2)

/*--------------------------------------------------------------------------
	Maximum number of port per device
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_DISCOVER_TRANSPORT_MAX	(16)

	
/*--------------------------------------------------------------------------
	Device port type
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_DEV_PORT_TYPE_INVALID	(0)
#define cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH		(1)

#define tOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM				tOCT_UINT32
#define cOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM_INVALID		cOCTVC1_PKT_API_DEV_PORT_TYPE_INVALID
#define cOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM_ETH			cOCTVC1_PKT_API_DEV_PORT_TYPE_ETH
#define cOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM_TRANSPORT	(2)

/*--------------------------------------------------------------------------
	Device user info maximum length
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_DEV_USER_INFO_LEN_MAX	(cOCTVC1_MAIN_USER_INFO_SIZE*sizeof(tOCT_UINT32))

/*--------------------------------------------------------------------------
	Device  info report by the embedded application 
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_DEV_INFO_LEN_MAX		(cOCTVC1_MAIN_TARGET_MAX_INFO_BYTE_SIZE)


/*--------------------------------------------------------------------------
	Maximum number of simultaneous synchronous command
----------------------------------------------------------------------------*/
#define tOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM			tOCT_UINT32
#define cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_DEFAULT	(0)
#define cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_NAME		(0xCAFEDECA)
#define cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_MAC		(0)
#define cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_INDEX	(0)

/*--------------------------------------------------------------------------
	Instance Option MASK
----------------------------------------------------------------------------*/
#define tOCTVC1_PKT_API_INSTANCE_OPTION_MASK					tOCT_UINT32
#define cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_NONE				(0)
#define cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT	(0x00000001)

/*--------------------------------------------------------------------------
	Generic defined
----------------------------------------------------------------------------*/
#define cOCTVC1_PKT_API_PAYLOAD_MAX							(1502)

/***************************  STRUCTURES *************************************/

/*----------------------------------------------------------------------------
	API Instance type
----------------------------------------------------------------------------*/
typedef void			*tPOCTVC1_PKT_API_INST;

/*----------------------------------------------------------------------------
	API Connection type
----------------------------------------------------------------------------*/
typedef void			*tPOCTVC1_PKT_API_CNCT;

/*----------------------------------------------------------------------------
	API Session type
----------------------------------------------------------------------------*/
typedef void			*tPOCTVC1_PKT_API_SESS;


/*--------------------------------------------------------------------------
	Optionnal User Transport Function Pointer
----------------------------------------------------------------------------*/
typedef int (*tPFNTRANSPORTAPI_OPEN)( void * f_pTransportContext, void *f_pParms, void ** f_phTransport );


typedef struct
{
	tPFNTRANSPORTAPI_OPEN pfnTransportApiOpen;

	/* Close transport */
	int (*pfnTransportApiClose)( void * f_hTransport );

	/* Send data through transport handle */
	int (*pfnTransportApiSend)( void * 	f_hTransport,
		void *		f_pTransportRemoteContext,
		void *		f_pBuffer,
		tOCT_UINT32 	f_ulBufferLength );

	/* Get transport received data */
	int (*pfnTransportApiRecv)( void *	f_hTransport,
		tOCT_UINT32	f_ulTimeoutMs,
		void *		f_pBuffer,
					tOCT_UINT32	f_ulMaxBufferLength );

	/* wait for transport receive data */
	int (*pfnTransportApiSelect)( void *	f_pTransportContext,
		tOCT_UINT32	f_ulTimeoutMs,
		tOCT_UINT32	f_ulTransportCnt,
		void *	f_ahTransport[],
		tOCT_UINT32	f_aulState[] );

		int (*pfnTransportApiOpenLoopBack)( void *f_Context, void **f_phTransport );

}tOCTVC1_PKT_API_TRANSPORT_FUNC, *tPOCTVC1_PKT_API_TRANSPORT_FUNC;

/*--------------------------------------------------------------------------
	API instance intialization parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulMaxConnection;	/* Maximum connection on this instance */
	tOCT_UINT32						ulMaxSession;		/* deprecated: Maximum session per connection on this instance */

	tOCT_UINT32						ulMaxSyncCmd;		/* Maximum simultaneous synchronous command */

	tOCT_UINT32						ulMaxPendingRsp;	/* Maximum pending response packet in queue */
	tOCT_UINT32						ulMaxPendingEvt;	/* Maximum pending event packet in queue */
	tOCT_UINT32						ulMaxPendingData;	/* Maximum pending data packet in queue  */

	tOCT_UINT32						ulCmdTimeoutMs;		/* deprecated: the command timeout is taking care by the API */

	tOCT_UINT16						usSessionInstanceStart;
														/* 16 MSB of session identifier start instance */
	void *							pOsContext;			/* Depricated: Porting OS layer context, submitted to Porting OS layer functions */
	void *							pTransportContext;	/* Porting transport layer context, submitted to Porting transport layer functions */
	void *							pTransportLocalContext;
														/* Porting transport layer local context,
															submitted to Porting transport layer open function */

	tOCT_UINT8						abyLocalMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
														/* Local MAC address */

	tOCTVC1_PKT_API_TRANSPORT_FUNC	TransportFunc;		/* User defined transport functions. Default is Ethernet transport */
	tOCT_UINT32						ulMaxRetry;			/* Maximum number of retry before the command is declare as timed out */

	tOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM	AdaptorSelection;	
														/* cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_DEFAULT - Specify to use interface MAC (abyLocalMac) */
														/* cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_MAC - Specify to use interface MAC (abyLocalMac) */
														/* In some environment multiple interface can have the same MAC */
														/* Default is to use abyLocalMac */

	tOCT_INT8*						pszInterfaceName;	/* Interface name */

	tOCTVC1_PKT_API_INSTANCE_OPTION_MASK	ulOptionMask;		/* Instance option:  */
														/* cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_NONE - (default) */
														/* cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_DISABLE_TIMEOUT - Allow not to report timeout. Command response will wait forever */
	tOCT_BOOL32						fUseExternalTransport;		/* Application is taking care of the transport */
	tOCTTRANSAPI_DISPATCHER_HANDLE	hTransDispatcher;	/* Application did call OctTransApiDispatcherRun in a separate thread. PktApi does not have to get msg from transport */

} tOCTVC1_PKT_API_INST_INIT_PARMS, *tPOCTVC1_PKT_API_INST_INIT_PARMS;


/*--------------------------------------------------------------------------
	API instance Get Size Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tPOCTVC1_PKT_API_INST_INIT_PARMS
									pInitParms;			/* IN: Pointer to instance creation parameter structure */
	tOCT_UINT32						ulRequiredSize;		/* OUT: in bytes */

} tOCTVC1_PKT_API_INST_GET_SIZE_PARMS, *tPOCTVC1_PKT_API_INST_GET_SIZE_PARMS;


/*--------------------------------------------------------------------------
	API Instance terminate Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_BOOL32						fForce;				/* Force to close the instance when */

} tOCTVC1_PKT_API_INST_TERM_PARMS, *tPOCTVC1_PKT_API_INST_TERM_PARMS;

/*--------------------------------------------------------------------------
	API Instance stats Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_BOOL32						fClear;
	tOCT_UINT32						ulOpenConnectionCnt;
	tOCT_UINT32						ulOpenSessionCnt;

	/* Total number of packet sent */
	tOCT_UINT32						ulTotalPktSentCnt;

	/* Total number of resent command. Cause may be unordered response or reach of internal timeout. */
	tOCT_UINT32						ulTotalPktRetryCnt;

	/* Total number of packet received with success */
	tOCT_UINT32						ulTotalPktRecvCnt;
	tOCT_UINT32						ulTotalPktRecvEventCnt;
	tOCT_UINT32						ulTotalPktRecvDataCnt;

	/* Total number of packet reject by the MGW  */
	tOCT_UINT32						ulTotalPktRejectCnt;

	/* Total number of command that never receives response after number of retry. */
	tOCT_UINT32						ulTotalPktTimeoutCnt;

	/* Total number of packet received with invalid routing informations */
	tOCT_UINT32						ulTotalPktInvalidCnt;

	/* Total number of packet received without enough resources  */
	tOCT_UINT32						ulTotalPktDropCnt;
	tOCT_UINT32						ulTotalPktDropEventCnt;
	tOCT_UINT32						ulTotalPktDropDataCnt;

	/* Total number of response received after timeout */
	tOCT_UINT32						ulTotalPktLateRspCnt;

	/* Elapse time needed to send a command and receive the associated response to internal queue */
	tOCT_UINT32						ulLowestRoundTripMs;
	tOCT_UINT32						ulHighestRoundTripMs;

	/* Elapse time that a received response stayed in the internal queue */
	tOCT_UINT32						ulLowestExtractTimeMs;
	tOCT_UINT32						ulHighestExtractTimeMs;

	/* Longest elapse time that a received packet stayed in the transport porting layer */
	tOCT_UINT32						ulHighestTransportRxTimeMs;

	/* Longest elapse time stayed in the transport porting layer waiting without received packet */
	tOCT_UINT32						ulHighestTransportNoRxTimeMs;

} tOCTVC1_PKT_API_INST_STATS_PARMS, *tPOCTVC1_PKT_API_INST_STATS_PARMS;


/*--------------------------------------------------------------------------
	API Instance info Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	void *							pTransportContext;	/* Porting transport layer context, submitted to Porting transport layer functions */
	void *							pTransportLocalContext;
														/* Porting transport layer local context,
															submitted to Porting transport layer open function */

	tOCT_UINT8						abyLocalMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
														/* Local MAC address. Valid when fUseExternalTransport is set to FALSE.  */

	tOCT_UINT32						ulMaxConnection;	/* Maximum connection on this instance */
	tOCT_UINT32						ulMaxSession;		/* Maximum session per connection on this instance */
	tOCT_UINT32						ulMaxSyncCmd;		/* Maximum simultaneous synchronous command */

	tOCT_UINT32						ulMaxPendingRsp;	/* Maximum pending response packet in queue */
	tOCT_UINT32						ulMaxPendingEvt;	/* Maximum pending event packet in queue */
	tOCT_UINT32						ulMaxPendingData;	/* Maximum pending data packet in queue  */
	tOCT_UINT32						ulMaxRetry;			/* Maximum number of retry before the command is declare as timed out */
	tOCT_UINT16						usSessionInstanceStart;
															/* 16 MSB of session identifier start instance */
	tOCTVC1_PKT_API_INSTANCE_OPTION_MASK	ulOptionMask;	/* Instance option:  */

	/* Application is taking care of the transport */
	tOCT_BOOL32						fUseExternalTransport;		

	/* Application is responsible to call OctTransApiDispatcherRun in a separate thread */
	tOCTTRANSAPI_DISPATCHER_HANDLE	hTransDispatcher;


} tOCTVC1_PKT_API_INST_INFO_PARMS, *tPOCTVC1_PKT_API_INST_INFO_PARMS;

/*--------------------------------------------------------------------------
	API Connection Open Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_UINT8						abyRemoteMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
														/* Remote MAC address */
	void *							pTransportRemoteContext;
														/* Porting transport layer remote context,
															submitted to Porting transport layer open function */
	void *							pUserConnectionContext;
	tPOCTVC1_PKT_API_CNCT 			pConnection;		/* Pointer to allocated connection */

	tOCTTRANSAPI_DESTINATION_HANDLE	hTransDest;			/* Handle to transport destination. To be used when instance is initialize with fUseExternalTransport = cOCT_TRUE */

} tOCTVC1_PKT_API_CNCT_OPEN_PARMS, *tPOCTVC1_PKT_API_CNCT_OPEN_PARMS;


/*--------------------------------------------------------------------------
	API Connection modify Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	
	tOCT_UINT8						abyRemoteMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
														/* Remote MAC address */

	void *							pTransportRemoteContext;
														/* Porting transport layer remote context,
															submitted to Porting transport layer open function */
	void *							pUserConnectionContext;
														/* Supplied to all received packets of this connection */

	tOCTTRANSAPI_DESTINATION_HANDLE	hTransDest;			/* Handle to transport destination. To be used when instance is initialize with fUseExternalTransport = cOCT_TRUE */

} tOCTVC1_PKT_API_CNCT_MODIFY_PARMS, *tPOCTVC1_PKT_API_CNCT_MODIFY_PARMS;


/*--------------------------------------------------------------------------
	API Connection destroy Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_BOOL32						fForce;				/* Force to close all opened associated sessions and release all pending packets.*/

} tOCTVC1_PKT_API_CNCT_CLOSE_PARMS, *tPOCTVC1_PKT_API_CNCT_CLOSE_PARMS;

/*--------------------------------------------------------------------------
	API Connection stats Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_BOOL32						fClear;
	tOCT_UINT32						ulOpenSessionCnt;

	/* Total number of packet sent */
	tOCT_UINT32						ulTotalPktSentCnt;

	/* Total number of resent command. Cause may be unordered response or reach of internal timeout. */
	tOCT_UINT32						ulTotalPktRetryCnt;

	/* Total number of packet received with success */
	tOCT_UINT32						ulTotalPktRecvCnt;
	tOCT_UINT32						ulTotalPktRecvEventCnt;
	tOCT_UINT32						ulTotalPktRecvDataCnt;

	/* Total number of packet reject by the MGW  */
	tOCT_UINT32						ulTotalPktRejectCnt;

	/* Total number of command that never receives response after number of retry. */
	tOCT_UINT32						ulTotalPktTimeoutCnt;

	/* Total number of packet received with invalid routing informations */
	tOCT_UINT32						ulTotalPktInvalidCnt;

	/* Total number of packet received without enough resources  */
	tOCT_UINT32						ulTotalPktDropCnt;
	tOCT_UINT32						ulTotalPktDropEventCnt;
	tOCT_UINT32						ulTotalPktDropDataCnt;

	/* Total number of response received after timeout */
	tOCT_UINT32						ulTotalPktLateRspCnt;

	/* Elapse time needed to send a command and receive the associated response to internal queue */
	tOCT_UINT32						ulLowestRoundTripMs;
	tOCT_UINT32						ulHighestRoundTripMs;

} tOCTVC1_PKT_API_CNCT_STATS_PARMS, *tPOCTVC1_PKT_API_CNCT_STATS_PARMS;

/*--------------------------------------------------------------------------
	API Connection info Parameters
----------------------------------------------------------------------------*/

typedef struct
{

	tOCT_UINT8						abyRemoteMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
														/* Remote MAC address */

	void *							pTransportRemoteContext;
														/* Porting transport layer remote context,
															submitted to Porting transport layer open function */
	void *							pUserConnectionContext;
														/* Supplied to all received packets of this connection */
	tOCTTRANSAPI_DESTINATION_HANDLE	hTransDest;			/* Handle to transport destination. To be used when instance is initialize with fUseExternalTransport = cOCT_TRUE */

} tOCTVC1_PKT_API_CNCT_INFO_PARMS, *tPOCTVC1_PKT_API_CNCT_INFO_PARMS;

/*--------------------------------------------------------------------------
	API Session Open Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_UINT32						ulControlProcessFifoId;
														/* Control Process FIFO identifier */
	void *							pUserSessionContext;
														/* return in recv packet */
	tPOCTVC1_PKT_API_SESS 			pSession;			/* Pointer to allocated session */

} tOCTVC1_PKT_API_SESS_OPEN_PARMS, *tPOCTVC1_PKT_API_SESS_OPEN_PARMS;

/*--------------------------------------------------------------------------
	API Session destroy Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_BOOL32						fForce;				/* see connection close */

} tOCTVC1_PKT_API_SESS_CLOSE_PARMS, *tPOCTVC1_PKT_API_SESS_CLOSE_PARMS;

/*--------------------------------------------------------------------------
	API Session stats Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_BOOL32						fClear;

	/* Total number of command sent */
	tOCT_UINT32						ulPktSentCnt;

	/* Total number of resent command. Cause may be unordered response or reach of internal timeout. */
	tOCT_UINT32						ulPktRetryCnt;

	/* Total number of packet received with success */
	tOCT_UINT32						ulPktRecvCnt;

	/* Total number of packet reject by the MGW  */
	tOCT_UINT32						ulPktRejectCnt;
	
	/* Total number of command that never receives response after number of retry. */
	tOCT_UINT32						ulPktTimeoutCnt;

	/* Total number of response received after timeout */
	tOCT_UINT32						ulPktLateRspCnt;

	/* Total number of packet received with invalid routing informations */
	tOCT_UINT32						ulPktInvalidCnt;

	/* Elapse time needed to send a command and receive the associated response to internal queue */
	tOCT_UINT32						ulLowestRoundTripMs;
	tOCT_UINT32						ulHighestRoundTripMs;


} tOCTVC1_PKT_API_SESS_STATS_PARMS, *tPOCTVC1_PKT_API_SESS_STATS_PARMS;

/*--------------------------------------------------------------------------
	API Packet send Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulFormat;			/* Data packet format cOCTVOCNET_PKT_FORMAT_* */
	tOCT_UINT32						ulLength;			/* Length of data packet */
	void* 							pData;				/* Pointer to the data payload to send */

} tOCTVC1_PKT_API_DATA_SEND_PARMS, *tPOCTVC1_PKT_API_DATA_SEND_PARMS;

/*--------------------------------------------------------------------------
	API Session command send Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulCmdTimeoutMs;		/* deprecated: the command timeout is taking care by the API */
	void *							pUserCmdContext;
	void * 							pCmd;				/* Pointer to the command structure to send */

} tOCTVC1_PKT_API_CMD_SEND_PARMS, *tPOCTVC1_PKT_API_CMD_SEND_PARMS;

/*--------------------------------------------------------------------------
	API Session command execute Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulCmdTimeoutMs;		/* deprecated: the command timeout is taking care by the API */
	void * 							pCmd;				/* Pointer to the command structure to send */
	tOCT_UINT32						ulMaxRspLength;		/* Maximum size of the pRsp buffer */
	tOCT_UINT32						ulRcvRspLength;		/* Size of the payload in the pRsp buffer */
	void * 							pRsp;				/* Pointer to the received response structure */
	tOCT_UINT32						ulRoundTripMs;		/* Round trip execution time in milliseconds */
	tOCT_UINT32						ulExtractTimeMs;	/* Time between reception and removal from Q */

} tOCTVC1_PKT_API_CMD_EXECUTE_PARMS, *tPOCTVC1_PKT_API_CMD_EXECUTE_PARMS;


/*--------------------------------------------------------------------------
	API Instance Packet receive Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_PKT_API_RCV_MASK		PktRcvMask;			/* Packet receive mask */
	tOCT_UINT32						ulTimeoutMs;		/* Maximum time in milliseconds to wait for a packet  */
	void *							pPayload;			/* Payload buffer pointer. The content of the pPayload buffer is network byte ordered.
															- If packet Type is cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP, pPayload points
															  to a tOCTVC1_MSG_HEADER structure.
															- If packet Type is cOCTVC1_PKT_API_PKT_TYPE_ENUM_EVENT, pPayload points
															  to a tOCTVC1_EVENT_HEADER structure.
															- If packet Type is cOCTVC1_PKT_API_PKT_TYPE_ENUM_DATA, pPayload points
															  to a tOCTVOCNET_PKT_DATA_HEADER structure.
														*/
	tOCT_UINT32						ulMaxPayloadLength;	/* IN max payload length */

	tOCTVC1_PKT_API_PKT_TYPE_ENUM	RcvPktType;			/* Packet type cOCTVC1_PKT_API_PKT_TYPE_ENUM_* */

	tOCT_UINT32						ulRcvPayloadLength;/* OUT payload receive length */

	/* Union of header structure containing already usable field value (i.e. CPU byte ordering) */
	union
	{
		/* Response extracted header fields. From tOCTVC1_MSG_HEADER and internals */
		struct
		{
			tOCT_UINT32				ulCmdId;			/* Identifier of the command */
			tOCT_UINT32				ulReturnCode;		/* Return code of the command */
			void *					pUserCmdContext;	/* OUT: User command context */
			tOCT_UINT32				ulRoundTripMs;		/* Round trip execution time in milliseconds */
			tOCT_UINT32				ulExtractTimeMs;	/* Time between reception and removal from Q */

		} Rsp;

		struct
		{
			tOCT_UINT32				ulTimestamp;		/* Event timestamp */
			tOCTVC1_HANDLE_OBJECT	hLogicalObj;		/* Logical_Object Handle */
			tOCT_UINT32				ulLogicalObjPktPort;/* Logical_Object Packet_Port */
			tOCT_UINT32				ulDestFifoId;       /* Destination FIFO ID.*/
			tOCT_UINT32				ulEvtId;			/* Identifier of the command */
			tOCT_UINT32				ulUserEvtId;		/* User Identifier of the command */

		} Evt;

		struct
		{
			tOCT_UINT32				ulPktFormat;
			tOCT_UINT32				ulPktSubType;

		} Data;

	} Info;

	tPOCTVC1_PKT_API_CNCT			pConnection;		/* Connection pointer */
	void *							pUserConnectionContext;

	tPOCTVC1_PKT_API_SESS			pSession;			/* Session pointer */
	void *							pUserSessionContext;

} tOCTVC1_PKT_API_INST_RECV_PARMS, *tPOCTVC1_PKT_API_INST_RECV_PARMS;

/*--------------------------------------------------------------------------
	Device port information
----------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_PKT_API_DEV_PORT_TYPE_ENUM	ulPortType;		/* Type of the port */
	tOCT_BOOL32							fReachable;		/* Boolean value indicating whether or not the
															device is reachable through the instance. */
	union
	{
		struct
		{
			tOCT_UINT32					ulPortId;		/* Ethernet port identifier (0 or 1) */
			tOCT_UINT8					abyMacAddr[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
		} Eth;

		struct
		{
			tOCT_UINT8					szDestinationAddr[ cOCTRANSAPI_DESTINATION_ADDR_STR_SIZE ];
		} Transport;

	} Type;

} tOCTVC1_PKT_API_DEV_PORT_INFO, *tPOCTVC1_PKT_API_DEV_PORT_INFO;

/*--------------------------------------------------------------------------
	API Instance devices information
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32							ulPortCnt;		/* Number of port in the device */
	tOCTVC1_PKT_API_DEV_PORT_INFO		aPortInfo[ cOCTVC1_PKT_API_DEV_PORT_MAX ];
														/* Port information array */
	tOCT_UINT32							ulUserInfoLength;
														/* User information length */
	tOCT_UINT8							abyUserInfo[ cOCTVC1_PKT_API_DEV_USER_INFO_LEN_MAX ];
														/* User information buffer */

	tOCT_UINT8							abyDeviceInfo[cOCTVC1_PKT_API_DEV_INFO_LEN_MAX];
														/* User information buffer */

	tOCTTRANSAPI_HANDLE					hTransport;		/* Transport handle where the device response from */

} tOCTVC1_PKT_API_DEV_INFO, *tPOCTVC1_PKT_API_DEV_INFO;

/*--------------------------------------------------------------------------
	API Instance devices discover Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32							ulTimeoutMs;	/* Maximum time in milliseconds to wait for device detection */
	void *								pTransportDiscoverContext;
														/* Transport discover context.
															submitted to Porting transport layer send function */

	tOCT_UINT32							ulExpectedDeviceCnt;	/* Expected devices count */
	tOCT_UINT32							ulDeviceCnt;			/* Discovered devices count */
	tOCTVC1_PKT_API_DEV_INFO			aDeviceInfo[ cOCTVC1_PKT_API_DEV_MAX ];
														/* Discovered devices information array */

	/* To be used when instance is initialize with fUseExternalTransport = cOCT_TRUE */
	tOCT_UINT32							ulTransportCnt;	/* Number of transport used to discover device */
	tOCTTRANSAPI_HANDLE					ahTransport[cOCTVC1_PKT_API_DISCOVER_TRANSPORT_MAX];	/* Number of transport used to discover device */

} tOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS, *tPOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS;

/*--------------------------------------------------------------------------
	API Instance Packet receive Parameters
----------------------------------------------------------------------------*/
typedef struct
{
	void *							pTransportContext;
														/* Porting transport layer context,
																submitted to Porting transport layer functions */

	tOCT_UINT32						ulAdaptorIndex;		/* Adaptor index */

	tOCT_UINT8						abyLocalMac[ cOCTVC1_PKT_API_MAC_ADDR_SIZE ];
														/* Local MAC address */
	tOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM	AdaptorSelection;	
														/* cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_NAME - Specify to use interface name (pszInterfaceName) */
														/* cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_DEFAULT - Specify to use interface index (ulAdaptorIndex) */
														/* cOCTVC1_PKT_API_ADAPTOR_SELECTION_TYPE_ENUM_INDEX - Specify to use interface index (ulAdaptorIndex) */
														/* Default is to use index */
	tOCT_INT8*						pszInterfaceName;	/* Interface name */


} tOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS, *tPOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS;


/*--------------------------------------------------------------------------
	API get version Parameters
----------------------------------------------------------------------------*/

typedef struct
{
	tOCT_UINT32						ulApiVersionId;		/* API version ID */
	tOCT_UINT8						szApiVersion[40];	/* API version string */

} tOCTVC1_PKT_API_GET_VERSION_PARMS, *tPOCTVC1_PKT_API_GET_VERSION_PARMS;



/*****************************  FUNCTIONS ************************************/

/*--------------------------------------------------------------------------
		INSTANCE functions
----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
	OctVc1PktApiInstGetSize
		This function calculates the size required to hold the instance.

  f_pParms	: OUT pointer to get size parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiInstGetSize(
	tPOCTVC1_PKT_API_INST_GET_SIZE_PARMS			f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiInstInit
		This function initializes the packet API instance. The user layer objects
		required by the packet API instance are created within this function,
		this includes: Queue Locks, Local transport object, Loopback transport
		object.
		The packet API instance is hold in a user allocated buffer,
		the size required to hold the packet API instance must be calculated
		by invoking the OctVc1PktApiInstGetSize() function.

  f_pInstance	: IN Pointer to user allocated memory.
  f_pParms		: IN Pointer to instance creation parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiInstInit(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_INIT_PARMS				f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiInstTerm
		This function terminates a packet API instance. When successful
		the user can release the packet API instance memory.

  f_pInstance	: IN Pointer to packet API instance to destroy.
  f_pParms		: IN Pointer to instance close parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiInstTerm(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_TERM_PARMS				f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiInstStats
		This function returns the statistics of a packet API instance.

  f_pInstance	: IN Pointer to packet API instance to stats.
  f_pParms		: IN Pointer to instance stats parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiInstStats(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_STATS_PARMS				f_pParms );


/*--------------------------------------------------------------------------
	OctVc1PktApiInstInfo
		This function returns the information of a packet API instance.

  f_pInstance	: IN Pointer to packet API instance to info.
  f_pParms		: IN Pointer to instance info parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiInstInfo(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_INFO_PARMS				f_pParms );


/*--------------------------------------------------------------------------
	OctVc1PktApiInstRecv
		This function receives a packet from the specified instance.

  f_pSession	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to packet receive parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiInstRecv(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_RECV_PARMS						f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiInstDiscoverDev
		This function discovers the remote devices reachable through the
		specified instance.

  f_pSession	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to discover parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiInstDiscoverDev(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS				f_pParms );

/*--------------------------------------------------------------------------
		CONNECTION functions
----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctOpen
		This function creates the packet API connection. The user layer objects
		required by the packet API connection are created within this function,
		this includes: Remote transport object,

  f_pInstance	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to connection creation parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiCnctOpen(
	tPOCTVC1_PKT_API_INST							f_pInstance,
	tPOCTVC1_PKT_API_CNCT_OPEN_PARMS				f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctClose
		This function close a packet API connection.

  f_pInstance	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to connection close parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiCnctClose(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_CNCT_CLOSE_PARMS				f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctStats
		This function returns the statistics of a packet API connection.

  f_pInstance	: IN Pointer to packet API instance to stats.
  f_pParms		: IN Pointer to connection stats parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiCnctStats(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_CNCT_STATS_PARMS				f_pParms );


/*--------------------------------------------------------------------------
	OctVc1PktApiCnctInfo
		This function returns the information of a packet API connection.

  f_pInstance	: IN Pointer to packet API connection to stats.
  f_pParms		: IN Pointer to connection info parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiCnctInfo(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_CNCT_INFO_PARMS				f_pParms );


/*--------------------------------------------------------------------------
	OctVc1PktApiCnctDataSend
		This function sends a data packet on a connection.

  f_pSession	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to data send parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiCnctDataSend(
	tPOCTVC1_PKT_API_CNCT						f_pConnection,
	tPOCTVC1_PKT_API_DATA_SEND_PARMS			f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiCnctModify
		This function modify the packet API connection.

  f_pConnection	: IN Pointer API connection to modify.
  f_pParms		: IN Pointer to connection modify parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiCnctModify(
	tPOCTVC1_PKT_API_CNCT						f_pConnection,
	tPOCTVC1_PKT_API_CNCT_MODIFY_PARMS			f_pParms );


/*--------------------------------------------------------------------------
		SESSION functions
----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
	OctVc1PktApiSessOpen
		This function creates the packet API connection. The user layer objects
		required by the packet API session are created within this function,
		this includes: Remote transport object,

  f_pInstance	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to session creation parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiSessOpen(
	tPOCTVC1_PKT_API_CNCT							f_pConnection,
	tPOCTVC1_PKT_API_SESS_OPEN_PARMS				f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiSessClose
		This function closes a packet API session.

  f_pSession	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to session close parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiSessClose(
	tPOCTVC1_PKT_API_SESS 							f_pSession,
	tPOCTVC1_PKT_API_SESS_CLOSE_PARMS				f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiSessStats
		This function returns the statistics of a packet API connection.

  f_pInstance	: IN Pointer to packet API instance to stats.
  f_pParms		: IN Pointer to connection stats parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiSessStats(
	tPOCTVC1_PKT_API_SESS 							f_pSession,
	tPOCTVC1_PKT_API_SESS_STATS_PARMS				f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiSessCmdSend
		This function sends a command to a session. The retransmit
		mechanism is activated for the command. The response packet to the command
		is retrieved by invoking the OctVc1PktApiRecv() function with the
		receive mask set to cOCTVC1_PKT_API_PKT_TYPE_ENUM_RSP.

  f_pSession	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to command send parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiSessCmdSend(
	tPOCTVC1_PKT_API_SESS							f_pSession,
	tPOCTVC1_PKT_API_CMD_SEND_PARMS					f_pParms );

/*--------------------------------------------------------------------------
	OctVc1PktApiSessCmdExecute
		This function excutes a command on a session. The retransmit
		mechanism is activated for the command. The response packet to the command
		is returned.

		Note: When the instance was initialized with fUseMsgAllocator set to true:
			1: The structure element 'pCmd' will be release by the API function.
			2: The structure element 'pRsp' is allocated by the API and should be release by the application 
			calling OctVc1PktApiSessMsgRelease.

  f_pSession	: IN Pointer to packet API instance.
  f_pParms		: IN Pointer to command execute parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiSessCmdExecute(
	tPOCTVC1_PKT_API_SESS							f_pSession,
	tPOCTVC1_PKT_API_CMD_EXECUTE_PARMS				f_pParms );

/*--------------------------------------------------------------------------
		MISC functions
----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
	OctVc1PktApiGetLocalMacAddr
		This function returns the local MAC address of the specified adaptor
		index.

  f_pParms	: IN Pointer to get local mac parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiGetLocalMacAddr(
	tPOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS		f_pParms );



/*--------------------------------------------------------------------------
	OctVc1PktApiGetVersion
		This function returns the API version informations
		index.

  f_pParms	: IN Pointer to get version parameters structure.
----------------------------------------------------------------------------*/
extern tOCT_UINT32	OctVc1PktApiGetVersion(
	tPOCTVC1_PKT_API_GET_VERSION_PARMS		f_pParms );



/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_PKT_API_H__*/
