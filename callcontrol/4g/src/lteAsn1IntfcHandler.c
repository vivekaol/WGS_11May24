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
* File Name   : lteAsn1IntfcHandler.c
*
* Description : Lte Asn1 Library Interface functions Handler
*
* History     :
*
* Date                                  Author                     Details
* -------------------------------------------------------------------------------------------
* 27/01/2015          				  Anand Kashikar			   Initial File Creation
*#############################################################################################
*/

#include <string.h>
#include <malloc.h>
#include "logManager.h"
#include "lteAsn1Handler.h"
#include "lteAsn1IntfcHandler.h"
#include "lteMacScheduler.h"
static uint8 sfn = 0;
uint8 lteRrcRedirectFlag;
uint8 lteRrcPrmRedirectFlag; // Permanent redirection
extern eLteBw lteSelectedBandwidth;
uint8 enableAttRejCause;
uint8 lteWlRejCause;
extern elteDupMode lteDuplxMode ;
uint8 systeInfoTagGlobal = LTE_SIB1_SYSTEM_VALUE_TAG;
extern lteWlRedirectInfo redirectInfo;
extern fxL4gConfigureIdCatcherParamsCmd lastLteIdCatcherConfigCmd;
extern int idCatcherLteWlRedirEarfcn;

lteSysModifyInfo sysInfoModify;

LteRrcMeasurementControlData gLteRrcMeasData;

asnLteNeighborConfig gAsnLteNeighConfigData; 

#define LTE_ASSIGN_NON_NEGATIVE(src, dst)          \
           if(dst != -1){                    \
              src = dst;                     \
           }                                 \

void generateMib()
{
	uint32 tmp = 0;
	if(lteSelectedBandwidth <= LTE_BW_N15)
	{
		uint8* asn = NULL;
		uint8 len = 0;
		lteMibStruct inMib = {0};
		inMib.dlBw = lteSelectedBandwidth;
		inMib.phichDuration = LTE_PHICH_DURATION_NORMAL;
		inMib.phichResource = LTE_PHICH_RESOURCE_HALF ; //LTE_PHICH_RESOURCE_ONSIXTH;
		inMib.sfn = sfn++;
		asn = buildAndEncodeMib(&inMib , &len );
		if(asn != NULL)
		memcpy(asn1EncodedMib , asn , len);
		return;
	}
	else if(lteSelectedBandwidth == LTE_BW_N25)
	{
		tmp = (0x10 << 8) | sfn++;
	}
	else if(lteSelectedBandwidth == LTE_BW_N50)
	{
		tmp = (0x18 << 8) | sfn++;
	}
	else if(lteSelectedBandwidth == LTE_BW_N75)
	{
		tmp = (0x20 << 8) | sfn++;
	}
	else if(lteSelectedBandwidth == LTE_BW_N100)
	{
		tmp = (0x28 << 8) | sfn++;
	}
	else
	{
		tmp = (0x18 << 8) | sfn++;
	}
	tmp = tmp << 10;
	asn1EncodedMib[2] = (tmp & 0xFF);
	asn1EncodedMib[1] = (tmp >> 8) & 0xFF;
	asn1EncodedMib[0] = (tmp >> 16) & 0xFF;

	//logPrint(LOG_DEBUG, "MIB Contents  %02x %02x %02x\n" , asn1EncodedMib[0],asn1EncodedMib[1],asn1EncodedMib[2]);
}

