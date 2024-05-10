/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_MAIN_RC.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the return codes for the MAIN API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_MAIN_RC_H__
#define OCTVC1_MAIN_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"
#include "octvc1_main_base.h"

/****************************************************************************
	MAIN return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_RC_PROCESS_IMAGE_LOAD_FILE_NOT_FOUND	 ( 0x0000 + cOCTVC1_MAIN_RC_BASE )
#define cOCTVC1_MAIN_RC_EVENT_MASK_INVALID					 ( 0x0005 + cOCTVC1_MAIN_RC_BASE )
#define cOCTVC1_MAIN_RC_PROCESS_NOT_FOUND					 ( 0x0007 + cOCTVC1_MAIN_RC_BASE )
#define cOCTVC1_MAIN_RC_API_SYSTEM_SESSION_NOT_ACTIVE		 ( 0x0008 + cOCTVC1_MAIN_RC_BASE )
#define cOCTVC1_MAIN_RC_RESET_STATS_ERROR					 ( 0x0009 + cOCTVC1_MAIN_RC_BASE )

/****************************************************************************
	FILE return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_FILE_RC_BASE							 ( 0x0200 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_FILE_OPEN							 ( 0x0002 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_HANDLE							 ( 0x0004 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_INVALID_ACCESS_RIGHTS			 ( 0x0005 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_WRITE							 ( 0x0006 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SEEK_UNKOWN_ORIGIN				 ( 0x0008 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SEEK_INVALID_OFFSET			 ( 0x0009 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SEEK							 ( 0x000A + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_NOT_FOUND						 ( 0x000C + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_MAX_READ_BYTE_SIZE				 ( 0x000D + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_MAX_WRITE_BYTE_SIZE			 ( 0x000E + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_NAME							 ( 0x000F + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_ALREADY_OPENED					 ( 0x0010 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_BUSY							 ( 0x0011 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_ALREADY_CLOSED					 ( 0x0012 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_NOT_OPEN						 ( 0x0013 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_FLASH_CMD_NOT_AVAILABLE		 ( 0x0014 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_GET_MODE_INVALID				 ( 0x0015 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_ACCESS_DENIED					 ( 0x0016 + cOCTVC1_MAIN_FILE_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_MAX_TRANSFERT_REACH			 ( 0x0017 + cOCTVC1_MAIN_FILE_RC_BASE )

/****************************************************************************
	FILE_SYSTEM return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE							 ( 0x0300 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_FILE_SYSTEM_INFO							 ( 0x0001 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SYSTEM_INFO_NO_MORE_FILE				 ( 0x0002 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SYSTEM_CANNOT_CLOSE_LOCAL				 ( 0x0003 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SYSTEM_CANNOT_ADD_REMOTE_FILE			 ( 0x0004 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SYSTEM_CANNOT_DELETE_REMOTE_FILE		 ( 0x0005 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SYSTEM_CANNOT_TRANSFER_REMOTE_FILE		 ( 0x0006 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SYSTEM_NAME							 ( 0x0007 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )
#define cOCTVC1_MAIN_RC_FILE_SYSTEM_CANNOT_CLOSE_FILE_STILL_OPEN	 ( 0x0008 + cOCTVC1_MAIN_FILE_SYSTEM_RC_BASE )

/****************************************************************************
	APPLICATION return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_APPLICATION_RC_BASE							 ( 0x0350 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_APPLICATION_ALREADY_START					 ( 0x0001 + cOCTVC1_MAIN_APPLICATION_RC_BASE )
#define cOCTVC1_MAIN_RC_APPLICATION_MODULE_ALREADY_START			 ( 0x0002 + cOCTVC1_MAIN_APPLICATION_RC_BASE )
#define cOCTVC1_MAIN_RC_APPLICATION_MODULE_ALREADY_STOP				 ( 0x0003 + cOCTVC1_MAIN_APPLICATION_RC_BASE )
#define cOCTVC1_MAIN_RC_APPLICATION_MODULE_MAIN_CANNOT_BE_STOP		 ( 0x0004 + cOCTVC1_MAIN_APPLICATION_RC_BASE )
#define cOCTVC1_MAIN_RC_APPLICATION_MODULE_ACCESS_DENIED			 ( 0x0005 + cOCTVC1_MAIN_APPLICATION_RC_BASE )
#define cOCTVC1_MAIN_RC_APPLICATION_MODULE_STARTED_ACTION_DENIED	 ( 0x0006 + cOCTVC1_MAIN_APPLICATION_RC_BASE )
#define cOCTVC1_MAIN_RC_APPLICATION_MODULE_PERMANENT_CANNOT_BE_STOP	 ( 0x0007 + cOCTVC1_MAIN_APPLICATION_RC_BASE )

/****************************************************************************
	LICENSING return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_LICENSING_RC_BASE						 ( 0x03A0 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_LICENSING_DENIED					 ( 0x0000 + cOCTVC1_MAIN_LICENSING_RC_BASE )
#define cOCTVC1_MAIN_RC_LICENSING_INVALID_LICENSE			 ( 0x0001 + cOCTVC1_MAIN_LICENSING_RC_BASE )
#define cOCTVC1_MAIN_RC_LICENSING_FEATURE_NOT_FOUND			 ( 0x0002 + cOCTVC1_MAIN_LICENSING_RC_BASE )

/****************************************************************************
	CPU_USAGE return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_CPU_USAGE_RC_BASE						 ( 0x0400 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_CPU_USAGE_HANDLE_INVALID			 ( 0x0000 + cOCTVC1_MAIN_CPU_USAGE_RC_BASE )
#define cOCTVC1_MAIN_RC_CPU_USAGE_THRESHOLD_INVALID			 ( 0x0001 + cOCTVC1_MAIN_CPU_USAGE_RC_BASE )
#define cOCTVC1_MAIN_RC_CPU_USAGE_NOT_ACCESSIBLE			 ( 0x0002 + cOCTVC1_MAIN_CPU_USAGE_RC_BASE )

/****************************************************************************
	API_SESSION return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_API_SESSION_RC_BASE					 ( 0x04A0 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_API_SESSION_SERVICE_NOT_INIT		 ( 0x0001 + cOCTVC1_MAIN_API_SESSION_RC_BASE )
#define cOCTVC1_MAIN_RC_API_SESSION_HEARTBEAT_ALREADY_START	 ( 0x0002 + cOCTVC1_MAIN_API_SESSION_RC_BASE )
#define cOCTVC1_MAIN_RC_API_SESSION_HEARTBEAT_NOT_START		 ( 0x0003 + cOCTVC1_MAIN_API_SESSION_RC_BASE )

/****************************************************************************
	LOG return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_LOG_RC_BASE							 ( 0x0500 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_LOG_LOGGER_NOT_INIT					 ( 0x0001 + cOCTVC1_MAIN_LOG_RC_BASE )
#define cOCTVC1_MAIN_RC_LOG_MGR_NOT_INIT					 ( 0x0002 + cOCTVC1_MAIN_LOG_RC_BASE )
#define cOCTVC1_MAIN_RC_LOG_INTERNAL_ERROR					 ( 0x0003 + cOCTVC1_MAIN_LOG_RC_BASE )
#define cOCTVC1_MAIN_RC_LOG_TRACE_ALREADY_START				 ( 0x0004 + cOCTVC1_MAIN_LOG_RC_BASE )
#define cOCTVC1_MAIN_RC_LOG_TRACE_NOT_START					 ( 0x0005 + cOCTVC1_MAIN_LOG_RC_BASE )
#define cOCTVC1_MAIN_RC_LOG_TRACE_MASK_INVALID				 ( 0x0006 + cOCTVC1_MAIN_LOG_RC_BASE )
#define cOCTVC1_MAIN_RC_LOG_TRACE_FILTER_PROCESS_EMPTY		 ( 0x0007 + cOCTVC1_MAIN_LOG_RC_BASE )

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_MAIN_AUTO_VALIDATE_RC_BASE					 ( 0xF000 + cOCTVC1_MAIN_RC_BASE )

#define cOCTVC1_MAIN_RC_LOG_TRACE_START_INVALID_FILE_SIZE	 ( 0x1 + cOCTVC1_MAIN_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_MAIN_RC_LOG_TRACE_START_INVALID_FILE_NUMBER	 ( 0x2 + cOCTVC1_MAIN_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_MAIN_RC_PROCESS_CPU_USAGE_MONITOR_INVALID_ALARM_THRESHOLD_HIGH_PERCENT	 ( 0x3 + cOCTVC1_MAIN_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_MAIN_RC_PROCESS_CPU_USAGE_MONITOR_INVALID_ALARM_THRESHOLD_LOW_PERCENT	 ( 0x4 + cOCTVC1_MAIN_AUTO_VALIDATE_RC_BASE )

#endif /* OCTVC1_MAIN_RC_H__ */

