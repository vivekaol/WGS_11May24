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
* File Name   : l1InterfaceManager.c
 *
* Description : L1-BTS interface & message conversion
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <assert.h>
#include <signal.h>
#include "l1Constants.h"
#include "l1InterfaceManager.h"
#include "gsmData.h"
#include "sysInfo.h"
#include "lapdm.h"
#include "ratSocketItf.h"
#include "dataIndMsgHandler.h"

#ifdef FEA_GPRS
#include "gprs.h"
#endif

#include "rtsTxMsgHandler.h"
#include "linkedlist.h"
#include "userManager.h"
#include "l2Scheduler.h"
#include "logManager.h"
#include "slsDecode2g.h"
#include "transactionMemoryManager.h"
#include "oct_l1cIoInit.h"


#define CCCH_LOGICAL_CHANNEL 0
#define TIMER_FOR_RACH_HANDLING 3000 // 3000ms

// Globals
gsm_trx * trx_g = NULL;
gsm_time * gsm_time_g = NULL;
rts_time * rts_time_g = NULL;
rts_time * rts_time_gprs = NULL;

signed int usf[8] = {-1,-1,-1,-1,-1,-1,-1, -1};
extern stateDataInd dataIndRcvdstate;
//extern tOCT_UINT8 timerTickReceived ;
//extern pthread_cond_t      condTimerTickInd  ;
//extern pthread_mutex_t     mutexTimerTickInd ;
static tOCT_UINT8 timerTickSignalGenerateCounter = 0;
queue dataIndQ ;
listNode *headForChanAllocationQ = NULL;
listNode *tailForChanAllocationQ = NULL;
tOCT_UINT32 l1StatusCounter = 0;
extern tOCTSAMPLES_APP_CTX_GSM g_AppCtxGsm;
extern tOCT_UINT8 usf_frame[GSM_MACBLOCK_LEN];
#ifdef FEA_VOICE_CALL_TO_TARGET
extern callContext targetVoiceCallCntxt;
#endif

extern fxLGpsLocation idCatcherGpsLoc;
extern fxLGpsFixType  idCatcherGpsFix;

extern tOCT_UINT8 maxPdtchChannel;

extern void transactionMemoryManagerInit();
extern int LogicalChanActivate( tOCTVC1_GSM_LOGICAL_CHANNEL_ID f_LchId );
extern int LogicalChanDeactivate( tOCTVC1_GSM_LOGICAL_CHANNEL_ID f_LchId );
#ifdef FEA_GPRS
extern gprsInfo* gprsAdd(logicalChannelIdentity * ch_id);
#endif

tOCT_UINT8 gprsRach = FALSE;

// Immediate assignment buffer
const tOCT_UINT8 const immAssgnAcc[GSM_MACBLOCK_LEN]=
{
    0x2D, 0x06, 0x3F, 0x03, 0x41, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x00, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B
};

// Immediate assignment Reject buffer
const tOCT_UINT8 const immAssgnRej[GSM_MACBLOCK_LEN]=
{
    0x4D, 0x06, 0x3A, 0x00, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B
};

extern tOCT_UINT8 rrlpGpsAssistData[RRLP_TOTAL_SEGMENTS][RRLP_GPS_ASSIST_OCTET_LEN][GSM_MACBLOCK_LEN - 2];

#ifdef FEA_GPRS
/* Immediate assignment buffer GPRS
06 0000....   Skip Indicator = 0
   ....0110   Protocol Discriminator = 6 :RR Message
3F 00111111    Message Type = 63 :Immediate Assignment
                Immediate Assignment:
                 (3GPP TS44.018 9.1.18)
                 Dedicated mode or TBF:
                  (3GPP TS44.018 10.5.2.25b)
10 0.......       Spare bit = 0
   .001....       TMA, DL and T/D = 1 :Uplink TBF, or 2nd of two MSGs for Upink or Downlink TBF
   ....00..      Spare bits = 00b
   ......00      Page Mode = 0 :Normal Paging
                 Packet Channel Description:
                  (3GPP TS44.018 10.5.2.25a)
0A 00001...       CHANNEL_TYPE = 1
   .....010       TN = 2
02 000.....       TSC = 0
   ...0....       FR Value type = 0 :ARFCN or MAIO MA
   ....0...        Hopping = 0 :Non hopping
   .....0..         Spare bit = 0
   ......10         ARFCN = 650
8A 10001010
                 Request Reference:
                  (3GPP TS44.018 10.5.2.30)
7C 01111100       Random Access Info = 124
2A 00101...       T1' = 5
   .....010       T3 = 17
32 001.....
   ...10010       T2 = 18
                 Timing Advance:
                  (3GPP TS44.018 10.5.2.40)
00 00000000       TIMING_ADVANCE = 0
                 Mobile Allocation:
                  (3GPP TS44.018 10.5.2.21)
00 00000000       Length of Mobile Allocation = 0 byte
                 Starting Time (IEI=7Ch):Absent
                 IA Rest Octet:
                  (3GPP TS44.018 10.5.2.16)
C8 11......       Content Type = 3 :Packet Assignment etc.
   ..00....        Assignment type = 0 :Packet Uplink Assignment
                    Packet Uplink Assignment:
   ....1...          Block Type = 1 :non-Single Block Allocation
   .....000           TFI_ASSIGNMENT = 0
00 00......
   ..0.....           POLLING = 0
   ...0....           Spare Bits = 0b
   ....000.           USF = 000b
   .......0           USF_GRANULARITY = 0 :one RLC/MAC block
10 0.......           P0/PR_MODE = 0 :Absent
   .00.....           CHANNEL_CODING_COMMAND = 0 :CS-1
   ...1....           TLLI_BLOCK_CHANNEL_CODING = 1 :MS shall use CHANNEL_CODING_COMMAND
   ....0...           ALPHA = 0 :Absent
   .....000           Gamma = 0 :0dB
0A 00......
   ..0.....           TIMING_ADVANCE_INDEX = 0 :Absent
   ...0....           TBF Starting Time = 0 :Absent
   ....1...          Additions in release 99 = 1b: L :Absent
   .....0..          Addition in Rel-6 = 0b: L :Absent
   ......1.        Addition in Rel-10 = 1b: L :Absent
                 Extended TSC Set (IEI=6Dh):Absent
   .......0  Spare Bits = 0b
*/
const tOCT_UINT8 const immAssgnAccGprs[GSM_MACBLOCK_LEN]=
{
    0xFD, 0x06, 0x3F, 0x10, 0x0A, 0x02, 0x8A, 0x7C, 0x2A, 0x32,
    0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2B,
    0x2B, 0x2B, 0x2B
};

tOCT_UINT8 usf_frame_tmp[GSM_MACBLOCK_LEN]=
{
    0x00, 0x94, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2B
};
#endif

const tOCT_UINT8 chanSubslots[] = 
{
	[EMPTY_CHANNEL]                     = 0,
    [eMAX_LOGICAL_CHANNEL_TYPE]         = 0,
    [FCCH_SCH_BCCH_CCCH]                = 0,
    [FCCH_SCH_BCCH_CCCH_SDCCH4_SACCHC4] = 4,
    [SDCCH8_SACCHC8]                    = 8,
	[TCHF_FACCHF_SACCHTF]               = 1,
	[TCHH_FACCHH_SACCHTH]               = 2,
	[PDTCHF_PACCHF_PTCCHF]              = 0,
};

