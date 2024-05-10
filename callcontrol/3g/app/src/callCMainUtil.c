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
 * File Name   : callCMainUtil.c 
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 11/09/2014	Kuldeep S. Chauhan      File Creation
 * 27/09/2014	Ashutosh Samal          Added Radio Link Setup Request
 *############################################################################
 */
 /* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------
 */
#include <stdio.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "errorCode.h"
#include "cmnDs.h"
#include "l1capi_datastruct.h"
#include "callCDefaultParam.h"
#include "callCMainUtil.h"
#include "clContext.h"
#include "umtsCfg.h"
#include "cmnDebug.h"
#include "rrc.h"

static DbgModule_e  DBG_MODULE = app;

extern L1CAPI_Modem_Setup_Request       gModemSetupReq;
extern L1CAPI_Cell_Delete_Request       gCellDeleteReq;
extern L1CAPI_Cell_Setup_Request        gCellSetupReq;
extern L1CAPI_Cell_Reconfig_Request     gCellReconfigReq;
extern L1CAPI_Sccpch_Setup_Request      gSccpchSetupReq;
extern L1CAPI_Prach_Setup_Request       gPrachSetupReq;
extern L1CAPI_Radiolink_Setup_Request   gRadioLinkSetupReq;
extern L1CAPI_Radiolink_DeletionRequest gRadioLinkDeleteReq;
extern L1CAPI_Radiolink_Reconfig_Prepare gRadioLinkReconfPrepReq;
extern L1CAPI_Radiolink_ReconfigCommit   gRadioLinkReconfCommitReq;
extern L1CAPI_Dedicated_Meas_Init_Request gDedicatedMeasInitReq;
extern L1CAPI_Dedicated_Meas_Term_Request gDedicatedMeasTermReq;
extern ClCntxt_t                        gClCntxt;
extern UmtsConfigControlBlock           gUmtsConfig;
extern RrcUeControlBlock                ueControlBlock;
extern fxLTxRxAntennaId                 txAntennaIdPri;
extern fxLTxRxAntennaId                 rxAntennaIdPri;
extern fxLTxRxAntennaId                 txAntennaIdSec;
extern fxLTxRxAntennaId                 rxAntennaIdSec;

/* -----------------------------------------------------
 *                 Utility Functions
 * -----------------------------------------------------*/ 
#if 0
void* memAlloc(uint_32 nBytes)
{
    assert (nBytes);
    void *p = NULL;
    p = malloc(nBytes);
	if (p == NULL)	
    {
       return NULL;
    }
    memset(p, 0, nBytes);
    return p;
}
#endif

ErrorCode_e InitTasks(void)
{
    //ErrorCode_e errorCode;
    /* Dummy Function, Place holder for actual implementation */

    return SUCCESS_E;
} /* End of InitTasks */

ErrorCode_e InitMemPool(void)  
{
    //ErrorCode_e errorCode;
    /* Dummy Function, Place holder for actual implementation */
    // Allocate Memory Pool
    // Initialize Memory Pool - memset
    return SUCCESS_E;
} /* End of InitMemPool */

ErrorCode_e InitMsgQueue(void) 
{
    //ErrorCode_e errorCode;
    /* Dummy Function, Place holder for actual implementation */

    return SUCCESS_E;
} /* End of InitMsgQueue */

ErrorCode_e InitStateMachine(void)
{
    //ErrorCode_e errorCode;
    /* Dummy Function, Place holder for actual implementation */

    return SUCCESS_E;
} /* End of InitStateMachine */

ErrorCode_e InitDfltParam(void)
{
    //ErrorCode_e errorCode;
    /* Dummy Function, Place holder for actual implementation */

    // Initialize all default Parameters

    return SUCCESS_E;
} /* End of InitDfltParam */

ErrorCode_e InitAppClCntxt(void)
{
    //ErrorCode_e errorCode;
    /* Dummy Function, Place holder for actual implementation */

    // Initialize App and Cl context and global data Structures.

    return SUCCESS_E;
} /* End of InitAppClCntxt */

ErrorCode_e InitCfgParam(void)
{
    //ErrorCode_e errorCode;
    /* Dummy Function, Place holder for actual implementation */

    // Read and initialize config param from file or CLI

    return SUCCESS_E;
} /* End of InitCfgParam */

/*
 * This function fills value in ModemSetup. 
 * Currently values are hardcoded, in Future these could be read from file
 */
void FillModemSetupReq(void)
{
   /* Fill Modem Setup Request information */
   gModemSetupReq.bit_mask = 0;

   gModemSetupReq.bit_mask |= mdmsetup_txattn_present;
   gModemSetupReq.txAttn = gUmtsConfig.txAttn & 0xFF;

   gModemSetupReq.bit_mask |= mdmsetup_rxgain_present;
   gModemSetupReq.rxGain = gUmtsConfig.rxGain & 0xFF;

   gModemSetupReq.bit_mask |= mdmsetup_rfport_present;

   if (TRUE == isItPrimaryDsp())
   {
      if (FXL_TX_RX_ANTENNA_ID_1 == txAntennaIdPri)
      {
         gModemSetupReq.txRfPort = 2;
      }
      else
      {
	     gModemSetupReq.txRfPort = 1;
      }

      if (FXL_TX_RX_ANTENNA_ID_1 == rxAntennaIdPri)
      {
         gModemSetupReq.rxRfPort = 2;
      }
      else
      {
	     gModemSetupReq.rxRfPort = 1;
      }
   }
   else
   {
	   if (FXL_TX_RX_ANTENNA_ID_1 == txAntennaIdSec)
	   {
		  gModemSetupReq.txRfPort = 2;
	   }
	   else
	   {
		  gModemSetupReq.txRfPort = 1;
	   }
	   
	   if (FXL_TX_RX_ANTENNA_ID_1 == rxAntennaIdSec)
	   {
		  gModemSetupReq.rxRfPort = 2;
	   }
	   else
	   {
		  gModemSetupReq.rxRfPort = 1;
	   }
   }
} /*End of FillModemSetupReq */

void FillCellDeleteReq(void)
{
   /* Fill the Cell Delete Request information */
   gCellDeleteReq.cId = gUmtsConfig.cellId;

}

/*
 *############################################################################
 * Method Name : clFillPrimaryCPICHInfo
 *
 * Description : This procedure fills Primary CPICH Information.
 *
 * Parameters  : 
 *  pPrimaryCPICHInfo   Poniter to Primary CPICH Information
 *  pCpichParams           Pointer to Primary CPICH Parameters
 *
 * Returns     : 
 *  ROK                    Success case
 *  RFAILED                Failure case
 *############################################################################
 */
void FillPriCPICHInfo ( void)
{

    gCellSetupReq.physDlPCpich.commonPhysicalChannelID = DEF_PCPICHId;

	if (true == gUmtsConfig.pilot_boost_enable)
	{
        gCellSetupReq.physDlPCpich.cpich_Power = 50;
	}
	else
    {
		gCellSetupReq.physDlPCpich.cpich_Power = 30;
	}
	
    gCellSetupReq.physDlPCpich.tSTD_Indicator = L1CAPI_TSTD_INDICATOR_INACTIVE;
}

/*
 *############################################################################
 * Method Name : FillPriSCHInfo
 *
 * Description : This procedure fills the SCH Information.
 *
 * Parameters  : 
 *  pSCHInfo   Poniter to SCH Information
 *  pSchParams    Pointer to SCH Parameters
 *
 * Returns     : 
 *  ROK           Success case
 *  RFAILED       Failure case
 *############################################################################
 */
void FillPriSCHInfo (void)
{
    gCellSetupReq.physDlPSch.commonPhysicalChannelID = DEF_PSCHId;
	
	if(true == gUmtsConfig.pilot_boost_enable)
	{
        gCellSetupReq.physDlPSch.sch_Power = -80;
	}
	else
	{
        gCellSetupReq.physDlPSch.sch_Power = 0;
	}
	
    gCellSetupReq.physDlPSch.tSTD_Indicator = L1CAPI_TSTD_INDICATOR_INACTIVE;
}

void FillSecSCHInfo (void)
{
    gCellSetupReq.physDlSSch.commonPhysicalChannelID = DEF_SSCHId;
	
	if(true == gUmtsConfig.pilot_boost_enable)
	{
        gCellSetupReq.physDlSSch.sch_Power = -80;
	}
	else
	{
	    gCellSetupReq.physDlSSch.sch_Power = 0;
	}
	
    gCellSetupReq.physDlSSch.tSTD_Indicator = L1CAPI_TSTD_INDICATOR_INACTIVE;
}

/*
 *############################################################################
 * Method Name : fillUlUarfcn
 *
 * Description : This procedure fills the UL Uarfcn depending on DL Uarfcn 
 *               configured in config file.
 *
 * Parameters  : None
 *
 * Returns     : None
 *############################################################################
 */
