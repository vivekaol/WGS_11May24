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
 * File Name   : lteL1IfApi.h
 *
 * Description : Lte L1C interface API definitions
 *
 * History     :
 *
 * Date                                  Author                     Details
 * ---------------------------------------------------------------------------
 * 11/10/2014          				  Anand Kashikar			   Initial File Creation
 *############################################################################
 */

#include <arpa/inet.h>
#include <string.h>
#include "logManager.h"
#include "rawSocketApi.h"
#include "oct_ltefapimacphyinterface.h"

uint8 lteFapiMsgBuffer[MAX_SIZE_OF_LTE_ETHERNET_FRAME];
uint16 LTE_PHYSICAL_CELL_ID_VALUE = 1;
extern uint16 bwToPrb[MAX_BANDWIDTH];
extern eLteBw lteSelectedBandwidth;
#ifdef FXL_4G_TX_JAMMER
extern int lteJamCellFound;
#endif
extern elteDupMode lteDuplxMode;
extern unsigned int pilot_boost_enabled;

void buildAndSendPhyParamReq()
{
	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&lteFapiMsgBuffer[START_OF_LTE_FAPI_MESSAGE];
	memset(lteFapiMsgBuffer, 0, MAX_SIZE_OF_LTE_ETHERNET_FRAME);

	lteFapiMsg->msgId = PHY_PARAM_REQUEST;
	lteFapiMsg->usMsgLen = 0;

	buildLteEthernetHeader(lteFapiMsgBuffer, SIZE_OF_LTE_FAPI_MESSAGE(lteFapiMsg->usMsgLen));

	if (SocketApp_Send4g(lteFapiMsgBuffer) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyParamReq send Failed \n");
	}
}

void buildAndSendPhyCellConfigReq()
{
	tOCT_UINT16 refSignalPower = 0x0000;

	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&lteFapiMsgBuffer[START_OF_LTE_FAPI_MESSAGE];
	tOCT_FAPI_CELL_CONFIG_REQUEST *lteCellConfigReq = (tOCT_FAPI_CELL_CONFIG_REQUEST *)&lteFapiMsgBuffer[START_OF_LTE_FAPI_MESSAGE + SIZE_TOCT_FAPI_L1_API_MSG];
	memset(lteFapiMsgBuffer, 0, MAX_SIZE_OF_LTE_ETHERNET_FRAME);

	lteFapiMsg->msgId = PHY_CELL_CONFIG_REQUEST;
	lteFapiMsg->usMsgLen = SIZE_TOCT_FAPI_CELL_CONFIG_REQUEST_BASE + 4;

	// 1- duplexing mode
	lteCellConfigReq->byNumOfTlv = 1; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen = lteFapiMsg->usMsgLen + SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_DUPLEXING_MODE;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usDuplexingMode = htons(eFAPI_TDD);
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usDuplexingMode = htons(eFAPI_FDD);
	}

	// 2- pcfich power offset
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_PCFICH_POWER_OFFSET;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);							// MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPcfichPowerOffset = htons(LTE_PCFICH_POWER_OFFSET_VALUE); // 6000 with  htons

	// 3- Pb Value
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_P_B;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPb = htons(LTE_PB_VALUE_TDD); // 0
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPb = htons(LTE_PB_VALUE); // 0
	}

	// 4- DL Cyclic Prefix
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_DL_CYCLIC_PREFIX_TYPE;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);			   // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usDlCyclicPrefixType = htons(eFAPI_CP_NORMAL); // 0

	// 5- UL Cyclic Prefix
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_UL_CYCLIC_PREFIX_TYPE;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);			   // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usUlCyclicPrefixType = htons(eFAPI_CP_NORMAL); // 0

	// 6- DL Channel Bandwidth
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_DL_CHANNEL_BANDWIDTH;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);					  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usDlChannelBW = htons(bwToPrb[lteSelectedBandwidth]); // htons

	// 7- UL Channel Bandwidth
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_UL_CHANNEL_BANDWIDTH;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);					  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usUlChannelBW = htons(bwToPrb[lteSelectedBandwidth]); //  htons

	// 8- reference signal power
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_REFERENCE_SIGNAL_POWER;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16

#ifdef FXL_4G_TX_JAMMER
	if (lteJamCellFound)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usRefSignalPower = htons(32 + 12);
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usRefSignalPower = htons(32);
	}
