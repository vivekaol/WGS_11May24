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
* File Name   : l1_hostapimsgdef.h
 *
* Description : This file contains all datastructures for Host-L1 Message APIs
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/

#ifndef _L1_HOST_API_MSG_DEF_H_
#define _L1_HOST_API_MSG_DEF_H_

#if 0

#include "l1Constants.h"

#define cSDR_ETH_GSM_PROTOCOL   0xF00D
#define MAX_PAYLOAD_SIZE_FOR_ETHERNET_MSG_BASE_PAYLOAD  488 //488 max size is of HW_INFO_RESP = 253
#define MAX_DATA_REQ_PAYLOAD_SIZE 32
#define MAX_DATA_IND_PAYLOAD_SIZE 32
#define MAX_RACH_IND_PAYLOAD_SIZE 2 // This can be 2
#define MAX_MSG_SIZE sizeof(tL1_API_ETHERNET_MSG_FRAME)//correct
#define MAX_SIZE_ETHERNET_MSG_BASE sizeof(tL1_API_ETHERNET_MSG_BASE)//correct header + payload
#define HEADER_SIZE_ETHERNET_MSG_FRAME (MAX_MSG_SIZE - MAX_SIZE_ETHERNET_MSG_BASE) //correct maxSize - Payload
#define HEADER_SIZE_ETHERNETE_MSG_BASE (MAX_SIZE_ETHERNET_MSG_BASE - MAX_PAYLOAD_SIZE_FOR_ETHERNET_MSG_BASE_PAYLOAD)//correct
#define MAX_DATA_REQ_PAYLOAD_HEADER_SIZE sizeof(tDATA_REQ_L1Msg)//correct header + payload
#define HEADER_SIZE_HOST_L1_DATA_REQ  (MAX_DATA_REQ_PAYLOAD_HEADER_SIZE - MAX_DATA_REQ_PAYLOAD_SIZE)//Correct
#define START_OF_DATA_REQ_PAYLOAD (HEADER_SIZE_ETHERNET_MSG_FRAME + HEADER_SIZE_ETHERNETE_MSG_BASE + HEADER_SIZE_HOST_L1_DATA_REQ) //Correct
#define START_OF_ETHERNET_MSG_BASE_HEADER (HEADER_SIZE_ETHERNET_MSG_FRAME) // Correct
#define START_OF_DATA_REQ_HEADER (HEADER_SIZE_ETHERNET_MSG_FRAME + HEADER_SIZE_ETHERNETE_MSG_BASE )//Correct

// The ethernet frame's message base as defined by the GSM-GPRS Layer 3 API document section 3.2
//
typedef struct
{
    tOCT_UINT8 byMessageType;
    tOCT_UINT8 bySize;
    tOCT_UINT16 usSequenceNumber;
    tOCT_UINT8 abyMessagePayload[MAX_PAYLOAD_SIZE_FOR_ETHERNET_MSG_BASE_PAYLOAD]; // 488
}tL1_API_ETHERNET_MSG_BASE;


// Ethernet Frame
typedef struct
{
    tOCT_UINT8 abyDestMACAddress[6];
    tOCT_UINT8 abySrcMACAddress[6];
    tOCT_UINT16 usEtherType;
    tOCT_UINT16 abyReserved;
    tL1_API_ETHERNET_MSG_BASE abyMessageBase;
    //Frame check sequence would be added by host ethernet
    //tOCT_UINT16 abyFrameCheckSequenceMSB;
    //tOCT_UINT16 abyFrameCheckSequenceLSB;
}tL1_API_ETHERNET_MSG_FRAME;


// Host - to - L1 Messages

// 0x80 PHY TRX Configuration
typedef struct
{
    tOCT_UINT16 TrxCfgMask1;
    tOCT_UINT16 arfcn;
    tOCT_UINT16 bcch_arfcn;
    tOCT_UINT16 TrxCfgMask2;
    tOCT_UINT16 hopping_list_length;
    tOCT_UINT16 hopping_arfcn[64];
}tTRX_CONFIG_L1Msg;


// 0x87 PHY TRX Reset Request
typedef struct{
    tOCT_UINT16 TrxrstMask;
}tTRX_RESET_REQ_L1Msg;


