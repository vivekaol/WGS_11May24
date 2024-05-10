/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_ID.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the identifiers for the 3G_NODEB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_3G_NODEB_ID_H__
#define __OCTVC1_3G_NODEB_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_3g_nodeb_base.h"

/****************************************************************************
	Command IDs
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CID   ( 0x001 + cOCTVC1_3G_NODEB_CID_BASE )
#define cOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CID ( 0x002 + cOCTVC1_3G_NODEB_CID_BASE )
#define cOCTVC1_3G_NODEB_MSG_CELL_OPEN_CID            ( ( 0x005 + cOCTVC1_3G_NODEB_CID_BASE )| cOCTVC1_MSG_LONG_PROCESSING_FLAG  ) 
#define cOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CID           ( 0x006 + cOCTVC1_3G_NODEB_CID_BASE )
#define cOCTVC1_3G_NODEB_MSG_CELL_INFO_CID            ( 0x007 + cOCTVC1_3G_NODEB_CID_BASE )
#define cOCTVC1_3G_NODEB_MSG_CELL_LIST_CID            ( 0x008 + cOCTVC1_3G_NODEB_CID_BASE )
#define cOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CID         ( 0x009 + cOCTVC1_3G_NODEB_CID_BASE )

#define cOCTVC1_3G_NODEB_CID_MAX                      (( 0x009 + 1 ) & 0xFFF)

/****************************************************************************
	Event IDs
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EID ( 0x0001 + cOCTVC1_3G_NODEB_EID_BASE )

#define cOCTVC1_3G_NODEB_EID_MAX                   (( 0x0001 + 1 ) & 0xFFFF)


#endif /* __OCTVC1_3G_NODEB_ID_H__ */

