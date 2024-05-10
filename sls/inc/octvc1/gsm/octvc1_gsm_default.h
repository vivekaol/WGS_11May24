/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_GSM_DEFAULT.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the GSM API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_GSM_DEFAULT_H__
#define __OCTVC1_GSM_DEFAULT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_gsm_api.h"

/*****************************  COMMAND DEFAULT *****************************/

/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_OPEN_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_OPEN_CMD buf_tOCTVC1_GSM_MSG_TRX_OPEN_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_OPEN_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_OPEN_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulRfPortIndex */
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* Config */
       0, /* ulBand */
       0, /* usTsc */
       0, /* usArfcn */
       0, /* usBcchArfcn */
       0, /* usCentreArfcn */
       0, /* usHsn */
       0, /* usMaio */
       { /* ausReserve */
           0, /* ausReserve[0] */
           0  /* ausReserve[1] */
       },
       0, /* ulHoppingFlag */
       0, /* ulHoppingListLength */
       { /* ausHoppingList */
           0, /* ausHoppingList[0] */
           0, /* ausHoppingList[1] */
           0, /* ausHoppingList[2] */
           0, /* ausHoppingList[3] */
           0, /* ausHoppingList[4] */
           0, /* ausHoppingList[5] */
           0, /* ausHoppingList[6] */
           0, /* ausHoppingList[7] */
           0, /* ausHoppingList[8] */
           0, /* ausHoppingList[9] */
           0, /* ausHoppingList[10] */
           0, /* ausHoppingList[11] */
           0, /* ausHoppingList[12] */
           0, /* ausHoppingList[13] */
           0, /* ausHoppingList[14] */
           0, /* ausHoppingList[15] */
           0, /* ausHoppingList[16] */
           0, /* ausHoppingList[17] */
           0, /* ausHoppingList[18] */
           0, /* ausHoppingList[19] */
           0, /* ausHoppingList[20] */
           0, /* ausHoppingList[21] */
           0, /* ausHoppingList[22] */
           0, /* ausHoppingList[23] */
           0, /* ausHoppingList[24] */
           0, /* ausHoppingList[25] */
           0, /* ausHoppingList[26] */
           0, /* ausHoppingList[27] */
           0, /* ausHoppingList[28] */
           0, /* ausHoppingList[29] */
           0, /* ausHoppingList[30] */
           0, /* ausHoppingList[31] */
           0, /* ausHoppingList[32] */
           0, /* ausHoppingList[33] */
           0, /* ausHoppingList[34] */
           0, /* ausHoppingList[35] */
           0, /* ausHoppingList[36] */
           0, /* ausHoppingList[37] */
           0, /* ausHoppingList[38] */
           0, /* ausHoppingList[39] */
           0, /* ausHoppingList[40] */
           0, /* ausHoppingList[41] */
           0, /* ausHoppingList[42] */
           0, /* ausHoppingList[43] */
           0, /* ausHoppingList[44] */
           0, /* ausHoppingList[45] */
           0, /* ausHoppingList[46] */
           0, /* ausHoppingList[47] */
           0, /* ausHoppingList[48] */
           0, /* ausHoppingList[49] */
           0, /* ausHoppingList[50] */
           0, /* ausHoppingList[51] */
           0, /* ausHoppingList[52] */
           0, /* ausHoppingList[53] */
           0, /* ausHoppingList[54] */
           0, /* ausHoppingList[55] */
           0, /* ausHoppingList[56] */
           0, /* ausHoppingList[57] */
           0, /* ausHoppingList[58] */
           0, /* ausHoppingList[59] */
           0, /* ausHoppingList[60] */
           0, /* ausHoppingList[61] */
           0, /* ausHoppingList[62] */
           0  /* ausHoppingList[63] */
       }
   },
   { /* RfConfig */
       70, /* ulRxGainDb */
       0, /* ulTxAttndB */
       0, /* ulTxAntennaId */
       0  /* ulRxAntennaId */
   }
};

