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
* File Name   : lteMacIntfcHandler.h
 *
* Description : Lte Mac Interface Layer functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 7/02/2015          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#ifndef LTE_INTERFACE_MAC_H_
#define LTE_INTERFACE_MAC_H_

#include "lteL1Defs.h"
#include "lteUserManager.h"
#include "oct_ltefapimacphyinterface.h"
#include "lteL2Interface.h"

#define TIMER_FOR_LTE_RACH_HANDLING 100
#define TIMER_FOR_WAITING_FOR_HARQ 200
#define TIMER_FOR_WAIT_RRC_CONN_SETUP 300
#define TIMER_FOR_RLC_POLL_RETRANSMIT 1200 //3100 //inRrrConnectionSetup->rlcAmPollRetxTimer = LTE_RLCAM_POLL_RETX_TIMER_ms500;
#define RLC_MAX_RETRANSMISSION_THRESHOLD 3 //inRrrConnectionSetup->rlcAmMaxRetxThreshold = LTE_RLC_RETX_THRESHOLD_4;
#define TIMER_FOR_WAIT_RRC_CONN_SETUP_COMPLETE 3000 //15000
#define TIMER_FOR_SENDING_PDCCH_ORDER 10200
#define TIMER_FOR_STARTING_CONT_GRANT 330 //1000

typedef enum
{
	STATE_RXIND_NOT_RECEIVED = 0 ,
	STATE_RXIND_RECEIVED ,

} stateRxInd;

#define LTE_RAR_PDU_LENGTH 7
#define LTE_PUCCH_INDEX_FOR_UCI_SR 0
#define LTE_MAX_NO_UL_PDU_PER_TTI 4
//Uplink Grants
#define LTE_MAC_UL_GRANT_INSIDE_RAR_MCS 5 //TB size = 144 = 2PRB
#define LTE_MAC_UL_GRANT_SIZE_FOR_RRC_CONN_REQ 144/8 //18
#define LTE_MAC_UL_GRANT_FOR_RRC_CONN_COMPLETE_MCS 9 //TbSize = 1544
#define LTE_MAC_UL_GRANT_SIZE_FOR_RRC_CONN_SETUP_COMPLETE 1544/8
#define LTE_MAC_UL_GRANT_FOR_RRC_NAS_MSG_MCS 9 //TbSize = 776 PRB = 3
#define LTE_MAC_UL_GRANT_SIZE_FOR_RRC_NAS_MSG 776/8
#define LTE_MAC_UL_GRANT_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS 3 //TbSize = 104
#define LTE_MAC_UL_GRANT_SIZE_FOR_RLC_ACK_FOR_CONN_REL_MSG 104/8
#define LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_MCS 9 //TbSize = 1544
#define LTE_MAC_UL_GRANT_FOR_SLIENT_CALL_NAS_MSG_SIZE 1544/8


#define LTE_MAC_UL_GRANT_BW_143_INSIDE_RAR_MCS 5 //TB size = 144 = 2PRB
#define LTE_MAC_UL_GRANT_BW_143_FOR_RRC_CONN_COMPLETE_MCS 14 //9 //TbSize = 936
#define LTE_MAC_UL_GRANT_BW_143_FOR_RRC_NAS_MSG_MCS 11 //TbSize = 256
#define LTE_MAC_UL_GRANT_BW_143_FOR_RLC_ACK_FOR_CONN_REL_MSG_MCS 3 //TbSize = 104
#define LTE_MAC_UL_GRANT_BW_143_FOR_SLIENT_CALL_MCS 14 //TbSize = 1544

//Downlink Grants
#define LTE_MAC_RAR_CARRYING_DL_MCS 1 //= 56 bits , PRB = 2
#define LTE_MAC_CONTENTION_RESOLUTION_CARRYING_DL_MCS 1 // = 56 bits , PRB = 2
#define LTE_MAC_RRC_CONN_SETUP_CARRYING_DL_MCS 4 //= 256 bits , PRB = 4
#define LTE_MAC_RLC_ACK_CARRYING_DL_MCS 1
#define LTE_MAC_NAS_REQ_CARRYING_DL_MCS 5
#define LTE_MAC_RRC_CONN_REL_CARRYING_DL_MCS 4
#define LTE_MAC_RRC_MEAS_REQ_CARRYING_DL_MCS 9
#define LTE_MAC_RRC_RECONFIG_REQ_CARRYING_DL_MCS 8

