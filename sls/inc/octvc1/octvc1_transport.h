/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_TRANSPORT.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_TRANSPORT_H__
#define __OCTVC1_TRANSPORT_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_base.h"
#include "octvc1_eth.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Transport Type
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTVC1_TRANSPORT_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_TRANSPORT_TYPE_ENUM							tOCT_UINT32

#define cOCTVC1_TRANSPORT_TYPE_ENUM_NONE					0		 	/* No transport */
#define cOCTVC1_TRANSPORT_TYPE_ENUM_ETH						1		 	/* Ethernet Tranport */
#define cOCTVC1_TRANSPORT_TYPE_ENUM_UDP						2		 	/* UDP Tranport */
#define cOCTVC1_TRANSPORT_TYPE_ENUM_TCP						1		 	/* TCP Tranport */
#define cOCTVC1_TRANSPORT_TYPE_ENUM_LOCAL					1		 	/* Local Tranport */
#define cOCTVC1_TRANSPORT_TYPE_ENUM_IPC						1		 	/* IPC Tranport */
#define cOCTVC1_TRANSPORT_TYPE_ENUM_USER					10		 	/* User Tranport */

/*-------------------------------------------------------------------------------------
 	Transport Address
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_TRANSPORT_ADDRESS

 Members:
	ulTransportType
		Default:	cOCTVC1_TRANSPORT_TYPE_ENUM_NONE
 		Target file system to file server transport type.
	Eth
 		Ethernet destination information.
 		Only valid if ulTransportType set to cOCTDEV_TRANSPORT_TYPE_ENUM_ETH.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_TRANSPORT_TYPE_ENUM	ulTransportType;
	tOCTVC1_ETH_ADDRESS			Eth;

} tOCTVC1_TRANSPORT_ADDRESS;


#endif /* __OCTVC1_TRANSPORT_H__ */

