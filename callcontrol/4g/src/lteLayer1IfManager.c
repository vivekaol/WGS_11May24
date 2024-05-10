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
* File Name   : lteLayer1IfManager.c
 *
* Description : L1-Lte ENodeB interface & message conversion
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/01/2015          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/


#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h> //For htons
#include "lteLayer1IfManager.h"
#include "linkedlist.h"
#include "logManager.h"
#include "rawSocketApi.h"
#include "lteL1IfApi.h"
#include "lteMacScheduler.h"
#include "lteMacIntfcHandler.h"
#include "timerApi.h"
#include "lteRrcMain.h"

uint8 lteTimerTickReceived ;
pthread_cond_t      lteCondTimerTickInd  ;
pthread_mutex_t     lteMutexTimerTickInd ;
// This buffer is used to receive message from L1
uint8 packetBufferLte[MAX_SIZE_OF_LTE_ETHERNET_FRAME*4];
#ifdef TEST_LTE_RACH_LOAD
uint8 rachPkt[72] = {/*0x50,0x2d,0xf4,0x08,0xc8,0xa2,0x00,0x0c,0x90,0x34,0x1f,0xae,0x52,0x01,0xff,0xff,0x20,0x00,0x00,0x34,*/0x88,0x00,0x00,0x2c,0x24,0x47,0x00,0x05,0x00,0x08,0x00,0x04,0x07,0x00,0x2f,0x03,0x00,0x08,0x00,0x04,0x06,0x00,0x2f,0x03,0x00,0x08,0x00,0x04,0x03,0x00,0x2f,0x03,0x00,0x08,0x00,0x05,0x01,0x00,0x2f,0x04,0x00,0x08,0x00,0x04,0x0b,0x00,0x2f,0x03,0x00,0x00,0x00,0x00};
uint8 rachRecvd = FALSE;
#endif
extern queue rxRlcDataQ;
extern void ulHarqIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg);
extern void ulTddHarqIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg);
extern void ulRxUlschIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg);
extern void lteUserInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
extern void buildAndSendRlcMsgToRrc(lteUserInfo *userInfo , lteMsgType_e msgType);
extern void lteStopRrcTimer(uint16 crnti);
extern void lteRlcResetHandler(uint16 crnti);
extern void buildAndSendPdcchOrderReq(lteUserInfo* userInfo);
extern uint16 bwToPrb[MAX_BANDWIDTH];
#ifdef FXL_4G_TX_JAMMER
extern int lteJamCellFound ;
#endif
extern eLteBw lteSelectedBandwidth;
extern volatile int  exitLteApp;
extern volatile int  changeEarfcn;
extern elteDupMode lteDuplxMode ;
extern pthread_mutex_t mutexlteRrcInd;
extern stateRxInd      lteRrcIndRcvdstate;
extern pthread_cond_t  condlteRrcInd;
extern pthread_t       lteRrcIndThread;
extern pthread_t       lteTimerThread;
extern lteRrcUeControlBlock lteUeControlBlock;
extern tcbTimer_t pgTimer;
extern pthread_mutex_t   mutexLteBlackListQ;
extern listNode *headForLteBlacklistedUserQ;
extern listNode *tailForLteBlacklistedUserQ;
extern const uint16 ULDL[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER];
int exitLteRrcThread = 0;
int exitLteTimerThread = 0;
uint8 *hiDci0ReqPtr = NULL;

#ifdef FEA_PICSIX_CHANGE
extern int send4gStatusInd;
#endif

void lteSetSfnSubframeNum(uint16 usSfnsf)
{
	uint16 nextSfn = 0 ;
	static uint16 timerTickSignalGenerateCounter = 0;
	uint8 nextSbn = 0;
	lteCurrentSubframeNum = usSfnsf & 0x000F;
	lteCurrentSfn = (usSfnsf >> 4) & 0x0FFF;

	nextSbn = (1 + lteCurrentSubframeNum) % LTE_MAX_SUB_FRAME_NUMBER;
	if(lteCurrentSubframeNum == 0x09)
	{
		nextSfn = (1 + lteCurrentSfn) % LTE_MAX_SYSTEM_FRAME_NUMBER;
	}
	else
	{
		nextSfn = lteCurrentSfn;
	}
#ifdef TEST_LTE_RACH_LOAD
	if((rachRecvd == FALSE)&&(((usSfnsf & 0x000F) == 0) && (((usSfnsf >> 4) & 0x0FFF) % 8 == 0)))
	{
		//logPrint(LOG_DEBUG, "dummy rach\n");
		ulRachIndHandler((tOCT_FAPI_L1_API_MSG*)rachPkt);
	}
#endif

	if(lteDuplxMode)
	{
		lteTddMacScheduler(nextSfn , nextSbn);
	}
	else
	{
		lteMacScheduler(nextSfn , nextSbn);
	}

	if(timerTickSignalGenerateCounter == TCB_RESOLUTION_4G) // 100/2 ms
	{
		timerTickSignalGenerateCounter = 0;

		pthread_mutex_lock(&lteMutexTimerTickInd);

		lteTimerTickReceived = TRUE;
		pthread_mutex_unlock(&lteMutexTimerTickInd);
		pthread_cond_signal(&lteCondTimerTickInd);

	}
	
    timerTickSignalGenerateCounter++;
}

uint16 lteGetCurrentSfNSbfn(void)
{
	return ((lteCurrentSfn<<4)|(lteCurrentSubframeNum & 0x0F));
	//*currentSfn = lteCurrentSfn;
	//*currentSbfn = lteCurrentSubframeNum;
}