// Allocate global memeory
int memAlloc()
{
    trx_g = malloc(sizeof(gsm_trx));
    if(trx_g == NULL)
    {
        exit(1);
    }

    gsm_time_g = malloc(sizeof(gsm_time));
    if(gsm_time_g == NULL)
    {
        exit(1);
    }

    rts_time_g = malloc(sizeof(rts_time));
    if(rts_time_g == NULL)
    {
        exit(1);
    }
#ifdef FEA_GPRS
    rts_time_gprs = malloc(sizeof(rts_time));
    if(rts_time_gprs == NULL)
    {
        exit(1);
    }
#endif

    allocateDataIndBuffer();
    allocateTxDataBuffer();
    allocatePageRachBuffer();
#ifdef FEA_GPRS
    allocateGprsDataIndBuffer();
    allocateTxGprsBuffer();
#endif
    return 0;
}

// De-Allocate Global memory
void deallocMem()
{
	listNode *qNode = NULL;
	if(trx_g != NULL)
	{
		free(trx_g);
		trx_g = NULL;
	}
	if(gsm_time_g != NULL)
	{
		free(gsm_time_g);
		gsm_time_g = NULL;
	}
	if(rts_time_g != NULL)
	{
		free(rts_time_g);
		rts_time_g = NULL;
	}
    deallocateDataIndBuffer();
    deallocateTxDataBuffer();
    deallocatePageRachBuffer();

#ifdef FEA_GPRS
    deallocateGprsDataIndBuffer();
	deallocateGprsTxDataBuffer();
#endif

    clearSchedulerData();
    cleanPagingQ();

    if(headForChanAllocationQ != NULL)
    {
      qNode = popMsgFromList(&headForChanAllocationQ );
    }

    while(qNode != NULL)
    {
      free(qNode);
      qNode = NULL;
      if(headForChanAllocationQ != NULL)
      {
        qNode = popMsgFromList(&headForChanAllocationQ );
    }
    }
    tailForChanAllocationQ = headForChanAllocationQ = NULL;
}

// initialize Global memory
void memInit()
{
    memset(trx_g, 0, sizeof(gsm_trx));
    
    int i;
    for(i=0; i<MAX_TS; i++)
    {
        trx_g->ts[i].ts_num = i;
        trx_g->ts[i].lchan  = EMPTY_CHANNEL;
    }

    trx_g->bts.cell_sel_par.rxlev_acc_min = 0;
    trx_g->bts.cell_sel_par.cell_resel_hyst = 7; //2 ; // 4dB
    trx_g->bts.cell_sel_par.neci = 1;
    trx_g->bts.cell_sel_par.acs = 0;
    trx_g->bts.cell_sel_par.ms_txpwr_max_ccch = 0; //ms_power_control(bts->band, 40);

    trx_g->bts.opt_cell_sel_par.parameter_present = 1;
    trx_g->bts.opt_cell_sel_par.cell_bar_qualify = 0;
    trx_g->bts.opt_cell_sel_par.cell_reselect_offset = 32;
    trx_g->bts.opt_cell_sel_par.temp_offset = 0;
    trx_g->bts.opt_cell_sel_par.penalty_time = 0;

    trx_g->bts.rach_ctrl_par.re        = 1; // no re-establishment
    trx_g->bts.rach_ctrl_par.cell_bar  = 0;
    trx_g->bts.rach_ctrl_par.tx_int    = 0x0E; // 32 we can try to increase time between retransmission
    trx_g->bts.rach_ctrl_par.max_trans = 3; // max transmissions 7

    trx_g->bts.radio_link_timeout = (32 >> 2) - 1;
    trx_g->bts.t3212 = 1; /* 6 min periodic update interval as default */
    trx_g->bts.ta_filter_start = 0;
    trx_g->bts.ta_filter_stop  = 63;
    trx_g->bts.access_class_list = 0;
    trx_g->bts.blockReservedForAgch = 1;
    trx_g->bts.pagingPeriodicity = 5;
	
    trx_g->bts.neigh_list.nbr_of_arfcns = 0;
    for(i=0; i<GERAN_ARFCN_LIST_LENGTH; i++)
    {
        trx_g->bts.neigh_list.arfcns[i] = END_OF_LIST;
    }

    trx_g->bts.neigh_ca_list.nbr_of_arfcns = 0;
    for(i=0; i<SIZE_OF_HOPPING_LIST; i++)
    {
        trx_g->bts.neigh_ca_list.arfcns[i] = END_OF_LIST;
    }
    
#ifdef FEA_2G_SEND_SMS_DURING_REGISTRATION
    trx_g->bts.sendSmsDuringRegistration = FALSE;
#endif

    initQueue(&dataIndQ);
	l1StatusCounter = 0;
    dataIndRcvdstate = STATE_DATAIND_NOT_RECEIVED;
//    timerTickReceived = FALSE;
    timerTickSignalGenerateCounter = 0;

#ifdef FEA_VOICE_CALL_TO_TARGET
    memset(&targetVoiceCallCntxt, 0, sizeof(callContext));
    targetVoiceCallCntxt.moTsNum   = 0xFF;
    targetVoiceCallCntxt.moSubChan = 0xFF;
    targetVoiceCallCntxt.mtTsNum   = 0xFF;
    targetVoiceCallCntxt.mtSubChan = 0xFF;
#endif

    memset(rrlpGpsAssistData, 0 , sizeof(rrlpGpsAssistData));
    buildAndEncodeRrlpGpsAssistanceData(rrlpGpsAssistData, idCatcherGpsFix, idCatcherGpsLoc);
}

// Map BAND type to Octasic type
eBands numToOctasicBand(int band)
{
        switch (band)
    {
        case 450:
                return GSM_450;
        case 850:
                return GSM_850;
        case 900:
                return GSM_900;
        case 1800:
                return DCS_1800;
        case 1900:
                return PCS_1900;
        default:
                return -EINVAL;
        }
};

tOCT_UINT8 isTimeSlotTypeSupportsTCHF(tOCT_UINT8 tsIndx)
{
    if(trx_g->ts[tsIndx].lchan != TCHF_FACCHF_SACCHTF)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

tOCT_UINT8 isTimeSlotTypeSupportsTCHH(tOCT_UINT8 tsIndx)
{
    if(trx_g->ts[tsIndx].lchan != TCHH_FACCHH_SACCHTH)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

tOCT_UINT8 isTimeSlotTypeSupportsPDTCH(tOCT_UINT8 tsIndx)
{
    if(trx_g->ts[tsIndx].lchan != PDTCHF_PACCHF_PTCCHF)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


int activateLogicalChannel(tOCT_UINT8 ts_num , tOCT_UINT8 sub_ch)
{
    // Logical channel activate for Octasic BTS
#ifndef NDEBUG
    assert(ts_num < MAX_TS);
#else
	if(ts_num >= MAX_TS)
	{
		logPrint(LOG_ERR, "activateLogicalChannel: ts_num >= MAX_TS\n");
		exit(1);
	}
#endif

    tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

    tOCTVC1_GSM_SAPI_ENUM tchTxSapi[3];
    tOCTVC1_GSM_SAPI_ENUM tchRxSapi[3];

    if(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE)
    {
       tchTxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHH;
       tchTxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHH;
       tchTxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;

       tchRxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHH;
       tchRxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHH;
       tchRxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;
    }
    else
    {
       tchTxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHF;
       tchTxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHF;
       tchTxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;

       tchRxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHF;
       tchRxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHF;
       tchRxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;
    }

    tOCTVC1_GSM_SAPI_ENUM aTxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_SACCH,
    		                            cOCTVC1_GSM_SAPI_ENUM_SDCCH };
    tOCTVC1_GSM_SAPI_ENUM aRxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_SACCH,
                                        cOCTVC1_GSM_SAPI_ENUM_SDCCH };

	tOCT_UINT32 j;

#ifdef FEA_GPRS

    tOCTVC1_GSM_SAPI_ENUM gprsTxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_PDTCH};
    tOCTVC1_GSM_SAPI_ENUM gprsRxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_PDTCH};

  if(isTimeSlotTypeSupportsPDTCH(ts_num) == TRUE)
   {
    LchId.byTimeslotNb = ts_num;
    LchId.bySubChannelNb = sub_ch;
    LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_TX_BTS_MS;
    LchId.bySAPI= gprsTxSapi[0];

    if (0 != LogicalChanActivate( LchId ))
    {
      return 1;
    }

    LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_RX_BTS_MS;
    LchId.bySAPI= gprsRxSapi[0];

    if (0 != LogicalChanActivate( LchId ))
    {
      return 1;
    }
		return 0;
   }
