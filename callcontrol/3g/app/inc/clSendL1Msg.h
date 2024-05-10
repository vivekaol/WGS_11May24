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
 * File Name	 : clSendL1Msg.h  
 *
 * Description   : This file has interface with L1, all data/control msg are sent to L1 throught this file
 *
 * History 	 :
 *
 * Date		 Author                  Details
 * ---------------------------------------------------------------------------
 * 12/09/2014	 Kuldeep S. Chauhan 	 File Creation
 *############################################################################
*/
#ifndef _CL_SEND_L1_MSG_
#define _CL_SEND_L1_MSG_H
#include "l1capi_datastruct.h"
#include "cmnDs.h"
#include "errorCode.h"
#include "msgQue.h"
#include "rrc.h"

 /* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------
 */
#define CL_MSG_BUF_SIZE 2000

/***************************
 * Functions declarations  *
 * ************************/
ErrorCode_e oct_modem_setup_req (L1CAPI_Modem_Setup_Request *pModSetupReq);
ErrorCode_e oct_cell_delete_req (L1CAPI_Cell_Delete_Request *pCellDeleteReq);
ErrorCode_e oct_sysInfo_update  (L1CAPI_BCH_SIM_DATA *pOctSysInfoUpdate);
ErrorCode_e oct_radiolink_setup_req (L1CAPI_Radiolink_Setup_Request *pOctRlSetupReq);
ErrorCode_e oct_radiolink_delete_req (L1CAPI_Radiolink_DeletionRequest *pOctRlDeleteReq);
ErrorCode_e clL1CSndTaskHandleAppRrcMsg (Msg_t msgBuf);
ErrorCode_e buildAndSendRadioLinkSetupReq (Msg_t msgBuf);
ErrorCode_e buildAndSendRadioLinkDeleteReq (Msg_t msgBuf);
ErrorCode_e SendPchDataToL1 (unsigned int pcchIdx, unsigned int bfn);
ErrorCode_e oct_cell_reconfig_req (L1CAPI_Cell_Reconfig_Request *pCellReconfigReq);
void handleChgTxAttnCpichTxPwrTimeout (tcbTimer_t *pTimer, void *pCellIdx);
void sendChgTxAttnCpichTxPwrRsp (unsigned char success);
void handleSystemInfoUpdateTimeout (tcbTimer_t *pTimer, void *pCellIdx);
void sendSystemInfoUpdateRsp (unsigned char success);
#endif



