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
* File Name   : lteRrcIntfcHandler.c
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

#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <assert.h>
#include "lteMacIntfcHandler.h"
#include "logManager.h"
#include "linkedlist.h"
#include "lteRrcIntfcHandler.h"
#include "lteL2Interface.h"
#include "lteRrcMain.h"

queue lteL3DataQ ;
stateRxInd lteRrcIndRcvdstate = STATE_RXIND_NOT_RECEIVED;
pthread_cond_t      condlteRrcInd  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t     mutexlteRrcInd = PTHREAD_MUTEX_INITIALIZER;
extern tcbTimer_t pgTimer;
extern int exitLteRrcThread;
extern uint8 lteSilentCallStarted;
void lteRrcMsgHandler();

/*
 *############################################################################
 * Method Name : lteRrcIndMsgHandler
 *
 * Description : Checks lteL3DataQ Message QueQue for incoming Messages to RRC
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void *lteRrcIndMsgHandler(void *nothing)
{

	int ret = 0 , dataAvailable = FALSE;
	stick_this_thread_to_core(3);
    initQueue(&lteL3DataQ); // Init before thread initializes
    InitializeLteRrcContext();
	logPrint(LOG_DEBUG , "lteRrcIndMsgHandler Thread Initialized\n");
	while(TRUE)
	{
		pthread_mutex_lock(&mutexlteRrcInd);

		while (lteRrcIndRcvdstate != STATE_RXIND_RECEIVED)
		pthread_cond_wait(&condlteRrcInd, &mutexlteRrcInd);

        if(exitLteRrcThread)
        {
            lteRrcIndRcvdstate = STATE_RXIND_NOT_RECEIVED;
			dataAvailable = FALSE;
			pthread_mutex_unlock(&mutexlteRrcInd);
            pthread_exit(NULL);
        }
		
		dataAvailable = TRUE;
		lteRrcIndRcvdstate = STATE_RXIND_NOT_RECEIVED ;
		pthread_mutex_unlock(&mutexlteRrcInd);

		if(dataAvailable == TRUE)
		{
			lteRrcMsgHandler();
			dataAvailable = FALSE;
		}
	}
	return (void*)ret;
}

/*
 *############################################################################
 * Method Name : lteRrcMsgHandler
 *
 * Description : Handles the incoming Messages to lteL3DataQ Message QueQue
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void lteRrcMsgHandler()
{
	lteL2InftMsg_t *pRrcMsg = NULL;
	pRrcMsg = (lteL2InftMsg_t*)deQueue(&lteL3DataQ);
	do
	{
		if(pRrcMsg != NULL)
		{
			if(pRrcMsg->msgType != LTE_MSG_UPDATE_PHR_RSSI_IN_SILENT_CALL_E)
			logPrint(LOG_DEBUG , "lteRrcMsgHandler MsgType = %d , CRNTI = %d\n" , pRrcMsg->msgType , pRrcMsg->l2Data.crnti);
			switch(pRrcMsg->msgType)
			{
				case LTE_MSG_RRC_UL_DATA_IND_E :
					{
						lteUlDcchHandler(&(pRrcMsg->l2Data));
					}
					break;

				case LTE_MSG_RRC_RESTART_SIB_CHANGE_PAGING_TIMER_E :
					{
						if((lteSilentCallStarted == FALSE)&&(isTimerRunning(&pgTimer) == FALSE))
						{
						    if(TRUE == isTimerRunning(&pgTimer))
						    {
						        timerStop(&pgTimer);
						    }
							
							timerStart(&pgTimer,
									   LTE_RRC_PAGING_TIMEOUT,
									   0,
									   handleRrcPagingTimeout,
									   NULL);
						}
					}
					break;

				case LTE_MSG_L2_ACK_FOR_UPLINK_MSG_E :
					{
						lteDlDcchHandler(&(pRrcMsg->l2Data));
					}
					break;

				case LTE_MSG_RLC_RESET_REQ_E :
				case LTE_MSG_MAC_RESET_REQ_E :
					{
						lteStopRrcTimer(pRrcMsg->l2Data.crnti);
						lteRlcResetHandler(pRrcMsg->l2Data.crnti);
					}
					break;

				case LTE_MSG_RELEASE_UE_TO_NETWORK_REQ_E :
					{
						lteStopRrcTimer(pRrcMsg->l2Data.crnti);
						lteRrcReleaseUeToNwHandler(pRrcMsg->l2Data.crnti);
					}
					break;
					
				case LTE_MSG_RRC_START_IDENTITY_REQ_TIMER_E :
					{
						lteStartRrcIdentityReqTimer(pRrcMsg->l2Data.crnti);
					}
					break;
					
				case LTE_MSG_RRC_DELETE_BLACKLIST_USER_E :
					{
						deleteBlackListUserFromLinkedListRrcThrd((listNode*)(pRrcMsg->l2Data.spare));
					}
					break;

				case LTE_MSG_RRC_BLACKLIST_TEST_PAGE_SIBMOD :
					{
						sendLteBlTestSibModificationPage((lteblackListedUserInfo *)(pRrcMsg->l2Data.spare));
					}
				break;

				case LTE_MSG_UPDATE_PHR_RSSI_IN_SILENT_CALL_E:
					{
						lteRrcPhrMeasReportHandler(&(pRrcMsg->l2Data));
					}
				break;

				case LTE_MSG_TRIGGER_RRC_RECONFIG_REQ_E:
					{
						lteStopRrcTimer(pRrcMsg->l2Data.crnti);
						triggerRrcReconfigMsgHanlder(pRrcMsg->l2Data.crnti);
					}
				break;

				default:
					break;
				}
		}
		pRrcMsg = (lteL2InftMsg_t*)deQueue(&lteL3DataQ);
	}while(pRrcMsg != NULL);

	return;
}

/*
 *############################################################################
 * Method Name : ltePutMsgInRrcQ
 *
 * Description : Send the RLC PDU to RRC in lteL3DataQ Message QueQue
 *
 * Parameters	: None
 *
 * Returns 	: None
 *############################################################################
 */
void ltePutMsgInRrcQ(void* rlcMsg)
{
	pthread_mutex_lock(&mutexlteRrcInd);
	{
		enQueue(&lteL3DataQ , (void *)rlcMsg);
		lteRrcIndRcvdstate = STATE_RXIND_RECEIVED;
	}
	pthread_mutex_unlock(&mutexlteRrcInd);
	pthread_cond_signal(&condlteRrcInd);

	return;
}

