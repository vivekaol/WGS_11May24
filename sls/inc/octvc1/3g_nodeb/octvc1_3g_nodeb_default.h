/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_DEFAULT.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the 3G_NODEB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_3G_NODEB_DEFAULT_H__
#define __OCTVC1_3G_NODEB_DEFAULT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_3g_nodeb_api.h"

/*****************************  COMMAND DEFAULT *****************************/

/*--------------------------------------------------------------------------
    tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD buf_tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD =
    &buf_tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_3G_NODEB_MSG_MODULE_INFO_CONFIG_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD buf_tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD =
    &buf_tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_3G_NODEB_MSG_MODULE_MODIFY_CONFIG_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD buf_tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_3G_NODEB_MSG_CELL_OPEN_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulRfPortIndex */
   0, /* ulUserId */
   { /* RfConfig */
       cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_1, /* ulBandId */
       10700, /* ulDlUarfcn */
       9750, /* ulUlUarfcn */
       38, /* ulRxGainDb */
       0  /* ulTxAttndB */
   }
};

const tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD =
    &buf_tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_OPEN_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD buf_tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hCell */
};

const tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD =
    &buf_tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_CLOSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD buf_tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_3G_NODEB_MSG_CELL_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hCell */
};

const tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD =
    &buf_tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD buf_tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_3G_NODEB_MSG_CELL_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD =
    &buf_tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD buf_tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hCell */
};

const tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD =
    &buf_tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_3G_NODEB_MSG_CELL_INFO_RF_CMD; \
    }


#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_3G_NODEB_DEFAULT_H__ */