//ASHU ASN.1 Issue
void generateSib1RrcThrd(fxL4gConfigureIdCatcherParamsCmd * cmd)
{
	lteSib1Struct inSib1 = {0};
	uint8* asnBuf = NULL;
	uint8 i = 0, j = 0;

	memset(asn1EncodedSib1 , 0 , LTE_MAC_SIB1_PDU_SIZE);
	asn1EncodedSib1Len = 0;
	if(initializeLteASNContextRrcThrd("Sib1BuildTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "SIB1 ASN1 DECODING FAILED");
		return;
	}

	inSib1.cellId = htonl(cmd->layer3CellId << 4);//LTE_LAYER3_CELL_IDENTITY_VALUE;
	inSib1.freqBandIndicator = cmd->bandIndicator;//LTE_FREQUENCY_BAND_INDICATOR;
	inSib1.isCellBarred = FALSE; // Not - Barred
	inSib1.isIntraFreqSelectionAllowed = TRUE; // TRUE-Allowed , FALSE -Not Allowed //Need to check and update
	inSib1.noOfPlmns = cmd->numOfPlmn;
	for (i = 0; i < inSib1.noOfPlmns; i++)
	{
	    inSib1.plmn[i].mccLength = cmd->plmn[i].mccLength;
		for (j = 0; j < inSib1.plmn[i].mccLength; j++)
		{
		    inSib1.plmn[i].mcc[j] = cmd->plmn[i].mcc[j];
		}

	    inSib1.plmn[i].mncLength = cmd->plmn[i].mncLength;
		for (j = 0; j < inSib1.plmn[i].mncLength; j++)
		{
		    inSib1.plmn[i].mnc[j] = cmd->plmn[i].mnc[j];
		}
	}
	inSib1.qRxLevMin = LTE_SIB1_Q_RXLEV_MIN;
	inSib1.qRxLevMinOffset = LTE_SIB1_Q_RXLEV_MIN_OFFSET;
	inSib1.siWindowLength = LTE_SI_WINDOW_LENGTH_MS5;
	inSib1.systemValueTag = (systeInfoTagGlobal++)%31;
	inSib1.trackingAreaCode = htons(cmd->tac);//LTE_LAYER3_TRACKING_AREA_CODE;
	inSib1.siPeriodicity = LTE_SI_PERIODICITY_RF32; //set the LTE_SIBS_REPITITION_FRAMES accordingly when you change this
    inSib1.sibMask = 0;

#if 0	
/*
        if ((REDIRECTION_TO_4G == cmd->redirectionType) &&
            (cmd->earfcn == cmd->redirectionInfo.eutraEARFCN))
        { 
            //Add SIB4
            inSib1.sibMask |= SIB4_MASK;
        }
        else if ((REDIRECTION_TO_4G == cmd->redirectionType) &&
                 (cmd->earfcn != cmd->redirectionInfo.eutraEARFCN))
        {
            //Add SIB5
            inSib1.sibMask |= SIB5_MASK;
        }
        else if (REDIRECTION_TO_3G == cmd->redirectionType)
        {
            //Add SIB6
            inSib1.sibMask |= SIB6_MASK;
        }
        else if (REDIRECTION_TO_2G == cmd->redirectionType)
        {
            //Add SIB7
            inSib1.sibMask |= SIB7_MASK;
        }
		else if (REDIRECTION_TO_CDMA == cmd->redirectionType)
        {
            //Add SIB8
            inSib1.sibMask |= SIB8_MASK;
        }
        else			
        {
            if(gAsnLteNeighConfigData.numberOfLteNeighbor > 0)
            {
               // Add SIB5 
               inSib1.sibMask |= SIB5_MASK;
            }
            
            if(gAsnLteNeighConfigData.numberOfUmtsNeighbor > 0)
            {
               // Add SIB6 
               inSib1.sibMask |= SIB6_MASK;
            }

            if(gAsnLteNeighConfigData.numberOfGsmNeighbor > 0)
            {
               // Add SIB7 
               inSib1.sibMask |= SIB7_MASK;
            } 
        }

        if (SERVING_CELL_3G == cmd->emeCallSrvCellType)
        {
            //Add SIB6
            inSib1.sibMask |= SIB6_MASK;
        }
        else if (SERVING_CELL_2G == cmd->emeCallSrvCellType)
        {
            //Add SIB7
             inSib1.sibMask |= SIB7_MASK;
        }
        else if (SERVING_CELL_CDMA == cmd->emeCallSrvCellType)
        {
            //Add SIB8
            inSib1.sibMask |= SIB8_MASK;
        }
        else
        {
             // Nothing
        }
*/
#endif

	if((inSib1.freqBandIndicator > 32)&&(inSib1.freqBandIndicator < 53))
	{
		inSib1.ulDLConfig = LTE_TDD_UD_CONFIG;
	    inSib1.specialsubfAssg = LTE_TDD_SPECIALSUBF_ASSG;
	}

	asnBuf = buildAndEncodeSib1RrcThrd(&inSib1 , &asn1EncodedSib1Len); // Here memory is allocated inside this function.
	logPrint(LOG_DEBUG , "buildAndEncodeSib1RrcThrd Encoded SIB1 Size = %d \n" , asn1EncodedSib1Len );

	assert(asn1EncodedSib1Len != 0);
	if(asnBuf != NULL)
	{
		memcpy(asn1EncodedSib1, asnBuf, asn1EncodedSib1Len);		
		free(asnBuf);	
	}

	cleanLteASNContextRrcThrd();


	sysInfoModify.earfcn = cmd->earfcn;
	sysInfoModify.bandIndicator = cmd->bandIndicator;
	sysInfoModify.layer3CellId = cmd->layer3CellId;
	sysInfoModify.phyCellId = cmd->phyCellId;
	sysInfoModify.numOfPlmn = cmd->numOfPlmn;
	for (i = 0; i < sysInfoModify.numOfPlmn; i++)
	{
	    sysInfoModify.plmn[i].mccLength = cmd->plmn[i].mccLength;
		for (j = 0; j < sysInfoModify.plmn[i].mccLength; j++)
		{
		    sysInfoModify.plmn[i].mcc[j] = cmd->plmn[i].mcc[j];
		}

	    sysInfoModify.plmn[i].mncLength = cmd->plmn[i].mncLength;
		for (j = 0; j < sysInfoModify.plmn[i].mncLength; j++)
		{
		    sysInfoModify.plmn[i].mnc[j] = cmd->plmn[i].mnc[j];
		}
	}
}

void generateSib1(fxL4gConfigureIdCatcherParamsCmd * cmd)
{
	lteSib1Struct inSib1 = {0};
	uint8* asnBuf = NULL;
	uint8 i = 0, j = 0;

	memset(asn1EncodedSib1 , 0 , LTE_MAC_SIB1_PDU_SIZE);
	asn1EncodedSib1Len = 0;
	if(initializeLteASNContext("Sib1BuildTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "SIB1 ASN1 DECODING FAILED");
		return;
	}

	inSib1.cellId = htonl(cmd->layer3CellId << 4);//LTE_LAYER3_CELL_IDENTITY_VALUE;
	inSib1.freqBandIndicator = cmd->bandIndicator;//LTE_FREQUENCY_BAND_INDICATOR;
	inSib1.isCellBarred = FALSE; // Not - Barred
	inSib1.isIntraFreqSelectionAllowed = TRUE; // TRUE-Allowed , FALSE -Not Allowed //Need to check and update
	inSib1.noOfPlmns = cmd->numOfPlmn;
	for (i = 0; i < inSib1.noOfPlmns; i++)
	{
	    inSib1.plmn[i].mccLength = cmd->plmn[i].mccLength;
		for (j = 0; j < inSib1.plmn[i].mccLength; j++)
		{
		    inSib1.plmn[i].mcc[j] = cmd->plmn[i].mcc[j];
		}

	    inSib1.plmn[i].mncLength = cmd->plmn[i].mncLength;
		for (j = 0; j < inSib1.plmn[i].mncLength; j++)
		{
		    inSib1.plmn[i].mnc[j] = cmd->plmn[i].mnc[j];
		}
	}
	inSib1.qRxLevMin = LTE_SIB1_Q_RXLEV_MIN;
	inSib1.qRxLevMinOffset = LTE_SIB1_Q_RXLEV_MIN_OFFSET;
	inSib1.siWindowLength = LTE_SI_WINDOW_LENGTH_MS5;
	inSib1.systemValueTag = (systeInfoTagGlobal++)%31;
	inSib1.trackingAreaCode = htons(cmd->tac);//LTE_LAYER3_TRACKING_AREA_CODE;
	inSib1.siPeriodicity = LTE_SI_PERIODICITY_RF32; //set the LTE_SIBS_REPITITION_FRAMES accordingly when you change this
    inSib1.sibMask = 0;

#if 0
/*
    if ((REDIRECTION_TO_4G == cmd->redirectionType) &&
        (cmd->earfcn == cmd->redirectionInfo.eutraEARFCN))
    { 
        //Add SIB4
        inSib1.sibMask |= SIB4_MASK;
    }
    else if ((REDIRECTION_TO_4G == cmd->redirectionType) &&
             (cmd->earfcn != cmd->redirectionInfo.eutraEARFCN))
    {
        //Add SIB5
        inSib1.sibMask |= SIB5_MASK;
    }
    else if (REDIRECTION_TO_3G == cmd->redirectionType)
    {
        //Add SIB6
        inSib1.sibMask |= SIB6_MASK;
    }
    else if (REDIRECTION_TO_2G == cmd->redirectionType)
    {
        //Add SIB7
        inSib1.sibMask |= SIB7_MASK;
    }
    else if (REDIRECTION_TO_CDMA == cmd->redirectionType)
    {
        //Add SIB8
        inSib1.sibMask |= SIB8_MASK;
    }
    else			
    {

        if(gAsnLteNeighConfigData.numberOfLteNeighbor > 0)
        {
           // Add SIB5 
           inSib1.sibMask |= SIB5_MASK;
        }

        if(gAsnLteNeighConfigData.numberOfUmtsNeighbor > 0)
        {
           // Add SIB6 
           inSib1.sibMask |= SIB6_MASK;
        }

        if(gAsnLteNeighConfigData.numberOfGsmNeighbor > 0)
        {
           // Add SIB7 
           inSib1.sibMask |= SIB7_MASK;
        }
    }
    
    if (SERVING_CELL_3G == cmd->emeCallSrvCellType)
    {
        //Add SIB6
        inSib1.sibMask |= SIB6_MASK;
    }
    else if (SERVING_CELL_2G == cmd->emeCallSrvCellType)
    {
        //Add SIB7
         inSib1.sibMask |= SIB7_MASK;
    }
    else if (SERVING_CELL_CDMA == cmd->emeCallSrvCellType)
    {
        //Add SIB8
        inSib1.sibMask |= SIB8_MASK;
    }
    else
    {
         // Nothing
    }
*/
#endif

	if((inSib1.freqBandIndicator > 32)&&(inSib1.freqBandIndicator < 53))
	{
		inSib1.ulDLConfig = LTE_TDD_UD_CONFIG;
	    inSib1.specialsubfAssg = LTE_TDD_SPECIALSUBF_ASSG;
	}

	asnBuf = buildAndEncodeSib1(&inSib1 , &asn1EncodedSib1Len); // Here memory is allocated inside this function.
	logPrint(LOG_DEBUG , "buildAndEncodeSib1 Encoded SIB1 Size = %d \n" , asn1EncodedSib1Len );

	assert(asn1EncodedSib1Len != 0);
	if(asnBuf != NULL)
	{
		memcpy(asn1EncodedSib1, asnBuf, asn1EncodedSib1Len);		
		free(asnBuf);	
	}

	cleanLteASNContext();

	sysInfoModify.earfcn = cmd->earfcn;
	sysInfoModify.bandIndicator = cmd->bandIndicator;
	sysInfoModify.layer3CellId = cmd->layer3CellId;
	sysInfoModify.phyCellId = cmd->phyCellId;
	sysInfoModify.numOfPlmn = cmd->numOfPlmn;
	for (i = 0; i < sysInfoModify.numOfPlmn; i++)
	{
	    sysInfoModify.plmn[i].mccLength = cmd->plmn[i].mccLength;
		for (j = 0; j < sysInfoModify.plmn[i].mccLength; j++)
		{
		    sysInfoModify.plmn[i].mcc[j] = cmd->plmn[i].mcc[j];
		}

	    sysInfoModify.plmn[i].mncLength = cmd->plmn[i].mncLength;
		for (j = 0; j < sysInfoModify.plmn[i].mncLength; j++)
		{
		    sysInfoModify.plmn[i].mnc[j] = cmd->plmn[i].mnc[j];
		}
	}
}

void generateSibs(fxL4gConfigureIdCatcherParamsCmd * cmd)
{
	lteSibsStruct *inSibs = NULL ;

	if(asn1EncodedSibs != NULL)
	{
		free(asn1EncodedSibs);
		sfn = 0;
	}
	asn1EncodedSibs = NULL;
	asn1EncodedSibsLen = 0;
	if(initializeLteASNContext("SibsBuildTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "SIBS ASN1 DECODING FAILED");
		return;
	}

	inSibs = (lteSibsStruct *)malloc(sizeof(lteSibsStruct)) ;

    inSibs->sibMask = 0;
   
        //Add SIB2
    inSibs->sibMask |= SIB2_MASK;
	inSibs->sib2.alpha = LTE_UL_POWER_CONTROL_ALPHA_7;
	inSibs->sib2.cyclicPrefixLen = LTE_CYCLIC_PREFIX_LEN_1;
	inSibs->sib2.deltaPreambleMsg3 = LTE_SIB2_DELTA_PREAMBLE_MSG3;
	inSibs->sib2.drxCycle = LTE_DRX_CYCLE_RF32;
	inSibs->sib2.enable64QAM = TRUE;
	inSibs->sib2.format1Delta = LTE_PUCCH_FORMAT1_DELTA_0;
	inSibs->sib2.format1bDelta = LTE_PUCCH_FORMAT1B_DELTA_3;
	inSibs->sib2.format2Delta = LTE_PUCCH_FORMAT2_DELTA_1;
	inSibs->sib2.format2aDelta = LTE_PUCCH_FORMAT2A_DELTA_2;
	inSibs->sib2.format2bDelta = LTE_PUCCH_FORMAT2B_DELTA_2;
	inSibs->sib2.hoppingMode = LTE_HOPPING_MODE_INTERSUBFRAME; // sync with cell config
	inSibs->sib2.isBarredForEmergency = FALSE;
    inSibs->sib2.isBarredForMoData = FALSE;
	inSibs->sib2.isBarredForMoSignalling = FALSE;
    inSibs->sib2.isBarredForMmtelVoice = FALSE;
    inSibs->sib2.isBarredForMmtelVideo = FALSE;
    inSibs->sib2.isBarredForCsfb = FALSE;
	inSibs->sib2.isGroupHoppingEnabled = FALSE; //// sync with cell config
	inSibs->sib2.isHighSpeedFlagSet = FALSE;
	inSibs->sib2.isSequenceHoppingEnabled = FALSE;
	inSibs->sib2.isSrsAckNackSimultaeneousTransmissionAllowed = FALSE; // sync with cell config
	inSibs->sib2.maxHARQMsg3Tx = LTE_SIB2_MAX_HARQ_MSG3_TX;
	inSibs->sib2.modficationCoeff = LTE_BCCH_MODIFICATION_PERIOD_COEFF_N16;
	inSibs->sib2.n310 = LTE_UE_CONSTANT_N310_10;
	inSibs->sib2.n311 = LTE_UE_CONSTANT_N310_1;
	inSibs->sib2.nB = LTE_PCCH_NB_1T ;

	inSibs->sib2.noRaPreambles = LTE_NO_RA_PREAMBLES_52; //LTE_NO_RA_PREAMBLES_16;
	inSibs->sib2.powerRampingStep = LTE_RACH_POWER_RAMPING_STEP_DB2;
	inSibs->sib2.prachFreqOffset = LTE_PRACH_FREQUENCY_OFFSET;
	if(lteSelectedBandwidth < LTE_BW_N25)
	{
		inSibs->sib2.prachFreqOffset = 0;
	}
	inSibs->isitTdd = lteDuplxMode;
    if (lteDuplxMode)
    {
	     inSibs->sib2.prachZeroCorrelationZoneConfig = LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX_TDD;
	     inSibs->sib2.prachConfigIndex =  LTE_PRACH_CONFIGURATION_INDEX_TDD;
	     inSibs->sib2.n1PucchAN = LTE_PUCCH_AN_TDD;
	     inSibs->sib2.pB = LTE_PB_VALUE_TDD;
	     inSibs->sib2.p0NominalPUSCH = LTE_PO_NOMINAL_PUSCH_TDD; // This may need to tuning
	     inSibs->sib2.refSignalPower = LTE_REFERENCE_SIGNAL_POWER_TDD;
	     inSibs->sib2.p0NominalPUCCH = LTE_PO_NOMINAL_PUCCH_TDD;
	     inSibs->sib2.n1CsAn = LTE_PUCCH_NUM_CYCLIC_SHIFT_TDD;
	     inSibs->sib2.nRBCqi = LTE_PUCCH_NUM_CQI_RB_ALLOCATED_TDD;		 
		 inSibs->sib2.preambleTargetPower = LTE_INITIAL_PREAMBLE_TARGET_POWER_106DBM; //LTE_INITIAL_PREAMBLE_TARGET_POWER_94DBM
    }
    else
    {
		inSibs->sib2.prachZeroCorrelationZoneConfig = LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX;
		inSibs->sib2.prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX;
		inSibs->sib2.n1PucchAN = LTE_PUCCH_AN;
		inSibs->sib2.pB = LTE_PB_VALUE;
		inSibs->sib2.p0NominalPUSCH = LTE_PO_NOMINAL_PUSCH; // This may need to tuning
		inSibs->sib2.refSignalPower = LTE_REFERENCE_SIGNAL_POWER;
		inSibs->sib2.p0NominalPUCCH = LTE_PO_NOMINAL_PUCCH;
		inSibs->sib2.n1CsAn = LTE_PUCCH_NUM_CYCLIC_SHIFT;
		inSibs->sib2.nRBCqi = LTE_PUCCH_NUM_CQI_RB_ALLOCATED;		
		inSibs->sib2.preambleTargetPower = LTE_INITIAL_PREAMBLE_TARGET_POWER_104DBM; //LTE_INITIAL_PREAMBLE_TARGET_POWER_94DBM
    }
	inSibs->sib2.pucchDeltaShift = LTE_PUCCH_DELTA_SHIFT_2 ; 
	inSibs->sib2.puschGroupAssignment = LTE_PUSCH_GROUP_ASSIGNEMENT;
	inSibs->sib2.puschHoppingOffset = LTE_PUSCH_HOPPING_OFFSET;
	inSibs->sib2.puschNSB = LTE_PUSCH_NUM_OF_SUBBANDS;
	inSibs->sib2.puschRefSigCyclicShift = LTE_PUSCH_REF_SIG_CYCLIC_SHIFT;
	inSibs->sib2.rootSequenceIndex = LTE_PRACH_ROOT_SEQUENCE_INDEX;
	inSibs->sib2.srsBw = LTE_SRS_BANDWIDTH_0;//LTE_SRS_BANDWIDTH_CONFIGURATION
	inSibs->sib2.srsSubframe = LTE_SRS_SUBFRAME_0;
	inSibs->sib2.t300 = LTE_UE_TIMER_T300_2000 ;
	inSibs->sib2.t301 = LTE_UE_TIMER_T301_2000;
	inSibs->sib2.t310 = LTE_UE_TIMER_T310_1000;
	inSibs->sib2.t311 = LTE_UE_TIMER_T311_5000;
	inSibs->sib2.taTimer = LTE_UL_TIME_ALIGNMENT_TIMER_10240;
	inSibs->sib2.macContentionResolutionTimer = LTE_CONTENTION_RESOLUTION_TIMER_SF64;
	inSibs->sib2.preambleTransMax = LTE_PREAMBLE_TRANS_MAX_N10; 
	inSibs->sib2.raResponseWindow = LTE_RA_RESPONSE_WINDOW_10;

   // if (!lteDuplxMode) // FDD case
    {
		inSibs->sib2.ulBandwidth = lteSelectedBandwidth;  // For TDD , there parameters are same as DL BW n Freq.
		inSibs->sib2.ulFrequency = 0;//23799;
    }
    /*else
    {
        inSibs->sib2.ulBandwidth = 0; // TDD Case
    }*/
	//Add SIB3
    inSibs->sibMask |= SIB3_MASK;
	inSibs->sib3.cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY;
	inSibs->sib3.isAntennaPort1Present = FALSE;
	inSibs->sib3.qHyst = LTE_RESELECTION_QHYSTERIS_4;
	inSibs->sib3.qRxLevMin = LTE_SIB3_Q_RXLEV_MIN;
	inSibs->sib3.tReselectionEUTRA = LTE_SIB3_TRESELECTION_EUTRA; //TBD Add highest value here
	inSibs->sib3.threshServingLow = LTE_SIB3_THRESH_SERVING_LOW;
	inSibs->sib3.sIntraSearch = LTE_SIB3_SINTRASEARCH;
	inSibs->sib3.sNonIntraSearch = LTE_SIB3_SNONINTRASEARCH;	
#if 0	
	/*
	unsigned int idx = 0;
    if ((REDIRECTION_TO_4G == cmd->redirectionType) &&
        (cmd->earfcn == cmd->redirectionInfo.eutraEARFCN))
    { 
        //Add SIB4
        inSibs->sibMask |= SIB4_MASK;
	    inSibs->sib4.noOfIntraNeighbourCells = 1;
	    inSibs->sib4.neighbourIntraCells[0] = 20;
	    inSibs->sib4.neighbourIntraCellQOffset[0] = 0;
    }
    else if ((REDIRECTION_TO_4G == cmd->redirectionType) &&
            (cmd->earfcn != cmd->redirectionInfo.eutraEARFCN))
    {
        //Add SIB5
        inSibs->sibMask |= SIB5_MASK;
	    inSibs->sib5.noOfInterFreqNeighbourCells = 1;
	    inSibs->sib5.interFreqNeighbourCell[0].dlCarrierFreq = cmd->redirectionInfo.eutraEARFCN;
	    inSibs->sib5.interFreqNeighbourCell[0].bandwidth = cmd->lteBandwidth;
	    inSibs->sib5.interFreqNeighbourCell[0].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY ;
	    inSibs->sib5.interFreqNeighbourCell[0].qRxLevMin = LTE_SIB3_Q_RXLEV_MIN;
	    inSibs->sib5.interFreqNeighbourCell[0].threshXHigh = 0;
	    inSibs->sib5.interFreqNeighbourCell[0].threshXLow = 0;
	    inSibs->sib5.interFreqNeighbourCell[0].tReselect = 0;
	    inSibs->sib5.interFreqNeighbourCell[0].cellConfig = 0xFFFFFFFF;
    }	
    else if (REDIRECTION_TO_3G == cmd->redirectionType)
    {
        // Add SIB6 
        inSibs->sibMask |= SIB6_MASK;
        inSibs->sib6.noOfUmtsNeighborCells = 1;
        inSibs->sib6.umtsNeighbourCell[0].umtsCarrierFreq = cmd->redirectionInfo.utraFDDUARFCN;
        inSibs->sib6.umtsNeighbourCell[0].pMaxUTRA = 24;
        inSibs->sib6.umtsNeighbourCell[0].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY ;
        inSibs->sib6.umtsNeighbourCell[0].qQualMin = -18;
        inSibs->sib6.umtsNeighbourCell[0].qRxLevMin = -58;
        inSibs->sib6.umtsNeighbourCell[0].threshXLow = 0;
        inSibs->sib6.umtsNeighbourCell[0].threshXHigh = 0;
        inSibs->sib6.tReselectionUTRA = 0;
    }
    else if (REDIRECTION_TO_2G == cmd->redirectionType)
    {
        // Add SIB7 
        inSibs->sibMask |= SIB7_MASK;
        inSibs->sib7.noOfGsmNeighborCells = 1;
        inSibs->sib7.gsmNeighbourCell[0].startingARFCN = cmd->redirectionInfo.gsmRedirectinfo.startingarfcn;
        inSibs->sib7.gsmNeighbourCell[0].bandIndicator = cmd->redirectionInfo.gsmRedirectinfo.bandIndicator;
        inSibs->sib7.gsmNeighbourCell[0].followingArfcnType = LTE_FOLLOWING_ARFCN_EXPLICITLIST;
        inSibs->sib7.gsmNeighbourCell[0].neighborList.expArfcn.noOfArfcn = 0;
        //inSibs->sib7.gsmNeighbourCell[0].neighborList.expArfcn.ARFCN_ValueGERAN[0] = 
        //                                             cmd->redirectionInfo.gsmRedirectinfo.startingarfcn + 1;
        inSibs->sib7.gsmNeighbourCell[0].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY -1 ;
        inSibs->sib7.gsmNeighbourCell[0].pMaxGeran = 27;
        inSibs->sib7.gsmNeighbourCell[0].qRxLevMin = 10;
        inSibs->sib7.gsmNeighbourCell[0].threshXLow = 0;
        inSibs->sib7.gsmNeighbourCell[0].threshXHigh = 0;
        inSibs->sib7.tReselectionGERAN = 0;
    }
    else if (REDIRECTION_TO_CDMA == cmd->redirectionType)
    {
        // Add SIB8 
        inSibs->sibMask |= SIB8_MASK;
        inSibs->sib8.tReselectionCDMA2000 = 2;
        inSibs->sib8.numberOfBandClass = 1;
        inSibs->sib8.cdmaBandClass[0].bandIndicator = cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator;
        inSibs->sib8.cdmaBandClass[0].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY ;
        inSibs->sib8.cdmaBandClass[0].threshXLow = 6;
        inSibs->sib8.cdmaBandClass[0].threshXHigh = 8;
        inSibs->sib8.numberOfNeighCellPerBand = 1;
        inSibs->sib8.cdmaNeighCellPerBand[0].bandIndicator = cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator;
        inSibs->sib8.cdmaNeighCellPerBand[0].numberOfNeighCell = 1;
        inSibs->sib8.cdmaNeighCellPerBand[0].cdmaNeighCell[0].arfcn = cmd->redirectionInfo.cdmaRedirectinfo.startingarfcn;
        inSibs->sib8.cdmaNeighCellPerBand[0].cdmaNeighCell[0].noOfPhyCellId = 1;
        inSibs->sib8.cdmaNeighCellPerBand[0].cdmaNeighCell[0].phyCellId[0] = cmd->redirectionInfo.cdmaRedirectinfo.phyCellId;
    }
    else			
    {
        if(gAsnLteNeighConfigData.numberOfLteNeighbor > 0)
        {
            // Add SIB5 
            inSibs->sibMask |= SIB5_MASK;
            inSibs->sib5.noOfInterFreqNeighbourCells = gAsnLteNeighConfigData.numberOfLteNeighbor;

        	for(idx = 0; idx < gAsnLteNeighConfigData.numberOfLteNeighbor; idx++)
        	{
            inSibs->sib5.interFreqNeighbourCell[idx].dlCarrierFreq = gAsnLteNeighConfigData.lteNeighbors[idx].dlEarfcn;
    	    inSibs->sib5.interFreqNeighbourCell[idx].bandwidth = gAsnLteNeighConfigData.lteNeighbors[idx].bandwidth;
            inSibs->sib5.interFreqNeighbourCell[idx].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
            inSibs->sib5.interFreqNeighbourCell[idx].qRxLevMin = LTE_SIB3_Q_RXLEV_MIN;
            inSibs->sib5.interFreqNeighbourCell[idx].threshXHigh = 8;
            inSibs->sib5.interFreqNeighbourCell[idx].threshXLow = 6;
            inSibs->sib5.interFreqNeighbourCell[idx].tReselect = LTE_SIB3_TRESELECTION_EUTRA;
            inSibs->sib5.interFreqNeighbourCell[idx].cellConfig = 0xFFFFFFFF;
        	}
        }

        if(gAsnLteNeighConfigData.numberOfUmtsNeighbor > 0)
        {
           // Add SIB6 
           inSibs->sibMask |= SIB6_MASK;
           inSibs->sib6.noOfUmtsNeighborCells = gAsnLteNeighConfigData.numberOfUmtsNeighbor;

           for(idx = 0; idx < gAsnLteNeighConfigData.numberOfUmtsNeighbor; idx++)
           {
               inSibs->sib6.umtsNeighbourCell[idx].umtsCarrierFreq = gAsnLteNeighConfigData.dlUarfcn[idx];
               inSibs->sib6.umtsNeighbourCell[idx].pMaxUTRA = 33;
               inSibs->sib6.umtsNeighbourCell[idx].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
               inSibs->sib6.umtsNeighbourCell[idx].qQualMin = -18;
               inSibs->sib6.umtsNeighbourCell[idx].qRxLevMin = -58;
    	       inSibs->sib6.umtsNeighbourCell[idx].threshXLow = 6;
               inSibs->sib6.umtsNeighbourCell[idx].threshXHigh = 8;
           }
           inSibs->sib6.tReselectionUTRA = 2;
        }

        if(gAsnLteNeighConfigData.numberOfGsmNeighbor > 0)
        {
           // Add SIB7 
           inSibs->sibMask |= SIB7_MASK;
           inSibs->sib7.noOfGsmNeighborCells = gAsnLteNeighConfigData.numberOfGsmNeighbor;

           for(idx = 0; idx < gAsnLteNeighConfigData.numberOfGsmNeighbor; idx++)
           {
               inSibs->sib7.gsmNeighbourCell[idx].startingARFCN = gAsnLteNeighConfigData.gsmNeighbors[idx].arfcn;
    	       inSibs->sib7.gsmNeighbourCell[idx].bandIndicator = gAsnLteNeighConfigData.gsmNeighbors[idx].bandIndicator;
               inSibs->sib7.gsmNeighbourCell[idx].followingArfcnType = LTE_FOLLOWING_ARFCN_EXPLICITLIST;
    	       inSibs->sib7.gsmNeighbourCell[idx].neighborList.expArfcn.noOfArfcn = 1;
               inSibs->sib7.gsmNeighbourCell[idx].neighborList.expArfcn.ARFCN_ValueGERAN[0] = gAsnLteNeighConfigData.gsmNeighbors[idx].arfcn + 1;
               inSibs->sib7.gsmNeighbourCell[idx].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
    	       inSibs->sib7.gsmNeighbourCell[idx].pMaxGeran = 27;
               inSibs->sib7.gsmNeighbourCell[idx].qRxLevMin = 10;
    	       inSibs->sib7.gsmNeighbourCell[idx].threshXLow = 0;
               inSibs->sib7.gsmNeighbourCell[idx].threshXHigh = 0;
           }
           inSibs->sib7.tReselectionGERAN = 0;
        }
    }

    if(SERVING_CELL_3G == cmd->emeCallSrvCellType)
    {
        if (REDIRECTION_TO_3G == cmd->redirectionType)
        {
           inSibs->sib6.noOfUmtsNeighborCells = 2;
           inSibs->sib6.umtsNeighbourCell[1].umtsCarrierFreq = cmd->emeCallSrvCellInfo.utraFDDUARFCN;
           inSibs->sib6.umtsNeighbourCell[1].pMaxUTRA = 24;
           inSibs->sib6.umtsNeighbourCell[1].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib6.umtsNeighbourCell[1].qQualMin = -18;
           inSibs->sib6.umtsNeighbourCell[1].qRxLevMin = -58;
           inSibs->sib6.umtsNeighbourCell[1].threshXLow = 0;
           inSibs->sib6.umtsNeighbourCell[1].threshXHigh = 0;
        }
        else if(gAsnLteNeighConfigData.numberOfUmtsNeighbor > 0)
        {
           inSibs->sib6.noOfUmtsNeighborCells = gAsnLteNeighConfigData.numberOfUmtsNeighbor + 1;
           idx = gAsnLteNeighConfigData.numberOfUmtsNeighbor;

           inSibs->sib6.umtsNeighbourCell[idx].umtsCarrierFreq = cmd->emeCallSrvCellInfo.utraFDDUARFCN;
           inSibs->sib6.umtsNeighbourCell[idx].pMaxUTRA = 33;
           inSibs->sib6.umtsNeighbourCell[idx].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib6.umtsNeighbourCell[idx].qQualMin = -18;
           inSibs->sib6.umtsNeighbourCell[idx].qRxLevMin = -58;
           inSibs->sib6.umtsNeighbourCell[idx].threshXLow = 6;
           inSibs->sib6.umtsNeighbourCell[idx].threshXHigh = 8;
        }
        else
        {
           // Add SIB6 
           inSibs->sibMask |= SIB6_MASK;
           inSibs->sib6.noOfUmtsNeighborCells = 1;
           inSibs->sib6.umtsNeighbourCell[0].umtsCarrierFreq = cmd->emeCallSrvCellInfo.utraFDDUARFCN;
           inSibs->sib6.umtsNeighbourCell[0].pMaxUTRA = 24;
           inSibs->sib6.umtsNeighbourCell[0].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib6.umtsNeighbourCell[0].qQualMin = -18;
           inSibs->sib6.umtsNeighbourCell[0].qRxLevMin = -58;
           inSibs->sib6.umtsNeighbourCell[0].threshXLow = 0;
           inSibs->sib6.umtsNeighbourCell[0].threshXHigh = 0;
           inSibs->sib6.tReselectionUTRA = 0;
        }
    }
    else if (SERVING_CELL_2G == cmd->emeCallSrvCellType)
    {
        if (REDIRECTION_TO_2G == cmd->redirectionType)
        {
           inSibs->sib7.noOfGsmNeighborCells = 1;
           inSibs->sib7.gsmNeighbourCell[1].startingARFCN = cmd->emeCallSrvCellInfo.gsmCellInfo.startingarfcn;
           inSibs->sib7.gsmNeighbourCell[1].bandIndicator = cmd->emeCallSrvCellInfo.gsmCellInfo.bandIndicator;
           inSibs->sib7.gsmNeighbourCell[1].followingArfcnType = LTE_FOLLOWING_ARFCN_EXPLICITLIST;
           inSibs->sib7.gsmNeighbourCell[1].neighborList.expArfcn.noOfArfcn = 0;
           //inSibs->sib7.gsmNeighbourCell[1].neighborList.expArfcn.ARFCN_ValueGERAN[0] =
           //                                          cmd->emeCallSrvCellInfo.gsmCellInfo.startingarfcn + 1;
           inSibs->sib7.gsmNeighbourCell[1].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib7.gsmNeighbourCell[1].pMaxGeran = 27;
           inSibs->sib7.gsmNeighbourCell[1].qRxLevMin = 10;
           inSibs->sib7.gsmNeighbourCell[1].threshXLow = 0;
           inSibs->sib7.gsmNeighbourCell[1].threshXHigh = 0;
		   inSibs->sib7.tReselectionGERAN = 0;
        }
        else if(gAsnLteNeighConfigData.numberOfGsmNeighbor > 0)
        {
           inSibs->sib7.noOfGsmNeighborCells = gAsnLteNeighConfigData.numberOfGsmNeighbor + 1;
           idx = gAsnLteNeighConfigData.numberOfGsmNeighbor;

           inSibs->sib7.gsmNeighbourCell[idx].startingARFCN = cmd->emeCallSrvCellInfo.gsmCellInfo.startingarfcn;
           inSibs->sib7.gsmNeighbourCell[idx].bandIndicator = cmd->emeCallSrvCellInfo.gsmCellInfo.bandIndicator;
           inSibs->sib7.gsmNeighbourCell[idx].followingArfcnType = LTE_FOLLOWING_ARFCN_EXPLICITLIST;
           inSibs->sib7.gsmNeighbourCell[idx].neighborList.expArfcn.noOfArfcn = 1;
           inSibs->sib7.gsmNeighbourCell[idx].neighborList.expArfcn.ARFCN_ValueGERAN[0] =
                                                     cmd->emeCallSrvCellInfo.gsmCellInfo.startingarfcn + 1;
           inSibs->sib7.gsmNeighbourCell[idx].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib7.gsmNeighbourCell[idx].pMaxGeran = 27;
           inSibs->sib7.gsmNeighbourCell[idx].qRxLevMin = 18;
           inSibs->sib7.gsmNeighbourCell[idx].threshXLow = 1;
           inSibs->sib7.gsmNeighbourCell[idx].threshXHigh = 1;
		   inSibs->sib7.tReselectionGERAN = 0;
        }
        else
        {
           // Add SIB7 
           inSibs->sibMask |= SIB7_MASK;
           inSibs->sib7.noOfGsmNeighborCells = 1;
           inSibs->sib7.gsmNeighbourCell[0].startingARFCN = cmd->emeCallSrvCellInfo.gsmCellInfo.startingarfcn;
           inSibs->sib7.gsmNeighbourCell[0].bandIndicator = cmd->emeCallSrvCellInfo.gsmCellInfo.bandIndicator;
           inSibs->sib7.gsmNeighbourCell[0].followingArfcnType = LTE_FOLLOWING_ARFCN_EXPLICITLIST;
           inSibs->sib7.gsmNeighbourCell[0].neighborList.expArfcn.noOfArfcn = 0;
           //inSibs->sib7.gsmNeighbourCell[0].neighborList.expArfcn.ARFCN_ValueGERAN[0] =
           //                                          cmd->emeCallSrvCellInfo.gsmCellInfo.startingarfcn + 1;
           inSibs->sib7.gsmNeighbourCell[0].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib7.gsmNeighbourCell[0].pMaxGeran = 27;
           inSibs->sib7.gsmNeighbourCell[0].qRxLevMin = 10;
           inSibs->sib7.gsmNeighbourCell[0].threshXLow = 0;
           inSibs->sib7.gsmNeighbourCell[0].threshXHigh = 0;
           inSibs->sib7.tReselectionGERAN = 0;
        }
    }
    else if (SERVING_CELL_CDMA == cmd->emeCallSrvCellType)
    {
        if (REDIRECTION_TO_CDMA == cmd->redirectionType)
        {
           inSibs->sib8.numberOfBandClass = 2;
           inSibs->sib8.cdmaBandClass[1].bandIndicator = cmd->emeCallSrvCellInfo.cdmaCellInfo.bandIndicator;
           inSibs->sib8.cdmaBandClass[1].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib8.cdmaBandClass[1].threshXLow = 6;
           inSibs->sib8.cdmaBandClass[1].threshXHigh = 8;
           inSibs->sib8.numberOfNeighCellPerBand = 2;
           inSibs->sib8.cdmaNeighCellPerBand[1].bandIndicator = cmd->emeCallSrvCellInfo.cdmaCellInfo.bandIndicator;
           inSibs->sib8.cdmaNeighCellPerBand[1].numberOfNeighCell = 1;
           inSibs->sib8.cdmaNeighCellPerBand[1].cdmaNeighCell[0].arfcn = cmd->emeCallSrvCellInfo.cdmaCellInfo.startingarfcn;
           inSibs->sib8.cdmaNeighCellPerBand[1].cdmaNeighCell[0].noOfPhyCellId = 1;
           inSibs->sib8.cdmaNeighCellPerBand[1].cdmaNeighCell[0].phyCellId[0] = cmd->emeCallSrvCellInfo.cdmaCellInfo.phyCellId;
        }
        else
        {
           // Add SIB8 
           inSibs->sibMask |= SIB8_MASK;
           inSibs->sib8.tReselectionCDMA2000 = 2;
           inSibs->sib8.numberOfBandClass = 1;
           inSibs->sib8.cdmaBandClass[0].bandIndicator = cmd->emeCallSrvCellInfo.cdmaCellInfo.bandIndicator;
           inSibs->sib8.cdmaBandClass[0].cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY - 1;
           inSibs->sib8.cdmaBandClass[0].threshXLow = 6;
           inSibs->sib8.cdmaBandClass[0].threshXHigh = 8;
           inSibs->sib8.numberOfNeighCellPerBand = 1;
           inSibs->sib8.cdmaNeighCellPerBand[0].bandIndicator = cmd->emeCallSrvCellInfo.cdmaCellInfo.bandIndicator;
           inSibs->sib8.cdmaNeighCellPerBand[0].numberOfNeighCell = 1;
           inSibs->sib8.cdmaNeighCellPerBand[0].cdmaNeighCell[0].arfcn = cmd->emeCallSrvCellInfo.cdmaCellInfo.startingarfcn;
           inSibs->sib8.cdmaNeighCellPerBand[0].cdmaNeighCell[0].noOfPhyCellId = 1;
           inSibs->sib8.cdmaNeighCellPerBand[0].cdmaNeighCell[0].phyCellId[0] = cmd->emeCallSrvCellInfo.cdmaCellInfo.phyCellId;
        }
    }
    else
    {
        //Do Nothing
    } 
*/
#endif	
	asn1EncodedSibs = buildAndEncodeSib2345(inSibs , &asn1EncodedSibsLen); // Here memory is allocated inside this function.
	logPrint(LOG_DEBUG , "Encoded SIBS Size = %d \n" , asn1EncodedSibsLen);
	
	cleanLteASNContext();
	free(inSibs);
        inSibs = NULL;
/*
	if(asn1EncodedSibs != NULL)
	{
		uint8 i = 0;
		for(i = 0; i<asn1EncodedSibsLen; i++ )
		{
			logPrint(LOG_DEBUG , "%02x ",asn1EncodedSibs[i] );
		}
	}

	buildPdcchPacketForMib(4 , 0);
	buildTxDataPacketForMib(4 , 0);
*/	
	buildPdcchPacketForSib1(8 , 5);
	buildTxDataPacketForSib1(8 , 5);
}

void generateSib1Modify(fxL4gSysInfoModifyCmd * cmd)
{
	lteSib1Struct inSib1 = {0};
	uint8* asnBuf = NULL;
	uint8 i = 0, j = 0;

	memset(asn1EncodedSib1 , 0 , LTE_MAC_SIB1_PDU_SIZE);
	asn1EncodedSib1Len = 0;
	if(initializeLteASNContext("Sib1ModifyBuildTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "SIB1 MODIFY ASN1 DECODING FAILED");
		return;
	}

       // DO NOT CHANGE	
	inSib1.cellId = htonl(sysInfoModify.layer3CellId << 4);//LTE_LAYER3_CELL_IDENTITY_VALUE;
	inSib1.freqBandIndicator = sysInfoModify.bandIndicator;//LTE_FREQUENCY_BAND_INDICATOR;
	inSib1.noOfPlmns = sysInfoModify.numOfPlmn;
	for (i = 0; i < inSib1.noOfPlmns; i++)
	{
	    inSib1.plmn[i].mccLength = sysInfoModify.plmn[i].mccLength;
		for (j = 0; j < inSib1.plmn[i].mccLength; j++)
		{
		    inSib1.plmn[i].mcc[j] = sysInfoModify.plmn[i].mcc[j];
		}

	    inSib1.plmn[i].mncLength = sysInfoModify.plmn[i].mncLength;
		for (j = 0; j < inSib1.plmn[i].mncLength; j++)
		{
		    inSib1.plmn[i].mnc[j] = sysInfoModify.plmn[i].mnc[j];
		}
	}
	inSib1.siWindowLength = LTE_SI_WINDOW_LENGTH_MS5;
	inSib1.siPeriodicity = LTE_SI_PERIODICITY_RF32; //set the LTE_SIBS_REPITITION_FRAMES accordingly when you change this
    if((inSib1.freqBandIndicator > 32)&&(inSib1.freqBandIndicator < 53))
    {
        inSib1.ulDLConfig = LTE_TDD_UD_CONFIG;
        inSib1.specialsubfAssg = LTE_TDD_SPECIALSUBF_ASSG;
    }
    inSib1.trackingAreaCode = htons(lastLteIdCatcherConfigCmd.tac);

	//Defaults
	inSib1.qRxLevMin = LTE_SIB1_Q_RXLEV_MIN;
	inSib1.qRxLevMinOffset = LTE_SIB1_Q_RXLEV_MIN_OFFSET;
	inSib1.isCellBarred = FALSE; // 1- not Barred
	inSib1.isIntraFreqSelectionAllowed = TRUE; // TRUE-Not- Allowed , FALSE - Allowed //Need to check and update 
    inSib1.systemValueTag = (systeInfoTagGlobal++)%31;
        inSib1.sibMask = 0;

	//User Sib Update
	if((cmd->sibMask & SIB1_MASK) == SIB1_MASK)
	{	
		logPrint(LOG_DEBUG, " User defined SIB1 generation Called");
		LTE_ASSIGN_NON_NEGATIVE(	inSib1.isCellBarred , cmd->sib1.isCellBarred); // 1- not Barred
		LTE_ASSIGN_NON_NEGATIVE(	inSib1.isIntraFreqSelectionAllowed , cmd->sib1.isIntraFreqSelectionAllowed); // TRUE-Not- Allowed , FALSE - Allowed //Need to check and update 
		LTE_ASSIGN_NON_NEGATIVE(	inSib1.systemValueTag ,cmd->sib1.systemValueTag);
		if (cmd->sib1.tac != -1)
		inSib1.trackingAreaCode = htons(cmd->sib1.tac);

		if (cmd->sib1.qRxLevMinOffset != -1)
		inSib1.qRxLevMinOffset =  cmd->sib1.qRxLevMinOffset;
		
		if ((cmd->sib1.qRxLevMin > -71) && (cmd->sib1.qRxLevMin < -21))
		inSib1.qRxLevMin = cmd->sib1.qRxLevMin;

		if ((cmd->sib1.pMax> -31) && (cmd->sib1.pMax < 34))
			inSib1.pMax = cmd->sib1.pMax;

	}

	asnBuf = buildAndEncodeSib1(&inSib1 , &asn1EncodedSib1Len); // Here memory is allocated inside this function.
	logPrint(LOG_DEBUG , "Encoded SIB1 Modify Size = %d \n" , asn1EncodedSib1Len );
	cleanLteASNContext();
	if((asnBuf != NULL)&&(asn1EncodedSib1Len != 0))
	{
		memcpy(asn1EncodedSib1, asnBuf, asn1EncodedSib1Len);
		logPrint(LOG_DEBUG , " asn1EncodedSib1 updated \n" );
		free(asnBuf);
	}
}

void generateSibsModify(fxL4gSysInfoModifyCmd * cmd)
{
	lteSibsStruct *inSibs = NULL ;

	if(asn1EncodedSibs != NULL)
	{
		free(asn1EncodedSibs);
	}
	
	asn1EncodedSibs = NULL;
	asn1EncodedSibsLen = 0;
	if(initializeLteASNContext("SibsModifyBuildTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "SIBS MODIFY ASN1 DECODING FAILED");
		return;
	}

	inSibs = (lteSibsStruct *)malloc(sizeof(lteSibsStruct)) ;

    inSibs->sibMask = 0;
	inSibs->isitTdd = lteDuplxMode;
	//Defaults
	inSibs->sibMask |= SIB2_MASK;
	inSibs->sib2.alpha = LTE_UL_POWER_CONTROL_ALPHA_7;
	inSibs->sib2.cyclicPrefixLen = LTE_CYCLIC_PREFIX_LEN_1;
	inSibs->sib2.deltaPreambleMsg3 = LTE_SIB2_DELTA_PREAMBLE_MSG3;
	inSibs->sib2.drxCycle = LTE_DRX_CYCLE_RF32;
	inSibs->sib2.enable64QAM = TRUE;
	inSibs->sib2.format1Delta = LTE_PUCCH_FORMAT1_DELTA_0;
	inSibs->sib2.format1bDelta = LTE_PUCCH_FORMAT1B_DELTA_3;
	inSibs->sib2.format2Delta = LTE_PUCCH_FORMAT2_DELTA_1;
	inSibs->sib2.format2aDelta = LTE_PUCCH_FORMAT2A_DELTA_2;
	inSibs->sib2.format2bDelta = LTE_PUCCH_FORMAT2B_DELTA_2;
	inSibs->sib2.hoppingMode = LTE_HOPPING_MODE_INTERSUBFRAME; // sync with cell config
	inSibs->sib2.isBarredForEmergency = FALSE;
	inSibs->sib2.isBarredForMoData = FALSE;
	inSibs->sib2.isBarredForMoSignalling = FALSE;
    inSibs->sib2.isBarredForMmtelVoice = FALSE;
	inSibs->sib2.isBarredForMmtelVideo = FALSE;
	inSibs->sib2.isBarredForCsfb = FALSE;
	inSibs->sib2.isGroupHoppingEnabled = FALSE; //// sync with cell config
	inSibs->sib2.isHighSpeedFlagSet = FALSE;
	inSibs->sib2.isSequenceHoppingEnabled = FALSE;
	inSibs->sib2.isSrsAckNackSimultaeneousTransmissionAllowed = FALSE; // sync with cell config
	inSibs->sib2.maxHARQMsg3Tx = LTE_SIB2_MAX_HARQ_MSG3_TX;
	inSibs->sib2.modficationCoeff = LTE_BCCH_MODIFICATION_PERIOD_COEFF_N16;
	inSibs->sib2.n310 = LTE_UE_CONSTANT_N310_10;
	inSibs->sib2.n311 = LTE_UE_CONSTANT_N310_1;
	inSibs->sib2.nB = LTE_PCCH_NB_1T ;

	inSibs->sib2.noRaPreambles = LTE_NO_RA_PREAMBLES_16;//LTE_NO_RA_PREAMBLES_52;
	inSibs->sib2.powerRampingStep = LTE_RACH_POWER_RAMPING_STEP_DB2;
	inSibs->sib2.prachFreqOffset = LTE_PRACH_FREQUENCY_OFFSET;
    if (lteDuplxMode)
    {
		 inSibs->sib2.prachZeroCorrelationZoneConfig = LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX_TDD;
		 inSibs->sib2.prachConfigIndex =  LTE_PRACH_CONFIGURATION_INDEX_TDD;
		 inSibs->sib2.n1PucchAN = LTE_PUCCH_AN_TDD;
		 inSibs->sib2.pB = LTE_PB_VALUE_TDD;
		 inSibs->sib2.p0NominalPUSCH = LTE_PO_NOMINAL_PUSCH_TDD; // This may need to tuning
		 inSibs->sib2.refSignalPower = LTE_REFERENCE_SIGNAL_POWER_TDD;
		 inSibs->sib2.p0NominalPUCCH = LTE_PO_NOMINAL_PUCCH_TDD;
		 inSibs->sib2.n1CsAn = LTE_PUCCH_NUM_CYCLIC_SHIFT_TDD;
		 inSibs->sib2.nRBCqi = LTE_PUCCH_NUM_CQI_RB_ALLOCATED_TDD;
    }
    else
    {
		inSibs->sib2.prachZeroCorrelationZoneConfig = LTE_PRACH_ZERO_CORRELATION_ZONE_CONFIGURATION_INDEX;
		inSibs->sib2.prachConfigIndex = LTE_PRACH_CONFIGURATION_INDEX;
		inSibs->sib2.n1PucchAN = LTE_PUCCH_AN;
		inSibs->sib2.pB = LTE_PB_VALUE;
		inSibs->sib2.p0NominalPUSCH = LTE_PO_NOMINAL_PUSCH; // This may need to tuning
		inSibs->sib2.refSignalPower = LTE_REFERENCE_SIGNAL_POWER;
		inSibs->sib2.p0NominalPUCCH = LTE_PO_NOMINAL_PUCCH;
		inSibs->sib2.n1CsAn = LTE_PUCCH_NUM_CYCLIC_SHIFT;
		inSibs->sib2.nRBCqi = LTE_PUCCH_NUM_CQI_RB_ALLOCATED;
    }
	inSibs->sib2.preambleTargetPower = LTE_INITIAL_PREAMBLE_TARGET_POWER_104DBM; //LTE_INITIAL_PREAMBLE_TARGET_POWER_94DBM;
	inSibs->sib2.pucchDeltaShift = LTE_PUCCH_DELTA_SHIFT_2 ; 
	inSibs->sib2.puschGroupAssignment = LTE_PUSCH_GROUP_ASSIGNEMENT;
	inSibs->sib2.puschHoppingOffset = LTE_PUSCH_HOPPING_OFFSET;
	inSibs->sib2.puschNSB = LTE_PUSCH_NUM_OF_SUBBANDS;
	inSibs->sib2.puschRefSigCyclicShift = LTE_PUSCH_REF_SIG_CYCLIC_SHIFT;
	inSibs->sib2.rootSequenceIndex = LTE_PRACH_ROOT_SEQUENCE_INDEX;
	inSibs->sib2.srsBw = LTE_SRS_BANDWIDTH_0;//LTE_SRS_BANDWIDTH_CONFIGURATION
	inSibs->sib2.srsSubframe = LTE_SRS_SUBFRAME_0;
	inSibs->sib2.t300 = LTE_UE_TIMER_T300_2000 ;
	inSibs->sib2.t301 = LTE_UE_TIMER_T301_2000;
	inSibs->sib2.t310 = LTE_UE_TIMER_T310_1000;
	inSibs->sib2.t311 = LTE_UE_TIMER_T311_5000;
	inSibs->sib2.taTimer = LTE_UL_TIME_ALIGNMENT_TIMER_10240;
	inSibs->sib2.macContentionResolutionTimer = LTE_CONTENTION_RESOLUTION_TIMER_SF64;
	inSibs->sib2.preambleTransMax = LTE_PREAMBLE_TRANS_MAX_N10; 
	inSibs->sib2.raResponseWindow = LTE_RA_RESPONSE_WINDOW_10;

//    if (!lteDuplxMode) // FDD case
    {
		inSibs->sib2.ulBandwidth = lteSelectedBandwidth;  // For TDD , there parameters are same as DL BW n Freq.
		inSibs->sib2.ulFrequency = 0;//23799;
    }
//    else 
//    {
//        inSibs->sib2.ulBandwidth = 0; // TDD Case
//    }
        inSibs->sibMask |= SIB3_MASK;     
	inSibs->sib3.cellReselectionPriority = LTE_SIB3_CELL_RESELECTION_PRIORITY;
	inSibs->sib3.isAntennaPort1Present = FALSE;
	inSibs->sib3.qHyst = LTE_RESELECTION_QHYSTERIS_4;
	inSibs->sib3.qRxLevMin = LTE_SIB3_Q_RXLEV_MIN;
	inSibs->sib3.tReselectionEUTRA = LTE_SIB3_TRESELECTION_EUTRA; //TBD Add highest value here
	inSibs->sib3.threshServingLow = LTE_SIB3_THRESH_SERVING_LOW;
	inSibs->sib3.sIntraSearch = LTE_SIB3_SINTRASEARCH;
	inSibs->sib3.sNonIntraSearch = LTE_SIB3_SNONINTRASEARCH;

	if((cmd->sibMask & SIB2_MASK) == SIB2_MASK)
	{
		
		logPrint(LOG_DEBUG, " User defined SIB2 generation Called");
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.alpha , cmd->sib2.alpha);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.cyclicPrefixLen , cmd->sib2.cyclicPrefixLen);

		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.enable64QAM , cmd->sib2.enable64QAM);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.format1Delta , cmd->sib2.format1bDelta);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.format1bDelta , cmd->sib2.format1Delta);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.format2Delta , cmd->sib2.format2Delta);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.format2aDelta , cmd->sib2.format2aDelta);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.format2bDelta , cmd->sib2.format2bDelta);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.hoppingMode , cmd->sib2.hoppingMode); // sync with cell config
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isBarredForEmergency , cmd->sib2.isBarredForEmergency);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isBarredForMoData , cmd->sib2.isBarredForMoData);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isBarredForMoSignalling , cmd->sib2.isBarredForMoSignalling);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isGroupHoppingEnabled , cmd->sib2.isGroupHoppingEnabled); //// sync with cell config
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isHighSpeedFlagSet , cmd->sib2.isHighSpeedFlagSet);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isSequenceHoppingEnabled , cmd->sib2.isSequenceHoppingEnabled);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isSrsAckNackSimultaeneousTransmissionAllowed , cmd->sib2.isSrsAckNackSimultaeneousTransmissionAllowed); // sync with cell config
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.maxHARQMsg3Tx , cmd->sib2.maxHARQMsg3Tx);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.modficationCoeff , cmd->sib2.modficationCoeff);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.n310 , cmd->sib2.n310);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.n311 , cmd->sib2.n311);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.nB , cmd->sib2.nB);

		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.noRaPreambles , cmd->sib2.noRaPreambles);//LTE_NO_RA_PREAMBLES_52);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.powerRampingStep , cmd->sib2.powerRampingStep);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.prachFreqOffset , cmd->sib2.prachFreqOffset);

		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.prachZeroCorrelationZoneConfig , cmd->sib2.prachZeroCorrelationZoneConfig);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.prachConfigIndex , cmd->sib2.prachConfigIndex);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.n1PucchAN , cmd->sib2.n1PucchAN);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.pB , cmd->sib2.pB);

		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.n1CsAn , cmd->sib2.n1CsAn);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.nRBCqi , cmd->sib2.nRBCqi);
		
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.preambleTargetPower , cmd->sib2.preambleTargetPower); //LTE_INITIAL_PREAMBLE_TARGET_POWER_94DBM);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.pucchDeltaShift , cmd->sib2.pucchDeltaShift); 
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.puschGroupAssignment , cmd->sib2.puschGroupAssignment);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.puschHoppingOffset , cmd->sib2.puschHoppingOffset);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.puschNSB , cmd->sib2.puschNSB);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.puschRefSigCyclicShift , cmd->sib2.puschRefSigCyclicShift);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.rootSequenceIndex , cmd->sib2.rootSequenceIndex);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.srsBw , cmd->sib2.srsBw);//LTE_SRS_BANDWIDTH_CONFIGURATION
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.srsSubframe , cmd->sib2.srsSubframe);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.t300 , cmd->sib2.t300);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.t301 , cmd->sib2.t301);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.t310 , cmd->sib2.t310);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.t311 , cmd->sib2.t311);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.taTimer , cmd->sib2.taTimer);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.macContentionResolutionTimer , cmd->sib2.macContentionResolutionTimer);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.preambleTransMax , cmd->sib2.preambleTransMax); 
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.raResponseWindow , cmd->sib2.raResponseWindow);
            	LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isBarredForMmtelVoice , cmd->sib2.isBarredForMmtelVoice);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isBarredForMmtelVideo , cmd->sib2.isBarredForMmtelVideo);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib2.isBarredForCsfb , cmd->sib2.isBarredForCsfb);

		if((cmd->sib2.deltaPreambleMsg3 > -2)&&(cmd->sib2.deltaPreambleMsg3 < 7))
			inSibs->sib2.deltaPreambleMsg3 = cmd->sib2.deltaPreambleMsg3;
		if((cmd->sib2.p0NominalPUSCH > -127)&&(cmd->sib2.p0NominalPUSCH < 25))
			inSibs->sib2.p0NominalPUSCH = cmd->sib2.p0NominalPUSCH; 
		if((cmd->sib2.refSignalPower > -61)&&(cmd->sib2.refSignalPower < 51))
			inSibs->sib2.refSignalPower = cmd->sib2.refSignalPower;
		if((cmd->sib2.p0NominalPUCCH > -128)&&(cmd->sib2.p0NominalPUCCH < -95))
			inSibs->sib2.p0NominalPUCCH = cmd->sib2.p0NominalPUCCH;

        if(inSibs->sib2.isBarredForMoSignalling)
        {
            inSibs->sib2.moSignallingBarringInfo.acBarringFactor = cmd->sib2.moSignallingBarringInfo.acBarringFactor;
            inSibs->sib2.moSignallingBarringInfo.acBarringTime = cmd->sib2.moSignallingBarringInfo.acBarringTime;
            inSibs->sib2.moSignallingBarringInfo.acBarringForSpecialAC = cmd->sib2.moSignallingBarringInfo.acBarringForSpecialAC;
        }

        if(inSibs->sib2.isBarredForMoData)
        {
            inSibs->sib2.moDataBarringInfo.acBarringFactor = cmd->sib2.moDataBarringInfo.acBarringFactor;
            inSibs->sib2.moDataBarringInfo.acBarringTime = cmd->sib2.moDataBarringInfo.acBarringTime;
            inSibs->sib2.moDataBarringInfo.acBarringForSpecialAC = cmd->sib2.moDataBarringInfo.acBarringForSpecialAC;
        }

        if(inSibs->sib2.isBarredForMmtelVoice)
        {
            inSibs->sib2.ssacMmtelVoiceBarringInfo.acBarringFactor = cmd->sib2.ssacMmtelVoiceBarringInfo.acBarringFactor;
            inSibs->sib2.ssacMmtelVoiceBarringInfo.acBarringTime = cmd->sib2.ssacMmtelVoiceBarringInfo.acBarringTime;
            inSibs->sib2.ssacMmtelVoiceBarringInfo.acBarringForSpecialAC = cmd->sib2.ssacMmtelVoiceBarringInfo.acBarringForSpecialAC;
        }

        if(inSibs->sib2.isBarredForMmtelVideo)
        {
            inSibs->sib2.ssacMmtelVideoBarringInfo.acBarringFactor = cmd->sib2.ssacMmtelVideoBarringInfo.acBarringFactor;
            inSibs->sib2.ssacMmtelVideoBarringInfo.acBarringTime = cmd->sib2.ssacMmtelVideoBarringInfo.acBarringTime;
            inSibs->sib2.ssacMmtelVideoBarringInfo.acBarringForSpecialAC = cmd->sib2.ssacMmtelVideoBarringInfo.acBarringForSpecialAC;
        }

       if(inSibs->sib2.isBarredForCsfb)
       {
            inSibs->sib2.csfbBarringInfo.acBarringFactor = cmd->sib2.csfbBarringInfo.acBarringFactor;
            inSibs->sib2.csfbBarringInfo.acBarringTime = cmd->sib2.csfbBarringInfo.acBarringTime;
            inSibs->sib2.csfbBarringInfo.acBarringForSpecialAC = cmd->sib2.csfbBarringInfo.acBarringForSpecialAC;
       }
	}

	if((cmd->sibMask & SIB3_MASK) == SIB3_MASK)
	{
		logPrint(LOG_DEBUG, " User defined SIB3 generation Called");
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.cellReselectionPriority , cmd->sib3.cellReselectionPriority);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.isAntennaPort1Present , cmd->sib3.isAntennaPort1Present);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.qHyst , cmd->sib3.qHyst);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.tReselectionEUTRA , cmd->sib3.tReselectionEUTRA); //TBD Add highest value here
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.threshServingLow , cmd->sib3.threshServingLow);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.sIntraSearch , cmd->sib3.sIntraSearch);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.sNonIntraSearch , cmd->sib3.sNonIntraSearch);
		LTE_ASSIGN_NON_NEGATIVE(inSibs->sib3.neighbourCellConfig , cmd ->sib3.neighbourCell);

		if ((cmd->sib3.qRxLevMin > -71) && (cmd->sib3.qRxLevMin < -21))
		inSibs->sib3.qRxLevMin = cmd->sib3.qRxLevMin;
	}
	
	asn1EncodedSibs = buildAndEncodeSib2345(inSibs , &asn1EncodedSibsLen); // Here memory is allocated inside this function.
	logPrint(LOG_DEBUG , "Encoded SIBS MODIFY Size = %d \n" , asn1EncodedSibsLen);

	cleanLteASNContext();
	free(inSibs);
