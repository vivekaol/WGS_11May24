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
 * File Name   : dataIndMsgHandler.c
 *
 * Description : Function to support processing of incoming data received from the L1
 *
 * History     :
 *
 * Date                                  Author                     Details
 * ----------------------------------------------------------------------------------------
 * 15/10/2014          					Anand Kashikar            Initial File Creation
 *#########################################################################################
 */

#include "dataIndMsgHandler.h"
#include "l1Constants.h"
#include "l1InterfaceManager.h"
#include "gsmData.h"
#include "sysInfo.h"
#include "lapdm.h"
#include "linkedlist.h"
#include <pthread.h>
#include <arpa/inet.h>
#include <assert.h>
#include "logManager.h"
#include "gsmCommon.h"
#include "fxLSocketInterfaceApi.h"
#include "ratSocketItf.h"
#include "transactionMemoryManager.h"
#include "sms.h"
#include "ed_c_RR.h"
#define MAX_RETRANSMISSION_COUNT_FOR_L3_MSG       2
extern unsigned char licenseSupportedFeaturePacks[10];
extern void buildISendFrameHeader(userInfo *info);
extern unsigned char lapdmMessageHandler(tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA  *inData, userInfo * info, tOCT_UINT8 msgOnTchSapi);
extern int GsmTrxModifyTsDigitalScaling( tOCT_UINT8 nonApplicableTs );
void phMeasReportHandler(userInfo * info, tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA* data_ind);
extern int lchanMeasCheck(tOCT_INT8 tn, tOCT_INT8 sc, userInfo* info, tOCT_UINT32 fn);
void periodicTimerexpiry(tcbTimer_t *tmr , void *infoPtr);

#ifdef FEA_MT_SMS
extern void buildSapi3SABMFrameHeader(tOCT_UINT8 *sapi3SabmFrame);
#endif
extern 	tOCT_UINT8 create_address( tOCT_UINT8 address_type, tOCT_UINT8 type_of_address, tOCT_UINT8 *address, tOCT_UINT8 **address_ptr );

void phDataIndHandler();
void sabmLauReqHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi);
void sabmCmServiceReqHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi);
#ifdef FEA_DECODE_MO_SMS
void cmServiceReqHandler(userInfo* info);
#endif
void sabmPagingRespHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi);
void dataImsiIdentityRespHandler(userInfo* info);
void dataImeiIdentityRespHandler(userInfo* info, tOCT_UINT8 sapi);
void sendChannelReleaseWithRedirection(userInfo* info, redirectInfo2g* gsmRedirectInfo, tOCT_UINT8 sapi );
void dataTmsiReallocCompleteHandler(userInfo* info, tOCT_UINT8 sapi);
void dataSetupHandler(userInfo* info, tOCT_UINT8 sapi);
fxlUePositioningError dataLcsPosRespHandler(userInfo* info);
#if (defined FEA_SILENT_CALL) || (defined FEA_VOICE_CALL_TO_TARGET)
void pushUaLapdmMsgToTxDataQ(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi);
void discLapdmMsgHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi);
void callConfRespHandler(userInfo* info, tOCT_UINT8 sapi);
void preparePushAssgnCmdToTxDataQ(userInfo * info);
void sabmAssignmentCommandHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi);
void mtAlertHandler(userInfo* info, tOCT_UINT8 sapi);
void mtConnectHandler(userInfo* info, tOCT_UINT8 sapi);
void checkAndResetCallCtx(userInfo *info);
#else
void pushUaLapdmMsgToTxDataQ(tOCT_UINT8* inMsgBuf , userInfo* info);
void discLapdmMsgHandler(tOCT_UINT8* inMsgBuf , userInfo* info);
#endif
#ifdef FEA_SILENT_CALL
void sendSilentCallMeasIndOverSocket(userInfo *info);
void sendSilentCallResourcesIndOverSocket(userInfo *info, fxLSilentCallPurpose purpose);
#endif
void pushLayer3ReqToTxDataQ(userInfo* info , const tOCT_UINT8 * const stdMsgBuf, tOCT_UINT8 sapi);
void pushPagingReqToPageQ(blackListedUserInfo* info);
tOCT_UINT8 resendLayer3MessageWaitingForL2Ack(userInfo *info, tOCT_UINT8 sapi);
void sendRegistrationAttemptedIndOverSocket(userInfo *info);
void sendMoCallAttemptedIndOverSocket(userInfo *info, char* msisdn);
tOCT_UINT8 searchIdDbForRecvdIdentity(userInfo *info, tOCT_UINT8 isImsi);
ConfigList* getConfigUeIdListPtr();
void sendRssiGpsIndOverSocket(userInfo *info, fxlUePositioningInfo* gpsInfo, fxlUePositioningError gpsResult);
void sendBlUserDetachedIndOverSocket(blackListedUserInfo *blackUserInfo);
#ifdef FXL_BL_UE_POWER_OFF
void send2gBlUePowerOffInd(blackListedUserInfo *blackUserInfo, fxlBlUeDeatchCause cause);
#endif
void updateMsClassmark(userInfo* info);
void changeBLtoWLInConfigDb(blackListedUserInfo* blackUserInfo);

extern gsm_trx * trx_g;
extern rts_time * rts_time_g;

extern queue dataIndQ ;
extern listNode *headForBlacklistedUserQ;
extern listNode *tailForBlacklistedUserQ;
extern pthread_mutex_t     mutexBlacklistUserQ;
listNode *headForPagingReqQ[MAX_PAGING_PERIODICITY][MAX_PAGING_BLOCKS_IN_51_FRAME] = {{NULL}};
listNode *tailForPagingReqQ[MAX_PAGING_PERIODICITY][MAX_PAGING_BLOCKS_IN_51_FRAME] = {{NULL}};
tOCT_UINT8 socketMsgBuf[EXTERNAL_MESSAGE_SIZE];
unsigned int noOfAttemptedRegistrationInGsm;
GsmLatchedUeDetails     *pGsmLatchedUeDetails = NULL;
extern const tOCT_UINT8 const fill_frame[GSM_MACBLOCK_LEN] ;
#ifdef FEA_MT_SMS
extern tOCT_UINT8 mtBroadcastSmsL3Pdu[SMS_CP_DATA_MAX_LENGTH];
#endif
#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
extern tOCT_UINT8 sendSmsDuringRegistrationL3Pdu[SMS_CP_DATA_MAX_LENGTH];
#endif
#ifdef FEA_REJECT_CAUSE_CONTROL
extern unsigned int gsmDefaultWLRejectCause;
#endif /* FEA_REJECT_CAUSE_CONTROL */

extern tOCT_UINT8 checkForInactive2gBLUsers;

extern int exitGsmAppThreads;
extern tOCT_UINT8  logicalChannels[MAX_TS][MAX_SUBCHAN_TIMESLOT];
extern volatile signed char noOfAllocatedFullTrafficChannels;

#ifdef FEA_VOICE_CALL_TO_TARGET
callContext targetVoiceCallCntxt;
int gResetCallAnyway = FALSE;
#endif

tOCT_UINT8 tchSilentCallUnderProgress;
tOCT_UINT8 cellBarDuringTchSilentCall;

#ifdef MM_INFO
tOCT_UINT8 mmInfoReq[GSM_MACBLOCK_LEN - 2]=
{
	0x2D, 0x05, 0x32, 0x43, 0x02, 0x86, 0xE1, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};
#endif

const tOCT_UINT8 const tmsiIdentityReq[GSM_MACBLOCK_LEN - 2]=
{
	0x0D, 0x05, 0x18, 0x04, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

const tOCT_UINT8 const imsiIdentityReq[GSM_MACBLOCK_LEN - 2]=
{
	0x0D, 0x05, 0x18, 0x01, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

const tOCT_UINT8  const imeiIdentityReq[GSM_MACBLOCK_LEN - 2]=
{
	0x0D, 0x05, 0x18, 0x03, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

const tOCT_UINT8 const locUpdateAccept[GSM_MACBLOCK_LEN - 2]=
{
	0x39, 0x05, 0x02, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x17, 0x05,
	0xF4, 0x12, 0x34, 0x56, 0x78, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

const tOCT_UINT8 const locUpdateReject[GSM_MACBLOCK_LEN - 2]=
{
	0x0D, 0x05, 0x04, 0x0F, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

const tOCT_UINT8 const tmsiReallocationCmd[GSM_MACBLOCK_LEN - 2]=
{
	0x41, 0x05, 0x1A, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x05, 0xF4,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

const tOCT_UINT8 const classmarkEnquiry[GSM_MACBLOCK_LEN - 2]=
{
	0x09, 0x06, 0x13, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};


const tOCT_UINT8 const channelRelease[GSM_MACBLOCK_LEN - 2]=
{
	0x0D, 0x06, 0x0D, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

const tOCT_UINT8 const lcsPosReq[GSM_MACBLOCK_LEN - 2]=
{
	0x21, 0x06, 0x38, 0x00, 0x04, 0x40, 0x01, 0xFE, 0xD0, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};
tOCT_UINT8 rrlpGpsAssistData[RRLP_TOTAL_SEGMENTS][RRLP_GPS_ASSIST_OCTET_LEN][GSM_MACBLOCK_LEN - 2];


const tOCT_UINT8 const cmServiceReject[GSM_MACBLOCK_LEN - 2]=
{
	0x0D, 0x05, 0x22, 0x26, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};


static tOCT_UINT8 pagingReqType1[GSM_MACBLOCK_LEN]=
{
	0x31, 0x06, 0x21, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

#if 0
static tOCT_UINT8 pagingReqType3[GSM_MACBLOCK_LEN]=
{
	0x59, 0x06, 0x24, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x00, 0x00, 0x00
};
#endif

static tOCT_UINT8 cipheringModeCommand[GSM_MACBLOCK_LEN]=
{
	0x0D, 0x06, 0x35, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

#ifdef FEA_VOICE_CALL_TO_TARGET
static tOCT_UINT8 callProc[GSM_MACBLOCK_LEN]=
{
	0x09, 0x83, 0x02, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

static tOCT_UINT8 setUp[GSM_MACBLOCK_LEN]=
{
	0x00, 0x03, 0x05, 0x04, 0x01, 0xA0, 0x5C, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

static tOCT_UINT8 alert[GSM_MACBLOCK_LEN]=
{
	0x09, 0x83, 0x01, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

static tOCT_UINT8 Connect[GSM_MACBLOCK_LEN]=
{
	0x09, 0x83, 0x07, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

static tOCT_UINT8 conAck[GSM_MACBLOCK_LEN]=
{
	0x09, 0x03, 0x0F, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

static tOCT_UINT8 holdRej[GSM_MACBLOCK_LEN]=
{
	0x15, 0x83, 0x1A, 0x02, 0xE0, 0xAF, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};
#endif /* FEA_VOICE_CALL_TO_TARGET */

static tOCT_UINT8 releaseComplete[GSM_MACBLOCK_LEN - 2]=
{
	0x19, 0x03, 0x2A, 0x08, 0x02, 0xE2, 0xBF, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};

tOCT_UINT8 disconnect[GSM_MACBLOCK_LEN]=
{
	0x15, 0x03, 0x25, 0x02, 0xE1, 0x92, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

static tOCT_UINT8 releaseCmp[GSM_MACBLOCK_LEN]=
{
	0x09, 0x03, 0x2A, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

static tOCT_UINT8 release[GSM_MACBLOCK_LEN]=
{
	0x09, 0x03, 0x2D, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};
#ifdef FEA_ALERT
static tOCT_UINT8 setUpAlert[GSM_MACBLOCK_LEN]=
{
	0x00, 0x03, 0x05, 0x34, 0x00, 0x5C, 0x00, 0x00, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};
#endif

static tOCT_UINT8 disconnectNwOutOfOrder[GSM_MACBLOCK_LEN]=
{
	0x15, 0x03, 0x25, 0x26, 0xE1, 0x92, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};

#ifdef FEA_SILENT_CALL
static tOCT_UINT8 assgnCmd[GSM_MACBLOCK_LEN]=
{
	0x21, 0x06, 0x2E, 0x2B, 0x2B, 0x2B, 0x05, 0x63, 0x00, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B
};
#endif

static tOCT_UINT8 attachReject[GSM_MACBLOCK_LEN - 2]=
{
	0x0D, 0x08, 0x04, 0x07, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
	0x2B
};


stateDataInd dataIndRcvdstate = STATE_DATAIND_NOT_RECEIVED;
pthread_cond_t      conddataInd  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutexdataInd = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t     mutexPagingQ = PTHREAD_MUTEX_INITIALIZER;

void * dataIndMsgHandler(void *nothing)
{
	int ret = 0 , dataAvailable = FALSE;
	noOfAttemptedRegistrationInGsm = 0;
	logPrint(LOG_DEBUG , "dataIndMsgHandler Thread Initialized\n");
	while(1)
	{
		pthread_mutex_lock(&mutexdataInd);

		while (dataIndRcvdstate != STATE_DATAIND_RECEIVED)
			pthread_cond_wait(&conddataInd, &mutexdataInd);

		if (exitGsmAppThreads)
		{
			dataIndRcvdstate = STATE_DATAIND_NOT_RECEIVED;
			dataAvailable = FALSE;
			pthread_mutex_unlock(&mutexdataInd);
			pthread_exit(NULL);
		}

		dataAvailable = TRUE;
		dataIndRcvdstate = STATE_DATAIND_NOT_RECEIVED ;
		pthread_mutex_unlock(&mutexdataInd);

		if(dataAvailable == TRUE)
		{
			phDataIndHandler();
			dataAvailable = FALSE;
		}
	}
	return (void*)ret;
}

void phDataIndHandler()
{
	tOCT_UINT8 sapi , tsNum , sc, ignoreThisFrame = 0 ;
	tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA * data_ind = NULL;
	blackListedUserInfo* blackUserInfo = NULL;
	data_ind = deQueue(&dataIndQ);
	do
	{
		if(data_ind != NULL)
		{

			sapi  = (tOCT_UINT8) data_ind->LchId.bySAPI;
			tsNum = (tOCT_UINT8) data_ind->LchId.byTimeslotNb;
			sc    = (tOCT_UINT8) data_ind->LchId.bySubChannelNb;
			tOCT_UINT8 *evtDataContent = (tOCT_UINT8*)(( tOCT_UINT8*) data_ind + sizeof(tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA)) ;

			userInfo* info = NULL;
			logicalChannelIdentity ch_id;
			ch_id.txSLotNum = tsNum;
			if( sc == SUBCHF)
				ch_id.subChNum = 0;
			else
				ch_id.subChNum = sc;

			info = userFindUsingLogicalChannel(&ch_id);
			if(info == NULL)
			{
				logPrint(LOG_ERR , "Could not find user for this timeslot = %d and subchannel = %d \n" , tsNum , sc);
				return;
			}
			phMeasReportHandler(info, data_ind);
			lchanMeasCheck(tsNum, sc, info, rts_time_g->fn);

			if(sapi == cOCTVC1_GSM_SAPI_ENUM_SDCCH)
			{
				ignoreThisFrame = lapdmMessageHandler(data_ind, info, sapi);// First Handle layer-2 header and process it. For I-Frame send L2-Ack

				if(!ignoreThisFrame)
				{
					if( ((info->l3Msg[0] & 0x0F) == 0x05) && ((info->l3Msg[1] & 0x3F) == 0x01))
					{
						logPrint(LOG_DEBUG,"User = %p : IMSI Detach Indication Received, Previous State = %s \n ", info, logGetUserStateString(info->userPrevState));

						blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(&evtDataContent[6], TRUE, FALSE);

						if(blackUserInfo != NULL)
						{
							// Send BL-Detach Ind to Client
#ifdef FXL_BL_UE_POWER_OFF
							send2gBlUePowerOffInd(blackUserInfo, FXL_POWER_OFF);
#else
							sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif
							delete2gBlackListUserFromLinkedList(blackUserInfo);
						}

						timerStop(&info->tmr);
						if(info->userLogicalChannel.txSLotNum ||
								isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
						{
							if(!(info->userTchChannel.txSLotNum))  //Delete User as well
								clearUserContext(info, FALSE, TRUE);
							else
								clearUserContext(info, FALSE, FALSE);
						}

						if(info->userTchChannel.txSLotNum)
							clearUserContext(info, TRUE, TRUE);

					}
					else if( evtDataContent[1] == 0x3F)
					{
						if( ((evtDataContent[3] & 0x0F) == 0x05) && ((evtDataContent[4] & 0x3F) == 0x08)) // SABM
						{
							info->userPrevState = info->userState;
							info->userState = LAU_REQ_RECEIVED;
							logPrint(LOG_DEBUG,"User = %p LAU-TPYPE = %02x : SABM for LAU Received Previous State = %s\n ", info,(evtDataContent[5] & 0x03), logGetUserStateString(info->userPrevState));
							// Save the Last lac value
							info->last_lac = (evtDataContent[9] << 8) | (evtDataContent[10]);
							timerStop(&info->tmr);
    						sabmLauReqHandler(evtDataContent , info, sapi);
						}
						else if( ((evtDataContent[3] & 0x0F) == 0x05) && ((evtDataContent[4] & 0x3F) == 0x24)) // SABM
						{
							info->userPrevState = info->userState;
							info->userState = CM_SERVICE_REQ_RECEIVED;
							logPrint(LOG_DEBUG,"User = %p : SABM for CM Service Request Received Previous State = %s \n ", info, logGetUserStateString(info->userPrevState));
							timerStop(&info->tmr);
    						sabmCmServiceReqHandler(evtDataContent , info, sapi);
						}
						else if( ((evtDataContent[3] & 0x0F) == 0x06) && (evtDataContent[4] == 0x27))
						{
							info->userPrevState = info->userState;
							info->userState = PAGING_RESP_RECEIVED;
							logPrint(LOG_DEBUG,"User = %p : SABM for Paging Response Received Previous State = %s\n ", info, logGetUserStateString(info->userPrevState) , info);

							timerStop(&info->tmr);
    						sabmPagingRespHandler(evtDataContent , info, sapi);
						}

					}
					else if( evtDataContent[1] == 0x53 )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = DISC_RECEIVED;
						logPrint(LOG_INFO,"User = %p : DISC_RECEIVED Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
#ifdef FEA_SILENT_CALL
    					discLapdmMsgHandler(evtDataContent , info, sapi);
#else
						discLapdmMsgHandler(evtDataContent , info);
#endif
					}
#ifdef FEA_DECODE_MO_SMS
					/* CM-Serv-Req during Concatenated MO-SMS */
					else if( ((info->l3Msg[0] & 0x0F) == 0x05) && ((info->l3Msg[1] & 0x3F) == 0x24))
					{
						info->userPrevState = info->userState;
						info->userState = CM_SERVICE_REQ_RECEIVED;
						logPrint(LOG_DEBUG,"User = %p : CM Service Request Received Previous State = %s \n ", info, logGetUserStateString(info->userPrevState));
						timerStop(&info->tmr);
						cmServiceReqHandler(info);
					}
#endif
					else if( ((info->l3Msg[0] & 0x0F) == 0x05) && ((info->l3Msg[1] & 0x3F) == 0x19))
					{
						timerStop(&info->tmr);

						if((info->l3Msg[3] & 0x07) == 0x01)
						{
							/* Store IMSI value */
							memcpy(info->userImsi , &info->l3Msg[2] , SIZE_OF_IDENTITY);

							info->userPrevState = info->userState;
							info->userState = IMSI_RECEIVED;

							logPrint(LOG_DEBUG, "User = %p : Received Identity response, Identity Type: IMSI  Previous State = %s\n" , info, logGetUserStateString(info->userPrevState));

							dataImsiIdentityRespHandler(info);
							info->retransmissionCountForL3Msg = 0;
                            pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
							logPrint(LOG_DEBUG, "User = %p : Sending classmarkEnquiry, User State = %s \n" , info, logGetUserStateString(info->userState));
						}
						else if((info->l3Msg[3] & 0x07) == 0x03)
						{
							info->userPrevState = info->userState;
							info->userState = IMEI_RECEIVED;

							logPrint(LOG_DEBUG, "User = %p : Received Identity response, Identity Type: IMEI Previous State = %s\n" , info, logGetUserStateString(info->userPrevState));

							dataImeiIdentityRespHandler(info, sapi);
							/* Send IMSI, IMEI over Socket */
							sendRegistrationAttemptedIndOverSocket(info);
						}
						else if((info->l3Msg[3] & 0x07) == 0x04)
						{
							/* Store TMSI value */
							memcpy(info->userTmsi , &info->l3Msg[2] , SIZE_OF_TMSI);

							pushLayer3ReqToTxDataQ(info , imsiIdentityReq, sapi);
							logPrint(LOG_DEBUG , "User = %p : Received TMSI, Sending imsiIdentityReq" , info);
							info->retransmissionCountForL3Msg = 0;
						}
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x05) && ((info->l3Msg[1] & 0x3F) == 0x1B ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = TMSI_REALLOCATION_COMPLETE_RECEIVED;
						logPrint(LOG_DEBUG,"User = %p : TMSI_REALLOCATION_COMPLETE_RECEIVED Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
						if(trx_g->bts.redirType == FXL_GSM_NO_REDIR)
						{
							dataTmsiReallocCompleteHandler(info, sapi);
						}
						else
						{
							redirectInfo2g redirectInfo;
							redirectInfo.bandIndicator = trx_g->bts.redirBand;
							redirectInfo.arfcn = trx_g->bts.redirArfcn;
							redirectInfo.bsic = trx_g->bts.redirBsic;

							/* Send Channel Release filling redirect info. */
							sendChannelReleaseWithRedirection(info, &redirectInfo, sapi);
						}
					}
					else if(((info->l3Msg[0] & 0x0F) == 0x06) && (info->l3Msg[1] == 0x32))
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = CIPHERING_MODE_COMPLETE_RECEIVED;
						logPrint(LOG_DEBUG,"User = %p : CIPHERING_MODE_COMPLETE_RECEIVED Previous State = %s\n ",
								info, logGetUserStateString(info->userPrevState));

#if defined(FEA_MT_SMS) || defined(FEA_2G_SEND_SMS_DURING_REGISTRATION)

						blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);


#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
						if(      (trx_g->bts.sendSmsDuringRegistration == TRUE)
								&&  ((blackUserInfo != NULL)
									&& (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_INDIVIDUAL_SMS) != SET_TRIGGER_FOR_INDIVIDUAL_SMS)
										&&  ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BROADCAST_SMS)  != SET_TRIGGER_FOR_BROADCAST_SMS))))
						{
							info->mtSmsL3Pdu = sendSmsDuringRegistrationL3Pdu;
						}
#endif
						if(
#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
								((trx_g->bts.sendSmsDuringRegistration == TRUE)
								 &&   (info->cmServiceReqTypeRcvd == 0)) ||
#endif
								((blackUserInfo != NULL)
								 && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_INDIVIDUAL_SMS) == SET_TRIGGER_FOR_INDIVIDUAL_SMS)
									 ||  ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BROADCAST_SMS) == SET_TRIGGER_FOR_BROADCAST_SMS))))
						{
							// Establish Lapdm SAPI-3 Multiframe mode connection.
							tOCT_UINT8* sapi3SabmFrame = getTxDataBuffer();
							assert(sapi3SabmFrame != NULL);
							memcpy(sapi3SabmFrame,	fill_frame, GSM_MACBLOCK_LEN); // Copy standard message

                            transactMemoryParams params;
                            params.pushToTail = TRUE;
                            params.sapi       = SAPI_SDCCH;

							buildSapi3SABMFrameHeader(sapi3SabmFrame);
    					    pushMsgToTransactionMemoryManager((void*)sapi3SabmFrame , &info->userLogicalChannel, params); // Put this message to tail
							info->retransmissionCountForL3Msg = 0;
							info->userPrevState = EST_L2_SAPI3_FOR_MT_SMS;
							info->userState = WAITING_FOR_L2ACK;
							logPrint(LOG_DEBUG, "User = %p : Establishing L2 SAPI-3 for MT-SMS, sending SabmFrame\n" , info);
						}
#endif /* FEA_MT_SMS || FEA_2G_SEND_SMS_DURING_REGISTRATION*/
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x05 ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = SETUP_RECEIVED;
						logPrint(LOG_DEBUG,"User = %p : SETUP_RECEIVED Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
						dataSetupHandler(info, sapi);
					}
					else if(((info->l3Msg[0] & 0x0F) == 0x06) && (info->l3Msg[1] == 0x38))
					{
						timerStop(&info->tmr);

						logPrint(LOG_DEBUG, "User = %p : RRLP - %s", info, gsmL3PduHexdump(info->l3Msg, info->l3MsgLen));
						logPrint(LOG_DEBUG, "User = %p : RRLP - APDU ID, Protocol Identifer = %d", info, (info->l3Msg[2] & 0x0F));

						if((info->l3Msg[2] & 0x0F) == 0x00) /* RRLP/LCS Message, Continue decoding */
						{
							switch((info->l3Msg[4] & 0x0E) >> 1)
							{
								case 0x01: /* MS Positioning Response */
									{
										logPrint(LOG_DEBUG,"User = %p : RRLP - LCS_POS_RECEIVED Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));

										if(FXL_UE_POS_ERR_ASSISTANCE_DATA_MISSING == dataLcsPosRespHandler(info))
										{
											/* Send First Segment of RRLP GPS Assistance Data */
											info->rrlpGpsAssistCount   = 0;
											info->rrlpGpsAssistSegment = 0;
											info->userState = RRLP_GPS_ASSIST_DATA_SENT;
											info->retransmissionCountForL3Msg = 0;
											pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapi);
											logPrint(LOG_DEBUG, "User = %p : RRLP - Sending rrlpGpsAssistData[%d][%d], User State = %s \n" , info, info->rrlpGpsAssistSegment,(info->rrlpGpsAssistCount-1), logGetUserStateString(info->userState));

											return;
										}
									}
									break;

								case 0x03: /* Assistance Data Ack */
									{
										logPrint(LOG_DEBUG, "User = %p : RRLP - Assistance Data Ack Received on SDCCH for Segment = %d", info, info->rrlpGpsAssistSegment);

										if(info->rrlpGpsAssistSegment < RRLP_TOTAL_SEGMENTS - 1)
										{
											/* Send Next Segment of RRLP GPS Assistance Data */
											info->rrlpGpsAssistSegment++;
											info->rrlpGpsAssistCount = 0;
											info->userState = RRLP_GPS_ASSIST_DATA_SENT;
											info->retransmissionCountForL3Msg = 0;
											pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapi);
											logPrint(LOG_DEBUG, "User = %p : RRLP - Sending rrlpGpsAssistData[%d][%d], User State = %s \n" , info, info->rrlpGpsAssistSegment,(info->rrlpGpsAssistCount-1), logGetUserStateString(info->userState));
											return;
										}
										else
										{
											/* All RRLP segments sent, reset counters */
											info->rrlpGpsAssistSegment = 0;
											info->rrlpGpsAssistCount = 0;
											info->userState = RRLP_GPS_ASSIST_DATA_ACK_RCVD;
											info->retransmissionCountForL3Msg = 0;
											pushLayer3ReqToTxDataQ(info , lcsPosReq, sapi);
											logPrint(LOG_DEBUG, "User = %p : Sending lcsPosReq, User State = %s \n" , info, logGetUserStateString(info->userState));
											return;
										}
									}
									break;

								case 0x04: /* Protocol Error */
									{
										logPrint(LOG_DEBUG, "User = %p : RRLP - Protocol Error Received", info);
									}
									break;

								case 0x05: /* Unknown/Reserved */
									{
										logPrint(LOG_DEBUG, "User = %p : RRLP - Unknown Message Received", info);
									}
									break;

								default:
									break;
							}

							info->userPrevState = info->userState;
							info->userState = LCS_POS_RECEIVED;

							/* Send Channel Release */
							info->retransmissionCountForL3Msg = 0;
							pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
							logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
						}
					}
					else if (((info->l3Msg[0] & 0x0F) == 0x06) && (info->l3Msg[1] == 0x34))
					{
						timerStop(&info->tmr);
						info->gprsSuspReceived = TRUE;

						blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
						if(blackUserInfo != NULL)
							blackUserInfo->gprsSuspExpectedFromThisUe = info->gprsSuspReceived;

						logPrint(LOG_DEBUG,"User = %p : GPRS Suspension Received\n " , info);
						// If we don't receive within the expiry of timer then the userState will be either WAITING_FOR_L2ACK or IMEI_RECEIVED
						if(info->userState == LAU_REQ_RECEIVED)
						{
							//Send IMSI Identity Req
							info->retransmissionCountForL3Msg = 0;
    						pushLayer3ReqToTxDataQ(info , imsiIdentityReq, sapi);
							logPrint(LOG_DEBUG, "User = %p : Sending imsiIdentityReq, User State = %s \n" , info, logGetUserStateString(info->userState));
						}
						else if(info->userState == CM_SERVICE_REQ_RECEIVED)// Waiting for GPRS Suspension Req
						{
							if(info->userBlacklisted == TRUE)
							{
								//Send Cipher Mode Command
								info->retransmissionCountForL3Msg = 0;
    							pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
								logPrint(LOG_DEBUG, "User = %p : Sending cipheringModeCommand, User State = %s \n" , info, logGetUserStateString(info->userState));
							}
							else
							{
								//Send IMSI Identity Req
								info->retransmissionCountForL3Msg = 0;
    							pushLayer3ReqToTxDataQ(info , imsiIdentityReq, sapi);
								logPrint(LOG_DEBUG, "User = %p : Sending imsiIdentityReq, User State = %s \n" , info, logGetUserStateString(info->userState));
							}
						}
						else if (info->userState == PAGING_RESP_RECEIVED)
						{
							if(info->userBlacklisted == TRUE)
							{
								if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RELEASE) == SET_TRIGGER_FOR_RELEASE))
								{
									/* Send TMSI Reallocation command */
									info->retransmissionCountForL3Msg = 0;
									pushLayer3ReqToTxDataQ(info , tmsiReallocationCmd, sapi);
									logPrint(LOG_DEBUG, "User = %p : Sending TMSI Reallocation command\n" , info);
								}

								else if(  blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_REDIRECTION) == SET_TRIGGER_FOR_REDIRECTION) )
								{
									/* Send Channel Release filling redirect info. */
									sendChannelReleaseWithRedirection(info, &blackUserInfo->redirectInfo, sapi);
								}

#ifdef FEA_SILENT_CALL
								else if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL))
								{
									blackUserInfo->triggerPagingReq = FALSE;
									// Send Silent Call allocated resources Indication to client.
									sendSilentCallResourcesIndOverSocket(info, FXL_SDCCH_SILENT_CALL);
									info->userState = SDCCH_SILENT_CALL_IN_PROGRESS;

									//Sending Classmark Enquiry to keep some active transaction during silent call
    								pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
									logPrint(LOG_DEBUG , "User = %p : Sending classmarkEnquiry, User State = %s \n" , info, logGetUserStateString(info->userState));
									info->retransmissionCountForL3Msg = 0;
								}
#endif
#ifdef FEA_MT_SMS
								else if(blackUserInfo != NULL && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_INDIVIDUAL_SMS) == SET_TRIGGER_FOR_INDIVIDUAL_SMS) || \
											((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BROADCAST_SMS) == SET_TRIGGER_FOR_BROADCAST_SMS)) )
								{
									//Send Cipher Mode Command
									info->retransmissionCountForL3Msg = 0;
    								pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
									logPrint(LOG_DEBUG, "User = %p : Sending cipheringModeCommand, User State = %s \n" , info, logGetUserStateString(info->userState));
								}
#endif

								else if (blackUserInfo != NULL &&
										(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) == SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) ||
										 ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) == SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) ) )
								{
									//Send LCS Positioning Request
									info->retransmissionCountForL3Msg = 0;
									pushLayer3ReqToTxDataQ(info , lcsPosReq, sapi);
									logPrint(LOG_DEBUG, "User = %p : Sending lcsPosReq, User State = %s \n" , info, logGetUserStateString(info->userState));
								}
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
								else if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK) == SET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK))
								{
									blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK;
									//Send Channel Release
									info->retransmissionCountForL3Msg = 0;
                                    pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
									logPrint(LOG_DEBUG, "blackUserInfo = %p, IMSI = %s : Paging validity check succeeded sending channelRelease\n" , blackUserInfo, blackUserInfo->userImsi_str);
								}
