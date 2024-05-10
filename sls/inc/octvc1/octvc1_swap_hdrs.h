/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

File: octvc1_swap_hdrs.h	

Copyright (c) 2019 Octasic Technologies Private Limited. All rights reserved.	

Description:	

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.	

Release: OCTSDR Software Development Kit OCTSDR_GSM-04.02.00-B3135 (2019/03/05)	

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/	
#ifndef __OCTVC1_SWAP_HDRS_H__
#define __OCTVC1_SWAP_HDRS_H__

#ifdef __cplusplus
extern "C" {
#endif

/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_macro.h"
#ifndef SWAP_UNUSED
#define SWAP_UNUSED(x) (void)(x);
#endif

/* START OF SWAP FILE HDR */

#include "../octdev_types_swap.h"
#include "../octdev_devices_swap.h"
#include "../octpkt/octpkt_hdr_swap.h"
#include "../octpkt/octpkt_hdrxl_swap.h"
#include "octvocnet_pkt_swap.h"
#include "octvc1_cursor_swap.h"
#include "octvc1_buffer_swap.h"
#include "octvc1_eth_swap.h"
#include "octvc1_handle_swap.h"
#include "octvc1_ip_swap.h"
#include "octvc1_vlan_swap.h"
#include "octvc1_list_swap.h"
#include "octvc1_msg_swap.h"
#include "octvc1_log_swap.h"
#include "octvc1_file_swap.h"
#include "octvc1_module_swap.h"
#include "octvc1_stream_swap.h"
#include "octvc1_tap_swap.h"
#include "octvc1_ipc_swap.h"
#include "octvc1_process_swap.h"
#include "octvc1_user_id_swap.h"
#include "octvc1_radio_swap.h"
#include "octvc1_transport_swap.h"
#include "octvc1_api_swap.h"
#include "ctrl/octvc1_ctrl_api_swap.h"
#include "main/octvc1_main_api_swap.h"
#include "main/octvc1_main_evt_swap.h"
#include "job/octvc1_job_api_swap.h"
#include "job/octvc1_job_evt_swap.h"
#include "hw/octvc1_hw_api_swap.h"
#include "hw/octvc1_hw_evt_swap.h"
#include "irsc/octvc1_irsc_api_swap.h"
#include "irsc/octvc1_irsc_evt_swap.h"
#include "rus/octvc1_rus_api_swap.h"
#include "rus/octvc1_rus_evt_swap.h"
#include "obm/octvc1_obm_api_swap.h"
#include "obm/octvc1_obm_evt_swap.h"
#include "gsm/octvc1_gsm_api_swap.h"
#include "gsm/octvc1_gsm_evt_swap.h"
#include "lte/octvc1_lte_api_swap.h"
#include "lte/octvc1_lte_evt_swap.h"
#include "3g_nodeb/octvc1_3g_nodeb_api_swap.h"
#include "3g_nodeb/octvc1_3g_nodeb_evt_swap.h"

/* END OF SWAP FILE HDR */
#ifdef __cplusplus
}

#endif

#endif /* __OCTVC1_SWAP_HDRS_H__ */
