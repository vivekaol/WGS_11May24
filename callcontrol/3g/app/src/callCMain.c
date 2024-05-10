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
 ############################################################################*/

/*############################################################################
 * File Name   : callCMain.c 
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 11/09/2014	Kuldeep S. Chauhan      File Creation
 ############################################################################ */
 
/* -----------------------------------------------------
 *                 Include Files
 * ----------------------------------------------------- */
#include <stdio.h>
#include "pthread.h"
#include "unistd.h"
#include "l1capi_datastruct.h"
#include "oct_l1cIoApi.h"
#include "callCMainUtil.h"
#include "clL1RcvMsg.h"
#include "cmnDs.h"
#include "callCMainUtil.h"
#include "errorCode.h"
#include "clContext.h"
#include "callCTaskHndlr.h"
#include "l2TaskHndlr.h"
#include "timerApi.h"
#include "umtsCfg.h"
#include "asnApi.h"
#include "slsDecode3g.h"
#include "cmnDebug.h"
#include "rrc.h"
#include "fxLSocketInterfaceApi.h"
#include "ratSocketItf.h"
#include "gsmCommon.h"

static DbgModule_e  DBG_MODULE = app;
extern int clientFd;

#ifdef CELL_ANTENNA_CHANGE
extern FILE *pBandFreqFile;
#endif

/* -----------------------------------------------------
 *                 Global Variable (App Level)
 * -----------------------------------------------------*/
L1CAPI_Modem_Setup_Request       gModemSetupReq;
L1CAPI_Cell_Delete_Request       gCellDeleteReq;
L1CAPI_Cell_Setup_Request        gCellSetupReq;
L1CAPI_Cell_Reconfig_Request     gCellReconfigReq;
L1CAPI_Sccpch_Setup_Request      gSccpchSetupReq;
L1CAPI_Prach_Setup_Request       gPrachSetupReq;
L1CAPI_Radiolink_Setup_Request   gRadioLinkSetupReq;
L1CAPI_Radiolink_DeletionRequest gRadioLinkDeleteReq;
L1CAPI_Radiolink_Reconfig_Prepare gRadioLinkReconfPrepReq;
L1CAPI_Radiolink_ReconfigCommit   gRadioLinkReconfCommitReq;
L1CAPI_Dedicated_Meas_Init_Request gDedicatedMeasInitReq;
L1CAPI_Dedicated_Meas_Term_Request gDedicatedMeasTermReq;
ClCntxt_t                        gClCntxt;
UmtsConfigControlBlock           gUmtsConfig;
extern AutoCfgScanResult_t      *pAutoCfgScanResult;
extern unsigned int fillCellSelReSelInfoFromScanResult ();
void sendStartIdCatcherRsp(unsigned int status);
ErrorCode_e clRecvCPlaneRSP (void);
ErrorCode_e InitSystem(void);
ErrorCode_e CreateL1RvcThrd(void);
ErrorCode_e RrcAppCellSmStart(void);

//FILE       *gLogFileFd   = NULL;
//const char *gLogFileName = "3gImscLogFile.txt";

pthread_t      gL1RcvThreadId;
pthread_attr_t gL1RcvThreadAttr;
extern int exitUmtsL1RcvThread;

//extern void* clL1Receiver(void *dummy);
/* -----------------------------------------------------
 *                 IMSI Catcher Application Init
 * -----------------------------------------------------*/
 
/*############################################################################
 * Method Name : clL1Receiver
 *
 * Description : This procedure waits for messages from L1.
 *
 * Parameters	: 
 *  dummy		  Dummy
 *
 * Returns 	: NULLP, if exits
 * 			  None,  waits forever
 ############################################################################ */
void* clL1Receiver(void *dummy)
{
    uint32_t getMask = 0;
    uint32_t setmask = 0;

    L1API_Error_t l1ApiErr = L1API_NO_ERROR;
   	 
    getMask = (1 << L1API_PORT_CPLANE_RSP) | (1 << L1API_PORT_UPLANE_UL) |
   		   (1 << L1API_PORT_BFN );
   	 
    /* Forever loop */
    while (1)
    {		
        setmask = 0;

        /* Get Message */
        l1ApiErr = L1API_PollMsg(NULL, getMask, &setmask, 0);
		
		if(exitUmtsL1RcvThread)
		{
		    pthread_exit(NULL);
		}
		
        if(L1API_NO_ERROR == l1ApiErr)
        {			  
  	   /* Receive Control Plane message */
           if(setmask & (1 << L1API_PORT_CPLANE_RSP))
           {
              clRecvCPlaneRSP();
       	   }

           /* Receive BFN */
           if(setmask & (1 << L1API_PORT_BFN))
           {
               clRecvBFN();
           }

           /* Receive User Plane message */
       	   if(setmask & (1 << L1API_PORT_UPLANE_UL))
           {
       	      clRecvUPlaneData();
       	   }			  
        }
        else
        {
       	   DEBUG1(("L1API_PollMsg() error %u\n",l1ApiErr));
        }
    }

    return (NULL);
}

#if 0
ErrorCode_e InitImscLogFile()
{
   ErrorCode_e retCode = SUCCESS_E;

   // This log file cant be used for CL as Currently no locking is implemented,
   // and CL runs in different thread than App(L2,L3,App)
   /*---------------- INITALIZE Log File: START --------------------------*/
   printf("===== INITIALIZE : Log File =========\n");
   gLogFileFd  = fopen(gLogFileName , "wb");
   if (NULL == gLogFileFd)
   {
       fprintf(stderr, "Error: can't open %s\n", gLogFileFd);
       retCode = ERROR_GENERIC_FAILURE_E;
   }

   fprintf(gLogFileFd, "===== Log File INITIALIZED =========\n");
   return retCode;
}

