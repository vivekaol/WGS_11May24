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
* File Name   : lteRrcMain.c
 *
* Description : LTE RRC Interface Layer functions header
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------------
* 09/04/2015          			 Suresh Kumar Garikipati			   Initial File Creation
*#############################################################################################
*/

#include <assert.h>
#include "lteL2Interface.h"
#include "lteAsn1Def.h"
#include "lteAsn1IntfcHandler.h"
#include "lteRrcMain.h"
#include "logManager.h"
#include "lteRrcIntfcHandler.h"
#include "lteMacIntfcHandler.h"
#include "timerApi.h"
#include "lteMacIntfcHandler.h"
#include "fxLSocketInterfaceApi.h"
#include "ratSocketItf.h"
#include "linkedlist.h"
lteRrcUeControlBlock lteUeControlBlock;
fxL4gRegistrationAttemptedInd regInd;
extern void writeToExternalSocketInterface(uint8* msgBuf , uint16 msgLen);
extern void generateSib1WithNewTA();
//ASHU ASN.1 Change
extern void generateSib1WithNewTARrcThrd();
//ASHU ASN.1 Change
extern ConfigList* getConfigUeIdListPtr();
extern int idCatcherLteEarfcn;
extern uint8 lteRrcRedirectFlag;
extern uint8 lteRrcPrmRedirectFlag;
extern uint8 enableAttRejCause;
extern uint8 lteWlRejCause;
extern volatile int  exitLteApp;
extern elteDupMode lteDuplxMode ;
extern int idCatcherLteWlRedirEarfcn;
extern fxL4gConfigureIdCatcherParamsCmd lastLteIdCatcherConfigCmd;
pthread_mutex_t   mutexLteBlackListQ  = PTHREAD_MUTEX_INITIALIZER;
tcbTimer_t pgTimer;
uint8 sibModTimerStarted = FALSE;
lteL2InftMsg_t pagingTimerStart;
lteDlPagingStruct gPageImsi = {0};
listNode *headForLteBlacklistedUserQ = NULL;
listNode *tailForLteBlacklistedUserQ = NULL;
void decodeLastTacAndCM(int ueIndex , unsigned char *pNasMsg);
void sendNeighCellMeasReportIndToClient(unsigned int ueIndex);
void sendBLRlFailureInd(unsigned int ueIndex);
void removeTargetPagingAfterUERedirected(int ueIndex);
void sendStartSibchangePagingTimerMsgToSelf(void);
float rsrqIndB[35] = {-20,-19.5,-19,-18.5,-18,-17.5,-17,-16.5,-16,-15.5,-15,-14.5,-14,-13.5,-13,-12.5,-12,-11.5,-11,-10.5,-10,-9.5,-9,-8.5,-8,-7.5,-7,-6.5,-6,-5.5,-5,-4.5,-4,-3.5,-3 };
uint8 pageMsg[24];
uint8* getPagingAsnEncodedMsg(lteDlPagingStruct *inRrcPagingBuf);
uint8* getSTmsiPagingAsnEncodedMsg(lteDlPagingStruct *inRrcPagingBuf);

void sendMsgToMacToRemovePagingReq(lteblackListedUserInfo *blUser);
void send4gBlOutOfServiceInd(uint8* imsi);
void handleRrcConnKeepAliveTimer(tcbTimer_t *pTimer, void *pUeIndex);
#ifdef FXL_BL_UE_POWER_OFF
void sendBLUePowerOffInd(unsigned int ueIndex);
#endif
uint8 checkDefaultconfigOfList(void);

extern uint8 lteSilentCallStarted;
#define LTE_RSSI_POWER_OFFSET 12

/*
 *############################################################################
 * Method Name : sendIndicationToClient
 *
 * Description : This function send Information to TCP Client
 *
 * Parameters	: ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void sendIndicationToClient(int ueIndex)
{
    if(TRUE == exitLteApp)
    {
       return;
    }   

    //Send indication to Tcp Client
    memset(&regInd , 0 , sizeof(fxL4gRegistrationAttemptedInd));
    if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
    {
		regInd.listType = FXL_BLACKUSERSLIST;
		logPrint(LOG_DEBUG, "User = %d : BLACKLISTING IMSI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imsi);		
		lteblackListedUserInfo* blackUserInfo = blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi , FALSE);
		if(!lteRrcRedirectFlag)
		{
			if(blackUserInfo != NULL)
			{
	            if(TRUE == blackUserInfo->redirectEnabled)
	            {
	                sendMsgToMacToRemovePagingReq(blackUserInfo);

	                blackUserInfo->redirectEnabled = FALSE;
	                if (NULL != blackUserInfo->pRrcConRelWithRedirect)
	                {
	                    free (blackUserInfo->pRrcConRelWithRedirect);
	                    blackUserInfo->pRrcConRelWithRedirect = NULL;
	                }
	                blackUserInfo->rrcConRelWithRedirectLen = 0;
	            }
				else					
				{
					if(blackUserInfo->lteSilentCallStarted == FALSE)
					{
						buildAndEncodeRrcPagingMsg(ueIndex);
					}
			    }
            }
	  }
	  else
	  {
		  removeTargetPagingAfterUERedirected(ueIndex);
	  }
    }
    else
    {
		regInd.listType = FXL_WHITEUSERSLIST;
		logPrint(LOG_DEBUG, "User = %d : WHITELISTING IMSI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imsi);
    }


	regInd.timingAdvance = lteUeControlBlock.lteueSpecificData[ueIndex].timingAdvance;
	regInd.guti.mmecode = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mmecode;
	regInd.guti.mmegrpID = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mmegrpID;
	regInd.guti.mtmsi = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mtmsi;
	regInd.guti.plmn.mcc[0] = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mcc[0];
	regInd.guti.plmn.mcc[1] = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mcc[1];
	regInd.guti.plmn.mcc[2] = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mcc[2];
	regInd.guti.plmn.mnc[0] = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mnc[0];
	regInd.guti.plmn.mnc[1] = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mnc[1];
	regInd.guti.plmn.mnc[2] = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mnc[2];
	regInd.guti.plmn.mccLength = regInd.guti.plmn.mncLength = 3;

	memcpy(regInd.imeiStr , lteUeControlBlock.lteueSpecificData[ueIndex].imei , MAX_IDENTITY_LENGTH_STR_4G);
	memcpy(regInd.imsiStr , lteUeControlBlock.lteueSpecificData[ueIndex].imsi , MAX_IDENTITY_LENGTH_STR_4G);

	if(strlen(regInd.imsiStr) < 15)
	{
		return;
	}

	regInd.rsrp = (lteUeControlBlock.lteueSpecificData[ueIndex].ulRssiPerPrb) * -1;

    /* Fill Rssi */
	regInd.rssi = regInd.rsrp + lteUeControlBlock.lteueSpecificData[ueIndex].snr;

    regInd.rsrq = ((lteUeControlBlock.lteueSpecificData[ueIndex].snr) * -1) + LTE_RSSI_POWER_OFFSET;

    /* Fill Emergency Call Indication */
	regInd.emergencyCallIndication = lteUeControlBlock.lteueSpecificData[ueIndex].emeCallAttemptedInd;

    /* Fill Last TAC */
    regInd.lastTac = lteUeControlBlock.lteueSpecificData[ueIndex].lastTac;

    /* Fill Classmark 2 */
    memcpy(regInd.encodedCM2, lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2, 4);

    /* Fill Classmark 3 */
    regInd.lengthOfCM3 = lteUeControlBlock.lteueSpecificData[ueIndex].lengthOfCM3;
    memcpy(regInd.encodedCM3, lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM3, regInd.lengthOfCM3);

    /* Fill Last LAC */
    regInd.lastLac = lteUeControlBlock.lteueSpecificData[ueIndex].lastLac;
            
    regInd.hdr.msgLength = sizeof(fxL4gRegistrationAttemptedInd);
	regInd.hdr.msgType = FXL_4G_REGISTRATION_ATTEMPTED_IND;
	regInd.hdr.rat = FXL_RAT_4G;

    writeToExternalSocketInterface((uint8*)&regInd , sizeof(fxL4gRegistrationAttemptedInd));
}

void triggerPagingForBlUsers(int ueIndex)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

    if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
    {
		if(!lteRrcRedirectFlag)
        {
            lteblackListedUserInfo* blackUserInfo = blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi , FALSE);
            if(blackUserInfo != NULL)
            {
                 if(TRUE == blackUserInfo->redirectEnabled)
                 {
                    sendMsgToMacToRemovePagingReq(blackUserInfo);

                    blackUserInfo->redirectEnabled = FALSE;
                    if (NULL != blackUserInfo->pRrcConRelWithRedirect)
                    {
                        free (blackUserInfo->pRrcConRelWithRedirect);
                        blackUserInfo->pRrcConRelWithRedirect = NULL;
                    }
                    blackUserInfo->rrcConRelWithRedirectLen = 0;
                 }
            }
        }
    }
}

fxL4gMeasurementReportInd meas4gind ;

/*
 *############################################################################
 * Method Name : sendMeasReportIndToClient
 *
 * Description : This function send Measurement Report to TCP Client
 *
 * Parameters	: ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void sendMeasReportIndToClient(lteblackListedUserInfo* blackUserInfo)
{
 	if(TRUE == exitLteApp)
	 {
   		return;
	 }
	if((blackUserInfo != NULL) && (lteSilentCallStarted == TRUE))
	{
		meas4gind.hdr.msgType = FXL_4G_MEASUREMENT_REPORT_IND;
		meas4gind.hdr.rat = FXL_RAT_4G;
		meas4gind.hdr.msgLength = sizeof(fxL4gMeasurementReportInd);

		meas4gind.rsrp = blackUserInfo->rsrp;
		meas4gind.rsrq = blackUserInfo->rsrq;
		memcpy(meas4gind.imsiStr , blackUserInfo->userImsi_str , SIZE_OF_IDENTITY_STR);

		writeToExternalSocketInterface((uint8*)&meas4gind , sizeof(fxL4gMeasurementReportInd));
	}
}


/*
 *############################################################################
 * Method Name : sendUeRssiPhrReportIndToClient
 *
 * Description : This function send Measurement Report to TCP Client
 *
 * Parameters	: ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void sendUeRssiPhrReportIndToClient(lteblackListedUserInfo* blackUserInfo)
{
    if(TRUE == exitLteApp)
	{
   		return;
	}
	if((blackUserInfo != NULL) && (blackUserInfo->ulRssiPhr != 0) && (lteSilentCallStarted == TRUE))
	{
		meas4gind.hdr.msgType = FXL_4G_MEASUREMENT_REPORT_IND;
		meas4gind.hdr.rat = FXL_RAT_4G;
		meas4gind.hdr.msgLength = sizeof(fxL4gMeasurementReportInd);

		meas4gind.rsrp = blackUserInfo->ulRssiPhr;
		meas4gind.rsrq = 0;
		memcpy(meas4gind.imsiStr , blackUserInfo->userImsi_str , SIZE_OF_IDENTITY_STR);

		writeToExternalSocketInterface((uint8*)&meas4gind , sizeof(fxL4gMeasurementReportInd));

		//logPrint(LOG_DEBUG , "sendUeRssiPhrReportIndToClient RSRP = %d\n",blackUserInfo->ulRssiPhr);
	}

}



/*
 *############################################################################
 * Method Name : lteUlDcchHandler
 *
 * Description : This procedure Handles the Uplink DCCH messages
 *
 * Parameters	: lteL2IntfData_t
 *
 * Returns 	: None
 *############################################################################
 */
void lteUlDcchHandler (lteL2IntfData_t *pRlcMsgData)
{
        if(TRUE == exitLteApp)
	{
       		return;
    	}

	unsigned int ueIndex = pRlcMsgData->crnti - LTE_C_RNTI_START;
	int nasIndex = 0;
	uint8* bufPtr = (uint8*) &pRlcMsgData->dataBuf[1]; // Moving one more byte to start RRC PDU, first 0th Byte is PDCP header
	uint8 encodingLength = pRlcMsgData->size - 1;
	logPrint(LOG_DEBUG,"lteUlDcchHandler - Decoding Uplink RRC Pdu Size = %d in RrcUeState = %d CRNTI = %d\n",pRlcMsgData->size , lteUeControlBlock.lteueSpecificData[ueIndex].ueState , pRlcMsgData->crnti);

	if((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CON_SETUP_COMPLETE_LTE)||(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_RELEASED))
	{
		lteRrcConnSetupCompleteStruct *pUlDcch = &lteUeControlBlock.lteueSpecificData[ueIndex].ulDcchRrcSetupCmpltData;
		memset((lteRrcUeSpecificData *)&lteUeControlBlock.lteueSpecificData[ueIndex], 0, sizeof(lteRrcUeSpecificData));
		lteUeControlBlock.lteueSpecificData[ueIndex].crnti = pRlcMsgData->crnti;
		lteUeControlBlock.lteueSpecificData[ueIndex].timingAdvance = pRlcMsgData->PF;//copying TA value
		lteUeControlBlock.lteueSpecificData[ueIndex].ulRssiPerPrb = ((pRlcMsgData->PO) & 0x00FF);//copying ulRssiPerPrb
		lteUeControlBlock.lteueSpecificData[ueIndex].snr = (pRlcMsgData->snr); //copying RSSI
		lteUeControlBlock.lteueSpecificData[ueIndex].emeCallAttemptedInd = (uint8)(pRlcMsgData->emeCallInd); //copying Emeregency Indication
		if(decodeDcchData(bufPtr ,encodingLength,(void*)pUlDcch) == 0)
		{
			//logPrint(LOG_DEBUG , "MMEC = %d , MMEGI = %d , PlmnId = %d\n",pUlDcch->mmec , pUlDcch->mmegi , pUlDcch->plmnid);
			//Decode GUTI/IMSI n store in ueCtxt global
			if ( (pUlDcch->pNasMsg[0] & 0xF0 ) >> 4 == 0x0)// to check security header type
			{
				nasIndex = 0; // if Plain NAS Message
			}
			else
			{
				nasIndex = 6; // if integrity protected and security protected
			}

			if( (pUlDcch->pNasMsg[nasIndex+1] & 0xFF) == 0x41 )
			{
				lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType = NAS_EMM_ATTACH_REQUEST;
				decodeMobileIdentity(ueIndex , &pUlDcch->pNasMsg[nasIndex]);
                decodeLastTacAndCM(ueIndex , &pUlDcch->pNasMsg[nasIndex]);
			}
			else if ((pUlDcch->pNasMsg[nasIndex+1] & 0xFF) == 0x48)
			{
				lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType = NAS_TRACKING_AREA_UPDATE_REQ;
				decodeMobileIdentity(ueIndex , &pUlDcch->pNasMsg[nasIndex]);
                decodeLastTacAndCM(ueIndex , &pUlDcch->pNasMsg[nasIndex]);
			}
			else if ((pUlDcch->pNasMsg[nasIndex+1] & 0xFF) == 0x45)
			{							        
				lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType = NAS_EMM_DETACH_REQUEST;
				if(pUlDcch->pNasMsg[nasIndex+2] & (0x08)) // to check 4 bit 
            	{
                 	logPrint(LOG_DEBUG,"IDLE MODE: UE Switch OFF ( UE initiated detach)\n");
            	}
				else
				{
					logPrint(LOG_DEBUG,"IDLE MODE: Normal Detach Triggered by UE\n");
				}

                if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
			    	sendBLUePowerOffInd(ueIndex);
			}
			else
			{
				logPrint(LOG_DEBUG,"Unknown Message received from UE Nas-Msg-Type = %02x\n", 
					     (pUlDcch->pNasMsg[nasIndex+1] & 0xFF));
				lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType = LTE_NAS_INVALID_MSG_TYPE;
				lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDT_IMSI;
			}

		}
		else
		{
                     logPrint(LOG_DEBUG,"UL DCCH Decode Failed for CRNTI = %d\n", pRlcMsgData->crnti);
                     lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType = LTE_NAS_INVALID_MSG_TYPE;
                     lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDT_IMSI;
		}
	}
	else if((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDENTITY_RESP_LTE) ||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_UECAPA_INFO_IN_SC) ||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState ==UE_WAIT_FOR_RRC_CONN_RECONFIG_CMPLT) ||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDENTITY_RESP_LTE_SC) ||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState ==UE_WAIT_FOR_RRC_CONN_MEAS_REPORT))
	{
		lteUeControlBlock.lteueSpecificData[ueIndex].snr = (pRlcMsgData->snr); //copying SNR
		lteUeControlBlock.lteueSpecificData[ueIndex].emeCallAttemptedInd = (pRlcMsgData->emeCallInd); //copying Emeregency Indication
		lteRrcUlDCCHData *pUlInfoTransMsg = &lteUeControlBlock.lteueSpecificData[ueIndex].ulDcchUlInfoTransData;
		lteblackListedUserInfo* blackUserInfo = blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi , FALSE);

		if(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_RECONFIG_CMPLT)
		{
			//if(((bufPtr[0] & 0xF8) == 0x10) && (encodingLength < 10))
			{
				lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_REPORT;
				//logPrint(LOG_DEBUG,"Keep Alive Timer for RRC Connection Started\n");
				if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
				{
				     timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
				}
				
				timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
						   LTE_SC_KEEP_RRC_CONNECTION_TIMER,
						   0,
						   handleRrcConnKeepAliveTimer,
						   &lteUeControlBlock.lteueSpecificData[ueIndex]);
			}
			return;

		}
		if(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_MEAS_REPORT)
		{

			if((encodingLength > 20)||((bufPtr[0] & 0xF8) != 0x08))
			{
				//logPrint(LOG_DEBUG,"Wrong meas report \n" );
				return;
			}
		}

		if((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_UECAPA_INFO_IN_SC) || 
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDENTITY_RESP_LTE_SC))
		{
			//buildAndEncodeRrcMeasConfigReqMsg(ueIndex);
			
			lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_REPORT;

			if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
			{
			      timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
			}
			
			timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
					   LTE_SC_KEEP_RRC_CONNECTION_TIMER,
					   0,
					   handleRrcConnKeepAliveTimer,
					   &lteUeControlBlock.lteueSpecificData[ueIndex]);
			return;
		}
		//Call IDT RSP ASN decode function
		if(decodeUlDcchUlInfoTrans(bufPtr,encodingLength, (void*)pUlInfoTransMsg) == 0)
		{
			if(pUlInfoTransMsg->ulMsgType == UL_IDENTITY_RESPONSE_MSG)
			{
				if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
					timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
				//logPrint(LOG_DEBUG,"Received IDENTITY RESPONSE from UE(%d)\n",lteUeControlBlock.lteueSpecificData[ueIndex].crnti );
				if ((pUlInfoTransMsg->pNasMsg[0] & 0xF0 ) >> 4 == 0x0)// to check security header type
				{
				  nasIndex = 0; // if Plain NAS Message
				}
				else
				{
				  nasIndex = 6; // if integrity protected and security protected
				}
				

				if(pUlInfoTransMsg->pNasMsg[nasIndex+1]== 0x45) // check if dettach is triggered from UE 
				{			        
					lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType = NAS_EMM_DETACH_REQUEST; /* Poweroff Indication changes */;

					if(pUlInfoTransMsg->pNasMsg[nasIndex+2] & (0x08)) // to check 4 bit 
                	{
                     	logPrint(LOG_DEBUG,"CONN MODE: UE Switch OFF ( UE initiated detach)  \n");
                	}
					else
					{
						logPrint(LOG_DEBUG,"CONN MODE: Normal Detach Triggered by UE \n");
					}

                     if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
				       	 sendBLUePowerOffInd(ueIndex);
				}

				if(decodeMobileIdentity(ueIndex , &pUlInfoTransMsg->pNasMsg[nasIndex])== 0)
				{
					logPrint(LOG_DEBUG,"decodeMobileIdentity EPS ID could not able to decode \n" );
				}
			}
			else if (pUlInfoTransMsg->ulMsgType == UL_SECURITY_MODE_FAILURE)
			{
			    if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
					timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
				logPrint(LOG_DEBUG,"Received Security Mode Failure from UE(%d)\n",lteUeControlBlock.lteueSpecificData[ueIndex].crnti );
				processUlMsgForImeiReq(ueIndex , pUlInfoTransMsg);
			}
			else if((pUlInfoTransMsg->ulMsgType == UL_UECAPA_INFO)||(pUlInfoTransMsg->ulMsgType == UL_PROXIMITY_IND))
			{
				if(pUlInfoTransMsg->ulMsgType == UL_PROXIMITY_IND)
					logPrint(LOG_DEBUG,"Proximity INdication Received from UE(%d)\n",lteUeControlBlock.lteueSpecificData[ueIndex].crnti );
				else
					logPrint(LOG_DEBUG,"UE capability Information Received from UE(%d)\n",lteUeControlBlock.lteueSpecificData[ueIndex].crnti );
			}
			else if (pUlInfoTransMsg->ulMsgType == UL_RECONF_CMPLT)
			{
				logPrint(LOG_DEBUG,"RRc Reconfig CMplt Received from UE(%d)\n",lteUeControlBlock.lteueSpecificData[ueIndex].crnti );
				lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_REPORT;

				if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
				{
					timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
				}
				
				timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
						   LTE_SC_KEEP_RRC_CONNECTION_TIMER,
				           0,
						   handleRrcConnKeepAliveTimer,
				           &lteUeControlBlock.lteueSpecificData[ueIndex]);
			}
			else if (pUlInfoTransMsg->ulMsgType == UL_MEAS_REPORT)
			{
				if(blackUserInfo != NULL)
			     {
                  if(blackUserInfo->measurementType == FXL_4G_OWN_CELL_MEASUREMENT)
                  {
					if(blackUserInfo->rsrp != ((sint32)(pUlInfoTransMsg->rsrp - 140)))//print only when it changes
					{
						logPrint(LOG_DEBUG,"RRC Meas Report Received RSRP = %lld  , RSRQ = %lld  from UE(%d)\n",pUlInfoTransMsg->rsrp, pUlInfoTransMsg->rsrq, lteUeControlBlock.lteueSpecificData[ueIndex].crnti );
					}
					blackUserInfo->rsrp = (sint32)(pUlInfoTransMsg->rsrp) - 140;
					if(pUlInfoTransMsg->rsrq < 35)
					blackUserInfo->rsrq = rsrqIndB[(int)(pUlInfoTransMsg->rsrq)];
                  }
                  else
                  {
                     if(lteUeControlBlock.lteueSpecificData[ueIndex].ulDcchUlInfoTransData.measReportEmpty == 0)
                     {
				         logPrint(LOG_DEBUG,"decodeUlDcchUlInfoTrans Send Neighbor Meas Report \n");
                         /* Send Neighbor Meas Report */
                         sendNeighCellMeasReportIndToClient(ueIndex);
                     }
                     else
                     {
                         logPrint(LOG_DEBUG,"decodeUlDcchUlInfoTrans Received Empty Neighbor Meas Report \n");
                     }
                  }
				}
			}
			else
			{
				logPrint(LOG_DEBUG,"decodeUlDcchUlInfoTrans ASN Unhandled  Msg-Type = %d \n" , pUlInfoTransMsg->ulMsgType );
			}
		}
		else
		{
			//logPrint(LOG_DEBUG," Failed to decode asn bufPtr[0]:%02x,bufPtr[1]:%02x,bufPtr[2]:%02x,bufPtr[3]:%02x,bufPtr[4]:%02x,bufPtr[5]:%02x\n",bufPtr[0],bufPtr[1],bufPtr[2],bufPtr[3],bufPtr[4],bufPtr[5]);
			//logPrint(LOG_DEBUG,"bufPtr[6]:%02x,bufPtr[7]:%02x,bufPtr[8]:%02x,bufPtr[9]:%02x,bufPtr[10]:%02x,bufPtr[11]:%02x\n",bufPtr[6],bufPtr[7],bufPtr[8],bufPtr[9],bufPtr[10],bufPtr[11]);
			//logPrint(LOG_DEBUG,"bufPtr[12]:%02x,bufPtr[13]:%02x,bufPtr[14]:%02x,bufPtr[15]:%02x,bufPtr[16]:%02x,bufPtr[17]:%02x\n",bufPtr[12],bufPtr[13],bufPtr[14],bufPtr[15],bufPtr[16],bufPtr[17]);
		}

	}

}

