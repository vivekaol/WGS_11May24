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
* File Name   : sms.c
 *
* Description : This file provides the functionality of the SMS
*
* History     :
*
* Date                                  Author                     Details
* ---------------------------------------------------------------------------
* 05/06/2015          Shivashankar V     File Creation
*############################################################################
*/

#include "sms.h"
#include "logManager.h"
#include "ratSocketItf.h"
#include <stddef.h>

#define NEXT(i) (*(void**)((char*)(i)+offs))

#define slIterator_Valid(i) ((i)->pCurrent != NULL)

//static const char* conv_tbl_ascii = "0123456789*#abc";
//static const char* conv_tbl_nibble_string = "0123456789ABCDEF";

#define SPC             0x20  /* Space character for non-defined conversions */

/* Masks fro various bytes of UTF-8 character set
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx */

#define MODEM_CHAR_UTF_8_CONV_1 0x00 /*0xxxxxxx*/
#define MODEM_CHAR_UTF_8_CONV_2 0x80 /*10xxxxxx*/
#define MODEM_CHAR_UTF_8_CONV_3 0xC0 /*110xxxxx*/
#define MODEM_CHAR_UTF_8_CONV_4 0xE0 /*1110xxxx*/


#define MODEM_CHAR_COLS_IN_CNV_TBL 4
#define MODEM_CHAR_CNV_TBL_SIZE    sizeof( modem_char_conversion_table )
#define MODEM_CHARS_IN_TBL           (MODEM_CHAR_CNV_TBL_SIZE / 5)
#define MODEM_CHAR_NEEDS_CONVERSION( x ) \
    ((x) <= 0x09 || (x) == 0x0B || (x) == 0x0C || ((x) >= 0x0E && \
     (x) <= 0x1F) || (x) == 0x24 || (x) == 0x40 || ((x) >= 0x5B && \
     (x) <= 0x60) || (x) >= 0x7B)


/* This table is used when a GSM (TBCD) address is converted to ASCII. */
static const tOCT_UINT8 ipl_wm_gsm_semioct_to_char_table[] =
{
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '*', '#', 'a', 'b', 'c', '\0'
};

typedef struct
{
    tOCT_UINT8   gsm_char;
    tOCT_UINT16 unicode_char;
} IPL_WM_GSM_LIB_CONV_STR;


/* Character conversion table. Table contains Unicode characters which
 * are put to numerical order so that unicode character that corresponds
 * to GSM 7 bit default alphabet (3GPP TS 23.038) is in place of
 * ipl_wm_gsm_lib_unicode_table[GSM 7bit default alphabet]. */
static const tOCT_UINT16 ipl_wm_gsm_lib_unicode_table[] =
{
    0x0040, /* 0x00 = 'At sign' */
    0x00A3, /* 0x01 = 'Pound sign' */
    0x0024, /* 0x02 = 'Dollar sign' */
    0x00A5, /* 0x03 = 'Yen sign' */
    0x00E8, /* 0x04 = 'e grave' */
    0x00E9, /* 0x05 = 'e acute' */
    0x00F9, /* 0x06 = 'u grave' */
    0x00EC, /* 0x07 = 'i grave' */
    0x00F2, /* 0x08 = 'o grave' */
    0x00C7, /* 0x09 = 'Capital C-cedilla' */
    0x000A, /* 0x0A = 'Linefeed' */
    0x00D8, /* 0x0B = 'Capital O slash' */
    0x00F8, /* 0x0C = 'o slash' */
    0x000D, /* 0x0D = 'Carriage Return' */
    0x00C5, /* 0x0E = 'Capital A ring' */
    0x00E5, /* 0x0F = 'a ring' */
    0x0394, /* 0x10 = 'Greek capital Delta' */
    0x005F, /* 0x11 = 'Underscore' */
    0x03A6, /* 0x12 = 'Greek capital Phi' */
    0x0393, /* 0x13 = 'Greek capital Gamma' */
    0x039B, /* 0x14 = 'Greek capital Lambda' */
    0x03A9, /* 0x15 = 'Greek capital Omega' */
    0x03A0, /* 0x16 = 'Greek capital Pi' */
    0x03A8, /* 0x17 = 'Greek capital Psi' */
    0x03A3, /* 0x18 = 'Greek capital Sigma' */
    0x0398, /* 0x19 = 'Greek capital Theta' */
    0x039E, /* 0x1A = 'Greek capital Xi' */
    0x0000, /* 0x1B = 'Extension character mark' */
    0x00C6, /* 0x1C = 'Capital AE' */
    0x00E6, /* 0x1D = 'ae' */
    0x00DF, /* 0x1E = 'Sharp S' */
    0x00C9, /* 0x1F = 'Capital E acute' */
    0x0020, /* 0x20 = 'Space' */
    0x0021, /* 0x21 = '!' */
    0x0022, /* 0x22 = '"' */
    0x0023, /* 0x23 = '#' */
    0x00A4, /* 0x24 = 'Currency sign' */
    0x0025, /* 0x25 = '%' */
    0x0026, /* 0x26 = '&' */
    0x0027, /* 0x27 = ''' */
    0x0028, /* 0x28 = '(' */
    0x0029, /* 0x29 = ')' */
    0x002A, /* 0x2A = '*' */
    0x002B, /* 0x2B = '+' */
    0x002C, /* 0x2C = ',' */
    0x002D, /* 0x2D = '-' */
    0x002E, /* 0x2E = '.' */
    0x002F, /* 0x2F = '/' */
    0x0030, /* 0x30 = '0' */
    0x0031, /* 0x31 = '1' */
    0x0032, /* 0x32 = '2' */
    0x0033, /* 0x33 = '3' */
    0x0034, /* 0x34 = '4' */
    0x0035, /* 0x35 = '5' */
    0x0036, /* 0x36 = '6' */
    0x0037, /* 0x37 = '7' */
    0x0038, /* 0x38 = '8' */
    0x0039, /* 0x39 = '9' */
    0x003A, /* 0x3A = ':' */
    0x003B, /* 0x3B = ';' */
    0x003C, /* 0x3C = '<' */
    0x003D, /* 0x3D = '=' */
    0x003E, /* 0x3E = '>' */
    0x003F, /* 0x3F = '?' */
    0x00A1, /* 0x40 = 'Inverted !' */
    0x0041, /* 0x41 = 'A' */
    0x0042, /* 0x42 = 'B' */
    0x0043, /* 0x43 = 'C' */
    0x0044, /* 0x44 = 'D' */
    0x0045, /* 0x45 = 'E' */
    0x0046, /* 0x46 = 'F' */
    0x0047, /* 0x47 = 'G' */
    0x0048, /* 0x48 = 'H' */
    0x0049, /* 0x49 = 'I' */
    0x004A, /* 0x4A = 'J' */
    0x004B, /* 0x4B = 'K' */
    0x004C, /* 0x4C = 'L' */
    0x004D, /* 0x4D = 'M' */
    0x004E, /* 0x4E = 'N' */
    0x004F, /* 0x4F = 'O' */
    0x0050, /* 0x50 = 'P' */
    0x0051, /* 0x51 = 'Q' */
    0x0052, /* 0x52 = 'R' */
    0x0053, /* 0x53 = 'S' */
    0x0054, /* 0x54 = 'T' */
    0x0055, /* 0x55 = 'U' */
    0x0056, /* 0x56 = 'V' */
    0x0057, /* 0x57 = 'W' */
    0x0058, /* 0x58 = 'X' */
    0x0059, /* 0x59 = 'Y' */
    0x005A, /* 0x5A = 'Z' */
    0x00C4, /* 0x5B = 'Capital A umlaut' */
    0x00D6, /* 0x5C = 'Capital O umlaut' */
    0x00D1, /* 0x5D = 'Capital N tilde' */
    0x00DC, /* 0x5E = 'Capital U umlaut' */
    0x00A7, /* 0x5F = 'Section sign' */
    0x00BF, /* 0x60 = 'Inverted ?' */
    0x0061, /* 0x61 = 'a' */
    0x0062, /* 0x62 = 'b' */
    0x0063, /* 0x63 = 'c' */
    0x0064, /* 0x64 = 'd' */
    0x0065, /* 0x65 = 'e' */
    0x0066, /* 0x66 = 'f' */
    0x0067, /* 0x67 = 'g' */
    0x0068, /* 0x68 = 'h' */
    0x0069, /* 0x69 = 'i' */
    0x006A, /* 0x6A = 'j' */
    0x006B, /* 0x6B = 'k' */
    0x006C, /* 0x6C = 'l' */
    0x006D, /* 0x6D = 'm' */
    0x006E, /* 0x6E = 'n' */
    0x006F, /* 0x6F = 'o' */
    0x0070, /* 0x70 = 'p' */
    0x0071, /* 0x71 = 'q' */
    0x0072, /* 0x72 = 'r' */
    0x0073, /* 0x73 = 's' */
    0x0074, /* 0x74 = 't' */
    0x0075, /* 0x75 = 'u' */
    0x0076, /* 0x76 = 'v' */
    0x0077, /* 0x77 = 'w' */
    0x0078, /* 0x78 = 'x' */
    0x0079, /* 0x79 = 'y' */
    0x007A, /* 0x7A = 'z' */
    0x00E4, /* 0x7B = 'a umlaut' */
    0x00F6, /* 0x7C = 'o umlaut' */
    0x00F1, /* 0x7D = 'n tilde' */
    0x00FC, /* 0x7E = 'u umlaut' */
    0x00E0  /* 0x7F = 'a grave' */
};


/* This table contains values that are presented in GSM 7 bit default alphabet
 * with two characters. First one is so called escape character, 0x1B, followed
 * by actual character. See 3GPP TS 23.038 for further details.
 */
static const IPL_WM_GSM_LIB_CONV_STR ipl_wm_gsm_lib_extension_char_table[] =
{
    { 0x65, 0x20AC }, /* The euro character */
    { 0x14, 0x005E }, /* ^ */
    { 0x1B, 0x0020 }, /* Extension table mark */
    { 0x28, 0x007B }, /* { */
    { 0x29, 0x007D }, /* } */
    { 0x2F, 0x005C }, /* \ */
    { 0x3C, 0x005B }, /* [ */
    { 0x3D, 0x007E }, /* ~ */
    { 0x3E, 0x005D }, /* ] */
    { 0x40, 0x007C }  /* | */
};


/* Turkish locking shift differential table
   This table contains the characters in turkish national language
   locking shift table that differ from the default 7-bit GSM
   character table. First column is the 7-bit GSM character, second is
   the corresponding Unicode character */
static const IPL_WM_GSM_LIB_CONV_STR ipl_wm_gsm_lib_TR_locking_shift_diff_table[] =
{
    { 0x04, 0x20AC }, /* Euro sign */
    { 0x07, 0x0131 }, /* i dotless */
    { 0x0B, 0x011E }, /* Capital G-breve */
    { 0x0C, 0x011F }, /* g-breve */
    { 0x1C, 0x015E }, /* Capital S-cedilla */
    { 0x1D, 0x015F }, /* s-cedilla */
    { 0x40, 0x0130 }, /* Capital Dotted I */
    { 0x60, 0x00E7 }  /* c-cedilla */
};

/* Character conversion table, the first column is 3GPP TS 23.038 GSM 7 bit
 * default alphabet and the second is Unicode standard character.
 * This table maps special (e.g. mathematical symbols) and accented (e.g.
 * Â ) Unicode characters to their equivalent or close equivalent ones in
 * GSM 7 bit alphabet. E.g. Â will be mapped as A.
 */
static const IPL_WM_GSM_LIB_CONV_STR
ipl_wm_gsm_lib_unicode_additional_table[] =
{
    { 0x10, 0x03B4 },
    { 0x11, 0x005F },
    { 0x12, 0x03C6 },
    { 0x13, 0x03B3 },
    { 0x14, 0x03BB },
    { 0x15, 0x038F },
    { 0x15, 0x03C9 },
    { 0x15, 0x03CE },
    { 0x16, 0x03C0 },
    { 0x17, 0x03C8 },
    { 0x18, 0x03C2 },
    { 0x18, 0x03C3 },
    { 0x19, 0x03B8 },
    { 0x1A, 0x03BE },
    { 0x2A, 0x00D7 },
    { 0x41, 0x00C0 },
    { 0x41, 0x00C1 },
    { 0x41, 0x00C2 },
    { 0x41, 0x00C3 },
    { 0x41, 0x0100 },
    { 0x41, 0x0102 },
    { 0x41, 0x0104 },
    { 0x41, 0x0386 },
    { 0x41, 0x0391 },
    { 0x41, 0x03AC },
    { 0x41, 0x03B1 },
    { 0x42, 0x0392 },
    { 0x42, 0x03B2 },
    { 0x43, 0x0106 },
    { 0x43, 0x0108 },
    { 0x43, 0x010A },
    { 0x43, 0x010C },
    { 0x44, 0x010E },
    { 0x44, 0x0110 },
    { 0x44, 0x00D0 },
    { 0x45, 0x00C8 },
    { 0x45, 0x00CA },
    { 0x45, 0x00CB },
    { 0x45, 0x0112 },
    { 0x45, 0x0114 },
    { 0x45, 0x0116 },
    { 0x45, 0x0118 },
    { 0x45, 0x011A },
    { 0x45, 0x0388 },
    { 0x45, 0x0395 },
    { 0x45, 0x03AD },
    { 0x45, 0x03B5 },
    { 0x47, 0x011C },
    { 0x47, 0x011E },
    { 0x47, 0x0120 },
    { 0x47, 0x0122 },
    { 0x48, 0x0124 },
    { 0x48, 0x0126 },
    { 0x48, 0x0389 },
    { 0x48, 0x0397 },
    { 0x48, 0x03AE },
    { 0x48, 0x03B7 },
    { 0x49, 0x00CC },
    { 0x49, 0x00CD },
    { 0x49, 0x00CE },
    { 0x49, 0x00CF },
    { 0x49, 0x0128 },
    { 0x49, 0x012A },
    { 0x49, 0x012C },
    { 0x49, 0x012E },
    { 0x49, 0x0130 },
    { 0x49, 0x038A },
    { 0x49, 0x0390 },
    { 0x49, 0x0399 },
    { 0x49, 0x03AA },
    { 0x49, 0x03AF },
    { 0x49, 0x03B9 },
    { 0x49, 0x03CA },
    { 0x4A, 0x0134 },
    { 0x4B, 0x004B },
    { 0x4B, 0x0136 },
    { 0x4B, 0x039A },
    { 0x4B, 0x03BA },
    { 0x4C, 0x0139 },
    { 0x4C, 0x013B },
    { 0x4C, 0x013D },
    { 0x4C, 0x013F },
    { 0x4C, 0x0141 },
    { 0x4D, 0x039C },
    { 0x4D, 0x03BC },
    { 0x4E, 0x0143 },
    { 0x4E, 0x0145 },
    { 0x4E, 0x0147 },
    { 0x4E, 0x039D },
    { 0x4E, 0x03BD },
    { 0x4F, 0x00D2 },
    { 0x4F, 0x00D3 },
    { 0x4F, 0x00D4 },
    { 0x4F, 0x00D5 },
    { 0x4F, 0x014C },
    { 0x4F, 0x014E },
    { 0x4F, 0x0150 },
    { 0x4F, 0x038C },
    { 0x4F, 0x039F },
    { 0x4F, 0x03BF },
    { 0x4F, 0x03CC },
    { 0x50, 0x03A1 },
    { 0x50, 0x03C1 },
    { 0x52, 0x0154 },
    { 0x52, 0x0156 },
    { 0x52, 0x0158 },
    { 0x53, 0x015A },
    { 0x53, 0x015C },
    { 0x53, 0x015E },
    { 0x53, 0x0160 },
    { 0x54, 0x00DE },
    { 0x54, 0x0162 },
    { 0x54, 0x0164 },
    { 0x54, 0x0166 },
    { 0x54, 0x03A4 },
    { 0x54, 0x03C4 },
    { 0x55, 0x00D9 },
    { 0x55, 0x00DA },
    { 0x55, 0x00DB },
    { 0x55, 0x0168 },
    { 0x55, 0x016A },
    { 0x55, 0x016C },
    { 0x55, 0x016E },
    { 0x55, 0x0170 },
    { 0x55, 0x0172 },
    { 0x58, 0x03A7 },
    { 0x58, 0x03C7 },
    { 0x59, 0x00DD },
    { 0x59, 0x038E },
    { 0x59, 0x03A5 },
    { 0x59, 0x03AB },
    { 0x59, 0x03B0 },
    { 0x59, 0x03C5 },
    { 0x59, 0x03CB },
    { 0x59, 0x03CD },
    { 0x5A, 0x0179 },
    { 0x5A, 0x017B },
    { 0x5A, 0x017D },
    { 0x5A, 0x0396 },
    { 0x5A, 0x03B6 },
    { 0x61, 0x00E1 },
    { 0x61, 0x00E2 },
    { 0x61, 0x00E3 },
    { 0x61, 0x0101 },
    { 0x61, 0x0103 },
    { 0x61, 0x0105 },
    { 0x63, 0x00E7 },
    { 0x63, 0x0107 },
    { 0x63, 0x0109 },
    { 0x63, 0x010B },
    { 0x63, 0x010D },
    { 0x64, 0x010F },
    { 0x64, 0x0111 },
    { 0x64, 0x00F0 },
    { 0x65, 0x00EA },
    { 0x65, 0x00EB },
    { 0x65, 0x0113 },
    { 0x65, 0x0115 },
    { 0x65, 0x0117 },
    { 0x65, 0x0119 },
    { 0x65, 0x011B },
    { 0x67, 0x011D },
    { 0x67, 0x011F },
    { 0x67, 0x0121 },
    { 0x67, 0x0123 },
    { 0x68, 0x0125 },
    { 0x68, 0x0127 },
    { 0x69, 0x00ED },
    { 0x69, 0x00EE },
    { 0x69, 0x00EF },
    { 0x69, 0x0129 },
    { 0x69, 0x012B },
    { 0x69, 0x012D },
    { 0x69, 0x012F },
    { 0x69, 0x0131 },
    { 0x6A, 0x0135 },
    { 0x6B, 0x0137 },
    { 0x6C, 0x013A },
    { 0x6C, 0x013C },
    { 0x6C, 0x013E },
    { 0x6C, 0x0140 },
    { 0x6C, 0x0142 },
    { 0x6E, 0x0144 },
    { 0x6E, 0x0146 },
    { 0x6E, 0x0148 },
    { 0x6F, 0x00F3 },
    { 0x6F, 0x00F4 },
    { 0x6F, 0x00F5 },
    { 0x6F, 0x00F7 },
    { 0x6F, 0x014D },
    { 0x6F, 0x014F },
    { 0x6F, 0x0151 },
    { 0x72, 0x0072 },
    { 0x72, 0x0155 },
    { 0x72, 0x0157 },
    { 0x72, 0x0159 },
    { 0x73, 0x015B },
    { 0x73, 0x015D },
    { 0x73, 0x015F },
    { 0x73, 0x0161 },
    { 0x74, 0x00FE },
    { 0x74, 0x0163 },
    { 0x74, 0x0165 },
    { 0x74, 0x0167 },
    { 0x75, 0x00FA },
    { 0x75, 0x00FB },
    { 0x75, 0x0169 },
    { 0x75, 0x016B },
    { 0x75, 0x016D },
    { 0x75, 0x016F },
    { 0x75, 0x0171 },
    { 0x75, 0x0173 },
    { 0x79, 0x00FD },
    { 0x79, 0x00FF },
    { 0x7A, 0x017A },
    { 0x7A, 0x017C },
    { 0x7A, 0x017E }
};


/* 7-bit GSM Turkish National Language Single Shift Table
   First column contains the 7-bit GSM Turkish Single Shift characters
   and the second the corresponding Unicode characters
*/
static const IPL_WM_GSM_LIB_CONV_STR ipl_wm_gsm_lib_TR_single_shift_unicode_table[] =
{
    { 0x14, 0x005E }, /* ^ */
    { 0x1B, 0x0020 }, /* Extension table mark */
    { 0x28, 0x007B }, /* { */
    { 0x29, 0x007D }, /* } */
    { 0x2F, 0x005C }, /* \ */
    { 0x3C, 0x005B }, /* [ */
    { 0x3D, 0x007E }, /* ~ */
    { 0x3E, 0x005D }, /* ] */
    { 0x40, 0x007C }, /* | */
    { 0x47, 0x011E }, /* Capital G-breve */
    { 0x49, 0x0130 }, /* Dotted capital I */
    { 0x53, 0x015E }, /* Capital S-cedilla */
    { 0x63, 0x00E7 }, /* c-cedilla */
    { 0x65, 0x20AC }, /* Euro sign */
    { 0x67, 0x011F }, /* g-breve */
    { 0x69, 0x0131 }, /* Dotless i */
    { 0x73, 0x015F }  /* s-cedilla */
};

/* 7-bit GSM Spanish National Language Single Shift Table
   First column contains the 7-bit GSM Spanish Single Shift characters
   and the second the corresponding Unicode characters
*/
static const IPL_WM_GSM_LIB_CONV_STR ipl_wm_gsm_lib_ES_single_shift_unicode_table[] =
{
   { 0x09, 0x00E7 }, /* c-cedilla */
   { 0x14, 0x005E }, /* ^ */
   { 0x1B, 0x0020 }, /* Extension table mark */
   { 0x28, 0x007B }, /* { */
   { 0x29, 0x007D }, /* } */
   { 0x2F, 0x005C }, /* \ */
   { 0x3C, 0x005B }, /* [ */
   { 0x3D, 0x007E }, /* ~ */
   { 0x3E, 0x005D }, /* ] */
   { 0x40, 0x007C }, /* | */
   { 0x41, 0x00C1 }, /* Capital A-acute */
   { 0x49, 0x00CD }, /* Capital I-acute */
   { 0x4F, 0x00D3 }, /* Capital O-acute */
   { 0x55, 0x00DA }, /* Capital U-acute */
   { 0x61, 0x00E1 }, /* a-acute */
   { 0x65, 0x20AC }, /* Euro sign */
   { 0x69, 0x00ED }, /* i-acute */
   { 0x6F, 0x00F3 }, /* o-acute */
   { 0x75, 0x00FA }, /* u-acute */
};