uint8* buildUlHarqReq(tOCT_FAPI_L1_API_MSG * fapiMsg , uint16 sfNsf)
{
	uint8 *msgBuf = getUlTxDataBuffer();
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_HI_DCI0_REQUEST *hiDci0Req = (tOCT_FAPI_HI_DCI0_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_UL_CRC_INDICATION *ulCrcInd = (tOCT_FAPI_UL_CRC_INDICATION*)fapiMsg->abyMsgBody;
	uint16 numOfCrc = htons(ulCrcInd->usNumOfCrc) , msgLenth = SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE;
	tOCT_FAPI_UL_CRC_PDU_IND *crcPduInd = NULL;
	lteUserInfo* userInfo = NULL;
	tOCT_FAPI_UL_HI_PDU_INFO *ulHiPdu = NULL;
	hiDci0Req->usSfnsf = htons(sfNsf);
	hiDci0Req->byNumOfHI = 0;
	hiDci0Req->byNumOfDCI = 0;
	while(numOfCrc > 0)
	{
		crcPduInd = (tOCT_FAPI_UL_CRC_PDU_IND*)&ulCrcInd->aCrcPduInfo[numOfCrc - 1];//&fapiMsg->abyMsgBody[SIZE_TOCT_FAPI_UL_CRC_INDICATION + indexLen];
		userInfo = userFindUsingCrnti(htons(crcPduInd->usRnti));
		if(userInfo != NULL)
		{
			//logPrint(LOG_ERR , "buildUlHarqReq , Sending UL-HArq for CRNTI = %d , MAc-STate = %d\n" , userInfo->crnti , userInfo->macLayerState);
			if((START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfHI)*SIZE_TOCT_FAPI_UL_HI_PDU_INFO + SIZE_TOCT_FAPI_UL_HI_PDU_INFO) > LTE_MAX_SIZE_BUFFER)
			{
				logPrint(LOG_ERR , "buildUlHarqReq , Buffer size is less , break\n");
				break;
			}
			ulHiPdu = (tOCT_FAPI_UL_HI_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfHI)*SIZE_TOCT_FAPI_UL_HI_PDU_INFO];
			if(ulHiPdu == NULL)
			{
				logPrint(LOG_ERR , "buildUlHarqReq , ulHiPdu is NULL break\n");
				break;
			}
			userInfo->rntiType = eFAPI_C_RNTI;
			userInfo->ulHandle = htonl(crcPduInd->ulHandle);
			hiDci0Req->byNumOfHI++;
			ulHiPdu->byPduType = eFAPI_HI_PDU;
			ulHiPdu->byHipduSize = SIZE_TOCT_FAPI_UL_HI_PDU_INFO;
			{
				if(userInfo->continuousUlGrant == FALSE)
				{
					ulHiPdu->byRbStart = (userInfo->ulRiv % bwToPrb[lteSelectedBandwidth]) ;
				}
				else
				{
					ulHiPdu->byRbStart = userInfo->rbStart1;
					userInfo->rbStart1 = 0;
					if (userInfo->rbStart2 != 0)
					{
						userInfo->rbStart1 = userInfo->rbStart2;
						userInfo->rbStart2 = 0;
					}
				
				}
			}
			ulHiPdu->byCyclicShift2forDMRS = 0;
			if(crcPduInd->byCrcFlag == eFAPI_CRC_CORRECT)
			{
				ulHiPdu->byHiValue = eFAPI_HI_ACK;
				if(userInfo->continuousUlGrant == TRUE)
				{
					userInfo->srRecoveryCounter = 0;
					if(userInfo->pdcchOrderSent == TRUE)
					{
						userInfo->pdcchOrderSent = 0xFF;
					}
				}
			}
			else
			{
				ulHiPdu->byHiValue = eFAPI_HI_NACK;
				if(userInfo->continuousUlGrant == TRUE)
				{
					if(userInfo->macLayerState >= WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL)
					{
						userInfo->continuousUlGrant = FALSE;
						userDeleteUsingCrnti(userInfo->crnti , TRUE);
					}
					else if(userInfo->macLayerState > WAITING_FOR_RRC_CONN_COMPLETE)
				 	{
						if(userInfo->silentCallStarted == TRUE)
						{
							if(userInfo->srRecoveryCounter > 25)
							{
							    if(TRUE == isTimerRunning(&userInfo->tmr))
									timerStop(&userInfo->tmr);
								
								logPrint(LOG_DEBUG , "MAC-RESET in SC for continuous NACK for Ul grant in State = %d for User = %d \n" , userInfo->macLayerState , userInfo->crnti);
								buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
								userDeleteUsingCrnti(userInfo->crnti, TRUE);
							}
							else
							{
								if(userInfo->pdcchOrderSent == FALSE)
								{
									buildAndSendPdcchOrderReq(userInfo);
								}
								else
								{
									if((userInfo->pdcchOrderSent == 0xFF)&&((userInfo->srRecoveryCounter % 10) == 0))
									{
										if(userInfo->srRecoveryCounter != 0)
										{
											buildAndSendPdcchOrderReq(userInfo);
										}
									}
								}
							}
						}
						else
						{
							if(userInfo->srRecoveryCounter > 750)
							{
							    if(TRUE == isTimerRunning(&userInfo->tmr))
									timerStop(&userInfo->tmr);
								logPrint(LOG_DEBUG , "MAC-RESET for continuous NACK for Ul grant in State = %d for User = %d \n" , userInfo->macLayerState , userInfo->crnti);
								buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
								userDeleteUsingCrnti(userInfo->crnti, TRUE);
							}
						}

					}
					else if((userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE) && (userInfo->srRecoveryCounter > 2000))
					{
					    if(TRUE == isTimerRunning(&userInfo->tmr))
							timerStop(&userInfo->tmr);
						logPrint(LOG_DEBUG , "MAC-RESET before Attach for continuous NACK for Ul grant in State = %d for User = %d \n" , userInfo->macLayerState , userInfo->crnti);
						buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
						userDeleteUsingCrnti(userInfo->crnti, TRUE);
					}
					else
					{
						//logPrint(LOG_DEBUG , "State of Handling = %d and Counter = %d\n",userInfo->macLayerState , userInfo->srRecoveryCounter);
					}
					userInfo->srRecoveryCounter++;
				}
			}
			ulHiPdu->byIPHICH = 0;
			ulHiPdu->usTxPower = htons(LTE_PHICH_POWER_OFFSET_VALUE);
			msgLenth = msgLenth + SIZE_TOCT_FAPI_UL_HI_PDU_INFO;
		}
		numOfCrc--;
	}
	if(msgLenth > SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE)
	{
		lteFapiMsg->msgId = PHY_DL_HI_DCI0_REQUEST;
		buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
		lteFapiMsg->usMsgLen = htons(msgLenth);
		return msgBuf;
	}
	else
	{
		return NULL;
	}
}
#ifdef LTE_USE_SR
uint8* buildUlDci0Req(tOCT_FAPI_L1_API_MSG * fapiMsg , uint16 sfNsf)
{
	uint8 *msgBuf = getUlTxDataBuffer();
	uint8 startRb = 3;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_HI_DCI0_REQUEST *hiDci0Req = (tOCT_FAPI_HI_DCI0_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_UL_RX_SR_INDICATION *ulRxSrInd = (tOCT_FAPI_UL_RX_SR_INDICATION*)fapiMsg->abyMsgBody;
	uint16 numOfSr = htons(ulRxSrInd->usNumOfSr) , msgLenth = SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE;
	tOCT_FAPI_UL_SR_PDU_IND *ulSrPduInd = NULL;
	lteUserInfo* userInfo = NULL;
	tOCT_FAPI_UL_DCI_PDU_INFO *ulDci0Pdu = NULL;

	if(numOfSr > 3)
	{
		numOfSr = 3;
	}
	hiDci0Req->usSfnsf = htons(sfNsf);
	hiDci0Req->byNumOfHI = 0;
	hiDci0Req->byNumOfDCI = 0;
	while(numOfSr != 0)
	{
		ulSrPduInd = (tOCT_FAPI_UL_SR_PDU_IND*)&ulRxSrInd->aSrPduInfo[numOfSr -1];//&fapiMsg->abyMsgBody[SIZE_TOCT_FAPI_UL_SR_INDICATION + indexLen];
		userInfo = userFindUsingCrnti(htons(ulSrPduInd->usRnti));
		if(userInfo != NULL)
		{
			//logPrint(LOG_ERR , "buildUlDci0Req , Sending DCI-0 for CRNTI = %d , MAc-STate = %d\n" , userInfo->crnti , userInfo->macLayerState);
			if(userInfo->continuousUlGrant == FALSE)
			{
				userInfo->srRecoveryCounter++;
				if(userInfo->srRecoveryCounter > 10)
				{
				    if(TRUE == isTimerRunning(&userInfo->tmr))
						timerStop(&userInfo->tmr);
					buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
					userDeleteUsingCrnti(userInfo->crnti , TRUE);
					numOfSr--;
					continue;
				}
			}

			if(userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)
			{
				//timerStop(&userInfo->tmr); // Till here MAC is handling . After this state let RLC handle
				if(TRUE == isTimerRunning(&userInfo->tmr))
				{
				    timerStop(&userInfo->tmr);
				}
				
				timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP_COMPLETE/3 , 0 , lteUserInfoTimerCbFunction, userInfo);//5sec
			}
			if((userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)||
			   (userInfo->macLayerState == ACK_RECEIVED_FOR_RRC_CONN_REL) ||
			   (userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH))
			{
				if((START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfDCI)*SIZE_TOCT_FAPI_UL_DCI_PDU_INFO + SIZE_TOCT_FAPI_UL_DCI_PDU_INFO) > LTE_MAX_SIZE_BUFFER )
				{
					logPrint(LOG_ERR , "buildUlDci0Req , Buffer size is less , break\n");
					break;
				}
				ulDci0Pdu = (tOCT_FAPI_UL_DCI_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfDCI)*SIZE_TOCT_FAPI_UL_DCI_PDU_INFO];
				if(ulDci0Pdu == NULL)
				{
					logPrint(LOG_ERR , "buildUlDci0Req , ulDci0Pdu is NULL break\n");
					break;
				}
				hiDci0Req->byNumOfDCI++;
				ulDci0Pdu->byPduType = eFAPI_DCI_UL_PDU;
				ulDci0Pdu->byUlDCIPDUSize = SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
				ulDci0Pdu->byUlDCIFormat = eFAPI_UL_DCI_FORMAT_0;
				ulDci0Pdu->byCceIndex = userInfo->cceIndex[(sfNsf & 0x000F)];
				ulDci0Pdu->usRnti = htons(userInfo->crnti);
				ulDci0Pdu->byAggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
				userInfo->ulRiv = getCurrentRiv(userInfo->ulRiv ,&startRb);
				ulDci0Pdu->byRbStart = (userInfo->ulRiv % bwToPrb[lteSelectedBandwidth]); // Assign RIV before sending any DCI0 message
				ulDci0Pdu->byNumOfRB = (userInfo->ulRiv / bwToPrb[lteSelectedBandwidth]) + 1;
				ulDci0Pdu->byMcs = userInfo->ulMcs;
				ulDci0Pdu->byCyclicShift2forDMRS = 0;
				ulDci0Pdu->byFreqHoppingenabledFlag = 0; // no hopping
				ulDci0Pdu->byFreqHoppingBits = 0;
				ulDci0Pdu->byUeTxAntennaSelection = 0;
				ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_0;
				ulDci0Pdu->byCqiRequest = 0;
				ulDci0Pdu->usTxPower = htons(LTE_SHORT_ZERO);
				//Other are not required as its fdd.
				msgLenth = msgLenth + SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
			   if(lteDuplxMode)
			   {
					ulDci0Pdu->byNewDataIndication = 0;//userInfo->ndi; // New transmission
					ulDci0Pdu->byDlAssignmentIndex = 4; // TDD
			   }
		 	  else
			   {			
			   		ulDci0Pdu->byNewDataIndication = userInfo->ndi; // New transmission
			   }
					prepareUlMessageAfterSendingDlTxReq(userInfo , sfNsf);//4subframes after sending dci0 allocation peek for ulsch
		   }
		}
		numOfSr--;
	}
	lteFapiMsg->msgId = PHY_DL_HI_DCI0_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);

	return msgBuf;
}