#endif
								else
								{
									//Send Channel Release
									info->retransmissionCountForL3Msg = 0;
    								pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
									logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
								}

							}
							else
							{
								if(info->userTmsi[0] != 0 )  /* TMSI already received */
								{
									pushLayer3ReqToTxDataQ(info , imsiIdentityReq, sapi);
									logPrint(LOG_DEBUG , "User = %p : Sending first time imsiIdentityReq after expiry of waiting for GPRS suspension\n" , info);
									info->retransmissionCountForL3Msg = 0;
								}
								else
								{
									pushLayer3ReqToTxDataQ(info , tmsiIdentityReq, sapi);
									logPrint(LOG_DEBUG , "User = %p : Sending first time tmsiIdentityReq after expiry of waiting for GPRS suspension\n" , info);
									info->retransmissionCountForL3Msg = 0;
								}
							}
						}

						else if(info->userState == WAITING_TO_SEND_SETUP)
						{
							if (blackUserInfo != NULL && info->userPrevState == PAGING_RESP_RECEIVED)		// send SETUP message
							{
								logPrint(LOG_DEBUG, "Trigger check: Curr val 0x%x\n",blackUserInfo->bitMaskForTriggers);
								info->retransmissionCountForL3Msg = 0;
								if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING)
								{
#ifdef FEA_ALERT
									tOCT_UINT8 callingBcd_length, *tmpPtr = NULL;
									tOCT_UINT8 tmpSetUpAlert[GSM_MACBLOCK_LEN] = {0};

									memcpy(tmpSetUpAlert, setUpAlert, GSM_MACBLOCK_LEN);

									tmpPtr = &tmpSetUpAlert[6];
									if(blackUserInfo->alertIsdn_str != NULL)
									{
										logPrint(LOG_DEBUG, "MSISDN is %s\n",blackUserInfo->alertIsdn_str);
										callingBcd_length = create_address(SMS_SMSC_ADDRESS, TOA_TON_INTERNATIONAL | TOA_NPI_ISDN, ( tOCT_UINT8* )blackUserInfo->alertIsdn_str, &tmpPtr);
									}
									else
									{
										callingBcd_length = create_address(ISDN_ADDRESS , TOA_TON_UNKNOWN | TOA_NPI_UNKNOWN, ( tOCT_UINT8* )blackUserInfo->alertIsdn_str, &tmpPtr);
									}
									tmpSetUpAlert[0] = (((callingBcd_length + 5) << 2) | 0x01);  // L2 Length

    								pushLayer3ReqToTxDataQ(info , tmpSetUpAlert, sapi);
									logPrint(LOG_DEBUG, "User = %p : Sending SETUP for Alerting, User State = %s \n" , info, logGetUserStateString(info->userState));
#endif /* FEA_ALERT */
								}
#ifdef FEA_VOICE_CALL_TO_TARGET
								else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL)
								{
									userInfo* moInfo = NULL;
									ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
									ch_id.subChNum  = targetVoiceCallCntxt.moSubChan;

									if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum > 0)) //&& (ch_id.subChNum < MAX_SUBCHAN_TIMESLOT))
									{
										moInfo = userFindUsingLogicalChannel(&ch_id);
									}
									if((targetVoiceCallCntxt.moTsNum == 0xFF) || (moInfo == NULL))
									{
										logPrint(LOG_DEBUG, "User = %p : MO already Disconnected Sending channelRelease to MT, User State = %s", info, logGetUserStateString(info->userState));
										info->retransmissionCountForL3Msg = 0;
                                        pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
									}
									else
									{
										tOCT_UINT8 callingBcd_length, *tmpPtr = NULL;
										tOCT_UINT8 tmpSetUp[GSM_MACBLOCK_LEN] = {0};

										memcpy(tmpSetUp, setUp, GSM_MACBLOCK_LEN);

										tmpPtr = &tmpSetUp[7];
										if(targetVoiceCallCntxt.moMsIsdnStr != NULL)
										{
											logPrint(LOG_DEBUG, "MO-MSISDN for Target Voice Call is %s\n",targetVoiceCallCntxt.moMsIsdnStr);
											callingBcd_length = create_address(SMS_SMSC_ADDRESS, TOA_TON_INTERNATIONAL | TOA_NPI_ISDN, ( tOCT_UINT8* )targetVoiceCallCntxt.moMsIsdnStr, &tmpPtr);
										}
										else
										{
											callingBcd_length = create_address(ISDN_ADDRESS , TOA_TON_UNKNOWN | TOA_NPI_UNKNOWN, ( tOCT_UINT8* )targetVoiceCallCntxt.moMsIsdnStr, &tmpPtr);
										}
										tmpSetUp[0] = (((callingBcd_length + 9) << 2) | 0x01);  // L2 Length

                                        pushLayer3ReqToTxDataQ(info , tmpSetUp, sapi);

										logPrint(LOG_DEBUG, "User = %p : Sending SETUP, User State = %s \n" , info, logGetUserStateString(info->userState));
									}
								}
#endif /* FEA_VOICE_CALL_TO_TARGET */
								else
								{}
							}
						}
						else if (info->userState == IMSI_RECEIVED)
						{
							//Send IMSI Identity Req
							info->retransmissionCountForL3Msg = 0;
    						pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
							logPrint(LOG_DEBUG, "User = %p : Sending classmarkEnquiry, User State = %s \n" , info, logGetUserStateString(info->userState));
						}
#ifdef FEA_SILENT_CALL
						else if (info->userState == TCH_ALLOCATED)
						{
							preparePushAssgnCmdToTxDataQ(info);
							info->retransmissionCountForL3Msg = 0;
							logPrint(LOG_DEBUG,"User = %p : Sending assgnCmd after expiry of waiting for GPRS suspension\n" , info);
						}
#endif
					}
					else if(((info->l3Msg[0] & 0x0F) == 0x06) && (info->l3Msg[1] == 0x16))
					{
						timerStop(&info->tmr);
						logPrint(LOG_DEBUG,"User = %p : CLASSMARK Msg Received(%s) \n ", info, gsmL3PduHexdump(info->l3Msg, info->l3MsgLen));

						updateMsClassmark(info);

						if(info->userPrevState == IMSI_RECEIVED)
						{
							info->userPrevState = info->userState;
							info->userState = CLASSMARK_RECEIVED;
							info->retransmissionCountForL3Msg = 0;
                            pushLayer3ReqToTxDataQ(info , imeiIdentityReq, sapi);
							logPrint(LOG_DEBUG, "User = %p : Sending imeiIdentityReq, User State = %s \n" , info, logGetUserStateString(info->userState));
						}
						else
						{
#ifdef FEA_SILENT_CALL
							blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
							if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL))
							{
								info->userState = SDCCH_SILENT_CALL_IN_PROGRESS;
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
								blackUserInfo->pagingInactivityCounter = 0;
#endif
        	    	            pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
								logPrint(LOG_DEBUG, "User = %p : Sending classmarkEnquiry, User State = %s \n" , info, logGetUserStateString(info->userState));
							}
#endif
						}
					}
#if defined(FEA_ALERT) || defined(FEA_VOICE_CALL_TO_TARGET)
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x08 ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = CALL_CONF_RCVD;
						logPrint(LOG_DEBUG,"User = %p : CALL_CONF Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
#ifdef FEA_VOICE_CALL_TO_TARGET
						gResetCallAnyway = FALSE; //since MM connection is established and call shall be released gracefully
#endif
						callConfRespHandler(info, sapi );
					}
#ifdef FEA_VOICE_CALL_TO_TARGET
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x01 ) )
					{
						timerStop(&info->tmr);
						if(((blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE)) != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING))
						{
							info->userPrevState = info->userState;
							info->userState = ALERT_RCVD;
							logPrint(LOG_DEBUG,"User = %p :RING RING !!!! On MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							mtAlertHandler(info, sapi);
						}
					}

					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x07 ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = PH_CONNECT_RCVD;
						logPrint(LOG_DEBUG,"User = %p :CONNECT Rcvd from MT Previous State = %s", info, logGetUserStateString(info->userPrevState));
						mtConnectHandler( info, sapi );
					}
#endif /* FEA_VOICE_CALL_TO_TARGET */
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x2D ) )
					{
						timerStop(&info->tmr);
						if(((blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE)) != NULL))
						{
							info->userPrevState = info->userState;
							info->userState = REL_PROC;
							logPrint(LOG_DEBUG,"User = %p :REL rcvd from  MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							logPrint(LOG_DEBUG,"User = %p :Sending REL_COMP \n ", info);
     				        pushLayer3ReqToTxDataQ(info , releaseCmp, sapi);
						}

					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x25 ) )
					{
						timerStop(&info->tmr);
						if(((blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE)) != NULL))
						{
							info->userPrevState = info->userState;
							info->userState = WAITING_FOR_REL_CMP;
							logPrint(LOG_DEBUG,"User = %p :DISC rcvd from  MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							logPrint(LOG_DEBUG,"User = %p :Sending REL \n ", info);
     				        pushLayer3ReqToTxDataQ(info , release, sapi);
						}

					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x2A ) )
					{
						timerStop(&info->tmr);
						if(((blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE)) != NULL))
						{
							info->userPrevState = info->userState;
							info->userState = WAITING_FOR_REL_CMP;		//Wouldn't matter
							info->userPrevState = info->userState;
							logPrint(LOG_DEBUG,"User = %p :RLC rcvd from  MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
    					    pushLayer3ReqToTxDataQ(info , channelRelease, sapi);

							if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING)
                            {
								blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_ALERTING;

								/* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
								if(configUeIdList.defaultConfig == BLACKLIST)
								{
									tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
									if(retVal == RC_TCB_OK)
									  logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on release complete for alert ");
							    }
                            }
						}
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x07 ) )
					{
						timerStop(&info->tmr);
						logPrint(LOG_DEBUG,"User = %p :CONNECT Rcvd\n ", info);
						if(((blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE)) != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING))
						{
							/*Send DISCONNECT*/
							info->userPrevState = info->userState;
							info->userState = DISC_SENT;
							logPrint(LOG_DEBUG , "User = %p : Going to send DISC Nw_OutOfOrder, User State = %s \n" , info, logGetUserStateString(info->userState));
    						pushLayer3ReqToTxDataQ(info , disconnectNwOutOfOrder, sapi);
						}
					}
#endif /* FEA_ALERT || FEA_VOICE_CALL_TO_TARGET */
					else if( ((info->l3Msg[0] & 0x0F) == 0x08) && (info->l3Msg[1] == 0x01) ) /* ATTACH_REQUEST */
					{
						logPrint(LOG_DEBUG, "User = %p : ATTACH REQUEST Received", info);

						/* Send Attach Reject, cause GPRS Services not allowed */
						info->userPrevState = info->userState;
						info->userState = ATTACH_RECEIVED;
                        pushLayer3ReqToTxDataQ(info , attachReject, sapi);
					}

					else
					{
						logPrint(LOG_DEBUG,"User = %p : UnHandled Message( %s )", info, gsmL3PduHexdump(info->l3Msg, info->l3MsgLen));
					}
				}	/*ignoreThisFrame */
				else
				{
					if( !((data_ind->Data.ulDataLength == 0)         ||
								(evtDataContent[1] == 0x03) ||
								(evtDataContent[1] == 0x73) ||
								(((evtDataContent[1]) & 0x03) == 0x01)))
					{
						logPrint(LOG_DEBUG,"User = %p : Ignored Message( %s )", info, gsmL3PduHexdump(evtDataContent, 23));
					}
				}

			}

#if defined (FEA_SILENT_CALL) || defined (FEA_VOICE_CALL_TO_TARGET)
			else if(sapi == cOCTVC1_GSM_SAPI_ENUM_SACCH)
			{
				if(info != NULL && ((info->userImsi[1] & 0x07) == 0x01))
				{
					if(data_ind->Data.ulDataLength != 0)
						info->measReport.timingAdvance   = evtDataContent[1];

					info->l1MeasFlag |= UL_M_F_L1_VALID;
					if(((evtDataContent[5] & 0x0F) == 0x06) && (evtDataContent[6] == 0x15))
					{
						c_MEASUREMENT_REPORT_UP decodedMeasReport;
						INIT_c_MEASUREMENT_REPORT_UP(&decodedMeasReport);
						DECODE_c_MEASUREMENT_REPORT_UP(&evtDataContent[5], 0, &decodedMeasReport, 18*8);

						info->initialMeasReport.dlRxLevFull     = decodedMeasReport.MeasurementResults.RXLEV_FULL_SERVING_CELL;
						info->initialMeasReport.dlRxLevSub      = decodedMeasReport.MeasurementResults.RXLEV_SUB_SERVING_CELL;
						info->initialMeasReport.dlRxQualFull    = decodedMeasReport.MeasurementResults.RXQUAL_FULL_SERVING_CELL;
						info->initialMeasReport.dlRxQualSub     = decodedMeasReport.MeasurementResults.RXQUAL_SUB_SERVING_CELL;
						FREE_c_MEASUREMENT_REPORT_UP(&decodedMeasReport);
					}

					blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

					if((isTimeSlotTypeSupportsTCHF(tsNum) == TRUE) || (isTimeSlotTypeSupportsTCHH(tsNum) == TRUE) ||
							((blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL))))
					{
						// Octasic BTS :In case of SACCH, data len will be sent as zero if CRC fails in PHY
						if(data_ind->Data.ulDataLength == 0)
						{
							if(info->rltCounter > 0)
							{
								info->rltCounter--;

								if(info->rltCounter == 0)
								{
									logPrint(LOG_DEBUG,"RADIO_LINK_FAILURE occured for TS = %d, SC = %d", tsNum, sc);

									if(blackUserInfo != NULL)
									{
#ifdef FXL_BL_UE_POWER_OFF
										send2gBlUePowerOffInd(blackUserInfo, FXL_UE_OUT_OF_RANGE);
#else
										sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif
										delete2gBlackListUserFromLinkedList(blackUserInfo);
									}
									timerStop(&info->tmr);

									if(info->userLogicalChannel.txSLotNum ||
											isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
									{
										if(!(info->userTchChannel.txSLotNum))  //Delete User as well
											clearUserContext(info, FALSE, TRUE);
										else
											clearUserContext(info, FALSE, FALSE);
									}

									if(info->userTchChannel.txSLotNum)
										clearUserContext(info, TRUE, TRUE);

								}
							}
						}
						else
						{
							if(info->rltCounter < trx_g->bts.radio_link_timeout)
							{
								info->rltCounter += 2;

								if(info->rltCounter > trx_g->bts.radio_link_timeout)
									info->rltCounter = trx_g->bts.radio_link_timeout;
							}
						}
					}

					if(blackUserInfo != NULL && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL) ||
								((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)))
					{
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
						blackUserInfo->pagingInactivityCounter = 0;
#endif
						/* Decode Measurement Report */
						if(((evtDataContent[5] & 0x0F) == 0x06) && (evtDataContent[6] == 0x15))
						{
							unsigned int i = 0;
							c_MEASUREMENT_REPORT_UP decodedMeasReport;

							INIT_c_MEASUREMENT_REPORT_UP(&decodedMeasReport);

							DECODE_c_MEASUREMENT_REPORT_UP(&evtDataContent[5], 0, &decodedMeasReport, 18*8);

							info->measReport.timingAdvance   = evtDataContent[1];
							info->measReport.msPowerUsed     = evtDataContent[0] & 0x1F;

							info->measReport.baUsed          = decodedMeasReport.MeasurementResults.BA_USED;
							info->measReport.ulDtxUsed       = decodedMeasReport.MeasurementResults.DTX_USED;
							info->measReport.measValid       = decodedMeasReport.MeasurementResults.MEAS_VALID;

							info->measReport.dlRxLevFull     = decodedMeasReport.MeasurementResults.RXLEV_FULL_SERVING_CELL;
							info->measReport.dlRxLevSub      = decodedMeasReport.MeasurementResults.RXLEV_SUB_SERVING_CELL;
							info->measReport.dlRxQualFull    = decodedMeasReport.MeasurementResults.RXQUAL_FULL_SERVING_CELL;
							info->measReport.dlRxQualSub     = decodedMeasReport.MeasurementResults.RXQUAL_SUB_SERVING_CELL;

							info->measReport.numOfCellsMeasured = decodedMeasReport.MeasurementResults.NO_NCELL_M;

							if(info->measReport.numOfCellsMeasured >= 1 && info->measReport.numOfCellsMeasured <= 6)
							{
								for(i = 0; i < info->measReport.numOfCellsMeasured; i++)
								{
#ifdef FEA_2G_INTER_RAT_MEAS
									/* 3GPP TS 44.018, 10.5.2.20, Measurement Results */

									if(blackUserInfo->si5Neighbors.nbr_of_arfcns > 31)
									{
										info->measReport.neigh[i].measRatType = FXL_RAT_2G;
									}
									else if(decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BCCH_FREQ_NCELL < 31 )
									{
										if( (blackUserInfo->measInfo.lteNeighbors.noEutranFreqs == 0) || \
												((blackUserInfo->measInfo.lteNeighbors.noEutranFreqs != 0) &&\
												 (blackUserInfo->si5Neighbors.nbr_of_arfcns > (31 - blackUserInfo->measInfo.lteNeighbors.noEutranFreqs))))
										{
											info->measReport.neigh[i].measRatType = FXL_RAT_2G;
										}
										else if(decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BCCH_FREQ_NCELL >= \
												(31 - blackUserInfo->measInfo.lteNeighbors.noEutranFreqs))
										{
											info->measReport.neigh[i].measRatType = FXL_RAT_4G;
										}
										else
										{
											info->measReport.neigh[i].measRatType = FXL_RAT_2G;
										}
									}
									else if(decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BCCH_FREQ_NCELL >= 31)
									{
										info->measReport.neigh[i].measRatType = FXL_RAT_3G;
									}
									else
									{
										info->measReport.neigh[i].measRatType = FXL_RAT_NONE;
									}

									if(info->measReport.neigh[i].measRatType == FXL_RAT_2G)
									{
										info->measReport.neigh[i].u.gsmNeighCell.arfcn       = blackUserInfo->si5Neighbors.arfcns[decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BCCH_FREQ_NCELL];
										info->measReport.neigh[i].u.gsmNeighCell.bsic        = decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BSIC_NCELL;
										info->measReport.neigh[i].u.gsmNeighCell.rxlev_Rssi  = decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->RXLEV_NCELL;
									}
									else if(info->measReport.neigh[i].measRatType == FXL_RAT_3G)
									{
										tOCT_UINT8 umtsNeighIndex = (decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BCCH_FREQ_NCELL - 31);

										info->measReport.neigh[i].u.umtsNeighCell.uarfcn          = blackUserInfo->gsm3gNeighCellList[umtsNeighIndex].uarfcn;
										info->measReport.neigh[i].u.umtsNeighCell.psc             = blackUserInfo->gsm3gNeighCellList[umtsNeighIndex].psc;
										info->measReport.neigh[i].u.umtsNeighCell.rxlev_Rscp_ecNo = decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->RXLEV_NCELL;
									}
									else if(info->measReport.neigh[i].measRatType == FXL_RAT_4G)
									{
										tOCT_UINT8 lteNeighIndex = (30 - decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BCCH_FREQ_NCELL);

										if(lteNeighIndex >= 0 && lteNeighIndex < FXL_2G_MAX_4G_NEIGHBOR_EARFCNS)
										{
											info->measReport.neigh[i].u.lteNeighCell.earfcn          = blackUserInfo->measInfo.lteNeighbors.eutranFreq[lteNeighIndex].earfcn;
											info->measReport.neigh[i].u.lteNeighCell.pcid            = (int)((decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BSIC_NCELL  & 0x3F) |      \
													((decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->RXLEV_NCELL & 0x07) << 6));
											info->measReport.neigh[i].u.lteNeighCell.rxlev_Rsrp_Rsrq =  (tOCT_UINT8)(decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->RXLEV_NCELL & 0x38) >> 3;
										}
									}
									else
									{}
#else
									info->measReport.neigh[i].measRatType = FXL_RAT_2G;
									info->measReport.neigh[i].u.gsmNeighCell.arfcn       = blackUserInfo->si5Neighbors.arfcns[decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BCCH_FREQ_NCELL];
									info->measReport.neigh[i].u.gsmNeighCell.bsic        = decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->BSIC_NCELL;
									info->measReport.neigh[i].u.gsmNeighCell.rxlev_Rssi  = decodedMeasReport.MeasurementResults.NCELL_Report.data[i]->RXLEV_NCELL;
#endif /* FEA_2G_INTER_RAT_MEAS */
								}
							}

							FREE_c_MEASUREMENT_REPORT_UP(&decodedMeasReport);

                            if(!info->measReport.measValid) /* measValid == 0; Measurements are valid */
                              sendSilentCallMeasIndOverSocket(info);
						}
						//logPrint(LOG_DEBUG, "UL SACCH Block = %s", gsmL3PduHexdump(evtDataContent, 23));
					}
					else
					{}
				}
			}
			else if(sapi == cOCTVC1_GSM_SAPI_ENUM_FACCHF || sapi == cOCTVC1_GSM_SAPI_ENUM_FACCHH)
			{
                tOCT_UINT8 sapiForTxDataQ;

                if(sapi == cOCTVC1_GSM_SAPI_ENUM_FACCHF)
                  sapiForTxDataQ = SAPI_TCHF;
                else
                  sapiForTxDataQ = SAPI_TCHH;

				ignoreThisFrame =	lapdmMessageHandler(data_ind, info, sapiForTxDataQ);// First Handle layer-2 header and process it. For I-Frame send L2-Ack

				if(!ignoreThisFrame)
				{
					if( evtDataContent[1] == 0x3F)
					{
						info->userPrevState = info->userState;
						info->userState = SABM_RECEIVED_ON_FACCH;
						logPrint(LOG_DEBUG,"User = %p : SABM for Assignment Command Received Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));

						timerStop(&info->tmr);

    					sabmAssignmentCommandHandler(evtDataContent , info, sapiForTxDataQ);
					}
					else if( evtDataContent[1] == 0x53 )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = DISC_RECEIVED;
						logPrint(LOG_INFO,"User = %p : DISC_RECEIVED on FACCH, Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
    					discLapdmMsgHandler(evtDataContent , info, sapiForTxDataQ);
					}
					else if (((info->l3Msg[0] & 0x0F) == 0x06) && (info->l3Msg[1] == 0x29))
					{
						timerStop(&info->tmr);
						logPrint(LOG_DEBUG,"User = %p : Assignment Complete Received, RR cause = %d \n " , info, info->l3Msg[2] );

						// De-activate SDCCH channel for this user, when Assignment complete is received.
						if(info->userLogicalChannel.txSLotNum)
							clearUserContext(info, FALSE, FALSE);

						// Reset to 0, since not deleting user.
						info->userLogicalChannel.txSLotNum = 0;
						info->userLogicalChannel.subChNum  = 0;

						blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
#ifdef FEA_SILENT_CALL
						if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL))
						{
							if(blackUserInfo->muteDlPwrDuringSilentCall == TRUE)
							{
								/* Scale down the Downlink Power on all the remaining timeslots
								 * except timeslot on which silent call has started */
								GsmTrxModifyTsDigitalScaling(blackUserInfo->timeSlotForTchSilentCall);
							}

							/* Send Silent Call allocated resources Indication to client */
							sendSilentCallResourcesIndOverSocket(info, FXL_TCH_SILENT_CALL);
							tchSilentCallUnderProgress = FALSE;

							info->userState = TCH_SILENT_CALL_IN_PROGRESS;
							info->retransmissionCountForL3Msg = 0;
                            pushLayer3ReqToTxDataQ(info , lcsPosReq, sapiForTxDataQ);
							logPrint(LOG_DEBUG, "User = %p : Sending lcsPosReq, User State = %s \n" , info, logGetUserStateString(info->userState));
						}
#endif /* FEA_SILENT_CALL */
#ifdef FEA_VOICE_CALL_TO_TARGET
						else if((targetVoiceCallCntxt.moImsiStr != NULL) && (memcmp(info->userImsi_str , targetVoiceCallCntxt.moImsiStr, MAX_IDENTITY_LENGTH_STR) == 0))
						{
							// MO Assignment Complete

							targetVoiceCallCntxt.moTsNum   = info->userTchChannel.txSLotNum;
							targetVoiceCallCntxt.moSubChan = info->userTchChannel.subChNum;
							logPrint(LOG_DEBUG,"MO Assignment Complete !!, MO Call Context Updated(TS = %d, SC = %d)", targetVoiceCallCntxt.moTsNum, targetVoiceCallCntxt.moSubChan);

							blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)targetVoiceCallCntxt.mtImsiStr, FALSE, FALSE);
							if(blackUserInfo == NULL)
								return;

							blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_TARGET_VOICE_CALL;
							blackUserInfo->triggerPagingReq = TRUE;

							pushPagingReqToPageQ(blackUserInfo);
						}
						else if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL))
						{
							// MT Assignment Complete

							targetVoiceCallCntxt.mtTsNum   = info->userTchChannel.txSLotNum;
							targetVoiceCallCntxt.mtSubChan = info->userTchChannel.subChNum;
							logPrint(LOG_DEBUG,"MT Assignment Complete !!, MT Call Context Updated(TS = %d, SC = %d)", targetVoiceCallCntxt.mtTsNum, targetVoiceCallCntxt.mtSubChan);

							logPrint(LOG_DEBUG,"User = %p : ASSGN_CMP Received Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							timerStop(&info->tmr);
							info->userPrevState= info->userState;
							info->userState = WAITING_FOR_ALERT;
						}
#endif /* FEA_VOICE_CALL_TO_TARGET */
					}

					else if (((info->l3Msg[0] & 0x0F) == 0x06) && (info->l3Msg[1] == 0x38))
					{
						timerStop(&info->tmr);

						logPrint(LOG_DEBUG, "User = %p : RRLP - %s", info, gsmL3PduHexdump(info->l3Msg, info->l3MsgLen));
						logPrint(LOG_DEBUG, "User = %p : RRLP - APDU ID, Protocol Identifer = %d", info, (info->l3Msg[2] & 0x0F));

						if((info->l3Msg[2] & 0x0F) == 0x00) /* RRLP/LCS Message, Continue decoding */
						{
							switch((info->l3Msg[4] & 0x0E) >> 1)
							{
								case 0x01: /* MS Positioning Response */
									{
										logPrint(LOG_DEBUG,"User = %p : RRLP - LCS_POS_RECEIVED Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));

										if(FXL_UE_POS_ERR_ASSISTANCE_DATA_MISSING == dataLcsPosRespHandler(info))
										{
											/* Send First Segment of RRLP GPS Assistance Data */
											info->rrlpGpsAssistCount   = 0;
											info->rrlpGpsAssistSegment = 0;
											info->userState = RRLP_GPS_ASSIST_DATA_SENT;
											info->retransmissionCountForL3Msg = 0;
											pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapiForTxDataQ);
											logPrint(LOG_DEBUG, "User = %p : RRLP - Sending rrlpGpsAssistData[%d][%d], User State = %s \n" , info, info->rrlpGpsAssistSegment,(info->rrlpGpsAssistCount-1), logGetUserStateString(info->userState));

											return;
										}
									}
									break;

								case 0x03: /* Assistance Data Ack */
									{
										logPrint(LOG_DEBUG, "User = %p : RRLP - Assistance Data Ack Received on FACCH for Segment = %d", info, info->rrlpGpsAssistSegment);

										if(info->rrlpGpsAssistSegment < RRLP_TOTAL_SEGMENTS - 1)
										{
											/* Send Next Segment of RRLP GPS Assistance Data */
											info->rrlpGpsAssistSegment++;
											info->rrlpGpsAssistCount = 0;
											info->userState = RRLP_GPS_ASSIST_DATA_SENT;
											info->retransmissionCountForL3Msg = 0;
											pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapiForTxDataQ);
											logPrint(LOG_DEBUG, "User = %p : RRLP - Sending rrlpGpsAssistData[%d][%d], User State = %s \n" , info, info->rrlpGpsAssistSegment,(info->rrlpGpsAssistCount-1), logGetUserStateString(info->userState));
											return;
										}
										else
										{
											/* All RRLP segments sent, reset counters */
											info->rrlpGpsAssistSegment = 0;
											info->rrlpGpsAssistCount = 0;
										}
									}
									break;

								case 0x04: /* Protocol Error */
									{
										logPrint(LOG_DEBUG, "User = %p : RRLP - Protocol Error Received", info);
									}
									break;

								case 0x05: /* Unknown/Reserved */
									{
										logPrint(LOG_DEBUG, "User = %p : RRLP - Unknown Message Received", info);
									}
									break;

								default:
									break;
							}
						}

						info->userState = TCH_SILENT_CALL_IN_PROGRESS;
						info->retransmissionCountForL3Msg = 0;
                        pushLayer3ReqToTxDataQ(info , lcsPosReq, sapiForTxDataQ);
						logPrint(LOG_DEBUG, "User = %p : Sending lcsPosReq, User State = %s \n" , info, logGetUserStateString(info->userState));
					}
