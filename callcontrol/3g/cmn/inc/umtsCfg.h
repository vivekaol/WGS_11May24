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
 * File Name   : umtsCfg.h 
 *
 * Description : This file contains umts config control block.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 15/12/2014	        Ashutosh Samal              File Creation
 *############################################################################
 */
#ifndef _UMTS_CFG_H_
#define _UMTS_CFG_H_
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "fxLSocketInterfaceApi.h"
#include "asnApi.h"

//Hard Coded UL Scrambling Code. This will be increamented by UE Index.
#define UL_SCRAMBLING_CODE        0x1500 
#define DL_CHANNELISATION_CODE    32

/*
 * UE UL Tx Pwr Details
 */
typedef struct ueUlTxPwrData
{
    char imsiStr[SIZE_OF_IDENTITY_STR];
    int  maxUlTxPwr;
}UeUlTxPwrData;

/*
  * BL UE Redirect Info
  */
typedef struct umtsBlUeRedirectInfo
{
   char                  imsiStr[SIZE_OF_IDENTITY_STR];
   fxL3gRedirectionType  redirectionType;
   fxL3gRedirectionInfo  redirectionInfo;
}UmtsBlUeRedirectInfo;

typedef struct radioLinkReconfigPrepReqInfo
{
    unsigned int rlId;
    int          ulSIRtarget;
}RadioLinkReconfigPrepReqInfo;

#ifdef FXL_3G_TX_JAMMER
/* 
 * Structure for the PSC found in a UARFCN
 */
typedef struct
{
   fxLDspType   dspType;
   unsigned int numOfPsc;
   unsigned int psc[MAX_NUM_OF_PSC_PER_UARFCN];
   float        rscp[MAX_NUM_OF_PSC_PER_UARFCN];
}jammerPscInfo;
#endif

typedef struct delConifgIdList
{
    int    idType;    
    char   identity[SIZE_OF_IDENTITY_STR];
}DelConfigIdList;

typedef enum
{
   INVALID_E,
   CELL_START_TRIGGERED_E,
   CELL_START_FAILURE_SENT_E,
   CELL_START_SUCCESS_SENT_E

}CellStartStatus;


/*
 * UMTS Config Control Block
 */
typedef struct umtsConfigControlBlock 
{
   unsigned int              dlUarfcn;
   CellStartStatus         cellStartStatus;
   unsigned int              rncId;
   unsigned int              cellId;
   unsigned int              psc;
   unsigned char             mibPlmnIdentity;
   unsigned int              numOfPlmn;
   PlmnData                  plmn[6];
   unsigned int              lac[2];
   unsigned int              rac;
   //If User configured reselection parameter dont update at Id catcher starting
   unsigned int              cellReselectUsrCfgStatus;
   unsigned int              txAttn;
   unsigned int              cellSelQualMeas;
   signed   int              qQualMin;
   signed   int              qRxLevMin;
   unsigned int              tReselec;
   unsigned int              qHystLS;
   unsigned int              qHyst2S;
   signed   int              maxUlTxPwr;
   unsigned int              cpichTxPwr;
   int                       redirectDlUarfcn;
   fxL3gRedirectionType      redirectionType;
   fxL3gRedirectionInfo      redirectionInfo;
   unsigned int              wlRejectCauseCfgEnable; 
   unsigned int              wlRejectCause;
#if 0
   unsigned int              numIntraFreqNeighbr;
   fxl3gIntraFreqNeigbrInfo  intraFreqNeighbrList[FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST];
   unsigned int              numInterFreqNeighbr;
   fxl3gInterFreqNeigbrInfo  interFreqNeighbrList[FXL_UMTS_MAX_INTER_FREQ_CELL_LIST];
#endif
   unsigned int              gpsWeek;
   unsigned int              gpsTow;
#ifdef FXL_3G_TX_JAMMER
   unsigned int              txJammerEnabled;
#endif
   unsigned int              t3212;
   unsigned int              att;
   unsigned int              nmo;

   // New Configurable parameter for SysInfo
   unsigned int              mibValueTag;
   fxL3gSib1Info             sib1Info;
   fxL3gSib2Info             sib2Info;
   /*Parameter which are already present above are not used from Sib3Info data structure e.g. CellId, cellSelQualMeas, qHyst2S*/
   fxL3gSib3Info             sib3Info;
   
   fxL3gSib5Info             sib5Info;  //Not Supported.
   fxL3gSib7Info             sib7Info;
   fxL3gSib11Info            sib11Info;

   fxL3gRedirectionType      wlUserRedirectionType; 
   fxL3gRedirectionInfo      wlUserRedirectionInfo;

   unsigned int              enableEmergencyCallRejection;
   fxL3gRedirectionType      emergencyCallRedirectionType;
   fxL3gRedirectionInfo      emergencyCallRedirectionInfo;
   unsigned int              pilot_boost_enable;
   unsigned int              rxGain;
}UmtsConfigControlBlock;

#endif
