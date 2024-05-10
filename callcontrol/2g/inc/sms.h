/*
*############################################################################
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
*############################################################################
*/

/*
*############################################################################
* File Name   : sms.h
 *
* Description : SMS header file
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 05/06/2015          Shivashankar V     File Creation
*############################################################################
*/

#ifndef _SMS_H_
#define _SMS_H_

#include "lapdm.h"
#include "userManager.h"
#include <time.h>

#define SWAP_BYTE( value ) \
		    ( (((value) & 0x0f ) << 4) | \
		      (((value) & 0xf0 ) >> 4) ) 

/* PUTB8 macro writes byte value to given address.
 * This macro is used mainly by other PUTBXX macros.
 */
#define PUTB8(p,v) \
    {(*(tOCT_UINT8 *)(p)) = ((tOCT_UINT8)(v));}


/* PUTB16 macro writes 16-bit value in Big Endian format
 * to given address. 16-bit value is written as two separate
 * bytes, and so this macro can write 16-bit value to whatever
 * address, regardless of the processor alignment restrictions
 */
#define PUTB16(p,v) \
    {PUTB8((p),(tOCT_UINT16)(v)>>8); PUTB8((tOCT_UINT8*)(p)+1,v);}

/* PUTL8 macro writes byte value to given address.
 * This macro is used mainly by other PUTLXX macros.
 */
#define PUTL8(p,v) \
    {(*(tOCT_UINT8 *)(p)) = ((tOCT_UINT8)(v));}


/* PUTL16 macro writes 16-bit value in Little Endian format
 * to given address. 16-bit value is written as two separate
 * bytes, and so this macro can write 16-bit value to whatever
 * address, regardless of the processor alignment restrictions
 */
#define PUTL16(p,v) /*lint -e{572,778}*/ \
    {PUTL8((p),(v)); PUTL8((tOCT_UINT8*)(p)+1,(tOCT_UINT16)(v)>>8);}


/* GETB8 macro returns byte value from given address.
 * This macro is used mainly by other GETBXX macros.
 */
#define GETB8(p) \
    (*(tOCT_UINT8*)(p))

/* GETB16 macro reads 16-bit value in Big Endian format
 * from given address. 16-bit value is read as two separate
 * bytes, and so this macro can read 16-bit value from whatever
 * address, regardless of the processor alignment restrictions
 */
#define GETB16(p) \
    (((tOCT_UINT16) GETB8(p)<<8) | (tOCT_UINT16) GETB8((tOCT_UINT8 *)(p)+1))

/* GETL8 macro returns byte value from given address.
 * This macro is used mainly by other GETLXX macros.
 */
#define GETL8(p) \
    (*(tOCT_UINT8 *)(p))


/* GETL16 macro reads 16-bit value in Little Endian format
 * from given address. 16-bit value is read as two separate
 * bytes, and so this macro can read 16-bit value from whatever
 * address, regardless of the processor alignment restrictions
 */
#define GETL16(p) \
    (((tOCT_UINT16) GETL8((tOCT_UINT8 *)(p)+1)<<8) | GETL8(p))



#define EXT_BIT_MASK                    0x80

#define INVALID_VALUE                   0x00
#define ALL_CHARS_MAPPED                0x01
#define EQUIVALENCY_MAPPING_DONE        0x02
#define CHARS_REPLACED_OR_MAPPED        0x04
#define INVALID_PARAMS                  0x08
#define INVALID_CHARS                   0x10

/* Characater set values */
#define SMS_GSM_7BIT_CS  1
#define SMS_8BIT_CS      2
#define SMS_UCS2_CS      3

#define UCS2_a                          0x0061
#define UCS2_c                          0x0063
#define UCS2_0                          0x0030
#define UCS2_9                          0x0039
#define UCS2_ASTERISK                   0x002A /* UCS-2 character '*' */
#define UCS2_HASH                       0x0023 /* UCS-2 character '#' */
#define UCS2_SPACE                      0x0020

