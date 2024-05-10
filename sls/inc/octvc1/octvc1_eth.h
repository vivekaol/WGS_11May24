/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_ETH.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_ETH_H__
#define __OCTVC1_ETH_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_base.h"
#include "octvc1_mac.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Ethernet port identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_ETH_PORT_ID_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_ETH_PORT_ID_ENUM							tOCT_UINT32

#define cOCTVC1_ETH_PORT_ID_ENUM_0							0		
#define cOCTVC1_ETH_PORT_ID_ENUM_1							1		
#define cOCTVC1_ETH_PORT_ID_ENUM_2							2		
#define cOCTVC1_ETH_PORT_ID_ENUM_3							3		
#define cOCTVC1_ETH_PORT_ID_ENUM_INVALID					0xFFFFFFFF	

#define cOCTVC1_ETH_802_1_PQ_TCI_INVALID					0xFFFFFFFF	 	/* Ethernet 802.1 pq definition */

/*-------------------------------------------------------------------------------------
	tOCTVC1_ETH_ADDRESS
 		Ethernet address information

 Members:
	MacAddress
	usEtherType
	usReserved
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MAC_ADDRESS	MacAddress;
	tOCT_UINT16			usEtherType;
	tOCT_UINT16			usReserved;

} tOCTVC1_ETH_ADDRESS;


#endif /* __OCTVC1_ETH_H__ */

