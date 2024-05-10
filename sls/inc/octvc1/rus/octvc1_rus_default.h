/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_DEFAULT.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the event definition of the RUS API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RUS_DEFAULT_H__
#define __OCTVC1_RUS_DEFAULT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_rus_api.h"

/*****************************  COMMAND DEFAULT *****************************/

/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_OPEN_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_OPEN_CMD buf_tOCTVC1_RUS_MSG_RFFI_OPEN_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_OPEN_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_OPEN_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulPortIndex */
   cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulType */
   0, /* ulRxGainMode */
   { /* Umts */
       cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_1, /* ulBand */
       { /* Tx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK, /* eLinkType */
           10700, /* ulUarfcn */
           -15360  /* lGaindB */
       },
       { /* Rx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK, /* eLinkType */
           10701, /* ulUarfcn */
           0  /* ulGaindB */
       }
   },
   { /* Gsm */
       cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_E_900, /* ulBand */
       124, /* ulUarfcn */
       { /* Tx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK, /* eLinkType */
           -15360  /* lGaindB */
       },
       { /* Rx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK, /* eLinkType */
           0  /* ulGaindB */
       }
   },
   { /* Lte */
       cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_5MHZ, /* ulBwId */
       cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_1, /* ulBand */
       { /* Tx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK, /* eLinkType */
           300, /* ulUarfcn */
           -15360  /* lGaindB */
       },
       { /* Rx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_UPLINK, /* eLinkType */
           18300, /* ulUarfcn */
           0  /* ulGaindB */
       }
   },
   { /* Cdma2000 */
       cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_1, /* ulBand */
       0, /* ulRfcn */
       { /* Tx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK, /* eLinkType */
           -15360  /* lGaindB */
       },
       { /* Rx */
           cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK, /* eLinkType */
           0  /* ulGaindB */
       }
   },
   { /* RadioConfigFile */
       { /* szConfigFileName */
           0, /* szConfigFileName[0..127] */
       },
       0  /* ulSamplingRate */
   },
   { /* LoopBack */
       0, /* ulLoopbackEnableFlag */
       0  /* ulLoopbackDelayInSamples */
   },
   cOCTVC1_RUS_RFFI_ANTENNA_MODE_ENUM_1ANT  /* eAntennaMode */
};

const tOCTVC1_RUS_MSG_RFFI_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_OPEN_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_OPEN_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_OPEN_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_OPEN_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_OPEN_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD buf_tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_CLOSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_CLOSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_CLOSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_INFO_CMD buf_tOCTVC1_RUS_MSG_RFFI_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_STATS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_STATS_CMD buf_tOCTVC1_RUS_MSG_RFFI_STATS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_STATS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_STATS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_STATS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_STATS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_STATS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_STATS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_LIST_CMD buf_tOCTVC1_RUS_MSG_RFFI_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_RUS_MSG_RFFI_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_LIST_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD buf_tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CAPTURE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD buf_tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hRffi */
   30, /* ulCapturedRadioUnitLength */
   0, /* ulContinuousCaptureFlag */
   0, /* ulDurationType */
   0, /* ulDuration */
   { /* szFileNamePrefix */
       0, /* szFileNamePrefix[0..127] */
   }
};

const tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_START_CAPTURE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD buf_tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_UMTS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD buf_tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_UMTS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD buf_tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_INFO_GSM_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_GSM_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD buf_tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_STATS_GSM_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_GSM_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD buf_tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STOP_CAPTURE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD buf_tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_INFO_LTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_LTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD buf_tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_STATS_LTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_LTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD buf_tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_OPEN_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_OPEN_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_OPEN_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD buf_tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_CLOSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hPlayer */
};

const tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_CLOSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_INFO_CMD buf_tOCTVC1_RUS_MSG_PLAYER_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hPlayer */
};

const tOCTVC1_RUS_MSG_PLAYER_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_INFO_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_STATS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_STATS_CMD buf_tOCTVC1_RUS_MSG_PLAYER_STATS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_STATS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_STATS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hPlayer */
};

const tOCTVC1_RUS_MSG_PLAYER_STATS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_STATS_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_STATS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_STATS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_STATS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_STATS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_STATS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_LIST_CMD buf_tOCTVC1_RUS_MSG_PLAYER_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_RUS_MSG_PLAYER_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_LIST_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_START_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_START_CMD buf_tOCTVC1_RUS_MSG_PLAYER_START_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_START_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_START_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPlayer */
   0, /* ulActiveFileEntryId */
   cOCT_TRUE  /* ulRepeatForeverFlag */
};

