/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_BUFFER.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_BUFFER_H__
#define __OCTVC1_BUFFER_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_module.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
	tOCTVC1_BUFFER_FORMAT_ENUM : 	Buffer format
 	Bits[31:16] Reserved
 	Bits[15:12] Specify the API type of a buffer.
 	Bits[11: 0] Specify the content type of a buffer.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_BUFFER_FORMAT_ENUM							tOCT_UINT32

#define cOCTVC1_BUFFER_FORMAT_ENUM_UNKNOWN					0x0000	
#define cOCTVC1_BUFFER_FORMAT_ENUM_MAIN						((tOCT_UINT32)(cOCTVC1_MODULE_ID_ENUM_MAIN<<12) )	

/*-------------------------------------------------------------------------------------
	tOCTVC1_BUFFER_FORMAT_MAIN_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_BUFFER_FORMAT_MAIN_ENUM						tOCTVC1_BUFFER_FORMAT_ENUM

#define cOCTVC1_BUFFER_FORMAT_MAIN_ENUM_PCAP_TRACE			((tOCTVC1_BUFFER_FORMAT_ENUM)(0x0001|cOCTVC1_BUFFER_FORMAT_ENUM_MAIN) )	
#define cOCTVC1_BUFFER_FORMAT_MAIN_ENUM_FILE_SYS			((tOCTVC1_BUFFER_FORMAT_ENUM)(0x0002|cOCTVC1_BUFFER_FORMAT_ENUM_MAIN) )	


#endif /* __OCTVC1_BUFFER_H__ */

