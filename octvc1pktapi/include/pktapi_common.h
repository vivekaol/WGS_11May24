/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_COMMON.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __PKTAPI_COMMON_H__
#define __PKTAPI_COMMON_H__

/*****************************  INCLUDE FILES  *******************************/

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  DEFINES **************************************/
/* 32 bit FIFO ID used for the Host side */
#define cPKTAPI_FIFO_ID_MSG				0xAAAA0001
#define cPKTAPI_FIFO_ID_USER_MSG		0xBBBB0001

/*----------------------------------------------------------------------------
	Ethernet header size
----------------------------------------------------------------------------*/
#define cPKTAPI_ETH_II_HEADER_SIZE		((cOCTVC1_PKT_API_MAC_ADDR_SIZE*2) + 2)

/*----------------------------------------------------------------------------
	Control header size
----------------------------------------------------------------------------*/
#define cPKTAPI_CTL_HEADER_SIZE			(	cPKTAPI_ETH_II_HEADER_SIZE +		\
											sizeof(tOCTVOCNET_PKT_HEADER) +		\
											sizeof(tOCTVOCNET_PKT_CTL_HEADER) )

/*----------------------------------------------------------------------------
	Routing header maximum size
----------------------------------------------------------------------------*/
#define cPKTAPI_ROUTING_HEADER_SIZE		(cPKTAPI_ETH_II_HEADER_SIZE +			\
										sizeof(tOCTVOCNET_PKT_HEADER) )

/*----------------------------------------------------------------------------
	Max payload size
----------------------------------------------------------------------------*/
#ifdef cOCTVC1_PKT_API_PAYLOAD_MAX
#define cPKTAPI_PAYLOAD_MAX					cOCTVC1_PKT_API_PAYLOAD_MAX
#else
#define cPKTAPI_PAYLOAD_MAX					(1502)	
#endif /* cOCTVC1_PKT_API_PAYLOAD_MAX */
	
#define cPKTAPI_PAYLOAD_ALIGNMENT_PADDING	(2)

/*****************************  MACROS **************************************/


/***************************  STRUCTURES *************************************/
/*----------------------------------------------------------------------------
	NULL MAC Address
----------------------------------------------------------------------------*/
extern unsigned char g_abyPktApiMacAddrNull[];

/*----------------------------------------------------------------------------
	Broadcast MAC Address
----------------------------------------------------------------------------*/
extern unsigned char g_abyPktApiMacAddrBroadcast[];

/*****************************  FUNCTIONS ************************************/

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __PKTAPI_COMMON_H__*/
