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
* File Name   : rawSocketApi.c
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
#include <linux/filter.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sched.h>
#include <unistd.h>
#include "rawSocketApi.h"
#include "logManager.h"
#include "oct_l1cIoInit.h"
#define MAX_L1C_CONFIG_PARAMETERS (20)
#define LTE_ETHERNET_PACKET_LENGTH 16

struct sockaddr_ll socket_address;
volatile sint32 socketAddressHandle = -1;
extern L1C_CONFIG_DB  g_L1CConfigDB;
extern volatile int exitLteApp;
static int initLteThreadForRx = FALSE;
extern void buildAndSendPhyParamReq();
void setNetworkDriverPriorityForLte(uint8 setPriority)
{
	if(setPriority == TRUE)
	{
		system("echo 7 > /sys/devices/platform/enet.0/net/eth0/queues/rx-0/rps_cpus");
		system("echo 8 > /proc/irq/150/smp_affinity");
		system("chrt -pf 90 `pidof irq/150-enet`");
		system("taskset -p 8 `pidof irq/150-enet`");
		system("chrt -pf 89 `pidof ksoftirqd/3`");
	}
	else
	{
		system("echo 0 > /sys/devices/platform/enet.0/net/eth0/queues/rx-0/rps_cpus");
		system("echo f > /proc/irq/150/smp_affinity");
		system("chrt -pf 50 `pidof irq/150-enet`");
		system("taskset -p 15 `pidof irq/150-enet`");
		system("chrt -pf 1 `pidof ksoftirqd/3`");
	}
	return;
}

l1IfErrors lteOpenRawSocketInterface(void)
{
    if(socketAddressHandle != -1)
    {
    	SocketApp_Close4g();
    }
	setNetworkDriverPriorityForLte(TRUE);

    if(SocketApp_Init4g() == -1)
    {
      return L1IF_RAW_ETHERNET;
    }
 
    return L1IF_NO_ERROR;	/* Success */
}

l1IfErrors lteCloseRawSocketInterface(void)
{
    SocketApp_Close4g();
    return L1IF_NO_ERROR;
}


static void sigIntHandler(int signum)
{
   struct ifreq ifr; 

   logPrint(LOG_INFO,"L1C: Terminated signal :%d received \n",signum);
   assert(socketAddressHandle != -1);
   memset(&ifr , 0 , sizeof(struct ifreq));
   strncpy(ifr.ifr_name, (char *)&g_L1CConfigDB.deviceHost[0], 5);
   if(ioctl(socketAddressHandle,SIOCGIFFLAGS,&ifr) == -1)
   {
     logPrint(LOG_INFO,"\nERROR Cannot get i/f flags");
     assert(0);
   }
   ifr.ifr_flags &= ~IFF_PROMISC;
   if(ioctl(socketAddressHandle,SIOCSIFFLAGS,&ifr) == -1)
   {
     logPrint(LOG_INFO,"\nERROR Cannot set i/f flags");
     assert(0);
   }
   if(ioctl(socketAddressHandle,SIOCGIFFLAGS,&ifr) == -1)
   {
     logPrint(LOG_INFO,"\nERROR Cannot get i/f flags");
     assert(0);
   }
   logPrint(LOG_INFO,"\nMy i/f flags after termination = %x\n",ifr.ifr_flags);
   shutdown(socketAddressHandle,SHUT_RDWR);
   close(socketAddressHandle);
   socketAddressHandle = -1;
   assert(0);
}

