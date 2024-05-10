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
* File Name   : userManager.h
 *
* Description : Function to support add/delete/find user
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 15/10/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#ifndef USERMANAGER_H_
#define USERMANAGER_H_

#include "l1Constants.h"
#include "l1InterfaceManager.h"
#include "l2Scheduler.h"
#include "lapdm.h"
#include "timerApi.h"

#define MAX_IMSI_LENGTH_2G 15
#define SIZE_OF_IDENTITY 9 // What received in 3GPP messages
#define SIZE_OF_TMSI 6 // Length of Identity(5) + Type of Identity(F4) + 4 bytes randomly generated

#define TIMER_VALUE_WAITING_FOR_UE_RSP                 2000 //2sec
#define TIMER_VALUE_WAITING_FOR_LCS_RSP               10000 //10sec
#define TIMER_FOR_RECEIVING_ALERT                     10000 //10 sec
#define TIMER_FOR_MT_ALERT                            15000 // T301 could be upto 18Mins, configured to 15secs

#define TIMER_VALUE_WAITING_FOR_GPRS_SUSP              2000 //2sec
#define TIMER_FOR_PAGE_RETRANSMIT                      2000 // 2sec

#define PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY         (60000 + 4620 +10000 ) * 6 // (60 seconds plus extra 10 s) * 6 
#define BL_PAGING_INACTIVITY_TIMEOUT_CTR                  8
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
#define PAGING_TIMER_FOR_BL_VALIDITY_CHECK            3000 // 20 seconds, Blacklist user Validity Check Timer

#endif

#define SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS 	  0x0001
#define SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT		  0x0002
#define RESET_TRIGGER_FOR_RSSI_GPS_IND 				~(0x0003)

#ifdef FEA_MT_SMS
#define SET_TRIGGER_FOR_INDIVIDUAL_SMS				  0x0004
#define SET_TRIGGER_FOR_BROADCAST_SMS				  0x0008
#define RESET_TRIGGER_FOR_SMS 			            ~(0x000C)
#endif

#ifdef FEA_SILENT_CALL
#define SET_TRIGGER_FOR_TCH_SILENT_CALL	              0x0010
#define SET_TRIGGER_FOR_SDCCH_SILENT_CALL		      0x0020
#define SET_TRIGGER_FOR_END_SILENT_CALL      		  0x0040
#define RESET_TRIGGER_FOR_SILENT_CALL       		~(0x0070)
#endif /* FEA_SILENT_CALL */

#define SET_TRIGGER_FOR_REDIRECTION                   0x0080
#define RESET_TRIGGER_FOR_REDIRECTION               ~(0x0080)

#define SET_TRIGGER_FOR_ALERTING 	                  0x0100
#define RESET_TRIGGER_FOR_ALERTING                  ~(0x0100)

#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
#define SET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK      0x0200
#define RESET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK  ~(0x0200)
#endif

#define SET_TRIGGER_FOR_TARGET_VOICE_CALL             0x0400
#define RESET_TRIGGER_FOR_TARGET_VOICE_CALL         ~(0x0400)

#define SET_TRIGGER_FOR_RELEASE                       0x0800
#define RESET_TRIGGER_FOR_RELEASE                   ~(0x0800)

/*
 * GSM Application States
 */
