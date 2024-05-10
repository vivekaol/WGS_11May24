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
 ############################################################################ */

/*
 *############################################################################
 * File Name   : timer.c 
 *
 * Description : This file provides the functionality of the Timer Control
 *               Block.
 *
 * History     :
 *
 * Date			Author		   Details
 * ---------------------------------------------------------------------------
 * 30/10/2014	     Ashutosh Samal      File Creation
 *############################################################################
 */

/*
 * Include Headers
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timerApi.h"
#include "timer.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = cmn;

/*
 *############################################################################
 * Method Name : tcbTimerEnqueue
 *
 * Description : Enqueues the Timer Element to the proper position in Timer 
 *               Control Block.
 *
 * Parameters  :
 *     *tcb      pointer to the Timer Control Block
 *
 *     *tmr      pointer to the Timer Element
 *
 *     delay     delay in milliseconds
 *
 * Returns     : None
 *############################################################################
 */
static void tcbTimerEnqueue (tcb_t *tcb, tcbTimer_t *tmr, unsigned int delay) 
{
    tcbLinks_t  *prev, *spoke;

    unsigned int curPosition;
    unsigned int ticks;
    unsigned int tickDisplacement;

    if (delay < tcb->tcbGranularity)
    {
        /* must delay at least one tick, can not delay in past... */
        ticks = 1;

    }
    else
    {
        /* compute number ticks reqquired to expire the duration */
        ticks = (delay / tcb->tcbGranularity);
    }

    /* tick displacement from current position */
    tickDisplacement = (ticks % tcb->tcbSize);

    tmr->timerRotationCount = (ticks / tcb->tcbSize);

    /* calculate position to place the timer */
    curPosition = ((tcb->tcbTimerIndex + tickDisplacement) % tcb->tcbSize);

    spoke = &tcb->tcbTimerElements[curPosition];
    /*
     * We have a timer and now we have a spoke.  All that is left is to
     * link the timer to the spoke's list of timers.  With a doubly linked
     * list, there is no need to check for an empty list.  We simply link
     * it to the end of the list.  This is the same price as putting it
     * on the front of the list but feels more 'right'.
     */
    prev = spoke->tcbPrev;
    tmr->timerLinks.tcbNext = spoke;
    tmr->timerLinks.tcbPrev = prev;

    prev->tcbNext  = (tcbLinks_t *)tmr;
    spoke->tcbPrev = (tcbLinks_t *)tmr;

    return;
}

/*
 *############################################################################
 * Method Name : tcbStatus
 *
 * Description : Displays the status of timers in Timer Control Block.
 *
 * Parameter   :
 *       *tcb    pointer to the Timer Control Block.
 *
 * Returns     : None     
 *############################################################################
 */
void tcbStatus (const tcb_t *tcb)
{
    if (NULL == tcb)
    {
        return;
    }

    DEBUG4(("\t\t\t%s \n", tcb->tcbName ));
    DEBUG4(("   TCB Granularity\t=\t%u\n", tcb->tcbGranularity));
    DEBUG4(("          TCB Size\t=\t%u\n", tcb->tcbSize));
    DEBUG4(("    TCB Tick Count\t=\t%u\n", tcb->tcbTicks));
    DEBUG4(("   TCB Timer Index\t=\t%u\n", tcb->tcbTimerIndex));

    DEBUG4(("TCB Running timers\t=\t%u\n", tcb->tcbTimerActive));
    DEBUG4(("TCB Started timers\t=\t%u\n", tcb->tcbTimerStarted));
    DEBUG4(("TCB Stopped timers\t=\t%u\n", tcb->tcbTimerStopped));
    DEBUG4(("TCB Expired timers\t=\t%u\n", tcb->tcbTimerExpired));
    return;
}

/*
 *############################################################################
 * Method Name : isTcbTimerRunning
 *
 * Description : This method gives that a particular Timer Element is running 
 *               or not. 
 *
 * Parameter   :
 *     *tmr      pointer to the Timer Element
 *
 * Returns     : true, if timer is active.
 *               false, if timer is not active.
 *############################################################################
 */