#ifdef FEA_VOICE_CALL_TO_TARGET
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x01 ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = ALERT_RCVD;
						logPrint(LOG_DEBUG,"User = %p :RING RING !!!! On MT Previous State = %s", info, logGetUserStateString(info->userPrevState));
						mtAlertHandler(info, sapiForTxDataQ);
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x07 ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = PH_CONNECT_RCVD;
						logPrint(LOG_DEBUG,"User = %p :CONNECT Rcvd from MT Previous State = %s", info, logGetUserStateString(info->userPrevState));
						mtConnectHandler( info, sapiForTxDataQ );
					}

					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x18 ) )
					{
						timerStop(&info->tmr);
						info->userState = HOLD_RCVD;
						logPrint(LOG_DEBUG,"User = %p :HOLD Rcvd, Sending HOLD_REJ \n ", info);
                        pushLayer3ReqToTxDataQ(info , holdRej, sapiForTxDataQ);
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x2D ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = REL_PROC;
						logPrint(LOG_DEBUG,"User = %p :REL rcvd from  MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
						logPrint(LOG_DEBUG,"User = %p :Sending REL_COMP \n ", info);
                        pushLayer3ReqToTxDataQ(info , releaseCmp, sapiForTxDataQ);
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x25 ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = WAITING_FOR_REL_CMP;
						if(targetVoiceCallCntxt.isOnGoingCall)
						{
							if(targetVoiceCallCntxt.moTsNum == tsNum)
							{
								logPrint(LOG_DEBUG,"User = %p :DISC rcvd from  MO Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
								logPrint(LOG_DEBUG,"User = %p :Sending REL \n ", info);
								pushLayer3ReqToTxDataQ(info , release, sapiForTxDataQ);

								/*Send DISC to MT*/
								userInfo* mtInfo = NULL;
								logicalChannelIdentity ch_id;
								ch_id.txSLotNum = targetVoiceCallCntxt.mtTsNum;
								ch_id.subChNum  = targetVoiceCallCntxt.mtSubChan;
								if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum >= 0)) //&& (ch_id.subChNum < MAX_SUBCHAN_TIMESLOT))
								{
									mtInfo = userFindUsingLogicalChannel(&ch_id);
								}

								if(mtInfo != NULL)
								{
									timerStop(&mtInfo->tmr);
									mtInfo->userPrevState= mtInfo->userState;
									if((mtInfo->userPrevState >= SABM_RECEIVED_ON_FACCH))
									{
										mtInfo->userState = DISC_SENT;
										logPrint(LOG_DEBUG , "User = %p : Sending DISC on FACCH to MT User PrevState = %s \n" , info,logGetUserStateString(mtInfo->userPrevState));
                                        pushLayer3ReqToTxDataQ(mtInfo , disconnect, sapiForTxDataQ);
									}
									else if((mtInfo->userPrevState >= CALL_CONF_RCVD) || (mtInfo->userState >= CALL_CONF_RCVD))
									{
										mtInfo->userState = DISC_SENT;
										logPrint(LOG_DEBUG , "User = %p : Sending DISC on SDCCH to MT User PrevState = %s \n" , info,logGetUserStateString(mtInfo->userPrevState));
                                        pushLayer3ReqToTxDataQ(mtInfo , disconnect, sapiForTxDataQ);
									}
									else
									{
										//Both IFs: MT_ASS_CMD sent, but MO DISC comes before ASS_CMP, TCH &/Or SDCCh channel allocated and activated must deactivated and deallocated
										logPrint(LOG_DEBUG,"MT->LogicaltxSLotNum : %d, MT->TchtxSLotNum : %d",
												mtInfo->userLogicalChannel.txSLotNum,mtInfo->userTchChannel.txSLotNum);

										blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(mtInfo->userImsi) , TRUE, FALSE);
										if(blackUserInfo != NULL)
											blackUserInfo->isInConnectedState = FALSE;

										if(mtInfo->userLogicalChannel.txSLotNum ||
												isTimeSlotTypeSupportsCombinedSDCCH(mtInfo->userLogicalChannel.txSLotNum))
										{
											gResetCallAnyway = TRUE;
											if(!(mtInfo->userTchChannel.txSLotNum))  //Delete User as well
												clearUserContext(mtInfo, FALSE, TRUE);
											else
												clearUserContext(mtInfo, FALSE, FALSE);

										}

										if(mtInfo->userTchChannel.txSLotNum)
										{
											gResetCallAnyway = TRUE;
											clearUserContext(mtInfo, TRUE, TRUE);
										}
									}
								}
								else
								{
									logPrint(LOG_DEBUG , "User = %p : no MT user found for this call \n" , info);
									blackListedUserInfo* blackUserInfo = NULL;
									blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(targetVoiceCallCntxt.mtImsiStr), FALSE, FALSE);
									if((blackUserInfo != NULL) && (blackUserInfo->triggerPagingReq == TRUE))
										blackUserInfo->triggerPagingReq = FALSE;
								}
							}
							else if(targetVoiceCallCntxt.mtTsNum == tsNum)
							{
								logPrint(LOG_DEBUG,"User = %p :DISC rcvd from  MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
								logPrint(LOG_DEBUG,"User = %p :Sending REL \n ", info);
								pushLayer3ReqToTxDataQ(info , release, sapiForTxDataQ);

								/*Send DISC to MO*/
								userInfo* moInfo = NULL;
								logicalChannelIdentity ch_id;
								ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
								ch_id.subChNum = targetVoiceCallCntxt.moSubChan;
								if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum >= 0))
								{
									moInfo = userFindUsingLogicalChannel(&ch_id);
									if(moInfo != NULL)
									{
										moInfo->userPrevState= info->userState;
										moInfo->userState = DISC_SENT;
										logPrint(LOG_DEBUG , "User = %p : Sending DISC to MO User = %p \n" , info,moInfo);
                                        pushLayer3ReqToTxDataQ(moInfo , disconnect, sapiForTxDataQ);
									}
									else
									{
										logPrint(LOG_DEBUG , "User = %p : no MO user found for this call \n" , info);
									}
								}
							}
						}
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x2A ) )
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;      /*Important: state set to Free Channels at popMsg*/
						info->userState = WAITING_FOR_REL_CMP;      //Wouldn't matter
						if(targetVoiceCallCntxt.isOnGoingCall)
						{
							if(targetVoiceCallCntxt.moTsNum == tsNum)
							{
								logPrint(LOG_DEBUG,"User = %p :RLC rcvd from MO Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							}
							else if(targetVoiceCallCntxt.mtTsNum == tsNum)
							{
								logPrint(LOG_DEBUG,"User = %p :RLC rcvd from MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							}
						}
						//logPrint(LOG_DEBUG,"User = %p :Free the channels once L2_ACK is sent\n ", info);
						logPrint(LOG_DEBUG,"User = %p :Free the channels send Chan_REL\n ", info);
                        pushLayer3ReqToTxDataQ(info , channelRelease, sapiForTxDataQ);
					}
					else if( ((info->l3Msg[0] & 0x0F) == 0x03) && ((info->l3Msg[1] & 0x3F) == 0x0F ) )
					{
						timerStop(&info->tmr);

						if(info->userState == CALL_EST)
							info->userState = WAITING_FOR_CALL_EST; //In case Mobile Coudln't rcv L2_Ack for ConnAck (sends ConnAck repeatedly)

						info->userPrevState = info->userState;    /*Important: state set to Free Channels at popMsg*/
						if(targetVoiceCallCntxt.isOnGoingCall)
						{
							if(targetVoiceCallCntxt.moTsNum == tsNum)
							{
								logPrint(LOG_DEBUG,"User = %p :Conn_Ack rcvd from MO Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
							}
						}
					}

					else if( ((info->l3Msg[0] & 0x0F) == 0x05) && ((info->l3Msg[1] & 0x3F) == 0x01))
					{
						timerStop(&info->tmr);
						info->userPrevState = info->userState;
						info->userState = WAITING_FOR_REL_CMP;
						if(targetVoiceCallCntxt.isOnGoingCall)
						{
							if(targetVoiceCallCntxt.moTsNum == tsNum)
							{
								logPrint(LOG_DEBUG,"User = %p :IMSI Detach rcvd from MO Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
								logPrint(LOG_DEBUG,"User = %p :Sending REL \n ", info);
                                pushLayer3ReqToTxDataQ(info , release, sapiForTxDataQ);

								/*Send DISC to MT*/
								userInfo* mtInfo = NULL;
								logicalChannelIdentity ch_id;
								ch_id.txSLotNum = targetVoiceCallCntxt.mtTsNum;
								ch_id.subChNum  = targetVoiceCallCntxt.mtSubChan;
								if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum >= 0)) //&& (ch_id.subChNum < MAX_SUBCHAN_TIMESLOT))
								{
									mtInfo = userFindUsingLogicalChannel(&ch_id);
								}

								if(mtInfo != NULL)
								{
									timerStop(&mtInfo->tmr);
									mtInfo->userPrevState= mtInfo->userState;
									if((mtInfo->userPrevState >= SABM_RECEIVED_ON_FACCH))
									{
										mtInfo->userState = DISC_SENT;
										logPrint(LOG_DEBUG , "User = %p : Sending DISC on FACCH to MT User PrevState = %s \n" , info,logGetUserStateString(mtInfo->userPrevState));
                                        pushLayer3ReqToTxDataQ(mtInfo , disconnect, sapiForTxDataQ);
									}
									else if((mtInfo->userPrevState >= CALL_CONF_RCVD) || (mtInfo->userState >= CALL_CONF_RCVD))
									{
										mtInfo->userState = DISC_SENT;
										logPrint(LOG_DEBUG , "User = %p : Sending DISC on SDCCH to MT User PrevState = %s \n" , info,logGetUserStateString(mtInfo->userPrevState));
                                        pushLayer3ReqToTxDataQ(mtInfo , disconnect, sapiForTxDataQ);
									}
									else
									{
										//Both IFs: MT_ASS_CMD sent, but MO DISC comes before ASS_CMP, TCH &/Or SDCCh channel allocated and activated must deactivated and deallocated
										logPrint(LOG_DEBUG,"MT->LogicaltxSLotNum : %d, MT->TchtxSLotNum : %d",
												mtInfo->userLogicalChannel.txSLotNum,mtInfo->userTchChannel.txSLotNum);

										blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(mtInfo->userImsi) , TRUE, FALSE);
										if(blackUserInfo != NULL)
											blackUserInfo->isInConnectedState = FALSE;

										if(mtInfo->userLogicalChannel.txSLotNum)
										{
											gResetCallAnyway = TRUE;
											if(!(mtInfo->userTchChannel.txSLotNum))  //Delete User as well
												clearUserContext(mtInfo, FALSE, TRUE);
											else
												clearUserContext(mtInfo, FALSE, FALSE);

										}

										if(mtInfo->userTchChannel.txSLotNum)
										{
											gResetCallAnyway = TRUE;
											clearUserContext(mtInfo, TRUE, TRUE);
										}
									}
								}
								else
								{
									logPrint(LOG_DEBUG , "User = %p : no MT user found for this call \n" , info);
									blackListedUserInfo* blackUserInfo = NULL;
									blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(targetVoiceCallCntxt.mtImsiStr), FALSE, FALSE);
									if((blackUserInfo != NULL) && (blackUserInfo->triggerPagingReq == TRUE))
										blackUserInfo->triggerPagingReq = FALSE;
								}
							}
							else if(targetVoiceCallCntxt.mtTsNum == tsNum)
							{
								logPrint(LOG_DEBUG,"User = %p :IMSI Detach rcvd from  MT Previous State = %s\n ", info, logGetUserStateString(info->userPrevState));
								logPrint(LOG_DEBUG,"User = %p :Sending REL \n ", info);
                                pushLayer3ReqToTxDataQ(info , release, sapiForTxDataQ);

								/*Send DISC to MO*/
								userInfo* moInfo = NULL;
								logicalChannelIdentity ch_id;
								ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
								ch_id.subChNum = targetVoiceCallCntxt.moSubChan;
								if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum >= 0))
								{
									moInfo = userFindUsingLogicalChannel(&ch_id);
									if(moInfo != NULL)
									{
										moInfo->userPrevState= info->userState;
										moInfo->userState = DISC_SENT;
										logPrint(LOG_DEBUG , "User = %p : Sending DISC to MO User = %p \n" , info,moInfo);
                                        pushLayer3ReqToTxDataQ(moInfo , disconnect, sapiForTxDataQ);
									}
									else
									{
										logPrint(LOG_DEBUG , "User = %p : no MO user found for this call \n" , info);
									}
								}
							}
						}

						blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(&info->l3Msg[3], TRUE, FALSE);

						if(blackUserInfo != NULL)
						{
							// Send BL-Detach Ind to Client
#ifdef FXL_BL_UE_POWER_OFF
							send2gBlUePowerOffInd(blackUserInfo, FXL_POWER_OFF);
#else
							sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif
							delete2gBlackListUserFromLinkedList(blackUserInfo);
						}
					}
#endif /* FEA_VOICE_CALL_TO_TARGET */
					else
					{
						logPrint(LOG_DEBUG,"User = %p : Unhandled Message( %s )", info, gsmL3PduHexdump(info->l3Msg, info->l3MsgLen));
					}
				}	/*ignoreThisFrame*/
				else
				{
					if( !((data_ind->Data.ulDataLength == 0)         ||
								(evtDataContent[1] == 0x03) ||
								(evtDataContent[1] == 0x73) ||
								(((evtDataContent[1]) & 0x03) == 0x01)))
					{
						logPrint(LOG_DEBUG,"User = %p : Ignored Message( %s )", info, gsmL3PduHexdump(evtDataContent, 23));
					}
				}
			}
#ifdef FEA_VOICE_CALL_TO_TARGET
			else if( sapi == SAPI_TCHF || sapi == SAPI_TCHH )
			{
				if((data_ind->Data.ulDataLength != 0) && (info->userState == CALL_EST))
				{
					//logPrint(LOG_DEBUG,"Rcvd TCH Frame after CALL EST");
					if((targetVoiceCallCntxt.moTsNum   != 0xFF) &&
							(targetVoiceCallCntxt.mtTsNum   == info->userTchChannel.txSLotNum) &&
							(targetVoiceCallCntxt.mtSubChan == info->userTchChannel.subChNum))
					{
						/*Send frame to MO*/
						userInfo* moInfo = NULL;
						logicalChannelIdentity ch_id;
						ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
						ch_id.subChNum  = targetVoiceCallCntxt.moSubChan;
						moInfo = userFindUsingLogicalChannel(&ch_id);
						if((moInfo != NULL) && (moInfo->userState == CALL_EST))
						{
							//logPrint(LOG_INFO,"------>> MO");
                            transactMemoryParams params;
                            params.pushToTail = TRUE;
                            params.sapi       = sapi;

				  			pushMsgToTransactionMemoryManager((void*)evtDataContent, &moInfo->userTchChannel, params); // Put this message at end of Queue ie tail
						}
						else
							logPrint(LOG_ERR , "Couldn't find MO user on this timeslot = %d and subchannel = %d or wait for CALL_EST \n" ,ch_id.txSLotNum , ch_id.subChNum);
					}
					else if((targetVoiceCallCntxt.mtTsNum   != 0xFF) &&
							(targetVoiceCallCntxt.moTsNum   == info->userTchChannel.txSLotNum) &&
							(targetVoiceCallCntxt.moSubChan == info->userTchChannel.subChNum))
					{
						/*Send frame to MT*/
						userInfo* mtInfo = NULL;
						logicalChannelIdentity ch_id;
						ch_id.txSLotNum = targetVoiceCallCntxt.mtTsNum;
						ch_id.subChNum  = targetVoiceCallCntxt.mtSubChan;
						mtInfo = userFindUsingLogicalChannel(&ch_id);
						if((mtInfo != NULL) && (mtInfo->userState == CALL_EST))
						{
                            transactMemoryParams params;
                            params.pushToTail = TRUE;
                            params.sapi       = sapi;

						    //logPrint(LOG_INFO,"------>> MT");
				  			pushMsgToTransactionMemoryManager((void*)evtDataContent, &mtInfo->userTchChannel, params); // Put this message at end of Queue ie tail
						}
						else
							logPrint(LOG_ERR , "Couldn't find MT user for this timeslot = %d and subchannel = %d or wait for CALL_EST \n" ,ch_id.txSLotNum , ch_id.subChNum);
					}
					else
					{}
				}
			}
#endif // FEA_VOICE_CALL_TO_TARGET
#endif // FEA_SILENT_CALL || FEA_VOICE_CALL_TO_TARGET
		}
		data_ind = NULL;
		data_ind = deQueue(&dataIndQ);
	} while(data_ind != NULL);

	return ;
}


void updateMsClassmark(userInfo* info)
{
	// Mobile Station Classmark 2: 3GPP TS 24.008, 10.5.1.6

	memcpy(info->msClassmark.encodedCM2, &info->l3Msg[2], SIZE_OF_CLASSMARK_2);

	info->msClassmark.revisionLevel         = (info->l3Msg[3] & 0x60) >> 5;
	info->msClassmark.earlyClassmarkSending = (info->l3Msg[3] & 0x10) >> 4;
	info->msClassmark.A5_1AlgorithmSupport  = (info->l3Msg[3] & 0x08) >> 3;
	info->msClassmark.rfPowerCapability     = (info->l3Msg[3] & 0x07);

	info->msClassmark.pseudoSyncCapability  = (info->l3Msg[4] & 0x40) >> 6;
	info->msClassmark.ssScreeningIndicator  = (info->l3Msg[4] & 0x03) >> 4;
	info->msClassmark.smCapability          = (info->l3Msg[4] & 0x08) >> 3;
	info->msClassmark.vbsCapability         = (info->l3Msg[4] & 0x04) >> 2;
	info->msClassmark.vgcsCapability        = (info->l3Msg[4] & 0x02) >> 1;
	info->msClassmark.freqCapability        = (info->l3Msg[4] & 0x01);

	info->msClassmark.lcsValCapability      = (info->l3Msg[5] & 0x20) >> 5;
	info->msClassmark.ucs2Treatment         = (info->l3Msg[5] & 0x10) >> 4;
	info->msClassmark.soLsaSupport          = (info->l3Msg[5] & 0x08) >> 3;
	info->msClassmark.cmServicePrompt       = (info->l3Msg[5] & 0x04) >> 2;
	info->msClassmark.A5_3AlgorithmSupport  = (info->l3Msg[5] & 0x02) >> 1;
	info->msClassmark.A5_2AlgorithmSupport  = (info->l3Msg[5] & 0x01);
}

#ifdef FEA_2G_INTER_RAT_MEAS
int generateMeasInfoBuffers(blackListedUserInfo* info)
{
	tOCT_UINT8 *mi = NULL;
	tOCT_UINT8 i = 0, instance = 0, noOfMIInstancesWith3gInfo = 0, noOfMIInstancesWith4gInfo = 0;
	int retVal = 1;
	tOCT_UINT8 umtsInstance = 0, lteInstance = 0;

	/* MI: Instance 0: Measurement Parameters Information */
	info->noOfValidMIInstances = 1;

	if(info->measInfo.umtsNeighbors.noOfFddUarfcns > FXL_2G_MAX_3G_NEIGHBOR_UARFCNS)
	{
		logPrint(LOG_DEBUG, "generateMeasInfoBuffers: Number Of Fdd Uarfcns > FXL_2G_MAX_3G_NEIGHBOR_UARFCNS");
		retVal = -1;
		return retVal;
	}

	if(info->measInfo.lteNeighbors.noEutranFreqs > FXL_2G_MAX_4G_NEIGHBOR_EARFCNS)
	{
		logPrint(LOG_DEBUG, "generateMeasInfoBuffers: Number Of Earfcns > FXL_2G_MAX_4G_NEIGHBOR_EARFCNS");
		retVal = -1;
		return retVal;
	}

	/* Each MI Instance can contain 2 3G Neighbor Freq Information or 3 4G Neighbor Freq Information */
	for(i = 0; i < info->measInfo.umtsNeighbors.noOfFddUarfcns; i = i+2)
	{
		info->noOfValidMIInstances++;
		noOfMIInstancesWith3gInfo++;
	}

	for(i = 0; i < info->measInfo.lteNeighbors.noEutranFreqs; i = i+3)
	{
		info->noOfValidMIInstances++;
		noOfMIInstancesWith4gInfo++;
	}

	/* Initialize */
	for(i = 0; i < MAX_MI_INSTANCES; i++)
	{
		mi = (tOCT_UINT8 *) &info->mi_buf[i][0];
		memset(mi, GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN - 2);
	}

	umtsInstance = 0;
	lteInstance  = 0;

	for(instance = 0; instance < info->noOfValidMIInstances; instance++)
	{
		mi = (tOCT_UINT8 *) &info->mi_buf[instance][0];
		int  Len, i;
		char Buffer [128];

		memset(Buffer, GSM_MACBLOCK_PADDING, 128);

		c_MEASUREMENT_INFORMATION MI;
		INIT_c_MEASUREMENT_INFORMATION(&MI);

		MI.contents.MI_INDEX  = instance;
		MI.contents.MI_COUNT  = info->noOfValidMIInstances - 1;

		MI.contents.REPORT_TYPE = 1; /* MS to use MEASUREMENT REPORT */

		if(MI.contents.MI_INDEX == 0)
		{
			/* 3G Measurement Parameters*/
			SETPRESENT_c_Measurement_information__3G_MEASUREMENT_Parameters_Description(&(MI.contents), ED_TRUE);

			MI.contents._3G_MEASUREMENT_Parameters_Description->Qsearch_C = info->measInfo.umtsMeasParams.qSearchC;
			MI.contents._3G_MEASUREMENT_Parameters_Description->FDD_REP_QUANT = info->measInfo.umtsMeasParams.fddRepQuant;
			MI.contents._3G_MEASUREMENT_Parameters_Description->FDD_MULTIRAT_REPORTING_Present = TRUE;
			MI.contents._3G_MEASUREMENT_Parameters_Description->FDD_MULTIRAT_REPORTING = info->measInfo.umtsMeasParams.fddMultiratReporting;

			c_Measurement_information_E_UTRAN_Parameters_Description * eutranParams = NULL;
			c_Measurement_information_E_UTRAN_Parameters_Description_E_UTRAN_Measurement_Parameters_Description* eutranMeasParamsDescr = NULL;

			SETPRESENT_c_Measurement_information_E_UTRAN_Parameters_Description(&(MI.contents), ED_TRUE);
			eutranParams = MI.contents.E_UTRAN_Parameters_Description;

			/* E-UTRAN Parameters Description */
			SETPRESENT_c_Measurement_information_E_UTRAN_Parameters_Description_E_UTRAN_Measurement_Parameters_Description(eutranParams, ED_TRUE);
			eutranMeasParamsDescr = eutranParams->E_UTRAN_Measurement_Parameters_Description;

			eutranMeasParamsDescr->Qsearch_C_E_UTRAN_Initial                     = info->measInfo.lteMeasParams.qSearchC_Eutran;
			eutranMeasParamsDescr->E_UTRAN_REP_QUANT                             = info->measInfo.lteMeasParams.eutranRepQuant;
			eutranMeasParamsDescr->E_UTRAN_MULTIRAT_REPORTING                    = info->measInfo.lteMeasParams.eutranMultiratReporting;
			eutranMeasParamsDescr->E_UTRAN_FDD_MEASUREMENT_REPORT_OFFSET_Present = TRUE;
			eutranMeasParamsDescr->E_UTRAN_FDD_MEASUREMENT_REPORT_OFFSET         = 40;
			eutranMeasParamsDescr->E_UTRAN_TDD_MEASUREMENT_REPORT_OFFSET_Present = TRUE;
			eutranMeasParamsDescr->E_UTRAN_TDD_MEASUREMENT_REPORT_OFFSET         = 40;

			eutranMeasParamsDescr->REPORTING_GRANULARITY_Present                 = TRUE;
			eutranMeasParamsDescr->REPORTING_GRANULARITY                         = 0;

			/* Encode MI */
			Len = ENCODE_c_MEASUREMENT_INFORMATION(Buffer, 0, &MI);

			memcpy(mi, Buffer, 21);

			if(Len > 168)
				logPrint(LOG_ERR, "generateMeasInfoBuffers(): Encoded MI Instance(%d) exceeded 21 bytes", instance);

			/* Free the allocated memory */
			FREE_c_MEASUREMENT_INFORMATION(&MI);

		}
		else if(MI.contents.MI_INDEX > noOfMIInstancesWith3gInfo)
		{
			/* 4G Neighbor Info */
			c_Measurement_information_E_UTRAN_Parameters_Description * eutranParams = NULL;
			c_Measurement_information_E_UTRAN_Parameters_Description_Repeated_E_UTRAN_Neighbour_Cells_data** eutranNeighInfo = NULL;

			SETPRESENT_c_Measurement_information_E_UTRAN_Parameters_Description(&(MI.contents), ED_TRUE);
			eutranParams = MI.contents.E_UTRAN_Parameters_Description;

			/* one MI instance can contain 3 4G neighbor EARFCN info */
			SETITEMS_c_Measurement_information_E_UTRAN_Parameters_Description_Repeated_E_UTRAN_Neighbour_Cells(&(eutranParams->Repeated_E_UTRAN_Neighbour_Cells), 3);
			eutranNeighInfo = eutranParams->Repeated_E_UTRAN_Neighbour_Cells.data;

			tOCT_UINT8 lteNeighIndex = 0;

			if(lteInstance == 0) lteNeighIndex = 0;
			else if(lteInstance == 1) lteNeighIndex = 3;

			for(i = 0; i < 3; i++)
			{
				SETITEMS_c_Measurement_information_E_UTRAN_Parameters_Description_Repeated_E_UTRAN_Neighbour_Cells_data_EARFCN(&(eutranNeighInfo[i]->EARFCN), 1);

				eutranNeighInfo[i]->EARFCN.data[0]                  = info->measInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].earfcn;
				eutranNeighInfo[i]->Measurement_Bandwidth_Present   = TRUE;
				eutranNeighInfo[i]->Measurement_Bandwidth           = info->measInfo.lteNeighbors.eutranFreq[lteNeighIndex + i].eutranMeasBwNrb;
			}

			/* Encode MI */
			Len = ENCODE_c_MEASUREMENT_INFORMATION(Buffer, 0, &MI);

			memcpy(mi, Buffer, 21);

			if(Len > 168)
				logPrint(LOG_ERR, "generateMeasInfoBuffers(): Encoded MI Instance(%d) exceeded 21 bytes", instance);

			/* Free the allocated memory */
			FREE_c_MEASUREMENT_INFORMATION(&MI);

			lteInstance++;
		}
		else
		{
			/* 3G Neighbor Info */
			c_Measurement_information__3G_Neighbour_Cell_Description* p3gNeighCellDescr = NULL;
			c_Measurement_information__3G_Neighbour_Cell_Description_UTRAN_FDD_Description* utranFddDescr = NULL;
			c_Measurement_information__3G_Neighbour_Cell_Description_UTRAN_FDD_Description_Repeated_UTRAN_FDD_Neighbour_Cells_data **utranFddNeighbors = NULL;

			SETPRESENT_c_Measurement_information__3G_Neighbour_Cell_Description(&(MI.contents), ED_TRUE);
			p3gNeighCellDescr = MI.contents._3G_Neighbour_Cell_Description;

			if(umtsInstance == 0)
			{
				p3gNeighCellDescr->Index_Start_3G_Present = TRUE;
				p3gNeighCellDescr->Index_Start_3G = 0;
			}

			SETPRESENT_c_Measurement_information__3G_Neighbour_Cell_Description_UTRAN_FDD_Description(MI.contents._3G_Neighbour_Cell_Description, ED_TRUE);
			utranFddDescr = p3gNeighCellDescr->UTRAN_FDD_Description;

			/* one MI instance can contain 2 3G neighbor UARFCN info */
			SETITEMS_c_Measurement_information__3G_Neighbour_Cell_Description_UTRAN_FDD_Description_Repeated_UTRAN_FDD_Neighbour_Cells(&(utranFddDescr->Repeated_UTRAN_FDD_Neighbour_Cells), 2);
			utranFddNeighbors = utranFddDescr->Repeated_UTRAN_FDD_Neighbour_Cells.data;

			/* 3G FDD Neighbor - 1 */
			utranFddNeighbors[0]->FDD_ARFCN       = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].uarfcn;
			utranFddNeighbors[0]->FDD_Indic0      = 0;
			if((info->measInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].noOfCells > 0) && \
					(info->measInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].noOfCells <= FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN))
				utranFddNeighbors[0]->NR_OF_FDD_CELLS = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].noOfCells;

			if(utranFddNeighbors[0]->NR_OF_FDD_CELLS > 0)
			{
				SETITEMS_c_FDD_CELL_INFORMATION(&(utranFddNeighbors[0]->FDD_CELL_INFORMATION_Field), utranFddNeighbors[0]->NR_OF_FDD_CELLS);

				for (i = 0; i < utranFddNeighbors[0]->NR_OF_FDD_CELLS; i++)
				{
					utranFddNeighbors[0]->FDD_CELL_INFORMATION_Field.data[i]->ScramblingCode = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].neighFddCell[i].psc;
					utranFddNeighbors[0]->FDD_CELL_INFORMATION_Field.data[i]->Diversity = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance - 1)*2].neighFddCell[i].diversityApplied;
				}
			}

			/* 3G FDD Neighbor - 2 */
			utranFddNeighbors[1]->FDD_ARFCN       = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].uarfcn;
			utranFddNeighbors[1]->FDD_Indic0      = 0;
			if((info->measInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].noOfCells > 0) && \
					(info->measInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].noOfCells <= FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN))
				utranFddNeighbors[1]->NR_OF_FDD_CELLS = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].noOfCells;

			if(utranFddNeighbors[1]->NR_OF_FDD_CELLS > 0)
			{
				SETITEMS_c_FDD_CELL_INFORMATION(&(utranFddNeighbors[1]->FDD_CELL_INFORMATION_Field), utranFddNeighbors[1]->NR_OF_FDD_CELLS);

				for (i = 0; i < utranFddNeighbors[1]->NR_OF_FDD_CELLS; i++)
				{
					utranFddNeighbors[1]->FDD_CELL_INFORMATION_Field.data[i]->ScramblingCode = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].neighFddCell[i].psc;
					utranFddNeighbors[1]->FDD_CELL_INFORMATION_Field.data[i]->Diversity = info->measInfo.umtsNeighbors.neighFddUarfcn[(instance*2)-1].neighFddCell[i].diversityApplied;
				}
			}

			/* Encode MI */
			Len = ENCODE_c_MEASUREMENT_INFORMATION(Buffer, 0, &MI);

			memcpy(mi, Buffer, 21);

			if(Len > 168)
				logPrint(LOG_ERR, "generateMeasInfoBuffers(): Encoded MI Instance(%d) exceeded 21 bytes", instance);

			/* Free the allocated memory */
			FREE_c_MEASUREMENT_INFORMATION(&MI);

			umtsInstance++;
		}

		retVal = 1;
	}
	return retVal;
}
#endif /* FEA_2G_INTER_RAT_MEAS */

void sabmLauReqHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi)
{
	void* msg = NULL;

	/* Check & Remove any unsent messages in the Queue , Assuming only one Identity Req in the queue */
	if((msg = popMsgFromTransactionMemoryManager((&info->userLogicalChannel), sapi)) != NULL)
	{
		// Q Node is deleted inside pop function
		//free(msg); // static buffer
		//msg = NULL;
		logPrint(LOG_DEBUG , "User = %p : Removing Old Request from Queue\n" , info);
	}

	/* First create UA message from SABM message */
#ifdef FEA_SILENT_CALL
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info, sapi);
#else
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info);
#endif

	// Check if LAU request is sent with IMSI
	if((info->userState == LAU_REQ_RECEIVED) && ((inMsgBuf[13] & 0x07) == 0x01))
	{
		// TMSI is not available and hence UE sent LAU Req with IMSI
		info->userOldTmsi[0] = 0xFF;
		info->userOldTmsi[1] = 0xFF;
		info->userOldTmsi[2] = 0xFF;
		info->userOldTmsi[3] = 0xFF;

		// Store IMSI value;
		memcpy(info->userImsi , &inMsgBuf[12] , SIZE_OF_IDENTITY);

		info->userPrevState = LAU_REQ_RECEIVED;
		info->userState = IMSI_RECEIVED;
		logPrint(LOG_DEBUG, "User = %p : IMSI Received in LAU Request\n" ,info);
		dataImsiIdentityRespHandler(info);
	}
	/* LAU request is sent with TMSI/P-TMSI */
	else if((info->userState == LAU_REQ_RECEIVED) && ((inMsgBuf[13] & 0x07) == 0x04))
	{
		// Store TMSI value
		memcpy(info->userOldTmsi, &inMsgBuf[14], (SIZE_OF_TMSI -2)); /* exclude length and type of identity */
	}
	else
	{}

	/* Start timer to wait for Gprs Suspension request */
	tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_GPRS_SUSP , 0 , &userInfoTimerCbFunction, info);
	assert(retVal == RC_TCB_OK);
}

void sabmCmServiceReqHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi)
{
	void* msg = NULL;
	tOCT_UINT8 * identity = NULL;

	/* Check & Remove any unsent messages in the Queue */
	if((msg = popMsgFromTransactionMemoryManager((&info->userLogicalChannel), sapi)) != NULL)
	{
		// Q Node is deleted inside pop function
		//free(msg); // static buffer
		//msg = NULL;
		logPrint(LOG_DEBUG , "User = %p : Removing Old Request from Queue\n" , info);
	}

	/* First create UA message from SABM message */
#ifdef FEA_SILENT_CALL
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info, sapi);
#else
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info);
#endif

	info->cmServiceReqTypeRcvd = inMsgBuf[5] & 0x0F; // Store the CM-Serv-Req Type

#ifdef FEA_EMER
	fxLGsmEmergencyCallAttmpInd *ind = (fxLGsmEmergencyCallAttmpInd *) socketMsgBuf;
	memset(ind,0,sizeof(fxLGsmEmergencyCallAttmpInd));

	if((info->cmServiceReqTypeRcvd == 0x02)||(info->emergency_service_req == TRUE))	//CM-Serv-Req type == EMER
	{
		tOCT_UINT8 identityLen = inMsgBuf[10]-1 ,i=0 ,j=0, check_digit, len;

		if((inMsgBuf[11] & 0x07) == 2)
		{
			logPrint(LOG_DEBUG,"Type of Identity is IMEI in CM_SERV_REQ\n");
			if((inMsgBuf[11] & 0x08) == 8)	//oddEvenInd
			{
				info->userImei_str[j++] = ((inMsgBuf[11] & 0xF0) >> 4) + '0';
			}

			for(i=12; i < (12+identityLen); i++)
			{
				info->userImei_str[j++] = (inMsgBuf[i] & 0x0F) + '0';
				info->userImei_str[j++] = ((inMsgBuf[i] & 0xF0) >> 4) + '0';
			}
			info->userImei_str[j] = '\0';
			memcpy(ind->imeiStr , info->userImei_str , SIZE_OF_IDENTITY_STR);
			blackListedUserInfo* BlackUserInfo = blacklistUserFindUsingIdentity(info->userImei_str, FALSE, TRUE);
			if(BlackUserInfo != NULL)
			{
				memcpy(ind->imsiStr,BlackUserInfo->userImsi_str,MAX_IDENTITY_LENGTH_STR);
			}
			// Calculate the last digit of the IMEI, i.e., check digit
			check_digit = getImeiCheckDigit(info->userImei_str);


			// Replace the last digit with calculated check digit
			len = strlen(info->userImei_str);
#ifndef NDEBUG
			assert(len < MAX_IDENTITY_LENGTH_STR);
#else
			if(len >= MAX_IDENTITY_LENGTH_STR)
			{
				logPrint(LOG_ERR, "User = %p : sabmCmServiceReqHandler: len >= MAX_IDENTITY_LENGTH_STR\n", info);
				exit(1);
			}
#endif
			info->userImei_str[len - 1] = check_digit;

		}
		else if((inMsgBuf[11] & 0x07) == 0x04)
		{
			logPrint(LOG_DEBUG,"Type of Identity is TMSI in CM_SERV_REQ\n");
			identity = &inMsgBuf[10];
			blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(identity , TRUE, FALSE);
			if(blackUserInfo != NULL)
			{
				memcpy(ind->imsiStr,blackUserInfo->userImsi_str,MAX_IDENTITY_LENGTH_STR);
				memcpy(ind->imeiStr,blackUserInfo->userImei_str,MAX_IDENTITY_LENGTH_STR);
			}

		}
                ind->hdr.msgLength = sizeof (fxLGsmEmergencyCallAttmpInd);
		ind->hdr.msgType = FXL_2G_EMERGENCY_CALL_ATTEMPTED_IND;
		ind->hdr.rat = FXL_RAT_2G;

		// Send these values over socket interface to outside world
		writeToExternalSocketInterface((tOCT_UINT8*)ind, sizeof(fxLGsmEmergencyCallAttmpInd));

		logPrint(LOG_DEBUG,"EMERGENCY Call  Imei =%s,Imsi =%s",ind->imeiStr,ind->imsiStr);
		info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;
		if((info->cmServiceReqTypeRcvd == 0x02) && (trx_g->bts.Emergencyredirectenable == TRUE))
		{
			redirectInfo2g redirectInfo;
			redirectInfo.bandIndicator = trx_g->bts.Redirectemergencyinfo.bandIndicator;
			redirectInfo.arfcn = trx_g->bts.Redirectemergencyinfo.arfcn;
			redirectInfo.bsic = trx_g->bts.Redirectemergencyinfo.bsic;
			/* Send Channel Release filling redirect info. */
			sendChannelReleaseWithRedirection(info, &redirectInfo, sapi);
			info->emergency_service_req = FALSE;
		}
		//pushLayer3ReqToTxDataQ(info , cmServiceReject, sapi);
		//logPrint(LOG_DEBUG, "User = %p : Sending cmServiceReject, User State = %s \n" , info, logGetUserStateString(info->userState));
		return;
	}
#endif /*FEA_EMER*/

	//Check if it is blacklisted UE which is already registered with us
	//based on the IMSI/TMSI value received
	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(&inMsgBuf[10] , TRUE, FALSE);

	if(blackUserInfo != NULL) //Already registered with our BS.
	{
		logPrint(LOG_DEBUG, "User = %p : CM Service Request is for Blacklist User = %p, IMSI = %s", info, blackUserInfo, blackUserInfo->userImsi_str);

		blackUserInfo->isInConnectedState = TRUE;

		info->userBlacklisted = TRUE;
		info->last_lac = blackUserInfo->last_lac;
		memcpy(info->userImsi_str , blackUserInfo->userImsi_str , MAX_IDENTITY_LENGTH_STR);
		memcpy(info->userImei_str , blackUserInfo->userImei_str , MAX_IDENTITY_LENGTH_STR);
		memcpy(info->userImsi     , blackUserInfo->userImsi     , SIZE_OF_IDENTITY);
		memcpy(info->userTmsi     , blackUserInfo->userTmsi     , SIZE_OF_TMSI);
		memcpy(info->userOldTmsi  , blackUserInfo->userOldTmsi  , (SIZE_OF_TMSI - 2));

		if(info->cmServiceReqTypeRcvd == 0x01)
			info->blockedMoCallsCounter = ++blackUserInfo->blockedMoCallsCounter;

		if(blackUserInfo->gprsSuspExpectedFromThisUe == TRUE)
		{
			tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_GPRS_SUSP , 0 , &userInfoTimerCbFunction, info);
			assert(retVal == RC_TCB_OK);
		}
		else
		{
			// TODO: - 100 ms delay added so that we dont need to wait for 2 secs for GPRS_SUSP which was not needed for paging/cm-service case.
			tOCT_UINT8 retVal = timerStart(&info->tmr , 100 , 0 , &userInfoTimerCbFunction, info);
			assert(retVal == RC_TCB_OK);
		}
        /* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
        if(configUeIdList.defaultConfig == BLACKLIST)
        {
			tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
			if(retVal == RC_TCB_OK)
			  logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on CM_SERVICE_REQ_RECEIVED ");
        }
	}
	else
	{
		logPrint(LOG_DEBUG, "User = %p : CM Service Request is not for Blacklist User, TMSI(%02x %02x %02x %02x %02x %02x)", info, info->userTmsi[0], info->userTmsi[1],\
				info->userTmsi[2], info->userTmsi[3],\
				info->userTmsi[4], info->userTmsi[5]);
		info->userBlacklisted = FALSE;
	}
}

#ifdef FEA_DECODE_MO_SMS

void cmServiceReqHandler(userInfo* info)
{

	info->cmServiceReqTypeRcvd = info->l3Msg[2] & 0x0F; // Store the CM-Serv-Req Type

	//Check if it is blacklisted UE which is already registered with us
	//based on the IMSI/TMSI value received
	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(&info->l3Msg[7] , TRUE, FALSE);

	if(blackUserInfo != NULL) //Already registered with our BS.
	{
		logPrint(LOG_DEBUG, "User = %p : CM Service Request is for Blacklist User = %p, IMSI = %s", info, blackUserInfo, blackUserInfo->userImsi_str);

		if(blackUserInfo->gprsSuspExpectedFromThisUe == TRUE)
		{
			tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_GPRS_SUSP , 0 , &userInfoTimerCbFunction, info);
			assert(retVal == RC_TCB_OK);
		}
		else
		{
			// TODO: - 100 ms delay added so that we dont need to wait for 2 secs for GPRS_SUSP which was not needed for paging/cm-service case.
			tOCT_UINT8 retVal = timerStart(&info->tmr , 100 , 0 , &userInfoTimerCbFunction, info);
			assert(retVal == RC_TCB_OK);
		}

        /* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
        if(configUeIdList.defaultConfig == BLACKLIST)
        {
			tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
			if(retVal == RC_TCB_OK)
			  logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on CM_SERVICE_REQ_RECEIVED SMS ");
		}
	}
	else
	{
		info->userBlacklisted = FALSE;
	}

}
#endif /* FEA_DECODE_MO_SMS */

void sabmPagingRespHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi)
{

	void* msg = NULL;

	//Check & Remove any unsent messages in the Queue
	if((msg = popMsgFromTransactionMemoryManager((&info->userLogicalChannel), sapi)) != NULL)
	{
		// Q Node is deleted inside pop function
		//free(msg); //static buffer
		//msg = NULL;
		logPrint(LOG_DEBUG , "User = %p : Removing Old Request from Queue\n" , info);
	}

	//First create UA message from SABM message
#ifdef FEA_SILENT_CALL
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info, sapi);
#else
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info);
#endif

	/* Check if it is blacklisted UE which is already registered with us
	 * based on the IMSI/TMSI value received
	 */
	tOCT_UINT8 * identity = &inMsgBuf[10];
	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(identity , TRUE, FALSE);

	if(blackUserInfo != NULL) //Already registered with our BS.
	{
		logPrint(LOG_DEBUG, "User = %p : Paging Response due to Trigger(0x%x) is for Blacklist User = %p, IMSI = %s", info, blackUserInfo->bitMaskForTriggers, blackUserInfo, blackUserInfo->userImsi_str);

		info->userBlacklisted = TRUE;

		blackUserInfo->isInConnectedState = TRUE;
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
		blackUserInfo->pagingInactivityCounter = 0;
#endif
		info->last_lac = blackUserInfo->last_lac;
		// Need some optimization here avoid memcpy
		memcpy(info->userImsi_str , blackUserInfo->userImsi_str , MAX_IDENTITY_LENGTH_STR);
		memcpy(info->userImei_str , blackUserInfo->userImei_str , MAX_IDENTITY_LENGTH_STR);
		memcpy(info->userImsi     , blackUserInfo->userImsi     , SIZE_OF_IDENTITY);
		memcpy(info->userTmsi     , blackUserInfo->userTmsi     , SIZE_OF_TMSI);
		memcpy(info->userOldTmsi  , blackUserInfo->userOldTmsi  , (SIZE_OF_TMSI - 2));
		info->blockedMoCallsCounter = blackUserInfo->blockedMoCallsCounter;

		if(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_REDIRECTION) == SET_TRIGGER_FOR_REDIRECTION) ||
				((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RELEASE) == SET_TRIGGER_FOR_RELEASE))
		{
			blackUserInfo->triggerPagingReq = FALSE;
		}

#ifdef FEA_SILENT_CALL
		else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)
		{
			blackUserInfo->triggerPagingReq = FALSE;
		}
		else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
		{
			// Allocate TCH channel for this user, SDCCH channel will be deallocated when TCH assignment is completed.
			if(blackUserInfo->timeSlotForTchSilentCall > 0 && blackUserInfo->timeSlotForTchSilentCall <= 7)
			{
				if(logicalChannels[blackUserInfo->timeSlotForTchSilentCall][0] == EMPTY)
				{
					info->userTchChannel.txSLotNum = blackUserInfo->timeSlotForTchSilentCall;
					info->userTchChannel.subChNum  = 0;

					logicalChannels[info->userTchChannel.txSLotNum][info->userTchChannel.subChNum] = FULL;
					noOfAllocatedFullTrafficChannels++;
					logPrint(LOG_INFO, "TCH/F Allocated, TS = %d , SC = %d\n",info->userTchChannel.txSLotNum, info->userTchChannel.subChNum );

					blackUserInfo->triggerPagingReq = FALSE;

					// Update the user pointer in TCH channel as well
					updateUserDb(info, &(info->userTchChannel));

					activateLogicalChannel(info->userTchChannel.txSLotNum , info->userTchChannel.subChNum);
					info->userState = TCH_ALLOCATED;
					logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the TCH/F, FACCH/F and SACCH/F, TimeSlot = %d , SubChannel = %d\n" , info, info->userTchChannel.txSLotNum , info->userTchChannel.subChNum );
				}
				else
				{
					tchSilentCallUnderProgress = FALSE;
                    cellBarDuringTchSilentCall = FALSE;
					logPrint(LOG_ERR , "TS(%d) is already used, cannot allocate it for TCH/F Silent Call\n", blackUserInfo->timeSlotForTchSilentCall);
				}
			}
			else if(allocateFullTrafficChannel(&(info->userTchChannel)) == TRUE)
			{
				blackUserInfo->triggerPagingReq = FALSE;

				// Update the user pointer in TCH channel as well
				updateUserDb(info, &(info->userTchChannel));

				activateLogicalChannel(info->userTchChannel.txSLotNum , info->userTchChannel.subChNum);
				info->userState = TCH_ALLOCATED;
				logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the TCH/F, FACCH/F and SACCH/F, TimeSlot = %d , SubChannel = %d\n" , info, info->userTchChannel.txSLotNum , info->userTchChannel.subChNum );
			}
			else if(allocateHalfTrafficChannel(&(info->userTchChannel)) == TRUE)
			{
				blackUserInfo->triggerPagingReq = FALSE;
				// Update the user pointer in TCH channel as well
				updateUserDb(info, &(info->userTchChannel));
				activateLogicalChannel(info->userTchChannel.txSLotNum , info->userTchChannel.subChNum);
				info->userState = TCH_ALLOCATED;
				logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the TCH/H, FACCH/H and SACCH/H, TimeSlot = %d , SubChannel = %d\n" , info, info->userTchChannel.txSLotNum , info->userTchChannel.subChNum );
			}
			else
			{
				tchSilentCallUnderProgress = FALSE;
                cellBarDuringTchSilentCall = FALSE;
				logPrint(LOG_ERR , "Could not allocate TCH for Silent Call\n");
			}
		}
#endif /* FEA_SILENT_CALL */

#ifdef FEA_MT_SMS
		else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_INDIVIDUAL_SMS) == SET_TRIGGER_FOR_INDIVIDUAL_SMS)
		{
			blackUserInfo->triggerPagingReq = FALSE;
			info->mtSmsL3Pdu = blackUserInfo->mtSmsL3Pdu;
		}
		else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BROADCAST_SMS) == SET_TRIGGER_FOR_BROADCAST_SMS)
		{
			blackUserInfo->triggerPagingReq = FALSE;
			info->mtSmsL3Pdu = mtBroadcastSmsL3Pdu;
		}
#endif /* FEA_MT_SMS */

#if	defined(FEA_ALERT) || defined(FEA_VOICE_CALL_TO_TARGET)
		else if(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING) ||\
				((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL))
		{
			blackUserInfo->triggerPagingReq = FALSE;
			info->userPrevState= PAGING_RESP_RECEIVED;
			info->userState = WAITING_TO_SEND_SETUP;
		}
#endif /* FEA_ALERT || FEA_VOICE_CALL_TO_TARGET */
		else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) == SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT)
		{
			blackUserInfo->triggerPagingReq = FALSE;
		}

		else
		{}

		if(blackUserInfo->gprsSuspExpectedFromThisUe == TRUE)
		{
			tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_GPRS_SUSP , 0 , &userInfoTimerCbFunction, info);
			assert(retVal == RC_TCB_OK);
		}
		else
		{
			// TODO:- 100 ms delay added so that we dont need to wait for 2 secs for GPRS_SUSP which was not needed for paging/cm-service case.
			tOCT_UINT8 retVal = timerStart(&info->tmr , 100 , 0 , &userInfoTimerCbFunction, info);
			assert(retVal == RC_TCB_OK);
		}
	}
	else
	{
		/* Paging response for the user which is not in BL store */
		info->userBlacklisted = FALSE;
		info->initialRachIsPaging = TRUE;
		logPrint(LOG_DEBUG , "User = %p : Paging Response is not for Blacklist User: contents( %s )", info, gsmL3PduHexdump(inMsgBuf, 23));

		if((identity[1] & 0x07) == 0x01) /* IMSI */
		{
			memcpy(info->userImsi, identity, SIZE_OF_IDENTITY);
		}
		else if((identity[1] & 0x07) == 0x04) /* TMSI */
		{
			memcpy(info->userTmsi, identity, SIZE_OF_TMSI);
		}
		else
		{
			/* Identity type is not IMSI/TMSI, of which we have no interest */
			logPrint(LOG_DEBUG , "User = %p : Paging response: Identity type is not IMSI/TMSI", info);
		}

		tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_GPRS_SUSP , 0 , &userInfoTimerCbFunction, info);
		assert(retVal == RC_TCB_OK);
	}
}

#ifdef FEA_SILENT_CALL
void sabmAssignmentCommandHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi)
{
	void* msg = NULL;

	//Check & Remove any unsent messages in the Queue , Assuming only one Identity Req in the queue
	if((msg = popMsgFromTransactionMemoryManager((&info->userTchChannel), sapi)) != NULL)
	{
		// Q Node is deleted inside pop function
		//free(msg);
		//msg = NULL;
		logPrint(LOG_DEBUG , "User = %p : Removing Old Request from Queue \n" , info);
	}

	//First create UA message from SABM message
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info, sapi);

	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

	if(blackUserInfo != NULL) //Already registered with our BS.
	{
		logPrint(LOG_DEBUG, "User = %p : SABM for Assignment cmd received for Blacklist User = %p, IMSI = %s", info, blackUserInfo, blackUserInfo->userImsi_str);
		blackUserInfo->isInConnectedState = TRUE;
	}

	tOCT_UINT8 retVal = timerStart(&info->tmr , 100 , 0 , &userInfoTimerCbFunction, info);
	assert(retVal == RC_TCB_OK);
}
#endif /* FEA_SILENT_CALL */

void dataImsiIdentityRespHandler(userInfo* info)
{
	// Decode IMSI as string
	bcd2str( info->userImsi, info->userImsi_str, FALSE);

	info->userBlacklisted = 0xFF;

	if (searchIdDbForRecvdIdentity(info,  TRUE) == FALSE)
	{
		logPrint(LOG_DEBUG, "User = %p : Received IMSI is not in Configured LIST, BL/WL will be based on IMEI configuration\n", info);
	}

	// Keep the count here for total number of IMSI capture can be for white or blacklist
	noOfAttemptedRegistrationInGsm++;
}

void dataImeiIdentityRespHandler(userInfo* info, tOCT_UINT8 sapi)
{
	tOCT_UINT8 check_digit , len, imeiSvBcd;
	ConfigList* ConfigListPtr = getConfigUeIdListPtr();

	//Store Imei value, Decode IMEI as string
	bcd2str( &info->l3Msg[2], info->userImei_str, FALSE);

	// Calculate the last digit of the IMEI, i.e., check digit
	check_digit = getImeiCheckDigit(info->userImei_str);

	// Replace the last digit with calculated check digit
	len = strlen(info->userImei_str);
#ifndef NDEBUG
	assert(len < MAX_IDENTITY_LENGTH_STR);
#else
	if(len >= MAX_IDENTITY_LENGTH_STR)
	{
		logPrint(LOG_ERR, "User = %p : dataImeiIdentityRespHandler: len >= MAX_IDENTITY_LENGTH_STR\n", info);
		exit(1);
	}
#endif
	info->userImei_str[len - 1] = check_digit;

	imeiSvBcd = ((info->l3Msg[2 + info->l3Msg[2] - 1] & 0xF0) | (info->l3Msg[2 + info->l3Msg[2]] & 0x0F));
	info->userImeiSv = (tOCT_UINT8)( 10*(imeiSvBcd >> 4) + (imeiSvBcd & 0x0F));

	if(info->userBlacklisted == TRUE) // Based on Imsi in BLACKLIST
	{
		logPrint(LOG_DEBUG, "User = %p : Received IMEI corresponds to IMSI in BLACKLIST\n", info);
		logPrint(LOG_DEBUG, "User = %p : BLACKLISTING IMEI [%s]\n", info, info->userImei_str);
	}

	else if(info->userBlacklisted == FALSE) // Based on Imsi in WHITELIST
	{
		logPrint(LOG_DEBUG, "User = %p : Received IMEI corresponds to IMSI in WHITELIST\n" , info);

		logPrint(LOG_DEBUG, "User = %p : WHITELISTING IMEI [%s] with REJ-CAUSE [%d]\n", info, info->userImei_str, info->wlRejectCause);
	}

	else if(info->userBlacklisted == 0xFF)
	{
		if(searchIdDbForRecvdIdentity(info, FALSE) == FALSE)
		{
			logPrint(LOG_DEBUG, "User = %p : Neither IMSI nor IMEI is in configured LIST, default action : %s\n", info, (ConfigListPtr->defaultConfig == 0)?"WHITELIST":"BLACKLIST");

			if(ConfigListPtr->defaultConfig == WHITELIST)
			{
				info->userBlacklisted = FALSE;
#ifdef FEA_REJECT_CAUSE_CONTROL
				info->wlRejectCause = gsmDefaultWLRejectCause;
#endif

				logPrint(LOG_DEBUG, "User = %p : WHITELISTING IMSI[%s], IMEI[%s] with REJ-CAUSE [%d]\n", info, info->userImsi_str, info->userImei_str, info->wlRejectCause);
			}
			else if(ConfigListPtr->defaultConfig == BLACKLIST)
			{
				info->userBlacklisted = TRUE;

				logPrint(LOG_DEBUG, "User = %p : BLACKLISTING IMSI[%s], IMEI[%s]\n", info, info->userImsi_str, info->userImei_str);
			}
		}
	}

	else
	{}

	if(info->cmServiceReqTypeRcvd != 0)  /* Case where initial RACH is not LAU but CM-Serv-Req (MO_CALL/SMS/...) */
	{
		/* Send CM Service Reject */
		info->retransmissionCountForL3Msg = 0;
		info->userState = L3_REJECT_FOR_UE;
		pushLayer3ReqToTxDataQ(info , cmServiceReject, sapi);
		logPrint(LOG_DEBUG, "User = %p : Sending cmServiceReject, User State = %s \n" , info, logGetUserStateString(info->userState));
	}
	else if(info->initialRachIsPaging == TRUE)  /* Case where initial RACH is not LAU but Paging-Req */
	{
		/* Send Channel Release */
		info->retransmissionCountForL3Msg = 0;
		pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
		logPrint(LOG_DEBUG, "User = %p, Sending channelRelease, User State = %s" , info, logGetUserStateString(info->userState));
	}
	else
	{
		if((info->initialMeasReport.timingAdvance < trx_g->bts.ta_filter_start) ||
				(info->initialMeasReport.timingAdvance > trx_g->bts.ta_filter_stop ))
		{
			info->userBlacklisted = FALSE;

			info->retransmissionCountForL3Msg = 0;
			info->userState = L3_REJECT_FOR_UE;
			info->wlRejectCause = gsmDefaultWLRejectCause;
			pushLayer3ReqToTxDataQ(info , locUpdateReject, sapi);
			logPrint(LOG_DEBUG, "User = %p : User TA(%d) Out of range(%d - %d), Reject the user", info->initialMeasReport.timingAdvance, trx_g->bts.ta_filter_start, trx_g->bts.ta_filter_stop);
			logPrint(LOG_DEBUG, "User = %p : Sending locUpdateReject, User State = %s \n" , info, logGetUserStateString(info->userState));
		}
		else if(info->userBlacklisted == TRUE)
		{
			info->retransmissionCountForL3Msg = 0;
			if (trx_g->bts.redirType  == FXL_GSM_PERM_REDIR)
			{
				info->retransmissionCountForL3Msg = 0;
				info->userState = L3_REJECT_FOR_UE;
				info->wlRejectCause = FXL_REJ_CAUSE_NO_SUITABLE_CELLS_IN_LA;
					pushLayer3ReqToTxDataQ(info , locUpdateReject, sapi);
				logPrint(LOG_DEBUG, "User = %p : Sending locUpdateReject For BL user, User State = %s \n" , info, logGetUserStateString(info->userState));
			}
			else
			{
				/* Blacklist case, Send LAU Accept */
#ifdef MM_INFO
				if(trx_g->bts.nwNameLen != 0)
				{
					if(trx_g->bts.nwNameLen > MAX_SIZE_OF_NW_NAME)
					{
						trx_g->bts.nwNameLen = MAX_SIZE_OF_NW_NAME;
					}
					mmInfoReq[4] = trx_g->bts.nwNameLen + 1; // 0x86
					mmInfoReq[5] = 0x86;
					memcpy(&mmInfoReq[6] , trx_g->bts.nwName , trx_g->bts.nwNameLen);
					mmInfoReq[0] = trx_g->bts.nwNameLen + 5;
					mmInfoReq[0] = (mmInfoReq[0] << 2) | 0x01;
					pushLayer3ReqToTxDataQ(info , mmInfoReq, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending mmInfoReq, User State = %s \n" , info, logGetUserStateString(info->userState));
				}
				else
				{
					pushLayer3ReqToTxDataQ(info , locUpdateAccept, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending locUpdateAccept, User State = %s \n" , info, logGetUserStateString(info->userState));
				}
#else
					pushLayer3ReqToTxDataQ(info , locUpdateAccept, sapi);
				logPrint(LOG_DEBUG, "User = %p : Sending locUpdateAccept, User State = %s \n" , info, logGetUserStateString(info->userState));
#endif
			}
		}
		else
		{
			/* Whitelist case, Send LAU Reject */
			info->retransmissionCountForL3Msg = 0;
			info->userState = L3_REJECT_FOR_UE;
			pushLayer3ReqToTxDataQ(info , locUpdateReject, sapi);
			logPrint(LOG_DEBUG, "User = %p : Sending locUpdateReject For WL user, User State = %s \n" , info, logGetUserStateString(info->userState));
		}
	}
}

void sendChannelReleaseWithRedirection(userInfo* info, redirectInfo2g* redirectInfo, tOCT_UINT8 sapi)
{
	tOCT_UINT8 channelReleaseWithRedirection[GSM_MACBLOCK_LEN - 2];
	tOCT_UINT8 gsmRatIndicator = 0x10;

	logPrint(LOG_DEBUG, "User = %p : Redirection info: bandIndicator(%d), ARFCN(%d), BSIC(%d)\n" , info, redirectInfo->bandIndicator, redirectInfo->arfcn, redirectInfo->bsic );

	memcpy(channelReleaseWithRedirection, channelRelease, GSM_MACBLOCK_LEN - 2);

	/* Filling Redirection info here */
	channelReleaseWithRedirection[0] = 0x21; /* L2-Length */
	channelReleaseWithRedirection[4] = 0x77; /* IEI(77) - Cell selection indicator after release */
	channelReleaseWithRedirection[5] = 0x03; /* Length of the information octets */

	channelReleaseWithRedirection[6] = (gsmRatIndicator | ((redirectInfo->bandIndicator & 0x01) << 3) | ((redirectInfo->arfcn & 0x0380) >> 7) );
	channelReleaseWithRedirection[7] = (((redirectInfo->arfcn & 0x007F) << 1) | ((redirectInfo->bsic & 0x20) >> 5));
	channelReleaseWithRedirection[8] = ((redirectInfo->bsic & 0x1F) << 3);

	info->retransmissionCountForL3Msg = 0;
    pushLayer3ReqToTxDataQ(info , channelReleaseWithRedirection, sapi);
	info->userRedirected = TRUE;
	logPrint(LOG_DEBUG, "User = %p : Sending channelRelease with redirection info, User State = %s \n" , info, logGetUserStateString(info->userState));
}

void dataTmsiReallocCompleteHandler( userInfo* info, tOCT_UINT8 sapi)
{
	//Send Channel Release
	info->retransmissionCountForL3Msg = 0;

	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
	if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RELEASE) == SET_TRIGGER_FOR_RELEASE))
	{
		changeBLtoWLInConfigDb(blackUserInfo);
		blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_RELEASE;
		delete2gBlackListUserFromLinkedList(blackUserInfo);
	}
