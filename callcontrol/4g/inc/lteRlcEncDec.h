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
* File Name   : lteRlcEncDec.h
 *
* Description : Lte Rlc Layer Encoder Decoder  functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 17/04/2015          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#ifndef LTE_RLC_ENC_DEC_H_
#define LTE_RLC_ENC_DEC_H_

#include "lteL1Defs.h"
#include "lteUserManager.h"

#define LTE_RLC_AM_WINDOW_SIZE 8
#define LTE_RLC_CPT_FIELD_STATUS_PDU 0
#define LTE_RLC_AMD_MAX_PDU 8

typedef enum{
    LTE_RLC_E_FIELD_HEADER_NOT_EXTENDED = 0,
    LTE_RLC_E_FIELD_HEADER_EXTENDED,
    LTE_RLC_E_FIELD_N_ITEMS,
}eLteRlcExtensionField;

typedef enum{
    LTE_RLC_FI_FIELD_FULL_SDU = 0,
    LTE_RLC_FI_FIELD_FIRST_SDU_SEGMENT,
    LTE_RLC_FI_FIELD_LAST_SDU_SEGMENT,
    LTE_RLC_FI_FIELD_MIDDLE_SDU_SEGMENT,
    LTE_RLC_FI_FIELD_N_ITEMS,
}eLteRlcFiField;

typedef enum{
    LTE_RLC_LSF_FIELD_NOT_LAST_SEGMENT = 0,
    LTE_RLC_LSF_FIELD_LAST_SEGMENT,
    LTE_RLC_LSF_FIELD_N_ITEMS,
}eLteRlcLsfFiled;

typedef enum{
    LTE_RLC_DC_FIELD_CONTROL_PDU = 0,
    LTE_RLC_DC_FIELD_DATA_PDU,
    LTE_RLC_DC_FIELD_N_ITEMS,
}eLteRlcDcField;

typedef enum{
    LTE_RLC_RF_FIELD_AMD_PDU = 0,
    LTE_RLC_RF_FIELD_AMD_PDU_SEGMENT,
    LTE_RLC_RF_FIELD_N_ITEMS,
}eLteRlcRfField;

typedef enum{
    LTE_RLC_P_FIELD_STATUS_REPORT_NOT_REQUESTED = 0,
    LTE_RLC_P_FIELD_STATUS_REPORT_REQUESTED,
    LTE_RLC_P_FIELD_N_ITEMS,
}eLteRlcPField;

typedef enum{
    LTE_RLC_E1_FIELD_NOT_EXTENDED = 0,
    LTE_RLC_E1_FIELD_EXTENDED,
    LTE_RLC_E1_FIELD_N_ITEMS,
}eLteRlcE1Field;

typedef enum{
    LTE_RLC_E2_FIELD_NOT_EXTENDED = 0,
    LTE_RLC_E2_FIELD_EXTENDED,
    LTE_RLC_E2_FIELD_N_ITEMS,
}eLteRlcE2Field;

typedef struct{
    eLteRlcDcField dc;
    eLteRlcRfField rf;
    eLteRlcPField  p;
    eLteRlcFiField fi;
    uint16         sn;
}lteRlcAmdPduHdrStruct;

typedef struct{
    lteRlcAmdPduHdrStruct hdr;
    ltePduMsgStruct       data[LTE_RLC_AMD_MAX_PDU];
    uint8 noOfPdus;
}lteRlcAmdPduStruct;

typedef struct{
    uint32 N_nack;
    uint16 ack_sn;
    uint16 nack_sn[LTE_RLC_AM_WINDOW_SIZE];
}lteRlcStatusPduStruct;


uint8 decodeUlRlcAmPdu(ltePduMsgStruct *msg, lteRlcAmdPduStruct *pdu);
uint8 encodeDlRlcAmPdu(lteRlcAmdPduStruct *pdu, ltePduMsgStruct *msg);
uint8 decodeUlRlcStatusPdu(ltePduMsgStruct *msg, lteRlcStatusPduStruct *pdu);
uint8 encodeDlRlcStatusPdu(lteRlcStatusPduStruct *pdu, ltePduMsgStruct *msg);

#endif //LTE_RLC_H_