sint32 SocketApp_Init4g(void)
{
   sint32 ret , enable = 1;
   struct ifreq ifr;  

   socketAddressHandle = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

   if (socketAddressHandle == -1)
   { 
	   logPrint(LOG_INFO,"\n Error creating socket\n");
	   assert(0);
   }
   /* Reuse the address */
   if (setsockopt (socketAddressHandle, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
   {
     printf("SocketApp_Init4g : Error : failed to set socket option for reuse\n");
   }
   logPrint(LOG_INFO,"SocketApp_Init: Socket_Fd = %d\n" , socketAddressHandle);
   memset(&ifr , 0 , sizeof(struct ifreq));
   strncpy(ifr.ifr_name, (char *)&g_L1CConfigDB.deviceHost[0], 5);
   if(ioctl(socketAddressHandle,SIOCGIFINDEX,&ifr) == -1)
   {
	   logPrint(LOG_INFO,"\nERROR Cannot get i/f index\n");
	   logPrint(LOG_INFO,"\nPlease update the correct L1-stack interface in config l1c_cfg_parm.txt\n");
	   assert(0);
   }

   logPrint(LOG_INFO,"My i/f index = %d\n",ifr.ifr_ifindex);
   /*prepare sockaddr_ll*/
   /*RAW communication*/
   socket_address.sll_family   = AF_PACKET;     
   /*we don't use a protocol above ethernet layer
   ->just use anything here*/
   socket_address.sll_protocol = htons(LTE_OCT_SDR_ETH_PROTOCOL); //htons(ETH_P_ALL);

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

   signal(SIGINT,sigIntHandler);

   if(ioctl(socketAddressHandle,SIOCGIFFLAGS,&ifr) != 0)
   {
   	  logPrint(LOG_INFO,"\nERROR Cannot get i/f flags\n");
   	  assert(0);
   }

   logPrint(LOG_INFO,"My i/f flags = %x\n",ifr.ifr_flags);
   ifr.ifr_flags &= ~IFF_PROMISC;
   ifr.ifr_flags &= ~IFF_NOARP;
   if(ioctl(socketAddressHandle,SIOCSIFFLAGS,&ifr) != 0)
   {
      logPrint(LOG_INFO,"\nERROR Cannot set i/f flags");
      assert(0);
   }
   if(ioctl(socketAddressHandle,SIOCGIFFLAGS,&ifr) != 0)
   {
   	  logPrint(LOG_INFO,"\nERROR Cannot get i/f flags\n");
   	  assert(0);
   }
   logPrint(LOG_INFO,"My i/f flags after reset = %x\n\n",ifr.ifr_flags);

   uint32 mac0 = 0;
   uint32 mac1 = 0;
   struct sock_filter BPF_code[13];
   struct sock_fprog filter; 

   memcpy(&mac1, &g_L1CConfigDB.l1DstMacAddr[2], 4);
   memcpy(&mac0, &g_L1CConfigDB.l1DstMacAddr[0], 2);
   mac1 = htonl(mac1);
   mac0 = htons(mac0);

   BPF_code[0] = (struct sock_filter) { 0x20, 0, 0, 0x00000008 };
   BPF_code[1] = (struct sock_filter) { 0x15, 0, 2, mac1 };
   BPF_code[2] = (struct sock_filter) { 0x28, 0, 0, 0x00000006 };
   BPF_code[3] = (struct sock_filter) { 0x15, 7, 0, mac0 };
   BPF_code[4] = (struct sock_filter) { 0x20, 0, 0, 0x00000002 };
   BPF_code[5] = (struct sock_filter) { 0x15, 0, 2, mac1 };
   BPF_code[6] = (struct sock_filter) { 0x28, 0, 0, 0x00000000 };
   BPF_code[7] = (struct sock_filter) { 0x15, 3, 4, mac0 };
   BPF_code[8] = (struct sock_filter) { 0x15, 0, 3, 0xffffffff };
   BPF_code[9] = (struct sock_filter) { 0x28, 0, 0, 0x00000000 };
   BPF_code[10] = (struct sock_filter) { 0x15, 0, 1, 0x0000ffff };
   BPF_code[11] = (struct sock_filter) { 0x6, 0, 0, 0x0000ffff };
   BPF_code[12] = (struct sock_filter) { 0x6, 0, 0, 0x00000000 };
    
   filter.len = 13;
   filter.filter = BPF_code;
   
   ret = setsockopt(socketAddressHandle, SOL_SOCKET, SO_ATTACH_FILTER,
                    &filter, sizeof(filter));
   if(0 != ret)
   {
      logPrint(LOG_INFO,"Setting MAC Address Filtering is failed\n");
   }

   ret = bind(socketAddressHandle,(struct sockaddr*)&socket_address,sizeof(socket_address));
   //ret = setsockopt(socketAddressHandle, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr));
   if(ret != 0)
   {
      logPrint(LOG_INFO,"Binding ethernet address is failed?????\n");
   }
   else
   {
      logPrint(LOG_INFO,"Binding ethernet address is success!!\n\n");
   }
   initLteThreadForRx = FALSE;
   return socketAddressHandle;
      
}

sint32 SocketApp_Send4g(uint8* buffer)
{
   sint16 ret = -1 , pktLen = 0;
   lteEthernetFrameHeader *pkt = (lteEthernetFrameHeader*)buffer;
   pktLen = LTE_ETHERNET_PACKET_LENGTH + ntohs(pkt->ltePacketLength) + 4;

   // Send ethernet packet
   if(socketAddressHandle != -1)
   ret = sendto(socketAddressHandle, buffer, pktLen, 0,
                   		(struct sockaddr*)&socket_address, sizeof(socket_address));
   if(ret == -1)
   {
      logPrint(LOG_ERR,"L1C-IO: unable to send packet through ethernet!\n");
   }
     
   return ret;
}



sint32 SocketApp_Recv4g(uint8* rcvbuffer,uint32 size_bytes)
{
   sint32 length = -1;
   struct sockaddr_ll addr;
   socklen_t fromLen = sizeof(addr);
   if(initLteThreadForRx == FALSE)
   {
	   buildAndSendPhyParamReq();
	   initLteThreadForRx = TRUE;
   }
   while(TRUE)
   {
	  if((exitLteApp == TRUE)||(socketAddressHandle == -1))
	  {
		  length = -1;
		  break;
	  }
	  memset(&addr, 0, sizeof(addr));
      length = recvfrom(socketAddressHandle, rcvbuffer, size_bytes, 0, (struct sockaddr*)&addr, &fromLen);
      if((exitLteApp == TRUE)||(socketAddressHandle == -1))
	  {
		  length = -1;
		  break;
	  }

      if (length <= 0)
      {
         return length;
      }
      
      if(addr.sll_ifindex != socket_address.sll_ifindex) 
      {
         // This socket is bound to a specific interface, but we are getting
         //  frames sent to other interfaces on multi-NIC systems.
          // Log these unexpected frames. 
          logPrint(LOG_INFO,"SocketApp_Recv: discarding frame from interface %d, src %02x:%02x:%02x:%02x:%02x:%02x\n",
		         (int)addr.sll_ifindex,
                  addr.sll_addr[0],
                  addr.sll_addr[1],
                  addr.sll_addr[2],
                  addr.sll_addr[3],
                  addr.sll_addr[4],
                  addr.sll_addr[5]);
          continue;
      }

      // If the frame didn't come from the radio, discard it
      if (0 != memcmp(addr.sll_addr, socket_address.sll_addr, ETH_ALEN))
      {
          logPrint(LOG_INFO,"SocketApp_Recv: discarding frame, src %02x:%02x:%02x:%02x:%02x:%02x\n",
                 addr.sll_addr[0],
                 addr.sll_addr[1],
                 addr.sll_addr[2],
                 addr.sll_addr[3],
                 addr.sll_addr[4],
                 addr.sll_addr[5]);
          continue;
      }

      return length;
   }

   return length;
}

/*
sint32 SocketApp_Recv4g(uint8* rcvbuffer,uint32 size_bytes)
{
   int SelectResults = -1 , max_sd = 0 , length = -1;
   fd_set   readfds ;
   struct sockaddr_ll addr;
   socklen_t fromLen = sizeof(addr);
   struct timeval tv = {0, 5000};

   while(TRUE)
   {
	  if(socketAddressHandle == -1)
		  break;
      memset(&addr, 0, sizeof(addr));
      //clear the socket set
      FD_ZERO(&readfds);
      //add server socket to set
      FD_SET(socketAddressHandle, &readfds);
      max_sd = socketAddressHandle;

      //wait for an activity on one of the sockets , timeout is 1sec , so wait for 1sec
      SelectResults = select( max_sd + 1 , &readfds , NULL , NULL , &tv);
   	  if(SelectResults >= 0 )
	  {
   		 if(socketAddressHandle == -1)
   			  break;

		 if(FD_ISSET(socketAddressHandle,&readfds))
		 {
	  		 if(socketAddressHandle == -1)
	   			  break;

			  length = recvfrom(socketAddressHandle, rcvbuffer, size_bytes, MSG_DONTWAIT, (struct sockaddr*)&addr, &fromLen);

			  if (length <= 0)
			  {
				 continue;
			  }
			  else
			  {
				  return length;
			  }
		 }
	  }
   	  else
   	  {
   		length = -1;
   		logPrint(LOG_DEBUG , "Select Timeout on LTE Raw Socket\n");
   		break;
   	  }
   }

   return length;
}
*/
void SocketApp_Close4g(void)
{
   //printf("4G-Raw Socket Closed\n");
	if(socketAddressHandle != -1)
	{
		shutdown(socketAddressHandle,SHUT_RDWR);
		close(socketAddressHandle);
	}
   socketAddressHandle = -1;
   initLteThreadForRx = FALSE;
  // setNetworkDriverPriorityForLte(FALSE);
}

void buildLteEthernetHeader(uint8 *msgBuf, uint16 msgLen)
{
	lteEthernetFrameHeader *lteHdr = (lteEthernetFrameHeader*)msgBuf;
	memcpy(lteHdr->destMACAddress , g_L1CConfigDB.l1DstMacAddr , 6);
	memcpy(lteHdr->srcMACAddress , g_L1CConfigDB.l23SrcMacAddr , 6);
	lteHdr->lteEtherType = htons(LTE_OCT_SDR_ETH_PROTOCOL);
	lteHdr->lteReserved = LTE_OCT_SDR_ETH_RESERVED;
	lteHdr->ltePktHeader = htons(LTE_OCT_SDR_ETH_PTRBITS);
	lteHdr->ltePacketLength = htons(LTE_OCT_SDR_ETH_HEADER_SIZE + msgLen);
}