/*
	if(asn1EncodedSibs != NULL)
	{
		uint8 i = 0;
		for(i = 0; i<asn1EncodedSibsLen; i++ )
		{
			logPrint(LOG_DEBUG , "%02x ",asn1EncodedSibs[i] );
		}
	}
*/
}

lteRrcConnSetupStruct inRrrConnectionSetup = {0};
void generateRrcConnectionSetup()
{
	if(asn1EncodedRrcConnectionSetup !=NULL)
	{
		free(asn1EncodedRrcConnectionSetup);
	}
	asn1EncodedRrcConnectionSetup = NULL;
	asn1EncodedRrcConnectionSetupLen = 0;
	if(initializeLteASNContext("RrcConnectionSetupBuildTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcConnectionSetup ASN1 ENCODING FAILED");
		return;
	}

	inRrrConnectionSetup.dsrTransMax = LTE_SRSETUP_DSR_TRANS_MAX_n64;

	inRrrConnectionSetup.rlcAmMaxRetxThreshold = LTE_RLC_RETX_THRESHOLD_32;
	inRrrConnectionSetup.rlcAmPollByte = LTE_RLCAM_POLL_BYTE_125; //LTE_RLCAM_POLL_BYTE_25;
	inRrrConnectionSetup.rlcAmPollPdu = LTE_RLCAM_POLL_PDU_128; //LTE_RLCAM_POLL_PDU_4;
	inRrrConnectionSetup.rlcAmPollRetxTimer = LTE_RLCAM_POLL_RETX_TIMER_ms500; //LTE_RLCAM_POLL_RETX_TIMER_ms80;
	inRrrConnectionSetup.rrcTransactionId = 0;
	inRrrConnectionSetup.srConfigIndex = LTE_SR_INDEX;
	inRrrConnectionSetup.lteDuplexMode = 0;
	inRrrConnectionSetup.pdschPAValue = LTE_PDSCH_CONFIG_PA_VALUE_dB_3;
	inRrrConnectionSetup.srPucchResourceIndex = LTE_DEDICATED_MODE_PUCCH_RESOURCE_INDEX;
	inRrrConnectionSetup.srbIdentity = 1;
	inRrrConnectionSetup.taTimerDedicated = LTE_TA_DEDICATED_MODE_TIMER_sf10240;
	inRrrConnectionSetup.ulSchMaxHarqTx = LTE_ULSCH_MAX_HARQ_TX_n1;//LTE_ULSCH_MAX_HARQ_TX_n5;
	inRrrConnectionSetup.ulSchPeriodicBsrTimer = LTE_ULSCH_PERIODIC_BSR_TIMER_sf32;
	inRrrConnectionSetup.ulSchRetxBsrTimer = LTE_ULSCH_RETX_BSR_TIMER_sf2560;
	inRrrConnectionSetup.rlcAmDlTStatusReorderingTimer = LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS0;
	inRrrConnectionSetup.rlcAmDlTreorderingTimer = LTE_RLCAMDL_TREORDERING_TIMER_MS80;
	inRrrConnectionSetup.phrDlPathLoss = LTE_PHR_DL_PATHLOSS_dB1;
	inRrrConnectionSetup.phrPeriodicTimerValue = LTE_PERIODIC_PHR_TIMER_sf100;
	inRrrConnectionSetup.phrProhibitTimerValue = LTE_PROHIBIT_PHR_TIMER_sf0;//LTE_PROHIBIT_PHR_TIMER_sf100;
	asn1EncodedRrcConnectionSetup = buildAndEncodeRrcConnectionSetup(&inRrrConnectionSetup , &asn1EncodedRrcConnectionSetupLen); // Here memory is allocated inside this function.
	//logPrint(LOG_DEBUG , "Encoded RrcConnectionSetup Size = %d \n" , asn1EncodedRrcConnectionSetupLen );
	cleanLteASNContext();

}

