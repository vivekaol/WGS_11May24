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
  * File Name	: rrcMsg.c  
  *
  * Description : This file has interface with L2, all data/control msg are 
  *               received from L2.
  *
  * History 	:
  *
  * Date		 Author 				 Details
  * ---------------------------------------------------------------------------
  * 17/11/2014	         Ashutosh Samal                          File Creation
  *############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * ----------------------------------------------------- */
#include "stdio.h"
#include "rrcMsg.h"
#include "rrc.h"
#include "rrcItf.h"
#include "cmnDebug.h"
#include "feaConfig.h"

static DbgModule_e  DBG_MODULE = rrc;

ErrorCode_e UeSmL2EvtHndlr(Msg_t msgBuf)
{
   ErrorCode_e retCode = SUCCESS_E;
   RrcDataReq *pRrcDataInd;
   /* Get UE Id */
   unsigned int *pUeId = NULL;


   switch(msgBuf.msgType)
   {
      case L2_UL_CCCH_DATA_INDICATION_E:
         DEBUG3((" UL CCCH Data Indication received\n"));
         pRrcDataInd = (RrcDataReq *)msgBuf.msgBuf;
         rrcHandleRlcDataIndication (pRrcDataInd);
         break;

      case L2_UL_DCCH_DATA_INDICATION_E:
         DEBUG3(("UL DCCH Data Indication received\n"));
         pRrcDataInd = (RrcDataReq *)msgBuf.msgBuf;
         rrcHandleRlcDataIndication (pRrcDataInd);
         break;

      case L2_RLC_ERROR_CALL_RLS_E:
         pUeId = (unsigned int *)msgBuf.msgBuf;
         handleUeEvents (*pUeId, UE_RLC_ERROR_CALL_RLS);
         break;

      default:
         DEBUG2(("RRC : Unknown Message Type received from L2_UL_DATA_TASK_E\n"));
         break;
   }

   return (retCode);
}

ErrorCode_e IdleUeEvtHndlr(Msg_t msgBuf)
{
   ErrorCode_e retCode = SUCCESS_E;
   char *oocImsi = (char *)msgBuf.msgBuf; //Out of coverage IMSI

   switch(msgBuf.msgType)
   {
      case L2_DL_PCCH_UE_OUT_OF_COVERAGE_E:
         DEBUG3(("Idle UE Out of Coverage Event Handler\n"));
         handleIdleUeEvent(oocImsi, UE_OUT_OF_COVERAGE_E);
         break;

      default:
         DEBUG2(("RRC : Unknown Message Type received from L2_DL_DATA_TASK_E\n"));
         break;
   }

   return(retCode);
}

ErrorCode_e UeSmTimerEvtHndlr (Msg_t msgBuf)
{
   ErrorCode_e retCode = SUCCESS_E;

   /* Get UE Id */
   unsigned int *pUeId = (unsigned int *)msgBuf.msgBuf;

   if ((*pUeId >= 0) && (*pUeId < MAX_UE_SUPPORTED))
   { 
      switch(msgBuf.msgType)
      {
         case RRC_RL_SETUP_TIMEOUT_E:
            DEBUG1(("RADIO LINK SETUP TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RL_SETUP_TIMEOUT);
            break;

         case RRC_RL_DELETE_TIMEOUT_E:
            DEBUG1(("RADIO LINK DELETE TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RL_DELETE_TIMEOUT);
            break;

         case RRC_CONN_SETUP_TIMEOUT_E:
            DEBUG1(("RRC CONNECTION SETUP TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RRC_CON_SETUP_TIMEOUT);
            break;

         case RRC_IDENTITY_REQ_TIMEOUT_E:
            DEBUG1(("RRC IDENTITY REQUEST TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_IDENTITY_REQ_TIMEOUT);
            break;

         case RRC_CONNECTION_REL_TIMEOUT_E:
            DEBUG1(("RRC CONNECTION RELEASE TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RRC_CON_REL_TIMEOUT);
            break;

         case RRC_NAS_REJECT_TIMEOUT_E:
            DEBUG1(("NAS REJECT TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_NAS_REJECT_TIMEOUT);
            break;

         case RRC_DED_MEAS_INIT_REQ_TIMEOUT_E:
            DEBUG1(("DED MEAS INIT REQ TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_DED_MEAS_INIT_REQ_TIMEOUT);
            break;

         case RRC_DED_MEAS_TERM_REQ_TIMEOUT_E:
            DEBUG1(("DED MEAS TERM REQ TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_DED_MEAS_TERM_REQ_TIMEOUT);
            break;

        case RRC_PAGING_TYPE2_TIMEOUT_E:
            DEBUGMSG(("PAGING TYPE2 TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RRC_PAGING_TYPE2_TIMEOUT);
            break; 

        case RRC_PHY_CH_RECONF_TIMEOUT_E:
            DEBUGMSG(("PHYSICAL CHANNEL RECONFIG TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RRC_PHY_CH_RECONF_TIMEOUT);
            break; 

         case RRC_START_GPS_TIMEOUT_E:
            DEBUGMSG(("START UE BASED GPS TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RRC_START_UE_BASED_GPS_TIMEOUT);
            break;

         case RRC_GPS_MEAS_CNTRL_REL_TIMEOUT_E:
            DEBUGMSG(("GPS MEASUREMENT CONTROL REL TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RRC_GPS_MEAS_CNTRL_REL_TIMEOUT);
            break;

#if 0
         case RRC_GPS_MEAS_CNTRL_MODIFY_TIMEOUT_E:
            DEBUGMSG(("GPS MEASUREMENT CONTROL MODIFY TIMEOUT for UE Id(%ld)\n",
                   *pUeId));
            handleUeEvents (*pUeId, UE_RRC_GPS_MEAS_CNTRL_MODIFY_TIMEOUT);
            break;
#endif //if 0

         default:
            DEBUG1(("UNKNOWN MESSAGE TYPE received from TIMER_TASK_E\n"));
            break;
      }
   }

   /* Free the memory */
   if (NULL != pUeId)
   {
      free (pUeId);
      pUeId = NULL;
   }

   return (retCode);
}

