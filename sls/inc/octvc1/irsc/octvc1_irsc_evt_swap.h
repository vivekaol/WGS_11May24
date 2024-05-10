/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_irsc_evt_swap.h	

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_IRSC_EVT_SWAP_H__
#define __OCTVC1_IRSC_EVT_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_swap_hdrs.h"
#include "octvc1_irsc_evt.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT_SWAP( _f_pParms ){ 	tOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT * pOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT = (_f_pParms); SWAP_UNUSED(pOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT)\
	{ mOCTVC1_EVENT_HEADER_SWAP( &((tOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT *)pOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT)->Header ); }  \
	((tOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT *)pOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT)->hProcess = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT *)pOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT)->hProcess); \
}
#else
#define mOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT_SWAP( pOCTVC1_IRSC_MSG_PROCESS_DUMP_EVT )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_IRSC_EVT_SWAP_H__ */
