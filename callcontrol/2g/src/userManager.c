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
* File Name   : userManager.c
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

#include <malloc.h>
#include <assert.h>
#include <pthread.h>
#include "logManager.h"
#include "userManager.h"
#include "linkedlist.h"
#include "transactionMemoryManager.h"

#ifdef FEA_GPRS
#include "gprs.h"
#endif

#define MAX_NO_USER_CONTEXTS MAX_SUBCHAN_TIMESLOT*MAX_TS
listNode   *headForBlacklistedUserQ = NULL;
listNode   *tailForBlacklistedUserQ = NULL;
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
tcbTimer_t blUsersValidityTmr;
#endif
pthread_mutex_t     mutexUserMgr = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t     mutexBlacklistUserQ = PTHREAD_MUTEX_INITIALIZER;

tOCT_UINT8 si5Buf[GSM_MACBLOCK_LEN - 4] = 
{
    0x49, 0x06, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};

tOCT_UINT8 si6Buf[GSM_MACBLOCK_LEN - 4] = 
{
    0x2D, 0x06, 0x1E, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x27, 0xFF, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B
};

extern gsm_trx * trx_g;
extern GsmLatchedUeDetails     *pGsmLatchedUeDetails;
static userInfo*  gsmUserDb[MAX_TS][MAX_SUBCHAN_TIMESLOT] ;
userInfo userCntxt[MAX_NO_USER_CONTEXTS];
extern tOCT_UINT8 disconnect[GSM_MACBLOCK_LEN];
extern signed int usf[8];
extern tOCT_UINT8 tchSilentCallUnderProgress;
extern tOCT_UINT8 cellBarDuringTchSilentCall;

#ifdef FEA_GPRS
gprsInfo gprsCntxt[MAX_NO_USER_CONTEXTS];
gprsInfo*  gprsUserDb[GPRS_MAX_TS][MAX_SUBCHAN_TIMESLOT] ;
#endif

#ifdef FEA_VOICE_CALL_TO_TARGET
extern callContext targetVoiceCallCntxt;
extern int gResetCallAnyway;
#endif

extern int GsmTrxResetDigitalScaling( void );
extern void pushPagingReqToPageQ(blackListedUserInfo* info);
extern tOCT_UINT16 imsiMod1000Get( tOCT_UINT8* imsi );
extern void pagingBlockCalculate(blackListedUserInfo* info);
extern void sendRegistrationAttemptedIndOverSocket(userInfo *info);
extern void periodicTimerexpiry(tcbTimer_t *tmr , void *infoPtr);
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
extern void blacklistUserValidityTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
#endif
extern void sendBlUserDetachedIndOverSocket(blackListedUserInfo *blackUserInfo);
extern void pushLayer3ReqToTxDataQ(userInfo* info , const tOCT_UINT8 * const stdMsgBuf, tOCT_UINT8 sapi);
#ifdef FXL_BL_UE_POWER_OFF
extern void send2gBlUePowerOffInd(blackListedUserInfo *blackUserInfo, fxlBlUeDeatchCause cause);
#endif
extern tOCT_UINT8* getLaiFromSysInfo();
#ifdef FEA_VOICE_CALL_TO_TARGET
void checkAndResetCallCtx(userInfo *info);
#endif

