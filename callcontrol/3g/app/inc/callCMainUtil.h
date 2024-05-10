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
 * File Name   : callCMainUtil.h 
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *               global data structures, Massage Queue, Task and interface with L1.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 12/09/2014	Kuldeep S. Chauhan      File Creation
 *############################################################################
*/

#ifndef _CALL_C_MAIN_UTIL_H
#define _CALL_C_MAIN_UTIL_H
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------
*/
#include "errorCode.h"
#include "umtsCfg.h"

/* -----------------------------------------------------
 *                 Utility Functions decleration
 -----------------------------------------------------*/ 
ErrorCode_e InitTasks(void);
ErrorCode_e InitMemPool(void);
ErrorCode_e InitMsgQueue(void);
ErrorCode_e InitStateMachine(void);
ErrorCode_e InitDfltParam(void);
ErrorCode_e InitAppClCntxt(void);
ErrorCode_e InitCfgParam(void);

void FillModemSetupReq(void);
void FillCellDeleteReq(void);
void FillPriCPICHInfo ( void);
void FillPriSCHInfo (void);
void FillSecSCHInfo (void);
void FillCellInfo (void);
void FillCellSetupReq(void);
void fillSCCPCHPhyInfo(void);
void fillRlTfcsInfo(void);
void fillSCCPCHTrchInfo(void);
void fillPCHInfo(void);
void fillPICHInfo(void);
void fillSccpchSetupRequest(void);
void fillPrachPhysUlPrach(void);
void fillPrachPhysDlAich(void);
void fillPrachCctrchUlTfc(void);
void fillPrachUlTrch(void);
void fillPrachSetupRequest(void);
void fillRadioLinkSetupRequest (unsigned int rlId);
void fillRadioLinkDeleteRequest (unsigned int rlId);
void cleanMemRadioLinkSetupRequest (void);
void cleanMemSccpchSetupRequest(void);
void cleanMemPrachSetupRequest (void);
void cleanMemRadioLinkDeleteRequest (void);
void fillCellReconfigReq (void);
void fillRadioLinkReconfigPrepRequest (RadioLinkReconfigPrepReqInfo *pRLReconfPrepReq);
void cleanMemRadioLinkReconfigPrepRequest (void);
void fillRadioLinkReconfigCommitRequest (unsigned int *pRlId);

#endif
