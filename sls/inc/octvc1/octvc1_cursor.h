/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: OCTVC1_CURSOR.h

Copyright (c) 2018 Octasic Technologies Private Limited. All rights reserved.

Description: 

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_RUS-02.07.00-B621 (2018/04/04)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OCTVC1_CURSOR_H__
#define __OCTVC1_CURSOR_H__


/*****************************  INCLUDE FILES  *******************************/
#include "../octdev_types.h"
#include "octvc1_base.h"
#include "octvc1_handle.h"


/************************  COMMON DEFINITIONS  *******************************/

/*-------------------------------------------------------------------------------------
 	Object Get Mode
-------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------
	tOCTVC1_OBJECT_CURSOR_ENUM :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_OBJECT_CURSOR_ENUM							tOCT_UINT32

#define cOCTVC1_OBJECT_CURSOR_ENUM_DONE						0		
#define cOCTVC1_OBJECT_CURSOR_ENUM_SPECIFIC					1		
#define cOCTVC1_OBJECT_CURSOR_ENUM_FIRST					2		
#define cOCTVC1_OBJECT_CURSOR_ENUM_NEXT						3		
#define cOCTVC1_OBJECT_CURSOR_ENUM_SUB_OBJECT_FIRST			4		
#define cOCTVC1_OBJECT_CURSOR_ENUM_SUB_OBJECT_NEXT			5		

/*-------------------------------------------------------------------------------------
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET
 		Generic Handle Object Get structure,
 		Use when the object is identified by a tOCTVC1_HANDLE_OBJECT.

 Members:
	hObject
 		Object handle
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
 		Get mode
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT		hObject;
	tOCTVC1_OBJECT_CURSOR_ENUM	ulGetMode;

} tOCTVC1_CURSOR_HANDLE_OBJECT_GET;

/*-------------------------------------------------------------------------------------
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_HANDLE_OBJECT
 		Handle object get structure when the parent is identified by a
 		tOCTVC1_HANDLE_OBJECT

 Members:
	hObject
 		Object handle of the parent
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
 		Get mode
	hHandleObjectGet
 		Handle object to get
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT		hObject;
	tOCTVC1_OBJECT_CURSOR_ENUM	ulGetMode;
	tOCTVC1_HANDLE_OBJECT		hHandleObjectGet;

} tOCTVC1_CURSOR_HANDLE_OBJECT_GET_HANDLE_OBJECT;

/*-------------------------------------------------------------------------------------
	tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID
 		Sub-object get structure when the parent is identified by a
 		tOCTVC1_HANDLE_OBJECT

 Members:
	hObject
 		Object handle
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
 		Get mode
	ulSubObjectId
 		Sub Object Id
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_HANDLE_OBJECT		hObject;
	tOCTVC1_OBJECT_CURSOR_ENUM	ulGetMode;
	tOCTVC1_SUB_OBJECT_ID		ulSubObjectId;

} tOCTVC1_CURSOR_HANDLE_OBJECT_GET_SUB_OBJECT_ID;

/*-------------------------------------------------------------------------------------
	tOCTVC1_CURSOR_INDEX_GET
 		Generic Index Object Get structure,
 		Use when the object is identified by a tOCTVC1_INDEX.

 Members:
	ulIndex
 		Object index
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
 		Get mode
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_INDEX				ulIndex;
	tOCTVC1_OBJECT_CURSOR_ENUM	ulGetMode;

} tOCTVC1_CURSOR_INDEX_GET;

/*-------------------------------------------------------------------------------------
	tOCTVC1_CURSOR_INDEX_GET_SUB_INDEX
 		Generic Index Object Get structure,
 		when the parent is identified by tOCTVC1_INDEX.

 Members:
	ulParentIndex
 		Parent index
	ulGetMode
		Default:	cOCTVC1_OBJECT_CURSOR_ENUM_FIRST
 		Get mode
	ulSubIndex
 		Object index
-------------------------------------------------------------------------------------*/
typedef struct
{
	tOCTVC1_INDEX				ulParentIndex;
	tOCTVC1_OBJECT_CURSOR_ENUM	ulGetMode;
	tOCTVC1_INDEX				ulSubIndex;

} tOCTVC1_CURSOR_INDEX_GET_SUB_INDEX;

/*-------------------------------------------------------------------------------------
 	Legacy types. Please use the new cursors.
-------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------
	tOCTVC1_INDEX_CURSOR :
-------------------------------------------------------------------------------------*/
#define tOCTVC1_INDEX_CURSOR								tOCTVC1_CURSOR_INDEX_GET



#endif /* __OCTVC1_CURSOR_H__ */

