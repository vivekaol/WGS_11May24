/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_IP.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_IP_H__
#define __OCTVC1_IP_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
	tOCTVC1_IP_VERSION_ENUM : 	IP versions
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IP_VERSION_ENUM								tOCTDEV_IP_VERSION_ENUM

#define cOCTVC1_IP_VERSION_ENUM_4							cOCTDEV_IP_VERSION_ENUM_4	
#define cOCTVC1_IP_VERSION_ENUM_6							cOCTDEV_IP_VERSION_ENUM_6	
#define cOCTVC1_IP_VERSION_ENUM_INVALID						cOCTDEV_IP_VERSION_ENUM_INVALID	

/*-------------------------------------------------------------------------------------
	tOCTVC1_IP_ADDRESS : 	IP address structure
-------------------------------------------------------------------------------------*/
#define tOCTVC1_IP_ADDRESS									tOCTDEV_IP_ADDRESS


                
/*--------------------------------------------------------------------------
	SWAP directive (for compatibility reason)
----------------------------------------------------------------------------*/
#define mOCTVC1_IP_ADDRESS_SWAP mOCTDEV_IP_ADDRESS_SWAP
            
              

#endif /* __OCTVC1_IP_H__ */

