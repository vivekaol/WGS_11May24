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
* File Name   : rtsTxMsgHandler.h
 *
* Description : Function to support processing of readyToSend Ind from L1
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 15/10/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#ifndef RTSTXMSGHANDLER_H_
#define RTSTXMSGHANDLER_H_

typedef enum
{
	STATE_RTSMSG_NOT_RECEIVED = 0 ,
	STATE_RTSMSG_RECEIVED ,

} stateRTSMsg;

#endif // RTSTXMSGHANDLER_H_
