/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTDEV_TYPES.h

Copyright (c) 2019 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR_RUS-04.00.02-B3333 (2019/01/02)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTDEV_TYPES_H__
#define __OCTDEV_TYPES_H__


/*****************************  INCLUDE FILES  *******************************/
#include <limits.h>


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	API Data Types
-------------------------------------------------------------------------------------*/

                
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif
                
#if SHRT_MAX == 32767
	/* short is 16-bit */
	typedef unsigned short	tOCT_UINT16;
	typedef short			tOCT_INT16;
#elif INT_MAX == 32767
	/* integer is 16-bit */
	typedef unsigned int	tOCT_UINT16;
	typedef int				tOCT_INT16;
#else
	/* unexpected 16-bit type */
	#error Cannot determine 16-bit type
#endif

#if INT_MAX == 2147483647L
	/* integer is 32-bit */
	typedef int				tOCT_INT32;
	typedef unsigned int	tOCT_UINT32;
#elif LONG_MAX == 2147483647L
	/* long is 32-bit */
	typedef long			tOCT_INT32;
	typedef unsigned long	tOCT_UINT32;
#else
	/* unexpected 32-bit type */
	#error Cannot determine 32-bit type
#endif

typedef long long			tOCT_INT64;
typedef unsigned long long	tOCT_UINT64;

typedef char			tOCT_INT8;
typedef unsigned char	tOCT_UINT8;
            
              
/*-------------------------------------------------------------------------------------
 	TRUE/FALSE
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCT_BOOL32 :
-------------------------------------------------------------------------------------*/
#define tOCT_BOOL32											tOCT_UINT32

#define cOCT_TRUE											1		
#define cOCT_FALSE											0		

/*-------------------------------------------------------------------------------------
 	Generic Timeout value
-------------------------------------------------------------------------------------*/
#define cOCTDEV_TIMEOUT_FOREVER								0xFFFFFFFF	

                
/*--------------------------------------------------------------------------
	ENDIAN Determination

    _OCT_ENDIAN_TYPE_BE_: Defined when target is Big Endian
    _OCT_ENDIAN_TYPE_LE_: Defined when target is Little Endian

	These must be set by the user. If not set the system will try to
	automatically determine them based on some common compiler #define
	values.

----------------------------------------------------------------------------*/

#if !defined( _OCT_ENDIAN_TYPE_BE_ ) && !defined( _OCT_ENDIAN_TYPE_LE_ )
	/* Not Set - try to determine automatically */

	/* Look for Intel target */
	#if defined( __OCT_ENV_OPUS__ ) || defined( _M_OPUS1 ) || defined( _M_OPUS2 ) || defined( _M_OPUS3 )
		#define _OCT_ENDIAN_TYPE_BE_
		#define _OCT_PLATFORM_OPUS_
	#elif defined( _M_IX86 ) || defined(__x86_64__)
		#define _OCT_ENDIAN_TYPE_LE_
		#define _OCT_PLATFORM_X86_
	#elif defined( __i386 )
		#define _OCT_ENDIAN_TYPE_LE_
		#define _OCT_PLATFORM_X86_
	#elif defined( i386 )
		#define _OCT_ENDIAN_TYPE_LE_
		#define _OCT_PLATFORM_X86_
	/* Look for Motorola PPC target */
	#elif defined( _M_MPPC  ) || defined( _M_PPC ) || defined( __ppc__ ) || defined( __PPC )
		#define _OCT_ENDIAN_TYPE_BE_
		#define _OCT_PLATFORM_PPC_
	/* Look for Sparc target */
	#elif defined( __sparc )
		#define _OCT_ENDIAN_TYPE_BE_
		#define _OCT_PLATFORM_SPARC_
	#elif defined( __sun__ )
		#define _OCT_ENDIAN_TYPE_BE_
		#define _OCT_PLATFORM_SPARC_
	/* Look for ARM target */
	#elif defined( __ARMEB__ ) || defined( __AARCH64EB__ )
		#define _OCT_ENDIAN_TYPE_BE_
		#define _OCT_PLATFORM_ARM_
	#elif defined( __ARMEL__ )|| defined( __AARCH64EL__ )	
		#define _OCT_ENDIAN_TYPE_LE_
		#define _OCT_PLATFORM_ARM_
	/* Look for MIPS target */
	#elif  defined( __mips__ ) || defined( __MIPSEB )
		#define _OCT_ENDIAN_TYPE_BE_
		#define _OCT_PLATFORM_MIPS_
	/* others */
	#elif defined( __BIG_ENDIAN__ )
		#define _OCT_ENDIAN_TYPE_BE_
	#elif defined( __LITTLE_ENDIAN__ )
		#define _OCT_ENDIAN_TYPE_LE_		
	#elif defined( CPU )
		#if CPU==PPC860
			#define _OCT_ENDIAN_TYPE_BE_
			#define _OCT_PLATFORM_PPC_
		#endif
	#endif
#endif

/* Now insure the endian format is set properly */
#if !defined( _OCT_ENDIAN_TYPE_BE_ ) && !defined( _OCT_ENDIAN_TYPE_LE_ )
	#error Processor Endian not determined
#endif
#if defined( _OCT_ENDIAN_TYPE_BE_ ) && defined( _OCT_ENDIAN_TYPE_LE_ )
	#error Processor Endian Set to both Values
#endif

