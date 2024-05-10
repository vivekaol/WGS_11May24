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
 ############################################################################ */
/*############################################################################
 * File Name	 : clSendL1Msg.c  
 *
 * Description   : This file has interface with L1, all data/control msg are sent
 *                 to L1 throught this file
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 12/09/2014	 Kuldeep S. Chauhan 	 File Creation
 * 28/09/2014	 Ashutosh Samal          Added Radio Link Setup
 ############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "l1capi_datastruct.h"
#include "clSendL1Msg.h"
#include "clContext.h"
#include "l1MsgStatus.h"
#include "msgHeaderDef.h"
#include "L1C_responseProcDecHdlr.h"
#include "msgPrimitives.h"
#include "cmnDs.h"
#include "msgHeaderCodec.h"
#include "oct_l1cIoApi.h"
#include "stdlib.h"
#include "errorCode.h"
#include "msgPutPrimitives.h"
#include "taskHndlr.h"
#include "msgQue.h"
#include "cmnPf.h"
#include "macContext.h"
#include "cmnDebug.h"
#include "rrc.h"
#include "callCDefaultParam.h"
#include "umtsCfg.h"
#include "timerApi.h"
#include "fxLSocketInterfaceApi.h"

void *pHostDLMsg;

static DbgModule_e  DBG_MODULE = app;
extern UmtsConfigControlBlock  gUmtsConfig;
extern L1CAPI_Radiolink_Setup_Request   gRadioLinkSetupReq;
extern L1CAPI_Radiolink_DeletionRequest gRadioLinkDeleteReq;
extern L1CAPI_Dedicated_Meas_Init_Request gDedicatedMeasInitReq;
extern L1CAPI_Dedicated_Meas_Term_Request gDedicatedMeasTermReq;
extern MacPagingContext_t               gMacPagingContext;
extern L1CAPI_Radiolink_Reconfig_Prepare gRadioLinkReconfPrepReq;
extern L1CAPI_Radiolink_ReconfigCommit   gRadioLinkReconfCommitReq;


/*
 * Client File Descriptor for sending indication to external client
 */
extern int clientFd;

uint32_t clMsgHdrProcEncHdlr (L1MsgStatus_t *msgStatus, L1MsgId_e msgId, 
                              L1MsgType_e msgType, uint32_t transactionId,
                              uint32_t buffLen)
{
   L1CAPI_MsgHdr l1cMsgHeader;

   l1cMsgHeader.msgSize = findMsgBodySize();
   l1cMsgHeader.msgSize += buffLen;
   l1cMsgHeader.msgId = msgId;
   l1cMsgHeader.msgType = msgType;
   l1cMsgHeader.transactionId = transactionId;
   l1c_msgHdrMsgEncHdlr(msgStatus, &l1cMsgHeader);

   return (l1cMsgHeader.msgSize + MSG_HDR_SIZE);
}

ErrorCode_e sendToOctL1 (L1MsgStatus_t *pMsgStatus, 
                 L1MsgId_e msgId, L1MsgType_e msgType, uint32_t *sendBuf,
                 uint32_t trId, uint32_t buffLen)
{
    ErrorCode_e     retCode   = SUCCESS_E;
    U8              port = L1API_PORT_CPLANE_REQ;  
    L1API_Error_t   err;
    uint32_t        totalMsgSize = 0;

    totalMsgSize = clMsgHdrProcEncHdlr (pMsgStatus, msgId, msgType, trId, buffLen);
    /* Send the message to the L1 API */
    port = (FP_MSG == msgType) ? (L1API_PORT_UPLANE_DL) : (L1API_PORT_CPLANE_REQ);

    err = L1API_SendMsg(NULL,
                        port,
                        sendBuf,
                        totalMsgSize,
                        CL_MSG_BUF_SIZE);

    if (err != L1API_NO_ERROR)
    {
        DEBUG1(("Sending failed err %u\n",err));
        retCode = ERROR_GENERIC_FAILURE_E;
    }
    return (retCode);
}