static const tOCT_UINT8 modem_char_conversion_table[][5] =
{
        /*          1.           2.     3.     4.
         *    UCS2  UCS2  GSM    GSM    PCCP   PCDN
         *    MSB   LSB   ext           437
         */

    { 0x00, 0x0C, 0x80 | 0x0A,  0x0C,  0x0C },
    { 0x00, 0x24,        0x02,  0x24,  0x24 },
    { 0x00, 0x40,        0x00,  0x40,  0x40 },
    { 0x00, 0x5B, 0x80 | 0x3C,  0x5B,  0x5B },
    { 0x00, 0x5C, 0x80 | 0x2F,  0x5C,  0x5C },
    { 0x00, 0x5D, 0x80 | 0x3E,  0x5D,  0x5D },
    { 0x00, 0x5E, 0x80 | 0x14,  0x5E,  0x5E },
    { 0x00, 0x5F,        0x11,  0x5F,  0x5F },
    { 0x00, 0x7B, 0x80 | 0x28,  0x7B,  0x7B },
    { 0x00, 0x7C, 0x80 | 0x40,  0x7C,  0x7C },
    { 0x00, 0x7D, 0x80 | 0x29,  0x7D,  0x7D },
    { 0x00, 0x7E, 0x80 | 0x3D,  0x7E,  0x7E },
    { 0x00, 0xA1,        0x40,  0xAD,  0xAD },
    { 0x00, 0xA3,        0x01,  0x9C,  0x9C },
    { 0x00, 0xA4,        0x24,   SPC,  0xAF },
    { 0x00, 0xA5,        0x03,  0x9D,   SPC },
    { 0x00, 0xA7,        0x5F,  0x15,  0x15 },
    { 0x00, 0xBF,        0x60,  0xA8,  0xA8 },
    { 0x00, 0xC0,        0x41,  0x41,  0x41 },
    { 0x00, 0xC1,        0x41,  0x41,  0x41 },
    { 0x00, 0xC2,        0x41,  0x41,  0x41 },
    { 0x00, 0xC3,        0x41,  0x41,  0x41 },
    { 0x00, 0xC8,        0x45,  0x45,  0x45 },
    { 0x00, 0xCA,        0x45,  0x45,  0x45 },
    { 0x00, 0xCB,        0x45,  0x45,  0x45 },
    { 0x00, 0xCC,        0x49,  0x49,  0x49 },
    { 0x00, 0xCD,        0x49,  0x49,  0x49 },
    { 0x00, 0xCE,        0x49,  0x49,  0x49 },
    { 0x00, 0xCF,        0x49,  0x49,  0x49 },
    { 0x00, 0xD2,        0x4F,  0x4F,  0x4F },
    { 0x00, 0xD3,        0x4F,  0x4F,  0x4F },
    { 0x00, 0xD4,        0x4F,  0x4F,  0x4F },
    { 0x00, 0xD5,        0x4F,  0x4F,  0x4F },
    { 0x00, 0xD9,        0x55,  0x55,  0x55 },
    { 0x00, 0xDA,        0x55,  0x55,  0x55 },
    { 0x00, 0xDB,        0x55,  0x55,  0x55 },
    { 0x00, 0xDD,        0x59,  0x59,  0x59 },
    { 0x00, 0xE3,        0x61,  0x61,  0x61 },
    { 0x00, 0xF5,        0x6F,  0x6F,  0x6F },
    { 0x00, 0xFD,        0x79,  0x79,  0x79 },
    { 0x00, 0xC4,        0x5B,  0x8E,  0x8E },
    { 0x00, 0xC5,        0x0E,  0x8F,  0x8F },
    { 0x00, 0xC6,        0x1C,  0x92,  0x92 },
    { 0x00, 0xC7,        0x09,  0x80,  0x80 },
    { 0x00, 0xC9,        0x1F,  0x90,  0x90 },
    { 0x00, 0xD1,        0x5D,  0xA5,  0xA5 },
    { 0x00, 0xD6,        0x5C,  0x99,  0x99 },
    { 0x00, 0xDC,        0x5E,  0x9A,  0x9A },
    { 0x00, 0xDF,        0x1E,  0xE1,  0xE1 },
    { 0x00, 0xE1,        0x61,  0xA0,  0xA0 },
    { 0x00, 0xE2,        0x61,  0x83,  0x83 },
    { 0x00, 0xE4,        0x7B,  0x84,  0x84 },
    { 0x00, 0xE5,        0x0F,  0x86,  0x86 },
    { 0x00, 0xE6,        0x1D,  0x91,  0x91 },
    { 0x00, 0xE7,        0x09,  0x87,  0x87 },
    { 0x00, 0xE8,        0x04,  0x8A,  0x8A },
    { 0x00, 0xE9,        0x05,  0x82,  0x82 },
    { 0x00, 0xEA,        0x65,  0x88,  0x88 },
    { 0x00, 0xEB,        0x65,  0x89,  0x89 },
    { 0x00, 0xEC,        0x07,  0x8D,  0x8D },
    { 0x00, 0xED,        0x69,  0xA1,  0xA1 },
    { 0x00, 0xEE,        0x69,  0x8C,  0x8C },
    { 0x00, 0xEF,        0x69,  0x8B,  0x8B },
    { 0x00, 0xF2,        0x08,  0x95,  0x95 },
    { 0x00, 0xF3,        0x6F,  0xA2,  0xA2 },
    { 0x00, 0xF4,        0x6F,  0x93,  0x93 },
    { 0x00, 0xF6,        0x7C,  0x94,  0x94 },
    { 0x00, 0xFA,        0x75,  0xA3,  0xA3 },
    { 0x00, 0xFB,        0x75,  0x96,  0x96 },
    { 0x00, 0xD8,        0x0B,   SPC,  0x9D },
    { 0x00, 0xE0,        0x7F,  0x85,  0x85 },
    { 0x00, 0xF1,        0x7D,  0xA4,  0xA4 },
    { 0x00, 0xF8,        0x0C,   SPC,  0x9B },
    { 0x00, 0xF9,        0x06,  0x97,  0x97 },
    { 0x00, 0xFC,        0x7E,  0x81,  0x81 },
    { 0x00, 0xFF,        0x79,  0x98,  0x98 },
    { 0x03, 0x94,        0x10,   SPC,   SPC },
    { 0x03, 0xA6,        0x12,  0xE8,  0xE8 },
    { 0x03, 0x93,        0x13,  0xE2,  0xE2 },
    { 0x03, 0x9B,        0x14,   SPC,   SPC },
    { 0x03, 0xA9,        0x15,  0xEA,  0xEA },
    { 0x03, 0xA0,        0x16,   SPC,   SPC },
    { 0x03, 0xA8,        0x17,   SPC,   SPC },
    { 0x03, 0xA3,        0x18,  0xE4,  0xE4 },
    { 0x03, 0x98,        0x19,  0xE9,  0xE9 },
    { 0x03, 0x9E,        0x1A,   SPC,   SPC },
    { 0x20, 0xAC, 0x80 | 0x65,  0x65,  0x65 },
    { 0x00, 0x60,        0x27,  0x60,  0x60 }
};
 
const CHAR_CONV_STR gsm_ucs2_to_ucs2_conv_tbl_modem[ ] =
{
    { 0x00, 0x00, 0x0040 },
    { 0x01, 0x01, 0x00A3 },
    { 0x02, 0x02, 0x0024 },
    { 0x03, 0x03, 0x00A5 },
    { 0x04, 0x04, 0x00E8 },
    { 0x05, 0x05, 0x00E9 },
    { 0x06, 0x06, 0x00F9 },
    { 0x07, 0x07, 0x00EC },
    { 0x08, 0x08, 0x00F2 },
    { 0x09, 0x09, 0x00C7 },
    { 0x0A, 0x0A, 0x000A },
    { 0x0B, 0x0B, 0x00D8 },
    { 0x0C, 0x0C, 0x00F8 },
    { 0x0D, 0x0D, 0x000D },
    { 0x0E, 0x0E, 0x00C5 },
    { 0x0F, 0x0F, 0x00E5 },
    { 0x10, 0x10, 0x0394 },
    { 0x11, 0x11, 0x005F },
    { 0x12, 0x12, 0x03A6 },
    { 0x13, 0x13, 0x0393 },
    { 0x14, 0x14, 0x039B },
    { 0x15, 0x15, 0x03A9 },
    { 0x16, 0x16, 0x03A0 },
    { 0x17, 0x17, 0x03A8 },
    { 0x18, 0x18, 0x03A3 },
    { 0x19, 0x19, 0x0398 },
    { 0x1A, 0x1A, 0x039E },
    { 0x1C, 0x1C, 0x00C6 },
    { 0x1D, 0x1D, 0x00E6 },
    { 0x1E, 0x1E, 0x00DF },
    { 0x1F, 0x1F, 0x00C9 },
    { 0x20, 0x20, 0x0020 },
    { 0x21, 0x21, 0x0021 },
    { 0x22, 0x22, 0x0022 },
    { 0x23, 0x23, 0x0023 },
    { 0x24, 0x24, 0x00A4 },
    { 0x25, 0x25, 0x0025 },
    { 0x26, 0x26, 0x0026 },
    { 0x27, 0x27, 0x0027 },
    { 0x28, 0x28, 0x0028 },
    { 0x29, 0x29, 0x0029 },
    { 0x2A, 0x2A, 0x002A },
    { 0x2B, 0x2B, 0x002B },
    { 0x2C, 0x2C, 0x002C },
    { 0x2D, 0x2D, 0x002D },
    { 0x2E, 0x2E, 0x002E },
    { 0x2F, 0x2F, 0x002F },
    { 0x30, 0x30, 0x0030 },
    { 0x31, 0x31, 0x0031 },
    { 0x32, 0x32, 0x0032 },
    { 0x33, 0x33, 0x0033 },
    { 0x34, 0x34, 0x0034 },
    { 0x35, 0x35, 0x0035 },
    { 0x36, 0x36, 0x0036 },
    { 0x37, 0x37, 0x0037 },
    { 0x38, 0x38, 0x0038 },
    { 0x39, 0x39, 0x0039 },
    { 0x3A, 0x3A, 0x003A },
    { 0x3B, 0x3B, 0x003B },
    { 0x3C, 0x3C, 0x003C },
    { 0x3D, 0x3D, 0x003D },
    { 0x3E, 0x3E, 0x003E },
    { 0x3F, 0x3F, 0x003F },
    { 0x40, 0x40, 0x0040 },  /* In ASCII is 0x40 = "@" */
    { 0x40, 0x40, 0x00A1 },  /* In GSM 7bit is 0x40 = Inverted ! */
    { 0x41, 0x41, 0x0041 },
    { 0x42, 0x42, 0x0042 },
    { 0x43, 0x43, 0x0043 },
    { 0x44, 0x44, 0x0044 },
    { 0x45, 0x45, 0x0045 },
    { 0x46, 0x46, 0x0046 },
    { 0x47, 0x47, 0x0047 },
    { 0x48, 0x48, 0x0048 },
    { 0x49, 0x49, 0x0049 },
    { 0x4A, 0x4A, 0x004A },
    { 0x4B, 0x4B, 0x004B },
    { 0x4C, 0x4C, 0x004C },
    { 0x4D, 0x4D, 0x004D },
    { 0x4E, 0x4E, 0x004E },
    { 0x4F, 0x4F, 0x004F },
    { 0x50, 0x50, 0x0050 },
    { 0x51, 0x51, 0x0051 },
    { 0x52, 0x52, 0x0052 },
    { 0x53, 0x53, 0x0053 },
    { 0x54, 0x54, 0x0054 },
    { 0x55, 0x55, 0x0055 },
    { 0x56, 0x56, 0x0056 },
    { 0x57, 0x57, 0x0057 },
    { 0x58, 0x58, 0x0058 },
    { 0x59, 0x59, 0x0059 },
    { 0x5A, 0x5A, 0x005A },
    { 0x5B, 0x5B, 0x00C4 },
    { 0x5C, 0x5C, 0x00D6 },
    { 0x5D, 0x5D, 0x00D1 },
    { 0x5E, 0x5E, 0x00DC },
    { 0x5F, 0x5F, 0x00A7 },
    { 0x60, 0x60, 0x00BF },
    { 0x61, 0x61, 0x0061 },
    { 0x62, 0x62, 0x0062 },
    { 0x63, 0x63, 0x0063 },
    { 0x64, 0x64, 0x0064 },
    { 0x65, 0x65, 0x0065 },
    { 0x66, 0x66, 0x0066 },
    { 0x67, 0x67, 0x0067 },
    { 0x68, 0x68, 0x0068 },
    { 0x69, 0x69, 0x0069 },
    { 0x6A, 0x6A, 0x006A },
    { 0x6B, 0x6B, 0x006B },
    { 0x6C, 0x6C, 0x006C },
    { 0x6D, 0x6D, 0x006D },
    { 0x6E, 0x6E, 0x006E },
    { 0x6F, 0x6F, 0x006F },
    { 0x70, 0x70, 0x0070 },
    { 0x71, 0x71, 0x0071 },
    { 0x72, 0x72, 0x0072 },
    { 0x73, 0x73, 0x0073 },
    { 0x74, 0x74, 0x0074 },
    { 0x75, 0x75, 0x0075 },
    { 0x76, 0x76, 0x0076 },
    { 0x77, 0x77, 0x0077 },
    { 0x78, 0x78, 0x0078 },
    { 0x79, 0x79, 0x0079 },
    { 0x7A, 0x7A, 0x007A },
    { 0x7B, 0x7B, 0x00E4 },
    { 0x7C, 0x7C, 0x00F6 },
    { 0x7D, 0x7D, 0x00F1 },
    { 0x7E, 0x7E, 0x00FC },
    { 0x7F, 0x7F, 0x00E0 },
    { 0x80, 0x94, 0x005E }, /* ^ */
    { 0x81, 0x9B, 0x0020 }, /* extension table mark as space*/
    { 0x82, 0xA8, 0x007B }, /* { */
    { 0x83, 0xA9, 0x007D }, /* } */
    { 0x84, 0xAF, 0x005C }, /* \ */
    { 0x85, 0xBD, 0x007E }, /* ~ */
    { 0x86, 0xBC, 0x005B }, /* [ */
    { 0x87, 0xBE, 0x005D }, /* ] */
    { 0x88, 0xC0, 0x007C }, /* | */
    { 0x89, 0xE5, 0x20AC }, /* The euro character */
    { 0x00, 0x00, 0x0000 }  /* END MARKER */
};    

#define IPL_WM_GSM_LIB_DEFAULT_GSM_CHAR_COUNT \
    ( sizeof( ipl_wm_gsm_lib_unicode_table ) / UCS2_VS_ASCII_CHAR_SIZE )

#define IPL_WM_GSM_LIB_EQUIVALENCY_CHAR_COUNT \
    ( sizeof( ipl_wm_gsm_lib_unicode_additional_table ) \
      / sizeof( IPL_WM_GSM_LIB_CONV_STR ) )

#define IPL_WM_GSM_LIB_EXTENSION_CHAR_COUNT \
    ( sizeof( ipl_wm_gsm_lib_extension_char_table )    \
      / sizeof( IPL_WM_GSM_LIB_CONV_STR ) )

#define IPL_WM_GSM_LIB_TR_SINGLE_SHIFT_CHAR_COUNT \
    ( sizeof( ipl_wm_gsm_lib_TR_single_shift_unicode_table ) \
      / sizeof( IPL_WM_GSM_LIB_CONV_STR ) )

#define IPL_WM_GSM_LIB_ES_SINGLE_SHIFT_CHAR_COUNT \
    ( sizeof( ipl_wm_gsm_lib_ES_single_shift_unicode_table ) \
      / sizeof( IPL_WM_GSM_LIB_CONV_STR ) )

#define IPL_WM_GSM_LIB_TR_LOCKING_SHIFT_CHAR_COUNT \
    ( sizeof( ipl_wm_gsm_lib_TR_locking_shift_diff_table ) \
      / sizeof( IPL_WM_GSM_LIB_CONV_STR ) )



tOCT_UINT16 igl_map_uni_to_gsm_tables (tOCT_UINT16 *uni_str, tOCT_UINT16 uni_len,
                                            tOCT_UINT8 **gsm_str,
                                            tOCT_INT8 *info, tOCT_UINT16 *error_count,
                                            tOCT_UINT8 gsm_table, tOCT_UINT8 ext_table);

tOCT_UINT16 ipl_wm_gsm_lib_unicode_to_gsm_with_language(
                                            tOCT_UINT16 *string, tOCT_UINT16 length, tOCT_UINT8 **result, tOCT_INT8 *info,
                                            tOCT_UINT16 *error_count, tOCT_UINT8 lang_locking_shift_table,
                                            tOCT_UINT8 lang_single_shift_table );

tOCT_UINT16 *ucs2_strcpy_ascii_to_ucs2(tOCT_UINT16 *destination, const char *source);
tOCT_UINT16 ipl_wm_gsm_lib_sms_pack_message( tOCT_UINT8 *dest_ptr, tOCT_UINT8 *src_ptr, tOCT_UINT16 byte_count );
tOCT_UINT8 ipl_wm_gsm_lib_calculate_packed_len( tOCT_UINT8 number_of_chars );
tOCT_INT8 ipl_wm_gsm_lib_asciiz_to_gsm_address ( char *ascii_ptr, tOCT_UINT8 *gsm_ptr, tOCT_UINT8 number_info, tOCT_UINT8 max_length, tOCT_UINT8 gsm_spec);
tOCT_UINT8 create_address( tOCT_UINT8 address_type, tOCT_UINT8 type_of_address, tOCT_UINT8 *address, tOCT_UINT8 **address_ptr );
tOCT_UINT8 create_sms_data( tOCT_UINT8 character_set, tOCT_UINT8 *data, tOCT_UINT8 *character_count, tOCT_UINT8 **user_data_ptr );
tOCT_UINT8 char2bcd2(tOCT_UINT8 input);
void buildCpData( tOCT_UINT8* outPtr, char* smsMsg, char* moMsisdn);

extern tOCT_UINT8 socketMsgBuf[EXTERNAL_MESSAGE_SIZE];
extern const tOCT_UINT8 const fill_frame[GSM_MACBLOCK_LEN] ;


