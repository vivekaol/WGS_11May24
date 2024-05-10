/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_l1cIoApi.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Input Output APIs Interface Definitions

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _OCT_L1CIOAPI_H
#define _OCT_L1CIOAPI_H

#include "l1capi_typedef.h"
/* Dependencies ---------------------------------------------------------- */

typedef enum			/* L1API error codes */
{
  L1API_NO_ERROR,
  L1API_RAW_ETHERNET,
  L1API_WRONG_PORT_DATA,
  L1API_INTERNAL_BUCKET_OVERFLOW,
  L1API_INVALID_PORT,
  L1API_PORT_NO_DATA,
  L1API_BUFFER_INSUFFICIENT,
  L1API_CONFIG_FILE_ERROR
} L1API_Error_t;

typedef enum			/* L1API port types */
{
  L1API_PORT_NONE,
  L1API_PORT_CPLANE_REQ,
  L1API_PORT_CPLANE_RSP,
  L1API_PORT_UPLANE_DL,
  L1API_PORT_UPLANE_UL,
  L1API_PORT_BFN,
  L1API_PORT_OAM,
} L1API_Port_t;

/* Macros ---------------------------------------------------------------- */

/* Types ----------------------------------------------------------------- */

typedef void *L1API_Handle_t;

/* Functions ------------------------------------------------------------- */

L1API_Error_t L1API_Open(const char *pArgs, L1API_Handle_t *pHandle);
L1API_Error_t L1API_Close(L1API_Handle_t handle);
L1API_Error_t L1API_PollMsg(L1API_Handle_t handle,
			    uint32_t getMask,
			    uint32_t *pSetMask,
			    int32_t timeout);
L1API_Error_t L1API_SendMsg(L1API_Handle_t handle,
			    L1API_Port_t port,
			    uint32_t *pBuf,
			    uint32_t msgLen,
			    uint32_t bufLen);
L1API_Error_t L1API_RecvMsg(L1API_Handle_t handle,
			    L1API_Port_t port,
			    uint32_t *pBuf,
			    uint32_t len,
			    uint32_t *pLen);

#endif

