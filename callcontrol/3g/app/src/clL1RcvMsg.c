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
  * File Name	: clL1RcvMsg.c  
  *
  * Description : This file has interface with L1, all data/control msg are sent
  *               to L1 throught this file
  *
  * History 	:
  *
  * Date		 Author 				 Details
  * ---------------------------------------------------------------------------
  * 12/09/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################ */
 
/* -----------------------------------------------------
 *                 Include Files
 * ----------------------------------------------------- */
#include "stdio.h"
#include "errorCode.h"
#include "l1MsgStatus.h"
#include "msgHeaderDef.h"
#include "l1capi_datastruct.h"
#include "L1C_responseProcDecHdlr.h"
#include "clL1RcvMsg.h"
#include "msgPrimitives.h"
#include "cmnDs.h"
#include "msgHeaderCodec.h"
#include "oct_l1cIoApi.h"
#include "stdlib.h"
#include "msgGetPrimitives.h"
#include "callCSysInfoUpdate.h"
#include "cmnPf.h"
#include "macFpInterface.h"
#include "clContext.h"
#include "timerApi.h"
#include "cmnDebug.h"
#include "rrc.h"

static DbgModule_e  DBG_MODULE = app;
void * pHostUlMsg;
extern ClCntxt_t   gClCntxt;
fxLDspType       dspType;

/*############################################################################
 * Method Name : clCleanRadioLinkSetupResponse
 *
 * Description : This procedure frees all the memory allocated in Heap for 
 *               Radio Link Setup Response decode.
 *
 * Parameters  : 
 *  pRlSetupRsp  Pointer to RL Setup Response Buffer
 *
 * Returns     : None
 ############################################################################*/
void clCleanRadioLinkSetupResponse (L1CAPI_Radiolink_Setup_Response *pRlSetupRsp)
{
   unsigned int i = 0;

   pRlSetupRsp = (L1CAPI_Radiolink_Setup_Response *)pHostUlMsg;

   if ((NULL != pRlSetupRsp) && (NULL != pRlSetupRsp->ptrRlInfoResp))
   {
       for(i = 0; i < pRlSetupRsp->rlCount; i++)
       {
           /* Free the Coord TRCH Response */
           if ((NULL != pRlSetupRsp->ptrRlInfoResp[i].ptrCoordTrchRsp) &&
               (0 != pRlSetupRsp->ptrRlInfoResp[i].coordTrchCount))
           {
               free(pRlSetupRsp->ptrRlInfoResp[i].ptrCoordTrchRsp);
               pRlSetupRsp->ptrRlInfoResp[i].ptrCoordTrchRsp = NULL;
           }

           /* Free the EDCH FDD Info Response */
           if ((0x80 == pRlSetupRsp->ptrRlInfoResp[i].bit_mask) && 
               (NULL != pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp))
           {
               /* Free the EDCH MACD Flow Info Response */
               if ((0 != pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->mAcdFlowCount) && 
                   (NULL != pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp))
               {
                   free(pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp);
                   pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp = NULL;
               }

               /* Free the EDCH FDD Control Channel Info Response */
               if ((0x80 == pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->bit_mask) && 
                   (NULL != pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo))
               {
                   free(pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo);
                   pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo = NULL;
               }

               free(pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp);
               pRlSetupRsp->ptrRlInfoResp[i].ptrEdchFddInfoRsp = NULL;
           }
       }

       /* Free the RL Info Response */
       if (NULL != pRlSetupRsp->ptrRlInfoResp)
       {
          free(pRlSetupRsp->ptrRlInfoResp);
          pRlSetupRsp->ptrRlInfoResp = NULL;
       }

       free(pRlSetupRsp);
       pRlSetupRsp = NULL;
   }
}

/*############################################################################
 * Method Name : clRadioLinkSetupResponseDec
 *
 * Description : This procedure calls the L1 API to decode Radio Link Setup
 *               Response received from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *  pRlSetupRsp  Pointer to RL Setup Response Buffer
 *  pMsgReadPtr  Pointer to message read position
 *
 * Returns     : 
 *  SUCCESS_E                    Success case
 *  ERROR_GENERIC_FAILURE_E      Failure case
 ############################################################################*/
ErrorCode_e clRadioLinkSetupResponseDec (L1MsgStatus_t                   *pMsgStatus, 
                                         L1CAPI_MsgHdr                   *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E; 
    
    /* Start the decoding procedure */
    radiolinkSetupResponseProcDecHdlr (pMsgStatus);
    
    if (L1_MSG_SUCCESS == pMsgStatus->l1MsgResult)
    {
        /* Check message size was correct */
        if (obtainMsgInSize() != pMsgHdr->msgSize+MSG_HDR_SIZE)
        {
            /* Fill-in message status with error notification info */
            pMsgStatus->l1MsgResult = L1_EMSG_MSGHDR;
            pMsgStatus->additionalInfo0 = PARAM_1;
            pMsgStatus->additionalInfo1 = pMsgHdr->msgSize+MSG_HDR_SIZE;

            retCode = ERROR_GENERIC_FAILURE_E;
        }        
    }
    else
    {
        retCode = ERROR_GENERIC_FAILURE_E;
    }

    return (retCode);
}

/*############################################################################
 * Method Name : clDecodeRadioLinkSetupResponse
 *
 * Description : This procedure decodes Radio Link Setup Response received 
 *               from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *  pMsgReadPtr  Pointer to message read position
 *
 * Returns     : 
 *  SUCCESS_E                    Success case
 *  ERROR_GENERIC_FAILURE_E      Failure case
 ############################################################################*/
ErrorCode_e clDecodeRadioLinkSetupResponse (L1MsgStatus_t                   *pMsgStatus, 
                                            L1CAPI_MsgHdr                   *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E; 
    unsigned int *pRlId = NULL;
    U32 bindId = 0;
    L1CAPI_Radiolink_Setup_Response *pRlSetupRsp = NULL;

    retCode = clRadioLinkSetupResponseDec (pMsgStatus, pMsgHdr);
    pRlSetupRsp = (L1CAPI_Radiolink_Setup_Response *) pHostUlMsg;

    if(SUCCESS_E == retCode)
    {
        /* Get the Radio Link Id */
        if (pRlSetupRsp->rlCount > 0)
        {
            pRlId = (unsigned int *)malloc (sizeof(unsigned int));
            *pRlId = pRlSetupRsp->ptrRlInfoResp[0].rL_ID;
            DEBUGMSG(("CL Recv Task : RADIOLINK_SETUP_RESPONSE Received from L1 with RL Id(%ld)\n",
                   *pRlId));

            /* Store NodeB Common Context */
            gClCntxt.clUeCntxt[*pRlId].nodebCmnCntxt = pRlSetupRsp->NodeBComContext;
            gClCntxt.clUeCntxt[*pRlId].numDch        = CL_MAX_DCH_SUPPORT;
            gClCntxt.clUeCntxt[*pRlId].bindIdToDchMap[0].dchId   = pRlSetupRsp->ptrRlInfoResp[0].ptrCoordTrchRsp[0].dchId;
            gClCntxt.clUeCntxt[*pRlId].bindIdToDchMap[0].bindId  = pRlSetupRsp->ptrRlInfoResp[0].ptrCoordTrchRsp[0].binding_id;
            DEBUG3(("CL: clUEContext Update nBCmnCntxt(%d), dchId(%d), bindId(%d)\n",
                   gClCntxt.clUeCntxt[*pRlId].nodebCmnCntxt,
                   gClCntxt.clUeCntxt[*pRlId].bindIdToDchMap[0].dchId, gClCntxt.clUeCntxt[*pRlId].bindIdToDchMap[0].bindId));

            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RADIO_LINK_SETUP_RSP_E, pRlId);
        }
        else
        {
            DEBUG1(("CL Recv Task : **** Wrong Message Received from L1 ****\n"));
            DEBUG1(("CL Recv Task : RADIOLINK_SETUP_RESPONSE Received from L1 with RL Count(%ld)\n",
                   pRlSetupRsp->rlCount));
        }
    }
    else
    {
        DEBUG1(("CL Recv Task : **** Wrong RADIOLINK_SETUP_RESPONSE Received from L1 ****\n"));
    }

    /* Clean all the memory allocated in Decode Method */
    clCleanRadioLinkSetupResponse (pRlSetupRsp);

    return (retCode);
}

