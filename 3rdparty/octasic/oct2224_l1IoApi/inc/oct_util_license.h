#ifndef OCT_OPT_REMOVE_LICENSING
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: octadf_util_license.h

Copyright (c) 2018 Octasic Inc. All rights reserved.

This source code is Octasic Confidential. Use of and access to this code
is covered by the Octasic Device Enabling Software License Agreement.
Acknowledgement of the Octasic Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: Octasic Application Development Framework OCTADF-04.10.01-B3387 (2018/01/29)

$Octasic_Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef __OCTADF_UTIL_LICENSE_H__
#define __OCTADF_UTIL_LICENSE_H__

/*--------------------------------------------------------------------------
	C language
----------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif

#include "octdev_types.h"
#include "oct_util_config.h"

/* Builtin function abstraction
 */
#define mOADF_BUILTIN_ABS			abs
#define mOADF_BUILTIN_LABS			labs
#define mOADF_BUILTIN_LLABS			llabs
#define mOADF_BUILTIN_MEMCHR		memchr
#define mOADF_BUILTIN_MEMCMP		memcmp
#define mOADF_BUILTIN_MEMCPY		memcpy
#define mOADF_BUILTIN_MEMSET		memset
#define mOADF_BUILTIN_STRCASECMP	_stricmp
#define mOADF_BUILTIN_STRCAT		strcat
#define mOADF_BUILTIN_STRCHR		strchr
#define mOADF_BUILTIN_STRCMP		strcmp
#define mOADF_BUILTIN_STRCPY		strcpy
#define mOADF_BUILTIN_STRLEN		strlen
#define mOADF_BUILTIN_STRNCASECMP	_strnicmp
#define mOADF_BUILTIN_STRNCAT		strncat
#define mOADF_BUILTIN_STRNCMP		strncmp
#define mOADF_BUILTIN_STRNCPY		strncpy
#define mOADF_BUILTIN_STRSTR		strstr

#define FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_FILE_SIZE (10 * 1024)
#define FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_KEY_SIZE (1 * 1024)

#define TARGET_UTIL_RC_BASE 0xAAAA
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_NOT_INIT				( 0x020 | TARGET_UTIL_RC_BASE)
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_ALREADY_INIT			( 0x021 | TARGET_UTIL_RC_BASE )
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_PARSE_ERROR			( 0x022 | TARGET_UTIL_RC_BASE)
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_SIGNED_ERROR			( 0x023 | TARGET_UTIL_RC_BASE)
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_PROJID_ERROR			( 0x024 | TARGET_UTIL_RC_BASE)
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_HW_SIGNED_ERROR		( 0x025 | TARGET_UTIL_RC_BASE)
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_BOARD_TYPE_ERROR		( 0x026 | TARGET_UTIL_RC_BASE)
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_HW_UNSIGNED			( 0x027 | TARGET_UTIL_RC_BASE)
#define cOCTADF_FILE_SYSTEM_RC_LICENSING_FILE_NONE				( 0x028 | TARGET_UTIL_RC_BASE)

typedef struct __FILE_SYSTEM_LICENSE_CONFIG_PARSER__
{
	tOCTADF_UTIL_CONFIG_CTX ConfigCtx;

	tOCT_UINT32 ulKeyLength;
	tOCT_INT8 abyKey[FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_KEY_SIZE];

	tOCT_UINT32 ulContentLength;
	tOCT_INT8 abyFileContent[FILE_SYSTEM_LICENSE_CONFIG_PARSER_MAX_FILE_SIZE];

}FILE_SYSTEM_LICENSE_CONFIG_PARSER;


/*****************************  DEFINES  *************************************/


/* Prototype */
extern tOCT_UINT32 OctAdfUtilLicenseValidate(
	tOCT_INT8* f_pKey, tOCT_UINT32 f_ulKeyLength, tOCT_INT8 *f_pContent, tOCT_UINT32 f_ulContentLength );

extern tOCT_UINT32 OctAdfUtilLicenseValidateDetach(
	tOCT_INT8* f_pKey, tOCT_UINT32 f_ulKeyLength, tOCT_INT8* f_pContent, tOCT_UINT32 f_ulContentLength,
	tOCT_UINT8* f_pSignContent, tOCT_UINT32 f_ulSignLength );

extern tOCT_UINT32 OctAdfUtilLicenseEncryptContent(tOCT_INT8* f_pContent, tOCT_UINT32 f_ulContentLength,
	tOCT_UINT8* f_pEncryptContent, tOCT_UINT32* f_pulEncryptLength);
#ifdef __cplusplus
}
#endif

#endif /* __OCTADF_UTIL_LICENSE_H__ */
#endif /* OCT_OPT_REMOVE_LICENSING */
