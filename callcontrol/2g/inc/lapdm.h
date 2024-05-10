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
* File Name   : lapdm.h
 *
* Description : GSM Layer-2 header file
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/

#ifndef _LAPDM_H_
#define _LAPDM_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "l1Constants.h"
#include "gsmData.h"
//#include "userManager.h"


typedef enum{
    Initial=0x0,
    LinkEstablished=0x1,
    LinkReleased=0x2
}mLapdmstate_;
typedef tOCT_UINT8 mLapdmstate;

typedef struct LapdmStateVar
{
tOCT_UINT8 mVS;                                  ///< GSM 3.5.2.2, Q.921 3.5.2.2, send counter, NS+1 of last sent I-frame
tOCT_UINT8 mVA;                                 ///< GSM 3.5.2.3, Q.921 3.5.2.3, ack counter, NR+1 of last acked I-frame
tOCT_UINT8 mVR;                                 ///< GSM 3.5.2.5, Q.921 3.5.2.5, recv counter, NR+1 of last recvd I-frame
tOCT_UINT8 mRC;                                ///< retransmission counter, GSM 04.06 5.4.1-5.4.4
tOCT_UINT8 receivedPFbit;
mLapdmstate  mLapdmstate;
}mLapdmStateVar;

#endif  /* #ifndef _LAPDM_H_ */
