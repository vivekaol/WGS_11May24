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
* File Name   : lteMacScheduler.c
 *
* Description : Lte Mac Scheduler functions header
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------------
* 11/10/2014          				  Anand Kashikar			   Initial File Creation
*#############################################################################################
*/

#include <string.h>
#include <arpa/inet.h>
#include "lteMacScheduler.h"
#include "logManager.h"
#include "linkedlist.h"
#include "rawSocketApi.h"
#include "oct_ltefapimacphyinterface.h"
#include "lteL1IfApi.h"
#include "lteAsn1IntfcHandler.h"
#include "linkedlist.h"
#include "lteMacIntfcHandler.h"

uint8 lteRvArr[4] = {0,2,3,1};
//uint8 lteTddRvArr[6] = {0,2,-1,-1,3,-1,1};
uint8 rvIdx = 0;
uint8 lteSib1TxStarted = FALSE;
uint8 lteMibTxStarted = FALSE;
uint8 pdcchMib[64] = {0};
uint8 txDataMib[64] = {0};
uint8 pdcchSib1[128] = {0};
uint8 txDataSib1[96] = {0};
uint8 pdcchMibSibs[128] = {0};
uint8 txDataMibSibs[160] = {0};
uint8 pdcchSibs[128] = {0};
uint8 txDataSibs[128] = {0};
uint8 dummyDlConfig[64] = {0};
/*
Uplink-downlink 
configuration	Downlink-to-Uplink 
Switch-point periodicity	Subframe number
		  	0	1	2	3	4	5	6	7	8	9
0	5 ms	D	S	U	U	U	D	S	U	U	U
1	5 ms	D	S	U	U	D	D	S	U	U	D
2	5 ms	D	S	U	D	D	D	S	U	D	D
3	10 ms	D	S	U	U	U	D	D	D	D	D
4	10 ms	D	S	U	U	D	D	D	D	D	D
5	10 ms	D	S	U	D	D	D	D	D	D	D
6	5 ms	D	S	U	U	U	D	S	U	U	D
*/
//uint8 ULDL[10] =  {0,2,1,1,0,0,2,1,1,0};
const uint16 ULDL[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER] =    {	
																	{0,2,1,1,1,0,2,1,1,1},
																	{0,2,1,1,0,0,2,1,1,0},
																	{0,2,1,0,0,0,2,1,0,0},
																	{0,2,1,1,1,0,0,0,0,0},
																	{0,2,1,1,0,0,0,0,0,0},
																	{0,2,1,0,0,0,0,0,0,0},
																	{0,2,1,1,1,0,2,1,1,0},
															     };
const uint16 lteTddGrant[LTE_TDD_MAX_UD_CONFIG][LTE_MAX_SUB_FRAME_NUMBER] = {
																		{4,6,0,0,0,4,6,0,0,0},
																		{0,6,0,0,4,0,6,0,0,4},
																		{0,0,0,4,0,0,0,0,4,0},
																		{4,0,0,0,0,0,0,0,4,4},
																		{0,0,0,0,0,0,0,0,4,4},
																		{0,0,0,0,0,0,0,0,4,0},
																		{0,7,7,0,0,7,7,0,0,5},
																		};
extern uint8 rlcDataIndHandler();
extern void checkAndPushTDDPagingReqToDlSchedulerQ(uint16 sfn , uint8 sbfn);
extern elteDupMode lteDuplxMode ;
extern uint8 skipNextTxDataReq;
extern uint8 *hiDci0ReqPtr;
extern volatile int  exitLteApp;
extern void buildAndSendUlDci0ReqForContinuesGrant(uint16 sfNsf , uint8* msgBuf);
extern listNode *headForLteMacUlSchedulerQ[LTE_MAX_SUB_FRAME_NUMBER];
extern listNode *tailForLteMacUlSchedulerQ[LTE_MAX_SUB_FRAME_NUMBER];
extern eLteBw lteSelectedBandwidth;
extern uint16 bwToPrb[MAX_BANDWIDTH];
extern uint16 dlRivArr[MAX_BANDWIDTH][MAX_NO_DOWNLINK_GRANTS];
#ifdef FXL_4G_TX_JAMMER
extern int lteJamCellFound ;
#endif
void buildPdcchPacketForMib(uint16 sfn , uint8 sbfn);
void buildTxDataPacketForMib(uint16 sfn , uint8 sbfn);
void buildPdcchPacketForSib1(uint16 sfn , uint8 sbfn);
void buildTxDataPacketForSib1(uint16 sfn , uint8 sbfn);
void buildPdcchPacketForMibSibs(uint16 sfn , uint8 sbfn);
void buildTxDataPacketForMibSibs(uint16 sfn , uint8 sbfn);
void buildPdcchPacketForSibs(uint16 sfn , uint8 sbfn);
void buildTxDataPacketForSibs(uint16 sfn , uint8 sbfn);

#define MIB_PREPARATION_SUBFRAME 6
#define SIB1_PREPARATION_SUBFRAME 1