#define NUL                             '\0'
#define ASCII_SPACE                     0x20
#define ASCII_PLUS                      '+'
#define ASCII_HASH                      '#'
#define ASCII_LOWER_CASE_A              'a'
#define ASCII_LOWER_CASE_C              'c'
#define ASCII_ZERO                      '0'
#define ASCII_NINE                      '9'
#define ASCII_ASTERISK                  '*'
#define ASCII_QUESTION_MARK             '?'

#define GSM_ALPHABET_EXTENSION_CHAR     0x1B

#define GSM_ADDRESS_END_MARK            0x0F
#define LOWER_SEMI_OCTET_MASK           0x0F
#define SEMI_OCTET_SIZE                 4
#define UCS2_VS_ASCII_CHAR_SIZE         2
#define OCTET_VS_SEMI_OCTET_SIZE        2
#define SAFETY_BUFFER_MULTIPLIER        2
#define ADDRESS_LEN_IE_AND_TOA          2 /* Length of address IE and Type-of-Address fields */

#define BITS_IN_BYTE                    8
#define BITS_IN_GSM_CHAR                7

/* Type of number */
#define TOA_TON_UNKNOWN               0x00
#define TOA_TON_INTERNATIONAL         0x10
#define TOA_TON_NATIONAL              0x20
#define TOA_TON_NETWORK_SPECIFIC      0x30
#define TOA_TON_SUBSCRIBER            0x40
#define TOA_TON_ALPHANUMERIC          0x50
#define TOA_TON_ABBREVIATED           0x60
#define TOA_TON_RESERVED              0x70

/* Numbering plan identification */
#define TOA_NPI_UNKNOWN               0x00
#define TOA_NPI_ISDN                  0x01
#define TOA_NPI_RESERVED1             0x02
#define TOA_NPI_DATA                  0x03
#define TOA_NPI_TELEX                 0x04
#define TOA_NPI_SRV_CENTER_SPECIFIC1  0x05
#define TOA_NPI_SRV_CENTER_SPECIFIC2  0x06
#define TOA_NPI_RESERVED2             0x07
#define TOA_NPI_NATIONAL              0x08
#define TOA_NPI_PRIVATE               0x09
#define TOA_NPI_ERMES                 0x0A
#define TOA_NPI_RESERVED3             0x0B
#define TOA_NPI_RESERVED4             0x0C
#define TOA_NPI_RESERVED5             0x0D
#define TOA_NPI_RESERVED6             0x0E
#define TOA_NPI_RESERVED              0x0F

/* 
   Address masks
   Type-of-Number mask B0111_0000
*/
#define SMS_TP_ADDR_TON_MASK                     0x70
/* For originating/destination address
   B0000_0000
*/
#define SMS_TP_ADDR_TON_UNKNOWN                  0x00
#define SMS_TP_ADDR_TON_INTERNATIONAL            0x10  /* B0001_0000 */
#define SMS_TP_ADDR_TON_NATIONAL                 0x20  /* B0010_0000 */
#define SMS_TP_ADDR_TON_NETW_SPECIFIC            0x30  /* B0011_0000 */
#define SMS_TP_ADDR_TON_SUBSCRIBER               0x40  /* B0100_0000 */
#define SMS_TP_ADDR_TON_ALPHANUMERIC             0x50  /* B0101_0000 */
#define SMS_TP_ADDR_TON_ABBREVIATED              0x60  /* B0110_0000 */
#define SMS_TP_ADDR_TON_RESERVED                 0x70  /* B0111_0000 */


#define SMS_DESTINATION_ADDRESS                  0x01
#define SMS_SMSC_ADDRESS                         0x02
#define ISDN_ADDRESS 		                         0x03

#define UCS2_VS_ASCII_CHAR_SIZE                  2

#define IPL_WM_GSM_DEFAULT_LANGUAGE_TABLE        0
#define IPL_WM_GSM_TURKISH_LANGUAGE_TABLE        1