const tOCTVC1_RUS_MSG_PLAYER_START_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_START_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_START_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_START_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_START_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_START_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_START_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_STOP_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_STOP_CMD buf_tOCTVC1_RUS_MSG_PLAYER_STOP_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_STOP_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_STOP_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hPlayer */
};

const tOCTVC1_RUS_MSG_PLAYER_STOP_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_STOP_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_STOP_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_STOP_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_STOP_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_STOP_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_STOP_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD buf_tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_MODIFY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPlayer */
   0  /* ulActiveFileEntryId */
};

const tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_MODIFY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD buf_tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPlayer */
   { /* szFileName */
       0, /* szFileName[0..31] */
   },
   0, /* lFileOffset */
   0  /* lGaindB */
};

const tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_ADD_FILE_ENTRY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD buf_tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPlayer */
   0  /* ulFileEntryId */
};

const tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_REMOVE_FILE_ENTRY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD buf_tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPlayer */
   0  /* ulFileEntryId */
};

const tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_INFO_FILE_ENTRY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD buf_tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectIdGet */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_LIST_FILE_ENTRY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD buf_tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPlayer */
   0, /* ulFileEntryId */
   0, /* lFileOffset */
   0  /* lGaindB */
};

const tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD =
    &buf_tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_PLAYER_MODIFY_FILE_ENTRY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD buf_tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   { /* SearchParms */
       1, /* ulEntryCount */
       0, /* ulSearchMode */
       cOCTVC1_RUS_WNM_RXMODE_ENUM_AGC, /* ulRxGainControlMode */
       cOCTVC1_RUS_WNM_RXMODE_MGC_GAIN_USE_DEFAULT, /* lManualRxGaindB */
       { /* SelectiveSibDecoding */
           cOCT_FALSE, /* ulEnableFlag */
           (cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_2|cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_3|cOCTVC1_RUS_WNM_SYSINFO_GSM_TYPE_MASK_SI_4), /* ulGsmSIMask */
           (cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_SPM|cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_APM|cOCTVC1_RUS_WNM_SYSINFO_CDMA2000_TYPE_MASK_NLM), /* ulCdma2000SIMask */
           cOCTVC1_RUS_WNM_SYSINFO_UMTS_TYPE_MASK_ALL, /* ulUmtsSibMask */
           cOCTVC1_RUS_WNM_SYSINFO_LTE_TYPE_MASK_ALL, /* ulLteSibMask */
           cOCTVC1_RUS_WNM_SYSINFO_NR_TYPE_MASK_NONE  /* ulNrSibMask */
       },
       0, /* ulUserEventId */
       0, /* ubyEventCellStatsEnableFlag */
       0, /* ubyEventSearchStatsRate */
       0, /* usReserved0 */
       0, /* ulReserved0 */
       0, /* ulReserved1 */
       { /* aEntryList */
           { /* aEntryList[0] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[1] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[2] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[3] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[4] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[5] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[6] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[7] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[8] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[9] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[10] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[11] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[12] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[13] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[14] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[15] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[16] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[17] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[18] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[19] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[20] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[21] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[22] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[23] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[24] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[25] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[26] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[27] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[28] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[29] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[30] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           },
           { /* aEntryList[31] */
               cOCTVC1_RADIO_STANDARD_ENUM_UMTS, /* ulWaveForm */
               1, /* ulBand */
               0, /* ulUarfcnStart */
               0, /* ulUarfcnStop */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRssiThreshold */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lRSPThresholddBm */
               cOCTVC1_RUS_WNM_SEARCH_ENTRY_THRESHOLD_DISABLED, /* lSQThresholddB */
               cOCTVC1_RUS_WNM_DEFAULT_BCH_MAX_NUM_TB_IN_FILE, /* usMaxBchPayloadBlockCnt */
               0  /* usReserved */
           }
       }
   }
};

const tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_MODIFY_SEARCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD buf_tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_START_SEARCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hWnm */
};

const tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_START_SEARCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD buf_tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hWnm */
};

const tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STOP_SEARCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD buf_tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hWnm */
};

const tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_RESUME_SEARCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD buf_tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hWnm */
};

const tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_SEARCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hWnm */
};

const tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_SEARCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_OPEN_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_OPEN_CMD buf_tOCTVC1_RUS_MSG_WNM_OPEN_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_OPEN_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_OPEN_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulPortIndex */
};

const tOCTVC1_RUS_MSG_WNM_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_OPEN_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_OPEN_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_OPEN_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_OPEN_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_OPEN_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_CLOSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_CLOSE_CMD buf_tOCTVC1_RUS_MSG_WNM_CLOSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_CLOSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_CLOSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hWnm */
};