void userManagerInit()
{
	tOCT_UINT8 i=0 , j = 0;
	for ( i = 0; i < MAX_TS; i++ )
	{
	  for ( j = 0; j < MAX_SUBCHAN_TIMESLOT; j++ )
	  {
		  gsmUserDb[i][j] = NULL;
#ifdef FEA_GPRS
		  gprsUserDb[i][j] = NULL;
#endif
	  }
	}
	memset(userCntxt , 0 , (sizeof(userInfo)*MAX_NO_USER_CONTEXTS));
#ifdef FEA_GPRS
	memset(gprsCntxt , 0 , (sizeof(gprsInfo)*MAX_NO_USER_CONTEXTS));
#endif
	for ( j = 0; j < MAX_NO_USER_CONTEXTS; j++ )
	{
	  timerInit(&userCntxt[j].tmr);
#ifdef FEA_GPRS
	  timerInit(&gprsCntxt[j].tmr);
#endif
	}

	return;
}
void updateUserDb(userInfo *info , logicalChannelIdentity * ch_id )
{
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum >= 0));
	assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum < 0))
	{
		logPrint(LOG_ERR, "updateUserDb: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "updateUserDb: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
	gsmUserDb[ch_id->txSLotNum][ch_id->subChNum] = info;
}

userInfo* userAdd(logicalChannelIdentity * ch_id)
{
	userInfo* info = NULL ;
	tOCT_UINT8 i =0;
	pthread_mutex_lock(&mutexUserMgr);
	for(i = 0; i < MAX_NO_USER_CONTEXTS; i++)
	{
		if(userCntxt[i].inUse == FALSE)
		{
			info = &userCntxt[i];
			info->inUse = TRUE;
			break;
		}
	}
#ifndef NDEBUG
	assert(info != NULL);
#else
	if(info == NULL)
	{
		logPrint(LOG_ERR, "userAdd: info == NULL\n");
		exit(1);
	}
#endif
	updateUserDb(info, ch_id);
	pthread_mutex_unlock(&mutexUserMgr);
	info->userLogicalChannel.txSLotNum = ch_id->txSLotNum;
	info->userLogicalChannel.subChNum = ch_id->subChNum;
	info->userState = RACH_RECEIVED;
    info->rltCounter = trx_g->bts.radio_link_timeout;

	logPrint(LOG_INFO,"User Added to DB %p \n" , info);
	return info;
}

void userDeleteUsingLogicalChannel(logicalChannelIdentity * ch_id)
{
  userInfo * info = NULL;
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum >= 0));
	assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum < 0))
	{
		logPrint(LOG_ERR, "userDeleteUsingLogicalChannel: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "userDeleteUsingLogicalChannel: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
  pthread_mutex_lock(&mutexUserMgr);
  info = gsmUserDb[ch_id->txSLotNum][ch_id->subChNum];
  if(info != NULL)
  {
	  logPrint(LOG_INFO,"User Deleted from DB %p \n" , info);
#ifdef FEA_MT_SMS
      if(info->moSmsL3Pdu != NULL)
      {
          free(info->moSmsL3Pdu);
          info->moSmsL3Pdu = NULL;
      }
#endif
	  memset(info , 0 , sizeof(userInfo));
	  info->inUse = FALSE;
	  gsmUserDb[ch_id->txSLotNum][ch_id->subChNum] = NULL;

      clearUserTransactionMemory(ch_id);
  }
  else
  {
	  logPrint(LOG_ERR , "User does not exist \n");
  }
  pthread_mutex_unlock(&mutexUserMgr);
}

userInfo* userFindUsingLogicalChannel(logicalChannelIdentity * ch_id)
{
	userInfo* info = NULL ;
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum >= 0));
	assert((ch_id->subChNum < MAX_SUBCHAN_TIMESLOT) || (ch_id->subChNum == cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_ALL));
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum < 0))
	{
		logPrint(LOG_ERR, "userFindUsingLogicalChannel: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "userFindUsingLogicalChannel: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
	pthread_mutex_lock(&mutexUserMgr);
	info = gsmUserDb[ch_id->txSLotNum][ch_id->subChNum];
    if(info != NULL && info->inUse == FALSE)
    {
        info = gsmUserDb[ch_id->txSLotNum][ch_id->subChNum] = NULL;
    }
	pthread_mutex_unlock(&mutexUserMgr);
	//logPrint(LOG_DEBUG,"User found in DB %p \n" , info);
	return info;
}

void clearUserContext(userInfo* info, tOCT_UINT8 tchUser, tOCT_UINT8 deleteUser)
{
    logicalChannelIdentity deallocate_channel;
    
    if(info == NULL)
      return;

    if(tchUser)
    {
        deallocate_channel.txSLotNum = info->userTchChannel.txSLotNum;
        deallocate_channel.subChNum  = info->userTchChannel.subChNum;
    }
    else
    {        
        deallocate_channel.txSLotNum = info->userLogicalChannel.txSLotNum;
        deallocate_channel.subChNum  = info->userLogicalChannel.subChNum;
    }

    deactivateLogicalChannel(deallocate_channel.txSLotNum , deallocate_channel.subChNum);

    // Reinitiate any pending transaction if it has ended abnormally.

    blackListedUserInfo* blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
    
    if( blackUserInfo != NULL )
    {
        if(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_REDIRECTION) == SET_TRIGGER_FOR_REDIRECTION) ||
           ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RELEASE) == SET_TRIGGER_FOR_RELEASE))
        {
            blackUserInfo->triggerPagingReq = TRUE;
            pushPagingReqToPageQ(blackUserInfo);
        }
#ifdef FEA_SILENT_CALL
        else if(((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL) ||
                ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL))
        {
            /* Disable DL Mute temporarily if enabled during silent call */
            if(blackUserInfo->muteDlPwrDuringSilentCall == TRUE)
            {
                /* Reset TS Digital Scaling */
                GsmTrxResetDigitalScaling();
            }

            blackUserInfo->triggerPagingReq = TRUE;
            pushPagingReqToPageQ(blackUserInfo);
        }
#endif /* FEA_SILENT_CALL */

#ifdef FEA_MT_SMS
        else if(( info->mtSmsL3Pdu != NULL ) && \
                (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_INDIVIDUAL_SMS) == SET_TRIGGER_FOR_INDIVIDUAL_SMS) || \
                ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_BROADCAST_SMS) == SET_TRIGGER_FOR_BROADCAST_SMS) ) )
		{
   		    blackUserInfo->triggerPagingReq = TRUE;
            pushPagingReqToPageQ(blackUserInfo);
		}
#endif /* FEA_MT_SMS */

#ifdef FEA_ALERT
        else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_ALERTING) == SET_TRIGGER_FOR_ALERTING)
        {
            blackUserInfo->triggerPagingReq = TRUE;
            pushPagingReqToPageQ(blackUserInfo);
        }
