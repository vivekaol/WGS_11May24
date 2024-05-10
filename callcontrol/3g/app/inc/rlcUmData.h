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
/*############################################################################
 * File Name	 : rlcUmData.h 
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 10/11/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef RLC_UM_DATA_H
#define RLC_UM_DATA_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "errorCode.h"
#include "cmnDs.h"
#include "l2Cmn.h"
#include "rlc.h"

#define SN_BIT_MASK(len)           (~((~0)<< len))

/************** DUMMY VALUE ****************/
#define RLC_SINGLE_SDU_STRT_END_WITH_PDU 0x00
/************** DUMMY VALUE ****************/
#define RLC_LI_VALUE_NONE                0x00
#define RLC_SINGLE_SDU_STRT_WITH_PDU     0x7C
#define RLC_SINGLE_SDU_END_WITH_PDU      0x7D

#define RLC_PREV_SDU_SDU_END             0x00
#define MAX_NUM_SDU_PER_PDU              5
#define MAX_DCH_LOG_CH_PER_UE            5
#define RLC_UM_RO_QUEUE_SIZE             1024
//#define RLC_UM_RO_QUEUE_SIZE             100
#define MAX_SDU_SEG_PER_UM_PDU           5
#define RLC_UM_WINDOW_SIZE               32

//  0++++++++++vrR-----vrH-----vrMr+++++++++MAXSN
//  0------vrH----vrMr++++++++++vrR---------MAXSN
//  Area indicated in '-' is within Window. equation is good Only for first case 
//  For second case equation wrong for sn > 0 & sn < vrMr
//  TBD: But in current Test scenarios this should never be hit
#define RLC_RX_UM_SN_IN_WINDOW(sn, low, High) (((sn>=low) && (sn < High)) ? TRUE_E : FALSE_E)

typedef struct _UmRlcRxSv
{
   U16            vr_R;
   U16            vr_H;
   U16            vr_Mr;

}UmRlcRxSv_t;

typedef struct _RxUmPduHdrInfo
{
   U16          hdrLen;
   U16          pduLen;
   U8           sn;
   U16          e;
   U16          numLi;
   U16          Li[MAX_SDU_SEG_PER_UM_PDU];
}RxUmPduHdrInfo_t;

typedef struct _RxUmSduDataInPdu
{
   U16     len;
   // Starting from PDU bit0, If PDU itself is offset from buffer that 
   // information will be stored in bitOffset present in RxUmPduInfo
   U16     bitOffset;  
   U16     isFirstSeg; 
   U16     isLastSeg; 
   
}RxUmSduDataSeg_t;

typedef struct _RxUmPduInfo
{
   U8       inUse;
   U8       sn;
   U16      pduLen;
   U8      *rlcPduBuf;  //Free Memory when deleting UmPduEntry not on Sdu delivery
   U16      pduBitOffset;
   U16      numFirstSduSeg;
   U16      numLastSduSeg;
   U16      numSeg;
   U16      nxtValidSegIdx;
   // When some Initial segment assembled to form PDU it will have index of next unprocessed Sdu Seg
   RxUmSduDataSeg_t    segDataInfo[MAX_SDU_SEG_PER_UM_PDU];

}RxUmPduInfo_t;

typedef struct _RlcPduHdrInfo
{
   U8              sn;
   U8              paddingPresFlag;
   /***** These parameter are used to Fill RLC Header Field***/
   U8              numLi;
   U8              Li[MAX_NUM_SDU_PER_PDU];
   /***** These parameter are used to Fill Data In RLC Field***/
   U16             numSduSeg;
   DlSduDataSeg_t  sduDataSeg[MAX_NUM_SDU_PER_PDU];
   U16             totalSduData;
}RlcPduHdrInfo_t;

typedef struct _TxPduInfo
{
   U8              inUse;
   RlcPduHdrInfo_t rlcPduHdrInfo;
   U16             pduLen;

}TxUmPduInfo_t;

typedef struct _LchDlUmCntxt
{
   LogChType_e     lchType;
   U16             logChId;
   Direction_e     dir;         //direction DIR_DL_E/DIR_UL_E
   RlcMode_e       rlcMode;
   U16             nxtSn;
   U16             snLen;       // In Bits , = 7bit for UM,
   U16             boData;
   U16             boCtrl;
   U16             ctrlPduPres; //Flag to indicate if Control PDU is present.
   UmRlcRxSv_t     umSV;
   U8              prevPduFullLiPendFlag;
   TxUmPduInfo_t   rlxTxPdu;
   // TBD: Check if not using Queue in UM remove it frm DataStructure
   TxUmPduInfo_t   reTxQ[RLC_UM_RO_QUEUE_SIZE]; // Needed in Rx, not needed in Tx
   //CtrlPduInfo_t crtlPduInfo; //Needed in UM Mode, add it for UM Mode
   SduQCntxt_t     sduQCntxt;

} LchDlUmCntxt_t;

typedef struct _LchUlUmCntxt
{
   // Dummy for Now
   Direction_e       dir;  //direction DIR_DL_E/DIR_UL_E
   RlcMode_e         rlcMode;
   U16               logChId;
   LogChType_e       lchType;

   U16               snLen;                    // In Bits , = 7bit for UM,
   UmRlcRxSv_t       umSv;                     // State Variables based on RLC Mode
   RxUmPduHdrInfo_t  hdrInfo;                  // Current PDU Header decoded Info
   RxUmPduInfo_t     RxRoQueue[RLC_UM_RO_QUEUE_SIZE]; // Reordering Queue

} LchUlUmCntxt_t;

ErrorCode_e GetUmDlRlcHdrInfo(LogChId_t *logChinfo, U16 pduLen, LchDlUmCntxt_t *logChCntxt, SduInfo_t *sduCntxt);
ErrorCode_e CreateDlUmRlcHdr( U8 *rlcPduBuf, U16 *pduByteIdx, TxUmPduInfo_t *txPduInfo);
ErrorCode_e CreateUmRlcPdu( U8 *rlcPduBuf, U16 *pduByteIdx, LchDlUmCntxt_t *logChCntxt, U16 pduLen);
#endif