#define IPL_WM_GSM_DEFAULT_EXT_TABLE             0
#define IPL_WM_GSM_TURKISH_EXT_TABLE             1
#define IPL_WM_GSM_SPANISH_EXT_TABLE             2

#define IPL_WM_GSM_INVALID_VALUE                 0
#define IPL_WM_GSM_ALL_CHARS_MAPPED              1
#define IPL_WM_GSM_EQUIVALENCY_MAPPING_DONE      2
#define IPL_WM_GSM_CHARS_REPLACED_OR_MAPPED      3

#define IPL_WM_GSM_ERR_ADDRESS_TOO_LONG            -1
#define IPL_WM_GSM_ERR_INVALID_CHARACTERS          -2
#define IPL_WM_GSM_ERR_INVALID_INPUT               -3
#define IPL_WM_GSM_ERR_INVALID_LANGUAGE_PARAMETERS -4
#define IPL_WM_GSM_ERR_INVALID_LANGUAGE_CHARS      -5


#define SMS_CP_DATA_MAX_LENGTH                      251   /* Max length of CP-DATA */

#define SMS_MSG_OK              1
#define SMS_MSG_INVALID_PARAM   2
#define SMS_MSG_BUFFER_OVERRUN  3
#define SMS_MSG_PARSE_ERROR     4
#define SMS_MSG_INVALID_ADDRESS 5

#define SMS_DATA_CODING_MASK            0x0c            /* b00001100 */

/* sms field masks */
#define SMS_MESSAGE_TYPE_MASK           0x03            /* b00000011 */
#define SMS_VALIDITY_PERIOD_MASK        0x18            /* b00011000 */
#define SMS_MORE_MES_TO_SEND_MASK       0x04            /* b00000100 */
#define SMS_REPORT_IND_REQ_QUAL_MASK    0x20            /* b00100000 */
#define SMS_USERDATA_HEADER_IND_MASK    0x40            /* b01000000 */
#define SMS_REPLY_PATH_MASK             0x80            /* b10000000 */                 

#define SMS_REJECT_DUPLICATES_MASK      0x04            /* b00000100 */

#define SMS_PARM_USERDA_LEN_MASK        0x04            /* b00000100 */
#define SMS_PARM_DCS_MASK               0x02            /* b00000010 */
#define SMS_PARM_PID_MASK               0x01            /* b00000001 */

#define SMS_ENHANCE_FORMAT_MASK         0x03            /* b00000011 */
#define SMS_ENHANCE_FORMAT_RELATIVE     0x01            /* b00000001 */
#define SMS_ENHANCE_FORMAT_SECOND       0x02            /* b00000010 */
#define SMS_ENHANCE_FORMAT_TIME         0x03            /* b00000011 */

#define SMS_DELIVER         1         /* Received sms */
#define SMS_DELIVER_REPORT  2         /* Reveived report */
#define SMS_SUBMIT          3         /* Sending sms */
#define SMS_SUBMIT_REPORT   4         /* Sending report */
#define SMS_STATUS_REPORT   5         /* SMSLibDelivery status message */
#define SMS_COMMAND         6         /* special command pdu */

/* Address values */
#define SMS_GSM_ADDRESS_TYPE_MASK           0x70    /* b01110000 */
#define SMS_GSM_ADDRESS_NUM_PLAN_MASK       0x0f    /* b00001111 */
#define SMS_MAX_GSM_ADDRESS_LENGTH          (20+1)  /* 10 bytes can store 20 semi octet character (3GPP TS 23.040) + international '+' mark */

/* Value Masks */

/* Data coding group values */

#define SMS_DATA_CODING_GROUP_HALF_MASK     0xc0    /* b11000000 */