void fillUlUarfcn (void)
{
    /* Band1 */
    if ((gUmtsConfig.dlUarfcn >= 10562) && (gUmtsConfig.dlUarfcn <= 10838))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 950;  
    }
    /* Band2 */
    else if ((gUmtsConfig.dlUarfcn >= 9662) && (gUmtsConfig.dlUarfcn <= 9938))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 400;  
    }
    /* Band3 */
    else if ((gUmtsConfig.dlUarfcn >= 1162) && (gUmtsConfig.dlUarfcn <= 1513))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band4 */
    else if ((gUmtsConfig.dlUarfcn >= 1537) && (gUmtsConfig.dlUarfcn <= 1738))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band5 and Band6 */
    else if ((gUmtsConfig.dlUarfcn >= 4357) && (gUmtsConfig.dlUarfcn <= 4458))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band7 */
    else if ((gUmtsConfig.dlUarfcn >= 2237) && (gUmtsConfig.dlUarfcn <= 2563))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band8 */
    else if ((gUmtsConfig.dlUarfcn >= 2937) && (gUmtsConfig.dlUarfcn <= 3088))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band9 */
    else if ((gUmtsConfig.dlUarfcn >= 9237) && (gUmtsConfig.dlUarfcn <= 9387))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 475;
    }
    /* Band10 */
    else if ((gUmtsConfig.dlUarfcn >= 3112) && (gUmtsConfig.dlUarfcn <= 3388))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band11 */
    else if ((gUmtsConfig.dlUarfcn >= 3712) && (gUmtsConfig.dlUarfcn <= 3787))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band12 */
    else if ((gUmtsConfig.dlUarfcn >= 3842) && (gUmtsConfig.dlUarfcn <= 3903))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band13 */
    else if ((gUmtsConfig.dlUarfcn >= 4017) && (gUmtsConfig.dlUarfcn <= 4043))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band14 */
    else if ((gUmtsConfig.dlUarfcn >= 4117) && (gUmtsConfig.dlUarfcn <= 4143))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band19 */
    else if ((gUmtsConfig.dlUarfcn >= 712) && (gUmtsConfig.dlUarfcn <= 763))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 400;
    }
    /* Band20 */
    else if ((gUmtsConfig.dlUarfcn >= 4512) && (gUmtsConfig.dlUarfcn <= 4638))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band21 */
    else if ((gUmtsConfig.dlUarfcn >= 862) && (gUmtsConfig.dlUarfcn <= 912))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 400;
    }
    /* Band22 */
    else if ((gUmtsConfig.dlUarfcn >= 4662) && (gUmtsConfig.dlUarfcn <= 5038))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band25 */
    else if ((gUmtsConfig.dlUarfcn >= 5112) && (gUmtsConfig.dlUarfcn <= 5413))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band26 */
    else if ((gUmtsConfig.dlUarfcn >= 5762) && (gUmtsConfig.dlUarfcn <= 5913))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band2 Additional */
    else if ((gUmtsConfig.dlUarfcn == 412) || (gUmtsConfig.dlUarfcn == 437) ||
             (gUmtsConfig.dlUarfcn == 462) || (gUmtsConfig.dlUarfcn == 487) ||
             (gUmtsConfig.dlUarfcn == 512) || (gUmtsConfig.dlUarfcn == 537) ||
             (gUmtsConfig.dlUarfcn == 562) || (gUmtsConfig.dlUarfcn == 587) ||
             (gUmtsConfig.dlUarfcn == 612) || (gUmtsConfig.dlUarfcn == 637) ||
             (gUmtsConfig.dlUarfcn == 662) || (gUmtsConfig.dlUarfcn == 687))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 400;  
    }
    /* Band5 and Band6 Additional */
    else if ((gUmtsConfig.dlUarfcn == 1007) || (gUmtsConfig.dlUarfcn == 1012) ||
             (gUmtsConfig.dlUarfcn == 1032) || (gUmtsConfig.dlUarfcn == 1037) ||
             (gUmtsConfig.dlUarfcn == 1062) || (gUmtsConfig.dlUarfcn == 1087))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band4 Additional */
    else if ((gUmtsConfig.dlUarfcn == 1887) || (gUmtsConfig.dlUarfcn == 1912) ||
             (gUmtsConfig.dlUarfcn == 1937) || (gUmtsConfig.dlUarfcn == 1962) ||
             (gUmtsConfig.dlUarfcn == 1987) || (gUmtsConfig.dlUarfcn == 2012) ||
	     (gUmtsConfig.dlUarfcn == 2037) || (gUmtsConfig.dlUarfcn == 2062) ||
	     (gUmtsConfig.dlUarfcn == 2087))
    {
       gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band7 Additional */
    else if ((gUmtsConfig.dlUarfcn == 2587) || (gUmtsConfig.dlUarfcn == 2612)||    
             (gUmtsConfig.dlUarfcn == 2637) || (gUmtsConfig.dlUarfcn == 2662)||
             (gUmtsConfig.dlUarfcn == 2687) || (gUmtsConfig.dlUarfcn == 2712)||
             (gUmtsConfig.dlUarfcn == 2737) || (gUmtsConfig.dlUarfcn == 2762)||
             (gUmtsConfig.dlUarfcn == 2787) || (gUmtsConfig.dlUarfcn == 2812)||
             (gUmtsConfig.dlUarfcn == 2837) || (gUmtsConfig.dlUarfcn == 2862)||
             (gUmtsConfig.dlUarfcn == 2887) || (gUmtsConfig.dlUarfcn == 2912))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band10 Additional */    
    else if ((gUmtsConfig.dlUarfcn == 3412) || (gUmtsConfig.dlUarfcn == 3437)||       
             (gUmtsConfig.dlUarfcn == 3462) || (gUmtsConfig.dlUarfcn == 3487)||
             (gUmtsConfig.dlUarfcn == 3512) || (gUmtsConfig.dlUarfcn == 3537)||
             (gUmtsConfig.dlUarfcn == 3562) || (gUmtsConfig.dlUarfcn == 3587)||
             (gUmtsConfig.dlUarfcn == 3612) || (gUmtsConfig.dlUarfcn == 3637)||
             (gUmtsConfig.dlUarfcn == 3662) || (gUmtsConfig.dlUarfcn == 3687))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band12 Additional */
    else if ((gUmtsConfig.dlUarfcn == 3932) || (gUmtsConfig.dlUarfcn == 3957)|| 
             (gUmtsConfig.dlUarfcn == 3962) || (gUmtsConfig.dlUarfcn == 3987)||
             (gUmtsConfig.dlUarfcn == 3992))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band13 Additional */ 
    else if ((gUmtsConfig.dlUarfcn == 4067) || (gUmtsConfig.dlUarfcn == 4092))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band14 Additional */
    else if ((gUmtsConfig.dlUarfcn == 4167) || (gUmtsConfig.dlUarfcn == 4192))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band19 Additional */
    else if ((gUmtsConfig.dlUarfcn == 787) || (gUmtsConfig.dlUarfcn == 812) ||
             (gUmtsConfig.dlUarfcn == 837))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 400;
    }
    /* Band25 Additional */
    else if ((gUmtsConfig.dlUarfcn == 6292) || (gUmtsConfig.dlUarfcn == 6317)||    
             (gUmtsConfig.dlUarfcn == 6342) || (gUmtsConfig.dlUarfcn == 6367)||
             (gUmtsConfig.dlUarfcn == 6392) || (gUmtsConfig.dlUarfcn == 6417)||
             (gUmtsConfig.dlUarfcn == 6442) || (gUmtsConfig.dlUarfcn == 6467)||
             (gUmtsConfig.dlUarfcn == 6492) || (gUmtsConfig.dlUarfcn == 6517)||
             (gUmtsConfig.dlUarfcn == 6542) || (gUmtsConfig.dlUarfcn == 6567)||
             (gUmtsConfig.dlUarfcn == 6592))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }
    /* Band26 Additional */
    else if ((gUmtsConfig.dlUarfcn == 5937) || (gUmtsConfig.dlUarfcn == 5962)||      
             (gUmtsConfig.dlUarfcn == 5987) || (gUmtsConfig.dlUarfcn == 5992)||
             (gUmtsConfig.dlUarfcn == 6012) || (gUmtsConfig.dlUarfcn == 6017)||
             (gUmtsConfig.dlUarfcn == 6037) || (gUmtsConfig.dlUarfcn == 6042)||
             (gUmtsConfig.dlUarfcn == 6062) || (gUmtsConfig.dlUarfcn == 6067)||
             (gUmtsConfig.dlUarfcn == 6087))
    {
        gCellSetupReq.cellInfo.uarfcnUl = gUmtsConfig.dlUarfcn - 225;
    }     
    else
    {
         gCellSetupReq.cellInfo.uarfcnUl = 9788;
         gUmtsConfig.dlUarfcn = 10738;
    }

    DEBUGMSG(("UL Uarfcn = %ld DL Uarfcn = %ld in Cell Setup Req\n", 
           gCellSetupReq.cellInfo.uarfcnUl, gUmtsConfig.dlUarfcn));
}

