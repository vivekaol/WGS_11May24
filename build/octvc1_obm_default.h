/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_DEFAULT.h

$Octasic_Copyright: $

Description: Contains the event definition of the OBM API.

$Octasic_Confidentiality: $

$Octasic_Release: $

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_OBM_DEFAULT_H__
#define __OCTVC1_OBM_DEFAULT_H__


/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_obm_api.h"

/*****************************  COMMAND DEFAULT *****************************/

/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD buf_tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_SYSTEM_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD *g_pOctDef_tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD =
    &buf_tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD *g_pOctDef_tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_SYSTEM_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_SYSTEM_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD buf_tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_SYSTEM_MODIFY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulBootServiceFlag */
};

const tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD =
    &buf_tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_SYSTEM_MODIFY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD buf_tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD *g_pOctDef_tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD =
    &buf_tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD *g_pOctDef_tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_CONFIGURATION_WRITE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD buf_tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_INFO_DSP_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0  /* ulDspId */
};

const tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_DSP_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD buf_tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_RESET_DSP_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulDspId */
   0, /* ulState */
   { /* szFileName */
       0, /* szFileName[0..255] */
   }
};

const tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_RESET_DSP_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_DSP_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_DSP_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_OBM_MSG_BOARD_LIST_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_INFO_CMD buf_tOCTVC1_OBM_MSG_BOARD_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulBoardIndex */
};

const tOCTVC1_OBM_MSG_BOARD_INFO_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_INFO_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_MODIFY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   cOCTVC1_DO_NOT_MODIFY, /* ulInputReferenceClock */
   cOCTVC1_DO_NOT_MODIFY  /* ulOutputReferenceClock */
};

const tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_MODIFY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_STATS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_STATS_CMD buf_tOCTVC1_OBM_MSG_BOARD_STATS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_STATS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_STATS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* ulBoardIndex */
};

const tOCTVC1_OBM_MSG_BOARD_STATS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_STATS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_STATS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_STATS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_STOP_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_STOP_CMD buf_tOCTVC1_OBM_MSG_BOARD_STOP_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_STOP_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_STOP_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   { /* WakeupDateTime */
       0, /* ulDay */
       0, /* ulMonth */
       0, /* ulYear */
       0, /* ulHour */
       0, /* ulMinutes */
       0  /* ulSeconds */
   }
};

const tOCTVC1_OBM_MSG_BOARD_STOP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STOP_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_STOP_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_STOP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STOP_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_STOP_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STOP_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD buf_tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_UPDATE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   { /* szEmic */
       0, /* szEmic[0] */
       0, /* szEmic[1] */
       0, /* szEmic[2] */
       0, /* szEmic[3] */
       0, /* szEmic[4] */
       0, /* szEmic[5] */
       0, /* szEmic[6] */
       0, /* szEmic[7] */
       0, /* szEmic[8] */
       0, /* szEmic[9] */
       0, /* szEmic[10] */
       0, /* szEmic[11] */
       0, /* szEmic[12] */
       0, /* szEmic[13] */
       0, /* szEmic[14] */
       0, /* szEmic[15] */
       0, /* szEmic[16] */
       0, /* szEmic[17] */
       0, /* szEmic[18] */
       0, /* szEmic[19] */
       0, /* szEmic[20] */
       0, /* szEmic[21] */
       0, /* szEmic[22] */
       0, /* szEmic[23] */
       0, /* szEmic[24] */
       0, /* szEmic[25] */
       0, /* szEmic[26] */
       0, /* szEmic[27] */
       0, /* szEmic[28] */
       0, /* szEmic[29] */
       0, /* szEmic[30] */
       0, /* szEmic[31] */
       0, /* szEmic[32] */
       0, /* szEmic[33] */
       0, /* szEmic[34] */
       0, /* szEmic[35] */
       0, /* szEmic[36] */
       0, /* szEmic[37] */
       0, /* szEmic[38] */
       0, /* szEmic[39] */
       0, /* szEmic[40] */
       0, /* szEmic[41] */
       0, /* szEmic[42] */
       0, /* szEmic[43] */
       0, /* szEmic[44] */
       0, /* szEmic[45] */
       0, /* szEmic[46] */
       0, /* szEmic[47] */
       0, /* szEmic[48] */
       0, /* szEmic[49] */
       0, /* szEmic[50] */
       0, /* szEmic[51] */
       0, /* szEmic[52] */
       0, /* szEmic[53] */
       0, /* szEmic[54] */
       0, /* szEmic[55] */
       0, /* szEmic[56] */
       0, /* szEmic[57] */
       0, /* szEmic[58] */
       0, /* szEmic[59] */
       0, /* szEmic[60] */
       0, /* szEmic[61] */
       0, /* szEmic[62] */
       0, /* szEmic[63] */
       0, /* szEmic[64] */
       0, /* szEmic[65] */
       0, /* szEmic[66] */
       0, /* szEmic[67] */
       0, /* szEmic[68] */
       0, /* szEmic[69] */
       0, /* szEmic[70] */
       0, /* szEmic[71] */
       0, /* szEmic[72] */
       0, /* szEmic[73] */
       0, /* szEmic[74] */
       0, /* szEmic[75] */
       0, /* szEmic[76] */
       0, /* szEmic[77] */
       0, /* szEmic[78] */
       0, /* szEmic[79] */
       0, /* szEmic[80] */
       0, /* szEmic[81] */
       0, /* szEmic[82] */
       0, /* szEmic[83] */
       0, /* szEmic[84] */
       0, /* szEmic[85] */
       0, /* szEmic[86] */
       0, /* szEmic[87] */
       0, /* szEmic[88] */
       0, /* szEmic[89] */
       0, /* szEmic[90] */
       0, /* szEmic[91] */
       0, /* szEmic[92] */
       0, /* szEmic[93] */
       0, /* szEmic[94] */
       0, /* szEmic[95] */
       0, /* szEmic[96] */
       0, /* szEmic[97] */
       0, /* szEmic[98] */
       0, /* szEmic[99] */
       0, /* szEmic[100] */
       0, /* szEmic[101] */
       0, /* szEmic[102] */
       0, /* szEmic[103] */
       0, /* szEmic[104] */
       0, /* szEmic[105] */
       0, /* szEmic[106] */
       0, /* szEmic[107] */
       0, /* szEmic[108] */
       0, /* szEmic[109] */
       0, /* szEmic[110] */
       0, /* szEmic[111] */
       0, /* szEmic[112] */
       0, /* szEmic[113] */
       0, /* szEmic[114] */
       0, /* szEmic[115] */
       0, /* szEmic[116] */
       0, /* szEmic[117] */
       0, /* szEmic[118] */
       0, /* szEmic[119] */
       0, /* szEmic[120] */
       0, /* szEmic[121] */
       0, /* szEmic[122] */
       0, /* szEmic[123] */
       0, /* szEmic[124] */
       0, /* szEmic[125] */
       0, /* szEmic[126] */
       0  /* szEmic[127] */
   }
};

const tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_UPDATE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_UPDATE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD buf_tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_INFO_GPS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0  /* ulGpsId */
};

const tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_GPS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD buf_tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_STATS_GPS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0  /* ulGpsId */
};

const tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_GPS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD buf_tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_RESET_GPS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulGpsId */
   0, /* ulState */
   0  /* ulColdStartFlag */
};

const tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_RESET_GPS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_GPS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_GPS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD buf_tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_INFO_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0  /* ulRfId */
};

const tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_RF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulRfId */
   cOCTVC1_DO_NOT_MODIFY, /* ulNumStagesActive */
   cOCTVC1_DO_NOT_MODIFY, /* ulTxFilterIndex */
   cOCTVC1_DO_NOT_MODIFY  /* ulRxFilterIndex */
};

const tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_RF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_RF_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD buf_tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_READ_I2C_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulBusId */
   1, /* ulNumBytes */
   0  /* bySlave */
};

const tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_READ_I2C_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD buf_tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulBusId */
   0, /* ulNumBytes */
   0, /* bySlave */
   { /* abyData */
       0, /* abyData[0] */
       0, /* abyData[1] */
       0, /* abyData[2] */
       0, /* abyData[3] */
       0, /* abyData[4] */
       0, /* abyData[5] */
       0, /* abyData[6] */
       0, /* abyData[7] */
       0, /* abyData[8] */
       0, /* abyData[9] */
       0, /* abyData[10] */
       0, /* abyData[11] */
       0, /* abyData[12] */
       0, /* abyData[13] */
       0, /* abyData[14] */
       0, /* abyData[15] */
       0, /* abyData[16] */
       0, /* abyData[17] */
       0, /* abyData[18] */
       0, /* abyData[19] */
       0, /* abyData[20] */
       0, /* abyData[21] */
       0, /* abyData[22] */
       0, /* abyData[23] */
       0, /* abyData[24] */
       0, /* abyData[25] */
       0, /* abyData[26] */
       0, /* abyData[27] */
       0, /* abyData[28] */
       0, /* abyData[29] */
       0, /* abyData[30] */
       0  /* abyData[31] */
   }
};

const tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_WRITE_I2C_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_I2C_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_I2C_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD buf_tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0  /* ulPowerSwitchId */
};

const tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_POWER_SWITCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulPowerSwitchId */
   cOCTVC1_DO_NOT_MODIFY, /* ulDownEventTimeMs */
   cOCTVC1_DO_NOT_MODIFY  /* ulUpEventTimeMs */
};

const tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_POWER_SWITCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* SubObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST, /* ulGetMode */
       0  /* ulSubObjectId */
   }
};

const tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_POWER_SWITCH_CMD; \
    }


#endif /* __OCTVC1_OBM_DEFAULT_H__ */

