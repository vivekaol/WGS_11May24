/*############################################################################
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
 ############################################################################ */
/**############################################################################
 * File Name	 : rlc.h 
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 25/11/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef RLC_H
#define RLC_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "cmnDs.h"
#include "l2Cmn.h"

#define RLC_MAX_UE_NUM             32

#define MAX_SDU_PER_LOG_CH         32
#define DL_CCCH_LCH_IDX_FOR_FACH   0
#define DL_CCCH_LCH_IDX_FOR_PAGING 1
#define INVALID_SDU_IDX            0
#define RLC_INVALID_UE_IDX         0
#define RLC_FIRST_UE_IDX           1
// This is used to update Bo when last PDU ended with SDU, bo = 0, but header still thr to send
#define RLC_PREV_SDU_END_WITH_PDU_LEN 3

#define INCREMENT_RLC_SN(sn, len)  (sn) = ((sn) + 1) & SN_BIT_MASK(len)
#define INC_RLC_SDU_NUM(sduIdx)    ( (sduIdx == (MAX_SDU_PER_LOG_CH - 1)) ? 0 : (sduIdx + 1))
#define DEC_RLC_SDU_NUM(sduIdx)    ( (sduIdx == 0) ? (MAX_SDU_PER_LOG_CH - 1) : (sduIdx - 1))

#define LI_PREV_SDU_END_WITH_PDU      0x00
#define SDU_STRT_WITH_PDU_NON_ENDING  0x7C
#define SDU_STRT_WITH_UM_PDU          0x7C
#define SDU_EXACT_FIT_PDU_WITH_LI     0x7D
#define SDU_ONLY_ONE_SEG_IN_PDU       0x7E
#define LI_PADDING_TO_FILL_PDU        0x7F
// Set LSB, Extention Bit In Li/SN Field
#define SET_EXTN_BIT_IN_LI_SN(Byte)   ((Byte) = (Byte) | 0x01)

typedef enum _RlcMode
{
   INVALID_Rlc_MODE_E,
   RLC_MODE_TM_E,
   RLC_MODE_UM_E,
   RLC_MODE_AM_E

}RlcMode_e;

typedef enum _AmPdyType
{
   PDU_TYPE_STATUS_E,
   PDU_TYPE_RESET_E,
   PDU_TYPE_RESET_ACK_E,
   INVALID_PDU_TYPE_E = 0x07,
   PDU_TYPE_DATA_E,
   PDU_TYPE_CTRL_E,   // Generic Type for CTRL PDU, This value used till specific type of CTRL PDU not decoded
   PDU_TYPE_INVALID_E

}AmPdyType_e;

typedef struct _DlSduDataInPdu
{
   U16     len;
   U16     sduCntxtIdx; // SduInfo Context for Sdu Context management, used in Deleting Sdu.
   U16     segOffset;   // Offset in Byte
   U16     sduIdx;
}DlSduDataSeg_t;

typedef struct _RxSduDataInPdu
{
   U16     len;
   U16     segOffset;   // Offset in Byte
   U16     sduIdx;
   U16     isLastSeg;

}RxSduDataSeg_t;

typedef struct _SduInfo
{
   U16          inUse;
   U16          numUsr; // Number Of handlers
   U16          mui;
   U16          byteLeft;
   U16          len; // In Bytes 
   U16          nxtPduOffset;
   U8          *buf;

   U16          nxtSduIdx;
   U16          prevSduIdx;
}SduInfo_t;

typedef struct _SduQCntxt
{
   U16          numSdu;
   // SDU will always be used in continuation, so next to last will be free and round of at 64
   U16          nxtSduIdx;
   U16          prevSduPduSameEnd;
   U16          lastSduIdx;
   SduInfo_t    sduInfo[MAX_SDU_PER_LOG_CH];

}SduQCntxt_t;
#endif
