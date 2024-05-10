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
 * File Name	 : macFpInterface.h
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 10/10/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef MAC_FP_INTERFACE_H
#define MAC_FP_INTERFACE_H
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "cmnDs.h"
#include "msgQue.h"
#define MAX_CRCI_NUM    12
#define UE_IDX_OFFSET_L2 1
/* -----------------------------------------------------
 *                 Data Type
 * -----------------------------------------------------*/
typedef struct _MacUlDataInd
{
   //MacUlDataPhyHdr_t  macUlDataPhyHdr;
   U16  ueIdx;
   U8   cfn;
   U8   tfi; 
   U8   propDelay;
   U8   numTb;
   U8   crci[MAX_CRCI_NUM];
   U16  dataLen;
   U8   *ulDataBuf; //Variable length array, If prob check by changing it to pointer 05Dec

} MacUlDataInd_t;

MacUlDataInd_t  *allocMem_RachDataInd(U16 paylodLen);
#endif