tOCT_UINT16 igl_map_uni_to_gsm_tables(tOCT_UINT16 *uni_str, tOCT_UINT16 uni_len,
                                       tOCT_UINT8 **gsm_str,
                                       tOCT_INT8 *info, tOCT_UINT16 *error_count,
                                       tOCT_UINT8 gsm_table, tOCT_UINT8 ext_table)
{
    /*  
           Maps the specified unicode string into a GSM string using
           the specified language tables

       Inputs

           uni_str       = Unicode string to be mapped

           uni_len       = Length of the Unicode string

           gsm_table     = National Language Locking Shift table to be
                           used for mapping

           ext_table     = National Language Single Shift table to be
                           used for mapping

       Outputs

           gsm_str       = Resulting GSM string

           info          = Info value of the mapping

           error_count   = Number of mapping errors occurred

           return value  = Length of the resulting GSM string

-----------------------------------------------------------------------------
*/

    tOCT_UINT16 i;
    tOCT_UINT16 j;
    tOCT_UINT16 errors;
    tOCT_UINT8 char_found;
    tOCT_UINT16 extra_chars = 0;
    const IPL_WM_GSM_LIB_CONV_STR *diff_table_ptr;
    const IPL_WM_GSM_LIB_CONV_STR *ext_table_ptr;
    tOCT_UINT16 ext_table_char_count;
    tOCT_UINT16 diff_table_char_count;
    tOCT_UINT8 *temp_str;
    tOCT_UINT16 gsm_len;
    tOCT_UINT8 info_value;

    if( NULL != error_count )
      *error_count = 0;
    errors = 0;

    gsm_len = 0;
    info_value = 0;

    switch( gsm_table )
    {
        case IPL_WM_GSM_DEFAULT_LANGUAGE_TABLE:
            diff_table_ptr = NULL;
            diff_table_char_count = 0;
            break;

        default:
            diff_table_ptr = NULL;
            diff_table_char_count = 0;
            info_value = info_value | INVALID_PARAMS;
            break;
    }

    switch( ext_table )
    {
        case IPL_WM_GSM_DEFAULT_EXT_TABLE:
            ext_table_char_count = IPL_WM_GSM_LIB_EXTENSION_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_extension_char_table;
            break;

        case IPL_WM_GSM_TURKISH_EXT_TABLE:
            ext_table_char_count = IPL_WM_GSM_LIB_TR_SINGLE_SHIFT_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_TR_single_shift_unicode_table;
            break;

        case IPL_WM_GSM_SPANISH_EXT_TABLE:
            ext_table_char_count = IPL_WM_GSM_LIB_ES_SINGLE_SHIFT_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_ES_single_shift_unicode_table;
            break;

        default:
            ext_table_char_count = IPL_WM_GSM_LIB_EXTENSION_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_extension_char_table;
            info_value = info_value | INVALID_PARAMS;
            break;
    }

    /* Get the extra character count for extension characters */
    for ( i = 0; i < uni_len; i ++ )
    {
        for( j = 0; j < ext_table_char_count; j++ )
        {
            if( uni_str[ i ] == ext_table_ptr[ j ].unicode_char )
            {
                if ( ext_table_ptr[ j ].unicode_char != UCS2_SPACE )
                {
                    extra_chars++;
                }
                break;
            }
        }
    }

    temp_str = malloc( uni_len + extra_chars );
    assert(temp_str != NULL);
    memset( temp_str, 0, uni_len + extra_chars ); 

    for( i = 0; i < uni_len; i++)
    {
        char_found = FALSE;

        /* Look for character in the locking shift diff table */
        if( NULL != diff_table_ptr )
        {
            for( j = 0; j < diff_table_char_count; j++)
            {
                if( uni_str[ i ] == diff_table_ptr[ j ].unicode_char )
                {
                    temp_str[ gsm_len++ ] = diff_table_ptr[ j ].gsm_char;
                    char_found = TRUE;
                    info_value = info_value | ALL_CHARS_MAPPED;
                    break;
                }
            }
        }
        if( FALSE == char_found )
        {
            /* Look for character in default unicode table */
            for( j = 0; j < IPL_WM_GSM_LIB_DEFAULT_GSM_CHAR_COUNT; j++ )
            {
                if( uni_str[ i ] == ipl_wm_gsm_lib_unicode_table[ j ])
                {
                    temp_str[ gsm_len++ ] = ( tOCT_UINT8 )j;
                    char_found = TRUE;
                    info_value = info_value | ALL_CHARS_MAPPED;
                    break;
                }
            }
        }
        if( FALSE == char_found )
        {
            /* Look for character in extension table */
            for( j = 0; j < ext_table_char_count; j++ )
            {
                if( uni_str[ i ] == ext_table_ptr[ j ].unicode_char )
                {
                    temp_str[ gsm_len++ ] = GSM_ALPHABET_EXTENSION_CHAR;
                    temp_str[ gsm_len++ ] = ext_table_ptr[ j ].gsm_char;
                    char_found = TRUE;
                    info_value = info_value | ALL_CHARS_MAPPED;
                    break;
                }
            }
        }

        if( (NULL == diff_table_ptr) && (FALSE == char_found) )
        {
            /* Look for character in equivalency mapping table if no
                          locking shift table has been specified */
            for( j = 0; j < IPL_WM_GSM_LIB_EQUIVALENCY_CHAR_COUNT; j++ )
            {
                if( uni_str[ i ] == ipl_wm_gsm_lib_unicode_additional_table[ j ].unicode_char )
                {
                    temp_str[ gsm_len++ ] = ipl_wm_gsm_lib_unicode_additional_table[ j ].gsm_char;
                    char_found = TRUE;
                    errors++;
                    info_value = info_value | EQUIVALENCY_MAPPING_DONE;
                    break;
                }
            }
        }
        if( FALSE == char_found )
        {
            if( NULL == diff_table_ptr )
            {
                temp_str[ gsm_len++ ] = ASCII_SPACE;
                errors++;
                info_value = info_value | CHARS_REPLACED_OR_MAPPED;
            }
            else
            {
                temp_str[ gsm_len++ ] = ASCII_QUESTION_MARK;
                errors++;
                info_value = info_value | INVALID_CHARS;
            }
        }
    }
    if( ( NULL != gsm_str ) && ( 0 < gsm_len ) )
    {
        *gsm_str = malloc( gsm_len );
        assert(gsm_str != NULL);
        memset( *gsm_str, 0, gsm_len ); 
        memcpy( *gsm_str, temp_str, gsm_len );
    }

    free( temp_str );

    if ( NULL != info )
    {
        if( INVALID_PARAMS == ( info_value & INVALID_PARAMS ) )
        {
            *info = IPL_WM_GSM_ERR_INVALID_LANGUAGE_PARAMETERS;
        }
        else if( INVALID_CHARS == ( info_value & INVALID_CHARS ) )
        {
            *info = IPL_WM_GSM_ERR_INVALID_LANGUAGE_CHARS;
        }
        else if ( CHARS_REPLACED_OR_MAPPED == ( info_value & CHARS_REPLACED_OR_MAPPED ) )
        {
            *info = IPL_WM_GSM_CHARS_REPLACED_OR_MAPPED;
        }
        else if ( EQUIVALENCY_MAPPING_DONE == ( info_value & EQUIVALENCY_MAPPING_DONE ) )
        {
            *info = IPL_WM_GSM_EQUIVALENCY_MAPPING_DONE;
        }
        else if ( ALL_CHARS_MAPPED == ( info_value & ALL_CHARS_MAPPED ) )
        {
            *info = IPL_WM_GSM_ALL_CHARS_MAPPED;
        }
        else
        {
            *info = IPL_WM_GSM_INVALID_VALUE;
        }
    }

    if( NULL != error_count )
      *error_count = errors;

    return gsm_len;
}


tOCT_UINT16 ipl_wm_gsm_lib_unicode_to_gsm_with_language(
    tOCT_UINT16 *string, tOCT_UINT16 length, tOCT_UINT8 **result, tOCT_INT8 *info,
    tOCT_UINT16 *error_count, tOCT_UINT8 lang_locking_shift_table,
    tOCT_UINT8 lang_single_shift_table )
{
    /* 
        This function converts Unicode standard string into GSM 7 bit default
        alphabet (3GPP TS 23.038) string. Function also returns information
        about converted characters.

       Inputs:

        string          = pointer to the unicode string

        length          = unicode string length in characters

        lang_locking_shift_table
                        = National Language Locking Shift table to use

                        IPL_WM_GSM_DEFAULT_LANGUAGE_TABLE
                        IPL_WM_GSM_TURKISH_LANGUAGE_TABLE

                        Note that the Turkish locking shift is not to
                        be implemented at this time and thus will not
                        work.

        lang_single_shift_table
                        = National Language Single Shift table to use

                        IPL_WM_GSM_DEFAULT_EXT_TABLE
                        IPL_WM_GSM_TURKISH_EXT_TABLE
                        IPL_WM_GSM_SPANISH_EXT_TABLE

       Outputs:

        result    = pointer to the converted text
        info      = contains information about converted characters
                    according to values presented below. See details
                    from specification.

                    IPL_WM_GSM_ERR_INVALID_LANGUAGE_PARAMETERS
                    IPL_WM_GSM_INVALID_VALUE
                    IPL_WM_GSM_ALL_CHARS_MAPPED
                    IPL_WM_GSM_EQUIVALENCY_MAPPING_DONE
                    IPL_WM_GSM_CHARS_REPLACED_OR_MAPPED
                    IPL_WM_GSM_ERR_INVALID_LANGUAGE_CHARS

        error_count = number of characters that required equivalency
                      mapping, replacing or were invalid

        Return Values:

            Length of the converted string

-------------------------------------------------------------------------------
*/

    tOCT_UINT16  gsm_len;
    tOCT_UINT8   *temp_str;

    if( NULL != error_count )
      *error_count = 0;

    if( ( NULL == string ) || ( 0 == length ) )
    {
        if( NULL != result )
          *result = NULL;
		
        if ( NULL != info )
          *info = IPL_WM_GSM_INVALID_VALUE;
		
        return ( 0 );
    }

    gsm_len = igl_map_uni_to_gsm_tables( string, length, &temp_str, info,
                                   error_count, lang_locking_shift_table,
                                   lang_single_shift_table );

    if ( result != NULL )
    {
        *result = ( tOCT_UINT8* ) malloc( gsm_len );
        assert(result != NULL);
        memset( *result, 0, gsm_len ); 
        memcpy( *result, temp_str, gsm_len );
    }
    free( temp_str );

    return ( gsm_len );

}


tOCT_UINT16 *ucs2_strcpy_ascii_to_ucs2(tOCT_UINT16 *destination,
                                     const char *source)
{

  /* Data structures */

  tOCT_INT32 index;
    
  /* Code */

  index = 0;

  while(source[index] != NUL)
    {
      destination[index] = (tOCT_UINT16)(unsigned char)source[index];
      index++;
    }

  destination[index] = NUL;
    
  return (destination);
}


tOCT_UINT16 ipl_wm_gsm_lib_sms_pack_message( tOCT_UINT8 *dest_ptr, tOCT_UINT8 *src_ptr, tOCT_UINT16 byte_count )
{
    /* 
        This function packs a given text string consisting of 7-bit
        characters into 8 bit bytes in such a way that a 160-character
        message takes only 140 bytes of memory after the compression.

        The function returns the length of the packed message.

        Inputs:

        src_ptr:       pointer to array containing unpacked message
        byte_count:    the number of bytes in source

        Outputs

        dest_ptr:      pointer to array containing packed message

        Return Values:

        Length of packed message in bytes.

-------------------------------------------------------------------------------
*/

    tOCT_UINT16 si;
    tOCT_UINT16 di;
    tOCT_UINT8   tmp_modulo;

    si = 0;
    di = 0;
    tmp_modulo = di % BITS_IN_GSM_CHAR;

    while( si < byte_count )
    {
        /* Is this the last character of the message? If it is, just shift it
               * to the right. Otherwise, fill the rest of the byte with the bits of
               * the next source character.
               */
        if( si == ( byte_count - 1 ) )
        {
            dest_ptr[ di ] = ( src_ptr[ si ] >> tmp_modulo );
        }
        else
        {
            dest_ptr[ di ] = ( src_ptr[ si ] >> tmp_modulo ) | (src_ptr[ si + 1 ] << ( 7 - tmp_modulo ) );
        }

        di++;
        tmp_modulo = di % BITS_IN_GSM_CHAR;

        /* Check if the destination byte could take the entire source character.
               * In that case, the source character does not have to be divided and
               * the next source character can be taken.
               */
        if( tmp_modulo == 0 )
        {
            si += 2;
        }
        else
        {
            si++;
        }
    }

    /* Return the length of the coded message. */
    return( di );
}

tOCT_UINT8 ipl_wm_gsm_lib_calculate_packed_len( tOCT_UINT8 number_of_chars )
{
    tOCT_UINT8 semi_octet_count;
    semi_octet_count = 0;

    semi_octet_count = ( tOCT_UINT8)( number_of_chars * BITS_IN_GSM_CHAR ) / SEMI_OCTET_SIZE;

    if ( ( ( number_of_chars * BITS_IN_GSM_CHAR ) % SEMI_OCTET_SIZE ) > 0 )
    {
        semi_octet_count++;
    }

    return ( semi_octet_count );
}



tOCT_INT8 ipl_wm_gsm_lib_asciiz_to_gsm_address ( char *ascii_ptr, tOCT_UINT8 *gsm_ptr, tOCT_UINT8 number_info, tOCT_UINT8 max_length, tOCT_UINT8 gsm_spec)
{
     /* 
        This function encodes ASCIIZ address into GSM address format (TBCD).
        This function can encode the address formats of 3GPP TS 23.040, 24.008,
        24.011 and 29.002. The length field is in semi-octets when used
        coding is 3GPP TS 23.040 or in bytes if another coding is used.
        Function returns the total length of the encoded GSM address in bytes.
        A negative return value denotes an error code.

        The format of GSM address:

            Octet no:                      Description
                       ________________
                1     I                I   IE length or number of semi-octets
                      I________________I      in address-value (3GPP TS 23.040).
                2     I                I   Type of number and numbering plan
                      I________________I      identification.
                3     I                I   -
                      I________________I    |
                4     I                I    |
                      I________________I    |
                5     I                I    |
                      I________________I     -  Address-Value
                6     I                I    |
                      .                .    .
                      .                .    .
                n     I                I    |
                      I________________I   -

        Input Parameters:
            ascii_ptr     = Pointer to buffer containing ASCIIZ string address.
            number_info   = Type of address and numbering plan for the GSM
                             address. For possible values look at appropriate
                             specification.
            max_length    = Maximum length of encoded GSM address. This is size
                             of GSM address storage. At least 2 bytes must be
                             allocated.
            gsm_spec      = Used coding scheme for GSM address.


        Output Parameters:
            gsm_ptr        = Pointer to buffer containing encoded GSM address.

        Return Values:
            Positive value        = Total length of encoded address in bytes.
            IPL_WM_GSM_ERR_ADDRESS_TOO_LONG
                                  = The length of encoded GSM address exceeds
                                    maximum length, max_length. GSM address is
                                    encoded partly.
            IPL_WM_GSM_ERR_INVALID_CHARACTERS
                                  = Invalid characters were found from ASCIIZ
                                    address. GSM address is encoded partly.

------------------------------------------------------------------------------
*/

    tOCT_INT8       length;
    tOCT_UINT8      *length_ptr;
    tOCT_UINT8      *gsm_lcl_ptr;
    tOCT_UINT16     *ucs2_ptr;

    length = 0;

    /* Length_ptr points to the start of GSM address string. */
    length_ptr = gsm_ptr++;

    /* ASCII plus character is included only in case of alphanumeric
        * coded 23.040 address. Otherwise it is forbidden character to
        * be decoded and it is discarded. TON unknown requires special
        * handling due to SMS UI.
        */
    if ( ( *ascii_ptr == ASCII_PLUS ) && ( ( number_info & SMS_TP_ADDR_TON_MASK ) == SMS_TP_ADDR_TON_UNKNOWN ) )
    {
        /* TON unknown is changed to TON international. */
        number_info = 0x10 | number_info;
    }
    else if ( !( *ascii_ptr == ASCII_PLUS ) || ( ( *ascii_ptr == ASCII_PLUS ) && ( gsm_spec == ( tOCT_UINT8 ) IPL_WM_GSM_23040 )
         && ( number_info & SMS_TP_ADDR_TON_MASK ) == SMS_TP_ADDR_TON_ALPHANUMERIC ) )
    {
        ascii_ptr--;
    }

    /* Correct number info is set to gsm_ptr and
        * bit 7 is set to on.
        */
    *gsm_ptr  = number_info | EXT_BIT_MASK;

    /* Alphanumeric coding for 23.040 type of address */
    if ( ( gsm_spec == ( tOCT_UINT8 ) IPL_WM_GSM_23040 ) && ( ( number_info & SMS_TP_ADDR_TON_MASK ) == SMS_TP_ADDR_TON_ALPHANUMERIC ) )
    {
        /* Advance to first character */
        ascii_ptr++;
        gsm_ptr++;

        /* Convert ASCIIZ string to UCS2 in order to use existing GSM coding
               * function.
               */
        ucs2_ptr = ( tOCT_UINT16* )malloc( ( strlen ( ascii_ptr ) + 1 ) * UCS2_VS_ASCII_CHAR_SIZE );
        assert(ucs2_ptr != NULL);

        ( void ) ucs2_strcpy_ascii_to_ucs2 ( ucs2_ptr, ascii_ptr );
        length = ( tOCT_INT8 )ipl_wm_gsm_lib_unicode_to_gsm_with_language( (tOCT_UINT16 *)ucs2_ptr, ( tOCT_UINT16 )strlen( ascii_ptr ), 
			                  &gsm_lcl_ptr, NULL, NULL, IPL_WM_GSM_DEFAULT_LANGUAGE_TABLE, IPL_WM_GSM_DEFAULT_EXT_TABLE );
        free( ucs2_ptr );

        /* If maximum allocated length would be exceeded truncate address
               * within available space discarding extra characters.
               */
        if ( length > max_length )
        {
            ( void )ipl_wm_gsm_lib_sms_pack_message( gsm_ptr, gsm_lcl_ptr, ( tOCT_UINT16 )( max_length - ADDRESS_LEN_IE_AND_TOA ) );
            free( gsm_lcl_ptr );
            return ( IPL_WM_GSM_ERR_ADDRESS_TOO_LONG );
        }

        ( void)ipl_wm_gsm_lib_sms_pack_message( gsm_ptr, gsm_lcl_ptr, ( tOCT_UINT16 )( tOCT_UINT8 )length );

        length = ( tOCT_INT8 )ipl_wm_gsm_lib_calculate_packed_len( ( tOCT_UINT8 )length );
        free( gsm_lcl_ptr );
    }

    /* Semi-octet coding */
    else
    {
        while ( *++ascii_ptr != NUL )
        {
            if ( max_length-- < 3 )
            {
                return ( IPL_WM_GSM_ERR_ADDRESS_TOO_LONG );
            }

            /* Encode lower half of octet (first semi-octet).
                      * Check also contents so that input can be encoded.
                      */
            *++gsm_ptr = *ascii_ptr & 0x0F;
            if ( *ascii_ptr == ASCII_HASH )
            {
                *gsm_ptr |= 0x08;
            }
            else if ( ( *ascii_ptr >= ASCII_LOWER_CASE_A ) && ( *ascii_ptr <= ASCII_LOWER_CASE_C ) )
            {
                *gsm_ptr += 0x0B;
            }
            else if ( ( ( *ascii_ptr < ASCII_ZERO ) || ( *ascii_ptr > ASCII_NINE ) ) && ( *ascii_ptr != ASCII_ASTERISK ) )
            {
                return ( IPL_WM_GSM_ERR_INVALID_CHARACTERS );
            }
            length++;

            /* Encode higher half of octet (second semi-octet).
                      * Check also contents so that input can be encoded.
                      */
            if ( *++ascii_ptr != NUL )
            {
                *gsm_ptr |= ( tOCT_UINT8 ) ( *ascii_ptr << 4 );
                if ( *ascii_ptr == ASCII_HASH )
                {
                    *gsm_ptr |= 0x80;
                }
                else if ( ( *ascii_ptr >= ASCII_LOWER_CASE_A ) && ( *ascii_ptr <= ASCII_LOWER_CASE_C ) )
                {
                    *gsm_ptr += 0xB0;
                }
                else if ( ( ( *ascii_ptr < ASCII_ZERO ) || ( *ascii_ptr > ASCII_NINE ) ) && ( *ascii_ptr != ASCII_ASTERISK ) )
                {
                    return ( IPL_WM_GSM_ERR_INVALID_CHARACTERS );
                }
                length++;
            }
            else
            {
                /* In case of odd number of digits use end mark code. */
                *gsm_ptr |= 0xF0;
                break;
            }
        }
    }

    /* Length is in semi-octets, convert it to octets indicating IE length
        * if standard is different from 3GPP TS 23.040. Save length to the first
        * byte.
        */

    if ( gsm_spec == ( tOCT_UINT8 ) IPL_WM_GSM_23040 )
    {
        *length_ptr = ( tOCT_UINT8 ) length;
        length = ( length + 3 ) / OCTET_VS_SEMI_OCTET_SIZE;
    }
    else if ( ( gsm_spec == ( tOCT_UINT8 ) IPL_WM_GSM_24011 ) && ( length == 0 ) )
    {
        /* Special case in 3GPP TS 24.011, numbering plan is omitted if length
               * is 0.
               */
        *length_ptr = ( tOCT_UINT8 ) length;
    }
    else
    {
        length = ( length + 3 ) / OCTET_VS_SEMI_OCTET_SIZE;
        *length_ptr = ( tOCT_UINT8 ) length;
    }

    /* Return the total length of the encoded address in bytes. */
    return ( length + 1 );
}
    


/*--------------------------------------------------------------------------
 *  This function creates specification described address from ASCII
 *  string based on instructions from given variables.
 * --------------------------------------------------------------------------*/
tOCT_UINT8 create_address( tOCT_UINT8 address_type, tOCT_UINT8 type_of_address, tOCT_UINT8 *address, tOCT_UINT8 **address_ptr )
{
    tOCT_UINT8 address_length;
    tOCT_UINT8 gsm_spec;
    tOCT_INT8  result;

    /* Address length calculation:
        * number of characters in address is number of bytes,
        * subtract one if address includes '+'-sign as that is part of ToA,
        * divide remaining length by 2 since address is in BCD format,
        * and add bytes for address length field and ToA field. */

    if( address != NULL )
    {
        address_length = strlen( ( const char* )address );
    }
    else
    {
        address_length = NUL;
    }

    if( ( address != NULL ) && ( ASCII_PLUS == *address ) )
    {
        address_length--;
    }

    if ( SMS_TP_ADDR_TON_ALPHANUMERIC == ( type_of_address & SMS_TP_ADDR_TON_MASK ) && ( SMS_DESTINATION_ADDRESS == address_type ) )
    {
        address_length += ADDRESS_LEN_IE_AND_TOA;
    }
    else
    {
        address_length = ( address_length + 1 ) >> 1;
        address_length += ADDRESS_LEN_IE_AND_TOA;
    }

    if( SMS_DESTINATION_ADDRESS == address_type )
    {
        gsm_spec = IPL_WM_GSM_23040;
    }
    else
    {
        gsm_spec = IPL_WM_GSM_24011;
    }

    if( address != NULL )
    {
        /* MSB in Type-of-Address is forced to one as per specs. */
        result = ipl_wm_gsm_lib_asciiz_to_gsm_address( ( char* )address, *address_ptr, type_of_address | 0x80, address_length, gsm_spec );
    }
    else
    {
        /* Address length is set to minimum allowed */
        result = ADDRESS_LEN_IE_AND_TOA;
    }

    if( result < 0 )
    {
        logPrint( LOG_ERR, "SMS: create_address() - Address creation failed" );
        address_length = 0;
    }
    else
    {
        address_length = result;
    }

    return( address_length );
}


