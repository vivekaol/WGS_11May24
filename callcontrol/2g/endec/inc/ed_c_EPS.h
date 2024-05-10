/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c
	http://www.Dafocus.it/
**************************************************************************/

#ifndef __ed_c_EPS_h_H
#define __ed_c_EPS_h_H

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


/* Access member 'IdentityType' of type 'c_RemoteUEContext_Identity' as a variable reference */
#define VAR_c_RemoteUEContext_Identity_IdentityType(var) var

/* Access member 'IdentityType' of type 'c_RemoteUEContext_Identity' as a pointer */
#define PTR_c_RemoteUEContext_Identity_IdentityType(var) (&var)

/* Access member 'data' of type 'c_RemoteUEContext_Identity_IdentityDigit' as a variable reference */
#define VAR_c_RemoteUEContext_Identity_IdentityDigit_data(var) var

/* Access member 'data' of type 'c_RemoteUEContext_Identity_IdentityDigit' as a pointer */
#define PTR_c_RemoteUEContext_Identity_IdentityDigit_data(var) (&var)

/* Access member 'IdentityDigit' of type 'c_RemoteUEContext_Identity' as a variable reference */
#define VAR_c_RemoteUEContext_Identity_IdentityDigit(var) var

/* Access member 'IdentityDigit' of type 'c_RemoteUEContext_Identity' as a pointer */
#define PTR_c_RemoteUEContext_Identity_IdentityDigit(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_RemoteUEContext_Identity_IdentityDigit */
typedef struct _c_RemoteUEContext_Identity_IdentityDigit {

	ED_LONG* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-14795=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_RemoteUEContext_Identity_IdentityDigit;


/*-A----------------------------------*/
typedef struct _c_RemoteUEContext_Identity {
	ED_LOCATOR IdentityType___LOCATOR; /* QUI2 */

	ED_LONG IdentityType; /* ODY01a *//*GBD01b*/
	c_RemoteUEContext_Identity_IdentityDigit IdentityDigit;/*GFB09*//*GBD01b*/

}	c_RemoteUEContext_Identity;
#define INIT_c_RemoteUEContext_Identity(sp) ED_RESET_MEM ((sp), sizeof (c_RemoteUEContext_Identity))
/*FRK03a*/
void FREE_c_RemoteUEContext_Identity(c_RemoteUEContext_Identity* sp);

/* Access member 'ProtocolId' of type 'c_epsProtocolCfg' as a variable reference */
#define VAR_c_epsProtocolCfg_ProtocolId(var) var

/* Access member 'ProtocolId' of type 'c_epsProtocolCfg' as a pointer */
#define PTR_c_epsProtocolCfg_ProtocolId(var) (&var)

/* Access member 'Contents' of type 'c_epsProtocolCfg' as a variable reference */
#define VAR_c_epsProtocolCfg_Contents(var) var

/* Access member 'Contents' of type 'c_epsProtocolCfg' as a pointer */
#define PTR_c_epsProtocolCfg_Contents(var) (&var)

/* DEFINITION OF BINARY c_epsProtocolCfg_Contents */
typedef struct _c_epsProtocolCfg_Contents {
	ED_BYTE* value; /* Variable size; bits needed 512 */
	int usedBits;
} c_epsProtocolCfg_Contents;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_epsProtocolCfg_Contents(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_epsProtocolCfg {
	ED_LOCATOR ProtocolId___LOCATOR; /* QUI2 */
	ED_LOCATOR Contents___LOCATOR  /*LBD02*/;

	ED_LONG ProtocolId; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfg_Contents Contents; /* Static, variable size; bits needed 512 *//*GBD01b*/

}	c_epsProtocolCfg;
#define INIT_c_epsProtocolCfg(sp) ED_RESET_MEM ((sp), sizeof (c_epsProtocolCfg))
/*FRK03a*/
void FREE_c_epsProtocolCfg(c_epsProtocolCfg* sp);

/* Access member 'data' of type 'c_RemoteUEContext_SingleContext_UserIDs' as a variable reference */
#define VAR_c_RemoteUEContext_SingleContext_UserIDs_data(var) (*var)

/* Access member 'data' of type 'c_RemoteUEContext_SingleContext_UserIDs' as a pointer */
#define PTR_c_RemoteUEContext_SingleContext_UserIDs_data(var) var

/* Access member 'UserIDs' of type 'c_RemoteUEContext_SingleContext' as a variable reference */
#define VAR_c_RemoteUEContext_SingleContext_UserIDs(var) var

/* Access member 'UserIDs' of type 'c_RemoteUEContext_SingleContext' as a pointer */
#define PTR_c_RemoteUEContext_SingleContext_UserIDs(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_RemoteUEContext_SingleContext_UserIDs */
typedef struct _c_RemoteUEContext_SingleContext_UserIDs {

	c_RemoteUEContext_Identity **data; /* NDY01 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_RemoteUEContext_SingleContext_UserIDs;


/*-A----------------------------------*/
typedef struct _c_RemoteUEContext_SingleContext {

	c_RemoteUEContext_SingleContext_UserIDs UserIDs;/*GFB09*//*GBD01b*/

}	c_RemoteUEContext_SingleContext;
#define INIT_c_RemoteUEContext_SingleContext(sp) ED_RESET_MEM ((sp), sizeof (c_RemoteUEContext_SingleContext))
/*FRK03a*/
void FREE_c_RemoteUEContext_SingleContext(c_RemoteUEContext_SingleContext* sp);

/* Access member 'MCC2' of type 'c_PartialTrackingAreaIdentity_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentity_Type2_MCC2(var) var

/* Access member 'MCC2' of type 'c_PartialTrackingAreaIdentity_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentity_Type2_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_PartialTrackingAreaIdentity_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentity_Type2_MCC1(var) var

/* Access member 'MCC1' of type 'c_PartialTrackingAreaIdentity_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentity_Type2_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_PartialTrackingAreaIdentity_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentity_Type2_MNC3(var) var

/* Access member 'MNC3' of type 'c_PartialTrackingAreaIdentity_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentity_Type2_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_PartialTrackingAreaIdentity_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentity_Type2_MCC3(var) var

/* Access member 'MCC3' of type 'c_PartialTrackingAreaIdentity_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentity_Type2_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_PartialTrackingAreaIdentity_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentity_Type2_MNC2(var) var

/* Access member 'MNC2' of type 'c_PartialTrackingAreaIdentity_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentity_Type2_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_PartialTrackingAreaIdentity_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentity_Type2_MNC1(var) var

/* Access member 'MNC1' of type 'c_PartialTrackingAreaIdentity_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentity_Type2_MNC1(var) (&var)

/* Access member 'TAC' of type 'c_PartialTrackingAreaIdentity_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentity_Type2_TAC(var) var

/* Access member 'TAC' of type 'c_PartialTrackingAreaIdentity_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentity_Type2_TAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PartialTrackingAreaIdentity_Type2 {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR TAC___LOCATOR; /* QUI2 */

	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_SHORT TAC; /* ODY01a *//*GBD01b*/

}	c_PartialTrackingAreaIdentity_Type2;
#define INIT_c_PartialTrackingAreaIdentity_Type2(sp) ED_RESET_MEM ((sp), sizeof (c_PartialTrackingAreaIdentity_Type2))
/*FRK03a*/
void FREE_c_PartialTrackingAreaIdentity_Type2(c_PartialTrackingAreaIdentity_Type2* sp);

/* Access member 'data' of type 'c_PartialTrackingAreaIdentityList_TACS' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_TACS_data(var) var

/* Access member 'data' of type 'c_PartialTrackingAreaIdentityList_TACS' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_TACS_data(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PartialTrackingAreaIdentityList_TACS {

		ED_SHORT* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-14174=EDCore::TDMSequence)  */
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_PartialTrackingAreaIdentityList_TACS;
#define INIT_c_PartialTrackingAreaIdentityList_TACS(sp) ED_RESET_MEM ((sp), sizeof (c_PartialTrackingAreaIdentityList_TACS))
/*FRK02b*/
void FREE_c_PartialTrackingAreaIdentityList_TACS (c_PartialTrackingAreaIdentityList_TACS* sp);
/* SETITEMS/ADDITEMS commands for type 'c_PartialTrackingAreaIdentityList_TACS'. */
int SETITEMS_c_PartialTrackingAreaIdentityList_TACS (c_PartialTrackingAreaIdentityList_TACS* sequence, int desiredItems);
#define ADDITEMS_c_PartialTrackingAreaIdentityList_TACS(sequence, itemsToBeAdded) SETITEMS_c_PartialTrackingAreaIdentityList_TACS (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'data' of type 'c_epsProtocolCfgList' as a variable reference */
#define VAR_c_epsProtocolCfgList_data(var) (*var)

/* Access member 'data' of type 'c_epsProtocolCfgList' as a pointer */
#define PTR_c_epsProtocolCfgList_data(var) var


/*-A----------------------------------*/
typedef struct _c_epsProtocolCfgList {

		c_epsProtocolCfg **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_epsProtocolCfgList;
#define INIT_c_epsProtocolCfgList(sp) ED_RESET_MEM ((sp), sizeof (c_epsProtocolCfgList))
/*FRK02b*/
void FREE_c_epsProtocolCfgList (c_epsProtocolCfgList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_epsProtocolCfgList'. */
int SETITEMS_c_epsProtocolCfgList (c_epsProtocolCfgList* sequence, int desiredItems);
#define ADDITEMS_c_epsProtocolCfgList(sequence, itemsToBeAdded) SETITEMS_c_epsProtocolCfgList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'MCC2' of type 'c_PartialTrackingAreaIdentityList_Type0' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type0_MCC2(var) var

/* Access member 'MCC2' of type 'c_PartialTrackingAreaIdentityList_Type0' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type0_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_PartialTrackingAreaIdentityList_Type0' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type0_MCC1(var) var

/* Access member 'MCC1' of type 'c_PartialTrackingAreaIdentityList_Type0' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type0_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_PartialTrackingAreaIdentityList_Type0' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type0_MNC3(var) var

/* Access member 'MNC3' of type 'c_PartialTrackingAreaIdentityList_Type0' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type0_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_PartialTrackingAreaIdentityList_Type0' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type0_MCC3(var) var

/* Access member 'MCC3' of type 'c_PartialTrackingAreaIdentityList_Type0' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type0_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_PartialTrackingAreaIdentityList_Type0' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type0_MNC2(var) var

/* Access member 'MNC2' of type 'c_PartialTrackingAreaIdentityList_Type0' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type0_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_PartialTrackingAreaIdentityList_Type0' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type0_MNC1(var) var

/* Access member 'MNC1' of type 'c_PartialTrackingAreaIdentityList_Type0' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type0_MNC1(var) (&var)

/* Access member 'TAC' of type 'c_PartialTrackingAreaIdentityList_Type0' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type0_TAC(var) var

/* Access member 'TAC' of type 'c_PartialTrackingAreaIdentityList_Type0' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type0_TAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PartialTrackingAreaIdentityList_Type0 {
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
	c_PartialTrackingAreaIdentityList_TACS TAC; /* ODY01a *//*GBD01b*/

}	c_PartialTrackingAreaIdentityList_Type0;
#define INIT_c_PartialTrackingAreaIdentityList_Type0(sp) ED_RESET_MEM ((sp), sizeof (c_PartialTrackingAreaIdentityList_Type0))
/*FRK03a*/
void FREE_c_PartialTrackingAreaIdentityList_Type0(c_PartialTrackingAreaIdentityList_Type0* sp);

/* Access member 'spare' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_spare(var) var

/* Access member 'spare' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_spare(var) (&var)

/* Access member 'TypeOfList' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_TypeOfList(var) var

/* Access member 'TypeOfList' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_TypeOfList(var) (&var)

/* Access member 'NumberOfElements' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_NumberOfElements(var) var

/* Access member 'NumberOfElements' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_NumberOfElements(var) (&var)

/* Access member 'MCC2' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_MCC2(var) var

/* Access member 'MCC2' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_MCC1(var) var

/* Access member 'MCC1' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_MNC3(var) var

/* Access member 'MNC3' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_MCC3(var) var

/* Access member 'MCC3' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_MNC2(var) var

/* Access member 'MNC2' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_MNC1(var) var

/* Access member 'MNC1' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_MNC1(var) (&var)

/* Access member 'TAC' of type 'c_PartialTrackingAreaIdentityList_Type1' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type1_TAC(var) var

/* Access member 'TAC' of type 'c_PartialTrackingAreaIdentityList_Type1' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type1_TAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_PartialTrackingAreaIdentityList_Type1 {
	ED_LOCATOR NumberOfElements___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR TAC___LOCATOR; /* QUI2 */

	/*GBD01b*/
	/*GBD01b*/
	ED_OCTET NumberOfElements; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_SHORT TAC; /* ODY01a *//*GBD01b*/

}	c_PartialTrackingAreaIdentityList_Type1;
#define INIT_c_PartialTrackingAreaIdentityList_Type1(sp) ED_RESET_MEM ((sp), sizeof (c_PartialTrackingAreaIdentityList_Type1))
/*FRK03a*/
void FREE_c_PartialTrackingAreaIdentityList_Type1(c_PartialTrackingAreaIdentityList_Type1* sp);

/* Access member 'spare' of type 'c_PDNAddress' as a variable reference */
#define VAR_c_PDNAddress_spare(var) var

/* Access member 'spare' of type 'c_PDNAddress' as a pointer */
#define PTR_c_PDNAddress_spare(var) (&var)

/* Access member 'PDNType' of type 'c_PDNAddress' as a variable reference */
#define VAR_c_PDNAddress_PDNType(var) var

/* Access member 'PDNType' of type 'c_PDNAddress' as a pointer */
#define PTR_c_PDNAddress_PDNType(var) (&var)

/* Access member 'PDNAddressInformation' of type 'c_PDNAddress' as a variable reference */
#define VAR_c_PDNAddress_PDNAddressInformation(var) var

/* Access member 'PDNAddressInformation' of type 'c_PDNAddress' as a pointer */
#define PTR_c_PDNAddress_PDNAddressInformation(var) (&var)

/* DEFINITION OF BINARY c_PDNAddress_PDNAddressInformation */
typedef struct _c_PDNAddress_PDNAddressInformation {
	ED_BYTE* value; /* Variable size; bits needed 96 */
	int usedBits;
} c_PDNAddress_PDNAddressInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_PDNAddress_PDNAddressInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_PDNAddress {
	ED_LOCATOR PDNType___LOCATOR; /* QUI2 */
	ED_LOCATOR PDNAddressInformation___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET PDNType; /* ODY01a *//*GBD01b*/
	c_PDNAddress_PDNAddressInformation PDNAddressInformation; /* Static, variable size; bits needed 96 *//*GBD01b*/

}	c_PDNAddress;
#define INIT_c_PDNAddress(sp) ED_RESET_MEM ((sp), sizeof (c_PDNAddress))
/*FRK03a*/
void FREE_c_PDNAddress(c_PDNAddress* sp);

/* Access member 'spare' of type 'c_epsReAttemptIndicator' as a variable reference */
#define VAR_c_epsReAttemptIndicator_spare(var) var

/* Access member 'spare' of type 'c_epsReAttemptIndicator' as a pointer */
#define PTR_c_epsReAttemptIndicator_spare(var) (&var)

/* Access member 'EPLMNC' of type 'c_epsReAttemptIndicator' as a variable reference */
#define VAR_c_epsReAttemptIndicator_EPLMNC(var) var

/* Access member 'EPLMNC' of type 'c_epsReAttemptIndicator' as a pointer */
#define PTR_c_epsReAttemptIndicator_EPLMNC(var) (&var)

/* Access member 'RATC' of type 'c_epsReAttemptIndicator' as a variable reference */
#define VAR_c_epsReAttemptIndicator_RATC(var) var

/* Access member 'RATC' of type 'c_epsReAttemptIndicator' as a pointer */
#define PTR_c_epsReAttemptIndicator_RATC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsReAttemptIndicator {
	ED_LOCATOR EPLMNC___LOCATOR; /* QUI2 */
	ED_LOCATOR RATC___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN EPLMNC; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RATC; /* ODY01a *//*GBD01b*/

}	c_epsReAttemptIndicator;
#define INIT_c_epsReAttemptIndicator(sp) ED_RESET_MEM ((sp), sizeof (c_epsReAttemptIndicator))
/*FRK03a*/
void FREE_c_epsReAttemptIndicator(c_epsReAttemptIndicator* sp);

/* Access member 'spare' of type 'c_PKMFAddress' as a variable reference */
#define VAR_c_PKMFAddress_spare(var) var

/* Access member 'spare' of type 'c_PKMFAddress' as a pointer */
#define PTR_c_PKMFAddress_spare(var) (&var)

/* Access member 'addressType' of type 'c_PKMFAddress' as a variable reference */
#define VAR_c_PKMFAddress_addressType(var) var

/* Access member 'addressType' of type 'c_PKMFAddress' as a pointer */
#define PTR_c_PKMFAddress_addressType(var) (&var)

/* Access member 'AddressInformation' of type 'c_PKMFAddress' as a variable reference */
#define VAR_c_PKMFAddress_AddressInformation(var) var

/* Access member 'AddressInformation' of type 'c_PKMFAddress' as a pointer */
#define PTR_c_PKMFAddress_AddressInformation(var) (&var)

/* DEFINITION OF BINARY c_PKMFAddress_AddressInformation */
typedef struct _c_PKMFAddress_AddressInformation {
	ED_BYTE* value; /* Variable size; bits needed 120 */
	int usedBits;
} c_PKMFAddress_AddressInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_PKMFAddress_AddressInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_PKMFAddress {
	ED_LOCATOR addressType___LOCATOR; /* QUI2 */
	ED_LOCATOR AddressInformation___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET addressType; /* ODY01a *//*GBD01b*/
	c_PKMFAddress_AddressInformation AddressInformation; /* Static, variable size; bits needed 120 *//*GBD01b*/

}	c_PKMFAddress;
#define INIT_c_PKMFAddress(sp) ED_RESET_MEM ((sp), sizeof (c_PKMFAddress))
/*FRK03a*/
void FREE_c_PKMFAddress(c_PKMFAddress* sp);

/* Access member 'Spare' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_Spare(var) var

/* Access member 'Spare' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_Spare(var) (&var)

/* Access member 'P0x0104' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_P0x0104(var) var

/* Access member 'P0x0104' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_P0x0104(var) (&var)

/* Access member 'P0x0103' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_P0x0103(var) var

/* Access member 'P0x0103' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_P0x0103(var) (&var)

/* Access member 'P0x0102' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_P0x0102(var) var

/* Access member 'P0x0102' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_P0x0102(var) (&var)

/* Access member 'P0x0006' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_P0x0006(var) var

/* Access member 'P0x0006' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_P0x0006(var) (&var)

/* Access member 'P0x0004' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_P0x0004(var) var

/* Access member 'P0x0004' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_P0x0004(var) (&var)

/* Access member 'P0x0003' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_P0x0003(var) var

/* Access member 'P0x0003' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_P0x0003(var) (&var)

/* Access member 'P0x0002' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_P0x0002(var) var

/* Access member 'P0x0002' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_P0x0002(var) (&var)

/* Access member 'MAX_CID' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_MAX_CID(var) var

/* Access member 'MAX_CID' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_MAX_CID(var) (&var)

/* Access member 'Parameters' of type 'c_HeaderCompressionCfg' as a variable reference */
#define VAR_c_HeaderCompressionCfg_Parameters(var) var

/* Access member 'Parameters' of type 'c_HeaderCompressionCfg' as a pointer */
#define PTR_c_HeaderCompressionCfg_Parameters(var) (&var)

/* DEFINITION OF BINARY c_HeaderCompressionCfg_Parameters */
typedef struct _c_HeaderCompressionCfg_Parameters {
	ED_BYTE* value; /* Variable size; bits needed 2016 */
	int usedBits;
} c_HeaderCompressionCfg_Parameters;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_HeaderCompressionCfg_Parameters(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_HeaderCompressionCfg {
	ED_LOCATOR P0x0104___LOCATOR; /* QUI2 */
	ED_LOCATOR P0x0103___LOCATOR; /* QUI2 */
	ED_LOCATOR P0x0102___LOCATOR; /* QUI2 */
	ED_LOCATOR P0x0006___LOCATOR; /* QUI2 */
	ED_LOCATOR P0x0004___LOCATOR; /* QUI2 */
	ED_LOCATOR P0x0003___LOCATOR; /* QUI2 */
	ED_LOCATOR P0x0002___LOCATOR; /* QUI2 */
	ED_LOCATOR MAX_CID___LOCATOR; /* QUI2 */
	ED_LOCATOR Parameters___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_BOOLEAN P0x0104; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN P0x0103; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN P0x0102; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN P0x0006; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN P0x0004; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN P0x0003; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN P0x0002; /* ODY01a *//*GBD01b*/
	ED_SHORT MAX_CID; /* ODY01a *//*GBD01b*/
	c_HeaderCompressionCfg_Parameters Parameters; /* Static, variable size; bits needed 2016 *//*GBD01b*/

}	c_HeaderCompressionCfg;
#define INIT_c_HeaderCompressionCfg(sp) ED_RESET_MEM ((sp), sizeof (c_HeaderCompressionCfg))
/*FRK03a*/
void FREE_c_HeaderCompressionCfg(c_HeaderCompressionCfg* sp);

/* Access member 'spare' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_spare(var) var

/* Access member 'spare' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_spare(var) (&var)

/* Access member 'AutomaticallyInitiatedECall' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_AutomaticallyInitiatedECall(var) var

/* Access member 'AutomaticallyInitiatedECall' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_AutomaticallyInitiatedECall(var) (&var)

/* Access member 'ManuallyInitiatedECall' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_ManuallyInitiatedECall(var) var

/* Access member 'ManuallyInitiatedECall' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_ManuallyInitiatedECall(var) (&var)

/* Access member 'MountainRescue' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_MountainRescue(var) var

/* Access member 'MountainRescue' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_MountainRescue(var) (&var)

/* Access member 'MarineGuard' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_MarineGuard(var) var

/* Access member 'MarineGuard' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_MarineGuard(var) (&var)

/* Access member 'FireBrigade' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_FireBrigade(var) var

/* Access member 'FireBrigade' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_FireBrigade(var) (&var)

/* Access member 'Ambulance' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_Ambulance(var) var

/* Access member 'Ambulance' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_Ambulance(var) (&var)

/* Access member 'Police' of type 'c_epsServCategory' as a variable reference */
#define VAR_c_epsServCategory_Police(var) var

/* Access member 'Police' of type 'c_epsServCategory' as a pointer */
#define PTR_c_epsServCategory_Police(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsServCategory {
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

}	c_epsServCategory;
#define INIT_c_epsServCategory(sp) ED_RESET_MEM ((sp), sizeof (c_epsServCategory))
/*FRK03a*/
void FREE_c_epsServCategory(c_epsServCategory* sp);

/* Access member 'spare' of type 'c_epsLlcServAccessPointId' as a variable reference */
#define VAR_c_epsLlcServAccessPointId_spare(var) var

/* Access member 'spare' of type 'c_epsLlcServAccessPointId' as a pointer */
#define PTR_c_epsLlcServAccessPointId_spare(var) (&var)

/* Access member 'LLCSAPIValue' of type 'c_epsLlcServAccessPointId' as a variable reference */
#define VAR_c_epsLlcServAccessPointId_LLCSAPIValue(var) var

/* Access member 'LLCSAPIValue' of type 'c_epsLlcServAccessPointId' as a pointer */
#define PTR_c_epsLlcServAccessPointId_LLCSAPIValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsLlcServAccessPointId {
	ED_LOCATOR LLCSAPIValue___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET LLCSAPIValue; /* ODY01a *//*GBD01b*/

}	c_epsLlcServAccessPointId;
#define INIT_c_epsLlcServAccessPointId(sp) ED_RESET_MEM ((sp), sizeof (c_epsLlcServAccessPointId))
/*FRK03a*/
void FREE_c_epsLlcServAccessPointId(c_epsLlcServAccessPointId* sp);

/* Access member 'spare' of type 'c_epsPacketFlowIdentifie' as a variable reference */
#define VAR_c_epsPacketFlowIdentifie_spare(var) var

/* Access member 'spare' of type 'c_epsPacketFlowIdentifie' as a pointer */
#define PTR_c_epsPacketFlowIdentifie_spare(var) (&var)

/* Access member 'PacketFlowIdentifierValue' of type 'c_epsPacketFlowIdentifie' as a variable reference */
#define VAR_c_epsPacketFlowIdentifie_PacketFlowIdentifierValue(var) var

/* Access member 'PacketFlowIdentifierValue' of type 'c_epsPacketFlowIdentifie' as a pointer */
#define PTR_c_epsPacketFlowIdentifie_PacketFlowIdentifierValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsPacketFlowIdentifie {
	ED_LOCATOR PacketFlowIdentifierValue___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET PacketFlowIdentifierValue; /* ODY01a *//*GBD01b*/

}	c_epsPacketFlowIdentifie;
#define INIT_c_epsPacketFlowIdentifie(sp) ED_RESET_MEM ((sp), sizeof (c_epsPacketFlowIdentifie))
/*FRK03a*/
void FREE_c_epsPacketFlowIdentifie(c_epsPacketFlowIdentifie* sp);

/* Access member 'connType' of type 'c_epsConnectivityType' as a variable reference */
#define VAR_c_epsConnectivityType_connType(var) var

/* Access member 'connType' of type 'c_epsConnectivityType' as a pointer */
#define PTR_c_epsConnectivityType_connType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsConnectivityType {
	ED_LOCATOR connType___LOCATOR; /* QUI2 */

	ED_OCTET connType; /* ODY01a *//*GBD01b*/

}	c_epsConnectivityType;
#define INIT_c_epsConnectivityType(sp) ED_RESET_MEM ((sp), sizeof (c_epsConnectivityType))
/*FRK03a*/
void FREE_c_epsConnectivityType(c_epsConnectivityType* sp);

/* Access member 'spare' of type 'c_epsWLANOffloadAcceptability' as a variable reference */
#define VAR_c_epsWLANOffloadAcceptability_spare(var) var

/* Access member 'spare' of type 'c_epsWLANOffloadAcceptability' as a pointer */
#define PTR_c_epsWLANOffloadAcceptability_spare(var) (&var)

/* Access member 'UTRAN_Offload_Acceptability_Value' of type 'c_epsWLANOffloadAcceptability' as a variable reference */
#define VAR_c_epsWLANOffloadAcceptability_UTRAN_Offload_Acceptability_Value(var) var

/* Access member 'UTRAN_Offload_Acceptability_Value' of type 'c_epsWLANOffloadAcceptability' as a pointer */
#define PTR_c_epsWLANOffloadAcceptability_UTRAN_Offload_Acceptability_Value(var) (&var)

/* Access member 'EUTRAN_Offload_Acceptability_Value' of type 'c_epsWLANOffloadAcceptability' as a variable reference */
#define VAR_c_epsWLANOffloadAcceptability_EUTRAN_Offload_Acceptability_Value(var) var

/* Access member 'EUTRAN_Offload_Acceptability_Value' of type 'c_epsWLANOffloadAcceptability' as a pointer */
#define PTR_c_epsWLANOffloadAcceptability_EUTRAN_Offload_Acceptability_Value(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsWLANOffloadAcceptability {
	ED_LOCATOR UTRAN_Offload_Acceptability_Value___LOCATOR; /* QUI2 */
	ED_LOCATOR EUTRAN_Offload_Acceptability_Value___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN UTRAN_Offload_Acceptability_Value; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EUTRAN_Offload_Acceptability_Value; /* ODY01a *//*GBD01b*/

}	c_epsWLANOffloadAcceptability;
#define INIT_c_epsWLANOffloadAcceptability(sp) ED_RESET_MEM ((sp), sizeof (c_epsWLANOffloadAcceptability))
/*FRK03a*/
void FREE_c_epsWLANOffloadAcceptability(c_epsWLANOffloadAcceptability* sp);

/* Access member 'spare' of type 'c_epsDeviceProperties' as a variable reference */
#define VAR_c_epsDeviceProperties_spare(var) var

/* Access member 'spare' of type 'c_epsDeviceProperties' as a pointer */
#define PTR_c_epsDeviceProperties_spare(var) (&var)

/* Access member 'lowPriority' of type 'c_epsDeviceProperties' as a variable reference */
#define VAR_c_epsDeviceProperties_lowPriority(var) var

/* Access member 'lowPriority' of type 'c_epsDeviceProperties' as a pointer */
#define PTR_c_epsDeviceProperties_lowPriority(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsDeviceProperties {
	ED_LOCATOR lowPriority___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN lowPriority; /* ODY01a *//*GBD01b*/

}	c_epsDeviceProperties;
#define INIT_c_epsDeviceProperties(sp) ED_RESET_MEM ((sp), sizeof (c_epsDeviceProperties))
/*FRK03a*/
void FREE_c_epsDeviceProperties(c_epsDeviceProperties* sp);

/* Access member 'spare' of type 'c_epsProtocolCfgOpt' as a variable reference */
#define VAR_c_epsProtocolCfgOpt_spare(var) var

/* Access member 'spare' of type 'c_epsProtocolCfgOpt' as a pointer */
#define PTR_c_epsProtocolCfgOpt_spare(var) (&var)

/* Access member 'ConfigurationProtocol' of type 'c_epsProtocolCfgOpt' as a variable reference */
#define VAR_c_epsProtocolCfgOpt_ConfigurationProtocol(var) var

/* Access member 'ConfigurationProtocol' of type 'c_epsProtocolCfgOpt' as a pointer */
#define PTR_c_epsProtocolCfgOpt_ConfigurationProtocol(var) (&var)

/* Access member 'ProtocolCfgs' of type 'c_epsProtocolCfgOpt' as a variable reference */
#define VAR_c_epsProtocolCfgOpt_ProtocolCfgs(var) var

/* Access member 'ProtocolCfgs' of type 'c_epsProtocolCfgOpt' as a pointer */
#define PTR_c_epsProtocolCfgOpt_ProtocolCfgs(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsProtocolCfgOpt {
	ED_LOCATOR ConfigurationProtocol___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET ConfigurationProtocol; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgList ProtocolCfgs; /* ODY01a *//*GBD01b*/

}	c_epsProtocolCfgOpt;
#define INIT_c_epsProtocolCfgOpt(sp) ED_RESET_MEM ((sp), sizeof (c_epsProtocolCfgOpt))
/*FRK03a*/
void FREE_c_epsProtocolCfgOpt(c_epsProtocolCfgOpt* sp);

/* Access member 'data' of type 'c_PartialTrackingAreaIdentityList_Type2' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_Type2_data(var) (*var)

/* Access member 'data' of type 'c_PartialTrackingAreaIdentityList_Type2' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_Type2_data(var) var


/*-A----------------------------------*/
typedef struct _c_PartialTrackingAreaIdentityList_Type2 {

		c_PartialTrackingAreaIdentity_Type2 **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_PartialTrackingAreaIdentityList_Type2;
#define INIT_c_PartialTrackingAreaIdentityList_Type2(sp) ED_RESET_MEM ((sp), sizeof (c_PartialTrackingAreaIdentityList_Type2))
/*FRK02b*/
void FREE_c_PartialTrackingAreaIdentityList_Type2 (c_PartialTrackingAreaIdentityList_Type2* sp);
/* SETITEMS/ADDITEMS commands for type 'c_PartialTrackingAreaIdentityList_Type2'. */
int SETITEMS_c_PartialTrackingAreaIdentityList_Type2 (c_PartialTrackingAreaIdentityList_Type2* sequence, int desiredItems);
#define ADDITEMS_c_PartialTrackingAreaIdentityList_Type2(sequence, itemsToBeAdded) SETITEMS_c_PartialTrackingAreaIdentityList_Type2 (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'APN_AMBRDownlink' of type 'c_APNAggregateMaxBitRate' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_APN_AMBRDownlink(var) var

/* Access member 'APN_AMBRDownlink' of type 'c_APNAggregateMaxBitRate' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_APN_AMBRDownlink(var) (&var)

/* Access member 'APN_AMBRUplink' of type 'c_APNAggregateMaxBitRate' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_APN_AMBRUplink(var) var

/* Access member 'APN_AMBRUplink' of type 'c_APNAggregateMaxBitRate' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_APN_AMBRUplink(var) (&var)

/* Access member 'APN_AMBRDownlinkExt' of type 'c_APNAggregateMaxBitRate_ext' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_ext_APN_AMBRDownlinkExt(var) var

/* Access member 'APN_AMBRDownlinkExt' of type 'c_APNAggregateMaxBitRate_ext' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_ext_APN_AMBRDownlinkExt(var) (&var)

/* Access member 'APN_AMBRUplinkExt' of type 'c_APNAggregateMaxBitRate_ext' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_ext_APN_AMBRUplinkExt(var) var

/* Access member 'APN_AMBRUplinkExt' of type 'c_APNAggregateMaxBitRate_ext' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_ext_APN_AMBRUplinkExt(var) (&var)

/* Access member 'ext' of type 'c_APNAggregateMaxBitRate' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_ext(var) (*var)

/* Access member 'ext' of type 'c_APNAggregateMaxBitRate' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_ext(var) var

/* Access member 'APN_AMBRDownlinkExt2' of type 'c_APNAggregateMaxBitRate_ext2' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_ext2_APN_AMBRDownlinkExt2(var) var

/* Access member 'APN_AMBRDownlinkExt2' of type 'c_APNAggregateMaxBitRate_ext2' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_ext2_APN_AMBRDownlinkExt2(var) (&var)

/* Access member 'APN_AMBRUplinkExt2' of type 'c_APNAggregateMaxBitRate_ext2' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_ext2_APN_AMBRUplinkExt2(var) var

/* Access member 'APN_AMBRUplinkExt2' of type 'c_APNAggregateMaxBitRate_ext2' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_ext2_APN_AMBRUplinkExt2(var) (&var)

/* Access member 'ext2' of type 'c_APNAggregateMaxBitRate' as a variable reference */
#define VAR_c_APNAggregateMaxBitRate_ext2(var) (*var)

/* Access member 'ext2' of type 'c_APNAggregateMaxBitRate' as a pointer */
#define PTR_c_APNAggregateMaxBitRate_ext2(var) var

/* DEFINITION OF SUB-STRUCTURE c_APNAggregateMaxBitRate_ext */
typedef struct _c_APNAggregateMaxBitRate_ext {
	ED_LOCATOR APN_AMBRDownlinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR APN_AMBRUplinkExt___LOCATOR; /* QUI2 */

	ED_OCTET APN_AMBRDownlinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET APN_AMBRUplinkExt; /* ODY01a *//*GBD01b*/

} c_APNAggregateMaxBitRate_ext;

/* DEFINITION OF SUB-STRUCTURE c_APNAggregateMaxBitRate_ext2 */
typedef struct _c_APNAggregateMaxBitRate_ext2 {
	ED_LOCATOR APN_AMBRDownlinkExt2___LOCATOR; /* QUI2 */
	ED_LOCATOR APN_AMBRUplinkExt2___LOCATOR; /* QUI2 */

	ED_OCTET APN_AMBRDownlinkExt2; /* ODY01a *//*GBD01b*/
	ED_OCTET APN_AMBRUplinkExt2; /* ODY01a *//*GBD01b*/

} c_APNAggregateMaxBitRate_ext2;


/*-A----------------------------------*/
typedef struct _c_APNAggregateMaxBitRate {
	ED_LOCATOR APN_AMBRDownlink___LOCATOR; /* QUI2 */
	ED_LOCATOR APN_AMBRUplink___LOCATOR; /* QUI2 */

	ED_OCTET APN_AMBRDownlink; /* ODY01a *//*GBD01b*/
	ED_OCTET APN_AMBRUplink; /* ODY01a *//*GBD01b*/
	c_APNAggregateMaxBitRate_ext *ext; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN ext_Present;
	c_APNAggregateMaxBitRate_ext2 *ext2; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN ext2_Present;

}	c_APNAggregateMaxBitRate;
#define INIT_c_APNAggregateMaxBitRate(sp) ED_RESET_MEM ((sp), sizeof (c_APNAggregateMaxBitRate))
/*FRK03a*/
void FREE_c_APNAggregateMaxBitRate(c_APNAggregateMaxBitRate* sp);
int SETPRESENT_c_APNAggregateMaxBitRate_ext (c_APNAggregateMaxBitRate* sp, ED_BOOLEAN present);
#define GETPRESENT_c_APNAggregateMaxBitRate_ext(sp) ((sp)->ext_Present)
int SETPRESENT_c_APNAggregateMaxBitRate_ext2 (c_APNAggregateMaxBitRate* sp, ED_BOOLEAN present);
#define GETPRESENT_c_APNAggregateMaxBitRate_ext2(sp) ((sp)->ext2_Present)

/* Access member 'QCI' of type 'c_EPS_QOS' as a variable reference */
#define VAR_c_EPS_QOS_QCI(var) var

/* Access member 'QCI' of type 'c_EPS_QOS' as a pointer */
#define PTR_c_EPS_QOS_QCI(var) (&var)

/* Access member 'MaximumBitRateForUplink' of type 'c_EPS_QOS_basic' as a variable reference */
#define VAR_c_EPS_QOS_basic_MaximumBitRateForUplink(var) var

/* Access member 'MaximumBitRateForUplink' of type 'c_EPS_QOS_basic' as a pointer */
#define PTR_c_EPS_QOS_basic_MaximumBitRateForUplink(var) (&var)

/* Access member 'MaximumBitRateForDownlink' of type 'c_EPS_QOS_basic' as a variable reference */
#define VAR_c_EPS_QOS_basic_MaximumBitRateForDownlink(var) var

/* Access member 'MaximumBitRateForDownlink' of type 'c_EPS_QOS_basic' as a pointer */
#define PTR_c_EPS_QOS_basic_MaximumBitRateForDownlink(var) (&var)

/* Access member 'GuaranteedBitRateForUplink' of type 'c_EPS_QOS_basic' as a variable reference */
#define VAR_c_EPS_QOS_basic_GuaranteedBitRateForUplink(var) var

/* Access member 'GuaranteedBitRateForUplink' of type 'c_EPS_QOS_basic' as a pointer */
#define PTR_c_EPS_QOS_basic_GuaranteedBitRateForUplink(var) (&var)

/* Access member 'GuaranteedBitRateForDownlink' of type 'c_EPS_QOS_basic' as a variable reference */
#define VAR_c_EPS_QOS_basic_GuaranteedBitRateForDownlink(var) var

/* Access member 'GuaranteedBitRateForDownlink' of type 'c_EPS_QOS_basic' as a pointer */
#define PTR_c_EPS_QOS_basic_GuaranteedBitRateForDownlink(var) (&var)

/* Access member 'basic' of type 'c_EPS_QOS' as a variable reference */
#define VAR_c_EPS_QOS_basic(var) (*var)

/* Access member 'basic' of type 'c_EPS_QOS' as a pointer */
#define PTR_c_EPS_QOS_basic(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_EPS_QOS_extended' as a variable reference */
#define VAR_c_EPS_QOS_extended_MaximumBitRateForUplinkExt(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_EPS_QOS_extended' as a pointer */
#define PTR_c_EPS_QOS_extended_MaximumBitRateForUplinkExt(var) (&var)

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_EPS_QOS_extended' as a variable reference */
#define VAR_c_EPS_QOS_extended_MaximumBitRateForDownlinkExt(var) var

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_EPS_QOS_extended' as a pointer */
#define PTR_c_EPS_QOS_extended_MaximumBitRateForDownlinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_EPS_QOS_extended' as a variable reference */
#define VAR_c_EPS_QOS_extended_GuaranteedBitRateForUplinkExt(var) var

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_EPS_QOS_extended' as a pointer */
#define PTR_c_EPS_QOS_extended_GuaranteedBitRateForUplinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_EPS_QOS_extended' as a variable reference */
#define VAR_c_EPS_QOS_extended_GuaranteedBitRateForDownlinkExt(var) var

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_EPS_QOS_extended' as a pointer */
#define PTR_c_EPS_QOS_extended_GuaranteedBitRateForDownlinkExt(var) (&var)

/* Access member 'extended' of type 'c_EPS_QOS' as a variable reference */
#define VAR_c_EPS_QOS_extended(var) (*var)

/* Access member 'extended' of type 'c_EPS_QOS' as a pointer */
#define PTR_c_EPS_QOS_extended(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_EPS_QOS_extended2' as a variable reference */
#define VAR_c_EPS_QOS_extended2_MaximumBitRateForUplinkExt(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_EPS_QOS_extended2' as a pointer */
#define PTR_c_EPS_QOS_extended2_MaximumBitRateForUplinkExt(var) (&var)

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_EPS_QOS_extended2' as a variable reference */
#define VAR_c_EPS_QOS_extended2_MaximumBitRateForDownlinkExt(var) var

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_EPS_QOS_extended2' as a pointer */
#define PTR_c_EPS_QOS_extended2_MaximumBitRateForDownlinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_EPS_QOS_extended2' as a variable reference */
#define VAR_c_EPS_QOS_extended2_GuaranteedBitRateForUplinkExt(var) var

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_EPS_QOS_extended2' as a pointer */
#define PTR_c_EPS_QOS_extended2_GuaranteedBitRateForUplinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_EPS_QOS_extended2' as a variable reference */
#define VAR_c_EPS_QOS_extended2_GuaranteedBitRateForDownlinkExt(var) var

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_EPS_QOS_extended2' as a pointer */
#define PTR_c_EPS_QOS_extended2_GuaranteedBitRateForDownlinkExt(var) (&var)

/* Access member 'extended2' of type 'c_EPS_QOS' as a variable reference */
#define VAR_c_EPS_QOS_extended2(var) (*var)

/* Access member 'extended2' of type 'c_EPS_QOS' as a pointer */
#define PTR_c_EPS_QOS_extended2(var) var

/* DEFINITION OF SUB-STRUCTURE c_EPS_QOS_basic */
typedef struct _c_EPS_QOS_basic {
	ED_LOCATOR MaximumBitRateForUplink___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForDownlink___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplink___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlink___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateForUplink; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForDownlink; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplink; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlink; /* ODY01a *//*GBD01b*/

} c_EPS_QOS_basic;

/* DEFINITION OF SUB-STRUCTURE c_EPS_QOS_extended */
typedef struct _c_EPS_QOS_extended {
	ED_LOCATOR MaximumBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForDownlinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlinkExt___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/

} c_EPS_QOS_extended;

/* DEFINITION OF SUB-STRUCTURE c_EPS_QOS_extended2 */
typedef struct _c_EPS_QOS_extended2 {
	ED_LOCATOR MaximumBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR MaximumBitRateForDownlinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlinkExt___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET MaximumBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/

} c_EPS_QOS_extended2;


/*-A----------------------------------*/
typedef struct _c_EPS_QOS {
	ED_LOCATOR QCI___LOCATOR; /* QUI2 */

	ED_OCTET QCI; /* ODY01a *//*GBD01b*/
	c_EPS_QOS_basic *basic; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN basic_Present;
	c_EPS_QOS_extended *extended; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN extended_Present;
	c_EPS_QOS_extended2 *extended2; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN extended2_Present;

}	c_EPS_QOS;
#define INIT_c_EPS_QOS(sp) ED_RESET_MEM ((sp), sizeof (c_EPS_QOS))
/*FRK03a*/
void FREE_c_EPS_QOS(c_EPS_QOS* sp);
int SETPRESENT_c_EPS_QOS_basic (c_EPS_QOS* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EPS_QOS_basic(sp) ((sp)->basic_Present)
int SETPRESENT_c_EPS_QOS_extended (c_EPS_QOS* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EPS_QOS_extended(sp) ((sp)->extended_Present)
int SETPRESENT_c_EPS_QOS_extended2 (c_EPS_QOS* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EPS_QOS_extended2(sp) ((sp)->extended2_Present)

/* Access member 'DelayClass' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_DelayClass(var) var

/* Access member 'DelayClass' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_DelayClass(var) (&var)

/* Access member 'ReliabilityClass' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_ReliabilityClass(var) var

/* Access member 'ReliabilityClass' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_ReliabilityClass(var) (&var)

/* Access member 'PeakThroughput' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_PeakThroughput(var) var

/* Access member 'PeakThroughput' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_PeakThroughput(var) (&var)

/* Access member 'PrecedenceClass' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_PrecedenceClass(var) var

/* Access member 'PrecedenceClass' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_PrecedenceClass(var) (&var)

/* Access member 'MeanThroughput' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_MeanThroughput(var) var

/* Access member 'MeanThroughput' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_MeanThroughput(var) (&var)

/* Access member 'TrafficClass' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_TrafficClass(var) var

/* Access member 'TrafficClass' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_TrafficClass(var) (&var)

/* Access member 'DeliveryOrder' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_DeliveryOrder(var) var

/* Access member 'DeliveryOrder' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_DeliveryOrder(var) (&var)

/* Access member 'DeliveryOfErroneusSDU' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_DeliveryOfErroneusSDU(var) var

/* Access member 'DeliveryOfErroneusSDU' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_DeliveryOfErroneusSDU(var) (&var)

/* Access member 'MaximumSDUSize' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_MaximumSDUSize(var) var

/* Access member 'MaximumSDUSize' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_MaximumSDUSize(var) (&var)

/* Access member 'MaximumBitRateForUplink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_MaximumBitRateForUplink(var) var

/* Access member 'MaximumBitRateForUplink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_MaximumBitRateForUplink(var) (&var)

/* Access member 'MaximumBitRateForDownlink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_MaximumBitRateForDownlink(var) var

/* Access member 'MaximumBitRateForDownlink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_MaximumBitRateForDownlink(var) (&var)

/* Access member 'ResidualBER' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_ResidualBER(var) var

/* Access member 'ResidualBER' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_ResidualBER(var) (&var)

/* Access member 'SDUErrorRatio' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_SDUErrorRatio(var) var

/* Access member 'SDUErrorRatio' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_SDUErrorRatio(var) (&var)

/* Access member 'TransderDelay' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_TransderDelay(var) var

/* Access member 'TransderDelay' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_TransderDelay(var) (&var)

/* Access member 'TrafficHandlingPriority' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_TrafficHandlingPriority(var) var

/* Access member 'TrafficHandlingPriority' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_TrafficHandlingPriority(var) (&var)

/* Access member 'GuaranteedBitRateForUplink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_GuaranteedBitRateForUplink(var) var

/* Access member 'GuaranteedBitRateForUplink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_GuaranteedBitRateForUplink(var) (&var)

/* Access member 'GuaranteedBitRateForDownlink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_GuaranteedBitRateForDownlink(var) var

/* Access member 'GuaranteedBitRateForDownlink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_GuaranteedBitRateForDownlink(var) (&var)

/* Access member 'SignalingIndication' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_SignalingIndication(var) var

/* Access member 'SignalingIndication' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_SignalingIndication(var) (&var)

/* Access member 'SourceStatisticsDescriptor' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_SourceStatisticsDescriptor(var) var

/* Access member 'SourceStatisticsDescriptor' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_SourceStatisticsDescriptor(var) (&var)

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_epsQualityOfServ_downlink' as a variable reference */
#define VAR_c_epsQualityOfServ_downlink_MaximumBitRateForDownlinkExt(var) var

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_epsQualityOfServ_downlink' as a pointer */
#define PTR_c_epsQualityOfServ_downlink_MaximumBitRateForDownlinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_epsQualityOfServ_downlink' as a variable reference */
#define VAR_c_epsQualityOfServ_downlink_GuaranteedBitRateForDownlinkExt(var) var

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_epsQualityOfServ_downlink' as a pointer */
#define PTR_c_epsQualityOfServ_downlink_GuaranteedBitRateForDownlinkExt(var) (&var)

/* Access member 'downlink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_downlink(var) (*var)

/* Access member 'downlink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_downlink(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_epsQualityOfServ_uplink' as a variable reference */
#define VAR_c_epsQualityOfServ_uplink_MaximumBitRateForUplinkExt(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_epsQualityOfServ_uplink' as a pointer */
#define PTR_c_epsQualityOfServ_uplink_MaximumBitRateForUplinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_epsQualityOfServ_uplink' as a variable reference */
#define VAR_c_epsQualityOfServ_uplink_GuaranteedBitRateForUplinkExt(var) var

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_epsQualityOfServ_uplink' as a pointer */
#define PTR_c_epsQualityOfServ_uplink_GuaranteedBitRateForUplinkExt(var) (&var)

/* Access member 'uplink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_uplink(var) (*var)

/* Access member 'uplink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_uplink(var) var

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_epsQualityOfServ_ext2downlink' as a variable reference */
#define VAR_c_epsQualityOfServ_ext2downlink_MaximumBitRateForDownlinkExt(var) var

/* Access member 'MaximumBitRateForDownlinkExt' of type 'c_epsQualityOfServ_ext2downlink' as a pointer */
#define PTR_c_epsQualityOfServ_ext2downlink_MaximumBitRateForDownlinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_epsQualityOfServ_ext2downlink' as a variable reference */
#define VAR_c_epsQualityOfServ_ext2downlink_GuaranteedBitRateForDownlinkExt(var) var

/* Access member 'GuaranteedBitRateForDownlinkExt' of type 'c_epsQualityOfServ_ext2downlink' as a pointer */
#define PTR_c_epsQualityOfServ_ext2downlink_GuaranteedBitRateForDownlinkExt(var) (&var)

/* Access member 'ext2downlink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_ext2downlink(var) (*var)

/* Access member 'ext2downlink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_ext2downlink(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_epsQualityOfServ_ext2uplink' as a variable reference */
#define VAR_c_epsQualityOfServ_ext2uplink_MaximumBitRateForUplinkExt(var) var

/* Access member 'MaximumBitRateForUplinkExt' of type 'c_epsQualityOfServ_ext2uplink' as a pointer */
#define PTR_c_epsQualityOfServ_ext2uplink_MaximumBitRateForUplinkExt(var) (&var)

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_epsQualityOfServ_ext2uplink' as a variable reference */
#define VAR_c_epsQualityOfServ_ext2uplink_GuaranteedBitRateForUplinkExt(var) var

/* Access member 'GuaranteedBitRateForUplinkExt' of type 'c_epsQualityOfServ_ext2uplink' as a pointer */
#define PTR_c_epsQualityOfServ_ext2uplink_GuaranteedBitRateForUplinkExt(var) (&var)

/* Access member 'ext2uplink' of type 'c_epsQualityOfServ' as a variable reference */
#define VAR_c_epsQualityOfServ_ext2uplink(var) (*var)

/* Access member 'ext2uplink' of type 'c_epsQualityOfServ' as a pointer */
#define PTR_c_epsQualityOfServ_ext2uplink(var) var

/* DEFINITION OF SUB-STRUCTURE c_epsQualityOfServ_downlink */
typedef struct _c_epsQualityOfServ_downlink {
	ED_LOCATOR MaximumBitRateForDownlinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlinkExt___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/

} c_epsQualityOfServ_downlink;

/* DEFINITION OF SUB-STRUCTURE c_epsQualityOfServ_uplink */
typedef struct _c_epsQualityOfServ_uplink {
	ED_LOCATOR MaximumBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplinkExt___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplinkExt; /* ODY01a *//*GBD01b*/

} c_epsQualityOfServ_uplink;

/* DEFINITION OF SUB-STRUCTURE c_epsQualityOfServ_ext2downlink */
typedef struct _c_epsQualityOfServ_ext2downlink {
	ED_LOCATOR MaximumBitRateForDownlinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForDownlinkExt___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForDownlinkExt; /* ODY01a *//*GBD01b*/

} c_epsQualityOfServ_ext2downlink;

/* DEFINITION OF SUB-STRUCTURE c_epsQualityOfServ_ext2uplink */
typedef struct _c_epsQualityOfServ_ext2uplink {
	ED_LOCATOR MaximumBitRateForUplinkExt___LOCATOR; /* QUI2 */
	ED_LOCATOR GuaranteedBitRateForUplinkExt___LOCATOR; /* QUI2 */

	ED_OCTET MaximumBitRateForUplinkExt; /* ODY01a *//*GBD01b*/
	ED_OCTET GuaranteedBitRateForUplinkExt; /* ODY01a *//*GBD01b*/

} c_epsQualityOfServ_ext2uplink;


/*-A----------------------------------*/
typedef struct _c_epsQualityOfServ {
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

	ED_OCTET DelayClass; /* ODY01a *//*GBD01b*/
	ED_OCTET ReliabilityClass; /* ODY01a *//*GBD01b*/
	ED_OCTET PeakThroughput; /* ODY01a *//*GBD01b*/
	ED_OCTET PrecedenceClass; /* ODY01a *//*GBD01b*/
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
	ED_BOOLEAN SignalingIndication; /* ODY01a *//*GBD01b*/
	ED_OCTET SourceStatisticsDescriptor; /* ODY01a *//*GBD01b*/
	c_epsQualityOfServ_downlink *downlink; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN downlink_Present;
	c_epsQualityOfServ_uplink *uplink; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN uplink_Present;
	c_epsQualityOfServ_ext2downlink *ext2downlink; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN ext2downlink_Present;
	c_epsQualityOfServ_ext2uplink *ext2uplink; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN ext2uplink_Present;

}	c_epsQualityOfServ;
#define INIT_c_epsQualityOfServ(sp) ED_RESET_MEM ((sp), sizeof (c_epsQualityOfServ))
/*FRK03a*/
void FREE_c_epsQualityOfServ(c_epsQualityOfServ* sp);
int SETPRESENT_c_epsQualityOfServ_downlink (c_epsQualityOfServ* sp, ED_BOOLEAN present);
#define GETPRESENT_c_epsQualityOfServ_downlink(sp) ((sp)->downlink_Present)
int SETPRESENT_c_epsQualityOfServ_uplink (c_epsQualityOfServ* sp, ED_BOOLEAN present);
#define GETPRESENT_c_epsQualityOfServ_uplink(sp) ((sp)->uplink_Present)
int SETPRESENT_c_epsQualityOfServ_ext2downlink (c_epsQualityOfServ* sp, ED_BOOLEAN present);
#define GETPRESENT_c_epsQualityOfServ_ext2downlink(sp) ((sp)->ext2downlink_Present)
int SETPRESENT_c_epsQualityOfServ_ext2uplink (c_epsQualityOfServ* sp, ED_BOOLEAN present);
#define GETPRESENT_c_epsQualityOfServ_ext2uplink(sp) ((sp)->ext2uplink_Present)

/* Access member 'data' of type 'c_RemoteUEContext_Contexts' as a variable reference */
#define VAR_c_RemoteUEContext_Contexts_data(var) (*var)

/* Access member 'data' of type 'c_RemoteUEContext_Contexts' as a pointer */
#define PTR_c_RemoteUEContext_Contexts_data(var) var

/* Access member 'Contexts' of type 'c_RemoteUEContext' as a variable reference */
#define VAR_c_RemoteUEContext_Contexts(var) var

/* Access member 'Contexts' of type 'c_RemoteUEContext' as a pointer */
#define PTR_c_RemoteUEContext_Contexts(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_RemoteUEContext_Contexts */
typedef struct _c_RemoteUEContext_Contexts {

	c_RemoteUEContext_SingleContext **data; /* NDY01 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_RemoteUEContext_Contexts;


/*-A----------------------------------*/
typedef struct _c_RemoteUEContext {

	c_RemoteUEContext_Contexts Contexts;/*GFB09*//*GBD01b*/

}	c_RemoteUEContext;
#define INIT_c_RemoteUEContext(sp) ED_RESET_MEM ((sp), sizeof (c_RemoteUEContext))
/*FRK03a*/
void FREE_c_RemoteUEContext(c_RemoteUEContext* sp);

/* Access member 'TIValue' of type 'c_epsLinkedTi' as a variable reference */
#define VAR_c_epsLinkedTi_TIValue(var) var

/* Access member 'TIValue' of type 'c_epsLinkedTi' as a pointer */
#define PTR_c_epsLinkedTi_TIValue(var) (&var)

/* Access member 'TIFlag' of type 'c_epsLinkedTi' as a variable reference */
#define VAR_c_epsLinkedTi_TIFlag(var) var

/* Access member 'TIFlag' of type 'c_epsLinkedTi' as a pointer */
#define PTR_c_epsLinkedTi_TIFlag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsLinkedTi {
	ED_LOCATOR TIValue___LOCATOR; /* QUI2 */
	ED_LOCATOR TIFlag___LOCATOR; /* QUI2 */

	ED_LONG TIValue; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN TIFlag; /* ODY01a *//*GBD01b*/

}	c_epsLinkedTi;
#define INIT_c_epsLinkedTi(sp) ED_RESET_MEM ((sp), sizeof (c_epsLinkedTi))
/*FRK03a*/
void FREE_c_epsLinkedTi(c_epsLinkedTi* sp);

/* Access member 'TFTOperationCode' of type 'c_epsTrafficFlowTemplate' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_TFTOperationCode(var) var

/* Access member 'TFTOperationCode' of type 'c_epsTrafficFlowTemplate' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_TFTOperationCode(var) (&var)

/* Access member 'PacketFilterId' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data_PacketFilterId(var) var

/* Access member 'PacketFilterId' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data_PacketFilterId(var) (&var)

/* Access member 'PacketFilterDirection' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data_PacketFilterDirection(var) var

/* Access member 'PacketFilterDirection' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data_PacketFilterDirection(var) (&var)

/* Access member 'PacketFilterEvalPrecedence' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data_PacketFilterEvalPrecedence(var) var

/* Access member 'PacketFilterEvalPrecedence' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data_PacketFilterEvalPrecedence(var) (&var)

/* Access member 'ComponentTypeId' of type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentTypeId(var) var

/* Access member 'ComponentTypeId' of type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentTypeId(var) (&var)

/* Access member 'ComponentData' of type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData(var) var

/* Access member 'ComponentData' of type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData(var) (&var)

/* Access member 'data' of type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data(var) (*var)

/* Access member 'data' of type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data(var) var

/* Access member 'FilterContents' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents(var) var

/* Access member 'FilterContents' of type 'c_epsTrafficFlowTemplate_PacketFilters_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents(var) (&var)

/* Access member 'data' of type 'c_epsTrafficFlowTemplate_PacketFilters' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters_data(var) (*var)

/* Access member 'data' of type 'c_epsTrafficFlowTemplate_PacketFilters' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters_data(var) var

/* Access member 'PacketFilters' of type 'c_epsTrafficFlowTemplate' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketFilters(var) var

/* Access member 'PacketFilters' of type 'c_epsTrafficFlowTemplate' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketFilters(var) (&var)

/* Access member 'ParameterId' of type 'c_epsTrafficFlowTemplate_PacketParameters_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketParameters_data_ParameterId(var) var

/* Access member 'ParameterId' of type 'c_epsTrafficFlowTemplate_PacketParameters_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketParameters_data_ParameterId(var) (&var)

/* Access member 'Contents' of type 'c_epsTrafficFlowTemplate_PacketParameters_data' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketParameters_data_Contents(var) var

/* Access member 'Contents' of type 'c_epsTrafficFlowTemplate_PacketParameters_data' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketParameters_data_Contents(var) (&var)

/* Access member 'data' of type 'c_epsTrafficFlowTemplate_PacketParameters' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketParameters_data(var) (*var)

/* Access member 'data' of type 'c_epsTrafficFlowTemplate_PacketParameters' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketParameters_data(var) var

/* Access member 'PacketParameters' of type 'c_epsTrafficFlowTemplate' as a variable reference */
#define VAR_c_epsTrafficFlowTemplate_PacketParameters(var) var

/* Access member 'PacketParameters' of type 'c_epsTrafficFlowTemplate' as a pointer */
#define PTR_c_epsTrafficFlowTemplate_PacketParameters(var) (&var)

/* DEFINITION OF BINARY c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData */
typedef struct _c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData {
	ED_BYTE* value; /* Variable size; bits needed 256 */
	int usedBits;
} c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data */
typedef struct _c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data {
	ED_LOCATOR ComponentTypeId___LOCATOR; /* QUI2 */
	ED_LOCATOR ComponentData___LOCATOR  /*LBD02*/;

	ED_OCTET ComponentTypeId; /* ODY01a *//*GBD01b*/
	c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data_ComponentData ComponentData; /* Static, variable size; bits needed 256 *//*GBD01b*/

} c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data;

/* DEFINITION OF SUB-STRUCTURE c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents */
typedef struct _c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents {

	c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents;

/* DEFINITION OF SUB-STRUCTURE c_epsTrafficFlowTemplate_PacketFilters_data */
typedef struct _c_epsTrafficFlowTemplate_PacketFilters_data {
	ED_LOCATOR PacketFilterId___LOCATOR; /* QUI2 */
	ED_LOCATOR PacketFilterDirection___LOCATOR; /* QUI2 */
	ED_LOCATOR PacketFilterEvalPrecedence___LOCATOR; /* QUI2 */

	ED_OCTET PacketFilterId; /* ODY01a *//*GBD01b*/
	ED_OCTET PacketFilterDirection; /* ODY01a *//*GBD01b*/
	ED_LONG PacketFilterEvalPrecedence; /* ODY01a *//*GBD01b*/
	c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents FilterContents;/*GFB09*//*GBD01b*/

} c_epsTrafficFlowTemplate_PacketFilters_data;

/* DEFINITION OF SUB-STRUCTURE c_epsTrafficFlowTemplate_PacketFilters */
typedef struct _c_epsTrafficFlowTemplate_PacketFilters {

	c_epsTrafficFlowTemplate_PacketFilters_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_epsTrafficFlowTemplate_PacketFilters;

/* DEFINITION OF BINARY c_epsTrafficFlowTemplate_PacketParameters_data_Contents */
typedef struct _c_epsTrafficFlowTemplate_PacketParameters_data_Contents {
	ED_BYTE* value; /* Variable size; bits needed 256 */
	int usedBits;
} c_epsTrafficFlowTemplate_PacketParameters_data_Contents;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_epsTrafficFlowTemplate_PacketParameters_data_Contents(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF SUB-STRUCTURE c_epsTrafficFlowTemplate_PacketParameters_data */
typedef struct _c_epsTrafficFlowTemplate_PacketParameters_data {
	ED_LOCATOR ParameterId___LOCATOR; /* QUI2 */
	ED_LOCATOR Contents___LOCATOR  /*LBD02*/;

	ED_LONG ParameterId; /* ODY01a *//*GBD01b*/
	c_epsTrafficFlowTemplate_PacketParameters_data_Contents Contents; /* Static, variable size; bits needed 256 *//*GBD01b*/

} c_epsTrafficFlowTemplate_PacketParameters_data;

/* DEFINITION OF SUB-STRUCTURE c_epsTrafficFlowTemplate_PacketParameters */
typedef struct _c_epsTrafficFlowTemplate_PacketParameters {

	c_epsTrafficFlowTemplate_PacketParameters_data **data; /* NDY03 *//*GBD01b*//*AR01*/
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_epsTrafficFlowTemplate_PacketParameters;


/*-A----------------------------------*/
typedef struct _c_epsTrafficFlowTemplate {
	ED_LOCATOR TFTOperationCode___LOCATOR; /* QUI2 */

	ED_OCTET TFTOperationCode; /* ODY01a *//*GBD01b*/
	c_epsTrafficFlowTemplate_PacketFilters PacketFilters;/*GFB09*//*GBD01b*/
	c_epsTrafficFlowTemplate_PacketParameters PacketParameters;/*GFB09*//*GBD01b*/

}	c_epsTrafficFlowTemplate;
#define INIT_c_epsTrafficFlowTemplate(sp) ED_RESET_MEM ((sp), sizeof (c_epsTrafficFlowTemplate))
/*FRK03a*/
void FREE_c_epsTrafficFlowTemplate(c_epsTrafficFlowTemplate* sp);

/* Access member 'Unit' of type 'c_epsGprsTimer' as a variable reference */
#define VAR_c_epsGprsTimer_Unit(var) var

/* Access member 'Unit' of type 'c_epsGprsTimer' as a pointer */
#define PTR_c_epsGprsTimer_Unit(var) (&var)

/* Access member 'TimerValue' of type 'c_epsGprsTimer' as a variable reference */
#define VAR_c_epsGprsTimer_TimerValue(var) var

/* Access member 'TimerValue' of type 'c_epsGprsTimer' as a pointer */
#define PTR_c_epsGprsTimer_TimerValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsGprsTimer {
	ED_LOCATOR Unit___LOCATOR; /* QUI2 */
	ED_LOCATOR TimerValue___LOCATOR; /* QUI2 */

	ED_OCTET Unit; /* ODY01a *//*GBD01b*/
	ED_OCTET TimerValue; /* ODY01a *//*GBD01b*/

}	c_epsGprsTimer;
#define INIT_c_epsGprsTimer(sp) ED_RESET_MEM ((sp), sizeof (c_epsGprsTimer))
/*FRK03a*/
void FREE_c_epsGprsTimer(c_epsGprsTimer* sp);

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer */
typedef struct _c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT;
#define INIT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT))
/*FRK03a*/
void FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT(c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp);
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer */
typedef struct _c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT;
#define INIT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT))
/*FRK03a*/
void FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT(c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp);
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) var


/*-A----------------------------------*/
typedef struct _c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT;
#define INIT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT))
/*FRK03a*/
void FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT(c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* sp);
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(var) var


/*-A----------------------------------*/
typedef struct _c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT;
#define INIT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT))
/*FRK03a*/
void FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT(c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* sp);
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'LinkedEPSBearerIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_LinkedEPSBearerIdentity(var) var

/* Access member 'LinkedEPSBearerIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_LinkedEPSBearerIdentity(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_SpareHalfOctet(var) (&var)

/* Access member 'TrafficFlowAggregate' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_TrafficFlowAggregate(var) var

/* Access member 'TrafficFlowAggregate' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_TrafficFlowAggregate(var) (&var)

/* Access member 'RequiredTrafficFlowQoS' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_RequiredTrafficFlowQoS(var) var

/* Access member 'RequiredTrafficFlowQoS' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_RequiredTrafficFlowQoS(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'DeviceProperties' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties(var) var

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer */
typedef struct _c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_BEARER_RESOURCE_ALLOCATION_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR LinkedEPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET LinkedEPSBearerIdentity; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_epsTrafficFlowTemplate TrafficFlowAggregate; /* ODY01a *//*GBD01b*/
	c_EPS_QOS RequiredTrafficFlowQoS; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsDeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_BEARER_RESOURCE_ALLOCATION_REQUEST;
#define INIT_c_BEARER_RESOURCE_ALLOCATION_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_BEARER_RESOURCE_ALLOCATION_REQUEST))
/*FRK03a*/
void FREE_c_BEARER_RESOURCE_ALLOCATION_REQUEST(c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp);
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'LinkedEPSBearerIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_LinkedEPSBearerIdentity(var) var

/* Access member 'LinkedEPSBearerIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_LinkedEPSBearerIdentity(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_SpareHalfOctet(var) (&var)

/* Access member 'TrafficFlowAggregate' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_TrafficFlowAggregate(var) var

/* Access member 'TrafficFlowAggregate' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_TrafficFlowAggregate(var) (&var)

/* Access member 'RequiredTrafficFlowQoS' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS(var) (*var)

/* Access member 'RequiredTrafficFlowQoS' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS(var) var

/* Access member 'ESMCause' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'DeviceProperties' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties(var) var

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer(var) var

/* Access member 'HeaderCompressionCfg' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg(var) (*var)

/* Access member 'HeaderCompressionCfg' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REQUEST' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer */
typedef struct _c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_BEARER_RESOURCE_MODIFICATION_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR LinkedEPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET LinkedEPSBearerIdentity; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_epsTrafficFlowTemplate TrafficFlowAggregate; /* ODY01a *//*GBD01b*/
	c_EPS_QOS *RequiredTrafficFlowQoS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RequiredTrafficFlowQoS_Present;
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ESMCause_Present;
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsDeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_HeaderCompressionCfg *HeaderCompressionCfg; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HeaderCompressionCfg_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_BEARER_RESOURCE_MODIFICATION_REQUEST;
#define INIT_c_BEARER_RESOURCE_MODIFICATION_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_BEARER_RESOURCE_MODIFICATION_REQUEST))
/*FRK03a*/
void FREE_c_BEARER_RESOURCE_MODIFICATION_REQUEST(c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp);
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_RequiredTrafficFlowQoS(sp) ((sp)->RequiredTrafficFlowQoS_Present)
#define SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ESMCause(sp,present) (((sp)->ESMCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ESMCause(sp) ((sp)->ESMCause_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_HeaderCompressionCfg(sp) ((sp)->HeaderCompressionCfg_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) var

/* Access member 'NBIFOMContainer' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer */
typedef struct _c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT;
#define INIT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT))
/*FRK03a*/
void FREE_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT(c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp);
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ESM_DUMMY_MESSAGE' as a variable reference */
#define VAR_c_ESM_DUMMY_MESSAGE_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ESM_DUMMY_MESSAGE' as a pointer */
#define PTR_c_ESM_DUMMY_MESSAGE_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_DUMMY_MESSAGE' as a variable reference */
#define VAR_c_ESM_DUMMY_MESSAGE_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_DUMMY_MESSAGE' as a pointer */
#define PTR_c_ESM_DUMMY_MESSAGE_ProcedureTransactionIdentity(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ESM_DUMMY_MESSAGE {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/

}	c_ESM_DUMMY_MESSAGE;
#define INIT_c_ESM_DUMMY_MESSAGE(sp) ED_RESET_MEM ((sp), sizeof (c_ESM_DUMMY_MESSAGE))
/*FRK03a*/
void FREE_c_ESM_DUMMY_MESSAGE(c_ESM_DUMMY_MESSAGE* sp);

/* Access member 'EPSBearerIdentity' of type 'c_ESM_INFORMATION_RESPONSE' as a variable reference */
#define VAR_c_ESM_INFORMATION_RESPONSE_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ESM_INFORMATION_RESPONSE' as a pointer */
#define PTR_c_ESM_INFORMATION_RESPONSE_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_INFORMATION_RESPONSE' as a variable reference */
#define VAR_c_ESM_INFORMATION_RESPONSE_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_INFORMATION_RESPONSE' as a pointer */
#define PTR_c_ESM_INFORMATION_RESPONSE_ProcedureTransactionIdentity(var) (&var)

/* Access member 'AccessPointName' of type 'c_ESM_INFORMATION_RESPONSE' as a variable reference */
#define VAR_c_ESM_INFORMATION_RESPONSE_AccessPointName(var) (*var)

/* Access member 'AccessPointName' of type 'c_ESM_INFORMATION_RESPONSE' as a pointer */
#define PTR_c_ESM_INFORMATION_RESPONSE_AccessPointName(var) var

/* Access member 'ProtocolConfigurationOptions' of type 'c_ESM_INFORMATION_RESPONSE' as a variable reference */
#define VAR_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ESM_INFORMATION_RESPONSE' as a pointer */
#define PTR_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ESM_INFORMATION_RESPONSE' as a variable reference */
#define VAR_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ESM_INFORMATION_RESPONSE' as a pointer */
#define PTR_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_ESM_INFORMATION_RESPONSE_AccessPointName */
typedef struct _c_ESM_INFORMATION_RESPONSE_AccessPointName {
	ED_BYTE* value; /* Variable size; bits needed 800 */
	int usedBits;
} c_ESM_INFORMATION_RESPONSE_AccessPointName;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ESM_INFORMATION_RESPONSE_AccessPointName(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ESM_INFORMATION_RESPONSE {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR AccessPointName___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_ESM_INFORMATION_RESPONSE_AccessPointName* AccessPointName; /* Dynamic, variable size; bits needed 800 ODY02b *//*GBD01b*/
	ED_BOOLEAN AccessPointName_Present;
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_ESM_INFORMATION_RESPONSE;
#define INIT_c_ESM_INFORMATION_RESPONSE(sp) ED_RESET_MEM ((sp), sizeof (c_ESM_INFORMATION_RESPONSE))
/*FRK03a*/
void FREE_c_ESM_INFORMATION_RESPONSE(c_ESM_INFORMATION_RESPONSE* sp);
int SETPRESENT_c_ESM_INFORMATION_RESPONSE_AccessPointName (c_ESM_INFORMATION_RESPONSE* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ESM_INFORMATION_RESPONSE_AccessPointName(sp) ((sp)->AccessPointName_Present)
int SETPRESENT_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions (c_ESM_INFORMATION_RESPONSE* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ESM_INFORMATION_RESPONSE_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions (c_ESM_INFORMATION_RESPONSE* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ESM_INFORMATION_RESPONSE_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ESM_STATUS' as a variable reference */
#define VAR_c_ESM_STATUS_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ESM_STATUS' as a pointer */
#define PTR_c_ESM_STATUS_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_STATUS' as a variable reference */
#define VAR_c_ESM_STATUS_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_STATUS' as a pointer */
#define PTR_c_ESM_STATUS_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_ESM_STATUS' as a variable reference */
#define VAR_c_ESM_STATUS_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_ESM_STATUS' as a pointer */
#define PTR_c_ESM_STATUS_ESMCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ESM_STATUS {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/

}	c_ESM_STATUS;
#define INIT_c_ESM_STATUS(sp) ED_RESET_MEM ((sp), sizeof (c_ESM_STATUS))
/*FRK03a*/
void FREE_c_ESM_STATUS(c_ESM_STATUS* sp);

/* Access member 'EPSBearerIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer */
typedef struct _c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT;
#define INIT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT))
/*FRK03a*/
void FREE_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT(c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp);
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REJECT' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer */
typedef struct _c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_EPS_BEARER_CONTEXT_REJECT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_MODIFY_EPS_BEARER_CONTEXT_REJECT;
#define INIT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_EPS_BEARER_CONTEXT_REJECT))
/*FRK03a*/
void FREE_c_MODIFY_EPS_BEARER_CONTEXT_REJECT(c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp);
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer (c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REJECT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'RequestType' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_RequestType(var) var

/* Access member 'RequestType' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_RequestType(var) (&var)

/* Access member 'PDNType' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_PDNType(var) var

/* Access member 'PDNType' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_PDNType(var) (&var)

/* Access member 'ESMInformationTransferFlag' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_ESMInformationTransferFlag(var) var

/* Access member 'ESMInformationTransferFlag' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_ESMInformationTransferFlag(var) (&var)

/* Access member 'AccessPointName' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_AccessPointName(var) (*var)

/* Access member 'AccessPointName' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_AccessPointName(var) var

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'DeviceProperties' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties(var) var

/* Access member 'NBIFOMContainer' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer(var) var

/* Access member 'HeaderCompressionCfg' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg(var) (*var)

/* Access member 'HeaderCompressionCfg' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REQUEST' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REQUEST' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_PDN_CONNECTIVITY_REQUEST_AccessPointName */
typedef struct _c_PDN_CONNECTIVITY_REQUEST_AccessPointName {
	ED_BYTE* value; /* Variable size; bits needed 800 */
	int usedBits;
} c_PDN_CONNECTIVITY_REQUEST_AccessPointName;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_PDN_CONNECTIVITY_REQUEST_AccessPointName(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer */
typedef struct _c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_PDN_CONNECTIVITY_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR RequestType___LOCATOR; /* QUI2 */
	ED_LOCATOR PDNType___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMInformationTransferFlag___LOCATOR; /* QUI2 */
	ED_LOCATOR AccessPointName___LOCATOR  /*LBD01*/;
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET RequestType; /* ODY01a *//*GBD01b*/
	ED_OCTET PDNType; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMInformationTransferFlag; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ESMInformationTransferFlag_Present;
	c_PDN_CONNECTIVITY_REQUEST_AccessPointName* AccessPointName; /* Dynamic, variable size; bits needed 800 ODY02b *//*GBD01b*/
	ED_BOOLEAN AccessPointName_Present;
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsDeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_HeaderCompressionCfg *HeaderCompressionCfg; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HeaderCompressionCfg_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_PDN_CONNECTIVITY_REQUEST;
#define INIT_c_PDN_CONNECTIVITY_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_PDN_CONNECTIVITY_REQUEST))
/*FRK03a*/
void FREE_c_PDN_CONNECTIVITY_REQUEST(c_PDN_CONNECTIVITY_REQUEST* sp);
#define SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ESMInformationTransferFlag(sp,present) (((sp)->ESMInformationTransferFlag_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ESMInformationTransferFlag(sp) ((sp)->ESMInformationTransferFlag_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_AccessPointName (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REQUEST_AccessPointName(sp) ((sp)->AccessPointName_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REQUEST_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REQUEST_HeaderCompressionCfg(sp) ((sp)->HeaderCompressionCfg_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_PDN_DISCONNECT_REQUEST' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_PDN_DISCONNECT_REQUEST' as a pointer */
#define PTR_c_PDN_DISCONNECT_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_DISCONNECT_REQUEST' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_DISCONNECT_REQUEST' as a pointer */
#define PTR_c_PDN_DISCONNECT_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'LinkedEPSBearerIdentity' of type 'c_PDN_DISCONNECT_REQUEST' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REQUEST_LinkedEPSBearerIdentity(var) var

/* Access member 'LinkedEPSBearerIdentity' of type 'c_PDN_DISCONNECT_REQUEST' as a pointer */
#define PTR_c_PDN_DISCONNECT_REQUEST_LinkedEPSBearerIdentity(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_PDN_DISCONNECT_REQUEST' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REQUEST_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_PDN_DISCONNECT_REQUEST' as a pointer */
#define PTR_c_PDN_DISCONNECT_REQUEST_SpareHalfOctet(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REQUEST' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REQUEST' as a pointer */
#define PTR_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REQUEST' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REQUEST' as a pointer */
#define PTR_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions(var) var


/*-A----------------------------------*/
typedef struct _c_PDN_DISCONNECT_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR LinkedEPSBearerIdentity___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET LinkedEPSBearerIdentity; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_PDN_DISCONNECT_REQUEST;
#define INIT_c_PDN_DISCONNECT_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_PDN_DISCONNECT_REQUEST))
/*FRK03a*/
void FREE_c_PDN_DISCONNECT_REQUEST(c_PDN_DISCONNECT_REQUEST* sp);
int SETPRESENT_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions (c_PDN_DISCONNECT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_DISCONNECT_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions (c_PDN_DISCONNECT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_DISCONNECT_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_REMOTE_UE_REPORT' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_REMOTE_UE_REPORT' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_REMOTE_UE_REPORT' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_REMOTE_UE_REPORT' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'RemoteUEContextConnected' of type 'c_REMOTE_UE_REPORT' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_RemoteUEContextConnected(var) (*var)

/* Access member 'RemoteUEContextConnected' of type 'c_REMOTE_UE_REPORT' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_RemoteUEContextConnected(var) var

/* Access member 'RemoteUEContextDisconnected' of type 'c_REMOTE_UE_REPORT' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected(var) (*var)

/* Access member 'RemoteUEContextDisconnected' of type 'c_REMOTE_UE_REPORT' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected(var) var

/* Access member 'ProSeKeyManagementFunctionAddr' of type 'c_REMOTE_UE_REPORT' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr(var) (*var)

/* Access member 'ProSeKeyManagementFunctionAddr' of type 'c_REMOTE_UE_REPORT' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr(var) var


/*-A----------------------------------*/
typedef struct _c_REMOTE_UE_REPORT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_RemoteUEContext *RemoteUEContextConnected; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RemoteUEContextConnected_Present;
	c_RemoteUEContext *RemoteUEContextDisconnected; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN RemoteUEContextDisconnected_Present;
	c_PKMFAddress *ProSeKeyManagementFunctionAddr; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProSeKeyManagementFunctionAddr_Present;

}	c_REMOTE_UE_REPORT;
#define INIT_c_REMOTE_UE_REPORT(sp) ED_RESET_MEM ((sp), sizeof (c_REMOTE_UE_REPORT))
/*FRK03a*/
void FREE_c_REMOTE_UE_REPORT(c_REMOTE_UE_REPORT* sp);
int SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextConnected (c_REMOTE_UE_REPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextConnected(sp) ((sp)->RemoteUEContextConnected_Present)
int SETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected (c_REMOTE_UE_REPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REMOTE_UE_REPORT_RemoteUEContextDisconnected(sp) ((sp)->RemoteUEContextDisconnected_Present)
int SETPRESENT_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr (c_REMOTE_UE_REPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_REMOTE_UE_REPORT_ProSeKeyManagementFunctionAddr(sp) ((sp)->ProSeKeyManagementFunctionAddr_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ESM_DATA_TRANSPORT' as a variable reference */
#define VAR_c_ESM_DATA_TRANSPORT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ESM_DATA_TRANSPORT' as a pointer */
#define PTR_c_ESM_DATA_TRANSPORT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_DATA_TRANSPORT' as a variable reference */
#define VAR_c_ESM_DATA_TRANSPORT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_DATA_TRANSPORT' as a pointer */
#define PTR_c_ESM_DATA_TRANSPORT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'UserDataContainer' of type 'c_ESM_DATA_TRANSPORT' as a variable reference */
#define VAR_c_ESM_DATA_TRANSPORT_UserDataContainer(var) var

/* Access member 'UserDataContainer' of type 'c_ESM_DATA_TRANSPORT' as a pointer */
#define PTR_c_ESM_DATA_TRANSPORT_UserDataContainer(var) (&var)

/* Access member 'ReleaseAssistanceIndication' of type 'c_ESM_DATA_TRANSPORT' as a variable reference */
#define VAR_c_ESM_DATA_TRANSPORT_ReleaseAssistanceIndication(var) var

/* Access member 'ReleaseAssistanceIndication' of type 'c_ESM_DATA_TRANSPORT' as a pointer */
#define PTR_c_ESM_DATA_TRANSPORT_ReleaseAssistanceIndication(var) (&var)

/* DEFINITION OF BINARY c_ESM_DATA_TRANSPORT_UserDataContainer */
typedef struct _c_ESM_DATA_TRANSPORT_UserDataContainer {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_ESM_DATA_TRANSPORT_UserDataContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ESM_DATA_TRANSPORT_UserDataContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ESM_DATA_TRANSPORT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR UserDataContainer___LOCATOR  /*LBD02*/;
	ED_LOCATOR ReleaseAssistanceIndication___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_ESM_DATA_TRANSPORT_UserDataContainer UserDataContainer; /* Static, variable size; bits needed 4784 *//*GBD01b*/
	ED_OCTET ReleaseAssistanceIndication; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ReleaseAssistanceIndication_Present;

}	c_ESM_DATA_TRANSPORT;
#define INIT_c_ESM_DATA_TRANSPORT(sp) ED_RESET_MEM ((sp), sizeof (c_ESM_DATA_TRANSPORT))
/*FRK03a*/
void FREE_c_ESM_DATA_TRANSPORT(c_ESM_DATA_TRANSPORT* sp);
#define SETPRESENT_c_ESM_DATA_TRANSPORT_ReleaseAssistanceIndication(sp,present) (((sp)->ReleaseAssistanceIndication_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ESM_DATA_TRANSPORT_ReleaseAssistanceIndication(sp) ((sp)->ReleaseAssistanceIndication_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'LinkedEPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_LinkedEPSBearerIdentity(var) var

/* Access member 'LinkedEPSBearerIdentity' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_LinkedEPSBearerIdentity(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_SpareHalfOctet(var) (&var)

/* Access member 'EPSQoS' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_EPSQoS(var) var

/* Access member 'EPSQoS' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_EPSQoS(var) (&var)

/* Access member 'TFT' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TFT(var) var

/* Access member 'TFT' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TFT(var) (&var)

/* Access member 'TransactionIdentifier' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier(var) (*var)

/* Access member 'TransactionIdentifier' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier(var) var

/* Access member 'NegotiatedQoS' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS(var) (*var)

/* Access member 'NegotiatedQoS' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS(var) var

/* Access member 'NegotiatedLLCSAPI' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(var) (*var)

/* Access member 'NegotiatedLLCSAPI' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(var) var

/* Access member 'RadioPriority' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(var) var

/* Access member 'RadioPriority' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(var) (&var)

/* Access member 'PacketFlowIdentifier' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(var) (*var)

/* Access member 'PacketFlowIdentifier' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(var) var

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer */
typedef struct _c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR LinkedEPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR RadioPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET LinkedEPSBearerIdentity; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_EPS_QOS EPSQoS; /* ODY01a *//*GBD01b*/
	c_epsTrafficFlowTemplate TFT; /* ODY01a *//*GBD01b*/
	c_epsLinkedTi *TransactionIdentifier; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TransactionIdentifier_Present;
	c_epsQualityOfServ *NegotiatedQoS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedQoS_Present;
	c_epsLlcServAccessPointId *NegotiatedLLCSAPI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedLLCSAPI_Present;
	ED_OCTET RadioPriority; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RadioPriority_Present;
	c_epsPacketFlowIdentifie *PacketFlowIdentifier; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PacketFlowIdentifier_Present;
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsWLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST;
#define INIT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST))
/*FRK03a*/
void FREE_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST(c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp);
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier(sp) ((sp)->TransactionIdentifier_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS(sp) ((sp)->NegotiatedQoS_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(sp) ((sp)->NegotiatedLLCSAPI_Present)
#define SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(sp,present) (((sp)->RadioPriority_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(sp) ((sp)->RadioPriority_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(sp) ((sp)->PacketFlowIdentifier_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'EPSQoS' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_EPSQoS(var) var

/* Access member 'EPSQoS' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_EPSQoS(var) (&var)

/* Access member 'AccessPointName' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName(var) var

/* Access member 'AccessPointName' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName(var) (&var)

/* Access member 'PDNAddress' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PDNAddress(var) var

/* Access member 'PDNAddress' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PDNAddress(var) (&var)

/* Access member 'TransactionIdentifier' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier(var) (*var)

/* Access member 'TransactionIdentifier' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier(var) var

/* Access member 'NegotiatedQoS' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS(var) (*var)

/* Access member 'NegotiatedQoS' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS(var) var

/* Access member 'NegotiatedLLCSAPI' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(var) (*var)

/* Access member 'NegotiatedLLCSAPI' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(var) var

/* Access member 'RadioPriority' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(var) var

/* Access member 'RadioPriority' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(var) (&var)

/* Access member 'PacketFlowIdentifier' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(var) (*var)

/* Access member 'PacketFlowIdentifier' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(var) var

/* Access member 'APNAMBR' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR(var) (*var)

/* Access member 'APNAMBR' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR(var) var

/* Access member 'ESMCause' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'ConnectivityType' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType(var) (*var)

/* Access member 'ConnectivityType' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType(var) var

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) var

/* Access member 'HeaderCompressionCfg' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg(var) (*var)

/* Access member 'HeaderCompressionCfg' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg(var) var

/* Access member 'ControlPlaneOnlyIndication' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ControlPlaneOnlyIndication(var) var

/* Access member 'ControlPlaneOnlyIndication' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ControlPlaneOnlyIndication(var) (&var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) var

/* Access member 'ServingPLMNRateControl' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl(var) var

/* Access member 'ServingPLMNRateControl' of type 'c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl(var) (&var)

/* DEFINITION OF BINARY c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName */
typedef struct _c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName {
	ED_BYTE* value; /* Variable size; bits needed 800 */
	int usedBits;
} c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer */
typedef struct _c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR AccessPointName___LOCATOR  /*LBD02*/;
	ED_LOCATOR RadioPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;
	ED_LOCATOR ControlPlaneOnlyIndication___LOCATOR; /* QUI2 */
	ED_LOCATOR ServingPLMNRateControl___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_EPS_QOS EPSQoS; /* ODY01a *//*GBD01b*/
	c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_AccessPointName AccessPointName; /* Static, variable size; bits needed 800 *//*GBD01b*/
	c_PDNAddress PDNAddress; /* ODY01a *//*GBD01b*/
	c_epsLinkedTi *TransactionIdentifier; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TransactionIdentifier_Present;
	c_epsQualityOfServ *NegotiatedQoS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedQoS_Present;
	c_epsLlcServAccessPointId *NegotiatedLLCSAPI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedLLCSAPI_Present;
	ED_OCTET RadioPriority; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RadioPriority_Present;
	c_epsPacketFlowIdentifie *PacketFlowIdentifier; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PacketFlowIdentifier_Present;
	c_APNAggregateMaxBitRate *APNAMBR; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN APNAMBR_Present;
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ESMCause_Present;
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsConnectivityType *ConnectivityType; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ConnectivityType_Present;
	c_epsWLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_HeaderCompressionCfg *HeaderCompressionCfg; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HeaderCompressionCfg_Present;
	ED_OCTET ControlPlaneOnlyIndication; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ControlPlaneOnlyIndication_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;
	ED_SHORT ServingPLMNRateControl; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ServingPLMNRateControl_Present;

}	c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST;
#define INIT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST))
/*FRK03a*/
void FREE_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST(c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp);
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_TransactionIdentifier(sp) ((sp)->TransactionIdentifier_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedQoS(sp) ((sp)->NegotiatedQoS_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(sp) ((sp)->NegotiatedLLCSAPI_Present)
#define SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(sp,present) (((sp)->RadioPriority_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(sp) ((sp)->RadioPriority_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(sp) ((sp)->PacketFlowIdentifier_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_APNAMBR(sp) ((sp)->APNAMBR_Present)
#define SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ESMCause(sp,present) (((sp)->ESMCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ESMCause(sp) ((sp)->ESMCause_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ConnectivityType(sp) ((sp)->ConnectivityType_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg(sp) ((sp)->HeaderCompressionCfg_Present)
#define SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ControlPlaneOnlyIndication(sp,present) (((sp)->ControlPlaneOnlyIndication_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ControlPlaneOnlyIndication(sp) ((sp)->ControlPlaneOnlyIndication_Present)
int SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)
#define SETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl(sp,present) (((sp)->ServingPLMNRateControl_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST_ServingPLMNRateControl(sp) ((sp)->ServingPLMNRateControl_Present)

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions(var) var

/* Access member 'BackOffTimer' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer(var) (*var)

/* Access member 'BackOffTimer' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer(var) var

/* Access member 'ReAttemptIndicator' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator(var) (*var)

/* Access member 'ReAttemptIndicator' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator(var) var

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_ALLOCATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer */
typedef struct _c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_BEARER_RESOURCE_ALLOCATION_REJECT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsGprsTimer *BackOffTimer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BackOffTimer_Present;
	c_epsReAttemptIndicator *ReAttemptIndicator; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReAttemptIndicator_Present;
	c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_BEARER_RESOURCE_ALLOCATION_REJECT;
#define INIT_c_BEARER_RESOURCE_ALLOCATION_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_BEARER_RESOURCE_ALLOCATION_REJECT))
/*FRK03a*/
void FREE_c_BEARER_RESOURCE_ALLOCATION_REJECT(c_BEARER_RESOURCE_ALLOCATION_REJECT* sp);
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_BackOffTimer(sp) ((sp)->BackOffTimer_Present)
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ReAttemptIndicator(sp) ((sp)->ReAttemptIndicator_Present)
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_ALLOCATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_ALLOCATION_REJECT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions(var) var

/* Access member 'BackOffTimer' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer(var) (*var)

/* Access member 'BackOffTimer' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer(var) var

/* Access member 'ReAttemptIndicator' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator(var) (*var)

/* Access member 'ReAttemptIndicator' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator(var) var

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a variable reference */
#define VAR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_BEARER_RESOURCE_MODIFICATION_REJECT' as a pointer */
#define PTR_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer */
typedef struct _c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_BEARER_RESOURCE_MODIFICATION_REJECT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsGprsTimer *BackOffTimer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BackOffTimer_Present;
	c_epsReAttemptIndicator *ReAttemptIndicator; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReAttemptIndicator_Present;
	c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_BEARER_RESOURCE_MODIFICATION_REJECT;
#define INIT_c_BEARER_RESOURCE_MODIFICATION_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_BEARER_RESOURCE_MODIFICATION_REJECT))
/*FRK03a*/
void FREE_c_BEARER_RESOURCE_MODIFICATION_REJECT(c_BEARER_RESOURCE_MODIFICATION_REJECT* sp);
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_BackOffTimer(sp) ((sp)->BackOffTimer_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ReAttemptIndicator(sp) ((sp)->ReAttemptIndicator_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions (c_BEARER_RESOURCE_MODIFICATION_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_BEARER_RESOURCE_MODIFICATION_REJECT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'T3396Value' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value(var) (*var)

/* Access member 'T3396Value' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value(var) var

/* Access member 'WLANOffloadIndication' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer */
typedef struct _c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsGprsTimer *T3396Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3396Value_Present;
	c_epsWLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST;
#define INIT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST))
/*FRK03a*/
void FREE_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST(c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp);
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_T3396Value(sp) ((sp)->T3396Value_Present)
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_ESM_INFORMATION_REQUEST' as a variable reference */
#define VAR_c_ESM_INFORMATION_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_ESM_INFORMATION_REQUEST' as a pointer */
#define PTR_c_ESM_INFORMATION_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_INFORMATION_REQUEST' as a variable reference */
#define VAR_c_ESM_INFORMATION_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_ESM_INFORMATION_REQUEST' as a pointer */
#define PTR_c_ESM_INFORMATION_REQUEST_ProcedureTransactionIdentity(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ESM_INFORMATION_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/

}	c_ESM_INFORMATION_REQUEST;
#define INIT_c_ESM_INFORMATION_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_ESM_INFORMATION_REQUEST))
/*FRK03a*/
void FREE_c_ESM_INFORMATION_REQUEST(c_ESM_INFORMATION_REQUEST* sp);

/* Access member 'EPSBearerIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProcedureTransactionIdentity(var) (&var)

/* Access member 'NewEPSQoS' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS(var) (*var)

/* Access member 'NewEPSQoS' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS(var) var

/* Access member 'TFT' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT(var) (*var)

/* Access member 'TFT' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT(var) var

/* Access member 'NewQoS' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS(var) (*var)

/* Access member 'NewQoS' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS(var) var

/* Access member 'NegotiatedLLCSAPI' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(var) (*var)

/* Access member 'NegotiatedLLCSAPI' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(var) var

/* Access member 'RadioPriority' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(var) var

/* Access member 'RadioPriority' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(var) (&var)

/* Access member 'PacketFlowIdentifier' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(var) (*var)

/* Access member 'PacketFlowIdentifier' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(var) var

/* Access member 'APNAMBR' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR(var) (*var)

/* Access member 'APNAMBR' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR(var) var

/* Access member 'ProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(var) var

/* Access member 'WLANOffloadIndication' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) (*var)

/* Access member 'WLANOffloadIndication' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(var) var

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(var) var

/* Access member 'HeaderCompressionCfg' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg(var) (*var)

/* Access member 'HeaderCompressionCfg' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a variable reference */
#define VAR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_MODIFY_EPS_BEARER_CONTEXT_REQUEST' as a pointer */
#define PTR_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer */
typedef struct _c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_MODIFY_EPS_BEARER_CONTEXT_REQUEST {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR RadioPriority___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_EPS_QOS *NewEPSQoS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NewEPSQoS_Present;
	c_epsTrafficFlowTemplate *TFT; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TFT_Present;
	c_epsQualityOfServ *NewQoS; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NewQoS_Present;
	c_epsLlcServAccessPointId *NegotiatedLLCSAPI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NegotiatedLLCSAPI_Present;
	ED_OCTET RadioPriority; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN RadioPriority_Present;
	c_epsPacketFlowIdentifie *PacketFlowIdentifier; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN PacketFlowIdentifier_Present;
	c_APNAggregateMaxBitRate *APNAMBR; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN APNAMBR_Present;
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsWLANOffloadAcceptability *WLANOffloadIndication; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN WLANOffloadIndication_Present;
	c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_HeaderCompressionCfg *HeaderCompressionCfg; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HeaderCompressionCfg_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_MODIFY_EPS_BEARER_CONTEXT_REQUEST;
#define INIT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST))
/*FRK03a*/
void FREE_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST(c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp);
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewEPSQoS(sp) ((sp)->NewEPSQoS_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_TFT(sp) ((sp)->TFT_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NewQoS(sp) ((sp)->NewQoS_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NegotiatedLLCSAPI(sp) ((sp)->NegotiatedLLCSAPI_Present)
#define SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(sp,present) (((sp)->RadioPriority_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_RadioPriority(sp) ((sp)->RadioPriority_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_PacketFlowIdentifier(sp) ((sp)->PacketFlowIdentifier_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_APNAMBR(sp) ((sp)->APNAMBR_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_WLANOffloadIndication(sp) ((sp)->WLANOffloadIndication_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_HeaderCompressionCfg(sp) ((sp)->HeaderCompressionCfg_Present)
int SETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions (c_MODIFY_EPS_BEARER_CONTEXT_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_MODIFY_EPS_BEARER_CONTEXT_REQUEST_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_EPS_NOTIFICATION' as a variable reference */
#define VAR_c_EPS_NOTIFICATION_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_EPS_NOTIFICATION' as a pointer */
#define PTR_c_EPS_NOTIFICATION_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_EPS_NOTIFICATION' as a variable reference */
#define VAR_c_EPS_NOTIFICATION_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_EPS_NOTIFICATION' as a pointer */
#define PTR_c_EPS_NOTIFICATION_ProcedureTransactionIdentity(var) (&var)

/* Access member 'NotificationIndicator' of type 'c_EPS_NOTIFICATION' as a variable reference */
#define VAR_c_EPS_NOTIFICATION_NotificationIndicator(var) var

/* Access member 'NotificationIndicator' of type 'c_EPS_NOTIFICATION' as a pointer */
#define PTR_c_EPS_NOTIFICATION_NotificationIndicator(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPS_NOTIFICATION {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR NotificationIndicator___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET NotificationIndicator; /* ODY01a *//*GBD01b*/

}	c_EPS_NOTIFICATION;
#define INIT_c_EPS_NOTIFICATION(sp) ED_RESET_MEM ((sp), sizeof (c_EPS_NOTIFICATION))
/*FRK03a*/
void FREE_c_EPS_NOTIFICATION(c_EPS_NOTIFICATION* sp);

/* Access member 'EPSBearerIdentity' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions(var) var

/* Access member 'BackOffTimer' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_BackOffTimer(var) (*var)

/* Access member 'BackOffTimer' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_BackOffTimer(var) var

/* Access member 'ReAttemptIndicator' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator(var) (*var)

/* Access member 'ReAttemptIndicator' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator(var) var

/* Access member 'NBIFOMContainer' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer(var) (*var)

/* Access member 'NBIFOMContainer' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REJECT' as a variable reference */
#define VAR_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_CONNECTIVITY_REJECT' as a pointer */
#define PTR_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions(var) var

/* DEFINITION OF BINARY c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer */
typedef struct _c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_PDN_CONNECTIVITY_REJECT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR NBIFOMContainer___LOCATOR  /*LBD01*/;

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsGprsTimer *BackOffTimer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN BackOffTimer_Present;
	c_epsReAttemptIndicator *ReAttemptIndicator; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ReAttemptIndicator_Present;
	c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer* NBIFOMContainer; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN NBIFOMContainer_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_PDN_CONNECTIVITY_REJECT;
#define INIT_c_PDN_CONNECTIVITY_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_PDN_CONNECTIVITY_REJECT))
/*FRK03a*/
void FREE_c_PDN_CONNECTIVITY_REJECT(c_PDN_CONNECTIVITY_REJECT* sp);
int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REJECT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_BackOffTimer (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REJECT_BackOffTimer(sp) ((sp)->BackOffTimer_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REJECT_ReAttemptIndicator(sp) ((sp)->ReAttemptIndicator_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REJECT_NBIFOMContainer(sp) ((sp)->NBIFOMContainer_Present)
int SETPRESENT_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions (c_PDN_CONNECTIVITY_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_CONNECTIVITY_REJECT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_PDN_DISCONNECT_REJECT' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REJECT_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_PDN_DISCONNECT_REJECT' as a pointer */
#define PTR_c_PDN_DISCONNECT_REJECT_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_DISCONNECT_REJECT' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REJECT_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_PDN_DISCONNECT_REJECT' as a pointer */
#define PTR_c_PDN_DISCONNECT_REJECT_ProcedureTransactionIdentity(var) (&var)

/* Access member 'ESMCause' of type 'c_PDN_DISCONNECT_REJECT' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REJECT_ESMCause(var) var

/* Access member 'ESMCause' of type 'c_PDN_DISCONNECT_REJECT' as a pointer */
#define PTR_c_PDN_DISCONNECT_REJECT_ESMCause(var) (&var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REJECT' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions(var) (*var)

/* Access member 'ProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REJECT' as a pointer */
#define PTR_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REJECT' as a variable reference */
#define VAR_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions(var) (*var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_PDN_DISCONNECT_REJECT' as a pointer */
#define PTR_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions(var) var


/*-A----------------------------------*/
typedef struct _c_PDN_DISCONNECT_REJECT {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ESMCause___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ESMCause; /* ODY01a *//*GBD01b*/
	c_epsProtocolCfgOpt *ProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ProtocolConfigurationOptions_Present;
	c_epsProtocolCfgOpt *ExtendedProtocolConfigurationOptions; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_PDN_DISCONNECT_REJECT;
#define INIT_c_PDN_DISCONNECT_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_PDN_DISCONNECT_REJECT))
/*FRK03a*/
void FREE_c_PDN_DISCONNECT_REJECT(c_PDN_DISCONNECT_REJECT* sp);
int SETPRESENT_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions (c_PDN_DISCONNECT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_DISCONNECT_REJECT_ProtocolConfigurationOptions(sp) ((sp)->ProtocolConfigurationOptions_Present)
int SETPRESENT_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions (c_PDN_DISCONNECT_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_PDN_DISCONNECT_REJECT_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'EPSBearerIdentity' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_RESPONSE_EPSBearerIdentity(var) var

/* Access member 'EPSBearerIdentity' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_RESPONSE_EPSBearerIdentity(var) (&var)

/* Access member 'ProcedureTransactionIdentity' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_RESPONSE_ProcedureTransactionIdentity(var) var

/* Access member 'ProcedureTransactionIdentity' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_RESPONSE_ProcedureTransactionIdentity(var) (&var)

/* Access member 'UserDataContainer' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer(var) var

/* Access member 'UserDataContainer' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer(var) (&var)

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a variable reference */
#define VAR_c_REMOTE_UE_REPORT_RESPONSE_ExtendedProtocolConfigurationOptions(var) var

/* Access member 'ExtendedProtocolConfigurationOptions' of type 'c_REMOTE_UE_REPORT_RESPONSE' as a pointer */
#define PTR_c_REMOTE_UE_REPORT_RESPONSE_ExtendedProtocolConfigurationOptions(var) (&var)

/* DEFINITION OF BINARY c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer */
typedef struct _c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_REMOTE_UE_REPORT_RESPONSE {
	ED_LOCATOR EPSBearerIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR ProcedureTransactionIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR UserDataContainer___LOCATOR  /*LBD02*/;
	ED_LOCATOR ExtendedProtocolConfigurationOptions___LOCATOR; /* QUI2 */

	ED_OCTET EPSBearerIdentity; /* ODY01a *//*GBD01b*/
	ED_OCTET ProcedureTransactionIdentity; /* ODY01a *//*GBD01b*/
	c_REMOTE_UE_REPORT_RESPONSE_UserDataContainer UserDataContainer; /* Static, variable size; bits needed 4784 *//*GBD01b*/
	ED_OCTET ExtendedProtocolConfigurationOptions; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ExtendedProtocolConfigurationOptions_Present;

}	c_REMOTE_UE_REPORT_RESPONSE;
#define INIT_c_REMOTE_UE_REPORT_RESPONSE(sp) ED_RESET_MEM ((sp), sizeof (c_REMOTE_UE_REPORT_RESPONSE))
/*FRK03a*/
void FREE_c_REMOTE_UE_REPORT_RESPONSE(c_REMOTE_UE_REPORT_RESPONSE* sp);
#define SETPRESENT_c_REMOTE_UE_REPORT_RESPONSE_ExtendedProtocolConfigurationOptions(sp,present) (((sp)->ExtendedProtocolConfigurationOptions_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_REMOTE_UE_REPORT_RESPONSE_ExtendedProtocolConfigurationOptions(sp) ((sp)->ExtendedProtocolConfigurationOptions_Present)

/* Access member 'spare' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_spare(var) var

/* Access member 'spare' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_spare(var) (&var)

/* Access member 'OddEven' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_OddEven(var) var

/* Access member 'OddEven' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_OddEven(var) (&var)

/* Access member 'IdentityType' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_IdentityType(var) var

/* Access member 'IdentityType' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_IdentityType(var) (&var)

/* Access member 'MCC2' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MCC2(var) var

/* Access member 'MCC2' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MCC1(var) var

/* Access member 'MCC1' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MNC3(var) var

/* Access member 'MNC3' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MCC3(var) var

/* Access member 'MCC3' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MNC2(var) var

/* Access member 'MNC2' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MNC1(var) var

/* Access member 'MNC1' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MNC1(var) (&var)

/* Access member 'MMEGroupID' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MMEGroupID(var) var

/* Access member 'MMEGroupID' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MMEGroupID(var) (&var)

/* Access member 'MMECode' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_MMECode(var) var

/* Access member 'MMECode' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_MMECode(var) (&var)

/* Access member 'M_TMSI' of type 'c_EPSMobileIdentity_GUTI' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI_M_TMSI(var) var

/* Access member 'M_TMSI' of type 'c_EPSMobileIdentity_GUTI' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI_M_TMSI(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPSMobileIdentity_GUTI {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MMEGroupID___LOCATOR; /* QUI2 */
	ED_LOCATOR MMECode___LOCATOR; /* QUI2 */
	ED_LOCATOR M_TMSI___LOCATOR; /* QUI2 */

	/*GBD01b*/
	/*GBD01b*/
	/*GBD01b*/
	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_SHORT MMEGroupID; /* ODY01a *//*GBD01b*/
	ED_OCTET MMECode; /* ODY01a *//*GBD01b*/
	ED_LONG M_TMSI; /* ODY01a *//*GBD01b*/

}	c_EPSMobileIdentity_GUTI;
#define INIT_c_EPSMobileIdentity_GUTI(sp) ED_RESET_MEM ((sp), sizeof (c_EPSMobileIdentity_GUTI))
/*FRK03a*/
void FREE_c_EPSMobileIdentity_GUTI(c_EPSMobileIdentity_GUTI* sp);

/* Access member 'spare' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_spare(var) var

/* Access member 'spare' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_spare(var) (&var)

/* Access member 'MBMSSessIdIndic' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MBMSSessIdIndic(var) var

/* Access member 'MBMSSessIdIndic' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MBMSSessIdIndic(var) (&var)

/* Access member 'MCCMNCIndic' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MCCMNCIndic(var) var

/* Access member 'MCCMNCIndic' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MCCMNCIndic(var) (&var)

/* Access member 'OddEven' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_OddEven(var) var

/* Access member 'OddEven' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_OddEven(var) (&var)

/* Access member 'IdentityType' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_IdentityType(var) var

/* Access member 'IdentityType' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_IdentityType(var) (&var)

/* Access member 'MBMSServiceID' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MBMSServiceID(var) var

/* Access member 'MBMSServiceID' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MBMSServiceID(var) (&var)

/* Access member 'MCC2' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MCC2(var) var

/* Access member 'MCC2' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MCC1(var) var

/* Access member 'MCC1' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MNC3(var) var

/* Access member 'MNC3' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MCC3(var) var

/* Access member 'MCC3' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MNC2(var) var

/* Access member 'MNC2' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MNC1(var) var

/* Access member 'MNC1' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MNC1(var) (&var)

/* Access member 'MBMSSessionIdentity' of type 'c_epsMobileId_TMGI' as a variable reference */
#define VAR_c_epsMobileId_TMGI_MBMSSessionIdentity(var) var

/* Access member 'MBMSSessionIdentity' of type 'c_epsMobileId_TMGI' as a pointer */
#define PTR_c_epsMobileId_TMGI_MBMSSessionIdentity(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsMobileId_TMGI {
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

}	c_epsMobileId_TMGI;
#define INIT_c_epsMobileId_TMGI(sp) ED_RESET_MEM ((sp), sizeof (c_epsMobileId_TMGI))
/*FRK03a*/
void FREE_c_epsMobileId_TMGI(c_epsMobileId_TMGI* sp);

/* Access member 'MCC2' of type 'c_epsPlmn' as a variable reference */
#define VAR_c_epsPlmn_MCC2(var) var

/* Access member 'MCC2' of type 'c_epsPlmn' as a pointer */
#define PTR_c_epsPlmn_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_epsPlmn' as a variable reference */
#define VAR_c_epsPlmn_MCC1(var) var

/* Access member 'MCC1' of type 'c_epsPlmn' as a pointer */
#define PTR_c_epsPlmn_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_epsPlmn' as a variable reference */
#define VAR_c_epsPlmn_MNC3(var) var

/* Access member 'MNC3' of type 'c_epsPlmn' as a pointer */
#define PTR_c_epsPlmn_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_epsPlmn' as a variable reference */
#define VAR_c_epsPlmn_MCC3(var) var

/* Access member 'MCC3' of type 'c_epsPlmn' as a pointer */
#define PTR_c_epsPlmn_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_epsPlmn' as a variable reference */
#define VAR_c_epsPlmn_MNC2(var) var

/* Access member 'MNC2' of type 'c_epsPlmn' as a pointer */
#define PTR_c_epsPlmn_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_epsPlmn' as a variable reference */
#define VAR_c_epsPlmn_MNC1(var) var

/* Access member 'MNC1' of type 'c_epsPlmn' as a pointer */
#define PTR_c_epsPlmn_MNC1(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsPlmn {
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

}	c_epsPlmn;
#define INIT_c_epsPlmn(sp) ED_RESET_MEM ((sp), sizeof (c_epsPlmn))
/*FRK03a*/
void FREE_c_epsPlmn(c_epsPlmn* sp);

/* Access member 'data' of type 'c_EPSMobileIdentity_IMSI_IdentityDigit' as a variable reference */
#define VAR_c_EPSMobileIdentity_IMSI_IdentityDigit_data(var) var

/* Access member 'data' of type 'c_EPSMobileIdentity_IMSI_IdentityDigit' as a pointer */
#define PTR_c_EPSMobileIdentity_IMSI_IdentityDigit_data(var) (&var)

/* Access member 'IdentityDigit' of type 'c_EPSMobileIdentity_IMSI' as a variable reference */
#define VAR_c_EPSMobileIdentity_IMSI_IdentityDigit(var) var

/* Access member 'IdentityDigit' of type 'c_EPSMobileIdentity_IMSI' as a pointer */
#define PTR_c_EPSMobileIdentity_IMSI_IdentityDigit(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_EPSMobileIdentity_IMSI_IdentityDigit */
typedef struct _c_EPSMobileIdentity_IMSI_IdentityDigit {

	ED_LONG* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-14709=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_EPSMobileIdentity_IMSI_IdentityDigit;


/*-A----------------------------------*/
typedef struct _c_EPSMobileIdentity_IMSI {

	c_EPSMobileIdentity_IMSI_IdentityDigit IdentityDigit;/*GFB09*//*GBD01b*/

}	c_EPSMobileIdentity_IMSI;
#define INIT_c_EPSMobileIdentity_IMSI(sp) ED_RESET_MEM ((sp), sizeof (c_EPSMobileIdentity_IMSI))
/*FRK03a*/
void FREE_c_EPSMobileIdentity_IMSI(c_EPSMobileIdentity_IMSI* sp);

/* Access member 'Type0' of type 'c_TrackingAreaIdentityList_Item' as a variable reference */
#define VAR_c_TrackingAreaIdentityList_Item_Type0(var) (*var)

/* Access member 'Type0' of type 'c_TrackingAreaIdentityList_Item' as a pointer */
#define PTR_c_TrackingAreaIdentityList_Item_Type0(var) var

/* Access member 'Type1' of type 'c_TrackingAreaIdentityList_Item' as a variable reference */
#define VAR_c_TrackingAreaIdentityList_Item_Type1(var) (*var)

/* Access member 'Type1' of type 'c_TrackingAreaIdentityList_Item' as a pointer */
#define PTR_c_TrackingAreaIdentityList_Item_Type1(var) var

/* Access member 'Type2' of type 'c_TrackingAreaIdentityList_Item' as a variable reference */
#define VAR_c_TrackingAreaIdentityList_Item_Type2(var) (*var)

/* Access member 'Type2' of type 'c_TrackingAreaIdentityList_Item' as a pointer */
#define PTR_c_TrackingAreaIdentityList_Item_Type2(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_TrackingAreaIdentityList_Item_NONE,
	U_c_TrackingAreaIdentityList_Item_Type0,
	U_c_TrackingAreaIdentityList_Item_Type1,
	U_c_TrackingAreaIdentityList_Item_Type2
} TPRESENT_c_TrackingAreaIdentityList_Item;

typedef struct _c_TrackingAreaIdentityList_Item {

		TPRESENT_c_TrackingAreaIdentityList_Item Present;
		union {
			c_PartialTrackingAreaIdentityList_Type0 *Type0; /* ODY01 *//*GBD01b*/
		
			c_PartialTrackingAreaIdentityList_Type1 *Type1; /* ODY01 *//*GBD01b*/
		
			c_PartialTrackingAreaIdentityList_Type2 *Type2; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_TrackingAreaIdentityList_Item;
#define INIT_c_TrackingAreaIdentityList_Item(sp) ED_RESET_MEM ((sp), sizeof (c_TrackingAreaIdentityList_Item))
/*FRK01a*/
void FREE_c_TrackingAreaIdentityList_Item (c_TrackingAreaIdentityList_Item* sp);

/* SETPRESENT commands for type 'c_TrackingAreaIdentityList_Item' */
int GLOB_SETPRESENT_c_TrackingAreaIdentityList_Item (c_TrackingAreaIdentityList_Item* sp, TPRESENT_c_TrackingAreaIdentityList_Item toBeSetPresent);
#define SETPRESENT_c_TrackingAreaIdentityList_Item_NONE(sp) GLOB_SETPRESENT_c_TrackingAreaIdentityList_Item(sp, U_c_TrackingAreaIdentityList_Item_NONE)
#define GETPRESENT_c_TrackingAreaIdentityList_Item_NONE(sp) ((sp)->Present == U_c_TrackingAreaIdentityList_Item_NONE)
#define SETPRESENT_c_TrackingAreaIdentityList_Item_Type0(sp) GLOB_SETPRESENT_c_TrackingAreaIdentityList_Item(sp, U_c_TrackingAreaIdentityList_Item_Type0)
#define GETPRESENT_c_TrackingAreaIdentityList_Item_Type0(sp) ((sp)->Present == U_c_TrackingAreaIdentityList_Item_Type0)
#define SETPRESENT_c_TrackingAreaIdentityList_Item_Type1(sp) GLOB_SETPRESENT_c_TrackingAreaIdentityList_Item(sp, U_c_TrackingAreaIdentityList_Item_Type1)
#define GETPRESENT_c_TrackingAreaIdentityList_Item_Type1(sp) ((sp)->Present == U_c_TrackingAreaIdentityList_Item_Type1)
#define SETPRESENT_c_TrackingAreaIdentityList_Item_Type2(sp) GLOB_SETPRESENT_c_TrackingAreaIdentityList_Item(sp, U_c_TrackingAreaIdentityList_Item_Type2)
#define GETPRESENT_c_TrackingAreaIdentityList_Item_Type2(sp) ((sp)->Present == U_c_TrackingAreaIdentityList_Item_Type2)
#define GETPRESENT_c_TrackingAreaIdentityList_Item(sp) ((sp)->Present)


/* Access member 'data' of type 'c_epsMobileId_Identity_IdentityDigit' as a variable reference */
#define VAR_c_epsMobileId_Identity_IdentityDigit_data(var) var

/* Access member 'data' of type 'c_epsMobileId_Identity_IdentityDigit' as a pointer */
#define PTR_c_epsMobileId_Identity_IdentityDigit_data(var) (&var)

/* Access member 'IdentityDigit' of type 'c_epsMobileId_Identity' as a variable reference */
#define VAR_c_epsMobileId_Identity_IdentityDigit(var) var

/* Access member 'IdentityDigit' of type 'c_epsMobileId_Identity' as a pointer */
#define PTR_c_epsMobileId_Identity_IdentityDigit(var) (&var)

/* Access member 'IdentityType' of type 'c_epsMobileId_Identity' as a variable reference */
#define VAR_c_epsMobileId_Identity_IdentityType(var) var

/* Access member 'IdentityType' of type 'c_epsMobileId_Identity' as a pointer */
#define PTR_c_epsMobileId_Identity_IdentityType(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_epsMobileId_Identity_IdentityDigit */
typedef struct _c_epsMobileId_Identity_IdentityDigit {

	ED_LONG* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-14813=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_epsMobileId_Identity_IdentityDigit;


/*-A----------------------------------*/
typedef struct _c_epsMobileId_Identity {
	ED_LOCATOR IdentityType___LOCATOR; /* QUI2 */

	c_epsMobileId_Identity_IdentityDigit IdentityDigit;/*GFB09*//*GBD01b*/
	ED_LONG IdentityType; /* ODY01a *//*GBD01b*/

}	c_epsMobileId_Identity;
#define INIT_c_epsMobileId_Identity(sp) ED_RESET_MEM ((sp), sizeof (c_epsMobileId_Identity))
/*FRK03a*/
void FREE_c_epsMobileId_Identity(c_epsMobileId_Identity* sp);

/* Access member 'ServiceCategory' of type 'c_epsTBCDEmergencyNumber' as a variable reference */
#define VAR_c_epsTBCDEmergencyNumber_ServiceCategory(var) var

/* Access member 'ServiceCategory' of type 'c_epsTBCDEmergencyNumber' as a pointer */
#define PTR_c_epsTBCDEmergencyNumber_ServiceCategory(var) (&var)

/* Access member 'data' of type 'c_epsTBCDEmergencyNumber_Numbers' as a variable reference */
#define VAR_c_epsTBCDEmergencyNumber_Numbers_data(var) var

/* Access member 'data' of type 'c_epsTBCDEmergencyNumber_Numbers' as a pointer */
#define PTR_c_epsTBCDEmergencyNumber_Numbers_data(var) (&var)

/* Access member 'Numbers' of type 'c_epsTBCDEmergencyNumber' as a variable reference */
#define VAR_c_epsTBCDEmergencyNumber_Numbers(var) var

/* Access member 'Numbers' of type 'c_epsTBCDEmergencyNumber' as a pointer */
#define PTR_c_epsTBCDEmergencyNumber_Numbers(var) (&var)

/* DEFINITION OF SUB-STRUCTURE c_epsTBCDEmergencyNumber_Numbers */
typedef struct _c_epsTBCDEmergencyNumber_Numbers {

	ED_OCTET* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-14829=EDCore::TDMSequence)  */
	int allocatedItems; /*ALC*/
	int items; /*XYZ*/
	ED_LOCATOR* data___LOCATOR /* ARLC02 */;

} c_epsTBCDEmergencyNumber_Numbers;


/*-A----------------------------------*/
typedef struct _c_epsTBCDEmergencyNumber {

	c_epsServCategory ServiceCategory; /* ODY01a *//*GBD01b*/
	c_epsTBCDEmergencyNumber_Numbers Numbers;/*GFB09*//*GBD01b*/

}	c_epsTBCDEmergencyNumber;
#define INIT_c_epsTBCDEmergencyNumber(sp) ED_RESET_MEM ((sp), sizeof (c_epsTBCDEmergencyNumber))
/*FRK03a*/
void FREE_c_epsTBCDEmergencyNumber(c_epsTBCDEmergencyNumber* sp);

/* Access member 'data' of type 'c_epsTBCDArray' as a variable reference */
#define VAR_c_epsTBCDArray_data(var) var

/* Access member 'data' of type 'c_epsTBCDArray' as a pointer */
#define PTR_c_epsTBCDArray_data(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsTBCDArray {

		ED_LONG* data; /* NDY01a *//*GBD01b*//*GAD01a*//*AR02 ('TDMSequence'-14833=EDCore::TDMSequence)  */
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_epsTBCDArray;
#define INIT_c_epsTBCDArray(sp) ED_RESET_MEM ((sp), sizeof (c_epsTBCDArray))
/*FRK02b*/
void FREE_c_epsTBCDArray (c_epsTBCDArray* sp);
/* SETITEMS/ADDITEMS commands for type 'c_epsTBCDArray'. */
int SETITEMS_c_epsTBCDArray (c_epsTBCDArray* sequence, int desiredItems);
#define ADDITEMS_c_epsTBCDArray(sequence, itemsToBeAdded) SETITEMS_c_epsTBCDArray (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'SysId' of type 'c_epsSupportedCodec' as a variable reference */
#define VAR_c_epsSupportedCodec_SysId(var) var

/* Access member 'SysId' of type 'c_epsSupportedCodec' as a pointer */
#define PTR_c_epsSupportedCodec_SysId(var) (&var)

/* Access member 'CodecBitmap' of type 'c_epsSupportedCodec' as a variable reference */
#define VAR_c_epsSupportedCodec_CodecBitmap(var) var

/* Access member 'CodecBitmap' of type 'c_epsSupportedCodec' as a pointer */
#define PTR_c_epsSupportedCodec_CodecBitmap(var) (&var)

/* DEFINITION OF BINARY c_epsSupportedCodec_CodecBitmap */
typedef struct _c_epsSupportedCodec_CodecBitmap {
	ED_BYTE* value; /* Variable size; bits needed 64 */
	int usedBits;
} c_epsSupportedCodec_CodecBitmap;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_epsSupportedCodec_CodecBitmap(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_epsSupportedCodec {
	ED_LOCATOR SysId___LOCATOR; /* QUI2 */
	ED_LOCATOR CodecBitmap___LOCATOR  /*LBD02*/;

	ED_LONG SysId; /* ODY01a *//*GBD01b*/
	c_epsSupportedCodec_CodecBitmap CodecBitmap; /* Static, variable size; bits needed 64 *//*GBD01b*/

}	c_epsSupportedCodec;
#define INIT_c_epsSupportedCodec(sp) ED_RESET_MEM ((sp), sizeof (c_epsSupportedCodec))
/*FRK03a*/
void FREE_c_epsSupportedCodec(c_epsSupportedCodec* sp);

/* Access member 'EBI07' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI07(var) var

/* Access member 'EBI07' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI07(var) (&var)

/* Access member 'EBI06' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI06(var) var

/* Access member 'EBI06' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI06(var) (&var)

/* Access member 'EBI05' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI05(var) var

/* Access member 'EBI05' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI05(var) (&var)

/* Access member 'EBI04' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI04(var) var

/* Access member 'EBI04' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI04(var) (&var)

/* Access member 'spare' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_spare(var) var

/* Access member 'spare' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_spare(var) (&var)

/* Access member 'EBI15' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI15(var) var

/* Access member 'EBI15' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI15(var) (&var)

/* Access member 'EBI14' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI14(var) var

/* Access member 'EBI14' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI14(var) (&var)

/* Access member 'EBI13' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI13(var) var

/* Access member 'EBI13' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI13(var) (&var)

/* Access member 'EBI12' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI12(var) var

/* Access member 'EBI12' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI12(var) (&var)

/* Access member 'EBI11' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI11(var) var

/* Access member 'EBI11' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI11(var) (&var)

/* Access member 'EBI10' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI10(var) var

/* Access member 'EBI10' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI10(var) (&var)

/* Access member 'EBI09' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI09(var) var

/* Access member 'EBI09' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI09(var) (&var)

/* Access member 'EBI08' of type 'c_EPSBearerContextStatus' as a variable reference */
#define VAR_c_EPSBearerContextStatus_EBI08(var) var

/* Access member 'EBI08' of type 'c_EPSBearerContextStatus' as a pointer */
#define PTR_c_EPSBearerContextStatus_EBI08(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPSBearerContextStatus {
	ED_LOCATOR EBI07___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI06___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI05___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI04___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI15___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI14___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI13___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI12___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI11___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI10___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI09___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI08___LOCATOR; /* QUI2 */

	ED_BOOLEAN EBI07; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI06; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI05; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI04; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN EBI15; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI14; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI13; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI12; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI11; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI10; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI09; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI08; /* ODY01a *//*GBD01b*/

}	c_EPSBearerContextStatus;
#define INIT_c_EPSBearerContextStatus(sp) ED_RESET_MEM ((sp), sizeof (c_EPSBearerContextStatus))
/*FRK03a*/
void FREE_c_EPSBearerContextStatus(c_EPSBearerContextStatus* sp);

/* Access member 'ANB_UP_CIOT' of type 'c_AdditionalUpdateResult' as a variable reference */
#define VAR_c_AdditionalUpdateResult_ANB_UP_CIOT(var) var

/* Access member 'ANB_UP_CIOT' of type 'c_AdditionalUpdateResult' as a pointer */
#define PTR_c_AdditionalUpdateResult_ANB_UP_CIOT(var) (&var)

/* Access member 'ANB_CP_CIOT' of type 'c_AdditionalUpdateResult' as a variable reference */
#define VAR_c_AdditionalUpdateResult_ANB_CP_CIOT(var) var

/* Access member 'ANB_CP_CIOT' of type 'c_AdditionalUpdateResult' as a pointer */
#define PTR_c_AdditionalUpdateResult_ANB_CP_CIOT(var) (&var)

/* Access member 'Additional_update_result' of type 'c_AdditionalUpdateResult' as a variable reference */
#define VAR_c_AdditionalUpdateResult_Additional_update_result(var) var

/* Access member 'Additional_update_result' of type 'c_AdditionalUpdateResult' as a pointer */
#define PTR_c_AdditionalUpdateResult_Additional_update_result(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AdditionalUpdateResult {
	ED_LOCATOR ANB_UP_CIOT___LOCATOR; /* QUI2 */
	ED_LOCATOR ANB_CP_CIOT___LOCATOR; /* QUI2 */
	ED_LOCATOR Additional_update_result___LOCATOR; /* QUI2 */

	ED_BOOLEAN ANB_UP_CIOT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ANB_CP_CIOT; /* ODY01a *//*GBD01b*/
	ED_OCTET Additional_update_result; /* ODY01a *//*GBD01b*/

}	c_AdditionalUpdateResult;
#define INIT_c_AdditionalUpdateResult(sp) ED_RESET_MEM ((sp), sizeof (c_AdditionalUpdateResult))
/*FRK03a*/
void FREE_c_AdditionalUpdateResult(c_AdditionalUpdateResult* sp);

/* Access member 'PNB_CIoT' of type 'c_epsAdditionalUpdateType' as a variable reference */
#define VAR_c_epsAdditionalUpdateType_PNB_CIoT(var) var

/* Access member 'PNB_CIoT' of type 'c_epsAdditionalUpdateType' as a pointer */
#define PTR_c_epsAdditionalUpdateType_PNB_CIoT(var) (&var)

/* Access member 'SAF' of type 'c_epsAdditionalUpdateType' as a variable reference */
#define VAR_c_epsAdditionalUpdateType_SAF(var) var

/* Access member 'SAF' of type 'c_epsAdditionalUpdateType' as a pointer */
#define PTR_c_epsAdditionalUpdateType_SAF(var) (&var)

/* Access member 'AUTV' of type 'c_epsAdditionalUpdateType' as a variable reference */
#define VAR_c_epsAdditionalUpdateType_AUTV(var) var

/* Access member 'AUTV' of type 'c_epsAdditionalUpdateType' as a pointer */
#define PTR_c_epsAdditionalUpdateType_AUTV(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsAdditionalUpdateType {
	ED_LOCATOR PNB_CIoT___LOCATOR; /* QUI2 */
	ED_LOCATOR SAF___LOCATOR; /* QUI2 */
	ED_LOCATOR AUTV___LOCATOR; /* QUI2 */

	ED_OCTET PNB_CIoT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SAF; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AUTV; /* ODY01a *//*GBD01b*/

}	c_epsAdditionalUpdateType;
#define INIT_c_epsAdditionalUpdateType(sp) ED_RESET_MEM ((sp), sizeof (c_epsAdditionalUpdateType))
/*FRK03a*/
void FREE_c_epsAdditionalUpdateType(c_epsAdditionalUpdateType* sp);

/* Access member 'SwitchOff' of type 'c_EPSDetachType' as a variable reference */
#define VAR_c_EPSDetachType_SwitchOff(var) var

/* Access member 'SwitchOff' of type 'c_EPSDetachType' as a pointer */
#define PTR_c_EPSDetachType_SwitchOff(var) (&var)

/* Access member 'Type' of type 'c_EPSDetachType' as a variable reference */
#define VAR_c_EPSDetachType_Type(var) var

/* Access member 'Type' of type 'c_EPSDetachType' as a pointer */
#define PTR_c_EPSDetachType_Type(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPSDetachType {
	ED_LOCATOR SwitchOff___LOCATOR; /* QUI2 */
	ED_LOCATOR Type___LOCATOR; /* QUI2 */

	ED_BOOLEAN SwitchOff; /* ODY01a *//*GBD01b*/
	ED_OCTET Type; /* ODY01a *//*GBD01b*/

}	c_EPSDetachType;
#define INIT_c_EPSDetachType(sp) ED_RESET_MEM ((sp), sizeof (c_EPSDetachType))
/*FRK03a*/
void FREE_c_EPSDetachType(c_EPSDetachType* sp);

/* Access member 'CP_CIoT' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_CP_CIoT(var) var

/* Access member 'CP_CIoT' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_CP_CIoT(var) (&var)

/* Access member 'ERw_oPDN' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_ERw_oPDN(var) var

/* Access member 'ERw_oPDN' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_ERw_oPDN(var) (&var)

/* Access member 'ESR_PS' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_ESR_PS(var) var

/* Access member 'ESR_PS' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_ESR_PS(var) (&var)

/* Access member 'CS_LCS' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_CS_LCS(var) var

/* Access member 'CS_LCS' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_CS_LCS(var) (&var)

/* Access member 'EPC_LCS' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_EPC_LCS(var) var

/* Access member 'EPC_LCS' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_EPC_LCS(var) (&var)

/* Access member 'EMC_BS' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_EMC_BS(var) var

/* Access member 'EMC_BS' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_EMC_BS(var) (&var)

/* Access member 'IMS_VoPS' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_IMS_VoPS(var) var

/* Access member 'IMS_VoPS' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_IMS_VoPS(var) (&var)

/* Access member 'spare' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_spare(var) var

/* Access member 'spare' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_spare(var) (&var)

/* Access member 'ePCO' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_ePCO(var) var

/* Access member 'ePCO' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_ePCO(var) (&var)

/* Access member 'HC_CP_CIoT' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_HC_CP_CIoT(var) var

/* Access member 'HC_CP_CIoT' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_HC_CP_CIoT(var) (&var)

/* Access member 'S1_U_data' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_S1_U_data(var) var

/* Access member 'S1_U_data' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_S1_U_data(var) (&var)

/* Access member 'UP_CIoT' of type 'c_EPSNetworkFeatureSupport' as a variable reference */
#define VAR_c_EPSNetworkFeatureSupport_UP_CIoT(var) var

/* Access member 'UP_CIoT' of type 'c_EPSNetworkFeatureSupport' as a pointer */
#define PTR_c_EPSNetworkFeatureSupport_UP_CIoT(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPSNetworkFeatureSupport {
	ED_LOCATOR CP_CIoT___LOCATOR; /* QUI2 */
	ED_LOCATOR ERw_oPDN___LOCATOR; /* QUI2 */
	ED_LOCATOR ESR_PS___LOCATOR; /* QUI2 */
	ED_LOCATOR CS_LCS___LOCATOR; /* QUI2 */
	ED_LOCATOR EPC_LCS___LOCATOR; /* QUI2 */
	ED_LOCATOR EMC_BS___LOCATOR; /* QUI2 */
	ED_LOCATOR IMS_VoPS___LOCATOR; /* QUI2 */
	ED_LOCATOR ePCO___LOCATOR; /* QUI2 */
	ED_LOCATOR HC_CP_CIoT___LOCATOR; /* QUI2 */
	ED_LOCATOR S1_U_data___LOCATOR; /* QUI2 */
	ED_LOCATOR UP_CIoT___LOCATOR; /* QUI2 */

	ED_BOOLEAN CP_CIoT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ERw_oPDN; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ESR_PS; /* ODY01a *//*GBD01b*/
	ED_OCTET CS_LCS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EPC_LCS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMC_BS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IMS_VoPS; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BOOLEAN ePCO; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HC_CP_CIoT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN S1_U_data; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UP_CIoT; /* ODY01a *//*GBD01b*/

}	c_EPSNetworkFeatureSupport;
#define INIT_c_EPSNetworkFeatureSupport(sp) ED_RESET_MEM ((sp), sizeof (c_EPSNetworkFeatureSupport))
/*FRK03a*/
void FREE_c_EPSNetworkFeatureSupport(c_EPSNetworkFeatureSupport* sp);

/* Access member 'Active' of type 'c_EPSUpdateType' as a variable reference */
#define VAR_c_EPSUpdateType_Active(var) var

/* Access member 'Active' of type 'c_EPSUpdateType' as a pointer */
#define PTR_c_EPSUpdateType_Active(var) (&var)

/* Access member 'EPSUpdTypeValue' of type 'c_EPSUpdateType' as a variable reference */
#define VAR_c_EPSUpdateType_EPSUpdTypeValue(var) var

/* Access member 'EPSUpdTypeValue' of type 'c_EPSUpdateType' as a pointer */
#define PTR_c_EPSUpdateType_EPSUpdTypeValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPSUpdateType {
	ED_LOCATOR Active___LOCATOR; /* QUI2 */
	ED_LOCATOR EPSUpdTypeValue___LOCATOR; /* QUI2 */

	ED_BOOLEAN Active; /* ODY01a *//*GBD01b*/
	ED_OCTET EPSUpdTypeValue; /* ODY01a *//*GBD01b*/

}	c_EPSUpdateType;
#define INIT_c_EPSUpdateType(sp) ED_RESET_MEM ((sp), sizeof (c_EPSUpdateType))
/*FRK03a*/
void FREE_c_EPSUpdateType(c_EPSUpdateType* sp);

/* Access member 'KSIasme' of type 'c_KSIAndSequenceNumber' as a variable reference */
#define VAR_c_KSIAndSequenceNumber_KSIasme(var) var

/* Access member 'KSIasme' of type 'c_KSIAndSequenceNumber' as a pointer */
#define PTR_c_KSIAndSequenceNumber_KSIasme(var) (&var)

/* Access member 'SequenceNumber' of type 'c_KSIAndSequenceNumber' as a variable reference */
#define VAR_c_KSIAndSequenceNumber_SequenceNumber(var) var

/* Access member 'SequenceNumber' of type 'c_KSIAndSequenceNumber' as a pointer */
#define PTR_c_KSIAndSequenceNumber_SequenceNumber(var) (&var)


/*-A----------------------------------*/
typedef struct _c_KSIAndSequenceNumber {
	ED_LOCATOR KSIasme___LOCATOR; /* QUI2 */
	ED_LOCATOR SequenceNumber___LOCATOR; /* QUI2 */

	ED_OCTET KSIasme; /* ODY01a *//*GBD01b*/
	ED_OCTET SequenceNumber; /* ODY01a *//*GBD01b*/

}	c_KSIAndSequenceNumber;
#define INIT_c_KSIAndSequenceNumber(sp) ED_RESET_MEM ((sp), sizeof (c_KSIAndSequenceNumber))
/*FRK03a*/
void FREE_c_KSIAndSequenceNumber(c_KSIAndSequenceNumber* sp);

/* Access member 'TSC' of type 'c_NASKeySetIdentifier' as a variable reference */
#define VAR_c_NASKeySetIdentifier_TSC(var) var

/* Access member 'TSC' of type 'c_NASKeySetIdentifier' as a pointer */
#define PTR_c_NASKeySetIdentifier_TSC(var) (&var)

/* Access member 'NASKeySetId' of type 'c_NASKeySetIdentifier' as a variable reference */
#define VAR_c_NASKeySetIdentifier_NASKeySetId(var) var

/* Access member 'NASKeySetId' of type 'c_NASKeySetIdentifier' as a pointer */
#define PTR_c_NASKeySetIdentifier_NASKeySetId(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NASKeySetIdentifier {
	ED_LOCATOR TSC___LOCATOR; /* QUI2 */
	ED_LOCATOR NASKeySetId___LOCATOR; /* QUI2 */

	ED_BOOLEAN TSC; /* ODY01a *//*GBD01b*/
	ED_OCTET NASKeySetId; /* ODY01a *//*GBD01b*/

}	c_NASKeySetIdentifier;
#define INIT_c_NASKeySetIdentifier(sp) ED_RESET_MEM ((sp), sizeof (c_NASKeySetIdentifier))
/*FRK03a*/
void FREE_c_NASKeySetIdentifier(c_NASKeySetIdentifier* sp);

/* Access member 'spare1' of type 'c_NASSecurityAlgorithms' as a variable reference */
#define VAR_c_NASSecurityAlgorithms_spare1(var) var

/* Access member 'spare1' of type 'c_NASSecurityAlgorithms' as a pointer */
#define PTR_c_NASSecurityAlgorithms_spare1(var) (&var)

/* Access member 'TypeOfCipheringAlg' of type 'c_NASSecurityAlgorithms' as a variable reference */
#define VAR_c_NASSecurityAlgorithms_TypeOfCipheringAlg(var) var

/* Access member 'TypeOfCipheringAlg' of type 'c_NASSecurityAlgorithms' as a pointer */
#define PTR_c_NASSecurityAlgorithms_TypeOfCipheringAlg(var) (&var)

/* Access member 'spare2' of type 'c_NASSecurityAlgorithms' as a variable reference */
#define VAR_c_NASSecurityAlgorithms_spare2(var) var

/* Access member 'spare2' of type 'c_NASSecurityAlgorithms' as a pointer */
#define PTR_c_NASSecurityAlgorithms_spare2(var) (&var)

/* Access member 'TypeOfIntegrityProtectionAlg' of type 'c_NASSecurityAlgorithms' as a variable reference */
#define VAR_c_NASSecurityAlgorithms_TypeOfIntegrityProtectionAlg(var) var

/* Access member 'TypeOfIntegrityProtectionAlg' of type 'c_NASSecurityAlgorithms' as a pointer */
#define PTR_c_NASSecurityAlgorithms_TypeOfIntegrityProtectionAlg(var) (&var)


/*-A----------------------------------*/
typedef struct _c_NASSecurityAlgorithms {
	ED_LOCATOR TypeOfCipheringAlg___LOCATOR; /* QUI2 */
	ED_LOCATOR TypeOfIntegrityProtectionAlg___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET TypeOfCipheringAlg; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET TypeOfIntegrityProtectionAlg; /* ODY01a *//*GBD01b*/

}	c_NASSecurityAlgorithms;
#define INIT_c_NASSecurityAlgorithms(sp) ED_RESET_MEM ((sp), sizeof (c_NASSecurityAlgorithms))
/*FRK03a*/
void FREE_c_NASSecurityAlgorithms(c_NASSecurityAlgorithms* sp);

/* Access member 'spare' of type 'c_ExtendedEMMCause' as a variable reference */
#define VAR_c_ExtendedEMMCause_spare(var) var

/* Access member 'spare' of type 'c_ExtendedEMMCause' as a pointer */
#define PTR_c_ExtendedEMMCause_spare(var) (&var)

/* Access member 'E_UTRAN_allowed' of type 'c_ExtendedEMMCause' as a variable reference */
#define VAR_c_ExtendedEMMCause_E_UTRAN_allowed(var) var

/* Access member 'E_UTRAN_allowed' of type 'c_ExtendedEMMCause' as a pointer */
#define PTR_c_ExtendedEMMCause_E_UTRAN_allowed(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ExtendedEMMCause {
	ED_LOCATOR E_UTRAN_allowed___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN E_UTRAN_allowed; /* ODY01a *//*GBD01b*/

}	c_ExtendedEMMCause;
#define INIT_c_ExtendedEMMCause(sp) ED_RESET_MEM ((sp), sizeof (c_ExtendedEMMCause))
/*FRK03a*/
void FREE_c_ExtendedEMMCause(c_ExtendedEMMCause* sp);

/* Access member 'MCC2' of type 'c_TrackingAreaIdentity' as a variable reference */
#define VAR_c_TrackingAreaIdentity_MCC2(var) var

/* Access member 'MCC2' of type 'c_TrackingAreaIdentity' as a pointer */
#define PTR_c_TrackingAreaIdentity_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_TrackingAreaIdentity' as a variable reference */
#define VAR_c_TrackingAreaIdentity_MCC1(var) var

/* Access member 'MCC1' of type 'c_TrackingAreaIdentity' as a pointer */
#define PTR_c_TrackingAreaIdentity_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_TrackingAreaIdentity' as a variable reference */
#define VAR_c_TrackingAreaIdentity_MNC3(var) var

/* Access member 'MNC3' of type 'c_TrackingAreaIdentity' as a pointer */
#define PTR_c_TrackingAreaIdentity_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_TrackingAreaIdentity' as a variable reference */
#define VAR_c_TrackingAreaIdentity_MCC3(var) var

/* Access member 'MCC3' of type 'c_TrackingAreaIdentity' as a pointer */
#define PTR_c_TrackingAreaIdentity_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_TrackingAreaIdentity' as a variable reference */
#define VAR_c_TrackingAreaIdentity_MNC2(var) var

/* Access member 'MNC2' of type 'c_TrackingAreaIdentity' as a pointer */
#define PTR_c_TrackingAreaIdentity_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_TrackingAreaIdentity' as a variable reference */
#define VAR_c_TrackingAreaIdentity_MNC1(var) var

/* Access member 'MNC1' of type 'c_TrackingAreaIdentity' as a pointer */
#define PTR_c_TrackingAreaIdentity_MNC1(var) (&var)

/* Access member 'TAC' of type 'c_TrackingAreaIdentity' as a variable reference */
#define VAR_c_TrackingAreaIdentity_TAC(var) var

/* Access member 'TAC' of type 'c_TrackingAreaIdentity' as a pointer */
#define PTR_c_TrackingAreaIdentity_TAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TrackingAreaIdentity {
	ED_LOCATOR MCC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC1___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MCC3___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC2___LOCATOR; /* QUI2 */
	ED_LOCATOR MNC1___LOCATOR; /* QUI2 */
	ED_LOCATOR TAC___LOCATOR; /* QUI2 */

	ED_OCTET MCC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC1; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MCC3; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC2; /* ODY01a *//*GBD01b*/
	ED_OCTET MNC1; /* ODY01a *//*GBD01b*/
	ED_SHORT TAC; /* ODY01a *//*GBD01b*/

}	c_TrackingAreaIdentity;
#define INIT_c_TrackingAreaIdentity(sp) ED_RESET_MEM ((sp), sizeof (c_TrackingAreaIdentity))
/*FRK03a*/
void FREE_c_TrackingAreaIdentity(c_TrackingAreaIdentity* sp);

/* Access member 'spare' of type 'c_GUTIType' as a variable reference */
#define VAR_c_GUTIType_spare(var) var

/* Access member 'spare' of type 'c_GUTIType' as a pointer */
#define PTR_c_GUTIType_spare(var) (&var)

/* Access member 'GUTIType' of type 'c_GUTIType' as a variable reference */
#define VAR_c_GUTIType_GUTIType(var) var

/* Access member 'GUTIType' of type 'c_GUTIType' as a pointer */
#define PTR_c_GUTIType_GUTIType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_GUTIType {
	ED_LOCATOR GUTIType___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN GUTIType; /* ODY01a *//*GBD01b*/

}	c_GUTIType;
#define INIT_c_GUTIType(sp) ED_RESET_MEM ((sp), sizeof (c_GUTIType))
/*FRK03a*/
void FREE_c_GUTIType(c_GUTIType* sp);

/* Access member 'ActiveFlag' of type 'c_DataServiceType' as a variable reference */
#define VAR_c_DataServiceType_ActiveFlag(var) var

/* Access member 'ActiveFlag' of type 'c_DataServiceType' as a pointer */
#define PTR_c_DataServiceType_ActiveFlag(var) (&var)

/* Access member 'Value' of type 'c_DataServiceType' as a variable reference */
#define VAR_c_DataServiceType_Value(var) var

/* Access member 'Value' of type 'c_DataServiceType' as a pointer */
#define PTR_c_DataServiceType_Value(var) (&var)


/*-A----------------------------------*/
typedef struct _c_DataServiceType {
	ED_LOCATOR ActiveFlag___LOCATOR; /* QUI2 */
	ED_LOCATOR Value___LOCATOR; /* QUI2 */

	ED_BOOLEAN ActiveFlag; /* ODY01a *//*GBD01b*/
	ED_OCTET Value; /* ODY01a *//*GBD01b*/

}	c_DataServiceType;
#define INIT_c_DataServiceType(sp) ED_RESET_MEM ((sp), sizeof (c_DataServiceType))
/*FRK03a*/
void FREE_c_DataServiceType(c_DataServiceType* sp);

/* Access member 'EBI_7' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_7(var) var

/* Access member 'EBI_7' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_7(var) (&var)

/* Access member 'EBI_6' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_6(var) var

/* Access member 'EBI_6' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_6(var) (&var)

/* Access member 'EBI_5' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_5(var) var

/* Access member 'EBI_5' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_5(var) (&var)

/* Access member 'EBI_4' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_4(var) var

/* Access member 'EBI_4' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_4(var) (&var)

/* Access member 'EBI_3' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_3(var) var

/* Access member 'EBI_3' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_3(var) (&var)

/* Access member 'EBI_2' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_2(var) var

/* Access member 'EBI_2' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_2(var) (&var)

/* Access member 'EBI_1' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_1(var) var

/* Access member 'EBI_1' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_1(var) (&var)

/* Access member 'EBI_0' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_0(var) var

/* Access member 'EBI_0' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_0(var) (&var)

/* Access member 'EBI_15' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_15(var) var

/* Access member 'EBI_15' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_15(var) (&var)

/* Access member 'EBI_14' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_14(var) var

/* Access member 'EBI_14' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_14(var) (&var)

/* Access member 'EBI_13' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_13(var) var

/* Access member 'EBI_13' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_13(var) (&var)

/* Access member 'EBI_12' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_12(var) var

/* Access member 'EBI_12' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_12(var) (&var)

/* Access member 'EBI_11' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_11(var) var

/* Access member 'EBI_11' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_11(var) (&var)

/* Access member 'EBI_10' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_10(var) var

/* Access member 'EBI_10' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_10(var) (&var)

/* Access member 'EBI_9' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_9(var) var

/* Access member 'EBI_9' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_9(var) (&var)

/* Access member 'EBI_8' of type 'c_HeaderCompressionCfgStatus' as a variable reference */
#define VAR_c_HeaderCompressionCfgStatus_EBI_8(var) var

/* Access member 'EBI_8' of type 'c_HeaderCompressionCfgStatus' as a pointer */
#define PTR_c_HeaderCompressionCfgStatus_EBI_8(var) (&var)


/*-A----------------------------------*/
typedef struct _c_HeaderCompressionCfgStatus {
	ED_LOCATOR EBI_7___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_6___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_5___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_4___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_3___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_2___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_1___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_0___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_15___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_14___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_13___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_12___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_11___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_10___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_9___LOCATOR; /* QUI2 */
	ED_LOCATOR EBI_8___LOCATOR; /* QUI2 */

	ED_BOOLEAN EBI_7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_0; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_15; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_14; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_13; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_12; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_11; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_10; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_9; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EBI_8; /* ODY01a *//*GBD01b*/

}	c_HeaderCompressionCfgStatus;
#define INIT_c_HeaderCompressionCfgStatus(sp) ED_RESET_MEM ((sp), sizeof (c_HeaderCompressionCfgStatus))
/*FRK03a*/
void FREE_c_HeaderCompressionCfgStatus(c_HeaderCompressionCfgStatus* sp);

/* Access member 'MCC2' of type 'c_epsLocationAreaId' as a variable reference */
#define VAR_c_epsLocationAreaId_MCC2(var) var

/* Access member 'MCC2' of type 'c_epsLocationAreaId' as a pointer */
#define PTR_c_epsLocationAreaId_MCC2(var) (&var)

/* Access member 'MCC1' of type 'c_epsLocationAreaId' as a variable reference */
#define VAR_c_epsLocationAreaId_MCC1(var) var

/* Access member 'MCC1' of type 'c_epsLocationAreaId' as a pointer */
#define PTR_c_epsLocationAreaId_MCC1(var) (&var)

/* Access member 'MNC3' of type 'c_epsLocationAreaId' as a variable reference */
#define VAR_c_epsLocationAreaId_MNC3(var) var

/* Access member 'MNC3' of type 'c_epsLocationAreaId' as a pointer */
#define PTR_c_epsLocationAreaId_MNC3(var) (&var)

/* Access member 'MCC3' of type 'c_epsLocationAreaId' as a variable reference */
#define VAR_c_epsLocationAreaId_MCC3(var) var

/* Access member 'MCC3' of type 'c_epsLocationAreaId' as a pointer */
#define PTR_c_epsLocationAreaId_MCC3(var) (&var)

/* Access member 'MNC2' of type 'c_epsLocationAreaId' as a variable reference */
#define VAR_c_epsLocationAreaId_MNC2(var) var

/* Access member 'MNC2' of type 'c_epsLocationAreaId' as a pointer */
#define PTR_c_epsLocationAreaId_MNC2(var) (&var)

/* Access member 'MNC1' of type 'c_epsLocationAreaId' as a variable reference */
#define VAR_c_epsLocationAreaId_MNC1(var) var

/* Access member 'MNC1' of type 'c_epsLocationAreaId' as a pointer */
#define PTR_c_epsLocationAreaId_MNC1(var) (&var)

/* Access member 'LAC' of type 'c_epsLocationAreaId' as a variable reference */
#define VAR_c_epsLocationAreaId_LAC(var) var

/* Access member 'LAC' of type 'c_epsLocationAreaId' as a pointer */
#define PTR_c_epsLocationAreaId_LAC(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsLocationAreaId {
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

}	c_epsLocationAreaId;
#define INIT_c_epsLocationAreaId(sp) ED_RESET_MEM ((sp), sizeof (c_epsLocationAreaId))
/*FRK03a*/
void FREE_c_epsLocationAreaId(c_epsLocationAreaId* sp);

/* Access member 'spare1' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_spare1(var) var

/* Access member 'spare1' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_spare1(var) (&var)

/* Access member 'RevisionLevel' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_RevisionLevel(var) var

/* Access member 'RevisionLevel' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_RevisionLevel(var) (&var)

/* Access member 'EsInd' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_EsInd(var) var

/* Access member 'EsInd' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_EsInd(var) (&var)

/* Access member 'A5_1' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_A5_1(var) var

/* Access member 'A5_1' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_A5_1(var) (&var)

/* Access member 'RFPowerCapability' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_RFPowerCapability(var) var

/* Access member 'RFPowerCapability' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_RFPowerCapability(var) (&var)

/* Access member 'spare2' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_spare2(var) var

/* Access member 'spare2' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_spare2(var) (&var)

/* Access member 'PSCapability' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_PSCapability(var) var

/* Access member 'PSCapability' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_PSCapability(var) (&var)

/* Access member 'SSScreenIndicator' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_SSScreenIndicator(var) var

/* Access member 'SSScreenIndicator' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_SSScreenIndicator(var) (&var)

/* Access member 'SMCapability' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_SMCapability(var) var

/* Access member 'SMCapability' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_SMCapability(var) (&var)

/* Access member 'VBS' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_VBS(var) var

/* Access member 'VBS' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_VBS(var) (&var)

/* Access member 'VGCS' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_VGCS(var) var

/* Access member 'VGCS' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_VGCS(var) (&var)

/* Access member 'FC' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_FC(var) var

/* Access member 'FC' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_FC(var) (&var)

/* Access member 'CM3' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_CM3(var) var

/* Access member 'CM3' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_CM3(var) (&var)

/* Access member 'spare3' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_spare3(var) var

/* Access member 'spare3' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_spare3(var) (&var)

/* Access member 'LCSVA_CAP' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_LCSVA_CAP(var) var

/* Access member 'LCSVA_CAP' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_LCSVA_CAP(var) (&var)

/* Access member 'UCS2' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_UCS2(var) var

/* Access member 'UCS2' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_UCS2(var) (&var)

/* Access member 'SoLSA' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_SoLSA(var) var

/* Access member 'SoLSA' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_SoLSA(var) (&var)

/* Access member 'CMSP' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_CMSP(var) var

/* Access member 'CMSP' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_CMSP(var) (&var)

/* Access member 'A5_3' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_A5_3(var) var

/* Access member 'A5_3' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_A5_3(var) (&var)

/* Access member 'A5_2' of type 'c_epsMobileStationClassmark2' as a variable reference */
#define VAR_c_epsMobileStationClassmark2_A5_2(var) var

/* Access member 'A5_2' of type 'c_epsMobileStationClassmark2' as a pointer */
#define PTR_c_epsMobileStationClassmark2_A5_2(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsMobileStationClassmark2 {
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

}	c_epsMobileStationClassmark2;
#define INIT_c_epsMobileStationClassmark2(sp) ED_RESET_MEM ((sp), sizeof (c_epsMobileStationClassmark2))
/*FRK03a*/
void FREE_c_epsMobileStationClassmark2(c_epsMobileStationClassmark2* sp);

/* Access member 'spare' of type 'c_epsMSNetworkFeatureSupport' as a variable reference */
#define VAR_c_epsMSNetworkFeatureSupport_spare(var) var

/* Access member 'spare' of type 'c_epsMSNetworkFeatureSupport' as a pointer */
#define PTR_c_epsMSNetworkFeatureSupport_spare(var) (&var)

/* Access member 'extendedPeriodicTimers' of type 'c_epsMSNetworkFeatureSupport' as a variable reference */
#define VAR_c_epsMSNetworkFeatureSupport_extendedPeriodicTimers(var) var

/* Access member 'extendedPeriodicTimers' of type 'c_epsMSNetworkFeatureSupport' as a pointer */
#define PTR_c_epsMSNetworkFeatureSupport_extendedPeriodicTimers(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsMSNetworkFeatureSupport {
	ED_LOCATOR extendedPeriodicTimers___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN extendedPeriodicTimers; /* ODY01a *//*GBD01b*/

}	c_epsMSNetworkFeatureSupport;
#define INIT_c_epsMSNetworkFeatureSupport(sp) ED_RESET_MEM ((sp), sizeof (c_epsMSNetworkFeatureSupport))
/*FRK03a*/
void FREE_c_epsMSNetworkFeatureSupport(c_epsMSNetworkFeatureSupport* sp);

/* Access member 'ext' of type 'c_epsNetwkName' as a variable reference */
#define VAR_c_epsNetwkName_ext(var) var

/* Access member 'ext' of type 'c_epsNetwkName' as a pointer */
#define PTR_c_epsNetwkName_ext(var) (&var)

/* Access member 'CodingScheme' of type 'c_epsNetwkName' as a variable reference */
#define VAR_c_epsNetwkName_CodingScheme(var) var

/* Access member 'CodingScheme' of type 'c_epsNetwkName' as a pointer */
#define PTR_c_epsNetwkName_CodingScheme(var) (&var)

/* Access member 'AddCI' of type 'c_epsNetwkName' as a variable reference */
#define VAR_c_epsNetwkName_AddCI(var) var

/* Access member 'AddCI' of type 'c_epsNetwkName' as a pointer */
#define PTR_c_epsNetwkName_AddCI(var) (&var)

/* Access member 'SpareBitsInLastOctet' of type 'c_epsNetwkName' as a variable reference */
#define VAR_c_epsNetwkName_SpareBitsInLastOctet(var) var

/* Access member 'SpareBitsInLastOctet' of type 'c_epsNetwkName' as a pointer */
#define PTR_c_epsNetwkName_SpareBitsInLastOctet(var) (&var)

/* Access member 'TextString' of type 'c_epsNetwkName' as a variable reference */
#define VAR_c_epsNetwkName_TextString(var) var

/* Access member 'TextString' of type 'c_epsNetwkName' as a pointer */
#define PTR_c_epsNetwkName_TextString(var) (&var)

/* DEFINITION OF BINARY c_epsNetwkName_TextString */
typedef struct _c_epsNetwkName_TextString {
	ED_BYTE* value; /* Variable size; bits needed 1992 */
	int usedBits;
} c_epsNetwkName_TextString;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_epsNetwkName_TextString(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_epsNetwkName {
	ED_LOCATOR CodingScheme___LOCATOR; /* QUI2 */
	ED_LOCATOR AddCI___LOCATOR; /* QUI2 */
	ED_LOCATOR SpareBitsInLastOctet___LOCATOR; /* QUI2 */
	ED_LOCATOR TextString___LOCATOR  /*LBD02*/;

	/*GBD01b*/
	ED_OCTET CodingScheme; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN AddCI; /* ODY01a *//*GBD01b*/
	ED_OCTET SpareBitsInLastOctet; /* ODY01a *//*GBD01b*/
	c_epsNetwkName_TextString TextString; /* Static, variable size; bits needed 1992 *//*GBD01b*/

}	c_epsNetwkName;
#define INIT_c_epsNetwkName(sp) ED_RESET_MEM ((sp), sizeof (c_epsNetwkName))
/*FRK03a*/
void FREE_c_epsNetwkName(c_epsNetwkName* sp);

/* Access member 'Year' of type 'c_epsTimeZoneAndTime' as a variable reference */
#define VAR_c_epsTimeZoneAndTime_Year(var) var

/* Access member 'Year' of type 'c_epsTimeZoneAndTime' as a pointer */
#define PTR_c_epsTimeZoneAndTime_Year(var) (&var)

/* Access member 'Month' of type 'c_epsTimeZoneAndTime' as a variable reference */
#define VAR_c_epsTimeZoneAndTime_Month(var) var

/* Access member 'Month' of type 'c_epsTimeZoneAndTime' as a pointer */
#define PTR_c_epsTimeZoneAndTime_Month(var) (&var)

/* Access member 'Day' of type 'c_epsTimeZoneAndTime' as a variable reference */
#define VAR_c_epsTimeZoneAndTime_Day(var) var

/* Access member 'Day' of type 'c_epsTimeZoneAndTime' as a pointer */
#define PTR_c_epsTimeZoneAndTime_Day(var) (&var)

/* Access member 'Hour' of type 'c_epsTimeZoneAndTime' as a variable reference */
#define VAR_c_epsTimeZoneAndTime_Hour(var) var

/* Access member 'Hour' of type 'c_epsTimeZoneAndTime' as a pointer */
#define PTR_c_epsTimeZoneAndTime_Hour(var) (&var)

/* Access member 'Minute' of type 'c_epsTimeZoneAndTime' as a variable reference */
#define VAR_c_epsTimeZoneAndTime_Minute(var) var

/* Access member 'Minute' of type 'c_epsTimeZoneAndTime' as a pointer */
#define PTR_c_epsTimeZoneAndTime_Minute(var) (&var)

/* Access member 'Second' of type 'c_epsTimeZoneAndTime' as a variable reference */
#define VAR_c_epsTimeZoneAndTime_Second(var) var

/* Access member 'Second' of type 'c_epsTimeZoneAndTime' as a pointer */
#define PTR_c_epsTimeZoneAndTime_Second(var) (&var)

/* Access member 'TimeZone' of type 'c_epsTimeZoneAndTime' as a variable reference */
#define VAR_c_epsTimeZoneAndTime_TimeZone(var) var

/* Access member 'TimeZone' of type 'c_epsTimeZoneAndTime' as a pointer */
#define PTR_c_epsTimeZoneAndTime_TimeZone(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsTimeZoneAndTime {
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

}	c_epsTimeZoneAndTime;
#define INIT_c_epsTimeZoneAndTime(sp) ED_RESET_MEM ((sp), sizeof (c_epsTimeZoneAndTime))
/*FRK03a*/
void FREE_c_epsTimeZoneAndTime(c_epsTimeZoneAndTime* sp);

/* Access member 'spare' of type 'c_epsDaylightSavingTime' as a variable reference */
#define VAR_c_epsDaylightSavingTime_spare(var) var

/* Access member 'spare' of type 'c_epsDaylightSavingTime' as a pointer */
#define PTR_c_epsDaylightSavingTime_spare(var) (&var)

/* Access member 'Value' of type 'c_epsDaylightSavingTime' as a variable reference */
#define VAR_c_epsDaylightSavingTime_Value(var) var

/* Access member 'Value' of type 'c_epsDaylightSavingTime' as a pointer */
#define PTR_c_epsDaylightSavingTime_Value(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsDaylightSavingTime {
	ED_LOCATOR Value___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_OCTET Value; /* ODY01a *//*GBD01b*/

}	c_epsDaylightSavingTime;
#define INIT_c_epsDaylightSavingTime(sp) ED_RESET_MEM ((sp), sizeof (c_epsDaylightSavingTime))
/*FRK03a*/
void FREE_c_epsDaylightSavingTime(c_epsDaylightSavingTime* sp);

/* Access member 'spare' of type 'c_epsTmsiStatus' as a variable reference */
#define VAR_c_epsTmsiStatus_spare(var) var

/* Access member 'spare' of type 'c_epsTmsiStatus' as a pointer */
#define PTR_c_epsTmsiStatus_spare(var) (&var)

/* Access member 'TMSIFlag' of type 'c_epsTmsiStatus' as a variable reference */
#define VAR_c_epsTmsiStatus_TMSIFlag(var) var

/* Access member 'TMSIFlag' of type 'c_epsTmsiStatus' as a pointer */
#define PTR_c_epsTmsiStatus_TMSIFlag(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsTmsiStatus {
	ED_LOCATOR TMSIFlag___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN TMSIFlag; /* ODY01a *//*GBD01b*/

}	c_epsTmsiStatus;
#define INIT_c_epsTmsiStatus(sp) ED_RESET_MEM ((sp), sizeof (c_epsTmsiStatus))
/*FRK03a*/
void FREE_c_epsTmsiStatus(c_epsTmsiStatus* sp);

/* Access member 'SplitPgCycleCode' of type 'c_epsDrxParam' as a variable reference */
#define VAR_c_epsDrxParam_SplitPgCycleCode(var) var

/* Access member 'SplitPgCycleCode' of type 'c_epsDrxParam' as a pointer */
#define PTR_c_epsDrxParam_SplitPgCycleCode(var) (&var)

/* Access member 'CNSpecDRX' of type 'c_epsDrxParam' as a variable reference */
#define VAR_c_epsDrxParam_CNSpecDRX(var) var

/* Access member 'CNSpecDRX' of type 'c_epsDrxParam' as a pointer */
#define PTR_c_epsDrxParam_CNSpecDRX(var) (&var)

/* Access member 'SplitOnCCCH' of type 'c_epsDrxParam' as a variable reference */
#define VAR_c_epsDrxParam_SplitOnCCCH(var) var

/* Access member 'SplitOnCCCH' of type 'c_epsDrxParam' as a pointer */
#define PTR_c_epsDrxParam_SplitOnCCCH(var) (&var)

/* Access member 'nonDRXTimer' of type 'c_epsDrxParam' as a variable reference */
#define VAR_c_epsDrxParam_nonDRXTimer(var) var

/* Access member 'nonDRXTimer' of type 'c_epsDrxParam' as a pointer */
#define PTR_c_epsDrxParam_nonDRXTimer(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsDrxParam {
	ED_LOCATOR SplitPgCycleCode___LOCATOR; /* QUI2 */
	ED_LOCATOR CNSpecDRX___LOCATOR; /* QUI2 */
	ED_LOCATOR SplitOnCCCH___LOCATOR; /* QUI2 */
	ED_LOCATOR nonDRXTimer___LOCATOR; /* QUI2 */

	ED_OCTET SplitPgCycleCode; /* ODY01a *//*GBD01b*/
	ED_OCTET CNSpecDRX; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SplitOnCCCH; /* ODY01a *//*GBD01b*/
	ED_OCTET nonDRXTimer; /* ODY01a *//*GBD01b*/

}	c_epsDrxParam;
#define INIT_c_epsDrxParam(sp) ED_RESET_MEM ((sp), sizeof (c_epsDrxParam))
/*FRK03a*/
void FREE_c_epsDrxParam(c_epsDrxParam* sp);

/* Access member 'spare' of type 'c_epsVoiceDomainPreferenceAndUEsUsageSetting' as a variable reference */
#define VAR_c_epsVoiceDomainPreferenceAndUEsUsageSetting_spare(var) var

/* Access member 'spare' of type 'c_epsVoiceDomainPreferenceAndUEsUsageSetting' as a pointer */
#define PTR_c_epsVoiceDomainPreferenceAndUEsUsageSetting_spare(var) (&var)

/* Access member 'UEUsageSetting' of type 'c_epsVoiceDomainPreferenceAndUEsUsageSetting' as a variable reference */
#define VAR_c_epsVoiceDomainPreferenceAndUEsUsageSetting_UEUsageSetting(var) var

/* Access member 'UEUsageSetting' of type 'c_epsVoiceDomainPreferenceAndUEsUsageSetting' as a pointer */
#define PTR_c_epsVoiceDomainPreferenceAndUEsUsageSetting_UEUsageSetting(var) (&var)

/* Access member 'VoiceDomainPreferenceForEUTRAN' of type 'c_epsVoiceDomainPreferenceAndUEsUsageSetting' as a variable reference */
#define VAR_c_epsVoiceDomainPreferenceAndUEsUsageSetting_VoiceDomainPreferenceForEUTRAN(var) var

/* Access member 'VoiceDomainPreferenceForEUTRAN' of type 'c_epsVoiceDomainPreferenceAndUEsUsageSetting' as a pointer */
#define PTR_c_epsVoiceDomainPreferenceAndUEsUsageSetting_VoiceDomainPreferenceForEUTRAN(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsVoiceDomainPreferenceAndUEsUsageSetting {
	ED_LOCATOR UEUsageSetting___LOCATOR; /* QUI2 */
	ED_LOCATOR VoiceDomainPreferenceForEUTRAN___LOCATOR; /* QUI2 */

	/*GBD01b*/
	ED_BOOLEAN UEUsageSetting; /* ODY01a *//*GBD01b*/
	ED_OCTET VoiceDomainPreferenceForEUTRAN; /* ODY01a *//*GBD01b*/

}	c_epsVoiceDomainPreferenceAndUEsUsageSetting;
#define INIT_c_epsVoiceDomainPreferenceAndUEsUsageSetting(sp) ED_RESET_MEM ((sp), sizeof (c_epsVoiceDomainPreferenceAndUEsUsageSetting))
/*FRK03a*/
void FREE_c_epsVoiceDomainPreferenceAndUEsUsageSetting(c_epsVoiceDomainPreferenceAndUEsUsageSetting* sp);

/* Access member 'NRIContainerValue' of type 'c_epsNetworkResourceIdentifierContainer' as a variable reference */
#define VAR_c_epsNetworkResourceIdentifierContainer_NRIContainerValue(var) var

/* Access member 'NRIContainerValue' of type 'c_epsNetworkResourceIdentifierContainer' as a pointer */
#define PTR_c_epsNetworkResourceIdentifierContainer_NRIContainerValue(var) (&var)

/* Access member 'spare' of type 'c_epsNetworkResourceIdentifierContainer' as a variable reference */
#define VAR_c_epsNetworkResourceIdentifierContainer_spare(var) var

/* Access member 'spare' of type 'c_epsNetworkResourceIdentifierContainer' as a pointer */
#define PTR_c_epsNetworkResourceIdentifierContainer_spare(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsNetworkResourceIdentifierContainer {
	ED_LOCATOR NRIContainerValue___LOCATOR; /* QUI2 */

	ED_SHORT NRIContainerValue; /* ODY01a *//*GBD01b*/
	/*GBD01b*/

}	c_epsNetworkResourceIdentifierContainer;
#define INIT_c_epsNetworkResourceIdentifierContainer(sp) ED_RESET_MEM ((sp), sizeof (c_epsNetworkResourceIdentifierContainer))
/*FRK03a*/
void FREE_c_epsNetworkResourceIdentifierContainer(c_epsNetworkResourceIdentifierContainer* sp);

/* Access member 'PagingTimeWindow' of type 'c_epsExtendedDRXParameters' as a variable reference */
#define VAR_c_epsExtendedDRXParameters_PagingTimeWindow(var) var

/* Access member 'PagingTimeWindow' of type 'c_epsExtendedDRXParameters' as a pointer */
#define PTR_c_epsExtendedDRXParameters_PagingTimeWindow(var) (&var)

/* Access member 'eDRX' of type 'c_epsExtendedDRXParameters' as a variable reference */
#define VAR_c_epsExtendedDRXParameters_eDRX(var) var

/* Access member 'eDRX' of type 'c_epsExtendedDRXParameters' as a pointer */
#define PTR_c_epsExtendedDRXParameters_eDRX(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsExtendedDRXParameters {
	ED_LOCATOR PagingTimeWindow___LOCATOR; /* QUI2 */
	ED_LOCATOR eDRX___LOCATOR; /* QUI2 */

	ED_OCTET PagingTimeWindow; /* ODY01a *//*GBD01b*/
	ED_OCTET eDRX; /* ODY01a *//*GBD01b*/

}	c_epsExtendedDRXParameters;
#define INIT_c_epsExtendedDRXParameters(sp) ED_RESET_MEM ((sp), sizeof (c_epsExtendedDRXParameters))
/*FRK03a*/
void FREE_c_epsExtendedDRXParameters(c_epsExtendedDRXParameters* sp);

/* Access member 'TimerValue' of type 'c_epsGprsTimer2' as a variable reference */
#define VAR_c_epsGprsTimer2_TimerValue(var) var

/* Access member 'TimerValue' of type 'c_epsGprsTimer2' as a pointer */
#define PTR_c_epsGprsTimer2_TimerValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsGprsTimer2 {
	ED_LOCATOR TimerValue___LOCATOR; /* QUI2 */

	ED_OCTET TimerValue; /* ODY01a *//*GBD01b*/

}	c_epsGprsTimer2;
#define INIT_c_epsGprsTimer2(sp) ED_RESET_MEM ((sp), sizeof (c_epsGprsTimer2))
/*FRK03a*/
void FREE_c_epsGprsTimer2(c_epsGprsTimer2* sp);

/* Access member 'TypeOfNumber' of type 'c_epsCallingPartyBcdNum' as a variable reference */
#define VAR_c_epsCallingPartyBcdNum_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_epsCallingPartyBcdNum' as a pointer */
#define PTR_c_epsCallingPartyBcdNum_TypeOfNumber(var) (&var)

/* Access member 'NumberingPlanIdent' of type 'c_epsCallingPartyBcdNum' as a variable reference */
#define VAR_c_epsCallingPartyBcdNum_NumberingPlanIdent(var) var

/* Access member 'NumberingPlanIdent' of type 'c_epsCallingPartyBcdNum' as a pointer */
#define PTR_c_epsCallingPartyBcdNum_NumberingPlanIdent(var) (&var)

/* Access member 'PresentationIndicator' of type 'c_epsCallingPartyBcdNum' as a variable reference */
#define VAR_c_epsCallingPartyBcdNum_PresentationIndicator(var) var

/* Access member 'PresentationIndicator' of type 'c_epsCallingPartyBcdNum' as a pointer */
#define PTR_c_epsCallingPartyBcdNum_PresentationIndicator(var) (&var)

/* Access member 'spare' of type 'c_epsCallingPartyBcdNum' as a variable reference */
#define VAR_c_epsCallingPartyBcdNum_spare(var) var

/* Access member 'spare' of type 'c_epsCallingPartyBcdNum' as a pointer */
#define PTR_c_epsCallingPartyBcdNum_spare(var) (&var)

/* Access member 'ScreeningIndicator' of type 'c_epsCallingPartyBcdNum' as a variable reference */
#define VAR_c_epsCallingPartyBcdNum_ScreeningIndicator(var) var

/* Access member 'ScreeningIndicator' of type 'c_epsCallingPartyBcdNum' as a pointer */
#define PTR_c_epsCallingPartyBcdNum_ScreeningIndicator(var) (&var)

/* Access member 'Number' of type 'c_epsCallingPartyBcdNum' as a variable reference */
#define VAR_c_epsCallingPartyBcdNum_Number(var) var

/* Access member 'Number' of type 'c_epsCallingPartyBcdNum' as a pointer */
#define PTR_c_epsCallingPartyBcdNum_Number(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsCallingPartyBcdNum {
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
	c_epsTBCDArray Number; /* ODY01a *//*GBD01b*/

}	c_epsCallingPartyBcdNum;
#define INIT_c_epsCallingPartyBcdNum(sp) ED_RESET_MEM ((sp), sizeof (c_epsCallingPartyBcdNum))
/*FRK03a*/
void FREE_c_epsCallingPartyBcdNum(c_epsCallingPartyBcdNum* sp);
#define SETPRESENT_c_epsCallingPartyBcdNum_PresentationIndicator(sp,present) (((sp)->PresentationIndicator_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsCallingPartyBcdNum_PresentationIndicator(sp) ((sp)->PresentationIndicator_Present)

/* Access member 'data' of type 'c_PartialTrackingAreaIdentityList' as a variable reference */
#define VAR_c_PartialTrackingAreaIdentityList_data(var) (*var)

/* Access member 'data' of type 'c_PartialTrackingAreaIdentityList' as a pointer */
#define PTR_c_PartialTrackingAreaIdentityList_data(var) var


/*-A----------------------------------*/
typedef struct _c_PartialTrackingAreaIdentityList {

		c_TrackingAreaIdentityList_Item **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_PartialTrackingAreaIdentityList;
#define INIT_c_PartialTrackingAreaIdentityList(sp) ED_RESET_MEM ((sp), sizeof (c_PartialTrackingAreaIdentityList))
/*FRK02b*/
void FREE_c_PartialTrackingAreaIdentityList (c_PartialTrackingAreaIdentityList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_PartialTrackingAreaIdentityList'. */
int SETITEMS_c_PartialTrackingAreaIdentityList (c_PartialTrackingAreaIdentityList* sequence, int desiredItems);
#define ADDITEMS_c_PartialTrackingAreaIdentityList(sequence, itemsToBeAdded) SETITEMS_c_PartialTrackingAreaIdentityList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'data' of type 'c_epsPlmnList' as a variable reference */
#define VAR_c_epsPlmnList_data(var) (*var)

/* Access member 'data' of type 'c_epsPlmnList' as a pointer */
#define PTR_c_epsPlmnList_data(var) var


/*-A----------------------------------*/
typedef struct _c_epsPlmnList {

		c_epsPlmn **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_epsPlmnList;
#define INIT_c_epsPlmnList(sp) ED_RESET_MEM ((sp), sizeof (c_epsPlmnList))
/*FRK02b*/
void FREE_c_epsPlmnList (c_epsPlmnList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_epsPlmnList'. */
int SETITEMS_c_epsPlmnList (c_epsPlmnList* sequence, int desiredItems);
#define ADDITEMS_c_epsPlmnList(sequence, itemsToBeAdded) SETITEMS_c_epsPlmnList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'data' of type 'c_epsEmergencyNumberList' as a variable reference */
#define VAR_c_epsEmergencyNumberList_data(var) (*var)

/* Access member 'data' of type 'c_epsEmergencyNumberList' as a pointer */
#define PTR_c_epsEmergencyNumberList_data(var) var


/*-A----------------------------------*/
typedef struct _c_epsEmergencyNumberList {

		c_epsTBCDEmergencyNumber **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_epsEmergencyNumberList;
#define INIT_c_epsEmergencyNumberList(sp) ED_RESET_MEM ((sp), sizeof (c_epsEmergencyNumberList))
/*FRK02b*/
void FREE_c_epsEmergencyNumberList (c_epsEmergencyNumberList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_epsEmergencyNumberList'. */
int SETITEMS_c_epsEmergencyNumberList (c_epsEmergencyNumberList* sequence, int desiredItems);
#define ADDITEMS_c_epsEmergencyNumberList(sequence, itemsToBeAdded) SETITEMS_c_epsEmergencyNumberList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'data' of type 'c_epsSupportedCodecList' as a variable reference */
#define VAR_c_epsSupportedCodecList_data(var) (*var)

/* Access member 'data' of type 'c_epsSupportedCodecList' as a pointer */
#define PTR_c_epsSupportedCodecList_data(var) var


/*-A----------------------------------*/
typedef struct _c_epsSupportedCodecList {

		c_epsSupportedCodec **data; /* NDY01 *//*GBD01b*//*AR01*/
		int allocatedItems; /*ALC*/
		int items; /*XYZ*/
		ED_LOCATOR* data___LOCATOR /* ARLC02 */;

}	c_epsSupportedCodecList;
#define INIT_c_epsSupportedCodecList(sp) ED_RESET_MEM ((sp), sizeof (c_epsSupportedCodecList))
/*FRK02b*/
void FREE_c_epsSupportedCodecList (c_epsSupportedCodecList* sp);
/* SETITEMS/ADDITEMS commands for type 'c_epsSupportedCodecList'. */
int SETITEMS_c_epsSupportedCodecList (c_epsSupportedCodecList* sequence, int desiredItems);
#define ADDITEMS_c_epsSupportedCodecList(sequence, itemsToBeAdded) SETITEMS_c_epsSupportedCodecList (sequence, (sequence)->items+itemsToBeAdded)


/* Access member 'p128_EEA0' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_p128_EEA0(var) var

/* Access member 'p128_EEA0' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_p128_EEA0(var) (&var)

/* Access member 'p128_EEA1' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_p128_EEA1(var) var

/* Access member 'p128_EEA1' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_p128_EEA1(var) (&var)

/* Access member 'p128_EEA2' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_p128_EEA2(var) var

/* Access member 'p128_EEA2' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_p128_EEA2(var) (&var)

/* Access member 'p128_EEA3' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_p128_EEA3(var) var

/* Access member 'p128_EEA3' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_p128_EEA3(var) (&var)

/* Access member 'EEA4' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EEA4(var) var

/* Access member 'EEA4' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EEA4(var) (&var)

/* Access member 'EEA5' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EEA5(var) var

/* Access member 'EEA5' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EEA5(var) (&var)

/* Access member 'EEA6' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EEA6(var) var

/* Access member 'EEA6' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EEA6(var) (&var)

/* Access member 'EEA7' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EEA7(var) var

/* Access member 'EEA7' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EEA7(var) (&var)

/* Access member 'EIA0' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EIA0(var) var

/* Access member 'EIA0' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EIA0(var) (&var)

/* Access member 'p128_EIA1' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_p128_EIA1(var) var

/* Access member 'p128_EIA1' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_p128_EIA1(var) (&var)

/* Access member 'p128_EIA2' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_p128_EIA2(var) var

/* Access member 'p128_EIA2' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_p128_EIA2(var) (&var)

/* Access member 'p128_EIA3' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_p128_EIA3(var) var

/* Access member 'p128_EIA3' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_p128_EIA3(var) (&var)

/* Access member 'EIA4' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EIA4(var) var

/* Access member 'EIA4' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EIA4(var) (&var)

/* Access member 'EIA5' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EIA5(var) var

/* Access member 'EIA5' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EIA5(var) (&var)

/* Access member 'EIA6' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EIA6(var) var

/* Access member 'EIA6' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EIA6(var) (&var)

/* Access member 'EIA7' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_EIA7(var) var

/* Access member 'EIA7' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_EIA7(var) (&var)

/* Access member 'UEA0' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA0(var) var

/* Access member 'UEA0' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA0(var) (&var)

/* Access member 'UEA1' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA1(var) var

/* Access member 'UEA1' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA1(var) (&var)

/* Access member 'UEA2' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA2(var) var

/* Access member 'UEA2' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA2(var) (&var)

/* Access member 'UEA3' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA3(var) var

/* Access member 'UEA3' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA3(var) (&var)

/* Access member 'UEA4' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA4(var) var

/* Access member 'UEA4' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA4(var) (&var)

/* Access member 'UEA5' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA5(var) var

/* Access member 'UEA5' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA5(var) (&var)

/* Access member 'UEA6' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA6(var) var

/* Access member 'UEA6' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA6(var) (&var)

/* Access member 'UEA7' of type 'c_UENetworkCapability_octet_5' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5_UEA7(var) var

/* Access member 'UEA7' of type 'c_UENetworkCapability_octet_5' as a pointer */
#define PTR_c_UENetworkCapability_octet_5_UEA7(var) (&var)

/* Access member 'octet_5' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_octet_5(var) (*var)

/* Access member 'octet_5' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_octet_5(var) var

/* Access member 'UCS2' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UCS2(var) var

/* Access member 'UCS2' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UCS2(var) (&var)

/* Access member 'UIA1' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UIA1(var) var

/* Access member 'UIA1' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UIA1(var) (&var)

/* Access member 'UIA2' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UIA2(var) var

/* Access member 'UIA2' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UIA2(var) (&var)

/* Access member 'UIA3' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UIA3(var) var

/* Access member 'UIA3' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UIA3(var) (&var)

/* Access member 'UIA4' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UIA4(var) var

/* Access member 'UIA4' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UIA4(var) (&var)

/* Access member 'UIA5' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UIA5(var) var

/* Access member 'UIA5' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UIA5(var) (&var)

/* Access member 'UIA6' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UIA6(var) var

/* Access member 'UIA6' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UIA6(var) (&var)

/* Access member 'UIA7' of type 'c_UENetworkCapability_octet_6' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6_UIA7(var) var

/* Access member 'UIA7' of type 'c_UENetworkCapability_octet_6' as a pointer */
#define PTR_c_UENetworkCapability_octet_6_UIA7(var) (&var)

/* Access member 'octet_6' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_octet_6(var) (*var)

/* Access member 'octet_6' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_octet_6(var) var

/* Access member 'H245_ASH' of type 'c_UENetworkCapability_octet_7' as a variable reference */
#define VAR_c_UENetworkCapability_octet_7_H245_ASH(var) var

/* Access member 'H245_ASH' of type 'c_UENetworkCapability_octet_7' as a pointer */
#define PTR_c_UENetworkCapability_octet_7_H245_ASH(var) (&var)

/* Access member 'ACC_CSFB' of type 'c_UENetworkCapability_octet_7' as a variable reference */
#define VAR_c_UENetworkCapability_octet_7_ACC_CSFB(var) var

/* Access member 'ACC_CSFB' of type 'c_UENetworkCapability_octet_7' as a pointer */
#define PTR_c_UENetworkCapability_octet_7_ACC_CSFB(var) (&var)

/* Access member 'LPP' of type 'c_UENetworkCapability_octet_7' as a variable reference */
#define VAR_c_UENetworkCapability_octet_7_LPP(var) var

/* Access member 'LPP' of type 'c_UENetworkCapability_octet_7' as a pointer */
#define PTR_c_UENetworkCapability_octet_7_LPP(var) (&var)

/* Access member 'LCS' of type 'c_UENetworkCapability_octet_7' as a variable reference */
#define VAR_c_UENetworkCapability_octet_7_LCS(var) var

/* Access member 'LCS' of type 'c_UENetworkCapability_octet_7' as a pointer */
#define PTR_c_UENetworkCapability_octet_7_LCS(var) (&var)

/* Access member 'p1xSR_VCC' of type 'c_UENetworkCapability_octet_7' as a variable reference */
#define VAR_c_UENetworkCapability_octet_7_p1xSR_VCC(var) var

/* Access member 'p1xSR_VCC' of type 'c_UENetworkCapability_octet_7' as a pointer */
#define PTR_c_UENetworkCapability_octet_7_p1xSR_VCC(var) (&var)

/* Access member 'ISR' of type 'c_UENetworkCapability_octet_7' as a variable reference */
#define VAR_c_UENetworkCapability_octet_7_ISR(var) var

/* Access member 'ISR' of type 'c_UENetworkCapability_octet_7' as a pointer */
#define PTR_c_UENetworkCapability_octet_7_ISR(var) (&var)

/* Access member 'octet_7' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_octet_7(var) (*var)

/* Access member 'octet_7' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_octet_7(var) var

/* Access member 'ePCO' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_ePCO(var) var

/* Access member 'ePCO' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_ePCO(var) (&var)

/* Access member 'HC_CP_CIoT' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_HC_CP_CIoT(var) var

/* Access member 'HC_CP_CIoT' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_HC_CP_CIoT(var) (&var)

/* Access member 'ERw_oPDN' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_ERw_oPDN(var) var

/* Access member 'ERw_oPDN' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_ERw_oPDN(var) (&var)

/* Access member 'S1_U_data' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_S1_U_data(var) var

/* Access member 'S1_U_data' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_S1_U_data(var) (&var)

/* Access member 'UP_CIoT' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_UP_CIoT(var) var

/* Access member 'UP_CIoT' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_UP_CIoT(var) (&var)

/* Access member 'CP_CIoT' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_CP_CIoT(var) var

/* Access member 'CP_CIoT' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_CP_CIoT(var) (&var)

/* Access member 'Prose_relay' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_Prose_relay(var) var

/* Access member 'Prose_relay' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_Prose_relay(var) (&var)

/* Access member 'ProSe_dc' of type 'c_UENetworkCapability_octet_8' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8_ProSe_dc(var) var

/* Access member 'ProSe_dc' of type 'c_UENetworkCapability_octet_8' as a pointer */
#define PTR_c_UENetworkCapability_octet_8_ProSe_dc(var) (&var)

/* Access member 'octet_8' of type 'c_UENetworkCapability' as a variable reference */
#define VAR_c_UENetworkCapability_octet_8(var) (*var)

/* Access member 'octet_8' of type 'c_UENetworkCapability' as a pointer */
#define PTR_c_UENetworkCapability_octet_8(var) var

/* DEFINITION OF SUB-STRUCTURE c_UENetworkCapability_octet_5 */
typedef struct _c_UENetworkCapability_octet_5 {
	ED_LOCATOR UEA0___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA1___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA2___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA3___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA4___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA5___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA6___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA7___LOCATOR; /* QUI2 */

	ED_BOOLEAN UEA0; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA7; /* ODY01a *//*GBD01b*/

} c_UENetworkCapability_octet_5;

/* DEFINITION OF SUB-STRUCTURE c_UENetworkCapability_octet_6 */
typedef struct _c_UENetworkCapability_octet_6 {
	ED_LOCATOR UCS2___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA1___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA2___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA3___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA4___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA5___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA6___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA7___LOCATOR; /* QUI2 */

	ED_BOOLEAN UCS2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA7; /* ODY01a *//*GBD01b*/

} c_UENetworkCapability_octet_6;

/* DEFINITION OF SUB-STRUCTURE c_UENetworkCapability_octet_7 */
typedef struct _c_UENetworkCapability_octet_7 {
	ED_LOCATOR H245_ASH___LOCATOR; /* QUI2 */
	ED_LOCATOR ACC_CSFB___LOCATOR; /* QUI2 */
	ED_LOCATOR LPP___LOCATOR; /* QUI2 */
	ED_LOCATOR LCS___LOCATOR; /* QUI2 */
	ED_LOCATOR p1xSR_VCC___LOCATOR; /* QUI2 */
	ED_LOCATOR ISR___LOCATOR; /* QUI2 */

	ED_BOOLEAN H245_ASH; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ACC_CSFB; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LPP; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LCS; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p1xSR_VCC; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ISR; /* ODY01a *//*GBD01b*/

} c_UENetworkCapability_octet_7;

/* DEFINITION OF SUB-STRUCTURE c_UENetworkCapability_octet_8 */
typedef struct _c_UENetworkCapability_octet_8 {
	ED_LOCATOR ePCO___LOCATOR; /* QUI2 */
	ED_LOCATOR HC_CP_CIoT___LOCATOR; /* QUI2 */
	ED_LOCATOR ERw_oPDN___LOCATOR; /* QUI2 */
	ED_LOCATOR S1_U_data___LOCATOR; /* QUI2 */
	ED_LOCATOR UP_CIoT___LOCATOR; /* QUI2 */
	ED_LOCATOR CP_CIoT___LOCATOR; /* QUI2 */
	ED_LOCATOR Prose_relay___LOCATOR; /* QUI2 */
	ED_LOCATOR ProSe_dc___LOCATOR; /* QUI2 */

	ED_BOOLEAN ePCO; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN HC_CP_CIoT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ERw_oPDN; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN S1_U_data; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UP_CIoT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CP_CIoT; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN Prose_relay; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ProSe_dc; /* ODY01a *//*GBD01b*/

} c_UENetworkCapability_octet_8;


/*-A----------------------------------*/
typedef struct _c_UENetworkCapability {
	ED_LOCATOR p128_EEA0___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EEA1___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EEA2___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EEA3___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA4___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA5___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA6___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA7___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA0___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EIA1___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EIA2___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EIA3___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA4___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA5___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA6___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA7___LOCATOR; /* QUI2 */

	ED_BOOLEAN p128_EEA0; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EEA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EEA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EEA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA0; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EIA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EIA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EIA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA7; /* ODY01a *//*GBD01b*/
	c_UENetworkCapability_octet_5 *octet_5; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN octet_5_Present;
	c_UENetworkCapability_octet_6 *octet_6; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN octet_6_Present;
	c_UENetworkCapability_octet_7 *octet_7; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN octet_7_Present;
	c_UENetworkCapability_octet_8 *octet_8; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN octet_8_Present;

}	c_UENetworkCapability;
#define INIT_c_UENetworkCapability(sp) ED_RESET_MEM ((sp), sizeof (c_UENetworkCapability))
/*FRK03a*/
void FREE_c_UENetworkCapability(c_UENetworkCapability* sp);
int SETPRESENT_c_UENetworkCapability_octet_5 (c_UENetworkCapability* sp, ED_BOOLEAN present);
#define GETPRESENT_c_UENetworkCapability_octet_5(sp) ((sp)->octet_5_Present)
int SETPRESENT_c_UENetworkCapability_octet_6 (c_UENetworkCapability* sp, ED_BOOLEAN present);
#define GETPRESENT_c_UENetworkCapability_octet_6(sp) ((sp)->octet_6_Present)
int SETPRESENT_c_UENetworkCapability_octet_7 (c_UENetworkCapability* sp, ED_BOOLEAN present);
#define GETPRESENT_c_UENetworkCapability_octet_7(sp) ((sp)->octet_7_Present)
int SETPRESENT_c_UENetworkCapability_octet_8 (c_UENetworkCapability* sp, ED_BOOLEAN present);
#define GETPRESENT_c_UENetworkCapability_octet_8(sp) ((sp)->octet_8_Present)

/* Access member 'p128_EEA0' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EEA0(var) var

/* Access member 'p128_EEA0' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EEA0(var) (&var)

/* Access member 'p128_EEA1' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EEA1(var) var

/* Access member 'p128_EEA1' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EEA1(var) (&var)

/* Access member 'p128_EEA2' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EEA2(var) var

/* Access member 'p128_EEA2' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EEA2(var) (&var)

/* Access member 'p128_EEA3' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EEA3(var) var

/* Access member 'p128_EEA3' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EEA3(var) (&var)

/* Access member 'EEA4' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EEA4(var) var

/* Access member 'EEA4' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EEA4(var) (&var)

/* Access member 'EEA5' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EEA5(var) var

/* Access member 'EEA5' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EEA5(var) (&var)

/* Access member 'EEA6' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EEA6(var) var

/* Access member 'EEA6' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EEA6(var) (&var)

/* Access member 'EEA7' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EEA7(var) var

/* Access member 'EEA7' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EEA7(var) (&var)

/* Access member 'p128_EIA0' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EIA0(var) var

/* Access member 'p128_EIA0' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EIA0(var) (&var)

/* Access member 'p128_EIA1' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EIA1(var) var

/* Access member 'p128_EIA1' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EIA1(var) (&var)

/* Access member 'p128_EIA2' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EIA2(var) var

/* Access member 'p128_EIA2' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EIA2(var) (&var)

/* Access member 'p128_EIA3' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_p128_EIA3(var) var

/* Access member 'p128_EIA3' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_p128_EIA3(var) (&var)

/* Access member 'EIA4' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EIA4(var) var

/* Access member 'EIA4' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EIA4(var) (&var)

/* Access member 'EIA5' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EIA5(var) var

/* Access member 'EIA5' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EIA5(var) (&var)

/* Access member 'EIA6' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EIA6(var) var

/* Access member 'EIA6' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EIA6(var) (&var)

/* Access member 'EIA7' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_EIA7(var) var

/* Access member 'EIA7' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_EIA7(var) (&var)

/* Access member 'UEA0' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA0(var) var

/* Access member 'UEA0' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA0(var) (&var)

/* Access member 'UEA1' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA1(var) var

/* Access member 'UEA1' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA1(var) (&var)

/* Access member 'UEA2' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA2(var) var

/* Access member 'UEA2' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA2(var) (&var)

/* Access member 'UEA3' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA3(var) var

/* Access member 'UEA3' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA3(var) (&var)

/* Access member 'UEA4' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA4(var) var

/* Access member 'UEA4' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA4(var) (&var)

/* Access member 'UEA5' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA5(var) var

/* Access member 'UEA5' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA5(var) (&var)

/* Access member 'UEA6' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA6(var) var

/* Access member 'UEA6' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA6(var) (&var)

/* Access member 'UEA7' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UEA7(var) var

/* Access member 'UEA7' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UEA7(var) (&var)

/* Access member 'UIA1' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UIA1(var) var

/* Access member 'UIA1' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UIA1(var) (&var)

/* Access member 'UIA2' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UIA2(var) var

/* Access member 'UIA2' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UIA2(var) (&var)

/* Access member 'UIA3' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UIA3(var) var

/* Access member 'UIA3' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UIA3(var) (&var)

/* Access member 'UIA4' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UIA4(var) var

/* Access member 'UIA4' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UIA4(var) (&var)

/* Access member 'UIA5' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UIA5(var) var

/* Access member 'UIA5' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UIA5(var) (&var)

/* Access member 'UIA6' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UIA6(var) var

/* Access member 'UIA6' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UIA6(var) (&var)

/* Access member 'UIA7' of type 'c_UESecurityCapability_UEA_UIA' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA_UIA7(var) var

/* Access member 'UIA7' of type 'c_UESecurityCapability_UEA_UIA' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA_UIA7(var) (&var)

/* Access member 'UEA_UIA' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_UEA_UIA(var) (*var)

/* Access member 'UEA_UIA' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_UEA_UIA(var) var

/* Access member 'GEA1' of type 'c_UESecurityCapability_GEA' as a variable reference */
#define VAR_c_UESecurityCapability_GEA_GEA1(var) var

/* Access member 'GEA1' of type 'c_UESecurityCapability_GEA' as a pointer */
#define PTR_c_UESecurityCapability_GEA_GEA1(var) (&var)

/* Access member 'GEA2' of type 'c_UESecurityCapability_GEA' as a variable reference */
#define VAR_c_UESecurityCapability_GEA_GEA2(var) var

/* Access member 'GEA2' of type 'c_UESecurityCapability_GEA' as a pointer */
#define PTR_c_UESecurityCapability_GEA_GEA2(var) (&var)

/* Access member 'GEA3' of type 'c_UESecurityCapability_GEA' as a variable reference */
#define VAR_c_UESecurityCapability_GEA_GEA3(var) var

/* Access member 'GEA3' of type 'c_UESecurityCapability_GEA' as a pointer */
#define PTR_c_UESecurityCapability_GEA_GEA3(var) (&var)

/* Access member 'GEA4' of type 'c_UESecurityCapability_GEA' as a variable reference */
#define VAR_c_UESecurityCapability_GEA_GEA4(var) var

/* Access member 'GEA4' of type 'c_UESecurityCapability_GEA' as a pointer */
#define PTR_c_UESecurityCapability_GEA_GEA4(var) (&var)

/* Access member 'GEA5' of type 'c_UESecurityCapability_GEA' as a variable reference */
#define VAR_c_UESecurityCapability_GEA_GEA5(var) var

/* Access member 'GEA5' of type 'c_UESecurityCapability_GEA' as a pointer */
#define PTR_c_UESecurityCapability_GEA_GEA5(var) (&var)

/* Access member 'GEA6' of type 'c_UESecurityCapability_GEA' as a variable reference */
#define VAR_c_UESecurityCapability_GEA_GEA6(var) var

/* Access member 'GEA6' of type 'c_UESecurityCapability_GEA' as a pointer */
#define PTR_c_UESecurityCapability_GEA_GEA6(var) (&var)

/* Access member 'GEA7' of type 'c_UESecurityCapability_GEA' as a variable reference */
#define VAR_c_UESecurityCapability_GEA_GEA7(var) var

/* Access member 'GEA7' of type 'c_UESecurityCapability_GEA' as a pointer */
#define PTR_c_UESecurityCapability_GEA_GEA7(var) (&var)

/* Access member 'GEA' of type 'c_UESecurityCapability' as a variable reference */
#define VAR_c_UESecurityCapability_GEA(var) (*var)

/* Access member 'GEA' of type 'c_UESecurityCapability' as a pointer */
#define PTR_c_UESecurityCapability_GEA(var) var

/* DEFINITION OF SUB-STRUCTURE c_UESecurityCapability_UEA_UIA */
typedef struct _c_UESecurityCapability_UEA_UIA {
	ED_LOCATOR UEA0___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA1___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA2___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA3___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA4___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA5___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA6___LOCATOR; /* QUI2 */
	ED_LOCATOR UEA7___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA1___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA2___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA3___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA4___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA5___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA6___LOCATOR; /* QUI2 */
	ED_LOCATOR UIA7___LOCATOR; /* QUI2 */

	ED_BOOLEAN UEA0; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UEA7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UIA7; /* ODY01a *//*GBD01b*/

} c_UESecurityCapability_UEA_UIA;

/* DEFINITION OF SUB-STRUCTURE c_UESecurityCapability_GEA */
typedef struct _c_UESecurityCapability_GEA {
	ED_LOCATOR GEA1___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA2___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA3___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA4___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA5___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA6___LOCATOR; /* QUI2 */
	ED_LOCATOR GEA7___LOCATOR; /* QUI2 */

	ED_BOOLEAN GEA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA7; /* ODY01a *//*GBD01b*/

} c_UESecurityCapability_GEA;


/*-A----------------------------------*/
typedef struct _c_UESecurityCapability {
	ED_LOCATOR p128_EEA0___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EEA1___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EEA2___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EEA3___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA4___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA5___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA6___LOCATOR; /* QUI2 */
	ED_LOCATOR EEA7___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EIA0___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EIA1___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EIA2___LOCATOR; /* QUI2 */
	ED_LOCATOR p128_EIA3___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA4___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA5___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA6___LOCATOR; /* QUI2 */
	ED_LOCATOR EIA7___LOCATOR; /* QUI2 */

	ED_BOOLEAN p128_EEA0; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EEA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EEA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EEA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EEA7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EIA0; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EIA1; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EIA2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN p128_EIA3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EIA7; /* ODY01a *//*GBD01b*/
	c_UESecurityCapability_UEA_UIA *UEA_UIA; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN UEA_UIA_Present;
	c_UESecurityCapability_GEA *GEA; /* ODY03 <> *//*GBD01b*/
	ED_BOOLEAN GEA_Present;

}	c_UESecurityCapability;
#define INIT_c_UESecurityCapability(sp) ED_RESET_MEM ((sp), sizeof (c_UESecurityCapability))
/*FRK03a*/
void FREE_c_UESecurityCapability(c_UESecurityCapability* sp);
int SETPRESENT_c_UESecurityCapability_UEA_UIA (c_UESecurityCapability* sp, ED_BOOLEAN present);
#define GETPRESENT_c_UESecurityCapability_UEA_UIA(sp) ((sp)->UEA_UIA_Present)
int SETPRESENT_c_UESecurityCapability_GEA (c_UESecurityCapability* sp, ED_BOOLEAN present);
#define GETPRESENT_c_UESecurityCapability_GEA(sp) ((sp)->GEA_Present)

/* Access member 'Multiband_supported' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Multiband_supported(var) var

/* Access member 'Multiband_supported' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Multiband_supported(var) (&var)

/* Access member 'A5_7' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_A5_7(var) var

/* Access member 'A5_7' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_A5_7(var) (&var)

/* Access member 'A5_6' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_A5_6(var) var

/* Access member 'A5_6' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_A5_6(var) (&var)

/* Access member 'A5_5' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_A5_5(var) var

/* Access member 'A5_5' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_A5_5(var) (&var)

/* Access member 'A5_4' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_A5_4(var) var

/* Access member 'A5_4' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_A5_4(var) (&var)

/* Access member 'Associated_Radio_Capability_2' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Associated_Radio_Capability_2(var) var

/* Access member 'Associated_Radio_Capability_2' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Associated_Radio_Capability_2(var) (&var)

/* Access member 'Associated_Radio_Capability_1' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Associated_Radio_Capability_1(var) var

/* Access member 'Associated_Radio_Capability_1' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Associated_Radio_Capability_1(var) (&var)

/* Access member 'R_GSM_band_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_R_GSM_band_Associated_Radio_Capability(var) var

/* Access member 'R_GSM_band_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_R_GSM_band_Associated_Radio_Capability(var) (&var)

/* Access member 'HSCSD_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_HSCSD_Multi_Slot_Class(var) var

/* Access member 'HSCSD_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_HSCSD_Multi_Slot_Class(var) (&var)

/* Access member 'UCS2_treatment' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_UCS2_treatment(var) var

/* Access member 'UCS2_treatment' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_UCS2_treatment(var) (&var)

/* Access member 'Extended_Measurement_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Extended_Measurement_Capability(var) var

/* Access member 'Extended_Measurement_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Extended_Measurement_Capability(var) (&var)

/* Access member 'SMS_VALUE' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_SMS_VALUE(var) var

/* Access member 'SMS_VALUE' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_SMS_VALUE(var) (&var)

/* Access member 'SM_VALUE' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_SM_VALUE(var) var

/* Access member 'SM_VALUE' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_SM_VALUE(var) (&var)

/* Access member 'MS_Positioning_Method' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_MS_Positioning_Method(var) var

/* Access member 'MS_Positioning_Method' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_MS_Positioning_Method(var) (&var)

/* Access member 'ECSD_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_ECSD_Multi_Slot_Class(var) var

/* Access member 'ECSD_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_ECSD_Multi_Slot_Class(var) (&var)

/* Access member 'Modulation_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Modulation_Capability(var) var

/* Access member 'Modulation_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Modulation_Capability(var) (&var)

/* Access member '_8_PSK_RF_Power_Capability_1' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value__8_PSK_RF_Power_Capability_1(var) var

/* Access member '_8_PSK_RF_Power_Capability_1' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value__8_PSK_RF_Power_Capability_1(var) (&var)

/* Access member '_8_PSK_RF_Power_Capability_2' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value__8_PSK_RF_Power_Capability_2(var) var

/* Access member '_8_PSK_RF_Power_Capability_2' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value__8_PSK_RF_Power_Capability_2(var) (&var)

/* Access member 'GSM_400_Bands_Supported' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GSM_400_Bands_Supported(var) var

/* Access member 'GSM_400_Bands_Supported' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GSM_400_Bands_Supported(var) (&var)

/* Access member 'GSM_400_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GSM_400_Associated_Radio_Capability(var) var

/* Access member 'GSM_400_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GSM_400_Associated_Radio_Capability(var) (&var)

/* Access member 'GSM_850_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GSM_850_Associated_Radio_Capability(var) var

/* Access member 'GSM_850_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GSM_850_Associated_Radio_Capability(var) (&var)

/* Access member 'GSM_1900_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GSM_1900_Associated_Radio_Capability(var) var

/* Access member 'GSM_1900_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GSM_1900_Associated_Radio_Capability(var) (&var)

/* Access member 'UMTS_FDD_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_FDD_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_UMTS_FDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_UMTS_3_84_Mcps_TDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'CDMA_2000_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability(var) var

/* Access member 'CDMA_2000_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_CDMA_2000_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'DTM_GPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class(var) var

/* Access member 'DTM_GPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Single_Slot_DTM' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Single_Slot_DTM(var) var

/* Access member 'Single_Slot_DTM' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Single_Slot_DTM(var) (&var)

/* Access member 'DTM_EGPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class(var) var

/* Access member 'DTM_EGPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class(var) (&var)

/* Access member 'GSM_Band' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GSM_Band(var) var

/* Access member 'GSM_Band' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GSM_Band(var) (&var)

/* Access member 'GSM_750_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GSM_750_Associated_Radio_Capability(var) var

/* Access member 'GSM_750_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GSM_750_Associated_Radio_Capability(var) (&var)

/* Access member 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(var) var

/* Access member 'UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(var) (&var)

/* Access member 'GERAN_Feature_Package_1' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GERAN_Feature_Package_1(var) var

/* Access member 'GERAN_Feature_Package_1' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GERAN_Feature_Package_1(var) (&var)

/* Access member 'Extended_DTM_GPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(var) var

/* Access member 'Extended_DTM_GPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(var) (&var)

/* Access member 'Extended_DTM_EGPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(var) var

/* Access member 'Extended_DTM_EGPRS_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(var) (&var)

/* Access member 'High_Multislot_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_High_Multislot_Capability(var) var

/* Access member 'High_Multislot_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_High_Multislot_Capability(var) (&var)

/* Access member 'Length' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Length(var) var

/* Access member 'Length' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Length(var) (&var)

/* Access member 'FLO_Iu_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_FLO_Iu_Capability(var) var

/* Access member 'FLO_Iu_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_FLO_Iu_Capability(var) (&var)

/* Access member 'GERAN_Feature_Package_2' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GERAN_Feature_Package_2(var) var

/* Access member 'GERAN_Feature_Package_2' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GERAN_Feature_Package_2(var) (&var)

/* Access member 'GMSK_Multislot_Power_Profile' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GMSK_Multislot_Power_Profile(var) var

/* Access member 'GMSK_Multislot_Power_Profile' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GMSK_Multislot_Power_Profile(var) (&var)

/* Access member '_8_PSK_Multislot_Power_Profile' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value__8_PSK_Multislot_Power_Profile(var) var

/* Access member '_8_PSK_Multislot_Power_Profile' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value__8_PSK_Multislot_Power_Profile(var) (&var)

/* Access member 'T_GSM_400_Bands_Supported' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_T_GSM_400_Bands_Supported(var) var

/* Access member 'T_GSM_400_Bands_Supported' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_T_GSM_400_Bands_Supported(var) (&var)

/* Access member 'T_GSM_400_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability(var) var

/* Access member 'T_GSM_400_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability(var) (&var)

/* Access member 'T_GSM_900_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability(var) var

/* Access member 'T_GSM_900_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability(var) (&var)

/* Access member 'Downlink_Advanced_Receiver_Performance' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Downlink_Advanced_Receiver_Performance(var) var

/* Access member 'Downlink_Advanced_Receiver_Performance' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Downlink_Advanced_Receiver_Performance(var) (&var)

/* Access member 'DTM_Enhancements_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_DTM_Enhancements_Capability(var) var

/* Access member 'DTM_Enhancements_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_DTM_Enhancements_Capability(var) (&var)

/* Access member 'DTM_GPRS_High_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class(var) var

/* Access member 'DTM_GPRS_High_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class(var) (&var)

/* Access member 'Offset_required' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Offset_required(var) var

/* Access member 'Offset_required' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Offset_required(var) (&var)

/* Access member 'DTM_EGPRS_High_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class(var) var

/* Access member 'DTM_EGPRS_High_Multi_Slot_Class' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class(var) (&var)

/* Access member 'Repeated_ACCH_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Repeated_ACCH_Capability(var) var

/* Access member 'Repeated_ACCH_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Repeated_ACCH_Capability(var) (&var)

/* Access member 'GSM_710_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GSM_710_Associated_Radio_Capability(var) var

/* Access member 'GSM_710_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GSM_710_Associated_Radio_Capability(var) (&var)

/* Access member 'T_GSM_810_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability(var) var

/* Access member 'T_GSM_810_Associated_Radio_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability(var) (&var)

/* Access member 'Ciphering_Mode_Setting_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Ciphering_Mode_Setting_Capability(var) var

/* Access member 'Ciphering_Mode_Setting_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Ciphering_Mode_Setting_Capability(var) (&var)

/* Access member 'Additional_Positioning_Capabilities' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Additional_Positioning_Capabilities(var) var

/* Access member 'Additional_Positioning_Capabilities' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Additional_Positioning_Capabilities(var) (&var)

/* Access member 'E_UTRA_FDD_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_E_UTRA_FDD_support(var) var

/* Access member 'E_UTRA_FDD_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_E_UTRA_FDD_support(var) (&var)

/* Access member 'E_UTRA_TDD_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_E_UTRA_TDD_support(var) var

/* Access member 'E_UTRA_TDD_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_E_UTRA_TDD_support(var) (&var)

/* Access member 'E_UTRA_Measurement_and_Reporting_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support(var) var

/* Access member 'E_UTRA_Measurement_and_Reporting_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support(var) (&var)

/* Access member 'Priority_based_reselection_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Priority_based_reselection_support(var) var

/* Access member 'Priority_based_reselection_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Priority_based_reselection_support(var) (&var)

/* Access member 'UTRA_CSG_Cells_Reporting' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_UTRA_CSG_Cells_Reporting(var) var

/* Access member 'UTRA_CSG_Cells_Reporting' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_UTRA_CSG_Cells_Reporting(var) (&var)

/* Access member 'VAMOS_Level' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_VAMOS_Level(var) var

/* Access member 'VAMOS_Level' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_VAMOS_Level(var) (&var)

/* Access member 'TIGHTER_Capability' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_TIGHTER_Capability(var) var

/* Access member 'TIGHTER_Capability' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_TIGHTER_Capability(var) (&var)

/* Access member 'Selective_Ciphering_of_Downlink_SACCH' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH(var) var

/* Access member 'Selective_Ciphering_of_Downlink_SACCH' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH(var) (&var)

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(var) var

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_UTRA' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(var) (&var)

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(var) var

/* Access member 'CS_to_PS_SRVCC_from_GERAN_to_E_UTRA' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(var) (&var)

/* Access member 'GERAN_Network_Sharing_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_GERAN_Network_Sharing_support(var) var

/* Access member 'GERAN_Network_Sharing_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_GERAN_Network_Sharing_support(var) (&var)

/* Access member 'E_UTRA_Wideband_RSRQ_measurements_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(var) var

/* Access member 'E_UTRA_Wideband_RSRQ_measurements_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(var) (&var)

/* Access member 'ER_Band_Support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_ER_Band_Support(var) var

/* Access member 'ER_Band_Support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_ER_Band_Support(var) (&var)

/* Access member 'UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(var) var

/* Access member 'UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(var) (&var)

/* Access member 'E_UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(var) var

/* Access member 'E_UTRA_Multiple_Frequency_Band_Indicators_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(var) (&var)

/* Access member 'Extended_TSC_Set_Capability_support' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Extended_TSC_Set_Capability_support(var) var

/* Access member 'Extended_TSC_Set_Capability_support' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Extended_TSC_Set_Capability_support(var) (&var)

/* Access member 'Extended_EARFCN_value_range' of type 'c_epsClassmark3Value' as a variable reference */
#define VAR_c_epsClassmark3Value_Extended_EARFCN_value_range(var) var

/* Access member 'Extended_EARFCN_value_range' of type 'c_epsClassmark3Value' as a pointer */
#define PTR_c_epsClassmark3Value_Extended_EARFCN_value_range(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsClassmark3Value {
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

}	c_epsClassmark3Value;
#define INIT_c_epsClassmark3Value(sp) ED_RESET_MEM ((sp), sizeof (c_epsClassmark3Value))
/*FRK03a*/
void FREE_c_epsClassmark3Value(c_epsClassmark3Value* sp);
#define SETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_2(sp,present) (((sp)->Associated_Radio_Capability_2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_2(sp) ((sp)->Associated_Radio_Capability_2_Present)
#define SETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_1(sp,present) (((sp)->Associated_Radio_Capability_1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Associated_Radio_Capability_1(sp) ((sp)->Associated_Radio_Capability_1_Present)
#define SETPRESENT_c_epsClassmark3Value_R_GSM_band_Associated_Radio_Capability(sp,present) (((sp)->R_GSM_band_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_R_GSM_band_Associated_Radio_Capability(sp) ((sp)->R_GSM_band_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_HSCSD_Multi_Slot_Class(sp,present) (((sp)->HSCSD_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_HSCSD_Multi_Slot_Class(sp) ((sp)->HSCSD_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_SMS_VALUE(sp,present) (((sp)->SMS_VALUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_SMS_VALUE(sp) ((sp)->SMS_VALUE_Present)
#define SETPRESENT_c_epsClassmark3Value_SM_VALUE(sp,present) (((sp)->SM_VALUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_SM_VALUE(sp) ((sp)->SM_VALUE_Present)
#define SETPRESENT_c_epsClassmark3Value_MS_Positioning_Method(sp,present) (((sp)->MS_Positioning_Method_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_MS_Positioning_Method(sp) ((sp)->MS_Positioning_Method_Present)
#define SETPRESENT_c_epsClassmark3Value_ECSD_Multi_Slot_Class(sp,present) (((sp)->ECSD_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_ECSD_Multi_Slot_Class(sp) ((sp)->ECSD_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_Modulation_Capability(sp,present) (((sp)->Modulation_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Modulation_Capability(sp) ((sp)->Modulation_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_1(sp,present) (((sp)->_8_PSK_RF_Power_Capability_1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_1(sp) ((sp)->_8_PSK_RF_Power_Capability_1_Present)
#define SETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_2(sp,present) (((sp)->_8_PSK_RF_Power_Capability_2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value__8_PSK_RF_Power_Capability_2(sp) ((sp)->_8_PSK_RF_Power_Capability_2_Present)
#define SETPRESENT_c_epsClassmark3Value_GSM_400_Bands_Supported(sp,present) (((sp)->GSM_400_Bands_Supported_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GSM_400_Bands_Supported(sp) ((sp)->GSM_400_Bands_Supported_Present)
#define SETPRESENT_c_epsClassmark3Value_GSM_400_Associated_Radio_Capability(sp,present) (((sp)->GSM_400_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GSM_400_Associated_Radio_Capability(sp) ((sp)->GSM_400_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_GSM_850_Associated_Radio_Capability(sp,present) (((sp)->GSM_850_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GSM_850_Associated_Radio_Capability(sp) ((sp)->GSM_850_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_GSM_1900_Associated_Radio_Capability(sp,present) (((sp)->GSM_1900_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GSM_1900_Associated_Radio_Capability(sp) ((sp)->GSM_1900_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class(sp,present) (((sp)->DTM_GPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_DTM_GPRS_Multi_Slot_Class(sp) ((sp)->DTM_GPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_Single_Slot_DTM(sp,present) (((sp)->Single_Slot_DTM_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Single_Slot_DTM(sp) ((sp)->Single_Slot_DTM_Present)
#define SETPRESENT_c_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class(sp,present) (((sp)->DTM_EGPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_DTM_EGPRS_Multi_Slot_Class(sp) ((sp)->DTM_EGPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_GSM_Band(sp,present) (((sp)->GSM_Band_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GSM_Band(sp) ((sp)->GSM_Band_Present)
#define SETPRESENT_c_epsClassmark3Value_GSM_750_Associated_Radio_Capability(sp,present) (((sp)->GSM_750_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GSM_750_Associated_Radio_Capability(sp) ((sp)->GSM_750_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(sp,present) (((sp)->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability(sp) ((sp)->UMTS_1_28_Mcps_TDD_Radio_Access_Technology_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_1(sp,present) (((sp)->GERAN_Feature_Package_1_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_1(sp) ((sp)->GERAN_Feature_Package_1_Present)
#define SETPRESENT_c_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(sp,present) (((sp)->Extended_DTM_GPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Extended_DTM_GPRS_Multi_Slot_Class(sp) ((sp)->Extended_DTM_GPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(sp,present) (((sp)->Extended_DTM_EGPRS_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Extended_DTM_EGPRS_Multi_Slot_Class(sp) ((sp)->Extended_DTM_EGPRS_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_High_Multislot_Capability(sp,present) (((sp)->High_Multislot_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_High_Multislot_Capability(sp) ((sp)->High_Multislot_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_Length(sp,present) (((sp)->Length_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Length(sp) ((sp)->Length_Present)
#define SETPRESENT_c_epsClassmark3Value_FLO_Iu_Capability(sp,present) (((sp)->FLO_Iu_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_FLO_Iu_Capability(sp) ((sp)->FLO_Iu_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_2(sp,present) (((sp)->GERAN_Feature_Package_2_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GERAN_Feature_Package_2(sp) ((sp)->GERAN_Feature_Package_2_Present)
#define SETPRESENT_c_epsClassmark3Value_GMSK_Multislot_Power_Profile(sp,present) (((sp)->GMSK_Multislot_Power_Profile_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GMSK_Multislot_Power_Profile(sp) ((sp)->GMSK_Multislot_Power_Profile_Present)
#define SETPRESENT_c_epsClassmark3Value__8_PSK_Multislot_Power_Profile(sp,present) (((sp)->_8_PSK_Multislot_Power_Profile_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value__8_PSK_Multislot_Power_Profile(sp) ((sp)->_8_PSK_Multislot_Power_Profile_Present)
#define SETPRESENT_c_epsClassmark3Value_T_GSM_400_Bands_Supported(sp,present) (((sp)->T_GSM_400_Bands_Supported_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_T_GSM_400_Bands_Supported(sp) ((sp)->T_GSM_400_Bands_Supported_Present)
#define SETPRESENT_c_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability(sp,present) (((sp)->T_GSM_400_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_T_GSM_400_Associated_Radio_Capability(sp) ((sp)->T_GSM_400_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability(sp,present) (((sp)->T_GSM_900_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_T_GSM_900_Associated_Radio_Capability(sp) ((sp)->T_GSM_900_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_Downlink_Advanced_Receiver_Performance(sp,present) (((sp)->Downlink_Advanced_Receiver_Performance_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Downlink_Advanced_Receiver_Performance(sp) ((sp)->Downlink_Advanced_Receiver_Performance_Present)
#define SETPRESENT_c_epsClassmark3Value_DTM_Enhancements_Capability(sp,present) (((sp)->DTM_Enhancements_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_DTM_Enhancements_Capability(sp) ((sp)->DTM_Enhancements_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class(sp,present) (((sp)->DTM_GPRS_High_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_DTM_GPRS_High_Multi_Slot_Class(sp) ((sp)->DTM_GPRS_High_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_Offset_required(sp,present) (((sp)->Offset_required_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Offset_required(sp) ((sp)->Offset_required_Present)
#define SETPRESENT_c_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class(sp,present) (((sp)->DTM_EGPRS_High_Multi_Slot_Class_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_DTM_EGPRS_High_Multi_Slot_Class(sp) ((sp)->DTM_EGPRS_High_Multi_Slot_Class_Present)
#define SETPRESENT_c_epsClassmark3Value_Repeated_ACCH_Capability(sp,present) (((sp)->Repeated_ACCH_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Repeated_ACCH_Capability(sp) ((sp)->Repeated_ACCH_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_GSM_710_Associated_Radio_Capability(sp,present) (((sp)->GSM_710_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GSM_710_Associated_Radio_Capability(sp) ((sp)->GSM_710_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability(sp,present) (((sp)->T_GSM_810_Associated_Radio_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_T_GSM_810_Associated_Radio_Capability(sp) ((sp)->T_GSM_810_Associated_Radio_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_Ciphering_Mode_Setting_Capability(sp,present) (((sp)->Ciphering_Mode_Setting_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Ciphering_Mode_Setting_Capability(sp) ((sp)->Ciphering_Mode_Setting_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_Additional_Positioning_Capabilities(sp,present) (((sp)->Additional_Positioning_Capabilities_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Additional_Positioning_Capabilities(sp) ((sp)->Additional_Positioning_Capabilities_Present)
#define SETPRESENT_c_epsClassmark3Value_E_UTRA_FDD_support(sp,present) (((sp)->E_UTRA_FDD_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_E_UTRA_FDD_support(sp) ((sp)->E_UTRA_FDD_support_Present)
#define SETPRESENT_c_epsClassmark3Value_E_UTRA_TDD_support(sp,present) (((sp)->E_UTRA_TDD_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_E_UTRA_TDD_support(sp) ((sp)->E_UTRA_TDD_support_Present)
#define SETPRESENT_c_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support(sp,present) (((sp)->E_UTRA_Measurement_and_Reporting_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_E_UTRA_Measurement_and_Reporting_support(sp) ((sp)->E_UTRA_Measurement_and_Reporting_support_Present)
#define SETPRESENT_c_epsClassmark3Value_Priority_based_reselection_support(sp,present) (((sp)->Priority_based_reselection_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Priority_based_reselection_support(sp) ((sp)->Priority_based_reselection_support_Present)
#define SETPRESENT_c_epsClassmark3Value_UTRA_CSG_Cells_Reporting(sp,present) (((sp)->UTRA_CSG_Cells_Reporting_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_UTRA_CSG_Cells_Reporting(sp) ((sp)->UTRA_CSG_Cells_Reporting_Present)
#define SETPRESENT_c_epsClassmark3Value_VAMOS_Level(sp,present) (((sp)->VAMOS_Level_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_VAMOS_Level(sp) ((sp)->VAMOS_Level_Present)
#define SETPRESENT_c_epsClassmark3Value_TIGHTER_Capability(sp,present) (((sp)->TIGHTER_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_TIGHTER_Capability(sp) ((sp)->TIGHTER_Capability_Present)
#define SETPRESENT_c_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH(sp,present) (((sp)->Selective_Ciphering_of_Downlink_SACCH_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Selective_Ciphering_of_Downlink_SACCH(sp) ((sp)->Selective_Ciphering_of_Downlink_SACCH_Present)
#define SETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(sp,present) (((sp)->CS_to_PS_SRVCC_from_GERAN_to_UTRA_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_UTRA(sp) ((sp)->CS_to_PS_SRVCC_from_GERAN_to_UTRA_Present)
#define SETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(sp,present) (((sp)->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_CS_to_PS_SRVCC_from_GERAN_to_E_UTRA(sp) ((sp)->CS_to_PS_SRVCC_from_GERAN_to_E_UTRA_Present)
#define SETPRESENT_c_epsClassmark3Value_GERAN_Network_Sharing_support(sp,present) (((sp)->GERAN_Network_Sharing_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_GERAN_Network_Sharing_support(sp) ((sp)->GERAN_Network_Sharing_support_Present)
#define SETPRESENT_c_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(sp,present) (((sp)->E_UTRA_Wideband_RSRQ_measurements_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_E_UTRA_Wideband_RSRQ_measurements_support(sp) ((sp)->E_UTRA_Wideband_RSRQ_measurements_support_Present)
#define SETPRESENT_c_epsClassmark3Value_ER_Band_Support(sp,present) (((sp)->ER_Band_Support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_ER_Band_Support(sp) ((sp)->ER_Band_Support_Present)
#define SETPRESENT_c_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(sp,present) (((sp)->UTRA_Multiple_Frequency_Band_Indicators_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_UTRA_Multiple_Frequency_Band_Indicators_support(sp) ((sp)->UTRA_Multiple_Frequency_Band_Indicators_support_Present)
#define SETPRESENT_c_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(sp,present) (((sp)->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_E_UTRA_Multiple_Frequency_Band_Indicators_support(sp) ((sp)->E_UTRA_Multiple_Frequency_Band_Indicators_support_Present)
#define SETPRESENT_c_epsClassmark3Value_Extended_TSC_Set_Capability_support(sp,present) (((sp)->Extended_TSC_Set_Capability_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Extended_TSC_Set_Capability_support(sp) ((sp)->Extended_TSC_Set_Capability_support_Present)
#define SETPRESENT_c_epsClassmark3Value_Extended_EARFCN_value_range(sp,present) (((sp)->Extended_EARFCN_value_range_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsClassmark3Value_Extended_EARFCN_value_range(sp) ((sp)->Extended_EARFCN_value_range_Present)

/* Access member 'GEA_1' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GEA_1(var) var

/* Access member 'GEA_1' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GEA_1(var) (&var)

/* Access member 'SM_capabilities_via_dedicated_channels' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_SM_capabilities_via_dedicated_channels(var) var

/* Access member 'SM_capabilities_via_dedicated_channels' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_SM_capabilities_via_dedicated_channels(var) (&var)

/* Access member 'SM_capabilities_via_GPRS_channels' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_SM_capabilities_via_GPRS_channels(var) var

/* Access member 'SM_capabilities_via_GPRS_channels' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_SM_capabilities_via_GPRS_channels(var) (&var)

/* Access member 'UCS2_support' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_UCS2_support(var) var

/* Access member 'UCS2_support' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_UCS2_support(var) (&var)

/* Access member 'SS_Screening_Indicator' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_SS_Screening_Indicator(var) var

/* Access member 'SS_Screening_Indicator' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_SS_Screening_Indicator(var) (&var)

/* Access member 'SoLSA_Capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_SoLSA_Capability(var) var

/* Access member 'SoLSA_Capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_SoLSA_Capability(var) (&var)

/* Access member 'Revision_level_indicator' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_Revision_level_indicator(var) var

/* Access member 'Revision_level_indicator' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_Revision_level_indicator(var) (&var)

/* Access member 'PFC_feature_mode' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_PFC_feature_mode(var) var

/* Access member 'PFC_feature_mode' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_PFC_feature_mode(var) (&var)

/* Access member 'GEA_2' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GEA_2(var) var

/* Access member 'GEA_2' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GEA_2(var) (&var)

/* Access member 'GEA_3' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GEA_3(var) var

/* Access member 'GEA_3' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GEA_3(var) (&var)

/* Access member 'GEA_4' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GEA_4(var) var

/* Access member 'GEA_4' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GEA_4(var) (&var)

/* Access member 'GEA_5' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GEA_5(var) var

/* Access member 'GEA_5' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GEA_5(var) (&var)

/* Access member 'GEA_6' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GEA_6(var) var

/* Access member 'GEA_6' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GEA_6(var) (&var)

/* Access member 'GEA_7' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GEA_7(var) var

/* Access member 'GEA_7' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GEA_7(var) (&var)

/* Access member 'LCS_VA_capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_LCS_VA_capability(var) var

/* Access member 'LCS_VA_capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_LCS_VA_capability(var) (&var)

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(var) var

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(var) (&var)

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(var) var

/* Access member 'PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(var) (&var)

/* Access member 'EMM_Combined_procedures_Capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_EMM_Combined_procedures_Capability(var) var

/* Access member 'EMM_Combined_procedures_Capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_EMM_Combined_procedures_Capability(var) (&var)

/* Access member 'ISR_support' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_ISR_support(var) var

/* Access member 'ISR_support' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_ISR_support(var) (&var)

/* Access member 'SRVCC_to_GERAN_UTRAN_capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(var) var

/* Access member 'SRVCC_to_GERAN_UTRAN_capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(var) (&var)

/* Access member 'EPC_capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_EPC_capability(var) var

/* Access member 'EPC_capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_EPC_capability(var) (&var)

/* Access member 'NF_capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_NF_capability(var) var

/* Access member 'NF_capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_NF_capability(var) (&var)

/* Access member 'GERAN_network_sharing_capability' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GERAN_network_sharing_capability(var) var

/* Access member 'GERAN_network_sharing_capability' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GERAN_network_sharing_capability(var) (&var)

/* Access member 'User_plane_integrity_protection_support' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_User_plane_integrity_protection_support(var) var

/* Access member 'User_plane_integrity_protection_support' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_User_plane_integrity_protection_support(var) (&var)

/* Access member 'GIA_4' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GIA_4(var) var

/* Access member 'GIA_4' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GIA_4(var) (&var)

/* Access member 'GIA_5' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GIA_5(var) var

/* Access member 'GIA_5' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GIA_5(var) (&var)

/* Access member 'GIA_6' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GIA_6(var) var

/* Access member 'GIA_6' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GIA_6(var) (&var)

/* Access member 'GIA_7' of type 'c_epsMsNetwkCpblty' as a variable reference */
#define VAR_c_epsMsNetwkCpblty_GIA_7(var) var

/* Access member 'GIA_7' of type 'c_epsMsNetwkCpblty' as a pointer */
#define PTR_c_epsMsNetwkCpblty_GIA_7(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsMsNetwkCpblty {
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
	ED_BOOLEAN GEA_2; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_3; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_4; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_5; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_6; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GEA_7; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LCS_VA_capability; /* ODY01a *//*GBD01b*/
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

}	c_epsMsNetwkCpblty;
#define INIT_c_epsMsNetwkCpblty(sp) ED_RESET_MEM ((sp), sizeof (c_epsMsNetwkCpblty))
/*FRK03a*/
void FREE_c_epsMsNetwkCpblty(c_epsMsNetwkCpblty* sp);
#define SETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(sp,present) (((sp)->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability(sp) ((sp)->PS_inter_RAT_HO_from_GERAN_to_UTRAN_Iu_mode_capability_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(sp,present) (((sp)->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability(sp) ((sp)->PS_inter_RAT_HO_from_GERAN_to_E_UTRAN_S1_mode_capability_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_EMM_Combined_procedures_Capability(sp,present) (((sp)->EMM_Combined_procedures_Capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_EMM_Combined_procedures_Capability(sp) ((sp)->EMM_Combined_procedures_Capability_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_ISR_support(sp,present) (((sp)->ISR_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_ISR_support(sp) ((sp)->ISR_support_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(sp,present) (((sp)->SRVCC_to_GERAN_UTRAN_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_SRVCC_to_GERAN_UTRAN_capability(sp) ((sp)->SRVCC_to_GERAN_UTRAN_capability_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_EPC_capability(sp,present) (((sp)->EPC_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_EPC_capability(sp) ((sp)->EPC_capability_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_NF_capability(sp,present) (((sp)->NF_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_NF_capability(sp) ((sp)->NF_capability_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_GERAN_network_sharing_capability(sp,present) (((sp)->GERAN_network_sharing_capability_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_GERAN_network_sharing_capability(sp) ((sp)->GERAN_network_sharing_capability_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_User_plane_integrity_protection_support(sp,present) (((sp)->User_plane_integrity_protection_support_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_User_plane_integrity_protection_support(sp) ((sp)->User_plane_integrity_protection_support_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_GIA_4(sp,present) (((sp)->GIA_4_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_GIA_4(sp) ((sp)->GIA_4_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_GIA_5(sp,present) (((sp)->GIA_5_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_GIA_5(sp) ((sp)->GIA_5_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_GIA_6(sp,present) (((sp)->GIA_6_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_GIA_6(sp) ((sp)->GIA_6_Present)
#define SETPRESENT_c_epsMsNetwkCpblty_GIA_7(sp,present) (((sp)->GIA_7_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_epsMsNetwkCpblty_GIA_7(sp) ((sp)->GIA_7_Present)

/* Access member 'IMSI' of type 'c_EPSMobileIdentity' as a variable reference */
#define VAR_c_EPSMobileIdentity_IMSI(var) (*var)

/* Access member 'IMSI' of type 'c_EPSMobileIdentity' as a pointer */
#define PTR_c_EPSMobileIdentity_IMSI(var) var

/* Access member 'GUTI' of type 'c_EPSMobileIdentity' as a variable reference */
#define VAR_c_EPSMobileIdentity_GUTI(var) (*var)

/* Access member 'GUTI' of type 'c_EPSMobileIdentity' as a pointer */
#define PTR_c_EPSMobileIdentity_GUTI(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_EPSMobileIdentity_NONE,
	U_c_EPSMobileIdentity_IMSI,
	U_c_EPSMobileIdentity_GUTI
} TPRESENT_c_EPSMobileIdentity;

typedef struct _c_EPSMobileIdentity {

		TPRESENT_c_EPSMobileIdentity Present;
		union {
			c_EPSMobileIdentity_IMSI *IMSI; /* ODY01 *//*GBD01b*/
		
			c_EPSMobileIdentity_GUTI *GUTI; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_EPSMobileIdentity;
#define INIT_c_EPSMobileIdentity(sp) ED_RESET_MEM ((sp), sizeof (c_EPSMobileIdentity))
/*FRK01a*/
void FREE_c_EPSMobileIdentity (c_EPSMobileIdentity* sp);

/* SETPRESENT commands for type 'c_EPSMobileIdentity' */
int GLOB_SETPRESENT_c_EPSMobileIdentity (c_EPSMobileIdentity* sp, TPRESENT_c_EPSMobileIdentity toBeSetPresent);
#define SETPRESENT_c_EPSMobileIdentity_NONE(sp) GLOB_SETPRESENT_c_EPSMobileIdentity(sp, U_c_EPSMobileIdentity_NONE)
#define GETPRESENT_c_EPSMobileIdentity_NONE(sp) ((sp)->Present == U_c_EPSMobileIdentity_NONE)
#define SETPRESENT_c_EPSMobileIdentity_IMSI(sp) GLOB_SETPRESENT_c_EPSMobileIdentity(sp, U_c_EPSMobileIdentity_IMSI)
#define GETPRESENT_c_EPSMobileIdentity_IMSI(sp) ((sp)->Present == U_c_EPSMobileIdentity_IMSI)
#define SETPRESENT_c_EPSMobileIdentity_GUTI(sp) GLOB_SETPRESENT_c_EPSMobileIdentity(sp, U_c_EPSMobileIdentity_GUTI)
#define GETPRESENT_c_EPSMobileIdentity_GUTI(sp) ((sp)->Present == U_c_EPSMobileIdentity_GUTI)
#define GETPRESENT_c_EPSMobileIdentity(sp) ((sp)->Present)


/* Access member 'pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT(var) (*var)

/* Access member 'pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT(var) var

/* Access member 'pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT(var) (*var)

/* Access member 'pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT(var) var

/* Access member 'pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT(var) (*var)

/* Access member 'pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT(var) var

/* Access member 'pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT(var) (*var)

/* Access member 'pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT(var) var

/* Access member 'pBEARER_RESOURCE_ALLOCATION_REQUEST' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST(var) (*var)

/* Access member 'pBEARER_RESOURCE_ALLOCATION_REQUEST' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST(var) var

/* Access member 'pBEARER_RESOURCE_MODIFICATION_REQUEST' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST(var) (*var)

/* Access member 'pBEARER_RESOURCE_MODIFICATION_REQUEST' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST(var) var

/* Access member 'pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT(var) (*var)

/* Access member 'pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT(var) var

/* Access member 'pESM_DATA_TRANSPORT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pESM_DATA_TRANSPORT(var) (*var)

/* Access member 'pESM_DATA_TRANSPORT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pESM_DATA_TRANSPORT(var) var

/* Access member 'pESM_DUMMY_MESSAGE' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pESM_DUMMY_MESSAGE(var) (*var)

/* Access member 'pESM_DUMMY_MESSAGE' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pESM_DUMMY_MESSAGE(var) var

/* Access member 'pESM_INFORMATION_RESPONSE' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pESM_INFORMATION_RESPONSE(var) (*var)

/* Access member 'pESM_INFORMATION_RESPONSE' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pESM_INFORMATION_RESPONSE(var) var

/* Access member 'pESM_STATUS' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pESM_STATUS(var) (*var)

/* Access member 'pESM_STATUS' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pESM_STATUS(var) var

/* Access member 'pMODIFY_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT(var) (*var)

/* Access member 'pMODIFY_EPS_BEARER_CONTEXT_ACCEPT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT(var) var

/* Access member 'pMODIFY_EPS_BEARER_CONTEXT_REJECT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT(var) (*var)

/* Access member 'pMODIFY_EPS_BEARER_CONTEXT_REJECT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT(var) var

/* Access member 'pPDN_CONNECTIVITY_REQUEST' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST(var) (*var)

/* Access member 'pPDN_CONNECTIVITY_REQUEST' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST(var) var

/* Access member 'pPDN_DISCONNECT_REQUEST' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST(var) (*var)

/* Access member 'pPDN_DISCONNECT_REQUEST' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST(var) var

/* Access member 'pREMOTE_UE_REPORT' of type 'c_ESMMessageUp' as a variable reference */
#define VAR_c_ESMMessageUp_pREMOTE_UE_REPORT(var) (*var)

/* Access member 'pREMOTE_UE_REPORT' of type 'c_ESMMessageUp' as a pointer */
#define PTR_c_ESMMessageUp_pREMOTE_UE_REPORT(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_ESMMessageUp_NONE,
	U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT,
	U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT,
	U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT,
	U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT,
	U_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST,
	U_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST,
	U_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT,
	U_c_ESMMessageUp_pESM_DATA_TRANSPORT,
	U_c_ESMMessageUp_pESM_DUMMY_MESSAGE,
	U_c_ESMMessageUp_pESM_INFORMATION_RESPONSE,
	U_c_ESMMessageUp_pESM_STATUS,
	U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT,
	U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT,
	U_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST,
	U_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST,
	U_c_ESMMessageUp_pREMOTE_UE_REPORT
} TPRESENT_c_ESMMessageUp;

typedef struct _c_ESMMessageUp {

		TPRESENT_c_ESMMessageUp Present;
		union {
			c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT *pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT; /* ODY01 *//*GBD01b*/
		
			c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT *pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT; /* ODY01 *//*GBD01b*/
		
			c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT *pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT; /* ODY01 *//*GBD01b*/
		
			c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT *pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT; /* ODY01 *//*GBD01b*/
		
			c_BEARER_RESOURCE_ALLOCATION_REQUEST *pBEARER_RESOURCE_ALLOCATION_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_BEARER_RESOURCE_MODIFICATION_REQUEST *pBEARER_RESOURCE_MODIFICATION_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_DEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT *pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT; /* ODY01 *//*GBD01b*/
		
			c_ESM_DATA_TRANSPORT *pESM_DATA_TRANSPORT; /* ODY01 *//*GBD01b*/
		
			c_ESM_DUMMY_MESSAGE *pESM_DUMMY_MESSAGE; /* ODY01 *//*GBD01b*/
		
			c_ESM_INFORMATION_RESPONSE *pESM_INFORMATION_RESPONSE; /* ODY01 *//*GBD01b*/
		
			c_ESM_STATUS *pESM_STATUS; /* ODY01 *//*GBD01b*/
		
			c_MODIFY_EPS_BEARER_CONTEXT_ACCEPT *pMODIFY_EPS_BEARER_CONTEXT_ACCEPT; /* ODY01 *//*GBD01b*/
		
			c_MODIFY_EPS_BEARER_CONTEXT_REJECT *pMODIFY_EPS_BEARER_CONTEXT_REJECT; /* ODY01 *//*GBD01b*/
		
			c_PDN_CONNECTIVITY_REQUEST *pPDN_CONNECTIVITY_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_PDN_DISCONNECT_REQUEST *pPDN_DISCONNECT_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_REMOTE_UE_REPORT *pREMOTE_UE_REPORT; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_ESMMessageUp;
#define INIT_c_ESMMessageUp(sp) ED_RESET_MEM ((sp), sizeof (c_ESMMessageUp))
/*FRK01a*/
void FREE_c_ESMMessageUp (c_ESMMessageUp* sp);

/* SETPRESENT commands for type 'c_ESMMessageUp' */
int GLOB_SETPRESENT_c_ESMMessageUp (c_ESMMessageUp* sp, TPRESENT_c_ESMMessageUp toBeSetPresent);
#define SETPRESENT_c_ESMMessageUp_NONE(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_NONE)
#define GETPRESENT_c_ESMMessageUp_NONE(sp) ((sp)->Present == U_c_ESMMessageUp_NONE)
#define SETPRESENT_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT)
#define GETPRESENT_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT(sp) ((sp)->Present == U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_ACCEPT)
#define SETPRESENT_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT)
#define GETPRESENT_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT(sp) ((sp)->Present == U_c_ESMMessageUp_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REJECT)
#define SETPRESENT_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT)
#define GETPRESENT_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT(sp) ((sp)->Present == U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_ACCEPT)
#define SETPRESENT_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT)
#define GETPRESENT_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT(sp) ((sp)->Present == U_c_ESMMessageUp_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REJECT)
#define SETPRESENT_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST)
#define GETPRESENT_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST(sp) ((sp)->Present == U_c_ESMMessageUp_pBEARER_RESOURCE_ALLOCATION_REQUEST)
#define SETPRESENT_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST)
#define GETPRESENT_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST(sp) ((sp)->Present == U_c_ESMMessageUp_pBEARER_RESOURCE_MODIFICATION_REQUEST)
#define SETPRESENT_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT)
#define GETPRESENT_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT(sp) ((sp)->Present == U_c_ESMMessageUp_pDEACTIVATE_EPS_BEARER_CONTEXT_ACCEPT)
#define SETPRESENT_c_ESMMessageUp_pESM_DATA_TRANSPORT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pESM_DATA_TRANSPORT)
#define GETPRESENT_c_ESMMessageUp_pESM_DATA_TRANSPORT(sp) ((sp)->Present == U_c_ESMMessageUp_pESM_DATA_TRANSPORT)
#define SETPRESENT_c_ESMMessageUp_pESM_DUMMY_MESSAGE(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pESM_DUMMY_MESSAGE)
#define GETPRESENT_c_ESMMessageUp_pESM_DUMMY_MESSAGE(sp) ((sp)->Present == U_c_ESMMessageUp_pESM_DUMMY_MESSAGE)
#define SETPRESENT_c_ESMMessageUp_pESM_INFORMATION_RESPONSE(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pESM_INFORMATION_RESPONSE)
#define GETPRESENT_c_ESMMessageUp_pESM_INFORMATION_RESPONSE(sp) ((sp)->Present == U_c_ESMMessageUp_pESM_INFORMATION_RESPONSE)
#define SETPRESENT_c_ESMMessageUp_pESM_STATUS(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pESM_STATUS)
#define GETPRESENT_c_ESMMessageUp_pESM_STATUS(sp) ((sp)->Present == U_c_ESMMessageUp_pESM_STATUS)
#define SETPRESENT_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT)
#define GETPRESENT_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT(sp) ((sp)->Present == U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_ACCEPT)
#define SETPRESENT_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT)
#define GETPRESENT_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT(sp) ((sp)->Present == U_c_ESMMessageUp_pMODIFY_EPS_BEARER_CONTEXT_REJECT)
#define SETPRESENT_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST)
#define GETPRESENT_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST(sp) ((sp)->Present == U_c_ESMMessageUp_pPDN_CONNECTIVITY_REQUEST)
#define SETPRESENT_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST)
#define GETPRESENT_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST(sp) ((sp)->Present == U_c_ESMMessageUp_pPDN_DISCONNECT_REQUEST)
#define SETPRESENT_c_ESMMessageUp_pREMOTE_UE_REPORT(sp) GLOB_SETPRESENT_c_ESMMessageUp(sp, U_c_ESMMessageUp_pREMOTE_UE_REPORT)
#define GETPRESENT_c_ESMMessageUp_pREMOTE_UE_REPORT(sp) ((sp)->Present == U_c_ESMMessageUp_pREMOTE_UE_REPORT)
#define GETPRESENT_c_ESMMessageUp(sp) ((sp)->Present)


/* Access member 'pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST(var) (*var)

/* Access member 'pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST(var) var

/* Access member 'pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST(var) (*var)

/* Access member 'pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST(var) var

/* Access member 'pBEARER_RESOURCE_ALLOCATION_REJECT' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT(var) (*var)

/* Access member 'pBEARER_RESOURCE_ALLOCATION_REJECT' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT(var) var

/* Access member 'pBEARER_RESOURCE_MODIFICATION_REJECT' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT(var) (*var)

/* Access member 'pBEARER_RESOURCE_MODIFICATION_REJECT' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT(var) var

/* Access member 'pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST(var) (*var)

/* Access member 'pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST(var) var

/* Access member 'pEPS_NOTIFICATION' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pEPS_NOTIFICATION(var) (*var)

/* Access member 'pEPS_NOTIFICATION' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pEPS_NOTIFICATION(var) var

/* Access member 'pESM_DATA_TRANSPORT' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pESM_DATA_TRANSPORT(var) (*var)

/* Access member 'pESM_DATA_TRANSPORT' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pESM_DATA_TRANSPORT(var) var

/* Access member 'pESM_DUMMY_MESSAGE' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pESM_DUMMY_MESSAGE(var) (*var)

/* Access member 'pESM_DUMMY_MESSAGE' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pESM_DUMMY_MESSAGE(var) var

/* Access member 'pESM_INFORMATION_REQUEST' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pESM_INFORMATION_REQUEST(var) (*var)

/* Access member 'pESM_INFORMATION_REQUEST' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pESM_INFORMATION_REQUEST(var) var

/* Access member 'pESM_STATUS' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pESM_STATUS(var) (*var)

/* Access member 'pESM_STATUS' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pESM_STATUS(var) var

/* Access member 'pMODIFY_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST(var) (*var)

/* Access member 'pMODIFY_EPS_BEARER_CONTEXT_REQUEST' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST(var) var

/* Access member 'pPDN_CONNECTIVITY_REJECT' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT(var) (*var)

/* Access member 'pPDN_CONNECTIVITY_REJECT' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT(var) var

/* Access member 'pPDN_DISCONNECT_REJECT' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pPDN_DISCONNECT_REJECT(var) (*var)

/* Access member 'pPDN_DISCONNECT_REJECT' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pPDN_DISCONNECT_REJECT(var) var

/* Access member 'pREMOTE_UE_REPORT_RESPONSE' of type 'c_ESMMessageDn' as a variable reference */
#define VAR_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE(var) (*var)

/* Access member 'pREMOTE_UE_REPORT_RESPONSE' of type 'c_ESMMessageDn' as a pointer */
#define PTR_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_ESMMessageDn_NONE,
	U_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST,
	U_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST,
	U_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT,
	U_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT,
	U_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST,
	U_c_ESMMessageDn_pEPS_NOTIFICATION,
	U_c_ESMMessageDn_pESM_DATA_TRANSPORT,
	U_c_ESMMessageDn_pESM_DUMMY_MESSAGE,
	U_c_ESMMessageDn_pESM_INFORMATION_REQUEST,
	U_c_ESMMessageDn_pESM_STATUS,
	U_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST,
	U_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT,
	U_c_ESMMessageDn_pPDN_DISCONNECT_REJECT,
	U_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE
} TPRESENT_c_ESMMessageDn;

typedef struct _c_ESMMessageDn {

		TPRESENT_c_ESMMessageDn Present;
		union {
			c_ACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST *pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_ACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST *pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_BEARER_RESOURCE_ALLOCATION_REJECT *pBEARER_RESOURCE_ALLOCATION_REJECT; /* ODY01 *//*GBD01b*/
		
			c_BEARER_RESOURCE_MODIFICATION_REJECT *pBEARER_RESOURCE_MODIFICATION_REJECT; /* ODY01 *//*GBD01b*/
		
			c_DEACTIVATE_EPS_BEARER_CONTEXT_REQUEST *pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_EPS_NOTIFICATION *pEPS_NOTIFICATION; /* ODY01 *//*GBD01b*/
		
			c_ESM_DATA_TRANSPORT *pESM_DATA_TRANSPORT; /* ODY01 *//*GBD01b*/
		
			c_ESM_DUMMY_MESSAGE *pESM_DUMMY_MESSAGE; /* ODY01 *//*GBD01b*/
		
			c_ESM_INFORMATION_REQUEST *pESM_INFORMATION_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_ESM_STATUS *pESM_STATUS; /* ODY01 *//*GBD01b*/
		
			c_MODIFY_EPS_BEARER_CONTEXT_REQUEST *pMODIFY_EPS_BEARER_CONTEXT_REQUEST; /* ODY01 *//*GBD01b*/
		
			c_PDN_CONNECTIVITY_REJECT *pPDN_CONNECTIVITY_REJECT; /* ODY01 *//*GBD01b*/
		
			c_PDN_DISCONNECT_REJECT *pPDN_DISCONNECT_REJECT; /* ODY01 *//*GBD01b*/
		
			c_REMOTE_UE_REPORT_RESPONSE *pREMOTE_UE_REPORT_RESPONSE; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_ESMMessageDn;
#define INIT_c_ESMMessageDn(sp) ED_RESET_MEM ((sp), sizeof (c_ESMMessageDn))
/*FRK01a*/
void FREE_c_ESMMessageDn (c_ESMMessageDn* sp);

/* SETPRESENT commands for type 'c_ESMMessageDn' */
int GLOB_SETPRESENT_c_ESMMessageDn (c_ESMMessageDn* sp, TPRESENT_c_ESMMessageDn toBeSetPresent);
#define SETPRESENT_c_ESMMessageDn_NONE(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_NONE)
#define GETPRESENT_c_ESMMessageDn_NONE(sp) ((sp)->Present == U_c_ESMMessageDn_NONE)
#define SETPRESENT_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST)
#define GETPRESENT_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST(sp) ((sp)->Present == U_c_ESMMessageDn_pACTIVATE_DEDICATED_EPS_BEARER_CONTEXT_REQUEST)
#define SETPRESENT_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST)
#define GETPRESENT_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST(sp) ((sp)->Present == U_c_ESMMessageDn_pACTIVATE_DEFAULT_EPS_BEARER_CONTEXT_REQUEST)
#define SETPRESENT_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT)
#define GETPRESENT_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT(sp) ((sp)->Present == U_c_ESMMessageDn_pBEARER_RESOURCE_ALLOCATION_REJECT)
#define SETPRESENT_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT)
#define GETPRESENT_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT(sp) ((sp)->Present == U_c_ESMMessageDn_pBEARER_RESOURCE_MODIFICATION_REJECT)
#define SETPRESENT_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST)
#define GETPRESENT_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST(sp) ((sp)->Present == U_c_ESMMessageDn_pDEACTIVATE_EPS_BEARER_CONTEXT_REQUEST)
#define SETPRESENT_c_ESMMessageDn_pEPS_NOTIFICATION(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pEPS_NOTIFICATION)
#define GETPRESENT_c_ESMMessageDn_pEPS_NOTIFICATION(sp) ((sp)->Present == U_c_ESMMessageDn_pEPS_NOTIFICATION)
#define SETPRESENT_c_ESMMessageDn_pESM_DATA_TRANSPORT(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pESM_DATA_TRANSPORT)
#define GETPRESENT_c_ESMMessageDn_pESM_DATA_TRANSPORT(sp) ((sp)->Present == U_c_ESMMessageDn_pESM_DATA_TRANSPORT)
#define SETPRESENT_c_ESMMessageDn_pESM_DUMMY_MESSAGE(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pESM_DUMMY_MESSAGE)
#define GETPRESENT_c_ESMMessageDn_pESM_DUMMY_MESSAGE(sp) ((sp)->Present == U_c_ESMMessageDn_pESM_DUMMY_MESSAGE)
#define SETPRESENT_c_ESMMessageDn_pESM_INFORMATION_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pESM_INFORMATION_REQUEST)
#define GETPRESENT_c_ESMMessageDn_pESM_INFORMATION_REQUEST(sp) ((sp)->Present == U_c_ESMMessageDn_pESM_INFORMATION_REQUEST)
#define SETPRESENT_c_ESMMessageDn_pESM_STATUS(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pESM_STATUS)
#define GETPRESENT_c_ESMMessageDn_pESM_STATUS(sp) ((sp)->Present == U_c_ESMMessageDn_pESM_STATUS)
#define SETPRESENT_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST)
#define GETPRESENT_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST(sp) ((sp)->Present == U_c_ESMMessageDn_pMODIFY_EPS_BEARER_CONTEXT_REQUEST)
#define SETPRESENT_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT)
#define GETPRESENT_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT(sp) ((sp)->Present == U_c_ESMMessageDn_pPDN_CONNECTIVITY_REJECT)
#define SETPRESENT_c_ESMMessageDn_pPDN_DISCONNECT_REJECT(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pPDN_DISCONNECT_REJECT)
#define GETPRESENT_c_ESMMessageDn_pPDN_DISCONNECT_REJECT(sp) ((sp)->Present == U_c_ESMMessageDn_pPDN_DISCONNECT_REJECT)
#define SETPRESENT_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE(sp) GLOB_SETPRESENT_c_ESMMessageDn(sp, U_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE)
#define GETPRESENT_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE(sp) ((sp)->Present == U_c_ESMMessageDn_pREMOTE_UE_REPORT_RESPONSE)
#define GETPRESENT_c_ESMMessageDn(sp) ((sp)->Present)


/* Access member 'Identity' of type 'c_epsMobileId' as a variable reference */
#define VAR_c_epsMobileId_Identity(var) (*var)

/* Access member 'Identity' of type 'c_epsMobileId' as a pointer */
#define PTR_c_epsMobileId_Identity(var) var

/* Access member 'TMGI' of type 'c_epsMobileId' as a variable reference */
#define VAR_c_epsMobileId_TMGI(var) (*var)

/* Access member 'TMGI' of type 'c_epsMobileId' as a pointer */
#define PTR_c_epsMobileId_TMGI(var) var


/*-A----------------------------------*/
typedef enum {
	U_c_epsMobileId_NONE,
	U_c_epsMobileId_Identity,
	U_c_epsMobileId_TMGI
} TPRESENT_c_epsMobileId;

typedef struct _c_epsMobileId {

		TPRESENT_c_epsMobileId Present;
		union {
			c_epsMobileId_Identity *Identity; /* ODY01 *//*GBD01b*/
		
			c_epsMobileId_TMGI *TMGI; /* ODY01 *//*GBD01b*/
		
		} u;

}	c_epsMobileId;
#define INIT_c_epsMobileId(sp) ED_RESET_MEM ((sp), sizeof (c_epsMobileId))
/*FRK01a*/
void FREE_c_epsMobileId (c_epsMobileId* sp);

/* SETPRESENT commands for type 'c_epsMobileId' */
int GLOB_SETPRESENT_c_epsMobileId (c_epsMobileId* sp, TPRESENT_c_epsMobileId toBeSetPresent);
#define SETPRESENT_c_epsMobileId_NONE(sp) GLOB_SETPRESENT_c_epsMobileId(sp, U_c_epsMobileId_NONE)
#define GETPRESENT_c_epsMobileId_NONE(sp) ((sp)->Present == U_c_epsMobileId_NONE)
#define SETPRESENT_c_epsMobileId_Identity(sp) GLOB_SETPRESENT_c_epsMobileId(sp, U_c_epsMobileId_Identity)
#define GETPRESENT_c_epsMobileId_Identity(sp) ((sp)->Present == U_c_epsMobileId_Identity)
#define SETPRESENT_c_epsMobileId_TMGI(sp) GLOB_SETPRESENT_c_epsMobileId(sp, U_c_epsMobileId_TMGI)
#define GETPRESENT_c_epsMobileId_TMGI(sp) ((sp)->Present == U_c_epsMobileId_TMGI)
#define GETPRESENT_c_epsMobileId(sp) ((sp)->Present)


/* Access member 'SecurityHeaderType' of type 'c_ATTACH_COMPLETE' as a variable reference */
#define VAR_c_ATTACH_COMPLETE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_ATTACH_COMPLETE' as a pointer */
#define PTR_c_ATTACH_COMPLETE_SecurityHeaderType(var) (&var)

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_COMPLETE' as a variable reference */
#define VAR_c_ATTACH_COMPLETE_ESMMessageContainer(var) var

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_COMPLETE' as a pointer */
#define PTR_c_ATTACH_COMPLETE_ESMMessageContainer(var) (&var)


/*-A----------------------------------*/
typedef struct _c_ATTACH_COMPLETE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_ESMMessageUp ESMMessageContainer; /* ODY01a *//*GBD01b*/

}	c_ATTACH_COMPLETE;
#define INIT_c_ATTACH_COMPLETE(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_COMPLETE))
/*FRK03a*/
void FREE_c_ATTACH_COMPLETE(c_ATTACH_COMPLETE* sp);

/* Access member 'SecurityHeaderType' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_SecurityHeaderType(var) (&var)

/* Access member 'EPSAttachType' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_EPSAttachType(var) var

/* Access member 'EPSAttachType' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_EPSAttachType(var) (&var)

/* Access member 'NASKeySetIdentifier' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_NASKeySetIdentifier(var) var

/* Access member 'NASKeySetIdentifier' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_NASKeySetIdentifier(var) (&var)

/* Access member 'EPSMobileIdentity' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_EPSMobileIdentity(var) var

/* Access member 'EPSMobileIdentity' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_EPSMobileIdentity(var) (&var)

/* Access member 'UENetworkCapability' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_UENetworkCapability(var) var

/* Access member 'UENetworkCapability' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_UENetworkCapability(var) (&var)

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_ESMMessageContainer(var) var

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_ESMMessageContainer(var) (&var)

/* Access member 'OldPTMSISignature' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_OldPTMSISignature(var) (*var)

/* Access member 'OldPTMSISignature' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_OldPTMSISignature(var) var

/* Access member 'AdditionalGUTI' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_AdditionalGUTI(var) (*var)

/* Access member 'AdditionalGUTI' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_AdditionalGUTI(var) var

/* Access member 'LastVisitedRegisteredTAI' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_LastVisitedRegisteredTAI(var) (*var)

/* Access member 'LastVisitedRegisteredTAI' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_LastVisitedRegisteredTAI(var) var

/* Access member 'DRXParameter' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_DRXParameter(var) (*var)

/* Access member 'DRXParameter' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_DRXParameter(var) var

/* Access member 'MSNetworkCapability' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_MSNetworkCapability(var) (*var)

/* Access member 'MSNetworkCapability' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_MSNetworkCapability(var) var

/* Access member 'OldLocationAreaIdentification' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_OldLocationAreaIdentification(var) (*var)

/* Access member 'OldLocationAreaIdentification' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_OldLocationAreaIdentification(var) var

/* Access member 'TMSIStatus' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_TMSIStatus(var) (*var)

/* Access member 'TMSIStatus' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_TMSIStatus(var) var

/* Access member 'epsMobileStationClassmark2' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_epsMobileStationClassmark2(var) (*var)

/* Access member 'epsMobileStationClassmark2' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_epsMobileStationClassmark2(var) var

/* Access member 'MobileStationClassmark3' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_MobileStationClassmark3(var) (*var)

/* Access member 'MobileStationClassmark3' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_MobileStationClassmark3(var) var

/* Access member 'SupportedCodecs' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_SupportedCodecs(var) var

/* Access member 'AdditionalUpdateType' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_AdditionalUpdateType(var) (*var)

/* Access member 'AdditionalUpdateType' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_AdditionalUpdateType(var) var

/* Access member 'VoiceDomainPref' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_VoiceDomainPref(var) (*var)

/* Access member 'VoiceDomainPref' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_VoiceDomainPref(var) var

/* Access member 'DeviceProperties' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_DeviceProperties(var) var

/* Access member 'OldGUTIType' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_OldGUTIType(var) (*var)

/* Access member 'OldGUTIType' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_OldGUTIType(var) var

/* Access member 'MSNetworkFeatureSupport' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_MSNetworkFeatureSupport(var) (*var)

/* Access member 'MSNetworkFeatureSupport' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_MSNetworkFeatureSupport(var) var

/* Access member 'TMSIBasedNRIContainer' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_TMSIBasedNRIContainer(var) (*var)

/* Access member 'TMSIBasedNRIContainer' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_TMSIBasedNRIContainer(var) var

/* Access member 'T3324ValueGPRSTimer2' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_T3324ValueGPRSTimer2(var) (*var)

/* Access member 'T3324ValueGPRSTimer2' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_T3324ValueGPRSTimer2(var) var

/* Access member 'T3412ExtendedValue' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_T3412ExtendedValue(var) (*var)

/* Access member 'T3412ExtendedValue' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_T3412ExtendedValue(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_REQUEST' as a variable reference */
#define VAR_c_ATTACH_REQUEST_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_REQUEST' as a pointer */
#define PTR_c_ATTACH_REQUEST_ExtendedDRXParameters(var) var


/*-A----------------------------------*/
typedef struct _c_ATTACH_REQUEST {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EPSAttachType___LOCATOR; /* QUI2 */
	ED_LOCATOR OldPTMSISignature___LOCATOR  /*LBD01*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EPSAttachType; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier NASKeySetIdentifier; /* ODY01a *//*GBD01b*/
	c_EPSMobileIdentity EPSMobileIdentity; /* ODY01a *//*GBD01b*/
	c_UENetworkCapability UENetworkCapability; /* ODY01a *//*GBD01b*/
	c_ESMMessageUp ESMMessageContainer; /* ODY01a *//*GBD01b*/
	ED_BYTE* OldPTMSISignature; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN OldPTMSISignature_Present;
	c_EPSMobileIdentity *AdditionalGUTI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalGUTI_Present;
	c_TrackingAreaIdentity *LastVisitedRegisteredTAI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN LastVisitedRegisteredTAI_Present;
	c_epsDrxParam *DRXParameter; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DRXParameter_Present;
	c_epsMsNetwkCpblty *MSNetworkCapability; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSNetworkCapability_Present;
	c_epsLocationAreaId *OldLocationAreaIdentification; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN OldLocationAreaIdentification_Present;
	c_epsTmsiStatus *TMSIStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TMSIStatus_Present;
	c_epsMobileStationClassmark2 *epsMobileStationClassmark2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN epsMobileStationClassmark2_Present;
	c_epsClassmark3Value *MobileStationClassmark3; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileStationClassmark3_Present;
	c_epsSupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;
	c_epsAdditionalUpdateType *AdditionalUpdateType; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateType_Present;
	c_epsVoiceDomainPreferenceAndUEsUsageSetting *VoiceDomainPref; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN VoiceDomainPref_Present;
	c_epsDeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_GUTIType *OldGUTIType; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN OldGUTIType_Present;
	c_epsMSNetworkFeatureSupport *MSNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSNetworkFeatureSupport_Present;
	c_epsNetworkResourceIdentifierContainer *TMSIBasedNRIContainer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TMSIBasedNRIContainer_Present;
	c_epsGprsTimer2 *T3324ValueGPRSTimer2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324ValueGPRSTimer2_Present;
	c_epsGprsTimer *T3412ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3412ExtendedValue_Present;
	c_epsExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;

}	c_ATTACH_REQUEST;
#define INIT_c_ATTACH_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_REQUEST))
/*FRK03a*/
void FREE_c_ATTACH_REQUEST(c_ATTACH_REQUEST* sp);
int SETPRESENT_c_ATTACH_REQUEST_OldPTMSISignature (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_OldPTMSISignature(sp) ((sp)->OldPTMSISignature_Present)
int SETPRESENT_c_ATTACH_REQUEST_AdditionalGUTI (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_AdditionalGUTI(sp) ((sp)->AdditionalGUTI_Present)
int SETPRESENT_c_ATTACH_REQUEST_LastVisitedRegisteredTAI (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_LastVisitedRegisteredTAI(sp) ((sp)->LastVisitedRegisteredTAI_Present)
int SETPRESENT_c_ATTACH_REQUEST_DRXParameter (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_DRXParameter(sp) ((sp)->DRXParameter_Present)
int SETPRESENT_c_ATTACH_REQUEST_MSNetworkCapability (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_MSNetworkCapability(sp) ((sp)->MSNetworkCapability_Present)
int SETPRESENT_c_ATTACH_REQUEST_OldLocationAreaIdentification (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_OldLocationAreaIdentification(sp) ((sp)->OldLocationAreaIdentification_Present)
int SETPRESENT_c_ATTACH_REQUEST_TMSIStatus (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_TMSIStatus(sp) ((sp)->TMSIStatus_Present)
int SETPRESENT_c_ATTACH_REQUEST_epsMobileStationClassmark2 (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_epsMobileStationClassmark2(sp) ((sp)->epsMobileStationClassmark2_Present)
int SETPRESENT_c_ATTACH_REQUEST_MobileStationClassmark3 (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_MobileStationClassmark3(sp) ((sp)->MobileStationClassmark3_Present)
int SETPRESENT_c_ATTACH_REQUEST_SupportedCodecs (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)
int SETPRESENT_c_ATTACH_REQUEST_AdditionalUpdateType (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_AdditionalUpdateType(sp) ((sp)->AdditionalUpdateType_Present)
int SETPRESENT_c_ATTACH_REQUEST_VoiceDomainPref (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_VoiceDomainPref(sp) ((sp)->VoiceDomainPref_Present)
int SETPRESENT_c_ATTACH_REQUEST_DeviceProperties (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_ATTACH_REQUEST_OldGUTIType (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_OldGUTIType(sp) ((sp)->OldGUTIType_Present)
int SETPRESENT_c_ATTACH_REQUEST_MSNetworkFeatureSupport (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_MSNetworkFeatureSupport(sp) ((sp)->MSNetworkFeatureSupport_Present)
int SETPRESENT_c_ATTACH_REQUEST_TMSIBasedNRIContainer (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_TMSIBasedNRIContainer(sp) ((sp)->TMSIBasedNRIContainer_Present)
int SETPRESENT_c_ATTACH_REQUEST_T3324ValueGPRSTimer2 (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_T3324ValueGPRSTimer2(sp) ((sp)->T3324ValueGPRSTimer2_Present)
int SETPRESENT_c_ATTACH_REQUEST_T3412ExtendedValue (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_T3412ExtendedValue(sp) ((sp)->T3412ExtendedValue_Present)
int SETPRESENT_c_ATTACH_REQUEST_ExtendedDRXParameters (c_ATTACH_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REQUEST_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_FAILURE' as a variable reference */
#define VAR_c_AUTHENTICATION_FAILURE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_FAILURE' as a pointer */
#define PTR_c_AUTHENTICATION_FAILURE_SecurityHeaderType(var) (&var)

/* Access member 'EMMCause' of type 'c_AUTHENTICATION_FAILURE' as a variable reference */
#define VAR_c_AUTHENTICATION_FAILURE_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_AUTHENTICATION_FAILURE' as a pointer */
#define PTR_c_AUTHENTICATION_FAILURE_EMMCause(var) (&var)

/* Access member 'AuthenticationFailureParameter' of type 'c_AUTHENTICATION_FAILURE' as a variable reference */
#define VAR_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter(var) (*var)

/* Access member 'AuthenticationFailureParameter' of type 'c_AUTHENTICATION_FAILURE' as a pointer */
#define PTR_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter(var) var


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_FAILURE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthenticationFailureParameter___LOCATOR  /*LBD01*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/
	ED_BYTE* AuthenticationFailureParameter; /* Dynamic, fixed size; bits needed: 112 ODY02a *//*GBD01b*/
	ED_BOOLEAN AuthenticationFailureParameter_Present;

}	c_AUTHENTICATION_FAILURE;
#define INIT_c_AUTHENTICATION_FAILURE(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_FAILURE))
/*FRK03a*/
void FREE_c_AUTHENTICATION_FAILURE(c_AUTHENTICATION_FAILURE* sp);
int SETPRESENT_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter (c_AUTHENTICATION_FAILURE* sp, ED_BOOLEAN present);
#define GETPRESENT_c_AUTHENTICATION_FAILURE_AuthenticationFailureParameter(sp) ((sp)->AuthenticationFailureParameter_Present)

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_RESPONSE' as a variable reference */
#define VAR_c_AUTHENTICATION_RESPONSE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_RESPONSE' as a pointer */
#define PTR_c_AUTHENTICATION_RESPONSE_SecurityHeaderType(var) (&var)

/* Access member 'AuthenticationResponseParameter' of type 'c_AUTHENTICATION_RESPONSE' as a variable reference */
#define VAR_c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter(var) var

/* Access member 'AuthenticationResponseParameter' of type 'c_AUTHENTICATION_RESPONSE' as a pointer */
#define PTR_c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter(var) (&var)

/* DEFINITION OF BINARY c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter */
typedef struct _c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter {
	ED_BYTE* value; /* Variable size; bits needed 128 */
	int usedBits;
} c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_RESPONSE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthenticationResponseParameter___LOCATOR  /*LBD02*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_AUTHENTICATION_RESPONSE_AuthenticationResponseParameter AuthenticationResponseParameter; /* Static, variable size; bits needed 128 *//*GBD01b*/

}	c_AUTHENTICATION_RESPONSE;
#define INIT_c_AUTHENTICATION_RESPONSE(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_RESPONSE))
/*FRK03a*/
void FREE_c_AUTHENTICATION_RESPONSE(c_AUTHENTICATION_RESPONSE* sp);

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_ACCEPT_UP' as a variable reference */
#define VAR_c_EPS_DETACH_ACCEPT_UP_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_ACCEPT_UP' as a pointer */
#define PTR_c_EPS_DETACH_ACCEPT_UP_SecurityHeaderType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPS_DETACH_ACCEPT_UP {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/

}	c_EPS_DETACH_ACCEPT_UP;
#define INIT_c_EPS_DETACH_ACCEPT_UP(sp) ED_RESET_MEM ((sp), sizeof (c_EPS_DETACH_ACCEPT_UP))
/*FRK03a*/
void FREE_c_EPS_DETACH_ACCEPT_UP(c_EPS_DETACH_ACCEPT_UP* sp);

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_UP_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_UP_SecurityHeaderType(var) (&var)

/* Access member 'DetachType' of type 'c_EPS_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_UP_DetachType(var) var

/* Access member 'DetachType' of type 'c_EPS_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_UP_DetachType(var) (&var)

/* Access member 'NASKeySetIdentifier' of type 'c_EPS_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_UP_NASKeySetIdentifier(var) var

/* Access member 'NASKeySetIdentifier' of type 'c_EPS_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_UP_NASKeySetIdentifier(var) (&var)

/* Access member 'EPSMobileIdentity' of type 'c_EPS_DETACH_REQUEST_UP' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_UP_EPSMobileIdentity(var) var

/* Access member 'EPSMobileIdentity' of type 'c_EPS_DETACH_REQUEST_UP' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_UP_EPSMobileIdentity(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPS_DETACH_REQUEST_UP {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_EPSDetachType DetachType; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier NASKeySetIdentifier; /* ODY01a *//*GBD01b*/
	c_EPSMobileIdentity EPSMobileIdentity; /* ODY01a *//*GBD01b*/

}	c_EPS_DETACH_REQUEST_UP;
#define INIT_c_EPS_DETACH_REQUEST_UP(sp) ED_RESET_MEM ((sp), sizeof (c_EPS_DETACH_REQUEST_UP))
/*FRK03a*/
void FREE_c_EPS_DETACH_REQUEST_UP(c_EPS_DETACH_REQUEST_UP* sp);

/* Access member 'SecurityHeaderType' of type 'c_EMM_STATUS' as a variable reference */
#define VAR_c_EMM_STATUS_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_EMM_STATUS' as a pointer */
#define PTR_c_EMM_STATUS_SecurityHeaderType(var) (&var)

/* Access member 'EMMCause' of type 'c_EMM_STATUS' as a variable reference */
#define VAR_c_EMM_STATUS_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_EMM_STATUS' as a pointer */
#define PTR_c_EMM_STATUS_EMMCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EMM_STATUS {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/

}	c_EMM_STATUS;
#define INIT_c_EMM_STATUS(sp) ED_RESET_MEM ((sp), sizeof (c_EMM_STATUS))
/*FRK03a*/
void FREE_c_EMM_STATUS(c_EMM_STATUS* sp);

/* Access member 'SecurityHeaderType' of type 'c_EXTENDED_SERVICE_REQUEST' as a variable reference */
#define VAR_c_EXTENDED_SERVICE_REQUEST_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_EXTENDED_SERVICE_REQUEST' as a pointer */
#define PTR_c_EXTENDED_SERVICE_REQUEST_SecurityHeaderType(var) (&var)

/* Access member 'ServiceType' of type 'c_EXTENDED_SERVICE_REQUEST' as a variable reference */
#define VAR_c_EXTENDED_SERVICE_REQUEST_ServiceType(var) var

/* Access member 'ServiceType' of type 'c_EXTENDED_SERVICE_REQUEST' as a pointer */
#define PTR_c_EXTENDED_SERVICE_REQUEST_ServiceType(var) (&var)

/* Access member 'NASKeySetIdentifier' of type 'c_EXTENDED_SERVICE_REQUEST' as a variable reference */
#define VAR_c_EXTENDED_SERVICE_REQUEST_NASKeySetIdentifier(var) var

/* Access member 'NASKeySetIdentifier' of type 'c_EXTENDED_SERVICE_REQUEST' as a pointer */
#define PTR_c_EXTENDED_SERVICE_REQUEST_NASKeySetIdentifier(var) (&var)

/* Access member 'MTMSI' of type 'c_EXTENDED_SERVICE_REQUEST' as a variable reference */
#define VAR_c_EXTENDED_SERVICE_REQUEST_MTMSI(var) var

/* Access member 'MTMSI' of type 'c_EXTENDED_SERVICE_REQUEST' as a pointer */
#define PTR_c_EXTENDED_SERVICE_REQUEST_MTMSI(var) (&var)

/* Access member 'CSFBResponse' of type 'c_EXTENDED_SERVICE_REQUEST' as a variable reference */
#define VAR_c_EXTENDED_SERVICE_REQUEST_CSFBResponse(var) var

/* Access member 'CSFBResponse' of type 'c_EXTENDED_SERVICE_REQUEST' as a pointer */
#define PTR_c_EXTENDED_SERVICE_REQUEST_CSFBResponse(var) (&var)

/* Access member 'EPSBearerContextStatus' of type 'c_EXTENDED_SERVICE_REQUEST' as a variable reference */
#define VAR_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus(var) (*var)

/* Access member 'EPSBearerContextStatus' of type 'c_EXTENDED_SERVICE_REQUEST' as a pointer */
#define PTR_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus(var) var

/* Access member 'DeviceProperties' of type 'c_EXTENDED_SERVICE_REQUEST' as a variable reference */
#define VAR_c_EXTENDED_SERVICE_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_EXTENDED_SERVICE_REQUEST' as a pointer */
#define PTR_c_EXTENDED_SERVICE_REQUEST_DeviceProperties(var) var


/*-A----------------------------------*/
typedef struct _c_EXTENDED_SERVICE_REQUEST {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR ServiceType___LOCATOR; /* QUI2 */
	ED_LOCATOR CSFBResponse___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET ServiceType; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier NASKeySetIdentifier; /* ODY01a *//*GBD01b*/
	c_epsMobileId MTMSI; /* ODY01a *//*GBD01b*/
	ED_OCTET CSFBResponse; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN CSFBResponse_Present;
	c_EPSBearerContextStatus *EPSBearerContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EPSBearerContextStatus_Present;
	c_epsDeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;

}	c_EXTENDED_SERVICE_REQUEST;
#define INIT_c_EXTENDED_SERVICE_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_EXTENDED_SERVICE_REQUEST))
/*FRK03a*/
void FREE_c_EXTENDED_SERVICE_REQUEST(c_EXTENDED_SERVICE_REQUEST* sp);
#define SETPRESENT_c_EXTENDED_SERVICE_REQUEST_CSFBResponse(sp,present) (((sp)->CSFBResponse_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_EXTENDED_SERVICE_REQUEST_CSFBResponse(sp) ((sp)->CSFBResponse_Present)
int SETPRESENT_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus (c_EXTENDED_SERVICE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EXTENDED_SERVICE_REQUEST_EPSBearerContextStatus(sp) ((sp)->EPSBearerContextStatus_Present)
int SETPRESENT_c_EXTENDED_SERVICE_REQUEST_DeviceProperties (c_EXTENDED_SERVICE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EXTENDED_SERVICE_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)

/* Access member 'SecurityHeaderType' of type 'c_GUTI_REALLOCATION_COMPLETE' as a variable reference */
#define VAR_c_GUTI_REALLOCATION_COMPLETE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_GUTI_REALLOCATION_COMPLETE' as a pointer */
#define PTR_c_GUTI_REALLOCATION_COMPLETE_SecurityHeaderType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_GUTI_REALLOCATION_COMPLETE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/

}	c_GUTI_REALLOCATION_COMPLETE;
#define INIT_c_GUTI_REALLOCATION_COMPLETE(sp) ED_RESET_MEM ((sp), sizeof (c_GUTI_REALLOCATION_COMPLETE))
/*FRK03a*/
void FREE_c_GUTI_REALLOCATION_COMPLETE(c_GUTI_REALLOCATION_COMPLETE* sp);

/* Access member 'SecurityHeaderType' of type 'c_IDENTITY_RESPONSE' as a variable reference */
#define VAR_c_IDENTITY_RESPONSE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_IDENTITY_RESPONSE' as a pointer */
#define PTR_c_IDENTITY_RESPONSE_SecurityHeaderType(var) (&var)

/* Access member 'MobileIdentity' of type 'c_IDENTITY_RESPONSE' as a variable reference */
#define VAR_c_IDENTITY_RESPONSE_MobileIdentity(var) var

/* Access member 'MobileIdentity' of type 'c_IDENTITY_RESPONSE' as a pointer */
#define PTR_c_IDENTITY_RESPONSE_MobileIdentity(var) (&var)


/*-A----------------------------------*/
typedef struct _c_IDENTITY_RESPONSE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_epsMobileId MobileIdentity; /* ODY01a *//*GBD01b*/

}	c_IDENTITY_RESPONSE;
#define INIT_c_IDENTITY_RESPONSE(sp) ED_RESET_MEM ((sp), sizeof (c_IDENTITY_RESPONSE))
/*FRK03a*/
void FREE_c_IDENTITY_RESPONSE(c_IDENTITY_RESPONSE* sp);

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_MODE_COMPLETE' as a variable reference */
#define VAR_c_SECURITY_MODE_COMPLETE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_MODE_COMPLETE' as a pointer */
#define PTR_c_SECURITY_MODE_COMPLETE_SecurityHeaderType(var) (&var)

/* Access member 'IMEISV' of type 'c_SECURITY_MODE_COMPLETE' as a variable reference */
#define VAR_c_SECURITY_MODE_COMPLETE_IMEISV(var) (*var)

/* Access member 'IMEISV' of type 'c_SECURITY_MODE_COMPLETE' as a pointer */
#define PTR_c_SECURITY_MODE_COMPLETE_IMEISV(var) var


/*-A----------------------------------*/
typedef struct _c_SECURITY_MODE_COMPLETE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_epsMobileId *IMEISV; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN IMEISV_Present;

}	c_SECURITY_MODE_COMPLETE;
#define INIT_c_SECURITY_MODE_COMPLETE(sp) ED_RESET_MEM ((sp), sizeof (c_SECURITY_MODE_COMPLETE))
/*FRK03a*/
void FREE_c_SECURITY_MODE_COMPLETE(c_SECURITY_MODE_COMPLETE* sp);
int SETPRESENT_c_SECURITY_MODE_COMPLETE_IMEISV (c_SECURITY_MODE_COMPLETE* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SECURITY_MODE_COMPLETE_IMEISV(sp) ((sp)->IMEISV_Present)

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_MODE_REJECT' as a variable reference */
#define VAR_c_SECURITY_MODE_REJECT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_MODE_REJECT' as a pointer */
#define PTR_c_SECURITY_MODE_REJECT_SecurityHeaderType(var) (&var)

/* Access member 'EMMCause' of type 'c_SECURITY_MODE_REJECT' as a variable reference */
#define VAR_c_SECURITY_MODE_REJECT_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_SECURITY_MODE_REJECT' as a pointer */
#define PTR_c_SECURITY_MODE_REJECT_EMMCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_SECURITY_MODE_REJECT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/

}	c_SECURITY_MODE_REJECT;
#define INIT_c_SECURITY_MODE_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_SECURITY_MODE_REJECT))
/*FRK03a*/
void FREE_c_SECURITY_MODE_REJECT(c_SECURITY_MODE_REJECT* sp);

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a variable reference */
#define VAR_c_SECURITY_PROTECTED_NAS_MESSAGE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a pointer */
#define PTR_c_SECURITY_PROTECTED_NAS_MESSAGE_SecurityHeaderType(var) (&var)

/* Access member 'MessageAuthenticationCode' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a variable reference */
#define VAR_c_SECURITY_PROTECTED_NAS_MESSAGE_MessageAuthenticationCode(var) var

/* Access member 'MessageAuthenticationCode' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a pointer */
#define PTR_c_SECURITY_PROTECTED_NAS_MESSAGE_MessageAuthenticationCode(var) (&var)

/* Access member 'SequenceNumber' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a variable reference */
#define VAR_c_SECURITY_PROTECTED_NAS_MESSAGE_SequenceNumber(var) var

/* Access member 'SequenceNumber' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a pointer */
#define PTR_c_SECURITY_PROTECTED_NAS_MESSAGE_SequenceNumber(var) (&var)

/* Access member 'NASMessage' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a variable reference */
#define VAR_c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage(var) var

/* Access member 'NASMessage' of type 'c_SECURITY_PROTECTED_NAS_MESSAGE' as a pointer */
#define PTR_c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage(var) (&var)

/* DEFINITION OF BINARY c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage */
typedef struct _c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage {
	ED_BYTE* value; /* Variable size; bits needed 4800 */
	int usedBits;
} c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_SECURITY_PROTECTED_NAS_MESSAGE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR MessageAuthenticationCode___LOCATOR  /*LBD02*/;
	ED_LOCATOR SequenceNumber___LOCATOR  /*LBD02*/;
	ED_LOCATOR NASMessage___LOCATOR  /*LBD02*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_BYTE MessageAuthenticationCode [4]; /* Static, fixed size; bits needed 32 *//*GBD01b*/
	ED_BYTE SequenceNumber [1]; /* Static, fixed size; bits needed 8 *//*GBD01b*/
	c_SECURITY_PROTECTED_NAS_MESSAGE_NASMessage NASMessage; /* Static, variable size; bits needed 4800 *//*GBD01b*/

}	c_SECURITY_PROTECTED_NAS_MESSAGE;
#define INIT_c_SECURITY_PROTECTED_NAS_MESSAGE(sp) ED_RESET_MEM ((sp), sizeof (c_SECURITY_PROTECTED_NAS_MESSAGE))
/*FRK03a*/
void FREE_c_SECURITY_PROTECTED_NAS_MESSAGE(c_SECURITY_PROTECTED_NAS_MESSAGE* sp);

/* Access member 'SecurityHeaderType' of type 'c_SERVICE_REQUEST' as a variable reference */
#define VAR_c_SERVICE_REQUEST_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_SERVICE_REQUEST' as a pointer */
#define PTR_c_SERVICE_REQUEST_SecurityHeaderType(var) (&var)

/* Access member 'KSIAndSequenceNumber' of type 'c_SERVICE_REQUEST' as a variable reference */
#define VAR_c_SERVICE_REQUEST_KSIAndSequenceNumber(var) var

/* Access member 'KSIAndSequenceNumber' of type 'c_SERVICE_REQUEST' as a pointer */
#define PTR_c_SERVICE_REQUEST_KSIAndSequenceNumber(var) (&var)

/* Access member 'MessageAuthenticationCodeShort' of type 'c_SERVICE_REQUEST' as a variable reference */
#define VAR_c_SERVICE_REQUEST_MessageAuthenticationCodeShort(var) var

/* Access member 'MessageAuthenticationCodeShort' of type 'c_SERVICE_REQUEST' as a pointer */
#define PTR_c_SERVICE_REQUEST_MessageAuthenticationCodeShort(var) (&var)


/*-A----------------------------------*/
typedef struct _c_SERVICE_REQUEST {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR MessageAuthenticationCodeShort___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_KSIAndSequenceNumber KSIAndSequenceNumber; /* ODY01a *//*GBD01b*/
	ED_SHORT MessageAuthenticationCodeShort; /* ODY01a *//*GBD01b*/

}	c_SERVICE_REQUEST;
#define INIT_c_SERVICE_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_SERVICE_REQUEST))
/*FRK03a*/
void FREE_c_SERVICE_REQUEST(c_SERVICE_REQUEST* sp);

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_COMPLETE' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_COMPLETE_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_COMPLETE' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_COMPLETE_SecurityHeaderType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_TRACKING_AREA_UPDATE_COMPLETE {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/

}	c_TRACKING_AREA_UPDATE_COMPLETE;
#define INIT_c_TRACKING_AREA_UPDATE_COMPLETE(sp) ED_RESET_MEM ((sp), sizeof (c_TRACKING_AREA_UPDATE_COMPLETE))
/*FRK03a*/
void FREE_c_TRACKING_AREA_UPDATE_COMPLETE(c_TRACKING_AREA_UPDATE_COMPLETE* sp);

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_SecurityHeaderType(var) (&var)

/* Access member 'EPSUpdateType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_EPSUpdateType(var) var

/* Access member 'EPSUpdateType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_EPSUpdateType(var) (&var)

/* Access member 'NASKeySetIdentifier' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_NASKeySetIdentifier(var) var

/* Access member 'NASKeySetIdentifier' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_NASKeySetIdentifier(var) (&var)

/* Access member 'OldGUTI' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTI(var) var

/* Access member 'OldGUTI' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTI(var) (&var)

/* Access member 'NonCurrentNativeNASKeySetId' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId(var) (*var)

/* Access member 'NonCurrentNativeNASKeySetId' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId(var) var

/* Access member 'GPRSCipheringKeySequenceNumber' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_GPRSCipheringKeySequenceNumber(var) var

/* Access member 'GPRSCipheringKeySequenceNumber' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_GPRSCipheringKeySequenceNumber(var) (&var)

/* Access member 'OldPTMSISignature' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature(var) (*var)

/* Access member 'OldPTMSISignature' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature(var) var

/* Access member 'AdditionalGUTI' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI(var) (*var)

/* Access member 'AdditionalGUTI' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI(var) var

/* Access member 'NonceUE' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_NonceUE(var) var

/* Access member 'NonceUE' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_NonceUE(var) (&var)

/* Access member 'UENetworkCapability' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability(var) (*var)

/* Access member 'UENetworkCapability' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability(var) var

/* Access member 'LastVisitedRegisteredTAI' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI(var) (*var)

/* Access member 'LastVisitedRegisteredTAI' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI(var) var

/* Access member 'DRXParameter' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter(var) (*var)

/* Access member 'DRXParameter' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter(var) var

/* Access member 'UERadioCapabilityInformationUpdateNeeded' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_UERadioCapabilityInformationUpdateNeeded(var) var

/* Access member 'UERadioCapabilityInformationUpdateNeeded' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_UERadioCapabilityInformationUpdateNeeded(var) (&var)

/* Access member 'EPSBearerContextStatus' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus(var) (*var)

/* Access member 'EPSBearerContextStatus' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus(var) var

/* Access member 'MSNetworkCapability' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability(var) (*var)

/* Access member 'MSNetworkCapability' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability(var) var

/* Access member 'OldLocationAreaIdentification' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification(var) (*var)

/* Access member 'OldLocationAreaIdentification' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification(var) var

/* Access member 'TMSIStatus' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus(var) (*var)

/* Access member 'TMSIStatus' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus(var) var

/* Access member 'epsMobileStationClassmark2' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2(var) (*var)

/* Access member 'epsMobileStationClassmark2' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2(var) var

/* Access member 'MobileStationClassmark3' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3(var) (*var)

/* Access member 'MobileStationClassmark3' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3(var) var

/* Access member 'SupportedCodecs' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs(var) (*var)

/* Access member 'SupportedCodecs' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs(var) var

/* Access member 'AdditionalUpdateType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType(var) (*var)

/* Access member 'AdditionalUpdateType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType(var) var

/* Access member 'VoiceDomainPref' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref(var) (*var)

/* Access member 'VoiceDomainPref' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref(var) var

/* Access member 'OldGUTIType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType(var) (*var)

/* Access member 'OldGUTIType' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType(var) var

/* Access member 'DeviceProperties' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties(var) var

/* Access member 'MSNetworkFeatureSupport' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport(var) (*var)

/* Access member 'MSNetworkFeatureSupport' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport(var) var

/* Access member 'TMSIBasedNRIContainer' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer(var) (*var)

/* Access member 'TMSIBasedNRIContainer' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer(var) var

/* Access member 'T3324ValueGPRSTimer2' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2(var) (*var)

/* Access member 'T3324ValueGPRSTimer2' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2(var) var

/* Access member 'T3412ExtendedValue' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue(var) (*var)

/* Access member 'T3412ExtendedValue' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_TRACKING_AREA_UPDATE_REQUEST' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters(var) var


/*-A----------------------------------*/
typedef struct _c_TRACKING_AREA_UPDATE_REQUEST {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR GPRSCipheringKeySequenceNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR OldPTMSISignature___LOCATOR  /*LBD01*/;
	ED_LOCATOR NonceUE___LOCATOR; /* QUI2 */
	ED_LOCATOR UERadioCapabilityInformationUpdateNeeded___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_EPSUpdateType EPSUpdateType; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier NASKeySetIdentifier; /* ODY01a *//*GBD01b*/
	c_EPSMobileIdentity OldGUTI; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier *NonCurrentNativeNASKeySetId; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NonCurrentNativeNASKeySetId_Present;
	ED_OCTET GPRSCipheringKeySequenceNumber; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN GPRSCipheringKeySequenceNumber_Present;
	ED_BYTE* OldPTMSISignature; /* Dynamic, fixed size; bits needed: 24 ODY02a *//*GBD01b*/
	ED_BOOLEAN OldPTMSISignature_Present;
	c_EPSMobileIdentity *AdditionalGUTI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalGUTI_Present;
	ED_LONG NonceUE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NonceUE_Present;
	c_UENetworkCapability *UENetworkCapability; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN UENetworkCapability_Present;
	c_TrackingAreaIdentity *LastVisitedRegisteredTAI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN LastVisitedRegisteredTAI_Present;
	c_epsDrxParam *DRXParameter; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DRXParameter_Present;
	ED_OCTET UERadioCapabilityInformationUpdateNeeded; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN UERadioCapabilityInformationUpdateNeeded_Present;
	c_EPSBearerContextStatus *EPSBearerContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EPSBearerContextStatus_Present;
	c_epsMsNetwkCpblty *MSNetworkCapability; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSNetworkCapability_Present;
	c_epsLocationAreaId *OldLocationAreaIdentification; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN OldLocationAreaIdentification_Present;
	c_epsTmsiStatus *TMSIStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TMSIStatus_Present;
	c_epsMobileStationClassmark2 *epsMobileStationClassmark2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN epsMobileStationClassmark2_Present;
	c_epsClassmark3Value *MobileStationClassmark3; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MobileStationClassmark3_Present;
	c_epsSupportedCodecList *SupportedCodecs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN SupportedCodecs_Present;
	c_epsAdditionalUpdateType *AdditionalUpdateType; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateType_Present;
	c_epsVoiceDomainPreferenceAndUEsUsageSetting *VoiceDomainPref; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN VoiceDomainPref_Present;
	c_GUTIType *OldGUTIType; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN OldGUTIType_Present;
	c_epsDeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;
	c_epsMSNetworkFeatureSupport *MSNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSNetworkFeatureSupport_Present;
	c_epsNetworkResourceIdentifierContainer *TMSIBasedNRIContainer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TMSIBasedNRIContainer_Present;
	c_epsGprsTimer2 *T3324ValueGPRSTimer2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324ValueGPRSTimer2_Present;
	c_epsGprsTimer *T3412ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3412ExtendedValue_Present;
	c_epsExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;

}	c_TRACKING_AREA_UPDATE_REQUEST;
#define INIT_c_TRACKING_AREA_UPDATE_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_TRACKING_AREA_UPDATE_REQUEST))
/*FRK03a*/
void FREE_c_TRACKING_AREA_UPDATE_REQUEST(c_TRACKING_AREA_UPDATE_REQUEST* sp);
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonCurrentNativeNASKeySetId(sp) ((sp)->NonCurrentNativeNASKeySetId_Present)
#define SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_GPRSCipheringKeySequenceNumber(sp,present) (((sp)->GPRSCipheringKeySequenceNumber_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_GPRSCipheringKeySequenceNumber(sp) ((sp)->GPRSCipheringKeySequenceNumber_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldPTMSISignature(sp) ((sp)->OldPTMSISignature_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalGUTI(sp) ((sp)->AdditionalGUTI_Present)
#define SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonceUE(sp,present) (((sp)->NonceUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_NonceUE(sp) ((sp)->NonceUE_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UENetworkCapability(sp) ((sp)->UENetworkCapability_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_LastVisitedRegisteredTAI(sp) ((sp)->LastVisitedRegisteredTAI_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DRXParameter(sp) ((sp)->DRXParameter_Present)
#define SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UERadioCapabilityInformationUpdateNeeded(sp,present) (((sp)->UERadioCapabilityInformationUpdateNeeded_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_UERadioCapabilityInformationUpdateNeeded(sp) ((sp)->UERadioCapabilityInformationUpdateNeeded_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_EPSBearerContextStatus(sp) ((sp)->EPSBearerContextStatus_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkCapability(sp) ((sp)->MSNetworkCapability_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldLocationAreaIdentification(sp) ((sp)->OldLocationAreaIdentification_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIStatus(sp) ((sp)->TMSIStatus_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2 (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_epsMobileStationClassmark2(sp) ((sp)->epsMobileStationClassmark2_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3 (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MobileStationClassmark3(sp) ((sp)->MobileStationClassmark3_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_SupportedCodecs(sp) ((sp)->SupportedCodecs_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_AdditionalUpdateType(sp) ((sp)->AdditionalUpdateType_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_VoiceDomainPref(sp) ((sp)->VoiceDomainPref_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_OldGUTIType(sp) ((sp)->OldGUTIType_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_MSNetworkFeatureSupport(sp) ((sp)->MSNetworkFeatureSupport_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_TMSIBasedNRIContainer(sp) ((sp)->TMSIBasedNRIContainer_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2 (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3324ValueGPRSTimer2(sp) ((sp)->T3324ValueGPRSTimer2_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_T3412ExtendedValue(sp) ((sp)->T3412ExtendedValue_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters (c_TRACKING_AREA_UPDATE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REQUEST_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)

/* Access member 'SecurityHeaderType' of type 'c_UPLINK_NAS_TRANSPORT' as a variable reference */
#define VAR_c_UPLINK_NAS_TRANSPORT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_UPLINK_NAS_TRANSPORT' as a pointer */
#define PTR_c_UPLINK_NAS_TRANSPORT_SecurityHeaderType(var) (&var)

/* Access member 'NASMessageContainer' of type 'c_UPLINK_NAS_TRANSPORT' as a variable reference */
#define VAR_c_UPLINK_NAS_TRANSPORT_NASMessageContainer(var) var

/* Access member 'NASMessageContainer' of type 'c_UPLINK_NAS_TRANSPORT' as a pointer */
#define PTR_c_UPLINK_NAS_TRANSPORT_NASMessageContainer(var) (&var)

/* DEFINITION OF BINARY c_UPLINK_NAS_TRANSPORT_NASMessageContainer */
typedef struct _c_UPLINK_NAS_TRANSPORT_NASMessageContainer {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_UPLINK_NAS_TRANSPORT_NASMessageContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_UPLINK_NAS_TRANSPORT_NASMessageContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_UPLINK_NAS_TRANSPORT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR NASMessageContainer___LOCATOR  /*LBD02*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_UPLINK_NAS_TRANSPORT_NASMessageContainer NASMessageContainer; /* Static, variable size; bits needed 2008 *//*GBD01b*/

}	c_UPLINK_NAS_TRANSPORT;
#define INIT_c_UPLINK_NAS_TRANSPORT(sp) ED_RESET_MEM ((sp), sizeof (c_UPLINK_NAS_TRANSPORT))
/*FRK03a*/
void FREE_c_UPLINK_NAS_TRANSPORT(c_UPLINK_NAS_TRANSPORT* sp);

/* Access member 'SecurityHeaderType' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_UPLINK_GENERIC_NAS_TRANSPORT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_UPLINK_GENERIC_NAS_TRANSPORT_SecurityHeaderType(var) (&var)

/* Access member 'NASMessageContainer' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer(var) var

/* Access member 'NASMessageContainer' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer(var) (&var)

/* Access member 'GenericMessageContainerType' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainerType(var) var

/* Access member 'GenericMessageContainerType' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainerType(var) (&var)

/* Access member 'GenericMessageContainer' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer(var) var

/* Access member 'GenericMessageContainer' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer(var) (&var)

/* Access member 'AdditionalInformation' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(var) (*var)

/* Access member 'AdditionalInformation' of type 'c_UPLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(var) var

/* DEFINITION OF BINARY c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer */
typedef struct _c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer */
typedef struct _c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation */
typedef struct _c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_UPLINK_GENERIC_NAS_TRANSPORT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR NASMessageContainer___LOCATOR  /*LBD02*/;
	ED_LOCATOR GenericMessageContainerType___LOCATOR; /* QUI2 */
	ED_LOCATOR GenericMessageContainer___LOCATOR  /*LBD02*/;
	ED_LOCATOR AdditionalInformation___LOCATOR  /*LBD01*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_UPLINK_GENERIC_NAS_TRANSPORT_NASMessageContainer NASMessageContainer; /* Static, variable size; bits needed 2008 *//*GBD01b*/
	ED_OCTET GenericMessageContainerType; /* ODY01a *//*GBD01b*/
	c_UPLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer GenericMessageContainer; /* Static, variable size; bits needed 4784 *//*GBD01b*/
	c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation* AdditionalInformation; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN AdditionalInformation_Present;

}	c_UPLINK_GENERIC_NAS_TRANSPORT;
#define INIT_c_UPLINK_GENERIC_NAS_TRANSPORT(sp) ED_RESET_MEM ((sp), sizeof (c_UPLINK_GENERIC_NAS_TRANSPORT))
/*FRK03a*/
void FREE_c_UPLINK_GENERIC_NAS_TRANSPORT(c_UPLINK_GENERIC_NAS_TRANSPORT* sp);
int SETPRESENT_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (c_UPLINK_GENERIC_NAS_TRANSPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_UPLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(sp) ((sp)->AdditionalInformation_Present)

/* Access member 'SecurityHeaderType' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a variable reference */
#define VAR_c_CONTROL_PLANE_SERVICE_REQUEST_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a pointer */
#define PTR_c_CONTROL_PLANE_SERVICE_REQUEST_SecurityHeaderType(var) (&var)

/* Access member 'DataServiceType' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a variable reference */
#define VAR_c_CONTROL_PLANE_SERVICE_REQUEST_DataServiceType(var) var

/* Access member 'DataServiceType' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a pointer */
#define PTR_c_CONTROL_PLANE_SERVICE_REQUEST_DataServiceType(var) (&var)

/* Access member 'NASKeySetIdentifier' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a variable reference */
#define VAR_c_CONTROL_PLANE_SERVICE_REQUEST_NASKeySetIdentifier(var) var

/* Access member 'NASKeySetIdentifier' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a pointer */
#define PTR_c_CONTROL_PLANE_SERVICE_REQUEST_NASKeySetIdentifier(var) (&var)

/* Access member 'ESMMessageContainer' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a variable reference */
#define VAR_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer(var) (*var)

/* Access member 'ESMMessageContainer' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a pointer */
#define PTR_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer(var) var

/* Access member 'NASMessageContainer' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a variable reference */
#define VAR_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer(var) (*var)

/* Access member 'NASMessageContainer' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a pointer */
#define PTR_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer(var) var

/* Access member 'EPSBearerContextStatus' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a variable reference */
#define VAR_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus(var) (*var)

/* Access member 'EPSBearerContextStatus' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a pointer */
#define PTR_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus(var) var

/* Access member 'DeviceProperties' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a variable reference */
#define VAR_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties(var) (*var)

/* Access member 'DeviceProperties' of type 'c_CONTROL_PLANE_SERVICE_REQUEST' as a pointer */
#define PTR_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties(var) var

/* DEFINITION OF BINARY c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer */
typedef struct _c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_CONTROL_PLANE_SERVICE_REQUEST {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR NASMessageContainer___LOCATOR  /*LBD01*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_DataServiceType DataServiceType; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier NASKeySetIdentifier; /* ODY01a *//*GBD01b*/
	c_ESMMessageUp *ESMMessageContainer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ESMMessageContainer_Present;
	c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer* NASMessageContainer; /* Dynamic, variable size; bits needed 2008 ODY02b *//*GBD01b*/
	ED_BOOLEAN NASMessageContainer_Present;
	c_EPSBearerContextStatus *EPSBearerContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EPSBearerContextStatus_Present;
	c_epsDeviceProperties *DeviceProperties; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN DeviceProperties_Present;

}	c_CONTROL_PLANE_SERVICE_REQUEST;
#define INIT_c_CONTROL_PLANE_SERVICE_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_CONTROL_PLANE_SERVICE_REQUEST))
/*FRK03a*/
void FREE_c_CONTROL_PLANE_SERVICE_REQUEST(c_CONTROL_PLANE_SERVICE_REQUEST* sp);
int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_ESMMessageContainer(sp) ((sp)->ESMMessageContainer_Present)
int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_NASMessageContainer(sp) ((sp)->NASMessageContainer_Present)
int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_EPSBearerContextStatus(sp) ((sp)->EPSBearerContextStatus_Present)
int SETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties (c_CONTROL_PLANE_SERVICE_REQUEST* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CONTROL_PLANE_SERVICE_REQUEST_DeviceProperties(sp) ((sp)->DeviceProperties_Present)

/* Access member 'SecurityHeaderType' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_SecurityHeaderType(var) (&var)

/* Access member 'EPSAttachResult' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_EPSAttachResult(var) var

/* Access member 'EPSAttachResult' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_EPSAttachResult(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_SpareHalfOctet(var) (&var)

/* Access member 'T3412Value' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_T3412Value(var) var

/* Access member 'T3412Value' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_T3412Value(var) (&var)

/* Access member 'TAIList' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_TAIList(var) var

/* Access member 'TAIList' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_TAIList(var) (&var)

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_ESMMessageContainer(var) var

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_ESMMessageContainer(var) (&var)

/* Access member 'GUTI' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_GUTI(var) (*var)

/* Access member 'GUTI' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_GUTI(var) var

/* Access member 'LocationAreaIdentification' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_LocationAreaIdentification(var) (*var)

/* Access member 'LocationAreaIdentification' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_LocationAreaIdentification(var) var

/* Access member 'MSIdentity' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_MSIdentity(var) (*var)

/* Access member 'MSIdentity' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_MSIdentity(var) var

/* Access member 'EMMCause' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_EMMCause(var) (&var)

/* Access member 'T3402Value' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_T3402Value(var) (*var)

/* Access member 'T3402Value' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_T3402Value(var) var

/* Access member 'T3423Value' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_T3423Value(var) (*var)

/* Access member 'T3423Value' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_T3423Value(var) var

/* Access member 'EquivalentPLMNs' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_EquivalentPLMNs(var) (*var)

/* Access member 'EquivalentPLMNs' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_EquivalentPLMNs(var) var

/* Access member 'epsEmergencyNumberList' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_epsEmergencyNumberList(var) (*var)

/* Access member 'epsEmergencyNumberList' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_epsEmergencyNumberList(var) var

/* Access member 'EPSNetworkFeatureSupport' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport(var) (*var)

/* Access member 'EPSNetworkFeatureSupport' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport(var) var

/* Access member 'AdditionalUpdateResult' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_AdditionalUpdateResult(var) (*var)

/* Access member 'AdditionalUpdateResult' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_AdditionalUpdateResult(var) var

/* Access member 'T3412ExtendedValue' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_T3412ExtendedValue(var) (*var)

/* Access member 'T3412ExtendedValue' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_T3412ExtendedValue(var) var

/* Access member 'T3324ValueGPRSTimer2' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2(var) (*var)

/* Access member 'T3324ValueGPRSTimer2' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_ACCEPT' as a variable reference */
#define VAR_c_ATTACH_ACCEPT_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_ATTACH_ACCEPT' as a pointer */
#define PTR_c_ATTACH_ACCEPT_ExtendedDRXParameters(var) var


/*-A----------------------------------*/
typedef struct _c_ATTACH_ACCEPT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EPSAttachResult___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EPSAttachResult; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_epsGprsTimer T3412Value; /* ODY01a *//*GBD01b*/
	c_PartialTrackingAreaIdentityList TAIList; /* ODY01a *//*GBD01b*/
	c_ESMMessageDn ESMMessageContainer; /* ODY01a *//*GBD01b*/
	c_EPSMobileIdentity *GUTI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN GUTI_Present;
	c_epsLocationAreaId *LocationAreaIdentification; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN LocationAreaIdentification_Present;
	c_epsMobileId *MSIdentity; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSIdentity_Present;
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMMCause_Present;
	c_epsGprsTimer *T3402Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3402Value_Present;
	c_epsGprsTimer *T3423Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3423Value_Present;
	c_epsPlmnList *EquivalentPLMNs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EquivalentPLMNs_Present;
	c_epsEmergencyNumberList *epsEmergencyNumberList; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN epsEmergencyNumberList_Present;
	c_EPSNetworkFeatureSupport *EPSNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EPSNetworkFeatureSupport_Present;
	c_AdditionalUpdateResult *AdditionalUpdateResult; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateResult_Present;
	c_epsGprsTimer *T3412ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3412ExtendedValue_Present;
	c_epsGprsTimer2 *T3324ValueGPRSTimer2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324ValueGPRSTimer2_Present;
	c_epsExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;

}	c_ATTACH_ACCEPT;
#define INIT_c_ATTACH_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_ACCEPT))
/*FRK03a*/
void FREE_c_ATTACH_ACCEPT(c_ATTACH_ACCEPT* sp);
int SETPRESENT_c_ATTACH_ACCEPT_GUTI (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_GUTI(sp) ((sp)->GUTI_Present)
int SETPRESENT_c_ATTACH_ACCEPT_LocationAreaIdentification (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_LocationAreaIdentification(sp) ((sp)->LocationAreaIdentification_Present)
int SETPRESENT_c_ATTACH_ACCEPT_MSIdentity (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_MSIdentity(sp) ((sp)->MSIdentity_Present)
#define SETPRESENT_c_ATTACH_ACCEPT_EMMCause(sp,present) (((sp)->EMMCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_ATTACH_ACCEPT_EMMCause(sp) ((sp)->EMMCause_Present)
int SETPRESENT_c_ATTACH_ACCEPT_T3402Value (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_T3402Value(sp) ((sp)->T3402Value_Present)
int SETPRESENT_c_ATTACH_ACCEPT_T3423Value (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_T3423Value(sp) ((sp)->T3423Value_Present)
int SETPRESENT_c_ATTACH_ACCEPT_EquivalentPLMNs (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_EquivalentPLMNs(sp) ((sp)->EquivalentPLMNs_Present)
int SETPRESENT_c_ATTACH_ACCEPT_epsEmergencyNumberList (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_epsEmergencyNumberList(sp) ((sp)->epsEmergencyNumberList_Present)
int SETPRESENT_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_EPSNetworkFeatureSupport(sp) ((sp)->EPSNetworkFeatureSupport_Present)
int SETPRESENT_c_ATTACH_ACCEPT_AdditionalUpdateResult (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_AdditionalUpdateResult(sp) ((sp)->AdditionalUpdateResult_Present)
int SETPRESENT_c_ATTACH_ACCEPT_T3412ExtendedValue (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_T3412ExtendedValue(sp) ((sp)->T3412ExtendedValue_Present)
int SETPRESENT_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2 (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_T3324ValueGPRSTimer2(sp) ((sp)->T3324ValueGPRSTimer2_Present)
int SETPRESENT_c_ATTACH_ACCEPT_ExtendedDRXParameters (c_ATTACH_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_ACCEPT_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)

/* Access member 'SecurityHeaderType' of type 'c_ATTACH_REJECT' as a variable reference */
#define VAR_c_ATTACH_REJECT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_ATTACH_REJECT' as a pointer */
#define PTR_c_ATTACH_REJECT_SecurityHeaderType(var) (&var)

/* Access member 'EMMCause' of type 'c_ATTACH_REJECT' as a variable reference */
#define VAR_c_ATTACH_REJECT_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_ATTACH_REJECT' as a pointer */
#define PTR_c_ATTACH_REJECT_EMMCause(var) (&var)

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_REJECT' as a variable reference */
#define VAR_c_ATTACH_REJECT_ESMMessageContainer(var) (*var)

/* Access member 'ESMMessageContainer' of type 'c_ATTACH_REJECT' as a pointer */
#define PTR_c_ATTACH_REJECT_ESMMessageContainer(var) var

/* Access member 'T3346Value' of type 'c_ATTACH_REJECT' as a variable reference */
#define VAR_c_ATTACH_REJECT_T3346Value(var) (*var)

/* Access member 'T3346Value' of type 'c_ATTACH_REJECT' as a pointer */
#define PTR_c_ATTACH_REJECT_T3346Value(var) var

/* Access member 'T3402Value' of type 'c_ATTACH_REJECT' as a variable reference */
#define VAR_c_ATTACH_REJECT_T3402Value(var) (*var)

/* Access member 'T3402Value' of type 'c_ATTACH_REJECT' as a pointer */
#define PTR_c_ATTACH_REJECT_T3402Value(var) var

/* Access member 'ExtendedEMMCause' of type 'c_ATTACH_REJECT' as a variable reference */
#define VAR_c_ATTACH_REJECT_ExtendedEMMCause(var) (*var)

/* Access member 'ExtendedEMMCause' of type 'c_ATTACH_REJECT' as a pointer */
#define PTR_c_ATTACH_REJECT_ExtendedEMMCause(var) var


/*-A----------------------------------*/
typedef struct _c_ATTACH_REJECT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/
	c_ESMMessageDn *ESMMessageContainer; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ESMMessageContainer_Present;
	c_epsGprsTimer2 *T3346Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3346Value_Present;
	c_epsGprsTimer2 *T3402Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3402Value_Present;
	c_ExtendedEMMCause *ExtendedEMMCause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedEMMCause_Present;

}	c_ATTACH_REJECT;
#define INIT_c_ATTACH_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_ATTACH_REJECT))
/*FRK03a*/
void FREE_c_ATTACH_REJECT(c_ATTACH_REJECT* sp);
int SETPRESENT_c_ATTACH_REJECT_ESMMessageContainer (c_ATTACH_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REJECT_ESMMessageContainer(sp) ((sp)->ESMMessageContainer_Present)
int SETPRESENT_c_ATTACH_REJECT_T3346Value (c_ATTACH_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REJECT_T3346Value(sp) ((sp)->T3346Value_Present)
int SETPRESENT_c_ATTACH_REJECT_T3402Value (c_ATTACH_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REJECT_T3402Value(sp) ((sp)->T3402Value_Present)
int SETPRESENT_c_ATTACH_REJECT_ExtendedEMMCause (c_ATTACH_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_ATTACH_REJECT_ExtendedEMMCause(sp) ((sp)->ExtendedEMMCause_Present)

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_REJECT' as a variable reference */
#define VAR_c_AUTHENTICATION_REJECT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_REJECT' as a pointer */
#define PTR_c_AUTHENTICATION_REJECT_SecurityHeaderType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_REJECT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/

}	c_AUTHENTICATION_REJECT;
#define INIT_c_AUTHENTICATION_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_REJECT))
/*FRK03a*/
void FREE_c_AUTHENTICATION_REJECT(c_AUTHENTICATION_REJECT* sp);

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_REQUEST' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_AUTHENTICATION_REQUEST' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_SecurityHeaderType(var) (&var)

/* Access member 'NASKeySetIdentifierASME' of type 'c_AUTHENTICATION_REQUEST' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_NASKeySetIdentifierASME(var) var

/* Access member 'NASKeySetIdentifierASME' of type 'c_AUTHENTICATION_REQUEST' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_NASKeySetIdentifierASME(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_AUTHENTICATION_REQUEST' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_AUTHENTICATION_REQUEST' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_SpareHalfOctet(var) (&var)

/* Access member 'AuthenticationParameterRANDEPSChallenge' of type 'c_AUTHENTICATION_REQUEST' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_AuthenticationParameterRANDEPSChallenge(var) var

/* Access member 'AuthenticationParameterRANDEPSChallenge' of type 'c_AUTHENTICATION_REQUEST' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_AuthenticationParameterRANDEPSChallenge(var) (&var)

/* Access member 'AuthenticationParameterAUTNEPSChallenge' of type 'c_AUTHENTICATION_REQUEST' as a variable reference */
#define VAR_c_AUTHENTICATION_REQUEST_AuthenticationParameterAUTNEPSChallenge(var) var

/* Access member 'AuthenticationParameterAUTNEPSChallenge' of type 'c_AUTHENTICATION_REQUEST' as a pointer */
#define PTR_c_AUTHENTICATION_REQUEST_AuthenticationParameterAUTNEPSChallenge(var) (&var)


/*-A----------------------------------*/
typedef struct _c_AUTHENTICATION_REQUEST {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR AuthenticationParameterRANDEPSChallenge___LOCATOR  /*LBD02*/;
	ED_LOCATOR AuthenticationParameterAUTNEPSChallenge___LOCATOR  /*LBD02*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier NASKeySetIdentifierASME; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_BYTE AuthenticationParameterRANDEPSChallenge [16]; /* Static, fixed size; bits needed 128 *//*GBD01b*/
	ED_BYTE AuthenticationParameterAUTNEPSChallenge [16]; /* Static, fixed size; bits needed 128 *//*GBD01b*/

}	c_AUTHENTICATION_REQUEST;
#define INIT_c_AUTHENTICATION_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_AUTHENTICATION_REQUEST))
/*FRK03a*/
void FREE_c_AUTHENTICATION_REQUEST(c_AUTHENTICATION_REQUEST* sp);

/* Access member 'SecurityHeaderType' of type 'c_CS_SERVICE_NOTIFICATION' as a variable reference */
#define VAR_c_CS_SERVICE_NOTIFICATION_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_CS_SERVICE_NOTIFICATION' as a pointer */
#define PTR_c_CS_SERVICE_NOTIFICATION_SecurityHeaderType(var) (&var)

/* Access member 'PagingIdentity' of type 'c_CS_SERVICE_NOTIFICATION' as a variable reference */
#define VAR_c_CS_SERVICE_NOTIFICATION_PagingIdentity(var) var

/* Access member 'PagingIdentity' of type 'c_CS_SERVICE_NOTIFICATION' as a pointer */
#define PTR_c_CS_SERVICE_NOTIFICATION_PagingIdentity(var) (&var)

/* Access member 'CLI' of type 'c_CS_SERVICE_NOTIFICATION' as a variable reference */
#define VAR_c_CS_SERVICE_NOTIFICATION_CLI(var) (*var)

/* Access member 'CLI' of type 'c_CS_SERVICE_NOTIFICATION' as a pointer */
#define PTR_c_CS_SERVICE_NOTIFICATION_CLI(var) var

/* Access member 'SSCode' of type 'c_CS_SERVICE_NOTIFICATION' as a variable reference */
#define VAR_c_CS_SERVICE_NOTIFICATION_SSCode(var) var

/* Access member 'SSCode' of type 'c_CS_SERVICE_NOTIFICATION' as a pointer */
#define PTR_c_CS_SERVICE_NOTIFICATION_SSCode(var) (&var)

/* Access member 'LCSIndicator' of type 'c_CS_SERVICE_NOTIFICATION' as a variable reference */
#define VAR_c_CS_SERVICE_NOTIFICATION_LCSIndicator(var) var

/* Access member 'LCSIndicator' of type 'c_CS_SERVICE_NOTIFICATION' as a pointer */
#define PTR_c_CS_SERVICE_NOTIFICATION_LCSIndicator(var) (&var)

/* Access member 'LCSClientId' of type 'c_CS_SERVICE_NOTIFICATION' as a variable reference */
#define VAR_c_CS_SERVICE_NOTIFICATION_LCSClientId(var) (*var)

/* Access member 'LCSClientId' of type 'c_CS_SERVICE_NOTIFICATION' as a pointer */
#define PTR_c_CS_SERVICE_NOTIFICATION_LCSClientId(var) var

/* DEFINITION OF BINARY c_CS_SERVICE_NOTIFICATION_LCSClientId */
typedef struct _c_CS_SERVICE_NOTIFICATION_LCSClientId {
	ED_BYTE* value; /* Variable size; bits needed 2040 */
	int usedBits;
} c_CS_SERVICE_NOTIFICATION_LCSClientId;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_CS_SERVICE_NOTIFICATION_LCSClientId(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_CS_SERVICE_NOTIFICATION {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR PagingIdentity___LOCATOR; /* QUI2 */
	ED_LOCATOR SSCode___LOCATOR; /* QUI2 */
	ED_LOCATOR LCSIndicator___LOCATOR; /* QUI2 */
	ED_LOCATOR LCSClientId___LOCATOR  /*LBD01*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET PagingIdentity; /* ODY01a *//*GBD01b*/
	c_epsCallingPartyBcdNum *CLI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN CLI_Present;
	ED_OCTET SSCode; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN SSCode_Present;
	ED_OCTET LCSIndicator; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LCSIndicator_Present;
	c_CS_SERVICE_NOTIFICATION_LCSClientId* LCSClientId; /* Dynamic, variable size; bits needed 2040 ODY02b *//*GBD01b*/
	ED_BOOLEAN LCSClientId_Present;

}	c_CS_SERVICE_NOTIFICATION;
#define INIT_c_CS_SERVICE_NOTIFICATION(sp) ED_RESET_MEM ((sp), sizeof (c_CS_SERVICE_NOTIFICATION))
/*FRK03a*/
void FREE_c_CS_SERVICE_NOTIFICATION(c_CS_SERVICE_NOTIFICATION* sp);
int SETPRESENT_c_CS_SERVICE_NOTIFICATION_CLI (c_CS_SERVICE_NOTIFICATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CS_SERVICE_NOTIFICATION_CLI(sp) ((sp)->CLI_Present)
#define SETPRESENT_c_CS_SERVICE_NOTIFICATION_SSCode(sp,present) (((sp)->SSCode_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CS_SERVICE_NOTIFICATION_SSCode(sp) ((sp)->SSCode_Present)
#define SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSIndicator(sp,present) (((sp)->LCSIndicator_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSIndicator(sp) ((sp)->LCSIndicator_Present)
int SETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSClientId (c_CS_SERVICE_NOTIFICATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_CS_SERVICE_NOTIFICATION_LCSClientId(sp) ((sp)->LCSClientId_Present)

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_ACCEPT_DN' as a variable reference */
#define VAR_c_EPS_DETACH_ACCEPT_DN_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_ACCEPT_DN' as a pointer */
#define PTR_c_EPS_DETACH_ACCEPT_DN_SecurityHeaderType(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPS_DETACH_ACCEPT_DN {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/

}	c_EPS_DETACH_ACCEPT_DN;
#define INIT_c_EPS_DETACH_ACCEPT_DN(sp) ED_RESET_MEM ((sp), sizeof (c_EPS_DETACH_ACCEPT_DN))
/*FRK03a*/
void FREE_c_EPS_DETACH_ACCEPT_DN(c_EPS_DETACH_ACCEPT_DN* sp);

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_REQUEST_DN' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_DN_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_EPS_DETACH_REQUEST_DN' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_DN_SecurityHeaderType(var) (&var)

/* Access member 'DetachType' of type 'c_EPS_DETACH_REQUEST_DN' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_DN_DetachType(var) var

/* Access member 'DetachType' of type 'c_EPS_DETACH_REQUEST_DN' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_DN_DetachType(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_EPS_DETACH_REQUEST_DN' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_DN_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_EPS_DETACH_REQUEST_DN' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_DN_SpareHalfOctet(var) (&var)

/* Access member 'EMMCause' of type 'c_EPS_DETACH_REQUEST_DN' as a variable reference */
#define VAR_c_EPS_DETACH_REQUEST_DN_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_EPS_DETACH_REQUEST_DN' as a pointer */
#define PTR_c_EPS_DETACH_REQUEST_DN_EMMCause(var) (&var)


/*-A----------------------------------*/
typedef struct _c_EPS_DETACH_REQUEST_DN {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_EPSDetachType DetachType; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMMCause_Present;

}	c_EPS_DETACH_REQUEST_DN;
#define INIT_c_EPS_DETACH_REQUEST_DN(sp) ED_RESET_MEM ((sp), sizeof (c_EPS_DETACH_REQUEST_DN))
/*FRK03a*/
void FREE_c_EPS_DETACH_REQUEST_DN(c_EPS_DETACH_REQUEST_DN* sp);
#define SETPRESENT_c_EPS_DETACH_REQUEST_DN_EMMCause(sp,present) (((sp)->EMMCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_EPS_DETACH_REQUEST_DN_EMMCause(sp) ((sp)->EMMCause_Present)

/* Access member 'SecurityHeaderType' of type 'c_DOWNLINK_NAS_TRANSPORT' as a variable reference */
#define VAR_c_DOWNLINK_NAS_TRANSPORT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_DOWNLINK_NAS_TRANSPORT' as a pointer */
#define PTR_c_DOWNLINK_NAS_TRANSPORT_SecurityHeaderType(var) (&var)

/* Access member 'NASMessageContainer' of type 'c_DOWNLINK_NAS_TRANSPORT' as a variable reference */
#define VAR_c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer(var) var

/* Access member 'NASMessageContainer' of type 'c_DOWNLINK_NAS_TRANSPORT' as a pointer */
#define PTR_c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer(var) (&var)

/* DEFINITION OF BINARY c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer */
typedef struct _c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer {
	ED_BYTE* value; /* Variable size; bits needed 2008 */
	int usedBits;
} c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DOWNLINK_NAS_TRANSPORT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR NASMessageContainer___LOCATOR  /*LBD02*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_DOWNLINK_NAS_TRANSPORT_NASMessageContainer NASMessageContainer; /* Static, variable size; bits needed 2008 *//*GBD01b*/

}	c_DOWNLINK_NAS_TRANSPORT;
#define INIT_c_DOWNLINK_NAS_TRANSPORT(sp) ED_RESET_MEM ((sp), sizeof (c_DOWNLINK_NAS_TRANSPORT))
/*FRK03a*/
void FREE_c_DOWNLINK_NAS_TRANSPORT(c_DOWNLINK_NAS_TRANSPORT* sp);

/* Access member 'SecurityHeaderType' of type 'c_EMM_INFORMATION' as a variable reference */
#define VAR_c_EMM_INFORMATION_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_EMM_INFORMATION' as a pointer */
#define PTR_c_EMM_INFORMATION_SecurityHeaderType(var) (&var)

/* Access member 'FullNameForNetwork' of type 'c_EMM_INFORMATION' as a variable reference */
#define VAR_c_EMM_INFORMATION_FullNameForNetwork(var) (*var)

/* Access member 'FullNameForNetwork' of type 'c_EMM_INFORMATION' as a pointer */
#define PTR_c_EMM_INFORMATION_FullNameForNetwork(var) var

/* Access member 'ShortNameForNetwork' of type 'c_EMM_INFORMATION' as a variable reference */
#define VAR_c_EMM_INFORMATION_ShortNameForNetwork(var) (*var)

/* Access member 'ShortNameForNetwork' of type 'c_EMM_INFORMATION' as a pointer */
#define PTR_c_EMM_INFORMATION_ShortNameForNetwork(var) var

/* Access member 'LocalTimeZone' of type 'c_EMM_INFORMATION' as a variable reference */
#define VAR_c_EMM_INFORMATION_LocalTimeZone(var) var

/* Access member 'LocalTimeZone' of type 'c_EMM_INFORMATION' as a pointer */
#define PTR_c_EMM_INFORMATION_LocalTimeZone(var) (&var)

/* Access member 'UniversalTimeAndLocalTimeZone' of type 'c_EMM_INFORMATION' as a variable reference */
#define VAR_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone(var) (*var)

/* Access member 'UniversalTimeAndLocalTimeZone' of type 'c_EMM_INFORMATION' as a pointer */
#define PTR_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone(var) var

/* Access member 'NetworkDaylightSavingTime' of type 'c_EMM_INFORMATION' as a variable reference */
#define VAR_c_EMM_INFORMATION_NetworkDaylightSavingTime(var) (*var)

/* Access member 'NetworkDaylightSavingTime' of type 'c_EMM_INFORMATION' as a pointer */
#define PTR_c_EMM_INFORMATION_NetworkDaylightSavingTime(var) var


/*-A----------------------------------*/
typedef struct _c_EMM_INFORMATION {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR LocalTimeZone___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_epsNetwkName *FullNameForNetwork; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN FullNameForNetwork_Present;
	c_epsNetwkName *ShortNameForNetwork; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ShortNameForNetwork_Present;
	ED_OCTET LocalTimeZone; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN LocalTimeZone_Present;
	c_epsTimeZoneAndTime *UniversalTimeAndLocalTimeZone; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN UniversalTimeAndLocalTimeZone_Present;
	c_epsDaylightSavingTime *NetworkDaylightSavingTime; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN NetworkDaylightSavingTime_Present;

}	c_EMM_INFORMATION;
#define INIT_c_EMM_INFORMATION(sp) ED_RESET_MEM ((sp), sizeof (c_EMM_INFORMATION))
/*FRK03a*/
void FREE_c_EMM_INFORMATION(c_EMM_INFORMATION* sp);
int SETPRESENT_c_EMM_INFORMATION_FullNameForNetwork (c_EMM_INFORMATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EMM_INFORMATION_FullNameForNetwork(sp) ((sp)->FullNameForNetwork_Present)
int SETPRESENT_c_EMM_INFORMATION_ShortNameForNetwork (c_EMM_INFORMATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EMM_INFORMATION_ShortNameForNetwork(sp) ((sp)->ShortNameForNetwork_Present)
#define SETPRESENT_c_EMM_INFORMATION_LocalTimeZone(sp,present) (((sp)->LocalTimeZone_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_EMM_INFORMATION_LocalTimeZone(sp) ((sp)->LocalTimeZone_Present)
int SETPRESENT_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone (c_EMM_INFORMATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EMM_INFORMATION_UniversalTimeAndLocalTimeZone(sp) ((sp)->UniversalTimeAndLocalTimeZone_Present)
int SETPRESENT_c_EMM_INFORMATION_NetworkDaylightSavingTime (c_EMM_INFORMATION* sp, ED_BOOLEAN present);
#define GETPRESENT_c_EMM_INFORMATION_NetworkDaylightSavingTime(sp) ((sp)->NetworkDaylightSavingTime_Present)

/* Access member 'SecurityHeaderType' of type 'c_GUTI_REALLOCATION_COMMAND' as a variable reference */
#define VAR_c_GUTI_REALLOCATION_COMMAND_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_GUTI_REALLOCATION_COMMAND' as a pointer */
#define PTR_c_GUTI_REALLOCATION_COMMAND_SecurityHeaderType(var) (&var)

/* Access member 'GUTI' of type 'c_GUTI_REALLOCATION_COMMAND' as a variable reference */
#define VAR_c_GUTI_REALLOCATION_COMMAND_GUTI(var) var

/* Access member 'GUTI' of type 'c_GUTI_REALLOCATION_COMMAND' as a pointer */
#define PTR_c_GUTI_REALLOCATION_COMMAND_GUTI(var) (&var)

/* Access member 'TAIList' of type 'c_GUTI_REALLOCATION_COMMAND' as a variable reference */
#define VAR_c_GUTI_REALLOCATION_COMMAND_TAIList(var) (*var)

/* Access member 'TAIList' of type 'c_GUTI_REALLOCATION_COMMAND' as a pointer */
#define PTR_c_GUTI_REALLOCATION_COMMAND_TAIList(var) var


/*-A----------------------------------*/
typedef struct _c_GUTI_REALLOCATION_COMMAND {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_EPSMobileIdentity GUTI; /* ODY01a *//*GBD01b*/
	c_PartialTrackingAreaIdentityList *TAIList; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TAIList_Present;

}	c_GUTI_REALLOCATION_COMMAND;
#define INIT_c_GUTI_REALLOCATION_COMMAND(sp) ED_RESET_MEM ((sp), sizeof (c_GUTI_REALLOCATION_COMMAND))
/*FRK03a*/
void FREE_c_GUTI_REALLOCATION_COMMAND(c_GUTI_REALLOCATION_COMMAND* sp);
int SETPRESENT_c_GUTI_REALLOCATION_COMMAND_TAIList (c_GUTI_REALLOCATION_COMMAND* sp, ED_BOOLEAN present);
#define GETPRESENT_c_GUTI_REALLOCATION_COMMAND_TAIList(sp) ((sp)->TAIList_Present)

/* Access member 'SecurityHeaderType' of type 'c_IDENTITY_REQUEST' as a variable reference */
#define VAR_c_IDENTITY_REQUEST_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_IDENTITY_REQUEST' as a pointer */
#define PTR_c_IDENTITY_REQUEST_SecurityHeaderType(var) (&var)

/* Access member 'IdentityType' of type 'c_IDENTITY_REQUEST' as a variable reference */
#define VAR_c_IDENTITY_REQUEST_IdentityType(var) var

/* Access member 'IdentityType' of type 'c_IDENTITY_REQUEST' as a pointer */
#define PTR_c_IDENTITY_REQUEST_IdentityType(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_IDENTITY_REQUEST' as a variable reference */
#define VAR_c_IDENTITY_REQUEST_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_IDENTITY_REQUEST' as a pointer */
#define PTR_c_IDENTITY_REQUEST_SpareHalfOctet(var) (&var)


/*-A----------------------------------*/
typedef struct _c_IDENTITY_REQUEST {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR IdentityType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET IdentityType; /* ODY01a *//*GBD01b*/
	/*GBD01b*/

}	c_IDENTITY_REQUEST;
#define INIT_c_IDENTITY_REQUEST(sp) ED_RESET_MEM ((sp), sizeof (c_IDENTITY_REQUEST))
/*FRK03a*/
void FREE_c_IDENTITY_REQUEST(c_IDENTITY_REQUEST* sp);

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_SecurityHeaderType(var) (&var)

/* Access member 'SelectedNASSecurityAlgorithms' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_SelectedNASSecurityAlgorithms(var) var

/* Access member 'SelectedNASSecurityAlgorithms' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_SelectedNASSecurityAlgorithms(var) (&var)

/* Access member 'NASKeySetIdentifier' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_NASKeySetIdentifier(var) var

/* Access member 'NASKeySetIdentifier' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_NASKeySetIdentifier(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_SpareHalfOctet(var) (&var)

/* Access member 'ReplayedUESecurityCapabilities' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_ReplayedUESecurityCapabilities(var) var

/* Access member 'ReplayedUESecurityCapabilities' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_ReplayedUESecurityCapabilities(var) (&var)

/* Access member 'IMEISVRequest' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_IMEISVRequest(var) var

/* Access member 'IMEISVRequest' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_IMEISVRequest(var) (&var)

/* Access member 'ReplayedNonceUE' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_ReplayedNonceUE(var) var

/* Access member 'ReplayedNonceUE' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_ReplayedNonceUE(var) (&var)

/* Access member 'NonceMME' of type 'c_SECURITY_MODE_COMMAND' as a variable reference */
#define VAR_c_SECURITY_MODE_COMMAND_NonceMME(var) var

/* Access member 'NonceMME' of type 'c_SECURITY_MODE_COMMAND' as a pointer */
#define PTR_c_SECURITY_MODE_COMMAND_NonceMME(var) (&var)


/*-A----------------------------------*/
typedef struct _c_SECURITY_MODE_COMMAND {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR IMEISVRequest___LOCATOR; /* QUI2 */
	ED_LOCATOR ReplayedNonceUE___LOCATOR; /* QUI2 */
	ED_LOCATOR NonceMME___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_NASSecurityAlgorithms SelectedNASSecurityAlgorithms; /* ODY01a *//*GBD01b*/
	c_NASKeySetIdentifier NASKeySetIdentifier; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_UESecurityCapability ReplayedUESecurityCapabilities; /* ODY01a *//*GBD01b*/
	ED_OCTET IMEISVRequest; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN IMEISVRequest_Present;
	ED_LONG ReplayedNonceUE; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN ReplayedNonceUE_Present;
	ED_LONG NonceMME; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN NonceMME_Present;

}	c_SECURITY_MODE_COMMAND;
#define INIT_c_SECURITY_MODE_COMMAND(sp) ED_RESET_MEM ((sp), sizeof (c_SECURITY_MODE_COMMAND))
/*FRK03a*/
void FREE_c_SECURITY_MODE_COMMAND(c_SECURITY_MODE_COMMAND* sp);
#define SETPRESENT_c_SECURITY_MODE_COMMAND_IMEISVRequest(sp,present) (((sp)->IMEISVRequest_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SECURITY_MODE_COMMAND_IMEISVRequest(sp) ((sp)->IMEISVRequest_Present)
#define SETPRESENT_c_SECURITY_MODE_COMMAND_ReplayedNonceUE(sp,present) (((sp)->ReplayedNonceUE_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SECURITY_MODE_COMMAND_ReplayedNonceUE(sp) ((sp)->ReplayedNonceUE_Present)
#define SETPRESENT_c_SECURITY_MODE_COMMAND_NonceMME(sp,present) (((sp)->NonceMME_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_SECURITY_MODE_COMMAND_NonceMME(sp) ((sp)->NonceMME_Present)

/* Access member 'SecurityHeaderType' of type 'c_SERVICE_REJECT' as a variable reference */
#define VAR_c_SERVICE_REJECT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_SERVICE_REJECT' as a pointer */
#define PTR_c_SERVICE_REJECT_SecurityHeaderType(var) (&var)

/* Access member 'EMMCause' of type 'c_SERVICE_REJECT' as a variable reference */
#define VAR_c_SERVICE_REJECT_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_SERVICE_REJECT' as a pointer */
#define PTR_c_SERVICE_REJECT_EMMCause(var) (&var)

/* Access member 'T3442Value' of type 'c_SERVICE_REJECT' as a variable reference */
#define VAR_c_SERVICE_REJECT_T3442Value(var) (*var)

/* Access member 'T3442Value' of type 'c_SERVICE_REJECT' as a pointer */
#define PTR_c_SERVICE_REJECT_T3442Value(var) var

/* Access member 'T3346Value' of type 'c_SERVICE_REJECT' as a variable reference */
#define VAR_c_SERVICE_REJECT_T3346Value(var) (*var)

/* Access member 'T3346Value' of type 'c_SERVICE_REJECT' as a pointer */
#define PTR_c_SERVICE_REJECT_T3346Value(var) var


/*-A----------------------------------*/
typedef struct _c_SERVICE_REJECT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/
	c_epsGprsTimer *T3442Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3442Value_Present;
	c_epsGprsTimer2 *T3346Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3346Value_Present;

}	c_SERVICE_REJECT;
#define INIT_c_SERVICE_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_SERVICE_REJECT))
/*FRK03a*/
void FREE_c_SERVICE_REJECT(c_SERVICE_REJECT* sp);
int SETPRESENT_c_SERVICE_REJECT_T3442Value (c_SERVICE_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_REJECT_T3442Value(sp) ((sp)->T3442Value_Present)
int SETPRESENT_c_SERVICE_REJECT_T3346Value (c_SERVICE_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_REJECT_T3346Value(sp) ((sp)->T3346Value_Present)

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_SecurityHeaderType(var) (&var)

/* Access member 'EPSUpdateResult' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_EPSUpdateResult(var) var

/* Access member 'EPSUpdateResult' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_EPSUpdateResult(var) (&var)

/* Access member 'SpareHalfOctet' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_SpareHalfOctet(var) var

/* Access member 'SpareHalfOctet' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_SpareHalfOctet(var) (&var)

/* Access member 'T3412Value' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value(var) (*var)

/* Access member 'T3412Value' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value(var) var

/* Access member 'GUTI' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI(var) (*var)

/* Access member 'GUTI' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI(var) var

/* Access member 'TAIList' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList(var) (*var)

/* Access member 'TAIList' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList(var) var

/* Access member 'EPSBearerContextStatus' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus(var) (*var)

/* Access member 'EPSBearerContextStatus' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus(var) var

/* Access member 'LocationAreaIdentification' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification(var) (*var)

/* Access member 'LocationAreaIdentification' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification(var) var

/* Access member 'MSIdentity' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity(var) (*var)

/* Access member 'MSIdentity' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity(var) var

/* Access member 'EMMCause' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_EMMCause(var) (&var)

/* Access member 'T3402Value' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value(var) (*var)

/* Access member 'T3402Value' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value(var) var

/* Access member 'T3423Value' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value(var) (*var)

/* Access member 'T3423Value' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value(var) var

/* Access member 'EquivalentPLMNs' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs(var) (*var)

/* Access member 'EquivalentPLMNs' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs(var) var

/* Access member 'epsEmergencyNumberList' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList(var) (*var)

/* Access member 'epsEmergencyNumberList' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList(var) var

/* Access member 'EPSNetworkFeatureSupport' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport(var) (*var)

/* Access member 'EPSNetworkFeatureSupport' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport(var) var

/* Access member 'AdditionalUpdateResult' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult(var) (*var)

/* Access member 'AdditionalUpdateResult' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult(var) var

/* Access member 'T3412ExtendedValue' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue(var) (*var)

/* Access member 'T3412ExtendedValue' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue(var) var

/* Access member 'T3324ValueGPRSTimer2' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2(var) (*var)

/* Access member 'T3324ValueGPRSTimer2' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2(var) var

/* Access member 'ExtendedDRXParameters' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters(var) (*var)

/* Access member 'ExtendedDRXParameters' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters(var) var

/* Access member 'HeaderCompressionCfgStatus' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus(var) (*var)

/* Access member 'HeaderCompressionCfgStatus' of type 'c_TRACKING_AREA_UPDATE_ACCEPT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus(var) var


/*-A----------------------------------*/
typedef struct _c_TRACKING_AREA_UPDATE_ACCEPT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EPSUpdateResult___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EPSUpdateResult; /* ODY01a *//*GBD01b*/
	/*GBD01b*/
	c_epsGprsTimer *T3412Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3412Value_Present;
	c_EPSMobileIdentity *GUTI; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN GUTI_Present;
	c_PartialTrackingAreaIdentityList *TAIList; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN TAIList_Present;
	c_EPSBearerContextStatus *EPSBearerContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EPSBearerContextStatus_Present;
	c_epsLocationAreaId *LocationAreaIdentification; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN LocationAreaIdentification_Present;
	c_epsMobileId *MSIdentity; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN MSIdentity_Present;
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/
	ED_BOOLEAN EMMCause_Present;
	c_epsGprsTimer *T3402Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3402Value_Present;
	c_epsGprsTimer *T3423Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3423Value_Present;
	c_epsPlmnList *EquivalentPLMNs; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EquivalentPLMNs_Present;
	c_epsEmergencyNumberList *epsEmergencyNumberList; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN epsEmergencyNumberList_Present;
	c_EPSNetworkFeatureSupport *EPSNetworkFeatureSupport; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EPSNetworkFeatureSupport_Present;
	c_AdditionalUpdateResult *AdditionalUpdateResult; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN AdditionalUpdateResult_Present;
	c_epsGprsTimer *T3412ExtendedValue; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3412ExtendedValue_Present;
	c_epsGprsTimer2 *T3324ValueGPRSTimer2; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3324ValueGPRSTimer2_Present;
	c_epsExtendedDRXParameters *ExtendedDRXParameters; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedDRXParameters_Present;
	c_HeaderCompressionCfgStatus *HeaderCompressionCfgStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN HeaderCompressionCfgStatus_Present;

}	c_TRACKING_AREA_UPDATE_ACCEPT;
#define INIT_c_TRACKING_AREA_UPDATE_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_TRACKING_AREA_UPDATE_ACCEPT))
/*FRK03a*/
void FREE_c_TRACKING_AREA_UPDATE_ACCEPT(c_TRACKING_AREA_UPDATE_ACCEPT* sp);
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412Value(sp) ((sp)->T3412Value_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_GUTI(sp) ((sp)->GUTI_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_TAIList(sp) ((sp)->TAIList_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSBearerContextStatus(sp) ((sp)->EPSBearerContextStatus_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_LocationAreaIdentification(sp) ((sp)->LocationAreaIdentification_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_MSIdentity(sp) ((sp)->MSIdentity_Present)
#define SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EMMCause(sp,present) (((sp)->EMMCause_Present = present), ED_NO_ERRORS)
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EMMCause(sp) ((sp)->EMMCause_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3402Value(sp) ((sp)->T3402Value_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3423Value(sp) ((sp)->T3423Value_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EquivalentPLMNs(sp) ((sp)->EquivalentPLMNs_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_epsEmergencyNumberList(sp) ((sp)->epsEmergencyNumberList_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_EPSNetworkFeatureSupport(sp) ((sp)->EPSNetworkFeatureSupport_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_AdditionalUpdateResult(sp) ((sp)->AdditionalUpdateResult_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3412ExtendedValue(sp) ((sp)->T3412ExtendedValue_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2 (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_T3324ValueGPRSTimer2(sp) ((sp)->T3324ValueGPRSTimer2_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_ExtendedDRXParameters(sp) ((sp)->ExtendedDRXParameters_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus (c_TRACKING_AREA_UPDATE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_ACCEPT_HeaderCompressionCfgStatus(sp) ((sp)->HeaderCompressionCfgStatus_Present)

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REJECT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REJECT_SecurityHeaderType(var) (&var)

/* Access member 'EMMCause' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REJECT_EMMCause(var) var

/* Access member 'EMMCause' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REJECT_EMMCause(var) (&var)

/* Access member 'T3346Value' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REJECT_T3346Value(var) (*var)

/* Access member 'T3346Value' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REJECT_T3346Value(var) var

/* Access member 'ExtendedEMMCause' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a variable reference */
#define VAR_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause(var) (*var)

/* Access member 'ExtendedEMMCause' of type 'c_TRACKING_AREA_UPDATE_REJECT' as a pointer */
#define PTR_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause(var) var


/*-A----------------------------------*/
typedef struct _c_TRACKING_AREA_UPDATE_REJECT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR EMMCause___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET EMMCause; /* ODY01a *//*GBD01b*/
	c_epsGprsTimer2 *T3346Value; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN T3346Value_Present;
	c_ExtendedEMMCause *ExtendedEMMCause; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN ExtendedEMMCause_Present;

}	c_TRACKING_AREA_UPDATE_REJECT;
#define INIT_c_TRACKING_AREA_UPDATE_REJECT(sp) ED_RESET_MEM ((sp), sizeof (c_TRACKING_AREA_UPDATE_REJECT))
/*FRK03a*/
void FREE_c_TRACKING_AREA_UPDATE_REJECT(c_TRACKING_AREA_UPDATE_REJECT* sp);
int SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_T3346Value (c_TRACKING_AREA_UPDATE_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_T3346Value(sp) ((sp)->T3346Value_Present)
int SETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause (c_TRACKING_AREA_UPDATE_REJECT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_TRACKING_AREA_UPDATE_REJECT_ExtendedEMMCause(sp) ((sp)->ExtendedEMMCause_Present)

/* Access member 'SecurityHeaderType' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_SecurityHeaderType(var) (&var)

/* Access member 'GenericMessageContainerType' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainerType(var) var

/* Access member 'GenericMessageContainerType' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainerType(var) (&var)

/* Access member 'GenericMessageContainer' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer(var) var

/* Access member 'GenericMessageContainer' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer(var) (&var)

/* Access member 'AdditionalInformation' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a variable reference */
#define VAR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(var) (*var)

/* Access member 'AdditionalInformation' of type 'c_DOWNLINK_GENERIC_NAS_TRANSPORT' as a pointer */
#define PTR_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(var) var

/* DEFINITION OF BINARY c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer */
typedef struct _c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))


/* DEFINITION OF BINARY c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation */
typedef struct _c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation {
	ED_BYTE* value; /* Variable size; bits needed 4784 */
	int usedBits;
} c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_DOWNLINK_GENERIC_NAS_TRANSPORT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */
	ED_LOCATOR GenericMessageContainerType___LOCATOR; /* QUI2 */
	ED_LOCATOR GenericMessageContainer___LOCATOR  /*LBD02*/;
	ED_LOCATOR AdditionalInformation___LOCATOR  /*LBD01*/;

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	ED_OCTET GenericMessageContainerType; /* ODY01a *//*GBD01b*/
	c_DOWNLINK_GENERIC_NAS_TRANSPORT_GenericMessageContainer GenericMessageContainer; /* Static, variable size; bits needed 4784 *//*GBD01b*/
	c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation* AdditionalInformation; /* Dynamic, variable size; bits needed 4784 ODY02b *//*GBD01b*/
	ED_BOOLEAN AdditionalInformation_Present;

}	c_DOWNLINK_GENERIC_NAS_TRANSPORT;
#define INIT_c_DOWNLINK_GENERIC_NAS_TRANSPORT(sp) ED_RESET_MEM ((sp), sizeof (c_DOWNLINK_GENERIC_NAS_TRANSPORT))
/*FRK03a*/
void FREE_c_DOWNLINK_GENERIC_NAS_TRANSPORT(c_DOWNLINK_GENERIC_NAS_TRANSPORT* sp);
int SETPRESENT_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation (c_DOWNLINK_GENERIC_NAS_TRANSPORT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_DOWNLINK_GENERIC_NAS_TRANSPORT_AdditionalInformation(sp) ((sp)->AdditionalInformation_Present)

/* Access member 'SecurityHeaderType' of type 'c_SERVICE_ACCEPT' as a variable reference */
#define VAR_c_SERVICE_ACCEPT_SecurityHeaderType(var) var

/* Access member 'SecurityHeaderType' of type 'c_SERVICE_ACCEPT' as a pointer */
#define PTR_c_SERVICE_ACCEPT_SecurityHeaderType(var) (&var)

/* Access member 'EPSBearerContextStatus' of type 'c_SERVICE_ACCEPT' as a variable reference */
#define VAR_c_SERVICE_ACCEPT_EPSBearerContextStatus(var) (*var)

/* Access member 'EPSBearerContextStatus' of type 'c_SERVICE_ACCEPT' as a pointer */
#define PTR_c_SERVICE_ACCEPT_EPSBearerContextStatus(var) var


/*-A----------------------------------*/
typedef struct _c_SERVICE_ACCEPT {
	ED_LOCATOR SecurityHeaderType___LOCATOR; /* QUI2 */

	ED_OCTET SecurityHeaderType; /* ODY01a *//*GBD01b*/
	c_EPSBearerContextStatus *EPSBearerContextStatus; /* ODY01 *//*GBD01b*/
	ED_BOOLEAN EPSBearerContextStatus_Present;

}	c_SERVICE_ACCEPT;
#define INIT_c_SERVICE_ACCEPT(sp) ED_RESET_MEM ((sp), sizeof (c_SERVICE_ACCEPT))
/*FRK03a*/
void FREE_c_SERVICE_ACCEPT(c_SERVICE_ACCEPT* sp);
int SETPRESENT_c_SERVICE_ACCEPT_EPSBearerContextStatus (c_SERVICE_ACCEPT* sp, ED_BOOLEAN present);
#define GETPRESENT_c_SERVICE_ACCEPT_EPSBearerContextStatus(sp) ((sp)->EPSBearerContextStatus_Present)

/* Access member 'Unit' of type 'c_epsGprsTimer3' as a variable reference */
#define VAR_c_epsGprsTimer3_Unit(var) var

/* Access member 'Unit' of type 'c_epsGprsTimer3' as a pointer */
#define PTR_c_epsGprsTimer3_Unit(var) (&var)

/* Access member 'TimerValue' of type 'c_epsGprsTimer3' as a variable reference */
#define VAR_c_epsGprsTimer3_TimerValue(var) var

/* Access member 'TimerValue' of type 'c_epsGprsTimer3' as a pointer */
#define PTR_c_epsGprsTimer3_TimerValue(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsGprsTimer3 {
	ED_LOCATOR Unit___LOCATOR; /* QUI2 */
	ED_LOCATOR TimerValue___LOCATOR; /* QUI2 */

	ED_OCTET Unit; /* ODY01a *//*GBD01b*/
	ED_OCTET TimerValue; /* ODY01a *//*GBD01b*/

}	c_epsGprsTimer3;
#define INIT_c_epsGprsTimer3(sp) ED_RESET_MEM ((sp), sizeof (c_epsGprsTimer3))
/*FRK03a*/
void FREE_c_epsGprsTimer3(c_epsGprsTimer3* sp);

/* Access member 'TypeOfNumber' of type 'c_epsCalledPartyBcdNum' as a variable reference */
#define VAR_c_epsCalledPartyBcdNum_TypeOfNumber(var) var

/* Access member 'TypeOfNumber' of type 'c_epsCalledPartyBcdNum' as a pointer */
#define PTR_c_epsCalledPartyBcdNum_TypeOfNumber(var) (&var)

/* Access member 'NumberingPlanIdent' of type 'c_epsCalledPartyBcdNum' as a variable reference */
#define VAR_c_epsCalledPartyBcdNum_NumberingPlanIdent(var) var

/* Access member 'NumberingPlanIdent' of type 'c_epsCalledPartyBcdNum' as a pointer */
#define PTR_c_epsCalledPartyBcdNum_NumberingPlanIdent(var) (&var)

/* Access member 'Number' of type 'c_epsCalledPartyBcdNum' as a variable reference */
#define VAR_c_epsCalledPartyBcdNum_Number(var) var

/* Access member 'Number' of type 'c_epsCalledPartyBcdNum' as a pointer */
#define PTR_c_epsCalledPartyBcdNum_Number(var) (&var)


/*-A----------------------------------*/
typedef struct _c_epsCalledPartyBcdNum {
	ED_LOCATOR TypeOfNumber___LOCATOR; /* QUI2 */
	ED_LOCATOR NumberingPlanIdent___LOCATOR; /* QUI2 */

	ED_OCTET TypeOfNumber; /* ODY01a *//*GBD01b*/
	ED_OCTET NumberingPlanIdent; /* ODY01a *//*GBD01b*/
	c_epsTBCDArray Number; /* ODY01a *//*GBD01b*/

}	c_epsCalledPartyBcdNum;
#define INIT_c_epsCalledPartyBcdNum(sp) ED_RESET_MEM ((sp), sizeof (c_epsCalledPartyBcdNum))
/*FRK03a*/
void FREE_c_epsCalledPartyBcdNum(c_epsCalledPartyBcdNum* sp);

/* Access member 'TLV_Tag' of type 'c_GenericTLV_EPS' as a variable reference */
#define VAR_c_GenericTLV_EPS_TLV_Tag(var) var

/* Access member 'TLV_Tag' of type 'c_GenericTLV_EPS' as a pointer */
#define PTR_c_GenericTLV_EPS_TLV_Tag(var) (&var)

/* Access member 'TLV_Data' of type 'c_GenericTLV_EPS' as a variable reference */
#define VAR_c_GenericTLV_EPS_TLV_Data(var) var

/* Access member 'TLV_Data' of type 'c_GenericTLV_EPS' as a pointer */
#define PTR_c_GenericTLV_EPS_TLV_Data(var) (&var)

/* DEFINITION OF BINARY c_GenericTLV_EPS_TLV_Data */
typedef struct _c_GenericTLV_EPS_TLV_Data {
	ED_BYTE* value; /* Variable size; bits needed 8192 */
	int usedBits;
} c_GenericTLV_EPS_TLV_Data;
/* Binary allocation macro (dynamic version). If the binary string was already
	 allocated, it will be freed and reallocated. */
#define ALLOC_c_GenericTLV_EPS_TLV_Data(sp,bits) EDAllocBinary (&((sp)->value), (unsigned)(bits), &((sp)->usedBits))



/*-A----------------------------------*/
typedef struct _c_GenericTLV_EPS {
	ED_LOCATOR TLV_Tag___LOCATOR; /* QUI2 */
	ED_LOCATOR TLV_Data___LOCATOR  /*LBD02*/;

	ED_LONG TLV_Tag; /* ODY01a *//*GBD01b*/
	c_GenericTLV_EPS_TLV_Data TLV_Data; /* Static, variable size; bits needed 8192 *//*GBD01b*/

}	c_GenericTLV_EPS;
#define INIT_c_GenericTLV_EPS(sp) ED_RESET_MEM ((sp), sizeof (c_GenericTLV_EPS))
/*FRK03a*/
void FREE_c_GenericTLV_EPS(c_GenericTLV_EPS* sp);

/* SETITEMS/ADDITEMS commands for type 'c_RemoteUEContext_Identity_IdentityDigit'. */
int SETITEMS_c_RemoteUEContext_Identity_IdentityDigit (c_RemoteUEContext_Identity_IdentityDigit* sequence, int desiredItems);
#define ADDITEMS_c_RemoteUEContext_Identity_IdentityDigit(sequence, itemsToBeAdded) SETITEMS_c_RemoteUEContext_Identity_IdentityDigit (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_RemoteUEContext_SingleContext_UserIDs'. */
int SETITEMS_c_RemoteUEContext_SingleContext_UserIDs (c_RemoteUEContext_SingleContext_UserIDs* sequence, int desiredItems);
#define ADDITEMS_c_RemoteUEContext_SingleContext_UserIDs(sequence, itemsToBeAdded) SETITEMS_c_RemoteUEContext_SingleContext_UserIDs (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_RemoteUEContext_Contexts'. */
int SETITEMS_c_RemoteUEContext_Contexts (c_RemoteUEContext_Contexts* sequence, int desiredItems);
#define ADDITEMS_c_RemoteUEContext_Contexts(sequence, itemsToBeAdded) SETITEMS_c_RemoteUEContext_Contexts (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_epsTrafficFlowTemplate_PacketFilters'. */
int SETITEMS_c_epsTrafficFlowTemplate_PacketFilters (c_epsTrafficFlowTemplate_PacketFilters* sequence, int desiredItems);
#define ADDITEMS_c_epsTrafficFlowTemplate_PacketFilters(sequence, itemsToBeAdded) SETITEMS_c_epsTrafficFlowTemplate_PacketFilters (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents'. */
int SETITEMS_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents (c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents* sequence, int desiredItems);
#define ADDITEMS_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents(sequence, itemsToBeAdded) SETITEMS_c_epsTrafficFlowTemplate_PacketFilters_data_FilterContents (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_epsTrafficFlowTemplate_PacketParameters'. */
int SETITEMS_c_epsTrafficFlowTemplate_PacketParameters (c_epsTrafficFlowTemplate_PacketParameters* sequence, int desiredItems);
#define ADDITEMS_c_epsTrafficFlowTemplate_PacketParameters(sequence, itemsToBeAdded) SETITEMS_c_epsTrafficFlowTemplate_PacketParameters (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_EPSMobileIdentity_IMSI_IdentityDigit'. */
int SETITEMS_c_EPSMobileIdentity_IMSI_IdentityDigit (c_EPSMobileIdentity_IMSI_IdentityDigit* sequence, int desiredItems);
#define ADDITEMS_c_EPSMobileIdentity_IMSI_IdentityDigit(sequence, itemsToBeAdded) SETITEMS_c_EPSMobileIdentity_IMSI_IdentityDigit (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_epsMobileId_Identity_IdentityDigit'. */
int SETITEMS_c_epsMobileId_Identity_IdentityDigit (c_epsMobileId_Identity_IdentityDigit* sequence, int desiredItems);
#define ADDITEMS_c_epsMobileId_Identity_IdentityDigit(sequence, itemsToBeAdded) SETITEMS_c_epsMobileId_Identity_IdentityDigit (sequence, (sequence)->items+itemsToBeAdded)

/* SETITEMS/ADDITEMS commands for type 'c_epsTBCDEmergencyNumber_Numbers'. */
int SETITEMS_c_epsTBCDEmergencyNumber_Numbers (c_epsTBCDEmergencyNumber_Numbers* sequence, int desiredItems);
#define ADDITEMS_c_epsTBCDEmergencyNumber_Numbers(sequence, itemsToBeAdded) SETITEMS_c_epsTBCDEmergencyNumber_Numbers (sequence, (sequence)->items+itemsToBeAdded)

#ifdef __cplusplus
}
#endif

#endif

