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
 *       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
 *
 ############################################################################*/

/*
 *############################################################################
 * File Name   : timerApi.h
 *
 * Description : This file provides the functionality of the Timer Control
 *               Block.
 *
 * History     :
 *
 * Date			Author		   Details
 * ---------------------------------------------------------------------------
 * 08/08/2014	     Ashutosh Samal      File Creation
 *############################################################################
 */

#ifndef __TIMER_API_H__
#define __TIMER_API_H__
#include <pthread.h>
#include "timer.h"

/* Define Constants */
#define TCB_SIZE         (100)   /* Timer Elements in TCB */
#define TCB_RESOLUTION   (1)     /* Granularity between Timer Elements in TCB */

#define TCB_SIZE_2G         (500)   /* Timer Elements in TCB */
#define TCB_RESOLUTION_2G   (100)     /* Granularity between Timer Elements in TCB */

#define TCB_SIZE_4G         (200)   /* Timer Elements in TCB */
#define TCB_RESOLUTION_4G   (100/10)     /* Granularity between Timer Elements in TCB */

extern pthread_mutex_t timerMutexLock;

/*
 * Utility routine to initialize the links of timer elements..
 */
extern void timerInit (tcbTimer_t *tmr);

/*
 * Displays Timer Control Block status.
 */
extern void timerStatus (void);

/*
 * returns active status of a timer.
 */
extern unsigned char isTimerRunning (tcbTimer_t *tmr); 

/*
 * starts a new timer on the Timer Control Block. If
 * the timer is currently running, it is stopped and
 * restarted a new
 */
extern RC_TCB_t timerStart (tcbTimer_t    *tmr,
                            unsigned int  delay,
                            unsigned int  periodic_delay,
                            tcbCallBack   user_cb,
                            void          *parm);

/*
 * stops a currently running timer
 */
extern RC_TCB_t timerStop (tcbTimer_t *tmr);

/*
 * System Timer Control Block tick handler
 */
extern void timerTick (void);

/*
 * Delete the Timer Control Block
 */
extern void timerDestroy (void);

/*
 * Creates and Initializes the Timer Control Block
 */
extern RC_TCB_t timerCreate (unsigned int tcbSize,
                             unsigned int tcbGranularity,
                             const char   *p2name);
/*
 * Timer Service Handler thread
 */
extern void * timerServiceHandler (void *param);
#endif /* __TIMER_API_H__ */