void generateRrcConnectionSetupTDD()
{
	if(asn1EncodedRrcConnectionSetupTdd !=NULL)
	{
		free(asn1EncodedRrcConnectionSetupTdd);
	}
	asn1EncodedRrcConnectionSetupTdd = NULL;
	asn1EncodedRrcConnectionSetupTddLen = 0;
	if(initializeLteASNContext("RrcConnectionSetupTddBuildTrace1.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcConnectionSetup ASN1 ENCODING FAILED");
		return;
	}

	inRrrConnectionSetup.dsrTransMax = LTE_SRSETUP_DSR_TRANS_MAX_n64;
	inRrrConnectionSetup.pdschPAValue = LTE_PDSCH_CONFIG_PA_VALUE_dB_3;//LTE_PDSCH_CONFIG_PA_VALUE_dB0;
	inRrrConnectionSetup.rlcAmMaxRetxThreshold = LTE_RLC_RETX_THRESHOLD_32;
	inRrrConnectionSetup.rlcAmPollByte = LTE_RLCAM_POLL_BYTE_125; //LTE_RLCAM_POLL_BYTE_25;
	inRrrConnectionSetup.rlcAmPollPdu = LTE_RLCAM_POLL_PDU_128; //LTE_RLCAM_POLL_PDU_4;
	inRrrConnectionSetup.rlcAmPollRetxTimer = LTE_RLCAM_POLL_RETX_TIMER_ms500; //LTE_RLCAM_POLL_RETX_TIMER_ms80;
	inRrrConnectionSetup.rrcTransactionId = 0;
	inRrrConnectionSetup.srConfigIndex = LTE_SR_INDEX;
	inRrrConnectionSetup.lteDuplexMode = 1 ;
	inRrrConnectionSetup.srPucchResourceIndex = LTE_DEDICATED_MODE_PUCCH_RESOURCE_INDEX;
	inRrrConnectionSetup.srbIdentity = 1;
	inRrrConnectionSetup.taTimerDedicated = LTE_TA_DEDICATED_MODE_TIMER_sf10240;
	inRrrConnectionSetup.ulSchMaxHarqTx = LTE_ULSCH_MAX_HARQ_TX_n1;//LTE_ULSCH_MAX_HARQ_TX_n5;
	inRrrConnectionSetup.ulSchPeriodicBsrTimer = LTE_ULSCH_PERIODIC_BSR_TIMER_sf32;
	inRrrConnectionSetup.ulSchRetxBsrTimer = LTE_ULSCH_RETX_BSR_TIMER_sf2560;
	inRrrConnectionSetup.rlcAmDlTStatusReorderingTimer = LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS0;
	inRrrConnectionSetup.rlcAmDlTreorderingTimer = LTE_RLCAMDL_TREORDERING_TIMER_MS80;
	inRrrConnectionSetup.phrDlPathLoss = LTE_PHR_DL_PATHLOSS_dB1;
	inRrrConnectionSetup.phrPeriodicTimerValue = LTE_PERIODIC_PHR_TIMER_sf100;
	inRrrConnectionSetup.phrProhibitTimerValue = LTE_PROHIBIT_PHR_TIMER_sf0;//LTE_PROHIBIT_PHR_TIMER_sf100;
	asn1EncodedRrcConnectionSetupTdd = buildAndEncodeRrcConnectionSetup(&inRrrConnectionSetup , &asn1EncodedRrcConnectionSetupTddLen); // Here memory is allocated inside this function.
	//logPrint(LOG_DEBUG , "Encoded RrcConnectionSetupTDD Size = %d \n" , asn1EncodedRrcConnectionSetupTddLen );
	cleanLteASNContext();
}