/*
 *############################################################################
 * Method Name : FillCellInfo
 *
 * Description : This procedure fills the Cell Information.
 *
 * Parameters  : 
 *  refPtr        Pointer to the buffer 
 *  pCellInfo  Poniter to Cell Information
 *  pCellParams   Pointer to Cell Parameters
 *
 * Returns     : 
 *  ROK           Success case
 *  RFAILED       Failure case
 *############################################################################
 */
void FillCellInfo (void)
{
   gCellSetupReq.cellInfo.bit_mask               = 0;
   gCellSetupReq.cellInfo.cId                    = gUmtsConfig.cellId;
   gCellSetupReq.cellInfo.localCellId            = DEF_LocalCellId;
   gCellSetupReq.cellInfo.tCell                  = L1CAPI_T_CELL_V0; /* 0 */

   fillUlUarfcn ();
   gCellSetupReq.cellInfo.uarfcnDl               = gUmtsConfig.dlUarfcn;
   gCellSetupReq.cellInfo.maxTxPower             = 100;
   gCellSetupReq.cellInfo.priScramCode           = gUmtsConfig.psc;
   gCellSetupReq.cellInfo.syncConfig.nInSyncInd  = DEF_NumInSyncEvnt;
   gCellSetupReq.cellInfo.syncConfig.nOutSyncInd = DEF_NumOutSyncEvnt; 
   gCellSetupReq.cellInfo.syncConfig.tRlFailure  = DEF_TimeRlFailure; 
   gCellSetupReq.cellInfo.dlTpc01Count           = DEF_DLTPC01;

   gCellSetupReq.cellInfo.ptrClLoopTimingAdjMode = 
                                (L1CAPI_Closedlooptimingadjustmentmode *) malloc(sizeof(L1CAPI_Closedlooptimingadjustmentmode));

   memset(gCellSetupReq.cellInfo.ptrClLoopTimingAdjMode,0, sizeof(L1CAPI_Closedlooptimingadjustmentmode));
   gCellSetupReq.cellInfo.bit_mask |= clLoopTimingAdjMode_present;
   *(gCellSetupReq.cellInfo.ptrClLoopTimingAdjMode) = L1CAPI_ADJ_1_SLOT;

   gCellSetupReq.cellInfo.pwrRaiseLimit    = DEF_PowerRaiseLimit;
   gCellSetupReq.cellInfo.dlPwrAvrgWinSize = DEF_DLAveragingWindowSize;

}

void cleanMemCellSetupReq (void)
{
    if (NULL != gCellSetupReq.cellInfo.ptrClLoopTimingAdjMode)
    {
        free (gCellSetupReq.cellInfo.ptrClLoopTimingAdjMode);
        gCellSetupReq.cellInfo.ptrClLoopTimingAdjMode = NULL;
    }
}

void FillCellSetupReq(void)
{

    FillCellInfo();
 
    FillPriSCHInfo();

    FillSecSCHInfo();

    FillPriCPICHInfo();

    gCellSetupReq.nSCPich = DEF_NumSCPICH;
    gCellSetupReq.physDlPCcpch.commonPhysicalChannelID = DEF_PCCPCHId; 
    gCellSetupReq.physDlPCcpch.sTTD_Indicator = 1;
    gCellSetupReq.trchCommonDlBch.commonTransportChannelID = DEF_BCHId; 

	if(true == gUmtsConfig.pilot_boost_enable)
	{
        gCellSetupReq.trchCommonDlBch.bCH_Power = -80;
	}
	else
	{
        gCellSetupReq.trchCommonDlBch.bCH_Power = -50;
	}
                                          
}

void fillSCCPCHPhyInfo(void)
{
   gSccpchSetupReq.physDlSCcpch.bit_mask = 0x00;

   gSccpchSetupReq.physDlSCcpch.commonPhysicalChannelID = DEF_SCCPCH_CommonPhysId;

   gSccpchSetupReq.physDlSCcpch.sCCPCH_Chip_Offset = DEF_SCCPCH_Offset; 

   gSccpchSetupReq.physDlSCcpch.bit_mask |= dl_ScramblingCode_present;

   gSccpchSetupReq.physDlSCcpch.dl_ScramblingCode = DEF_SCCPCH_ScramblingCode;
   gSccpchSetupReq.physDlSCcpch.dL_ChannelisationCodeNumber = DEF_SCCPCH_ChannelisationCode;
   gSccpchSetupReq.physDlSCcpch.sCCPCH_SlotFormat = DEF_SCCPCH_SlotFormat;

   gSccpchSetupReq.physDlSCcpch.bit_mask |= sccpch_tFCI_present;

   gSccpchSetupReq.physDlSCcpch.tFCI_Presence = 1;

   gSccpchSetupReq.physDlSCcpch.multiplexingPosition = L1CAPI_FLEXIBLE;

   gSccpchSetupReq.physDlSCcpch.pO1_ForTFCI_Bits = (L1CAPI_PowerOffset)DEF_SCCPCH_PowerOffset1;
   gSccpchSetupReq.physDlSCcpch.pO3_ForPilotBits = (L1CAPI_PowerOffset)DEF_SCCPCH_PowerOffset3;
   gSccpchSetupReq.physDlSCcpch.sTTD_Indicator = L1CAPI_STTD_INDICATOR_INACTIVE;
}

void fillRlTfcsInfo(void)
{
   U8 idx;
   gSccpchSetupReq.cctrchDlTfc.tfcsSize = DEF_FACH_PCH_NumberOfTFCS;
   gSccpchSetupReq.cctrchDlTfc.ptrCctrchTfc  = 
                                (L1CAPI_TFCS_Info_Item *) malloc(DEF_FACH_PCH_NumberOfTFCS * sizeof(L1CAPI_TFCS_Info_Item));

   memset(gSccpchSetupReq.cctrchDlTfc.ptrCctrchTfc, 0, DEF_FACH_PCH_NumberOfTFCS * sizeof(L1CAPI_TFCS_Info_Item));

   for(idx = 0;idx < DEF_FACH_PCH_NumberOfTFCS; idx++)
   {
      gSccpchSetupReq.cctrchDlTfc.ptrCctrchTfc[idx].bit_mask = 0;
      gSccpchSetupReq.cctrchDlTfc.ptrCctrchTfc[idx].cTFC = DEF_FACH_PCH_CTFC[idx];
   }

}

