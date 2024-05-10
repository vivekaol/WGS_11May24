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
* File Name   : lteL1IfApi.h
*
* Description : Lte L1C interface API definitions
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*########################################################################################
*/

#ifndef LTE_L1C_API_H_
#define LTE_L1C_API_H_

#include "lteL1Defs.h"

void buildAndSendPhyParamReq();
void buildAndSendPhyCellConfigReq();
void buildAndSendPhyStartReq();
void buildAndSendPhyStopReq();
void buildAndSendPhyDlConfigReq(uint8 *msgBuf , uint8 msgLen);
void buildAndSendPhyUlConfigReq(uint8 *msgBuf , uint8 msgLen);
void buildAndSendPhyDlHiDci0Req();
void buildAndSendPhyDlTxReq();


#endif /* LTE_L1C_API_H_ */