/*############################################################################
 * Method Name : clCleanRadioLinkReconfigReady
 *
 * Description : This procedure frees all the memory allocated in Heap for 
 *               Radio Link Reconfig Ready decode.
 *
 * Parameters  : 
 *  pRlSetupRsp  Pointer to RL Setup Response Buffer
 *
 * Returns     : None
 ############################################################################*/
void clCleanRadioLinkReconfigReady (L1CAPI_Radiolink_Reconfigure_Ready *pRlReconfigReady)
{
   unsigned int i = 0;

   pRlReconfigReady = (L1CAPI_Radiolink_Reconfigure_Ready *)pHostUlMsg;

   if ((NULL != pRlReconfigReady) && (NULL != pRlReconfigReady->ptrRlInfoResp))
   {
       for(i = 0; i < pRlReconfigReady->rlCount; i++)
       {
           /* Free the Coord TRCH Response */
           if ((NULL != pRlReconfigReady->ptrRlInfoResp[i].ptrCoordTrchRsp) &&
               (0 != pRlReconfigReady->ptrRlInfoResp[i].coordTrchCount))
           {
               free(pRlReconfigReady->ptrRlInfoResp[i].ptrCoordTrchRsp);
               pRlReconfigReady->ptrRlInfoResp[i].ptrCoordTrchRsp = NULL;
           }

           /* Free the EDCH FDD Info Response */
           if ((0x80 == pRlReconfigReady->ptrRlInfoResp[i].bit_mask) && 
               (NULL != pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp))
           {
               /* Free the EDCH MACD Flow Info Response */
               if ((0 != pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->mAcdFlowCount) && 
                   (NULL != pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp))
               {
                   free(pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp);
                   pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchMacdFlowInfoResp = NULL;
               }

               /* Free the EDCH FDD Control Channel Info Response */
               if ((0x80 == pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->bit_mask) && 
                   (NULL != pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo))
               {
                   free(pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo);
                   pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp->ptrEdchFddCtrlChanInfo = NULL;
               }

               free(pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp);
               pRlReconfigReady->ptrRlInfoResp[i].ptrEdchFddInfoRsp = NULL;
           }
       }

       /* Free the RL Info Response */
       if (NULL != pRlReconfigReady->ptrRlInfoResp)
       {
          free(pRlReconfigReady->ptrRlInfoResp);
          pRlReconfigReady->ptrRlInfoResp = NULL;
       }

       /* Free the HSDSCH Info */
       if ((0x80 == pRlReconfigReady->bit_mask) && (NULL != pRlReconfigReady->ptrHsdschInfoResp))
       {
           if (NULL != pRlReconfigReady->ptrHsdschInfoResp->ptrMacDFlowInfo)
           {
               free (pRlReconfigReady->ptrHsdschInfoResp->ptrMacDFlowInfo);
               pRlReconfigReady->ptrHsdschInfoResp->ptrMacDFlowInfo = NULL;
           }

           if (NULL != pRlReconfigReady->ptrHsdschInfoResp->ptrHsscchInfoResp)
           {
               free (pRlReconfigReady->ptrHsdschInfoResp->ptrHsscchInfoResp);
               pRlReconfigReady->ptrHsdschInfoResp->ptrHsscchInfoResp = NULL;
           }

           free(pRlReconfigReady->ptrHsdschInfoResp);
           pRlReconfigReady->ptrHsdschInfoResp = NULL;
       }

       free(pRlReconfigReady);
       pRlReconfigReady = NULL;
   }
}
/*############################################################################
 * Method Name : clRadioLinkReconfigReadyDec
 *
 * Description : This procedure calls the L1 API to decode Radio Link Reconfig
 *               Ready received from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *
 * Returns     : 
 *  SUCCESS_E                    Success case
 *  ERROR_GENERIC_FAILURE_E      Failure case
 ############################################################################*/
ErrorCode_e clRadioLinkReconfigReadyDec (L1MsgStatus_t                   *pMsgStatus, 
                                         L1CAPI_MsgHdr                   *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E; 
    
    /* Start the decoding procedure */
    radiolinkReconfigReadyProcDecHdlr (pMsgStatus);
    
    if (L1_MSG_SUCCESS == pMsgStatus->l1MsgResult)
    {
        /* Check message size was correct */
        if (obtainMsgInSize() != pMsgHdr->msgSize+MSG_HDR_SIZE)
        {
            /* Fill-in message status with error notification info */
            pMsgStatus->l1MsgResult = L1_EMSG_MSGHDR;
            pMsgStatus->additionalInfo0 = PARAM_1;
            pMsgStatus->additionalInfo1 = pMsgHdr->msgSize+MSG_HDR_SIZE;

            retCode = ERROR_RADIO_LINK_RECONFIG_READY_FAILURE_E;
        }        
    }
    else
    {
        retCode = ERROR_RADIO_LINK_RECONFIG_READY_FAILURE_E;
    }

    return (retCode);
}

/*############################################################################
 * Method Name : clDecodeRadioLinkReconfigReady
 *
 * Description : This procedure decodes Radio Link Reconfig Ready received 
 *               from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *  pMsgReadPtr  Pointer to message read position
 *
 * Returns     : 
 *  SUCCESS_E                    Success case
 *  ERROR_GENERIC_FAILURE_E      Failure case
 ############################################################################*/
ErrorCode_e clDecodeRadioLinkReconfigReady (L1MsgStatus_t                   *pMsgStatus, 
                                            L1CAPI_MsgHdr                   *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E; 
    unsigned int *pRlId = NULL;
    U32 bindId = 0;
    L1CAPI_Radiolink_Reconfigure_Ready *pRlReconfigReady = NULL;

    retCode = clRadioLinkReconfigReadyDec (pMsgStatus, pMsgHdr);
    pRlReconfigReady = (L1CAPI_Radiolink_Reconfigure_Ready *) pHostUlMsg;

    if(SUCCESS_E == retCode)
    {
        /* Get the Radio Link Id */
        if (pRlReconfigReady->rlCount > 0)
        {
            pRlId = (unsigned int *)malloc (sizeof(unsigned int));
            *pRlId = pRlReconfigReady->ptrRlInfoResp[0].rL_ID;
            DEBUGMSG(("CL Recv Task : RADIOLINK_RECONFIG_READY Received from L1 with RL Id(%ld)\n",
                   *pRlId));

            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RADIO_LINK_RECONFIG_READY_E, pRlId);
        }
        else
        {
            DEBUG1(("CL Recv Task : **** Wrong Message Received from L1 ****\n"));
            DEBUG1(("CL Recv Task : RADIOLINK_RECONFIG_READY Received from L1 with RL Count(%ld)\n",
                   pRlReconfigReady->rlCount));
        }
    }
    else
    {
        DEBUG1(("CL Recv Task : **** Wrong RADIOLINK_RECONFIG_READY Received from L1 ****\n"));
    }

    /* Clean all the memory allocated in Decode Method */
    clCleanRadioLinkReconfigReady (pRlReconfigReady);

    return (retCode);
}

