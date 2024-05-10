/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octsamples_string_utils.h

Copyright (c) 2018 Octasic Inc. All rights reserved.
    
Description:

    String utility functions.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: 41797 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTSAMPLES_STRING_UTILS_H__
#define __OCTSAMPLES_STRING_UTILS_H__

#include "octvc1/octvc1_ip.h"
#include "octvc1/octvc1_udp.h"
#include "octvc1/octvc1_handle.h"

#ifdef __cplusplus
extern "C" {                                    /* Assume C declarations for C++ */
#endif /* __cplusplus */

/***************************  FUNCTION PROTOTYPES  ***************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesMacAddr2Str

Description:    Converts a MAC address to a string.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesMacAddr2Str(char             *f_pszMacAddr,
                              const tOCT_UINT8 f_abyMacAddr[6]);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesMacAddr2Str

Description:    Converts a string to aMAC address.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesStr2MacAddr(tOCT_UINT8 f_abyMacAddr[6],
                              const char *f_pszMacAddr);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesIpAddr2Str

Description:    Converts an IP address to a string.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesIpAddr2Str(char                     *f_pszIpAddr,
                             const tOCTVC1_IP_ADDRESS *f_pIpAddr);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesUdpAddr2Str

Description:    Converts an UDP address to a string.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesUdpAddr2Str(char                      *f_pszUdpAddr,
                              const tOCTVC1_UDP_ADDRESS *f_pUdpAddr);



#ifdef __cplusplus
}                                               /* End of extern "C" { */
#endif /* __cplusplus */

#endif /* __OCTSAMPLES_STRING_UTILS_H__ */

