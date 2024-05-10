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
 * File Name   : umtsDecode.c
 *
 * Description : This file provides UMTS BCCH decoding functionality for WNM.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 12/10/2014	        Ashutosh Samal              File Creation
 *############################################################################
*/

/*
 * Include Files
 */
#include <stdio.h>
#include <string.h>
#include "asnApi.h"
#include "slsDecode3g.h"
#include "fxLSocketInterfaceApi.h"
#include "cmnDebug.h"

static DbgModule_e  DBG_MODULE = sls;

extern fxL3gListenModeSystemInfoInd g3gListenModeSysInfo;
void fillPlmn (MultiPlmnData multiPlmnInfo , unsigned int sibMask);
void fillSib1Info(Sib1Data sib1Info);
void fillCellSelResel (CellSelReselData cellSelReselInfo);
void initializeFreqCellInfo (SysInfoType11FreqCellList *pFreqCellInfo);
void fillFreqCellInfo (SysInfoType11FreqCellList freqCellInfo);
/*
 * Set Each Bit
 */
void WnmUmtsSetBit (unsigned char *pData, int byteIndex, 
                    int bitPosition, int bitValue)
{
   if (bitValue)
   {
      pData[byteIndex] |= (0x01 << bitPosition);
   }
   else
   {
      pData[byteIndex] &= ~(0x01 << bitPosition);
   }
}

/*
 * Combine All Segment
 */
void WnmUmtsCombineAllSegment (unsigned char *pCompleteData,
                               unsigned char *pSegmentedData,
                               int           *pTotalBitLength,
                               int           *pBitOffset,
                               int           *pByteOffset,
                               int            bitToCopy)
{
   int leftOver  = *pBitOffset;
   int byteCount = *pByteOffset;
   int bitCount  = 0;

   for (bitCount = 0; bitCount < bitToCopy; bitCount++)
   {
       WnmUmtsSetBit (pCompleteData, byteCount, (7 -leftOver),
                      (pSegmentedData[(bitCount >> 3)] >> (7 - (bitCount %8)) & 0x1));
       leftOver++;
       if (leftOver == 8)
       {
           leftOver = 0;
           byteCount++;
       }
   }

   *pBitOffset      = leftOver;
   *pTotalBitLength = *pTotalBitLength - bitToCopy;
   *pByteOffset     = byteCount;
}

/*
 * Combine And Decode MIB
 */
void WnmUmtsCombineAndDecodeMib (BcchSibInfo_t *pBcchSibInfo)
{
    int mibCount       = 0;
    int bitOffset      = 0;
    int byteOffset     = 0;
    int totalBitLength = 0;
    unsigned int sibMask = 0;
    MultiPlmnData multiPlmnInfo;
    memset((MultiPlmnData *)&multiPlmnInfo, 0, sizeof(MultiPlmnData));
   
    /* Maximum 10 Segments of MIB */
    unsigned char completeMib[320] = {0};
   
    /* Calculate Total Bit Length */
    for(mibCount = 0; mibCount < pBcchSibInfo->mibInfo.totalNumSeg; mibCount++)
    {
        totalBitLength += pBcchSibInfo->mibInfo.mibSegInfo[mibCount].bitLength;
    }

    /* Combine All Data */
    for(mibCount = 0; mibCount < pBcchSibInfo->mibInfo.totalNumSeg; mibCount++)
    {
        WnmUmtsCombineAllSegment(completeMib,
                                 pBcchSibInfo->mibInfo.mibSegInfo[mibCount].mibSegData,
                                 &totalBitLength, &bitOffset, &byteOffset,
                                 pBcchSibInfo->mibInfo.mibSegInfo[mibCount].bitLength);
    }

    /* Decode Complete MIB */
    decodeASNMib (completeMib, 320, &multiPlmnInfo , &sibMask);
    fillPlmn (multiPlmnInfo , sibMask);
}

/*
 * Combine And Decode SIB1
 */
void WnmUmtsCombineAndDecodeSib1 (BcchSibInfo_t *pBcchSibInfo)
{
    int sib1Count      = 0;
    int bitOffset      = 0;
    int byteOffset     = 0;
    int totalBitLength = 0;
    Sib1Data sib1Info;
    memset((Sib1Data *)&sib1Info, 0, sizeof(Sib1Data));
   
    /* Maximum 10 Segments of SIB1 */
    unsigned char completeSib1[320] = {0};
   
    /* Calculate Total Bit Length */
    for(sib1Count = 0; sib1Count < pBcchSibInfo->sib1Info.totalNumSeg; sib1Count++)
    {
        totalBitLength += pBcchSibInfo->sib1Info.sib1SegInfo[sib1Count].bitLength;
    }

    /* Combine All Data */
    for(sib1Count = 0; sib1Count < pBcchSibInfo->sib1Info.totalNumSeg; sib1Count++)
    {
        WnmUmtsCombineAllSegment(completeSib1,
                                 pBcchSibInfo->sib1Info.sib1SegInfo[sib1Count].sib1SegData,
                                 &totalBitLength, &bitOffset, &byteOffset,
                                 pBcchSibInfo->sib1Info.sib1SegInfo[sib1Count].bitLength);
    }

    /* Decode Complete SIB1 */
    decodeASNSib1 (completeSib1, 320, &sib1Info);
    fillSib1Info(sib1Info);
}

/*
 * Combine And Decode SIB3
 */
void WnmUmtsCombineAndDecodeSib3 (BcchSibInfo_t *pBcchSibInfo)
{
    int sib3Count      = 0;
    int bitOffset      = 0;
    int byteOffset     = 0;
    int totalBitLength = 0;
    CellSelReselData cellSelReselInfo;
    memset((CellSelReselData *)&cellSelReselInfo, 0, sizeof(CellSelReselData));
   
    /* Maximum 20 Segments of SIB3 */
    unsigned char completeSib3[640] = {0};
   
    /* Calculate Total Bit Length */
    for(sib3Count = 0; sib3Count < pBcchSibInfo->sib3Info.totalNumSeg; sib3Count++)
    {
        totalBitLength += pBcchSibInfo->sib3Info.sib3SegInfo[sib3Count].bitLength;
    }

    /* Combine All Data */
    for(sib3Count = 0; sib3Count < pBcchSibInfo->sib3Info.totalNumSeg; sib3Count++)
    {
        WnmUmtsCombineAllSegment(completeSib3,
                                 pBcchSibInfo->sib3Info.sib3SegInfo[sib3Count].sib3SegData,
                                 &totalBitLength, &bitOffset, &byteOffset,
                                 pBcchSibInfo->sib3Info.sib3SegInfo[sib3Count].bitLength);
    }

    /* Decode Complete SIB3 */
    decodeASNSib3 (completeSib3, 640, &cellSelReselInfo);
    fillCellSelResel (cellSelReselInfo);
}