void fillSCCPCHTrchInfo(void)
{
   L1CAPI_TFS_DynamicPartListItem *ptrTransFormatFach0;
   L1CAPI_TFS_DynamicPartListItem *ptrTransFormatFach1;

   gSccpchSetupReq.ptrTrchDlFach  = 
                                (L1CAPI_SCCPCH_Trch_Info *) malloc(gSccpchSetupReq.nFach * sizeof(L1CAPI_SCCPCH_Trch_Info));
   memset(gSccpchSetupReq.ptrTrchDlFach, 0, gSccpchSetupReq.nFach * sizeof(L1CAPI_SCCPCH_Trch_Info));

   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.tfCount = 3;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.tfCount = 2;

   ptrTransFormatFach0 = (L1CAPI_TFS_DynamicPartListItem *) malloc(gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.tfCount * sizeof(L1CAPI_TFS_DynamicPartListItem));
   ptrTransFormatFach1 = (L1CAPI_TFS_DynamicPartListItem *) malloc(gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.tfCount * sizeof(L1CAPI_TFS_DynamicPartListItem));
   memset(ptrTransFormatFach0, 0, gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.tfCount * sizeof(L1CAPI_TFS_DynamicPartListItem));
   memset(ptrTransFormatFach1, 0, gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.tfCount * sizeof(L1CAPI_TFS_DynamicPartListItem));


   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.ptrTransFormat  = ptrTransFormatFach0;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.ptrTransFormat  = ptrTransFormatFach1;

   gSccpchSetupReq.ptrTrchDlFach[0].commonTransportChannelID =
                   (L1CAPI_CommonTranspChannelID)2;

   gSccpchSetupReq.ptrTrchDlFach[1].commonTransportChannelID =
                   (L1CAPI_CommonTranspChannelID)3;

   if(true == gUmtsConfig.pilot_boost_enable)
   {
       gSccpchSetupReq.ptrTrchDlFach[0].maxFACH_PCH_Power = -40;
       gSccpchSetupReq.ptrTrchDlFach[1].maxFACH_PCH_Power = -40;
   }
   else
   {
       gSccpchSetupReq.ptrTrchDlFach[0].maxFACH_PCH_Power = -4;
       gSccpchSetupReq.ptrTrchDlFach[1].maxFACH_PCH_Power = -4;
   }

   gSccpchSetupReq.ptrTrchDlFach[0].toAWS = (L1CAPI_ToAWS)60;
   gSccpchSetupReq.ptrTrchDlFach[1].toAWS = (L1CAPI_ToAWS)0xA0;
  
   gSccpchSetupReq.ptrTrchDlFach[0].toAWE = (L1CAPI_ToAWE)0;
   gSccpchSetupReq.ptrTrchDlFach[1].toAWE = (L1CAPI_ToAWE)0x28;


   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.tti = L1CAPI_MSEC_10;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.tti = L1CAPI_MSEC_10;
   
   
   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.crcType = L1CAPI_TFS_CRC_SIZE_V16;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.crcType = L1CAPI_TFS_CRC_SIZE_V16;

   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.codingType = L1CAPI_CONV_CODING;
   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.codingRate = L1CAPI_HALF_RATE ;

   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.codingType = L1CAPI_TURBO_CODING;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.codingRate = L1CAPI_ONETHIRD_RATE ;

   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.rmAttrib = 0xdb;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.rmAttrib = 0x81;

   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.ptrTransFormat[0].nrOfTransportBlocks = 0;
   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.ptrTransFormat[0].transportBlockSize = 0xa8;
   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.ptrTransFormat[1].nrOfTransportBlocks = 1;
   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.ptrTransFormat[1].transportBlockSize = 0xa8;
   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.ptrTransFormat[2].nrOfTransportBlocks = 2;
   gSccpchSetupReq.ptrTrchDlFach[0].tfsDL.ptrTransFormat[2].transportBlockSize = 0xa8;

   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.ptrTransFormat[0].nrOfTransportBlocks = 0;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.ptrTransFormat[0].transportBlockSize = 0x168;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.ptrTransFormat[1].nrOfTransportBlocks = 1;
   gSccpchSetupReq.ptrTrchDlFach[1].tfsDL.ptrTransFormat[1].transportBlockSize = 0x168;

}

void fillPCHInfo(void)
{
   gSccpchSetupReq.ptrTrchDlPch->commonParameters.commonTransportChannelID =
                   (L1CAPI_CommonTranspChannelID)DEF_PCH_CommonTRCHId;

   if(true == gUmtsConfig.pilot_boost_enable)
   {
       gSccpchSetupReq.ptrTrchDlPch->commonParameters.maxFACH_PCH_Power = -40;
   }
   else
   {
       gSccpchSetupReq.ptrTrchDlPch->commonParameters.maxFACH_PCH_Power = (L1CAPI_DL_Power)-20;
   }

   gSccpchSetupReq.ptrTrchDlPch->commonParameters.toAWS = (L1CAPI_ToAWS)DEF_PCH_toAWS;
   gSccpchSetupReq.ptrTrchDlPch->commonParameters.toAWE = (L1CAPI_ToAWE)DEF_PCH_toAWE;

   gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.tfCount = DEF_PCH_NumberOfTFS;
   gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.tti = L1CAPI_MSEC_10;
   gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.crcType = L1CAPI_TFS_CRC_SIZE_V16;
   gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.codingType = L1CAPI_CONV_CODING;
   gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.codingRate = L1CAPI_HALF_RATE;

   gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.rmAttrib = DEF_PCH_RateMatchingAttribute;

   gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat  = 
                                (L1CAPI_TFS_DynamicPartListItem *) malloc(DEF_PCH_NumberOfTFS * sizeof(L1CAPI_TFS_DynamicPartListItem));

   memset(gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat, 0, DEF_PCH_NumberOfTFS * sizeof(L1CAPI_TFS_DynamicPartListItem));

  gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat[0].nrOfTransportBlocks = 0;
  gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat[1].nrOfTransportBlocks = 1;
  gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat[0].transportBlockSize = DEF_PCH_BlockSize[0];
  gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat[1].transportBlockSize = DEF_PCH_BlockSize[1];
}

void fillPICHInfo(void)
{
  gSccpchSetupReq.ptrTrchDlPch->pichPhys.commonPhysicalChannelID =
                                       (L1CAPI_CommonPhyChannelID)DEF_PICH_CommonPhysId;

  gSccpchSetupReq.ptrTrchDlPch->pichPhys.dl_ChannelisationCodeNumber = 
                                       (L1CAPI_DL_ChannelCodeNumber)DEF_PICH_ChannelisationCode;

  //gSccpchSetupReq.ptrTrchDlPch->pichPhys.pICH_Power = (L1CAPI_PICH_Power)DEF_PICH_Power;//-5;
  gSccpchSetupReq.ptrTrchDlPch->pichPhys.pICH_Power = gUmtsConfig.sib5Info.pichPwr; //-5;
  gSccpchSetupReq.ptrTrchDlPch->pichPhys.pICH_Mode = L1CAPI_PichMode_v18;                                     
  
  gSccpchSetupReq.ptrTrchDlPch->pichPhys.sTTD_Indicator = L1CAPI_STTD_INDICATOR_INACTIVE; 
}

void cleanMemSccpchSetupRequest(void)
{
    unsigned int idx = 0;

    if (NULL != gSccpchSetupReq.cctrchDlTfc.ptrCctrchTfc)
    {
        for (idx = 0; idx < gSccpchSetupReq.nFach; idx++)
        {
            if (NULL != gSccpchSetupReq.ptrTrchDlFach[idx].tfsDL.ptrTransFormat)
            {
                free (gSccpchSetupReq.ptrTrchDlFach[idx].tfsDL.ptrTransFormat);
                gSccpchSetupReq.ptrTrchDlFach[idx].tfsDL.ptrTransFormat = NULL;
            }
        }

        free (gSccpchSetupReq.cctrchDlTfc.ptrCctrchTfc);
        gSccpchSetupReq.cctrchDlTfc.ptrCctrchTfc = NULL;
    }

    if (NULL != gSccpchSetupReq.ptrTrchDlFach)
    {
        free (gSccpchSetupReq.ptrTrchDlFach);
        gSccpchSetupReq.ptrTrchDlFach = NULL;
    }

    if (NULL != gSccpchSetupReq.ptrTrchDlPch)
    {
        if (NULL != gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat)
        {
            free (gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat);
            gSccpchSetupReq.ptrTrchDlPch->commonParameters.tfsDL.ptrTransFormat = NULL;
        }

        free (gSccpchSetupReq.ptrTrchDlPch);
        gSccpchSetupReq.ptrTrchDlPch = NULL;
    }
}

void fillSccpchSetupRequest(void)
{
   gSccpchSetupReq.bit_mask = 0x00;    

   gSccpchSetupReq.cmnInfo.cId = gUmtsConfig.cellId;

   gSccpchSetupReq.nFach = 2; /* Number of FACH channel per cell. read from config file */

   fillSCCPCHPhyInfo();

   fillRlTfcsInfo();

   fillSCCPCHTrchInfo();
 
   gSccpchSetupReq.bit_mask |= trchCommonDlPch_present;

   gSccpchSetupReq.ptrTrchDlPch  = 
                                (L1CAPI_PCH_Info *) malloc(sizeof(L1CAPI_PCH_Info));

   memset(gSccpchSetupReq.ptrTrchDlPch, 0, sizeof(L1CAPI_PCH_Info));

   fillPCHInfo();

   fillPICHInfo();

}

/*---------------------------------------------------------------------------
 * Common UL Transport Channel: PRACH Configuration  
 *---------------------------------------------------------------------------*/
/*
 * Fill L1CAPI_Prach_Phy_Info      physUlPrach
*/
void fillPrachPhysUlPrach(void)
{
   U16 sfIdx = 0;
   gPrachSetupReq.physUlPrach.commonPhysicalChannelID   = DEF_PRACH_CommonPhysId;
   gPrachSetupReq.physUlPrach.scramblingCodeNumber      = DEF_PRACH_ScramblingCode;
   gPrachSetupReq.physUlPrach.preambleSignatures        = DEF_PRACH_PreambleSignatures;
   gPrachSetupReq.physUlPrach.allowedSFCount            = DEF_PRACH_AllowedSFCount;
   for(sfIdx = 0; sfIdx < DEF_PRACH_AllowedSFCount; sfIdx++){
      gPrachSetupReq.physUlPrach.allowedSlotFormatInfo[sfIdx] = DEF_PRACH_SlotFormats[sfIdx];
   }
   gPrachSetupReq.physUlPrach.rACH_SubChannelNumbers    = DEF_PRACH_SubChannelNumbers;
   gPrachSetupReq.physUlPrach.ul_punctureLimit          = DEF_PRACH_PunctureLimit;
   gPrachSetupReq.physUlPrach.preambleThreshold         = DEF_PRACH_PreambleThreshold; 
}

