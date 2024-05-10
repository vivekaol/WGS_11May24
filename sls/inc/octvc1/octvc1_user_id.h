/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_USER_ID.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_USER_ID_H__
#define __OCTVC1_USER_ID_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_base.h"
#include "octvc1_module.h"


/************************  COMMON DEFINITIONS  *******************************/

#define cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT					24		 	/* Number of bit the module id is shifted in user id. */

/*-------------------------------------------------------------------------------------
 	Base process user id.
 	Octadf_internal Process user id.
-------------------------------------------------------------------------------------*/
#define tOCTVC1_USER_ID_PROCESS_ENUM						tOCT_UINT32

#define cOCTVC1_USER_ID_PROCESS_ENUM_INVALID				0x00000000	
#define cOCTVC1_USER_ID_PROCESS_ENUM_MAIN_APP				((tOCT_UINT32)((0x00000000)|(cOCTVC1_MODULE_ID_ENUM_MAIN<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_MAIN_ROUTER			((tOCT_UINT32)((0x00000001)|(cOCTVC1_MODULE_ID_ENUM_MAIN<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_BASSC					((tOCT_UINT32)((0x00001000)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_BASSRFFI				((tOCT_UINT32)((0x00001100)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_BASSSYNC				((tOCT_UINT32)((0x00001200)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMC					((tOCT_UINT32)((0x00002000)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMRFFI				((tOCT_UINT32)((0x00002100)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM2GIM				((tOCT_UINT32)((0x00002200)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM2GOM				((tOCT_UINT32)((0x00002210)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM3GCS				((tOCT_UINT32)((0x00002300)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM3GIM0				((tOCT_UINT32)((0x00002310)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM3GIM1				((tOCT_UINT32)((0x00002311)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM3GOM				((tOCT_UINT32)((0x00002320)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM4GCS				((tOCT_UINT32)((0x00002400)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM4GIMCH				((tOCT_UINT32)((0x00002410)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM4GRX				((tOCT_UINT32)((0x00002411)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM4GRXC				((tOCT_UINT32)((0x00002420)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMSA					((tOCT_UINT32)((0x00002500)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMC2KIM				((tOCT_UINT32)((0x00002600)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMC2KOM				((tOCT_UINT32)((0x00002610)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNM5GCS				((tOCT_UINT32)((0x00002700)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_TXRFI					((tOCT_UINT32)((0x00003000)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_RXRFI					((tOCT_UINT32)((0x00003100)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_TEST					((tOCT_UINT32)((0x00004000)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_USSMUEC				((tOCT_UINT32)((0xF0004000)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_USSMUERFFI				((tOCT_UINT32)((0xF0004100)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_USSMUE3GL				((tOCT_UINT32)((0xF0004200)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_USSMUE3GTM				((tOCT_UINT32)((0xF0004300)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_USSMUE2GIM				((tOCT_UINT32)((0xF0004400)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_USSMUE2GOM				((tOCT_UINT32)((0xF0004500)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_USSMUE4GCS				((tOCT_UINT32)((0xF0004600)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_GSM_DL_0				((tOCT_UINT32)((0x00000100)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_GSM_ULIM_0				((tOCT_UINT32)((0x00000200)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_GSM_ULOM_0				((tOCT_UINT32)((0x00000300)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_GSM_SCHED_0			((tOCT_UINT32)((0x00000400)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_GSM_DECOMB				((tOCT_UINT32)((0x00000500)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_GSM_ULEQ				((tOCT_UINT32)((0x00000600)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_GSM_TEST				((tOCT_UINT32)((0x00000700)|(cOCTVC1_MODULE_ID_ENUM_GSM<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_L1C				((tOCT_UINT32)((0x00000100)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_DATA			((tOCT_UINT32)((0x00001000)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_DATA_SLAVE_0	((tOCT_UINT32)((0x00001100)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_DATA_SLAVE_1	((tOCT_UINT32)((0x00001101)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_CTRL			((tOCT_UINT32)((0x00001200)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_CTRL_1			((tOCT_UINT32)((0x00001201)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_CFR				((tOCT_UINT32)((0x00001300)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_RFI_0			((tOCT_UINT32)((0x00001400)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_DL_RFI_1			((tOCT_UINT32)((0x00001401)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_RFI_0			((tOCT_UINT32)((0x00002000)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_RFI_1			((tOCT_UINT32)((0x00002001)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_CH_EST			((tOCT_UINT32)((0x00002100)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_DEMOD_0	((tOCT_UINT32)((0x00002200)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_DEMOD_1	((tOCT_UINT32)((0x00002201)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_DEMOD_2	((tOCT_UINT32)((0x00002202)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_DEMOD_3	((tOCT_UINT32)((0x00002203)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_DEMOD_4	((tOCT_UINT32)((0x00002204)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_DEMOD_5	((tOCT_UINT32)((0x00002205)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_OM_0		((tOCT_UINT32)((0x00002300)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_OM_1		((tOCT_UINT32)((0x00002301)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_OM_2		((tOCT_UINT32)((0x00002302)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUSCH_OM_3		((tOCT_UINT32)((0x00002303)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PRACH			((tOCT_UINT32)((0x00002400)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_PUCCH			((tOCT_UINT32)((0x00002500)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_UL_SRS				((tOCT_UINT32)((0x00002600)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_TDD_BASS			((tOCT_UINT32)((0x00002700)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_LTE_TEST				((tOCT_UINT32)((0x00003000)|(cOCTVC1_MODULE_ID_ENUM_LTE<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	