/*
 * Combine And Decode SIB11
 */
void WnmUmtsCombineAndDecodeSib11 (BcchSibInfo_t *pBcchSibInfo)
{
    int sib11Count     = 0;
    int bitOffset      = 0;
    int byteOffset     = 0;
    int totalBitLength = 0;
    SysInfoType11FreqCellList freqCellInfo;
    initializeFreqCellInfo (&freqCellInfo);
 
    /* Maximum 30 Segments of SIB11 */
    unsigned char completeSib11[960] = {0};
   
    /* Calculate Total Bit Length */
    for(sib11Count = 0; sib11Count < pBcchSibInfo->sib11Info.totalNumSeg; sib11Count++)
    {
        totalBitLength += pBcchSibInfo->sib11Info.sib11SegInfo[sib11Count].bitLength;
    }

    /* Combine All Data */
    for(sib11Count = 0; sib11Count < pBcchSibInfo->sib11Info.totalNumSeg; sib11Count++)
    {
        WnmUmtsCombineAllSegment(completeSib11,
                                 pBcchSibInfo->sib11Info.sib11SegInfo[sib11Count].sib11SegData,
                                 &totalBitLength, &bitOffset, &byteOffset,
                                 pBcchSibInfo->sib11Info.sib11SegInfo[sib11Count].bitLength);
    }

    /* Decode Complete SIB11 */
    decodeASNSib11 (completeSib11, 960, &freqCellInfo);
    fillFreqCellInfo (freqCellInfo);
    pBcchSibInfo->isSib11Present = 1;
}

/*
 * Combine And Decode SIB12
 */
void WnmUmtsCombineAndDecodeSib12 (BcchSibInfo_t *pBcchSibInfo)
{
    int sib12Count     = 0;
    int bitOffset      = 0;
    int byteOffset     = 0;
    int totalBitLength = 0;
    SysInfoType11FreqCellList freqCellInfo;
    initializeFreqCellInfo (&freqCellInfo);
 
    /* Maximum 30 Segments of SIB12 */
    unsigned char completeSib12[960] = {0};
   
    /* Calculate Total Bit Length */
    for(sib12Count = 0; sib12Count < pBcchSibInfo->sib12Info.totalNumSeg; sib12Count++)
    {
        totalBitLength += pBcchSibInfo->sib12Info.sib12SegInfo[sib12Count].bitLength;
    }

    /* Combine All Data */
    for(sib12Count = 0; sib12Count < pBcchSibInfo->sib12Info.totalNumSeg; sib12Count++)
    {
        WnmUmtsCombineAllSegment(completeSib12,
                                 pBcchSibInfo->sib12Info.sib12SegInfo[sib12Count].sib12SegData,
                                 &totalBitLength, &bitOffset, &byteOffset,
                                 pBcchSibInfo->sib12Info.sib12SegInfo[sib12Count].bitLength);
    }

    /* Decode Complete SIB12 */
    decodeASNSib12 (completeSib12, 960, &freqCellInfo);
    if (0 == pBcchSibInfo->isSib11Present)
    {
        fillFreqCellInfo (freqCellInfo);
    }
}

/*
 * Combine And Decode SIB19
 */
void WnmUmtsCombineAndDecodeSib19 (BcchSibInfo_t *pBcchSibInfo)
{
    int sib19Count     = 0;
    int bitOffset      = 0;
    int byteOffset     = 0;
    int totalBitLength = 0;
    SysInfoType19FreqCellList priorityFreqCellInfo;
    initializePriorityFreqCellInfo (&priorityFreqCellInfo);

    /* Maximum 30 Segments of SIB19 */
    unsigned char completeSib19[960] = {0};

    /* Calculate Total Bit Length */
    for(sib19Count = 0; sib19Count < pBcchSibInfo->sib19Info.totalNumSeg; sib19Count++)
    {
        totalBitLength += pBcchSibInfo->sib19Info.sib19SegInfo[sib19Count].bitLength;
    }

    /* Combine All Data */
    for(sib19Count = 0; sib19Count < pBcchSibInfo->sib19Info.totalNumSeg; sib19Count++)
    {
        WnmUmtsCombineAllSegment(completeSib19,
                                 pBcchSibInfo->sib19Info.sib19SegInfo[sib19Count].sib19SegData,
                                 &totalBitLength, &bitOffset, &byteOffset,
                                 pBcchSibInfo->sib19Info.sib19SegInfo[sib19Count].bitLength);
    }

    /* Decode Complete SIB19 */
    decodeASNSib19 (completeSib19, 960, &priorityFreqCellInfo);
    fillPriorityFreqCellInfo (priorityFreqCellInfo);
}

/*
 * Decode First Segment
 */
void WnmUmtsDecodeFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                BcchSibInfo_t       *pBcchSibInfo)
{
    int sibCount = 0;

    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               pBcchSibInfo->mibInfo.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
               if (NOT_USED == pBcchSibInfo->mibInfo.mibSegInfo[0].usedOrNot)
               {
                   pBcchSibInfo->mibInfo.mibSegInfo[0].usedOrNot = USED;
                   pBcchSibInfo->mibInfo.mibSegInfo[0].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->mibInfo.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->mibInfo.mibSegInfo[0].mibSegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->mibInfo.totalNumSeg == pBcchSibInfo->mibInfo.currentSeg)
               {
                   WnmUmtsCombineAndDecodeMib (pBcchSibInfo);
               }

               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               pBcchSibInfo->sib1Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
               if (NOT_USED == pBcchSibInfo->sib1Info.sib1SegInfo[0].usedOrNot)
               {
                   pBcchSibInfo->sib1Info.sib1SegInfo[0].usedOrNot = USED;
                   pBcchSibInfo->sib1Info.sib1SegInfo[0].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib1Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib1Info.sib1SegInfo[0].sib1SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib1Info.totalNumSeg == pBcchSibInfo->sib1Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib1 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE3:
               pBcchSibInfo->sib3Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
               if (NOT_USED == pBcchSibInfo->sib3Info.sib3SegInfo[0].usedOrNot)
               {
                   pBcchSibInfo->sib3Info.sib3SegInfo[0].usedOrNot = USED;
                   pBcchSibInfo->sib3Info.sib3SegInfo[0].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib3Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib3Info.sib3SegInfo[0].sib3SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib3Info.totalNumSeg == pBcchSibInfo->sib3Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib3 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE11:
               pBcchSibInfo->sib11Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
               if (NOT_USED == pBcchSibInfo->sib11Info.sib11SegInfo[0].usedOrNot)
               {
                   pBcchSibInfo->sib11Info.sib11SegInfo[0].usedOrNot = USED;
                   pBcchSibInfo->sib11Info.sib11SegInfo[0].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib11Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib11Info.sib11SegInfo[0].sib11SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib11Info.totalNumSeg == pBcchSibInfo->sib11Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib11 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE12:
               pBcchSibInfo->sib12Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
               if (NOT_USED == pBcchSibInfo->sib12Info.sib12SegInfo[0].usedOrNot)
               {
                   pBcchSibInfo->sib12Info.sib12SegInfo[0].usedOrNot = USED;
                   pBcchSibInfo->sib12Info.sib12SegInfo[0].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib12Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib12Info.sib12SegInfo[0].sib12SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib12Info.totalNumSeg == pBcchSibInfo->sib12Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib12 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE19:
               pBcchSibInfo->sib19Info.totalNumSeg =
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
               if (NOT_USED == pBcchSibInfo->sib19Info.sib19SegInfo[0].usedOrNot)
               {
                   pBcchSibInfo->sib19Info.sib19SegInfo[0].usedOrNot = USED;
                   pBcchSibInfo->sib19Info.sib19SegInfo[0].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength; //222;
                   pBcchSibInfo->sib19Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib19Info.sib19SegInfo[0].sib19SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib19Info.totalNumSeg == pBcchSibInfo->sib19Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib19 (pBcchSibInfo);
               }

               break;

            default:
               break;
        }
    }
}

/*
 * Fill PLMN Info
 */
void fillPlmn (MultiPlmnData multiPlmnInfo , unsigned int sibMask)
{
    unsigned int idx1 = 0;
    unsigned int idx2 = 0;

    /* Fill number of Plmn */
    g3gListenModeSysInfo.numOfPlmn = multiPlmnInfo.numberOfPlmn;    
    g3gListenModeSysInfo.mibPlmnIdentity = multiPlmnInfo.mibPlmnIdentity;
//    g3gListenModeSysInfo.sibMask = sibMask;

    for (idx1 = 0; idx1 < g3gListenModeSysInfo.numOfPlmn; idx1++)
    {
        /* Fill MCC */
        g3gListenModeSysInfo.plmn[idx1].mccLength = multiPlmnInfo.plmnList[idx1].mccLength;
        for (idx2 = 0; idx2 < multiPlmnInfo.plmnList[idx1].mccLength; idx2++)
        {
           g3gListenModeSysInfo.plmn[idx1].mcc[idx2] = multiPlmnInfo.plmnList[idx1].mcc[idx2];
        }

        /* Fill MNC */
        g3gListenModeSysInfo.plmn[idx1].mncLength = multiPlmnInfo.plmnList[idx1].mncLength;
        for (idx2 = 0; idx2 < multiPlmnInfo.plmnList[idx1].mncLength; idx2++)
        {
           g3gListenModeSysInfo.plmn[idx1].mnc[idx2] = multiPlmnInfo.plmnList[idx1].mnc[idx2];
        }
    }     
}

/*
 * Fill Cell Selection Reselection Info
 */
void fillCellSelResel (CellSelReselData cellSelReselInfo)
{
   g3gListenModeSysInfo.cellInfo[0].networkCellId = cellSelReselInfo.cellId;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.qQualMin =
                                       cellSelReselInfo.qQualMin;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.qRxLevMin =
                                       cellSelReselInfo.qRxLevMin;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.qHystLS =
                                       cellSelReselInfo.qHystLS;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.qHyst2S =
                                       cellSelReselInfo.qHyst2S;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.tReselS =
                                       cellSelReselInfo.tReselS;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.maxAllowedULTxPower =
                                     cellSelReselInfo.maxAllowedULTxPower;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.sIntraSearch =
                                     cellSelReselInfo.sIntraSearch;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.sInterSearch =
                                     cellSelReselInfo.sInterSearch;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.sSearchHCS =
                                     cellSelReselInfo.sSearchHCS;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.ratSearch =
                                     cellSelReselInfo.ratSearch;
   g3gListenModeSysInfo.cellInfo[0].cellSelReselInfo.sLimitSearchRAT =
                                     cellSelReselInfo.sLimitSearchRAT;
}

/*
 * Initialize Frequency Cell Information
 */
void initializeFreqCellInfo (SysInfoType11FreqCellList *pFreqCellInfo)
{
   unsigned int idx = 0;

   for (idx = 0; idx < FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST; idx++)
   {
      pFreqCellInfo->intraFreqCellInfo[idx].psc    = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->intraFreqCellInfo[idx].cellId = FXL_UMTS_VALUE_NOT_APPLICABLE;
   }

   for (idx = 0; idx < FXL_UMTS_MAX_INTER_FREQ_CELL_LIST; idx++)
   {
      pFreqCellInfo->interFreqCellInfo[idx].psc      = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interFreqCellInfo[idx].cellId   = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interFreqCellInfo[idx].dlUarfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interFreqCellInfo[idx].ulUarfcn = FXL_UMTS_VALUE_NOT_APPLICABLE;
   }

   for (idx = 0; idx < FXL_UMTS_MAX_INTER_RAT_CELL_LIST; idx++)
   {
      pFreqCellInfo->interRATCellInfo[idx].cellId    = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATCellInfo[idx].ncc       = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATCellInfo[idx].bcc       = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATCellInfo[idx].band      = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATCellInfo[idx].arfcn     = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATCellInfo[idx].qRxLevMin = FXL_UMTS_VALUE_NOT_APPLICABLE;
   }
#if 0
   for (idx = 0; idx < FXL_UMTS_MAX_INTER_RAT_LTE_CELL_LIST; idx++)
   {
      pFreqCellInfo->interRATLteCellInfo[idx].earfcn    = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLteCellInfo[idx].priority       = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLteCellInfo[idx].qRxLevMinEUTRA       = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLteCellInfo[idx].threshXhigh      = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLteCellInfo[idx].threshXlow    = FXL_UMTS_VALUE_NOT_APPLICABLE;
    }
#endif
}

/*
 * Fill Frequency Cell Information
 */
void fillFreqCellInfo (SysInfoType11FreqCellList freqCellInfo)
{
   unsigned int idx = 0;

   for (idx = 0; idx < FXL_UMTS_MAX_INTRA_FREQ_CELL_LIST; idx++)
   {
      g3gListenModeSysInfo.cellInfo[0].intraFreqCellList[idx].psc    = freqCellInfo.intraFreqCellInfo[idx].psc;
      g3gListenModeSysInfo.cellInfo[0].intraFreqCellList[idx].cellId = freqCellInfo.intraFreqCellInfo[idx].cellId;
   }

   for (idx = 0; idx < FXL_UMTS_MAX_INTER_FREQ_CELL_LIST; idx++)
   {
      g3gListenModeSysInfo.cellInfo[0].interFreqCellList[idx].psc      = freqCellInfo.interFreqCellInfo[idx].psc;
      g3gListenModeSysInfo.cellInfo[0].interFreqCellList[idx].cellId   = freqCellInfo.interFreqCellInfo[idx].cellId;
      g3gListenModeSysInfo.cellInfo[0].interFreqCellList[idx].dlUarfcn = freqCellInfo.interFreqCellInfo[idx].dlUarfcn;
      g3gListenModeSysInfo.cellInfo[0].interFreqCellList[idx].ulUarfcn = freqCellInfo.interFreqCellInfo[idx].ulUarfcn;
   }

   for (idx = 0; idx < FXL_UMTS_MAX_INTER_RAT_CELL_LIST; idx++)
   {
      g3gListenModeSysInfo.cellInfo[0].interRATCellList[idx].cellId    = freqCellInfo.interRATCellInfo[idx].cellId;
      g3gListenModeSysInfo.cellInfo[0].interRATCellList[idx].ncc       = freqCellInfo.interRATCellInfo[idx].ncc;
      g3gListenModeSysInfo.cellInfo[0].interRATCellList[idx].bcc       = freqCellInfo.interRATCellInfo[idx].bcc;
      g3gListenModeSysInfo.cellInfo[0].interRATCellList[idx].band      = freqCellInfo.interRATCellInfo[idx].band;
      g3gListenModeSysInfo.cellInfo[0].interRATCellList[idx].arfcn     = freqCellInfo.interRATCellInfo[idx].arfcn;
      g3gListenModeSysInfo.cellInfo[0].interRATCellList[idx].qRxLevMin = freqCellInfo.interRATCellInfo[idx].qRxLevMin;
   }
}

/* 
 * Initialize Priority Frequency Cell Information
 */

void initializePriorityFreqCellInfo(SysInfoType19FreqCellList *pFreqCellInfo)
{
   unsigned int idx = 0;

   pFreqCellInfo->servingCellPriority = FXL_UMTS_VALUE_NOT_APPLICABLE;
   pFreqCellInfo->s_PrioritySearch1 = FXL_UMTS_VALUE_NOT_APPLICABLE;
   pFreqCellInfo->s_PrioritySearch2 = FXL_UMTS_VALUE_NOT_APPLICABLE;
   pFreqCellInfo->threshServingLow = FXL_UMTS_VALUE_NOT_APPLICABLE;

   for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
   {
      pFreqCellInfo->fddPriorityCellInfo[idx].uarfcn        = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->fddPriorityCellInfo[idx].priority      = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->fddPriorityCellInfo[idx].threshXhigh   = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->fddPriorityCellInfo[idx].threshXlow    = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->fddPriorityCellInfo[idx].qQualMinFdd   = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->fddPriorityCellInfo[idx].qRxLevMinFdd  = FXL_UMTS_VALUE_NOT_APPLICABLE;
   }

   for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
   {
      pFreqCellInfo->interRATGsmPriorityCellInfo[idx].arfcn          = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATGsmPriorityCellInfo[idx].bandIndicator  = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATGsmPriorityCellInfo[idx].priority       = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATGsmPriorityCellInfo[idx].qRxLevMinGSM   = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATGsmPriorityCellInfo[idx].threshXhigh    = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATGsmPriorityCellInfo[idx].threshXlow     = FXL_UMTS_VALUE_NOT_APPLICABLE;
   }

   for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
   {
      pFreqCellInfo->interRATLtePriorityCellInfo[idx].earfcn         = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLtePriorityCellInfo[idx].priority       = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLtePriorityCellInfo[idx].qRxLevMinEUTRA = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLtePriorityCellInfo[idx].threshXhigh    = FXL_UMTS_VALUE_NOT_APPLICABLE;
      pFreqCellInfo->interRATLtePriorityCellInfo[idx].threshXlow     = FXL_UMTS_VALUE_NOT_APPLICABLE;
   }
}

void fillPriorityFreqCellInfo (SysInfoType19FreqCellList priorityFreqCellInfo)
{
   unsigned int idx = 0;

   g3gListenModeSysInfo.priorityCellInfo.servingCellPriority    = priorityFreqCellInfo.servingCellPriority;
   g3gListenModeSysInfo.priorityCellInfo.s_PrioritySearch1      = priorityFreqCellInfo.s_PrioritySearch1;
   g3gListenModeSysInfo.priorityCellInfo.s_PrioritySearch2      = priorityFreqCellInfo.s_PrioritySearch2;
   g3gListenModeSysInfo.priorityCellInfo.threshServingLow       = priorityFreqCellInfo.threshServingLow;

   for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
   {
      g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].uarfcn         = priorityFreqCellInfo.fddPriorityCellInfo[idx].uarfcn;
      g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].priority       = priorityFreqCellInfo.fddPriorityCellInfo[idx].priority;
      g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].threshXhigh    = priorityFreqCellInfo.fddPriorityCellInfo[idx].threshXhigh;
      g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].threshXlow     = priorityFreqCellInfo.fddPriorityCellInfo[idx].threshXlow;
      g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].qQualMinFdd    = priorityFreqCellInfo.fddPriorityCellInfo[idx].qQualMinFdd;
      g3gListenModeSysInfo.priorityCellInfo.fddPriorityCellInfo[idx].qRxLevMinFdd   = priorityFreqCellInfo.fddPriorityCellInfo[idx].qRxLevMinFdd;
   }

   for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
   {
     g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].arfcn           = priorityFreqCellInfo.interRATGsmPriorityCellInfo[idx].arfcn;
     g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].bandIndicator   = priorityFreqCellInfo.interRATGsmPriorityCellInfo[idx].bandIndicator;
     g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].priority        = priorityFreqCellInfo.interRATGsmPriorityCellInfo[idx].priority;
     g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].qRxLevMinGSM    = priorityFreqCellInfo.interRATGsmPriorityCellInfo[idx].qRxLevMinGSM;
     g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].threshXhigh     = priorityFreqCellInfo.interRATGsmPriorityCellInfo[idx].threshXhigh;
     g3gListenModeSysInfo.priorityCellInfo.gsmPriorityCellInfo[idx].threshXlow      = priorityFreqCellInfo.interRATGsmPriorityCellInfo[idx].threshXlow;
   }

   for (idx = 0; idx < MAX_LTE_CELL_LIST; idx++)
   {
     g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].earfcn          = priorityFreqCellInfo.interRATLtePriorityCellInfo[idx].earfcn;
     g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].priority        = priorityFreqCellInfo.interRATLtePriorityCellInfo[idx].priority;
     g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].qRxLevMinEUTRA  = priorityFreqCellInfo.interRATLtePriorityCellInfo[idx].qRxLevMinEUTRA;
     g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].threshXhigh     = priorityFreqCellInfo.interRATLtePriorityCellInfo[idx].threshXhigh;
     g3gListenModeSysInfo.priorityCellInfo.ltePriorityCellInfo[idx].threshXlow      = priorityFreqCellInfo.interRATLtePriorityCellInfo[idx].threshXlow;
   }
}