/*
 * Fill L1CAPI_AICH_Phy_Info       physDlAich;
 */
void fillPrachPhysDlAich(void)
{
   gPrachSetupReq.physDlAich.commonPhysicalChannelID     = DEF_AICH_CommonPhysId;
   gPrachSetupReq.physDlAich.aICH_TransmissionTiming     = DEF_AICH_Timing;
   gPrachSetupReq.physDlAich.dl_ChannelisationCodeNumber = DEF_AICH_ChannelisationCode;
   /*TBD Reaad from Config file, check if need to change the value*/
   //gPrachSetupReq.physDlAich.aICH_Power                  = DEF_AICH_Power;//-5;
   gPrachSetupReq.physDlAich.aICH_Power                  = gUmtsConfig.sib5Info.aichPwr;
   gPrachSetupReq.physDlAich.sTTD_Indicator              = L1CAPI_STTD_INDICATOR_INACTIVE;
}

/*
 * Fill L1CAPI_TFCS_Info           cctrchUlTfc;
 */
void fillPrachCctrchUlTfc(void)
{
   L1CAPI_TFCS_Info_Item *ptrCctrchTfc = NULL;

   /* Allocate memory to store L1CAPI_TFCS_Info_Item, and ptrCctrchTfc.ptrTFCBeta */ 
   ptrCctrchTfc              = (L1CAPI_TFCS_Info_Item *) malloc(DEF_RACH_NumberOfTFCS * sizeof(L1CAPI_TFCS_Info_Item ));
   memset(ptrCctrchTfc, 0, DEF_RACH_NumberOfTFCS * sizeof(L1CAPI_TFCS_Info_Item));

   gPrachSetupReq.cctrchUlTfc.tfcsSize                   =  DEF_RACH_NumberOfTFCS;
   gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc               =  ptrCctrchTfc;

   gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc[0].ptrTFCBeta   = (L1CAPI_TFC_Beta *) malloc( sizeof(L1CAPI_TFC_Beta ));
   memset(gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc[0].ptrTFCBeta,   0, sizeof(L1CAPI_TFC_Beta ));

   ptrCctrchTfc[0].cTFC                          = DEF_RACH_CTFC[0]; 
   ptrCctrchTfc[0].bit_mask                     |= tFC_Beta_present;

   ptrCctrchTfc[0].ptrTFCBeta->gainFactor        = L1CAPI_SIGNALLED_GF;
   ptrCctrchTfc[0].ptrTFCBeta->betaC             = DEF_RACH_BetaC[0];
   ptrCctrchTfc[0].ptrTFCBeta->betaD             = DEF_RACH_BetaD[0];
   ptrCctrchTfc[0].ptrTFCBeta->refTFCNumber      = DEF_RACH_ReferenceID[0];
}

/*
 *  Fill L1CAPI_Prach_Trch_Info     trchUlPrach;
 */
void fillPrachUlTrch(void)
{
   U16 tfsIdx = 0;
   L1CAPI_TFS_DynamicPartListItem          *ptrTransFormat;

   gPrachSetupReq.trchUlPrach.commonTransportChannelID   = DEF_RACH_CommonTRCHId;
   gPrachSetupReq.trchUlPrach.tfsUL.tfCount              = DEF_RACH_NumberOfTFS;
   gPrachSetupReq.trchUlPrach.tfsUL.tti                  = L1CAPI_MSEC_20; 
   gPrachSetupReq.trchUlPrach.tfsUL.crcType              = L1CAPI_TFS_CRC_SIZE_V16;
   gPrachSetupReq.trchUlPrach.tfsUL.codingType           = L1CAPI_CONV_CODING;
   gPrachSetupReq.trchUlPrach.tfsUL.codingRate           = L1CAPI_HALF_RATE;
   gPrachSetupReq.trchUlPrach.tfsUL.rmAttrib             = DEF_RACH_RateMatchingAttribute; 

   ptrTransFormat = (L1CAPI_TFS_DynamicPartListItem *) malloc(DEF_RACH_NumberOfTFS * sizeof(L1CAPI_TFS_DynamicPartListItem ));
   memset(ptrTransFormat,   0, DEF_RACH_NumberOfTFS * sizeof(L1CAPI_TFS_DynamicPartListItem ));

   gPrachSetupReq.trchUlPrach.tfsUL.ptrTransFormat       = ptrTransFormat;

   for(tfsIdx = 0; tfsIdx < DEF_RACH_NumberOfTFS; tfsIdx++)
   {
      ptrTransFormat[tfsIdx].nrOfTransportBlocks         = DEF_RACH_NumberOfBlocks[tfsIdx];
      ptrTransFormat[tfsIdx].transportBlockSize          = DEF_RACH_BlockSize[tfsIdx];
   }
}

void cleanMemPrachSetupRequest (void)
{
    if (NULL != gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc)
    {
        if (NULL != gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc[0].ptrTFCBeta)
        {
            free (gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc[0].ptrTFCBeta);
            gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc[0].ptrTFCBeta = NULL;
        }

        free (gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc);
        gPrachSetupReq.cctrchUlTfc.ptrCctrchTfc = NULL;
    }

    if (NULL != gPrachSetupReq.trchUlPrach.tfsUL.ptrTransFormat)
    {
        free (gPrachSetupReq.trchUlPrach.tfsUL.ptrTransFormat);
        gPrachSetupReq.trchUlPrach.tfsUL.ptrTransFormat = NULL;
    }
}

void fillPrachSetupRequest(void)
{
   // Fill L1CAPI_CommonInfo          cmnInfo;
   gPrachSetupReq.cmnInfo.cId = gUmtsConfig.cellId;

   fillPrachPhysUlPrach();
   fillPrachPhysDlAich();
   fillPrachCctrchUlTfc();
   fillPrachUlTrch();

}

/*
 *############################################################################
 * Method Name : fillRadioLinkDeleteRequest
 *
 * Description : This procedure fills the Radio Link Delete Request.
 *
 * Parameters  : None
 *
 * Returns     : None
 *############################################################################
 */
void fillRadioLinkDeleteRequest (unsigned int rlId)
{
   /* Initialize the Radio Link Delete Request */
   memset((L1CAPI_Radiolink_DeletionRequest *)&gRadioLinkDeleteReq, 0, 
          sizeof(L1CAPI_Radiolink_DeletionRequest));

   gRadioLinkDeleteReq.NodeBComContext = gClCntxt.clUeCntxt[rlId].nodebCmnCntxt;
   gRadioLinkDeleteReq.rlCount = 1;
   gRadioLinkDeleteReq.pRl_ID = 
                   (L1CAPI_Radiolink_ID *)malloc(sizeof(L1CAPI_Radiolink_ID));
   gRadioLinkDeleteReq.pRl_ID[0] = rlId;
}

void cleanMemRadioLinkDeleteRequest (void)
{
   if (NULL != gRadioLinkDeleteReq.pRl_ID)
   {
       free (gRadioLinkDeleteReq.pRl_ID);
       gRadioLinkDeleteReq.pRl_ID = NULL;
   }
}

/*
 *############################################################################
 * Method Name : cleanMemRadioLinkReconfigPrepRequest
 *
 * Description : This procedure cleans memory allocated for Radio Link Reconfig 
 *               Prepare Request.
 *
 * Parameters  : None
 *
 * Returns     : None
 *############################################################################
 */
void cleanMemRadioLinkReconfigPrepRequest (void)
{
    if (NULL != gRadioLinkReconfPrepReq.ptrRlInfo)
    {
        free(gRadioLinkReconfPrepReq.ptrRlInfo);
        gRadioLinkReconfPrepReq.ptrRlInfo = NULL;
    }

    if (NULL != gRadioLinkReconfPrepReq.ptrPhysUldpch)
    {
        free(gRadioLinkReconfPrepReq.ptrPhysUldpch);
        gRadioLinkReconfPrepReq.ptrPhysUldpch = NULL;
    }
}

/*
 *############################################################################
 * Method Name : fillRadioLinkReconfigPrepRequest
 *
 * Description : This procedure fills the Radio Link Reconfig Prepare Request.
 *
 * Parameters  : 
 *               Radio Link Prepare Info
 *
 * Returns     : None
 *############################################################################
 */