void generateRrcConnReestabReject()
{
   if(asn1EncodedRrcConnReestabReject !=NULL)
   {
      free(asn1EncodedRrcConnReestabReject);
   }
	
   asn1EncodedRrcConnReestabReject = NULL;
   asn1EncodedRrcConnReestabRejectLen = 0;
	
   if(initializeLteASNContext("RrcConnReestabReject.txt") == -1)
   {
      logPrint(LOG_ERR , "RrcConnReestabReject ASN1 ENCODING FAILED");
      return;
   }

   asn1EncodedRrcConnReestabReject = 
       buildAndEncodeRrcConnReestabReject(&asn1EncodedRrcConnReestabRejectLen);

   logPrint(LOG_DEBUG, "Encoded RrcConnReestabReject Size = %d \n", 
            asn1EncodedRrcConnReestabRejectLen);

   cleanLteASNContext();
}

void generateIDTImsimessage(void)
{

	uint8  IDTMsg[3] = {0};
	if(asn1EncodedIdentityImsiRequest !=NULL)
	{
		free(asn1EncodedIdentityImsiRequest);
	}
	asn1EncodedIdentityImsiRequest = NULL;
	asn1EncodedIdentityImsiRequestLen = 0;
	if(initializeLteASNContext("IdentityRequestImsiTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "IdentityRequestImsi ASN1 DECODING FAILED");
		return;
	}
	IDTMsg[0] = 0x07;
	IDTMsg[1] = 0x55; // 55 Identity request // 44 Attach reject
	IDTMsg[2] = 0x01; // 01 for IMSI and 02 for IMEI
	asn1EncodedIdentityImsiRequest = buildAndEncodeDlTransferInfo(IDTMsg , &asn1EncodedIdentityImsiRequestLen);
	//logPrint(LOG_DEBUG , "Encoded Imsi Identity Request Message Size = %d \n" , asn1EncodedIdentityImsiRequestLen );

	cleanLteASNContext();

}

void generateIDTImeimessage(void)
{

	uint8  IDTMsg[3] = {0};
	if(asn1EncodedIdentityImeiRequest !=NULL)
	{
		free(asn1EncodedIdentityImeiRequest);
	}
	asn1EncodedIdentityImeiRequest = NULL;
	asn1EncodedIdentityImeiRequestLen = 0;
	if(initializeLteASNContext("IdentityRequestImeiTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "IdentityRequestImei ASN1 DECODING FAILED");
		return;
	}
	IDTMsg[0] = 0x07;
	IDTMsg[1] = 0x55; // 55 Identity request
	IDTMsg[2] = 0x02; // 01 for IMSI and 02 for IMEI
	asn1EncodedIdentityImeiRequest = buildAndEncodeDlTransferInfo(IDTMsg , &asn1EncodedIdentityImeiRequestLen);
	//logPrint(LOG_DEBUG , "Encoded Imei Identity Request Message Size = %d \n" , asn1EncodedIdentityImeiRequestLen );

	cleanLteASNContext();

}

void generateAttachRejmessage(fxL4gConfigureIdCatcherParamsCmd * cmd)
{
	unsigned char  IDTMsg[3] = {0};
	if(asn1EncodedAttachRejRequest !=NULL)
	{
		free(asn1EncodedAttachRejRequest);
	}
	asn1EncodedAttachRejRequest = NULL;
	asn1EncodedAttachRejRequestLen = 0;
	if(initializeLteASNContext("AttachRejectTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "Attach Reject ASN1 ENCODING FAILED");
		return;
	}
	IDTMsg[0] = 0x07;
	IDTMsg[1] = 0x44; // 55 Identity request // 44 Attach reject
	IDTMsg[2] = 0x0F; // 01 for IMSI and 02 for IMEI // 0C Tracking Area not Allowed
	asn1EncodedAttachRejRequest = buildAndEncodeDlTransferInfo(IDTMsg , &asn1EncodedAttachRejRequestLen);
	//logPrint(LOG_DEBUG , "Encoded Attach Reject Message Size = %d \n" , asn1EncodedAttachRejRequestLen );
	//logPrint(LOG_DEBUG , "%02x, %02x,%02x, %02x,%02x , %02x \n" , asn1EncodedAttachRejRequest[0],asn1EncodedAttachRejRequest[1],asn1EncodedAttachRejRequest[2],asn1EncodedAttachRejRequest[3],asn1EncodedAttachRejRequest[4],asn1EncodedAttachRejRequest[5] );
	enableAttRejCause = cmd->enableAttRejCause;
	lteWlRejCause = cmd->attRejCause;
	logPrint(LOG_DEBUG , "Global AttachRejCause Enable=%d , cause = %d \n" ,enableAttRejCause,lteWlRejCause );
	cleanLteASNContext();
}
void generateTAURejmessage(void)
{
	unsigned char  IDTMsg[3] = {0};
	if(asn1EncodedTAURejRequest !=NULL)
	{
		free(asn1EncodedTAURejRequest);
	}
	asn1EncodedTAURejRequest = NULL;
	asn1EncodedTAURejRequestLen = 0;
	if(initializeLteASNContext("TAURejectTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "TAU Reject ASN1 ENCODING FAILED");
		return;
	}
	IDTMsg[0] = 0x07;
	IDTMsg[1] = 0x4B; // 55 Identity request // 44 Attach reject //4B TAU Reject
	IDTMsg[2] = 0x0F; // 01 for IMSI and 02 for IMEI // 0C Tracking Area not Allowed
	asn1EncodedTAURejRequest = buildAndEncodeDlTransferInfo(IDTMsg , &asn1EncodedTAURejRequestLen);
	//logPrint(LOG_DEBUG , "Encoded TAU Reject Message Size = %d \n" , asn1EncodedTAURejRequestLen );
	//logPrint(LOG_DEBUG , "TAU-Reject message %02x,%02x,%02x,%02x,%02x,%02x \n" , asn1EncodedTAURejRequest[0],asn1EncodedTAURejRequest[1],asn1EncodedTAURejRequest[2],asn1EncodedTAURejRequest[3],asn1EncodedTAURejRequest[4],asn1EncodedTAURejRequest[5] );

	cleanLteASNContext();

}
void generateRrcConnectionRelmessage(void)
{
	lteRrcConnRelStruct inRrcConnRelBuf = {0};

	if(asn1EncodedRrcConnectionRelease !=NULL)
	{
		free(asn1EncodedRrcConnectionRelease);
	}
	asn1EncodedRrcConnectionRelease = NULL;
	asn1EncodedRrcConnectionReleaseLen = 0;
	if(initializeLteASNContext("RrcConnectionReleaseBuildTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcConnectionRelease ASN1 ENCODING FAILED");
		return;
	}

	inRrcConnRelBuf.rrcTransactionId=0;
	inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_OTHER;
	inRrcConnRelBuf.redirectInfoPresence = 0; // 0 for no_redirection , 1 for geran redierction and 2 for UMTS FDD
	asn1EncodedRrcConnectionRelease = buildAndEncodeRrcConnectionRel(&inRrcConnRelBuf , &asn1EncodedRrcConnectionReleaseLen);
	//logPrint(LOG_DEBUG , "Encoded RrcConnectionRelease Message Size = %d \n" , asn1EncodedRrcConnectionReleaseLen );
	cleanLteASNContext();

}

void generateRrcConnectionRelWithRedirectForBlUe(fxLRedirectionFrom4gType  redirectionType,
                                                 fxLRedirectionFrom4gInfo  redirectionInfo,
                                                 uint8                   **pEncodedBuff,
                                                 uint8                    *pEncodedBuffLen)
{
        lteRrcConnRelStruct inRrcConnRelBuf = {0};

        if(*pEncodedBuff != NULL)
        {
                free(*pEncodedBuff);
        }
 
        *pEncodedBuff = NULL;
        *pEncodedBuffLen = 0;
        if(initializeLteASNContext("RrcConnectionReleaseRedirectTrace.txt") == -1)
        {
                logPrint(LOG_ERR , "RrcConnectionRelease ASN1 ENCODING FAILED");
                return;
        }  
        inRrcConnRelBuf.rrcTransactionId=0;
        inRrcConnRelBuf.redirectInfoPresence = redirectionType; // 0 for no_redirection , 1 for geran redierction and 2 for UMTS FDD
        if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_2G)
        {
                inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_CS_FALLBACK_HIGH_PRIORITY;
                inRrcConnRelBuf.RedirectedCarrierInfo.gsmRedirectinfo.bandIndicator = redirectionInfo.gsmRedirectinfo.bandIndicator;
                inRrcConnRelBuf.RedirectedCarrierInfo.gsmRedirectinfo.startingarfcn = redirectionInfo.gsmRedirectinfo.startingarfcn;
        }
        else if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_3G )
        {
                inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_CS_FALLBACK_HIGH_PRIORITY;
                inRrcConnRelBuf.RedirectedCarrierInfo.utraFDDRedirectInfo = redirectionInfo.utraFDDUARFCN;
        }
        else if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_4G )
        {
                inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_LOAD_BALANCING_TAU_REQUIRED;
                inRrcConnRelBuf.RedirectedCarrierInfo.lteRrcEarfcn = redirectionInfo.eutraEARFCN;
        }
        else if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_CDMA)
        {
                inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_CS_FALLBACK_HIGH_PRIORITY;
                inRrcConnRelBuf.RedirectedCarrierInfo.cdmaRedirectinfo.bandIndicator = redirectionInfo.cdmaRedirectinfo.bandIndicator;
                inRrcConnRelBuf.RedirectedCarrierInfo.cdmaRedirectinfo.startingarfcn = redirectionInfo.cdmaRedirectinfo.startingarfcn;
        }
        //logPrint(LOG_DEBUG, "Paging Feature Enabled/redirection info : %d/%d\n", !inRrcConnRelBuf->redirectInfoPresence ,inRrcConnRelBuf->redirectInfoPresence);
        *pEncodedBuff = buildAndEncodeRrcConnectionRel(&inRrcConnRelBuf , pEncodedBuffLen);

        //logPrint(LOG_DEBUG , "Encoded RrcConnectionRelease Redirect Message Size = %d \n" , asn1EncodedRrcConnectionReleaseWithRedirectLen );
        cleanLteASNContext();
        
}

