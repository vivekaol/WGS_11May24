/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_EVT.h
Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the RUS API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_EVT_H__
#define __OCTVC1_RUS_EVT_H__


/*****************************  INCLUDE FILES  *******************************/

#include "octvc1_rus_api.h"

/************************  COMMON DEFINITIONS  *******************************/

/*****************************  NOTIFICATIONS  **********************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_SEARCH_STATS_EVT

 Members:
	Header
	Stats
 		Wnm Search statistic
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER			Header;
	tOCTVC1_RUS_WNM_SEARCH_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_SEARCH_STATS_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_GSM_CELL_STATS_EVT

 Members:
	Header
	ulCellId
 		Index on GSM Cell list
	Stats
 		GSM Cell statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER			Header;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_GSM_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_GSM_CELL_STATS_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_CDMA2000_CELL_STATS_EVT

 Members:
	Header
	ulCellId
 		Index on CDMA2000 Cell list
	Stats
 		CDMA2000 Cell statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER				Header;
	tOCTVC1_SUB_OBJECT_ID				ulCellId;
	tOCTVC1_RUS_WNM_CDMA2000_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_CDMA2000_CELL_STATS_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_UMTS_CELL_STATS_EVT

 Members:
	Header
	ulCellId
 		Index on UMTS Cell list
	Stats
 		UMTS Cell statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER			Header;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_UMTS_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_UMTS_CELL_STATS_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_LTE_CELL_STATS_EVT

 Members:
	Header
	ulCellId
 		Index on LTE Cell list
	Stats
 		LTE Cell statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER			Header;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_LTE_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_LTE_CELL_STATS_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_NR_CELL_STATS_EVT

 Members:
	Header
	ulCellId
 		Index on NR Cell list
	Stats
 		NR Cell statistics
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER			Header;
	tOCTVC1_SUB_OBJECT_ID			ulCellId;
	tOCTVC1_RUS_WNM_NR_CELL_STATS	Stats;

} tOCTVC1_RUS_MSG_WNM_NR_CELL_STATS_EVT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RUS_MSG_WNM_MCC_LIC_ERR_EVT

 Members:
	Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_EVENT_HEADER	Header;

} tOCTVC1_RUS_MSG_WNM_MCC_LIC_ERR_EVT;


#endif /* __OCTVC1_RUS_EVT_H__ */