#endif

	/* Activate Tx logical channel */
	for( j=0; j< (((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))?sizeof( tchTxSapi ):sizeof( aTxSapi )); j++ )
	{
		LchId.byTimeslotNb = ts_num;
		LchId.bySubChannelNb = sub_ch;
		LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_TX_BTS_MS;
		if((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))
          LchId.bySAPI= tchTxSapi[j];
		else
          LchId.bySAPI= aTxSapi[j];

		if (0 != LogicalChanActivate( LchId ))
		{
			return 1;
		}
	}

	/* Activate Rx logical channel */
	for( j=0; j< (((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))?sizeof( tchRxSapi ):sizeof( aRxSapi )); j++ )
	{
		LchId.byTimeslotNb = ts_num;
		LchId.bySubChannelNb = sub_ch;
		LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_RX_BTS_MS;
		if((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))
          LchId.bySAPI= tchRxSapi[j];
		else
	      LchId.bySAPI= aRxSapi[j];

		if (0 != LogicalChanActivate( LchId ))
		{
			return 1;
		}
	}

    return 0;
}

int deactivateLogicalChannel(tOCT_UINT8 ts_num , tOCT_UINT8 sub_ch)
{
    // Logical channel de-activate for Octasic BTS
#ifndef NDEBUG
    assert(ts_num < MAX_TS);
    assert(sub_ch != SUBCHF);
//    assert(ts_num != 0);
#else
	if(ts_num >= MAX_TS)
	{
		logPrint(LOG_ERR, "deactivateLogicalChannel: ts_num >= MAX_TS\n");
		exit(1);
	}
	if(sub_ch == SUBCHF)
	{
		logPrint(LOG_ERR, "deactivateLogicalChannel: sub_ch == SUBCHF\n");
		exit(1);
	}
#endif

    tOCTVC1_GSM_LOGICAL_CHANNEL_ID	LchId;

    tOCTVC1_GSM_SAPI_ENUM tchTxSapi[3];
    tOCTVC1_GSM_SAPI_ENUM tchRxSapi[3];

    if(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE)
    {
       tchTxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHH;
       tchTxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHH;
       tchTxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;

       tchRxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHH;
       tchRxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHH;
       tchRxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;
    }
    else
    {
       tchTxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHF;
       tchTxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHF;
       tchTxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;

       tchRxSapi[0] = cOCTVC1_GSM_SAPI_ENUM_TCHF;
       tchRxSapi[1] = cOCTVC1_GSM_SAPI_ENUM_FACCHF;
       tchRxSapi[2] = cOCTVC1_GSM_SAPI_ENUM_SACCH;
    }                

    tOCTVC1_GSM_SAPI_ENUM aTxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_SACCH,
    		                            cOCTVC1_GSM_SAPI_ENUM_SDCCH };
    tOCTVC1_GSM_SAPI_ENUM aRxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_SACCH,
                                        cOCTVC1_GSM_SAPI_ENUM_SDCCH };

	tOCT_UINT32 j;

#ifdef FEA_GPRS

    tOCTVC1_GSM_SAPI_ENUM gprsTxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_PDTCH};
    tOCTVC1_GSM_SAPI_ENUM gprsRxSapi[] = { cOCTVC1_GSM_SAPI_ENUM_PDTCH};

  if(isTimeSlotTypeSupportsPDTCH(ts_num) == TRUE)
   {
    LchId.byTimeslotNb = ts_num;
    LchId.bySubChannelNb = sub_ch;
    LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_TX_BTS_MS;
    LchId.bySAPI= gprsTxSapi[0];

    if (0 != LogicalChanDeactivate( LchId ))
    {
      return 1;
    }

    LchId.bySAPI= gprsRxSapi[0];
    LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_RX_BTS_MS;

    if (0 != LogicalChanDeactivate( LchId ))
    {
      return 1;
    }
		return 0;
   }
#endif


	/* Deactivate Tx logical channel */
	for( j=0; j< (((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))?sizeof( tchTxSapi ):sizeof( aTxSapi )); j++ )
	{
		LchId.byTimeslotNb   = ts_num;
		LchId.bySubChannelNb = sub_ch;

		LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_TX_BTS_MS;
		if((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))
		  LchId.bySAPI= tchTxSapi[j];
		else
		  LchId.bySAPI= aTxSapi[j];

		if (0 != LogicalChanDeactivate( LchId ))
		{
			return 1;
		}
	}

	/* Deactivate Rx logical channel */
	for( j=0; j< (((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))?sizeof( tchRxSapi ):sizeof( aRxSapi )); j++ )
	{
        LchId.byTimeslotNb = ts_num;
        LchId.bySubChannelNb = sub_ch;

		LchId.byDirection = cOCTVC1_GSM_DIRECTION_ENUM_RX_BTS_MS;
		if((isTimeSlotTypeSupportsTCHF(ts_num) == TRUE)||(isTimeSlotTypeSupportsTCHH(ts_num) == TRUE))
		  LchId.bySAPI= tchRxSapi[j];
		else
	      LchId.bySAPI= aRxSapi[j];

		if (0 != LogicalChanDeactivate( LchId ))
		{
			return 1;
		}
	}

    return 0;
}

int generateSysInfoMsgs()
{
	gsm_bts *bts;
    int ret = 0, i = 0;
#ifndef NDEBUG
	assert(trx_g != NULL);
#else
	if(trx_g == NULL)
	{
		logPrint(LOG_ERR, "generateSysInfoMsgs: trx_g == NULL\n");
		exit(1);
	}
#endif
    bts = &trx_g->bts;
    generate_si1(bts->si1_buf, trx_g);
    ret = generate_si2(bts->si2_buf, bts);
    generate_si3(bts->si3_buf, bts);

#ifdef FEA_2G_INTER_RAT_MEAS
    generate_si2q();
#endif

#ifdef FEA_GPRS
	if(maxPdtchChannel)
	  generate_si13(bts->si13_buf, bts);
#endif

    generate_si4(bts->si4_buf, bts);

    logPrint(LOG_INFO, "System Information Buffers Updated...");
    logPrint(LOG_INFO, "SI-1     = %s", gsmL3PduHexdump(bts->si1_buf, 23));
    logPrint(LOG_INFO, "SI-2     = %s", gsmL3PduHexdump(bts->si2_buf, 23));
#ifdef FEA_2G_INTER_RAT_MEAS
    for(i = 0; i < trx_g->bts.noOfValidSi2qInstances; i++)
      logPrint(LOG_INFO, "SI-2q[%d] = %s", i, gsmL3PduHexdump(&bts->si2q_buf[i][0], 23));
#endif
    logPrint(LOG_INFO, "SI-3     = %s", gsmL3PduHexdump(bts->si3_buf, 23));
    logPrint(LOG_INFO, "SI-4     = %s", gsmL3PduHexdump(bts->si4_buf, 23));
#ifdef FEA_GPRS
    logPrint(LOG_INFO, "SI-13    = %s", gsmL3PduHexdump(bts->si13_buf, 23));
#endif

    return ret;
}

