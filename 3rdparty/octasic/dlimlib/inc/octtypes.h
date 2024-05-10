/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octtypes.h

$Octasic_Copyright: $

Description:

   Provide cross-plateform definition

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: 13268 $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTTYPES_H__
#define __OCTTYPES_H__

/*-------------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif
/*-------------------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------------------*/
// Generic types
/*---------------------------------------------------------------------------------------*/
typedef unsigned char		u8;
typedef unsigned short		u16;
typedef unsigned int		u32;
typedef signed char			s8;
typedef signed short		s16;
typedef signed int			s32;
typedef long long			s64;
typedef unsigned long long  u64;  

typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
typedef signed char			sint8;
typedef signed short		sint16;
typedef signed int			sint32;
typedef long long			sint64;
typedef unsigned long long  uint64;  
typedef unsigned char       hardbits;
typedef float               softbits;  


	
/*---------------------------------------------------------------------------------------*/
// Composite types
/*---------------------------------------------------------------------------------------*/
typedef struct tCmplx32
{
	   s32 Real;
	   s32 Imag;
}tCmplx32;

typedef struct tCmplx16
{
	   s16 Real;
	   s16 Imag;
}tCmplx16;

typedef struct tCmplx8
{
   s8 Real;
   s8 Imag;
}tCmplx8;


	#ifdef WIN32	
		#define mSWAP32( f_ulValue ) \
					( ((((uint32)f_ulValue) & 0xff000000 ) >> 24) | \
					  ((((uint32)f_ulValue) & 0x00ff0000 ) >> 8) | \
					  ((((uint32)f_ulValue) & 0x0000ff00 ) << 8) | \
					  ((((uint32)f_ulValue) & 0x000000ff ) << 24)  )

		#define mSWAP16( f_ulValue ) \
					( (((f_ulValue) & 0xff00) >> 8) | \
					  (((f_ulValue) & 0x00ff ) << 8)  )

		#define __hil( f_ulPack32 ) ((s16)(f_ulPack32) ) 
		#define __lol( f_ulPack32 ) ((u16)(f_ulPack32>> 16))
		#define __ld_packw( f_u32 )  ((f_u32 & 0x0000FFFF) << 16) |(((unsigned)(f_u32 & 0xFFFF0000)) >> 16)
		#define __st_packw( f_u32 )  ((f_u32 & 0x0000FFFF) << 16) |(((unsigned)(f_u32 & 0xFFFF0000)) >> 16)
	#else
		#define mSWAP32( f_ulValue )  f_ulValue
		#define mSWAP16( f_ulValue )  f_ulValue
		#define __hil( f_ulPack32 ) ((u16)(f_ulPack32>> 16))
		#define __lol( f_ulPack32 ) ((s16)(f_ulPack32) ) 
		#define __ld_packw( f_u32 ) (f_u32)
		#define __st_packw( f_u32 ) (f_u32)

	#endif

#ifdef __cplusplus	
}
#endif
/*-------------------------------------------------------------------------------------*/


#endif  // __OCTTYPES_H__
