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
* File Name   : l2scheduler.h
 *
* Description : Layer-2 Scheduler functions header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#include "l2Scheduler.h"
#include "logManager.h"
#include "gsmData.h"


tOCT_UINT8 isTimeSlotTypeSupportsSDCCH(tOCT_UINT8 tSIndx);

pthread_mutex_t    mutexGsmChannelMgr = PTHREAD_MUTEX_INITIALIZER;

tOCT_UINT8  logicalChannels[MAX_TS][MAX_SUBCHAN_TIMESLOT];
static tOCT_UINT8  timeSlotIndx = 0 ; // Row
static tOCT_UINT8  subChannelIndx = 0; // Column
volatile signed char noOfAllocatedLogicalChannels = 0;
#if defined(FEA_SILENT_CALL) || defined(FEA_VOICE_CALL_TO_TARGET)
extern gsm_trx *   trx_g;
volatile signed char noOfAllocatedFullTrafficChannels = 0;
volatile signed char noOfAllocatedHalfTrafficChannels = 0;
#endif
#ifdef FEA_GPRS
volatile signed char noOfAllocatedPdtchChannels = 0;
static tOCT_UINT8  timeSlotIndxGprs = 0 ; // Row
static tOCT_UINT8  subChannelIndxGprs = 0; // Column
#endif

extern tOCT_UINT8 gprsRach;
tOCT_UINT8 maxSdcchChannel;
tOCT_UINT8 maxTchfChannel;
tOCT_UINT8 maxTchhChannel;
tOCT_UINT8 maxPdtchChannel;

tOCT_UINT8 allocateLogicalChannel(logicalChannelIdentity *allocated_channel)
{
    pthread_mutex_lock(&mutexGsmChannelMgr);
	tOCT_UINT8 ret_val = FALSE;

	if(noOfAllocatedLogicalChannels >= maxSdcchChannel)
	{
		logPrint(LOG_ERR, "Max Logical Channels( %d ) are already allocated\n", noOfAllocatedLogicalChannels);
	}
    else
    {
        for(; timeSlotIndx <= MAX_TS ; timeSlotIndx++)
        {
            if(timeSlotIndx == MAX_TS)
            {
                timeSlotIndx = 0;
                subChannelIndx = 0;
            }

            if(isTimeSlotTypeSupportsSDCCH(timeSlotIndx) == FALSE &&
               isTimeSlotTypeSupportsCombinedSDCCH(timeSlotIndx) == FALSE)
            {
                continue;
            }
    
            for(; subChannelIndx < MAX_SUBCHAN_TIMESLOT; subChannelIndx++)
            {
                if(( logicalChannels[timeSlotIndx][subChannelIndx] == EMPTY) &&
                   ((isTimeSlotTypeSupportsSDCCH(timeSlotIndx) == TRUE)      ||
                   ((isTimeSlotTypeSupportsCombinedSDCCH(timeSlotIndx) == TRUE) && (subChannelIndx <= 3))))
                {
                    ret_val = TRUE;
                    logicalChannels[timeSlotIndx][subChannelIndx] = FULL;
                    allocated_channel->txSLotNum = timeSlotIndx;
                    allocated_channel->subChNum = subChannelIndx;
                    noOfAllocatedLogicalChannels++;
                    logPrint(LOG_INFO, "No of Allocated Logical Channels = %d , TS = %d , SC = %d\n" ,noOfAllocatedLogicalChannels,timeSlotIndx, subChannelIndx );
                    break;
                }
            }
    
            if(ret_val == TRUE)
              break;
            else
              subChannelIndx = 0;
        }
    }    
    pthread_mutex_unlock(&mutexGsmChannelMgr);
	return ret_val;
}

void deallocateLogicalChannel(logicalChannelIdentity *deallocate_channel)
{
    pthread_mutex_lock(&mutexGsmChannelMgr);

    if(logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] != EMPTY)
    {
        logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] = EMPTY;

        noOfAllocatedLogicalChannels--;
        if(noOfAllocatedLogicalChannels <= 0)
        {
            noOfAllocatedLogicalChannels = 0;
        }
        logPrint(LOG_INFO, "deallocateLogicalChannel: No of Allocated Logical Channels = %d \n" ,noOfAllocatedLogicalChannels );
    }
    
    pthread_mutex_unlock(&mutexGsmChannelMgr);
    return;
}

