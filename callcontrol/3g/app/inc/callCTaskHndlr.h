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
 ############################################################################*/

/*############################################################################
 * File Name   : callCTaskHndlr.h 
 *
 * Description : This is Main file of ImsiCatcher application. It initializes all 
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 23/09/2014	Kuldeep S. Chauhan      File Creation
 ############################################################################ */
#ifndef _CALLC_TASK_HNDLR_H_
#define _CALLC_TASK_HNDLR_H_
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include "errorCode.h"
#include "cmnPf.h"
#include "msgQue.h"
#include "taskHndlr.h"

ErrorCode_e rrcAppTaskHndlr(Msg_t msgBuf);
void l2DlDataTaskHndlr(Msg_t msgBuf);
void l2UlDataTaskHndlr(Msg_t msgBuf);
void l2CfgTaskHndlr(Msg_t msgBuf);
void clL1CSndTaskHndlr (Msg_t msgBuf);

#endif
