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
* File Name   : dataIndMsgHandler.h
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
#ifndef DATAINDMSGHANDLER_H_
#define DATAINDMSGHANDLER_H_

#include "userManager.h"

typedef enum
{
	STATE_DATAIND_NOT_RECEIVED = 0 ,
	STATE_DATAIND_RECEIVED ,

} stateDataInd;

void * dataIndMsgHandler(void *nothing);
void setNextStateOnReceiptL2Ack(userInfo *info, tOCT_UINT8 sapi);
void userInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
void blacklistUserInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
#ifdef FEA_BL_VAL_CHK_BY_PERIODIC_PAGING
void blacklistUserValidityTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);
#endif
#ifdef FXL_BL_UE_POWER_OFF
void send2gBlUePowerOffInd(blackListedUserInfo *blackUserInfo, fxlBlUeDeatchCause cause);
#endif
void sendBlUserDetachedIndOverSocket(blackListedUserInfo *blackUserInfo);
void cleanPagingQ();
unsigned int  getAllRegisteredUesInGsm(void);
void pushLayer3ReqToTxDataQ(userInfo* info , const tOCT_UINT8 * const stdMsgBuf, tOCT_UINT8 sapi);
#ifdef FEA_2G_INTER_RAT_MEAS
int generateMeasInfoBuffers(blackListedUserInfo* info);
#endif
#ifdef FEA_SILENT_CALL
void discLapdmMsgHandler(tOCT_UINT8* inMsgBuf , userInfo* info, tOCT_UINT8 sapi);
#else
void discLapdmMsgHandler(tOCT_UINT8* inMsgBuf , userInfo* info);
#endif

#endif //DATAINDMSGHANLER_H_