tOCT_UINT8 create_sms_data( tOCT_UINT8 character_set, tOCT_UINT8 *data, tOCT_UINT8 *character_count, tOCT_UINT8 **user_data_ptr )
{
    tOCT_UINT8* temp_user_data_ptr;
    tOCT_UINT8  data_length;

    *character_count = strlen( ( const char* )data );
    data_length = *character_count;
    if( SMS_UCS2_CS == character_set )
    {
        *character_count = *character_count >> 1;
    }
    else if( SMS_GSM_7BIT_CS == character_set )
    {
        data_length = ( ( *character_count + 1 ) * 7 ) / 8;
    }

    temp_user_data_ptr = ( tOCT_UINT8* ) malloc( data_length );
    assert(temp_user_data_ptr != NULL);
    memset(temp_user_data_ptr, 0, data_length); 

    if( SMS_GSM_7BIT_CS == character_set )
    {
        ( void )ipl_wm_gsm_lib_sms_pack_message( temp_user_data_ptr, data, ( tOCT_UINT16 )*character_count );
    }
    else
    {
        memcpy( temp_user_data_ptr, data, data_length );
    }

    memcpy (*user_data_ptr, temp_user_data_ptr, data_length);
    free( temp_user_data_ptr );

    return( data_length );
}

tOCT_UINT8 char2bcd2(tOCT_UINT8 input)
{
    tOCT_UINT8 high = 0;

	if(input > 99)
	{
        logPrint(LOG_ERR, "char2bcd2: input > 99");
		return input;
	}

    while (input >= 10)                 // Count tens
    {
        high++;
        input -= 10;
    }

    return  (high << 4) | input;        // Add ones and return answer
}

void buildCpData( tOCT_UINT8* outPtr, char* smsMsg,  char* moMsisdn)
{
	tOCT_UINT8	cpData[251] = {0};
	tOCT_UINT8* user_data_ptr = NULL;
	tOCT_UINT8	index = 0, data_length;
	tOCT_UINT8  character_count;
	tOCT_UINT8	tp_orig_address_length;
	tOCT_UINT8* tp_orig_address_ptr = NULL;
	
	time_t rawtime;
	struct tm *info;
	
	/* PD */
	cpData[index] = 0x09;
	index++;
	
	/* MsgType = CP_DATA */
	cpData[index] = 0x01;
	index++;
	
	/* CP-DATA Length */
	/* Will be filled at the end after calculations*/
	index++;
	
	/* RP-MsgType(Nw -> MS) */
	cpData[index] = 0x01;
	index++;
	
	/* RP-MsgRef */
	cpData[index] = 0x01;
	index++;

	/* RP-Originator Address, min length is 2: contents put as 0's now */
	cpData[index] = 0x02;
	index++;
	cpData[index] = 0x00;
	index++;
	cpData[index] = 0x00;
	index++;
	
	/* Destination Address, 0 in N/W->MS side */
	cpData[index] = 0x00;
	index++;
	
	/* RP-UserData-Length	*/
	/* Will be filled at the end after calculations*/
	index++;
	
	/* TPDU 1st Octet : TP-RP = '0', TP-UDHI = '0, TP-SRI = '0, TP-MMS = '1'( no more messages ), TP-MTI = '00'(SMS-DELIVER) */
	cpData[10] = 0x04;
	index++;
	
	/* TP-Originating-Address */
	tp_orig_address_ptr = &cpData[index];
	tp_orig_address_length = create_address( SMS_DESTINATION_ADDRESS, TOA_TON_INTERNATIONAL | TOA_NPI_ISDN, ( tOCT_UINT8* )moMsisdn, &tp_orig_address_ptr );
	
	index += tp_orig_address_length;

	/* TP-Protocol-Identifier */
	cpData[index] = 0x00;
	index++;
		
	/* TP-Data-Coding-Scheme : GSM 7 bit default alphabet*/
	cpData[index] = 0x00;
	index++;
	
	time(&rawtime);
	/* Get GMT time */
	info = gmtime(&rawtime );
		   
	/* TP Service-Centre-Time-Stamp */
	tOCT_UINT8 year, month;
	
	year = info->tm_year - 100;
	cpData[index] = SWAP_BYTE(char2bcd2(year));
	index++;
	
	month = info->tm_mon + 1;
	cpData[index] = SWAP_BYTE(char2bcd2(month));
	index++;
	 
	cpData[index] = SWAP_BYTE(char2bcd2(info->tm_mday));
	index++;
	
	cpData[index] = SWAP_BYTE(char2bcd2(info->tm_hour));
	index++;
	
	cpData[index] = SWAP_BYTE(char2bcd2(info->tm_min));
	index++;
	
	cpData[index] = SWAP_BYTE(char2bcd2(info->tm_sec));
	index++;
	
	cpData[index] =  0x00;
	index++;
	
	/* TP-User-Data */
	user_data_ptr = &cpData[index + 1];
	data_length = create_sms_data( SMS_GSM_7BIT_CS, ( tOCT_UINT8* )smsMsg, &character_count, &user_data_ptr );
	
	/* TP-User-Data-Length */
	cpData[index] = character_count;
	
	/* RP-UserData-Length */
	cpData[9] = data_length + tp_orig_address_length + 11;
	
	/* CP-Data Length */
	cpData[2] = data_length + tp_orig_address_length + 18;

	memcpy(outPtr, cpData, SMS_CP_DATA_MAX_LENGTH);

}


#ifdef FEA_DECODE_MO_SMS
int SMSLib_element_cmp(const void* p1, const void* p2)
{
    return ((tSMSLib_InformElement*)p1)->ElementId - ((tSMSLib_InformElement*)p2)->ElementId;
}


/*-------------------------------------------------------------------------*/
/* _slList_void_cmp

    Functional Description:
        Return value:
        The difference between element addresses.
        
        Description:
        This is the default compare function used if no finction is supplied
        in the slList_Init function. The function will just compare the
        addresses of the two elements. So two element references will only be
        considered logically equal if they actually refer to the same physical
        element.

    Parameters:

        p1 - 
            Pointer to element in list.

        p2 - 
            Pointer to element to compare with.

*/

int  _slList_void_cmp(const void*  p1, const void*  p2)
{
    return (char*)p1 - (char*)p2;
}

/*-------------------------------------------------------------------------*/
/* slList_Init

    Functional Description:

        Initializes the list.
        Example:
        Create a list:
        int element_cmp(const void* p1, const void* p2)
        {
        return ((ELEMENT*)p1)->key - ((ELEMENT*)p2)->key;
        }
        ...
        
        slList q;
        slList_Init(&q, element_cmp, offsetof(ELEMENT,link));

    Parameters:

        pCmpFn - 
            Supply a pointer to a function (int (*cmp)(void*p1, void* p2))
            that can be used to compare elements in this list. The function
            will be called with two pointers (p1 and p2) that will point to
            the two elements that should be compared. It is assumed that the
            compare function will compare the "key" values for the elements.
            This is, however, not a restriction: the function can do whatever
            the user want to do in order to "compare" elements. If the
            element pointed to by p1 is conceptually bigger that the element
            p2 is pointing to, the return value should be positive. If the
            two elements are to be considered equal then the function should
            return zero. If the p2 element is bigger a negative value should
            be returned. If you supply a NULL for this parameter, then the
            addresses of the elements will be compared.

        linkOffs - 
            All elements that will be inserted in this list must contain a
            pointer type field that can be used by this list. This value
            tells the offset of this field within the structure. You can use
            offsetof (stddef.h) to get this value. If you have defined your
            structure like this:
            
            typedef struct
            {
            int key;
            char* name;
            void* link;
            } ELEMENT;
            
            then offsetof(ELEMENT, link) will give the value 8.

*/

void slList_Init(slList* self, LIST_CMP_FN pCmpFn, tOCT_UINT16  linkOffs)
{
    self->last = NULL;

    if (pCmpFn == NULL)
    {
        self->compare = _slList_void_cmp;
    }
    else
    {
        self->compare = pCmpFn;
    }

    self->nElement = 0;
	self->linkOffset = linkOffs;
}

/* ====================================================================== */
/*
 * Description:
 *      The iterator can be used to go though all elements in a list. The
 *      iterator will also provide all functions that relate to some position
 *      in the list, e.g. inserting new elements before or after already
 *      inserted elements. Typical use of the iterator is like this:
 *      
 *      slIterator i;
 *      
 *      for (slIterator_Init(&i, &q); slIterator_Valid(&i);
 *      slIterator_Next(&i))
 *      {
 *      ELEMENT* p = (ELEMENT*)slIterator_Current(&i));
 *      if (p->name)
 *      ...
 *      }
 *      
 *      It is important to note, that while you use the iterator, you must
 *      only use the operations defined by the iterator and not otherwise
 *      manipulate the list (ei. insert and remove elements).
 */ 
/* ---------------------------------------------------------------------- */



/*-------------------------------------------------------------------------*/
/* slIterator_Init

    Functional Description:
        Return value:
        -
        
        Description:
        Initializes the iterator and associates it with a list.

    Parameters:

        q - 
            List that this iterator should work on

*/

void slIterator_Init(slIterator* self, slList * q)
{
    register int offs = q->linkOffset;
    self->pList = q;
    self->position = 0;
    if (q->last)
    {
        self->pPrev = q->last;
        self->pCurrent = NEXT(q->last);
    }
    else
    {
        self->pCurrent = NULL;
    }
}
/*-------------------------------------------------------------------------*/
/* slIterator_Next

    Functional Description:
        Return value:
        -
        
        Description:
        Advances to the next item. It is required that the iterator is not
        already out-of-bounds when you call this function.

*/

void slIterator_Next(slIterator* self)
{
    register int offs = self->pList->linkOffset;

    assert(self->position < self->pList->nElement);
    
    if (++self->position == self->pList->nElement)
    {
        self->pCurrent = NULL;
    }
    else
    {
        self->pPrev = self->pCurrent;
        self->pCurrent = NEXT(self->pCurrent);
    }
}

/*-------------------------------------------------------------------------*/
/* slList_Dispose

    Functional Description:
        Return value:
        -
        
        Description:
        Will both remove and dispose all elements from the list. Disposal is
        done through function given as argument.
        Example:
        void element_delete(void* p)
        {
        os_block_dealloc(((ELEMENT*)p)->name);
        }
        ...
        
        slList_Dispose(&q, element_delete);

    Parameters:

        pDispFn - 
            Pointer to a destructor function with the prototype void
            xxx(void*). Will be called repeatedly with a pointer to each
            element removed from the list. Should perform whatever action
            needed to dispose the element.

*/

/*-------------------------------------------------------------------------*/
/* slIterator_Current

    Functional Description:
        Return value:
        Pointer to item. NULL if the iterator is out-of-bounds (not Valid)
        
        Description:
        Provides access to the current item

*/

void * slIterator_Current(slIterator* self)
{
    return self->pCurrent;
}


/*-------------------------------------------------------------------------*/
/* slIterator_Go

    Functional Description:
        Return value:
        Pointer to element found at position. NULL if position is "one after
        last" (see below).
        
        Description:
        Positions the iterator on the specified position (0 based). It is
        illegal to go to a position wich is numerically bigger than number of
        elements in the list. E.g.: if there are 7 elements in the list it is
        legal to go to position 7, but the the return value will be NULL. This
        is to be consistent with the use of Next, where it is legal to advance
        to the next position when the current element is the last in the list

    Parameters:

        pos - 
            Position to go to

*/

void * slIterator_Go(slIterator* self, tOCT_UINT16 pos)
{
    assert(pos <= self->pList->nElement);
    if (pos < self->position)
    {
        /* Reset if requested position is before the current one */
        slIterator_Init(self, self->pList);
    }
        
    while (self->position < pos)
    {
        slIterator_Next(self);
    }
        
    return self->pCurrent;
}


/*-------------------------------------------------------------------------*/
/* slIterator_Find

    Functional Description:
        Return value:
        Pointer to element found. NULL if nothing found
        
        Description:
        Will find the first element in the list - starting from current
        position - that satisfies some criteria. Be aware that if you want to
        search for multiple elements satisfying the same criteria, then you
        should call "next" after each call to find. Otherwise you will find
        the same element again and again.
        
        Example:
        Find all elements where name is "Foo":
        
        int cmpFn(const void* p1, const void* p2)
        {
        return strcmp(((ELEMENT*)p1)->name, (const char*)p2);
        }
        ...
        
        slIterator_Init(&i, &q);
        while (slIterator_Find(&i, cmpFn, "Foo"))
        {
        ELEMENT* p = (ELEMENT*)slIterator_Current(&i);
        slIterator_Next(&i);
        }

    Parameters:

        pCmpFn - 
            Supply a pointer to a function (int (*cmp)(void*p1, void* p2))
            that should be used to find elements in this list. If NULL is
            supplied, the default compare function for the list is used.

        data - 
            This data will be passed as parameter no. 2 in the compare
            function. It can be a pointer to an object of the element type or
            it can be a pointer to some other data that you want to compare
            each element against.

*/

void * slIterator_Find(slIterator* self, LIST_CMP_FN pCmpFn, void * data)
{
    if (!pCmpFn)
    {
        pCmpFn = self->pList->compare;
    }

    while (self->pCurrent)
    {
        if (pCmpFn(self->pCurrent, data) == 0)
        {
            break;
        }        
        else
        {
            slIterator_Next(self);
        }
    } 
    return self->pCurrent;
}

void slList_InsertLast(slList* self, void * item)
{
    register int offs = self->linkOffset;
    if (self->last)
    {
        void** l = &NEXT(self->last);
        NEXT(item) = *l;
        *l = item;
    }
    else
    {
        NEXT(item) = item;
    }
    self->last = item;
    self->nElement++;
}


/*-------------------------------------------------------------------------*/
/* slList_RemoveAll

    Functional Description:
        Return value:
        -
        
        Description:
        Frees all elements from the list. Note that no attempt will be done to
        deallocate the elements (compare with Dispose).

*/

void slList_RemoveAll(slList* self)
{
    self->last = NULL;
    self->nElement = 0;
}


/*-------------------------------------------------------------------------*/
/* slIterator_InsertBefore

    Functional Description:
        Return value:
        -
        
        Description:
        Inserts an element before the current position. If the iterator is
        pointing to the position just after the end of the list, the element
        will be inserted as last element (this also covers the case where the
        list is empty).

    Parameters:

        item - 
            Item to be inserted.

*/

void slIterator_InsertBefore(slIterator* self, void * item)
{
    register int offs = self->pList->linkOffset;

    if (self->position == self->pList->nElement)
    {
        /* Iterator is one position beyond the end - insert element as last. This covers also the empty case */
        slList_InsertLast(self->pList, item);
    }
    else
    {
        NEXT(item) = self->pCurrent;
        NEXT(self->pPrev) = item;
        self->pList->nElement++;
    }

    self->pPrev = item;
    self->position++;
}


/*-------------------------------------------------------------------------*/
/* slIterator_InsertAfter

    Functional Description:
        Return value:
        -
        
        Description:
        Inserts an element after the current position. It is a precondition
        that the iterator is pointing to a valid position (Valid() must be
        true)

    Parameters:

        item - 
            Item to be inserted.

*/

void slIterator_InsertAfter(slIterator* self, void * item)
{
    register int offs = self->pList->linkOffset;

    assert(self->pCurrent);

    NEXT(item) = NEXT(self->pCurrent);
    NEXT(self->pCurrent) = item;
    self->pList->nElement++;

    /* Test if inserting after last element */
    if (self->pCurrent == self->pList->last)
    {
        self->pList->last = item;
        /* Test if only element before insertion*/
        if (self->pPrev == self->pCurrent)
        {
            self->pPrev = item;
        }
    }
        
}


/*-------------------------------------------------------------------------*/
/* slIterator_RemoveCurrent

    Functional Description:
        Return value:
        Item that was removed from the list
        
    Description:
        Removes the current item from the list. Be aware that this function
        will advance the iterator to the next position in the list. This
        means that you cannot use this function in a for loop where the "next"
        function is used to advance to the next item. The effect would be that
        you would skip the element found after the one you remove.

    Example:
    Remove certain elements of list pointed to by pList:

    slIterator i;
    slIterator_Init(&i, pList);
    while (slIterator_Valid(&i))
        {
        if (some_condition)
            {
            / * This also advances iterator to next element * /
            ELEMENT* p = slIterator_RemoveCurrent(&i);
            ...
            os_block_dealloc(p);
            }
        else
            {
            slIterator_Next(&i);
            }
        }
*/

void* slIterator_RemoveCurrent(slIterator* self)
{
    register int offs = self->pList->linkOffset;
    void* ret_val = self->pCurrent;
    slList* pList = self->pList;
    
    assert(ret_val);
    
    /* Check if we remove only element */
    if (self->pPrev == self->pCurrent)
    {
        pList->last = NULL;
        self->pCurrent = NULL;
    }
    else
    {
        self->pCurrent = NEXT(self->pCurrent);
        NEXT(self->pPrev) = self->pCurrent;

        /* Check if removing the last element */
        if (ret_val == pList->last)
        {
            pList->last = self->pPrev;
            self->pCurrent = NULL;
        }
    }

    self->pList->nElement--;

    return ret_val;
}

void SMSLib_ListDestructor(void* Element)
{
    tSMSLib_InformElement* tmpElem = (tSMSLib_InformElement*)Element;
    if(tmpElem->value)
    {
        free(tmpElem->value);
    }
    free(tmpElem);
}

void slList_Dispose(slList* self, LIST_DISPOSE_FN pDispFn)
{
    slIterator i;

    assert(pDispFn);
    
    slIterator_Init(&i, self);
    while (slIterator_Valid(&i))
    {
       void* p = slIterator_Current(&i);
       slIterator_Next(&i);
       pDispFn(p);
    }
    slList_RemoveAll(self);
}


tSMSLib_Message* SMSLib_Message_Create(void)
{
    tSMSLib_Message* Message = NULL;
    
    /* allocate correct size of memory */
    Message = malloc(sizeof(tSMSLib_Message));
    assert(Message != NULL );
    memset( Message, 0, sizeof(tSMSLib_Message) );

    /* Create SlList struct and store it to message struct */
    Message->InfoElementlist = malloc(sizeof(slList));
    assert(Message->InfoElementlist != NULL );
    memset( Message->InfoElementlist, 0, sizeof(slList) );

    /* Initialize info list */
    slList_Init(Message->InfoElementlist,                                   /* list pointer */
                SMSLib_element_cmp,                                         /* define own comparsion function */
                (tOCT_UINT16)offsetof(tSMSLib_InformElement,nextElement));  /* Calculate nextElement link pointer offset from beginning of tSMSLib_InformElement */

    return Message;
}

void SMSLib_Message_Destroy(tSMSLib_Message* message)
{
    if (message)
    {            
        if (message->UserData)
        {
            /* Remove User data buffer */
            free(message->UserData);
        }

        if (message->InfoElementlist)
        {
            /* Dispose all elements from list */
            slList_Dispose(message->InfoElementlist,SMSLib_ListDestructor);
            free(message->InfoElementlist);
        }

        if (message->AddressValue.address)
        {
            /* remove address if exist */
            free(message->AddressValue.address);
        }
        free(message);
    }
}


void SMSLib_DecodeBitFieldValues(tSMSLib_Message* Message, tOCT_UINT8 BitFieldValue)
{

    tOCT_UINT8 MessageType = Message->MessageTypeIndicator;

    if ( (MessageType == SMS_SUBMIT_REPORT) || (MessageType == SMS_DELIVER_REPORT) )
    {
        /* check UserDataHeaderIndicator bit field value */
        if((BitFieldValue & SMS_USERDATA_HEADER_IND_MASK))
            Message->UserDataHeaderIndicator = TRUE;
    }
    else /* SMS_SUBMIT, SMS_DELIVER, SMS_STATUS_REPORT, SMS_COMMAND */
    {
        /* Check Common fields */

        /* check UserDataHeaderIndicator bit field value */
        if((BitFieldValue & SMS_USERDATA_HEADER_IND_MASK))
            Message->UserDataHeaderIndicator = TRUE;

        /* check StatusReportIndication bit field value */
        if((BitFieldValue & SMS_REPORT_IND_REQ_QUAL_MASK))
            Message->StatusReportIndReqQual = TRUE;


        if ((MessageType == SMS_SUBMIT) || (MessageType == SMS_DELIVER))
        {
            /* check ReplyPath bit field value */
            if((BitFieldValue & SMS_REPLY_PATH_MASK))
                Message->ReplyPath = TRUE;
        }

        if( (MessageType == SMS_STATUS_REPORT) || (MessageType == SMS_DELIVER) )
        {
            /* check MoreMessagestoSend TRUE/FALSE and add it in bit field */
            if(BitFieldValue & SMS_MORE_MES_TO_SEND_MASK)
                Message->MoreMessagestoSend = TRUE;
        }

        if(MessageType == SMS_SUBMIT)
        {
            /* check RejectDuplicates bit field value */
            if((BitFieldValue & SMS_REJECT_DUPLICATES_MASK))
               Message->RejectDuplicates = TRUE;

            /* check ValidityPeriodFormat bits field value */
            Message->ValidityPeriodFormat = (tOCT_UINT8)(BitFieldValue & SMS_VALIDITY_PERIOD_MASK);
        }

    }

}