void updateGsmtime(gsm_time *time, tOCT_UINT32 fn)
{
    if(time != NULL)
    {
        time->fn = fn;
        time->t1 = time->fn / (26*51);
        time->t2 = time->fn % 26;
        time->t3 = time->fn % 51;
        time->tc = (time->fn / 51) % 8;
    }
}

void updateRtstime(rts_time *time, tOCT_UINT32 fn)
{
    if(time != NULL)
    {
        time->fn = fn;
        time->t1 = time->fn / (26*51);
        time->t2 = time->fn % 26;
        time->t3 = time->fn % 51;
        time->tc = (time->fn / 51) % 8;
    }
}

// Map logical channel type from config file to Octasic Logical channel type
eLOGICAL_CHANNEL_TYPE strToLogChType(char * str)
{
    if(strcmp(str, "NONE")==0)
    return EMPTY_CHANNEL;

    else if(strcmp(str, "CCCH")==0)
    return FCCH_SCH_BCCH_CCCH;

    else if(strcmp(str, "CCCH+SDCCH4")==0)
    return FCCH_SCH_BCCH_CCCH_SDCCH4_SACCHC4;

    else if(strcmp(str, "SDCCH8")==0)
    return SDCCH8_SACCHC8;

    else if(strcmp(str, "TCH/F")==0)
    return TCHF_FACCHF_SACCHTF;

    else if(strcmp(str, "TCH/H")==0)
    return TCHH_FACCHH_SACCHTH;

    else if(strcmp(str, "PDTCH")==0)
    return PDTCHF_PACCHF_PTCCHF;

    else
    return EMPTY_CHANNEL;

};
/* 3GPP TS 44.018 - 10.5.2.5 */
void getChanDescforImmediateAssginment(userInfo* userInfo, tOCT_UINT8* ChanDesc)
{

    tOCT_UINT8 tn, sc;
    tOCT_UINT8 hoppingFlag = 0, spareFlag = 0;

    tn = userInfo->userLogicalChannel.txSLotNum;
    sc = userInfo->userLogicalChannel.subChNum;

    if(trx_g->ts[tn].lchan == TCHF_FACCHF_SACCHTF)
      ChanDesc[0] = (0x01 << 3) | tn ;

    else if(trx_g->ts[tn].lchan == TCHH_FACCHH_SACCHTH)
      ChanDesc[0] = (0x01 << 4) | (sc << 3) | tn ;

    else if(trx_g->ts[tn].lchan == FCCH_SCH_BCCH_CCCH_SDCCH4_SACCHC4)
      ChanDesc[0] = (0x01 << 5) | (sc << 3) | tn ;

    else if(trx_g->ts[tn].lchan == SDCCH8_SACCHC8)
      ChanDesc[0] = (0x01 << 6) | (sc << 3) | tn ;

#ifdef FEA_GPRS
		gprsInfo  *info = (gprsInfo*)(userInfo);
    tn = info->userLogicalChannel.txSLotNum;
    sc = info->userLogicalChannel.subChNum;
    if(trx_g->ts[tn].lchan == PDTCHF_PACCHF_PTCCHF)
      ChanDesc[0] = (0x01 << 3) | tn ;
#endif
    else
    {}

	ChanDesc[1] = (trx_g->bts.tsc << 5) | (hoppingFlag << 4) | (spareFlag << 2) | (trx_g->arfcn >> 8);
	ChanDesc[2] = trx_g->arfcn & 0xFF;

	return;
}

