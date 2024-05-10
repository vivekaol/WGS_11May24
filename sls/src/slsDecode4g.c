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
* File Name   : slsDecode4g.c
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
#include <assert.h>
#include "lteAsn1Handler.h"
#include "slsDecode4g.h"
#include "fxLSocketInterfaceApi.h"
#include "logManager.h"


fxL4gListenModeSystemInfoInd sysInfoind ;
extern void addLteScanDataToList(fxL4gListenModeSystemInfoInd * lteScanData);
extern void writeToExternalSocketInterface(uint8* msgBuf , int msgLen);
extern unsigned int getLteBandFromEARFCN(unsigned int lteEarfcn);

void decodeBcchData(uint8* asn1EncodedBuf, uint16 bufLength , lteServingCellStruct* servingCell)
{
	lteSib1Struct *inSib1Buf = (lteSib1Struct*)malloc(sizeof(lteSib1Struct));
	lteSibsStruct *inSibsBuf = (lteSibsStruct *)malloc(sizeof(lteSibsStruct));
	assert((inSib1Buf != NULL)||(inSibsBuf != NULL));
	uint8 i = 0, j =0;

	memset(inSibsBuf , 0 , sizeof(lteSibsStruct));
	memset(inSib1Buf , 0 , sizeof(lteSib1Struct));

	if(initializeLteASNContext("BcchDecodeTrace.txt") == -1)
	{
		logPrint(LOG_DEBUG, "decodeBcchData ASN1 CONTEXT INITIALIZATION FAILED\n");
		return;
	}

    if(decodeSibs(asn1EncodedBuf ,bufLength, inSibsBuf, inSib1Buf) == 0)
	{
		if(((inSibsBuf->sibMask & SIB1_MASK) == SIB1_MASK)&&((sysInfoind.sibMask & SIB1_MASK) == 0))
		{		
			logPrint(LOG_DEBUG,"Sib1 Start===========================================================================================\n");
			logPrint(LOG_DEBUG,"NoofPLMN = %d \n",inSib1Buf->noOfPlmns);

			sysInfoind.sib1.noOfPlmns= inSib1Buf->noOfPlmns;
			for(i = 0; i < LTE_MAX_NO_PLMNS; i++)
			{
		   		sysInfoind.sib1.plmn[i].mccLength = 0;
		   		sysInfoind.sib1.plmn[i].mcc[0]    = 0;
		   		sysInfoind.sib1.plmn[i].mcc[1]    = 0;
		   		sysInfoind.sib1.plmn[i].mcc[2]    = 0;
		   		sysInfoind.sib1.plmn[i].mncLength = 0;
		   		sysInfoind.sib1.plmn[i].mnc[0]    = 0;
		   		sysInfoind.sib1.plmn[i].mnc[1]    = 0;
		   		sysInfoind.sib1.plmn[i].mnc[2]    = 0;
			}

			for (i = 0; i < sysInfoind.sib1.noOfPlmns; i++)
			{
		    	logPrint(LOG_DEBUG,"SIB1 PLMN MCC LENGTH = %d\n", inSib1Buf->plmn[i].mccLength);
				logPrint(LOG_DEBUG,"SIB1 PLMN MCC = %d %d %d \n",inSib1Buf->plmn[i].mcc[0] ,inSib1Buf->plmn[i].mcc[1] , inSib1Buf->plmn[i].mcc[2] );
			
				sysInfoind.sib1.plmn[i].mccLength = inSib1Buf->plmn[i].mccLength;
				for (j = 0; j < sysInfoind.sib1.plmn[i].mccLength; j++)
				{
			    	sysInfoind.sib1.plmn[i].mcc[j] = inSib1Buf->plmn[i].mcc[j];
				}

		    	logPrint(LOG_DEBUG,"SIB1 PLMN MNC LENGTH = %d\n", inSib1Buf->plmn[i].mncLength);
				logPrint(LOG_DEBUG,"SIB1 PLMN MNC = %d %d %d \n", inSib1Buf->plmn[i].mnc[0], inSib1Buf->plmn[i].mnc[1], inSib1Buf->plmn[i].mnc[2]);
			
				sysInfoind.sib1.plmn[i].mncLength = inSib1Buf->plmn[i].mncLength;
				for (j = 0; j < sysInfoind.sib1.plmn[i].mncLength; j++)
				{
			    	sysInfoind.sib1.plmn[i].mnc[j] = inSib1Buf->plmn[i].mnc[j];
				}
			}
		
			logPrint(LOG_DEBUG,"SIB1 CellId = %d , TrackingAreaCode = %d , freqBandIndicator = %d\n" ,inSib1Buf->cellId , inSib1Buf->trackingAreaCode , inSib1Buf->freqBandIndicator);				
			logPrint(LOG_DEBUG,"SIB1 isCellBarred = %d , isIntraFreqSelectionAllowed = %d , qRxLevMin = %d\n" ,inSib1Buf->isCellBarred , inSib1Buf->isIntraFreqSelectionAllowed , inSib1Buf->qRxLevMin);
			logPrint(LOG_DEBUG,"SIB1 qRxLevMinOffset = %d , siPeriodicity = %d , siWindowLength = %d\n" ,inSib1Buf->qRxLevMinOffset , inSib1Buf->siPeriodicity , inSib1Buf->siWindowLength);
			logPrint(LOG_DEBUG,"SIB1 systemValueTag = %d , noOfPlmns = %d , pMax = %d\n" ,inSib1Buf->systemValueTag , inSib1Buf->noOfPlmns , inSib1Buf->pMax);

			sysInfoind.sib1.l3cellId = inSib1Buf->cellId;
			sysInfoind.sib1.tac = inSib1Buf->trackingAreaCode;
			sysInfoind.sib1.freqBandIndicator = inSib1Buf->freqBandIndicator;//getLteBandFromEARFCN(sysInfoind.earfcn) + 1;//inSib1Buf->freqBandIndicator;
			sysInfoind.sib1.isCellBarred = inSib1Buf->isCellBarred;
			sysInfoind.sib1.qRxLevMin = inSib1Buf->qRxLevMin;
			sysInfoind.sib1.qRxLevMinOffset = inSib1Buf->qRxLevMinOffset;
			sysInfoind.sib1.siPeriodicity = inSib1Buf->siPeriodicity;
			sysInfoind.sib1.siWindowLength = inSib1Buf->siWindowLength;
			sysInfoind.sib1.isIntraFreqSelectionAllowed= inSib1Buf->isIntraFreqSelectionAllowed;
			sysInfoind.sib1.pMax = inSib1Buf->pMax;
			sysInfoind.sibMask = (sysInfoind.sibMask)|(SIB1_MASK);		

			logPrint(LOG_DEBUG,"Sib1 SIB-MASK = %d End===========================================================================================\n" , inSibsBuf->sibMask);
			logPrint(LOG_DEBUG,"\n");
		}

		if(((inSibsBuf->sibMask & SIB2_MASK) == SIB2_MASK)&&((sysInfoind.sibMask & SIB2_MASK) == 0))
		{
			logPrint(LOG_DEBUG,"Sib2 Start===========================================================================================\n");

			logPrint(LOG_DEBUG,"Sib2 alpha = %d , cyclicPrefixLen = %d , deltaPreambleMsg3 = %d \n", inSibsBuf->sib2.alpha , inSibsBuf->sib2.cyclicPrefixLen , inSibsBuf->sib2.deltaPreambleMsg3);
			logPrint(LOG_DEBUG,"Sib2 drxCycle = %d , enable64QAM = %d , format1Delta = %d \n", inSibsBuf->sib2.drxCycle , inSibsBuf->sib2.enable64QAM , inSibsBuf->sib2.format1Delta);
			logPrint(LOG_DEBUG,"Sib2 format1bDelta = %d , format2Delta = %d , format2aDelta = %d \n", inSibsBuf->sib2.format1bDelta , inSibsBuf->sib2.format2Delta , inSibsBuf->sib2.format2aDelta);
			logPrint(LOG_DEBUG,"Sib2 format2bDelta = %d , hoppingMode = %d , isBarredForEmergency = %d \n", inSibsBuf->sib2.format2bDelta , inSibsBuf->sib2.hoppingMode , inSibsBuf->sib2.isBarredForEmergency);
			logPrint(LOG_DEBUG,"Sib2 isBarredForMoData = %d , isBarredForMoSignalling = %d , isGroupHoppingEnabled = %d \n", inSibsBuf->sib2.isBarredForMoData , inSibsBuf->sib2.isBarredForMoSignalling , inSibsBuf->sib2.isGroupHoppingEnabled);
			logPrint(LOG_DEBUG,"Sib2 isHighSpeedFlagSet = %d , isSequenceHoppingEnabled = %d , isSrsAckNackSimultaeneousTransmissionAllowed = %d \n", inSibsBuf->sib2.isHighSpeedFlagSet , inSibsBuf->sib2.isSequenceHoppingEnabled , inSibsBuf->sib2.isSrsAckNackSimultaeneousTransmissionAllowed);
			logPrint(LOG_DEBUG,"Sib2 macContentionResolutionTimer = %d , maxHARQMsg3Tx = %d , modficationCoeff = %d \n", inSibsBuf->sib2.macContentionResolutionTimer , inSibsBuf->sib2.maxHARQMsg3Tx , inSibsBuf->sib2.modficationCoeff);
			logPrint(LOG_DEBUG,"Sib2 n1CsAn = %d , n1PucchAN = %d , n310 = %d \n", inSibsBuf->sib2.n1CsAn , inSibsBuf->sib2.n1PucchAN , inSibsBuf->sib2.n310);
			logPrint(LOG_DEBUG,"Sib2 n311 = %d , nB = %d , nRBCqi = %d \n", inSibsBuf->sib2.n311 , inSibsBuf->sib2.nB , inSibsBuf->sib2.nRBCqi);
			logPrint(LOG_DEBUG,"Sib2 noRaPreambles = %d , p0NominalPUCCH = %d , p0NominalPUSCH = %d \n", inSibsBuf->sib2.noRaPreambles , inSibsBuf->sib2.p0NominalPUCCH , inSibsBuf->sib2.p0NominalPUSCH);
			logPrint(LOG_DEBUG,"Sib2 pB = %d , powerRampingStep = %d , prachConfigIndex = %d \n", inSibsBuf->sib2.pB , inSibsBuf->sib2.powerRampingStep , inSibsBuf->sib2.prachConfigIndex);
			logPrint(LOG_DEBUG,"Sib2 prachFreqOffset = %d , prachZeroCorrelationZoneConfig = %d , preambleTargetPower = %d \n", inSibsBuf->sib2.prachFreqOffset , inSibsBuf->sib2.prachZeroCorrelationZoneConfig , inSibsBuf->sib2.preambleTargetPower);
			logPrint(LOG_DEBUG,"Sib2 preambleTransMax = %d , pucchDeltaShift = %d , puschGroupAssignment = %d \n", inSibsBuf->sib2.preambleTransMax , inSibsBuf->sib2.pucchDeltaShift , inSibsBuf->sib2.puschGroupAssignment);
			logPrint(LOG_DEBUG,"Sib2 puschHoppingOffset = %d , puschNSB = %d , puschRefSigCyclicShift = %d \n", inSibsBuf->sib2.puschHoppingOffset , inSibsBuf->sib2.puschNSB , inSibsBuf->sib2.puschRefSigCyclicShift);
			logPrint(LOG_DEBUG,"Sib2 raResponseWindow = %d , refSignalPower = %d , rootSequenceIndex = %d \n", inSibsBuf->sib2.raResponseWindow , inSibsBuf->sib2.refSignalPower , inSibsBuf->sib2.rootSequenceIndex);
			logPrint(LOG_DEBUG,"Sib2 srsBw = %d , srsSubframe = %d , t300 = %d \n", inSibsBuf->sib2.srsBw , inSibsBuf->sib2.srsSubframe , inSibsBuf->sib2.t300);
			logPrint(LOG_DEBUG,"Sib2 t301 = %d , t310 = %d , t311 = %d \n", inSibsBuf->sib2.t301 , inSibsBuf->sib2.t310 , inSibsBuf->sib2.t311);
			logPrint(LOG_DEBUG,"Sib2 taTimer = %d , Uplink Bandwidth = %d , Uplink Frequency = %d\n", inSibsBuf->sib2.taTimer ,inSibsBuf->sib2.ulBandwidth , inSibsBuf->sib2.ulFrequency ); // Added UlFreq & Bw

			sysInfoind.sib2.drxCycle = inSibsBuf->sib2.drxCycle;
			sysInfoind.sib2.prachConfigIdx = inSibsBuf->sib2.prachConfigIndex;
			sysInfoind.sib2.prachZeroCorrelationZoneConfig = inSibsBuf->sib2.prachZeroCorrelationZoneConfig;
			sysInfoind.sib2.prachFreqOffset = inSibsBuf->sib2.prachFreqOffset;
			sysInfoind.sib2.highSpeedFlag = inSibsBuf->sib2.isHighSpeedFlagSet;
			sysInfoind.sib2.p0NominalPUCCH = inSibsBuf->sib2.p0NominalPUCCH;
        	sysInfoind.sibMask = (sysInfoind.sibMask)|(SIB2_MASK);		
			logPrint(LOG_DEBUG,"Sib2 End===========================================================================================\n");
			logPrint(LOG_DEBUG,"\n");
		}
		
		if(((inSibsBuf->sibMask & SIB3_MASK) == SIB3_MASK)&&((sysInfoind.sibMask & SIB3_MASK) == 0))
		{
			logPrint(LOG_DEBUG,"Sib3 Start===========================================================================================\n");
			logPrint(LOG_DEBUG,"Sib3 cellReselectionPriority = %d , isAntennaPort1Present = %d , qHyst = %d\n", inSibsBuf->sib3.cellReselectionPriority , inSibsBuf->sib3.isAntennaPort1Present , inSibsBuf->sib3.qHyst );
			logPrint(LOG_DEBUG,"Sib3 qRxLevMin = %d , tReselectionEUTRA = %d , threshServingLow = %d\n", inSibsBuf->sib3.qRxLevMin , inSibsBuf->sib3.tReselectionEUTRA , inSibsBuf->sib3.threshServingLow );
			logPrint(LOG_DEBUG,"Sib3 sNonIntraSearch = %d sIntraSearch = %d neighbourCellConfig = %0x\n", inSibsBuf->sib3.sNonIntraSearch , inSibsBuf->sib3.sIntraSearch , inSibsBuf->sib3.neighbourCellConfig);

			logPrint(LOG_DEBUG,"Sib3 End===========================================================================================\n");
			logPrint(LOG_DEBUG,"\n");
			sysInfoind.sib3.cellReselectionPriority = inSibsBuf->sib3.cellReselectionPriority;
			sysInfoind.sib3.isAntennaPort1Present = inSibsBuf->sib3.isAntennaPort1Present;
			sysInfoind.sib3.qHyst = inSibsBuf->sib3.qHyst;
			sysInfoind.sib3.qRxLevMin = inSibsBuf->sib3.qRxLevMin;
			sysInfoind.sib3.sIntraSearch = inSibsBuf->sib3.sIntraSearch;
			sysInfoind.sib3.sNonIntraSearch = inSibsBuf->sib3.sNonIntraSearch;
			sysInfoind.sib3.threshServingLow =  inSibsBuf->sib3.threshServingLow;
			sysInfoind.sib3.tReselectionEUTRA = inSibsBuf->sib3.tReselectionEUTRA;
			sysInfoind.sib3.neighbourCell = inSibsBuf->sib3.neighbourCellConfig;
			sysInfoind.sibMask = (sysInfoind.sibMask)|(SIB3_MASK);		
		}
		if(((inSibsBuf->sibMask & SIB4_MASK) == SIB4_MASK)&&((sysInfoind.sibMask & SIB4_MASK) == 0))
		{
			logPrint(LOG_DEBUG,"Sib4 Start===========================================================================================\n");
			logPrint(LOG_DEBUG,"Sib4 noOfIntraNeighbourCells = %d , noOfBlackListIntraNeighbourCells = %d \n", inSibsBuf->sib4.noOfIntraNeighbourCells , inSibsBuf->sib4.noOfBlackListIntraNeighbourCells );
			if(inSibsBuf->sib4.noOfIntraNeighbourCells > MAX_NO_OF_INTRA_FREQ_NEIGHBOR_CELLS)
			inSibsBuf->sib4.noOfIntraNeighbourCells = MAX_NO_OF_INTRA_FREQ_NEIGHBOR_CELLS;

			sysInfoind.sib4.noOfIntraFreqNeighbors = inSibsBuf->sib4.noOfIntraNeighbourCells ;
			for(i = 0; i <inSibsBuf->sib4.noOfIntraNeighbourCells ; i++)
			{
				logPrint(LOG_DEBUG,"Sib4 neighbourIntraCells-CellId = %d , neighbourIntra-CellQOffset = %d \n", inSibsBuf->sib4.neighbourIntraCells[i] , inSibsBuf->sib4.neighbourIntraCellQOffset[i] );
				sysInfoind.sib4.intraFreqCells[i].intraFreqNeighborCellPci = inSibsBuf->sib4.neighbourIntraCells[i] ;
				sysInfoind.sib4.intraFreqCells[i].intraFreqNeighborCellQoffset = inSibsBuf->sib4.neighbourIntraCellQOffset[i] ;
			}
			if(inSibsBuf->sib4.noOfBlackListIntraNeighbourCells > MAX_NO_OF_BLACKLISTED_NEIGHBOUR_CELLS_IN_SIB4)
				inSibsBuf->sib4.noOfBlackListIntraNeighbourCells = MAX_NO_OF_BLACKLISTED_NEIGHBOUR_CELLS_IN_SIB4;
			sysInfoind.sib4.noOfBlacklistedIntraFreqNeighbors = inSibsBuf->sib4.noOfBlackListIntraNeighbourCells ;
			for(i = 0; i <inSibsBuf->sib4.noOfBlackListIntraNeighbourCells ; i++)
			{
				sysInfoind.sib4.intraFreqBlacklistedCellPci[i] = inSibsBuf->sib4.blackListedIntraNeighbourCells[i] ;
				logPrint(LOG_DEBUG,"Sib4 blackListedIntraNeighbourCells-CellId = %d \n", inSibsBuf->sib4.blackListedIntraNeighbourCells[i] );
			}
			logPrint(LOG_DEBUG,"Sib4 End===========================================================================================\n");
			logPrint(LOG_DEBUG,"\n");
			sysInfoind.sibMask = (sysInfoind.sibMask)|(SIB4_MASK);		
		}
		if(((inSibsBuf->sibMask & SIB5_MASK) == SIB5_MASK)&&((sysInfoind.sibMask & SIB5_MASK) == 0))
		{
			logPrint(LOG_DEBUG,"Sib5 Start===========================================================================================\n");

			logPrint(LOG_DEBUG,"Sib5 noOfInterFreqNeighbourCells = %d \n", inSibsBuf->sib5.noOfInterFreqNeighbourCells );
			if(inSibsBuf->sib5.noOfInterFreqNeighbourCells > MAX_NO_OF_INTER_FREQ_NEIGHBOR_EARFCNS)
				inSibsBuf->sib5.noOfInterFreqNeighbourCells = MAX_NO_OF_INTER_FREQ_NEIGHBOR_EARFCNS;

			sysInfoind.sib5.noOfInterFreqNeighbourCells = inSibsBuf->sib5.noOfInterFreqNeighbourCells;
			for(i = 0; i <inSibsBuf->sib5.noOfInterFreqNeighbourCells ; i++)
			{
				logPrint(LOG_DEBUG,"Sib5 cellReselectionPriority = %d , dlCarrierFreq = %d \n", inSibsBuf->sib5.interFreqNeighbourCell[i].cellReselectionPriority , inSibsBuf->sib5.interFreqNeighbourCell[i].dlCarrierFreq );
				logPrint(LOG_DEBUG,"Sib5 qRxLevMin = %d , threshXLow = %d \n", inSibsBuf->sib5.interFreqNeighbourCell[i].qRxLevMin , inSibsBuf->sib5.interFreqNeighbourCell[i].threshXLow );
				sysInfoind.sib5.earfcnInterFreqNeighbors[i].dlCarrierFreq= inSibsBuf->sib5.interFreqNeighbourCell[i].dlCarrierFreq;
				sysInfoind.sib5.earfcnInterFreqNeighbors[i].cellReselectionPriority= inSibsBuf->sib5.interFreqNeighbourCell[i].cellReselectionPriority;
				sysInfoind.sib5.earfcnInterFreqNeighbors[i].qRxLevMin= inSibsBuf->sib5.interFreqNeighbourCell[i].qRxLevMin;
				sysInfoind.sib5.earfcnInterFreqNeighbors[i].threshXLow= inSibsBuf->sib5.interFreqNeighbourCell[i].threshXLow;				
			}
			logPrint(LOG_DEBUG,"Sib5 End===========================================================================================\n");
			logPrint(LOG_DEBUG,"\n");
			sysInfoind.sibMask = (sysInfoind.sibMask)|(SIB5_MASK);		
		}
		if(((inSibsBuf->sibMask & SIB6_MASK) == SIB6_MASK)&&((sysInfoind.sibMask & SIB6_MASK) == 0))
		{
			logPrint(LOG_DEBUG,"Sib6 Start===========================================================================================\n");
			

			if(inSibsBuf->sib6.noOfUmtsNeighborCells > MAX_NO_OF_INTER_RAT_NEIGHBOR_UARFCNS)
				inSibsBuf->sib6.noOfUmtsNeighborCells = MAX_NO_OF_INTER_RAT_NEIGHBOR_UARFCNS;

			sysInfoind.sib6.noOfInterRatUmtsNeighbors = inSibsBuf->sib6.noOfUmtsNeighborCells;
			logPrint(LOG_DEBUG,"Sib6 noOfUmtsNeighborCells = %d ,  tReselectionUTRA = %d\n", inSibsBuf->sib6.noOfUmtsNeighborCells , inSibsBuf->sib6.tReselectionUTRA  );
			for(i = 0; i <inSibsBuf->sib6.noOfUmtsNeighborCells ; i++)
			{
				logPrint(LOG_DEBUG,"Sib6 umtsCarrierFreq = %d \n", inSibsBuf->sib6.umtsNeighbourCell[i].umtsCarrierFreq);
				logPrint(LOG_DEBUG,"Sib6 cellReselectionPriority = %d , pMaxUTRA = %d , qQualMin = %d \n", inSibsBuf->sib6.umtsNeighbourCell[i].cellReselectionPriority , inSibsBuf->sib6.umtsNeighbourCell[i].pMaxUTRA , inSibsBuf->sib6.umtsNeighbourCell[i].qQualMin );
				logPrint(LOG_DEBUG,"Sib6 qRxLevMin = %d , threshXHigh = %d , threshXLow = %d\n", inSibsBuf->sib6.umtsNeighbourCell[i].qRxLevMin , inSibsBuf->sib6.umtsNeighbourCell[i].threshXHigh , inSibsBuf->sib6.umtsNeighbourCell[i].threshXLow);
				sysInfoind.sib6.uarfcnInterRatNeighbors[i].umtsCarrierFreq= inSibsBuf->sib6.umtsNeighbourCell[i].umtsCarrierFreq;
				sysInfoind.sib6.uarfcnInterRatNeighbors[i].cellReselectionPriority= inSibsBuf->sib6.umtsNeighbourCell[i].cellReselectionPriority;
				sysInfoind.sib6.uarfcnInterRatNeighbors[i].pMaxUTRA= inSibsBuf->sib6.umtsNeighbourCell[i].pMaxUTRA;
				sysInfoind.sib6.uarfcnInterRatNeighbors[i].qQualMin= inSibsBuf->sib6.umtsNeighbourCell[i].qQualMin;
				sysInfoind.sib6.uarfcnInterRatNeighbors[i].qRxLevMin= inSibsBuf->sib6.umtsNeighbourCell[i].qRxLevMin;				
				sysInfoind.sib6.uarfcnInterRatNeighbors[i].threshXHigh= inSibsBuf->sib6.umtsNeighbourCell[i].threshXHigh;
				sysInfoind.sib6.uarfcnInterRatNeighbors[i].threshXLow= inSibsBuf->sib6.umtsNeighbourCell[i].threshXLow;				
			}
			logPrint(LOG_DEBUG,"Sib6 End===========================================================================================\n");
			logPrint(LOG_DEBUG,"\n");
			sysInfoind.sibMask = (sysInfoind.sibMask)|(SIB6_MASK);		
		}
		
		if(((inSibsBuf->sibMask & SIB7_MASK) == SIB7_MASK)&&((sysInfoind.sibMask & SIB7_MASK) == 0))
		{
			logPrint(LOG_DEBUG,"Sib7 Start===========================================================================================\n");
			logPrint(LOG_DEBUG,"Sib7 noOfGsmNeighborCells = %d ,  tReselectionGeran = %d\n", inSibsBuf->sib7.noOfGsmNeighborCells , inSibsBuf->sib7.tReselectionGERAN  );

			if(inSibsBuf->sib7.noOfGsmNeighborCells > MAX_NO_OF_INTER_RAT_NEIGHBOR_ARFCNS)
				inSibsBuf->sib7.noOfGsmNeighborCells = MAX_NO_OF_INTER_RAT_NEIGHBOR_ARFCNS;
			sysInfoind.sib7.noOfInterRatGsmNeighbors = inSibsBuf->sib7.noOfGsmNeighborCells;

			for(i = 0; i <inSibsBuf->sib7.noOfGsmNeighborCells ; i++)
			{
				logPrint(LOG_DEBUG,"Sib7 GSM-Starting-ARFCN = %d , BandIndicator = %d \n", inSibsBuf->sib7.gsmNeighbourCell[i].startingARFCN , inSibsBuf->sib7.gsmNeighbourCell[i].bandIndicator );
				logPrint(LOG_DEBUG,"Sib7 cellReselectionPriority = %d , pMaxGERAN = %d , qRxLevMin = %d \n", inSibsBuf->sib7.gsmNeighbourCell[i].cellReselectionPriority , inSibsBuf->sib7.gsmNeighbourCell[i].pMaxGeran , inSibsBuf->sib7.gsmNeighbourCell[i].qRxLevMin );
				logPrint(LOG_DEBUG,"Sib7 threshXHigh = %d , threshXLow = %d , followingArfcnType = %d\n", inSibsBuf->sib7.gsmNeighbourCell[i].threshXHigh , inSibsBuf->sib7.gsmNeighbourCell[i].threshXLow , inSibsBuf->sib7.gsmNeighbourCell[i].followingArfcnType);
				sysInfoind.sib7.startingArfcnInterRatNeighbors[i] = inSibsBuf->sib7.gsmNeighbourCell[i].startingARFCN;
				sysInfoind.sib7.bandIndicator[i] = inSibsBuf->sib7.gsmNeighbourCell[i].bandIndicator;

				if(inSibsBuf->sib7.gsmNeighbourCell[i].followingArfcnType == LTE_FOLLOWING_ARFCN_EXPLICITLIST)
				{
					logPrint(LOG_DEBUG,"Sib7 followingArfcnType = LTE_FOLLOWING_ARFCN_EXPLICITLIST , NoOfFollowingARFCN = %d \n", inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.expArfcn.noOfArfcn );
					for(uint8 j = 0 ;j <inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.expArfcn.noOfArfcn; j++)
					logPrint(LOG_DEBUG,"Sib7 followingNeighborArfcn = %d \n", inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.expArfcn.ARFCN_ValueGERAN[j] );

				}
				else if(inSibsBuf->sib7.gsmNeighbourCell[i].followingArfcnType == LTE_FOLLOWING_ARFCN_EQUALLYSPACED)
				{
					logPrint(LOG_DEBUG,"Sib7 followingArfcnType = LTE_FOLLOWING_ARFCN_EQUALLYSPACED , NoOfFollowingEquallySpacedARFCN = %d with Equal-Spacing = %d \n", inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.eqArfcn.numberOfFollowingARFCNs , inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.eqArfcn.arfcn_Spacing );
				}
				else if(inSibsBuf->sib7.gsmNeighbourCell[i].followingArfcnType == LTE_FOLLOWING_ARFCN_VARIABLEBITMAP)
				{
					logPrint(LOG_DEBUG,"Sib7 followingArfcnType = LTE_FOLLOWING_ARFCN_VARIABLEBITMAP \n");
					logPrint(LOG_DEBUG,"Sib7 Bitmap0-7 = 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n", inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[0] ,inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[1] , inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[2], inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[3],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[4],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[5],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[6],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[7]);
					logPrint(LOG_DEBUG,"Sib7 Bitmap8-15 = 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n", inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[8] ,inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[9] , inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[10], inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[11],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[12],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[13],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[14],inSibsBuf->sib7.gsmNeighbourCell[i].neighborList.varBitMapArfcn.bitmap[15]);
				}

			}

			logPrint(LOG_DEBUG,"Sib7 End===========================================================================================\n");
			logPrint(LOG_DEBUG,"\n");
			sysInfoind.sibMask = (sysInfoind.sibMask)|(SIB7_MASK);
		}

	}
	else
	{
	    logPrint(LOG_DEBUG,"Decode Failed for SIB1 & SIBS\n");
	}

	free(inSib1Buf);
	inSib1Buf = NULL;
	free(inSibsBuf);
	inSibsBuf = NULL;
	cleanLteASNContext();
}

