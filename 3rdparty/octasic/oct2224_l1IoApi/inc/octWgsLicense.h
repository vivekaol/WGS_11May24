#ifndef _OCTWGSLICENSE_H_
#define _OCTWGSLICENSE_H_

#include "octdev_types.h"
#include "../inc/octvc1/main/octvc1_main_api.h"


/*--------------------------------------------------------------------------
    tOADF_FILE_SYSTEM_LICENSE_CTX
----------------------------------------------------------------------------*/
#define cOADF_FILE_SYSTEM_LICENSE_ID_LEGACY		(0x1 << 24)

#define cOADF_FILE_SYSTEM_LICENSE_TYPE_BOOLEAN 0x80000000
#define cOADF_FILE_SYSTEM_LICENSE_TYPE_COUNT 0x40000000

#define cOADF_FILE_SYSTEM_LICENSE_TYPE_MASK 0xE0000000
#define cOADF_FILE_SYSTEM_LICENSE_MAX_MASK 0x07FFE000
#define cOADF_FILE_SYSTEM_LICENSE_CNT_MASK 0x00001FFF

#define cOADF_FILE_SYSTEM_LICENSE_TYPE_OFFSET	29
#define cOADF_FILE_SYSTEM_LICENSE_MAX_OFFSET	13
#define cOADF_FILE_SYSTEM_LICENSE_CNT_OFFSET	0

#define mOADF_FILE_SYSTEM_LICENSE_IS_BOOLEAN(l) \
	((l & cOADF_FILE_SYSTEM_LICENSE_TYPE_BOOLEAN) == cOADF_FILE_SYSTEM_LICENSE_TYPE_BOOLEAN)

#define mOADF_FILE_SYSTEM_LICENSE_SET_BOOLEAN(v,l) (v=( ( l << cOADF_FILE_SYSTEM_LICENSE_MAX_OFFSET) | cOADF_FILE_SYSTEM_LICENSE_TYPE_BOOLEAN))

#define mOADF_FILE_SYSTEM_LICENSE_IS_COUNT(l) \
	((l & cOADF_FILE_SYSTEM_LICENSE_TYPE_COUNT) == cOADF_FILE_SYSTEM_LICENSE_TYPE_COUNT)

#define mOADF_FILE_SYSTEM_LICENSE_GET_MAX_COUNT(l) ( (l & cOADF_FILE_SYSTEM_LICENSE_MAX_MASK )>> cOADF_FILE_SYSTEM_LICENSE_MAX_OFFSET)
#define mOADF_FILE_SYSTEM_LICENSE_SET_MAX_COUNT(v,l) (v=( (l<< cOADF_FILE_SYSTEM_LICENSE_MAX_OFFSET) | cOADF_FILE_SYSTEM_LICENSE_TYPE_COUNT))

#define mOADF_FILE_SYSTEM_LICENSE_GET_ACTIVE_COUNT(l) (l & cOADF_FILE_SYSTEM_LICENSE_CNT_MASK)
#define mOADF_FILE_SYSTEM_LICENSE_SET_ACTIVE_COUNT(v,l) (v=((v&~cOADF_FILE_SYSTEM_LICENSE_CNT_MASK)|(l & cOADF_FILE_SYSTEM_LICENSE_CNT_MASK)))


typedef struct __attribute__((packed, aligned(4))) _OADF_FILE_SYSTEM_LICENSE_CTX_
{
	tOCT_UINT32		ulLicenseId;			/* License Id */
	tOCT_UINT32		ulLicenseTypeMaxCnt;	/* License Type, Max, Count */

} tOADF_FILE_SYSTEM_LICENSE_CTX;