/*--------------------------------------------------------------------------
	PLATFORM Determination

    OCT_WINDOWS_ENV : Defined when target running under windows
      OCT_LINUX_ENV : Defined when target running under linux
       OCT_OPUS_ENV : OPUS env
    OCT_UNKNOWN_ENV : Unknown env

----------------------------------------------------------------------------*/
#define __OCTDEV_TYPE_STR2__(x) #x
#define __OCTDEV_TYPE_STR1__(x) __OCTDEV_TYPE_STR2__(x)
#define __OCTDEV_TYPE_WARNLOC__ __FILE__ "("__OCTDEV_TYPE_STR1__(__LINE__)") : Warning Msg: "

#if defined( __OCT_ENV_OPUS__ ) || defined( _M_OPUS1 ) || defined( _M_OPUS2 ) || defined( _M_OPUS3 )
	#define OCT_ENV_TYPE_OPUS
	#define OCT_ENV_TYPE_OCTSYS
#ifndef NDEBUG
	#define OCT_ENV_MODE_DEBUG
#endif 
#elif defined( _LINUX_ ) || defined( __linux__ )
	#define OCT_ENV_TYPE_LINUX
  #define OCT_ENV_TYPE_OCTOS
#ifndef NDEBUG
	#define OCT_ENV_MODE_DEBUG
#endif   
#elif defined( _WIN32 ) || defined( WIN32 ) || defined( __WIN32__ ) ||	defined( _WIN32_ ) || defined( WIN32S ) || defined( _WIN64 )  || defined( WIN64 )
	#define OCT_ENV_TYPE_WINDOWS
  #define OCT_ENV_TYPE_OCTOS
#ifdef _DEBUG
	#define OCT_ENV_MODE_DEBUG
#endif   
#else
	#define OCT_ENV_TYPE_UNKNOWN
  #pragma message(__OCTDEV_TYPE_WARNLOC__"Environment platform not determined")
#endif

/*--------------------------------------------------------------------------
	POINTER type definition
----------------------------------------------------------------------------*/
#if defined( OCT_ENV_TYPE_WINDOWS )
#include <basetsd.h>

#define tOCT_UINT_PTR	UINT_PTR
#define tOCT_INT_PTR	INT_PTR

#elif defined( OCT_ENV_TYPE_LINUX )
#include <inttypes.h>

#define tOCT_UINT_PTR	uintptr_t
#define tOCT_INT_PTR	intptr_t

#elif defined( OCT_ENV_TYPE_OCTSYS )
#include  <stdint.h>

#define tOCT_UINT_PTR	uintptr_t
#define tOCT_INT_PTR	intptr_t

#else 
	#pragma message(__OCTDEV_TYPE_WARNLOC__"Environment pointer determined")


#endif /* OCT_ENV_TYPE_WINDOWS */

              
/*-------------------------------------------------------------------------------------
 	Generic IP Address
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTDEV_IP_VERSION_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTDEV_IP_VERSION_ENUM								tOCT_UINT32

#define cOCTDEV_IP_VERSION_ENUM_4							0		 	/* IP address version 4 */
#define cOCTDEV_IP_VERSION_ENUM_6							1		 	/* IP address version 6 */
#define cOCTDEV_IP_VERSION_ENUM_INVALID						0xFFFFFFFF	

/*-------------------------------------------------------------------------------------
	tOCTDEV_IP_ADDRESS
 		IP address structure

 Members:
	ulIpVersion
		Default:	cOCTDEV_IP_VERSION_ENUM_4
 		Version of the IP address
	aulIpAddress
 		Ip address, Version 4 -> aulIpAddress[0] only.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTDEV_IP_VERSION_ENUM	ulIpVersion;
	tOCT_UINT32				aulIpAddress[4];

} tOCTDEV_IP_ADDRESS;

/*-------------------------------------------------------------------------------------
 	Generic UDP Address
-------------------------------------------------------------------------------------*/
#define cOCTDEV_UDP_PORT_INVALID							0xFFFFFFFF	 	/* Invalid UDP port specification. */

/*-------------------------------------------------------------------------------------
	tOCTDEV_UDP_ADDRESS
 		UDP address structure

 Members:
	IpAddress
 		IP version and address.
	ulUdpPort
		Default:	cOCTDEV_UDP_PORT_INVALID
 		UDP port used with IP address
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTDEV_IP_ADDRESS	IpAddress;
	tOCT_UINT32			ulUdpPort;

} tOCTDEV_UDP_ADDRESS;

/*-------------------------------------------------------------------------------------
 	Generic TCP Address
-------------------------------------------------------------------------------------*/
#define cOCTDEV_TCP_PORT_INVALID							0xFFFFFFFF	 	/* Invalid TCP port specification. */

/*-------------------------------------------------------------------------------------
	tOCTDEV_TCP_ADDRESS
 		TCP address structure

 Members:
	IpAddress
 		IP version and address.
	ulTcpPort
		Default:	cOCTDEV_TCP_PORT_INVALID
 		TCP port used with IP address
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTDEV_IP_ADDRESS	IpAddress;
	tOCT_UINT32			ulTcpPort;

} tOCTDEV_TCP_ADDRESS;

/*-------------------------------------------------------------------------------------
 	Generic MAC Address
-------------------------------------------------------------------------------------*/
#define cOCTDEV_MAC_ADDRESS_BYTE_COUNT						6		

/*-------------------------------------------------------------------------------------
	tOCTDEV_MAC_ADDRESS
 		MAC address structure

 Members:
	abyReserved
 		Reserved fields inserted to ensure that the structure is an integer multiple of
 		DWORDS.
	abyMacAddress
 		MAC address; abyMacAddress[0] = msb, abyMacAddress[5] = lsb.
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT8	abyReserved[2];
	tOCT_UINT8	abyMacAddress[cOCTDEV_MAC_ADDRESS_BYTE_COUNT];

} tOCTDEV_MAC_ADDRESS;


#endif /* __OCTDEV_TYPES_H__ */