void scheduleDummyUlConfigReq(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = getBufferFordummyUlconfigReq();
	memset(msgBuf , 0 , 64);
	tOCT_FAPI_UL_CONFIG_REQUEST *ulConfigReq = (tOCT_FAPI_UL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	uint8 prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX;

	if (lteDuplxMode)
	{
		prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX_TDD;
		if((prachConfigIndex == 3) && (sbfn== 2))
		{
			ulConfigReq->byRachFreqResources = 1; // TDD-RACH
		}
		else if((prachConfigIndex == 0) && (sbfn == 2) &&  ((sfn % 2) == 0)) 
		{
			ulConfigReq->byRachFreqResources = 1; // TDD-RACH
		}
		else if((prachConfigIndex == 2) && (sbfn == 2)) 
		{
			ulConfigReq->byRachFreqResources = 1; // TDD-RACH
		}
		else
		{
			ulConfigReq->byRachFreqResources = 0; // TDD-RACH			
		}

	}
	else
	{
		if((prachConfigIndex == 2) && (sbfn == 7) && ((sfn % 2) == 0)) // Prach index = 2
		{
			ulConfigReq->byRachFreqResources = 1; // FDD-RACH
		}
		else if ((prachConfigIndex == 3) && (sbfn == 1))
		{
			ulConfigReq->byRachFreqResources = 1; // FDD-RACH
		}
		else
		{
			ulConfigReq->byRachFreqResources = 0; // FDD-RACH
		}
	}
	ulConfigReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	ulConfigReq->usUlConfigLen = htons(SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE);
	//Rest of elements are set to zero with memset done inside getDlTxDataBuffer

	buildAndSendPhyUlConfigReq(msgBuf , SIZE_TOCT_FAPI_UL_CONFIG_REQUEST_BASE);
}

void scheduleDummyDlConfigReq(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = dummyDlConfig;
	//memset(msgBuf , 0 , 64);
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

	dlConfigReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	if(lteDuplxMode)
	{
		if ((sbfn == 1) || (sbfn == 6)) // for special subframe : CFI is 1 or 2  
		dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH_TDD ;
		else
		dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH;			
	}
	else
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ;
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	dlConfigReq->usLength = htons(SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE);

	buildAndSendPhyDlConfigReq(msgBuf , SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE);
}


void lteScheduleMib(uint16 sfn)
{
	uint8 *dlConfig = getDlConfigBuffer();
	uint8 *txData =  getDlTxDataBuffer();

	if((sfn % LTE_SIBS_REPITITION_FRAMES) == 0)
	{
		memcpy(dlConfig , pdcchMibSibs , 128);
		memcpy(txData , txDataMibSibs , 160);
		pushToDlConfigReqQ(((sfn<<4)|LTE_MIB_SUBFRAME_LOCATION), dlConfig);
		pushToTxDataReqQ(((sfn<<4)|LTE_MIB_SUBFRAME_LOCATION), txData);
	}

	{
		memcpy(dlConfig , pdcchMib , 64);
		memcpy(txData , txDataMib , 64);
		pushToDlConfigReqQ(((sfn<<4)|LTE_MIB_SUBFRAME_LOCATION), dlConfig);
		pushToTxDataReqQ(((sfn<<4)|LTE_MIB_SUBFRAME_LOCATION), txData);
	}

	// Create packet for next occasion
	sfn = (sfn + LTE_MIB_REPITION_FRAMES)%LTE_MAX_SYSTEM_FRAME_NUMBER;
	if((sfn % LTE_SIBS_REPITITION_FRAMES) == 0)
	{
		buildPdcchPacketForMibSibs(sfn ,LTE_MIB_SUBFRAME_LOCATION);
		buildTxDataPacketForMibSibs(sfn ,LTE_MIB_SUBFRAME_LOCATION);
	}
	else if((sfn % LTE_MIB_REPITION_FRAMES) == 0)
	{
		buildPdcchPacketForMib(sfn ,LTE_MIB_SUBFRAME_LOCATION);
		buildTxDataPacketForMib(sfn ,LTE_MIB_SUBFRAME_LOCATION);
	}
	else
	{}

}

void lteScheduleSib1(uint16 sfn)
{
	uint16 sfnSf = ((sfn<<4)|(LTE_SIB1_SUBFRAME_LOCATION));

	uint8 *dlConfig =  getDlConfigBuffer();
	uint8 *txData =  getDlTxDataBuffer();
	memcpy(dlConfig , pdcchSib1 , 128);
	memcpy(txData , txDataSib1 , 96);
	pushToDlConfigReqQ(sfnSf , dlConfig);
	pushToTxDataReqQ(sfnSf , txData);
	// Create packet for next occasion
	sfn = (sfn + LTE_SIB1_REPITION_FRAMES) % LTE_MAX_SYSTEM_FRAME_NUMBER;
	buildPdcchPacketForSib1(sfn , LTE_SIB1_SUBFRAME_LOCATION);
	buildTxDataPacketForSib1(sfn , LTE_SIB1_SUBFRAME_LOCATION);
}

void lteScheduleSibs(uint16 sfn)
{
	uint8 *dlConfig =  getDlConfigBuffer();
	uint8 *txData =  getDlTxDataBuffer();

	memcpy(dlConfig , pdcchSibs , 128);
	memcpy(txData , txDataSibs , 128);
	pushToDlConfigReqQ(((sfn<<4)|LTE_MIB_SUBFRAME_LOCATION), dlConfig);
	pushToTxDataReqQ(((sfn<<4)|LTE_MIB_SUBFRAME_LOCATION), txData);

	// Create packet for next occasion
	sfn = (sfn + LTE_SIBS_REPITITION_FRAMES)%LTE_MAX_SYSTEM_FRAME_NUMBER;
	buildPdcchPacketForSibs(sfn ,LTE_MIB_SUBFRAME_LOCATION);
	buildTxDataPacketForSibs(sfn ,LTE_MIB_SUBFRAME_LOCATION);
	return;
}

void checkAndScheduleBcchInDlBins(uint16 nextSfn , uint8 nextsbfn)
{
	nextSfn = (nextSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;
	if(nextsbfn == SIB1_PREPARATION_SUBFRAME) // Set next Sib1 on subframe = 9
	{
		if((nextSfn % LTE_SIB1_REPITION_FRAMES) == 0)
		{
			if(lteSib1TxStarted == TRUE)
			{
				lteScheduleSib1(nextSfn);
			}
			else
			{
				if(nextSfn == 8)
				{
					lteScheduleSib1(nextSfn);
					lteSib1TxStarted = TRUE ;
				}
			}
		}
	}
	else if(nextsbfn == MIB_PREPARATION_SUBFRAME) // Set MIB/SIBS on subframe = 4
	{
		nextSfn = (nextSfn + 1) % LTE_MAX_SYSTEM_FRAME_NUMBER;

		if((nextSfn % LTE_SIBS_REPITITION_FRAMES)==0)
		{
			lteScheduleSibs(nextSfn);
		}
	}
	else
	{}
}

void lteMacScheduler(uint16 nextSfn , uint8 nextSbfn)
{
	listNode* qNode = NULL;
	uint8 *sndMsg = NULL , pduSent = FALSE;
	uint16 sfNsf = ((nextSfn<<4)|(nextSbfn & 0x0F));

#ifdef FXL_4G_TX_JAMMER
    if (lteJamCellFound )
	{
		scheduleDummyDlConfigReq(nextSfn , nextSbfn);
		scheduleDummyUlConfigReq(nextSfn , nextSbfn);
		return;
	}
#endif
	/// Downlink
	if((sndMsg = popFromDlConfigReqQ(sfNsf)) != NULL)
	{
		if(SocketApp_Send4g(sndMsg) == -1)
		{
			logPrint(LOG_ERR,"Send Failed-1 for SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
		}
		sndMsg = NULL;

		if((sndMsg = popFromTxDataReqQ(sfNsf)) != NULL)
		{
			if(SocketApp_Send4g(sndMsg) == -1)
			{
				logPrint(LOG_ERR,"Send Failed-2 for SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
			}
			sndMsg = NULL;
			pduSent = TRUE;
		}

	}
	else
	{
		scheduleDummyDlConfigReq(nextSfn , nextSbfn);
	}
	// Uplink
	sndMsg = NULL;
	if((headForLteMacUlSchedulerQ[nextSbfn] != NULL) && ((qNode = popMsgFromList( &headForLteMacUlSchedulerQ[nextSbfn]))!= NULL))
	{
		sndMsg = (uint8*) qNode->msg;
		if(SocketApp_Send4g(sndMsg) == -1)
		{
			logPrint(LOG_ERR,"Send Failed-3 for SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
		}
		free(qNode);
		qNode = NULL;

		headForLteMacUlSchedulerQ[nextSbfn] = NULL;
		tailForLteMacUlSchedulerQ[nextSbfn] = NULL;

	}
	else
	{
		scheduleDummyUlConfigReq(nextSfn , nextSbfn); //Need to send always
	}

	if(pduSent == FALSE)
	{
		buildAndSendUlDci0ReqForContinuesGrant(sfNsf , hiDci0ReqPtr);
	}
	else
	{
		if(hiDci0ReqPtr != NULL)
		{
			if(SocketApp_Send4g(hiDci0ReqPtr) == -1)
			{
				logPrint(LOG_ERR,"Send Failed-3 for SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
			}
		}
	}
	hiDci0ReqPtr = NULL;

	deallocateCceMap(nextSbfn);
	// Prepare and Schedule next BCCH messages
    if((nextSbfn == SIB1_PREPARATION_SUBFRAME)||(nextSbfn == MIB_PREPARATION_SUBFRAME))
    {
    	checkAndScheduleBcchInDlBins(nextSfn , nextSbfn);
    }
    prepareUlConfigReqForNplus1Subframes(nextSfn , nextSbfn);
}

uint8 lteCheckTDDsubframe( uint16 sbfn )
{
    uint8 ret = 3;// assign invalid
    if ((sbfn >= 0) && (sbfn < LTE_MAX_SUB_FRAME_NUMBER))
    {
        if (ULDL[LTE_TDD_UD_CONFIG][sbfn] == LTE_TDD_DOWNLINK)
            ret = LTE_TDD_DOWNLINK;
        else if (ULDL[LTE_TDD_UD_CONFIG][sbfn] == LTE_TDD_UPLINK)
            ret = LTE_TDD_UPLINK;
        else
            ret = LTE_TDD_SSUBFRAME;
    }
    return ret;
 }

void lteTddMacScheduler(uint16 nextSfn , uint8 nextSbfn)
{
	listNode* qNode = NULL;
	uint8 *sndMsg = NULL;
	uint16 sfNsf = ((nextSfn<<4)|(nextSbfn & 0x0F));

    uint8 subframe =  lteCheckTDDsubframe(nextSbfn) ;

    if ( LTE_TDD_DOWNLINK == subframe) // Downlink
     {   
		if((sndMsg = popFromDlConfigReqQ(sfNsf)) != NULL)
		{
			if(SocketApp_Send4g(sndMsg) == -1)
			{
				logPrint(LOG_ERR,"Send Failed for SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
			}
			sndMsg = NULL;

			if((sndMsg = popFromTxDataReqQ(sfNsf)) != NULL)
			{
				if(SocketApp_Send4g(sndMsg) == -1)
				{
					logPrint(LOG_ERR,"Send Failed for SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
				}
				sndMsg = NULL;
			}
		}
		else
		{
			scheduleDummyDlConfigReq(nextSfn , nextSbfn);
		}
     }
    else if (( LTE_TDD_UPLINK == subframe ) )// Uplink
     {     
		if((headForLteMacUlSchedulerQ[nextSbfn] != NULL) && ((qNode = popMsgFromList( &headForLteMacUlSchedulerQ[nextSbfn]))!= NULL))
		{
			while(qNode != NULL)
			{
				sndMsg = (uint8*) qNode->msg;
				if(SocketApp_Send4g(sndMsg) == -1)
				{
					logPrint(LOG_ERR,"Send Failed for SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
				}
				free(qNode);
				qNode = NULL;

				if(headForLteMacUlSchedulerQ[nextSbfn] != NULL)
				{
					qNode = popMsgFromList(&headForLteMacUlSchedulerQ[nextSbfn]);
				}
				else
				{
					qNode = NULL;
				}
			}
			headForLteMacUlSchedulerQ[nextSbfn] = NULL;
			tailForLteMacUlSchedulerQ[nextSbfn] = NULL;
		}
		else
		{
			scheduleDummyUlConfigReq(nextSfn , nextSbfn); //Need to send always
		}
     }
    else   //  (LTE_TDD_SSUBFRAME == subframe) //Currently Handling UL in SSA ie HARQ
    {
		scheduleDummyDlConfigReq(nextSfn , nextSbfn); // DL
		scheduleDummyUlConfigReq(nextSfn , nextSbfn); //Need to send always
	}
    // Check if we need to send either grant or HI-ACK/NACK
    if (lteTddGrant[LTE_TDD_UD_CONFIG][nextSbfn] != 0 )
    {
    	buildAndSendUlTddDci0ReqForContinuesGrant(sfNsf ,hiDci0ReqPtr); // Contionous Grant
    	hiDci0ReqPtr = NULL;
    }
    deallocateCceMap(nextSbfn);
	// Prepare and Schedule next BCCH messages
    if((nextSbfn == SIB1_PREPARATION_SUBFRAME)||(nextSbfn == MIB_PREPARATION_SUBFRAME))
    {
    	checkAndScheduleBcchInDlBins(nextSfn , nextSbfn);
    }

	if(ULDL[LTE_TDD_UD_CONFIG][((nextSbfn+1)%LTE_MAX_SUB_FRAME_NUMBER)] == LTE_TDD_UPLINK)
	{
		//logPrint(LOG_DEBUG,"SR Debug -1  SFN = %d , SubFrameNo = %d \n" , nextSfn , nextSbfn);
		prepareUlConfigReqForNplus1Subframes(nextSfn , nextSbfn);
	}

	if(nextSbfn == 1) /*LTE_TDD_SSUBFRAME for all UD combinations*/
	{
		checkAndPushTDDPagingReqToDlSchedulerQ(nextSfn , nextSbfn);
	}

	if(rlcDataIndHandler() == TRUE)
	{
		{
			rlcDataIndHandler();
		}
	}
}

void buildPdcchPacketForMib(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = pdcchMib;
	uint8 msgLenth = 0;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_CONFIG_PDU_LIST *dlConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *bchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

	memset(msgBuf , 0 , 64);
	dlConfigReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ; //3
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	dlConfigReq->byNumDCI = 0; // No dci for Mib
	dlConfigReq->byNumOfPDSCHRNTI = 0;
	dlConfigReq->usNumOfPDU = htons(1) ;

	dlConfigPdu->byPduType = eFAPI_BCH_PDU;
	dlConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; // include own size and should be multiple of 4
	generateMib();
	bchPduInfo->BCHPdu.usBchPduLen = htons(LTE_MIB_MAX_SIZE); // Actual length
	bchPduInfo->BCHPdu.usPduIndex = LTE_SHORT_ZERO;
	bchPduInfo->BCHPdu.usTxPower = htons(LTE_PCFICH_POWER_OFFSET_VALUE);

	msgLenth =  SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO;
	dlConfigReq->usLength = htons(msgLenth);

	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);
}

void buildTxDataPacketForMib(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = txDataMib;
	uint8 msgLen = 0;
	uint8* data = NULL;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_DATA_TX_REQUEST * txReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_PDU_DATA_INFO *dlPdu = (tOCT_FAPI_DL_PDU_DATA_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE];
	tOCT_FAPI_DL_PDU_DATA_TLV *txData = (tOCT_FAPI_DL_PDU_DATA_TLV*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

	memset(msgBuf , 0 , sizeof(txDataMib));
	txReq->usNumOfPDU = htons(1);
	txReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));

	dlPdu->usPduIndex = LTE_SHORT_ZERO;
	dlPdu->ulNumOfTLV = htonl(1);

	txData->usTag = 0; //Payload carried in the value field
	txData->usTagLen = htons(LTE_MIB_MAX_SIZE);
	txData->aulValue[0] = 0;
	data = (uint8*)&txData->aulValue[0];
	memcpy((uint8*)data, (uint8*)asn1EncodedMib , LTE_MIB_MAX_SIZE);
	dlPdu->usPduLen = htons(SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE + sizeof(tOCT_UINT32));

	msgLen = SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE + sizeof(tOCT_UINT32) ;

	lteFapiMsg->msgId = PHY_DL_TX_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);
}


void buildPdcchPacketForSib1(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = pdcchSib1;
	uint8 msgLenth = 0;

	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

	tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDciConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
	tOCT_FAPI_DCIFORMAT_1A *dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];

	tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDlSchConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

	memset(msgBuf , 0 , sizeof(pdcchSib1));

	dlConfigReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ; //3
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	dlConfigReq->byNumDCI = 1;
	dlConfigReq->byNumOfPDSCHRNTI = 1; // SI_RNTI only
	dlConfigReq->usNumOfPDU = htons(2) ; // 1-Pdcch(dci-1a) and 2-DlSch Pdu

	/* DCI1A Pdu Start*********************************************************************************************/
	dlDciConfigPdu->byPduType = eFAPI_DCI_DL_PDU;
	dlDciConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; //28bytes
	dciPduInfo->DCIPdu.byDciFormat = eFAPI_DL_DCI_FORMAT_1A;
		
	dciPduInfo->DCIPdu.byCceIndex = LTE_CCE_INDEX_FOR_SIB; // CalculateLteCceIdx(TRUE,LTE_SI_RNTI,sbfn);
	dciPduInfo->DCIPdu.usRnti = htons(LTE_SI_RNTI);
	if(lteSelectedBandwidth > LTE_BW_N15)
	{
		dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS;
	}
	else
	{
		dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS/2;
	}
	dci1AInfo->byVRBAssignmentFlag = eFAPI_LOCALISED; //Localized
	dci1AInfo->byMcs_1 = LTE_MAC_SIB1_CARRYING_DL_MCS;
	dci1AInfo->byRedundancyVersion_1 = 0; //lteRvArr[rvIdx]; // Redudancy version should be changed as 0->2->3->1
	dci1AInfo->ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_SIB1_CARRYING_DL_RIV]);
	dci1AInfo->byNewDataIndicator_1 = 0;
	dci1AInfo->byHarqProcessNum = 0;
	dci1AInfo->byTpc = eFAPI_TX_POWER_CONTROL_MINUS_1 ; // If this value changes then change the rbCoding as well and NPRB = 3
	if(lteDuplxMode)
	{
	 	dci1AInfo->byDlAssignmentIndex = 1;//tdd
	}
	else
	{
		dci1AInfo->byDlAssignmentIndex = 0;//tdd
	}
	dci1AInfo->byAllocatePRACHFlag = FALSE;
	dci1AInfo->byPreambleIndex = 0;
	dci1AInfo->usTxPower = htons(LTE_PDCCH_POWER_OFFSET_VALUE);
	dci1AInfo->byPRACHMaskIndex = 0;
	dci1AInfo->byRntiType = eFAPI_RA_RNTI_P_RNTI_SI_RNTI; //SI_RNTI
	/* DCI1A Pdu End*********************************************************************************************/

	/* DL-SCH Pdu Start*********************************************************************************************/
	dlDlSchConfigPdu->byPduType = eFAPI_DLSCH_PDU;
	dlDlSchConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; // 32Bytes

	dlSchPduInfo->DlSCHPdu.usDlschPduLen = htons(LTE_MAC_SIB1_PDU_SIZE); // Adjusting to TB Size of 296 bits
	dlSchPduInfo->DlSCHPdu.usPduIndex = LTE_SHORT_ZERO;
	dlSchPduInfo->DlSCHPdu.usRnti = htons(LTE_SI_RNTI);
	dlSchPduInfo->DlSCHPdu.byResAllocationType = eFAPI_RES_ALLOC_TYPE_2;
	dlSchPduInfo->DlSCHPdu.byVRBAssignmentFlag = eFAPI_LOCALISED;
	dlSchPduInfo->DlSCHPdu.ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_SIB1_CARRYING_DL_RIV]);
	dlSchPduInfo->DlSCHPdu.byMcs = eFAPI_QPSK;
	dlSchPduInfo->DlSCHPdu.byRedundancyVersion = 0; //lteRvArr[rvIdx++];
	//if(rvIdx == 4)rvIdx=0;
	dlSchPduInfo->DlSCHPdu.byTransportBlocks = 1;
	dlSchPduInfo->DlSCHPdu.byTbToCodeWordSwapFlag = eFAPI_NOSWAPPING;
	dlSchPduInfo->DlSCHPdu.byTransmissionScheme = eFAPI_DL_SINGLE_ANTENNA_PORT_0;
	dlSchPduInfo->DlSCHPdu.byNumOfLayers = 1;
	dlSchPduInfo->DlSCHPdu.byNumOfSubBand = 0;
	dlSchPduInfo->DlSCHPdu.byUeCatagoryCapacity = LTE_UE_CATEGORY;
	dlSchPduInfo->DlSCHPdu.byPA = LTE_PDSCH_CONFIG_PA_VALUE_dB_3; //-3dB //4; //0dB
	dlSchPduInfo->DlSCHPdu.byDeltaPowerOffsetAIndex = 0;
	dlSchPduInfo->DlSCHPdu.byNGap = 0;
	dlSchPduInfo->DlSCHPdu.byNPRB = 0; //NPRB=2
	dlSchPduInfo->DlSCHPdu.usNumRbPerSubBand = 0; //htons(bwToPrb[lteSelectedBandwidth]);
	dlSchPduInfo->DlSCHPdu.usNumbfVector = LTE_SHORT_ZERO;
	/* DL-SCH Pdu End*********************************************************************************************/

	//SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE
	msgLenth = SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE;
	dlConfigReq->usLength = htons(msgLenth);

	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);
}