#endif /* FEA_ALERT */
        else if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT) == SET_TRIGGER_FOR_RSSI_GPS_IND_ONESHOT)
        {
            blackUserInfo->triggerPagingReq = TRUE;
            pushPagingReqToPageQ(blackUserInfo);
        }
        else
        {}
    }

#ifdef FEA_VOICE_CALL_TO_TARGET
    if(targetVoiceCallCntxt.isOnGoingCall)
    {
        logicalChannelIdentity chId;
        userInfo * activeTchUserInfo;
        tOCT_UINT8 tchActive = FALSE;
        if(targetVoiceCallCntxt.moTsNum == info->userTchChannel.txSLotNum)
        {
            if(targetVoiceCallCntxt.mtTsNum != 0xFF)
            {
                chId.txSLotNum = targetVoiceCallCntxt.mtTsNum;
                chId.subChNum  = targetVoiceCallCntxt.mtSubChan;
                tchActive = TRUE;
            }
            else
            {
                gResetCallAnyway = TRUE;
                checkAndResetCallCtx(info);
            }
        }
        else if(targetVoiceCallCntxt.mtTsNum == info->userTchChannel.txSLotNum)
        {
            if(targetVoiceCallCntxt.moTsNum != 0xFF)
            {
                chId.txSLotNum = targetVoiceCallCntxt.moTsNum;
                chId.subChNum  = targetVoiceCallCntxt.moSubChan;
                tchActive = TRUE;
            }
            else
            {
                gResetCallAnyway = TRUE;
                checkAndResetCallCtx(info);
            }
        }
        else
        {}

        if(tchActive == TRUE)
        {
            activeTchUserInfo = userFindUsingLogicalChannel(&chId);
            if(activeTchUserInfo != NULL)
            {
                tOCT_UINT8 sapi = SAPI_IDLE;
                if(activeTchUserInfo->userTchChannel.txSLotNum)
                {
                    if(isTimeSlotTypeSupportsTCHF(activeTchUserInfo->userTchChannel.txSLotNum))
                      sapi = SAPI_TCHF;
                    else if(isTimeSlotTypeSupportsTCHH(activeTchUserInfo->userTchChannel.txSLotNum))
                      sapi = SAPI_TCHH;
                    else
                    {}
                }

                activeTchUserInfo->userPrevState = activeTchUserInfo->userState;
                activeTchUserInfo->userState = DISC_SENT;
                pushLayer3ReqToTxDataQ(activeTchUserInfo , disconnect, sapi);
                logPrint(LOG_DEBUG,"User = %p : Pushing DISC to TCH User", activeTchUserInfo);
                gResetCallAnyway = TRUE;
                checkAndResetCallCtx(activeTchUserInfo);
            }
        }
    }
#endif /* FEA_VOICE_CALL_TO_TARGET */

    if(deleteUser)
    {
        logPrint(LOG_DEBUG , "User = %p : Deleting User, User State = %s \n" , info, logGetUserStateString(info->userState));
        userDeleteUsingLogicalChannel(&deallocate_channel);
    }

    if(tchUser)
    {
        if(isTimeSlotTypeSupportsTCHF(deallocate_channel.txSLotNum) == TRUE)
        {
            deallocateFullTrafficChannel(&deallocate_channel);
            logPrint(LOG_DEBUG , "All Logical Channels are DEACTIVATED for the TCH/F, FACCH/F and SACCH/F, TimeSlot = %d , SubChannel = %d   \n", deallocate_channel.txSLotNum , deallocate_channel.subChNum);
        }
        else if(isTimeSlotTypeSupportsTCHH(deallocate_channel.txSLotNum) == TRUE)
        {
	        deallocateHalfTrafficChannel(&deallocate_channel);
            logPrint(LOG_DEBUG , "All Logical Channels are DEACTIVATED for the TCH/H, FACCH/H and SACCH/H, TimeSlot = %d , SubChannel = %d   \n", deallocate_channel.txSLotNum , deallocate_channel.subChNum);
        }
        else
        {

        }
    }
    else
    {
        deallocateLogicalChannel(&deallocate_channel);        
        logPrint(LOG_DEBUG , "All Logical Channels are DEACTIVATED for the SDCCH and SACCH , TimeSlot = %d , SubChannel = %d   \n", deallocate_channel.txSLotNum , deallocate_channel.subChNum);
    }    
}