#endif
ErrorCode_e InitSystem(void)
{
   ErrorCode_e errorCode = SUCCESS_E;

   /*---------------- INITALI PLATFORM: START --------------------------*/
   DEBUG3(("===== INITIALIZE : Thread,MsgQueue and Thread Context =========\n"));
   InitMsgQueCntxt();
   InitTaskCntxt();
   InitThrdCntxt(); 
 
   // ----------------------
   DEBUG3(("===== Create Thread Entries: Main Thread, CL Thread =========\n"));
   CreateThrdCntxt(THRD_ID_STACK_APP_E, &gMsgQCntxt); // STACK&APP Thread MsgQueuContext mapped
   CreateThrdCntxt(THRD_ID_CL_E,         NULL);       // CL TASK: No MsgQueueContext
   CreateThrdCntxt(THRD_ID_SOCK_ITF_E,         NULL);       // CL TASK: No MsgQueueContext
 
   // ----------------------
   DEBUG3(("===== Create Tasks Entries: RRC/APP, L2_DL, L2_UL, L2_CFG, CL_L1C =========\n"));
   CreateTask(APP_RRC_TASK_E,    THRD_ID_STACK_APP_E, APP_RRC_TASK_QUEUE_E);
   CreateTask(L2_DL_DATA_TASK_E, THRD_ID_STACK_APP_E, L2_DL_DATA_TASK_QUEUE_E);
   CreateTask(L2_UL_DATA_TASK_E, THRD_ID_STACK_APP_E, L2_UL_DATA_TASK_QUEUE_E);
   CreateTask(L2_CFG_TASK_E,     THRD_ID_STACK_APP_E, L2_CFG_TASK_QUEUE_E);
   CreateTask(CL_L1C_SND_TASK_E, THRD_ID_STACK_APP_E, CL_L1C_SND_TASK_QUEUE_E);
   CreateTask(CL_L1C_RCV_TASK_E, THRD_ID_CL_E,        INVALID_MSG_QUEUE_ID);
   CreateTask(SOCK_ITF_TASK_E,   THRD_ID_SOCK_ITF_E,  INVALID_MSG_QUEUE_ID);
 
   // ---- As CL Will be receiving Msg only from L1C, no need to have MsgQ with APP platform
   // For Now this only has handling of One MsgQContext
   DEBUG3(("===== Create Msg Q Entries: RRC/APP, L2_DL, L2_UL, L2_CFG =========\n"));
   CreateMsgQue(APP_RRC_TASK_QUEUE_E,    rrcAppTaskHndlr);
   CreateMsgQue(L2_DL_DATA_TASK_QUEUE_E, l2DlDataTaskHndlr);
   CreateMsgQue(L2_UL_DATA_TASK_QUEUE_E, l2UlDataTaskHndlr);
   CreateMsgQue(L2_CFG_TASK_QUEUE_E,     l2CfgTaskHndlr);
   CreateMsgQue(CL_L1C_SND_TASK_QUEUE_E, clL1CSndTaskHndlr);
 
   return errorCode;
} /* End InitSystem */


ErrorCode_e CreateL1RvcThrd(void)
{
    L1API_Error_t err;
    uint32_t handle = 3; // for 3g
    err = L1API_Open(NULL, &handle); //No need to pass any arguments

    if (err != L1API_NO_ERROR)
    {
        //LOGP(DL1C, LOGL_FATAL, "Error: L1C IO port opening failed.\n");
        DEBUG1(("Error: L1C IO port opening failed.\n"));
        return ERROR_CODE3_E;
    }
    else
    {
        /* Initialize Timer Mutex */
        if (0 != pthread_mutex_init(&timerMutexLock, NULL))
        {
           DEBUG1(("ERROR : Timer Mutex Initialization Failed\n"));
           return ERROR_GENERIC_FAILURE_E;
        }

        if (pthread_attr_init(&gL1RcvThreadAttr))
        {
           DEBUG1(("pthread attr create error \n"));
           return ERROR_GENERIC_FAILURE_E;
        }

        if ((pthread_attr_setstacksize(&gL1RcvThreadAttr, 100*1024) < 0))
        {
           DEBUG1(("pthread setstacksize error \n" ));
           return ERROR_GENERIC_FAILURE_E;
        }

        DEBUG3(("L1C IO port opened successfully.\n"));
        // Create receiver thread for octasic L1 messages
        if(pthread_create(&gL1RcvThreadId, &gL1RcvThreadAttr, clL1Receiver,NULL) )
        {
           //LOGP(DL1C, LOGL_FATAL, "Error: Rx thread failed.\n");
           DEBUG1(("Error: Rx thread creation failed.\n"));
           return ERROR_CODE4_E;
        }
    }

    return SUCCESS_E;
}

