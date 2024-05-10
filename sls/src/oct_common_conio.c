/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_common_conio.c

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description:

    Utility functions for performing console input and output.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.00-B3601 (2018/10/18)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/***************************  INCLUDE FILES  *********************************/
#include "../inc/octdev_types.h"
#ifndef OCT_ENV_TYPE_WINDOWS
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#else
#include <conio.h>
#endif

/* Octasic applications' common header files */
#include "../include/oct_common_conio.h"

/***************************  PRIVATE FUNCTIONS  ******************************/

#ifndef OCT_ENV_TYPE_WINDOWS
static struct termios old, New;

/* Initialize new terminal i/o settings */
static void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  New = old; /* make new settings same as old settings */
  New.c_lflag &= ~ICANON; /* disable buffered i/o */
  New.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &New); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
static void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}
#endif /*OCT_ENV_TYPE_WINDOWS*/

/***************************  PUBLIC FUNCTIONS  ******************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctKbhit

Description:    Returns a nonzero value if a key has been pressed. Otherwise,
                it returns 0.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

int OctKbhit(void)
{
#ifndef OCT_ENV_TYPE_WINDOWS
    fd_set         readfds;
    struct timeval tv;
    int            rc = 0;

    /*
     * Disable canonical mode (buffered I/O) and local echo.
     */
    initTermios(0);

    /*
     * Watch stdin to see if it has input.
     */
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec  = 0;
    tv.tv_usec = 0;

    if (0 < select(1, &readfds, NULL, NULL, &tv))
    {
        rc = 1;
    }

    /*
     * Restore the former settings.
     */
    resetTermios();

    return rc;
#else /*OCT_ENV_TYPE_WINDOWS*/
    return _kbhit();
#endif /*OCT_ENV_TYPE_WINDOWS*/
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctGetch

Description:    Gets a character from the console without echo.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
int OctGetch(void)
{
#ifndef OCT_ENV_TYPE_WINDOWS
  char ch;
  initTermios(0);
  ch = getchar();
  resetTermios();
  return ch;
#else /*OCT_ENV_TYPE_WINDOWS*/
    return _getch();
#endif /*OCT_ENV_TYPE_WINDOWS*/
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctGetche

Description:    Gets a character from the console with echo.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
int OctGetche(void)
{
#ifndef OCT_ENV_TYPE_WINDOWS
  char ch;
  initTermios(1);
  ch = getchar();
  resetTermios();
  return ch;
#else /*OCT_ENV_TYPE_WINDOWS*/
    return _getch();
#endif /*OCT_ENV_TYPE_WINDOWS*/
}