tOCT_UINT8 compareUserIdentity(blackListedUserInfo* info , tOCT_UINT8* identity , tOCT_UINT8 isItBcd, tOCT_UINT8 isItImei)
{
	tOCT_UINT8 ret = FALSE;
	//Check if it is TMSI or IMSI based on format
	if(isItBcd == TRUE)
	{
		if((identity[1] & 0x07) == 0x01)
		{
			 if(memcmp(info->userImsi , identity , SIZE_OF_IDENTITY) == 0) // Imsi
               ret = TRUE;
		}
		else if((identity[1] & 0x07) == 0x04)
		{
			 if(memcmp(info->userTmsi , identity , SIZE_OF_TMSI) == 0) // Tmsi
               ret = TRUE;
		}
		else
		{
			// Identity type is not IMSI/TMSI, of which we have no interest
			logPrint(LOG_DEBUG , "compareUserIdentity: Identity type is not IMSI/TMSI: Identity(%02x %02x %02x %02x %02x %02x)\n", identity[0], identity[1], identity[2], identity[3], identity[4], identity[5] );
		}
	}
	else
	{
		// Identity is in string format
		if(isItImei == TRUE)
        {
		    if(memcmp(info->userImei_str , identity , MAX_IDENTITY_LENGTH_STR) == 0) // Imei_str
			  ret = TRUE;
        }
        else
        {
		    if(memcmp(info->userImsi_str , identity , MAX_IDENTITY_LENGTH_STR) == 0) // Imsi_str
			  ret = TRUE;
        }
	}
	return ret;
}

blackListedUserInfo* blacklistUserFindUsingIdentity(tOCT_UINT8 *identity , tOCT_UINT8 isItBcd, tOCT_UINT8 isItImei)
{
	blackListedUserInfo* info = NULL ;
    
	pthread_mutex_lock(&mutexBlacklistUserQ);
	listNode *current = headForBlacklistedUserQ;    

	if(current == NULL)
	{
		//logPrint(LOG_ERR,"BlackListed User list is empty \n");
	}
	else
	{
		while(current != NULL)
		{
			blackListedUserInfo* tmp = (blackListedUserInfo*)(current->msg);
			if(compareUserIdentity(tmp , identity , isItBcd, isItImei) == TRUE)
			  break;
			else
			  current = current->next;
		}
		if(current != NULL)
		{
			info = (blackListedUserInfo*) (current->msg);
		}
		else
		{
			//logPrint(LOG_ERR,"User NOT found in BlackList \n");
		}
	}    
	pthread_mutex_unlock(&mutexBlacklistUserQ);
	return info;
}


