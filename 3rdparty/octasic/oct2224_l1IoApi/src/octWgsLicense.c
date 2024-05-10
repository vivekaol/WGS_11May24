#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "oct_util_license.h"
#include "octvc1_lic2string.h"
#include "octWgsLicense.h"

 

#define SWAP_BYTE_NIBBLE(l_byBYTE) (((l_byBYTE >> 4) & 0xf) | ((l_byBYTE & 0xF) << 4))
#define ARRAY_COUNT_OF( array ) ( sizeof( array )/sizeof( array[0] ) ) 
#define SIZEOF_PUB_KEY 1024
#define MAX_WGS_FEATURE_LICESNESES 10
tOCT_UINT32 *wgsLicenses;

const static unsigned char l_abyKey_0[] = {
	0x99, 0x52, 0xb0, 0x39, 0x74, 0x29, 0xd8, 0x48,
	0x10, 0x5b, 0x1e, 0x91, 0x19, 0x47, 0x00, 0x57,
	0x1f, 0x41, 0x35, 0x91, 0x0f, 0x54, 0xf6, 0xd2,
	0xa0, 0x36, 0x14, 0x91, 0x1a, 0x99, 0x47, 0x0d,
	0xac, 0x57, 0x77, 0x2d, 0xae, 0x63, 0x36, 0xb8,
	0x30, 0xbc, 0x96, 0x7b, 0x8c, 0xda, 0xf6, 0x29,
	0xf6, 0x72, 0xc3, 0x40, 0x02, 0xc9, 0x07, 0x7b,
	0xf5, 0xf2, 0x04, 0xae, 0xb2, 0x8f, 0x16, 0xdb,
	0x95, 0x56, 0xe2, 0x98, 0x11, 0x8f, 0xe3, 0xa6,
	0xcf, 0x2c, 0x40, 0xbb, 0xbb, 0x8c, 0x00, 0x3b,
	0xa9, 0xfe, 0x74, 0xe0, 0xc4, 0x44, 0x20, 0x5c,
	0x0b, 0x57, 0xb0, 0xe9, 0x64, 0xcf, 0x30, 0x5c,
	0x1a, 0x80, 0x20, 0x02, 0x06, 0x1a, 0x61, 0x53,
	0xe5, 0xff, 0x20, 0x6e, 0xab, 0x40, 0x71, 0x90,
	0xdf, 0x4f, 0x90, 0xfa, 0x4a, 0xc0, 0xa0, 0x84,
	0xdb, 0x0b, 0xd5, 0x96, 0xd6, 0x05, 0x80, 0x2e };

const static unsigned char l_abyKey_1[] = {
	0x10, 0x2b, 0xc2, 0xab, 0xc0, 0x51, 0xdf, 0xae,
	0x80, 0xe8, 0x00, 0x0e, 0x5a, 0xcc, 0x10, 0x1e,
	0x9c, 0x56, 0x57, 0x8e, 0x07, 0xb8, 0x27, 0x24,
	0xe3, 0xe6, 0x76, 0xfa, 0xa0, 0xc4, 0x02, 0xf4,
	0xfb, 0x5f, 0x77, 0x7d, 0xea, 0x74, 0x47, 0xbd,
	0xdc, 0xcf, 0x36, 0x26, 0xe9, 0x2d, 0xd6, 0x1c,
	0xc7, 0x21, 0x37, 0x9c, 0x58, 0xa9, 0xf6, 0x89,
	0xb4, 0xbf, 0xf6, 0x7e, 0x27, 0x55, 0x37, 0x77,
	0x42, 0x4c, 0x36, 0x6c, 0x2a, 0xe9, 0x98, 0xee,
	0x48, 0x1b, 0x31, 0xdd, 0x1e, 0x5d, 0x02, 0xf5,
	0x74, 0x9c, 0xc0, 0x12, 0xdc, 0xe0, 0xb1, 0x41,
	0x36, 0xf5, 0x90, 0xf5, 0x46, 0xa5, 0x20, 0x22,
	0x41, 0xc4, 0x80, 0xdb, 0xc1, 0xeb, 0x20, 0x93,
	0xd4, 0xba, 0xe1, 0xcd, 0xcd, 0x7b, 0x08, 0x45,
	0x0e, 0xfc, 0x01, 0x96, 0xf3, 0xc6, 0x89, 0x55,
	0xf7, 0x79, 0x8a, 0x31, 0x23, 0x74, 0x00, 0xf8 };