unsigned char isTcbTimerRunning (tcbTimer_t *tmr)
{
    if (NULL == tmr) 
    {
        return (FALSE);
    }

    /* if the timer is linked, its active */
    if (NULL != tmr->timerLinks.tcbNext)
    {
        return (TRUE);
    }

    return (FALSE);
}

/*
 *############################################################################
 * Method Name : tcbTimerInit
 *
 * Description : This procedure initializes the links of Timer Element.
 *
 * Parameter   :
 *     *tmr      pointer to the Timer Element
 *
 * Returns     : None
 *############################################################################
 */
void tcbTimerInit (tcbTimer_t *tmr)
{
    if (tmr)
    {
        tmr->timerLinks.tcbNext = NULL;
        tmr->timerLinks.tcbPrev = NULL;
    }
}

/*
 *############################################################################
 * Method Name : tcbTimerStart
 *
 * Description : Start (or Restart) a timer to expire in the future.If the
 *               timer is currently linked to a Timer Control Block, it will be
 *               removed first. A new timer will be linked based on the
 *               millisecond time delay requested by user. 
 *
 * Parameters  :
 *     *tcb             pointer to the Timer Control Block
 *
 *     *tmr             pointer to the Timer Element
 *
 *     delay            initial delay in milliseconds
 *
 *     periodic_delay   periodic delay in milliseconds
 *
 *     user_cb          application function callback to be invoked when the
 *                      timer expires. 
 *
 *     parm             persistent parameter passed to the application
 *                      callback function upon expiration
 *
 * Returns     : RC_TCB_OK on success
 *               error otherwise
 *############################################################################
 */
RC_TCB_t tcbTimerStart (tcb_t         *tcb,
                        tcbTimer_t    *tmr,
                        unsigned int  delay,
                        unsigned int  periodic_delay,
                        tcbCallBack   user_cb,
                        void          *parm)
{
    tcbLinks_t *next, *prev;

    if (NULL == tcb) 
    {
        return (RC_TCB_NULL);
    }

    if (NULL == tmr)
    {
        return (RC_TCB_NULL_TMR);
    }

    /* Lock the Timer Mutex */
    pthread_mutex_lock (&timerMutexLock);

    /*
     * First check to see if it is already running. If so, remove
     * it from the Timer Control Block. 
     */
    next = tmr->timerLinks.tcbNext;
    if (next) 
    {
        prev = tmr->timerLinks.tcbPrev;
        next->tcbPrev = prev;
        prev->tcbNext = next;

        /* stats book keeping */
        tcb->tcbTimerActive--;
    }

    /* set user call_back and parameter */
    tmr->func_ptr            = user_cb;
    tmr->parm                = parm;
    tmr->timerDelay          = delay;
    tmr->timerPeriodicDelay  = periodic_delay;

    tcbTimerEnqueue(tcb, tmr, delay);

    tcb->tcbTimerStarted++;
    tcb->tcbTimerActive = (tcb->tcbTimerActive + 1 ) % sizeof(unsigned int);

    /* Unlock the Timer Mutex */
    pthread_mutex_unlock (&timerMutexLock);

    return (RC_TCB_OK);
}

/*
 *############################################################################
 * Method Name : tcbTimerStop
 *
 * Description : Stop the timer by removing it from Timer Control Block 
 *
 * Parameters  :
 *     *tcb      pointer to the Timer Control Block
 *
 *     *tmr      pointer to the Timer Element
 *
 * Returns     : RC_TCB_OK on success
 *               error otherwise
 *############################################################################
 */
