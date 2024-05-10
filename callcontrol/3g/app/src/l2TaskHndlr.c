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
 * File Name	: l2TaskHndlr.c
 *
 * Description  : This file has is entry point of all Message received in L2 Task 
 *
 * History 	:
 *
 * Date		 Author 				 Details
 * ---------------------------------------------------------------------------
 * 13/10/2014	 Kuldeep S. Chauhan 	 File Creation
 *############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * ----------------------------------------------------- */
#include "stdio.h"
#include "l2TaskHndlr.h"
//#include "macFpInterface.h"
#include "rlcContext.h"
#include "macContext.h"
#include "rrc.h"
//#include "logFile.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = app;

void l2UlDataTaskHndlr(Msg_t ulDataMsg)
{
   MacUlDataInd_t *ulDataInd = NULL;

   DEBUG3(("L2: == ENTRY == l2UlDataTaskHndlr: srcTask(%d), dstTask(%d), msgType(%d)\n", ulDataMsg.srcTaskId, ulDataMsg.dstTaskId, ulDataMsg.msgType));
   switch(ulDataMsg.srcTaskId)
   {
      //Message Received from CL, NBAP Message.
      case CL_L1C_RCV_TASK_E:
         ulDataInd = (MacUlDataInd_t *)ulDataMsg.msgBuf;
         switch(ulDataMsg.msgType)
         {
            //Message Type for Message from CL to L2_UL_data
            case CL_L2_UL_RACH_DATA_IND:
                //printf("L2UL: RACH_DATA_IND Recceived \n");
                DEBUG3(("L2: === L2UL TASK: RACH DATA RECEIVED \n"));
                RachDataIndHndlr(ulDataInd);
                break;
            case CL_L2_UL_DCH_DATA_IND:
                DEBUG3(("L2: === L2UL TASK: DCH DATA RECEIVED \n"));
                DchDataIndHndlr(ulDataInd);
                break;
            default: 
               DEBUG2(("L2: === ERROR === Unknown Msg received in App from CL_L1C_TASK\n"));
               break;
         }
         break;
      case L2_DL_DATA_TASK_E:
         DEBUG1(("L2: === ERROR === Msg received in L2UL_DATA Task from L2_DL_DATA_TASK_E\n"));
         break;
      case L2_CFG_TASK_E:
         DEBUG1(("L2: === ERROR === Msg received in L2UL_DATA Task from  L2_CFG_TASK_E\n"));
         break;
      default:
         DEBUG1(("L2: === ERROR === Msg received in L2UL_DATA Task from  UNKNOWN TASK\n"));
         break;
   }

   return ;
} /*End Of l2UlDataTaskHndlr*/

