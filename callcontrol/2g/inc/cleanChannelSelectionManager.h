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
* File Name   : cleanChannelSelectionManager.h
 *
* Description : Function to parse and find clean channel parameters
*
* History     :
*
* Date                                  Author                     Details
* ----------------------------------------------------------------------------------------
* 05/12/2014          					Anand Kashikar            Initial File Creation
*#########################################################################################
*/
#ifndef CLEANCHANNELSELECTIONMGR_H_
#define CLEANCHANNELSELECTIONMGR_H_

#include "gsmCommon.h"

signed char parseGsmSysInfo(fxL2gPlmn* inPlmn, tOCT_UINT16* Lac);
void selectCleanChannelFromParsedData(tOCT_UINT16 *commonArfcn , tOCT_UINT8* mappedBand);

#endif
