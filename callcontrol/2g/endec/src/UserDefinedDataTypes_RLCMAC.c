/**************************************************************************
	Generated automatically by Codegenix(TM) - (c) 2000-2004 Dafocus
	EnDec version 1.0.168
	GENERATOR: ed-c-encodeco
	http://www.Dafocus.it/
**************************************************************************/


#include "UserDefinedDataTypes_RLCMAC.h"
#include "ed_c_known_ie_RLCMAC.h"
#include "ed_tlv.h"
#if ED_COMMON_CRC != 0xC33C6D73
#error Invalid Encodix library files linked; used those distributed with Encodix 1.0.168
#endif


#define THIS Source
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* IEEE 802.16 GENERIC TLV ENCODER */
ED_EXPORT_CALL (ED_EXLONG, ENCODE_c_GenericTLV_RLCMAC (char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, const c_GenericTLV_RLCMAC* ED_CONST Source))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG BinaryDataLength;
	


	
	ED_EXTRAPARAMS_CODE
						
	/* Encode the tag */
	EDIntToBits (Buffer, CurrOfs, Source->TLV_Tag, 8);
	CurrOfs += 8;
	
	/* Calculate the binary length */
	BinaryDataLength = Source->TLV_Data.usedBits;
	
	/* Encode the length rounded up to the nearest octet */
	CurrOfs += EDEncodeDefiniteFormLength (Buffer, CurrOfs, (((unsigned ED_EXLONG)BinaryDataLength)+7)>>3);
	
	/* Encode the bits of the binary data */
	EDCopyBits (Buffer, CurrOfs, Source->TLV_Data.value, 0, BinaryDataLength);
	CurrOfs += BinaryDataLength;
	
	/* Pad the remaining part */
	EDIntToBits (Buffer, CurrOfs, 0, BITS_TO_OCTET_PAD (CurrOfs-BitOffset));
	CurrOfs += BITS_TO_OCTET_PAD (CurrOfs-BitOffset);
	

	return (CurrOfs - BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
#define THIS Destin
#define ED_REMAINING_BITS (Length - (CurrOfs-BitOffset))
/* IEEE 802.16 GENERIC TLV DECODER */
ED_EXPORT_CALL (ED_EXLONG, DECODE_c_GenericTLV_RLCMAC (const char* ED_CONST Buffer, ED_CONST ED_EXLONG BitOffset, c_GenericTLV_RLCMAC* ED_CONST Destin, ED_EXLONG Length))
{
	ED_EXLONG CurrOfs = BitOffset;
	ED_EXLONG DataLength;
	ED_EXLONG EffectiveDataLength;
	ED_EXLONG RetLen;

	ED_EXTRAPARAMS_CODE
	
	ED_WARNING_REMOVER(RetLen);
	/* Is there room for tag and length? */
	if (Length < 16) return ED_MESSAGE_TOO_SHORT;

	/* Decode the tag */
	Destin->TLV_Tag = (ED_LONG)EDBitsToInt (Buffer, CurrOfs, 8);
	CurrOfs += 8;
	
	/* Decode the length */
	RetLen = EDDecodeDefiniteFormLength (Buffer, CurrOfs, &DataLength);
	if (RetLen < 0) return RetLen;
	DataLength = DataLength * 8;
	EffectiveDataLength = DataLength;
	CurrOfs += RetLen;
	if ((CurrOfs-BitOffset) > Length) return ED_MESSAGE_TOO_SHORT;
	if ((CurrOfs + (ED_EXLONG)DataLength)-BitOffset > Length) return ED_MESSAGE_TOO_SHORT;
	

	
	if (DataLength > 0) {
		/* Allocate 'DataLength' bits */
		ALLOC_c_GenericTLV_RLCMAC_TLV_Data (&(Destin->TLV_Data), DataLength);

		
		/* Save the bits in the binary data */
		EDCopyBits (Destin->TLV_Data.value, 0, Buffer, CurrOfs, DataLength);
		CurrOfs += (ED_EXLONG)EffectiveDataLength;
	}
	
	return (CurrOfs-BitOffset);
}

#undef THIS
#undef ED_REMAINING_BITS