/*
 * Fill LAC, RAC and T3212 
 */ 

void fillSib1Info(Sib1Data sib1Info)
{
   g3gListenModeSysInfo.lac = (sib1Info.lac[0] << 8) | sib1Info.lac[1];
   g3gListenModeSysInfo.rac = sib1Info.rac;
   g3gListenModeSysInfo.t3212 = sib1Info.t3212;
   g3gListenModeSysInfo.nmo = sib1Info.nmo;
}

/*
 * Decode Complete SIB
 */
void WnmUmtsDecodeCompleteSib (BcchBchDecodeData_t *pBcchBchDecodedData,
                               BcchSibInfo_t       *pBcchSibInfo)
{
    int sibCount = 0;
    Sib1Data sib1Info;
    unsigned int sibMask = 0;
    memset((Sib1Data *)&sib1Info, 0, sizeof(Sib1Data));
    MultiPlmnData multiPlmnInfo;
    memset((MultiPlmnData *)&multiPlmnInfo, 0, sizeof(MultiPlmnData));
    CellSelReselData cellSelReselInfo;
    memset((CellSelReselData *)&cellSelReselInfo, 0, sizeof(CellSelReselData));
    SysInfoType11FreqCellList freqCellInfo;
    initializeFreqCellInfo (&freqCellInfo);
    SysInfoType19FreqCellList priorityFreqCellInfo;
    initializePriorityFreqCellInfo (&priorityFreqCellInfo);
   
    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               decodeASNMib (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &multiPlmnInfo , &sibMask);
               fillPlmn (multiPlmnInfo , sibMask);
               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               decodeASNSib1 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &sib1Info);
               fillSib1Info(sib1Info);
               break;

            case SYSTEM_INFORMATION_TYPE3:
               decodeASNSib3 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &cellSelReselInfo);
               fillCellSelResel (cellSelReselInfo);
               break;

            case SYSTEM_INFORMATION_TYPE11:
               decodeASNSib11 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
               fillFreqCellInfo (freqCellInfo);
               pBcchSibInfo->isSib11Present = 1; 
               break;

            case SYSTEM_INFORMATION_TYPE12:
               decodeASNSib12 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
               if (0 == pBcchSibInfo->isSib11Present)
               {
                  fillFreqCellInfo (freqCellInfo);
               }
               break;

            case SYSTEM_INFORMATION_TYPE19:
               decodeASNSib19 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &priorityFreqCellInfo);
               fillPriorityFreqCellInfo (priorityFreqCellInfo);
               break;

            default:
               break;
        }
    }
}

