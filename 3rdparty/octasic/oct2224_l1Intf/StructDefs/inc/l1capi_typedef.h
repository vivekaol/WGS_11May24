/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: l1capi_typedef.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control API Typedef

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1CAPI_TYPEDEF_H_
#define _L1CAPI_TYPEDEF_H_
/*************************************************/
/******  basic type definition  ************************/
/*************************************************/
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;
typedef signed int     int32_t;
typedef signed char    sint8_t;
typedef signed short   sint16_t;
typedef signed int     sint32_t;

#ifdef OCT_ENV_TYPE_OPUS
#define SWAP_ENDIAN_16(data) (data)
#define SWAP_ENDIAN_32(data) (data)
#define SWAP_ENDIAN_64(data) (data)
#else
#define SWAP_ENDIAN_16(data) \
    ((((data) & (int)0x00FF) << 8) | \
     (((data) & (int)0xFF00) >> 8))

#define SWAP_ENDIAN_32(data) \
    ((((data) & 0x000000FF) << 24) | \
     (((data) & 0x0000FF00) << 8) | \
     (((data) & 0x00FF0000) >> 8) | \
     (((data) & 0xFF000000) >> 24))

#define SWAP_ENDIAN_64(data) \
    ((((data) & 0x00000000000000FF) << 56) | \
     (((data) & 0x000000000000FF00) << 40) | \
     (((data) & 0x0000000000FF0000) << 24) | \
     (((data) & 0x00000000FF000000) << 8) | \
     (((data) & 0x000000FF00000000) >> 8) | \
     (((data) & 0x0000FF0000000000) >> 24) | \
     (((data) & 0x00FF000000000000) >> 40) | \
     (((data) & 0xFF00000000000000) >> 56))
#endif

#define TSIZEOF(x) ((char*)((x *)0 + 1) - (char *)(x*)0)
#define LVSIZEOF(x) ((char*)(&(x) + 1) - (char*)&(x))

#endif 