ErrorCode_e oct_modem_setup_req (L1CAPI_Modem_Setup_Request *pModSetupReq)
{
    ErrorCode_e retCode   = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octModemSetupReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
    
    memset( octModemSetupReqEncodedBuf, 0, CL_MSG_BUF_SIZE* sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octModemSetupReqEncodedBuf);

    pHostDLMsg = pModSetupReq;
    modemSetupRequestProcEncHdlr(&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    { 
        retCode = sendToOctL1(&msgStatus,
                              MODEM_SETUP_REQUEST,
                              CTRL_NBAP_MSG,
                              octModemSetupReqEncodedBuf,
                              transId,0);

        gClCntxt.cellState = CL_WAIT_FOR_MODEM_SETUP_RESP;

        DEBUGMSG(("Modem Setup Request to L1 is sent, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("Sending Modem Setup Request to L1 is failed MsgResult %d add0 %d add1 %d\n", msgStatus.l1MsgResult,
                  msgStatus.additionalInfo0, msgStatus.additionalInfo1));
        retCode = ERROR_GENERIC_FAILURE_E;
    }		

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;
	
    return (retCode); 
}

ErrorCode_e oct_cell_delete_req (L1CAPI_Cell_Delete_Request *pCellDeleteRequest)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octCellDeleteReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
    
    memset( octCellDeleteReqEncodedBuf, 0, CL_MSG_BUF_SIZE* sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octCellDeleteReqEncodedBuf);

    pHostDLMsg = pCellDeleteRequest;
    cellDeleteRequestProcEncHdlr(&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    {  
        retCode = sendToOctL1(&msgStatus,
                              CELL_DELETE_REQUEST,
                              CTRL_NBAP_MSG,
                              octCellDeleteReqEncodedBuf,
                              transId,0);

        gClCntxt.cellState = CL_WAIT_FOR_CELL_DELETE_RESP;

        DEBUGMSG(("Cell Delete Reqs is sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("Sending Cell Delete Req is failed MsgResult %d add0 %d add1 %d\n", 
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));

        retCode = ERROR_GENERIC_FAILURE_E;
    }

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}

ErrorCode_e oct_cell_setup_req (L1CAPI_Cell_Setup_Request *pCelSetupReq)
{
   ErrorCode_e retCode = SUCCESS_E;
   L1CAPI_Msg_Status msgStatus;
   uint32_t octCellSetupReqEncodedBuf[CL_MSG_BUF_SIZE];
   uint32_t transId;

   transId = gClCntxt.cPlaneTrnsId;

   msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
      
   /* The data needs to be copied to L1 */
   memset( octCellSetupReqEncodedBuf, 0, CL_MSG_BUF_SIZE* sizeof(uint32_t));
   resetMsgWrite((uint8_t*)octCellSetupReqEncodedBuf);
  
   /*Encode */
   pHostDLMsg = pCelSetupReq;
   cellSetupRequestProcEncHdlr(&msgStatus);
   if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
   {   
       retCode = sendToOctL1(&msgStatus,
                             CELL_SETUP_REQUEST,
                             CTRL_NBAP_MSG,
                             octCellSetupReqEncodedBuf,
                             transId,
                             0);

       gClCntxt.cellState = CL_WAIT_FOR_CELL_SETUP_RESP;

       DEBUGMSG(("Cell Setup Request is sent to L1, Status = %d\n",retCode));
   }
   else
   {
       retCode = ERROR_GENERIC_FAILURE_E;
       DEBUG1(("Sending Cell Setup Request to L1 is failed MsgResult %d add0 %d add1 %d\n", msgStatus.l1MsgResult,
        msgStatus.additionalInfo0, msgStatus.additionalInfo1));
   }

   gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

   cleanMemCellSetupReq ();

   return (retCode);
}

ErrorCode_e oct_sccpch_setup_req (L1CAPI_Sccpch_Setup_Request *pSccpchSetupReq)
{
   ErrorCode_e retCode = SUCCESS_E;
   L1CAPI_Msg_Status msgStatus;
   uint32_t octSccpchReqEncodedBuf[CL_MSG_BUF_SIZE];
   uint32_t transId;
   
   transId = gClCntxt.cPlaneTrnsId;

   msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
 
   /* the data needs to be copied to L1 */
   memset( octSccpchReqEncodedBuf, 0, CL_MSG_BUF_SIZE* sizeof(uint32_t));
   resetMsgWrite((uint8_t*)octSccpchReqEncodedBuf);

   pHostDLMsg = pSccpchSetupReq;
   cmnTrchSccpchSetupRequestProcEncHdlr(&msgStatus);
   if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
   {
       retCode = sendToOctL1(&msgStatus,
                             CMN_TRCH_SCCPCH_SETUP_REQUEST,
                             CTRL_NBAP_MSG,
                             octSccpchReqEncodedBuf,
                             transId,0);

       gClCntxt.cellState = CL_WAIT_FOR_SCCPCH_SETUP_RESP;

       DEBUGMSG(("Sent SCCPCH setup ret %d\n",retCode));
   }
   else
   {
       retCode = ERROR_GENERIC_FAILURE_E;
                 DEBUG1(("CL : Sending SCCPCH Setup Request to L1 is failed MsgResult %d add0 %d add1 %d\n",
                 msgStatus.l1MsgResult,
                 msgStatus.additionalInfo0, msgStatus.additionalInfo1));
   }		
        
   gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

   cleanMemSccpchSetupRequest ();

   return (retCode);
}

ErrorCode_e oct_prach_setup_req (L1CAPI_Prach_Setup_Request *pPrachSetupReq)
{
   ErrorCode_e retCode = SUCCESS_E;
   L1CAPI_Msg_Status msgStatus;
   uint32_t octPrachSetupReqEncodedBuf[CL_MSG_BUF_SIZE];
   uint32_t transId;

   transId = gClCntxt.cPlaneTrnsId;

   msgStatus.l1MsgResult = L1_MSG_SUCCESS;

   memset( octPrachSetupReqEncodedBuf, 0, CL_MSG_BUF_SIZE* sizeof(uint32_t));
   resetMsgWrite((uint8_t*)octPrachSetupReqEncodedBuf);
   pHostDLMsg = pPrachSetupReq;
   cmnTrchPrachSetupRequestProcEncHdlr(&msgStatus);
   if (L1_MSG_SUCCESS == msgStatus.l1MsgResult)
   {  
       retCode = sendToOctL1(&msgStatus,
                             CMN_TRCH_PRACH_SETUP_REQUEST,
                             CTRL_NBAP_MSG,
                             octPrachSetupReqEncodedBuf,
                             transId,
                             0);

       gClCntxt.cellState = CL_WAIT_FOR_PRACH_SETUP_RESP;

       DEBUGMSG(("PRACH Setup Request is sent to L1, Status = %d\n", retCode));
   }
   else
   {
       DEBUG1(("Sending PRACH Setup Request to L1 is failed MsgResult %d add0 %d add1 %d\n", msgStatus.l1MsgResult,
       msgStatus.additionalInfo0, msgStatus.additionalInfo1));
       retCode = ERROR_GENERIC_FAILURE_E;
   }

   gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

   cleanMemPrachSetupRequest ();

   return (retCode);
}

ErrorCode_e oct_sysInfo_update (L1CAPI_BCH_SIM_DATA *pOctSysInfoUpdate)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octSysInfoReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;
        
    msgStatus.l1MsgResult = L1_MSG_SUCCESS;        

    memset( octSysInfoReqEncodedBuf, 0, CL_MSG_BUF_SIZE* sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octSysInfoReqEncodedBuf);

    pHostDLMsg = pOctSysInfoUpdate;
    systemInfoUpdateRequestProcEncHdlr(&msgStatus);

    if (L1_MSG_SUCCESS == msgStatus.l1MsgResult)
    {
        retCode = sendToOctL1(&msgStatus,
                              SYSTEM_INFO_UPDATE_REQUEST,
                              CTRL_NBAP_MSG,
                              octSysInfoReqEncodedBuf,
                              transId, 0);

        if (CL_WAIT_FOR_CELL_SETUP_RESP == gClCntxt.cellState)
        {
            gClCntxt.cellState = CL_WAIT_FOR_BRING_UP_SYSTEM_INFO_UPDATE_RESP;
        }
        else if (CL_WAIT_FOR_CELL_RECONFIG_RESP == gClCntxt.cellState)
        {
            gClCntxt.cellState = CL_WAIT_FOR_ONLINE_CPICH_SYSTEM_INFO_UPDATE_RESP;

            unsigned int *pCellId = (unsigned int *)malloc(sizeof(unsigned int));
            *pCellId = gUmtsConfig.cellId;

            /* Start the System Information Update Timer */
            timerStart(&gClCntxt.cellTimer,
                       CL_SYS_INFO_UPDATE_TIMEOUT,
                       0,
                       handleChgTxAttnCpichTxPwrTimeout,
                       pCellId);
        }
        else if(CL_CELL_ACTIVE == gClCntxt.cellState)
        {
            gClCntxt.cellState = CL_WAIT_FOR_ONLINE_SYSTEM_INFO_UPDATE_RESP;
             
            unsigned int *pCellId = (unsigned int *)malloc(sizeof(unsigned int));
            *pCellId = gUmtsConfig.cellId;

            /* Start the System Information Update Timer */
            timerStart(&gClCntxt.cellTimer,
                       CL_SYS_INFO_UPDATE_TIMEOUT,
                       0,
                       handleSystemInfoUpdateTimeout,
                       pCellId);
        }
        else
        {
            //Do Nothing
        }

        DEBUGMSG(("System Information Update Request is sent to L1, Status = %d\n", retCode));
    }
    else
    {
        retCode = ERROR_GENERIC_FAILURE_E;
        DEBUG1(("Sending System Information Update Request to L1 is failed MsgResult %d add0 %d add1 %d\n", 
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));
    }

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}