const tOCTVC1_RUS_MSG_WNM_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_CLOSE_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_CLOSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_CLOSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_CLOSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_CLOSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_INFO_CMD buf_tOCTVC1_RUS_MSG_WNM_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hWnm */
};

const tOCTVC1_RUS_MSG_WNM_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_LIST_CMD buf_tOCTVC1_RUS_MSG_WNM_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_RUS_MSG_WNM_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_UMTS_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_UMTS_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectIdGet */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_UMTS_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_GSM_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_GSM_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectIdGet */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_GSM_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_LTE_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_LTE_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectIdGet */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_LTE_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_CDMA2000_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_CDMA2000_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectIdGet */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_CDMA2000_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectGet */
       0, /* hWnm */
       { /* BandId */
           0, /* ulStandard */
           0  /* ulBandNumber */
       },
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   { /* BandId */
       0, /* ulStandard */
       0  /* ulBandNumber */
   },
   { /* ObjectGet */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulRfcn */
   }
};

const tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_RSSI_BAND_CHANNELS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_INFO_NR_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hWnm */
   0  /* ulCellId */
};

const tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_STATS_NR_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD buf_tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectIdGet */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD =
    &buf_tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_WNM_LIST_NR_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD buf_tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_LOOPBACK_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD buf_tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hRffi */
   { /* LoopBack */
       0, /* ulLoopbackEnableFlag */
       0  /* ulLoopbackDelayInSamples */
   }
};

const tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_MODIFY_LOOPBACK_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD buf_tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_INFO_CDMA2000_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD buf_tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRffi */
};

const tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD =
    &buf_tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_STATS_CDMA2000_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD buf_tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hBass */
   { /* AttachConfig */
       0, /* ulSyncMode */
       { /* BaseStationCfg */
           cOCTVC1_RADIO_STANDARD_ENUM_GSM, /* ulWaveForm */
           1, /* ulBand */
           979, /* ulRfcn */
           0, /* usPCI */
           0, /* usReserved */
           cOCTVC1_RUS_BASS_RXMODE_ENUM_MGC, /* ulRxGainControlMode */
           cOCTVC1_RUS_BASS_RXMODE_MGC_GAIN_USE_DEFAULT  /* lManualRxGaindB */
       }
   }
};

const tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_MODIFY_ATTACH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD buf_tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_START_ATTACH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hBass */
};

const tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_START_ATTACH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD buf_tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hBass */
};

const tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_STOP_ATTACH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD buf_tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hBass */
};

const tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_INFO_ATTACH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD buf_tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hBass */
};

const tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_STATS_ATTACH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_OPEN_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_OPEN_CMD buf_tOCTVC1_RUS_MSG_BASS_OPEN_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_OPEN_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_OPEN_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulPortIndex */
};

const tOCTVC1_RUS_MSG_BASS_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_OPEN_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_OPEN_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_OPEN_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_OPEN_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_OPEN_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_OPEN_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_CLOSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_CLOSE_CMD buf_tOCTVC1_RUS_MSG_BASS_CLOSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_CLOSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_CLOSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hBass */
};

const tOCTVC1_RUS_MSG_BASS_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_CLOSE_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_CLOSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_CLOSE_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_CLOSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_CLOSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_CLOSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_INFO_CMD buf_tOCTVC1_RUS_MSG_BASS_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hBass */
};

const tOCTVC1_RUS_MSG_BASS_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_INFO_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_INFO_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_BASS_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_BASS_LIST_CMD buf_tOCTVC1_RUS_MSG_BASS_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_RUS_MSG_BASS_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_RUS_MSG_BASS_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_RUS_MSG_BASS_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_LIST_CMD =
    &buf_tOCTVC1_RUS_MSG_BASS_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_BASS_LIST_CMD *g_pOctDef_tOCTVC1_RUS_MSG_BASS_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_BASS_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_BASS_LIST_CMD; \
    }


/*****************************  MODULE_DATA  *************************************/

/*--------------------------------------------------------------------------
    tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA buf_tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA =
{
   { /* ModuleData */
       (cOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   0, /* hRffi */
   0, /* ulPktCnt */
   0, /* ulAntIndex */
   0, /* ulNbSample */
   0  /* ulReserved */
};

const tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA =
    &buf_tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_RUS_MSG_RFFI_RX_CAPTURE_MDA; \
    }


#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_RUS_DEFAULT_H__ */

