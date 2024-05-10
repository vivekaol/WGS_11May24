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
* File Name   : lteL1IfManager.h
 *
* Description : LTE L1- EnodeB interface header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/


#ifndef _LTE_L1_IF_MANAGER_H_
#define _LTE_L1_IF_MANAGER_H_

#include <stdlib.h>
#include "lteL1Defs.h"

uint16 lteCurrentSubframeNum ;
uint16 lteCurrentSfn;
void * lteL1MsgHandler(void *nothing);
uint16 lteGetCurrentSfNSbfn(void);
void * lteTimerTickHandler(void *nothing);

#endif  //L1INTERFACEMANAGER_H_