void sendLteSysInfoInd(void)
{

    if((0 == sysInfoind.sibMask) ||((sysInfoind.sib1.plmn[0].mccLength == 0)&&(sysInfoind.sib1.plmn[0].mncLength == 0)) )
    {
        logPrint(LOG_DEBUG,"Sibmask = %d , mccLength = %d ,mncLength =%d  \n" , sysInfoind.sibMask,
			     sysInfoind.sib1.plmn[0].mccLength,sysInfoind.sib1.plmn[0].mncLength);
        return;
    }

    if(sysInfoind.sib1.freqBandIndicator <= 48)
    {
		if(sysInfoind.sib1.freqBandIndicator != (getLteBandFromEARFCN(sysInfoind.earfcn) + 1))
		{
		    logPrint(LOG_DEBUG,"Skipping overlap frequencies SIB1 Frequency Band Indicator = %d, Searching Band = %d\n", 
			         sysInfoind.sib1.freqBandIndicator, (getLteBandFromEARFCN(sysInfoind.earfcn) + 1));
		    return;
		}
		else
		{
			sysInfoind.sib1.freqBandIndicator = sysInfoind.sib1.freqBandIndicator - 1;
		}
    }
    else if (sysInfoind.sib1.freqBandIndicator == 50 || sysInfoind.sib1.freqBandIndicator == 51)
    {
        if(sysInfoind.sib1.freqBandIndicator != (getLteBandFromEARFCN(sysInfoind.earfcn) + 2))
        {
            logPrint(LOG_DEBUG,"Skipping overlap frequencies SIB1 Frequency Band Indicator = %d, Searching Band = %d\n",
                         sysInfoind.sib1.freqBandIndicator, (getLteBandFromEARFCN(sysInfoind.earfcn) + 2));
            return;
        }
		else
		{
			sysInfoind.sib1.freqBandIndicator = sysInfoind.sib1.freqBandIndicator - 2;

		}
    }
    else if ((sysInfoind.sib1.freqBandIndicator >= 65) && (sysInfoind.sib1.freqBandIndicator <= 72))
    {
        if((sysInfoind.sib1.freqBandIndicator - 14) != (getLteBandFromEARFCN(sysInfoind.earfcn) + 1))
        {
            logPrint(LOG_DEBUG,"Skipping overlap frequencies SIB1 Frequency Band Indicator = %d, Searching Band = %d\n",
                         (sysInfoind.sib1.freqBandIndicator - 14), (getLteBandFromEARFCN(sysInfoind.earfcn) + 1));
            return;
        }		
		else
		{
			sysInfoind.sib1.freqBandIndicator = sysInfoind.sib1.freqBandIndicator - 15;

		}
    }
    else if((sysInfoind.sib1.freqBandIndicator >= 74) && (sysInfoind.sib1.freqBandIndicator <= 76))
    {
        if((sysInfoind.sib1.freqBandIndicator - 15) != (getLteBandFromEARFCN(sysInfoind.earfcn) + 1))
        {
            logPrint(LOG_DEBUG,"Skipping overlap frequencies SIB1 Frequency Band Indicator = %d, Searching Band = %d\n",
                         (sysInfoind.sib1.freqBandIndicator - 15), (getLteBandFromEARFCN(sysInfoind.earfcn) + 1));
            return;
        }
		else
		{
			sysInfoind.sib1.freqBandIndicator = sysInfoind.sib1.freqBandIndicator - 16;
		}
    }
	else
	{
		if(sysInfoind.sib1.freqBandIndicator == 52)
		{
			sysInfoind.sib1.freqBandIndicator = sysInfoind.sib1.freqBandIndicator + 10;
		}

	}
	logPrint(LOG_DEBUG,"All decoded sibs SIB-MASK = %d	\n", sysInfoind.sibMask);
	if(((sysInfoind.sibMask) & SIB5_MASK) == 0)
	{
		memset(&sysInfoind.sib5 , 0 , sizeof(fxL4gSib5));
	}
	if(((sysInfoind.sibMask) & SIB4_MASK) == 0)
	{
		memset(&sysInfoind.sib4 , 0 , sizeof(fxL4gSib4));
	}
	if(((sysInfoind.sibMask) & SIB6_MASK) == 0)
	{
		memset(&sysInfoind.sib6 , 0 , sizeof(fxL4gSib6));
	}
	if(((sysInfoind.sibMask) & SIB7_MASK) == 0)
	{
		memset(&sysInfoind.sib7 , 0 , sizeof(fxL4gSib7));
	}	
	
	sysInfoind.hdr.msgLength = sizeof(fxL4gListenModeSystemInfoInd);
	sysInfoind.hdr.msgType   = FXL_4G_LISTEN_MODE_SYSTEM_INFO_IND;
	sysInfoind.hdr.rat       = FXL_RAT_4G;
    writeToExternalSocketInterface((uint8*)&sysInfoind , sizeof(fxL4gListenModeSystemInfoInd));

	addLteScanDataToList(&sysInfoind);
    memset((uint8*)&sysInfoind , 0 , sizeof(fxL4gListenModeSystemInfoInd));
    return;
}
