/*******************************************************************************
  lib_23.040.h  Developed by Dafocus - http://www.dafocus.com/

	Library of routines implementing come 3GPP TS 23.040 concepts.
*******************************************************************************/
#ifndef __LIB_23_040_H
#define __LIB_23_040_H
#include "ed_data.h"
#ifdef __cplusplus
	extern "C" {
#endif

/*==============================================================================
	Semi-octet decoder function (TS 23.040, 9.1.2.3).
	Reads the encoded octets from "Source"+"SourceOffset" bits and writes them 
	to "Destination".
	"Destination" must be the address of a array of ED_OCTETs big enough to
	contain the semi-octets.
	Each semi-octet is stored into on element of the "Destination" array.
	It returns the number of semi-octets really decoded: this could be less than
	"NumberOfSemiOctets" because semi-octets set to 1111 must be ignored.
==============================================================================*/
unsigned ED23040_DecodeSemiOctet (unsigned NumberOfSemiOctets, const void* Source, long SourceOffset, ED_OCTET* Destination);

/*==============================================================================
	Semi-octet encoder function (TS 23.040, 9.1.2.3).
	Reads "NumberOfSemiOctets" items from the "Source" array and encodes them
	as semi-octets starting at "Destination".
	It returns the number of octets really written, which is 
	"NumberOfSemiOctets/2" rounded up to the nearest upper integer.
	In case "NumberOfSemiOctets" is odd, the remaining semi-octet is padded
	with "1111", as specified in the standard.
==============================================================================*/
unsigned ED23040_EncodeSemiOctet (unsigned NumberOfSemiOctets, const ED_OCTET* Source, void* Destination, long DestinationOffset);

/*------------------------------------------------------------------------------
	This function copies 'Count' less significant bits of 'Source' integer to
	'Destination' ad offset 'Offset'.
------------------------------------------------------------------------------*/
void EDZIFIntToBits (void* Destination, long DestOffset, int Source, int Count);

/*------------------------------------------------------------------------------
	This function copies 'Count' less significant bits of 'Source' char buffer
	from offset 'Offset'. Read integer is returned.
------------------------------------------------------------------------------*/
int EDZIFBitsToInt (const void* Source, long SourceOffset, int Count);

#define ZIF_SHIFT_INT(bits) (CURPOS+=bits, EDZIFBitsToInt (Buffer, CURPOS-bits, bits))
#define ZIF_PUSH_INT(val, bits)	do {EDZIFIntToBits (Buffer, CURPOS, val, bits); CURPOS+=bits;} while (0)


#ifdef __cplusplus
	};
#endif
#endif