#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
	else if(trx_g->bts.sendSmsDuringRegistration == TRUE)
	{
		/* Send Cipher Mode Command */
		pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
		logPrint(LOG_DEBUG, "User = %p : Sending cipheringModeCommand, User State = %s \n",
				info, logGetUserStateString(info->userState));
		return;
	}
#endif /* FEA_2G_SEND_SMS_DURING_REGISTRATION */

	pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
	logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" ,
			info, logGetUserStateString(info->userState));
}

#ifdef FEA_EMER
void handleEmergencySetup(userInfo* info, tOCT_UINT8 sapi)
{
	if(trx_g->bts.Emergencyredirectenable == TRUE)
	{
		fxLGsmEmergencyCallAttmpInd *ind = (fxLGsmEmergencyCallAttmpInd *) socketMsgBuf;
		redirectInfo2g redirectInfo;
		redirectInfo.bandIndicator = trx_g->bts.Redirectemergencyinfo.bandIndicator;
		redirectInfo.arfcn = trx_g->bts.Redirectemergencyinfo.arfcn;
		redirectInfo.bsic = trx_g->bts.Redirectemergencyinfo.bsic;
		info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;
		/* Send Channel Release filling redirect info. */
		sendChannelReleaseWithRedirection(info, &redirectInfo, sapi);
		memset(ind,0,sizeof(fxLGsmEmergencyCallAttmpInd));
		memcpy(ind->imsiStr,info->userImsi_str,MAX_IDENTITY_LENGTH_STR);
		memcpy(ind->imeiStr,info->userImei_str,MAX_IDENTITY_LENGTH_STR);
                                ind->hdr.msgLength = sizeof (fxLGsmEmergencyCallAttmpInd);
		ind->hdr.msgType = FXL_2G_EMERGENCY_CALL_ATTEMPTED_IND;
		ind->hdr.rat = FXL_RAT_2G;
		writeToExternalSocketInterface((tOCT_UINT8*)ind, sizeof(fxLGsmEmergencyCallAttmpInd));
		logPrint(LOG_DEBUG,"ind->imsiStr=%s",ind->imsiStr);
	}
}
#endif
// TBD: we need to check concatenation of the SETUP message in case it exceeds 23 bytes.
void dataSetupHandler(userInfo* info, tOCT_UINT8 sapi)
{
	tOCT_UINT8 calledPartyNumberIndex = 2; // TBD: need to check for optional elements.
	char  calledPartyNumber[MAX_IDENTITY_LENGTH_STR];
#ifdef FEA_EMER
	char *emergency_number = "911";
#endif
	// Decode Called number

	if((info->l3Msg[calledPartyNumberIndex] >> 4) == 0x0D) // 3GPP TS 24.008 - 9.3.23: IEI_BC_REPEAT_INDICATOR = 0xD-
	{
		calledPartyNumberIndex++; // IEI
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x04) // 3GPP TS 24.008 - 9.3.23: IEI_BEARER_CAPABILITY(1) = 0x04
	{
		calledPartyNumberIndex++; // IEI
		calledPartyNumberIndex = calledPartyNumberIndex + info->l3Msg[calledPartyNumberIndex] + 1; // Length
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x04) // 3GPP TS 24.008 - 9.3.23: IEI_BEARER_CAPABILITY(2) = 0x04
	{
		calledPartyNumberIndex++; // IEI
		calledPartyNumberIndex = calledPartyNumberIndex + info->l3Msg[calledPartyNumberIndex] + 1; // Length
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x1C) // 3GPP TS 24.008 - 9.3.23: IEI_FACILITY = 0x1C
	{
		calledPartyNumberIndex++; // IEI
		calledPartyNumberIndex = calledPartyNumberIndex + info->l3Msg[calledPartyNumberIndex] + 1; // Length
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x1E) // 3GPP TS 24.008 - 10.5.4.21: PROGRESS_INDICATOR = 0x1C
	{
		calledPartyNumberIndex++; // IEI
		calledPartyNumberIndex = calledPartyNumberIndex + info->l3Msg[calledPartyNumberIndex] + 1; // Length
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x34) // 3GPP TS 24.008 - 10.5.4.23: SIGNAL = 0x34
	{
		calledPartyNumberIndex = calledPartyNumberIndex + 2; // IEI
		//calledPartyNumberIndex = calledPartyNumberIndex + inMsgBuf[calledPartyNumberIndex] + 1; // Length
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x5C) // 3GPP TS 24.008 - 10.5.4.9: IEI_CALLING_PARTY_BCD_NUMBER = 0x5C
	{
		calledPartyNumberIndex++; // IEI
		calledPartyNumberIndex = calledPartyNumberIndex + info->l3Msg[calledPartyNumberIndex] + 1; // Length
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x5D) // 3GPP TS 24.008 - 9.3.23: IEI_CALLING_PARTY_SUBADDRESS = 0x5D
	{
		calledPartyNumberIndex++; // IEI
		calledPartyNumberIndex = calledPartyNumberIndex + info->l3Msg[calledPartyNumberIndex] + 1; // Length
	}
	if(info->l3Msg[calledPartyNumberIndex] == 0x5E) // 3GPP TS 24.008 - 9.3.23: IEI_CALLED_PARTY_BCD_NUMBER = 0x5E
	{
		calledPartyNumberIndex++; // IEI
		bcd2str( &info->l3Msg[calledPartyNumberIndex], calledPartyNumber, TRUE);
		logPrint(LOG_INFO, "User = %p : Called Party Number is %s", info, calledPartyNumber);
#ifdef FEA_EMER
		if((strcmp(calledPartyNumber,emergency_number)==0))
		{
			logPrint(LOG_INFO, "User = %p : calledPartyNumber is equal to emergency_number so sending channel release");
			handleEmergencySetup(info, sapi);
			return;
		}
#endif

#ifdef FEA_VOICE_CALL_TO_TARGET

		if(!targetVoiceCallCntxt.isOnGoingCall && (targetVoiceCallCntxt.moImsiStr != NULL) && (targetVoiceCallCntxt.moMsIsdnStr != NULL) &&\
				(memcmp(info->userImsi_str , targetVoiceCallCntxt.moImsiStr, MAX_IDENTITY_LENGTH_STR) == 0))
		{

			logPrint(LOG_DEBUG, "User = %p : MO trigger for Target Voice Call, Called Party Number = %s !!", info, calledPartyNumber);
			if(memcmp(calledPartyNumber , targetVoiceCallCntxt.moImsiStr, MAX_IDENTITY_LENGTH_STR) == 0)
			{
				logPrint(LOG_DEBUG,"User = %p : Calling self !!!!", info);

				tOCT_UINT8 tmpBuf[GSM_MACBLOCK_LEN] = {0};
				// Update TI
				memcpy(tmpBuf, releaseComplete, GSM_MACBLOCK_LEN);
				tmpBuf[1] = (info->l3Msg[0] | 0x80);
				tmpBuf[5] = 0xE1;
				tmpBuf[6] = 0x95;		/* Call rejected */

				//Send Release Complete
				info->retransmissionCountForL3Msg = 0;
			pushLayer3ReqToTxDataQ(info , tmpBuf, sapi);
				logPrint(LOG_DEBUG, "User = %p : Sending releaseComplete, User State = %s \n" , info, logGetUserStateString(info->userState));
			}
			else
			{
				blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8 *)calledPartyNumber, FALSE, FALSE);
				if(blackUserInfo != NULL)
				{
					// Reset
					targetVoiceCallCntxt.moTsNum = 0XFF;
					targetVoiceCallCntxt.moSubChan = 0;
					targetVoiceCallCntxt.mtTsNum = 0XFF;
					targetVoiceCallCntxt.mtSubChan = 0;

					targetVoiceCallCntxt.isOnGoingCall = TRUE;
					memcpy(targetVoiceCallCntxt.mtImsiStr, blackUserInfo->userImsi_str, MAX_IDENTITY_LENGTH_STR);
					logPrint(LOG_DEBUG,"Call Context Updated(isOnGoingCall = %d, mtImsiStr = %s)", targetVoiceCallCntxt.isOnGoingCall, targetVoiceCallCntxt.mtImsiStr);

					info->userPrevState = info->userState;
					info->userState = CALL_PROC_SENT;
					info->retransmissionCountForL3Msg = 0;
                pushLayer3ReqToTxDataQ(info , callProc, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending callProc, User State = %s \n" , info, logGetUserStateString(info->userState));
				}
				else
				{
					logPrint(LOG_DEBUG, "User = %p : Called Party IMSI(%s) NOT found in BlackList", info, calledPartyNumber);
					tOCT_UINT8 tmpBuf[GSM_MACBLOCK_LEN] = {0};
					// Update TI
					memcpy(tmpBuf, releaseComplete, GSM_MACBLOCK_LEN);
					tmpBuf[1] = (info->l3Msg[0] | 0x80);
					tmpBuf[5] = 0xE1;
					tmpBuf[6] = 0x95;       /* Call rejected */

					//Send Release Complete
					info->retransmissionCountForL3Msg = 0;
                pushLayer3ReqToTxDataQ(info , tmpBuf, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending releaseComplete, User State = %s \n" , info, logGetUserStateString(info->userState));
				}
			}
		}
		else
#endif /* FEA_VOICE_CALL_TO_TARGET */
			sendMoCallAttemptedIndOverSocket(info , calledPartyNumber);
	}

#ifdef FEA_VOICE_CALL_TO_TARGET
	if((targetVoiceCallCntxt.moImsiStr != NULL) && (targetVoiceCallCntxt.moMsIsdnStr != NULL) &&\
			(memcmp(info->userImsi_str , targetVoiceCallCntxt.moImsiStr, MAX_IDENTITY_LENGTH_STR) == 0))
	{
		/* Do Nothing */
	}
	else
#endif /* FEA_VOICE_CALL_TO_TARGET */
	{
		info->userPrevState = info->userState;
		info->userState = CALL_PROC_SENT;
		info->retransmissionCountForL3Msg = 0;
		pushLayer3ReqToTxDataQ(info , callProc, sapi);
		logPrint(LOG_DEBUG, "User = %p : Sending callProc, User State = %s \n" , info, logGetUserStateString(info->userState));
	}
}

fxlUePositioningError dataLcsPosRespHandler(userInfo* info)
{
    fxlUePositioningInfo  gpsInfo;
	fxlUePositioningError gpsPosResult;

	// Call Lcs Parameter Parsing Function
	gpsPosResult = decodeGpsParameters(&info->l3Msg[4], &gpsInfo);

	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
	if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) == SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT))
	{
		blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_RSSI_GPS_IND;
	}

	info->retransmissionCountForL3Msg = 0;
	sendRssiGpsIndOverSocket(info, &gpsInfo, gpsPosResult);

	return gpsPosResult;
}

#ifdef FEA_SILENT_CALL
void discLapdmMsgHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi)
#else
void discLapdmMsgHandler(tOCT_UINT8* inMsgBuf , userInfo* info)
#endif
{
	info->userPrevState = DISC_RECEIVED;
#ifdef FEA_SILENT_CALL
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info, sapi);
#else
	pushUaLapdmMsgToTxDataQ(inMsgBuf , info);
#endif

	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

	/* Send Redirection Complete Indication to client */
	if((info->userRedirected) && (blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_REDIRECTION) == SET_TRIGGER_FOR_REDIRECTION))
	{
		fxL2gRedirectionCompleteInd *redirectionCompleteInd = (fxL2gRedirectionCompleteInd *) socketMsgBuf;
		memset(redirectionCompleteInd, 0, sizeof(fxL2gRedirectionCompleteInd));

		redirectionCompleteInd->hdr.msgLength = sizeof(fxL2gRedirectionCompleteInd);
		redirectionCompleteInd->hdr.msgType = FXL_2G_REDIRECTION_COMPLETE_IND;
		redirectionCompleteInd->hdr.rat = FXL_RAT_2G;

		memcpy(redirectionCompleteInd->imsiStr , blackUserInfo->userImsi_str , SIZE_OF_IDENTITY_STR);
		writeToExternalSocketInterface(socketMsgBuf , sizeof(fxL2gRedirectionCompleteInd));

		blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_REDIRECTION;

		/* Send BL-Detach Ind to Client */
#ifdef FXL_BL_UE_POWER_OFF
		send2gBlUePowerOffInd(blackUserInfo, FXL_REDIRECTED_TO_OTHER_CELL);
#else
		sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif
		delete2gBlackListUserFromLinkedList(blackUserInfo);
	}

	info->userState = NULL_STATE;
}

#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
void pushUaLapdmMsgToTxDataQ(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi)
#else
void pushUaLapdmMsgToTxDataQ(tOCT_UINT8* inMsgBuf , userInfo* info)
#endif
{
	tOCT_UINT8* l2UAMsg = getTxDataBuffer();
#ifndef NDEBUG
	assert(l2UAMsg != NULL);
#else
	if(l2UAMsg == NULL)
	{
		logPrint(LOG_ERR, "pushUaLapdmMsgToTxDataQ: l2UAMsg == NULL\n");
		exit(1);
	}
#endif
	memcpy(l2UAMsg,  inMsgBuf , GSM_MACBLOCK_LEN); // Copy standard message

	l2UAMsg[0] = info->lapdmParam[0]; // L2 header for UA
	l2UAMsg[1] = info->lapdmParam[1]; // L2 header for UA

    transactMemoryParams params;
    params.pushToTail = FALSE;
    params.sapi       = sapi;
#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
	if(sapi == SAPI_TCHF || sapi == SAPI_TCHH)
      pushMsgToTransactionMemoryManager((void*)l2UAMsg , &info->userTchChannel, params); // Put this message to head
	else
#endif
      pushMsgToTransactionMemoryManager((void*)l2UAMsg , &info->userLogicalChannel, params); // Put this message to head

	if(info->userState == DISC_RECEIVED)
	{
		info->userPrevState = info->userState;
		info->userState = NULL_STATE;
#ifdef FEA_VOICE_CALL_TO_TARGET
		checkAndResetCallCtx(info);
#endif
	}

	//logPrint(LOG_DEBUG,"User = %p : Sending UA to Queue,  Previous State = %s\n ",info, logGetUserStateString(info->userPrevState));
	return;

}

#ifdef FEA_VOICE_CALL_TO_TARGET
void checkAndResetCallCtx(userInfo *info)
{
	blackListedUserInfo* blackUserInfo = NULL;
	blackListedUserInfo* MoblackUserInfo = NULL;
	tOCT_UINT8   CallConnected = FALSE;

	logPrint(LOG_DEBUG,"Inside %s",__FUNCTION__);
	logPrint(LOG_DEBUG,"User = %p, isOnGoingCall : %d, userTchChannTs : %d, moTsNum = %d, mtTsNum : %d, gResetCallAnyway : %d",
			info, targetVoiceCallCntxt.isOnGoingCall, info->userTchChannel.txSLotNum, targetVoiceCallCntxt.moTsNum, targetVoiceCallCntxt.mtTsNum,gResetCallAnyway);

	if((targetVoiceCallCntxt.isOnGoingCall) || (info->userTchChannel.txSLotNum))
	{
		if((targetVoiceCallCntxt.moTsNum == info->userTchChannel.txSLotNum) && (targetVoiceCallCntxt.moSubChan == info->userTchChannel.subChNum))
		{
			targetVoiceCallCntxt.moTsNum = 0XFF;
			targetVoiceCallCntxt.moSubChan = 0;
            CallConnected = targetVoiceCallCntxt.isCallConnected;
			if(targetVoiceCallCntxt.mtTsNum == 0XFF)	// if MT is cleared
            {
				targetVoiceCallCntxt.isOnGoingCall = FALSE;
				targetVoiceCallCntxt.isCallConnected = FALSE;
            }

			blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)targetVoiceCallCntxt.mtImsiStr, FALSE, FALSE);
			if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL))
			{
				blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_TARGET_VOICE_CALL;
			}
			logPrint(LOG_INFO,"MO Context Cleared, isOnGoingCall = %d", targetVoiceCallCntxt.isOnGoingCall);
			MoblackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)targetVoiceCallCntxt.moImsiStr, FALSE, FALSE);
            if((MoblackUserInfo != NULL)&&(CallConnected == TRUE))
            {

                /* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
                if(configUeIdList.defaultConfig == BLACKLIST)
                {
				    tOCT_UINT8 retVal = timerStart(&MoblackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, MoblackUserInfo);
			        if(retVal == RC_TCB_OK)
                      logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on MO disconect ");
			    }
                CallConnected = FALSE;
            }
		}
		else if(((targetVoiceCallCntxt.mtTsNum == info->userTchChannel.txSLotNum) && (targetVoiceCallCntxt.mtSubChan == info->userTchChannel.subChNum))
				/*(targetVoiceCallCntxt.mtTsNum == 0xFF) DISC before ASS_CMP*/ )
		{
			logicalChannelIdentity chId;
			targetVoiceCallCntxt.mtTsNum = 0XFF;
			targetVoiceCallCntxt.mtSubChan = 0;

            CallConnected = targetVoiceCallCntxt.isCallConnected;
			if(targetVoiceCallCntxt.moTsNum == 0XFF)	// if MO is cleared
            {
				targetVoiceCallCntxt.isOnGoingCall = FALSE;
                targetVoiceCallCntxt.isCallConnected = FALSE;
            }

			chId.txSLotNum = info->userTchChannel.txSLotNum;
			chId.subChNum= info->userTchChannel.subChNum;

			if(isTimeSlotTypeSupportsTCHF(chId.txSLotNum) == TRUE)
				deallocateFullTrafficChannel(&chId);
			else if(isTimeSlotTypeSupportsTCHH(chId.txSLotNum) == TRUE)
				deallocateHalfTrafficChannel(&chId);

			blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)targetVoiceCallCntxt.mtImsiStr, FALSE, FALSE);
			if(blackUserInfo != NULL)
            {
                if ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL)
			    {
				    blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_TARGET_VOICE_CALL;
			    }
                if(CallConnected == TRUE)
                {

                    /* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
                    if(configUeIdList.defaultConfig == BLACKLIST)
                    {
					    tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
			            if(retVal == RC_TCB_OK)
                          logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on MT disconect ");
				    }
                    CallConnected = FALSE;
                }
            }
			logPrint(LOG_INFO,"MT Context Cleared, isOnGoingCall = %d", targetVoiceCallCntxt.isOnGoingCall);
		}

		if(gResetCallAnyway)
		{
			targetVoiceCallCntxt.moTsNum = 0XFF;
			targetVoiceCallCntxt.moSubChan = 0;
			targetVoiceCallCntxt.mtTsNum = 0XFF;
			targetVoiceCallCntxt.mtSubChan = 0;
			targetVoiceCallCntxt.isOnGoingCall = FALSE;
            targetVoiceCallCntxt.isCallConnected = FALSE;

			logPrint(LOG_INFO,"Call Context Resetted");

			blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)targetVoiceCallCntxt.mtImsiStr, FALSE, FALSE);
			if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL))
			{
				blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_TARGET_VOICE_CALL;

				/* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
		        if(configUeIdList.defaultConfig == BLACKLIST)
		        {
					tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
					if(retVal == RC_TCB_OK)
				      logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on MO-MT disconect ");
				}
			}
		}
	}
}
#endif /* FEA_VOICE_CALL_TO_TARGET */

#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
void preparePushAssgnCmdToTxDataQ(userInfo * info)
{
	tOCT_UINT8 hoppingFlag = 0, spareFlag = 0;

	if((trx_g->ts[info->userTchChannel.txSLotNum].lchan) == TCHF_FACCHF_SACCHTF)
	{
		//Send Assignment Command for TCH/F,
		assgnCmd[3] = (0x01 << 3) | info->userTchChannel.txSLotNum ;
		assgnCmd[4] = (trx_g->bts.tsc << 5) | (hoppingFlag << 4) | (spareFlag << 2) | (trx_g->arfcn >> 8);
		assgnCmd[5] = (trx_g->arfcn & 0xFF);

		if ((info->userPrevState == CALL_CONF_RCVD) || (info->userPrevState ==  CALL_PROC_SENT))
		{
			assgnCmd[8] = 0x01;		//encoding channelMode for FullRate or halfRate speech speech version 1(01) / FR or HR speech version 3 (41 // not acceptable)
		}

		logPrint(LOG_DEBUG, "User = %p : Sending assgnCmd, User State = %s \n" , info, logGetUserStateString(info->userState));
		pushLayer3ReqToTxDataQ(info , assgnCmd, SAPI_SDCCH);
		assgnCmd[8] = 0x00;
	}
	else if((trx_g->ts[info->userTchChannel.txSLotNum].lchan) == TCHH_FACCHH_SACCHTH)
	{
		//Send Assignment Command for TCH/H SC-0
		assgnCmd[3] = (0x01 << 4) | (info->userTchChannel.subChNum << 3) | info->userTchChannel.txSLotNum ;
		assgnCmd[4] = (trx_g->bts.tsc << 5) | (hoppingFlag << 4) | (spareFlag << 2) | (trx_g->arfcn >> 8);
		assgnCmd[5] = (trx_g->arfcn & 0xFF);

		if ((info->userPrevState == CALL_CONF_RCVD) || (info->userPrevState ==  CALL_PROC_SENT))
		{
			assgnCmd[8] = 0x01; //encoding channelMode for FullRate or halfRate speech speech version 1(01) / FR or HR speech version 3 (41 // not acceptable)
		}

		logPrint(LOG_DEBUG, "User = %p : Sending assgnCmd, User State = %s \n" , info, logGetUserStateString(info->userState));
		pushLayer3ReqToTxDataQ(info , assgnCmd, SAPI_SDCCH);
		assgnCmd[8] = 0x00;
	}
	else
	{}
}
#endif /* FEA_SILENT_CALL */

// Here stdMsgBuf can be any of buffer mentioend above imsi_identity_req , imei_identity_req , loc_update_accept ,
// loc_update_reject , channel_release , lcs_pos_req , cm_service_reject
// Call this function inside one of dataXXXHandler function to send the next request in response to received data.

void pushLayer3ReqToTxDataQ(userInfo* info , const tOCT_UINT8 * const stdMsgBuf, tOCT_UINT8 sapi)
{
	tOCT_UINT8* sndMsg = getTxDataBuffer();
#ifndef NDEBUG
	assert(sndMsg != NULL);
#else
	if(sndMsg == NULL)
	{
		logPrint(LOG_ERR, "pushLayer3ReqToTxDataQ: sndMsg == NULL\n");
		exit(1);
	}
#endif
	buildISendFrameHeader(info);     // Get the LAPDM header bytes
	sndMsg[0] = info->lapdmParam[0]; // L2 header
	sndMsg[1] = info->lapdmParam[1]; // L2 header
	memcpy(&sndMsg[2],  stdMsgBuf , (GSM_MACBLOCK_LEN - 2)); // Copy standard message

	if((stdMsgBuf[1] == 0x05)&& (stdMsgBuf[2] == 0x02) )
	{
		// Lau Accept update LAI and TMSI
		//LAI
		memcpy(&sndMsg[5] , getLaiFromSysInfo() , 5);
		// Tmsi
		memcpy(&sndMsg[11] , info->userTmsi , SIZE_OF_TMSI );
	}
#ifdef FEA_REJECT_CAUSE_CONTROL
	if((stdMsgBuf[1] == 0x05)&& (stdMsgBuf[2] == 0x04) ) // Lau Reject
	{
		//Reject Cause
		sndMsg[5] = info->wlRejectCause;
	}
#endif /* FEA_REJECT_CAUSE_CONTROL */

	if((stdMsgBuf[1] == 0x05)&& (stdMsgBuf[2] == 0x1A) ) // TMSI Reallocation Command
	{
		//LAI, with different LAC
		memcpy(&sndMsg[5], getLaiFromSysInfo(), 5);
		sndMsg[8] = (trx_g->bts.location_area_code + 1) >> 8;
		sndMsg[9] = (trx_g->bts.location_area_code + 1) & 0xFF;

		//TMSI
		memcpy(&sndMsg[12] , info->userOldTmsi, (SIZE_OF_TMSI - 2));
	}

    transactMemoryParams params;
    params.pushToTail = TRUE;
    params.sapi       = sapi;
#ifdef FEA_SILENT_CALL
	if(sapi == SAPI_TCHF || sapi == SAPI_TCHH)
		pushMsgToTransactionMemoryManager((void*)sndMsg , &info->userTchChannel, params); // Put this message at end of Queue ie tail
	else
#endif
	   pushMsgToTransactionMemoryManager((void*)sndMsg , &info->userLogicalChannel, params); // Put this message at end of Queue ie tail

	//Set the timer after sending the request to UE.
	info->userPrevState = info->userState;
	info->userState = WAITING_FOR_L2ACK; // May be we need to keep track of earlier state for debugging purpose , need to think.

	//logPrint(LOG_DEBUG, "User = %p : pushLayer3ReqToTxDataQ Previous State = %s\n ",info, logGetUserStateString(info->userPrevState));
	return;
}

#if 0
// This function checks if the TMSI to page can be accomodated in any of the old paging messages which are in the list already
tOCT_UINT8 checkIfNewPagingNodeIsNeeded(blackListedUserInfo* info)
{
	tOCT_UINT8 i = 0, paddingByte = 0x2B;
	listNode *current = NULL;


	if((headForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] == NULL)||(tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] == NULL))
	{
		return TRUE;
	}

	current = headForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex];

	if(current != NULL)
	{
		while(current != NULL)
		{
			for(i = 4; i <= 16; i = i+4)
			{
				/*  Check if the node can accomodate this TMSI as well in its paging request,
				 *  Note that we are using pagingReqType-3 which can ammodate 4 TMSI's in one msg.
				 */
				if(memcmp((tOCT_UINT8 *)(current->msg + i + 1), &paddingByte, 1 ) == 0) //This TMSI bit is always set to 0x23 while generating random TMSI
				{
					memcpy((tOCT_UINT8*)(current->msg + i), &info->userTmsi[2], SIZE_OF_TMSI - 2);
					return FALSE;
				}

				if(memcmp((tOCT_UINT8*)(current->msg + i), &info->userTmsi[2], SIZE_OF_TMSI - 2) == 0)
				{
					return TRUE;
				}
			}
			current = current->next;
		}
	}

	return TRUE;
}
#endif /* #if 0 */


