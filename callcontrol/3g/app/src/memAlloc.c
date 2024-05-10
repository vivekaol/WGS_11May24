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
 * File Name	 : memAlloc.c
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 10/10/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "cmnDs.h"
#include "macFpInterface.h"

MacUlDataInd_t  *allocMem_RachDataInd(U16 paylodLen)
{
   MacUlDataInd_t  *rachDataInd;

//   printf("Alloc mem length(%d)",paylodLen);
   rachDataInd        = (MacUlDataInd_t *) malloc(sizeof(MacUlDataInd_t));
   memset(rachDataInd, 0, sizeof(MacUlDataInd_t));

   rachDataInd->ulDataBuf = (U8 *)malloc( paylodLen);
   memset(rachDataInd->ulDataBuf, 0, sizeof( paylodLen));

   return rachDataInd;
}

MacUlDataInd_t  *allocMem_DchDataInd(U16 paylodLen)
{
   MacUlDataInd_t  *dchDataInd;

//   printf("Alloc mem length(%d)",paylodLen);
   dchDataInd       = (MacUlDataInd_t *) malloc(sizeof(MacUlDataInd_t));
   memset(dchDataInd, 0, sizeof(MacUlDataInd_t));

   dchDataInd->ulDataBuf = (U8 *)malloc( paylodLen);
   memset(dchDataInd->ulDataBuf, 0, sizeof( paylodLen));

   return dchDataInd;
}
