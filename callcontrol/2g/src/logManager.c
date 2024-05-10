/*
*############################################################################
*
*                   *** FXLynx Technologies Ltd. ***
*
*     The information contained in this file is the property of FXLynx
*     Technologies Ltd. Except as specifically authorized in writing by
*     FXLynx Technologies Ltd. The user of this file shall keep information
*     contained herein confidential and shall protect same in whole or in
*     part from disclosure and dissemination to third parties.
*
*     Without prior written consent of FXLynx Technologies Ltd. you may not
*     reproduce, represent, or download through any means, the information
 *     contained herein in any way or in any form.
*
*       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
*
*############################################################################
*/

/*
*############################################################################
* File Name   : logManager.c
 *
* Description : Logging API functions
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 5/11/2014          					Anand Kashikar       File Creation
*############################################################################
*/
#include "logManager.h"
#include "l1Constants.h"
//#define DEBUG_WITH_PRINTF

#ifdef DEBUG_WITH_PRINTF
#include <stdio.h>
#endif

extern unsigned char boardDspType;
extern unsigned char logsEnabled;
void logManagerInit()
{
  if(logsEnabled == 0)
  {
	return ;
  }

#ifndef DEBUG_WITH_PRINTF
	if(boardDspType == 0)
		openlog("WGSPri",LOG_CONS|LOG_PID|LOG_NDELAY,LOG_LOCAL0);
	else
		openlog("WGSSec",LOG_CONS|LOG_PID|LOG_NDELAY,LOG_LOCAL1);
#endif
}

char * logGetUserStateString( gsmL23States userState )
{
    static char userStateStr[51][50]={            
    	    "NULL_STATE",
    	    "RACH_RECEIVED",
    	    "SDCCH_CHANNEL_ALLOCATED",
    	    "CM_SERVICE_REQ_RECEIVED",
    	    "LAU_REQ_RECEIVED",
    	    "IMSI_RECEIVED",
    	    "IMEI_RECEIVED",
    	    "TMSI_REALLOCATION_COMPLETE_RECEIVED",
    	    "PAGING_RESP_RECEIVED",
    	    "LCS_POS_RECEIVED",
    	    "CIPHERING_MODE_COMPLETE_RECEIVED",
    	    "SETUP_RECEIVED",
    	    "DISC_RECEIVED",
    	    "WAITING_FOR_L2ACK",
    	    "WAITING_FOR_IDENTITY_RSP",
    	    "WAITING_FOR_LCS_POSN_RSP",
    	    "WAITING_FOR_LAUCM_REJECT_RSP",
    	    "WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE",
    	    "WAITING_FOR_CIPHERING_MODE_COMPLETE",
    	    "L3_REJECT_FOR_UE",
    	    "TCH_ALLOCATED",
    	    "WAITING_FOR_SABM_ON_FACCH",
    	    "SABM_RECEIVED_ON_FACCH",
    	    "TCH_SILENT_CALL_IN_PROGRESS",
    	    "SDCCH_SILENT_CALL_IN_PROGRESS",
    	    "WAITING_FOR_CLASSMARK",
    	    "END_SILENT_CALL",
	        "WAITING_TO_SEND_SETUP",
	        "WAITING_FOR_CALL_CONF",
	        "CALL_CONF_RCVD",
	        "CALL_PROC_SENT",
	        "MT_ASSGN_COMP_RCVD",
	        "WAITING_FOR_ALERT",
	        "ALERT_RCVD",
	        "WAITING_FOR_MT_CONNECT",
	        "PH_CONNECT_RCVD",
	        "DISC_SENT",
	        "REL_PROC",
	        "WAITING_FOR_REL_CMP",
	        "WAITING_FOR_CALL_EST",
	        "CALL_EST",
	        "HOLD_RCVD",
			"EST_L2_SAPI3_FOR_MT_SMS",
			"CP_ACK_RECEIVED",
            "CP_DATA_RECEIVED",
            "CP_ACK_SENT",
            "ATTACH_RECEIVED",
            "CLASSMARK_RECEIVED", 
#ifdef MM_INFO
            "MM_INFO_SENT",
#endif
            "RRLP_GPS_ASSIST_DATA_SENT",
            "RRLP_GPS_ASSIST_DATA_ACK_RCVD"
    };

    if( userState > RRLP_GPS_ASSIST_DATA_ACK_RCVD )
        return ( "INVALID_STATE" );
    else
        return( &userStateStr[userState][0] );
}

