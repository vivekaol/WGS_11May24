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
* File Name   : lteUserManager.h
 *
* Description : Function to support add/delete/find user
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 09/02/2015          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#ifndef LTE_USERMANAGER_H_
#define LTE_USERMANAGER_H_

#include "lteL1Defs.h"
#include "timerApi.h"
#if 0
#define MAX_SIZE_RLC_DL_PDU 88
#define LTE_MAX_MAC_PDU_SIZE 96
#endif

#define MAX_SIZE_RLC_DL_PDU 150
#define LTE_MAX_MAC_PDU_SIZE 158
/*
 * LTE Application States
 */
typedef enum
{
    LTE_RACH_RECEIVED = 0,
    RACH_RESPONSE_SENT = 1,
    RRC_CONN_REQ_RECEIVED_CONTENTION_RESOLUTION_SENT = 2,
    RRC_CONN_REESTAB_RECEIVED_CONTENTION_RESOLUTION_SENT = 3,
    RRC_CONN_SETUP_SENT = 4,
    RRC_CONN_REESTAB_REJECT_SENT = 5,
    WAITING_TO_START_CONT_GRANT = 6,
    WAITING_FOR_RRC_CONN_COMPLETE = 7,
    WAITING_FOR_ACK_FOR_RLC_PDU_SENT_ON_DL_DCCH = 8,
    ACK_RECEIVED_FOR_RLC_PDU_SENT_ON_DL_DCCH = 9,
    WAITING_FOR_RLC_ACK_FOR_RRC_CONN_REL = 10,
    ACK_RECEIVED_FOR_RRC_CONN_REL = 11,
    LTE_NULL_STATE = 0xFF
}lteMacLayerStates_;
typedef uint8 lteMacLayerStates;

typedef struct lteUsrData
{
	uint8     inUse;
	uint16    crnti;
	uint16    raRnti;
    uint16    timingAdvance;
    uint8     preamble;
    uint8     rvIndex;
    uint8	  ulMcs;
    uint8     dlMcs;
    uint8     ulModulationType; // 2-qpsk , 4-16qam , 6 = 64qam
    uint8     dlModulationType; // 2-qpsk , 4-16qam , 6 = 64qam
    uint16    ulRiv;
    uint16 	  dlRiv;
    uint32    ulHandle;
    uint8	  rntiType; //   1  =  C-RNTI ,   2 =  RA-RNTI, P-RNTI, or SI-RNTI   3 = SPS-CRNTI
	uint8 	  srConfigIndex;
    uint8     macPduLen;
    uint16    lcid;
	lteMacLayerStates macLayerState;
	uint8 	  srRecoveryCounter;
	uint8	  ndiDl;
	uint8	  ndiUl;
	uint8	  continuousUlGrant;
	uint8     rbStart1;
	uint8     rbStart2;
	uint8	  silentCallStarted;
	uint8     rssiIndex;
	uint16 	  phr_ulRssi; // Power headroom report
	// RLC Parameters
    uint16   rlc_vrr;
    uint16   rlc_vrmr;
    uint16   rlc_vrh;
    uint16   rlc_vta;
    uint16   rlc_vtms;
    uint16   rlc_vts;
    uint8 	 rlcLastSendPduMsgType;
    uint8 	 rlcLastSendPduNoOfBits;
    uint8 	 rlcPollRetxCounter;
	uint8 	 ulSaturationFlag;
    uint8 	 rlcLastSentDlPdu[MAX_SIZE_RLC_DL_PDU]; // Can be Identity_Req , Attach_Req , Tau_Req, RrcConnRel_Req
	tcbTimer_t tmr;
    uint8    macPduBuf[LTE_MAX_MAC_PDU_SIZE];
	uint8    cceIndex[LTE_MAX_SUB_FRAME_NUMBER];
	uint8  	 pucch_k;
	uint8  	 dl_allocation[LTE_MAX_SUB_FRAME_NUMBER];
	uint8  	 ulRssiArr[LTE_MAX_SUB_FRAME_NUMBER];
	uint8 	 pdcchOrderSent;
    sint16   ulSnr; 
	uint8 	 emergencyCallAttempted;
	uint8  measGapStarted;
}lteUserInfo;

void lteUserManagerInit();
lteUserInfo* lteUserAdd();
lteUserInfo* userFindUsingCrnti(uint16 crnti);
void userDeleteUsingCrnti(uint16 crnti, uint8 isiIFromSameThread);
//void populateCceIndex(lteUserInfo *userInfo);
#ifdef LTE_USE_SR
uint8 checkIfSrSubframe(uint16 sfn , uint8 sbfn , uint8 srConfigIdx);
void getLteSrConfigIndex(lteUserInfo *userInfo);
lteUserInfo * getUserContextForSchedulingRequest(uint8 sbfn);
uint8 convertToRealSrConfigIndex(uint8 srConfigIndex);
uint8 convertToRealSrTddConfigIndex(uint8 srConfigIndex);
#endif
void getNoOfUsers(uint8 * noOfActiveContext);
lteUserInfo* getUserContext(uint8 index);
uint16 CalculateTddPucchIndex(lteUserInfo* userInfo , uint16 sfNsf);
void deallocateCceMap(uint8 subfn);
uint8 CalculateLteCceIdx (uint8 searchSpace, uint16 rnti , uint16 sfnSf);
#endif //LTE_USERMANAGER_H_
