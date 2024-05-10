/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_common_getopt.h

Copyright (c) 2017 Octasic Inc. All rights reserved.
    
Description:

     The OctGetOpt() function incrementally parses a command line
     argument list argv and returns the next known option character. An
     option character is known if it has been specified in the string of
     accepted option characters, optstring.

     The option string optstring may contain the following elements: individu-
     al characters, and characters followed by a colon to indicate an option
     argument is to follow. For example, an option string "x" recognizes an
     option "-x", and an option string "x:" recognizes an option and argu-
     ment "-x argument". It does not matter to OctGetOpt() if a
     following argument has leading white space.

     On return from OctGetOpt(), optarg points to an option argument,
     if it is anticipated, and the variable optind contains the index to the
     next argv argument for a subsequent call to OctGetOpt(). The
     variable optopt saves the last known option character returned by
     OctGetOpt().

     The variable opterr and optind are both initialized to 1. The optind
     variable may be set to another value before a set of calls to
     OctGetOpt() in order to skip over more or less argv entries.

     In order to use OctGetOpt() to evaluate multiple sets of
     arguments, or to evaluate a single set of arguments multiple times, the
     variable optreset must be set to 1 before the second and each additional
     set of calls to OctGetOpt(), and the variable optind must be
     reinitialized.

     The OctGetOpt() function returns -1 when the argument list is
     exhausted, or '?' if a non-recognized option is encountered. The
     interpretation of options in the argument list may be canceled by the
     option '--' (double dash) which causes OctGetOpt() to signal the
     end of argument processing and returns -1. When all options have been
     processed (i.e., up to the first non-option argument),
     OctGetOpt() returns -1.

Diagnostics

     If the OctGetOpt() function encounters a character not found in
     the string optarg or detects a missing option argument it writes an error
     message to the stderr and returns '?'. Setting opterr to a zero will
     disable these error messages.  If optstring has a leading ':' then a
     missing option argument causes a ':' to be returned in addition to
     suppressing any error messages.

     Option arguments are allowed to begin with "-"; this is reasonable but
     reduces the amount of error checking possible.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-04.07.01-B3028 (2017/02/27)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCT_COMMON_GETOPT_H__
#define __OCT_COMMON_GETOPT_H__

#ifdef __cplusplus
extern "C" {                                    /* Assume C declarations for C++ */
#endif /* __cplusplus */

/***************************  GLOBAL VARIABLES  ******************************/

/*
 * When OctGetOpt() finds an option that takes an argument, the
 * argument value is returned here.
 */
extern char *optarg;

/*
 * Index in argv of the next element to be scanned.
 * This is used for communication to and from the caller and for
 * communication between successive calls to OctGetOpt().
 */
extern int optind;

/*
 * The variable optopt saves the last known option character returned by
 * OctGetOpt().
 */
extern int optopt;

/*
 * Store zero here to inhibit the error message OctGetOpt() prints
 * for unrecognized options.
 */
extern int opterr;

/*
 * The optreset variable was added to make it possible to call
 * OctGetOpt() multiple times.
 */
extern int optreset;

/***************************  FUNCTION PROTOTYPES  ***************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctGetOpt

Description:    Incrementally parses a command line argument list argv and
                returns the next known option character. An option character
                is known if it has been specified in the string of accepted
                option characters, optstring.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

int OctGetOpt(int argc, char * const *argv, const char *optstring);

#ifdef __cplusplus
}                                               /* End of extern "C" { */
#endif /* __cplusplus */

#endif /* __OCT_COMMON_GETOPT_H__ */