uint8* buildTddUlDci0Req(uint16 crnti  , uint16 sfNsf)
{
	uint8 *msgBuf = getUlTxDataBuffer();
	uint8 startRb = 0;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_HI_DCI0_REQUEST *hiDci0Req = (tOCT_FAPI_HI_DCI0_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
      uint16 msgLenth = SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE;
	

	hiDci0Req->usSfnsf = htons(sfNsf);
	hiDci0Req->byNumOfHI = 0;
	hiDci0Req->byNumOfDCI = 0;

		lteUserInfo* userInfo = userFindUsingCrnti(crnti);
		if(userInfo != NULL)
		{
		   		userInfo->srRecoveryCounter++;
				if(userInfo->srRecoveryCounter > 10)
				{
				    if(isTimerRunning(&userInfo->tmr) == TRUE)
				    {
						timerStop(&userInfo->tmr);
						userInfo->tmr.parm = NULL;
				    }
					buildAndSendRlcMsgToRrc(userInfo , LTE_MSG_MAC_RESET_REQ_E);
					userDeleteUsingCrnti(userInfo->crnti , TRUE);
				}

			if(userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)
			{
				//timerStop(&userInfo->tmr); // Till here MAC is handling . After this state let RLC handle
				if(TRUE == isTimerRunning(&userInfo->tmr))
				{
					timerStop(&userInfo->tmr);
				}
				
				timerStart(&userInfo->tmr , TIMER_FOR_WAIT_RRC_CONN_SETUP_COMPLETE/3 , 0 , lteUserInfoTimerCbFunction, userInfo);//5sec
			}
			if((userInfo->macLayerState == WAITING_FOR_RRC_CONN_COMPLETE)||
			   (userInfo->macLayerState == ACK_RECEIVED_FOR_RRC_CONN_REL) ||
			   (userInfo->macLayerState == ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH))
			{

		   		if((START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfDCI)*SIZE_TOCT_FAPI_UL_DCI_PDU_INFO + SIZE_TOCT_FAPI_UL_DCI_PDU_INFO) > LTE_MAX_SIZE_BUFFER )
				{
					logPrint(LOG_ERR , "buildUlDci0Req , Buffer size is less , break\n");
					//break;
				}
				tOCT_FAPI_UL_DCI_PDU_INFO *ulDci0Pdu = (tOCT_FAPI_UL_DCI_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_HI_DCI0_REQUEST_BASE + (hiDci0Req->byNumOfDCI)*SIZE_TOCT_FAPI_UL_DCI_PDU_INFO];
				if(ulDci0Pdu == NULL)
				{
					logPrint(LOG_ERR , "buildUlDci0Req , ulDci0Pdu is NULL break\n");
					//break;
				}
				hiDci0Req->byNumOfDCI++;
				ulDci0Pdu->byPduType = eFAPI_DCI_UL_PDU;
				ulDci0Pdu->byUlDCIPDUSize = SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
				ulDci0Pdu->byUlDCIFormat = eFAPI_UL_DCI_FORMAT_0;
				ulDci0Pdu->byCceIndex = userInfo->cceIndex[(sfNsf & 0x000F)];
				ulDci0Pdu->usRnti = htons(userInfo->crnti);
				ulDci0Pdu->byAggLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_MACPDU;
				userInfo->ulRiv = getCurrentRiv(userInfo->ulRiv ,&startRb);
				ulDci0Pdu->byRbStart = (userInfo->ulRiv % bwToPrb[lteSelectedBandwidth]); // Assign RIV before sending any DCI0 message
				ulDci0Pdu->byNumOfRB = (userInfo->ulRiv / bwToPrb[lteSelectedBandwidth]) + 1;
				ulDci0Pdu->byMcs = userInfo->ulMcs;
				ulDci0Pdu->byCyclicShift2forDMRS = 0;
				ulDci0Pdu->byFreqHoppingenabledFlag = 0; // no hopping
				ulDci0Pdu->byFreqHoppingBits = 0;
				ulDci0Pdu->byNewDataIndication = 0;//userInfo->ndi; // New transmission
				ulDci0Pdu->byUeTxAntennaSelection = 0;
				ulDci0Pdu->byTpc = eFAPI_TX_POWER_CONTROL_0;
				ulDci0Pdu->byCqiRequest = 0;
				ulDci0Pdu->usTxPower = htons(LTE_SHORT_ZERO);
				ulDci0Pdu->byDlAssignmentIndex = 4; // TDD
				//Other are not required as its fdd.
				msgLenth = msgLenth + SIZE_TOCT_FAPI_UL_DCI_PDU_INFO;
				prepareUlMessageAfterSendingDlTxReq(userInfo , sfNsf);//4subframes after sending dci0 allocation peek for ulsch
		 }
	 }	
	
	lteFapiMsg->msgId = PHY_DL_HI_DCI0_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);

	return msgBuf;
}