/*
 * ############################################################################
 * Method Name : sendNeighCellMeasReportIndToClient
 * 
 * Description : This function send Measurement Report to TCP Client
 * 
 * Parameters   : ueIndex
 * 
 * Returns      : None
 * ############################################################################
 */

void sendNeighCellMeasReportIndToClient(unsigned int ueIndex)
{
     fxL4gUeMeasurementReportInd ind ;
     ind.hdr.msgType = FXL_4G_UE_MEASUREMENT_REPORT_IND;
     ind.hdr.rat = FXL_RAT_4G;
     ind.hdr.msgLength = sizeof(fxL4gUeMeasurementReportInd);

     memcpy(ind.imsiStr, lteUeControlBlock.lteueSpecificData[ueIndex].imsi, SIZE_OF_IDENTITY_STR);
     ind.measType = lteUeControlBlock.lteueSpecificData[ueIndex].ulDcchUlInfoTransData.neighMeasType;    
     memcpy(&ind.u, &lteUeControlBlock.lteueSpecificData[ueIndex].ulDcchUlInfoTransData.measResult, sizeof(asnMeasResult));

     writeToExternalSocketInterface((uint8*)&ind , sizeof(fxL4gUeMeasurementReportInd));
}

/*
 *############################################################################
 * Method Name : lteDlDcchHandler
 *
 * Description : This procedure Handles the Downlink DCCH messages
 *
 * Parameters	: lteL2IntfData_t
 *
 * Returns 	: None
 *############################################################################
 */
void lteDlDcchHandler (lteL2IntfData_t *pRlcMsgData)
{
    if(TRUE == exitLteApp)
    {
            return;
    }

	unsigned int ueIndex = pRlcMsgData->crnti - LTE_C_RNTI_START;
	logPrint(LOG_DEBUG,"lteDlDcchHandler ueIndex = %d, RrcUeState = %d \n", ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].ueState);

	if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDT_IMSI)
	{
		buildAndEncodeIdentityMsg(ueIndex);

		if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
		{
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		}
		
		timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
					TIMER_FOR_4G_IDENTITY_REQUEST_TIMEOUT,
		           0,
		           handleIdentityReqTimeout,
		           &lteUeControlBlock.lteueSpecificData[ueIndex]);
	}
	else if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDT_IMEI)
	{
		buildAndEncodeIdentityMsg(ueIndex);
		
		if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
		{
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		}

		timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
					TIMER_FOR_4G_IDENTITY_REQUEST_TIMEOUT,
		           0,
		           handleIdentityReqTimeout,
		           &lteUeControlBlock.lteueSpecificData[ueIndex]);
	}
	else if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_ATTACH_REJECT)
	{
		buildAndEncodeAttachRejMsg(ueIndex);

		if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
		{
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		}

		timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
					ATTACH_REJECT_TIMEOUT,
		           0,
		           handleAttachRejTimeout,
		           &lteUeControlBlock.lteueSpecificData[ueIndex]);
	}
	else if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_TAU_REJECT)
	{
		buildAndEncodeTAURejMsg(ueIndex);

		if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
		{
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		}

		timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
					TAU_REJECT_TIMEOUT,
		           0,
		           handleTAURejTimeout,
		           &lteUeControlBlock.lteueSpecificData[ueIndex]);
	}
	else if ((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CON_REL) ||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CON_REL_REDIRECT)||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_WL_REDIRECT))
	{
	    if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		buildAndEncodeRrcReleaseMsg(ueIndex);
	}
	else if ((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_UECAPA_ENQUIRY)||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_REQ_CMPLT_RSP))
	{
		buildAndEncodeRrcUeCapaEnqMsg(ueIndex);
	}
	else if ((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG) /*||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_REQ_CMPLT_RSP)*/)
	{
	    if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		buildAndEncodeRrcMeasConfigReqMsg(ueIndex);
	}
        else if (/*(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CON_SETUP_COMPLETE_LTE)||*/
                 (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_RELEASED))
        {
              if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
              {
                   timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
              }

              //memset(&lteUeControlBlock.lteueSpecificData[ueIndex], 0, sizeof(lteRrcUeSpecificData));
			  /*
              lteL2InftMsg_t *pRrcMsg;
              pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
              if (NULL != pRrcMsg)
              {
                   pRrcMsg->msgType = LTE_MSG_DELETE_MAC_RLC_USER_CNTXT_E;
                   pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
                   ltePutMsgInRlcQ((void*)pRrcMsg);
              }*/   
        }
	else
	{

	}

}

/*
 *############################################################################
 * Method Name : buildAndEncodeIdentityMsg
 *
 * Description : This procedure Handles Encode of IDT message
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */
void buildAndEncodeIdentityMsg(int ueIndex)
{
	if(TRUE == exitLteApp)
    {
            return;
    }

	lteL2InftMsg_t *pRrcMsg;
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	pRrcMsg->msgType = LTE_MSG_IDENTITY_REQ_DL_DCH_SDU_REQ_E;
	pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;

	if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDT_IMSI)
	{
		if (lteUeControlBlock.lteueSpecificData[ueIndex].ueLteIMSIReqCount<5)
		{
			assert(asn1EncodedIdentityImsiRequest != NULL);
			pRrcMsg->l2Data.size = asn1EncodedIdentityImsiRequestLen+5;//1Byte Pdcp Header + 4Byte of MAC
			pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header
			memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedIdentityImsiRequest , asn1EncodedIdentityImsiRequestLen);
			logPrint(LOG_DEBUG, "buildAndEncodeIdentityIMSI Msg IdReqLEn = %d \n", asn1EncodedIdentityImsiRequestLen);
			lteUeControlBlock.lteueSpecificData[ueIndex].ueLteIMSIReqCount++;
			lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDENTITY_RESP_LTE;

			ltePutMsgInRlcQ((void*)pRrcMsg);
		}
	}
	else if ((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_MEAS_REPORT) ||
			(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_RECONFIG_CMPLT))
	{
			assert(asn1EncodedIdentityImsiRequest != NULL);
			pRrcMsg->l2Data.size = asn1EncodedIdentityImsiRequestLen+5;//1Byte Pdcp Header + 4Byte of MAC
			pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header
			memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedIdentityImsiRequest , asn1EncodedIdentityImsiRequestLen);
			logPrint(LOG_DEBUG, "buildAndEncodeIdentityIMSI in Silent Call for Keeping RRC Connection \n");
			lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDENTITY_RESP_LTE_SC;

			ltePutMsgInRlcQ((void*)pRrcMsg);

	}
	else if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDT_IMEI)
	{
		if (lteUeControlBlock.lteueSpecificData[ueIndex].ueLteIMEIReqCount<5)
		{
			assert(asn1EncodedIdentityImeiRequest != NULL);
			pRrcMsg->l2Data.size = asn1EncodedIdentityImeiRequestLen+5;//1Byte Pdcp Header + 4Byte of MAC
			pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header
			memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedIdentityImeiRequest , asn1EncodedIdentityImeiRequestLen);
			logPrint(LOG_DEBUG, "buildAndEncodeIdentityIMEI Msg IdReqLEn = %d \n", asn1EncodedIdentityImeiRequestLen);
			lteUeControlBlock.lteueSpecificData[ueIndex].ueLteIMEIReqCount++;
			lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDENTITY_RESP_LTE;

			ltePutMsgInRlcQ((void*)pRrcMsg);
		}

	}

	if ((lteUeControlBlock.lteueSpecificData[ueIndex].ueLteIMSIReqCount == 5 )|| (lteUeControlBlock.lteueSpecificData[ueIndex].ueLteIMEIReqCount ==5))
	{
		if ((lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == FALSE)&&((lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDT_IMSI) ||
		    (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDT_IMEI)))
		{
			buildAndEncodeAttachRejMsg(ueIndex);
		}
	}

	return;
}

/*
 *############################################################################
 * Method Name : buildAndEncodeAttachRejMsg
 *
 * Description : This procedure Handles the Encode of Attach Rej Message
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */
uint8 attachRej[34] = {0x10,0x18,0x28,0x30,0x38,0x40,0x48,0x50,0x58,0x60,0x68,0x70,0x78,0x80,0x88,0x90,0x98,0xa0,0xa8,0xb0,0xb8,0xc0,0xc8,0xd0,0x38,0x40,0xf8,0x00,0x08,0x10,0x18,0x20,0x28,0x78};
void buildAndEncodeAttachRejMsg(int ueIndex)
{
	if(TRUE == exitLteApp)
    {
            return;
    }

	lteL2InftMsg_t *pRrcMsg;
	assert(asn1EncodedAttachRejRequest != NULL);
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL;
	pRrcMsg->msgType = LTE_MSG_ATTACH_REJ_DL_DCH_SDU_REQ_E;
	pRrcMsg->l2Data.size = asn1EncodedAttachRejRequestLen+5;//1Byte Pdcp Header + 4Byte of MAC
	pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
	pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header
	memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedAttachRejRequest , asn1EncodedAttachRejRequestLen);

	if (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == FALSE)
	{
		 uint8 index5 , index4, input ;
		 if(lteUeControlBlock.lteueSpecificData[ueIndex].wlAttRejCause) // UE ID base Wl Reject Cause High Priority
		 	input = lteUeControlBlock.lteueSpecificData[ueIndex].wlAttRejCause;
		 else if (enableAttRejCause) // update Global Wl Rject Cause
		 	input = lteWlRejCause;
		 else
			 input = 0;
		 index4 = 0;
		 index5 = 0;
		//logPrint(LOG_DEBUG ,"WL Attach Reject cause = %d\n", input );
		if ((input == 2 ) || (input == 3))
		{
				index5 = input -2;
		}
		else if ((input >= 5)&& (input <=26))
		{
				index5 = input -1- 2;
		}
		else if ((input >=95) &&(input<= 101))
		{
			   index5 = input - 67 - 2;
			   if (input ==95)
				  index4 = index4+2;
			   else
				  index4 = index4+3;
		}
		else if ((input == 39) || (input == 40))
		{
				index5 = input - 13 - 2;
				index4 = index4+1;
		}
		else
		{
				index5 = 33;
				index4 = index4+3;
		}
		if (input)
		{
			pRrcMsg->l2Data.dataBuf[asn1EncodedAttachRejRequestLen] = attachRej[index5];
			pRrcMsg->l2Data.dataBuf[asn1EncodedAttachRejRequestLen-1] = asn1EncodedAttachRejRequest[4] + index4;
		}
		else
		{
			char tmp[MAX_IDENTITY_LENGTH_STR_4G] = {0};
            if(idCatcherLteWlRedirEarfcn)
            {
		        lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_WL_REDIRECT;
            }
			if(memcmp(tmp , lteUeControlBlock.lteueSpecificData[ueIndex].imsi , MAX_IDENTITY_LENGTH_STR_4G) == 0)
			{
				pRrcMsg->l2Data.dataBuf[asn1EncodedAttachRejRequestLen] = 0x48;
			}
		}
	}
	else if((lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)&& (!lteRrcRedirectFlag))
    {
    	lteblackListedUserInfo* blackUserInfo = blacklistLteUserFindUsingIdentity((tOCT_UINT8*)(lteUeControlBlock.lteueSpecificData[ueIndex].imsi) , FALSE);
        pRrcMsg->l2Data.dataBuf[asn1EncodedAttachRejRequestLen] = 0x10; // IMSI unknown in HSS (2)
        pRrcMsg->l2Data.dataBuf[asn1EncodedAttachRejRequestLen-1] = 0x20;
      

    	if((blackUserInfo != NULL)&&(blackUserInfo->lteSilentCallStarted == TRUE))
    	{
    		//Ask for measurement report only if silent call is enabled. Otherwise don't ask
     	    lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG;
    	}
    	else
    	{
    		lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL;
    	}

    }
    else if ((lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)&& (lteRrcPrmRedirectFlag))
    {
                lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                logPrint(LOG_DEBUG, "Preparing permnt redirect\n");
    }
    else {}


    logPrint(LOG_DEBUG, "buildAndEncodeAttachRejMsg AttRejLen = %d , cause PDU = 0x%02x \n", asn1EncodedAttachRejRequestLen,pRrcMsg->l2Data.dataBuf[asn1EncodedAttachRejRequestLen]);

    //logPrint(LOG_DEBUG , "%02x, %02x,%02x, %02x,%02x , %02x \n" , pRrcMsg->l2Data.dataBuf[1],pRrcMsg->l2Data.dataBuf[2],pRrcMsg->l2Data.dataBuf[3],pRrcMsg->l2Data.dataBuf[4],pRrcMsg->l2Data.dataBuf[5],pRrcMsg->l2Data.dataBuf[6] );
	ltePutMsgInRlcQ((void*)pRrcMsg);

	return;
}



