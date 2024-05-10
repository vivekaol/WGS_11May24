/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_GSM_LIC.h

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.

Description: Contains the license ids for the GSM API.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef OCTVC1_GSM_LIC_H__
#define OCTVC1_GSM_LIC_H__

#include "octvc1_gsm_base.h"

/****************************************************************************
	GSM license ids
 ****************************************************************************/
#define cOCTVC1_GSM_LIC_RF_BAND_ALL_ENABLE					 ( 0x0001 + (cOCTVC1_GSM_UID << 16) + ( 0x1 << 24 )  )
#define cOCTVC1_GSM_LIC_RF_BAND_410_ENABLE					 ( 0x0002 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_450_ENABLE					 ( 0x0003 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_480_ENABLE					 ( 0x0004 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_710_ENABLE					 ( 0x0005 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_750_ENABLE					 ( 0x0006 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_810_ENABLE					 ( 0x0007 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_850_ENABLE					 ( 0x0008 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_900_ENABLE					 ( 0x0009 + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_1800_ENABLE					 ( 0x000A + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RF_BAND_1900_ENABLE					 ( 0x000B + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_GPRS_EDGE_ENABLE					 ( 0x000C + (cOCTVC1_GSM_UID << 16) + ( 0x1 << 24 )  )
#define cOCTVC1_GSM_LIC_MULTI_TRX_ENABLE					 ( 0x000D + (cOCTVC1_GSM_UID << 16) )
#define cOCTVC1_GSM_LIC_RAW_DATA_ENABLE						 ( 0x000E + (cOCTVC1_GSM_UID << 16) )

#endif /* OCTVC1_GSM_LIC_H__ */