#ifdef FEA_GPRS
tOCT_UINT8 allocatePdtchChannel(logicalChannelIdentity *allocated_channel)
{
  pthread_mutex_lock(&mutexGsmChannelMgr);
	tOCT_UINT8 ret_val = FALSE;

    logPrint(LOG_INFO, "Allocation for GPRS");
    
	if(noOfAllocatedPdtchChannels >= maxPdtchChannel)
	{
		logPrint(LOG_ERR, "Max PDTCH Channels( %d ) are already allocated\n", noOfAllocatedPdtchChannels);
	}
    else
    {
        for(; timeSlotIndxGprs <= MAX_TS ; timeSlotIndxGprs++)
        {
            if(timeSlotIndxGprs == MAX_TS)
            {
                timeSlotIndxGprs = 0;
                subChannelIndxGprs = 0;
            }

    		if(isTimeSlotTypeSupportsPDTCH(timeSlotIndxGprs) == FALSE)
                continue;

			for(; subChannelIndxGprs < MAX_SUBCHAN_TIMESLOT; subChannelIndxGprs++)
		    {
				if(logicalChannels[timeSlotIndxGprs][subChannelIndxGprs] == EMPTY)
			    {
					ret_val = TRUE;
					logicalChannels[timeSlotIndxGprs][subChannelIndxGprs] = FULL;
					allocated_channel->txSLotNum = timeSlotIndxGprs;
					allocated_channel->subChNum = subChannelIndxGprs;                    
                    noOfAllocatedPdtchChannels++;
                    logPrint(LOG_INFO, "No of Allocated PDTCH Channels = %d , TS = %d , SC = %d\n" ,noOfAllocatedPdtchChannels,timeSlotIndxGprs, subChannelIndxGprs );
					break;
			    }
		    }

    		if(ret_val == TRUE)
    		  break;
        else
          subChannelIndxGprs = 0;
        }
    }

    pthread_mutex_unlock(&mutexGsmChannelMgr);
    return ret_val;
}

void deallocatePdtchChannel(logicalChannelIdentity *deallocate_channel)
{
    pthread_mutex_lock(&mutexGsmChannelMgr);

    if(logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] != EMPTY)
    {
        logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] = EMPTY;
        
        noOfAllocatedPdtchChannels--;
        if(noOfAllocatedPdtchChannels <= 0)
        {
            noOfAllocatedPdtchChannels = 0;
        }
        logPrint(LOG_INFO, "deallocateLogicalChannel: No of Allocated PDTCH Channels = %d \n" ,noOfAllocatedPdtchChannels );
    }
    
    pthread_mutex_unlock(&mutexGsmChannelMgr);
    return;
}
#endif /* FEA_GPRS */


#if defined (FEA_SILENT_CALL) || defined (FEA_VOICE_CALL_TO_TARGET)
tOCT_UINT8 allocateFullTrafficChannel(logicalChannelIdentity *allocated_channel)
{
    pthread_mutex_lock(&mutexGsmChannelMgr);

    tOCT_UINT8 ret_val = FALSE;

    if(noOfAllocatedFullTrafficChannels >= maxTchfChannel)
    {
      logPrint(LOG_ERR, "Max Full Traffic Channels( %d ) are already allocated\n",noOfAllocatedFullTrafficChannels);
    }
    else
    {
       for(; timeSlotIndx <= MAX_TS ; timeSlotIndx++)
       {
           if(timeSlotIndx == MAX_TS)
               timeSlotIndx = 0;
   
           if(isTimeSlotTypeSupportsTCHF(timeSlotIndx) == FALSE)
               continue;
   
           if(logicalChannels[timeSlotIndx][0] != EMPTY)
               continue;
   
           allocated_channel->txSLotNum = timeSlotIndx;
           allocated_channel->subChNum = SUBCH0;
           logicalChannels[allocated_channel->txSLotNum][allocated_channel->subChNum] = FULL;
           noOfAllocatedFullTrafficChannels++;
           logPrint(LOG_INFO, "TCH/F Allocated, TS = %d , SC = %d\n",allocated_channel->txSLotNum, allocated_channel->subChNum );
           ret_val = TRUE;
           break;
       }
    }
    
    pthread_mutex_unlock(&mutexGsmChannelMgr);
    return ret_val;
}

