/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_MSG.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_MSG_H__
#define __OCTVC1_MSG_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvocnet_pkt.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Message Types
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_TYPE_COMMAND							0		
#define cOCTVC1_MSG_TYPE_RESPONSE							1		
#define cOCTVC1_MSG_TYPE_NOTIFICATION						2		
#define cOCTVC1_MSG_TYPE_SUPERVISORY						7		
#define cOCTVC1_MSG_TYPE_BIT_OFFSET							29		
#define cOCTVC1_MSG_TYPE_BIT_MASK							0x7		

/*-------------------------------------------------------------------------------------
 	Message Resynch
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_RESYNCH_BIT_OFFSET						28		
#define cOCTVC1_MSG_RESYNCH_BIT_MASK						0x1		

/*-------------------------------------------------------------------------------------
 	Message identifier
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_ID_BIT_OFFSET							0		
#define cOCTVC1_MSG_ID_BIT_MASK								0x0FFFFFFF	

/*-------------------------------------------------------------------------------------
 	Message identifier - Method ID
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_METHOD_ID_BIT_OFFSET					0		
#define cOCTVC1_MSG_METHOD_BIT_MASK							0x00000FFF	

/*-------------------------------------------------------------------------------------
 	Message identifier - Module ID
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_MODULE_ID_BIT_OFFSET					16		
#define cOCTVC1_MSG_MODULE_BIT_MASK							0x0000001F	

/*-------------------------------------------------------------------------------------
 	Message identifier - SUB Module ID
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_SUB_MODULE_ID_BIT_OFFSET				21		
#define cOCTVC1_MSG_SUB_MODULE_BIT_MASK						0x00000007	

/*-------------------------------------------------------------------------------------
 	Message identifier - Module and MethodID
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_MODULE_AND_METHOD_BIT_MASK				((cOCTVC1_MSG_SUB_MODULE_BIT_MASK<<cOCTVC1_MSG_SUB_MODULE_ID_BIT_OFFSET)|(cOCTVC1_MSG_MODULE_BIT_MASK<<cOCTVC1_MSG_MODULE_ID_BIT_OFFSET)|(cOCTVC1_MSG_METHOD_BIT_MASK<<cOCTVC1_MSG_METHOD_ID_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	Message data length
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_LENGTH_BIT_OFFSET						0		
#define cOCTVC1_MSG_LENGTH_BIT_MASK							0x00003FFF	

/*-------------------------------------------------------------------------------------
 	Message format
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_FORMAT_BIT_OFFSET						24		
#define cOCTVC1_MSG_FORMAT_BIT_MASK							0x000000FF	

/*-------------------------------------------------------------------------------------
 	Message flags
-------------------------------------------------------------------------------------*/
#define cOCTVC1_MSG_FLAGS_BIT_OFFSET						12		
#define cOCTVC1_MSG_FLAGS_BIT_MASK							0xF		

/*-------------------------------------------------------------------------------------
	tOCTVC1_MSG_FLAGS_MASK :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_MSG_FLAGS_MASK								tOCT_UINT32

#define cOCTVC1_MSG_FLAGS_MASK_MID_PROCESSING				0x1		
#define cOCTVC1_MSG_FLAGS_MASK_RETRANSMIT					0x2		
#define cOCTVC1_MSG_FLAGS_MASK_NO_RESPONSE					0x4		
#define cOCTVC1_MSG_FLAGS_MASK_LONG_PROCESSING				0x8		
#define cOCTVC1_MSG_MID_PROCESSING_FLAG						((cOCTVC1_MSG_FLAGS_MASK_MID_PROCESSING&cOCTVC1_MSG_FLAGS_BIT_MASK)<<cOCTVC1_MSG_FLAGS_BIT_OFFSET)	
#define cOCTVC1_MSG_NO_RESPONSE_FLAG						((cOCTVC1_MSG_FLAGS_MASK_NO_RESPONSE&cOCTVC1_MSG_FLAGS_BIT_MASK)<<cOCTVC1_MSG_FLAGS_BIT_OFFSET)	
#define cOCTVC1_MSG_LONG_PROCESSING_FLAG					((cOCTVC1_MSG_FLAGS_MASK_LONG_PROCESSING&cOCTVC1_MSG_FLAGS_BIT_MASK)<<cOCTVC1_MSG_FLAGS_BIT_OFFSET)	
#define cOCTVC1_MSG_RETRANSMIT_FLAG							((cOCTVC1_MSG_FLAGS_MASK_RETRANSMIT&cOCTVC1_MSG_FLAGS_BIT_MASK)<<cOCTVC1_MSG_FLAGS_BIT_OFFSET)	

#define cOCTVC1_MSG_MAX_SESSIONS							8		
#define cOCTVC1_SUPERVISORY_MSG_MODULE_REJECT_CID			0x00100001	

/*-------------------------------------------------------------------------------------
	tOCTVC1_MSG_HEADER

 Members:
	ulLength
 		API Message Length (in bytes)
	ulTransactionId
 		Transaction ID.
	ul_Type_R_CmdId
 		bits[31:29] = Message type. bits[28] = API Session Resynch. bits[27:0] = API
 		Command ID.
	ulSessionId
 		API Session ID.
	ulReturnCode
 		Return code.
	ulUserInfo
 		User information.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulLength;
	tOCT_UINT32	ulTransactionId;
	tOCT_UINT32	ul_Type_R_CmdId;
	tOCT_UINT32	ulSessionId;
	tOCT_UINT32	ulReturnCode;
	tOCT_UINT32	ulUserInfo;/* NOSWAPMAC */

} tOCTVC1_MSG_HEADER;

/*-------------------------------------------------------------------------------------
	tOCTVC1_EVENT_HEADER
 		Vocallo API Common Event Message Header

 Members:
	ulLength
	ulEventId
	ulUserEventId
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulLength;
	tOCT_UINT32	ulEventId;
	tOCT_UINT32	ulUserEventId;

} tOCTVC1_EVENT_HEADER;


#endif /* __OCTVC1_MSG_H__ */