typedef enum
{    
    NULL_STATE                                  = 0,
    RACH_RECEIVED                               = 1,
    SDCCH_CHANNEL_ALLOCATED                     = 2,
    CM_SERVICE_REQ_RECEIVED                     = 3,
    LAU_REQ_RECEIVED                            = 4,
    IMSI_RECEIVED                               = 5,
    IMEI_RECEIVED                               = 6,
    TMSI_REALLOCATION_COMPLETE_RECEIVED         = 7,
    PAGING_RESP_RECEIVED                        = 8,
    LCS_POS_RECEIVED                            = 9,
    CIPHERING_MODE_COMPLETE_RECEIVED            = 10,
    SETUP_RECEIVED                              = 11,
    DISC_RECEIVED                               = 12,
    WAITING_FOR_L2ACK                           = 13,
    WAITING_FOR_IDENTITY_RSP                    = 14,
    WAITING_FOR_LCS_POSN_RSP                    = 15,
    WAITING_FOR_LAUCM_REJECT_RSP                = 16,
    WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE   = 17, //In Paging scenario this state will also act as WAITING_FOR_DISC
    WAITING_FOR_CIPHERING_MODE_COMPLETE         = 18,
    L3_REJECT_FOR_UE                            = 19, // For Whitelisted UE or Blocking MO calls
    TCH_ALLOCATED                               = 20,
    WAITING_FOR_SABM_ON_FACCH                   = 21,
    SABM_RECEIVED_ON_FACCH                      = 22,
    TCH_SILENT_CALL_IN_PROGRESS                 = 23,
    SDCCH_SILENT_CALL_IN_PROGRESS               = 24,
    WAITING_FOR_CLASSMARK                       = 25,
    END_SILENT_CALL                             = 26,
    WAITING_TO_SEND_SETUP                       = 27,
    WAITING_FOR_CALL_CONF                       = 28,
    CALL_CONF_RCVD                              = 29,
    CALL_PROC_SENT                              = 30,
    MT_ASSGN_COMP_RCVD                          = 31,
    WAITING_FOR_ALERT                           = 32,
    ALERT_RCVD                                  = 33,
    WAITING_FOR_MT_CONNECT                      = 34,
    PH_CONNECT_RCVD                             = 35,
    DISC_SENT                                   = 36,
    REL_PROC                                    = 37,
    WAITING_FOR_REL_CMP                         = 38,
    WAITING_FOR_CALL_EST                        = 39,
    CALL_EST                                    = 40,
    HOLD_RCVD                                   = 41,
#ifdef FEA_MT_SMS
    EST_L2_SAPI3_FOR_MT_SMS                     = 42,
    CP_ACK_RECEIVED                             = 43,
#endif
#ifdef FEA_DECODE_MO_SMS
    CP_DATA_RECEIVED                            = 44,
    CP_ACK_SENT                                 = 45,
#endif
    ATTACH_RECEIVED                             = 46,
    CLASSMARK_RECEIVED                          = 47,
#ifdef MM_INFO
  	MM_INFO_SENT								= 48,
#endif
    RRLP_GPS_ASSIST_DATA_SENT                   = 49,
    RRLP_GPS_ASSIST_DATA_ACK_RCVD               = 50
} gsmL23States_;
typedef int gsmL23States;

/*
 *  * Store the IMSI of UE latched to ID Catcher
 *   */
typedef struct gsmLatchedUeDetails
{  
    char                       imsi[MAX_IMSI_LENGTH_2G];
    char                       dummy;
    struct gsmLatchedUeDetails *next;
}GsmLatchedUeDetails;

typedef struct redirectionInfo2g
{
    tOCT_UINT8  bandIndicator;
    tOCT_UINT16 arfcn;
    tOCT_UINT8  bsic;
}redirectInfo2g;

#if 0  /* Temp Structures...To be moved to fxL file release 4.1 onwards is supported */

typedef struct
{
    /*
     * RXLEV   0   =   less than -110 dBm.
     * RXLEV   1   =   -110 dBm to -109 dBm
     * RXLEV   2   =   -109 dBm to -108 dBm
                        :
                        :
     * RXLEV   62  =   -49 dBm  to -48 dBm
     * RXLEV   63  =   greater than -48 dBm.
     */
        int           arfcn;
        unsigned char bsic;
        unsigned char rxlev_Rssi;
}fxLGsmMeasRes2gNeigh;

#ifdef FEA_2G_INTER_RAT_MEAS
typedef struct
{
    /* 3GPP TS 45008:8.1.5 - UTRAN Measurement quantity *
     * 
     * RSCP:
     *
     *     rxlev_Rscp_ecNo = 0;  --> " -116 dBm <= RSCP < -115 dBm"
     *     rxlev_Rscp_ecNo = 1;  --> " -115 dBm <= RSCP < -114 dBm"
     *     .
     *     .
     *     rxlev_Rscp_ecNo = 63; --> " -53 dBm  <= RSCP < -52 dBm"
     *
     * Ec/No:
     *
     *     rxlev_Rscp_ecNo = 0;  -->  " -24   dB >  CPICH Ec/Io"
     *     rxlev_Rscp_ecNo = 1;  -->  " -24   dB <= CPICH Ec/Io < -23.5 dB"
     *     rxlev_Rscp_ecNo = 2;  -->  " -23.5 dB <= CPICH Ec/Io < -23   dB"
     *     .
     *     .
     *     rxlev_Rscp_ecNo = 48; --> " -0.5 dB   <= CPICH Ec/Io < 0 dB"
     *     rxlev_Rscp_ecNo = 49; --> "  0   dB   <  CPICH Ec/Io"
     */
        int            uarfcn;
        int            psc;
        unsigned char  rxlev_Rscp_ecNo;
}fxLGsmMeasRes3gNeigh;