const static unsigned char l_abyKey_2[] = {
	0xd0, 0x5b, 0xad, 0xab, 0x5d, 0xa5, 0x33, 0x00,
	0x00, 0xb7, 0x1a, 0xb2, 0x3d, 0x1a, 0x11, 0x70,
	0x0b, 0x65, 0x4b, 0x13, 0xf4, 0xfd, 0x07, 0x6a,
	0xb8, 0xd0, 0x47, 0xc1, 0xf5, 0xa2, 0x56, 0x9a,
	0x37, 0xab, 0x82, 0x45, 0x4f, 0x39, 0xe2, 0xaa,
	0x6e, 0xb5, 0x16, 0x0a, 0x21, 0x05, 0xe2, 0x6d,
	0x6d, 0xbc, 0x92, 0xbd, 0x0e, 0x52, 0x57, 0x6c,
	0x72, 0x34, 0x27, 0xd6, 0x7e, 0x18, 0x36, 0x92,
	0x87, 0xfb, 0x96, 0x2d, 0xe8, 0x9a, 0xf6, 0x71,
	0x92, 0x4e, 0x10, 0x38, 0x8e, 0x5c, 0x10, 0xc8,
	0x48, 0xc7, 0x50, 0x8f, 0x68, 0xe4, 0x5d, 0xdd,
	0xe7, 0x5e, 0x30, 0x45, 0x90, 0x5d, 0x80, 0xfc,
	0x46, 0x17, 0x40, 0xce, 0xd0, 0xdd, 0x30, 0xc9,
	0xdc, 0x5d, 0x30, 0x65, 0x81, 0xdc, 0x10, 0x8d,
	0x5f, 0xcb, 0x00, 0x11, 0x19, 0x5d, 0x68, 0xf6,
	0xe8, 0x7b, 0x52, 0xdf, 0x1c, 0xe7, 0x52, 0x71 };

const static unsigned char l_abyKey_3[] = {
	0x40, 0xc0, 0xae, 0x87, 0x04, 0x4f, 0x53, 0x4b,
	0x3e, 0x05, 0x67, 0x48, 0x44, 0xcf, 0x10, 0xaf,
	0xce, 0x1e, 0x53, 0x3d, 0x4f, 0xc6, 0x07, 0x96,
	0x75, 0x06, 0x02, 0x9d, 0xc9, 0x96, 0xe6, 0xe9,
	0xdb, 0xb6, 0x77, 0x21, 0x88, 0x1d, 0xf6, 0xd5,
	0xff, 0x84, 0x37, 0xd4, 0xfd, 0xac, 0x36, 0x9b,
	0x28, 0x49, 0x02, 0x9f, 0xcc, 0x28, 0x07, 0x4c,
	0x87, 0x2e, 0x47, 0x44, 0xff, 0xb7, 0x47, 0x48,
	0x9a, 0xfb, 0x36, 0xf9, 0xc1, 0x16, 0xd6, 0x69,
	0x1d, 0x7f, 0x63, 0x02, 0x61, 0x6c, 0x20, 0x27,
	0x65, 0x6f, 0x20, 0xa0, 0xf7, 0x7c, 0x04, 0xed,
	0xc9, 0xe8, 0x60, 0x1c, 0xf1, 0x4f, 0x70, 0x41,
	0x27, 0xf7, 0x51, 0x62, 0x6f, 0x62, 0x40, 0x03,
	0xae, 0x4f, 0x10, 0x8c, 0x7d, 0x3b, 0x20, 0x1f,
	0xd3, 0x7d, 0xa0, 0xd4, 0x47, 0x7e, 0x42, 0xb0,
	0xdf, 0xa9, 0xf2, 0x3b, 0x60, 0x3e, 0x4c, 0x89 };