/*
 *############################################################################
 * Method Name : buildAndEncodeTAURejMsg
 *
 * Description : This procedure Handles the Encode of TAU Rej Message
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */
void buildAndEncodeTAURejMsg(int ueIndex)
{
	if(TRUE == exitLteApp)
    {
        return;
    }

	lteL2InftMsg_t *pRrcMsg;
	assert(asn1EncodedTAURejRequest != NULL);
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL;
	pRrcMsg->msgType = LTE_MSG_TAU_REJ_DL_DCH_SDU_REQ_E;
	pRrcMsg->l2Data.size = asn1EncodedTAURejRequestLen+5;//1Byte Pdcp Header + 4Byte of MAC
	pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
	pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header
	memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedTAURejRequest , asn1EncodedTAURejRequestLen);

	if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
	{
		pRrcMsg->l2Data.dataBuf[asn1EncodedTAURejRequestLen] = 0x48; //UE identity cannot be derived by the network (9)

	}

	logPrint(LOG_DEBUG, "buildAndEncodeTAURejMsg TauRejLen = %d  ueState = %d \n", asn1EncodedTAURejRequestLen ,lteUeControlBlock.lteueSpecificData[ueIndex].ueState);

	ltePutMsgInRlcQ((void*)pRrcMsg);

	return;

}


/*
 *############################################################################
 * Method Name : buildAndEncodeRrcReleaseMsg
 *
 * Description : This procedure Handles ENcode of RRC connection Release Msg
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */
void buildAndEncodeRrcReleaseMsg(int ueIndex)
{
	if(TRUE == exitLteApp)
    {
            return;
    }

	lteL2InftMsg_t *pRrcMsg;
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
	pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header
	if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CON_REL)
	{
		assert(asn1EncodedRrcConnectionRelease != NULL);
		pRrcMsg->msgType = LTE_MSG_RRC_CONN_REL_DL_DCH_SDU_REQ_E;
		pRrcMsg->l2Data.size = asn1EncodedRrcConnectionReleaseLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
		memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedRrcConnectionRelease , asn1EncodedRrcConnectionReleaseLen);
		//logPrint(LOG_DEBUG, "buildAndEncodeRrcReleaseMsg RrcConnRel = %d \n", asn1EncodedRrcConnectionReleaseLen);
		ltePutMsgInRlcQ((void*)pRrcMsg);
	}
	else if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CON_REL_REDIRECT)
	{
		pRrcMsg->msgType = LTE_MSG_RRC_CONN_REDIRECT_DL_DCH_SDU_REQ_E;

        if (lteRrcRedirectFlag)
        {
                assert(asn1EncodedRrcConnectionReleaseWithRedirect != NULL);
                pRrcMsg->l2Data.size = asn1EncodedRrcConnectionReleaseWithRedirectLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
                memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedRrcConnectionReleaseWithRedirect , asn1EncodedRrcConnectionReleaseWithRedirectLen);
				logPrint(LOG_DEBUG, "buildAndEncodeRrcReleaseMsg RrcConnReRedirect MsgLen= %d \n", asn1EncodedRrcConnectionReleaseWithRedirectLen);
        }
        else
        {
                lteblackListedUserInfo* blackUserInfo =
                                      blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);
                if((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
                {
                    assert(blackUserInfo->pRrcConRelWithRedirect != NULL);
                    pRrcMsg->l2Data.size = blackUserInfo->rrcConRelWithRedirectLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
                    memcpy(&pRrcMsg->l2Data.dataBuf[1] ,
                               blackUserInfo->pRrcConRelWithRedirect,
                           blackUserInfo->rrcConRelWithRedirectLen);
                	logPrint(LOG_DEBUG, "buildAndEncodeRrcReleaseMsg Per UE Based RrcConnReRedirect= %d \n",
                                 blackUserInfo->rrcConRelWithRedirectLen);
                }
        }
                ltePutMsgInRlcQ((void*)pRrcMsg);
	}
	else if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CONN_WL_REDIRECT)
	{
    	generateRrcReleaseWLRedirect(idCatcherLteEarfcn);
		assert(asn1EncodedRrcRedirectWL != NULL);
		pRrcMsg->msgType = LTE_MSG_RRC_CONN_REDIRECT_DL_DCH_SDU_REQ_E;
		pRrcMsg->l2Data.size = asn1EncodedRrcRedirectWLLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
		memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedRrcRedirectWL , asn1EncodedRrcRedirectWLLen);
		//logPrint(LOG_DEBUG, "buildAndEncodeRrcReleaseMsg RrcWLRedirect= %d \n", asn1EncodedRrcRedirectWLLen);
		ltePutMsgInRlcQ((void*)pRrcMsg);
	}
	
	sendIndicationToClient(ueIndex);
	lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_RELEASED;

	return;
}

/*
 *############################################################################
 * Method Name : buildAndEncodeRrcPagingMsg
 *
 * Description : This procedure Handles the Encode of Paging Message
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */
void buildAndEncodeRrcPagingMsg(int ueIndex)
{
	if(TRUE == exitLteApp)
    {
         return;
    }

	//logPrint(LOG_DEBUG, "buildAndEncodeRrcPagingMsg lteRrcRedirectFlag = %d \n", lteRrcRedirectFlag);

	if(!lteRrcRedirectFlag)
	{
		lteblackListedUserInfo* blackUserInfo = blacklistLteUserFindUsingIdentity((uint8 *)lteUeControlBlock.lteueSpecificData[ueIndex].imsi , FALSE);
		if(blackUserInfo != NULL)
		{
			lteL2InftMsg_t *pRrcMsg;
			if(blackUserInfo->PF > 31)
			{
				assert(0);
			}
			pRrcMsg = (lteL2InftMsg_t *)getRrcPageBuffer(blackUserInfo->PF);
			lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_SETUP_COMPLETE_LTE;
			pRrcMsg->msgType = LTE_MSG_PAGING_START_REQ_E;
			pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;

			pRrcMsg->l2Data.PF = blackUserInfo->PF; // will add code to get info from blacklistuserinfo
			pRrcMsg->l2Data.PO = blackUserInfo->PO;
			uint8 *pageAsnMsg = NULL;
			lteDlPagingStruct *pageimsi = lteGetImsiForPaging(blackUserInfo);

            if(pageimsi == NULL)
				return;

			if(pageimsi->uePageCount == 0)
			{
				return;
			}
			pageimsi->cnDomain = 0 ;//PS domain
			pageimsi->imsiLength = MAX_IDENTITY_LENGTH_STR_4G;

			if(pageimsi->uePageCount > 2)
			{
			
				if(blackUserInfo->sTmsiValid == TRUE)
				{
					generatePagingMsgWithSTmsi(pageimsi);
					assert(asn1EncodedPagingwithSTmsiRequest != NULL);
					pRrcMsg->l2Data.size = asn1EncodedPagingwithSTmsiRequestLen;
					memcpy(&pRrcMsg->l2Data.dataBuf[0] , asn1EncodedPagingwithSTmsiRequest , asn1EncodedPagingwithSTmsiRequestLen);
				}
				else
				{
				generatePagingMsg(pageimsi);
				assert(asn1EncodedPagingRequest!= NULL);
				pRrcMsg->l2Data.size = asn1EncodedPagingRequestLen;
				memcpy(&pRrcMsg->l2Data.dataBuf[0] , asn1EncodedPagingRequest , asn1EncodedPagingRequestLen);
			}
			}
			else
			{
				if(blackUserInfo->sTmsiValid == TRUE)
				{
					pageAsnMsg = getSTmsiPagingAsnEncodedMsg(pageimsi);
					pRrcMsg->l2Data.size = pageimsi->imsiLength;
					memcpy(&pRrcMsg->l2Data.dataBuf[0] , pageAsnMsg , pRrcMsg->l2Data.size);
					
				}
				else
				{
					pageAsnMsg = getPagingAsnEncodedMsg(pageimsi);
       
       				if(pageAsnMsg == NULL)
		            	return;

					pRrcMsg->l2Data.size = pageimsi->imsiLength;
					memcpy(&pRrcMsg->l2Data.dataBuf[0] , pageAsnMsg , pRrcMsg->l2Data.size);
				}
			}

			ltePutMsgInRlcQ((void*)pRrcMsg);

			if(sibModTimerStarted == FALSE)
			{
				sendStartSibchangePagingTimerMsgToSelf();
				sibModTimerStarted = TRUE;
				logPrint(LOG_DEBUG, "SIB modification timer started  \n");
			}
		}

	}

	return;
}


/*
 *############################################################################
 * Method Name : buildAndEncodeRrcPagingSibModMsg
 *
 * Description : After BL Pagiing timer expiry we will call this page for SIBMOD
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */

void buildAndEncodeRrcPagingSibModMsg(void)
{
	if(TRUE == exitLteApp)
    {
         return;
    }

	uint8 newTAC = TRUE;
	lteblackListedUserInfo* tmp = NULL;
	if(!lteRrcRedirectFlag)
	{
		pthread_mutex_lock(&mutexLteBlackListQ);
		listNode *current = headForLteBlacklistedUserQ;

		while (current != NULL)
		{
		   tmp = (lteblackListedUserInfo*)(current->msg);
		   if(tmp != NULL)
		   {
			   if(tmp->blRemoveFlag == TRUE)
			   {
				   logPrint(LOG_DEBUG , "BL UE removed %p \n", tmp);
				   sendMsgToMacToRemovePagingReq(tmp);
				   sendSignalToSelfToDeleteBLUser(current);
			   }
			   else
			   {
				   buildAndSendSibChangePagingMsg(tmp , newTAC);
				   newTAC = FALSE;
			   }
		   }
		   current = current->next;
		}
		pthread_mutex_unlock(&mutexLteBlackListQ);
	}

	return;

}

//ASHU ASN.1 Issue
void buildAndEncodeRrcPagingSibModMsgRrcThrd(void)
{
	if(TRUE == exitLteApp)
    {
        return;
    }

	uint8 newTAC = TRUE;
	lteblackListedUserInfo* tmp = NULL;
	if(!lteRrcRedirectFlag)
	{
		pthread_mutex_lock(&mutexLteBlackListQ);
		listNode *current = headForLteBlacklistedUserQ;

		while (current != NULL)
		{
		   tmp = (lteblackListedUserInfo*)(current->msg);
		   if(tmp != NULL)
		   {
               if(tmp->blRemoveFlag == TRUE)
			   {
				   logPrint(LOG_DEBUG , "BL UE removed %p \n", tmp);
				   sendMsgToMacToRemovePagingReq(tmp);
				   sendSignalToSelfToDeleteBLUser(current);
			   }
			   else
			   {
				   buildAndSendSibChangePagingMsgRrcThrd(tmp , newTAC);
				   newTAC = FALSE;
			   }
		   }
		   current = current->next;
		}
		pthread_mutex_unlock(&mutexLteBlackListQ);
	}

	return;

}
//ASHU ASN.1 Issue

/*
 *############################################################################
 * Method Name : buildAndEncodeRrcUeCapaEnqMsg
 *
 * Description : This procedure Handles the Encode of UE Capapability Enquiry Message
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */
void buildAndEncodeRrcUeCapaEnqMsg(int ueIndex)
{
	if(TRUE == exitLteApp)
    {
       return;
    }

	lteL2InftMsg_t *pRrcMsg;
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	logPrint(LOG_DEBUG, "buildAndEncodeRrcUeCapaEnqMsg UE State = %d \n", lteUeControlBlock.lteueSpecificData[ueIndex].ueState);
	lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_UECAPA_INFO_IN_SC;
	pRrcMsg->msgType = LTE_MSG_RRC_UECAPA_ENQ_REQ_E;
	pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
	pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header

	assert(asn1EncodedRrcUeCapaEnqReq!= NULL);

	pRrcMsg->l2Data.size = asn1EncodedRrcUeCapaEnqReqLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
	memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedRrcUeCapaEnqReq , asn1EncodedRrcUeCapaEnqReqLen);


	ltePutMsgInRlcQ((void*)pRrcMsg);

}


/*
 *############################################################################
 * Method Name : buildAndEncodeRrcMeasConfigReqMsg
 *
 * Description : This procedure Handles the Encode of UE Capapability Enquiry Message
 *
 * Parameters	: Takes ueIndex as input
 *
 * Returns 	: None
 *############################################################################
 */
void buildAndEncodeRrcMeasConfigReqMsg(int ueIndex)
{
	if(TRUE == exitLteApp)
    {
       return;
    }        

	lteblackListedUserInfo* blackUserInfo = blacklistLteUserFindUsingIdentity((tOCT_UINT8*)(lteUeControlBlock.lteueSpecificData[ueIndex].imsi) , FALSE);
    if(blackUserInfo == NULL)
    {
        lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL;
        return; 
    }

	lteL2InftMsg_t *pRrcMsg;
	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	logPrint(LOG_DEBUG, "buildAndEncodeRrcMeasConfigReqMsg in UE State = %d \n", lteUeControlBlock.lteueSpecificData[ueIndex].ueState);
	lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_RECONFIG_CMPLT ;
//	pRrcMsg->msgType = LTE_MSG_RRC_MEAS_REQ_E;
	pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
	pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header

    if(blackUserInfo->measurementType == FXL_4G_NEIGHBOR_CELL_MEASUREMENT)
    {
        lteUeControlBlock.lteueSpecificData[ueIndex].ulDcchUlInfoTransData.measurementType = ASN_4G_NEIGHBOR_CELL_MEASUREMENT;
        pRrcMsg->msgType = LTE_MSG_RRC_NEIGH_MEAS_REQ_E;
	    assert(asn1EncodedRrcNeighMeasCntrlReq != NULL);
	    pRrcMsg->l2Data.size = asn1EncodedRrcNeighMeasCntrlReqLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
   	    memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedRrcNeighMeasCntrlReq , asn1EncodedRrcNeighMeasCntrlReqLen);
    }
    else
    {
        lteUeControlBlock.lteueSpecificData[ueIndex].ulDcchUlInfoTransData.measurementType = ASN_4G_OWN_CELL_MEASUREMENT;
        pRrcMsg->msgType = LTE_MSG_RRC_MEAS_REQ_E;
        assert(asn1EncodedRrcMeasCntrlReq != NULL);
        pRrcMsg->l2Data.size = asn1EncodedRrcMeasCntrlReqLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
        memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedRrcMeasCntrlReq , asn1EncodedRrcMeasCntrlReqLen);
    }

	ltePutMsgInRlcQ((void*)pRrcMsg);

}

/*
 *############################################################################
 * Method Name : decodeGUTI
 *
 * Description :  Decodes Mobile Identity GUTI from DedicatedNAS info
 *
 * Parameters	: DedicatedNAsInfo
 *
 * Returns 	: None
 *############################################################################
 */
void decodeGUTI(uint8* bcd , lteRrcGuti_t* guti)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	if ((bcd[1] & 0x07) == GUTI_ID)
	{
		//logPrint(LOG_DEBUG,"Decode GUTI \n with length %d", ((bcd[0]) & (0x0F)));
		guti->mcc[0] = bcd[2] & 0x0F;
		guti->mcc[1] = (bcd[2] & 0xF0) >> 4;
		guti->mcc[2] = bcd[3] & 0x0F;

		guti->mnc[2] = (bcd[3] & 0xF0) >>4 ;
		guti->mnc[0] = bcd[4] & 0x0F;
		guti->mnc[1] = (bcd[4] & 0xF0) >> 4;

		guti->mmegrpID = (bcd[6]) |(bcd[5] <<8);

		guti->mmecode = bcd[7];

		guti->mtmsi = ( (bcd[11]) | (bcd[10] << 8) | (bcd[9] << 16) | bcd[8] << 24);

		guti->isGutiValid = TRUE;
		//logPrint(LOG_DEBUG,"mcc[1]:%d,mcc[2]:%d,mnc[3]:%d\n", guti->mcc[0], guti->mcc[1], guti->mcc[2]);
		//logPrint(LOG_DEBUG,"mnc[1]:%d,mnc[2]:%d,mnc[3]:%d\n", guti->mnc[0], guti->mnc[1], guti->mnc[2]);
		logPrint(LOG_DEBUG,"mmegrpID:%d,mmecode:%d,mtmsi:%8x\n", guti->mmegrpID, guti->mmecode, guti->mtmsi);

	}

}

/*
 * ############################################################################
 * Method Name : decodeLastTacAndCM
 * 
 * Description :  Decodes Last TAC from DedicatedNAS info
 * 
 * Parameters   : Takes ueIndex as input , unsigned char of DedicatedNAsInfo
 * 
 * Returns      : None
 * ############################################################################
 */
