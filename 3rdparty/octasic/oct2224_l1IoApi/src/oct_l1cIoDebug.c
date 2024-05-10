/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_l1cIoDebug.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control L1C I/O API Debug Prints

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* Dependencies ---------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>

static unsigned int g_debugLevel = 0;

/* Functions ------------------------------------------------------------- */

void setDebugLevel(unsigned int level)
{
  g_debugLevel = level;
}

void debugPrintf(unsigned int level,
		 const char *module,
		 const char *format,
		 ...)
{
  /* Only process if debug level is equal/higher to than that requested */
  if (g_debugLevel >= level && format)
  {
    unsigned int hrs, mins, secs, ms;
    struct timespec ts;
    va_list ap;

    /* Get current time */
    assert(clock_gettime(CLOCK_REALTIME, &ts) == 0);

    /* Calculate ms and ns time */
    secs = ts.tv_sec % 60;	/* Convert to seconds */
    mins = (ts.tv_sec / 60) % 60; /* Convert to mins */
    hrs = ts.tv_sec / 3600;	/* Convert to hours */
    ms = (ts.tv_nsec / 1000000L) % 1000; /* Convert nsec to millseconds */

    /* Display generic information (timestamp and module name) */
    printf("%u:%02u:%02u.%03u: %s: ", hrs, mins, secs, ms, module);

    /* Iterate through varargs */
    va_start(ap, format);
    vprintf(format, ap);
    va_end(ap);
  }
}

