/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_JOB_DEFAULT.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the event definition of the JOB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_JOB_DEFAULT_H__
#define __OCTVC1_JOB_DEFAULT_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "octvc1_job_api.h"

/*****************************  COMMAND DEFAULT *****************************/

/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_LIST_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_LIST_CMD buf_tOCTVC1_JOB_MSG_UNITS_LIST_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_LIST_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_LIST_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_JOB_MSG_UNITS_LIST_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_LIST_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_LIST_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_LIST_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_LIST_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_LIST_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_LIST_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD buf_tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_START_ALL_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_START_ALL_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_ALL_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_INFO_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_INFO_CMD buf_tOCTVC1_JOB_MSG_UNITS_INFO_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_INFO_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_INFO_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hPkgSuite */
};

const tOCTVC1_JOB_MSG_UNITS_INFO_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_INFO_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_INFO_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_INFO_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_INFO_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_INFO_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_INFO_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_FIND_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_FIND_CMD buf_tOCTVC1_JOB_MSG_UNITS_FIND_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_FIND_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_FIND_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* szPackageName */
       0, /* szPackageName[0..31] */
   },
   { /* szSuiteName */
       0, /* szSuiteName[0..31] */
   },
   { /* szCaseName */
       0, /* szCaseName[0..31] */
   },
   cOCTVC1_DO_NOT_MODIFY, /* hPackSuite */
   cOCTVC1_DO_NOT_MODIFY  /* ulCaseId */
};

const tOCTVC1_JOB_MSG_UNITS_FIND_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_FIND_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_FIND_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_FIND_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_FIND_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_FIND_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_FIND_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_START_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_START_CMD buf_tOCTVC1_JOB_MSG_UNITS_START_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_START_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_START_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hPkgSuite */
};

const tOCTVC1_JOB_MSG_UNITS_START_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_START_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_START_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_START_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD buf_tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_LIST_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
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

const tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_LIST_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD buf_tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_INFO_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPkgSuite */
   0  /* ulCaseId */
};

const tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_INFO_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD buf_tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_STATS_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPkgSuite */
   0  /* ulCaseId */
};

const tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_STATS_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD buf_tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPkgSuite */
   0, /* ulCaseId */
   cOCTVC1_DO_NOT_MODIFY  /* ulEnableStateFlag */
};

const tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_MODIFY_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD buf_tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_UNITS_START_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0, /* hPkgSuite */
   0, /* ulCaseId */
   { /* ExecParms */
       cOCT_FALSE, /* ulPulseModeFlag */
       { /* szParms */
           0, /* szParms[0..511] */
       }
   }
};

const tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_UNITS_START_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_UNITS_START_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD buf_tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID, /* hRunnerCase */
   { /* Data */
       { /* aulUserData */
           0, /* aulUserData[0] */
           0, /* aulUserData[1] */
           0, /* aulUserData[2] */
           0  /* aulUserData[3] */
       },
       { /* szData */
           0, /* szData[0..511] */
       }
   }
};

const tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_SEND_CASES_DATA_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_STATS_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_STATS_CMD buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_STATS_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_STATS_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCT_FALSE  /* ulResetStatsFlag */
};

const tOCTVC1_JOB_MSG_RUNNER_STATS_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_STATS_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_STATS_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD buf_tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_PAUSE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_PAUSE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD buf_tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_RESUME_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_RESUME_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_RESUME_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD buf_tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_CLEANUP_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_CLEANUP_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* RunnerAddParms */
       0, /* hPkgSuite */
       0, /* ulCaseId */
       { /* ExecParms */
           cOCT_FALSE, /* ulPulseModeFlag */
           { /* szParms */
               0, /* szParms[0..511] */
           }
       }
   }
};

const tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_ADD_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_START_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STOP_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID, /* hRunnerCase */
   1  /* ulPulseCnt */
};

const tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_PULSE_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD buf_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_EXECUTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_EXECUTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_EXECUTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD buf_tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_EXECUTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_EXECUTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_EXECUTE_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_CASES_ERROR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   0  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_CASES_ERROR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CASES_ERROR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_START_CASES_ERROR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hRunnerCase */
};

const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_CASES_ERROR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_REMOVE_ALL_CASES_ERROR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   { /* ObjectCursor */
       0, /* hObject */
       cOCTVC1_OBJECT_CURSOR_ENUM_FIRST  /* ulGetMode */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_LIST_EXECUTOR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID  /* hExecutor */
};

const tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_EXECUTOR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD buf_tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_HANDLE_INVALID, /* hExecutor */
   cOCT_FALSE  /* ulResetStatsFlag */
};

const tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_STATS_EXECUTOR_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   }
};

const tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_INFO_CONFIGURATION_CMD; \
    }


/*--------------------------------------------------------------------------
    tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD
----------------------------------------------------------------------------*/
#ifdef OCTVC1_OPT_DECLARE_DEFAULTS

const tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD buf_tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD =
{
   { /* Header */
       ((sizeof(tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD)<<cOCTVC1_MSG_LENGTH_BIT_OFFSET)&cOCTVC1_MSG_LENGTH_BIT_MASK), /* ulLength */
       0, /* ulTransactionId */
       ((cOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CID<<cOCTVC1_MSG_ID_BIT_OFFSET)&cOCTVC1_MSG_ID_BIT_MASK), /* ul_Type_R_CmdId */
       0, /* ulSessionId */
       0, /* ulReturnCode */
       0  /* ulUserInfo */
   },
   cOCTVC1_DO_NOT_MODIFY, /* ulRunnerCaseLevel */
   cOCTVC1_DO_NOT_MODIFY  /* ulSendStateChangeEvtFlag */
};

const tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD =
    &buf_tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD;

#else /* OCTVC1_OPT_DECLARE_DEFAULTS */
extern const tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD;
#endif /* OCTVC1_OPT_DECLARE_DEFAULTS */

#define mOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD_DEF(pSt) \
    { \
        *pSt = *g_pOctDef_tOCTVC1_JOB_MSG_RUNNER_MODIFY_CONFIGURATION_CMD; \
    }


#ifdef __cplusplus
}
#endif

#endif /* __OCTVC1_JOB_DEFAULT_H__ */