/* ############################################################################
 *  Method Name : clDedicatedMeasInitResponseDec
 *     
 *  Description : This procedure calls the L1 API to decode Dedicated Meas Init
 *                Response received from L1.
 *         
 *  Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *             
 *  Returns     : 
 *  SUCCESS_E                    Success case
 *  ERROR_GENERIC_FAILURE_E      Failure case
 * ############################################################################
 */

ErrorCode_e clDedicatedMeasInitResponseDec (L1MsgStatus_t                       *pMsgStatus,
                                            L1CAPI_MsgHdr                       *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E;

    /* Start the decoding procedure */
    dedicatedMeasInitResponseProcDecHdlr (pMsgStatus);

    if (L1_MSG_SUCCESS == pMsgStatus->l1MsgResult)
    {
        /* Check message size was correct */
        if (obtainMsgInSize() != pMsgHdr->msgSize+MSG_HDR_SIZE)
        {
            /* Fill-in message status with error notification info */
            pMsgStatus->l1MsgResult = L1_EMSG_MSGHDR;
            pMsgStatus->additionalInfo0 = PARAM_1;
            pMsgStatus->additionalInfo1 = pMsgHdr->msgSize+MSG_HDR_SIZE;

            retCode = ERROR_DEDICATED_MEAS_INIT_RSP_FAILURE_E;
        }
    }
    else
    {
        retCode = ERROR_DEDICATED_MEAS_INIT_RSP_FAILURE_E;
    }

    return (retCode);
}

/* ############################################################################
 * Method Name : clDecodeDedicatedMeasInitResponse
 *      
 * Description : This procedure decodes Dedicated Measurement Init Response 
 *               received from L1.
 *        
 * Parameters  : 
 * pMsgStatus   Pointer to message status
 * pMsgHdr      Pointer to message header
 *              
 * Returns     : 
 * SUCCESS_E                    Success case
 * ERROR_GENERIC_FAILURE_E      Failure case
 * ############################################################################
 */

ErrorCode_e clDecodeDedicatedMeasInitResponse (L1MsgStatus_t                   *pMsgStatus,
                                               L1CAPI_MsgHdr                   *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E;
    unsigned int *pRlId = NULL;
	UeDedicatedMeasReport *pDedMeasRep = NULL;
    L1CAPI_Dedicated_Meas_Init_Response *pDedMeasInitRsp = NULL;

    retCode = clDedicatedMeasInitResponseDec (pMsgStatus, pMsgHdr);
    pDedMeasInitRsp =(L1CAPI_Dedicated_Meas_Init_Response *) pHostUlMsg;

    if(SUCCESS_E == retCode)
    {
      /* Get the Radio Link Id */
      if (pDedMeasInitRsp->rlCount > 0)
      {
		  pDedMeasRep = (UeDedicatedMeasReport *)malloc(sizeof(UeDedicatedMeasReport));
		  memset((UeDedicatedMeasReport *)pDedMeasRep, 0, sizeof(UeDedicatedMeasReport));

          pDedMeasRep->rlId = pDedMeasInitRsp->pRLInf[0].rL_ID;

          DEBUGMSG(("CL Recv Task : DEDICATED_MEAS_INIT_RESPONSE Received from L1 with RL Id(%ld)\n",
                    pDedMeasRep->rlId));
          if ((pDedMeasRep->rlId * MAX_NUMBER_OF_MEASUREMENT) == pDedMeasInitRsp->measureID)
          { 
             pDedMeasRep->rttValue = pDedMeasInitRsp->pRLInf[0].measInf.measValue;
             SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RTT_DEDICATED_MEAS_INIT_RSP_E, pDedMeasRep);
          }
          else if (((pDedMeasRep->rlId * MAX_NUMBER_OF_MEASUREMENT) + 1) == pDedMeasInitRsp->measureID)
          {
             pDedMeasRep->rscpValue = pDedMeasInitRsp->pRLInf[0].measInf.measValue;
             SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RSCP_DEDICATED_MEAS_INIT_RSP_E, pDedMeasRep);
          }
          else
          {
             // Nothing 
          }
      }
      else
      {
         DEBUG1(("CL Recv Task : **** Wrong Message Received from L1 ****\n"));
         DEBUG1(("CL Recv Task : DEDICATED_MEAS_INIT_RESPONSE Received from L1 with RL Count(%ld)\n",
                 pDedMeasInitRsp->rlCount));
      }
    }
    else
    {
       DEBUG1(("CL Recv Task : **** DEDICATED MEAS INIT RESPONSE FAILURE Received from L1 ****\n"));
    }

    /* Free the memory allocated for decode */
    if ((0 != pDedMeasInitRsp->rlCount) &&
        (NULL != pDedMeasInitRsp->pRLInf))
    {
        free(pDedMeasInitRsp->pRLInf);
        pDedMeasInitRsp->pRLInf = NULL;
    }

    if((0 != pDedMeasInitRsp->rlsCount) &&
       (NULL != pDedMeasInitRsp->pRLSInf))
    {
        free (pDedMeasInitRsp->pRLSInf);
        pDedMeasInitRsp->pRLSInf = NULL;
    }

    if (NULL != pDedMeasInitRsp)
    {
        free(pDedMeasInitRsp);
        pDedMeasInitRsp = NULL;
    }

    return (retCode);
}

/* ############################################################################
 * Method Name : clDedicatedMeasReportDec
 *        
 * Description : This procedure calls the L1 API to decode Dedicated Meas Report
 *               received from L1.
 *               
 * Parameters  : 
 * pMsgStatus    Pointer to message status
 * pMsgHdr       Pointer to message header
 *                       
 * Returns     : 
 * SUCCESS_E                    Success case
 * ERROR_GENERIC_FAILURE_E      Failure case
 * ############################################################################
 */

ErrorCode_e clDedicatedMeasReportDec (L1MsgStatus_t                       *pMsgStatus,
                                      L1CAPI_MsgHdr                       *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E;

    /* Start the decoding procedure */
    dedicatedMeasReportProcDecHdlr (pMsgStatus);

    if (L1_MSG_SUCCESS == pMsgStatus->l1MsgResult)
    {
        /* Check message size was correct */
        if (obtainMsgInSize() != pMsgHdr->msgSize+MSG_HDR_SIZE)
        {
            /* Fill-in message status with error notification info */
            pMsgStatus->l1MsgResult = L1_EMSG_MSGHDR;
            pMsgStatus->additionalInfo0 = PARAM_1;
            pMsgStatus->additionalInfo1 = pMsgHdr->msgSize+MSG_HDR_SIZE;

            retCode = ERROR_DEDICATED_MEAS_REPORT_FAILURE_E;
        }
    }
    else
    {
        retCode = ERROR_DEDICATED_MEAS_REPORT_FAILURE_E;
    }

    return (retCode);
}

/*############################################################################
 * Method Name : clDecodeDedicatedMeasReport
 *         
 * Description : This procedure decodes Dedicated Measurement Report 
 *               received from L1.
 *              
 * Parameters  : 
 * pMsgStatus    Pointer to message status
 * pMsgHdr       Pointer to message header
 *                        
 * Returns     : 
 * SUCCESS_E                    Success case
 * ERROR_GENERIC_FAILURE_E      Failure case
 *############################################################################
 */
