/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTDEV_DEVICES.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTDEV_DEVICES_H__
#define __OCTDEV_DEVICES_H__


/*****************************  INCLUDE FILES  *******************************/
#include "octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
	tOCTDEV_DEVICES_TYPE_ENUM : 	Octasic Device type.
-------------------------------------------------------------------------------------*/
#define tOCTDEV_DEVICES_TYPE_ENUM							tOCT_UINT32

#define cOCTDEV_DEVICES_TYPE_ENUM_INVALID					0x0		
#define cOCTDEV_DEVICES_TYPE_ENUM_OCT1010					0x1		
#define cOCTDEV_DEVICES_TYPE_ENUM_OCT2200					0x2		
#define cOCTDEV_DEVICES_TYPE_ENUM_OCT3032					0x3		
#define cOCTDEV_DEVICES_TYPE_ENUM_CPU						0xF		

/*-------------------------------------------------------------------------------------
	tOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM : 	Octasic DSP Core type.
-------------------------------------------------------------------------------------*/
#define tOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM					tOCT_UINT32

#define cOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM_INVALID			0x0		
#define cOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM_OPUS1			0x1		
#define cOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM_OPUS2			0x2		
#define cOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM_OPUS3			0x3		

/*-------------------------------------------------------------------------------------
 	OCT1010 specific definitions.
-------------------------------------------------------------------------------------*/
#define cOCTDEV_DEVICES_OCT1010_MAX_CORE_NUMBER				15		 	/* Maximum number of core in the OCT1010. */
#define cOCTDEV_DEVICES_OCT1010_MAX_VSPMGR_THREADS			12		 	/* Maximum number of VSP Mgr threads that can be started on the OCT1010. */
#define cOCTDEV_DEVICES_OCT1010_CORE_TYPE					cOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM_OPUS1	 	/* Type of DSP Core in the OCT1010. */
#define cOCTDEV_DEVICES_OCT1010_MAX_ETH_PORT_NUMBER			2		 	/* Maximum number of Ethernet port in the OCT1010. */

/*-------------------------------------------------------------------------------------
 	OCT2200 specific definitions.
-------------------------------------------------------------------------------------*/
#define cOCTDEV_DEVICES_OCT2200_MAX_CORE_NUMBER				24		 	/* Maximum number of core in the OCT2200. */
#define cOCTDEV_DEVICES_OCT2200_MAX_VSPMGR_THREADS			21		 	/* Maximum number of VSP Mgr threads that can be started on the OCT2200. */
#define cOCTDEV_DEVICES_OCT2200_CORE_TYPE					cOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM_OPUS2	 	/* Type of DSP Core in the OCT2200. */
#define cOCTDEV_DEVICES_OCT2200_MAX_ETH_PORT_NUMBER			4		 	/* Maximum number of Ethernet port in the OCT2200. */

/*-------------------------------------------------------------------------------------
 	OCT3032 specific definitions.
-------------------------------------------------------------------------------------*/
#define cOCTDEV_DEVICES_OCT3032_MAX_CORE_NUMBER				32		 	/* Maximum number of core in the OCT3032. */
#define cOCTDEV_DEVICES_OCT3032_MAX_VSPMGR_THREADS			29		 	/* Maximum number of VSP Mgr threads that can be started on the OCT3032. */
#define cOCTDEV_DEVICES_OCT3032_CORE_TYPE					cOCTDEV_DEVICES_DSP_CORE_TYPE_ENUM_OPUS3	 	/* Type of DSP Core in the OCT3032. */
#define cOCTDEV_DEVICES_OCT3032_MAX_ETH_PORT_NUMBER			4		 	/* Maximum number of Ethernet port in the OCT3032. */


#endif /* __OCTDEV_DEVICES_H__ */

