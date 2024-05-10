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
* File Name   : gsmCommon.h
 *
* Description : common gsm header
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/09/2014          Shivashankar V     File Creation
*############################################################################
*/

#ifndef _GSM_COMMON_H_
#define _GSM_COMMON_H_

#include <assert.h>
#include "feaConfig.h"
#include "../../../sls/inc/octdev_types.h"
#include "../../../sls/inc/fxLSocketInterfaceApi.h"

#define MAXLEN 20

#define MAX_NO_OF_IDS 500

#define MAX_IDENTITY_LENGTH_STR 16
#define CONFIG_DATA_SIZE 4

#define RR_BCCH_SI_L2_HDR_OFFSET            0
#define RR_SACCH_SI_L2_HDR_OFFSET           2
#define RR_SACCH_SI_STANDARD_HDR_LEN        7
#define RR_SACCH_SI_SHORT_L2_HDR_LEN        3
#define RR_BCCH_SI_HDR_LEN                  3
#define RR_PROTOCOL_DISCRIMINATOR           0x06
#define RR_SI1_MSG_TYPE                     0x0019
#define RR_SI2_MSG_TYPE                     0x001A
#define RR_SI2BIS_MSG_TYPE                  0x0002
#define RR_SI2TER_MSG_TYPE                  0x0003
#define RR_SI2QUATER_MSG_TYPE               0x0007
#define RR_SI2N_MSG_TYPE                    0x0045
#define RR_SI3_MSG_TYPE                     0x001B
#define RR_SI4_MSG_TYPE                     0x001C

#define RR_SI1_MASK                         0x0001
#define RR_SI2_MASK                         0x0002
#define RR_SI2BIS_MASK                      0x0004
#define RR_SI2TER_MASK                      0x0008
#define RR_SI2QUATER_MASK                   0x0010
#define RR_SI3_MASK                         0x0020
#define RR_SI4_MASK                         0x0040

#define SIZE_OF_HOPPING_LIST                64 
#define RR_CELL_CHANNEL_DESCR_LEN           16
#define RR_NEIGHBOUR_CELLS_DESCR_LEN        16
#define FREQLIST_DECODING_OK                1
#define FREQLIST_FORMAT_ID_UNKNOWN  	    3
#define BIT_MAP_0_MASK                      0xC0       /* 1100 0000 */
#define RANGE_1024_MASK                     0xC8       /* 1100 1000 */
#define FORMAT_ID_MASK_1                    0x8E       /* 1000 1110 */
#define FORMAT_ID_MASK_2                    0xCE       /* 1100 1110 */
#define F0_MASK                             0x04       /* 0000 0100 */
#define BIT_MAP_0                           0x00       /* 00xx xxxx -> 0000 0000 */
#define RANGE_1024                          0x80       /* 10xx 0xxx -> 1000 0000 */
#define RANGE_512                           0x88       /* 10xx 100x -> 1000 1000 */
#define RANGE_256                           0x8A       /* 10xx 101x -> 1000 1010 */
#define RANGE_128                           0x8C       /* 10xx 110x -> 1000 1100 */
#define VAR_BIT_MAP                         0x8E       /* 10xx 111x -> 1000 1110 */
#define ORIG_RANGE_1024                     1023
#define ORIG_RANGE_512                      511
#define ORIG_RANGE_256                      255
#define ORIG_RANGE_128                      127
#define ORIG_RANGE_INVALID                  -1
#define MAX_RANGE_ENCODING_ARFCNS	        29
#define END_OF_LIST                         0xFFFF  /* for freq. list, used locally and not if */
#define GERAN_ARFCN_LIST_LENGTH             32
#define SIZE_OF_HOPPING_LIST                64 
#define END_OF_HOPPING_LIST                 0xFFFF
#define MAX_NO_OF_FDD_CELL_INFO_PARAMS      17
#define RR_RACH_CTRL_PARAMS_LEN             3
#define RR_SI_PADDING                       0x2b
#define RR_BCCH_SI_DATA_LEN                 20
#define RR_SI2_FREQ_LIST_IE_OFFSET          0
#define RR_SI2_NCC_PERMITTED_IE_OFFSET      16
#define LENGTH_OF_CELL_IDENTITY             2
#define RR_SI3_DATA_LEN                     20
#define CBCH_MOBILE_ALLOCATION_LENGTH       4
#define RR_SI4_DATA_LEN                     20
#define RR_IEI_CELL_CHANNEL_DESCR           0x64
#define RR_IEI_MOBILE_ALLOCATION            0x72
#define SI_FDD_CELL_INFO_FIELD_LENGTH       16
#define MAX_NBR_OF_RTD                      3
#define SI_NCELL_LIST_SIZE                  96
#define SI_NCELL_LIST_BITMAP_SIZE           (SI_NCELL_LIST_SIZE / 8)
#define UNSUPPORTED_NEIGHBOUR_ARFCN         0xFFFE