blackListedUserInfo* userStoreBlackListedInfo(userInfo *info)
{
	blackListedUserInfo* blackUserInfo = NULL ;
    int listlength = 0, i = 0;

	pthread_mutex_lock(&mutexBlacklistUserQ);
    listNode *tail = tailForBlacklistedUserQ;
	pthread_mutex_unlock(&mutexBlacklistUserQ);

	blackUserInfo = blacklistUserFindUsingIdentity(info->userImsi , TRUE, FALSE);
   
	if(blackUserInfo == NULL)
	{
	    pthread_mutex_lock(&mutexBlacklistUserQ);
	    listlength = lenghtOfList(headForBlacklistedUserQ);        
        pthread_mutex_unlock(&mutexBlacklistUserQ);
        
		if(listlength == MAX_NO_OF_IDS)
		{
			logPrint(LOG_INFO,"BlackList is FULL NOT ADDING THIS USER\n");
			return NULL;
		}

		blackUserInfo = (blackListedUserInfo*) malloc(sizeof(blackListedUserInfo));
#ifndef NDEBUG
		assert(blackUserInfo != NULL);
#else
		if(blackUserInfo == NULL)
		{
			logPrint(LOG_ERR, "userStoreBlackListedInfo: blackUserInfo == NULL\n");
			exit(1);
		}
#endif

        blackUserInfo->isInConnectedState = TRUE;
		memcpy(blackUserInfo->userImsi , info->userImsi , SIZE_OF_IDENTITY);
		memcpy(blackUserInfo->userTmsi , info->userTmsi , SIZE_OF_TMSI);
		memcpy(blackUserInfo->userOldTmsi , info->userOldTmsi , (SIZE_OF_TMSI - 2));
		memcpy(blackUserInfo->userImsi_str , info->userImsi_str , MAX_IDENTITY_LENGTH_STR);
		memcpy(blackUserInfo->userImei_str , info->userImei_str , MAX_IDENTITY_LENGTH_STR);
        blackUserInfo->userImeiSv = info->userImeiSv;
        blackUserInfo->last_lac   = info->last_lac;

		blackUserInfo->blockedMoCallsCounter = info->blockedMoCallsCounter;
		blackUserInfo->gprsSuspExpectedFromThisUe = info->gprsSuspReceived;

		pagingBlockCalculate(blackUserInfo);

		timerInit(&blackUserInfo->tmr);

		/* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/ 
        if(configUeIdList.defaultConfig == BLACKLIST)
        {		
		    tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
		    if(retVal == RC_TCB_OK)
			  logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started in userStoreBlackListedInfo() ");
		}

	    pthread_mutex_lock(&mutexBlacklistUserQ);
        blackUserInfo->isActive = TRUE;        
        pthread_mutex_unlock(&mutexBlacklistUserQ);

		blackUserInfo->triggerPagingReq = FALSE ;
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
        blackUserInfo->pagingInactivityCounter = 0;        
#endif
        blackUserInfo->bitMaskForTriggers = 0;
#ifdef FEA_MT_SMS
		blackUserInfo->mtSmsL3Pdu = NULL;
#endif

#ifdef FEA_SILENT_CALL
		blackUserInfo->uplinkPowerdBm = 40; // Maximum uplink power is commanded by default		
        blackUserInfo->timeSlotForTchSilentCall = 0xFF;
		blackUserInfo->muteDlPwrDuringSilentCall  = FALSE;
        memcpy(blackUserInfo->si5Buf, si5Buf, GSM_MACBLOCK_LEN - 4);        
        memcpy(blackUserInfo->si6Buf, si6Buf, GSM_MACBLOCK_LEN - 4);
        
        tOCT_UINT16 cellId = htons(trx_g->bts.cell_identity);
        memcpy(&blackUserInfo->si6Buf[3] ,&cellId, sizeof(tOCT_UINT16));

		memcpy(&blackUserInfo->si6Buf[5] , getLaiFromSysInfo() , 5);
        
        blackUserInfo->si5Neighbors.nbr_of_arfcns = 0;
        for(i=0; i<GERAN_ARFCN_LIST_LENGTH; i++)
        {
            blackUserInfo->si5Neighbors.arfcns[i] = END_OF_LIST;
        }

#ifdef FEA_2G_INTER_RAT_MEAS
        memset(&blackUserInfo->measInfo, 0, sizeof(fxL2gInterRatMeasInfo));
        memset(blackUserInfo->gsm3gNeighCellList, 0, (sizeof(gsm3gNeighCell) * FXL_2G_MAX_3G_NEIGHBOR_UARFCNS * FXL_2G_MAX_3G_NEIGH_CELLS_IN_UARFCN));
        for(i = 0; i < MAX_MI_INSTANCES; i++)
        {
            memset(&blackUserInfo->mi_buf[i][0], GSM_MACBLOCK_PADDING, GSM_MACBLOCK_LEN - 2);
        }
        blackUserInfo->noOfValidMIInstances = 0;
#endif
#endif

        pthread_mutex_lock(&mutexBlacklistUserQ);
		pushMsgToList(&tail ,(void*)blackUserInfo);
		if((headForBlacklistedUserQ == NULL)||(tailForBlacklistedUserQ == NULL))
		{
			headForBlacklistedUserQ = tailForBlacklistedUserQ = tail; // Update for the first time

#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
            /* OoS detection based on periodic paging, applied when default ID config is not BL*/ 
            if(configUeIdList.defaultConfig != BLACKLIST)
            {
                timerInit(&blUsersValidityTmr);

                /* Starting periodic timer for paging to check validity of the BL users */
                tOCT_UINT8 retVal = timerStart(&blUsersValidityTmr , PAGING_TIMER_FOR_BL_VALIDITY_CHECK , PAGING_TIMER_FOR_BL_VALIDITY_CHECK , &blacklistUserValidityTimerCbFunction, NULL);
                assert(retVal == RC_TCB_OK);
            }
#endif
        }
		else
		{
			tailForBlacklistedUserQ = tail; // Just update the tail node
		}        
        pthread_mutex_unlock(&mutexBlacklistUserQ);
        logPrint(LOG_INFO , "Blacklist USER(%p) IMSI = %s is added, TMSI Assigned = 0x%02x%02x%02x%02x%02x%02x \n", blackUserInfo, blackUserInfo->userImsi_str, \
                                                                                                                     blackUserInfo->userTmsi[0], blackUserInfo->userTmsi[1], \
                                                                                                                     blackUserInfo->userTmsi[2], blackUserInfo->userTmsi[3], \
                                                                                                                     blackUserInfo->userTmsi[4], blackUserInfo->userTmsi[5]);
	}
	else
	{
        pthread_mutex_lock(&mutexBlacklistUserQ);
	    blackUserInfo->isActive = TRUE;        
        pthread_mutex_unlock(&mutexBlacklistUserQ);

		memcpy(blackUserInfo->userTmsi , info->userTmsi , SIZE_OF_TMSI);//Update only time
		logPrint(LOG_INFO,"Blacklist USER(%p) IMSI = %s is already in the list, Updated TMSI = 0x%02x%02x%02x%02x%02x%02x \n", blackUserInfo, blackUserInfo->userImsi_str, \
                                                                                                                               blackUserInfo->userTmsi[0], blackUserInfo->userTmsi[1], \
                                                                                                                               blackUserInfo->userTmsi[2], blackUserInfo->userTmsi[3], \
                                                                                                                               blackUserInfo->userTmsi[4], blackUserInfo->userTmsi[5]);
        /* OoS detection based on periodic LAU timer, applied only when default ID config is BL*/ 
        if(configUeIdList.defaultConfig == BLACKLIST)
        {		
		    tOCT_UINT8 retVal = timerStart(&blackUserInfo->tmr , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , (PERIODIC_LOCATION_UPDATE_TIMER_EXPIRY * trx_g->bts.t3212) , &periodicTimerexpiry, blackUserInfo);
		    if(retVal == RC_TCB_OK)
			  logPrint(LOG_DEBUG,"PERIODIC LOCATION UPDATE timer started in userStoreBlackListedInfo() already in the list ");
		}
	}
    
	return blackUserInfo;
}