typedef struct
{
    /* 3GPP TS 45008:8.1.5 - EUTRAN Measurement quantity : 3 Bit Reporting *
     *
     *    Offset = E UTRAN_FDD_MEASUREMENT_REPORT_OFFSET/E UTRAN_TDD_MEASUREMENT_REPORT_OFFSET
     *             0 = -140 dBm, 1 = -139 dBm, 2 = -138 dBm, <85>, 62 = -78 dBm, 63 = -77 dBm.
     *
     *    Step   = REPORTING_GRANULARITY
     *             0 = 2 dB step size, 1 = 3 dB step size
     *
     *    
     *      rxlev_Rsrp_Rsrq  = 0   -->   Offset                  to  Offset + Step
     *      rxlev_Rsrp_Rsrq  = 1   -->   Offset  + Step          to  Offset + 2 * Step
     *      rxlev_Rsrp_Rsrq  = 2   -->   Offset  + 2 * Step      to  Offset + 3 * Step
     *      rxlev_Rsrp_Rsrq  = 3   -->   Offset  + 3 * Step      to  Offset + 4 * Step
     *      rxlev_Rsrp_Rsrq  = 4   -->   Offset  + 4 * Step      to  Offset + 5 * Step
     *      rxlev_Rsrp_Rsrq  = 5   -->   Offset  + 5 * Step      to  Offset + 6 * Step
     *      rxlev_Rsrp_Rsrq  = 6   -->   Offset  + 6 * Step      to  Offset + 7 * Step
     *      rxlev_Rsrp_Rsrq  = 7   -->   greater than or equal   to  Offset + 7 * Step
     *
     *    Default Values: Offset = 40(-100 dBm), Step = 0(2 dB step size)
     */
        int            earfcn;
        int            pcid;
        unsigned char  rxlev_Rsrp_Rsrq;
}fxLGsmMeasRes4gNeigh;

#endif /* FEA_2G_INTER_RAT_MEAS */

typedef struct
{
    fxLRat measRatType;
    union
    {
        fxLGsmMeasRes2gNeigh gsmNeighCell;
#ifdef FEA_2G_INTER_RAT_MEAS
        fxLGsmMeasRes3gNeigh umtsNeighCell;
        fxLGsmMeasRes4gNeigh lteNeighCell;
#endif
    }u;
}fxLGsmMeasRes;

typedef struct
{
    int            msPowerUsed;
    unsigned char  timingAdvance;
    unsigned char  timingAdvanceQbits;
    unsigned char  baUsed;
    unsigned char  ulDtxUsed;
    unsigned char  dlRxLevFull;
    unsigned char  dlRxLevSub;
    unsigned char  dlRxQualFull;
    unsigned char  dlRxQualSub;
    unsigned char  measValid;
    unsigned char  numOfCellsMeasured;
    fxLGsmMeasRes  neigh[6];
}fxLGsmMeasReport;


typedef struct
{
    unsigned char     timingAdvance;
    unsigned char     timingAdvanceQbits;
    unsigned char     dlRxLevFull;
    unsigned char     dlRxLevSub;
    unsigned char     dlRxQualFull;
    unsigned char     dlRxQualSub;
}fxLGsmiInitialDlMeasReport;

#endif