tOCT_UINT8 isTimeSlotTypeSupportsSDCCH(tOCT_UINT8 tsIndx)
{
	if(trx_g->ts[tsIndx].lchan != SDCCH8_SACCHC8)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

tOCT_UINT8 isTimeSlotTypeSupportsCombinedSDCCH(tOCT_UINT8 tsIndx)
{           
    if(trx_g->ts[tsIndx].lchan != FCCH_SCH_BCCH_CCCH_SDCCH4_SACCHC4)
    {   
        return FALSE;
    }   
    else
    {       
        return TRUE;
    }           
}


void preparePushImmediateAssignmentRejecttoRTSQ(tOCT_UINT8* racht1t2t3)
{
	listNode *tail = tailForChanAllocationQ;
	tOCT_UINT8* immAssgnRejBuf = (tOCT_UINT8*)getPageRachBuffer();
#ifndef NDEBUG
	assert(immAssgnRejBuf != NULL);
#else
	if(immAssgnRejBuf == NULL)
	{
		logPrint(LOG_ERR, "preparePushImmediateAssignmentRejecttoRTSQ: immAssgnRejBuf == NULL\n");
		exit(1);
	}
#endif
	memcpy(immAssgnRejBuf,  immAssgnRej, GSM_MACBLOCK_LEN); // Copy standard message

    // Fill Request Reference(RR) 1 and Wait Indication(WI) 1 values. Octets:4-7
	immAssgnRejBuf[4] = racht1t2t3[0];
	immAssgnRejBuf[5] = racht1t2t3[1];
	immAssgnRejBuf[6] = racht1t2t3[2];
    // Wait time: T3122- set to 5 seconds.
	immAssgnRejBuf[7] = 60;//5;
    // Copy the RR 1 and WI 1 values to RR and WI - 2,3,4.
    memcpy(&(immAssgnRejBuf[8]),  &(immAssgnRejBuf[4]), 4);
    memcpy(&(immAssgnRejBuf[12]), &(immAssgnRejBuf[4]), 4);
    memcpy(&(immAssgnRejBuf[16]), &(immAssgnRejBuf[4]), 4);

	pushMsgToList(&tail ,(void*)immAssgnRejBuf);
	if((headForChanAllocationQ == NULL)||(tailForChanAllocationQ == NULL))
	{
		headForChanAllocationQ = tailForChanAllocationQ = tail; // Update for the first time
	}
	else
	{
		tailForChanAllocationQ = tail; // Just update the tail node
	}
	logPrint(LOG_DEBUG , "preparePushImmediateAssignmentRejecttoRTSQ \n ");
	return;
}

void preparePushImmediateAssignmentAccepttoRTSQ(userInfo* userInfo)
{
	listNode *tail = tailForChanAllocationQ;
	tOCT_UINT8* immAssgnAccBuf = (tOCT_UINT8*)getPageRachBuffer(); //malloc(sizeof(sndrcvMsg));
#ifndef NDEBUG
	assert(immAssgnAccBuf != NULL);
#else
	if(immAssgnAccBuf == NULL)
	{
		logPrint(LOG_ERR, "preparePushImmediateAssignmentAccepttoRTSQ: immAssgnAccBuf == NULL\n");
		exit(1);
	}
#endif
	memcpy(immAssgnAccBuf,  immAssgnAcc, GSM_MACBLOCK_LEN); // Copy standard message

	// Filling Channel Description IE Bytes 4,5,6
	getChanDescforImmediateAssginment(userInfo , &immAssgnAccBuf[4]);
	immAssgnAccBuf[7] = userInfo->lapdmParam[0];
	immAssgnAccBuf[8] = userInfo->lapdmParam[1];
	immAssgnAccBuf[9] = userInfo->lapdmParam[2];

    /* Timing Advance */
    immAssgnAccBuf[10] = userInfo->initialMeasReport.timingAdvance;

	pushMsgToList(&tail ,(void*)immAssgnAccBuf);
	if((headForChanAllocationQ == NULL)||(tailForChanAllocationQ == NULL))
	{
		headForChanAllocationQ = tailForChanAllocationQ = tail; // Update for the first time
	}
	else
	{
		tailForChanAllocationQ = tail; // Just update the tail node
	}
	logPrint(LOG_DEBUG , "preparePushImmediateAssignmentAccepttoRTSQ \n ");
	return;
}


tOCT_UINT8 tsSubslots(gsm_ts *ts)
{
	return chanSubslots[ts->lchan];
}

/* Measurment reporting period and mapping of SACCH message block for TCHF and TCHH chan
  * As per in 3GPP TS 45.008, secton 8.4.1. 
  *
  * Timeslot number (TN)                                    TDMA frame number (FN) modulo 104
  *
  *    Full Rate        Half rate, subch.0          Half rate, subch.1             Reporting period       SACCH Message block
  *    0                0 and 1                                                    0 to 103               12, 38, 64, 90
  *    1                                             0 and 1                       13 to 12               25, 51, 77, 103
  *    2                2 and 3                                                    26 to 25               38, 64, 90, 12
  *    3                                             2 and 3                       39 to 38               51, 77, 103, 25
  *    4                4 and 5                                                    52 to 51               64, 90, 12, 38
  *    5                                             4 and 5                       65 to 64               77, 103, 25, 51
  *    6                6 and 7                                                    78 to 77               90, 12, 38, 64
  *    7                                             6 and 7                       91 to 90               103, 25, 51, 77
  */

/* measurement period ends at fn % 104 == ? */
/* Added (-1) offset in DATA-IND frame number to align with Meas period ends */
static const tOCT_UINT8 tchFmeasRepFn104[] = 
{
    [0] =   103 - 1,
    [1] =   12 - 1,
    [2] =   25 - 1,
    [3] =   38 - 1,
    [4] =   51 - 1,
    [5] =   64 - 1,
    [6] =   77 - 1,
    [7] =   90 - 1,
};

/* Added (-2) offset in DATA-IND frame number to align with Meas period ends */
static const uint8_t tchH0measRepFn104[] = 
{
    [0] =   103 - 2,
    [1] =   103 - 2,
    [2] =   25 - 2,
    [3] =   25 - 2,
    [4] =   51 - 2,
    [5] =   51 - 2,
    [6] =   77 - 2,
    [7] =   77 - 2,
};

/* Added (-1) offset in DATA-IND frame number to align with Meas period ends */
static const uint8_t tchH1measRepFn104[] = 
{
    [0] =   12 - 1,
    [1] =   12 - 1,
    [2] =   38 - 1,
    [3] =   38 - 1,
    [4] =   64 - 1,
    [5] =   64 - 1,
    [6] =   90 - 1,
    [7] =   90 - 1,
};

/* Measurment reporting period for SDCCH8 and SDCCH4 chan
  * As per in 3GPP TS 45.008, secton 8.4.2. 
  *
  * Logical Chan         TDMA frame number
  *                            (FN) modulo 102
  *
  * SDCCH/8            12 to 11
  * SDCCH/4            37 to 36 
  */

/* Added interleve offset to Meas period end Fn which would reduce the Meas Res msg load at Abis*/

static const uint8_t sdcch8MeasRepFn102[] =
{
    [0] =   11 + 7,
    [1] =   11 + 11, 
    [2] =   11 + 15,
    [3] =   11 + 19,
    [4] =   11 + 23, 
    [5] =   11 + 27,
    [6] =   11 + 31,
    [7] =   11 + 35
};

static const uint8_t sdcch4MeasRepFn102[] =
{
    [0] =   36 + 4,
    [1] =   36 + 8, 
    [2] =   36 + 14,
    [3] =   36 + 18 
};


int isMeasComplete(tOCT_UINT8 tn, tOCT_UINT8 sc, tOCT_UINT32 fn)
{
    tOCT_UINT32 fnMod = -1;
    const tOCT_UINT8 *tbl;
    int retVal = 0;

    if (tn >= 8)
        return -1;

    if (trx_g->ts[tn].lchan >= eMAX_LOGICAL_CHANNEL_TYPE)
        return -1;

    switch (trx_g->ts[tn].lchan) 
    {
        case TCHF_FACCHF_SACCHTF:
        {
            fnMod = fn % 104;
            
            if(tchFmeasRepFn104[tn] == fnMod)
              retVal = 1;
        }
        break;

        case TCHH_FACCHH_SACCHTH:
        {
            fnMod = fn % 104;

            if(sc == 0)
              tbl = tchH0measRepFn104;
            else
              tbl = tchH1measRepFn104;

            if(tbl[tn] == fnMod)
              retVal = 1;
        }
        break;

        case SDCCH8_SACCHC8:
        {
            fnMod = fn % 102;

            if(sdcch8MeasRepFn102[sc] == fnMod)
              retVal = 1;
        }
        break;

        case FCCH_SCH_BCCH_CCCH_SDCCH4_SACCHC4:
        {
            fnMod = fn % 102;

            if(sdcch4MeasRepFn102[sc] == fnMod)
              retVal = 1;
        }
        break;

        default:
        {
            retVal = 0;
        }
        break;
    }
    //logPrint(LOG_DEBUG, "Status of Meas-Period-End : retVal = %d for chan = %u, TS = %u, SC = %u, FN = %u, FN_MOD = %u\n", retVal, trx_g->ts[tn].lchan, tn, sc, fn, fnMod);
    
    return retVal;
}

void updateNewTA(userInfo* info, tOCT_INT32 taSum)
{
    tOCT_INT32 msTimingOffset = 0;
    tOCT_INT8  l1InfoValid;

    l1InfoValid = info->l1MeasFlag & UL_M_F_L1_VALID;

    if(l1InfoValid)
    {   
        msTimingOffset = taSum + (info->initialMeasReport.timingAdvance - info->newTimingAdvance);

        if(msTimingOffset > 0)
        {
            if(info->newTimingAdvance < 63)
            {
                /*MS is moving away from BTS. So increment Ordered TA by 1*/
                info->newTimingAdvance++; 
                
                logPrint(LOG_DEBUG,"User = %p : TA updated, Timing-Offset = %d, New-TA = %d", info, msTimingOffset, info->newTimingAdvance);
            }
        }
        else if(msTimingOffset < 0)
        {
            if(info->newTimingAdvance > 0)
            {
                /*MS is moving toward BTS. So decrement Ordered TA by 1*/
                info->newTimingAdvance--;
                
                logPrint(LOG_DEBUG,"User = %p : TA updated, Timing-Offset = %d, New-TA = %d", info, msTimingOffset, info->newTimingAdvance);
            }
        }
        else
        {
            /*MS is not moving so don't change Ordered TA*/
        }        
    }
    
    else
    {
        /*Do Nothing*/
    }

    /*Clear L1 INFO valid flag at Meas period end*/
    info->l1MeasFlag &= ~UL_M_F_L1_VALID;
    
    return;
}

int lchanMeasCheck(tOCT_INT8 tn, tOCT_INT8 sc, userInfo* info, tOCT_UINT32 fn)
{
    tOCT_INT32 taOffsetSum          = 0;
    tOCT_INT32 taOffsetQbitsSum     = 0;
    tOCT_INT32 ulRssiSum            = 0;
    tOCT_INT32 ulSnrSum             = 0;

    int i;
    
    /* if measurement period is not complete, abort */
    if (!isMeasComplete(tn, sc, fn))
        return 0;

    /* if there are no measurements, skip computation */
    if (info->noOfUlMeasurements == 0)
        return 0;

    /* compute the actual measurements */

    /* Average */
    for (i = 0; i < info->noOfUlMeasurements; i++)
    {
        taOffsetSum      += info->taOffset[i];
        taOffsetQbitsSum += info->taOffsetQbits[i];
        ulRssiSum  += info->ulRssi[i];
        ulSnrSum   += info->ulSnr[i];
    }

    taOffsetSum            = taOffsetSum / info->noOfUlMeasurements;
    taOffsetQbitsSum       = taOffsetQbitsSum / info->noOfUlMeasurements;
    info->ulRssiAvg        = (tOCT_UINT8) ulRssiSum / info->noOfUlMeasurements;
    info->ulSnrAvg         = (tOCT_INT16) ulSnrSum / info->noOfUlMeasurements;

    /*Update ordered TA for DL SACCH L1 Header*/
    updateNewTA(info, taOffsetSum);

    /* Update the TA-Qbits for the measurement period */
    if((info->measReport.timingAdvanceQbits + taOffsetQbitsSum) <= 0)
    {
        /* TA-Qbits can't be negative  */
        info->measReport.timingAdvanceQbits = 0;
    }
    else
    {
        /* TA-Qbits could only vary by 4 values within one measurement period */
        if(taOffsetQbitsSum > -4 && taOffsetQbitsSum < 4 )
          info->measReport.timingAdvanceQbits += taOffsetQbitsSum;
        else if(taOffsetQbitsSum < -4)
          info->measReport.timingAdvanceQbits -= 4;
        else if(taOffsetQbitsSum > 4)
          info->measReport.timingAdvanceQbits += 4;
    }

    if(info->measReport.timingAdvanceQbits > 124)
      info->measReport.timingAdvanceQbits = 124;
 
    info->noOfUlMeasurements = 0;

    /* Indicate computation is complete */
    return 1;
}

int tsMeasCheck(gsm_ts *ts, tOCT_UINT32 fn)
{
	int i;
	const int noOfSubslots = tsSubslots(ts);

	for (i = 0; i < noOfSubslots; ++i)
    {
        userInfo* info = NULL;
        logicalChannelIdentity ch_id;

		switch (ts->lchan)
        {
            case SDCCH8_SACCHC8:
            case TCHF_FACCHF_SACCHTF:
            case TCHH_FACCHH_SACCHTH:
            {
                ch_id.txSLotNum = ts->ts_num;
                ch_id.subChNum  = i;
                
                info = userFindUsingLogicalChannel(&ch_id);
                if(info == NULL)
                  continue;

    			lchanMeasCheck(ts->ts_num, i, info, fn);
            }
            break;

            default:
              break;
		}
	}
	return 0;
}

/* To be called every TDMA frame */
int trxMeasCheck(tOCT_UINT32 fn)
{
    int i;

    for (i = 0; i < 8; i++) 
    {
        tsMeasCheck(&trx_g->ts[i], fn);
    }
    return 0;
}


#ifdef FEA_GPRS

void preparePushGPRSImmediateAssignmentAccepttoRTSQ(gprsInfo* uInfo)
{
	listNode *tail = tailForChanAllocationQ;
	tOCT_UINT8* immAssgnAccBuf = (tOCT_UINT8*)getPageRachBuffer(); //malloc(sizeof(sndrcvMsg));
	tOCT_UINT32 tlli = 0;
	signed char i,j=0;
#ifndef NDEBUG
	assert(immAssgnAccBuf != NULL);
#else
	if(immAssgnAccBuf == NULL)
	{
		logPrint(LOG_ERR, "preparePushGPRSImmediateAssignmentAccepttoRTSQ: immAssgnAccBuf == NULL\n");
		exit(1);
	}
#endif

	memcpy(immAssgnAccBuf,  immAssgnAccGprs, GSM_MACBLOCK_LEN); // Copy standard message
	// Filling Channel Description IE Bytes 4,5,6
	getChanDescforImmediateAssginment((userInfo*)(uInfo), &immAssgnAccBuf[4]);
	immAssgnAccBuf[7] = uInfo->lapdmParam[0];
	immAssgnAccBuf[8] = uInfo->lapdmParam[1];
	immAssgnAccBuf[9] = uInfo->lapdmParam[2];
/*
D8 11......       Content Type = 3 :Packet Assignment etc.
   ..01....        Assignment type = 1 :Packet Downlink Assignment
                    Packet Downlink Assignment:
   ....1000          TLLI/G-RNTI = 80010080h
00 00000000
10 00010000
08 00001000
08 0000....
   ....1...          TFI_ASSIGNMENT/RLC_MODE etc. = 1 :Present
   .....000           TFI_ASSIGNMENT = 0
00 00......
   ..0.....           RLC_MODE = 0 :RLC acknowledged mode
   ...0....           Alpha = 0 :Absent
   ....0000           Gamma = 0 :0dB
42 0.......
   .1......           POLLING = 1
   ..0.....           TA_VALID = 0 :not valid
   ...0....          TIMING_ADVANCE_INDEX = 0 :Absent
   ....0...          TBF_STARTING_TIME = 0 :Absent
   .....0..          P0/PR_MODE = 0 :Absent
   ......1.          Additions in release 99 = 1b: L :Absent
   .......0  Spare Bits = 0b
*/

	if(!gprsRach)	//Sending PDA
	{
		j=12;
		immAssgnAccBuf[j] = 0xD0;		//Set MsgType PDA
		
	 for(i = 3; i >= 0 ; i--)
     {
      tlli |= (tOCT_UINT32)(uInfo->userTlli[i] << ((3-i)*8));
     }
  	immAssgnAccBuf[j++] |= (tOCT_UINT8)((tlli & 0xF0000000) >> 28);
  	immAssgnAccBuf[j++] |= (tOCT_UINT8)((tlli & 0x0FF00000) >> 20);
  	immAssgnAccBuf[j++] |= (tOCT_UINT8)((tlli & 0x000FF000) >> 12) ;
  	immAssgnAccBuf[j++] |= (tOCT_UINT8)((tlli & 0x00000FF0) >> 4) ;
  	immAssgnAccBuf[j++] |= ((tOCT_UINT8)(tlli & 0x0000000F) << 4) ;

		immAssgnAccBuf[16] |= (0x01 << 3);
		immAssgnAccBuf[17] = 0x00;
		immAssgnAccBuf[18] = 0x70;
		immAssgnAccBuf[19] = 0x20;
		logPrint(LOG_INFO,"0x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x", immAssgnAccBuf[0],immAssgnAccBuf[1],immAssgnAccBuf[2],immAssgnAccBuf[3],
												immAssgnAccBuf[4],immAssgnAccBuf[5],immAssgnAccBuf[6],immAssgnAccBuf[7],immAssgnAccBuf[8],immAssgnAccBuf[9],immAssgnAccBuf[10],
												immAssgnAccBuf[11],immAssgnAccBuf[12],immAssgnAccBuf[13],immAssgnAccBuf[14],immAssgnAccBuf[15],immAssgnAccBuf[16],immAssgnAccBuf[17],
												immAssgnAccBuf[18]);
	}
	else
	{
		immAssgnAccBuf[12] |= ((uInfo->tfi & 0x1F) >> 2);
		immAssgnAccBuf[13] |= ((uInfo->tfi & 0x03) << 6);
		immAssgnAccBuf[13] |= (uInfo->usf << 1) & 0x0E;
	}
		//memcpy(usf_frame_tmp, usf_frame,GSM_MACBLOCK_LEN);
		usf_frame_tmp[0] = (uInfo->usf & 0x07) | 0x40;
	
	pushMsgToList(&tail ,(void*)immAssgnAccBuf);
	if((headForChanAllocationQ == NULL)||(tailForChanAllocationQ == NULL))
	{
		headForChanAllocationQ = tailForChanAllocationQ = tail; // Update for the first time
	}
	else
	{
		tailForChanAllocationQ = tail; // Just update the tail node
	}
	logPrint(LOG_DEBUG , "preparePushGPRSImmediateAssignmentAccepttoRTSQ");
	gprsRach = FALSE;
	return;
}

#if 0
// Function queue paging request to paging queue
void pushGprsPagingReqToPageQ(blackListedUserInfo* info, gprsInfo *uInfo)
{
	listNode *tail = NULL;
	tOCT_UINT8* sndMsg = (tOCT_UINT8*)getPageRachBuffer(); //malloc(sizeof(sndrcvMsg));
	tOCT_UINT32 tlli = 0;
	signed char i,j=0;
#ifndef NDEBUG
	assert(sndMsg != NULL);
#else
	if(sndMsg == NULL)
	{
		logPrint(LOG_ERR, "pushPagingReqToPageQ: sndMsg == NULL\n");
		exit(1);
	}
#endif

#ifndef NDEBUG
	assert(info->pagingMultiFrame < BS_PA_MRFMS);
	assert(info->pagingBlockIndex < (MAX_PAGING_BLOCKS_IN_51_FRAME - BS_AG_BLKS_RES));
#else
	if(info->pagingMultiFrame >= BS_PA_MRFMS)
	{
		logPrint(LOG_ERR, "pushPagingReqToPageQ: info->pagingMultiFrame >= BS_PA_MRFMS\n");
	}
	if(info->pagingBlockIndex >= (MAX_PAGING_BLOCKS_IN_51_FRAME - BS_AG_BLKS_RES))
	{
		logPrint(LOG_ERR, "pushPagingReqToPageQ: info->pagingGroup >= (MAX_PAGING_BLOCKS_IN_51_FRAME - BS_AG_BLKS_RES)\n");
	}
    exit(1);
#endif

	memcpy(sndMsg, immAssgnAccGprs , GSM_MACBLOCK_LEN); // Copy standard message
	getChanDescforImmediateAssginment((userInfo*)uInfo, &sndMsg[4]);
	sndMsg[7] = uInfo->lapdmParam[0];
	sndMsg[8] = uInfo->lapdmParam[1];
	sndMsg[9] = uInfo->lapdmParam[2];
/*
D8 11......       Content Type = 3 :Packet Assignment etc.
   ..01....        Assignment type = 1 :Packet Downlink Assignment
                    Packet Downlink Assignment:
   ....1000          TLLI/G-RNTI = 80010080h
00 00000000
10 00010000
08 00001000
08 0000....
   ....1...          TFI_ASSIGNMENT/RLC_MODE etc. = 1 :Present
   .....000           TFI_ASSIGNMENT = 0
00 00......
   ..0.....           RLC_MODE = 0 :RLC acknowledged mode
   ...0....           Alpha = 0 :Absent
   ....0000           Gamma = 0 :0dB
42 0.......
   .1......           POLLING = 1
   ..0.....           TA_VALID = 0 :not valid
   ...0....          TIMING_ADVANCE_INDEX = 0 :Absent
   ....0...          TBF_STARTING_TIME = 0 :Absent
   .....0..          P0/PR_MODE = 0 :Absent
   ......1.          Additions in release 99 = 1b: L :Absent
   .......0  Spare Bits = 0b
*/

	if(!gprsRach)	//Sending PDA
	{
		j=12;
		sndMsg[j] = 0xD0;		//Set MsgType PDA
		
	 for(i = 3; i >= 0 ; i--)
     {
      tlli |= (tOCT_UINT32)(uInfo->userTlli[i] << ((3-i)*8));
     }
  	sndMsg[j++] |= (tOCT_UINT8)((tlli & 0xF0000000) >> 28);
  	sndMsg[j++] |= (tOCT_UINT8)((tlli & 0x0FF00000) >> 20);
  	sndMsg[j++] |= (tOCT_UINT8)((tlli & 0x000FF000) >> 12) ;
  	sndMsg[j++] |= (tOCT_UINT8)((tlli & 0x00000FF0) >> 4) ;
  	sndMsg[j++] |= ((tOCT_UINT8)(tlli & 0x0000000F) << 4) ;

		sndMsg[16] |= (0x01 << 3);
		sndMsg[17] = 0x00;
		sndMsg[18] = 0x70;
		sndMsg[19] = 0x20;
		logPrint(LOG_INFO,"0x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x_%x", sndMsg[0],sndMsg[1],sndMsg[2],sndMsg[3],
												sndMsg[4],sndMsg[5],sndMsg[6],sndMsg[7],sndMsg[8],sndMsg[9],sndMsg[10],
												sndMsg[11],sndMsg[12],sndMsg[13],sndMsg[14],sndMsg[15],sndMsg[16],sndMsg[17],
												sndMsg[18]);
	}

    pthread_mutex_lock(&mutexPagingQ);
	tail = tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex];

	pushMsgToList(&tail ,(void*)sndMsg);
	if((headForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] == NULL)||(tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] == NULL))
	{
		headForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] = tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] = tail; // Update for the first time
	}
	else
	{
		tailForPagingReqQ[info->pagingMultiFrame][info->pagingBlockIndex] = tail; // Just update the tail node
	}
    pthread_mutex_unlock(&mutexPagingQ);

    logPrint(LOG_DEBUG, "Paging is sent on P-MF = %d, PB = %d for Blacklist User = %p, IMSI = %s", \
                                                                  info->pagingMultiFrame, info->pagingBlockIndex,\
                                                                  info, info->userImsi_str);
 return;
}
#endif
#endif