// Type definitions
//typedef unsigned char       tOCT_UINT8;
//typedef unsigned short      tOCT_UINT16;
//typedef unsigned int        tOCT_UINT32;
//typedef signed char         sint8;
//typedef signed short        sint16;
//typedef signed int          sint32;
//typedef long long           sint64;
//typedef unsigned long long  tOCT_UINT64;

typedef tOCT_UINT32  T_CARRIER_NUMBER;

#define TRUE 1
#define FALSE 0

#define latconst1 0x00800000
#define latconst2 90
#define lonconst1 0x01000000
#define lonconst2 360

/*
 * Type of Configuration
 */
typedef enum
{
    WHITELIST = 0,
    BLACKLIST
} CONFIG_TYPE;

/*
 * Identity Type
 */
typedef enum
{
    IMSI = 0,
    IMEI
} IDENTITY_TYPE;

struct parameters
{
  int  MCC;
  int  MNC;
  int  BAND;
  int  ARFCN;
  int  CI;
  int  LAC;
  int  TSC;
  int  BSIC;
  int  TRX;
  char TRX0_TS0[MAXLEN];
  char TRX0_TS1[MAXLEN];
  char TRX0_TS2[MAXLEN];
  char TRX0_TS3[MAXLEN];
  char TRX0_TS4[MAXLEN];
  char TRX0_TS5[MAXLEN];
  char TRX0_TS6[MAXLEN];
  char TRX0_TS7[MAXLEN];
  int  TYPE; // 0-PRI , 1-SEC
};

typedef struct s_geran_arfcn_list_str
{
    T_CARRIER_NUMBER arfcns[GERAN_ARFCN_LIST_LENGTH];
    tOCT_UINT8 nbr_of_arfcns;
} GERAN_ARFCN_LIST_STR;

typedef struct s_geran_hopping_list_str
{   
    T_CARRIER_NUMBER arfcns[SIZE_OF_HOPPING_LIST];
    tOCT_UINT8 nbr_of_arfcns;
} GERAN_HOPPING_LIST_STR;

typedef struct _IdentityConfig
{
    char        identity[SIZE_OF_IDENTITY_STR];
    tOCT_UINT8  idType;
    tOCT_UINT8  listType;
    tOCT_UINT8  rejectCauseIfWhitelist;
} IdentityConfigStr;

typedef struct _ConfigList
{
   tOCT_UINT8        defaultConfig;
   tOCT_UINT8        dummyPadding;
   tOCT_UINT16       numbOfIds;
   IdentityConfigStr *configId;
} ConfigList;
char * trim (char * s);
void  initializeConfigUeIdList(ConfigList * list);
void  bcd2str(tOCT_UINT8* bcd, char* str, tOCT_UINT8 isMsIsdn);
tOCT_UINT8 getImeiCheckDigit(char *imeiStr);
fxlUePositioningError decodeGpsParameters(tOCT_UINT8 * buf, fxlUePositioningInfo * gpsInfo);
tOCT_UINT16 gsmCommRand( tOCT_UINT16 lower, tOCT_UINT16 upper );
char * gsmL3PduHexdump(tOCT_UINT8 *l3Pdu, tOCT_UINT8 l3PduLen);
#endif  //#ifndef _GSM_COMMON_H_

