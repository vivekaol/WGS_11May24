/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_l1cIoInit.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control API IO interface definitions

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _OCT_L1CIOINIT_H
#define _OCT_L1CIOINIT_H

#include "l1capi_typedef.h"

typedef struct L1C_CONFIG_DB
{
   uint8_t l23SrcMacAddr[6];
   uint8_t l1DstMacAddr[6];
   sint8_t deviceHost[5];
   uint16_t txPwrGain;
   uint16_t rxGain;
}L1C_CONFIG_DB;

#define MAX_L1C_CONFIG_PARAMETERS (20)
extern L1C_CONFIG_DB  g_L1CConfigDB;
uint8_t L1CReadConfigParams();

#endif