void deallocateFullTrafficChannel(logicalChannelIdentity *deallocate_channel)
{
    pthread_mutex_lock(&mutexGsmChannelMgr);
    if(logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] != EMPTY)
    {
        logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] = EMPTY;

        noOfAllocatedFullTrafficChannels--;
        if(noOfAllocatedFullTrafficChannels <= 0)
        {
            noOfAllocatedFullTrafficChannels = 0;
        }
        logPrint(LOG_INFO, "deallocate Full Traffic Channel: No of Allocated Full Traffic Channels = %d \n" ,noOfAllocatedFullTrafficChannels);
    }   
    pthread_mutex_unlock(&mutexGsmChannelMgr);
}

tOCT_UINT8 allocateHalfTrafficChannel(logicalChannelIdentity *allocated_channel)
{
    pthread_mutex_lock(&mutexGsmChannelMgr);

    tOCT_UINT8 ret_val = FALSE;

    if(noOfAllocatedHalfTrafficChannels >= 2 * maxTchhChannel)
    {
         logPrint(LOG_ERR, "Max Half Traffic Channels( %d ) are already allocated\n",noOfAllocatedHalfTrafficChannels);
    }
    else
    {
        for(; timeSlotIndx <= MAX_TS ; timeSlotIndx++)
        {
            if(timeSlotIndx == MAX_TS)
                timeSlotIndx = 0;

            if(isTimeSlotTypeSupportsTCHH(timeSlotIndx) == FALSE)
                continue;

            if(logicalChannels[timeSlotIndx][0] == EMPTY)
            {
                ret_val = TRUE;
                allocated_channel->txSLotNum = timeSlotIndx;
                allocated_channel->subChNum = SUBCH0;
                logicalChannels[allocated_channel->txSLotNum][0] = FULL;
                noOfAllocatedHalfTrafficChannels++;
                logPrint(LOG_INFO, "TCH/H Allocated, TS = %d , SC = %d\n",allocated_channel->txSLotNum, allocated_channel->subChNum);
                break;
            }
            else if (logicalChannels[timeSlotIndx][1] == EMPTY)
            {
                ret_val = TRUE;
                allocated_channel->txSLotNum = timeSlotIndx;
                allocated_channel->subChNum = SUBCH1;
                logicalChannels[allocated_channel->txSLotNum][1] = FULL;
                noOfAllocatedHalfTrafficChannels++;
                logPrint(LOG_INFO, "TCH/H Allocated, TS = %d , SC = %d\n",allocated_channel->txSLotNum, allocated_channel->subChNum);
                break;
            }
            else
               continue;
        }
    }

    pthread_mutex_unlock(&mutexGsmChannelMgr);
    return ret_val;
}

void deallocateHalfTrafficChannel(logicalChannelIdentity *deallocate_channel)
{
    pthread_mutex_lock(&mutexGsmChannelMgr);
    if(logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] != EMPTY)
    {
        logicalChannels[deallocate_channel->txSLotNum][deallocate_channel->subChNum] = EMPTY;

        noOfAllocatedHalfTrafficChannels--;
        if(noOfAllocatedHalfTrafficChannels <= 0)
        {
            noOfAllocatedHalfTrafficChannels = 0;
        }
        logPrint(LOG_INFO, "deallocate Half Traffic Channel: No of Allocated Half Traffic Channels = %d \n" ,noOfAllocatedHalfTrafficChannels);
    }
    pthread_mutex_unlock(&mutexGsmChannelMgr);
}
#endif /* FEA_VOICE_CALL_TO_TARGET and FEA_SILENT_CALL */

void clearSchedulerData()
{
	timeSlotIndx = 0 ; // Row
	subChannelIndx = 0; // Column
	noOfAllocatedLogicalChannels = 0;    
#if defined (FEA_SILENT_CALL) || defined (FEA_VOICE_CALL_TO_TARGET)
	noOfAllocatedFullTrafficChannels = 0;
    noOfAllocatedHalfTrafficChannels = 0;
#endif
	memset(logicalChannels , 0 , MAX_TS*MAX_SUBCHAN_TIMESLOT);
}