ErrorCode_e clDecodeDedicatedMeasReport (L1MsgStatus_t                   *pMsgStatus,
                                         L1CAPI_MsgHdr                   *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E;
    UeDedicatedMeasReport *pDedMeasRep = NULL;
    L1CAPI_Dedicated_Meas_Report *pDedMeasReport = NULL;

    retCode = clDedicatedMeasReportDec (pMsgStatus, pMsgHdr);
    pDedMeasReport =(L1CAPI_Dedicated_Meas_Report *) pHostUlMsg;

    if(SUCCESS_E == retCode)
    {
      /* Get the Radio Link Id */
      if (pDedMeasReport->rlCount > 0)
      {
         pDedMeasRep = (UeDedicatedMeasReport *)malloc(sizeof(UeDedicatedMeasReport));
		 memset((UeDedicatedMeasReport *)pDedMeasRep, 0, sizeof(UeDedicatedMeasReport));
		 
         pDedMeasRep->rlId = pDedMeasReport->pRLInf[0].rL_ID;

         DEBUGMSG(("CL Recv Task : DEDICATED_MEAS_REPORT Received from L1 with RL Id(%ld)\n",
                    pDedMeasRep->rlId));
         if ((pDedMeasReport->pRLInf[0].rL_ID * MAX_NUMBER_OF_MEASUREMENT) == pDedMeasReport->measureID)
         {
            pDedMeasRep->rttValue = pDedMeasReport->pRLInf[0].measInf.measValue;
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RTT_DEDICATED_MEAS_REPORT_E, pDedMeasRep);
         }
         else if (((pDedMeasReport->pRLInf[0].rL_ID * MAX_NUMBER_OF_MEASUREMENT) + 1) == pDedMeasReport->measureID)
         {
            pDedMeasRep->rscpValue = pDedMeasReport->pRLInf[0].measInf.measValue;
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RSCP_DEDICATED_MEAS_REPORT_E, pDedMeasRep);
         }
         else
         {
             // Nothing 
         }
       }
       else
       {
           DEBUG1(("CL Recv Task : **** Wrong Message Received from L1 ****\n"));
           DEBUG1(("CL Recv Task : DEDICATED_MEAS_REPORT Received from L1 with RL Count(%ld)\n",
                    pDedMeasReport->rlCount));
       }
    }
    else
    {
         DEBUG1(("CL Recv Task : **** DEDICATED MEAS REPORT FAILURE Received from L1 ****\n"));
    }

    /* Free the memory allocated for decode */
    if ((0 != pDedMeasReport->rlCount) &&
        (NULL != pDedMeasReport->pRLInf))
    {
        free(pDedMeasReport->pRLInf);
        pDedMeasReport->pRLInf = NULL;
    }

    if((0 != pDedMeasReport->rlsCount) &&
       (NULL != pDedMeasReport->pRLSInf))
    {
        free (pDedMeasReport->pRLSInf);
        pDedMeasReport->pRLSInf = NULL;
    }

    if (NULL != pDedMeasReport)
    {
        free(pDedMeasReport);
        pDedMeasReport = NULL;
    }

    return (retCode);
}

/*############################################################################
 * Method Name : clCleanRadioLinkFailureIndication
 *
 * Description : This procedure frees all the memory allocated in Heap for 
 *               Radio Link Failure Indication decode.
 *
 * Parameters  : 
 *  pRlFailInd   Pointer to RL Failure Indication Buffer
 *
 * Returns     : None
 ############################################################################*/
void clCleanRadioLinkFailureIndication (L1CAPI_Radiolink_Failure_Ind *pRlFailInd)
{
   pRlFailInd = (L1CAPI_Radiolink_Failure_Ind *)pHostUlMsg;

   if (NULL != pRlFailInd)
   {
      if ((0 != pRlFailInd->rlCount) && (NULL != pRlFailInd->pRlFailInf))
      {
          free(pRlFailInd->pRlFailInf);
          pRlFailInd->pRlFailInf = NULL;
      }

      if ((0 != pRlFailInd->rlsCount) && (NULL != pRlFailInd->pRlsFailInf))
      {
          free(pRlFailInd->pRlsFailInf);
          pRlFailInd->pRlsFailInf = NULL;
      }

      free(pRlFailInd);
      pRlFailInd = NULL;
   }
}

/*############################################################################
 * Method Name : clRadioLinkFailureIndicationDec
 *
 * Description : This procedure calls the L1 API to decode Radio Link Failure
 *               Indication received from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *  pRlFailInd   Pointer to RL Failure Indication Buffer
 *  pMsgReadPtr  Pointer to message read position
 *
 * Returns     : 
 *  SUCCESS_E                    Success case
 *  ERROR_GENERIC_FAILURE_E      Failure case
 ############################################################################*/
ErrorCode_e clRadioLinkFailureIndicationDec (L1MsgStatus_t                *pMsgStatus, 
                                             L1CAPI_MsgHdr                *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E;
    
    /* Start the decoding procedure */
    radiolinkFailureIndicationProcDecHdlr (pMsgStatus);
    
    if (L1_MSG_SUCCESS == pMsgStatus->l1MsgResult)
    {
        /* Check message size was correct */
        if (obtainMsgInSize() != pMsgHdr->msgSize + MSG_HDR_SIZE)
        {
            /* Fill-in message status with error notification info */
            pMsgStatus->l1MsgResult     = L1_EMSG_MSGHDR;
            pMsgStatus->additionalInfo0 = PARAM_1;
            pMsgStatus->additionalInfo1 = pMsgHdr->msgSize+MSG_HDR_SIZE;

            retCode = ERROR_GENERIC_FAILURE_E;
        }        
    }
    else
    {
        retCode = ERROR_GENERIC_FAILURE_E;
    }

    return (retCode);
}

/*############################################################################
 * Method Name : clDecodeRadioLinkFailureIndication
 *
 * Description : This procedure decodes Radio Link Failure Indication received 
 *               from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *  pMsgReadPtr  Pointer to message read position
 *
 * Returns     : 
 *  SUCCESS_E                    Success case
 *  ERROR_GENERIC_FAILURE_E      Failure case
 ############################################################################*/
ErrorCode_e clDecodeRadioLinkFailureIndication (L1MsgStatus_t                   *pMsgStatus, 
                                                L1CAPI_MsgHdr                   *pMsgHdr)
{
    L1CAPI_Radiolink_Failure_Ind *pRlFailInd = NULL;
    ErrorCode_e retCode = SUCCESS_E; 
    unsigned int *pRlId = NULL;

    retCode = clRadioLinkFailureIndicationDec (pMsgStatus, pMsgHdr);
    pRlFailInd  = (L1CAPI_Radiolink_Failure_Ind *) pHostUlMsg;

    if(SUCCESS_E == retCode)
    {
        /* Get the Radio Link Id */
        if (pRlFailInd->rlCount > 0)
        {
            pRlId = (unsigned int *)malloc (sizeof(unsigned int));
            *pRlId = pRlFailInd->pRlFailInf[0].rL_ID;
            DEBUG1(("CL Recv Task : RADIOLINK_FAILURE_INDICATION Received with RL Id(%ld) & Cause(%ld)\n",
                   *pRlId, pRlFailInd->pRlFailInf[0].cause));

            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RADIO_LINK_FAILURE_E, pRlId);
        }
        else
        {
            DEBUG1(("CL Recv Task : **** Wrong Message Received from L1 ****\n"));
            DEBUG1(("CL Recv Task : RADIOLINK_FAILURE_INDICATION Received from L1 with RL Count(%ld)\n",
                   pRlFailInd->rlCount));
        }
    }
    else
    {
        DEBUG1(("CL Recv Task : **** Wrong RADIOLINK_FAILURE_INDICATION Received from L1 ****\n"));
    }

    /* Clean all the memory allocated in Decode Method */
    clCleanRadioLinkFailureIndication (pRlFailInd);
 //   free (pRlFailInd);
