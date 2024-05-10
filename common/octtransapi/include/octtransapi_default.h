/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTTRANSAPI_DEFAULT.h

Copyright (c) 2017 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic System Development Framework OCTSYSTEM-02.14.00-B304 (2017/11/15)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTRANSAPI_DEFAULT_H__
#define __OCTTRANSAPI_DEFAULT_H__

/*****************************  INCLUDE FILES  *******************************/
#include <memory.h>
#include "octtransapi.h"

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  MACROS ************************************/

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_INIT_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_INIT_PARMS_DEF( _f_pParms )	\
	{												\
		tOCTTRANSAPI_INIT_PARMS *	_pParms;		\
		_pParms = (_f_pParms);						\
		memset( _pParms, 0, sizeof(*_pParms) );		\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_GET_LAST_ERROR_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_GET_LAST_ERROR_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_GET_LAST_ERROR_PARMS *	_pParms;	\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );			\
	}



/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_TERMINATE_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_TERMINATE_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_TERMINATE_PARMS *	_pParms;		\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );			\
	}



/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_SELECT_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_SELECT_PARMS_DEF( _f_pParms )	\
	{												\
		tOCTTRANSAPI_SELECT_PARMS *	_pParms;		\
		_pParms = (_f_pParms);						\
		memset( _pParms, 0, sizeof(*_pParms) );		\
		_pParms->ulTimeoutMs		= cOCTTRANSAPI_TIMEOUT_FOREVER;	\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_RECV_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_RECV_PARMS_DEF( _f_pParms )	\
	{												\
		tOCTTRANSAPI_RECV_PARMS *	_pParms;		\
		_pParms = (_f_pParms);						\
		memset( _pParms, 0, sizeof(*_pParms) );		\
		_pParms->ulTimeoutMs		= cOCTTRANSAPI_TIMEOUT_FOREVER;	\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_SET_DISPATCHER_CB_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_SET_DISPATCHER_CB_PARMS_DEF( _f_pParms )	\
	{														\
		tOCTTRANSAPI_SET_DISPATCHER_CB_PARMS *	_pParms;	\
		_pParms = (_f_pParms);								\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DESTINATION_ADD_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DESTINATION_ADD_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_DESTINATION_ADD_PARMS *	_pParms;	\
		_pParms = (_f_pParms);								\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DESTINATION_INFO_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DESTINATION_INFO_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_DESTINATION_INFO_PARMS *	_pParms;		\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DESTINATION_SEND_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DESTINATION_SEND_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_DESTINATION_SEND_PARMS *	_pParms;	\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_DESTINATION_PAYLOAD_HEADER_INFO_PARMS *	_pParms;	\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );			\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_MSG_SEIZE_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_MSG_SEIZE_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_MSG_SEIZE_PARMS *	_pParms;		\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );				\
		_pParms->ulMsgPayloadSize		= cOCTTRANSAPI_MSG_ALLOCATOR_MSG_MAX_SIZE;	\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_MSG_ALLOCATOR_INIT_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_MSG_ALLOCATOR_INIT_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_MSG_ALLOCATOR_INIT_PARMS *	_pParms;		\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_MSG_ALLOCATOR_STATUS_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_MSG_ALLOCATOR_STATUS_PARMS_DEF( _f_pParms )	\
	{													\
		tOCTTRANSAPI_MSG_ALLOCATOR_STATUS_PARMS *	_pParms;		\
		_pParms = (_f_pParms);							\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DISPATCHER_OPEN_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DISPATCHER_OPEN_PARMS_DEF( _f_pParms )	\
	{														\
		tOCTTRANSAPI_DISPATCHER_OPEN_PARMS *	_pParms;	\
		_pParms = (_f_pParms);								\
		memset( _pParms, 0, sizeof(*_pParms) );				\
		_pParms->ulRxBufferSize				= 2048;			\
		_pParms->ulElapseInactivityMs		= 50;			\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS_DEF( _f_pParms )	\
	{														\
		tOCTTRANSAPI_DISPATCHER_SET_INACTIVITY_PARMS *	_pParms;	\
		_pParms = (_f_pParms);								\
		memset( _pParms, 0, sizeof(*_pParms) );				\
		_pParms->ulElapseInactivityMs		= 50;			\
	}



/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS_DEF( _f_pParms )	\
	{														\
		tOCTTRANSAPI_DISPATCHER_INACTIVITY_PARMS *	_pParms;	\
		_pParms = (_f_pParms);								\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}



/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS_DEF( _f_pParms )	\
	{																	\
		tOCTTRANSAPI_DISPATCHER_ADD_TRANSPORT_PARMS *	_pParms;		\
		_pParms = (_f_pParms);											\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}


/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DISPATCHER_RUN_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DISPATCHER_RUN_PARMS_DEF( _f_pParms )	\
	{														\
		tOCTTRANSAPI_DISPATCHER_RUN_PARMS *	_pParms;		\
		_pParms = (_f_pParms);								\
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}

/*----------------------------------------------------------------------------
	Default macro for tOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS structure
----------------------------------------------------------------------------*/
#define mOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS_DEF( _f_pParms )	\
	{														\
		tOCTTRANSAPI_DISPATCHER_GET_STATUS_PARMS *	_pParms;	\
		_pParms = (_f_pParms);								\
		_pParms->ulState			= cOCTTRANSAPI_DISPATCHER_STATE_ENUM_NONE; \
		memset( _pParms, 0, sizeof(*_pParms) );				\
	}




/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __OCTTRANSAPI_DEFAULT_H__ */


