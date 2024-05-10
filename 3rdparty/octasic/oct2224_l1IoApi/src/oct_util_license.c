#ifndef OCT_OPT_REMOVE_LICENSING
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: util_license.c

Copyright (c) 2018 Octasic Inc. All rights reserved.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-04.10.01-B3387 (2018/01/29)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*****************************  INCLUDE FILES  *******************************/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<assert.h>
#include "oct_util_license.h"
#include "octdev_macro.h"


#define OCT_RC_OK 0
#define cLICENSING_PUBLIC_KEY_SIZE_BITS (2048)
#define cLICENSING_PUBLIC_KEY_SIZE_BYTES (cLICENSING_PUBLIC_KEY_SIZE_BITS / 8)

#define cLICENSING_SHA1_HASH_SIZE_BITS (160)
#define cLICENSING_SHA1_HASH_SIZE_BYTES (cLICENSING_SHA1_HASH_SIZE_BITS >> 3)
#define cLICENSING_SHA1_BLOCK_SIZE_BITS (512)
#define cLICENSING_SHA1_BLOCK_SIZE_BYTES (cLICENSING_SHA1_BLOCK_SIZE_BITS >> 3)

#define cOCTADF_UTIL_RC_STREAM_TX_FIFO_DATA					( 0x020 | TARGET_UTIL_RC_BASE )
#define cOCTADF_UTIL_RC_STREAM_UNSUPPORT_TRANSPORT			( 0x021 | TARGET_UTIL_RC_BASE )
#define cOCTADF_UTIL_RC_STREAM_DATA_PROTOCOL_NO_PACKET		( 0x022 | TARGET_UTIL_RC_BASE )
	
#define cOCTADF_UTIL_LICENSE_RC_KEY_SIZE_INVALID			(0x140 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_INVALID			(0x141 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID				(0x142 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_LM_ERROR					(0x143 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_SIGNATURE_MISSING			(0x144 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_SIGNATURE_CORRUPTED			(0x145 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID			(0x146 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_TO_SMALL		(0x147 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_BASE64_ENCODING_INVALID		(0x148 | TARGET_UTIL_RC_BASE)
#define cOCTADF_UTIL_LICENSE_RC_CRC24_INVALID				(0x149 | TARGET_UTIL_RC_BASE)


#define cBUF_SIZE 450

/* Generic MPI structure, size unspecified. */
typedef struct
{
	tOCT_UINT32 num_words;
	tOCT_UINT16 n[];		/* [num_words], [0] contains the lsbs. */

} MPI;


/*--------------------------------------------------------------------------
	Multi-Precision integers for the RSA assymetric keys.

	NOTE: The structure size is hard-coded to our requirements of a
          2048-bits key.
----------------------------------------------------------------------------*/
typedef struct
{
	unsigned num_words;
	unsigned short n[(cLICENSING_PUBLIC_KEY_SIZE_BITS >> 4)];

} MPI128;


/* SHA1 algorthm context */
typedef struct 
{
	tOCT_UINT32		ulMessageBlockOffset;
	tOCT_UINT32		ulMessageSize;
	tOCT_UINT8		abyMessageBlock[ cLICENSING_SHA1_BLOCK_SIZE_BYTES ];
	tOCT_UINT32		aulIntermediateHash[ 5 ];

} tLICENSING_SHA1_CONTEXT;

static tOCT_INT8* l_pCurrContent=NULL;
static tOCT_INT8* l_pMaxContent =NULL;

/*=======================  Cryptographic functions ====================*/

/*-------------------------------------------------------------------------*\

Function:		_LicensingSHA1CircularShift

Description:	Replacement for SHA1CircularShift macro from RFC 3174

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
static tOCT_UINT32 _LicensingSHA1CircularShift(
	tOCT_UINT32 f_ulBits,
	tOCT_UINT32 f_ulWord
)
{
	return (((f_ulWord) << (f_ulBits)) | ((f_ulWord) >> (32 - (f_ulBits))));
}

/*-------------------------------------------------------------------------*\

Function:		_LicensingSHA1ProcessBlock

Description:	Port of SHA1ProcessMessageBlock from RFC 3174; This function
				will process a 512 bit message block

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/

static void  _LicensingSHA1ProcessBlock(
	tOCT_UINT8* f_pabyMessageBlock,
	tOCT_UINT32* f_paulIntermediateHash
)
{
	tOCT_UINT32 K[4] = { 0x5A827999, /* Constants defined in SHA-1   */
		0x6ED9EBA1,
		0x8F1BBCDC,
		0xCA62C1D6 };

	tOCT_UINT32 t; /* Loop counter                */
	tOCT_UINT32 temp; /* Temporary word value        */
	tOCT_UINT32 A; /* Word buffers                */
	tOCT_UINT32 B; /* Word buffers                */
	tOCT_UINT32 C; /* Word buffers                */
	tOCT_UINT32 D; /* Word buffers                */
	tOCT_UINT32 E; /* Word buffers                */
	tOCT_UINT32 W[80]; /* Word sequence               */

	/*
	 *  Initialize the first 16 words in the array W
	 */

	for (t = 0; t < 16; t++)
	{
		W[t] = ((tOCT_UINT32)(f_pabyMessageBlock[0]) << 24) |
			((tOCT_UINT32)(f_pabyMessageBlock[1]) << 16) |
			((tOCT_UINT32)(f_pabyMessageBlock[2]) << 8) |
			((tOCT_UINT32)(f_pabyMessageBlock[3]) << 0);

		f_pabyMessageBlock = f_pabyMessageBlock + 4;
	}

	for (t = 16; t < 80; t++)
	{
		W[t] = _LicensingSHA1CircularShift(1, W[t - 3] ^ W[t - 8] ^ W[t - 14] ^ W[t - 16]);
	}

	A = f_paulIntermediateHash[0];
	B = f_paulIntermediateHash[1];
	C = f_paulIntermediateHash[2];
	D = f_paulIntermediateHash[3];
	E = f_paulIntermediateHash[4];

	for (t = 0; t < 20; t++)
	{
		temp = _LicensingSHA1CircularShift(5, A) +
			((B & C) | ((~B) & D)) + E + W[t] + K[0];
		E = D;
		D = C;
		C = _LicensingSHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	for (t = 20; t < 40; t++)
	{
		temp = _LicensingSHA1CircularShift(5, A) + (B ^ C ^ D) + E + W[t] + K[1];
		E = D;
		D = C;
		C = _LicensingSHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	for (t = 40; t < 60; t++)
	{
		temp = _LicensingSHA1CircularShift(5, A) +
			((B & C) | (B & D) | (C & D)) + E + W[t] + K[2];
		E = D;
		D = C;
		C = _LicensingSHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	for (t = 60; t < 80; t++)
	{
		temp = _LicensingSHA1CircularShift(5, A) + (B ^ C ^ D) + E + W[t] + K[3];
		E = D;
		D = C;
		C = _LicensingSHA1CircularShift(30, B);
		B = A;
		A = temp;
	}

	f_paulIntermediateHash[0] = A + f_paulIntermediateHash[0];
	f_paulIntermediateHash[1] = B + f_paulIntermediateHash[1];
	f_paulIntermediateHash[2] = C + f_paulIntermediateHash[2];
	f_paulIntermediateHash[3] = D + f_paulIntermediateHash[3];
	f_paulIntermediateHash[4] = E + f_paulIntermediateHash[4];

	return;
}


/*-------------------------------------------------------------------------*\

Function:		_LicensingSHA1Intitialize

Description:	This function is used to initialize an SHA1 context, ready
				to compute a new hash.
				

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
static void _LicensingSHA1Intitialize( 
	tLICENSING_SHA1_CONTEXT *		f_pSha1Context )
{
	tOCT_UINT32 i;
	tOCT_UINT32 aulIntermediateHashInit[] = {	0x67452301, 
												0xEFCDAB89,
												0x98BADCFE,
												0x10325476,
												0xC3D2E1F0 };

	f_pSha1Context->ulMessageBlockOffset	= 0;
	f_pSha1Context->ulMessageSize			= 0;
	for ( i=0; i<5; i++ )
		f_pSha1Context->aulIntermediateHash[ i ] = aulIntermediateHashInit[ i ];
}

/*-------------------------------------------------------------------------*\

Function:		_LicensingStrGets

Description:	Get string from global buffer
				
-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
static tOCT_INT8* _LicensingStrGets(
	tOCT_INT8* f_pszBuffer,
	tOCT_INT32 f_iBufSize )
{
	tOCT_PSZ pszTemp = l_pCurrContent;
	tOCT_PSZ pszTempMax = l_pCurrContent+ f_iBufSize;
	
	if ( (f_iBufSize == 0) || (l_pCurrContent >= l_pMaxContent) )
		return NULL;

	if (pszTempMax > l_pMaxContent)
		pszTempMax = l_pMaxContent;


	// Get one line
	while( *(pszTemp) != '\n') 
	{
		if (pszTemp == pszTempMax)
			break;

		pszTemp++;
	}

	if (pszTemp != pszTempMax)
		pszTemp++;

	mOADF_BUILTIN_MEMCPY(f_pszBuffer, l_pCurrContent, pszTemp - l_pCurrContent);
	f_pszBuffer[pszTemp - l_pCurrContent] = 0;
	l_pCurrContent = pszTemp;

	return f_pszBuffer;
}



/*-------------------------------------------------------------------------*\

Function:		_LicensingSHA1AccumulateLine

Description:	This function is used accumulate more data (in line form), to 
				be included in the SHA-1 hash. This data is expected to be 
				a NULL-terminated string. This line will be terminated with 
				a <cr><lf> (if not already done), as per RFC2440, prior to 
				inclusion in the hash.

				Also, any trailing whitespace (spaces and tabs (0x09)) at the 
				end of the line will be ignored in hash calculation.

				Refer to section 7.1 of RFC2440 for more information on the
				technalities of hash (message digest) calculation.
				
				PPMODIF: Added f_fClearText flag . To process non-clear text signature as
				in AdfUtilLicenseValidateContentDetach_ (for eeprom )

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
static void _LicensingSHA1AccumulateLine(
	tOCT_BOOL32	f_fClearText,
	tLICENSING_SHA1_CONTEXT* f_pSha1Context,
	tOCT_UINT8* f_pszData)
{
	/* Rewind a little and remove trailing whitespaces, CR, LF, as specified */
	/* in RFC2440 section 7.1. */
	int i = mOADF_BUILTIN_STRLEN((tOCT_INT8*)f_pszData);
	tOCT_UINT8* pszString;

	if (f_fClearText)
	{
		while (
			(
			 (f_pszData[i] == '\n') /* Line feed. */
			 || (f_pszData[i] == '\r') /* Carriage return. */
			 || (f_pszData[i] == 0) /* NULL character. */
			 || (f_pszData[i] == ' ') /* Space. */
			 || (f_pszData[i] == '\t') /* Tab. */
			) &&
			(i >= 0) /* Avoid "underflowing" */
		)
		{
			i--;
		}
	}
	else
	{
		while (
			(
			 (f_pszData[i] == '\n') /* Line feed. */
			 || (f_pszData[i] == '\r') /* Carriage return. */
			 || (f_pszData[i] == 0) /* NULL character. */
			//			 || (*pszString == ' ') /* Space. */
			//			 || (*pszString == '\t') /* Tab. */
			) &&
			(i >= 0) /* Avoid "underflowing" */
		)
		{
			i--;
		}
	}

	i++;

	/* Add the CR & LF characters, as per RFC2440 */
	if (f_pszData[i])
	{
		f_pszData[i] = '\r';
		f_pszData[i + 1] = '\n';
		f_pszData[i + 2] = 0;
	}

	/* Accumulate data, ready for submission to the SHA1 algorithm */
	for (pszString = f_pszData; (*pszString != 0x00); pszString++)
	{
		f_pSha1Context->abyMessageBlock[f_pSha1Context->ulMessageBlockOffset] = *pszString;
		f_pSha1Context->ulMessageBlockOffset++;

		/* Do we have a complete message block? */
		if (f_pSha1Context->ulMessageBlockOffset == cLICENSING_SHA1_BLOCK_SIZE_BYTES)
		{
			/* Hash this */
			_LicensingSHA1ProcessBlock(&f_pSha1Context->abyMessageBlock[0],
				&f_pSha1Context->aulIntermediateHash[0]);

			/* Start a new message block */
			f_pSha1Context->ulMessageBlockOffset = 0;
			f_pSha1Context->ulMessageSize = f_pSha1Context->ulMessageSize + cLICENSING_SHA1_BLOCK_SIZE_BYTES;

		}
	}

	return;
}

/*-------------------------------------------------------------------------*\

Function:		_LicensingSHA1AccumulateData

Description:	This function is used accumulate more data, to be included in
				the SHA-1 hash. This data is expected to be an array of bytes.
				

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
static void _LicensingSHA1AccumulateData(
	tLICENSING_SHA1_CONTEXT* f_pSha1Context,
	tOCT_UINT8* f_pbyData,
	tOCT_UINT32 f_ulDataSize
)
{
	tOCT_UINT8* pbyData;
	tOCT_UINT32 ulIndex;

	pbyData = f_pbyData;

	/* Accumulate data, ready for submission to the SHA1 algorithm */
	for (ulIndex = 0; ulIndex < f_ulDataSize; ulIndex++)
	{
		f_pSha1Context->abyMessageBlock[f_pSha1Context->ulMessageBlockOffset] = pbyData[ulIndex];
		f_pSha1Context->ulMessageBlockOffset++;

		/* Do we have a complete message block? */
		if (f_pSha1Context->ulMessageBlockOffset == cLICENSING_SHA1_BLOCK_SIZE_BYTES)
		{
			/* Hash this */
			_LicensingSHA1ProcessBlock(&f_pSha1Context->abyMessageBlock[0],
				&f_pSha1Context->aulIntermediateHash[0]);

			/* Start a new message block */
			f_pSha1Context->ulMessageBlockOffset = 0;
			f_pSha1Context->ulMessageSize = f_pSha1Context->ulMessageSize + cLICENSING_SHA1_BLOCK_SIZE_BYTES;
		}
	}

	return;
}

