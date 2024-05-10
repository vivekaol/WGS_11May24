/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_3g_nodeb_evt_swap.h	

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.02.00-B489 (2018/03/20)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_3G_NODEB_EVT_SWAP_H__
#define __OCTVC1_3G_NODEB_EVT_SWAP_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "../octvc1_swap_hdrs.h"
#include "octvc1_3g_nodeb_evt.h"

/*********************************  MACROS  **********************************/


#if defined( _OCT_ENDIAN_TYPE_LE_ )
#define mOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT_SWAP( _f_pParms ){ 	tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT * pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT = (_f_pParms); SWAP_UNUSED(pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)\
	{ mOCTVC1_EVENT_HEADER_SWAP( &((tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT *)pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)->Header ); }  \
	((tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT *)pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)->hCell = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT *)pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)->hCell); \
	((tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT *)pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)->ulUserId = \
		mOCT_SWAP32_IF_LE(((tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT *)pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)->ulUserId); \
	{ mOCTVC1_3G_NODEB_CELL_STATE_ENUM_SWAP( &((tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT *)pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)->OldState ); }  \
	{ mOCTVC1_3G_NODEB_CELL_STATE_ENUM_SWAP( &((tOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT *)pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT)->NewState ); }  \
}
#else
#define mOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT_SWAP( pOCTVC1_3G_NODEB_MSG_CELL_STATE_CHANGE_EVT )
#endif /* _OCT_ENDIAN_TYPE_LE_ */

#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_3G_NODEB_EVT_SWAP_H__ */
