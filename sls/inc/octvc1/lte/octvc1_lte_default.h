/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LTE_DEFAULT.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the event definition of the LTE API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_LTE_APP-04.03.00-B3607 (2019/04/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_LTE_DEFAULT_H__
#define __OCTVC1_LTE_DEFAULT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_lte_api.h"

/*****************************  COMMAND DEFAULT *****************************/

/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD buf_tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD *g_pOctDef_tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD =
    &buf_tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD *g_pOctDef_tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_MODULE_INFO_CONFIG_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD buf_tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_DO_NOT_MODIFY  /* ulBootProcConfigType */
};

const tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD *g_pOctDef_tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD =
    &buf_tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD *g_pOctDef_tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_MODULE_MODIFY_CONFIG_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD buf_tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_OPEN_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulUserId */
   0, /* ulRfPortIndex */
   { /* CellConfig */
       cOCTVC1_LTE_DUPLEX_MODE_ENUM_FDD, /* ulDuplexMode */
       cOCTVC1_LTE_CP_TYPE_ENUM_NORMAL, /* ulCpType */
       cOCTVC1_LTE_BANDWIDTH_ENUM_10MHZ  /* ulBwId */
   },
   { /* CellTddConfig */
       cOCTVC1_LTE_TDD_UL_DL_CONFIG_ENUM_INVALID, /* ulUplinkDownlinkConfigIdx */
       cOCTVC1_LTE_TDD_SPECIAL_SF_CONFIG_ENUM_INVALID  /* ulSpecialSubframeConfigIdx */
   },
   { /* RfConfig */
       cOCTVC1_LTE_RF_CONFIG_SOURCE_ENUM_EARFCN, /* ulConfigSource */
       6300, /* ulDownlinkEarfcn */
       cOCTVC1_LTE_AUTO, /* ulUplinkEarfcn */
       cOCTVC1_LTE_AUTO, /* ulDownlinkFrequencyKhz */
       cOCTVC1_LTE_AUTO  /* ulUplinkFrequencyKhz */
   },
   cOCT_FALSE, /* bTxOuputScPwrEqual */
   cOCT_FALSE, /* bUseExtFirCoeff */
   cOCT_FALSE, /* ulFrameBorderAlignEnableFlag */
   0, /* ulFrameBorderDelaySamples */
   { /* PhyConfig */
       cOCT_TRUE, /* ulDownlinkCfrEnableFlag */
       cOCT_TRUE, /* ulUplinkHarqEnableFlag */
       cOCT_FALSE, /* ulFrameTriggerGpioEnableFlag */
       cOCT_FALSE, /* ulTxDiversityEnableFlag */
       cOCT_FALSE, /* ulRxDiversityEnableFlag */
       { /* SfnSwitchConfig */
           cOCT_FALSE, /* ulSfnSwitchOnGpioEnableFlag */
           0  /* ulSfnSwitchValue */
       }
   },
   { /* BassConfig */
       cOCT_TRUE, /* ulSpecificPciFlag */
       0, /* ulPhysicalCellId */
       0, /* ulFrameOffset */
       cOCT_TRUE, /* ulRxGainFixedFlag */
       -32767, /* lSnrThreshold */
       32, /* ulTrackingPeriod */
       { /* tBlackListConfig */
           0, /* ulNumPhysicalCellId */
           { /* aPhysicalCellIdList */
               0, /* aPhysicalCellIdList[0] */
               0, /* aPhysicalCellIdList[1] */
               0, /* aPhysicalCellIdList[2] */
               0, /* aPhysicalCellIdList[3] */
               0, /* aPhysicalCellIdList[4] */
               0  /* aPhysicalCellIdList[5] */
           }
       }
   }
};

const tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_OPEN_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_OPEN_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD buf_tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_CLOSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_CLOSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_INFO_CMD buf_tOCTVC1_LTE_MSG_ENODEB_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_INFO_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_INFO_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_LIST_CMD buf_tOCTVC1_LTE_MSG_ENODEB_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_LTE_MSG_ENODEB_LIST_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_LIST_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_LIST_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD buf_tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD buf_tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hEnodeb */
   0  /* ulResetStatsFlag */
};

const tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hEnodeb */
   { /* CellConfig */
       cOCTVC1_DO_NOT_MODIFY, /* ulDuplexMode */
       cOCTVC1_DO_NOT_MODIFY, /* ulCpType */
       cOCTVC1_DO_NOT_MODIFY  /* ulBwId */
   },
   { /* CellTddConfig */
       cOCTVC1_DO_NOT_MODIFY, /* ulUplinkDownlinkConfigIdx */
       cOCTVC1_DO_NOT_MODIFY  /* ulSpecialSubframeConfigIdx */
   }
};

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD buf_tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_START_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_START_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD buf_tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STOP_CELL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD buf_tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_INFO_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_RF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hEnodeb */
   { /* RfConfig */
       cOCTVC1_DO_NOT_MODIFY, /* ulConfigSource */
       cOCTVC1_DO_NOT_MODIFY, /* ulDownlinkEarfcn */
       cOCTVC1_DO_NOT_MODIFY, /* ulUplinkEarfcn */
       cOCTVC1_DO_NOT_MODIFY, /* ulDownlinkFrequencyKhz */
       cOCTVC1_DO_NOT_MODIFY  /* ulUplinkFrequencyKhz */
   },
   { /* aTxLogicalAntennaConfig */
       { /* aTxLogicalAntennaConfig[0] */
           cOCTVC1_DO_NOT_MODIFY  /* ulPhysicalAntennaId */
       },
       { /* aTxLogicalAntennaConfig[1] */
           cOCTVC1_DO_NOT_MODIFY  /* ulPhysicalAntennaId */
       }
   },
   { /* aRxLogicalAntennaConfig */
       { /* aRxLogicalAntennaConfig[0] */
           cOCTVC1_DO_NOT_MODIFY  /* ulPhysicalAntennaId */
       },
       { /* aRxLogicalAntennaConfig[1] */
           cOCTVC1_DO_NOT_MODIFY  /* ulPhysicalAntennaId */
       }
   }
};

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_RF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD buf_tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_PHY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hEnodeb */
   { /* PhyConfig */
       cOCTVC1_DO_NOT_MODIFY, /* ulDownlinkCfrEnableFlag */
       cOCTVC1_DO_NOT_MODIFY, /* ulUplinkHarqEnableFlag */
       cOCTVC1_DO_NOT_MODIFY, /* ulFrameTriggerGpioEnableFlag */
       cOCTVC1_DO_NOT_MODIFY, /* ulTxDiversityEnableFlag */
       cOCTVC1_DO_NOT_MODIFY, /* ulRxDiversityEnableFlag */
       { /* SfnSwitchConfig */
           cOCTVC1_DO_NOT_MODIFY, /* ulSfnSwitchOnGpioEnableFlag */
           cOCTVC1_DO_NOT_MODIFY  /* ulSfnSwitchValue */
       }
   }
};

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_PHY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD buf_tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_PHY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD buf_tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_ETM_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hEnodeb */
   { /* EtmConfig */
       cOCTVC1_DO_NOT_MODIFY  /* ulEpreIndex */
   }
};

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_ETM_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD buf_tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_FAPI_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hEnodeb */
   { /* FapiPhyConfig */
       cOCTVC1_DO_NOT_MODIFY  /* ulFapiConfigHoldFlag */
   }
};

const tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_MODIFY_FAPI_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD buf_tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_INFO_BASS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD buf_tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_START_BASS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hEnodeb */
};

const tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_START_BASS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD buf_tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hEnodeb */
   cOCT_FALSE  /* ulResetStatsFlag */
};

const tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD =
    &buf_tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_LTE_MSG_ENODEB_STATS_BASS_CMD; \
    }


#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_LTE_DEFAULT_H__ */

