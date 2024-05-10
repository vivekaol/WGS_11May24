/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_l1cIoApi.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control I/O APIs Implementation

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <memory.h>
#include "oct_l1cIoApi.h"
#include "oct_l1cIoDebug.h"
#include "oct_etherApi.h"
#include "oct_l1cIoInit.h"

#define MAX_BUCKET_LEN            (50000*4)

static uint16_t g_currentBFN;

static uint8_t packetBuffer[ETH_PACKET_SIZE];

/*HSUPA to reach 2Mbps,hold 25 * 1000bytes ethernet packet*/
static uint32_t bucketLen = 0;
static uint8_t recvBufBucket[MAX_BUCKET_LEN];
static uint8_t currentOngoingPort = L1API_PORT_NONE;

/* Functions ------------------------------------------------------------- */

L1API_Error_t L1API_Open(const char *pArgs, L1API_Handle_t *pHandle)
{
    uint8_t octasic_handshake_buffer[10];
	
    if(L1CReadConfigParams() == 0)
	  return L1API_CONFIG_FILE_ERROR;
    if(SocketApp_Init() == 0)
      return L1API_RAW_ETHERNET;
    if(SocketApp_Send(octasic_handshake_buffer,
	    sizeof(octasic_handshake_buffer),
	    SWAP_ENDIAN_16(L23_L1_ETH_HANDSHAKE_PACKET),
	    SWAP_ENDIAN_16(L23_L1_ETH_HANDSHAKE_PACKET))< 0)
    {
       printf("****L1C: Unable to handshake with L1!****\n");
       return L1API_RAW_ETHERNET;
    }	
    return L1API_NO_ERROR;	/* Success */
}

L1API_Error_t L1API_Close(L1API_Handle_t handle)
{
    SocketApp_Close();
    return L1API_NO_ERROR;
}

L1API_Error_t L1API_PollMsg(L1API_Handle_t handle,
			    uint32_t getMask,
			    uint32_t *pSetMask,
			    int32_t timeout)
{
    sint32_t length;
    uint32_t payloadLen;
    uint16_t * pTempShort;
    uint8_t * pEthPayloadStart;
    uint8_t * pTempBytes;
    uint16_t l1cPacketType;
    uint8_t putToBucket = 1;
    L1API_Error_t retError = L1API_NO_ERROR;

    *pSetMask = 0;

    length = SocketApp_Recv(packetBuffer,ETH_PACKET_SIZE);
    if(length > 0){
      pTempShort = (uint16_t *)packetBuffer;   
      pTempBytes = (uint8_t *)packetBuffer;
      pEthPayloadStart = pTempBytes + ETH_PACKET_HEADER_SIZE_BYTES; 
      l1cPacketType = SWAP_ENDIAN_16(pTempShort[ETH_PACKET_TYPE_OFFSET_BYTES>>1]);
      payloadLen = ETH_PACKET_PAYLOAD_SIZE_BYTES;
      switch(l1cPacketType)
      {
      case L1C_NBAP_CTRL_MSG_RX_PACKET:
      case L1C_NBAP_CTRL_EVNT_MSG_RX_PACKET:      
        if( (currentOngoingPort != L1API_PORT_NONE) && (currentOngoingPort != L1API_PORT_CPLANE_RSP)){
          retError = L1API_WRONG_PORT_DATA;
          break;
        }
        currentOngoingPort =  L1API_PORT_CPLANE_RSP;
        break;
      case L1C_FP_DATA_MSG_RX_PACKET:
        if( (currentOngoingPort != L1API_PORT_NONE) && (currentOngoingPort != L1API_PORT_UPLANE_UL)){
          retError = L1API_WRONG_PORT_DATA;
          break;
        }
	    currentOngoingPort =  L1API_PORT_UPLANE_UL;
	break;
      case L1C_OAM_CTRL_MSG_RX_PACKET:
        if( (currentOngoingPort != L1API_PORT_NONE) && (currentOngoingPort != L1API_PORT_OAM)){
          retError = L1API_WRONG_PORT_DATA;
          break;
        }
        currentOngoingPort =  L1API_PORT_OAM;
        break;
      case L1C_NBAP_CTRL_MSG_RX_TAIL_PACKET:
      case L1C_NBAP_CTRL_EVNT_MSG_RX_TAIL_PACKET:
        if(getMask & 1<<L1API_PORT_CPLANE_RSP){
          *pSetMask |= 1<<L1API_PORT_CPLANE_RSP;
        }
        if( (currentOngoingPort != L1API_PORT_NONE) && (currentOngoingPort != L1API_PORT_CPLANE_RSP)){
          retError = L1API_WRONG_PORT_DATA;
          break;
        }
        currentOngoingPort =  L1API_PORT_CPLANE_RSP;
        break;
	  case L1C_NBAP_CTRL_MSG_TX_TAIL_PACKET:
      case L1C_FP_DATA_MSG_RX_TAIL_PACKET:
        if(getMask & 1<<L1API_PORT_UPLANE_UL){
          *pSetMask |= 1<<L1API_PORT_UPLANE_UL;
        }
        if( (currentOngoingPort != L1API_PORT_NONE) && (currentOngoingPort != L1API_PORT_UPLANE_UL)){
          retError = L1API_WRONG_PORT_DATA;
          break;
        }
        currentOngoingPort =  L1API_PORT_UPLANE_UL;
        break;
      case L1C_OAM_CTRL_MSG_RX_TAIL_PACKET:
        break;
      case L1C_10MS_TTI:
        g_currentBFN = SWAP_ENDIAN_16(*(uint16_t *)(packetBuffer + ETH_PACKET_HEADER_SIZE_BYTES));//Read and Swap         
        if(getMask & (1 << L1API_PORT_BFN))
        {
            *pSetMask |= 1 << L1API_PORT_BFN;
        }
        putToBucket = 0;
        break;
      default:
        return L1API_NO_ERROR; /*handle unknown eth packet*/
      }/*switch end*/
      if(putToBucket){
         memcpy(&recvBufBucket[bucketLen],pEthPayloadStart,payloadLen);
         bucketLen += payloadLen;
         if(bucketLen > MAX_BUCKET_LEN){
           printf("L1C-IO:Internal buffer overflow.\n");
           bucketLen = 0;
           retError = L1API_INTERNAL_BUCKET_OVERFLOW;
           currentOngoingPort =  L1API_PORT_NONE;
         }
      }
    }
    if(retError != L1API_NO_ERROR){
      if(retError == L1API_WRONG_PORT_DATA){
         printf("L1C-IO:Wrong port data packet type %x received,ongoing port is %d.\n",l1cPacketType,currentOngoingPort);
      }
      currentOngoingPort = L1API_PORT_NONE;
      bucketLen = 0;
    }

    return retError;
}