RC_TCB_t tcbTimerStop (tcb_t *tcb, tcbTimer_t *tmr)
{
    tcbLinks_t *next, *prev;

    if (NULL == tcb) 
    {
        return (RC_TCB_NULL);
    }

    if (NULL == tmr)
    {
        return (RC_TCB_NULL_TMR);
    }

    /* Lock the Timer Mutex */
    pthread_mutex_lock (&timerMutexLock);

    next = tmr->timerLinks.tcbNext;
    if (next)
    {
        prev = tmr->timerLinks.tcbPrev;
        next->tcbPrev = prev;
        prev->tcbNext = next;
        tmr->timerLinks.tcbNext = NULL;
        tmr->timerLinks.tcbPrev = NULL;

        tcb->tcbTimerActive--;
        tcb->tcbTimerStopped++;
    }

    /* Unlock the Timer Mutex */
    pthread_mutex_unlock (&timerMutexLock);

    return (RC_TCB_OK);
}

/*
 *############################################################################
 * Method Name : tcbTimerTick
 *
 * Description : This procedure moves the Timers in Timer Control Block & calls
 *               the callback method for the Timer Expired. 
 *
 * Parameters  :
 *     *tcb      pointer to the Timer Call Block
 *
 * Returns     : None
 *############################################################################
 */
void tcbTimerTick (tcb_t *tcb)
{
    tcbLinks_t  *spoke, *next, *prev;
    tcbTimer_t *tmr;

    tcbCallBack user_call_back;

    if (NULL == tcb)
    { 
        return;
    }

    /* Lock the Timer Mutex */
    pthread_mutex_lock (&timerMutexLock);

    tcb->tcbTicks++;

    /* Advance the index to the next */
    tcb->tcbTimerIndex = ( tcb->tcbTimerIndex + 1 ) % tcb->tcbSize;

    /*
     * Process the Timers, removing Timers that have expired.
     * If the timer rotation count is positive
     * decrement and catch the timer on the next Timer revolution.
     */
    spoke = &tcb->tcbTimerElements[tcb->tcbTimerIndex];
    tmr = (tcbTimer_t *)spoke->tcbNext;

    while((NULL != tmr) && ((tcbLinks_t *)tmr != spoke))
    {
        next = (tcbLinks_t *)tmr->timerLinks.tcbNext;
        prev = (tcbLinks_t *)tmr->timerLinks.tcbPrev;

        /*
         * if the timer is a long one and requires one or more rotations
         * decrement rotation count and leave for next turn.
         */
        if (tmr->timerRotationCount != 0) 
        {
            tmr->timerRotationCount--;
        } 
        else
        {
            if (NULL != prev)
            {
               prev->tcbNext = next;
            }

            if (NULL != next)
            {
               next->tcbPrev = prev;
            }

            tmr->timerLinks.tcbNext = NULL;
            tmr->timerLinks.tcbPrev = NULL;

            tcb->tcbTimerActive--;
            tcb->tcbTimerExpired++;

            /* Invoke the user expiration handler to do the actual work. */
            if(tmr->func_ptr != NULL)
            {
				user_call_back = tmr->func_ptr;
				if((*user_call_back) != NULL)
				(*user_call_back)(tmr, tmr->parm);
            }

            /* Automatically restart the timer if timerPeriodicDelay > 0 */
            if (tmr->timerPeriodicDelay > 0)
            {
                 tcbTimerEnqueue(tcb, tmr, tmr->timerPeriodicDelay);
                 tcb->tcbTimerActive = (tcb->tcbTimerActive + 1 ) % sizeof(unsigned int);
            }
        }

        tmr = (tcbTimer_t *)next;
    }

    /* Unlock the Timer Mutex */
    pthread_mutex_unlock (&timerMutexLock);
    
    return;
}

/*
 *############################################################################
 * Method Name : tcbTimerDestroy
 *
 * Description : This procedure destroys the specified Timer Control Block.
 *               All Timers are stopped and resource released.
 *
 * Parmeters   :
 *     *tcb      pointer to the Timer Control Block
 *
 * Returns     : RC_TCB_OK on success
 *               error otherwise
 *############################################################################
 */
