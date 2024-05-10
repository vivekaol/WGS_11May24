/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_RADIO.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_RADIO_H__
#define __OCTVC1_RADIO_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Radio Standard Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_FREQ_UNIT_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_FREQ_UNIT_ENUM						tOCT_UINT32

#define cOCTVC1_RADIO_FREQ_UNIT_ENUM_HZ						0		 	/* Frequency unit is in hertz. */
#define cOCTVC1_RADIO_FREQ_UNIT_ENUM_KHZ					1		 	/* Frequency unit is in kilohertz. */
#define cOCTVC1_RADIO_FREQ_UNIT_ENUM_MHZ					2		 	/* Frequency unit is in megahertz. */
#define cOCTVC1_RADIO_FREQ_UNIT_ENUM_GHZ					3		 	/* Frequency unit is in gigahertz. */

/*-------------------------------------------------------------------------------------
 	Radio Standard Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_ENUM							tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_ENUM_GSM						0		
#define cOCTVC1_RADIO_STANDARD_ENUM_UMTS					1		
#define cOCTVC1_RADIO_STANDARD_ENUM_LTE						2		
#define cOCTVC1_RADIO_STANDARD_ENUM_CDMA2000				3		
#define cOCTVC1_RADIO_STANDARD_ENUM_NR						4		
#define cOCTVC1_RADIO_STANDARD_ENUM_CUSTOM					5		
#define cOCTVC1_RADIO_STANDARD_ENUM_INVALID					0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard GSM Frequency Band Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM			tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_380		0		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_410		1		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_450		2		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_480		3		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_710		4		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_750		5		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_810		6		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_850		7		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_E_900		8		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_P_900		9		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_R_900		10		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_DCS_1800	11		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_PCS_1900	12		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_LAST		13		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_GSM_ENUM_INVALID	0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard UMTS Frequency Band Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM			tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_1		0		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_2		1		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_3		2		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_4		3		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_5		4		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_6		5		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_7		6		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_8		7		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_9		8		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_10		9		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_11		10		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_12		11		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_13		12		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_14		13		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_15		14		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_16		15		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_17		16		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_18		17		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_19		18		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_20		19		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_21		20		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_22		21		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_23		22		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_24		23		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_25		24		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_26		25		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_32		26		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_33		27		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_34		28		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_35		29		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_36		30		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_37		31		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_38		32		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_39		33		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_40		34		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_2	35		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_4	36		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_5	37		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_6	38		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_7	39		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_10	40		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_12	41		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_13	42		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_14	43		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_19	44		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_25	45		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_26	46		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_ADD_32	47		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_LAST		48		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_UMTS_ENUM_INVALID	0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard LTE Frequency Band Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM			tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_1			0		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_2			1		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_3			2		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_4			3		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_5			4		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_6			5		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_7			6		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_8			7		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_9			8		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_10		9		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_11		10		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_12		11		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_13		12		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_14		13		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_15		14		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_16		15		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_17		16		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_18		17		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_19		18		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_20		19		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_21		20		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_22		21		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_23		22		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_24		23		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_25		24		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_26		25		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_27		26		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_28		27		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_29		28		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_30		29		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_31		30		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_32		31		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_33		32		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_34		33		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_35		34		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_36		35		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_37		36		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_38		37		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_39		38		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_40		39		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_41		40		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_42		41		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_43		42		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_44		43		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_45		44		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_46		45		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_47		46		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_48		47		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_50		48		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_51		49		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_65		50		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_66		51		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_67		52		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_68		53		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_69		54		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_70		55		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_71		56		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_72		57		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_74		58		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_75		59		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_76		60		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_252		61		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_255		62		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_LAST		63		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_LTE_ENUM_INVALID	0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard CDMA2000 Frequency Band Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM			tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_0		0		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_1		1		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_2		2		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_3		3		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_4		4		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_5		5		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_6		6		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_7		7		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_8		8		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_9		9		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_10		10		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_11		11		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_12		12		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_13		13		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_14		14		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_15		15		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_16		16		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_18		18		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_19		19		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_20		20		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_21		21		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_LAST		22		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_CDMA2000_ENUM_INVALID	0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard NR (5G) Frequency Band Identifiers
 	NR spectrum below 6 GHz
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM			tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N1			0		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N2			1		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N3			2		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N4			3		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N5			4		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N6			5		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N7			6		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N8			7		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N9			8		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N10		9		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N11		10		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N12		11		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N13		12		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N14		13		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N15		14		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N16		15		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N17		16		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N18		17		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N19		18		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N20		19		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N21		20		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N22		21		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N23		22		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N24		23		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N25		24		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N26		25		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N27		26		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N28		27		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N29		28		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N30		29		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N31		30		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N32		31		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N33		32		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N34		33		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N35		34		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N36		35		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N37		36		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N38		37		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N39		38		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N40		39		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N41		40		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N42		41		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N43		42		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N44		43		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N45		44		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N46		45		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N47		46		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N48		47		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N49		48		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N50		49		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N51		50		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N52		51		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N53		52		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N54		53		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N55		54		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N56		55		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N57		56		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N58		57		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N59		58		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N60		59		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N61		60		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N62		61		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N63		62		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N64		63		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N65		64		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N66		65		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N67		66		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N68		67		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N69		68		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N70		69		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N71		70		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N72		71		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N73		72		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N74		73		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N75		74		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N76		75		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N77		76		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N78		77		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N79		78		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N80		79		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N81		80		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N82		81		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N83		82		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N84		83		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N85		84		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_N86		85		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_LAST		86		
#define cOCTVC1_RADIO_STANDARD_FREQ_BAND_NR_ENUM_INVALID	0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard NR (5G) Frequency RF1 SS-Block Pattren type
 	Required for GSCN and RN-RFCN calculation
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM			tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_A		0		
#define cOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_B		1		
#define cOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_C		2		
#define cOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_LAST		3		
#define cOCTVC1_RADIO_STANDARD_NR_SSB_PATTERN_ENUM_INVALID	0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard NR (5G) Frequency RF1 subcarrier spacing
 	Required for GSCN and RN-RFCN calculation
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_NR_SCS_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_NR_SCS_ENUM					tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_15KHz			0		
#define cOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_30KHz			1		
#define cOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_60KHz			2		
#define cOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_LAST				3		
#define cOCTVC1_RADIO_STANDARD_NR_SCS_ENUM_INVALID			0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	Radio Standard Frequency Band Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID

 Members:
	ulStandard
 		Radio standard
	ulBandNumber
		Default:	0
 		Band number value.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_STANDARD_ENUM	ulStandard;
	tOCT_UINT32					ulBandNumber;

} tOCTVC1_RADIO_STANDARD_FREQ_BAND_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_FREQUENCY_VALUE

 Members:
	ulUnit
		Default:	cOCTVC1_RADIO_FREQ_UNIT_ENUM_KHZ
 		Frequency unity: Hz,Kz,Mz
	ulValue
		Default:	0
 		Frequency value.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_RADIO_FREQ_UNIT_ENUM	ulUnit;
	tOCT_UINT32						ulValue;

} tOCTVC1_RADIO_FREQUENCY_VALUE;

/*-------------------------------------------------------------------------------------
 	Radio Configiguration Script Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_CONFIG_SCRIPT_TYPE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_CONFIG_SCRIPT_TYPE_ENUM				tOCT_UINT32

#define cOCTVC1_RADIO_CONFIG_SCRIPT_TYPE_ENUM_INVALID		0		
#define cOCTVC1_RADIO_CONFIG_SCRIPT_TYPE_ENUM_TEXT			1		
#define cOCTVC1_RADIO_CONFIG_SCRIPT_TYPE_ENUM_BIN			2		

/*-------------------------------------------------------------------------------------
 	Radio Direction Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_ID_DIRECTION_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_ID_DIRECTION_ENUM						tOCT_UINT32

#define cOCTVC1_RADIO_ID_DIRECTION_ENUM_INVALID				0		
#define cOCTVC1_RADIO_ID_DIRECTION_ENUM_DOWNLINK			1		
#define cOCTVC1_RADIO_ID_DIRECTION_ENUM_UPLINK				2		

/*-------------------------------------------------------------------------------------
 	Radio Standard Bandwidth Identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM				tOCT_UINT32

#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_1P4MHZ		0		
#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_3MHZ			1		
#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_5MHZ			2		
#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_10MHZ			3		
#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_15MHZ			4		
#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_20MHZ			5		
#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_LAST			6		
#define cOCTVC1_RADIO_STANDARD_BANDWIDTH_ENUM_INVALID		0xCAFEDECA	

/*-------------------------------------------------------------------------------------
 	RX Gain control identifier
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM				tOCT_UINT32

#define cOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM_MGC			0		 	/* Manual Gain Control */
#define cOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM_AGC_FAST_ATK	1		 	/* Automatic Gain Control */
#define cOCTVC1_RADIO_RX_GAIN_CTRL_MODE_ENUM_AGC_SLOW_ATK	2		 	/* Automatic Gain Control */

/*-------------------------------------------------------------------------------------
 	Radio duplexing mode identifiers
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM				tOCT_UINT32

#define cOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM_INVALID		0		
#define cOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM_FDD			1		
#define cOCTVC1_RADIO_ID_DUPLEXING_MODE_ENUM_TDD			2		


#endif /* __OCTVC1_RADIO_H__ */