ErrorCode_e oct_radiolink_setup_req (L1CAPI_Radiolink_Setup_Request *pOctRlSetupReq)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octRadioLinkSetupReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
    
    memset( octRadioLinkSetupReqEncodedBuf, 0, CL_MSG_BUF_SIZE * sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octRadioLinkSetupReqEncodedBuf);

    pHostDLMsg = pOctRlSetupReq;
    radiolinkSetupRequestProcEncHdlr(&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    { 
        retCode = sendToOctL1(&msgStatus,
                              RADIOLINK_SETUP_REQUEST,
                              CTRL_NBAP_MSG,
                              octRadioLinkSetupReqEncodedBuf,
                              transId,0);

        DEBUGMSG(("CL Send Task : RadioLink Setup Req is sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Sending Radio Link Setup Req to L1 is failed MsgResult %d add0 %d add1 %d\n", 
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));

         retCode = ERROR_RADIO_LINK_FAILURE_E;
    }

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}

ErrorCode_e buildAndSendRadioLinkSetupReq (Msg_t msgBuf)
{
   unsigned int *pRlId = NULL;
   ErrorCode_e retCode = SUCCESS_E;

   pRlId = (unsigned int *)msgBuf.msgBuf;
   DEBUGMSG(("CL Send Task : Sending RADIO LINK SETUP REQUEST message to L1 with RL Id(%ld)\n", 
          *pRlId));

   fillRadioLinkSetupRequest (*pRlId);

   if(SUCCESS_E != oct_radiolink_setup_req(&gRadioLinkSetupReq))
   {
       DEBUG1(("CL Send Task : Radio Link Setup Request failed for RL Id(%ld)\n",
              *pRlId));

       retCode = ERROR_RADIO_LINK_FAILURE_E;
   }

   /* Free the Memory */
   cleanMemRadioLinkSetupRequest ();
   free (pRlId);
   pRlId = NULL;

   return (retCode);
}

ErrorCode_e oct_radiolink_reconfig_prep_req (L1CAPI_Radiolink_Reconfig_Prepare *pOctRlReconfigPrepReq)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octRadioLinkReconfigPrepReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
    
    memset( octRadioLinkReconfigPrepReqEncodedBuf, 0, CL_MSG_BUF_SIZE * sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octRadioLinkReconfigPrepReqEncodedBuf);

    pHostDLMsg = pOctRlReconfigPrepReq;
    radiolinkReconfigPrepRequestProcEncHdlr (&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    { 
        retCode = sendToOctL1(&msgStatus,
                              RADIOLINK_RECONFIG_PREP_REQUEST,
                              CTRL_NBAP_MSG,
                              octRadioLinkReconfigPrepReqEncodedBuf,
                              transId,0);

        DEBUGMSG(("CL Send Task : RadioLink Reconfig Prepare Req is sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Sending Radio Link Reconfig Prepare Req to L1 is failed MsgResult %d add0 %d add1 %d\n", 
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));

        retCode = ERROR_RADIO_LINK_RECONFIG_PREP_FAILURE_E;
    }

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}

ErrorCode_e buildAndSendRadioLinkReconfigPrepReq (Msg_t msgBuf)
{
   RadioLinkReconfigPrepReqInfo *pRLPrepReq = NULL;
   ErrorCode_e retCode = SUCCESS_E;

   pRLPrepReq = (RadioLinkReconfigPrepReqInfo *)msgBuf.msgBuf;
   DEBUGMSG(("CL Send Task : Sending RADIO LINK RECONFIG PREPARE REQUEST message to L1 with RL Id(%ld)\n", 
            pRLPrepReq->rlId));

   fillRadioLinkReconfigPrepRequest (pRLPrepReq);

   if(SUCCESS_E != oct_radiolink_reconfig_prep_req(&gRadioLinkReconfPrepReq))
   {
       DEBUG1(("CL Send Task : Radio Link Reconfig Prepare Request failed for RL Id(%ld)\n",
              pRLPrepReq->rlId));

       retCode = ERROR_RADIO_LINK_RECONFIG_PREP_FAILURE_E;
   }

   /* Free the Memory */
   cleanMemRadioLinkReconfigPrepRequest ();
   free (pRLPrepReq);
   pRLPrepReq = NULL;

   return (retCode);
}

