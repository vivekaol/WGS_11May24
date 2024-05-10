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
* File Name   : lteMacScheduler.h
 *
* Description : Lte Mac Scheduler functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#ifndef LTE_MAC_SCHEDULER_H_
#define LTE_MAC_SCHEDULER_H_


#include "lteL1Defs.h"

void lteTddMacScheduler(uint16 nextSfn , uint8 nextSbfn);
uint8 lteCheckTDDsubframe( uint16 sbfn );
void lteMacScheduler(uint16 nextSfn , uint8 nextSbfn);
void buildPdcchPacketForMib(uint16 nextSfn , uint8 nextSbfn);
void buildTxDataPacketForMib(uint16 nextSfn , uint8 nextSbfn);
void buildPdcchPacketForSib1(uint16 nextSfn , uint8 nextSbfn);
void buildTxDataPacketForSib1(uint16 nextSfn , uint8 nextSbfn);

#endif /* LTE_MAC_SCHEDULER_H_ */
