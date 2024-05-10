/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVOCNET_PKT.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVOCNET_PKT_H__
#define __OCTVOCNET_PKT_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "../octpkt/octpkt_hdr.h"
#include "../octpkt/octpkt_hdrxl.h"
#include "octvc1_handle.h"
#include "octvc1_module.h"


/************************  COMMON DEFINITIONS  *******************************/

#define cOCTVOCNET_PKT_ETHERTYPE							cOCTPKT_HDR_ETHERTYPE	
#define cOCTVOCNET_PKT_ETHERTYPE_XL							cOCTPKT_HDRXL_ETHERTYPE	

/*-------------------------------------------------------------------------------------
 	VocalloNet Packet Format Values
-------------------------------------------------------------------------------------*/
#define cOCTVOCNET_PKT_FORMAT_MASK							cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT	
#define cOCTVOCNET_PKT_FORMAT_BIT_OFFSET					cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_OFFSET	
#define cOCTVOCNET_PKT_FORMAT_BIT_MASK						cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_FORMAT_BIT_MASK	
#define cOCTVOCNET_PKT_TRACE_MASK							cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE	
#define cOCTVOCNET_PKT_TRACE_BIT_OFFSET						cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE_BIT_OFFSET	
#define cOCTVOCNET_PKT_TRACE_BIT_MASK						cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_TRACE_BIT_MASK	
#define cOCTVOCNET_PKT_CONTROL_PROTOCOL_TYPE_MASK			cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE	
#define cOCTVOCNET_PKT_CONTROL_PROTOCOL_TYPE_BIT_OFFSET		cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_OFFSET	
#define cOCTVOCNET_PKT_CONTROL_PROTOCOL_TYPE_BIT_MASK		cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_CONTROL_PROTOCOL_TYPE_BIT_MASK	
#define cOCTVOCNET_PKT_LENGTH_MASK							cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH	
#define cOCTVOCNET_PKT_LENGTH_BIT_OFFSET					cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_OFFSET	
#define cOCTVOCNET_PKT_LENGTH_BIT_MASK						cOCTPKT_HDR_FORMAT_PROTO_TYPE_LEN_MASK_LENGTH_BIT_MASK	

/*-------------------------------------------------------------------------------------
 	VocalloNet Format Control Packet
-------------------------------------------------------------------------------------*/
#define cOCTVOCNET_PKT_FORMAT_CTRL							0x00	
#define cOCTVOCNET_PKT_FORMAT_F								0x01	
#define cOCTVOCNET_PKT_FORMAT_DATA_FRAGMENT					0x02	
#define cOCTVOCNET_PKT_FORMAT_MODULE_DATA					0x03	 	/* Use to send OCTVC1 MODULE DATA */

/*-------------------------------------------------------------------------------------
 	VocalloNet Format Control Bit Shifted
-------------------------------------------------------------------------------------*/
#define cOCTVOCNET_PKT_BITSHIFTED_FORMAT_CTRL				(cOCTVOCNET_PKT_FORMAT_CTRL<<cOCTVOCNET_PKT_FORMAT_BIT_OFFSET)	
#define cOCTVOCNET_PKT_BITSHIFTED_FORMAT_F					(cOCTVOCNET_PKT_FORMAT_F<<cOCTVOCNET_PKT_FORMAT_BIT_OFFSET)	
#define cOCTVOCNET_PKT_BITSHIFTED_FORMAT_DATA_FRAGMENT		(cOCTVOCNET_PKT_FORMAT_DATA_FRAGMENT<<cOCTVOCNET_PKT_FORMAT_BIT_OFFSET)	
#define cOCTVOCNET_PKT_BITSHIFTED_FORMAT_MODULE_DATA		(cOCTVOCNET_PKT_FORMAT_MODULE_DATA<<cOCTVOCNET_PKT_FORMAT_BIT_OFFSET)	

/*-------------------------------------------------------------------------------------
 	VocalloNet Packet F sub-type Values
-------------------------------------------------------------------------------------*/
#define cOCTVOCNET_PKT_SUBTYPE_UNSPECIFIED					0x0		
#define cOCTVOCNET_PKT_SUBTYPE_API_EVENT					0x1		
#define cOCTVOCNET_PKT_SUBTYPE_MODULE_DATA					0x2		