void buildTxDataPacketForSib1(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = txDataSib1;
	uint8 msgLen = 0;
	uint8* data = NULL;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_DATA_TX_REQUEST * txReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_PDU_DATA_INFO *dlPdu = (tOCT_FAPI_DL_PDU_DATA_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE];
	tOCT_FAPI_DL_PDU_DATA_TLV *txData = (tOCT_FAPI_DL_PDU_DATA_TLV*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

	memset(msgBuf , 0 , sizeof(txDataSib1));
	txReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	txReq->usNumOfPDU = htons(1);

	msgLen = LTE_MAC_SIB1_PDU_SIZE; //asn1EncodedSib1Len + 2;

	dlPdu->usPduIndex = LTE_SHORT_ZERO;
	dlPdu->ulNumOfTLV = htonl(1);

	txData->usTag = LTE_SHORT_ZERO;
	txData->usTagLen = htons(LTE_MAC_SIB1_PDU_SIZE);

	data = (uint8*)&txData->aulValue[0];//Check for length
	if((asn1EncodedSib1 != NULL)&&(asn1EncodedSib1Len != 0))
	memcpy((uint8*)data, (uint8*)asn1EncodedSib1 , asn1EncodedSib1Len);

	if((msgLen%4) != 0)
	{
		msgLen = msgLen + (4 - (msgLen%4)); // Aligning to word boundry
	}
	dlPdu->usPduLen = htons(msgLen + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE);
	msgLen = msgLen + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE ;

	lteFapiMsg->msgId = PHY_DL_TX_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);

}

