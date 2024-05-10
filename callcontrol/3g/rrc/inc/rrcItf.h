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
 * File Name   : rrcItf.h
 *
 * Description : This file provides interface functionality of Radio Resource
 *               Control (RRC) stack for ImsiCatcher application.
 *               
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 26/09/2014	        Ashutosh Samal              File Creation
 *############################################################################
 */
#ifndef _RRC_ITF_H_
#define _RRC_ITF_H_

#include "rrc.h"
#include "fxLSocketInterfaceApi.h"

/*
 * Function Prototypes
 */
extern void configureRrcIdentityList (fxLConfigureIdentityListCmd *pIdentityList);
extern void initializeRrcContext (void);
extern void handleUeEvents (unsigned int ueIndex, RrcUeEvent ueEvent);
extern void autoConfigureRrcIdentityList (fxL3gAutoConfigCmd *pIdentityList);
extern unsigned int getNumOfUeLatched (void);
#endif
