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
* File Name   : lteMacIntfcHandler.c
 *
* Description : Lte Mac Interface Layer functions header
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------------
* 07/02/2015          				  Anand Kashikar			   Initial File Creation
*#############################################################################################
*/

#include <string.h>
#include <malloc.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <assert.h>
#include "lteMacIntfcHandler.h"
#include "logManager.h"
#include "linkedlist.h"
#include "lteUserManager.h"
#include "lteLayer1IfManager.h"
#include "lteMacEncDec.h"
#include "rawSocketApi.h"
#include "lteAsn1IntfcHandler.h"
#include "timerApi.h"
#include "lteL2Interface.h"
#include "lteRlcIntfcHandler.h"
#include "lteRrcIntfcHandler.h"
#include "lteRrcMain.h"

#define MAX_PAGING_PER_MESSAGE 20
lteMacPduStruct         mac_pdu;
queue rxRlcDataQ ;
uint16 ulRivArr[MAX_BANDWIDTH][MAX_NO_UPLINK_GRANTS] = {
														   { 6,11,6,6,11}, /*LTE_DL_BW_N6*/
														   { 15,75,15,15,75}, /*LTE_DL_BW_N15*/
														   { 25,225,100,25,225 }, /*LTE_DL_BW_N25*/
														   { 50,450,200,50,450 }, /*LTE_DL_BW_N50*/
														   { 75,675,300,75,675 }, /*LTE_DL_BW_N75*/
														   { 100,900,400,100,900} /*LTE_DL_BW_N100*/
													   };
uint16 dlRivArr[MAX_BANDWIDTH][MAX_NO_DOWNLINK_GRANTS] = {
														   { 6,6,6,12,12,0,6,6,6,6,6,6,6,0 }, /*LTE_DL_BW_N6*/
														   { 15,15,15,30,30,0,15,15,15,15,15,15,15,105 },
														   { 25,25,75,50,75,25,25,25,25,25,25,25,25,175 }, /*LTE_DL_BW_N25*/
														   { 50,50,150,100,150,50,50,50,50,50,50,50,50,350 }, /*LTE_DL_BW_N50*/
														   { 75,75,225,150,225,75,75,75,75,75,75,75,75,525 }, /*LTE_DL_BW_N75*/
														   { 100,100,300,200,300,100,100,100,100,100,100,100,100,700 } /*LTE_DL_BW_N100*/
														};
uint16 bwToPrb[MAX_BANDWIDTH] = {6,15,25,50,75,100};
lteL2InftMsg_t* pagingQ[LTE_MAX_USER_SUPPORTED] = {NULL} ;
listNode *headForLteMacDlSchedulerQ[LTE_MAX_SUB_FRAME_NUMBER] = {NULL};
listNode *tailForLteMacDlSchedulerQ[LTE_MAX_SUB_FRAME_NUMBER] = {NULL};
listNode *headForLteMacDlTxDataQ[LTE_MAX_SUB_FRAME_NUMBER] = {NULL};
listNode *tailForLteMacDlTxDataQ[LTE_MAX_SUB_FRAME_NUMBER] = {NULL};
listNode *headForLteMacUlSchedulerQ[LTE_MAX_SUB_FRAME_NUMBER] = {NULL};
listNode *tailForLteMacUlSchedulerQ[LTE_MAX_SUB_FRAME_NUMBER] = {NULL};
listNode *headForUlConfigReqQ = NULL;
listNode *tailForUlConfigReqQ = NULL;
listNode *headForDlConfigReqQ = NULL;
listNode *tailForDlConfigReqQ = NULL;
listNode *headForTxDataReqQ = NULL;
listNode *tailForTxDataReqQ = NULL;

extern volatile int exitLteApp;
extern uint8 lteTimerTickReceived;
extern eLteBw lteSelectedBandwidth;
extern uint8 lteTimerTickReceived;
extern uint8 lteRvArr[4];
extern lteRrcUeControlBlock lteUeControlBlock;
extern const uint16 ULDL[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER] ;
extern elteDupMode lteDuplxMode ;
uint8* buildTddUlDci0Req(tOCT_FAPI_L1_API_MSG * fapiMsg , uint16 sfNsf);
void checkAndPushTDDPagingReqToDlSchedulerQ(uint16 sfn , uint8 sbfn);
extern uint8  cce_map[LTE_MAX_SUB_FRAME_NUMBER][LTE_MAX_CCE_IDX];
extern unsigned int minRachTaValue ;
extern unsigned int maxRachTaValue ;
extern void cleanMibSibData();
extern void cleanUpLteBlList();
extern void cleanUpAsnbuffers();
void ulschCcchSduHandler(lteUserInfo* userInfo, ltePduMsgStruct* sdu);
void ulschDcchSduHandler(lteUserInfo* userInfo,  ltePduMsgStruct* sdu);
void ulschCrntiHandler(lteUserInfo* userInfo, lteMacCrntiStruct* crnti);
void checkAndCorrectNextDlSubframe(uint16 *sfNsf, uint8 offset);
void buildAndSendRrcConnSetup(lteUserInfo* userInfo);
void buildAndSendRrcConnReestabReject(lteUserInfo* userInfo);
void lteUserInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
void createAndPushSrReqToQ(uint16 sfNsf , lteUserInfo* userInfo);
uint8* buildLteTxDataReq(lteUserInfo* userInfo , uint16 sfNsf);
uint8* buildLteDlConfigReq(lteUserInfo* userInfo , uint16 sfNsf);
void resentDlMacPduOnHarqNackDtx(lteUserInfo* userInfo , uint16 sfNsf);
#ifdef LTE_USE_SR
void checkAndConfigureSchedulingRequest(uint16 sfNsf);
#endif
void getRivAndMcsFromMessageType(lteUserInfo *userInfo , lteMsgType_e msgType);
void sendDeleteCntxtMsgToSelf(lteUserInfo *info);
void addPagingReqToQ(lteL2InftMsg_t *lteRlcMsg);
void deletePagingReqFromQ(lteL2InftMsg_t *lteRlcMsg);
uint8* buildLtePagingTxDataReq(lteL2InftMsg_t *lteRlcMsg , uint16 sfNsf);
uint8* buildLtePagingDlConfigReq(lteL2InftMsg_t *lteRlcMsg , uint16 sfNsf);
void checkAndPushPagingReqToDlSchedulerQ(uint16 sfn , uint8 sbfn);

extern LteRrcMeasurementControlData gLteRrcMeasData;
uint8 rlcDataIndHandler()
{
	uint8 retVal = FALSE;
	lteL2InftMsg_t * lteRlcMsg = NULL;
	lteRlcMsg = (lteL2InftMsg_t*)deQueue(&rxRlcDataQ);
	if((lteRlcMsg != NULL)&&(exitLteApp == FALSE))
	{
		retVal = TRUE;
		if(lteRlcMsg->msgType == LTE_MSG_DELETE_MAC_RLC_USER_CNTXT_E)
		{
			userDeleteUsingCrnti(lteRlcMsg->l2Data.crnti , TRUE);
		}
        else if(lteRlcMsg->msgType == LTE_MSG_PAGING_START_REQ_E)
		{
            addPagingReqToQ(lteRlcMsg);
        }
        else if(lteRlcMsg->msgType == LTE_MSG_PAGING_STOP_REQ_E)
		{
            deletePagingReqFromQ(lteRlcMsg);
        }
		else
		{
	  		// Call Rlc Function for handling downlink message from RRC
			lteBuildAndSendRlcPdu(lteRlcMsg);
		}
	}
    return retVal;
}

void lteTDDcheckforULDlsubframe( uint16 *sfNsf , uint8 isDLSubframe)
{
	int i = 0;
	uint16 tempSfn = 0 ; uint8 tempSbfn = 0 ;
	tempSfn = ((*sfNsf)>>4) & 0x0FFF;
	tempSbfn = ((*sfNsf) & 0x000F) % LTE_MAX_SUB_FRAME_NUMBER;
	if(isDLSubframe)
	{
		for(i = tempSbfn ; i < (tempSbfn+LTE_MAX_SUB_FRAME_NUMBER) ; i++ )
		{
			if (ULDL[LTE_TDD_UD_CONFIG][(i%LTE_MAX_SUB_FRAME_NUMBER)] == LTE_TDD_DOWNLINK)
			break;
		}
		if(i >= LTE_MAX_SUB_FRAME_NUMBER)
		{
			tempSfn = ((tempSfn + 1)%LTE_MAX_SYSTEM_FRAME_NUMBER);
			tempSbfn = (i%LTE_MAX_SUB_FRAME_NUMBER);
		}
		else
		{
			tempSbfn = (i%LTE_MAX_SUB_FRAME_NUMBER);
		}
	}
	else
	{
		for(i = tempSbfn ; i < (tempSbfn+LTE_MAX_SUB_FRAME_NUMBER); i++ )
		{
			if (ULDL[LTE_TDD_UD_CONFIG][(i%LTE_MAX_SUB_FRAME_NUMBER)] == LTE_TDD_UPLINK)
			break;
		}

		if(i >= LTE_MAX_SUB_FRAME_NUMBER)
		{
			tempSfn = ((tempSfn + 1)%LTE_MAX_SYSTEM_FRAME_NUMBER);
			tempSbfn = (i%LTE_MAX_SUB_FRAME_NUMBER);
		}
		else
		{
			tempSbfn = (i%LTE_MAX_SUB_FRAME_NUMBER);
		}

	}

	*sfNsf = ((tempSfn<<4)|(tempSbfn & 0x0F));
	return;
}
	

void checkAndCorrectNextTddUlDlSubframe(uint16 *sfNsf, uint8 offset , uint8 isDLSubframe)
{
	uint16 currentSfn = 0 ; uint8 currentSbfn = 0  , tmp = 0;

	currentSfn = ((*sfNsf)>>4) & 0x0FFF;
	currentSbfn = ((*sfNsf) & 0x000F) % LTE_MAX_SUB_FRAME_NUMBER;
	
	tmp = currentSbfn + offset;
	if(tmp >= (2*LTE_MAX_SUB_FRAME_NUMBER))
	{
		currentSfn = (currentSfn + 2)%LTE_MAX_SYSTEM_FRAME_NUMBER;
	}
	else if((tmp >= LTE_MAX_SUB_FRAME_NUMBER) && (tmp < (2*LTE_MAX_SUB_FRAME_NUMBER)))
	{
		currentSfn = (currentSfn + 1)%LTE_MAX_SYSTEM_FRAME_NUMBER;
	}
	else
	{}

	currentSbfn = (currentSbfn + offset)%LTE_MAX_SUB_FRAME_NUMBER;
	*sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
	lteTDDcheckforULDlsubframe (sfNsf, isDLSubframe);
	return ;
}

void ulRachIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg)
{
	tOCT_FAPI_UL_RACH_INDICATION *rachInd = (tOCT_FAPI_UL_RACH_INDICATION*) lteFapiMsg->abyMsgBody;
	uint8 startRb = 36; //Support only 4 RACH for 10Mhz band and above in one TTI
	uint16 numORach = htons(rachInd->usNumOfPreamble) , sfNsf = htons(rachInd->usSfnsf) , rachCount = 0;
	lteUserInfo* userInfo = NULL;
	uint8 *dlConfigReq = NULL , *txDataReq = NULL , prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX;
	tOCT_FAPI_UL_PRACH_PDU_IND * rachPdu = NULL;

	if(lteSelectedBandwidth == LTE_BW_N6)
	{
		startRb = 4;
	}
	else if(lteSelectedBandwidth == LTE_BW_N15)
	{
		startRb = 13;
	}
	else if(lteSelectedBandwidth == LTE_BW_N25)
	{
		startRb = 19;
	}
	else
	{
		startRb = 38;
	}

	while(numORach != 0)
	{
		rachPdu = (tOCT_FAPI_UL_PRACH_PDU_IND*)&rachInd->aRachPduInfo[numORach -1];//&lteFapiMsg->abyMsgBody[SIZE_TOCT_FAPI_UL_RACH_INDICATION + indexLen];
		//Check for Prach_Config_Index = 2
	if(lteDuplxMode)
	{
		prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX_TDD;
		if((prachConfigIndex == 3) && ((sfNsf & 0x000F) != 2))
		{
				numORach--;
				continue;
		}
		else if ((prachConfigIndex == 0) && (((sfNsf & 0x000F) != 2) || (((sfNsf >> 4) & 0x0FFF) % 2 != 0)))
		{
				numORach--;
				continue;
		}
		else if ((prachConfigIndex == 2) && ((sfNsf & 0x000F) !=2))
		{
				numORach--;
				continue;
		}
        else if((htons(rachPdu->usTimingAdvance) < minRachTaValue) || (htons(rachPdu->usTimingAdvance) > maxRachTaValue) || (rachPdu->byPreamble) > 52) // Corresponds to 390-140 meters of radius
		{
				numORach--;
				continue;
		}
		else if (rachPdu->bySnr < 100) //SNR -14 dbm ; 
		{
				numORach--;
				continue;
		}
		else
		{
			//logPrint(LOG_DEBUG , "Rach RNTI = %d , TimingAdvance = %d , Preamble = %d \n" , htons(rachPdu->usRnti) , htons(rachPdu->usTimingAdvance), rachPdu->byPreamble);
		}
	}
   else
	{		//Check for Prach_Config_Index = 2
		if((prachConfigIndex == 2) && (((sfNsf & 0x000F) != 7) || (((sfNsf >> 4) & 0x0FFF) % 2 != 0)))
		{
				numORach--;
				continue;
		}
		else if((prachConfigIndex == 3) && ((sfNsf & 0x000F) != 1))
		{
				numORach--;
				continue;
		}
        else if((htons(rachPdu->usTimingAdvance) < minRachTaValue) || (htons(rachPdu->usTimingAdvance) > maxRachTaValue) || (rachPdu->byPreamble > 52))// Corresponds to 781 meters of radius
		{
				numORach--;
				continue;
		}
		else if (rachPdu->bySnr < 100) //SNR -14 dbm ;
		{
				numORach--;
				continue;
		}
		else
		{
			//logPrint(LOG_DEBUG , "Rach RNTI = %d , TimingAdvance = %d , Preamble = %d \n" , htons(rachPdu->usRnti) , htons(rachPdu->usTimingAdvance), rachPdu->byPreamble);
		}
	 }

         if (lteDuplxMode) // TDD Case
         {
             checkAndCorrectNextTddUlDlSubframe(&sfNsf , 7 , TRUE); // targeting subframe 9
         }
		else // FDD Case
		{
			checkAndCorrectNextDlSubframe(&sfNsf , 6);
		}
        // check if it is CRNTI based RAT for expiry of TAT timer
         if(htons(rachPdu->usRnti) <  LTE_RA_RNTI_END)
         {
			//Create User Context based on T-CRNTI assigned to this new transaction.
			userInfo = lteUserAdd();
			if(userInfo != NULL)
			{
				userInfo->raRnti = htons(rachPdu->usRnti);
				userInfo->rntiType = eFAPI_RA_RNTI_P_RNTI_SI_RNTI;
				userInfo->preamble = rachPdu->byPreamble;
				userInfo->timingAdvance = htons(rachPdu->usTimingAdvance);
				userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_INSIDE_RAR_RIV];
				userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_RAR_CARRYING_DL_RIV];
				userInfo->ulRssiArr[userInfo->rssiIndex++] = 0xFF - (((htons(rachPdu->usRssi) & 0xFF00)>>7) & 0x00FF);
				userInfo->ulSnr = (rachPdu->bySnr - 127)/2;

				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					userInfo->ulMcs = LTE_MAC_UL_GRANT_INSIDE_RAR_MCS;
					userInfo->dlMcs = LTE_MAC_RAR_CARRYING_DL_MCS;
				}
				else
				{
					userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_INSIDE_RAR_MCS;
					userInfo->dlMcs = LTE_MAC_BW_143_RAR_CARRYING_DL_MCS;
				}
				userInfo->ulRiv = getCurrentRiv(userInfo->ulRiv ,&startRb);
				userInfo->ulModulationType = eFAPI_QPSK; // QPSK
				userInfo->dlModulationType = eFAPI_QPSK; // QPSK
				//Build RAR message including Uplink Grant (keep track of UL-PRBs)
				buildLteRARPdu(userInfo , userInfo->macPduBuf , LTE_MAC_RAR_HEADER_TYPE_RAPID);
				userInfo->macPduLen = LTE_RAR_PDU_LENGTH;
				//Build Dl-Config Req for sending RAR , (keep track of DL-PRBs)
				dlConfigReq = buildLteDlConfigReq(userInfo , sfNsf);
				//Build Tx-Req for RAR message
				txDataReq = buildLteTxDataReq(userInfo , sfNsf);
				//Put all messages in the scheduler bins for the current subframe + 2 bin
				pushToDlConfigReqQ(sfNsf, dlConfigReq);
				pushToTxDataReqQ(sfNsf, txDataReq);
				userInfo->macLayerState = RACH_RESPONSE_SENT;
				//timerStop(&userInfo->tmr);

				if(TRUE == isTimerRunning(&userInfo->tmr))
				{
					timerStop(&userInfo->tmr);
				}
				
				timerStart(&userInfo->tmr , TIMER_FOR_LTE_RACH_HANDLING , 0 , lteUserInfoTimerCbFunction, userInfo);
				prepareUlMessageAfterSendingDlTxReq(userInfo, sfNsf);
			}
         }
         else
         {
        	 // CRTNIt based RACH
        	 logPrint(LOG_DEBUG , "Handle the new RACH received in the RRC COnnected State CRNTI = \n", htons(rachPdu->usRnti));
         }
		numORach--;
		if((lteSelectedBandwidth == LTE_BW_N6) || (lteSelectedBandwidth == LTE_BW_N15))
		{
			break;//Only one Rach handled
		}
		else if(lteSelectedBandwidth == LTE_BW_N25)
		{
			rachCount++;
			if(rachCount == LTE_MAX_NO_UL_PDU_PER_TTI/2)
			{
				break; // Only 2 rach handled
			}
		}
		else
		{
			rachCount++;
			if(rachCount == LTE_MAX_NO_UL_PDU_PER_TTI)
			{
				break; // Only 4 rach handled here
			}
		}
	}
}

void ulHarqIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg)
{
	tOCT_FAPI_UL_HARQ_INDICATION *harqInd = (tOCT_FAPI_UL_HARQ_INDICATION*) lteFapiMsg->abyMsgBody ;
	uint16 numOfHarq = htons(harqInd->usNumOfHarq) , sfNsf = 0 , currentSfn = 0;
	tOCT_FAPI_UL_HARQ_PDU_IND_FDD * ulHarqPduInfo = NULL;
	uint8 currentSbfn = 0;
	lteUserInfo* userInfo = NULL;

	while(numOfHarq != 0)
	{
		ulHarqPduInfo = (tOCT_FAPI_UL_HARQ_PDU_IND_FDD*)&harqInd->aHarqPduInfo[numOfHarq-1];//&lteFapiMsg->abyMsgBody[SIZE_TOCT_FAPI_UL_HARQ_INDICATION + indexLen];
		userInfo = userFindUsingCrnti(htons(ulHarqPduInfo->usRnti));
		if(userInfo != NULL)
		{
			if(ulHarqPduInfo->byHarqTB1 == eFAPI_DL_ACK)
			{
				//logPrint(LOG_DEBUG, "ulHarqIndHandler ACK RECVD RNTI = %d , MacLayerState = %d\n", htons(ulHarqPduInfo->usRnti), userInfo->macLayerState);

				userInfo->rvIndex = 0;
				if(userInfo->macLayerState == RRC_CONN_REQ_RECEIVED_CONTENTION_RESOLUTION_SENT)
				{
					buildAndSendRrcConnSetup(userInfo);
				}
				else if(userInfo->macLayerState == 
                                        RRC_CONN_REESTAB_RECEIVED_CONTENTION_RESOLUTION_SENT)
				{
					buildAndSendRrcConnReestabReject(userInfo);
				}
				else if(userInfo->macLayerState == 
                                        RRC_CONN_REESTAB_REJECT_SENT)
				{
                    if(TRUE == isTimerRunning(&userInfo->tmr))
                        timerStop(&userInfo->tmr);

                    userInfo->continuousUlGrant = FALSE;
                    userDeleteUsingCrnti(userInfo->crnti, TRUE);
                }
				else if(userInfo->macLayerState == RRC_CONN_SETUP_SENT)
				{
					userInfo->macLayerState = WAITING_TO_START_CONT_GRANT; //WAITING_FOR_RRC_CONN_COMPLETE;
					userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_RRC_CONN_COMPLETE_RIV];
					userInfo->ulModulationType = eFAPI_QPSK;
					if(lteSelectedBandwidth >LTE_BW_N15)
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_RRC_CONN_COMPLETE_MCS;
					}
					else
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_RRC_CONN_COMPLETE_MCS;
						userInfo->ulModulationType = eFAPI_16QAM;
					}

					//userInfo->continuousUlGrant = TRUE;
					//timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP_COMPLETE , 0 , lteUserInfoTimerCbFunction, userInfo);
					if(TRUE == isTimerRunning(&userInfo->tmr))
					{
						timerStop(&userInfo->tmr);
					}
					
					timerStart(&userInfo->tmr , TIMER_FOR_STARTING_CONT_GRANT , 0 , lteUserInfoTimerCbFunction, userInfo);
				}
				else if(userInfo->macLayerState == WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)
				{
					userInfo->macLayerState = ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH;
					userInfo->ulModulationType = eFAPI_QPSK;
					if(userInfo->silentCallStarted == TRUE)
					{
						userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_SILENT_CALL_NAS_MSG_RIV];
						if(lteSelectedBandwidth >LTE_BW_N15)
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_MCS;
						}
						else
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_SLIENT_CALL_MCS;
							userInfo->ulModulationType = eFAPI_16QAM;
						}
						/*
						if(isTimerRunning(&userInfo->tmr) == FALSE)
						{
							timerStart(&userInfo->tmr , TIMER_FOR_SENDING_PDCCH_ORDER , 0 , lteUserInfoTimerCbFunction, userInfo);
						}*/
						if(TRUE == isTimerRunning(&userInfo->tmr))
							timerStop(&userInfo->tmr);
					}
					else
					{
						userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_RRC_NAS_MSG_RIV];
						if(lteSelectedBandwidth >LTE_BW_N15)
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_RRC_NAS_MSG_MCS;
						}
						else
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_RRC_NAS_MSG_MCS;
							userInfo->ulModulationType = eFAPI_16QAM;
						}
						// Starting RLC Poll Retransmit timer after receiveing HARQ ACK for the transmitted message
						if(TRUE == isTimerRunning(&userInfo->tmr))
						{
							timerStop(&userInfo->tmr);
						}
						
						timerStart(&userInfo->tmr , TIMER_FOR_RLC_POLL_RETRANSMIT , 0 , lteUserInfoTimerCbFunction, userInfo);
					}

					if(userInfo->continuousUlGrant == FALSE)
					{
						userInfo->srRecoveryCounter = 0;
					}
					buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E);
				}
				else if(userInfo->macLayerState == WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL)
				{
					userInfo->macLayerState = ACK_RECEIVED_FOR_RRC_CONN_REL;
					userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_RIV];
					if(lteSelectedBandwidth >LTE_BW_N15)
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS;
					}
					else
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS;
					}
					userInfo->ulModulationType = eFAPI_QPSK;
					if(userInfo->continuousUlGrant == FALSE)
					{
						userInfo->srRecoveryCounter = 0;
					}

					if(TRUE == isTimerRunning(&userInfo->tmr))
					{
						timerStop(&userInfo->tmr);
					}
					
					timerStart(&userInfo->tmr , TIMER_FOR_RLC_POLL_RETRANSMIT , 0 , lteUserInfoTimerCbFunction, userInfo);
					buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E);
				}
				else
				{
					if(userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH)
					{
						userInfo->macLayerState = ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH;
						userInfo->ulModulationType = eFAPI_QPSK;
						if(userInfo->silentCallStarted == TRUE)
						{
							userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_SILENT_CALL_NAS_MSG_RIV];
							if(lteSelectedBandwidth >LTE_BW_N15)
							{
								userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_MCS;
							}
							else
							{
								userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_SLIENT_CALL_MCS;
								userInfo->ulModulationType = eFAPI_16QAM;
							}
							if(TRUE == isTimerRunning(&userInfo->tmr))
								timerStop(&userInfo->tmr);
						}
					}
					else
					{
						logPrint(LOG_DEBUG, "ulHarqIndHandler Msg Not Handled with RNTI = %d , MacLayerState = %d\n", htons(ulHarqPduInfo->usRnti), userInfo->macLayerState);
					}
				}
			}
			else //if((ulHarqPduInfo->byHarqTB1 == eFAPI_DL_NACK)||(ulHarqPduInfo->byHarqTB1 == eFAPI_DL_ACK_OR_NACK))
			{
				sfNsf = htons(harqInd->usSfnsf);
				currentSfn = 0;
				currentSbfn = 0;
				if(TRUE == isTimerRunning(&userInfo->tmr))
					timerStop(&userInfo->tmr);
				if(userInfo->macLayerState >= WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL)
				{
					userDeleteUsingCrnti(userInfo->crnti , TRUE);
				}
				//Get the Current sfn and subframe number
				currentSfn = ((sfNsf)>>4) & 0x0FFF;
				currentSbfn = (((sfNsf) & 0x000F ) + 4 ) % LTE_MAX_SUB_FRAME_NUMBER;
				if((((sfNsf) & 0x000F ) + 4 ) >= LTE_MAX_SUB_FRAME_NUMBER)
				{
					currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
				}

				if((currentSbfn + 8 ) >= LTE_MAX_SUB_FRAME_NUMBER) // 4+8
				{
					currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
				}
				currentSbfn = (((sfNsf) & 0x000F ) + 8 ) % LTE_MAX_SUB_FRAME_NUMBER;
				sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
				resentDlMacPduOnHarqNackDtx(userInfo , sfNsf);
			}
		}
		numOfHarq--;
	}
	return;
}

void ulTddHarqIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg)
{
	tOCT_FAPI_UL_HARQ_INDICATION_TDD *harqInd = (tOCT_FAPI_UL_HARQ_INDICATION_TDD*) lteFapiMsg->abyMsgBody ;
	uint16 numOfHarq = htons(harqInd->usNumOfHarq),sfNsf = 0 ;
	tOCT_FAPI_UL_HARQ_PDU_IND_TDD * ulHarqPduInfo = NULL;
	lteUserInfo* userInfo = NULL;

	while(numOfHarq != 0)
	{
		ulHarqPduInfo = (tOCT_FAPI_UL_HARQ_PDU_IND_TDD*)&harqInd->aHarqPduInfo[numOfHarq-1];//&lteFapiMsg->abyMsgBody[SIZE_TOCT_FAPI_UL_HARQ_INDICATION + indexLen];
	    userInfo = userFindUsingCrnti(htons(ulHarqPduInfo->usRnti));
		if(userInfo != NULL)
		{
			if ((ulHarqPduInfo->byMode == eFAPI_TDD_BUNDLING) && (ulHarqPduInfo->tddHarqResult.tddBundling.byValue0 == eFAPI_DL_ACK)) // ACK
			{
				userInfo->rvIndex = 0;
				if(userInfo->macLayerState == RRC_CONN_REQ_RECEIVED_CONTENTION_RESOLUTION_SENT)
				{
					buildAndSendRrcConnSetup(userInfo);
				}
				else if(userInfo->macLayerState == 
                                        RRC_CONN_REESTAB_RECEIVED_CONTENTION_RESOLUTION_SENT)
				{
					buildAndSendRrcConnReestabReject(userInfo);
				}
				else if(userInfo->macLayerState == 
                                        RRC_CONN_REESTAB_REJECT_SENT)
				{
                    if(TRUE == isTimerRunning(&userInfo->tmr))
                        timerStop(&userInfo->tmr);

                    userInfo->continuousUlGrant = FALSE;
                    userDeleteUsingCrnti(userInfo->crnti, TRUE);
                }
				else if(userInfo->macLayerState == RRC_CONN_SETUP_SENT)
				{
					userInfo->macLayerState = WAITING_TO_START_CONT_GRANT;//WAITING_FOR_RRC_CONN_COMPLETE;
					userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_RRC_CONN_COMPLETE_RIV];
					userInfo->ulModulationType = eFAPI_QPSK;
					if(lteSelectedBandwidth >LTE_BW_N15)
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_RRC_CONN_COMPLETE_MCS;
					}
					else
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_RRC_CONN_COMPLETE_MCS;
						userInfo->ulModulationType = eFAPI_16QAM;
					}
					//userInfo->continuousUlGrant = TRUE;
					//logPrint(LOG_DEBUG , "Continuous Grant started after RrcConnSetup\n");
					if(TRUE == isTimerRunning(&userInfo->tmr))
					{
						timerStop(&userInfo->tmr);
					}
					//timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP_COMPLETE , 0 , lteUserInfoTimerCbFunction, userInfo);
					timerStart(&userInfo->tmr , TIMER_FOR_STARTING_CONT_GRANT , 0 , lteUserInfoTimerCbFunction, userInfo);
				}
				else if(userInfo->macLayerState == WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)
				{
					userInfo->macLayerState = ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH;
					userInfo->ulModulationType = eFAPI_QPSK;
					if(userInfo->silentCallStarted == TRUE)
					{
						userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_SILENT_CALL_NAS_MSG_RIV];
						if(lteSelectedBandwidth > LTE_BW_N15)
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_MCS;
						}
						else
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_SLIENT_CALL_MCS;
							userInfo->ulModulationType = eFAPI_16QAM;
						}
						// Not Starting timer here in Silent call
						if(TRUE == isTimerRunning(&userInfo->tmr))
							timerStop(&userInfo->tmr);
					}
					else
					{
						userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_RRC_NAS_MSG_RIV];
						if(lteSelectedBandwidth >LTE_BW_N15)
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_RRC_NAS_MSG_MCS;
						}
						else
						{
							userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_RRC_NAS_MSG_MCS;
							userInfo->ulModulationType = eFAPI_16QAM;
						}
						// Starting RLC Poll Retransmit timer after receiveing HARQ ACK for the transmitted message
						if(TRUE == isTimerRunning(&userInfo->tmr))
						{
							timerStop(&userInfo->tmr);
						}
						
						timerStart(&userInfo->tmr , TIMER_FOR_RLC_POLL_RETRANSMIT , 0 , lteUserInfoTimerCbFunction, userInfo);
					}

					if(userInfo->continuousUlGrant == FALSE)
					{
						userInfo->srRecoveryCounter = 0;
					}
					buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E);
				}
				else if(userInfo->macLayerState == WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL)
				{
					userInfo->macLayerState = ACK_RECEIVED_FOR_RRC_CONN_REL;
					userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_RIV];
					if(lteSelectedBandwidth >LTE_BW_N15)
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS;
					}
					else
					{
						userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS;
					}
					userInfo->ulModulationType = eFAPI_QPSK;
					if(userInfo->continuousUlGrant == FALSE)
					{
						userInfo->srRecoveryCounter = 0;
					}

					if(TRUE == isTimerRunning(&userInfo->tmr))
					{
						timerStop(&userInfo->tmr);
					}
					
					timerStart(&userInfo->tmr , TIMER_FOR_RLC_POLL_RETRANSMIT , 0 , lteUserInfoTimerCbFunction, userInfo);
					buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E);
					//logPrint(LOG_DEBUG, "ulTDDHARQ : RRC COnnection release HARQ ACK received");
				}
				else
				{
					if(userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH)
					{
						userInfo->macLayerState = ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH;
						userInfo->ulModulationType = eFAPI_QPSK;
						if(userInfo->silentCallStarted == TRUE)
						{
							userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_SILENT_CALL_NAS_MSG_RIV];
							if(lteSelectedBandwidth >LTE_BW_N15)
							{
								userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_MCS;
							}
							else
							{
								userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_SLIENT_CALL_MCS;
								userInfo->ulModulationType = eFAPI_16QAM;
							}
							if(TRUE == isTimerRunning(&userInfo->tmr))
								timerStop(&userInfo->tmr);
						}
					}
					else
					{
						logPrint(LOG_DEBUG, "ulTddHarqIndHandler Msg Not Handled with RNTI = %d , MacLayerState = %d\n", htons(ulHarqPduInfo->usRnti), userInfo->macLayerState);
					}

				}
			}
			else //if((ulHarqPduInfo->byHarqTB1 == eFAPI_DL_NACK)||(ulHarqPduInfo->byHarqTB1 == eFAPI_DL_ACK_OR_NACK))
			{
				sfNsf = htons(harqInd->usSfnsf);
				//currentSfn = 0;
				//currentSbfn = 0;
				if(isTimerRunning(&userInfo->tmr) == TRUE)
				{
					timerStop(&userInfo->tmr);
					userInfo->tmr.parm = NULL;
				}
				
				if(userInfo->macLayerState >= WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL)
				{
					userInfo->continuousUlGrant = FALSE;
					userDeleteUsingCrnti(userInfo->crnti , TRUE);
				}
				else
				{
				//Get the Current sfn and subframe number // n DL Msg , n+4 DTX/NACK , n+8 RETX
	                checkAndCorrectNextTddUlDlSubframe(&sfNsf , 5 , TRUE);
					resentDlMacPduOnHarqNackDtx(userInfo , sfNsf); // TBD
					//logPrint(LOG_DEBUG, "ulTddHarqIndHandler Msg Handled NACK Cases with RNTI = %d , MacLayerState = %d\n", htons(ulHarqPduInfo->usRnti), userInfo->macLayerState);
				}
			}
		}
		numOfHarq--;
	}
	return;
}

void ulRxUlschIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg)
{
	tOCT_FAPI_UL_SCH_INDICATION *ulSchInd = (tOCT_FAPI_UL_SCH_INDICATION*)lteFapiMsg->abyMsgBody;
	uint16 numOfUlPdus = htons(ulSchInd->usNumOfPdu), offset = 0 , pduLen = 0 , ulRssi_phr = 0 , avgRssi = 0;
	tOCT_FAPI_UL_DATA_PDU_IND *ulDataInd = NULL;
	lteUserInfo* userInfo = NULL;
	ltePduMsgStruct msg = {0};
	uint8 i = 0 , j = 0 , k = 0;
	//logPrint(LOG_DEBUG , "ulRxUlschIndHandler No. of Pdu = %d\n" , numOfUlPdus);
	if(numOfUlPdus > LTE_MAX_NO_UL_PDU_PER_TTI)
	{
		numOfUlPdus = LTE_MAX_NO_UL_PDU_PER_TTI;
	}
	while(numOfUlPdus > 0)
	{
		ulDataInd = (tOCT_FAPI_UL_DATA_PDU_IND*)&ulSchInd->aUlDataPduInfo[numOfUlPdus-1];//&lteFapiMsg->abyMsgBody[SIZE_TOCT_FAPI_UL_SCH_INDICATION + indexLen];
		userInfo = userFindUsingCrnti(htons(ulDataInd->usRnti));
		offset = htons(ulDataInd->usDataOffset);
		pduLen = htons(ulDataInd->usLength);
		if(offset == 0)
		{
			//logPrint(LOG_DEBUG , "ulRxUlschIndHandler PDU in CRC ERROR \n");
			if(userInfo != NULL)
            {
                 userInfo->ulSaturationFlag = ulDataInd->byUlSaturationFlag;
            }
		}
		else if((userInfo != NULL)&&(htons(lteFapiMsg->usMsgLen) > (offset + pduLen))) // Check if we need to add check for ulHandle as well
		{
			msg.N_bits = 0; msg.msg = NULL;
			memset((uint8*)&mac_pdu , 0, sizeof(lteMacPduStruct));
			userInfo->ulSaturationFlag = ulDataInd->byUlSaturationFlag;
            userInfo->ulSnr = (ulDataInd->byUlCqi -127)/2;

			ulRssi_phr = 0xFF - (((htons(ulDataInd->sUlRssi) & 0xFF00)>>7) & 0x00FF);
			if(ulRssi_phr < 110)
			{
				userInfo->ulRssiArr[userInfo->rssiIndex++] = (ulRssi_phr & 0x00FF);
				if(userInfo->rssiIndex == LTE_MAX_SUB_FRAME_NUMBER)
				{
					userInfo->rssiIndex = 0;
				}
			}
			mac_pdu.chan_type = LTE_MAC_CHAN_TYPE_ULSCH;
			msg.N_bits = 8*pduLen;//update this to offset
			msg.msg = (uint8*)&lteFapiMsg->abyMsgBody[offset + 2];//(uint8*)&ulSchInd->abyPduBuffer[pduLen];
			userInfo->ulHandle = htonl(ulDataInd->ulHandle);
	
			if(decodeUlMacPdu(&msg , &mac_pdu) == FALSE)
			{
//                           logPrint(LOG_DEBUG , "decodeUlMacPdu No. Of Subheaders = %d\n",mac_pdu.N_subheaders);
               for(i=0; i<mac_pdu.N_subheaders; i++)
               {
		        	if((LTE_MAC_ULSCH_POWER_HEADROOM_REPORT_LCID == mac_pdu.subheader[i].lcid) &&
                                   (0 != mac_pdu.subheader[i].eBit))
		        	{
		        		userInfo->phr_ulRssi = (userInfo->phr_ulRssi & 0xFF00);
		        		userInfo->phr_ulRssi = (userInfo->phr_ulRssi | 
                                                                mac_pdu.subheader[i].payload.power_headroom.ph);
//	        			logPrint(LOG_DEBUG, "ulRxUlschIndHandler PHR  = %02x\n", 
//                                                 (userInfo->phr_ulRssi & 0x00FF));
		        	}
                    else if((LTE_MAC_ULSCH_CCCH_LCID == mac_pdu.subheader[i].lcid) && 
                            (0 != mac_pdu.subheader[i].eBit))
	                {
//                                    logPrint(LOG_DEBUG, "ulRxUlschIndHandler CCCH LCID = 0x%x\n", 
//                                             mac_pdu.subheader[i].lcid);

                            if(TRUE == isTimerRunning(&userInfo->tmr))
                               timerStop(&userInfo->tmr);

                            ulschCcchSduHandler(userInfo,&mac_pdu.subheader[i].payload.sdu);
	                }
                    else if((LTE_MAC_ULSCH_DCCH_LCID_BEGIN <= mac_pdu.subheader[i].lcid) &&
                            (LTE_MAC_ULSCH_DCCH_LCID_END   >= mac_pdu.subheader[i].lcid) &&
                            (0 != mac_pdu.subheader[i].eBit))
	                {
	//                                    logPrint(LOG_DEBUG, "ulRxUlschIndHandler DCCH LCID = 0x%x\n", 
	//                                             mac_pdu.subheader[i].lcid);
                            userInfo->lcid = 0x0000FFFF & (mac_pdu.subheader[i].lcid);
                            ulschDcchSduHandler(userInfo, &mac_pdu.subheader[i].payload.sdu);
	                }
                    else if((LTE_MAC_ULSCH_C_RNTI_LCID == mac_pdu.subheader[i].lcid) &&
                            (0 != mac_pdu.subheader[i].eBit))
                    {
	//                                    logPrint(LOG_DEBUG, "ulRxUlschIndHandler CRNTI = %d LCID = 0x%x\n", 
	//                                             mac_pdu.subheader[i].payload.c_rnti.c_rnti, mac_pdu.subheader[i].lcid);
                          ulschCrntiHandler(userInfo, 
                                            &mac_pdu.subheader[i].payload.c_rnti);
                    }
		        }

    			if((userInfo->silentCallStarted == TRUE)&&((userInfo->phr_ulRssi & 0x00FF) != 0)&&(ulRssi_phr < 110))
    			{
    				for(j = 0; j<LTE_MAX_SUB_FRAME_NUMBER; j++)
    				{
    					if(userInfo->ulRssiArr[j] != 0)
    					{
    						avgRssi = avgRssi + userInfo->ulRssiArr[j];
    						k++;
    					}
    				}
    				avgRssi = avgRssi/k;
    				ulRssi_phr = (avgRssi & 0x00FF);
    				ulRssi_phr = (ulRssi_phr << 8) & 0xFF00;
	        		ulRssi_phr = ulRssi_phr | (userInfo->phr_ulRssi & 0x00FF); // update rssi here
	        		if(userInfo->phr_ulRssi != ulRssi_phr)
	        		{
						userInfo->phr_ulRssi = ulRssi_phr;
		        		buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_UPDATE_PHR_RSSI_IN_SILENT_CALL_E);        			
	        		}
     			}
			}
			//logPrint(LOG_DEBUG , "ulRxUlschIndHandler PduLen = %d , PHR = %d, RSSI/PRB = %d , CRNTI = %d\n" , htons(ulDataInd->usLength) , userInfo->phr , -1*(userInfo->ulRssiPerPrb)  , userInfo->crnti);
			//logPrint(LOG_DEBUG , "LTE Measurements Received RSRP = %d\n" , -1*ulRssi_phr);
		}
		else
		{}
		numOfUlPdus--;
		//pduLen = pduLen + htons(ulDataInd->usLength);
	}

	return;
}

listNode* getHeadDlSchedulerSubframeQ(uint8 subframeNo)
{
	assert(subframeNo < LTE_MAX_SUB_FRAME_NUMBER);
	return(headForLteMacDlSchedulerQ[subframeNo]);
}

listNode* getHeadDlTxDataSubframeQ(uint8 subframeNo)
{
	assert(subframeNo < LTE_MAX_SUB_FRAME_NUMBER);
	return(headForLteMacDlTxDataQ[subframeNo]);
}
// Function queue Mac Pdu to scheduler queue
void pushMacPduToDlSchedulerQ(uint8 subframeNo , uint8 *msg)
{
	listNode *tail = NULL;

	assert(subframeNo < LTE_MAX_SUB_FRAME_NUMBER);
	tail = tailForLteMacDlSchedulerQ[subframeNo];

	pushMsgToList(&tail ,(void*)msg);
	if((headForLteMacDlSchedulerQ[subframeNo] == NULL)||(tailForLteMacDlSchedulerQ[subframeNo] == NULL))
	{
		headForLteMacDlSchedulerQ[subframeNo] = tailForLteMacDlSchedulerQ[subframeNo] = tail; // Update for the first time
	}
	else
	{
		tailForLteMacDlSchedulerQ[subframeNo] = tail; // Just update the tail node
	}
	return;
}
// Function queue Mac Pdu to DlTxData queue
void pushMacPduToDlTxDataQ(uint8 subframeNo , uint8 *msg)
{
	listNode *tail = NULL;

	assert(subframeNo < LTE_MAX_SUB_FRAME_NUMBER);
	tail = tailForLteMacDlTxDataQ[subframeNo];

	pushMsgToList(&tail ,(void*)msg);
	if((headForLteMacDlTxDataQ[subframeNo] == NULL)||(tailForLteMacDlTxDataQ[subframeNo] == NULL))
	{
		headForLteMacDlTxDataQ[subframeNo] = tailForLteMacDlTxDataQ[subframeNo] = tail; // Update for the first time
	}
	else
	{
		tailForLteMacDlTxDataQ[subframeNo] = tail; // Just update the tail node
	}
	return;
}
void pushMacPduToUlSchedulerQ(uint8 subframeNo , uint8 *msg)
{
	listNode *tail = NULL;

	assert(subframeNo < LTE_MAX_SUB_FRAME_NUMBER);
	tail = tailForLteMacUlSchedulerQ[subframeNo];

	pushMsgToList(&tail ,(void*)msg);
	if((headForLteMacUlSchedulerQ[subframeNo] == NULL)||(tailForLteMacUlSchedulerQ[subframeNo] == NULL))
	{
		headForLteMacUlSchedulerQ[subframeNo] = tailForLteMacUlSchedulerQ[subframeNo] = tail; // Update for the first time
	}
	else
	{
		tailForLteMacUlSchedulerQ[subframeNo] = tail; // Just update the tail node
	}

	return;

}

