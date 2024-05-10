/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_RC.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the return codes for the OBM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.5.0-B393 (07/02/2018)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_OBM_RC_H__
#define OCTVC1_OBM_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "octvc1_obm_base.h"

/****************************************************************************
	OBM return codes
 ****************************************************************************/
#define cOCTVC1_OBM_RC_TFTP_UNAVAILABLE									 ( 0x0000 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_OCTPOD_OPEN_ERROR								 ( 0x0001 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_OCTPOD_READ_ERROR								 ( 0x0002 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_OCTPOD_WRITE_ERROR								 ( 0x0003 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_I2C_SLAVE_ERROR									 ( 0x0004 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_I2C_READ_SLAVE_ERROR								 ( 0x0005 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_I2C_WRITE_SLAVE_ERROR							 ( 0x0006 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_I2C_RECOVERY_UNAVAILABLE							 ( 0x0007 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_USB_CABLE_NOT_FOUND								 ( 0x0008 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_IO_EVENT_FAILURE									 ( 0x0009 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RS232_PORT_ERROR									 ( 0x000A + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_FILE_OPEN_ERROR									 ( 0x000B + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_FILE_READ_ERROR									 ( 0x000C + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_GPIO_DIRECTION_INVALID							 ( 0x000E + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_SOCKET_BIND_ERROR								 ( 0x000F + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_SOCKET_CONNECTION_ABORT							 ( 0x0010 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_ETH_SWITCH_BUSY_TIMEOUT							 ( 0x0011 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_I2C_BUS_NOT_ACCESSIBLE							 ( 0x0012 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_SPI_INIT_SLAVE_ERROR								 ( 0x0013 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_SPI_READ_SLAVE_ERROR								 ( 0x0014 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_SPI_WRITE_SLAVE_ERROR							 ( 0x0015 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_REF_CLOCK_IN_INVALID								 ( 0x0016 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_REF_CLOCK_OUT_INVALID							 ( 0x0017 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_POWER_UP_TIME_INVALID							 ( 0x0018 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_POWER_DOWN_TIME_INVALID							 ( 0x0019 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_AMPLIFICATION_STAGE_INVALID			 ( 0x001A + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_FILTER_AND_AMPLIFICATION_MISMATCH	 ( 0x001B + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_TX_FILTER_INVALID					 ( 0x001C + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_RX_FILTER_INVALID					 ( 0x001D + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_I2C_BUS_MISSING									 ( 0x001E + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_ETHERNET_SWITCH_MISSING							 ( 0x001F + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_REF_CLOCK_OUT_FEATURE_MISSING					 ( 0x0021 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_POWER_OFF_FEATURE_MISSING						 ( 0x0022 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_GPS_CANNOT_COLD_START							 ( 0x0023 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_GPS_CANNOT_SELECT_ANTENNA						 ( 0x0024 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_PERIOD_NOT_CONFIGURABLE							 ( 0x0025 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_POWER_SWITCH_CANNOT_BYPASS						 ( 0x0026 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_NO_TX_FILTER_LIMITS					 ( 0x0027 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_NO_RX_FILTER_LIMITS					 ( 0x0028 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_GPS_MISSING										 ( 0x0029 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_DHCP_UNAVAILABLE									 ( 0x002A + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_DUPLEX_MODE_FEATURE_MISSING						 ( 0x002B + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_OCTPKTAPI_OPEN_ERROR								 ( 0x002C + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_SOCKET_OPEN_ERROR								 ( 0x002D + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_SOCKET_RECEIVE_ERROR								 ( 0x002E + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_ALREADY_ATTACHED									 ( 0x002F + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_MUXING_MODE_INVALID							 ( 0x0030 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_BATTERY_POWER_FEATURE_MISSING					 ( 0x0031 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_RF_MANAGEMENT_MODE_INVALID						 ( 0x0032 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_OCTPKTAPI_CLOSE_ERROR							 ( 0x0033 + cOCTVC1_OBM_RC_BASE )
#define cOCTVC1_OBM_RC_OCTPKTAPI_TIMEOUT_ERROR							 ( 0x0034 + cOCTVC1_OBM_RC_BASE )

/****************************************************************************
	GENERIC return codes
 ****************************************************************************/
#define cOCTVC1_OBM_GENERIC_RC_BASE							 ( 0x0100 + cOCTVC1_OBM_RC_BASE )

#define cOCTVC1_OBM_RC_GENERIC_FEATURE_UNAVAILABLE			 ( 0x0001 + cOCTVC1_OBM_GENERIC_RC_BASE ) 	/* The requested feature is not available on the targeted board */
#define cOCTVC1_OBM_RC_GENERIC_INVALID_ARGUMENT				 ( 0x0002 + cOCTVC1_OBM_GENERIC_RC_BASE )
#define cOCTVC1_OBM_RC_GENERIC_INVALID_INDEX				 ( 0x0003 + cOCTVC1_OBM_GENERIC_RC_BASE )
#define cOCTVC1_OBM_RC_GENERIC_HARDWARE_INIT_ERROR			 ( 0x0004 + cOCTVC1_OBM_GENERIC_RC_BASE ) 	/* Failed to initialize an internal hardware component */

/****************************************************************************
	DSP return codes
 ****************************************************************************/