#endif

void ltePhyParamResponseHandler(tOCT_FAPI_L1_API_MSG *lteFapiMsg)
{
	tOCT_FAPI_PARAM_RESPONSE_V1PT1 * lteFapiParamRsp = (tOCT_FAPI_PARAM_RESPONSE_V1PT1 *)lteFapiMsg->abyMsgBody;
	logPrint(LOG_DEBUG, "ltePhyParamResponseHandler Error Code = %d , NumofTlv = %d \n", lteFapiParamRsp->byErrorCode, lteFapiParamRsp->byNumOfTlv);

	if(lteFapiParamRsp->byErrorCode == eFAPI_MSG_OK)
	{
		for(uint8 i =0 ; i<lteFapiParamRsp->byNumOfTlv; i++)
		{
			if(lteFapiParamRsp->aTlvs[i].byTag == eFAPI_PHY_STATE)
				logPrint(LOG_DEBUG, "ltePhyParamResponseHandler eFAPI_PHY_STATE = %d \n",ntohs(lteFapiParamRsp->aTlvs[i].configParam.usPhyState));

			if(lteFapiParamRsp->aTlvs[i].byTag == eFAPI_DL_BANDWIDTH_SUPPORT)
				logPrint(LOG_DEBUG, "ltePhyParamResponseHandler eFAPI_DL_BANDWIDTH_SUPPORT = %d \n",ntohs(lteFapiParamRsp->aTlvs[i].configParam.usDlBandWidthSupport));

			if(lteFapiParamRsp->aTlvs[i].byTag == eFAPI_UL_BANDWIDTH_SUPPORT)
				logPrint(LOG_DEBUG, "ltePhyParamResponseHandler eFAPI_UL_BANDWIDTH_SUPPORT = %d \n",ntohs(lteFapiParamRsp->aTlvs[i].configParam.usUlBandWidthSupport));

			if(lteFapiParamRsp->aTlvs[i].byTag == eFAPI_DL_MODULATION_SUPPORT)
				logPrint(LOG_DEBUG, "ltePhyParamResponseHandler eFAPI_DL_MODULATION_SUPPORT = %d \n",ntohs(lteFapiParamRsp->aTlvs[i].configParam.usDlModulationSupport));

			if(lteFapiParamRsp->aTlvs[i].byTag == eFAPI_UL_MODULATION_SUPPORT)
				logPrint(LOG_DEBUG, "ltePhyParamResponseHandler eFAPI_UL_MODULATION_SUPPORT = %d \n",ntohs(lteFapiParamRsp->aTlvs[i].configParam.usUlModulationSupport));

			if(lteFapiParamRsp->aTlvs[i].byTag == eFAPI_PHY_ANTENNA_CAPABILITY)
				logPrint(LOG_DEBUG, "ltePhyParamResponseHandler eFAPI_PHY_ANTENNA_CAPABILITY = %d \n",ntohs(lteFapiParamRsp->aTlvs[i].configParam.usPhyAntennaCapability));
		}

		buildAndSendPhyCellConfigReq();
	}
	else
	{
		//assert(0);
	}
}