/*-------------------------------------------------------------------------*\

Function:		_LicensingSHA1Finalize

Description:	This function is used to complete an ongiong SHA1 hash
				calculation, returning the computed hash value.
				

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
static void _LicensingSHA1Finalize(
	tLICENSING_SHA1_CONTEXT* f_pSha1Context,
	tOCT_UINT8* f_pbyHash
)
{
	tOCT_UINT32 ulBlockOffset;
	tOCT_UINT32 ulMessageSize;
	tOCT_UINT32 ulIndex;

	ulBlockOffset = f_pSha1Context->ulMessageBlockOffset;
	ulMessageSize = f_pSha1Context->ulMessageSize + f_pSha1Context->ulMessageBlockOffset;

	/* Code derived from SHA1PadMessage()
     *  Check to see if the current message block is too small to hold
     *  the initial padding bits and length.  If so, we will pad the
     *  block, process it, and then continue padding into a second
     *  block.
     */
	if (ulBlockOffset > 55)
	{
		f_pSha1Context->abyMessageBlock[ulBlockOffset] = 0x80;
		for (ulIndex = ulBlockOffset + 1; ulIndex < cLICENSING_SHA1_BLOCK_SIZE_BYTES; ulIndex++)
		{
			f_pSha1Context->abyMessageBlock[ulIndex] = 0;
		}

		/* Accumulate hash over block */
		_LicensingSHA1ProcessBlock(&f_pSha1Context->abyMessageBlock[0],
			&f_pSha1Context->aulIntermediateHash[0]);

		for (ulIndex = 0; ulIndex < 56; ulIndex++)
		{
			f_pSha1Context->abyMessageBlock[ulIndex] = 0;
		}
	}
	else
	{
		f_pSha1Context->abyMessageBlock[ulBlockOffset] = 0x80;
		for (ulIndex = ulBlockOffset + 1; ulIndex < 56; ulIndex++)
		{
			f_pSha1Context->abyMessageBlock[ulIndex] = 0;
		}
	}

	/*
     *  Store the message length as the last 8 octets
     */
	f_pSha1Context->abyMessageBlock[56] = 0;
	f_pSha1Context->abyMessageBlock[57] = 0;
	f_pSha1Context->abyMessageBlock[58] = 0;
	f_pSha1Context->abyMessageBlock[59] = (ulMessageSize >> 31);
	f_pSha1Context->abyMessageBlock[60] = ((ulMessageSize << 3) >> 24);
	f_pSha1Context->abyMessageBlock[61] = ((ulMessageSize << 3) >> 16);
	f_pSha1Context->abyMessageBlock[62] = ((ulMessageSize << 3) >> 8);
	f_pSha1Context->abyMessageBlock[63] = ((ulMessageSize << 3) >> 0);

	/* Accumulate hash over block */
	_LicensingSHA1ProcessBlock(&f_pSha1Context->abyMessageBlock[0],
		&f_pSha1Context->aulIntermediateHash[0]);

	/* Prepare return value */
	for (ulIndex = 0; ulIndex < cLICENSING_SHA1_HASH_SIZE_BYTES; ulIndex++)
	{
		f_pbyHash[ulIndex] = (f_pSha1Context->aulIntermediateHash[ulIndex >> 2] >> (8 * (3 - (ulIndex & 0x03))));
	}

	return;
}


