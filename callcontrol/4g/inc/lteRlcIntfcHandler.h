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
* File Name   : lteRlcIntfcHandler.h
 *
* Description : Lte RLC Interface Layer functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 17/04/2015          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#ifndef LTE_INTERFACE_RLC_H_
#define LTE_INTERFACE_RLC_H_

#include "lteL1Defs.h"
#include "lteUserManager.h"
#include "oct_ltefapimacphyinterface.h"
#include "lteL2Interface.h"


uint8 lteRlcUlDchDataHandler(ltePduMsgStruct *pdu, lteUserInfo *info);
void lteBuildAndSendRlcPdu(lteL2InftMsg_t *rrcMsg);
#endif /* LTE_INTERFACE_RLC_H_ */
