
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
 * File Name   : cmnDebug.h 
 *
 * Description : This file has support for logging based on module
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 27/01/2015	   Roshan Kumar Singh            File Creation
 *############################################################################ */
 
#ifndef _CMN_DEBUG_H_
#define _CMN_DEBUG_H_

#include <syslog.h>
#include <stdarg.h>
#include <time.h>
#include "cmnTypes.h"

#define MAX_CHAR_MOD_NAME 20
typedef enum
{
   sls,
   app,
   cmn,
   mac,
   rlc,
   rrc,
   MAX_MOD_NUM
} DbgModule_e;

extern char dngModNameStr[MAX_MOD_NUM][MAX_CHAR_MOD_NAME];
extern int dbgLevelCtrl;
extern int dbgModLvlStatus[MAX_MOD_NUM];
extern unsigned char boardDspType;

#define DEBUG(lev, printArg)                                                                         \
{                                                                                                     \
      if ((lev <= dbgLevelCtrl) && (lev <= dbgModLvlStatus[DBG_MODULE])&& (DBG_MODULE <= MAX_MOD_NUM))                                      \
      {                                                                                     \
         umtsLogPrint(LOG_LOCAL0, dngModNameStr[DBG_MODULE], __FUNCTION__, __LINE__,formatDbgStr printArg);  \
      }                                                                                     \
}

#define DEBUG1(printArg)   DEBUG(1, printArg)
#define DEBUG2(printArg)   DEBUG(2, printArg)
#define DEBUG3(printArg)   DEBUG(3, printArg)
#define DEBUG4(printArg)   DEBUG(4, printArg)
#define DEBUGMSG(printArg) DEBUG(0, printArg)

#define DBG_FUNC_ENTRY(lev,x) DEBUG(lev, "========= ENTERED FUNC: #x ==========\n")
#define DBG_FUNC_EXIT(lev,x)  DEBUG(lev, "========= EXITING FUNC: #x ==========\n")

#endif /* CMN_DEBUG_H */