/*-------------------------------------------------------------------------*\

Function:		LicensingRadix64Crc

Description:	According to RFC2440:  The CRC is computed by using the
				generator 0x864CFB and an initialization of 0xB704CE.  The
				accumulation is done on the data before it is converted to
				radix-64, rather than on the converted data.

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
#define CRC24_INIT 0xB704CE
#define CRC24_POLY 0x1864CFB
static tOCT_UINT32 _LicensingRadix64Crc(
	tOCT_UINT8* f_pbyOctets,
	tOCT_UINT32 f_ulLength)
{
	tOCT_UINT32 ulCrc = CRC24_INIT;
	tOCT_INT32 i;

	while (f_ulLength--)
	{
		//printf("f_pbyOctets = %x \n",*f_pbyOctets );
	
		ulCrc ^= (*f_pbyOctets++) << 16;

		for (i = 0; i < 8; i++)
		{
			ulCrc <<= 1;
			if (ulCrc & 0x1000000)
				ulCrc ^= CRC24_POLY;
		}
		//printf(" %x      \n",ulCrc  );
	}
	return ulCrc & 0xFFFFFF;
}

/*-------------------------------------------------------------------------*\

Function:		LicensingRadix64Decode

Description:	The LicensingRadix64Decode() function Decodes the buffer
				pointed to by f_pbyInBuffer from Radix-64 format, as specified
				in RFC2440. This includes the verification of a CRC-24 over
				f_pbyInBuffer.

-------------------------------------------------------------------------------
|	Argument		|	Description
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/
static tOCT_UINT32 _LicensingRadix64Decode(
	tOCT_UINT8* f_pbyInBuffer,
	tOCT_INT32 f_ulInBufferSize,
	tOCT_UINT8* f_pbyOutBuffer,
	tOCT_UINT32* f_pulOutBufferSize)
{
	tOCT_UINT32 ulRc = OCT_RC_OK;
	tOCT_UINT32 ulCalculatedCrc;
	tOCT_INT32 i, z;
	tOCT_INT32 iReadPtr = 0;
	tOCT_INT32 iWritePtr = 0;
	tOCT_UINT8 cCurrentChar;
	tOCT_UINT32 ulCharFoundFlag;
	tOCT_UINT32 ulCrc;
	tOCT_UINT32 ulLength;
	tOCT_UINT8 a[4];
	tOCT_UINT8 b[4];
	tOCT_UINT8 abyOutput[3];

	while (ulRc == OCT_RC_OK)
	{
		for (i = 0; i < 4; i++)
		{
			/* Skip carriage return, line feeds, extra crap. */
			ulCharFoundFlag = 0;

			while (iReadPtr != f_ulInBufferSize)
			{
				cCurrentChar = f_pbyInBuffer[iReadPtr];
				iReadPtr++;

				if (cCurrentChar > ' ')
				{
					ulCharFoundFlag = 1;
					break;
				}
			}

			/* Check for end of buffer. */
			if ((iReadPtr == f_ulInBufferSize) && (ulCharFoundFlag == 0))
			{
				if (i > 0)
				{
					/* printf("base64 encoded stream incomplete.\n"); */
					printf("_LicensingRadix64Decode cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_TO_SMALL-1\n");
					ulRc = cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_TO_SMALL;
					break;
				}

				/* Correct return point -- no padding at the end of the message */
				*f_pulOutBufferSize = iWritePtr;

				goto CheckSum;
			}

			/* Convert the characters */
			if ((cCurrentChar >= 'A') && (cCurrentChar <= 'Z'))
			{
				b[i] = (cCurrentChar - 0x41);
			}
			else if ((cCurrentChar >= 'a') && (cCurrentChar <= 'z'))
			{
				b[i] = (cCurrentChar - (0x61 - 26));
			}
			else if ((cCurrentChar >= '0') && (cCurrentChar <= '9'))
			{
				b[i] = (cCurrentChar + (52 - 0x30));
			}
			else if (cCurrentChar == '+')
			{
				b[i] = 62;
			}
			else if (cCurrentChar == '/')
			{
				b[i] = 63;
			}
			else if (cCurrentChar == '=')
			{
				b[i] = 0;
			}
			else
			{
				/* Provided data is not Radix-64! */

				/* printf( "Illegal character '%c' in base64 encoded input stream.\n", c ); */
				printf("_LicensingRadix64Decode cOCTADF_UTIL_LICENSE_RC_BASE64_ENCODING_INVALID-1\n");
				ulRc = cOCTADF_UTIL_LICENSE_RC_BASE64_ENCODING_INVALID;
				break;
			}

			a[i] = cCurrentChar;
		}

		abyOutput[0] = (b[0] << 2) | (b[1] >> 4);
		abyOutput[1] = (b[1] << 4) | (b[2] >> 2);
		abyOutput[2] = (b[2] << 6) | b[3];

		i = a[2] == '=' ? 1 : (a[3] == '=' ? 2 : 3);

		for (z = 0; z < i; z++)
		{
			f_pbyOutBuffer[iWritePtr] = abyOutput[z];
			iWritePtr++;

			if ((tOCT_UINT32)iWritePtr == *f_pulOutBufferSize)
			{
				printf("_LicensingRadix64Decode cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_TO_SMALL-2\n");			
				ulRc = cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_TO_SMALL;
				break;
			}
		}

		if (i < 3)
		{
			/* Correct return point, the message was padded. */
			*f_pulOutBufferSize = iWritePtr;

			goto CheckSum;
		}
	}

	/* An error occurred. */
	return ulRc;

CheckSum:

	/* Do not try to extract checksum if we are recursing. */
	if (f_ulInBufferSize > 4)
	{
		/* Look for CRC. */
		for (;;)
		{
			cCurrentChar = f_pbyInBuffer[iReadPtr];
			if ((cCurrentChar > ' ') && (cCurrentChar != '='))
			{			
			   //printf("0x%x 0x%x 0x%x 0x%x readPtr = %d,\n", f_pbyInBuffer[iReadPtr] , f_pbyInBuffer[iReadPtr+1], f_pbyInBuffer[iReadPtr+2],f_pbyInBuffer[iReadPtr+3] ,  iReadPtr );
				/* Recurse to extract CRC value. */
				ulLength = 4;
				ulRc = _LicensingRadix64Decode(&f_pbyInBuffer[iReadPtr], 4,
					(tOCT_UINT8*)&ulCrc, &ulLength);
				if (ulRc == OCT_RC_OK)
				{				
					//printf("ulCrc = %x  swapped %x\n", ulCrc , htonl(ulCrc));
					ulCrc = mOCT_SWAP32_IF_LE(ulCrc);
					/* Only 24-bits are used. */
					ulCrc >>= 8;
					/* Calculate. */
					//printf("f_pbyOutBuffer %x %x %x %x size = %d \n",f_pbyOutBuffer[0],f_pbyOutBuffer[1],f_pbyOutBuffer[2],f_pbyOutBuffer[3], *f_pulOutBufferSize);
					ulCalculatedCrc = _LicensingRadix64Crc(f_pbyOutBuffer, *f_pulOutBufferSize);
					
					/* Compare*/
					if (ulCrc != ulCalculatedCrc)
					{
						printf("_LicensingRadix64Decode cOCTADF_UTIL_LICENSE_RC_CRC24_INVALID-1 ulCrc = 0x%x , ulCalculatedCrc = 0x%x ulLen = %d\n", ulCrc , ulCalculatedCrc , ulLength); 		
						ulRc = cOCTADF_UTIL_LICENSE_RC_CRC24_INVALID;
					} 
				}
				else
				{
					printf("_LicensingRadix64Decode cOCTADF_UTIL_LICENSE_RC_CRC24_INVALID-2\n");						
					ulRc = cOCTADF_UTIL_LICENSE_RC_CRC24_INVALID;
				}

				break;
			}

			iReadPtr++;

			if (iReadPtr >= f_ulInBufferSize)
			{
				printf("_LicensingRadix64Decode cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_TO_SMALL-3\n");									
				ulRc = cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_TO_SMALL;
				break;
			}
		}
	}

	/* Hopefully, CRC-24 matched and message is valid. */
	return ulRc;
}


// z = a * b;
// z must contain a+b words.
static tOCT_UINT32  lm_mul(const MPI* a, const MPI* b, MPI* z)
{
	tOCT_UINT32 i, j;

	if ((a->num_words + b->num_words) != z->num_words)
		return cOCTADF_UTIL_LICENSE_RC_LM_ERROR;

	i = sizeof(tOCT_UINT16) * z->num_words;
	mOADF_BUILTIN_MEMSET(z->n, 0x00, i);

	for (i = 0; i < a->num_words; i++)
	{
		tOCT_UINT32 an = a->n[i];

		for (j = 0; j < b->num_words; j++)
		{
			tOCT_UINT16* zp = &z->n[i + j];
			tOCT_UINT32 x = an * b->n[j];
			tOCT_UINT32 oldz;
			tOCT_UINT32 carry = 0;

			oldz = *zp, *zp += (x & 0xFFFF) + carry, carry = (*zp++ < (oldz + carry));
			oldz = *zp, *zp += (x >> 16) + carry, carry = (*zp++ < (oldz + carry));

			// Propagate the carry until it is zero.
			while (carry != 0)
				carry = (++*zp++ == 0);
		}
	}

	return OCT_RC_OK;
}