ErrorCode_e oct_radiolink_reconfig_commit_req (L1CAPI_Radiolink_ReconfigCommit *pOctRlReconfigCommitReq)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octRadioLinkReconfigCommitReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
    
    memset( octRadioLinkReconfigCommitReqEncodedBuf, 0, CL_MSG_BUF_SIZE * sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octRadioLinkReconfigCommitReqEncodedBuf);

    pHostDLMsg = pOctRlReconfigCommitReq;
    radiolinkReconfigCommitRequestProcEncHdlr (&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    { 
        retCode = sendToOctL1(&msgStatus,
                              RADIOLINK_RECONFIG_COMMIT_REQUEST,
                              CTRL_NBAP_MSG,
                              octRadioLinkReconfigCommitReqEncodedBuf,
                              transId,0);

        DEBUGMSG(("CL Send Task : RadioLink Reconfig Commit Req is sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Sending Radio Link Reconfig Commit Req to L1 is failed MsgResult %d add0 %d add1 %d\n", 
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));

        retCode = ERROR_RADIO_LINK_RECONFIG_COMMIT_FAILURE_E;
    }

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}

ErrorCode_e buildAndSendRadioLinkReconfigCommitReq (Msg_t msgBuf)
{
   unsigned int *pRlId = NULL;
   ErrorCode_e retCode = SUCCESS_E;

   pRlId = (unsigned int *)msgBuf.msgBuf;
   DEBUGMSG(("CL Send Task : Sending RADIO LINK RECONFIG COMMIT REQUEST message to L1 with RL Id(%ld)\n", 
            *pRlId));

   fillRadioLinkReconfigCommitRequest (pRlId);

   if(SUCCESS_E != oct_radiolink_reconfig_commit_req(&gRadioLinkReconfCommitReq))
   {
       DEBUG1(("CL Send Task : Radio Link Reconfig Commit Request failed for RL Id(%ld)\n",
              *pRlId));

       retCode = ERROR_RADIO_LINK_RECONFIG_COMMIT_FAILURE_E;
   }

   /* Free the Memory */
   if (NULL != pRlId)
   {
       free (pRlId);
       pRlId = NULL;
   }

   return (retCode);
}

ErrorCode_e oct_Dedicated_meas_init_req (L1CAPI_Dedicated_Meas_Init_Request *pOctDedMeasInitReq)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octDedicatedMeasInitReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;

    memset(octDedicatedMeasInitReqEncodedBuf, 0, CL_MSG_BUF_SIZE * sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octDedicatedMeasInitReqEncodedBuf);
    pHostDLMsg = pOctDedMeasInitReq; 

    dedicatedMeasInitRequestProcEncHdlr(&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    {
        retCode = sendToOctL1(&msgStatus,
                              DEDICATED_MEAS_INIT_REQ,
                              CTRL_NBAP_MSG,
                              octDedicatedMeasInitReqEncodedBuf,
                              transId,0);

        DEBUGMSG(("CL Send Task : Dedicated Meas Init Req is sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Sending Dedicated Meas Init Req to L1 is failed MsgResult %d add0 %d add1 %d\n",
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));

         retCode = ERROR_DEDICATED_MEAS_INIT_FAILURE_E;
    }

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}

ErrorCode_e buildAndSendDedicatedMeasInitReq (Msg_t msgBuf)
{
   MeasInfo_t *measInfo = NULL;
   ErrorCode_e retCode = SUCCESS_E;
   measInfo = (MeasInfo_t *)msgBuf.msgBuf;

   fillDedicatedMeasInitRequest(measInfo, 0);

   if(SUCCESS_E != oct_Dedicated_meas_init_req(&gDedicatedMeasInitReq))
   {
       DEBUG1(("CL Send Task : Dedicated MEAS INIT Request failed for RL Id(%ld)\n",
              measInfo->rlId));

       retCode = ERROR_DEDICATED_MEAS_INIT_FAILURE_E;
   }

   /* Free the Memory */
   //cleanMemRadioLinkSetupRequest ();
   if (NULL != gDedicatedMeasInitReq.pRl_ID)
   {
        free (gDedicatedMeasInitReq.pRl_ID);
        gDedicatedMeasInitReq.pRl_ID = NULL;
   }
   free (measInfo);
   measInfo = NULL;
   
   return (retCode);
}

ErrorCode_e buildAndSendOnDemandDchMeasInitReq (Msg_t msgBuf)
{
   MeasInfo_t *measInfo = NULL;
   ErrorCode_e retCode = SUCCESS_E;
   measInfo = (MeasInfo_t *)msgBuf.msgBuf;

   fillDedicatedMeasInitRequest(measInfo, 1);

   if(SUCCESS_E != oct_Dedicated_meas_init_req(&gDedicatedMeasInitReq))
   {
       DEBUG1(("CL Send Task : Dedicated MEAS INIT Request failed for RL Id(%ld)\n",
              measInfo->rlId));

       retCode = ERROR_DEDICATED_MEAS_INIT_FAILURE_E;
   }

   /* Free the Memory */
   //cleanMemRadioLinkSetupRequest ();
   if (NULL != gDedicatedMeasInitReq.pRl_ID)
   {
        free (gDedicatedMeasInitReq.pRl_ID);
        gDedicatedMeasInitReq.pRl_ID = NULL;
   }
   free (measInfo);
   measInfo = NULL;
   
   return (retCode);
}

ErrorCode_e oct_Dedicated_meas_term_req (L1CAPI_Dedicated_Meas_Term_Request *pOctDedMeasTermReq)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octDedicatedMeasTermReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;

    memset(octDedicatedMeasTermReqEncodedBuf, 0, CL_MSG_BUF_SIZE * sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octDedicatedMeasTermReqEncodedBuf);
    pHostDLMsg = pOctDedMeasTermReq;
    dedicatedMeasTermRequestProcEncHdlr(&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    {
        retCode = sendToOctL1(&msgStatus,
                              DEDICATED_MEAS_TERMINATE_REQ,
                              CTRL_NBAP_MSG,
                              octDedicatedMeasTermReqEncodedBuf,
                              transId,0);

        DEBUGMSG(("CL Send Task : Dedicated Meas Term Req is sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Sending Dedicated Meas term Req to L1 is failed MsgResult %d add0 %d add1 %d\n",
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));

        retCode = ERROR_DEDICATED_MEAS_TERM_REQ_FAILURE_E;
    }
    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}


