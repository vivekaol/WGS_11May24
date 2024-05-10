/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTDEV_OPUS_REV.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

Description: 

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Board management software (OBM) 2.3.2-B385 (09/01/2018)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTDEV_OPUS_REV_H__
#define __OCTDEV_OPUS_REV_H__


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Revision history
-------------------------------------------------------------------------------------*/

                
#ifdef _M_OPUS1  
#define	OCT1010_REV_B
#endif /* _M_OPUS1 */

#ifdef	OCT1010_REV_A
	#define d1jnsrc		d1jnsrp
	#define d2jnsrc		d2jnsrp
	#define d4jnsrc		d4jnsrp
	#define d8jnsrc		d8jnsrp
	#define d16jnsrc	d16jnsrp
	#define d32jnsrc	d32jnsrp
	#define d64jnsrc	d64jnsrp
	#define d128jnsrc	d128jnsrp
	#define d1jnsc		d1jnsrp
	#define d2jnsc		d2jnsrp
	#define d4jnsc		d4jnsrp
	#define d8jnsc		d8jnsrp
	#define d16jnsc		d16jnsrp
	#define d32jnsc		d32jnsrp
	#define d64jnsc		d64jnsrp
	#define d128jnsc	d128jnsrp

	/* need for the migration from Rev A to Rev B
	 */
	#define mOCTDEV_OPUS_RDTSC_CORRECTION( f_ulTimestamp ) \
		_asm and 	f_ulTimestamp, 0x7FFFFFFF

	#define mOCTDEV_OPUS_RDTSC_CORRECTION_C( f_ulTimestamp ) \
		f_ulTimestamp &= 0x7FFFFFFF;

	#define mOCTDEV_OPUS_UNSEIZABLE_FIX( f_ulRegister ) \
		_asm { halt ( ( f_ulRegister & 0 ) != 0 ) }

	#define mOCTDEV_OPUS_UNSEIZABLE_FIX_C( f_ulRegister ) \
		{_chalt(( f_ulRegister & 0 ) != 0 );}

#endif /* OCT1010_REV_A */

#ifdef	OCT1010_REV_B
	#define mOCTDEV_OPUS_RDTSC_CORRECTION( f_ulTimestamp ) \
		_asm and 	f_ulTimestamp, 0x7FFFFFFF

	#define mOCTDEV_OPUS_RDTSC_CORRECTION_C( f_ulTimestamp ) \
		f_ulTimestamp &= 0x7FFFFFFF;

	#define mOCTDEV_OPUS_UNSEIZABLE_FIX( f_ulRegister ) \
		_asm { halt ( ( f_ulRegister & 0 ) != 0 ) }

	#define mOCTDEV_OPUS_UNSEIZABLE_FIX_C( f_ulRegister ) \
		{_chalt(( f_ulRegister & 0 ) != 0 );}

#endif /* OCT1010_REV_B */

#ifdef _M_OPUS2
	#define	OCT2200_REV_B
#endif /* _M_OPUS2 */
	
#ifdef OCT2200_REV_A
	#define mOCTDEV_OPUS_RDTSC_CORRECTION( f_ulTimestamp )
  #define mOCTDEV_OPUS_RDTSC_CORRECTION_C( f_ulTimestamp )
	
	#define mOCTDEV_OPUS_UNSEIZABLE_FIX( f_ulRegister )
  #define mOCTDEV_OPUS_UNSEIZABLE_FIX_C( f_ulRegister )
        
#endif /* OCT2200_REV_A */

#ifdef OCT2200_REV_B
	#define mOCTDEV_OPUS_RDTSC_CORRECTION( f_ulTimestamp )
  #define mOCTDEV_OPUS_RDTSC_CORRECTION_C( f_ulTimestamp )
	
	#define mOCTDEV_OPUS_UNSEIZABLE_FIX( f_ulRegister )
  #define mOCTDEV_OPUS_UNSEIZABLE_FIX_C( f_ulRegister )
        
#endif /* OCT2200_REV_B */

#ifdef _M_OPUS3
	#define mOCTDEV_OPUS_RDTSC_CORRECTION( f_ulTimestamp )
  #define mOCTDEV_OPUS_RDTSC_CORRECTION_C( f_ulTimestamp )
	
	#define mOCTDEV_OPUS_UNSEIZABLE_FIX( f_ulRegister )
  #define mOCTDEV_OPUS_UNSEIZABLE_FIX_C( f_ulRegister )
        
#endif /* _M_OPUS3 */
            
              
#endif /* __OCTDEV_OPUS_REV_H__ */

