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
* File Name   : gprs.h
 *
* Description : Function to support STATE and Network TIMERS
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 15/10/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#ifndef GPRS_H_
#define GPRS_H_

#include "l1Constants.h"
#include "l1InterfaceManager.h"
#include "l2Scheduler.h"
#include "lapdm.h"
#include "timerApi.h"
#include "userManager.h"

void gprsInfoTimerCbFunction(tcbTimer_t *tmr , void *infoPtr);

#define SIZE_OF_TLLI 4 // Length of Identity(5) + Type of Identity(F4) + 4 bytes randomly generated

/*Message TYPES*/
#define UL_RLC_DATA_BLOCK		0
#define UL_RLC_MAC_MESSAGE	1

/*Octet Info Uplink*/
#define PAYLOAD_TYPE_OCTET	0 											// Val: ((a[PAYLOAD_TYPE_OCTET ] & 0xC0) >> 6)
#define CV_OCTET 						PAYLOAD_TYPE_OCTET 			// Val: ((a[CV_OCTET ] & 0x3C) >> 2)
#define TFI_OCTET 					PAYLOAD_TYPE_OCTET+1		// Val: ((a[TFI_OCTET ] & 0x3E) >> 1)
#define TI_OCTET 						PAYLOAD_TYPE_OCTET+1		// Val: ((a[TFI_OCTET ] & 0x01))
#define EXT_BIT_OCTET 			PAYLOAD_TYPE_OCTET+2		// Val: ((a[EXT_BIT_OCTET ] & 0x01))
#define LEN_IND_OCTET 			PAYLOAD_TYPE_OCTET+3 		// Val: ((a[LEN_IND_OCTET ] & 0xFC) >> 2)
#define MORE_EXT_OCTET 			PAYLOAD_TYPE_OCTET+3		// Val: ((a[LEN_IND_OCTET ] & 0x01))

#define LLC_HDR_LEN					3
//#define MORE_LLC_OCTET 			LEN_IND_OCTET  					// Val: ((a[LEN_IND_OCTET ] & 0x02) >> 1)
//#define LLC_PDU_OCTET 	//Will be defined by check on TI value and 2nd ExtensionBit Value 
//(TI==1 && MORE_EXT_OCTET ==1) ? LLC_PDU_OCTET  = 8:9
//(TI==1 && EXT_OCTET ==1) ? LLC_PDU_OCTET  = 7:8
//#define PFI_OCTET 				//Will need once PDP_CONTEXT is in scene.

/*Octet Info Downlink*/
#define PAYLOAD_TYPE_OCTET	0 											// Val: ((a[PAYLOAD_TYPE_OCTET ] & 0xC0) >> 6)
#define USF_OCTET         	PAYLOAD_TYPE_OCTET	  	// Val: ((a[PAYLOAD_TYPE_OCTET ] & 0x07)) >> 6)
#define FBI_OCTET         	PAYLOAD_TYPE_OCTET+1	  // Val: (a[FBI_OCTET] & 0x01)
#define BSN_OCTET         	PAYLOAD_TYPE_OCTET+2	  // Val: (a[BSN_OCTET] & 0xFE)

/*Messages*/
#define BASE_MESSAGE_TYPE					200
#define PKT_UPLINK_ACK_NACK				BASE_MESSAGE_TYPE+1
#define PKT_DOWNLINK_ACK_NACK			BASE_MESSAGE_TYPE+2
#define PKT_DOWNLINK_ASSGN 				BASE_MESSAGE_TYPE+3
#define PKT_UPLINK_ASSGN 					BASE_MESSAGE_TYPE+4
#define PKT_DATA_BLOCK   					BASE_MESSAGE_TYPE+5
#define PKT_CONTROL_ACK    				BASE_MESSAGE_TYPE+10

#define GMM_ID_REQ_IMEI						BASE_MESSAGE_TYPE+11
#define GMM_ID_REQ_IMSI						BASE_MESSAGE_TYPE+12
#define GMM_ATTACH_REJECT					BASE_MESSAGE_TYPE+13
#define GMM_RAU_REJECT						BASE_MESSAGE_TYPE+14

/*TIMERS*/
#define TIMER_GPRS_WAITING_FOR_UE_RSP                 5000 //2sec
//#define TIMER_FOR_RECEIVING_ALERT                     10000 //10 sec
//#define TIMER_FOR_MT_ALERT                            15000 // T301 could be upto 18Mins, configured to 15secs





/*
 * GPRS Application States
 */
