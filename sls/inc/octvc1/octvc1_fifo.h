/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_FIFO.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_FIFO_H__
#define __OCTVC1_FIFO_H__


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Control process FIFO-ID definition
 	Deprecated should use cOCTVC1_FIFO_ID_CONTROL
-------------------------------------------------------------------------------------*/

#define cOCTVC1_FIFO_ID_MGW_CONTROL							0x00000000	

/*-------------------------------------------------------------------------------------
 	Control process _FIFO-ID definition
-------------------------------------------------------------------------------------*/

#define cOCTVC1_FIFO_ID_CONTROL								0x00000000	

/*-------------------------------------------------------------------------------------
 	Invalid _FIFO-ID
-------------------------------------------------------------------------------------*/

#define cOCTVC1_FIFO_ID_INVALID								0xFFFFFFFF	

#endif /* __OCTVC1_FIFO_H__ */

