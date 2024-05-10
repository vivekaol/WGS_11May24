/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: Octsamples_string_utils.c

$ Octasic_Copyright: $
    
Description:

    String utility functions.

$ Octasic_Confidentiality: $

$ Octasic_Release: $

$Revision: 37787 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/***************************  INCLUDE FILES  *********************************/

#include <stdio.h>
#include <string.h>

/* Vocallo samples' common header files */
#include "../inc/octsamples_string_utils.h"

/***************************  PUBLIC FUNCTIONS  ******************************/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesMacAddr2Str

Description:    Converts a MAC address to a string.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesMacAddr2Str(char             *f_pszMacAddr,
                              const tOCT_UINT8 f_abyMacAddr[6])
{
    sprintf(f_pszMacAddr, "%02x:%02x:%02x:%02x:%02x:%02x",
            f_abyMacAddr[0],
            f_abyMacAddr[1],
            f_abyMacAddr[2],
            f_abyMacAddr[3],
            f_abyMacAddr[4],
            f_abyMacAddr[5]);
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesMacAddr2Str

Description:    Converts a string to aMAC address.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesStr2MacAddr(tOCT_UINT8 f_abyMacAddr[6],
                              const char *f_pszMacAddr)
{
	if( f_pszMacAddr )
	{
		tOCT_UINT32 aulMac[6];
		int i=0;
	
		if( f_pszMacAddr[2] == ':' )
		{
			sscanf(f_pszMacAddr, "%02x:%02x:%02x:%02x:%02x:%02x",
				&aulMac[0],&aulMac[1],&aulMac[2],
				&aulMac[3],&aulMac[4],&aulMac[5] );
		}
		else if( f_pszMacAddr[2] == '-' )
		{
			sscanf(f_pszMacAddr, "%02x-%02x-%02x-%02x-%02x-%02x",
				&aulMac[0],&aulMac[1],&aulMac[2],
				&aulMac[3],&aulMac[4],&aulMac[5] );
		}
		for(i=0;i<6;i++)
		{
			f_abyMacAddr[i] = (tOCT_UINT8)aulMac[i];
		}
		
	}
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesIpAddr2Str

Description:    Converts an IP address to a string.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesIpAddr2Str(char                     *f_pszIpAddr,
                             const tOCTVC1_IP_ADDRESS *f_pIpAddr)
{
    unsigned int auiIpv6Fields[8];
    unsigned int i,uiSemiColonRequiredBeforeNextField=0, uiIpv6AddressPrintOffset=0,
        uiLongestZeroIpv6FieldSequenceLength=0,uiLongestZeroIpv6FieldSequenceStartPos=0,
        uiCurrentZeroIpv6FieldSequenceLength=0,uiCurrentZeroIpv6FieldSequenceStartPos=0;
        
    switch (f_pIpAddr->ulIpVersion)
    {
        /* IPv4 address */
        case cOCTVC1_IP_VERSION_ENUM_4:
            sprintf(f_pszIpAddr, "%d.%d.%d.%d",
                    ((f_pIpAddr->aulIpAddress[0] >> 24) & 0xFF),
                    ((f_pIpAddr->aulIpAddress[0] >> 16) & 0xFF),
                    ((f_pIpAddr->aulIpAddress[0] >> 8)  & 0xFF),
                    ((f_pIpAddr->aulIpAddress[0])       & 0xFF));
            break;
        /* IPv6 address */
        case cOCTVC1_IP_VERSION_ENUM_6:

            uiLongestZeroIpv6FieldSequenceLength = 0;
            uiCurrentZeroIpv6FieldSequenceLength = 0;
            for(i = 0; i < 8; i++)
            {
                auiIpv6Fields[i] =( f_pIpAddr->aulIpAddress[i/2] >> (16 * ((i + 1) & 1))) & 0xFFFF;
                if(auiIpv6Fields[i] == 0)
                {
                    if(uiCurrentZeroIpv6FieldSequenceLength == 0)
                    {
                        uiCurrentZeroIpv6FieldSequenceStartPos = i;
                    }
                    uiCurrentZeroIpv6FieldSequenceLength += 1;

                    if(uiCurrentZeroIpv6FieldSequenceLength > uiLongestZeroIpv6FieldSequenceLength)
                    {
                        uiLongestZeroIpv6FieldSequenceLength = uiCurrentZeroIpv6FieldSequenceLength;
                        uiLongestZeroIpv6FieldSequenceStartPos = uiCurrentZeroIpv6FieldSequenceStartPos;
                    }
                }
                else
                {
                    uiCurrentZeroIpv6FieldSequenceLength = 0;
                }
            }

            uiSemiColonRequiredBeforeNextField = 0;
            uiIpv6AddressPrintOffset = 0;
            uiIpv6AddressPrintOffset += sprintf(f_pszIpAddr, "[");
            for(i = 0; i < 8; i++)
            {
                if(uiLongestZeroIpv6FieldSequenceLength > 1 && i == uiLongestZeroIpv6FieldSequenceStartPos)
                {
                    uiIpv6AddressPrintOffset += sprintf(f_pszIpAddr + uiIpv6AddressPrintOffset, "::");
                    uiSemiColonRequiredBeforeNextField = 0;
                }
                if(uiLongestZeroIpv6FieldSequenceLength <= 1 || i < uiLongestZeroIpv6FieldSequenceStartPos ||
                    i >= (uiLongestZeroIpv6FieldSequenceStartPos + uiLongestZeroIpv6FieldSequenceLength))
                {
                    if(uiSemiColonRequiredBeforeNextField)
                    {
                        uiIpv6AddressPrintOffset += sprintf(f_pszIpAddr + uiIpv6AddressPrintOffset, ":");
                    }
                    uiIpv6AddressPrintOffset += sprintf(f_pszIpAddr + uiIpv6AddressPrintOffset, "%x",auiIpv6Fields[i]);
                    uiSemiColonRequiredBeforeNextField = 1;
                }
            }
            break;
        /* Invalid address */
        default:
            f_pszIpAddr[0] = '\0';
            break;
    };
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

Function:       OctSamplesUdpAddr2Str

Description:    Converts an UDP address to a string.

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

void OctSamplesUdpAddr2Str(char                      *f_pszUdpAddr,
                              const tOCTVC1_UDP_ADDRESS *f_pUdpAddr)
{
    unsigned int auiIpv6Fields[8];
    unsigned int i,uiSemiColonRequiredBeforeNextField, uiIpv6AddressPrintOffset,
        uiLongestZeroIpv6FieldSequenceLength,uiLongestZeroIpv6FieldSequenceStartPos,
        uiCurrentZeroIpv6FieldSequenceLength,uiCurrentZeroIpv6FieldSequenceStartPos;
        
    switch (f_pUdpAddr->IpAddress.ulIpVersion)
    {
        /* IPv4 address */
        case cOCTVC1_IP_VERSION_ENUM_4:
            sprintf(f_pszUdpAddr, "%d.%d.%d.%d:%d",
                    ((f_pUdpAddr->IpAddress.aulIpAddress[0] >> 24) & 0xFF),
                    ((f_pUdpAddr->IpAddress.aulIpAddress[0] >> 16) & 0xFF),
                    ((f_pUdpAddr->IpAddress.aulIpAddress[0] >> 8)  & 0xFF),
                    ((f_pUdpAddr->IpAddress.aulIpAddress[0])       & 0xFF),
                    f_pUdpAddr->ulUdpPort);
            break;
        /* IPv6 address */
        case cOCTVC1_IP_VERSION_ENUM_6:

            uiLongestZeroIpv6FieldSequenceLength = 0;
            uiCurrentZeroIpv6FieldSequenceLength = 0;
            for(i = 0; i < 8; i++)
            {
                auiIpv6Fields[i] =( f_pUdpAddr->IpAddress.aulIpAddress[i/2] >> (16 * ((i + 1) & 1))) & 0xFFFF;
                if(auiIpv6Fields[i] == 0)
                {
                    if(uiCurrentZeroIpv6FieldSequenceLength == 0)
                    {
                        uiCurrentZeroIpv6FieldSequenceStartPos = i;
                    }
                    uiCurrentZeroIpv6FieldSequenceLength += 1;

                    if(uiCurrentZeroIpv6FieldSequenceLength > uiLongestZeroIpv6FieldSequenceLength)
                    {
                        uiLongestZeroIpv6FieldSequenceLength = uiCurrentZeroIpv6FieldSequenceLength;
                        uiLongestZeroIpv6FieldSequenceStartPos = uiCurrentZeroIpv6FieldSequenceStartPos;
                    }
                }
                else
                {
                    uiCurrentZeroIpv6FieldSequenceLength = 0;
                }
            }

            uiSemiColonRequiredBeforeNextField = 0;
            uiIpv6AddressPrintOffset = 0;
            uiIpv6AddressPrintOffset += sprintf(f_pszUdpAddr, "[");
            for(i = 0; i < 8; i++)
            {
                if(uiLongestZeroIpv6FieldSequenceLength > 1 && i == uiLongestZeroIpv6FieldSequenceStartPos)
                {
                    uiIpv6AddressPrintOffset += sprintf(f_pszUdpAddr + uiIpv6AddressPrintOffset, "::");
                    uiSemiColonRequiredBeforeNextField = 0;
                }
                if(uiLongestZeroIpv6FieldSequenceLength <= 1 || i < uiLongestZeroIpv6FieldSequenceStartPos ||
                    i >= (uiLongestZeroIpv6FieldSequenceStartPos + uiLongestZeroIpv6FieldSequenceLength))
                {
                    if(uiSemiColonRequiredBeforeNextField)
                    {
                        uiIpv6AddressPrintOffset += sprintf(f_pszUdpAddr + uiIpv6AddressPrintOffset, ":");
                    }
                    uiIpv6AddressPrintOffset += sprintf(f_pszUdpAddr + uiIpv6AddressPrintOffset, "%x",auiIpv6Fields[i]);
                    uiSemiColonRequiredBeforeNextField = 1;
                }
            }
            
            sprintf(f_pszUdpAddr + uiIpv6AddressPrintOffset, "]:%d",f_pUdpAddr->ulUdpPort);
            break;
        /* Invalid address */
        default:
            f_pszUdpAddr[0] = '\0';
            break;
    };
}