void l2DlDataTaskHndlr(Msg_t dlDataMsg)
{
   U32 bfn = 0;

   //printf("ENTRY l2DlDataTaskHndlr: srcTask(%d), dstTask(%d), msgType(%d)\n", dlDataMsg.srcTaskId, dlDataMsg.dstTaskId, dlDataMsg.msgType);
   switch(dlDataMsg.srcTaskId)
   {
      //Message Received from CL, NBAP Message.
      case CL_L1C_RCV_TASK_E:
         switch(dlDataMsg.msgType)
         {
            // This is received in every TTI, so no print as it will fill the logs.
            case CL_L2_DL_TTI_IND:
                bfn = *((U32 *)dlDataMsg.msgBuf);
                // TTI Indication received from L1
                //printf("TTI Ind Received in MAC for Bfn (%d)\n", bfn);
                MacTtiIndHndlr(bfn);
                break;
            default: 
               DEBUG1(("L2: === ERROR === Unknown Msg received in App from CL_L1C_TASK\n"));
               break;
         }
         break;
      case APP_RRC_TASK_E:
         switch(dlDataMsg.msgType)
         {
            case L2_DL_CCCH_DATA_REQUEST_E:
               DEBUG3(("L2: === L2: DL_CCCH_RRC_Msg received in L2_DL_DATA Task from APP_RRC_TASK_E\n"));
               RlcDlCcchDataHndlr((RrcDataReq *) dlDataMsg.msgBuf);
               break;
            case L2_DL_DCCH_DATA_REQUEST_E:
               DEBUG3(("L2: === L2: DL_DCCH_RRC_Msg received in L2_DL_DATA Task from APP_RRC_TASK_E\n"));
               RlcDlDcchDataHndlr((RrcDataReq *) dlDataMsg.msgBuf);
               break;
            case L2_DL_PCCH_DATA_REQUEST_E:
               DEBUG1(("L2: === L2: DL_PCCH_RRC_Msg received in L2_DL_DATA Task from APP_RRC_TASK_E\n"));
               MacAddPcchMsgToMacPagingContext((RrcPcchMsg *) dlDataMsg.msgBuf);
               break;
            case L2_DL_DEL_PCCH_DATA_REQUEST_E:
               DEBUG1(("L2: === L2: DL_DEL_PCCH_RRC_Msg received in L2_DL_DATA Task from APP_RRC_TASK_E\n"));
               MacDelPcchMsgFromMacPagingContext((char *) dlDataMsg.msgBuf, 1);
               break;
            case L2_CONFIG_DEL_PCH_DATA_REQUEST_E:
               DEBUG1(("L2: === L2: DEL_PCCH_DATA_RRC_Msg received in L2_DL_DATA Task from APP_RRC_TASK_E\n"));
               MacClaenupMacPagingContext();
               break;
            default: 
               DEBUG1(("L2: === ERROR === Unknown Msg received in App from APP_RRC_TASK_E\n"));
               break;
         }
         break;
      case L2_UL_DATA_TASK_E:
         DEBUG1(("L2: === ERROR === Msg received in L2_DL_DATA Task from L2_UL_DATA_TASK_E\n"));
         break;
      case L2_CFG_TASK_E:
         DEBUG1(("L2: === ERROR === Msg received in L2_DL_DATA Task from  L2_CFG_TASK_E\n"));
         break;
      default:
         DEBUG1(("L2: === ERROR === Msg received in L2_DL_DATA Task from  UNKNOWN TASK\n"));
         break;
   }

   return ;
}

void l2CfgTaskHndlr(Msg_t msgBuf)
{
   DEBUG3(("L2: == ENTRY == l2CfgTaskHndlr: srcTask(%d), dstTask(%d), msgType(%d)\n", msgBuf.srcTaskId, msgBuf.dstTaskId, msgBuf.msgType));

   unsigned int ueIdx = *((unsigned int *) msgBuf.msgBuf);
   ueIdx = ueIdx + 1; // RRC Index is starting from 0 where L2 Index is starting from 1
   
   //printf("ENTRY l2DlDataTaskHndlr: srcTask(%d), dstTask(%d), msgType(%d)\n", dlDataMsg.srcTaskId, dlDataMsg.dstTaskId, dlDataMsg.msgType);
   switch(msgBuf.srcTaskId)
   {
      //Message Received from CL, NBAP Message.
      case APP_RRC_TASK_E:
         switch(msgBuf.msgType)
         {
            case L2_CONFIG_REQUEST_E:
               DEBUG3(("L2: === Request for ueIdx (%d) received in L2 Cfg Task from APP_RRC_TASK_E\n",ueIdx));
               MacUeCfgReq(ueIdx);  // Pass UE Id
               RlcUeCfgReq(ueIdx);  // Pass UE Id       
               break;
			   
            case L2_CONFIG_DEL_REQUEST_E:
               DEBUG3(("L2: ===  Delete Request for ueIdx (%d) received in L2 Cfg Task from APP_RRC_TASK_E\n",ueIdx));
               MacCfgDelReq(ueIdx);
               RlcCfgDelReq(ueIdx);
               break;           
            default:
               DEBUG1(("L2: === ERROR === Msg(%d) received in L2_DL_DATA Task\n", msgBuf.msgType));
               break;
         }
         break;
      default:
         DEBUG1(("L2: === ERROR === Msg received in L2_DL_DATA Task from TaskId(%d)\n", msgBuf.srcTaskId));
         break;
   }

   free(msgBuf.msgBuf);
   
   return ; //Dummy
}

void InitializeL2Context(void )
{
   DEBUG3(("L2: =============== Initialize L2 context ============\n"));
   // Initialize MAC Context
   InitMacCellContext();
   InitMacRachContext();
   InitMacFachContext();
   InitMacUeContext();
   InitMacPagingContext();

   // Initialize RLC Context
   InitRlcContext();

   return;
}