#define SMS_DATA_CODING_GROUP_GENERAL       0x00    /* b00000000 */
#define SMS_DATA_CODING_GROUP_AUT_DEL       0x40    /* b01000000 */
#define SMS_DATA_CODING_GROUP_RESERV        0x80    /* b10000000 */

#define SMS_DATA_CODING_GROUP_MASK          0xF0    /* b11110000 */

#define SMS_DATA_CODING_GROUP_DISCARD       0xC0    /* b11000000 */
#define SMS_DATA_CODING_GROUP_STORE_7BIT    0xD0    /* b11010000 */
#define SMS_DATA_CODING_GROUP_STORE_UCS2    0xE0    /* b11100000 */
#define SMS_DATA_CODING_GROUP_OTHER         0xF0    /* b11110000 */

/* User data coding values */ 
#define SMS_DATA_CODING_7BIT_VALUE      0x00            /* b00000000 */
#define SMS_DATA_CODING_UCS2_VALUE      0x08            /* b00001000 */
#define SMS_DATA_CODING_8BIT_VALUE      0x04            /* b00000100 */

/* Maximum field values */

#define SMS_MAX_USER_DATA_LEN_BYTES     140

#define SMS_SEMI_OCTET_SIZE             4

/* Validity period values */
#define SMS_VALIDITY_PERIOD_RELATIVE      0x10          /* b00010000 */
#define SMS_VALIDITY_PERIOD_ENHANCED      0x08          /* b00001000 */
#define SMS_VALIDITY_PERIOD_ABSOLUTE      0x18          /* b00011000 */

/* Static default header lengths */

#define SMS_DELIVER_STATIC_HEADER_LEN           10
#define SMS_REPORT_STATIC_HEADER_LEN            7
#define SMS_STATUS_REPORT_STATIC_HEADER_LEN     15
#define SMS_COMMAND_STATIC_HEADER_LEN           4
#define SMS_SUBMIT_STATIC_HEADER_LEN            3
#define SMS_SUBMIT_RELATIVE_FORMAT_HEADER_LEN   1
#define SMS_SUBMIT_OTHER_FORMAT_HEADER_LEN      7

#define    IPL_WM_GSM_OK                     1

#define IPL_WM_GSM_CPN_ALLOWED               0
#define IPL_WM_GSM_CPN_RESTRICTED            1
#define IPL_WM_GSM_CPN_NOT_AVAILABLE         2
#define IPL_WM_GSM_CPN_RESERVED              3

/* Type of number */
#define IPL_WM_GSM_TON_UNKNOWN               0x00
#define IPL_WM_GSM_TON_INTERNATIONAL         0x10
#define IPL_WM_GSM_TON_NATIONAL              0x20
#define IPL_WM_GSM_TON_NETWORK_SPECIFIC      0x30
#define IPL_WM_GSM_TON_SUBSCRIBER            0x40 /* 24.008: dedicated */
#define IPL_WM_GSM_TON_ALPHANUMERIC          0x50 /* only in 23.040 */
#define IPL_WM_GSM_TON_ABBREVIATED           0x60 /* not in 24.008 */
#define IPL_WM_GSM_TON_RESERVED              0x70

#define IPL_WM_GSM_TON_MASK                  0x70

/* Valid header */
#define SMS_ELEMENT_ID_EMAIL_HEADER         0x20

/* Reserved ids */
#define SMS_ELEMENT_ID_RESERVED             0x02
#define SMS_ELEMENT_ID_RESERV_EMS_START     0x1b
#define SMS_ELEMENT_ID_RESERV_EMS_END       0x1f
#define SMS_ELEMENT_ID_RESERV_FUTURE_START  0x26
#define SMS_ELEMENT_ID_RESERV_FUTURE_END    0x6f
#define SMS_ELEMENT_ID_RESERV_FUTURE2_START 0xa0
#define SMS_ELEMENT_ID_RESERV_FUTURE2_END   0xbf
#define SMS_ELEMENT_ID_RESERV_FUTURE3_START 0xe0