#if 0
ErrorCode_e InitTimerThread(void)
{
    ErrorCode_e    retCode = SUCCESS_E;

    /* Initialize Timer Mutex */
    if (0 != pthread_mutex_init(&timerMutexLock, NULL))
    {
        printf("ERROR : **** Timer Thread Mutex Initialization Failed ****\n");
        retCode = ERROR_GENERIC_FAILURE_E;
    }

    /* Initialize Timer Thread Attribute */
    pthread_attr_init(&gTimerThreadAttr);

    /* Create Timer Thread */
    if (0 != pthread_create(&gTimerThreadId, &gTimerThreadAttr,
                            timerServiceHandler, NULL))
    {
        printf("ERROR : **** Timer Thread Creation Failed ****\n");
        retCode = ERROR_GENERIC_FAILURE_E;
    }

    return (retCode);
}
ErrorCode_e readAndFillUmtsConfig (void)
{
    ErrorCode_e retCode        = SUCCESS_E;
    FILE        *pFile         = NULL;
    char        paramName[100] = {'\0'};
    unsigned int idx = 0;

    /* Open the file umts_cfg.txt file */
    if (NULL == (pFile = fopen("umts_cfg.txt", "r")))
    {
        printf("APP : Unable to open umts_cfg.txt file\n");
        return (ERROR_GENERIC_FAILURE_E);
    }

    /* Read General config parameters */
    fscanf (pFile, "%*s %*s");

    /* Read maxNumOfUsers parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxNumOfUsers);

    /* Read band parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.band);

    /* Read DLUARFCN parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.dlUarfcn);

    /* Read rncId parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.rncId);

    /* Read cellId parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.cellId);

    /* Read psc parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.psc);

    /* Read PLMN config parameters */
    fscanf (pFile, "%*s %*s");

    /* Read mccLen parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.mccLen);

    /* Read mcc parameter */
    fscanf (pFile, "%s %*s %ld %ld %ld", paramName,
                                         &gUmtsConfig.mcc[0],
                                         &gUmtsConfig.mcc[1],
                                         &gUmtsConfig.mcc[2]);

    /* Read mncLen parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.mncLen);

    /* Read mnc parameter */
    fscanf (pFile, "%s %*s %ld %ld %ld", paramName,
                                         &gUmtsConfig.mnc[0],
                                         &gUmtsConfig.mnc[1],
                                         &gUmtsConfig.mnc[2]);

    /* Read lac parameter */
    fscanf (pFile, "%s %*s %ld %ld", paramName,
                                     &gUmtsConfig.lac[0],
                                     &gUmtsConfig.lac[1]);

    /* Read rac parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.rac);

    /* Read Cell Reselcetion config parameters */
    fscanf (pFile, "%*s %*s %*s");

    /* Read cellSelQualMeas parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.cellSelQualMeas);

    /* Read qQualMin parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.qQualMin);

    /* Read qQaulMinOffset parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.qQaulMinOffset);

    /* Read qRxLevMin parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.qRxLevMin);

    /* Read qRxLevMinOffset parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.qRxLevMinOffset);

    /* Read tReselec parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.tReselec);

    /* Read ueTxPwrMaxRACH parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.ueTxPwrMaxRACH);

    /* Read qhyst1 parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.qhyst1);

    /* Read Power config parameters */
    fscanf (pFile, "%*s %*s");

    /* Read maxCellTxPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxCellTxPwr);
    
    /* Read maxUlTxPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxUlTxPwr);
    
    /* Read maxPcpichPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxPcpichPwr);
    
    /* Read maxPschpPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxPschpPwr);
    
    /* Read maxSschPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxSschPwr);
    
    /* Read maxBchPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxBchPwr);
    
    /* Read maxAichPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxAichPwr);
    
    /* Read maxPichPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxPichPwr);
    
    /* Read maxPchPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxPchPwr);
    
    /* Read maxFachPwr parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.maxFachPwr);
    
    /* Read txAttn parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.txAttn);

    /* Read GSM Redirect parameters */
    fscanf (pFile, "%*s %*s %*s");
    
    /* Read numOfGSMNetwork parameter */
    fscanf (pFile, "%s %*s %ld", paramName, &gUmtsConfig.numOfGsmRedirectInfo);
   
    for (idx = 0; idx < gUmtsConfig.numOfGsmRedirectInfo; idx++)
    {
        /* Read arfcn parameter */
        fscanf (pFile, "%s %*s %ld", paramName, 
                                     &gUmtsConfig.gsmRedirectInfo[idx].arfcn);

        /* Read freqBand parameter */
        fscanf (pFile, "%s %*s %ld", paramName, 
                                     &gUmtsConfig.gsmRedirectInfo[idx].frequencyBand);

        /* Read bsicPresence parameter */
        fscanf (pFile, "%s %*s %ld", paramName, 
                                     &gUmtsConfig.gsmRedirectInfo[idx].bsicPresence);

        /* Read bsicNcc parameter */
        fscanf (pFile, "%s %*s %ld", paramName, 
                                     &gUmtsConfig.gsmRedirectInfo[idx].bsicNcc);

        /* Read bsicBcc parameter */
        fscanf (pFile, "%s %*s %ld", paramName, 
                                     &gUmtsConfig.gsmRedirectInfo[idx].bsicBcc);
    }
    
    /* Close the file */
    fclose (pFile);
    
    return (retCode);
}
#endif