const tOCTVC1_GSM_MSG_TRX_OPEN_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_OPEN_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_OPEN_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_OPEN_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_OPEN_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_OPEN_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_OPEN_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_CLOSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_CLOSE_CMD buf_tOCTVC1_GSM_MSG_TRX_CLOSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_CLOSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_CLOSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_CLOSE_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_CLOSE_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_CLOSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_CLOSE_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_CLOSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_CLOSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_CLOSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STATUS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STATUS_CMD buf_tOCTVC1_GSM_MSG_TRX_STATUS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_STATUS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_STATUS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0  /* ulResetFlag */
};

const tOCTVC1_GSM_MSG_TRX_STATUS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_STATUS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STATUS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STATUS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_RESET_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_RESET_CMD buf_tOCTVC1_GSM_MSG_TRX_RESET_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_RESET_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_RESET_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_RESET_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_RESET_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_RESET_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_RESET_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_MODIFY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_MODIFY_CMD buf_tOCTVC1_GSM_MSG_TRX_MODIFY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_MODIFY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_MODIFY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* Config */
       cOCTVC1_DO_NOT_MODIFY, /* ulBand */
       (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* usTsc */
       (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* usArfcn */
       (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* usBcchArfcn */
       (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* usCentreArfcn */
       (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* usHsn */
       (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* usMaio */
       { /* ausReserve */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausReserve[0] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF)  /* ausReserve[1] */
       },
       cOCTVC1_DO_NOT_MODIFY, /* ulHoppingFlag */
       cOCTVC1_DO_NOT_MODIFY, /* ulHoppingListLength */
       { /* ausHoppingList */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[0] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[1] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[2] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[3] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[4] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[5] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[6] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[7] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[8] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[9] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[10] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[11] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[12] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[13] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[14] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[15] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[16] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[17] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[18] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[19] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[20] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[21] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[22] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[23] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[24] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[25] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[26] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[27] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[28] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[29] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[30] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[31] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[32] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[33] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[34] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[35] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[36] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[37] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[38] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[39] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[40] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[41] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[42] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[43] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[44] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[45] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[46] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[47] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[48] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[49] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[50] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[51] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[52] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[53] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[54] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[55] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[56] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[57] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[58] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[59] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[60] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[61] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF), /* ausHoppingList[62] */
           (cOCTVC1_DO_NOT_MODIFY & 0xFFFF)  /* ausHoppingList[63] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_MODIFY_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_MODIFY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_MODIFY_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_MODIFY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_LIST_CMD buf_tOCTVC1_GSM_MSG_TRX_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxIdCursor */
       { /* TrxId */
           0, /* byTrxId */
           { /* abyPad */
               0, /* abyPad[0] */
               0, /* abyPad[1] */
               0  /* abyPad[2] */
           }
       },
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_GSM_MSG_TRX_LIST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_LIST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD buf_tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_CLOSE_ALL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD buf_tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_START_RECORD_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_START_RECORD_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_RECORD_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD buf_tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_STOP_RECORD_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_RECORD_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   { /* Config */
       0, /* byTimingAdvance */
       0, /* byBSIC */
       0, /* byCmiPhase */
       cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET, /* byInitRate */
       { /* abyRate */
           cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET, /* abyRate[0] */
           cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET, /* abyRate[1] */
           cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET, /* abyRate[2] */
           cOCTVC1_GSM_AMR_CODEC_MODE_ENUM_UNSET  /* abyRate[3] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_ACTIVATE_LOGICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   }
};

const tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_LOGICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   }
};

const tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_LOGICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_LOGICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* LchIdCursor */
       { /* TrxId */
           0, /* byTrxId */
           { /* abyPad */
               0, /* abyPad[0] */
               0, /* abyPad[1] */
               0  /* abyPad[2] */
           }
       },
       { /* LchId */
           cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
           cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
           0, /* bySAPI */
           0  /* byDirection */
       },
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_LOGICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0, /* ulChannelType */
   0  /* ulPayloadType */
};

const tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_ACTIVATE_PHYSICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DEACTIVATE_PHYSICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0  /* ulResetFlag */
};

const tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_PHYSICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_PHYSICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* PchIdCursor */
       { /* TrxId */
           0, /* byTrxId */
           { /* abyPad */
               0, /* abyPad[0] */
               0, /* abyPad[1] */
               0  /* abyPad[2] */
           }
       },
       { /* PchId */
           cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
           { /* abyPad */
               0, /* abyPad[0] */
               0, /* abyPad[1] */
               0  /* abyPad[2] */
           }
       },
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_LIST_PHYSICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD buf_tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0, /* ulSubchannelNb */
   { /* Config */
       0, /* ulCipherId */
       { /* abyKey */
           0, /* abyKey[0] */
           0, /* abyKey[1] */
           0, /* abyKey[2] */
           0, /* abyKey[3] */
           0, /* abyKey[4] */
           0, /* abyKey[5] */
           0, /* abyKey[6] */
           0  /* abyKey[7] */
       }
   },
   0, /* ulDirection */
   { /* abyPad */
       0, /* abyPad[0] */
       0, /* abyPad[1] */
       0, /* abyPad[2] */
       0, /* abyPad[3] */
       0, /* abyPad[4] */
       0, /* abyPad[5] */
       0  /* abyPad[6] */
   }
};

const tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_PHYSICAL_CHANNEL_CIPHERING_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_CIPHERING_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* PchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_PHYSICAL_CHANNEL_MEASUREMENT_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_RF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD buf_tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_MODIFY_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* RfConfig */
       cOCTVC1_DO_NOT_MODIFY, /* ulRxGainDb */
       cOCTVC1_DO_NOT_MODIFY, /* ulTxAttndB */
       cOCTVC1_DO_NOT_MODIFY, /* ulTxAntennaId */
       cOCTVC1_DO_NOT_MODIFY  /* ulRxAntennaId */
   }
};

const tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_RF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD buf_tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TAP_FILTER_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* IndexGet */
       0, /* ulIndex */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD =
    &buf_tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD buf_tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TAP_FILTER_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulFilterIndex */
};

const tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD =
    &buf_tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD buf_tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TAP_FILTER_STATS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulFilterIndex */
};

const tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD =
    &buf_tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_STATS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD buf_tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulFilterIndex */
   { /* Filter */
       cOCTVC1_GSM_TAP_FILTER_TYPE_ENUM_NONE, /* ulType */
       cOCTVC1_GSM_TAP_FILTER_MASK_NONE, /* ulMask */
       { /* Trx */
           cOCT_FALSE, /* ulAllTrxFlag */
           { /* TrxId */
               0, /* byTrxId */
               { /* abyPad */
                   0, /* abyPad[0] */
                   0, /* abyPad[1] */
                   0  /* abyPad[2] */
               }
           }
       },
       { /* PhysicalChannel */
           0, /* ulEntryCnt */
           { /* aEntry */
               { /* aEntry[0] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               },
               { /* aEntry[1] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               },
               { /* aEntry[2] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               },
               { /* aEntry[3] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               },
               { /* aEntry[4] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               },
               { /* aEntry[5] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               },
               { /* aEntry[6] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               },
               { /* aEntry[7] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* PchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   }
               }
           }
       },
       { /* LogicalChannel */
           0, /* ulEntryCnt */
           { /* aEntry */
               { /* aEntry[0] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               },
               { /* aEntry[1] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               },
               { /* aEntry[2] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               },
               { /* aEntry[3] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               },
               { /* aEntry[4] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               },
               { /* aEntry[5] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               },
               { /* aEntry[6] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               },
               { /* aEntry[7] */
                   { /* TrxId */
                       0, /* byTrxId */
                       { /* abyPad */
                           0, /* abyPad[0] */
                           0, /* abyPad[1] */
                           0  /* abyPad[2] */
                       }
                   },
                   { /* LchId */
                       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
                       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
                       0, /* bySAPI */
                       0  /* byDirection */
                   }
               }
           }
       }
   }
};

const tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD =
    &buf_tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TAP_FILTER_MODIFY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD buf_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulOversample16xEnableFlag */
};

const tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD *g_pOctDef_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD =
    &buf_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD *g_pOctDef_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_MODIFY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD buf_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD *g_pOctDef_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD =
    &buf_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD *g_pOctDef_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_OVERSAMPLE_SELECT_16X_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD buf_tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   }
};

const tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD buf_tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   }
};

const tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_LOGICAL_CHANNEL_RAW_DATA_INDICATIONS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD buf_tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   0  /* ulResetFlag */
};

const tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_REQUEST_LOGICAL_CHANNEL_CMU_LOOPBACK_TEST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_STUBB_LOOPBACK_TEST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD buf_tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* STUB_CHANNEL_ID */
       cOCTVC1_GSM_TIMESLOT_NB_STUB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       cOCTVC1_GSM_SAPI_ENUM_TCHF, /* bySAPI */
       cOCTVC1_GSM_STUB_MODE_ENUM_NONE  /* byStubMode */
   },
   0  /* HEADER_CAPTURE */
};

const tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_STUBB_LOOPBACK_TEST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD buf_tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0, /* byTimeslotNb */
   0, /* bySubChannelNb */
   0  /* byStubMode */
};

const tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_STUBB_LOOPBACK_TEST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD buf_tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0, /* testModeVal */
   0, /* modulation */
   { /* abyBurstType */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND, /* abyBurstType[0] */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND, /* abyBurstType[1] */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND, /* abyBurstType[2] */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND, /* abyBurstType[3] */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND, /* abyBurstType[4] */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND, /* abyBurstType[5] */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND, /* abyBurstType[6] */
       cOCTVC1_GSM_TEST_MODE_BURST_TYPE_ENUM_DATA_RAND  /* abyBurstType[7] */
   }
};

const tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_TEST_MODE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_TEST_MODE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_DL_TRACE_BUFF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD buf_tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0, /* Mode */
   0, /* TimeslotNb */
   0, /* SubChannelNb */
   0, /* tracePoint */
   0  /* Type */
};

const tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_START_DL_TRACE_BUFF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD buf_tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0, /* TimeslotNb */
   0, /* SubChannelNb */
   0  /* Mode */
};

const tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STOP_DL_TRACE_BUFF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD buf_tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* TSDigitalScaling */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF), /* TSDigitalScaling[0] */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF), /* TSDigitalScaling[1] */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF), /* TSDigitalScaling[2] */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF), /* TSDigitalScaling[3] */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF), /* TSDigitalScaling[4] */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF), /* TSDigitalScaling[5] */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF), /* TSDigitalScaling[6] */
       (cOCTVC1_DO_NOT_MODIFY & 0xFF)  /* TSDigitalScaling[7] */
   }
};

const tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_MODIFY_TS_DIGITAL_SCALING_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD buf_tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INFO_TS_DIGITAL_SCALING_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD buf_tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD =
    &buf_tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RESET_TS_DIGITAL_SCALING_CMD; \
    }


/*****************************  MODULE_DATA  *************************************/

/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA buf_tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   0, /* ulAntennaIndex */
   0, /* ulFrameNumber */
   0, /* ulPower */
   0, /* ulDataSizeInBytes */
   0, /* byBadFlag */
   0, /* byBurstId */
   0, /* byReserved0 */
   0  /* byReserved1 */
};

const tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_UPLINK_RF_INPUT_DATA_LOGICAL_CHANNEL_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA buf_tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   0  /* ulFrameNumber */
};

const tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_EMPTY_FRAME_LOGICAL_CHANNEL_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA buf_tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   { /* Data */
       0, /* ulFrameNumber */
       cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE, /* ulPayloadType */
       0, /* ulDataLength */
       { /* abyEgprsCrc */
           0, /* abyEgprsCrc[0] */
           0  /* abyEgprsCrc[1] */
       },
       0, /* ucInvertedCrcSpeechFlag */
       0, /* ucTbfStartIndicationBitMap */
       { /* abyPadding */
           0, /* abyPadding[0] */
           0, /* abyPadding[1] */
           0, /* abyPadding[2] */
           0  /* abyPadding[3] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DATA_REQUEST_LOGICAL_CHANNEL_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA buf_tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0  /* ulFrameNumber */
};

const tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_TIME_INDICATION_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA buf_tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0, /* ulStatus */
   0  /* ulFrameNumber */
};

const tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_STATUS_CHANGE_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA buf_tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   0  /* ulMcc */
};

const tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_INVALID_MCC_INDICATION_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA buf_tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   { /* MeasurementInfo */
       0, /* sSNRDb */
       0, /* sRSSIDbm */
       0, /* sBurstTiming */
       0, /* sBurstTiming4x */
       0, /* usBERCnt */
       0, /* usBERTotalBitCnt */
       0, /* uLMeanBep */
       0, /* uLCVBep */
       0  /* uLReserved1 */
   },
   { /* Data */
       0, /* ulFrameNumber */
       cOCTVC1_GSM_PAYLOAD_TYPE_ENUM_NONE, /* ulPayloadType */
       0, /* ulDataLength */
       { /* abyEgprsCrc */
           0, /* abyEgprsCrc[0] */
           0  /* abyEgprsCrc[1] */
       },
       0, /* ucInvertedCrcSpeechFlag */
       0, /* ucTbfStartIndicationBitMap */
       { /* abyPadding */
           0, /* abyPadding[0] */
           0, /* abyPadding[1] */
           0, /* abyPadding[2] */
           0  /* abyPadding[3] */
       }
   }
};

const tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_DATA_INDICATION_LOGICAL_CHANNEL_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA buf_tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   0, /* ulFrameNumber */
   0  /* ulPrevDRLateFlag */
};

const tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_READY_TO_SEND_INDICATION_LOGICAL_CHANNEL_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA buf_tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   0, /* ulBurstType */
   0, /* ulFrameNumber */
   { /* MeasurementInfo */
       0, /* sSNRDb */
       0, /* sRSSIDbm */
       0, /* sBurstTiming */
       0, /* sBurstTiming4x */
       0, /* usBERCnt */
       0, /* usBERTotalBitCnt */
       0, /* uLMeanBep */
       0, /* uLCVBep */
       0  /* uLReserved1 */
   },
   0  /* ulMsgLength */
};

const tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RACH_INDICATION_LOGICAL_CHANNEL_MDA; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA buf_tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA =
{
   { /* ModuleData */
       (cOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MID), /* ulModuleDataId */
       (sizeof(tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA)), /* ulModuleDataSize */
       0, /* hLogicalObj */
       0  /* ulTimestamp */
   },
   { /* TrxId */
       0, /* byTrxId */
       { /* abyPad */
           0, /* abyPad[0] */
           0, /* abyPad[1] */
           0  /* abyPad[2] */
       }
   },
   { /* LchId */
       cOCTVC1_GSM_ID_TIMESLOT_NB_ENUM_0, /* byTimeslotNb */
       cOCTVC1_GSM_ID_SUB_CHANNEL_NB_ENUM_0, /* bySubChannelNb */
       0, /* bySAPI */
       0  /* byDirection */
   },
   { /* MeasurementInfo */
       0, /* sSNRDb */
       0, /* sRSSIDbm */
       0, /* sBurstTiming */
       0, /* sBurstTiming4x */
       0, /* usBERCnt */
       0, /* usBERTotalBitCnt */
       0, /* usTrSqErrCnt */
       0, /* usTrSqTotalBitCnt */
       0, /* sFreqErrHz */
       0  /* usReserved */
   },
   { /* Data */
       0, /* ulFrameNumber */
       0  /* ulDataLength */
   }
};

const tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA =
    &buf_tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_GSM_MSG_TRX_RAW_DATA_INDICATION_LOGICAL_CHANNEL_MDA; \
    }


#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_GSM_DEFAULT_H__ */