RC_TCB_t tcbTimerDestroy (tcb_t *tcb)
{
    unsigned int timerCnt;
    tcbLinks_t *spoke;

    tcbTimer_t *tmr;

    if (NULL == tcb)
    {
        return (RC_TCB_NULL);
    }

    /* Search all Timer Elements in the Timer Control Block and 
     * stop all Timers.
     */
    for (timerCnt = 0; timerCnt < tcb->tcbSize; timerCnt++)
    {
        spoke = &tcb->tcbTimerElements[timerCnt];

        tmr = (tcbTimer_t *)spoke->tcbNext;

        while ((NULL != tmr) && ((tcbLinks_t *)tmr != spoke))
        {
            tcbTimerStop(tcb, tmr);

            tmr = (tcbTimer_t *)spoke->tcbNext;
        } /* end while */

    } /* end for */

    free(tcb->tcbTimerElements);
    free(tcb);

    return (RC_TCB_OK);
}

/*
 *############################################################################
 * Method Name : tcbTimerCreate
 *
 * Description : This procedure initializes Timer Control Block. Timers must not
 *               not be started before this procedure is called.
 *
 * Parmeters   :
 *     tcbSize         number of Timer Elements in the TCB.  The number
 *                     of Timer Elements should be engineered such that
 *                     tcbSize >= (longest duration / tcbGranularity )
 *                     Depending upon the number of concurrent timers, the
 *                     distribution of those timers, it may be beneficial to
 *                     further increase the tcb size.  Objective is to
 *                     minimize frequency of 'long' timers requiring wheel
 *                     revolutions.
 *
 *     tcbGranularity  milliseconds between ticks
 *
 *     *p2name         pointer to the name of Timer Control Block.  Limited
 *                     to TCB_NAME_LENGTH
 *
 *     **tcb           returned pointer to the created Timer Control Block
 *
 * Returns     : RC_TCB_OK on success
 *               error otherwise
 *############################################################################
 */
RC_TCB_t tcbTimerCreate (unsigned int tcbSize,
                         unsigned int tcbGranularity,
                         const char   *p2name,
                         tcb_t        **tcb)
{
    unsigned int timerCnt;
    tcbLinks_t *spoke;

    tcb_t  *p2tcb;

    if (NULL == tcb) 
    {
        return (RC_TCB_NULL);
    }
    *tcb = NULL;

    if ((tcbSize < TCB_MIN_SIZE) || (tcbSize > TCB_MAX_SIZE))
    {
        return (RC_TCB_INVALID_SIZE);
    }

    if ((tcbGranularity < TCB_MIN_GRANULARITY) ||
        (tcbGranularity > TCB_MAX_GRANULARITY))
    {
        return (RC_TCB_INVALID_GRANULARITY);
    }

    p2tcb = (tcb_t *)malloc( sizeof(tcb_t));
    if (NULL == p2tcb)
    {
        return (RC_TCB_NO_RESOURCES);
    }

    p2tcb->tcbTimerElements = 
                           (tcbLinks_t *)malloc(tcbSize * sizeof(tcbLinks_t));
    if (NULL == p2tcb->tcbTimerElements)
    {
        free(p2tcb); 
        return (RC_TCB_NO_RESOURCES);
    }

    strncpy(p2tcb->tcbName, p2name, TCB_NAME_LENGTH-1);
    p2tcb->tcbName[TCB_NAME_LENGTH-1] = '\0';  

    p2tcb->tcbTicks = 0;

    p2tcb->tcbTimerIndex = 0;
    p2tcb->tcbGranularity = tcbGranularity;
    p2tcb->tcbSize  = tcbSize;

    /*
     * timer status to zero
     */
    p2tcb->tcbTimerActive  = 0;
    p2tcb->tcbTimerStopped = 0;
    p2tcb->tcbTimerExpired = 0;
    p2tcb->tcbTimerStarted = 0;

    /*
     * Set all Timer Elements to empty
     */
    spoke = &p2tcb->tcbTimerElements[0];
    for (timerCnt = 0; timerCnt < tcbSize; timerCnt++)
    {
        spoke->tcbNext = spoke;    /* empty spoke points to itself */
        spoke->tcbPrev = spoke;
        spoke++;
    }

    *tcb = p2tcb;
    return (RC_TCB_OK);
}
