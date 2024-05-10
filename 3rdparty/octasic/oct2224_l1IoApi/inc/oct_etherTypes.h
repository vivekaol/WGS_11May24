/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_etherTypes.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control I/O Ethernet Protocol and Packet Types

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _OCT_ETHERTYPES_H_
#define _OCT_ETHERTYPES_H_

#define ETH_OCTASIC_L1API_PROTOCOL            (0xcdab) 
/*Host Ethernet TX Message*/
#define ETH_L1C_NBAP_CTRL_MSG_TX_PACKET		  (0xe000)
#define ETH_L1C_NBAP_CTRL_MSG_TX_TAIL_PACKET  (0xe001)
#define ETH_L1C_OAM_CTRL_MSG_TX_PACKET		  (0xe004)
#define ETH_L1C_OAM_CTRL_MSG_TX_TAIL_PACKET	  (0xe005)
#define ETH_L23_L1_ETH_HANDSHAKE_PACKET       (0xf00f)

#define ETH_OCTASIC_L1_DUMP_REQUEST			  (0xf00d)

/*Host Ethernet RX Message*/
#define ETH_L1C_NBAP_CTRL_MSG_RX_PACKET		  (0xd000)
#define ETH_L1C_NBAP_CTRL_MSG_RX_TAIL_PACKET  (0xd001)
#define ETH_L1C_NBAP_CTRL_EVNT_MSG_RX_PACKET      (0xf000)
#define ETH_L1C_NBAP_CTRL_EVNT_MSG_RX_TAIL_PACKET (0xf001)
#define ETH_L1C_FP_DATA_MSG_RX_PACKET		  (0xd002)
#define ETH_L1C_FP_DATA_MSG_RX_TAIL_PACKET	  (0xd003)
#define ETH_L1C_OAM_CTRL_MSG_RX_PACKET		  (0xd004)
#define ETH_L1C_OAM_CTRL_MSG_RX_TAIL_PACKET	  (0xd005)
#define ETH_L1C_10MS_TTI                      (0xd006)

#define ETH_OCTASIC_L1_DUMP_READY             (0xfeed)
#define ETH_OCTASIC_L1_CORE_ASSERTION         (0xdead)

#endif //#ifndef _OCT_ETHERTYPES_H_