// Function queue paging request to paging queue
void pushPagingReqToPageQ(blackListedUserInfo* info)
{
	listNode *tail = NULL;
	tOCT_UINT8* sndMsg = (tOCT_UINT8*)getPageRachBuffer(); //malloc(sizeof(sndrcvMsg));
#ifndef NDEBUG
	assert(sndMsg != NULL);
#else
	if(sndMsg == NULL)
	{
		logPrint(LOG_ERR, "pushPagingReqToPageQ: sndMsg == NULL\n");
		exit(1);
	}
#endif

#ifndef NDEBUG
	assert(info->pagingMultiFrame < MAX_PAGING_PERIODICITY);
	assert(info->pagingBlockIndex < MAX_PAGING_BLOCKS_IN_51_FRAME);
#else
	if(info->pagingMultiFrame >= MAX_PAGING_PERIODICITY)
	{
		logPrint(LOG_ERR, "pushPagingReqToPageQ: info->pagingMultiFrame >= MAX_PAGING_PERIODICITY\n");
        exit(1);
    }
	if(info->pagingBlockIndex >= MAX_PAGING_BLOCKS_IN_51_FRAME)
	{
		logPrint(LOG_ERR, "pushPagingReqToPageQ: info->pagingGroup >= MAX_PAGING_BLOCKS_IN_51_FRAME\n");
        exit(1);
    }
#endif

	memcpy(sndMsg,  pagingReqType1 , GSM_MACBLOCK_LEN);    /* Copy standard message */
	memcpy(&sndMsg[4], info->userImsi, SIZE_OF_IDENTITY);  /* Copy IMSI */

	pthread_mutex_lock(&mutexPagingQ);
	tail = tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex];

	pushMsgToList(&tail ,(void*)sndMsg);
	if((headForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] == NULL)||(tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] == NULL))
	{
		headForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] = tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] = tail; // Update for the first time
	}
	else
	{
		tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] = tail; // Just update the tail node
	}
	pthread_mutex_unlock(&mutexPagingQ);

	return;
}

void setNextStateOnReceiptL2Ack(userInfo *info, tOCT_UINT8 sapi)
{
	logPrint(LOG_DEBUG , "User = %p : setNextStateOnReceiptL2Ack User Previous State = %s\n" , info, logGetUserStateString(info->userPrevState) );
	if(info->userState == WAITING_FOR_L2ACK)
	{
		switch(info->userPrevState)
		{
			case LAU_REQ_RECEIVED:
			case IMSI_RECEIVED:
				{
					//This must be L2ACK for IMSI/IMEI Identity request
					info->userState = WAITING_FOR_IDENTITY_RSP;

					//Set the timer after sending the request to UE.
					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

#ifdef FEA_SILENT_CALL
			case SDCCH_SILENT_CALL_IN_PROGRESS:
				{
					//This must be L2ACK for Classmark Enquiry request
					info->userState = WAITING_FOR_CLASSMARK;

					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

			case RRLP_GPS_ASSIST_DATA_ACK_RCVD:
				{
					/* This must be L2ACK for LCS Positioning request */
					info->userState = WAITING_FOR_LCS_POSN_RSP;

					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_LCS_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;
			case TCH_SILENT_CALL_IN_PROGRESS:
				{
					/* This must be L2ACK for LCS Positioning request */
					info->userState = WAITING_FOR_LCS_POSN_RSP;
					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_LCS_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;
#endif
			case PAGING_RESP_RECEIVED:
				{
					int timerValue = TIMER_VALUE_WAITING_FOR_UE_RSP;

					if(info->userBlacklisted == TRUE)
					{
						blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
						if(  blackUserInfo != NULL &&
								(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) == SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) ||
								 ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) == SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) ) )
						{
							info->userState = WAITING_FOR_LCS_POSN_RSP;
							timerValue = TIMER_VALUE_WAITING_FOR_LCS_RSP;
						}
						else
						{
							info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;
						}
					}
					else
					{
						info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;// In paging scenario this will waiting for disc.
					}

					tOCT_UINT8 retVal = timerStart(&info->tmr , timerValue, 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

#ifdef FEA_SILENT_CALL
			case END_SILENT_CALL:
#endif

#ifndef MM_INFO
			case IMEI_RECEIVED:
#endif
			case LCS_POS_RECEIVED:
				//case ATTACH_RECEIVED:
				{
					//This is L2 Ack for the LAU Accept/Channel Release , don't do anything here as we will wait for TMSI-REALLOCATION-COMPLETE/DISC MESSAGE
					info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;

					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

#ifdef MM_INFO
			case IMEI_RECEIVED:
				{
					if((info->userBlacklisted == TRUE)&&(trx_g->bts.nwNameLen != 0))
					{
						//For Blacklisted User we had sent MM-INFO , Now we will send LAU-ACCEPT , here
						info->userState = MM_INFO_SENT;
						pushLayer3ReqToTxDataQ(info , locUpdateAccept, sapi);
						logPrint(LOG_DEBUG, "User = %p : Sending locUpdateAccept, User State = %s \n" , info, logGetUserStateString(info->userState));
					}
					else
					{
						//This is L2 Ack for the LAU Accept/Channel Release , don't do anything here as we will wait for TMSI-REALLOCATION-COMPLETE/DISC MESSAGE
						info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;

						tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
						assert(retVal == RC_TCB_OK);
					}
				}
				break;

			case MM_INFO_SENT:
				{
					//This is L2 Ack for the LAU Accept/Channel Release , don't do anything here as we will wait for TMSI-REALLOCATION-COMPLETE/DISC MESSAGE
					info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;

					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;
#endif
			case SETUP_RECEIVED:
				{
					// Ack for Release Complete, Send Channel Release here
					info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;
				pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
				}
				break;

			case CM_SERVICE_REQ_RECEIVED:
				{
					if(info->userBlacklisted == TRUE)
					{
						info->userState = WAITING_FOR_CIPHERING_MODE_COMPLETE;
					}
					else
					{
						info->userState = WAITING_FOR_IDENTITY_RSP;
					}

					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

			case L3_REJECT_FOR_UE:
				{
					// L2 Ack for either LAU Reject or CM Service Reject, We have to send Channel Release here
					info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;
#ifdef FEA_EMER
					if((info->cmServiceReqTypeRcvd == 0x02) && (trx_g->bts.Emergencyredirectenable == TRUE))
					{
						redirectInfo2g redirectInfo;
						redirectInfo.bandIndicator = trx_g->bts.Redirectemergencyinfo.bandIndicator;
						redirectInfo.arfcn = trx_g->bts.Redirectemergencyinfo.arfcn;
						redirectInfo.bsic = trx_g->bts.Redirectemergencyinfo.bsic;
						/* Send Channel Release filling redirect info. */
						sendChannelReleaseWithRedirection(info, &redirectInfo, sapi);
                    break;
                }
#endif
					 if(info->userBlacklisted == TRUE && trx_g->bts.redirType != FXL_GSM_NO_REDIR)
					{
						redirectInfo2g redirectInfo;
						redirectInfo.bandIndicator = trx_g->bts.redirBand;
						redirectInfo.arfcn = trx_g->bts.redirArfcn;
						redirectInfo.bsic = trx_g->bts.redirBsic;

						/* Send Channel Release filling redirect info. */
                       sendChannelReleaseWithRedirection(info, &redirectInfo, sapi);
					}
					else
					{
    				   pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
						logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
					}
				}
				break;

#if	defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
			case TCH_ALLOCATED: // Ack for Assignment Command
				{
					info->userState = WAITING_FOR_SABM_ON_FACCH;

					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;
#endif /* FEA_SILENT_CALL || FEA_VOICE_CALL_TO_TARGET */

			case WAITING_TO_SEND_SETUP:
				{
					//This must be L2ACK for SETUP
					info->userState = WAITING_FOR_CALL_CONF;

					//Set the timer after sending the request to UE.
					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

			case DISC_SENT:
				{
					//This must be L2ACK for DISC
					info->userState = REL_PROC;

					//Set the timer after sending the request to UE.
					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

			case REL_PROC:
				{
					//This must be L2ACK for REL_CMP
					info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;

					blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(info->userImsi) , TRUE, FALSE);

					if(info->userTchChannel.txSLotNum)
					{
					pushLayer3ReqToTxDataQ(info , channelRelease, sapi);		/*Channel Release important, else direct deactivation sometimes takes time resulting in crash*/
						logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
					}
					else
					{
					pushLayer3ReqToTxDataQ(info , channelRelease, sapi);		/*Channel Release important, else direct deactivation sometimes takes time resulting in crash*/
						logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));

						if( ((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING)) )
						{
							blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_ALERTING;

							/* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
					        if(configUeIdList.defaultConfig == BLACKLIST)
					        {
								tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
								if(retVal == RC_TCB_OK)
								  logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started on channel release for alert ");
							}
						}
					}
				}
				break;

			case WAITING_FOR_REL_CMP:
				{
					//This must be L2ACK for DISC
					info->userState = WAITING_FOR_REL_CMP;

					//Set the timer after sending the request to UE.
					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

#ifdef FEA_VOICE_CALL_TO_TARGET
			case PH_CONNECT_RCVD:
			case WAITING_FOR_CALL_EST:
				{
					if((targetVoiceCallCntxt.isOnGoingCall) && (targetVoiceCallCntxt.mtTsNum == info->userTchChannel.txSLotNum) &&
							(targetVoiceCallCntxt.mtSubChan == info->userTchChannel.subChNum))
					{
						info->userState = CALL_EST;
                        targetVoiceCallCntxt.isCallConnected = TRUE;
						logPrint(LOG_DEBUG, "CALL Established !!! Hear Me Out !!");

						/* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/
						if(configUeIdList.defaultConfig == BLACKLIST)
						{
							blackListedUserInfo* MoblackUserInfo = NULL;
                            blackListedUserInfo* MtblackUserInfo = NULL;

							MoblackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)targetVoiceCallCntxt.moImsiStr, FALSE, FALSE);
	                        if(MoblackUserInfo!=NULL)
	                        {
	                            timerStop(&MoblackUserInfo->tmr);
								logPrint(LOG_DEBUG, "periodic timer Stop for mo user !!");
	                        }
	                        MtblackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)targetVoiceCallCntxt.mtImsiStr, FALSE, FALSE);
	                        if(MtblackUserInfo!=NULL)
	                        {
	                            timerStop(&MtblackUserInfo->tmr);
		    					logPrint(LOG_DEBUG, "periodic timer Stop for mt user !!");
	                        }
						}
					}
					else
					{
						info->userState = info->userPrevState;
						logPrint(LOG_DEBUG, "L2Ack for MO_Connect");
					}
				}
				break;

			case HOLD_RCVD:
				{
					/* L2-ACK for HOLD_REJ, Reset state to CALL_EST */
					info->userState = CALL_EST;
				}
				break;
#endif

#ifdef FEA_DECODE_MO_SMS
			case CP_ACK_SENT:
				{
					//This must be L2ACK for CP_ACK, RP_ACK sent
					//Start Timer, to receive RP_ACK from phone
					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_UE_RSP , 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;
#endif /* FEA_DECODE_MO_SMS */

			case CALL_PROC_SENT:
				{
					// This must be L2ACK for CALL_PROC
#ifdef FEA_VOICE_CALL_TO_TARGET
					if((targetVoiceCallCntxt.moImsiStr != NULL) && (targetVoiceCallCntxt.moMsIsdnStr != NULL) &&\
							(memcmp(info->userImsi_str , targetVoiceCallCntxt.moImsiStr, MAX_IDENTITY_LENGTH_STR) == 0))
					{
						// Allocate TCH channel for this user, SDCCH channel will be deallocated when TCH assignment is completed.
						if(allocateHalfTrafficChannel(&(info->userTchChannel)) == TRUE)
						{
							updateUserDb(info, &(info->userTchChannel));
							activateLogicalChannel(info->userTchChannel.txSLotNum , info->userTchChannel.subChNum);
							info->userState = TCH_ALLOCATED;
							logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the TCH/H, FACCH/H and SACCH/H, TimeSlot = %d , SubChannel = %d\n" , info, info->userTchChannel.txSLotNum , info->userTchChannel.subChNum );
							preparePushAssgnCmdToTxDataQ(info);
						}
						else if(allocateFullTrafficChannel(&(info->userTchChannel)) == TRUE)
						{
							// Update the user pointer in TCH channel as well
							updateUserDb(info, &(info->userTchChannel));

							activateLogicalChannel(info->userTchChannel.txSLotNum , info->userTchChannel.subChNum);
							info->userState = TCH_ALLOCATED;
							logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the TCH/F, FACCH/F and SACCH/F, TimeSlot = %d , SubChannel = %d\n" , info, info->userTchChannel.txSLotNum , info->userTchChannel.subChNum );

							preparePushAssgnCmdToTxDataQ(info);
						}
						else
						{
							logPrint(LOG_ERR , "User = %p, Could not allocate TCH for MO Call, send DISC to MO", info);
		    				pushLayer3ReqToTxDataQ(info , disconnect, sapi);
						}
					}
					else
#endif /* FEA_VOICE_CALL_TO_TARGET */
					{
						info->userState = info->userPrevState;
						info->userState = WAITING_FOR_MT_CONNECT;
						logPrint(LOG_DEBUG , "User = %p : Sending ALERT to MO" , info);
						pushLayer3ReqToTxDataQ(info , alert, sapi);
					}
				}
				break;

			case WAITING_FOR_MT_CONNECT:
				{
					info->userState = info->userPrevState;
					tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_FOR_MT_ALERT, 0 , &userInfoTimerCbFunction, info);
					assert(retVal == RC_TCB_OK);
				}
				break;

			case RRLP_GPS_ASSIST_DATA_SENT:
				{
					/* This must be L2-Ack for RRLP Assistance Data Sent */
					if(   info->rrlpGpsAssistCount < RRLP_GPS_ASSIST_OCTET_LEN
							&& rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount][0] != 0)
					{
						info->userState = RRLP_GPS_ASSIST_DATA_SENT;

						if(info->userTchChannel.txSLotNum)
            				pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapi);
						else
            				pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapi);

						logPrint(LOG_DEBUG, "User = %p : RRLP - Sending rrlpGpsAssistData[%d][%d], User State = %s \n" , info, info->rrlpGpsAssistSegment,(info->rrlpGpsAssistCount-1), logGetUserStateString(info->userState));
					}
					else
					{
						info->rrlpGpsAssistCount = 0;
						/* Start Timer, to receive Assistance Data ACK from phone */
						tOCT_UINT8 retVal = timerStart(&info->tmr , TIMER_VALUE_WAITING_FOR_LCS_RSP , 0 , &userInfoTimerCbFunction, info);
						assert(retVal == RC_TCB_OK);
					}
				}
				break;

			default:
				{
					//logPrint(LOG_ERR , "User = %p : setNextStateOnReceiptL2Ack User Previous State = %s\n" , info, logGetUserStateString(info->userPrevState) );
				}
				break;
		}
	}
	else
	{
		logPrint(LOG_ERR , "User = %p : setNextStateOnReceiptL2Ack SOMETHING WRONG User State = %s\n" ,  info, logGetUserStateString(info->userState) );

		timerStop(&info->tmr);

		blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(info->userImsi) , TRUE, FALSE);
		if(blackUserInfo != NULL)
			blackUserInfo->isInConnectedState = FALSE;

		if(info->userLogicalChannel.txSLotNum ||
				isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
		{
			if(!(info->userTchChannel.txSLotNum))  //Delete User as well
				clearUserContext(info, FALSE, TRUE);
			else
				clearUserContext(info, FALSE, FALSE);
		}

		if(info->userTchChannel.txSLotNum)
			clearUserContext(info, TRUE, TRUE);

	}

	return;
}

tOCT_UINT8 resendLayer3MessageWaitingForL2Ack(userInfo *info, tOCT_UINT8 sapi)
{
	tOCT_UINT8 ret_val = TRUE;
	switch(info->userPrevState)
	{
		case LAU_REQ_RECEIVED:
			{
				//Resend IMSI Identity Req
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
				pushLayer3ReqToTxDataQ(info , imsiIdentityReq, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent imsiIdentityReq no of times = %d\n", info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case ATTACH_RECEIVED:
			{
				//Resend Attach Reject
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
				pushLayer3ReqToTxDataQ(info , attachReject, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent attachReject no of times = %d\n", info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case IMSI_RECEIVED:
			{
				//Resend classmarkEnquiry Req
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
				pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent classmarkEnquiry no of times = %d\n",info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case CLASSMARK_RECEIVED:
			{
				//Resend imeiIdentityReq
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
                      pushLayer3ReqToTxDataQ(info , imeiIdentityReq, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent imeiIdentityReq no of times = %d\n",info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case IMEI_RECEIVED:
			{
				if(info->userBlacklisted == TRUE)
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
					pushLayer3ReqToTxDataQ(info , locUpdateAccept, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent locUpdateAccept no of times = %d\n", info, info->retransmissionCountForL3Msg);
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
			}
			break;

		case CM_SERVICE_REQ_RECEIVED:
			{
				if(info->userBlacklisted == TRUE)
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
					pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent cipheringModeCommand no of times = %d \n", info, info->retransmissionCountForL3Msg);
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
				else
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
						pushLayer3ReqToTxDataQ(info , tmsiIdentityReq, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent tmsiIdentityReq no of times = %d\n", info, info->retransmissionCountForL3Msg);
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
			}
			break;

		case L3_REJECT_FOR_UE:
			{
				if(info->cmServiceReqTypeRcvd != 0)
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
					pushLayer3ReqToTxDataQ(info , cmServiceReject, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent cmServiceReject no of times = %d\n", info, info->retransmissionCountForL3Msg );
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
				else
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
						pushLayer3ReqToTxDataQ(info , locUpdateReject, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent locUpdateReject no of times = %d\n", info, info->retransmissionCountForL3Msg );
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}

				}
			}
			break;

		case RRLP_GPS_ASSIST_DATA_SENT:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					/* Send RRLP GPS Assistance Data */
					info->rrlpGpsAssistCount = 0;
					info->userState = info->userPrevState;
					pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapi);
					logPrint(LOG_DEBUG, "User = %p : RRLP - Re-sending rrlpGpsAssistData[%d][%d], User State = %s \n" , info, info->rrlpGpsAssistSegment,(info->rrlpGpsAssistCount-1), logGetUserStateString(info->userState));

					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case LCS_POS_RECEIVED:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
					pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent channelRelease no of times = %d\n", info, info->retransmissionCountForL3Msg);

					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

#ifdef FEA_SILENT_CALL
		case SDCCH_SILENT_CALL_IN_PROGRESS:
			{
				blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

				if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL))
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
    				pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent classmarkEnquiry no of times = %d\n", info, info->retransmissionCountForL3Msg );
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case RRLP_GPS_ASSIST_DATA_ACK_RCVD:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
					pushLayer3ReqToTxDataQ(info , lcsPosReq, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent lcsPosReq no of times = %d\n", info, info->retransmissionCountForL3Msg);

					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case TCH_SILENT_CALL_IN_PROGRESS:
			{
				if(info->userState == WAITING_FOR_LCS_POSN_RSP)
				{
					/* Some Phones send L2-ACK for the LCS_REQ, but doesn't respond to the message,
					 * for such phones, as a workaround we send LCS_REQ for 50 times and then release
					 * the channel, to restart the process.
					 */

					if(info->retransmissionCountForL3Msg < 50)
					{
						/* Set the Previous state to new state again so that next time it will get set properly */
						info->userState = info->userPrevState;
                    pushLayer3ReqToTxDataQ(info , lcsPosReq, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent LCS Positioning Req no of times = %d\n", info, info->retransmissionCountForL3Msg );

						info->retransmissionCountForL3Msg++;
					}
					else if(info->retransmissionCountForL3Msg < (MAX_RETRANSMISSION_COUNT_FOR_L3_MSG + 50))
					{
						/* Set the Previous state to new state again so that next time it will get set properly */
						info->userState = info->userPrevState;
    				pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent channelRelease no of times = %d\n", info, info->retransmissionCountForL3Msg);

						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
				else if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					/* Set the Previous state to new state again so that next time it will get set properly */
					info->userState = info->userPrevState;
				pushLayer3ReqToTxDataQ(info , lcsPosReq, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent LCS Positioning Req no of times = %d\n", info, info->retransmissionCountForL3Msg );

					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case END_SILENT_CALL:
#endif
		case WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
					if((isTimeSlotTypeSupportsTCHF(info->userTchChannel.txSLotNum) == TRUE) ||
							(isTimeSlotTypeSupportsTCHH(info->userTchChannel.txSLotNum) == TRUE)) // TCH Active
   				  pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					else
#endif
				  pushLayer3ReqToTxDataQ(info , channelRelease, sapi);

					logPrint(LOG_DEBUG , "User = %p : Resent channelRelease no of times = %d\n", info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}

			}
			break;

		case TMSI_REALLOCATION_COMPLETE_RECEIVED:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					/* Set the Previous state to new state again so that next time it will get set properly */
					info->userState = info->userPrevState;

#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
					blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
					if(blackUserInfo!= NULL && trx_g->bts.sendSmsDuringRegistration == TRUE)
					{
						/* Send Cipher Mode Command */
						pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
						logPrint(LOG_DEBUG, "User = %p : Resent cipheringModeCommand no of times = %d\n",
								info, info->retransmissionCountForL3Msg );
					}
					else
					{
						pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
						logPrint(LOG_DEBUG, "User = %p : Resent channelRelease no of times = %d\n",
								info, info->retransmissionCountForL3Msg );
					}
#else
					pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					logPrint(LOG_DEBUG, "User = %p : Resent channelRelease no of times = %d\n",
							info, info->retransmissionCountForL3Msg );
#endif
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case PAGING_RESP_RECEIVED:
			{
				if(info->userBlacklisted == TRUE)
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

						if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RELEASE) == SET_TRIGGER_FOR_RELEASE))
						{
							/* Set the Previous state to new state again so that next time it will get set properly */
							info->userState = info->userPrevState;
							pushLayer3ReqToTxDataQ(info , tmsiReallocationCmd, sapi);
							logPrint(LOG_DEBUG, "User = %p : Resent TMSI Reallocation command\n" , info);
							info->retransmissionCountForL3Msg++;
						}
						else if(  blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_REDIRECTION) == SET_TRIGGER_FOR_REDIRECTION) )
						{
							/* Send Channel Release filling redirect info. */
							sendChannelReleaseWithRedirection(info, &blackUserInfo->redirectInfo, sapi);
						}
#ifdef FEA_MT_SMS
						else if(blackUserInfo != NULL && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_INDIVIDUAL_SMS) == SET_TRIGGER_FOR_INDIVIDUAL_SMS) || \
									((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BROADCAST_SMS) == SET_TRIGGER_FOR_BROADCAST_SMS)))
						{
							//Set the Previous state to new state again so that next time it will get set properly
							info->userState = info->userPrevState;
					    pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
							logPrint(LOG_DEBUG , "User = %p : Resent cipheringModeCommand no of times = %d \n", info, info->retransmissionCountForL3Msg);
							info->retransmissionCountForL3Msg++;
						}
#endif /* FEA_MT_SMS */
						else if( blackUserInfo != NULL &&
								(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) == SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) ||
								 ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) == SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) ) )
						{
							//Set the Previous state to new state again so that next time it will get set properly
							info->userState = info->userPrevState;
							pushLayer3ReqToTxDataQ(info , lcsPosReq, sapi);
							logPrint(LOG_DEBUG , "User = %p : Resent LCS Positioning Req no of times = %d\n", info, info->retransmissionCountForL3Msg );
							info->retransmissionCountForL3Msg++;
						}
						else
						{
							//Set the Previous state to new state again so that next time it will get set properly
							info->userState = info->userPrevState;
					    pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
							logPrint(LOG_DEBUG , "User = %p : Resent channelRelease no of times = %d\n", info, info->retransmissionCountForL3Msg );
							info->retransmissionCountForL3Msg++;
						}
					}
					else
					{
						ret_val = FALSE;
					}
				}
				else
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
					pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent channelRelease no of times = %d\n", info, info->retransmissionCountForL3Msg );
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
			}
			break;

		case SETUP_RECEIVED:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
				pushLayer3ReqToTxDataQ(info , releaseComplete, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent releaseComplete no of times = %d\n", info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

#if	defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
		case TCH_ALLOCATED:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
					preparePushAssgnCmdToTxDataQ(info);
					logPrint(LOG_DEBUG,"User = %p : Resent Assignment Command no of times = %d \n", info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;
#endif /* FEA_SILENT_CALL || FEA_VOICE_CALL_TO_TARGET */

#ifdef FEA_MT_SMS
		case EST_L2_SAPI3_FOR_MT_SMS:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					// Establish Lapdm SAPI-3 Multiframe mode connection.
					tOCT_UINT8* sapi3SabmFrame = getTxDataBuffer();
					assert(sapi3SabmFrame != NULL);
					memcpy(sapi3SabmFrame,	fill_frame, GSM_MACBLOCK_LEN); // Copy standard message
					buildSapi3SABMFrameHeader(sapi3SabmFrame);
	                transactMemoryParams params;
	                params.pushToTail = TRUE;
	                params.sapi       = sapi;
	                pushMsgToTransactionMemoryManager((void*)sapi3SabmFrame , &info->userLogicalChannel, params); // Put this message to tail

					//Set the next state to Waiting for L2 Ack
					info->userState = WAITING_FOR_L2ACK;
					logPrint(LOG_DEBUG,"User = %p : Establishing L2 SAPI-3 for MT-SMS, no of attempts = %d \n", info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case CP_ACK_RECEIVED:
			{
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
				    pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resent channelRelease no of times = %d\n", info, info->retransmissionCountForL3Msg );
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;
#endif /* FEA_MT_SMS */

		case WAITING_TO_SEND_SETUP:
			{
				//Resend SETUP
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
					blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(info->userImsi) , TRUE, FALSE);

					if( ((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) != SET_TRIGGER_FOR_ALERTING)) )
					{
#ifdef FEA_ALERT
						tOCT_UINT8 callingBcd_length, *tmpPtr = NULL;
						tOCT_UINT8 tmpSetUpAlert[GSM_MACBLOCK_LEN] = {0};

						memcpy(tmpSetUpAlert, setUpAlert, GSM_MACBLOCK_LEN);

						tmpPtr = &tmpSetUpAlert[6];
						if(blackUserInfo->alertIsdn_str != NULL)
						{
							logPrint(LOG_DEBUG, "MSISDN is %s\n",blackUserInfo->alertIsdn_str);
							callingBcd_length = create_address(SMS_SMSC_ADDRESS, TOA_TON_INTERNATIONAL | TOA_NPI_ISDN, ( tOCT_UINT8* )blackUserInfo->alertIsdn_str, &tmpPtr);
						}
						else
						{
							callingBcd_length = create_address(ISDN_ADDRESS , TOA_TON_UNKNOWN | TOA_NPI_UNKNOWN, ( tOCT_UINT8* )blackUserInfo->alertIsdn_str, &tmpPtr);
						}
						tmpSetUpAlert[0] = (((callingBcd_length + 5) << 2) | 0x01);  // L2 Length

						pushLayer3ReqToTxDataQ(info , tmpSetUpAlert, sapi);

						logPrint(LOG_DEBUG , "User = %p : Resent setUp for Alerting no of times = %d\n", info, info->retransmissionCountForL3Msg );
						info->retransmissionCountForL3Msg++;
#endif
					}

#ifdef FEA_VOICE_CALL_TO_TARGET
					else if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL))
					{
						userInfo* moInfo = NULL;
						logicalChannelIdentity ch_id;
						ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
						ch_id.subChNum  = targetVoiceCallCntxt.moSubChan;

						if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum > 0)) //&& (ch_id.subChNum < MAX_SUBCHAN_TIMESLOT))
						{
							moInfo = userFindUsingLogicalChannel(&ch_id);
						}
						if((targetVoiceCallCntxt.moTsNum == 0xFF) || (moInfo == NULL))
						{
							logPrint(LOG_DEBUG, "User = %p : MO already Disconnected Sending channelRelease to MT, User State = %s", info, logGetUserStateString(info->userState));
							info->retransmissionCountForL3Msg = 0;
                            pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
						}
						else
						{
							tOCT_UINT8 callingBcd_length, *tmpPtr = NULL;
							tOCT_UINT8 tmpSetUp[GSM_MACBLOCK_LEN] = {0};

							memcpy(tmpSetUp, setUp, GSM_MACBLOCK_LEN);

							tmpPtr = &tmpSetUp[7];
							if(targetVoiceCallCntxt.moMsIsdnStr != NULL)
							{
								logPrint(LOG_DEBUG, "MO-MSISDN for Target Voice Call is %s\n",targetVoiceCallCntxt.moMsIsdnStr);
								callingBcd_length = create_address(SMS_SMSC_ADDRESS, TOA_TON_INTERNATIONAL | TOA_NPI_ISDN, ( tOCT_UINT8* )targetVoiceCallCntxt.moMsIsdnStr, &tmpPtr);
							}
							else
							{
								callingBcd_length = create_address(ISDN_ADDRESS , TOA_TON_UNKNOWN | TOA_NPI_UNKNOWN, ( tOCT_UINT8* )targetVoiceCallCntxt.moMsIsdnStr, &tmpPtr);
							}
							tmpSetUp[0] = (((callingBcd_length + 9) << 2) | 0x01);  // L2 Length

                            pushLayer3ReqToTxDataQ(info , tmpSetUp, sapi);

							logPrint(LOG_DEBUG, "User = %p : Sending SETUP, User State = %s \n" , info, logGetUserStateString(info->userState));
						}
					}
#endif /* FEA_VOICE_CALL_TO_TARGET */
					else
					{}
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case WAITING_FOR_MT_CONNECT:
		case ALERT_RCVD:
			{
#ifdef FEA_VOICE_CALL_TO_TARGET
				if((targetVoiceCallCntxt.isOnGoingCall) && (targetVoiceCallCntxt.moTsNum == info->userTchChannel.txSLotNum) &&
						(targetVoiceCallCntxt.moSubChan == info->userTchChannel.subChNum))
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
					    pushLayer3ReqToTxDataQ(info , alert, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resent alert no of times = %d\n", info, info->retransmissionCountForL3Msg );
						info->retransmissionCountForL3Msg++;
						break;
					}
					else
					{
						ret_val = FALSE;
						break;
					}
				}
#endif
				// Waiting of MT_CONNECT
				logPrint(LOG_DEBUG , "User = %p  T301 Expired \n", info);
				info->userPrevState = info->userState;
				ret_val = FALSE;
			}
			break;

#ifdef FEA_VOICE_CALL_TO_TARGET
		case DISC_SENT:
			{
				//Resend DISCONNECT
				if(  (targetVoiceCallCntxt.isOnGoingCall) &&
						(((targetVoiceCallCntxt.moTsNum == info->userTchChannel.txSLotNum) && (targetVoiceCallCntxt.moSubChan == info->userTchChannel.subChNum)) ||
						 ((targetVoiceCallCntxt.mtTsNum == info->userTchChannel.txSLotNum) && (targetVoiceCallCntxt.mtSubChan == info->userTchChannel.subChNum))) )
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						//Set the Previous state to new state again so that next time it will get set properly
						info->userState = info->userPrevState;
						pushLayer3ReqToTxDataQ(info , disconnect, sapi);
						logPrint(LOG_DEBUG , "User = %p : Resending DISC to MT, User State = %s \n" , info, logGetUserStateString(info->userState));

						info->retransmissionCountForL3Msg++;
					}
					else
					{
						info->userState = info->userPrevState;
						info->userState = DISC_SENT;
						ret_val = FALSE;
					}
				}
				else
				{
					if(info->userLogicalChannel.txSLotNum)
					{
						/* MO Call flow from Blacklisted UE */
						if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
						{
							//Set the Previous state to new state again so that next time it will get set properly
							info->userState = info->userPrevState;
        					pushLayer3ReqToTxDataQ(info , disconnect, sapi);
							logPrint(LOG_DEBUG , "User = %p : Resending DISC to MO, User State = %s \n" , info, logGetUserStateString(info->userState));

							info->retransmissionCountForL3Msg++;
						}
						else
						{
							info->userState = info->userPrevState;
							info->userState = DISC_SENT;
							ret_val = FALSE;
						}
					}
				}
			}
			break;

		case WAITING_FOR_CALL_EST:
			{
				if((targetVoiceCallCntxt.isOnGoingCall) && (targetVoiceCallCntxt.moTsNum == info->userTchChannel.txSLotNum) &&
						(targetVoiceCallCntxt.moSubChan == info->userTchChannel.subChNum))
				{
					if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
					{
						logPrint(LOG_DEBUG , "User = %p : Waiting on CONNECT no of times = %d\n", info, info->retransmissionCountForL3Msg );
						info->userState = WAITING_FOR_CALL_EST;
                        pushLayer3ReqToTxDataQ(info , Connect, sapi);
						info->retransmissionCountForL3Msg++;
					}
					else
					{
						ret_val = FALSE;
					}
				}
			}
			break;

		case HOLD_RCVD:
			{
				/* Resend Hold Reject */
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;
                    pushLayer3ReqToTxDataQ(info , holdRej, sapi);
					logPrint(LOG_DEBUG , "User = %p : Resending holdRej, User State = %s \n" , info, logGetUserStateString(info->userState));
					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;
#endif /* FEA_VOICE_CALL_TO_TARGET */

		case REL_PROC:
			{
				//Resend Release Complete
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					//Set the Previous state to new state again so that next time it will get set properly
					info->userState = info->userPrevState;

					if(info->userTchChannel.txSLotNum)
				      pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					else
                      pushLayer3ReqToTxDataQ(info , channelRelease, sapi);

					logPrint(LOG_DEBUG , "User = %p : Resending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));

					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		case WAITING_FOR_REL_CMP:
			{
				//WAIT for	RLC
				if(info->retransmissionCountForL3Msg < MAX_RETRANSMISSION_COUNT_FOR_L3_MSG)
				{
					logPrint(LOG_DEBUG , "User = %p : Waiting on RLC no of times = %d\n", info, info->retransmissionCountForL3Msg );
					info->userState = WAITING_FOR_REL_CMP;
					if(info->userTchChannel.txSLotNum)
                      pushLayer3ReqToTxDataQ(info , release, sapi);
					else
				      pushLayer3ReqToTxDataQ(info , release, sapi);

					info->retransmissionCountForL3Msg++;
				}
				else
				{
					ret_val = FALSE;
				}
			}
			break;

		default:
			{
				logPrint(LOG_INFO , "User = %p : Timer Expired but ,Not sure what to do in this state %s\n" ,info, logGetUserStateString(info->userPrevState) );
			}
			break;

	}
	return ret_val;
}

//This function will be called out from Main thread
void userInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr)
{
	userInfo *info = (userInfo*)infoPtr;
	blackListedUserInfo* blackUserInfo;
	//timerStatus();
	if(info != NULL) // For now just clean up that user
	{
        tOCT_UINT8 sapi = SAPI_IDLE;
        if(info->userTchChannel.txSLotNum)
        {
            if(isTimeSlotTypeSupportsTCHF(info->userTchChannel.txSLotNum))
              sapi = SAPI_TCHF;
            else if(isTimeSlotTypeSupportsTCHH(info->userTchChannel.txSLotNum))
              sapi = SAPI_TCHH;
            else
            {}
        }
        else if(isTimeSlotTypeSupportsSDCCH(info->userLogicalChannel.txSLotNum))
          sapi = SAPI_SDCCH;
        else
        {}
		logPrint(LOG_INFO, "User = %p : Timer Expired User State = %s , User Previous State = %s\n" , info, logGetUserStateString(info->userState) , logGetUserStateString(info->userPrevState) );
		if(        info->userState == SDCCH_CHANNEL_ALLOCATED
				|| info->userState == CIPHERING_MODE_COMPLETE_RECEIVED
				|| info->userState == WAITING_FOR_ALERT
                || info->userPrevState == DISC_RECEIVED
#ifdef FEA_MT_SMS
				|| (info->userState == CP_DATA_RECEIVED)
#endif
#ifdef FEA_DECODE_MO_SMS
				|| (info->userState == CP_ACK_SENT)
#endif
		  )
		{
			blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(info->userImsi) , TRUE, FALSE);
			if(blackUserInfo != NULL)
				blackUserInfo->isInConnectedState = FALSE;

			if(info->userLogicalChannel.txSLotNum ||
					isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
			{
				if(!(info->userTchChannel.txSLotNum))  //Delete User as well
					clearUserContext(info, FALSE, TRUE);
				else
					clearUserContext(info, FALSE, FALSE);
			}

			if(info->userTchChannel.txSLotNum)
				clearUserContext(info, TRUE, TRUE);

		}
		else if (( info->userState == WAITING_FOR_L2ACK)|| \
				( info->userState == WAITING_FOR_IDENTITY_RSP) || \
				( info->userState == WAITING_FOR_LCS_POSN_RSP) || \
				( info->userState == WAITING_FOR_CALL_CONF) || \
				( info->userState == WAITING_FOR_MT_CONNECT) || \
				( info->userState == REL_PROC) || \
				( info->userState == WAITING_FOR_REL_CMP) || \
				( info->userState == WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE) || \
				((info->userState == SABM_RECEIVED_ON_FACCH) && info->userPrevState == TCH_ALLOCATED)
#ifdef FEA_SILENT_CALL
				||(info->userState == WAITING_FOR_CLASSMARK)
#endif
			)
		{
			if(resendLayer3MessageWaitingForL2Ack(info, sapi) == FALSE)
			{
				blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
				if(blackUserInfo != NULL)
				{
					if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING)
					{
						if(info->userState == WAITING_FOR_MT_CONNECT)
						{
							/*Send DISCONNECT*/
							info->userPrevState = info->userState;
							info->userState = DISC_SENT;
							logPrint(LOG_DEBUG , "User = %p : Going to send DISC to MT, User State = %s \n" , info, logGetUserStateString(info->userState));
    						pushLayer3ReqToTxDataQ(info , disconnect, sapi);
							return;
						}
						if((info->userState == WAITING_FOR_REL_CMP) || (info->userPrevState == WAITING_FOR_REL_CMP))
						{
							blackUserInfo->isInConnectedState = FALSE;

							if(info->userLogicalChannel.txSLotNum ||
									isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
							{
								if(!(info->userTchChannel.txSLotNum))  //Delete User as well
									clearUserContext(info, FALSE, TRUE);
								else
									clearUserContext(info, FALSE, FALSE);
							}

							if(info->userTchChannel.txSLotNum)
								clearUserContext(info, TRUE, TRUE);

							return;
						}
					}
					else if (!info->userTchChannel.txSLotNum && info->userState == WAITING_FOR_MT_CONNECT)
					{
						/* MO Call Flow for Blacklisted device, send Disconnect after ALerting is done */
						info->userPrevState = info->userState;
						info->userState = DISC_SENT;
						logPrint(LOG_DEBUG , "User = %p : Sending DISC to MO, User State = %s \n" , info, logGetUserStateString(info->userState));
						pushLayer3ReqToTxDataQ(info , disconnect, sapi);
					}
#ifdef FEA_VOICE_CALL_TO_TARGET
					else
					{
						if(info->userState == WAITING_FOR_MT_CONNECT || info->userState == WAITING_FOR_CALL_EST /*Added for MO disc if con_ack !rcvd */)
						{
							/*Send DISCONNECT*/
							info->userPrevState = info->userState;
							info->userState = DISC_SENT;
							logPrint(LOG_DEBUG , "User = %p : Going to send DISC to MT, User State = %s \n" , info, logGetUserStateString(info->userState));
    						pushLayer3ReqToTxDataQ(info , disconnect, sapi);

							if((targetVoiceCallCntxt.isOnGoingCall))
							{
								/*Send DISC to MO*/
								userInfo* moInfo = NULL;
								logicalChannelIdentity ch_id;
								ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
								ch_id.subChNum  = targetVoiceCallCntxt.moSubChan;
								moInfo = userFindUsingLogicalChannel(&ch_id);
								if(moInfo != NULL)
								{
									moInfo->userPrevState= info->userState;
									moInfo->userState = DISC_SENT;
									logPrint(LOG_DEBUG , "User = %p : Sending DISC to MO User = %p \n" , info,moInfo);
    								pushLayer3ReqToTxDataQ(moInfo , disconnect, sapi);
								}
								else
								{
									logPrint(LOG_DEBUG , "User = %p : no MO user found for this call \n" , info);
								}
							}
							return;
						}

						if((info->userState == WAITING_FOR_REL_CMP) || (info->userState == DISC_SENT/*when MT switches off after Alerting*/))
						{
							if(info->userState == DISC_SENT)
								checkAndResetCallCtx(info);
							else
								logPrint(LOG_DEBUG , "User = %p : MaxTry for RLC wait, freeing the channels, User State = %s \n" , info, logGetUserStateString(info->userState));

							blackUserInfo->isInConnectedState = FALSE;

							if(info->userLogicalChannel.txSLotNum ||
									isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
							{
								if(!(info->userTchChannel.txSLotNum))  //Delete User as well
									clearUserContext(info, FALSE, TRUE);
								else
									clearUserContext(info, FALSE, FALSE);
							}

							if(info->userTchChannel.txSLotNum)
								clearUserContext(info, TRUE, TRUE);

							return;
						}
					}
#endif /* FEA_VOICE_CALL_TO_TARGET */
				}
#ifdef FEA_VOICE_CALL_TO_TARGET
				if(info->userPrevState == TCH_ALLOCATED) 	//If ASS_CMP is not received
				{
					if(targetVoiceCallCntxt.isOnGoingCall)
					{
						if((targetVoiceCallCntxt.moTsNum != 0xFF && (targetVoiceCallCntxt.moTsNum == info->userTchChannel.txSLotNum)) ||\
								(targetVoiceCallCntxt.moTsNum != 0xFF && (targetVoiceCallCntxt.mtTsNum == info->userTchChannel.txSLotNum)))
						{
							info->userPrevState = info->userState;
							info->userState = DISC_SENT;
                            pushLayer3ReqToTxDataQ(info , disconnect, sapi);
							logPrint(LOG_DEBUG,"User = %p : Pushing DISC to TCH User", info);

							checkAndResetCallCtx(info);
						}
					}
				}
#endif /* FEA_VOICE_CALL_TO_TARGET */

				if(blackUserInfo != NULL)
					blackUserInfo->isInConnectedState = FALSE;

				if(info->userLogicalChannel.txSLotNum ||
						isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
				{
					if(!(info->userTchChannel.txSLotNum))  //Delete User as well
						clearUserContext(info, FALSE, TRUE);
					else
						clearUserContext(info, FALSE, FALSE);
				}

				if(info->userTchChannel.txSLotNum)
					clearUserContext(info, TRUE, TRUE);

			}
		}
		else if (info->userState == RRLP_GPS_ASSIST_DATA_SENT)
		{
			/* Send RRLP GPS Assistance Data */
			info->rrlpGpsAssistCount = 0;
			pushLayer3ReqToTxDataQ(info , &rrlpGpsAssistData[info->rrlpGpsAssistSegment][info->rrlpGpsAssistCount++][0], sapi);
			logPrint(LOG_DEBUG, "User = %p : RRLP - Re-sending rrlpGpsAssistData[%d][%d], User State = %s \n" , info, info->rrlpGpsAssistSegment,(info->rrlpGpsAssistCount-1), logGetUserStateString(info->userState));

			info->retransmissionCountForL3Msg = 0;
		}
		else if (info->userState == LAU_REQ_RECEIVED) // Waiting for GPRS Suspension Req
		{
			pushLayer3ReqToTxDataQ(info , imsiIdentityReq, sapi);
			logPrint(LOG_DEBUG , "User = %p : Sending first time imsiIdentityReq after expiry of waiting for GPRS suspension\n" , info);
			info->retransmissionCountForL3Msg = 0;
		}
		else if(info->userState == CM_SERVICE_REQ_RECEIVED)// Waiting for GPRS Suspension Req
		{
			if(info->userBlacklisted == TRUE)
			{
				//Send Cipher Mode Command
				pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
				logPrint(LOG_DEBUG , "User = %p : Sending first time cipheringModeCommand after expiry of waiting for GPRS suspension\n" , info);
				info->retransmissionCountForL3Msg = 0;
			}
			else
			{
				pushLayer3ReqToTxDataQ(info , tmsiIdentityReq, sapi);
				logPrint(LOG_DEBUG , "User = %p : Sending first time tmsiIdentityReq after expiry of waiting for GPRS suspension\n" , info);
				info->retransmissionCountForL3Msg = 0;
			}
		}
		else if (info->userState == PAGING_RESP_RECEIVED) // Waiting for GPRS Suspension Req
		{
			if(info->userBlacklisted == TRUE)
			{
				blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

				if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RELEASE) == SET_TRIGGER_FOR_RELEASE))
				{
					/* Send TMSI Reallocation command */
					info->retransmissionCountForL3Msg = 0;
					pushLayer3ReqToTxDataQ(info , tmsiReallocationCmd, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending TMSI Reallocation command\n" , info);
				}

				else if(  blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_REDIRECTION) == SET_TRIGGER_FOR_REDIRECTION) )
				{
					/* Send Channel Release filling redirect info */
					sendChannelReleaseWithRedirection(info, &blackUserInfo->redirectInfo, SAPI_SDCCH);
				}

#ifdef FEA_SILENT_CALL
				else if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL))
				{

					// Send Silent Call allocated resources Indication to client.
					sendSilentCallResourcesIndOverSocket(info, FXL_SDCCH_SILENT_CALL);

					info->userState = SDCCH_SILENT_CALL_IN_PROGRESS;
					//Sending Classmark Enquiry to keep some active transaction during silent call
					pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
					logPrint(LOG_DEBUG , "User = %p : Sending first time classmarkEnquiry after expiry of waiting for GPRS suspension\n" , info);
					info->retransmissionCountForL3Msg = 0;
				}