void triggerRrcReconfigReqFromRRC(lteUserInfo *info)
{
	buildAndSendRlcMsgToRrc(info , LTE_MSG_TRIGGER_RRC_RECONFIG_REQ_E);
}

void buildAndSendPdcchOrderReq(lteUserInfo* userInfo)
{
	uint8 *msgBuf = getDlConfigBuffer();
	uint8 msgLenth = 0;
	uint16 sfNsf = 0;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	checkAndCorrectNextDlSubframe(&sfNsf, 5);
	dlConfigReq->usSfnsf = htons(sfNsf);
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ; //3
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	msgLenth = SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE;
	if(userInfo != NULL) // Real Dl-config request
	{
		tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDciConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE];
		tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
		tOCT_FAPI_DCIFORMAT_1A *dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];

		dlConfigReq->byNumDCI = 1;
		dlConfigReq->byNumOfPDSCHRNTI = 0; // RA/CI_RNTI only
		dlConfigReq->usNumOfPDU = htons(1) ; // 1-Pdcch(dci-1a)

		/* DCI1A Pdu Start*********************************************************************************************/
		dlDciConfigPdu->byPduType = eFAPI_DCI_DL_PDU;
		dlDciConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; //28bytes

		dciPduInfo->DCIPdu.byDciFormat = eFAPI_DL_DCI_FORMAT_1A;
		dciPduInfo->DCIPdu.byCceIndex = CalculateLteCceIdx(FALSE,userInfo->crnti,sfNsf);
		userInfo->cceIndex[(sfNsf & 0x000F)] = dciPduInfo->DCIPdu.byCceIndex;
		dciPduInfo->DCIPdu.usRnti = htons(userInfo->crnti);
		dci1AInfo->byTpc = eFAPI_TX_POWER_CONTROL_0; // If this value changes then change the rbCoding as well and NPRB = 3
		if(lteSelectedBandwidth > LTE_BW_N15)
		{
			dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
		}
		else
		{
			dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU/2;
		}

		dci1AInfo->byVRBAssignmentFlag = eFAPI_LOCALISED; //Localized
		dci1AInfo->byMcs_1 = 0;
		dci1AInfo->byRedundancyVersion_1 = 0; // Redudancy version should be changed as 0->2->3->1
		dci1AInfo->ulRbCoding = htonl(0xFFFFFFFF); //PDCCH-ORDER;
		dci1AInfo->byNewDataIndicator_1 = 0;

		dci1AInfo->byHarqProcessNum = 0;

		dci1AInfo->byDlAssignmentIndex = 0;//tdd

		dci1AInfo->byAllocatePRACHFlag = TRUE;
		dci1AInfo->byPreambleIndex = userInfo->preamble;
		dci1AInfo->usTxPower = 0; //htons(LTE_PDCCH_POWER_OFFSET_VALUE);
		dci1AInfo->byPRACHMaskIndex = 0;
		dci1AInfo->byRntiType = eFAPI_C_RNTI;
		/* DCI1A Pdu End*********************************************************************************************/


		//SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A
		msgLenth = msgLenth + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A;
	}

	dlConfigReq->usLength = htons(msgLenth);
	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);
	//logPrint(LOG_DEBUG , "PDCCH-ORDER CRNTI = %d , SFNSF = %04x\n",userInfo->crnti , sfNsf);
	pushToDlConfigReqQ(sfNsf, msgBuf);
	return;
}


uint8* buildLteDlConfigReq(lteUserInfo* userInfo , uint16 sfNsf)
{
	uint8 *msgBuf = getDlConfigBuffer();
	uint8 msgLenth = 0;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	dlConfigReq->usSfnsf = htons(sfNsf);
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ; //3
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	msgLenth = SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE;
	if(userInfo != NULL) // Real Dl-config request
	{
		tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDciConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE];
		tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
		tOCT_FAPI_DCIFORMAT_1A *dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];

		tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDlSchConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A];
		tOCT_FAPI_DL_CONFIG_PDU_INFO *dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

		dlConfigReq->byNumDCI = 1;
		dlConfigReq->byNumOfPDSCHRNTI = 1; // RA/CI_RNTI only
		dlConfigReq->usNumOfPDU = htons(2) ; // 1-Pdcch(dci-1a) and 2-DlSch Pdu

		/* DCI1A Pdu Start*********************************************************************************************/
		dlDciConfigPdu->byPduType = eFAPI_DCI_DL_PDU;
		dlDciConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; //28bytes

		dciPduInfo->DCIPdu.byDciFormat = eFAPI_DL_DCI_FORMAT_1A;
		if(userInfo->rntiType == eFAPI_RA_RNTI_P_RNTI_SI_RNTI) //RA_RNTI/SI_RNTI
		{
			dciPduInfo->DCIPdu.byCceIndex = CalculateLteCceIdx(TRUE,userInfo->raRnti,sfNsf);
			userInfo->cceIndex[(sfNsf & 0x000F)] = dciPduInfo->DCIPdu.byCceIndex;			
			dciPduInfo->DCIPdu.usRnti = htons(userInfo->raRnti);
			dci1AInfo->byTpc = eFAPI_TX_POWER_CONTROL_MINUS_1; // If this value changes then change the rbCoding as well and NPRB = 3
			if(lteSelectedBandwidth > LTE_BW_N15)
			{
				dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS;
			}
			else
			{
				dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS/2;
			}
		}
		else if(userInfo->rntiType == eFAPI_C_RNTI)
		{
			dciPduInfo->DCIPdu.byCceIndex = CalculateLteCceIdx(FALSE,userInfo->crnti,sfNsf);
			userInfo->cceIndex[(sfNsf & 0x000F)] = dciPduInfo->DCIPdu.byCceIndex;
			dciPduInfo->DCIPdu.usRnti = htons(userInfo->crnti);
			dci1AInfo->byTpc = eFAPI_TX_POWER_CONTROL_0; // If this value changes then change the rbCoding as well and NPRB = 3
			if(lteSelectedBandwidth > LTE_BW_N15)
			{
				dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
			}
			else
			{
				dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU/2;
			}
		}


		dci1AInfo->byVRBAssignmentFlag = eFAPI_LOCALISED; //Localized
		dci1AInfo->byMcs_1 = userInfo->dlMcs;
		dci1AInfo->byRedundancyVersion_1 = lteRvArr[0 /*userInfo->rvIndex*/]; // Redudancy version should be changed as 0->2->3->1
		dci1AInfo->ulRbCoding = htonl(userInfo->dlRiv); //riv;
		dci1AInfo->byNewDataIndicator_1 = userInfo->ndiDl;
		if(userInfo->ndiDl == 1)
		{
			userInfo->ndiDl = 0;
		}
		else
		{
			userInfo->ndiDl = 1;
		}

		dci1AInfo->byHarqProcessNum = 0;
		if(lteDuplxMode)
		dci1AInfo->byDlAssignmentIndex = 1;//tdd
		else
		dci1AInfo->byDlAssignmentIndex = 0;//tdd
			
		dci1AInfo->byAllocatePRACHFlag = FALSE;
		dci1AInfo->byPreambleIndex = 0;
		dci1AInfo->usTxPower = htons(LTE_PDCCH_POWER_OFFSET_VALUE);
		dci1AInfo->byPRACHMaskIndex = 0;
		dci1AInfo->byRntiType = userInfo->rntiType;
		/* DCI1A Pdu End*********************************************************************************************/

		/* DL-SCH Pdu Start*********************************************************************************************/
		dlDlSchConfigPdu->byPduType = eFAPI_DLSCH_PDU;
		dlDlSchConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; // 32Bytes

		dlSchPduInfo->DlSCHPdu.usDlschPduLen = htons(userInfo->macPduLen);
		dlSchPduInfo->DlSCHPdu.usPduIndex = LTE_SHORT_ZERO;
		if(userInfo->rntiType == eFAPI_RA_RNTI_P_RNTI_SI_RNTI) //RA_RNTI/SI_RNTI
		{
			dlSchPduInfo->DlSCHPdu.usRnti = htons(userInfo->raRnti);
		}
		else if(userInfo->rntiType == eFAPI_C_RNTI)
		{
			dlSchPduInfo->DlSCHPdu.usRnti = htons(userInfo->crnti);
		}

		dlSchPduInfo->DlSCHPdu.byResAllocationType = eFAPI_RES_ALLOC_TYPE_2;
		dlSchPduInfo->DlSCHPdu.byVRBAssignmentFlag = eFAPI_LOCALISED;
		dlSchPduInfo->DlSCHPdu.ulRbCoding = htonl(userInfo->dlRiv);//riv;
		dlSchPduInfo->DlSCHPdu.byMcs = userInfo->dlModulationType;
		dlSchPduInfo->DlSCHPdu.byRedundancyVersion = 0;//lteRvArr[0 /*userInfo->rvIndex*/];
		dlSchPduInfo->DlSCHPdu.byTransportBlocks = 1;
		dlSchPduInfo->DlSCHPdu.byTbToCodeWordSwapFlag = eFAPI_NOSWAPPING;
		dlSchPduInfo->DlSCHPdu.byTransmissionScheme = eFAPI_DL_SINGLE_ANTENNA_PORT_0;
		dlSchPduInfo->DlSCHPdu.byNumOfLayers = 1;
		dlSchPduInfo->DlSCHPdu.byNumOfSubBand = 0;
		dlSchPduInfo->DlSCHPdu.byUeCatagoryCapacity = LTE_UE_CATEGORY;
		dlSchPduInfo->DlSCHPdu.byPA = LTE_PDSCH_CONFIG_PA_VALUE_dB_3;//-3dB //4; //0dB
		dlSchPduInfo->DlSCHPdu.byDeltaPowerOffsetAIndex = 0;
		dlSchPduInfo->DlSCHPdu.byNGap = 0;
		dlSchPduInfo->DlSCHPdu.byNPRB = 0; //NPRB=2
		dlSchPduInfo->DlSCHPdu.usNumRbPerSubBand = 0;// htons(bwToPrb[lteSelectedBandwidth]);
		dlSchPduInfo->DlSCHPdu.usNumbfVector = LTE_SHORT_ZERO;
		/* DL-SCH Pdu End*********************************************************************************************/

		//SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE
		msgLenth = msgLenth + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE;

	}

	dlConfigReq->usLength = htons(msgLenth);
	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);

	return msgBuf;
}


uint8* buildLteTxDataReq(lteUserInfo* userInfo , uint16 sfNsf)
{
	uint8 *msgBuf = getDlTxDataBuffer();
	uint8 msgLen = 0;
	uint8* data = NULL;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_DATA_TX_REQUEST * txReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_PDU_DATA_INFO *dlPdu = (tOCT_FAPI_DL_PDU_DATA_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE];
	tOCT_FAPI_DL_PDU_DATA_TLV *txData = (tOCT_FAPI_DL_PDU_DATA_TLV*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

	txReq->usSfnsf = htons(sfNsf);
	txReq->usNumOfPDU = htons(1);

	msgLen = userInfo->macPduLen;

	dlPdu->usPduIndex = LTE_SHORT_ZERO;
	dlPdu->ulNumOfTLV = htonl(1);

	data = (uint8*)&txData->aulValue[0];//Check for length
	if(userInfo->macPduLen > 160 )
		userInfo->macPduLen = 160;
	memcpy((uint8*)data, (uint8*)userInfo->macPduBuf , userInfo->macPduLen);

	txData->usTag = LTE_SHORT_ZERO;
	txData->usTagLen = htons(userInfo->macPduLen);
	if((msgLen%4) != 0)
	{
		msgLen = msgLen + (4 - (msgLen%4)); // Aligning to word boundry
	}
	dlPdu->usPduLen = htons(msgLen + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE);
	msgLen = msgLen + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE;

	lteFapiMsg->msgId = PHY_DL_TX_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);

	return msgBuf;
}

uint8* buildLteUlConfigReq(lteUserInfo* userInfo , uint16 sfNsf , eFAPI_UL_CONFIG_PDU_INFO pduType)
{
	uint8 *msgBuf = NULL;
	if(userInfo != NULL)
	{
		msgBuf =  getUlConfigBuffer();
	}
	else
	{
		msgBuf = getBufferFordummyUlconfigReq();
		memset(msgBuf , 0 , 64);
	}
	uint8 msgLenth = 0 , pduSize = 0 , prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_UL_CONFIG_REQUEST *ulConfigReq = (tOCT_FAPI_UL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

	if(lteDuplxMode)
	{
		prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX_TDD;
		if((prachConfigIndex == 3)&&((sfNsf & 0x000F) == 2))
		{
			ulConfigReq->byRachFreqResources = 1; // TDD-RACH
		}
		else if((prachConfigIndex == 0) && ((sfNsf & 0x000F) == 2) && (((sfNsf >> 4) & 0x0FFF) % 2 == 0))
		{
			ulConfigReq->byRachFreqResources = 1; // TDD-RACH
		}
		else if((prachConfigIndex == 2) && ((sfNsf & 0x000F) == 2))
		{
			ulConfigReq->byRachFreqResources = 1; // TDD-RACH
		}
		else
		{
			ulConfigReq->byRachFreqResources = 0; // TDD-RACH
		}
	}
	else
	{
		if((prachConfigIndex == 2) && ((sfNsf & 0x000F) == 7) && (((sfNsf >> 4) & 0x0FFF) % 2 == 0))
		{
			ulConfigReq->byRachFreqResources = 1; // FDD-RACH
		}
		else if ((prachConfigIndex == 3) && ((sfNsf & 0x000F) == 1))
		{
			ulConfigReq->byRachFreqResources = 1; // FDD-RACH
		}
		else
		{
			ulConfigReq->byRachFreqResources = 0; // FDD-RACH
		}
	}

	ulConfigReq->usSfnsf = htons(sfNsf);
	ulConfigReq->bySrsPresent = 0;
	msgLenth = SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE;

	if(userInfo != NULL)
	{
		ulConfigReq->byNumOfPdu = 1;
		tOCT_FAPI_UL_CONFIG_PDU_INFO *ulPdu = (tOCT_FAPI_UL_CONFIG_PDU_INFO *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE];
		ulPdu->byUlConfigPduType = pduType;
		ulPdu->byUlConfigPduSize = SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE; //Add more bytes as per pdutype
		switch(pduType)
		{
			case eFAPI_ULSCH:
			{
				tOCT_FAPI_UL_SCH_PDU_INFO *pduInfo = (tOCT_FAPI_UL_SCH_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE];
				pduInfo->ulHandle = htonl(userInfo->ulHandle);

				if(userInfo->macLayerState == RACH_RESPONSE_SENT)
                {
                       pduInfo->usSize = htons(LTE_MAC_UL_GRANT_SIZE_FOR_RRC_CONN_REQ);
                }
				else if((userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)||
	                    (userInfo->macLayerState == RRC_CONN_SETUP_SENT)||
	                    (userInfo->macLayerState == RRC_CONN_REQ_RECEIVED_CONTENTION_RESOLUTION_SENT)||
	                    (userInfo->macLayerState == RRC_CONN_REESTAB_RECEIVED_CONTENTION_RESOLUTION_SENT))
				{
					pduInfo->usSize = htons(LTE_MAC_UL_GRANT_SIZE_FOR_RRC_CONN_SETUP_COMPLETE);
				}
				else if((userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH)||(userInfo->macLayerState == WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH))
				{
					if(userInfo->silentCallStarted == TRUE)
					{
						pduInfo->usSize = htons(LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_NAS_MSG_SIZE);
					}
					else
					{
						pduInfo->usSize = htons(LTE_MAC_UL_GRANT_SIZE_FOR_RRC_NAS_MSG);
					}
				}
				else if((userInfo->macLayerState == ACK_RECEIVED_FOR_RRC_CONN_REL)||(userInfo->macLayerState == WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL))
				{
					pduInfo->usSize = htons(LTE_MAC_UL_GRANT_SIZE_FOR_RLC_ACK_FOR_CONN_REL_MSG);
				}
				else
				{
					logPrint(LOG_ERR, "Not handling UL in this State of LTE-MAC=%d\n",userInfo->macLayerState );
					assert(0);
				}

				pduInfo->usRnti = htons(userInfo->crnti);
				pduInfo->byRbStart = (userInfo->ulRiv % bwToPrb[lteSelectedBandwidth]) ;
				pduInfo->byNumOfRB = (userInfo->ulRiv / bwToPrb[lteSelectedBandwidth]) + 1 ;
				if((lteSelectedBandwidth == LTE_BW_N6)&&(userInfo->ulRiv == 11))
				{
					pduInfo->byRbStart = 0;
					pduInfo->byNumOfRB = 6;
				}
				pduInfo->byModulationType = userInfo->ulModulationType;
				pduInfo->byCyclicShift2forDMRS = 0;
				pduInfo->byFreqHoppingenabledFlag = 0; // disabled
				pduInfo->byFreqHoppingBits = 0;
				pduInfo->byNewDataIndication = userInfo->ndiUl;
				pduInfo->byRedundancyVersion = 0;
				pduInfo->byHarqProcessNumber = 0;
				pduInfo->byUlTxMode = 0; // SISO mode
				pduInfo->byCurrentTxNB = 0;
				pduInfo->byNSRS = 0; // No Overlap
				pduSize = SIZE_TOCT_FAPI_UL_SCH_PDU_INFO;
			}
			break;

			case eFAPI_ULSCH_CQI_RI:
			{
				tOCT_FAPI_UL_SCH_CQIRI_PDU_INFO *pduInfo = (tOCT_FAPI_UL_SCH_CQIRI_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE];
				pduInfo->ulSCHPduInfo.ulHandle = htonl(userInfo->ulHandle);

				if((userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH)||(userInfo->macLayerState == WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH))
				{
					pduInfo->ulSCHPduInfo.usSize = htons(LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_NAS_MSG_SIZE);
				}
				else if((userInfo->macLayerState == ACK_RECEIVED_FOR_RRC_CONN_REL)||(userInfo->macLayerState == WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL))
				{
					pduInfo->ulSCHPduInfo.usSize = htons(LTE_MAC_UL_GRANT_SIZE_FOR_RLC_ACK_FOR_CONN_REL_MSG);
				}
				else
				{
					logPrint(LOG_ERR, "Not handling UL in this State of LTE-MAC=%d\n",userInfo->macLayerState );
					assert(0);
				}

				pduInfo->ulSCHPduInfo.usRnti = htons(userInfo->crnti);
				pduInfo->ulSCHPduInfo.byRbStart = (userInfo->ulRiv % bwToPrb[lteSelectedBandwidth]) ;
				pduInfo->ulSCHPduInfo.byNumOfRB = (userInfo->ulRiv / bwToPrb[lteSelectedBandwidth]) + 1 ;
				if((lteSelectedBandwidth == LTE_BW_N6)&&(userInfo->ulRiv == 11))
				{
					pduInfo->ulSCHPduInfo.byRbStart = 0;
					pduInfo->ulSCHPduInfo.byNumOfRB = 6;
				}
				pduInfo->ulSCHPduInfo.byModulationType = userInfo->ulModulationType;
				pduInfo->ulSCHPduInfo.byCyclicShift2forDMRS = 0;
				pduInfo->ulSCHPduInfo.byFreqHoppingenabledFlag = 0; // disabled
				pduInfo->ulSCHPduInfo.byFreqHoppingBits = 0;
				pduInfo->ulSCHPduInfo.byNewDataIndication = userInfo->ndiUl;
				pduInfo->ulSCHPduInfo.byRedundancyVersion = 0;
				pduInfo->ulSCHPduInfo.byHarqProcessNumber = 0;
				pduInfo->ulSCHPduInfo.byUlTxMode = 0; // SISO mode
				pduInfo->ulSCHPduInfo.byCurrentTxNB = 0;
				pduInfo->ulSCHPduInfo.byNSRS = 0; // No Overlap

				// CQI Info
				pduInfo->cqiRiInfo.byDeltaOffsetCQI = LTE_PERIODIC_CQI_OFFSET;
				pduInfo->cqiRiInfo.byDeltaOffsetRI = LTE_PERIODIC_RI_OFFSET;
				pduInfo->cqiRiInfo.byDlCqiPmiSizeRankGT_1 = 4;
				pduInfo->cqiRiInfo.byDlCqiPmiSizeRank_1 = 4;
				pduInfo->cqiRiInfo.byRiSize = 0;

				// InitTxParam
				pduInfo->initialTxParamInfo.byNSRSInitial = 0;
				pduInfo->initialTxParamInfo.byInitialNumOfRB = pduInfo->ulSCHPduInfo.byNumOfRB;
				pduSize = SIZE_TOCT_FAPI_UL_SCH_CQIRI_PDU_INFO;
			}
			break;

			case eFAPI_UCI_HARQ:
			{

				if(lteDuplxMode)
				{
					// LTE TDD Changes for HARQ
					tOCT_FAPI_UCI_HARQ_PDU_INFO_TDD *uciHarqPduInfo = (tOCT_FAPI_UCI_HARQ_PDU_INFO_TDD*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE];
					uciHarqPduInfo->ulHandle = htonl(userInfo->ulHandle);
					uciHarqPduInfo->usRnti = htons(userInfo->crnti);

					uciHarqPduInfo->harqInfo.byHarqSize =  1; // Always 1 in siso mode
					uciHarqPduInfo->harqInfo.byAcknackMode = 0; // Bundling
					uciHarqPduInfo->harqInfo.byNumOfPUCCHResource = 1;
					uciHarqPduInfo->harqInfo.usN_PUCCH_1_0 = htons(CalculateTddPucchIndex(userInfo , sfNsf));
					uciHarqPduInfo->harqInfo.usN_PUCCH_1_1 = 0;
					uciHarqPduInfo->harqInfo.usN_PUCCH_1_2 = 0;
					uciHarqPduInfo->harqInfo.usN_PUCCH_1_3 = 0;
					pduSize = SIZE_TOCT_FAPI_UCI_HARQ_PDU_INFO_TDD;
				}
				else
				{
					tOCT_FAPI_UCI_HARQ_PDU_INFO *uciHarqPduInfo = (tOCT_FAPI_UCI_HARQ_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE];
					uciHarqPduInfo->ulHandle = htonl(userInfo->ulHandle);
					uciHarqPduInfo->usRnti = htons(userInfo->crnti);
					uciHarqPduInfo->harqInfo.usPucchIndex = htons(userInfo->cceIndex[((LTE_MAX_SUB_FRAME_NUMBER + (sfNsf & 0x000F) - 4) % LTE_MAX_SUB_FRAME_NUMBER)] + LTE_PUCCH_AN);
					uciHarqPduInfo->harqInfo.byHarqSize = 1; // Always 1 in siso mode
					pduSize = SIZE_TOCT_FAPI_UCI_HARQ_PDU_INFO;
				}
			}
			break;

			case eFAPI_UCI_SR_HARQ:
			{
				if(lteDuplxMode)
				{
					tOCT_FAPI_UCI_SRHARQ_PDU_INFO_TDD *uciSrHarqPduInfoTdd = (tOCT_FAPI_UCI_SRHARQ_PDU_INFO_TDD*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE];
					uciSrHarqPduInfoTdd->ulHandle = htonl(userInfo->ulHandle);
					uciSrHarqPduInfoTdd->usRnti = htons(userInfo->crnti);
					uciSrHarqPduInfoTdd->srInfo.usPucchIndex = htons(LTE_DEDICATED_MODE_PUCCH_RESOURCE_INDEX);
						
					uciSrHarqPduInfoTdd->harqInfo.byHarqSize =	1; // Always 1 in siso mode
					uciSrHarqPduInfoTdd->harqInfo.byAcknackMode = 0; // Bundling
					uciSrHarqPduInfoTdd->harqInfo.byNumOfPUCCHResource = 1;
					uciSrHarqPduInfoTdd->harqInfo.usN_PUCCH_1_0 = htons(CalculateTddPucchIndex(userInfo , sfNsf));
					uciSrHarqPduInfoTdd->harqInfo.usN_PUCCH_1_1 = 0;
					uciSrHarqPduInfoTdd->harqInfo.usN_PUCCH_1_2 = 0;
					uciSrHarqPduInfoTdd->harqInfo.usN_PUCCH_1_3 = 0;
					pduSize = SIZE_TOCT_FAPI_UCI_SRHARQ_PDU_INFO_TDD;
				}
				else
				{
					tOCT_FAPI_UCI_SRHARQ_PDU_INFO *uciSrHarqPduInfo = (tOCT_FAPI_UCI_SRHARQ_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE];
					uciSrHarqPduInfo->ulHandle = htonl(userInfo->ulHandle);
					uciSrHarqPduInfo->usRnti = htons(userInfo->crnti);
					uciSrHarqPduInfo->srInfo.usPucchIndex = htons(LTE_DEDICATED_MODE_PUCCH_RESOURCE_INDEX);
					uciSrHarqPduInfo->harqInfo.byHarqSize = 1;
					uciSrHarqPduInfo->harqInfo.usPucchIndex = htons(userInfo->cceIndex[((LTE_MAX_SUB_FRAME_NUMBER + (sfNsf & 0x000f) - 4) % LTE_MAX_SUB_FRAME_NUMBER)] + LTE_PUCCH_AN);
					pduSize = SIZE_TOCT_FAPI_UCI_SRHARQ_PDU_INFO;
				}
				
			}
			break;

#ifdef LTE_USE_SR
			case eFAPI_UCI_SR:
			{
				tOCT_FAPI_UCI_SR_PDU_INFO *uciSrPduInfo = (tOCT_FAPI_UCI_SR_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_UL_CONFIG_PDU_INFO_BASE];
				uciSrPduInfo->usRnti = htons(userInfo->crnti);
				uciSrPduInfo->ulHandle = htonl(userInfo->ulHandle);
				uciSrPduInfo->srInfo.usPucchIndex = htons(LTE_DEDICATED_MODE_PUCCH_RESOURCE_INDEX);
				pduSize = SIZE_TOCT_FAPI_UCI_SR_PDU_INFO;
			}
			break;
#endif
			default:
			{
				assert(0);
			}
			break;
		}
		ulPdu->byUlConfigPduSize = ulPdu->byUlConfigPduSize + pduSize;
		msgLenth = msgLenth + ulPdu->byUlConfigPduSize;

	}
	ulConfigReq->usUlConfigLen = htons(msgLenth);
	lteFapiMsg->msgId = PHY_UL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);

	return msgBuf;
}


