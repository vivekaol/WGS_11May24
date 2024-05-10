/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: oct_etherApi.c

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <linux/sockios.h>
#include <netinet/in.h>
#include <signal.h>

#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include "oct_etherApi.h"
#include "oct_l1cIoInit.h"
#include "l1IntEnums.h"
#include "msgHeaderDef.h"

struct sockaddr_ll socket_address;

static sint32_t socket_address_handle;

pthread_mutex_t L1C_Ether_Mutex = PTHREAD_MUTEX_INITIALIZER;

//uint16_t g_txSeqNo = 0;

static void sigint(int signum)
{
   struct ifreq ifr; 
   printf("L1C: Terminated signal :%d received \n",signum);
   strncpy(ifr.ifr_name,&g_L1CConfigDB.deviceHost[0],5);
   if(ioctl(socket_address_handle,SIOCGIFFLAGS,&ifr) != 0)
   {
     printf("\nERROR Cannot get i/f flags for interface %s", g_L1CConfigDB.deviceHost);   
     exit(-1);
   }
   ifr.ifr_flags &= ~IFF_PROMISC;
   if(ioctl(socket_address_handle,SIOCSIFFLAGS,&ifr) != 0)
   {
     printf("\nERROR Cannot set i/fflags for interface %s", g_L1CConfigDB.deviceHost);   
     exit(-1);
   }
   if(ioctl(socket_address_handle,SIOCGIFFLAGS,&ifr) != 0)
   {
     printf("\nERROR Cannot get i/fflags for interface %s", g_L1CConfigDB.deviceHost);   
     exit(-1);
   }
   printf("\nMy i/f flags after termination = %x\n",ifr.ifr_flags);
   shutdown(socket_address_handle,SHUT_RDWR);
//   close(socket_address_handle);
   exit(0);
}

sint32_t SocketApp_Init(void)
{
   sint32_t s,ret;
   struct ifreq ifr;  
   
   socket_address_handle = s = socket(PF_PACKET, SOCK_RAW, htons(ETH_OCTASIC_L1API_PROTOCOL));

   if (s == -1) 
   { 
     printf("\n Error creating socket\n");
   }

   strncpy(ifr.ifr_name,&g_L1CConfigDB.deviceHost[0],5);
   if(ioctl(s,SIOCGIFINDEX,&ifr) != 0)
   {
   	printf("\nERROR Cannot get i/findex %s", g_L1CConfigDB.deviceHost);   
        exit(-1);
   }

   printf("\nMy i/findex = %d for deviceHost %s\n",ifr.ifr_ifindex, g_L1CConfigDB.deviceHost);
       
   /*prepare sockaddr_ll*/
   /*RAW communication*/
   socket_address.sll_family   = AF_PACKET;      
   /*we don't use a protocol above ethernet layer
   ->just use anything here*/
   socket_address.sll_protocol = htons(ETH_OCTASIC_L1API_PROTOCOL);       

   /*index of the network device
   see full code later how to retrieve it*/
   socket_address.sll_ifindex  = ifr.ifr_ifindex;

   /*ARP hardware identifier is ethernet*/
   socket_address.sll_hatype   = ARPHRD_ETHER;
        
   /*target is another host*/
   socket_address.sll_pkttype  = PACKET_OTHERHOST;

   /*address length*/
   socket_address.sll_halen    = ETH_ALEN;              
   /*MAC - begin*/
   socket_address.sll_addr[0]  = g_L1CConfigDB.l1DstMacAddr[0];
   socket_address.sll_addr[1]  = g_L1CConfigDB.l1DstMacAddr[1];
   socket_address.sll_addr[2]  = g_L1CConfigDB.l1DstMacAddr[2];
   socket_address.sll_addr[3]  = g_L1CConfigDB.l1DstMacAddr[3];
   socket_address.sll_addr[4]  = g_L1CConfigDB.l1DstMacAddr[4];
   socket_address.sll_addr[5]  = g_L1CConfigDB.l1DstMacAddr[5];

   /*MAC - end*/
   socket_address.sll_addr[6]  = 0x00;/*not used*/
   socket_address.sll_addr[7]  = 0x00;/*not used*/

   signal(SIGINT,sigint);

   if(ioctl(s,SIOCGIFFLAGS,&ifr) != 0)
   {
   	printf("\nERROR Cannot get i/fflags");   
        exit(-1);
   }

   printf("\nMy i/f flags = %x\n",ifr.ifr_flags);
   ifr.ifr_flags &= ~IFF_PROMISC;
   ifr.ifr_flags &= ~IFF_NOARP;
   if(ioctl(s,SIOCSIFFLAGS,&ifr) != 0)
   {
      printf("\nERROR Cannot set i/fflags");   
      exit(-1);
   }
   if(ioctl(s,SIOCGIFFLAGS,&ifr) != 0)
   {
   	printf("\nERROR Cannot get i/fflags");   
        exit(-1);
   }
   printf("\nMy i/f flags after reset = %x\n",ifr.ifr_flags);
   ret = bind(s,(struct sockaddr*)&socket_address,sizeof(socket_address));
   if(ret != 0)
   {
      printf("Binding ethernet address is failed?????\n");
   }
   else
   {
      printf("Binding ethernet address is success!!\n");
   }

   return s; 
      
}

