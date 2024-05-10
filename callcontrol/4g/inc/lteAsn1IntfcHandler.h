/*
*############################################################################
*
*                   *** FXLynx Technologies Ltd. ***
*
*     The information contained in this file is the property of FXLynx
*     Technologies Ltd. Except as specifically authorized in writing by
*     FXLynx Technologies Ltd. The user of this file shall keep information
*     contained herein confidential and shall protect same in whole or in
*     part from disclosure and dissemination to third parties.
*
*     Without prior written consent of FXLynx Technologies Ltd. you may not
*     reproduce, represent, or download through any means, the information
 *     contained herein in any way or in any form.
*
*       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
*
*############################################################################
*/

/*
*############################################################################
* File Name   : lteAsn1IntfcHandler.h
*
* Description : Lte Asn1 Library Interface functions Handler
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 27/01/2015          				  Anand Kashikar			LTE_ASN1_INTFC_HANDLER_H_   Initial File Creation
*############################################################################
*/

#ifndef LTE_ASN1_INTFC_HANDLER_H_
#define LTE_ASN1_INTFC_HANDLER_H_


#include "lteL1Defs.h"
#include "lteUserManager.h"
#include "fxLSocketInterfaceApi.h"
#include "lteAsn1Def.h"

typedef struct lteWlRedirectInfo_t
{
	int earfcn;
	int sib5Earfcn;
	int sib6Uarfcn;
	int sib7Arcfn;
	uint8 noOfSib5Freq;
	uint8 noOfSib6Freq;
	uint8 noOfSib7Freq;
	uint8 sib7BandIndicator;
}lteWlRedirectInfo;

typedef struct lteSysModifyInfo_t
{
	unsigned int 	      earfcn;
  	fxL4gBandType     bandIndicator;
	unsigned int	      phyCellId; // 0-503
	unsigned int         layer3CellId;
	unsigned int         numOfPlmn;
	fxL4gPlmn            plmn[FXL_LTE_MAX_NO_PLMNS];
}lteSysModifyInfo;

uint8 asn1EncodedMib[LTE_MIB_MAX_SIZE];
uint8 asn1EncodedSib1[LTE_MAC_SIB1_PDU_SIZE];
uint8 asn1EncodedSib1Len;
uint8 *asn1EncodedSibs;
uint8 asn1EncodedSibsLen;
uint8 *asn1EncodedRrcConnectionSetup;
uint8 asn1EncodedRrcConnectionSetupLen;
uint8 *asn1EncodedRrcConnectionSetupTdd;
uint8 asn1EncodedRrcConnectionSetupTddLen;
uint8 *asn1EncodedRrcConnReestabReject;
uint8 asn1EncodedRrcConnReestabRejectLen;
uint8 *asn1EncodedRrcConnectionRelease;
uint8 asn1EncodedRrcConnectionReleaseLen;
uint8 *asn1EncodedIdentityImsiRequest;
uint8 asn1EncodedIdentityImsiRequestLen;
uint8 *asn1EncodedIdentityImeiRequest;
uint8 asn1EncodedIdentityImeiRequestLen;
uint8 *asn1EncodedAttachRejRequest;
uint8 asn1EncodedAttachRejRequestLen;
uint8 *asn1EncodedTAURejRequest;
uint8 asn1EncodedTAURejRequestLen;
uint8 *asn1EncodedRrcConnectionReleaseWithRedirect;
uint8 asn1EncodedRrcConnectionReleaseWithRedirectLen;
uint8 *asn1EncodedRrcRedirectWL;
uint8 asn1EncodedRrcRedirectWLLen;
uint8 *asn1EncodedPagingRequest;
uint8 asn1EncodedPagingRequestLen;
uint8 *asn1EncodedPagingSibModRequest;
uint8 asn1EncodedPagingSibModRequestLen;
uint8 *asn1EncodedRrcUeCapaEnqReq;
uint8 asn1EncodedRrcUeCapaEnqReqLen;
uint8 *asn1EncodedRrcMeasCntrlReq;
uint8 asn1EncodedRrcMeasCntrlReqLen;
uint8 *asn1EncodedRrcNeighMeasCntrlReq;
uint8 asn1EncodedRrcNeighMeasCntrlReqLen;
unsigned int generateRrcNeighMeasConfigMsg(fxL4gMeasurementCfgCmd * cmd);
uint8 *asn1EncodedRrcReconfigReq;
uint8 asn1EncodedRrcReconfigReqLen;
uint8 *asn1EncodedPagingwithSTmsiRequest;
uint8 asn1EncodedPagingwithSTmsiRequestLen;


void generateMib();
void generateSib1(fxL4gConfigureIdCatcherParamsCmd * cmd);
//ASHU ASN.1 Issue
void generateSib1RrcThrd(fxL4gConfigureIdCatcherParamsCmd * cmd);
//ASHU ASN.1 Issue
void generateSibs(fxL4gConfigureIdCatcherParamsCmd * cmd);
void generateSib1Modify(fxL4gSysInfoModifyCmd * cmd);
void generateSibsModify(fxL4gSysInfoModifyCmd * cmd);
void generateRrcConnectionSetup();
void generateRrcConnReestabReject();
void generateRrcConnectionSetupTDD();
void generateRrcConnectionRelmessage(void);
void generateRrcConnectionRelWithRedirect(fxL4gConfigureIdCatcherParamsCmd * cmd);
void generateRrcReleaseWLRedirect(int earfcn);
void generateIDTImsimessage();
void generateIDTImeimessage();
void generateAttachRejmessage(fxL4gConfigureIdCatcherParamsCmd * cmd);
void generateTAURejmessage();
void generatePagingMsg(lteDlPagingStruct *pImsi);
void generateIMSIPagingMsg(lteDlPagingStruct *inRrcPagingBuf);
void generatePagingMsgWithSTmsi(lteDlPagingStruct *pSTmsi);
void generatePagingMsgForSibMod(void);
void generateRrcReconfigReqMsg(void);
void generateRrcUeCapaEnqMsg();
void generateRrcMeasConfigMsg(fxL4gConfigureIdCatcherParamsCmd * cmd);
int decodeDcchData(uint8* asn1EncodedBuf, uint16 bufLength , void* decodedBuf);
int decodeCcchData(uint8* asn1EncodedBuf, uint16 bufLength , lteUlCCCHMsgStruct *pUlCCCHMsg);

int decodeUlDcchUlInfoTrans(uint8* asn1EncodedBuf, uint16 bufLength , void* decodedBuf);
void generateRrcConnectionRelWithRedirectForBlUe(fxLRedirectionFrom4gType  redirectionType,
                                                 fxLRedirectionFrom4gInfo  redirectionInfo,
                                                 uint8                   **pEncodedBuff,
                                                 uint8                    *pEncodedBuffLen);

#endif /* LTE_ASN1_INTFC_HANDLER_H_ */
