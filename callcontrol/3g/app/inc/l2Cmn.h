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
 * File Name	 : l2Cmn.h
 *
 * Description   : This file has MAC interface with CL
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 28/10/2014	 Kuldeep S. Chauhan 	 File Creation
 ############################################################################*/
#ifndef L2_CMN_H
#define L2_CMN_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "stdio.h"
#include "cmnDs.h"

#define LOG_CH_ID_FACH  0
#define LOG_CH_ID_RACH  2

typedef enum _Direction
{
   INVALID_DIR_E,
   DIR_DL_E,
   DIR_UL_E

}Direction_e;

typedef enum _LogChType
{
   LOG_CH_INVLID_E,
   LOG_CH_CCCH_E,
   LOG_CH_CTCH_E,
   LOG_CH_DTCH_E,
   LOG_CH_DCCH_E

}LogChType_e; 

typedef union _Identifier_u
{
   U16        cellId;
   U16        ueIdx;
}Identifier_u;

typedef enum _IdType_e
{
   ID_TYPE_INVLID_E,
   ID_TYPE_CELL_ID_E,
   ID_TYPE_UE_IDX_E,
   ID_TYPE_CRNTI_E,
   ID_TYPE_URNTI_E,
   ID_TYPE_MAX_ID_E

}IdType_e; 

typedef struct _LogChId
{
   LogChType_e  logChType;
   U16          logChId;
   IdType_e     idType;
   Identifier_u ueCellId;
}LogChId_t;

#endif
