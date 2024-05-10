/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_VLAN.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_VLAN_H__
#define __OCTVC1_VLAN_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

#define cOCTVC1_VLAN_MAX_TAG								4		

/*-------------------------------------------------------------------------------------
	tOCTVC1_VLAN_PROTOCOL_ID_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_VLAN_PROTOCOL_ID_ENUM						tOCT_UINT32

#define cOCTVC1_VLAN_PROTOCOL_ID_ENUM_8100					0		
#define cOCTVC1_VLAN_PROTOCOL_ID_ENUM_88A8					1		
#define cOCTVC1_VLAN_PROTOCOL_ID_ENUM_9100					2		
#define cOCTVC1_VLAN_PROTOCOL_ID_ENUM_9200					3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_VLAN_TAG

 Members:
	ulPriority
		Range:		[0..7]
		Default:	5
	ulVlanId
		Range:		[0..4095]
		Default:	0
	ulProtocolId
		Default:	cOCTVC1_VLAN_PROTOCOL_ID_ENUM_8100
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32						ulPriority;
	tOCT_UINT32						ulVlanId;
	tOCTVC1_VLAN_PROTOCOL_ID_ENUM	ulProtocolId;

} tOCTVC1_VLAN_TAG;

/*-------------------------------------------------------------------------------------
	tOCTVC1_VLAN_HEADER_INFO

 Members:
	ulNumVlanTag
		Range:		[0..cOCTVC1_VLAN_MAX_TAG]
		Default:	0
 		Number of Vlan TAGs present in the header. The tag inserted right after the
 		Ethernet header must be located at index 0 of aVlanTag while the one at the
 		highest index is located right before the transport header.
	aVlanTag
 		Array containing the VLAN TAG to present in the header for this member.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32			ulNumVlanTag;
	tOCTVC1_VLAN_TAG	aVlanTag[cOCTVC1_VLAN_MAX_TAG];

} tOCTVC1_VLAN_HEADER_INFO;


#endif /* __OCTVC1_VLAN_H__ */