void ipl_wm_gsm_lib_sms_unpack_message( tOCT_UINT8 *dest_ptr, tOCT_UINT8 *src_ptr, tOCT_UINT16 char_count )
    {
/*  Functional Description

        This function decodes a message that has been encoded using the
        algorithm described in 3GPP TS 23.038. The result string will consist of
        bytes that contain a 7-bit character each.

    Inputs
        src_ptr:       pointer to array containing packed message
        char_count:    the number of characters in source

    Outputs
        dest_ptr:      pointer to array containing unpacked message

-------------------------------------------------------------------------------
*/

    /* This table is used when a SMS message is being unpacked. */
    static const tOCT_UINT8 gsm_lib_sms_unpack_mask_table[ 8 ] = { 0x7F, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };
    tOCT_UINT16 si;
    tOCT_UINT16 di;
    tOCT_UINT8  tmp_modulo;

    si = 0;

    /* The location of the current 7-bit character determines the
        * action to be taken. Only every 7th character is not divided into
        * two bytes. All other characters will have to be constructed by
        * combining bits of two consequent bytes.
        */

    for( di = 0; di < char_count; di++ )
    {
        tmp_modulo = di % BITS_IN_BYTE;
        switch( tmp_modulo )
        {
            case 0:
                dest_ptr[ di ] = src_ptr[ si ] & 0x7F;
                break;
            case 7:
                dest_ptr[ di ] = ( src_ptr[ si ] >> 1 ) & 0x7F;
                si++;
                break;
            default:
                dest_ptr[ di ]  = src_ptr[ si ] >> ( 8 - ( tmp_modulo ) );
                dest_ptr[ di ] &= gsm_lib_sms_unpack_mask_table[ tmp_modulo ];
                dest_ptr[ di ] |= src_ptr[ si + 1 ] << tmp_modulo;
                dest_ptr[ di ] &= 0x7F;
                si++;
                break;
        }
    }

}

tOCT_UINT16 *ipl_wm_gsm_lib_gsm_to_unicode_and_info( tOCT_UINT8 *string, tOCT_UINT16 *length, tOCT_INT8 *info,tOCT_UINT8 lang_locking_shift_table, tOCT_UINT8 lang_single_shift_table )
    {
/*  Functional Description

        This function converts GSM 7 bit default alphabet (3GPP TS 23.038)
        string into Unicode standard string.

        Function call

        converted_string_ptr = ipl_wm_gsm_lib_gsm_to_unicode_and_info(
           gsm_string_ptr, gsm_string_length_ptr, return_info_ptr,
           locking_shift_param, single_shift_param )


    Inputs

        string          = pointer to the text
        length          = pointer to text length in characters
        lang_locking_shift = defines the language (locking shift) table to be used

                          IPL_WM_GSM_DEFAULT_LANGUAGE_TABLE
                          IPL_WM_GSM_TURKISH_LANGUAGE_TABLE

        lang_single_shift = defines the extension (single shift) table to be used

                          IPL_WM_GSM_DEFAULT_EXT_TABLE
                          IPL_WM_GSM_TURKISH_EXT_TABLE
                          IPL_WM_GSM_SPANISH_EXT_TABLE

    Outputs

        *length  will be reduced if extension character(s) exists in original text string

        *info    will contain the conversion result

        Return Values:

        unicode_string    = pointer to the converted text

    Exceptional conditions

        Before using this function GSM 7 bit default alphabet string
        must be decoded to string which consist of bytes that contain
        a 7-bit character each. e.g. by using function
        ipl_wm_gsm_lib_sms_unpack_message

-------------------------------------------------------------------------------
*/

    tOCT_UINT16 i;
    tOCT_UINT16 j;
    tOCT_UINT16 unicode_index;
    tOCT_UINT16 *unicode_string;
    const IPL_WM_GSM_LIB_CONV_STR *diff_table_ptr;
    const IPL_WM_GSM_LIB_CONV_STR *ext_table_ptr;
    tOCT_UINT16 diff_table_char_count;
    tOCT_UINT16 ext_table_char_count;
    tOCT_INT8  info_value;
    tOCT_UINT8 char_found;

    unicode_index = 0;
    info_value = 0;
    if( NULL != info )
    {
        *info = 0;
    }
    if( ( NULL == string ) || ( NULL == length ) )
    {
        if( NULL != info )
        {
            *info = IPL_WM_GSM_INVALID_VALUE;
        }
        return NULL;
    }

    /* Get a pointer to specified diff table */
    switch( lang_locking_shift_table )
    {
        case IPL_WM_GSM_DEFAULT_LANGUAGE_TABLE:
            diff_table_ptr = NULL;
            diff_table_char_count = 0;
            break;

        case IPL_WM_GSM_TURKISH_LANGUAGE_TABLE:
            diff_table_ptr = ipl_wm_gsm_lib_TR_locking_shift_diff_table;
            diff_table_char_count = IPL_WM_GSM_LIB_TR_LOCKING_SHIFT_CHAR_COUNT;
            break;

        default:
            diff_table_ptr = NULL;
            diff_table_char_count = 0;
            info_value = info_value | INVALID_PARAMS;
            break;
    }

    switch( lang_single_shift_table )
    {
        case IPL_WM_GSM_DEFAULT_EXT_TABLE:
            ext_table_char_count = IPL_WM_GSM_LIB_EXTENSION_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_extension_char_table;
            break;

        case IPL_WM_GSM_TURKISH_EXT_TABLE:
            ext_table_char_count = IPL_WM_GSM_LIB_TR_SINGLE_SHIFT_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_TR_single_shift_unicode_table;
            break;

        case IPL_WM_GSM_SPANISH_EXT_TABLE:
            ext_table_char_count = IPL_WM_GSM_LIB_ES_SINGLE_SHIFT_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_ES_single_shift_unicode_table;
            break;

        default:
            ext_table_char_count = IPL_WM_GSM_LIB_EXTENSION_CHAR_COUNT;
            ext_table_ptr = ipl_wm_gsm_lib_extension_char_table;
            info_value = info_value | INVALID_PARAMS;
            break;
    }

    if( ( NULL == string ) || ( 0 == *length ) )
    {
        return ( NULL );
    }

    unicode_string = ( tOCT_UINT16 * ) malloc( ( tOCT_UINT16 ) ( *length * UCS2_VS_ASCII_CHAR_SIZE ) );
    assert ( unicode_string != NULL );
    memset( unicode_string, 0, ( tOCT_UINT16 ) ( *length * UCS2_VS_ASCII_CHAR_SIZE ) ); 

    /* Character mapping */
    for( i = 0; i < *length; i++ )
    {
        char_found = FALSE;
        /* Is this extension table character? */
        if( string[ i ] == GSM_ALPHABET_EXTENSION_CHAR )
        {
            /* Is extension character is the last one? */
            if( ( i + 1 ) < *length )
            {
                /* If there is two on the row they will be converted to one
                              * space character as there is only one extension table defined
                              * presently.
                              */
                if( string[ i + 1 ] == GSM_ALPHABET_EXTENSION_CHAR )
                {
                    unicode_string[ unicode_index++ ] = UCS2_SPACE;
                    i++;
                    char_found = TRUE;
                }
                else
                {
                    /* Look up for valid extension character */
                    for( j = 0; j < ext_table_char_count; j++ )
                    {
                        if( string[ i + 1 ] == ext_table_ptr[ j ].gsm_char )
                        {
                            unicode_string[ unicode_index++ ] = ext_table_ptr[ j ].unicode_char;
                            i++;
                            char_found = TRUE;
                            break;
                        }
                    }

                    /* If no extension character was defined in the
                                     * table, we will skip this and treat the next
                                     * character like it was a normal character */
                }
            }
            /* Single extension character at the end is converted to space. */
            else
            {
                unicode_string[ unicode_index++ ] = UCS2_SPACE;
                char_found = TRUE;
            }
        }

        /* Normal character conversion */
        else
        {
            if( NULL != diff_table_ptr )
            {
                for( j = 0;j < diff_table_char_count; j++ )
                {
                    if( diff_table_ptr[ j ].gsm_char == string[i] )
                    {
                        unicode_string[ unicode_index++ ] = diff_table_ptr[ j ].unicode_char;
                        char_found = TRUE;
                        break;
                    }
                }
            }
            if( FALSE == char_found )
            {
                unicode_string[ unicode_index++ ] = ipl_wm_gsm_lib_unicode_table[ string[ i ] ];
                char_found = TRUE;
            }
            if( TRUE == char_found )
            {
                info_value = info_value | ALL_CHARS_MAPPED;
            }
        }
    }
    /* Character mapping ends */

    *length = unicode_index;

    if( NULL != info )
    {
        if( INVALID_VALUE == info_value )
        {
            *info = IPL_WM_GSM_INVALID_VALUE;
        }
        else if( INVALID_PARAMS == ( info_value & INVALID_PARAMS) )
        {
            *info = IPL_WM_GSM_ERR_INVALID_LANGUAGE_PARAMETERS;
        }
        else if( ALL_CHARS_MAPPED == ( info_value & ALL_CHARS_MAPPED ) )
        {
            *info = IPL_WM_GSM_ALL_CHARS_MAPPED;
        }
        else
        {
            *info = IPL_WM_GSM_INVALID_VALUE;
        }
    }

    return ( unicode_string );
}

tOCT_UINT16 *ucs2_strncpy(tOCT_UINT16 *destination, const tOCT_UINT16 *source, tOCT_UINT32 count)
{
    tOCT_UINT16 *original;
    tOCT_UINT16  character;

    if(count == 0)
    {
        return destination;
    }

    original = destination;

    while( count-- > 0 )
    {
        character = *source++;
        *destination++ = character;

        if( character == NUL )
        {
            while( count-- > 0 )
            {
                *destination++ = character;
            }
            break;
        }
    }
    return original;
}

tOCT_UINT16 *ucs2_strncpy_endian(tOCT_UINT16 *destination, const tOCT_UINT16 *source, tOCT_UINT32 count, tOCT_UINT32 mode)
{
  tOCT_INT32 i2Counter = 0;

  if(count == 0)
  {
      return destination;
  }
    
  while( (count > 0) && (source[i2Counter] != NUL) )
  {

      switch(mode)
      {
          case UCS2_FROM_BIG_TO_PLATFORM_ENDIAN:
            destination[i2Counter] = GETB16(&source[i2Counter]);
            break;
          case UCS2_FROM_PLATFORM_TO_BIG_ENDIAN:
            PUTB16(&destination[i2Counter], source[i2Counter]);
            break;
          case UCS2_FROM_LITTLE_TO_PLATFORM_ENDIAN:
            destination[i2Counter] = GETL16(&source[i2Counter]);
            break;
          case UCS2_FROM_PLATFORM_TO_LITTLE_ENDIAN:
            PUTL16(&destination[i2Counter], source[i2Counter]);
            break;
          default:
            destination[i2Counter] = source[i2Counter];
            break;
        }

      i2Counter++;
      count--;
  }

  while( count > 0)
  {
      destination[i2Counter++] = NUL;
      count--;
  }
            
  return (destination);
}


static tOCT_UINT8 *ipl_wm_gsm_lib_find_next_octet( tOCT_UINT8 *ie_ptr, tOCT_UINT8 *ie_len )
{

/*  Description

        Skip the octet at ie_ptr and advance the pointer to the first
        octet of the next octet group. ie_len is a limiter to avoid
        pointing beyond the end of IE. Pointer to the next octet group
        is returned to the caller. The number of bytes ie_ptr was
        advanced is subtracted from ie_len.

    Inputs
            ie_ptr      = Pointer to an octet in IE.
            ie_len      = Number of remaining bytes to the end of the IE.
                              Notice that this is not necessary the same as the length of the whole IE.

    Outputs
            ie_len      = Number of remaining bytes after finding the next octet.

        Return Values:
            Pointer to the next octet in IE.

 --------------------------------------------------------------------------
*/
    while ( ( *ie_len > 0 ) && ( ( *ie_ptr & 0x80 ) != 0x80 ) )
    {
        ie_ptr++;           /* skip extension octets  */
        ( *ie_len )--;
    }

    if ( *ie_len > 0 )      /* avoid pointing beyond the end of IE  */
    {
        ie_ptr++;           /* point to the beginning of next octet */
        ( *ie_len )--;
    }

    return ( ie_ptr );
}


tOCT_INT8 ipl_wm_gsm_lib_gsm_address_to_ucs2( IPL_WM_GSM_LIB_GSM_UCS2_PARAMETERS_STR *param )
{
/*    Functional Description

        This function decodes GSM address format (TBCD) into UCS-2 address format.

        Decoding rules are defined in Table 10.5.118/3GPP TS 24.008 or TBCD-STRING/3GPP TS 29.002.

        This function can decode the address formats of 3GPP TS 23.040, 24.011, 24.008 and 29.002.

        The format of GSM address:

            Octet no:                      Description
                       ________________
                1     I                I   IE length or number of semi-octets
                      I________________I      in address-value (3GPP TS 23.040).
                2     I                I   Type of number and numbering plan
                      I________________I      identification.
                2a    I                I   Presentation and screening
                      .                .      indicator (optional)
                      .                .      Valid for 24.008 and 29.002.
                2n    I                I   The rest of possible extensions
                      I________________I
                3     I                I   -
                      I________________I    |
                4     I                I    |
                      I________________I    |
                5     I                I    |
                      I________________I     -  Address-Value
                6     I                I    |
                      .                .    .
                      .                .    .
                n     I                I    |
                      I________________I   -


     Inputs

        Struct *IPL_WM_GSM_LIB_GSM_UCS2_PARAMETERS_STR contents:

           ucs2_ptr  = Pointer to UCS-2 address.

            gsm_ptr     = Pointer to GSM address.

            number_info = Points to memory location which value is set at function exit point to (return value):

                                Type of number and numbering plan identification (octet 2).

                                Format:

                                Byte  7   6   5   4   3   2   1   0
                                     _______________________________
                                    I   I   Type of I Numbering     I
                                    I 0 I   number  I plan identif. I
                                    I___I___________I_______________I

            ucs2_length = Points to memory location which value is set at function exit point (return value): Number of UCS-2 characters to convert.

            gsm_spec     = Used coding; selects the format of length field.

            pres_scr_ind= Points to memory location which value is set at function exit point to (return value):

                                Presentation and screening indicators (defined in Table 10.81/3GPP TS 24.008 or AddressString/3GPP TS 29.002).

                                Format:

                                Byte  7   6   5   4   3   2   1   0
                                     _______________________________
                                    I   IPresen.I           I Scree.I
                                    I 0 Iindi.  I 0   0   0 I indi. I
                                    I___I_______I___________I_______I


                                Return value if octet 2a is not present is 0: presentation indicator = presentation allowed, screening indicator = user-provided, not screened

     Outputs

        Parameters:
            Passed through memory location to which pointers at IPL_WM_GSM_LIB_GSM_UCS2_PARAMETERS_STR structure point.

        Return Values:
            IPL_WM_GSM_OK            = Successful conversion.
            IPL_WM_GSM_ERR_ADDRESS_TOO_LONG = The length of decoded GSM address exceeds maximum length of UCS2 string. GSM address is decoded only partly.

------------------------------------------------------------------------------
*/

    tOCT_UINT8   length;
    tOCT_UINT8   ucs2_length_i;
    tOCT_UINT8  is_address_too_long;
    tOCT_UINT16 number_of_chars;
    tOCT_UINT8  number_of_digits;
    tOCT_UINT8  number_of_skipped_digits;
    tOCT_UINT8  *gsm_packed_lcl_ptr;
    tOCT_UINT8  *gsm_packed_lcl_start_ptr;
    tOCT_UINT8  *gsm_unpacked_lcl_ptr;

    ucs2_length_i = 0;
    number_of_chars = 0;
    number_of_digits = 0;
    number_of_skipped_digits = 0;

    is_address_too_long = FALSE;

    length = *( param->gsm_ptr )++;

    if ( 0 == length )
    {
        *( param->pres_scr_ind ) = IPL_WM_GSM_CPN_NOT_AVAILABLE;
        *( param->ucs2_length ) = 0;
        return ( IPL_WM_GSM_OK );
    }

    if ( param->gsm_spec == ( tOCT_UINT8 )IPL_WM_GSM_23040 )
    {
        /* Store number of characters in case this is alphanumeric address. */
        number_of_chars = ( tOCT_UINT16 )( length * SEMI_OCTET_SIZE ) / BITS_IN_GSM_CHAR;

        /* In 3GPP TS 23.040 the length field is the number of effective packed
               * digits. Convert it to bytes and add one byte for Type-of-Address
               * field.
               */
        number_of_digits = length;
        length = ( length + 3 ) / OCTET_VS_SEMI_OCTET_SIZE;
    }
    else
    {
        /* In other 3GPP TSs the length field is the IE length in
               * bytes. Subtract type of number and numbering plan ID byte.
               * If address contains odd number of digits, last digit
               * is "1111" and it will be ignored.
               */
        number_of_digits = ( length - 1 ) * OCTET_VS_SEMI_OCTET_SIZE;
    }

    /* Type of number and numbering plan identification are
         * copied from octet 2.
         */
    *param->number_info = *( param->gsm_ptr ) & 0x7F;

    /* default value to presentation indicator */
    *( param->pres_scr_ind ) = 0x00;

    /* Alphanumeric coding for 23.040 type of address */
    if ( ( param->gsm_spec == ( tOCT_UINT8 ) IPL_WM_GSM_23040 ) && ( ( ( *param->number_info ) & IPL_WM_GSM_TON_MASK ) == IPL_WM_GSM_TON_ALPHANUMERIC ) )
    {
        /* Move over Type-of-Address to first GSM character. */
        param->gsm_ptr++;
        length--;

        if ( 0 == length )
        {
            ucs2_length_i = 0;
        }
        /* Errorneous situation where semi-octet count is one. */
        else if (0 == number_of_chars )
        {
            *( param->ucs2_ptr ) = 0x0000;
            *( param->ucs2_length ) = 0;
            return ( IPL_WM_GSM_OK );
        }
        else
        {
            gsm_packed_lcl_ptr = ( tOCT_UINT8* ) malloc( *( param->ucs2_length ) * SAFETY_BUFFER_MULTIPLIER );
            assert ( gsm_packed_lcl_ptr != NULL );
            memset( gsm_packed_lcl_ptr, 0, *( param->ucs2_length ) * SAFETY_BUFFER_MULTIPLIER ); 
            gsm_packed_lcl_start_ptr = gsm_packed_lcl_ptr;

            gsm_unpacked_lcl_ptr = ( tOCT_UINT8* ) malloc( *( param->ucs2_length ) * SAFETY_BUFFER_MULTIPLIER );
            if ( gsm_unpacked_lcl_ptr != NULL );
            memset( gsm_unpacked_lcl_ptr, 0, *( param->ucs2_length ) * SAFETY_BUFFER_MULTIPLIER ); 

            while ( length > 0 )
            {
                /* Is maximum UCS2 string length exceeded? */
                if ( ucs2_length_i >= *( param->ucs2_length ) )
                {
                    is_address_too_long = TRUE;
                    ucs2_length_i = *( param->ucs2_length );
                    /* number_of_chars must be same with ucs2_length at this code branch. */
                    number_of_chars = *( param->ucs2_length );
                    break;
                }

                *( gsm_packed_lcl_ptr )++ = *( param->gsm_ptr )++;

                ucs2_length_i++;
                length--;
            }
            ipl_wm_gsm_lib_sms_unpack_message( gsm_unpacked_lcl_ptr, gsm_packed_lcl_start_ptr, number_of_chars );

            /* convert and store data to temporary existing buffer */
            gsm_packed_lcl_ptr = ( tOCT_UINT8* ) ipl_wm_gsm_lib_gsm_to_unicode_and_info( gsm_unpacked_lcl_ptr, &number_of_chars, NULL, IPL_WM_GSM_DEFAULT_LANGUAGE_TABLE, IPL_WM_GSM_DEFAULT_EXT_TABLE );

            /* Copy data from temporary buffer to client buffer. */
            ucs2_strncpy( param->ucs2_ptr,(tOCT_UINT16*)gsm_packed_lcl_ptr, number_of_chars );

            ucs2_length_i = ( tOCT_UINT8 )number_of_chars;

            free( gsm_packed_lcl_start_ptr );
            free( gsm_unpacked_lcl_ptr );
            free( gsm_packed_lcl_ptr );
            gsm_packed_lcl_ptr = NULL;
            gsm_packed_lcl_start_ptr = NULL;
            gsm_unpacked_lcl_ptr = NULL;

            if ( is_address_too_long == TRUE )
            {
                return ( IPL_WM_GSM_ERR_ADDRESS_TOO_LONG );
            }
        }
    }

    /* Semi-octet coding */
    else
    {
        if ( length > 0 )
        {
            length--;

            /* Check whether octet 2a or 3* exist. Not possible on 23.040 */
            if ( ( length > 0 ) && ( ( *( param->gsm_ptr++ ) & EXT_BIT_MASK ) == 0x00 ) && ( param->gsm_spec != ( tOCT_UINT8 ) IPL_WM_GSM_23040 ) )
            {

                /* Copy value from octet 2a or 3* to presentation and screening indicator. */
                if ( param->gsm_spec != ( tOCT_UINT8 ) IPL_WM_GSM_24011 )
                {
                    *( param->pres_scr_ind ) = ( *( param->gsm_ptr ) & 0x63 );
                }

                /* Skip over the rest of octet 2a or 3* extensions. */
                param->gsm_ptr = ipl_wm_gsm_lib_find_next_octet( param->gsm_ptr, &length);
            }
        }

        /* Translate GSM address semioctets to UCS2 string words. */
        while ( ( length > 0 ) && ( ucs2_length_i < number_of_digits ) )
        {
            /* When ucs2_length_i (runs from zero to max length) is odd  number decode lower half of octet (first semi-octet). */
            if ( ( ucs2_length_i & 1 ) == 0 )
            {
                /* "1111" shall be skipped */
                if ( ( *( param->gsm_ptr ) & LOWER_SEMI_OCTET_MASK ) == GSM_ADDRESS_END_MARK )
                {
                    number_of_skipped_digits++;
                }
                else
                {
                    /* Is maximum UCS2 string length exceeded? */
                    if ( ( ucs2_length_i - number_of_skipped_digits ) >= *( param->ucs2_length ) )
                    {
                        return( IPL_WM_GSM_ERR_ADDRESS_TOO_LONG );
                    }
                    else
                    {
                        *( param->ucs2_ptr )++ = ipl_wm_gsm_semioct_to_char_table[( *( param->gsm_ptr ) & LOWER_SEMI_OCTET_MASK ) ];
                    }
                }
            }
            /* When ucs2_length_i is even decode upper half of octet (second semi-octet). */
            else
            {
                /* "1111" shall be skipped */
                if ( ( *( param->gsm_ptr ) >> 4 ) == GSM_ADDRESS_END_MARK )
                {
                    number_of_skipped_digits++;
                }
                else
                {
                    /* Is maximum UCS2 string length exceeded? */
                    if ( ( ucs2_length_i - number_of_skipped_digits ) >= *( param->ucs2_length ) )
                    {
                        return ( IPL_WM_GSM_ERR_ADDRESS_TOO_LONG );
                    }
                    else
                    {
                        *( param->ucs2_ptr )++ = ipl_wm_gsm_semioct_to_char_table[( *( param->gsm_ptr ) >> 4 ) ];
                    }
                }
                param->gsm_ptr++;
                length--;
            }
            ucs2_length_i++;
        }
        /* Number of skipped digits needs to be subtracted from ucs2_length_i to get the number of digits decoded to UCS2 format. */
        ucs2_length_i -= number_of_skipped_digits;
    }

    *( param->ucs2_length ) = ucs2_length_i;

    return ( IPL_WM_GSM_OK );
}