void generateRrcConnectionRelWithRedirect(fxL4gConfigureIdCatcherParamsCmd * cmd)
{
	lteRrcConnRelStruct inRrcConnRelBuf = {0};

	if(asn1EncodedRrcConnectionReleaseWithRedirect !=NULL)
	{
		free(asn1EncodedRrcConnectionReleaseWithRedirect);
	}
	asn1EncodedRrcConnectionReleaseWithRedirect = NULL;
	asn1EncodedRrcConnectionReleaseWithRedirectLen = 0;
	if(initializeLteASNContext("RrcConnectionReleaseRedirectTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcConnectionRelease ASN1 ENCODING FAILED");
		return;
	}
	inRrcConnRelBuf.rrcTransactionId=0;
	lteRrcRedirectFlag = cmd->redirectionType;
	inRrcConnRelBuf.redirectInfoPresence = cmd->redirectionType; // 0 for no_redirection , 1 for geran redierction and 2 for UMTS FDD
	if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_2G)
	{
	    inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_CS_FALLBACK_HIGH_PRIORITY;
		inRrcConnRelBuf.RedirectedCarrierInfo.gsmRedirectinfo.bandIndicator = cmd->redirectionInfo.gsmRedirectinfo.bandIndicator;
		inRrcConnRelBuf.RedirectedCarrierInfo.gsmRedirectinfo.startingarfcn = cmd->redirectionInfo.gsmRedirectinfo.startingarfcn;
	}
	else if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_3G )
	{
	    inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_CS_FALLBACK_HIGH_PRIORITY;
		inRrcConnRelBuf.RedirectedCarrierInfo.utraFDDRedirectInfo = cmd->redirectionInfo.utraFDDUARFCN;
	}
	else if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_4G )
	{
	    inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_LOAD_BALANCING_TAU_REQUIRED;
		inRrcConnRelBuf.RedirectedCarrierInfo.lteRrcEarfcn = cmd->redirectionInfo.eutraEARFCN;
	}
    else if(inRrcConnRelBuf.redirectInfoPresence == REDIRECTION_TO_CDMA)
    {
        inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_CS_FALLBACK_HIGH_PRIORITY;
    	inRrcConnRelBuf.RedirectedCarrierInfo.cdmaRedirectinfo.bandIndicator = cmd->redirectionInfo.cdmaRedirectinfo.bandIndicator;
        inRrcConnRelBuf.RedirectedCarrierInfo.cdmaRedirectinfo.startingarfcn = cmd->redirectionInfo.cdmaRedirectinfo.startingarfcn;
	}
	//logPrint(LOG_DEBUG, "Paging Feature Enabled/redirection info : %d/%d\n", !inRrcConnRelBuf->redirectInfoPresence ,inRrcConnRelBuf->redirectInfoPresence);
	asn1EncodedRrcConnectionReleaseWithRedirect = buildAndEncodeRrcConnectionRel(&inRrcConnRelBuf , &asn1EncodedRrcConnectionReleaseWithRedirectLen);

	//logPrint(LOG_DEBUG , "Encoded RrcConnectionRelease Redirect Message Size = %d \n" , asn1EncodedRrcConnectionReleaseWithRedirectLen );
	cleanLteASNContext();

}