const static unsigned char l_abyKey_4[] = {
	0xb2, 0xda, 0x15, 0x5f, 0x15, 0xfd, 0x37, 0xd5,
	0x42, 0xbf, 0xbc, 0x6d, 0x65, 0xdd, 0xee, 0xba,
	0xcf, 0x10, 0xbe, 0x84, 0x03, 0x73, 0x30, 0xda,
	0x46, 0x5f, 0x6b, 0x4f, 0x4c, 0xfa, 0x40, 0x4d,
	0x14, 0x5d, 0xaa, 0xfa, 0xa5, 0x2e, 0x1c, 0xbb,
	0x09, 0x1a, 0xab, 0xad, 0xd9, 0x70, 0x11, 0x5d,
	0x49, 0x3c, 0x71, 0x0e, 0x07, 0x62, 0x33, 0xab,
	0x75, 0x77, 0x92, 0xdf, 0x5b, 0xa2, 0x6f, 0xee,
	0x78, 0xd3, 0x28, 0x8d, 0x8e, 0x6d, 0x10, 0xbd,
	0xf2, 0x7c, 0x05, 0x85, 0x84, 0xf6, 0xa8, 0x0e,
	0x87, 0x82, 0x69, 0x7a, 0x35, 0x81, 0x6c, 0xe9,
	0x0c, 0x4a, 0xd9, 0x2a, 0xda, 0x3f, 0x18, 0x55,
	0x13, 0x60, 0xa1, 0xf7, 0xea, 0xbe, 0xef, 0xd6,
	0x0c, 0x4e, 0x1b, 0xe9, 0x69, 0x50, 0xe1, 0x85,
	0xe0, 0x98, 0xf3, 0xf7, 0xad, 0xc9, 0xfc, 0xe9,
	0xfc, 0xd9, 0x76, 0x15, 0x9c, 0x80, 0x45, 0x03 };

char octPubKey[SIZEOF_PUB_KEY] = {}; // Get it from Octasic
//char *octPubFingerprint = "D546750FBFC12AB1DC1E40A386240A98252F5DA8";