// z = a % b;
// z must contain b words.
// there are no restrictions on the number of dwords in a.
// return OCT_RC_OK if everything's good. otherwise error.
// could be a division by 0.
static tOCT_UINT32 lm_mod(const MPI* a, const MPI* b, MPI* z)
{
	tOCT_UINT16 w2[((sizeof(MPI) + cLICENSING_PUBLIC_KEY_SIZE_BYTES * 2) + 4) / 2];
	tOCT_UINT16* w;
	tOCT_UINT32 w_num_words = (a->num_words > z->num_words) ? a->num_words : z->num_words;
	tOCT_INT32 w_msb;
	tOCT_INT32 b_msb;
	tOCT_UINT32 b_msb_word_p1;

	if (b->num_words != z->num_words)
		return cOCTADF_UTIL_LICENSE_RC_LM_ERROR;

	mOADF_BUILTIN_MEMSET(w2, 0x00, sizeof(w2));
	// Copy a into a working buffer. Setup the MSB pointer.
	w = w2 + 2;
	mOADF_BUILTIN_MEMCPY(w, a->n, sizeof(tOCT_UINT16) * a->num_words);
	w[w_num_words] = 0xFFFF; // This prevents access vioation through borrow overflow.


	// Find the MSB of w & b.
	w_msb = (a->num_words * 16) - 1;
	b_msb = (b->num_words * 16) - 1;

	while (b_msb >= 0 && ((b->n[b_msb >> 4] >> (b_msb & 0xF)) & 0x1) == 0)
		b_msb--;

	// Prevent division by zero.
	if (b_msb == -1)
		return cOCTADF_UTIL_LICENSE_RC_LM_ERROR;

	// Extract the normalized MSB dword of b.
	if (b_msb < 16)
		return cOCTADF_UTIL_LICENSE_RC_LM_ERROR;

	b_msb_word_p1 = b->n[(b_msb >> 4) - 0] << (15 - (b_msb & 0xF));
	b_msb_word_p1 |= b->n[(b_msb >> 4) - 1] >> ((b_msb & 0xF) + 1);
	b_msb_word_p1 += 1;

	// Perform the division loop;
	for (;;)
	{
		tOCT_UINT32 i, j;
		tOCT_UINT16 me[2];
		tOCT_UINT32 me_sl16;

		// Skip leading zeros in the working buffer.
		while (w_msb >= 0 && ((w[w_msb >> 4] >> (w_msb & 0xF)) & 0x1) == 0)
			w_msb--;

		// Work register is zero or obviously smaller than the modulo register. We are done.
		if (w_msb < 0 || w_msb < b_msb)
			break;

		if (w_msb == b_msb) // We are at the last iteration.
		{
			tOCT_UINT16* wp = w;
			tOCT_UINT32 oldw;
			tOCT_UINT32 carry = 1;

			// Lets be aggressive and assume that we fit once. This is not confirmed though, and the decision
			// may need to be reverted if we were wrong. Lets save the result in case.
			mOADF_BUILTIN_MEMCPY(z->n, w, sizeof(tOCT_UINT16) * z->num_words);

			// Do a straight subtraction.
			for (i = 0; i < b->num_words; i++)
				oldw = *wp, *wp += (~b->n[i] & 0xFFFF) + carry, carry = (*wp++ < (oldw + carry));
			while (carry == 0)
				oldw = *wp, *wp += (~0 & 0xFFFF) + carry, carry = (*wp++ < (oldw + carry));
			break;
		}
		else
		{
			tOCT_UINT32 w_msb_dword;
			tOCT_UINT32 de;
			tOCT_INT32 de_sl;

			// Extract the normalized MSB dword of w.
			w_msb_dword = w[(w_msb >> 4) - 0] << (31 - (w_msb & 0xF));
			w_msb_dword |= w[(w_msb >> 4) - 1] << (15 - (w_msb & 0xF));
			w_msb_dword |= w[(w_msb >> 4) - 2] >> ((w_msb & 0xF) + 1);

			// Estimate the division result, rounding down.
			// 0.50 = 0x80000000 / (0xFFFF+1) = 0x08000;
			// 1.99 = 0xFFFFFFFF / (0x8000+1) = 0x1FFFC;
			de = w_msb_dword / b_msb_word_p1;

			// me = de << (w_msb_dword - b_msb_word - 16);
			de_sl = (w_msb - b_msb - 16);
			if ((de & 0x10000) == 0)
			{
				de <<= 1;
				de_sl--;
			}

			if (de_sl < 0)
			{
				me[0] = de >> (-de_sl);
				me[1] = 0;
				me_sl16 = 0;
			}
			else
			{
				me[0] = de << (de_sl & 0xF);
				me[1] = de >> (16 - (de_sl & 0xF));
				me_sl16 = de_sl >> 4;
			}
		}

		// Multiply and subtract.
		for (i = 0; i < b->num_words; i++)
		{
			tOCT_UINT32 bn = b->n[i];

			for (j = 0; j < 2; j++)
			{
				tOCT_UINT16* wp = &w[i + j + me_sl16];
				tOCT_UINT32 x = ~(bn * me[j]);
				tOCT_UINT32 oldz;
				tOCT_UINT32 carry = 1;

				oldz = *wp, *wp += (x & 0xFFFF) + carry, carry = (*wp++ < (oldz + carry));
				oldz = *wp, *wp += (x >> 16) + carry, carry = (*wp++ < (oldz + carry));

				// Propagate the carry until it is one
				while (carry == 0)
					carry = (--*wp++ != 0xFFFF);

				if (w[w_num_words] != 0xFFFF)
					return cOCTADF_UTIL_LICENSE_RC_LM_ERROR;
			}
		}
	}

	// Save the results (unless borrow overflow occured)
	if (w[w_num_words] == 0xFFFF)
		mOADF_BUILTIN_MEMCPY(z->n, w, sizeof(tOCT_UINT16) * z->num_words);

	return OCT_RC_OK;
}


// returns OCT_RC_OK on success, anything else is a failure.
// z = (m ^^ e) % n;
// n & z must have the same number of words.
// m can have any number of dwords.
// e can have any number of dwords.