void ulschCcchSduHandler(lteUserInfo* userInfo, ltePduMsgStruct* sdu)
{
	if((sdu->msg != NULL)&&
           (sdu->N_bits >= LTE_SIZE_OF_CONTENTION_RES_ID*8)&&
           (userInfo->macLayerState == RACH_RESPONSE_SENT))
	{
		uint8 *dlConfigReq = NULL , *txDataReq = NULL ;
		uint16 sfNsf = 0;
		ltePduMsgStruct		   encodedPdu = {0};
		lteUlCCCHMsgStruct ulCcchMsg;
		memset(&ulCcchMsg, 0, sizeof(lteUlCCCHMsgStruct));

		decodeCcchData(sdu->msg, sdu->N_bits/8, &ulCcchMsg);
        userInfo->emergencyCallAttempted = ulCcchMsg.emergencyCall;

        if (lteDuplxMode)
        {
           sfNsf = lteGetCurrentSfNSbfn();
           checkAndCorrectNextTddUlDlSubframe(&sfNsf , 4 , TRUE); // Contention Resolution Msg DL : 4
        }
        else
        {
           checkAndCorrectNextDlSubframe(&sfNsf , 8);
        }

        encodedPdu.msg = userInfo->macPduBuf;
        memset(encodedPdu.msg , 0 , 10);
        userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_CONTENTION_RESOLUTION_CARRYING_DL_RIV];
        if(lteSelectedBandwidth > LTE_BW_N15)
        {
           userInfo->dlMcs = LTE_MAC_CONTENTION_RESOLUTION_CARRYING_DL_MCS;
        }
        else
        {
           userInfo->dlMcs = LTE_MAC_BW_143_CONTENTION_RESOLUTION_CARRYING_DL_MCS;
        }

        userInfo->dlModulationType = eFAPI_QPSK; // QPSK

        //Build Contention Resolution message
    	mac_pdu.N_subheaders = 1;
    	mac_pdu.subheader[0].lcid = LTE_MAC_DLSCH_UE_CONTENTION_RESOLUTION_ID_LCID;
    	mac_pdu.chan_type = LTE_MAC_CHAN_TYPE_DLSCH;
    	memcpy(mac_pdu.subheader[0].payload.ue_con_res_id.id , sdu->msg , LTE_SIZE_OF_CONTENTION_RES_ID);
        encodeDlMacPdu(&mac_pdu, &encodedPdu);
        userInfo->macPduLen = 7; //(encodedPdu.N_bits / 8); //7 bytes length

        //Build Dl-Config Req for sending RAR , (keep track of DL-PRBs)
        dlConfigReq = buildLteDlConfigReq(userInfo , sfNsf);

        //Build Tx-Req for Contention Resolution message
        txDataReq = buildLteTxDataReq(userInfo , sfNsf);
        //Put all messages in the scheduler bins for the current subframe + 2 bin
        pushToDlConfigReqQ(sfNsf, dlConfigReq);
        pushToTxDataReqQ(sfNsf, txDataReq);

        //timerStop(&userInfo->tmr);
        if(TRUE == isTimerRunning(&userInfo->tmr))
        {
           timerStop(&userInfo->tmr);
        }

        timerStart(&userInfo->tmr, TIMER_FOR_WAIT_RRC_CONN_SETUP, 
                   0, lteUserInfoTimerCbFunction, userInfo);

		if(LTE_UL_CCCH_RRC_CONN_REQ == ulCcchMsg.msgType)
		{
            logPrint(LOG_DEBUG , "RRC Connection Request CRNTI = %d MAC-State = %d \n", 
                     userInfo->crnti , userInfo->macLayerState);

            userInfo->macLayerState = RRC_CONN_REQ_RECEIVED_CONTENTION_RESOLUTION_SENT;
            prepareUlMessageAfterSendingDlTxReq(userInfo, sfNsf);
		}
		else if(LTE_UL_CCCH_RRC_CONN_REESTAB== ulCcchMsg.msgType)
		{
            logPrint(LOG_DEBUG , "RRC Connection Reestablishment CRNTI = %d MAC-State = %d\n",
                     userInfo->crnti , userInfo->macLayerState);

            userInfo->macLayerState = RRC_CONN_REESTAB_RECEIVED_CONTENTION_RESOLUTION_SENT;
            prepareUlMessageAfterSendingDlTxReq(userInfo, sfNsf);
		}
        else
        {
		    logPrint(LOG_DEBUG , "ulschCcchSduHandler CCCH Msg Type = %d is not handled in state = %d CRNTI = %d \n", 
                             ulCcchMsg.msgType, userInfo->macLayerState , userInfo->crnti);

            if(userInfo->macLayerState >= WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)
            {
				//Delete this user now
				buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
		    }
		
            if(TRUE == isTimerRunning(&userInfo->tmr))
               timerStop(&userInfo->tmr);

            userInfo->continuousUlGrant = FALSE;
            userDeleteUsingCrnti(userInfo->crnti, TRUE);
       }
	}
	else
	{
           logPrint(LOG_DEBUG , "ulschCcchSduHandler CCCH PDU is not handled in state = %d CRNTI = %d \n",
                    userInfo->macLayerState , userInfo->crnti);
           if(userInfo->macLayerState >= WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)
           {
              //Delete this user now
              buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
           }
		
           if(TRUE == isTimerRunning(&userInfo->tmr))
              timerStop(&userInfo->tmr);
		
           userInfo->continuousUlGrant = FALSE;
           userDeleteUsingCrnti(userInfo->crnti, TRUE);
	}
}

void ulschDcchSduHandler(lteUserInfo* userInfo,  ltePduMsgStruct* sdu)
{
	//logPrint(LOG_DEBUG , "ulschDcchSduHandler MacLayerState = %d , SdU Bytes = %d\n" , userInfo->macLayerState , sdu->N_bits/8);
	if(userInfo->crnti != 0)
	{
		if(userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)
		{
		    if(TRUE == isTimerRunning(&userInfo->tmr))
				timerStop(&userInfo->tmr);
		}
		if(userInfo->macLayerState >= WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL)
		{
			userInfo->continuousUlGrant = FALSE;
			//userInfo->macLayerState = LTE_NULL_STATE;
			 //logPrint(LOG_DEBUG , " MacLayerState = %d , CRNTI :%d \n" , userInfo->macLayerState , userInfo->crnti);
			//userDeleteUsingCrnti(userInfo->crnti, TRUE);
		}

		//logPrint(LOG_DEBUG , "ulschDcchSduHandler UlSch SDU Size = %d\n" , sdu->N_bits/8);

		if((sdu->msg != NULL)&&(sdu->N_bits >= 16)&&(lteRlcUlDchDataHandler(sdu , userInfo) != 0))
		{
			logPrint(LOG_DEBUG , "Decoding Error for RLC , MacLayerState = %d\n" , userInfo->macLayerState);
		}
	}

	return;
}

void ulschCrntiHandler(lteUserInfo* userInfo, lteMacCrntiStruct* crnti)
{
	lteUserInfo* info = NULL;
	//First Check if there is any context based on new CRNTI in RACH response send state
	//Change the crnti in the userInfo context
	//logPrint(LOG_DEBUG , "ulschCrntiHandler , New CRNTI = %d , Old CRNTI = %d\n", crnti->c_rnti , userInfo->crnti);
	userInfo->pdcchOrderSent = TRUE;
	info = userFindUsingCrnti(crnti->c_rnti);
	if((info != NULL)&&(info->macLayerState > WAITING_FOR_RRC_CONN_COMPLETE))
	{
		logPrint(LOG_DEBUG , "ulschCrntiHandler Found context with this CRNTI = %d ,  Mac-State = %d \n", info->crnti , info->macLayerState);
		triggerRrcReconfigReqFromRRC(info);
	}

	if(crnti->c_rnti != userInfo->crnti)
	{
		//Second delete the old crnti based context.
		if((isTimerRunning(&userInfo->tmr) == TRUE))
		{
			timerStop(&userInfo->tmr);
		}
		userDeleteUsingCrnti(userInfo->crnti, TRUE);
	}

}

void checkAndCorrectNextDlSubframe(uint16 *sfNsf, uint8 offset)
{
	uint16 currentSfn = 0 ; uint8 currentSbfn = 0 , tmp = 0 ;
	//Get the Current sfn and subframe number
	uint16 cSfnSf = lteGetCurrentSfNSbfn();
	currentSfn = ((cSfnSf)>>4) & 0x0FFF;
	currentSbfn = ((cSfnSf) & 0x000F) % LTE_MAX_SUB_FRAME_NUMBER;

	if(((currentSbfn + offset)%2) == 0)
	{
		offset = offset + 1; // Send it only on odd subframes
	}
	tmp = currentSbfn + offset;
	if(tmp >= (2*LTE_MAX_SUB_FRAME_NUMBER))
	{
		currentSfn = (currentSfn + 2)%LTE_MAX_SYSTEM_FRAME_NUMBER;
	}
	else if((tmp >= LTE_MAX_SUB_FRAME_NUMBER) && (tmp < (2*LTE_MAX_SUB_FRAME_NUMBER)))
	{
		currentSfn = (currentSfn + 1)%LTE_MAX_SYSTEM_FRAME_NUMBER;
	}
	else
	{}
	currentSbfn = (currentSbfn + offset)%LTE_MAX_SUB_FRAME_NUMBER;

	*sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
	//logPrint(LOG_DEBUG , "Current = %04x , Allocated SfNSf = %04x \n" ,cSfnSf, *sfNsf);
	return ;
}

void checkAndCorrectNextDlSubframeWithMeasGap(uint16 *sfNsf, uint8 offset)
{
        uint16 currentSfn = 0 ; uint8 currentSbfn = 0 ;
        //Get the Current sfn and subframe number
        uint16 cSfnSf = lteGetCurrentSfNSbfn();
        currentSfn = ((cSfnSf)>>4) & 0x0FFF;
        currentSbfn = ((cSfnSf) & 0x000F) % LTE_MAX_SUB_FRAME_NUMBER;

        if((currentSbfn + offset)%2 == 0)
        {
                offset = offset + 1; // Send it only on odd subframes
        }
        if((currentSbfn + offset) >= LTE_MAX_SUB_FRAME_NUMBER)
        {
                currentSfn = (currentSfn + 1)%LTE_MAX_SYSTEM_FRAME_NUMBER;
        }
        currentSbfn = (currentSbfn + offset)%LTE_MAX_SUB_FRAME_NUMBER;

        if((currentSfn % 4) == 0)
        {
            currentSfn = (currentSfn + 1)%LTE_MAX_SYSTEM_FRAME_NUMBER;
            currentSbfn = 2; 
        }

        if(((currentSfn % 4) == 3) && currentSbfn > 5)
        {
            currentSfn = (currentSfn + 2)%LTE_MAX_SYSTEM_FRAME_NUMBER;
            currentSbfn = 2;
        } 

        *sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
        logPrint(LOG_DEBUG , "Meas GAP Current = %d , Allocated SfNSf = %d \n" ,cSfnSf, *sfNsf);
        return ;
}

void buildAndSendRrcConnReestabReject(lteUserInfo* userInfo)
{
	uint8 *dlConfigReq = NULL , *txDataReq = NULL; //, srIndex = 0;
	//uint8 tmp = 0;
	uint16 sfNsf = 0;
	ltePduMsgStruct		   encodedPdu = {0};
	
	encodedPdu.msg = userInfo->macPduBuf;
	memset(encodedPdu.msg , 0 , 30);
	memset(&mac_pdu , 0 , sizeof(lteMacPduStruct));
	
	userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_DL_GRANT_FOR_RLC_ACK];
	if(lteSelectedBandwidth > LTE_BW_N15)
	{
		userInfo->dlMcs = LTE_MAC_RLC_ACK_CARRYING_DL_MCS;
	}
	else
	{
		userInfo->dlMcs = LTE_MAC_BW_143_RLC_ACK_CARRYING_DL_MCS;
	}
	userInfo->dlModulationType = eFAPI_QPSK; // QPSK


	if (lteDuplxMode) // TDD Case : Currently for UlDL : 1 , DL Subframe
	{
		sfNsf = lteGetCurrentSfNSbfn();
		checkAndCorrectNextTddUlDlSubframe(&sfNsf , 4 , TRUE);
	}
	else
	{
	    checkAndCorrectNextDlSubframe(&sfNsf , 7);
	}

        /* Fill MAC PDU */
	mac_pdu.N_subheaders = 2;
	mac_pdu.subheader[0].lcid   = LTE_MAC_DLSCH_CCCH_LCID;
	mac_pdu.subheader[0].payload.sdu.msg = asn1EncodedRrcConnReestabReject;
	mac_pdu.subheader[0].payload.sdu.N_bits = asn1EncodedRrcConnReestabRejectLen * 8;
	mac_pdu.subheader[1].lcid   = LTE_MAC_DLSCH_PADDING_LCID;
	mac_pdu.chan_type = LTE_MAC_CHAN_TYPE_DLSCH;


	encodeDlMacPdu(&mac_pdu, &encodedPdu);
	memcpy(encodedPdu.msg + encodedPdu.N_bits/8, 
               asn1EncodedRrcConnReestabReject, 
               asn1EncodedRrcConnReestabRejectLen);
	userInfo->macPduLen = LTE_MAC_RLC_ACK_PDU_SIZE;

        //Build DL Config Request for RRC Connection Reestablishment Reject Message
	dlConfigReq = buildLteDlConfigReq(userInfo , sfNsf);

	//Build Tx-Req for RRC Connection Reestablishment Message
	txDataReq = buildLteTxDataReq(userInfo , sfNsf);

	pushToDlConfigReqQ(sfNsf, dlConfigReq);
	pushToTxDataReqQ(sfNsf, txDataReq);
	userInfo->macLayerState = RRC_CONN_REESTAB_REJECT_SENT;

	if(TRUE == isTimerRunning(&userInfo->tmr))
	{
		timerStop(&userInfo->tmr);
	}

   	timerStart(&userInfo->tmr, TIMER_FOR_WAIT_RRC_CONN_SETUP, 0, lteUserInfoTimerCbFunction, userInfo);
	logPrint(LOG_DEBUG,"RrcConnReestabReject sent for CRNTI = %d on sfnSf = %04x \n",
                 userInfo->crnti, sfNsf);
	prepareUlMessageAfterSendingDlTxReq(userInfo, sfNsf);
	return;
}

void buildAndSendRrcConnSetup(lteUserInfo* userInfo)
{
	uint8 *dlConfigReq = NULL , *txDataReq = NULL; //, srIndex = 0;
	//uint8 tmp = 0;
	uint16 sfNsf = 0;
	ltePduMsgStruct		   encodedPdu = {0};
	encodedPdu.msg = userInfo->macPduBuf;
	memset(encodedPdu.msg , 0 , 36);
	memset(&mac_pdu , 0 , sizeof(lteMacPduStruct));
	userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_RRC_CONN_SETUP_CARRYING_DL_RIV];
	if(lteSelectedBandwidth > LTE_BW_N15)
	{
		userInfo->dlMcs = LTE_MAC_RRC_CONN_SETUP_CARRYING_DL_MCS;
	}
	else
	{
		userInfo->dlMcs = LTE_MAC_BW_143_RRC_CONN_SETUP_CARRYING_DL_MCS;
	}
	userInfo->dlModulationType = eFAPI_QPSK; // QPSK

#ifdef LTE_USE_SR
	uint16 srIndex = 0;
	if(userInfo->srConfigIndex == LTE_INVALID_SR_CONFIG_INDEX)
	{
		getLteSrConfigIndex(userInfo);
		if(userInfo->srConfigIndex  == LTE_INVALID_SR_CONFIG_INDEX)
		{
			logPrint(LOG_DEBUG , "No SR Index available ignoring this user for now \n");
			userDeleteUsingCrnti(userInfo->crnti, TRUE);
			return;
		}
		if(lteDuplxMode)
		{	
			sfNsf = lteGetCurrentSfNSbfn();
			srIndex = convertToRealSrTddConfigIndex(userInfo->srConfigIndex) + LTE_DEDICATED_MODE_SR_CONFIG_INDEX_START_TDD;
		}
		else
			srIndex = convertToRealSrConfigIndex(userInfo->srConfigIndex) + LTE_DEDICATED_MODE_SR_CONFIG_INDEX_START;
	}
	else
	{
		logPrint(LOG_DEBUG , "Sending second time RrcConnSetup \n");
	}
#endif
  //  logPrint(LOG_DEBUG ,"SrConfigIndex = %d , CRNTI = %d , MacLayerState = %d \n",srIndex, userInfo->crnti , userInfo->macLayerState);

	if (lteDuplxMode) // TDD Case : Currently for UlDL : 1 , DL Subframe
	{
		sfNsf = lteGetCurrentSfNSbfn();
		checkAndCorrectNextTddUlDlSubframe(&sfNsf , 4 , TRUE);
	}
	else
	{
	    	checkAndCorrectNextDlSubframe(&sfNsf , 7);
	}



	if (lteDuplxMode) //TDD : Update SR Config index in RRC Conn Setup 
	{
	   // generateRrcConnectionSetupTDD(LTE_DEDICATED_MODE_SR_CONFIG_INDEX_START_TDD); //==>change for TDD
	    mac_pdu.N_subheaders = 2;
	    mac_pdu.subheader[0].lcid   = LTE_MAC_DLSCH_CCCH_LCID;
	    mac_pdu.subheader[0].payload.sdu.msg = asn1EncodedRrcConnectionSetupTdd;
	    mac_pdu.subheader[0].payload.sdu.N_bits = asn1EncodedRrcConnectionSetupTddLen*8;
	    mac_pdu.subheader[1].lcid   = LTE_MAC_DLSCH_PADDING_LCID;
	    mac_pdu.chan_type = LTE_MAC_CHAN_TYPE_DLSCH;

	    encodeDlMacPdu(&mac_pdu, &encodedPdu);
	    memcpy(encodedPdu.msg + encodedPdu.N_bits/8 , asn1EncodedRrcConnectionSetupTdd , asn1EncodedRrcConnectionSetupTddLen);
		userInfo->macPduLen = LTE_MAC_RRC_CONN_SETUP_PDU_SIZE ; // adjusted to 208 bits

#ifdef LTE_USE_SR
	    uint8 idx2 = encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 2];
	    uint8 idx1 = encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 1];
	    int srPdu =  ((idx2<<8)|(idx1&0xFF)) ;
	    uint8 diff = srIndex - LTE_DEDICATED_MODE_SR_CONFIG_INDEX_START_TDD;
		if(diff)
		{
			srPdu = srPdu + (0x0020)*diff ;
			// logPrint(LOG_DEBUG,"SR Pdu ID: %d ==> %04x\n",srIndex ,srPdu);
		}
		idx2 = ((srPdu >> 8)&(0xFF));
		idx1 = srPdu&(0xFF);
	   encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 2] = idx2;
	   encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 1] = idx1;
	   logPrint(LOG_DEBUG,"SR Pdu ID: %d ==> %02x,%02x , \n",srIndex, idx2, idx1);
