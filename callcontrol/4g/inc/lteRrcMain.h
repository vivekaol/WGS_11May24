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
* File Name   : lteRrcMain.h
 *
* Description : Lte RRC Layer functions header
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------------
* 09/04/2015          				 Suresh Kumar Garikipati			   Initial File Creation
*#############################################################################################
*/

#ifndef LTE_RRC_MAIN_H_
#define LTE_RRC_MAIN_H_

#include "lteAsn1Def.h"
#include "gsmCommon.h"
#include "linkedlist.h"
#include "lteRrcIntfcHandler.h"

#define SIZE_OF_IDENTITY_3GPP 								 9 // What received in 3GPP messages
#define MAX_GUTI_LENGTH                                   	 80

#define ATTACH_REJECT_TIMEOUT                         		 5000// need to be maintained at MAC for LTE case
#define TAU_REJECT_TIMEOUT                         		     1000
#define TIMER_FOR_4G_IDENTITY_REQUEST_TIMEOUT                1000 //6000*2
#define LTE_RRC_PAGING_TIMEOUT                               60000*10 // 10-min
#define TIMER_FOR_4G_SC_SIB_PAGE_RETRANSMIT					 1000
#define TIMER_FOR_4G_MEAS_REPORT_TIMEOUT					 1000*60*3 // 1Minutes
#define SIB_MODIFICATION_PAGING_COUNTER						 10
#define LTE_BL_STEP2_TIMER     					             1000*20  // 10 secs tested
#define LTE_BLACKLIST_UE_REMOVE_COUNTER           			 30 //120  //2 minutes

#define LTE_SC_KEEP_RRC_CONNECTION_TIMER               		 1000//300// At this timeout we can ask for IMSI request or UE Cap Info


#define IMSI_ID												 0x01
#define IMEI_ID_TYPE1										 0x03
#define IMEI_ID_TYPE2										 0x02
#define GUTI_ID												 0x06
#define LTE_MAX_PHR											 63

/*
* UL DCCH Data
*/
typedef enum
{
	LTE_NAS_INVALID_MSG_TYPE,
	NAS_TRACKING_AREA_UPDATE_REQ,
	NAS_EMM_ATTACH_REQUEST,
	NAS_EMM_DETACH_REQUEST	
}lteNasMsgType;

/*
* UE States
*/
typedef enum
{
	UE_WAIT_FOR_RRC_CON_SETUP_COMPLETE_LTE = 0,
	UE_WAIT_FOR_L2ACK = 1,
	UE_WAIT_FOR_IDT_IMSI = 2,
	UE_WAIT_FOR_IDT_IMEI = 3,
	UE_WAIT_FOR_IDENTITY_RESP_LTE = 4,
	UE_WAIT_FOR_ATTACH_REJECT = 5,
	UE_WAIT_FOR_TAU_REJECT = 6,
	UE_WAIT_FOR_RRC_UECAPA_ENQUIRY = 7,
	UE_WAIT_FOR_RRC_UECAPA_INFO_IN_SC = 8,
	UE_WAIT_FOR_RRC_CON_REL_REDIRECT = 9,
	UE_WAIT_FOR_RRC_CON_REL = 10,
	UE_WAIT_FOR_RRC_CONN_WL_REDIRECT = 11,
	UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG = 12,
	UE_WAIT_FOR_RRC_CONN_RECONFIG_CMPLT = 13,
	UE_WAIT_FOR_RRC_CONN_MEAS_REPORT = 14,
	UE_WAIT_FOR_RRC_CONN_REQ_CMPLT_RSP = 15,
	UE_WAIT_FOR_IDENTITY_RESP_LTE_SC = 16,
	UE_RELEASED = 17
}lteRrcUeState;

typedef struct guti_t
{
	uint8 mnc[3];
	uint8 mcc[3];
	uint16 mmegrpID;
	uint8 mmecode;
	uint32 mtmsi;
	uint8 isGutiValid;
}lteRrcGuti_t;


typedef struct lterrcUeSpecificData
{
	uint16 					crnti;
	lteRrcUeState           ueState;
	tcbTimer_t              ueTimer;
	lteRrcConnSetupCompleteStruct           ulDcchRrcSetupCmpltData;
	lteNasMsgType           nasMsgType;
	lteRrcUlDCCHData        ulDcchUlInfoTransData;
	char                    imsi[MAX_IDENTITY_LENGTH_STR_4G];
	char                    imei[MAX_IDENTITY_LENGTH_STR_4G];
	uint8                   userImsi[SIZE_OF_IDENTITY_3GPP];
	lteRrcGuti_t            guti;
	uint8 					userBlacklisted;
	uint8           		pdcp_tx_sn;
	uint32            		ueLteIMSIReqCount;
	uint8            		ueLteIMEIReqCount;
	uint8            		ueGUTIReqCount;
	uint8					wlMaskNeeded;
	uint16           		timingAdvance;
	uint8 					phr;
	uint8					ulRssiPerPrb;
	uint8					wlAttRejCause;
	uint8					additionalListInfo;
    sint32                  lastTac;
    uint8                   encodedCM2[4];
    uint8                   lengthOfCM3;
    uint8                   encodedCM3[34];
    sint32                  lastLac;
    sint16                  snr;
    uint8                   emeCallAttemptedInd;
}lteRrcUeSpecificData;


/*
* UE Control Block
*/
typedef struct lterrcUeControlBlock
{
	lteRrcUeSpecificData  lteueSpecificData[LTE_MAX_USER_SUPPORTED];
}lteRrcUeControlBlock;


typedef enum
{
	UNKOWN_STACK= 0,
	QC_STACK = 1,
	OTHER_STACK = 2
}lteBlState_;
typedef uint8 lteBlState;