void timeIndHandler(tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA* time_ind)
{
    tOCT_UINT32 fn;

    fn = time_ind->ulFrameNumber;

    // Update our data structures with the current GSM time
    if(gsm_time_g != NULL)
    updateGsmtime(gsm_time_g, fn);

    timerTickSignalGenerateCounter++;
	if(timerTickSignalGenerateCounter == TCB_RESOLUTION_2G/5) // 100 ms Tick comes every 4.67ms
	{
	    l1StatusCounter++;
	    if(l1StatusCounter == 0xFFFFFFFF)
	    {
	    	l1StatusCounter = 0;
	    }

		timerTickSignalGenerateCounter = 0;
        timerTick();
	}
    
    trxMeasCheck(fn);

    return ;
}

void phRachIndHandler(tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA *rachInd)
{
    tOCT_UINT32 fn;
    tOCT_UINT8 t1prime;
    logicalChannelIdentity allocated_channel = {0};
    userInfo* userInfo = NULL;
    tOCT_UINT8 racht1t2t3[3] = {0};
	tOCT_UINT8 *abyMsg = (tOCT_UINT8*)((tOCT_UINT8*)rachInd + sizeof(tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA));

#ifdef FEA_GPRS
    gprsInfo* gprsInfo = NULL;
#endif

    fn = rachInd->ulFrameNumber;

    if (rachInd->ulMsgLength != 1)
    {
        return;
    }

    racht1t2t3[0] = abyMsg[0];
    logPrint(LOG_INFO, "RACH IND Received, Rach Byte = 0x%02x  \n" , racht1t2t3[0]);

    updateRtstime(rts_time_g, fn);
    // compute T1prime
    t1prime = rts_time_g->t1 % 32;
    racht1t2t3[1] = (t1prime << 3) | (rts_time_g->t3 >> 3);
    racht1t2t3[2] = (rts_time_g->t3 << 5) | rts_time_g->t2;

    if( ((((racht1t2t3[0] & 0xF0)>>4) == 0) /* LAU */            ||
     	 (((racht1t2t3[0] & 0xF0)>>4) == 4) /* MO Call TCH/H */  ||
     	 (((racht1t2t3[0] & 0xE0)>>5) == 7) /* MO Call TCH/F */  ||
     	 (((racht1t2t3[0] & 0xE0)>>5) == 4) /* Paging Response */||
     	 (((racht1t2t3[0] & 0xF0)>>4) == 1) /* Others which need SDCCH, IMSI Detach, SMS ... */
#ifdef FEA_EMER
     	 || (((racht1t2t3[0] & 0xE0)>>5) == 5) /* Emergency Call */ 
#endif
#ifdef FEA_GPRS
     	 || (((racht1t2t3[0])>>3) == 0x0f) /* GPRS*/ 
#endif
			 ))
    {
        if((((racht1t2t3[0])>>3) == 0x0f) /* GPRS*/)
          gprsRach = TRUE;

    	// First allocate logical channel for this user if it failed then reject the immediate assignment
    	if((!gprsRach && allocateLogicalChannel(&allocated_channel) == TRUE)
#ifdef FEA_GPRS
          || (gprsRach && allocatePdtchChannel(&allocated_channel) == TRUE)
#endif
          )
    	{
    		// Add this user to our database
    		if(!gprsRach)
            {      
    			userInfo = userAdd(&allocated_channel);
            }
			else
			{
#ifdef FEA_GPRS
    			gprsInfo = gprsAdd(&allocated_channel);
#endif
			}
#ifdef FEA_GPRS
            if(gprsRach)
            {
                int i = allocated_channel.subChNum;
                gprsInfo->usf = allocated_channel.subChNum;
                gprsInfo->tfi = gprsInfo->usf;
                usf[i] = 0;
                logPrint(LOG_DEBUG,"User = %p :USF: %d TFI: %d",gprsInfo,gprsInfo->usf,gprsInfo->tfi);
                // Store the Random reference value
                gprsInfo->lapdmParam[0] = racht1t2t3[0];
                gprsInfo->lapdmParam[1] = racht1t2t3[1];
                gprsInfo->lapdmParam[2] = racht1t2t3[2];
                gprsInfo->userState = PDTCH_CHANNEL_ALLOCATED;
                preparePushGPRSImmediateAssignmentAccepttoRTSQ(gprsInfo);

                tOCT_UINT8 retVal = timerStart(&gprsInfo->tmr , TIMER_FOR_RACH_HANDLING , 0 , &gprsInfoTimerCbFunction, gprsInfo);
                assert(retVal == RC_TCB_OK);

                logPrint(LOG_DEBUG , "User = %p : Logical Channels are ACTIVATED for the PDTCH TS=%d , SubChan=%d" ,
                											 gprsInfo , allocated_channel.txSLotNum , allocated_channel.subChNum);
                return;
            }
#endif

            // Store the Random reference value
    		userInfo->lapdmParam[0] = racht1t2t3[0];
            userInfo->lapdmParam[1] = racht1t2t3[1];
            userInfo->lapdmParam[2] = racht1t2t3[2];

            if (rachInd->MeasurementInfo.sBurstTiming< 0)
               userInfo->initialMeasReport.timingAdvance = 0;
            else
               userInfo->initialMeasReport.timingAdvance = rachInd->MeasurementInfo.sBurstTiming;

            /* Update the timing advance value to be sent to the UE in SACCH */
            userInfo->newTimingAdvance = userInfo->initialMeasReport.timingAdvance;
            
            if (rachInd->MeasurementInfo.sBurstTiming4x< 0)
               userInfo->initialMeasReport.timingAdvanceQbits = 0;
            else
               userInfo->initialMeasReport.timingAdvanceQbits = rachInd->MeasurementInfo.sBurstTiming4x;

            if(((racht1t2t3[0] & 0xF0)>>4) == 0) /* LAU */
            {
                userInfo->userTmsi[5] = racht1t2t3[1];
                userInfo->userTmsi[4] = racht1t2t3[0];
        	    userInfo->userTmsi[3] = 0x23;
                userInfo->userTmsi[2] = racht1t2t3[2];
            
        	    userInfo->userTmsi[1] = 0xF4; // Identity type: TMSI
        	    userInfo->userTmsi[0] = 0x05; // Length of Identity
            }

#ifdef FEA_EMER
     	 if(((racht1t2t3[0] & 0xE0)>>5) == 5) /* Emergency Call */ 
          {
          userInfo->emergency_service_req = TRUE;
    	    logPrint(LOG_DEBUG ,"Emergency Service req received in rach");
          }
#endif
            activateLogicalChannel(allocated_channel.txSLotNum , allocated_channel.subChNum);

			userInfo->userState = SDCCH_CHANNEL_ALLOCATED;
			preparePushImmediateAssignmentAccepttoRTSQ(userInfo);
			logPrint(LOG_DEBUG , "User = %p : All Logical Channels are ACTIVATED for the SDCCH and SACCH , TimeSlot = %d , SubChannel = %d\n" , userInfo , allocated_channel.txSLotNum , allocated_channel.subChNum);

            tOCT_UINT8 retVal = timerStart(&userInfo->tmr , TIMER_FOR_RACH_HANDLING , 0 , &userInfoTimerCbFunction, userInfo);
            assert(retVal == RC_TCB_OK);
    	}
    	else
    	{
    	    logPrint(LOG_ERR , "Cannot Allocate any Logical Channel Sending Reject for \n");
    		// Send immediate assignment reject
    		preparePushImmediateAssignmentRejecttoRTSQ(racht1t2t3);
            gprsRach = FALSE;
    	}
    }
   else
    {
        // Send Immediate Assignment Reject for all RACH requests other than LA.
	   logPrint(LOG_ERR , "Sending Immediate Assignment Reject for RACH, Rach Byte = 0x%02x  \n" , racht1t2t3[0]);
	   preparePushImmediateAssignmentRejecttoRTSQ(racht1t2t3);
    }
    return ;
}