/* Special UDH elements which can have zero element length */
#define SMS_TOOLKIT_SECURITY_HEADER_START_ID    0x70
#define SMS_TOOLKIT_SECURITY_HEADER_END_ID      0x7F
#define SMS_EXTENDED_OBJECT_DATA_REQUEST_ID     0x1A

#define MODEM_CHAR_UCS2_0707             1 /* UCS2 defined in 3GPP 27.007 */
#define MODEM_CHAR_GSM                   2
#define MODEM_CHAR_PCCP437               3
#define MODEM_CHAR_PCDN                  4
#define MODEM_CHAR_IRA                   5
#define MODEM_CHAR_8859_1                6
#define MODEM_CHAR_HEX                   7
#define MODEM_CHAR_UTF_8                 8 /* UTF-8 charcater set*/
#define MODEM_CHAR_UCS2_PLAIN            9 /* Normal Unicode  (ISO-/IEC10646-1) */
#define MODEM_CHAR_SJIS                  10

#define MODEM_CHAR_OK                    0x00
#define MODEM_CHAR_ERROR                 0xFF

#define ESCAPE                           0x1b /* the escape char in GSM 03.38 */

enum ipl_wm_gsm_lib_specs
{
    IPL_WM_GSM_23040,
    IPL_WM_GSM_24008,
    IPL_WM_GSM_24011,
    IPL_WM_GSM_29002,
    IPL_WM_GSM_OTHER
};

typedef struct
{
    tOCT_UINT8 index;
    tOCT_UINT8 gsm_char;
    tOCT_UINT16 unicode_char;
} CHAR_CONV_STR;

#ifdef FEA_DECODE_MO_SMS
typedef struct 
{
    tOCT_UINT16 *ucs2_ptr;
    tOCT_UINT8 *gsm_ptr;
    tOCT_UINT8 *number_info;
    tOCT_UINT8 *ucs2_length;
    tOCT_UINT8 gsm_spec;
    tOCT_UINT8 *pres_scr_ind;
} IPL_WM_GSM_LIB_GSM_UCS2_PARAMETERS_STR;

/* Conversion modes used by ucs2_strncpy_endian */
enum ENDIAN_CONVERSION_MODES
{
    UCS2_FROM_BIG_TO_PLATFORM_ENDIAN,
    UCS2_FROM_PLATFORM_TO_BIG_ENDIAN,
    UCS2_FROM_LITTLE_TO_PLATFORM_ENDIAN,
    UCS2_FROM_PLATFORM_TO_LITTLE_ENDIAN                 
};


/* Address structure where all address info is included */
typedef struct
{
    tOCT_UINT16*   address;
    tOCT_UINT8     number_info;
    tOCT_UINT8     address_length;
    tOCT_UINT8     gsm_spec;
}tSMSLib_Address;

/* Time */
typedef struct
{
    tOCT_UINT8 year;
    tOCT_UINT8 month;
    tOCT_UINT8 day;
    tOCT_UINT8 hour;
    tOCT_UINT8 minute;
    tOCT_UINT8 second;           /* Used also to store TP-VP value when
                                                           * Validity period has format Enhanced and
                                                           * sub type relative or seconds. See
                                                           * 3GPP TS 23.040 chapter 9.2.3.12.3 */
    tOCT_INT8  time_zone;        /* amount of 15min time intervals */
}tSMSLib_Time;

typedef struct 
{
    tOCT_UINT16 ElementId;          /* ElementId = 0x00XX          standard ids  ElementId = 0x01xx - 0xffxx Internal ids */
    tOCT_UINT8  ElementSize;        /* Size of Binary element if <5 then Integervalue is used to store value and value pointer should be null */
    tOCT_UINT8* value;              /* Binary Element */
    tOCT_UINT32 IntegerValue;       /* Store Numeric values and small elements -> prevent small dynamic buffers Must be in big endian (same endian as in sms binary) */
    void*  nextElement;             /* Next Element */ 
} tSMSLib_InformElement;


