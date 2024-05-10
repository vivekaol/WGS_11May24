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
 *############################################################################*/
/*############################################################################
  * File Name	: rrcMsg.h  
  *
  * Description : This file has interface with L2, all data/control msg are 
  *               received from L2.
  *
  * History 	:
  *
  * Date		 Author 				 Details
  * ---------------------------------------------------------------------------
  * 17/11/2014	         Ashutosh Samal                          File Creation
  *############################################################################*/
#ifndef _RRC_MSG_H_
#define _RRC_MSG_H_

/* -----------------------------------------------------
 *                 Include Files
 * ----------------------------------------------------- */
#include "errorCode.h"
#include "taskHndlr.h"
#include "cmnDs.h"

/* -----------------------------------------------------
 *                 Proto Types
 * ----------------------------------------------------- */
extern ErrorCode_e UeSmL2EvtHndlr(Msg_t msgBuf);
extern ErrorCode_e UeSmTimerEvtHndlr (Msg_t msgBuf);

#endif