static tOCT_INT32 lm_exp_mod(const MPI* m, const MPI* e, const MPI* n, MPI* z)
{
	tOCT_UINT8 abyWBuffer[(sizeof(MPI) + cLICENSING_PUBLIC_KEY_SIZE_BYTES) + 4];
	tOCT_UINT8 abyW2Buffer[(sizeof(MPI) + cLICENSING_PUBLIC_KEY_SIZE_BYTES * 2) + 4];
	tOCT_UINT8 abyZdBuffer[(sizeof(MPI) + cLICENSING_PUBLIC_KEY_SIZE_BYTES) + 4];
	MPI* w;
	MPI* w2;
	MPI* zd;
	tOCT_INT32 e_msb;
	tOCT_INT32 i;
	tOCT_UINT32 ulRc = OCT_RC_OK;

	if (n->num_words != z->num_words)
		return cOCTADF_UTIL_LICENSE_RC_LM_ERROR;

	if (m->num_words > z->num_words)
		return cOCTADF_UTIL_LICENSE_RC_LM_ERROR;

	/* Assign working buffers, allocated on the stack. */
	w = (MPI*)abyWBuffer;
	w2 = (MPI*)abyW2Buffer;
	zd = (MPI*)abyZdBuffer;

	w->num_words = n->num_words;
	w2->num_words = n->num_words * 2;
	zd->num_words = n->num_words;

	// Initialize w working buffer to m.
	ulRc = lm_mod(m, n, w);
	if (ulRc != OCT_RC_OK)
		return ulRc;

	// Initialize z working buffer to 1.
	{
		tOCT_UINT32 ulSize = sizeof(tOCT_UINT16) * z->num_words;
		mOADF_BUILTIN_MEMSET(z->n, 0x00, ulSize);
		z->n[0] = 0x0001;
	}

	// Find the size of the exponent (in bits).
	e_msb = (e->num_words * 16) - 1;
	while (e_msb >= 0 && ((e->n[e_msb >> 4] >> (e_msb & 0xF)) & 0x1) == 0)
		e_msb--;

	for (i = 0; i <= e_msb; i++)
	{
		// Calculate z*w. Crush result or not to avoid calculation based time vulnerability.
		ulRc = lm_mul(z, w, w2);
		ulRc |= lm_mod(w2, n, ((e->n[i >> 4] >> (i & 0xF)) & 0x1) ? z : zd);

		// Calculate w^2.
		ulRc |= lm_mul(w, w, w2);
		ulRc |= lm_mod(w2, n, w);

		if (ulRc != OCT_RC_OK)
			break;
	}

	return ulRc;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		AdfUtilLicenseValidateContent_
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static tOCT_UINT32 AdfUtilLicenseValidateContent_(
	tOCT_INT8* f_pContent, tOCT_UINT32 f_ulContentLength, MPI* f_pPublicKeyN, MPI* f_pPublicKeyE)
{
	tLICENSING_SHA1_CONTEXT Sha1Context;
	tOCT_UINT8 abyDecodedSignature[300];

	tOCT_UINT8 aszTmp[cBUF_SIZE]; // attached signature is expected to be 395 characters
	tOCT_UINT8 abyComputedHash[cLICENSING_SHA1_HASH_SIZE_BYTES];
	tOCT_UINT8* pbyDecodedSignature;
	tOCT_UINT32 ulDecodedSignatureSize;
	tOCT_UINT32 ulCharacterPosition;
	tOCT_UINT32 ulRc = OCT_RC_OK;
	
	l_pCurrContent = f_pContent;
	l_pMaxContent = f_pContent + f_ulContentLength;

	pbyDecodedSignature = abyDecodedSignature;

	/* The first 2 lines must be the signature header */
	if ((tOCT_UINT32)_LicensingStrGets((tOCT_INT8*)aszTmp, sizeof(aszTmp) ))
	{
		/* First line should be "-----BEGIN PGP SIGNED MESSAGE-----" */
		if (mOADF_BUILTIN_STRNCMP((tOCT_INT8*)aszTmp, "-----BEGIN ", 11) != 0)
		{
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_MISSING-1\n");
			return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_MISSING;
		}
	}
	else
	{
		printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_MISSING-2\n");
		return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_MISSING;
	}

	if ((tOCT_UINT32)_LicensingStrGets((tOCT_INT8*)aszTmp, cBUF_SIZE))
	{
		/* Second line should be "Hash: SHA1"  */
		if (mOADF_BUILTIN_STRNCMP((tOCT_INT8*)aszTmp, "Hash: SHA1", 10) != 0)
		{		
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-1\n");
			return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
		}
	}
	else
	{	
		printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-2\n");
		return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
	}

	if ((tOCT_UINT32)_LicensingStrGets((tOCT_INT8*)aszTmp, cBUF_SIZE ))
	{
		/* Third line should be empty */
		if ((aszTmp[0] != '\n') && (aszTmp[0] != '\r'))
		{	
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-3\n");
			return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
		}
	}
	else
	{
		printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-4\n");
		return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
	}


/* Start computing the hash */
	_LicensingSHA1Intitialize( &Sha1Context );

	/* Look for the start of the body */
	for (;;)
	{
		/* Get the next line */
		if( !(tOCT_UINT32)_LicensingStrGets( (tOCT_INT8 *)aszTmp, cBUF_SIZE ) )
		{
			ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;			
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-5\n");
			break;
		}

		/* Look for [AUTH_BEGIN] tag (meanwhile, anything not commented out is an error) */
		if (mOADF_BUILTIN_STRNCMP( (tOCT_INT8 *)aszTmp, "[AUTH_BEGIN]", 12 ) == 0 )
		{
			/* Add this line to the hash */
			_LicensingSHA1AccumulateLine(cOCT_TRUE, &Sha1Context, aszTmp );

			/* Found what we were looking for; on to the next item(s) */
			break;
		}
		else
		{
			/* There shouldn't be anything else than comments or empty lines in this section */
			if( ( aszTmp[ 0 ] != '#' ) &&
				( aszTmp[ 0 ] != '\r' ) &&
				( aszTmp[ 0 ] != '\n' ) )
			{
				printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-6\n");
				return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
			}

			/* Add this line to the hash */
			_LicensingSHA1AccumulateLine(cOCT_TRUE, &Sha1Context, aszTmp );
		}
	}

	/* Everything here has meaning to us; parse */
	while (ulRc == OCT_RC_OK)
	{
		/* Get the next line */
		if (!(tOCT_UINT32)_LicensingStrGets((tOCT_INT8*)aszTmp, cBUF_SIZE))
		{
			/* Out of data! */
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-7\n");			
			ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
			break;
		}

		/* Skip commented-out or empty lines */
		if ((aszTmp[0] == '#') ||
			(aszTmp[0] == '\r') ||
			(aszTmp[0] == '\n'))
		{
			/* Nothing to do! */
		}	/* Look for a closing [AUTH_END] tag */
		else if (mOADF_BUILTIN_STRNCMP((tOCT_INT8*)aszTmp, "[AUTH_END]", 10) == 0)
		{
			/* Need to accumulate this as binary data since the trailing blanks
			  (including the ending newline) are to be removed */

			/* NOTE: Enforcing the last characters to be this string is a limitation */
			/* of our signature checking mechanism. We could modify our approach */
			/* and let the user add comments below the [AUTH_END] statement, but this */
			/* would make the code a little more complicated. Some day... */

			/* RFC2440 does not enforce this... */

			_LicensingSHA1AccumulateData(&Sha1Context, aszTmp, 10);

			/* Bail out; anything else is not to be interpreted by us, but should be hashed in. */
			break;
		}
		/* Add this line to the hash */
		_LicensingSHA1AccumulateLine(cOCT_TRUE,&Sha1Context, aszTmp);
	}

	/* Next, we should find the beginning of the signature */
	while (ulRc == OCT_RC_OK)
	{
		if ((tOCT_UINT32)_LicensingStrGets((tOCT_INT8*)aszTmp, cBUF_SIZE))
		{
			/* First line should be "-----BEGIN PGP SIGNATURE-----" */
			if (mOADF_BUILTIN_STRNCMP((tOCT_INT8*)aszTmp, "-----BEGIN ", 11) == 0)
			{
				/* We have found the signature! */
				/* Done with hashing. */
				break;
			}

			/* Anything else should be an empty line or comments. */
			if ((aszTmp[0] == '#') ||
				(aszTmp[0] == '\r') ||
				(aszTmp[0] == '\n'))
			{
				/* Nothing to do! */
			}
			else
			{
				printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-8\n"); 					
				ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
			}
		}
		else
		{
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-9\n"); 							
			ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
		}

		/* Add this line to the hash */
		_LicensingSHA1AccumulateLine(cOCT_TRUE,&Sha1Context, aszTmp);
	}

	/* Look for the first empty line, which is the beginning of the signature itself */
	if (ulRc == OCT_RC_OK)
	{
		do
		{
			/* Get the next line */
			if (!(tOCT_UINT32)_LicensingStrGets((tOCT_INT8*)aszTmp, cBUF_SIZE ))
			{
				/* End of file reached without finding the beginning of the signature.. Abort! */
				printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-10\n"); 											
				ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
				break;
			}

		} while ((aszTmp[0] != '\n') && (aszTmp[0] != '\r'));
	}
	else
	{
		assert(0);
	}
	
	ulCharacterPosition = 0;

	/* Look for the end of the signature, accumulating lines along the way as this is the radix64-encoded hash */
	while (ulRc == OCT_RC_OK)
	{
		/* Get the next line */
		if (!(tOCT_UINT32)_LicensingStrGets(
				(tOCT_INT8*)&aszTmp[ulCharacterPosition], cBUF_SIZE - ulCharacterPosition))
		{
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-11\n");													
			ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
		}
		else
		{
			/* Is this the end of the signature ("-----END PGP SIGNATURE-----")? */
			if (mOADF_BUILTIN_STRNCMP((tOCT_INT8*)&aszTmp[ulCharacterPosition + 0], "-----END ", 9) == 0)
			{
				printf("License File read successfully\n");
				/* This is the end of the radix64-encoded data; bail out */
				break;
			}
			else
			{
				/* Move the character pointer to the next position */
				ulCharacterPosition = ulCharacterPosition + mOADF_BUILTIN_STRLEN((tOCT_INT8*)&aszTmp[ulCharacterPosition]);

				/* Is there some romm left in the temporary buffer? */
				if (ulCharacterPosition >= cBUF_SIZE)
				{
					/* We need to stop parsing or we would overflow. Anyway, aszTmp
					 * is dimensionned adequately to hold the entire signature and
					 * should not overflow. We can therefore conclude that the file
					 * is corrupt somehow */
					printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_CORRUPTED-1\n");																		 
					ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_CORRUPTED;
				}
			}
		}
	}

	/* Use "gpg --clearsign [-u <email>] license.lic" to sign license file with SHA-1 */
	/* This will ask you for the key password and then will create license.lic.asc */
	/* with appropriate cleartext base64 encoded signature */

	if (OCT_RC_OK == ulRc)
	{
		/* Decode the signature */
		ulDecodedSignatureSize = sizeof(abyDecodedSignature);
		//printf("aszTmp buffer 0x%x 0x%x 0x%x 0x%x ,\n", aszTmp[0] , aszTmp[1], aszTmp[2],aszTmp[3] );

		ulRc = _LicensingRadix64Decode(
			aszTmp,
			ulCharacterPosition,
			pbyDecodedSignature,
			&ulDecodedSignatureSize);
		if (OCT_RC_OK == ulRc)
		{
			/* This singature is an RFC2440-compliant signature packet; we
			   only support version 3 format, for a specific public key size
			   so the first few bytes are always the same. */
			if ((pbyDecodedSignature[0] != 0x89) || /* Packet tag -- tag number 2 */
				(pbyDecodedSignature[1] != 0x01) || /* One-Octet packet length field */
				(pbyDecodedSignature[2] != 0x15) || /* Actual packet length:  21 bytes. */
				(pbyDecodedSignature[3] != 0x03) || /* One-octet version number (3). */
				(pbyDecodedSignature[4] != 0x05) || /* One-octet length of following hashed material.  MUST be 5.  -
													   One-octet signature type. - Four-octet creation time. */
				(pbyDecodedSignature[5] !=
					0x01) || /* - One-octet signature type, (1) - Signature of a canonical text document. */
				/* Typically, this means the signer owns it, created it, or */
				/* certifies that it has not been modified.  The signature is */
				/* calculated over the text data with its line endings converted */
				/* to <CR><LF> and trailing blanks removed. */
				/* [6-9] Creation time. */
				/* [10-17] Eight-octet key ID of signer. */
				(pbyDecodedSignature[18] != 0x01) || /* One-octet public key algorithm. */
				(pbyDecodedSignature[19] != 0x02)) /* One-octet hash algorithm, SHA-1. */
			/* [20-21] Two-octet field holding left 16 bits of signed hash value. */
			{
				printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-12\n");																		 			
				ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
			}
		}		
		else
		{
			assert(0);
		}
	}
	else
	{
		assert(0);
	}

	if (OCT_RC_OK == ulRc)
	{
		/* Add the signature type & timestamp, as per RFC2440 */
		_LicensingSHA1AccumulateData(&Sha1Context, &pbyDecodedSignature[5], 5);

		/* Compute the hash */
		_LicensingSHA1Finalize(&Sha1Context, &abyComputedHash[0]);

		/* Save some MIPS by performing a comparison of the first 2 octets of the hash */
		if ((abyComputedHash[0] != pbyDecodedSignature[20]) ||
			(abyComputedHash[1] != pbyDecodedSignature[21]))
		{
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-13\n");																							
			ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
		}
	}
	else
	{
		assert(0);
	}

	/* Carry on and match against the provided public key. */
	if (OCT_RC_OK == ulRc)
	{
		tOCT_UINT16* pusNavigator;
		tOCT_UINT32 ulIndex;
		MPI128 Cyphertext;
		MPI128 Plaintext;
		unsigned short tmp = mOCT_SWAP16_IF_LE(*((tOCT_UINT16*)&pbyDecodedSignature[22]));

		Cyphertext.num_words = ((tmp + 7) >> 4);
		if (Cyphertext.num_words != (cLICENSING_PUBLIC_KEY_SIZE_BITS >> 4))
		{
			/* Key size is not what's expected..  We expect a key size of 2048 bits. */
			printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_KEY_SIZE_INVALID-1 Cyphertext.num_words = %d , %d\n", Cyphertext.num_words , ((cLICENSING_PUBLIC_KEY_SIZE_BITS >> 4)));																										
			ulRc = cOCTADF_UTIL_LICENSE_RC_KEY_SIZE_INVALID;
		}
		else
		{
			Plaintext.num_words = Cyphertext.num_words;
			pusNavigator = (tOCT_UINT16*)&pbyDecodedSignature[24 + (Cyphertext.num_words << 1) - 2];
			for (ulIndex = 0; ulIndex < Cyphertext.num_words; ulIndex++, pusNavigator--)
			{
				Cyphertext.n[ulIndex] = mOCT_SWAP16_IF_LE(*pusNavigator);
			}

			{
				ulRc = lm_exp_mod((MPI*)&Cyphertext, f_pPublicKeyE, f_pPublicKeyN, (MPI*)&Plaintext);
				if (OCT_RC_OK == ulRc)
				{
					/* Compare the hashes (which are 160 bits) */
					pusNavigator = (tOCT_UINT16*)&abyComputedHash[20 - 2];
					for (ulIndex = 0; ulIndex < 10; ulIndex++, pusNavigator--)
					{
						/* If the hashes do not match, Signature is invalid */
						if (Plaintext.n[ulIndex] != mOCT_SWAP16_IF_LE(*pusNavigator))
						{
							printf("AdfUtilLicenseValidateContent_ cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID-14\n");																													
							ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
							break;
						}
					}
				}
			}
		}
	}
	else
	{
		assert(0);
	}
	//printf("AdfUtilLicenseValidateContent_ RetValue = %d\n",ulRc);																													
	return ulRc;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		AdfUtilLicenseProcessPubKey_
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

static tOCT_UINT32 AdfUtilLicenseProcessPubKey_(tOCT_INT8* f_pKey, tOCT_UINT32 f_ulKeyLength, 
			MPI *f_pPublicKeyN, MPI* f_pPublicKeyE )
{
	tOCT_UINT8 *pbyBuffer= (tOCT_UINT8*)f_pKey;
	tOCT_UINT32 ulRc = OCT_RC_OK;
	tOCT_UINT32 ulKeySize = f_ulKeyLength;
	tOCT_UINT32 ulCurrentKey;
	tOCT_UINT32 ulReadIdx = 0;
	MPI* pCurrentKey;
		
	/* Is this a supported (binary) key file? */
	if (pbyBuffer[0] == 0x99 && /* Magic Byte: 0x99 */
		pbyBuffer[3] == 0x04 && /* Version Number: 4 */
		pbyBuffer[8] == 0x01) /* Public-Key Algorithm: RSA (Encrypt + Sign) */
	{
		ulReadIdx += 9;
		/* Following in the key file are the algorithm specific fields. */

		/* Read in algorithm specific fields. */

		/* The format of the binary key is defined in RFC2440, PGP packet format. */
		for (ulCurrentKey = 0; (ulCurrentKey < 2) && (ulRc == OCT_RC_OK); ulCurrentKey++)
		{
			tOCT_UINT32 ulIndex;
			tOCT_UINT32 ulLoopCount;
			tOCT_UINT16 usMpiBitSize;
			tOCT_UINT32 ulMpiByteSize;
			tOCT_UINT32 usTemp;
			tOCT_UINT8 byTemp;

			/* Choose current key. */
			if (ulCurrentKey == 0)
				pCurrentKey = f_pPublicKeyN; /* Read in the modulus, supposed to be 2048 bits */
			else
				pCurrentKey = f_pPublicKeyE; /* Read in the exponent, i have seen this value at 6 bits?? */

			/*

			Multi-Precision Integers (As read from binary key file)

			Multi-Precision Integers (also called MPIs) are tOCT_UINT32 integers
			used to hold large integers such as the ones used in cryptographic
			calculations.

			An MPI consists of two pieces: a two-octet scalar that is the length
			of the MPI in bits followed by a string of octets that contain the
			actual integer.

			These octets form a big-endian number; a big-endian (MSB first) number
			can be made into an MPI by prefixing it with the appropriate length.

			Examples:

			(all numbers are in hexadecimal)

			The string of octets [00 01 01] forms an MPI with the value 1. The
			string [00 09 01 FF] forms an MPI with the value of 511.

			Additional rules:

			The size of an MPI is ((MPI.length + 7) / 8) + 2 octets.

			The length field of an MPI describes the length starting from its
			most significant non-zero bit. Thus, the MPI [00 02 01] is not formed
			correctly. It should be [00 01 01].

			*/

			/* Endian is correct.  Read in value directly. */

			//	ulRc = OctSysFileRead( f_pKeyFile, &usTemp, 2, &ulReadSize );
			if ((ulReadIdx + 2) >= ulKeySize)
			{
				/* File read error. */
				printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_INVALID-1\n");																																	
				ulRc = cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_INVALID;
				break;
			}
			else
			{
				usTemp = pbyBuffer[ulReadIdx] << 8;
				usTemp += pbyBuffer[ulReadIdx + 1];
				ulReadIdx += 2;
				ulRc = OCT_RC_OK;
			}

			if (ulRc == OCT_RC_OK)
			{
				usMpiBitSize = usTemp;
				ulMpiByteSize = ((usMpiBitSize + 7) >> 3);
				pCurrentKey->num_words = (ulMpiByteSize + 1) >> 1;

				/* Check key size.. must fit our requirements. */
				if ((ulCurrentKey == 0) &&
					(pCurrentKey->num_words != (cLICENSING_PUBLIC_KEY_SIZE_BITS >> 4)))
				{
					/* Key size is not what's expected..  We expect a key size of 2048 bits. */
					printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_KEY_SIZE_INVALID-1\n"); 																																					
					ulRc = cOCTADF_UTIL_LICENSE_RC_KEY_SIZE_INVALID;
				}
				else
				{
					/* If we had an odd byte count, read one less byte. */
					/* Further processing for this last byte will be done below. */
					if ((ulMpiByteSize & 0x1) == 0x1)
					{
						ulLoopCount = pCurrentKey->num_words - 1;
					}
					else
					{
						ulLoopCount = pCurrentKey->num_words;
					}

					for (ulIndex = 0; ulIndex < ulLoopCount; ulIndex++)
					{
						// ulRc = OctSysFileRead( f_pKeyFile, &usTemp, 2, &ulReadSize );
						if ((ulReadIdx + 2) >= ulKeySize)
						{
							/* File read error. */
							printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_INVALID-2\n"); 																																							
							ulRc = cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_INVALID;
							break;
						}
						else
						{
							usTemp = pbyBuffer[ulReadIdx] << 8;
							usTemp += pbyBuffer[ulReadIdx + 1];
							ulReadIdx += 2;
							ulRc = OCT_RC_OK;
						}

						if (ulRc == OCT_RC_OK)
						{
							/* Perform MSB to LSB conversion toward our MPI format. */
							pCurrentKey->n[pCurrentKey->num_words - ulIndex - 1] = usTemp;
						}
						else
						{
							printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID-1\n"); 																																													
							ulRc = cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID;
							break;
						}
					}

					if (ulRc == OCT_RC_OK)
					{
						/* If we had an odd byte count, the last byte must be in the LSB (index 0) */
						if ((ulMpiByteSize & 0x1) == 0x1)
						{
							// ulRc = OctSysFileRead( f_pKeyFile, &byTemp, 1, &ulReadSize );
							if ((ulReadIdx + 1) >= ulKeySize)
							{
								/* File read error. */
								printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_INVALID-3\n"); 																																															
								ulRc = cOCTADF_UTIL_LICENSE_RC_BUFFER_SIZE_INVALID;
								break;
							}
							else
							{
								byTemp = pbyBuffer[ulReadIdx];
								ulReadIdx += 1;
								ulRc = OCT_RC_OK;
							}

							if (ulRc == OCT_RC_OK)
							{
								pCurrentKey->n[0] = byTemp;

								/* Then carry on and perform byte re-alignment. */
								/* This piece of code is not well optimized, but statistically */
								/* the exponent is very small and the exponent is the only one that */
								/* can have an odd number of bytes. Oh well. */

								/* Here is a brief explanation of how our MPIs are stored.

								n[0] contains the Least Significant Byte(s).
								n[num_words] contains the Most Significant Byte(s).

								For example, the following 4 bytes integer in a key file:

									0xAA 0xBB 0xCC 0xDD

								Would be represented as:

									n[0] = 0xBBAA;
									n[1] = 0xDDCC;
									n->num_words = 2;

								This works well when the byte count is even, but when the count
								is odd, things must be re-ordered. Consider the following
								5 bytes integer in a key file:

									0xAA 0xBB 0xCC 0xDD 0xEE

								This would represented as:

									n[0] = 0xBBAA;
									n[1] = 0xDDCC;
									n[2] = 0x00EE;
									n->num_words = 3;

								in our MPI definition. This is especially important in the case
								of the exponents, which use a small number of bits (even or odd) */

								/* Only perform byte re-alignment if more then 1 word in the MPI. */
								if (pCurrentKey->num_words > 1)
								{
									for (ulIndex = 1; ulIndex < (pCurrentKey->num_words); ulIndex++)
									{
										pCurrentKey->n[ulIndex - 1] &= 0x00FF;
										pCurrentKey->n[ulIndex - 1] |= ((pCurrentKey->n[ulIndex] & 0xFF) << 8);
										pCurrentKey->n[ulIndex] = ((pCurrentKey->n[ulIndex] & 0xFF00) >> 8);
									}
								}
							}
							else
							{
								printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID-2\n");																																																				
								ulRc = cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID;
							}
						}
					}
				}
			}
			else
			{
				printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID-3\n");																																																
				ulRc = cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID;
			}
		}
	}
	else
	{
		printf("AdfUtilLicenseProcessPubKey_ cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID-4\n");																																														
		ulRc = cOCTADF_UTIL_LICENSE_RC_FORMAT_INVALID;
	}

	return ulRc;
}


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		OctAdfUtilLicenseValidate
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OctAdfUtilLicenseValidate(
	tOCT_INT8* f_pKey, tOCT_UINT32 f_ulKeyLength, tOCT_INT8 * f_pContent, tOCT_UINT32 f_ulContentLength)
{
	tOCT_UINT32 ulRc = OCT_RC_OK;

	/* Encryption keys */
	MPI128 PublicKeyE;
	MPI128 PublicKeyN;

	ulRc = AdfUtilLicenseProcessPubKey_(f_pKey, f_ulKeyLength, (MPI*) &PublicKeyN, (MPI*)&PublicKeyE );
	if (ulRc == OCT_RC_OK)
	{
		ulRc = AdfUtilLicenseValidateContent_(	f_pContent, f_ulContentLength, (MPI*)&PublicKeyN, (MPI*)&PublicKeyE);
	}

	printf("License Validated Successfully\n");
	return ulRc;
}

#if defined(OCT_ENV_TYPE_WINDOWS)
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		OctAdfUtilLicenseDeEncryptContent

	tOCT_INT8 * f_pContent,							IN
	tOCT_UINT32 f_ulContentLength,					IN
	tOCT_UINT8* f_pbEncryptContent,					IN/OUT
	tOCT_UINT32 *f_pulEncryptLength					IN/OUT

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OctAdfUtilLicenseDeEncryptContent(tOCT_UINT16* f_pusKey, tOCT_UINT32 f_ulKeySize, 
		tOCT_UINT8* f_pbEncryptContent, tOCT_UINT32 f_ulEncryptLength,
		tOCT_UINT8* f_pContent, tOCT_UINT32* f_pulContentLength)
{
	tOCT_UINT32 ulRc = OCT_RC_OK;

	/* Encryption keys */
	MPI128 PublicKeyN;
	MPI128 Cyphertext;
	MPI128 Plaintext;
	MPI128 PublicKeyD;

	tOCT_UINT16* pusNavigator;
	tOCT_UINT32 ulIndex;
	unsigned short aPublickKeyN[] = { 63093, 46629, 43371, 13913, 32320, 3469, 8307, 17213, 57574, 614, 60808, 21150,
		35295, 38605, 17159, 53850, 18926, 50268,
		47591, 15966, 17670, 28947, 6550, 35708, 42001, 29506, 46457, 44404, 55248, 2269, 16523, 30318, 51086, 4744,
		56599, 11817, 58795, 8959, 46950,
		61145, 26550, 54142, 53825, 12470, 28617, 13823, 11007, 15018, 53252, 23418, 38436, 3100, 49059, 12775, 45257,
		54597, 56687, 49478, 18055, 44390,
		17305, 43006, 53449, 32832, 37097, 55547, 29149, 5079, 42758, 61904, 57829, 46214, 35438, 58545, 41730, 19576,
		4430, 62828, 42268, 46606, 56219, 26082,
		9009, 60265, 52710, 40255, 18976, 31747, 61826, 15537, 54958, 16601, 2480, 11819, 50651, 57372, 2632, 7202,
		33268, 47856, 995, 45729, 47856, 24037, 46531,
		44892, 17544, 64718, 59563, 62691, 1231, 62895, 27223, 52201, 57959, 41269, 24845, 64394, 25157, 12280, 21399,
		65357, 24087, 61425, 5478, 21141, 8865, 34138 };


	PublicKeyN.num_words = sizeof(aPublickKeyN) / sizeof(unsigned short);
	memcpy(&PublicKeyN.n, aPublickKeyN, sizeof(aPublickKeyN));

	PublicKeyD.num_words = f_ulKeySize >> 1;
	memcpy((char*)&PublicKeyD.n, (char *)f_pusKey, f_ulKeySize);

	Cyphertext.num_words = (f_ulEncryptLength >> 1);
	pusNavigator = (tOCT_UINT16*)f_pbEncryptContent;
	for (ulIndex = 0; ulIndex < Cyphertext.num_words; ulIndex++, pusNavigator++)
	{
		Cyphertext.n[ulIndex] = mOCT_SWAP16_IF_LE(*pusNavigator);
	}
	
	Plaintext.num_words = 0x80;
	mOADF_BUILTIN_MEMSET(&Plaintext.n, 0, sizeof(Plaintext.n));

	ulRc = lm_exp_mod((MPI*)&Cyphertext, (MPI*)&PublicKeyD, (MPI*)&PublicKeyN, (MPI*)&Plaintext);
	if (OCT_RC_OK == ulRc)
	{
		pusNavigator = (tOCT_UINT16*)f_pContent;
		for (ulIndex = 0; ulIndex < Plaintext.num_words; ulIndex++, pusNavigator++)
		{
			 *pusNavigator = mOCT_SWAP16_IF_LE(Plaintext.n[ulIndex]);
		}

		*f_pulContentLength = (Plaintext.num_words << 1);
	}

	return ulRc;

}
#endif // defined(OCT_ENV_TYPE_WINDOWS)

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		OctAdfUtilLicenseEncryptContent

	tOCT_INT8 * f_pContent,							IN
	tOCT_UINT32 f_ulContentLength,					IN
	tOCT_UINT8* f_pbEncryptContent,					IN/OUT
	tOCT_UINT32 *f_pulEncryptLength					IN/OUT

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OctAdfUtilLicenseEncryptContent( tOCT_INT8 * f_pContent, tOCT_UINT32 f_ulContentLength,
	tOCT_UINT8* f_pEncryptContent,	tOCT_UINT32 *f_pulEncryptLength )
{

	tOCT_UINT32 ulRc = OCT_RC_OK;

	/* Encryption keys */
	MPI128 PublicKeyE;
	MPI128 PublicKeyN;
	MPI128 Cyphertext;
	MPI128 Plaintext;

	tOCT_UINT16* pusNavigator;
	tOCT_UINT32 ulIndex;

	unsigned short aPublickKeyN[] = { 63093,46629,43371,13913,32320,3469,8307,17213,57574,614,60808,21150,35295,38605,17159,53850,18926,50268,
		47591,15966,17670,28947,6550,35708,42001,29506,46457,44404,55248,2269,16523,30318,51086,4744,56599,11817,58795,8959,46950,
		61145,26550,54142,53825,12470,28617,13823,11007,15018,53252,23418,38436,3100,49059,12775,45257,54597,56687,49478,18055,44390,
		17305,43006,53449,32832,37097,55547,29149,5079,42758,61904,57829,46214,35438,58545,41730,19576,4430,62828,42268,46606,56219,26082,
		9009,60265,52710,40255,18976,31747,61826,15537,54958,16601,2480,11819,50651,57372,2632,7202,33268,47856,995,45729,47856,24037,46531,
		44892,17544,64718,59563,62691,1231,62895,27223,52201,57959,41269,24845,64394,25157,12280,21399,65357,24087,61425,5478,21141,8865,34138	};

	mOADF_BUILTIN_MEMSET(&PublicKeyN.n, 0, sizeof(PublicKeyN.n));
	mOADF_BUILTIN_MEMSET(&PublicKeyE.n, 0, sizeof(PublicKeyE.n));
	mOADF_BUILTIN_MEMSET(&Plaintext.n, 0, sizeof(Plaintext.n));
	mOADF_BUILTIN_MEMSET(&Cyphertext.n, 0, sizeof(Cyphertext.n));

	PublicKeyN.num_words = sizeof( aPublickKeyN)/sizeof(unsigned short );
	memcpy( &PublicKeyN.n, aPublickKeyN, sizeof(aPublickKeyN));
	
	PublicKeyE.num_words = 1;
	PublicKeyE.n[0] = 0x11;

	Cyphertext.num_words = PublicKeyN.num_words;

	// make sure that we do not encrypt more that key size (-1 short.. = 254b)
	if (f_ulContentLength > sizeof(aPublickKeyN)-2)
		return cOCTADF_UTIL_LICENSE_RC_KEY_SIZE_INVALID;

	Plaintext.num_words = (f_ulContentLength>>1);

	pusNavigator = (tOCT_UINT16*)f_pContent;
	for (ulIndex = 0; ulIndex < Plaintext.num_words; ulIndex++, pusNavigator++)
	{
		Plaintext.n[ulIndex] = mOCT_SWAP16_IF_LE(*pusNavigator);
	}
	if ((f_ulContentLength & 1) == 1)
	{
		char chData = *(f_pContent + (f_ulContentLength-1));
		Plaintext.n[ulIndex] = (unsigned short)((chData<<8)&0xFF00);
		Plaintext.num_words++;
		ulIndex++;
	}	

	ulRc = lm_exp_mod((MPI*)&Plaintext, (MPI*)&PublicKeyE, (MPI*)&PublicKeyN, (MPI*)&Cyphertext);
	if (OCT_RC_OK == ulRc)
	{
		memcpy( f_pEncryptContent,(char *)Cyphertext.n, Cyphertext.num_words<<1 );
		*f_pulEncryptLength = Cyphertext.num_words<<1;
	}
#ifdef PPTEST
	{
		pusNavigator = (tOCT_UINT16*)f_pEncryptContent;
		for (ulIndex = 0; ulIndex < Cyphertext.num_words; ulIndex++, pusNavigator++)
		{
			 *pusNavigator = mOCT_SWAP16_IF_LE(Cyphertext.n[ulIndex]);
		}

		*f_pulEncryptLength = (Cyphertext.num_words << 1);
	}
#endif

	return ulRc;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		AdfUtilLicenseValidateContentDetach_
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
static tOCT_UINT32 AdfUtilLicenseValidateContentDetach_(
	tOCT_INT8* f_pContent, tOCT_UINT32 f_ulContentLength, tOCT_UINT8* f_pSignContent,
		tOCT_UINT32 f_ulSignLength, MPI* f_pPublicKeyN, MPI* f_pPublicKeyE )
{
	tLICENSING_SHA1_CONTEXT Sha1Context;
	tOCT_UINT8 aszTmp[cBUF_SIZE]; // attached signature is expected to be 395 characters
	tOCT_UINT8 abyComputedHash[cLICENSING_SHA1_HASH_SIZE_BYTES];
	tOCT_UINT32 ulRc = OCT_RC_OK;

	/* This singature is an RFC2440-compliant signature packet; we
		only support version 3 format, for a specific public key size
		so the first few bytes are always the same. */
	if ((f_pSignContent[0] != 0x89) || /* Packet tag -- tag number 2 */
		(f_pSignContent[1] != 0x01) || /* One-Octet packet length field */
		(f_pSignContent[2] != 0x15) || /* Actual packet length:  21 bytes. */
		(f_pSignContent[3] != 0x03) || /* One-octet version number (3). */
		(f_pSignContent[4] != 0x05) || /* One-octet length of following hashed material.  MUST be 5.  -
												One-octet signature type. - Four-octet creation time. */
		(f_pSignContent[5] !=
			 0x01) || /* - One-octet signature type, (1) - Signature of a canonical text document. */
		/* Typically, this means the signer owns it, created it, or */
		/* certifies that it has not been modified.  The signature is */
		/* calculated over the text data with its line endings converted */
		/* to <CR><LF> and trailing blanks removed. */
		/* [6-9] Creation time. */
		/* [10-17] Eight-octet key ID of signer. */
		(f_pSignContent[18] != 0x01) || /* One-octet public key algorithm. */
		(f_pSignContent[19] != 0x02)) /* One-octet hash algorithm, SHA-1. */
	/* [20-21] Two-octet field holding left 16 bits of signed hash value. */
	{
		// Test if 0xFF
		if( (f_pSignContent[0] == 0xFF) &&
			(f_pSignContent[1] == 0xFF) &&
			(f_pSignContent[2] == 0xFF) &&
			(f_pSignContent[3] == 0xFF) &&
			(f_pSignContent[4] == 0xFF) &&
			(f_pSignContent[5] == 0xFF) )
			return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_MISSING;
		else if( (f_pSignContent[0] == 0) &&
			(f_pSignContent[1] == 0) &&
			(f_pSignContent[2] == 0) &&
			(f_pSignContent[3] == 0) &&
			(f_pSignContent[4] == 0) &&
			(f_pSignContent[5] == 0) )
			return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_MISSING;
		else
			return cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
	}


	l_pCurrContent = f_pContent;
	l_pMaxContent = f_pContent + f_ulContentLength;

	/* Start computing the hash */
	_LicensingSHA1Intitialize(&Sha1Context);

	/* Look for the start of the body */
	for (;;)
	{
		/* Get the next line */
		if (!(tOCT_UINT32)_LicensingStrGets((tOCT_INT8*)aszTmp, cBUF_SIZE))
		{
			break;
		}

		/* Add this line to the hash */
		_LicensingSHA1AccumulateLine(cOCT_FALSE,&Sha1Context, aszTmp);

	}

	if (OCT_RC_OK == ulRc)
	{
		/* Add the signature type & timestamp, as per RFC2440 */
		_LicensingSHA1AccumulateData(&Sha1Context, &f_pSignContent[5], 5);

		/* Compute the hash */
		_LicensingSHA1Finalize(&Sha1Context, &abyComputedHash[0]);

		/* Save some MIPS by performing a comparison of the first 2 octets of the hash */
		if ((abyComputedHash[0] != f_pSignContent[20]) ||
			(abyComputedHash[1] != f_pSignContent[21]))
		{
			ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
		}
	}

	/* Carry on and match against the provided public key. */
	if (OCT_RC_OK == ulRc)
	{
		tOCT_UINT16* pusNavigator;
		tOCT_UINT32 ulIndex;
		MPI128 Cyphertext;
		MPI128 Plaintext;

		Cyphertext.num_words = ((*((tOCT_UINT16*)&f_pSignContent[22]) + 7) >> 4);
		if (Cyphertext.num_words != (cLICENSING_PUBLIC_KEY_SIZE_BITS >> 4))
		{
			/* Key size is not what's expected..  We expect a key size of 2048 bits. */
			ulRc = cOCTADF_UTIL_LICENSE_RC_KEY_SIZE_INVALID;
		}
		else
		{
			Plaintext.num_words = Cyphertext.num_words;
			pusNavigator = (tOCT_UINT16*)&f_pSignContent[24 + (Cyphertext.num_words << 1) - 2];
			for (ulIndex = 0; ulIndex < Cyphertext.num_words; ulIndex++, pusNavigator--)
			{
				Cyphertext.n[ulIndex] = *pusNavigator;
			}
			ulRc = lm_exp_mod((MPI*)&Cyphertext, f_pPublicKeyE, f_pPublicKeyN, (MPI*)&Plaintext);
			if (OCT_RC_OK == ulRc)
			{
				/* Compare the hashes (which are 160 bits) */
				pusNavigator = (tOCT_UINT16*)&abyComputedHash[20 - 2];
				for (ulIndex = 0; ulIndex < 10; ulIndex++, pusNavigator--)
				{
					/* If the hashes do not match, Signature is invalid */
					if (Plaintext.n[ulIndex] != *pusNavigator)
					{
						ulRc = cOCTADF_UTIL_LICENSE_RC_SIGNATURE_INVALID;
						break;
					}
				}
			}
		}
	}
	return ulRc;
}
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		OctAdfUtilLicenseValidateDetach
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 OctAdfUtilLicenseValidateDetach(
	tOCT_INT8* f_pKey, tOCT_UINT32 f_ulKeyLength, tOCT_INT8* f_pContent, tOCT_UINT32 f_ulContentLength,
	tOCT_UINT8* f_pSignContent, tOCT_UINT32 f_ulSignLength)
{
	tOCT_UINT32 ulRc = OCT_RC_OK;

	/* Encryption keys */
	MPI128 PublicKeyE;
	MPI128 PublicKeyN;

	ulRc = AdfUtilLicenseProcessPubKey_(f_pKey, f_ulKeyLength, (MPI*)&PublicKeyN, (MPI*)&PublicKeyE);

	if (ulRc == OCT_RC_OK)
		ulRc = AdfUtilLicenseValidateContentDetach_(f_pContent, f_ulContentLength, f_pSignContent, f_ulSignLength, 
					(MPI*)&PublicKeyN, (MPI*)&PublicKeyE);

	return ulRc;
}

#endif /* OCT_OPT_REMOVE_LICENSING */


