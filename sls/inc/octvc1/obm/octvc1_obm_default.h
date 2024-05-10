/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_OBM_DEFAULT.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: Contains the event definition of the OBM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.7.0-B435 (24/10/2018)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_OBM_DEFAULT_H__
#define __OCTVC1_OBM_DEFAULT_H__

#ifdef __cplusplus
extern "C" {
#endif

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
   cOCTVC1_DO_NOT_MODIFY, /* ulDhcpServerEnableFlag */
   cOCTVC1_DO_NOT_MODIFY  /* ulTftpServerEnableFlag */
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
    tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD buf_tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD *g_pOctDef_tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD =
    &buf_tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD *g_pOctDef_tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_LAST_ERROR_DESC_READ_CMD; \
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
   cOCTVC1_OBM_SIGNAL_STATE_ENUM_CYCLE, /* ulState */
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
    tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulDspId */
   { /* ulNextAssignedIp */
       cOCTDEV_IP_VERSION_ENUM_4, /* ulIpVersion */
       { /* aulIpAddress */
           0, /* aulIpAddress[0] */
           0, /* aulIpAddress[1] */
           0, /* aulIpAddress[2] */
           0  /* aulIpAddress[3] */
       }
   }
};

const tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_DSP_CMD; \
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
   cOCTVC1_DO_NOT_MODIFY, /* ulOutputReferenceClock */
   cOCTVC1_DO_NOT_MODIFY  /* ulRfMuxingMode */
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
   cOCTVC1_OBM_BOARD_STOP_ACTION_ENUM_SHUT_DOWN, /* ulAction */
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
   { /* AntennaConnectorId */
       0, /* usTransceiverIndex */
       0  /* usAntennaIndex */
   },
   cOCTVC1_OBM_UPDATEABLE_COMPONENT_TYPE_ENUM_EMIC, /* ulComponentType */
   { /* szFilename */
       0, /* szFilename[0..127] */
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
    tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD buf_tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_ATTACH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   cOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND, /* ulComponentType */
   { /* szManufacturer */
       0, /* szManufacturer[0..31] */
   },
   { /* szModel */
       0, /* szModel[0..31] */
   },
   { /* szAttachInfo */
       0, /* szAttachInfo[0..255] */
   },
   { /* aAntennaConnectors */
       { /* aAntennaConnectors[0] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[1] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[2] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[3] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[4] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[5] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[6] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[7] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       }
   },
   0  /* ulNumAntennaConnectors */
};

const tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_ATTACH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_ATTACH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_DETACH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_DETACH_CMD buf_tOCTVC1_OBM_MSG_BOARD_DETACH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_DETACH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_DETACH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   cOCTVC1_OBM_ATTACHABLE_COMPONENT_TYPE_ENUM_RF_FRONTEND, /* ulComponentType */
   { /* aAntennaConnectors */
       { /* aAntennaConnectors[0] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[1] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[2] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[3] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[4] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[5] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[6] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       { /* aAntennaConnectors[7] */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       }
   },
   0  /* ulNumAntennaConnectors */
};

const tOCTVC1_OBM_MSG_BOARD_DETACH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_DETACH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_DETACH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_DETACH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_DETACH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_DETACH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_DETACH_CMD; \
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
    tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulGpsId */
   cOCTVC1_DO_NOT_MODIFY, /* ulAntennaSelection */
   cOCTVC1_DO_NOT_MODIFY  /* ulSetSystemTimeFlag */
};

const tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_GPS_CMD; \
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
   { /* AntennaConnectorId */
       0, /* usTransceiverIndex */
       0  /* usAntennaIndex */
   },
   0, /* ulTxRfComponentBankIndex */
   0  /* ulRxRfComponentBankIndex */
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
   { /* AntennaConnectorId */
       0, /* usTransceiverIndex */
       0  /* usAntennaIndex */
   },
   0, /* ulTxRfComponentBankIndex */
   0, /* ulRxRfComponentBankIndex */
   cOCTVC1_DO_NOT_MODIFY, /* ulNumStagesActive */
   cOCTVC1_DO_NOT_MODIFY, /* lTargetTxPowerDbmQ9 */
   cOCTVC1_DO_NOT_MODIFY, /* ulTxRfComponentIndex */
   cOCTVC1_DO_NOT_MODIFY, /* ulRxRfComponentIndex */
   cOCTVC1_DO_NOT_MODIFY, /* ulTxFrequencyKhz */
   cOCTVC1_OBM_RF_DEFAULT_BANDWIDTH_KHZ, /* ulTxBandwidthKhz */
   cOCTVC1_DO_NOT_MODIFY, /* ulRxFrequencyKhz */
   cOCTVC1_OBM_RF_DEFAULT_BANDWIDTH_KHZ, /* ulRxBandwidthKhz */
   { /* szBand */
       0, /* szBand[0..7] */
   },
   cOCTVC1_DO_NOT_MODIFY, /* ulPhyRole */
   cOCT_TRUE, /* ulAllowMissingFiltersFlag */
   cOCTVC1_DO_NOT_MODIFY, /* ulDuplexMode */
   cOCTVC1_DO_NOT_MODIFY, /* ulManagementMode */
   cOCTVC1_DO_NOT_MODIFY, /* lTxGainDbQ9 */
   cOCTVC1_DO_NOT_MODIFY  /* lRxGainDbQ9 */
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
   { /* RfAntennaConnectorIdCursor */
       0, /* ulBoardIndex */
       { /* AntennaConnectorId */
           0, /* usTransceiverIndex */
           0  /* usAntennaIndex */
       },
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
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
    tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD buf_tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_STATS_RF_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   { /* AntennaConnectorId */
       0, /* usTransceiverIndex */
       0  /* usAntennaIndex */
   },
   cOCT_FALSE  /* ulResetStatsFlag */
};

const tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_RF_CMD; \
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
   cOCTVC1_DO_NOT_MODIFY, /* ulUpEventTimeMs */
   cOCTVC1_DO_NOT_MODIFY, /* ulBypassFlag */
   cOCTVC1_DO_NOT_MODIFY  /* ulBypassMode */
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


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD buf_tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0  /* ulBatteryId */
};

const tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_BATTERY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
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

const tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_BATTERY_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD buf_tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulEthernetSwitchId */
   0, /* ulPortId */
   cOCT_FALSE  /* ulResetStatsFlag */
};

const tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_STATS_ETHERNET_SWITCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD buf_tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulEthernetSwitchId */
   0  /* ulLinkStatusPortId */
};

const tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_INFO_ETHERNET_SWITCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD buf_tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
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

const tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_LIST_ETHERNET_SWITCH_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* ulBoardIndex */
   0, /* ulEthernetSwitchId */
   cOCTVC1_DO_NOT_MODIFY, /* ulPortMirrorSrcList */
   cOCTVC1_DO_NOT_MODIFY, /* ulPortMirrorDst */
   { /* aPortVlanMapping */
       cOCTVC1_DO_NOT_MODIFY, /* aPortVlanMapping[0] */
       cOCTVC1_DO_NOT_MODIFY, /* aPortVlanMapping[1] */
       cOCTVC1_DO_NOT_MODIFY, /* aPortVlanMapping[2] */
       cOCTVC1_DO_NOT_MODIFY, /* aPortVlanMapping[3] */
       cOCTVC1_DO_NOT_MODIFY, /* aPortVlanMapping[4] */
       cOCTVC1_DO_NOT_MODIFY, /* aPortVlanMapping[5] */
       cOCTVC1_DO_NOT_MODIFY  /* aPortVlanMapping[6] */
   },
   cOCTVC1_DO_NOT_MODIFY  /* ulRestartAutoNegotiationPortId */
};

const tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD =
    &buf_tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_OBM_MSG_BOARD_MODIFY_ETHERNET_SWITCH_CMD; \
    }


#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_OBM_DEFAULT_H__ */

