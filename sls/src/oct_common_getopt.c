/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_common_getopt.c

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description:

  Gets options from the command line argument list.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.00-B3601 (2018/10/18)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <string.h>

/* Octasic applications' common header files */
#include "../inc/oct_common_getopt.h"

#ifdef __cplusplus
extern "C" {                                    /* Assume C declarations for C++ */
#endif /* __cplusplus */

/***************************  GLOBAL VARIABLES  ******************************/

char *optarg  = NULL;
int  optopt   = 0;
int  optind   = 1;
int  opterr   = 1;
int  optreset = 1;

/***************************  PUBLIC FUNCTIONS  ******************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctGetOpt

Description:    Incrementally parses a command line argument list argv and
                returns the next known option character. An option character
                is known if it has been specified in the string of accepted
                option characters, optstring.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

int OctGetOpt(int argc, char * const *argv, const char *optstring)
{
    unsigned long arglen;
    char          *optstringptr;
    static char   *option;
    static int    optmore;

    if (optreset)
    {
        optarg   = NULL;
        optind   = 1;
        optopt   = 0;
        optreset = 0;
        optmore  = 0;
    }

    if ((optind == argc) || ('-' != argv[optind][0]))
    {
        /*
         * Argument list is exhausted.
         */
        return -1;
    }

    if (0 == optmore)
    {
        option  = argv[optind];
        optmore = 1;
    }
    option++;

    if ((arglen = strlen(option)) != 0)
    {
        /*
         * The interpretation of options in the argument list may be canceled
         * by the option '--' (double dash) which causes OctGetOpt()
         * to signal the end of argument processing and returns -1.
         */
        if ('-' == *option)
        {
            return -1;
        }

        if (NULL == (optstringptr = strchr(optstring, *option)))
        {
            /*
             * A non-recognized option is encountered.
             */
            if (opterr)
            {
                fprintf(stderr, "Error: illegal option -- '%c'\n", *option);
				optind++;
            }
			else
			{
				/* May scan for specific option try to place to next '-' */
				optind++;
				while(optind < argc)
				{
					if('-' == argv[optind][0])
					{
						optmore = 0;
						break;
					}
					else
						optind++;
				}
			}
            return '?';
        }

        if ((':' != optstringptr[1]) && ('\0' == *(option + 1)))
        {
            optind++;
            optmore = 0;
        }

        if (':' == optstringptr[1])
        {
            if (arglen > 1)
            {
                /*
                 * The parameter contains the following elements:
                 * option, and option argument.
                 */
                optarg = option + 1;
            }
            else
            {
                if (++optind >= argc)
                {
                    /*
                     * The OctGetOpt() function detects a missing
                     * option argument, then it writes an error message to the
                     * stderr an returns '?'. Setting opterr to a zero will
                     * disable these error messages. If optstring has a leading
                     * ':' then a missing option argument cause a ':' to be
                     * returned in addition to suppressing any error messages.
                     */
                    if (':' == optstring[0])
                    {
                        return ':';
                    }

                    if (opterr)
                    {
                        fprintf(stderr, "Error: option requires an argument -- %c\n", *option);
                    }

                    return '?';
                }

                optarg = argv[optind];
            }

            optind++;
            optmore = 0;
        }
    }
    else
    {
        /*
         * A single '-' may be specified as a character in optstring, however
         * it should never have an argument associated with it. This allows
         * OctGetOpt() to be used with programs that expect '-' as an
         * option flag. This practice is wrong, and should not be used in any
         * current development. It is provided for backward compatibility only.
         * By default, a single dash causes OctGetOpt() to return -1.
         */
        if (NULL == (optstringptr = strchr(optstring, argv[optind][0])))
        {
            return -1;
        }

        option = argv[optind];
        optind++;
    }

    return (optopt = *option);
}

#ifdef __cplusplus
}                                               /* End of extern "C" { */
#endif /* __cplusplus */