void delete2gBlackListUserFromLinkedList(blackListedUserInfo *blackUserInfo)
{
	pthread_mutex_lock(&mutexBlacklistUserQ);

	listNode *current = headForBlacklistedUserQ;
	listNode *prev = NULL , *tmpNode = NULL;

	while(current != NULL)
	{
	   if(blackUserInfo == (blackListedUserInfo*)current->msg)
	   {
		   if(current == headForBlacklistedUserQ) // First node
		   {
			   headForBlacklistedUserQ = current->next; 
			   if(headForBlacklistedUserQ == NULL)
			   {
				   tailForBlacklistedUserQ = NULL;                   
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
                   timerStop(&blUsersValidityTmr); // No blacklist users in the list so stop the main timer as well
#endif
               }
		   }
           else if(current == tailForBlacklistedUserQ) //Last node
           {
               tailForBlacklistedUserQ = prev;
           }
           else
           {}

		   tmpNode = current;
		   current = current->next;
		   if(prev != NULL)
		   {
			   prev->next = current;
		   }
		   timerStop(&blackUserInfo->tmr);

           if(( blackUserInfo->muteDlPwrDuringSilentCall == TRUE ) && 
             (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL) ||
              ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)))
           {
               /* Reset TS Digital Scaling */
               GsmTrxResetDigitalScaling();
           }

           if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
           {
               tchSilentCallUnderProgress = FALSE;
               cellBarDuringTchSilentCall = FALSE;
           }
           
		   logPrint(LOG_DEBUG , "Blacklist USER(%p) IMSI = %s is deleted \n", blackUserInfo, blackUserInfo->userImsi_str);
		   free(blackUserInfo);
           blackUserInfo = NULL;
		   free(tmpNode);
           tmpNode = NULL;

		   break;
	   }

	   prev = current;
	   current = current->next;
	}
    
	pthread_mutex_unlock(&mutexBlacklistUserQ);
}

