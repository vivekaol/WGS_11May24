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

#ifndef __OCTVC1_PKT_API_DEF_H__
#define __OCTVC1_PKT_API_DEF_H__

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_pkt_api.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/

/*--------------------------------------------------------------------------
		INSTANCE Default structure macros
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_INST_GET_SIZE_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_INST_GET_SIZE_PARMS_DEF( _f_pParms )	\
	{															\
		tOCTVC1_PKT_API_INST_GET_SIZE_PARMS *	_pParms;		\
		_pParms = (_f_pParms);									\
		_pParms->pInitParms		= 0x0;							\
		_pParms->ulRequiredSize	= 0;							\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_INST_INIT_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_INST_INIT_PARMS_DEF( _f_pParms )		\
	{															\
		tOCTVC1_PKT_API_INST_INIT_PARMS *	_pParms;			\
		_pParms = (_f_pParms);									\
		_pParms->ulCmdTimeoutMs			= 2000;					\
		_pParms->ulMaxRetry				= 1;					\
		_pParms->ulMaxConnection		= 2;					\
		_pParms->ulMaxSession			= 1;					\
		_pParms->ulMaxSyncCmd			= 8;					\
		_pParms->ulMaxPendingRsp		= 8;					\
		_pParms->ulMaxPendingEvt		= 8;					\
		_pParms->ulMaxPendingData		= 8;					\
		_pParms->usSessionInstanceStart	= 0;					\
		_pParms->pOsContext				= 0x0;					\
		_pParms->pTransportContext		= 0x0;					\
		_pParms->pTransportLocalContext	= 0x0;					\
		_pParms->AdaptorSelection		= 0;					\
		_pParms->abyLocalMac[0]			= 0x0;					\
		_pParms->abyLocalMac[1]			= 0x0;					\
		_pParms->abyLocalMac[2]			= 0x0;					\
		_pParms->abyLocalMac[3]			= 0x0;					\
		_pParms->abyLocalMac[4]			= 0x0;					\
		_pParms->abyLocalMac[5]			= 0x0;					\
		_pParms->pszInterfaceName		= NULL;					\
		_pParms->ulOptionMask			= cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_NONE;	\
		_pParms->TransportFunc.pfnTransportApiOpen = 0x0;		\
		_pParms->TransportFunc.pfnTransportApiClose = 0x0;		\
		_pParms->TransportFunc.pfnTransportApiSend = 0x0;		\
		_pParms->TransportFunc.pfnTransportApiRecv = 0x0;		\
		_pParms->TransportFunc.pfnTransportApiSelect = 0x0;		\
		_pParms->TransportFunc.pfnTransportApiOpenLoopBack = 0x0;\
		_pParms->fUseExternalTransport	= cOCT_FALSE;			\
		_pParms->hTransDispatcher		= NULL;			\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_INST_TERM_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_INST_TERM_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_INST_TERM_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->fForce						= cOCT_FALSE;					\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_INST_STATS_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_INST_STATS_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_INST_STATS_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->fClear						= cOCT_FALSE;					\
		_pParms->ulOpenConnectionCnt		= 0;							\
		_pParms->ulOpenSessionCnt			= 0;							\
		_pParms->ulTotalPktSentCnt			= 0;							\
		_pParms->ulTotalPktRecvCnt			= 0;							\
		_pParms->ulTotalPktRejectCnt		= 0;							\
		_pParms->ulTotalPktTimeoutCnt		= 0;							\
		_pParms->ulTotalPktInvalidCnt		= 0;							\
		_pParms->ulTotalPktDropCnt			= 0;							\
		_pParms->ulTotalPktLateRspCnt		= 0;							\
	}



/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_INST_INFO_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_INST_INFO_PARMS_DEF( _f_pParms )		\
	{															\
		tOCTVC1_PKT_API_INST_INFO_PARMS *	_pParms;			\
		_pParms = (_f_pParms);									\
		_pParms->pTransportContext		= 0x0;					\
		_pParms->pTransportLocalContext	= 0x0;					\
		_pParms->abyLocalMac[0]			= 0x0;					\
		_pParms->abyLocalMac[1]			= 0x0;					\
		_pParms->abyLocalMac[2]			= 0x0;					\
		_pParms->abyLocalMac[3]			= 0x0;					\
		_pParms->abyLocalMac[4]			= 0x0;					\
		_pParms->abyLocalMac[5]			= 0x0;					\
		_pParms->ulOptionMask			= cOCTVC1_PKT_API_INSTANCE_OPTION_MASK_NONE;	\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_INST_DISCOVER_DEV_PARMS *	_pParms;					\
		_pParms = (_f_pParms);												\
		_pParms->ulTimeoutMs				= 500;							\
		_pParms->pTransportDiscoverContext	= NULL;							\
		_pParms->ulExpectedDeviceCnt		= 0;							\
		_pParms->ulDeviceCnt				= 0;							\
		_pParms->ulTransportCnt				= 0;							\
	}




/*--------------------------------------------------------------------------
		CONNECTION Default structure macros
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_CNCT_OPEN_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_CNCT_OPEN_PARMS_DEF( _f_pParms )		\
	{															\
		tOCTVC1_PKT_API_CNCT_OPEN_PARMS *	_pParms;			\
		_pParms = (_f_pParms);									\
		_pParms->abyRemoteMac[0]			= 0x0;				\
		_pParms->abyRemoteMac[1]			= 0x0;				\
		_pParms->abyRemoteMac[2]			= 0x0;				\
		_pParms->abyRemoteMac[3]			= 0x0;				\
		_pParms->abyRemoteMac[4]			= 0x0;				\
		_pParms->abyRemoteMac[5]			= 0x0;				\
		_pParms->pTransportRemoteContext	= NULL;				\
		_pParms->pUserConnectionContext		= NULL;				\
		_pParms->pConnection				= NULL;				\
		_pParms->hTransDest					= NULL;				\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_CNCT_CLOSE_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_CNCT_CLOSE_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_CNCT_CLOSE_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->fForce						= cOCT_FALSE;					\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_CNCT_STATS_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_CNCT_STATS_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_CNCT_STATS_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->fClear						= cOCT_FALSE;					\
		_pParms->ulOpenSessionCnt			= 0;							\
		_pParms->ulTotalPktSentCnt			= 0;							\
		_pParms->ulTotalPktRecvCnt			= 0;							\
		_pParms->ulTotalPktRejectCnt		= 0;							\
		_pParms->ulTotalPktTimeoutCnt		= 0;							\
		_pParms->ulTotalPktDropCnt			= 0;							\
		_pParms->ulTotalPktLateRspCnt		= 0;							\
	}



/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_CNCT_INFO_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_CNCT_INFO_PARMS_DEF( _f_pParms )		\
	{															\
		tOCTVC1_PKT_API_CNCT_INFO_PARMS *	_pParms;			\
		_pParms = (_f_pParms);									\
		_pParms->abyRemoteMac[0]			= 0x0;				\
		_pParms->abyRemoteMac[1]			= 0x0;				\
		_pParms->abyRemoteMac[2]			= 0x0;				\
		_pParms->abyRemoteMac[3]			= 0x0;				\
		_pParms->abyRemoteMac[4]			= 0x0;				\
		_pParms->abyRemoteMac[5]			= 0x0;				\
		_pParms->pTransportRemoteContext	= NULL;				\
		_pParms->pUserConnectionContext		= NULL;				\
		_pParms->hTransDest					= NULL;				\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_CNCT_MODIFY_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_CNCT_MODIFY_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_CNCT_MODIFY_PARMS *	_pParms;			\
		_pParms = (_f_pParms);									\
		_pParms->abyRemoteMac[0]			= 0x0;				\
		_pParms->abyRemoteMac[1]			= 0x0;				\
		_pParms->abyRemoteMac[2]			= 0x0;				\
		_pParms->abyRemoteMac[3]			= 0x0;				\
		_pParms->abyRemoteMac[4]			= 0x0;				\
		_pParms->abyRemoteMac[5]			= 0x0;				\
		_pParms->pTransportRemoteContext	= NULL;				\
		_pParms->pUserConnectionContext		= NULL;				\
		_pParms->hTransDest					= NULL;				\
	}



/*--------------------------------------------------------------------------
		SESSION Default structure macros
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_SESS_OPEN_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_SESS_OPEN_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_SESS_OPEN_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->ulControlProcessFifoId		= cOCTVC1_FIFO_ID_CONTROL;		\
		_pParms->pUserSessionContext		= NULL;							\
		_pParms->pSession					= NULL;							\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_SESS_CLOSE_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_SESS_CLOSE_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_SESS_CLOSE_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->fForce						= cOCT_FALSE;					\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_SESS_STATS_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_SESS_STATS_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_SESS_STATS_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->fClear						= cOCT_FALSE;					\
		_pParms->ulPktSentCnt				= 0;							\
		_pParms->ulPktRecvCnt				= 0;							\
		_pParms->ulPktRejectCnt				= 0;							\
		_pParms->ulPktTimeoutCnt			= 0;							\
		_pParms->ulPktLateRspCnt			= 0;							\
	}


/*--------------------------------------------------------------------------
		Common Default structure macros
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_INST_RECV_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_INST_RECV_PARMS_DEF( _f_pParms )								\
	{																			\
		tOCTVC1_PKT_API_INST_RECV_PARMS *	_pParms;								\
		_pParms = (_f_pParms);													\
		_pParms->PktRcvMask					= cOCTVC1_PKT_API_RCV_MASK_ALL;		\
		_pParms->ulTimeoutMs				= cOCTVC1_PKT_API_FOREVER;			\
		_pParms->pPayload					= NULL;								\
		_pParms->ulMaxPayloadLength			= 0;								\
		_pParms->RcvPktType					= cOCTVC1_PKT_API_PKT_TYPE_ENUM_INVALID;	\
		_pParms->ulRcvPayloadLength			= 0;								\
		_pParms->Info.Rsp.ulCmdId			= 0;								\
		_pParms->Info.Rsp.ulReturnCode		= 0;								\
		_pParms->Info.Rsp.pUserCmdContext	= NULL;								\
		_pParms->pConnection				= NULL;								\
		_pParms->pUserConnectionContext		= NULL;								\
		_pParms->pSession					= NULL;								\
		_pParms->pUserSessionContext		= NULL;								\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_DATA_SEND_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_DATA_SEND_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_DATA_SEND_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->ulFormat					= cOCTVOCNET_PKT_FORMAT_MODULE_DATA;	\
		_pParms->ulLength					= 0;							\
		_pParms->pData						= NULL;							\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_CMD_SEND_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_CMD_SEND_PARMS_DEF( _f_pParms )						\
	{																		\
		tOCTVC1_PKT_API_CMD_SEND_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->pUserCmdContext			= NULL;							\
		_pParms->pCmd						= NULL;							\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_CMD_EXECUTE_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_CMD_EXECUTE_PARMS_DEF( _f_pParms )					\
	{																		\
		tOCTVC1_PKT_API_CMD_EXECUTE_PARMS *	_pParms;						\
		_pParms = (_f_pParms);												\
		_pParms->pCmd						= NULL;							\
		_pParms->ulMaxRspLength				= 0;							\
		_pParms->ulRcvRspLength				= 0;							\
		_pParms->pRsp						= NULL;							\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS_DEF( _f_pParms )			\
	{																		\
		tOCTVC1_PKT_API_SYSTEM_GET_MAC_ADDR_PARMS *	_pParms;				\
		_pParms = (_f_pParms);												\
		_pParms->pTransportContext			= NULL;							\
		_pParms->AdaptorSelection			= 0;					\
		_pParms->pszInterfaceName			= NULL;							\
		_pParms->ulAdaptorIndex				= 0;							\
		_pParms->abyLocalMac[0]				= 0;							\
		_pParms->abyLocalMac[1]				= 0;							\
		_pParms->abyLocalMac[2]				= 0;							\
		_pParms->abyLocalMac[3]				= 0;							\
		_pParms->abyLocalMac[4]				= 0;							\
		_pParms->abyLocalMac[5]				= 0;							\
	}

/***************************  STRUCTURES *************************************/



/*****************************  FUNCTIONS ************************************/

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_PKT_API_DEF_H__*/