void generateRrcReleaseWLRedirect(int earfcn)
{
	lteRrcConnRelStruct inRrcConnRelBuf = {0};

	if(asn1EncodedRrcRedirectWL !=NULL)
	{
		free(asn1EncodedRrcRedirectWL);
	}
	asn1EncodedRrcRedirectWL = NULL;
	asn1EncodedRrcRedirectWLLen = 0;
	if(initializeLteASNContextRrcThrd("RrcRedirectWLLenTrace.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcRedirectWLLen ASN1 ENCODING FAILED");
		return;
	}
	inRrcConnRelBuf.rrcTransactionId = 0;
	inRrcConnRelBuf.releaseCause = RELEASE_CAUSE_OTHER;

    if(idCatcherLteWlRedirEarfcn)
    {
        inRrcConnRelBuf.redirectInfoPresence = REDIRECTION_TO_4G;
        inRrcConnRelBuf.RedirectedCarrierInfo.lteRrcEarfcn = idCatcherLteWlRedirEarfcn;
    }
	else if (redirectInfo.noOfSib5Freq)
	{
		inRrcConnRelBuf.redirectInfoPresence = REDIRECTION_TO_4G;
		inRrcConnRelBuf.RedirectedCarrierInfo.lteRrcEarfcn = redirectInfo.sib5Earfcn;
		//logPrint(LOG_DEBUG, "WL Redirectinfo : %d ,SIb5 Earfcn = %d \n", inRrcConnRelBuf->redirectInfoPresence ,inRrcConnRelBuf->RedirectedCarrierInfo.lteRrcEarfcn);
	}
	else if (redirectInfo.noOfSib6Freq)
	{
		inRrcConnRelBuf.redirectInfoPresence = REDIRECTION_TO_3G;
		inRrcConnRelBuf.RedirectedCarrierInfo.utraFDDRedirectInfo = redirectInfo.sib6Uarfcn;
		//logPrint(LOG_DEBUG, "WL Redirectinfo : %d , Uarfcn = %d \n", inRrcConnRelBuf->redirectInfoPresence ,inRrcConnRelBuf->RedirectedCarrierInfo.utraFDDRedirectInfo);
	}
	else if (redirectInfo.noOfSib7Freq)
	{
		inRrcConnRelBuf.redirectInfoPresence = REDIRECTION_TO_2G;
		inRrcConnRelBuf.RedirectedCarrierInfo.gsmRedirectinfo.startingarfcn = redirectInfo.sib7Arcfn;
		inRrcConnRelBuf.RedirectedCarrierInfo.gsmRedirectinfo.bandIndicator = redirectInfo.sib7BandIndicator;
		//logPrint(LOG_DEBUG, "WL Redirectinfo : %d , Arfcn = %d , BandIndicator = %d\n", inRrcConnRelBuf->redirectInfoPresence ,inRrcConnRelBuf->RedirectedCarrierInfo.gsmRedirectinfo.startingarfcn,inRrcConnRelBuf->RedirectedCarrierInfo.gsmRedirectinfo.bandIndicator);
	}
	else
	{
		inRrcConnRelBuf.redirectInfoPresence = REDIRECTION_TO_4G;
		inRrcConnRelBuf.RedirectedCarrierInfo.lteRrcEarfcn = earfcn ;
		//logPrint(LOG_DEBUG, "WL Redirectinfo : %d , Earfcn = %d \n", inRrcConnRelBuf->redirectInfoPresence ,inRrcConnRelBuf->RedirectedCarrierInfo.lteRrcEarfcn);
	}

	asn1EncodedRrcRedirectWL = buildAndEncodeRrcConnectionRel(&inRrcConnRelBuf , &asn1EncodedRrcRedirectWLLen);
	//logPrint(LOG_DEBUG , "Encoded RrcRedirectWLLen Size = %d \n" , asn1EncodedRrcRedirectWLLen );
	cleanLteASNContextRrcThrd();

}

int decodeDcchData(uint8* asn1EncodedBuf, uint16 bufLength , void* decodedBuf)
{
	int ret = 0;
	if(initializeLteASNContextRrcThrd("RrcDcchMsgTrace.txt") == -1)
	{
		logPrint(LOG_DEBUG, "decodeDcchData ASN1 INITIALIZATION CONTEXT FAILED\n");
		ret =  -1;
	}

	// Call asn library function here to decode and then store data in decodedBuf
	if(decodeMSG5(asn1EncodedBuf ,bufLength, (lteRrcConnSetupCompleteStruct *)decodedBuf) != 0)
	{
		logPrint(LOG_ERR , "RrcConnectionComplete ASN1 DECODING FAILED");
		ret = -1;
	}
	
	cleanLteASNContextRrcThrd();

	return ret;
}

int decodeCcchData(uint8* asn1EncodedBuf, uint16 bufLength , lteUlCCCHMsgStruct *pUlCCCHMsg)
{
	int ret = 0;
	if(initializeLteASNContextMacThrd("RrcCcchMsgTrace.txt") == -1)
	{
		logPrint(LOG_DEBUG, "decodeCcchData ASN1 INITIALIZATION CONTEXT FAILED\n");
		ret =  -1;
	}

	// Call asn library function here to decode and then store data in decodedBuf
	if(decodeUlCCCHMsg(asn1EncodedBuf ,bufLength, pUlCCCHMsg) != 0)
	{
		logPrint(LOG_ERR , "decodeCcchData ASN1 DECODING FAILED");
		ret = -1;
	}
	
	cleanLteASNContextMacThrd();

	return ret;
}

int decodeUlDcchUlInfoTrans(uint8* asn1EncodedBuf, uint16 bufLength , void* decodedBuf)
{
	int ret = 0;
	if(initializeLteASNContextRrcThrd("UlInfoNasMsgTrace.txt") == -1)
	{
		logPrint(LOG_DEBUG, "decode ULINFO TRANSFER ASN1 DECODING FAILED\n");
		ret =  -1;
	}

	// Call asn library function here to decode and then store data in decodedBuf
	if(decodeUltransferinfo(asn1EncodedBuf ,bufLength, (lteRrcUlDCCHData*)decodedBuf) != 0)
	{
		logPrint(LOG_ERR , "UL INFO TRANSFER ASN1 DECODING FAILED");
		ret = -1;
	}
	cleanLteASNContextRrcThrd();

	return ret;
}

void generateRrcUeCapaEnqMsg()
{
	if(asn1EncodedRrcUeCapaEnqReq !=NULL)
	{
		free(asn1EncodedRrcUeCapaEnqReq);
	}
	asn1EncodedRrcUeCapaEnqReq = NULL;
	asn1EncodedRrcUeCapaEnqReqLen = 0;
	if(initializeLteASNContext("RrcUECapaEnQ.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcUECapaEnQ ASN1 DECODING FAILED");
		return;
	}

	asn1EncodedRrcUeCapaEnqReq = buildAndEncodeRrcUeCapaEnquiryMsg(&asn1EncodedRrcUeCapaEnqReqLen );
	//logPrint(LOG_DEBUG , "Encoded RrcUECapaEnQ Message Size = %d \n" , asn1EncodedRrcUeCapaEnqReqLen );

	cleanLteASNContext();

}

unsigned int storeNeighborConfiguration(fxL4gConfigureNeighborCmd *cmd)
{
    unsigned int idx = 0;

    gAsnLteNeighConfigData.numberOfLteNeighbor = cmd->numberOfLteNeighbor;
    for(idx = 0; idx < gAsnLteNeighConfigData.numberOfLteNeighbor; idx++)
    {
        gAsnLteNeighConfigData.lteNeighbors[idx].dlEarfcn  = cmd->lteNeighbors[idx].dlEarfcn;
        gAsnLteNeighConfigData.lteNeighbors[idx].bandwidth = cmd->lteNeighbors[idx].bandwidth;
    }

    gAsnLteNeighConfigData.numberOfUmtsNeighbor = cmd->numberOfUmtsNeighbor;
    for(idx = 0; idx < gAsnLteNeighConfigData.numberOfUmtsNeighbor; idx++)
    {
        gAsnLteNeighConfigData.dlUarfcn[idx] = cmd->dlUarfcn[idx];
    }

    gAsnLteNeighConfigData.numberOfGsmNeighbor = cmd->numberOfGsmNeighbor;
    for(idx = 0; idx < gAsnLteNeighConfigData.numberOfGsmNeighbor; idx++)
    {
        gAsnLteNeighConfigData.gsmNeighbors[idx].arfcn = cmd->gsmNeighbors[idx].arfcn;
        gAsnLteNeighConfigData.gsmNeighbors[idx].bandIndicator = cmd->gsmNeighbors[idx].bandIndicator;
    }

	return 0;
}

unsigned int generateRrcNeighMeasConfigMsg(fxL4gMeasurementCfgCmd *cmd)
{
    unsigned int idx = 0;
    unsigned int idx1 = 0;
 
    gLteRrcMeasData.ueLteMeasConfig.enableIntraFreqMeasurement = cmd->ueMeasCfg.enableIntraFreqMeasurement;

    gLteRrcMeasData.ueLteMeasConfig.numInterFreqEarfcn = cmd->ueMeasCfg.numInterFreqEarfcn;
    for(idx = 0; idx < gLteRrcMeasData.ueLteMeasConfig.numInterFreqEarfcn;idx++)
    {
        gLteRrcMeasData.ueLteMeasConfig.interFreqNeighbrList[idx].dlEarfcn = cmd->ueMeasCfg.interFreqNeighbrList[idx].dlEarfcn;
        gLteRrcMeasData.ueLteMeasConfig.interFreqNeighbrList[idx].bandWidth   = cmd->ueMeasCfg.interFreqNeighbrList[idx].bandWidth;
    }

    gLteRrcMeasData.ueLteMeasConfig.numInterRatUmtsNeighbr = cmd->ueMeasCfg.numInterRatUmtsNeighbr;
    for(idx = 0; idx < gLteRrcMeasData.ueLteMeasConfig.numInterRatUmtsNeighbr;idx++)
    {
        gLteRrcMeasData.ueLteMeasConfig.interRatUmtsNeighbrList[idx].dlUarfcn  = cmd->ueMeasCfg.interRatUmtsNeighbrList[idx].dlUarfcn;
        gLteRrcMeasData.ueLteMeasConfig.interRatUmtsNeighbrList[idx].numPSC  = cmd->ueMeasCfg.interRatUmtsNeighbrList[idx].numPSC;
        for(idx1 = 0; idx1 <  gLteRrcMeasData.ueLteMeasConfig.interRatUmtsNeighbrList[idx].numPSC; idx1++)
        {
            gLteRrcMeasData.ueLteMeasConfig.interRatUmtsNeighbrList[idx].psc[idx1] = cmd->ueMeasCfg.interRatUmtsNeighbrList[idx].psc[idx1];
        }
    }

    gLteRrcMeasData.ueLteMeasConfig.numInterRatGsmNeighbr = cmd->ueMeasCfg.numInterRatGsmNeighbr;
    for(idx = 0; idx < gLteRrcMeasData.ueLteMeasConfig.numInterRatGsmNeighbr; idx++)
    {
        gLteRrcMeasData.ueLteMeasConfig.interRatGsmNeighbrList[idx].band  = cmd->ueMeasCfg.interRatGsmNeighbrList[idx].band;
        gLteRrcMeasData.ueLteMeasConfig.interRatGsmNeighbrList[idx].startingArfcn  = cmd->ueMeasCfg.interRatGsmNeighbrList[idx].startingArfcn;
        gLteRrcMeasData.ueLteMeasConfig.interRatGsmNeighbrList[idx].numArfcn = cmd->ueMeasCfg.interRatGsmNeighbrList[idx].numArfcn;

        for(idx1 = 0; idx1 <  gLteRrcMeasData.ueLteMeasConfig.interRatGsmNeighbrList[idx].numArfcn; idx1++)
        {
            gLteRrcMeasData.ueLteMeasConfig.interRatGsmNeighbrList[idx].arfcn[idx1] = cmd->ueMeasCfg.interRatGsmNeighbrList[idx].arfcn[idx1];
        }
    }

    if(asn1EncodedRrcNeighMeasCntrlReq !=NULL)
    {
         free(asn1EncodedRrcNeighMeasCntrlReq);
    }
    asn1EncodedRrcNeighMeasCntrlReq = NULL;
    asn1EncodedRrcNeighMeasCntrlReqLen = 0;

    if(initializeLteASNContext("RrcMeasConfig.txt") == -1)
    {                                             
          logPrint(LOG_ERR , "RrcMeasConfig ASN1 DECODING FAILED");
          return 1;
    }

    asn1EncodedRrcNeighMeasCntrlReq = buildAndEncodeRrcMeasCntrlMsgForNeighMeas(&gLteRrcMeasData , &asn1EncodedRrcNeighMeasCntrlReqLen);
    logPrint(LOG_DEBUG , "Encoded RRC Neigh Meas Config Message Size = %d \n" , asn1EncodedRrcNeighMeasCntrlReqLen);

    cleanLteASNContext();

    if(asn1EncodedRrcNeighMeasCntrlReqLen != 0)
    	return 0;
    else
	return 1;
}


