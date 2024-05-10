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
 * File Name   : timer.h 
 *
 * Description : This file provides the functionality of the Timer Control
 *               Block to external users.
 *
 * History     :
 *
 * Date			Author		   Details
 * ---------------------------------------------------------------------------
 * 08/08/2014	     Ashutosh Samal      File Creation
 *############################################################################
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#define TRUE    1
#define FALSE   0

typedef enum 
{
   RC_TCB_OK = 0,
   RC_TCB_NULL,
   RC_TCB_NULL_TMR,
   RC_TCB_INVALID_SIZE,
   RC_TCB_INVALID_GRANULARITY,
   RC_TCB_NO_RESOURCES,
}RC_TCB_t;

/*
 * we need to put some bounds to protect against extremely
 * large numbers.
 */

/*
 * Range of valid Timer Elements
 */
#define TCB_MIN_SIZE    (   32 )
#define TCB_MAX_SIZE    ( 4096 )

/*
 * Granularity of a timer tick in milliseconds   
 */
#define TCB_MIN_GRANULARITY   (   1 )
#define TCB_MAX_GRANULARITY   ( 100 )

/*
 * tcb_links
 *  Definition of the pointers used to link a timer.
 *  Double-linked list for efficiency.
 */
typedef struct tcbLinks 
{
    struct tcbLinks *tcbNext;
    struct tcbLinks *tcbPrev;
} tcbLinks_t;



/*
 * Timer Control Block used to manage the timer elements
 * and keep status to help understand performance
 */
#define TCB_NAME_LENGTH   ( 32 )

typedef struct 
{
    char          tcbName[ TCB_NAME_LENGTH ];
    unsigned int  tcbSize;
    unsigned int  tcbTimerIndex;         /* mod index around wheel */
    unsigned int  tcbTicks;              /* absolute ticks */
    unsigned int  tcbGranularity;        /* millisecond per tick */

    /*
     * few book keeping parameters to debug
     */
    unsigned int  tcbTimerActive;
    unsigned int  tcbTimerStopped;
    unsigned int  tcbTimerExpired;
    unsigned int  tcbTimerStarted;

    tcbLinks_t    *tcbTimerElements;
} tcb_t;


/*
 * tcbTimer_t
 *  Definition of a timer element.
 *  This can be malloc'ed or embedded into an existing
 *  application structure.
 */
typedef struct 
{
    tcbLinks_t   timerLinks;
    unsigned int timerRotationCount;
    unsigned int timerDelay;           /* initial delay       */
    unsigned int timerPeriodicDelay;   /* auto-restart if > 0 */
    void         *func_ptr;
    void         *parm;
} tcbTimer_t;


/*
 * Application call-back type to be invoked at timer
 * expiration.  The call-back must be short-n-sweet,
 * non-blocking.
 */
typedef void (*tcbCallBack)(tcbTimer_t *tmr, void *parm);



/*
 * isTcbTimerRunning
 *  Returns TRUE if the timer is active
 */
extern unsigned char isTcbTimerRunning (tcbTimer_t *tmr);

/*
 * tcbTimerInit
 *  Utility routine to initialize the links of timer elements.
 */
extern void tcbTimerInit (tcbTimer_t *tmr);

/*
 * tcbStatus
 * Displays timer wheel stats and counters to stdout.
 */
extern void tcbStatus (const tcb_t *tcb);

/*
 * tcbTimerStart
 * Starts a new timer.  If the timer is currently running,
 * it is stopped and restarted anew
 */
extern RC_TCB_t tcbTimerStart (tcb_t         *tcb,
                               tcbTimer_t    *tmr,
                               unsigned int  delay,
                               unsigned int  periodic_delay,
                               tcbCallBack   user_cb,
                               void          *parm);

/*
 * tcbTimerStop
 * stops a currently running timer
 */
extern RC_TCB_t tcbTimerStop (tcb_t *tcb, tcbTimer_t *tmr);

/*
 * tcbTimerTick
 * Timer Control Block tick handler which drives time for the
 * specified Timer Element
 */
extern void tcbTimerTick (tcb_t *tcb);

/*
 * tcbTimerDestroy
 * Destroys a timer wheel
 */
extern RC_TCB_t tcbTimerDestroy (tcb_t *tcb);

/*
 * tcbTimerCreate
 * creates and initializes a Timer Control Block
 */
extern RC_TCB_t tcbTimerCreate (unsigned int tcbSize,
                                unsigned int tcbGranularity,
                                const char   *p2name,
                                tcb_t        **tcb);

#endif /* __TCB_TIMER_H__ */
