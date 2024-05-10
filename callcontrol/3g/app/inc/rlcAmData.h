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
 * File Name	 : rlcAmData.h 
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 10/11/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef RLC_AM_DATA_H
#define RLC_AM_DATA_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "cmnDs.h"
#include "l2Cmn.h"

#define RLC_AM_RO_QUEUE_SIZE    4096
#define RLC_AM_RO_SN_MASK       0xEFFF
#define MAX_SDU_SEG_PER_AM_PDU  5
#define MAX_RLC_DL_AM_PDU_SIZE  17
#define RLC_AM_CTRL_PDU         0
#define RLC_AM_DATA_PDU         1
#define RLC_AM_WINDOW_SIZE      32
#define RLC_AM_MAX_NUM_RETX     4

#define RLC_PREV_PDU_END_WITH_SDU        0x00
#define RLC_INVALID_AM_PDU_1             0x7C
#define RLC_INVALID_AM_PDU_2             0x7D
#define RLC_AM_STATUS_PDU                0x7E
#define RLC_PDU_PADDING                  0x7F
#define MAX_SUFI_NUM_IN_STATUS_PDU       5
#define MAX_DL_NACK_SUFI                 10
#define MAX_BYTE_LEN_BITMAP_SUFI         4
//  0++++++++++vrR-----vrH-----vrMr+++++++++MAXSN
//  0------vrH----vrMr++++++++++vrR---------MAXSN
//  Area indicated in '-' is within Window. equation is good Only for first case 
//  For second case equation wrong for sn > 0 & sn < vrMr
//  TBD: But in current Test scenarios this should never be hit
#define RLC_RX_AM_SN_IN_WINDOW(sn, vrR, vrMr) (((sn>=vrR) && (sn < vrMr)) ? TRUE_E : FALSE_E)


#define RLC_AM_ACK_SUFI_SIZE_BYTE        0x03

typedef struct _AmRlcRxSv
{
   U16            vr_R;
   U16            vr_H;
   U16            vr_Mr;
 
}AmRlcRxSv_t;

typedef struct _AmRlcTxSv
{
   U16            vt_S;
   U16            vt_A;
   U16            vt_Ms;
   U16            vt_Pdu;
   U16            vt_Sdu;
   U16            vt_Rst;
   U16            vt_Mrw;
   U16            vt_Ws;
 
}AmRlcTxSv_t;
/***********************************************************
*  INFO Related to SUFI
*********************************************************/
// Sufi 4 bit Fields
typedef enum _SufiType
{
   SUFI_NO_MORE_E,  //0000
   SUFI_WINDOW_E,   //0001
   SUFI_ACK_E,      //0010
   SUFI_LIST_E,     //0011
   SUFI_BITMAP_E,   //0100
   SUFI_RLIST_E,    //0101
   SUFI_MRW_E,      //0110
   SUFI_MRW_ACK_E,  //0111
   SUFI_MAX_VALID_E

}SufiType_e;

typedef struct _AckSufi
{
   U16  lsn;  // 12 Bit Value

}ActSufi_t;

typedef struct _WindowSufi
{
   U16  wsn;  // 12 Bit Value

}WindowSufi_t;

typedef struct _ListSufi
{
   U16  length;  // 4 Bit Value
#define RLC_AM_LIST_SUFI_MAX_SIZE  16
   U16  SN[RLC_AM_LIST_SUFI_MAX_SIZE];    // 12 Bit Value
   U16  LI[RLC_AM_LIST_SUFI_MAX_SIZE];    // 4 Bit Value

}ListSufi_t;

typedef struct _BitMapSufi
{
   U16  length;  // 4 Bit Value
   U16  FSN;     // 12 Bit Value
   U16  Bitmap[MAX_BYTE_LEN_BITMAP_SUFI];  // 4 Bit Value

}BitMapSufi_t;

typedef struct _SufiInfo
{
   U16          dcField;
   AmPdyType_e  pduType;
   SufiType_e   sufiType;
   union {
      ActSufi_t      ackSufi;
      WindowSufi_t   windowSufi;
      ListSufi_t     lstSufi;
      BitMapSufi_t   bitMapSufi;
   }sufi;

} SufiInfo_t;

typedef struct _StatusPduDec
{
   U16          numSufi;
   SufiInfo_t   sufiInfo[MAX_SUFI_NUM_IN_STATUS_PDU];
   
}StatusPduEncDec_t;

