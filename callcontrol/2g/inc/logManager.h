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
* File Name   : logManager.h
 *
* Description : Logging API functions
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 5/11/2014          					Anand Kashikar       File Creation
*############################################################################
*/
#ifndef LOGMANAGER_H_
#define LOGMANAGER_H_

#include <syslog.h>
#include <stdarg.h>
#include "userManager.h"
#include "fxLSocketInterfaceApi.h"

/*
       LOG_EMERG      system is unusable

       LOG_ALERT      action must be taken immediately

       LOG_CRIT       critical conditions

       LOG_ERR        error conditions

       LOG_WARNING    warning conditions

       LOG_NOTICE     normal, but significant, condition

       LOG_INFO       informational message

       LOG_DEBUG      debug-level message

*/

void logManagerInit();
char * logGetUserStateString( gsmL23States userState );
//char * logGetFxlHdrMsgTypeString( fxLMsgType msgType );
void logPrint(int logPriority , const char *message, ...);
void logManagerExit();


#endif