// 0x85 PHY TRX Status Request
typedef struct{
    tOCT_UINT16 TrxStatMask;
}tTRX_STATUS_REQ_L1Msg;


// 0x83 PHY Connect Channel
typedef struct{
    tOCT_UINT16 PhychConMask1;
    tOCT_UINT16 PhychConMask2;
}tPHYS_CONNECT_CHAN_L1Msg;


// 0x84 PHY Disconnect Channel
typedef struct{
    tOCT_UINT16 PhyTsDisConMask;
}tPHYS_DISCONNECT_CHAN_L1Msg;


// 0x86 PHY Timeslot Status Request
typedef struct{
    tOCT_UINT16 PhyTsStatMask;
}tTIMESLOT_STATUS_REQ_L1Msg;


// 0x8B PHY Logical Channel Activate Request
typedef struct{
    tOCT_UINT16 LogChActvtMask1;
    tOCT_UINT16 LogChActvtMask2;
    tOCT_UINT16 LogChActvtMask3;
    tOCT_UINT16 LogChActvtMask4;
    tOCT_UINT16 LogChActvtMask5;
}tLOGICAL_CHAN_ACTIVATE_REQ_L1Msg;


// 0x8C PHY Logical Channel Deactivate Request
typedef struct{
    tOCT_UINT16 LogChDeActvtMask1;
    tOCT_UINT16 LogChDeActvtMask2;
}tLOGICAL_CHAN_DEACTIVATE_REQ_L1Msg;


// 0x82 PHY Data Request
typedef struct{
    tOCT_UINT16 DataReqMask1;
    tOCT_UINT16 DataReqMask2;
    tOCT_UINT16 frNumhigh;
    tOCT_UINT16 frNumLow;
    tOCT_UINT16 dataLength;
    tOCT_UINT8 dataContent[MAX_DATA_REQ_PAYLOAD_SIZE];
}tDATA_REQ_L1Msg;


// 0x81 PHY Empty Frame Request
typedef struct{
    tOCT_UINT16 EmptyReqMask1;
    tOCT_UINT16 EmptyReqMask2;
    tOCT_UINT16 frNumhigh;
    tOCT_UINT16 frNumLow;
}tEMPTY_FRAME_REQ_L1Msg;


// 0x91 PHY Measurement Report Request
typedef struct{
    tOCT_UINT16 MeasureRepMask1;
    tOCT_UINT16 MeasureRepMask2;
    tOCT_UINT16 MeasureRepMask3;
}tMEAS_REPORT_REQ_L1Msg;


// 0x8D PHY Channel Ciphering Request
typedef struct{
    tOCT_UINT16 PhyChCiphMask1;
    tOCT_UINT16 PhyChCiphMask2;
    tOCT_UINT16 cipher_key_1; // MSB
    tOCT_UINT16 cipher_key_2;
    tOCT_UINT16 cipher_key_3;
    tOCT_UINT16 cipher_key_4; // LSB
}tPHYS_CHAN_CIPHERING_REQ_L1Msg;


// L1 - to - Host Messages

// 0x0F PHY Hardware Info Response
typedef struct{
    char szHWInfo[253];
}tL1_HW_INFO_RESPONSE;


// 0x09 Phy Reset Ack
typedef struct{
    tOCT_UINT16 usStatus;
}tL1_RESET_ACKMsg;


// 0x00 PHY TRX Configuration Ack
typedef struct{
    tOCT_UINT16 TrxCfgAckMask;
    tOCT_UINT16 usStatus;
}tL1_TRX_CONFIG_ACKMsg;


// 0x08 PHY TRX Reset Ack
typedef struct{
    tOCT_UINT16 TrxRstAckMask;
    tOCT_UINT16 usStatus;
}tL1_TRX_RESET_ACKMsg;


// 0x05 PHY TRX Status Response
typedef struct{
    tOCT_UINT16 TsStatMask;
}tTimeSlotStatus;

typedef struct{
    tOCT_UINT16 TrxStatRespMask1;
    tTimeSlotStatus tsStatus[NSLOTS_IN_FRAME];
}tL1_TRX_STATUS_RESPONSEMsg;