void ltePhyCellConfigResponseHandler(tOCT_FAPI_L1_API_MSG *lteFapiMsg)
{
	tOCT_FAPI_CELL_CONFIG_RESPONSE_V1PT1 * lteFapiCellConfigRsp = (tOCT_FAPI_CELL_CONFIG_RESPONSE_V1PT1 *)lteFapiMsg->abyMsgBody;
	logPrint(LOG_DEBUG, "ltePhyCellConfigResponseHandler Error Code = %d \n", lteFapiCellConfigRsp->byErrorCode);
	logPrint(LOG_DEBUG, "ltePhyCellConfigResponseHandler NumOfInvalidOrUnsupportedTLV = %d, NumOfMissingTLV = %d \n",lteFapiCellConfigRsp->byNumOfInvalidOrUnsupportedTLV , lteFapiCellConfigRsp->byNumOfMissingTLV);

	if(lteFapiCellConfigRsp->byErrorCode == eFAPI_MSG_OK)
	{
		for(uint8 i =0 ; i<lteFapiCellConfigRsp->byNumOfInvalidOrUnsupportedTLV; i++)
		{
			if(lteFapiCellConfigRsp->aListOfTLV[i].byTag == eFAPI_PHY_STATE)
				logPrint(LOG_DEBUG, "ltePhyCellConfigResponseHandler eFAPI_PHY_STATE = %d \n",ntohs(lteFapiCellConfigRsp->aListOfTLV[i].configParam.usPhyState));

			if(lteFapiCellConfigRsp->aListOfTLV[i].byTag == eFAPI_SFN_SF)
			{
				logPrint(LOG_DEBUG, "ltePhyCellConfigResponseHandler eFAPI_SFN_SF = %d \n",ntohs(lteFapiCellConfigRsp->aListOfTLV[i].configParam.usSfnsf));
			}

		}
		buildAndSendPhyStartReq();
	}

}

void ltePhyStopIndicationHandler(tOCT_FAPI_L1_API_MSG *lteFapiMsg)
{
	logPrint(LOG_DEBUG, "ltePhyStopIndicationHandler \n");
}
void ltePhyErrorIndicationHandler(tOCT_FAPI_L1_API_MSG *lteFapiMsg)
{
	tOCT_FAPI_ERROR_INDICATION_V1PT1 *errInd = (tOCT_FAPI_ERROR_INDICATION_V1PT1*)lteFapiMsg->abyMsgBody;
	if(errInd->byErrorCode != 9)
	logPrint(LOG_DEBUG, "ltePhyErrorIndicationHandler Error = %d  LastSfn = %d , LastSbfn = %d \n" , errInd->byErrorCode , lteCurrentSfn ,lteCurrentSubframeNum);
}
void ltePhyUlSubframeIndicationHandler(tOCT_FAPI_L1_API_MSG *lteFapiMsg)
{
	tOCT_FAPI_SUBFRAME_INDICATION * sfInd = (tOCT_FAPI_SUBFRAME_INDICATION*)lteFapiMsg->abyMsgBody;
	lteSetSfnSubframeNum(ntohs(sfInd->usSfnsf));
}
void ltePhyUlSrsIndicationHandler(tOCT_FAPI_L1_API_MSG *lteFapiMsg)
{
	logPrint(LOG_DEBUG, "ltePhyUlSrsIndicationHandler \n");
}

