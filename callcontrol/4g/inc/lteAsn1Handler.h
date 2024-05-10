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
* File Name   : lteAsn1Handler.h
 *
* Description : Lte Asn1 Handler
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 25/01/2015          					Anand Kashikar       File Creation
*############################################################################
*/
#ifndef LTE_ASN1_HANDLER_H_
#define LTE_ASN1_HANDLER_H_

#include "lteAsn1Def.h"

sint8  initializeLteASNContext (char *fileName);
void   cleanLteASNContext(void);
//ASHU ASN.1 Changes
sint8  initializeLteASNContextRrcThrd(char *fileName);
void   cleanLteASNContextRrcThrd(void);
sint8  initializeLteASNContextMacThrd(char *fileName);
void   cleanLteASNContextMacThrd(void);
//ASHU ASN.1 Changes
uint8* buildAndEncodeMib(lteMibStruct* inMibBuf , uint8* outEncodedMibBufLen );
uint8* buildAndEncodeSib1(lteSib1Struct* inSib1Buf , uint8* outEncodedSib1BufLen );
uint8* buildAndEncodeSib2345(lteSibsStruct* inSibsBuf , uint8* outEncodedSibsBufLen );
uint8* buildAndEncodeRrcConnectionSetup(lteRrcConnSetupStruct* inRrcConnSetupBuf , uint8* outEncodedRrcConnSetupLen );
uint8* buildAndEncodeRrcReconfigReqMsg(lteRrcConnSetupStruct* inRrcConnSetupBuf , uint8* outEncodedRrcReconfigLen);
uint8* buildAndEncodeRrcConnectionRel(lteRrcConnRelStruct* inRrcConnRelBuf , uint8* outEncodedRrcMsgLen );
//ASHU ASN.1 Change
uint8* buildAndEncodeSib1RrcThrd(lteSib1Struct* inSib1Buf , uint8* outEncodedSib1BufLen );
uint8* buildAndEncodeRrcConnectionRelRrcThrd(lteRrcConnRelStruct* inRrcConnRelBuf , uint8* outEncodedRrcMsgLen );
uint8* buildAndEncodeDlTransferInfo(uint8 *dlIDTMsg, uint8* outEncodedIdtyReqLen );
uint8* buildAndEncodePagingSibModMsg( uint8* outEncodedRrcMsgLen );
uint8* buildAndEncodePagingMsg(lteDlPagingStruct* inRrcPagingBuf , uint8* outEncodedRrcMsgLen );
uint8* buildAndEncodeIMSIPagingMsg(lteDlPagingStruct* inRrcPagingBuf , uint8* outEncodedRrcMsgLen );
uint8* buildAndEncodePagingWithTMSIMsg(lteDlPagingStruct* inRrcPagingBuf , uint8* outEncodedRrcMsgLen );
uint8* buildAndEncodeRrcUeCapaEnquiryMsg(uint8* outEncodedUeCapaReqLen );
uint8* buildAndEncodeRrcMeasCntrlMsg(int earfcn , int ltePCI , uint8* outEncodedMeasConfigLen , eLteBw bandwidth);
uint8* buildAndEncodeRrcMeasCntrlMsgForNeighMeas (LteRrcMeasurementControlData *pLteRrcMeasCtrl , uint8* outEncodedMeasConfigLenForNeighMeas );
int decodeUltransferinfo(uint8* inEncodedBuffer ,uint8 encodingLength, lteRrcUlDCCHData *pUlIdtMsg);
int decodeMib(uint8* inEncodedBuffer ,uint8 encodingLength, lteMibStruct* inMibBuf);
int decodeSibs(uint8* inEncodedBuffer ,uint8 encodingLength, lteSibsStruct* inSibsBuf,lteSib1Struct* inSib1Buf);
int decodeMSG5(uint8* inEncodedBuffer ,uint8 encodingLength, lteRrcConnSetupCompleteStruct *inMsg5Buf);
int decodeUlCCCHMsg(uint8* inEncodedBuffer ,uint8 encodingLength, lteUlCCCHMsgStruct *pUlCCCHMsg);
uint8* buildAndEncodeRrcConnReestabReject(uint8* outEncodedRrcConnReestabReject);
#endif //LTE_ASN1_HANDLER_H_