// 0x03 PHY Channel Connect Ack
typedef struct{
    tOCT_UINT16 PhychConAckMask;
    tOCT_UINT16 usStatus;
}tL1_PHYS_CHAN_CONNECT_ACKMsg;


// 0x04 PHY Channel Disconnect Ack
typedef struct{
    tOCT_UINT16 PhychDisConAckMask;
    tOCT_UINT16 usStatus;
}tL1_PHYS_CHAN_DISCONNECT_ACKMsg;


// 0x06 PHY Timeslot Status Response
typedef struct{
    tOCT_UINT16 ulSapiMapMsb;
    tOCT_UINT16 ulSapiMapLsb;
    tOCT_UINT16 dlSapiMapMsb;
    tOCT_UINT16 dlSapiMapLsb;
}tSubChStatus;

typedef struct{
    tOCT_UINT16 TsStatRespMask1;
    tOCT_UINT16 TsStatRespMask2;
    tTimeSlotStatus tsStatus;
    tSubChStatus subChStatus[MAX_SUBCHAN_TIMESLOT];
}tL1_TIMESLOT_STATUS_RESPONSEMsg;


// 0x0B PHY Logical Channel Activate Ack
typedef struct{
    tOCT_UINT16 LogChanActAckMask1;
    tOCT_UINT16 LogChanActAckMask2;
    tOCT_UINT16 usStatus;
}tL1_LOGICAL_CHAN_ACTIVATE_ACKMsg;


// 0x0c PHY Logical Channel Deactivate Ack
typedef struct{
    tOCT_UINT16 LogChanDeActAckMask1;
    tOCT_UINT16 LogChanDeActAckMask2;
    tOCT_UINT16 usStatus;
}tL1_LOGICAL_CHAN_DEACTIVATE_ACKMsg;


// 0x0E PHY Time Indication
typedef struct{
    tOCT_UINT16 TimeIndMask;
    tOCT_UINT16 frNumMSB;
    tOCT_UINT16 frNumLSB;
}tL1_TIME_INDMsg;


// 0x02 PHY Ready to Send Indication
typedef struct{
    tOCT_UINT16 RtsMask1;
    tOCT_UINT16 RtsMask2;
    tOCT_UINT16 frNumMSB;
    tOCT_UINT16 frNumLSB;
}tL1_RDY_TO_SEND_INDMsg;


// 0x01 PHY Data Indication
typedef struct{
    sint16 rssi;
    sint16 snr;
    sint16 burst_timing;
    tOCT_UINT16 ber_errcnt;
    tOCT_UINT16 ber_bitcnt;
}tMeasInfo;

typedef struct{
    tOCT_UINT16 DataIndMask1;
    tOCT_UINT16 DataIndMask2;
    tOCT_UINT16 frNumMSB;
    tOCT_UINT16 frNumLSB;
    tMeasInfo meas_report;
    tOCT_UINT16 data_length;
    tOCT_UINT8 dataContent[MAX_DATA_IND_PAYLOAD_SIZE]; //512
}tL1_DATA_INDMsg;


// 0x07 PHY RACH Indication
typedef struct{
    tOCT_UINT16 RachIndMask1;
    tOCT_UINT16 RachIndMask2;
    tOCT_UINT16 frNumMSB;
    tOCT_UINT16 frNumLSB;
    tMeasInfo meas_report;
    tOCT_UINT16 data_length;
    tOCT_UINT8 dataContent[MAX_RACH_IND_PAYLOAD_SIZE]; //512
}tL1_RACH_INDMsg;


// 0x0A PHY Measurement Report
typedef struct{
    tOCT_UINT16 MeasRepMask1;
    tOCT_UINT16 MeasRepMask2;
    tMeasInfo meas_report;
}tL1_MEAS_REPORTMsg;


// 0x0D PHY Channel Ciphering Ack
typedef struct{
    tOCT_UINT16 ChanCipherAckMask1;
    tOCT_UINT16 ChanCipherAckMask2;
    tOCT_UINT16 usStatus;
}tL1_PHYS_CHAN_CIPHERING_ACKMsg;

#endif /* #if 0 */

#endif // _L1_HOST_API_MSG_DEF_H_