#else
	{
		refSignalPower = 0x0020;
		logPrint(LOG_INFO, "refSignalPower = %d\n", inSibs->sib2.refSignalPower);
		if (pilot_boost_enabled == TRUE)
		{
			refSignalPower = 0xFF00;
			logPrint(LOG_INFO, "refSignalPower = %d\n", inSibs->sib2.refSignalPower);
		}
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usRefSignalPower = htons(refSignalPower);
	}
#endif
	// 9- Tx Antenna Ports
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_TX_ANTENNA_PORTS;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usTxAntennaPort = htons(eFAPI_TX_ANTENNA_PORT_1); // eFAPI_TX_ANTENNA_PORT_1

	// 10- Rx Antenna Ports
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_RX_ANTENNA_PORTS;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usRxAntennaPort = htons(eFAPI_RX_ANTENNA_PORT_1); // eFAPI_RX_ANTENNA_PORT_1

	// 11- Phich Resource
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_PHICH_RESOURCE;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);			 // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPhichResource = htons(eFAPI_PHICH_R_HALF); // eFAPI_PHICH_R_ONE_SIXTH

	// 12- Phich Duration
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_PHICH_DURATION;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);			   // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPhichDuration = htons(eFAPI_PHICH_D_NORMAL); // eFAPI_PHICH_D_NORMAL

	// 13- Phich Power Offset
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_PHICH_POWER_OFFSET;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);						// MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPhichPowOffset = htons(LTE_PHICH_POWER_OFFSET_VALUE); // 6000 with htons

	// 14- Primary Sync Signal
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_PRIMARY_SYNC_SIGNAL;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);							// MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPrimarySyncSignal = htons(LTE_PRIMARY_SYNC_SIGNAL_VALUE); // 6000

	// 15- Secondary Sync Signal
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_SECONDARY_SYNC_SIGNAL;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);								// MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usSecondarySyncSignal = htons(LTE_SECONDARY_SYNC_SIGNAL_VALUE); // 6000

	// 16- Physical Cell Id
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_PHYSICAL_CELL_ID;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);					  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usPhysicalCellId = htons(LTE_PHYSICAL_CELL_ID_VALUE); // 1 with htons

	// 17- Prach configuration Index
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_CONFIGURATION_INDEX;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);							 // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usConfigurationIndex = htons(LTE_PRACH_CONFIGURATION_INDEX); // 03 htons
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usConfigurationIndex = htons(LTE_PRACH_CONFIGURATION_INDEX_TDD); // 03 htons
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usConfigurationIndex = htons(LTE_PRACH_CONFIGURATION_INDEX); // 03 htons
	}

	// 18- Prach Root Sequence Index
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_ROOT_SEQUENCE_INDEX;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);					   // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usRootSeqIndex = htons(LTE_PRACH_ROOT_SEQUENCE_INDEX); // 16 htons

	// 19- Prach Zero Correlation Configuration Zone Index
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_ZERO_CORRELATION_ZONE_CONFIGURATION;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usZeroCorelationZoneConfig = htons(LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX_TDD); // 1 htons
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usZeroCorelationZoneConfig = htons(LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX); // 1 htons
	}

	// 20- Prach High Speed Flag
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_HIGH_SPEED_FLAG;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);					// MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usHighSpeedFlag = htons(eFAPI_HS_UNRESTRICTED_SET); // 0

	// 21- Prach Frequency Offset
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_FREQUENCY_OFFSET;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usFreqOffset = htons(LTE_PRACH_FREQUENCY_OFFSET); // 4 htons
	if (lteSelectedBandwidth < LTE_BW_N25)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usFreqOffset = htons(LTE_SHORT_ZERO);
	}

	// 22- Pusch Hopping Mode
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_HOPPING_MODE;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);		  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usHoppingMode = htons(eFAPI_HM_INTER_SF); // 0

	// 23- Pusch Hopping Offset
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_HOPPIG_OFFSET;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				   // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usHoppingOffset = htons(LTE_PUSCH_HOPPING_OFFSET); // 1 htons

	// 24- Pusch Num. of Subbands used for hopping
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_NUM_OF_SUB_BANDS;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				   // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usNumOfSubBand = htons(LTE_PUSCH_NUM_OF_SUBBANDS); // 2 htons

	// 25- Pucch delta shift
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_DELTA_PUCCH_SHIFT;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usDeltaPUCCHShift = htons(LTE_PUCCH_DELTA_SHIFT); // 2 htons

	// 26- Pucch Number cqi rb
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_N_CQI_RB;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usNCQIRB = htons(LTE_PUCCH_NUM_CQI_RB_ALLOCATED_TDD); // 04 htons
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usNCQIRB = htons(LTE_PUCCH_NUM_CQI_RB_ALLOCATED); // 04 htons
	}

	// 27- Pucch Number cyclic shifts
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_N_AN_CS;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usNAnCs = htons(LTE_PUCCH_NUM_CYCLIC_SHIFT_TDD); // 0
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usNAnCs = htons(LTE_PUCCH_NUM_CYCLIC_SHIFT); // 0
	}

	// 28- Pucch XXX
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_N_1_PUCCH_AN;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usN1PucchAn = htons(LTE_PUCCH_AN_TDD); // 20
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usN1PucchAn = htons(LTE_PUCCH_AN); // 20
	}

	// 29- SRS Configuration  Bandwidth
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_BANDWIDTH_CONFIGURATION;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usBandWidthConfiguration = htons(LTE_SHORT_ZERO); // 0 htons
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usBandWidthConfiguration = htons(LTE_SRS_BANDWIDTH_CONFIGURATION); // 0 htons
	}
	// 30- SRS TDD UpPts
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_MAX_UP_PTS;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usMaxUpPTS = LTE_SHORT_ZERO;		// Disabled

	// 31- SRS subframe configuration
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_SRS_SUB_FRAME_CONFIGURATION;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM); // MAX element size is 2 ie UINT16
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usSRSSubframeConfiguration = htons(LTE_SHORT_ZERO); // 0 to 15
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usSRSSubframeConfiguration = htons(LTE_SRS_SUBFRAME_CONFIG); // 0 to 15
	}
	// 32- SRS simulataneous ack/nack transmission
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_SRS_ACK_NACK_SRS_SIMULTANEOUS_TRANSMISSION;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = htons(1); // 1
	if (lteDuplxMode)
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.bySrsAckNackSimulTx = LTE_SHORT_ZERO; // no simultaneous transmission  //0
	}
	else
	{
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.bySrsAckNackSimulTx = LTE_SHORT_ZERO; // no simultaneous transmission  //0
	}
	// 33- uplink reference signal configuration hopping
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_UPLINK_RS_HOPPING;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				// MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usUplinkRSHopping = htons(eFAPI_RS_NO_HOPPING); // 0

	// 34- uplink reference signal group assignment
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_GROUP_ASSIGNMENT;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);						// MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usGroupAssignment = htons(LTE_PUSCH_GROUP_ASSIGNEMENT); // 0 to 29  // 0

	// 35- uplink reference signal cyclic one for dmrs
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_CYCLIC_SHIFT_1_FOR_DMRS;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);							   // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usCyclicShift1forDMRS = htons(LTE_PUSCH_REF_SIG_CYCLIC_SHIFT); // 0 to 7 // 0

	// 36- Data Report Mode
	lteCellConfigReq->byNumOfTlv++; // Start with 1 and then increment it
	lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_DATA_REPORT_MODE;
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);	  // MAX element size is 2 ie UINT16
	lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usDataReportingMode = LTE_SHORT_ZERO; // 0: The CRC.indication message is sent every subframe

	if (lteDuplxMode)
	{
		// 37 - SubfarmeAssignment //	usSubFrameAssignment
		lteCellConfigReq->byNumOfTlv++;
		lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_SUB_FRAME_ASSIGNMENT;
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);				 // MAX element size is 2 ie UINT16
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usSubFrameAssignment = htons(LTE_TDD_UD_CONFIG); // 0 to 6

		// 38 - SpecialSubfarmeAssignment //
		lteCellConfigReq->byNumOfTlv++;
		lteFapiMsg->usMsgLen += SIZE_TOCT_FAPI_CELL_CONFIG_TLV;
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTag = eFAPI_SPECIAL_SUB_FRAME_PATTERNS;
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].byTagLen = sizeof(tOCT_FAPI_CELL_CONFIG_PARAM);							 // MAX element size is 2 ie UINT16
		lteCellConfigReq->aConfigTlvs[lteCellConfigReq->byNumOfTlv - 1].configParam.usSpecialSubFramePatterns = htons(LTE_TDD_SPECIALSUBF_ASSG); // 0 to 6
	}

	buildLteEthernetHeader(lteFapiMsgBuffer, SIZE_OF_LTE_FAPI_MESSAGE(lteFapiMsg->usMsgLen));
	lteFapiMsg->usMsgLen = htons(lteFapiMsg->usMsgLen);
	if (SocketApp_Send4g(lteFapiMsgBuffer) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyCellConfigReq send Failed \n");
	}
}

