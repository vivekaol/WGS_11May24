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
* File Name   : lteMacEncDec.h
 *
* Description : Lte Mac Layer Encoder Decoder functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 7/02/2015          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#ifndef LTE_MAC_ENC_DEC_H_
#define LTE_MAC_ENC_DEC_H_

#include "lteL1Defs.h"
#include "lteUserManager.h"

#define LTE_MAC_MAX_MAC_PDU_N_SUBHEADERS               15
#define LTE_MAC_DLSCH_CCCH_LCID                        0x00
#define LTE_MAC_DLSCH_DCCH_LCID_BEGIN                  0x01
#define LTE_MAC_DLSCH_DCCH_LCID_END                    0x0A
#define LTE_MAC_DLSCH_UE_CONTENTION_RESOLUTION_ID_LCID 0x1C
#define LTE_MAC_DLSCH_TA_COMMAND_LCID                  0x1D
#define LTE_MAC_DLSCH_DRX_COMMAND_LCID                 0x1E
#define LTE_MAC_DLSCH_PADDING_LCID                     0x1F
#define LTE_MAC_ULSCH_CCCH_LCID                        0x00
#define LTE_MAC_ULSCH_DCCH_LCID_BEGIN                  0x01
#define LTE_MAC_ULSCH_DCCH_LCID_END                    0x0A
#define LTE_MAC_ULSCH_EXT_POWER_HEADROOM_REPORT_LCID   0x19
#define LTE_MAC_ULSCH_POWER_HEADROOM_REPORT_LCID       0x1A
#define LTE_MAC_ULSCH_C_RNTI_LCID                      0x1B
#define LTE_MAC_ULSCH_TRUNCATED_BSR_LCID               0x1C
#define LTE_MAC_ULSCH_SHORT_BSR_LCID                   0x1D
#define LTE_MAC_ULSCH_LONG_BSR_LCID                    0x1E
#define LTE_MAC_ULSCH_PADDING_LCID                     0x1F
#define LTE_SIZE_OF_CONTENTION_RES_ID				   6
// Enums
typedef enum{
    LTE_MAC_CHAN_TYPE_DLSCH = 0,
    LTE_MAC_CHAN_TYPE_ULSCH
}eLteMacChanType;

typedef enum{
    LTE_MAC_RAR_HEADER_TYPE_BI = 0,
    LTE_MAC_RAR_HEADER_TYPE_RAPID,
}eLteMacRarHdr;

typedef struct{
    uint32 max_buffer_size;
    uint32 min_buffer_size;
    uint8  lcg_id;
}lteMacTruncatedBsrStruct;

typedef lteMacTruncatedBsrStruct lteMacShortBsrStruct;

typedef struct{
    uint8 buffer_size_0;
    uint8 buffer_size_1;
    uint8 buffer_size_2;
    uint8 buffer_size_3;
}lteMacLongBsrStruct;

typedef struct{
    uint16 c_rnti;
}lteMacCrntiStruct;

typedef struct{
    uint8 ph;
}lteMacPowerHeadroomStruct;

typedef struct{

}lteMacExtPowerHeadroomStruct;

typedef struct{
    uint8 id[LTE_SIZE_OF_CONTENTION_RES_ID];
}lteMacUeContResolnIdStruct;

typedef struct{
    uint8 ta;
}lteMacTaCommandStruct;

typedef union{
    lteMacTruncatedBsrStruct               truncated_bsr;
    lteMacShortBsrStruct                   short_bsr;
    lteMacLongBsrStruct                    long_bsr;
    lteMacCrntiStruct                      c_rnti;
    lteMacUeContResolnIdStruct 			   ue_con_res_id;
    lteMacTaCommandStruct                  ta_command;
    lteMacPowerHeadroomStruct              power_headroom;
    lteMacExtPowerHeadroomStruct           ext_power_headroom;
    ltePduMsgStruct                        sdu;
}lteMacSubHdrUnion;

typedef struct{
    lteMacSubHdrUnion payload;
    uint32                             lcid;
    uint32                             eBit;
}lteMacPduSubHdrStruct;

typedef struct{
    lteMacPduSubHdrStruct subheader[LTE_MAC_MAX_MAC_PDU_N_SUBHEADERS];
    eLteMacChanType       chan_type;
    uint32                       N_subheaders;
}lteMacPduStruct;

void buildLteRARPdu(lteUserInfo* userInfo , uint8 *rarPdu , eLteMacRarHdr rarHdrType);
uint8 decodeUlMacPdu(ltePduMsgStruct *msg, lteMacPduStruct *pdu);
uint8 encodeDlMacPdu(lteMacPduStruct *pdu, ltePduMsgStruct *msg);

#endif //LTE_MAC_H_
