/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_IPC.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_IPC_H__
#define __OCTVC1_IPC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Interprocess communication
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
 	IPC Header Definition
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTVC1_IPC_MSG_FLAG_MASK :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IPC_MSG_FLAG_MASK							tOCT_UINT8

#define cOCTVC1_IPC_MSG_FLAG_MASK_VALID						0x1		
#define cOCTVC1_IPC_MSG_FLAG_MASK_ERROR						0x8		
#define cOCTVC1_IPC_MSG_FLAG_BIT_OFFSET						28		
#define cOCTVC1_IPC_MSG_FLAG_BIT_MASK						0xF0000000	

/*-------------------------------------------------------------------------------------
 	IPC Message Header sequence.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_IPC_MSG_SEQUENCE_BIT_OFFSET					20		
#define cOCTVC1_IPC_MSG_SEQUENCE_BIT_MASK					0x0FF00000	

/*-------------------------------------------------------------------------------------
 	IPC Message Header ID.
-------------------------------------------------------------------------------------*/
#define cOCTVC1_IPC_MSG_ID_BIT_OFFSET						0		
#define cOCTVC1_IPC_MSG_ID_BIT_MASK							0x000FFFFF	
/*-------------------------------------------------------------------------------------
	tOCTVC1_IPC_MSG_HEADER
 		IPC message Header

 Members:
	ulFlag_Seq_Id
 		bits[31:28] = Message flag tOCTVC1_IPC_MSG_FLAG_MASK_.
 		bits[27:20] = Sequence number
 		bits[19:0] = IPC Message Id.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulFlag_Seq_Id;

} tOCTVC1_IPC_MSG_HEADER;


#endif /* __OCTVC1_IPC_H__ */