#define LTE_MAC_RRC_CONN_SETUP_PDU_SIZE 256/8
#define LTE_MAC_RLC_ACK_PDU_SIZE 56/8
#define LTE_MAC_NAS_REQ_PDU_SIZE 144/8
#define LTE_MAC_RRC_CONN_REL_PDU_SIZE 120/8
#define LTE_MAC_RRC_MEAS_REQ_PDU_SIZE 296/8
#define LTE_MAC_RRC_RECONFIG_REQ_PDU_SIZE 256/8

#define LTE_MAC_BW_143_RAR_CARRYING_DL_MCS 1
#define LTE_MAC_BW_143_CONTENTION_RESOLUTION_CARRYING_DL_MCS 1
#define LTE_MAC_BW_143_RRC_CONN_SETUP_CARRYING_DL_MCS 8 //= 256 bits , PRB = 2
#define LTE_MAC_BW_143_RLC_ACK_CARRYING_DL_MCS 1
#define LTE_MAC_BW_143_NAS_REQ_CARRYING_DL_MCS 5
#define LTE_MAC_BW_143_RRC_CONN_REL_CARRYING_DL_MCS 4
#define LTE_MAC_BW_143_RRC_MEAS_REQ_CARRYING_DL_MCS 8 // PRB = 2
#define LTE_MAC_BW_143_RRC_RECONFIG_REQ_CARRYING_DL_MCS 8 // PRB = 2


//Paging Grants
#define LTE_MAC_PAGING_REQ_CARRYING_DL_MCS 3 //= 104 bits
#define LTE_MAC_PAGING_REQ_PDU_SIZE 104/8
#define LTE_MAC_4_PAGING_REQ_CARRYING_DL_MCS 9 //= 296 bits
#define LTE_MAC_4_PAGING_REQ_PDU_SIZE 296/8
#define LTE_MAC_8_PAGING_REQ_CARRYING_DL_MCS 15 //= 600 bits
#define LTE_MAC_8_PAGING_REQ_PDU_SIZE 600/8

#define LTE_MAC_BW_143_PAGING_REQ_CARRYING_DL_MCS 7 //= 104 bits
#define LTE_MAC_BW_143_PAGING_REQ_PDU_SIZE 104/8



void * rxIndMsgHandler(void *nothing);
void prepareUlMessageAfterSendingDlTxReq(lteUserInfo* userInfo , uint16 sfNsf);
uint8* buildLteUlConfigReq(lteUserInfo* userInfo , uint16 sfNsf , eFAPI_UL_CONFIG_PDU_INFO pduType);
void pushMacPduToDlSchedulerQ(uint8 subframeNo , uint8 *msg);
void pushMacPduToUlSchedulerQ(uint8 subframeNo , uint8 *msg);
void prepareUlConfigReqForNplus1Subframes(uint16 sfn , uint8 sbfn);
void resentDlMacPduOnHarqNackDtx(lteUserInfo* userInfo , uint16 sfNsf);
void ltePutMsgInRlcQ(void* rrcMsg);
void buildAndSendRlcMsgToRrc(lteUserInfo *userInfo , lteMsgType_e msgType);
void buildAndScheduleDlDchRlcPdu(ltePduMsgStruct* pdu , lteUserInfo* userInfo , lteMsgType_e msgType);
void pushToTxDataReqQ(uint16 sfNsf , uint8*txData);
void pushToDlConfigReqQ(uint16 sfNsf , uint8*dlConfig);
uint8* popFromDlConfigReqQ(uint16 sfNsf);
uint8* popFromTxDataReqQ(uint16 sfNsf);
uint32 getCurrentRiv(uint32 riv ,uint8 *startRb);
void ulRachIndHandler(tOCT_FAPI_L1_API_MSG * lteFapiMsg);
void checkAndCorrectNextTddUlDlSubframe(uint16 *sfNsf, uint8 offset , uint8 isDLSubframe);
void lteTDDcheckforULDlsubframe( uint16 *sfNsf , uint8 isDLSubframe);
#ifdef LTE_USE_SR
void checkAndConfigureTddSchedulingRequest(uint16 sfNsf);
#endif
void checkAndPushTDDPagingReqToDlSchedulerQ(uint16 sfn , uint8 sbfn);
void buildAndSendUlTddDci0ReqForContinuesGrant(uint16 sfNsf , uint8 *msgHiPdu);
#endif /* LTE_INTERFACE_MAC_H_ */
