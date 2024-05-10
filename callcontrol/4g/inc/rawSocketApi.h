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
* File Name   : rawSocketApi.h
 *
* Description : Raw Socket receive & send API functions
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 11/01/2015          			Anand Kashikar       File Creation
*############################################################################
*/

#ifndef _RAW_SOCKET_API_H_
#define _RAW_SOCKET_API_H_

#include "lteL1Defs.h"
#include "oct_ltefapimacphyinterface.h"

/*
Ethernet Header ==>
48 bit Destination MAC
48 bit Source MAC
16 bit Ethernet Type: Set to 0x5201
-------------------------------------
16 bit Reserved Ethernet Header: Set to 0x0000
-------------------------------------
32 bit Octasic Packet Header
-------------------------------------
4 bit PT: Set to 0x2
4 bit R: Set to 0x0
8 bit Format: Set to 0x00
16 bit Packet Length: (Octasic Packet Header Length Bytes + Payload Length Bytes)
                                     =(4 + Payload Length Bytes)
-------------------------------------
Payload: FAPI Message aligned to 32 bit boundary
*/
#define LTE_OCT_SDR_ETH_PROTOCOL 0x5201
#define LTE_OCT_SDR_ETH_PTRBITS 0x2000
#define LTE_OCT_SDR_ETH_RESERVED 0x0000
#define LTE_OCT_SDR_ETH_HEADER_SIZE 4

// LTE Ethernet Frame
typedef struct
{
    uint8 destMACAddress[6];
    uint8 srcMACAddress[6];
    uint16 lteEtherType; //0x5201
    uint16 lteReserved; // 0x0000
    uint16 ltePktHeader; //0x2000
    uint16 ltePacketLength; // 4 + actual message length

}lteEthernetFrameHeader;

typedef struct
{
   uint8 l23SrcMacAddr[6];
   uint8 l1DstMacAddr[6];
}lteL1cConfigParams;

/* Dependencies ---------------------------------------------------------- */

typedef enum			/* L1API error codes */
{
  L1IF_NO_ERROR,
  L1IF_RAW_ETHERNET,
  L1IF_WRONG_PORT_DATA,
  L1IF_INTERNAL_BUCKET_OVERFLOW,
  L1IF_INVALID_PORT,
  L1IF_PORT_NO_DATA,
  L1IF_BUFFER_INSUFFICIENT,
  L1IF_CONFIG_FILE_ERROR
} l1IfErrors;


#define START_OF_LTE_FAPI_MESSAGE sizeof(lteEthernetFrameHeader)
#define SIZE_OF_LTE_FAPI_MESSAGE(msgLen) (SIZE_TOCT_FAPI_L1_API_MSG + msgLen)

/* Functions ------------------------------------------------------------- */

l1IfErrors lteOpenRawSocketInterface(void);
l1IfErrors lteCloseRawSocketInterface(void);
uint8 L1CRead4gConfigParams();
sint32 SocketApp_Init4g(void);
sint32 SocketApp_Send4g(uint8* buffer);
sint32 SocketApp_Recv4g(uint8* buffer,uint32 size_bytes);
void SocketApp_Close4g(void);
void buildLteEthernetHeader(uint8 *msgBuf, uint16 msgLen);
#endif