#endif
	}
	else
	{
		mac_pdu.N_subheaders = 2;
		mac_pdu.subheader[0].lcid   = LTE_MAC_DLSCH_CCCH_LCID;
		mac_pdu.subheader[0].payload.sdu.msg = asn1EncodedRrcConnectionSetup;
		mac_pdu.subheader[0].payload.sdu.N_bits = asn1EncodedRrcConnectionSetupLen*8;
		mac_pdu.subheader[1].lcid   = LTE_MAC_DLSCH_PADDING_LCID;
		mac_pdu.chan_type = LTE_MAC_CHAN_TYPE_DLSCH;

		encodeDlMacPdu(&mac_pdu, &encodedPdu);
		memcpy(encodedPdu.msg + encodedPdu.N_bits/8 , asn1EncodedRrcConnectionSetup , asn1EncodedRrcConnectionSetupLen);
		userInfo->macPduLen = LTE_MAC_RRC_CONN_SETUP_PDU_SIZE ; // adjusted to 208 bits
#ifdef LTE_USE_SR
		// Now change the SR index to one newly assigned
		encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 2] = srIndex;
		encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 2] = encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 2] >> 2;
		tmp = (srIndex << 6);
		encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 1] = (encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 1] & 0x3F);
		encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 1] = tmp | encodedPdu.msg[encodedPdu.N_bits/8 + asn1EncodedRrcConnectionSetupLen - 1];

		logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",encodedPdu.msg[0],encodedPdu.msg[1],encodedPdu.msg[2],encodedPdu.msg[3],encodedPdu.msg[4],encodedPdu.msg[5]);
		logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",encodedPdu.msg[6],encodedPdu.msg[7],encodedPdu.msg[8],encodedPdu.msg[9],encodedPdu.msg[10],encodedPdu.msg[11]);
		logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",encodedPdu.msg[12],encodedPdu.msg[13],encodedPdu.msg[14],encodedPdu.msg[15],encodedPdu.msg[16],encodedPdu.msg[17]);
		logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",encodedPdu.msg[18],encodedPdu.msg[19],encodedPdu.msg[20],encodedPdu.msg[21],encodedPdu.msg[22],encodedPdu.msg[23]);
		logPrint(LOG_DEBUG,"%02x,%02x,%02x,%02x,%02x,%02x\n",encodedPdu.msg[24],encodedPdu.msg[25],encodedPdu.msg[26],encodedPdu.msg[27],encodedPdu.msg[28],encodedPdu.msg[29]);
		logPrint(LOG_DEBUG,"%02x,%02x \n",encodedPdu.msg[30],encodedPdu.msg[31]);
#endif
	}

	//Build Dl-Config Req for sending RAR , (keep track of DL-PRBs)
	dlConfigReq = buildLteDlConfigReq(userInfo , sfNsf);
	//Build Tx-Req for RRC Connection Setup message
	txDataReq = buildLteTxDataReq(userInfo , sfNsf);
	pushToDlConfigReqQ(sfNsf, dlConfigReq);
	pushToTxDataReqQ(sfNsf, txDataReq);
	userInfo->macLayerState = RRC_CONN_SETUP_SENT;
	//timerStop(&userInfo->tmr);
	if(TRUE == isTimerRunning(&userInfo->tmr))
	{
		timerStop(&userInfo->tmr);
	}

   	timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP , 0 , lteUserInfoTimerCbFunction, userInfo);
	logPrint(LOG_DEBUG,"RrcConnSetup For Crnti = %d Sent on sfnSf = %04x \n" ,userInfo->crnti, sfNsf);
	prepareUlMessageAfterSendingDlTxReq(userInfo, sfNsf);
	return;
}

//This function will be called out from Main thread
void lteUserInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr)
{
	lteUserInfo *info = (lteUserInfo*)infoPtr;
	if(info != NULL) // For now just clean up that user
	{
		//logPrint(LOG_DEBUG , "Timer Expired for CRNTI = %d , State = %d \n", info->crnti , info->macLayerState);
		if(info->macLayerState == WAITING_TO_START_CONT_GRANT)
		{
			info->continuousUlGrant = 0xFF;
		}
		else if((info->macLayerState <= WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)||((info->macLayerState >= WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL)))
		{
			info->continuousUlGrant = FALSE;
			sendDeleteCntxtMsgToSelf(info);
		}
		else if((info->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH)&&(info->silentCallStarted == FALSE))
		{
			logPrint(LOG_DEBUG , "Checking any pending message in Que for CRNTI = %d Mac-State = %d \n",info->crnti, info->macLayerState);
			buildAndSendRlcMsgToRrc(info , LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E);
		}
		else
		{
			/*if(info->silentCallStarted == TRUE)
			{
				buildAndSendPdcchOrderReq(info);
			}
			else*/
			{
				logPrint(LOG_DEBUG , "RLC-RESET CRNTI = %d Mac-State = %d \n",info->crnti, info->macLayerState);
				info->continuousUlGrant = FALSE;
				buildAndSendRlcMsgToRrc(info , LTE_MSG_RLC_RESET_REQ_E);
				sendDeleteCntxtMsgToSelf(info);
			}
		}
	}
}

const uint16 pucch[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER] =	{
																		{4,6,0,0,0,4,6,0,0,0},
																		{7,6,0,0,4,7,6,0,0,4},
																		{7,6,0,4,8,7,6,0,4,8},
																		{4,11,0,0,0,7,6,6,5,5},
																		{12,11,0,0,8,7,7,6,5,4},
																		{12,11,0,9,8,7,6,5,4,13},
																		{7,7,0,0,0,7,7,0,0,5},
																	};

//This function can be called out from Main thread
void prepareUlMessageAfterSendingDlTxReq(lteUserInfo* userInfo , uint16 sfNsf)
{
	uint8 *ulConfigReq = NULL , currentSbfn = (sfNsf & 0x000F);
	uint16 currentSfn = (sfNsf >> 4) & 0x0FFF;
	listNode *tail = NULL;

	switch(userInfo->macLayerState)
	{
		case RACH_RESPONSE_SENT:
		{
			if(lteDuplxMode)
			{
				checkAndCorrectNextTddUlDlSubframe(&sfNsf , 8 , FALSE);	// MSG3 at UL:7			
			}
			else
			{
				if((currentSbfn + 6) >= LTE_MAX_SUB_FRAME_NUMBER)
				{
					currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
				}
				currentSbfn = (currentSbfn + 6) % LTE_MAX_SUB_FRAME_NUMBER;
				sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
			}

			//Put the Dummy-Dl-Config & Ul-Config Req with ULSCH Pdu in the current + 8 subframe bin
			ulConfigReq = buildLteUlConfigReq(userInfo , sfNsf , eFAPI_ULSCH);
		}
		break;

		case WAITING_FOR_RRC_CONN_COMPLETE: // Cases where SR is expected
		case ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH:
		case ACK_RECEIVED_FOR_RRC_CONN_REL:
		{
			if (lteDuplxMode)
			{
				checkAndCorrectNextTddUlDlSubframe(&sfNsf , 4 , FALSE);	
			}
			else
			{
				if((currentSbfn + 4) >= LTE_MAX_SUB_FRAME_NUMBER)
				{
					currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
				}
				currentSbfn = (currentSbfn + 4) % LTE_MAX_SUB_FRAME_NUMBER;
				sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
			}

			//Put the Dummy-Dl-Config & Ul-Config Req with ULSCH Pdu in the current + 8 subframe bin
			ulConfigReq = buildLteUlConfigReq(userInfo , sfNsf , eFAPI_ULSCH);
		}
		break;

		case RRC_CONN_REQ_RECEIVED_CONTENTION_RESOLUTION_SENT: // Cases where HARQ
		case RRC_CONN_REESTAB_RECEIVED_CONTENTION_RESOLUTION_SENT: // Cases where HARQ
		case RRC_CONN_SETUP_SENT:
		case RRC_CONN_REESTAB_REJECT_SENT:
		case WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH:
		case WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL:
		{
			if (lteDuplxMode)
			{
			      //ULDL : 1 , Table 10.1-1: 36.213
/*			      
Table 10.1-1: Downlink association set index :   for TDD
UL-DL
Configuration	Subframe n
	0	1	2	3	4	5	6	7	8	9
0	-	-	6	-	4	-	-	6	-	4
1	-	-	7, 6	4	-	-	-	7, 6	4	-
2	-	-	8, 7, 4, 6	-	-	-	-	8, 7, 4, 6	-	-
3	-	-	7, 6, 11	6, 5	5, 4	-	-	-	-	-
4	-	-	12, 8, 7, 11	6, 5, 4, 7	-	-	-	-	-	-
5	-	-	13, 12, 9, 8, 7, 5, 4, 11, 6	-	-	-	-	-	-	-
6	-	-	7	7	5	-	-	7	7	-
*/
				if (ULDL[LTE_TDD_UD_CONFIG][currentSbfn] == LTE_TDD_DOWNLINK)
				{
					userInfo->pucch_k = pucch[LTE_TDD_UD_CONFIG][currentSbfn];
					userInfo->dl_allocation[(currentSbfn) % LTE_MAX_SUB_FRAME_NUMBER] = 1;
					checkAndCorrectNextTddUlDlSubframe(&sfNsf , userInfo->pucch_k , FALSE);
					//logPrint(LOG_DEBUG , "PUCCH K Value = %d ,sfNsf = %04x  \n", userInfo->pucch_k , sfNsf);					
				}

			}
			else
			{
				if((currentSbfn + 4) >= LTE_MAX_SUB_FRAME_NUMBER)
				{
					currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
				}
				currentSbfn = (currentSbfn + 4) % LTE_MAX_SUB_FRAME_NUMBER;
				sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
			}

			//Also send UCI-HARQ request after 4 subframes
			currentSfn = (sfNsf >> 4) & 0x0FFF;
			
			if(((currentSfn % (LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY/10)) == 0)&&((sfNsf & 0x000F) == LTE_DEDICATED_MODE_SR_SUBFRAME)) //Then configure UCI_SR_HARQ
			{
				//logPrint(LOG_DEBUG , "UL-Config for eFAPI_UCI_SR_HARQ SFNSF = 0x%04x \n", sfNsf);
				ulConfigReq = buildLteUlConfigReq(userInfo , sfNsf , eFAPI_UCI_SR_HARQ);
			}
			else
			{
				ulConfigReq = buildLteUlConfigReq(userInfo , sfNsf , eFAPI_UCI_HARQ);
			}
		}
		break;
		default:
		{
			logPrint(LOG_ERR ,"prepareUlMessageAfterSendingDlTxReq Uplink message not handled in Mac-State = %d\n" , userInfo->macLayerState);
			return;
		}
		break;
	}
	if(ulConfigReq == NULL)
	{
		return;
	}
	tail = tailForUlConfigReqQ;
	pushMsgToList(&tail ,(void*)ulConfigReq);
	if((headForUlConfigReqQ == NULL)||(tailForUlConfigReqQ == NULL))
	{
		headForUlConfigReqQ = tailForUlConfigReqQ = tail; // Update for the first time
	}
	else
	{
		tailForUlConfigReqQ = tail; // Just update the tail node
	}
	//logPrint(LOG_DEBUG,"Peeking Ul sfnSf = %04x , Mac-State = %d\n , CRNTI = %d " , sfNsf , userInfo->macLayerState , userInfo->crnti);
	return;
}

void createAndPushSrReqToQ(uint16 sfNsf , lteUserInfo* userInfo)
{
	uint8* srReq = NULL;
	listNode *tail = NULL;
	uint8  sbfn = (sfNsf & 0x000F);
	uint16 sfn = ((sfNsf >> 4) & 0x0FFF);
	uint16 offset = ( LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY/10 - (sfn%(LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY/10)) ) ;

	if(offset == 0)
	{
		sfn = sfn + (LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY/10); // Add 8 frames
	}
	else
	{
		sfn = sfn + offset; // Add this offset
	}
	sfn = sfn % LTE_MAX_SYSTEM_FRAME_NUMBER;
	sfNsf = ((sfn<<4)|(sbfn & 0x0F));

	srReq = buildLteUlConfigReq(userInfo ,  sfNsf , eFAPI_UCI_SR);
	tail = tailForUlConfigReqQ;
	pushMsgToList(&tail ,(void*)srReq);
	if((headForUlConfigReqQ == NULL)||(tailForUlConfigReqQ == NULL))
	{
		headForUlConfigReqQ = tailForUlConfigReqQ = tail; // Update for the first time
	}
	else
	{
		tailForUlConfigReqQ = tail; // Just update the tail node
	}

}