int getPscFromScanResult (void)
{
   unsigned int idxIntraFreq = 0;
   unsigned int idxInterFreq = 0;
   unsigned int found = 0;
   unsigned int idx = 0;
   int          pscResult       = 0;
   unsigned int pscPriority[32] = {0};
   unsigned int interPscPriority[300] = {0};
   unsigned int interPsc[300] = {0};
   unsigned int interPscIndex = 0;
   unsigned int interPscFound = 0;
   unsigned int maxValue = 0;
   unsigned int maxIndex = 0;
   unsigned int foundInterFreqList = 0;
   AutoCfgScanResult_t *pCurScanRslt = NULL;
   AutoCfgScanResult_t *pStartScanRslt = NULL;

   /*check inter frequency List present or not*/
   pCurScanRslt = pAutoCfgScanResult;
   while(NULL != pCurScanRslt)
   {
      /* Find pointer which have inter frequency list */
      if (-1 != pCurScanRslt->interFreqPsc[0])
      {
          foundInterFreqList = 1;
          break;
      }
      pCurScanRslt = pCurScanRslt->next;
   }

   if(foundInterFreqList == 1)
   {
       pscResult = pCurScanRslt->interFreqPsc[0];

       while(NULL != pCurScanRslt)
       {
           /* Search in Inter Frequency List of neighbour list */
           for(idxInterFreq = 0; idxInterFreq < 32; idxInterFreq++)
           {
               interPscFound = 0;
               found = 0;
               if((-1 != pCurScanRslt->interFreqPsc[idxInterFreq]))
               {                   
                   /* Get the inter freq PSC which is not equal to actual operator PSC */
                   pStartScanRslt = pAutoCfgScanResult;
                   while(NULL != pStartScanRslt)
                   {
                        /* Active PSC Found */
                        if (pCurScanRslt->interFreqPsc[idxInterFreq] == pStartScanRslt->psc)
                        {
                            found = 1;
                            break;
                        }
                        pStartScanRslt = pStartScanRslt->next;
                   }
                   
                   if(found == 0)
                   {
                       for(idx = 0; idx < interPscIndex; idx++)
                       {
                          if(interPsc[idx] == pCurScanRslt->interFreqPsc[idxInterFreq])
                          {
                              interPscFound = 1;
                              interPscPriority[idx] = interPscPriority[idx] + 1;
                          }
                       }
                
                       if(interPscFound == 0)
                       {
                           interPsc[interPscIndex] = pCurScanRslt->interFreqPsc[idxInterFreq];
                           interPscPriority[interPscIndex] = interPscPriority[interPscIndex]  + 1;
                          interPscIndex++;
                       } 
                   }
                }
           }
           pCurScanRslt = pCurScanRslt->next;
       }
      
       /* Get the inter frequency PSC which having Highest priority */
       maxValue = interPscPriority[0];
       maxIndex = 0;

       for (idx = 1; idx < interPscIndex; idx++)
       {
           if (interPscPriority[idx] > maxValue)
           {
               maxValue = interPscPriority[idx];
               maxIndex = idx;
           }
       }
        
       if(interPsc[maxIndex] != 0)
       {
            pscResult = interPsc[maxIndex];
       }

       for (idx = 0; idx < interPscIndex; idx++)
       {
           DEBUG1(("index %d, PSC value %d, priority %d\n",idx,interPsc[idx],interPscPriority[idx]));
       }
   }
   /* 
    * Check if no Intra & Inter List is present, configure the active
    * PSC of the UARFCN having higher RSCP value.
    */
   else if ((-1 == pAutoCfgScanResult->intraFreqPsc[0]) &&
            (-1 == pAutoCfgScanResult->interFreqPsc[0]))
   {
      /* Returning Active PSC as no Intra & Inter PSC is present */
      pscResult = pAutoCfgScanResult->psc;
   }
   else if (pAutoCfgScanResult->intraFreqPsc[0] != -1)
   {
      for (idxIntraFreq = 0; idxIntraFreq < 32; idxIntraFreq++)
      {
          pscResult = pAutoCfgScanResult->intraFreqPsc[idxIntraFreq];

          if (-1 != pscResult)
          {
              /* Get the intra freq PSC which is not equal to actual operator PSC */
              pCurScanRslt = pAutoCfgScanResult;
              while(NULL != pCurScanRslt)
              {
                  /* Active PSC Found */
                  if (pscResult == pCurScanRslt->psc)
                  {
                     found = 1;
                     break;
                  }
                 
                  pCurScanRslt = pCurScanRslt->next;
              }
       
              /* Current PSC is matching to the active PSC */
              if(1 == found)
              {
                  found = 0;
                  continue;
              }
              else
              {
                  pscPriority[idxIntraFreq] = pscPriority[idxIntraFreq] + 1;
              }

              /* 
               * If current PSC is not matching to any of the active PSC, search
               * the PSC in Inter Frequency list 
               */ 
              for (idx = 0; idx < 32; idx++)
              {
                 if ((-1 != pAutoCfgScanResult->interFreqPsc[idx]) &&
                     (pscResult == pAutoCfgScanResult->interFreqPsc[idx]))
                 {
                    pscPriority[idxIntraFreq] = pscPriority[idxIntraFreq] + 1;
                 }
              }

              /*
               * Check for the presence of PSC in all neighbour list
               */
              pCurScanRslt = pAutoCfgScanResult;
              while(NULL != pCurScanRslt->next)
              {
                  /* Search in Intra Frequency List of neighbour list */
                  for(idx = 0; idx < 32; idx++)
                  {
                     if((-1 != pCurScanRslt->next->intraFreqPsc[idx]) &&
                        (pscResult == pCurScanRslt->next->intraFreqPsc[idx]))
                     {
                        pscPriority[idxIntraFreq] = pscPriority[idxIntraFreq] + 1;
                     }

                  }

                  /* Search in Inter Frequency List of neighbour list */
                  for(idx = 0; idx < 32; idx++)
                  {
                     if((-1 != pCurScanRslt->next->interFreqPsc[idx]) &&
                        (pscResult == pCurScanRslt->next->interFreqPsc[idx]))
                     {
                        pscPriority[idxIntraFreq] = pscPriority[idxIntraFreq] + 1;
                     }
                  }

                  pCurScanRslt = pCurScanRslt->next;
              }
          }
      }

      /* Get the intra frequency PSC which having Highest priority */
      maxValue = pscPriority[0];
      maxIndex = 0;

      for (idx = 1; idx < 32; idx++)
      {
         if (pscPriority[idx] > maxValue)
         {
             maxValue = pscPriority[idx];
             maxIndex = idx;
         }
      }

      pscResult = pAutoCfgScanResult->intraFreqPsc[maxIndex];
   }
   else if (pAutoCfgScanResult->interFreqPsc[0] != -1)
   {
      for (idxInterFreq = 0; idxInterFreq < 32; idxInterFreq++)
      {
          pscResult = pAutoCfgScanResult->interFreqPsc[idxInterFreq];

          if (-1 != pscResult)
          {
              /* Get the intra freq PSC which is not equal to actual operator PSC */
              AutoCfgScanResult_t *pCurScanRslt = pAutoCfgScanResult;
              while(NULL != pCurScanRslt)
              {
                  /* Active PSC Found */
                  if (pscResult == pCurScanRslt->psc)
                  {
                     found = 1;
                     break;
                  }
                 
                  pCurScanRslt = pCurScanRslt->next;
              }
       
              /* Current PSC is matching to the active PSC */
              if(1 == found)
              {
                  found = 0;
                  continue;
              }
              else
              {
                  pscPriority[idxInterFreq] = pscPriority[idxInterFreq] + 1;
              }

              /*
               * Check for the presence of PSC in all neighbour list
               */
              pCurScanRslt = pAutoCfgScanResult;
              while(NULL != pCurScanRslt->next)
              {
                  /* Search in Intra Frequency List of neighbour list */
                  for(idx = 0; idx < 32; idx++)
                  {
                     if((-1 != pCurScanRslt->next->intraFreqPsc[idx]) &&
                        (pscResult == pCurScanRslt->next->intraFreqPsc[idx]))
                     {
                        pscPriority[idxInterFreq] = pscPriority[idxInterFreq] + 1;
                     }
                  }

                  /* Search in Inter Frequency List of neighbour list */
                  for(idx = 0; idx < 32; idx++)
                  {
                     if((-1 != pCurScanRslt->next->interFreqPsc[idx]) &&
                        (pscResult == pCurScanRslt->next->interFreqPsc[idx]))
                     {
                        pscPriority[idxInterFreq] = pscPriority[idxInterFreq] + 1;
                     }
                  }

                  pCurScanRslt = pCurScanRslt->next;
              }
          }
      }

      /* Get the intra frequency PSC which having Highest priority */
      maxValue = pscPriority[0];
      maxIndex = 0;

      for (idx = 1; idx < 32; idx++)
      {
         if (pscPriority[idx] > maxValue)
         {
             maxValue = pscPriority[idx];
             maxIndex = idx;
         }
      }

      pscResult = pAutoCfgScanResult->interFreqPsc[maxIndex];
   }

   return (pscResult);
}