void generateRrcMeasConfigMsg(fxL4gConfigureIdCatcherParamsCmd * cmd)
{
	if(asn1EncodedRrcMeasCntrlReq !=NULL)
	{
		free(asn1EncodedRrcMeasCntrlReq);
	}
	asn1EncodedRrcMeasCntrlReq = NULL;
	asn1EncodedRrcMeasCntrlReqLen = 0;
	if(initializeLteASNContext("RrcMeasConfig.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcMeasConfig ASN1 DECODING FAILED");
		return;
	}

	asn1EncodedRrcMeasCntrlReq = buildAndEncodeRrcMeasCntrlMsg(cmd->earfcn , cmd->phyCellId, &asn1EncodedRrcMeasCntrlReqLen , lteSelectedBandwidth);
	logPrint(LOG_DEBUG , "Encoded RrcMeasConfig Message Size = %d \n" , asn1EncodedRrcMeasCntrlReqLen );

	cleanLteASNContext();

}

void generateRrcReconfigReqMsg(void)
{
	if(asn1EncodedRrcReconfigReq !=NULL)
	{
		free(asn1EncodedRrcReconfigReq);
	}
	asn1EncodedRrcReconfigReq = NULL;
	asn1EncodedRrcReconfigReqLen = 0;
	if(initializeLteASNContext("RrcReconfig.txt") == -1)
	{
		logPrint(LOG_ERR , "RrcReconfig ASN1 ENCODING FAILED");
		return;
	}
	inRrrConnectionSetup.dsrTransMax = LTE_SRSETUP_DSR_TRANS_MAX_n64;

	inRrrConnectionSetup.rlcAmMaxRetxThreshold = LTE_RLC_RETX_THRESHOLD_32;
	inRrrConnectionSetup.rlcAmPollByte = LTE_RLCAM_POLL_BYTE_125; //LTE_RLCAM_POLL_BYTE_25;
	inRrrConnectionSetup.rlcAmPollPdu = LTE_RLCAM_POLL_PDU_128; //LTE_RLCAM_POLL_PDU_4;
	inRrrConnectionSetup.rlcAmPollRetxTimer = LTE_RLCAM_POLL_RETX_TIMER_ms500; //LTE_RLCAM_POLL_RETX_TIMER_ms80;
	inRrrConnectionSetup.rrcTransactionId = 0;
	inRrrConnectionSetup.srConfigIndex = LTE_SR_INDEX;
	inRrrConnectionSetup.lteDuplexMode = lteDuplxMode;
	inRrrConnectionSetup.pdschPAValue = LTE_PDSCH_CONFIG_PA_VALUE_dB_3;
	inRrrConnectionSetup.srPucchResourceIndex = LTE_DEDICATED_MODE_PUCCH_RESOURCE_INDEX;
	inRrrConnectionSetup.srbIdentity = 1;
	inRrrConnectionSetup.taTimerDedicated = LTE_TA_DEDICATED_MODE_TIMER_sf10240;
	inRrrConnectionSetup.ulSchMaxHarqTx = LTE_ULSCH_MAX_HARQ_TX_n1;//LTE_ULSCH_MAX_HARQ_TX_n5;
	inRrrConnectionSetup.ulSchPeriodicBsrTimer = LTE_ULSCH_PERIODIC_BSR_TIMER_sf32;
	inRrrConnectionSetup.ulSchRetxBsrTimer = LTE_ULSCH_RETX_BSR_TIMER_sf2560;
	inRrrConnectionSetup.rlcAmDlTStatusReorderingTimer = LTE_RLCDLAM_TSTATUS_PROHIBIT_TIMER_MS0;
	inRrrConnectionSetup.rlcAmDlTreorderingTimer = LTE_RLCAMDL_TREORDERING_TIMER_MS80;
	inRrrConnectionSetup.phrDlPathLoss = LTE_PHR_DL_PATHLOSS_dB1;
	inRrrConnectionSetup.phrPeriodicTimerValue = LTE_PERIODIC_PHR_TIMER_sf100;
	inRrrConnectionSetup.phrProhibitTimerValue = LTE_PROHIBIT_PHR_TIMER_sf0;//LTE_PROHIBIT_PHR_TIMER_sf100;
	asn1EncodedRrcReconfigReq = buildAndEncodeRrcReconfigReqMsg(&inRrrConnectionSetup , &asn1EncodedRrcReconfigReqLen); // Here memory is allocated inside this function.

	logPrint(LOG_DEBUG , "Encoded RrcReconfigReq Message Size = %d \n" , asn1EncodedRrcReconfigReqLen );

	cleanLteASNContext();

}

// Assume as of now one BL IMSI received
void generatePagingMsg(lteDlPagingStruct *inRrcPagingBuf)
{
	if (!lteRrcRedirectFlag)
	{
		if(asn1EncodedPagingRequest !=NULL)
		{
			free(asn1EncodedPagingRequest);
		}
		asn1EncodedPagingRequest = NULL;
		asn1EncodedPagingRequestLen = 0;
		if(initializeLteASNContextRrcThrd("RrcPagingMessage.txt") == -1)
		{
			logPrint(LOG_ERR , "RrcPaging ASN1 ENCODING FAILED");
			return ;
		}

		asn1EncodedPagingRequest = buildAndEncodePagingMsg(inRrcPagingBuf , &asn1EncodedPagingRequestLen);
		//logPrint(LOG_DEBUG , "Encoded Rrc Paging Message Size = %d , UE-PageCount = %d  \n" , asn1EncodedPagingRequestLen , inRrcPagingBuf->uePageCount );
		cleanLteASNContextRrcThrd();
	}
	else
	{
		logPrint(LOG_ERR , "Paging feature not enabled  = %d \n" , lteRrcRedirectFlag );
	}
}

void generateIMSIPagingMsg(lteDlPagingStruct *inRrcPagingBuf)
{
    if(asn1EncodedPagingRequest !=NULL)
	{
		free(asn1EncodedPagingRequest);
	}
	asn1EncodedPagingRequest = NULL;
	asn1EncodedPagingRequestLen = 0;
	if(initializeLteASNContext("RrcPagingMessage.txt") == -1)
	{
		logPrint(LOG_ERR , "IMSI Paging ASN1 ENCODING FAILED");
		return;
	}

	asn1EncodedPagingRequest = buildAndEncodeIMSIPagingMsg(inRrcPagingBuf , &asn1EncodedPagingRequestLen);
	cleanLteASNContext();
	logPrint(LOG_DEBUG , "Encoded IMSI Paging Message Size = %d\n", 
		     asn1EncodedPagingRequestLen);
}

// Assume as of now one BL IMSI received
void generatePagingMsgForSibMod(void)
{
	if (!lteRrcRedirectFlag)
	{

		if(asn1EncodedPagingSibModRequest !=NULL)
		{
			free(asn1EncodedPagingSibModRequest);
		}
		asn1EncodedPagingSibModRequest = NULL;
		asn1EncodedPagingSibModRequestLen = 0;
		if(initializeLteASNContext("RrcPagingSibMod.txt") == -1)
		{
			logPrint(LOG_ERR , "RrcPaging ASN1 ENCODING FAILED");
			return ;
		}

		asn1EncodedPagingSibModRequest = buildAndEncodePagingSibModMsg(&asn1EncodedPagingSibModRequestLen);
		//logPrint(LOG_DEBUG , "Encoded RrcPagingSIBMOD Message Size = %d \n" , asn1EncodedPagingSibModRequestLen );
		cleanLteASNContext();
	}
	else
	{
		logPrint(LOG_ERR , "Paging feature not enabled  = %d \n" , lteRrcRedirectFlag );
	}
}

// Assume as of now one BL IMSI received
void generatePagingMsgWithSTmsi(lteDlPagingStruct *inRrcPagingBuf)
{
	if (!lteRrcRedirectFlag)
	{
		if(asn1EncodedPagingwithSTmsiRequest !=NULL)
		{
			free(asn1EncodedPagingwithSTmsiRequest);
		}
		asn1EncodedPagingwithSTmsiRequest = NULL;
		asn1EncodedPagingwithSTmsiRequestLen = 0;
		if(initializeLteASNContextRrcThrd("RrcPagingMessageWitSTmsi.txt") == -1)
		{
			logPrint(LOG_ERR , "RrcPaging with TMsi ASN1 ENCODING FAILED");
			return ;
		}

		asn1EncodedPagingwithSTmsiRequest = buildAndEncodePagingWithTMSIMsg(inRrcPagingBuf , &asn1EncodedPagingwithSTmsiRequestLen);
		logPrint(LOG_DEBUG , "Encoded Rrc STmsi Paging Message Size = %d , UE-PageCount = %d  \n" , asn1EncodedPagingwithSTmsiRequestLen , inRrcPagingBuf->uePageCount );
		cleanLteASNContextRrcThrd();
	}
	else
	{
		logPrint(LOG_ERR , "Paging feature not enabled  = %d \n" , lteRrcRedirectFlag );
	}
}
void cleanUpAsnbuffers()
{
	lteRrcRedirectFlag = 0;
    lteRrcPrmRedirectFlag = 0;
	sfn = 0;
	systeInfoTagGlobal = 0;
	if(asn1EncodedPagingSibModRequest != NULL)
	{
		free(asn1EncodedPagingSibModRequest);
		asn1EncodedPagingSibModRequest = NULL;
	}
	if(asn1EncodedPagingRequest != NULL)
	{
		free(asn1EncodedPagingRequest);
		asn1EncodedPagingRequest = NULL;
	}
	if(asn1EncodedRrcReconfigReq != NULL)
	{
		free(asn1EncodedRrcReconfigReq);
		asn1EncodedRrcReconfigReq = NULL;
	}
	if(asn1EncodedRrcMeasCntrlReq != NULL)
	{
		free(asn1EncodedRrcMeasCntrlReq);
		asn1EncodedRrcMeasCntrlReq = NULL;
	}
    if(asn1EncodedRrcNeighMeasCntrlReq != NULL)
    {
        free(asn1EncodedRrcNeighMeasCntrlReq);
        asn1EncodedRrcNeighMeasCntrlReq = NULL;
    }
	if(asn1EncodedRrcUeCapaEnqReq != NULL)
	{
		free(asn1EncodedRrcUeCapaEnqReq);
		asn1EncodedRrcUeCapaEnqReq = NULL;
	}
	if(asn1EncodedRrcRedirectWL != NULL)
	{
		free(asn1EncodedRrcRedirectWL);
		asn1EncodedRrcRedirectWL = NULL;
	}
	if(asn1EncodedRrcConnectionReleaseWithRedirect != NULL)
	{
		free(asn1EncodedRrcConnectionReleaseWithRedirect);
		asn1EncodedRrcConnectionReleaseWithRedirect = NULL;
	}
	if(asn1EncodedRrcConnectionRelease != NULL)
	{
		free(asn1EncodedRrcConnectionRelease);
		asn1EncodedRrcConnectionRelease = NULL;
	}
	if(asn1EncodedTAURejRequest != NULL)
	{
		free(asn1EncodedTAURejRequest);
		asn1EncodedTAURejRequest = NULL;
	}
	if(asn1EncodedAttachRejRequest != NULL)
	{
		free(asn1EncodedAttachRejRequest);
		asn1EncodedAttachRejRequest = NULL;
	}
	if(asn1EncodedIdentityImeiRequest != NULL)
	{
		free(asn1EncodedIdentityImeiRequest);
		asn1EncodedIdentityImeiRequest = NULL;
	}
	if(asn1EncodedIdentityImsiRequest != NULL)
	{
		free(asn1EncodedIdentityImsiRequest);
		asn1EncodedIdentityImsiRequest = NULL;
	}
	if(asn1EncodedRrcConnectionSetup != NULL)
	{
		free(asn1EncodedRrcConnectionSetup);
		asn1EncodedRrcConnectionSetup = NULL;
	}
	if(asn1EncodedRrcConnectionSetupTdd != NULL)
	{
		free(asn1EncodedRrcConnectionSetupTdd);
		asn1EncodedRrcConnectionSetupTdd = NULL;
	}
	if(asn1EncodedSibs != NULL)
	{
		free(asn1EncodedSibs);
		asn1EncodedSibs = NULL;
	}
	if(asn1EncodedRrcConnReestabReject != NULL)
	{
		free(asn1EncodedRrcConnReestabReject);
		asn1EncodedRrcConnReestabReject = NULL;
	}
}