void decodeLastTacAndCM(int ueIndex , unsigned char *pNasMsg)
{
    if(TRUE == exitLteApp)
    {
         return;
    }

    if(lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_EMM_ATTACH_REQUEST)
    {
       unsigned int len = 0, len1 = 0, len2 = 0, len3 =0, i = 0;
       len = pNasMsg[3];
       len1 = pNasMsg[3 + 1 + len];
       len2 = pNasMsg[3 + 1 + len + 2 + len1];
       /*P-TMSI signature*/
       if(pNasMsg[7 + len + len1 + len2] == 0x19)
       {
          len3 = 4;
       }
       /*EPS mobile identity*/
       if(pNasMsg[7 + len + len1 + len2 + len3] == 0x50)
       {
          len3 += 13;
       }
       /*Tracking area identity*/
       if(pNasMsg[7 + len + len1 + len2 + len3] == 0x52)
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastTac = (pNasMsg[7 + len + len1 + len2 + len3 + 4] << 8) | (pNasMsg[7 + len + len1 + len2 + len3 + 5]);
          len3 += 6;
       }
       else
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastTac = -1;
       }
       /*DRX parameter*/
       if(pNasMsg[7 + len + len1 + len2 + len3] == 0x5C)
       {
          len3 += 3;
       }
       /*MS network capability*/
       if(pNasMsg[7 + len + len1 + len2 + len3] == 0x31)
       {
          unsigned int msNetworkCapLen = 0;
          msNetworkCapLen = pNasMsg[8 + len + len1 + len2 + len3];
          len3 += msNetworkCapLen;
          len3 += 2;
       }
       /*Location area identification*/
       if(pNasMsg[7 + len + len1 + len2 + len3] == 0x13)
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastLac = (pNasMsg[7 + len + len1 + len2 + len3 + 4] << 8) | (pNasMsg[7 + len + len1 + len2 + len3 + 5]);;
          len3 += 6;
       }
       else
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastLac = -1;
       }
       /*TMSI status*/
       if((pNasMsg[7 + len + len1 + len2 + len3] & 0xF0) == 0x90)
       {
          len3 += 1;
       }
       /*Mobile station classmark 2*/
       if(pNasMsg[7 + len + len1 + len2 + len3] == 0x11)
       {
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[0] = pNasMsg[8 + len + len1 + len2 + len3];
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[1] = pNasMsg[9 + len + len1 + len2 + len3];
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[2] = pNasMsg[10 + len + len1 + len2 + len3];
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[3] = pNasMsg[11 + len + len1 + len2 + len3];
           len3 += 5;
       }
       /*Mobile station classmark 3*/
       if(pNasMsg[7 + len + len1 + len2 + len3] == 0x20)
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lengthOfCM3 = pNasMsg[8 + len + len1 + len2 + len3];
          len3 += 2;
          for(i = 0; i<lteUeControlBlock.lteueSpecificData[ueIndex].lengthOfCM3; i++)
          {
              lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM3[i] = pNasMsg[7 + len + len1 + len2 + len3];
              len3 += 1;
          }
       }
    }
    else if(lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
    {
       unsigned int len = 0, i = 0;
       /*NAS key set identifier */
       if((pNasMsg[15] & 0xF0) == 0xB0)
       {
          len += 1;
       }
       /*Ciphering key sequence numbe */
       if((pNasMsg[15 + len] & 0xF0) == 0x80)
       {
          len += 1;
       }
       /*P-TMSI signature*/
       if(pNasMsg[15 + len] == 0x19)
       {
          len += 4;
       }
       /*EPS mobile identity*/
       if(pNasMsg[15 + len] == 0x50)
       {
          len += 13;
       }
       /*Nonce*/
       if(pNasMsg[15 + len] == 0x55)
       {
          len += 5;
       }
       /*UE network capability*/
       if(pNasMsg[15 + len] == 0x58)
       {
          unsigned int ueNetworkCapLen = 0;
          ueNetworkCapLen = pNasMsg[16 + len];
          len += ueNetworkCapLen;
          len += 2;
       }
       /*Tracking area identity*/
       if(pNasMsg[15 + len] == 0x52)
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastTac = (pNasMsg[15 + len + 4] << 8) | (pNasMsg[15 + len + 5]);
          len += 6;
       }
       else
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastTac = -1;
       }
       /*DRX parameter*/
       if(pNasMsg[15 + len] == 0x5C)
       {
          len += 3;
       }
       /*UE radio capability information update needed*/
       if((pNasMsg[15 + len] & 0xF0) == 0xA0)
       {
          len += 1;
       }
       /*EPS bearer context status*/
       if(pNasMsg[15 + len] == 0x57)
       {
          len += 4;
       }
       /*MS network capability*/
       if(pNasMsg[15 + len] == 0x31)
       {
          unsigned int msNetworkCapLen = 0;
          msNetworkCapLen = pNasMsg[16 + len];
          len += msNetworkCapLen;
          len += 2;
       }
       /*Location area identification*/
       if(pNasMsg[15 + len] == 0x13)
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastLac = (pNasMsg[15 + len + 4] << 8) | (pNasMsg[15 + len + 5]);
          len += 6;
       }
       else
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lastLac = -1;
       }
       /*TMSI status*/
       if((pNasMsg[15 + len] & 0xF0) == 0x90)
       {
          len += 1;
       }
       /*Mobile station classmark 2*/
       if(pNasMsg[15 + len] == 0x11)
       {
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[0] = pNasMsg[16 + len];
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[1] = pNasMsg[17 + len];
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[2] = pNasMsg[18 + len];
           lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM2[3] = pNasMsg[19 + len];
           len += 5;
       }
       /*Mobile station classmark 3*/
       if(pNasMsg[15 + len] == 0x20)
       {
          lteUeControlBlock.lteueSpecificData[ueIndex].lengthOfCM3 = pNasMsg[16 + len];
          len += 2;
          for(i = 0; i<lteUeControlBlock.lteueSpecificData[ueIndex].lengthOfCM3; i++)
          {
              lteUeControlBlock.lteueSpecificData[ueIndex].encodedCM3[i] = pNasMsg[15 + len];
              len += 1;
          }
       }
    }
}

void checkAndDeleteDuplicateUeContext(int ueIndex)
{
   if(TRUE == exitLteApp)
   {
        return;
   }

   int ueIdx = 0;

   for (ueIdx = 0; ueIdx < LTE_MAX_USER_SUPPORTED; ueIdx++)
   {
       if(0 == strncmp(lteUeControlBlock.lteueSpecificData[ueIdx].imsi,
                       lteUeControlBlock.lteueSpecificData[ueIndex].imsi,
                       MAX_IDENTITY_LENGTH_STR_4G))
       {
           if (ueIndex != ueIdx)
           {
               logPrint(LOG_DEBUG, "Duplicate Entry found at index = %d for IMSI = %s\n", 
                        ueIdx, lteUeControlBlock.lteueSpecificData[ueIndex].imsi);

               if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIdx].ueTimer))
               {
                   timerStop(&lteUeControlBlock.lteueSpecificData[ueIdx].ueTimer);
               }

               memset(&lteUeControlBlock.lteueSpecificData[ueIdx], 0, sizeof(lteRrcUeSpecificData));
			   /*
               lteL2InftMsg_t *pRrcMsg;
               pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
               if (NULL != pRrcMsg)
               {
                   pRrcMsg->msgType = LTE_MSG_DELETE_MAC_RLC_USER_CNTXT_E;
                   pRrcMsg->l2Data.crnti = ueIdx + LTE_C_RNTI_START;
                   ltePutMsgInRlcQ((void*)pRrcMsg);
               }*/
          }
      }
      else if((UE_WAIT_FOR_RRC_CON_SETUP_COMPLETE_LTE != lteUeControlBlock.lteueSpecificData[ueIdx].ueState) && 
	  	      (UE_RELEASED != lteUeControlBlock.lteueSpecificData[ueIdx].ueState) &&
	  	      (strlen(lteUeControlBlock.lteueSpecificData[ueIdx].imsi) < 15))
      {
          logPrint(LOG_DEBUG, "Empty IMSI at index = %d for IMSI = %s\n", 
                   ueIdx, lteUeControlBlock.lteueSpecificData[ueIdx].imsi);

          if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIdx].ueTimer))
          {
              timerStop(&lteUeControlBlock.lteueSpecificData[ueIdx].ueTimer);
          }

          memset(&lteUeControlBlock.lteueSpecificData[ueIdx], 0, sizeof(lteRrcUeSpecificData));
		  /*
          lteL2InftMsg_t *pRrcMsg;
          pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
          if (NULL != pRrcMsg)
          {
              pRrcMsg->msgType = LTE_MSG_DELETE_MAC_RLC_USER_CNTXT_E;
              pRrcMsg->l2Data.crnti = ueIdx + LTE_C_RNTI_START;
              ltePutMsgInRlcQ((void*)pRrcMsg);
          }*/  
      }
   }
}

/*
 *############################################################################
 * Method Name : decodeMobileIdentity
 *
 * Description :  Decodes Mobile Identity from DedicatedNAS info
 *
 * Parameters	: Takes ueIndex as input , unsigned char of DedicatedNAsInfo
 *
 * Returns 	: None
 *############################################################################
 */
int decodeMobileIdentity(int ueIndex , unsigned char *pNasMsg)
{
    if(TRUE == exitLteApp)
    {
            return -1;
    }

	if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_RRC_CON_SETUP_COMPLETE_LTE)
	{
		if((pNasMsg[4] & 0x07) == IMSI_ID) // IMSI received
		{
			bcd2str(&pNasMsg[3],lteUeControlBlock.lteueSpecificData[ueIndex].imsi,FALSE);
            //checkAndDeleteDuplicateUeContext(ueIndex);
			memcpy(lteUeControlBlock.lteueSpecificData[ueIndex].userImsi , &pNasMsg[3] , SIZE_OF_IDENTITY_3GPP);
			// It will check received MobileID is BlackListed or WhiteListed
			if(lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
			{
				checkMobileIDCfg(ueIndex , TRUE);
				if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
				{

                    lteblackListedUserInfo* blackUserInfo =
                    blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);

					if(lteRrcRedirectFlag)
					{
                       if (lteRrcPrmRedirectFlag)
                       {
                               lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
                       }
                       else
                       {
                               lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                       }
					}
                    else if((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
                    {
                       lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                    }
					else
					{					
						lteblackListedUserInfo* blackListUser = lteuserStoreBlackListedInfo(ueIndex);// create BL user Linkedlist
						//Now check here if SC is in progress if yes , change the state to asking for measurement report
						if((blackListUser != NULL)&&(blackListUser->lteSilentCallStarted == TRUE))
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG;
						}
						else
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
						}
					}
				}
				else
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
				}
			}
			else //NAS_EMM_ATTACH_REQUEST
			{
				checkMobileIDCfg(ueIndex,TRUE);
				if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
				{

                    lteblackListedUserInfo* blackUserInfo =
                    blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);
					if(lteRrcRedirectFlag)
					{
                       if (lteRrcPrmRedirectFlag)
                       {
                               lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
                       }
                       else
                       {
                               lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                       }
					}
                    else if((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
                    {
                           lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                    }
					else
					{
					    lteblackListedUserInfo* blackListUser = lteuserStoreBlackListedInfo(ueIndex);// create BL user Linkedlist
						//Now check here if SC is in progress if yes , change the state to asking for measurement report
						if((blackListUser != NULL)&&(blackListUser->lteSilentCallStarted == TRUE))
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG;
						}
						else
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
						}
					}
				}
			 	else
               	{
                    lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
                }
			}
		}
		else if ((pNasMsg[4] & 0x07) == GUTI_ID) // GUTI received
		{
			//Decode GUTI TODO
			decodeGUTI(&pNasMsg[3],&lteUeControlBlock.lteueSpecificData[ueIndex].guti);
			lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDT_IMSI;
		}
		else if ((pNasMsg[4] & 0x07) == IMEI_ID_TYPE1) // IMEI received
		{
			bcd2str(&pNasMsg[3],lteUeControlBlock.lteueSpecificData[ueIndex].imei,FALSE);
			// It will check received MobileID is BlackListed or WhiteListed
			checkMobileIDCfg(ueIndex,TRUE);
			if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
			{

               lteblackListedUserInfo* blackUserInfo =
               blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);
               if(lteRrcRedirectFlag)
               {
                     if (lteRrcPrmRedirectFlag)
                     {
                            lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
                     }
                     else
                     {
                            lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                     }
               }
               else if ((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
               {
                     lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
               }
               else
               {
                      lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
               }
			}
			else
			{
			        // Here TAU Reject and Attach Reject based on pNasMsgType
				if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_EMM_ATTACH_REQUEST )
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
				}
				else if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
				}
			}
		}
		else
		{
			lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDT_IMSI;
		}
	}
	else if (lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDENTITY_RESP_LTE)
	{
		if ((pNasMsg[3] & 0x07) == IMSI_ID) //IMSI Response
		{
			bcd2str(&pNasMsg[2],lteUeControlBlock.lteueSpecificData[ueIndex].imsi,FALSE);
			memcpy(lteUeControlBlock.lteueSpecificData[ueIndex].userImsi , &pNasMsg[2] , SIZE_OF_IDENTITY_3GPP);
			if(lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
			{
				checkMobileIDCfg(ueIndex,TRUE);
				if (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
				{

                    lteblackListedUserInfo* blackUserInfo =
                    blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);

					if(lteRrcRedirectFlag)
					{
                       if (lteRrcPrmRedirectFlag)
                       {
                               lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
                       }
                       else
                       {
                                lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                       }
					}
                    else if((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
                    {
                           lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                    }
					else
					{
						lteblackListedUserInfo* blackListUser = lteuserStoreBlackListedInfo(ueIndex);// create BL user Linkedlist
						//Now check here if SC is in progress if yes , change the state to asking for measurement report
						if((blackListUser != NULL)&&(blackListUser->lteSilentCallStarted == TRUE))
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG;
						}
						else
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
						}
					}
				}
				else
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
				}
			}
			else //NAS_EMM_ATTACH_REQUEST
			{
				checkMobileIDCfg(ueIndex,TRUE);
				if (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
				{

                    lteblackListedUserInfo* blackUserInfo =
                    blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);
					if(lteRrcRedirectFlag)
					{
                       if (lteRrcPrmRedirectFlag)
                       {
                               lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
                       }
                       else
                       {
                               lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                       }
					}
                    else if((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
                    {
                           lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                    }
					else
					{
						lteblackListedUserInfo* blackListUser = lteuserStoreBlackListedInfo(ueIndex);// create BL user Linkedlist
						//Now check here if SC is in progress if yes , change the state to asking for measurement report
						if((blackListUser != NULL)&&(blackListUser->lteSilentCallStarted == TRUE))
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG;
						}
						else
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
						}
					}
				}
                else
                {
	                lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
                }
			}
		}
		else if ((pNasMsg[3] & 0x07) == IMEI_ID_TYPE2) // IMEI Response
		{
			bcd2str(&pNasMsg[2],lteUeControlBlock.lteueSpecificData[ueIndex].imei,FALSE);
				
			uint8 check_digit = 0 ;
			uint8 len = 0;
			check_digit = getImeiCheckDigit(lteUeControlBlock.lteueSpecificData[ueIndex].imei);
			len= strlen(lteUeControlBlock.lteueSpecificData[ueIndex].imei);
			assert(len < MAX_IDENTITY_LENGTH_STR);

			lteUeControlBlock.lteueSpecificData[ueIndex].imei[len-1] = check_digit;
			logPrint(LOG_DEBUG, "decodeMobileIdentity IMEI+CD = %s \n" , lteUeControlBlock.lteueSpecificData[ueIndex].imei);

			// It will check received MobileID is BlackListed or WhiteListed
			checkMobileIDCfg(ueIndex,TRUE);

			if (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
			{

               lteblackListedUserInfo* blackUserInfo =
               blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);
               if(lteRrcRedirectFlag)
               {
                   if (lteRrcPrmRedirectFlag)
                   {
                             lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
                   }
                   else
                   {
                              lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                   }
               }
               else if((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
               {
                       lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
               }
               else
               {
                       lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
               }
			}
			else
			{
				// Here TAU Reject and Attach Reject based on pNasMsgType
				if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_EMM_ATTACH_REQUEST )
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
				}
				else if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
				}
			}
		}
		else
		{				
		    if(lteSilentCallStarted == TRUE)
		    {
			  	lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_MEAS_CONFIG;
				return -1;
            }
		    return 0;
		}
	}
	else{}

return -1;
}

/*
 *############################################################################
 * Method Name : handleIdentityReqTimeout
 *
 * Description :  Callback funtion for Identity Request Timeout
 *
 * Parameters	: pTimer , ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void handleIdentityReqTimeout(tcbTimer_t *pTimer, void *pUeIndex)
{
    if(TRUE == exitLteApp)
    {
       return;
    }
	/* Get UE context */
	lteRrcUeSpecificData *pUeCntxt = (lteRrcUeSpecificData *)pUeIndex;
	if(pUeCntxt != NULL)
	{
		logPrint(LOG_DEBUG, "Identity Request Timeout for UE Id(%ld)\n", pUeCntxt->crnti);
		if((pUeCntxt->ueLteIMSIReqCount < 3)&&(pUeCntxt->ueState == UE_WAIT_FOR_IDENTITY_RESP_LTE) && (strlen(pUeCntxt->imsi) == 0))
		{
			pUeCntxt->ueState = UE_WAIT_FOR_IDT_IMSI;
			buildAndEncodeIdentityMsg(pUeCntxt->crnti - LTE_C_RNTI_START);
			sendSignalToSelfTostartIdentityReqTimer(pUeCntxt->crnti);
		}
		else
		{
			lteRrcReleaseUeToNwHandler(pUeCntxt->crnti);
		}
	}
}

/*
 *############################################################################
 * Method Name : handleAttachRejTimeout
 *
 * Description :
 *
 * Parameters	: pTimer , ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void handleAttachRejTimeout(tcbTimer_t *pTimer, void *pUeIndex)
{

    if(TRUE == exitLteApp)
    {
       return;
    }
	/* Get UE context */
	lteRrcUeSpecificData *pUeCntxt = (lteRrcUeSpecificData *)pUeIndex;
	if(pUeCntxt != NULL)
	{
		pUeCntxt->ueState = UE_WAIT_FOR_RRC_CON_REL;

		if (pUeCntxt->userBlacklisted == FALSE)
		{
			pUeCntxt->ueState = UE_WAIT_FOR_RRC_CONN_WL_REDIRECT;
		}

		logPrint(LOG_DEBUG, "Attach Reject Timeout for UE Id(%d)\n", pUeCntxt->crnti);

		if(((pUeCntxt->crnti - LTE_C_RNTI_START) >= 0)&&((pUeCntxt->crnti - LTE_C_RNTI_START) < LTE_MAX_USER_SUPPORTED))
		{
			buildAndEncodeRrcReleaseMsg(pUeCntxt->crnti - LTE_C_RNTI_START);
		}
	}
}