void autoConfigureUmtsIdCatcherParameters (void)
{
   unsigned idx, idx1 = 0;   

   /* Fill PSC */
   static int pscCount = 0;
   
   if(pAutoCfgScanResult->intraFreqPsc[pscCount] == -1)
	    pscCount = 0;
   
   gUmtsConfig.psc = pAutoCfgScanResult->intraFreqPsc[pscCount];//gsmCommRand(1, 511); //getPscFromScanResult ();

   pscCount++;
   if (pscCount >= 31)
     pscCount = 0;

   if(gUmtsConfig.psc == -1)
	   gUmtsConfig.psc = pAutoCfgScanResult->psc;

   /* Fill DL UARFCN */
   gUmtsConfig.dlUarfcn = pAutoCfgScanResult->dlUarfcn;
  
   /* Fill T3212 */
   gUmtsConfig.t3212 = pAutoCfgScanResult->t3212;

   /* Fill NMO */
   gUmtsConfig.nmo = pAutoCfgScanResult->nmo;

   /* Fill ATT */
   gUmtsConfig.att = 1;
 
   /* Fill Mib Plmn identity */
   gUmtsConfig.mibPlmnIdentity = pAutoCfgScanResult->mibPlmnIdentity;
 
   /* Fill number of Plmn*/
   gUmtsConfig.numOfPlmn = pAutoCfgScanResult->numOfPlmn;

   /* Fill Intra Frequency List */
   gUmtsConfig.sib11Info.numIntraFreqNeighbr = 3;
   gUmtsConfig.sib11Info.intraFreqNeighbrList[0].psc = gUmtsConfig.psc;
   if (pscCount <= 29)
   {
      gUmtsConfig.sib11Info.intraFreqNeighbrList[1].psc = pAutoCfgScanResult->intraFreqPsc[pscCount+1];
      gUmtsConfig.sib11Info.intraFreqNeighbrList[2].psc = pAutoCfgScanResult->intraFreqPsc[pscCount+2];
   }
   else
   {
      gUmtsConfig.sib11Info.intraFreqNeighbrList[1].psc = pAutoCfgScanResult->intraFreqPsc[0];
      gUmtsConfig.sib11Info.intraFreqNeighbrList[2].psc = pAutoCfgScanResult->intraFreqPsc[1];
   }

   /* Initialize MCC and MNC */
   for(idx1 = 0; idx1 < 6; idx1++)
   {
       gUmtsConfig.plmn[idx1].mccLength = 0;
       gUmtsConfig.plmn[idx1].mncLength = 0;

       for (idx = 0; idx < FXL_UMTS_MAX_MCC_LEN; idx++)
       {
           gUmtsConfig.plmn[idx1].mcc[idx] = 0xFFFFFFFF;
           gUmtsConfig.plmn[idx1].mnc[idx] = 0xFFFFFFFF;
       }
   }

   /* Fill MCC and MNC */
   for(idx1 = 0; idx1 < gUmtsConfig.numOfPlmn; idx1++)
   {
       gUmtsConfig.plmn[idx1].mccLength = pAutoCfgScanResult->plmn[idx1].mccLength;
       for (idx = 0; idx < pAutoCfgScanResult->plmn[idx1].mccLength; idx++)
       {
           gUmtsConfig.plmn[idx1].mcc[idx] = pAutoCfgScanResult->plmn[idx1].mcc[idx];
       }

       gUmtsConfig.plmn[idx1].mncLength = pAutoCfgScanResult->plmn[idx1].mncLength;
       for (idx = 0; idx < pAutoCfgScanResult->plmn[idx1].mncLength; idx++)
       {
           gUmtsConfig.plmn[idx1].mnc[idx] = pAutoCfgScanResult->plmn[idx1].mnc[idx];
       }
   }

   /* Fill RNC Id */
   gUmtsConfig.rncId = gsmCommRand(1, 65534);//200;
  
   /* Fill Cell Id */
   gUmtsConfig.cellId = gsmCommRand(1, 65534);

   gUmtsConfig.mibValueTag = gsmCommRand(1, 8);

   /* Fill cellSelQualMeas */
   gUmtsConfig.cellSelQualMeas = 0;

   /* Fill qQualMin */
   if (-1 != pAutoCfgScanResult->qQualMin)
   {
       gUmtsConfig.qQualMin = pAutoCfgScanResult->qQualMin;
   }
   else
   {
       gUmtsConfig.qQualMin = -24;
   }

   /* Fill qRxLevMin */
   if (-1 != pAutoCfgScanResult->qRxLevMin)
   {
       gUmtsConfig.qRxLevMin = pAutoCfgScanResult->qRxLevMin;
   }
   else
   {
       gUmtsConfig.qRxLevMin = -58;
   }

   /* Fill tReselec */
   if (-1 != pAutoCfgScanResult->tReselS)
   {
       gUmtsConfig.tReselec = pAutoCfgScanResult->tReselS;
   }
   else
   {
       gUmtsConfig.tReselec = 31;
   }

   /* Fill qHystLS */
   if (-1 != pAutoCfgScanResult->qHystLS)
   {
       gUmtsConfig.qHystLS = pAutoCfgScanResult->qHystLS;
   }
   else
   {
       gUmtsConfig.qHystLS= 4;
   }

   /* Fill qHystLS */
   if (-1 != pAutoCfgScanResult->qHyst2S)
   {
       gUmtsConfig.qHyst2S = pAutoCfgScanResult->qHyst2S;
   }
   else
   {
       gUmtsConfig.qHyst2S= 4;
   }

   /* Fill maxUlTxPwr */
   if (-1 != pAutoCfgScanResult->maxAllowedULTxPower)
   {
       gUmtsConfig.maxUlTxPwr = pAutoCfgScanResult->maxAllowedULTxPower;
   }
   else
   {
       gUmtsConfig.maxUlTxPwr = 24;
   }

   usleep(1000);
   /* Send configured Uarfcn indication to external client */
   fxL3gAutoConfigUarfcnInd uarfcnInd;
   
   uarfcnInd.hdr.msgLength = sizeof(fxL3gAutoConfigUarfcnInd);
   uarfcnInd.hdr.msgType = FXL_3G_AUTO_CONFIG_UARFCN_IND;
   uarfcnInd.hdr.rat = FXL_RAT_3G;
   uarfcnInd.uarfcn = gUmtsConfig.dlUarfcn;
   uarfcnInd.psc = gUmtsConfig.psc;
   uarfcnInd.cellId = gUmtsConfig.cellId;
   uarfcnInd.lac[0] = gUmtsConfig.lac[0];
   uarfcnInd.lac[1] = gUmtsConfig.lac[1];
   uarfcnInd.rac    = gUmtsConfig.rac;
   uarfcnInd.band   = pAutoCfgScanResult->band;
 
   if (-1 != clientFd)
   {
      if (send(clientFd, &uarfcnInd, sizeof(uarfcnInd), 0) < 0)
      {
          DEBUG1(("Unable to send Message to External Client\n"));
      }
      else
      {
          DEBUGMSG(("Auto config Uarfcn Indication is sent to External Client\n"));
      }
   }
   else
   {
      DEBUG1(("Unable to send message to External Client, clientFd = -1\n"));
   }


   /* Auto Configure Redirect DL UARFCN */
   AutoCfgScanResult_t *pCurScanRslt = pAutoCfgScanResult;
 
   gUmtsConfig.redirectDlUarfcn = pAutoCfgScanResult->dlUarfcn;

   while(NULL != pCurScanRslt)
   {
       if((pCurScanRslt->next != NULL) && 
          (pCurScanRslt->next->dlUarfcn != pAutoCfgScanResult->dlUarfcn))
       {
          gUmtsConfig.redirectDlUarfcn = pCurScanRslt->dlUarfcn;
          break;
       }
       pCurScanRslt = pCurScanRslt->next;
   }
}