ErrorCode_e buildAndSendDedicatedMeasTermReq (Msg_t msgBuf)
{
   MeasInfo_t *measInfo = NULL;
   ErrorCode_e retCode = SUCCESS_E;
   measInfo = (MeasInfo_t *)msgBuf.msgBuf;

   fillDedicatedMeasTermRequest(measInfo);
   
   if(SUCCESS_E != oct_Dedicated_meas_term_req(&gDedicatedMeasTermReq))
   {
       DEBUG1(("CL Send Task : Dedicated MEAS INIT Request failed for RL Id(%ld)\n",
              measInfo->rlId));

       retCode = ERROR_DEDICATED_MEAS_TERM_REQ_FAILURE_E;
   }

   free (measInfo);
   measInfo = NULL;

   return (retCode);
}


ErrorCode_e oct_radiolink_delete_req (L1CAPI_Radiolink_DeletionRequest *pOctRlDeleteReq)
{
    ErrorCode_e retCode = SUCCESS_E;
    L1CAPI_Msg_Status msgStatus;
    uint32_t octRadioLinkDeleteReqEncodedBuf[CL_MSG_BUF_SIZE];
    uint32_t transId;

    transId = gClCntxt.cPlaneTrnsId;

    msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
    
    memset( octRadioLinkDeleteReqEncodedBuf, 0, CL_MSG_BUF_SIZE * sizeof(uint32_t));
    resetMsgWrite((uint8_t*)octRadioLinkDeleteReqEncodedBuf);

    pHostDLMsg = pOctRlDeleteReq;
    radiolinkDeleteRequestProcEncHdlr (&msgStatus);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    { 
        retCode = sendToOctL1(&msgStatus,
                              RADIOLINK_DELETE_REQUEST,
                              CTRL_NBAP_MSG,
                              octRadioLinkDeleteReqEncodedBuf,
                              transId,0);

        DEBUGMSG(("CL Send Task : RadioLink Delete Req is sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Sending Radio Link Delete Req to L1 is failed MsgResult %d add0 %d add1 %d\n", 
               msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));

         retCode = ERROR_RADIO_LINK_FAILURE_E;
    }

    gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

    cleanMemRadioLinkDeleteRequest ();

    return (retCode);
}

ErrorCode_e buildAndSendRadioLinkDeleteReq (Msg_t msgBuf)
{
   unsigned int *pRlId = NULL;
   ErrorCode_e retCode = SUCCESS_E;

   pRlId = (unsigned int *)msgBuf.msgBuf;
   DEBUGMSG(("CL Send Task : Sending RADIO LINK DELETE REQUEST message to L1 with RL Id(%ld)\n", 
          *pRlId));

   fillRadioLinkDeleteRequest (*pRlId);

   /* Store the Radio Link Delete Transaction Id */
   gClCntxt.clUeCntxt[*pRlId].rlDelTransId = gClCntxt.cPlaneTrnsId;

   if(SUCCESS_E != oct_radiolink_delete_req(&gRadioLinkDeleteReq))
   {
       DEBUG1(("CL Send Task : Radio Link Delete Request failed for RL Id(%ld)\n",
              *pRlId));

       retCode = ERROR_RADIO_LINK_FAILURE_E;
   }

   /* Free the Memory */
   free (pRlId);
   pRlId = NULL;

   return (retCode);
}

ErrorCode_e SendFachDataToL1(U8 *fachDataBuf, U8 cfn, U16 tfi, MacTf_t macTf)
{
    U8                l1RetVal = 0;
    U16               payloadOffset = 0;
    uint32_t          transId;
    static uint8_t    octFachFpData[CL_MSG_BUF_SIZE]; // CL_MSG_BUF_SIZE = 2000 bytes
    ErrorCode_e       retCode = SUCCESS_E;
    L1CAPI_Msg_Status          msgStatus;
    L1CAPI_FP_MSG              fachFpMsg;
    L1CAPI_FP_R4_DATA_MSG_Hdr *fachFpDataR4Hdr;
    
    transId                     = gClCntxt.uPlaneTrnsId;
    msgStatus.l1MsgResult       = L1_MSG_SUCCESS;        
    // TBD: ASSUMING FIRST FACH USED FOR CCCH. check and varify. if not might have to use index 1
    fachFpMsg.bindingId         = gClCntxt.fachL1BindId[0];
    fachFpMsg.fp_msg_type       = L1CAPI_MSG_TYPE_FP_DATA;
    fachFpDataR4Hdr             = &fachFpMsg.u.data.fpDatahdr.r4DataHdr;
    // Encode R4 Hdr info for Fach Data
    fachFpDataR4Hdr->cfn        = cfn+8; // adding 4 to make sure TTI boundy has => cfn%2 or cfn%4 = 0
    fachFpDataR4Hdr->tfi        = tfi; 
    fachFpDataR4Hdr->fachTxPwr  = 0;
    fachFpDataR4Hdr->numTb      = macTf.blockNum; 
    fachFpDataR4Hdr->payloadLen = ((macTf.blockNum) * (macTf.blockSize) + 7) >> 3; // Length in Byte
    fachFpDataR4Hdr->direction  = L1CAPI_DL_DATA_FRAME;  

    memset( octFachFpData, 0, CL_MSG_BUF_SIZE * sizeof(uint8_t));
    resetMsgWrite((uint8_t*)octFachFpData);

    l1RetVal        = fpEncHdlr( &fachFpMsg, FP_FACH_MSG);
    if(l1RetVal == 0){
       DEBUG1(("ERROR: FACH FP DATA ENCODE FAILURE\n"));
       free(fachDataBuf);
    }

    payloadOffset   = findMsgBodySize() + MSG_HDR_SIZE;

    // COPY FP BUFFER TO L1 SEND BUFFER
    memcpy(&octFachFpData[payloadOffset], fachDataBuf, fachFpDataR4Hdr->payloadLen);
    free(fachDataBuf);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    { 
        retCode = sendToOctL1(&msgStatus,
                              FP_FACH_MSG,
                              FP_MSG,
                              octFachFpData,
                              transId,
                              fachFpDataR4Hdr->payloadLen);
        DEBUG4(("CL Send Task : Fach Data sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Fach Data sent to L1 is failed MsgResult %d add0 %d add1 %d\n", 
                    msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));
        retCode = ERROR_RADIO_LINK_FAILURE_E;
    }

    gClCntxt.uPlaneTrnsId = (gClCntxt.uPlaneTrnsId + 1) % 0x8000;

    return (retCode);
} /*End of SendFachDataToL1*/