void readWgsLicFile(char *filename , FILE_SYSTEM_LICENSE_CONFIG_PARSER *wgsLicCtx)
{
	/* declare a file pointer */
	FILE *infile = NULL;
	 
	/* open an existing file for reading */
	infile = fopen(filename, "rb");
	 
	/* quit if the file does not exist */
	assert(infile != NULL);
	 
	/* Get the number of bytes */
	fseek(infile, 0L, SEEK_END);
	wgsLicCtx->ulContentLength = ftell(infile);

	/* reset the file position indicator to 
	the beginning of the file */
	fseek(infile, 0L, SEEK_SET);	
	 
 
	/* copy all the text into the buffer */
	fread(wgsLicCtx->abyFileContent , sizeof(char), wgsLicCtx->ulContentLength , infile);
	fclose(infile);
	 
	/* confirm we have read the file by	outputing it to the console */
	//printf("The file called %s read %d bytes successfully asked %d bytes \n", filename ,tmp,  wgsLicCtx->ulContentLength);

	return; 
}
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		getPubLicKey
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
int getPubLicKey(char* f_pbKey, unsigned int* f_pulKeySize)
{
	unsigned int ulRc = 0;
	unsigned int ulKeyLen;
	unsigned int i = 0;
	unsigned int ulMaxSize = *f_pulKeySize;
	struct keyTbl_Size
	{
		unsigned int ulCount;
		const unsigned char* abyKey;
	} aTblSize[] = {
	{ sizeof(l_abyKey_0), l_abyKey_0 },
	{ sizeof(l_abyKey_1), l_abyKey_1 },
	{ sizeof(l_abyKey_2), l_abyKey_2 },
	{ sizeof(l_abyKey_3), l_abyKey_3 },
	{ sizeof(l_abyKey_4), l_abyKey_4 },
	};

	*f_pulKeySize = 0;

	ulKeyLen = 0;
	for (i = 0; i < ARRAY_COUNT_OF(aTblSize); i++)
	{
		ulKeyLen += aTblSize[i].ulCount;
	}

	if (ulKeyLen < ulMaxSize )
	{
		unsigned int ulByteIndex;
		ulKeyLen = 0;
		for (ulByteIndex = 0; ulByteIndex < sizeof(l_abyKey_0); ulByteIndex += 4)
		{
			f_pbKey[ulByteIndex]	 = SWAP_BYTE_NIBBLE( aTblSize[0].abyKey[ulByteIndex] );
			f_pbKey[ulByteIndex+1]	 = SWAP_BYTE_NIBBLE( aTblSize[1].abyKey[ulByteIndex] );
			f_pbKey[ulByteIndex+2]	 = SWAP_BYTE_NIBBLE( aTblSize[2].abyKey[ulByteIndex] );
			f_pbKey[ulByteIndex+3]	 = SWAP_BYTE_NIBBLE( aTblSize[3].abyKey[ulByteIndex] );

			f_pbKey[ulByteIndex + 128]	 = SWAP_BYTE_NIBBLE( aTblSize[3].abyKey[ulByteIndex+1] );
			f_pbKey[ulByteIndex + 128+1] = SWAP_BYTE_NIBBLE( aTblSize[0].abyKey[ulByteIndex+1] );
			f_pbKey[ulByteIndex + 128+2] = SWAP_BYTE_NIBBLE( aTblSize[1].abyKey[ulByteIndex+1] );
			f_pbKey[ulByteIndex + 128+3] = SWAP_BYTE_NIBBLE( aTblSize[2].abyKey[ulByteIndex+1] );

			f_pbKey[ulByteIndex + 256]	   = SWAP_BYTE_NIBBLE( aTblSize[2].abyKey[ulByteIndex + 2] );
			f_pbKey[ulByteIndex + 256 + 1] = SWAP_BYTE_NIBBLE( aTblSize[3].abyKey[ulByteIndex + 2] );
			f_pbKey[ulByteIndex + 256 + 2] = SWAP_BYTE_NIBBLE( aTblSize[0].abyKey[ulByteIndex + 2] );
			f_pbKey[ulByteIndex + 256 + 3] = SWAP_BYTE_NIBBLE( aTblSize[1].abyKey[ulByteIndex + 2] );

			f_pbKey[ulByteIndex + 384]	   = SWAP_BYTE_NIBBLE( aTblSize[1].abyKey[ulByteIndex + 3] );
			f_pbKey[ulByteIndex + 384 + 1] = SWAP_BYTE_NIBBLE( aTblSize[2].abyKey[ulByteIndex + 3] );
			f_pbKey[ulByteIndex + 384 + 2] = SWAP_BYTE_NIBBLE( aTblSize[3].abyKey[ulByteIndex + 3] );
			f_pbKey[ulByteIndex + 384 + 3] = SWAP_BYTE_NIBBLE( aTblSize[0].abyKey[ulByteIndex + 3] );
		}

		{
			char* pbKeyBegin = &f_pbKey[512];
			char* pbKeyEnd = &f_pbKey[512+127];
			char* pbKey_4Begin = (char*) &aTblSize[4].abyKey[0];
			char* pbKey_4End = (char*) &aTblSize[4].abyKey[127];

			for (ulByteIndex = 0; ulByteIndex < sizeof(l_abyKey_4); ulByteIndex+=2, pbKeyBegin++, pbKey_4Begin++, pbKey_4End--, pbKeyEnd-- )
			{
				*pbKeyBegin = SWAP_BYTE_NIBBLE( *pbKey_4End );
				*pbKeyEnd = SWAP_BYTE_NIBBLE( *pbKey_4Begin );
			}
		}

		for (i = 0; i < ARRAY_COUNT_OF(aTblSize); i++)
		{
			ulKeyLen += aTblSize[i].ulCount;
		}
		*f_pulKeySize = ulKeyLen;
	}
	else
		ulRc = 1;

	return ulRc;
}