#endif

#ifdef FEA_MT_SMS
				else if(blackUserInfo != NULL && (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_INDIVIDUAL_SMS) == SET_TRIGGER_FOR_INDIVIDUAL_SMS) || \
							((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BROADCAST_SMS) == SET_TRIGGER_FOR_BROADCAST_SMS)))
				{
					//Send Cipher Mode Command
					pushLayer3ReqToTxDataQ(info , cipheringModeCommand, sapi);
					logPrint(LOG_DEBUG , "User = %p : Sending first time cipheringModeCommand after expiry of waiting for GPRS suspension\n" , info);
					info->retransmissionCountForL3Msg = 0;
				}
#endif
				else if ( blackUserInfo != NULL &&
						(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) == SET_TRIGGER_FOR_RSSI_GPS_IND_CONTINUOUS) ||
						 ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) == SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) ) )
				{
					//Send LCS Positioning Request
					info->retransmissionCountForL3Msg = 0;
					pushLayer3ReqToTxDataQ(info , lcsPosReq, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending first time lcsPosReq after expiry of waiting for GPRS suspension\n" , info);
				}
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
				else if(blackUserInfo != NULL && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK) == SET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK))
				{
					blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers & RESET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK;
					//Send Channel Release
					info->retransmissionCountForL3Msg = 0;
                    pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					logPrint(LOG_DEBUG, "blackUserInfo = %p, IMSI = %s : Paging validity check succeeded sending channelRelease\n" , blackUserInfo, blackUserInfo->userImsi_str);
				}
#endif
				else
				{
					//Send Channel Release
					info->retransmissionCountForL3Msg = 0;
					pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending first time channelRelease after expiry of waiting for GPRS suspension\n" , info);
				}

			}
			else
			{
				if(info->userTmsi[0] != 0 )  /* TMSI already received */
				{
					pushLayer3ReqToTxDataQ(info , imsiIdentityReq, sapi);
					logPrint(LOG_DEBUG , "User = %p : Sending first time imsiIdentityReq after expiry of waiting for GPRS suspension\n" , info);
					info->retransmissionCountForL3Msg = 0;
				}
				else
				{
					pushLayer3ReqToTxDataQ(info , tmsiIdentityReq, sapi);
					logPrint(LOG_DEBUG , "User = %p : Sending first time tmsiIdentityReq after expiry of waiting for GPRS suspension\n" , info);
					info->retransmissionCountForL3Msg = 0;
				}
			}
		}
		else if (info->userState == IMSI_RECEIVED) // Waiting for GPRS Suspension Req
		{
			pushLayer3ReqToTxDataQ(info , classmarkEnquiry, sapi);
			logPrint(LOG_DEBUG , "User = %p : Sending first time classmarkEnquiry after expiry of waiting for GPRS suspension\n" ,info);
			info->retransmissionCountForL3Msg = 0;
		}
#ifdef FEA_SILENT_CALL
		else if (info->userState == TCH_ALLOCATED)
		{
			preparePushAssgnCmdToTxDataQ(info);
			info->retransmissionCountForL3Msg = 0;
			logPrint(LOG_DEBUG,"User = %p : Sending assgnCmd after expiry of waiting for TCH allocation\n" , info);
		}
		else if (info->userState == WAITING_FOR_SABM_ON_FACCH)
		{
            tOCT_UINT8 sapi = SAPI_IDLE;
            if(info->userTchChannel.txSLotNum)
            {
                if(isTimeSlotTypeSupportsTCHF(info->userTchChannel.txSLotNum))
                  sapi = SAPI_TCHF;
                else if(isTimeSlotTypeSupportsTCHH(info->userTchChannel.txSLotNum))
                  sapi = SAPI_TCHH;
                else
                {}
            }
            else if(isTimeSlotTypeSupportsSDCCH(info->userLogicalChannel.txSLotNum))
              sapi = SAPI_SDCCH;
            else
            {}
			if(resendLayer3MessageWaitingForL2Ack(info, sapi) == FALSE)
			{
				blackUserInfo = blacklistUserFindUsingIdentity((tOCT_UINT8*)(info->userImsi) , TRUE, FALSE);
				if(blackUserInfo != NULL)
					blackUserInfo->isInConnectedState = FALSE;

				if(info->userLogicalChannel.txSLotNum ||
						isTimeSlotTypeSupportsCombinedSDCCH(info->userLogicalChannel.txSLotNum))
				{
					if(!(info->userTchChannel.txSLotNum))  //Delete User as well
						clearUserContext(info, FALSE, TRUE);
					else
						clearUserContext(info, FALSE, FALSE);
				}

				if(info->userTchChannel.txSLotNum)
					clearUserContext(info, TRUE, TRUE);
			}
		}
#endif /* FEA_SILENT_CALL */

		/*Commented since this section is for both FEA_PRIV_CALL and FEA_ALERT, and none will hit this section if flags are not #def*/
		else if(info->userState == WAITING_TO_SEND_SETUP)
		{
			blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

			/* send Setup Message */
			if (blackUserInfo != NULL && info->userPrevState == PAGING_RESP_RECEIVED)		// send SETUP message
			{
				logPrint(LOG_DEBUG, "Trigger check: Curr val 0x%x\n",blackUserInfo->bitMaskForTriggers);
				info->retransmissionCountForL3Msg = 0;
				if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING)
				{
#ifdef FEA_ALERT
					tOCT_UINT8 callingBcd_length, *tmpPtr = NULL;
					tOCT_UINT8 tmpSetUpAlert[GSM_MACBLOCK_LEN] = {0};

					memcpy(tmpSetUpAlert, setUpAlert, GSM_MACBLOCK_LEN);

					tmpPtr = &tmpSetUpAlert[6];
					if(blackUserInfo->alertIsdn_str != NULL)
					{
						logPrint(LOG_DEBUG, "MSISDN is %s\n",blackUserInfo->alertIsdn_str);
						callingBcd_length = create_address(SMS_SMSC_ADDRESS, TOA_TON_INTERNATIONAL | TOA_NPI_ISDN, ( tOCT_UINT8* )blackUserInfo->alertIsdn_str, &tmpPtr);
					}
					else
					{
						callingBcd_length = create_address(ISDN_ADDRESS , TOA_TON_UNKNOWN | TOA_NPI_UNKNOWN, ( tOCT_UINT8* )blackUserInfo->alertIsdn_str, &tmpPtr);
					}
					tmpSetUpAlert[0] = (((callingBcd_length + 5) << 2) | 0x01);  // L2 Length

					pushLayer3ReqToTxDataQ(info , tmpSetUpAlert, sapi);
					logPrint(LOG_DEBUG, "User = %p : Sending SETUP for Alerting, User State = %s \n" , info, logGetUserStateString(info->userState));
#endif
				}
#ifdef FEA_VOICE_CALL_TO_TARGET
				else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL)
				{
					userInfo* moInfo = NULL;
					logicalChannelIdentity ch_id;
					ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
					ch_id.subChNum  = targetVoiceCallCntxt.moSubChan;

					if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum > 0)) //&& (ch_id.subChNum < MAX_SUBCHAN_TIMESLOT))
					{
						moInfo = userFindUsingLogicalChannel(&ch_id);
					}
					if((targetVoiceCallCntxt.moTsNum == 0xFF) || (moInfo == NULL))
					{
						logPrint(LOG_DEBUG, "User = %p : MO already Disconnected Sending channelRelease to MT, User State = %s", info, logGetUserStateString(info->userState));
						info->retransmissionCountForL3Msg = 0;
                        pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
					}
					else
					{
						tOCT_UINT8 callingBcd_length, *tmpPtr = NULL;
						tOCT_UINT8 tmpSetUp[GSM_MACBLOCK_LEN] = {0};

						memcpy(tmpSetUp, setUp, GSM_MACBLOCK_LEN);

						tmpPtr = &tmpSetUp[7];
						if(targetVoiceCallCntxt.moMsIsdnStr != NULL)
						{
							logPrint(LOG_DEBUG, "MO-MSISDN for Target Voice Call is %s\n",targetVoiceCallCntxt.moMsIsdnStr);
							callingBcd_length = create_address(SMS_SMSC_ADDRESS, TOA_TON_INTERNATIONAL | TOA_NPI_ISDN, ( tOCT_UINT8* )targetVoiceCallCntxt.moMsIsdnStr, &tmpPtr);
						}
						else
						{
							callingBcd_length = create_address(ISDN_ADDRESS , TOA_TON_UNKNOWN | TOA_NPI_UNKNOWN, ( tOCT_UINT8* )targetVoiceCallCntxt.moMsIsdnStr, &tmpPtr);
						}
						tmpSetUp[0] = (((callingBcd_length + 9) << 2) | 0x01);  // L2 Length

                        pushLayer3ReqToTxDataQ(info , tmpSetUp, sapi);

						logPrint(LOG_DEBUG, "User = %p : Sending SETUP, User State = %s \n" , info, logGetUserStateString(info->userState));
					}
				}
#endif /* FEA_VOICE_CALL_TO_TARGET */
				else
				{}
			}
		}

	}
	return;
}

void periodicTimerexpiry(tcbTimer_t *tmr , void *infoPtr)
{
	blackListedUserInfo *blackUserInfo = (blackListedUserInfo*)infoPtr;

	if(blackUserInfo == NULL )
		return;

	blackUserInfo->isActive = FALSE;
	// Set flag which check for Inactive BL Users here
	pthread_mutex_lock(&mutexBlacklistUserQ);
	checkForInactive2gBLUsers = TRUE;
	pthread_mutex_unlock(&mutexBlacklistUserQ);
	logPrint(LOG_DEBUG , "BlackList User(%p) IMSI = %s, timer expired for periodic location update\n ", blackUserInfo, blackUserInfo->userImsi_str);
}

/* This function will be called out from Main thread */
void blacklistUserInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr)
{
	blackListedUserInfo *blackUserInfo = (blackListedUserInfo*)infoPtr;

	if(    (blackUserInfo != NULL )
			&& (blackUserInfo->triggerPagingReq == TRUE)
			&& (blackUserInfo->isInConnectedState == FALSE))
	{
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
		if(blackUserInfo->pagingInactivityCounter == BL_PAGING_INACTIVITY_TIMEOUT_CTR)
		{
			blackUserInfo->pagingInactivityCounter = 0;

			logPrint(LOG_DEBUG , "BlackList User(%p) IMSI = %s, State = Trying to Connect: User out of reach\n ", blackUserInfo, blackUserInfo->userImsi_str);
			blackUserInfo->isActive = FALSE;

			// Set flag which check for Inactive BL Users here
			pthread_mutex_lock(&mutexBlacklistUserQ);
			checkForInactive2gBLUsers = TRUE;
			pthread_mutex_unlock(&mutexBlacklistUserQ);
		}
#endif
		pushPagingReqToPageQ(blackUserInfo);
	}
	return;
}

#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
void blacklistUserValidityTimerCbFunction(tcbTimer_t *tmr , void *infoPtr)
{
	blackListedUserInfo *blackUserInfo = NULL;

	pthread_mutex_lock(&mutexBlacklistUserQ);
	listNode *current = headForBlacklistedUserQ;

	if( current != NULL )
	{
		logPrint(LOG_DEBUG , "Blacklist USERS Validity Timer Expired sending Paging Requests \n");

		while(current != NULL)
		{
			blackUserInfo = (blackListedUserInfo*)(current->msg);

			if((blackUserInfo != NULL) && (blackUserInfo->isInConnectedState == FALSE)) // If BL user is Idle
			{
				if(blackUserInfo->pagingInactivityCounter == BL_PAGING_INACTIVITY_TIMEOUT_CTR)
				{
					blackUserInfo->pagingInactivityCounter = 0;

					logPrint(LOG_DEBUG , "BlackList User(%p) IMSI = %s, State = Idle: User out of reach\n ", blackUserInfo, blackUserInfo->userImsi_str);
					blackUserInfo->isActive = FALSE;
					/* Set flag which check for Inactive BL Users here */
					checkForInactive2gBLUsers = TRUE;
				}

				blackUserInfo->bitMaskForTriggers = blackUserInfo->bitMaskForTriggers | SET_TRIGGER_FOR_BL_PAGING_VALIDITY_CHECK;

				pushPagingReqToPageQ(blackUserInfo);
			}

			current = current->next;
		}
	}
	pthread_mutex_unlock(&mutexBlacklistUserQ);
	return;
}
#endif

