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
 *       (c) FXLynx Technologies Ltd. 2015, All Rights Reserved
 *
 ############################################################################ */

/*############################################################################
 * File Name   : cmnDebug.c 
 *
 * Description : This file has support for logging based on module
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 27/01/2015	   Roshan Kumar Singh            File Creation
 *############################################################################ */
 
#include <sys/time.h>
#include <pthread.h>
#include "cmnDs.h"
#include "cmnDebug.h"
#include "logManager.h"
extern unsigned char boardDspType;
int dbgLevelCtrl = 3;
int dbgForUnitTest = 0;
/*
   sls,
   app,
   cmn,
   mac,
   rlc,
   rrc,
*/
int  dbgModLvlStatus[MAX_MOD_NUM] = {3,3,3,3,3,3};
char dngModNameStr[MAX_MOD_NUM][MAX_CHAR_MOD_NAME] = 
              {
                 "sls",
                 "app",
                 "cmn",
                 "mac",
                 "rlc",
                 "rrc"
              };

const char *formatDbgStr(const char * msg, ...)
{
   static char prntBuf[100];
   va_list args;

   va_start(args, msg);
   vsprintf(prntBuf, msg, args);
   va_end(args);

   return prntBuf;
}

void umtsLogPrint(int logPriority , const char *modName, const char *funcName, unsigned lineNum, const char *msg)
{
/*
   if(dbgForUnitTest == 0)
   {
      if(boardDspType == 0)
      	vsyslog(logPriority|LOG_LOCAL0, "ModName(%s): %s", modName, msg);
      else
      	vsyslog(logPriority|LOG_LOCAL1, "ModName(%s): %s", modName, msg);
   }
   else
   {
      printf("ModName(%s): %s", modName, msg);
   }
 */
 logPrint(LOG_DEBUG , msg);
}