tOCT_UINT32 getWgsLicId(tOCT_UINT32 licId)
{
	switch(licId)
	{
#ifdef WGS_LICENSING	
	    case cOCTVC1_WGS_LIC_INTERNAL_ENABLE:
		case cOCTVC1_WGS_LIC_LTE_FDD_ENABLE:
		case cOCTVC1_WGS_LIC_LTE_TDD_ENABLE:
		{
			return cOCT_TRUE;
		}
#endif		
		default:
		{
			return cOCT_FALSE;
		}
	}
	
	return cOCT_FALSE;

}

unsigned char checkWgsFeatureLicense(tOCT_UINT32 ulLicenseId)
{
	int i =0 ;

	for(i=0 ; i<MAX_WGS_FEATURE_LICESNESES; i++)
	{
		if(wgsLicenses[i] == ulLicenseId)
			return cOCT_TRUE;
	}

	return cOCT_FALSE;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		wgsFileSystemLicenseParseFile
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
tOCT_UINT32 wgsFileSystemLicenseParseFile(FILE_SYSTEM_LICENSE_CONFIG_PARSER* f_pFileParser , tOCT_UINT32 *wgsLicFeatureFlags)
{
	tOCT_UINT32 ulNbLicense = 0;	
	tOCT_UINT32 ulRc = 0;
	tOCTVC1_MAIN_LICENSING_STATUS_ENUM ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ACTIVE;
	tOCT_UINT32 ulCtxSize = sizeof(tOADF_FILE_SYSTEM_LICENSE_AUTH_CTX);
	tOADF_FILE_SYSTEM_LICENSE_AUTH_CTX* pAuthCtx;
	tOCT_UINT32 ulProjNumber=0xFFFFFFFF ;
	
	tOCT_UINT32 ulTempRc = OctAdfUtilLicenseValidate(
		f_pFileParser->abyKey, f_pFileParser->ulKeyLength,
		f_pFileParser->abyFileContent, f_pFileParser->ulContentLength);
	
	if (ulTempRc != cOCTVC1_RC_OK)
	{
		if (f_pFileParser->ulContentLength == 0)
		{
			ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_NO_LICENSE_ERROR;
			printf("License File Length is 0 Ret-Value = %d\n", ulTempRc);
		}
		else
		{
			ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_SYSTEM_ERROR;			
			printf("Licensing Error Ret-Value = %d\n", ulTempRc);
		}

		assert(0);
	}
	else
	{
		mOADF_BUILTIN_MEMSET(&f_pFileParser->ConfigCtx, 0, sizeof(f_pFileParser->ConfigCtx));
		
		if( (ulState == cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ACTIVE) ||
			( cOCTVC1_MAIN_LICENSING_STATUS_ENUM_LEGACY == ulState ) )
		{
			// Must be last section to read ... next will follow with read items
			// File content may be empty
			ulTempRc = OctAdfUtilConfigGetFirstSection(
				&f_pFileParser->ConfigCtx, "LICENSES", NULL, 0, f_pFileParser->abyFileContent);
			if (ulTempRc == cOCTVC1_RC_OK)
			{
				ulTempRc = OctAdfUtilConfigGetItemCount(&f_pFileParser->ConfigCtx, "FEATURE", &ulNbLicense);
				if (ulTempRc != cOCTVC1_RC_OK)
				{
					printf("FEATURE item cannot be read from license file\n");
					ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_FILE_ERROR;
				}
				else
				{
					// No feature on legacy
					if (cOCTVC1_MAIN_LICENSING_STATUS_ENUM_LEGACY == ulState)
						ulNbLicense = 0;
				}
			}
			else
			{		
				printf("LICENSES item cannot be read from license file\n");
				ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_FILE_ERROR;
			}
	
		}
	}
	if (ulNbLicense > 1)
		ulCtxSize += (ulNbLicense - 1) * sizeof(tOADF_FILE_SYSTEM_LICENSE_CTX);

	pAuthCtx = (tOADF_FILE_SYSTEM_LICENSE_AUTH_CTX*)malloc(ulCtxSize);
	if (pAuthCtx == NULL)
	{
		assert(0);
	}
	else
		mOADF_BUILTIN_MEMSET(pAuthCtx, 0, ulCtxSize);

	pAuthCtx->ulState = ulState;
	pAuthCtx->usSessionIndex = cOCTADF_LICENSE_STATE_SESSION_EVT_INVALID;

	// Act as legacy if there is no license file or no feature and board is legacy
	if (ulState == cOCTVC1_MAIN_LICENSING_STATUS_ENUM_LEGACY)
		pAuthCtx->ulStateFlag |= cOCTADF_LICENSE_STATE_FLAG_ENUM_LEGACY;

	if( (pAuthCtx->ulState == cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ACTIVE) ||
		( pAuthCtx->ulState == cOCTVC1_MAIN_LICENSING_STATUS_ENUM_LEGACY )	)
	{
		// test if active
		if (ulNbLicense)
		{
			tOCT_INT8 szFeature[128];
			tOCT_UINT32 iLicense = 0;

			if ((ulRc = OctAdfUtilConfigGetFirstItem(
					 &f_pFileParser->ConfigCtx, "FEATURE", szFeature, sizeof(szFeature))) == cOCTVC1_RC_OK)
			{
				do
				{
					tOCT_INT8 szLicenseId[128];
					tOCT_INT8* pszToken;

					// szFeature contain :
					//				LicenseId,BOOLEAN(TRUE/FALSE)
					//				LicenseId,COUNT(23)

					if (iLicense == ulNbLicense)
					{
						pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
						break;
					}

					pAuthCtx->aLicenseCtx[iLicense].ulLicenseId = 0;
					pAuthCtx->aLicenseCtx[iLicense].ulLicenseTypeMaxCnt = 0;


					pszToken = mOADF_BUILTIN_STRCHR(szFeature, ',');
					if (pszToken)
					{
						mOADF_BUILTIN_STRCPY(szLicenseId, "cOCTVC1_");
						mOADF_BUILTIN_STRNCAT(szLicenseId, szFeature, pszToken - szFeature);
						// terminate the string ... include "cOCTVC1_" (8)
						szLicenseId[8 + (pszToken - szFeature)] = 0;

						pAuthCtx->aLicenseCtx[iLicense].ulLicenseId = octvc1_string2lic(szLicenseId);


						if (pAuthCtx->aLicenseCtx[iLicense].ulLicenseId)
						{
							tOCT_BOOL32 fIsLicenseOk;

							fIsLicenseOk = cOCT_FALSE;
							pszToken++;
							if (mOADF_BUILTIN_STRSTR(pszToken, "BOOLEAN("))
							{
								if (mOADF_BUILTIN_STRSTR(pszToken, "(TRUE)"))
								{
									mOADF_FILE_SYSTEM_LICENSE_SET_BOOLEAN(
										pAuthCtx->aLicenseCtx[iLicense].ulLicenseTypeMaxCnt, cOCT_TRUE);
									fIsLicenseOk = cOCT_TRUE;
								}
								else if (mOADF_BUILTIN_STRSTR(pszToken, "(FALSE)"))
								{
									mOADF_FILE_SYSTEM_LICENSE_SET_BOOLEAN(
										pAuthCtx->aLicenseCtx[iLicense].ulLicenseTypeMaxCnt, cOCT_FALSE);
									fIsLicenseOk = cOCT_TRUE;
								}
								else
								{
									assert(0);
								}
							}
							else if (mOADF_BUILTIN_STRSTR(pszToken, "COUNT("))
							{
								tOCT_INT8 szCount[16];

								if (OctAdfUtilStrExtractSubString(pszToken, '(', ')', szCount, sizeof(szCount)) == NULL)
								{
									assert(0);
								}
								else
								{
									tOCT_INT32 ulMax = atoi(szCount);
									if (ulMax)
									{
										mOADF_FILE_SYSTEM_LICENSE_SET_MAX_COUNT(
											pAuthCtx->aLicenseCtx[iLicense].ulLicenseTypeMaxCnt, ulMax);

										fIsLicenseOk = cOCT_TRUE;
									}
									else
										assert(0);
								}
							}
							else
								assert(0);

							if (fIsLicenseOk)
								iLicense++;
							else
							{
								pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
								break;
							}
						}
					}
					else
					{
						pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
						break;
					}

				} while (
					OctAdfUtilConfigGetNextItem(&f_pFileParser->ConfigCtx, szFeature, sizeof(szFeature)) ==
					cOCTVC1_RC_OK);
			}
			else
			{
				pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
			}

			// Set knowned licenses;
			pAuthCtx->usLicenseCnt = iLicense;
		}
		else
		{
			pAuthCtx->usLicenseCnt = 0;
		}

		if (pAuthCtx->ulState == cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ACTIVE)
		{
			// Get [INFO].PROJNUM
			ulRc = OctAdfUtilConfigGetFirstSection(
				&f_pFileParser->ConfigCtx, "INFO", NULL, 0, f_pFileParser->abyFileContent);
			if (ulRc == cOCTVC1_RC_OK)
			{
				tOCT_INT8 szItem[16];
				if ((ulRc = OctAdfUtilConfigGetFirstItem(
						 &f_pFileParser->ConfigCtx, "PROJNUM", szItem, sizeof(szItem))) == cOCTVC1_RC_OK)
				{
					ulProjNumber = atoi(szItem);
					if (ulProjNumber == 0)
					{
						pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
					}
					else {
						if((ulProjNumber ^ 0x27062017) == 0x27096228)
							pAuthCtx->ulStateFlag |=  cOCTADF_LICENSE_STATE_FLAG_ENUM_EMUL_OTP;
					}

					// May read PROJTYPE to see "SDR" or "MGW" or ???
				}
				else
				{
					pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
				}
			}
			else
			{
				pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
			}

			ulRc = OctAdfUtilConfigGetFirstSection(
				&f_pFileParser->ConfigCtx, "HARDWARE", NULL, 0, f_pFileParser->abyFileContent);
			if (ulRc == cOCTVC1_RC_OK)
			{
				if ((ulRc = OctAdfUtilConfigGetFirstItem(
						 &f_pFileParser->ConfigCtx, "BOARD_TYPE", pAuthCtx->szBoardType, sizeof(pAuthCtx->szBoardType))) !=
					cOCTVC1_RC_OK)
				{
					pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
				}
			}
			else
			{
				pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;
			}
		}
		// Test if Auth fit the PCB
		if(pAuthCtx->ulState == cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ACTIVE)
		{
			printf("Project-Num = %d , Board-Type = %s \n",ulProjNumber , pAuthCtx->szBoardType );
		
/*			// EEPROM is signed .. make sure licence fit this eeprom... no module
			// Test if ulProjNumber are set
			if (ulProjNumber != ulPcbInfoProjId)
			{
				pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;

			}

			// Test if board type are same
			if (mOADF_BUILTIN_STRCMP(pAuthCtx->szBoardType, szPcbInfoBoardType) !=
				0)
			{
				pAuthCtx->ulState = cOCTVC1_MAIN_LICENSING_STATUS_ENUM_ITEM_ERROR;

			}	
*/			
		}
		
	}
	// test for error
	if(pAuthCtx->ulState > cOCTVC1_MAIN_LICENSING_STATUS_ENUM_INACTIVE)
	{
		pAuthCtx->usLicenseCnt = 0;
	}

	ulState = pAuthCtx->ulState;
	
	if (cOCTVC1_RC_OK == ulRc)
	{
		if (( pAuthCtx->ulStateFlag & cOCTADF_LICENSE_STATE_FLAG_ENUM_LEGACY ) == cOCTADF_LICENSE_STATE_FLAG_ENUM_LEGACY )
			ulRc = cOCTVC1_RC_OK;
		else
		{
			tOCT_UINT32 i , j =0;

			ulRc = cOCTVC1_MAIN_RC_LICENSING_FEATURE_NOT_FOUND;

			for (i = 0; i < pAuthCtx->usLicenseCnt; i++)
			{
				printf("Licenses Read from File = 0x%08x \n",pAuthCtx->aLicenseCtx[i].ulLicenseId);
				if (getWgsLicId(pAuthCtx->aLicenseCtx[i].ulLicenseId) == cOCT_TRUE)
				{
					if (mOADF_FILE_SYSTEM_LICENSE_GET_MAX_COUNT(pAuthCtx->aLicenseCtx[i].ulLicenseTypeMaxCnt))
						{
							ulRc = cOCTVC1_RC_OK;							
							printf("Licenses Matched = 0x%08x \n",pAuthCtx->aLicenseCtx[i].ulLicenseId);
							wgsLicFeatureFlags[j++] = pAuthCtx->aLicenseCtx[i].ulLicenseId;
						}
				}
			}
		}
	}
	
	free(pAuthCtx);

	// All state > cOCTVC1_MAIN_LICENSING_STATUS_ENUM_INACTIVE will disable the user module start
	return (ulState > cOCTVC1_MAIN_LICENSING_STATUS_ENUM_INACTIVE) ? cOCTADF_FILE_SYSTEM_RC_LICENSING_PARSE_ERROR : cOCTVC1_RC_OK ;
}



/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\
Function:		wgsFileSystemLicenseInit
\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
unsigned int wgsFileSystemLicenseInit()
{
	unsigned int ulRc = 0;
	FILE_SYSTEM_LICENSE_CONFIG_PARSER* wgsLicParser = NULL;
	char * licFilename = "/home/wgs/octWgs.lic";

	// Make sure file content is empty.
	wgsLicParser = (FILE_SYSTEM_LICENSE_CONFIG_PARSER*) malloc(sizeof(FILE_SYSTEM_LICENSE_CONFIG_PARSER));
	assert(wgsLicParser != NULL);
	memset(wgsLicParser , 0 , sizeof(FILE_SYSTEM_LICENSE_CONFIG_PARSER));

	readWgsLicFile(licFilename , wgsLicParser);

	wgsLicParser->ulKeyLength = sizeof(wgsLicParser->abyKey);
	ulRc = getPubLicKey( wgsLicParser->abyKey, &wgsLicParser->ulKeyLength);
	
	if(0 != ulRc)
	{
		printf("Problem in reading Public Key exiting\n");
		assert(0);
	}
	wgsLicenses = malloc(sizeof(tOCT_UINT32) * MAX_WGS_FEATURE_LICESNESES);
	memset(wgsLicenses , 0 , (sizeof(tOCT_UINT32) * MAX_WGS_FEATURE_LICESNESES) );

	ulRc = wgsFileSystemLicenseParseFile(wgsLicParser , wgsLicenses);

	if(ulRc !=0)
	{
		printf("Problem in reading parsing license file exiting\n");
		assert(0);
	}

	free(wgsLicParser);
	return ulRc;

}