typedef enum			//START from 100 [Providing Buffer to future GSM states]
{    
    IDLE_STATE                                  = 100,
    GPRS_RACH_RECEIVED                               = 101,
    PDTCH_CHANNEL_ALLOCATED                     = 102,
    WAIT_FOR_PKT																= 103,
    DOWNLINK_ASSGN_SENT													= 104,
    PKT_UPLINK_ACK_NACK_SENT										= 105,
    WAIT_FOR_DWNLNK_ACK													= 106,
    WAIT_FOR_GMM_ID_RSP													= 107,
    WAIT_FOR_GMM_ATTACH_CMP											= 108,
    ATTACH_REQ_RECEIVED                         = 109,
    GPRS_IMEI_RECEIVED                          = 110,
    GPRS_IMSI_RECEIVED                          = 111,
    GPRS_TMSI_REALLOCATION_COMPLETE_RECEIVED    = 112,
    WAIT_FOR_PKT_CNTRL_ACK											= 113,
    GPRS_L3_REJECT_FOR_UE                            = 114, // For Whitelisted UE or Blocking MO calls
    GPRS_PAGING_RESP_RECEIVED                        = 8,
    GPRS_LCS_POS_RECEIVED                            = 9,
    GPRS_CIPHERING_MODE_COMPLETE_RECEIVED            = 10,
    GPRS_DISC_RECEIVED                               = 12,
    GPRS_WAITING_FOR_L2ACK                           = 13,
    GPRS_WAITING_FOR_LCS_POSN_RSP                    = 15,
    GPRS_WAITING_FOR_LAUCM_REJECT_RSP                = 16,
    GPRS_WAITING_FOR_DISC_OR_TMSI_REALLOC_COMPLETE   = 17, //In Paging scenario this state will also act as WAITING_FOR_DISC
    GPRS_WAITING_FOR_CIPHERING_MODE_COMPLETE         = 18,
    GPRS_ATTACH_RECEIVED                             = 45
} gprsL23States_;
typedef int gprsL23States;

typedef struct gprsData
{
	tOCT_UINT8     inUse;
	gprsL23States   userState;
	gprsL23States   userPrevState;
	gprsL23States   userAltState;
	tOCT_UINT32    ulFrameNum;
	tOCT_UINT32    ulAltFrameNum;
	logicalChannelIdentity userLogicalChannel;
	tOCT_UINT8     lapdmParam[3]; // ra , t1,t2,t3 parameters from original rach request.
  tOCT_UINT8     rltCounter;
	tOCT_UINT8     userBlacklisted; // TRUE = Yes , FALSE = No
	tOCT_UINT8     cmServiceReqTypeRcvd; // Type of CM-Service Req
	//tOCT_UINT32    blockedMoCallsCounter;
	//tOCT_UINT8     retransmissionCountForL3Msg; //Retransmission Count
	tcbTimer_t     tmr; // alloc during activate logical channel and free during deactivate channel
	//tOCT_UINT8     pagingReqSentInRegisteredMode;
	tOCT_UINT8     gprsSuspReceived;
	char           userImei_str[MAX_IDENTITY_LENGTH_STR];
	char           userImsi_str[MAX_IDENTITY_LENGTH_STR];
	tOCT_UINT8     userOldTmsi[SIZE_OF_TMSI - 2]; // TMSI Assigned by real network, Storing only TMSI value excluding length and type of identity.
	tOCT_UINT8     userTmsi[SIZE_OF_TMSI]; // Valid for Blacklisted UE's, TMSI assigned by our BTS
	tOCT_UINT8     userImsi[SIZE_OF_IDENTITY];
	tOCT_UINT8		 cv;		//CounterValue
	tOCT_UINT8		 tfi;		//TempFlowId
	tOCT_UINT8		 fbi;		//TempFlowId
	tOCT_UINT8		 bsn;		//TempFlowId
	tOCT_UINT8		 usf;		//TempFlowId
	tOCT_UINT8		 altUsf;		//TempFlowId
	tOCT_UINT8     userTlli[SIZE_OF_TMSI + 2]; 
	tOCT_UINT8     *llcBuf; 
	tOCT_UINT8     bufIndex;
	tOCT_UINT8     ssn;	//Start Sequence Number used in PKT_UPLINK_ACK_NACK
	tOCT_UINT8	   morePdu;	//if MORE_BIT_OFFSET is set/unset
  tOCT_UINT8     tmpLlcBuf[GPRS_MACBLOCK_LEN];    //Temporary, Length TBD yet
	tOCT_INT64		 ack;
}gprsInfo; // TODO align structures for word boundry

void * rlcIndMsgHandler(void *nothing);
void * llcIndMsgHandler(void *nothing);
tOCT_UINT8* encodeRlcMacPdu(gprsInfo *info, tOCT_UINT8 msg);
void decodeRlcMacPdu(tOCT_UINT8* rlcPdu , gprsInfo* info);

#endif
