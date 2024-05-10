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
 * File Name   : wnm.h 
 *
 * Description : This file provides decoding functionality for WNM.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 12/10/2014	        Ashutosh Samal              File Creation
 *############################################################################
*/

#ifndef __WNM_H__
#define __WNM_H__

#include "octdev_types.h"
#include "fxLSocketInterfaceApi.h"

#define NOT_USED   0
#define USED       1

/*
 * MIB Segment Info
 */
typedef struct mibSegInfo
{
   int           usedOrNot; 
   int           bitLength;
   unsigned char mibSegData[32];
}MibSegInfo_t;

/*
 * MIB Info
 */
typedef struct mibInfo
{
   int            totalNumSeg;
   int            currentSeg;
   /* Currently supporting MIB 10 Segments */
   MibSegInfo_t  mibSegInfo[10]; 
}MibInfo_t;

/*
 * SIB1 Segment Info
 */
typedef struct sib1SegInfo
{
   int           usedOrNot; 
   int           bitLength;
   unsigned char sib1SegData[32];
}Sib1SegInfo_t;

/*
 * SIB1 Info
 */
typedef struct sib1Info
{
   int             totalNumSeg;
   int             currentSeg;
   /* Currently supporting SIB1 10 Segments */
   Sib1SegInfo_t  sib1SegInfo[10]; 
}Sib1Info_t;

/*
 * SIB3 Segment Info
 */
typedef struct sib3SegInfo
{
   int           usedOrNot; 
   int           bitLength;
   unsigned char sib3SegData[32];
}Sib3SegInfo_t;

/*
 * SIB3 Info
 */
typedef struct sib3Info
{
   int             totalNumSeg;
   int             currentSeg;
   /* Currently supporting SIB3 20 Segments */
   Sib3SegInfo_t  sib3SegInfo[20]; 
}Sib3Info_t;

/*
 * SIB11 Segment Info
 */
typedef struct sib11SegInfo
{
   int           usedOrNot; 
   int           bitLength;
   unsigned char sib11SegData[32];
}Sib11SegInfo_t;

/*
 * SIB11 Info
 */
typedef struct sib11Info
{
   int             totalNumSeg;
   int             currentSeg;
   /* Currently supporting SIB11 30 Segments */
   Sib11SegInfo_t  sib11SegInfo[30]; 
}Sib11Info_t;

/*
 * SIB12 Segment Info
 */
typedef struct sib12SegInfo
{
   int           usedOrNot; 
   int           bitLength;
   unsigned char sib12SegData[32];
}Sib12SegInfo_t;

/*
 * SIB12 Info
 */
typedef struct sib12Info
{
   int             totalNumSeg;
   int             currentSeg;
   /* Currently supporting SIB12 30 Segments */
   Sib12SegInfo_t  sib12SegInfo[30]; 
}Sib12Info_t;

/*
 * SIB19 Segment Info
 */
typedef struct sib19SegInfo
{
   int           usedOrNot;
   int           bitLength;
   unsigned char sib19SegData[32];
}Sib19SegInfo_t;

/*
 * SIB19 Info
 */
typedef struct sib19Info
{
   int             totalNumSeg;
   int             currentSeg;
   /* Currently supporting SIB19 30 Segments */
   Sib19SegInfo_t  sib19SegInfo[30];
}Sib19Info_t;
/*
 * BCCH SIB Data
 */
typedef struct bcchSibInfo
{
   MibInfo_t    mibInfo;
   Sib1Info_t   sib1Info;
   Sib3Info_t   sib3Info;
   Sib11Info_t  sib11Info;
   unsigned int isSib11Present;
   Sib12Info_t  sib12Info;
   Sib19Info_t  sib19Info;
}BcchSibInfo_t;

/*
 * Auto Config Scan Result
 */

typedef struct
{
   int uarfcn;
   int priority;
}priority3GCellInfo;

typedef struct autoCfgScanResult
{
   unsigned int              numOfPlmn;
   unsigned char             mibPlmnIdentity;
   PlmnData                  plmn[6];
   int                       psc;
   int                       dlUarfcn;
   fxL3gBandType             band;
   float                     rscp;
   int                       intraFreqPsc[32];
   int                       interFreqPsc[32];
   int                       qQualMin;
   int                       qRxLevMin;
   int                       qHystLS;
   int                       qHyst2S;
   int                       tReselS;
   int                       maxAllowedULTxPower;
   unsigned int              t3212;
   unsigned int              nmo;
   int                       servingCellPriority;
   priority3GCellInfo        fddPriorityCellInfo[8];   
   struct autoCfgScanResult *next;
}AutoCfgScanResult_t;

/*
 * Function Prototypes
 */
extern void WnmUmtsSetBit (unsigned char *pData, int byteIndex, 
                    int bitPosition, int bitValue);
extern void WnmUmtsCombineAllSegment (unsigned char *pCompleteData,
                               unsigned char *pSegmentedData,
                               int           *pTotalBitLength,
                               int           *pBitOffset,
                               int           *pByteOffset,
                               int            bitToCopy);
extern void WnmUmtsCombineAndDecodeMib (BcchSibInfo_t *pBcchSibInfo);
extern void WnmUmtsCombineAndDecodeSib1 (BcchSibInfo_t *pBcchSibInfo);
extern void WnmUmtsCombineAndDecodeSib3 (BcchSibInfo_t *pBcchSibInfo);
extern void WnmUmtsCombineAndDecodeSib11 (BcchSibInfo_t *pBcchSibInfo);
extern void WnmUmtsCombineAndDecodeSib12 (BcchSibInfo_t *pBcchSibInfo);
extern void WnmUmtsDecodeFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsDecodeCompleteSib (BcchBchDecodeData_t *pBcchBchDecodedData,
                                      BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsDecodeSubsequentSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                     BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsDecodeLastSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                                BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsDecodeLastAndFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                       BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsDecodeLastAndCompleteSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                          BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsDecodeLastAndCompleteAndFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                                  BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsDecodeCompleteAndFirstSegment (BcchBchDecodeData_t *pBcchBchDecodedData,
                                                  BcchSibInfo_t       *pBcchSibInfo);
extern void WnmUmtsBCCHBufferDecode (tOCT_INT8 *pPayload, BcchSibInfo_t *pBcchSibInfo);

extern void umtsListenMode();
extern void delAllAutoCfgScanResult (void);
extern void addAutoCfgScanResult (void);
extern void WnmUmtsCombineAndDecodeSib19 (BcchSibInfo_t *pBcchSibInfo);
#endif
