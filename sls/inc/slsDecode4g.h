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
#include "lteAsn1Def.h"

void decodeBcchData(uint8* asn1EncodedBuf, uint16 bufLength , lteServingCellStruct* servingCell);
void sendLteSysInfoInd(void);
#endif /* LTE_ASN1_INTFC_HANDLER_H_ */