//    pRlFailInd = NULL;

    return (retCode);
}

/*############################################################################
 * Method Name : clGenericResponseDec
 *
 * Description : This procedure decodes Generic Response received from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *
 * Returns     : 
 *  ROK          Success case
 *  RFAILED      Failure case
 ############################################################################ */
ErrorCode_e clGenericResponseDec (L1MsgStatus_t           *msgStatus, 
                                 L1CAPI_MsgHdr           *pMsgHdr)
{
    ErrorCode_e retCode = SUCCESS_E; 
    ProcedureStatus_e procedureStatus;
    
    /* Start the decoding procedure */
    genericResponseProcDecHdlr (msgStatus);
    
    if (L1_MSG_SUCCESS == msgStatus->l1MsgResult)
    {
        /* Decoding procedure successful so far, commit is the next step */
        procedureStatus = PROC_COMMIT;        

        /* Check message size was correct */
        if (obtainMsgInSize() != pMsgHdr->msgSize+MSG_HDR_SIZE)
        {
            /* Fill-in message status with error notification info */
            msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
            msgStatus->additionalInfo0 = PARAM_1;
            msgStatus->additionalInfo1 = pMsgHdr->msgSize+MSG_HDR_SIZE;

            /* Cancel decoding procedure */
            procedureStatus = PROC_CANCEL;
            retCode = ERROR_GENERIC_FAILURE_E;
        }        
    }
    else
    {
        
        /* Error detected, cancel procedure */
        procedureStatus = PROC_CANCEL;
        retCode = ERROR_GENERIC_FAILURE_E;
    }

    /* Continue with decoding procedure */
    genericResponseProcDecCommit (procedureStatus);

    return (retCode);
}

/*############################################################################
 * Method Name : clSccpchResponseDec
 *
 * Description : This procedure decodes Generic Response received from L1.
 *
 * Parameters  : 
 *  pMsgStatus   Pointer to message status
 *  pMsgHdr      Pointer to message header
 *
 * Returns     : 
 *  ROK          Success case
 *  RFAILED      Failure case
 ############################################################################ */
ErrorCode_e clSccpchResponseDec( L1MsgStatus_t           *msgStatus, 
                                 L1CAPI_MsgHdr           *pMsgHdr,
                                 L1CAPI_Sccpch_Setup_Response* pL1CSccpchRsp)
{
    ErrorCode_e retCode = SUCCESS_E; 
    
    /* Sccpch Response L1 Decoding*/
    cmnTrchSccpchSetupResponseProcDecHdlr(msgStatus);
    pL1CSccpchRsp = (L1CAPI_Sccpch_Setup_Response *) pHostUlMsg; 
    gClCntxt.fachL1BindId[0] = pL1CSccpchRsp->ptrFACH_binding_id[0];
    gClCntxt.fachL1BindId[1] = pL1CSccpchRsp->ptrFACH_binding_id[1];
    gClCntxt.pchL1BindId =  pL1CSccpchRsp->pCH_binding_id;

    DEBUGMSG(("CL:== clSccpchResponseDec fachL1BindId(%ld), pchL1BindId(%d)\n", gClCntxt.fachL1BindId, gClCntxt.pchL1BindId));
    
    if (L1_MSG_SUCCESS == msgStatus->l1MsgResult)
    {
        /* Check message size was correct */
        if (obtainMsgInSize() != pMsgHdr->msgSize+MSG_HDR_SIZE)
        {
            /* Fill-in message status with error notification info */
            msgStatus->l1MsgResult = L1_EMSG_MSGHDR;
            msgStatus->additionalInfo0 = PARAM_1;
            msgStatus->additionalInfo1 = pMsgHdr->msgSize+MSG_HDR_SIZE;

            /* Cancel decoding procedure */
            retCode = ERROR_L1_DECODE_FAIL_E;
        }        
    }
    else
    {
        /* Error detected, cancel procedure */
        retCode = ERROR_L1_DECODE_FAIL_E;
    }

    return (retCode);
}

/*############################################################################
 * Method Name : clFwdDchDataInd
 *
 * Description : This procedure Converts RACH Data indication received from L1 to 
 *               MAC format and send RachDataInd Msg to L2.
 * Parameters  : 
 *  pMsgHdr       Pointer to header of the message
 *  Returns: 
 *  ROK           Success case
 *  RFAILED       Failure case
 ############################################################################ */
ErrorCode_e clFwdDchDataInd(U8                     *pRcvdRachData,
                        S16                         ueIdx,
                        L1CAPI_MsgHdr              *pMsgHdr,
                        L1CAPI_FP_R4_DATA_MSG_Hdr  *octFpDataHdr)
{
    MacUlDataInd_t  *dchDataInd;
    U16             i = 0;
    ErrorCode_e     retCode; 

    dchDataInd              = (MacUlDataInd_t *) allocMem_DchDataInd(pMsgHdr->msgSize + 1 + sizeof(MacUlDataInd_t)/*OFFSET: TBD Check if needed*/);
    dchDataInd->ueIdx       = ueIdx + UE_IDX_OFFSET_L2; // MAC/RLC(L2) UeIdx starting from 0 while L1/L3 starting from 0
    dchDataInd->cfn         = octFpDataHdr->cfn;
    dchDataInd->tfi         = octFpDataHdr->tfi;
    dchDataInd->propDelay   = octFpDataHdr->propagationDelay;
    dchDataInd->numTb       = octFpDataHdr->numTb;
    /*This Param used for pointer access MAX val. Read content based on TbSize configured for RACH*/
    dchDataInd->dataLen     = pMsgHdr->msgSize + 1; 
    
    for(i = 0; i < dchDataInd->numTb; i++){
       dchDataInd->crci[i]    = octFpDataHdr->u.ulTrchCommon.crci[i];
       if(dchDataInd->crci[i] == TRUE_E)
       {
          retCode = ERROR_L2_DCH_DATA_CRC_ERROR_E;
          free(dchDataInd);
          DEBUG4((COLOR_TXT_RED "ERROR: CRC Error in DCH TB, Dropping in CL\n" COLOR_TXT_RST ));
          return retCode;
       }
    }

    // TBD: TEST THIS, POSSIBLY THIS COULD CAUSE ERROR / FAILURE / CRASH
    memcpy(dchDataInd->ulDataBuf, pRcvdRachData, pMsgHdr->msgSize); 

    DEBUG3(("CL: ===== Forwarding UL Dch_Data_Indication to L2\n"));
    SendMsgToTask(CL_L1C_RCV_TASK_E, L2_UL_DATA_TASK_E, CL_L2_UL_DCH_DATA_IND, dchDataInd);

    return SUCCESS_E;
} /*End of clFwdDchDataInd*/

/*############################################################################
 * Method Name : clFwdRachDataInd
 *
 * Description : This procedure Converts RACH Data indication received from L1 to 
 *               MAC format and send RachDataInd Msg to L2.
 * Parameters  : 
 *  pMsgHdr       Pointer to header of the message
 *  Returns: 
 *  ROK           Success case
 *  RFAILED       Failure case
 ############################################################################ */
