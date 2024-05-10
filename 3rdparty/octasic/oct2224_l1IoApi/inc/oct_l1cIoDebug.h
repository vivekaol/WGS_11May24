/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_l1cIoDebug.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control API IO Debug print routines

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* Dependencies ---------------------------------------------------------- */

/* Constants ------------------------------------------------------------- */

extern unsigned int debugLevel;

/* Macros ---------------------------------------------------------------- */

/* The following #define enables to pre-processor to strip out debug
 * messages entirely.  The optional inclusion is handled via the Makefile.
 */
#if DEBUG
#define DEBUG_PRINTF debugPrintf
#else
#define DEBUG_PRINTF(...)
#endif

/* Types ----------------------------------------------------------------- */

enum
{
  DEBUG_NONE,
  DEBUG_ERROR,
  DEBUG_TRACE1,
  DEBUG_TRACE2,
  DEBUG_TRACE3,
  DEBUG_TRACE4,
  DEBUG_TRACE5
};

/* Functions ------------------------------------------------------------- */

void setDebugLevel(unsigned int level);

void debugPrintf(unsigned int level,
		 const char *module,
		 const char *format,
		 ...);

/* End of $RCSfile: l1apiDebug.h,v $ */