typedef struct
{
	uint16     PF;
	uint16     PO;
	sint32     rsrp;
	float      rsrq;
	tcbTimer_t blTimer;
	sint32     ulRssiPhr;
	uint8      userImsi_str[MAX_IDENTITY_LENGTH_STR]; // decoded imsi
	uint8      userImsi[SIZE_OF_IDENTITY_3GPP]; // 3gpp imsi bcd
	uint32      measRepCntr;
	uint8      lteSilentCallStarted;
	fxLLteMeasurementType  measurementType;
	uint8      ueCheckFlag;
	uint8      ueCheckCntr;
	uint8      blRemoveFlag;
	uint8	   redirectEnabled;
	uint8	   rrcConRelWithRedirectLen;
	uint8	  *pRrcConRelWithRedirect;
	uint8 	  sTmsiValid;
	uint8 	   mmec;
	uint32     mTmsi;
}lteblackListedUserInfo;


void lteUlDcchHandler (lteL2IntfData_t *pRlcMsgData);
void lteDlDcchHandler (lteL2IntfData_t *pRlcMsgData);
void lteRlcResetHandler(uint16 crnti);
void buildAndEncodeIdentityMsg(int ueIndex);
void buildAndEncodeAttachRejMsg(int ueIndex);
void buildAndEncodeTAURejMsg(int ueIndex);
void buildAndEncodeRrcPagingMsg(int ueIndex);
void buildAndEncodeRrcReleaseMsg(int ueIndex);
void buildAndEncodeRrcPagingSibModMsg();
//ASHU ASN.1 Issue
void buildAndEncodeRrcPagingSibModMsgRrcThrd();
void buildAndEncodeRrcUeCapaEnqMsg(int ueIndex);
void buildAndEncodeRrcMeasConfigReqMsg(int ueIndex);
int decodeMobileIdentity(int ueIndex , unsigned char *pNasMsg);
void handleIdentityReqTimeout(tcbTimer_t *pTimer, void *pUeIndex);
void handleAttachRejTimeout(tcbTimer_t *pTimer, void *pUeIndex);
void handleTAURejTimeout(tcbTimer_t *pTimer, void *pUeIndex);
void handleRrcPagingTimeout(tcbTimer_t *pTimer, void *pUeIndex);
void handleMeasReportTimeout(tcbTimer_t *pTimer, void *pUeIndex);
void handleUeCapaEnqTimeout(tcbTimer_t *pTimer, void *pUeIndex);
void InitializeLteRrcContext (void);
void SendTimerExpirySignalToSelf(lteMsgType_e msgType , int pUeId);
void decodeGUTI(uint8* bcd , lteRrcGuti_t* guti);
void checkMobileIDCfg(int ueIndex ,int isImsi);
void searchIdDbForRecvdID(int ueIndex, tOCT_UINT8 isImsi);
void processUlMsgForImeiReq(int ueIndex, lteRrcUlDCCHData *pUlMsg);
void lteRrcReleaseUeToNwHandler(uint16 crnti);
void lteStopRrcTimer(uint16 crnti);
void lteStartRrcIdentityReqTimer(uint16 crnti);
void sendSignalToSelfTostartIdentityReqTimer(uint16 crnti);

void generatePagingSfn(int ueIndex);
lteblackListedUserInfo* lteuserStoreBlackListedInfo(int ueIndex);
void calculatePOnPF(lteblackListedUserInfo* blackUserInfo);
uint16 imsiMod1024( uint8* imsi );
lteblackListedUserInfo* blacklistLteUserFindUsingIdentity(uint8 *identity , uint8 isItBcd);
uint8 compareLteUserIdentity(lteblackListedUserInfo* info , uint8* identity , uint8 isItBcd);
lteDlPagingStruct* lteGetImsiForPaging(lteblackListedUserInfo* blackUserInfo);
void buildAndSendSibChangePagingMsg(lteblackListedUserInfo *blUser, uint8 newTAC);
void buildAndSendSibChangePagingMsgRrcThrd(lteblackListedUserInfo *blUser, uint8 newTAC);
void handle4gScSibPageRetransmitTimeoutRrcThrd(tcbTimer_t *pTimer, void *blUser);
void buildAndSendSibChangePagingMsgRrcThrd(lteblackListedUserInfo *blUser, uint8 newTAC);
void deleteBlackListUserFromLinkedListRrcThrd(listNode *blNode);
void deleteBlackListUserFromLinkedList(listNode *blNode);
void sendSignalToSelfToDeleteBLUser(listNode *blNode);
void handle4gBlTestTimeout(tcbTimer_t *pTimer, void *blUsr);
void handle4gBlQCCheckTestTimeout(tcbTimer_t *pTimer, void *blUsr);
void sendLteBlTestSibModificationPage(lteblackListedUserInfo *blUsr);
void sendSignalToSelfToPageSIBModBLTest(lteblackListedUserInfo *blUser );
void sendUeRssiPhrReportIndToClient(lteblackListedUserInfo* blackUserInfo);
listNode* searchBlNodeUsingBlUsrInfo(lteblackListedUserInfo* blackUserDelInfo);
void lteRrcPhrMeasReportHandler(lteL2IntfData_t *pRlcMsgData);
void triggerRrcReconfigMsgHanlder(uint16 crnti);
void ltePageAllConfifguredTargetPhone(void);
void convertImsiToBcd(uint8 *imsiStr, uint8 *imsi3gpp);
void calculatePOnPFfromIMSI(uint8 *imsiStr, uint16 *PO, uint16 *PF);
#endif //LTE_RRC_MAIN_H_






