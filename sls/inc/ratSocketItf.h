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
* File Name   : ratSocketItf.h
 *
* Description : External Socket interface header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 25/11/2014          				  Anand Kashikar			   Initial File Creation
*############################################################################
*/


#ifndef EXTERNALINERFACEMANAGER_H_
#define EXTERNALINERFACEMANAGER_H_

//#include "l1Constants.h"
#include "fxLSocketInterfaceApi.h"

typedef struct
{
	int arfcn;
	int band;
	int ncc;
    int bcc;
	float rssi;
	float snr;
	int cellId;
}cellParams;

typedef struct autoConfigCfg
{
   unsigned int     autoConfig3g;
   fxLDspType       dspType;
   fxLL1ImageType   l1Image;
   unsigned int     dspResetNeeded;
}AutoConfigCfg;

typedef struct
{   
   int uarfcn;
   int priority;
}umtsPriorityCellInfo;

typedef struct scanCellInfo 
{
    unsigned int    uarfcn;
    float           rscp;
    fxL3gBandType   band;
    int             psc;
	int             qQualMin;
    int             qRxLevMin;
    int             qHystLS;
    int             qHyst2S;
    int             tReselS;
    int             maxAllowedULTxPower;
    unsigned int    t3212;
    unsigned int    nmo;
    unsigned int    neighbourIntraPsc[32]; 
    unsigned int    neighbourInterPsc[32]; 
    int             servingCellPriority;
    umtsPriorityCellInfo fddPriorityCellInfo[8];
}ScanCellInfo;

typedef struct plmnInfo
{
   unsigned int       mccLength;
   unsigned int       mncLength;
   unsigned int       mcc[3];
   unsigned int       mnc[3];
}PlmnInfo;

typedef struct operatorScanResult
{
   unsigned int       numOfPlmn;
   PlmnInfo           plmn[6];
   unsigned int       mibPlmnIdentity;
   unsigned int       numberOfCell;
   ScanCellInfo       *scanCellRslt[100];
}OperatorScanResult;

typedef struct scanResult
{
   unsigned int numOfValidOperator;
   OperatorScanResult *op[32];
}ScanResult;

typedef struct
{
   unsigned int uarfcn;
   fxL3gBandType band;
}umtsJammerParams;

#define EXTERNAL_MESSAGE_SIZE 1024*32
#define ASSIGN_NON_NEGATIVE(src, dst)          \
           if(src != 0xFFFF){                    \
              dst = src;                     \
           }                                 \

typedef struct
{
	int earfcn;
	int txAttnDb;
	int ulRxGainDb;
	int cellBandWidth;
	int f_enodebStartOrStop;
	int islteTDD;
	unsigned int relativeD;
}lteRfConfig;

typedef enum
{
 ONEBIN_STATE_IDLE = 0x3F,
 ONEBIN_STATE_2G_SCANNING = 0,
 ONEBIN_STATE_3G_SCANNING = 1,
 ONEBIN_STATE_4G_SCANNING = 2,
 ONEBIN_STATE_2G_IDCATCHING = 3,
 ONEBIN_STATE_3G_IDCATCHING = 4,
 ONEBIN_STATE_4G_IDCATCHING = 5,
 ONEBIN_STATE_3G_AUTOCONFIG = 6,
 ONEBIN_STATE_CDMA_SCANNING = 7,
 ONEBIN_STATE_2G_BASS       = 8,
}oneBinState;

tOCT_UINT8 createAndWaitSocketServerInterface(void);
void closeSocketServerInterface(void);
void externalSocketMsgHandler(void);
void writeToExternalSocketInterface(tOCT_UINT8* msgBuf , tOCT_UINT16 msgLen);
void createSharedMemoryStoringIdLists();
tOCT_UINT8 * getAccessToIdList();
void releaseAccessToIdList(tOCT_UINT8* sharedMemory );
void changeTxRxAntennaIdCmdHandler (tOCT_UINT8* inMsgBuf);

#endif