tOCT_UINT8* SMSLib_DecodeAddressField(const tOCT_UINT8* MessageBuffer, tOCT_UINT32 MessageBufferLegth, tSMSLib_Address* Address, tOCT_UINT8 gsm_spec)
{
    tOCT_UINT8       number_info   = 0;
    tOCT_UINT8       ucs2_length   = SMS_MAX_GSM_ADDRESS_LENGTH; /* Null termination also reserved */
    tOCT_UINT8       pres_scr_ind  = 0;
    tOCT_INT8        return_value  = 0;
    tOCT_UINT32      tmpLength     = 0;
    tOCT_UINT32      characters    = 0;
    tOCT_UINT16*     tmpString     = NULL;

    IPL_WM_GSM_LIB_GSM_UCS2_PARAMETERS_STR AddressStruct;


    /* Calculate AddressLenght in bytes */
    tmpLength = *MessageBuffer;

    /* In 3GPP TS 23.040 the length field is the number of effective packed
     * digits. Convert it to bytes and add one byte for octet 3.
     */
    tmpLength = ( tmpLength + 3 ) / 2;

    /* Check do we least have enought data to address field */
    if (tmpLength < (MessageBufferLegth-1))
    {
        /* Parse gsm address to ucs2 format and store other address info */
        /* Initialize conversion struct */
        AddressStruct.number_info = &number_info;
        AddressStruct.ucs2_length = &ucs2_length;
        AddressStruct.pres_scr_ind = &pres_scr_ind;
        AddressStruct.ucs2_ptr = malloc(ucs2_length*2);
        assert ( AddressStruct.ucs2_ptr != NULL);
        memset( AddressStruct.ucs2_ptr, 0, ucs2_length*2 );

        /* store original buffer because conversion lose it */
        Address->address = AddressStruct.ucs2_ptr;

        AddressStruct.gsm_spec = gsm_spec;
        AddressStruct.gsm_ptr = (tOCT_UINT8*) MessageBuffer;

        return_value = ipl_wm_gsm_lib_gsm_address_to_ucs2(&AddressStruct);

        if ( (number_info & SMS_GSM_ADDRESS_TYPE_MASK) == IPL_WM_GSM_TON_ALPHANUMERIC )
        {
            /* Calculate ascii address value length */
            characters = ((*MessageBuffer)*SMS_SEMI_OCTET_SIZE)/7;

            if (return_value == TRUE   ) /* && characters == *AddressStruct.ucs2_length*/
            {
                Address->address_length  = *AddressStruct.ucs2_length;
                Address->number_info     = *AddressStruct.number_info | 0x80;
                Address->gsm_spec        = AddressStruct.gsm_spec;

                /* Return Pointer to address end */
                return (tOCT_UINT8*)(MessageBuffer+tmpLength+1);

            }
            else
            {
                free(Address->address);
                Address->address = NULL;
            }

        }
        else
        {
            /* Read original number amount */
            characters = *MessageBuffer;

            if (return_value == TRUE   && characters == *AddressStruct.ucs2_length )
            {
                Address->address_length  = *AddressStruct.ucs2_length;
                Address->number_info     = *AddressStruct.number_info | 0x80;
                Address->gsm_spec        = AddressStruct.gsm_spec;

                if ( (Address->number_info & SMS_GSM_ADDRESS_TYPE_MASK) == IPL_WM_GSM_TON_INTERNATIONAL)
                {
                    /* Increase length so that it include also internation mark */
                    Address->address_length++;

                    /* Create new correct size of buffer and store address including internation mark */
                    tmpString = malloc(( Address->address_length+1)*sizeof(tOCT_UINT16));
                    assert (tmpString != NULL);

                    *tmpString = L'+';
                    ucs2_strncpy((tmpString+1),Address->address,(Address->address_length-1));
                    tmpString[Address->address_length] = 0;

                    /* Remove old buffer and store new one */
                    free(Address->address);
                    Address->address = tmpString;
                    tmpString = NULL;
                }

                /* Return Pointer to address end */
                return (tOCT_UINT8*)(MessageBuffer+tmpLength+1);

            }
            else
            {
                free(Address->address);
                Address->address = NULL;
            }
        }
    }

    return NULL;
}

tOCT_UINT8* SMSLib_DecodeTimeField(const tOCT_UINT8* MessageBuffer, tSMSLib_Time* Time)
{
    /* Store Time stamp value (TP-SCTS, GSM 03.40) */

    /* get year from semi-octet data */

    Time->year    =  (tOCT_UINT8)((MessageBuffer[0] & 0x0f)*10 + MessageBuffer[0]/16);
    Time->month   =  (tOCT_UINT8)((MessageBuffer[1] & 0x0f)*10 + MessageBuffer[1]/16);
    Time->day     =  (tOCT_UINT8)((MessageBuffer[2] & 0x0f)*10 + MessageBuffer[2]/16);
    Time->hour    =  (tOCT_UINT8)((MessageBuffer[3] & 0x0f)*10 + MessageBuffer[3]/16);
    Time->minute  =  (tOCT_UINT8)((MessageBuffer[4] & 0x0f)*10 + MessageBuffer[4]/16);
    Time->second  =  (tOCT_UINT8)((MessageBuffer[5] & 0x0f)*10 + MessageBuffer[5]/16);

    /* Calculate timezone semi octet value */
    Time->time_zone = (tOCT_INT8)((MessageBuffer[6] & 0x07)*10+MessageBuffer[6]/16);

    /* if sign is negative */
    if(MessageBuffer[6] & 0x08)
    {
        /* change value to negative */
        Time->time_zone *= -1;
    }

    return (tOCT_UINT8*)&MessageBuffer[7];
}

void SMSLib_DecodeValidityPeriodField(tSMSLib_Message* Message, const tOCT_UINT8* MessageBuffer)
{
    tOCT_UINT8           tmpValidityformat     = 0;

    switch (Message->ValidityPeriodFormat)
    {
        case SMS_VALIDITY_PERIOD_ABSOLUTE:
        {
            /* Store Time stamp value (TP-SCTS, GSM 03.40) */
            /* get year from semi-octet data */
            (void)SMSLib_DecodeTimeField(MessageBuffer,&Message->ServiceCentreTime);
            break;
        }
        case SMS_VALIDITY_PERIOD_RELATIVE:
        {
            /* Store Time value to Validity period field and it must handled like TP-VP relative defines */
            Message->ValidityPeriod = *MessageBuffer;
            break;
        }
        default: /* SMS_VALIDITY_PERIOD_ENHANCED */
        {
            /* Read Enhanced format information to period field */
            Message->ValidityPeriod = *MessageBuffer;
            MessageBuffer++;

            tmpValidityformat = (tOCT_UINT8)(Message->ValidityPeriod & SMS_ENHANCE_FORMAT_MASK);

            switch (tmpValidityformat)
            {
                case SMS_ENHANCE_FORMAT_TIME:
                {
                    /* SMS_ENHANCE_FORMAT_TIME field is handled like normal time field but date info is ignored */
                    /* Fill dummy default values to year, month and day fields */
                    Message->ServiceCentreTime.year = 1;
                    Message->ServiceCentreTime.month = 1;
                    Message->ServiceCentreTime.day = 1;
                    Message->ServiceCentreTime.hour = (tOCT_UINT8)((MessageBuffer[0] & 0x0f)*10 + ((MessageBuffer[0] & 0xf0) >> 4));
                    Message->ServiceCentreTime.minute = (tOCT_UINT8)((MessageBuffer[1] & 0x0f)*10 + ((MessageBuffer[1] & 0xf0) >> 4));
                    Message->ServiceCentreTime.second = (tOCT_UINT8)((MessageBuffer[2] & 0x0f)*10 + ((MessageBuffer[2] & 0xf0) >> 4));
                }
                case SMS_ENHANCE_FORMAT_RELATIVE:
                case SMS_ENHANCE_FORMAT_SECOND:
                {
                    /* Store Time value to gmt time but it must handled like TP-VP relative defines */
                    Message->ServiceCentreTime.second = *MessageBuffer;
                }
            } /* Other format are ignored */
        }
    }
}

tOCT_UINT8 SMSLib_DecodeSubmitHeaders(tSMSLib_Message* Message, const tOCT_UINT8* MessageBuffer, tOCT_UINT32 MessageBufferLength, tOCT_UINT32* BytesConsumed)
{
    tOCT_UINT8  ReturnValue         = SMS_MSG_BUFFER_OVERRUN;
    tOCT_UINT8  validityPeriodLen   = 0;
    tOCT_UINT8* smsCursor           = NULL;
    
    *BytesConsumed   = 0;
    
    SMSLib_DecodeBitFieldValues(Message,*MessageBuffer);

    /* All bits are used so we don't need check unused bit values */
    (*BytesConsumed)++;
    MessageBuffer++;

    if (*BytesConsumed < MessageBufferLength)
    {
        Message->MessageReference = *MessageBuffer;
        (*BytesConsumed)++;
        MessageBuffer++;
        
        /* Parse gsm address to ucs2 format and store other address info */
        smsCursor = SMSLib_DecodeAddressField(MessageBuffer,(MessageBufferLength - *BytesConsumed),&Message->AddressValue,IPL_WM_GSM_23040);
    
        if (smsCursor)
        {
            *BytesConsumed = *BytesConsumed + (tOCT_UINT32)(smsCursor - MessageBuffer); 
            
            /* Calculate lenght of validity period header */
            if (Message->ValidityPeriodFormat == SMS_VALIDITY_PERIOD_RELATIVE)
            {
                validityPeriodLen = SMS_SUBMIT_RELATIVE_FORMAT_HEADER_LEN;
            }
            else if (Message->ValidityPeriodFormat == 0)
            {
                validityPeriodLen = 0;
            }
            else
            {
                validityPeriodLen = SMS_SUBMIT_OTHER_FORMAT_HEADER_LEN;
            }

            /* does buffer include all headers */
            if ((*BytesConsumed + validityPeriodLen + SMS_SUBMIT_STATIC_HEADER_LEN) <= MessageBufferLength)
            {
                Message->ProtocolIdentifier  = *smsCursor;
                smsCursor++;

                Message->DataCodingScheme    = *smsCursor;
                smsCursor++;

                /* It's not needed to decode validity period field if format is 0 */
                if (Message->ValidityPeriodFormat != 0)
                {
                    SMSLib_DecodeValidityPeriodField(Message,smsCursor);
                    smsCursor += validityPeriodLen;
                }
            
                /* Read user data len from end of validity period field */
                Message->UserDataLength = *smsCursor;

                *BytesConsumed += (validityPeriodLen+SMS_SUBMIT_STATIC_HEADER_LEN);
                ReturnValue = SMS_MSG_OK;
            }
        }
        else
        {
            ReturnValue = SMS_MSG_INVALID_ADDRESS;
        }
    }
    return ReturnValue;
}

tOCT_UINT8 SMSLib_IsElementIdValid(tOCT_UINT16 ElementId)
{
    /* Elementid is defined in 3GPP TS 23.040 Element Identifier table */
    if (((ElementId < SMS_ELEMENT_ID_RESERV_EMS_START) && (ElementId != SMS_ELEMENT_ID_RESERVED))             || \
        ((ElementId >= SMS_ELEMENT_ID_EMAIL_HEADER) && (ElementId < SMS_ELEMENT_ID_RESERV_FUTURE_START))      || \
        ((ElementId > SMS_ELEMENT_ID_RESERV_FUTURE_END) && (ElementId < SMS_ELEMENT_ID_RESERV_FUTURE2_START)) || \
        ((ElementId > SMS_ELEMENT_ID_RESERV_FUTURE2_END) && (ElementId < SMS_ELEMENT_ID_RESERV_FUTURE3_START)))
    {
        return TRUE;
    }

    return FALSE;
}

/*-------------------------------------------------------------------------*/
/* slList_FindRemove

    Functional Description:
        Return value:
        Element that is removed from the list.
        
        Description:
        Searches for and removes an element from the list. Note that it is not
        the element that is used as a "query example" that is removed from the
        list, but the first element that matches the query based on the result
        from the compare function.
        
        Example:
        ELEMENT search;
        search.key = 5;
        elem = (ELEMENT*)slList_FindRemove(&q, &search);

    Parameters:

        item - 
            Element used as "example" to find the element to be removed. The
            compare function will be used to find the element. If no compare
            function is supplied in the Init function, then the addresses of
            the elements will be compared.

*/

void* slList_FindRemove(slList* self, void * item)
{
    register int offs = self->linkOffset;
    register void* pCurrent;  /* Element to be checked */
    void* pPrevious;          /* Points to the element before pCurrent */ 

    if (self->last)
    {
        /* Make pCurrent point to first element */
        pCurrent = NEXT(self->last);
        pPrevious = self->last;
    
        do
        {
            /* Check if we should remove this element */
            if (self->compare(pCurrent, item) == 0)
            {
                /* Check if we remove only element */
                if (pPrevious == pCurrent)
                {
                    self->last = NULL;
                }
                else
                {
                    /* Check if removing the last element */
                    if (pCurrent == self->last)
                    {
                        self->last = pPrevious;
                    }
    
                    NEXT(pPrevious) = NEXT(pCurrent);
                }
                    
                self->nElement--;
                /* No need to proceed */
                return pCurrent;
            }

            pPrevious = pCurrent;
            pCurrent = NEXT(pCurrent);

        } while (pPrevious != self->last);
    }
    return NULL;
}

tOCT_UINT8 SMSLib_DecodeInformationHeaders(slList* HeaderInfoList, const tOCT_UINT8* MessageBuffer, tOCT_UINT32 MessageBufferLength, tOCT_UINT32* BytesConsumed)
{
    tSMSLib_InformElement   tmpElement;
    tOCT_UINT32             ElementLen          = 0;
    tOCT_UINT32             InfoHeaderLen       = 0;
    tOCT_UINT32             tmpBytesConsumed    = 0;

    tSMSLib_InformElement*  Element             = NULL;

    tOCT_UINT8              ReturnValue         = SMS_MSG_PARSE_ERROR;

    /* Information header Length must exist */
    if (MessageBufferLength > 0 )
    {
        /* get Information header Length from second byte */
        InfoHeaderLen = *MessageBuffer;
        tmpBytesConsumed = 1;

        /* least one element must exist and information headers can't be longer than whole buffer */
        if( (InfoHeaderLen < MessageBufferLength) && (InfoHeaderLen >= 2) )
        {
            /* Add elements until whole information data is handled */
            while( (tmpBytesConsumed-1) < InfoHeaderLen)
            {
                /* Store element id to temporary element */
                tmpElement.ElementId = MessageBuffer[tmpBytesConsumed];
                tmpBytesConsumed++;

                /* find is this id valid */
                if(SMSLib_IsElementIdValid(tmpElement.ElementId))
                {
                    /* Get Element Length */
                    ElementLen = MessageBuffer[tmpBytesConsumed];
                    tmpBytesConsumed++;

                    /* Check is element len zero And this element type doesn't allow zero length */
                    if (!ElementLen &&
                        (((tmpElement.ElementId < SMS_TOOLKIT_SECURITY_HEADER_START_ID) ||
                         (tmpElement.ElementId > SMS_TOOLKIT_SECURITY_HEADER_END_ID) ) &&
                         (SMS_EXTENDED_OBJECT_DATA_REQUEST_ID != tmpElement.ElementId)) )
                    {
                        /* stop scannin because information header is corrupted */
                        break;
                    }

                    /* Check does sum of previous elements + new element is bigger than whole info header */
                    if ((ElementLen + (tmpBytesConsumed-1)) <= InfoHeaderLen)
                    {
                        /* check do we already have this element */
                        Element = slList_FindRemove(HeaderInfoList,&tmpElement);

                        /* If element found destruct it */
                        if(Element)
                        {
                            SMSLib_ListDestructor(Element);
                            Element = NULL;
                        }

                        /* create new element and insert element datas */
                        Element = malloc(sizeof(tSMSLib_InformElement));
                        assert ( Element != NULL );
                        memset( Element, 0, sizeof(tSMSLib_InformElement) );

                        Element->ElementId = tmpElement.ElementId;
                        Element->ElementSize = (tOCT_UINT8)ElementLen;

                        /* Check can we store value to uint32 value or do we need bigger buffer */
                        if (ElementLen <= sizeof(tOCT_UINT32))
                        {
                            memcpy(&Element->IntegerValue,&MessageBuffer[tmpBytesConsumed],ElementLen);
                        }
                        else
                        {
                            Element->value = malloc(ElementLen);
                            assert (( Element->value ) != NULL );
                            memcpy(Element->value,&MessageBuffer[tmpBytesConsumed],ElementLen);
                        }

                        /* store element to list and increase consume amount */
                        slList_InsertLast(HeaderInfoList,(void*)Element);

                        tmpBytesConsumed += ElementLen;
                        Element = NULL;
                    }
                    else /* stop scannin because information header is corrupted */
                    {
                        break;
                    }


                }
                else /* element is not valid -> skip unknown element */
                {
                    /* skip amount of Length info */
                    tmpBytesConsumed += MessageBuffer[tmpBytesConsumed]+1;
                }


            } /* while information data exist */

        } /* if information header Length is correct */

        /* Return handled data amount to caller */
        *BytesConsumed = tmpBytesConsumed;

        /* check is all data information data handled */
        if (tmpBytesConsumed-1 == InfoHeaderLen)
        {
            ReturnValue = SMS_MSG_OK;
        }

    }

    return ReturnValue;
}

tOCT_UINT8 SMSLib_CheckDataFormat(tOCT_UINT8 DcsValue)
{
    tOCT_UINT8 ReturnValue = 0;

    switch (DcsValue & SMS_DATA_CODING_GROUP_HALF_MASK)
    {
        case SMS_DATA_CODING_GROUP_GENERAL:
        case SMS_DATA_CODING_GROUP_AUT_DEL:
        {
            /* Normal Detection */
            if ((DcsValue & SMS_DATA_CODING_MASK) == SMS_DATA_CODING_UCS2_VALUE)
            {
                ReturnValue = SMS_DATA_CODING_UCS2_VALUE;
            }
            else if ((DcsValue & SMS_DATA_CODING_MASK) == SMS_DATA_CODING_8BIT_VALUE)
            {
                ReturnValue = SMS_DATA_CODING_8BIT_VALUE;
            }
            else /* 7-bit format */
            {
                ReturnValue = SMS_DATA_CODING_7BIT_VALUE;              
            }
            break;
        }
        case SMS_DATA_CODING_GROUP_RESERV:
        {
            /* Allways 7bit user data used */
            ReturnValue = SMS_DATA_CODING_7BIT_VALUE;
            break;
        }
        default:
        {
            /* Is group SMS_DATA_CODING_GROUP_DISCARD or SMS_DATA_CODING_GROUP_STORE_7BIT */
            if ((DcsValue & SMS_DATA_CODING_GROUP_MASK) <= SMS_DATA_CODING_GROUP_STORE_7BIT)
            {
                ReturnValue = SMS_DATA_CODING_7BIT_VALUE;
            }
            else if ((DcsValue & SMS_DATA_CODING_GROUP_MASK) == SMS_DATA_CODING_GROUP_STORE_UCS2)
            {
                ReturnValue = SMS_DATA_CODING_UCS2_VALUE;
            }
            else if (DcsValue & 0x04) /* SMS_DATA_CODING_GROUP_OTHER -> bit2 indicate if 8bit format used */
            {
                ReturnValue = SMS_DATA_CODING_8BIT_VALUE;
            }
            else
            {
                ReturnValue = SMS_DATA_CODING_7BIT_VALUE;
            }
        }

    }
    
    return ReturnValue;
}

/* ======================================================================
 * FUNCTION:  SMSLib_DecodeUserData
 *
 * PURPOSE:  Decode user data to UserData field and if coding is 7-bit it is converted to 8-bit format.
 *           8-bit coding doesn't need any conversion and then it is same format as in binary.
 *           Ucs-2 format text is converted to phone endian. Data coding scheme are not changed even
 *           7-bit format is converted to readable 8-bit format. When DCS information is always the
 *           original format then decoded message can be encoded back to original format.
 *
 * PARAMETERS:
 *  Message                         - Pointer to sms message
 *  MessageCursor                   - Pointer to userdata after informationheaders
 *  MessageBufferLenght             - Lenght of buffer
 *  BytesConsumed                   - Return value for caller to indicate readed amount of data
 *  DataCodingScheme                - Inform which unpack we have to use
 *  InfoHeaderLen                   - Indicate does user data include information header and how long it is
 *
 * RETURN VALUES:
 *    SMS_MSG_OK
 *    SMS_MSG_BUFFER_OVERRUN
 * ====================================================================== */