/*
 * Decode Subsequent Segment
 */
void WnmUmtsDecodeSubsequentSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                     BcchSibInfo_t       *pBcchSibInfo)
{
    int sibCount = 0;
    int sibIndex = 0;

    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->mibInfo.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].mibSegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->mibInfo.totalNumSeg == pBcchSibInfo->mibInfo.currentSeg)
               {
                   WnmUmtsCombineAndDecodeMib (pBcchSibInfo);
               }

               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib1Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].sib1SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib1Info.totalNumSeg == pBcchSibInfo->sib1Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib1 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE3:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib3Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].sib3SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib3Info.totalNumSeg == pBcchSibInfo->sib3Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib3 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE11:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib11Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].sib11SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib11Info.totalNumSeg == pBcchSibInfo->sib11Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib11 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE12:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib12Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].sib12SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib12Info.totalNumSeg == pBcchSibInfo->sib12Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib12 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE19:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength; //222;
                   pBcchSibInfo->sib19Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].sib19SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib19Info.totalNumSeg == pBcchSibInfo->sib19Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib19 (pBcchSibInfo);
               }

               break;

            default:
               break;
        }
    }
}

/*
 * Decode Last Segment/Last Segment Short
 */
void WnmUmtsDecodeLastSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                         BcchSibInfo_t       *pBcchSibInfo)               
{
    int sibCount = 0;
    int sibIndex = 0;

    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].bitLength = 
				   	                   pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->mibInfo.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].mibSegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->mibInfo.totalNumSeg == pBcchSibInfo->mibInfo.currentSeg)
               {
                   WnmUmtsCombineAndDecodeMib (pBcchSibInfo);
               }

               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].bitLength = 
				   	                         pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib1Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].sib1SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib1Info.totalNumSeg == pBcchSibInfo->sib1Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib1 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE3:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].bitLength = 
				   	                          pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib3Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].sib3SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib3Info.totalNumSeg == pBcchSibInfo->sib3Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib3 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE11:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].bitLength = 
				   	                          pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib11Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].sib11SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib11Info.totalNumSeg == pBcchSibInfo->sib11Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib11 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE12:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].bitLength = 
				   	                              pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib12Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].sib12SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib12Info.totalNumSeg == pBcchSibInfo->sib12Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib12 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE19:
               sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               if (NOT_USED == pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = 
				   	                          pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
/*
                   if(0 == complete)
                   {
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = 214;
                   }
                   else
                   {
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = 222;
                   }
*/
                   pBcchSibInfo->sib19Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].sib19SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib19Info.totalNumSeg == pBcchSibInfo->sib19Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib19 (pBcchSibInfo);
               }

               break;

            default:
               break;
        }
    }
}