void ltePhyUlRxCqiIndicationHandler(tOCT_FAPI_L1_API_MSG *lteFapiMsg)
{
	//tOCT_FAPI_UL_RX_CQI_INDICATION *ulRxCqi = (tOCT_FAPI_UL_RX_CQI_INDICATION*)lteFapiMsg->abyMsgBody;
	//logPrint(LOG_DEBUG, "ltePhyUlRxCqiIndicationHandler UlCqi = %d , TA = %d\n" ,htons(ulRxCqi->aCqiPduInfo[0].usRnti) , ulRxCqi->aCqiPduInfo[0].byUlCqi , htons(ulRxCqi->aCqiPduInfo[0].usTimingAdvance) );
}

#ifdef LTE_USE_SR
void ulRxSrIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg)
{
	uint8* dci0Pdu = NULL , currentSbfn = 0;
	uint16 currentSfn = 0 , sfNsf = 0;
	tOCT_FAPI_UL_RX_SR_INDICATION *ulRxSrInd = (tOCT_FAPI_UL_RX_SR_INDICATION*)lteFapiMsg->abyMsgBody;
	sfNsf = htons(ulRxSrInd->usSfnsf);
	//Get the Current sfn and subframe number
		currentSfn = (((sfNsf)>>4) & 0x0FFF);
		currentSbfn = ((sfNsf) & 0x000F ) % LTE_MAX_SUB_FRAME_NUMBER;

	if (lteDuplxMode) // TDD Case : Currently for UlDL : 1 , PHICH ACK is updated
	{            
		if ((currentSbfn == 2)||(currentSbfn == 7))   // + 4 Special Subframe case
		{
			if((currentSbfn + 4 ) >= LTE_MAX_SUB_FRAME_NUMBER)
			{
				currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
			}
			currentSbfn = (((sfNsf) & 0x000F ) + 4) % LTE_MAX_SUB_FRAME_NUMBER;
		   	sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
		}
		else if ((currentSbfn == 3) || (currentSbfn == 8))
		{
       		sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
		      checkAndCorrectNextTddUlDlSubframe(&sfNsf , 4 , TRUE);
		      currentSbfn = ((sfNsf) & 0x000F )  % LTE_MAX_SUB_FRAME_NUMBER;			
		}
	}
	else
	{
		if((currentSbfn + 4 ) >= LTE_MAX_SUB_FRAME_NUMBER)
		{
			currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
		}
		currentSbfn = (((sfNsf) & 0x000F ) + 4) % LTE_MAX_SUB_FRAME_NUMBER;
	   	sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
	}

	dci0Pdu = buildUlDci0Req(lteFapiMsg , sfNsf);
	pushMacPduToUlSchedulerQ(currentSbfn , dci0Pdu);
	return;
}
#endif

/*
Table 9.1.2-1:   for TDD
TDD UL/DL
Configuration	subframe index n
	0	1	2	3	4	5	6	7	8	9
0			4	7	6			4	7	6
1			4	6				4	6
2			6					6
3			6	6	6
4			6	6
5			6
6			4	6	6			4	7	*/
const uint16 pHich[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER] = {
																	{0,0,4,7,6,0,0,4,7,6},
																	{0,0,4,6,0,0,0,4,6,0},
																	{0,0,6,0,0,0,0,6,0,0},
																	{0,0,6,6,6,0,0,0,0,0},
																	{0,0,6,6,0,0,0,0,0,0},
																	{0,0,6,0,0,0,0,0,0,0},
																	{0,0,4,6,6,0,0,4,7,0},
																};

void ulCrcIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg)
{
	//uint8* hiPdu = NULL , currentSbfn = 0;
	uint8 currentSbfn = 0;
	tOCT_FAPI_UL_CRC_INDICATION *ulCrcInd = (tOCT_FAPI_UL_CRC_INDICATION*)lteFapiMsg->abyMsgBody;
	uint16 currentSfn = 0 , sfNsf = 0 ;
	sfNsf = htons(ulCrcInd->usSfnsf);
	//Get the Current sfn and subframe number
	currentSfn = (((sfNsf)>>4) & 0x0FFF);
	currentSbfn = ((sfNsf) & 0x000F ) % LTE_MAX_SUB_FRAME_NUMBER;

	if (lteDuplxMode) // TDD Case : Currently for UlDl : 1 , PHICH ACK is updated
	{
		if(ULDL[LTE_TDD_UD_CONFIG][currentSbfn] == LTE_TDD_UPLINK)
		{
			uint8 pHich_value = pHich[LTE_TDD_UD_CONFIG][currentSbfn];
			/*uint8 sbf =  (currentSbfn + pHich_value) % LTE_MAX_SUB_FRAME_NUMBER ;
			if(ULDL[LTE_TDD_UD_CONFIG][sbf] == LTE_TDD_SSUBFRAME)
			{
				if((currentSbfn + pHich_value ) >= LTE_MAX_SUB_FRAME_NUMBER)
				{
					currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
				}
				currentSbfn = (((sfNsf) & 0x000F ) + pHich_value) % LTE_MAX_SUB_FRAME_NUMBER;
			   	sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
			}
			else */
			{
				//sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F)); // n+6 case
			    checkAndCorrectNextTddUlDlSubframe(&sfNsf , pHich_value , TRUE);
			    //currentSbfn = ((sfNsf) & 0x000F )  % LTE_MAX_SUB_FRAME_NUMBER;
			}
		}		
	}
	else
	{
		if((currentSbfn + 4 ) >= LTE_MAX_SUB_FRAME_NUMBER)
		{
			currentSfn = (currentSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
		}
		currentSbfn = (((sfNsf) & 0x000F ) + 4) % LTE_MAX_SUB_FRAME_NUMBER;
	   	sfNsf = ((currentSfn<<4)|(currentSbfn & 0x0F));
	}
	hiDci0ReqPtr = buildUlHarqReq(lteFapiMsg , sfNsf);
/*
		if(lteDuplxMode)
		{
			uint8 *hiPdu = NULL ;
			hiPdu = buildUlHarqReq(lteFapiMsg , sfNsf);
			if (hiPdu != NULL)
			pushMacPduToUlSchedulerQ(currentSbfn, hiPdu);
		}
		else
		{	
			hiDci0ReqPtr = buildUlHarqReq(lteFapiMsg , sfNsf);  
		}
*/
	return;
}

void deleteAllUserForChangeEarfcn()
{
   uint16  crntiIdx;
   for (crntiIdx = LTE_C_RNTI_START; crntiIdx < (LTE_C_RNTI_START+LTE_MAX_USER_SUPPORTED); crntiIdx++)
   {
       lteUserInfo* userInfo = userFindUsingCrnti(crntiIdx);
       if((NULL != userInfo) && (TRUE == userInfo->inUse))
       {
            if(TRUE == isTimerRunning(&userInfo->tmr))
            	timerStop(&userInfo->tmr);

            if(userInfo->macLayerState > WAITING_FOR_RRC_CONN_COMPLETE)
            {
                  lteStopRrcTimer(crntiIdx);
                  lteRlcResetHandler(crntiIdx);
            }
            userDeleteUsingCrnti(crntiIdx , FALSE);
       }
   }
   
   if(isTimerRunning(&pgTimer) == TRUE)
   {
       timerStop(&pgTimer);
   }
  
   pthread_mutex_lock(&mutexLteBlackListQ);
   listNode *current = headForLteBlacklistedUserQ;
   lteblackListedUserInfo *blInfo = NULL;

   while(current != NULL)
   {
       blInfo = (lteblackListedUserInfo*)current->msg;
       if(NULL != blInfo)
       {
           blInfo->lteSilentCallStarted = FALSE;
           blInfo->ueCheckCntr = 0;
           blInfo->ueCheckFlag = FALSE;
           blInfo->blRemoveFlag = FALSE;
		   
           if(isTimerRunning(&blInfo->blTimer) == TRUE)
           {
                timerStop(&blInfo->blTimer);
                blInfo->blTimer.parm = NULL;
           }
       }
       current = current->next;
    }

    pthread_mutex_unlock(&mutexLteBlackListQ);
}

// Receiver thread
void * lteL1MsgHandler(void *nothing)
{
  uint8 * pLteFapiMsgStart;
  uint16  crntiIdx;
  tOCT_FAPI_L1_API_MSG * lteFapiMsg;
  stick_this_thread_to_core(2);
  logPrint(LOG_DEBUG , "lteL1MsgHandler Thread Initialized\n");
  initQueue(&rxRlcDataQ);
  while(TRUE)
  {
    if((SocketApp_Recv4g(packetBufferLte,MAX_SIZE_OF_LTE_ETHERNET_FRAME*4) <= 0)||(exitLteApp == TRUE))
    {
    	logPrint(LOG_ERR , "LTE L1 thread strated exiting exitFlag = %d\n",exitLteApp);
		// Delete All the Users latched
		for (crntiIdx = LTE_C_RNTI_START; crntiIdx < (LTE_C_RNTI_START+LTE_MAX_USER_SUPPORTED); crntiIdx++)
		{
			lteUserInfo* userInfo = userFindUsingCrnti(crntiIdx);
			if((NULL != userInfo) && (TRUE == userInfo->inUse))
			{
			    if(TRUE == isTimerRunning(&userInfo->tmr))
					timerStop(&userInfo->tmr);
				
				if(userInfo->macLayerState > WAITING_FOR_RRC_CONN_COMPLETE)
				{
					lteStopRrcTimer(crntiIdx);
					lteRlcResetHandler(crntiIdx);
				}
				userDeleteUsingCrnti(crntiIdx , TRUE);
			}
		}

        if(isTimerRunning(&pgTimer) == TRUE)
        {
            timerStop(&pgTimer);
        }
		// Deleting all Black List Users
		pthread_mutex_lock(&mutexLteBlackListQ);
		listNode *current = headForLteBlacklistedUserQ;
		listNode *tmp = NULL;
		lteblackListedUserInfo *blInfo = NULL;
		while(current != NULL)
		{
			tmp = current;
			if(current != NULL)
			{
				current = current->next;
			}

			blInfo = (lteblackListedUserInfo*)tmp->msg;
			if(NULL != blInfo)
			{
			    if(isTimerRunning(&blInfo->blTimer) == TRUE)
    			{
					timerStop(&blInfo->blTimer);
					blInfo->blTimer.parm = NULL;
    			}
			}

			free(tmp->msg);
			free(tmp);
		}

		headForLteBlacklistedUserQ = tailForLteBlacklistedUserQ = NULL;
		pthread_mutex_unlock(&mutexLteBlackListQ);

		// Exit LTE RRC Indication Tread
		exitLteRrcThread = 1;
		pthread_mutex_lock(&mutexlteRrcInd);
		lteRrcIndRcvdstate = STATE_RXIND_RECEIVED;
		pthread_mutex_unlock(&mutexlteRrcInd);
		pthread_cond_signal(&condlteRrcInd);

		if((lteRrcIndThread !=0)&&(pthread_join(lteRrcIndThread, NULL)))
		{
			//logPrint(LOG_ERR , "RRC Receive Thread join failed");
		}
		exitLteRrcThread = 0;

		// Exit LTE Timer Thread
		exitLteTimerThread = 1;
		pthread_mutex_lock(&lteMutexTimerTickInd);
		lteTimerTickReceived = TRUE;
		pthread_mutex_unlock(&lteMutexTimerTickInd);
		pthread_cond_signal(&lteCondTimerTickInd);

		if((lteTimerThread != 0)&&(pthread_join(lteTimerThread, NULL)))
		{
			//logPrint(LOG_ERR , "Timer Thread join failed");
		}
		exitLteTimerThread = 0;

		if(exitLteApp == TRUE)
		{
			logPrint(LOG_ERR , "ALL LTE THREAD EXITED Normally\n");
		}
		else
		{
			logPrint(LOG_ERR , "lteL1MsgHandler Length of Received Message is less than or equal to zero length \n");
			logPrint(LOG_ERR , "ALL LTE THREAD EXITED Abnormally\n");
#ifdef FEA_PICSIX_CHANGE
                        send4gStatusInd = TRUE;
                        sendSystemStatusIndication(FXL_4G_IDC, FXL_ERROR);
#endif
		}
		// Exit LTE L1 Message Handler
		pthread_exit(NULL);
    }
    else if (changeEarfcn == TRUE)
    {
        continue;
    }
    else
    {
        if(exitLteApp == TRUE)
        {
            continue;
        }

      	lteEthernetFrameHeader* lteL1EthernetMsgFrame = (lteEthernetFrameHeader *) packetBufferLte;
    	if (lteL1EthernetMsgFrame->lteEtherType != ntohs(LTE_OCT_SDR_ETH_PROTOCOL))
    	{
    		logPrint(LOG_ERR, "Message for different Protocol = %d received\n",ntohs(lteL1EthernetMsgFrame->lteEtherType));
			continue;
    	}
     	pLteFapiMsgStart = (uint8*)((uint8*)packetBufferLte + sizeof(lteEthernetFrameHeader));
    	lteFapiMsg = (tOCT_FAPI_L1_API_MSG*)pLteFapiMsgStart;
		if((SIZE_TOCT_FAPI_L1_API_MSG + htons(lteFapiMsg->usMsgLen)) > (LTE_MAX_SIZE_ULSCH_BUFFER))
		{
			logPrint(LOG_ERR, "Huge Message Size = %d received from L1 \n",(SIZE_TOCT_FAPI_L1_API_MSG + htons(lteFapiMsg->usMsgLen)));
			continue;
		}
		switch(lteFapiMsg->msgId)
		{
			case PHY_UL_SUBFRAME_INDICATION:
			{
				ltePhyUlSubframeIndicationHandler(lteFapiMsg);
#ifdef TEST_LTE_RACH_LOAD
				rachRecvd = FALSE;
#endif
			}
			break;
			case PHY_UL_CRC_INDICATION:
			{
				ulCrcIndHandler(lteFapiMsg);
			}
			break;
			case PHY_UL_HARQ_INDICATION:
			{
				if(lteDuplxMode)
					ulTddHarqIndHandler(lteFapiMsg);
				else
					ulHarqIndHandler(lteFapiMsg);
			}
			break;
			case PHY_UL_RX_ULSCH_INDICATION:
			{
				ulRxUlschIndHandler(lteFapiMsg);
			}
			break;
			case PHY_UL_RACH_INDICATION:
			{
#ifdef FXL_4G_TX_JAMMER
				if(!lteJamCellFound)
#endif
				{
					ulRachIndHandler(lteFapiMsg);
				}
				
#ifdef TEST_LTE_RACH_LOAD
				rachRecvd = TRUE;
				logPrint(LOG_DEBUG, "Real Rach recevd \n");
#endif
			}
			break;
#ifdef LTE_USE_SR
			case PHY_UL_RX_SR_INDICATION:
			{
				ulRxSrIndHandler(lteFapiMsg);
			}
#endif
			break;
			case PHY_PARAM_RESPONSE:
			{
				ltePhyParamResponseHandler(lteFapiMsg);
			}
			break;
			case PHY_CELL_CONFIG_RESPONSE:
			{
				ltePhyCellConfigResponseHandler(lteFapiMsg);
			}
			break;
			case PHY_STOP_INDICATION:
			{
				ltePhyStopIndicationHandler(lteFapiMsg);
			}
			break;
			case PHY_ERROR_INDICATION:
			{
				//ltePhyErrorIndicationHandler(lteFapiMsg);
			}
			break;
			case PHY_UL_SRS_INDICATION:
			{
				ltePhyUlSrsIndicationHandler(lteFapiMsg);
			}
			break;
			case PHY_UL_RX_CQI_INDICATION:
			{
				ltePhyUlRxCqiIndicationHandler(lteFapiMsg);
			}
			break;
			default:
			{
				logPrint(LOG_ERR, "Unknown Message received from PHY = %d \n",lteFapiMsg->msgId);
			}
			break;

		}//switch

    }//else

  }//while
  return (void*) -1;
}//clL1Receiver()


void * lteTimerTickHandler(void *nothing)
{
	int ret = 0;
    // main loop
	stick_this_thread_to_core(0);
	logPrint(LOG_ERR, "lteTimerTickHandler Timer Thread Started\n");
    while(TRUE)
    {
		pthread_mutex_lock(&lteMutexTimerTickInd);

		while (lteTimerTickReceived != TRUE)
		pthread_cond_wait(&lteCondTimerTickInd, &lteMutexTimerTickInd);
		if(exitLteTimerThread)
		{
            lteTimerTickReceived = FALSE;
			pthread_mutex_unlock(&lteMutexTimerTickInd);
			pthread_exit(NULL);
		}
		lteTimerTickReceived = FALSE ;
		pthread_mutex_unlock(&lteMutexTimerTickInd);

		timerTick();
    }
    return (void*)ret;
}