typedef struct usrData
{
	tOCT_UINT8             inUse;
	gsmL23States           userState;
	gsmL23States           userPrevState;
	mLapdmStateVar         userLapdmStateVars;
#if defined(FEA_MT_SMS) || defined(FEA_DECODE_MO_SMS)
	mLapdmStateVar         userLapdmStateVarsSapi3;
#endif
	logicalChannelIdentity userLogicalChannel;
	logicalChannelIdentity userTchChannel;
	tOCT_UINT8             lapdmParam[3]; // ra , t1,t2,t3 parameters from original rach request.
    tOCT_UINT8             l3MsgRecvdBytes;
    tOCT_UINT8             l3Msg[GSM_L3_MSG_MAX_SIZE];
    tOCT_UINT8             l3MsgLen;
	tOCT_UINT8             userBlacklisted; // TRUE = Yes , FALSE = No
	tOCT_UINT8             cmServiceReqTypeRcvd; // Type of CM-Service Req
	tOCT_UINT32            blockedMoCallsCounter;
	tOCT_UINT8             retransmissionCountForL3Msg; //Retransmission Count
	tcbTimer_t             tmr; // alloc during activate logical channel and free during deactivate channel
    tOCT_UINT8             initialRachIsPaging;
    tOCT_UINT8             gprsSuspReceived;
	char                   userImei_str[MAX_IDENTITY_LENGTH_STR];
	char                   userImsi_str[MAX_IDENTITY_LENGTH_STR];
	tOCT_UINT8             userOldTmsi[SIZE_OF_TMSI - 2]; // TMSI Assigned by real network, Storing only TMSI value excluding length and type of identity.
	tOCT_UINT8             userTmsi[SIZE_OF_TMSI]; // Valid for Blacklisted UE's, TMSI assigned by our BTS
	tOCT_UINT8             userImsi[SIZE_OF_IDENTITY];
#ifdef FEA_MT_SMS
	tOCT_UINT8*            mtSmsL3Pdu;
    tOCT_UINT8             cpDataSentBytes;
#endif
#ifdef FEA_DECODE_MO_SMS
    tOCT_UINT8*            moSmsL3Pdu;
    tOCT_UINT8             cpDataRcvdBytes;
    tOCT_UINT8             moSmsAllPartsReceived;
#endif
    tOCT_UINT8             wlRejectCause;
    tOCT_UINT8             rltCounter;
    fxL2gMsClassmark       msClassmark;
    tOCT_UINT8             userImeiSv;
    tOCT_UINT16            last_lac;
    tOCT_UINT8             userRedirected;
    tOCT_UINT8             newTimingAdvance;
    tOCT_UINT8             noOfUlMeasurements;
    tOCT_INT16             taOffset[MAX_UL_MEASUREMNETS];
    tOCT_INT16             taOffsetQbits[MAX_UL_MEASUREMNETS];
    tOCT_UINT8             ulRssi[MAX_UL_MEASUREMNETS]; /* RSSI in dBm * -1 */
    tOCT_INT16             ulSnr[MAX_UL_MEASUREMNETS];  /* SNR in dB */
    tOCT_UINT8             ulRssiAvg; /* RSSI in dBm * -1 */
    tOCT_INT16             ulSnrAvg;  /* SNR in dB */
    tOCT_UINT8             l1MeasFlag;
    fxLGsmMeasReport       measReport;
    fxLGsmiInitialDlMeasReport initialMeasReport;
    tOCT_UINT8             rrlpGpsAssistCount;
    tOCT_UINT8             rrlpGpsAssistSegment;
#ifdef FEA_EMER
    tOCT_UINT8             emergency_service_req;
#endif

}userInfo; // TODO align structures for word boundry