ErrorCode_e SendDchDataToL1(U16 ueIdx, U8 *dchDataBuf, U8 cfn, U16 tfi, MacTf_t macTf)
{
    U16               i = 0;
    U8                l1RetVal = 0;
    U16               payloadOffset = 0;
    uint32_t          transId;
    static uint8_t    octFachFpData[CL_MSG_BUF_SIZE]; // CL_MSG_BUF_SIZE = 2000 bytes
    ErrorCode_e       retCode = SUCCESS_E;
    L1CAPI_Msg_Status          msgStatus;
    L1CAPI_FP_MSG              dchFpMsg;
    L1CAPI_FP_R4_DATA_MSG_Hdr *dchFpDataR4Hdr;
    
    DEBUG3(("===  CL SendDchDataToL1 Entry: ueIdx(%d), tfi(%d),transId (%d)\n", ueIdx, tfi, gClCntxt.uPlaneTrnsId));
    transId                     = gClCntxt.uPlaneTrnsId;
    msgStatus.l1MsgResult       = L1_MSG_SUCCESS;        
    // TBD: ASSUMING FIRST FACH USED FOR CCCH. check and varify. if not might have to use index 1
    dchFpMsg.bindingId          = gClCntxt.clUeCntxt[ueIdx].bindIdToDchMap[0].bindId; 
    dchFpMsg.fp_msg_type        = L1CAPI_MSG_TYPE_FP_DATA;
    dchFpDataR4Hdr              = &dchFpMsg.u.data.fpDatahdr.r4DataHdr;
    // Encode R4 Hdr info for Fach Data
    dchFpDataR4Hdr->cfn         = cfn+8; // adding 4 to make sure TTI boundy has => cfn%2 or cfn%4 = 0
    dchFpDataR4Hdr->tfi         = tfi; 
    //dchFpDataR4Hdr->fachTxPwr   = 0;
    dchFpDataR4Hdr->numTb       = macTf.blockNum; 
    dchFpDataR4Hdr->payloadLen  = ((macTf.blockNum) * (macTf.blockSize) + 7) >> 3; // Length in Byte
    DEBUG4(("payloadLen(%d), blockNum(%d),blockSize(%d)\n",dchFpDataR4Hdr->payloadLen, macTf.blockNum, macTf.blockSize));
    dchFpDataR4Hdr->direction   = L1CAPI_DL_DATA_FRAME;  

    memset( octFachFpData, 0, CL_MSG_BUF_SIZE * sizeof(uint8_t));
    resetMsgWrite((uint8_t*)octFachFpData);

    l1RetVal        = fpEncHdlr( &dchFpMsg, FP_DCH_MSG);
    if(l1RetVal == 0){
       DEBUG1(("ERROR: FACH FP DATA ENCODE FAILURE\n"));
       free(dchDataBuf);
    }

    payloadOffset   = findMsgBodySize() + MSG_HDR_SIZE;

    // COPY FP BUFFER TO L1 SEND BUFFER
    memcpy(&octFachFpData[payloadOffset], dchDataBuf, dchFpDataR4Hdr->payloadLen);
#if 0
    printf("===============================================================\n");
    printf("=============      CL to L1 DCH Data Buffer  ==================\n");
    printf("===============================================================\n");
    for(i = 0; i < dchFpDataR4Hdr->payloadLen; i++)
    {
       printf("%3x ",octFachFpData[i]);
    }printf("\n");
#endif
    free(dchDataBuf);

    if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
    { 
        retCode = sendToOctL1(&msgStatus,
                              FP_DCH_MSG,
                              FP_MSG,
                              octFachFpData,
                              transId,
                              dchFpDataR4Hdr->payloadLen);
        DEBUG4(("CL Send Task : Dch Data sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Fach Data sent to L1 is failed MsgResult %d add0 %d add1 %d\n", 
                    msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));
        retCode = ERROR_RADIO_LINK_FAILURE_E;
    }

    DEBUG4(("====================== DL DCH Data from CL to L1 TransId(%d)====\n", gClCntxt.uPlaneTrnsId));

    gClCntxt.uPlaneTrnsId = (gClCntxt.uPlaneTrnsId + 1) % 0x8000;

    return (retCode);
} /*End of SendDchDataToL1*/


ErrorCode_e clL1CSndTaskHandleAppRrcMsg (Msg_t msgBuf)
{
   ErrorCode_e retCode = SUCCESS_E;

   switch(msgBuf.msgType)
   {
       case CL_NBAP_UE_RADIO_LINK_SETUP_REQ_E:
          retCode = buildAndSendRadioLinkSetupReq (msgBuf); 
          break;
  
       case CL_NBAP_UE_RADIO_LINK_DELETE_REQ_E:
          retCode = buildAndSendRadioLinkDeleteReq (msgBuf); 
          break;

       case CL_NBAP_UE_RTT_DEDICATED_MEAS_INIT_REQ_E:
       case CL_NBAP_UE_RSCP_DEDICATED_MEAS_INIT_REQ_E:
           retCode = buildAndSendDedicatedMeasInitReq (msgBuf);
           break;

       case CL_NBAP_UE_RTT_DEDICATED_MEAS_TERM_REQ_E:
       case CL_NBAP_UE_RSCP_DEDICATED_MEAS_TERM_REQ_E:     
            retCode = buildAndSendDedicatedMeasTermReq (msgBuf);
            break;

       case CL_NBAP_UE_RTT_ON_DEMAND_MEAS_INIT_REQ_E:
       case CL_NBAP_UE_RSCP_ON_DEMAND_MEAS_INIT_REQ_E:
           retCode = buildAndSendOnDemandDchMeasInitReq(msgBuf);
           break;

       case CL_NBAP_UE_RADIO_LINK_RECONFIG_PREP_REQ_E:
          retCode = buildAndSendRadioLinkReconfigPrepReq (msgBuf); 
          break;

       case CL_NBAP_UE_RADIO_LINK_RECONFIG_COMMIT_REQ_E:
          retCode = buildAndSendRadioLinkReconfigCommitReq (msgBuf); 
          break;

       default:
          DEBUG2(("CL Send Task : Received unknown message type \n"));
          break;
   }

   return (retCode);
}