/*
 *############################################################################
 * Method Name : handleTAURejTimeout
 *
 * Description :
 *
 * Parameters	: pTimer , ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void handleTAURejTimeout(tcbTimer_t *pTimer, void *pUeIndex)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	/* Get UE context */
	lteRrcUeSpecificData *pUeCntxt = (lteRrcUeSpecificData *)pUeIndex;
	if(pUeCntxt != NULL)
	{
		pUeCntxt->ueState = UE_WAIT_FOR_RRC_CON_REL;

		if (pUeCntxt->userBlacklisted == FALSE)
		{
			pUeCntxt->ueState = UE_WAIT_FOR_RRC_CONN_WL_REDIRECT;
		}

		logPrint(LOG_DEBUG, "TAU Reject Timeout for UE Id(%d)\n", pUeCntxt->crnti);
		if(((pUeCntxt->crnti - LTE_C_RNTI_START) >= 0)&&((pUeCntxt->crnti - LTE_C_RNTI_START) < LTE_MAX_USER_SUPPORTED))
		{
			buildAndEncodeRrcReleaseMsg(pUeCntxt->crnti - LTE_C_RNTI_START);
		}
	}
}

/*
 *############################################################################
 * Method Name : handleMeasReportTimeout
 *
 * Description :
 *
 * Parameters	: pTimer , ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void handleMeasReportTimeout(tcbTimer_t *pTimer, void *pUeIndex)
{
    if(TRUE == exitLteApp)
    {
       return;
    }
	/* Get UE context */
	lteRrcUeSpecificData *pUeCntxt = (lteRrcUeSpecificData *)pUeIndex;
	if(pUeCntxt != NULL)
	{
		logPrint(LOG_DEBUG, "Meas Report Timeout for UE Id(%d)\n", pUeCntxt->crnti);
		pUeCntxt->ueState = UE_WAIT_FOR_RRC_CON_REL;
		if(((pUeCntxt->crnti - LTE_C_RNTI_START) >= 0)&&((pUeCntxt->crnti - LTE_C_RNTI_START) < LTE_MAX_USER_SUPPORTED))
		{
			buildAndEncodeRrcReleaseMsg(pUeCntxt->crnti - LTE_C_RNTI_START);
		}
	}
}

/*
 *############################################################################
 * Method Name : handleRrcConnKeepAliveTimer
 *
 * Description :
 *
 * Parameters	: pTimer , ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void handleRrcConnKeepAliveTimer(tcbTimer_t *pTimer, void *pUeIndex)
{
    if(TRUE == exitLteApp)
    {
       return;
    }
	/* Get UE context */
	lteRrcUeSpecificData *pUeCntxt = (lteRrcUeSpecificData *)pUeIndex;
	if(pUeCntxt != NULL)
	{
		logPrint(LOG_DEBUG, "handleRrcConnKeepAliveTimer UE Id(%d)\n", pUeCntxt->crnti);
		if(((pUeCntxt->crnti - LTE_C_RNTI_START) >= 0)&&((pUeCntxt->crnti - LTE_C_RNTI_START) < LTE_MAX_USER_SUPPORTED))
		{

			lteblackListedUserInfo *blackUserInfo = blacklistLteUserFindUsingIdentity(pUeCntxt->userImsi , TRUE);
			if(blackUserInfo != NULL)
			{
				blackUserInfo->ueCheckFlag = TRUE;
			}
			
			if((pUeCntxt->ueLteIMSIReqCount % 2) == 0)
			{
				buildAndEncodeIdentityMsg(pUeCntxt->crnti - LTE_C_RNTI_START);
			}
			else
			{
				buildAndEncodeRrcUeCapaEnqMsg(pUeCntxt->crnti - LTE_C_RNTI_START);
			}

			pUeCntxt->ueLteIMSIReqCount++;
		}
	}
}

/*
 *############################################################################
 * Method Name : sendStartSibchangePagingTimerMsgToSelf
 *
 * Description :
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void sendStartSibchangePagingTimerMsgToSelf(void)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	lteL2InftMsg_t *rrcMsg = &pagingTimerStart ;
    rrcMsg->msgType        = LTE_MSG_RRC_RESTART_SIB_CHANGE_PAGING_TIMER_E;
    rrcMsg->l2Data.size = 0;
    ltePutMsgInRrcQ((void*)rrcMsg);

    return;
}

/*
 *############################################################################
 * Method Name : handleRrcPagingTimeout
 *
 * Description :
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void handleRrcPagingTimeout(tcbTimer_t *pTimer, void *pUeCntxt)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	//logPrint(LOG_DEBUG, "SIB Modification Timeout\n");
	buildAndEncodeRrcPagingSibModMsgRrcThrd();
	sendStartSibchangePagingTimerMsgToSelf();
	return;
}

void handle4gScSibPageRetransmitTimeoutRrcThrd(tcbTimer_t *pTimer, void *blUsr)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	lteblackListedUserInfo *blUser = (lteblackListedUserInfo*)blUsr;
	if(blUser != NULL)
	{
		if(blUser->measurementType == FXL_4G_OWN_CELL_MEASUREMENT)
		{
			sendUeRssiPhrReportIndToClient(blUser);
		}
		
		if(blUser->ueCheckFlag == TRUE)
		{
			blUser->ueCheckCntr = 0;
			blUser->ueCheckFlag = FALSE;
		}
		else
		{
			if(blUser->ueCheckCntr++ == LTE_BLACKLIST_UE_REMOVE_COUNTER)
			{
				blUser->blRemoveFlag = TRUE;
				blUser->ulRssiPhr = 0;
				logPrint(LOG_DEBUG , "Ready to remove BlackListed UE %p \n", blUser);
				buildAndEncodeRrcPagingSibModMsgRrcThrd();
				blUser->ueCheckCntr = 0;
			}
		}
				
		if((blUser->measRepCntr % SIB_MODIFICATION_PAGING_COUNTER) == 0)
		{
			buildAndSendSibChangePagingMsgRrcThrd(blUser , TRUE); //For Non-QC stack page happens when we receive IMSI in connected mode.				
		}

		
		if(blUser->measRepCntr == 0xFFFFFFFF)
		{
			blUser->measRepCntr = 0;
		}
		else
		{
			blUser->measRepCntr = blUser->measRepCntr + 1;
		}
	}
	return;
}
//ASHU ASN.1 Issue

/*
 *############################################################################
 * Method Name :sendLteBlTestSibModificationPage
 *
 * Description :
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void sendLteBlTestSibModificationPage(lteblackListedUserInfo *blUsr)
{
    if(TRUE == exitLteApp)
    {
            return;
    }

	//logPrint(LOG_DEBUG, "Lte Bl Test QC Check:sendLteBlTestSibModificationPage \n");
	lteblackListedUserInfo *blUser = (lteblackListedUserInfo*)blUsr;
	if((blUser != NULL)&&(blUser->lteSilentCallStarted == FALSE))
	{
		buildAndSendSibChangePagingMsgRrcThrd(blUser, TRUE);

		if(TRUE == isTimerRunning(&blUser->blTimer))
		{
			timerStop(&blUser->blTimer);
		}
		
		timerStart(&blUser->blTimer , LTE_BL_STEP2_TIMER , 0 , &handle4gBlTestTimeout, blUser);
	}
}

/*
 *############################################################################
 * Method Name : handle4gBlQCCheckTestTimeout
 *
 * Description :
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void handle4gBlQCCheckTestTimeout(tcbTimer_t *pTimer, void *blUsr)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	//logPrint(LOG_DEBUG, "Lte Bl Test QC Check:handle4gBlQCCheckTestTimeout \n");
	lteblackListedUserInfo *blUser = (lteblackListedUserInfo*)blUsr;
	if(blUser != NULL)
	{
		sendSignalToSelfToPageSIBModBLTest(blUser);
	}
	return;
}


/*
 *############################################################################
 * Method Name : handle4gBlTestTimeout
 *
 * Description :
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void handle4gBlTestTimeout(tcbTimer_t *pTimer, void *blUsr)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	lteblackListedUserInfo *blUser = (lteblackListedUserInfo*)blUsr;
	assert(blUser != NULL);
	return;
}

/*
 *############################################################################
 * Method Name :handleUeCapaEnqTimeout
 *
 * Description :
 *
 * Parameters	: pTimer , ueIndex
 *
 * Returns 	: None
 *############################################################################
 */
void handleUeCapaEnqTimeout(tcbTimer_t *pTimer, void *pUeIndex)
{
    if(TRUE == exitLteApp)
    {
       return;
    }
	/* Get UE context */
	lteRrcUeSpecificData *pUeCntxt = (lteRrcUeSpecificData *)pUeIndex;
	if(pUeCntxt != NULL)
	{
		pUeCntxt->ueState = UE_WAIT_FOR_RRC_UECAPA_ENQUIRY;
		logPrint(LOG_DEBUG, "UE CAPA ENQ Timeout for UE Id(%d)\n", pUeCntxt->crnti);
		buildAndEncodeRrcUeCapaEnqMsg(pUeCntxt->crnti - LTE_C_RNTI_START);
	}
}

/*
 *############################################################################
 * Method Name : InitializeLteRrcContext
 *
 * Description : Initializes RRC context
 *
= * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void InitializeLteRrcContext (void)
{
    /* Initialize RRC UE Control Block */
    memset((lteRrcUeControlBlock *)&lteUeControlBlock, 0, sizeof(lteUeControlBlock));
	timerInit(&pgTimer);
	for(uint8 i=0 ; i< LTE_MAX_USER_SUPPORTED ; i++)
	{
		timerInit(&lteUeControlBlock.lteueSpecificData[i].ueTimer);
	}
	sibModTimerStarted = FALSE;
}

uint8 checkDefaultconfigOfList()
{
    uint8 *sharedMemPtr = getAccessToIdList();
	configUeIdList.configId = (IdentityConfigStr *)(sharedMemPtr + CONFIG_DATA_SIZE);
    releaseAccessToIdList(sharedMemPtr);
	return configUeIdList.defaultConfig;
}
/*
 *############################################################################
 * Method Name : searchIdDbForRecvdID
 *
 * Description : This function search for received Mobile IDentity in WL/BL database
 *
 * Parameters	: UeIndex and bool for imsi or imei presence
 *
 * Returns 	: None
 *############################################################################
 */
void searchIdDbForRecvdID(int ueIndex, uint8 isImsi)
{
    if(TRUE == exitLteApp)
    {
           return;
    }

    uint16 i;
    uint8 *sharedMemPtr = getAccessToIdList();
	configUeIdList.configId = (IdentityConfigStr *)(sharedMemPtr + CONFIG_DATA_SIZE);

	if((configUeIdList.defaultConfig == BLACKLIST)&&(configUeIdList.numbOfIds == 0))
	{
		lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = TRUE;
	}
	else // WHITELIST, or 
	{
	    for(i= 0; i < configUeIdList.numbOfIds; i++)
	    {
	    	if(isImsi == TRUE) // IMSI List
	    	{
				if (((configUeIdList.configId + i)->idType == IMSI) && (memcmp((configUeIdList.configId + i)->identity,lteUeControlBlock.lteueSpecificData[ueIndex].imsi, MAX_IDENTITY_LENGTH_STR) == 0 ))
				{
					if((configUeIdList.configId + i)->listType == BLACKLIST )
					{
						lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = TRUE;
						//logPrint(LOG_DEBUG, "User = %d : BLACKLISTING IMSI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imsi);
						break;
					}
					else if((configUeIdList.configId + i)->listType == WHITELIST )
					{
						lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = FALSE;
						lteUeControlBlock.lteueSpecificData[ueIndex].wlAttRejCause= (configUeIdList.configId + i)->rejectCauseIfWhitelist;
						//logPrint(LOG_DEBUG, "User = %d : WHITELISTING IMSI [%s] , reject Cause = %d\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imsi,lteUeControlBlock.lteueSpecificData[ueIndex].wlAttRejCause);
						break;
					}
					else
					{
						if((configUeIdList.defaultConfig == BLACKLIST)&&(configUeIdList.numbOfIds != 0))
						{
							lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = TRUE;
							break;
						}
						
					}
				}
	    	}
	    	/* else // IMEI List
	    	{
				if (((configUeIdList.configId + i)->idType == IMEI) && memcmp((configUeIdList.configId + i)->identity, lteUeControlBlock.lteueSpecificData[ueIndex].imei, MAX_IDENTITY_LENGTH_STR) == 0 )
				 {
					 if((configUeIdList.configId + i)->listType == BLACKLIST )
					 {
						 lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = TRUE;
						 logPrint(LOG_DEBUG, "User = %d : BLACKLISTING IMEI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imei);
						 break;
					 }
					 else if((configUeIdList.configId + i)->listType == WHITELIST )
					 {
						 lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = FALSE;
						 lteUeControlBlock.lteueSpecificData[ueIndex].wlAttRejCause= (configUeIdList.configId + i)->rejectCauseIfWhitelist;
						 break;
					 }
					 else
					 {
						 if((configUeIdList.defaultConfig == BLACKLIST)&&(configUeIdList.numbOfIds != 0))
						 {
							 lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = TRUE;
						 }
					 }
				 }
		    }*/
	    }
	}
    releaseAccessToIdList(sharedMemPtr);
}

/*
 *############################################################################
 * Method Name : checkMobileIDCfg
 *
 * Description : This function check recived Mobile Identity in configured WL/BL list
 *
 * Parameters	: ueIndex and isIMSI
 *
 * Returns 	: None
 *############################################################################
 */
void checkMobileIDCfg(int ueIndex,int isImsi)
{

	ConfigList* ConfigListPtr = getConfigUeIdListPtr();
	lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = 0xFF;
	assert(ConfigListPtr != NULL);

	// Black/white listing.
    if(isImsi)
    {
    	//logPrint(LOG_DEBUG, "Received IdentityType = IMSI  \n");
    	searchIdDbForRecvdID(ueIndex,  TRUE);

        if((ConfigListPtr->defaultConfig == WHITELIST) && (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == 0xFF))
		{
        	lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = FALSE;
        	//logPrint(LOG_DEBUG, "User = %d : WHITELISTING IMSI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imsi);
		}
        else if((ConfigListPtr->defaultConfig == BLACKLIST) && (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == 0xFF))
        {
        	lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = TRUE;
			//logPrint(LOG_DEBUG, "User = %d : BLACKLISTING IMSI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imsi);
        }

	}
    else if (isImsi == FALSE) // NO IMEI BL/WL Concept for LTE
    {
		logPrint(LOG_DEBUG, "Received IdentityType = IMEI \n");
        lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = 0xFF;
        searchIdDbForRecvdID(ueIndex, FALSE);

		if((ConfigListPtr->defaultConfig == WHITELIST) && (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == 0xFF))
		{
			lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = FALSE;
			//logPrint(LOG_DEBUG, "User = %d : WHITELISTING IMEI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imei);
		}
		else if((ConfigListPtr->defaultConfig == BLACKLIST) && (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == 0xFF))
		{
			lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted = TRUE;
			//logPrint(LOG_DEBUG, "User = %d : BLACKLISTING IMSI [%s]\n",ueIndex, lteUeControlBlock.lteueSpecificData[ueIndex].imei);
		}
    }
}

void processUlMsgForImeiReq(int ueIndex, lteRrcUlDCCHData *pUlMsg)
{
    if(TRUE == exitLteApp)
    {
            return;
    }

	if (pUlMsg->ulMsgType == UL_SECURITY_MODE_FAILURE)
	{
			// It will check received MobileID is BlackListed or WhiteListed
			checkMobileIDCfg(ueIndex,TRUE);

			if (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
			{
               lteblackListedUserInfo* blackUserInfo =
                                                       blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);
				if(lteRrcRedirectFlag)
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
				}
                else if((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
                {
                    lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
                }
				else
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL;
				}
			}
			else
			{
				// Here TAU Reject and Attach Reject based on pNasMsgType
				if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_EMM_ATTACH_REQUEST )
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_ATTACH_REJECT;
				}
				else if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
				{
					lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_TAU_REJECT;
				}

			}
	}
	else
	{
		logPrint(LOG_DEBUG, "User = %d : Received UL Message(%d) not Handled " , ueIndex,pUlMsg->ulMsgType);
	}

}