/*
 * Decode Last And First Segment
 */
void WnmUmtsDecodeLastAndFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                       BcchSibInfo_t       *pBcchSibInfo)
{
    int sibCount = 0;
    int sibIndex = 0;

    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               /* Check for First Segment */
               if((0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   pBcchSibInfo->mibInfo.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;
               }
               else
               {
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               }

               if (NOT_USED == pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].bitLength = 
				   	                    pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->mibInfo.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].mibSegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->mibInfo.totalNumSeg == pBcchSibInfo->mibInfo.currentSeg)
               {
                   WnmUmtsCombineAndDecodeMib (pBcchSibInfo);
               }

               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               /* Check for First Segment */
               if((0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   pBcchSibInfo->sib1Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;
               }
               else
               {
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               }

               if (NOT_USED == pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].bitLength = 
				   	                         pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib1Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].sib1SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib1Info.totalNumSeg == pBcchSibInfo->sib1Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib1 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE3:
               /* Check for First Segment */
               if((0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   pBcchSibInfo->sib3Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;
               }
               else
               {
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               }

               if (NOT_USED == pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].bitLength = 
				   	                             pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib3Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].sib3SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib3Info.totalNumSeg == pBcchSibInfo->sib3Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib3 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE11:
               /* Check for First Segment */
               if((0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   pBcchSibInfo->sib11Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;
               }
               else
               {
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               }

               if (NOT_USED == pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].bitLength = 
				   	                                  pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib11Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].sib11SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib11Info.totalNumSeg == pBcchSibInfo->sib11Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib11 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE12:
               /* Check for First Segment */
               if((0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   pBcchSibInfo->sib12Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;
               }
               else
               {
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               }

               if (NOT_USED == pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].bitLength = 
				   	                             pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                   pBcchSibInfo->sib12Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].sib12SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib12Info.totalNumSeg == pBcchSibInfo->sib12Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib12 (pBcchSibInfo);
               }

               break;

            case SYSTEM_INFORMATION_TYPE19:
               /* Check for First Segment */
               if((0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   pBcchSibInfo->sib19Info.totalNumSeg =
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;
               }
               else
               {
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
               }

               if (NOT_USED == pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot)
               {
                   pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot = USED;
                   pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength; //214;
                   pBcchSibInfo->sib19Info.currentSeg++;
                   memcpy((unsigned char *)pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].sib19SegData,
                          (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
               }

               if (pBcchSibInfo->sib19Info.totalNumSeg == pBcchSibInfo->sib19Info.currentSeg)
               {
                   WnmUmtsCombineAndDecodeSib19 (pBcchSibInfo);
               }

               break;

            default:
               break;
        }
    }
}

/*
 * Decode Last And Complete Segment
 */
void WnmUmtsDecodeLastAndCompleteSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                          BcchSibInfo_t       *pBcchSibInfo)
{
    int sibCount = 0;
    int sibIndex = 0;
    unsigned int sibMask = 0;
    //unsigned char lac[MAX_LAC_LENGTH] = {0};
    Sib1Data sibData ;
    MultiPlmnData multiPlmnInfo;
    memset((MultiPlmnData *)&multiPlmnInfo, 0, sizeof(MultiPlmnData));
    CellSelReselData cellSelReselInfo;
    memset((CellSelReselData *)&cellSelReselInfo, 0, sizeof(CellSelReselData));
    SysInfoType11FreqCellList freqCellInfo;
    initializeFreqCellInfo (&freqCellInfo);
    memset(&sibData , 0 , sizeof(Sib1Data));
    SysInfoType19FreqCellList priorityFreqCellInfo;
    initializePriorityFreqCellInfo (&priorityFreqCellInfo);

    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNMib (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &multiPlmnInfo , &sibMask);
                   fillPlmn (multiPlmnInfo , sibMask);
               }
               else
               {
                   /* Last Segment */
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;

                   if (NOT_USED == pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].bitLength =
					   	                     pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->mibInfo.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].mibSegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->mibInfo.totalNumSeg == pBcchSibInfo->mibInfo.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeMib (pBcchSibInfo);
                   }
               }

               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib1 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &sibData/*lac*/);
                   g3gListenModeSysInfo.lac = (sibData.lac[0] << 8) | sibData.lac[1];
                   g3gListenModeSysInfo.t3212 = sibData.t3212;
                   g3gListenModeSysInfo.rac = sibData.rac;
                   g3gListenModeSysInfo.nmo = sibData.nmo;
               }
               else
               {
                   /* Last Segment */
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;

                   if (NOT_USED == pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].bitLength = 
					   	                        pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib1Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].sib1SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib1Info.totalNumSeg == pBcchSibInfo->sib1Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib1 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE3:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib3 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &cellSelReselInfo);
                   fillCellSelResel (cellSelReselInfo);
               }
               else
               {
                   /* Last Segment */
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;

                   if (NOT_USED == pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].bitLength = 
					   	                         pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib3Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].sib3SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib3Info.totalNumSeg == pBcchSibInfo->sib3Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib3 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE11:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib11 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
                   fillFreqCellInfo (freqCellInfo);
                   pBcchSibInfo->isSib11Present = 1;
               }
               else
               {
                   /* Last Segment */
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;

                   if (NOT_USED == pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].bitLength = 
					   	                          pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib11Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].sib11SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib11Info.totalNumSeg == pBcchSibInfo->sib11Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib11 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE12:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib12 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
                   if (0 == pBcchSibInfo->isSib11Present)
                   {
                       fillFreqCellInfo (freqCellInfo);
                   }
               }
               else
               {
                   /* Last Segment */
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;

                   if (NOT_USED == pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].bitLength = 
					   	                          pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib12Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].sib12SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib12Info.totalNumSeg == pBcchSibInfo->sib12Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib12 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE19:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib19 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &priorityFreqCellInfo);
                   fillPriorityFreqCellInfo (priorityFreqCellInfo);
               }
               else
               {
                   /* Last Segment */
                   sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;

                   if (NOT_USED == pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength; //214;
                       pBcchSibInfo->sib19Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].sib19SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib19Info.totalNumSeg == pBcchSibInfo->sib19Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib19 (pBcchSibInfo);
                   }
               }

               break;

            default:
               break;
        }
    }
}

/*
 * Decode Last And Complete And First Segment
 */
