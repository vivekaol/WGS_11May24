/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_RC.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the return codes for the 3G_NODEB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_3G_NODEB_RC_H__
#define OCTVC1_3G_NODEB_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_3g_nodeb_base.h"

/****************************************************************************
	3G_NODEB return codes
 ****************************************************************************/

/****************************************************************************
	GENERIC return codes
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_GENERIC_RC_BASE					 ( 0x0100 + cOCTVC1_3G_NODEB_RC_BASE )

#define cOCTVC1_3G_NODEB_RC_GENERIC_EVENT_MASK_INVALID		 ( 0x0000 + cOCTVC1_3G_NODEB_GENERIC_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_GENERIC_ANTENNA_INFO_INVALID	 ( 0x0001 + cOCTVC1_3G_NODEB_GENERIC_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_GENERIC_TX_CALIB_NOT_PRESENT	 ( 0x0002 + cOCTVC1_3G_NODEB_GENERIC_RC_BASE )

/****************************************************************************
	CELL_OPEN return codes
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_CELL_OPEN_RC_BASE					 ( 0x0200 + cOCTVC1_3G_NODEB_RC_BASE )

#define cOCTVC1_3G_NODEB_RC_CELL_OPEN_RF_PORT_ALREADY_USED	 ( 0x0000 + cOCTVC1_3G_NODEB_CELL_OPEN_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_CELL_OPEN_RF_PORT_CONFIG_ERROR	 ( 0x0001 + cOCTVC1_3G_NODEB_CELL_OPEN_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_CELL_OPEN_RADIO_INIT_ERROR		 ( 0x0002 + cOCTVC1_3G_NODEB_CELL_OPEN_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_CELL_OPEN_RF_SCRIPT_NOT_FOUND	 ( 0x0003 + cOCTVC1_3G_NODEB_CELL_OPEN_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_CELL_OPEN_ALREADY_DONE			 ( 0x0004 + cOCTVC1_3G_NODEB_CELL_OPEN_RC_BASE )

/****************************************************************************
	CELL_CLOSE return codes
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_CELL_CLOSE_RC_BASE					 ( 0x0300 + cOCTVC1_3G_NODEB_RC_BASE )

#define cOCTVC1_3G_NODEB_RC_CELL_CLOSE_ALREADY_DONE			 ( 0x0000 + cOCTVC1_3G_NODEB_CELL_CLOSE_RC_BASE )

/****************************************************************************
	MODULE return codes
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_MODULE_RC_BASE						 ( 0x0400 + cOCTVC1_3G_NODEB_RC_BASE )

#define cOCTVC1_3G_NODEB_RC_MODULE_LICENSE_DENIED			 ( 0x0000 + cOCTVC1_3G_NODEB_MODULE_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_MODULE_INTERNAL_ERROR			 ( 0x0001 + cOCTVC1_3G_NODEB_MODULE_RC_BASE )

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_AUTO_VALIDATE_RC_BASE					 ( 0xF000 + cOCTVC1_3G_NODEB_RC_BASE )

#define cOCTVC1_3G_NODEB_RC_CELL_RF_CONFIG_INVALID_DL_UARFCN	 ( 0x1 + cOCTVC1_3G_NODEB_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_CELL_RF_CONFIG_INVALID_UL_UARFCN	 ( 0x2 + cOCTVC1_3G_NODEB_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_CELL_RF_CONFIG_INVALID_RX_GAIN_DB	 ( 0x3 + cOCTVC1_3G_NODEB_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_3G_NODEB_RC_CELL_RF_CONFIG_INVALID_TX_ATTND_B	 ( 0x4 + cOCTVC1_3G_NODEB_AUTO_VALIDATE_RC_BASE )

#endif /* OCTVC1_3G_NODEB_RC_H__ */