void lteRlcResetHandler(uint16 crnti)
{
	unsigned int ueIndex = crnti - LTE_C_RNTI_START;
	if(lteUeControlBlock.lteueSpecificData[ueIndex].ueState != UE_RELEASED)
	{
		char tmp[MAX_IDENTITY_LENGTH_STR_4G] = {0};
		if(memcmp(tmp , lteUeControlBlock.lteueSpecificData[ueIndex].imsi , MAX_IDENTITY_LENGTH_STR_4G) != 0)
		{
			checkMobileIDCfg(ueIndex,TRUE);
			//sendIndicationToClient(ueIndex);
			if(lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
            {
                 triggerPagingForBlUsers(ueIndex); 
            }
		}
		else
		{
			logPrint(LOG_DEBUG , "lteRlcResetHandler CRNTI = %d : IMSI NOT RECEIVED YET = %s\n" , crnti, lteUeControlBlock.lteueSpecificData[ueIndex].imsi);
		}

	}
	lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_RELEASED;
	return;
}


void lteRrcReleaseUeToNwHandler(uint16 crnti)
{
    if(TRUE == exitLteApp)
    {
            return;
    }

	unsigned int ueIndex = crnti - LTE_C_RNTI_START;
	char tmp[MAX_IDENTITY_LENGTH_STR_4G] = {0};
	if(lteUeControlBlock.lteueSpecificData[ueIndex].ueState !=  UE_RELEASED )
    {
		if(memcmp(tmp , lteUeControlBlock.lteueSpecificData[ueIndex].imsi , MAX_IDENTITY_LENGTH_STR_4G) != 0)
		{
			// It will check received MobileID is BlackListed or WhiteListed
			checkMobileIDCfg(ueIndex,TRUE);
			if (lteUeControlBlock.lteueSpecificData[ueIndex].userBlacklisted == TRUE)
			{
				if((!lteRrcRedirectFlag)&&(lteUeControlBlock.lteueSpecificData[ueIndex].ueState <=  UE_WAIT_FOR_RRC_CONN_WL_REDIRECT))
				{
					// Here TAU Reject and Attach Reject based on pNasMsgType
					if(lteSilentCallStarted == FALSE)
					{
						if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_EMM_ATTACH_REQUEST )
						{
							buildAndEncodeAttachRejMsg(ueIndex);
						}
						else if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
						{
							buildAndEncodeTAURejMsg(ueIndex);
						}
					}	
				}
				else
				{
					lteL2InftMsg_t *pRrcMsg;
					pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
					pRrcMsg->msgType = LTE_MSG_RRC_CONN_REL_DL_DCH_SDU_REQ_E;
					pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
					pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header

                    if (lteRrcRedirectFlag)
                    {
                        assert(asn1EncodedRrcConnectionReleaseWithRedirect != NULL);
                        pRrcMsg->l2Data.size = asn1EncodedRrcConnectionReleaseLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
                        memcpy(&pRrcMsg->l2Data.dataBuf[1],asn1EncodedRrcConnectionReleaseWithRedirect,asn1EncodedRrcConnectionReleaseWithRedirectLen);
                    }
                    else
                    {
						lteblackListedUserInfo* blackUserInfo =
						blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);

						if ((NULL != blackUserInfo) && (TRUE == blackUserInfo->redirectEnabled))
						{
						    assert(blackUserInfo->pRrcConRelWithRedirect != NULL);
						    pRrcMsg->l2Data.size = blackUserInfo->rrcConRelWithRedirectLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
						    memcpy(&pRrcMsg->l2Data.dataBuf[1] ,
						            blackUserInfo->pRrcConRelWithRedirect,
						            blackUserInfo->rrcConRelWithRedirectLen);
						    logPrint(LOG_DEBUG, "buildAndEncodeRrcReleaseMsg Per UE Based RrcConnReRedirect= %d \n",
						             blackUserInfo->rrcConRelWithRedirectLen);
						}
						else
						{
						    assert(asn1EncodedRrcConnectionRelease != NULL);
						    pRrcMsg->l2Data.size = asn1EncodedRrcConnectionReleaseLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
						    memcpy(&pRrcMsg->l2Data.dataBuf[1] ,
						            asn1EncodedRrcConnectionRelease,
						            asn1EncodedRrcConnectionReleaseLen);
						    logPrint(LOG_DEBUG, "buildAndEncodeRrcReleaseMsg without Redirect= %d \n",
						              asn1EncodedRrcConnectionReleaseLen);
						}

                    }
					ltePutMsgInRlcQ((void*)pRrcMsg);
				}

                sendIndicationToClient(ueIndex);
                lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_RELEASED;
			}
			else
			{
				if(lteSilentCallStarted == FALSE)
				{
					if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_EMM_ATTACH_REQUEST )
					{
						buildAndEncodeAttachRejMsg(ueIndex);
					}
					else if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
					{
						buildAndEncodeTAURejMsg(ueIndex);
					}
				}	
			}
		}
		else
		{
			// Here TAU Reject and Attach Reject based on pNasMsgType
			
			if(lteSilentCallStarted == FALSE)
			{
				if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_EMM_ATTACH_REQUEST )
				{
					if(lteUeControlBlock.lteueSpecificData[ueIndex].ueState == UE_WAIT_FOR_IDENTITY_RESP_LTE)
					{
						buildAndEncodeAttachRejMsg(ueIndex);
					}
				}
				else if (lteUeControlBlock.lteueSpecificData[ueIndex].nasMsgType == NAS_TRACKING_AREA_UPDATE_REQ)
				{
					buildAndEncodeTAURejMsg(ueIndex);
				}
			}
		}
    }
	return;
}

void lteStopRrcTimer(uint16 crnti)
{
	int ueIndex = crnti - LTE_C_RNTI_START;
	if((ueIndex >= 0)&&(ueIndex < LTE_MAX_USER_SUPPORTED))
	{
	    if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
	}
}

void lteStartRrcIdentityReqTimer(uint16 crnti)
{
	if(TRUE == exitLteApp)
    {
       return;
    }

	int ueIndex = crnti - LTE_C_RNTI_START;
	if((ueIndex >= 0)&&(ueIndex < LTE_MAX_USER_SUPPORTED))
	{	
		if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
		{
			timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		}
		
		timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
					TIMER_FOR_4G_IDENTITY_REQUEST_TIMEOUT,
		           0,
		           handleIdentityReqTimeout,
		           &lteUeControlBlock.lteueSpecificData[ueIndex]);		
	}
}

uint8 compareLteUserIdentity(lteblackListedUserInfo* info , uint8* identity , uint8 isItBcd)
{
    if(TRUE == exitLteApp)
    {
            return TRUE;
    }

	uint8 ret = FALSE;
	//Check if it is TMSI or IMSI based on format
	if(isItBcd == TRUE)
	{
		if((identity[1] & 0x07) == 0x01)
		{
			 if(memcmp(info->userImsi , identity , SIZE_OF_IDENTITY_3GPP) == 0) // Imsi
				ret = TRUE;
		}
		else
		{
			// Identity type is not IMSI/TMSI, of which we have no interest
			logPrint(LOG_DEBUG , "compareUserIdentity: Identity type is not IMSI/TMSI\n" );
		}
	}
	else
	{
		// IMSI is in string format
		if(memcmp(info->userImsi_str , identity , MAX_IDENTITY_LENGTH_STR) == 0) // Imsi_str
		{
			ret = TRUE;
		}
		else
		{
			//logPrint(LOG_DEBUG,"IMSI1 = %s , IMSI2 = %s \n", info->userImsi_str , identity);
		}

	}
	return ret;
}

lteblackListedUserInfo* blacklistLteUserFindUsingIdentity(uint8 *identity , uint8 isItBcd)
{
    if(TRUE == exitLteApp)
    {
            return NULL;
    }

	lteblackListedUserInfo* info = NULL ;
	pthread_mutex_lock(&mutexLteBlackListQ);
	listNode *current = headForLteBlacklistedUserQ;
	if(current == NULL)
	{
		//logPrint(LOG_ERR,"BlackListed User list is empty \n");
	}
	else
	{
		while(current != NULL)
		{
			lteblackListedUserInfo* tmp = (lteblackListedUserInfo*)(current->msg);
			if(compareLteUserIdentity(tmp , identity , isItBcd) == TRUE)
			{
				break;
			}
			else
			{
				current = current->next;
			}
		}
		if(current != NULL)
		{
			info = (lteblackListedUserInfo*) (current->msg);
		}
		else
		{
			logPrint(LOG_ERR,"User NOT found in BlackList \n");
		}
	}
	pthread_mutex_unlock(&mutexLteBlackListQ);
	return info;
}


uint16 imsiMod1024( uint8* imsi )
{
	uint64 multiplier = 1;
	uint64 converted_imsi = 0;
	uint16 ue_id = 0;
	uint8 digit_count , i, k , imsi_len = imsi[0] + 1;;

	if( 0 == imsi_len || (( imsi[ 0 ] & 0x08 ) && ( 1 == imsi_len) ) )
	{
	  ue_id = 0;
	}
	else
	{
		k = imsi_len - 1;

	   if( 0 == ( imsi[ 0 ] & 0x08 ) )
	   {
		 converted_imsi = ( ( imsi[ k ] & 0x0F ) );
		 digit_count = imsi_len * 2 - 3;
		 multiplier = multiplier * 10;
		 k--;
	   }
	   else
	   {
		 digit_count = imsi_len * 2 - 1;
	   }

		for( i = digit_count; i > 0; i-- )
		{
		 if( 0 == ( i % 2 ) )
		{
		  converted_imsi = converted_imsi + ( multiplier * ( imsi[ k ] & 0x0F ) );
		  multiplier = multiplier * 10;
		  k--;
		}
		 else
		{
		  converted_imsi = converted_imsi + ( multiplier * ( ( imsi[ k ] & 0xF0 ) >> 4 ) );
		  multiplier = multiplier * 10;
		}
	 }

		// UE ID: IMSI mod 1024 /
		ue_id = ( uint16 ) converted_imsi % 1024;
	}
 return ue_id;
}

void calculatePOnPF(lteblackListedUserInfo* blackUserInfo)
{
    if(TRUE == exitLteApp)
    {
       return;
    }

	uint16 ue_id;
	uint16 T = 32;// DRX default cycle as per SIB2 configuration
	uint16 N , Ns;
	uint16 i_s;

	ue_id = imsiMod1024(blackUserInfo->userImsi);

	//N = min(T, nB) == min(T, T) == 1
	// here nB = oneT as per SIB2 configuration.

	N = T;
	// PF = SFN mod T = (T div N) x (UE_ID mod N)
	// == > PF = SFN mod 64 = (T div T) x (ue_id % N)
	//                       =   ue_id % N

	blackUserInfo->PF = (ue_id % N) ; // need to calculate futureSFN based on current SFN 0 to 1023

	//Ns: max(1,nB/T) = max (1, T/T) = 1
	Ns = 1;
    i_s = (ue_id/T)%(Ns);// here math.h is not working , Need to FIX

	if (lteDuplxMode) //TDD PO n PF 
	{
			/*	Refer 36.304 : section 7.2
		 * TDD:
			Ns PO when i_s=0 PO when i_s=1 PO when i_s=2 PO when i_s=3
			1  0 N/A N/A N/A
			2  0 5 N/A N/A
			4  0 1 5 6 */

			if (Ns == 1)
			{
				if (i_s == 0)
					blackUserInfo->PO = 0;
				else
					logPrint(LOG_ERR,"Invalid PO \n");
			}
			else if ( Ns == 2)
			{
				if (i_s == 0)
					blackUserInfo->PO = 0;
				else if (i_s == 1 )
					blackUserInfo->PO = 5;
				else
					logPrint(LOG_ERR,"Invalid PO \n");
			}
			else if ( Ns == 4)
			{
				if (i_s == 0)
					blackUserInfo->PO = 0;
				else if (i_s == 1 )
					blackUserInfo->PO = 1;
				else if (i_s == 2 )
					blackUserInfo->PO = 5;
				else if (i_s == 3 )
					blackUserInfo->PO = 6;
				else
					logPrint(LOG_ERR,"Invalid PO \n");

			}
	}
	else
	{
			/*	Refer 36.304 : section 7.2
		 * FDD:
			Ns PO when i_s=0 PO when i_s=1 PO when i_s=2 PO when i_s=3
			1  9 N/A N/A N/A
			2  4 9 N/A N/A
			4  0 4 5 9 */

			if (Ns == 1)
			{
				if (i_s == 0)
					blackUserInfo->PO = 9;
				else
					logPrint(LOG_ERR,"Invalid PO \n");
			}
			else if ( Ns == 2)
			{
				if (i_s == 0)
					blackUserInfo->PO = 4;
				else if (i_s == 1 )
					blackUserInfo->PO = 9;
				else
					logPrint(LOG_ERR,"Invalid PO \n");
			}
			else if ( Ns == 4)
			{
				if (i_s == 0)
					blackUserInfo->PO = 0;
				else if (i_s == 1 )
					blackUserInfo->PO = 4;
				else if (i_s == 2 )
					blackUserInfo->PO = 5;
				else if (i_s == 3 )
					blackUserInfo->PO = 9;
				else
					logPrint(LOG_ERR,"Invalid PO \n");

			}
	}
	logPrint(LOG_INFO,"calculatePOnPF UE_ID = %d PO = %d , PF = %d \n", ue_id , blackUserInfo->PO , blackUserInfo->PF);

}

void removeTargetPagingAfterUERedirected(int ueIndex)
{
	lteblackListedUserInfo blackUserInfo;
	memset(&blackUserInfo , sizeof(lteblackListedUserInfo) , 0);
	memcpy(blackUserInfo.userImsi ,lteUeControlBlock.lteueSpecificData[ueIndex].userImsi , SIZE_OF_IDENTITY_3GPP);
	memcpy(blackUserInfo.userImsi_str ,lteUeControlBlock.lteueSpecificData[ueIndex].imsi  , MAX_IDENTITY_LENGTH_STR);
	calculatePOnPF(&blackUserInfo);
	sendMsgToMacToRemovePagingReq(&blackUserInfo);
	return;
}

lteblackListedUserInfo* lteuserStoreBlackListedInfo(int ueIndex)
{
    if(TRUE == exitLteApp)
    {
        return NULL;
    }

	lteblackListedUserInfo* blackUserInfo = NULL ;
	listNode *tail = NULL;
	uint8 defListType = checkDefaultconfigOfList();
	blackUserInfo = blacklistLteUserFindUsingIdentity(lteUeControlBlock.lteueSpecificData[ueIndex].userImsi , TRUE);
	if((blackUserInfo == NULL) && (FALSE == exitLteApp))
	{
		pthread_mutex_lock(&mutexLteBlackListQ);
		listNode *head = headForLteBlacklistedUserQ;

		if(defListType == WHITELIST)
		{
			if(lenghtOfList(head) == LTE_MAX_USER_SUPPORTED)
			{
				logPrint(LOG_INFO,"BlackList is FULL NOT ADDING THIS USER\n");
				pthread_mutex_unlock(&mutexLteBlackListQ);
				return NULL;
			}
		}
		else
		{
			if(lenghtOfList(head) == 128)
			{
				logPrint(LOG_INFO,"BlackList is FULL NOT ADDING THIS USER\n");
				pthread_mutex_unlock(&mutexLteBlackListQ);
				return NULL;
			}

		}
		blackUserInfo = (lteblackListedUserInfo*) malloc(sizeof(lteblackListedUserInfo));
		assert(blackUserInfo != NULL);

		memset(blackUserInfo , 0 , sizeof(lteblackListedUserInfo));
		memcpy(blackUserInfo->userImsi ,lteUeControlBlock.lteueSpecificData[ueIndex].userImsi , SIZE_OF_IDENTITY_3GPP);
		memcpy(blackUserInfo->userImsi_str ,lteUeControlBlock.lteueSpecificData[ueIndex].imsi  , MAX_IDENTITY_LENGTH_STR);
		calculatePOnPF(blackUserInfo);
	    blackUserInfo->measurementType = FXL_4G_OWN_CELL_MEASUREMENT;
		timerInit(&blackUserInfo->blTimer);

		tail = tailForLteBlacklistedUserQ;
		pushMsgToList(&tail ,(void*)blackUserInfo);
		if((headForLteBlacklistedUserQ == NULL)||(tailForLteBlacklistedUserQ == NULL))
		{
			headForLteBlacklistedUserQ = tailForLteBlacklistedUserQ = tail; // Update for the first time
		}
		else
		{
			tailForLteBlacklistedUserQ = tail; // Just update the tail node
		}
		pthread_mutex_unlock(&mutexLteBlackListQ);	
	}


	blackUserInfo->sTmsiValid = FALSE;
    blackUserInfo->ueCheckCntr = 0;
    blackUserInfo->ueCheckFlag = FALSE;
    blackUserInfo->blRemoveFlag = FALSE;
	blackUserInfo->redirectEnabled = FALSE;

	blackUserInfo->sTmsiValid = lteUeControlBlock.lteueSpecificData[ueIndex].guti.isGutiValid;
	blackUserInfo->mmec = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mmecode;
	blackUserInfo->mTmsi = lteUeControlBlock.lteueSpecificData[ueIndex].guti.mtmsi;

	if(defListType != BLACKLIST)
	{
		if(isTimerRunning(&blackUserInfo->blTimer) == FALSE)
		{
			timerStart(&blackUserInfo->blTimer, 
				       TIMER_FOR_4G_SC_SIB_PAGE_RETRANSMIT, 
				       TIMER_FOR_4G_SC_SIB_PAGE_RETRANSMIT, 
				       &handle4gScSibPageRetransmitTimeoutRrcThrd, 
				       blackUserInfo);
		}	
		blackUserInfo->lteSilentCallStarted = TRUE;
	}
	sendIndicationToClient(ueIndex);		
	return blackUserInfo;
}

lteDlPagingStruct* lteGetImsiForPaging(lteblackListedUserInfo* blackUserInfo)
{
    if(TRUE == exitLteApp)
    {
            return NULL;
    }

	listNode *current = NULL;
	lteDlPagingStruct *pPageImsi = &gPageImsi ;
	memset(pPageImsi, 0 , sizeof(lteDlPagingStruct));

	pthread_mutex_lock(&mutexLteBlackListQ);
	current = headForLteBlacklistedUserQ;
	if(current == NULL)
	{
		//logPrint(LOG_ERR,"BlackListed User list is empty \n");
	}
	else
	{
		while(current != NULL)
		{
		   lteblackListedUserInfo* tmp = (lteblackListedUserInfo*)(current->msg);
		   if(tmp->PF == blackUserInfo->PF )
		   {
				if(pPageImsi->uePageCount <= MAX_PAGE_UE_4G )
				{
					for (int idx = 0; idx < MAX_IDENTITY_LENGTH_STR_4G; idx++)
					{
						// Convert ASCII to Integer for IMSI value
						pPageImsi->imsi[pPageImsi->uePageCount][idx] = tmp->userImsi_str[idx] - '0';
					}
					pPageImsi->mmec[pPageImsi->uePageCount] = tmp->mmec;
					pPageImsi->m_Tmsi[pPageImsi->uePageCount] = htonl(tmp->mTmsi);
					pPageImsi->uePageCount++;
				}
			}
		  current = current->next;
		}
	}
	pthread_mutex_unlock(&mutexLteBlackListQ);
	return pPageImsi;
}

//ASHU ASN.1 Issue
void buildAndSendSibChangePagingMsgRrcThrd(lteblackListedUserInfo *blUser , uint8 newTAC)
{
	if(TRUE == exitLteApp)
    {
        return;
    }

	lteL2InftMsg_t *pRrcMsg;
	if((blUser == NULL)||(blUser->PF > 31))
	{
		assert(0);
	}
	pRrcMsg = (lteL2InftMsg_t *)getRrcPageBuffer(blUser->PF);
	pRrcMsg->msgType = LTE_MSG_PAGING_START_REQ_E;
	pRrcMsg->l2Data.crnti = 0; // invalid for paging message

	if(newTAC == TRUE)
	{
		generateSib1WithNewTARrcThrd();
	}

	pRrcMsg->l2Data.PF = blUser->PF; // will add code to get info from blacklistuserinfo
	pRrcMsg->l2Data.PO = blUser->PO;

	pRrcMsg->l2Data.size = 1;
	pRrcMsg->l2Data.dataBuf[0] = 0x20;
	ltePutMsgInRlcQ((void*)pRrcMsg);

}

//ASHU ASN.1 Issue