void buildPdcchPacketForMibSibs(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = pdcchMibSibs;
	uint8 msgLenth = 0;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_CONFIG_PDU_LIST *dlConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *bchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

	tOCT_FAPI_DL_CONFIG_PDU_LIST *dciConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

	tOCT_FAPI_DCIFORMAT_1A *dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];

	tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDlSchConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

	memset(msgBuf , 0 , 128);
	dlConfigReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ; //3
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	dlConfigReq->byNumDCI = 1; // No dci for Mib , 1 dci for Sibs
	dlConfigReq->byNumOfPDSCHRNTI = 1;
	dlConfigReq->usNumOfPDU = htons(3) ; // Bch-Mib , Dci-Sibs , DlSch-Sibs

	//Add Mib Pdu
	generateMib();
	//Now add bch pdu
	dlConfigPdu->byPduType = eFAPI_BCH_PDU;
	dlConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE;

	bchPduInfo->BCHPdu.usBchPduLen = htons(LTE_MIB_MAX_SIZE);
	bchPduInfo->BCHPdu.usPduIndex = LTE_SHORT_ZERO;
	bchPduInfo->BCHPdu.usTxPower = htons(LTE_PCFICH_POWER_OFFSET_VALUE);


	//Now Add Dci Pdu
	dciConfigPdu->byPduType = eFAPI_DCI_DL_PDU;
	dciConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE;

	dciPduInfo->DCIPdu.byDciFormat = eFAPI_DL_DCI_FORMAT_1A;
	
	dciPduInfo->DCIPdu.byCceIndex = LTE_CCE_INDEX_FOR_SIB; //CalculateLteCceIdx(TRUE,LTE_SI_RNTI,sbfn);
	dciPduInfo->DCIPdu.usRnti = htons(LTE_SI_RNTI);
	if(lteSelectedBandwidth > LTE_BW_N15)
	{
		dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS;
	}
	else
	{
		dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS/2;
	}
	dci1AInfo->byVRBAssignmentFlag = eFAPI_LOCALISED; //Localized
	dci1AInfo->byMcs_1 = LTE_MAC_SIBS_CARRYING_DL_MCS;
	dci1AInfo->byRedundancyVersion_1 = 0;
	
	dci1AInfo->byNewDataIndicator_1 = 0;
	dci1AInfo->byHarqProcessNum = 0;
	dci1AInfo->byTpc = eFAPI_TX_POWER_CONTROL_0; //eFAPI_TX_POWER_CONTROL_MINUS_1 ; // If this value changes then change the rbCoding as well and NPRB = 3
	if(lteDuplxMode)
	{
		dci1AInfo->byDlAssignmentIndex = 1;//tdd
	}	
	else
	{
		dci1AInfo->byDlAssignmentIndex = 0;//FDD		
	}
	dci1AInfo->ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_SIBS_CARRYING_DL_RIV]);
	dci1AInfo->byAllocatePRACHFlag = FALSE;
	dci1AInfo->byPreambleIndex = 0;
	dci1AInfo->usTxPower = htons(LTE_PDCCH_POWER_OFFSET_VALUE);
	dci1AInfo->byPRACHMaskIndex = 0;
	dci1AInfo->byRntiType = eFAPI_RA_RNTI_P_RNTI_SI_RNTI; //SI_RNTI

	/* DL-SCH Pdu Start*********************************************************************************************/
	dlDlSchConfigPdu->byPduType = eFAPI_DLSCH_PDU;
	dlDlSchConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; // 32Bytes

	dlSchPduInfo->DlSCHPdu.usDlschPduLen = htons(LTE_MAC_SIBS_PDU_SIZE); // Adjusted to 32 bytes
	dlSchPduInfo->DlSCHPdu.usPduIndex = htons(1); // bch pdu index = 0 and this is 1
	dlSchPduInfo->DlSCHPdu.usRnti = htons(LTE_SI_RNTI);
	dlSchPduInfo->DlSCHPdu.byResAllocationType = eFAPI_RES_ALLOC_TYPE_2;
	dlSchPduInfo->DlSCHPdu.byVRBAssignmentFlag = eFAPI_LOCALISED;
	dlSchPduInfo->DlSCHPdu.ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_SIBS_CARRYING_DL_RIV]);
	dlSchPduInfo->DlSCHPdu.byMcs = eFAPI_QPSK;
	dlSchPduInfo->DlSCHPdu.byRedundancyVersion = 0;
	dlSchPduInfo->DlSCHPdu.byTransportBlocks = 1;
	dlSchPduInfo->DlSCHPdu.byTbToCodeWordSwapFlag = eFAPI_NOSWAPPING;
	dlSchPduInfo->DlSCHPdu.byTransmissionScheme = eFAPI_DL_SINGLE_ANTENNA_PORT_0;
	dlSchPduInfo->DlSCHPdu.byNumOfLayers = 1;
	dlSchPduInfo->DlSCHPdu.byNumOfSubBand = 0;
	dlSchPduInfo->DlSCHPdu.byUeCatagoryCapacity = LTE_UE_CATEGORY;
	dlSchPduInfo->DlSCHPdu.byPA = LTE_PDSCH_CONFIG_PA_VALUE_dB_3; //-3dB //4; //0dB
	dlSchPduInfo->DlSCHPdu.byDeltaPowerOffsetAIndex = 0;
	dlSchPduInfo->DlSCHPdu.byNGap = 0;
	dlSchPduInfo->DlSCHPdu.byNPRB = 0; //NPRB=2
	dlSchPduInfo->DlSCHPdu.usNumRbPerSubBand = 0; //htons(bwToPrb[lteSelectedBandwidth]);
	dlSchPduInfo->DlSCHPdu.usNumbfVector = LTE_SHORT_ZERO;
	/* DL-SCH Pdu End*********************************************************************************************/

	// SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE

	msgLenth =  SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_BCH_PDU_INFO + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE;;
	dlConfigReq->usLength = htons(msgLenth);

	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);

}