void deleteInactiveBlacklistUsers()
{
    pthread_mutex_lock(&mutexBlacklistUserQ);

    listNode *current = headForBlacklistedUserQ;
    listNode *prev = NULL , *tmpNode = NULL;    
	blackListedUserInfo* blackUserInfo = NULL ;

    while(current != NULL)
    {
        blackUserInfo = (blackListedUserInfo*)(current->msg);
        if((blackUserInfo != NULL) && (blackUserInfo->isActive != TRUE))
        {
            if(current == headForBlacklistedUserQ) // First node
            {
                headForBlacklistedUserQ = current->next;
                if(headForBlacklistedUserQ == NULL)
                {
                    tailForBlacklistedUserQ = NULL;
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
                    timerStop(&blUsersValidityTmr); // No blacklist users in the list so stop the main timer as well
#endif
                }
            }
            else if(current == tailForBlacklistedUserQ) //Last node
            {
                tailForBlacklistedUserQ = prev;
            }
            else
            {}

            tmpNode = current;
            current = current->next;
            if(prev != NULL)
            {
                prev->next = current;
            }
            timerStop(&blackUserInfo->tmr);

            // Send BL-Detach Ind to Client
#ifdef FXL_BL_UE_POWER_OFF
            send2gBlUePowerOffInd(blackUserInfo, FXL_UE_OUT_OF_RANGE);
#else                           
            sendBlUserDetachedIndOverSocket(blackUserInfo);
#endif

            if(( blackUserInfo->muteDlPwrDuringSilentCall == TRUE ) && 
              (((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL) ||
               ((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_SDCCH_SILENT_CALL) == SET_TRIGGER_FOR_SDCCH_SILENT_CALL)))
            {
                /* Reset TS Digital Scaling */
                GsmTrxResetDigitalScaling();
            }

			if((blackUserInfo->bitMaskForTriggers & SET_TRIGGER_FOR_TCH_SILENT_CALL) == SET_TRIGGER_FOR_TCH_SILENT_CALL)
			{
				tchSilentCallUnderProgress = FALSE;
                cellBarDuringTchSilentCall = FALSE;
            }

            logPrint(LOG_DEBUG , "Blacklist USER(%p) IMSI = %s is deleted \n", blackUserInfo, blackUserInfo->userImsi_str);
            free(blackUserInfo);
            blackUserInfo = NULL;
            free(tmpNode);
            tmpNode = NULL;

        }

        prev = current;
        if(current != NULL)
          current = current->next;
    }
    
    pthread_mutex_unlock(&mutexBlacklistUserQ);
}


#if 0
void deleteBlacklistUserUsingIdentity(tOCT_UINT8 *identity , tOCT_UINT8 isItBcd)
{
	pthread_mutex_lock(&mutexBlacklistUserQ);
    listNode *current = headForBlacklistedUserQ;    

    listNode *prev = NULL;    
	blackListedUserInfo* blackUserInfo = NULL ;

    if(current == NULL)
    {
        //logPrint(LOG_ERR,"BlackListed User list is empty \n");
    }
    else
    {
        while(current != NULL)
        {
            blackUserInfo = (blackListedUserInfo*)(current->msg);
            if((blackUserInfo != NULL) && (compareUserIdentity(blackUserInfo , identity , isItBcd) == TRUE))
            {
                if(current == headForBlacklistedUserQ) // First node
                {
                    headForBlacklistedUserQ = current->next;

                    if(headForBlacklistedUserQ == NULL)
            		{
            			tailForBlacklistedUserQ = NULL;
            		}
                }
                else
                {
                    if(current == tailForBlacklistedUserQ) //Last node
                    {
                        tailForBlacklistedUserQ = prev;
                    }

                    prev->next = current->next;
                }

                logPrint(LOG_INFO,"Blacklisted User Deleted from the Black User List %p \n" , blackUserInfo);
                timerStop(&blackUserInfo->tmr);                    
        		free(blackUserInfo);
                blackUserInfo = NULL;

        		free(current);
                current = NULL;

                break;
            }
            prev = current;
            current = current->next;
        }
    }

	pthread_mutex_unlock(&mutexBlacklistUserQ);
    return;
}

void displayAllBlacklistUsers()
{
    pthread_mutex_lock(&mutexBlacklistUserQ);
	listNode *current = headForBlacklistedUserQ;    

    listNode *tmp = NULL;
    int i = 1;
	blackListedUserInfo* blackUserInfo = NULL ;
	while(current != NULL)
	{
        tmp = current;
		blackUserInfo = (blackListedUserInfo*)(tmp->msg);
		if(blackUserInfo != NULL)
		{
            logPrint(LOG_DEBUG,"Blacklisted User( %d ) ==> %s( %p ) \n" , i , blackUserInfo->userImsi_str, blackUserInfo);
		}
        
        current = current->next;
        i++;
	}
    
    pthread_mutex_unlock(&mutexBlacklistUserQ);
    return;
}
#endif

void deleteAllBlacklistUsers()
{
	listNode *current = headForBlacklistedUserQ;
	listNode *tmp = NULL;
	blackListedUserInfo* blackUserInfo = NULL ;
	while(current != NULL)
	{
		tmp = current;
		current = current->next;
		blackUserInfo = (blackListedUserInfo*)(tmp->msg);
		if(blackUserInfo != NULL)
		{
			timerStop(&blackUserInfo->tmr);            
			free(blackUserInfo);
		}
		free(tmp);
	}

	headForBlacklistedUserQ = tailForBlacklistedUserQ = NULL;
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
    timerStop(&blUsersValidityTmr);
#endif

	return;
}

void deleteGsmLatchedUsers () 
{
   GsmLatchedUeDetails *pDelUe = pGsmLatchedUeDetails;

   while (NULL != pDelUe)
   {
       pGsmLatchedUeDetails = pGsmLatchedUeDetails->next;
       free (pDelUe);
       pDelUe = pGsmLatchedUeDetails;
   }

   pGsmLatchedUeDetails = NULL;
   pDelUe = NULL;

}

void deleteAllUsers(void)
{
	tOCT_UINT8 i=0 , j = 0;
	userInfo* info = NULL;
	for ( i = 0; i < MAX_TS; i++ )
	{
	  for ( j = 0; j < MAX_SUBCHAN_TIMESLOT; j++ )
	  {
		  info = gsmUserDb[i][j];
		  if(info != NULL)
		  {
			 timerStop(&info->tmr);
			 gsmUserDb[i][j] = NULL;
		  }
	  }
	}
	memset(userCntxt , 0 , sizeof(userInfo)*MAX_NO_USER_CONTEXTS);
}

#ifdef FEA_GPRS

void updateGprsUserDb(gprsInfo *info , logicalChannelIdentity * ch_id )
{
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum > 0));
	assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0))
	{
		logPrint(LOG_ERR, "updateGprsUserDb: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "updateGprsUserDb: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
	gprsUserDb[ch_id->txSLotNum][ch_id->subChNum] = info;
}

gprsInfo* gprsAdd(logicalChannelIdentity * ch_id)
{
	gprsInfo* info = NULL ;
	tOCT_UINT8 i =0;
	pthread_mutex_lock(&mutexUserMgr);
	for(i = 0; i < MAX_NO_USER_CONTEXTS; i++)
	{
		if(gprsCntxt[i].inUse == FALSE)
		{
			info = &gprsCntxt[i];
			info->inUse = TRUE;
			break;
		}
	}
#ifndef NDEBUG
	assert(info != NULL);
#else
	if(info == NULL)
	{
		logPrint(LOG_ERR, "gprsAdd: info == NULL\n");
		exit(1);
	}
#endif
	updateGprsUserDb(info, ch_id);
	pthread_mutex_unlock(&mutexUserMgr);
	info->userLogicalChannel.txSLotNum = ch_id->txSLotNum;
	info->userLogicalChannel.subChNum = ch_id->subChNum;
	info->userState = RACH_RECEIVED;
    info->rltCounter = trx_g->bts.radio_link_timeout;
	info->tfi = ch_id->subChNum;
	info->morePdu = 1;
	info->cv= 0xFF;
	info->bsn = 0x00;
	info->ulFrameNum = 0x00;
	info->ulAltFrameNum = 0x00;
	info->llcBuf = NULL;
	logPrint(LOG_INFO,"GPRSUser Added to DB %p " , info);
	return info;
}


gprsInfo* gprsFindUsingLogicalChannel(logicalChannelIdentity * ch_id, tOCT_UINT8 tfi, tOCT_UINT32 fn) 
{
	gprsInfo* info = NULL ;
	tOCT_UINT8  subChNum = 0;
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum > 0));
	assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0))
	{
		logPrint(LOG_ERR, "userFindUsingLogicalChannel: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "userFindUsingLogicalChannel: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
	pthread_mutex_lock(&mutexUserMgr);

	for(; subChNum<MAX_SUBCHAN_TIMESLOT ; subChNum++)
    {
    	//logPrint(LOG_ERR, "TS %d SC %d",ch_id->txSLotNum,subChNum);
    	info = gprsUserDb[ch_id->txSLotNum][subChNum];
    	if((fn == 0) && (info != NULL) && (info->tfi == tfi))
    	{
    		//ch_id->subChNum = subChNum;
    		break;
    	}
    	else if ((fn !=0) && (info != NULL) && (info->ulAltFrameNum == fn))
    	{
    		//ch_id->subChNum = subChNum;
    		//if(info->ulAltFrameNum == (fn + 13))
    		//{
    			//logPrint(LOG_INFO,"User = %p : Found User",info);
    			break;
    		//}
    	}
    }
    if((info != NULL) && (info->inUse == FALSE)) 
    {
        info = gprsUserDb[ch_id->txSLotNum][ch_id->subChNum] = NULL;
    }
	pthread_mutex_unlock(&mutexUserMgr);
	//logPrint(LOG_DEBUG,"User found in DB %p \n" , info);
	return info;
}

void deleteAllGprsUsers(void)
{
	tOCT_UINT8 i=0 , j = 0;
	gprsInfo* info = NULL;
	for ( i = 0; i < MAX_TS; i++ )
	{
	  for ( j = 0; j < MAX_SUBCHAN_TIMESLOT; j++ )
	  {
		  info = gprsUserDb[i][j];
		  if(info != NULL)
		  {
			 timerStop(&info->tmr);
			 gprsUserDb[i][j] = NULL;
		  }
	  }
	}
	memset(gprsCntxt , 0 , sizeof(gprsInfo)*MAX_NO_USER_CONTEXTS);
}

void userDeleteGprsUsingLogicalChannel(logicalChannelIdentity * ch_id)
{
  gprsInfo * info = NULL;
#ifndef NDEBUG
	assert((ch_id->txSLotNum < MAX_TS)&&(ch_id->txSLotNum > 0));
	assert(ch_id->subChNum < MAX_SUBCHAN_TIMESLOT);
#else
	if((ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0))
	{
		logPrint(LOG_ERR, "gprsDeleteUsingLogicalChannel: (ch_id->txSLotNum >= MAX_TS)&&(ch_id->txSLotNum <= 0)\n");
		exit(1);
	}
	if(ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT)
	{
		logPrint(LOG_ERR, "gprsDeleteUsingLogicalChannel: ch_id->subChNum >= MAX_SUBCHAN_TIMESLOT\n");
		exit(1);
	}
#endif
  pthread_mutex_lock(&mutexUserMgr);
  info = gprsUserDb[ch_id->txSLotNum][ch_id->subChNum];
  if(info != NULL)
  {
	  logPrint(LOG_INFO,"GprsUser Deleted from DB %p" , info);
	  memset(info , 0 , sizeof(gprsInfo));
	  info->inUse = FALSE;
	  gprsUserDb[ch_id->txSLotNum][ch_id->subChNum] = NULL;

      clearUserTransactionMemory(ch_id);
  }
  else
  {
	  logPrint(LOG_ERR , "GprsUser does not exist ");
  }
  pthread_mutex_unlock(&mutexUserMgr);
}

void clearGprsContext(gprsInfo* info)
{
    logicalChannelIdentity deallocate_channel;

    deallocate_channel.txSLotNum = info->userLogicalChannel.txSLotNum ;
    deallocate_channel.subChNum = info->userLogicalChannel.subChNum ;
		
		
		if(usf[info->usf] == 0)
		{
			usf[info->usf] = -1;
			logPrint(LOG_DEBUG,"USF %d reset",deallocate_channel.subChNum);
		}
		if(usf[info->altUsf] == 0)
		{
			usf[info->altUsf] = -1;
			logPrint(LOG_DEBUG,"altUSF %d reset",info->altUsf);
		}
    //deactivateLogicalChannel(deallocate_channel.txSLotNum , deallocate_channel.subChNum);

    //Delete User as well
    logPrint(LOG_DEBUG , "User = %p : Deleting User, User State = %s \n" , info, logGetUserStateString(info->userState));
    userDeleteGprsUsingLogicalChannel(&deallocate_channel);
    deallocatePdtchChannel(&deallocate_channel);
    logPrint(LOG_DEBUG , "Logical Channels are DEALLOCATED for the PDTCH , TimeSlot = %d , SubChannel = %d ", deallocate_channel.txSLotNum , deallocate_channel.subChNum);
}
#endif
