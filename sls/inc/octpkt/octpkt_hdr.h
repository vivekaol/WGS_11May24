/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTPKT_HDR.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTPKT_HDR_H__
#define __OCTPKT_HDR_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

#define cOCTPKT_HDR_ETHERTYPE								0x5200	

/*-------------------------------------------------------------------------------------
 	OctPkt-Packet Format Values
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK :
-------------------------------------------------------------------------------------*/
#define tOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK									tOCT_UINT32

#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK						0x000000FF	
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET					24		
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT								((tOCT_UINT32)(cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK<<cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET) )	

#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE_BIT_MASK						0x00000001	
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE_BIT_OFFSET						23		
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE								((tOCT_UINT32)(cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE_BIT_MASK<<cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE_BIT_OFFSET) )	

#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK		0x0000000F	
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_OFFSET		11		
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE				((tOCT_UINT32)(cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK<<cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_OFFSET) )	

#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK						0x000007FF	
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET					0		
#define cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH								((tOCT_UINT32)(cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK<<cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET) )	


/*-------------------------------------------------------------------------------------
	tOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM				tOCT_UINT32

#define cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_OCTVOCNET	0x0		 	/* Vocallo MGW Control Protocol */
#define cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_OCTMFA		0x1		 	/* Media Flow Aggregator Control Protocol */
#define cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_LTE_FAPI		0x2		 	/* SDR LTE femtocells API Protocol */
#define cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_TEST			0xE		 	/* TEST Protocol */
#define cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_NONE			0xFFFFFFFF	 	/* Not used */


/*-------------------------------------------------------------------------------------
	tOCTPKT_HDR
 		COMMON Packet Header
 		32-bit value
 		bits[31:24] = Format
 		bit[23] = Trace Flag
 		bits[22:15] = 0=Reserved
 		bits[14:11] = Control Protocol Type
 		bits[10:0] = Total Packet Size in bytes

 Members:
	ul_Format_Trace_Length
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK	ul_Format_Trace_Length;

} tOCTPKT_HDR;


/*-------------------------------------------------------------------------------------
	tOCTPKT_HDR_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTPKT_HDR_TYPE_ENUM								tOCT_UINT32

#define cOCTPKT_HDR_TYPE_ENUM_NONE							0		 	/* Unused PktHdr */
#define cOCTPKT_HDR_TYPE_ENUM_NORMAL						1		 	/* Normal OctPktHdr */
#define cOCTPKT_HDR_TYPE_ENUM_XL							2		 	/* XL OctPktHdr */


#endif /* __OCTPKT_HDR_H__ */