typedef struct
{
	tOCT_UINT32             blockedMoCallsCounter;
	tOCT_UINT8              gprsSuspExpectedFromThisUe;
#ifdef FEA_SILENT_CALL
	tOCT_UINT8              uplinkPowerdBm;
    tOCT_UINT8              timeSlotForTchSilentCall;
    tOCT_UINT8              muteDlPwrDuringSilentCall;
#endif
    tOCT_UINT8              pagingMultiFrame;
	tOCT_UINT8              pagingBlockIndex;
	tOCT_UINT8              triggerPagingReq;
	tOCT_UINT16             bitMaskForTriggers;
	tcbTimer_t              tmr;
    tOCT_UINT8              isActive;
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING       
    tOCT_UINT16             pagingInactivityCounter;  /* ++ when Paging Req is sent, reset to 0 when Paging Response is received */
#endif
    tOCT_UINT8              isInConnectedState;
	tOCT_UINT8              userImsi[SIZE_OF_IDENTITY];
	char                    userImsi_str[MAX_IDENTITY_LENGTH_STR];
	tOCT_UINT8              userOldTmsi[SIZE_OF_TMSI - 2]; // TMSI Assigned by real network, Storing only TMSI value excluding length and type of identity.
	tOCT_UINT8              userTmsi[SIZE_OF_TMSI]; // Valid for Blacklisted UE's, TMSI assigned by our BTS
	char                    userImei_str[MAX_IDENTITY_LENGTH_STR];
	char                    alertIsdn_str[MAX_IDENTITY_LENGTH_STR];
#ifdef FEA_MT_SMS
	tOCT_UINT8*             mtSmsL3Pdu;
#endif
    redirectInfo2g          redirectInfo;
    tOCT_UINT8              userImeiSv;
#ifdef FEA_SILENT_CALL    
    tOCT_UINT8              si5Buf[GSM_MACBLOCK_LEN - 4];
    tOCT_UINT8              si6Buf[GSM_MACBLOCK_LEN - 4];
    GERAN_ARFCN_LIST_STR    si5Neighbors;
#ifdef FEA_2G_INTER_RAT_MEAS
    fxL2gInterRatMeasInfo   measInfo;    
    gsm3gNeighCell          gsm3gNeighCellList[FXL_2G_MAX_3G_NEIGHBOR_UARFCNS * FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN];    
    tOCT_UINT8              mi_buf[MAX_MI_INSTANCES][GSM_MACBLOCK_LEN - 2];
    tOCT_UINT8              noOfValidMIInstances;
#endif
#endif
    tOCT_UINT8              wlRejectCause;
    tOCT_UINT16             last_lac;
}blackListedUserInfo;

#ifdef FEA_VOICE_CALL_TO_TARGET
typedef struct
{
	tOCT_UINT8   isOnGoingCall;
	tOCT_UINT8   isCallConnected;
	tOCT_UINT8   moTsNum;
	tOCT_UINT8   moSubChan;
	tOCT_UINT8   mtTsNum;
	tOCT_UINT8   mtSubChan;
    char         moMsIsdnStr[MAX_IDENTITY_LENGTH_STR+1]; /* 1 Byte for + prefix*/
    char         moImsiStr[MAX_IDENTITY_LENGTH_STR];
	char         mtImsiStr[MAX_IDENTITY_LENGTH_STR];
	signed char  mtTi;
}callContext;
#endif /* FEA_VOICE_CALL_TO_TARGET */

typedef struct
{
//Mac Header
//8	7_________		6	5			4		3	2	1	
//Payload Type		RRBP		S/P		USF	
//
tOCT_UINT8 payloadType;
tOCT_UINT8 rrbp;			
tOCT_UINT8 pollingBit;	
tOCT_UINT8 usf;

//==========
//==========

//RlcHeader
//8	7		6	5	4	3	2		1	
//PR		TFI_____		FBI	Octet 1
//BSN___________		E		Octet 2
//LengthInd____	M		E		Octet 3 (optional)

tOCT_UINT8 pr;
tOCT_UINT8 tfi;
tOCT_UINT8 fbi;
tOCT_UINT8 bsn;
//tOCT_UINT8 extBit;
tOCT_UINT8 lenInd;
tOCT_UINT8 moreBit;
tOCT_UINT8 extBit;
}rlcMacDlHeader;


void userManagerInit();
userInfo* userAdd(logicalChannelIdentity * ch_id);
blackListedUserInfo* blacklistUserFindUsingIdentity(tOCT_UINT8 *identity , tOCT_UINT8 isItBcd, tOCT_UINT8 isItImei);
userInfo* userFindUsingLogicalChannel(logicalChannelIdentity * ch_id);
void userDeleteUsingLogicalChannel(logicalChannelIdentity * ch_id);
void clearUserContext(userInfo* info, tOCT_UINT8 tchUser, tOCT_UINT8 deleteUser);
blackListedUserInfo* userStoreBlackListedInfo(userInfo *info);
//void deleteBlacklistUserUsingIdentity(tOCT_UINT8 *identity , tOCT_UINT8 isItBcd);
void delete2gBlackListUserFromLinkedList(blackListedUserInfo *blackUserInfo);
void deleteInactiveBlacklistUsers(void);
void deleteAllBlacklistUsers();
void updateUserDb(userInfo *info , logicalChannelIdentity * ch_id );
void deleteAllUsers(void);

#endif //USERMANAGER_H_