tOCT_UINT8 SMSLib_DecodeUserData(tSMSLib_Message* Message,
                            const tOCT_UINT8* MessageCursor,
                            tOCT_UINT32  MessageBufferLength,
                            tOCT_UINT32* BytesConsumed,
                            tOCT_UINT32   InfoHeaderLen)
{
    tOCT_UINT8**         UserDataPointer     = &Message->UserData;
    tOCT_UINT8*          unpacked_data       = NULL;
    tOCT_UINT8*          tmpCursor           = NULL;
    tOCT_UINT32          ConvertDataLen      = 0;
    tOCT_UINT32          ConvertInfoLen      = 0;
    tOCT_UINT8           tmpDCS              = 0;
    tOCT_UINT8           retval              = SMS_MSG_OK;


    /* If buffer is over size use maximum value */
    if (MessageBufferLength > SMS_MAX_USER_DATA_LEN_BYTES)
    {
        MessageBufferLength = SMS_MAX_USER_DATA_LEN_BYTES;
    }

    /* Check What coding we need to use depeding dcs group */
    tmpDCS = SMSLib_CheckDataFormat(Message->DataCodingScheme);

    /* Check does we have correct user data len */
    if (tmpDCS == SMS_DATA_CODING_7BIT_VALUE)
    {
        /* calculate buffer size with bytes */
        ConvertDataLen = ((Message->UserDataLength+1)*7/8);
    }
    else /* User data len is in bytes */
    {
        ConvertDataLen = Message->UserDataLength;
    }

    /* Check do we have correct UDL field value if too big use buffer length */
    if (ConvertDataLen > MessageBufferLength)
    {
        ConvertDataLen = MessageBufferLength;
        /* Calculate new data length preventing problems in ipl_wm_gsm_lib_sms_unpack_message conversion */
        if (tmpDCS == SMS_DATA_CODING_7BIT_VALUE)
        {
            Message->UserDataLength = (tOCT_UINT8)(ConvertDataLen*8/7);
        }
        /* Return failure after possible valid data is readed */
        retval = SMS_MSG_BUFFER_OVERRUN;
    }

    /* If userdata len is not zero or equal to infoheader length */
    if ( ConvertDataLen && (ConvertDataLen > InfoHeaderLen) )
    {
        switch (tmpDCS)
        {
            case SMS_DATA_CODING_7BIT_VALUE:
            {
                /* Calculate amount of bytes after conversion and crete buffer */
                ConvertDataLen = Message->UserDataLength;
                unpacked_data = malloc(ConvertDataLen);
                assert( unpacked_data != NULL );

                /* convert whole data including info headers */
                ipl_wm_gsm_lib_sms_unpack_message(unpacked_data,(tOCT_UINT8*)MessageCursor,(tOCT_UINT16)ConvertDataLen);

                if (InfoHeaderLen)
                {
                    /* calculate how many 7-bit char can convert from info header value */
                    ConvertInfoLen = (((InfoHeaderLen)*8)/7);

                    /* Do we need fillers after info data */
                    if ((InfoHeaderLen*8)%7)
                    {
                        /* Increase info header septet length */
                        ConvertInfoLen++;
                    }
                }

                /* calculate converted user data Length */
                ConvertDataLen = (ConvertDataLen-ConvertInfoLen);

                /* Check do we have empty message */
                if (ConvertDataLen)
                {
                    /* allocate userdata buffer and copy only user data to buffer */
                    *UserDataPointer = malloc((ConvertDataLen+1));
                    assert ( ( *UserDataPointer )!= NULL );

                    memcpy(*UserDataPointer, &unpacked_data[ConvertInfoLen],ConvertDataLen);

                    /* Calculate how many bytes whole user data consume and decrease info header bytes */
                    *BytesConsumed = (ConvertDataLen+ConvertInfoLen+1)*7/8 - InfoHeaderLen;

                    (*UserDataPointer)[ConvertDataLen] = 0;
                }
                else
                {
                    /* Add consume amount if filler is needed and user data is not included */
                    *BytesConsumed = 1;
                }

                /* Store convert data amount to message */
                Message->UserDataLength = (tOCT_UINT8)ConvertDataLen;

                /* deallocate temporary conversion buffer */
                free(unpacked_data);
                unpacked_data = NULL;

                break;
            }
            case SMS_DATA_CODING_8BIT_VALUE:
            {
                /* Information headers is removed from infoConverDatalen length info */
                ConvertDataLen = ConvertDataLen-InfoHeaderLen;
                tmpCursor = (tOCT_UINT8*)(MessageCursor+InfoHeaderLen);


                /* Create buffer and copy value for it */
                *UserDataPointer = malloc((ConvertDataLen+1));
                assert (( *UserDataPointer )!= NULL );

                memcpy(*UserDataPointer,tmpCursor,ConvertDataLen);
                (*UserDataPointer)[ConvertDataLen] = 0;

                *BytesConsumed = ConvertDataLen;

                /* Store convert data amount to message  */
                Message->UserDataLength = (tOCT_UINT8)ConvertDataLen;

                break;
            }
            default: /* SMS_DATA_CODING_UCS2_VALUE */
            {
                /* Information headers is removed from infoConverDatalen length info */
                ConvertDataLen = ConvertDataLen-InfoHeaderLen;
                tmpCursor = (tOCT_UINT8*)(MessageCursor+InfoHeaderLen);

                /* data is dividable with two */
                if (ConvertDataLen%2)
                {
                    /* Remove illegal byte from conversion */
                    ConvertDataLen--;
                }

                /* create new buffer copy ucs2 string to platform endian */
                unpacked_data = malloc(ConvertDataLen);
                assert ( unpacked_data != NULL );

                *UserDataPointer = malloc((ConvertDataLen+2));
                assert (( *UserDataPointer ) != NULL );

                /* Copy data first to new buffer and then convert endian -> prevent alignment problems */
                memcpy(unpacked_data,tmpCursor,ConvertDataLen);

                ucs2_strncpy_endian((tOCT_UINT16*)*UserDataPointer, (tOCT_UINT16*)unpacked_data, (ConvertDataLen/2), UCS2_FROM_BIG_TO_PLATFORM_ENDIAN);

                /* Remove temporary buffer */
                free(unpacked_data);
                unpacked_data = NULL;

                /* make sure that null is included */
                ((tOCT_UINT16*)*UserDataPointer)[ConvertDataLen/2] = 0;

                *BytesConsumed = ConvertDataLen;

                /* Store convert data amount to message  */
                Message->UserDataLength = (tOCT_UINT8)ConvertDataLen;

            }
        }
    } /* If userdata len is not zero or equal to infoheader length */
    else
    {
        /* Set user data length to zero beacause we only have info header */
        Message->UserDataLength = 0;
        /* Data is not consumed */
        *BytesConsumed = 0;
    }
    return retval;
}


tOCT_UINT8 decodeSmsTpdu(const tOCT_UINT8* encodedMessage, tOCT_UINT32 length, tSMSLib_Message** createdMessage)
{
    tOCT_UINT8               ReturnValue                 = SMS_MSG_INVALID_PARAM;
    tOCT_UINT32              ConsumedDataLength          = 0;
    tOCT_UINT32              ConsumedUserDataLength      = 0;
    tOCT_UINT32              tmpUserDatalen              = 0;
    tOCT_UINT32              tmpInfoheaderLen            = 0;
    const tOCT_UINT8*        ParsingCursor               = NULL;

    if (encodedMessage && length)
    {
        /* create sms message struct */
        *createdMessage = SMSLib_Message_Create();
        
        /* store buffer to parsing cursor */
        ParsingCursor = encodedMessage;

        if((*encodedMessage & SMS_MESSAGE_TYPE_MASK) == 0x01) // SMS-SUBMIT
        {   
            /* Set Message type value to correspond indentified message */
            (*createdMessage)->MessageTypeIndicator = SMS_SUBMIT;
            //(*createdMessage)->MessageSubType       = MessageSubType;
            
            ReturnValue = SMSLib_DecodeSubmitHeaders(*createdMessage, ParsingCursor, length, &ConsumedDataLength);
        }
        
        /* Move cursor begin of user data and decrease buffer length */
        ParsingCursor += ConsumedDataLength;
        tmpUserDatalen = length - ConsumedDataLength;

        /* check do we have user data and is status still ok */
        if (ReturnValue == SMS_MSG_OK && (*createdMessage)->UserDataLength)
        {
            if ((*createdMessage)->UserDataHeaderIndicator)
            {   

                /* We have info headers so parse them and return consumed data amount */
                ReturnValue = SMSLib_DecodeInformationHeaders((*createdMessage)->InfoElementlist,ParsingCursor,tmpUserDatalen, &ConsumedUserDataLength);
                ConsumedDataLength += ConsumedUserDataLength;
            }

            if (ReturnValue == SMS_MSG_OK)
            {
                /* Store possible info header len */
                if ((*createdMessage)->UserDataHeaderIndicator)
                {
                    /* Read Info header len and add len field also */
                    tmpInfoheaderLen  = *ParsingCursor+1;
                    (*createdMessage)->UDHData = (tOCT_UINT8*)ParsingCursor;
                }
                else
                {
                (*createdMessage)->UDHData = NULL;
                }
                /* Whole user data is delivered to user data parser to make possible handle 7-bit alignment */
                ReturnValue = SMSLib_DecodeUserData(*createdMessage,ParsingCursor,tmpUserDatalen,&ConsumedUserDataLength,tmpInfoheaderLen);

                ConsumedDataLength += ConsumedUserDataLength;
            }
            else    /* Info header parsing fail but buffer may include still user data */
            {
                /* Make sure that user data is not readed because is not parsed at all */
                (*createdMessage)->UserDataLength = 0;
            }

        }
        /* Is some data left but coding is still ok */
        if ( (ConsumedDataLength != length) && (ReturnValue == SMS_MSG_OK) )
        {
            ReturnValue = SMS_MSG_PARSE_ERROR;
        }

    }

    return ReturnValue;
}


tOCT_UINT8 modem_char_hex_to_byte( const char *str )           /* In:  Hex string, length is 2 */
{
    tOCT_UINT32 i;
    tOCT_UINT8 number = 0;

    for (i = 0; i < 2; i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            number += str[i] - '0';
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            number += str[i] - 'A' + 10;
        }
        else if (str[i] >= 'a' && str[i] <= 'f')
        {
            number += str[i] - 'a' + 10;
        }
        if (i == 0)
        {
            number <<= 4;
        }
    }

    return (number);
}

void modem_char_byte_to_hex( tOCT_UINT8 number, char *str )    /* Out: Hex string, length is 2               */
{
    tOCT_UINT32 i;
    tOCT_UINT8 digit;

    for (i = 0; i < 2; i++)
    {
        digit = ((number << (i * 4)) / 16) & 0x0F;

        if (digit <= 9)
        {
            str[i] = digit + '0';
        }
        else
        {
            str[i] = digit + 'A' - 10;
        }
    }
}

static void modem_char_convert_from_utf_8( tOCT_UINT8 char_set_out, const char  *buff_in, char  *buff_out, tOCT_UINT16 in_buff_len, tOCT_UINT16 *out_buff_len )
{
    tOCT_UINT32 index=0;
    tOCT_UINT32 input=0;

    *out_buff_len = 0;
    switch (char_set_out)
    {
       case MODEM_CHAR_UCS2_PLAIN:
          for (;in_buff_len>0;)
          {
              input = 0;
              *buff_out = 0;
              if ((buff_in[index] & 0xF0) == 0xF0) 
              {
                /*Read four bytes to decode this number*/
                /* not UCS2 supported character */
		          in_buff_len -= 4;
		          continue;
              }
              else if ((buff_in[index] & 0xE0) == 0xE0)
              {
                input = input | buff_in[index];
                input = input << 8;
                input = input | buff_in[index+1];
                input = input << 8;
                input = input | buff_in[index+2];
                if(input < 0xE0A080 || input > 0xEFBFBF)
                {
                  index += 3;
                  in_buff_len -= 3;
                  continue;
                }
                input = 0;
                buff_out[1] = 0;
                buff_out[1] = buff_in[index+2] & 0x3F;
                input = buff_in[index+1]  & 0x03 ;
                input = input << 6;
                buff_out[1] = buff_out[1] |  input;
                input = 0;
                input = buff_in[index+1] & 0x3C;
                input = input >> 2;
                buff_out[0] = buff_out[0] | input;
                input = 0;
                input = buff_in[index] & 0x0F;
                input = input << 4;
                buff_out[0] = buff_out[0] |input;
                in_buff_len -= 3;
                index += 3;
              } 
              else if ((buff_in[index] & 0xC0) == 0xC0)
              {
                input = input | buff_in[index];
                input = input << 8;
                input = input | buff_in[index+1];
                if(input < 0xC280 || input > 0xDFBF)
                {
                  index += 2;
                  in_buff_len -= 2;
                  continue;
                }
                input = 0;
                buff_out[1] = 0;
                buff_out[1] = buff_in[index+1] & 0x3F;
                input = buff_in[index]  & 0x03 ;
                input = input << 6;
                buff_out[1] = buff_out[1] |  input;   
                input = 0;
                input = buff_in[index] & 0x1C;
                input = input >> 2;
                buff_out[0] = buff_out[0] | input;                 
                in_buff_len -= 2;
                index+=2;
              }
              else
              { 
                *buff_out = 0x00;
                *(buff_out+1) = buff_in[index++];
                in_buff_len--;
              }
              buff_out += 2;  
              *out_buff_len += 2;
           }
           break;
        default:
            logPrint(LOG_ERR, "modem_char_convert_from_utf_8(): unsupported char_set_out(%d)", char_set_out );
    }

}

static void modem_char_convert_to_utf_8( tOCT_UINT8 char_set_in, const char  *buff_in, char  *buff_out, tOCT_UINT16 in_buff_len, tOCT_UINT16 *out_buff_len )
{
    tOCT_UINT16 i,index=0;
    tOCT_UINT16 input=0,temp=0,j=0;
    char* temp_out = NULL;

    *out_buff_len = 0;
    switch (char_set_in)
    {
        case MODEM_CHAR_UCS2_PLAIN:
            temp_out = buff_out;
            for(;in_buff_len > 0; in_buff_len -= 2,index+=2)
            {
                input = 0;
                input |= ((tOCT_UINT8 *)buff_in)[index];
                input = input << 8;
                input |= ((tOCT_UINT8 *)buff_in)[index+1];

                *temp_out = 0;
                if(input <= 0x7f)
                {
                    *temp_out  = *temp_out | MODEM_CHAR_UTF_8_CONV_1; /* 0xxxxxxx*/
                    *temp_out = *temp_out | input;
                    *out_buff_len += 1;
                }
                else if(input >= 0x80 && input <= 0x7FF)
                {
                    *temp_out = *temp_out | MODEM_CHAR_UTF_8_CONV_2;
                    /* 110xxxxx 10xxxxxx*/
                    *out_buff_len += 2;
                    for (i=0; i < (2*8);i++)
                    {
                        /* these three steps gives bits one by one always*/
                        temp = input;
                        temp = temp >> i;
                        temp = temp & 1;

                    /* this gives the bit at its original position but with other bits as zero */
                        temp = temp << i;
                        if ( i < 6)
                        {
                            *temp_out = *temp_out | temp;
                        }
                        else if (i >= 6)
                        {
                            temp = temp >> 6;
                            *temp_out = *temp_out | temp;
                        }
                        if ((i+1) == 6)
                        {
                            temp_out += 1;
                            *temp_out = 0;
                            *temp_out = *temp_out | MODEM_CHAR_UTF_8_CONV_3;
                        }
                    }
                    /* Bytes are stored in reverse order.. Rearrange them */
                    j = buff_out[*out_buff_len-1];
                    buff_out[*out_buff_len-1] = buff_out[*out_buff_len-2];
                    buff_out[*out_buff_len-2] = j;
                }
                else if(input >= 0x800 && input <= 0xFFFF)
                {
                    /* 1110xxxx 10xxxxxx 10xxxxxx */
                    *temp_out = *temp_out | MODEM_CHAR_UTF_8_CONV_2;
                    *out_buff_len += 3;
                    for (i=0; i < (2*8);i++)
                    {
                        /* these three steps gives bits one by one always*/
                        temp = input;
                        temp = temp >> i;
                        temp = temp & 1;

                       /* this gives the bit at its original position but with other bits as zero */
                        temp = temp << i;

                        if ( i < 6)
                        {
                            *temp_out = *temp_out | temp;
                        }
                        else if ((i >= 6) && ( i < 12 ))
                        {
                            temp = temp >> 6;
                            *temp_out = *temp_out | temp;
                        }
                        else if (i >= 12)
                        {
                            temp = temp >> 12;
                            *temp_out = *temp_out | temp;
                        }
                        if ((i+1)==6||(i+1)==12)
                        {
                            temp_out += 1;
                            *temp_out = 0;
                            if ((i+1) == 6)
                            {
                                *temp_out = *temp_out | MODEM_CHAR_UTF_8_CONV_2;
                            }
                            else
                            {
                                *temp_out = *temp_out | MODEM_CHAR_UTF_8_CONV_4;
                            }
                        }
                    }
                    /* Bytes are stored in reverse order.. Rearrange them */
                    j = buff_out[*out_buff_len-1];
                    buff_out[*out_buff_len-1] =
                        buff_out[*out_buff_len-3];
                    buff_out[*out_buff_len-3] = j;
                }
                else
                {
                    return;
                }
                temp_out += 1;
            }
            break;
         default:
             logPrint(LOG_ERR, "modem_char_convert_to_utf_8(): unsupported char_set_in(%d)", char_set_in);
             break;
    }
}

static void modem_char_convert_to_ucs2(
    tOCT_UINT8  char_set_in,        /* In:   In buffer character set     */
    const char  *buff_in,           /* In:   Buffer to be converted      */
    char  *buff_out,                /* In:   Converted buffer            */
    tOCT_UINT16 in_buff_len,        /* In:   Length of incoming buffer   */
    tOCT_UINT16 *out_buff_len )     /* Out:  Length of outgoing buffer   */
{

    tOCT_UINT32 i;                  /* Loop counter                         */
    tOCT_UINT8 mask = 0;            /* GSM extended char mask               */
    tOCT_UINT8 mask2 = 0;           /* GSM extended char mask 2             */

    *out_buff_len = 0;

    switch (char_set_in)
    {
        case MODEM_CHAR_GSM:
            mask2 = 0x80;
            /* Flow through */
        case MODEM_CHAR_PCCP437:
            /* Flow through */
        case MODEM_CHAR_PCDN:
            for ( ; in_buff_len > 0; in_buff_len--, buff_in++)
            {
                if (MODEM_CHAR_NEEDS_CONVERSION( *buff_in | mask ))
                {
                    if (char_set_in == MODEM_CHAR_GSM && *buff_in == 0x1B)
                    {               /* GSM extended character */
                        mask = 0x80;
                        continue;
                    }
                    for (i = 0; i< MODEM_CHARS_IN_TBL && (*(tOCT_UINT8*)buff_in | mask) != modem_char_conversion_table[i][char_set_in]; i++)
                    {
                        /* Do nothing */
                    }
                    if ((i < MODEM_CHARS_IN_TBL) && !(mask2 & *(tOCT_UINT8*)buff_in))
                    {
                        *buff_out = modem_char_conversion_table[i][MODEM_CHAR_UCS2_0707-1];
                        *(buff_out + 1) = modem_char_conversion_table[i][MODEM_CHAR_UCS2_0707];
                    }
                    else    /* Not found in conversion table */
                    {
                        *buff_out = 0x00;
                        *(buff_out + 1) = SPC;
                    }
                    mask = 0x00;
                }
                else
                {
                    *buff_out = 0x00;
                    *(buff_out + 1) = *buff_in;
                }
                buff_out += 2;
                (*out_buff_len) += 2;
            }
            break;
        case MODEM_CHAR_IRA:
            /* Flow through */
        case MODEM_CHAR_8859_1:
            *out_buff_len = in_buff_len * 2;
            for ( ; in_buff_len > 0; in_buff_len--, buff_in++)
            {
                *buff_out = 0x00;
                if (char_set_in == MODEM_CHAR_IRA && *buff_in & 0x80)
                {
                    *(buff_out + 1) = SPC;
                }
                else
                {
                    *(buff_out + 1) = *buff_in;
                }
                buff_out += 2;
            }
            break;        
        case MODEM_CHAR_UTF_8:
           modem_char_convert_from_utf_8(MODEM_CHAR_UCS2_PLAIN, buff_in, buff_out, in_buff_len, out_buff_len );
          break;
	    
        default:
            logPrint(LOG_ERR, "modem_char_convert_to_ucs2(): unsupported char_set_in(%d)", char_set_in );
    }
}