#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_SCHED				((tOCT_UINT32)((0x00000100)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_L1C				((tOCT_UINT32)((0x00000200)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_RACH			((tOCT_UINT32)((0x00000300)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_0		((tOCT_UINT32)((0x00000400)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_1		((tOCT_UINT32)((0x00000401)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_2		((tOCT_UINT32)((0x00000402)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_3		((tOCT_UINT32)((0x00000403)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_4		((tOCT_UINT32)((0x00000404)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_5		((tOCT_UINT32)((0x00000405)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_6		((tOCT_UINT32)((0x00000406)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_MASTER_7		((tOCT_UINT32)((0x00000407)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_RFI			((tOCT_UINT32)((0x00000500)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULOM_MASTER_0		((tOCT_UINT32)((0x00000600)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULOM_MASTER_1		((tOCT_UINT32)((0x00000601)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_DLIM_MASTER_0		((tOCT_UINT32)((0x00000700)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_DLIM_MASTER_1		((tOCT_UINT32)((0x00000701)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_DLIM_MASTER_2		((tOCT_UINT32)((0x00000702)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_DLIM_MASTER_3		((tOCT_UINT32)((0x00000703)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_DLOM_MASTER		((tOCT_UINT32)((0x00000800)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_RFI				((tOCT_UINT32)((0x00000900)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ETH				((tOCT_UINT32)((0x00000A00)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_HSDLOM			((tOCT_UINT32)((0x00000B00)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_HSDLIM			((tOCT_UINT32)((0x00000C00)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_ULIM_SSE			((tOCT_UINT32)((0x00000D00)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_3G_NODEB_EDCH_ULOM_MASTER	((tOCT_UINT32)((0x00000E00)|(cOCTVC1_MODULE_ID_ENUM_3G_NODEB<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMQUICK_0				((tOCT_UINT32)((0x00003200)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMQUICK_1				((tOCT_UINT32)((0x00003201)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMQUICK_2				((tOCT_UINT32)((0x00003202)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMQUICK_3				((tOCT_UINT32)((0x00003203)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMQUICK_4				((tOCT_UINT32)((0x00003204)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_WNMQUICK_5				((tOCT_UINT32)((0x00003205)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	
#define cOCTVC1_USER_ID_PROCESS_ENUM_TEST					((tOCT_UINT32)((0x00004000)|(cOCTVC1_MODULE_ID_ENUM_RUS<<cOCTVC1_USER_ID_MODULE_ID_BIT_SHIFT)) )	

#endif /* __OCTVC1_USER_ID_H__ */

