/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_3G_NODEB_LIC.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the license ids for the 3G_NODEB API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_3G_NODEB_LIC_H__
#define OCTVC1_3G_NODEB_LIC_H__

#include "octvc1_3g_nodeb_base.h"

/****************************************************************************
	3G_NODEB license ids
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_LIC_HSPA_ENABLE					 ( 0x0001 + (cOCTVC1_3G_NODEB_UID << 16) + ( 0x1 << 24 )  )

/****************************************************************************
	RF_BAND license ids
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE					 ( 0x0100 + (cOCTVC1_3G_NODEB_UID << 16) )

#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ALL_ENABLE				 ( 0x0000 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE + ( 0x1 << 24 )  )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_1_ENABLE				 ( 0x0001 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_2_ENABLE				 ( 0x0002 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_3_ENABLE				 ( 0x0003 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_4_ENABLE				 ( 0x0004 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_5_ENABLE				 ( 0x0005 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_6_ENABLE				 ( 0x0006 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_7_ENABLE				 ( 0x0007 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_8_ENABLE				 ( 0x0008 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_9_ENABLE				 ( 0x0009 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_10_ENABLE				 ( 0x000A + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_11_ENABLE				 ( 0x000B + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_12_ENABLE				 ( 0x000C + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_13_ENABLE				 ( 0x000D + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_14_ENABLE				 ( 0x000E + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_15_ENABLE				 ( 0x000F + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_16_ENABLE				 ( 0x0010 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_17_ENABLE				 ( 0x0011 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_18_ENABLE				 ( 0x0012 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_19_ENABLE				 ( 0x0013 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_20_ENABLE				 ( 0x0014 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_21_ENABLE				 ( 0x0015 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_22_ENABLE				 ( 0x0016 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_23_ENABLE				 ( 0x0017 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_24_ENABLE				 ( 0x0018 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_25_ENABLE				 ( 0x0019 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_26_ENABLE				 ( 0x001A + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_2_ENABLE			 ( 0x001B + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_4_ENABLE			 ( 0x001C + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_5_ENABLE			 ( 0x001D + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_6_ENABLE			 ( 0x001E + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_7_ENABLE			 ( 0x001F + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_10_ENABLE			 ( 0x0020 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_12_ENABLE			 ( 0x0021 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_13_ENABLE			 ( 0x0022 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_14_ENABLE			 ( 0x0023 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_19_ENABLE			 ( 0x0024 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_25_ENABLE			 ( 0x0025 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )
#define cOCTVC1_3G_NODEB_LIC_RF_BAND_ADD_26_ENABLE			 ( 0x0026 + cOCTVC1_3G_NODEB_RF_BAND_LIC_BASE )

/****************************************************************************
	NUM_USERS license ids
 ****************************************************************************/
#define cOCTVC1_3G_NODEB_NUM_USERS_LIC_BASE						 ( 0x0200 + (cOCTVC1_3G_NODEB_UID << 16) )

#define cOCTVC1_3G_NODEB_LIC_NUM_USERS_FULL_CAPACITY_ENABLE		 ( 0x0000 + cOCTVC1_3G_NODEB_NUM_USERS_LIC_BASE + ( 0x1 << 24 )  )
#define cOCTVC1_3G_NODEB_LIC_NUM_USERS_QUARTER_CAPACITY_ENABLE	 ( 0x0001 + cOCTVC1_3G_NODEB_NUM_USERS_LIC_BASE )

#endif /* OCTVC1_3G_NODEB_LIC_H__ */

