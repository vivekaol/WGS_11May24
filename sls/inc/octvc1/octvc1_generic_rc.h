/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_GENERIC_RC.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the return codes for the GENERIC API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_GENERIC_RC_H__
#define OCTVC1_GENERIC_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_base.h"

/****************************************************************************
	GENERIC return codes
 ****************************************************************************/
#define cOCTVC1_RC_OK										 ( 0x0000 )
#define cOCTVC1_GENERIC_RC_BAD_PARAM						 ( 0x0001 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_NOT_FOUND						 ( 0x0002 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_ALREADY_USED						 ( 0x0003 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_READ_OBJECT						 ( 0x0004 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_WRITE_OBJECT						 ( 0x0005 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_INVALID_TRANSACTION_ID			 ( 0x0006 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_ID_INVALID						 ( 0x0007 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_SUB_ID_INVALID					 ( 0x0008 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_GET_MODE_INVALID					 ( 0x0009 + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_NO_MORE_OBJECT					 ( 0x000A + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_NO_MORE_SUB_OBJECT				 ( 0x000B + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_FULL								 ( 0x000C + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_TIMEOUT							 ( 0x000D + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_BAD_STATE						 ( 0x000E + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_ALREADY_START					 ( 0x000F + cOCTVC1_GENERIC_RC_BASE )
#define cOCTVC1_GENERIC_RC_ALREADY_STOP						 ( 0x0010 + cOCTVC1_GENERIC_RC_BASE )

/****************************************************************************
	API return codes
 ****************************************************************************/
#define cOCTVC1_GENERIC_API_RC_BASE							 ( 0x0300 + cOCTVC1_GENERIC_RC_BASE )

#define cOCTVC1_GENERIC_RC_API_CMD_NOT_IMPLEMENTED			 ( 0x0001 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_CMD_REJECT					 ( 0x0002 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_CMD_RETRANSMIT				 ( 0x0003 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_SESSION_INACTIVE				 ( 0x0004 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_INVALID_CMD_LENGTH			 ( 0x0005 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_INVALID_CMD_ID				 ( 0x0006 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_ROUTING_ERROR				 ( 0x0007 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_RSP_ERROR					 ( 0x0008 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_RESTRICTED_CMD_ID			 ( 0x0009 + cOCTVC1_GENERIC_API_RC_BASE )
#define cOCTVC1_GENERIC_RC_API_CMD_APP_MODULE_NOT_STARTED	 ( 0x000A + cOCTVC1_GENERIC_API_RC_BASE )

/****************************************************************************
	MEMORY return codes
 ****************************************************************************/
#define cOCTVC1_GENERIC_MEMORY_RC_BASE						 ( 0x0400 + cOCTVC1_GENERIC_RC_BASE )

#define cOCTVC1_GENERIC_RC_MEMORY_LOCAL_ALLOC				 ( 0x0001 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_LOCAL_FREE				 ( 0x0002 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_RESIDENT_ALLOC			 ( 0x0003 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_RESIDENT_FREE				 ( 0x0004 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_EXTERNAL_ALLOC			 ( 0x0005 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_EXTERNAL_FREE				 ( 0x0006 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_EXTERNAL_READ				 ( 0x0007 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_EXTERNAL_WRITE			 ( 0x0008 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_IO_READ					 ( 0x0009 + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_IO_WRITE					 ( 0x000A + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_CHECKSUM					 ( 0x000B + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_SIZE						 ( 0x000C + cOCTVC1_GENERIC_MEMORY_RC_BASE )
#define cOCTVC1_GENERIC_RC_MEMORY_SCRATCH_BAD_RESERVE		 ( 0x000D + cOCTVC1_GENERIC_MEMORY_RC_BASE )

/****************************************************************************
	INTERNAL return codes
 ****************************************************************************/
#define cOCTVC1_GENERIC_INTERNAL_RC_BASE					 ( 0x0500 + cOCTVC1_GENERIC_RC_BASE )

#define cOCTVC1_GENERIC_RC_INTERNAL_ERROR					 ( 0x0001 + cOCTVC1_GENERIC_INTERNAL_RC_BASE )
#define cOCTVC1_GENERIC_RC_INTERNAL_SERVICE_NOT_INIT		 ( 0x0002 + cOCTVC1_GENERIC_INTERNAL_RC_BASE )
#define cOCTVC1_GENERIC_RC_INTERNAL_TIMEOUT					 ( 0x0003 + cOCTVC1_GENERIC_INTERNAL_RC_BASE )
#define cOCTVC1_GENERIC_RC_INTERNAL_MSG_UNKNOWN				 ( 0x0004 + cOCTVC1_GENERIC_INTERNAL_RC_BASE )

#endif /* OCTVC1_GENERIC_RC_H__ */

