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
* File Name   : l1InterfaceManager.h
 *
* Description : L1-BTS interface header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/


#ifndef L1INTERFACEMANAGER_H_
#define L1INTERFACEMANAGER_H_

#include <stdlib.h>
#include "l2Scheduler.h"
#include "l1Constants.h"
#include "gsmData.h"

#include "../../../sls/inc/octvc1/gsm/octvc1_gsm_evt.h"

#include "../../../sls/inc/octsamples_pkt_api_session.h"

// Timeslot and Subslot
#define L1_CHAN2TS(chan) (chan & 7)
#define L1_CHAN2SS_SDCCH4(chan) ((chan >> 3) & 3)
#define L1_CHAN2SS_SDCCH8(chan) ((chan >> 3) & 7)

// Logical channel
#define L1_IS_LINK_SACCH(linkId) ((linkId & 0xC0) == 0x40)
#define L1_IS_CHAN_TCHF(chan) ((chan & 0xf8) == 0x08)
#define L1_IS_CHAN_TCHH(chan) ((chan & 0xf0) == 0x10)
#define L1_IS_CHAN_SDCCH4(chan) ((chan & 0xe0) == 0x20)
#define L1_IS_CHAN_SDCCH8(chan) ((chan & 0xc0) == 0x40)
#define L1_IS_CHAN_BCCH(chan) ((chan & 0xf8) == 0x80)
#define L1_IS_CHAN_RACH(chan) ((chan & 0xf8) == 0x88)
#define L1_IS_CHAN_AGCH_PCH(chan) ((chan & 0xf8) == 0x90)

// CCCH block from frame number
#define FN2CCCHBLOCK(fn) ((fn % 51) / 5 - 1)

#define MAX_UL_MEASUREMNETS	104
#define UL_M_F_L1_VALID	(1 << 0)

/*
* This structure contains application context data.
*/
typedef struct tOCTSAMPLES_APP_CTX_TAG_GSM
{
	tOCTSAMPLES_PKT_API_INFO	PktApiInfo;         /* Packet API information. */
	tOCTVC1_HANDLE_OBJECT		hGsm;
	tOCT_UINT32					ulTrxId;			/* TRX ID */
	tOCT_UINT32					ulRfPortIndex;		/* RF_PORT Index */
	tOCT_UINT32					ulTimeIndEventCount;/* Nb event to wait for ... default 500 */
	tOCT_UINT32					ulExpectedEvtId;	/* Expected Evt Id */

	tOCTVC1_GSM_TRX_ID			TrxId;				/* Trx Id */

} tOCTSAMPLES_APP_CTX_GSM, *tPOCTSAMPLES_APP_CTX_GSM, **tPPOCTSAMPLES_APP_CTX_GSM;

eLOGICAL_CHANNEL_TYPE strToLogChType(char * log_ch_type);
void timeIndHandler(tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA* msg);
void phRachIndHandler(tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA *rachInd);
int  generateSysInfoMsgs();
void deallocMem();
int  memAlloc();
void memInit();
int  activateLogicalChannel(tOCT_UINT8 ts_num , tOCT_UINT8 sub_ch);
int  deactivateLogicalChannel(tOCT_UINT8 ts_num , tOCT_UINT8 sub_ch);
tOCT_UINT8 isTimeSlotTypeSupportsSDCCH(tOCT_UINT8 tsIndx);
tOCT_UINT8 isTimeSlotTypeSupportsCombinedSDCCH(tOCT_UINT8 tsIndx);
tOCT_UINT8 isTimeSlotTypeSupportsPDTCH(tOCT_UINT8 tsIndx);
tOCT_UINT8 isTimeSlotTypeSupportsTCHH(tOCT_UINT8 tsIndx);
tOCT_UINT8 isTimeSlotTypeSupportsTCHF(tOCT_UINT8 tsIndx);
void updateRtstime(rts_time *time, tOCT_UINT32 fn);
void createAndInit2gContext(void);
void destroy2gContext(void);
#endif  //L1INTERFACEMANAGER_H_
