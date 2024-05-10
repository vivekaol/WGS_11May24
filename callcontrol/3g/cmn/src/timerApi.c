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
 * File Name   : timerApi.c 
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

/* Include Files */
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
//#include <bits/sigaction.h>
#include <signal.h>
#include <string.h>
#include "timerApi.h"

/* Global Variables */
static tcb_t *tcbHandle = NULL;
pthread_mutex_t timerMutexLock;

/*
 *############################################################################
 * Method Name : timerInit
 *
 * Description : This procedure initializes the links of Timer Element.
 *
 * Parameter   :
 *     *tmr      pointer to the Timer Element
 *
 * Returns     : None
 *############################################################################
 */
void timerInit (tcbTimer_t *tmr)
{
    tcbTimerInit(tmr);
    return;
}

/*
 *############################################################################
 * Method Name : timerStatus
 *
 * Description : Displays the status of timers in Timer Control Block.
 *
 * Parameter   : None
 *
 * Returns     : None     
 *############################################################################
 */
void timerStatus (void)
{
    tcbStatus(tcbHandle);
    return;
}

/*
 *############################################################################
 * Method Name : isTimerRunning
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
unsigned char isTimerRunning (tcbTimer_t *tmr)
{
    return (isTcbTimerRunning(tmr));
}

/*
 *############################################################################
 * Method Name : timerStart
 *
 * Description : Start (or Restart) a timer to expire in the future.If the
 *               timer is currently linked to a Timer Control Block, it will be
 *               removed first. A new timer will be linked based on the
 *               millisecond time delay requested by user. 
 *
 * Parameters  :
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
RC_TCB_t timerStart (tcbTimer_t    *tmr,
                     unsigned int  delay,
                     unsigned int  periodic_delay,
                     tcbCallBack   user_cb,
                     void          *parm)
{
    return (tcbTimerStart(tcbHandle,
                          tmr,
                          delay,
                          periodic_delay,
                          user_cb,
                          parm));
}

/*
 *############################################################################
 * Method Name : timerStop
 *
 * Description : Stop the timer by removing it from Timer Control Block 
 *
 * Parameters  :
 *     *tmr      pointer to the Timer Element
 *
 * Returns     : RC_TCB_OK on success
 *               error otherwise
 *############################################################################
 */
RC_TCB_t timerStop (tcbTimer_t *tmr)
{
    return (tcbTimerStop(tcbHandle, tmr));
}

/*
 *############################################################################
 * Method Name : timerTick
 *
 * Description : This procedure moves the Timers in Timer Control Block & calls
 *               the callback method for the Timer Expired. 
 *
 * Parameters  : None
 *
 * Returns     : None
 *############################################################################
 */
void timerTick (void)
{
    /*
     * protect from the possibility of not having initialized the tcb yet
     */
    if (tcbHandle)
    {
        tcbTimerTick(tcbHandle);
    }
    return;
}

/*
 *############################################################################
 * Method Name : timerDestroy
 *
 * Description : This procedure destroys the specified Timer Control Block.
 *               All Timers are stopped and resource released.
 *
 * Parmeters   : None
 *
 * Returns     : None
 *############################################################################
 */
void timerDestroy (void)
{
	if(tcbHandle != NULL)
	{
    	tcbTimerDestroy(tcbHandle);
		tcbHandle = NULL;
	}
    return;
}

/*
 *############################################################################
 * Method Name : timerCreate
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
 * Returns     : RC_TCB_OK on success
 *               error otherwise
 *############################################################################
 */
RC_TCB_t timerCreate (unsigned int tcbSize,
                      unsigned int tcbGranularity,
                      const char   *p2name)
{
    return (tcbTimerCreate(tcbSize,
                        tcbGranularity,
                        p2name,
                        &tcbHandle));
}

#if 0
/*
 *############################################################################
 * Method Name : timerHandler
 *
 * Description : This procedure is invoked as a result of SIGALRM to drive the
 *               Timer Control Block ticks.
 *
 * Parmeters   :
 *     signum    The signal number of SIGALRM
 *
 * Returns     : None
 *############################################################################
 */
void timerHandler (void)
{
    timerTick();
}
/*
 *############################################################################
 * Method Name : timerServiceHandler
 *
 * Description : This procedure initializes the Timer Control Block & moves 
 *               Timer Tick to handle active Timers in Timer Control Block.
 *               Different application can start & stop the Timer after this
 *               procedure is called.
 *
 * Parmeters   :
 *     *param    pointer to the parameter passed
 *
 * Returns     : NULL when thread dies 
 *               otherwise None
 *############################################################################
 */
void * timerServiceHandler (void *param)
{
     struct sigaction sigAct;
     struct itimerval timerVal;

     /* Create the Timer Control Block */
     timerCreate(TCB_SIZE, TCB_RESOLUTION, "Timer Control Block");  

     /* Interval Timer Handler as signal handler for SIGALRM */
     memset (&sigAct, 0, sizeof (sigAct));
     sigAct.sa_handler = &timerHandler;
     sigaction (SIGALRM, &sigAct, NULL);

     /* Set the timer value as 1 millisecond */
     timerVal.it_value.tv_sec     = 0;
     timerVal.it_value.tv_usec    = 1000;
     timerVal.it_interval.tv_sec  = 0;
     timerVal.it_interval.tv_usec = 1000;
     
     /* Start Interval Timer */
     setitimer (ITIMER_REAL, &timerVal, NULL);

     while (1)
     {
         /* TO DO */
     }
     
     /* Delete TCB */
     timerDestroy();

     return(NULL);
}
#endif
