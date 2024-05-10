/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LTE_LIC.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: Contains the license ids for the LTE API.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_LTE_APP-04.03.00-B3607 (2019/04/16)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_LTE_LIC_H__
#define OCTVC1_LTE_LIC_H__

#include "octvc1_lte_base.h"

/****************************************************************************
	LTE license ids
 ****************************************************************************/
#define cOCTVC1_LTE_LIC_FDD_ENABLE							 ( 0x0001 + (cOCTVC1_LTE_UID << 16) + ( 0x1 << 24 )  )
#define cOCTVC1_LTE_LIC_TDD_ENABLE							 ( 0x0002 + (cOCTVC1_LTE_UID << 16) )
#define cOCTVC1_LTE_LIC_TDD_BASS_ENABLE						 ( 0x0003 + (cOCTVC1_LTE_UID << 16) )

/****************************************************************************
	RF_BAND license ids
 ****************************************************************************/
#define cOCTVC1_LTE_RF_BAND_LIC_BASE						 ( 0x0100 + (cOCTVC1_LTE_UID << 16) )

#define cOCTVC1_LTE_LIC_RF_BAND_ALL_ENABLE					 ( 0x0000 + cOCTVC1_LTE_RF_BAND_LIC_BASE + ( 0x1 << 24 )  )
#define cOCTVC1_LTE_LIC_RF_BAND_1_ENABLE					 ( 0x0001 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_2_ENABLE					 ( 0x0002 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_3_ENABLE					 ( 0x0003 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_4_ENABLE					 ( 0x0004 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_5_ENABLE					 ( 0x0005 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_6_ENABLE					 ( 0x0006 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_7_ENABLE					 ( 0x0007 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_8_ENABLE					 ( 0x0008 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_9_ENABLE					 ( 0x0009 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_10_ENABLE					 ( 0x000a + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_11_ENABLE					 ( 0x000b + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_12_ENABLE					 ( 0x000c + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_13_ENABLE					 ( 0x000d + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_14_ENABLE					 ( 0x000e + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_15_ENABLE					 ( 0x000f + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_16_ENABLE					 ( 0x0010 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_17_ENABLE					 ( 0x0011 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_18_ENABLE					 ( 0x0012 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_19_ENABLE					 ( 0x0013 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_20_ENABLE					 ( 0x0014 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_21_ENABLE					 ( 0x0015 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_22_ENABLE					 ( 0x0016 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_23_ENABLE					 ( 0x0017 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_24_ENABLE					 ( 0x0018 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_25_ENABLE					 ( 0x0019 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_26_ENABLE					 ( 0x001A + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_27_ENABLE					 ( 0x001B + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_28_ENABLE					 ( 0x001C + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_29_ENABLE					 ( 0x001d + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_30_ENABLE					 ( 0x001e + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_31_ENABLE					 ( 0x001f + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_32_ENABLE					 ( 0x0020 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_33_ENABLE					 ( 0x0021 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_34_ENABLE					 ( 0x0022 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_35_ENABLE					 ( 0x0023 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_36_ENABLE					 ( 0x0024 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_37_ENABLE					 ( 0x0025 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_38_ENABLE					 ( 0x0026 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_39_ENABLE					 ( 0x0027 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_40_ENABLE					 ( 0x0028 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_41_ENABLE					 ( 0x0029 + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_42_ENABLE					 ( 0x002A + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_43_ENABLE					 ( 0x002B + cOCTVC1_LTE_RF_BAND_LIC_BASE )
#define cOCTVC1_LTE_LIC_RF_BAND_44_ENABLE					 ( 0x002C + cOCTVC1_LTE_RF_BAND_LIC_BASE )

#endif /* OCTVC1_LTE_LIC_H__ */