void fillRadioLinkReconfigPrepRequest (RadioLinkReconfigPrepReqInfo *pRLReconfPrepReq)
{
   /* Initialize the Radio Link Reconfig Prepare Request */
   memset((L1CAPI_Radiolink_Reconfig_Prepare *)&gRadioLinkReconfPrepReq, 0, 
          sizeof(L1CAPI_Radiolink_Reconfig_Prepare));

   gRadioLinkReconfPrepReq.bit_mask = 0x00;

   /* Fill Common Context Info */
   gRadioLinkReconfPrepReq.NodeBComContext = gClCntxt.clUeCntxt[pRLReconfPrepReq->rlId].nodebCmnCntxt;
   gRadioLinkReconfPrepReq.rl_reconfig_comContextInfo.rlCount = 1;
   gRadioLinkReconfPrepReq.rl_reconfig_comContextInfo.coorTrchCountAdd = 0;
   gRadioLinkReconfPrepReq.rl_reconfig_comContextInfo.coorTrchCountModify = 0;
   gRadioLinkReconfPrepReq.rl_reconfig_comContextInfo.trchCountDelete = 0;
   gRadioLinkReconfPrepReq.rl_reconfig_comContextInfo.tgpsCount = 0;

   /* Fill RL Info */
   gRadioLinkReconfPrepReq.ptrRlInfo = 
               (L1CAPI_Radiolink_Reconfig_params *)malloc(sizeof(L1CAPI_Radiolink_Reconfig_params)); 
   memset((L1CAPI_Radiolink_Reconfig_params *)gRadioLinkReconfPrepReq.ptrRlInfo, 0,
          sizeof(L1CAPI_Radiolink_Reconfig_params));                                          

   gRadioLinkReconfPrepReq.ptrRlInfo->bit_mask = 0x00;
   gRadioLinkReconfPrepReq.ptrRlInfo->dlCodeCount = 0;
   gRadioLinkReconfPrepReq.ptrRlInfo->rL_ID = pRLReconfPrepReq->rlId;
    
   gRadioLinkReconfPrepReq.ptrTrchDchDelete = NULL;
   gRadioLinkReconfPrepReq.ptrTrchDchAdd = NULL;
   gRadioLinkReconfPrepReq.PtrTrchDchModify = NULL;
   gRadioLinkReconfPrepReq.ptrPhysDldpch = NULL;

   /* Fill Physical UL DPCH */
   gRadioLinkReconfPrepReq.bit_mask |= rl_Reconfig_physUlDpch_present;
   gRadioLinkReconfPrepReq.ptrPhysUldpch = 
                (L1CAPI_UL_DPCH_PhyInfo_Reconfig *)malloc(sizeof(L1CAPI_UL_DPCH_PhyInfo_Reconfig));
   memset((L1CAPI_UL_DPCH_PhyInfo_Reconfig *)gRadioLinkReconfPrepReq.ptrPhysUldpch, 0,
          sizeof(L1CAPI_UL_DPCH_PhyInfo_Reconfig));

   gRadioLinkReconfPrepReq.ptrPhysUldpch->bit_mask = 0x00;

   gRadioLinkReconfPrepReq.ptrPhysUldpch->bit_mask |= UL_DPCH_Reconfig_UlSIR_present;
   gRadioLinkReconfPrepReq.ptrPhysUldpch->ul_SIR_Target = pRLReconfPrepReq->ulSIRtarget;
   
   gRadioLinkReconfPrepReq.cctrchDlTfc.tfcsSize = 0;
   gRadioLinkReconfPrepReq.cctrchDlTfc.ptrCctrchTfc = NULL;
   gRadioLinkReconfPrepReq.cctrchUlTfc.tfcsSize = 0;
   gRadioLinkReconfPrepReq.cctrchUlTfc.ptrCctrchTfc = NULL;
   gRadioLinkReconfPrepReq.ptrTransGapPattSeqInfo = NULL;
   gRadioLinkReconfPrepReq.ptrHsdsch = NULL;
   gRadioLinkReconfPrepReq.ptrEDchRlExtension = NULL;
}

/*
 *############################################################################
 * Method Name : fillRadioLinkReconfigCommitRequest
 *
 * Description : This procedure fills the Radio Link Reconfig Commit Request.
 *
 * Parameters  : 
 *               Radio Link Id
 *
 * Returns     : None
 *############################################################################
 */
void fillRadioLinkReconfigCommitRequest (unsigned int *pRlId)
{
   /* Initialize the Radio Link Reconfig Prepare Request */
   memset((L1CAPI_Radiolink_ReconfigCommit *)&gRadioLinkReconfCommitReq, 0, 
          sizeof(L1CAPI_Radiolink_ReconfigCommit));

   gRadioLinkReconfCommitReq.bit_mask = 0x00;

   /* Fill Common Context Info */
   gRadioLinkReconfCommitReq.NodeBComContext = gClCntxt.clUeCntxt[*pRlId].nodebCmnCntxt;
   gRadioLinkReconfCommitReq.cfn = (gClCntxt.bfn + 8) & 0xFF;
}

/*
 *############################################################################
 * Method Name : fillRadioLinkSetupRequest
 *
 * Description : This procedure fills the Radio Link Setup Request.
 *
 * Parameters  : None
 *
 * Returns     : None
 *############################################################################
 */
