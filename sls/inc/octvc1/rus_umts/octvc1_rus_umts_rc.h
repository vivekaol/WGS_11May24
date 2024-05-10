/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_UMTS_RC.h

Copyright (c) 2015 Octasic Inc. All rights reserved.

Description: Contains the return codes for the RUS_UMTS API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-02.08.00-B1331 (2015/12/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_RUS_UMTS_RC_H__
#define OCTVC1_RUS_UMTS_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"
#include "octvc1_rus_umts_base.h"

/****************************************************************************
	RUS_UMTS return codes
 ****************************************************************************/
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_OPEN_NO_MORE								 ( 0x0020 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_REQUIRE_RFFI_HANDLE							 ( 0x0021 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_ALREADY_STARTED								 ( 0x0022 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_ALREADY_STOPPED								 ( 0x0023 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_RFFI_STANDARD_INVALID						 ( 0x0024 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_RFFI_REQUIRE_UPLINK_UARFCN					 ( 0x0025 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_DCH_DEC_MUST_BE_STARTED						 ( 0x0026 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_DCH_DEC_INVALID_DPDCH_SLOTFORMAT			 ( 0x0027 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_DCH_DEC_INVALID_DPDCH_CHANNELIZATIONCODE	 ( 0x0028 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_DCH_DEC_INVALID_DPCCH_SLOTFORMAT			 ( 0x0029 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_DCH_DEC_MONITOR_RATE_OUT_OF_RANGE			 ( 0x002A + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_DCH_DEC_ITERATION_SEARCH_OUT_OF_RANGE		 ( 0x002B + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UPLK_UE_DCH_DEC_DPCCH_SCRAMBLING_CODE_OUT_OF_RANGE	 ( 0x002C + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_DNLK_NODEB_OPEN_NO_MORE								 ( 0x0030 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_DNLK_NODEB_REQUIRE_RFFI_HANDLE						 ( 0x0031 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_DNLK_NODEB_PRIMARY_SCR_INVALID						 ( 0x0032 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_DNLK_NODEB_RFFI_REQUIRE_DOWNLINK_UARFCN				 ( 0x0033 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_DNLK_NODEB_RFFI_STANDARD_INVALID					 ( 0x0034 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_USG_NOT_ADD_TRANSMITTER								 ( 0x0040 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_USSMUE_MAX_DCH										 ( 0x0050 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_USSMUE_INVALID_DCHID								 ( 0x0051 + cOCTVC1_RUS_UMTS_RC_BASE )
#define cOCTVC1_RUS_UMTS_RC_UMNB_NOT_ADD_RECEIVER								 ( 0x0060 + cOCTVC1_RUS_UMTS_RC_BASE )

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_RUS_UMTS_AUTO_VALIDATE_RC_BASE									 ( 0xF000 + cOCTVC1_RUS_UMTS_RC_BASE )


#endif /* OCTVC1_RUS_UMTS_RC_H__ */

