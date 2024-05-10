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
 * File Name	 : macUlDataHndlr.h
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 10/10/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef MAC_UL_DATA_HNDLR_H
#define MAC_UL_DATA_HNDLR_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "l2Cmn.h"
#include "macFpInterface.h"
typedef enum _TctfChType
{
   TCTF_CH_TYPE_INVALID_E,
   TCTF_CH_TYPE_BCCH_E,
   TCTF_CH_TYPE_PCCH_E,
   TCTF_CH_TYPE_CCCH_E,
   TCTF_CH_TYPE_CTCH_E,
   TCTF_CH_TYPE_DCCH_E,
   TCTF_CH_TYPE_DTCH_E

} TftfChType_e;

typedef struct _MacCt_t
{
   U16 logChId; // TBD: Kuldeep dummy
} MacCt_t;

typedef struct _MacHdr_t
{
   //TftfChType_e tctfChType; 
   IdType_e     idType;
   Identifier_u id;
   MacCt_t      macCt;
   LogChType_e  macLogChType;
} MacHdr_t;

void L2MacUlDataHndlr(Msg_t *ulDataMsg);
void RachDataIndHndlr(MacUlDataInd_t *rachDataInd);
void DchDataIndHndlr(MacUlDataInd_t *dchDataInd);

#endif