void buildTxDataPacketForMibSibs(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = txDataMibSibs;
	uint8 msgLen = 0;
	uint8* data1 = NULL , *data2 = NULL;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_DATA_TX_REQUEST * txReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_PDU_DATA_INFO *dlPdu = (tOCT_FAPI_DL_PDU_DATA_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE];
	tOCT_FAPI_DL_PDU_DATA_TLV *txMibData = (tOCT_FAPI_DL_PDU_DATA_TLV*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

	tOCT_FAPI_DL_PDU_DATA_INFO *dlSibsPdu = (tOCT_FAPI_DL_PDU_DATA_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE + 4];
	tOCT_FAPI_DL_PDU_DATA_TLV *txSibsData = (tOCT_FAPI_DL_PDU_DATA_TLV*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE + 4 + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

	memset(msgBuf , 0 , sizeof(txDataMibSibs));

	txReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	txReq->usNumOfPDU = htons(2);

	dlPdu->usPduLen = htons(SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE + sizeof(tOCT_UINT32));
	dlPdu->usPduIndex = LTE_SHORT_ZERO;
	dlPdu->ulNumOfTLV = htonl(1);


	txMibData->usTag = 0; //Payload carried in the value field
	txMibData->usTagLen = htons(LTE_MIB_MAX_SIZE);
	txMibData->aulValue[0] = 0;
	data1 = (uint8*)&txMibData->aulValue[0];
	memcpy((uint8*)data1, (uint8*)asn1EncodedMib , LTE_MIB_MAX_SIZE);

	//Add Sibs Pdu

	dlSibsPdu->usPduIndex = htons(1);
	dlSibsPdu->ulNumOfTLV = htonl(1);

	msgLen = LTE_MAC_SIBS_PDU_SIZE ; //asn1EncodedSibsLen + 3;
	txSibsData->usTag = 0;
	txSibsData->usTagLen = htons(LTE_MAC_SIBS_PDU_SIZE);
	data2 = (uint8*)&txSibsData->aulValue[0];
	if((asn1EncodedSibs != NULL)&&(asn1EncodedSibsLen != 0))
	memcpy((uint8*)data2, (uint8*)asn1EncodedSibs , asn1EncodedSibsLen);

	if((msgLen%4) != 0)
	{
		msgLen = msgLen + (4 - (msgLen%4)); // Aligning to word boundry
	}
	dlSibsPdu->usPduLen = htons(msgLen + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE);
	msgLen = SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + ntohs(dlSibsPdu->usPduLen + dlPdu->usPduLen) ;

	lteFapiMsg->msgId = PHY_DL_TX_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);

}

void buildPdcchPacketForSibs(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = pdcchSibs;
	uint8 msgLenth = 0;

	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_CONFIG_REQUEST *dlConfigReq = (tOCT_FAPI_DL_CONFIG_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];

	tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDciConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *dciPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];
	tOCT_FAPI_DCIFORMAT_1A *dci1AInfo = (tOCT_FAPI_DCIFORMAT_1A* )&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE];

	tOCT_FAPI_DL_CONFIG_PDU_LIST *dlDlSchConfigPdu = (tOCT_FAPI_DL_CONFIG_PDU_LIST *)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A];
	tOCT_FAPI_DL_CONFIG_PDU_INFO *dlSchPduInfo = (tOCT_FAPI_DL_CONFIG_PDU_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE];

	memset(msgBuf , 0 , sizeof(pdcchSibs));

	dlConfigReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	dlConfigReq->byCfi = LTE_NUMBER_OF_SYMBOLS_FOR_PDCCH ; //3
	dlConfigReq->usTxPowerForPCFICH = htons(LTE_PCFICH_POWER_OFFSET_VALUE);
	dlConfigReq->byNumDCI = 1;
	dlConfigReq->byNumOfPDSCHRNTI = 1; // SI_RNTI only
	dlConfigReq->usNumOfPDU = htons(2) ; // 1-Pdcch(dci-1a) and 2-DlSch Pdu

	/* DCI1A Pdu Start*********************************************************************************************/
	dlDciConfigPdu->byPduType = eFAPI_DCI_DL_PDU;
	dlDciConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; //28bytes

	dciPduInfo->DCIPdu.byDciFormat = eFAPI_DL_DCI_FORMAT_1A;

	dciPduInfo->DCIPdu.byCceIndex = LTE_CCE_INDEX_FOR_SIB; //CalculateLteCceIdx(TRUE,LTE_SI_RNTI,sbfn);
	dciPduInfo->DCIPdu.usRnti = htons(LTE_SI_RNTI);
	if(lteSelectedBandwidth > LTE_BW_N15)
	{
		dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS;
	}
	else
	{
		dci1AInfo->byAggregationLevel = LTE_PDCCH_AGGREGATION_LEVEL_FOR_SIBS/2;
	}
	dci1AInfo->byVRBAssignmentFlag = eFAPI_LOCALISED; //Localized
	dci1AInfo->byMcs_1 = LTE_MAC_SIBS_CARRYING_DL_MCS;
	dci1AInfo->byRedundancyVersion_1 = 0;
	dci1AInfo->ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_SIBS_CARRYING_DL_RIV]);
	dci1AInfo->byNewDataIndicator_1 = 0;
	dci1AInfo->byHarqProcessNum = 0;
	dci1AInfo->byTpc = eFAPI_TX_POWER_CONTROL_0; //eFAPI_TX_POWER_CONTROL_MINUS_1; // If this value changes then change the rbCoding as well and NPRB = 3
	
	if(lteDuplxMode)
	{
	 	dci1AInfo->byDlAssignmentIndex = 1;//tdd
	}
	else
	{
		dci1AInfo->byDlAssignmentIndex = 0;//tdd
	}

	dci1AInfo->byAllocatePRACHFlag = FALSE;
	dci1AInfo->byPreambleIndex = 0;
	dci1AInfo->usTxPower = htons(LTE_PDCCH_POWER_OFFSET_VALUE);
	dci1AInfo->byPRACHMaskIndex = 0;
	dci1AInfo->byRntiType = eFAPI_RA_RNTI_P_RNTI_SI_RNTI; //SI_RNTI
	/* DCI1A Pdu End*********************************************************************************************/

	/* DL-SCH Pdu Start*********************************************************************************************/
	dlDlSchConfigPdu->byPduType = eFAPI_DLSCH_PDU;
	dlDlSchConfigPdu->byPduSize = SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE; // 32Bytes

	dlSchPduInfo->DlSCHPdu.usDlschPduLen = htons(LTE_MAC_SIBS_PDU_SIZE); // Adjusting to TB Size of 32 Bytes
	dlSchPduInfo->DlSCHPdu.usPduIndex = LTE_SHORT_ZERO;
	dlSchPduInfo->DlSCHPdu.usRnti = htons(LTE_SI_RNTI);
	dlSchPduInfo->DlSCHPdu.byResAllocationType = eFAPI_RES_ALLOC_TYPE_2;
	dlSchPduInfo->DlSCHPdu.byVRBAssignmentFlag = eFAPI_LOCALISED;
	dlSchPduInfo->DlSCHPdu.ulRbCoding = htonl(dlRivArr[lteSelectedBandwidth][LTE_MAC_SIBS_CARRYING_DL_RIV]);
	dlSchPduInfo->DlSCHPdu.byMcs = eFAPI_QPSK;
	dlSchPduInfo->DlSCHPdu.byRedundancyVersion  = 0;
	dlSchPduInfo->DlSCHPdu.byTransportBlocks = 1;
	dlSchPduInfo->DlSCHPdu.byTbToCodeWordSwapFlag = eFAPI_NOSWAPPING;
	dlSchPduInfo->DlSCHPdu.byTransmissionScheme = eFAPI_DL_SINGLE_ANTENNA_PORT_0;
	dlSchPduInfo->DlSCHPdu.byNumOfLayers = 1;
	dlSchPduInfo->DlSCHPdu.byNumOfSubBand = 0;
	dlSchPduInfo->DlSCHPdu.byUeCatagoryCapacity = LTE_UE_CATEGORY;
	dlSchPduInfo->DlSCHPdu.byPA = LTE_PDSCH_CONFIG_PA_VALUE_dB_3; //-3dB //4; //0dB
	dlSchPduInfo->DlSCHPdu.byDeltaPowerOffsetAIndex = 0;
	dlSchPduInfo->DlSCHPdu.byNGap = 0;
	dlSchPduInfo->DlSCHPdu.byNPRB = 0; //NPRB=2
	dlSchPduInfo->DlSCHPdu.usNumRbPerSubBand = 0; //htons(bwToPrb[lteSelectedBandwidth]);
	dlSchPduInfo->DlSCHPdu.usNumbfVector = LTE_SHORT_ZERO;
	/* DL-SCH Pdu End*********************************************************************************************/

	msgLenth = SIZE_TOCT_FAPI_DL_CONFIG_REQUEST_BASE + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_DCI_PDU_INFO_BASE + SIZE_TOCT_FAPI_DCIFORMAT_1A + SIZE_TOCT_FAPI_DL_CONFIG_PDU_LIST_BASE + SIZE_TOCT_FAPI_DL_SCH_PDU_INFO_BASE;
	dlConfigReq->usLength = htons(msgLenth);

	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLenth));
	lteFapiMsg->usMsgLen = htons(msgLenth);
}