L1API_Error_t L1API_SendMsg(L1API_Handle_t handle,
			    L1API_Port_t port,
			    uint32_t *pBuf,
			    uint32_t msgLen,
			    uint32_t bufLen)
{
    uint16_t packetType,tailType;

    switch(port)
    {
    case L1API_PORT_CPLANE_REQ:
      packetType = SWAP_ENDIAN_16(L1C_NBAP_CTRL_MSG_TX_PACKET);
      tailType = SWAP_ENDIAN_16(L1C_NBAP_CTRL_MSG_TX_TAIL_PACKET);
      break;
    case L1API_PORT_UPLANE_DL:
      packetType = SWAP_ENDIAN_16(L1C_FP_DATA_MSG_TX_PACKET);
      tailType = SWAP_ENDIAN_16(L1C_FP_DATA_MSG_TX_TAIL_PACKET);
      break;
    default:
      printf("L1C-IO:The port %d is invalid.\n",port);
      return L1API_INVALID_PORT;
    }
    if(SocketApp_Send((uint8_t *)pBuf,msgLen,packetType,tailType)< 0)
    {
        return L1API_RAW_ETHERNET;
    }

    return L1API_NO_ERROR;
}


L1API_Error_t L1API_RecvMsg(L1API_Handle_t handle,
			    L1API_Port_t port,
			    uint32_t *pBuf,
			    uint32_t len,
			    uint32_t *pLen)
{   
    uint32_t copiedLen;
    uint16_t sizeofMsg = *((uint16_t *)(&recvBufBucket[0]));
    switch(port)
    {
    case L1API_PORT_UPLANE_UL:
    case L1API_PORT_CPLANE_RSP:
      if(currentOngoingPort != port){
        printf("L1C-IO:The port %d doesn't have any data,current ongoing port is %d.\n",port,currentOngoingPort);
        return L1API_PORT_NO_DATA;
      }
      copiedLen = SWAP_ENDIAN_16(sizeofMsg) + 8;
      if(len < copiedLen){
        printf("L1C-IO:The buffer passed in for port %d doesn't have sufficient size.\n",port);
        return L1API_BUFFER_INSUFFICIENT;
      }
      memcpy((uint8_t*)pBuf,recvBufBucket,copiedLen);
      *pLen = copiedLen;
      bucketLen = 0;
      currentOngoingPort =  L1API_PORT_NONE;
      break;
    case L1API_PORT_BFN:
      *pLen = 2;
      *pBuf = (uint32_t)(g_currentBFN<<16);
      break;
    default:
      printf("L1C-IO:The port %d is invalid.\n",port);
      return L1API_INVALID_PORT;
    }
    return L1API_NO_ERROR;
}