ErrorCode_e SendPchDataToL1 (unsigned int pcchIdx, unsigned int bfn)
{
    ErrorCode_e       retCode = SUCCESS_E;
    L1CAPI_FP_MSG     fpPchMsg;
    static uint8_t    octPchFpData[CL_MSG_BUF_SIZE]; // CL_MSG_BUF_SIZE = 2000 bytes
    L1CAPI_Msg_Status msgStatus;
    short             l1RetCode = 0;
    U32               payloadOffset = 0; 
    U32               payloadLen = (DEF_PCH_BlockSize[0] + 7) / 8;

    uint32_t transId      = gClCntxt.uPlaneTrnsId;
    msgStatus.l1MsgResult = L1_MSG_SUCCESS;

    L1CAPI_FP_MSG    *pFpPchMsg = &fpPchMsg;

    /* Fill PCH Bind Id */
    pFpPchMsg->bindingId   = gClCntxt.pchL1BindId;

    /* Fill FP Message Type */
    pFpPchMsg->fp_msg_type = L1CAPI_MSG_TYPE_FP_DATA;

    /* Fill PCH Header */
    pFpPchMsg->u.data.fpDatahdr.r4DataHdr.cfn            = ((bfn+8) & 0xFF);
    pFpPchMsg->u.data.fpDatahdr.r4DataHdr.tfi            = 1;
    pFpPchMsg->u.data.fpDatahdr.r4DataHdr.numTb          = 1;
    pFpPchMsg->u.data.fpDatahdr.r4DataHdr.payloadLen     = payloadLen;
    pFpPchMsg->u.data.fpDatahdr.r4DataHdr.direction      = L1CAPI_DL_DATA_FRAME;
    pFpPchMsg->u.data.fpDatahdr.r4DataHdr.u.pichInfo.len = 3;
    memset(&pFpPchMsg->u.data.fpDatahdr.r4DataHdr.u.pichInfo.piBmp, 0xFF, 3);

    memset( octPchFpData, 0, CL_MSG_BUF_SIZE * sizeof(uint8_t));
    resetMsgWrite((uint8_t*)octPchFpData);

    l1RetCode = fpEncHdlr (pFpPchMsg, FP_PCH_MSG);
    if(0 == l1RetCode)
    {
       DEBUG1(("ERROR: PCH FP DATA ENCODE FAILURE\n"));
       retCode = ERROR_GENERIC_FAILURE_E;
    }

    payloadOffset = findMsgBodySize() + MSG_HDR_SIZE;

    // Copy FP buffer to L1 send buffer
    memcpy(&octPchFpData[payloadOffset], gMacPagingContext.pPcchMsg[pcchIdx]->rrcPdu,
           gMacPagingContext.pPcchMsg[pcchIdx]->rrcPduLen);

    retCode = sendToOctL1(&msgStatus, FP_PCH_MSG, FP_MSG, octPchFpData,
                          transId, payloadLen);

    if ((SUCCESS_E == retCode) && (msgStatus.l1MsgResult == L1_MSG_SUCCESS))
    {
        //DEBUGMSG(("CL Send Task : Pch Data sent to L1, Status = %d\n",retCode));
    }
    else
    {
        DEBUG1(("CL Send Task : Sending Pch Data to L1 is failed MsgResult %d add0 %d add1 %d\n", 
                msgStatus.l1MsgResult, msgStatus.additionalInfo0, msgStatus.additionalInfo1));
    }

    gClCntxt.uPlaneTrnsId = (gClCntxt.uPlaneTrnsId + 1) % 0x8000;

    return (retCode);
}

ErrorCode_e oct_cell_reconfig_req (L1CAPI_Cell_Reconfig_Request *pCellReconfigReq)
{
   ErrorCode_e retCode = SUCCESS_E;
   L1CAPI_Msg_Status msgStatus;
   uint32_t octCellReconfigReqEncodedBuf[CL_MSG_BUF_SIZE];
   uint32_t transId;

   transId = gClCntxt.cPlaneTrnsId;

   msgStatus.l1MsgResult = L1_MSG_SUCCESS;        
      
   /* The data needs to be copied to L1 */
   memset( octCellReconfigReqEncodedBuf, 0, (CL_MSG_BUF_SIZE * sizeof(uint32_t)));
   resetMsgWrite((uint8_t*)octCellReconfigReqEncodedBuf);
  
   /*Encode */
   pHostDLMsg = pCellReconfigReq;
   cellReconfigRequestProcEncHdlr(&msgStatus);

   if (msgStatus.l1MsgResult == L1_MSG_SUCCESS)
   {   
       retCode = sendToOctL1(&msgStatus,
                             CELL_RECONFIG_REQUEST,
                             CTRL_NBAP_MSG,
                             octCellReconfigReqEncodedBuf,
                             transId,
                             0);

       gClCntxt.cellState = CL_WAIT_FOR_CELL_RECONFIG_RESP;

       unsigned int *pCellId = (unsigned int *)malloc(sizeof(unsigned int));
       *pCellId = gUmtsConfig.cellId;

       /* Start the Cell Reconfig Timer */
       timerStart(&gClCntxt.cellTimer,
                  CL_CELL_RECONFIG_TIMEOUT,
                  0,
                  handleChgTxAttnCpichTxPwrTimeout,
                  pCellId);     

       DEBUGMSG(("Cell Reconfig Request is sent to L1, Status = %d\n",retCode));
   }
   else
   {
       retCode = ERROR_GENERIC_FAILURE_E;
       DEBUG1(("Sending Cell Reconfig Request to L1 is failed MsgResult %d add0 %d add1 %d\n", msgStatus.l1MsgResult,
        msgStatus.additionalInfo0, msgStatus.additionalInfo1));
   }

   gClCntxt.cPlaneTrnsId = (gClCntxt.cPlaneTrnsId + 1) % 0x8000;

   return (retCode);
}

