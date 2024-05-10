/********************************************************************16**

                         (c) COPYRIGHT 2009 by 
                         Continuous Computing Corporation.
                         All rights reserved.

     This software is confidential and proprietary to Continuous Computing 
     Corporation (CCPU).  No part of this software may be reproduced,
     stored, transmitted, disclosed or used in any form or by any means
     other than as expressly provided by the written Software License 
     Agreement between CCPU and its licensee.

     CCPU warrants that for a period, as provided by the written
     Software License Agreement between CCPU and its licensee, this
     software will perform substantially to CCPU specifications as
     published at the time of shipment, exclusive of any updates or 
     upgrades, and the media used for delivery of this software will be 
     free from defects in materials and workmanship.  CCPU also warrants 
     that has the corporate authority to enter into and perform under the   
     Software License Agreement and it is the copyright owner of the software 
     as originally delivered to its licensee.

     CCPU MAKES NO OTHER WARRANTIES, EXPRESS OR IMPLIED, INCLUDING
     WITHOUT LIMITATION WARRANTIES OF MERCHANTABILITY OR FITNESS FOR
     A PARTICULAR PURPOSE WITH REGARD TO THIS SOFTWARE, SERVICE OR ANY RELATED
     MATERIALS.

     IN NO EVENT SHALL CCPU BE LIABLE FOR ANY INDIRECT, SPECIAL,
     CONSEQUENTIAL DAMAGES, OR PUNITIVE DAMAGES IN CONNECTION WITH OR ARISING
     OUT OF THE USE OF, OR INABILITY TO USE, THIS SOFTWARE, WHETHER BASED
     ON BREACH OF CONTRACT, TORT (INCLUDING NEGLIGENCE), PRODUCT
     LIABILITY, OR OTHERWISE, AND WHETHER OR NOT IT HAS BEEN ADVISED
     OF THE POSSIBILITY OF SUCH DAMAGE.

                       Restricted Rights Legend

     This software and all related materials licensed hereby are
     classified as "restricted computer software" as defined in clause
     52.227-19 of the Federal Acquisition Regulation ("FAR") and were
     developed entirely at private expense for nongovernmental purposes,
     are commercial in nature and have been regularly used for
     nongovernmental purposes, and, to the extent not published and
     copyrighted, are trade secrets and confidential and are provided
     with all rights reserved under the copyright laws of the United
     States.  The government's rights to the software and related
     materials are limited and restricted as provided in clause
     52.227-19 of the FAR.

                    IMPORTANT LIMITATION(S) ON USE

     The use of this software is limited to the use set
     forth in the written Software License Agreement between CCPU and
     its Licensee. Among other things, the use of this software
     may be limited to a particular type of Designated Equipment, as 
     defined in such Software License Agreement.
     Before any installation, use or transfer of this software, please
     consult the written Software License Agreement or contact CCPU at
     the location set forth below in order to confirm that you are
     engaging in a permissible use of the software.

                    Continuous Computing Corporation
                    9450, Carroll Park Drive
                    San Diego, CA-92121, USA

                    Tel: +1 (858) 882 8800
                    Fax: +1 (858) 777 3388

                    Email: support@trillium.com
                    Web: http://www.ccpu.com

*********************************************************************17*/

/********************************************************************20**
  
     Name:     FAP
  
     Type:     C Source Code.
  
     Desc:
         

     File:     op_std_def.h

     Sid:      op_std_def.h@@/main/3 - Mon Aug 10 21:09:19 2009
  
     Prg:      ds
  
*********************************************************************21*/

/************************************************************************
 
     Note: 
 
************************************************************************/

/* Prevent nested includes */
#ifndef __PP_STD_DEF_H__
#define __PP_STD_DEF_H__

/* Constants ------------------------------------------------------------- */

#ifdef FALSE
#undef FALSE
#endif

#ifdef TRUE
#undef TRUE
#endif

/* Boolean constants */
#ifndef FALSE
#define FALSE  0
#endif

#ifndef TRUE
#define TRUE   1
#endif

/* Types ----------------------------------------------------------------- */
#ifndef __ENVDEPH__
/* Common types */
#ifdef PICOARRAY
typedef unsigned long U32;
typedef unsigned long *PU32;
#else
typedef unsigned int U32;
/*typedef unsigned int uint32_t;*/
typedef unsigned int *PU32;
/*typedef int int32_t;*/
#endif

typedef void Void;

typedef unsigned short U16;
/*typedef unsigned short uint16_t;*/
typedef unsigned short *PU16;
typedef short S16;
/*typedef short int16_t;*/
typedef short *PS16;

#ifdef PICOARRAY
typedef long S32;
typedef long *PS32;
#else
typedef int S32;
typedef int *PS32;
#endif

typedef char S8;
/*typedef char int8_t;*/
typedef char *PS8;

typedef unsigned char U8;
/*typedef unsigned char uint8_t;*/
typedef unsigned char *PU8;
#endif

#ifndef VXWORKS
typedef int BOOL;
#endif

#ifdef EXTERN
#undef EXTERN
#define EXTERN  extern
#else /* not EXTERN */
#define EXTERN  extern
#endif /* EXTERN */

/* Functions ------------------------------------------------------------- */

#endif /* __PP_STD_DEF_H__ */





/********************************************************************30**

  End of file:     op_std_def.h@@/main/3 - Mon Aug 10 21:09:19 2009

*********************************************************************31*/

/********************************************************************40**

  Notes:

*********************************************************************41*/

/********************************************************************50**

*********************************************************************51*/

/********************************************************************60**

  Revision history:

*********************************************************************61*/
/********************************************************************70**

  version    initials                   description
  -----------  ---------  ------------------------------------------------

*********************************************************************71*/

/********************************************************************80**

*********************************************************************81*/
/********************************************************************90**

  ver       pat    init                  description
  ----------- -------- ---- -----------------------------------------------
/main/3      ---    sy           1.Created for Release FAP 1.3
*********************************************************************91*/