void WnmUmtsDecodeLastAndCompleteAndFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                                  BcchSibInfo_t       *pBcchSibInfo)
{
    int sibCount = 0;
    int sibIndex = 0;
    unsigned int sibMask = 0;
   // unsigned char lac[MAX_LAC_LENGTH] = {0};
    Sib1Data sibData ;
    MultiPlmnData multiPlmnInfo;
    memset((MultiPlmnData *)&multiPlmnInfo, 0, sizeof(MultiPlmnData));
    CellSelReselData cellSelReselInfo;
    memset((CellSelReselData *)&cellSelReselInfo, 0, sizeof(CellSelReselData));
    SysInfoType11FreqCellList freqCellInfo;
    initializeFreqCellInfo (&freqCellInfo);
    memset(&sibData , 0 , sizeof(Sib1Data));
    SysInfoType19FreqCellList priorityFreqCellInfo;
    initializePriorityFreqCellInfo (&priorityFreqCellInfo);

    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNMib (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &multiPlmnInfo , &sibMask);
                   fillPlmn (multiPlmnInfo , sibMask);
               }
               else
               {
                   if ((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                       (0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
                   {
                       /* Last Segment */
                       sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
                   }
                   else
                   {
                       /* First Segment */
                       pBcchSibInfo->mibInfo.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                       sibIndex = 0;
                   }

                   if (NOT_USED == pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->mibInfo.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].mibSegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->mibInfo.totalNumSeg == pBcchSibInfo->mibInfo.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeMib (pBcchSibInfo);
                   }
               }

               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib1 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &sibData /*lac*/);
                   //g3gListenModeSysInfo.lac = (lac[0] << 8) | lac[1];
                   g3gListenModeSysInfo.lac = (sibData.lac[0] << 8) | sibData.lac[1];
                   g3gListenModeSysInfo.t3212 = sibData.t3212;
                   g3gListenModeSysInfo.rac = sibData.rac;
                   g3gListenModeSysInfo.nmo = sibData.nmo;
               }
               else
               {
                   if ((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                       (0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
                   {
                       /* Last Segment */
                       sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
                   }
                   else
                   {
                       /* First Segment */
                       pBcchSibInfo->sib1Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                       sibIndex = 0;
                   }


                   if (NOT_USED == pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib1Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].sib1SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib1Info.totalNumSeg == pBcchSibInfo->sib1Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib1 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE3:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib3 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &cellSelReselInfo);
                   fillCellSelResel (cellSelReselInfo);
               }
               else
               {
                   if ((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                       (0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
                   {
                       /* Last Segment */
                       sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
                   }
                   else
                   {
                       /* First Segment */
                       pBcchSibInfo->sib3Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                       sibIndex = 0;
                   }

                   if (NOT_USED == pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib3Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].sib3SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib3Info.totalNumSeg == pBcchSibInfo->sib3Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib3 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE11:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib11 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
                   fillFreqCellInfo (freqCellInfo);
                   pBcchSibInfo->isSib11Present = 1;
               }
               else
               {
                   if ((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                       (0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
                   {
                       /* Last Segment */
                       sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
                   }
                   else
                   {
                       /* First Segment */
                       pBcchSibInfo->sib11Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                       sibIndex = 0;
                   }

                   if (NOT_USED == pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib11Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].sib11SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib11Info.totalNumSeg == pBcchSibInfo->sib11Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib11 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE12:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib12 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
                   if(0 == pBcchSibInfo->isSib11Present)
                   {
                       fillFreqCellInfo (freqCellInfo);
                   }
               }
               else
               {
                   if ((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                       (0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
                   {
                       /* Last Segment */
                       sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
                   }
                   else
                   {
                       /* First Segment */
                       pBcchSibInfo->sib12Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                       sibIndex = 0;
                   }

                   if (NOT_USED == pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib12Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].sib12SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib12Info.totalNumSeg == pBcchSibInfo->sib12Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib12 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE19:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib19 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &priorityFreqCellInfo);
                   fillPriorityFreqCellInfo (priorityFreqCellInfo);
               }
               else
               {
                   if ((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                       (0 != pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
                   {
                       /* Last Segment */
                       sibIndex = pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex;
                   }
                   else
                   {
                       /* First Segment */
                       pBcchSibInfo->sib19Info.totalNumSeg =
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                       sibIndex = 0;
                   }

                   if (NOT_USED == pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength; //214;
                       pBcchSibInfo->sib19Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].sib19SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib19Info.totalNumSeg == pBcchSibInfo->sib19Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib19 (pBcchSibInfo);
                   }
               }

               break;

            default:
               break;
        }
    }
}

/*
 * Decode Complete And First Segment
 */
void WnmUmtsDecodeCompleteAndFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                           BcchSibInfo_t       *pBcchSibInfo)
{
    int sibCount = 0;
    int sibIndex = 0;
    unsigned int sibMask = 0;
    //unsigned char lac[MAX_LAC_LENGTH] = {0};
    Sib1Data sibData ;
    MultiPlmnData multiPlmnInfo;
    memset((MultiPlmnData *)&multiPlmnInfo, 0, sizeof(MultiPlmnData));
    CellSelReselData cellSelReselInfo;
    memset((CellSelReselData *)&cellSelReselInfo, 0, sizeof(CellSelReselData));
    SysInfoType11FreqCellList freqCellInfo;
    initializeFreqCellInfo (&freqCellInfo);
    memset(&sibData , 0 , sizeof(Sib1Data));
    SysInfoType19FreqCellList priorityFreqCellInfo;
    initializePriorityFreqCellInfo (&priorityFreqCellInfo);

    for(sibCount = 0; sibCount < pBcchBchDecodedData->numOfSib; sibCount++)
    {
        switch (pBcchBchDecodedData->sibPayload[sibCount].sibType)
        {
            case MASTER_INFORMATION_BLOCK:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNMib (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &multiPlmnInfo , &sibMask);
                   fillPlmn (multiPlmnInfo , sibMask);
               }
               else
               {
                   /* First Segment */
                   pBcchSibInfo->mibInfo.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;

                   if (NOT_USED == pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->mibInfo.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->mibInfo.mibSegInfo[sibIndex].mibSegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->mibInfo.totalNumSeg == pBcchSibInfo->mibInfo.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeMib (pBcchSibInfo);
                   }
               }

               break;
 
            case SYSTEM_INFORMATION_TYPE1:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib1 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &sibData /*lac*/);
                   //g3gListenModeSysInfo.lac = (lac[0] << 8) | lac[1];
                   g3gListenModeSysInfo.lac = (sibData.lac[0] << 8) | sibData.lac[1];
                   g3gListenModeSysInfo.t3212 = sibData.t3212;
                   g3gListenModeSysInfo.rac = sibData.rac;
                   g3gListenModeSysInfo.nmo = sibData.nmo;

               }
               else
               {
                   /* First Segment */
                   pBcchSibInfo->sib1Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;

                   if (NOT_USED == pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib1Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib1Info.sib1SegInfo[sibIndex].sib1SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib1Info.totalNumSeg == pBcchSibInfo->sib1Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib1 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE3:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib3 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &cellSelReselInfo);
                   fillCellSelResel (cellSelReselInfo);
               }
               else
               {
                   /* First Segment */
                   pBcchSibInfo->sib3Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;

                   if (NOT_USED == pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib3Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib3Info.sib3SegInfo[sibIndex].sib3SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib3Info.totalNumSeg == pBcchSibInfo->sib3Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib3 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE11:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib11 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
                   fillFreqCellInfo (freqCellInfo);
                   pBcchSibInfo->isSib11Present = 1;
               }
               else
               {
                   /* First Segment */
                   pBcchSibInfo->sib11Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;

                   if (NOT_USED == pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib11Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib11Info.sib11SegInfo[sibIndex].sib11SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib11Info.totalNumSeg == pBcchSibInfo->sib11Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib11 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE12:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib12 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &freqCellInfo);
                   if (0 == pBcchSibInfo->isSib11Present)
                   {
                      fillFreqCellInfo (freqCellInfo);
                   }
               }
               else
               {
                   /* First Segment */
                   pBcchSibInfo->sib12Info.totalNumSeg = 
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;

                   if (NOT_USED == pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength;
                       pBcchSibInfo->sib12Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib12Info.sib12SegInfo[sibIndex].sib12SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib12Info.totalNumSeg == pBcchSibInfo->sib12Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib12 (pBcchSibInfo);
                   }
               }

               break;

            case SYSTEM_INFORMATION_TYPE19:
               /* Check for Complete Segment */
               if((0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegCount) &&
                  (0 == pBcchBchDecodedData->sibPayload[sibCount].sibSegIndex))
               {
                   decodeASNSib19 (pBcchBchDecodedData->sibPayload[sibCount].sibData, 32, &priorityFreqCellInfo);
                   fillPriorityFreqCellInfo (priorityFreqCellInfo);
               }
               else
               {
                   /* First Segment */
                   pBcchSibInfo->sib19Info.totalNumSeg =
                             pBcchBchDecodedData->sibPayload[sibCount].sibSegCount;
                   sibIndex = 0;

                   if (NOT_USED == pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot)
                   {
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].usedOrNot = USED;
                       pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].bitLength = pBcchBchDecodedData->sibPayload[sibCount].payloadBitLength; //214;
                       pBcchSibInfo->sib19Info.currentSeg++;
                       memcpy((unsigned char *)pBcchSibInfo->sib19Info.sib19SegInfo[sibIndex].sib19SegData,
                              (unsigned char *)pBcchBchDecodedData->sibPayload[sibCount].sibData, 32);
                   }

                   if (pBcchSibInfo->sib19Info.totalNumSeg == pBcchSibInfo->sib19Info.currentSeg)
                   {
                       WnmUmtsCombineAndDecodeSib19 (pBcchSibInfo);
                   }
               }

               break;

            default:
               break;
        }
    }
}

/*
 * BCCH Decode Function
 */
void WnmUmtsBCCHBufferDecode (tOCT_INT8 *pPayload, BcchSibInfo_t *pBcchSibInfo)
{
    int sibCount = 0;
    unsigned char bcchData[32] = {0};
    BcchBchDecodeData_t bcchDecodedData;
    
    memset((BcchBchDecodeData_t *)&bcchDecodedData, 0, sizeof(BcchBchDecodeData_t));

    memcpy ((unsigned char *)bcchData, (tOCT_INT8 *)pPayload, 32);

    /* Decode BCCH Message */
    decodeASNBcchBchMessage (bcchData, 32, &bcchDecodedData);

    DEBUGMSG(("\n---------------------- BCCH DECODE START ----------------------\n"));
    DEBUGMSG(("SFN\t\t\t:\t%ld\n", bcchDecodedData.sfn));
    DEBUGMSG(("DECODED DATA LENGTH\t:\t%ld\n", bcchDecodedData.decodedDataLen));
    DEBUGMSG(("SIB SEGMENT TYPE\t:\t%ld\n", bcchDecodedData.sibSegmentType));
    DEBUGMSG(("NUMBER OF SIB\t\t:\t%ld\n", bcchDecodedData.numOfSib));
    for(sibCount = 0; sibCount < bcchDecodedData.numOfSib; sibCount++)
    {
        DEBUGMSG(("SIB TYPE\t\t:\t%ld\n", bcchDecodedData.sibPayload[sibCount].sibType));
        DEBUGMSG(("SIB SEGMENT COUNT\t:\t%ld\n", bcchDecodedData.sibPayload[sibCount].sibSegCount));
        DEBUGMSG(("SIB SEGMENT INDEX\t:\t%ld\n", bcchDecodedData.sibPayload[sibCount].sibSegIndex));
		DEBUGMSG(("SIB PAYLOAD BIT LENGTH\t:\t%ld\n", bcchDecodedData.sibPayload[sibCount].payloadBitLength));
    } 
    DEBUGMSG(("----------------------  BCCH DECODE END  ----------------------\n"));

    switch(bcchDecodedData.sibSegmentType)
    {
        case BCH_PAYLOAD_COMPLETE_SIB_LIST:
        case BCH_PAYLOAD_COMPLETE_SIB:
           WnmUmtsDecodeCompleteSib (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_FIRST_SEGMENT:
           WnmUmtsDecodeFirstSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_SUBSEQUENT_SEGMENT:
           WnmUmtsDecodeSubsequentSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_LAST_SEGMENT_SHORT:
           WnmUmtsDecodeLastSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_LAST_SEGMENT:
           WnmUmtsDecodeLastSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_LAST_AND_FIRST:
           WnmUmtsDecodeLastAndFirstSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_LAST_AND_COMPLETE:
           WnmUmtsDecodeLastAndCompleteSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_LAST_AND_COMPLETE_AND_FIRST:
           WnmUmtsDecodeLastAndCompleteAndFirstSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_COMPLETE_AND_FIRST:
           WnmUmtsDecodeCompleteAndFirstSegment (&bcchDecodedData, pBcchSibInfo);
           break;

        case BCH_PAYLOAD_NO_SEGMENT:
        default:
           break;
    }

}