// This function is used to get the imsiMod1000 value.
tOCT_UINT16 imsiMod1000Get( tOCT_UINT8* imsi )
{
	tOCT_UINT16 imsiMod1000;
	tOCT_UINT8  len = imsi[0] + 1;

	/* Even number of digits? */
	if ( ( imsi[1] & 0x08 ) == 0 )
	{
		imsiMod1000 =
			( imsi[len - 1] & 0x0F ) +
			((imsi[len - 2] & 0xF0 ) >> 4 ) * 10 +
			( imsi[len - 2] & 0x0F ) * 100;
	}
	else
	{
		imsiMod1000 =
			( (imsi[len - 1] & 0xF0 ) >> 4 ) +
			(  imsi[len - 1] & 0x0F ) * 10 +
			( (imsi[len - 2] & 0xF0 ) >> 4 ) * 100;
	}

	return ( imsiMod1000 );
}

/*
 * This function calculates the paging block for which the UE has to be paged.
 *
 * Number of paging blocks 'available' in a 51 frame TDMA multi-frame on one
 * CCCH x BS_PA_MFRMS, see GSM 05.02/6.5.2/vers. 3.4.0
 *
 * see GSM 05.02/6.5.2/vers. 3.4.0
 */
void pagingBlockCalculate(blackListedUserInfo* info)
{
	tOCT_UINT8 bsCcChans, bsPaMfrms, bsAgBlksRes, ccchConf ;
	tOCT_UINT16 n, t, pagingGroup, imsiMod1000;
	struct ctrl_chan_desc controlChannelDesc;

	set_ccch_config(&controlChannelDesc, trx_g);

	ccchConf    = controlChannelDesc.ccch_conf;
	bsPaMfrms   = trx_g->bts.pagingPeriodicity;
	bsAgBlksRes = trx_g->bts.blockReservedForAgch;

	if( ccchConf == CCCH_CONF_1_NC )
	{
		bsCcChans = 1;
		n = ( MAX_PAGING_BLOCKS_IN_51_FRAME - bsAgBlksRes ) * bsPaMfrms;
	}
	else
	{
		if( ccchConf == CCCH_CONF_1_C )
			bsCcChans = 1;
		else if( ccchConf == CCCH_CONF_2_NC )
			bsCcChans = 2;
		else if( ccchConf == CCCH_CONF_3_NC )
			bsCcChans = 3;
		else
			bsCcChans = 4;

		if( bsAgBlksRes > 1 )
		{
			/* Number of paging blocks being available = 1
			*/
			n = bsPaMfrms;
		}
		else
		{
			/* Number of paging blocks being available = 2 or 3
			*/
			n = ( MAX_COMBINED_PAGE_BLOCKS_IN_51 - bsAgBlksRes ) * bsPaMfrms;
		}
	}

	imsiMod1000 = imsiMod1000Get( info->userImsi );
	t = ( tOCT_UINT16 ) imsiMod1000 % ( tOCT_UINT16 ) ( bsCcChans * n );

	pagingGroup = ( tOCT_UINT16 ) ( t % n );

	/* Paging block index refers to number of paging blocks, inside
	 * the 51-multiframe that are counted (after ag blocks) for
	 * defining the specific 'own' paging block.
	 */

	info->pagingBlockIndex = ( tOCT_UINT8 ) ( pagingGroup % ( ( tOCT_UINT16 ) ( n / bsPaMfrms ) ) );
	info->pagingMultiFrame = ( tOCT_UINT8 ) ( pagingGroup / ( ( tOCT_UINT16 ) ( n / bsPaMfrms ) ) );
}

unsigned int addIMSIInGsmLatchedUeList (userInfo *info)
{
	unsigned int found = 0;
	char imsiValue[MAX_IMSI_LENGTH_2G + 1];
	GsmLatchedUeDetails *pCurUe = NULL;
	GsmLatchedUeDetails *pTmpUe = NULL;
	GsmLatchedUeDetails *pNewUe = NULL;

	strncpy (imsiValue, info->userImsi_str,MAX_IMSI_LENGTH_2G);
	imsiValue[MAX_IMSI_LENGTH_2G] = '\0';

	if (NULL == pGsmLatchedUeDetails)
	{
		pGsmLatchedUeDetails = (GsmLatchedUeDetails *)malloc(sizeof(GsmLatchedUeDetails));
		strncpy (pGsmLatchedUeDetails->imsi, imsiValue, MAX_IMSI_LENGTH_2G);
		pGsmLatchedUeDetails->next = NULL;
	}
	else
	{
		pCurUe = pGsmLatchedUeDetails;

		/* Check that UE is already latched or not */
		while (NULL != pCurUe)
		{
			if (0 == strncmp(pCurUe->imsi, imsiValue, MAX_IMSI_LENGTH_2G))
			{
				found = 1;
				break;
			}

			if (NULL == pCurUe->next)
			{
				pTmpUe = pCurUe;
			}

			pCurUe = pCurUe->next;
		}

		/* If not found, add it in last node */
		if (0 == found)
		{
			pNewUe = (GsmLatchedUeDetails *)malloc(sizeof(GsmLatchedUeDetails));
			strncpy (pNewUe->imsi, imsiValue, MAX_IMSI_LENGTH_2G);
			pNewUe->next = NULL;
			pTmpUe->next = pNewUe;
		}
	}

	return (found);
}


unsigned int getNumOfGsmUeLatched (void)
{
	unsigned int ueCount = 0;

	GsmLatchedUeDetails *pCurUe = pGsmLatchedUeDetails;

	while (NULL != pCurUe)
	{
		ueCount++;
		pCurUe = pCurUe->next;
	}

	return (ueCount);
}


int findbandnumber(unsigned int band)
{
	switch (band)
	{
		case 0:
			return 31;
			break;

		case 1:
			return 5;
			break;

		case 2:
		case 5:
			return 8;
			break;

		case 3:
			return 3;
			break;

		case 4:
			return 2;
			break;

		default:
			return 0;
			break;
	}
}

void sendRegistrationAttemptedIndOverSocket(userInfo *info)
{


	fxL2gRegistrationAttemptedInd *ind = (fxL2gRegistrationAttemptedInd *) socketMsgBuf;
	memset(ind, 0, sizeof(fxL2gRegistrationAttemptedInd));

	if(info->userBlacklisted == TRUE)
	{
		ind->listType = FXL_BLACKUSERSLIST;
		//Add this user to blacklisted list
		userStoreBlackListedInfo(info);
	}
	else
	{
		ind->listType = FXL_WHITEUSERSLIST;


	}

	ind->hdr.msgLength = sizeof(fxL2gRegistrationAttemptedInd);
	ind->hdr.msgType = FXL_2G_REGISTRATION_ATTEMPTED_IND;
	ind->hdr.rat = FXL_RAT_2G;
	// Send these values over socket interface to outside world
	memcpy(ind->imsiStr , info->userImsi_str , SIZE_OF_IDENTITY_STR);
	memcpy(ind->imeiStr , info->userImei_str , SIZE_OF_IDENTITY_STR);
	memcpy(ind->tmsi , info->userOldTmsi , SIZE_OF_TMSI_IDENTITY);

    if(  (info->initialMeasReport.dlRxLevFull >= 0)
      && (info->initialMeasReport.dlRxLevFull <= 63))
    {
        ind->rssidBm = (float)(info->initialMeasReport.dlRxLevFull - 111);
    }
    else
    {
        ind->rssidBm = -60;
    }
	ind->snrdB   = info->ulSnrAvg;

	ind->imeiSv = info->userImeiSv;
	memcpy(&ind->msClassmark, &info->msClassmark, sizeof(fxL2gMsClassmark));
	ind->last_lac = info->last_lac;
	ind->timingAdvance = info->initialMeasReport.timingAdvance;

	writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxL2gRegistrationAttemptedInd));
	return;
}

void sendRssiGpsIndOverSocket(userInfo *info, fxlUePositioningInfo* gpsInfo, fxlUePositioningError gpsResult)
{
	fxL2gGetRssiGpsCoordinatesInd *ind = (fxL2gGetRssiGpsCoordinatesInd *) socketMsgBuf;
	memset(ind, 0, sizeof(fxL2gGetRssiGpsCoordinatesInd));

	ind->hdr.msgLength = sizeof(fxL2gGetRssiGpsCoordinatesInd);
	ind->hdr.msgType = FXL_2G_GET_RSSI_GPS_COORDINATES_IND;
	ind->hdr.rat = FXL_RAT_2G;
	// Send these values over socket interface to outside world
    if(  (info->measReport.dlRxLevFull >= 0)
      && (info->measReport.dlRxLevFull <= 63))
    {
        ind->rssi = (float)(info->measReport.dlRxLevFull - 111);
    }
    else
    {
        ind->rssi = -60;
    }
    ind->errorCode = gpsResult;
    if(ind->errorCode == FXL_UE_POS_ERR_NONE)
	memcpy(&ind->uePosInfo, gpsInfo, sizeof(fxlUePositioningInfo));
	memcpy(ind->imsiStr , info->userImsi_str , SIZE_OF_IDENTITY_STR);
	writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxL2gGetRssiGpsCoordinatesInd));

	return;
}

void sendMoCallAttemptedIndOverSocket(userInfo *info, char* msisdn)
{
	fxL2gCallAttemptedInd *ind = (fxL2gCallAttemptedInd *) socketMsgBuf;
	memset(ind, 0, sizeof(fxL2gCallAttemptedInd));
	ind->hdr.msgLength = sizeof(fxL2gCallAttemptedInd);
	ind->hdr.msgType = FXL_2G_MO_CALL_ATTEMPTED_IND;
	ind->hdr.rat = FXL_RAT_2G;
	// Send these values over socket interface to outside world
	memcpy(ind->imsiStr , info->userImsi_str , SIZE_OF_IDENTITY_STR);
	memcpy(ind->msisdnOfDialedNoStr , msisdn , MAX_IDENTITY_LENGTH_STR);
	ind->blockedCallCounter = info->blockedMoCallsCounter;
	writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxL2gCallAttemptedInd));

	return;
}

#ifdef FEA_SILENT_CALL
void sendSilentCallMeasIndOverSocket(userInfo *info)
{
	fxL2gSilentCallMeasInd *ind = (fxL2gSilentCallMeasInd *) socketMsgBuf;
	memset(ind, 0, sizeof(fxL2gSilentCallMeasInd));
	ind->hdr.msgLength = sizeof(fxL2gSilentCallMeasInd);
	ind->hdr.msgType = FXL_2G_SILENT_CALL_MEAS_IND;
	ind->hdr.rat = FXL_RAT_2G;

    if(  (info->measReport.dlRxLevFull >= 0)
      && (info->measReport.dlRxLevFull <= 63))
    {
        ind->rssidBm = (float)(info->measReport.dlRxLevFull - 111);
    }
    else
    {
        ind->rssidBm = -60;
    }
	ind->snrdB   = info->ulSnrAvg;
	memcpy(ind->imsiStr , info->userImsi_str , SIZE_OF_IDENTITY_STR);
	memcpy(&ind->measReport, &info->measReport, sizeof(fxLGsmMeasReport));
	writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxL2gSilentCallMeasInd));

	return;
}

void sendSilentCallResourcesIndOverSocket(userInfo *info, fxLSilentCallPurpose purpose)
{
	fxL2gSilentCallResourcesInd *ind = (fxL2gSilentCallResourcesInd *) socketMsgBuf;
	memset(ind, 0, sizeof(fxL2gSilentCallResourcesInd));
	ind->hdr.msgLength = sizeof(fxL2gSilentCallResourcesInd);
	ind->hdr.msgType = FXL_2G_SILENT_CALL_RESOURCES_IND;
	ind->hdr.rat = FXL_RAT_2G;
	// Send these values over socket interface to outside world
	memcpy(ind->imsiStr , info->userImsi_str , SIZE_OF_IDENTITY_STR);

	ind->purpose = purpose;
	ind->tsc = trx_g->bts.tsc;
	if(purpose == FXL_SDCCH_SILENT_CALL)
	{
		ind->timeSlot = info->userLogicalChannel.txSLotNum;
		ind->subChannel = info->userLogicalChannel.subChNum;
	}
	else
	{
		ind->timeSlot = info->userTchChannel.txSLotNum;
		ind->subChannel = info->userTchChannel.subChNum;
	}
	writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxL2gSilentCallResourcesInd));

	return;
}
#endif /* FEA_SILENT_CALL */

#ifdef FXL_BL_UE_POWER_OFF
void send2gBlUePowerOffInd(blackListedUserInfo *blackUserInfo, fxlBlUeDeatchCause cause)
{
	fxLBlUePowerOffInd *ind = (fxLBlUePowerOffInd *)socketMsgBuf;
	memset(ind, 0, sizeof(fxLBlUePowerOffInd));

	ind->hdr.msgLength = sizeof(fxLBlUePowerOffInd);
	ind->hdr.msgType = FXL_BL_UE_POWER_OFF_IND;
	ind->hdr.rat = FXL_RAT_2G;

	ind->detachCause = cause;
	memcpy(ind->imsiStr , blackUserInfo->userImsi_str , SIZE_OF_IDENTITY_STR);

	// Send these values over socket interface to outside world
	writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxLBlUePowerOffInd));

	return;
}
#endif

void sendBlUserDetachedIndOverSocket(blackListedUserInfo *blackUserInfo)
{
	fxL2gBlUserDetachedInd *ind = (fxL2gBlUserDetachedInd *) socketMsgBuf;
	memset(ind, 0, sizeof(fxL2gBlUserDetachedInd));
	ind->hdr.msgLength = sizeof(fxL2gBlUserDetachedInd);
	ind->hdr.msgType = FXL_2G_BL_USER_DETACHED_IND;
	ind->hdr.rat = FXL_RAT_2G;

	// Send these values over socket interface to outside world
	memcpy(ind->imsiStr , blackUserInfo->userImsi_str , SIZE_OF_IDENTITY_STR);

	writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxL2gBlUserDetachedInd));

	return;
}

tOCT_UINT8 searchIdDbForRecvdIdentity(userInfo *info, tOCT_UINT8 isImsi)
{
	tOCT_UINT8 *sharedMemPtr = getAccessToIdList();
	configUeIdList.configId = (IdentityConfigStr *) (sharedMemPtr + CONFIG_DATA_SIZE);
	tOCT_UINT16 i;
	tOCT_UINT8 retVal = FALSE;

	for(i = 0; i < configUeIdList.numbOfIds; i++)
	{
		if(isImsi == TRUE) // IMSI List
		{
			if (((configUeIdList.configId + i)->idType == IMSI) && \
					(memcmp((configUeIdList.configId + i)->identity, info->userImsi_str, MAX_IDENTITY_LENGTH_STR) == 0 ))
			{
				retVal = TRUE;
				if((configUeIdList.configId + i)->listType == BLACKLIST )
				{
					info->userBlacklisted = TRUE;

					if(info->cmServiceReqTypeRcvd == 0x01)
						info->blockedMoCallsCounter++;

					logPrint(LOG_DEBUG, "User = %p : Received IMSI is in BLACKLIST\n" , info);
					logPrint(LOG_DEBUG, "User = %p : BLACKLISTING IMSI [%s]\n",info, info->userImsi_str);
					break;
				}
				else if((configUeIdList.configId + i)->listType == WHITELIST )
				{
					info->userBlacklisted = FALSE;
#ifdef FEA_REJECT_CAUSE_CONTROL
					if((configUeIdList.configId + i)->rejectCauseIfWhitelist != 0 )
						info->wlRejectCause = (configUeIdList.configId + i)->rejectCauseIfWhitelist;
					else
						info->wlRejectCause = gsmDefaultWLRejectCause;
#endif

					//logPrint(LOG_DEBUG, "User = %p : Received IMSI is in WHITELIST\n" , info);
					logPrint(LOG_DEBUG, "User = %p : WHITELISTING IMSI [%s] with REJ-CAUSE [%d]\n", info, info->userImsi_str, info->wlRejectCause);
					break;
				}
			}
		}
		else // IMEI List
		{
			if (((configUeIdList.configId + i)->idType == IMEI) && \
					(memcmp((configUeIdList.configId + i)->identity, info->userImei_str, MAX_IDENTITY_LENGTH_STR) == 0 ))
			{
				retVal = TRUE;
				if((configUeIdList.configId + i)->listType == BLACKLIST )
				{
					info->userBlacklisted = TRUE;

					logPrint(LOG_DEBUG, "User = %p : Received IMEI is in BLACKLIST\n" , info);
					logPrint(LOG_DEBUG, "User = %p : BLACKLISTING IMEI [%s]\n",info, info->userImei_str);
					break;
				}
				else if((configUeIdList.configId + i)->listType == WHITELIST )
				{
					info->userBlacklisted = FALSE;
#ifdef FEA_REJECT_CAUSE_CONTROL
					if((configUeIdList.configId + i)->rejectCauseIfWhitelist != 0 )
						info->wlRejectCause = (configUeIdList.configId + i)->rejectCauseIfWhitelist;
					else
						info->wlRejectCause = gsmDefaultWLRejectCause;
#endif

					logPrint(LOG_DEBUG, "User = %p : Received IMEI is in WHITELIST\n", info);
					logPrint(LOG_DEBUG, "User = %p : WHITELISTING IMEI [%s] with REJ-CAUSE [%d]\n", info, info->userImei_str, info->wlRejectCause);
					break;
				}
			}
		}
	}

	releaseAccessToIdList(sharedMemPtr);
	return retVal;
}

void changeBLtoWLInConfigDb(blackListedUserInfo* blackUserInfo)
{
	tOCT_UINT8 *sharedMem = getAccessToIdList();
	tOCT_UINT8 *initialAddress = sharedMem;
	configUeIdList.configId = (IdentityConfigStr *) (sharedMem + CONFIG_DATA_SIZE);
	tOCT_UINT16 i;
	tOCT_UINT8 foundInConfigDb = FALSE;

	/* Modify the IMSI configuration in configDB from BL to WL */
	for(i = 0; i < configUeIdList.numbOfIds; i++)
	{
		if (((configUeIdList.configId + i)->idType == IMSI) && \
				(memcmp((configUeIdList.configId + i)->identity, blackUserInfo->userImsi_str, MAX_IDENTITY_LENGTH_STR) == 0 ))
		{
			if((configUeIdList.configId + i)->listType == BLACKLIST )
			{
				(configUeIdList.configId + i)->listType = WHITELIST;
				(configUeIdList.configId + i)->rejectCauseIfWhitelist = blackUserInfo->wlRejectCause;
				logPrint(LOG_DEBUG, "User = %p : Changing IMSI(%s) configuration to WHITELIST, REJ-CAUSE(%d)",
						blackUserInfo,
						blackUserInfo->userImsi_str,
						(configUeIdList.configId + i)->rejectCauseIfWhitelist);
				foundInConfigDb = TRUE;
				break;
			}
		}
		else if (((configUeIdList.configId + i)->idType == IMEI) && \
				(memcmp((configUeIdList.configId + i)->identity, blackUserInfo->userImei_str, MAX_IDENTITY_LENGTH_STR) == 0 ))
		{
			if((configUeIdList.configId + i)->listType == BLACKLIST )
			{
				(configUeIdList.configId + i)->listType = WHITELIST;
				(configUeIdList.configId + i)->rejectCauseIfWhitelist = blackUserInfo->wlRejectCause;
				logPrint(LOG_DEBUG, "User = %p : Changing IMEI(%s) configuration to WHITELIST, REJ-CAUSE(%d)",
						blackUserInfo,
						blackUserInfo->userImei_str,
						(configUeIdList.configId + i)->rejectCauseIfWhitelist);
				foundInConfigDb = TRUE;
				break;
			}
		}
	}
	if(foundInConfigDb == FALSE)
	{
		/* IMSI/IMEI not found in Config DB(==> Default BL Config Case),
		 * Add the IMSI configuration as WHITELIST.
		 */

		if(configUeIdList.numbOfIds >= MAX_NO_OF_IDS)
		{
			logPrint(LOG_ERR, "ConfigDB is FULL!! Cannot Add IMSI(%s)", blackUserInfo->userImsi_str);
		}
		else
		{
			sharedMem = sharedMem + configUeIdList.numbOfIds*sizeof(IdentityConfigStr) + CONFIG_DATA_SIZE;
			configUeIdList.configId = (IdentityConfigStr *)(sharedMem);

			memcpy(configUeIdList.configId->identity, blackUserInfo->userImsi_str, SIZE_OF_IDENTITY_STR);
			configUeIdList.configId->idType                 = FXL_IDENTITY_IMSI;
			configUeIdList.configId->listType               = FXL_WHITEUSERSLIST;
			configUeIdList.configId->rejectCauseIfWhitelist = blackUserInfo->wlRejectCause;

			configUeIdList.numbOfIds += 1;

			logPrint(LOG_DEBUG, "User = %p : Configured IMSI(%s) as WHITELIST, REJ-CAUSE(%d)",
					blackUserInfo,
					blackUserInfo->userImsi_str,
					configUeIdList.configId->rejectCauseIfWhitelist);
		}
	}

	releaseAccessToIdList(initialAddress);
}

ConfigList* getConfigUeIdListPtr()
{
	ConfigList *configDataPtr = NULL;
	configDataPtr = &configUeIdList;

	return configDataPtr;
}

void cleanPagingQ()
{
	tOCT_UINT8 i, j;
	for(i = 0; i < MAX_PAGING_PERIODICITY; i++)
	{
		for(j = 0; j < MAX_PAGING_BLOCKS_IN_51_FRAME; j++)
		{
			headForPagingReqQ[i][j] = NULL;
			tailForPagingReqQ[i][j] = NULL;
		}
	}
}

unsigned int getAllRegisteredUesInGsm(void)
{
	return noOfAttemptedRegistrationInGsm;
}

#if	defined (FEA_ALERT) || defined (FEA_VOICE_CALL_TO_TARGET)
void callConfRespHandler(userInfo* info, tOCT_UINT8 sapi)
{

#ifdef FEA_VOICE_CALL_TO_TARGET
	if((targetVoiceCallCntxt.isOnGoingCall) && (targetVoiceCallCntxt.moTsNum == 0xFF ))	//If MO gets cleared
	{
		info->userPrevState = info->userState;
		info->userState = DISC_SENT;
		logPrint(LOG_DEBUG,"User = %p : Pushing DISC to MT SDCCH ", info);
		pushLayer3ReqToTxDataQ(info , disconnect, sapi);
		return;
	}
#endif

	blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);

	if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING))
	{
		info->userPrevState= info->userState;
		info->userState = WAITING_FOR_ALERT;
		logPrint(LOG_DEBUG, "ALERTING feature \n");
		return;
	}
#ifdef FEA_VOICE_CALL_TO_TARGET
	else if((blackUserInfo != NULL) && ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TARGET_VOICE_CALL) == SET_TRIGGER_FOR_TARGET_VOICE_CALL))
	{
		// Allocate TCH channel for this user, SDCCH channel will be deallocated when TCH assignment is completed.
		if(allocateHalfTrafficChannel(&(info->userTchChannel)) == TRUE)
		{
			updateUserDb(info, &(info->userTchChannel));

			activateLogicalChannel(info->userTchChannel.txSLotNum , info->userTchChannel.subChNum);
			logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the TCH/H, FACCH/H and SACCH/H, TimeSlot = %d , SubChannel = %d\n" , info, info->userTchChannel.txSLotNum , info->userTchChannel.subChNum );

			info->userPrevState= info->userState;
			info->userState = TCH_ALLOCATED;
			preparePushAssgnCmdToTxDataQ(info);
			info->retransmissionCountForL3Msg = 0;
		}
		else if(allocateFullTrafficChannel(&(info->userTchChannel)) == TRUE)
		{
			// Update the user pointer in TCH channel as well
			updateUserDb(info, &(info->userTchChannel));

			activateLogicalChannel(info->userTchChannel.txSLotNum , info->userTchChannel.subChNum);
			logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the TCH/F, FACCH/F and SACCH/F, TimeSlot = %d , SubChannel = %d\n" , info, info->userTchChannel.txSLotNum , info->userTchChannel.subChNum );

			info->userPrevState= info->userState;
			info->userState = TCH_ALLOCATED;

			// Wait for 2 seconds before sending Assignment Command, to allow for any segmented CALL_CONF message to be handled.
			tOCT_UINT8 retVal = timerStart(&info->tmr , 2000 , 0 , &userInfoTimerCbFunction, info);
			assert(retVal == RC_TCB_OK);
		}
		else
		{
			logPrint(LOG_ERR , "Could not allocate TCH(MT) for Target Voice Call\n");

			logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
			info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;
            pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
			info->retransmissionCountForL3Msg = 0;
		}
	}
#endif /* FEA_VOICE_CALL_TO_TARGET */
	else
	{
		logPrint(LOG_DEBUG, "User = %p : Sending channelRelease, User State = %s \n" , info, logGetUserStateString(info->userState));
		info->userState = WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE;
        pushLayer3ReqToTxDataQ(info , channelRelease, sapi);
		info->retransmissionCountForL3Msg = 0;
	}
}

#ifdef FEA_VOICE_CALL_TO_TARGET
void mtAlertHandler(userInfo* info, tOCT_UINT8 sapi)
{
	info->userPrevState= info->userState;
	info->userState = WAITING_FOR_MT_CONNECT;

	if((targetVoiceCallCntxt.mtTsNum   == info->userTchChannel.txSLotNum) &&\
			(targetVoiceCallCntxt.mtSubChan == info->userTchChannel.subChNum))
	{
		/*Send alert to MO*/
		userInfo* moInfo = NULL;
		logicalChannelIdentity ch_id;
		ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
		ch_id.subChNum  = targetVoiceCallCntxt.moSubChan;

		if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum >= 0))
		{
			moInfo = userFindUsingLogicalChannel(&ch_id);
			if(moInfo != NULL)
			{
				moInfo->userPrevState= moInfo->userState;
				moInfo->userState = WAITING_FOR_MT_CONNECT;
				logPrint(LOG_DEBUG , "User = %p : Sending ALERT to MO User = %p \n" , info,moInfo);
                pushLayer3ReqToTxDataQ(moInfo , alert, sapi);
			}
			else
			{
				info->userPrevState = info->userState;
				info->userState = DISC_SENT;
				logPrint(LOG_DEBUG , "User = %p : MO user notfound/disconnected for this call, sending DISC to MT \n" , info);
				logPrint(LOG_DEBUG , "User = %p : Going to send DISC to MT, User State = %s \n" , info, logGetUserStateString(info->userState));
                pushLayer3ReqToTxDataQ(info , disconnect, sapi);
			}
		}
		else
		{
			info->userPrevState = info->userState;
			info->userState = DISC_SENT;
			logPrint(LOG_DEBUG , "User = %p : MO user notfound/disconnected for this call, sending DISC to MT \n" , info);
			logPrint(LOG_DEBUG , "User = %p : Going to send DISC to MT, User State = %s \n" , info, logGetUserStateString(info->userState));
            pushLayer3ReqToTxDataQ(info , disconnect, sapi);
		}
	}
}

void mtConnectHandler(userInfo* info, tOCT_UINT8 sapi)
{
	info->userPrevState= info->userState;
	info->userState = WAITING_FOR_CALL_EST;

	userInfo* moInfo = NULL;
	logicalChannelIdentity ch_id;
    ch_id.txSLotNum = 0XFF;
    ch_id.subChNum =  0xFF;
    if((targetVoiceCallCntxt.isOnGoingCall) && (targetVoiceCallCntxt.isCallConnected!=TRUE))
    {
	    ch_id.txSLotNum = targetVoiceCallCntxt.moTsNum;
	    ch_id.subChNum = targetVoiceCallCntxt.moSubChan;
    }

	if((ch_id.txSLotNum < MAX_TS)&&(ch_id.txSLotNum >= 0))
	{
		//Send connect to MO
		moInfo = userFindUsingLogicalChannel(&ch_id);
		if(moInfo != NULL)
		{
			moInfo->userPrevState= info->userState;
			moInfo->userState = WAITING_FOR_CALL_EST;

 			pushLayer3ReqToTxDataQ(moInfo , Connect, sapi);
			logPrint(LOG_DEBUG,"Sent Connect to MO_USER %p", moInfo);
		}
		else
		{
			logPrint(LOG_INFO,"User = %p : MO User notFound, sending DISC to MT",info);
			if(info->userTchChannel.txSLotNum)
              pushLayer3ReqToTxDataQ(info , disconnect, sapi);
			else
              pushLayer3ReqToTxDataQ(info , disconnect, sapi);
			return;
		}
	}
	else
	{
		logPrint(LOG_INFO,"User = %p : MO User notFound/disconnected for this call, sending DISC to MT",info);
		if(info->userTchChannel.txSLotNum)
		  pushLayer3ReqToTxDataQ(info , disconnect, sapi);
		else
          pushLayer3ReqToTxDataQ(info , disconnect, sapi);
		return;
	}

	// Send connect ack to MT
	logPrint(LOG_DEBUG,"Sent Connect_Ack to MT_USER");
	if(info->userTchChannel.txSLotNum)
      pushLayer3ReqToTxDataQ(info , conAck, sapi);
	else
      pushLayer3ReqToTxDataQ(info , conAck, sapi);
}
#endif /* FEA_VOICE_CALL_TO_TARGET */
#endif /* FEA_ALERT || FEA_VOICE_CALL_TO_TARGET*/


