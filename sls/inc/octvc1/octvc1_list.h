/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_LIST.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_LIST_H__
#define __OCTVC1_LIST_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_base.h"
#include "octvc1_cursor.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_HANDLE_OBJECT_GET
 		Handle Object list List structure,
 		Used when the objects to list are identified by a tOCTVC1_HANDLE_OBJECT.

 Members:
	ulNumHandleObject
 		Number of valid handle objects in aHandleObject
	aHandleObject
 		Array containing the listed handles
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32				ulNumHandleObject;
	tOCTVC1_HANDLE_OBJECT	aHandleObject[cOCTVC1_HANDLE_OBJECT_LIST_MAX_ENTRY];

} tOCTVC1_LIST_HANDLE_OBJECT_GET;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_NAME_OBJECT32_GET
 		Handle Object name List structure,
 		Used when the objects to list are identified by a tOCT_UINT32 and displayed by
 		name.

 Members:
	ulNumObject
 		Number of valid objects in aNamedObject
	aNameObject32
 		Array containing the listed handles and named
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32				ulNumObject;
	tOCTVC1_OBJECT32_NAME	aNameObject32[cOCTVC1_HANDLE_OBJECT32_NAME_LIST_MAX_ENTRY];

} tOCTVC1_LIST_NAME_OBJECT32_GET;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME
 		Handle Object list List structure,
 		Used when the objects to list are identified by a tOCTVC1_SUB_OBJECT_ID.

 Members:
	hParent
 		Handle object of the parent
	ulNumObject
 		Number of valid sub object IDs in aSubObjectId
	aNameObject32
 		Array containing the listed handles
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT	hParent;
	tOCT_UINT32				ulNumObject;
	tOCTVC1_OBJECT32_NAME	aNameObject32[cOCTVC1_HANDLE_OBJECT32_NAME_LIST_MAX_ENTRY];

} tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID
 		Handle Object list List structure,
 		Used when the objects to list are identified by a tOCTVC1_SUB_OBJECT_ID.

 Members:
	hParent
 		Handle object of the parent
	ulNumSubObjectId
 		Number of valid sub object IDs in aSubObjectId
	aSubObjectId
 		Array containing the listed handles
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT	hParent;
	tOCT_UINT32				ulNumSubObjectId;
	tOCTVC1_SUB_OBJECT_ID	aSubObjectId[cOCTVC1_HANDLE_OBJECT_LIST_MAX_ENTRY];

} tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_INDEX_GET
 		Object Index List structure,
 		Used when the objects to list are identified by a tOCTVC1_INDEX.

 Members:
	ulNumIndex
 		Number of valid index in aIndex
	aIndex
 		Array containing the listed of indexes
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32		ulNumIndex;
	tOCTVC1_INDEX	aIndex[cOCTVC1_HANDLE_OBJECT_LIST_MAX_ENTRY];

} tOCTVC1_LIST_INDEX_GET;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_INDEX_GET_SUB_INDEX
 		Object Index List structure,
 		Used when the objects to list are identified by a tOCTVC1_INDEX.

 Members:
	ulParentIndex
 		Index of the parent of the sub-index
	ulNumIndex
 		Number of valid index in aIndex
	aIndex
 		Array containing the listed of indexes
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_INDEX	ulParentIndex;
	tOCT_UINT32		ulNumIndex;
	tOCTVC1_INDEX	aIndex[cOCTVC1_HANDLE_OBJECT_LIST_MAX_ENTRY];

} tOCTVC1_LIST_INDEX_GET_SUB_INDEX;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_NAME128_OBJECT32_GET
 		Handle Object name List structure,
 		Used when the objects to list are identified by a tOCT_UINT32 and displayed by
 		name.

 Members:
	ulNumObject
 		Number of valid objects in aNamedObject
	aName128Object32
 		Array containing the listed handles and named
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCT_UINT32					ulNumObject;
	tOCTVC1_OBJECT32_NAME128	aName128Object32[cOCTVC1_HANDLE_OBJECT32_NAME128_LIST_MAX_ENTRY];

} tOCTVC1_LIST_NAME128_OBJECT32_GET;

/*-------------------------------------------------------------------------------------
	tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME128
 		Handle Object list List structure,
 		Used when the objects to list are identified by a tOCTVC1_SUB_OBJECT_ID.

 Members:
	hParent
 		Handle object of the parent
	ulNumObject
 		Number of valid sub object IDs in aSubObjectId
	aName128Object32
 		Array containing the listed handles
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT		hParent;
	tOCT_UINT32					ulNumObject;
	tOCTVC1_OBJECT32_NAME128	aName128Object32[cOCTVC1_HANDLE_OBJECT32_NAME128_LIST_MAX_ENTRY];

} tOCTVC1_LIST_HANDLE_OBJECT_GET_SUB_OBJECT_ID_NAME128;


#endif /* __OCTVC1_LIST_H__ */

