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
 * File Name   : rrcProto.h
 *
 * Description : This file provides receive functionality of Radio Resource 
 *               Control (RRC) stack for ImsiCatcher application.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 26/09/2014	        Ashutosh Samal              File Creation
 *############################################################################
 */
#ifndef _RRC_PROTO_H_
#define _RRC_PROTO_H_

/*
 * Include Files
 */
#include "rrc.h"
#include "umtsCfg.h"

/*
 * Function Prototypes
 */
extern int rrcHandleRlcDataIndication (RrcDataReq *pRlcDataInd);
extern int rrcHandleULCCCHMessage (RrcDataReq *pRlcDataInd);
extern int rrcHandleULDCCHMessage (RrcDataReq *pRlcDataInd);
extern unsigned int getUeIndexInUeControlBlock (RrcInitialUEIdentity *pInitialUeIdentity);
extern unsigned int addUeInUeControlBlock (RrcInitialUEIdentity *pInitialUeIdentity);
extern void handleRadioLinkSetupRequestTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void handleUeEventInIdleState (unsigned int ueIndex, RrcUeEvent ueEvent);
extern void fillRrcConnectionSetup (unsigned int ueIndex);
extern void buildAndSendRrcConnectionSetup (unsigned int ueIndex, unsigned char isL2ConfigRequired);
extern void handleUeEventInWaitRlSetupRespState (unsigned int ueIndex, RrcUeEvent ueEvent); 
extern void handleUeEvents (unsigned int ueIndex, RrcUeEvent ueEvent);
extern void handleRrcConnectionSetupTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void handleUeEventInWaitRrcConnSetupCompState (unsigned int ueIndex, RrcUeEvent ueEvent);
extern void handleUeEventInWaitIDTState (unsigned int ueIndex, RrcUeEvent ueEvent);
extern void handleRrcConnectionReleaseTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern unsigned char checkImsiReceivedInIdt (unsigned int ueIndex);
extern void buildAndSendRrcConnectionRelease (unsigned int ueIndex, unsigned char laterThanR3);
extern void buildAndSendDirectTransferNasReject (unsigned int ueIndex, unsigned int wlRejectCause, NasMsgType nasMsgType);
extern void handleIdentityRequestTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void buildAndSendDirectTransferIdentityReqIMSI (unsigned int ueIndex);
extern void handleUeEventInWaitIdentityRespState (unsigned int ueIndex, RrcUeEvent ueEvent); 
extern void handleUeEventInWaitRrcConnRelCompState (unsigned int ueIndex, RrcUeEvent   ueEvent);
extern void handleRadioLinkDeleteRequestTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void sendRadioLinkpDeleteReqToL1 (unsigned int ueIndex);
extern void cleanUeContextInUeControlBlock (unsigned int ueIndex);
extern void handleUeEventInWaitRLDeleteRespState (unsigned int ueIndex, RrcUeEvent ueEvent);
extern unsigned int isIMSIBlackListed (unsigned int ueIndex);
extern void buildAndSendDirectTransferIdentityReqIMEI (unsigned int ueIndex);
extern void storeImeiInUeControlBlock (unsigned int ueIndex);
extern void storeImsiInUeControlBlock (unsigned int ueIndex);
extern void checkAndActOnBlackWhiteListIMSI (unsigned int ueIndex);
extern void calculateLastDigitOfImei (unsigned int ueIndex);
extern void handleNasRejectTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void handleNasAcceptTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern unsigned int addIMSIInLatchedUeList (char *pImsi, unsigned int ueIndex);
extern void delLatchedUeList (void);
extern unsigned int isIMSIWhiteListed (unsigned int ueIndex);
extern void buildAndSendRrcMeasurementControl (unsigned int ueIndex);
extern void handleGpsMeasReportTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void buildAndSendRrcPagingType2 (unsigned int ueIndex);
extern void handleUeEventInWaitPagingType2TimeoutState (unsigned int ueIndex,
                                                        RrcUeEvent   ueEvent);
extern void handlePagingType2Timeout (tcbTimer_t *pTimer, void *pUeIndex);

extern void buildAndSendRrcPhyChReconfWithMaxAllowedUeTxPwr (unsigned int ueIndex, int maxUlTxPwr);
extern unsigned int getUeIndexFromImsi (char *pImsiStr);
extern void handleRrcChangeUeUlTxPwr (UeUlTxPwrData *pUeUlTxPwr);
extern void sendChangeUeUlTxPwrRsp (unsigned char success, char *pImsiStr);
extern void handlePhyChReconfTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void handleUeEventInWaitPhyChReconfRspState (unsigned int ueIndex,
                                                    RrcUeEvent   ueEvent);

extern void handleStartGpsTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void handleGpsMeasCntrlReleaseTimeout (tcbTimer_t *pTimer, void *pUeIndex);
extern void buildAndSendRrcMeasurementControlSetup (unsigned int ueIndex);
extern void sendGpsMeasurementFailureInd (unsigned int ueIndex);
extern void sendGpsMeasurementSuccessInd (unsigned int ueIndex);
extern void buildAndSendRrcMeasurementControlRelease (unsigned int ueIndex);
void pageAllConfiguredTargetPhone(void);
unsigned char isImsiMatchesToConfiguredPlmn(char *pImsi);
#endif