void buildAndSendPhyStartReq()
{
	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&lteFapiMsgBuffer[START_OF_LTE_FAPI_MESSAGE];
	memset(lteFapiMsgBuffer, 0, MAX_SIZE_OF_LTE_ETHERNET_FRAME);

	lteFapiMsg->msgId = PHY_START_REQUEST;
	lteFapiMsg->usMsgLen = 0;

	buildLteEthernetHeader(lteFapiMsgBuffer, SIZE_OF_LTE_FAPI_MESSAGE(lteFapiMsg->usMsgLen));

	if (SocketApp_Send4g(lteFapiMsgBuffer) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyStartReq send Failed \n");
	}
}

void buildAndSendPhyStopReq()
{
	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&lteFapiMsgBuffer[START_OF_LTE_FAPI_MESSAGE];
	memset(lteFapiMsgBuffer, 0, MAX_SIZE_OF_LTE_ETHERNET_FRAME);

	lteFapiMsg->msgId = PHY_STOP_REQUEST;
	lteFapiMsg->usMsgLen = 0;

	buildLteEthernetHeader(lteFapiMsgBuffer, SIZE_OF_LTE_FAPI_MESSAGE(lteFapiMsg->usMsgLen));

	if (SocketApp_Send4g(lteFapiMsgBuffer) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyStopReq send Failed \n");
	}
}