void buildTxDataPacketForSibs(uint16 sfn , uint8 sbfn)
{
	uint8 *msgBuf = txDataSibs;
	uint8 msgLen = 0;
	uint8* data = NULL;
	tOCT_FAPI_L1_API_MSG * lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_DL_DATA_TX_REQUEST * txReq = (tOCT_FAPI_DL_DATA_TX_REQUEST*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	tOCT_FAPI_DL_PDU_DATA_INFO *dlPdu = (tOCT_FAPI_DL_PDU_DATA_INFO*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE];
	tOCT_FAPI_DL_PDU_DATA_TLV *txData = (tOCT_FAPI_DL_PDU_DATA_TLV*)&msgBuf[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE];

	memset(msgBuf , 0 , sizeof(txDataSibs));
	txReq->usSfnsf = htons((sfn<<4)|(sbfn & 0x0F));
	txReq->usNumOfPDU = htons(1);

	msgLen = LTE_MAC_SIBS_PDU_SIZE ;//asn1EncodedSibsLen + 3;

	dlPdu->usPduIndex = LTE_SHORT_ZERO;
	dlPdu->ulNumOfTLV = htonl(1);

	txData->usTag = LTE_SHORT_ZERO;
	txData->usTagLen = htons(LTE_MAC_SIBS_PDU_SIZE);

	data = (uint8*)&txData->aulValue[0];//Check for length
	if((asn1EncodedSibs != NULL)&&(asn1EncodedSibsLen != 0))
	memcpy((uint8*)data, (uint8*)asn1EncodedSibs , asn1EncodedSibsLen);

	if((msgLen%4) != 0)
	{
		msgLen = msgLen + (4 - (msgLen%4)); // Aligning to word boundry
	}
	dlPdu->usPduLen = htons(msgLen + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE);
	msgLen = msgLen + SIZE_TOCT_FAPI_DL_DATA_TX_REQUEST_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_INFO_BASE + SIZE_TOCT_FAPI_DL_PDU_DATA_TLV_BASE ;

	lteFapiMsg->msgId = PHY_DL_TX_REQUEST;
	buildLteEthernetHeader(msgBuf , SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);

}

void cleanMibSibData()
{
	lteSib1TxStarted = FALSE;
	lteMibTxStarted = FALSE ;
	skipNextTxDataReq = FALSE;
	memset(pdcchMib , 0 , 64) ;
	memset(txDataMib , 0 , 64);
	memset(pdcchSib1 , 0 , 128);
	memset(txDataSib1 , 0 , 96);
	memset(pdcchMibSibs , 0 , 128);
	memset(txDataMibSibs ,0 , 160);
	memset(pdcchSibs , 0 , 128);
	memset(txDataSibs , 0 , 128);
	memset(dummyDlConfig , 0,  64);
}
