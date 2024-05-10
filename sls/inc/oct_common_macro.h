/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_common_macro.h

Copyright (c) 2018 Octasic Inc. All rights reserved.
    
Description:

    Utility macro definitions.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.00-B3601 (2018/10/18)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCT_COMMON_MACRO_H__
#define __OCT_COMMON_MACRO_H__

#ifdef __cplusplus
extern "C" {                                    /* Assume C declarations for C++ */
#endif /* __cplusplus */

#include "octdev_macro.h"
#include "octvc1/octvc1_macro.h"

/***************************  MACRO DEFINITIONS  *****************************/

/*****************************************************************************\
 * ARITHMETIC MACROS
\*****************************************************************************/

/*
 * Computes the maximum of two numeric values.
 */
#define mOCT_MAX(a, b) ((a) > (b) ? (a) : (b))

/*
 * Computes the minimum of two numeric values.
 */
#define mOCT_MIN(a, b) ((a) < (b) ? (a) : (b))

/*****************************************************************************\
 * CONVERSION MACROS
\*****************************************************************************/

/*
 * Converts a 64-bit integer to a string.
 */
#ifdef WIN32
#define mOCT_UINT64TOA(pszBuffer, aulValue) \
    sprintf(pszBuffer, "%I64u", \
            (unsigned __int64)(((unsigned __int64)aulValue[0]) << 32) | ((tOCT_UINT32)aulValue[1]))
#else
#define mOCT_UINT64TOA(pszBuffer, aulValue) \
    sprintf(pszBuffer, "%llu", \
            (unsigned long long)(((unsigned long long)aulValue[0]) << 32) | ((tOCT_UINT32)aulValue[1]))
#endif

/*****************************************************************************\
 * MISCELLANEOUS MACROS
\*****************************************************************************/

/*
 * Prints application version information.
 */
#define mOCT_PRINT_APP_VERSION_INFO(f_pszApplicationName, ulMajor, ulMinor, ulMaintenance) \
    printf("%s - %02d.%02d.%02d Built on %s at %s\n%s\n\n", \
           f_pszApplicationName, \
           ulMajor, \
           ulMinor, \
           ulMaintenance, \
           __DATE__, \
           __TIME__, \
           "Copyright (c) 2018 Octasic Inc. All rights reserved.")

#ifdef __cplusplus
}                                               /* End of extern "C" { */
#endif /* __cplusplus */

#endif /* __OCT_COMMON_MACRO_H__ */

