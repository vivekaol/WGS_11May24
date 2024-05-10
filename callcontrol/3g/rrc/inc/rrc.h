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
 * File Name   : rrc.h
 *
 * Description : This file provides main functionality of Radio Resource Control
 *               (RRC) stack for ImsiCatcher application.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 26/09/2014	        Ashutosh Samal              File Creation
 *############################################################################
 */
#ifndef _RRC_H_
#define _RRC_H_

#include "asnApi.h"
#include "timer.h"
#include "l2Cmn.h"
#include "fxLSocketInterfaceApi.h"
#include "feaConfig.h"

/*
 * Defines
 */

#define RRC_SUCCESS                                          0x00
#define RRC_FAILURE                                          0x01

#define RRC_CELL_ID                                          0x01
#define RRC_UE_ID                                            0x02
              
#define MAX_UL_RRC_MSG_BYTE_SIZE                             200
#define MAX_UE_SUPPORTED                                     32
#define MAX_BLACK_LISTED_IMSI                                500
#define MAX_WHITE_LISTED_IMSI                                500
#define MAX_NUM_GSM_REDIRECT_INFO                            10
#define RL_SETUP_REQ_TIMEOUT                                 1000
#define DED_MEAS_INIT_REQ_TIMEOUT                            1000
#define DED_MEAS_TERM_REQ_TIMEOUT                            200
#define RL_DELETE_REQ_TIMEOUT                                1000
#define RRC_CONNECTION_SETUP_TIMEOUT                         3000
#define IDENTITY_REQUEST_TIMEOUT                             2000
#define RRC_CONNECTION_RELEASE_TIMEOUT                       2000
#define RRC_GPS_MEAS_REPORT_TIMEOUT                          1000

#define SRNC_IDENTITY_LENGTH                                 12
#define SRNTI_LENGTH                                         20
#define SRNTI                                                0x2000
#define UTRAN_DRX_CYCLE_LENGTH_COEFF                         0x6
#define DCH_ID                                               5
#define GAIN_FACTOR_BETAC                                    10
#define GAIN_FACTOR_BETAD                                    15
#define MAX_RETRANSMIT_RRC_CON_SETUP                         2
#define MAX_RETRANSMIT_IDENTITY_REQ                          2
#define MAX_NUMBER_OF_MEASUREMENT                            2

#define UE_DEDICATED_MODE_GENERIC_TIMEOUT                    500


#define UE_MEASUREMENT_ID                                    10
#define UE_BASED_GPS_MEASUREMENT_TIMEOUT                     100

/*
 * Structures
 */
typedef struct rrcCellorUeId
{
  unsigned char choice;
  union
  {
      unsigned int  ueId;
      unsigned int  cellId;
  }u;
}RrcCellorUeId;

/*
 * RRC Data Req
 */
typedef struct rrcDataReq
{
   RrcCellorUeId  cellOrUeId;
   LogChType_e    logicalChType;
   unsigned int   logicalChId;
   unsigned int   rrcPduLen;
   unsigned char *rrcPdu;
   unsigned int   propDelay;
}RrcDataReq;

/*
 * RRC PCCH Message
 */
typedef struct rrcPcchMsg
{
   unsigned short  sfn;
   unsigned short  rrcPduLen;
   unsigned char  *rrcPdu;
   unsigned int    count; //Count How many times paging msg is sent
   char            imsi[MAX_IMSI_LENGTH + 1]; //Added to Identity UE in L2 for add and Delete operation
   unsigned int    isInitialIMSIPaging;
}RrcPcchMsg;

/*
 * UE Events
 */
