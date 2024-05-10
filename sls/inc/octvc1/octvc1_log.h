/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LOG.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_LOG_H__
#define __OCTVC1_LOG_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Log and trace
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LOG_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LOG_TYPE_ENUM								tOCT_UINT32

#define cOCTVC1_LOG_TYPE_ENUM_LOG							0		
#define cOCTVC1_LOG_TYPE_ENUM_TRACE							1		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LOG_LEVEL_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LOG_LEVEL_ENUM								tOCT_UINT32

#define cOCTVC1_LOG_LEVEL_ENUM_EMERGENCY					0		
#define cOCTVC1_LOG_LEVEL_ENUM_ALERT						1		
#define cOCTVC1_LOG_LEVEL_ENUM_CRITICAL						2		
#define cOCTVC1_LOG_LEVEL_ENUM_ERROR						3		
#define cOCTVC1_LOG_LEVEL_ENUM_WARNING						4		
#define cOCTVC1_LOG_LEVEL_ENUM_NOTICE						5		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LOG_PAYLOAD_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LOG_PAYLOAD_TYPE_ENUM						tOCT_UINT32

#define cOCTVC1_LOG_PAYLOAD_TYPE_ENUM_DATA					0		
#define cOCTVC1_LOG_PAYLOAD_TYPE_ENUM_STRING				1		
#define cOCTVC1_LOG_PAYLOAD_TYPE_ENUM_RC					2		
#define cOCTVC1_LOG_PAYLOAD_TYPE_ENUM_MODULE_DATA			3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LOG_TRACE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LOG_TRACE_ENUM								tOCT_UINT32

#define cOCTVC1_LOG_TRACE_ENUM_USER_0						0		
#define cOCTVC1_LOG_TRACE_ENUM_USER_1						1		
#define cOCTVC1_LOG_TRACE_ENUM_USER_2						2		
#define cOCTVC1_LOG_TRACE_ENUM_USER_3						3		
#define cOCTVC1_LOG_TRACE_ENUM_USER_4						4		
#define cOCTVC1_LOG_TRACE_ENUM_USER_5						5		
#define cOCTVC1_LOG_TRACE_ENUM_USER_6						6		
#define cOCTVC1_LOG_TRACE_ENUM_USER_7						7		
#define cOCTVC1_LOG_TRACE_ENUM_SYSTEM						8		
#define cOCTVC1_LOG_TRACE_ENUM_IPC_MESSAGE					9		
#define cOCTVC1_LOG_TRACE_ENUM_RESOURCE						10		

/*-------------------------------------------------------------------------------------
	tOCTVC1_LOG_TRACE_MASK :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LOG_TRACE_MASK								tOCT_UINT32

#define cOCTVC1_LOG_TRACE_MASK_USER_0						0x0001	
#define cOCTVC1_LOG_TRACE_MASK_USER_1						0x0002	
#define cOCTVC1_LOG_TRACE_MASK_USER_2						0x0004	
#define cOCTVC1_LOG_TRACE_MASK_USER_3						0x0008	
#define cOCTVC1_LOG_TRACE_MASK_USER_4						0x0010	
#define cOCTVC1_LOG_TRACE_MASK_USER_5						0x0020	
#define cOCTVC1_LOG_TRACE_MASK_USER_6						0x0040	
#define cOCTVC1_LOG_TRACE_MASK_USER_7						0x0080	
#define cOCTVC1_LOG_TRACE_MASK_SYSTEM						0x0100	
#define cOCTVC1_LOG_TRACE_MASK_IPC_MESSAGE					0x0200	
#define cOCTVC1_LOG_TRACE_MASK_RESOURCE						0x0400	
#define cOCTVC1_LOG_TRACE_MASK_NONE							0x0000	
#define cOCTVC1_LOG_TRACE_MASK_ALL							0xFFFFFFFF	

/*-------------------------------------------------------------------------------------
	tOCTVC1_LOG_ID :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_LOG_ID										tOCT_UINT32


/*-------------------------------------------------------------------------------------
 	Log Header Type
-------------------------------------------------------------------------------------*/
#define cOCTVC1_LOG_TYPE_BIT_OFFSET							28		
#define cOCTVC1_LOG_TYPE_BIT_MASK							0xF0000000	

/*-------------------------------------------------------------------------------------
 	Log Header Fragment Extra Entry.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_LOG_FRAGMENT_BIT_OFFSET						27		
#define cOCTVC1_LOG_FRAGMENT_BIT_MASK						0x08000000	

/*-------------------------------------------------------------------------------------
 	Log Header string data
-------------------------------------------------------------------------------------*/
#define cOCTVC1_LOG_PAYLOAD_TYPE_BIT_OFFSET					25		
#define cOCTVC1_LOG_PAYLOAD_TYPE_BIT_MASK					0x06000000	

/*-------------------------------------------------------------------------------------
 	Log Header info
 	If TYPE_LOG info value map to tOCTVC1_LOG_LEVEL_ENUM
 	If TYPE_TRACE info value map to tOCTVC1_LOG_TRACE_MASK
-------------------------------------------------------------------------------------*/
#define cOCTVC1_LOG_INFO_BIT_OFFSET							16		
#define cOCTVC1_LOG_INFO_BIT_MASK							0x00FF0000	

/*-------------------------------------------------------------------------------------
 	Log Header payload length
-------------------------------------------------------------------------------------*/
#define cOCTVC1_LOG_PAYLOAD_LENGTH_BIT_OFFSET				0		
#define cOCTVC1_LOG_PAYLOAD_LENGTH_BIT_MASK					0x0000FFFF	
/*-------------------------------------------------------------------------------------
	tOCTVC1_LOG_HEADER
 		Log and trace Header

 Members:
	ulId
	ulTime
 		Time of log, base on system time
	hProcess
 		Process handle
	ul_Type_Info_Length
 		bits[31:28] = Log TYPE tOCTVC1_LOG_TYPE_ENUM.
 		bits[27] = Fragment Extra Entry will follow.
 		bits[26:25] = Payload TYPE tOCTVC1_LOG_PAYLOAD_TYPE_ENUM.
 		bits[24] = Reserved.
 		bits[23:16] = Type Info base of Log Type see tOCTVC1_LOG_TYPE_ENUM
 		If TYPE_LOG base tOCTVC1_LOG_LEVEL_ENUM
 		If TYPE_TRACE base tOCTVC1_LOG_TRACE_ENUM
 		bits[15:0] = Log or Trace payload length (in bytes).
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulId;
	tOCT_UINT32	ulTime;
	tOCT_UINT32	hProcess;
	tOCT_UINT32	ul_Type_Info_Length;

} tOCTVC1_LOG_HEADER;


#endif /* __OCTVC1_LOG_H__ */

