/*############################################################################
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
 *############################################################################*/
/*############################################################################
 * File Name	: rrcAppMsgHndlr.c
 *
 * Description  : This file has is entry point of all Message received in RRC/APP
 *
 * History 	:
 *
 * Date		 Author 				 Details
 * ---------------------------------------------------------------------------
 * 12/09/2014	 Kuldeep S. Chauhan 	 File Creation
 *############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * ----------------------------------------------------- */
#include "stdio.h"
#include "callCTaskHndlr.h"
#include "clSendL1Msg.h"
#include "cmnDebug.h"
#include "feaConfig.h"


static DbgModule_e  DBG_MODULE = app;

ErrorCode_e rrcAppTaskHndlr(Msg_t msgBuf)
{
   logPrint(LOG_ERR, "rrcAppTaskHndlr :: lastLac \n");
   DEBUG3(("ENTRY rrcAppTaskHndlr: srcTask(%d), dstTask(%d), msgType(%d)\n", msgBuf.srcTaskId, msgBuf.dstTaskId, msgBuf.msgType));
   switch(msgBuf.srcTaskId)
   {
   //Message Received from CL, NBAP Message.
   case CL_L1C_RCV_TASK_E:
      switch(msgBuf.msgType)
      {
      case CL_NBAP_MODEM_SETUP_RSP_MSG_E:
      case CL_NBAP_CELL_DELETE_RSP_E:
      case CL_NBAP_CELL_SETUP_RSP_E:
      case CL_NBAP_CELL_RECONFIG_RSP_E:
      case CL_NBAP_SYSTEM_INFO_UPDATE_RSP_E:
      case CL_NBAP_SCCPCH_SETUP_RSP_E:
      case CL_NBAP_PRACH_SETUP_RSP_E:
         DEBUG3(("NBAP CellSm related msg received in App from CL_L1C_RCV_TASK_E\n"));
         CellSmEvntHndlr(msgBuf);
         break;	

      case CL_NBAP_UE_RADIO_LINK_SETUP_RSP_E:
      case CL_NBAP_UE_RADIO_LINK_FAILURE_E:
      case CL_NBAP_UE_RADIO_LINK_DELETE_RSP_E:
      case CL_NBAP_UE_RTT_DEDICATED_MEAS_INIT_RSP_E:
      case CL_NBAP_UE_RSCP_DEDICATED_MEAS_INIT_RSP_E:
      case CL_NBAP_UE_RTT_DEDICATED_MEAS_REPORT_E:
      case CL_NBAP_UE_RSCP_DEDICATED_MEAS_REPORT_E: 
      case CL_NBAP_UE_RTT_DEDICATED_MEAS_TERM_RSP_E:
      case CL_NBAP_UE_RSCP_DEDICATED_MEAS_TERM_RSP_E:
      case CL_NBAP_UE_RADIO_LINK_RECONFIG_READY_E:
         DEBUG3(("NBAP UE Specific msg received in App from CL_L1C_RCV_TASK_E\n"));
         UeSmL1EvtHndlr(msgBuf); 
         break;	

      case RRC_RL_SETUP_TIMEOUT_E:
      case RRC_RL_DELETE_TIMEOUT_E:
      case RRC_CONN_SETUP_TIMEOUT_E:
      case RRC_IDENTITY_REQ_TIMEOUT_E:
      case RRC_CONNECTION_REL_TIMEOUT_E:
      case RRC_NAS_REJECT_TIMEOUT_E:
      case RRC_DED_MEAS_INIT_REQ_TIMEOUT_E:
      case RRC_DED_MEAS_TERM_REQ_TIMEOUT_E:
      case RRC_PHY_CH_RECONF_TIMEOUT_E:
      case RRC_START_GPS_TIMEOUT_E:
      case RRC_GPS_MEAS_CNTRL_REL_TIMEOUT_E:

      case RRC_PAGING_TYPE2_TIMEOUT_E:
         DEBUG3(("RRC : Timeout Message Received\n"));
         UeSmTimerEvtHndlr (msgBuf);
         break;
          
      default: 
         DEBUG2(("ERROR: Unknown Msg received in App from CL_L1C_RCV_TASK_E\n"));
         break;
      }
      break;

   case L2_UL_DATA_TASK_E:
      DEBUG3(("RRC : Msg received from L2_UL_DATA_TASK_E\n"));
      UeSmL2EvtHndlr (msgBuf);
      break;
   case L2_DL_DATA_TASK_E:
      IdleUeEvtHndlr(msgBuf);
      DEBUG1(("RRC :  Msg received in App from L2_DL_DATA_TASK_E:\n"));
      break;
   case L2_CFG_TASK_E:
      DEBUG1(("ERROR: Msg received in App from L2_CFG_TASK_E\n"));
      break;

   case SOCK_ITF_TASK_E:
      AppSocketItfEvtHndlr (msgBuf); 
      break;
   default:
      DEBUG1(("ERROR: Msg received in App from UNKNOWN TASK\n"));
      break;
     
   }

   return SUCCESS_E;
}

void clL1CSndTaskHndlr (Msg_t msgBuf)
{
   DEBUG3(("ENTRY clL1CSndTaskHndlr: srcTask(%d), dstTask(%d), msgType(%d)\n", 
          msgBuf.srcTaskId, msgBuf.dstTaskId, msgBuf.msgType));

   switch(msgBuf.srcTaskId)
   {
      case APP_RRC_TASK_E:
         clL1CSndTaskHandleAppRrcMsg (msgBuf);
         break;

      default:
         DEBUG1(("ERROR: Message received from Unknown Task by CL Send Task\n"));
         break;
   }

   return ; //Dummy
}