typedef int  (*LIST_CMP_FN)(const void*, const void*);
typedef int  (*LIST_TRAVERSE_FN)(void*, void*);
typedef void (*LIST_DISPOSE_FN)(void*);


typedef struct _slList
{
    void*            last;             /* Pointer to last element in list */
    LIST_CMP_FN      compare;          /* Pointer to compare function. */
    tOCT_UINT16      nElement;         /* Number of elements in the list */
    tOCT_UINT16      linkOffset;       /* Offset of link field within the list element structures */
} slList;

typedef struct _slIterator
{
    slList*     pList;            /* Pointer to the list to operate on */
    void*       pCurrent;         /* Pointer to the current element */
    void*       pPrev;            /* Pointer to previous element. */
    int         position;         /* Current position in the list */
} slIterator;


/* tSMSLib_Message */
typedef struct
{
    /* Common for all message type */
    tOCT_UINT8                     MessageTypeIndicator;       /* Mandatory */
    //tOCT_UINT8                     MessageSubType;             /* Mandatory , Not included to binary but when composed or decoded client must inform which pdu this is (SMS_NOT_REPORT_PDU,SMS_RP_ERROR,SMS_RP_ACK) */

    tOCT_UINT8                     ProtocolIdentifier;         /* Mandatory */
    tOCT_UINT8                     DataCodingScheme;           /* Mandatory */
  
    /* Deliver Headers */
    tOCT_UINT8                     MoreMessagestoSend;         /* Mandatory (TRUE/FALSE) */
  
    /* Common for deliver, submit and reports */             
    tOCT_UINT8                     ReplyPath;                  /* Mandatory (TRUE/FALSE) */
    tOCT_UINT8                     UserDataHeaderIndicator;    /* Optional (TRUE/FALSE) */
    tOCT_UINT8                     StatusReportIndReqQual;     /* Optional (TRUE/FALSE) */
    tOCT_UINT8                     FailureCauseOrStatus;       /* Mandatory only for RP_ERROR report and Status report*/
    tOCT_UINT8                     ParameterIndicator;         /* Mandatory Only Reports */
 
    /* Submit headers */ 
    tOCT_UINT8                     RejectDuplicates;           /* Mandatory (TRUE/FALSE) */
    tOCT_UINT8                     ValidityPeriodFormat;       /* Mandatory */
    tOCT_UINT8                     MessageReference;           /* Mandatory */
    tOCT_UINT8                     ValidityPeriod;             /* Optional, If enhanced format is used this store enhance format info 
                                                                                                                * and ServiceCentreTime store real values if absolute are used this is null. 
                                                                                                                * When relative format is used then this include time value */
  
    /* Command headers */
    tOCT_UINT8                     CommandType;                /* Mandatory */
    tOCT_UINT8                     MessageNumber;              /* Mandatory */
  

    /* Commond address and time header values */
    tSMSLib_Time                   DischargeTime;              /* Mandatory for status report */  
    tSMSLib_Time                   ServiceCentreTime;          /* Mandatory , Can store also absolute or enhanced validityperiod values */

    tSMSLib_Address                AddressValue;               /* Mandatory, Value Meaning depend pdu type. (Originating, Destination and Recipient) */

    /* Common dynamic headers for all message type */
    slList*                        InfoElementlist;            /* Optional, Includes all user data headers (UDH) */
    tOCT_UINT8*                    UserData;                   /* Optional, User data store all user information (TP - UD without UDH) */
    tOCT_UINT8                     UserDataLength;             /* Mandatory, Length of user data without UDH */
    tOCT_UINT8*                    UDHData;                    /* Optional, User data store all user information (TP - UD without UDH) */

} tSMSLib_Message;


void decodeSmsPdu(userInfo* info);
#endif /* FEA_DECODE_MO_SMS */

#endif /* #ifndef _SMS_H_ */ 
