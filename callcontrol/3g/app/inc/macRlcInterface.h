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
 * File Name	 : macRlcInterface.h
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 28/10/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef MAC_RLC_INTERFACE_H
#define MAC_RLC_INTERFACE_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "cmnDs.h"
#include "l2Cmn.h"

typedef struct _RlcDataInfo
{
   U16      numPdu;
   U16      pduSize;
   U8      *pduBuf;
   U16      dataOffset; /*data offset in bits*/

}RlcDataInfo_t;

typedef struct _RlcDataInd
{
   LogChId_t      logChInfo;
   RlcDataInfo_t  rlcDataInfo;
   unsigned int    propDelay;
} RlcDataInd_t;
#endif