static void modem_char_convert_from_ucs2(
    tOCT_UINT8  char_set_out,       /* In:   Out buffer character set    */
    const char  *buff_in,           /* In:   Buffer to be converted      */
    char  *buff_out,                /* In:   Converted buffer            */
    tOCT_UINT16 in_buff_len,        /* In:   Length of incoming buffer   */
    tOCT_UINT16 *out_buff_len )     /* Out:  Length of outgoing buffer   */
{

    tOCT_UINT32 i;

    *out_buff_len = 0;

    switch (char_set_out)
        {
        case MODEM_CHAR_GSM:
            /* Flow through */
        case MODEM_CHAR_PCCP437:
            /* Flow through */
        case MODEM_CHAR_PCDN:
            for ( ; in_buff_len > 0; in_buff_len -= 2)
            {
                if (*buff_in != 0 || MODEM_CHAR_NEEDS_CONVERSION( *(buff_in + 1) ))
                {
                    for (i = 0; i < MODEM_CHARS_IN_TBL && ((tOCT_UINT8)*buff_in != modem_char_conversion_table[i][MODEM_CHAR_UCS2_0707-1] ||
                         (tOCT_UINT8)*(buff_in + 1) != modem_char_conversion_table[i][MODEM_CHAR_UCS2_0707]); i++)
                    {
                        /* Do nothing */
                    }
                    if (i < MODEM_CHARS_IN_TBL)
                    {
                        *buff_out = modem_char_conversion_table[i][char_set_out];
                        if (char_set_out == MODEM_CHAR_GSM && *buff_out & 0x80)
                        {
                            /* GSM extended char (0x1BXX) */
                            *(buff_out + 1) = *buff_out & 0x7F;
                            *buff_out++ = 0x1B;
                            (*out_buff_len)++;
                        }
                    }
                    else    /* Not found in conversion table */
                    {
                        *buff_out = SPC;
                    }
                }
                else
                {
                    *buff_out = *(buff_in + 1);
                }
                buff_in += 2;
                buff_out++;
                (*out_buff_len)++;
            }
            break;
        case MODEM_CHAR_IRA:
            /* Flow through */
        case MODEM_CHAR_8859_1:
            *out_buff_len = in_buff_len / 2;
            for ( ; in_buff_len > 0; in_buff_len -= 2 )
            {
                if (*buff_in == 0x00)
                {
                    if (char_set_out == MODEM_CHAR_IRA && *(buff_in + 1) & 0x80)
                    {
                        *buff_out = SPC;
                    }
                    else
                    {
                        *buff_out = *(buff_in + 1);
                    }
                }
                else
                {
                    *buff_out = SPC;
                }
                buff_in += 2;
                buff_out++;
            }
            break;    
	case MODEM_CHAR_UTF_8:
           modem_char_convert_to_utf_8( MODEM_CHAR_UCS2_PLAIN,buff_in, buff_out, in_buff_len, out_buff_len );
          break;
        default:
            logPrint(LOG_ERR, "modem_char_convert_from_ucs2(): unsupported char_set_out(%d)", char_set_out);
    }
}


char* modem_char_buffer_convert(
    tOCT_UINT8  char_set_in,             /* In:   In buffer character set     */
    tOCT_UINT8  char_set_out,            /* In:   Out buffer character set    */
    const char  *buff_in,                /* In:   Buffer to be converted      */
    char  *buff_out,                     /* In:   Converted buffer            */
    tOCT_UINT16 in_buff_len,             /* In:   Length of incoming buffer   */
    tOCT_UINT16* out_buff_len )          /* Out:  Length of outgoing buffer   */
{

/*  Functional Description

        Convert character buffer having a character set to another character
        set. For the description of the conversion see chapter 6.1. Supported
        character sets are UCS2_0707, UCS2_PLAIN, GSM, PCCP437 PCDN, IRA,
        8859-Latin-1 and HEX.

        If given buff_in and buff_out are the same buffer, it is guaranteed
        that output is not accidentally written over input before conversion
        is done completely. (For example when converting from IRA into
        Unicode on same buffer.)

        Both buffer lengths (in_buff_len & out_buff_len) are always given
        in amount of bytes. So IRA character's length is 1, UCS2_PLAIN
        character's length is 2, UCS2_0707 character's length is 4 etc. Note
        that GSM extended characters are two bytes long, but normal GSM
        characters are one byte long!

        Conversions to/from HEX-charset is done 'blind'. This means that no
        assumptions of the opposite character set (in/out) are done or utilized.
        This means that conversion is done character by character. For example:
        UCS2_PLAIN: 0x0012 <=> HEX: "12" and UCS2_PLAIN: 0x1234 <=> HEX: "20".

        GSM extended character set is supported and also used every time.

        There are two Unicode character sets supported by this function,
        the UCS2 specified by 3GPP TS 27.007 (UCS2_0707) and normal Unicode
        (UCS2_PLAIN). For example character 'A' is string "0041" in UCS2_0707
        and number 0x0041 in UCS2_PLAIN.

        Please take into account, that usage of end of string character in C
        ('\0' or NUL) is a risk when using this function. This function does
        not use the NUL character: it is not detected by this function, and
        it is not written by this function. Note also that in GSM character
        set the character number 0x00 is '@' (at sign)!

    Return Values
        Pointer to converted buffer.
-------------------------------------------------------------------------------
*/
    char *tmp = NULL;               /* Temporary buffer         */
    tOCT_INT32 i;                        /* Loop counter             */

    
    if (( buff_in == NULL ) || ( buff_out == NULL))
    {
        logPrint(LOG_ERR, "modem_char_buffer_convert() in/out buffer = NULL");
        return (NULL);
    }

    if (out_buff_len == 0x00)
    {
        logPrint(LOG_ERR, "modem_char_buffer_convert() out buffer length = 0");
        return (NULL);
    }

    if(!(
        char_set_in == MODEM_CHAR_UCS2_PLAIN ||
        char_set_in == MODEM_CHAR_UCS2_0707  ||
        char_set_in == MODEM_CHAR_PCCP437 ||
        char_set_in == MODEM_CHAR_PCDN     ||
        char_set_in == MODEM_CHAR_IRA     ||
        char_set_in == MODEM_CHAR_8859_1   ||
        char_set_in == MODEM_CHAR_HEX     ||
        char_set_in == MODEM_CHAR_GSM      ||
        char_set_out == MODEM_CHAR_UCS2_PLAIN ||
        char_set_out == MODEM_CHAR_UCS2_0707  ||
        char_set_out == MODEM_CHAR_PCCP437 ||
        char_set_out == MODEM_CHAR_PCDN   ||
        char_set_out == MODEM_CHAR_IRA     ||
        char_set_out == MODEM_CHAR_8859_1 ||
        char_set_out == MODEM_CHAR_HEX     ||
        char_set_out == MODEM_CHAR_GSM ))
     {
         logPrint(LOG_ERR, "modem_char_buffer_convert(): char_set_in(%d) to char_set_out(%d) conversion unsupported", char_set_in, char_set_out);
         return (NULL);
     }
     

    /* Buffer copy in case in & out character sets are equal: */
    if (char_set_in == char_set_out)
    {
        *out_buff_len = in_buff_len;

        /* Copy the buffer if in & out -buffers are not the same buffer: */
        if (buff_in != buff_out)
        {
            memcpy( buff_out, buff_in, in_buff_len );
        }
        return (buff_out);
    }

    /* From HEX-coding to UCS2_PLAIN: */
    if (char_set_in == MODEM_CHAR_HEX && char_set_out == MODEM_CHAR_UCS2_PLAIN)
    {
        *out_buff_len = in_buff_len;
        for (i = 0; i < in_buff_len; i += 2)
        {
            buff_out[i + 1] = modem_char_hex_to_byte( buff_in + i );
            buff_out[i] = 0;            /* Zero padding */
        }
        return (buff_out);
    }

    /* From HEX-coding to UCS2_0707: */
    if (char_set_in == MODEM_CHAR_HEX && char_set_out == MODEM_CHAR_UCS2_0707)
    {
        /* Protect the incoming buffer from corruption when same buffer     */
        /* is used for input and output:                                    */
        if (buff_in == buff_out)
        {
            tmp = malloc( in_buff_len );
            assert ( tmp != NULL);

            memcpy( tmp, buff_in, in_buff_len );
            buff_in = tmp;
        }

        *out_buff_len = (in_buff_len / 2) * 4;
        for (i = 0; i < in_buff_len / 2; i++)
        {
            buff_out[i * 4] = '0';
            buff_out[i * 4 + 1] = '0';
            buff_out[i * 4 + 2] = buff_in[i * 2];
            buff_out[i * 4 + 3] = buff_in[i * 2 + 1];
        }

        free( tmp );

        return (buff_out);
    }

    /* From HEX-coding to numbers or from UCS2HEX to UCS2: */
    if (char_set_in == MODEM_CHAR_HEX || (char_set_in == MODEM_CHAR_UCS2_0707 && char_set_out == MODEM_CHAR_UCS2_PLAIN))
    {
        *out_buff_len = in_buff_len / 2;
        for (i = 0; i < in_buff_len / 2; i++)
        {
            buff_out[i] = modem_char_hex_to_byte( buff_in + i * 2 );
        }
        return (buff_out);
    }

    /* From numbers to HEX-coding or from UCS2 to UCS2HEX: */
    if (char_set_out == MODEM_CHAR_HEX || (char_set_in == MODEM_CHAR_UCS2_PLAIN && char_set_out == MODEM_CHAR_UCS2_0707))
    {
        /* Protect the incoming buffer from corruption when same buffer     */
        /* is used for input and output:                                    */
        if (buff_in == buff_out)
        {
            tmp = malloc( in_buff_len );
            assert ( tmp != NULL);

            memcpy( tmp, buff_in, in_buff_len );
            buff_in = tmp;
        }

        if (char_set_in == MODEM_CHAR_UCS2_PLAIN && char_set_out == MODEM_CHAR_HEX)
        {
            *out_buff_len = (in_buff_len / 2) * 2;
            for (i = 0; i < *out_buff_len; i += 2)
            {
                if (buff_in[i] != 0)
                {
                    buff_out[i] = '2';
                    buff_out[i + 1] = '0';
                }
                else
                {
                    modem_char_byte_to_hex( buff_in[i + 1], buff_out + i );
                }
            }
        }
        else if (char_set_in == MODEM_CHAR_UCS2_0707)
        {
            *out_buff_len = in_buff_len / 2;
            for (i = 0; i < in_buff_len / 4; i++)
            {
                if (buff_in[i * 4] != '0' || buff_in[i * 4 + 1] != '0')
                {
                    buff_out[i * 2] = '2';
                    buff_out[i * 2 + 1] = '0';
                }
                else
                {
                    buff_out[i * 2] = buff_in[i * 4 + 2];
                    buff_out[i * 2 + 1] = buff_in[i * 4 + 3];
                }
            }
        }
        else
        {
            *out_buff_len = in_buff_len * 2;
            for (i = 0; i < in_buff_len; i++)
            {
                modem_char_byte_to_hex( buff_in[i], buff_out + i * 2 );
            }
        }

        free( tmp );

        return (buff_out);
    }

    /* Convert from UCS2_0707 to charset other than UCS2: */
    if (char_set_in == MODEM_CHAR_UCS2_0707)
    {
        /* First convert UCS2_0707 strings to UCS2 number vector: */
        tmp = malloc( in_buff_len / 2 );
        assert( tmp != NULL );

        for (i = 0; i < in_buff_len / 2; i++)
        {
            tmp[i] = modem_char_hex_to_byte( buff_in + i * 2 );
        }
        in_buff_len = in_buff_len / 2;

        /* Then convert in the same way as from UCS2: */
        modem_char_convert_from_ucs2( char_set_out, tmp, buff_out, in_buff_len, out_buff_len );
        free( tmp );
        return (buff_out);
    }

    /* Convert to UCS2_0707: */
    if (char_set_out == MODEM_CHAR_UCS2_0707)
    {
        /* Convert to UCS2 temporary buffer: */
        tmp = malloc( in_buff_len * 2 );
        assert ( tmp != NULL);

        modem_char_convert_to_ucs2( char_set_in, buff_in, tmp, in_buff_len, out_buff_len );

        /* Convert to UCS2_0707: */
        for (i = 0; i < *out_buff_len; i++)
        {
            modem_char_byte_to_hex( tmp[i], buff_out + i * 2 );
        }

        *out_buff_len = *out_buff_len * 2;
        free( tmp );
        return (buff_out);
    }

    /* Convert from UCS2_PLAIN to some charset: */
    if (char_set_in == MODEM_CHAR_UCS2_PLAIN)
    {
        modem_char_convert_from_ucs2( char_set_out, buff_in, buff_out, in_buff_len, out_buff_len );
        return (buff_out);
    }

    /* Convert to UCS2_PLAIN */
    if (char_set_out == MODEM_CHAR_UCS2_PLAIN)
    {
        /* Protect the incoming buffer from corruption when same buffer     */
        /* is used for input and output:                                    */
        if (buff_in == buff_out)
        {
            tmp = malloc( in_buff_len );
            assert ( tmp != NULL);
            memcpy( tmp, buff_in, in_buff_len );
            buff_in = tmp;
        }
        modem_char_convert_to_ucs2( char_set_in, buff_in, buff_out, in_buff_len, out_buff_len );

        free( tmp );

        return (buff_out);
    }


    /* Otherwise Convert xxx => UCS2_PLAIN => yyy : */
    else
    {
        tmp = malloc( in_buff_len * 2 );
        assert ( tmp != NULL );

        modem_char_convert_to_ucs2( char_set_in, buff_in, tmp, in_buff_len, out_buff_len );
        modem_char_convert_from_ucs2( char_set_out, tmp, buff_out, *out_buff_len, out_buff_len );
        free( tmp );
        return (buff_out);
    }
}

static char* sms_address_get( tSMSLib_Address* address_ptr )
{
    char* tmp_oa;
    tOCT_UINT8 i;
    tOCT_UINT16 tmp_str_len;

    tmp_oa = (char *) malloc(( ( address_ptr->address_length ) + 1 ) * 4 * sizeof( char ) );
    assert( tmp_oa != NULL);

    for(i = 0; i < address_ptr->address_length; i++)
    {
        address_ptr->address[ i ] = htons(address_ptr->address[ i ] );
    }

    ( void )modem_char_buffer_convert( MODEM_CHAR_UCS2_PLAIN, MODEM_CHAR_UTF_8,( char * )address_ptr->address, tmp_oa, ( tOCT_UINT16 )( address_ptr->address_length * 2 ), &tmp_str_len );

    tmp_oa[ tmp_str_len ] = '\0';

    return( tmp_oa );
}

int no_of_char_occurance_in_string(const char *str, char c, tOCT_UINT16 str_len)
{
    int  n = 0;
    int  i = 0;

    for(i=0; i < str_len; i++)
    {
        if( str[i] == c )
        {
            n++;
        }
    }
    return n;
}

static char* sms_get_user_data( tSMSLib_Message* decoded_msg_ptr, tOCT_UINT8* user_data_len )
{
    char* tmp_str = NULL;
    tOCT_UINT16 tmp_ud_length;
    tOCT_UINT8 i;
    tOCT_UINT8 tmp_val;


    if (decoded_msg_ptr->UserDataLength == 0)
    {
        tmp_str = (char*)malloc(1);
        assert ( tmp_str != NULL);

        *tmp_str = '\0';
        *user_data_len = 0;
        return (tmp_str);
    }

    /* Character conversion is done only when 7bit default alphabet is used and TP-UDHI bit is FALSE */
    if ( decoded_msg_ptr->DataCodingScheme == SMS_DATA_CODING_7BIT_VALUE /*&& decoded_msg_ptr->UserDataHeaderIndicator == FALSE */)
    {
        tmp_str = ( char * )malloc(( ( decoded_msg_ptr->UserDataLength ) + 1 ) * 4 * sizeof( char ) );
        assert ( tmp_str != NULL );

        (void)modem_char_buffer_convert( MODEM_CHAR_GSM, MODEM_CHAR_UTF_8,(char *)decoded_msg_ptr->UserData, (char *)tmp_str, (tOCT_UINT16)(decoded_msg_ptr->UserDataLength), &tmp_ud_length );
        tmp_str[tmp_ud_length] = '\0';

        /* Decrease character count if extension characters exist. */
        *user_data_len = decoded_msg_ptr->UserDataLength - no_of_char_occurance_in_string( (char *)decoded_msg_ptr->UserData, 0x1B, decoded_msg_ptr->UserDataLength);
        return ( tmp_str );
    }
    /* For 8bit and 16bit data coding and when TP-UDHI = TRUE, hexadecimal values are presented as ascii in result code. */
    else
    {
        tmp_str = ( char * )malloc(( ( decoded_msg_ptr->UserDataLength ) + 1 ) * 2 * sizeof( char ) );
        assert ( tmp_str != NULL);

        for (i=0; i<decoded_msg_ptr->UserDataLength; i++)
        {
            modem_char_byte_to_hex(decoded_msg_ptr->UserData[i], &tmp_str[i*2]);
        }
        tmp_str[(decoded_msg_ptr->UserDataLength)*2] = '\0';
    }

    if (decoded_msg_ptr->DataCodingScheme == SMS_DATA_CODING_UCS2_VALUE)
    {
        *user_data_len = decoded_msg_ptr->UserDataLength / 2;
        for (i=0; i<*user_data_len; i++)
        {
            /* Change endianess for UCS2 data */
            tmp_val = tmp_str[4*i];
            tmp_str[4*i] = tmp_str[4*i+2];
            tmp_str[4*i+2] = tmp_val;
            tmp_val = tmp_str[4*i+1];
            tmp_str[4*i+1] = tmp_str[4*i+3];
            tmp_str[4*i+3] = tmp_val;
        }
    }
    else
    {
        *user_data_len = decoded_msg_ptr->UserDataLength;
    }

    return( tmp_str );
}

void decodeSmsPdu(userInfo* info)
{
    tOCT_UINT8  tpdu_start_index = 0;
    tOCT_UINT32 tpdu_length = 0;
    tOCT_UINT8* tpdu_data_ptr = NULL;
    tSMSLib_Message* decoded_tpdu = NULL;
    char* da_address = NULL;
    char* user_data_ptr = NULL;
    tOCT_UINT8 converted_user_data_length;

    assert(info->moSmsL3Pdu != NULL);

	/* PD */
	tpdu_start_index++;
	
	/* MsgType = CP_DATA */
	tpdu_start_index++;
	
	/* CP-DATA Length */
	tpdu_start_index++;
	
	/* RP-MsgType(MS -> Nw) */
	tpdu_start_index++;
	
	/* RP-MsgRef */
	tpdu_start_index++;
    
	/* RP-Originator Address */
    tpdu_start_index += info->moSmsL3Pdu[tpdu_start_index];
    tpdu_start_index++; // Length Octet

	/* RP-Destination Address */
    tpdu_start_index += info->moSmsL3Pdu[tpdu_start_index];
    tpdu_start_index++; // Length Octet
    
	/* RP-UserData-Length	*/
    tpdu_length = info->moSmsL3Pdu[tpdu_start_index];
    tpdu_start_index++;

    tpdu_data_ptr = &info->moSmsL3Pdu[tpdu_start_index];
        
    if( SMS_MSG_OK == decodeSmsTpdu(tpdu_data_ptr,tpdu_length, &decoded_tpdu))
    {
        if(decoded_tpdu->MessageTypeIndicator == SMS_SUBMIT)
        {
            da_address = sms_address_get(( tSMSLib_Address* )&decoded_tpdu->AddressValue );
            
            user_data_ptr = sms_get_user_data( decoded_tpdu, &converted_user_data_length );

            // Send Decoded SMS information to client over socket
            fxL2gMoSmsAttemptedInd *ind = (fxL2gMoSmsAttemptedInd *) socketMsgBuf;            
            memset(ind, 0, sizeof(fxL2gMoSmsAttemptedInd));
            
        	ind->hdr.msgLength = sizeof(fxL2gMoSmsAttemptedInd);
            ind->hdr.msgType = FXL_2G_MO_SMS_ATTEMPTED_IND;
            ind->hdr.rat = FXL_RAT_2G;

            memcpy(ind->imsiStr , info->userImsi_str , SIZE_OF_IDENTITY_STR);
            memcpy(ind->msMsisdnOfRecipientNoStr , da_address , ( strlen ( da_address ) + 1 ));

            if(user_data_ptr != NULL)
              memcpy(ind->moSms.smsMessage, user_data_ptr, ( strlen ( user_data_ptr ) + 1 ));
            
            if(decoded_tpdu->UserDataHeaderIndicator == TRUE)
            {
                if(decoded_tpdu->UDHData != NULL && (&decoded_tpdu->UDHData[1]!= NULL && decoded_tpdu->UDHData[1] == 0x00))
                {
                    ind->moSms.isConcatenatedMsg = TRUE;
                    if(&decoded_tpdu->UDHData != NULL)
                      ind->moSms.messageRefNo = decoded_tpdu->UDHData[3];
                    if(&decoded_tpdu->UDHData[4] != NULL)
                      ind->moSms.messageTotalNoOfParts = decoded_tpdu->UDHData[4];
                    if(&decoded_tpdu->UDHData[5] != NULL)
                      ind->moSms.messagePartNumber = decoded_tpdu->UDHData[5];

                    if(ind->moSms.messageTotalNoOfParts != 0 && (ind->moSms.messagePartNumber == ind->moSms.messageTotalNoOfParts))
                    {
                        info->moSmsAllPartsReceived = TRUE;
                    }
                }
            }
            else
            {
                info->moSmsAllPartsReceived = TRUE;
            }

            writeToExternalSocketInterface((tOCT_UINT8*)ind , sizeof(fxL2gMoSmsAttemptedInd));

            /* Free memory */
            if( NULL != da_address )
            {
                free( da_address );
                da_address = NULL;
            }
            
            if( NULL != user_data_ptr )
            {
                free( user_data_ptr );
                user_data_ptr = NULL;
            }

        }

    }

    if ( decoded_tpdu != NULL )
    {
        SMSLib_Message_Destroy(decoded_tpdu);
        decoded_tpdu = NULL;
    }

}

#endif /* FEA_DECODE_MO_SMS */
