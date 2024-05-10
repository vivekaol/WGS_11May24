/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_UDP.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_UDP_H__
#define __OCTVC1_UDP_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"


/************************  COMMON DEFINITIONS  *******************************/

#define cOCTVC1_UDP_PORT_INVALID							cOCTDEV_UDP_PORT_INVALID	 	/* Invalid UDP port specification. */

/*-------------------------------------------------------------------------------------
	tOCTVC1_UDP_ADDRESS : 	UDP address structure
-------------------------------------------------------------------------------------*/
#define tOCTVC1_UDP_ADDRESS									tOCTDEV_UDP_ADDRESS


                
/*--------------------------------------------------------------------------
	SWAP directive (for compatibility reason)
----------------------------------------------------------------------------*/
#define mOCTVC1_UDP_ADDRESS_SWAP mOCTDEV_UDP_ADDRESS_SWAP
            
              

#endif /* __OCTVC1_UDP_H__ */

