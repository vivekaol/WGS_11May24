/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_API.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the definition of the 3G_NODEB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_3G_NODEB_API_H__
#define __OCTVC1_3G_NODEB_API_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../../octdev_types.h"
#include "../../octdev_devices.h"
#include "../octvc1_msg.h"
#include "../octvc1_handle.h"
#include "../octvc1_cursor.h"
#include "../octvc1_list.h"
#include "../octvc1_fifo.h"
#include "../octvc1_file.h"
#include "../octvc1_radio.h"

#include "octvc1_3g_nodeb_id.h"
#include "octvc1_3g_nodeb_rc.h"
#include "octvc1_3g_nodeb_lic.h"

/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	APP_TEST Application Module Id
-------------------------------------------------------------------------------------*/

#define cOCTVC1_3G_NODEB_APPLICATION_ID_MODULE_PHY			((0x00)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_MODULE_APPLICATION_ID_MODULE_BIT_OFFSET))	

/*-------------------------------------------------------------------------------------
 	CELL related definitions.
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_CELL_STATE_ENUM : 	3G BTS NodeB Cell state.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_3G_NODEB_CELL_STATE_ENUM					tOCT_UINT32

#define cOCTVC1_3G_NODEB_CELL_STATE_ENUM_INVALID			0		
#define cOCTVC1_3G_NODEB_CELL_STATE_ENUM_IDLE				1		
#define cOCTVC1_3G_NODEB_CELL_STATE_ENUM_READY				2		
#define cOCTVC1_3G_NODEB_CELL_STATE_ENUM_RUNNING			3		

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_CELL_RF_CONFIG
 		CELL RF configuration

 Members:
	ulBandId
		Default:	cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_1
 		System Bandwidth ID
	ulDlUarfcn
		Range:		[10562..10838]
		Default:	10700
 		DL UARFCN
	ulUlUarfcn
		Range:		[9612..9888]
		Default:	9750
 		UL UARFCN
	ulRxGainDb
		Range:		[0..73]
		Default:	38
 		Rx Gain Db
	ulTxAttndB
		Range:		[0..359]
 		Tx attenuation Db. (in 1/4 dB)
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM	ulBandId;
	tOCT_UINT32									ulDlUarfcn;
	tOCT_UINT32									ulUlUarfcn;
	tOCT_UINT32									ulRxGainDb;
	tOCT_UINT32									ulTxAttndB;

} tOCTVC1_3G_NODEB_CELL_RF_CONFIG;

/*****************************  METHODS  *************************************/
/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_RSP

 Members:
	Header
 		OCTVC1 Message Header
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER	Header;

} tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD

 Members:
	Header
 		OCTVC1 Message Header
	ulRfPortIndex
 		Unique RF port identifier
	ulUserId
 		Host application object identifier.
	RfConfig
 		RF configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_INDEX					ulRfPortIndex;
	tOCT_UINT32						ulUserId;
	tOCTVC1_3G_NODEB_CELL_RF_CONFIG	RfConfig;

} tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_OPEN_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hCell
 		Unique NodeB identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCell;

} tOCTVC1_3G_NODEB_MSG_CELL_OPEN_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hCell
 		Unique identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCell;

} tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hCell
 		Unique NodeB identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCell;

} tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD

 Members:
	Header
 		OCTVC1 Message Header
	hCell
 		Unique NodeB identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCell;

} tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_INFO_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hCell
 		Unique NodeB identifier
	ulPortIndex
 		RF port index
	ulUserId
 		Host application object identifier.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCell;
	tOCTVC1_INDEX			ulPortIndex;
	tOCT_UINT32				ulUserId;

} tOCTVC1_3G_NODEB_MSG_CELL_INFO_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD

 Members:
	Header
	ObjectCursor
 		Object Cursor.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;

} tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_LIST_RSP

 Members:
	Header
	ObjectCursor
 		Object Cursor.
	ObjectList
 		Generic handle object list structure
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER					Header;
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET	ObjectCursor;
	tOCTVC1_LIST_HANDLE_OBJECT_GET		ObjectList;

} tOCTVC1_3G_NODEB_MSG_CELL_LIST_RSP;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD
 		This command retrieves the cell configuration parameters.

 Members:
	Header
 		OCTVC1 Message Header
	hCell
 		Unique NodeB Cell identifier
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER		Header;
	tOCTVC1_HANDLE_OBJECT	hCell;

} tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD;

/*-------------------------------------------------------------------------------------
	tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_RSP

 Members:
	Header
 		OCTVC1 Message Header
	hCell
 		Unique NodeB Cell identifier
	Config
 		RF configuration
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_MSG_HEADER				Header;
	tOCTVC1_HANDLE_OBJECT			hCell;
	tOCTVC1_3G_NODEB_CELL_RF_CONFIG	Config;

} tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_RSP;


/***************  INCLUDE FILES WITH DEPENDENCIES ON THIS FILE  **************/
#include "octvc1_3g_nodeb_evt.h"

#endif /* __OCTVC1_3G_NODEB_API_H__ */