/*
 *############################################################################
 * Method Name : handleSystemInfoUpdateTimeout
 *
 * Description : This procedure handles System Information Update Timeout. 
 *
 * Parameters  : 
 *   pTimer       Pointer to the CELL timer
 *   pUeIndex     Pointer to the CELL Idx
 *
 * Returns     :  None
 *############################################################################
 */

void handleSystemInfoUpdateTimeout (tcbTimer_t *pTimer, void *pCellIdx)
{
    /* Get Cell Id */
    unsigned int *pCellId = (unsigned int *)pCellIdx;

    DEBUG1(("System Information Update Timeout for Cell Id(%ld)\n", *pCellId));

    /* Send Failure message to external client */
    sendSystemInfoUpdateRsp (0);

    if (NULL != pCellId)
    {
        free (pCellId);
        pCellId = NULL;
    }
}

/*
 *############################################################################
 * Method Name : sendSystemInfoUpdateRsp
 * 
 * Description : This procedure sends system info update Response to 
 *               external client. 
 * 
 * Parameters  : 
 * success     0 Failure 1 Success
 * 
 * Returns     :  None
 *############################################################################
*/

void sendSystemInfoUpdateRsp (unsigned char success)
{
    fxL3gSysInfoConfigRsp sysInfoUpdateRsp;

    /* Send System Info update Response to External Client */
    memset((fxL3gSysInfoConfigRsp *)&sysInfoUpdateRsp, 0,
           sizeof(fxL3gSysInfoConfigRsp));

    sysInfoUpdateRsp.hdr.msgLength = sizeof(sysInfoUpdateRsp);
    sysInfoUpdateRsp.hdr.rat       = FXL_RAT_3G;
    sysInfoUpdateRsp.hdr.msgType   = FXL_3G_SYSINFO_CONFIG_RSP;

    if (1 == success)
    {
        sysInfoUpdateRsp.result = FXL_SUCCESS;
    }
    else
    {
        sysInfoUpdateRsp.result = FXL_FAILURE;
    }

    if (-1 != clientFd)
    {
        if (send(clientFd, &sysInfoUpdateRsp, sizeof(sysInfoUpdateRsp), 0) < 0)
        {
            DEBUG1(("Send System Info update Response is failed\n"));
        }
        else
        {
            DEBUGMSG(("System Info update Response is sent to External Client\n"));
        }
    }
    else
    {
        DEBUG1(("System info update Response is failed, clinetFd = -1\n"));
    }
}

/*
 *############################################################################
 * Method Name : handleChgTxAttnCpichTxPwrTimeout
 *
 * Description : This procedure handles System Information Update & Cell Reconfig
 *               Timeout. 
 *
 * Parameters  : 
 *   pTimer       Pointer to the CELL timer
 *   pUeIndex     Pointer to the CELL Idx
 *
 * Returns     :  None
 *############################################################################
 */
void handleChgTxAttnCpichTxPwrTimeout (tcbTimer_t *pTimer, void *pCellIdx)
{
    /* Get Cell Id */
    unsigned int *pCellId = (unsigned int *)pCellIdx;

    DEBUG1(("System Information Update Timeout for Cell Id(%ld)\n", *pCellId));

    /* Make the Cell State to Active */
    gClCntxt.cellState = CL_CELL_ACTIVE;

    /* Send Failure message to external client */
    sendChgTxAttnCpichTxPwrRsp (0);

    if (NULL != pCellId)
    {
        free (pCellId);
        pCellId = NULL;
    }
}

/*
 *############################################################################
 * Method Name : sendChgTxAttnCpichTxPwrRsp
 *
 * Description : This procedure sends change txAttn & Cpich Tx Pwr Response to 
 *               external client. 
 *
 * Parameters  : 
 *   success     0 Failure 1 Success
 *
 * Returns     :  None
 *############################################################################
 */
void sendChgTxAttnCpichTxPwrRsp (unsigned char success)
{
    fxL3gChgTxAttnCpichTxPwrRsp txAttnCpichTxPwrRsp;

    /* Send Change txAttn & CPICH Tx Pwr Response to External Client */
    memset((fxL3gChgTxAttnCpichTxPwrRsp *)&txAttnCpichTxPwrRsp, 0,
           sizeof(fxL3gChgTxAttnCpichTxPwrRsp));

    txAttnCpichTxPwrRsp.hdr.msgLength = sizeof(fxL3gChgTxAttnCpichTxPwrRsp);
    txAttnCpichTxPwrRsp.hdr.rat       = FXL_RAT_3G;
    txAttnCpichTxPwrRsp.hdr.msgType   = FXL_3G_CHANGE_TX_ATTN_CPICH_TX_PWR_RSP;
 
    if (1 == success)
    {
        txAttnCpichTxPwrRsp.result = FXL_SUCCESS;
    }
    else
    {
        txAttnCpichTxPwrRsp.result = FXL_FAILURE;
    }

    if (-1 != clientFd)
    {
        if (send(clientFd, &txAttnCpichTxPwrRsp, sizeof(txAttnCpichTxPwrRsp), 0) < 0)
        {
            DEBUG1(("Send Change txAttn & CpichTxPwr Response is failed\n"));
        }
        else
        {
	    logPrint(LOG_INFO, "Client Message sent MsgType = %d\n",txAttnCpichTxPwrRsp.hdr.msgType );
            DEBUGMSG(("Change txAttn & CpichTxPwr Response is sent to External Client\n"));
        }
    }
    else
    {
        DEBUG1(("Send Change txAttn & CpcichTxPwr Response is failed, clinetFd = -1\n"));
    }
}