ErrorCode_e clFwdRachDataInd(U8           *pRcvdRachData,
                             L1CAPI_MsgHdr    *pMsgHdr,
                             L1CAPI_FP_R4_DATA_MSG_Hdr  *octFpDataHdr)
{
    MacUlDataInd_t  *rachDataInd;
    U16             i = 0;
    ErrorCode_e     retCode; 

    //rachDataInd  = allocMem_RachDataInd(pMsgHdr->msgSize + 1 + sizeof(MacUlDataHdr_t)/*OFFSET: TBD Check if needed*/);
    rachDataInd             = (MacUlDataInd_t *) allocMem_RachDataInd(pMsgHdr->msgSize + 1 + sizeof(MacUlDataInd_t)/*OFFSET: TBD Check if needed*/);

    //TBD: fpUlData.bindingId Not using for now need to add handling in future.
    //Currently using msgType to identify RACH
    rachDataInd->cfn         = octFpDataHdr->cfn;
    rachDataInd->tfi         = octFpDataHdr->tfi;
    rachDataInd->propDelay   = octFpDataHdr->propagationDelay;
    rachDataInd->numTb       = octFpDataHdr->numTb;
    /*This Param used for pointer access MAX val. Read content based on TbSize configured for RACH*/
    rachDataInd->dataLen     = pMsgHdr->msgSize + 1; 

    for(i = 0; i < rachDataInd->numTb; i++)
	{
       rachDataInd->crci[i]    = octFpDataHdr->u.ulTrchCommon.crci[i];
       if(rachDataInd->crci[i] == TRUE_E)
       {
          retCode = ERROR_L2_RACH_DATA_CRC_ERROR_E;
          free(rachDataInd);
          DEBUG4((COLOR_TXT_RED "ERROR: CRC Error in RACH TB, Dropping in CL\n" COLOR_TXT_RST ));
          return retCode;
       }
    }

    // TBD: TEST THIS, POSSIBLY THIS COULD CAUSE ERROR / FAILURE / CRASH
    memcpy(rachDataInd->ulDataBuf, pRcvdRachData, pMsgHdr->msgSize); 

    DEBUG3(("CL: ===== Forwarding Rach_Data_Indication to L2\n"));
    SendMsgToTask(CL_L1C_RCV_TASK_E, L2_UL_DATA_TASK_E, CL_L2_UL_RACH_DATA_IND, rachDataInd);

    return SUCCESS_E;
} /*End of clFwdRachDataInd */

S16 getUeIndexFromBindId (U32 bindingId)
{
   S16 retCode = INVALID_BIND_ID;
   S16 idx = 0;

   DEBUG3(("CL:  Get UeIdx for BindID(%lu)\n", bindingId));
   for (idx =0; idx < CL_MAX_UE_SUPPORTED; idx++)
   {
      if(gClCntxt.clUeCntxt[idx].bindIdToDchMap[0].bindId == bindingId)
      {
          retCode = idx;
          break;
      }
   }

   return (retCode);
} /* End of getUeIndexFromBindId */

S16 getUeIndexFromRLDelTransId (unsigned short transId)
{
   S16 retCode = INVALID_RL_TRANSACTION_ID;
   S16 idx = 0;

   for (idx =0; idx < CL_MAX_UE_SUPPORTED; idx++)
   {
      if(gClCntxt.clUeCntxt[idx].rlDelTransId == transId)
      {
          retCode = idx;
      }
   }

   return (retCode);
}

S16 getMeasIdFromDedTermReqTransId (unsigned short transId)
{
   S16 retCode = INVALID_MEAS_TRANSACTION_ID;
   S16 idx = 0;      
   
   for (idx =0; idx < CL_MAX_UE_SUPPORTED; idx++)
   {
      if(gClCntxt.clUeCntxt[idx].DedRttMeasTermTransId == transId)
      {  
          retCode = (idx * MAX_NUMBER_OF_MEASUREMENT);
      }
      else if (gClCntxt.clUeCntxt[idx].DedRscpMeasTermTransId == transId)
      {
         retCode = ((idx * MAX_NUMBER_OF_MEASUREMENT)+1);
      }
      else
      {
         //Nothing
      }
   }
   
   return (retCode);
}

/*############################################################################
 * Method Name : clRecvL1GenericRsp
 *
 * Description : This procedure handles generic response from L1.
 *
 * Parameters  : 
 *  pMsgHdr       Pointer to header of the message
 * Returns     : 
 *  ROK           Success case
 *  RFAILED       Failure case
 ############################################################################*/
ErrorCode_e clRecvL1GenericRsp (L1CAPI_Generic_Response * pL1CGenRsp,
                               L1CAPI_MsgHdr *pMsgHdr)
{
   ErrorCode_e retCode = SUCCESS_E;

   if(L1_MSG_SUCCESS != pL1CGenRsp->msgStatus.l1MsgResult)
   {
       DEBUG1(("Generic Reponse Failure additionalInfo0 %u additionalInfo1 %u\n", 
              pL1CGenRsp->msgStatus.additionalInfo0, 
              pL1CGenRsp->msgStatus.additionalInfo1));
   }

   switch(pL1CGenRsp->associatedMsg)
   {
        case CELL_SETUP_REQUEST:
            DEBUGMSG((" CELL_SETUP_REQUEST Generic Response Received from L1\n"));
            //sleep(2);
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_CELL_SETUP_RSP_E, NULL);
	    break;

        case SYSTEM_INFO_UPDATE_REQUEST:
            DEBUGMSG((" SYSTEM_INFO_UPDATE Generic Response Received from L1\n"));
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_SYSTEM_INFO_UPDATE_RSP_E, NULL);
	    break;

        case RADIOLINK_DELETE_REQUEST:
            DEBUGMSG((" RADIOLINK_DELETE_REQUEST Generic Response Received. Send To RRC_APP TASK\n"));
            /* Get the UE Id from Radio Link Delete Request Transaction Id */
            unsigned int ueIndex = getUeIndexFromRLDelTransId (pMsgHdr->transactionId);
            if (INVALID_RL_TRANSACTION_ID != ueIndex)
            {
                /* Post the Radio Link Delete Response to APP RRC Task */
                unsigned int *pUeId = (unsigned int *)malloc(sizeof(unsigned int));
                *pUeId = ueIndex;

                SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RADIO_LINK_DELETE_RSP_E, pUeId);
            }
            else
            {
                DEBUG1(("CL RCV TASK : Could not find UE Index for which RL Delete Received\n"));
            }
	    break;

        case MODEM_SETUP_REQUEST:
            //ADD MODEM SETUP RESPONSE HANDLER
            DEBUGMSG(("MODEM_SETUP_REQUEST Generic Response Received. Send To RRC_APP TASK\n"));
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_MODEM_SETUP_RSP_MSG_E, NULL);
            break;

        case CELL_DELETE_REQUEST:
            DEBUGMSG((" CELL DELETE_REQUEST Generic Response Received from L1\n"));
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_CELL_DELETE_RSP_E, NULL);
            break;

        case CELL_RECONFIG_REQUEST:
            DEBUGMSG((" CELL RECONFIG REQUEST Generic Response Received from L1\n"));
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_CELL_RECONFIG_RSP_E, NULL);
            break;


        case DEDICATED_MEAS_TERMINATE_REQ:
            DEBUGMSG((" DEDICATED MEAS TERMINATE REQ Generic Response Received from L1\n"));
            /* Get the Maesurement ID from DEDICATED_MEAS_TERMINATE_REQ Transaction Id */
             unsigned int measId = getMeasIdFromDedTermReqTransId (pMsgHdr->transactionId);
             if (INVALID_MEAS_TRANSACTION_ID != measId)
             {
                /* Post the Dedicated Meas Terminate Response to APP RRC Task */
                unsigned int *pUeId = (unsigned int *)malloc(sizeof(unsigned int));
                *pUeId = (measId/MAX_NUMBER_OF_MEASUREMENT);

                if ((measId % MAX_NUMBER_OF_MEASUREMENT) == 0)
                {
                   SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RTT_DEDICATED_MEAS_TERM_RSP_E, pUeId);
                }
                else
                {
                   SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_UE_RSCP_DEDICATED_MEAS_TERM_RSP_E, pUeId);
                }
             }
             break;

        case RADIOLINK_RECONFIG_COMMIT_REQUEST:
            DEBUGMSG((" RADIO LINK RECONFIG COMMIT Generic Response Received from L1\n"));
            break;

        default:
           DEBUG2(("Unknown Generic Response (%d)\n", pL1CGenRsp->associatedMsg));
           retCode = ERROR_GENERIC_FAILURE_E;
           break; 
   }
   DEBUGMSG(("L1 Generic Response Received\n"));

   return (retCode);
}

