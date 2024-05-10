/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_etherApi.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Ethernet Application Header file

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef _OCT_ETHERAPI_H_
#define _OCT_ETHERAPI_H_

#include "l1capi_typedef.h"
#include "oct_etherTypes.h"

/*#define L1C_ETH_FRAME_LEN 1536*/
#ifdef OCT1010_BOARD
#define ETH_PACKET_PAYLOAD_SIZE_BYTES   (1000)
#else
#define ETH_PACKET_PAYLOAD_SIZE_BYTES   (992) //OCT2224 Board
#endif

#define ETH_PACKET_MAC_ADDR_SIZE_BYTES  (12)
#define ETH_PACKET_PROTOCOL_SIZE_BYTES  (2)
#define ETH_PACKET_TYPE_SIZE_BYTES      (2)
#define ETH_PACKET_TYPE_OFFSET_BYTES    (14)
#define ETH_PACKET_HEADER_SIZE_BYTES    (ETH_PACKET_MAC_ADDR_SIZE_BYTES + ETH_PACKET_PROTOCOL_SIZE_BYTES + ETH_PACKET_TYPE_SIZE_BYTES)
#define ETH_PACKET_SIZE                 (ETH_PACKET_HEADER_SIZE_BYTES + ETH_PACKET_PAYLOAD_SIZE_BYTES)

#define DEVICE_HOST "eth0"

/*Host Ethernet TX Message*/
#define L1C_NBAP_CTRL_MSG_TX_PACKET		  ETH_L1C_NBAP_CTRL_MSG_TX_PACKET
#define L1C_NBAP_CTRL_MSG_TX_TAIL_PACKET  ETH_L1C_NBAP_CTRL_MSG_TX_TAIL_PACKET
#define L1C_FP_DATA_MSG_TX_PACKET		  ETH_L1C_NBAP_CTRL_MSG_TX_PACKET
#define L1C_FP_DATA_MSG_TX_TAIL_PACKET	  ETH_L1C_NBAP_CTRL_MSG_TX_TAIL_PACKET
#define L1C_OAM_CTRL_MSG_TX_PACKET		  ETH_L1C_OAM_CTRL_MSG_TX_PACKET
#define L1C_OAM_CTRL_MSG_TX_TAIL_PACKET	  ETH_L1C_OAM_CTRL_MSG_TX_TAIL_PACKET
#define L23_L1_ETH_HANDSHAKE_PACKET       ETH_L23_L1_ETH_HANDSHAKE_PACKET

/*Host Ethernet RX Message*/
#define L1C_NBAP_CTRL_MSG_RX_PACKET		  ETH_L1C_NBAP_CTRL_MSG_RX_PACKET
#define L1C_NBAP_CTRL_MSG_RX_TAIL_PACKET  ETH_L1C_NBAP_CTRL_MSG_RX_TAIL_PACKET
#define L1C_NBAP_CTRL_EVNT_MSG_RX_PACKET          ETH_L1C_NBAP_CTRL_EVNT_MSG_RX_PACKET
#define L1C_NBAP_CTRL_EVNT_MSG_RX_TAIL_PACKET     ETH_L1C_NBAP_CTRL_EVNT_MSG_RX_TAIL_PACKET
#define L1C_FP_DATA_MSG_RX_PACKET		  ETH_L1C_FP_DATA_MSG_RX_PACKET
#define L1C_FP_DATA_MSG_RX_TAIL_PACKET	  ETH_L1C_FP_DATA_MSG_RX_TAIL_PACKET
#define L1C_OAM_CTRL_MSG_RX_PACKET		  ETH_L1C_OAM_CTRL_MSG_RX_PACKET
#define L1C_OAM_CTRL_MSG_RX_TAIL_PACKET	  ETH_L1C_OAM_CTRL_MSG_RX_TAIL_PACKET
#define L1C_10MS_TTI                      ETH_L1C_10MS_TTI

sint32_t SocketApp_Init(void);
sint32_t SocketApp_Send(uint8_t* buffer,uint32_t size_bytes,uint16_t type,uint16_t tailType);
sint32_t SocketApp_Recv(uint8_t* buffer,uint32_t size_bytes);
void SocketApp_Close(void);

#endif
