/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTPKT_HDRXL.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTPKT_HDRXL_H__
#define __OCTPKT_HDRXL_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octpkt_hdr.h"


/************************  COMMON DEFINITIONS  *******************************/

#define cOCTPKT_HDRXL_ETHERTYPE								0x5201	

/*-------------------------------------------------------------------------------------
 	OctPkt-Packet Format Values
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK :
-------------------------------------------------------------------------------------*/
#define tOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK									tOCT_UINT32

#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK					0x000000FF	
#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET					16		
#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT								((tOCT_UINT32)(cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK<<cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET) )	

#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK		0x0000000F	
#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_OFFSET	28		
#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE				((tOCT_UINT32)(cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK<<cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_OFFSET) )	

#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK					0x0000FFFF	
#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET					0		
#define cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH								((tOCT_UINT32)(cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK<<cOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET) )	


/*-------------------------------------------------------------------------------------
	tOCTPKT_HDRXL
 		COMMON Packet Header Extended Length
 		32-bit value
 		bits[31:28] = Control Protocol Type
 		bits[27:24] = Reserved
 		bits[23:16] = Format (depend of the Protocol)
 		bits[15:0] = Total Packet Length (size in bytes)

 Members:
	ul_Proto_Format_Length
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTPKT_HDRXL_FORMAT_PROTO_TYPE_LEN_MASK	ul_Proto_Format_Length;

} tOCTPKT_HDRXL;

/*-------------------------------------------------------------------------------------
	tOCTPKT_HDRXL_ETH
 		Ethernet alignement header

 Members:
	usReserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT16	usReserved;

} tOCTPKT_HDRXL_ETH;


#endif /* __OCTPKT_HDRXL_H__ */

