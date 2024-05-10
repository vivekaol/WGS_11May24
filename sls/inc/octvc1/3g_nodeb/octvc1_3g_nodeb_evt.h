/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_EVT.h
Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the 3G_NODEB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_3G_NODEB_EVT_H__
#define __OCTVC1_3G_NODEB_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_3g_nodeb_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT

 Members:
	Header
	hCell
 		Unique NodeB identifier
	ulUserId
 		Host application object identifier.
	OldState
 		NodeB state
	NewState
 		NodeB state
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT				hCell;
	tOCT_UINT32							ulUserId;
	tOCTVC1_3G_NODEB_CELL_STATE_ENUM	OldState;
	tOCTVC1_3G_NODEB_CELL_STATE_ENUM	NewState;

} tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT;


#endif /* __OCTVC1_3G_NODEB_EVT_H__ */

