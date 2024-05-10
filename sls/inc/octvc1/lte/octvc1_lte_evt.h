/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LTE_EVT.h
Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the event definition of the LTE API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_LTE_APP-04.03.00-B3607 (2019/04/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_LTE_EVT_H__
#define __OCTVC1_LTE_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_lte_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_CELL_STATE_UPDATE_EVT

 Members:
	Header
	hEnodeb
 		Unique eNodeB identifier.
	ulUserId
 		Host application object identifier.
	ulOldState
 		eNodeB state.
	ulNewState
 		eNodeB state.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT		hEnodeb;
	tOCT_UINT32					ulUserId;
	tOCTVC1_LTE_CELL_STATE_ENUM	ulOldState;
	tOCTVC1_LTE_CELL_STATE_ENUM	ulNewState;

} tOCTVC1_LTE_MSG_ENODEB_CELL_STATE_UPDATE_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_BASS_NEW_CELL_FOUND_EVT

 Members:
	Header
	hEnodeb
 		Unique eNodeB identifier.
	ulUserId
 		Host application object identifier.
	LastCellInfo
 		Last Cell Info that TDD BASS synchonize with
	CurrentCellInfo
 		Current Cell Info that TDD BASS synchonize with
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT				hEnodeb;
	tOCT_UINT32							ulUserId;
	tOCTVC1_LTE_BASS_EVENT_CELL_INFO	LastCellInfo;
	tOCTVC1_LTE_BASS_EVENT_CELL_INFO	CurrentCellInfo;

} tOCTVC1_LTE_MSG_ENODEB_BASS_NEW_CELL_FOUND_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LTE_MSG_ENODEB_BASS_CELL_SYNC_CHANGE_SOURCE_EVT

 Members:
	Header
	hEnodeb
 		Unique eNodeB identifier.
	ulUserId
 		Host application object identifier.
	LastCellInfo
 		Last Cell Info that TDD BASS synchonize with
	CurrentCellInfo
 		Current Cell Info that TDD BASS synchonize with
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT				hEnodeb;
	tOCT_UINT32							ulUserId;
	tOCTVC1_LTE_BASS_EVENT_CELL_INFO	LastCellInfo;
	tOCTVC1_LTE_BASS_EVENT_CELL_INFO	CurrentCellInfo;

} tOCTVC1_LTE_MSG_ENODEB_BASS_CELL_SYNC_CHANGE_SOURCE_EVT;


#endif /* __OCTVC1_LTE_EVT_H__ */