#define cOCTADF_LICENSE_MCC_SEG_COUNT	4
#define cOCTADF_LICENSE_MCC_SEG_LENGTH	64
#define cOCTADF_LICENSE_MCC_BUFFER_LENGTH ((cOCTADF_LICENSE_MCC_SEG_COUNT * cOCTADF_LICENSE_MCC_SEG_LENGTH) / 2 )		// 2 characters per bytes (128)
#define cOCTADF_LICENSE_MCC_MAX_COUNT 	(cOCTADF_LICENSE_MCC_BUFFER_LENGTH * 8)		// cOCTADF_LICENSE_MCC_BUFFER_LENGTH * 8 bits (1024)

typedef struct __OCTADF_UTIL_MEM_BUFFER_CTX__
{	
	tOCT_UINT8 *  pExternalPtr; /* Base pointer, start of the buffer */
	tOCT_UINT32                ulSizeInBytes; /* Buffer size in bytes */
	
} tOCTADF_UTIL_MEM_BUFFER_CTX; 

typedef struct __attribute__((packed, aligned(4))) _OCTADF_LICENSE_MCC_CTX_

{
	tOCT_UINT8					byEmul;
	tOCT_UINT8					byThreshold;
	tOCT_UINT8					abyReserved[2];
	tOCT_UINT32					ulMccCount;		// Current number of accepted MCC
	tOCTADF_UTIL_MEM_BUFFER_CTX MccBuffer;

}tOCTADF_LICENSE_MCC_CTX;

typedef struct __attribute__((packed, aligned(4))) _OCTADF_LICENSE_EXT_SHARED_
{
	tOCTADF_LICENSE_MCC_CTX MccCtx;

}tOCTADF_LICENSE_EXT_SHARED;


#define tOCTADF_LICENSE_STATE_FLAG_ENUM					tOCT_UINT32
#define cOCTADF_LICENSE_STATE_FLAG_ENUM_EMUL_OTP		0x00000001
#define cOCTADF_LICENSE_STATE_FLAG_ENUM_LEGACY			0x00000010

#define cOCTADF_LICENSE_STATE_SESSION_EVT_INVALID		0xFFFF
typedef tOCT_UINT32 tOCTADF_OS_OBJMGR;

/*--------------------------------------------------------------------------
    tOADF_FILE_SYSTEM_LICENSE_AUTH_CTX
----------------------------------------------------------------------------*/
	typedef struct __attribute__((packed, aligned(4))) _OADF_FILE_SYSTEM_LICENSE_AUTH_CTX_
{
	tOCT_INT8		szBoardType[23 + 1];	/* Associated board type */

	tOCTVC1_MAIN_LICENSING_STATUS_ENUM	ulState;						/* LICENSE State */

	tOCTADF_LICENSE_STATE_FLAG_ENUM		ulStateFlag;

	tOCT_UINT16		usInfractionCount;									/* Current number of infraction ... from OTP */
	tOCT_UINT16		usInfractionMaxCount;								/* Maximum number of allowed infraction */

	tOCTADF_OS_OBJMGR LicInfractionObjMgr;

	tOCT_UINT16		usLicenseCnt;										/* Number License */
	tOCT_UINT16		usSessionIndex;										/* Session index to send INFRACTION event */

	// MUST BE LAST ITEMS of tOADF_FILE_SYSTEM_LICENSE_AUTH_CTX
	tOADF_FILE_SYSTEM_LICENSE_CTX aLicenseCtx[1];						/* First of the license Ctx */

} tOADF_FILE_SYSTEM_LICENSE_AUTH_CTX;


#define cOCTADF_FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_FILE_SIZE (10 * 1024)
#define cOCTADF_FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_KEY_SIZE (1 * 1024)

typedef struct __OCTADF_FILE_SYSTEM_LICENSE_CONFIG_PARSER__
{
	tOCTADF_UTIL_CONFIG_CTX ConfigCtx;

	tOCT_UINT32 ulKeyLength;
	tOCT_INT8 abyKey[cOCTADF_FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_KEY_SIZE];

	tOCT_UINT32 ulContentLength;
	tOCT_INT8 abyFileContent[cOCTADF_FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_FILE_SIZE];

} tOCTADF_FILE_SYSTEM_LICENSE_CONFIG_PARSER;

#endif