void buildAndSendSibChangePagingMsg(lteblackListedUserInfo *blUser , uint8 newTAC)
{
	if(TRUE == exitLteApp)
    {
        return;
    }

	lteL2InftMsg_t *pRrcMsg;
	if((blUser == NULL)||(blUser->PF > 31))
	{
		assert(0);
	}
	pRrcMsg = (lteL2InftMsg_t *)getRrcPageBuffer(blUser->PF);
	pRrcMsg->msgType = LTE_MSG_PAGING_START_REQ_E;
	pRrcMsg->l2Data.crnti = 0; // invalid for paging message

	if(newTAC == TRUE)
	{
		generateSib1WithNewTA();
	}

	pRrcMsg->l2Data.PF = blUser->PF; // will add code to get info from blacklistuserinfo
	pRrcMsg->l2Data.PO = blUser->PO;

	pRrcMsg->l2Data.size = 1;
	pRrcMsg->l2Data.dataBuf[0] = 0x20;

	ltePutMsgInRlcQ((void*)pRrcMsg);

}

uint8* getSTmsiPagingAsnEncodedMsg(lteDlPagingStruct *inRrcPagingBuf)
{
	memset(pageMsg , 0 , 24);
	if(inRrcPagingBuf->uePageCount == 1)
	{
		unsigned int m_Tmsi = htonl(inRrcPagingBuf->m_Tmsi[0]);
		pageMsg[0] = 0x40;
		pageMsg[1] = pageMsg[1] | ((inRrcPagingBuf->mmec[0] >> 4) & 0x0F); // No. of UE's last 3 bits
		pageMsg[2] = (uint8)((inRrcPagingBuf->mmec[0] << 4) & 0xF0) | ((m_Tmsi >> 28) & 0x0000000F);
		pageMsg[3] = (uint8)((m_Tmsi >> 20) & 0x000000F0) | ((m_Tmsi >> 20) & 0x0000000F);
		pageMsg[4] = (uint8)((m_Tmsi >> 12) & 0x000000F0) | ((m_Tmsi >> 12) & 0x0000000F);
		pageMsg[5] = (uint8)((m_Tmsi >> 4) & 0x000000F0) | ((m_Tmsi >> 4) & 0x0000000F);
		pageMsg[6] = (uint8)((m_Tmsi << 4) & 0x000000F0) ;
		inRrcPagingBuf->imsiLength = 7;
	}
	else // Page-Count = 2
	{
		unsigned int m_Tmsi = htonl(inRrcPagingBuf->m_Tmsi[0]);
		unsigned int m_Tmsi1 = htonl(inRrcPagingBuf->m_Tmsi[1]);
		pageMsg[0] = 0x40;
		pageMsg[1] = 0x80; 
		pageMsg[2] = (uint8)((inRrcPagingBuf->mmec[0] << 4) & 0xF0) | ((m_Tmsi >> 28) & 0x0F);
		pageMsg[3] = (uint8)((m_Tmsi >> 20) & 0x000000F0) | ((m_Tmsi >> 20) & 0x0000000F);
		pageMsg[4] = (uint8)((m_Tmsi >> 12) & 0x000000F0) | ((m_Tmsi >> 12) & 0x0000000F);
		pageMsg[5] = (uint8)((m_Tmsi >> 4) & 0x000000F0) | ((m_Tmsi >> 4) & 0x0000000F);
		pageMsg[6] = (uint8) ((m_Tmsi << 4) & 0x000000F0) ;
		pageMsg[7] = (uint8)(inRrcPagingBuf->mmec[1] & 0xFF);
		pageMsg[8] = (uint8)((m_Tmsi1 >> 24) & 0xFF);		
		pageMsg[9] = (uint8)((m_Tmsi1 >> 16) & 0xFF); 
		pageMsg[10] = (uint8)((m_Tmsi1 >> 8) & 0xFF); 
		pageMsg[11] = (uint8)((m_Tmsi1) & 0xFF); 
		pageMsg[12] = 0x00;
		inRrcPagingBuf->imsiLength = 13;
	}
		

	//logPrint(LOG_DEBUG,"pageMsg[0]:%02x,pageMsg[1]:%02x,pageMsg[2]:%02x,pageMsg[3]:%02x,pageMsg[4]:%02x,pageMsg[5]:%02x\n",pageMsg[0],pageMsg[1],pageMsg[2],pageMsg[3],pageMsg[4],pageMsg[5]);
	//logPrint(LOG_DEBUG,"pageMsg[6]:%02x,pageMsg[7]:%02x,pageMsg[8]:%02x,pageMsg[9]:%02x,pageMsg[10]:%02x,pageMsg[11]:%02x , pageMsg[12]:%02x\n",pageMsg[6],pageMsg[7],pageMsg[8],pageMsg[9],pageMsg[10],pageMsg[11] , pageMsg[12]);

	return pageMsg;
}

uint8* getPagingAsnEncodedMsg(lteDlPagingStruct *inRrcPagingBuf)
{
    if(TRUE == exitLteApp)
    {
       return NULL;
    }

	uint8 i = 0 , j = 0 , cnDomain = 1 , m = 0 , k = 0;
	memset(pageMsg , 0 , 24);
	pageMsg[0] = 0x40;
	pageMsg[0] = pageMsg[0] | (((inRrcPagingBuf->uePageCount - 1) & 0x07) >> 1); // No. of UE's last 3 bits
	pageMsg[1] = 0x19;
	if(((inRrcPagingBuf->uePageCount - 1)%2) != 0)
	{
		pageMsg[1] = 0x99;
	}
	if(inRrcPagingBuf->cnDomain == 1)//cs
	{
		cnDomain = 0x09;
	}

	for(i = 0; i<inRrcPagingBuf->uePageCount ; i++)
	{
		k = i * 8;
		if(i>0)
		{
			if((i%2)!=0)
			{
				pageMsg[2+k] = 0x90;
				pageMsg[2+k] = pageMsg[2+k] | (inRrcPagingBuf->imsi[i][0] & 0x0F);
				j = 1;
				m = 1;
			}
			else
			{
				pageMsg[2+k] = pageMsg[2+k] & 0x09;
			}
		}
		for(; j<MAX_IDENTITY_LENGTH_STR_4G/2 ; j++)
		{
			pageMsg[2+j+k] = pageMsg[2+j+k] | ((inRrcPagingBuf->imsi[i][m] & 0x0F) << 4);
			if((m+1) < 16)
			pageMsg[2+j+k] = pageMsg[2+j+k] | (inRrcPagingBuf->imsi[i][m+1] & 0x0F);
			m = m + 2;
		}
		if((m%2) == 0)
		{
			pageMsg[2+j+k] = pageMsg[2+j+k] | cnDomain;
		}
		else
		{
			pageMsg[2+j+k] = ((pageMsg[2+j+k] | cnDomain) << 4);
		}
		m = 0;
		j = 0;
	}
	inRrcPagingBuf->imsiLength = (8 + 68*inRrcPagingBuf->uePageCount)/8 + 1 ;

	//logPrint(LOG_DEBUG,"pageMsg[0]:%02x,pageMsg[1]:%02x,pageMsg[2]:%02x,pageMsg[3]:%02x,pageMsg[4]:%02x,pageMsg[5]:%02x\n",pageMsg[0],pageMsg[1],pageMsg[2],pageMsg[3],pageMsg[4],pageMsg[5]);
	//logPrint(LOG_DEBUG,"pageMsg[6]:%02x,pageMsg[7]:%02x,pageMsg[8]:%02x,pageMsg[9]:%02x,pageMsg[10]:%02x,pageMsg[11]:%02x\n",pageMsg[6],pageMsg[7],pageMsg[8],pageMsg[9],pageMsg[10],pageMsg[11]);

	return pageMsg;
}

void deleteBlackListUserFromLinkedList(listNode *blNode)
{
	pthread_mutex_lock(&mutexLteBlackListQ);
	listNode *current = headForLteBlacklistedUserQ;
	listNode *prev = NULL , *tmpNode = NULL;
	lteblackListedUserInfo *tmp = NULL , *blInfo = NULL;

	if((NULL == blNode) ||(blNode->msg == NULL))
	{	 
		pthread_mutex_unlock(&mutexLteBlackListQ);
		return;
	}

	
	blInfo = (lteblackListedUserInfo*)blNode->msg;

	while(current != NULL)
	{
	   tmp = (lteblackListedUserInfo*)current->msg;
	   if ((tmp != NULL) && (blNode !=NULL))
	   	{	   
		   if(current == blNode)
		   {
			   //Delete this blacklist node from the list
			   if(current == headForLteBlacklistedUserQ) // First node
			   {
				   headForLteBlacklistedUserQ = current->next;
				   if(headForLteBlacklistedUserQ == NULL)
				   {
					   tailForLteBlacklistedUserQ = NULL;
					   timerStop(&pgTimer); // No blacklist users in the list so stop the main timer as well
					   sibModTimerStarted = FALSE;
				   }
			   }
			   else if(current == tailForLteBlacklistedUserQ) //Last node           
			   {               
			   	   tailForLteBlacklistedUserQ = prev;           
			   }           
			   else           
			   {}

			   tmpNode = current;
			   current = current->next;
			   if(prev != NULL)
			   {
				   prev->next = current;
			   }
			   tmp->lteSilentCallStarted = FALSE;
			   timerStop(&tmp->blTimer);			   
			   tmp->ueCheckCntr = 0;
			   tmp->ueCheckFlag = FALSE;
			   tmp->blRemoveFlag = FALSE;
       		   tmp->measurementType = FXL_4G_OWN_CELL_MEASUREMENT;
			   logPrint(LOG_DEBUG , "Blacklist IMSI = %s is deleted \n", tmp->userImsi_str);
			   send4gBlOutOfServiceInd(tmp->userImsi_str);
			   free(tmp);
			   free(tmpNode);		
		   }
		   else
		   {
		   	   if((blInfo!=NULL)&& (blInfo->PF == tmp->PF))//Check if we have any nodes with same PF as deleted node
			   {
				   //If there is , then send PagingReq for that PF
				   buildAndSendSibChangePagingMsg(tmp , FALSE);
			   }

			   prev = current;
			   if(current != NULL)
			   {
				   current = current->next;
			   }
		   }
	   	}
	   else
	   {
		   prev = current;
		   if(current != NULL)
		   {
			   current = current->next;
		   }
	   }
	}
	
	pthread_mutex_unlock(&mutexLteBlackListQ);
}

void deleteBlackListUserFromLinkedListRrcThrd(listNode *blNode)
{
	pthread_mutex_lock(&mutexLteBlackListQ);
	listNode *current = headForLteBlacklistedUserQ;
	listNode *prev = NULL , *tmpNode = NULL;
	lteblackListedUserInfo *tmp = NULL , *blInfo = NULL;

	if((NULL == blNode) ||(blNode->msg == NULL))
	{	 
		pthread_mutex_unlock(&mutexLteBlackListQ);
		return;
	}

	
	blInfo = (lteblackListedUserInfo*)blNode->msg;

	while(current != NULL)
	{
	   tmp = (lteblackListedUserInfo*)current->msg;
	   if ((tmp != NULL) && (blNode !=NULL))
	   	{	   
		   if(current == blNode)
		   {
			   //Delete this blacklist node from the list
			   if(current == headForLteBlacklistedUserQ) // First node
			   {
				   headForLteBlacklistedUserQ = current->next;
				   if(headForLteBlacklistedUserQ == NULL)
				   {
					   tailForLteBlacklistedUserQ = NULL;
					   timerStop(&pgTimer); // No blacklist users in the list so stop the main timer as well
					   sibModTimerStarted = FALSE;
				   }
			   }
			   else if(current == tailForLteBlacklistedUserQ) //Last node           
			   {               
			   	   tailForLteBlacklistedUserQ = prev;           
			   }           
			   else           
			   {}

			   tmpNode = current;
			   current = current->next;
			   if(prev != NULL)
			   {
				   prev->next = current;
			   }
			   tmp->lteSilentCallStarted = FALSE;
			   timerStop(&tmp->blTimer);			   
			   tmp->ueCheckCntr = 0;
			   tmp->ueCheckFlag = FALSE;
			   tmp->blRemoveFlag = FALSE;
       		   tmp->measurementType = FXL_4G_OWN_CELL_MEASUREMENT;
			   logPrint(LOG_DEBUG , "Blacklist IMSI = %s is deleted \n", tmp->userImsi_str);
			   send4gBlOutOfServiceInd(tmp->userImsi_str);
			   free(tmp);
			   free(tmpNode);	
		   }
		   else
		   {
		   	   if((blInfo!=NULL)&& (blInfo->PF == tmp->PF))//Check if we have any nodes with same PF as deleted node
			   {
				   //If there is , then send PagingReq for that PF
				   buildAndSendSibChangePagingMsgRrcThrd(tmp , FALSE);
			   }

			   prev = current;
			   if(current != NULL)
			   {
				   current = current->next;
			   }
		   }
	   	}
	   else
	   {
		   prev = current;
		   if(current != NULL)
		   {
			   current = current->next;
		   }
	   }
	}
	pthread_mutex_unlock(&mutexLteBlackListQ);

}

void sendSignalToSelfToDeleteBLUser(listNode *blNode)
{
    if(TRUE == exitLteApp)
    {
         return;
    }

	lteL2InftMsg_t *rrcMsg = (lteL2InftMsg_t*)getRrcDataBuffer();
    rrcMsg->msgType        = LTE_MSG_RRC_DELETE_BLACKLIST_USER_E;
    rrcMsg->l2Data.size = 0;
    rrcMsg->l2Data.spare = (void*) blNode;
    ltePutMsgInRrcQ((void*)rrcMsg);
    return;

}

void sendSignalToSelfTostartIdentityReqTimer(uint16 crnti)
{
    if(TRUE == exitLteApp)
    {
         return;
    }

	lteL2InftMsg_t *rrcMsg = (lteL2InftMsg_t*)getRrcDataBuffer();
    rrcMsg->msgType        = LTE_MSG_RRC_START_IDENTITY_REQ_TIMER_E;
    rrcMsg->l2Data.size = 0;
    rrcMsg->l2Data.crnti= crnti;
    ltePutMsgInRrcQ((void*)rrcMsg);
    return;

}

void sendSignalToSelfToPageSIBModBLTest(lteblackListedUserInfo *blUser)
{
    if(TRUE == exitLteApp)
    {
         return;
    }

	lteL2InftMsg_t *rrcMsg = (lteL2InftMsg_t*)getRrcDataBuffer();
    rrcMsg->msgType        = LTE_MSG_RRC_BLACKLIST_TEST_PAGE_SIBMOD;
    rrcMsg->l2Data.size = 0;
    rrcMsg->l2Data.spare = (void*) blUser;
    ltePutMsgInRrcQ((void*)rrcMsg);
    return;

}

void sendMsgToMacToRemovePagingReq(lteblackListedUserInfo *blUser)
{
    if(TRUE == exitLteApp)
	{
      	return;
    }

	lteL2InftMsg_t *pRrcMsg;

	pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
	pRrcMsg->msgType = LTE_MSG_PAGING_STOP_REQ_E;
	pRrcMsg->l2Data.PF = blUser->PF;
	pRrcMsg->l2Data.PO = blUser->PO;
	ltePutMsgInRlcQ((void*)pRrcMsg);
	return ;
}

void cleanUpLteBlList()
{
    pthread_mutex_lock(&mutexLteBlackListQ);
	listNode *current = headForLteBlacklistedUserQ , *tmp = NULL;

	while(current != NULL)
	{
		tmp = current;
		if(current != NULL)
		current = current->next;

		free(tmp->msg);
		free(tmp);
	}

	headForLteBlacklistedUserQ = tailForLteBlacklistedUserQ = NULL;
	pthread_mutex_unlock(&mutexLteBlackListQ);
}

listNode* searchBlNodeUsingBlUsrInfo(lteblackListedUserInfo *blackUserDelInfo)
{
        if(TRUE == exitLteApp)
	{
        	 return NULL;
    	}


	pthread_mutex_lock(&mutexLteBlackListQ);
	listNode *current = headForLteBlacklistedUserQ;
	lteblackListedUserInfo *tmp = NULL;
	listNode *tmpNode = NULL;

	while(current != NULL)
	{
	   tmp = (lteblackListedUserInfo*)current->msg;
	   if(memcmp(tmp->userImsi_str , blackUserDelInfo->userImsi_str , MAX_IDENTITY_LENGTH_STR) == 0)
	   {
		   tmpNode = current;
		   break;
	   }
	   current = current->next;
	}
	pthread_mutex_unlock(&mutexLteBlackListQ);
	return tmpNode;
}


void send4gBlOutOfServiceInd(uint8* imsi)
{
    if(TRUE == exitLteApp)
    {
            return;
    }

	fxL4gBlUeOutOfCoverageInd ind ;
	ind.hdr.msgType = FXL_4G_BL_UE_OUT_OF_COVERAGE_IND;
	ind.hdr.rat = FXL_RAT_4G;
	ind.hdr.msgLength = sizeof(fxL4gBlUeOutOfCoverageInd);

	memcpy(ind.imsiStr , imsi , SIZE_OF_IDENTITY_STR);

	writeToExternalSocketInterface((uint8*)&ind , sizeof(fxL4gBlUeOutOfCoverageInd));
}

void lteRrcPhrMeasReportHandler(lteL2IntfData_t *pRlcMsgData)
{
    if(TRUE == exitLteApp)
    {
         return;
    }

	unsigned int ueIndex = pRlcMsgData->crnti - LTE_C_RNTI_START;
	lteUeControlBlock.lteueSpecificData[ueIndex].phr  = ((pRlcMsgData->PO) & 0x00FF);//copying pht
	lteUeControlBlock.lteueSpecificData[ueIndex].ulRssiPerPrb = ((pRlcMsgData->PO >> 8) & 0x00FF) ;//copying ulrssi
    lteUeControlBlock.lteueSpecificData[ueIndex].snr = (pRlcMsgData->snr); //copying SNR
	lteblackListedUserInfo* blackUserInfo = blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi , FALSE);
	if(blackUserInfo != NULL)
	{
		sint32 rssi = 0;
		blackUserInfo->ueCheckFlag = TRUE;
		rssi = ((lteUeControlBlock.lteueSpecificData[ueIndex].ulRssiPerPrb) + (LTE_MAX_PHR - lteUeControlBlock.lteueSpecificData[ueIndex].phr));
		if((rssi > 20)&&(rssi < 150))
		{
			blackUserInfo->ulRssiPhr = (-1*rssi) + LTE_RSSI_POWER_OFFSET;
		}
		//logPrint(LOG_DEBUG,"lteRrcPhrMeasReportHandler PhrMeasReport = %d ,ulRssiPerPrb = %d , PHR = %d\n",blackUserInfo->ulRssiPhr,lteUeControlBlock.lteueSpecificData[ueIndex].ulRssiPerPrb , lteUeControlBlock.lteueSpecificData[ueIndex].phr );
	}
}

