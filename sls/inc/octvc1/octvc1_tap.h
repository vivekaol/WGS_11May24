/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_TAP.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_TAP_H__
#define __OCTVC1_TAP_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_stream.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Tap
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_TAP_DIRECTION_ENUM : 	Tap direction.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_TAP_DIRECTION_ENUM							tOCT_UINT32

#define cOCTVC1_TAP_DIRECTION_ENUM_TX						cOCTVC1_STREAM_DIRECTION_ENUM_TO_HOST	
#define cOCTVC1_TAP_DIRECTION_ENUM_RX						cOCTVC1_STREAM_DIRECTION_ENUM_FROM_HOST	

/*-------------------------------------------------------------------------------------
	tOCTVC1_TAP_ID : 	TAP_ID : [ApplicationModuleId|Direction|Index].
 	ModuleId (16bits)-> Application Module Id[tOCTVC1_MODULE_ID_ENUM|index] .
 	Direction -> cOCTVC1_TAP_DIRECTION_ENUM_ .
-------------------------------------------------------------------------------------*/
#define tOCTVC1_TAP_ID										tOCT_UINT32

#define cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT					0x0000FFFF	
#define cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET			16		
#define cOCTVC1_TAP_ID_MASK_MODULE_ID						((tOCT_UINT32)(cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT<<cOCTVC1_TAP_ID_MASK_MODULE_ID_BIT_OFFSET) )	

#define cOCTVC1_TAP_ID_MASK_DIRECTION_BIT					0x000000FF	
#define cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET			8		
#define cOCTVC1_TAP_ID_MASK_DIRECTION						((tOCT_UINT32)(cOCTVC1_TAP_ID_MASK_DIRECTION_BIT<<cOCTVC1_TAP_ID_MASK_DIRECTION_BIT_OFFSET) )	

#define cOCTVC1_TAP_ID_MASK_INDEX_BIT						0x000000FF	
#define cOCTVC1_TAP_ID_MASK_INDEX_BIT_OFFSET				0		
#define cOCTVC1_TAP_ID_MASK_INDEX							((tOCT_UINT32)(cOCTVC1_TAP_ID_MASK_INDEX_BIT<<cOCTVC1_TAP_ID_MASK_INDEX_BIT_OFFSET) )	


#endif /* __OCTVC1_TAP_H__ */

