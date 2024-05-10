/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1c_codec.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Codec: Defines the entry point for the console application.

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include "L1CAPI_Validation.h"

void main()
{
	if(!cellSetupReqValidate())
		return 0;
	if(!prachSetupReqValidate())
		return 0;
	if(!sccpchSetupReqValidate())
		return 0;
	if(!phySharedCHReconfigReqValidate())
		return 0;
    if(!radiolinkSetupReqValidate())
	    return 0;
	if(!radiolinkReconfigPrepareValidate())
		return 0;	
	if(!radiolinkReconfigCommitValidate())
		return 0;
	if(!rlDeleteValidate())
		return 0;
	if(!genericRespValidate())
		return 0;
	if(!prachSetupRespValidate())
		return 0;
	if(!sccpchSetupRespValidate())
		return 0;
	if(!rlSetupRespValidate())
		return 0;
	if(!rlReconfigReadyValidate())
		return 0;
	if(!fpR4UlDchDataValidate())
		return 0;
	if(!fpR4DlPchDataValidate())
		return 0;
	if(!fpR5HsdschDataValidate())
		return 0;
	if(!fpR5HsCapReqValidate())
		return 0;
	if(!fpR5HsCapAllocValidate())
		return 0;
	printf("Codec validation success\n");
}