typedef struct _DLStatusPduInfo
{
   U16          dcField;
   AmPdyType_e  pduType;
   U16          listSufiLength;
   ListSufi_t   listSufiInfo;
   ActSufi_t    ackSufiInfo;
   
}DlStatusPduInfo_t;

typedef struct _RxAmPduHdrInfo
{
   U16          hdrLen;
   U16          pduLen;
   U16          dcFlag;
   U8           sn;
   U16          pollBit;
   U16          he;
   U16          numLi;
   U16          Li[MAX_SDU_SEG_PER_AM_PDU];
   AmPdyType_e  pduType;
   StatusPduEncDec_t  statusPdu;
}RxAmPduHdrInfo_t;

typedef struct _RxAmSduDataInPdu
{
   U16     len;
   // Starting from PDU bit0, If PDU itself is offset from buffer that 
   // information will be stored in bitOffset present in RxAmPduInfo
   U16     bitOffset;  
   U16     isLastSeg;

}RxAmSduDataSeg_t;

typedef struct _RxAmPduInfo
{
   U8       inUse;
   U8       sn;
   U16      pduLen;
   //U8       rlcPduBuf[MAX_RLC_DL_AM_PDU_SIZE]; // UL AM PDU Size 148 bit ==> 116 Byte +1
   U8      *rlcPduBuf;  //Free Memory when deleting AmPduEntry not on Sdu delivery
   U16      pduBitOffset;
   U16      numLastSduSeg;
   U16      numSeg;
   U16      nxtValidSegIdx;
   // When some Initial segment assembled to form PDU it will have index of next unprocessed Sdu Seg
   RxAmSduDataSeg_t    segDataInfo[MAX_SDU_SEG_PER_AM_PDU];

}RxAmPduInfo_t;

typedef struct _LchUlAmCntxt
{
   Direction_e       dir;                      //direction DIR_DL_E/DIR_UL_E
   U16               logChId;
   LogChType_e       lchType;
   U16               snLen;                    // In Bits , = 7bit for UM,
   U16               amPollingStatus;
   AmRlcRxSv_t       amSv;                     // State Variables based on RLC Mode
   RxAmPduHdrInfo_t  hdrInfo;                  // Current PDU Header decoded Info
   RxAmPduInfo_t     RxRoQueue[RLC_AM_RO_QUEUE_SIZE]; // Reordering Queue

} LchUlAmCntxt_t;

typedef struct _RlcAmTxPduHdrInfo
{
   U16             dcFlag;
   U16             sn;
   U16             pollBit;
   U16             he;
   U8              paddingPresFlag;
   /***** These parameter are used to Fill RLC Header Field***/
   S8              numLi;
   U8              Li[MAX_NUM_SDU_PER_PDU];
   /***** These parameter are used to Fill Data In RLC Field***/
   U16             numSduSeg;
   DlSduDataSeg_t  sduDataSeg[MAX_NUM_SDU_PER_PDU];
   U16             totalSduData;  // Actual SDU data len, remaining might be padding or Piggyback Status SDU
}RlcAmdTxPduHdrInfo_t;

typedef struct _TxAmPduInfo
{
   U8                    inUse;
   U16                   sn;
   U16                   vt_Dat;
   U16                   reTxStatus; // ==TRUE_E means ready for next reTransmission
   U16                   pduLen;
   U16                   numSeg;
   //DlSduDataSeg_t        segDataInfo[MAX_SDU_SEG_PER_AM_PDU];
   RlcAmdTxPduHdrInfo_t  amPduHdrInfo;

}TxAmPduInfo_t;

typedef struct _LchDlAmCntxt
{
   LogChType_e       lchType;
   U16               logChId;
   Direction_e       dir;                      //direction DIR_DL_E/DIR_UL_E
   U16               snLen;                    // In Bits , = 12bit for UM,
   AmRlcTxSv_t       amSv;                     // State Variables based on RLC Mode
   U16               boData;
   // On Nack Inc by Nacked PDU len, update in MAC as well
   U16               boReTxData;
   U16               boCtrl;
   U8                prevPduFullLiPendFlag;
   U16               statusPduFlag;
   DlStatusPduInfo_t statusPduInfo;
   // For boReTxData > 0,loop frm vt_A(lower Edge of Window) to vt_S
   // Check reTxStatus for each PDU and re-trans if it is zero
   // TBD: In Future it might be good idea to keep saperate list of NACKed Sn as that will be faster.
   TxAmPduInfo_t     reTxQ[RLC_AM_RO_QUEUE_SIZE];
   SduQCntxt_t       sduQCntxt;
  
} LchDlAmCntxt_t;
#endif