void fillRadioLinkSetupRequest (unsigned int rlId)
{
   int idx = 0;

   /* Initialize the Radio Link Setup Request */
   memset((L1CAPI_Radiolink_Setup_Request *)&gRadioLinkSetupReq, 0, 
          sizeof(L1CAPI_Radiolink_Setup_Request));

   gRadioLinkSetupReq.comContextInfo.rlCount = 1;
   gRadioLinkSetupReq.comContextInfo.coordTrchCount = 1;
   gRadioLinkSetupReq.comContextInfo.tgpsCount = 0;
 
   /* Fill RL Info */ 
   gRadioLinkSetupReq.pRlInfo = 
               (L1CAPI_RadioLink_Info *)malloc(sizeof(L1CAPI_RadioLink_Info)); 
   memset((L1CAPI_RadioLink_Info *)gRadioLinkSetupReq.pRlInfo, 0,
          sizeof(L1CAPI_RadioLink_Info));                                          

   gRadioLinkSetupReq.pRlInfo->bit_mask = 0x00;
   gRadioLinkSetupReq.pRlInfo->dlCodeCount = 1;
   gRadioLinkSetupReq.pRlInfo->rL_ID = rlId;
   gRadioLinkSetupReq.pRlInfo->c_ID  = gUmtsConfig.cellId;
   gRadioLinkSetupReq.pRlInfo->firstRLS_indicator = 1;
   gRadioLinkSetupReq.pRlInfo->frameOffset = 0;
   gRadioLinkSetupReq.pRlInfo->chipOffset  = 0;
   gRadioLinkSetupReq.pRlInfo->bit_mask |= propagationDelay_present;
   gRadioLinkSetupReq.pRlInfo->propagationDelay  = 0;
   gRadioLinkSetupReq.pRlInfo->bit_mask |= diversityControlField_present;
   gRadioLinkSetupReq.pRlInfo->diversityControlField  = L1CAPI_DIV_MAY_COMBINE;
   gRadioLinkSetupReq.pRlInfo->initialDL_transmissionPower  = -20;
   gRadioLinkSetupReq.pRlInfo->maximumDL_power = 30;
   gRadioLinkSetupReq.pRlInfo->minimumDL_power = -120;
   gRadioLinkSetupReq.pRlInfo->bit_mask |= rl_info_transmitDiverIndicator_present;
   gRadioLinkSetupReq.pRlInfo->transmitDiversityIndicator = L1CAPI_TSTD_INDICATOR_INACTIVE;

   gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo =
                  (L1CAPI_DL_CodeInfo *)malloc(sizeof(L1CAPI_DL_CodeInfo));
   memset((L1CAPI_DL_CodeInfo *)gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo, 0,
          sizeof(L1CAPI_DL_CodeInfo));

   gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo->dl_ScramblingCode = DEF_SCCPCH_ScramblingCode;
   // TBD: Different sfIdx for different UEs.
   gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo->dL_ChannelisationCodeNumber = DL_CHANNELISATION_CODE + rlId;
   DEBUGMSG(("dlchannilisationCode num (%d) for rlId(%d)\n", gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo->dL_ChannelisationCodeNumber, rlId));
   gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo->TransGapPatternSequenceCodeInfo = 
                                                              L1CAPI_TX_GAP_NO_CODE_CHANGE;

   /* Fill Coord TRCH DCH Info */
   gRadioLinkSetupReq.ptrCoordTrchDchInfo =
      (L1CAPI_DCH_CoordTrchInfoListItem *)malloc(sizeof(L1CAPI_DCH_CoordTrchInfoListItem)); 
   memset((L1CAPI_DCH_CoordTrchInfoListItem *)gRadioLinkSetupReq.ptrCoordTrchDchInfo, 0,
          sizeof(L1CAPI_DCH_CoordTrchInfoListItem));
   
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->bit_mask = 0x00;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->dchCount = 1;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->bit_mask |= toAws_present;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->toAWS = 160;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->bit_mask |= toAwe_present;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->toAWE = 40;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->bit_mask |= payloadCRC_presenceIndicator_present;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->payloadCRC_PresenceIndicator = 0;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->bit_mask |= ulFpMode_present;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ul_FP_Mode = 0;

   /* Fill DCH Specific Info */
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo =
                                        (L1CAPI_DCH_Info *)malloc(sizeof(L1CAPI_DCH_Info));
   memset((L1CAPI_DCH_Info *)gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo, 0,
          sizeof(L1CAPI_DCH_Info));

   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->bit_mask = 0x00;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->dCH_ID = DCH_ID + rlId;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->qE_Selector = 0;

   /* Fill DL TFS */
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->bit_mask |= tfsDL_present;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL =
                  (L1CAPI_TransportFormatSet *)malloc(sizeof(L1CAPI_TransportFormatSet)); 
   memset((L1CAPI_TransportFormatSet *)gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL,
          0, sizeof(L1CAPI_TransportFormatSet));

   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->tfCount = 2;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->tti = L1CAPI_MSEC_40;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->crcType = L1CAPI_TFS_CRC_SIZE_V16;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->codingType = L1CAPI_CONV_CODING;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->codingRate = L1CAPI_ONETHIRD_RATE;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->rmAttrib = 190;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->ptrTransFormat =
       (L1CAPI_TFS_DynamicPartListItem *)malloc(gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->tfCount * 
                                                sizeof(L1CAPI_TFS_DynamicPartListItem));  
   memset((L1CAPI_TFS_DynamicPartListItem *)gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->ptrTransFormat,
          0, gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->tfCount * sizeof(L1CAPI_TFS_DynamicPartListItem)); 
   for(idx = 0; idx < gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->tfCount; idx++)
   {
      gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->ptrTransFormat[idx].nrOfTransportBlocks = idx;
      gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->ptrTransFormat[idx].transportBlockSize = 148;
   }

   /* Fill UL TFS */
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->bit_mask |= tfsUL_present;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL =
                  (L1CAPI_TransportFormatSet *)malloc(sizeof(L1CAPI_TransportFormatSet)); 
   memset((L1CAPI_TransportFormatSet *)gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL,
          0, sizeof(L1CAPI_TransportFormatSet));

   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->tfCount = 2;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->tti = L1CAPI_MSEC_40;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->crcType = L1CAPI_TFS_CRC_SIZE_V16;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->codingType = L1CAPI_CONV_CODING;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->codingRate = L1CAPI_ONETHIRD_RATE;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->rmAttrib = 190;
   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->ptrTransFormat =
       (L1CAPI_TFS_DynamicPartListItem *)malloc(gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->tfCount * 
                                                sizeof(L1CAPI_TFS_DynamicPartListItem));  
   memset((L1CAPI_TFS_DynamicPartListItem *)gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->ptrTransFormat,
          0, gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->tfCount * sizeof(L1CAPI_TFS_DynamicPartListItem)); 
   for(idx = 0; idx < gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->tfCount; idx++)
   {
      gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->ptrTransFormat[idx].nrOfTransportBlocks = idx;
      gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->ptrTransFormat[idx].transportBlockSize = 148;
   }

   /* Fill Physical DL DPCH */
   gRadioLinkSetupReq.physDlDpch.bit_mask = 0x00;
   gRadioLinkSetupReq.physDlDpch.dl_DPCH_SlotFormat = 5;
   gRadioLinkSetupReq.physDlDpch.bit_mask |= DL_DPCH_RL_Setup_tFCI_present;
   gRadioLinkSetupReq.physDlDpch.tFCI_Presence = 1;

   gRadioLinkSetupReq.physDlDpch.multiplexingPosition = L1CAPI_FIXED;
   gRadioLinkSetupReq.physDlDpch.powerOffsetInformation.pO1_ForTFCI_Bits = 0;
   gRadioLinkSetupReq.physDlDpch.powerOffsetInformation.pO2_ForTPC_Bits  = 0;
   gRadioLinkSetupReq.physDlDpch.powerOffsetInformation.pO3_ForPilotBits = 0;
   gRadioLinkSetupReq.physDlDpch.tPC_DownlinkStepSize = 0;
   gRadioLinkSetupReq.physDlDpch.limitedPowerIncrease = 1;
   gRadioLinkSetupReq.physDlDpch.innerLoopDLPCStatus  = 0;
   
   /* Fill CCTRCH DL TFC */
   gRadioLinkSetupReq.cctrchDlTfc.tfcsSize = 2;
   gRadioLinkSetupReq.cctrchDlTfc.ptrCctrchTfc = (L1CAPI_TFCS_Info_Item *)malloc
                                                 (gRadioLinkSetupReq.cctrchDlTfc.tfcsSize * sizeof(L1CAPI_TFCS_Info_Item));
   memset((L1CAPI_TFCS_Info_Item *)gRadioLinkSetupReq.cctrchDlTfc.ptrCctrchTfc, 0,
          sizeof(L1CAPI_TFCS_Info_Item));
   
   for (idx = 0; idx < gRadioLinkSetupReq.cctrchDlTfc.tfcsSize; idx++)
   {
       gRadioLinkSetupReq.cctrchDlTfc.ptrCctrchTfc[idx].bit_mask = 0x00;
       gRadioLinkSetupReq.cctrchDlTfc.ptrCctrchTfc[idx].cTFC = idx;
   }

   /* Fill Physical UL DPCH */
   gRadioLinkSetupReq.physUlDpch.bit_mask = 0x00;
   gRadioLinkSetupReq.physUlDpch.ul_ScramblingCodeInfo.uL_ScramblingCodeLength = L1CAPI_UL_SCRAMCODELENGTH_LONG;
   gRadioLinkSetupReq.physUlDpch.ul_ScramblingCodeInfo.uL_ScramblingCodeNumber = UL_SCRAMBLING_CODE + rlId; 
   gRadioLinkSetupReq.physUlDpch.minUL_ChannelisationCodeLength = 6;
   gRadioLinkSetupReq.physUlDpch.bit_mask |= UL_DPCH_Setup_DpcMode_present;
   gRadioLinkSetupReq.physUlDpch.dpcMode = L1CAPI_DPC_MODE0;
   gRadioLinkSetupReq.physUlDpch.bit_mask |= UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present;
   gRadioLinkSetupReq.physUlDpch.maxNrOfUL_DPDCHs = 1;
   gRadioLinkSetupReq.physUlDpch.ul_PunctureLimit = 15;
   gRadioLinkSetupReq.physUlDpch.ul_DPCCH_SlotFormat = 0;
   gRadioLinkSetupReq.physUlDpch.ul_SIR_Target = 60;
   gRadioLinkSetupReq.physUlDpch.diversityMode = L1CAPI_DIV_NONE;
   gRadioLinkSetupReq.physUlDpch.dpcMode = L1CAPI_DPC_MODE0;
   gRadioLinkSetupReq.physUlDpch.bit_mask |= UL_DPCH_Setup_IndEDch_present;
   gRadioLinkSetupReq.physUlDpch.ulDpdchIndEDch = 0;

   /* Fill CCTRCH UL TFC */
   gRadioLinkSetupReq.cctrchUlTfc.tfcsSize = 2;
    
   gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc = (L1CAPI_TFCS_Info_Item *)malloc
                                                  (gRadioLinkSetupReq.cctrchUlTfc.tfcsSize *
                                                   sizeof(L1CAPI_TFCS_Info_Item));
   memset((L1CAPI_TFCS_Info_Item *)gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc, 0,
          gRadioLinkSetupReq.cctrchUlTfc.tfcsSize * sizeof(L1CAPI_TFCS_Info_Item));

   for (idx = 0; idx < gRadioLinkSetupReq.cctrchUlTfc.tfcsSize; idx++)
   {
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].bit_mask = 0x00;
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].cTFC = idx;
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].bit_mask |= tFC_Beta_present;
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta =
                              (L1CAPI_TFC_Beta *)malloc(sizeof(L1CAPI_TFC_Beta));
       memset((L1CAPI_TFC_Beta *)gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta, 0,
              sizeof(L1CAPI_TFC_Beta));
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta->betaC = 10;
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta->betaD = 15;
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta->gainFactor = 0;
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta->refTFCNumber = idx;
   }
} /*End of fillRadioLinkSetupRequest*/

/*
 * ############################################################################
 * Method Name : fillDedicatedMeasInitRequest
 *        
 * Description : This procedure fills the Dedicated Measurement Init Request.
 *         
 * Parameters  : None
 *            
 * Returns     : None
 * ############################################################################
 */