/*############################################################################
 * Method Name : clDecodeProcFpData
 *
 * Description : This procedure decodes and Hanldes FP(UL) DATA received from L1.
 *
 * Parameters    : 
 * pMsgStatus   Pointer to message Buffer
 * pMsgHdr      Pointer to message header
 * pMsgReadPtr  Pointer to read the circular buffer
 *
 * Returns     :       None
 ############################################################################ */
static ErrorCode_e clDecodeProcFpData(U8      *pCll1RecvBuf,
                              L1CAPI_MsgHdr   *pMsgHdr)
{
    ErrorCode_e      retCode;
    L1CAPI_FP_MSG    fpUlData;
    U16              fpDataOffset = 0;
    S16              ueIdx  = 0;

    if(!fpDecHdlr(&fpUlData,pMsgHdr->msgId))
    {       
       DEBUG1(("Error In Decoding UL FP data\n"));
       return ERROR_L1_DATA_READ_FAIL_E;
    }
    else if(fpUlData.fp_msg_type  != L1CAPI_MSG_TYPE_FP_DATA)
    {
       DEBUG1(("NOT HANDLING FP CNTRL MSG \n"));
       return ERROR_GENERIC_FAILURE_E;
    }

    fpDataOffset = obtainMsgInSize();

    switch(pMsgHdr->msgId)
    {
        case FP_RACH_MSG:
            clFwdRachDataInd(&pCll1RecvBuf[fpDataOffset], pMsgHdr, &fpUlData.u.data.fpDatahdr.r4DataHdr);
            DEBUG4(("===== CL --> Frame Protocl Rach Message Received\n"));
            break;
        case FP_DCH_MSG:
            ueIdx = getUeIndexFromBindId (fpUlData.bindingId);
            if(ueIdx == -1){
               DEBUG1(("===== ERROR: Couldn't Find UeIdx For DCH BindId(%d), Drop DCH TB \n", fpUlData.bindingId));
               return;
            }
            clFwdDchDataInd(&pCll1RecvBuf[fpDataOffset], ueIdx, pMsgHdr, &fpUlData.u.data.fpDatahdr.r4DataHdr);
            DEBUG4(("===== CL --> Frame Protocl Dch Message \n"));
            break;
        case FP_OLPC_MSG:
            DEBUG3(("===== CL --> Frame Protocol Outer Loop Power Control Message \n"));
            break;  
        default:
            DEBUG2(("Unsupported FP message Id received%d\n",pMsgHdr->msgId));
            break;
    }

    return (retCode);
}/*End of clDecodeProcFpData*/


/*############################################################################
 * Method Name : clDecodeNBAPMsg
 *
 * Description    : This procedure decodes NBAP messages received from L1.
 *
 * Parameters    : 
 * pMsgStatus   Pointer to message Buffer
 * pMsgHdr      Pointer to message header
 * pMsgReadPtr  Pointer to read the circular buffer
 *
 * Returns     :       None
 ############################################################################*/
static S16 clDecodeNBAPMsg (L1MsgStatus_t   *pMsgStatus,
                            U8          *pCll1RecvBuf,
                            L1CAPI_MsgHdr   *pMsgHdr)
{
    ErrorCode_e retCode;

    switch(pMsgHdr->msgId)
    {
        case GENERIC_RESPONSE:
        {
            L1CAPI_Generic_Response * pL1CGenRsp = NULL;                           

            retCode = clGenericResponseDec(pMsgStatus, pMsgHdr);
            if( L1_MSG_SUCCESS == pMsgStatus->l1MsgResult)
            {
               pL1CGenRsp = (L1CAPI_Generic_Response *)pHostUlMsg;
               retCode = clRecvL1GenericRsp(pL1CGenRsp,pMsgHdr);
             
               /* Clean up the memory */
               if (NULL != pL1CGenRsp)
               {
                  free(pL1CGenRsp);
                  pL1CGenRsp = NULL;
               }
            }
            else
            {
               DEBUG2(("CL Recv Task : ***WARNING***:decodeL1MsgId generic responce %d addInfo0 %d addInfo1 %d\n", 
                      pMsgStatus->l1MsgResult, pMsgStatus->additionalInfo0, pMsgStatus->additionalInfo1));
            }
        }
        break;

        case CMN_TRCH_PRACH_SETUP_RESPONSE:
            DEBUGMSG(("CL Recv Task : CMN_TRCH_PRACH_SETUP_RESPONSE Received from L1\n"));
            SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_PRACH_SETUP_RSP_E, NULL);
            break;

        case CMN_TRCH_SCCPCH_SETUP_RESPONSE:
        {
            L1CAPI_Sccpch_Setup_Response* pL1CSccpchRsp = NULL;

            retCode = clSccpchResponseDec(pMsgStatus, pMsgHdr, pL1CSccpchRsp);
            if( L1_MSG_SUCCESS == pMsgStatus->l1MsgResult)
            {
               DEBUGMSG(("CL Recv Task : CMN_TRCH_SCCPCH_SETUP_RESPONSE Received from L1\n"));
               SendMsgToTask(CL_L1C_RCV_TASK_E, APP_RRC_TASK_E, CL_NBAP_SCCPCH_SETUP_RSP_E, NULL);

               pL1CSccpchRsp = (L1CAPI_Sccpch_Setup_Response *)pHostUlMsg;

               /* Clean Memory Allocated */
               if(NULL != pL1CSccpchRsp)
               {
                   int idx = 0;
                   for (idx = 0; idx < pL1CSccpchRsp->n_FACH; idx++)
                   {
                      if(NULL != pL1CSccpchRsp->ptrFACH_binding_id)
                      {
                         free (pL1CSccpchRsp->ptrFACH_binding_id);
                         pL1CSccpchRsp->ptrFACH_binding_id = NULL;
                      }
                   }

                   free(pL1CSccpchRsp);
                   pL1CSccpchRsp = NULL;
               }
            }
            else
            {
               DEBUG1((" ***WARNING***:FAILED: decodeL1MsgId Sccpch response %d addInfo0 %d addInfo1 %d\n", pMsgStatus->l1MsgResult,
                                                                                                    pMsgStatus->additionalInfo0, 
                                                                                                    pMsgStatus->additionalInfo1));
            }
            break;
        }
        case RADIOLINK_SETUP_RESPONSE:
            clDecodeRadioLinkSetupResponse (pMsgStatus, pMsgHdr);
            break;

        case DEDICATED_MEAS_INIT_RSP:
            DEBUGMSG(("DEDICATED_MEAS_INIT_RSP: DEDICATED MEAS INIT RESPONSE Received from L1\n"));
            clDecodeDedicatedMeasInitResponse (pMsgStatus, pMsgHdr);
            break;

        case DEDICATED_MEAS_REPORT:
            DEBUGMSG(("DEDICATED_MEAS_INIT_RSP: DEDICATED MEAS REPORT Received from L1\n"));
            clDecodeDedicatedMeasReport (pMsgStatus, pMsgHdr);
            break;

        case DEDICATED_MEAS_FAILURE_IND:
            break;

        case COMMON_MEAS_INIT_RSP:
            break;

        case COMMON_MEAS_REPORT:
            break;

        case RADIOLINK_FAILURE_INDICATION:
            clDecodeRadioLinkFailureIndication (pMsgStatus, pMsgHdr);
            break;

        case RADIOLINK_RESTORE_INDICATION:
            break; 

        case RADIOLINK_RECONFIG_READY:
            DEBUGMSG(("RADIOLINK_RECONFIG_READY: Received from L1\n"));
            clDecodeRadioLinkReconfigReady(pMsgStatus, pMsgHdr);
            break;

        default:
            DEBUG2(("CL Recv Task : Unsupported message Id %d\n",pMsgHdr->msgId));
            break;
    }

    return (retCode);
}