void mergeUlConfigReqests(uint8* ulConfig , uint8* newUlConfig)
{
	lteEthernetFrameHeader *lteHdr = (lteEthernetFrameHeader*)ulConfig;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&ulConfig[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_UL_CONFIG_REQUEST *ulConfigRequest = (tOCT_FAPI_UL_CONFIG_REQUEST*)&ulConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	//tOCT_FAPI_UL_CONFIG_PDU_INFO *oldUlPduReq = (tOCT_FAPI_UL_CONFIG_PDU_INFO *)&ulConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST];
	tOCT_FAPI_UL_CONFIG_PDU_INFO *newUlPduReq = (tOCT_FAPI_UL_CONFIG_PDU_INFO *)&newUlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE];

	uint16 offset = ntohs(ulConfigRequest->usUlConfigLen);
	uint8 *oldPtr = NULL , *newPtr = NULL;
	ulConfigRequest->byNumOfPdu++;
	oldPtr = (uint8*)ulConfigRequest;
	oldPtr = oldPtr + offset;
	newPtr = (uint8*)newUlPduReq;
	assert((offset + newUlPduReq->byUlConfigPduSize) < LTE_MAX_SIZE_BUFFER);
	memcpy(oldPtr , newPtr , newUlPduReq->byUlConfigPduSize);
	ulConfigRequest->usUlConfigLen = htons(offset + newUlPduReq->byUlConfigPduSize);
	lteFapiMsg->usMsgLen = htons(ntohs(lteFapiMsg->usMsgLen) + newUlPduReq->byUlConfigPduSize);
	lteHdr->ltePacketLength = htons(ntohs(lteHdr->ltePacketLength) + newUlPduReq->byUlConfigPduSize);
}
void prepareUlConfigReqForNplus1Subframes(uint16 sfn , uint8 sbfn)
{
	uint8* ulConfigReq = NULL , idx = 0 ,i = 0;
	uint8 *ulConfig[LTE_MAX_NO_UL_PDU_PER_TTI*2] = {NULL} , *ulPduPtr = NULL;
	uint16 sfNsf = 0;
	listNode *head = NULL , *tmp = NULL , *prev = NULL ;

    if(exitLteApp == TRUE)
    {
    	return;
    }

	if((sbfn + 1) >= LTE_MAX_SUB_FRAME_NUMBER)
	{
		sfn = (sfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
	}
	sbfn = (sbfn + 1) % LTE_MAX_SUB_FRAME_NUMBER;
	sfNsf = ((sfn<<4)|(sbfn & 0x0F));


#ifdef LTE_USE_SR
	if (lteDuplxMode)
	{
		if((sfn % (LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY_TDD/10)) == 0)
		{
	           	checkAndConfigureTddSchedulingRequest(sfNsf);
		}
	}
	else
	{
		if((sfn % (LTE_DEDICATED_MODE_SR_CONFIG_PERIODICITY/10)) == 0)
		{
			checkAndConfigureSchedulingRequest(sfNsf);
		}// Ignore SR request in case of continuous grant
	}
#endif

	head = headForUlConfigReqQ;
	if(head == NULL)
	{
		ulConfigReq = buildLteUlConfigReq(NULL , sfNsf , eFAPI_INVALID_PDU_TYPE);
	}
	else
	{
		//Search in ulConfig list
		while(head != NULL)
		{
			ulPduPtr = (uint8*)head->msg;
			if(ulPduPtr != NULL)
			{
				tOCT_FAPI_UL_CONFIG_REQUEST *ulConfigPdu = (tOCT_FAPI_UL_CONFIG_REQUEST*)&ulPduPtr[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

				if((ulConfigPdu != NULL)&&(ntohs(ulConfigPdu->usSfnsf) == sfNsf)&&(idx < LTE_MAX_NO_UL_PDU_PER_TTI*2))
				{
					ulConfig[idx] = (uint8*)ulPduPtr;

					if(head == headForUlConfigReqQ)
					{
						//current node matches to head
						headForUlConfigReqQ = head->next;
						if(headForUlConfigReqQ == NULL)
						{
							tailForUlConfigReqQ = NULL;
						}
					}
					else if(head == tailForUlConfigReqQ)
					{
						//current node matches to tail
						tailForUlConfigReqQ = prev;
					}
					else
					{
						// current matched with some in-between node
					}
				    tmp = head;
				    head = head->next;
				    if(prev != NULL)
				    {
					    prev->next = head;
				    }
				    free(tmp);
				    idx = idx + 1;
				}
				else
				{
				   prev = head;
				   if(head != NULL)
				   {
					   head = head->next;
				   }
				}
			}
			else
			{
			   prev = head;
			   if(head != NULL)
			   {
				   head = head->next;
			   }
			}
		}

		if(idx == 0)//UlPDu not found in list
		{
			ulConfigReq = buildLteUlConfigReq(NULL , sfNsf , eFAPI_INVALID_PDU_TYPE);
		}
		else
		{
			uint8* ithUlReq = (uint8*)ulConfig[0];
			ulConfigReq = getUlTxDataBuffer();
			if((ithUlReq == NULL) || (ulConfigReq == NULL))
			{
				return;
			}
			memcpy((uint8*)ulConfigReq , (uint8*)ithUlReq , LTE_MAX_MSG_SIZE );
			ithUlReq = NULL;
			if(idx > 1)
			{
				if(idx > LTE_MAX_NO_UL_PDU_PER_TTI*2)
				{
					idx = LTE_MAX_NO_UL_PDU_PER_TTI*2;
				}

				for(i=1; i<idx;i++)
				{
					//Merge all ulConfigReq into one ulConfigReq
					if(ulConfig[i] != NULL)
					{
						ithUlReq = (uint8*)ulConfig[i];
						mergeUlConfigReqests((uint8*)ulConfigReq , (uint8*)ithUlReq);
						ithUlReq = NULL;
					}
				}
			}
		}
	}
	//Put all messages in the scheduler bins
	pushMacPduToUlSchedulerQ(sbfn , ulConfigReq );

	if(lteDuplxMode == LTE_FDD)
	{
		checkAndPushPagingReqToDlSchedulerQ(sfn , sbfn);
		if(rlcDataIndHandler() == TRUE)
		{
			//if(rlcDataIndHandler() == TRUE)
			{
				rlcDataIndHandler();
			}
		}
	}
	return;
}

void resentDlMacPduOnHarqNackDtx(lteUserInfo* userInfo , uint16 sfNsf)
{
	//Resent the pdu with different redundancy version, taken from queue
	if((userInfo != NULL)&&(userInfo->macLayerState != 0))
	{
		userInfo->rvIndex++;
		if(userInfo->rvIndex < 4)
		{
			uint8 *dlConfigReq = NULL;
			uint8 *txDataReq = NULL;
	
			if(userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)
			{
				userInfo->macLayerState = RRC_CONN_SETUP_SENT;
			}
			else if(userInfo->macLayerState == RRC_CONN_SETUP_SENT)
			{
				userInfo->macLayerState = RRC_CONN_REQ_RECEIVED_CONTENTION_RESOLUTION_SENT;
			}
			else if(userInfo->macLayerState == RRC_CONN_REESTAB_REJECT_SENT)
			{
				userInfo->macLayerState = RRC_CONN_REESTAB_RECEIVED_CONTENTION_RESOLUTION_SENT;
			}

			//Build Dl-Config Req for sending DL-SCH message , (keep track of DL-PRBs)
			dlConfigReq = buildLteDlConfigReq(userInfo , sfNsf);
			//Build Tx-Req for RLC message
			txDataReq = buildLteTxDataReq(userInfo , sfNsf);
			pushToDlConfigReqQ(sfNsf, dlConfigReq);
			pushToTxDataReqQ(sfNsf, txDataReq);
			//timerStop(&userInfo->tmr);
			if(TRUE == isTimerRunning(&userInfo->tmr))
			{
				timerStop(&userInfo->tmr);
			}

			timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP , 0 , lteUserInfoTimerCbFunction, userInfo);
			//logPrint(LOG_DEBUG , "resentDlMacPduOnHarqNackDtx Mac-State = %d , SfNsf = %04x\n",userInfo->macLayerState,sfNsf);
			prepareUlMessageAfterSendingDlTxReq(userInfo, sfNsf);
		}
		else
		{
			if(userInfo->macLayerState >= WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)
			{
				//Delete this user now
				logPrint(LOG_DEBUG , "MAC-RESET Cleaning up Context in State = %d for User = %d \n" , userInfo->macLayerState , userInfo->crnti);
				buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
			}
			if(TRUE == isTimerRunning(&userInfo->tmr))
				timerStop(&userInfo->tmr);
			userInfo->continuousUlGrant = FALSE;
			userDeleteUsingCrnti(userInfo->crnti , TRUE);
		}
	}
	return;
}

#ifdef LTE_USE_SR

void checkAndConfigureSchedulingRequest(uint16 sfNsf)
{
	lteUserInfo* userInfo = NULL;
	uint8 srIndex = (sfNsf & 0x000F);
	while(srIndex < LTE_MAX_USER_SUPPORTED)
	{
		userInfo = getUserContextForSchedulingRequest(srIndex);
		if((userInfo != NULL) && (userInfo->continuousUlGrant == FALSE) && ((userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)||
		  (userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH)||
	      (userInfo->macLayerState == ACK_RECEIVED_FOR_RRC_CONN_REL)))
		{
			createAndPushSrReqToQ(sfNsf ,  userInfo);
			userInfo = NULL;
		}
		srIndex = srIndex + 10;
	}
	return;
}

void checkAndConfigureTddSchedulingRequest(uint16 sfNsf)
{
	lteUserInfo* userInfo = NULL;
	uint8 srIndex = (sfNsf & 0x000F);

#if 0
       if ((srIndex == 2)||(srIndex == 3))
	    srIndex = srIndex-2;
	 else if ((srIndex == 7)||(srIndex == 8))
	    srIndex = srIndex - 5; 
#endif
	srIndex = 0;
		//logPrint(LOG_DEBUG,"SR Debug -3  srIndex = %d \n" , srIndex);	
	while(srIndex < LTE_MAX_USER_SUPPORTED)
	{
		userInfo = getUserContextForSchedulingRequest(srIndex);
		if((userInfo != NULL) && (userInfo->continuousUlGrant == FALSE) && ((userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)||
		  (userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH)||
	      (userInfo->macLayerState == ACK_RECEIVED_FOR_RRC_CONN_REL)))
		{
			//logPrint(LOG_DEBUG,"SR Debug -4  srIndex = %d \n" , srIndex);	
			createAndPushSrReqToQ(sfNsf ,  userInfo);
			userInfo = NULL;
		}
		srIndex = srIndex + 1;
	}
	return;
}
#endif
void buildAndScheduleDlDchRlcPdu(ltePduMsgStruct* pdu , lteUserInfo* userInfo , lteMsgType_e msgType)
{
	uint8 *dlConfigReq = NULL , *txDataReq = NULL ;
	ltePduMsgStruct		   encodedPdu = {0};
	uint16 sfNsf = 0;
	
		if(lteDuplxMode) // TDD Case
		{
			sfNsf = lteGetCurrentSfNSbfn();
			if(userInfo->macLayerState == WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)
			{
				checkAndCorrectNextTddUlDlSubframe(&sfNsf , (4+9) , TRUE);
				//logPrint(LOG_DEBUG , "Sending msg after 4 subframes at %04x \n",sfNsf);
			}
			else
			{
				checkAndCorrectNextTddUlDlSubframe(&sfNsf , 4 , TRUE); // targeting subframe 9
			}

		}
		else // FDD Case
		{
			if(userInfo->measGapStarted == 1)
			{
                checkAndCorrectNextDlSubframeWithMeasGap(&sfNsf , 8);
			}				
			else if(userInfo->macLayerState == WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH)
			{
				checkAndCorrectNextDlSubframe(&sfNsf , (7+9));
				//logPrint(LOG_DEBUG , "Sending msg after 4 subframes at %04x \n",sfNsf);
			}
			else
			{
				checkAndCorrectNextDlSubframe(&sfNsf , 7);
			}
		}
	
	encodedPdu.msg = userInfo->macPduBuf;
	memset(encodedPdu.msg , 0 , LTE_MAX_MAC_PDU_SIZE);
	memset(&mac_pdu , 0 , sizeof(lteMacPduStruct));

	//logPrint(LOG_DEBUG , "buildAndScheduleDlDchRlcPdu CRNTI = %d , LCID = %d , MsgSize = %d \n", userInfo->crnti , userInfo->lcid , pdu->N_bits/8);
	getRivAndMcsFromMessageType(userInfo , msgType);
	userInfo->dlModulationType = eFAPI_QPSK; // QPSK

    mac_pdu.N_subheaders = 2;
    mac_pdu.subheader[0].lcid   = userInfo->lcid;
    mac_pdu.subheader[0].payload.sdu.msg = pdu->msg;
    mac_pdu.subheader[0].payload.sdu.N_bits = pdu->N_bits;
    mac_pdu.subheader[1].lcid   = LTE_MAC_DLSCH_PADDING_LCID;
    mac_pdu.chan_type = LTE_MAC_CHAN_TYPE_DLSCH;

    encodeDlMacPdu(&mac_pdu, &encodedPdu);
    memcpy(encodedPdu.msg + encodedPdu.N_bits/8 , pdu->msg , pdu->N_bits/8);
	//Build Dl-Config Req for sending DL-SCH message , (keep track of DL-PRBs)
	dlConfigReq = buildLteDlConfigReq(userInfo , sfNsf);
	//Build Tx-Req for RLC message
	txDataReq = buildLteTxDataReq(userInfo , sfNsf);
	pushToDlConfigReqQ(sfNsf, dlConfigReq);
	pushToTxDataReqQ(sfNsf, txDataReq);
	userInfo->macLayerState = WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH;
	if((msgType == LTE_MSG_RRC_CONN_REL_DL_DCH_SDU_REQ_E) || (msgType == LTE_MSG_RRC_CONN_REDIRECT_DL_DCH_SDU_REQ_E))
	{
		userInfo->macLayerState = WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL;
		userInfo->ulRiv = ulRivArr[lteSelectedBandwidth][LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_RIV];
		if(lteSelectedBandwidth >LTE_BW_N15)
		{
			userInfo->ulMcs = LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS;
		}
		else
		{
			userInfo->ulMcs = LTE_MAC_UL_GRANT_BW_143_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS;
		}
		userInfo->ulModulationType = eFAPI_QPSK;
		userInfo->continuousUlGrant = FALSE;
		userInfo->srRecoveryCounter = 0;
	}
	if((msgType == LTE_MSG_RRC_MEAS_REQ_E) || (msgType == LTE_MSG_RRC_UECAPA_ENQ_REQ_E) || (msgType == LTE_MSG_RRC_RECONFIG_REQ_E))
	{
		userInfo->silentCallStarted = TRUE;
	}
	
	/*Check for Meas Gap Started or not */
    if((msgType == LTE_MSG_RRC_NEIGH_MEAS_REQ_E) &&
       (gLteRrcMeasData.measGapConfigured == 1))
    {
            userInfo->measGapStarted = 1;
    }
	
	if(TRUE == isTimerRunning(&userInfo->tmr))
	{
		timerStop(&userInfo->tmr);
	}

	timerStart(&userInfo->tmr , TIMER_FOR_WAITING_FOR_HARQ , 0 , lteUserInfoTimerCbFunction, userInfo);
	logPrint(LOG_DEBUG,"CRNTI = %d DCCH-Msg = %d in Mac-State = %d at %04x \n" ,userInfo->crnti , msgType, userInfo->macLayerState , sfNsf);
	prepareUlMessageAfterSendingDlTxReq(userInfo, sfNsf);
	return;

}

void getRivAndMcsFromMessageType(lteUserInfo *userInfo , lteMsgType_e msgType)
{
	switch(msgType)
	{
		case LTE_MSG_MAC_RLC_ACK_CTRL_PDU_E:
			{
				userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_DL_GRANT_FOR_RLC_ACK]; // RB-Start = 0 , No-Rb = 2
				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					userInfo->dlMcs = LTE_MAC_RLC_ACK_CARRYING_DL_MCS; //1;  // TBs = 56
				}
				else
				{
					userInfo->dlMcs = LTE_MAC_BW_143_RLC_ACK_CARRYING_DL_MCS; //4;  // TBs = 56
				}
				userInfo->macPduLen = LTE_MAC_RLC_ACK_PDU_SIZE; //7;
			}
			break;
		case LTE_MSG_IDENTITY_REQ_DL_DCH_SDU_REQ_E:
		case LTE_MSG_ATTACH_REJ_DL_DCH_SDU_REQ_E:
		case LTE_MSG_TAU_REJ_DL_DCH_SDU_REQ_E:
		case LTE_MSG_RRC_CONN_REDIRECT_DL_DCH_SDU_REQ_E:
        case LTE_MSG_RRC_UECAPA_ENQ_REQ_E:
			{
				userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_DL_GRANT_FOR_NAS_REQ]; // RB-Start = 0 , No-Rb = 4
				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					userInfo->dlMcs = LTE_MAC_NAS_REQ_CARRYING_DL_MCS; //1; // TBS = 144
				}
				else
				{
					userInfo->dlMcs = LTE_MAC_BW_143_NAS_REQ_CARRYING_DL_MCS; //11; // TBS = 144
				}
				userInfo->macPduLen = LTE_MAC_NAS_REQ_PDU_SIZE; //144/8; // 12 bytes
			}
			break;
		case LTE_MSG_RRC_CONN_REL_DL_DCH_SDU_REQ_E:
			{
				userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_DL_GRANT_FOR_RRC_CONN_REL]; // RB-Start = 35 , No-Rb = 5
				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					userInfo->dlMcs = LTE_MAC_RRC_CONN_REL_CARRYING_DL_MCS; //0; // TBS = 120
				}
				else
				{
					userInfo->dlMcs = LTE_MAC_BW_143_RRC_CONN_REL_CARRYING_DL_MCS; //8; // TBS = 120
				}
				userInfo->macPduLen = LTE_MAC_RRC_CONN_REL_PDU_SIZE; //120/8; // 15 bytes
			}
			break;
		case LTE_MSG_RRC_MEAS_REQ_E:
			{
				userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_DL_GRANT_FOR_RRC_MEAS_REQ]; // RB-Start = 40 , No-Rb = 6
				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					userInfo->dlMcs = LTE_MAC_RRC_MEAS_REQ_CARRYING_DL_MCS; //2; // TBS = 256
				}
				else
				{
					userInfo->dlMcs = LTE_MAC_BW_143_RRC_MEAS_REQ_CARRYING_DL_MCS; //8; // TBS = 256
				}
				userInfo->macPduLen = LTE_MAC_RRC_MEAS_REQ_PDU_SIZE; //256/8; // 32 bytes

			}
			break;
		case LTE_MSG_RRC_RECONFIG_REQ_E:
			{
				userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_DL_GRANT_FOR_RRC_RECONFIG_REQ]; // RB-Start = 40 , No-Rb = 6
				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					userInfo->dlMcs = LTE_MAC_RRC_RECONFIG_REQ_CARRYING_DL_MCS; //2; // TBS = 256
				}
				else
				{
					userInfo->dlMcs = LTE_MAC_BW_143_RRC_RECONFIG_REQ_CARRYING_DL_MCS; //8; // TBS = 256
				}
				userInfo->macPduLen = LTE_MAC_RRC_RECONFIG_REQ_PDU_SIZE; //256/8; // 32 bytes

			}
			break;
			
			case LTE_MSG_RRC_NEIGH_MEAS_REQ_E:
            {
                 userInfo->dlRiv = dlRivArr[lteSelectedBandwidth][LTE_MAC_DL_GRANT_FOR_RRC_NEIGH_MEAS_REQ]; // RB-Start = 40 , No-Rb = 8
                 userInfo->dlMcs = 9; // TBS = 1256
                 userInfo->macPduLen = 1256/8; // 157 bytes
            }
            break;
			
		default:
			{
				logPrint(LOG_DEBUG ,"getRivAndMcsFromMessageType Unhandled Message = %d \n" , msgType);
			}
			break;
	}
	return;
}

void ltePutMsgInRlcQ(void* rrcMsg)
{
	enQueue(&rxRlcDataQ , (void *)rrcMsg);
	return;
}

void buildAndSendRlcMsgToRrc(lteUserInfo *userInfo , lteMsgType_e msgType)
{
	lteL2InftMsg_t *pRrcMsg = NULL;
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	pRrcMsg->msgType = msgType;
	pRrcMsg->l2Data.size = 0;
	pRrcMsg->l2Data.crnti = userInfo->crnti;
	pRrcMsg->l2Data.PO = userInfo->phr_ulRssi;
	pRrcMsg->l2Data.PF = userInfo->timingAdvance;
	pRrcMsg->l2Data.snr = userInfo->ulSnr;
	pRrcMsg->l2Data.emeCallInd = userInfo->emergencyCallAttempted;
	ltePutMsgInRrcQ(pRrcMsg);
	return;
}


void cleanMacSchedulerBins()
{
	uint8 nextSbfn = 0;
	listNode* qNode = NULL;
	for(nextSbfn = 0; nextSbfn < LTE_MAX_SUB_FRAME_NUMBER ; nextSbfn++)
	{
		if((headForLteMacDlSchedulerQ[nextSbfn] != NULL) && ((qNode = popMsgFromList( &headForLteMacDlSchedulerQ[nextSbfn]))!= NULL))
		{
			while(qNode != NULL)
			{
				if(qNode != NULL)
				{
					free(qNode);
					qNode = NULL;
				}
				if(headForLteMacDlSchedulerQ[nextSbfn] != NULL)
				{
					qNode = popMsgFromList(&headForLteMacDlSchedulerQ[nextSbfn]);
				}
				else
				{
					qNode = NULL;
				}
			}
			headForLteMacDlSchedulerQ[nextSbfn] = NULL;
			tailForLteMacDlSchedulerQ[nextSbfn] = NULL;

		}

		// Uplink
		qNode = NULL;
		if((headForLteMacUlSchedulerQ[nextSbfn] != NULL) && ((qNode = popMsgFromList( &headForLteMacUlSchedulerQ[nextSbfn]))!= NULL))
		{
			while(qNode != NULL)
			{
				if(qNode != NULL)
				{
					free(qNode);
					qNode = NULL;
				}
				if(headForLteMacUlSchedulerQ[nextSbfn] != NULL)
				{
					qNode = popMsgFromList(&headForLteMacUlSchedulerQ[nextSbfn]);
				}
				else
				{
					qNode = NULL;
				}
			}
			headForLteMacUlSchedulerQ[nextSbfn] = NULL;
			tailForLteMacUlSchedulerQ[nextSbfn] = NULL;

		}

		// Dl Tx Data
		qNode = NULL;
		if((headForLteMacDlTxDataQ[nextSbfn] != NULL) && ((qNode = popMsgFromList( &headForLteMacDlTxDataQ[nextSbfn]))!= NULL))
		{
			while(qNode != NULL)
			{
				if(qNode != NULL)
				{
					free(qNode);
					qNode = NULL;
				}
				if(headForLteMacDlTxDataQ[nextSbfn] != NULL)
				{
					qNode = popMsgFromList(&headForLteMacDlTxDataQ[nextSbfn]);
				}
				else
				{
					qNode = NULL;
				}
			}
			headForLteMacDlTxDataQ[nextSbfn] = NULL;
			tailForLteMacDlTxDataQ[nextSbfn] = NULL;		
		}	
	}

	return;
}

void destroy4gContext(void)
{
    uint8 i =0;
	listNode* qNode = NULL;
	cleanMibSibData();

    if(headForUlConfigReqQ != NULL)
    {
      qNode = popMsgFromList(&headForUlConfigReqQ );
    }
    while(qNode != NULL)
    {
      if(qNode != NULL)
      {
		  free(qNode);
		  qNode = NULL;
      }
      if(headForUlConfigReqQ != NULL)
      {
        qNode = popMsgFromList(&headForUlConfigReqQ );
      }
    }
    tailForUlConfigReqQ = headForUlConfigReqQ = NULL;

    cleanUpLteBlList();
	lteTimerTickReceived = FALSE;
	cleanMacSchedulerBins();
    deallocateUlTxDataBuffer();
    deallocateRrcDataBuffer();
    deallocateDlConfigBuffer();
    deallocateUlConfigBuffer();
    deallocateDlTxDataBuffer();
    memset((lteRrcUeControlBlock *)&lteUeControlBlock, 0, sizeof(lteUeControlBlock));
    for(i = 0; i < LTE_MAX_USER_SUPPORTED; i++)
    {
       lteUeControlBlock.lteueSpecificData[i].ueState = UE_RELEASED;
    }
    timerDestroy();
	pthread_mutex_destroy(&timerMutexLock);
    cleanUpAsnbuffers();

    for(i=0;i<LTE_MAX_USER_SUPPORTED;i++)
    {
    	pagingQ[i] = NULL;
    }
	 memset(&cce_map, 0, (sizeof(cce_map[0][0])*LTE_MAX_CCE_IDX*LTE_MAX_SUB_FRAME_NUMBER));
}

void sendDeleteCntxtMsgToSelf(lteUserInfo *info)
{
#if 0
	lteL2InftMsg_t *pRrcMsg;
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	pRrcMsg->msgType = LTE_MSG_DELETE_MAC_RLC_USER_CNTXT_E;
	pRrcMsg->l2Data.crnti = info->crnti;
	ltePutMsgInRlcQ((void*)pRrcMsg);
#endif
	userDeleteUsingCrnti(info->crnti , FALSE);

}

void addPagingReqToQ(lteL2InftMsg_t *pagingMsg)
{
	//logPrint(LOG_DEBUG , "Paging REQ PO = %d , PF = %d \n", pagingMsg->l2Data.PO , pagingMsg->l2Data.PF);
	assert(pagingMsg->l2Data.PF <= LTE_MAX_USER_SUPPORTED);
	pagingMsg->l2Data.crnti = 0;
	pagingQ[pagingMsg->l2Data.PF] = pagingMsg; // Add new one
	return;
}

void deletePagingReqFromQ(lteL2InftMsg_t *pagingMsg)
{
	logPrint(LOG_DEBUG , "Paging REQ PO = %d , PF = %d Size = %d Deleted\n", pagingMsg->l2Data.PO , pagingMsg->l2Data.PF , pagingMsg->l2Data.size);
	assert(pagingMsg->l2Data.PF <= LTE_MAX_USER_SUPPORTED);
	if(pagingQ[pagingMsg->l2Data.PF] != NULL)
	{
		pagingQ[pagingMsg->l2Data.PF] = NULL;
	}
	return;
}