typedef enum
{
    UE_RRC_CON_REQ,
    UE_CELL_OR_URA_UPDATE,
    UE_RL_SETUP_SUCCESS,
    UE_RL_SETUP_FAILURE,
    UE_RLC_ERROR_CALL_RLS,
    UE_RL_SETUP_TIMEOUT,
    UE_RL_DELETE_TIMEOUT,
    UE_RL_DELETE_SUCCESS,
    UE_RRC_CON_SETUP_TIMEOUT,
    UE_RRC_CON_SETUP_COMP_RCVD,
    UE_IDT_RCVD,
    UE_IDENTITY_REQ_TIMEOUT,
    UE_IDENTITY_RESP_RCVD,
    UE_RRC_CON_REL_TIMEOUT,
    UE_RRC_CON_REL_COMP_RCVD,
    UE_NAS_REJECT_TIMEOUT,
    UE_DED_MEAS_RTT_INIT_REQ_SUCCESS,
    UE_DED_MEAS_RSCP_INIT_REQ_SUCCESS,
    UE_DED_MEAS_RTT_REPORT_SUCCESS,
    UE_DED_MEAS_RSCP_REPORT_SUCCESS,
    UE_DED_MEAS_INIT_REQ_TIMEOUT,
    UE_DED_MEAS_RTT_TERM_REQ_SUCCESS,
    UE_DED_MEAS_RSCP_TERM_REQ_SUCCESS,
    UE_DED_MEAS_TERM_REQ_TIMEOUT,
    UE_RRC_PAGING_TYPE2_TIMEOUT,
	
    UE_RRC_PHY_CH_RECONF_TIMEOUT,
    UE_RRC_PHY_CH_RECONF_COMP_RCVD,
    UE_RRC_PHY_CH_RECONF_FAIL_RCVD,

    UE_RRC_START_UE_BASED_GPS_TIMEOUT,
    UE_RRC_GPS_MEAS_CNTRL_REL_TIMEOUT,
#if 0
    UE_RRC_GPS_MEAS_CNTRL_MODIFY_TIMEOUT,
#endif
    UE_RRC_GPS_MEAS_CNTRL_FAILURE,
    UE_RRC_GPS_MEAS_CNTRL_REPORT,

    UE_OUT_OF_COVERAGE_E
}RrcUeEvent;

/*
 * UE States
 */
typedef enum
{
    UE_IDLE,
    UE_WAIT_FOR_RL_SETUP_RESP,
    UE_WAIT_FOR_RRC_CON_SETUP_COMPLETE,
    UE_WAIT_FOR_IDT,
    UE_WAIT_FOR_IDENTITY_RESP,
    UE_WAIT_FOR_RRC_CON_REL_COMPLETE,
    UE_WAIT_FOR_RL_DELETE_RESP,
    UE_WAIT_FOR_PAGING_TYPE2_TIMEOUT,
    UE_WAIT_FOR_PHY_CH_RECONF_RESP,
    UE_STOP_MSG_HANDLING 
}RrcUeState;

typedef enum
{
     NAS_INVALID_MSG_TYPE,
     NAS_LOCATION_UPDATE_REQ,
     NAS_GMM_ATTACH_REQUEST,
     NAS_GMM_ROUTING_AREA_UPDATE
}NasMsgType;

/*
 * UE Specific Data
 */