/*-------------------------------------------------------------------------------------
 	Control Protocol Types.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVOCNET_PKT_CONTROL_PROTOCOL_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVOCNET_PKT_CONTROL_PROTOCOL_TYPE_ENUM			tOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM

#define cOCTVOCNET_PKT_CONTROL_PROTOCOL_TYPE_ENUM_OCTVC1	cOCTPKT_HDR_CONTROL_PROTOCOL_TYPE_ENUM_OCTVOCNET	 	/* Vocallo Control Protocol */

/*-------------------------------------------------------------------------------------
 	Octvocnet types.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVOCNET_PKT_HEADER :
-------------------------------------------------------------------------------------*/
#define tOCTVOCNET_PKT_HEADER								tOCTPKT_HDR


/*-------------------------------------------------------------------------------------
	tOCTVOCNET_PKT_HEADER_XL :
-------------------------------------------------------------------------------------*/
#define tOCTVOCNET_PKT_HEADER_XL							tOCTPKT_HDRXL


/*-------------------------------------------------------------------------------------
	tOCTVOCNET_PKT_CTL_HEADER
 		VocalloNet Control Packet Header

 Members:
	ulDestFifoId
 		Destination FIFO ID.
	ulSourceFifoId
 		Source FIFO ID.
	ulSocketId
 		Return socket identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32	ulDestFifoId;
	tOCT_UINT32	ulSourceFifoId;
	tOCT_UINT32	ulSocketId;

} tOCTVOCNET_PKT_CTL_HEADER;

/*-------------------------------------------------------------------------------------
	tOCTVOCNET_PKT_DATA_HEADER
 		VocalloNet Data Packet Header

 Members:
	hLogicalObj
 		Logical Obj Handle.
	ulLogicalObjPktPort
 		Logical_Object Packet_Port.
	ulDestFifoId
 		Destination FIFO ID.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT	hLogicalObj;
	tOCT_UINT32				ulLogicalObjPktPort;
	tOCT_UINT32				ulDestFifoId;

} tOCTVOCNET_PKT_DATA_HEADER;

                
#define mOCTVOCNET_PKT_DATA_HEADER_LOGICALOBJ_GET_HANDLE_OBJECT( f_hLogicalObj ) ( f_hLogicalObj )
              
              
/*-------------------------------------------------------------------------------------
 	VocalloNet Logical Object port signature for event session
-------------------------------------------------------------------------------------*/
#define cOCTVOCNET_PKT_DATA_LOGICAL_OBJ_PKT_PORT_EVENT_SESSION	0x19751007	
/*-------------------------------------------------------------------------------------
	tOCTVOCNET_PKT_DATA_F_HEADER
 		VocalloNet Format F Packet Header (Raw Data packet)

 Members:
	VocNetHeader
	ulTimestamp
 		bits[31:0] = Timestamp
	ulSubType
 		bits[31:0] = SubType
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVOCNET_PKT_DATA_HEADER	VocNetHeader;
	tOCT_UINT32					ulTimestamp;
	tOCT_UINT32					ulSubType;

} tOCTVOCNET_PKT_DATA_F_HEADER;

/*-------------------------------------------------------------------------------------
	tOCTVOCNET_PKT_DATA_FRAGMENT_HEADER
 		VocalloNet Data Packet Header

 Members:
	DataHeader
	ulSequenceId
 		Sequence id.
	ulTransfertTotalSize
 		Total byte transert for that ulSequenceId (for all ulFragmentTotalCnt fragment).
 		If ulTransfertTotalSize set 0, the total ulTransfertTotalSize is unknown
	ulFragmentTotalCnt
 		Total count of fragment.
 		If ulFragmentTotalCnt set 0, the total ulFragmentTotalCnt is unknown
	ulFragmentId
 		Fragment id.
	ulFragmentDataOffset
 		Byte offset where to reassemble the data
	ulFragmentDataSize
 		Data prensent in this fragment.
	ulUserId
 		User Id.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVOCNET_PKT_DATA_F_HEADER	DataHeader;
	tOCT_UINT32						ulSequenceId;
	tOCT_UINT32						ulTransfertTotalSize;
	tOCT_UINT32						ulFragmentTotalCnt;
	tOCT_UINT32						ulFragmentId;
	tOCT_UINT32						ulFragmentDataOffset;
	tOCT_UINT32						ulFragmentDataSize;
	tOCT_UINT32						ulUserId;

} tOCTVOCNET_PKT_DATA_FRAGMENT_HEADER;


#endif /* __OCTVOCNET_PKT_H__ */