/*############################################################################
 * Method Name : clDecodeL1MsgType
 *
 * Description : This procedure decodes messages received from L1.
 *
 * Parameters  : 
 * pMsgStatus   Pointer to message Buffer 
 * pMsgHdr      Pointer to message header
 * pMsgReadPtr  Pointer to read the circular buffer
 *
 * Returns     : None
 *############################################################################ */
static void clDecodeL1MsgType (L1MsgStatus_t   *pMsgStatus,
                               U8              *pCll1RecvBuf,
                               L1CAPI_MsgHdr   *pMsgHdr)
{
    switch(pMsgHdr->msgType)
    {
        case CTRL_NBAP_MSG:
            DEBUG4(("Process NBAP message Received from L1\n"));
            clDecodeNBAPMsg(pMsgStatus, pCll1RecvBuf, pMsgHdr);
            break;

        case FP_MSG:
            DEBUG4(("Process FP message Received from L1\n"));
            clDecodeProcFpData(pCll1RecvBuf, pMsgHdr);
            break;

        default:
            DEBUG2(("Unsupported message Type %d\n",pMsgHdr->msgType));
            break;
    }
}


/*############################################################################
 * Method Name : clDecodeOctL1Buff
 *
 * Description : This procedure decodes messages received from L1.
 *
 * Parameters  : 
 *  pCll1RecvBuf Pointer to L1 received buffer
 *
 * Returns     : None
 *############################################################################*/
void clDecodeOctL1Buff (uint8_t* pCll1RecvBuf)
{
    L1MsgStatus_t    msgStatus;
    L1CAPI_MsgHdr    msgHdr;

    /* Initialize the msgStatus struct */
    msgStatus.l1MsgResult     = L1_MSG_SUCCESS;
    msgStatus.additionalInfo0 = 0;
    msgStatus.additionalInfo1 = 0; 

    resetMsgRead ((uint8_t *)pCll1RecvBuf);

    /* Decode the header */
    l1c_msgHdrMsgDecHdlr(&msgStatus, &msgHdr);

    if(msgStatus.l1MsgResult != L1_MSG_SUCCESS)
    {
       DEBUG1(("CL : Received Message Header decode error\n"));
       return ERROR_L1_DATA_READ_FAIL_E;
    }
    else
    {
       clDecodeL1MsgType(&msgStatus, pCll1RecvBuf, &msgHdr);
    }
}

ErrorCode_e clRecvCPlaneRSP (void)
{
    uint32_t      length       = 0;
    L1API_Error_t l1ApiErr     = L1API_NO_ERROR;

    memset(gClCntxt.cPlaneL1RspBuf, 0, L1_CPLANE_RSP_MAX_BUF_SIZE);
    l1ApiErr = L1API_RecvMsg(NULL, L1API_PORT_CPLANE_RSP,
                             (uint32_t*)gClCntxt.cPlaneL1RspBuf, L1_CPLANE_RSP_MAX_BUF_SIZE, &length);
    if (L1API_NO_ERROR != l1ApiErr)
    {
       DEBUG1(("\n CL : ERROR in receiving control packet \n"));
       return ERROR_L1_DATA_READ_FAIL_E;
    }

    if(length > 0){
       clDecodeOctL1Buff((uint8_t*) gClCntxt.cPlaneL1RspBuf);
    }

    return (SUCCESS_E);
}

ErrorCode_e clRecvUPlaneData(void)
{
    uint32_t      length       = 0;
    L1API_Error_t l1ApiErr     = L1API_NO_ERROR;

    // Using same global variable to read and store L1 Msg/Data temporarily
    memset(gClCntxt.uPlaneL1DataBuf, 0, L1_UPLANE_MAX_BUF_SIZE);
    l1ApiErr = L1API_RecvMsg(NULL, L1API_PORT_UPLANE_UL,
                            (uint32_t*)gClCntxt.uPlaneL1DataBuf, 
                             L1_UPLANE_MAX_BUF_SIZE, &length);
    if (L1API_NO_ERROR != l1ApiErr)
    {
       DEBUG1(("\n CL : ERROR in receiving control packet \n"));
       return ERROR_L1_DATA_READ_FAIL_E;
    }

    if(length > 0)
    {
       clDecodeOctL1Buff((uint8_t*) gClCntxt.uPlaneL1DataBuf);
    }

    return (SUCCESS_E);
}

ErrorCode_e clRecvBFN(void)
{
    uint32_t      length    = 0;
    L1API_Error_t l1ApiErr  = L1API_NO_ERROR;
    uint32_t      bfn       = 0;
    // Using same global variable to read and store L1 Msg/Data temporarily
    memset(gClCntxt.uPlaneL1DataBuf, 0, L1_UPLANE_MAX_BUF_SIZE);
    l1ApiErr = L1API_RecvMsg(NULL, L1API_PORT_BFN, &bfn, sizeof(U32), &length);

    if (L1API_NO_ERROR != l1ApiErr)
    {
       DEBUG1(("\n CL : ERROR in BFN Reading \n"));
       return ERROR_L1_DATA_READ_FAIL_E;
    }

    gClCntxt.bfn = bfn >> 16;
#if 1
  //  if(gClCntxt.bfn %100 == 0){
  //      printf("\n Received TTI from Layer1 \n");
    //   printf("Sending Bfn to L2: bfn(%d)\n", gClCntxt.bfn);
//    }
#else 
    // TBD: This will create too much of log, remove it once bfn transfer to L2 is tested.
    printf("L1 Bfn Value(%d)",gClCntxt.bfn);
#endif

    /* Timer Control Block tick */
    timerTick ();

    SendMsgToTask(CL_L1C_RCV_TASK_E, L2_DL_DATA_TASK_E, CL_L2_DL_TTI_IND, &gClCntxt.bfn);

    return (SUCCESS_E);
}

ErrorCode_e InitClContext(void)
{
    // TBD: INITIALIZE Cl Context,UL/DL Both 
    gClCntxt.cPlaneTrnsId = 0;
    gClCntxt.uPlaneTrnsId = 0;
    gClCntxt.bfn          = 0;
    gClCntxt.pchL1BindId  = 0;
#if 0
    gClCntxt.bindIdUeIdxMappingInfo.numValidEntry = 0;
    gClCntxt.bindIdUeIdxMappingInfo.firstValidEntryIdx = INVALID_MAPPING_IDX;
    gClCntxt.bindIdUeIdxMappingInfo.lastValidEntryIdx  = INVALID_MAPPING_IDX;
    memset(&gClCntxt.bindIdUeIdxMappingInfo.clBindIdMapping, 0, sizeof(ClBindIdMapping_t) * MAX_BIND_ID_MAPPING_ENTRY);
#endif
    return SUCCESS_E;
}