#ifdef FXL_BL_UE_POWER_OFF
/*
 *  *############################################################################
 *   * Method Name : delLatchedUe
 *    *
 *     * Description : This procedure deletes single UE from Latched Ue list
 *      *
 *       * Parameters  : None
 *        *
 *         * Returns     : None
 *          *############################################################################
 *           */
void sendBLUePowerOffInd(unsigned int ueIndex)
{
      if(TRUE == exitLteApp)
      {
          return;
      }

      fxLBlUePowerOffInd ltepowerOffInd;
      memset (&ltepowerOffInd, 0 , sizeof (fxLBlUePowerOffInd));
      ltepowerOffInd.hdr.msgLength = sizeof(fxLBlUePowerOffInd);
      ltepowerOffInd.hdr.rat = FXL_RAT_4G;
      ltepowerOffInd.hdr.msgType = FXL_BL_UE_POWER_OFF_IND;
      ltepowerOffInd.detachCause = FXL_POWER_OFF;
      memcpy (ltepowerOffInd.imsiStr, lteUeControlBlock.lteueSpecificData[ueIndex].imsi, MAX_IDENTITY_LENGTH_STR_4G);
      logPrint(LOG_DEBUG , "Send Power off Indication with cause Power off for IMSI = %s\n" ,lteUeControlBlock.lteueSpecificData[ueIndex].imsi);
     
      writeToExternalSocketInterface((uint8*)&ltepowerOffInd , sizeof(fxLBlUePowerOffInd));
}
#endif

void sendBLRlFailureInd(unsigned int ueIndex)
{
      if(TRUE == exitLteApp)
      {
          return;
      }

      fxLBlUePowerOffInd ltepowerOffInd;
      memset (&ltepowerOffInd, 0 , sizeof (fxLBlUePowerOffInd));
      ltepowerOffInd.hdr.msgLength = sizeof(fxLBlUePowerOffInd);
      ltepowerOffInd.hdr.rat = FXL_RAT_4G;
      ltepowerOffInd.hdr.msgType = FXL_BL_UE_POWER_OFF_IND;
      ltepowerOffInd.detachCause = FXL_RL_FAILURE;
      memcpy (ltepowerOffInd.imsiStr, lteUeControlBlock.lteueSpecificData[ueIndex].imsi, MAX_IDENTITY_LENGTH_STR_4G);
      logPrint(LOG_DEBUG , "Send Power off Indication with cause RL Failure for IMSI = %s\n" ,lteUeControlBlock.lteueSpecificData[ueIndex].imsi);

      writeToExternalSocketInterface((uint8*)&ltepowerOffInd , sizeof(fxLBlUePowerOffInd));
}

void triggerRrcReconfigMsgHanlder(uint16 crnti)
{
        if(TRUE == exitLteApp)
        {
                return;
        }

	unsigned int ueIndex = crnti - LTE_C_RNTI_START;
	logPrint(LOG_DEBUG , "triggerRrcReconfigMsgHanlder CRNTI = %d , STATE = %d IMSI = %s\n" , crnti, lteUeControlBlock.lteueSpecificData[ueIndex].ueState , lteUeControlBlock.lteueSpecificData[ueIndex].imsi);
	if(strlen(lteUeControlBlock.lteueSpecificData[ueIndex].imsi) == 0)
	{
		lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_IDT_IMSI;
		buildAndEncodeIdentityMsg(ueIndex);
		if(TRUE == isTimerRunning(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer))
		{
		    timerStop(&lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer);
		}
		timerStart(&(lteUeControlBlock.lteueSpecificData[ueIndex].ueTimer),
					TIMER_FOR_4G_IDENTITY_REQUEST_TIMEOUT,
		           0,
		           handleIdentityReqTimeout,
		           &lteUeControlBlock.lteueSpecificData[ueIndex]);
	}
	else if(UE_WAIT_FOR_RRC_CONN_REQ_CMPLT_RSP != lteUeControlBlock.lteueSpecificData[ueIndex].ueState)
	{
		lteL2InftMsg_t *pRrcMsg = NULL;
		pRrcMsg = (lteL2InftMsg_t *)getRrcDataBuffer();
		logPrint(LOG_DEBUG, "RrcReconfigReqMsgHanlder in UE State = %d , Length = %d \n", lteUeControlBlock.lteueSpecificData[ueIndex].ueState , asn1EncodedRrcReconfigReqLen);
		lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CONN_REQ_CMPLT_RSP ;
		pRrcMsg->msgType = LTE_MSG_RRC_RECONFIG_REQ_E;
		pRrcMsg->l2Data.crnti = ueIndex + LTE_C_RNTI_START;
		pRrcMsg->l2Data.dataBuf[0] = lteUeControlBlock.lteueSpecificData[ueIndex].pdcp_tx_sn++;//Pdcp header

		assert(asn1EncodedRrcReconfigReq != NULL);

		pRrcMsg->l2Data.size = asn1EncodedRrcReconfigReqLen + 5;//1Byte Pdcp Header + 4Byte of MAC;
		memcpy(&pRrcMsg->l2Data.dataBuf[1] , asn1EncodedRrcReconfigReq , asn1EncodedRrcReconfigReqLen);

		ltePutMsgInRlcQ((void*)pRrcMsg);
	}
	return;
}


int getLteUeIndxFromImsi (char *imsi)
{
   if(TRUE == exitLteApp)
   {
       return 0xFFFFFFFF;
   }
   int ueIndx = 0xFFFFFFFF;
   uint8 idx =0;

   for (idx =0; idx < LTE_MAX_USER_SUPPORTED; idx++)
   {
       if(0 == memcmp(imsi, lteUeControlBlock.lteueSpecificData[idx].imsi, MAX_IDENTITY_LENGTH_STR_4G))
       {
           ueIndx = idx;
                   break;
       }
   }

   return ueIndx;
}

void updateAndBuildRrcConRelWithRedirect (int ueIndex,
                                          fxLRedirectionFrom4gType redirectionType,
                                          fxLRedirectionFrom4gInfo redirectionInfo)
{
        if(TRUE == exitLteApp)
        {
                return;
        }

        lteblackListedUserInfo* blackUserInfo =
                                   blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);

    if (NULL != blackUserInfo)
    {
        blackUserInfo->redirectEnabled = TRUE;
        blackUserInfo->lteSilentCallStarted = FALSE;
        lteSilentCallStarted = FALSE;
        lteUeControlBlock.lteueSpecificData[ueIndex].ueState = UE_WAIT_FOR_RRC_CON_REL_REDIRECT;
 
        generateRrcConnectionRelWithRedirectForBlUe(redirectionType, redirectionInfo,
                                                    &blackUserInfo->pRrcConRelWithRedirect,
                                                    &blackUserInfo->rrcConRelWithRedirectLen);
       
    }
}

int getLteBLUeIndxFromImsi (char *imsi)
{
   if(TRUE == exitLteApp)
   {
       return 0xFFFFFFFF;
   }

   int ueIndx = 0xFFFFFFFF;
   uint8 idx =0;
   for (idx =0; idx < LTE_MAX_USER_SUPPORTED; idx++)
   {
       if(0 == memcmp(imsi, lteUeControlBlock.lteueSpecificData[idx].imsi, MAX_IDENTITY_LENGTH_STR_4G))
       {
           ueIndx = idx;
                   break;
       }
   }
   return ueIndx;
}
void updateAndBuildRrcConRel (int ueIndex)
{
        if(TRUE == exitLteApp)
        {
                return;
        }
        lteblackListedUserInfo* blackUserInfo =
                                   blacklistLteUserFindUsingIdentity((uint8*)lteUeControlBlock.lteueSpecificData[ueIndex].imsi, FALSE);
    if (NULL != blackUserInfo)
    {
            logPrint(LOG_DEBUG,"generateRrcConnectionRelmessage for IMSI %s,UeIndex %d\n",lteUeControlBlock.lteueSpecificData[ueIndex].imsi,ueIndex);
            generateRrcConnectionRelmessage();
    }
}

void stopLteScForAllBlUser()
{
    listNode *current = headForLteBlacklistedUserQ;

     while(current != NULL)
     {
          lteblackListedUserInfo* blackUserInfo = (lteblackListedUserInfo*)(current->msg);

          if(blackUserInfo != NULL)
          {
             blackUserInfo->lteSilentCallStarted = FALSE;
             if(isTimerRunning(&blackUserInfo->blTimer) == TRUE)
             {
                  timerStop(&blackUserInfo->blTimer);
                             blackUserInfo->blTimer.parm = NULL;
             }
          }

          current = current->next;
     }

    lteSilentCallStarted = FALSE;
}

uint8 isImsiBelongsToConfiguredPlmn(char *imsi)
{
	int i =0;
	for(i=0; i<lastLteIdCatcherConfigCmd.numOfPlmn;i++)
	{
		if(((imsi[0]- '0') == (char)lastLteIdCatcherConfigCmd.plmn[i].mcc[0]) &&
			((imsi[1]- '0') == (char)lastLteIdCatcherConfigCmd.plmn[i].mcc[1]) &&
			((imsi[2] -'0') == (char)lastLteIdCatcherConfigCmd.plmn[i].mcc[2]) &&
			((imsi[3] -'0') == (char)lastLteIdCatcherConfigCmd.plmn[i].mnc[0]) &&
			((imsi[4]- '0') == (char)lastLteIdCatcherConfigCmd.plmn[i].mnc[1]) )
			{
				if(lastLteIdCatcherConfigCmd.plmn[i].mncLength == 3)
				{
					if((imsi[5]- '0') == (char)lastLteIdCatcherConfigCmd.plmn[i].mnc[2]) 
						return TRUE;
				}				
				else
					return TRUE;			
			}
			
	}

	return FALSE;
}
/*
 *############################################################################
 * Method Name : ltePageAllConfifguredTargetPhone
 *
 * Description    : This procedure send paging with IMSI to the traget phone
 *
 * Parameters    : None
 *
 * Returns         : None
 *############################################################################
 */
void ltePageAllConfifguredTargetPhone()
{
   if((TRUE == exitLteApp) || (lastLteIdCatcherConfigCmd.redirectionType == NO_REDIRECTION))
   {
      return;
   }

   uint16 idx = 0, idx1 = 0;
   uint16 PF = 0, PO = 0;
   uint8 *sharedMemPtr = getAccessToIdList();
   configUeIdList.configId = (IdentityConfigStr *)(sharedMemPtr + CONFIG_DATA_SIZE);

   lteDlPagingStruct *pPageImsi = &gPageImsi;
    
   for(idx = 0; idx < configUeIdList.numbOfIds; idx++)
   {
       if(((configUeIdList.configId + idx)->idType == IMSI) &&
          ((configUeIdList.configId + idx)->listType == BLACKLIST))
       {
           PO = 0;
           PF = 0;
		   if(isImsiBelongsToConfiguredPlmn((configUeIdList.configId + idx)->identity) == FALSE)
		   {
		   	 logPrint(LOG_DEBUG , "IMSI does not match plmn, ignoring %s\n",(configUeIdList.configId + idx)->identity);
			 continue;
		   }
           calculatePOnPFfromIMSI((configUeIdList.configId + idx)->identity, &PO, &PF);
   
           lteL2InftMsg_t *pRrcMsg = (lteL2InftMsg_t *)getRrcPageBuffer(PF); 
           pRrcMsg->msgType = LTE_MSG_PAGING_START_REQ_E;
           pRrcMsg->l2Data.crnti = 0;
           pRrcMsg->l2Data.PF = PF;
           pRrcMsg->l2Data.PO = PO;
   
           memset(pPageImsi, 0 , sizeof(lteDlPagingStruct));
           pPageImsi->uePageCount = 1;    
           pPageImsi->cnDomain = 0;
           pPageImsi->imsiLength = MAX_IDENTITY_LENGTH_STR_4G;
           for(idx1 = 0; idx1 < MAX_IDENTITY_LENGTH_STR_4G; idx1++)
           {
               pPageImsi->imsi[0][idx1] = 
                         (configUeIdList.configId + idx)->identity[idx1] - '0';
           }

           logPrint(LOG_DEBUG, "IMSI Paging for IMSI = %s\n", 
                    (configUeIdList.configId + idx)->identity);
           generateIMSIPagingMsg(pPageImsi);
           assert(asn1EncodedPagingRequest != NULL);
           pRrcMsg->l2Data.size = asn1EncodedPagingRequestLen;
           memcpy(&pRrcMsg->l2Data.dataBuf[0], 
                  asn1EncodedPagingRequest, 
                  asn1EncodedPagingRequestLen);

           ltePutMsgInRlcQ((void*)pRrcMsg);
       }
   }

   releaseAccessToIdList(sharedMemPtr);

   return;
}

/*
 * ############################################################################
 * Method Name : convertImsiToBcd
 * 
 * Description : This function converts the IMSI String to BCD format
 * 
 * Parameters  : IMSI
 * 
 * Returns     : IMSI in BCD
 * ############################################################################
 */
void convertImsiToBcd(uint8 *imsiStr, uint8 *imsi3gpp)
{
   uint8 imsi3gppCount = 2;
   uint8 imsiStrCount = 0;

   imsi3gpp[0] = 0x08; 
   imsi3gpp[1] = ((imsiStr[0] - '0') << 4) | 0x09;

   for(imsiStrCount = 1; imsiStrCount < (MAX_IDENTITY_LENGTH_STR - 1); imsiStrCount++)
   {
      if(0 == (imsiStrCount % 2))
      {
          imsi3gpp[imsi3gppCount] |=  ((imsiStr[imsiStrCount] - '0') << 4);
          imsi3gppCount++;
      }
      else
      {
          imsi3gpp[imsi3gppCount] = imsiStr[imsiStrCount] - '0';
      }
   }

   return;
}

/*
 * ############################################################################
 * Method Name : calculatePOnPFfromIMSI
 * 
 * Description : This function provides the Paging Occasion & Paging Frame from
 *               IMSI & DRX Cycle
 * 
 * Parameters  : IMSI
 * 
 * Returns     : PO & PF
 * ############################################################################
 */
void calculatePOnPFfromIMSI(uint8 *imsiStr, uint16 *PO, uint16 *PF)
{
   if(TRUE == exitLteApp)
   {
       return;
   }

   uint16 ue_id;
   uint16 T = 32;// DRX default cycle as per SIB2 configuration
   uint16 N , Ns;
   uint16 i_s;
   uint8 imsi3gpp[9] = {0x00};

   convertImsiToBcd(imsiStr, imsi3gpp);

   ue_id = imsiMod1024(imsi3gpp);

   //N = min(T, nB) == min(T, T) == 1
   // here nB = oneT as per SIB2 configuration.

   N = T;
   // PF = SFN mod T = (T div N) x (UE_ID mod N)
   // == > PF = SFN mod 64 = (T div T) x (ue_id % N)
   //                       =   ue_id % N

   *PF = (ue_id % N) ; // need to calculate futureSFN based on current SFN 0 to 1023

   //Ns: max(1,nB/T) = max (1, T/T) = 1
   Ns = 1;
   i_s = (ue_id/T)%(Ns);// here math.h is not working , Need to FIX

   if (lteDuplxMode) //TDD PO n PF 
   {
       /* Refer 36.304 : section 7.2
        * TDD:
          Ns PO when i_s=0 PO when i_s=1 PO when i_s=2 PO when i_s=3
          1  0 N/A N/A N/A
          2  0 5 N/A N/A
          4  0 1 5 6 */
       if(Ns == 1)
       {
           if(i_s == 0)
           {
               *PO = 0;
           }
           else
           {
               logPrint(LOG_ERR,"Invalid PO \n");
           }
       }
       else if(Ns == 2)
       {
           if (i_s == 0)
           {
               *PO = 0;
           }
           else if (i_s == 1 )
           {
               *PO = 5;
           }
           else
           {
               logPrint(LOG_ERR,"Invalid PO \n");
           }
       }
       else if(Ns == 4)
       {
           if(i_s == 0)
           {
               *PO = 0;
           }
           else if(i_s == 1)
           {
               *PO = 1;
           }
           else if(i_s == 2)
           {
               *PO = 5;
           }
           else if(i_s == 3)
           {
               *PO = 6;
           }
           else
           {
               logPrint(LOG_ERR,"Invalid PO\n");
           }
       }
   }
   else
   {
       /* Refer 36.304 : section 7.2
        * FDD:
          Ns PO when i_s=0 PO when i_s=1 PO when i_s=2 PO when i_s=3
          1  9 N/A N/A N/A
          2  4 9 N/A N/A
          4  0 4 5 9 */
       if(Ns == 1)
       {
          if(i_s == 0)
          {
             *PO = 9;
          }
          else
          {
             logPrint(LOG_ERR,"Invalid PO \n");
          }
       }
       else if(Ns == 2)
       {
           if(i_s == 0)
           {
              *PO = 4;
           }
           else if(i_s == 1)
           {
              *PO = 9;
           }
           else
           {
              logPrint(LOG_ERR,"Invalid PO \n");
           }
       }
       else if(Ns == 4)
       {
           if(i_s == 0)
           {
              *PO = 0;
           }
           else if(i_s == 1)
           {
              *PO = 4;
           }
           else if(i_s == 2)
           {
              *PO = 5;
           }
           else if(i_s == 3)
           {
              *PO = 9;
           }
           else
           {
              logPrint(LOG_ERR,"Invalid PO\n");
           }
       }
   }
   
   logPrint(LOG_INFO,"calculatePOnPFfromIMSI UE_ID = %d PO = %d , PF = %d \n", 
            ue_id , *PO , *PF);
}


