/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: PKTAPI_HELPER.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-05.02.02-B3642 (2018/12/10)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __PKTAPI_HELPER_H__
#define __PKTAPI_HELPER_H__

/*****************************  INCLUDE FILES  *******************************/

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif


/*****************************  DEFINES **************************************/



/***************************  STRUCTURES *************************************/


/*****************************  FUNCTIONS ************************************/

/*--------------------------------------------------------------------------
	OctVc1PktApiHelperSessGetInst
		This function returns the instance of the specified session.

  f_pSession: IN pointer to session.
----------------------------------------------------------------------------*/
tPOCTVC1_PKT_API_INST	OctVc1PktApiHelperSessGetInst(
	tPOCTVC1_PKT_API_SESS							f_pSession );


/*--------------------------------------------------------------------------
	OctVc1PktApiHelperSessGetCnct
		This function returns the connection of the specified session.

  f_pSession: IN pointer to session.
----------------------------------------------------------------------------*/
tPOCTVC1_PKT_API_CNCT	OctVc1PktApiHelperSessGetCnct(
	tPOCTVC1_PKT_API_SESS							f_pSession );




/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* __PKTAPI_HELPER_H__*/