uint8* buildLtePagingTxDataReq(lteL2InftMsg_t *ltePageMsg , uint16 sfNsf)
{
	uint8 *msgBuf = getDlTxDataBuffer();
	uint8 msgLen = 0;
	uint8* data = NULL;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_DATA_TX_REQUEST * txReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_PDU_DATA_INFO *dlPdu = (tOCT_FAPI_DL_PDU_DATA_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE];
	tOCT_FAPI_DL_PDU_DATA_TLV *txData = (tOCT_FAPI_DL_PDU_DATA_TLV*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

	txReq->usSfnsf = htons(sfNsf);
	txReq->usNumOfPDU = htons(1);

	dlPdu->usPduIndex = LTE_SHORT_ZERO;
	dlPdu->ulNumOfTLV = htonl(1);

	txData->usTag = LTE_SHORT_ZERO;
	if(ltePageMsg->l2Data.size > 37)
	{
		msgLen = LTE_MAC_8_PAGING_REQ_PDU_SIZE;
		txData->usTagLen = htons(LTE_MAC_8_PAGING_REQ_PDU_SIZE);
	}
	else if((ltePageMsg->l2Data.size < 38)&&(ltePageMsg->l2Data.size > 10))
	{
		msgLen = LTE_MAC_4_PAGING_REQ_PDU_SIZE;
		txData->usTagLen = htons(LTE_MAC_4_PAGING_REQ_PDU_SIZE);
	}
	else
	{
		msgLen = LTE_MAC_PAGING_REQ_PDU_SIZE;
		txData->usTagLen = htons(LTE_MAC_PAGING_REQ_PDU_SIZE);
	}

	data = (uint8*)&txData->aulValue[0];//Check for length
	if(ltePageMsg->l2Data.size > 160 )
		ltePageMsg->l2Data.size = 160;
	memcpy((uint8*)data, (uint8*)ltePageMsg->l2Data.dataBuf, ltePageMsg->l2Data.size);

	if((msgLen%4) != 0)
	{
		msgLen = msgLen + (4 - (msgLen%4)); // Aligning to word boundry
	}
	dlPdu->usPduLen = htons(msgLen + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE);
	msgLen = msgLen + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE;

	lteFapiMsg->msgId = PHY_DL_TX_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);

	return msgBuf;

}
uint8* buildLtePagingDlConfigReq(lteL2InftMsg_t *ltePageMsg , uint16 sfNsf)
{
	uint8 *msgBuf = getDlConfigBuffer();
	uint8 msgLenth = 0;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	dlConfigReq->usSfnsf = htons(sfNsf);
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ; //3
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	msgLenth = SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE;

	if(ltePageMsg != NULL) // Real Dl-config request
	{
		tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDciConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE];
		tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
		tOCT_FAPI_DCIFORMAT_1A *dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];

		tOCT_FAPI_DL_CONFIG_PDU_LIST *pchConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A];
		tOCT_FAPI_DL_CONFIG_PDU_INFO *pchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

		//uint32 riv = 0;
		dlConfigReq->byNumDCI = 1;
		dlConfigReq->byNumOfPDSCHRNTI = 1; // RA/CI/PCH_RNTI only
		dlConfigReq->usNumOfPDU = htons(2) ; // 1-Pdcch(dci-1a) and 2-PCH Pdu

		/* DCI1A Pdu Start*********************************************************************************************/
		dlDciConfigPdu->byPduType = eFAPI_DCI_DL_PDU;
		dlDciConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; //28bytes
		dciPduInfo->DCIPdu.byDciFormat = eFAPI_DL_DCI_FORMAT_1A;	

		dciPduInfo->DCIPdu.byCceIndex  = CalculateLteCceIdx(TRUE,LTE_P_RNTI,sfNsf);
		dciPduInfo->DCIPdu.usRnti = htons(LTE_P_RNTI);
		dci1AInfo->byTpc = eFAPI_TX_POWER_CONTROL_MINUS_1; // If this value changes then change the rbCoding as well and NPRB = 3
		if(lteSelectedBandwidth > LTE_BW_N15)
		{
			dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
		}
		else
		{
			dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU/2;
		}
		dci1AInfo->byVRBAssignmentFlag = eFAPI_LOCALISED; //Localized
		dci1AInfo->byRedundancyVersion_1 = 0; // Redudancy version should be changed as 0->2->3->1
		dci1AInfo->byNewDataIndicator_1 = 0;
		dci1AInfo->byHarqProcessNum = 0;
		if(lteDuplxMode)
		{
			dci1AInfo->byDlAssignmentIndex = 1;//tdd
		}
		else
		{
			dci1AInfo->byDlAssignmentIndex = 0;//tdd
		}
		dci1AInfo->byAllocatePRACHFlag = FALSE;
		dci1AInfo->byPreambleIndex = 0;
		dci1AInfo->usTxPower = htons(LTE_PDCCH_POWER_OFFSET_VALUE);
		dci1AInfo->byPRACHMaskIndex = 0;
		dci1AInfo->byRntiType = eFAPI_RA_RNTI_P_RNTI_SI_RNTI;
		/* DCI1A Pdu End*********************************************************************************************/

		/* DL-SCH Pdu Start*********************************************************************************************/
		pchConfigPdu->byPduType = eFAPI_PCH_PDU;
		pchConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_PCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE;
		pchPduInfo->PCHPdu.usPduIndex = LTE_SHORT_ZERO;
		pchPduInfo->PCHPdu.usPRNTI = htons(LTE_P_RNTI);
		pchPduInfo->PCHPdu.byResAllocationType = eFAPI_RES_ALLOC_TYPE_2;
		pchPduInfo->PCHPdu.byVRBAssignmentFlag = eFAPI_LOCALISED;
		pchPduInfo->PCHPdu.byMcs = 0;//QPSK
		pchPduInfo->PCHPdu.byRedundancyVersion = 0;
		pchPduInfo->PCHPdu.byNumOftransportBlocks = 1;
		pchPduInfo->PCHPdu.byTbToCodeWordSwapFlag = eFAPI_NOSWAPPING;
		pchPduInfo->PCHPdu.byTransmissionScheme = eFAPI_DL_SINGLE_ANTENNA_PORT_0;
		pchPduInfo->PCHPdu.byNumOfLayers = 1;
		pchPduInfo->PCHPdu.byCodeBookIndex = 0;
		pchPduInfo->PCHPdu.byUeCatagoryCapacity = LTE_UE_CATEGORY;
		pchPduInfo->PCHPdu.byPA = LTE_PDSCH_CONFIG_PA_VALUE_dB_3; //4; //0dB
		pchPduInfo->PCHPdu.byNPRB = 0;
		pchPduInfo->PCHPdu.usTxPower = htons(LTE_PDCCH_POWER_OFFSET_VALUE);;

		/* DL-SCH Pdu End*********************************************************************************************/

		if(ltePageMsg->l2Data.size > 37)
		{
			dci1AInfo->byMcs_1 = LTE_MAC_8_PAGING_REQ_CARRYING_DL_MCS;
			pchPduInfo->PCHPdu.usPchPduLen = htons(LTE_MAC_8_PAGING_REQ_PDU_SIZE);
			dci1AInfo->ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_8_PAGING_REQ_CARRYING_DL_RIV]);//riv;
			pchPduInfo->PCHPdu.ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_8_PAGING_REQ_CARRYING_DL_RIV]); //riv;
		}
		else if((ltePageMsg->l2Data.size < 38)&&(ltePageMsg->l2Data.size > 10))
		{
			dci1AInfo->byMcs_1 = LTE_MAC_4_PAGING_REQ_CARRYING_DL_MCS;
			pchPduInfo->PCHPdu.usPchPduLen = htons(LTE_MAC_4_PAGING_REQ_PDU_SIZE);
			dci1AInfo->ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_4_PAGING_REQ_CARRYING_DL_RIV]); //riv;
			pchPduInfo->PCHPdu.ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_4_PAGING_REQ_CARRYING_DL_RIV]); //riv;
		}
		else
		{
			if(lteSelectedBandwidth > LTE_BW_N15)
			{
				dci1AInfo->byMcs_1 = LTE_MAC_PAGING_REQ_CARRYING_DL_MCS;
			}
			else
			{
				dci1AInfo->byMcs_1 = LTE_MAC_BW_143_PAGING_REQ_CARRYING_DL_MCS;
			}
			pchPduInfo->PCHPdu.usPchPduLen = htons(LTE_MAC_PAGING_REQ_PDU_SIZE);
			dci1AInfo->ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_PAGING_REQ_CARRYING_DL_RIV]);//riv;
			pchPduInfo->PCHPdu.ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_PAGING_REQ_CARRYING_DL_RIV]); //riv;
		}

		msgLenth = msgLenth + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_PCH_PDU_INFO;

	}

	dlConfigReq->usLength = htons(msgLenth);
	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);

	return msgBuf;
}

void checkAndPushPagingReqToDlSchedulerQ(uint16 sfn , uint8 sbfn)
{
	uint8 pagingQindex = sfn % LTE_MAX_USER_SUPPORTED;

	if(sbfn == 1)
	{
		if(pagingQ[pagingQindex] != NULL)
		{
			uint8 *dlConfigReq = NULL;
			uint8 *txDataReq = NULL;
			lteL2InftMsg_t* ltePageMsg = pagingQ[pagingQindex];
			uint16 sfNsf = ((sfn<<4)|(LTE_PAGING_SUBFRAME_LOCATION & 0x0F));
			//Build Dl-Config Req for sending Paging message
			dlConfigReq = buildLtePagingDlConfigReq(ltePageMsg , sfNsf);
			//Build Tx-Req for Paging message
			txDataReq = buildLtePagingTxDataReq(ltePageMsg ,sfNsf);
			pushToDlConfigReqQ(sfNsf, dlConfigReq);
			pushToTxDataReqQ(sfNsf, txDataReq);
		}
	}

	return;
}

void checkAndPushTDDPagingReqToDlSchedulerQ(uint16 sfn , uint8 sbfn)
{
	sfn = (sfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
	uint8 pagingQindex = sfn % LTE_MAX_USER_SUPPORTED;

	if(pagingQ[pagingQindex] != NULL)
	{
		uint8 *dlConfigReq = NULL;
		uint8 *txDataReq = NULL;
		lteL2InftMsg_t* ltePageMsg = pagingQ[pagingQindex];
		uint16 sfNsf = ((sfn<<4)|(LTE_PAGING_SUBFRAME_LOCATION_TDD & 0x0F));
		//Build Dl-Config Req for sending Paging message
		dlConfigReq = buildLtePagingDlConfigReq(ltePageMsg , sfNsf);
		//Build Tx-Req for Paging message
		txDataReq = buildLtePagingTxDataReq(ltePageMsg ,sfNsf);
		pushToDlConfigReqQ(sfNsf, dlConfigReq);
		pushToTxDataReqQ(sfNsf, txDataReq);
		//logPrint(LOG_DEBUG , "Paging msg Size = %d , sfnsf = %04x",ltePageMsg->l2Data.size , sfNsf);
	}
	return;
}

uint32 getCurrentRiv(uint32 riv ,uint8 *startRb)
{
	uint32 currentRiv = 0 ;
	uint8 noOfRbs = (riv / bwToPrb[lteSelectedBandwidth]) + 1;
	assert(*startRb < bwToPrb[lteSelectedBandwidth]);
	currentRiv = (bwToPrb[lteSelectedBandwidth] *(noOfRbs - 1)) + *startRb;
	if(lteSelectedBandwidth > LTE_BW_N15)
	{
		if(lteSelectedBandwidth == LTE_BW_N25)
		{	
			*startRb = *startRb + noOfRbs;
		}
		else
		{			
			*startRb = *startRb + noOfRbs + 1; // Keeping offset of 1 PRB in between to UE allocation
		}
	}
	else
	{
		if(lteSelectedBandwidth == LTE_BW_N6)
		{
			if(riv == 11)
			{
				currentRiv = riv;
				noOfRbs = 6;
				*startRb = 6;
				return currentRiv;
			}
		}
		*startRb = *startRb + noOfRbs;
	}
	return currentRiv;
}
uint8 skipNextTxDataReq = FALSE;
void pushToDlConfigReqQ(uint16 sfNsf , uint8*dlConfig)
{
	uint8* dlPduPtr = NULL , pduFound = FALSE;
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = NULL;
	tOCT_FAPI_DCIFORMAT_1A *dci1AInfo = NULL;
	tOCT_FAPI_DL_CONFIG_PDU_INFO *dlSchPduInfo = NULL;
	listNode *head = getHeadDlSchedulerSubframeQ((sfNsf & 0x000F));
	//Search in ulConfig list
	while(head != NULL)
	{
		dlPduPtr = (uint8*)head->msg;
		if(dlPduPtr != NULL)
		{
			dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

			if((dlConfigReq != NULL)&&(ntohs(dlConfigReq->usSfnsf) == sfNsf))
			{
				pduFound = TRUE;
				break;
			}
		}
		head = head->next;
	}

	if(pduFound == FALSE) // New Pdu
	{
		dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
		if(dlConfigReq->byNumDCI > 0)//MIB
		{
			if(ntohs(dlConfigReq->usNumOfPDU) == 3)
			{
				dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];
				dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
			}
			else
			{
				dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];
				dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
			}
			if(lteSelectedBandwidth > LTE_BW_N15)
			{
				dlConfigReq->abyPadding[0] = 3; // Using this padding byte as starting RB.
			}
			else
			{
				dlConfigReq->abyPadding[0] = 0; // Using this padding byte as starting RB.
			}
			if(ntohl(dci1AInfo->ulRbCoding) != 0xFFFFFFFF)// Not a PDCCH Order
			{
				dci1AInfo->ulRbCoding = htonl(getCurrentRiv(ntohl(dci1AInfo->ulRbCoding) ,&dlConfigReq->abyPadding[0]));
				dlSchPduInfo->DlSCHPdu.ulRbCoding = dci1AInfo->ulRbCoding;
			}

		}
		pushMacPduToDlSchedulerQ((sfNsf & 0x000F) , dlConfig);
	}
	else // Merge new Pdu with old Pdu
	{
		lteEthernetFrameHeader *lteHdr = (lteEthernetFrameHeader*)dlPduPtr;
		uint16 msgLen = ntohs(lteHdr->ltePacketLength);
		tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE];
		tOCT_FAPI_DL_CONFIG_REQUEST *newDlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

		if((dlConfigReq->byNumDCI == 0)&&(newDlConfigReq->byNumDCI == 0)&&(dlConfigReq->byNumOfPDSCHRNTI == 0)&&(newDlConfigReq->byNumOfPDSCHRNTI == 0))
		{
			//logPrint(LOG_DEBUG , "NumOfPDSCHRNTI = %d , NumOfPdu = %d SfNsf = 0x%04x\n", dlConfigReq->byNumOfPDSCHRNTI , ntohs(dlConfigReq->usNumOfPDU) , sfNsf );
			return;
		}

		if(((((sfNsf>>4) & 0x0FFF) % LTE_SIB1_REPITION_FRAMES) == 0)&&((sfNsf & 0x000F) == LTE_SIB1_SUBFRAME_LOCATION))
		{
			tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
			if(dciPduInfo->DCIPdu.usRnti == LTE_SI_RNTI) // ntohs will give you same
			{
				skipNextTxDataReq = TRUE;
				return;
			}
		}
		else if(((((sfNsf>>4) & 0x0FFF) % LTE_SIBS_REPITITION_FRAMES) == 0)&&((sfNsf & 0x000F) == LTE_MIB_SUBFRAME_LOCATION))
		{
			tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
			if(dciPduInfo->DCIPdu.usRnti == LTE_SI_RNTI) // ntohs will give you same
			{
				skipNextTxDataReq = TRUE;
				return;
			}

		}
		else
		{}

		if(newDlConfigReq->byNumDCI > 0)//MIB
		{
			if(ntohs(newDlConfigReq->usNumOfPDU) == 3)
			{
				dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];
				dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
			}
			else
			{
				dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];
				dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
			}
			if(ntohl(dci1AInfo->ulRbCoding) != 0xFFFFFFFF)// Not a PDCCH Order
			{
				dci1AInfo->ulRbCoding = htonl(getCurrentRiv(ntohl(dci1AInfo->ulRbCoding) ,&dlConfigReq->abyPadding[0]));
				dlSchPduInfo->DlSCHPdu.ulRbCoding = dci1AInfo->ulRbCoding;
			}
		}
		dlConfigReq->byNumDCI = dlConfigReq->byNumDCI + newDlConfigReq->byNumDCI;
		dlConfigReq->byNumOfPDSCHRNTI = dlConfigReq->byNumOfPDSCHRNTI + newDlConfigReq->byNumOfPDSCHRNTI;
		dlConfigReq->usNumOfPDU = htons(ntohs(dlConfigReq->usNumOfPDU) + ntohs(newDlConfigReq->usNumOfPDU)) ;
		dlConfigReq->usLength = htons(ntohs(dlConfigReq->usLength)+ntohs(newDlConfigReq->usLength)- SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE);
		lteFapiMsg->usMsgLen = dlConfigReq->usLength;
		lteHdr->ltePacketLength = htons(msgLen + ntohs(newDlConfigReq->usLength)- SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE);

		if((ntohs(lteHdr->ltePacketLength)+START_OF_LTE_FAPI_MESSAGE) < LTE_MAX_SIZE_BUFFER)
		{
			memcpy((uint8*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + msgLen - LTE_OCT_SDR_ETH_HEADER_SIZE] ,(uint8*)&dlConfig[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE], (ntohs(newDlConfigReq->usLength)- SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE));
		}
		else
		{
			logPrint(LOG_DEBUG , "pushToDlConfigReqQ , Bigger Size = %d\n" , ntohs(lteHdr->ltePacketLength) /*(abs(tmp1-tmp2) + (ntohs(newDlConfigReq->usLength)- SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE))*/);
		}
		//logPrint(LOG_DEBUG,"Merging Dl-Config Pdus's on sfNsf = %04x , NumDci = %d , PdschRnti = %d \n" , sfNsf , dlConfigReq->byNumDCI , dlConfigReq->byNumOfPDSCHRNTI);
	}
}