void buildAndSendPhyDlConfigReq(uint8 *msgBuf, uint8 msgLen)
{
	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];

	lteFapiMsg->msgId = PHY_DL_CONFIG_REQUEST;

	/// Put complete DCI message here
	buildLteEthernetHeader(msgBuf, SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);

	if (SocketApp_Send4g(msgBuf) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyDlConfigReq send Failed \n");
	}
}

void buildAndSendPhyUlConfigReq(uint8 *msgBuf, uint8 msgLen)
{
	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&msgBuf[START_OF_LTE_FAPI_MESSAGE];

	lteFapiMsg->msgId = PHY_UL_CONFIG_REQUEST;

	/// Put complete DCI message here
	buildLteEthernetHeader(msgBuf, SIZE_OF_LTE_FAPI_MESSAGE(msgLen));
	lteFapiMsg->usMsgLen = htons(msgLen);

	if (SocketApp_Send4g(msgBuf) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyUlConfigReq send Failed \n");
	}
}

void buildAndSendPhyDlHiDci0Req()
{
	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&lteFapiMsgBuffer[START_OF_LTE_FAPI_MESSAGE];
	memset(lteFapiMsgBuffer, 0, MAX_SIZE_OF_LTE_ETHERNET_FRAME);

	lteFapiMsg->msgId = PHY_DL_HI_DCI0_REQUEST;
	lteFapiMsg->usMsgLen = 0;

	/// Put complete DCI message here
	buildLteEthernetHeader(lteFapiMsgBuffer, SIZE_OF_LTE_FAPI_MESSAGE(lteFapiMsg->usMsgLen));

	if (SocketApp_Send4g(lteFapiMsgBuffer) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyDlHiDci0Req send Failed \n");
	}
}

void buildAndSendPhyDlTxReq()
{
	tOCT_FAPI_L1_API_MSG *lteFapiMsg = (tOCT_FAPI_L1_API_MSG *)&lteFapiMsgBuffer[START_OF_LTE_FAPI_MESSAGE];
	memset(lteFapiMsgBuffer, 0, MAX_SIZE_OF_LTE_ETHERNET_FRAME);

	lteFapiMsg->msgId = PHY_DL_TX_REQUEST;
	lteFapiMsg->usMsgLen = 0;

	/// Put complete DCI message here
	buildLteEthernetHeader(lteFapiMsgBuffer, SIZE_OF_LTE_FAPI_MESSAGE(lteFapiMsg->usMsgLen));

	if (SocketApp_Send4g(lteFapiMsgBuffer) == -1)
	{
		logPrint(LOG_ERR, "buildAndSendPhyDlTxReq send Failed \n");
	}
}
