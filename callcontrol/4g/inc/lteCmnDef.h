/*############################################################################
 *
 *                   *** FXLynx Technologies Ltd. ***
 *
 *     The information contained in this file is the property of FXLynx
 *     Technologies Ltd. Except as specifically authorized in writing by
 *     FXLynx Technologies Ltd. The user of this file shall keep information
 *     contained herein confidential and shall protect same in whole or in
 *     part from disclosure and dissemination to third parties.
 *
 *     Without prior written consent of FXLynx Technologies Ltd. you may not
 *     reproduce, represent, or download through any means, the information 
 *     contained herein in any way or in any form.
 *
 *       (c) FXLynx Technologies Ltd. 2014, All Rights Reserved
 *
 ############################################################################*/

/*############################################################################
 * File Name   : lteCmnDef.h
 *
 * Description : This file has common DataType and Macros used across different
 *               modules in LTE
 *
 * History     :
 *
 * Date	        Author                  Details
 * ---------------------------------------------------------------------------
 * 06/04/2015   Anand Kashikar      Moved Common datatypes from lteMac
 *                                      & l1Def to this file
 ############################################################################*/
#ifndef _LTE_CMN_DEF_H_
#define _LTE_CMN_DEF_H_

/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
/* -----------------------------------------------------
 *                Data Type 
 * -----------------------------------------------------*/

#define TRUE 1
#define FALSE 0
#define LTE_MAX_MSG_SIZE 212   // Fix to increase UL msg buffer size 
#define LTE_MAX_RRC_MSG_SIZE 192 // Sometimes HEADER extension message is coming from UE
#define LTE_MAX_SIZE_BUFFER 512
#define LTE_MAX_SIZE_ULSCH_BUFFER (896 + 8) // 4 Ul Pdus

#define SET_LTE_BAND_1 0x00000001
#define SET_LTE_BAND_2 0x00000002
#define SET_LTE_BAND_3 0x00000004
#define SET_LTE_BAND_4 0x00000008
#define SET_LTE_BAND_5 0x00000010
#define SET_LTE_BAND_6 0x00000020
#define SET_LTE_BAND_7 0x00000040
#define SET_LTE_BAND_8 0x00000080
#define SET_LTE_BAND_9 0x00000100
#define SET_LTE_BAND_10 0x00000200
#define SET_LTE_BAND_11 0x00000400
#define SET_LTE_BAND_12 0x00000800
#define SET_LTE_BAND_13 0x00001000
#define SET_LTE_BAND_14 0x00002000
#define SET_LTE_BAND_15 0x00004000
#define SET_LTE_BAND_16 0x00008000
#define SET_LTE_BAND_17 0x00010000
#define SET_LTE_BAND_18 0x00020000
#define SET_LTE_BAND_19 0x00040000
#define SET_LTE_BAND_20 0x00080000
#define SET_LTE_BAND_21 0x00100000
#define SET_LTE_BAND_22 0x00200000
#define SET_LTE_BAND_23 0x00400000
#define SET_LTE_BAND_24 0x00800000
#define SET_LTE_BAND_25 0x01000000
#define SET_LTE_BAND_26 0x02000000
#define SET_LTE_BAND_27 0x04000000
#define SET_LTE_BAND_28 0x08000000
#define SET_LTE_BAND_29 0x10000000
#define SET_LTE_BAND_30 0x20000000
#define SET_LTE_BAND_31 0x40000000
#define SET_LTE_BAND_32 0x80000000

// Type definitions
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef signed char         sint8;
typedef signed short        sint16;
typedef signed int          sint32;
typedef long long           sint64;
typedef unsigned long long  uint64;

typedef struct{
    uint32 N_bits;
    uint8*  msg;
}ltePduMsgStruct;

uint32 getIE(uint8  *bits, uint32 N_bits, uint32 *startPos);
void setIE(uint32   value, uint8 *bits, uint32 N_bits, uint32 *startPos);
void allocateRxDataBuffer();
void deallocateRxDataBuffer();
uint8* getRxDataBuffer();
void allocateUlTxDataBuffer();
void deallocateUlTxDataBuffer();
uint8* getUlTxDataBuffer();
uint8* getBufferFordummyUlconfigReq();
void allocateRrcDataBuffer();
void deallocateRrcDataBuffer();
uint8* getRrcDataBuffer();
void allocateDlConfigBuffer();
void deallocateDlConfigBuffer();
uint8* getDlConfigBuffer();
void allocateDlTxDataBuffer();
void deallocateDlTxDataBuffer();
uint8* getDlTxDataBuffer();
void allocateUlConfigBuffer();
void deallocateUlConfigBuffer();
uint8* getUlConfigBuffer();
uint8* getRrcPageBuffer(uint8 pageIndex);
int stick_this_thread_to_core(int core_id);
#endif