typedef struct rrcUeSpecificData
{
   unsigned int            ueUsed;
   unsigned int            rrcTransactionId;
   RrcInitialUEIdentity    ueInitialIdentity;
   unsigned int            ueRrcConnSetupCount;
   RrcConnectionSetupData  ueRrcConnSetup;
   RrcUeState              ueState;
   tcbTimer_t              ueTimer;
   tcbTimer_t              ueDedMeasTimer;
   tcbTimer_t              ueDedGenericTimer;
   RrcUlDCCHData           ulDcchData;
   unsigned int            locationUpdateReqReceived;
   unsigned int            attachReqReceived;
   unsigned int            routingAreaUpdateReceived;
//   NasMsgType              nasMsgType;
   unsigned int            isIDTSaved;
   RrcUlDCCHData           savedIDT;
   unsigned int            imsiLen;
   unsigned int            imeiLen;
   unsigned int            tmsiLen;
   char                    imsi[MAX_IMSI_LENGTH];
   char                    imei[MAX_IMEI_LENGTH];
   char                    tmsi[MAX_TMSI_LENGTH];
   //char                    dummy[2];
   unsigned int            imeiSv;    // Dev team changes
   unsigned int            ueIMSIReqCount;
   unsigned int            ueIMEIReqCount;
   unsigned int            ueTMSIReqCount;
   unsigned int            stopMsgHandling;
   unsigned int            isBlackListed;
   unsigned int            rttValue;
   unsigned int            rscpValue;
   unsigned int            isFirstTimeLatched;
   fxL3gMeasType           measType; 
   unsigned char           silentCallEnabFlag;  // TRUE - Silent call enabled, FALSE - Silent call disabled
   unsigned char           isDedMeasStarted;
   fxL3gMeasType           dedMeasType;
#ifdef FXL_BL_UE_POWER_OFF
   unsigned int            powerOffIndSend;
#endif
   unsigned int            propagationDelay;
   unsigned int            emergencyCallAttempted;
   unsigned int            networkAssistedGpsSupport;
   unsigned int            ueAccessSpectrumReleaseIndicator;
   unsigned int            endSilentCallRspSent;
   unsigned int            numberOfBandSupported;
   unsigned int            supportedBand[22];
   int          	       lastLac;  // Dev team changes
}RrcUeSpecificData;

/*
  * Dedicated Measurment Report
  */
typedef struct ueDedicatedMeasReport
{
    unsigned int rlId;
	unsigned int rttValue;
	unsigned int rscpValue;
}UeDedicatedMeasReport;

/*
 * Store the IMSI of UE latched to ID Catcher
 */
typedef struct latchedUeDetails
{
   char                     imsi[MAX_IMSI_LENGTH];
   char                     dummy;
   fxL3gMeasType            measType;
   unsigned char            silentCallEnabFlag;  // TRUE - Silent call enabled, FALSE - Silent call disabled
   struct latchedUeDetails *next;
}LatchedUeDetails;

typedef struct measInfo_t
{
   unsigned int rlId;
   fxL3gMeasType measType;      
}MeasInfo_t;

typedef struct UeIdentityConfig_
{
    char              identity[SIZE_OF_IDENTITY_STR];
    unsigned char     idType;
    unsigned char     listType;
    unsigned char     rejectCauseIfWhitelist;
} UeIdentityConfig;

typedef struct UmtsConfigList_
{
   unsigned char       defaultConfig;
   unsigned char       dummyPadding;
   unsigned short int  numbOfIds;
   UeIdentityConfig    *configId;  //Variable length array
} UmtsConfigList;

/*
 * UE Control Block
 */
typedef struct rrcUeControlBlock
{
//   unsigned int          rrcConnSetupCount;
//   unsigned int          rrcConnRelCount;
//   unsigned int          ulCCCHMsgCount;
//   unsigned int          ulDCCHMsgCount;
   LatchedUeDetails     *pLatchedUeDetails;

   unsigned int          cleanupCount;
   unsigned int          numOfUe;
   RrcUeSpecificData     ueSpecificData[MAX_UE_SUPPORTED];
#if 0
   unsigned int          numOfBlackListedImsi;
   char                  blackListedImsi[MAX_BLACK_LISTED_IMSI][MAX_IMSI_LENGTH];
   unsigned int          numOfBlackListedImei;
   char                  blackListedImei[MAX_BLACK_LISTED_IMSI][MAX_IMEI_LENGTH];
   unsigned int          numOfWhiteListedImsi;
   char                  whiteListedImsi[MAX_WHITE_LISTED_IMSI][MAX_IMSI_LENGTH];
   unsigned int          numOfWhiteListedImei;
   char                  whiteListedImei[MAX_WHITE_LISTED_IMSI][MAX_IMEI_LENGTH];
#endif
}RrcUeControlBlock;

#endif