#define cOCTVC1_OBM_DSP_RC_BASE								 ( 0x0200 + cOCTVC1_OBM_RC_BASE )

#define cOCTVC1_OBM_RC_DSP_IN_RESET							 ( 0x0000 + cOCTVC1_OBM_DSP_RC_BASE ) 	/* Operation is not available since DSP is held in reset */
#define cOCTVC1_OBM_RC_DSP_MII_BUSY_TIMEOUT					 ( 0x0001 + cOCTVC1_OBM_DSP_RC_BASE )
#define cOCTVC1_OBM_RC_DSP_LOOKUP_FAILED					 ( 0x0002 + cOCTVC1_OBM_DSP_RC_BASE )
#define cOCTVC1_OBM_RC_DSP_NO_RUNNING_APPLICATION			 ( 0x0003 + cOCTVC1_OBM_DSP_RC_BASE )

/****************************************************************************
	EMIC return codes
 ****************************************************************************/
#define cOCTVC1_OBM_EMIC_RC_BASE							 ( 0x0300 + cOCTVC1_OBM_RC_BASE )

#define cOCTVC1_OBM_RC_EMIC_UPDATE_TIMEOUT					 ( 0x0000 + cOCTVC1_OBM_EMIC_RC_BASE )
#define cOCTVC1_OBM_RC_EMIC_INVALID_ID						 ( 0x0001 + cOCTVC1_OBM_EMIC_RC_BASE )
#define cOCTVC1_OBM_RC_EMIC_UPDATE_FAILED					 ( 0x0002 + cOCTVC1_OBM_EMIC_RC_BASE )
#define cOCTVC1_OBM_RC_EMIC_FILE_CORRUPT					 ( 0x0003 + cOCTVC1_OBM_EMIC_RC_BASE )
#define cOCTVC1_OBM_RC_EMIC_NOT_UPDATEABLE					 ( 0x0004 + cOCTVC1_OBM_EMIC_RC_BASE )

/****************************************************************************
	RF_FRONTEND return codes
 ****************************************************************************/
#define cOCTVC1_OBM_RF_FRONTEND_RC_BASE						 ( 0x0400 + cOCTVC1_OBM_RC_BASE )

#define cOCTVC1_OBM_RC_RF_FRONTEND_LOOKUP_FAILED			 ( 0x0000 + cOCTVC1_OBM_RF_FRONTEND_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_UNHANDLED_FREQUENCY		 ( 0x0001 + cOCTVC1_OBM_RF_FRONTEND_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_UNHANDLED_BAND			 ( 0x0002 + cOCTVC1_OBM_RF_FRONTEND_RC_BASE )
#define cOCTVC1_OBM_RC_RF_FRONTEND_CALIBRATED_TX_ATT_ERROR	 ( 0x0003 + cOCTVC1_OBM_RF_FRONTEND_RC_BASE )

/****************************************************************************
	PLUGIN return codes
 ****************************************************************************/
#define cOCTVC1_OBM_PLUGIN_RC_BASE							 ( 0x0500 + cOCTVC1_OBM_RC_BASE )

#define cOCTVC1_OBM_RC_PLUGIN_ERROR							 ( 0x0000 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* Generic error occurred in the plugin framework. */
#define cOCTVC1_OBM_RC_PLUGIN_NOT_FOUND						 ( 0x0001 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* The requested plugin was not found. */
#define cOCTVC1_OBM_RC_PLUGIN_INTERPRETER_FAILED			 ( 0x0002 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* Failed to start the script interpreter. */
#define cOCTVC1_OBM_RC_PLUGIN_SYNTAX_ERROR					 ( 0x0003 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* The parsed plugin has a syntax error. */
#define cOCTVC1_OBM_RC_PLUGIN_CALL_FAILED					 ( 0x0004 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* There was an error calling the required plugin function. */
#define cOCTVC1_OBM_RC_PLUGIN_UNHANDLED						 ( 0x0005 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* The scanned plugin cannot be handled by this obm version. */
#define cOCTVC1_OBM_RC_PLUGIN_BAD_PARAM						 ( 0x0006 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* Function was given a bad parameter. */
#define cOCTVC1_OBM_RC_PLUGIN_NOT_IMPLEMENTED				 ( 0x0007 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* Function call is not implemented yet. */
#define cOCTVC1_OBM_RC_PLUGIN_NOT_SUPPORTED					 ( 0x0008 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* Targeted component does not exist on this board. */
#define cOCTVC1_OBM_RC_PLUGIN_HARDWARE_MALFUNCTION			 ( 0x0009 + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* Plugin has detected that the hardware it manages is not functioning properly. */
#define cOCTVC1_OBM_RC_PLUGIN_BAD_BUS_ID					 ( 0x000A + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* The requested bus is not available. */
#define cOCTVC1_OBM_RC_PLUGIN_IO_ERROR						 ( 0x000B + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* Error accessing the requested device. */
#define cOCTVC1_OBM_RC_PLUGIN_BAD_EEPROM_FORMAT				 ( 0x000C + cOCTVC1_OBM_PLUGIN_RC_BASE ) 	/* The attached EEPROM is of the wrong fromat. */

#endif /* OCTVC1_OBM_RC_H__ */

