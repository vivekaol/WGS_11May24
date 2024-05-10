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
* File Name   : l2scheduler.h
 *
* Description : Layer-2 Scheduler functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#ifndef L2SCHEDULER_H_
#define L2SCHEDULER_H_


#include "l1Constants.h"

typedef struct allocation
{
tOCT_UINT8 txSLotNum;
tOCT_UINT8 subChNum;
}logicalChannelIdentity;

tOCT_UINT8 allocateLogicalChannel(logicalChannelIdentity *allocated_channel);
void deallocateLogicalChannel(logicalChannelIdentity *deallocate_channel);

#if	(defined FEA_SILENT_CALL) || (defined FEA_VOICE_CALL_TO_TARGET)
tOCT_UINT8 allocateFullTrafficChannel(logicalChannelIdentity *allocated_channel);
void deallocateFullTrafficChannel(logicalChannelIdentity *deallocate_channel);
tOCT_UINT8 allocateHalfTrafficChannel(logicalChannelIdentity *allocated_channel);
void deallocateHalfTrafficChannel(logicalChannelIdentity *deallocate_channel);
#endif
#ifdef FEA_GPRS
tOCT_UINT8 allocatePdtchChannel(logicalChannelIdentity *allocated_channel);
void deallocatePdtchChannel(logicalChannelIdentity *deallocate_channel);
#endif
void clearSchedulerData();
#endif /* L2SCHEDULER_H_ */