void configureUmtsIdCatcherParameters (fxL3gConfigureIdCatcherParamsCmd *pIdCatcherParams)
{
   unsigned int idx,idx1 = 0;
#if EVAL_IDR_TECH
   fxL3gPlmn operator1Plmn;
   fxL3gPlmn operator2Plmn;

   operator1Plmn.mccLength = 3;
   operator1Plmn.mcc[0]    = 3;
   operator1Plmn.mcc[1]    = 3;
   operator1Plmn.mcc[2]    = 4;
   operator1Plmn.mncLength = 2;
   operator1Plmn.mnc[0]    = 0;
   operator1Plmn.mnc[1]    = 2;
   operator2Plmn.mccLength = 3;
   operator2Plmn.mcc[0]    = 3;
   operator2Plmn.mcc[1]    = 3;
   operator2Plmn.mcc[2]    = 4;
   operator2Plmn.mncLength = 2;
   operator2Plmn.mnc[0]    = 0;
   operator2Plmn.mnc[1]    = 3;
#endif


   /* Fill DL UARFCN */
   gUmtsConfig.dlUarfcn = pIdCatcherParams->dlUarfcn;

   /* Fill Redirect Info */
   gUmtsConfig.redirectDlUarfcn = pIdCatcherParams->dlUarfcn;

   /* Fill RNC Id */
   gUmtsConfig.rncId = pIdCatcherParams->rncId;
  
   /* Fill Cell Id */
   gUmtsConfig.cellId = pIdCatcherParams->cellId;
   
   /* Fill PSC */
   gUmtsConfig.psc = pIdCatcherParams->psc;

#if EVAL_IDR_TECH
   if( (operator1Plmn.mcc[0] == pIdCatcherParams->plmn.mcc[0])
      && (operator1Plmn.mcc[1] == pIdCatcherParams->plmn.mcc[1])
      && (operator1Plmn.mcc[2] == pIdCatcherParams->plmn.mcc[2]))
   {
      if( ((operator1Plmn.mnc[0] == pIdCatcherParams->plmn.mnc[0]) && (operator1Plmn.mnc[1] == pIdCatcherParams->plmn.mnc[1]))
        || ( (operator2Plmn.mnc[0] == pIdCatcherParams->plmn.mnc[0]) && (operator2Plmn.mnc[1] == pIdCatcherParams->plmn.mnc[1])))
      { }
      else
      {
         DEBUGMSG(( "\n Invalid MNC Configured\n"));
         return;
      }
   } 
   else
   {
      DEBUGMSG(( "\n Invalid MCC Configured\n"));
      return;
   }
#endif
   
   /* Fill Mib Plmn Identity */ 
   gUmtsConfig.mibPlmnIdentity = 0;
   
   /* Fill number of Plmn*/
   gUmtsConfig.numOfPlmn = pIdCatcherParams->numOfPlmn;

   /* Initialize MCC and MNC */
   for(idx1 = 0; idx1 < 6; idx1++)
   {
       gUmtsConfig.plmn[idx1].mccLength = 0;
       gUmtsConfig.plmn[idx1].mncLength = 0;
       
       for (idx = 0; idx < FXL_UMTS_MAX_MCC_LEN; idx++)
       {
           gUmtsConfig.plmn[idx1].mcc[idx] = 0xFFFFFFFF;
           gUmtsConfig.plmn[idx1].mnc[idx] = 0xFFFFFFFF;
       }
   }

   /* Fill MCC and MNC */
   for(idx1 = 0; idx1 < gUmtsConfig.numOfPlmn; idx1++)
   {
       gUmtsConfig.plmn[idx1].mccLength = pIdCatcherParams->plmn[idx1].mccLength;
       for (idx = 0; idx < pIdCatcherParams->plmn[idx1].mccLength; idx++)
       {
           gUmtsConfig.plmn[idx1].mcc[idx] = pIdCatcherParams->plmn[idx1].mcc[idx];
       }

       gUmtsConfig.plmn[idx1].mncLength = pIdCatcherParams->plmn[idx1].mncLength;
       for (idx = 0; idx < pIdCatcherParams->plmn[idx1].mncLength; idx++)
       {
           gUmtsConfig.plmn[idx1].mnc[idx] = pIdCatcherParams->plmn[idx1].mnc[idx];
       }
   }

   /* Fill LAC */
   gUmtsConfig.lac[0] = pIdCatcherParams->lac[0];
   gUmtsConfig.lac[1] = pIdCatcherParams->lac[1];

   /* Fill RAC */
   gUmtsConfig.rac = pIdCatcherParams->rac;

   /* Fill txAttenuation */
   gUmtsConfig.txAttn = pIdCatcherParams->txAttn;

   /* Fill T3212 */
   gUmtsConfig.t3212 = pIdCatcherParams->t3212;

   /* Fill NMO */
   gUmtsConfig.nmo = 1;

   /* Fill ATT */
   // Initialized in fillSibCfgParams. removed from here so that change of this parameter if done is not reset.
   //gUmtsConfig.att = 0x01;

   /* Fill Redirection Type */
   gUmtsConfig.redirectionType = pIdCatcherParams->redirectionType;

   /* Fill Redirection Info */
   if (FXL_UMTS_REDIRECTION_TO_2G == pIdCatcherParams->redirectionType)
   {
       gUmtsConfig.redirectionInfo.gsmRedirectinfo.startingarfcn = 
                               pIdCatcherParams->redirectionInfo.gsmRedirectinfo.startingarfcn;

       gUmtsConfig.redirectionInfo.gsmRedirectinfo.bandIndicator = 
                               pIdCatcherParams->redirectionInfo.gsmRedirectinfo.bandIndicator;
   }
   else if (FXL_UMTS_REDIRECTION_TO_3G == pIdCatcherParams->redirectionType)
   {
       gUmtsConfig.redirectionInfo.dlUarfcn = pIdCatcherParams->redirectionInfo.dlUarfcn;
   }
   else
   {
       memset((fxL3gRedirectionInfo *)&gUmtsConfig.redirectionInfo, 0, 
              sizeof(fxL3gRedirectionInfo));
   }

   gUmtsConfig.cpichTxPwr = pIdCatcherParams->cpichTxPwr;

   /* Fill cellSelQualMeas */
   // Initialized in fillSibCfgParams. removed from here so that change of this parameter if done is not reset.
   //gUmtsConfig.cellSelQualMeas = 0;

   memset((fxL3gRedirectionInfo *)&gUmtsConfig.wlUserRedirectionInfo, 0, 
                  sizeof(fxL3gRedirectionInfo));

#if 0
   {  // Redirection Info for WL User
       /* Fill Redirection Type */
       gUmtsConfig.wlUserRedirectionType = pIdCatcherParams->wlUserRedirectionType;
    
       /* Fill Redirection Info */
       if (FXL_UMTS_REDIRECTION_TO_2G == pIdCatcherParams->wlUserRedirectionType)
       {
           gUmtsConfig.wlUserRedirectionInfo.gsmRedirectinfo.startingarfcn = 
                              pIdCatcherParams->wlUserRedirectionInfo.gsmRedirectinfo.startingarfcn;
    
           gUmtsConfig.wlUserRedirectionInfo.gsmRedirectinfo.bandIndicator = 
                              pIdCatcherParams->wlUserRedirectionInfo.gsmRedirectinfo.bandIndicator;
       }
       else if (FXL_UMTS_REDIRECTION_TO_3G == pIdCatcherParams->wlUserRedirectionType)
       {
           gUmtsConfig.wlUserRedirectionInfo.dlUarfcn = pIdCatcherParams->wlUserRedirectionInfo.dlUarfcn;
       }
       else
       {
           memset((fxL3gRedirectionInfo *)&gUmtsConfig.wlUserRedirectionInfo, 0, 
                  sizeof(fxL3gRedirectionInfo));
       }
   }
#endif

   //Cell reselection parameter configured by user no Auto Selection
   if(gUmtsConfig.cellReselectUsrCfgStatus != 1)
   {
       /* Fill Cell Selection & Reselection Parameters */
       fillCellSelReSelInfoFromScanResult ();
   }

   if (0 != pIdCatcherParams->rejectCauseEnable)
   {
      gUmtsConfig.wlRejectCauseCfgEnable  = 1;
      gUmtsConfig.wlRejectCause           = pIdCatcherParams->rejectCause;
   }
   else
   {
      gUmtsConfig.wlRejectCauseCfgEnable  = 0;
      gUmtsConfig.wlRejectCause           = 0;
   }

   /* Fill emergency call rejection flag */
   gUmtsConfig.enableEmergencyCallRejection = pIdCatcherParams->enableEmergencyRejection;

   /* Fill Emergency call Redirection Type */
   gUmtsConfig.emergencyCallRedirectionType = pIdCatcherParams->emergencyCallRedirectionType;

   /* Fill Emergency call Redirection Info */
   if (FXL_UMTS_REDIRECTION_TO_2G == pIdCatcherParams->emergencyCallRedirectionType)
   {
       gUmtsConfig.emergencyCallRedirectionInfo.gsmRedirectinfo.startingarfcn =
                               pIdCatcherParams->emergencyCallRedirectionInfo.gsmRedirectinfo.startingarfcn;

       gUmtsConfig.emergencyCallRedirectionInfo.gsmRedirectinfo.bandIndicator =
                               pIdCatcherParams->emergencyCallRedirectionInfo.gsmRedirectinfo.bandIndicator;
   }
   else if (FXL_UMTS_REDIRECTION_TO_3G == pIdCatcherParams->emergencyCallRedirectionType)
   {
       gUmtsConfig.emergencyCallRedirectionInfo.dlUarfcn = pIdCatcherParams->emergencyCallRedirectionInfo.dlUarfcn;
   }
   else
   {
       memset((fxL3gRedirectionInfo *)&gUmtsConfig.emergencyCallRedirectionInfo, 0,
              sizeof(fxL3gRedirectionInfo));
   }

   /* Fill pilot_boost_enable flag */
   gUmtsConfig.pilot_boost_enable = pIdCatcherParams->pilot_boost_enable;
   if (true == gUmtsConfig.pilot_boost_enable)
   {
	   gUmtsConfig.sib5Info.pichPwr = -8; //DEF_PICH_Power;
	   gUmtsConfig.sib5Info.aichPwr = -8; //DEF_AICH_Power;
   }
   else
   {
       gUmtsConfig.sib5Info.pichPwr = -5; //DEF_PICH_Power;
       gUmtsConfig.sib5Info.aichPwr = -5; //DEF_AICH_Power;
   }

   /* Fill Rx Gain */
   gUmtsConfig.rxGain = pIdCatcherParams->ulRxGainDb;
   printf("RX GAIN = %d \n",gUmtsConfig.rxGain);
}
/*
int main(int argc, char **argv)
{
    ErrorCode_e    retCode;

    printf("############################################################################\n");
    printf("*\n");
    printf("*                            3G SCANNER AND IDCATCHER V_%ld \n", FXL_SOCKETINTERFACEAPI_VERSION);
    printf(("*\n"));
    printf(("*       (c) FXLynx Technologies Ltd. 2015, All Rights Reserved\n"));
    printf(("*\n"));
    printf(("############################################################################\n"));

    LogInit(WGS3G_LOG_FILE);

    retCode = InitSystem();
    if(retCode != SUCCESS_E)
    {
        DEBUG1(("Initializing Q failed\n"));
        exit (0);
    }

   if (0 != createAndWaitSocketServerInterface ())
   {
       DEBUG1(("External Socket Creation failed\n"));
       exit (0);
   }

   externalSocketMsgHandler();

   return 0;    
} //end main
*/
void* umtsIdCatcher (void* nothing)
{
    unsigned int i = 0, j = 0;
    ErrorCode_e    retCode;

    unsigned int idx = 0;
	
#ifdef CELL_ANTENNA_CHANGE	
    fxL3gBandType bandRet;   
    int activeBand;
#endif
    gUmtsConfig.cellStartStatus   = CELL_START_TRIGGERED_E;
    retCode = InitSystem();
    if(retCode != SUCCESS_E)
    {
        DEBUG1(("Initializing Q failed\n"));
        gUmtsConfig.cellStartStatus   = CELL_START_FAILURE_SENT_E;
        sendStartIdCatcherRsp(1);
        exit (0);
    }

    /* Create the Timer Control Block */
    timerCreate(TCB_SIZE, TCB_RESOLUTION, "Timer Control Block");

    retCode = CreateL1RvcThrd();
    if (retCode != SUCCESS_E) 
    {
    	DEBUG1(("Opening L1 Interface Failed, Exiting...\n"));
        gUmtsConfig.cellStartStatus   = CELL_START_FAILURE_SENT_E;
        sendStartIdCatcherRsp(1);
    	return 1;
    }

#ifdef FXL_3G_TX_JAMMER
    if (TRUE != gUmtsConfig.txJammerEnabled)
    {
#endif
    	printf("=========================================\n");
    	printf("          3G IDCATCHER CONFIGURATION     \n");
    	printf("=========================================\n");

	    printf("Number of PLMN = %d\n", gUmtsConfig.numOfPlmn);
	    for(i = 0; i < gUmtsConfig.numOfPlmn; i++)
	    {
	        printf("PLMN[%d] MCC Length = %d\n", i, gUmtsConfig.plmn[i].mccLength);
	        for (j = 0; j < gUmtsConfig.plmn[i].mccLength; j++)
	        {
	            printf("MCC[%d] = %d ", j, gUmtsConfig.plmn[i].mcc[j]);
	        }
	        printf("\n");

	        printf("PLMN[%d] MNC Length = %d\n", i, gUmtsConfig.plmn[i].mncLength);
	        for (j = 0; j < gUmtsConfig.plmn[i].mncLength; j++)
	        {
	             printf("MNC[%d] = %d ", j, gUmtsConfig.plmn[i].mnc[j]);
	        }
	        printf("\n");
	    }
    	printf("\n");
    	printf("  PSC\t\t= %ld\n", gUmtsConfig.psc);
    	printf("  LAC0\t\t= %ld\n", gUmtsConfig.lac[0]);
    	printf("  LAC1\t\t= %ld\n", gUmtsConfig.lac[1]);
    	printf("  RAC\t\t= %ld\n", gUmtsConfig.rac);
    	printf("  DL_UARFCN\t= %ld\n", gUmtsConfig.dlUarfcn);
		printf("  qQualMin\t= %ld\n", gUmtsConfig.qQualMin);
		printf("  qRxLevMin\t= %ld\n", gUmtsConfig.qRxLevMin);
		printf("  tReselS\t= %ld\n", gUmtsConfig.tReselec);
		printf("  qHystLS\t= %ld\n", gUmtsConfig.qHystLS);
		printf("  qHyst2S\t= %ld\n", gUmtsConfig.qHyst2S);
		printf("  maxUlTxPwr\t= %ld\n", gUmtsConfig.maxUlTxPwr);
    	printf("=========================================\n");
#ifdef FXL_3G_TX_JAMMER
	}
#endif

#ifdef CELL_ANTENNA_CHANGE
        bandRet = CalculateBandUsingUarfcn (gUmtsConfig.dlUarfcn);
        activeBand = calculateBnadNumber (bandRet);
		/* Set the CellAntenna PA */
		char dspType;
		if(TRUE == isItPrimaryDsp())
		{
		    dspType = '1';
		}
		else
		{
		    dspType = '2';
		}
		configureCellAntennaPA(dspType, activeBand, 'i');
#endif

	if(SUCCESS_E != RrcAppCellSmStart())
	{
        sendStartIdCatcherRsp(1);
    }

    InitClContext();

    /*Initialize L2 Context*/
    InitializeL2Context();

    /*----------------------------------------------------------------
     *  Task Scheduler for main thread, PARAM: THREAD_ID.
     *  Main Thread will wait here for ever and process all Message 
     *  send for Main thread in it.
     *---------------------------------------------------------------*/
    TaskSchedulerPerThrd(THRD_ID_STACK_APP_E);

    return (void*)0;   
}

/*
 * ############################################################################
 * Method Name : sendStartIdCatcherRsp
 *   
 * Description : Send Start ID catcher response to external client.
 * 
 * Parameters  : status (0 = success, failure = 1)
 * 
 * Returns     :  None
 * ############################################################################
 */

void sendStartIdCatcherRsp(unsigned int status)
{
    fxL3gStartIdCatcherRsp startRsp;
    printf("Start 3G S/W RSP(%d) ....\n", status);

    startRsp.hdr.msgLength = sizeof(fxL3gStartIdCatcherRsp);
    startRsp.hdr.rat       = FXL_RAT_3G;
    startRsp.hdr.msgType   = FXL_3G_START_IDCATCHER_RSP;
    startRsp.result             = status;

    if (-1 != clientFd)
    {
        if (send(clientFd,&startRsp, sizeof(fxL3gStartIdCatcherRsp), 0) < 0)
        {
            DEBUG1(("Unable to send Message to External Client\n"));
        }
        else
        {
            DEBUGMSG(("Stop Silent call Response is sent to External Client\n"));
        }
    }
    else
    {
        DEBUG1(("Unable to send message to External Client, clientFd = -1\n"));
    }
}