sint32_t SocketApp_Send(uint8_t* buffer,uint32_t size_bytes,uint16_t type,uint16_t tailType)
{
   sint32_t ret = 0;
   uint32_t bytesToSend = size_bytes;
   uint32_t curPktCapacity, curPktOffset;
   short packet_type;
   struct ethhdr *eh;

   uint8_t segmentedSendBuffer[1024];
   uint8_t msgHeader[L1CAPI_MSGHDR_BYTES];
   uint8_t *pSegmentedPayloadStartPtr = NULL;
   uint16_t *pSequenceNoFieldPtr = NULL;   
   ret = ETH_ALEN;

   memcpy((void*)segmentedSendBuffer, (void*)(g_L1CConfigDB.l1DstMacAddr), ETH_ALEN);
   memcpy((void*)(segmentedSendBuffer+ETH_ALEN), (void*)(g_L1CConfigDB.l23SrcMacAddr), ETH_ALEN);

   pSegmentedPayloadStartPtr = segmentedSendBuffer + ETH_PACKET_HEADER_SIZE_BYTES;
   
   pSequenceNoFieldPtr = (uint16_t*)(segmentedSendBuffer +
   	                                 ETH_PACKET_MAC_ADDR_SIZE_BYTES + /*Src MAC and dec MAC address,12 bytes*/
   	                                 ETH_PACKET_PROTOCOL_SIZE_BYTES)/*packet type,2 bytes*/;

   /* buffer points to payload (incl. L1C header) and does not include MAC Addresses */
   memcpy((void*)msgHeader, (void*)buffer, L1CAPI_MSGHDR_BYTES);

   if(size_bytes <= 0 || (buffer == 0))
   {       
       return 0;
   }
   
   curPktCapacity = ETH_PACKET_PAYLOAD_SIZE_BYTES;
   curPktOffset = 0;
   
   /*pthread_mutex_lock(&L1C_Ether_Mutex);*/
   while(bytesToSend > 0)
   {
     memset(pSegmentedPayloadStartPtr, 0, ETH_PACKET_PAYLOAD_SIZE_BYTES);
     
     if(bytesToSend > curPktCapacity)
     {
       memcpy(pSegmentedPayloadStartPtr+curPktOffset, buffer, curPktCapacity);
       bytesToSend = bytesToSend - curPktCapacity;
       packet_type = type;
     }
     else
     {
       //memcpy(pSegmentedPayloadStartPtr+curPktOffset, buffer, bytesToSend);
       memcpy(pSegmentedPayloadStartPtr+curPktOffset, buffer, ETH_PACKET_PAYLOAD_SIZE_BYTES); //_MK_ FPCTRL Fix?
       bytesToSend = 0;
       packet_type = tailType;
     }
     
     if (curPktOffset>0)
     {
         memcpy(pSegmentedPayloadStartPtr, msgHeader, curPktOffset);
     }
     
     /*_MK_ g_txSeqNo removed*/
     /* *pSequenceNoFieldPtr = g_txSeqNo;*/
     /*g_txSeqNo = (g_txSeqNo + 1) & 0xffff;*/

     /*ETH L1C Packet Type*/
     *(pSequenceNoFieldPtr+0) = packet_type; 

     eh = (struct ethhdr *)segmentedSendBuffer;
     eh->h_proto = SWAP_ENDIAN_16(ETH_OCTASIC_L1API_PROTOCOL);
     ret = sizeof(struct ethhdr);       
     ret = sendto(socket_address_handle,segmentedSendBuffer,ETH_PACKET_SIZE,0,
                   (struct sockaddr*)&socket_address, sizeof(socket_address));
     if(ret == -1)
     {
       printf("L1C-IO: unable to send packet through ethernet!\n");
       break;
     }
     
     buffer += curPktCapacity;
     
     curPktCapacity = ETH_PACKET_PAYLOAD_SIZE_BYTES-L1CAPI_MSGHDR_BYTES;
     curPktOffset = L1CAPI_MSGHDR_BYTES;
     
   } //while(bytesToSend > 0)
   
   /*pthread_mutex_unlock(&L1C_Ether_Mutex);*/
   return ret;
}


sint32_t SocketApp_Recv(uint8_t* rcvbuffer,uint32_t size_bytes)
{
   sint32_t length; 

   for (;;) 
   {
      struct sockaddr_ll addr;
      socklen_t fromLen = sizeof(addr);
      memset(&addr, 0, sizeof(addr));
      length = recvfrom(socket_address_handle, rcvbuffer, size_bytes, 0, (struct sockaddr*)&addr, &fromLen);
      
      if (length < 0)
      {
         return length;
      }
      
      if (addr.sll_ifindex != socket_address.sll_ifindex) 
      {
         /* This socket is bound to a specific interface, but we are getting
          * frames sent to other interfaces on multi-NIC systems.
          * Log these unexpected frames. */
          printf("SocketApp_Recv: discarding frame from interface %d, src %02x:%02x:%02x:%02x:%02x:%02x\n",
		         (int)addr.sll_ifindex,
                  addr.sll_addr[0],
                  addr.sll_addr[1],
                  addr.sll_addr[2],
                  addr.sll_addr[3],
                  addr.sll_addr[4],
                  addr.sll_addr[5]);
          continue;
      }

      /* If the frame didn't come from the radio, discard it */
      if (0 != memcmp(addr.sll_addr, socket_address.sll_addr, ETH_ALEN))
      {
          continue;
      }

      return length;
   }
}

void SocketApp_Close(void)
{
   close(socket_address_handle);
}