void fillDedicatedMeasInitRequest (MeasInfo_t *measInfo, unsigned int isOnDemandMeas)
{

   /* Initialize the Dedicated Meas Init Request */
   memset((L1CAPI_Dedicated_Meas_Init_Request *)&gDedicatedMeasInitReq, 0,
          sizeof(L1CAPI_Dedicated_Meas_Init_Request));

   gDedicatedMeasInitReq.bit_mask = 0x80 ;
   unsigned int rlId = measInfo->rlId;
   gDedicatedMeasInitReq.NodeBComContext = gClCntxt.clUeCntxt[rlId].nodebCmnCntxt; // need to  discuss

   if (measInfo->measType == FXL_RTT_MEAS)
   {
      gDedicatedMeasInitReq.measureID = (rlId * MAX_NUMBER_OF_MEASUREMENT);
      gDedicatedMeasInitReq.measType  = L1CAPI_MEAS_RTT;
   }
   else if (measInfo->measType == FXL_RSCP_MEAS)
   {
      gDedicatedMeasInitReq.measureID = ((rlId*MAX_NUMBER_OF_MEASUREMENT) +1);
      gDedicatedMeasInitReq.measType  = L1CAPI_MEAS_RSCP;
   }
   else
   {
        // Nothing
   }
   gDedicatedMeasInitReq.rlCount = 1;
   gDedicatedMeasInitReq.rlsCount = 0;

   gDedicatedMeasInitReq.pRl_ID =
               (L1CAPI_Radiolink_ID *)malloc((gDedicatedMeasInitReq.rlCount) * sizeof(L1CAPI_Radiolink_ID));
   memset((L1CAPI_Radiolink_ID *)gDedicatedMeasInitReq.pRl_ID, 0,
           (gDedicatedMeasInitReq.rlCount) * sizeof(L1CAPI_Radiolink_ID));
   gDedicatedMeasInitReq.pRl_ID[0] = rlId;

   if( 0 == isOnDemandMeas)
   {
      gDedicatedMeasInitReq.reportInf.reportMode = L1CAPI_MEAS_PERIODIC;
      gDedicatedMeasInitReq.reportInf.periodicRepCfg.scale = 0;
      gDedicatedMeasInitReq.reportInf.periodicRepCfg.repFreq = 100;
   }
   else
   {
      gDedicatedMeasInitReq.reportInf.reportMode = L1CAPI_MEAS_ON_DEMAND;
   }
   gDedicatedMeasInitReq.cfnReportInd = L1CAPI_FN_REPORT_NOT_REQD;

}

/*
* ############################################################################
* Method Name : fillDedicatedMeasTermRequest
*            
* Description : This procedure fills the Dedicated Measurement Term Request.
*             
* Parameters  : None
*           
* Returns     : None
* ############################################################################
*/

void fillDedicatedMeasTermRequest (MeasInfo_t *measInfo)
{
   /* Initialize the Dedicated Meas Term Request */
   memset((L1CAPI_Dedicated_Meas_Term_Request *)&gDedicatedMeasTermReq, 0,
          sizeof(L1CAPI_Dedicated_Meas_Term_Request));

   unsigned int rlId = measInfo->rlId;

   gDedicatedMeasTermReq.NodeBComContext = gClCntxt.clUeCntxt[rlId].nodebCmnCntxt;
   if (measInfo->measType == FXL_RTT_MEAS )
   {
       gClCntxt.clUeCntxt[rlId].DedRttMeasTermTransId = gClCntxt.cPlaneTrnsId;
       gDedicatedMeasTermReq.measureID = rlId * MAX_NUMBER_OF_MEASUREMENT;
   }
   else if (measInfo->measType == FXL_RSCP_MEAS )
   {
      gClCntxt.clUeCntxt[rlId].DedRscpMeasTermTransId = gClCntxt.cPlaneTrnsId;
      gDedicatedMeasTermReq.measureID = ((rlId *MAX_NUMBER_OF_MEASUREMENT) +1);
   }
}

/*
 *############################################################################
 * Method Name : cleanMemRadioLinkSetupRequest
 *
 * Description : This procedure cleans memory allocated for Radio Link Setup 
 *               Request.
 *
 * Parameters  : None
 *
 * Returns     : None
 *############################################################################
 */
void cleanMemRadioLinkSetupRequest (void)
{
   unsigned int idx = 0;

   /* Clean RL Info */
   if (NULL != gRadioLinkSetupReq.pRlInfo)
   {
       if (NULL != gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo)
       {
           free (gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo);
           gRadioLinkSetupReq.pRlInfo->ptrDlCodeInfo = NULL;
       }

       free (gRadioLinkSetupReq.pRlInfo);
       gRadioLinkSetupReq.pRlInfo = NULL;
   }

   /* Clean Coord TRCH DCH Info */
   if (NULL != gRadioLinkSetupReq.ptrCoordTrchDchInfo)
   {
       if (NULL != gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo)
       {
           if (NULL != gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL)
           {
               if (NULL != gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->ptrTransFormat)
               {
                   free (gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->ptrTransFormat);
                   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL->ptrTransFormat = NULL;
               }

               free (gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL);
               gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsDL = NULL;
           }

           if (NULL != gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL)
           {
               if (NULL != gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->ptrTransFormat)
               {
                   free (gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->ptrTransFormat);
                   gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL->ptrTransFormat = NULL;
               }

               free (gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL);
               gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo->ptrTfsUL = NULL;
           }

           free (gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo);
           gRadioLinkSetupReq.ptrCoordTrchDchInfo->ptrDCHSpecificInfo = NULL;
       }
  
       free (gRadioLinkSetupReq.ptrCoordTrchDchInfo);
       gRadioLinkSetupReq.ptrCoordTrchDchInfo = NULL;
   }

   /* Clean CCTRCH DL TFC */
   if (NULL != gRadioLinkSetupReq.cctrchDlTfc.ptrCctrchTfc)
   {
       free (gRadioLinkSetupReq.cctrchDlTfc.ptrCctrchTfc);
       gRadioLinkSetupReq.cctrchDlTfc.ptrCctrchTfc = NULL;
   }

   /* Clean CCTRCH UL TFC */
   if (NULL != gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc)
   {
       for (idx = 0; idx < gRadioLinkSetupReq.cctrchUlTfc.tfcsSize; idx++)
       {
          if (NULL != gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta)
          {
              free (gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta);
              gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc[idx].ptrTFCBeta = NULL;
          }
       }

       free (gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc);
       gRadioLinkSetupReq.cctrchUlTfc.ptrCctrchTfc = NULL;
   }
}

/*
 *############################################################################
 * Method Name : getPagingSfn
 *
 * Description : This procedure calculates the SFN for Paging Message.
 *
 * Parameters  : 
 *   pImsi               IMSI String 
 *
 * Returns     : 
 *   unsigned short      Paging SFN Value
 *############################################################################
 */
unsigned short getPagingSfn (char *pImsi, unsigned int imsiLen)
{
   unsigned int idx = 0;
   unsigned int pagingSfn = 0;
   unsigned int winSizeBitmap = ~((1 << 0) -1);

   /* Get IMSI value in Integer format */
   int64_t imsiValue = 0;

   while (idx < imsiLen)
   {
      imsiValue = ((imsiValue * 10) + (*(pImsi + idx) - '0'));
      idx++;
   }

   DEBUG3(("IMSI String : %s IMSI Integer Value = %lld\n", pImsi, imsiValue));

   /* Get window adjustment */
   unsigned int winSize = DEF_PCH_toAWS / 20;
   DEBUG3(("Paging : Window Size = %ld\n", winSize));
 
   /* DRX Cycle is equal to 64 */
   imsiValue = imsiValue % 64;
   DEBUG3(("IMSI Value after DRX Cycle Calculation = %lld\n", imsiValue));

   /* Get the future SFN */
   unsigned int futureSfn = ((4096 + gClCntxt.bfn + winSize) % 4096) & winSizeBitmap;

   idx = 0;
   while (pagingSfn < 4096)
   {
       /* DRX Cycle is equal to 64 */
       pagingSfn = imsiValue + (idx * 64);
       idx++;
       if (pagingSfn > futureSfn)
       {
           break;
       }
   }

   pagingSfn = pagingSfn % 4096;
   if (pagingSfn <= 8)
   {
      pagingSfn = pagingSfn + 64;
   }

   DEBUGMSG(("Future SFN (%ld),  Paging SFN(%ld)\n", futureSfn, pagingSfn));

   return (pagingSfn);
}

/*
 *############################################################################
 * Method Name : fillCellReconfigReq
 *
 * Description : This procedure fills the Cell Reconfig Reuest to be sent to
 *               Layer1.
 *
 * Parameters  : None
 *
 * Returns     : None
 *############################################################################
 */
void fillCellReconfigReq (void)
{
   gCellReconfigReq.bit_mask  = 0;
   gCellReconfigReq.cId       = gUmtsConfig.cellId;
   gCellReconfigReq.bit_mask |= cellreconf_txattn_present;
   gCellReconfigReq.txAttn    = gUmtsConfig.txAttn & 0xFF;
}