void phMeasReportHandler(userInfo * info, tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA* data_ind)
{
    if(info->noOfUlMeasurements < MAX_UL_MEASUREMNETS)
    {
        /* Update Timing offset for valid radio block*/
        if(data_ind->Data.ulDataLength != 0)
        {
            info->taOffset[info->noOfUlMeasurements]      = data_ind->MeasurementInfo.sBurstTiming;   /* burst timing in 1x */
            info->taOffsetQbits[info->noOfUlMeasurements] = data_ind->MeasurementInfo.sBurstTiming4x; /* burst timing in 4x */
        }
        else
        {
            info->taOffset[info->noOfUlMeasurements]       = 0;
            info->taOffsetQbits[info->noOfUlMeasurements]  = 0;
        }

        info->ulRssi[info->noOfUlMeasurements] = (tOCT_UINT8) ((data_ind->MeasurementInfo.sRSSIDbm >> 8) * -1); /* RSSI is in Q8 Format */
        info->ulSnr[info->noOfUlMeasurements]  = (tOCT_INT16) (data_ind->MeasurementInfo.sSNRDb >> 8);          /* SNR is in Q8 Format */

        info->noOfUlMeasurements++;
    }

    return ;
}


void createAndInit2gContext(void)
{
    // Allocate global memory
    memAlloc();
    // Initialize global memory
    memInit();
    // Initialize User Manager
    userManagerInit();
    // Initialize Transaction Memory Manager
    transactionMemoryManagerInit();

    // Initialize SysLog 
    // Same file used for 2G,3G,LTE. So moved init to main and Exit moved to signal handler
    logManagerInit();

    logPrint(LOG_INFO,"############################################################################\n");
    logPrint(LOG_INFO,"*\n");
    logPrint(LOG_INFO,"*                             gsmIDCatcher\n");
    logPrint(LOG_INFO,"*\n");
    //logPrint(LOG_INFO,"*       (c) FXLynx Technologies Ltd. 2015, All Rights Reserved\n");
    //logPrint(LOG_INFO,"*\n");
    logPrint(LOG_INFO,"############################################################################\n");
	pthread_mutex_init(&timerMutexLock, NULL);
    if(timerCreate(TCB_SIZE_2G, TCB_RESOLUTION_2G , "Timer Control Block") !=0)
    {
       logPrint(LOG_ERR , "Timer Creation FAILED for 2G\n");
       exit(1);
    }

}

void destroy2gContext(void)
{
    deallocMem();
    timerDestroy();
	pthread_mutex_destroy(&timerMutexLock);
    transactionMemoryManagerClose();
    logManagerExit();
}
