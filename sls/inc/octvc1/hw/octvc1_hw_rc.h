/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_HW_RC.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the return codes for the HW API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_HW_RC_H__
#define OCTVC1_HW_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"
#include "octvc1_hw_base.h"

/****************************************************************************
	HW return codes
 ****************************************************************************/
#define cOCTVC1_HW_RC_CORE_NOT_FOUND						 ( 0x0004 + cOCTVC1_HW_RC_BASE )
#define cOCTVC1_HW_RC_ETH_PORT_RESTRICTED_API_DENIED		 ( 0x0006 + cOCTVC1_HW_RC_BASE )

/****************************************************************************
	ETH return codes
 ****************************************************************************/
#define cOCTVC1_HW_ETH_RC_BASE								 ( 0x0010 + cOCTVC1_HW_RC_BASE )

#define cOCTVC1_HW_RC_ETH_PORT_IN_USED						 ( 0x0001 + cOCTVC1_HW_ETH_RC_BASE )

/****************************************************************************
	RF_PORT return codes
 ****************************************************************************/
#define cOCTVC1_HW_RF_PORT_RC_BASE							 ( 0x0020 + cOCTVC1_HW_RC_BASE )

#define cOCTVC1_HW_RC_RF_PORT_UNUSED						 ( 0x0001 + cOCTVC1_HW_RF_PORT_RC_BASE )
#define cOCTVC1_HW_RC_RF_PORT_ANTENNA_UNUSED				 ( 0x0002 + cOCTVC1_HW_RF_PORT_RC_BASE )
#define cOCTVC1_HW_RC_RF_PORT_ANTENNA_INTERNAL_ERROR		 ( 0x0003 + cOCTVC1_HW_RF_PORT_RC_BASE )
#define cOCTVC1_HW_RC_RF_PORT_ANTENNA_CANNOT_MODIFY			 ( 0x0004 + cOCTVC1_HW_RF_PORT_RC_BASE )
#define cOCTVC1_HW_RC_RF_PORT_TX_CALIBRATION_NOT_AVAILABLE	 ( 0x0005 + cOCTVC1_HW_RF_PORT_RC_BASE )
#define cOCTVC1_HW_RC_RF_PORT_ANTENNA_RX_AGC_MODE			 ( 0x0006 + cOCTVC1_HW_RF_PORT_RC_BASE )

/****************************************************************************
	CLOCK_SYNC_MGR return codes
 ****************************************************************************/
#define cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE							 ( 0x0050 + cOCTVC1_HW_RC_BASE )

#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_ALREADY_OPEN					 ( 0x0000 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_OPEN_ERROR						 ( 0x0001 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_CLOSE_ERROR					 ( 0x0002 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_BAD_PCB_INFO					 ( 0x0003 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_DAC_OPEN_ERROR					 ( 0x0004 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_PROCESS_OPEN_ERROR				 ( 0x0005 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_PROCESS_CLOSE_ERROR			 ( 0x0006 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_DAC_CLOSE_ERROR				 ( 0x0007 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_STATS_ERROR					 ( 0x0008 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_NOT_SUPPORTED					 ( 0x0009 + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_NOT_OPENED						 ( 0x000A + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE )
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_BAD_CLOCK_SRC_REF_ON_FREE_RUN	 ( 0x000B + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE ) 	/* Free running DAC_TYPE is only compatible with 1PPS clock src */
#define cOCTVC1_HW_RC_CLOCK_SYNC_MGR_APPLICATION_MODULE_NOT_STOPPED	 ( 0x000C + cOCTVC1_HW_CLOCK_SYNC_MGR_RC_BASE ) 	/* All application module (except system) must be stopped to be able to stop the */
 																		/* clock sync manager */
 																		/* Use methode cOCTVC1_MAIN_MSG_APPLICATION_STOP_MODULE_CID */

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_HW_AUTO_VALIDATE_RC_BASE					 ( 0xF000 + cOCTVC1_HW_RC_BASE )

#define cOCTVC1_HW_RC_RF_PORT_ANTENNA_RX_CONFIG_MODIFY_INVALID_RX_GAIND_B	 ( 0x1 + cOCTVC1_HW_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_HW_RC_RF_PORT_ANTENNA_TX_CONFIG_MODIFY_INVALID_TX_GAIND_B	 ( 0x2 + cOCTVC1_HW_AUTO_VALIDATE_RC_BASE )

#endif /* OCTVC1_HW_RC_H__ */