void pushToTxDataReqQ(uint16 sfNsf , uint8* txData)
{
	uint8* dlPduPtr = NULL , pduFound = FALSE;
	tOCT_FAPI_DL_DATA_TX_REQUEST *txDataReq = NULL;
	listNode *head = getHeadDlTxDataSubframeQ((sfNsf & 0x000F));
	if(skipNextTxDataReq == TRUE)
	{
		skipNextTxDataReq = FALSE;
		return;
	}
	//Search in ulConfig list
	while(head != NULL)
	{
		dlPduPtr = (uint8*)head->msg;
		if(dlPduPtr != NULL)
		{
			txDataReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

			if((NULL != txDataReq) && (ntohs(txDataReq->usSfnsf) == sfNsf))
			{
				pduFound = TRUE;
				break;
			}
		}
		head = head->next;
	}

	if(pduFound == FALSE) // New Pdu
	{
		pushMacPduToDlTxDataQ((sfNsf & 0x000F) , txData);
	}
	else // Merge new Pdu with old Pdu
	{
		// Retrieve Old TxData Req
		lteEthernetFrameHeader *lteHdr = (lteEthernetFrameHeader*)dlPduPtr;
		uint16 msgLen = ntohs(lteHdr->ltePacketLength) , txPdu2Len = 0;
		tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE];
		//Retrieve New Tx Data Req
		tOCT_FAPI_DL_DATA_TX_REQUEST *newTxDataReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&txData[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
		tOCT_FAPI_DL_PDU_DATA_INFO *txPdu1 = (tOCT_FAPI_DL_PDU_DATA_INFO*)&txData[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE];
		tOCT_FAPI_DL_PDU_DATA_TLV *txDataTlvOld = (tOCT_FAPI_DL_PDU_DATA_TLV*)&txData[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];
		tOCT_FAPI_DL_PDU_DATA_TLV *txDataTlvNew = (tOCT_FAPI_DL_PDU_DATA_TLV*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

		if((newTxDataReq->usNumOfPDU == 1)&&(txDataReq->usNumOfPDU == 1)&&(txDataTlvOld->usTagLen == LTE_MIB_MAX_SIZE )&&(txDataTlvNew->usTagLen == LTE_MIB_MAX_SIZE))
		{
			logPrint(LOG_DEBUG , "MIB data SfNsf = 0x%04x\n", sfNsf );
			return;
		}

		txDataReq->usNumOfPDU = htons(ntohs(txDataReq->usNumOfPDU) + ntohs(newTxDataReq->usNumOfPDU));
		txPdu1->usPduIndex = htons(ntohs(txDataReq->usNumOfPDU)-1); // Update the Pdu index before copying the pdu
		lteFapiMsg->usMsgLen = htons(ntohs(lteFapiMsg->usMsgLen) + ntohs(txPdu1->usPduLen));
		lteHdr->ltePacketLength = htons(msgLen + ntohs(txPdu1->usPduLen));

		if(newTxDataReq->usNumOfPDU == 2)
		{
			tOCT_FAPI_DL_PDU_DATA_INFO *txPdu2 = (tOCT_FAPI_DL_PDU_DATA_INFO*)&txData[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + ntohs(txPdu1->usPduLen)];
			txPdu1->usPduIndex = htons(ntohs(txDataReq->usNumOfPDU)-2); // Update the Pdu index before copying the pdu
			txPdu2->usPduIndex = htons(ntohs(txPdu1->usPduIndex)+1);
			txPdu2Len = ntohs(txPdu2->usPduLen);
			lteFapiMsg->usMsgLen = htons(ntohs(lteFapiMsg->usMsgLen) + txPdu2Len);
			lteHdr->ltePacketLength = htons(ntohs(lteHdr->ltePacketLength) + txPdu2Len);
		}

		if((ntohs(lteHdr->ltePacketLength)+START_OF_LTE_FAPI_MESSAGE) < LTE_MAX_SIZE_BUFFER)
		{
			memcpy((uint8*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + msgLen - LTE_OCT_SDR_ETH_HEADER_SIZE] ,(uint8*)&txData[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE], (ntohs(txPdu1->usPduLen)));
			if((newTxDataReq->usNumOfPDU == 2)&&(txPdu2Len != 0))
			{
				memcpy((uint8*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + msgLen - LTE_OCT_SDR_ETH_HEADER_SIZE + ntohs(txPdu1->usPduLen)] ,(uint8*)&txData[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + ntohs(txPdu1->usPduLen)], txPdu2Len);
			}
		}
		else
		{
			logPrint(LOG_DEBUG, "pushToTxDataReqQ Merged Pdu size is more than buffer size ignoring this pdu size = %d \n",ntohs(lteHdr->ltePacketLength) /*(abs(tmp1-tmp2) + txPdu2Len)*/);
		}
		//logPrint(LOG_DEBUG,"Merging Tx-Data Pdus's on sfNsf = %04x\n" , sfNsf);
	}
}

uint8* popFromDlConfigReqQ(uint16 sfNsf)
{
	uint8* dlPduPtr = NULL , *dlConfig = NULL;
	listNode *head = headForLteMacDlSchedulerQ[(sfNsf & 0x000F)];
	listNode *tmp = NULL , *prev = NULL;

	while(head != NULL)
	{
		dlPduPtr = (uint8*)head->msg;
		if(dlPduPtr != NULL)
		{
			tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigPdu = (tOCT_FAPI_DL_CONFIG_REQUEST*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

			if((NULL != dlConfigPdu) && (ntohs(dlConfigPdu->usSfnsf) == sfNsf))
			{
				dlConfig = (uint8*)dlPduPtr;
				if(head == headForLteMacDlSchedulerQ[(sfNsf & 0x000F)])
				{
					//head node itself matches
					headForLteMacDlSchedulerQ[(sfNsf & 0x000F)] = head->next;
					if(headForLteMacDlSchedulerQ[(sfNsf & 0x000F)] == NULL)
					{
						tailForLteMacDlSchedulerQ[(sfNsf & 0x000F)] = NULL;
					}
				}
				else if(head == tailForLteMacDlSchedulerQ[(sfNsf & 0x000F)])
				{
					//tail node matched
					tailForLteMacDlSchedulerQ[(sfNsf & 0x000F)] = prev;
				}
				else
				{
					//some node in between matched
				}
			    tmp = head;
			    head = head->next;
			    if(prev != NULL)
			    {
				    prev->next = head;
			    }
			    free(tmp);

				break;
			}
			else
			{
			   prev = head;
			   if(head != NULL)
			   {
				   head = head->next;
			   }
			}
		}
		else
		{
		   prev = head;
		   if(head != NULL)
		   {
			   head = head->next;
		   }
		}
	}

	return dlConfig;
}

uint8* popFromTxDataReqQ(uint16 sfNsf)
{
	uint8* dlPduPtr = NULL , *txData = NULL;
	listNode *head = headForLteMacDlTxDataQ[(sfNsf & 0x000F)];
	listNode *tmp = NULL , *prev = NULL;

	while(head != NULL)
	{
		dlPduPtr = (uint8*)head->msg;
		if(dlPduPtr != NULL)
		{
			tOCT_FAPI_DL_DATA_TX_REQUEST *txDataPdu = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&dlPduPtr[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

			if(ntohs(txDataPdu->usSfnsf) == sfNsf)
			{
				txData = (uint8*)dlPduPtr;
				if(head == headForLteMacDlTxDataQ[(sfNsf & 0x000F)])
				{
					//head node itself matches
					headForLteMacDlTxDataQ[(sfNsf & 0x000F)] = head->next;
					if(headForLteMacDlTxDataQ[(sfNsf & 0x000F)] == NULL)
					{
						tailForLteMacDlTxDataQ[(sfNsf & 0x000F)] = NULL;
					}
				}
				else if(head == tailForLteMacDlTxDataQ[(sfNsf & 0x000F)])
				{
					tailForLteMacDlTxDataQ[(sfNsf & 0x000F)] = prev;
				}
				else
				{
					// Some Node in-between
				}

			    tmp = head;
			    head = head->next;
			    if(prev != NULL)
			    {
				    prev->next = head;
			    }
			    free(tmp);

				break;
			}
			else
			{
			   prev = head;
			   if(head != NULL)
			   {
				   head = head->next;
			   }
			}
		}
		else
		{
		   prev = head;
		   if(head != NULL)
		   {
			   head = head->next;
		   }
		}
	}

	return txData;
}

uint8 getStartRbForSilentCallUlAllocation(eLteBw bandwidth)
{
	uint8 startRb = 3;
	if(bandwidth == LTE_BW_N25)
	{
		startRb = 8; // Middle is 12 so 5 left side and 5 right side
	}
	else if(bandwidth == LTE_BW_N50)
	{
		startRb = 21;
	}
	else if(bandwidth == LTE_BW_N75)
	{
		startRb = 33;
	}
	else if(bandwidth == LTE_BW_N100)
	{
		startRb = 46;
	}
	else
	{
		startRb = 3;
	}
	return startRb;
}
	
uint8 continuousGrantBuf[256];
void buildAndSendUlDci0ReqForContinuesGrant(uint16 sfNsf , uint8 *msgHiPdu)
{
	static uint8 continuousGrantIndex = 0;
	lteUserInfo *ulGrantUser[LTE_MAX_NO_UL_PDU_PER_TTI/2] = {NULL} , *userInfo = NULL; // Only 2 user per TTI
	uint8 i = 0, contextFound = FALSE , noOfUser = 0 , startRb = 3 , subfn = (sfNsf & 0x000F) , noOfActiveContext = 0; // Grant interval is every even TTI
	uint8 *msgBuf = NULL , lastFoundContext = 0xFF;
	uint16 msgLenth = 0;

	if((subfn % 2) != 0)//On Odd subframes
	{
		if(msgHiPdu != NULL)
		{
			if(SocketApp_Send4g(msgHiPdu) == -1)
			{
				logPrint(LOG_ERR,"buildUlDci0ReqForContinuesGrant send Failed-1 \n");
			}
		}
		return;
	}
	getNoOfUsers(&noOfActiveContext);
	// Send grant on even subframes
	if(noOfActiveContext > 0)
	{
		if(lteSelectedBandwidth == LTE_BW_N6)
		{
			startRb = 0;
		}

		for(i = continuousGrantIndex ; i < LTE_MAX_USER_SUPPORTED ; i++)
		{
			userInfo = getUserContext(i);
			if((userInfo != NULL) && (userInfo->continuousUlGrant == 0xFF))
			{
				userInfo->continuousUlGrant = TRUE;		
				userInfo->macLayerState = WAITING_FOR_RRC_CONN_COMPLETE;
				timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP_COMPLETE , 0 , lteUserInfoTimerCbFunction, userInfo);
				continue;	
			}
			else if((userInfo != NULL)&&(userInfo->continuousUlGrant == TRUE)&&
				(userInfo->macLayerState != WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH))
			{
				contextFound = TRUE;
				ulGrantUser[noOfUser++] = userInfo;
				lastFoundContext = i;
				if(lteSelectedBandwidth <= LTE_BW_N25) // Allocation only for one user
				{
					if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/4)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				else // For 2 users
				{
					if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/2)
					{
						continue;
					}
					else
					{
						break;
					}
				}
			}
		}

		if((contextFound == FALSE)||((noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/4)&&(lteSelectedBandwidth <= LTE_BW_N25)) || ((noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/2)&&(lteSelectedBandwidth > LTE_BW_N25)))
		{
			// Try from 0 till last found
			for(i = 0 ; i < continuousGrantIndex; i++)
			{
				userInfo = getUserContext(i);
				if((userInfo != NULL)&&(userInfo->continuousUlGrant == TRUE)&&
				   (userInfo->macLayerState != WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH))
				{
					contextFound = TRUE;
					ulGrantUser[noOfUser++] = userInfo;
					lastFoundContext = i;
					if(lteSelectedBandwidth <= LTE_BW_N25)
					{
						if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/4)
						{
							continue;
						}
						else
						{
							break;
						}
					}
					else
					{
						if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/2)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}

			}

		}

		if(lteSelectedBandwidth <= LTE_BW_N25)
		{
			if(noOfUser > LTE_MAX_NO_UL_PDU_PER_TTI/4)
			{
				noOfUser = LTE_MAX_NO_UL_PDU_PER_TTI/4;
			}

		}
		else
		{
			if(noOfUser > LTE_MAX_NO_UL_PDU_PER_TTI/2)
			{
				noOfUser = LTE_MAX_NO_UL_PDU_PER_TTI/2;
			}
		}
	}

	if((contextFound == TRUE)&&(noOfUser != 0))
	{
		tOCT_FAPI_L1_API_MSG * lteFapiMsg = NULL;
		tOCT_FAPI_UL_DCI_PDU_INFO *ulDci0Pdu = NULL;
		tOCT_FAPI_HI_DCI0_REQUEST *hiDci0Req = NULL;
		uint8* ulConfigReqForContGrant = NULL;
		listNode *tail = NULL;
		// First Update the next Index here
		continuousGrantIndex = lastFoundContext + 1;
		if(continuousGrantIndex >= LTE_MAX_USER_SUPPORTED)
		{
			continuousGrantIndex = 0;
		}

		if(msgHiPdu == NULL)
		{
			msgBuf = continuousGrantBuf;
			memset(msgBuf,0,256);
			msgLenth = SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE;
			lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
		}
		else
		{
			msgBuf = msgHiPdu;
			lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
			msgLenth = htons(lteFapiMsg->usMsgLen) ;
		}
		hiDci0Req = (tOCT_FAPI_HI_DCI0_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
		hiDci0Req->usSfnsf = htons(sfNsf);

		for(i=0; i<noOfUser; i++)
		{
			userInfo = ulGrantUser[i];
			if(userInfo != NULL)
			{
				//byNumOfHI = 0; //either 0(through memset) or some value don't change it
				ulDci0Pdu = (tOCT_FAPI_UL_DCI_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfDCI)*SIZE_TOCT_FAPI_UL_DCI_PDU_INFO + (hiDci0Req->byNumOfHI)*SIZE_TOCT_FAPI_UL_HI_PDU_INFO];

				hiDci0Req->byNumOfDCI++;
				ulDci0Pdu->byPduType = eFAPI_DCI_UL_PDU;
				ulDci0Pdu->byUlDCIPDUSize = SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
				ulDci0Pdu->byUlDCIFormat = eFAPI_UL_DCI_FORMAT_0;
				ulDci0Pdu->byCceIndex = CalculateLteCceIdx(FALSE,userInfo->crnti,sfNsf);
				ulDci0Pdu->usRnti = htons(userInfo->crnti);
				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					ulDci0Pdu->byAggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
				}
				else
				{
					ulDci0Pdu->byAggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU/2;
				}

				

				if(lteSelectedBandwidth == LTE_BW_N6)
				{
					userInfo->ulRiv = 11;
					ulDci0Pdu->byRbStart = 0;
					ulDci0Pdu->byNumOfRB = 6;
				}
				else
				{
					if(userInfo->silentCallStarted == TRUE)
					{
						startRb = getStartRbForSilentCallUlAllocation(lteSelectedBandwidth);
					}
					
					userInfo->ulRiv = getCurrentRiv(userInfo->ulRiv ,&startRb);
					ulDci0Pdu->byRbStart = (userInfo->ulRiv % bwToPrb[lteSelectedBandwidth]); // Assign RIV before sending any DCI0 message
					ulDci0Pdu->byNumOfRB = (userInfo->ulRiv / bwToPrb[lteSelectedBandwidth]) + 1;
				}

				if(userInfo->rbStart1 == 0)
				{
					userInfo->rbStart1 = ulDci0Pdu->byRbStart;
				}
				else
				{
					userInfo->rbStart2 = ulDci0Pdu->byRbStart;
				}
				
				ulDci0Pdu->byMcs = userInfo->ulMcs;
				ulDci0Pdu->byCyclicShift2forDMRS = 0;
				ulDci0Pdu->byFreqHoppingenabledFlag = 0; // no hopping
				ulDci0Pdu->byFreqHoppingBits = 0;
				ulDci0Pdu->byNewDataIndication = userInfo->ndiUl; // New transmission
				if(userInfo->srRecoveryCounter == 0)
				{
					//Toggle only if ACK is received
					if(userInfo->ndiUl == 1)
					{
						userInfo->ndiUl = 0;
					}
					else
					{
						userInfo->ndiUl = 1;
					}
				}
				ulDci0Pdu->byUeTxAntennaSelection = 0;
/*
				if((userInfo->ulSaturationFlag == TRUE)&&(userInfo->silentCallStarted == FALSE))
				{
					ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_MINUS_1;//-1
				}
				else if((userInfo->timingAdvance > 4)||(userInfo->silentCallStarted == TRUE))
				{
					ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_3 ;//3
				}
				else
				{
					ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_0; //2;
				}
*/
				
				if(userInfo->silentCallStarted == TRUE)
				{
					if(userInfo->ulSaturationFlag == TRUE)
					{
						ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_0; //2;
					}
					else
					{
						ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_3 ;//3
					}
				}
				else
				{
					if(userInfo->ulSaturationFlag == TRUE)
					{
						ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_MINUS_1; //2;
					}
					else
					{
						ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_0 ;//3
					}
				}
				
				ulDci0Pdu->byCqiRequest = 0;
				ulDci0Pdu->usTxPower = htons(LTE_SHORT_ZERO);
				//Other are not required as its fdd.
				msgLenth = msgLenth + SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
			}
		}
		lteFapiMsg->msgId = PHY_DL_HI_DCI0_REQUEST;
		buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
		lteFapiMsg->usMsgLen = htons(msgLenth);

		if(msgLenth > SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE)
		{
			if(SocketApp_Send4g(msgBuf) == -1)
			{
				logPrint(LOG_ERR,"buildUlDci0ReqForContinuesGrant send Failed-2 \n");
			}
		}
		// Also schedule the UlConfig for the uplink grant send
		if(msgLenth > SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE)
		{
			uint8 currentSbfn = (sfNsf & 0x000F);
			uint16 currentSfn = (sfNsf >> 4) & 0x0FFF;
			if((currentSbfn + 4) >= LTE_MAX_SUB_FRAME_NUMBER)
			{
				currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
			}
			currentSbfn = (currentSbfn + 4) % LTE_MAX_SUB_FRAME_NUMBER;
			sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));

			for(i=0; i<noOfUser; i++)
			{
				userInfo = ulGrantUser[i];
				if(userInfo != NULL)
				{
					if((userInfo->silentCallStarted == TRUE)&&(currentSbfn == 4))
					{
						ulConfigReqForContGrant = buildLteUlConfigReq(userInfo , sfNsf , eFAPI_ULSCH_CQI_RI);
					}
					else
					{
						ulConfigReqForContGrant = buildLteUlConfigReq(userInfo , sfNsf , eFAPI_ULSCH);
					}
					tail = tailForUlConfigReqQ;
					pushMsgToList(&tail ,(void*)ulConfigReqForContGrant);
					if((headForUlConfigReqQ == NULL)||(tailForUlConfigReqQ == NULL))
					{
						headForUlConfigReqQ = tailForUlConfigReqQ = tail; // Update for the first time
					}
					else
					{
						tailForUlConfigReqQ = tail; // Just update the tail node
					}
				}
				else
				{
					continue;
				}
			}
		}
	}
	else
	{
		if(noOfActiveContext == 0)
		{
			continuousGrantIndex = 0;
		}
		else
		{
			continuousGrantIndex = continuousGrantIndex + 1;
			if(continuousGrantIndex >= LTE_MAX_USER_SUPPORTED)
			{
				continuousGrantIndex = 0;
			}
		}

		if(msgHiPdu != NULL)
		{
			if(SocketApp_Send4g(msgHiPdu) == -1)
			{
				logPrint(LOG_ERR,"buildUlDci0ReqForContinuesGrant send Failed-3 \n");
			}
		}
	}
	return;
}


extern const uint16 lteTddGrant[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER];
void buildAndSendUlTddDci0ReqForContinuesGrant(uint16 sfNsf , uint8 *msgHiPdu)
{
	static uint8 continuousGrantIndex = 0;
	lteUserInfo *ulGrantUser[LTE_MAX_NO_UL_PDU_PER_TTI/2] = {NULL} , *userInfo = NULL; // Only 2 user per TTI
	uint8 i = 0, contextFound = FALSE , noOfUser = 0 , startRb = 6 , subfn = (sfNsf & 0x000F) , noOfActiveContext = 0; // Grant interval is every even TTI
	uint8 *msgBuf = NULL , lastFoundContext = 0xFF;
	uint16 msgLenth = 0;

	getNoOfUsers(&noOfActiveContext);
	//Send Grants on DL subframes 3 and 8
	if(noOfActiveContext > 0)
	{
		if(lteSelectedBandwidth == LTE_BW_N6)
		{
			startRb = 0;
		}

		for(i = continuousGrantIndex ; i < LTE_MAX_USER_SUPPORTED ; i++)
		{
			userInfo = getUserContext(i);
			
			if((userInfo != NULL) && (userInfo->continuousUlGrant == 0xFF))
			{
				userInfo->continuousUlGrant = TRUE;		
				userInfo->macLayerState = WAITING_FOR_RRC_CONN_COMPLETE;
				timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP_COMPLETE , 0 , lteUserInfoTimerCbFunction, userInfo);
				continue;	
			}
			else if((userInfo != NULL)&&(userInfo->continuousUlGrant == TRUE)&&
				(userInfo->macLayerState != WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH))
			{
				contextFound = TRUE;
				ulGrantUser[noOfUser++] = userInfo;
				lastFoundContext = i;
				if(lteSelectedBandwidth <= LTE_BW_N25) // Allocation only for one user
				{
					if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/4)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				else // For 2 users
				{
					if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/2)
					{
						continue;
					}
					else
					{
						break;
					}
				}
			}
		}

		if((contextFound == FALSE)||((noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/4)&&(lteSelectedBandwidth <= LTE_BW_N25)) || ((noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/2)&&(lteSelectedBandwidth > LTE_BW_N25)))
		{
			// Try from 0 till last found
			for(i = 0 ; i < continuousGrantIndex; i++)
			{
				userInfo = getUserContext(i);
				if((userInfo != NULL)&&(userInfo->continuousUlGrant == TRUE)&&
				   (userInfo->macLayerState != WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH))
				{
					contextFound = TRUE;
					ulGrantUser[noOfUser++] = userInfo;
					lastFoundContext = i;
					if(lteSelectedBandwidth <= LTE_BW_N25)
					{
						if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/4)
						{
							continue;
						}
						else
						{
							break;
						}
					}
					else
					{
						if(noOfUser < LTE_MAX_NO_UL_PDU_PER_TTI/2)
						{
							continue;
						}
						else
						{
							break;
						}
					}
				}

			}

		}

		if(lteSelectedBandwidth <= LTE_BW_N25)
		{
			if(noOfUser > LTE_MAX_NO_UL_PDU_PER_TTI/4)
			{
				noOfUser = LTE_MAX_NO_UL_PDU_PER_TTI/4;
			}

		}
		else
		{
			if(noOfUser > LTE_MAX_NO_UL_PDU_PER_TTI/2)
			{
				noOfUser = LTE_MAX_NO_UL_PDU_PER_TTI/2;
			}
		}
	}

	if((contextFound == TRUE)&&(noOfUser != 0))
	{
		tOCT_FAPI_L1_API_MSG * lteFapiMsg = NULL;
		tOCT_FAPI_UL_DCI_PDU_INFO *ulDci0Pdu = NULL;
		tOCT_FAPI_HI_DCI0_REQUEST *hiDci0Req = NULL;
		uint8* ulConfigReqForContGrant = NULL;
		listNode *tail = NULL;
		// First Update the next Index here
		continuousGrantIndex = lastFoundContext + 1;
		if(continuousGrantIndex >= LTE_MAX_USER_SUPPORTED)
		{
			continuousGrantIndex = 0;
		}

		if(msgHiPdu == NULL)
		{
			msgBuf = continuousGrantBuf;
			memset(msgBuf,0,256);
			msgLenth = SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE;
			lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
		}
		else
		{
			msgBuf = msgHiPdu;
			lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
			msgLenth = htons(lteFapiMsg->usMsgLen) ;
		}
		hiDci0Req = (tOCT_FAPI_HI_DCI0_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
		hiDci0Req->usSfnsf = htons(sfNsf);

		for(i=0; i<noOfUser; i++)
		{
			userInfo = ulGrantUser[i];
			if(userInfo != NULL)
			{
				//byNumOfHI = 0; //either 0(through memset) or some value don't change it
				ulDci0Pdu = (tOCT_FAPI_UL_DCI_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfDCI)*SIZE_TOCT_FAPI_UL_DCI_PDU_INFO + (hiDci0Req->byNumOfHI)*SIZE_TOCT_FAPI_UL_HI_PDU_INFO];

				hiDci0Req->byNumOfDCI++;
				ulDci0Pdu->byPduType = eFAPI_DCI_UL_PDU;
				ulDci0Pdu->byUlDCIPDUSize = SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
				ulDci0Pdu->byUlDCIFormat = eFAPI_UL_DCI_FORMAT_0;
				ulDci0Pdu->byCceIndex = CalculateLteCceIdx(FALSE,userInfo->crnti,sfNsf);
				ulDci0Pdu->usRnti = htons(userInfo->crnti);
				if(lteSelectedBandwidth > LTE_BW_N15)
				{
					ulDci0Pdu->byAggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
				}
				else
				{
					ulDci0Pdu->byAggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU/2;
				}
				
				if(userInfo->silentCallStarted == TRUE)
				{
					startRb = getStartRbForSilentCallUlAllocation(lteSelectedBandwidth);
				}
				
				userInfo->ulRiv = getCurrentRiv(userInfo->ulRiv ,&startRb);
				ulDci0Pdu->byRbStart = (userInfo->ulRiv % bwToPrb[lteSelectedBandwidth]); // Assign RIV before sending any DCI0 message
				ulDci0Pdu->byNumOfRB = (userInfo->ulRiv / bwToPrb[lteSelectedBandwidth]) + 1;

				if((lteSelectedBandwidth == LTE_BW_N6)&&(userInfo->ulRiv == 11))
				{
					ulDci0Pdu->byRbStart = 0;
					ulDci0Pdu->byNumOfRB = 6;
				}

				if(userInfo->rbStart1 == 0)
				{
					userInfo->rbStart1 = ulDci0Pdu->byRbStart;
				}
				else
				{
					userInfo->rbStart2 = ulDci0Pdu->byRbStart;
				}
				ulDci0Pdu->byMcs = userInfo->ulMcs;
				ulDci0Pdu->byCyclicShift2forDMRS = 0;
				ulDci0Pdu->byFreqHoppingenabledFlag = 0; // no hopping
				ulDci0Pdu->byFreqHoppingBits = 0;
				ulDci0Pdu->byNewDataIndication = userInfo->ndiUl; // New transmission
				if((userInfo->srRecoveryCounter == 0)||(userInfo->silentCallStarted == TRUE))
				{
					//Toggle only if ACK is received
					if(userInfo->ndiUl == 1)
					{
						userInfo->ndiUl = 0;
					}
					else
					{
						userInfo->ndiUl = 1;
					}
				}
				ulDci0Pdu->byUeTxAntennaSelection = 0;

				if((userInfo->ulSaturationFlag == TRUE)&&(userInfo->silentCallStarted == FALSE))
				{
					ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_MINUS_1;//-1//0
				}
				else if((userInfo->timingAdvance > 4)||(userInfo->silentCallStarted == TRUE))
				{
					ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_3 ;//3
				}
				else
				{
					ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_0; //2;
				}
				ulDci0Pdu->byDlAssignmentIndex = 4; // TDD
				ulDci0Pdu->byCqiRequest = 0;
				ulDci0Pdu->usTxPower = htons(LTE_SHORT_ZERO);
				//Other are not required as its fdd.
				msgLenth = msgLenth + SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
			}
		}
		lteFapiMsg->msgId = PHY_DL_HI_DCI0_REQUEST;
		buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
		lteFapiMsg->usMsgLen = htons(msgLenth);

		if(msgLenth > SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE)
		{
			if(SocketApp_Send4g(msgBuf) == -1)
			{
				logPrint(LOG_ERR,"buildAndSendUlTddDci0ReqForContinuesGrant send Failed-2 \n");
			}
		}
		// Also schedule the UlConfig for the uplink grant send
		if(msgLenth > SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE)
		{
		    // Table 8-2 k for TDD configurations 0-6
		    uint8 kValue = lteTddGrant[LTE_TDD_UD_CONFIG][subfn];
		    checkAndCorrectNextTddUlDlSubframe(&sfNsf , kValue , FALSE);

			for(i=0; i<noOfUser; i++)
			{
				userInfo = ulGrantUser[i];
				if(userInfo != NULL)
				{
					ulConfigReqForContGrant = buildLteUlConfigReq(userInfo , sfNsf , eFAPI_ULSCH);
					tail = tailForUlConfigReqQ;
					pushMsgToList(&tail ,(void*)ulConfigReqForContGrant);
					if((headForUlConfigReqQ == NULL)||(tailForUlConfigReqQ == NULL))
					{
						headForUlConfigReqQ = tailForUlConfigReqQ = tail; // Update for the first time
					}
					else
					{
						tailForUlConfigReqQ = tail; // Just update the tail node
					}
				}
				else
				{
					continue;
				}
			}
		}
	}
	else
	{
		if(noOfActiveContext == 0)
		{
			continuousGrantIndex = 0;
		}
		else
		{
			continuousGrantIndex = continuousGrantIndex + 1;
			if(continuousGrantIndex >= LTE_MAX_USER_SUPPORTED)
			{
				continuousGrantIndex = 0;
			}
		}

		if(msgHiPdu != NULL)
		{
			if(SocketApp_Send4g(msgHiPdu) == -1)
			{
				logPrint(LOG_ERR,"buildAndSendUlTddDci0ReqForContinuesGrant send Failed-3 \n");
			}
		}
	}
	return;
}



