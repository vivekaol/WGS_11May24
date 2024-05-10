/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RUS_GSM_RC.h

Copyright (c) 2015 Octasic Inc. All rights reserved.

Description: Contains the return codes for the RUS_GSM API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-02.08.00-B1331 (2015/12/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_RUS_GSM_RC_H__
#define OCTVC1_RUS_GSM_RC_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_base.h"
#include "../octvc1_generic_rc.h"
#include "octvc1_rus_gsm_base.h"

/****************************************************************************
	RUS_GSM return codes
 ****************************************************************************/
#define cOCTVC1_RUS_GSM_RC_GSM_INVALID_MSID							 ( 0x0001 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_DNLK_BS_OPEN_NO_MORE						 ( 0x0010 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_DNLK_BS_REQUIRE_RFFI_HANDLE				 ( 0x0011 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_DNLK_BS_RFFI_REQUIRE_DOWNLINK_UARFCN		 ( 0x0012 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_DNLK_BS_RFFI_STANDARD_INVALID			 ( 0x0013 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_OPEN_NO_MORE						 ( 0x0020 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_REQUIRE_RFFI_HANDLE				 ( 0x0021 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_ALREADY_STARTED					 ( 0x0022 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_ALREADY_STOPPED					 ( 0x0023 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_RFFI_STANDARD_INVALID			 ( 0x0024 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_RFFI_REQUIRE_UPLINK_UARFCN		 ( 0x0025 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_DEC_MUST_BE_STARTED				 ( 0x0026 + cOCTVC1_RUS_GSM_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_DEC_MONITOR_RATE_OUT_OF_RANGE	 ( 0x0027 + cOCTVC1_RUS_GSM_RC_BASE )

/****************************************************************************
	Validate return codes
 ****************************************************************************/
#define cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE						 ( 0xF000 + cOCTVC1_RUS_GSM_RC_BASE )

#define cOCTVC1_RUS_GSM_RC_DNLK_BS_STATS_INVALID_FRAME_NUMBER		 ( 0x1 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_DNLK_BS_STATS_INVALID_USLOT_NUMBER		 ( 0x2 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_DNLK_BS_STATS_INVALID_RTWPD_BM			 ( 0x3 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_PRM_INVALID_CHANNEL_NUMBER		 ( 0x4 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_PRM_INVALID_MEASUREMENT_TIMER	 ( 0x5 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_PRM_INVALID_HOPPING_ENABLE_FLAG	 ( 0x6 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_PRM_INVALID_MA					 ( 0x7 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_PRM_INVALID_MAIO					 ( 0x8 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_PRM_INVALID_HSN					 ( 0x9 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_PRM_INVALID_TSC					 ( 0xA + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_STATS_INVALID_FRAME_NUMBER		 ( 0xB + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_STATS_INVALID_USLOT_NUMBER		 ( 0xC + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_STATS_INVALID_RTWPD_BM			 ( 0xD + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_STATS_INVALID_RSSID_BM			 ( 0xE + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_STATS_INVALID_SNRD_B				 ( 0xF + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )
#define cOCTVC1_RUS_GSM_RC_UPLK_MS_STATS_INVALID_BER				 ( 0x10 + cOCTVC1_RUS_GSM_AUTO_VALIDATE_RC_BASE )

#endif /* OCTVC1_RUS_GSM_RC_H__ */

