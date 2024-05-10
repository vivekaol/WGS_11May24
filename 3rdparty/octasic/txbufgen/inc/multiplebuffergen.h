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
 *       (c) FXLynx Technologies Ltd. 2016, All Rights Reserved
 *
 *############################################################################
 */

/*
 *############################################################################
 * File Name   : multiplebuffergen.h
 *
 * Description : This file provides main functionality for multiple 3g Tx Buffer 
 *               Generator.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 07/01/2016	        Ashutosh Samal              File Creation
 *############################################################################
 */
#ifndef _MULTIPLE_BUFFER_GEN_H_
#define _MULTIPLE_BUFFER_GEN_H_
#include "buffergen.h"

typedef struct
{
    unsigned    PSC;    //Primary Scrambling Code
    unsigned    TS;     //TimeShift in chip  0  to +38399
    short       Gain;   // -200:1:200 => -20.0 : 0.1 : +20.0 dB
    short       CpichdBm;
    short       PSchPowerdB; 
    short       SSchPowerdB; 
}tCellPrm;

void nGenerator( unsigned f_NumCell, tCellPrm * f_ptPrm,  short * f_Chips );

#endif //_MULTIPLE_BUFFER_GEN_H_
