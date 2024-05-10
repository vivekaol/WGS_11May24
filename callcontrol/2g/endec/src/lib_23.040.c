/*******************************************************************************
  lib_23.040.c  Developed by Dafocus - http://www.dafocus.com/

	Library of routines implementing come 3GPP TS 23.040 concepts.
*******************************************************************************/
#include "lib_23.040.h"
#include "ed_lib.h"

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
unsigned ED23040_DecodeSemiOctet (unsigned NumberOfSemiOctets, const void* Source, long SourceOffset, ED_OCTET* Destination)
{
	unsigned destPosition = 0;
	unsigned i, offset;
	ED_OCTET value;

	for (i=0; i<NumberOfSemiOctets; i++) {
		offset = ((i & ~1) | (1 & ~i)) << 2;
		value = (ED_OCTET)EDBitsToInt (Source, SourceOffset+offset, 4);
		if (value != 15) {
			Destination [destPosition] = value;
			destPosition++;			
		}
	}
	return destPosition;
}

/*==============================================================================
	Semi-octet encoder function (TS 23.040, 9.1.2.3).
	Reads "NumberOfSemiOctets" items from the "Source" array and encodes them
	as semi-octets starting at "Destination".
	It returns the number of octets really written, which is 
	"NumberOfSemiOctets/2" rounded up to the nearest upper integer.
	In case "NumberOfSemiOctets" is odd, the remaining semi-octet is padded
	with "1111", as specified in the standard.
==============================================================================*/
unsigned ED23040_EncodeSemiOctet (unsigned NumberOfSemiOctets, const ED_OCTET* Source, void* Destination, long DestinationOffset)
{
	unsigned i, offset;
	for (i=0; i<NumberOfSemiOctets; i++) {
		offset = ((i & ~1) | (1 & ~i)) << 2;
		EDIntToBits (Destination, DestinationOffset+offset, Source [i], 4);
	}
	/* If "NumberOfSemiOctets" is odd, fill the extra semi-octet with 1111 */
	if ((NumberOfSemiOctets & 1) != 0) {
		offset = ((i & ~1) | (1 & ~i)) << 2;
		EDIntToBits (Destination, DestinationOffset+offset, 15, 4);
		i++;
	}
	return i>>1;
}

#define POS(bit) (1 << (bit & 7))
#define SRC (*(((const unsigned char*) Source)+(SourceOffset >> 3)))
#define DST (*(((unsigned char*)Destination)+(DestOffset >> 3)))


/*------------------------------------------------------------------------------
	This function copies 'Count' less significant bits of 'Source' integer to
	'Destination' ad offset 'Offset'.
------------------------------------------------------------------------------*/
void EDZIFIntToBits (void* Destination, long DestOffset, int Source, int Count)
{
	int i;
	for (i=0; i<Count; i++) {
		if ((Source & (1 << i)) != 0) DST |= POS(DestOffset);
		else DST &= ~POS(DestOffset);
		DestOffset++;
	}
}

/*------------------------------------------------------------------------------
	This function copies 'Count' less significant bits of 'Source' char buffer
	from offset 'Offset'. Read integer is returned.
------------------------------------------------------------------------------*/
int EDZIFBitsToInt (const void* Source, long SourceOffset, int Count)
{
	int i, ret=0;
	int Remainder = Count;
	for (i=0; i<Count; i++) {
		if ((SRC & POS(SourceOffset)) != 0) ret |= (1 << i);
		SourceOffset++;
	}
	return ret;
}