#if 0
char * logGetFxlHdrMsgTypeString( fxLMsgType msgType )
{
    switch(msgType)
    {
        case FXL_HANDSHAKE_CMD:
        {
            return((char*)"FXL_HANDSHAKE_CMD");
        }
        break;
        case FXL_HANDSHAKE_RSP:
        {
            return((char*)"FXL_HANDSHAKE_RSP");
        }
        break;
        case FXL_CONFIGURE_IDENTITY_LIST_CMD:
        {
            return((char*)"FXL_CONFIGURE_IDENTITY_LIST_CMD");
        }
        break;
        case FXL_CONFIGURE_IDENTITY_LIST_RSP:
        {
            return((char*)"FXL_CONFIGURE_IDENTITY_LIST_RSP");
        }
        break;
        case FXL_BOOT_L1_CMD:
        {
            return((char*)"FXL_BOOT_L1_CMD");
        }
        break;
        case FXL_BOOT_L1_RSP:
        {
            return((char*)"FXL_BOOT_L1_RSP");
        }
        break;
        case FXL_2G_CONFIGURE_IDCATCHER_PARAMS_CMD:
        {
            return((char*)"FXL_2G_CONFIGURE_IDCATCHER_PARAMS_CMD");
        }
        break;
        case FXL_2G_CONFIGURE_IDCATCHER_PARAMS_RSP:
        {
            return((char*)"FXL_2G_CONFIGURE_IDCATCHER_PARAMS_RSP");
        }
        break;
        case FXL_2G_START_IDCATCHER_CMD:
        {
            return((char*)"FXL_2G_START_IDCATCHER_CMD");
        }
        break;
        case FXL_2G_START_IDCATCHER_RSP:
        {
            return((char*)"FXL_2G_START_IDCATCHER_RSP");
        }
        break;
        case FXL_2G_GET_RSSI_GPS_COORDINATES_CMD:
        {
            return((char*)"FXL_2G_GET_RSSI_GPS_COORDINATES_CMD");
        }
        break;
        case FXL_2G_GET_RSSI_GPS_COORDINATES_RSP:
        {
            return((char*)"FXL_2G_GET_RSSI_GPS_COORDINATES_RSP");
        }
        break;
        case FXL_2G_GET_RSSI_GPS_COORDINATES_IND:
        {
            return((char*)"FXL_2G_GET_RSSI_GPS_COORDINATES_IND");
        }
        break;
        case FXL_2G_GET_BLOCKED_CALL_COUNTER_CMD:
        {
            return((char*)"FXL_2G_GET_BLOCKED_CALL_COUNTER_CMD");
        }
        break;
        case FXL_2G_GET_BLOCKED_CALL_COUNTER_RSP:
        {
            return((char*)"FXL_2G_GET_BLOCKED_CALL_COUNTER_RSP");
        }
        break;
#ifdef FEA_SILENT_CALL
        case FXL_2G_START_SILENT_CALL_CMD:
        {
            return((char*)"FXL_2G_START_SILENT_CALL_CMD");
        }
        break;
        case FXL_2G_START_SILENT_CALL_RSP:
        {
            return((char*)"FXL_2G_START_SILENT_CALL_RSP");
        }
        break;
        case FXL_2G_MODIFY_UE_TX_POWER_CMD:
        {
            return((char*)"FXL_2G_MODIFY_UE_TX_POWER_CMD");
        }
        break;
        case FXL_2G_MODIFY_UE_TX_POWER_RSP:
        {
            return((char*)"FXL_2G_MODIFY_UE_TX_POWER_RSP");
        }
        break;
        case FXL_2G_END_SILENT_CALL_CMD:
        {
            return((char*)"FXL_2G_END_SILENT_CALL_CMD");
        }
        break;
        case FXL_2G_END_SILENT_CALL_RSP:
        {
            return((char*)"FXL_2G_END_SILENT_CALL_RSP");
        }
        break;
#endif /* FEA_SILENT_CALL */

#ifdef FEA_MT_SMS
        case FXL_2G_SEND_INDIVIDUAL_SMS_CMD:
        {
            return((char*)"FXL_2G_SEND_INDIVIDUAL_SMS_CMD");
        }
        break;
        case FXL_2G_SEND_INDIVIDUAL_SMS_RSP:
        {
            return((char*)"FXL_2G_SEND_INDIVIDUAL_SMS_RSP");
        }
        break;
        case FXL_2G_SEND_BROADCAST_SMS_CMD:
        {
            return((char*)"FXL_2G_SEND_BROADCAST_SMS_CMD");
        }
        break;
        case FXL_2G_SEND_BROADCAST_SMS_RSP:
        {
            return((char*)"FXL_2G_SEND_BROADCAST_SMS_RSP");
        }
        break;
#endif /* FEA_MT_SMS */
        case FXL_2G_REGISTRATION_ATTEMPTED_IND:
        {
            return((char*)"FXL_2G_REGISTRATION_ATTEMPTED_IND");
        }
        break;
        case FXL_2G_MO_CALL_ATTEMPTED_IND:
        {
            return((char*)"FXL_2G_MO_CALL_ATTEMPTED_IND");
        }
        break;
        case FXL_2G_STOP_IDCATCHER_CMD:
        {
            return((char*)"FXL_2G_STOP_IDCATCHER_CMD");
        }
        break;
        case FXL_2G_STOP_IDCATCHER_RSP:
        {
            return((char*)"FXL_2G_STOP_IDCATCHER_RSP");
        }
        break;
        case FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_CMD:
        {
            return((char*)"FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_CMD");
        }
        break;
        case FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_RSP:
        {
            return((char*)"FXL_2G_LISTEN_MODE_CONFIGURE_BANDS_RSP");
        }
        break;
        case FXL_2G_LISTEN_MODE_START_SCAN_CMD:
        {
            return((char*)"FXL_2G_LISTEN_MODE_START_SCAN_CMD");
        }
        break;
        case FXL_2G_LISTEN_MODE_START_SCAN_RSP:
        {
            return((char*)"FXL_2G_LISTEN_MODE_START_SCAN_RSP");
        }
        break;
        case FXL_2G_LISTEN_MODE_STOP_SCAN_CMD:
        {
            return((char*)"FXL_2G_LISTEN_MODE_STOP_SCAN_CMD");
        }
        break;
        case FXL_2G_LISTEN_MODE_STOP_SCAN_RSP:
        {
            return((char*)"FXL_2G_LISTEN_MODE_STOP_SCAN_RSP");
        }
        break;
        case FXL_2G_LISTEN_MODE_SYSTEM_INFO_IND:
        {
            return((char*)"FXL_2G_LISTEN_MODE_SYSTEM_INFO_IND");
        }
        break;
        case FXL_2G_LISTEN_MODE_SCAN_COMPLETE_IND:
        {
            return((char*)"FXL_2G_LISTEN_MODE_SCAN_COMPLETE_IND");
        }
        break;
        default:
        {
            return((char*)"Invalid msgType");
        }
        break;
    }
}
#endif /* #if 0 */

void logPrint(int logPriority , const char *message, ...)
{
	if(logsEnabled == 0)
	{
	  return ;
	}

#ifndef DEBUG_WITH_PRINTF
	  va_list args;
	  va_start(args, message);
	  {
		if(boardDspType == 0)
			vsyslog(logPriority|LOG_LOCAL0 , message, args);
		else
			vsyslog(logPriority|LOG_LOCAL1 , message, args);
	  }
	  va_end(args);
#else
	  if(logPriority < LOG_DEBUG)
	  {
		  va_list args;
		  va_start(args, message);
		  vprintf(message, args);
		  va_end(args);
	  }
#endif
	 return;
}

void logManagerExit()
{
	if(logsEnabled == 0)
	{
	  return ;
	}

#ifndef DEBUG_WITH_PRINTF
	closelog();
#endif
}
