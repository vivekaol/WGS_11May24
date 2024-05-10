/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_L3_h_H
#define __ed_c_L3_h_H

#include "ed_dynamic.h"
#include "ed_data.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif

#ifndef ED_HAS_ACCESS_LOCATOR
#define ED_HAS_ACCESS_LOCATOR
#endif
#ifndef ED_DOT
#define ED_DOT ->
#endif
#ifndef ED_AMP
#define ED_AMP(a) a
#endif
#define ED_DYNAMIC_DEFAULT 1

#ifdef __cplusplus
extern "C" {
#endif


/* Access member 'spare' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_spare(var) var

/* Access member 'spare' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_spare(var) (&var)

/* Access member 'AutomaticallyInitiatedECall' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_AutomaticallyInitiatedECall(var) var

/* Access member 'AutomaticallyInitiatedECall' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_AutomaticallyInitiatedECall(var) (&var)

/* Access member 'ManuallyInitiatedECall' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_ManuallyInitiatedECall(var) var

/* Access member 'ManuallyInitiatedECall' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_ManuallyInitiatedECall(var) (&var)

/* Access member 'MountainRescue' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_MountainRescue(var) var

/* Access member 'MountainRescue' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_MountainRescue(var) (&var)

/* Access member 'MarineGuard' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_MarineGuard(var) var

/* Access member 'MarineGuard' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_MarineGuard(var) (&var)

/* Access member 'FireBrigade' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_FireBrigade(var) var

/* Access member 'FireBrigade' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_FireBrigade(var) (&var)

/* Access member 'Ambulance' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_Ambulance(var) var

/* Access member 'Ambulance' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_Ambulance(var) (&var)

/* Access member 'Police' of type 'c_ServCategory' as a variable reference */
#define VAR_c_ServCategory_Police(var) var

/* Access member 'Police' of type 'c_ServCategory' as a pointer */
#define PTR_c_ServCategory_Police(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ServCategory {
	ED_LOCATOR AutomaticallyInitiatedECall___LOCATOR; /* QUI2 */
	ED_LOCATOR ManuallyInitiatedECall___LOCATOR; /* QUI2 */
	ED_LOCATOR MountainRescue___LOCATOR; /* QUI2 */
	ED_LOCATOR MarineGuard___LOCATOR; /* QUI2 */
	ED_LOCATOR FireBrigade___LOCATOR; /* QUI2 */
	ED_LOCATOR Ambulance___LOCATOR; /* QUI2 */
	ED_LOCATOR Police___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN AutomaticallyInitiatedECall; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ManuallyInitiatedECall; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MountainRescue; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MarineGuard; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN FireBrigade; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Ambulance; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Police; /* ODY01a *//*GBD01b*/

}	c_ServCategory;
#define INIT_c_ServCategory(sp) ED_RESET_MEM ((sp), sizeof (c_ServCategory))
/*FRK03a*/
void FREE_c_ServCategory(c_ServCategory* sp);

/* Access member 'data' of type 'c_TBCDArray' as a variable reference */
#define VAR_c_TBCDArray_data(var) var

/* Access member 'data' of type 'c_TBCDArray' as a pointer */
#define PTR_c_TBCDArray_data(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TBCDArray {

		ED_LONG* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-19550=EDCore::TDMSequence)  */
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_TBCDArray;
#define INIT_c_TBCDArray(sp) ED_RESET_MEM ((sp), sizeof (c_TBCDArray))
/*FRK02b*/
void FREE_c_TBCDArray (c_TBCDArray* sp);
/* SETITEMS/ADDITEMS commands for type 'c_TBCDArray'. */
int SETITEMS_c_TBCDArray (c_TBCDArray* sequence, int desiredItems);
#define ADDITEMS_c_TBCDArray(sequence, itemsToBeAdded) SETITEMS_c_TBCDArray (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'SysId' of type 'c_SupportedCodec' as a variable reference */
#define VAR_c_SupportedCodec_SysId(var) var

/* Access member 'SysId' of type 'c_SupportedCodec' as a pointer */
#define PTR_c_SupportedCodec_SysId(var) (&var)

/* Access member 'CodecBitmap' of type 'c_SupportedCodec' as a variable reference */
#define VAR_c_SupportedCodec_CodecBitmap(var) var

/* Access member 'CodecBitmap' of type 'c_SupportedCodec' as a pointer */
#define PTR_c_SupportedCodec_CodecBitmap(var) (&var)

/* DEFINITION OF BINARY c_SupportedCodec_CodecBitmap */
typedef struct _c_SupportedCodec_CodecBitmap {
	ED_BYTE* value; /* Variable size; bits needed 64 */
	int usedBits;
} c_SupportedCodec_CodecBitmap;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SupportedCodec_CodecBitmap(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SupportedCodec {
	ED_LOCATOR SysId___LOCATOR; /* QUI2 */
	ED_LOCATOR CodecBitmap___LOCATOR  /*LBD02*/;

	ED_LONG SysId; /* ODY01a *//*GBD01b*/
	c_SupportedCodec_CodecBitmap CodecBitmap; /* Static, variable size; bits needed 64 *//*GBD01b*/

}	c_SupportedCodec;
#define INIT_c_SupportedCodec(sp) ED_RESET_MEM ((sp), sizeof (c_SupportedCodec))
/*FRK03a*/
void FREE_c_SupportedCodec(c_SupportedCodec* sp);

/* Access member 'spare' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_spare(var) var

/* Access member 'spare' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_spare(var) (&var)

/* Access member 'MBMSSessIdIndic' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MBMSSessIdIndic(var) var

/* Access member 'MBMSSessIdIndic' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MBMSSessIdIndic(var) (&var)

/* Access member 'MCCMNCIndic' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MCCMNCIndic(var) var

/* Access member 'MCCMNCIndic' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MCCMNCIndic(var) (&var)

/* Access member 'OddEven' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_OddEven(var) var

/* Access member 'OddEven' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_OddEven(var) (&var)

/* Access member 'IdentityType' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_IdentityType(var) var

/* Access member 'IdentityType' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_IdentityType(var) (&var)

/* Access member 'MBMSServiceID' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MBMSServiceID(var) var

/* Access member 'MBMSServiceID' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MBMSServiceID(var) (&var)

/* Access member 'MCC2' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MCC2(var) var

/* Access member 'MCC2' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MCC1(var) var

/* Access member 'MCC1' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MNC3(var) var

/* Access member 'MNC3' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MCC3(var) var

/* Access member 'MCC3' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MNC2(var) var

/* Access member 'MNC2' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MNC1(var) var

/* Access member 'MNC1' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MNC1(var) (&var)

/* Access member 'MBMSSessionIdentity' of type 'c_MobileId_TMGI' as a variable reference */
#define VAR_c_MobileId_TMGI_MBMSSessionIdentity(var) var

/* Access member 'MBMSSessionIdentity' of type 'c_MobileId_TMGI' as a pointer */
#define PTR_c_MobileId_TMGI_MBMSSessionIdentity(var) (&var)


/*-A----------------------------------*/
typedef struct _c_MobileId_TMGI {
	ED_LOCATOR MBMSSessIdIndic___LOCATOR; /* QUI2 */
	ED_LOCATOR MCCMNCIndic___LOCATOR; /* QUI2 */
	ED_LOCATOR IdentityType___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSServiceID___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSSessionIdentity___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN MBMSSessIdIndic; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MCCMNCIndic; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET IdentityType; /* ODY01a *//*GBD01b*/
	ED_LONG MBMSServiceID; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MBMSSessionIdentity; /* ODY01a *//*GBD01b*/

}	c_MobileId_TMGI;
#define INIT_c_MobileId_TMGI(sp) ED_RESET_MEM ((sp), sizeof (c_MobileId_TMGI))
/*FRK03a*/
void FREE_c_MobileId_TMGI(c_MobileId_TMGI* sp);

/* Access member 'MCC2' of type 'c_Plmn' as a variable reference */
#define VAR_c_Plmn_MCC2(var) var

/* Access member 'MCC2' of type 'c_Plmn' as a pointer */
#define PTR_c_Plmn_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_Plmn' as a variable reference */
#define VAR_c_Plmn_MCC1(var) var

/* Access member 'MCC1' of type 'c_Plmn' as a pointer */
#define PTR_c_Plmn_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_Plmn' as a variable reference */
#define VAR_c_Plmn_MNC3(var) var

/* Access member 'MNC3' of type 'c_Plmn' as a pointer */
#define PTR_c_Plmn_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_Plmn' as a variable reference */
#define VAR_c_Plmn_MCC3(var) var

/* Access member 'MCC3' of type 'c_Plmn' as a pointer */
#define PTR_c_Plmn_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_Plmn' as a variable reference */
#define VAR_c_Plmn_MNC2(var) var

/* Access member 'MNC2' of type 'c_Plmn' as a pointer */
#define PTR_c_Plmn_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_Plmn' as a variable reference */
#define VAR_c_Plmn_MNC1(var) var

/* Access member 'MNC1' of type 'c_Plmn' as a pointer */
#define PTR_c_Plmn_MNC1(var) (&var)


/*-A----------------------------------*/
typedef struct _c_Plmn {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */

	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/

}	c_Plmn;
#define INIT_c_Plmn(sp) ED_RESET_MEM ((sp), sizeof (c_Plmn))
/*FRK03a*/
void FREE_c_Plmn(c_Plmn* sp);

/* Access member 'MCC2' of type 'c_TempMobileNumbers' as a variable reference */
#define VAR_c_TempMobileNumbers_MCC2(var) var

/* Access member 'MCC2' of type 'c_TempMobileNumbers' as a pointer */
#define PTR_c_TempMobileNumbers_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_TempMobileNumbers' as a variable reference */
#define VAR_c_TempMobileNumbers_MCC1(var) var

/* Access member 'MCC1' of type 'c_TempMobileNumbers' as a pointer */
#define PTR_c_TempMobileNumbers_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_TempMobileNumbers' as a variable reference */
#define VAR_c_TempMobileNumbers_MNC3(var) var

/* Access member 'MNC3' of type 'c_TempMobileNumbers' as a pointer */
#define PTR_c_TempMobileNumbers_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_TempMobileNumbers' as a variable reference */
#define VAR_c_TempMobileNumbers_MCC3(var) var

/* Access member 'MCC3' of type 'c_TempMobileNumbers' as a pointer */
#define PTR_c_TempMobileNumbers_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_TempMobileNumbers' as a variable reference */
#define VAR_c_TempMobileNumbers_MNC2(var) var

/* Access member 'MNC2' of type 'c_TempMobileNumbers' as a pointer */
#define PTR_c_TempMobileNumbers_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_TempMobileNumbers' as a variable reference */
#define VAR_c_TempMobileNumbers_MNC1(var) var

/* Access member 'MNC1' of type 'c_TempMobileNumbers' as a pointer */
#define PTR_c_TempMobileNumbers_MNC1(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TempMobileNumbers {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */

	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/

}	c_TempMobileNumbers;
#define INIT_c_TempMobileNumbers(sp) ED_RESET_MEM ((sp), sizeof (c_TempMobileNumbers))
/*FRK03a*/
void FREE_c_TempMobileNumbers(c_TempMobileNumbers* sp);

/* Access member 'data' of type 'c_MobileId_Identity_IdentityDigit' as a variable reference */
#define VAR_c_MobileId_Identity_IdentityDigit_data(var) var

/* Access member 'data' of type 'c_MobileId_Identity_IdentityDigit' as a pointer */
#define PTR_c_MobileId_Identity_IdentityDigit_data(var) (&var)

/* Access member 'IdentityDigit' of type 'c_MobileId_Identity' as a variable reference */
#define VAR_c_MobileId_Identity_IdentityDigit(var) var

/* Access member 'IdentityDigit' of type 'c_MobileId_Identity' as a pointer */
#define PTR_c_MobileId_Identity_IdentityDigit(var) (&var)

/* Access member 'IdentityType' of type 'c_MobileId_Identity' as a variable reference */
#define VAR_c_MobileId_Identity_IdentityType(var) var

/* Access member 'IdentityType' of type 'c_MobileId_Identity' as a pointer */
#define PTR_c_MobileId_Identity_IdentityType(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_MobileId_Identity_IdentityDigit */
typedef struct _c_MobileId_Identity_IdentityDigit {

	ED_LONG* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-19530=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_MobileId_Identity_IdentityDigit;


/*-A----------------------------------*/
typedef struct _c_MobileId_Identity {
	ED_LOCATOR IdentityType___LOCATOR; /* QUI2 */

	c_MobileId_Identity_IdentityDigit IdentityDigit;/*GFB09*//*GBD01b*/
	ED_LONG IdentityType; /* ODY01a *//*GBD01b*/

}	c_MobileId_Identity;
#define INIT_c_MobileId_Identity(sp) ED_RESET_MEM ((sp), sizeof (c_MobileId_Identity))
/*FRK03a*/
void FREE_c_MobileId_Identity(c_MobileId_Identity* sp);

/* Access member 'ServiceCategory' of type 'c_TBCDEmergencyNumber' as a variable reference */
#define VAR_c_TBCDEmergencyNumber_ServiceCategory(var) var

/* Access member 'ServiceCategory' of type 'c_TBCDEmergencyNumber' as a pointer */
#define PTR_c_TBCDEmergencyNumber_ServiceCategory(var) (&var)

/* Access member 'data' of type 'c_TBCDEmergencyNumber_Numbers' as a variable reference */
#define VAR_c_TBCDEmergencyNumber_Numbers_data(var) var

/* Access member 'data' of type 'c_TBCDEmergencyNumber_Numbers' as a pointer */
#define PTR_c_TBCDEmergencyNumber_Numbers_data(var) (&var)

/* Access member 'Numbers' of type 'c_TBCDEmergencyNumber' as a variable reference */
#define VAR_c_TBCDEmergencyNumber_Numbers(var) var

/* Access member 'Numbers' of type 'c_TBCDEmergencyNumber' as a pointer */
#define PTR_c_TBCDEmergencyNumber_Numbers(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_TBCDEmergencyNumber_Numbers */
typedef struct _c_TBCDEmergencyNumber_Numbers {

	ED_OCTET* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-19546=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TBCDEmergencyNumber_Numbers;


/*-A----------------------------------*/
typedef struct _c_TBCDEmergencyNumber {

	c_ServCategory ServiceCategory; /* ODY01a *//*GBD01b*/
	c_TBCDEmergencyNumber_Numbers Numbers;/*GFB09*//*GBD01b*/

}	c_TBCDEmergencyNumber;
#define INIT_c_TBCDEmergencyNumber(sp) ED_RESET_MEM ((sp), sizeof (c_TBCDEmergencyNumber))
/*FRK03a*/
void FREE_c_TBCDEmergencyNumber(c_TBCDEmergencyNumber* sp);

/* Access member 'MaximumSupportedBearers' of type 'c_CallControlCapabil' as a variable reference */
#define VAR_c_CallControlCapabil_MaximumSupportedBearers(var) var

/* Access member 'MaximumSupportedBearers' of type 'c_CallControlCapabil' as a pointer */
#define PTR_c_CallControlCapabil_MaximumSupportedBearers(var) (&var)

/* Access member 'MCAT' of type 'c_CallControlCapabil' as a variable reference */
#define VAR_c_CallControlCapabil_MCAT(var) var

/* Access member 'MCAT' of type 'c_CallControlCapabil' as a pointer */
#define PTR_c_CallControlCapabil_MCAT(var) (&var)

/* Access member 'ENICM' of type 'c_CallControlCapabil' as a variable reference */
#define VAR_c_CallControlCapabil_ENICM(var) var

/* Access member 'ENICM' of type 'c_CallControlCapabil' as a pointer */
#define PTR_c_CallControlCapabil_ENICM(var) (&var)

/* Access member 'PCP' of type 'c_CallControlCapabil' as a variable reference */
#define VAR_c_CallControlCapabil_PCP(var) var

/* Access member 'PCP' of type 'c_CallControlCapabil' as a pointer */
#define PTR_c_CallControlCapabil_PCP(var) (&var)

/* Access member 'DTMF' of type 'c_CallControlCapabil' as a variable reference */
#define VAR_c_CallControlCapabil_DTMF(var) var

/* Access member 'DTMF' of type 'c_CallControlCapabil' as a pointer */
#define PTR_c_CallControlCapabil_DTMF(var) (&var)

/* Access member 'spare2' of type 'c_CallControlCapabil' as a variable reference */
#define VAR_c_CallControlCapabil_spare2(var) var

/* Access member 'spare2' of type 'c_CallControlCapabil' as a pointer */
#define PTR_c_CallControlCapabil_spare2(var) (&var)

/* Access member 'MaximumNumOfBearers' of type 'c_CallControlCapabil' as a variable reference */
#define VAR_c_CallControlCapabil_MaximumNumOfBearers(var) var

/* Access member 'MaximumNumOfBearers' of type 'c_CallControlCapabil' as a pointer */
#define PTR_c_CallControlCapabil_MaximumNumOfBearers(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CallControlCapabil {
	ED_LOCATOR MaximumSupportedBearers___LOCATOR; /* QUI2 */
	ED_LOCATOR MCAT___LOCATOR; /* QUI2 */
	ED_LOCATOR ENICM___LOCATOR; /* QUI2 */
	ED_LOCATOR PCP___LOCATOR; /* QUI2 */
	ED_LOCATOR DTMF___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumNumOfBearers___LOCATOR; /* QUI2 */

	ED_OCTET MaximumSupportedBearers; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MCAT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ENICM; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PCP; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTMF; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET MaximumNumOfBearers; /* ODY01a *//*GBD01b*/

}	c_CallControlCapabil;
#define INIT_c_CallControlCapabil(sp) ED_RESET_MEM ((sp), sizeof (c_CallControlCapabil))
/*FRK03a*/
void FREE_c_CallControlCapabil(c_CallControlCapabil* sp);

/* Access member 'ext' of type 'c_CalledPartySubaddr' as a variable reference */
#define VAR_c_CalledPartySubaddr_ext(var) var

/* Access member 'ext' of type 'c_CalledPartySubaddr' as a pointer */
#define PTR_c_CalledPartySubaddr_ext(var) (&var)

/* Access member 'TypeOfSubaddress' of type 'c_CalledPartySubaddr' as a variable reference */
#define VAR_c_CalledPartySubaddr_TypeOfSubaddress(var) var

/* Access member 'TypeOfSubaddress' of type 'c_CalledPartySubaddr' as a pointer */
#define PTR_c_CalledPartySubaddr_TypeOfSubaddress(var) (&var)

/* Access member 'OddEvenIndicator' of type 'c_CalledPartySubaddr' as a variable reference */
#define VAR_c_CalledPartySubaddr_OddEvenIndicator(var) var

/* Access member 'OddEvenIndicator' of type 'c_CalledPartySubaddr' as a pointer */
#define PTR_c_CalledPartySubaddr_OddEvenIndicator(var) (&var)

/* Access member 'spare' of type 'c_CalledPartySubaddr' as a variable reference */
#define VAR_c_CalledPartySubaddr_spare(var) var

/* Access member 'spare' of type 'c_CalledPartySubaddr' as a pointer */
#define PTR_c_CalledPartySubaddr_spare(var) (&var)

/* Access member 'SubaddressInformation' of type 'c_CalledPartySubaddr' as a variable reference */
#define VAR_c_CalledPartySubaddr_SubaddressInformation(var) var

/* Access member 'SubaddressInformation' of type 'c_CalledPartySubaddr' as a pointer */
#define PTR_c_CalledPartySubaddr_SubaddressInformation(var) (&var)

/* DEFINITION OF BINARY c_CalledPartySubaddr_SubaddressInformation */
typedef struct _c_CalledPartySubaddr_SubaddressInformation {
	ED_BYTE* value; /* Variable size; bits needed 160 */
	int usedBits;
} c_CalledPartySubaddr_SubaddressInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CalledPartySubaddr_SubaddressInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_CalledPartySubaddr {
	ED_LOCATOR TypeOfSubaddress___LOCATOR; /* QUI2 */
	ED_LOCATOR OddEvenIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR SubaddressInformation___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET TypeOfSubaddress; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OddEvenIndicator; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_CalledPartySubaddr_SubaddressInformation SubaddressInformation; /* Static, variable size; bits needed 160 *//*GBD01b*/

}	c_CalledPartySubaddr;
#define INIT_c_CalledPartySubaddr(sp) ED_RESET_MEM ((sp), sizeof (c_CalledPartySubaddr))
/*FRK03a*/
void FREE_c_CalledPartySubaddr(c_CalledPartySubaddr* sp);

/* Access member 'ext' of type 'c_CallingPartySubaddr' as a variable reference */
#define VAR_c_CallingPartySubaddr_ext(var) var

/* Access member 'ext' of type 'c_CallingPartySubaddr' as a pointer */
#define PTR_c_CallingPartySubaddr_ext(var) (&var)

/* Access member 'TypeOfSubaddress' of type 'c_CallingPartySubaddr' as a variable reference */
#define VAR_c_CallingPartySubaddr_TypeOfSubaddress(var) var

/* Access member 'TypeOfSubaddress' of type 'c_CallingPartySubaddr' as a pointer */
#define PTR_c_CallingPartySubaddr_TypeOfSubaddress(var) (&var)

/* Access member 'OddEvenIndicator' of type 'c_CallingPartySubaddr' as a variable reference */
#define VAR_c_CallingPartySubaddr_OddEvenIndicator(var) var

/* Access member 'OddEvenIndicator' of type 'c_CallingPartySubaddr' as a pointer */
#define PTR_c_CallingPartySubaddr_OddEvenIndicator(var) (&var)

/* Access member 'spare' of type 'c_CallingPartySubaddr' as a variable reference */
#define VAR_c_CallingPartySubaddr_spare(var) var

/* Access member 'spare' of type 'c_CallingPartySubaddr' as a pointer */
#define PTR_c_CallingPartySubaddr_spare(var) (&var)

/* Access member 'SubaddressInformation' of type 'c_CallingPartySubaddr' as a variable reference */
#define VAR_c_CallingPartySubaddr_SubaddressInformation(var) var

/* Access member 'SubaddressInformation' of type 'c_CallingPartySubaddr' as a pointer */
#define PTR_c_CallingPartySubaddr_SubaddressInformation(var) (&var)

/* DEFINITION OF BINARY c_CallingPartySubaddr_SubaddressInformation */
typedef struct _c_CallingPartySubaddr_SubaddressInformation {
	ED_BYTE* value; /* Variable size; bits needed 160 */
	int usedBits;
} c_CallingPartySubaddr_SubaddressInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CallingPartySubaddr_SubaddressInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_CallingPartySubaddr {
	ED_LOCATOR TypeOfSubaddress___LOCATOR; /* QUI2 */
	ED_LOCATOR OddEvenIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR SubaddressInformation___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET TypeOfSubaddress; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OddEvenIndicator; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_CallingPartySubaddr_SubaddressInformation SubaddressInformation; /* Static, variable size; bits needed 160 *//*GBD01b*/

}	c_CallingPartySubaddr;
#define INIT_c_CallingPartySubaddr(sp) ED_RESET_MEM ((sp), sizeof (c_CallingPartySubaddr))
/*FRK03a*/
void FREE_c_CallingPartySubaddr(c_CallingPartySubaddr* sp);

/* Access member 'RadioChannelRequirement' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_RadioChannelRequirement(var) var

/* Access member 'RadioChannelRequirement' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_RadioChannelRequirement(var) (&var)

/* Access member 'CodingStd' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_CodingStd(var) var

/* Access member 'CodingStd' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_CodingStd(var) (&var)

/* Access member 'TransferMode' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_TransferMode(var) var

/* Access member 'TransferMode' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_TransferMode(var) (&var)

/* Access member 'InformationTransferCapability' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_InformationTransferCapability(var) var

/* Access member 'InformationTransferCapability' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_InformationTransferCapability(var) (&var)

/* Access member 'Coding1' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Coding1(var) var

/* Access member 'Coding1' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Coding1(var) (&var)

/* Access member 'CTM' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_CTM(var) var

/* Access member 'CTM' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_CTM(var) (&var)

/* Access member 'spare3a' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare3a(var) var

/* Access member 'spare3a' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare3a(var) (&var)

/* Access member 'SpeechVersionIndicator1' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_SpeechVersionIndicator1(var) var

/* Access member 'SpeechVersionIndicator1' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_SpeechVersionIndicator1(var) (&var)

/* Access member 'Coding2' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Coding2(var) var

/* Access member 'Coding2' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Coding2(var) (&var)

/* Access member 'spare3b' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare3b(var) var

/* Access member 'spare3b' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare3b(var) (&var)

/* Access member 'SpeechVersionIndicator2' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_SpeechVersionIndicator2(var) var

/* Access member 'SpeechVersionIndicator2' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_SpeechVersionIndicator2(var) (&var)

/* Access member 'Coding3' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Coding3(var) var

/* Access member 'Coding3' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Coding3(var) (&var)

/* Access member 'spare3c' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare3c(var) var

/* Access member 'spare3c' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare3c(var) (&var)

/* Access member 'SpeechVersionIndicator3' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_SpeechVersionIndicator3(var) var

/* Access member 'SpeechVersionIndicator3' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_SpeechVersionIndicator3(var) (&var)

/* Access member 'Coding4' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Coding4(var) var

/* Access member 'Coding4' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Coding4(var) (&var)

/* Access member 'spare3d' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare3d(var) var

/* Access member 'spare3d' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare3d(var) (&var)

/* Access member 'SpeechVersionIndicator4' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_SpeechVersionIndicator4(var) var

/* Access member 'SpeechVersionIndicator4' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_SpeechVersionIndicator4(var) (&var)

/* Access member 'Compress' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Compress(var) var

/* Access member 'Compress' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Compress(var) (&var)

/* Access member 'Structure' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Structure(var) var

/* Access member 'Structure' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Structure(var) (&var)

/* Access member 'DuplMode' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_DuplMode(var) var

/* Access member 'DuplMode' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_DuplMode(var) (&var)

/* Access member 'Configuration' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Configuration(var) var

/* Access member 'Configuration' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Configuration(var) (&var)

/* Access member 'NIRR' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_NIRR(var) var

/* Access member 'NIRR' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_NIRR(var) (&var)

/* Access member 'Establishment' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Establishment(var) var

/* Access member 'Establishment' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Establishment(var) (&var)

/* Access member 'AccessId' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_AccessId(var) var

/* Access member 'AccessId' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_AccessId(var) (&var)

/* Access member 'RateAdaption' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_RateAdaption(var) var

/* Access member 'RateAdaption' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_RateAdaption(var) (&var)

/* Access member 'SignallingAccessProtocol' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_SignallingAccessProtocol(var) var

/* Access member 'SignallingAccessProtocol' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_SignallingAccessProtocol(var) (&var)

/* Access member 'OtherITC' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_OtherITC(var) var

/* Access member 'OtherITC' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_OtherITC(var) (&var)

/* Access member 'OtherRateAdaption' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_OtherRateAdaption(var) var

/* Access member 'OtherRateAdaption' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_OtherRateAdaption(var) (&var)

/* Access member 'spare5a' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare5a(var) var

/* Access member 'spare5a' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare5a(var) (&var)

/* Access member 'HDR' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_HDR(var) var

/* Access member 'HDR' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_HDR(var) (&var)

/* Access member 'MultiFrame' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_MultiFrame(var) var

/* Access member 'MultiFrame' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_MultiFrame(var) (&var)

/* Access member 'Mode' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Mode(var) var

/* Access member 'Mode' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Mode(var) (&var)

/* Access member 'LLI' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_LLI(var) var

/* Access member 'LLI' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_LLI(var) (&var)

/* Access member 'AssigNorE' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_AssigNorE(var) var

/* Access member 'AssigNorE' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_AssigNorE(var) (&var)

/* Access member 'IbmNeg' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_IbmNeg(var) var

/* Access member 'IbmNeg' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_IbmNeg(var) (&var)

/* Access member 'spare5b' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare5b(var) var

/* Access member 'spare5b' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare5b(var) (&var)

/* Access member 'Layer1ID' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Layer1ID(var) var

/* Access member 'Layer1ID' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Layer1ID(var) (&var)

/* Access member 'UserInfoLayer1Protocol' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_UserInfoLayer1Protocol(var) var

/* Access member 'UserInfoLayer1Protocol' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_UserInfoLayer1Protocol(var) (&var)

/* Access member 'ASync' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_ASync(var) var

/* Access member 'ASync' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_ASync(var) (&var)

/* Access member 'NumbStopBits' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_NumbStopBits(var) var

/* Access member 'NumbStopBits' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_NumbStopBits(var) (&var)

/* Access member 'Negotiation' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Negotiation(var) var

/* Access member 'Negotiation' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Negotiation(var) (&var)

/* Access member 'NumbDataBits' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_NumbDataBits(var) var

/* Access member 'NumbDataBits' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_NumbDataBits(var) (&var)

/* Access member 'UserRate' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_UserRate(var) var

/* Access member 'UserRate' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_UserRate(var) (&var)

/* Access member 'IntermediateRate' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_IntermediateRate(var) var

/* Access member 'IntermediateRate' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_IntermediateRate(var) (&var)

/* Access member 'NICOnTX' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_NICOnTX(var) var

/* Access member 'NICOnTX' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_NICOnTX(var) (&var)

/* Access member 'NICOnRX' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_NICOnRX(var) var

/* Access member 'NICOnRX' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_NICOnRX(var) (&var)

/* Access member 'Parity' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Parity(var) var

/* Access member 'Parity' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Parity(var) (&var)

/* Access member 'ConnectionElement' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_ConnectionElement(var) var

/* Access member 'ConnectionElement' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_ConnectionElement(var) (&var)

/* Access member 'ModemType' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_ModemType(var) var

/* Access member 'ModemType' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_ModemType(var) (&var)

/* Access member 'OtherModemType' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_OtherModemType(var) var

/* Access member 'OtherModemType' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_OtherModemType(var) (&var)

/* Access member 'FixedNetworkUserRate' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_FixedNetworkUserRate(var) var

/* Access member 'FixedNetworkUserRate' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_FixedNetworkUserRate(var) (&var)

/* Access member 'TCH_F14_4_acceptable' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_TCH_F14_4_acceptable(var) var

/* Access member 'TCH_F14_4_acceptable' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_TCH_F14_4_acceptable(var) (&var)

/* Access member 'spare6e' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare6e(var) var

/* Access member 'spare6e' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare6e(var) (&var)

/* Access member 'TCH_F9_6_acceptable' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_TCH_F9_6_acceptable(var) var

/* Access member 'TCH_F9_6_acceptable' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_TCH_F9_6_acceptable(var) (&var)

/* Access member 'TCH_F4_8_acceptable' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_TCH_F4_8_acceptable(var) var

/* Access member 'TCH_F4_8_acceptable' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_TCH_F4_8_acceptable(var) (&var)

/* Access member 'MaxNumberOfTrafficChannels' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_MaxNumberOfTrafficChannels(var) var

/* Access member 'MaxNumberOfTrafficChannels' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_MaxNumberOfTrafficChannels(var) (&var)

/* Access member 'UIMI' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_UIMI(var) var

/* Access member 'UIMI' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_UIMI(var) (&var)

/* Access member 'WantedAirInterfaceUserRate' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_WantedAirInterfaceUserRate(var) var

/* Access member 'WantedAirInterfaceUserRate' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_WantedAirInterfaceUserRate(var) (&var)

/* Access member 'TCH_F28_8_acceptable' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_TCH_F28_8_acceptable(var) var

/* Access member 'TCH_F28_8_acceptable' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_TCH_F28_8_acceptable(var) (&var)

/* Access member 'TCH_F32_0_acceptable' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_TCH_F32_0_acceptable(var) var

/* Access member 'TCH_F32_0_acceptable' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_TCH_F32_0_acceptable(var) (&var)

/* Access member 'TCH_F43_2_acceptable' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_TCH_F43_2_acceptable(var) var

/* Access member 'TCH_F43_2_acceptable' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_TCH_F43_2_acceptable(var) (&var)

/* Access member 'AsymmetryIndication' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_AsymmetryIndication(var) var

/* Access member 'AsymmetryIndication' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_AsymmetryIndication(var) (&var)

/* Access member 'spare6g' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_spare6g(var) var

/* Access member 'spare6g' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_spare6g(var) (&var)

/* Access member 'Layer2ID' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_Layer2ID(var) var

/* Access member 'Layer2ID' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_Layer2ID(var) (&var)

/* Access member 'UserInfoLayer2Protocol' of type 'c_BearerCpblty' as a variable reference */
#define VAR_c_BearerCpblty_UserInfoLayer2Protocol(var) var

/* Access member 'UserInfoLayer2Protocol' of type 'c_BearerCpblty' as a pointer */
#define PTR_c_BearerCpblty_UserInfoLayer2Protocol(var) (&var)


/*-A----------------------------------*/
typedef struct _c_BearerCpblty {
	ED_LOCATOR RadioChannelRequirement___LOCATOR; /* QUI2 */
	ED_LOCATOR CodingStd___LOCATOR; /* QUI2 */
	ED_LOCATOR TransferMode___LOCATOR; /* QUI2 */
	ED_LOCATOR InformationTransferCapability___LOCATOR; /* QUI2 */
	ED_LOCATOR Coding1___LOCATOR; /* QUI2 */
	ED_LOCATOR CTM___LOCATOR; /* QUI2 */
	ED_LOCATOR SpeechVersionIndicator1___LOCATOR; /* QUI2 */
	ED_LOCATOR Coding2___LOCATOR; /* QUI2 */
	ED_LOCATOR SpeechVersionIndicator2___LOCATOR; /* QUI2 */
	ED_LOCATOR Coding3___LOCATOR; /* QUI2 */
	ED_LOCATOR SpeechVersionIndicator3___LOCATOR; /* QUI2 */
	ED_LOCATOR Coding4___LOCATOR; /* QUI2 */
	ED_LOCATOR SpeechVersionIndicator4___LOCATOR; /* QUI2 */
	ED_LOCATOR Compress___LOCATOR; /* QUI2 */
	ED_LOCATOR Structure___LOCATOR; /* QUI2 */
	ED_LOCATOR DuplMode___LOCATOR; /* QUI2 */
	ED_LOCATOR Configuration___LOCATOR; /* QUI2 */
	ED_LOCATOR NIRR___LOCATOR; /* QUI2 */
	ED_LOCATOR Establishment___LOCATOR; /* QUI2 */
	ED_LOCATOR AccessId___LOCATOR; /* QUI2 */
	ED_LOCATOR RateAdaption___LOCATOR; /* QUI2 */
	ED_LOCATOR SignallingAccessProtocol___LOCATOR; /* QUI2 */
	ED_LOCATOR OtherITC___LOCATOR; /* QUI2 */
	ED_LOCATOR OtherRateAdaption___LOCATOR; /* QUI2 */
	ED_LOCATOR HDR___LOCATOR; /* QUI2 */
	ED_LOCATOR MultiFrame___LOCATOR; /* QUI2 */
	ED_LOCATOR Mode___LOCATOR; /* QUI2 */
	ED_LOCATOR LLI___LOCATOR; /* QUI2 */
	ED_LOCATOR AssigNorE___LOCATOR; /* QUI2 */
	ED_LOCATOR IbmNeg___LOCATOR; /* QUI2 */
	ED_LOCATOR Layer1ID___LOCATOR; /* QUI2 */
	ED_LOCATOR UserInfoLayer1Protocol___LOCATOR; /* QUI2 */
	ED_LOCATOR ASync___LOCATOR; /* QUI2 */
	ED_LOCATOR NumbStopBits___LOCATOR; /* QUI2 */
	ED_LOCATOR Negotiation___LOCATOR; /* QUI2 */
	ED_LOCATOR NumbDataBits___LOCATOR; /* QUI2 */
	ED_LOCATOR UserRate___LOCATOR; /* QUI2 */
	ED_LOCATOR IntermediateRate___LOCATOR; /* QUI2 */
	ED_LOCATOR NICOnTX___LOCATOR; /* QUI2 */
	ED_LOCATOR NICOnRX___LOCATOR; /* QUI2 */
	ED_LOCATOR Parity___LOCATOR; /* QUI2 */
	ED_LOCATOR ConnectionElement___LOCATOR; /* QUI2 */
	ED_LOCATOR ModemType___LOCATOR; /* QUI2 */
	ED_LOCATOR OtherModemType___LOCATOR; /* QUI2 */
	ED_LOCATOR FixedNetworkUserRate___LOCATOR; /* QUI2 */
	ED_LOCATOR TCH_F14_4_acceptable___LOCATOR; /* QUI2 */
	ED_LOCATOR TCH_F9_6_acceptable___LOCATOR; /* QUI2 */
	ED_LOCATOR TCH_F4_8_acceptable___LOCATOR; /* QUI2 */
	ED_LOCATOR MaxNumberOfTrafficChannels___LOCATOR; /* QUI2 */
	ED_LOCATOR UIMI___LOCATOR; /* QUI2 */
	ED_LOCATOR WantedAirInterfaceUserRate___LOCATOR; /* QUI2 */
	ED_LOCATOR TCH_F28_8_acceptable___LOCATOR; /* QUI2 */
	ED_LOCATOR TCH_F32_0_acceptable___LOCATOR; /* QUI2 */
	ED_LOCATOR TCH_F43_2_acceptable___LOCATOR; /* QUI2 */
	ED_LOCATOR AsymmetryIndication___LOCATOR; /* QUI2 */
	ED_LOCATOR UserInfoLayer2Protocol___LOCATOR; /* QUI2 */

	ED_OCTET RadioChannelRequirement; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CodingStd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TransferMode; /* ODY01a *//*GBD01b*/
	ED_OCTET InformationTransferCapability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding1_Present;
	ED_BOOLEAN CTM; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET SpeechVersionIndicator1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding2_Present;
	/*GBD01b*/
	ED_OCTET SpeechVersionIndicator2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding3_Present;
	/*GBD01b*/
	ED_OCTET SpeechVersionIndicator3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Coding4_Present;
	/*GBD01b*/
	ED_OCTET SpeechVersionIndicator4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Compress; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Compress_Present;
	ED_OCTET Structure; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DuplMode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Configuration; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NIRR; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Establishment; /* ODY01a *//*GBD01b*/
	ED_OCTET AccessId; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AccessId_Present;
	ED_OCTET RateAdaption; /* ODY01a *//*GBD01b*/
	ED_OCTET SignallingAccessProtocol; /* ODY01a *//*GBD01b*/
	ED_OCTET OtherITC; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OtherITC_Present;
	ED_OCTET OtherRateAdaption; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN HDR; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HDR_Present;
	ED_BOOLEAN MultiFrame; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Mode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LLI; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AssigNorE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IbmNeg; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET Layer1ID; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Layer1ID_Present;
	ED_OCTET UserInfoLayer1Protocol; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ASync; /* ODY01a *//*GBD01b*/
	ED_OCTET NumbStopBits; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NumbStopBits_Present;
	ED_BOOLEAN Negotiation; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NumbDataBits; /* ODY01a *//*GBD01b*/
	ED_OCTET UserRate; /* ODY01a *//*GBD01b*/
	ED_OCTET IntermediateRate; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IntermediateRate_Present;
	ED_BOOLEAN NICOnTX; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NICOnRX; /* ODY01a *//*GBD01b*/
	ED_OCTET Parity; /* ODY01a *//*GBD01b*/
	ED_OCTET ConnectionElement; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ConnectionElement_Present;
	ED_OCTET ModemType; /* ODY01a *//*GBD01b*/
	ED_OCTET OtherModemType; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OtherModemType_Present;
	ED_OCTET FixedNetworkUserRate; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TCH_F14_4_acceptable; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TCH_F14_4_acceptable_Present;
	/*GBD01b*/
	ED_BOOLEAN TCH_F9_6_acceptable; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TCH_F4_8_acceptable; /* ODY01a *//*GBD01b*/
	ED_OCTET MaxNumberOfTrafficChannels; /* ODY01a *//*GBD01b*/
	ED_OCTET UIMI; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIMI_Present;
	ED_OCTET WantedAirInterfaceUserRate; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TCH_F28_8_acceptable; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TCH_F28_8_acceptable_Present;
	ED_BOOLEAN TCH_F32_0_acceptable; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TCH_F43_2_acceptable; /* ODY01a *//*GBD01b*/
	ED_OCTET AsymmetryIndication; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN Layer2ID_Present;
	ED_OCTET UserInfoLayer2Protocol; /* ODY01a *//*GBD01b*/

}	c_BearerCpblty;
#define INIT_c_BearerCpblty(sp) ED_RESET_MEM ((sp), sizeof (c_BearerCpblty))
/*FRK03a*/
void FREE_c_BearerCpblty(c_BearerCpblty* sp);
#define SETPRESENT_c_BearerCpblty_Coding1(sp,present) (((sp)->Coding1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_Coding1(sp) ((sp)->Coding1_Present)
#define SETPRESENT_c_BearerCpblty_Coding2(sp,present) (((sp)->Coding2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_Coding2(sp) ((sp)->Coding2_Present)
#define SETPRESENT_c_BearerCpblty_Coding3(sp,present) (((sp)->Coding3_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_Coding3(sp) ((sp)->Coding3_Present)
#define SETPRESENT_c_BearerCpblty_Coding4(sp,present) (((sp)->Coding4_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_Coding4(sp) ((sp)->Coding4_Present)
#define SETPRESENT_c_BearerCpblty_Compress(sp,present) (((sp)->Compress_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_Compress(sp) ((sp)->Compress_Present)
#define SETPRESENT_c_BearerCpblty_AccessId(sp,present) (((sp)->AccessId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_AccessId(sp) ((sp)->AccessId_Present)
#define SETPRESENT_c_BearerCpblty_OtherITC(sp,present) (((sp)->OtherITC_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_OtherITC(sp) ((sp)->OtherITC_Present)
#define SETPRESENT_c_BearerCpblty_HDR(sp,present) (((sp)->HDR_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_HDR(sp) ((sp)->HDR_Present)
#define SETPRESENT_c_BearerCpblty_Layer1ID(sp,present) (((sp)->Layer1ID_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_Layer1ID(sp) ((sp)->Layer1ID_Present)
#define SETPRESENT_c_BearerCpblty_NumbStopBits(sp,present) (((sp)->NumbStopBits_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_NumbStopBits(sp) ((sp)->NumbStopBits_Present)
#define SETPRESENT_c_BearerCpblty_IntermediateRate(sp,present) (((sp)->IntermediateRate_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_IntermediateRate(sp) ((sp)->IntermediateRate_Present)
#define SETPRESENT_c_BearerCpblty_ConnectionElement(sp,present) (((sp)->ConnectionElement_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_ConnectionElement(sp) ((sp)->ConnectionElement_Present)
#define SETPRESENT_c_BearerCpblty_OtherModemType(sp,present) (((sp)->OtherModemType_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_OtherModemType(sp) ((sp)->OtherModemType_Present)
#define SETPRESENT_c_BearerCpblty_TCH_F14_4_acceptable(sp,present) (((sp)->TCH_F14_4_acceptable_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_TCH_F14_4_acceptable(sp) ((sp)->TCH_F14_4_acceptable_Present)
#define SETPRESENT_c_BearerCpblty_UIMI(sp,present) (((sp)->UIMI_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_UIMI(sp) ((sp)->UIMI_Present)
#define SETPRESENT_c_BearerCpblty_TCH_F28_8_acceptable(sp,present) (((sp)->TCH_F28_8_acceptable_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_TCH_F28_8_acceptable(sp) ((sp)->TCH_F28_8_acceptable_Present)
#define SETPRESENT_c_BearerCpblty_Layer2ID(sp,present) (((sp)->Layer2ID_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BearerCpblty_Layer2ID(sp) ((sp)->Layer2ID_Present)

/* Access member 'TypeOfNumber' of type 'c_CalledPartyBcdNum' as a variable reference */
#define VAR_c_CalledPartyBcdNum_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_CalledPartyBcdNum' as a pointer */
#define PTR_c_CalledPartyBcdNum_TypeOfNumber(var) (&var)

/* Access member 'NumberingPlanIdent' of type 'c_CalledPartyBcdNum' as a variable reference */
#define VAR_c_CalledPartyBcdNum_NumberingPlanIdent(var) var

/* Access member 'NumberingPlanIdent' of type 'c_CalledPartyBcdNum' as a pointer */
#define PTR_c_CalledPartyBcdNum_NumberingPlanIdent(var) (&var)

/* Access member 'Number' of type 'c_CalledPartyBcdNum' as a variable reference */
#define VAR_c_CalledPartyBcdNum_Number(var) var

/* Access member 'Number' of type 'c_CalledPartyBcdNum' as a pointer */
#define PTR_c_CalledPartyBcdNum_Number(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CalledPartyBcdNum {
	ED_LOCATOR TypeOfNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR NumberingPlanIdent___LOCATOR; /* QUI2 */

	ED_OCTET TypeOfNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET NumberingPlanIdent; /* ODY01a *//*GBD01b*/
	c_TBCDArray Number; /* ODY01a *//*GBD01b*/

}	c_CalledPartyBcdNum;
#define INIT_c_CalledPartyBcdNum(sp) ED_RESET_MEM ((sp), sizeof (c_CalledPartyBcdNum))
/*FRK03a*/
void FREE_c_CalledPartyBcdNum(c_CalledPartyBcdNum* sp);

/* Access member 'CodingStandard' of type 'c_HighLayerCpbility' as a variable reference */
#define VAR_c_HighLayerCpbility_CodingStandard(var) var

/* Access member 'CodingStandard' of type 'c_HighLayerCpbility' as a pointer */
#define PTR_c_HighLayerCpbility_CodingStandard(var) (&var)

/* Access member 'Interpretation' of type 'c_HighLayerCpbility' as a variable reference */
#define VAR_c_HighLayerCpbility_Interpretation(var) var

/* Access member 'Interpretation' of type 'c_HighLayerCpbility' as a pointer */
#define PTR_c_HighLayerCpbility_Interpretation(var) (&var)

/* Access member 'PresentationMethod' of type 'c_HighLayerCpbility' as a variable reference */
#define VAR_c_HighLayerCpbility_PresentationMethod(var) var

/* Access member 'PresentationMethod' of type 'c_HighLayerCpbility' as a pointer */
#define PTR_c_HighLayerCpbility_PresentationMethod(var) (&var)

/* Access member 'HighLayerCharacteristicsId' of type 'c_HighLayerCpbility' as a variable reference */
#define VAR_c_HighLayerCpbility_HighLayerCharacteristicsId(var) var

/* Access member 'HighLayerCharacteristicsId' of type 'c_HighLayerCpbility' as a pointer */
#define PTR_c_HighLayerCpbility_HighLayerCharacteristicsId(var) (&var)

/* Access member 'ExtHighLayerCharacteristicsId' of type 'c_HighLayerCpbility' as a variable reference */
#define VAR_c_HighLayerCpbility_ExtHighLayerCharacteristicsId(var) var

/* Access member 'ExtHighLayerCharacteristicsId' of type 'c_HighLayerCpbility' as a pointer */
#define PTR_c_HighLayerCpbility_ExtHighLayerCharacteristicsId(var) (&var)


/*-A----------------------------------*/
typedef struct _c_HighLayerCpbility {
	ED_LOCATOR CodingStandard___LOCATOR; /* QUI2 */
	ED_LOCATOR Interpretation___LOCATOR; /* QUI2 */
	ED_LOCATOR PresentationMethod___LOCATOR; /* QUI2 */
	ED_LOCATOR HighLayerCharacteristicsId___LOCATOR; /* QUI2 */
	ED_LOCATOR ExtHighLayerCharacteristicsId___LOCATOR; /* QUI2 */

	ED_OCTET CodingStandard; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CodingStandard_Present;
	ED_OCTET Interpretation; /* ODY01a *//*GBD01b*/
	ED_OCTET PresentationMethod; /* ODY01a *//*GBD01b*/
	ED_OCTET HighLayerCharacteristicsId; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HighLayerCharacteristicsId_Present;
	ED_OCTET ExtHighLayerCharacteristicsId; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ExtHighLayerCharacteristicsId_Present;

}	c_HighLayerCpbility;
#define INIT_c_HighLayerCpbility(sp) ED_RESET_MEM ((sp), sizeof (c_HighLayerCpbility))
/*FRK03a*/
void FREE_c_HighLayerCpbility(c_HighLayerCpbility* sp);
#define SETPRESENT_c_HighLayerCpbility_CodingStandard(sp,present) (((sp)->CodingStandard_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_HighLayerCpbility_CodingStandard(sp) ((sp)->CodingStandard_Present)
#define SETPRESENT_c_HighLayerCpbility_HighLayerCharacteristicsId(sp,present) (((sp)->HighLayerCharacteristicsId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_HighLayerCpbility_HighLayerCharacteristicsId(sp) ((sp)->HighLayerCharacteristicsId_Present)
#define SETPRESENT_c_HighLayerCpbility_ExtHighLayerCharacteristicsId(sp,present) (((sp)->ExtHighLayerCharacteristicsId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_HighLayerCpbility_ExtHighLayerCharacteristicsId(sp) ((sp)->ExtHighLayerCharacteristicsId_Present)

/* Access member 'data' of type 'c_SupportedCodecList' as a variable reference */
#define VAR_c_SupportedCodecList_data(var) (*var)

/* Access member 'data' of type 'c_SupportedCodecList' as a pointer */
#define PTR_c_SupportedCodecList_data(var) var


/*-A----------------------------------*/
typedef struct _c_SupportedCodecList {

		c_SupportedCodec **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_SupportedCodecList;
#define INIT_c_SupportedCodecList(sp) ED_RESET_MEM ((sp), sizeof (c_SupportedCodecList))
/*FRK02b*/
void FREE_c_SupportedCodecList (c_SupportedCodecList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_SupportedCodecList'. */
int SETITEMS_c_SupportedCodecList (c_SupportedCodecList* sequence, int desiredItems);
#define ADDITEMS_c_SupportedCodecList(sequence, itemsToBeAdded) SETITEMS_c_SupportedCodecList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'MCC2' of type 'c_LocationAreaId' as a variable reference */
#define VAR_c_LocationAreaId_MCC2(var) var

/* Access member 'MCC2' of type 'c_LocationAreaId' as a pointer */
#define PTR_c_LocationAreaId_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_LocationAreaId' as a variable reference */
#define VAR_c_LocationAreaId_MCC1(var) var

/* Access member 'MCC1' of type 'c_LocationAreaId' as a pointer */
#define PTR_c_LocationAreaId_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_LocationAreaId' as a variable reference */
#define VAR_c_LocationAreaId_MNC3(var) var

/* Access member 'MNC3' of type 'c_LocationAreaId' as a pointer */
#define PTR_c_LocationAreaId_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_LocationAreaId' as a variable reference */
#define VAR_c_LocationAreaId_MCC3(var) var

/* Access member 'MCC3' of type 'c_LocationAreaId' as a pointer */
#define PTR_c_LocationAreaId_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_LocationAreaId' as a variable reference */
#define VAR_c_LocationAreaId_MNC2(var) var

/* Access member 'MNC2' of type 'c_LocationAreaId' as a pointer */
#define PTR_c_LocationAreaId_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_LocationAreaId' as a variable reference */
#define VAR_c_LocationAreaId_MNC1(var) var

/* Access member 'MNC1' of type 'c_LocationAreaId' as a pointer */
#define PTR_c_LocationAreaId_MNC1(var) (&var)

/* Access member 'LAC' of type 'c_LocationAreaId' as a variable reference */
#define VAR_c_LocationAreaId_LAC(var) var

/* Access member 'LAC' of type 'c_LocationAreaId' as a pointer */
#define PTR_c_LocationAreaId_LAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_LocationAreaId {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR LAC___LOCATOR; /* QUI2 */

	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_SHORT LAC; /* ODY01a *//*GBD01b*/

}	c_LocationAreaId;
#define INIT_c_LocationAreaId(sp) ED_RESET_MEM ((sp), sizeof (c_LocationAreaId))
/*FRK03a*/
void FREE_c_LocationAreaId(c_LocationAreaId* sp);

/* Access member 'spare' of type 'c_MobileStationClassmark1' as a variable reference */
#define VAR_c_MobileStationClassmark1_spare(var) var

/* Access member 'spare' of type 'c_MobileStationClassmark1' as a pointer */
#define PTR_c_MobileStationClassmark1_spare(var) (&var)

/* Access member 'RevisionLevel' of type 'c_MobileStationClassmark1' as a variable reference */
#define VAR_c_MobileStationClassmark1_RevisionLevel(var) var

/* Access member 'RevisionLevel' of type 'c_MobileStationClassmark1' as a pointer */
#define PTR_c_MobileStationClassmark1_RevisionLevel(var) (&var)

/* Access member 'EsInd' of type 'c_MobileStationClassmark1' as a variable reference */
#define VAR_c_MobileStationClassmark1_EsInd(var) var

/* Access member 'EsInd' of type 'c_MobileStationClassmark1' as a pointer */
#define PTR_c_MobileStationClassmark1_EsInd(var) (&var)

/* Access member 'A5_1' of type 'c_MobileStationClassmark1' as a variable reference */
#define VAR_c_MobileStationClassmark1_A5_1(var) var

/* Access member 'A5_1' of type 'c_MobileStationClassmark1' as a pointer */
#define PTR_c_MobileStationClassmark1_A5_1(var) (&var)

/* Access member 'RfPowerCapability' of type 'c_MobileStationClassmark1' as a variable reference */
#define VAR_c_MobileStationClassmark1_RfPowerCapability(var) var

/* Access member 'RfPowerCapability' of type 'c_MobileStationClassmark1' as a pointer */
#define PTR_c_MobileStationClassmark1_RfPowerCapability(var) (&var)


/*-A----------------------------------*/
typedef struct _c_MobileStationClassmark1 {
	ED_LOCATOR RevisionLevel___LOCATOR; /* QUI2 */
	ED_LOCATOR EsInd___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_1___LOCATOR; /* QUI2 */
	ED_LOCATOR RfPowerCapability___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET RevisionLevel; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EsInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_1; /* ODY01a *//*GBD01b*/
	ED_OCTET RfPowerCapability; /* ODY01a *//*GBD01b*/

}	c_MobileStationClassmark1;
#define INIT_c_MobileStationClassmark1(sp) ED_RESET_MEM ((sp), sizeof (c_MobileStationClassmark1))
/*FRK03a*/
void FREE_c_MobileStationClassmark1(c_MobileStationClassmark1* sp);

/* Access member 'spare1' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_spare1(var) var

/* Access member 'spare1' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_spare1(var) (&var)

/* Access member 'RevisionLevel' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_RevisionLevel(var) var

/* Access member 'RevisionLevel' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_RevisionLevel(var) (&var)

/* Access member 'EsInd' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_EsInd(var) var

/* Access member 'EsInd' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_EsInd(var) (&var)

/* Access member 'A5_1' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_A5_1(var) var

/* Access member 'A5_1' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_A5_1(var) (&var)

/* Access member 'RFPowerCapability' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_RFPowerCapability(var) var

/* Access member 'RFPowerCapability' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_RFPowerCapability(var) (&var)

/* Access member 'spare2' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_spare2(var) var

/* Access member 'spare2' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_spare2(var) (&var)

/* Access member 'PSCapability' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_PSCapability(var) var

/* Access member 'PSCapability' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_PSCapability(var) (&var)

/* Access member 'SSScreenIndicator' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_SSScreenIndicator(var) var

/* Access member 'SSScreenIndicator' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_SSScreenIndicator(var) (&var)

/* Access member 'SMCapability' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_SMCapability(var) var

/* Access member 'SMCapability' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_SMCapability(var) (&var)

/* Access member 'VBS' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_VBS(var) var

/* Access member 'VBS' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_VBS(var) (&var)

/* Access member 'VGCS' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_VGCS(var) var

/* Access member 'VGCS' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_VGCS(var) (&var)

/* Access member 'FC' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_FC(var) var

/* Access member 'FC' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_FC(var) (&var)

/* Access member 'CM3' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_CM3(var) var

/* Access member 'CM3' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_CM3(var) (&var)

/* Access member 'spare3' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_spare3(var) var

/* Access member 'spare3' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_spare3(var) (&var)

/* Access member 'LCSVA_CAP' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_LCSVA_CAP(var) var

/* Access member 'LCSVA_CAP' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_LCSVA_CAP(var) (&var)

/* Access member 'UCS2' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_UCS2(var) var

/* Access member 'UCS2' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_UCS2(var) (&var)

/* Access member 'SoLSA' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_SoLSA(var) var

/* Access member 'SoLSA' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_SoLSA(var) (&var)

/* Access member 'CMSP' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_CMSP(var) var

/* Access member 'CMSP' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_CMSP(var) (&var)

/* Access member 'A5_3' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_A5_3(var) var

/* Access member 'A5_3' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_A5_3(var) (&var)

/* Access member 'A5_2' of type 'c_MobileStationClassmark2' as a variable reference */
#define VAR_c_MobileStationClassmark2_A5_2(var) var

/* Access member 'A5_2' of type 'c_MobileStationClassmark2' as a pointer */
#define PTR_c_MobileStationClassmark2_A5_2(var) (&var)


/*-A----------------------------------*/
typedef struct _c_MobileStationClassmark2 {
	ED_LOCATOR RevisionLevel___LOCATOR; /* QUI2 */
	ED_LOCATOR EsInd___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_1___LOCATOR; /* QUI2 */
	ED_LOCATOR RFPowerCapability___LOCATOR; /* QUI2 */
	ED_LOCATOR PSCapability___LOCATOR; /* QUI2 */
	ED_LOCATOR SSScreenIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR SMCapability___LOCATOR; /* QUI2 */
	ED_LOCATOR VBS___LOCATOR; /* QUI2 */
	ED_LOCATOR VGCS___LOCATOR; /* QUI2 */
	ED_LOCATOR FC___LOCATOR; /* QUI2 */
	ED_LOCATOR CM3___LOCATOR; /* QUI2 */
	ED_LOCATOR LCSVA_CAP___LOCATOR; /* QUI2 */
	ED_LOCATOR UCS2___LOCATOR; /* QUI2 */
	ED_LOCATOR SoLSA___LOCATOR; /* QUI2 */
	ED_LOCATOR CMSP___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_3___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_2___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET RevisionLevel; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EsInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_1; /* ODY01a *//*GBD01b*/
	ED_OCTET RFPowerCapability; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN PSCapability; /* ODY01a *//*GBD01b*/
	ED_OCTET SSScreenIndicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SMCapability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VBS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VGCS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN FC; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CM3; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN LCSVA_CAP; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UCS2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SoLSA; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CMSP; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_2; /* ODY01a *//*GBD01b*/

}	c_MobileStationClassmark2;
#define INIT_c_MobileStationClassmark2(sp) ED_RESET_MEM ((sp), sizeof (c_MobileStationClassmark2))
/*FRK03a*/
void FREE_c_MobileStationClassmark2(c_MobileStationClassmark2* sp);

/* Access member 'spare' of type 'c_PdAndSapiCcbs' as a variable reference */
#define VAR_c_PdAndSapiCcbs_spare(var) var

/* Access member 'spare' of type 'c_PdAndSapiCcbs' as a pointer */
#define PTR_c_PdAndSapiCcbs_spare(var) (&var)

/* Access member 'SAPI' of type 'c_PdAndSapiCcbs' as a variable reference */
#define VAR_c_PdAndSapiCcbs_SAPI(var) var

/* Access member 'SAPI' of type 'c_PdAndSapiCcbs' as a pointer */
#define PTR_c_PdAndSapiCcbs_SAPI(var) (&var)

/* Access member 'PD' of type 'c_PdAndSapiCcbs' as a variable reference */
#define VAR_c_PdAndSapiCcbs_PD(var) var

/* Access member 'PD' of type 'c_PdAndSapiCcbs' as a pointer */
#define PTR_c_PdAndSapiCcbs_PD(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PdAndSapiCcbs {
	ED_LOCATOR SAPI___LOCATOR; /* QUI2 */
	ED_LOCATOR PD___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET SAPI; /* ODY01a *//*GBD01b*/
	ED_OCTET PD; /* ODY01a *//*GBD01b*/

}	c_PdAndSapiCcbs;
#define INIT_c_PdAndSapiCcbs(sp) ED_RESET_MEM ((sp), sizeof (c_PdAndSapiCcbs))
/*FRK03a*/
void FREE_c_PdAndSapiCcbs(c_PdAndSapiCcbs* sp);

/* Access member 'spare' of type 'c_PriorityLevel' as a variable reference */
#define VAR_c_PriorityLevel_spare(var) var

/* Access member 'spare' of type 'c_PriorityLevel' as a pointer */
#define PTR_c_PriorityLevel_spare(var) (&var)

/* Access member 'CallPriority' of type 'c_PriorityLevel' as a variable reference */
#define VAR_c_PriorityLevel_CallPriority(var) var

/* Access member 'CallPriority' of type 'c_PriorityLevel' as a pointer */
#define PTR_c_PriorityLevel_CallPriority(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PriorityLevel {
	ED_LOCATOR CallPriority___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET CallPriority; /* ODY01a *//*GBD01b*/

}	c_PriorityLevel;
#define INIT_c_PriorityLevel(sp) ED_RESET_MEM ((sp), sizeof (c_PriorityLevel))
/*FRK03a*/
void FREE_c_PriorityLevel(c_PriorityLevel* sp);

/* Access member 'spare' of type 'c_MSNetworkFeatureSupport' as a variable reference */
#define VAR_c_MSNetworkFeatureSupport_spare(var) var

/* Access member 'spare' of type 'c_MSNetworkFeatureSupport' as a pointer */
#define PTR_c_MSNetworkFeatureSupport_spare(var) (&var)

/* Access member 'ExtendedPeriodicTimers' of type 'c_MSNetworkFeatureSupport' as a variable reference */
#define VAR_c_MSNetworkFeatureSupport_ExtendedPeriodicTimers(var) var

/* Access member 'ExtendedPeriodicTimers' of type 'c_MSNetworkFeatureSupport' as a pointer */
#define PTR_c_MSNetworkFeatureSupport_ExtendedPeriodicTimers(var) (&var)


/*-A----------------------------------*/
typedef struct _c_MSNetworkFeatureSupport {
	ED_LOCATOR ExtendedPeriodicTimers___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN ExtendedPeriodicTimers; /* ODY01a *//*GBD01b*/

}	c_MSNetworkFeatureSupport;
#define INIT_c_MSNetworkFeatureSupport(sp) ED_RESET_MEM ((sp), sizeof (c_MSNetworkFeatureSupport))
/*FRK03a*/
void FREE_c_MSNetworkFeatureSupport(c_MSNetworkFeatureSupport* sp);

/* Access member 'xFOR' of type 'c_LocationUpdatingType' as a variable reference */
#define VAR_c_LocationUpdatingType_xFOR(var) var

/* Access member 'xFOR' of type 'c_LocationUpdatingType' as a pointer */
#define PTR_c_LocationUpdatingType_xFOR(var) (&var)

/* Access member 'spare' of type 'c_LocationUpdatingType' as a variable reference */
#define VAR_c_LocationUpdatingType_spare(var) var

/* Access member 'spare' of type 'c_LocationUpdatingType' as a pointer */
#define PTR_c_LocationUpdatingType_spare(var) (&var)

/* Access member 'LUT' of type 'c_LocationUpdatingType' as a variable reference */
#define VAR_c_LocationUpdatingType_LUT(var) var

/* Access member 'LUT' of type 'c_LocationUpdatingType' as a pointer */
#define PTR_c_LocationUpdatingType_LUT(var) (&var)


/*-A----------------------------------*/
typedef struct _c_LocationUpdatingType {
	ED_LOCATOR xFOR___LOCATOR; /* QUI2 */
	ED_LOCATOR LUT___LOCATOR; /* QUI2 */

	ED_BOOLEAN xFOR; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET LUT; /* ODY01a *//*GBD01b*/

}	c_LocationUpdatingType;
#define INIT_c_LocationUpdatingType(sp) ED_RESET_MEM ((sp), sizeof (c_LocationUpdatingType))
/*FRK03a*/
void FREE_c_LocationUpdatingType(c_LocationUpdatingType* sp);

/* Access member 'ext' of type 'c_NetwkName' as a variable reference */
#define VAR_c_NetwkName_ext(var) var

/* Access member 'ext' of type 'c_NetwkName' as a pointer */
#define PTR_c_NetwkName_ext(var) (&var)

/* Access member 'CodingScheme' of type 'c_NetwkName' as a variable reference */
#define VAR_c_NetwkName_CodingScheme(var) var

/* Access member 'CodingScheme' of type 'c_NetwkName' as a pointer */
#define PTR_c_NetwkName_CodingScheme(var) (&var)

/* Access member 'AddCI' of type 'c_NetwkName' as a variable reference */
#define VAR_c_NetwkName_AddCI(var) var

/* Access member 'AddCI' of type 'c_NetwkName' as a pointer */
#define PTR_c_NetwkName_AddCI(var) (&var)

/* Access member 'SpareBitsInLastOctet' of type 'c_NetwkName' as a variable reference */
#define VAR_c_NetwkName_SpareBitsInLastOctet(var) var

/* Access member 'SpareBitsInLastOctet' of type 'c_NetwkName' as a pointer */
#define PTR_c_NetwkName_SpareBitsInLastOctet(var) (&var)

/* Access member 'TextString' of type 'c_NetwkName' as a variable reference */
#define VAR_c_NetwkName_TextString(var) var

/* Access member 'TextString' of type 'c_NetwkName' as a pointer */
#define PTR_c_NetwkName_TextString(var) (&var)

/* DEFINITION OF BINARY c_NetwkName_TextString */
typedef struct _c_NetwkName_TextString {
	ED_BYTE* value; /* Variable size; bits needed 1992 */
	int usedBits;
} c_NetwkName_TextString;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_NetwkName_TextString(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_NetwkName {
	ED_LOCATOR CodingScheme___LOCATOR; /* QUI2 */
	ED_LOCATOR AddCI___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareBitsInLastOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR TextString___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET CodingScheme; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AddCI; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareBitsInLastOctet; /* ODY01a *//*GBD01b*/
	c_NetwkName_TextString TextString; /* Static, variable size; bits needed 1992 *//*GBD01b*/

}	c_NetwkName;
#define INIT_c_NetwkName(sp) ED_RESET_MEM ((sp), sizeof (c_NetwkName))
/*FRK03a*/
void FREE_c_NetwkName(c_NetwkName* sp);

/* Access member 'Cause' of type 'c_RejectCause' as a variable reference */
#define VAR_c_RejectCause_Cause(var) var

/* Access member 'Cause' of type 'c_RejectCause' as a pointer */
#define PTR_c_RejectCause_Cause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RejectCause {
	ED_LOCATOR Cause___LOCATOR; /* QUI2 */

	ED_OCTET Cause; /* ODY01a *//*GBD01b*/

}	c_RejectCause;
#define INIT_c_RejectCause(sp) ED_RESET_MEM ((sp), sizeof (c_RejectCause))
/*FRK03a*/
void FREE_c_RejectCause(c_RejectCause* sp);

/* Access member 'Year' of type 'c_TimeZoneAndTime' as a variable reference */
#define VAR_c_TimeZoneAndTime_Year(var) var

/* Access member 'Year' of type 'c_TimeZoneAndTime' as a pointer */
#define PTR_c_TimeZoneAndTime_Year(var) (&var)

/* Access member 'Month' of type 'c_TimeZoneAndTime' as a variable reference */
#define VAR_c_TimeZoneAndTime_Month(var) var

/* Access member 'Month' of type 'c_TimeZoneAndTime' as a pointer */
#define PTR_c_TimeZoneAndTime_Month(var) (&var)

/* Access member 'Day' of type 'c_TimeZoneAndTime' as a variable reference */
#define VAR_c_TimeZoneAndTime_Day(var) var

/* Access member 'Day' of type 'c_TimeZoneAndTime' as a pointer */
#define PTR_c_TimeZoneAndTime_Day(var) (&var)

/* Access member 'Hour' of type 'c_TimeZoneAndTime' as a variable reference */
#define VAR_c_TimeZoneAndTime_Hour(var) var

/* Access member 'Hour' of type 'c_TimeZoneAndTime' as a pointer */
#define PTR_c_TimeZoneAndTime_Hour(var) (&var)

/* Access member 'Minute' of type 'c_TimeZoneAndTime' as a variable reference */
#define VAR_c_TimeZoneAndTime_Minute(var) var

/* Access member 'Minute' of type 'c_TimeZoneAndTime' as a pointer */
#define PTR_c_TimeZoneAndTime_Minute(var) (&var)

/* Access member 'Second' of type 'c_TimeZoneAndTime' as a variable reference */
#define VAR_c_TimeZoneAndTime_Second(var) var

/* Access member 'Second' of type 'c_TimeZoneAndTime' as a pointer */
#define PTR_c_TimeZoneAndTime_Second(var) (&var)

/* Access member 'TimeZone' of type 'c_TimeZoneAndTime' as a variable reference */
#define VAR_c_TimeZoneAndTime_TimeZone(var) var

/* Access member 'TimeZone' of type 'c_TimeZoneAndTime' as a pointer */
#define PTR_c_TimeZoneAndTime_TimeZone(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TimeZoneAndTime {
	ED_LOCATOR Year___LOCATOR; /* QUI2 */
	ED_LOCATOR Month___LOCATOR; /* QUI2 */
	ED_LOCATOR Day___LOCATOR; /* QUI2 */
	ED_LOCATOR Hour___LOCATOR; /* QUI2 */
	ED_LOCATOR Minute___LOCATOR; /* QUI2 */
	ED_LOCATOR Second___LOCATOR; /* QUI2 */
	ED_LOCATOR TimeZone___LOCATOR; /* QUI2 */

	ED_OCTET Year; /* ODY01a *//*GBD01b*/
	ED_OCTET Month; /* ODY01a *//*GBD01b*/
	ED_OCTET Day; /* ODY01a *//*GBD01b*/
	ED_OCTET Hour; /* ODY01a *//*GBD01b*/
	ED_OCTET Minute; /* ODY01a *//*GBD01b*/
	ED_OCTET Second; /* ODY01a *//*GBD01b*/
	ED_OCTET TimeZone; /* ODY01a *//*GBD01b*/

}	c_TimeZoneAndTime;
#define INIT_c_TimeZoneAndTime(sp) ED_RESET_MEM ((sp), sizeof (c_TimeZoneAndTime))
/*FRK03a*/
void FREE_c_TimeZoneAndTime(c_TimeZoneAndTime* sp);

/* Access member 'spare' of type 'c_DaylightSavingTime' as a variable reference */
#define VAR_c_DaylightSavingTime_spare(var) var

/* Access member 'spare' of type 'c_DaylightSavingTime' as a pointer */
#define PTR_c_DaylightSavingTime_spare(var) (&var)

/* Access member 'Value' of type 'c_DaylightSavingTime' as a variable reference */
#define VAR_c_DaylightSavingTime_Value(var) var

/* Access member 'Value' of type 'c_DaylightSavingTime' as a pointer */
#define PTR_c_DaylightSavingTime_Value(var) (&var)


/*-A----------------------------------*/
typedef struct _c_DaylightSavingTime {
	ED_LOCATOR Value___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET Value; /* ODY01a *//*GBD01b*/

}	c_DaylightSavingTime;
#define INIT_c_DaylightSavingTime(sp) ED_RESET_MEM ((sp), sizeof (c_DaylightSavingTime))
/*FRK03a*/
void FREE_c_DaylightSavingTime(c_DaylightSavingTime* sp);

/* Access member 'spare' of type 'c_AdditionalUpdateParameters' as a variable reference */
#define VAR_c_AdditionalUpdateParameters_spare(var) var

/* Access member 'spare' of type 'c_AdditionalUpdateParameters' as a pointer */
#define PTR_c_AdditionalUpdateParameters_spare(var) (&var)

/* Access member 'CSMO' of type 'c_AdditionalUpdateParameters' as a variable reference */
#define VAR_c_AdditionalUpdateParameters_CSMO(var) var

/* Access member 'CSMO' of type 'c_AdditionalUpdateParameters' as a pointer */
#define PTR_c_AdditionalUpdateParameters_CSMO(var) (&var)

/* Access member 'CSMT' of type 'c_AdditionalUpdateParameters' as a variable reference */
#define VAR_c_AdditionalUpdateParameters_CSMT(var) var

/* Access member 'CSMT' of type 'c_AdditionalUpdateParameters' as a pointer */
#define PTR_c_AdditionalUpdateParameters_CSMT(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AdditionalUpdateParameters {
	ED_LOCATOR CSMO___LOCATOR; /* QUI2 */
	ED_LOCATOR CSMT___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN CSMO; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CSMT; /* ODY01a *//*GBD01b*/

}	c_AdditionalUpdateParameters;
#define INIT_c_AdditionalUpdateParameters(sp) ED_RESET_MEM ((sp), sizeof (c_AdditionalUpdateParameters))
/*FRK03a*/
void FREE_c_AdditionalUpdateParameters(c_AdditionalUpdateParameters* sp);

/* Access member 'ext' of type 'c_AuxiliaryStates' as a variable reference */
#define VAR_c_AuxiliaryStates_ext(var) var

/* Access member 'ext' of type 'c_AuxiliaryStates' as a pointer */
#define PTR_c_AuxiliaryStates_ext(var) (&var)

/* Access member 'spare' of type 'c_AuxiliaryStates' as a variable reference */
#define VAR_c_AuxiliaryStates_spare(var) var

/* Access member 'spare' of type 'c_AuxiliaryStates' as a pointer */
#define PTR_c_AuxiliaryStates_spare(var) (&var)

/* Access member 'HoldAuxState' of type 'c_AuxiliaryStates' as a variable reference */
#define VAR_c_AuxiliaryStates_HoldAuxState(var) var

/* Access member 'HoldAuxState' of type 'c_AuxiliaryStates' as a pointer */
#define PTR_c_AuxiliaryStates_HoldAuxState(var) (&var)

/* Access member 'MPTYAuxState' of type 'c_AuxiliaryStates' as a variable reference */
#define VAR_c_AuxiliaryStates_MPTYAuxState(var) var

/* Access member 'MPTYAuxState' of type 'c_AuxiliaryStates' as a pointer */
#define PTR_c_AuxiliaryStates_MPTYAuxState(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AuxiliaryStates {
	ED_LOCATOR HoldAuxState___LOCATOR; /* QUI2 */
	ED_LOCATOR MPTYAuxState___LOCATOR; /* QUI2 */

	/*GBD01b*/
	/*GBD01b*/
	ED_OCTET HoldAuxState; /* ODY01a *//*GBD01b*/
	ED_OCTET MPTYAuxState; /* ODY01a *//*GBD01b*/

}	c_AuxiliaryStates;
#define INIT_c_AuxiliaryStates(sp) ED_RESET_MEM ((sp), sizeof (c_AuxiliaryStates))
/*FRK03a*/
void FREE_c_AuxiliaryStates(c_AuxiliaryStates* sp);

/* Access member 'CodingStandard' of type 'c_CallState' as a variable reference */
#define VAR_c_CallState_CodingStandard(var) var

/* Access member 'CodingStandard' of type 'c_CallState' as a pointer */
#define PTR_c_CallState_CodingStandard(var) (&var)

/* Access member 'CallStateValue' of type 'c_CallState' as a variable reference */
#define VAR_c_CallState_CallStateValue(var) var

/* Access member 'CallStateValue' of type 'c_CallState' as a pointer */
#define PTR_c_CallState_CallStateValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CallState {
	ED_LOCATOR CodingStandard___LOCATOR; /* QUI2 */
	ED_LOCATOR CallStateValue___LOCATOR; /* QUI2 */

	ED_OCTET CodingStandard; /* ODY01a *//*GBD01b*/
	ED_OCTET CallStateValue; /* ODY01a *//*GBD01b*/

}	c_CallState;
#define INIT_c_CallState(sp) ED_RESET_MEM ((sp), sizeof (c_CallState))
/*FRK03a*/
void FREE_c_CallState(c_CallState* sp);

/* Access member 'ext' of type 'c_ConnSubaddres' as a variable reference */
#define VAR_c_ConnSubaddres_ext(var) var

/* Access member 'ext' of type 'c_ConnSubaddres' as a pointer */
#define PTR_c_ConnSubaddres_ext(var) (&var)

/* Access member 'TypeOfSubaddress' of type 'c_ConnSubaddres' as a variable reference */
#define VAR_c_ConnSubaddres_TypeOfSubaddress(var) var

/* Access member 'TypeOfSubaddress' of type 'c_ConnSubaddres' as a pointer */
#define PTR_c_ConnSubaddres_TypeOfSubaddress(var) (&var)

/* Access member 'OddEvenIndicator' of type 'c_ConnSubaddres' as a variable reference */
#define VAR_c_ConnSubaddres_OddEvenIndicator(var) var

/* Access member 'OddEvenIndicator' of type 'c_ConnSubaddres' as a pointer */
#define PTR_c_ConnSubaddres_OddEvenIndicator(var) (&var)

/* Access member 'spare' of type 'c_ConnSubaddres' as a variable reference */
#define VAR_c_ConnSubaddres_spare(var) var

/* Access member 'spare' of type 'c_ConnSubaddres' as a pointer */
#define PTR_c_ConnSubaddres_spare(var) (&var)

/* Access member 'SubaddressInformation' of type 'c_ConnSubaddres' as a variable reference */
#define VAR_c_ConnSubaddres_SubaddressInformation(var) var

/* Access member 'SubaddressInformation' of type 'c_ConnSubaddres' as a pointer */
#define PTR_c_ConnSubaddres_SubaddressInformation(var) (&var)

/* DEFINITION OF BINARY c_ConnSubaddres_SubaddressInformation */
typedef struct _c_ConnSubaddres_SubaddressInformation {
	ED_BYTE* value; /* Variable size; bits needed 160 */
	int usedBits;
} c_ConnSubaddres_SubaddressInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ConnSubaddres_SubaddressInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ConnSubaddres {
	ED_LOCATOR TypeOfSubaddress___LOCATOR; /* QUI2 */
	ED_LOCATOR OddEvenIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR SubaddressInformation___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET TypeOfSubaddress; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OddEvenIndicator; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_ConnSubaddres_SubaddressInformation SubaddressInformation; /* Static, variable size; bits needed 160 *//*GBD01b*/

}	c_ConnSubaddres;
#define INIT_c_ConnSubaddres(sp) ED_RESET_MEM ((sp), sizeof (c_ConnSubaddres))
/*FRK03a*/
void FREE_c_ConnSubaddres(c_ConnSubaddres* sp);

/* Access member 'spare' of type 'c_KeypadFacility' as a variable reference */
#define VAR_c_KeypadFacility_spare(var) var

/* Access member 'spare' of type 'c_KeypadFacility' as a pointer */
#define PTR_c_KeypadFacility_spare(var) (&var)

/* Access member 'KeypadInfo' of type 'c_KeypadFacility' as a variable reference */
#define VAR_c_KeypadFacility_KeypadInfo(var) var

/* Access member 'KeypadInfo' of type 'c_KeypadFacility' as a pointer */
#define PTR_c_KeypadFacility_KeypadInfo(var) (&var)


/*-A----------------------------------*/
typedef struct _c_KeypadFacility {
	ED_LOCATOR KeypadInfo___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET KeypadInfo; /* ODY01a *//*GBD01b*/

}	c_KeypadFacility;
#define INIT_c_KeypadFacility(sp) ED_RESET_MEM ((sp), sizeof (c_KeypadFacility))
/*FRK03a*/
void FREE_c_KeypadFacility(c_KeypadFacility* sp);

/* Access member 'ext' of type 'c_NotifInd' as a variable reference */
#define VAR_c_NotifInd_ext(var) var

/* Access member 'ext' of type 'c_NotifInd' as a pointer */
#define PTR_c_NotifInd_ext(var) (&var)

/* Access member 'NotificationDescription' of type 'c_NotifInd' as a variable reference */
#define VAR_c_NotifInd_NotificationDescription(var) var

/* Access member 'NotificationDescription' of type 'c_NotifInd' as a pointer */
#define PTR_c_NotifInd_NotificationDescription(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NotifInd {
	ED_LOCATOR NotificationDescription___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET NotificationDescription; /* ODY01a *//*GBD01b*/

}	c_NotifInd;
#define INIT_c_NotifInd(sp) ED_RESET_MEM ((sp), sizeof (c_NotifInd))
/*FRK03a*/
void FREE_c_NotifInd(c_NotifInd* sp);

/* Access member 'ext1' of type 'c_ProgrInd' as a variable reference */
#define VAR_c_ProgrInd_ext1(var) var

/* Access member 'ext1' of type 'c_ProgrInd' as a pointer */
#define PTR_c_ProgrInd_ext1(var) (&var)

/* Access member 'CodingStandard' of type 'c_ProgrInd' as a variable reference */
#define VAR_c_ProgrInd_CodingStandard(var) var

/* Access member 'CodingStandard' of type 'c_ProgrInd' as a pointer */
#define PTR_c_ProgrInd_CodingStandard(var) (&var)

/* Access member 'spare' of type 'c_ProgrInd' as a variable reference */
#define VAR_c_ProgrInd_spare(var) var

/* Access member 'spare' of type 'c_ProgrInd' as a pointer */
#define PTR_c_ProgrInd_spare(var) (&var)

/* Access member 'location' of type 'c_ProgrInd' as a variable reference */
#define VAR_c_ProgrInd_location(var) var

/* Access member 'location' of type 'c_ProgrInd' as a pointer */
#define PTR_c_ProgrInd_location(var) (&var)

/* Access member 'ext2' of type 'c_ProgrInd' as a variable reference */
#define VAR_c_ProgrInd_ext2(var) var

/* Access member 'ext2' of type 'c_ProgrInd' as a pointer */
#define PTR_c_ProgrInd_ext2(var) (&var)

/* Access member 'ProgressDescription' of type 'c_ProgrInd' as a variable reference */
#define VAR_c_ProgrInd_ProgressDescription(var) var

/* Access member 'ProgressDescription' of type 'c_ProgrInd' as a pointer */
#define PTR_c_ProgrInd_ProgressDescription(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ProgrInd {
	ED_LOCATOR CodingStandard___LOCATOR; /* QUI2 */
	ED_LOCATOR location___LOCATOR; /* QUI2 */
	ED_LOCATOR ProgressDescription___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET CodingStandard; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET location; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET ProgressDescription; /* ODY01a *//*GBD01b*/

}	c_ProgrInd;
#define INIT_c_ProgrInd(sp) ED_RESET_MEM ((sp), sizeof (c_ProgrInd))
/*FRK03a*/
void FREE_c_ProgrInd(c_ProgrInd* sp);

/* Access member 'spare' of type 'c_RecallType' as a variable reference */
#define VAR_c_RecallType_spare(var) var

/* Access member 'spare' of type 'c_RecallType' as a pointer */
#define PTR_c_RecallType_spare(var) (&var)

/* Access member 'RecallType' of type 'c_RecallType' as a variable reference */
#define VAR_c_RecallType_RecallType(var) var

/* Access member 'RecallType' of type 'c_RecallType' as a pointer */
#define PTR_c_RecallType_RecallType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RecallType {
	ED_LOCATOR RecallType___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET RecallType; /* ODY01a *//*GBD01b*/

}	c_RecallType;
#define INIT_c_RecallType(sp) ED_RESET_MEM ((sp), sizeof (c_RecallType))
/*FRK03a*/
void FREE_c_RecallType(c_RecallType* sp);

/* Access member 'ext' of type 'c_RedirPartySubaddr' as a variable reference */
#define VAR_c_RedirPartySubaddr_ext(var) var

/* Access member 'ext' of type 'c_RedirPartySubaddr' as a pointer */
#define PTR_c_RedirPartySubaddr_ext(var) (&var)

/* Access member 'TypeOfSubaddress' of type 'c_RedirPartySubaddr' as a variable reference */
#define VAR_c_RedirPartySubaddr_TypeOfSubaddress(var) var

/* Access member 'TypeOfSubaddress' of type 'c_RedirPartySubaddr' as a pointer */
#define PTR_c_RedirPartySubaddr_TypeOfSubaddress(var) (&var)

/* Access member 'OddEvenIndicator' of type 'c_RedirPartySubaddr' as a variable reference */
#define VAR_c_RedirPartySubaddr_OddEvenIndicator(var) var

/* Access member 'OddEvenIndicator' of type 'c_RedirPartySubaddr' as a pointer */
#define PTR_c_RedirPartySubaddr_OddEvenIndicator(var) (&var)

/* Access member 'spare' of type 'c_RedirPartySubaddr' as a variable reference */
#define VAR_c_RedirPartySubaddr_spare(var) var

/* Access member 'spare' of type 'c_RedirPartySubaddr' as a pointer */
#define PTR_c_RedirPartySubaddr_spare(var) (&var)

/* Access member 'SubaddressInformation' of type 'c_RedirPartySubaddr' as a variable reference */
#define VAR_c_RedirPartySubaddr_SubaddressInformation(var) var

/* Access member 'SubaddressInformation' of type 'c_RedirPartySubaddr' as a pointer */
#define PTR_c_RedirPartySubaddr_SubaddressInformation(var) (&var)

/* DEFINITION OF BINARY c_RedirPartySubaddr_SubaddressInformation */
typedef struct _c_RedirPartySubaddr_SubaddressInformation {
	ED_BYTE* value; /* Variable size; bits needed 160 */
	int usedBits;
} c_RedirPartySubaddr_SubaddressInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RedirPartySubaddr_SubaddressInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_RedirPartySubaddr {
	ED_LOCATOR TypeOfSubaddress___LOCATOR; /* QUI2 */
	ED_LOCATOR OddEvenIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR SubaddressInformation___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET TypeOfSubaddress; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OddEvenIndicator; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_RedirPartySubaddr_SubaddressInformation SubaddressInformation; /* Static, variable size; bits needed 160 *//*GBD01b*/

}	c_RedirPartySubaddr;
#define INIT_c_RedirPartySubaddr(sp) ED_RESET_MEM ((sp), sizeof (c_RedirPartySubaddr))
/*FRK03a*/
void FREE_c_RedirPartySubaddr(c_RedirPartySubaddr* sp);

/* Access member 'spare' of type 'c_AlertingPattern' as a variable reference */
#define VAR_c_AlertingPattern_spare(var) var

/* Access member 'spare' of type 'c_AlertingPattern' as a pointer */
#define PTR_c_AlertingPattern_spare(var) (&var)

/* Access member 'AlertingPatternValue' of type 'c_AlertingPattern' as a variable reference */
#define VAR_c_AlertingPattern_AlertingPatternValue(var) var

/* Access member 'AlertingPatternValue' of type 'c_AlertingPattern' as a pointer */
#define PTR_c_AlertingPattern_AlertingPatternValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AlertingPattern {
	ED_LOCATOR AlertingPatternValue___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET AlertingPatternValue; /* ODY01a *//*GBD01b*/

}	c_AlertingPattern;
#define INIT_c_AlertingPattern(sp) ED_RESET_MEM ((sp), sizeof (c_AlertingPattern))
/*FRK03a*/
void FREE_c_AlertingPattern(c_AlertingPattern* sp);

/* Access member 'CCBSAct' of type 'c_AllowedActionsCcbs' as a variable reference */
#define VAR_c_AllowedActionsCcbs_CCBSAct(var) var

/* Access member 'CCBSAct' of type 'c_AllowedActionsCcbs' as a pointer */
#define PTR_c_AllowedActionsCcbs_CCBSAct(var) (&var)

/* Access member 'spare' of type 'c_AllowedActionsCcbs' as a variable reference */
#define VAR_c_AllowedActionsCcbs_spare(var) var

/* Access member 'spare' of type 'c_AllowedActionsCcbs' as a pointer */
#define PTR_c_AllowedActionsCcbs_spare(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AllowedActionsCcbs {
	ED_LOCATOR CCBSAct___LOCATOR; /* QUI2 */

	ED_BOOLEAN CCBSAct; /* ODY01a *//*GBD01b*/
	/*GBD01b*/

}	c_AllowedActionsCcbs;
#define INIT_c_AllowedActionsCcbs(sp) ED_RESET_MEM ((sp), sizeof (c_AllowedActionsCcbs))
/*FRK03a*/
void FREE_c_AllowedActionsCcbs(c_AllowedActionsCcbs* sp);

/* Access member 'spare' of type 'c_NetwkCallControlCapabil' as a variable reference */
#define VAR_c_NetwkCallControlCapabil_spare(var) var

/* Access member 'spare' of type 'c_NetwkCallControlCapabil' as a pointer */
#define PTR_c_NetwkCallControlCapabil_spare(var) (&var)

/* Access member 'MCS' of type 'c_NetwkCallControlCapabil' as a variable reference */
#define VAR_c_NetwkCallControlCapabil_MCS(var) var

/* Access member 'MCS' of type 'c_NetwkCallControlCapabil' as a pointer */
#define PTR_c_NetwkCallControlCapabil_MCS(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NetwkCallControlCapabil {
	ED_LOCATOR MCS___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN MCS; /* ODY01a *//*GBD01b*/

}	c_NetwkCallControlCapabil;
#define INIT_c_NetwkCallControlCapabil(sp) ED_RESET_MEM ((sp), sizeof (c_NetwkCallControlCapabil))
/*FRK03a*/
void FREE_c_NetwkCallControlCapabil(c_NetwkCallControlCapabil* sp);

/* Access member 'PNB_CIoT' of type 'c_AdditionalUpdateType' as a variable reference */
#define VAR_c_AdditionalUpdateType_PNB_CIoT(var) var

/* Access member 'PNB_CIoT' of type 'c_AdditionalUpdateType' as a pointer */
#define PTR_c_AdditionalUpdateType_PNB_CIoT(var) (&var)

/* Access member 'SAF' of type 'c_AdditionalUpdateType' as a variable reference */
#define VAR_c_AdditionalUpdateType_SAF(var) var

/* Access member 'SAF' of type 'c_AdditionalUpdateType' as a pointer */
#define PTR_c_AdditionalUpdateType_SAF(var) (&var)

/* Access member 'AUTV' of type 'c_AdditionalUpdateType' as a variable reference */
#define VAR_c_AdditionalUpdateType_AUTV(var) var

/* Access member 'AUTV' of type 'c_AdditionalUpdateType' as a pointer */
#define PTR_c_AdditionalUpdateType_AUTV(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AdditionalUpdateType {
	ED_LOCATOR PNB_CIoT___LOCATOR; /* QUI2 */
	ED_LOCATOR SAF___LOCATOR; /* QUI2 */
	ED_LOCATOR AUTV___LOCATOR; /* QUI2 */

	ED_OCTET PNB_CIoT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SAF; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AUTV; /* ODY01a *//*GBD01b*/

}	c_AdditionalUpdateType;
#define INIT_c_AdditionalUpdateType(sp) ED_RESET_MEM ((sp), sizeof (c_AdditionalUpdateType))
/*FRK03a*/
void FREE_c_AdditionalUpdateType(c_AdditionalUpdateType* sp);

/* Access member 'FOP' of type 'c_AttachResult' as a variable reference */
#define VAR_c_AttachResult_FOP(var) var

/* Access member 'FOP' of type 'c_AttachResult' as a pointer */
#define PTR_c_AttachResult_FOP(var) (&var)

/* Access member 'ResultOfAttach' of type 'c_AttachResult' as a variable reference */
#define VAR_c_AttachResult_ResultOfAttach(var) var

/* Access member 'ResultOfAttach' of type 'c_AttachResult' as a pointer */
#define PTR_c_AttachResult_ResultOfAttach(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AttachResult {
	ED_LOCATOR FOP___LOCATOR; /* QUI2 */
	ED_LOCATOR ResultOfAttach___LOCATOR; /* QUI2 */

	ED_BOOLEAN FOP; /* ODY01a *//*GBD01b*/
	ED_OCTET ResultOfAttach; /* ODY01a *//*GBD01b*/

}	c_AttachResult;
#define INIT_c_AttachResult(sp) ED_RESET_MEM ((sp), sizeof (c_AttachResult))
/*FRK03a*/
void FREE_c_AttachResult(c_AttachResult* sp);

/* Access member 'xFOR' of type 'c_AttachType' as a variable reference */
#define VAR_c_AttachType_xFOR(var) var

/* Access member 'xFOR' of type 'c_AttachType' as a pointer */
#define PTR_c_AttachType_xFOR(var) (&var)

/* Access member 'TypeOfAttach' of type 'c_AttachType' as a variable reference */
#define VAR_c_AttachType_TypeOfAttach(var) var

/* Access member 'TypeOfAttach' of type 'c_AttachType' as a pointer */
#define PTR_c_AttachType_TypeOfAttach(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AttachType {
	ED_LOCATOR xFOR___LOCATOR; /* QUI2 */
	ED_LOCATOR TypeOfAttach___LOCATOR; /* QUI2 */

	ED_BOOLEAN xFOR; /* ODY01a *//*GBD01b*/
	ED_OCTET TypeOfAttach; /* ODY01a *//*GBD01b*/

}	c_AttachType;
#define INIT_c_AttachType(sp) ED_RESET_MEM ((sp), sizeof (c_AttachType))
/*FRK03a*/
void FREE_c_AttachType(c_AttachType* sp);

/* Access member 'spare' of type 'c_IntegrityProtectionAlgorithm' as a variable reference */
#define VAR_c_IntegrityProtectionAlgorithm_spare(var) var

/* Access member 'spare' of type 'c_IntegrityProtectionAlgorithm' as a pointer */
#define PTR_c_IntegrityProtectionAlgorithm_spare(var) (&var)

/* Access member 'TypeOfAlgorithm' of type 'c_IntegrityProtectionAlgorithm' as a variable reference */
#define VAR_c_IntegrityProtectionAlgorithm_TypeOfAlgorithm(var) var

/* Access member 'TypeOfAlgorithm' of type 'c_IntegrityProtectionAlgorithm' as a pointer */
#define PTR_c_IntegrityProtectionAlgorithm_TypeOfAlgorithm(var) (&var)


/*-A----------------------------------*/
typedef struct _c_IntegrityProtectionAlgorithm {
	ED_LOCATOR TypeOfAlgorithm___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET TypeOfAlgorithm; /* ODY01a *//*GBD01b*/

}	c_IntegrityProtectionAlgorithm;
#define INIT_c_IntegrityProtectionAlgorithm(sp) ED_RESET_MEM ((sp), sizeof (c_IntegrityProtectionAlgorithm))
/*FRK03a*/
void FREE_c_IntegrityProtectionAlgorithm(c_IntegrityProtectionAlgorithm* sp);

/* Access member 'spare' of type 'c_TmsiStatus' as a variable reference */
#define VAR_c_TmsiStatus_spare(var) var

/* Access member 'spare' of type 'c_TmsiStatus' as a pointer */
#define PTR_c_TmsiStatus_spare(var) (&var)

/* Access member 'TMSIFlag' of type 'c_TmsiStatus' as a variable reference */
#define VAR_c_TmsiStatus_TMSIFlag(var) var

/* Access member 'TMSIFlag' of type 'c_TmsiStatus' as a pointer */
#define PTR_c_TmsiStatus_TMSIFlag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TmsiStatus {
	ED_LOCATOR TMSIFlag___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN TMSIFlag; /* ODY01a *//*GBD01b*/

}	c_TmsiStatus;
#define INIT_c_TmsiStatus(sp) ED_RESET_MEM ((sp), sizeof (c_TmsiStatus))
/*FRK03a*/
void FREE_c_TmsiStatus(c_TmsiStatus* sp);

/* Access member 'PowerOff' of type 'c_DetachType' as a variable reference */
#define VAR_c_DetachType_PowerOff(var) var

/* Access member 'PowerOff' of type 'c_DetachType' as a pointer */
#define PTR_c_DetachType_PowerOff(var) (&var)

/* Access member 'TypeOfDetach' of type 'c_DetachType' as a variable reference */
#define VAR_c_DetachType_TypeOfDetach(var) var

/* Access member 'TypeOfDetach' of type 'c_DetachType' as a pointer */
#define PTR_c_DetachType_TypeOfDetach(var) (&var)


/*-A----------------------------------*/
typedef struct _c_DetachType {
	ED_LOCATOR PowerOff___LOCATOR; /* QUI2 */
	ED_LOCATOR TypeOfDetach___LOCATOR; /* QUI2 */

	ED_BOOLEAN PowerOff; /* ODY01a *//*GBD01b*/
	ED_OCTET TypeOfDetach; /* ODY01a *//*GBD01b*/

}	c_DetachType;
#define INIT_c_DetachType(sp) ED_RESET_MEM ((sp), sizeof (c_DetachType))
/*FRK03a*/
void FREE_c_DetachType(c_DetachType* sp);

/* Access member 'SplitPgCycleCode' of type 'c_DrxParam' as a variable reference */
#define VAR_c_DrxParam_SplitPgCycleCode(var) var

/* Access member 'SplitPgCycleCode' of type 'c_DrxParam' as a pointer */
#define PTR_c_DrxParam_SplitPgCycleCode(var) (&var)

/* Access member 'CNSpecDRX' of type 'c_DrxParam' as a variable reference */
#define VAR_c_DrxParam_CNSpecDRX(var) var

/* Access member 'CNSpecDRX' of type 'c_DrxParam' as a pointer */
#define PTR_c_DrxParam_CNSpecDRX(var) (&var)

/* Access member 'SplitOnCCCH' of type 'c_DrxParam' as a variable reference */
#define VAR_c_DrxParam_SplitOnCCCH(var) var

/* Access member 'SplitOnCCCH' of type 'c_DrxParam' as a pointer */
#define PTR_c_DrxParam_SplitOnCCCH(var) (&var)

/* Access member 'nonDRXTimer' of type 'c_DrxParam' as a variable reference */
#define VAR_c_DrxParam_nonDRXTimer(var) var

/* Access member 'nonDRXTimer' of type 'c_DrxParam' as a pointer */
#define PTR_c_DrxParam_nonDRXTimer(var) (&var)


/*-A----------------------------------*/
typedef struct _c_DrxParam {
	ED_LOCATOR SplitPgCycleCode___LOCATOR; /* QUI2 */
	ED_LOCATOR CNSpecDRX___LOCATOR; /* QUI2 */
	ED_LOCATOR SplitOnCCCH___LOCATOR; /* QUI2 */
	ED_LOCATOR nonDRXTimer___LOCATOR; /* QUI2 */

	ED_OCTET SplitPgCycleCode; /* ODY01a *//*GBD01b*/
	ED_OCTET CNSpecDRX; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SplitOnCCCH; /* ODY01a *//*GBD01b*/
	ED_OCTET nonDRXTimer; /* ODY01a *//*GBD01b*/

}	c_DrxParam;
#define INIT_c_DrxParam(sp) ED_RESET_MEM ((sp), sizeof (c_DrxParam))
/*FRK03a*/
void FREE_c_DrxParam(c_DrxParam* sp);

/* Access member 'MCC2' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_MCC2(var) var

/* Access member 'MCC2' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_MCC1(var) var

/* Access member 'MCC1' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_MNC3(var) var

/* Access member 'MNC3' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_MCC3(var) var

/* Access member 'MCC3' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_MNC2(var) var

/* Access member 'MNC2' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_MNC1(var) var

/* Access member 'MNC1' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_MNC1(var) (&var)

/* Access member 'LAC' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_LAC(var) var

/* Access member 'LAC' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_LAC(var) (&var)

/* Access member 'RAC' of type 'c_RoutingAreaIdenti' as a variable reference */
#define VAR_c_RoutingAreaIdenti_RAC(var) var

/* Access member 'RAC' of type 'c_RoutingAreaIdenti' as a pointer */
#define PTR_c_RoutingAreaIdenti_RAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RoutingAreaIdenti {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR LAC___LOCATOR; /* QUI2 */
	ED_LOCATOR RAC___LOCATOR; /* QUI2 */

	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_SHORT LAC; /* ODY01a *//*GBD01b*/
	ED_OCTET RAC; /* ODY01a *//*GBD01b*/

}	c_RoutingAreaIdenti;
#define INIT_c_RoutingAreaIdenti(sp) ED_RESET_MEM ((sp), sizeof (c_RoutingAreaIdenti))
/*FRK03a*/
void FREE_c_RoutingAreaIdenti(c_RoutingAreaIdenti* sp);

/* Access member 'MCC2' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_MCC2(var) var

/* Access member 'MCC2' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_MCC1(var) var

/* Access member 'MCC1' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_MNC3(var) var

/* Access member 'MNC3' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_MCC3(var) var

/* Access member 'MCC3' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_MNC2(var) var

/* Access member 'MNC2' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_MNC1(var) var

/* Access member 'MNC1' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_MNC1(var) (&var)

/* Access member 'LAC' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_LAC(var) var

/* Access member 'LAC' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_LAC(var) (&var)

/* Access member 'RAC' of type 'c_RoutingAreaIdenti2' as a variable reference */
#define VAR_c_RoutingAreaIdenti2_RAC(var) var

/* Access member 'RAC' of type 'c_RoutingAreaIdenti2' as a pointer */
#define PTR_c_RoutingAreaIdenti2_RAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RoutingAreaIdenti2 {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR LAC___LOCATOR; /* QUI2 */
	ED_LOCATOR RAC___LOCATOR; /* QUI2 */

	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_SHORT LAC; /* ODY01a *//*GBD01b*/
	ED_OCTET RAC; /* ODY01a *//*GBD01b*/

}	c_RoutingAreaIdenti2;
#define INIT_c_RoutingAreaIdenti2(sp) ED_RESET_MEM ((sp), sizeof (c_RoutingAreaIdenti2))
/*FRK03a*/
void FREE_c_RoutingAreaIdenti2(c_RoutingAreaIdenti2* sp);

/* Access member 'xFOR' of type 'c_UpdateType' as a variable reference */
#define VAR_c_UpdateType_xFOR(var) var

/* Access member 'xFOR' of type 'c_UpdateType' as a pointer */
#define PTR_c_UpdateType_xFOR(var) (&var)

/* Access member 'UpdateTypeValue' of type 'c_UpdateType' as a variable reference */
#define VAR_c_UpdateType_UpdateTypeValue(var) var

/* Access member 'UpdateTypeValue' of type 'c_UpdateType' as a pointer */
#define PTR_c_UpdateType_UpdateTypeValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_UpdateType {
	ED_LOCATOR xFOR___LOCATOR; /* QUI2 */
	ED_LOCATOR UpdateTypeValue___LOCATOR; /* QUI2 */

	ED_BOOLEAN xFOR; /* ODY01a *//*GBD01b*/
	ED_OCTET UpdateTypeValue; /* ODY01a *//*GBD01b*/

}	c_UpdateType;
#define INIT_c_UpdateType(sp) ED_RESET_MEM ((sp), sizeof (c_UpdateType))
/*FRK03a*/
void FREE_c_UpdateType(c_UpdateType* sp);

/* Access member 'spare' of type 'c_PSLCSCapabilit' as a variable reference */
#define VAR_c_PSLCSCapabilit_spare(var) var

/* Access member 'spare' of type 'c_PSLCSCapabilit' as a pointer */
#define PTR_c_PSLCSCapabilit_spare(var) (&var)

/* Access member 'APC' of type 'c_PSLCSCapabilit' as a variable reference */
#define VAR_c_PSLCSCapabilit_APC(var) var

/* Access member 'APC' of type 'c_PSLCSCapabilit' as a pointer */
#define PTR_c_PSLCSCapabilit_APC(var) (&var)

/* Access member 'OTD_A' of type 'c_PSLCSCapabilit' as a variable reference */
#define VAR_c_PSLCSCapabilit_OTD_A(var) var

/* Access member 'OTD_A' of type 'c_PSLCSCapabilit' as a pointer */
#define PTR_c_PSLCSCapabilit_OTD_A(var) (&var)

/* Access member 'OTD_B' of type 'c_PSLCSCapabilit' as a variable reference */
#define VAR_c_PSLCSCapabilit_OTD_B(var) var

/* Access member 'OTD_B' of type 'c_PSLCSCapabilit' as a pointer */
#define PTR_c_PSLCSCapabilit_OTD_B(var) (&var)

/* Access member 'GPS_A' of type 'c_PSLCSCapabilit' as a variable reference */
#define VAR_c_PSLCSCapabilit_GPS_A(var) var

/* Access member 'GPS_A' of type 'c_PSLCSCapabilit' as a pointer */
#define PTR_c_PSLCSCapabilit_GPS_A(var) (&var)

/* Access member 'GPS_B' of type 'c_PSLCSCapabilit' as a variable reference */
#define VAR_c_PSLCSCapabilit_GPS_B(var) var

/* Access member 'GPS_B' of type 'c_PSLCSCapabilit' as a pointer */
#define PTR_c_PSLCSCapabilit_GPS_B(var) (&var)

/* Access member 'GPS_C' of type 'c_PSLCSCapabilit' as a variable reference */
#define VAR_c_PSLCSCapabilit_GPS_C(var) var

/* Access member 'GPS_C' of type 'c_PSLCSCapabilit' as a pointer */
#define PTR_c_PSLCSCapabilit_GPS_C(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PSLCSCapabilit {
	ED_LOCATOR APC___LOCATOR; /* QUI2 */
	ED_LOCATOR OTD_A___LOCATOR; /* QUI2 */
	ED_LOCATOR OTD_B___LOCATOR; /* QUI2 */
	ED_LOCATOR GPS_A___LOCATOR; /* QUI2 */
	ED_LOCATOR GPS_B___LOCATOR; /* QUI2 */
	ED_LOCATOR GPS_C___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN APC; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OTD_A; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OTD_B; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GPS_A; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GPS_B; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GPS_C; /* ODY01a *//*GBD01b*/

}	c_PSLCSCapabilit;
#define INIT_c_PSLCSCapabilit(sp) ED_RESET_MEM ((sp), sizeof (c_PSLCSCapabilit))
/*FRK03a*/
void FREE_c_PSLCSCapabilit(c_PSLCSCapabilit* sp);

/* Access member 'LCS_MOLR' of type 'c_NetworkFeatureSupport' as a variable reference */
#define VAR_c_NetworkFeatureSupport_LCS_MOLR(var) var

/* Access member 'LCS_MOLR' of type 'c_NetworkFeatureSupport' as a pointer */
#define PTR_c_NetworkFeatureSupport_LCS_MOLR(var) (&var)

/* Access member 'MBMS' of type 'c_NetworkFeatureSupport' as a variable reference */
#define VAR_c_NetworkFeatureSupport_MBMS(var) var

/* Access member 'MBMS' of type 'c_NetworkFeatureSupport' as a pointer */
#define PTR_c_NetworkFeatureSupport_MBMS(var) (&var)

/* Access member 'IMSVoPS' of type 'c_NetworkFeatureSupport' as a variable reference */
#define VAR_c_NetworkFeatureSupport_IMSVoPS(var) var

/* Access member 'IMSVoPS' of type 'c_NetworkFeatureSupport' as a pointer */
#define PTR_c_NetworkFeatureSupport_IMSVoPS(var) (&var)

/* Access member 'EMCBS' of type 'c_NetworkFeatureSupport' as a variable reference */
#define VAR_c_NetworkFeatureSupport_EMCBS(var) var

/* Access member 'EMCBS' of type 'c_NetworkFeatureSupport' as a pointer */
#define PTR_c_NetworkFeatureSupport_EMCBS(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NetworkFeatureSupport {
	ED_LOCATOR LCS_MOLR___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMS___LOCATOR; /* QUI2 */
	ED_LOCATOR IMSVoPS___LOCATOR; /* QUI2 */
	ED_LOCATOR EMCBS___LOCATOR; /* QUI2 */

	ED_BOOLEAN LCS_MOLR; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MBMS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IMSVoPS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMCBS; /* ODY01a *//*GBD01b*/

}	c_NetworkFeatureSupport;
#define INIT_c_NetworkFeatureSupport(sp) ED_RESET_MEM ((sp), sizeof (c_NetworkFeatureSupport))
/*FRK03a*/
void FREE_c_NetworkFeatureSupport(c_NetworkFeatureSupport* sp);

/* Access member 'spare' of type 'c_AdditionalNetworkFeatureSupport' as a variable reference */
#define VAR_c_AdditionalNetworkFeatureSupport_spare(var) var

/* Access member 'spare' of type 'c_AdditionalNetworkFeatureSupport' as a pointer */
#define PTR_c_AdditionalNetworkFeatureSupport_spare(var) (&var)

/* Access member 'GPRS_SMS' of type 'c_AdditionalNetworkFeatureSupport' as a variable reference */
#define VAR_c_AdditionalNetworkFeatureSupport_GPRS_SMS(var) var

/* Access member 'GPRS_SMS' of type 'c_AdditionalNetworkFeatureSupport' as a pointer */
#define PTR_c_AdditionalNetworkFeatureSupport_GPRS_SMS(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AdditionalNetworkFeatureSupport {
	ED_LOCATOR GPRS_SMS___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN GPRS_SMS; /* ODY01a *//*GBD01b*/

}	c_AdditionalNetworkFeatureSupport;
#define INIT_c_AdditionalNetworkFeatureSupport(sp) ED_RESET_MEM ((sp), sizeof (c_AdditionalNetworkFeatureSupport))
/*FRK03a*/
void FREE_c_AdditionalNetworkFeatureSupport(c_AdditionalNetworkFeatureSupport* sp);

/* Access member 'I_RAT' of type 'c_RequestedMSInformation' as a variable reference */
#define VAR_c_RequestedMSInformation_I_RAT(var) var

/* Access member 'I_RAT' of type 'c_RequestedMSInformation' as a pointer */
#define PTR_c_RequestedMSInformation_I_RAT(var) (&var)

/* Access member 'I_RAT2' of type 'c_RequestedMSInformation' as a variable reference */
#define VAR_c_RequestedMSInformation_I_RAT2(var) var

/* Access member 'I_RAT2' of type 'c_RequestedMSInformation' as a pointer */
#define PTR_c_RequestedMSInformation_I_RAT2(var) (&var)

/* Access member 'spare' of type 'c_RequestedMSInformation' as a variable reference */
#define VAR_c_RequestedMSInformation_spare(var) var

/* Access member 'spare' of type 'c_RequestedMSInformation' as a pointer */
#define PTR_c_RequestedMSInformation_spare(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RequestedMSInformation {
	ED_LOCATOR I_RAT___LOCATOR; /* QUI2 */
	ED_LOCATOR I_RAT2___LOCATOR; /* QUI2 */

	ED_BOOLEAN I_RAT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN I_RAT2; /* ODY01a *//*GBD01b*/
	/*GBD01b*/

}	c_RequestedMSInformation;
#define INIT_c_RequestedMSInformation(sp) ED_RESET_MEM ((sp), sizeof (c_RequestedMSInformation))
/*FRK03a*/
void FREE_c_RequestedMSInformation(c_RequestedMSInformation* sp);

/* Access member 'spare' of type 'c_VoiceDomainPreferenceAndUEsUsageSetting' as a variable reference */
#define VAR_c_VoiceDomainPreferenceAndUEsUsageSetting_spare(var) var

/* Access member 'spare' of type 'c_VoiceDomainPreferenceAndUEsUsageSetting' as a pointer */
#define PTR_c_VoiceDomainPreferenceAndUEsUsageSetting_spare(var) (&var)

/* Access member 'UEUsageSetting' of type 'c_VoiceDomainPreferenceAndUEsUsageSetting' as a variable reference */
#define VAR_c_VoiceDomainPreferenceAndUEsUsageSetting_UEUsageSetting(var) var

/* Access member 'UEUsageSetting' of type 'c_VoiceDomainPreferenceAndUEsUsageSetting' as a pointer */
#define PTR_c_VoiceDomainPreferenceAndUEsUsageSetting_UEUsageSetting(var) (&var)

/* Access member 'VoiceDomainPreferenceForEUTRAN' of type 'c_VoiceDomainPreferenceAndUEsUsageSetting' as a variable reference */
#define VAR_c_VoiceDomainPreferenceAndUEsUsageSetting_VoiceDomainPreferenceForEUTRAN(var) var

/* Access member 'VoiceDomainPreferenceForEUTRAN' of type 'c_VoiceDomainPreferenceAndUEsUsageSetting' as a pointer */
#define PTR_c_VoiceDomainPreferenceAndUEsUsageSetting_VoiceDomainPreferenceForEUTRAN(var) (&var)


/*-A----------------------------------*/
typedef struct _c_VoiceDomainPreferenceAndUEsUsageSetting {
	ED_LOCATOR UEUsageSetting___LOCATOR; /* QUI2 */
	ED_LOCATOR VoiceDomainPreferenceForEUTRAN___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN UEUsageSetting; /* ODY01a *//*GBD01b*/
	ED_OCTET VoiceDomainPreferenceForEUTRAN; /* ODY01a *//*GBD01b*/

}	c_VoiceDomainPreferenceAndUEsUsageSetting;
#define INIT_c_VoiceDomainPreferenceAndUEsUsageSetting(sp) ED_RESET_MEM ((sp), sizeof (c_VoiceDomainPreferenceAndUEsUsageSetting))
/*FRK03a*/
void FREE_c_VoiceDomainPreferenceAndUEsUsageSetting(c_VoiceDomainPreferenceAndUEsUsageSetting* sp);

/* Access member 'spare' of type 'c_PTMSI_Type' as a variable reference */
#define VAR_c_PTMSI_Type_spare(var) var

/* Access member 'spare' of type 'c_PTMSI_Type' as a pointer */
#define PTR_c_PTMSI_Type_spare(var) (&var)

/* Access member 'PTMSI_Type' of type 'c_PTMSI_Type' as a variable reference */
#define VAR_c_PTMSI_Type_PTMSI_Type(var) var

/* Access member 'PTMSI_Type' of type 'c_PTMSI_Type' as a pointer */
#define PTR_c_PTMSI_Type_PTMSI_Type(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PTMSI_Type {
	ED_LOCATOR PTMSI_Type___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN PTMSI_Type; /* ODY01a *//*GBD01b*/

}	c_PTMSI_Type;
#define INIT_c_PTMSI_Type(sp) ED_RESET_MEM ((sp), sizeof (c_PTMSI_Type))
/*FRK03a*/
void FREE_c_PTMSI_Type(c_PTMSI_Type* sp);

/* Access member 'NRIContainerValue' of type 'c_NetworkResourceIdContainer' as a variable reference */
#define VAR_c_NetworkResourceIdContainer_NRIContainerValue(var) var

/* Access member 'NRIContainerValue' of type 'c_NetworkResourceIdContainer' as a pointer */
#define PTR_c_NetworkResourceIdContainer_NRIContainerValue(var) (&var)

/* Access member 'spare' of type 'c_NetworkResourceIdContainer' as a variable reference */
#define VAR_c_NetworkResourceIdContainer_spare(var) var

/* Access member 'spare' of type 'c_NetworkResourceIdContainer' as a pointer */
#define PTR_c_NetworkResourceIdContainer_spare(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NetworkResourceIdContainer {
	ED_LOCATOR NRIContainerValue___LOCATOR; /* QUI2 */

	ED_SHORT NRIContainerValue; /* ODY01a *//*GBD01b*/
	/*GBD01b*/

}	c_NetworkResourceIdContainer;
#define INIT_c_NetworkResourceIdContainer(sp) ED_RESET_MEM ((sp), sizeof (c_NetworkResourceIdContainer))
/*FRK03a*/
void FREE_c_NetworkResourceIdContainer(c_NetworkResourceIdContainer* sp);

/* Access member 'PagingTimeWindow' of type 'c_ExtendedDRXParameters' as a variable reference */
#define VAR_c_ExtendedDRXParameters_PagingTimeWindow(var) var

/* Access member 'PagingTimeWindow' of type 'c_ExtendedDRXParameters' as a pointer */
#define PTR_c_ExtendedDRXParameters_PagingTimeWindow(var) (&var)

/* Access member 'eDRXValue' of type 'c_ExtendedDRXParameters' as a variable reference */
#define VAR_c_ExtendedDRXParameters_eDRXValue(var) var

/* Access member 'eDRXValue' of type 'c_ExtendedDRXParameters' as a pointer */
#define PTR_c_ExtendedDRXParameters_eDRXValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ExtendedDRXParameters {
	ED_LOCATOR PagingTimeWindow___LOCATOR; /* QUI2 */
	ED_LOCATOR eDRXValue___LOCATOR; /* QUI2 */

	ED_OCTET PagingTimeWindow; /* ODY01a *//*GBD01b*/
	ED_OCTET eDRXValue; /* ODY01a *//*GBD01b*/

}	c_ExtendedDRXParameters;
#define INIT_c_ExtendedDRXParameters(sp) ED_RESET_MEM ((sp), sizeof (c_ExtendedDRXParameters))
/*FRK03a*/
void FREE_c_ExtendedDRXParameters(c_ExtendedDRXParameters* sp);

/* Access member 'spare' of type 'c_NetwkServAccessPointId' as a variable reference */
#define VAR_c_NetwkServAccessPointId_spare(var) var

/* Access member 'spare' of type 'c_NetwkServAccessPointId' as a pointer */
#define PTR_c_NetwkServAccessPointId_spare(var) (&var)

/* Access member 'NSAPIValue' of type 'c_NetwkServAccessPointId' as a variable reference */
#define VAR_c_NetwkServAccessPointId_NSAPIValue(var) var

/* Access member 'NSAPIValue' of type 'c_NetwkServAccessPointId' as a pointer */
#define PTR_c_NetwkServAccessPointId_NSAPIValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NetwkServAccessPointId {
	ED_LOCATOR NSAPIValue___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET NSAPIValue; /* ODY01a *//*GBD01b*/

}	c_NetwkServAccessPointId;
#define INIT_c_NetwkServAccessPointId(sp) ED_RESET_MEM ((sp), sizeof (c_NetwkServAccessPointId))
/*FRK03a*/
void FREE_c_NetwkServAccessPointId(c_NetwkServAccessPointId* sp);

/* Access member 'spare' of type 'c_PacketDataProtocolAddr' as a variable reference */
#define VAR_c_PacketDataProtocolAddr_spare(var) var

/* Access member 'spare' of type 'c_PacketDataProtocolAddr' as a pointer */
#define PTR_c_PacketDataProtocolAddr_spare(var) (&var)

/* Access member 'PDPTypeOrganisation' of type 'c_PacketDataProtocolAddr' as a variable reference */
#define VAR_c_PacketDataProtocolAddr_PDPTypeOrganisation(var) var

/* Access member 'PDPTypeOrganisation' of type 'c_PacketDataProtocolAddr' as a pointer */
#define PTR_c_PacketDataProtocolAddr_PDPTypeOrganisation(var) (&var)

/* Access member 'PDPTypeNumber' of type 'c_PacketDataProtocolAddr' as a variable reference */
#define VAR_c_PacketDataProtocolAddr_PDPTypeNumber(var) var

/* Access member 'PDPTypeNumber' of type 'c_PacketDataProtocolAddr' as a pointer */
#define PTR_c_PacketDataProtocolAddr_PDPTypeNumber(var) (&var)

/* Access member 'AddressInformation' of type 'c_PacketDataProtocolAddr' as a variable reference */
#define VAR_c_PacketDataProtocolAddr_AddressInformation(var) var

/* Access member 'AddressInformation' of type 'c_PacketDataProtocolAddr' as a pointer */
#define PTR_c_PacketDataProtocolAddr_AddressInformation(var) (&var)

/* DEFINITION OF BINARY c_PacketDataProtocolAddr_AddressInformation */
typedef struct _c_PacketDataProtocolAddr_AddressInformation {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_PacketDataProtocolAddr_AddressInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_PacketDataProtocolAddr_AddressInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_PacketDataProtocolAddr {
	ED_LOCATOR PDPTypeOrganisation___LOCATOR; /* QUI2 */
	ED_LOCATOR PDPTypeNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR AddressInformation___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET PDPTypeOrganisation; /* ODY01a *//*GBD01b*/
	ED_OCTET PDPTypeNumber; /* ODY01a *//*GBD01b*/
	c_PacketDataProtocolAddr_AddressInformation AddressInformation; /* Static, variable size; bits needed 128 *//*GBD01b*/

}	c_PacketDataProtocolAddr;
#define INIT_c_PacketDataProtocolAddr(sp) ED_RESET_MEM ((sp), sizeof (c_PacketDataProtocolAddr))
/*FRK03a*/
void FREE_c_PacketDataProtocolAddr(c_PacketDataProtocolAddr* sp);

/* Access member 'spare1' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_spare1(var) var

/* Access member 'spare1' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_spare1(var) (&var)

/* Access member 'DelayClass' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_DelayClass(var) var

/* Access member 'DelayClass' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_DelayClass(var) (&var)

/* Access member 'ReliabilityClass' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_ReliabilityClass(var) var

/* Access member 'ReliabilityClass' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_ReliabilityClass(var) (&var)

/* Access member 'PeakThroughput' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_PeakThroughput(var) var

/* Access member 'PeakThroughput' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_PeakThroughput(var) (&var)

/* Access member 'spare2' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_spare2(var) var

/* Access member 'spare2' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_spare2(var) (&var)

/* Access member 'PrecedenceClass' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_PrecedenceClass(var) var

/* Access member 'PrecedenceClass' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_PrecedenceClass(var) (&var)

/* Access member 'spare3' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_spare3(var) var

/* Access member 'spare3' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_spare3(var) (&var)

/* Access member 'MeanThroughput' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MeanThroughput(var) var

/* Access member 'MeanThroughput' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MeanThroughput(var) (&var)

/* Access member 'TrafficClass' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_TrafficClass(var) var

/* Access member 'TrafficClass' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_TrafficClass(var) (&var)

/* Access member 'DeliveryOrder' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_DeliveryOrder(var) var

/* Access member 'DeliveryOrder' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_DeliveryOrder(var) (&var)

/* Access member 'DeliveryOfErroneusSDU' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_DeliveryOfErroneusSDU(var) var

/* Access member 'DeliveryOfErroneusSDU' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_DeliveryOfErroneusSDU(var) (&var)

/* Access member 'MaximumSDUSize' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MaximumSDUSize(var) var

/* Access member 'MaximumSDUSize' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MaximumSDUSize(var) (&var)

/* Access member 'MaximumBitRateForUplink' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MaximumBitRateForUplink(var) var

/* Access member 'MaximumBitRateForUplink' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MaximumBitRateForUplink(var) (&var)

/* Access member 'MaximumBitRateForDownlink' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MaximumBitRateForDownlink(var) var

/* Access member 'MaximumBitRateForDownlink' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MaximumBitRateForDownlink(var) (&var)

/* Access member 'ResidualBER' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_ResidualBER(var) var

/* Access member 'ResidualBER' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_ResidualBER(var) (&var)

/* Access member 'SDUErrorRatio' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_SDUErrorRatio(var) var

/* Access member 'SDUErrorRatio' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_SDUErrorRatio(var) (&var)

/* Access member 'TransderDelay' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_TransderDelay(var) var

/* Access member 'TransderDelay' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_TransderDelay(var) (&var)

/* Access member 'TrafficHandlingPriority' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_TrafficHandlingPriority(var) var

/* Access member 'TrafficHandlingPriority' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_TrafficHandlingPriority(var) (&var)

/* Access member 'GuaranteedBitRateForUplink' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_GuaranteedBitRateForUplink(var) var

/* Access member 'GuaranteedBitRateForUplink' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_GuaranteedBitRateForUplink(var) (&var)

/* Access member 'GuaranteedBitRateForDownlink' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_GuaranteedBitRateForDownlink(var) var

/* Access member 'GuaranteedBitRateForDownlink' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_GuaranteedBitRateForDownlink(var) (&var)

/* Access member 'spare4' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_spare4(var) var

/* Access member 'spare4' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_spare4(var) (&var)

/* Access member 'SignalingIndication' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_SignalingIndication(var) var

/* Access member 'SignalingIndication' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_SignalingIndication(var) (&var)

/* Access member 'SourceStatisticsDescriptor' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_SourceStatisticsDescriptor(var) var

/* Access member 'SourceStatisticsDescriptor' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_SourceStatisticsDescriptor(var) (&var)

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MaximumBitRateForDownlinkExt(var) var

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MaximumBitRateForDownlinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_GuaranteedBitRateForDownlinkExt(var) var

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_GuaranteedBitRateForDownlinkExt(var) (&var)

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MaximumBitRateForUplinkExt(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MaximumBitRateForUplinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_GuaranteedBitRateForUplinkExt(var) var

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_GuaranteedBitRateForUplinkExt(var) (&var)

/* Access member 'MaximumBitRateForDownlinkExt2' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MaximumBitRateForDownlinkExt2(var) var

/* Access member 'MaximumBitRateForDownlinkExt2' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MaximumBitRateForDownlinkExt2(var) (&var)

/* Access member 'GuaranteedBitRateForDownlinkExt2' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_GuaranteedBitRateForDownlinkExt2(var) var

/* Access member 'GuaranteedBitRateForDownlinkExt2' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_GuaranteedBitRateForDownlinkExt2(var) (&var)

/* Access member 'MaximumBitRateForUplinkExt2' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_MaximumBitRateForUplinkExt2(var) var

/* Access member 'MaximumBitRateForUplinkExt2' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_MaximumBitRateForUplinkExt2(var) (&var)

/* Access member 'GuaranteedBitRateForUplinkExt2' of type 'c_QualityOfServ' as a variable reference */
#define VAR_c_QualityOfServ_GuaranteedBitRateForUplinkExt2(var) var

/* Access member 'GuaranteedBitRateForUplinkExt2' of type 'c_QualityOfServ' as a pointer */
#define PTR_c_QualityOfServ_GuaranteedBitRateForUplinkExt2(var) (&var)


/*-A----------------------------------*/
typedef struct _c_QualityOfServ {
	ED_LOCATOR DelayClass___LOCATOR; /* QUI2 */
	ED_LOCATOR ReliabilityClass___LOCATOR; /* QUI2 */
	ED_LOCATOR PeakThroughput___LOCATOR; /* QUI2 */
	ED_LOCATOR PrecedenceClass___LOCATOR; /* QUI2 */
	ED_LOCATOR MeanThroughput___LOCATOR; /* QUI2 */
	ED_LOCATOR TrafficClass___LOCATOR; /* QUI2 */
	ED_LOCATOR DeliveryOrder___LOCATOR; /* QUI2 */
	ED_LOCATOR DeliveryOfErroneusSDU___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumSDUSize___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForUplink___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForDownlink___LOCATOR; /* QUI2 */
	ED_LOCATOR ResidualBER___LOCATOR; /* QUI2 */
	ED_LOCATOR SDUErrorRatio___LOCATOR; /* QUI2 */
	ED_LOCATOR TransderDelay___LOCATOR; /* QUI2 */
	ED_LOCATOR TrafficHandlingPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplink___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlink___LOCATOR; /* QUI2 */
	ED_LOCATOR SignalingIndication___LOCATOR; /* QUI2 */
	ED_LOCATOR SourceStatisticsDescriptor___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForDownlinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForDownlinkExt2___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlinkExt2___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForUplinkExt2___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplinkExt2___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET DelayClass; /* ODY01a *//*GBD01b*/
	ED_OCTET ReliabilityClass; /* ODY01a *//*GBD01b*/
	ED_OCTET PeakThroughput; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET PrecedenceClass; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET MeanThroughput; /* ODY01a *//*GBD01b*/
	ED_OCTET TrafficClass; /* ODY01a *//*GBD01b*/
	ED_OCTET DeliveryOrder; /* ODY01a *//*GBD01b*/
	ED_OCTET DeliveryOfErroneusSDU; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumSDUSize; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForUplink; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForDownlink; /* ODY01a *//*GBD01b*/
	ED_OCTET ResidualBER; /* ODY01a *//*GBD01b*/
	ED_OCTET SDUErrorRatio; /* ODY01a *//*GBD01b*/
	ED_OCTET TransderDelay; /* ODY01a *//*GBD01b*/
	ED_OCTET TrafficHandlingPriority; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplink; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlink; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN SignalingIndication; /* ODY01a *//*GBD01b*/
	ED_OCTET SourceStatisticsDescriptor; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForDownlinkExt2; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlinkExt2; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForUplinkExt2; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplinkExt2; /* ODY01a *//*GBD01b*/

}	c_QualityOfServ;
#define INIT_c_QualityOfServ(sp) ED_RESET_MEM ((sp), sizeof (c_QualityOfServ))
/*FRK03a*/
void FREE_c_QualityOfServ(c_QualityOfServ* sp);

/* Access member 'spare' of type 'c_ReAttemptIndicator' as a variable reference */
#define VAR_c_ReAttemptIndicator_spare(var) var

/* Access member 'spare' of type 'c_ReAttemptIndicator' as a pointer */
#define PTR_c_ReAttemptIndicator_spare(var) (&var)

/* Access member 'EPLMNC' of type 'c_ReAttemptIndicator' as a variable reference */
#define VAR_c_ReAttemptIndicator_EPLMNC(var) var

/* Access member 'EPLMNC' of type 'c_ReAttemptIndicator' as a pointer */
#define PTR_c_ReAttemptIndicator_EPLMNC(var) (&var)

/* Access member 'RATC' of type 'c_ReAttemptIndicator' as a variable reference */
#define VAR_c_ReAttemptIndicator_RATC(var) var

/* Access member 'RATC' of type 'c_ReAttemptIndicator' as a pointer */
#define PTR_c_ReAttemptIndicator_RATC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ReAttemptIndicator {
	ED_LOCATOR EPLMNC___LOCATOR; /* QUI2 */
	ED_LOCATOR RATC___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN EPLMNC; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RATC; /* ODY01a *//*GBD01b*/

}	c_ReAttemptIndicator;
#define INIT_c_ReAttemptIndicator(sp) ED_RESET_MEM ((sp), sizeof (c_ReAttemptIndicator))
/*FRK03a*/
void FREE_c_ReAttemptIndicator(c_ReAttemptIndicator* sp);

/* Access member 'Cause' of type 'c_SMCause' as a variable reference */
#define VAR_c_SMCause_Cause(var) var

/* Access member 'Cause' of type 'c_SMCause' as a pointer */
#define PTR_c_SMCause_Cause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_SMCause {
	ED_LOCATOR Cause___LOCATOR; /* QUI2 */

	ED_OCTET Cause; /* ODY01a *//*GBD01b*/

}	c_SMCause;
#define INIT_c_SMCause(sp) ED_RESET_MEM ((sp), sizeof (c_SMCause))
/*FRK03a*/
void FREE_c_SMCause(c_SMCause* sp);

/* Access member 'spare' of type 'c_LlcServAccessPointId' as a variable reference */
#define VAR_c_LlcServAccessPointId_spare(var) var

/* Access member 'spare' of type 'c_LlcServAccessPointId' as a pointer */
#define PTR_c_LlcServAccessPointId_spare(var) (&var)

/* Access member 'LLCSAPIValue' of type 'c_LlcServAccessPointId' as a variable reference */
#define VAR_c_LlcServAccessPointId_LLCSAPIValue(var) var

/* Access member 'LLCSAPIValue' of type 'c_LlcServAccessPointId' as a pointer */
#define PTR_c_LlcServAccessPointId_LLCSAPIValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_LlcServAccessPointId {
	ED_LOCATOR LLCSAPIValue___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET LLCSAPIValue; /* ODY01a *//*GBD01b*/

}	c_LlcServAccessPointId;
#define INIT_c_LlcServAccessPointId(sp) ED_RESET_MEM ((sp), sizeof (c_LlcServAccessPointId))
/*FRK03a*/
void FREE_c_LlcServAccessPointId(c_LlcServAccessPointId* sp);

/* Access member 'spare' of type 'c_TearDownInd' as a variable reference */
#define VAR_c_TearDownInd_spare(var) var

/* Access member 'spare' of type 'c_TearDownInd' as a pointer */
#define PTR_c_TearDownInd_spare(var) (&var)

/* Access member 'TDIFlag' of type 'c_TearDownInd' as a variable reference */
#define VAR_c_TearDownInd_TDIFlag(var) var

/* Access member 'TDIFlag' of type 'c_TearDownInd' as a pointer */
#define PTR_c_TearDownInd_TDIFlag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TearDownInd {
	ED_LOCATOR TDIFlag___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN TDIFlag; /* ODY01a *//*GBD01b*/

}	c_TearDownInd;
#define INIT_c_TearDownInd(sp) ED_RESET_MEM ((sp), sizeof (c_TearDownInd))
/*FRK03a*/
void FREE_c_TearDownInd(c_TearDownInd* sp);

/* Access member 'spare' of type 'c_PacketFlowIdentifie' as a variable reference */
#define VAR_c_PacketFlowIdentifie_spare(var) var

/* Access member 'spare' of type 'c_PacketFlowIdentifie' as a pointer */
#define PTR_c_PacketFlowIdentifie_spare(var) (&var)

/* Access member 'PacketFlowIdentifierValue' of type 'c_PacketFlowIdentifie' as a variable reference */
#define VAR_c_PacketFlowIdentifie_PacketFlowIdentifierValue(var) var

/* Access member 'PacketFlowIdentifierValue' of type 'c_PacketFlowIdentifie' as a pointer */
#define PTR_c_PacketFlowIdentifie_PacketFlowIdentifierValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PacketFlowIdentifie {
	ED_LOCATOR PacketFlowIdentifierValue___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET PacketFlowIdentifierValue; /* ODY01a *//*GBD01b*/

}	c_PacketFlowIdentifie;
#define INIT_c_PacketFlowIdentifie(sp) ED_RESET_MEM ((sp), sizeof (c_PacketFlowIdentifie))
/*FRK03a*/
void FREE_c_PacketFlowIdentifie(c_PacketFlowIdentifie* sp);

/* Access member 'MBMSServiceId' of type 'c_TempMobileGroupId' as a variable reference */
#define VAR_c_TempMobileGroupId_MBMSServiceId(var) var

/* Access member 'MBMSServiceId' of type 'c_TempMobileGroupId' as a pointer */
#define PTR_c_TempMobileGroupId_MBMSServiceId(var) (&var)

/* Access member 'Numbers' of type 'c_TempMobileGroupId' as a variable reference */
#define VAR_c_TempMobileGroupId_Numbers(var) var

/* Access member 'Numbers' of type 'c_TempMobileGroupId' as a pointer */
#define PTR_c_TempMobileGroupId_Numbers(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TempMobileGroupId {
	ED_LOCATOR MBMSServiceId___LOCATOR; /* QUI2 */

	ED_LONG MBMSServiceId; /* ODY01a *//*GBD01b*/
	c_TempMobileNumbers Numbers; /* ODY01a *//*GBD01b*/

}	c_TempMobileGroupId;
#define INIT_c_TempMobileGroupId(sp) ED_RESET_MEM ((sp), sizeof (c_TempMobileGroupId))
/*FRK03a*/
void FREE_c_TempMobileGroupId(c_TempMobileGroupId* sp);

/* Access member 'MaximumBitRateDownlink' of type 'c_MBMSBearerCapabilities' as a variable reference */
#define VAR_c_MBMSBearerCapabilities_MaximumBitRateDownlink(var) var

/* Access member 'MaximumBitRateDownlink' of type 'c_MBMSBearerCapabilities' as a pointer */
#define PTR_c_MBMSBearerCapabilities_MaximumBitRateDownlink(var) (&var)

/* Access member 'MaximumBitRateDownlinkExt' of type 'c_MBMSBearerCapabilities' as a variable reference */
#define VAR_c_MBMSBearerCapabilities_MaximumBitRateDownlinkExt(var) var

/* Access member 'MaximumBitRateDownlinkExt' of type 'c_MBMSBearerCapabilities' as a pointer */
#define PTR_c_MBMSBearerCapabilities_MaximumBitRateDownlinkExt(var) (&var)


/*-A----------------------------------*/
typedef struct _c_MBMSBearerCapabilities {
	ED_LOCATOR MaximumBitRateDownlink___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateDownlinkExt___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateDownlink; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateDownlinkExt; /* ODY01a *//*GBD01b*/

}	c_MBMSBearerCapabilities;
#define INIT_c_MBMSBearerCapabilities(sp) ED_RESET_MEM ((sp), sizeof (c_MBMSBearerCapabilities))
/*FRK03a*/
void FREE_c_MBMSBearerCapabilities(c_MBMSBearerCapabilities* sp);

/* Access member 'spare' of type 'c_WLANOffloadAcceptability' as a variable reference */
#define VAR_c_WLANOffloadAcceptability_spare(var) var

/* Access member 'spare' of type 'c_WLANOffloadAcceptability' as a pointer */
#define PTR_c_WLANOffloadAcceptability_spare(var) (&var)

/* Access member 'UTRANOffloadAcceptabilityValue' of type 'c_WLANOffloadAcceptability' as a variable reference */
#define VAR_c_WLANOffloadAcceptability_UTRANOffloadAcceptabilityValue(var) var

/* Access member 'UTRANOffloadAcceptabilityValue' of type 'c_WLANOffloadAcceptability' as a pointer */
#define PTR_c_WLANOffloadAcceptability_UTRANOffloadAcceptabilityValue(var) (&var)

/* Access member 'EUTRANOffloadAcceptabilityValue' of type 'c_WLANOffloadAcceptability' as a variable reference */
#define VAR_c_WLANOffloadAcceptability_EUTRANOffloadAcceptabilityValue(var) var

/* Access member 'EUTRANOffloadAcceptabilityValue' of type 'c_WLANOffloadAcceptability' as a pointer */
#define PTR_c_WLANOffloadAcceptability_EUTRANOffloadAcceptabilityValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_WLANOffloadAcceptability {
	ED_LOCATOR UTRANOffloadAcceptabilityValue___LOCATOR; /* QUI2 */
	ED_LOCATOR EUTRANOffloadAcceptabilityValue___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN UTRANOffloadAcceptabilityValue; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EUTRANOffloadAcceptabilityValue; /* ODY01a *//*GBD01b*/

}	c_WLANOffloadAcceptability;
#define INIT_c_WLANOffloadAcceptability(sp) ED_RESET_MEM ((sp), sizeof (c_WLANOffloadAcceptability))
/*FRK03a*/
void FREE_c_WLANOffloadAcceptability(c_WLANOffloadAcceptability* sp);

/* Access member 'Unit' of type 'c_GprsTimer' as a variable reference */
#define VAR_c_GprsTimer_Unit(var) var

/* Access member 'Unit' of type 'c_GprsTimer' as a pointer */
#define PTR_c_GprsTimer_Unit(var) (&var)

/* Access member 'TimerValue' of type 'c_GprsTimer' as a variable reference */
#define VAR_c_GprsTimer_TimerValue(var) var

/* Access member 'TimerValue' of type 'c_GprsTimer' as a pointer */
#define PTR_c_GprsTimer_TimerValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_GprsTimer {
	ED_LOCATOR Unit___LOCATOR; /* QUI2 */
	ED_LOCATOR TimerValue___LOCATOR; /* QUI2 */

	ED_OCTET Unit; /* ODY01a *//*GBD01b*/
	ED_OCTET TimerValue; /* ODY01a *//*GBD01b*/

}	c_GprsTimer;
#define INIT_c_GprsTimer(sp) ED_RESET_MEM ((sp), sizeof (c_GprsTimer))
/*FRK03a*/
void FREE_c_GprsTimer(c_GprsTimer* sp);

/* Access member 'Unit' of type 'c_GprsTimer2' as a variable reference */
#define VAR_c_GprsTimer2_Unit(var) var

/* Access member 'Unit' of type 'c_GprsTimer2' as a pointer */
#define PTR_c_GprsTimer2_Unit(var) (&var)

/* Access member 'TimerValue' of type 'c_GprsTimer2' as a variable reference */
#define VAR_c_GprsTimer2_TimerValue(var) var

/* Access member 'TimerValue' of type 'c_GprsTimer2' as a pointer */
#define PTR_c_GprsTimer2_TimerValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_GprsTimer2 {
	ED_LOCATOR Unit___LOCATOR; /* QUI2 */
	ED_LOCATOR TimerValue___LOCATOR; /* QUI2 */

	ED_OCTET Unit; /* ODY01a *//*GBD01b*/
	ED_OCTET TimerValue; /* ODY01a *//*GBD01b*/

}	c_GprsTimer2;
#define INIT_c_GprsTimer2(sp) ED_RESET_MEM ((sp), sizeof (c_GprsTimer2))
/*FRK03a*/
void FREE_c_GprsTimer2(c_GprsTimer2* sp);

/* Access member 'Unit' of type 'c_GprsTimer3' as a variable reference */
#define VAR_c_GprsTimer3_Unit(var) var

/* Access member 'Unit' of type 'c_GprsTimer3' as a pointer */
#define PTR_c_GprsTimer3_Unit(var) (&var)

/* Access member 'TimerValue' of type 'c_GprsTimer3' as a variable reference */
#define VAR_c_GprsTimer3_TimerValue(var) var

/* Access member 'TimerValue' of type 'c_GprsTimer3' as a pointer */
#define PTR_c_GprsTimer3_TimerValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_GprsTimer3 {
	ED_LOCATOR Unit___LOCATOR; /* QUI2 */
	ED_LOCATOR TimerValue___LOCATOR; /* QUI2 */

	ED_OCTET Unit; /* ODY01a *//*GBD01b*/
	ED_OCTET TimerValue; /* ODY01a *//*GBD01b*/

}	c_GprsTimer3;
#define INIT_c_GprsTimer3(sp) ED_RESET_MEM ((sp), sizeof (c_GprsTimer3))
/*FRK03a*/
void FREE_c_GprsTimer3(c_GprsTimer3* sp);

/* Access member 'NSAPI_07' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_07(var) var

/* Access member 'NSAPI_07' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_07(var) (&var)

/* Access member 'NSAPI_06' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_06(var) var

/* Access member 'NSAPI_06' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_06(var) (&var)

/* Access member 'NSAPI_05' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_05(var) var

/* Access member 'NSAPI_05' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_05(var) (&var)

/* Access member 'spare1' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_spare1(var) var

/* Access member 'spare1' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_spare1(var) (&var)

/* Access member 'NSAPI_15' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_15(var) var

/* Access member 'NSAPI_15' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_15(var) (&var)

/* Access member 'NSAPI_14' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_14(var) var

/* Access member 'NSAPI_14' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_14(var) (&var)

/* Access member 'NSAPI_13' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_13(var) var

/* Access member 'NSAPI_13' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_13(var) (&var)

/* Access member 'NSAPI_12' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_12(var) var

/* Access member 'NSAPI_12' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_12(var) (&var)

/* Access member 'NSAPI_11' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_11(var) var

/* Access member 'NSAPI_11' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_11(var) (&var)

/* Access member 'NSAPI_10' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_10(var) var

/* Access member 'NSAPI_10' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_10(var) (&var)

/* Access member 'NSAPI_09' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_09(var) var

/* Access member 'NSAPI_09' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_09(var) (&var)

/* Access member 'NSAPI_08' of type 'c_UplinkDataStatus' as a variable reference */
#define VAR_c_UplinkDataStatus_NSAPI_08(var) var

/* Access member 'NSAPI_08' of type 'c_UplinkDataStatus' as a pointer */
#define PTR_c_UplinkDataStatus_NSAPI_08(var) (&var)


/*-A----------------------------------*/
typedef struct _c_UplinkDataStatus {
	ED_LOCATOR NSAPI_07___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_06___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_05___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_15___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_14___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_13___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_12___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_11___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_10___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_09___LOCATOR; /* QUI2 */
	ED_LOCATOR NSAPI_08___LOCATOR; /* QUI2 */

	ED_BOOLEAN NSAPI_07; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_06; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_05; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN NSAPI_15; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_14; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_13; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_12; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_11; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_10; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_09; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NSAPI_08; /* ODY01a *//*GBD01b*/

}	c_UplinkDataStatus;
#define INIT_c_UplinkDataStatus(sp) ED_RESET_MEM ((sp), sizeof (c_UplinkDataStatus))
/*FRK03a*/
void FREE_c_UplinkDataStatus(c_UplinkDataStatus* sp);

/* Access member 'spare' of type 'c_DeviceProperties' as a variable reference */
#define VAR_c_DeviceProperties_spare(var) var

/* Access member 'spare' of type 'c_DeviceProperties' as a pointer */
#define PTR_c_DeviceProperties_spare(var) (&var)

/* Access member 'LowPriority' of type 'c_DeviceProperties' as a variable reference */
#define VAR_c_DeviceProperties_LowPriority(var) var

/* Access member 'LowPriority' of type 'c_DeviceProperties' as a pointer */
#define PTR_c_DeviceProperties_LowPriority(var) (&var)


/*-A----------------------------------*/
typedef struct _c_DeviceProperties {
	ED_LOCATOR LowPriority___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN LowPriority; /* ODY01a *//*GBD01b*/

}	c_DeviceProperties;
#define INIT_c_DeviceProperties(sp) ED_RESET_MEM ((sp), sizeof (c_DeviceProperties))
/*FRK03a*/
void FREE_c_DeviceProperties(c_DeviceProperties* sp);

/* Access member 'text' of type 'c_ASCII' as a variable reference */
#define VAR_c_ASCII_text(var) var

/* Access member 'text' of type 'c_ASCII' as a pointer */
#define PTR_c_ASCII_text(var) (&var)

/* DEFINITION OF BINARY c_ASCII_text */
typedef struct _c_ASCII_text {
	ED_BYTE* value; /* Variable size; bits needed 800 */
	int usedBits;
} c_ASCII_text;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ASCII_text(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ASCII {
	ED_LOCATOR text___LOCATOR  /*LBD02*/;

	c_ASCII_text text; /* Static, variable size; bits needed 800 *//*GBD01b*/

}	c_ASCII;
#define INIT_c_ASCII(sp) ED_RESET_MEM ((sp), sizeof (c_ASCII))
/*FRK03a*/
void FREE_c_ASCII(c_ASCII* sp);

/* Access member 'RadioChannelRequirement' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_RadioChannelRequirement(var) var

/* Access member 'RadioChannelRequirement' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_RadioChannelRequirement(var) (&var)

/* Access member 'CodingStd' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_CodingStd(var) var

/* Access member 'CodingStd' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_CodingStd(var) (&var)

/* Access member 'TransferMode' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_TransferMode(var) var

/* Access member 'TransferMode' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_TransferMode(var) (&var)

/* Access member 'InformationTransferCapability' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_InformationTransferCapability(var) var

/* Access member 'InformationTransferCapability' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_InformationTransferCapability(var) (&var)

/* Access member 'Compress' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Compress(var) var

/* Access member 'Compress' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Compress(var) (&var)

/* Access member 'Structure' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Structure(var) var

/* Access member 'Structure' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Structure(var) (&var)

/* Access member 'DuplMode' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_DuplMode(var) var

/* Access member 'DuplMode' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_DuplMode(var) (&var)

/* Access member 'Configured' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Configured(var) var

/* Access member 'Configured' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Configured(var) (&var)

/* Access member 'NIRR' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_NIRR(var) var

/* Access member 'NIRR' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_NIRR(var) (&var)

/* Access member 'Established' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Established(var) var

/* Access member 'Established' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Established(var) (&var)

/* Access member 'AccessId' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_AccessId(var) var

/* Access member 'AccessId' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_AccessId(var) (&var)

/* Access member 'RateAdaption' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_RateAdaption(var) var

/* Access member 'RateAdaption' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_RateAdaption(var) (&var)

/* Access member 'SignallinAccessProtocol' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_SignallinAccessProtocol(var) var

/* Access member 'SignallinAccessProtocol' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_SignallinAccessProtocol(var) (&var)

/* Access member 'OtherITC' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_OtherITC(var) var

/* Access member 'OtherITC' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_OtherITC(var) (&var)

/* Access member 'OtherRateAdaption' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_OtherRateAdaption(var) var

/* Access member 'OtherRateAdaption' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_OtherRateAdaption(var) (&var)

/* Access member 'spare5a' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_spare5a(var) var

/* Access member 'spare5a' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_spare5a(var) (&var)

/* Access member 'Layer1id' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Layer1id(var) var

/* Access member 'Layer1id' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Layer1id(var) (&var)

/* Access member 'UserInfoLayer1Protocol' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_UserInfoLayer1Protocol(var) var

/* Access member 'UserInfoLayer1Protocol' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_UserInfoLayer1Protocol(var) (&var)

/* Access member 'Asynchronous' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Asynchronous(var) var

/* Access member 'Asynchronous' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Asynchronous(var) (&var)

/* Access member 'NumbStopBits' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_NumbStopBits(var) var

/* Access member 'NumbStopBits' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_NumbStopBits(var) (&var)

/* Access member 'Negotiations' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Negotiations(var) var

/* Access member 'Negotiations' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Negotiations(var) (&var)

/* Access member 'NumbDataBits' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_NumbDataBits(var) var

/* Access member 'NumbDataBits' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_NumbDataBits(var) (&var)

/* Access member 'UserRate' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_UserRate(var) var

/* Access member 'UserRate' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_UserRate(var) (&var)

/* Access member 'IntermedRate' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_IntermedRate(var) var

/* Access member 'IntermedRate' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_IntermedRate(var) (&var)

/* Access member 'NIConTX' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_NIConTX(var) var

/* Access member 'NIConTX' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_NIConTX(var) (&var)

/* Access member 'NIConRX' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_NIConRX(var) var

/* Access member 'NIConRX' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_NIConRX(var) (&var)

/* Access member 'Parity' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Parity(var) var

/* Access member 'Parity' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Parity(var) (&var)

/* Access member 'ConnectionElement' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_ConnectionElement(var) var

/* Access member 'ConnectionElement' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_ConnectionElement(var) (&var)

/* Access member 'ModemType' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_ModemType(var) var

/* Access member 'ModemType' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_ModemType(var) (&var)

/* Access member 'OtherModemType' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_OtherModemType(var) var

/* Access member 'OtherModemType' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_OtherModemType(var) (&var)

/* Access member 'FixedNetworkUserRate' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_FixedNetworkUserRate(var) var

/* Access member 'FixedNetworkUserRate' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_FixedNetworkUserRate(var) (&var)

/* Access member 'AcceptableChannelCodings' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_AcceptableChannelCodings(var) var

/* Access member 'AcceptableChannelCodings' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_AcceptableChannelCodings(var) (&var)

/* Access member 'MaxNumOfTrafficChannels' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_MaxNumOfTrafficChannels(var) var

/* Access member 'MaxNumOfTrafficChannels' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_MaxNumOfTrafficChannels(var) (&var)

/* Access member 'UIMI' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_UIMI(var) var

/* Access member 'UIMI' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_UIMI(var) (&var)

/* Access member 'WantedAirInterfUserRate' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_WantedAirInterfUserRate(var) var

/* Access member 'WantedAirInterfUserRate' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_WantedAirInterfUserRate(var) (&var)

/* Access member 'AcceptableChCodingsExt' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_AcceptableChCodingsExt(var) var

/* Access member 'AcceptableChCodingsExt' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_AcceptableChCodingsExt(var) (&var)

/* Access member 'AsymmetryInd' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_AsymmetryInd(var) var

/* Access member 'AsymmetryInd' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_AsymmetryInd(var) (&var)

/* Access member 'spare6g' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_spare6g(var) var

/* Access member 'spare6g' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_spare6g(var) (&var)

/* Access member 'Layer2id' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_Layer2id(var) var

/* Access member 'Layer2id' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_Layer2id(var) (&var)

/* Access member 'USerInfoLayer2Protocol' of type 'c_BackupBearerCapability' as a variable reference */
#define VAR_c_BackupBearerCapability_USerInfoLayer2Protocol(var) var

/* Access member 'USerInfoLayer2Protocol' of type 'c_BackupBearerCapability' as a pointer */
#define PTR_c_BackupBearerCapability_USerInfoLayer2Protocol(var) (&var)


/*-A----------------------------------*/
typedef struct _c_BackupBearerCapability {
	ED_LOCATOR RadioChannelRequirement___LOCATOR; /* QUI2 */
	ED_LOCATOR CodingStd___LOCATOR; /* QUI2 */
	ED_LOCATOR TransferMode___LOCATOR; /* QUI2 */
	ED_LOCATOR InformationTransferCapability___LOCATOR; /* QUI2 */
	ED_LOCATOR Compress___LOCATOR; /* QUI2 */
	ED_LOCATOR Structure___LOCATOR; /* QUI2 */
	ED_LOCATOR DuplMode___LOCATOR; /* QUI2 */
	ED_LOCATOR Configured___LOCATOR; /* QUI2 */
	ED_LOCATOR NIRR___LOCATOR; /* QUI2 */
	ED_LOCATOR Established___LOCATOR; /* QUI2 */
	ED_LOCATOR RateAdaption___LOCATOR; /* QUI2 */
	ED_LOCATOR SignallinAccessProtocol___LOCATOR; /* QUI2 */
	ED_LOCATOR OtherITC___LOCATOR; /* QUI2 */
	ED_LOCATOR OtherRateAdaption___LOCATOR; /* QUI2 */
	ED_LOCATOR UserInfoLayer1Protocol___LOCATOR; /* QUI2 */
	ED_LOCATOR Asynchronous___LOCATOR; /* QUI2 */
	ED_LOCATOR NumbStopBits___LOCATOR; /* QUI2 */
	ED_LOCATOR Negotiations___LOCATOR; /* QUI2 */
	ED_LOCATOR NumbDataBits___LOCATOR; /* QUI2 */
	ED_LOCATOR UserRate___LOCATOR; /* QUI2 */
	ED_LOCATOR IntermedRate___LOCATOR; /* QUI2 */
	ED_LOCATOR NIConTX___LOCATOR; /* QUI2 */
	ED_LOCATOR NIConRX___LOCATOR; /* QUI2 */
	ED_LOCATOR Parity___LOCATOR; /* QUI2 */
	ED_LOCATOR ConnectionElement___LOCATOR; /* QUI2 */
	ED_LOCATOR ModemType___LOCATOR; /* QUI2 */
	ED_LOCATOR OtherModemType___LOCATOR; /* QUI2 */
	ED_LOCATOR FixedNetworkUserRate___LOCATOR; /* QUI2 */
	ED_LOCATOR AcceptableChannelCodings___LOCATOR; /* QUI2 */
	ED_LOCATOR MaxNumOfTrafficChannels___LOCATOR; /* QUI2 */
	ED_LOCATOR UIMI___LOCATOR; /* QUI2 */
	ED_LOCATOR WantedAirInterfUserRate___LOCATOR; /* QUI2 */
	ED_LOCATOR AcceptableChCodingsExt___LOCATOR; /* QUI2 */
	ED_LOCATOR AsymmetryInd___LOCATOR; /* QUI2 */
	ED_LOCATOR USerInfoLayer2Protocol___LOCATOR; /* QUI2 */

	ED_OCTET RadioChannelRequirement; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CodingStd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TransferMode; /* ODY01a *//*GBD01b*/
	ED_OCTET InformationTransferCapability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Compress; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Compress_Present;
	ED_OCTET Structure; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DuplMode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Configured; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NIRR; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Established; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN AccessId_Present;
	ED_OCTET RateAdaption; /* ODY01a *//*GBD01b*/
	ED_OCTET SignallinAccessProtocol; /* ODY01a *//*GBD01b*/
	ED_OCTET OtherITC; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OtherITC_Present;
	ED_OCTET OtherRateAdaption; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN Layer1id_Present;
	ED_OCTET UserInfoLayer1Protocol; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Asynchronous; /* ODY01a *//*GBD01b*/
	ED_OCTET NumbStopBits; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NumbStopBits_Present;
	ED_BOOLEAN Negotiations; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NumbDataBits; /* ODY01a *//*GBD01b*/
	ED_OCTET UserRate; /* ODY01a *//*GBD01b*/
	ED_OCTET IntermedRate; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IntermedRate_Present;
	ED_BOOLEAN NIConTX; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NIConRX; /* ODY01a *//*GBD01b*/
	ED_OCTET Parity; /* ODY01a *//*GBD01b*/
	ED_OCTET ConnectionElement; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ConnectionElement_Present;
	ED_OCTET ModemType; /* ODY01a *//*GBD01b*/
	ED_OCTET OtherModemType; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN OtherModemType_Present;
	ED_OCTET FixedNetworkUserRate; /* ODY01a *//*GBD01b*/
	ED_OCTET AcceptableChannelCodings; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AcceptableChannelCodings_Present;
	ED_OCTET MaxNumOfTrafficChannels; /* ODY01a *//*GBD01b*/
	ED_OCTET UIMI; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIMI_Present;
	ED_OCTET WantedAirInterfUserRate; /* ODY01a *//*GBD01b*/
	ED_OCTET AcceptableChCodingsExt; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AcceptableChCodingsExt_Present;
	ED_OCTET AsymmetryInd; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN Layer2id_Present;
	ED_OCTET USerInfoLayer2Protocol; /* ODY01a *//*GBD01b*/

}	c_BackupBearerCapability;
#define INIT_c_BackupBearerCapability(sp) ED_RESET_MEM ((sp), sizeof (c_BackupBearerCapability))
/*FRK03a*/
void FREE_c_BackupBearerCapability(c_BackupBearerCapability* sp);
#define SETPRESENT_c_BackupBearerCapability_Compress(sp,present) (((sp)->Compress_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_Compress(sp) ((sp)->Compress_Present)
#define SETPRESENT_c_BackupBearerCapability_AccessId(sp,present) (((sp)->AccessId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_AccessId(sp) ((sp)->AccessId_Present)
#define SETPRESENT_c_BackupBearerCapability_OtherITC(sp,present) (((sp)->OtherITC_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_OtherITC(sp) ((sp)->OtherITC_Present)
#define SETPRESENT_c_BackupBearerCapability_Layer1id(sp,present) (((sp)->Layer1id_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_Layer1id(sp) ((sp)->Layer1id_Present)
#define SETPRESENT_c_BackupBearerCapability_NumbStopBits(sp,present) (((sp)->NumbStopBits_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_NumbStopBits(sp) ((sp)->NumbStopBits_Present)
#define SETPRESENT_c_BackupBearerCapability_IntermedRate(sp,present) (((sp)->IntermedRate_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_IntermedRate(sp) ((sp)->IntermedRate_Present)
#define SETPRESENT_c_BackupBearerCapability_ConnectionElement(sp,present) (((sp)->ConnectionElement_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_ConnectionElement(sp) ((sp)->ConnectionElement_Present)
#define SETPRESENT_c_BackupBearerCapability_OtherModemType(sp,present) (((sp)->OtherModemType_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_OtherModemType(sp) ((sp)->OtherModemType_Present)
#define SETPRESENT_c_BackupBearerCapability_AcceptableChannelCodings(sp,present) (((sp)->AcceptableChannelCodings_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_AcceptableChannelCodings(sp) ((sp)->AcceptableChannelCodings_Present)
#define SETPRESENT_c_BackupBearerCapability_UIMI(sp,present) (((sp)->UIMI_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_UIMI(sp) ((sp)->UIMI_Present)
#define SETPRESENT_c_BackupBearerCapability_AcceptableChCodingsExt(sp,present) (((sp)->AcceptableChCodingsExt_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_AcceptableChCodingsExt(sp) ((sp)->AcceptableChCodingsExt_Present)
#define SETPRESENT_c_BackupBearerCapability_Layer2id(sp,present) (((sp)->Layer2id_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BackupBearerCapability_Layer2id(sp) ((sp)->Layer2id_Present)

/* Access member 'TypeOfNumber' of type 'c_CallingPartyBcdNum' as a variable reference */
#define VAR_c_CallingPartyBcdNum_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_CallingPartyBcdNum' as a pointer */
#define PTR_c_CallingPartyBcdNum_TypeOfNumber(var) (&var)

/* Access member 'NumberingPlanIdent' of type 'c_CallingPartyBcdNum' as a variable reference */
#define VAR_c_CallingPartyBcdNum_NumberingPlanIdent(var) var

/* Access member 'NumberingPlanIdent' of type 'c_CallingPartyBcdNum' as a pointer */
#define PTR_c_CallingPartyBcdNum_NumberingPlanIdent(var) (&var)

/* Access member 'PresentationIndicator' of type 'c_CallingPartyBcdNum' as a variable reference */
#define VAR_c_CallingPartyBcdNum_PresentationIndicator(var) var

/* Access member 'PresentationIndicator' of type 'c_CallingPartyBcdNum' as a pointer */
#define PTR_c_CallingPartyBcdNum_PresentationIndicator(var) (&var)

/* Access member 'spare' of type 'c_CallingPartyBcdNum' as a variable reference */
#define VAR_c_CallingPartyBcdNum_spare(var) var

/* Access member 'spare' of type 'c_CallingPartyBcdNum' as a pointer */
#define PTR_c_CallingPartyBcdNum_spare(var) (&var)

/* Access member 'ScreeningIndicator' of type 'c_CallingPartyBcdNum' as a variable reference */
#define VAR_c_CallingPartyBcdNum_ScreeningIndicator(var) var

/* Access member 'ScreeningIndicator' of type 'c_CallingPartyBcdNum' as a pointer */
#define PTR_c_CallingPartyBcdNum_ScreeningIndicator(var) (&var)

/* Access member 'Number' of type 'c_CallingPartyBcdNum' as a variable reference */
#define VAR_c_CallingPartyBcdNum_Number(var) var

/* Access member 'Number' of type 'c_CallingPartyBcdNum' as a pointer */
#define PTR_c_CallingPartyBcdNum_Number(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CallingPartyBcdNum {
	ED_LOCATOR TypeOfNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR NumberingPlanIdent___LOCATOR; /* QUI2 */
	ED_LOCATOR PresentationIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR ScreeningIndicator___LOCATOR; /* QUI2 */

	ED_OCTET TypeOfNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET NumberingPlanIdent; /* ODY01a *//*GBD01b*/
	ED_OCTET PresentationIndicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PresentationIndicator_Present;
	/*GBD01b*/
	ED_OCTET ScreeningIndicator; /* ODY01a *//*GBD01b*/
	c_TBCDArray Number; /* ODY01a *//*GBD01b*/

}	c_CallingPartyBcdNum;
#define INIT_c_CallingPartyBcdNum(sp) ED_RESET_MEM ((sp), sizeof (c_CallingPartyBcdNum))
/*FRK03a*/
void FREE_c_CallingPartyBcdNum(c_CallingPartyBcdNum* sp);
#define SETPRESENT_c_CallingPartyBcdNum_PresentationIndicator(sp,present) (((sp)->PresentationIndicator_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CallingPartyBcdNum_PresentationIndicator(sp) ((sp)->PresentationIndicator_Present)

/* Access member 'CodingStandard' of type 'c_Cause' as a variable reference */
#define VAR_c_Cause_CodingStandard(var) var

/* Access member 'CodingStandard' of type 'c_Cause' as a pointer */
#define PTR_c_Cause_CodingStandard(var) (&var)

/* Access member 'spare' of type 'c_Cause' as a variable reference */
#define VAR_c_Cause_spare(var) var

/* Access member 'spare' of type 'c_Cause' as a pointer */
#define PTR_c_Cause_spare(var) (&var)

/* Access member 'Location' of type 'c_Cause' as a variable reference */
#define VAR_c_Cause_Location(var) var

/* Access member 'Location' of type 'c_Cause' as a pointer */
#define PTR_c_Cause_Location(var) (&var)

/* Access member 'Recommendation' of type 'c_Cause' as a variable reference */
#define VAR_c_Cause_Recommendation(var) var

/* Access member 'Recommendation' of type 'c_Cause' as a pointer */
#define PTR_c_Cause_Recommendation(var) (&var)

/* Access member 'CauseValue' of type 'c_Cause' as a variable reference */
#define VAR_c_Cause_CauseValue(var) var

/* Access member 'CauseValue' of type 'c_Cause' as a pointer */
#define PTR_c_Cause_CauseValue(var) (&var)

/* Access member 'diagnostic' of type 'c_Cause' as a variable reference */
#define VAR_c_Cause_diagnostic(var) var

/* Access member 'diagnostic' of type 'c_Cause' as a pointer */
#define PTR_c_Cause_diagnostic(var) (&var)

/* DEFINITION OF BINARY c_Cause_diagnostic */
typedef struct _c_Cause_diagnostic {
	ED_BYTE* value; /* Variable size; bits needed 239 */
	int usedBits;
} c_Cause_diagnostic;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_Cause_diagnostic(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_Cause {
	ED_LOCATOR CodingStandard___LOCATOR; /* QUI2 */
	ED_LOCATOR Location___LOCATOR; /* QUI2 */
	ED_LOCATOR Recommendation___LOCATOR; /* QUI2 */
	ED_LOCATOR CauseValue___LOCATOR; /* QUI2 */
	ED_LOCATOR diagnostic___LOCATOR  /*LBD02*/;

	ED_OCTET CodingStandard; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET Location; /* ODY01a *//*GBD01b*/
	ED_OCTET Recommendation; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Recommendation_Present;
	ED_OCTET CauseValue; /* ODY01a *//*GBD01b*/
	c_Cause_diagnostic diagnostic; /* Static, variable size; bits needed 239 *//*GBD01b*/

}	c_Cause;
#define INIT_c_Cause(sp) ED_RESET_MEM ((sp), sizeof (c_Cause))
/*FRK03a*/
void FREE_c_Cause(c_Cause* sp);
#define SETPRESENT_c_Cause_Recommendation(sp,present) (((sp)->Recommendation_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Cause_Recommendation(sp) ((sp)->Recommendation_Present)

/* Access member 'TypeOfNumber' of type 'c_ConnNum' as a variable reference */
#define VAR_c_ConnNum_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_ConnNum' as a pointer */
#define PTR_c_ConnNum_TypeOfNumber(var) (&var)

/* Access member 'NumberingPlanIdent' of type 'c_ConnNum' as a variable reference */
#define VAR_c_ConnNum_NumberingPlanIdent(var) var

/* Access member 'NumberingPlanIdent' of type 'c_ConnNum' as a pointer */
#define PTR_c_ConnNum_NumberingPlanIdent(var) (&var)

/* Access member 'PresentationIndicator' of type 'c_ConnNum' as a variable reference */
#define VAR_c_ConnNum_PresentationIndicator(var) var

/* Access member 'PresentationIndicator' of type 'c_ConnNum' as a pointer */
#define PTR_c_ConnNum_PresentationIndicator(var) (&var)

/* Access member 'spare' of type 'c_ConnNum' as a variable reference */
#define VAR_c_ConnNum_spare(var) var

/* Access member 'spare' of type 'c_ConnNum' as a pointer */
#define PTR_c_ConnNum_spare(var) (&var)

/* Access member 'ScreeningIndicator' of type 'c_ConnNum' as a variable reference */
#define VAR_c_ConnNum_ScreeningIndicator(var) var

/* Access member 'ScreeningIndicator' of type 'c_ConnNum' as a pointer */
#define PTR_c_ConnNum_ScreeningIndicator(var) (&var)

/* Access member 'Number' of type 'c_ConnNum' as a variable reference */
#define VAR_c_ConnNum_Number(var) var

/* Access member 'Number' of type 'c_ConnNum' as a pointer */
#define PTR_c_ConnNum_Number(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ConnNum {
	ED_LOCATOR TypeOfNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR NumberingPlanIdent___LOCATOR; /* QUI2 */
	ED_LOCATOR PresentationIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR ScreeningIndicator___LOCATOR; /* QUI2 */

	ED_OCTET TypeOfNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET NumberingPlanIdent; /* ODY01a *//*GBD01b*/
	ED_OCTET PresentationIndicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PresentationIndicator_Present;
	/*GBD01b*/
	ED_OCTET ScreeningIndicator; /* ODY01a *//*GBD01b*/
	c_TBCDArray Number; /* ODY01a *//*GBD01b*/

}	c_ConnNum;
#define INIT_c_ConnNum(sp) ED_RESET_MEM ((sp), sizeof (c_ConnNum))
/*FRK03a*/
void FREE_c_ConnNum(c_ConnNum* sp);
#define SETPRESENT_c_ConnNum_PresentationIndicator(sp,present) (((sp)->PresentationIndicator_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ConnNum_PresentationIndicator(sp) ((sp)->PresentationIndicator_Present)

/* Access member 'TypeOfNumber' of type 'c_RedirPartyBcdNum' as a variable reference */
#define VAR_c_RedirPartyBcdNum_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_RedirPartyBcdNum' as a pointer */
#define PTR_c_RedirPartyBcdNum_TypeOfNumber(var) (&var)

/* Access member 'NumberingPlanIdent' of type 'c_RedirPartyBcdNum' as a variable reference */
#define VAR_c_RedirPartyBcdNum_NumberingPlanIdent(var) var

/* Access member 'NumberingPlanIdent' of type 'c_RedirPartyBcdNum' as a pointer */
#define PTR_c_RedirPartyBcdNum_NumberingPlanIdent(var) (&var)

/* Access member 'PresentationIndicator' of type 'c_RedirPartyBcdNum' as a variable reference */
#define VAR_c_RedirPartyBcdNum_PresentationIndicator(var) var

/* Access member 'PresentationIndicator' of type 'c_RedirPartyBcdNum' as a pointer */
#define PTR_c_RedirPartyBcdNum_PresentationIndicator(var) (&var)

/* Access member 'spare' of type 'c_RedirPartyBcdNum' as a variable reference */
#define VAR_c_RedirPartyBcdNum_spare(var) var

/* Access member 'spare' of type 'c_RedirPartyBcdNum' as a pointer */
#define PTR_c_RedirPartyBcdNum_spare(var) (&var)

/* Access member 'ScreeningIndicator' of type 'c_RedirPartyBcdNum' as a variable reference */
#define VAR_c_RedirPartyBcdNum_ScreeningIndicator(var) var

/* Access member 'ScreeningIndicator' of type 'c_RedirPartyBcdNum' as a pointer */
#define PTR_c_RedirPartyBcdNum_ScreeningIndicator(var) (&var)

/* Access member 'Number' of type 'c_RedirPartyBcdNum' as a variable reference */
#define VAR_c_RedirPartyBcdNum_Number(var) var

/* Access member 'Number' of type 'c_RedirPartyBcdNum' as a pointer */
#define PTR_c_RedirPartyBcdNum_Number(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RedirPartyBcdNum {
	ED_LOCATOR TypeOfNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR NumberingPlanIdent___LOCATOR; /* QUI2 */
	ED_LOCATOR PresentationIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR ScreeningIndicator___LOCATOR; /* QUI2 */

	ED_OCTET TypeOfNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET NumberingPlanIdent; /* ODY01a *//*GBD01b*/
	ED_OCTET PresentationIndicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PresentationIndicator_Present;
	/*GBD01b*/
	ED_OCTET ScreeningIndicator; /* ODY01a *//*GBD01b*/
	c_TBCDArray Number; /* ODY01a *//*GBD01b*/

}	c_RedirPartyBcdNum;
#define INIT_c_RedirPartyBcdNum(sp) ED_RESET_MEM ((sp), sizeof (c_RedirPartyBcdNum))
/*FRK03a*/
void FREE_c_RedirPartyBcdNum(c_RedirPartyBcdNum* sp);
#define SETPRESENT_c_RedirPartyBcdNum_PresentationIndicator(sp,present) (((sp)->PresentationIndicator_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_RedirPartyBcdNum_PresentationIndicator(sp) ((sp)->PresentationIndicator_Present)

/* Access member 'data' of type 'c_PlmnList' as a variable reference */
#define VAR_c_PlmnList_data(var) (*var)

/* Access member 'data' of type 'c_PlmnList' as a pointer */
#define PTR_c_PlmnList_data(var) var


/*-A----------------------------------*/
typedef struct _c_PlmnList {

		c_Plmn **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_PlmnList;
#define INIT_c_PlmnList(sp) ED_RESET_MEM ((sp), sizeof (c_PlmnList))
/*FRK02b*/
void FREE_c_PlmnList (c_PlmnList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_PlmnList'. */
int SETITEMS_c_PlmnList (c_PlmnList* sequence, int desiredItems);
#define ADDITEMS_c_PlmnList(sequence, itemsToBeAdded) SETITEMS_c_PlmnList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'data' of type 'c_EmergencyNumberList' as a variable reference */
#define VAR_c_EmergencyNumberList_data(var) (*var)

/* Access member 'data' of type 'c_EmergencyNumberList' as a pointer */
#define PTR_c_EmergencyNumberList_data(var) var


/*-A----------------------------------*/
typedef struct _c_EmergencyNumberList {

		c_TBCDEmergencyNumber **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_EmergencyNumberList;
#define INIT_c_EmergencyNumberList(sp) ED_RESET_MEM ((sp), sizeof (c_EmergencyNumberList))
/*FRK02b*/
void FREE_c_EmergencyNumberList (c_EmergencyNumberList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_EmergencyNumberList'. */
int SETITEMS_c_EmergencyNumberList (c_EmergencyNumberList* sequence, int desiredItems);
#define ADDITEMS_c_EmergencyNumberList(sequence, itemsToBeAdded) SETITEMS_c_EmergencyNumberList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'Multiband_supported' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Multiband_supported(var) var

/* Access member 'Multiband_supported' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Multiband_supported(var) (&var)

/* Access member 'A5_7' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_A5_7(var) var

/* Access member 'A5_7' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_A5_7(var) (&var)

/* Access member 'A5_6' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_A5_6(var) var

/* Access member 'A5_6' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_A5_6(var) (&var)

/* Access member 'A5_5' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_A5_5(var) var

/* Access member 'A5_5' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_A5_5(var) (&var)

/* Access member 'A5_4' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_A5_4(var) var

/* Access member 'A5_4' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_A5_4(var) (&var)

/* Access member 'Associated_Radio_Capability_2' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Associated_Radio_Capability_2(var) var

/* Access member 'Associated_Radio_Capability_2' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Associated_Radio_Capability_2(var) (&var)

/* Access member 'Associated_Radio_Capability_1' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Associated_Radio_Capability_1(var) var

/* Access member 'Associated_Radio_Capability_1' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Associated_Radio_Capability_1(var) (&var)

/* Access member 'R_GSM_band_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_R_GSM_band_Associated_Radio_Capability(var) var

/* Access member 'R_GSM_band_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_R_GSM_band_Associated_Radio_Capability(var) (&var)

/* Access member 'HSCSD_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_HSCSD_Multi_Slot_Class(var) var

/* Access member 'HSCSD_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_HSCSD_Multi_Slot_Class(var) (&var)

/* Access member 'UCS2_treatment' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_UCS2_treatment(var) var

/* Access member 'UCS2_treatment' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_UCS2_treatment(var) (&var)

/* Access member 'Extended_Measurement_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Extended_Measurement_Capability(var) var

/* Access member 'Extended_Measurement_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Extended_Measurement_Capability(var) (&var)

/* Access member 'SMS_VALUE' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_SMS_VALUE(var) var

/* Access member 'SMS_VALUE' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_SMS_VALUE(var) (&var)

/* Access member 'SM_VALUE' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_SM_VALUE(var) var

/* Access member 'SM_VALUE' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_SM_VALUE(var) (&var)

/* Access member 'MS_Positioning_Method' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_MS_Positioning_Method(var) var

/* Access member 'MS_Positioning_Method' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_MS_Positioning_Method(var) (&var)

/* Access member 'ECSD_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_ECSD_Multi_Slot_Class(var) var

/* Access member 'ECSD_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_ECSD_Multi_Slot_Class(var) (&var)

/* Access member 'Modulation_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Modulation_Capability(var) var

/* Access member 'Modulation_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Modulation_Capability(var) (&var)

/* Access member '_8_PSK_RF_Power_Capability_1' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value__8_PSK_RF_Power_Capability_1(var) var

/* Access member '_8_PSK_RF_Power_Capability_1' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value__8_PSK_RF_Power_Capability_1(var) (&var)

/* Access member '_8_PSK_RF_Power_Capability_2' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value__8_PSK_RF_Power_Capability_2(var) var

/* Access member '_8_PSK_RF_Power_Capability_2' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value__8_PSK_RF_Power_Capability_2(var) (&var)

/* Access member 'GSM_400_Bands_Supported' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GSM_400_Bands_Supported(var) var

/* Access member 'GSM_400_Bands_Supported' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GSM_400_Bands_Supported(var) (&var)

/* Access member 'GSM_400_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GSM_400_Associated_Radio_Capability(var) var

/* Access member 'GSM_400_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GSM_400_Associated_Radio_Capability(var) (&var)

/* Access member 'GSM_850_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GSM_850_Associated_Radio_Capability(var) var

/* Access member 'GSM_850_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GSM_850_Associated_Radio_Capability(var) (&var)

/* Access member 'GSM_1900_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GSM_1900_Associated_Radio_Capability(var) var

/* Access member 'GSM_1900_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GSM_1900_Associated_Radio_Capability(var) (&var)

/* Access member 'UMTS_FDD_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_UMTS_FDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_FDD_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_UMTS_FDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'CDMA_2000_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_CDMA_2000_Radio_Access_Technology_Capability(var) var

/* Access member 'CDMA_2000_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_CDMA_2000_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'DTM_GPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_DTM_GPRS_Multi_Slot_Class(var) var

/* Access member 'DTM_GPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_DTM_GPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Single_Slot_DTM' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Single_Slot_DTM(var) var

/* Access member 'Single_Slot_DTM' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Single_Slot_DTM(var) (&var)

/* Access member 'DTM_EGPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_DTM_EGPRS_Multi_Slot_Class(var) var

/* Access member 'DTM_EGPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_DTM_EGPRS_Multi_Slot_Class(var) (&var)

/* Access member 'GSM_Band' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GSM_Band(var) var

/* Access member 'GSM_Band' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GSM_Band(var) (&var)

/* Access member 'GSM_750_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GSM_750_Associated_Radio_Capability(var) var

/* Access member 'GSM_750_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GSM_750_Associated_Radio_Capability(var) (&var)

/* Access member 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'GERAN_Feature_Package_1' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GERAN_Feature_Package_1(var) var

/* Access member 'GERAN_Feature_Package_1' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GERAN_Feature_Package_1(var) (&var)

/* Access member 'Extended_DTM_GPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(var) var

/* Access member 'Extended_DTM_GPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Extended_DTM_EGPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(var) var

/* Access member 'Extended_DTM_EGPRS_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(var) (&var)

/* Access member 'High_Multislot_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_High_Multislot_Capability(var) var

/* Access member 'High_Multislot_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_High_Multislot_Capability(var) (&var)

/* Access member 'Length' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Length(var) var

/* Access member 'Length' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Length(var) (&var)

/* Access member 'FLO_Iu_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_FLO_Iu_Capability(var) var

/* Access member 'FLO_Iu_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_FLO_Iu_Capability(var) (&var)

/* Access member 'GERAN_Feature_Package_2' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GERAN_Feature_Package_2(var) var

/* Access member 'GERAN_Feature_Package_2' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GERAN_Feature_Package_2(var) (&var)

/* Access member 'GMSK_Multislot_Power_Profile' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GMSK_Multislot_Power_Profile(var) var

/* Access member 'GMSK_Multislot_Power_Profile' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GMSK_Multislot_Power_Profile(var) (&var)

/* Access member '_8_PSK_Multislot_Power_Profile' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value__8_PSK_Multislot_Power_Profile(var) var

/* Access member '_8_PSK_Multislot_Power_Profile' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value__8_PSK_Multislot_Power_Profile(var) (&var)

/* Access member 'T_GSM_400_Bands_Supported' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_T_GSM_400_Bands_Supported(var) var

/* Access member 'T_GSM_400_Bands_Supported' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_T_GSM_400_Bands_Supported(var) (&var)

/* Access member 'T_GSM_400_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_T_GSM_400_Associated_Radio_Capability(var) var

/* Access member 'T_GSM_400_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_T_GSM_400_Associated_Radio_Capability(var) (&var)

/* Access member 'T_GSM_900_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_T_GSM_900_Associated_Radio_Capability(var) var

/* Access member 'T_GSM_900_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_T_GSM_900_Associated_Radio_Capability(var) (&var)

/* Access member 'Downlink_Advanced_Receiver_Performance' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Downlink_Advanced_Receiver_Performance(var) var

/* Access member 'Downlink_Advanced_Receiver_Performance' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Downlink_Advanced_Receiver_Performance(var) (&var)

/* Access member 'DTM_Enhancements_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_DTM_Enhancements_Capability(var) var

/* Access member 'DTM_Enhancements_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_DTM_Enhancements_Capability(var) (&var)

/* Access member 'DTM_GPRS_High_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class(var) var

/* Access member 'DTM_GPRS_High_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class(var) (&var)

/* Access member 'Offset_required' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Offset_required(var) var

/* Access member 'Offset_required' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Offset_required(var) (&var)

/* Access member 'DTM_EGPRS_High_Multi_Slot_Class' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class(var) var

/* Access member 'DTM_EGPRS_High_Multi_Slot_Class' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class(var) (&var)

/* Access member 'Repeated_ACCH_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Repeated_ACCH_Capability(var) var

/* Access member 'Repeated_ACCH_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Repeated_ACCH_Capability(var) (&var)

/* Access member 'GSM_710_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GSM_710_Associated_Radio_Capability(var) var

/* Access member 'GSM_710_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GSM_710_Associated_Radio_Capability(var) (&var)

/* Access member 'T_GSM_810_Associated_Radio_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_T_GSM_810_Associated_Radio_Capability(var) var

/* Access member 'T_GSM_810_Associated_Radio_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_T_GSM_810_Associated_Radio_Capability(var) (&var)

/* Access member 'Ciphering_Mode_Setting_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Ciphering_Mode_Setting_Capability(var) var

/* Access member 'Ciphering_Mode_Setting_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Ciphering_Mode_Setting_Capability(var) (&var)

/* Access member 'Additional_Positioning_Capabilities' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Additional_Positioning_Capabilities(var) var

/* Access member 'Additional_Positioning_Capabilities' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Additional_Positioning_Capabilities(var) (&var)

/* Access member 'E_UTRA_FDD_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_E_UTRA_FDD_support(var) var

/* Access member 'E_UTRA_FDD_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_E_UTRA_FDD_support(var) (&var)

/* Access member 'E_UTRA_TDD_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_E_UTRA_TDD_support(var) var

/* Access member 'E_UTRA_TDD_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_E_UTRA_TDD_support(var) (&var)

/* Access member 'E_UTRA_Measurement_and_Reporting_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_E_UTRA_Measurement_and_Reporting_support(var) var

/* Access member 'E_UTRA_Measurement_and_Reporting_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_E_UTRA_Measurement_and_Reporting_support(var) (&var)

/* Access member 'Priority_based_reselection_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Priority_based_reselection_support(var) var

/* Access member 'Priority_based_reselection_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Priority_based_reselection_support(var) (&var)

/* Access member 'UTRA_CSG_Cells_Reporting' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_UTRA_CSG_Cells_Reporting(var) var

/* Access member 'UTRA_CSG_Cells_Reporting' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_UTRA_CSG_Cells_Reporting(var) (&var)

/* Access member 'VAMOS_Level' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_VAMOS_Level(var) var

/* Access member 'VAMOS_Level' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_VAMOS_Level(var) (&var)

/* Access member 'TIGHTER_Capability' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_TIGHTER_Capability(var) var

/* Access member 'TIGHTER_Capability' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_TIGHTER_Capability(var) (&var)

/* Access member 'Selective_Ciphering_of_Downlink_SACCH' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH(var) var

/* Access member 'Selective_Ciphering_of_Downlink_SACCH' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH(var) (&var)

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(var) var

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(var) (&var)

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(var) var

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(var) (&var)

/* Access member 'GERAN_Network_Sharing_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_GERAN_Network_Sharing_support(var) var

/* Access member 'GERAN_Network_Sharing_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_GERAN_Network_Sharing_support(var) (&var)

/* Access member 'E_UTRA_Wideband_RSRQ_measurements_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(var) var

/* Access member 'E_UTRA_Wideband_RSRQ_measurements_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(var) (&var)

/* Access member 'ER_Band_Support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_ER_Band_Support(var) var

/* Access member 'ER_Band_Support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_ER_Band_Support(var) (&var)

/* Access member 'UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(var) var

/* Access member 'UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(var) (&var)

/* Access member 'E_UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(var) var

/* Access member 'E_UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(var) (&var)

/* Access member 'Extended_TSC_Set_Capability_support' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Extended_TSC_Set_Capability_support(var) var

/* Access member 'Extended_TSC_Set_Capability_support' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Extended_TSC_Set_Capability_support(var) (&var)

/* Access member 'Extended_EARFCN_value_range' of type 'c_Classmark3Value' as a variable reference */
#define VAR_c_Classmark3Value_Extended_EARFCN_value_range(var) var

/* Access member 'Extended_EARFCN_value_range' of type 'c_Classmark3Value' as a pointer */
#define PTR_c_Classmark3Value_Extended_EARFCN_value_range(var) (&var)


/*-A----------------------------------*/
typedef struct _c_Classmark3Value {
	ED_LOCATOR Multiband_supported___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_7___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_6___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_5___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_4___LOCATOR; /* QUI2 */
	ED_LOCATOR Associated_Radio_Capability_2___LOCATOR; /* QUI2 */
	ED_LOCATOR Associated_Radio_Capability_1___LOCATOR; /* QUI2 */
	ED_LOCATOR R_GSM_band_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR HSCSD_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR UCS2_treatment___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_Measurement_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR SMS_VALUE___LOCATOR; /* QUI2 */
	ED_LOCATOR SM_VALUE___LOCATOR; /* QUI2 */
	ED_LOCATOR MS_Positioning_Method___LOCATOR; /* QUI2 */
	ED_LOCATOR ECSD_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Modulation_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR _8_PSK_RF_Power_Capability_1___LOCATOR; /* QUI2 */
	ED_LOCATOR _8_PSK_RF_Power_Capability_2___LOCATOR; /* QUI2 */
	ED_LOCATOR GSM_400_Bands_Supported___LOCATOR; /* QUI2 */
	ED_LOCATOR GSM_400_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GSM_850_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GSM_1900_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR UMTS_FDD_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR CDMA_2000_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_GPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Single_Slot_DTM___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_EGPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR GSM_Band___LOCATOR; /* QUI2 */
	ED_LOCATOR GSM_750_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GERAN_Feature_Package_1___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_DTM_GPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_DTM_EGPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR High_Multislot_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */
	ED_LOCATOR FLO_Iu_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GERAN_Feature_Package_2___LOCATOR; /* QUI2 */
	ED_LOCATOR GMSK_Multislot_Power_Profile___LOCATOR; /* QUI2 */
	ED_LOCATOR _8_PSK_Multislot_Power_Profile___LOCATOR; /* QUI2 */
	ED_LOCATOR T_GSM_400_Bands_Supported___LOCATOR; /* QUI2 */
	ED_LOCATOR T_GSM_400_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR T_GSM_900_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Downlink_Advanced_Receiver_Performance___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_Enhancements_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_GPRS_High_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Offset_required___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_EGPRS_High_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Repeated_ACCH_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GSM_710_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR T_GSM_810_Associated_Radio_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Ciphering_Mode_Setting_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Additional_Positioning_Capabilities___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_FDD_support___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_TDD_support___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_Measurement_and_Reporting_support___LOCATOR; /* QUI2 */
	ED_LOCATOR Priority_based_reselection_support___LOCATOR; /* QUI2 */
	ED_LOCATOR UTRA_CSG_Cells_Reporting___LOCATOR; /* QUI2 */
	ED_LOCATOR VAMOS_Level___LOCATOR; /* QUI2 */
	ED_LOCATOR TIGHTER_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Selective_Ciphering_of_Downlink_SACCH___LOCATOR; /* QUI2 */
	ED_LOCATOR CS_to_PS_SRVCC_from_GERAN_to_UTRA___LOCATOR; /* QUI2 */
	ED_LOCATOR CS_to_PS_SRVCC_from_GERAN_to_E_UTRA___LOCATOR; /* QUI2 */
	ED_LOCATOR GERAN_Network_Sharing_support___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_Wideband_RSRQ_measurements_support___LOCATOR; /* QUI2 */
	ED_LOCATOR ER_Band_Support___LOCATOR; /* QUI2 */
	ED_LOCATOR UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_TSC_Set_Capability_support___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_EARFCN_value_range___LOCATOR; /* QUI2 */

	ED_OCTET Multiband_supported; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_4; /* ODY01a *//*GBD01b*/
	ED_OCTET Associated_Radio_Capability_2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Associated_Radio_Capability_2_Present;
	ED_OCTET Associated_Radio_Capability_1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Associated_Radio_Capability_1_Present;
	ED_OCTET R_GSM_band_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN R_GSM_band_Associated_Radio_Capability_Present;
	ED_OCTET HSCSD_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HSCSD_Multi_Slot_Class_Present;
	ED_BOOLEAN UCS2_treatment; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_Measurement_Capability; /* ODY01a *//*GBD01b*/
	ED_OCTET SMS_VALUE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SMS_VALUE_Present;
	ED_OCTET SM_VALUE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SM_VALUE_Present;
	ED_OCTET MS_Positioning_Method; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MS_Positioning_Method_Present;
	ED_OCTET ECSD_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ECSD_Multi_Slot_Class_Present;
	ED_BOOLEAN Modulation_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Modulation_Capability_Present;
	ED_OCTET _8_PSK_RF_Power_Capability_1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN _8_PSK_RF_Power_Capability_1_Present;
	ED_OCTET _8_PSK_RF_Power_Capability_2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN _8_PSK_RF_Power_Capability_2_Present;
	ED_OCTET GSM_400_Bands_Supported; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GSM_400_Bands_Supported_Present;
	ED_OCTET GSM_400_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GSM_400_Associated_Radio_Capability_Present;
	ED_OCTET GSM_850_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GSM_850_Associated_Radio_Capability_Present;
	ED_OCTET GSM_1900_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GSM_1900_Associated_Radio_Capability_Present;
	ED_BOOLEAN UMTS_FDD_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CDMA_2000_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_OCTET DTM_GPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_GPRS_Multi_Slot_Class_Present;
	ED_BOOLEAN Single_Slot_DTM; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Single_Slot_DTM_Present;
	ED_OCTET DTM_EGPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_EGPRS_Multi_Slot_Class_Present;
	ED_OCTET GSM_Band; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GSM_Band_Present;
	ED_OCTET GSM_750_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GSM_750_Associated_Radio_Capability_Present;
	ED_BOOLEAN UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present;
	ED_BOOLEAN GERAN_Feature_Package_1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GERAN_Feature_Package_1_Present;
	ED_OCTET Extended_DTM_GPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_DTM_GPRS_Multi_Slot_Class_Present;
	ED_OCTET Extended_DTM_EGPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_DTM_EGPRS_Multi_Slot_Class_Present;
	ED_OCTET High_Multislot_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN High_Multislot_Capability_Present;
	ED_OCTET Length; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Length_Present;
	ED_BOOLEAN FLO_Iu_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN FLO_Iu_Capability_Present;
	ED_BOOLEAN GERAN_Feature_Package_2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GERAN_Feature_Package_2_Present;
	ED_OCTET GMSK_Multislot_Power_Profile; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GMSK_Multislot_Power_Profile_Present;
	ED_OCTET _8_PSK_Multislot_Power_Profile; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN _8_PSK_Multislot_Power_Profile_Present;
	ED_OCTET T_GSM_400_Bands_Supported; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN T_GSM_400_Bands_Supported_Present;
	ED_OCTET T_GSM_400_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN T_GSM_400_Associated_Radio_Capability_Present;
	ED_OCTET T_GSM_900_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN T_GSM_900_Associated_Radio_Capability_Present;
	ED_OCTET Downlink_Advanced_Receiver_Performance; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Downlink_Advanced_Receiver_Performance_Present;
	ED_BOOLEAN DTM_Enhancements_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_Enhancements_Capability_Present;
	ED_OCTET DTM_GPRS_High_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_GPRS_High_Multi_Slot_Class_Present;
	ED_BOOLEAN Offset_required; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Offset_required_Present;
	ED_OCTET DTM_EGPRS_High_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_EGPRS_High_Multi_Slot_Class_Present;
	ED_BOOLEAN Repeated_ACCH_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Repeated_ACCH_Capability_Present;
	ED_OCTET GSM_710_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GSM_710_Associated_Radio_Capability_Present;
	ED_OCTET T_GSM_810_Associated_Radio_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN T_GSM_810_Associated_Radio_Capability_Present;
	ED_BOOLEAN Ciphering_Mode_Setting_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Ciphering_Mode_Setting_Capability_Present;
	ED_BOOLEAN Additional_Positioning_Capabilities; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Additional_Positioning_Capabilities_Present;
	ED_BOOLEAN E_UTRA_FDD_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_FDD_support_Present;
	ED_BOOLEAN E_UTRA_TDD_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_TDD_support_Present;
	ED_BOOLEAN E_UTRA_Measurement_and_Reporting_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_Measurement_and_Reporting_support_Present;
	ED_BOOLEAN Priority_based_reselection_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Priority_based_reselection_support_Present;
	ED_BOOLEAN UTRA_CSG_Cells_Reporting; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UTRA_CSG_Cells_Reporting_Present;
	ED_OCTET VAMOS_Level; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VAMOS_Level_Present;
	ED_OCTET TIGHTER_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TIGHTER_Capability_Present;
	ED_BOOLEAN Selective_Ciphering_of_Downlink_SACCH; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Selective_Ciphering_of_Downlink_SACCH_Present;
	ED_OCTET CS_to_PS_SRVCC_from_GERAN_to_UTRA; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CS_to_PS_SRVCC_from_GERAN_to_UTRA_Present;
	ED_OCTET CS_to_PS_SRVCC_from_GERAN_to_E_UTRA; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_Present;
	ED_BOOLEAN GERAN_Network_Sharing_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GERAN_Network_Sharing_support_Present;
	ED_BOOLEAN E_UTRA_Wideband_RSRQ_measurements_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_Wideband_RSRQ_measurements_support_Present;
	ED_BOOLEAN ER_Band_Support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ER_Band_Support_Present;
	ED_BOOLEAN UTRA_Multiple_Frequency_Band_Indicators_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UTRA_Multiple_Frequency_Band_Indicators_support_Present;
	ED_BOOLEAN E_UTRA_Multiple_Frequency_Band_Indicators_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_Multiple_Frequency_Band_Indicators_support_Present;
	ED_BOOLEAN Extended_TSC_Set_Capability_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_TSC_Set_Capability_support_Present;
	ED_BOOLEAN Extended_EARFCN_value_range; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_EARFCN_value_range_Present;

}	c_Classmark3Value;
#define INIT_c_Classmark3Value(sp) ED_RESET_MEM ((sp), sizeof (c_Classmark3Value))
/*FRK03a*/
void FREE_c_Classmark3Value(c_Classmark3Value* sp);
#define SETPRESENT_c_Classmark3Value_Associated_Radio_Capability_2(sp,present) (((sp)->Associated_Radio_Capability_2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Associated_Radio_Capability_2(sp) ((sp)->Associated_Radio_Capability_2_Present)
#define SETPRESENT_c_Classmark3Value_Associated_Radio_Capability_1(sp,present) (((sp)->Associated_Radio_Capability_1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Associated_Radio_Capability_1(sp) ((sp)->Associated_Radio_Capability_1_Present)
#define SETPRESENT_c_Classmark3Value_R_GSM_band_Associated_Radio_Capability(sp,present) (((sp)->R_GSM_band_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_R_GSM_band_Associated_Radio_Capability(sp) ((sp)->R_GSM_band_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_HSCSD_Multi_Slot_Class(sp,present) (((sp)->HSCSD_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_HSCSD_Multi_Slot_Class(sp) ((sp)->HSCSD_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_SMS_VALUE(sp,present) (((sp)->SMS_VALUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_SMS_VALUE(sp) ((sp)->SMS_VALUE_Present)
#define SETPRESENT_c_Classmark3Value_SM_VALUE(sp,present) (((sp)->SM_VALUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_SM_VALUE(sp) ((sp)->SM_VALUE_Present)
#define SETPRESENT_c_Classmark3Value_MS_Positioning_Method(sp,present) (((sp)->MS_Positioning_Method_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_MS_Positioning_Method(sp) ((sp)->MS_Positioning_Method_Present)
#define SETPRESENT_c_Classmark3Value_ECSD_Multi_Slot_Class(sp,present) (((sp)->ECSD_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_ECSD_Multi_Slot_Class(sp) ((sp)->ECSD_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_Modulation_Capability(sp,present) (((sp)->Modulation_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Modulation_Capability(sp) ((sp)->Modulation_Capability_Present)
#define SETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_1(sp,present) (((sp)->_8_PSK_RF_Power_Capability_1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_1(sp) ((sp)->_8_PSK_RF_Power_Capability_1_Present)
#define SETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_2(sp,present) (((sp)->_8_PSK_RF_Power_Capability_2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value__8_PSK_RF_Power_Capability_2(sp) ((sp)->_8_PSK_RF_Power_Capability_2_Present)
#define SETPRESENT_c_Classmark3Value_GSM_400_Bands_Supported(sp,present) (((sp)->GSM_400_Bands_Supported_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GSM_400_Bands_Supported(sp) ((sp)->GSM_400_Bands_Supported_Present)
#define SETPRESENT_c_Classmark3Value_GSM_400_Associated_Radio_Capability(sp,present) (((sp)->GSM_400_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GSM_400_Associated_Radio_Capability(sp) ((sp)->GSM_400_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_GSM_850_Associated_Radio_Capability(sp,present) (((sp)->GSM_850_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GSM_850_Associated_Radio_Capability(sp) ((sp)->GSM_850_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_GSM_1900_Associated_Radio_Capability(sp,present) (((sp)->GSM_1900_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GSM_1900_Associated_Radio_Capability(sp) ((sp)->GSM_1900_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_DTM_GPRS_Multi_Slot_Class(sp,present) (((sp)->DTM_GPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_DTM_GPRS_Multi_Slot_Class(sp) ((sp)->DTM_GPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_Single_Slot_DTM(sp,present) (((sp)->Single_Slot_DTM_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Single_Slot_DTM(sp) ((sp)->Single_Slot_DTM_Present)
#define SETPRESENT_c_Classmark3Value_DTM_EGPRS_Multi_Slot_Class(sp,present) (((sp)->DTM_EGPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_DTM_EGPRS_Multi_Slot_Class(sp) ((sp)->DTM_EGPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_GSM_Band(sp,present) (((sp)->GSM_Band_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GSM_Band(sp) ((sp)->GSM_Band_Present)
#define SETPRESENT_c_Classmark3Value_GSM_750_Associated_Radio_Capability(sp,present) (((sp)->GSM_750_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GSM_750_Associated_Radio_Capability(sp) ((sp)->GSM_750_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(sp,present) (((sp)->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(sp) ((sp)->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present)
#define SETPRESENT_c_Classmark3Value_GERAN_Feature_Package_1(sp,present) (((sp)->GERAN_Feature_Package_1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GERAN_Feature_Package_1(sp) ((sp)->GERAN_Feature_Package_1_Present)
#define SETPRESENT_c_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(sp,present) (((sp)->Extended_DTM_GPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(sp) ((sp)->Extended_DTM_GPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(sp,present) (((sp)->Extended_DTM_EGPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(sp) ((sp)->Extended_DTM_EGPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_High_Multislot_Capability(sp,present) (((sp)->High_Multislot_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_High_Multislot_Capability(sp) ((sp)->High_Multislot_Capability_Present)
#define SETPRESENT_c_Classmark3Value_Length(sp,present) (((sp)->Length_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Length(sp) ((sp)->Length_Present)
#define SETPRESENT_c_Classmark3Value_FLO_Iu_Capability(sp,present) (((sp)->FLO_Iu_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_FLO_Iu_Capability(sp) ((sp)->FLO_Iu_Capability_Present)
#define SETPRESENT_c_Classmark3Value_GERAN_Feature_Package_2(sp,present) (((sp)->GERAN_Feature_Package_2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GERAN_Feature_Package_2(sp) ((sp)->GERAN_Feature_Package_2_Present)
#define SETPRESENT_c_Classmark3Value_GMSK_Multislot_Power_Profile(sp,present) (((sp)->GMSK_Multislot_Power_Profile_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GMSK_Multislot_Power_Profile(sp) ((sp)->GMSK_Multislot_Power_Profile_Present)
#define SETPRESENT_c_Classmark3Value__8_PSK_Multislot_Power_Profile(sp,present) (((sp)->_8_PSK_Multislot_Power_Profile_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value__8_PSK_Multislot_Power_Profile(sp) ((sp)->_8_PSK_Multislot_Power_Profile_Present)
#define SETPRESENT_c_Classmark3Value_T_GSM_400_Bands_Supported(sp,present) (((sp)->T_GSM_400_Bands_Supported_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_T_GSM_400_Bands_Supported(sp) ((sp)->T_GSM_400_Bands_Supported_Present)
#define SETPRESENT_c_Classmark3Value_T_GSM_400_Associated_Radio_Capability(sp,present) (((sp)->T_GSM_400_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_T_GSM_400_Associated_Radio_Capability(sp) ((sp)->T_GSM_400_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_T_GSM_900_Associated_Radio_Capability(sp,present) (((sp)->T_GSM_900_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_T_GSM_900_Associated_Radio_Capability(sp) ((sp)->T_GSM_900_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_Downlink_Advanced_Receiver_Performance(sp,present) (((sp)->Downlink_Advanced_Receiver_Performance_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Downlink_Advanced_Receiver_Performance(sp) ((sp)->Downlink_Advanced_Receiver_Performance_Present)
#define SETPRESENT_c_Classmark3Value_DTM_Enhancements_Capability(sp,present) (((sp)->DTM_Enhancements_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_DTM_Enhancements_Capability(sp) ((sp)->DTM_Enhancements_Capability_Present)
#define SETPRESENT_c_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class(sp,present) (((sp)->DTM_GPRS_High_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_DTM_GPRS_High_Multi_Slot_Class(sp) ((sp)->DTM_GPRS_High_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_Offset_required(sp,present) (((sp)->Offset_required_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Offset_required(sp) ((sp)->Offset_required_Present)
#define SETPRESENT_c_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class(sp,present) (((sp)->DTM_EGPRS_High_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_DTM_EGPRS_High_Multi_Slot_Class(sp) ((sp)->DTM_EGPRS_High_Multi_Slot_Class_Present)
#define SETPRESENT_c_Classmark3Value_Repeated_ACCH_Capability(sp,present) (((sp)->Repeated_ACCH_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Repeated_ACCH_Capability(sp) ((sp)->Repeated_ACCH_Capability_Present)
#define SETPRESENT_c_Classmark3Value_GSM_710_Associated_Radio_Capability(sp,present) (((sp)->GSM_710_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GSM_710_Associated_Radio_Capability(sp) ((sp)->GSM_710_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_T_GSM_810_Associated_Radio_Capability(sp,present) (((sp)->T_GSM_810_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_T_GSM_810_Associated_Radio_Capability(sp) ((sp)->T_GSM_810_Associated_Radio_Capability_Present)
#define SETPRESENT_c_Classmark3Value_Ciphering_Mode_Setting_Capability(sp,present) (((sp)->Ciphering_Mode_Setting_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Ciphering_Mode_Setting_Capability(sp) ((sp)->Ciphering_Mode_Setting_Capability_Present)
#define SETPRESENT_c_Classmark3Value_Additional_Positioning_Capabilities(sp,present) (((sp)->Additional_Positioning_Capabilities_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Additional_Positioning_Capabilities(sp) ((sp)->Additional_Positioning_Capabilities_Present)
#define SETPRESENT_c_Classmark3Value_E_UTRA_FDD_support(sp,present) (((sp)->E_UTRA_FDD_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_E_UTRA_FDD_support(sp) ((sp)->E_UTRA_FDD_support_Present)
#define SETPRESENT_c_Classmark3Value_E_UTRA_TDD_support(sp,present) (((sp)->E_UTRA_TDD_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_E_UTRA_TDD_support(sp) ((sp)->E_UTRA_TDD_support_Present)
#define SETPRESENT_c_Classmark3Value_E_UTRA_Measurement_and_Reporting_support(sp,present) (((sp)->E_UTRA_Measurement_and_Reporting_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_E_UTRA_Measurement_and_Reporting_support(sp) ((sp)->E_UTRA_Measurement_and_Reporting_support_Present)
#define SETPRESENT_c_Classmark3Value_Priority_based_reselection_support(sp,present) (((sp)->Priority_based_reselection_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Priority_based_reselection_support(sp) ((sp)->Priority_based_reselection_support_Present)
#define SETPRESENT_c_Classmark3Value_UTRA_CSG_Cells_Reporting(sp,present) (((sp)->UTRA_CSG_Cells_Reporting_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_UTRA_CSG_Cells_Reporting(sp) ((sp)->UTRA_CSG_Cells_Reporting_Present)
#define SETPRESENT_c_Classmark3Value_VAMOS_Level(sp,present) (((sp)->VAMOS_Level_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_VAMOS_Level(sp) ((sp)->VAMOS_Level_Present)
#define SETPRESENT_c_Classmark3Value_TIGHTER_Capability(sp,present) (((sp)->TIGHTER_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_TIGHTER_Capability(sp) ((sp)->TIGHTER_Capability_Present)
#define SETPRESENT_c_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH(sp,present) (((sp)->Selective_Ciphering_of_Downlink_SACCH_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Selective_Ciphering_of_Downlink_SACCH(sp) ((sp)->Selective_Ciphering_of_Downlink_SACCH_Present)
#define SETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(sp,present) (((sp)->CS_to_PS_SRVCC_from_GERAN_to_UTRA_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(sp) ((sp)->CS_to_PS_SRVCC_from_GERAN_to_UTRA_Present)
#define SETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(sp,present) (((sp)->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(sp) ((sp)->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_Present)
#define SETPRESENT_c_Classmark3Value_GERAN_Network_Sharing_support(sp,present) (((sp)->GERAN_Network_Sharing_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_GERAN_Network_Sharing_support(sp) ((sp)->GERAN_Network_Sharing_support_Present)
#define SETPRESENT_c_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(sp,present) (((sp)->E_UTRA_Wideband_RSRQ_measurements_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(sp) ((sp)->E_UTRA_Wideband_RSRQ_measurements_support_Present)
#define SETPRESENT_c_Classmark3Value_ER_Band_Support(sp,present) (((sp)->ER_Band_Support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_ER_Band_Support(sp) ((sp)->ER_Band_Support_Present)
#define SETPRESENT_c_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(sp,present) (((sp)->UTRA_Multiple_Frequency_Band_Indicators_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(sp) ((sp)->UTRA_Multiple_Frequency_Band_Indicators_support_Present)
#define SETPRESENT_c_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(sp,present) (((sp)->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(sp) ((sp)->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present)
#define SETPRESENT_c_Classmark3Value_Extended_TSC_Set_Capability_support(sp,present) (((sp)->Extended_TSC_Set_Capability_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Extended_TSC_Set_Capability_support(sp) ((sp)->Extended_TSC_Set_Capability_support_Present)
#define SETPRESENT_c_Classmark3Value_Extended_EARFCN_value_range(sp,present) (((sp)->Extended_EARFCN_value_range_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_Classmark3Value_Extended_EARFCN_value_range(sp) ((sp)->Extended_EARFCN_value_range_Present)

/* Access member 'data' of type 'c_ReceiveNPduNumbersList_sapi' as a variable reference */
#define VAR_c_ReceiveNPduNumbersList_sapi_data(var) var

/* Access member 'data' of type 'c_ReceiveNPduNumbersList_sapi' as a pointer */
#define PTR_c_ReceiveNPduNumbersList_sapi_data(var) (&var)

/* Access member 'sapi' of type 'c_ReceiveNPduNumbersList' as a variable reference */
#define VAR_c_ReceiveNPduNumbersList_sapi(var) var

/* Access member 'sapi' of type 'c_ReceiveNPduNumbersList' as a pointer */
#define PTR_c_ReceiveNPduNumbersList_sapi(var) (&var)

/* Access member 'data' of type 'c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value' as a variable reference */
#define VAR_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value_data(var) var

/* Access member 'data' of type 'c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value' as a pointer */
#define PTR_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value_data(var) (&var)

/* Access member 'Receive_N_PDU_Number_value' of type 'c_ReceiveNPduNumbersList' as a variable reference */
#define VAR_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value(var) var

/* Access member 'Receive_N_PDU_Number_value' of type 'c_ReceiveNPduNumbersList' as a pointer */
#define PTR_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_ReceiveNPduNumbersList_sapi */
typedef struct _c_ReceiveNPduNumbersList_sapi {

	ED_OCTET* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-19235=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_ReceiveNPduNumbersList_sapi;

/* DEFINITION OF SUB-STRUCTURE c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value */
typedef struct _c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value {

	ED_OCTET* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-19239=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value;


/*-A----------------------------------*/
typedef struct _c_ReceiveNPduNumbersList {

	c_ReceiveNPduNumbersList_sapi sapi;/*GFB09*//*GBD01b*/
	c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value Receive_N_PDU_Number_value;/*GFB09*//*GBD01b*/

}	c_ReceiveNPduNumbersList;
#define INIT_c_ReceiveNPduNumbersList(sp) ED_RESET_MEM ((sp), sizeof (c_ReceiveNPduNumbersList))
/*FRK03a*/
void FREE_c_ReceiveNPduNumbersList(c_ReceiveNPduNumbersList* sp);

/* Access member 'GEA_1' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GEA_1(var) var

/* Access member 'GEA_1' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GEA_1(var) (&var)

/* Access member 'SM_capabilities_via_dedicated_channels' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_SM_capabilities_via_dedicated_channels(var) var

/* Access member 'SM_capabilities_via_dedicated_channels' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_SM_capabilities_via_dedicated_channels(var) (&var)

/* Access member 'SM_capabilities_via_GPRS_channels' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_SM_capabilities_via_GPRS_channels(var) var

/* Access member 'SM_capabilities_via_GPRS_channels' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_SM_capabilities_via_GPRS_channels(var) (&var)

/* Access member 'UCS2_support' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_UCS2_support(var) var

/* Access member 'UCS2_support' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_UCS2_support(var) (&var)

/* Access member 'SS_Screening_Indicator' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_SS_Screening_Indicator(var) var

/* Access member 'SS_Screening_Indicator' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_SS_Screening_Indicator(var) (&var)

/* Access member 'SoLSA_Capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_SoLSA_Capability(var) var

/* Access member 'SoLSA_Capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_SoLSA_Capability(var) (&var)

/* Access member 'Revision_level_indicator' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_Revision_level_indicator(var) var

/* Access member 'Revision_level_indicator' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_Revision_level_indicator(var) (&var)

/* Access member 'PFC_feature_mode' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_PFC_feature_mode(var) var

/* Access member 'PFC_feature_mode' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_PFC_feature_mode(var) (&var)

/* Access member 'GEA_2' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GEA_2(var) var

/* Access member 'GEA_2' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GEA_2(var) (&var)

/* Access member 'GEA_3' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GEA_3(var) var

/* Access member 'GEA_3' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GEA_3(var) (&var)

/* Access member 'GEA_4' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GEA_4(var) var

/* Access member 'GEA_4' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GEA_4(var) (&var)

/* Access member 'GEA_5' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GEA_5(var) var

/* Access member 'GEA_5' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GEA_5(var) (&var)

/* Access member 'GEA_6' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GEA_6(var) var

/* Access member 'GEA_6' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GEA_6(var) (&var)

/* Access member 'GEA_7' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GEA_7(var) var

/* Access member 'GEA_7' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GEA_7(var) (&var)

/* Access member 'LCS_VA_capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_LCS_VA_capability(var) var

/* Access member 'LCS_VA_capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_LCS_VA_capability(var) (&var)

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(var) var

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(var) (&var)

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(var) var

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(var) (&var)

/* Access member 'EMM_Combined_procedures_Capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_EMM_Combined_procedures_Capability(var) var

/* Access member 'EMM_Combined_procedures_Capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_EMM_Combined_procedures_Capability(var) (&var)

/* Access member 'ISR_support' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_ISR_support(var) var

/* Access member 'ISR_support' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_ISR_support(var) (&var)

/* Access member 'SRVCC_to_GERAN_UTRAN_capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(var) var

/* Access member 'SRVCC_to_GERAN_UTRAN_capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(var) (&var)

/* Access member 'EPC_capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_EPC_capability(var) var

/* Access member 'EPC_capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_EPC_capability(var) (&var)

/* Access member 'NF_capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_NF_capability(var) var

/* Access member 'NF_capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_NF_capability(var) (&var)

/* Access member 'GERAN_network_sharing_capability' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GERAN_network_sharing_capability(var) var

/* Access member 'GERAN_network_sharing_capability' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GERAN_network_sharing_capability(var) (&var)

/* Access member 'User_plane_integrity_protection_support' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_User_plane_integrity_protection_support(var) var

/* Access member 'User_plane_integrity_protection_support' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_User_plane_integrity_protection_support(var) (&var)

/* Access member 'GIA_4' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GIA_4(var) var

/* Access member 'GIA_4' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GIA_4(var) (&var)

/* Access member 'GIA_5' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GIA_5(var) var

/* Access member 'GIA_5' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GIA_5(var) (&var)

/* Access member 'GIA_6' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GIA_6(var) var

/* Access member 'GIA_6' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GIA_6(var) (&var)

/* Access member 'GIA_7' of type 'c_MsNetwkCpblty' as a variable reference */
#define VAR_c_MsNetwkCpblty_GIA_7(var) var

/* Access member 'GIA_7' of type 'c_MsNetwkCpblty' as a pointer */
#define PTR_c_MsNetwkCpblty_GIA_7(var) (&var)


/*-A----------------------------------*/
typedef struct _c_MsNetwkCpblty {
	ED_LOCATOR GEA_1___LOCATOR; /* QUI2 */
	ED_LOCATOR SM_capabilities_via_dedicated_channels___LOCATOR; /* QUI2 */
	ED_LOCATOR SM_capabilities_via_GPRS_channels___LOCATOR; /* QUI2 */
	ED_LOCATOR UCS2_support___LOCATOR; /* QUI2 */
	ED_LOCATOR SS_Screening_Indicator___LOCATOR; /* QUI2 */
	ED_LOCATOR SoLSA_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Revision_level_indicator___LOCATOR; /* QUI2 */
	ED_LOCATOR PFC_feature_mode___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA_2___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA_3___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA_4___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA_5___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA_6___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA_7___LOCATOR; /* QUI2 */
	ED_LOCATOR LCS_VA_capability___LOCATOR; /* QUI2 */
	ED_LOCATOR PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability___LOCATOR; /* QUI2 */
	ED_LOCATOR PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability___LOCATOR; /* QUI2 */
	ED_LOCATOR EMM_Combined_procedures_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR ISR_support___LOCATOR; /* QUI2 */
	ED_LOCATOR SRVCC_to_GERAN_UTRAN_capability___LOCATOR; /* QUI2 */
	ED_LOCATOR EPC_capability___LOCATOR; /* QUI2 */
	ED_LOCATOR NF_capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GERAN_network_sharing_capability___LOCATOR; /* QUI2 */
	ED_LOCATOR User_plane_integrity_protection_support___LOCATOR; /* QUI2 */
	ED_LOCATOR GIA_4___LOCATOR; /* QUI2 */
	ED_LOCATOR GIA_5___LOCATOR; /* QUI2 */
	ED_LOCATOR GIA_6___LOCATOR; /* QUI2 */
	ED_LOCATOR GIA_7___LOCATOR; /* QUI2 */

	ED_BOOLEAN GEA_1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SM_capabilities_via_dedicated_channels; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SM_capabilities_via_GPRS_channels; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UCS2_support; /* ODY01a *//*GBD01b*/
	ED_OCTET SS_Screening_Indicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SoLSA_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Revision_level_indicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PFC_feature_mode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PFC_feature_mode_Present;
	ED_BOOLEAN GEA_2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_2_Present;
	ED_BOOLEAN GEA_3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_3_Present;
	ED_BOOLEAN GEA_4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_4_Present;
	ED_BOOLEAN GEA_5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_5_Present;
	ED_BOOLEAN GEA_6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_6_Present;
	ED_BOOLEAN GEA_7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_7_Present;
	ED_BOOLEAN LCS_VA_capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LCS_VA_capability_Present;
	ED_BOOLEAN PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_Present;
	ED_BOOLEAN PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_Present;
	ED_BOOLEAN EMM_Combined_procedures_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMM_Combined_procedures_Capability_Present;
	ED_BOOLEAN ISR_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ISR_support_Present;
	ED_BOOLEAN SRVCC_to_GERAN_UTRAN_capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SRVCC_to_GERAN_UTRAN_capability_Present;
	ED_BOOLEAN EPC_capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EPC_capability_Present;
	ED_BOOLEAN NF_capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NF_capability_Present;
	ED_BOOLEAN GERAN_network_sharing_capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GERAN_network_sharing_capability_Present;
	ED_BOOLEAN User_plane_integrity_protection_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN User_plane_integrity_protection_support_Present;
	ED_BOOLEAN GIA_4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GIA_4_Present;
	ED_BOOLEAN GIA_5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GIA_5_Present;
	ED_BOOLEAN GIA_6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GIA_6_Present;
	ED_BOOLEAN GIA_7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GIA_7_Present;

}	c_MsNetwkCpblty;
#define INIT_c_MsNetwkCpblty(sp) ED_RESET_MEM ((sp), sizeof (c_MsNetwkCpblty))
/*FRK03a*/
void FREE_c_MsNetwkCpblty(c_MsNetwkCpblty* sp);
#define SETPRESENT_c_MsNetwkCpblty_PFC_feature_mode(sp,present) (((sp)->PFC_feature_mode_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_PFC_feature_mode(sp) ((sp)->PFC_feature_mode_Present)
#define SETPRESENT_c_MsNetwkCpblty_GEA_2(sp,present) (((sp)->GEA_2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GEA_2(sp) ((sp)->GEA_2_Present)
#define SETPRESENT_c_MsNetwkCpblty_GEA_3(sp,present) (((sp)->GEA_3_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GEA_3(sp) ((sp)->GEA_3_Present)
#define SETPRESENT_c_MsNetwkCpblty_GEA_4(sp,present) (((sp)->GEA_4_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GEA_4(sp) ((sp)->GEA_4_Present)
#define SETPRESENT_c_MsNetwkCpblty_GEA_5(sp,present) (((sp)->GEA_5_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GEA_5(sp) ((sp)->GEA_5_Present)
#define SETPRESENT_c_MsNetwkCpblty_GEA_6(sp,present) (((sp)->GEA_6_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GEA_6(sp) ((sp)->GEA_6_Present)
#define SETPRESENT_c_MsNetwkCpblty_GEA_7(sp,present) (((sp)->GEA_7_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GEA_7(sp) ((sp)->GEA_7_Present)
#define SETPRESENT_c_MsNetwkCpblty_LCS_VA_capability(sp,present) (((sp)->LCS_VA_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_LCS_VA_capability(sp) ((sp)->LCS_VA_capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(sp,present) (((sp)->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(sp) ((sp)->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(sp,present) (((sp)->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(sp) ((sp)->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_EMM_Combined_procedures_Capability(sp,present) (((sp)->EMM_Combined_procedures_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_EMM_Combined_procedures_Capability(sp) ((sp)->EMM_Combined_procedures_Capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_ISR_support(sp,present) (((sp)->ISR_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_ISR_support(sp) ((sp)->ISR_support_Present)
#define SETPRESENT_c_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(sp,present) (((sp)->SRVCC_to_GERAN_UTRAN_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(sp) ((sp)->SRVCC_to_GERAN_UTRAN_capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_EPC_capability(sp,present) (((sp)->EPC_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_EPC_capability(sp) ((sp)->EPC_capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_NF_capability(sp,present) (((sp)->NF_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_NF_capability(sp) ((sp)->NF_capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_GERAN_network_sharing_capability(sp,present) (((sp)->GERAN_network_sharing_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GERAN_network_sharing_capability(sp) ((sp)->GERAN_network_sharing_capability_Present)
#define SETPRESENT_c_MsNetwkCpblty_User_plane_integrity_protection_support(sp,present) (((sp)->User_plane_integrity_protection_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_User_plane_integrity_protection_support(sp) ((sp)->User_plane_integrity_protection_support_Present)
#define SETPRESENT_c_MsNetwkCpblty_GIA_4(sp,present) (((sp)->GIA_4_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GIA_4(sp) ((sp)->GIA_4_Present)
#define SETPRESENT_c_MsNetwkCpblty_GIA_5(sp,present) (((sp)->GIA_5_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GIA_5(sp) ((sp)->GIA_5_Present)
#define SETPRESENT_c_MsNetwkCpblty_GIA_6(sp,present) (((sp)->GIA_6_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GIA_6(sp) ((sp)->GIA_6_Present)
#define SETPRESENT_c_MsNetwkCpblty_GIA_7(sp,present) (((sp)->GIA_7_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsNetwkCpblty_GIA_7(sp) ((sp)->GIA_7_Present)

/* Access member 'Access_Technology_Type' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_Technology_Type(var) var

/* Access member 'Access_Technology_Type' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_Technology_Type(var) (&var)

/* Access member 'Length' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Length(var) var

/* Access member 'Length' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Length(var) (&var)

/* Access member 'RF_Power_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RF_Power_Capability(var) var

/* Access member 'RF_Power_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RF_Power_Capability(var) (&var)

/* Access member 'A5_1' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_1(var) var

/* Access member 'A5_1' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_1(var) (&var)

/* Access member 'A5_2' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_2(var) var

/* Access member 'A5_2' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_2(var) (&var)

/* Access member 'A5_3' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_3(var) var

/* Access member 'A5_3' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_3(var) (&var)

/* Access member 'A5_4' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_4(var) var

/* Access member 'A5_4' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_4(var) (&var)

/* Access member 'A5_5' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_5(var) var

/* Access member 'A5_5' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_5(var) (&var)

/* Access member 'A5_6' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_6(var) var

/* Access member 'A5_6' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_6(var) (&var)

/* Access member 'A5_7' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_7(var) var

/* Access member 'A5_7' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits_A5_7(var) (&var)

/* Access member 'A5_bits' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits(var) (*var)

/* Access member 'A5_bits' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits(var) var

/* Access member 'ES_IND' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_ES_IND(var) var

/* Access member 'ES_IND' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_ES_IND(var) (&var)

/* Access member 'PS' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS(var) var

/* Access member 'PS' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS(var) (&var)

/* Access member 'VGCS' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VGCS(var) var

/* Access member 'VGCS' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VGCS(var) (&var)

/* Access member 'VBS' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VBS(var) var

/* Access member 'VBS' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VBS(var) (&var)

/* Access member 'HSCSD_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_HSCSD_multislot_class(var) var

/* Access member 'HSCSD_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_HSCSD_multislot_class(var) (&var)

/* Access member 'GPRS_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_multislot_class(var) var

/* Access member 'GPRS_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_multislot_class(var) (&var)

/* Access member 'GPRS_Extended_Dynamic_Allocation_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_Extended_Dynamic_Allocation_Capability(var) var

/* Access member 'GPRS_Extended_Dynamic_Allocation_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_Extended_Dynamic_Allocation_Capability(var) (&var)

/* Access member 'SMS_VALUE' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SMS_VALUE(var) var

/* Access member 'SMS_VALUE' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SMS_VALUE(var) (&var)

/* Access member 'SM_VALUE' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SM_VALUE(var) var

/* Access member 'SM_VALUE' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SM_VALUE(var) (&var)

/* Access member 'ECSD_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_ECSD_multislot_class(var) var

/* Access member 'ECSD_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_ECSD_multislot_class(var) (&var)

/* Access member 'EGPRS_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_multislot_class(var) var

/* Access member 'EGPRS_multislot_class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_multislot_class(var) (&var)

/* Access member 'EGPRS_Extended_Dynamic_Allocation_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_Extended_Dynamic_Allocation_Capability(var) var

/* Access member 'EGPRS_Extended_Dynamic_Allocation_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_Extended_Dynamic_Allocation_Capability(var) (&var)

/* Access member 'DTM_GPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_GPRS_Multi_Slot_Class(var) var

/* Access member 'DTM_GPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_GPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Single_Slot_DTM' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_Single_Slot_DTM(var) var

/* Access member 'Single_Slot_DTM' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_Single_Slot_DTM(var) (&var)

/* Access member 'DTM_EGPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_EGPRS_Multi_Slot_Class(var) var

/* Access member 'DTM_EGPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_EGPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Multislot_capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability(var) (*var)

/* Access member 'Multislot_capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability(var) var

/* Access member '_8PSK_Power_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8PSK_Power_Capability(var) var

/* Access member '_8PSK_Power_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8PSK_Power_Capability(var) (&var)

/* Access member 'COMPACT_Interference_Measurement_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_COMPACT_Interference_Measurement_Capability(var) var

/* Access member 'COMPACT_Interference_Measurement_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_COMPACT_Interference_Measurement_Capability(var) (&var)

/* Access member 'Revision_Level_Indicator' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Revision_Level_Indicator(var) var

/* Access member 'Revision_Level_Indicator' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Revision_Level_Indicator(var) (&var)

/* Access member 'UMTS_FDD_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_FDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_FDD_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_FDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'CDMA_2000_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_CDMA_2000_Radio_Access_Technology_Capability(var) var

/* Access member 'CDMA_2000_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_CDMA_2000_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'GERAN_Feature_Package_1' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Feature_Package_1(var) var

/* Access member 'GERAN_Feature_Package_1' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Feature_Package_1(var) (&var)

/* Access member 'Extended_DTM_GPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_GPRS_Multi_Slot_Class(var) var

/* Access member 'Extended_DTM_GPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_GPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Extended_DTM_EGPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_EGPRS_Multi_Slot_Class(var) var

/* Access member 'Extended_DTM_EGPRS_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_EGPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Modulation_based_multislot_class_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Modulation_based_multislot_class_support(var) var

/* Access member 'Modulation_based_multislot_class_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Modulation_based_multislot_class_support(var) (&var)

/* Access member 'High_Multislot_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_High_Multislot_Capability(var) var

/* Access member 'High_Multislot_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_High_Multislot_Capability(var) (&var)

/* Access member 'Length' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Length(var) var

/* Access member 'Length' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Length(var) (&var)

/* Access member 'FLO_Iu_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FLO_Iu_Capability(var) var

/* Access member 'FLO_Iu_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FLO_Iu_Capability(var) (&var)

/* Access member 'GMSK_Multislot_Power_Profile' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GMSK_Multislot_Power_Profile(var) var

/* Access member 'GMSK_Multislot_Power_Profile' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GMSK_Multislot_Power_Profile(var) (&var)

/* Access member '_8_PSK_Multislot_Power_Profile' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8_PSK_Multislot_Power_Profile(var) var

/* Access member '_8_PSK_Multislot_Power_Profile' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8_PSK_Multislot_Power_Profile(var) (&var)

/* Access member 'Multiple_TBF_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multiple_TBF_Capability(var) var

/* Access member 'Multiple_TBF_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multiple_TBF_Capability(var) (&var)

/* Access member 'Downlink_Advanced_Receiver_Performance' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Advanced_Receiver_Performance(var) var

/* Access member 'Downlink_Advanced_Receiver_Performance' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Advanced_Receiver_Performance(var) (&var)

/* Access member 'Extended_RLC_MAC_Control_Message_Segmentation_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_RLC_MAC_Control_Message_Segmentation_Capability(var) var

/* Access member 'Extended_RLC_MAC_Control_Message_Segmentation_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_RLC_MAC_Control_Message_Segmentation_Capability(var) (&var)

/* Access member 'DTM_Enhancements_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Enhancements_Capability(var) var

/* Access member 'DTM_Enhancements_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Enhancements_Capability(var) (&var)

/* Access member 'DTM_GPRS_High_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_GPRS_High_Multi_Slot_Class(var) var

/* Access member 'DTM_GPRS_High_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_GPRS_High_Multi_Slot_Class(var) (&var)

/* Access member 'DTM_EGPRS_High_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_EGPRS_High_Multi_Slot_Class(var) var

/* Access member 'DTM_EGPRS_High_Multi_Slot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_EGPRS_High_Multi_Slot_Class(var) (&var)

/* Access member 'PS_Handover_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS_Handover_Capability(var) var

/* Access member 'PS_Handover_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS_Handover_Capability(var) (&var)

/* Access member 'DTM_Handover_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Handover_Capability(var) var

/* Access member 'DTM_Handover_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Handover_Capability(var) (&var)

/* Access member 'Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(var) var

/* Access member 'Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(var) (&var)

/* Access member 'Downlink_Dual_Carrier_for_DTM_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Dual_Carrier_for_DTM_Capability(var) var

/* Access member 'Downlink_Dual_Carrier_for_DTM_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Dual_Carrier_for_DTM_Capability(var) (&var)

/* Access member 'Flexible_Timeslot_Assignment' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Flexible_Timeslot_Assignment(var) var

/* Access member 'Flexible_Timeslot_Assignment' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Flexible_Timeslot_Assignment(var) (&var)

/* Access member 'GAN_PS_Handover_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GAN_PS_Handover_Capability(var) var

/* Access member 'GAN_PS_Handover_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GAN_PS_Handover_Capability(var) (&var)

/* Access member 'RLC_Non_persistent_Mode' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RLC_Non_persistent_Mode(var) var

/* Access member 'RLC_Non_persistent_Mode' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RLC_Non_persistent_Mode(var) (&var)

/* Access member 'Reduced_Latency_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Reduced_Latency_Capability(var) var

/* Access member 'Reduced_Latency_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Reduced_Latency_Capability(var) (&var)

/* Access member 'Uplink_EGPRS2' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Uplink_EGPRS2(var) var

/* Access member 'Uplink_EGPRS2' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Uplink_EGPRS2(var) (&var)

/* Access member 'Downlink_EGPRS2' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_EGPRS2(var) var

/* Access member 'Downlink_EGPRS2' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_EGPRS2(var) (&var)

/* Access member 'E_UTRA_FDD_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_FDD_support(var) var

/* Access member 'E_UTRA_FDD_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_FDD_support(var) (&var)

/* Access member 'E_UTRA_TDD_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_TDD_support(var) var

/* Access member 'E_UTRA_TDD_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_TDD_support(var) (&var)

/* Access member 'GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode(var) var

/* Access member 'GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode(var) (&var)

/* Access member 'Priority_based_reselection_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Priority_based_reselection_support(var) var

/* Access member 'Priority_based_reselection_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Priority_based_reselection_support(var) (&var)

/* Access member 'Alternative_EFTA_Multislot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_Alternative_EFTA_Multislot_Class(var) var

/* Access member 'Alternative_EFTA_Multislot_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_Alternative_EFTA_Multislot_Class(var) (&var)

/* Access member 'EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(var) var

/* Access member 'EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(var) (&var)

/* Access member 'Enhanced_Flexible_Timeslot_Assignment' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment(var) (*var)

/* Access member 'Enhanced_Flexible_Timeslot_Assignment' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment(var) var

/* Access member 'Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM(var) var

/* Access member 'Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM(var) (&var)

/* Access member 'EMST_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMST_Capability(var) var

/* Access member 'EMST_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMST_Capability(var) (&var)

/* Access member 'MTTI_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_MTTI_Capability(var) var

/* Access member 'MTTI_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_MTTI_Capability(var) (&var)

/* Access member 'UTRA_CSG_Cells_Reporting' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_CSG_Cells_Reporting(var) var

/* Access member 'UTRA_CSG_Cells_Reporting' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_CSG_Cells_Reporting(var) (&var)

/* Access member 'E_UTRA_CSG_Cells_Reporting' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_CSG_Cells_Reporting(var) var

/* Access member 'E_UTRA_CSG_Cells_Reporting' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_CSG_Cells_Reporting(var) (&var)

/* Access member 'DTR_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTR_Capability(var) var

/* Access member 'DTR_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTR_Capability(var) (&var)

/* Access member 'EMSR_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMSR_Capability(var) var

/* Access member 'EMSR_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMSR_Capability(var) (&var)

/* Access member 'Fast_Downlink_Frequency_Switching_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Fast_Downlink_Frequency_Switching_Capability(var) var

/* Access member 'Fast_Downlink_Frequency_Switching_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Fast_Downlink_Frequency_Switching_Capability(var) (&var)

/* Access member 'TIGHTER_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_TIGHTER_Capability(var) var

/* Access member 'TIGHTER_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_TIGHTER_Capability(var) (&var)

/* Access member 'FANR_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FANR_Capability(var) var

/* Access member 'FANR_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FANR_Capability(var) (&var)

/* Access member 'IPA_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_IPA_Capability(var) var

/* Access member 'IPA_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_IPA_Capability(var) (&var)

/* Access member 'GERAN_Network_Sharing_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Network_Sharing_support(var) var

/* Access member 'GERAN_Network_Sharing_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Network_Sharing_support(var) (&var)

/* Access member 'E_UTRA_Wideband_RSRQ_measurements_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Wideband_RSRQ_measurements_support(var) var

/* Access member 'E_UTRA_Wideband_RSRQ_measurements_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Wideband_RSRQ_measurements_support(var) (&var)

/* Access member 'UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_Multiple_Frequency_Band_Indicators_support(var) var

/* Access member 'UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_Multiple_Frequency_Band_Indicators_support(var) (&var)

/* Access member 'E_UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Multiple_Frequency_Band_Indicators_support(var) var

/* Access member 'E_UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Multiple_Frequency_Band_Indicators_support(var) (&var)

/* Access member 'DLMC_Non_contiguous_intra_band_reception' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Non_contiguous_intra_band_reception(var) var

/* Access member 'DLMC_Non_contiguous_intra_band_reception' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Non_contiguous_intra_band_reception(var) (&var)

/* Access member 'DLMC_Inter_band_reception' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Inter_band_reception(var) var

/* Access member 'DLMC_Inter_band_reception' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Inter_band_reception(var) (&var)

/* Access member 'DLMC_Maximum_Bandwidth' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Maximum_Bandwidth(var) var

/* Access member 'DLMC_Maximum_Bandwidth' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Maximum_Bandwidth(var) (&var)

/* Access member 'DLMC_Maximum_Number_of_Downlink_Timeslots' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Maximum_Number_of_Downlink_Timeslots(var) var

/* Access member 'DLMC_Maximum_Number_of_Downlink_Timeslots' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Maximum_Number_of_Downlink_Timeslots(var) (&var)

/* Access member 'DLMC_Maximum_Number_of_Downlink_Carriers' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Maximum_Number_of_Downlink_Carriers(var) var

/* Access member 'DLMC_Maximum_Number_of_Downlink_Carriers' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Maximum_Number_of_Downlink_Carriers(var) (&var)

/* Access member 'DLMC_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability(var) (*var)

/* Access member 'DLMC_Capability' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability(var) var

/* Access member 'Extended_TSC_Set_Capability_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_TSC_Set_Capability_support(var) var

/* Access member 'Extended_TSC_Set_Capability_support' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_TSC_Set_Capability_support(var) (&var)

/* Access member 'Extended_EARFCN_value_range' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_EARFCN_value_range(var) var

/* Access member 'Extended_EARFCN_value_range' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_EARFCN_value_range(var) (&var)

/* Access member 'Access_capabilities' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities(var) var

/* Access member 'Access_capabilities' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities(var) (&var)

/* Access member 'Access_capabilities' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities(var) (*var)

/* Access member 'Access_capabilities' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities(var) var

/* Access member 'Length' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Length(var) var

/* Access member 'Length' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Length(var) (&var)

/* Access member 'Access_Technology_Type' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data_Access_Technology_Type(var) var

/* Access member 'Access_Technology_Type' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data_Access_Technology_Type(var) (&var)

/* Access member 'GMSK_Power_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data_GMSK_Power_Class(var) var

/* Access member 'GMSK_Power_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data_GMSK_Power_Class(var) (&var)

/* Access member '_8PSK_Power_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data__8PSK_Power_Class(var) var

/* Access member '_8PSK_Power_Class' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data__8PSK_Power_Class(var) (&var)

/* Access member 'data' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data(var) (*var)

/* Access member 'data' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data(var) var

/* Access member 'Additional_access_technologies' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies(var) var

/* Access member 'Additional_access_technologies' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies(var) (&var)

/* Access member 'data' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data(var) (*var)

/* Access member 'data' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data(var) var

/* Access member 'MS_RA_capability_value' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value(var) var

/* Access member 'MS_RA_capability_value' of type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value(var) (&var)

/* Access member 'MS_RA_capability_value_part' of type 'c_MsRadioAccessCpblty' as a variable reference */
#define VAR_c_MsRadioAccessCpblty_MS_RA_capability_value_part(var) var

/* Access member 'MS_RA_capability_value_part' of type 'c_MsRadioAccessCpblty' as a pointer */
#define PTR_c_MsRadioAccessCpblty_MS_RA_capability_value_part(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits {
	ED_LOCATOR A5_1___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_2___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_3___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_4___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_5___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_6___LOCATOR; /* QUI2 */
	ED_LOCATOR A5_7___LOCATOR; /* QUI2 */

	ED_BOOLEAN A5_1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN A5_7; /* ODY01a *//*GBD01b*/

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability {
	ED_LOCATOR HSCSD_multislot_class___LOCATOR; /* QUI2 */
	ED_LOCATOR GPRS_multislot_class___LOCATOR; /* QUI2 */
	ED_LOCATOR GPRS_Extended_Dynamic_Allocation_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR SMS_VALUE___LOCATOR; /* QUI2 */
	ED_LOCATOR SM_VALUE___LOCATOR; /* QUI2 */
	ED_LOCATOR ECSD_multislot_class___LOCATOR; /* QUI2 */
	ED_LOCATOR EGPRS_multislot_class___LOCATOR; /* QUI2 */
	ED_LOCATOR EGPRS_Extended_Dynamic_Allocation_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_GPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Single_Slot_DTM___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_EGPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */

	ED_OCTET HSCSD_multislot_class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HSCSD_multislot_class_Present;
	ED_OCTET GPRS_multislot_class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GPRS_multislot_class_Present;
	ED_BOOLEAN GPRS_Extended_Dynamic_Allocation_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GPRS_Extended_Dynamic_Allocation_Capability_Present;
	ED_OCTET SMS_VALUE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SMS_VALUE_Present;
	ED_OCTET SM_VALUE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SM_VALUE_Present;
	ED_OCTET ECSD_multislot_class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ECSD_multislot_class_Present;
	ED_OCTET EGPRS_multislot_class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EGPRS_multislot_class_Present;
	ED_BOOLEAN EGPRS_Extended_Dynamic_Allocation_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EGPRS_Extended_Dynamic_Allocation_Capability_Present;
	ED_OCTET DTM_GPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_GPRS_Multi_Slot_Class_Present;
	ED_BOOLEAN Single_Slot_DTM; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Single_Slot_DTM_Present;
	ED_OCTET DTM_EGPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_EGPRS_Multi_Slot_Class_Present;

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment {
	ED_LOCATOR Alternative_EFTA_Multislot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier___LOCATOR; /* QUI2 */

	ED_OCTET Alternative_EFTA_Multislot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Alternative_EFTA_Multislot_Class_Present;
	ED_OCTET EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present;

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability {
	ED_LOCATOR DLMC_Non_contiguous_intra_band_reception___LOCATOR; /* QUI2 */
	ED_LOCATOR DLMC_Inter_band_reception___LOCATOR; /* QUI2 */
	ED_LOCATOR DLMC_Maximum_Bandwidth___LOCATOR; /* QUI2 */
	ED_LOCATOR DLMC_Maximum_Number_of_Downlink_Timeslots___LOCATOR; /* QUI2 */
	ED_LOCATOR DLMC_Maximum_Number_of_Downlink_Carriers___LOCATOR; /* QUI2 */

	ED_OCTET DLMC_Non_contiguous_intra_band_reception; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DLMC_Non_contiguous_intra_band_reception_Present;
	ED_BOOLEAN DLMC_Inter_band_reception; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DLMC_Inter_band_reception_Present;
	ED_OCTET DLMC_Maximum_Bandwidth; /* ODY01a *//*GBD01b*/
	ED_OCTET DLMC_Maximum_Number_of_Downlink_Timeslots; /* ODY01a *//*GBD01b*/
	ED_OCTET DLMC_Maximum_Number_of_Downlink_Carriers; /* ODY01a *//*GBD01b*/

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities {
	ED_LOCATOR RF_Power_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR ES_IND___LOCATOR; /* QUI2 */
	ED_LOCATOR PS___LOCATOR; /* QUI2 */
	ED_LOCATOR VGCS___LOCATOR; /* QUI2 */
	ED_LOCATOR VBS___LOCATOR; /* QUI2 */
	ED_LOCATOR _8PSK_Power_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR COMPACT_Interference_Measurement_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Revision_Level_Indicator___LOCATOR; /* QUI2 */
	ED_LOCATOR UMTS_FDD_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR CDMA_2000_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GERAN_Feature_Package_1___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_DTM_GPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_DTM_EGPRS_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR Modulation_based_multislot_class_support___LOCATOR; /* QUI2 */
	ED_LOCATOR High_Multislot_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */
	ED_LOCATOR FLO_Iu_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GMSK_Multislot_Power_Profile___LOCATOR; /* QUI2 */
	ED_LOCATOR _8_PSK_Multislot_Power_Profile___LOCATOR; /* QUI2 */
	ED_LOCATOR Multiple_TBF_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Downlink_Advanced_Receiver_Performance___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_RLC_MAC_Control_Message_Segmentation_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_Enhancements_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_GPRS_High_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_EGPRS_High_Multi_Slot_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR PS_Handover_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR DTM_Handover_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Multislot_Capability_Reduction_for_Downlink_Dual_Carrier___LOCATOR; /* QUI2 */
	ED_LOCATOR Downlink_Dual_Carrier_for_DTM_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Flexible_Timeslot_Assignment___LOCATOR; /* QUI2 */
	ED_LOCATOR GAN_PS_Handover_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR RLC_Non_persistent_Mode___LOCATOR; /* QUI2 */
	ED_LOCATOR Reduced_Latency_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Uplink_EGPRS2___LOCATOR; /* QUI2 */
	ED_LOCATOR Downlink_EGPRS2___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_FDD_support___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_TDD_support___LOCATOR; /* QUI2 */
	ED_LOCATOR GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode___LOCATOR; /* QUI2 */
	ED_LOCATOR Priority_based_reselection_support___LOCATOR; /* QUI2 */
	ED_LOCATOR Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM___LOCATOR; /* QUI2 */
	ED_LOCATOR EMST_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR MTTI_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR UTRA_CSG_Cells_Reporting___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_CSG_Cells_Reporting___LOCATOR; /* QUI2 */
	ED_LOCATOR DTR_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR EMSR_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR Fast_Downlink_Frequency_Switching_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR TIGHTER_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR FANR_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR IPA_Capability___LOCATOR; /* QUI2 */
	ED_LOCATOR GERAN_Network_Sharing_support___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_Wideband_RSRQ_measurements_support___LOCATOR; /* QUI2 */
	ED_LOCATOR UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR; /* QUI2 */
	ED_LOCATOR E_UTRA_Multiple_Frequency_Band_Indicators_support___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_TSC_Set_Capability_support___LOCATOR; /* QUI2 */
	ED_LOCATOR Extended_EARFCN_value_range___LOCATOR; /* QUI2 */

	ED_OCTET RF_Power_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RF_Power_Capability_Present;
	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits *A5_bits; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN A5_bits_Present;
	ED_BOOLEAN ES_IND; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ES_IND_Present;
	ED_BOOLEAN PS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PS_Present;
	ED_BOOLEAN VGCS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VGCS_Present;
	ED_BOOLEAN VBS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN VBS_Present;
	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability *Multislot_capability; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN Multislot_capability_Present;
	ED_OCTET _8PSK_Power_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN _8PSK_Power_Capability_Present;
	ED_BOOLEAN COMPACT_Interference_Measurement_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN COMPACT_Interference_Measurement_Capability_Present;
	ED_BOOLEAN Revision_Level_Indicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Revision_Level_Indicator_Present;
	ED_BOOLEAN UMTS_FDD_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UMTS_FDD_Radio_Access_Technology_Capability_Present;
	ED_BOOLEAN UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present;
	ED_BOOLEAN CDMA_2000_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CDMA_2000_Radio_Access_Technology_Capability_Present;
	ED_BOOLEAN UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present;
	ED_BOOLEAN GERAN_Feature_Package_1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GERAN_Feature_Package_1_Present;
	ED_OCTET Extended_DTM_GPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_DTM_GPRS_Multi_Slot_Class_Present;
	ED_OCTET Extended_DTM_EGPRS_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_DTM_EGPRS_Multi_Slot_Class_Present;
	ED_BOOLEAN Modulation_based_multislot_class_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Modulation_based_multislot_class_support_Present;
	ED_OCTET High_Multislot_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN High_Multislot_Capability_Present;
	ED_OCTET Length; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Length_Present;
	ED_BOOLEAN FLO_Iu_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN FLO_Iu_Capability_Present;
	ED_OCTET GMSK_Multislot_Power_Profile; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GMSK_Multislot_Power_Profile_Present;
	ED_OCTET _8_PSK_Multislot_Power_Profile; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN _8_PSK_Multislot_Power_Profile_Present;
	ED_BOOLEAN Multiple_TBF_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Multiple_TBF_Capability_Present;
	ED_OCTET Downlink_Advanced_Receiver_Performance; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Downlink_Advanced_Receiver_Performance_Present;
	ED_BOOLEAN Extended_RLC_MAC_Control_Message_Segmentation_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present;
	ED_BOOLEAN DTM_Enhancements_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_Enhancements_Capability_Present;
	ED_OCTET DTM_GPRS_High_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_GPRS_High_Multi_Slot_Class_Present;
	ED_OCTET DTM_EGPRS_High_Multi_Slot_Class; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_EGPRS_High_Multi_Slot_Class_Present;
	ED_BOOLEAN PS_Handover_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN PS_Handover_Capability_Present;
	ED_BOOLEAN DTM_Handover_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTM_Handover_Capability_Present;
	ED_OCTET Multislot_Capability_Reduction_for_Downlink_Dual_Carrier; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present;
	ED_BOOLEAN Downlink_Dual_Carrier_for_DTM_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Downlink_Dual_Carrier_for_DTM_Capability_Present;
	ED_BOOLEAN Flexible_Timeslot_Assignment; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Flexible_Timeslot_Assignment_Present;
	ED_BOOLEAN GAN_PS_Handover_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GAN_PS_Handover_Capability_Present;
	ED_BOOLEAN RLC_Non_persistent_Mode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RLC_Non_persistent_Mode_Present;
	ED_BOOLEAN Reduced_Latency_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Reduced_Latency_Capability_Present;
	ED_OCTET Uplink_EGPRS2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Uplink_EGPRS2_Present;
	ED_OCTET Downlink_EGPRS2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Downlink_EGPRS2_Present;
	ED_BOOLEAN E_UTRA_FDD_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_FDD_support_Present;
	ED_BOOLEAN E_UTRA_TDD_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_TDD_support_Present;
	ED_OCTET GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present;
	ED_BOOLEAN Priority_based_reselection_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Priority_based_reselection_support_Present;
	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment *Enhanced_Flexible_Timeslot_Assignment; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN Enhanced_Flexible_Timeslot_Assignment_Present;
	ED_BOOLEAN Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present;
	ED_BOOLEAN EMST_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMST_Capability_Present;
	ED_BOOLEAN MTTI_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MTTI_Capability_Present;
	ED_BOOLEAN UTRA_CSG_Cells_Reporting; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UTRA_CSG_Cells_Reporting_Present;
	ED_BOOLEAN E_UTRA_CSG_Cells_Reporting; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_CSG_Cells_Reporting_Present;
	ED_BOOLEAN DTR_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN DTR_Capability_Present;
	ED_BOOLEAN EMSR_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMSR_Capability_Present;
	ED_BOOLEAN Fast_Downlink_Frequency_Switching_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Fast_Downlink_Frequency_Switching_Capability_Present;
	ED_OCTET TIGHTER_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TIGHTER_Capability_Present;
	ED_BOOLEAN FANR_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN FANR_Capability_Present;
	ED_BOOLEAN IPA_Capability; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IPA_Capability_Present;
	ED_BOOLEAN GERAN_Network_Sharing_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GERAN_Network_Sharing_support_Present;
	ED_BOOLEAN E_UTRA_Wideband_RSRQ_measurements_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_Wideband_RSRQ_measurements_support_Present;
	ED_BOOLEAN UTRA_Multiple_Frequency_Band_Indicators_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UTRA_Multiple_Frequency_Band_Indicators_support_Present;
	ED_BOOLEAN E_UTRA_Multiple_Frequency_Band_Indicators_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN E_UTRA_Multiple_Frequency_Band_Indicators_support_Present;
	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability *DLMC_Capability; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN DLMC_Capability_Present;
	ED_BOOLEAN Extended_TSC_Set_Capability_support; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_TSC_Set_Capability_support_Present;
	ED_BOOLEAN Extended_EARFCN_value_range; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Extended_EARFCN_value_range_Present;

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities {
	ED_LOCATOR Length___LOCATOR; /* QUI2 */

	ED_OCTET Length; /* ODY01a *//*GBD01b*/
	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities Access_capabilities;/*GBD01b*/

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data {
	ED_LOCATOR Access_Technology_Type___LOCATOR; /* QUI2 */
	ED_LOCATOR GMSK_Power_Class___LOCATOR; /* QUI2 */
	ED_LOCATOR _8PSK_Power_Class___LOCATOR; /* QUI2 */

	ED_OCTET Access_Technology_Type; /* ODY01a *//*GBD01b*/
	ED_OCTET GMSK_Power_Class; /* ODY01a *//*GBD01b*/
	ED_OCTET _8PSK_Power_Class; /* ODY01a *//*GBD01b*/

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies {

	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data {
	ED_LOCATOR Access_Technology_Type___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */

	ED_OCTET Access_Technology_Type; /* ODY01a *//*GBD01b*/
	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities *Access_capabilities; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN Access_capabilities_Present;
	ED_OCTET Length; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Length_Present;
	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies Additional_access_technologies;/*GFB09*//*GBD01b*/

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value {

	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value;

/* DEFINITION OF SUB-STRUCTURE c_MsRadioAccessCpblty_MS_RA_capability_value_part */
typedef struct _c_MsRadioAccessCpblty_MS_RA_capability_value_part {

	c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value MS_RA_capability_value;/*GFB09*//*GBD01b*/

} c_MsRadioAccessCpblty_MS_RA_capability_value_part;


/*-A----------------------------------*/
typedef struct _c_MsRadioAccessCpblty {

	c_MsRadioAccessCpblty_MS_RA_capability_value_part MS_RA_capability_value_part;/*GBD01b*/

}	c_MsRadioAccessCpblty;
#define INIT_c_MsRadioAccessCpblty(sp) ED_RESET_MEM ((sp), sizeof (c_MsRadioAccessCpblty))
/*FRK03a*/
void FREE_c_MsRadioAccessCpblty(c_MsRadioAccessCpblty* sp);

/* Access member 'ConfigurationProtocol' of type 'c_ProtocolCfgOpt' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ConfigurationProtocol(var) var

/* Access member 'ConfigurationProtocol' of type 'c_ProtocolCfgOpt' as a pointer */
#define PTR_c_ProtocolCfgOpt_ConfigurationProtocol(var) (&var)

/* Access member 'ProtocolId' of type 'c_ProtocolCfgOpt_ProtocolCfgs_data' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ProtocolCfgs_data_ProtocolId(var) var

/* Access member 'ProtocolId' of type 'c_ProtocolCfgOpt_ProtocolCfgs_data' as a pointer */
#define PTR_c_ProtocolCfgOpt_ProtocolCfgs_data_ProtocolId(var) (&var)

/* Access member 'Length' of type 'c_ProtocolCfgOpt_ProtocolCfgs_data' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ProtocolCfgs_data_Length(var) var

/* Access member 'Length' of type 'c_ProtocolCfgOpt_ProtocolCfgs_data' as a pointer */
#define PTR_c_ProtocolCfgOpt_ProtocolCfgs_data_Length(var) (&var)

/* Access member 'Contents' of type 'c_ProtocolCfgOpt_ProtocolCfgs_data' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ProtocolCfgs_data_Contents(var) var

/* Access member 'Contents' of type 'c_ProtocolCfgOpt_ProtocolCfgs_data' as a pointer */
#define PTR_c_ProtocolCfgOpt_ProtocolCfgs_data_Contents(var) (&var)

/* Access member 'data' of type 'c_ProtocolCfgOpt_ProtocolCfgs' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ProtocolCfgs_data(var) (*var)

/* Access member 'data' of type 'c_ProtocolCfgOpt_ProtocolCfgs' as a pointer */
#define PTR_c_ProtocolCfgOpt_ProtocolCfgs_data(var) var

/* Access member 'ProtocolCfgs' of type 'c_ProtocolCfgOpt' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ProtocolCfgs(var) var

/* Access member 'ProtocolCfgs' of type 'c_ProtocolCfgOpt' as a pointer */
#define PTR_c_ProtocolCfgOpt_ProtocolCfgs(var) (&var)

/* Access member 'ContainerId' of type 'c_ProtocolCfgOpt_ContainerCfgs_data' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ContainerCfgs_data_ContainerId(var) var

/* Access member 'ContainerId' of type 'c_ProtocolCfgOpt_ContainerCfgs_data' as a pointer */
#define PTR_c_ProtocolCfgOpt_ContainerCfgs_data_ContainerId(var) (&var)

/* Access member 'Length' of type 'c_ProtocolCfgOpt_ContainerCfgs_data' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ContainerCfgs_data_Length(var) var

/* Access member 'Length' of type 'c_ProtocolCfgOpt_ContainerCfgs_data' as a pointer */
#define PTR_c_ProtocolCfgOpt_ContainerCfgs_data_Length(var) (&var)

/* Access member 'Contents' of type 'c_ProtocolCfgOpt_ContainerCfgs_data' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ContainerCfgs_data_Contents(var) var

/* Access member 'Contents' of type 'c_ProtocolCfgOpt_ContainerCfgs_data' as a pointer */
#define PTR_c_ProtocolCfgOpt_ContainerCfgs_data_Contents(var) (&var)

/* Access member 'data' of type 'c_ProtocolCfgOpt_ContainerCfgs' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ContainerCfgs_data(var) (*var)

/* Access member 'data' of type 'c_ProtocolCfgOpt_ContainerCfgs' as a pointer */
#define PTR_c_ProtocolCfgOpt_ContainerCfgs_data(var) var

/* Access member 'ContainerCfgs' of type 'c_ProtocolCfgOpt' as a variable reference */
#define VAR_c_ProtocolCfgOpt_ContainerCfgs(var) var

/* Access member 'ContainerCfgs' of type 'c_ProtocolCfgOpt' as a pointer */
#define PTR_c_ProtocolCfgOpt_ContainerCfgs(var) (&var)

/* DEFINITION OF BINARY c_ProtocolCfgOpt_ProtocolCfgs_data_Contents */
typedef struct _c_ProtocolCfgOpt_ProtocolCfgs_data_Contents {
	ED_BYTE* value; /* Variable size; bits needed 64 */
	int usedBits;
} c_ProtocolCfgOpt_ProtocolCfgs_data_Contents;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ProtocolCfgOpt_ProtocolCfgs_data_Contents(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_ProtocolCfgOpt_ProtocolCfgs_data */
typedef struct _c_ProtocolCfgOpt_ProtocolCfgs_data {
	ED_LOCATOR ProtocolId___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */
	ED_LOCATOR Contents___LOCATOR  /*LBD02*/;

	ED_SHORT ProtocolId; /* ODY01a *//*GBD01b*/
	ED_OCTET Length; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt_ProtocolCfgs_data_Contents Contents; /* Static, variable size; bits needed 64 *//*GBD01b*/

} c_ProtocolCfgOpt_ProtocolCfgs_data;

/* DEFINITION OF SUB-STRUCTURE c_ProtocolCfgOpt_ProtocolCfgs */
typedef struct _c_ProtocolCfgOpt_ProtocolCfgs {

	c_ProtocolCfgOpt_ProtocolCfgs_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_ProtocolCfgOpt_ProtocolCfgs;

/* DEFINITION OF BINARY c_ProtocolCfgOpt_ContainerCfgs_data_Contents */
typedef struct _c_ProtocolCfgOpt_ContainerCfgs_data_Contents {
	ED_BYTE* value; /* Variable size; bits needed 64 */
	int usedBits;
} c_ProtocolCfgOpt_ContainerCfgs_data_Contents;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ProtocolCfgOpt_ContainerCfgs_data_Contents(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_ProtocolCfgOpt_ContainerCfgs_data */
typedef struct _c_ProtocolCfgOpt_ContainerCfgs_data {
	ED_LOCATOR ContainerId___LOCATOR; /* QUI2 */
	ED_LOCATOR Length___LOCATOR; /* QUI2 */
	ED_LOCATOR Contents___LOCATOR  /*LBD02*/;

	ED_SHORT ContainerId; /* ODY01a *//*GBD01b*/
	ED_OCTET Length; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt_ContainerCfgs_data_Contents Contents; /* Static, variable size; bits needed 64 *//*GBD01b*/

} c_ProtocolCfgOpt_ContainerCfgs_data;

/* DEFINITION OF SUB-STRUCTURE c_ProtocolCfgOpt_ContainerCfgs */
typedef struct _c_ProtocolCfgOpt_ContainerCfgs {

	c_ProtocolCfgOpt_ContainerCfgs_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_ProtocolCfgOpt_ContainerCfgs;


/*-A----------------------------------*/
typedef struct _c_ProtocolCfgOpt {
	ED_LOCATOR ConfigurationProtocol___LOCATOR; /* QUI2 */

	ED_OCTET ConfigurationProtocol; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt_ProtocolCfgs ProtocolCfgs;/*GFB09*//*GBD01b*/
	c_ProtocolCfgOpt_ContainerCfgs ContainerCfgs;/*GFB09*//*GBD01b*/

}	c_ProtocolCfgOpt;
#define INIT_c_ProtocolCfgOpt(sp) ED_RESET_MEM ((sp), sizeof (c_ProtocolCfgOpt))
/*FRK03a*/
void FREE_c_ProtocolCfgOpt(c_ProtocolCfgOpt* sp);

/* Access member 'Identity' of type 'c_MobileId' as a variable reference */
#define VAR_c_MobileId_Identity(var) (*var)

/* Access member 'Identity' of type 'c_MobileId' as a pointer */
#define PTR_c_MobileId_Identity(var) var

/* Access member 'TMGI' of type 'c_MobileId' as a variable reference */
#define VAR_c_MobileId_TMGI(var) (*var)

/* Access member 'TMGI' of type 'c_MobileId' as a pointer */
#define PTR_c_MobileId_TMGI(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_MobileId_NONE,
	U_c_MobileId_Identity,
	U_c_MobileId_TMGI
} TPRESENT_c_MobileId;

typedef struct _c_MobileId {

		TPRESENT_c_MobileId Present;
		union {
			c_MobileId_Identity *Identity; /* ODY01 *//*GBD01b*/
		
			c_MobileId_TMGI *TMGI; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_MobileId;
#define INIT_c_MobileId(sp) ED_RESET_MEM ((sp), sizeof (c_MobileId))
/*FRK01a*/
void FREE_c_MobileId (c_MobileId* sp);

/* SETPRESENT commands for type 'c_MobileId' */
int GLOB_SETPRESENT_c_MobileId (c_MobileId* sp, TPRESENT_c_MobileId toBeSetPresent);
#define SETPRESENT_c_MobileId_NONE(sp) GLOB_SETPRESENT_c_MobileId(sp, U_c_MobileId_NONE)
#define GETPRESENT_c_MobileId_NONE(sp) ((sp)->Present == U_c_MobileId_NONE)
#define SETPRESENT_c_MobileId_Identity(sp) GLOB_SETPRESENT_c_MobileId(sp, U_c_MobileId_Identity)
#define GETPRESENT_c_MobileId_Identity(sp) ((sp)->Present == U_c_MobileId_Identity)
#define SETPRESENT_c_MobileId_TMGI(sp) GLOB_SETPRESENT_c_MobileId(sp, U_c_MobileId_TMGI)
#define GETPRESENT_c_MobileId_TMGI(sp) ((sp)->Present == U_c_MobileId_TMGI)
#define GETPRESENT_c_MobileId(sp) ((sp)->Present)


/* Access member 'TIValue' of type 'c_LinkedTi' as a variable reference */
#define VAR_c_LinkedTi_TIValue(var) var

/* Access member 'TIValue' of type 'c_LinkedTi' as a pointer */
#define PTR_c_LinkedTi_TIValue(var) (&var)

/* Access member 'TIFlag' of type 'c_LinkedTi' as a variable reference */
#define VAR_c_LinkedTi_TIFlag(var) var

/* Access member 'TIFlag' of type 'c_LinkedTi' as a pointer */
#define PTR_c_LinkedTi_TIFlag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_LinkedTi {
	ED_LOCATOR TIValue___LOCATOR; /* QUI2 */
	ED_LOCATOR TIFlag___LOCATOR; /* QUI2 */

	ED_LONG TIValue; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TIFlag; /* ODY01a *//*GBD01b*/

}	c_LinkedTi;
#define INIT_c_LinkedTi(sp) ED_RESET_MEM ((sp), sizeof (c_LinkedTi))
/*FRK03a*/
void FREE_c_LinkedTi(c_LinkedTi* sp);

/* Access member 'TFTOperationCode' of type 'c_TrafficFlowTemplate' as a variable reference */
#define VAR_c_TrafficFlowTemplate_TFTOperationCode(var) var

/* Access member 'TFTOperationCode' of type 'c_TrafficFlowTemplate' as a pointer */
#define PTR_c_TrafficFlowTemplate_TFTOperationCode(var) (&var)

/* Access member 'PacketFilterId' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data_PacketFilterId(var) var

/* Access member 'PacketFilterId' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data_PacketFilterId(var) (&var)

/* Access member 'PacketFilterDirection' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data_PacketFilterDirection(var) var

/* Access member 'PacketFilterDirection' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data_PacketFilterDirection(var) (&var)

/* Access member 'PacketFilterEvalPrecedence' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data_PacketFilterEvalPrecedence(var) var

/* Access member 'PacketFilterEvalPrecedence' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data_PacketFilterEvalPrecedence(var) (&var)

/* Access member 'ComponentTypeId' of type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentTypeId(var) var

/* Access member 'ComponentTypeId' of type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentTypeId(var) (&var)

/* Access member 'ComponentData' of type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData(var) var

/* Access member 'ComponentData' of type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData(var) (&var)

/* Access member 'data' of type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data(var) (*var)

/* Access member 'data' of type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data(var) var

/* Access member 'FilterContents' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents(var) var

/* Access member 'FilterContents' of type 'c_TrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data_FilterContents(var) (&var)

/* Access member 'data' of type 'c_TrafficFlowTemplate_PacketFilters' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters_data(var) (*var)

/* Access member 'data' of type 'c_TrafficFlowTemplate_PacketFilters' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters_data(var) var

/* Access member 'PacketFilters' of type 'c_TrafficFlowTemplate' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketFilters(var) var

/* Access member 'PacketFilters' of type 'c_TrafficFlowTemplate' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketFilters(var) (&var)

/* Access member 'ParameterId' of type 'c_TrafficFlowTemplate_PacketParameters_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketParameters_data_ParameterId(var) var

/* Access member 'ParameterId' of type 'c_TrafficFlowTemplate_PacketParameters_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketParameters_data_ParameterId(var) (&var)

/* Access member 'Contents' of type 'c_TrafficFlowTemplate_PacketParameters_data' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketParameters_data_Contents(var) var

/* Access member 'Contents' of type 'c_TrafficFlowTemplate_PacketParameters_data' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketParameters_data_Contents(var) (&var)

/* Access member 'data' of type 'c_TrafficFlowTemplate_PacketParameters' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketParameters_data(var) (*var)

/* Access member 'data' of type 'c_TrafficFlowTemplate_PacketParameters' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketParameters_data(var) var

/* Access member 'PacketParameters' of type 'c_TrafficFlowTemplate' as a variable reference */
#define VAR_c_TrafficFlowTemplate_PacketParameters(var) var

/* Access member 'PacketParameters' of type 'c_TrafficFlowTemplate' as a pointer */
#define PTR_c_TrafficFlowTemplate_PacketParameters(var) (&var)

/* DEFINITION OF BINARY c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData */
typedef struct _c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData {
	ED_BYTE* value; /* Variable size; bits needed 256 */
	int usedBits;
} c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data */
typedef struct _c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data {
	ED_LOCATOR ComponentTypeId___LOCATOR; /* QUI2 */
	ED_LOCATOR ComponentData___LOCATOR  /*LBD02*/;

	ED_OCTET ComponentTypeId; /* ODY01a *//*GBD01b*/
	c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData ComponentData; /* Static, variable size; bits needed 256 *//*GBD01b*/

} c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data;

/* DEFINITION OF SUB-STRUCTURE c_TrafficFlowTemplate_PacketFilters_data_FilterContents */
typedef struct _c_TrafficFlowTemplate_PacketFilters_data_FilterContents {

	c_TrafficFlowTemplate_PacketFilters_data_FilterContents_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TrafficFlowTemplate_PacketFilters_data_FilterContents;

/* DEFINITION OF SUB-STRUCTURE c_TrafficFlowTemplate_PacketFilters_data */
typedef struct _c_TrafficFlowTemplate_PacketFilters_data {
	ED_LOCATOR PacketFilterId___LOCATOR; /* QUI2 */
	ED_LOCATOR PacketFilterDirection___LOCATOR; /* QUI2 */
	ED_LOCATOR PacketFilterEvalPrecedence___LOCATOR; /* QUI2 */

	ED_OCTET PacketFilterId; /* ODY01a *//*GBD01b*/
	ED_OCTET PacketFilterDirection; /* ODY01a *//*GBD01b*/
	ED_LONG PacketFilterEvalPrecedence; /* ODY01a *//*GBD01b*/
	c_TrafficFlowTemplate_PacketFilters_data_FilterContents FilterContents;/*GFB09*//*GBD01b*/

} c_TrafficFlowTemplate_PacketFilters_data;

/* DEFINITION OF SUB-STRUCTURE c_TrafficFlowTemplate_PacketFilters */
typedef struct _c_TrafficFlowTemplate_PacketFilters {

	c_TrafficFlowTemplate_PacketFilters_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TrafficFlowTemplate_PacketFilters;

/* DEFINITION OF BINARY c_TrafficFlowTemplate_PacketParameters_data_Contents */
typedef struct _c_TrafficFlowTemplate_PacketParameters_data_Contents {
	ED_BYTE* value; /* Variable size; bits needed 256 */
	int usedBits;
} c_TrafficFlowTemplate_PacketParameters_data_Contents;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_TrafficFlowTemplate_PacketParameters_data_Contents(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_TrafficFlowTemplate_PacketParameters_data */
typedef struct _c_TrafficFlowTemplate_PacketParameters_data {
	ED_LOCATOR ParameterId___LOCATOR; /* QUI2 */
	ED_LOCATOR Contents___LOCATOR  /*LBD02*/;

	ED_LONG ParameterId; /* ODY01a *//*GBD01b*/
	c_TrafficFlowTemplate_PacketParameters_data_Contents Contents; /* Static, variable size; bits needed 256 *//*GBD01b*/

} c_TrafficFlowTemplate_PacketParameters_data;

/* DEFINITION OF SUB-STRUCTURE c_TrafficFlowTemplate_PacketParameters */
typedef struct _c_TrafficFlowTemplate_PacketParameters {

	c_TrafficFlowTemplate_PacketParameters_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_TrafficFlowTemplate_PacketParameters;


/*-A----------------------------------*/
typedef struct _c_TrafficFlowTemplate {
	ED_LOCATOR TFTOperationCode___LOCATOR; /* QUI2 */

	ED_OCTET TFTOperationCode; /* ODY01a *//*GBD01b*/
	c_TrafficFlowTemplate_PacketFilters PacketFilters;/*GFB09*//*GBD01b*/
	c_TrafficFlowTemplate_PacketParameters PacketParameters;/*GFB09*//*GBD01b*/

}	c_TrafficFlowTemplate;
#define INIT_c_TrafficFlowTemplate(sp) ED_RESET_MEM ((sp), sizeof (c_TrafficFlowTemplate))
/*FRK03a*/
void FREE_c_TrafficFlowTemplate(c_TrafficFlowTemplate* sp);

/* Access member 'data' of type 'c_PdpContextStatus' as a variable reference */
#define VAR_c_PdpContextStatus_data(var) var

/* Access member 'data' of type 'c_PdpContextStatus' as a pointer */
#define PTR_c_PdpContextStatus_data(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PdpContextStatus {

		ED_BOOLEAN* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-19596=EDCore::TDMSequence)  */
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_PdpContextStatus;
#define INIT_c_PdpContextStatus(sp) ED_RESET_MEM ((sp), sizeof (c_PdpContextStatus))
/*FRK02b*/
void FREE_c_PdpContextStatus (c_PdpContextStatus* sp);
/* SETITEMS/ADDITEMS commands for type 'c_PdpContextStatus'. */
int SETITEMS_c_PdpContextStatus (c_PdpContextStatus* sequence, int desiredItems);
#define ADDITEMS_c_PdpContextStatus(sequence, itemsToBeAdded) SETITEMS_c_PdpContextStatus (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'TI_Value' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_TI_Flag(var) (&var)

/* Access member 'BcRepeatInd' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_BcRepeatInd(var) var

/* Access member 'BcRepeatInd' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_BcRepeatInd(var) (&var)

/* Access member 'BearerCpblty1' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_BearerCpblty1(var) var

/* Access member 'BearerCpblty1' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_BearerCpblty1(var) (&var)

/* Access member 'BearerCpblty2' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_BearerCpblty2(var) (*var)

/* Access member 'BearerCpblty2' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_BearerCpblty2(var) var

/* Access member 'FacilitySimpleRecallAlignment' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_FacilitySimpleRecallAlignment(var) (*var)

/* Access member 'FacilitySimpleRecallAlignment' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_FacilitySimpleRecallAlignment(var) var

/* Access member 'CallingPartySubAddr' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_CallingPartySubAddr(var) (*var)

/* Access member 'CallingPartySubAddr' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_CallingPartySubAddr(var) var

/* Access member 'CalledPartyBcdNum' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_CalledPartyBcdNum(var) var

/* Access member 'CalledPartyBcdNum' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_CalledPartyBcdNum(var) (&var)

/* Access member 'CalledPartySubAddr' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_CalledPartySubAddr(var) (*var)

/* Access member 'CalledPartySubAddr' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_CalledPartySubAddr(var) var

/* Access member 'LlcRepeatInd' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_LlcRepeatInd(var) var

/* Access member 'LlcRepeatInd' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_LlcRepeatInd(var) (&var)

/* Access member 'LowLayerCpbilityI' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_LowLayerCpbilityI(var) (*var)

/* Access member 'LowLayerCpbilityI' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_LowLayerCpbilityI(var) var

/* Access member 'LowLayerCpbilityIi' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_LowLayerCpbilityIi(var) (*var)

/* Access member 'LowLayerCpbilityIi' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_LowLayerCpbilityIi(var) var

/* Access member 'HlcRepeatInd' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_HlcRepeatInd(var) var

/* Access member 'HlcRepeatInd' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_HlcRepeatInd(var) (&var)

/* Access member 'HighLayerCpbilityI' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_HighLayerCpbilityI(var) (*var)

/* Access member 'HighLayerCpbilityI' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_HighLayerCpbilityI(var) var

/* Access member 'HighLayerCpbilityIi' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_HighLayerCpbilityIi(var) (*var)

/* Access member 'HighLayerCpbilityIi' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_HighLayerCpbilityIi(var) var

/* Access member 'UserUser' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_UserUser(var) var

/* Access member 'SsVer' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_SsVer(var) (*var)

/* Access member 'SsVer' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_SsVer(var) var

/* Access member 'ClirSuppression' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_ClirSuppression(var) var

/* Access member 'ClirSuppression' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_ClirSuppression(var) (&var)

/* Access member 'ClirInvocation' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_ClirInvocation(var) var

/* Access member 'ClirInvocation' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_ClirInvocation(var) (&var)

/* Access member 'CcCapabil' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_CcCapabil(var) (*var)

/* Access member 'CcCapabil' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_CcCapabil(var) var

/* Access member 'FacilityCcbsAdvancedRecallAlignment' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment(var) (*var)

/* Access member 'FacilityCcbsAdvancedRecallAlignment' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment(var) var

/* Access member 'FacilityRecallAlignmentNotEssentialCcbs' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs(var) (*var)

/* Access member 'FacilityRecallAlignmentNotEssentialCcbs' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs(var) var

/* Access member 'StreamId' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_StreamId(var) var

/* Access member 'StreamId' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_StreamId(var) (&var)

/* Access member 'SupportedCodecs' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_SupportedCodecs(var) var

/* Access member 'Redial' of type 'c_SETUP_UP' as a variable reference */
#define VAR_c_SETUP_UP_Redial(var) var

/* Access member 'Redial' of type 'c_SETUP_UP' as a pointer */
#define PTR_c_SETUP_UP_Redial(var) (&var)

/* DEFINITION OF BINARY c_SETUP_UP_FacilitySimpleRecallAlignment */
typedef struct _c_SETUP_UP_FacilitySimpleRecallAlignment {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_SETUP_UP_FacilitySimpleRecallAlignment;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_UP_FacilitySimpleRecallAlignment(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_UP_LowLayerCpbilityI */
typedef struct _c_SETUP_UP_LowLayerCpbilityI {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_SETUP_UP_LowLayerCpbilityI;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_UP_LowLayerCpbilityI(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_UP_LowLayerCpbilityIi */
typedef struct _c_SETUP_UP_LowLayerCpbilityIi {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_SETUP_UP_LowLayerCpbilityIi;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_UP_LowLayerCpbilityIi(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_UP_UserUser */
typedef struct _c_SETUP_UP_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 264 */
	int usedBits;
} c_SETUP_UP_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_UP_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_UP_SsVer */
typedef struct _c_SETUP_UP_SsVer {
	ED_BYTE* value; /* Variable size; bits needed 8 */
	int usedBits;
} c_SETUP_UP_SsVer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_UP_SsVer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment */
typedef struct _c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs */
typedef struct _c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SETUP_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR BcRepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR FacilitySimpleRecallAlignment___LOCATOR  /*LBD01*/;
	ED_LOCATOR LlcRepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR LowLayerCpbilityI___LOCATOR  /*LBD01*/;
	ED_LOCATOR LowLayerCpbilityIi___LOCATOR  /*LBD01*/;
	ED_LOCATOR HlcRepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;
	ED_LOCATOR SsVer___LOCATOR  /*LBD01*/;
	ED_LOCATOR FacilityCcbsAdvancedRecallAlignment___LOCATOR  /*LBD01*/;
	ED_LOCATOR FacilityRecallAlignmentNotEssentialCcbs___LOCATOR  /*LBD01*/;
	ED_LOCATOR StreamId___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET BcRepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN BcRepeatInd_Present;
	c_BearerCpblty BearerCpblty1; /* ODY01a *//*GBD01b*/
	c_BearerCpblty *BearerCpblty2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty2_Present;
	c_SETUP_UP_FacilitySimpleRecallAlignment* FacilitySimpleRecallAlignment; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN FacilitySimpleRecallAlignment_Present;
	c_CallingPartySubaddr *CallingPartySubAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CallingPartySubAddr_Present;
	c_CalledPartyBcdNum CalledPartyBcdNum; /* ODY01a *//*GBD01b*/
	c_CalledPartySubaddr *CalledPartySubAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CalledPartySubAddr_Present;
	ED_OCTET LlcRepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LlcRepeatInd_Present;
	c_SETUP_UP_LowLayerCpbilityI* LowLayerCpbilityI; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN LowLayerCpbilityI_Present;
	c_SETUP_UP_LowLayerCpbilityIi* LowLayerCpbilityIi; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN LowLayerCpbilityIi_Present;
	ED_OCTET HlcRepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HlcRepeatInd_Present;
	c_HighLayerCpbility *HighLayerCpbilityI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HighLayerCpbilityI_Present;
	c_HighLayerCpbility *HighLayerCpbilityIi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HighLayerCpbilityIi_Present;
	c_SETUP_UP_UserUser* UserUser; /* Dynamic, variable size; bits needed 264 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_SETUP_UP_SsVer* SsVer; /* Dynamic, variable size; bits needed 8 ODY02b *//*GBD01b*/
	ED_BOOLEAN SsVer_Present;
	/*GBD01b*/
	ED_BOOLEAN ClirSuppression_Present;
	/*GBD01b*/
	ED_BOOLEAN ClirInvocation_Present;
	c_CallControlCapabil *CcCapabil; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CcCapabil_Present;
	c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment* FacilityCcbsAdvancedRecallAlignment; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN FacilityCcbsAdvancedRecallAlignment_Present;
	c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs* FacilityRecallAlignmentNotEssentialCcbs; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN FacilityRecallAlignmentNotEssentialCcbs_Present;
	ED_OCTET StreamId; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN StreamId_Present;
	c_SupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;
	/*GBD01b*/
	ED_BOOLEAN Redial_Present;

}	c_SETUP_UP;
#define INIT_c_SETUP_UP(sp) ED_RESET_MEM ((sp), sizeof (c_SETUP_UP))
/*FRK03a*/
void FREE_c_SETUP_UP(c_SETUP_UP* sp);
#define SETPRESENT_c_SETUP_UP_BcRepeatInd(sp,present) (((sp)->BcRepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_UP_BcRepeatInd(sp) ((sp)->BcRepeatInd_Present)
int SETPRESENT_c_SETUP_UP_BearerCpblty2 (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_BearerCpblty2(sp) ((sp)->BearerCpblty2_Present)
int SETPRESENT_c_SETUP_UP_FacilitySimpleRecallAlignment (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_FacilitySimpleRecallAlignment(sp) ((sp)->FacilitySimpleRecallAlignment_Present)
int SETPRESENT_c_SETUP_UP_CallingPartySubAddr (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_CallingPartySubAddr(sp) ((sp)->CallingPartySubAddr_Present)
int SETPRESENT_c_SETUP_UP_CalledPartySubAddr (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_CalledPartySubAddr(sp) ((sp)->CalledPartySubAddr_Present)
#define SETPRESENT_c_SETUP_UP_LlcRepeatInd(sp,present) (((sp)->LlcRepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_UP_LlcRepeatInd(sp) ((sp)->LlcRepeatInd_Present)
int SETPRESENT_c_SETUP_UP_LowLayerCpbilityI (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_LowLayerCpbilityI(sp) ((sp)->LowLayerCpbilityI_Present)
int SETPRESENT_c_SETUP_UP_LowLayerCpbilityIi (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_LowLayerCpbilityIi(sp) ((sp)->LowLayerCpbilityIi_Present)
#define SETPRESENT_c_SETUP_UP_HlcRepeatInd(sp,present) (((sp)->HlcRepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_UP_HlcRepeatInd(sp) ((sp)->HlcRepeatInd_Present)
int SETPRESENT_c_SETUP_UP_HighLayerCpbilityI (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_HighLayerCpbilityI(sp) ((sp)->HighLayerCpbilityI_Present)
int SETPRESENT_c_SETUP_UP_HighLayerCpbilityIi (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_HighLayerCpbilityIi(sp) ((sp)->HighLayerCpbilityIi_Present)
int SETPRESENT_c_SETUP_UP_UserUser (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_SETUP_UP_SsVer (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_SsVer(sp) ((sp)->SsVer_Present)
#define SETPRESENT_c_SETUP_UP_ClirSuppression(sp,present) (((sp)->ClirSuppression_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_UP_ClirSuppression(sp) ((sp)->ClirSuppression_Present)
#define SETPRESENT_c_SETUP_UP_ClirInvocation(sp,present) (((sp)->ClirInvocation_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_UP_ClirInvocation(sp) ((sp)->ClirInvocation_Present)
int SETPRESENT_c_SETUP_UP_CcCapabil (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_CcCapabil(sp) ((sp)->CcCapabil_Present)
int SETPRESENT_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_FacilityCcbsAdvancedRecallAlignment(sp) ((sp)->FacilityCcbsAdvancedRecallAlignment_Present)
int SETPRESENT_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_FacilityRecallAlignmentNotEssentialCcbs(sp) ((sp)->FacilityRecallAlignmentNotEssentialCcbs_Present)
#define SETPRESENT_c_SETUP_UP_StreamId(sp,present) (((sp)->StreamId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_UP_StreamId(sp) ((sp)->StreamId_Present)
int SETPRESENT_c_SETUP_UP_SupportedCodecs (c_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_UP_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)
#define SETPRESENT_c_SETUP_UP_Redial(sp,present) (((sp)->Redial_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_UP_Redial(sp) ((sp)->Redial_Present)

/* Access member 'AuthRespParam' of type 'c_AUTHENTICATION_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_RESPONSE_UP_AuthRespParam(var) var

/* Access member 'AuthRespParam' of type 'c_AUTHENTICATION_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_RESPONSE_UP_AuthRespParam(var) (&var)

/* Access member 'AuthRespParamExt' of type 'c_AUTHENTICATION_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt(var) (*var)

/* Access member 'AuthRespParamExt' of type 'c_AUTHENTICATION_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt(var) var

/* DEFINITION OF BINARY c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt */
typedef struct _c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt {
	ED_BYTE* value; /* Variable size; bits needed 96 */
	int usedBits;
} c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_RESPONSE_UP {
	ED_LOCATOR AuthRespParam___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthRespParamExt___LOCATOR  /*LBD01*/;

	ED_LONG AuthRespParam; /* ODY01a *//*GBD01b*/
	c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt* AuthRespParamExt; /* Dynamic, variable size; bits needed 96 ODY02b *//*GBD01b*/
	ED_BOOLEAN AuthRespParamExt_Present;

}	c_AUTHENTICATION_RESPONSE_UP;
#define INIT_c_AUTHENTICATION_RESPONSE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_RESPONSE_UP))
/*FRK03a*/
void FREE_c_AUTHENTICATION_RESPONSE_UP(c_AUTHENTICATION_RESPONSE_UP* sp);
int SETPRESENT_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt (c_AUTHENTICATION_RESPONSE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_RESPONSE_UP_AuthRespParamExt(sp) ((sp)->AuthRespParamExt_Present)

/* Access member 'RejCause' of type 'c_AUTHENTICATION_FAILURE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_FAILURE_UP_RejCause(var) var

/* Access member 'RejCause' of type 'c_AUTHENTICATION_FAILURE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_FAILURE_UP_RejCause(var) (&var)

/* Access member 'AuthFailureParam' of type 'c_AUTHENTICATION_FAILURE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam(var) (*var)

/* Access member 'AuthFailureParam' of type 'c_AUTHENTICATION_FAILURE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam(var) var


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_FAILURE_UP {
	ED_LOCATOR AuthFailureParam___LOCATOR  /*LBD01*/;

	c_RejectCause RejCause; /* ODY01a *//*GBD01b*/
	ED_BYTE* AuthFailureParam; /* Dynamic, fixed size; bits needed: 112 ODY02a *//*GBD01b*/
	ED_BOOLEAN AuthFailureParam_Present;

}	c_AUTHENTICATION_FAILURE_UP;
#define INIT_c_AUTHENTICATION_FAILURE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_FAILURE_UP))
/*FRK03a*/
void FREE_c_AUTHENTICATION_FAILURE_UP(c_AUTHENTICATION_FAILURE_UP* sp);
int SETPRESENT_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam (c_AUTHENTICATION_FAILURE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_FAILURE_UP_AuthFailureParam(sp) ((sp)->AuthFailureParam_Present)

/* Access member 'CiphKeySequenceNum' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a variable reference */
#define VAR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_CiphKeySequenceNum(var) var

/* Access member 'CiphKeySequenceNum' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a pointer */
#define PTR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_CiphKeySequenceNum(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a variable reference */
#define VAR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a pointer */
#define PTR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_SpareHalfOctet(var) (&var)

/* Access member 'MobileStationClassmark' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a variable reference */
#define VAR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_MobileStationClassmark(var) var

/* Access member 'MobileStationClassmark' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a pointer */
#define PTR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_MobileStationClassmark(var) (&var)

/* Access member 'MobileId' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a variable reference */
#define VAR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_MobileId(var) var

/* Access member 'MobileId' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a pointer */
#define PTR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_MobileId(var) (&var)

/* Access member 'LocationAreaId' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a variable reference */
#define VAR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId(var) (*var)

/* Access member 'LocationAreaId' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a pointer */
#define PTR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId(var) var

/* Access member 'DeviceProperties' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a variable reference */
#define VAR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_CM_RE_ESTABLISHMENT_REQUEST_UP' as a pointer */
#define PTR_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties(var) var


/*-A----------------------------------*/
typedef struct _c_CM_RE_ESTABLISHMENT_REQUEST_UP {
	ED_LOCATOR CiphKeySequenceNum___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */

	ED_OCTET CiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_MobileStationClassmark2 MobileStationClassmark; /* ODY01a *//*GBD01b*/
	c_MobileId MobileId; /* ODY01a *//*GBD01b*/
	c_LocationAreaId *LocationAreaId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN LocationAreaId_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;

}	c_CM_RE_ESTABLISHMENT_REQUEST_UP;
#define INIT_c_CM_RE_ESTABLISHMENT_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_CM_RE_ESTABLISHMENT_REQUEST_UP))
/*FRK03a*/
void FREE_c_CM_RE_ESTABLISHMENT_REQUEST_UP(c_CM_RE_ESTABLISHMENT_REQUEST_UP* sp);
int SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId (c_CM_RE_ESTABLISHMENT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_LocationAreaId(sp) ((sp)->LocationAreaId_Present)
int SETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties (c_CM_RE_ESTABLISHMENT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CM_RE_ESTABLISHMENT_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)


/*-A----------------------------------*/
typedef struct _c_CM_SERVICE_ABORT_UP {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_CM_SERVICE_ABORT_UP;
#define INIT_c_CM_SERVICE_ABORT_UP(sp) ED_RESET_MEM ((sp), sizeof (c_CM_SERVICE_ABORT_UP))
/*FRK03a*/
void FREE_c_CM_SERVICE_ABORT_UP(c_CM_SERVICE_ABORT_UP* sp);

/* Access member 'CmServType' of type 'c_CM_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_CM_SERVICE_REQUEST_UP_CmServType(var) var

/* Access member 'CmServType' of type 'c_CM_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_CM_SERVICE_REQUEST_UP_CmServType(var) (&var)

/* Access member 'CiphKeySequenceNum' of type 'c_CM_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_CM_SERVICE_REQUEST_UP_CiphKeySequenceNum(var) var

/* Access member 'CiphKeySequenceNum' of type 'c_CM_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_CM_SERVICE_REQUEST_UP_CiphKeySequenceNum(var) (&var)

/* Access member 'MobileStationClassmark' of type 'c_CM_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_CM_SERVICE_REQUEST_UP_MobileStationClassmark(var) var

/* Access member 'MobileStationClassmark' of type 'c_CM_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_CM_SERVICE_REQUEST_UP_MobileStationClassmark(var) (&var)

/* Access member 'MobileId' of type 'c_CM_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_CM_SERVICE_REQUEST_UP_MobileId(var) var

/* Access member 'MobileId' of type 'c_CM_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_CM_SERVICE_REQUEST_UP_MobileId(var) (&var)

/* Access member 'Priority' of type 'c_CM_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_CM_SERVICE_REQUEST_UP_Priority(var) (*var)

/* Access member 'Priority' of type 'c_CM_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_CM_SERVICE_REQUEST_UP_Priority(var) var

/* Access member 'AdditionalUpdateParameters' of type 'c_CM_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters(var) (*var)

/* Access member 'AdditionalUpdateParameters' of type 'c_CM_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters(var) var

/* Access member 'DeviceProperties' of type 'c_CM_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_CM_SERVICE_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_CM_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_CM_SERVICE_REQUEST_UP_DeviceProperties(var) var


/*-A----------------------------------*/
typedef struct _c_CM_SERVICE_REQUEST_UP {
	ED_LOCATOR CmServType___LOCATOR; /* QUI2 */
	ED_LOCATOR CiphKeySequenceNum___LOCATOR; /* QUI2 */

	ED_OCTET CmServType; /* ODY01a *//*GBD01b*/
	ED_OCTET CiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	c_MobileStationClassmark2 MobileStationClassmark; /* ODY01a *//*GBD01b*/
	c_MobileId MobileId; /* ODY01a *//*GBD01b*/
	c_PriorityLevel *Priority; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Priority_Present;
	c_AdditionalUpdateParameters *AdditionalUpdateParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateParameters_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;

}	c_CM_SERVICE_REQUEST_UP;
#define INIT_c_CM_SERVICE_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_CM_SERVICE_REQUEST_UP))
/*FRK03a*/
void FREE_c_CM_SERVICE_REQUEST_UP(c_CM_SERVICE_REQUEST_UP* sp);
int SETPRESENT_c_CM_SERVICE_REQUEST_UP_Priority (c_CM_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CM_SERVICE_REQUEST_UP_Priority(sp) ((sp)->Priority_Present)
int SETPRESENT_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters (c_CM_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CM_SERVICE_REQUEST_UP_AdditionalUpdateParameters(sp) ((sp)->AdditionalUpdateParameters_Present)
int SETPRESENT_c_CM_SERVICE_REQUEST_UP_DeviceProperties (c_CM_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CM_SERVICE_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)

/* Access member 'MobileId' of type 'c_IDENTITY_RESPONSE_UP' as a variable reference */
#define VAR_c_IDENTITY_RESPONSE_UP_MobileId(var) var

/* Access member 'MobileId' of type 'c_IDENTITY_RESPONSE_UP' as a pointer */
#define PTR_c_IDENTITY_RESPONSE_UP_MobileId(var) (&var)

/* Access member 'PTMSI' of type 'c_IDENTITY_RESPONSE_UP' as a variable reference */
#define VAR_c_IDENTITY_RESPONSE_UP_PTMSI(var) (*var)

/* Access member 'PTMSI' of type 'c_IDENTITY_RESPONSE_UP' as a pointer */
#define PTR_c_IDENTITY_RESPONSE_UP_PTMSI(var) var

/* Access member 'AdditionalOldRoutingAreaIdent' of type 'c_IDENTITY_RESPONSE_UP' as a variable reference */
#define VAR_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent(var) (*var)

/* Access member 'AdditionalOldRoutingAreaIdent' of type 'c_IDENTITY_RESPONSE_UP' as a pointer */
#define PTR_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent(var) var

/* Access member 'PTmsiSign' of type 'c_IDENTITY_RESPONSE_UP' as a variable reference */
#define VAR_c_IDENTITY_RESPONSE_UP_PTmsiSign(var) (*var)

/* Access member 'PTmsiSign' of type 'c_IDENTITY_RESPONSE_UP' as a pointer */
#define PTR_c_IDENTITY_RESPONSE_UP_PTmsiSign(var) var


/*-A----------------------------------*/
typedef struct _c_IDENTITY_RESPONSE_UP {
	ED_LOCATOR PTmsiSign___LOCATOR  /*LBD01*/;

	c_MobileId MobileId; /* ODY01a *//*GBD01b*/
	c_PTMSI_Type *PTMSI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PTMSI_Present;
	c_RoutingAreaIdenti2 *AdditionalOldRoutingAreaIdent; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalOldRoutingAreaIdent_Present;
	ED_BYTE* PTmsiSign; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN PTmsiSign_Present;

}	c_IDENTITY_RESPONSE_UP;
#define INIT_c_IDENTITY_RESPONSE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_IDENTITY_RESPONSE_UP))
/*FRK03a*/
void FREE_c_IDENTITY_RESPONSE_UP(c_IDENTITY_RESPONSE_UP* sp);
int SETPRESENT_c_IDENTITY_RESPONSE_UP_PTMSI (c_IDENTITY_RESPONSE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_IDENTITY_RESPONSE_UP_PTMSI(sp) ((sp)->PTMSI_Present)
int SETPRESENT_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent (c_IDENTITY_RESPONSE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_IDENTITY_RESPONSE_UP_AdditionalOldRoutingAreaIdent(sp) ((sp)->AdditionalOldRoutingAreaIdent_Present)
int SETPRESENT_c_IDENTITY_RESPONSE_UP_PTmsiSign (c_IDENTITY_RESPONSE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_IDENTITY_RESPONSE_UP_PTmsiSign(sp) ((sp)->PTmsiSign_Present)

/* Access member 'MobileStationClassmark' of type 'c_IMSI_DETACH_INDICATION_UP' as a variable reference */
#define VAR_c_IMSI_DETACH_INDICATION_UP_MobileStationClassmark(var) var

/* Access member 'MobileStationClassmark' of type 'c_IMSI_DETACH_INDICATION_UP' as a pointer */
#define PTR_c_IMSI_DETACH_INDICATION_UP_MobileStationClassmark(var) (&var)

/* Access member 'MobileId' of type 'c_IMSI_DETACH_INDICATION_UP' as a variable reference */
#define VAR_c_IMSI_DETACH_INDICATION_UP_MobileId(var) var

/* Access member 'MobileId' of type 'c_IMSI_DETACH_INDICATION_UP' as a pointer */
#define PTR_c_IMSI_DETACH_INDICATION_UP_MobileId(var) (&var)


/*-A----------------------------------*/
typedef struct _c_IMSI_DETACH_INDICATION_UP {

	c_MobileStationClassmark1 MobileStationClassmark; /* ODY01a *//*GBD01b*/
	c_MobileId MobileId; /* ODY01a *//*GBD01b*/

}	c_IMSI_DETACH_INDICATION_UP;
#define INIT_c_IMSI_DETACH_INDICATION_UP(sp) ED_RESET_MEM ((sp), sizeof (c_IMSI_DETACH_INDICATION_UP))
/*FRK03a*/
void FREE_c_IMSI_DETACH_INDICATION_UP(c_IMSI_DETACH_INDICATION_UP* sp);

/* Access member 'LocationUpdatingType' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REQUEST_UP_LocationUpdatingType(var) var

/* Access member 'LocationUpdatingType' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a pointer */
#define PTR_c_LOCATION_UPDATING_REQUEST_UP_LocationUpdatingType(var) (&var)

/* Access member 'CiphKeySequenceNum' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REQUEST_UP_CiphKeySequenceNum(var) var

/* Access member 'CiphKeySequenceNum' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a pointer */
#define PTR_c_LOCATION_UPDATING_REQUEST_UP_CiphKeySequenceNum(var) (&var)

/* Access member 'LocationAreaId' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REQUEST_UP_LocationAreaId(var) var

/* Access member 'LocationAreaId' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a pointer */
#define PTR_c_LOCATION_UPDATING_REQUEST_UP_LocationAreaId(var) (&var)

/* Access member 'MobileStationClassmark' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmark(var) var

/* Access member 'MobileStationClassmark' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a pointer */
#define PTR_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmark(var) (&var)

/* Access member 'MobileId' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REQUEST_UP_MobileId(var) var

/* Access member 'MobileId' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a pointer */
#define PTR_c_LOCATION_UPDATING_REQUEST_UP_MobileId(var) (&var)

/* Access member 'MobileStationClassmarkForUmts' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts(var) (*var)

/* Access member 'MobileStationClassmarkForUmts' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a pointer */
#define PTR_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts(var) var

/* Access member 'AdditionalUpdateParameters' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters(var) (*var)

/* Access member 'AdditionalUpdateParameters' of type 'c_LOCATION_UPDATING_REQUEST_UP' as a pointer */
#define PTR_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters(var) var


/*-A----------------------------------*/
typedef struct _c_LOCATION_UPDATING_REQUEST_UP {
	ED_LOCATOR CiphKeySequenceNum___LOCATOR; /* QUI2 */

	c_LocationUpdatingType LocationUpdatingType; /* ODY01a *//*GBD01b*/
	ED_OCTET CiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	c_LocationAreaId LocationAreaId; /* ODY01a *//*GBD01b*/
	c_MobileStationClassmark1 MobileStationClassmark; /* ODY01a *//*GBD01b*/
	c_MobileId MobileId; /* ODY01a *//*GBD01b*/
	c_MobileStationClassmark2 *MobileStationClassmarkForUmts; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileStationClassmarkForUmts_Present;
	c_AdditionalUpdateParameters *AdditionalUpdateParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateParameters_Present;

}	c_LOCATION_UPDATING_REQUEST_UP;
#define INIT_c_LOCATION_UPDATING_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_LOCATION_UPDATING_REQUEST_UP))
/*FRK03a*/
void FREE_c_LOCATION_UPDATING_REQUEST_UP(c_LOCATION_UPDATING_REQUEST_UP* sp);
int SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts (c_LOCATION_UPDATING_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_MobileStationClassmarkForUmts(sp) ((sp)->MobileStationClassmarkForUmts_Present)
int SETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters (c_LOCATION_UPDATING_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_LOCATION_UPDATING_REQUEST_UP_AdditionalUpdateParameters(sp) ((sp)->AdditionalUpdateParameters_Present)

/* Access member 'RejCause' of type 'c_MM_STATUS' as a variable reference */
#define VAR_c_MM_STATUS_RejCause(var) var

/* Access member 'RejCause' of type 'c_MM_STATUS' as a pointer */
#define PTR_c_MM_STATUS_RejCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_MM_STATUS {

	c_RejectCause RejCause; /* ODY01a *//*GBD01b*/

}	c_MM_STATUS;
#define INIT_c_MM_STATUS(sp) ED_RESET_MEM ((sp), sizeof (c_MM_STATUS))
/*FRK03a*/
void FREE_c_MM_STATUS(c_MM_STATUS* sp);


/*-A----------------------------------*/
typedef struct _c_TMSI_REALLOCATION_COMPLETE_UP {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_TMSI_REALLOCATION_COMPLETE_UP;
#define INIT_c_TMSI_REALLOCATION_COMPLETE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_TMSI_REALLOCATION_COMPLETE_UP))
/*FRK03a*/
void FREE_c_TMSI_REALLOCATION_COMPLETE_UP(c_TMSI_REALLOCATION_COMPLETE_UP* sp);


/*-A----------------------------------*/
typedef struct _c_MM_NULL_UP {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_MM_NULL_UP;
#define INIT_c_MM_NULL_UP(sp) ED_RESET_MEM ((sp), sizeof (c_MM_NULL_UP))
/*FRK03a*/
void FREE_c_MM_NULL_UP(c_MM_NULL_UP* sp);

/* Access member 'TI_Value' of type 'c_ALERTING_UP' as a variable reference */
#define VAR_c_ALERTING_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ALERTING_UP' as a pointer */
#define PTR_c_ALERTING_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ALERTING_UP' as a variable reference */
#define VAR_c_ALERTING_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ALERTING_UP' as a pointer */
#define PTR_c_ALERTING_UP_TI_Flag(var) (&var)

/* Access member 'Facility' of type 'c_ALERTING_UP' as a variable reference */
#define VAR_c_ALERTING_UP_Facility(var) (*var)

/* Access member 'Facility' of type 'c_ALERTING_UP' as a pointer */
#define PTR_c_ALERTING_UP_Facility(var) var

/* Access member 'UserUser' of type 'c_ALERTING_UP' as a variable reference */
#define VAR_c_ALERTING_UP_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_ALERTING_UP' as a pointer */
#define PTR_c_ALERTING_UP_UserUser(var) var

/* Access member 'SsVer' of type 'c_ALERTING_UP' as a variable reference */
#define VAR_c_ALERTING_UP_SsVer(var) (*var)

/* Access member 'SsVer' of type 'c_ALERTING_UP' as a pointer */
#define PTR_c_ALERTING_UP_SsVer(var) var

/* DEFINITION OF BINARY c_ALERTING_UP_Facility */
typedef struct _c_ALERTING_UP_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_ALERTING_UP_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ALERTING_UP_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ALERTING_UP_UserUser */
typedef struct _c_ALERTING_UP_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_ALERTING_UP_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ALERTING_UP_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ALERTING_UP_SsVer */
typedef struct _c_ALERTING_UP_SsVer {
	ED_BYTE* value; /* Variable size; bits needed 8 */
	int usedBits;
} c_ALERTING_UP_SsVer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ALERTING_UP_SsVer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ALERTING_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;
	ED_LOCATOR SsVer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_ALERTING_UP_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_ALERTING_UP_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_ALERTING_UP_SsVer* SsVer; /* Dynamic, variable size; bits needed 8 ODY02b *//*GBD01b*/
	ED_BOOLEAN SsVer_Present;

}	c_ALERTING_UP;
#define INIT_c_ALERTING_UP(sp) ED_RESET_MEM ((sp), sizeof (c_ALERTING_UP))
/*FRK03a*/
void FREE_c_ALERTING_UP(c_ALERTING_UP* sp);
int SETPRESENT_c_ALERTING_UP_Facility (c_ALERTING_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ALERTING_UP_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_ALERTING_UP_UserUser (c_ALERTING_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ALERTING_UP_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_ALERTING_UP_SsVer (c_ALERTING_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ALERTING_UP_SsVer(sp) ((sp)->SsVer_Present)

/* Access member 'TI_Value' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_TI_Flag(var) (&var)

/* Access member 'RepeatInd' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_RepeatInd(var) var

/* Access member 'RepeatInd' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_RepeatInd(var) (&var)

/* Access member 'BearerCpblty1' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_BearerCpblty1(var) (*var)

/* Access member 'BearerCpblty1' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_BearerCpblty1(var) var

/* Access member 'BearerCpblty2' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_BearerCpblty2(var) (*var)

/* Access member 'BearerCpblty2' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_BearerCpblty2(var) var

/* Access member 'Cause' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_Cause(var) (*var)

/* Access member 'Cause' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_Cause(var) var

/* Access member 'CcCapabil' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_CcCapabil(var) (*var)

/* Access member 'CcCapabil' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_CcCapabil(var) var

/* Access member 'StreamId' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_StreamId(var) var

/* Access member 'StreamId' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_StreamId(var) (&var)

/* Access member 'SupportedCodecs' of type 'c_CALL_CONFIRMED_UP' as a variable reference */
#define VAR_c_CALL_CONFIRMED_UP_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_CALL_CONFIRMED_UP' as a pointer */
#define PTR_c_CALL_CONFIRMED_UP_SupportedCodecs(var) var


/*-A----------------------------------*/
typedef struct _c_CALL_CONFIRMED_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR RepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR StreamId___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET RepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RepeatInd_Present;
	c_BearerCpblty *BearerCpblty1; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty1_Present;
	c_BearerCpblty *BearerCpblty2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty2_Present;
	c_Cause *Cause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Cause_Present;
	c_CallControlCapabil *CcCapabil; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CcCapabil_Present;
	ED_OCTET StreamId; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN StreamId_Present;
	c_SupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;

}	c_CALL_CONFIRMED_UP;
#define INIT_c_CALL_CONFIRMED_UP(sp) ED_RESET_MEM ((sp), sizeof (c_CALL_CONFIRMED_UP))
/*FRK03a*/
void FREE_c_CALL_CONFIRMED_UP(c_CALL_CONFIRMED_UP* sp);
#define SETPRESENT_c_CALL_CONFIRMED_UP_RepeatInd(sp,present) (((sp)->RepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CALL_CONFIRMED_UP_RepeatInd(sp) ((sp)->RepeatInd_Present)
int SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty1 (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty1(sp) ((sp)->BearerCpblty1_Present)
int SETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty2 (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_CONFIRMED_UP_BearerCpblty2(sp) ((sp)->BearerCpblty2_Present)
int SETPRESENT_c_CALL_CONFIRMED_UP_Cause (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_CONFIRMED_UP_Cause(sp) ((sp)->Cause_Present)
int SETPRESENT_c_CALL_CONFIRMED_UP_CcCapabil (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_CONFIRMED_UP_CcCapabil(sp) ((sp)->CcCapabil_Present)
#define SETPRESENT_c_CALL_CONFIRMED_UP_StreamId(sp,present) (((sp)->StreamId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CALL_CONFIRMED_UP_StreamId(sp) ((sp)->StreamId_Present)
int SETPRESENT_c_CALL_CONFIRMED_UP_SupportedCodecs (c_CALL_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_CONFIRMED_UP_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)

/* Access member 'TI_Value' of type 'c_CONNECT_UP' as a variable reference */
#define VAR_c_CONNECT_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CONNECT_UP' as a pointer */
#define PTR_c_CONNECT_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CONNECT_UP' as a variable reference */
#define VAR_c_CONNECT_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CONNECT_UP' as a pointer */
#define PTR_c_CONNECT_UP_TI_Flag(var) (&var)

/* Access member 'Facility' of type 'c_CONNECT_UP' as a variable reference */
#define VAR_c_CONNECT_UP_Facility(var) (*var)

/* Access member 'Facility' of type 'c_CONNECT_UP' as a pointer */
#define PTR_c_CONNECT_UP_Facility(var) var

/* Access member 'ConnSubaddr' of type 'c_CONNECT_UP' as a variable reference */
#define VAR_c_CONNECT_UP_ConnSubaddr(var) (*var)

/* Access member 'ConnSubaddr' of type 'c_CONNECT_UP' as a pointer */
#define PTR_c_CONNECT_UP_ConnSubaddr(var) var

/* Access member 'UserUser' of type 'c_CONNECT_UP' as a variable reference */
#define VAR_c_CONNECT_UP_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_CONNECT_UP' as a pointer */
#define PTR_c_CONNECT_UP_UserUser(var) var

/* Access member 'SsVer' of type 'c_CONNECT_UP' as a variable reference */
#define VAR_c_CONNECT_UP_SsVer(var) (*var)

/* Access member 'SsVer' of type 'c_CONNECT_UP' as a pointer */
#define PTR_c_CONNECT_UP_SsVer(var) var

/* Access member 'StreamId' of type 'c_CONNECT_UP' as a variable reference */
#define VAR_c_CONNECT_UP_StreamId(var) var

/* Access member 'StreamId' of type 'c_CONNECT_UP' as a pointer */
#define PTR_c_CONNECT_UP_StreamId(var) (&var)

/* DEFINITION OF BINARY c_CONNECT_UP_Facility */
typedef struct _c_CONNECT_UP_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_CONNECT_UP_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CONNECT_UP_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_CONNECT_UP_UserUser */
typedef struct _c_CONNECT_UP_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_CONNECT_UP_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CONNECT_UP_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_CONNECT_UP_SsVer */
typedef struct _c_CONNECT_UP_SsVer {
	ED_BYTE* value; /* Variable size; bits needed 8 */
	int usedBits;
} c_CONNECT_UP_SsVer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CONNECT_UP_SsVer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_CONNECT_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;
	ED_LOCATOR SsVer___LOCATOR  /*LBD01*/;
	ED_LOCATOR StreamId___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_CONNECT_UP_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_ConnSubaddres *ConnSubaddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ConnSubaddr_Present;
	c_CONNECT_UP_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_CONNECT_UP_SsVer* SsVer; /* Dynamic, variable size; bits needed 8 ODY02b *//*GBD01b*/
	ED_BOOLEAN SsVer_Present;
	ED_OCTET StreamId; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN StreamId_Present;

}	c_CONNECT_UP;
#define INIT_c_CONNECT_UP(sp) ED_RESET_MEM ((sp), sizeof (c_CONNECT_UP))
/*FRK03a*/
void FREE_c_CONNECT_UP(c_CONNECT_UP* sp);
int SETPRESENT_c_CONNECT_UP_Facility (c_CONNECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_UP_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_CONNECT_UP_ConnSubaddr (c_CONNECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_UP_ConnSubaddr(sp) ((sp)->ConnSubaddr_Present)
int SETPRESENT_c_CONNECT_UP_UserUser (c_CONNECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_UP_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_CONNECT_UP_SsVer (c_CONNECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_UP_SsVer(sp) ((sp)->SsVer_Present)
#define SETPRESENT_c_CONNECT_UP_StreamId(sp,present) (((sp)->StreamId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CONNECT_UP_StreamId(sp) ((sp)->StreamId_Present)

/* Access member 'TI_Value' of type 'c_CONNECT_ACKNOWLEDGE' as a variable reference */
#define VAR_c_CONNECT_ACKNOWLEDGE_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CONNECT_ACKNOWLEDGE' as a pointer */
#define PTR_c_CONNECT_ACKNOWLEDGE_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CONNECT_ACKNOWLEDGE' as a variable reference */
#define VAR_c_CONNECT_ACKNOWLEDGE_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CONNECT_ACKNOWLEDGE' as a pointer */
#define PTR_c_CONNECT_ACKNOWLEDGE_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CONNECT_ACKNOWLEDGE {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_CONNECT_ACKNOWLEDGE;
#define INIT_c_CONNECT_ACKNOWLEDGE(sp) ED_RESET_MEM ((sp), sizeof (c_CONNECT_ACKNOWLEDGE))
/*FRK03a*/
void FREE_c_CONNECT_ACKNOWLEDGE(c_CONNECT_ACKNOWLEDGE* sp);

/* Access member 'TI_Value' of type 'c_DISCONNECT_UP' as a variable reference */
#define VAR_c_DISCONNECT_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_DISCONNECT_UP' as a pointer */
#define PTR_c_DISCONNECT_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_DISCONNECT_UP' as a variable reference */
#define VAR_c_DISCONNECT_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_DISCONNECT_UP' as a pointer */
#define PTR_c_DISCONNECT_UP_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_DISCONNECT_UP' as a variable reference */
#define VAR_c_DISCONNECT_UP_Cause(var) var

/* Access member 'Cause' of type 'c_DISCONNECT_UP' as a pointer */
#define PTR_c_DISCONNECT_UP_Cause(var) (&var)

/* Access member 'Facility' of type 'c_DISCONNECT_UP' as a variable reference */
#define VAR_c_DISCONNECT_UP_Facility(var) (*var)

/* Access member 'Facility' of type 'c_DISCONNECT_UP' as a pointer */
#define PTR_c_DISCONNECT_UP_Facility(var) var

/* Access member 'UserUser' of type 'c_DISCONNECT_UP' as a variable reference */
#define VAR_c_DISCONNECT_UP_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_DISCONNECT_UP' as a pointer */
#define PTR_c_DISCONNECT_UP_UserUser(var) var

/* Access member 'SsVer' of type 'c_DISCONNECT_UP' as a variable reference */
#define VAR_c_DISCONNECT_UP_SsVer(var) (*var)

/* Access member 'SsVer' of type 'c_DISCONNECT_UP' as a pointer */
#define PTR_c_DISCONNECT_UP_SsVer(var) var

/* DEFINITION OF BINARY c_DISCONNECT_UP_Facility */
typedef struct _c_DISCONNECT_UP_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_DISCONNECT_UP_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DISCONNECT_UP_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_DISCONNECT_UP_UserUser */
typedef struct _c_DISCONNECT_UP_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_DISCONNECT_UP_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DISCONNECT_UP_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_DISCONNECT_UP_SsVer */
typedef struct _c_DISCONNECT_UP_SsVer {
	ED_BYTE* value; /* Variable size; bits needed 8 */
	int usedBits;
} c_DISCONNECT_UP_SsVer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DISCONNECT_UP_SsVer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DISCONNECT_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;
	ED_LOCATOR SsVer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause Cause; /* ODY01a *//*GBD01b*/
	c_DISCONNECT_UP_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_DISCONNECT_UP_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_DISCONNECT_UP_SsVer* SsVer; /* Dynamic, variable size; bits needed 8 ODY02b *//*GBD01b*/
	ED_BOOLEAN SsVer_Present;

}	c_DISCONNECT_UP;
#define INIT_c_DISCONNECT_UP(sp) ED_RESET_MEM ((sp), sizeof (c_DISCONNECT_UP))
/*FRK03a*/
void FREE_c_DISCONNECT_UP(c_DISCONNECT_UP* sp);
int SETPRESENT_c_DISCONNECT_UP_Facility (c_DISCONNECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DISCONNECT_UP_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_DISCONNECT_UP_UserUser (c_DISCONNECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DISCONNECT_UP_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_DISCONNECT_UP_SsVer (c_DISCONNECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DISCONNECT_UP_SsVer(sp) ((sp)->SsVer_Present)

/* Access member 'TI_Value' of type 'c_EMERGENCY_SETUP_UP' as a variable reference */
#define VAR_c_EMERGENCY_SETUP_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_EMERGENCY_SETUP_UP' as a pointer */
#define PTR_c_EMERGENCY_SETUP_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_EMERGENCY_SETUP_UP' as a variable reference */
#define VAR_c_EMERGENCY_SETUP_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_EMERGENCY_SETUP_UP' as a pointer */
#define PTR_c_EMERGENCY_SETUP_UP_TI_Flag(var) (&var)

/* Access member 'BearerCpblty' of type 'c_EMERGENCY_SETUP_UP' as a variable reference */
#define VAR_c_EMERGENCY_SETUP_UP_BearerCpblty(var) (*var)

/* Access member 'BearerCpblty' of type 'c_EMERGENCY_SETUP_UP' as a pointer */
#define PTR_c_EMERGENCY_SETUP_UP_BearerCpblty(var) var

/* Access member 'StreamId' of type 'c_EMERGENCY_SETUP_UP' as a variable reference */
#define VAR_c_EMERGENCY_SETUP_UP_StreamId(var) var

/* Access member 'StreamId' of type 'c_EMERGENCY_SETUP_UP' as a pointer */
#define PTR_c_EMERGENCY_SETUP_UP_StreamId(var) (&var)

/* Access member 'SupportedCodecs' of type 'c_EMERGENCY_SETUP_UP' as a variable reference */
#define VAR_c_EMERGENCY_SETUP_UP_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_EMERGENCY_SETUP_UP' as a pointer */
#define PTR_c_EMERGENCY_SETUP_UP_SupportedCodecs(var) var

/* Access member 'EmergencyCategory' of type 'c_EMERGENCY_SETUP_UP' as a variable reference */
#define VAR_c_EMERGENCY_SETUP_UP_EmergencyCategory(var) (*var)

/* Access member 'EmergencyCategory' of type 'c_EMERGENCY_SETUP_UP' as a pointer */
#define PTR_c_EMERGENCY_SETUP_UP_EmergencyCategory(var) var


/*-A----------------------------------*/
typedef struct _c_EMERGENCY_SETUP_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR StreamId___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_BearerCpblty *BearerCpblty; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty_Present;
	ED_OCTET StreamId; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN StreamId_Present;
	c_SupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;
	c_ServCategory *EmergencyCategory; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EmergencyCategory_Present;

}	c_EMERGENCY_SETUP_UP;
#define INIT_c_EMERGENCY_SETUP_UP(sp) ED_RESET_MEM ((sp), sizeof (c_EMERGENCY_SETUP_UP))
/*FRK03a*/
void FREE_c_EMERGENCY_SETUP_UP(c_EMERGENCY_SETUP_UP* sp);
int SETPRESENT_c_EMERGENCY_SETUP_UP_BearerCpblty (c_EMERGENCY_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EMERGENCY_SETUP_UP_BearerCpblty(sp) ((sp)->BearerCpblty_Present)
#define SETPRESENT_c_EMERGENCY_SETUP_UP_StreamId(sp,present) (((sp)->StreamId_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_EMERGENCY_SETUP_UP_StreamId(sp) ((sp)->StreamId_Present)
int SETPRESENT_c_EMERGENCY_SETUP_UP_SupportedCodecs (c_EMERGENCY_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EMERGENCY_SETUP_UP_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)
int SETPRESENT_c_EMERGENCY_SETUP_UP_EmergencyCategory (c_EMERGENCY_SETUP_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EMERGENCY_SETUP_UP_EmergencyCategory(sp) ((sp)->EmergencyCategory_Present)

/* Access member 'TI_Value' of type 'c_FACILITY_UP' as a variable reference */
#define VAR_c_FACILITY_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_FACILITY_UP' as a pointer */
#define PTR_c_FACILITY_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_FACILITY_UP' as a variable reference */
#define VAR_c_FACILITY_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_FACILITY_UP' as a pointer */
#define PTR_c_FACILITY_UP_TI_Flag(var) (&var)

/* Access member 'Facility' of type 'c_FACILITY_UP' as a variable reference */
#define VAR_c_FACILITY_UP_Facility(var) var

/* Access member 'Facility' of type 'c_FACILITY_UP' as a pointer */
#define PTR_c_FACILITY_UP_Facility(var) (&var)

/* Access member 'SsVer' of type 'c_FACILITY_UP' as a variable reference */
#define VAR_c_FACILITY_UP_SsVer(var) (*var)

/* Access member 'SsVer' of type 'c_FACILITY_UP' as a pointer */
#define PTR_c_FACILITY_UP_SsVer(var) var

/* DEFINITION OF BINARY c_FACILITY_UP_Facility */
typedef struct _c_FACILITY_UP_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4792 */
	int usedBits;
} c_FACILITY_UP_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_FACILITY_UP_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_FACILITY_UP_SsVer */
typedef struct _c_FACILITY_UP_SsVer {
	ED_BYTE* value; /* Variable size; bits needed 8 */
	int usedBits;
} c_FACILITY_UP_SsVer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_FACILITY_UP_SsVer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_FACILITY_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD02*/;
	ED_LOCATOR SsVer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_FACILITY_UP_Facility Facility; /* Static, variable size; bits needed 4792 *//*GBD01b*/
	c_FACILITY_UP_SsVer* SsVer; /* Dynamic, variable size; bits needed 8 ODY02b *//*GBD01b*/
	ED_BOOLEAN SsVer_Present;

}	c_FACILITY_UP;
#define INIT_c_FACILITY_UP(sp) ED_RESET_MEM ((sp), sizeof (c_FACILITY_UP))
/*FRK03a*/
void FREE_c_FACILITY_UP(c_FACILITY_UP* sp);
int SETPRESENT_c_FACILITY_UP_SsVer (c_FACILITY_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_FACILITY_UP_SsVer(sp) ((sp)->SsVer_Present)

/* Access member 'TI_Value' of type 'c_HOLD_UP' as a variable reference */
#define VAR_c_HOLD_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_HOLD_UP' as a pointer */
#define PTR_c_HOLD_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_HOLD_UP' as a variable reference */
#define VAR_c_HOLD_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_HOLD_UP' as a pointer */
#define PTR_c_HOLD_UP_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_HOLD_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_HOLD_UP;
#define INIT_c_HOLD_UP(sp) ED_RESET_MEM ((sp), sizeof (c_HOLD_UP))
/*FRK03a*/
void FREE_c_HOLD_UP(c_HOLD_UP* sp);

/* Access member 'TI_Value' of type 'c_MODIFY' as a variable reference */
#define VAR_c_MODIFY_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY' as a pointer */
#define PTR_c_MODIFY_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY' as a variable reference */
#define VAR_c_MODIFY_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY' as a pointer */
#define PTR_c_MODIFY_TI_Flag(var) (&var)

/* Access member 'BearerCpblty' of type 'c_MODIFY' as a variable reference */
#define VAR_c_MODIFY_BearerCpblty(var) var

/* Access member 'BearerCpblty' of type 'c_MODIFY' as a pointer */
#define PTR_c_MODIFY_BearerCpblty(var) (&var)

/* Access member 'LowLayerComp' of type 'c_MODIFY' as a variable reference */
#define VAR_c_MODIFY_LowLayerComp(var) (*var)

/* Access member 'LowLayerComp' of type 'c_MODIFY' as a pointer */
#define PTR_c_MODIFY_LowLayerComp(var) var

/* Access member 'HighLayerComp' of type 'c_MODIFY' as a variable reference */
#define VAR_c_MODIFY_HighLayerComp(var) (*var)

/* Access member 'HighLayerComp' of type 'c_MODIFY' as a pointer */
#define PTR_c_MODIFY_HighLayerComp(var) var

/* Access member 'ReverseCallSetupDir' of type 'c_MODIFY' as a variable reference */
#define VAR_c_MODIFY_ReverseCallSetupDir(var) var

/* Access member 'ReverseCallSetupDir' of type 'c_MODIFY' as a pointer */
#define PTR_c_MODIFY_ReverseCallSetupDir(var) (&var)

/* Access member 'ImmediateModifInd' of type 'c_MODIFY' as a variable reference */
#define VAR_c_MODIFY_ImmediateModifInd(var) var

/* Access member 'ImmediateModifInd' of type 'c_MODIFY' as a pointer */
#define PTR_c_MODIFY_ImmediateModifInd(var) (&var)

/* DEFINITION OF BINARY c_MODIFY_LowLayerComp */
typedef struct _c_MODIFY_LowLayerComp {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_MODIFY_LowLayerComp;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_LowLayerComp(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR LowLayerComp___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_BearerCpblty BearerCpblty; /* ODY01a *//*GBD01b*/
	c_MODIFY_LowLayerComp* LowLayerComp; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN LowLayerComp_Present;
	c_HighLayerCpbility *HighLayerComp; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HighLayerComp_Present;
	/*GBD01b*/
	ED_BOOLEAN ReverseCallSetupDir_Present;
	/*GBD01b*/
	ED_BOOLEAN ImmediateModifInd_Present;

}	c_MODIFY;
#define INIT_c_MODIFY(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY))
/*FRK03a*/
void FREE_c_MODIFY(c_MODIFY* sp);
int SETPRESENT_c_MODIFY_LowLayerComp (c_MODIFY* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_LowLayerComp(sp) ((sp)->LowLayerComp_Present)
int SETPRESENT_c_MODIFY_HighLayerComp (c_MODIFY* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_HighLayerComp(sp) ((sp)->HighLayerComp_Present)
#define SETPRESENT_c_MODIFY_ReverseCallSetupDir(sp,present) (((sp)->ReverseCallSetupDir_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MODIFY_ReverseCallSetupDir(sp) ((sp)->ReverseCallSetupDir_Present)
#define SETPRESENT_c_MODIFY_ImmediateModifInd(sp,present) (((sp)->ImmediateModifInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MODIFY_ImmediateModifInd(sp) ((sp)->ImmediateModifInd_Present)

/* Access member 'TI_Value' of type 'c_MODIFY_COMPLETE' as a variable reference */
#define VAR_c_MODIFY_COMPLETE_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY_COMPLETE' as a pointer */
#define PTR_c_MODIFY_COMPLETE_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY_COMPLETE' as a variable reference */
#define VAR_c_MODIFY_COMPLETE_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY_COMPLETE' as a pointer */
#define PTR_c_MODIFY_COMPLETE_TI_Flag(var) (&var)

/* Access member 'BearerCpblty' of type 'c_MODIFY_COMPLETE' as a variable reference */
#define VAR_c_MODIFY_COMPLETE_BearerCpblty(var) var

/* Access member 'BearerCpblty' of type 'c_MODIFY_COMPLETE' as a pointer */
#define PTR_c_MODIFY_COMPLETE_BearerCpblty(var) (&var)

/* Access member 'LowLayerComp' of type 'c_MODIFY_COMPLETE' as a variable reference */
#define VAR_c_MODIFY_COMPLETE_LowLayerComp(var) (*var)

/* Access member 'LowLayerComp' of type 'c_MODIFY_COMPLETE' as a pointer */
#define PTR_c_MODIFY_COMPLETE_LowLayerComp(var) var

/* Access member 'HighLayerComp' of type 'c_MODIFY_COMPLETE' as a variable reference */
#define VAR_c_MODIFY_COMPLETE_HighLayerComp(var) (*var)

/* Access member 'HighLayerComp' of type 'c_MODIFY_COMPLETE' as a pointer */
#define PTR_c_MODIFY_COMPLETE_HighLayerComp(var) var

/* Access member 'ReverseCallSetupDir' of type 'c_MODIFY_COMPLETE' as a variable reference */
#define VAR_c_MODIFY_COMPLETE_ReverseCallSetupDir(var) var

/* Access member 'ReverseCallSetupDir' of type 'c_MODIFY_COMPLETE' as a pointer */
#define PTR_c_MODIFY_COMPLETE_ReverseCallSetupDir(var) (&var)

/* DEFINITION OF BINARY c_MODIFY_COMPLETE_LowLayerComp */
typedef struct _c_MODIFY_COMPLETE_LowLayerComp {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_MODIFY_COMPLETE_LowLayerComp;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_COMPLETE_LowLayerComp(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_COMPLETE {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR LowLayerComp___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_BearerCpblty BearerCpblty; /* ODY01a *//*GBD01b*/
	c_MODIFY_COMPLETE_LowLayerComp* LowLayerComp; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN LowLayerComp_Present;
	c_HighLayerCpbility *HighLayerComp; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HighLayerComp_Present;
	/*GBD01b*/
	ED_BOOLEAN ReverseCallSetupDir_Present;

}	c_MODIFY_COMPLETE;
#define INIT_c_MODIFY_COMPLETE(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_COMPLETE))
/*FRK03a*/
void FREE_c_MODIFY_COMPLETE(c_MODIFY_COMPLETE* sp);
int SETPRESENT_c_MODIFY_COMPLETE_LowLayerComp (c_MODIFY_COMPLETE* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_COMPLETE_LowLayerComp(sp) ((sp)->LowLayerComp_Present)
int SETPRESENT_c_MODIFY_COMPLETE_HighLayerComp (c_MODIFY_COMPLETE* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_COMPLETE_HighLayerComp(sp) ((sp)->HighLayerComp_Present)
#define SETPRESENT_c_MODIFY_COMPLETE_ReverseCallSetupDir(sp,present) (((sp)->ReverseCallSetupDir_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MODIFY_COMPLETE_ReverseCallSetupDir(sp) ((sp)->ReverseCallSetupDir_Present)

/* Access member 'TI_Value' of type 'c_MODIFY_REJECT' as a variable reference */
#define VAR_c_MODIFY_REJECT_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY_REJECT' as a pointer */
#define PTR_c_MODIFY_REJECT_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY_REJECT' as a variable reference */
#define VAR_c_MODIFY_REJECT_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY_REJECT' as a pointer */
#define PTR_c_MODIFY_REJECT_TI_Flag(var) (&var)

/* Access member 'BearerCpblty' of type 'c_MODIFY_REJECT' as a variable reference */
#define VAR_c_MODIFY_REJECT_BearerCpblty(var) var

/* Access member 'BearerCpblty' of type 'c_MODIFY_REJECT' as a pointer */
#define PTR_c_MODIFY_REJECT_BearerCpblty(var) (&var)

/* Access member 'Cause' of type 'c_MODIFY_REJECT' as a variable reference */
#define VAR_c_MODIFY_REJECT_Cause(var) var

/* Access member 'Cause' of type 'c_MODIFY_REJECT' as a pointer */
#define PTR_c_MODIFY_REJECT_Cause(var) (&var)

/* Access member 'LowLayerComp' of type 'c_MODIFY_REJECT' as a variable reference */
#define VAR_c_MODIFY_REJECT_LowLayerComp(var) (*var)

/* Access member 'LowLayerComp' of type 'c_MODIFY_REJECT' as a pointer */
#define PTR_c_MODIFY_REJECT_LowLayerComp(var) var

/* Access member 'HighLayerComp' of type 'c_MODIFY_REJECT' as a variable reference */
#define VAR_c_MODIFY_REJECT_HighLayerComp(var) (*var)

/* Access member 'HighLayerComp' of type 'c_MODIFY_REJECT' as a pointer */
#define PTR_c_MODIFY_REJECT_HighLayerComp(var) var

/* DEFINITION OF BINARY c_MODIFY_REJECT_LowLayerComp */
typedef struct _c_MODIFY_REJECT_LowLayerComp {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_MODIFY_REJECT_LowLayerComp;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_REJECT_LowLayerComp(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_REJECT {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR LowLayerComp___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_BearerCpblty BearerCpblty; /* ODY01a *//*GBD01b*/
	c_Cause Cause; /* ODY01a *//*GBD01b*/
	c_MODIFY_REJECT_LowLayerComp* LowLayerComp; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN LowLayerComp_Present;
	c_HighLayerCpbility *HighLayerComp; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HighLayerComp_Present;

}	c_MODIFY_REJECT;
#define INIT_c_MODIFY_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_REJECT))
/*FRK03a*/
void FREE_c_MODIFY_REJECT(c_MODIFY_REJECT* sp);
int SETPRESENT_c_MODIFY_REJECT_LowLayerComp (c_MODIFY_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_REJECT_LowLayerComp(sp) ((sp)->LowLayerComp_Present)
int SETPRESENT_c_MODIFY_REJECT_HighLayerComp (c_MODIFY_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_REJECT_HighLayerComp(sp) ((sp)->HighLayerComp_Present)

/* Access member 'TI_Value' of type 'c_NOTIFY' as a variable reference */
#define VAR_c_NOTIFY_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_NOTIFY' as a pointer */
#define PTR_c_NOTIFY_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_NOTIFY' as a variable reference */
#define VAR_c_NOTIFY_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_NOTIFY' as a pointer */
#define PTR_c_NOTIFY_TI_Flag(var) (&var)

/* Access member 'NotifInd' of type 'c_NOTIFY' as a variable reference */
#define VAR_c_NOTIFY_NotifInd(var) var

/* Access member 'NotifInd' of type 'c_NOTIFY' as a pointer */
#define PTR_c_NOTIFY_NotifInd(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NOTIFY {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_NotifInd NotifInd; /* ODY01a *//*GBD01b*/

}	c_NOTIFY;
#define INIT_c_NOTIFY(sp) ED_RESET_MEM ((sp), sizeof (c_NOTIFY))
/*FRK03a*/
void FREE_c_NOTIFY(c_NOTIFY* sp);

/* Access member 'TI_Value' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_CONFIRMED_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_CONFIRMED_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_CONFIRMED_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_CONFIRMED_UP_TI_Flag(var) (&var)

/* Access member 'RepeatInd' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_CONFIRMED_UP_RepeatInd(var) var

/* Access member 'RepeatInd' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_CONFIRMED_UP_RepeatInd(var) (&var)

/* Access member 'BearerCpblty1' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty1(var) var

/* Access member 'BearerCpblty1' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty1(var) (&var)

/* Access member 'BearerCpblty2' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2(var) (*var)

/* Access member 'BearerCpblty2' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2(var) var

/* Access member 'Cause' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause(var) (*var)

/* Access member 'Cause' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause(var) var

/* Access member 'SupportedCodecs' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_CC_ESTABLISHMENT_CONFIRMED_UP' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs(var) var


/*-A----------------------------------*/
typedef struct _c_CC_ESTABLISHMENT_CONFIRMED_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR RepeatInd___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET RepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RepeatInd_Present;
	c_BearerCpblty BearerCpblty1; /* ODY01a *//*GBD01b*/
	c_BearerCpblty *BearerCpblty2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty2_Present;
	c_Cause *Cause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Cause_Present;
	c_SupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;

}	c_CC_ESTABLISHMENT_CONFIRMED_UP;
#define INIT_c_CC_ESTABLISHMENT_CONFIRMED_UP(sp) ED_RESET_MEM ((sp), sizeof (c_CC_ESTABLISHMENT_CONFIRMED_UP))
/*FRK03a*/
void FREE_c_CC_ESTABLISHMENT_CONFIRMED_UP(c_CC_ESTABLISHMENT_CONFIRMED_UP* sp);
#define SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_RepeatInd(sp,present) (((sp)->RepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_RepeatInd(sp) ((sp)->RepeatInd_Present)
int SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2 (c_CC_ESTABLISHMENT_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_BearerCpblty2(sp) ((sp)->BearerCpblty2_Present)
int SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause (c_CC_ESTABLISHMENT_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_Cause(sp) ((sp)->Cause_Present)
int SETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs (c_CC_ESTABLISHMENT_CONFIRMED_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CC_ESTABLISHMENT_CONFIRMED_UP_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)

/* Access member 'TI_Value' of type 'c_RELEASE_UP' as a variable reference */
#define VAR_c_RELEASE_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RELEASE_UP' as a pointer */
#define PTR_c_RELEASE_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RELEASE_UP' as a variable reference */
#define VAR_c_RELEASE_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RELEASE_UP' as a pointer */
#define PTR_c_RELEASE_UP_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_RELEASE_UP' as a variable reference */
#define VAR_c_RELEASE_UP_Cause(var) (*var)

/* Access member 'Cause' of type 'c_RELEASE_UP' as a pointer */
#define PTR_c_RELEASE_UP_Cause(var) var

/* Access member 'SecondCause' of type 'c_RELEASE_UP' as a variable reference */
#define VAR_c_RELEASE_UP_SecondCause(var) (*var)

/* Access member 'SecondCause' of type 'c_RELEASE_UP' as a pointer */
#define PTR_c_RELEASE_UP_SecondCause(var) var

/* Access member 'Facility' of type 'c_RELEASE_UP' as a variable reference */
#define VAR_c_RELEASE_UP_Facility(var) (*var)

/* Access member 'Facility' of type 'c_RELEASE_UP' as a pointer */
#define PTR_c_RELEASE_UP_Facility(var) var

/* Access member 'UserUser' of type 'c_RELEASE_UP' as a variable reference */
#define VAR_c_RELEASE_UP_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_RELEASE_UP' as a pointer */
#define PTR_c_RELEASE_UP_UserUser(var) var

/* Access member 'SsVer' of type 'c_RELEASE_UP' as a variable reference */
#define VAR_c_RELEASE_UP_SsVer(var) (*var)

/* Access member 'SsVer' of type 'c_RELEASE_UP' as a pointer */
#define PTR_c_RELEASE_UP_SsVer(var) var

/* DEFINITION OF BINARY c_RELEASE_UP_Facility */
typedef struct _c_RELEASE_UP_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_RELEASE_UP_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_UP_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_RELEASE_UP_UserUser */
typedef struct _c_RELEASE_UP_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_RELEASE_UP_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_UP_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_RELEASE_UP_SsVer */
typedef struct _c_RELEASE_UP_SsVer {
	ED_BYTE* value; /* Variable size; bits needed 8 */
	int usedBits;
} c_RELEASE_UP_SsVer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_UP_SsVer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_RELEASE_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;
	ED_LOCATOR SsVer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause *Cause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Cause_Present;
	c_Cause *SecondCause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SecondCause_Present;
	c_RELEASE_UP_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_RELEASE_UP_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_RELEASE_UP_SsVer* SsVer; /* Dynamic, variable size; bits needed 8 ODY02b *//*GBD01b*/
	ED_BOOLEAN SsVer_Present;

}	c_RELEASE_UP;
#define INIT_c_RELEASE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_RELEASE_UP))
/*FRK03a*/
void FREE_c_RELEASE_UP(c_RELEASE_UP* sp);
int SETPRESENT_c_RELEASE_UP_Cause (c_RELEASE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_UP_Cause(sp) ((sp)->Cause_Present)
int SETPRESENT_c_RELEASE_UP_SecondCause (c_RELEASE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_UP_SecondCause(sp) ((sp)->SecondCause_Present)
int SETPRESENT_c_RELEASE_UP_Facility (c_RELEASE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_UP_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_RELEASE_UP_UserUser (c_RELEASE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_UP_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_RELEASE_UP_SsVer (c_RELEASE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_UP_SsVer(sp) ((sp)->SsVer_Present)

/* Access member 'TI_Value' of type 'c_RELEASE_COMPLETE_UP' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RELEASE_COMPLETE_UP' as a pointer */
#define PTR_c_RELEASE_COMPLETE_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RELEASE_COMPLETE_UP' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RELEASE_COMPLETE_UP' as a pointer */
#define PTR_c_RELEASE_COMPLETE_UP_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_RELEASE_COMPLETE_UP' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_UP_Cause(var) (*var)

/* Access member 'Cause' of type 'c_RELEASE_COMPLETE_UP' as a pointer */
#define PTR_c_RELEASE_COMPLETE_UP_Cause(var) var

/* Access member 'Facility' of type 'c_RELEASE_COMPLETE_UP' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_UP_Facility(var) (*var)

/* Access member 'Facility' of type 'c_RELEASE_COMPLETE_UP' as a pointer */
#define PTR_c_RELEASE_COMPLETE_UP_Facility(var) var

/* Access member 'UserUser' of type 'c_RELEASE_COMPLETE_UP' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_UP_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_RELEASE_COMPLETE_UP' as a pointer */
#define PTR_c_RELEASE_COMPLETE_UP_UserUser(var) var

/* Access member 'SsVer' of type 'c_RELEASE_COMPLETE_UP' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_UP_SsVer(var) (*var)

/* Access member 'SsVer' of type 'c_RELEASE_COMPLETE_UP' as a pointer */
#define PTR_c_RELEASE_COMPLETE_UP_SsVer(var) var

/* DEFINITION OF BINARY c_RELEASE_COMPLETE_UP_Facility */
typedef struct _c_RELEASE_COMPLETE_UP_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_RELEASE_COMPLETE_UP_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_COMPLETE_UP_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_RELEASE_COMPLETE_UP_UserUser */
typedef struct _c_RELEASE_COMPLETE_UP_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_RELEASE_COMPLETE_UP_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_COMPLETE_UP_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_RELEASE_COMPLETE_UP_SsVer */
typedef struct _c_RELEASE_COMPLETE_UP_SsVer {
	ED_BYTE* value; /* Variable size; bits needed 8 */
	int usedBits;
} c_RELEASE_COMPLETE_UP_SsVer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_COMPLETE_UP_SsVer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_RELEASE_COMPLETE_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;
	ED_LOCATOR SsVer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause *Cause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Cause_Present;
	c_RELEASE_COMPLETE_UP_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_RELEASE_COMPLETE_UP_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_RELEASE_COMPLETE_UP_SsVer* SsVer; /* Dynamic, variable size; bits needed 8 ODY02b *//*GBD01b*/
	ED_BOOLEAN SsVer_Present;

}	c_RELEASE_COMPLETE_UP;
#define INIT_c_RELEASE_COMPLETE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_RELEASE_COMPLETE_UP))
/*FRK03a*/
void FREE_c_RELEASE_COMPLETE_UP(c_RELEASE_COMPLETE_UP* sp);
int SETPRESENT_c_RELEASE_COMPLETE_UP_Cause (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_COMPLETE_UP_Cause(sp) ((sp)->Cause_Present)
int SETPRESENT_c_RELEASE_COMPLETE_UP_Facility (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_COMPLETE_UP_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_RELEASE_COMPLETE_UP_UserUser (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_COMPLETE_UP_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_RELEASE_COMPLETE_UP_SsVer (c_RELEASE_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_COMPLETE_UP_SsVer(sp) ((sp)->SsVer_Present)

/* Access member 'TI_Value' of type 'c_RETRIEVE_UP' as a variable reference */
#define VAR_c_RETRIEVE_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RETRIEVE_UP' as a pointer */
#define PTR_c_RETRIEVE_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RETRIEVE_UP' as a variable reference */
#define VAR_c_RETRIEVE_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RETRIEVE_UP' as a pointer */
#define PTR_c_RETRIEVE_UP_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RETRIEVE_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_RETRIEVE_UP;
#define INIT_c_RETRIEVE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_RETRIEVE_UP))
/*FRK03a*/
void FREE_c_RETRIEVE_UP(c_RETRIEVE_UP* sp);

/* Access member 'TI_Value' of type 'c_START_CC_UP' as a variable reference */
#define VAR_c_START_CC_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_START_CC_UP' as a pointer */
#define PTR_c_START_CC_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_START_CC_UP' as a variable reference */
#define VAR_c_START_CC_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_START_CC_UP' as a pointer */
#define PTR_c_START_CC_UP_TI_Flag(var) (&var)

/* Access member 'CcCapabil' of type 'c_START_CC_UP' as a variable reference */
#define VAR_c_START_CC_UP_CcCapabil(var) (*var)

/* Access member 'CcCapabil' of type 'c_START_CC_UP' as a pointer */
#define PTR_c_START_CC_UP_CcCapabil(var) var


/*-A----------------------------------*/
typedef struct _c_START_CC_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_CallControlCapabil *CcCapabil; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CcCapabil_Present;

}	c_START_CC_UP;
#define INIT_c_START_CC_UP(sp) ED_RESET_MEM ((sp), sizeof (c_START_CC_UP))
/*FRK03a*/
void FREE_c_START_CC_UP(c_START_CC_UP* sp);
int SETPRESENT_c_START_CC_UP_CcCapabil (c_START_CC_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_START_CC_UP_CcCapabil(sp) ((sp)->CcCapabil_Present)

/* Access member 'TI_Value' of type 'c_START_DTMF_UP' as a variable reference */
#define VAR_c_START_DTMF_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_START_DTMF_UP' as a pointer */
#define PTR_c_START_DTMF_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_START_DTMF_UP' as a variable reference */
#define VAR_c_START_DTMF_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_START_DTMF_UP' as a pointer */
#define PTR_c_START_DTMF_UP_TI_Flag(var) (&var)

/* Access member 'KeypadFacility' of type 'c_START_DTMF_UP' as a variable reference */
#define VAR_c_START_DTMF_UP_KeypadFacility(var) var

/* Access member 'KeypadFacility' of type 'c_START_DTMF_UP' as a pointer */
#define PTR_c_START_DTMF_UP_KeypadFacility(var) (&var)


/*-A----------------------------------*/
typedef struct _c_START_DTMF_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_KeypadFacility KeypadFacility; /* ODY01a *//*GBD01b*/

}	c_START_DTMF_UP;
#define INIT_c_START_DTMF_UP(sp) ED_RESET_MEM ((sp), sizeof (c_START_DTMF_UP))
/*FRK03a*/
void FREE_c_START_DTMF_UP(c_START_DTMF_UP* sp);

/* Access member 'TI_Value' of type 'c_STATUS' as a variable reference */
#define VAR_c_STATUS_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_STATUS' as a pointer */
#define PTR_c_STATUS_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_STATUS' as a variable reference */
#define VAR_c_STATUS_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_STATUS' as a pointer */
#define PTR_c_STATUS_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_STATUS' as a variable reference */
#define VAR_c_STATUS_Cause(var) var

/* Access member 'Cause' of type 'c_STATUS' as a pointer */
#define PTR_c_STATUS_Cause(var) (&var)

/* Access member 'CallState' of type 'c_STATUS' as a variable reference */
#define VAR_c_STATUS_CallState(var) var

/* Access member 'CallState' of type 'c_STATUS' as a pointer */
#define PTR_c_STATUS_CallState(var) (&var)

/* Access member 'AuxiliaryStates' of type 'c_STATUS' as a variable reference */
#define VAR_c_STATUS_AuxiliaryStates(var) (*var)

/* Access member 'AuxiliaryStates' of type 'c_STATUS' as a pointer */
#define PTR_c_STATUS_AuxiliaryStates(var) var


/*-A----------------------------------*/
typedef struct _c_STATUS {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause Cause; /* ODY01a *//*GBD01b*/
	c_CallState CallState; /* ODY01a *//*GBD01b*/
	c_AuxiliaryStates *AuxiliaryStates; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AuxiliaryStates_Present;

}	c_STATUS;
#define INIT_c_STATUS(sp) ED_RESET_MEM ((sp), sizeof (c_STATUS))
/*FRK03a*/
void FREE_c_STATUS(c_STATUS* sp);
int SETPRESENT_c_STATUS_AuxiliaryStates (c_STATUS* sp, ED_BOOLEAN present);
#define GETPRESENT_c_STATUS_AuxiliaryStates(sp) ((sp)->AuxiliaryStates_Present)

/* Access member 'TI_Value' of type 'c_STATUS_ENQUIRY' as a variable reference */
#define VAR_c_STATUS_ENQUIRY_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_STATUS_ENQUIRY' as a pointer */
#define PTR_c_STATUS_ENQUIRY_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_STATUS_ENQUIRY' as a variable reference */
#define VAR_c_STATUS_ENQUIRY_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_STATUS_ENQUIRY' as a pointer */
#define PTR_c_STATUS_ENQUIRY_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_STATUS_ENQUIRY {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_STATUS_ENQUIRY;
#define INIT_c_STATUS_ENQUIRY(sp) ED_RESET_MEM ((sp), sizeof (c_STATUS_ENQUIRY))
/*FRK03a*/
void FREE_c_STATUS_ENQUIRY(c_STATUS_ENQUIRY* sp);

/* Access member 'TI_Value' of type 'c_STOP_DTMF_UP' as a variable reference */
#define VAR_c_STOP_DTMF_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_STOP_DTMF_UP' as a pointer */
#define PTR_c_STOP_DTMF_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_STOP_DTMF_UP' as a variable reference */
#define VAR_c_STOP_DTMF_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_STOP_DTMF_UP' as a pointer */
#define PTR_c_STOP_DTMF_UP_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_STOP_DTMF_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_STOP_DTMF_UP;
#define INIT_c_STOP_DTMF_UP(sp) ED_RESET_MEM ((sp), sizeof (c_STOP_DTMF_UP))
/*FRK03a*/
void FREE_c_STOP_DTMF_UP(c_STOP_DTMF_UP* sp);

/* Access member 'TI_Value' of type 'c_USER_INFORMATION' as a variable reference */
#define VAR_c_USER_INFORMATION_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_USER_INFORMATION' as a pointer */
#define PTR_c_USER_INFORMATION_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_USER_INFORMATION' as a variable reference */
#define VAR_c_USER_INFORMATION_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_USER_INFORMATION' as a pointer */
#define PTR_c_USER_INFORMATION_TI_Flag(var) (&var)

/* Access member 'UserUser' of type 'c_USER_INFORMATION' as a variable reference */
#define VAR_c_USER_INFORMATION_UserUser(var) var

/* Access member 'UserUser' of type 'c_USER_INFORMATION' as a pointer */
#define PTR_c_USER_INFORMATION_UserUser(var) (&var)

/* Access member 'MoreData' of type 'c_USER_INFORMATION' as a variable reference */
#define VAR_c_USER_INFORMATION_MoreData(var) var

/* Access member 'MoreData' of type 'c_USER_INFORMATION' as a pointer */
#define PTR_c_USER_INFORMATION_MoreData(var) (&var)

/* DEFINITION OF BINARY c_USER_INFORMATION_UserUser */
typedef struct _c_USER_INFORMATION_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1040 */
	int usedBits;
} c_USER_INFORMATION_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_USER_INFORMATION_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_USER_INFORMATION {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR UserUser___LOCATOR  /*LBD02*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_USER_INFORMATION_UserUser UserUser; /* Static, variable size; bits needed 1040 *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN MoreData_Present;

}	c_USER_INFORMATION;
#define INIT_c_USER_INFORMATION(sp) ED_RESET_MEM ((sp), sizeof (c_USER_INFORMATION))
/*FRK03a*/
void FREE_c_USER_INFORMATION(c_USER_INFORMATION* sp);
#define SETPRESENT_c_USER_INFORMATION_MoreData(sp,present) (((sp)->MoreData_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_USER_INFORMATION_MoreData(sp) ((sp)->MoreData_Present)

/* Access member 'MsNetwkCpblty' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_MsNetwkCpblty(var) var

/* Access member 'MsNetwkCpblty' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_MsNetwkCpblty(var) (&var)

/* Access member 'AttachType' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_AttachType(var) var

/* Access member 'AttachType' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_AttachType(var) (&var)

/* Access member 'GprsCiphKeySequenceNum' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_GprsCiphKeySequenceNum(var) var

/* Access member 'GprsCiphKeySequenceNum' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_GprsCiphKeySequenceNum(var) (&var)

/* Access member 'DrxParam' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_DrxParam(var) var

/* Access member 'DrxParam' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_DrxParam(var) (&var)

/* Access member 'MobileIdentity' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_MobileIdentity(var) var

/* Access member 'MobileIdentity' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_MobileIdentity(var) (&var)

/* Access member 'OldRoutingAreaId' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_OldRoutingAreaId(var) var

/* Access member 'OldRoutingAreaId' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_OldRoutingAreaId(var) (&var)

/* Access member 'MsRadioAccessCpblty' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_MsRadioAccessCpblty(var) var

/* Access member 'MsRadioAccessCpblty' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_MsRadioAccessCpblty(var) (&var)

/* Access member 'OldPTmsiSign' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_OldPTmsiSign(var) (*var)

/* Access member 'OldPTmsiSign' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_OldPTmsiSign(var) var

/* Access member 'ReqRdyTimerValue' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_ReqRdyTimerValue(var) (*var)

/* Access member 'ReqRdyTimerValue' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_ReqRdyTimerValue(var) var

/* Access member 'TmsiStatus' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_TmsiStatus(var) (*var)

/* Access member 'TmsiStatus' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_TmsiStatus(var) var

/* Access member 'PSLCSCapability' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_PSLCSCapability(var) (*var)

/* Access member 'PSLCSCapability' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_PSLCSCapability(var) var

/* Access member 'MobileStationClassmark2' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_MobileStationClassmark2(var) (*var)

/* Access member 'MobileStationClassmark2' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_MobileStationClassmark2(var) var

/* Access member 'MobileStationClassmark3' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_MobileStationClassmark3(var) (*var)

/* Access member 'MobileStationClassmark3' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_MobileStationClassmark3(var) var

/* Access member 'SupportedCodecs' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_SupportedCodecs(var) var

/* Access member 'UENetworkCapability' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_UENetworkCapability(var) (*var)

/* Access member 'UENetworkCapability' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_UENetworkCapability(var) var

/* Access member 'AdditionalMobileIdentity' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity(var) (*var)

/* Access member 'AdditionalMobileIdentity' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity(var) var

/* Access member 'AdditionalOldRoutingAreaId' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId(var) (*var)

/* Access member 'AdditionalOldRoutingAreaId' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId(var) var

/* Access member 'VoiceDomainPrefUEUsageSetting' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting(var) (*var)

/* Access member 'VoiceDomainPrefUEUsageSetting' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting(var) var

/* Access member 'DeviceProperties' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_DeviceProperties(var) var

/* Access member 'PTMSI' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_PTMSI(var) (*var)

/* Access member 'PTMSI' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_PTMSI(var) var

/* Access member 'MSNetworkFeatureSupport' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport(var) (*var)

/* Access member 'MSNetworkFeatureSupport' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport(var) var

/* Access member 'OldLocationAreaIdentification' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification(var) (*var)

/* Access member 'OldLocationAreaIdentification' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification(var) var

/* Access member 'AdditionalUpdateType' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_AdditionalUpdateType(var) (*var)

/* Access member 'AdditionalUpdateType' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_AdditionalUpdateType(var) var

/* Access member 'TMSIBasedNRIContainer' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer(var) (*var)

/* Access member 'TMSIBasedNRIContainer' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer(var) var

/* Access member 'T3324Value' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_T3324Value(var) (*var)

/* Access member 'T3324Value' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_T3324Value(var) var

/* Access member 'T3312ExtendedValue' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_T3312ExtendedValue(var) (*var)

/* Access member 'T3312ExtendedValue' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_T3312ExtendedValue(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_REQUEST_UP' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UP_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_REQUEST_UP' as a pointer */
#define PTR_c_ATTACH_REQUEST_UP_ExtendedDRXParameters(var) var

/* DEFINITION OF BINARY c_ATTACH_REQUEST_UP_UENetworkCapability */
typedef struct _c_ATTACH_REQUEST_UP_UENetworkCapability {
	ED_BYTE* value; /* Variable size; bits needed 104 */
	int usedBits;
} c_ATTACH_REQUEST_UP_UENetworkCapability;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ATTACH_REQUEST_UP_UENetworkCapability(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ATTACH_REQUEST_UP {
	ED_LOCATOR GprsCiphKeySequenceNum___LOCATOR; /* QUI2 */
	ED_LOCATOR OldPTmsiSign___LOCATOR  /*LBD01*/;
	ED_LOCATOR UENetworkCapability___LOCATOR  /*LBD01*/;
	ED_LOCATOR OldLocationAreaIdentification___LOCATOR  /*LBD01*/;

	c_MsNetwkCpblty MsNetwkCpblty; /* ODY01a *//*GBD01b*/
	c_AttachType AttachType; /* ODY01a *//*GBD01b*/
	ED_OCTET GprsCiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	c_DrxParam DrxParam; /* ODY01a *//*GBD01b*/
	c_MobileId MobileIdentity; /* ODY01a *//*GBD01b*/
	c_RoutingAreaIdenti OldRoutingAreaId; /* ODY01a *//*GBD01b*/
	c_MsRadioAccessCpblty MsRadioAccessCpblty; /* ODY01a *//*GBD01b*/
	ED_BYTE* OldPTmsiSign; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN OldPTmsiSign_Present;
	c_GprsTimer *ReqRdyTimerValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReqRdyTimerValue_Present;
	c_TmsiStatus *TmsiStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TmsiStatus_Present;
	c_PSLCSCapabilit *PSLCSCapability; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PSLCSCapability_Present;
	c_MobileStationClassmark2 *MobileStationClassmark2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileStationClassmark2_Present;
	c_Classmark3Value *MobileStationClassmark3; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileStationClassmark3_Present;
	c_SupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;
	c_ATTACH_REQUEST_UP_UENetworkCapability* UENetworkCapability; /* Dynamic, variable size; bits needed 104 ODY02b *//*GBD01b*/
	ED_BOOLEAN UENetworkCapability_Present;
	c_MobileId *AdditionalMobileIdentity; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalMobileIdentity_Present;
	c_RoutingAreaIdenti2 *AdditionalOldRoutingAreaId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalOldRoutingAreaId_Present;
	c_VoiceDomainPreferenceAndUEsUsageSetting *VoiceDomainPrefUEUsageSetting; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN VoiceDomainPrefUEUsageSetting_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_PTMSI_Type *PTMSI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PTMSI_Present;
	c_MSNetworkFeatureSupport *MSNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSNetworkFeatureSupport_Present;
	ED_BYTE* OldLocationAreaIdentification; /* Dynamic, fixed size; bits needed: 40 ODY02a *//*GBD01b*/
	ED_BOOLEAN OldLocationAreaIdentification_Present;
	c_AdditionalUpdateType *AdditionalUpdateType; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateType_Present;
	c_NetworkResourceIdContainer *TMSIBasedNRIContainer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TMSIBasedNRIContainer_Present;
	c_GprsTimer2 *T3324Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324Value_Present;
	c_GprsTimer3 *T3312ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3312ExtendedValue_Present;
	c_ExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;

}	c_ATTACH_REQUEST_UP;
#define INIT_c_ATTACH_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_REQUEST_UP))
/*FRK03a*/
void FREE_c_ATTACH_REQUEST_UP(c_ATTACH_REQUEST_UP* sp);
int SETPRESENT_c_ATTACH_REQUEST_UP_OldPTmsiSign (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_OldPTmsiSign(sp) ((sp)->OldPTmsiSign_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_ReqRdyTimerValue (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_ReqRdyTimerValue(sp) ((sp)->ReqRdyTimerValue_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_TmsiStatus (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_TmsiStatus(sp) ((sp)->TmsiStatus_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_PSLCSCapability (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_PSLCSCapability(sp) ((sp)->PSLCSCapability_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark2 (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark2(sp) ((sp)->MobileStationClassmark2_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark3 (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_MobileStationClassmark3(sp) ((sp)->MobileStationClassmark3_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_SupportedCodecs (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_UENetworkCapability (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_UENetworkCapability(sp) ((sp)->UENetworkCapability_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_AdditionalMobileIdentity(sp) ((sp)->AdditionalMobileIdentity_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_AdditionalOldRoutingAreaId(sp) ((sp)->AdditionalOldRoutingAreaId_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_VoiceDomainPrefUEUsageSetting(sp) ((sp)->VoiceDomainPrefUEUsageSetting_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_DeviceProperties (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_PTMSI (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_PTMSI(sp) ((sp)->PTMSI_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_MSNetworkFeatureSupport(sp) ((sp)->MSNetworkFeatureSupport_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_OldLocationAreaIdentification(sp) ((sp)->OldLocationAreaIdentification_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_AdditionalUpdateType (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_AdditionalUpdateType(sp) ((sp)->AdditionalUpdateType_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_TMSIBasedNRIContainer(sp) ((sp)->TMSIBasedNRIContainer_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_T3324Value (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_T3324Value(sp) ((sp)->T3324Value_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_T3312ExtendedValue (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_T3312ExtendedValue(sp) ((sp)->T3312ExtendedValue_Present)
int SETPRESENT_c_ATTACH_REQUEST_UP_ExtendedDRXParameters (c_ATTACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_UP_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)

/* Access member 'InterRATHandoverInfo' of type 'c_ATTACH_COMPLETE_UP' as a variable reference */
#define VAR_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo(var) (*var)

/* Access member 'InterRATHandoverInfo' of type 'c_ATTACH_COMPLETE_UP' as a pointer */
#define PTR_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo(var) var

/* Access member 'E_UTRAN_InterRATHandoverInfo' of type 'c_ATTACH_COMPLETE_UP' as a variable reference */
#define VAR_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(var) (*var)

/* Access member 'E_UTRAN_InterRATHandoverInfo' of type 'c_ATTACH_COMPLETE_UP' as a pointer */
#define PTR_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(var) var

/* DEFINITION OF BINARY c_ATTACH_COMPLETE_UP_InterRATHandoverInfo */
typedef struct _c_ATTACH_COMPLETE_UP_InterRATHandoverInfo {
	ED_BYTE* value; /* Variable size; bits needed 1984 */
	int usedBits;
} c_ATTACH_COMPLETE_UP_InterRATHandoverInfo;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo */
typedef struct _c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ATTACH_COMPLETE_UP {
	ED_LOCATOR InterRATHandoverInfo___LOCATOR  /*LBD01*/;
	ED_LOCATOR E_UTRAN_InterRATHandoverInfo___LOCATOR  /*LBD01*/;

	c_ATTACH_COMPLETE_UP_InterRATHandoverInfo* InterRATHandoverInfo; /* Dynamic, variable size; bits needed 1984 ODY02b *//*GBD01b*/
	ED_BOOLEAN InterRATHandoverInfo_Present;
	c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo* E_UTRAN_InterRATHandoverInfo; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN E_UTRAN_InterRATHandoverInfo_Present;

}	c_ATTACH_COMPLETE_UP;
#define INIT_c_ATTACH_COMPLETE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_COMPLETE_UP))
/*FRK03a*/
void FREE_c_ATTACH_COMPLETE_UP(c_ATTACH_COMPLETE_UP* sp);
int SETPRESENT_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo (c_ATTACH_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_COMPLETE_UP_InterRATHandoverInfo(sp) ((sp)->InterRATHandoverInfo_Present)
int SETPRESENT_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (c_ATTACH_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(sp) ((sp)->E_UTRAN_InterRATHandoverInfo_Present)

/* Access member 'DetachType' of type 'c_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_DETACH_REQUEST_UP_DetachType(var) var

/* Access member 'DetachType' of type 'c_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_DETACH_REQUEST_UP_DetachType(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_DETACH_REQUEST_UP_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_DETACH_REQUEST_UP_SpareHalfOctet(var) (&var)

/* Access member 'PTmsi' of type 'c_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_DETACH_REQUEST_UP_PTmsi(var) (*var)

/* Access member 'PTmsi' of type 'c_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_DETACH_REQUEST_UP_PTmsi(var) var

/* Access member 'PTmsiSign' of type 'c_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_DETACH_REQUEST_UP_PTmsiSign(var) (*var)

/* Access member 'PTmsiSign' of type 'c_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_DETACH_REQUEST_UP_PTmsiSign(var) var


/*-A----------------------------------*/
typedef struct _c_DETACH_REQUEST_UP {
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR PTmsiSign___LOCATOR  /*LBD01*/;

	c_DetachType DetachType; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_MobileId *PTmsi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PTmsi_Present;
	ED_BYTE* PTmsiSign; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN PTmsiSign_Present;

}	c_DETACH_REQUEST_UP;
#define INIT_c_DETACH_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_DETACH_REQUEST_UP))
/*FRK03a*/
void FREE_c_DETACH_REQUEST_UP(c_DETACH_REQUEST_UP* sp);
int SETPRESENT_c_DETACH_REQUEST_UP_PTmsi (c_DETACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DETACH_REQUEST_UP_PTmsi(sp) ((sp)->PTmsi_Present)
int SETPRESENT_c_DETACH_REQUEST_UP_PTmsiSign (c_DETACH_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DETACH_REQUEST_UP_PTmsiSign(sp) ((sp)->PTmsiSign_Present)


/*-A----------------------------------*/
typedef struct _c_DETACH_ACCEPT_UP {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_DETACH_ACCEPT_UP;
#define INIT_c_DETACH_ACCEPT_UP(sp) ED_RESET_MEM ((sp), sizeof (c_DETACH_ACCEPT_UP))
/*FRK03a*/
void FREE_c_DETACH_ACCEPT_UP(c_DETACH_ACCEPT_UP* sp);


/*-A----------------------------------*/
typedef struct _c_P_TMSI_REALLOCATION_COMPLETE_UP {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_P_TMSI_REALLOCATION_COMPLETE_UP;
#define INIT_c_P_TMSI_REALLOCATION_COMPLETE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_P_TMSI_REALLOCATION_COMPLETE_UP))
/*FRK03a*/
void FREE_c_P_TMSI_REALLOCATION_COMPLETE_UP(c_P_TMSI_REALLOCATION_COMPLETE_UP* sp);

/* Access member 'ACRefNum' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_ACRefNum(var) var

/* Access member 'ACRefNum' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_ACRefNum(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_SpareHalfOctet(var) (&var)

/* Access member 'AuthParamResp' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthParamResp(var) var

/* Access member 'AuthParamResp' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthParamResp(var) (&var)

/* Access member 'Imeisv' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv(var) (*var)

/* Access member 'Imeisv' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv(var) var

/* Access member 'AuthRespParamExt' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt(var) (*var)

/* Access member 'AuthRespParamExt' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt(var) var

/* Access member 'MessageAuthCode' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode(var) var

/* Access member 'MessageAuthCode' of type 'c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode(var) (&var)

/* DEFINITION OF BINARY c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt */
typedef struct _c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt {
	ED_BYTE* value; /* Variable size; bits needed 96 */
	int usedBits;
} c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP {
	ED_LOCATOR ACRefNum___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthParamResp___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthRespParamExt___LOCATOR  /*LBD01*/;
	ED_LOCATOR MessageAuthCode___LOCATOR; /* QUI2 */

	ED_OCTET ACRefNum; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	ED_LONG AuthParamResp; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AuthParamResp_Present;
	c_MobileId *Imeisv; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Imeisv_Present;
	c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt* AuthRespParamExt; /* Dynamic, variable size; bits needed 96 ODY02b *//*GBD01b*/
	ED_BOOLEAN AuthRespParamExt_Present;
	ED_LONG MessageAuthCode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MessageAuthCode_Present;

}	c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP;
#define INIT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP))
/*FRK03a*/
void FREE_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP(c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* sp);
#define SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthParamResp(sp,present) (((sp)->AuthParamResp_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthParamResp(sp) ((sp)->AuthParamResp_Present)
int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_Imeisv(sp) ((sp)->Imeisv_Present)
int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt (c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_AuthRespParamExt(sp) ((sp)->AuthRespParamExt_Present)
#define SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode(sp,present) (((sp)->MessageAuthCode_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_RESPONSE_UP_MessageAuthCode(sp) ((sp)->MessageAuthCode_Present)

/* Access member 'GmmCause' of type 'c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_GmmCause(var) (&var)

/* Access member 'AuthFailureParam' of type 'c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam(var) (*var)

/* Access member 'AuthFailureParam' of type 'c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam(var) var


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP {
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthFailureParam___LOCATOR  /*LBD01*/;

	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/
	ED_BYTE* AuthFailureParam; /* Dynamic, fixed size; bits needed: 112 ODY02a *//*GBD01b*/
	ED_BOOLEAN AuthFailureParam_Present;

}	c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP;
#define INIT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP))
/*FRK03a*/
void FREE_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP(c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* sp);
int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam (c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_FAILURE_UP_AuthFailureParam(sp) ((sp)->AuthFailureParam_Present)

/* Access member 'MobileId' of type 'c_IDENTITY_RESPONSE_B_UP' as a variable reference */
#define VAR_c_IDENTITY_RESPONSE_B_UP_MobileId(var) var

/* Access member 'MobileId' of type 'c_IDENTITY_RESPONSE_B_UP' as a pointer */
#define PTR_c_IDENTITY_RESPONSE_B_UP_MobileId(var) (&var)


/*-A----------------------------------*/
typedef struct _c_IDENTITY_RESPONSE_B_UP {

	c_MobileId MobileId; /* ODY01a *//*GBD01b*/

}	c_IDENTITY_RESPONSE_B_UP;
#define INIT_c_IDENTITY_RESPONSE_B_UP(sp) ED_RESET_MEM ((sp), sizeof (c_IDENTITY_RESPONSE_B_UP))
/*FRK03a*/
void FREE_c_IDENTITY_RESPONSE_B_UP(c_IDENTITY_RESPONSE_B_UP* sp);

/* Access member 'UpdateType' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_UpdateType(var) var

/* Access member 'UpdateType' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_UpdateType(var) (&var)

/* Access member 'GprsCiphKeySequenceNum' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_GprsCiphKeySequenceNum(var) var

/* Access member 'GprsCiphKeySequenceNum' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_GprsCiphKeySequenceNum(var) (&var)

/* Access member 'OldRoutingAreaId' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldRoutingAreaId(var) var

/* Access member 'OldRoutingAreaId' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldRoutingAreaId(var) (&var)

/* Access member 'MsRadioAccessCpblty' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsRadioAccessCpblty(var) var

/* Access member 'MsRadioAccessCpblty' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsRadioAccessCpblty(var) (&var)

/* Access member 'OldPTmsiSign' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign(var) (*var)

/* Access member 'OldPTmsiSign' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign(var) var

/* Access member 'ReqRdyTimerValue' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue(var) (*var)

/* Access member 'ReqRdyTimerValue' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue(var) var

/* Access member 'DrxParam' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam(var) (*var)

/* Access member 'DrxParam' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam(var) var

/* Access member 'TmsiStatus' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus(var) (*var)

/* Access member 'TmsiStatus' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus(var) var

/* Access member 'PTmsi' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi(var) (*var)

/* Access member 'PTmsi' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi(var) var

/* Access member 'MsNetwkCpblty' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty(var) (*var)

/* Access member 'MsNetwkCpblty' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty(var) var

/* Access member 'PdpContextStatus' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus(var) (*var)

/* Access member 'PdpContextStatus' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus(var) var

/* Access member 'PSLCSCapability' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability(var) (*var)

/* Access member 'PSLCSCapability' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability(var) var

/* Access member 'MBMSContextStatus' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus(var) (*var)

/* Access member 'MBMSContextStatus' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus(var) var

/* Access member 'UENetworkCapability' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability(var) (*var)

/* Access member 'UENetworkCapability' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability(var) var

/* Access member 'AdditionalMobileIdentity' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity(var) (*var)

/* Access member 'AdditionalMobileIdentity' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity(var) var

/* Access member 'AdditionalOldRoutingAreaIdent' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent(var) (*var)

/* Access member 'AdditionalOldRoutingAreaIdent' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent(var) var

/* Access member 'MobileStationClassmark2' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2(var) (*var)

/* Access member 'MobileStationClassmark2' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2(var) var

/* Access member 'MobileStationClassmark3' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3(var) (*var)

/* Access member 'MobileStationClassmark3' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3(var) var

/* Access member 'SupportedCodecs' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs(var) var

/* Access member 'VoiceDomainPrefUEUsageSetting' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting(var) (*var)

/* Access member 'VoiceDomainPrefUEUsageSetting' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting(var) var

/* Access member 'PTMSI' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI(var) (*var)

/* Access member 'PTMSI' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI(var) var

/* Access member 'DeviceProperties' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties(var) var

/* Access member 'MSNetworkFeatureSupport' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport(var) (*var)

/* Access member 'MSNetworkFeatureSupport' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport(var) var

/* Access member 'OldLocationAreaId' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId(var) (*var)

/* Access member 'OldLocationAreaId' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId(var) var

/* Access member 'AdditionalUpdateType' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType(var) (*var)

/* Access member 'AdditionalUpdateType' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType(var) var

/* Access member 'TMSIBasedNRIContainer' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer(var) (*var)

/* Access member 'TMSIBasedNRIContainer' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer(var) var

/* Access member 'T3324Value' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value(var) (*var)

/* Access member 'T3324Value' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value(var) var

/* Access member 'T3312ExtendedValue' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue(var) (*var)

/* Access member 'T3312ExtendedValue' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_ROUTING_AREA_UPDATE_REQUEST_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters(var) var

/* DEFINITION OF BINARY c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus */
typedef struct _c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability */
typedef struct _c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability {
	ED_BYTE* value; /* Variable size; bits needed 104 */
	int usedBits;
} c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ROUTING_AREA_UPDATE_REQUEST_UP {
	ED_LOCATOR GprsCiphKeySequenceNum___LOCATOR; /* QUI2 */
	ED_LOCATOR OldPTmsiSign___LOCATOR  /*LBD01*/;
	ED_LOCATOR MBMSContextStatus___LOCATOR  /*LBD01*/;
	ED_LOCATOR UENetworkCapability___LOCATOR  /*LBD01*/;
	ED_LOCATOR OldLocationAreaId___LOCATOR  /*LBD01*/;

	c_UpdateType UpdateType; /* ODY01a *//*GBD01b*/
	ED_OCTET GprsCiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	c_RoutingAreaIdenti OldRoutingAreaId; /* ODY01a *//*GBD01b*/
	c_MsRadioAccessCpblty MsRadioAccessCpblty; /* ODY01a *//*GBD01b*/
	ED_BYTE* OldPTmsiSign; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN OldPTmsiSign_Present;
	c_GprsTimer *ReqRdyTimerValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReqRdyTimerValue_Present;
	c_DrxParam *DrxParam; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DrxParam_Present;
	c_TmsiStatus *TmsiStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TmsiStatus_Present;
	c_MobileId *PTmsi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PTmsi_Present;
	c_MsNetwkCpblty *MsNetwkCpblty; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MsNetwkCpblty_Present;
	c_PdpContextStatus *PdpContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PdpContextStatus_Present;
	c_PSLCSCapabilit *PSLCSCapability; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PSLCSCapability_Present;
	c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus* MBMSContextStatus; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSContextStatus_Present;
	c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability* UENetworkCapability; /* Dynamic, variable size; bits needed 104 ODY02b *//*GBD01b*/
	ED_BOOLEAN UENetworkCapability_Present;
	c_MobileId *AdditionalMobileIdentity; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalMobileIdentity_Present;
	c_RoutingAreaIdenti2 *AdditionalOldRoutingAreaIdent; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalOldRoutingAreaIdent_Present;
	c_MobileStationClassmark2 *MobileStationClassmark2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileStationClassmark2_Present;
	c_Classmark3Value *MobileStationClassmark3; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileStationClassmark3_Present;
	c_SupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;
	c_VoiceDomainPreferenceAndUEsUsageSetting *VoiceDomainPrefUEUsageSetting; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN VoiceDomainPrefUEUsageSetting_Present;
	c_PTMSI_Type *PTMSI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PTMSI_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_MSNetworkFeatureSupport *MSNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSNetworkFeatureSupport_Present;
	ED_BYTE* OldLocationAreaId; /* Dynamic, fixed size; bits needed: 40 ODY02a *//*GBD01b*/
	ED_BOOLEAN OldLocationAreaId_Present;
	c_AdditionalUpdateType *AdditionalUpdateType; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateType_Present;
	c_NetworkResourceIdContainer *TMSIBasedNRIContainer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TMSIBasedNRIContainer_Present;
	c_GprsTimer2 *T3324Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324Value_Present;
	c_GprsTimer3 *T3312ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3312ExtendedValue_Present;
	c_ExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;

}	c_ROUTING_AREA_UPDATE_REQUEST_UP;
#define INIT_c_ROUTING_AREA_UPDATE_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_ROUTING_AREA_UPDATE_REQUEST_UP))
/*FRK03a*/
void FREE_c_ROUTING_AREA_UPDATE_REQUEST_UP(c_ROUTING_AREA_UPDATE_REQUEST_UP* sp);
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldPTmsiSign(sp) ((sp)->OldPTmsiSign_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ReqRdyTimerValue(sp) ((sp)->ReqRdyTimerValue_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DrxParam(sp) ((sp)->DrxParam_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TmsiStatus(sp) ((sp)->TmsiStatus_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTmsi(sp) ((sp)->PTmsi_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MsNetwkCpblty(sp) ((sp)->MsNetwkCpblty_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PdpContextStatus(sp) ((sp)->PdpContextStatus_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PSLCSCapability(sp) ((sp)->PSLCSCapability_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MBMSContextStatus(sp) ((sp)->MBMSContextStatus_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_UENetworkCapability(sp) ((sp)->UENetworkCapability_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalMobileIdentity(sp) ((sp)->AdditionalMobileIdentity_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalOldRoutingAreaIdent(sp) ((sp)->AdditionalOldRoutingAreaIdent_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2 (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark2(sp) ((sp)->MobileStationClassmark2_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3 (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MobileStationClassmark3(sp) ((sp)->MobileStationClassmark3_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_VoiceDomainPrefUEUsageSetting(sp) ((sp)->VoiceDomainPrefUEUsageSetting_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_PTMSI(sp) ((sp)->PTMSI_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_MSNetworkFeatureSupport(sp) ((sp)->MSNetworkFeatureSupport_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_OldLocationAreaId(sp) ((sp)->OldLocationAreaId_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_AdditionalUpdateType(sp) ((sp)->AdditionalUpdateType_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_TMSIBasedNRIContainer(sp) ((sp)->TMSIBasedNRIContainer_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3324Value(sp) ((sp)->T3324Value_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_T3312ExtendedValue(sp) ((sp)->T3312ExtendedValue_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters (c_ROUTING_AREA_UPDATE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REQUEST_UP_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)

/* Access member 'ListOfReceiveNPduNumbers' of type 'c_ROUTING_AREA_UPDATE_COMPLETE_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers(var) (*var)

/* Access member 'ListOfReceiveNPduNumbers' of type 'c_ROUTING_AREA_UPDATE_COMPLETE_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers(var) var

/* Access member 'InterRATHandoverInfo' of type 'c_ROUTING_AREA_UPDATE_COMPLETE_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo(var) (*var)

/* Access member 'InterRATHandoverInfo' of type 'c_ROUTING_AREA_UPDATE_COMPLETE_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo(var) var

/* Access member 'E_UTRAN_InterRATHandoverInfo' of type 'c_ROUTING_AREA_UPDATE_COMPLETE_UP' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(var) (*var)

/* Access member 'E_UTRAN_InterRATHandoverInfo' of type 'c_ROUTING_AREA_UPDATE_COMPLETE_UP' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(var) var

/* DEFINITION OF BINARY c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo */
typedef struct _c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo {
	ED_BYTE* value; /* Variable size; bits needed 1984 */
	int usedBits;
} c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo */
typedef struct _c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ROUTING_AREA_UPDATE_COMPLETE_UP {
	ED_LOCATOR InterRATHandoverInfo___LOCATOR  /*LBD01*/;
	ED_LOCATOR E_UTRAN_InterRATHandoverInfo___LOCATOR  /*LBD01*/;

	c_ReceiveNPduNumbersList *ListOfReceiveNPduNumbers; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ListOfReceiveNPduNumbers_Present;
	c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo* InterRATHandoverInfo; /* Dynamic, variable size; bits needed 1984 ODY02b *//*GBD01b*/
	ED_BOOLEAN InterRATHandoverInfo_Present;
	c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo* E_UTRAN_InterRATHandoverInfo; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN E_UTRAN_InterRATHandoverInfo_Present;

}	c_ROUTING_AREA_UPDATE_COMPLETE_UP;
#define INIT_c_ROUTING_AREA_UPDATE_COMPLETE_UP(sp) ED_RESET_MEM ((sp), sizeof (c_ROUTING_AREA_UPDATE_COMPLETE_UP))
/*FRK03a*/
void FREE_c_ROUTING_AREA_UPDATE_COMPLETE_UP(c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp);
int SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers (c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_ListOfReceiveNPduNumbers(sp) ((sp)->ListOfReceiveNPduNumbers_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo (c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_InterRATHandoverInfo(sp) ((sp)->InterRATHandoverInfo_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo (c_ROUTING_AREA_UPDATE_COMPLETE_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_COMPLETE_UP_E_UTRAN_InterRATHandoverInfo(sp) ((sp)->E_UTRAN_InterRATHandoverInfo_Present)

/* Access member 'GmmCause' of type 'c_GMM_STATUS' as a variable reference */
#define VAR_c_GMM_STATUS_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_GMM_STATUS' as a pointer */
#define PTR_c_GMM_STATUS_GmmCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_GMM_STATUS {
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */

	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/

}	c_GMM_STATUS;
#define INIT_c_GMM_STATUS(sp) ED_RESET_MEM ((sp), sizeof (c_GMM_STATUS))
/*FRK03a*/
void FREE_c_GMM_STATUS(c_GMM_STATUS* sp);

/* Access member 'CiphKeySequenceNum' of type 'c_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_SERVICE_REQUEST_UP_CiphKeySequenceNum(var) var

/* Access member 'CiphKeySequenceNum' of type 'c_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_SERVICE_REQUEST_UP_CiphKeySequenceNum(var) (&var)

/* Access member 'ServType' of type 'c_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_SERVICE_REQUEST_UP_ServType(var) var

/* Access member 'ServType' of type 'c_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_SERVICE_REQUEST_UP_ServType(var) (&var)

/* Access member 'PTmsi' of type 'c_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_SERVICE_REQUEST_UP_PTmsi(var) var

/* Access member 'PTmsi' of type 'c_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_SERVICE_REQUEST_UP_PTmsi(var) (&var)

/* Access member 'PdpContextStatus' of type 'c_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_SERVICE_REQUEST_UP_PdpContextStatus(var) (*var)

/* Access member 'PdpContextStatus' of type 'c_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_SERVICE_REQUEST_UP_PdpContextStatus(var) var

/* Access member 'MBMSContextStatus' of type 'c_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_SERVICE_REQUEST_UP_MBMSContextStatus(var) (*var)

/* Access member 'MBMSContextStatus' of type 'c_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_SERVICE_REQUEST_UP_MBMSContextStatus(var) var

/* Access member 'UplinkDataStatus' of type 'c_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_SERVICE_REQUEST_UP_UplinkDataStatus(var) (*var)

/* Access member 'UplinkDataStatus' of type 'c_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_SERVICE_REQUEST_UP_UplinkDataStatus(var) var

/* Access member 'DeviceProperties' of type 'c_SERVICE_REQUEST_UP' as a variable reference */
#define VAR_c_SERVICE_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_SERVICE_REQUEST_UP' as a pointer */
#define PTR_c_SERVICE_REQUEST_UP_DeviceProperties(var) var

/* DEFINITION OF BINARY c_SERVICE_REQUEST_UP_MBMSContextStatus */
typedef struct _c_SERVICE_REQUEST_UP_MBMSContextStatus {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_SERVICE_REQUEST_UP_MBMSContextStatus;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SERVICE_REQUEST_UP_MBMSContextStatus(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SERVICE_REQUEST_UP {
	ED_LOCATOR CiphKeySequenceNum___LOCATOR; /* QUI2 */
	ED_LOCATOR ServType___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSContextStatus___LOCATOR  /*LBD01*/;

	ED_OCTET CiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	ED_OCTET ServType; /* ODY01a *//*GBD01b*/
	c_MobileId PTmsi; /* ODY01a *//*GBD01b*/
	c_PdpContextStatus *PdpContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PdpContextStatus_Present;
	c_SERVICE_REQUEST_UP_MBMSContextStatus* MBMSContextStatus; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSContextStatus_Present;
	c_UplinkDataStatus *UplinkDataStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN UplinkDataStatus_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;

}	c_SERVICE_REQUEST_UP;
#define INIT_c_SERVICE_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_SERVICE_REQUEST_UP))
/*FRK03a*/
void FREE_c_SERVICE_REQUEST_UP(c_SERVICE_REQUEST_UP* sp);
int SETPRESENT_c_SERVICE_REQUEST_UP_PdpContextStatus (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_REQUEST_UP_PdpContextStatus(sp) ((sp)->PdpContextStatus_Present)
int SETPRESENT_c_SERVICE_REQUEST_UP_MBMSContextStatus (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_REQUEST_UP_MBMSContextStatus(sp) ((sp)->MBMSContextStatus_Present)
int SETPRESENT_c_SERVICE_REQUEST_UP_UplinkDataStatus (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_REQUEST_UP_UplinkDataStatus(sp) ((sp)->UplinkDataStatus_Present)
int SETPRESENT_c_SERVICE_REQUEST_UP_DeviceProperties (c_SERVICE_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_REJECT_DN {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_AUTHENTICATION_REJECT_DN;
#define INIT_c_AUTHENTICATION_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_REJECT_DN))
/*FRK03a*/
void FREE_c_AUTHENTICATION_REJECT_DN(c_AUTHENTICATION_REJECT_DN* sp);

/* Access member 'CiphKeySequenceNum' of type 'c_AUTHENTICATION_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_DN_CiphKeySequenceNum(var) var

/* Access member 'CiphKeySequenceNum' of type 'c_AUTHENTICATION_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_DN_CiphKeySequenceNum(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_AUTHENTICATION_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_AUTHENTICATION_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_DN_SpareHalfOctet(var) (&var)

/* Access member 'AuthParamRandUmtsChallOrGsmChall' of type 'c_AUTHENTICATION_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_DN_AuthParamRandUmtsChallOrGsmChall(var) var

/* Access member 'AuthParamRandUmtsChallOrGsmChall' of type 'c_AUTHENTICATION_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_DN_AuthParamRandUmtsChallOrGsmChall(var) (&var)

/* Access member 'AuthParamAutn' of type 'c_AUTHENTICATION_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn(var) (*var)

/* Access member 'AuthParamAutn' of type 'c_AUTHENTICATION_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn(var) var


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_REQUEST_DN {
	ED_LOCATOR CiphKeySequenceNum___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthParamRandUmtsChallOrGsmChall___LOCATOR  /*LBD02*/;
	ED_LOCATOR AuthParamAutn___LOCATOR  /*LBD01*/;

	ED_OCTET CiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	ED_BYTE AuthParamRandUmtsChallOrGsmChall [16]; /* Static, fixed size; bits needed 128 *//*GBD01b*/
	ED_BYTE* AuthParamAutn; /* Dynamic, fixed size; bits needed: 128 ODY02a *//*GBD01b*/
	ED_BOOLEAN AuthParamAutn_Present;

}	c_AUTHENTICATION_REQUEST_DN;
#define INIT_c_AUTHENTICATION_REQUEST_DN(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_REQUEST_DN))
/*FRK03a*/
void FREE_c_AUTHENTICATION_REQUEST_DN(c_AUTHENTICATION_REQUEST_DN* sp);
int SETPRESENT_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn (c_AUTHENTICATION_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_REQUEST_DN_AuthParamAutn(sp) ((sp)->AuthParamAutn_Present)


/*-A----------------------------------*/
typedef struct _c_CM_SERVICE_ACCEPT_DN {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_CM_SERVICE_ACCEPT_DN;
#define INIT_c_CM_SERVICE_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_CM_SERVICE_ACCEPT_DN))
/*FRK03a*/
void FREE_c_CM_SERVICE_ACCEPT_DN(c_CM_SERVICE_ACCEPT_DN* sp);

/* Access member 'PdAndSapiOfCm' of type 'c_CM_SERVICE_PROMPT_DN' as a variable reference */
#define VAR_c_CM_SERVICE_PROMPT_DN_PdAndSapiOfCm(var) var

/* Access member 'PdAndSapiOfCm' of type 'c_CM_SERVICE_PROMPT_DN' as a pointer */
#define PTR_c_CM_SERVICE_PROMPT_DN_PdAndSapiOfCm(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CM_SERVICE_PROMPT_DN {

	c_PdAndSapiCcbs PdAndSapiOfCm; /* ODY01a *//*GBD01b*/

}	c_CM_SERVICE_PROMPT_DN;
#define INIT_c_CM_SERVICE_PROMPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_CM_SERVICE_PROMPT_DN))
/*FRK03a*/
void FREE_c_CM_SERVICE_PROMPT_DN(c_CM_SERVICE_PROMPT_DN* sp);

/* Access member 'RejCause' of type 'c_CM_SERVICE_REJECT_DN' as a variable reference */
#define VAR_c_CM_SERVICE_REJECT_DN_RejCause(var) var

/* Access member 'RejCause' of type 'c_CM_SERVICE_REJECT_DN' as a pointer */
#define PTR_c_CM_SERVICE_REJECT_DN_RejCause(var) (&var)

/* Access member 'T3246Value' of type 'c_CM_SERVICE_REJECT_DN' as a variable reference */
#define VAR_c_CM_SERVICE_REJECT_DN_T3246Value(var) var

/* Access member 'T3246Value' of type 'c_CM_SERVICE_REJECT_DN' as a pointer */
#define PTR_c_CM_SERVICE_REJECT_DN_T3246Value(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CM_SERVICE_REJECT_DN {
	ED_LOCATOR T3246Value___LOCATOR; /* QUI2 */

	c_RejectCause RejCause; /* ODY01a *//*GBD01b*/
	ED_OCTET T3246Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN T3246Value_Present;

}	c_CM_SERVICE_REJECT_DN;
#define INIT_c_CM_SERVICE_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_CM_SERVICE_REJECT_DN))
/*FRK03a*/
void FREE_c_CM_SERVICE_REJECT_DN(c_CM_SERVICE_REJECT_DN* sp);
#define SETPRESENT_c_CM_SERVICE_REJECT_DN_T3246Value(sp,present) (((sp)->T3246Value_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CM_SERVICE_REJECT_DN_T3246Value(sp) ((sp)->T3246Value_Present)

/* Access member 'RejCause' of type 'c_ABORT_DN' as a variable reference */
#define VAR_c_ABORT_DN_RejCause(var) var

/* Access member 'RejCause' of type 'c_ABORT_DN' as a pointer */
#define PTR_c_ABORT_DN_RejCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ABORT_DN {

	c_RejectCause RejCause; /* ODY01a *//*GBD01b*/

}	c_ABORT_DN;
#define INIT_c_ABORT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ABORT_DN))
/*FRK03a*/
void FREE_c_ABORT_DN(c_ABORT_DN* sp);

/* Access member 'IdType' of type 'c_IDENTITY_REQUEST_DN' as a variable reference */
#define VAR_c_IDENTITY_REQUEST_DN_IdType(var) var

/* Access member 'IdType' of type 'c_IDENTITY_REQUEST_DN' as a pointer */
#define PTR_c_IDENTITY_REQUEST_DN_IdType(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_IDENTITY_REQUEST_DN' as a variable reference */
#define VAR_c_IDENTITY_REQUEST_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_IDENTITY_REQUEST_DN' as a pointer */
#define PTR_c_IDENTITY_REQUEST_DN_SpareHalfOctet(var) (&var)


/*-A----------------------------------*/
typedef struct _c_IDENTITY_REQUEST_DN {
	ED_LOCATOR IdType___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */

	ED_OCTET IdType; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/

}	c_IDENTITY_REQUEST_DN;
#define INIT_c_IDENTITY_REQUEST_DN(sp) ED_RESET_MEM ((sp), sizeof (c_IDENTITY_REQUEST_DN))
/*FRK03a*/
void FREE_c_IDENTITY_REQUEST_DN(c_IDENTITY_REQUEST_DN* sp);

/* Access member 'LocationAreaId' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a variable reference */
#define VAR_c_LOCATION_UPDATING_ACCEPT_DN_LocationAreaId(var) var

/* Access member 'LocationAreaId' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a pointer */
#define PTR_c_LOCATION_UPDATING_ACCEPT_DN_LocationAreaId(var) (&var)

/* Access member 'MobileId' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a variable reference */
#define VAR_c_LOCATION_UPDATING_ACCEPT_DN_MobileId(var) (*var)

/* Access member 'MobileId' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a pointer */
#define PTR_c_LOCATION_UPDATING_ACCEPT_DN_MobileId(var) var

/* Access member 'FollowOnProceed' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a variable reference */
#define VAR_c_LOCATION_UPDATING_ACCEPT_DN_FollowOnProceed(var) var

/* Access member 'FollowOnProceed' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a pointer */
#define PTR_c_LOCATION_UPDATING_ACCEPT_DN_FollowOnProceed(var) (&var)

/* Access member 'CtsPermission' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a variable reference */
#define VAR_c_LOCATION_UPDATING_ACCEPT_DN_CtsPermission(var) var

/* Access member 'CtsPermission' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a pointer */
#define PTR_c_LOCATION_UPDATING_ACCEPT_DN_CtsPermission(var) (&var)

/* Access member 'EquivPlmns' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a variable reference */
#define VAR_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns(var) (*var)

/* Access member 'EquivPlmns' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a pointer */
#define PTR_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns(var) var

/* Access member 'EmergencyNumberList' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a variable reference */
#define VAR_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList(var) (*var)

/* Access member 'EmergencyNumberList' of type 'c_LOCATION_UPDATING_ACCEPT_DN' as a pointer */
#define PTR_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList(var) var


/*-A----------------------------------*/
typedef struct _c_LOCATION_UPDATING_ACCEPT_DN {

	c_LocationAreaId LocationAreaId; /* ODY01a *//*GBD01b*/
	c_MobileId *MobileId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileId_Present;
	/*GBD01b*/
	ED_BOOLEAN FollowOnProceed_Present;
	/*GBD01b*/
	ED_BOOLEAN CtsPermission_Present;
	c_PlmnList *EquivPlmns; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EquivPlmns_Present;
	c_EmergencyNumberList *EmergencyNumberList; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EmergencyNumberList_Present;

}	c_LOCATION_UPDATING_ACCEPT_DN;
#define INIT_c_LOCATION_UPDATING_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_LOCATION_UPDATING_ACCEPT_DN))
/*FRK03a*/
void FREE_c_LOCATION_UPDATING_ACCEPT_DN(c_LOCATION_UPDATING_ACCEPT_DN* sp);
int SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_MobileId (c_LOCATION_UPDATING_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_MobileId(sp) ((sp)->MobileId_Present)
#define SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_FollowOnProceed(sp,present) (((sp)->FollowOnProceed_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_FollowOnProceed(sp) ((sp)->FollowOnProceed_Present)
#define SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_CtsPermission(sp,present) (((sp)->CtsPermission_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_CtsPermission(sp) ((sp)->CtsPermission_Present)
int SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns (c_LOCATION_UPDATING_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EquivPlmns(sp) ((sp)->EquivPlmns_Present)
int SETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList (c_LOCATION_UPDATING_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_LOCATION_UPDATING_ACCEPT_DN_EmergencyNumberList(sp) ((sp)->EmergencyNumberList_Present)

/* Access member 'RejCause' of type 'c_LOCATION_UPDATING_REJECT_DN' as a variable reference */
#define VAR_c_LOCATION_UPDATING_REJECT_DN_RejCause(var) var

/* Access member 'RejCause' of type 'c_LOCATION_UPDATING_REJECT_DN' as a pointer */
#define PTR_c_LOCATION_UPDATING_REJECT_DN_RejCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_LOCATION_UPDATING_REJECT_DN {

	c_RejectCause RejCause; /* ODY01a *//*GBD01b*/

}	c_LOCATION_UPDATING_REJECT_DN;
#define INIT_c_LOCATION_UPDATING_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_LOCATION_UPDATING_REJECT_DN))
/*FRK03a*/
void FREE_c_LOCATION_UPDATING_REJECT_DN(c_LOCATION_UPDATING_REJECT_DN* sp);

/* Access member 'FullNameForNetwk' of type 'c_MM_INFORMATION_DN' as a variable reference */
#define VAR_c_MM_INFORMATION_DN_FullNameForNetwk(var) (*var)

/* Access member 'FullNameForNetwk' of type 'c_MM_INFORMATION_DN' as a pointer */
#define PTR_c_MM_INFORMATION_DN_FullNameForNetwk(var) var

/* Access member 'ShortNameForNetwk' of type 'c_MM_INFORMATION_DN' as a variable reference */
#define VAR_c_MM_INFORMATION_DN_ShortNameForNetwk(var) (*var)

/* Access member 'ShortNameForNetwk' of type 'c_MM_INFORMATION_DN' as a pointer */
#define PTR_c_MM_INFORMATION_DN_ShortNameForNetwk(var) var

/* Access member 'LocalTimeZone' of type 'c_MM_INFORMATION_DN' as a variable reference */
#define VAR_c_MM_INFORMATION_DN_LocalTimeZone(var) var

/* Access member 'LocalTimeZone' of type 'c_MM_INFORMATION_DN' as a pointer */
#define PTR_c_MM_INFORMATION_DN_LocalTimeZone(var) (&var)

/* Access member 'UniversalTimeAndLocalTimeZone' of type 'c_MM_INFORMATION_DN' as a variable reference */
#define VAR_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone(var) (*var)

/* Access member 'UniversalTimeAndLocalTimeZone' of type 'c_MM_INFORMATION_DN' as a pointer */
#define PTR_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone(var) var

/* Access member 'LsaId' of type 'c_MM_INFORMATION_DN' as a variable reference */
#define VAR_c_MM_INFORMATION_DN_LsaId(var) (*var)

/* Access member 'LsaId' of type 'c_MM_INFORMATION_DN' as a pointer */
#define PTR_c_MM_INFORMATION_DN_LsaId(var) var

/* Access member 'NetwkDaylightSavingTime' of type 'c_MM_INFORMATION_DN' as a variable reference */
#define VAR_c_MM_INFORMATION_DN_NetwkDaylightSavingTime(var) (*var)

/* Access member 'NetwkDaylightSavingTime' of type 'c_MM_INFORMATION_DN' as a pointer */
#define PTR_c_MM_INFORMATION_DN_NetwkDaylightSavingTime(var) var

/* DEFINITION OF BINARY c_MM_INFORMATION_DN_LsaId */
typedef struct _c_MM_INFORMATION_DN_LsaId {
	ED_BYTE* value; /* Variable size; bits needed 24 */
	int usedBits;
} c_MM_INFORMATION_DN_LsaId;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MM_INFORMATION_DN_LsaId(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MM_INFORMATION_DN {
	ED_LOCATOR LocalTimeZone___LOCATOR; /* QUI2 */
	ED_LOCATOR LsaId___LOCATOR  /*LBD01*/;

	c_NetwkName *FullNameForNetwk; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN FullNameForNetwk_Present;
	c_NetwkName *ShortNameForNetwk; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ShortNameForNetwk_Present;
	ED_OCTET LocalTimeZone; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LocalTimeZone_Present;
	c_TimeZoneAndTime *UniversalTimeAndLocalTimeZone; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN UniversalTimeAndLocalTimeZone_Present;
	c_MM_INFORMATION_DN_LsaId* LsaId; /* Dynamic, variable size; bits needed 24 ODY02b *//*GBD01b*/
	ED_BOOLEAN LsaId_Present;
	c_DaylightSavingTime *NetwkDaylightSavingTime; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NetwkDaylightSavingTime_Present;

}	c_MM_INFORMATION_DN;
#define INIT_c_MM_INFORMATION_DN(sp) ED_RESET_MEM ((sp), sizeof (c_MM_INFORMATION_DN))
/*FRK03a*/
void FREE_c_MM_INFORMATION_DN(c_MM_INFORMATION_DN* sp);
int SETPRESENT_c_MM_INFORMATION_DN_FullNameForNetwk (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MM_INFORMATION_DN_FullNameForNetwk(sp) ((sp)->FullNameForNetwk_Present)
int SETPRESENT_c_MM_INFORMATION_DN_ShortNameForNetwk (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MM_INFORMATION_DN_ShortNameForNetwk(sp) ((sp)->ShortNameForNetwk_Present)
#define SETPRESENT_c_MM_INFORMATION_DN_LocalTimeZone(sp,present) (((sp)->LocalTimeZone_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MM_INFORMATION_DN_LocalTimeZone(sp) ((sp)->LocalTimeZone_Present)
int SETPRESENT_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MM_INFORMATION_DN_UniversalTimeAndLocalTimeZone(sp) ((sp)->UniversalTimeAndLocalTimeZone_Present)
int SETPRESENT_c_MM_INFORMATION_DN_LsaId (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MM_INFORMATION_DN_LsaId(sp) ((sp)->LsaId_Present)
int SETPRESENT_c_MM_INFORMATION_DN_NetwkDaylightSavingTime (c_MM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MM_INFORMATION_DN_NetwkDaylightSavingTime(sp) ((sp)->NetwkDaylightSavingTime_Present)

/* Access member 'LocationAreaId' of type 'c_TMSI_REALLOCATION_COMMAND_DN' as a variable reference */
#define VAR_c_TMSI_REALLOCATION_COMMAND_DN_LocationAreaId(var) var

/* Access member 'LocationAreaId' of type 'c_TMSI_REALLOCATION_COMMAND_DN' as a pointer */
#define PTR_c_TMSI_REALLOCATION_COMMAND_DN_LocationAreaId(var) (&var)

/* Access member 'MobileId' of type 'c_TMSI_REALLOCATION_COMMAND_DN' as a variable reference */
#define VAR_c_TMSI_REALLOCATION_COMMAND_DN_MobileId(var) var

/* Access member 'MobileId' of type 'c_TMSI_REALLOCATION_COMMAND_DN' as a pointer */
#define PTR_c_TMSI_REALLOCATION_COMMAND_DN_MobileId(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TMSI_REALLOCATION_COMMAND_DN {

	c_LocationAreaId LocationAreaId; /* ODY01a *//*GBD01b*/
	c_MobileId MobileId; /* ODY01a *//*GBD01b*/

}	c_TMSI_REALLOCATION_COMMAND_DN;
#define INIT_c_TMSI_REALLOCATION_COMMAND_DN(sp) ED_RESET_MEM ((sp), sizeof (c_TMSI_REALLOCATION_COMMAND_DN))
/*FRK03a*/
void FREE_c_TMSI_REALLOCATION_COMMAND_DN(c_TMSI_REALLOCATION_COMMAND_DN* sp);

/* Access member 'TI_Value' of type 'c_ALERTING_DN' as a variable reference */
#define VAR_c_ALERTING_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ALERTING_DN' as a pointer */
#define PTR_c_ALERTING_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ALERTING_DN' as a variable reference */
#define VAR_c_ALERTING_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ALERTING_DN' as a pointer */
#define PTR_c_ALERTING_DN_TI_Flag(var) (&var)

/* Access member 'Facility' of type 'c_ALERTING_DN' as a variable reference */
#define VAR_c_ALERTING_DN_Facility(var) (*var)

/* Access member 'Facility' of type 'c_ALERTING_DN' as a pointer */
#define PTR_c_ALERTING_DN_Facility(var) var

/* Access member 'ProgrInd' of type 'c_ALERTING_DN' as a variable reference */
#define VAR_c_ALERTING_DN_ProgrInd(var) (*var)

/* Access member 'ProgrInd' of type 'c_ALERTING_DN' as a pointer */
#define PTR_c_ALERTING_DN_ProgrInd(var) var

/* Access member 'UserUser' of type 'c_ALERTING_DN' as a variable reference */
#define VAR_c_ALERTING_DN_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_ALERTING_DN' as a pointer */
#define PTR_c_ALERTING_DN_UserUser(var) var

/* DEFINITION OF BINARY c_ALERTING_DN_Facility */
typedef struct _c_ALERTING_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_ALERTING_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ALERTING_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ALERTING_DN_UserUser */
typedef struct _c_ALERTING_DN_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_ALERTING_DN_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ALERTING_DN_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ALERTING_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_ALERTING_DN_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_ProgrInd *ProgrInd; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProgrInd_Present;
	c_ALERTING_DN_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;

}	c_ALERTING_DN;
#define INIT_c_ALERTING_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ALERTING_DN))
/*FRK03a*/
void FREE_c_ALERTING_DN(c_ALERTING_DN* sp);
int SETPRESENT_c_ALERTING_DN_Facility (c_ALERTING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ALERTING_DN_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_ALERTING_DN_ProgrInd (c_ALERTING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ALERTING_DN_ProgrInd(sp) ((sp)->ProgrInd_Present)
int SETPRESENT_c_ALERTING_DN_UserUser (c_ALERTING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ALERTING_DN_UserUser(sp) ((sp)->UserUser_Present)

/* Access member 'TI_Value' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_TI_Flag(var) (&var)

/* Access member 'RepeatInd' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_RepeatInd(var) var

/* Access member 'RepeatInd' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_RepeatInd(var) (&var)

/* Access member 'BearerCpblty1' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_BearerCpblty1(var) (*var)

/* Access member 'BearerCpblty1' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_BearerCpblty1(var) var

/* Access member 'BearerCpblty2' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_BearerCpblty2(var) (*var)

/* Access member 'BearerCpblty2' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_BearerCpblty2(var) var

/* Access member 'Facility' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_Facility(var) (*var)

/* Access member 'Facility' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_Facility(var) var

/* Access member 'ProgrInd' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_ProgrInd(var) (*var)

/* Access member 'ProgrInd' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_ProgrInd(var) var

/* Access member 'PriorityGranted' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_PriorityGranted(var) (*var)

/* Access member 'PriorityGranted' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_PriorityGranted(var) var

/* Access member 'NetwkCallControlCapabil' of type 'c_CALL_PROCEEDING_DN' as a variable reference */
#define VAR_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil(var) (*var)

/* Access member 'NetwkCallControlCapabil' of type 'c_CALL_PROCEEDING_DN' as a pointer */
#define PTR_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil(var) var

/* DEFINITION OF BINARY c_CALL_PROCEEDING_DN_Facility */
typedef struct _c_CALL_PROCEEDING_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_CALL_PROCEEDING_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CALL_PROCEEDING_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_CALL_PROCEEDING_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR RepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET RepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RepeatInd_Present;
	c_BearerCpblty *BearerCpblty1; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty1_Present;
	c_BearerCpblty *BearerCpblty2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty2_Present;
	c_CALL_PROCEEDING_DN_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_ProgrInd *ProgrInd; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProgrInd_Present;
	c_PriorityLevel *PriorityGranted; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PriorityGranted_Present;
	c_NetwkCallControlCapabil *NetwkCallControlCapabil; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NetwkCallControlCapabil_Present;

}	c_CALL_PROCEEDING_DN;
#define INIT_c_CALL_PROCEEDING_DN(sp) ED_RESET_MEM ((sp), sizeof (c_CALL_PROCEEDING_DN))
/*FRK03a*/
void FREE_c_CALL_PROCEEDING_DN(c_CALL_PROCEEDING_DN* sp);
#define SETPRESENT_c_CALL_PROCEEDING_DN_RepeatInd(sp,present) (((sp)->RepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CALL_PROCEEDING_DN_RepeatInd(sp) ((sp)->RepeatInd_Present)
int SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty1 (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty1(sp) ((sp)->BearerCpblty1_Present)
int SETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty2 (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_PROCEEDING_DN_BearerCpblty2(sp) ((sp)->BearerCpblty2_Present)
int SETPRESENT_c_CALL_PROCEEDING_DN_Facility (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_PROCEEDING_DN_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_CALL_PROCEEDING_DN_ProgrInd (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_PROCEEDING_DN_ProgrInd(sp) ((sp)->ProgrInd_Present)
int SETPRESENT_c_CALL_PROCEEDING_DN_PriorityGranted (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_PROCEEDING_DN_PriorityGranted(sp) ((sp)->PriorityGranted_Present)
int SETPRESENT_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil (c_CALL_PROCEEDING_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CALL_PROCEEDING_DN_NetwkCallControlCapabil(sp) ((sp)->NetwkCallControlCapabil_Present)

/* Access member 'TI_Value' of type 'c_CONGESTION_CONTROL_DN' as a variable reference */
#define VAR_c_CONGESTION_CONTROL_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CONGESTION_CONTROL_DN' as a pointer */
#define PTR_c_CONGESTION_CONTROL_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CONGESTION_CONTROL_DN' as a variable reference */
#define VAR_c_CONGESTION_CONTROL_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CONGESTION_CONTROL_DN' as a pointer */
#define PTR_c_CONGESTION_CONTROL_DN_TI_Flag(var) (&var)

/* Access member 'CongestionLevel' of type 'c_CONGESTION_CONTROL_DN' as a variable reference */
#define VAR_c_CONGESTION_CONTROL_DN_CongestionLevel(var) var

/* Access member 'CongestionLevel' of type 'c_CONGESTION_CONTROL_DN' as a pointer */
#define PTR_c_CONGESTION_CONTROL_DN_CongestionLevel(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_CONGESTION_CONTROL_DN' as a variable reference */
#define VAR_c_CONGESTION_CONTROL_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_CONGESTION_CONTROL_DN' as a pointer */
#define PTR_c_CONGESTION_CONTROL_DN_SpareHalfOctet(var) (&var)

/* Access member 'Cause' of type 'c_CONGESTION_CONTROL_DN' as a variable reference */
#define VAR_c_CONGESTION_CONTROL_DN_Cause(var) (*var)

/* Access member 'Cause' of type 'c_CONGESTION_CONTROL_DN' as a pointer */
#define PTR_c_CONGESTION_CONTROL_DN_Cause(var) var


/*-A----------------------------------*/
typedef struct _c_CONGESTION_CONTROL_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR CongestionLevel___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET CongestionLevel; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_Cause *Cause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Cause_Present;

}	c_CONGESTION_CONTROL_DN;
#define INIT_c_CONGESTION_CONTROL_DN(sp) ED_RESET_MEM ((sp), sizeof (c_CONGESTION_CONTROL_DN))
/*FRK03a*/
void FREE_c_CONGESTION_CONTROL_DN(c_CONGESTION_CONTROL_DN* sp);
int SETPRESENT_c_CONGESTION_CONTROL_DN_Cause (c_CONGESTION_CONTROL_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONGESTION_CONTROL_DN_Cause(sp) ((sp)->Cause_Present)

/* Access member 'TI_Value' of type 'c_CONNECT_DN' as a variable reference */
#define VAR_c_CONNECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CONNECT_DN' as a pointer */
#define PTR_c_CONNECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CONNECT_DN' as a variable reference */
#define VAR_c_CONNECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CONNECT_DN' as a pointer */
#define PTR_c_CONNECT_DN_TI_Flag(var) (&var)

/* Access member 'Facility' of type 'c_CONNECT_DN' as a variable reference */
#define VAR_c_CONNECT_DN_Facility(var) (*var)

/* Access member 'Facility' of type 'c_CONNECT_DN' as a pointer */
#define PTR_c_CONNECT_DN_Facility(var) var

/* Access member 'ProgrInd' of type 'c_CONNECT_DN' as a variable reference */
#define VAR_c_CONNECT_DN_ProgrInd(var) (*var)

/* Access member 'ProgrInd' of type 'c_CONNECT_DN' as a pointer */
#define PTR_c_CONNECT_DN_ProgrInd(var) var

/* Access member 'ConnNum' of type 'c_CONNECT_DN' as a variable reference */
#define VAR_c_CONNECT_DN_ConnNum(var) (*var)

/* Access member 'ConnNum' of type 'c_CONNECT_DN' as a pointer */
#define PTR_c_CONNECT_DN_ConnNum(var) var

/* Access member 'ConnSubaddr' of type 'c_CONNECT_DN' as a variable reference */
#define VAR_c_CONNECT_DN_ConnSubaddr(var) (*var)

/* Access member 'ConnSubaddr' of type 'c_CONNECT_DN' as a pointer */
#define PTR_c_CONNECT_DN_ConnSubaddr(var) var

/* Access member 'UserUser' of type 'c_CONNECT_DN' as a variable reference */
#define VAR_c_CONNECT_DN_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_CONNECT_DN' as a pointer */
#define PTR_c_CONNECT_DN_UserUser(var) var

/* DEFINITION OF BINARY c_CONNECT_DN_Facility */
typedef struct _c_CONNECT_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_CONNECT_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CONNECT_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_CONNECT_DN_UserUser */
typedef struct _c_CONNECT_DN_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_CONNECT_DN_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CONNECT_DN_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_CONNECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_CONNECT_DN_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_ProgrInd *ProgrInd; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProgrInd_Present;
	c_ConnNum *ConnNum; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ConnNum_Present;
	c_ConnSubaddres *ConnSubaddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ConnSubaddr_Present;
	c_CONNECT_DN_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;

}	c_CONNECT_DN;
#define INIT_c_CONNECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_CONNECT_DN))
/*FRK03a*/
void FREE_c_CONNECT_DN(c_CONNECT_DN* sp);
int SETPRESENT_c_CONNECT_DN_Facility (c_CONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_DN_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_CONNECT_DN_ProgrInd (c_CONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_DN_ProgrInd(sp) ((sp)->ProgrInd_Present)
int SETPRESENT_c_CONNECT_DN_ConnNum (c_CONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_DN_ConnNum(sp) ((sp)->ConnNum_Present)
int SETPRESENT_c_CONNECT_DN_ConnSubaddr (c_CONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_DN_ConnSubaddr(sp) ((sp)->ConnSubaddr_Present)
int SETPRESENT_c_CONNECT_DN_UserUser (c_CONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONNECT_DN_UserUser(sp) ((sp)->UserUser_Present)

/* Access member 'TI_Value' of type 'c_DISCONNECT_DN' as a variable reference */
#define VAR_c_DISCONNECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_DISCONNECT_DN' as a pointer */
#define PTR_c_DISCONNECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_DISCONNECT_DN' as a variable reference */
#define VAR_c_DISCONNECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_DISCONNECT_DN' as a pointer */
#define PTR_c_DISCONNECT_DN_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_DISCONNECT_DN' as a variable reference */
#define VAR_c_DISCONNECT_DN_Cause(var) var

/* Access member 'Cause' of type 'c_DISCONNECT_DN' as a pointer */
#define PTR_c_DISCONNECT_DN_Cause(var) (&var)

/* Access member 'Facility' of type 'c_DISCONNECT_DN' as a variable reference */
#define VAR_c_DISCONNECT_DN_Facility(var) (*var)

/* Access member 'Facility' of type 'c_DISCONNECT_DN' as a pointer */
#define PTR_c_DISCONNECT_DN_Facility(var) var

/* Access member 'ProgrInd' of type 'c_DISCONNECT_DN' as a variable reference */
#define VAR_c_DISCONNECT_DN_ProgrInd(var) (*var)

/* Access member 'ProgrInd' of type 'c_DISCONNECT_DN' as a pointer */
#define PTR_c_DISCONNECT_DN_ProgrInd(var) var

/* Access member 'UserUser' of type 'c_DISCONNECT_DN' as a variable reference */
#define VAR_c_DISCONNECT_DN_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_DISCONNECT_DN' as a pointer */
#define PTR_c_DISCONNECT_DN_UserUser(var) var

/* Access member 'AllowedActionsCcbs' of type 'c_DISCONNECT_DN' as a variable reference */
#define VAR_c_DISCONNECT_DN_AllowedActionsCcbs(var) (*var)

/* Access member 'AllowedActionsCcbs' of type 'c_DISCONNECT_DN' as a pointer */
#define PTR_c_DISCONNECT_DN_AllowedActionsCcbs(var) var

/* DEFINITION OF BINARY c_DISCONNECT_DN_Facility */
typedef struct _c_DISCONNECT_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_DISCONNECT_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DISCONNECT_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_DISCONNECT_DN_UserUser */
typedef struct _c_DISCONNECT_DN_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_DISCONNECT_DN_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DISCONNECT_DN_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DISCONNECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause Cause; /* ODY01a *//*GBD01b*/
	c_DISCONNECT_DN_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_ProgrInd *ProgrInd; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProgrInd_Present;
	c_DISCONNECT_DN_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_AllowedActionsCcbs *AllowedActionsCcbs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AllowedActionsCcbs_Present;

}	c_DISCONNECT_DN;
#define INIT_c_DISCONNECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_DISCONNECT_DN))
/*FRK03a*/
void FREE_c_DISCONNECT_DN(c_DISCONNECT_DN* sp);
int SETPRESENT_c_DISCONNECT_DN_Facility (c_DISCONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DISCONNECT_DN_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_DISCONNECT_DN_ProgrInd (c_DISCONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DISCONNECT_DN_ProgrInd(sp) ((sp)->ProgrInd_Present)
int SETPRESENT_c_DISCONNECT_DN_UserUser (c_DISCONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DISCONNECT_DN_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_DISCONNECT_DN_AllowedActionsCcbs (c_DISCONNECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DISCONNECT_DN_AllowedActionsCcbs(sp) ((sp)->AllowedActionsCcbs_Present)

/* Access member 'TI_Value' of type 'c_FACILITY_DN' as a variable reference */
#define VAR_c_FACILITY_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_FACILITY_DN' as a pointer */
#define PTR_c_FACILITY_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_FACILITY_DN' as a variable reference */
#define VAR_c_FACILITY_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_FACILITY_DN' as a pointer */
#define PTR_c_FACILITY_DN_TI_Flag(var) (&var)

/* Access member 'Facility' of type 'c_FACILITY_DN' as a variable reference */
#define VAR_c_FACILITY_DN_Facility(var) var

/* Access member 'Facility' of type 'c_FACILITY_DN' as a pointer */
#define PTR_c_FACILITY_DN_Facility(var) (&var)

/* DEFINITION OF BINARY c_FACILITY_DN_Facility */
typedef struct _c_FACILITY_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4792 */
	int usedBits;
} c_FACILITY_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_FACILITY_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_FACILITY_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD02*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_FACILITY_DN_Facility Facility; /* Static, variable size; bits needed 4792 *//*GBD01b*/

}	c_FACILITY_DN;
#define INIT_c_FACILITY_DN(sp) ED_RESET_MEM ((sp), sizeof (c_FACILITY_DN))
/*FRK03a*/
void FREE_c_FACILITY_DN(c_FACILITY_DN* sp);

/* Access member 'TI_Value' of type 'c_HOLD_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_HOLD_ACKNOWLEDGE_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_HOLD_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_HOLD_ACKNOWLEDGE_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_HOLD_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_HOLD_ACKNOWLEDGE_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_HOLD_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_HOLD_ACKNOWLEDGE_DN_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_HOLD_ACKNOWLEDGE_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_HOLD_ACKNOWLEDGE_DN;
#define INIT_c_HOLD_ACKNOWLEDGE_DN(sp) ED_RESET_MEM ((sp), sizeof (c_HOLD_ACKNOWLEDGE_DN))
/*FRK03a*/
void FREE_c_HOLD_ACKNOWLEDGE_DN(c_HOLD_ACKNOWLEDGE_DN* sp);

/* Access member 'TI_Value' of type 'c_HOLD_REJECT_DN' as a variable reference */
#define VAR_c_HOLD_REJECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_HOLD_REJECT_DN' as a pointer */
#define PTR_c_HOLD_REJECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_HOLD_REJECT_DN' as a variable reference */
#define VAR_c_HOLD_REJECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_HOLD_REJECT_DN' as a pointer */
#define PTR_c_HOLD_REJECT_DN_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_HOLD_REJECT_DN' as a variable reference */
#define VAR_c_HOLD_REJECT_DN_Cause(var) var

/* Access member 'Cause' of type 'c_HOLD_REJECT_DN' as a pointer */
#define PTR_c_HOLD_REJECT_DN_Cause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_HOLD_REJECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause Cause; /* ODY01a *//*GBD01b*/

}	c_HOLD_REJECT_DN;
#define INIT_c_HOLD_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_HOLD_REJECT_DN))
/*FRK03a*/
void FREE_c_HOLD_REJECT_DN(c_HOLD_REJECT_DN* sp);

/* Access member 'TI_Value' of type 'c_PROGRESS_DN' as a variable reference */
#define VAR_c_PROGRESS_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_PROGRESS_DN' as a pointer */
#define PTR_c_PROGRESS_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_PROGRESS_DN' as a variable reference */
#define VAR_c_PROGRESS_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_PROGRESS_DN' as a pointer */
#define PTR_c_PROGRESS_DN_TI_Flag(var) (&var)

/* Access member 'ProgrInd' of type 'c_PROGRESS_DN' as a variable reference */
#define VAR_c_PROGRESS_DN_ProgrInd(var) var

/* Access member 'ProgrInd' of type 'c_PROGRESS_DN' as a pointer */
#define PTR_c_PROGRESS_DN_ProgrInd(var) (&var)

/* Access member 'UserUser' of type 'c_PROGRESS_DN' as a variable reference */
#define VAR_c_PROGRESS_DN_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_PROGRESS_DN' as a pointer */
#define PTR_c_PROGRESS_DN_UserUser(var) var

/* DEFINITION OF BINARY c_PROGRESS_DN_UserUser */
typedef struct _c_PROGRESS_DN_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_PROGRESS_DN_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_PROGRESS_DN_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_PROGRESS_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_ProgrInd ProgrInd; /* ODY01a *//*GBD01b*/
	c_PROGRESS_DN_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;

}	c_PROGRESS_DN;
#define INIT_c_PROGRESS_DN(sp) ED_RESET_MEM ((sp), sizeof (c_PROGRESS_DN))
/*FRK03a*/
void FREE_c_PROGRESS_DN(c_PROGRESS_DN* sp);
int SETPRESENT_c_PROGRESS_DN_UserUser (c_PROGRESS_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PROGRESS_DN_UserUser(sp) ((sp)->UserUser_Present)

/* Access member 'TI_Value' of type 'c_CC_ESTABLISHMENT_DN' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_CC_ESTABLISHMENT_DN' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_CC_ESTABLISHMENT_DN' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_CC_ESTABLISHMENT_DN' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_DN_TI_Flag(var) (&var)

/* Access member 'SetupContainer' of type 'c_CC_ESTABLISHMENT_DN' as a variable reference */
#define VAR_c_CC_ESTABLISHMENT_DN_SetupContainer(var) var

/* Access member 'SetupContainer' of type 'c_CC_ESTABLISHMENT_DN' as a pointer */
#define PTR_c_CC_ESTABLISHMENT_DN_SetupContainer(var) (&var)


/*-A----------------------------------*/
typedef struct _c_CC_ESTABLISHMENT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SETUP_UP SetupContainer; /* ODY01a *//*GBD01b*/

}	c_CC_ESTABLISHMENT_DN;
#define INIT_c_CC_ESTABLISHMENT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_CC_ESTABLISHMENT_DN))
/*FRK03a*/
void FREE_c_CC_ESTABLISHMENT_DN(c_CC_ESTABLISHMENT_DN* sp);

/* Access member 'TI_Value' of type 'c_RELEASE_DN' as a variable reference */
#define VAR_c_RELEASE_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RELEASE_DN' as a pointer */
#define PTR_c_RELEASE_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RELEASE_DN' as a variable reference */
#define VAR_c_RELEASE_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RELEASE_DN' as a pointer */
#define PTR_c_RELEASE_DN_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_RELEASE_DN' as a variable reference */
#define VAR_c_RELEASE_DN_Cause(var) (*var)

/* Access member 'Cause' of type 'c_RELEASE_DN' as a pointer */
#define PTR_c_RELEASE_DN_Cause(var) var

/* Access member 'SecondCause' of type 'c_RELEASE_DN' as a variable reference */
#define VAR_c_RELEASE_DN_SecondCause(var) (*var)

/* Access member 'SecondCause' of type 'c_RELEASE_DN' as a pointer */
#define PTR_c_RELEASE_DN_SecondCause(var) var

/* Access member 'Facility' of type 'c_RELEASE_DN' as a variable reference */
#define VAR_c_RELEASE_DN_Facility(var) (*var)

/* Access member 'Facility' of type 'c_RELEASE_DN' as a pointer */
#define PTR_c_RELEASE_DN_Facility(var) var

/* Access member 'UserUser' of type 'c_RELEASE_DN' as a variable reference */
#define VAR_c_RELEASE_DN_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_RELEASE_DN' as a pointer */
#define PTR_c_RELEASE_DN_UserUser(var) var

/* DEFINITION OF BINARY c_RELEASE_DN_Facility */
typedef struct _c_RELEASE_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_RELEASE_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_RELEASE_DN_UserUser */
typedef struct _c_RELEASE_DN_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_RELEASE_DN_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_DN_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_RELEASE_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause *Cause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Cause_Present;
	c_Cause *SecondCause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SecondCause_Present;
	c_RELEASE_DN_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_RELEASE_DN_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;

}	c_RELEASE_DN;
#define INIT_c_RELEASE_DN(sp) ED_RESET_MEM ((sp), sizeof (c_RELEASE_DN))
/*FRK03a*/
void FREE_c_RELEASE_DN(c_RELEASE_DN* sp);
int SETPRESENT_c_RELEASE_DN_Cause (c_RELEASE_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_DN_Cause(sp) ((sp)->Cause_Present)
int SETPRESENT_c_RELEASE_DN_SecondCause (c_RELEASE_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_DN_SecondCause(sp) ((sp)->SecondCause_Present)
int SETPRESENT_c_RELEASE_DN_Facility (c_RELEASE_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_DN_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_RELEASE_DN_UserUser (c_RELEASE_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_DN_UserUser(sp) ((sp)->UserUser_Present)

/* Access member 'TI_Value' of type 'c_RECALL_DN' as a variable reference */
#define VAR_c_RECALL_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RECALL_DN' as a pointer */
#define PTR_c_RECALL_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RECALL_DN' as a variable reference */
#define VAR_c_RECALL_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RECALL_DN' as a pointer */
#define PTR_c_RECALL_DN_TI_Flag(var) (&var)

/* Access member 'RecallType' of type 'c_RECALL_DN' as a variable reference */
#define VAR_c_RECALL_DN_RecallType(var) var

/* Access member 'RecallType' of type 'c_RECALL_DN' as a pointer */
#define PTR_c_RECALL_DN_RecallType(var) (&var)

/* Access member 'Facility' of type 'c_RECALL_DN' as a variable reference */
#define VAR_c_RECALL_DN_Facility(var) var

/* Access member 'Facility' of type 'c_RECALL_DN' as a pointer */
#define PTR_c_RECALL_DN_Facility(var) (&var)

/* DEFINITION OF BINARY c_RECALL_DN_Facility */
typedef struct _c_RECALL_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4792 */
	int usedBits;
} c_RECALL_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RECALL_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_RECALL_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD02*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_RecallType RecallType; /* ODY01a *//*GBD01b*/
	c_RECALL_DN_Facility Facility; /* Static, variable size; bits needed 4792 *//*GBD01b*/

}	c_RECALL_DN;
#define INIT_c_RECALL_DN(sp) ED_RESET_MEM ((sp), sizeof (c_RECALL_DN))
/*FRK03a*/
void FREE_c_RECALL_DN(c_RECALL_DN* sp);

/* Access member 'TI_Value' of type 'c_RELEASE_COMPLETE_DN' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RELEASE_COMPLETE_DN' as a pointer */
#define PTR_c_RELEASE_COMPLETE_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RELEASE_COMPLETE_DN' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RELEASE_COMPLETE_DN' as a pointer */
#define PTR_c_RELEASE_COMPLETE_DN_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_RELEASE_COMPLETE_DN' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_DN_Cause(var) (*var)

/* Access member 'Cause' of type 'c_RELEASE_COMPLETE_DN' as a pointer */
#define PTR_c_RELEASE_COMPLETE_DN_Cause(var) var

/* Access member 'Facility' of type 'c_RELEASE_COMPLETE_DN' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_DN_Facility(var) (*var)

/* Access member 'Facility' of type 'c_RELEASE_COMPLETE_DN' as a pointer */
#define PTR_c_RELEASE_COMPLETE_DN_Facility(var) var

/* Access member 'UserUser' of type 'c_RELEASE_COMPLETE_DN' as a variable reference */
#define VAR_c_RELEASE_COMPLETE_DN_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_RELEASE_COMPLETE_DN' as a pointer */
#define PTR_c_RELEASE_COMPLETE_DN_UserUser(var) var

/* DEFINITION OF BINARY c_RELEASE_COMPLETE_DN_Facility */
typedef struct _c_RELEASE_COMPLETE_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_RELEASE_COMPLETE_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_COMPLETE_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_RELEASE_COMPLETE_DN_UserUser */
typedef struct _c_RELEASE_COMPLETE_DN_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 1032 */
	int usedBits;
} c_RELEASE_COMPLETE_DN_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_RELEASE_COMPLETE_DN_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_RELEASE_COMPLETE_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause *Cause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Cause_Present;
	c_RELEASE_COMPLETE_DN_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_RELEASE_COMPLETE_DN_UserUser* UserUser; /* Dynamic, variable size; bits needed 1032 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;

}	c_RELEASE_COMPLETE_DN;
#define INIT_c_RELEASE_COMPLETE_DN(sp) ED_RESET_MEM ((sp), sizeof (c_RELEASE_COMPLETE_DN))
/*FRK03a*/
void FREE_c_RELEASE_COMPLETE_DN(c_RELEASE_COMPLETE_DN* sp);
int SETPRESENT_c_RELEASE_COMPLETE_DN_Cause (c_RELEASE_COMPLETE_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_COMPLETE_DN_Cause(sp) ((sp)->Cause_Present)
int SETPRESENT_c_RELEASE_COMPLETE_DN_Facility (c_RELEASE_COMPLETE_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_COMPLETE_DN_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_RELEASE_COMPLETE_DN_UserUser (c_RELEASE_COMPLETE_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_RELEASE_COMPLETE_DN_UserUser(sp) ((sp)->UserUser_Present)

/* Access member 'TI_Value' of type 'c_RETRIEVE_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_RETRIEVE_ACKNOWLEDGE_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RETRIEVE_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_RETRIEVE_ACKNOWLEDGE_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RETRIEVE_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_RETRIEVE_ACKNOWLEDGE_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RETRIEVE_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_RETRIEVE_ACKNOWLEDGE_DN_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RETRIEVE_ACKNOWLEDGE_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_RETRIEVE_ACKNOWLEDGE_DN;
#define INIT_c_RETRIEVE_ACKNOWLEDGE_DN(sp) ED_RESET_MEM ((sp), sizeof (c_RETRIEVE_ACKNOWLEDGE_DN))
/*FRK03a*/
void FREE_c_RETRIEVE_ACKNOWLEDGE_DN(c_RETRIEVE_ACKNOWLEDGE_DN* sp);

/* Access member 'TI_Value' of type 'c_RETRIEVE_REJECT_DN' as a variable reference */
#define VAR_c_RETRIEVE_REJECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_RETRIEVE_REJECT_DN' as a pointer */
#define PTR_c_RETRIEVE_REJECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_RETRIEVE_REJECT_DN' as a variable reference */
#define VAR_c_RETRIEVE_REJECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_RETRIEVE_REJECT_DN' as a pointer */
#define PTR_c_RETRIEVE_REJECT_DN_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_RETRIEVE_REJECT_DN' as a variable reference */
#define VAR_c_RETRIEVE_REJECT_DN_Cause(var) var

/* Access member 'Cause' of type 'c_RETRIEVE_REJECT_DN' as a pointer */
#define PTR_c_RETRIEVE_REJECT_DN_Cause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_RETRIEVE_REJECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause Cause; /* ODY01a *//*GBD01b*/

}	c_RETRIEVE_REJECT_DN;
#define INIT_c_RETRIEVE_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_RETRIEVE_REJECT_DN))
/*FRK03a*/
void FREE_c_RETRIEVE_REJECT_DN(c_RETRIEVE_REJECT_DN* sp);

/* Access member 'TI_Value' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_TI_Flag(var) (&var)

/* Access member 'BcRepeatInd' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_BcRepeatInd(var) var

/* Access member 'BcRepeatInd' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_BcRepeatInd(var) (&var)

/* Access member 'BearerCpblty1' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_BearerCpblty1(var) (*var)

/* Access member 'BearerCpblty1' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_BearerCpblty1(var) var

/* Access member 'BearerCpblty2' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_BearerCpblty2(var) (*var)

/* Access member 'BearerCpblty2' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_BearerCpblty2(var) var

/* Access member 'Facility' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_Facility(var) (*var)

/* Access member 'Facility' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_Facility(var) var

/* Access member 'ProgrInd' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_ProgrInd(var) (*var)

/* Access member 'ProgrInd' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_ProgrInd(var) var

/* Access member 'Signal' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_Signal(var) var

/* Access member 'Signal' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_Signal(var) (&var)

/* Access member 'CallingPartyBcdNum' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_CallingPartyBcdNum(var) (*var)

/* Access member 'CallingPartyBcdNum' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_CallingPartyBcdNum(var) var

/* Access member 'CallingPartySubAddr' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_CallingPartySubAddr(var) (*var)

/* Access member 'CallingPartySubAddr' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_CallingPartySubAddr(var) var

/* Access member 'CalledPartyBcdNum' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_CalledPartyBcdNum(var) (*var)

/* Access member 'CalledPartyBcdNum' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_CalledPartyBcdNum(var) var

/* Access member 'CalledPartySubAddr' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_CalledPartySubAddr(var) (*var)

/* Access member 'CalledPartySubAddr' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_CalledPartySubAddr(var) var

/* Access member 'RedirPartyBcdNum' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_RedirPartyBcdNum(var) (*var)

/* Access member 'RedirPartyBcdNum' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_RedirPartyBcdNum(var) var

/* Access member 'RedirPartySubAddr' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_RedirPartySubAddr(var) (*var)

/* Access member 'RedirPartySubAddr' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_RedirPartySubAddr(var) var

/* Access member 'LlcRepeatInd' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_LlcRepeatInd(var) var

/* Access member 'LlcRepeatInd' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_LlcRepeatInd(var) (&var)

/* Access member 'LowLayerCpbilityI' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_LowLayerCpbilityI(var) (*var)

/* Access member 'LowLayerCpbilityI' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_LowLayerCpbilityI(var) var

/* Access member 'LowLayerCpbilityIi' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_LowLayerCpbilityIi(var) (*var)

/* Access member 'LowLayerCpbilityIi' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_LowLayerCpbilityIi(var) var

/* Access member 'HlcRepeatInd' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_HlcRepeatInd(var) var

/* Access member 'HlcRepeatInd' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_HlcRepeatInd(var) (&var)

/* Access member 'HighLayerCpbilityI' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_HighLayerCpbilityI(var) (*var)

/* Access member 'HighLayerCpbilityI' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_HighLayerCpbilityI(var) var

/* Access member 'HighLayerCpbilityIi' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_HighLayerCpbilityIi(var) (*var)

/* Access member 'HighLayerCpbilityIi' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_HighLayerCpbilityIi(var) var

/* Access member 'UserUser' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_UserUser(var) (*var)

/* Access member 'UserUser' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_UserUser(var) var

/* Access member 'Priority' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_Priority(var) (*var)

/* Access member 'Priority' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_Priority(var) var

/* Access member 'Alert' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_Alert(var) (*var)

/* Access member 'Alert' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_Alert(var) var

/* Access member 'NetwkCallControlCapabil' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_NetwkCallControlCapabil(var) (*var)

/* Access member 'NetwkCallControlCapabil' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_NetwkCallControlCapabil(var) var

/* Access member 'CauseOfNoCli' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_CauseOfNoCli(var) var

/* Access member 'CauseOfNoCli' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_CauseOfNoCli(var) (&var)

/* Access member 'BackupBearerCapability' of type 'c_SETUP_DN' as a variable reference */
#define VAR_c_SETUP_DN_BackupBearerCapability(var) (*var)

/* Access member 'BackupBearerCapability' of type 'c_SETUP_DN' as a pointer */
#define PTR_c_SETUP_DN_BackupBearerCapability(var) var

/* DEFINITION OF BINARY c_SETUP_DN_Facility */
typedef struct _c_SETUP_DN_Facility {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_SETUP_DN_Facility;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_DN_Facility(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_DN_LowLayerCpbilityI */
typedef struct _c_SETUP_DN_LowLayerCpbilityI {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_SETUP_DN_LowLayerCpbilityI;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_DN_LowLayerCpbilityI(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_DN_LowLayerCpbilityIi */
typedef struct _c_SETUP_DN_LowLayerCpbilityIi {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_SETUP_DN_LowLayerCpbilityIi;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_DN_LowLayerCpbilityIi(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_SETUP_DN_UserUser */
typedef struct _c_SETUP_DN_UserUser {
	ED_BYTE* value; /* Variable size; bits needed 264 */
	int usedBits;
} c_SETUP_DN_UserUser;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SETUP_DN_UserUser(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SETUP_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR BcRepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR Facility___LOCATOR  /*LBD01*/;
	ED_LOCATOR Signal___LOCATOR; /* QUI2 */
	ED_LOCATOR LlcRepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR LowLayerCpbilityI___LOCATOR  /*LBD01*/;
	ED_LOCATOR LowLayerCpbilityIi___LOCATOR  /*LBD01*/;
	ED_LOCATOR HlcRepeatInd___LOCATOR; /* QUI2 */
	ED_LOCATOR UserUser___LOCATOR  /*LBD01*/;
	ED_LOCATOR CauseOfNoCli___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET BcRepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN BcRepeatInd_Present;
	c_BearerCpblty *BearerCpblty1; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty1_Present;
	c_BearerCpblty *BearerCpblty2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BearerCpblty2_Present;
	c_SETUP_DN_Facility* Facility; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN Facility_Present;
	c_ProgrInd *ProgrInd; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProgrInd_Present;
	ED_OCTET Signal; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Signal_Present;
	c_CallingPartyBcdNum *CallingPartyBcdNum; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CallingPartyBcdNum_Present;
	c_CallingPartySubaddr *CallingPartySubAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CallingPartySubAddr_Present;
	c_CalledPartyBcdNum *CalledPartyBcdNum; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CalledPartyBcdNum_Present;
	c_CalledPartySubaddr *CalledPartySubAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CalledPartySubAddr_Present;
	c_RedirPartyBcdNum *RedirPartyBcdNum; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RedirPartyBcdNum_Present;
	c_RedirPartySubaddr *RedirPartySubAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RedirPartySubAddr_Present;
	ED_OCTET LlcRepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LlcRepeatInd_Present;
	c_SETUP_DN_LowLayerCpbilityI* LowLayerCpbilityI; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN LowLayerCpbilityI_Present;
	c_SETUP_DN_LowLayerCpbilityIi* LowLayerCpbilityIi; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN LowLayerCpbilityIi_Present;
	ED_OCTET HlcRepeatInd; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HlcRepeatInd_Present;
	c_HighLayerCpbility *HighLayerCpbilityI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HighLayerCpbilityI_Present;
	c_HighLayerCpbility *HighLayerCpbilityIi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HighLayerCpbilityIi_Present;
	c_SETUP_DN_UserUser* UserUser; /* Dynamic, variable size; bits needed 264 ODY02b *//*GBD01b*/
	ED_BOOLEAN UserUser_Present;
	c_PriorityLevel *Priority; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Priority_Present;
	c_AlertingPattern *Alert; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Alert_Present;
	c_NetwkCallControlCapabil *NetwkCallControlCapabil; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NetwkCallControlCapabil_Present;
	ED_OCTET CauseOfNoCli; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CauseOfNoCli_Present;
	c_BackupBearerCapability *BackupBearerCapability; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BackupBearerCapability_Present;

}	c_SETUP_DN;
#define INIT_c_SETUP_DN(sp) ED_RESET_MEM ((sp), sizeof (c_SETUP_DN))
/*FRK03a*/
void FREE_c_SETUP_DN(c_SETUP_DN* sp);
#define SETPRESENT_c_SETUP_DN_BcRepeatInd(sp,present) (((sp)->BcRepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_DN_BcRepeatInd(sp) ((sp)->BcRepeatInd_Present)
int SETPRESENT_c_SETUP_DN_BearerCpblty1 (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_BearerCpblty1(sp) ((sp)->BearerCpblty1_Present)
int SETPRESENT_c_SETUP_DN_BearerCpblty2 (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_BearerCpblty2(sp) ((sp)->BearerCpblty2_Present)
int SETPRESENT_c_SETUP_DN_Facility (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_Facility(sp) ((sp)->Facility_Present)
int SETPRESENT_c_SETUP_DN_ProgrInd (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_ProgrInd(sp) ((sp)->ProgrInd_Present)
#define SETPRESENT_c_SETUP_DN_Signal(sp,present) (((sp)->Signal_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_DN_Signal(sp) ((sp)->Signal_Present)
int SETPRESENT_c_SETUP_DN_CallingPartyBcdNum (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_CallingPartyBcdNum(sp) ((sp)->CallingPartyBcdNum_Present)
int SETPRESENT_c_SETUP_DN_CallingPartySubAddr (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_CallingPartySubAddr(sp) ((sp)->CallingPartySubAddr_Present)
int SETPRESENT_c_SETUP_DN_CalledPartyBcdNum (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_CalledPartyBcdNum(sp) ((sp)->CalledPartyBcdNum_Present)
int SETPRESENT_c_SETUP_DN_CalledPartySubAddr (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_CalledPartySubAddr(sp) ((sp)->CalledPartySubAddr_Present)
int SETPRESENT_c_SETUP_DN_RedirPartyBcdNum (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_RedirPartyBcdNum(sp) ((sp)->RedirPartyBcdNum_Present)
int SETPRESENT_c_SETUP_DN_RedirPartySubAddr (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_RedirPartySubAddr(sp) ((sp)->RedirPartySubAddr_Present)
#define SETPRESENT_c_SETUP_DN_LlcRepeatInd(sp,present) (((sp)->LlcRepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_DN_LlcRepeatInd(sp) ((sp)->LlcRepeatInd_Present)
int SETPRESENT_c_SETUP_DN_LowLayerCpbilityI (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_LowLayerCpbilityI(sp) ((sp)->LowLayerCpbilityI_Present)
int SETPRESENT_c_SETUP_DN_LowLayerCpbilityIi (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_LowLayerCpbilityIi(sp) ((sp)->LowLayerCpbilityIi_Present)
#define SETPRESENT_c_SETUP_DN_HlcRepeatInd(sp,present) (((sp)->HlcRepeatInd_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_DN_HlcRepeatInd(sp) ((sp)->HlcRepeatInd_Present)
int SETPRESENT_c_SETUP_DN_HighLayerCpbilityI (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_HighLayerCpbilityI(sp) ((sp)->HighLayerCpbilityI_Present)
int SETPRESENT_c_SETUP_DN_HighLayerCpbilityIi (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_HighLayerCpbilityIi(sp) ((sp)->HighLayerCpbilityIi_Present)
int SETPRESENT_c_SETUP_DN_UserUser (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_UserUser(sp) ((sp)->UserUser_Present)
int SETPRESENT_c_SETUP_DN_Priority (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_Priority(sp) ((sp)->Priority_Present)
int SETPRESENT_c_SETUP_DN_Alert (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_Alert(sp) ((sp)->Alert_Present)
int SETPRESENT_c_SETUP_DN_NetwkCallControlCapabil (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_NetwkCallControlCapabil(sp) ((sp)->NetwkCallControlCapabil_Present)
#define SETPRESENT_c_SETUP_DN_CauseOfNoCli(sp,present) (((sp)->CauseOfNoCli_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SETUP_DN_CauseOfNoCli(sp) ((sp)->CauseOfNoCli_Present)
int SETPRESENT_c_SETUP_DN_BackupBearerCapability (c_SETUP_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SETUP_DN_BackupBearerCapability(sp) ((sp)->BackupBearerCapability_Present)

/* Access member 'TI_Value' of type 'c_START_DTMF_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_START_DTMF_ACKNOWLEDGE_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_START_DTMF_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_START_DTMF_ACKNOWLEDGE_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_START_DTMF_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_START_DTMF_ACKNOWLEDGE_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_START_DTMF_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_START_DTMF_ACKNOWLEDGE_DN_TI_Flag(var) (&var)

/* Access member 'KeypadFacility' of type 'c_START_DTMF_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_START_DTMF_ACKNOWLEDGE_DN_KeypadFacility(var) var

/* Access member 'KeypadFacility' of type 'c_START_DTMF_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_START_DTMF_ACKNOWLEDGE_DN_KeypadFacility(var) (&var)


/*-A----------------------------------*/
typedef struct _c_START_DTMF_ACKNOWLEDGE_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_KeypadFacility KeypadFacility; /* ODY01a *//*GBD01b*/

}	c_START_DTMF_ACKNOWLEDGE_DN;
#define INIT_c_START_DTMF_ACKNOWLEDGE_DN(sp) ED_RESET_MEM ((sp), sizeof (c_START_DTMF_ACKNOWLEDGE_DN))
/*FRK03a*/
void FREE_c_START_DTMF_ACKNOWLEDGE_DN(c_START_DTMF_ACKNOWLEDGE_DN* sp);

/* Access member 'TI_Value' of type 'c_START_DTMF_REJECT_DN' as a variable reference */
#define VAR_c_START_DTMF_REJECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_START_DTMF_REJECT_DN' as a pointer */
#define PTR_c_START_DTMF_REJECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_START_DTMF_REJECT_DN' as a variable reference */
#define VAR_c_START_DTMF_REJECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_START_DTMF_REJECT_DN' as a pointer */
#define PTR_c_START_DTMF_REJECT_DN_TI_Flag(var) (&var)

/* Access member 'Cause' of type 'c_START_DTMF_REJECT_DN' as a variable reference */
#define VAR_c_START_DTMF_REJECT_DN_Cause(var) var

/* Access member 'Cause' of type 'c_START_DTMF_REJECT_DN' as a pointer */
#define PTR_c_START_DTMF_REJECT_DN_Cause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_START_DTMF_REJECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_Cause Cause; /* ODY01a *//*GBD01b*/

}	c_START_DTMF_REJECT_DN;
#define INIT_c_START_DTMF_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_START_DTMF_REJECT_DN))
/*FRK03a*/
void FREE_c_START_DTMF_REJECT_DN(c_START_DTMF_REJECT_DN* sp);

/* Access member 'TI_Value' of type 'c_STOP_DTMF_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_STOP_DTMF_ACKNOWLEDGE_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_STOP_DTMF_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_STOP_DTMF_ACKNOWLEDGE_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_STOP_DTMF_ACKNOWLEDGE_DN' as a variable reference */
#define VAR_c_STOP_DTMF_ACKNOWLEDGE_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_STOP_DTMF_ACKNOWLEDGE_DN' as a pointer */
#define PTR_c_STOP_DTMF_ACKNOWLEDGE_DN_TI_Flag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_STOP_DTMF_ACKNOWLEDGE_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/

}	c_STOP_DTMF_ACKNOWLEDGE_DN;
#define INIT_c_STOP_DTMF_ACKNOWLEDGE_DN(sp) ED_RESET_MEM ((sp), sizeof (c_STOP_DTMF_ACKNOWLEDGE_DN))
/*FRK03a*/
void FREE_c_STOP_DTMF_ACKNOWLEDGE_DN(c_STOP_DTMF_ACKNOWLEDGE_DN* sp);

/* Access member 'AttachResult' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_AttachResult(var) var

/* Access member 'AttachResult' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_AttachResult(var) (&var)

/* Access member 'ForceToStandby' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_ForceToStandby(var) (&var)

/* Access member 'PeriodicRaUpdateTimer' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_PeriodicRaUpdateTimer(var) var

/* Access member 'PeriodicRaUpdateTimer' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_PeriodicRaUpdateTimer(var) (&var)

/* Access member 'RadioPriorityForSms' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_RadioPriorityForSms(var) var

/* Access member 'RadioPriorityForSms' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_RadioPriorityForSms(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_SpareHalfOctet(var) (&var)

/* Access member 'RoutingAreaId' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_RoutingAreaId(var) var

/* Access member 'RoutingAreaId' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_RoutingAreaId(var) (&var)

/* Access member 'PTmsiSign' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_PTmsiSign(var) (*var)

/* Access member 'PTmsiSign' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_PTmsiSign(var) var

/* Access member 'NegotiatedRdyTimerValue' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue(var) (*var)

/* Access member 'NegotiatedRdyTimerValue' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue(var) var

/* Access member 'AllocatedPTmsi' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_AllocatedPTmsi(var) (*var)

/* Access member 'AllocatedPTmsi' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_AllocatedPTmsi(var) var

/* Access member 'MsId' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_MsId(var) (*var)

/* Access member 'MsId' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_MsId(var) var

/* Access member 'GmmCause' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_GmmCause(var) (&var)

/* Access member 'T3302Value' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_T3302Value(var) (*var)

/* Access member 'T3302Value' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_T3302Value(var) var

/* Access member 'CellNotif' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_CellNotif(var) var

/* Access member 'CellNotif' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_CellNotif(var) (&var)

/* Access member 'EquivPlmns' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_EquivPlmns(var) (*var)

/* Access member 'EquivPlmns' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_EquivPlmns(var) var

/* Access member 'NetworkFeatureSupport' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport(var) (*var)

/* Access member 'NetworkFeatureSupport' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport(var) var

/* Access member 'EmergencyNumberList' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_EmergencyNumberList(var) (*var)

/* Access member 'EmergencyNumberList' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_EmergencyNumberList(var) var

/* Access member 'RequestedMSInformation' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_RequestedMSInformation(var) (*var)

/* Access member 'RequestedMSInformation' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_RequestedMSInformation(var) var

/* Access member 'T3319Value' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_T3319Value(var) (*var)

/* Access member 'T3319Value' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_T3319Value(var) var

/* Access member 'T3323Value' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_T3323Value(var) (*var)

/* Access member 'T3323Value' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_T3323Value(var) var

/* Access member 'T3312ExtendedValue' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_T3312ExtendedValue(var) (*var)

/* Access member 'T3312ExtendedValue' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_T3312ExtendedValue(var) var

/* Access member 'AdditionalNetworkFeatureSupport' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport(var) (*var)

/* Access member 'AdditionalNetworkFeatureSupport' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport(var) var

/* Access member 'T3324Value' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_T3324Value(var) (*var)

/* Access member 'T3324Value' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_T3324Value(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_ACCEPT_DN' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_ACCEPT_DN' as a pointer */
#define PTR_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters(var) var


/*-A----------------------------------*/
typedef struct _c_ATTACH_ACCEPT_DN {
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */
	ED_LOCATOR RadioPriorityForSms___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR PTmsiSign___LOCATOR  /*LBD01*/;
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */

	c_AttachResult AttachResult; /* ODY01a *//*GBD01b*/
	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/
	c_GprsTimer PeriodicRaUpdateTimer; /* ODY01a *//*GBD01b*/
	ED_OCTET RadioPriorityForSms; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_RoutingAreaIdenti RoutingAreaId; /* ODY01a *//*GBD01b*/
	ED_BYTE* PTmsiSign; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN PTmsiSign_Present;
	c_GprsTimer *NegotiatedRdyTimerValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedRdyTimerValue_Present;
	c_MobileId *AllocatedPTmsi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AllocatedPTmsi_Present;
	c_MobileId *MsId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MsId_Present;
	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GmmCause_Present;
	c_GprsTimer2 *T3302Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3302Value_Present;
	/*GBD01b*/
	ED_BOOLEAN CellNotif_Present;
	c_PlmnList *EquivPlmns; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EquivPlmns_Present;
	c_NetworkFeatureSupport *NetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NetworkFeatureSupport_Present;
	c_EmergencyNumberList *EmergencyNumberList; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EmergencyNumberList_Present;
	c_RequestedMSInformation *RequestedMSInformation; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RequestedMSInformation_Present;
	c_GprsTimer2 *T3319Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3319Value_Present;
	c_GprsTimer2 *T3323Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3323Value_Present;
	c_GprsTimer3 *T3312ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3312ExtendedValue_Present;
	c_AdditionalNetworkFeatureSupport *AdditionalNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalNetworkFeatureSupport_Present;
	c_GprsTimer2 *T3324Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324Value_Present;
	c_ExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;

}	c_ATTACH_ACCEPT_DN;
#define INIT_c_ATTACH_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_ACCEPT_DN))
/*FRK03a*/
void FREE_c_ATTACH_ACCEPT_DN(c_ATTACH_ACCEPT_DN* sp);
int SETPRESENT_c_ATTACH_ACCEPT_DN_PTmsiSign (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_PTmsiSign(sp) ((sp)->PTmsiSign_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_NegotiatedRdyTimerValue(sp) ((sp)->NegotiatedRdyTimerValue_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_AllocatedPTmsi (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_AllocatedPTmsi(sp) ((sp)->AllocatedPTmsi_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_MsId (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_MsId(sp) ((sp)->MsId_Present)
#define SETPRESENT_c_ATTACH_ACCEPT_DN_GmmCause(sp,present) (((sp)->GmmCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ATTACH_ACCEPT_DN_GmmCause(sp) ((sp)->GmmCause_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_T3302Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_T3302Value(sp) ((sp)->T3302Value_Present)
#define SETPRESENT_c_ATTACH_ACCEPT_DN_CellNotif(sp,present) (((sp)->CellNotif_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ATTACH_ACCEPT_DN_CellNotif(sp) ((sp)->CellNotif_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_EquivPlmns (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_EquivPlmns(sp) ((sp)->EquivPlmns_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_NetworkFeatureSupport(sp) ((sp)->NetworkFeatureSupport_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_EmergencyNumberList (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_EmergencyNumberList(sp) ((sp)->EmergencyNumberList_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_RequestedMSInformation (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_RequestedMSInformation(sp) ((sp)->RequestedMSInformation_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_T3319Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_T3319Value(sp) ((sp)->T3319Value_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_T3323Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_T3323Value(sp) ((sp)->T3323Value_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_T3312ExtendedValue (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_T3312ExtendedValue(sp) ((sp)->T3312ExtendedValue_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_AdditionalNetworkFeatureSupport(sp) ((sp)->AdditionalNetworkFeatureSupport_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_T3324Value (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_T3324Value(sp) ((sp)->T3324Value_Present)
int SETPRESENT_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters (c_ATTACH_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_DN_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)

/* Access member 'GmmCause' of type 'c_ATTACH_REJECT_DN' as a variable reference */
#define VAR_c_ATTACH_REJECT_DN_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_ATTACH_REJECT_DN' as a pointer */
#define PTR_c_ATTACH_REJECT_DN_GmmCause(var) (&var)

/* Access member 'T3302Value' of type 'c_ATTACH_REJECT_DN' as a variable reference */
#define VAR_c_ATTACH_REJECT_DN_T3302Value(var) (*var)

/* Access member 'T3302Value' of type 'c_ATTACH_REJECT_DN' as a pointer */
#define PTR_c_ATTACH_REJECT_DN_T3302Value(var) var

/* Access member 'T3346Value' of type 'c_ATTACH_REJECT_DN' as a variable reference */
#define VAR_c_ATTACH_REJECT_DN_T3346Value(var) (*var)

/* Access member 'T3346Value' of type 'c_ATTACH_REJECT_DN' as a pointer */
#define PTR_c_ATTACH_REJECT_DN_T3346Value(var) var


/*-A----------------------------------*/
typedef struct _c_ATTACH_REJECT_DN {
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */

	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/
	c_GprsTimer2 *T3302Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3302Value_Present;
	c_GprsTimer2 *T3346Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3346Value_Present;

}	c_ATTACH_REJECT_DN;
#define INIT_c_ATTACH_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_REJECT_DN))
/*FRK03a*/
void FREE_c_ATTACH_REJECT_DN(c_ATTACH_REJECT_DN* sp);
int SETPRESENT_c_ATTACH_REJECT_DN_T3302Value (c_ATTACH_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REJECT_DN_T3302Value(sp) ((sp)->T3302Value_Present)
int SETPRESENT_c_ATTACH_REJECT_DN_T3346Value (c_ATTACH_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REJECT_DN_T3346Value(sp) ((sp)->T3346Value_Present)

/* Access member 'DetachType' of type 'c_DETACH_REQUEST_DN' as a variable reference */
#define VAR_c_DETACH_REQUEST_DN_DetachType(var) var

/* Access member 'DetachType' of type 'c_DETACH_REQUEST_DN' as a pointer */
#define PTR_c_DETACH_REQUEST_DN_DetachType(var) (&var)

/* Access member 'ForceToStandby' of type 'c_DETACH_REQUEST_DN' as a variable reference */
#define VAR_c_DETACH_REQUEST_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_DETACH_REQUEST_DN' as a pointer */
#define PTR_c_DETACH_REQUEST_DN_ForceToStandby(var) (&var)

/* Access member 'GmmCause' of type 'c_DETACH_REQUEST_DN' as a variable reference */
#define VAR_c_DETACH_REQUEST_DN_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_DETACH_REQUEST_DN' as a pointer */
#define PTR_c_DETACH_REQUEST_DN_GmmCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_DETACH_REQUEST_DN {
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */

	c_DetachType DetachType; /* ODY01a *//*GBD01b*/
	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/
	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GmmCause_Present;

}	c_DETACH_REQUEST_DN;
#define INIT_c_DETACH_REQUEST_DN(sp) ED_RESET_MEM ((sp), sizeof (c_DETACH_REQUEST_DN))
/*FRK03a*/
void FREE_c_DETACH_REQUEST_DN(c_DETACH_REQUEST_DN* sp);
#define SETPRESENT_c_DETACH_REQUEST_DN_GmmCause(sp,present) (((sp)->GmmCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_DETACH_REQUEST_DN_GmmCause(sp) ((sp)->GmmCause_Present)

/* Access member 'ForceToStandby' of type 'c_DETACH_ACCEPT_DN' as a variable reference */
#define VAR_c_DETACH_ACCEPT_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_DETACH_ACCEPT_DN' as a pointer */
#define PTR_c_DETACH_ACCEPT_DN_ForceToStandby(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_DETACH_ACCEPT_DN' as a variable reference */
#define VAR_c_DETACH_ACCEPT_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_DETACH_ACCEPT_DN' as a pointer */
#define PTR_c_DETACH_ACCEPT_DN_SpareHalfOctet(var) (&var)


/*-A----------------------------------*/
typedef struct _c_DETACH_ACCEPT_DN {
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */

	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/

}	c_DETACH_ACCEPT_DN;
#define INIT_c_DETACH_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_DETACH_ACCEPT_DN))
/*FRK03a*/
void FREE_c_DETACH_ACCEPT_DN(c_DETACH_ACCEPT_DN* sp);

/* Access member 'AllocatedPTmsi' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a variable reference */
#define VAR_c_P_TMSI_REALLOCATION_COMMAND_DN_AllocatedPTmsi(var) var

/* Access member 'AllocatedPTmsi' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a pointer */
#define PTR_c_P_TMSI_REALLOCATION_COMMAND_DN_AllocatedPTmsi(var) (&var)

/* Access member 'RoutingAreaId' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a variable reference */
#define VAR_c_P_TMSI_REALLOCATION_COMMAND_DN_RoutingAreaId(var) var

/* Access member 'RoutingAreaId' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a pointer */
#define PTR_c_P_TMSI_REALLOCATION_COMMAND_DN_RoutingAreaId(var) (&var)

/* Access member 'ForceToStandby' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a variable reference */
#define VAR_c_P_TMSI_REALLOCATION_COMMAND_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a pointer */
#define PTR_c_P_TMSI_REALLOCATION_COMMAND_DN_ForceToStandby(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a variable reference */
#define VAR_c_P_TMSI_REALLOCATION_COMMAND_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a pointer */
#define PTR_c_P_TMSI_REALLOCATION_COMMAND_DN_SpareHalfOctet(var) (&var)

/* Access member 'PTmsiSign' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a variable reference */
#define VAR_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign(var) (*var)

/* Access member 'PTmsiSign' of type 'c_P_TMSI_REALLOCATION_COMMAND_DN' as a pointer */
#define PTR_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign(var) var


/*-A----------------------------------*/
typedef struct _c_P_TMSI_REALLOCATION_COMMAND_DN {
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR PTmsiSign___LOCATOR  /*LBD01*/;

	c_MobileId AllocatedPTmsi; /* ODY01a *//*GBD01b*/
	c_RoutingAreaIdenti RoutingAreaId; /* ODY01a *//*GBD01b*/
	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	ED_BYTE* PTmsiSign; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN PTmsiSign_Present;

}	c_P_TMSI_REALLOCATION_COMMAND_DN;
#define INIT_c_P_TMSI_REALLOCATION_COMMAND_DN(sp) ED_RESET_MEM ((sp), sizeof (c_P_TMSI_REALLOCATION_COMMAND_DN))
/*FRK03a*/
void FREE_c_P_TMSI_REALLOCATION_COMMAND_DN(c_P_TMSI_REALLOCATION_COMMAND_DN* sp);
int SETPRESENT_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign (c_P_TMSI_REALLOCATION_COMMAND_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_P_TMSI_REALLOCATION_COMMAND_DN_PTmsiSign(sp) ((sp)->PTmsiSign_Present)

/* Access member 'CiphAlg' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_CiphAlg(var) var

/* Access member 'CiphAlg' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_CiphAlg(var) (&var)

/* Access member 'ImeisvReq' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_ImeisvReq(var) var

/* Access member 'ImeisvReq' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_ImeisvReq(var) (&var)

/* Access member 'ForceToStandby' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_ForceToStandby(var) (&var)

/* Access member 'ACRefNum' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_ACRefNum(var) var

/* Access member 'ACRefNum' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_ACRefNum(var) (&var)

/* Access member 'AuthParamRand' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand(var) (*var)

/* Access member 'AuthParamRand' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand(var) var

/* Access member 'GprsCiphKeySequenceNum' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_GprsCiphKeySequenceNum(var) var

/* Access member 'GprsCiphKeySequenceNum' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_GprsCiphKeySequenceNum(var) (&var)

/* Access member 'AuthParamAutn' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn(var) (*var)

/* Access member 'AuthParamAutn' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn(var) var

/* Access member 'MsNetwkCpblty' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty(var) (*var)

/* Access member 'MsNetwkCpblty' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty(var) var

/* Access member 'IntegrityProtectionAlgorithm' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm(var) (*var)

/* Access member 'IntegrityProtectionAlgorithm' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm(var) var

/* Access member 'MessageAuthCode' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a variable reference */
#define VAR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode(var) var

/* Access member 'MessageAuthCode' of type 'c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN' as a pointer */
#define PTR_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN {
	ED_LOCATOR CiphAlg___LOCATOR; /* QUI2 */
	ED_LOCATOR ImeisvReq___LOCATOR; /* QUI2 */
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */
	ED_LOCATOR ACRefNum___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthParamRand___LOCATOR  /*LBD01*/;
	ED_LOCATOR GprsCiphKeySequenceNum___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthParamAutn___LOCATOR  /*LBD01*/;
	ED_LOCATOR MessageAuthCode___LOCATOR; /* QUI2 */

	ED_OCTET CiphAlg; /* ODY01a *//*GBD01b*/
	ED_OCTET ImeisvReq; /* ODY01a *//*GBD01b*/
	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/
	ED_OCTET ACRefNum; /* ODY01a *//*GBD01b*/
	ED_BYTE* AuthParamRand; /* Dynamic, fixed size; bits needed: 128 ODY02a *//*GBD01b*/
	ED_BOOLEAN AuthParamRand_Present;
	ED_OCTET GprsCiphKeySequenceNum; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GprsCiphKeySequenceNum_Present;
	ED_BYTE* AuthParamAutn; /* Dynamic, fixed size; bits needed: 128 ODY02a *//*GBD01b*/
	ED_BOOLEAN AuthParamAutn_Present;
	c_MsNetwkCpblty *MsNetwkCpblty; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MsNetwkCpblty_Present;
	c_IntegrityProtectionAlgorithm *IntegrityProtectionAlgorithm; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN IntegrityProtectionAlgorithm_Present;
	ED_LONG MessageAuthCode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN MessageAuthCode_Present;

}	c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN;
#define INIT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN))
/*FRK03a*/
void FREE_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN(c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp);
int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamRand(sp) ((sp)->AuthParamRand_Present)
#define SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_GprsCiphKeySequenceNum(sp,present) (((sp)->GprsCiphKeySequenceNum_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_GprsCiphKeySequenceNum(sp) ((sp)->GprsCiphKeySequenceNum_Present)
int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_AuthParamAutn(sp) ((sp)->AuthParamAutn_Present)
int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MsNetwkCpblty(sp) ((sp)->MsNetwkCpblty_Present)
int SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm (c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_IntegrityProtectionAlgorithm(sp) ((sp)->IntegrityProtectionAlgorithm_Present)
#define SETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode(sp,present) (((sp)->MessageAuthCode_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_AUTHENTICATION_AND_CIPHERING_REQUEST_DN_MessageAuthCode(sp) ((sp)->MessageAuthCode_Present)


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_AND_CIPHERING_REJECT_DN {

	int __Dummy_Field__; /* Added to avoid empty structures/unions/etc */
}	c_AUTHENTICATION_AND_CIPHERING_REJECT_DN;
#define INIT_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_AND_CIPHERING_REJECT_DN))
/*FRK03a*/
void FREE_c_AUTHENTICATION_AND_CIPHERING_REJECT_DN(c_AUTHENTICATION_AND_CIPHERING_REJECT_DN* sp);

/* Access member 'IdType' of type 'c_IDENTITY_REQUEST_B_DN' as a variable reference */
#define VAR_c_IDENTITY_REQUEST_B_DN_IdType(var) var

/* Access member 'IdType' of type 'c_IDENTITY_REQUEST_B_DN' as a pointer */
#define PTR_c_IDENTITY_REQUEST_B_DN_IdType(var) (&var)

/* Access member 'ForceToStandby' of type 'c_IDENTITY_REQUEST_B_DN' as a variable reference */
#define VAR_c_IDENTITY_REQUEST_B_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_IDENTITY_REQUEST_B_DN' as a pointer */
#define PTR_c_IDENTITY_REQUEST_B_DN_ForceToStandby(var) (&var)


/*-A----------------------------------*/
typedef struct _c_IDENTITY_REQUEST_B_DN {
	ED_LOCATOR IdType___LOCATOR; /* QUI2 */
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */

	ED_OCTET IdType; /* ODY01a *//*GBD01b*/
	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/

}	c_IDENTITY_REQUEST_B_DN;
#define INIT_c_IDENTITY_REQUEST_B_DN(sp) ED_RESET_MEM ((sp), sizeof (c_IDENTITY_REQUEST_B_DN))
/*FRK03a*/
void FREE_c_IDENTITY_REQUEST_B_DN(c_IDENTITY_REQUEST_B_DN* sp);

/* Access member 'ForceToStandby' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ForceToStandby(var) (&var)

/* Access member 'UpdateResult' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_UpdateResult(var) var

/* Access member 'UpdateResult' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_UpdateResult(var) (&var)

/* Access member 'PeriodicRaUpdateTimer' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PeriodicRaUpdateTimer(var) var

/* Access member 'PeriodicRaUpdateTimer' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PeriodicRaUpdateTimer(var) (&var)

/* Access member 'RoutingAreaId' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RoutingAreaId(var) var

/* Access member 'RoutingAreaId' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RoutingAreaId(var) (&var)

/* Access member 'PTmsiSign' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign(var) (*var)

/* Access member 'PTmsiSign' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign(var) var

/* Access member 'AllocatedPTmsi' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi(var) (*var)

/* Access member 'AllocatedPTmsi' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi(var) var

/* Access member 'MsId' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId(var) (*var)

/* Access member 'MsId' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId(var) var

/* Access member 'ListOfReceiveNPduNumbers' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers(var) (*var)

/* Access member 'ListOfReceiveNPduNumbers' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers(var) var

/* Access member 'NegotiatedRdyTimerValue' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue(var) (*var)

/* Access member 'NegotiatedRdyTimerValue' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue(var) var

/* Access member 'GmmCause' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_GmmCause(var) (&var)

/* Access member 'T3302Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value(var) (*var)

/* Access member 'T3302Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value(var) var

/* Access member 'CellNotif' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_CellNotif(var) var

/* Access member 'CellNotif' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_CellNotif(var) (&var)

/* Access member 'EquivPlmns' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns(var) (*var)

/* Access member 'EquivPlmns' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns(var) var

/* Access member 'PdpContextStatus' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus(var) (*var)

/* Access member 'PdpContextStatus' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus(var) var

/* Access member 'NetworkFeatureSupport' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport(var) (*var)

/* Access member 'NetworkFeatureSupport' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport(var) var

/* Access member 'EmergencyNumberList' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList(var) (*var)

/* Access member 'EmergencyNumberList' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList(var) var

/* Access member 'MBMSContextStatus' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus(var) (*var)

/* Access member 'MBMSContextStatus' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus(var) var

/* Access member 'RequestedMSInformation' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation(var) (*var)

/* Access member 'RequestedMSInformation' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation(var) var

/* Access member 'T3319Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value(var) (*var)

/* Access member 'T3319Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value(var) var

/* Access member 'T3323Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value(var) (*var)

/* Access member 'T3323Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value(var) var

/* Access member 'T3312ExtendedValue' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue(var) (*var)

/* Access member 'T3312ExtendedValue' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue(var) var

/* Access member 'AdditionalNetworkFeatureSupport' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport(var) (*var)

/* Access member 'AdditionalNetworkFeatureSupport' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport(var) var

/* Access member 'T3324Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value(var) (*var)

/* Access member 'T3324Value' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_ROUTING_AREA_UPDATE_ACCEPT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters(var) var

/* DEFINITION OF BINARY c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus */
typedef struct _c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ROUTING_AREA_UPDATE_ACCEPT_DN {
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */
	ED_LOCATOR UpdateResult___LOCATOR; /* QUI2 */
	ED_LOCATOR PTmsiSign___LOCATOR  /*LBD01*/;
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSContextStatus___LOCATOR  /*LBD01*/;

	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/
	ED_OCTET UpdateResult; /* ODY01a *//*GBD01b*/
	c_GprsTimer PeriodicRaUpdateTimer; /* ODY01a *//*GBD01b*/
	c_RoutingAreaIdenti RoutingAreaId; /* ODY01a *//*GBD01b*/
	ED_BYTE* PTmsiSign; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN PTmsiSign_Present;
	c_MobileId *AllocatedPTmsi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AllocatedPTmsi_Present;
	c_MobileId *MsId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MsId_Present;
	c_ReceiveNPduNumbersList *ListOfReceiveNPduNumbers; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ListOfReceiveNPduNumbers_Present;
	c_GprsTimer *NegotiatedRdyTimerValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedRdyTimerValue_Present;
	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GmmCause_Present;
	c_GprsTimer2 *T3302Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3302Value_Present;
	/*GBD01b*/
	ED_BOOLEAN CellNotif_Present;
	c_PlmnList *EquivPlmns; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EquivPlmns_Present;
	c_PdpContextStatus *PdpContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PdpContextStatus_Present;
	c_NetworkFeatureSupport *NetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NetworkFeatureSupport_Present;
	c_EmergencyNumberList *EmergencyNumberList; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EmergencyNumberList_Present;
	c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus* MBMSContextStatus; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSContextStatus_Present;
	c_RequestedMSInformation *RequestedMSInformation; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RequestedMSInformation_Present;
	c_GprsTimer2 *T3319Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3319Value_Present;
	c_GprsTimer2 *T3323Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3323Value_Present;
	c_GprsTimer3 *T3312ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3312ExtendedValue_Present;
	c_AdditionalNetworkFeatureSupport *AdditionalNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalNetworkFeatureSupport_Present;
	c_GprsTimer2 *T3324Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324Value_Present;
	c_ExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;

}	c_ROUTING_AREA_UPDATE_ACCEPT_DN;
#define INIT_c_ROUTING_AREA_UPDATE_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ROUTING_AREA_UPDATE_ACCEPT_DN))
/*FRK03a*/
void FREE_c_ROUTING_AREA_UPDATE_ACCEPT_DN(c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp);
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PTmsiSign(sp) ((sp)->PTmsiSign_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AllocatedPTmsi(sp) ((sp)->AllocatedPTmsi_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MsId(sp) ((sp)->MsId_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ListOfReceiveNPduNumbers(sp) ((sp)->ListOfReceiveNPduNumbers_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NegotiatedRdyTimerValue(sp) ((sp)->NegotiatedRdyTimerValue_Present)
#define SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_GmmCause(sp,present) (((sp)->GmmCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_GmmCause(sp) ((sp)->GmmCause_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3302Value(sp) ((sp)->T3302Value_Present)
#define SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_CellNotif(sp,present) (((sp)->CellNotif_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_CellNotif(sp) ((sp)->CellNotif_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EquivPlmns(sp) ((sp)->EquivPlmns_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_PdpContextStatus(sp) ((sp)->PdpContextStatus_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_NetworkFeatureSupport(sp) ((sp)->NetworkFeatureSupport_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_EmergencyNumberList(sp) ((sp)->EmergencyNumberList_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_MBMSContextStatus(sp) ((sp)->MBMSContextStatus_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_RequestedMSInformation(sp) ((sp)->RequestedMSInformation_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3319Value(sp) ((sp)->T3319Value_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3323Value(sp) ((sp)->T3323Value_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3312ExtendedValue(sp) ((sp)->T3312ExtendedValue_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_AdditionalNetworkFeatureSupport(sp) ((sp)->AdditionalNetworkFeatureSupport_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_T3324Value(sp) ((sp)->T3324Value_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters (c_ROUTING_AREA_UPDATE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_ACCEPT_DN_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)

/* Access member 'GmmCause' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REJECT_DN_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REJECT_DN_GmmCause(var) (&var)

/* Access member 'ForceToStandby' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REJECT_DN_ForceToStandby(var) var

/* Access member 'ForceToStandby' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REJECT_DN_ForceToStandby(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REJECT_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REJECT_DN_SpareHalfOctet(var) (&var)

/* Access member 'T3302Value' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value(var) (*var)

/* Access member 'T3302Value' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value(var) var

/* Access member 'T3346Value' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a variable reference */
#define VAR_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value(var) (*var)

/* Access member 'T3346Value' of type 'c_ROUTING_AREA_UPDATE_REJECT_DN' as a pointer */
#define PTR_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value(var) var


/*-A----------------------------------*/
typedef struct _c_ROUTING_AREA_UPDATE_REJECT_DN {
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */
	ED_LOCATOR ForceToStandby___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */

	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/
	ED_OCTET ForceToStandby; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_GprsTimer2 *T3302Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3302Value_Present;
	c_GprsTimer2 *T3346Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3346Value_Present;

}	c_ROUTING_AREA_UPDATE_REJECT_DN;
#define INIT_c_ROUTING_AREA_UPDATE_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ROUTING_AREA_UPDATE_REJECT_DN))
/*FRK03a*/
void FREE_c_ROUTING_AREA_UPDATE_REJECT_DN(c_ROUTING_AREA_UPDATE_REJECT_DN* sp);
int SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value (c_ROUTING_AREA_UPDATE_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3302Value(sp) ((sp)->T3302Value_Present)
int SETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value (c_ROUTING_AREA_UPDATE_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ROUTING_AREA_UPDATE_REJECT_DN_T3346Value(sp) ((sp)->T3346Value_Present)

/* Access member 'FullNameForNetwk' of type 'c_GMM_INFORMATION_DN' as a variable reference */
#define VAR_c_GMM_INFORMATION_DN_FullNameForNetwk(var) (*var)

/* Access member 'FullNameForNetwk' of type 'c_GMM_INFORMATION_DN' as a pointer */
#define PTR_c_GMM_INFORMATION_DN_FullNameForNetwk(var) var

/* Access member 'ShortNameForNetwk' of type 'c_GMM_INFORMATION_DN' as a variable reference */
#define VAR_c_GMM_INFORMATION_DN_ShortNameForNetwk(var) (*var)

/* Access member 'ShortNameForNetwk' of type 'c_GMM_INFORMATION_DN' as a pointer */
#define PTR_c_GMM_INFORMATION_DN_ShortNameForNetwk(var) var

/* Access member 'LocalTimeZone' of type 'c_GMM_INFORMATION_DN' as a variable reference */
#define VAR_c_GMM_INFORMATION_DN_LocalTimeZone(var) var

/* Access member 'LocalTimeZone' of type 'c_GMM_INFORMATION_DN' as a pointer */
#define PTR_c_GMM_INFORMATION_DN_LocalTimeZone(var) (&var)

/* Access member 'UniversalTimeAndLocalTimeZone' of type 'c_GMM_INFORMATION_DN' as a variable reference */
#define VAR_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone(var) (*var)

/* Access member 'UniversalTimeAndLocalTimeZone' of type 'c_GMM_INFORMATION_DN' as a pointer */
#define PTR_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone(var) var

/* Access member 'LsaId' of type 'c_GMM_INFORMATION_DN' as a variable reference */
#define VAR_c_GMM_INFORMATION_DN_LsaId(var) (*var)

/* Access member 'LsaId' of type 'c_GMM_INFORMATION_DN' as a pointer */
#define PTR_c_GMM_INFORMATION_DN_LsaId(var) var

/* Access member 'NetwkDaylightSavingTime' of type 'c_GMM_INFORMATION_DN' as a variable reference */
#define VAR_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime(var) (*var)

/* Access member 'NetwkDaylightSavingTime' of type 'c_GMM_INFORMATION_DN' as a pointer */
#define PTR_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime(var) var

/* DEFINITION OF BINARY c_GMM_INFORMATION_DN_LsaId */
typedef struct _c_GMM_INFORMATION_DN_LsaId {
	ED_BYTE* value; /* Variable size; bits needed 24 */
	int usedBits;
} c_GMM_INFORMATION_DN_LsaId;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_GMM_INFORMATION_DN_LsaId(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_GMM_INFORMATION_DN {
	ED_LOCATOR LocalTimeZone___LOCATOR; /* QUI2 */
	ED_LOCATOR LsaId___LOCATOR  /*LBD01*/;

	c_NetwkName *FullNameForNetwk; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN FullNameForNetwk_Present;
	c_NetwkName *ShortNameForNetwk; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ShortNameForNetwk_Present;
	ED_OCTET LocalTimeZone; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LocalTimeZone_Present;
	c_TimeZoneAndTime *UniversalTimeAndLocalTimeZone; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN UniversalTimeAndLocalTimeZone_Present;
	c_GMM_INFORMATION_DN_LsaId* LsaId; /* Dynamic, variable size; bits needed 24 ODY02b *//*GBD01b*/
	ED_BOOLEAN LsaId_Present;
	c_DaylightSavingTime *NetwkDaylightSavingTime; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NetwkDaylightSavingTime_Present;

}	c_GMM_INFORMATION_DN;
#define INIT_c_GMM_INFORMATION_DN(sp) ED_RESET_MEM ((sp), sizeof (c_GMM_INFORMATION_DN))
/*FRK03a*/
void FREE_c_GMM_INFORMATION_DN(c_GMM_INFORMATION_DN* sp);
int SETPRESENT_c_GMM_INFORMATION_DN_FullNameForNetwk (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_GMM_INFORMATION_DN_FullNameForNetwk(sp) ((sp)->FullNameForNetwk_Present)
int SETPRESENT_c_GMM_INFORMATION_DN_ShortNameForNetwk (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_GMM_INFORMATION_DN_ShortNameForNetwk(sp) ((sp)->ShortNameForNetwk_Present)
#define SETPRESENT_c_GMM_INFORMATION_DN_LocalTimeZone(sp,present) (((sp)->LocalTimeZone_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_GMM_INFORMATION_DN_LocalTimeZone(sp) ((sp)->LocalTimeZone_Present)
int SETPRESENT_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_GMM_INFORMATION_DN_UniversalTimeAndLocalTimeZone(sp) ((sp)->UniversalTimeAndLocalTimeZone_Present)
int SETPRESENT_c_GMM_INFORMATION_DN_LsaId (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_GMM_INFORMATION_DN_LsaId(sp) ((sp)->LsaId_Present)
int SETPRESENT_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime (c_GMM_INFORMATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_GMM_INFORMATION_DN_NetwkDaylightSavingTime(sp) ((sp)->NetwkDaylightSavingTime_Present)

/* Access member 'PdpContextStatus' of type 'c_SERVICE_ACCEPT_DN' as a variable reference */
#define VAR_c_SERVICE_ACCEPT_DN_PdpContextStatus(var) (*var)

/* Access member 'PdpContextStatus' of type 'c_SERVICE_ACCEPT_DN' as a pointer */
#define PTR_c_SERVICE_ACCEPT_DN_PdpContextStatus(var) var

/* Access member 'MBMSContextStatus' of type 'c_SERVICE_ACCEPT_DN' as a variable reference */
#define VAR_c_SERVICE_ACCEPT_DN_MBMSContextStatus(var) (*var)

/* Access member 'MBMSContextStatus' of type 'c_SERVICE_ACCEPT_DN' as a pointer */
#define PTR_c_SERVICE_ACCEPT_DN_MBMSContextStatus(var) var

/* DEFINITION OF BINARY c_SERVICE_ACCEPT_DN_MBMSContextStatus */
typedef struct _c_SERVICE_ACCEPT_DN_MBMSContextStatus {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_SERVICE_ACCEPT_DN_MBMSContextStatus;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SERVICE_ACCEPT_DN_MBMSContextStatus(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SERVICE_ACCEPT_DN {
	ED_LOCATOR MBMSContextStatus___LOCATOR  /*LBD01*/;

	c_PdpContextStatus *PdpContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PdpContextStatus_Present;
	c_SERVICE_ACCEPT_DN_MBMSContextStatus* MBMSContextStatus; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSContextStatus_Present;

}	c_SERVICE_ACCEPT_DN;
#define INIT_c_SERVICE_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_SERVICE_ACCEPT_DN))
/*FRK03a*/
void FREE_c_SERVICE_ACCEPT_DN(c_SERVICE_ACCEPT_DN* sp);
int SETPRESENT_c_SERVICE_ACCEPT_DN_PdpContextStatus (c_SERVICE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_ACCEPT_DN_PdpContextStatus(sp) ((sp)->PdpContextStatus_Present)
int SETPRESENT_c_SERVICE_ACCEPT_DN_MBMSContextStatus (c_SERVICE_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_ACCEPT_DN_MBMSContextStatus(sp) ((sp)->MBMSContextStatus_Present)

/* Access member 'GmmCause' of type 'c_SERVICE_REJECT_DN' as a variable reference */
#define VAR_c_SERVICE_REJECT_DN_GmmCause(var) var

/* Access member 'GmmCause' of type 'c_SERVICE_REJECT_DN' as a pointer */
#define PTR_c_SERVICE_REJECT_DN_GmmCause(var) (&var)

/* Access member 'T3346Value' of type 'c_SERVICE_REJECT_DN' as a variable reference */
#define VAR_c_SERVICE_REJECT_DN_T3346Value(var) (*var)

/* Access member 'T3346Value' of type 'c_SERVICE_REJECT_DN' as a pointer */
#define PTR_c_SERVICE_REJECT_DN_T3346Value(var) var


/*-A----------------------------------*/
typedef struct _c_SERVICE_REJECT_DN {
	ED_LOCATOR GmmCause___LOCATOR; /* QUI2 */

	ED_OCTET GmmCause; /* ODY01a *//*GBD01b*/
	c_GprsTimer2 *T3346Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3346Value_Present;

}	c_SERVICE_REJECT_DN;
#define INIT_c_SERVICE_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_SERVICE_REJECT_DN))
/*FRK03a*/
void FREE_c_SERVICE_REJECT_DN(c_SERVICE_REJECT_DN* sp);
int SETPRESENT_c_SERVICE_REJECT_DN_T3346Value (c_SERVICE_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_REJECT_DN_T3346Value(sp) ((sp)->T3346Value_Present)

/* Access member 'TI_Value' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_TI_Flag(var) (&var)

/* Access member 'ReqNsapi' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqNsapi(var) var

/* Access member 'ReqNsapi' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqNsapi(var) (&var)

/* Access member 'ReqLlcSapi' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi(var) var

/* Access member 'ReqLlcSapi' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi(var) (&var)

/* Access member 'ReqQos' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqQos(var) var

/* Access member 'ReqQos' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqQos(var) (&var)

/* Access member 'ReqPdpAddr' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqPdpAddr(var) var

/* Access member 'ReqPdpAddr' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ReqPdpAddr(var) (&var)

/* Access member 'AccessPointName' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName(var) (*var)

/* Access member 'AccessPointName' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName(var) var

/* Access member 'ProtocolCfgOpt' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt(var) (*var)

/* Access member 'ProtocolCfgOpt' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt(var) var

/* Access member 'RequestType' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_RequestType(var) var

/* Access member 'RequestType' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_RequestType(var) (&var)

/* Access member 'DeviceProperties' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer */
typedef struct _c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_PDP_CONTEXT_REQUEST_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR RequestType___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_NetwkServAccessPointId ReqNsapi; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId ReqLlcSapi; /* ODY01a *//*GBD01b*/
	c_QualityOfServ ReqQos; /* ODY01a *//*GBD01b*/
	c_PacketDataProtocolAddr ReqPdpAddr; /* ODY01a *//*GBD01b*/
	c_ASCII *AccessPointName; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AccessPointName_Present;
	c_ProtocolCfgOpt *ProtocolCfgOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolCfgOpt_Present;
	ED_OCTET RequestType; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RequestType_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_ACTIVATE_PDP_CONTEXT_REQUEST_UP;
#define INIT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP))
/*FRK03a*/
void FREE_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP(c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp);
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_AccessPointName(sp) ((sp)->AccessPointName_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_ProtocolCfgOpt(sp) ((sp)->ProtocolCfgOpt_Present)
#define SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_RequestType(sp,present) (((sp)->RequestType_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_RequestType(sp) ((sp)->RequestType_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (c_ACTIVATE_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_TI_Flag(var) (&var)

/* Access member 'ReqNsapi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ReqNsapi(var) var

/* Access member 'ReqNsapi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ReqNsapi(var) (&var)

/* Access member 'ReqLlcSapi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi(var) var

/* Access member 'ReqLlcSapi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi(var) (&var)

/* Access member 'ReqQos' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ReqQos(var) var

/* Access member 'ReqQos' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ReqQos(var) (&var)

/* Access member 'LinkedTi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_LinkedTi(var) var

/* Access member 'LinkedTi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_LinkedTi(var) (&var)

/* Access member 'Tft' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft(var) (*var)

/* Access member 'Tft' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt(var) var

/* Access member 'DeviceProperties' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer */
typedef struct _c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_NetwkServAccessPointId ReqNsapi; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId ReqLlcSapi; /* ODY01a *//*GBD01b*/
	c_QualityOfServ ReqQos; /* ODY01a *//*GBD01b*/
	c_LinkedTi LinkedTi; /* ODY01a *//*GBD01b*/
	c_TrafficFlowTemplate *Tft; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Tft_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP;
#define INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP))
/*FRK03a*/
void FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP(c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp);
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_Tft(sp) ((sp)->Tft_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_SmCause(var) var

/* Access member 'SmCause' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_SmCause(var) (&var)

/* Access member 'ProtocolConfigOpt' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt(var) var

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer */
typedef struct _c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP;
#define INIT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP(sp) ED_RESET_MEM ((sp), sizeof (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP))
/*FRK03a*/
void FREE_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP(c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* sp);
int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer (c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_REJECT_UP_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_TI_Flag(var) (&var)

/* Access member 'ReqLlcSapi' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi(var) (*var)

/* Access member 'ReqLlcSapi' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi(var) var

/* Access member 'ReqNewQos' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos(var) (*var)

/* Access member 'ReqNewQos' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos(var) var

/* Access member 'NewTft' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft(var) (*var)

/* Access member 'NewTft' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt(var) var

/* Access member 'DeviceProperties' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer */
typedef struct _c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_PDP_CONTEXT_REQUEST_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId *ReqLlcSapi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReqLlcSapi_Present;
	c_QualityOfServ *ReqNewQos; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReqNewQos_Present;
	c_TrafficFlowTemplate *NewTft; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NewTft_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_MODIFY_PDP_CONTEXT_REQUEST_UP;
#define INIT_c_MODIFY_PDP_CONTEXT_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_PDP_CONTEXT_REQUEST_UP))
/*FRK03a*/
void FREE_c_MODIFY_PDP_CONTEXT_REQUEST_UP(c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp);
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqLlcSapi(sp) ((sp)->ReqLlcSapi_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ReqNewQos(sp) ((sp)->ReqNewQos_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NewTft(sp) ((sp)->NewTft_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_REQUEST_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_UP_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_TI_Flag(var) (&var)

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_UP' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer */
typedef struct _c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_PDP_CONTEXT_ACCEPT_UP {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_MODIFY_PDP_CONTEXT_ACCEPT_UP;
#define INIT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_PDP_CONTEXT_ACCEPT_UP))
/*FRK03a*/
void FREE_c_MODIFY_PDP_CONTEXT_ACCEPT_UP(c_MODIFY_PDP_CONTEXT_ACCEPT_UP* sp);
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_ACCEPT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_ACCEPT_UP* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_UP_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_SmCause(var) var

/* Access member 'SmCause' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_SmCause(var) (&var)

/* Access member 'TearDownInd' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd(var) (*var)

/* Access member 'TearDownInd' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt(var) var

/* Access member 'MBMSContextStatus' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus(var) (*var)

/* Access member 'MBMSContextStatus' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus(var) var

/* Access member 'T3396Value' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value(var) (*var)

/* Access member 'T3396Value' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value(var) var

/* Access member 'WLANOffloadIndication' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_DEACTIVATE_PDP_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication(var) var

/* DEFINITION OF BINARY c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus */
typedef struct _c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DEACTIVATE_PDP_CONTEXT_REQUEST {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSContextStatus___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_TearDownInd *TearDownInd; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TearDownInd_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus* MBMSContextStatus; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSContextStatus_Present;
	c_GprsTimer3 *T3396Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3396Value_Present;
	c_WLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;

}	c_DEACTIVATE_PDP_CONTEXT_REQUEST;
#define INIT_c_DEACTIVATE_PDP_CONTEXT_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_DEACTIVATE_PDP_CONTEXT_REQUEST))
/*FRK03a*/
void FREE_c_DEACTIVATE_PDP_CONTEXT_REQUEST(c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp);
int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_TearDownInd(sp) ((sp)->TearDownInd_Present)
int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_MBMSContextStatus(sp) ((sp)->MBMSContextStatus_Present)
int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_T3396Value(sp) ((sp)->T3396Value_Present)
int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication (c_DEACTIVATE_PDP_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_PDP_CONTEXT_REQUEST_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)

/* Access member 'TI_Value' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_TI_Flag(var) (&var)

/* Access member 'ProtocolConfigOpt' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt(var) var

/* Access member 'MBMSContextStatus' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus(var) (*var)

/* Access member 'MBMSContextStatus' of type 'c_DEACTIVATE_PDP_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus(var) var

/* DEFINITION OF BINARY c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus */
typedef struct _c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DEACTIVATE_PDP_CONTEXT_ACCEPT {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSContextStatus___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus* MBMSContextStatus; /* Dynamic, variable size; bits needed 128 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSContextStatus_Present;

}	c_DEACTIVATE_PDP_CONTEXT_ACCEPT;
#define INIT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_DEACTIVATE_PDP_CONTEXT_ACCEPT))
/*FRK03a*/
void FREE_c_DEACTIVATE_PDP_CONTEXT_ACCEPT(c_DEACTIVATE_PDP_CONTEXT_ACCEPT* sp);
int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt (c_DEACTIVATE_PDP_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus (c_DEACTIVATE_PDP_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_PDP_CONTEXT_ACCEPT_MBMSContextStatus(sp) ((sp)->MBMSContextStatus_Present)

/* Access member 'TI_Value' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_SmCause(var) var

/* Access member 'SmCause' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_SmCause(var) (&var)

/* Access member 'ProtocolCfgOpt' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt(var) (*var)

/* Access member 'ProtocolCfgOpt' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt(var) var

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer */
typedef struct _c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt *ProtocolCfgOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolCfgOpt_Present;
	c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT;
#define INIT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT))
/*FRK03a*/
void FREE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT(c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* sp);
int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_ProtocolCfgOpt(sp) ((sp)->ProtocolCfgOpt_Present)
int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_REJECT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_SM_STATUS' as a variable reference */
#define VAR_c_SM_STATUS_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_SM_STATUS' as a pointer */
#define PTR_c_SM_STATUS_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_SM_STATUS' as a variable reference */
#define VAR_c_SM_STATUS_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_SM_STATUS' as a pointer */
#define PTR_c_SM_STATUS_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_SM_STATUS' as a variable reference */
#define VAR_c_SM_STATUS_SmCause(var) var

/* Access member 'SmCause' of type 'c_SM_STATUS' as a pointer */
#define PTR_c_SM_STATUS_SmCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_SM_STATUS {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/

}	c_SM_STATUS;
#define INIT_c_SM_STATUS(sp) ED_RESET_MEM ((sp), sizeof (c_SM_STATUS))
/*FRK03a*/
void FREE_c_SM_STATUS(c_SM_STATUS* sp);

/* Access member 'TI_Value' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_TI_Flag(var) (&var)

/* Access member 'ReqMbmsNsapi' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_ReqMbmsNsapi(var) var

/* Access member 'ReqMbmsNsapi' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_ReqMbmsNsapi(var) (&var)

/* Access member 'ReqLlcSapi' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_ReqLlcSapi(var) var

/* Access member 'ReqLlcSapi' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_ReqLlcSapi(var) (&var)

/* Access member 'SupportedMBMSBearerCapabilities' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_SupportedMBMSBearerCapabilities(var) var

/* Access member 'SupportedMBMSBearerCapabilities' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_SupportedMBMSBearerCapabilities(var) (&var)

/* Access member 'RequestedMulticastAddress' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_RequestedMulticastAddress(var) var

/* Access member 'RequestedMulticastAddress' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_RequestedMulticastAddress(var) (&var)

/* Access member 'AccessPointName' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName(var) var

/* Access member 'AccessPointName' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName(var) (&var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts(var) (*var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts(var) var

/* Access member 'DeviceProperties' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_ACTIVATE_MBMS_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties(var) var

/* DEFINITION OF BINARY c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName */
typedef struct _c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName {
	ED_BYTE* value; /* Variable size; bits needed 800 */
	int usedBits;
} c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts */
typedef struct _c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_MBMS_CONTEXT_REQUEST {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR ReqMbmsNsapi___LOCATOR; /* QUI2 */
	ED_LOCATOR AccessPointName___LOCATOR  /*LBD02*/;
	ED_LOCATOR MBMSProtocolConfigOpts___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET ReqMbmsNsapi; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId ReqLlcSapi; /* ODY01a *//*GBD01b*/
	c_MBMSBearerCapabilities SupportedMBMSBearerCapabilities; /* ODY01a *//*GBD01b*/
	c_PacketDataProtocolAddr RequestedMulticastAddress; /* ODY01a *//*GBD01b*/
	c_ACTIVATE_MBMS_CONTEXT_REQUEST_AccessPointName AccessPointName; /* Static, variable size; bits needed 800 *//*GBD01b*/
	c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts* MBMSProtocolConfigOpts; /* Dynamic, variable size; bits needed 2008 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSProtocolConfigOpts_Present;
	c_DeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;

}	c_ACTIVATE_MBMS_CONTEXT_REQUEST;
#define INIT_c_ACTIVATE_MBMS_CONTEXT_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_MBMS_CONTEXT_REQUEST))
/*FRK03a*/
void FREE_c_ACTIVATE_MBMS_CONTEXT_REQUEST(c_ACTIVATE_MBMS_CONTEXT_REQUEST* sp);
int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts (c_ACTIVATE_MBMS_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_MBMSProtocolConfigOpts(sp) ((sp)->MBMSProtocolConfigOpts_Present)
int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties (c_ACTIVATE_MBMS_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)

/* Access member 'TI_Value' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_SmCause(var) var

/* Access member 'SmCause' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_SmCause(var) (&var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts(var) (*var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts(var) var

/* DEFINITION OF BINARY c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts */
typedef struct _c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSProtocolConfigOpts___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts* MBMSProtocolConfigOpts; /* Dynamic, variable size; bits needed 2008 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSProtocolConfigOpts_Present;

}	c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT;
#define INIT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT))
/*FRK03a*/
void FREE_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT(c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* sp);
int SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts (c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_REJECT_MBMSProtocolConfigOpts(sp) ((sp)->MBMSProtocolConfigOpts_Present)

/* Access member 'TI_Value' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_TI_Flag(var) (&var)

/* Access member 'NegotiatedLlcSapi' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi(var) var

/* Access member 'NegotiatedLlcSapi' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi(var) (&var)

/* Access member 'NegotiatedQos' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos(var) var

/* Access member 'NegotiatedQos' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos(var) (&var)

/* Access member 'RadioPriority' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_RadioPriority(var) var

/* Access member 'RadioPriority' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_RadioPriority(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SpareHalfOctet(var) (&var)

/* Access member 'PdpAddr' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr(var) (*var)

/* Access member 'PdpAddr' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr(var) var

/* Access member 'ProtocolCfgOpt' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt(var) (*var)

/* Access member 'ProtocolCfgOpt' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt(var) var

/* Access member 'PacketFlowId' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(var) (*var)

/* Access member 'PacketFlowId' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(var) var

/* Access member 'SMCause' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause(var) (*var)

/* Access member 'SMCause' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause(var) var

/* Access member 'ConnectivityType' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ConnectivityType(var) var

/* Access member 'ConnectivityType' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ConnectivityType(var) (&var)

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer */
typedef struct _c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR RadioPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR ConnectivityType___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId NegotiatedLlcSapi; /* ODY01a *//*GBD01b*/
	c_QualityOfServ NegotiatedQos; /* ODY01a *//*GBD01b*/
	ED_OCTET RadioPriority; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_PacketDataProtocolAddr *PdpAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PdpAddr_Present;
	c_ProtocolCfgOpt *ProtocolCfgOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolCfgOpt_Present;
	c_PacketFlowIdentifie *PacketFlowId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PacketFlowId_Present;
	c_SMCause *SMCause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SMCause_Present;
	ED_OCTET ConnectivityType; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ConnectivityType_Present;
	c_WLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN;
#define INIT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN))
/*FRK03a*/
void FREE_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN(c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp);
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PdpAddr(sp) ((sp)->PdpAddr_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ProtocolCfgOpt(sp) ((sp)->ProtocolCfgOpt_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(sp) ((sp)->PacketFlowId_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_SMCause(sp) ((sp)->SMCause_Present)
#define SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ConnectivityType(sp,present) (((sp)->ConnectivityType_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_ConnectivityType(sp) ((sp)->ConnectivityType_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_SmCause(var) var

/* Access member 'SmCause' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_SmCause(var) (&var)

/* Access member 'ProtocolCfgOpt' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt(var) (*var)

/* Access member 'ProtocolCfgOpt' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt(var) var

/* Access member 'T3396Value' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value(var) (*var)

/* Access member 'T3396Value' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value(var) var

/* Access member 'ReAttemptIndicator' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(var) (*var)

/* Access member 'ReAttemptIndicator' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer */
typedef struct _c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_PDP_CONTEXT_REJECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt *ProtocolCfgOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolCfgOpt_Present;
	c_GprsTimer3 *T3396Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3396Value_Present;
	c_ReAttemptIndicator *ReAttemptIndicator; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReAttemptIndicator_Present;
	c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_ACTIVATE_PDP_CONTEXT_REJECT_DN;
#define INIT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_PDP_CONTEXT_REJECT_DN))
/*FRK03a*/
void FREE_c_ACTIVATE_PDP_CONTEXT_REJECT_DN(c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp);
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ProtocolCfgOpt(sp) ((sp)->ProtocolCfgOpt_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_T3396Value(sp) ((sp)->T3396Value_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(sp) ((sp)->ReAttemptIndicator_Present)
int SETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (c_ACTIVATE_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_TI_Flag(var) (&var)

/* Access member 'NegotiatedLlcSapi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi(var) var

/* Access member 'NegotiatedLlcSapi' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi(var) (&var)

/* Access member 'NegotiatedQos' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos(var) var

/* Access member 'NegotiatedQos' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos(var) (&var)

/* Access member 'RadioPriority' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_RadioPriority(var) var

/* Access member 'RadioPriority' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_RadioPriority(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_SpareHalfOctet(var) (&var)

/* Access member 'PacketFlowId' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(var) (*var)

/* Access member 'PacketFlowId' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt(var) var

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer */
typedef struct _c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR RadioPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId NegotiatedLlcSapi; /* ODY01a *//*GBD01b*/
	c_QualityOfServ NegotiatedQos; /* ODY01a *//*GBD01b*/
	ED_OCTET RadioPriority; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_PacketFlowIdentifie *PacketFlowId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PacketFlowId_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_WLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN;
#define INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN))
/*FRK03a*/
void FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN(c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp);
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(sp) ((sp)->PacketFlowId_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_SmCause(var) var

/* Access member 'SmCause' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_SmCause(var) (&var)

/* Access member 'ProtocolConfigOpt' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt(var) var

/* Access member 'T3396Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value(var) (*var)

/* Access member 'T3396Value' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value(var) var

/* Access member 'ReAttemptIndicator' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(var) (*var)

/* Access member 'ReAttemptIndicator' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer */
typedef struct _c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_GprsTimer3 *T3396Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3396Value_Present;
	c_ReAttemptIndicator *ReAttemptIndicator; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReAttemptIndicator_Present;
	c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN;
#define INIT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN))
/*FRK03a*/
void FREE_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN(c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp);
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_T3396Value(sp) ((sp)->T3396Value_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(sp) ((sp)->ReAttemptIndicator_Present)
int SETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_SECONDARY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_TI_Flag(var) (&var)

/* Access member 'OfferedPdpAddr' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_OfferedPdpAddr(var) var

/* Access member 'OfferedPdpAddr' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_OfferedPdpAddr(var) (&var)

/* Access member 'AccessPointName' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName(var) (*var)

/* Access member 'AccessPointName' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt(var) var

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a variable reference */
#define VAR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_PDP_CONTEXT_ACTIVATION_DN' as a pointer */
#define PTR_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName */
typedef struct _c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName {
	ED_BYTE* value; /* Variable size; bits needed 800 */
	int usedBits;
} c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer */
typedef struct _c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_REQUEST_PDP_CONTEXT_ACTIVATION_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR AccessPointName___LOCATOR  /*LBD01*/;
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_PacketDataProtocolAddr OfferedPdpAddr; /* ODY01a *//*GBD01b*/
	c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName* AccessPointName; /* Dynamic, variable size; bits needed 800 ODY02b *//*GBD01b*/
	ED_BOOLEAN AccessPointName_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_REQUEST_PDP_CONTEXT_ACTIVATION_DN;
#define INIT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN(sp) ED_RESET_MEM ((sp), sizeof (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN))
/*FRK03a*/
void FREE_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN(c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp);
int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_AccessPointName(sp) ((sp)->AccessPointName_Present)
int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer (c_REQUEST_PDP_CONTEXT_ACTIVATION_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_PDP_CONTEXT_ACTIVATION_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_TI_Flag(var) (&var)

/* Access member 'RadioPriority' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_RadioPriority(var) var

/* Access member 'RadioPriority' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_RadioPriority(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_SpareHalfOctet(var) (&var)

/* Access member 'ReqLlcSapi' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ReqLlcSapi(var) var

/* Access member 'ReqLlcSapi' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ReqLlcSapi(var) (&var)

/* Access member 'NewQos' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NewQos(var) var

/* Access member 'NewQos' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NewQos(var) (&var)

/* Access member 'PdpAddr' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr(var) (*var)

/* Access member 'PdpAddr' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr(var) var

/* Access member 'PacketFlowId' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId(var) (*var)

/* Access member 'PacketFlowId' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt(var) var

/* Access member 'Tft' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft(var) (*var)

/* Access member 'Tft' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft(var) var

/* Access member 'WLANOffloadIndication' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_REQUEST_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer */
typedef struct _c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_PDP_CONTEXT_REQUEST_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR RadioPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareHalfOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET RadioPriority; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareHalfOctet; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId ReqLlcSapi; /* ODY01a *//*GBD01b*/
	c_QualityOfServ NewQos; /* ODY01a *//*GBD01b*/
	c_PacketDataProtocolAddr *PdpAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PdpAddr_Present;
	c_PacketFlowIdentifie *PacketFlowId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PacketFlowId_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_TrafficFlowTemplate *Tft; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Tft_Present;
	c_WLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_MODIFY_PDP_CONTEXT_REQUEST_DN;
#define INIT_c_MODIFY_PDP_CONTEXT_REQUEST_DN(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_PDP_CONTEXT_REQUEST_DN))
/*FRK03a*/
void FREE_c_MODIFY_PDP_CONTEXT_REQUEST_DN(c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp);
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PdpAddr(sp) ((sp)->PdpAddr_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_PacketFlowId(sp) ((sp)->PacketFlowId_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_Tft(sp) ((sp)->Tft_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_REQUEST_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REQUEST_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_TI_Flag(var) (&var)

/* Access member 'NegotiatedQos' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos(var) (*var)

/* Access member 'NegotiatedQos' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos(var) var

/* Access member 'NegotiatedLlcSapi' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi(var) (*var)

/* Access member 'NegotiatedLlcSapi' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi(var) var

/* Access member 'NewRadioPriority' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NewRadioPriority(var) var

/* Access member 'NewRadioPriority' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NewRadioPriority(var) (&var)

/* Access member 'PacketFlowId' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(var) (*var)

/* Access member 'PacketFlowId' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt(var) var

/* Access member 'WLANOffloadIndication' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_ACCEPT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer */
typedef struct _c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_PDP_CONTEXT_ACCEPT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NewRadioPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_QualityOfServ *NegotiatedQos; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedQos_Present;
	c_LlcServAccessPointId *NegotiatedLlcSapi; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedLlcSapi_Present;
	ED_OCTET NewRadioPriority; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NewRadioPriority_Present;
	c_PacketFlowIdentifie *PacketFlowId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PacketFlowId_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_WLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_MODIFY_PDP_CONTEXT_ACCEPT_DN;
#define INIT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_PDP_CONTEXT_ACCEPT_DN))
/*FRK03a*/
void FREE_c_MODIFY_PDP_CONTEXT_ACCEPT_DN(c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp);
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedQos(sp) ((sp)->NegotiatedQos_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NegotiatedLlcSapi(sp) ((sp)->NegotiatedLlcSapi_Present)
#define SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NewRadioPriority(sp,present) (((sp)->NewRadioPriority_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NewRadioPriority(sp) ((sp)->NewRadioPriority_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_PacketFlowId(sp) ((sp)->PacketFlowId_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_ACCEPT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_ACCEPT_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REJECT_DN_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REJECT_DN_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REJECT_DN_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REJECT_DN_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REJECT_DN_SmCause(var) var

/* Access member 'SmCause' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REJECT_DN_SmCause(var) (&var)

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt(var) var

/* Access member 'T3396Value' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value(var) (*var)

/* Access member 'T3396Value' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value(var) var

/* Access member 'ReAttemptIndicator' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(var) (*var)

/* Access member 'ReAttemptIndicator' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a variable reference */
#define VAR_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_PDP_CONTEXT_REJECT_DN' as a pointer */
#define PTR_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer */
typedef struct _c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_PDP_CONTEXT_REJECT_DN {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_GprsTimer3 *T3396Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3396Value_Present;
	c_ReAttemptIndicator *ReAttemptIndicator; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReAttemptIndicator_Present;
	c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_MODIFY_PDP_CONTEXT_REJECT_DN;
#define INIT_c_MODIFY_PDP_CONTEXT_REJECT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_PDP_CONTEXT_REJECT_DN))
/*FRK03a*/
void FREE_c_MODIFY_PDP_CONTEXT_REJECT_DN(c_MODIFY_PDP_CONTEXT_REJECT_DN* sp);
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_T3396Value(sp) ((sp)->T3396Value_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_ReAttemptIndicator(sp) ((sp)->ReAttemptIndicator_Present)
int SETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer (c_MODIFY_PDP_CONTEXT_REJECT_DN* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_PDP_CONTEXT_REJECT_DN_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_TI_Flag(var) (&var)

/* Access member 'ReqQos' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ReqQos(var) var

/* Access member 'ReqQos' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ReqQos(var) (&var)

/* Access member 'LinkedTi' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_LinkedTi(var) var

/* Access member 'LinkedTi' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_LinkedTi(var) (&var)

/* Access member 'Tft' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft(var) (*var)

/* Access member 'Tft' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft(var) var

/* Access member 'ProtocolConfigOpt' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt(var) (*var)

/* Access member 'ProtocolConfigOpt' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt(var) var

/* Access member 'WLANOffloadIndication' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer(var) var

/* DEFINITION OF BINARY c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer */
typedef struct _c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_QualityOfServ ReqQos; /* ODY01a *//*GBD01b*/
	c_LinkedTi LinkedTi; /* ODY01a *//*GBD01b*/
	c_TrafficFlowTemplate *Tft; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN Tft_Present;
	c_ProtocolCfgOpt *ProtocolConfigOpt; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigOpt_Present;
	c_WLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;

}	c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION;
#define INIT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION(sp) ED_RESET_MEM ((sp), sizeof (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION))
/*FRK03a*/
void FREE_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION(c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp);
int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_Tft(sp) ((sp)->Tft_Present)
int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_ProtocolConfigOpt(sp) ((sp)->ProtocolConfigOpt_Present)
int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer (c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_SECONDARY_PDP_CONTEXT_ACTIVATION_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)

/* Access member 'TI_Value' of type 'c_NOTIFICATION' as a variable reference */
#define VAR_c_NOTIFICATION_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_NOTIFICATION' as a pointer */
#define PTR_c_NOTIFICATION_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_NOTIFICATION' as a variable reference */
#define VAR_c_NOTIFICATION_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_NOTIFICATION' as a pointer */
#define PTR_c_NOTIFICATION_TI_Flag(var) (&var)

/* Access member 'NotificationIndicator' of type 'c_NOTIFICATION' as a variable reference */
#define VAR_c_NOTIFICATION_NotificationIndicator(var) var

/* Access member 'NotificationIndicator' of type 'c_NOTIFICATION' as a pointer */
#define PTR_c_NOTIFICATION_NotificationIndicator(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NOTIFICATION {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR NotificationIndicator___LOCATOR; /* QUI2 */

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	ED_OCTET NotificationIndicator; /* ODY01a *//*GBD01b*/

}	c_NOTIFICATION;
#define INIT_c_NOTIFICATION(sp) ED_RESET_MEM ((sp), sizeof (c_NOTIFICATION))
/*FRK03a*/
void FREE_c_NOTIFICATION(c_NOTIFICATION* sp);

/* Access member 'TI_Value' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_TI_Flag(var) (&var)

/* Access member 'TempMobileGroupId' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_TempMobileGroupId(var) var

/* Access member 'TempMobileGroupId' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_TempMobileGroupId(var) (&var)

/* Access member 'NegotiatedLlcSapi' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_NegotiatedLlcSapi(var) var

/* Access member 'NegotiatedLlcSapi' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_NegotiatedLlcSapi(var) (&var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts(var) (*var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_ACTIVATE_MBMS_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts(var) var

/* DEFINITION OF BINARY c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts */
typedef struct _c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_MBMS_CONTEXT_ACCEPT {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSProtocolConfigOpts___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_TempMobileGroupId TempMobileGroupId; /* ODY01a *//*GBD01b*/
	c_LlcServAccessPointId NegotiatedLlcSapi; /* ODY01a *//*GBD01b*/
	c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts* MBMSProtocolConfigOpts; /* Dynamic, variable size; bits needed 2008 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSProtocolConfigOpts_Present;

}	c_ACTIVATE_MBMS_CONTEXT_ACCEPT;
#define INIT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_MBMS_CONTEXT_ACCEPT))
/*FRK03a*/
void FREE_c_ACTIVATE_MBMS_CONTEXT_ACCEPT(c_ACTIVATE_MBMS_CONTEXT_ACCEPT* sp);
int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts (c_ACTIVATE_MBMS_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_MBMS_CONTEXT_ACCEPT_MBMSProtocolConfigOpts(sp) ((sp)->MBMSProtocolConfigOpts_Present)

/* Access member 'TI_Value' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REJECT_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REJECT_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REJECT_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REJECT_TI_Flag(var) (&var)

/* Access member 'SmCause' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REJECT_SmCause(var) var

/* Access member 'SmCause' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REJECT_SmCause(var) (&var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts(var) (*var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts(var) var

/* Access member 'BackOffTimerValue' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue(var) (*var)

/* Access member 'BackOffTimerValue' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue(var) var

/* Access member 'ReAttemptIndicator' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator(var) (*var)

/* Access member 'ReAttemptIndicator' of type 'c_ACTIVATE_MBMS_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator(var) var

/* DEFINITION OF BINARY c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts */
typedef struct _c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_MBMS_CONTEXT_REJECT {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR MBMSProtocolConfigOpts___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_SMCause SmCause; /* ODY01a *//*GBD01b*/
	c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts* MBMSProtocolConfigOpts; /* Dynamic, variable size; bits needed 2008 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSProtocolConfigOpts_Present;
	c_GprsTimer3 *BackOffTimerValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BackOffTimerValue_Present;
	c_ReAttemptIndicator *ReAttemptIndicator; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReAttemptIndicator_Present;

}	c_ACTIVATE_MBMS_CONTEXT_REJECT;
#define INIT_c_ACTIVATE_MBMS_CONTEXT_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_MBMS_CONTEXT_REJECT))
/*FRK03a*/
void FREE_c_ACTIVATE_MBMS_CONTEXT_REJECT(c_ACTIVATE_MBMS_CONTEXT_REJECT* sp);
int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts (c_ACTIVATE_MBMS_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_MBMSProtocolConfigOpts(sp) ((sp)->MBMSProtocolConfigOpts_Present)
int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue (c_ACTIVATE_MBMS_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_BackOffTimerValue(sp) ((sp)->BackOffTimerValue_Present)
int SETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator (c_ACTIVATE_MBMS_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_MBMS_CONTEXT_REJECT_ReAttemptIndicator(sp) ((sp)->ReAttemptIndicator_Present)

/* Access member 'TI_Value' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_TI_Value(var) var

/* Access member 'TI_Value' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_TI_Value(var) (&var)

/* Access member 'TI_Flag' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_TI_Flag(var) var

/* Access member 'TI_Flag' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_TI_Flag(var) (&var)

/* Access member 'LinkedNSAPI' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_LinkedNSAPI(var) var

/* Access member 'LinkedNSAPI' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_LinkedNSAPI(var) (&var)

/* Access member 'OfferedMulticastAddr' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_OfferedMulticastAddr(var) var

/* Access member 'OfferedMulticastAddr' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_OfferedMulticastAddr(var) (&var)

/* Access member 'AccessPointName' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName(var) var

/* Access member 'AccessPointName' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName(var) (&var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a variable reference */
#define VAR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts(var) (*var)

/* Access member 'MBMSProtocolConfigOpts' of type 'c_REQUEST_MBMS_CONTEXT_ACTIVATION' as a pointer */
#define PTR_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts(var) var

/* DEFINITION OF BINARY c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName */
typedef struct _c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName {
	ED_BYTE* value; /* Variable size; bits needed 800 */
	int usedBits;
} c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts */
typedef struct _c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_REQUEST_MBMS_CONTEXT_ACTIVATION {
	ED_LOCATOR TI_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR TI_Flag___LOCATOR; /* QUI2 */
	ED_LOCATOR AccessPointName___LOCATOR  /*LBD02*/;
	ED_LOCATOR MBMSProtocolConfigOpts___LOCATOR  /*LBD01*/;

	ED_OCTET TI_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TI_Flag; /* ODY01a *//*GBD01b*/
	c_NetwkServAccessPointId LinkedNSAPI; /* ODY01a *//*GBD01b*/
	c_PacketDataProtocolAddr OfferedMulticastAddr; /* ODY01a *//*GBD01b*/
	c_REQUEST_MBMS_CONTEXT_ACTIVATION_AccessPointName AccessPointName; /* Static, variable size; bits needed 800 *//*GBD01b*/
	c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts* MBMSProtocolConfigOpts; /* Dynamic, variable size; bits needed 2008 ODY02b *//*GBD01b*/
	ED_BOOLEAN MBMSProtocolConfigOpts_Present;

}	c_REQUEST_MBMS_CONTEXT_ACTIVATION;
#define INIT_c_REQUEST_MBMS_CONTEXT_ACTIVATION(sp) ED_RESET_MEM ((sp), sizeof (c_REQUEST_MBMS_CONTEXT_ACTIVATION))
/*FRK03a*/
void FREE_c_REQUEST_MBMS_CONTEXT_ACTIVATION(c_REQUEST_MBMS_CONTEXT_ACTIVATION* sp);
int SETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts (c_REQUEST_MBMS_CONTEXT_ACTIVATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REQUEST_MBMS_CONTEXT_ACTIVATION_MBMSProtocolConfigOpts(sp) ((sp)->MBMSProtocolConfigOpts_Present)

/* Access member 'TLV_Tag' of type 'c_GenericTLV_L3' as a variable reference */
#define VAR_c_GenericTLV_L3_TLV_Tag(var) var

/* Access member 'TLV_Tag' of type 'c_GenericTLV_L3' as a pointer */
#define PTR_c_GenericTLV_L3_TLV_Tag(var) (&var)

/* Access member 'TLV_Data' of type 'c_GenericTLV_L3' as a variable reference */
#define VAR_c_GenericTLV_L3_TLV_Data(var) var

/* Access member 'TLV_Data' of type 'c_GenericTLV_L3' as a pointer */
#define PTR_c_GenericTLV_L3_TLV_Data(var) (&var)

/* DEFINITION OF BINARY c_GenericTLV_L3_TLV_Data */
typedef struct _c_GenericTLV_L3_TLV_Data {
	ED_BYTE* value; /* Variable size; bits needed 8192 */
	int usedBits;
} c_GenericTLV_L3_TLV_Data;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_GenericTLV_L3_TLV_Data(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_GenericTLV_L3 {
	ED_LOCATOR TLV_Tag___LOCATOR; /* QUI2 */
	ED_LOCATOR TLV_Data___LOCATOR  /*LBD02*/;

	ED_LONG TLV_Tag; /* ODY01a *//*GBD01b*/
	c_GenericTLV_L3_TLV_Data TLV_Data; /* Static, variable size; bits needed 8192 *//*GBD01b*/

}	c_GenericTLV_L3;
#define INIT_c_GenericTLV_L3(sp) ED_RESET_MEM ((sp), sizeof (c_GenericTLV_L3))
/*FRK03a*/
void FREE_c_GenericTLV_L3(c_GenericTLV_L3* sp);

/* SETITEMS/ADDITEMS commands for type 'c_MobileId_Identity_IdentityDigit'. */
int SETITEMS_c_MobileId_Identity_IdentityDigit (c_MobileId_Identity_IdentityDigit* sequence, int desiredItems);
#define ADDITEMS_c_MobileId_Identity_IdentityDigit(sequence, itemsToBeAdded) SETITEMS_c_MobileId_Identity_IdentityDigit (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_TBCDEmergencyNumber_Numbers'. */
int SETITEMS_c_TBCDEmergencyNumber_Numbers (c_TBCDEmergencyNumber_Numbers* sequence, int desiredItems);
#define ADDITEMS_c_TBCDEmergencyNumber_Numbers(sequence, itemsToBeAdded) SETITEMS_c_TBCDEmergencyNumber_Numbers (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_ReceiveNPduNumbersList_sapi'. */
int SETITEMS_c_ReceiveNPduNumbersList_sapi (c_ReceiveNPduNumbersList_sapi* sequence, int desiredItems);
#define ADDITEMS_c_ReceiveNPduNumbersList_sapi(sequence, itemsToBeAdded) SETITEMS_c_ReceiveNPduNumbersList_sapi (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value'. */
int SETITEMS_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value (c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value* sequence, int desiredItems);
#define ADDITEMS_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value(sequence, itemsToBeAdded) SETITEMS_c_ReceiveNPduNumbersList_Receive_N_PDU_Number_value (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value'. */
int SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value* sequence, int desiredItems);
#define ADDITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value(sequence, itemsToBeAdded) SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value (sequence, (sequence)->items+itemsToBeAdded)

int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities(sp) ((sp)->Access_capabilities_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Length(sp,present) (((sp)->Length_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Length(sp) ((sp)->Length_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RF_Power_Capability(sp,present) (((sp)->RF_Power_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RF_Power_Capability(sp) ((sp)->RF_Power_Capability_Present)
int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_A5_bits(sp) ((sp)->A5_bits_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_ES_IND(sp,present) (((sp)->ES_IND_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_ES_IND(sp) ((sp)->ES_IND_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS(sp,present) (((sp)->PS_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS(sp) ((sp)->PS_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VGCS(sp,present) (((sp)->VGCS_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VGCS(sp) ((sp)->VGCS_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VBS(sp,present) (((sp)->VBS_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_VBS(sp) ((sp)->VBS_Present)
int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability(sp) ((sp)->Multislot_capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8PSK_Power_Capability(sp,present) (((sp)->_8PSK_Power_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8PSK_Power_Capability(sp) ((sp)->_8PSK_Power_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_COMPACT_Interference_Measurement_Capability(sp,present) (((sp)->COMPACT_Interference_Measurement_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_COMPACT_Interference_Measurement_Capability(sp) ((sp)->COMPACT_Interference_Measurement_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Revision_Level_Indicator(sp,present) (((sp)->Revision_Level_Indicator_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Revision_Level_Indicator(sp) ((sp)->Revision_Level_Indicator_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_FDD_Radio_Access_Technology_Capability(sp,present) (((sp)->UMTS_FDD_Radio_Access_Technology_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_FDD_Radio_Access_Technology_Capability(sp) ((sp)->UMTS_FDD_Radio_Access_Technology_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(sp,present) (((sp)->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(sp) ((sp)->UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_CDMA_2000_Radio_Access_Technology_Capability(sp,present) (((sp)->CDMA_2000_Radio_Access_Technology_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_CDMA_2000_Radio_Access_Technology_Capability(sp) ((sp)->CDMA_2000_Radio_Access_Technology_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(sp,present) (((sp)->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(sp) ((sp)->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Feature_Package_1(sp,present) (((sp)->GERAN_Feature_Package_1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Feature_Package_1(sp) ((sp)->GERAN_Feature_Package_1_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_GPRS_Multi_Slot_Class(sp,present) (((sp)->Extended_DTM_GPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_GPRS_Multi_Slot_Class(sp) ((sp)->Extended_DTM_GPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_EGPRS_Multi_Slot_Class(sp,present) (((sp)->Extended_DTM_EGPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_DTM_EGPRS_Multi_Slot_Class(sp) ((sp)->Extended_DTM_EGPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Modulation_based_multislot_class_support(sp,present) (((sp)->Modulation_based_multislot_class_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Modulation_based_multislot_class_support(sp) ((sp)->Modulation_based_multislot_class_support_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_High_Multislot_Capability(sp,present) (((sp)->High_Multislot_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_High_Multislot_Capability(sp) ((sp)->High_Multislot_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Length(sp,present) (((sp)->Length_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Length(sp) ((sp)->Length_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FLO_Iu_Capability(sp,present) (((sp)->FLO_Iu_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FLO_Iu_Capability(sp) ((sp)->FLO_Iu_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GMSK_Multislot_Power_Profile(sp,present) (((sp)->GMSK_Multislot_Power_Profile_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GMSK_Multislot_Power_Profile(sp) ((sp)->GMSK_Multislot_Power_Profile_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8_PSK_Multislot_Power_Profile(sp,present) (((sp)->_8_PSK_Multislot_Power_Profile_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities__8_PSK_Multislot_Power_Profile(sp) ((sp)->_8_PSK_Multislot_Power_Profile_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multiple_TBF_Capability(sp,present) (((sp)->Multiple_TBF_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multiple_TBF_Capability(sp) ((sp)->Multiple_TBF_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Advanced_Receiver_Performance(sp,present) (((sp)->Downlink_Advanced_Receiver_Performance_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Advanced_Receiver_Performance(sp) ((sp)->Downlink_Advanced_Receiver_Performance_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_RLC_MAC_Control_Message_Segmentation_Capability(sp,present) (((sp)->Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_RLC_MAC_Control_Message_Segmentation_Capability(sp) ((sp)->Extended_RLC_MAC_Control_Message_Segmentation_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Enhancements_Capability(sp,present) (((sp)->DTM_Enhancements_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Enhancements_Capability(sp) ((sp)->DTM_Enhancements_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_GPRS_High_Multi_Slot_Class(sp,present) (((sp)->DTM_GPRS_High_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_GPRS_High_Multi_Slot_Class(sp) ((sp)->DTM_GPRS_High_Multi_Slot_Class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_EGPRS_High_Multi_Slot_Class(sp,present) (((sp)->DTM_EGPRS_High_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_EGPRS_High_Multi_Slot_Class(sp) ((sp)->DTM_EGPRS_High_Multi_Slot_Class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS_Handover_Capability(sp,present) (((sp)->PS_Handover_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_PS_Handover_Capability(sp) ((sp)->PS_Handover_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Handover_Capability(sp,present) (((sp)->DTM_Handover_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTM_Handover_Capability(sp) ((sp)->DTM_Handover_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(sp,present) (((sp)->Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(sp) ((sp)->Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Dual_Carrier_for_DTM_Capability(sp,present) (((sp)->Downlink_Dual_Carrier_for_DTM_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_Dual_Carrier_for_DTM_Capability(sp) ((sp)->Downlink_Dual_Carrier_for_DTM_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Flexible_Timeslot_Assignment(sp,present) (((sp)->Flexible_Timeslot_Assignment_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Flexible_Timeslot_Assignment(sp) ((sp)->Flexible_Timeslot_Assignment_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GAN_PS_Handover_Capability(sp,present) (((sp)->GAN_PS_Handover_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GAN_PS_Handover_Capability(sp) ((sp)->GAN_PS_Handover_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RLC_Non_persistent_Mode(sp,present) (((sp)->RLC_Non_persistent_Mode_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_RLC_Non_persistent_Mode(sp) ((sp)->RLC_Non_persistent_Mode_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Reduced_Latency_Capability(sp,present) (((sp)->Reduced_Latency_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Reduced_Latency_Capability(sp) ((sp)->Reduced_Latency_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Uplink_EGPRS2(sp,present) (((sp)->Uplink_EGPRS2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Uplink_EGPRS2(sp) ((sp)->Uplink_EGPRS2_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_EGPRS2(sp,present) (((sp)->Downlink_EGPRS2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Downlink_EGPRS2(sp) ((sp)->Downlink_EGPRS2_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_FDD_support(sp,present) (((sp)->E_UTRA_FDD_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_FDD_support(sp) ((sp)->E_UTRA_FDD_support_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_TDD_support(sp,present) (((sp)->E_UTRA_TDD_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_TDD_support(sp) ((sp)->E_UTRA_TDD_support_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode(sp,present) (((sp)->GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode(sp) ((sp)->GERAN_to_E_UTRA_support_in_GERAN_packet_transfer_mode_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Priority_based_reselection_support(sp,present) (((sp)->Priority_based_reselection_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Priority_based_reselection_support(sp) ((sp)->Priority_based_reselection_support_Present)
int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment(sp) ((sp)->Enhanced_Flexible_Timeslot_Assignment_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM(sp,present) (((sp)->Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM(sp) ((sp)->Indication_of_Upper_Layer_PDU_Start_Capability_for_RLC_UM_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMST_Capability(sp,present) (((sp)->EMST_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMST_Capability(sp) ((sp)->EMST_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_MTTI_Capability(sp,present) (((sp)->MTTI_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_MTTI_Capability(sp) ((sp)->MTTI_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_CSG_Cells_Reporting(sp,present) (((sp)->UTRA_CSG_Cells_Reporting_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_CSG_Cells_Reporting(sp) ((sp)->UTRA_CSG_Cells_Reporting_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_CSG_Cells_Reporting(sp,present) (((sp)->E_UTRA_CSG_Cells_Reporting_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_CSG_Cells_Reporting(sp) ((sp)->E_UTRA_CSG_Cells_Reporting_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTR_Capability(sp,present) (((sp)->DTR_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DTR_Capability(sp) ((sp)->DTR_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMSR_Capability(sp,present) (((sp)->EMSR_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_EMSR_Capability(sp) ((sp)->EMSR_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Fast_Downlink_Frequency_Switching_Capability(sp,present) (((sp)->Fast_Downlink_Frequency_Switching_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Fast_Downlink_Frequency_Switching_Capability(sp) ((sp)->Fast_Downlink_Frequency_Switching_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_TIGHTER_Capability(sp,present) (((sp)->TIGHTER_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_TIGHTER_Capability(sp) ((sp)->TIGHTER_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FANR_Capability(sp,present) (((sp)->FANR_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_FANR_Capability(sp) ((sp)->FANR_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_IPA_Capability(sp,present) (((sp)->IPA_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_IPA_Capability(sp) ((sp)->IPA_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Network_Sharing_support(sp,present) (((sp)->GERAN_Network_Sharing_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_GERAN_Network_Sharing_support(sp) ((sp)->GERAN_Network_Sharing_support_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Wideband_RSRQ_measurements_support(sp,present) (((sp)->E_UTRA_Wideband_RSRQ_measurements_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Wideband_RSRQ_measurements_support(sp) ((sp)->E_UTRA_Wideband_RSRQ_measurements_support_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_Multiple_Frequency_Band_Indicators_support(sp,present) (((sp)->UTRA_Multiple_Frequency_Band_Indicators_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_UTRA_Multiple_Frequency_Band_Indicators_support(sp) ((sp)->UTRA_Multiple_Frequency_Band_Indicators_support_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Multiple_Frequency_Band_Indicators_support(sp,present) (((sp)->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_E_UTRA_Multiple_Frequency_Band_Indicators_support(sp) ((sp)->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present)
int SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability(sp) ((sp)->DLMC_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_TSC_Set_Capability_support(sp,present) (((sp)->Extended_TSC_Set_Capability_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_TSC_Set_Capability_support(sp) ((sp)->Extended_TSC_Set_Capability_support_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_EARFCN_value_range(sp,present) (((sp)->Extended_EARFCN_value_range_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Extended_EARFCN_value_range(sp) ((sp)->Extended_EARFCN_value_range_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_HSCSD_multislot_class(sp,present) (((sp)->HSCSD_multislot_class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_HSCSD_multislot_class(sp) ((sp)->HSCSD_multislot_class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_multislot_class(sp,present) (((sp)->GPRS_multislot_class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_multislot_class(sp) ((sp)->GPRS_multislot_class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_Extended_Dynamic_Allocation_Capability(sp,present) (((sp)->GPRS_Extended_Dynamic_Allocation_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_GPRS_Extended_Dynamic_Allocation_Capability(sp) ((sp)->GPRS_Extended_Dynamic_Allocation_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SMS_VALUE(sp,present) (((sp)->SMS_VALUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SMS_VALUE(sp) ((sp)->SMS_VALUE_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SM_VALUE(sp,present) (((sp)->SM_VALUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_SM_VALUE(sp) ((sp)->SM_VALUE_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_ECSD_multislot_class(sp,present) (((sp)->ECSD_multislot_class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_ECSD_multislot_class(sp) ((sp)->ECSD_multislot_class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_multislot_class(sp,present) (((sp)->EGPRS_multislot_class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_multislot_class(sp) ((sp)->EGPRS_multislot_class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_Extended_Dynamic_Allocation_Capability(sp,present) (((sp)->EGPRS_Extended_Dynamic_Allocation_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_EGPRS_Extended_Dynamic_Allocation_Capability(sp) ((sp)->EGPRS_Extended_Dynamic_Allocation_Capability_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_GPRS_Multi_Slot_Class(sp,present) (((sp)->DTM_GPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_GPRS_Multi_Slot_Class(sp) ((sp)->DTM_GPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_Single_Slot_DTM(sp,present) (((sp)->Single_Slot_DTM_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_Single_Slot_DTM(sp) ((sp)->Single_Slot_DTM_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_EGPRS_Multi_Slot_Class(sp,present) (((sp)->DTM_EGPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Multislot_capability_DTM_EGPRS_Multi_Slot_Class(sp) ((sp)->DTM_EGPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_Alternative_EFTA_Multislot_Class(sp,present) (((sp)->Alternative_EFTA_Multislot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_Alternative_EFTA_Multislot_Class(sp) ((sp)->Alternative_EFTA_Multislot_Class_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(sp,present) (((sp)->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_Enhanced_Flexible_Timeslot_Assignment_EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier(sp) ((sp)->EFTA_Multislot_Capability_Reduction_for_Downlink_Dual_Carrier_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Non_contiguous_intra_band_reception(sp,present) (((sp)->DLMC_Non_contiguous_intra_band_reception_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Non_contiguous_intra_band_reception(sp) ((sp)->DLMC_Non_contiguous_intra_band_reception_Present)
#define SETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Inter_band_reception(sp,present) (((sp)->DLMC_Inter_band_reception_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Access_capabilities_Access_capabilities_DLMC_Capability_DLMC_Inter_band_reception(sp) ((sp)->DLMC_Inter_band_reception_Present)
/* SETITEMS/ADDITEMS commands for type 'c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies'. */
int SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies (c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies* sequence, int desiredItems);
#define ADDITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies(sequence, itemsToBeAdded) SETITEMS_c_MsRadioAccessCpblty_MS_RA_capability_value_part_MS_RA_capability_value_data_Additional_access_technologies (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_ProtocolCfgOpt_ProtocolCfgs'. */
int SETITEMS_c_ProtocolCfgOpt_ProtocolCfgs (c_ProtocolCfgOpt_ProtocolCfgs* sequence, int desiredItems);
#define ADDITEMS_c_ProtocolCfgOpt_ProtocolCfgs(sequence, itemsToBeAdded) SETITEMS_c_ProtocolCfgOpt_ProtocolCfgs (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_ProtocolCfgOpt_ContainerCfgs'. */
int SETITEMS_c_ProtocolCfgOpt_ContainerCfgs (c_ProtocolCfgOpt_ContainerCfgs* sequence, int desiredItems);
#define ADDITEMS_c_ProtocolCfgOpt_ContainerCfgs(sequence, itemsToBeAdded) SETITEMS_c_ProtocolCfgOpt_ContainerCfgs (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_TrafficFlowTemplate_PacketFilters'. */
int SETITEMS_c_TrafficFlowTemplate_PacketFilters (c_TrafficFlowTemplate_PacketFilters* sequence, int desiredItems);
#define ADDITEMS_c_TrafficFlowTemplate_PacketFilters(sequence, itemsToBeAdded) SETITEMS_c_TrafficFlowTemplate_PacketFilters (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_TrafficFlowTemplate_PacketFilters_data_FilterContents'. */
int SETITEMS_c_TrafficFlowTemplate_PacketFilters_data_FilterContents (c_TrafficFlowTemplate_PacketFilters_data_FilterContents* sequence, int desiredItems);
#define ADDITEMS_c_TrafficFlowTemplate_PacketFilters_data_FilterContents(sequence, itemsToBeAdded) SETITEMS_c_TrafficFlowTemplate_PacketFilters_data_FilterContents (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_TrafficFlowTemplate_PacketParameters'. */
int SETITEMS_c_TrafficFlowTemplate_PacketParameters (c_TrafficFlowTemplate_PacketParameters* sequence, int desiredItems);
#define ADDITEMS_c_TrafficFlowTemplate_PacketParameters(sequence, itemsToBeAdded) SETITEMS_c_TrafficFlowTemplate_PacketParameters (sequence, (sequence)->items+itemsToBeAdded)

#ifdef __cplusplus
}
#endif

#endif

