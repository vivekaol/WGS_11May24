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
 * File Name   : buffergen.h
 *
 * Description : This file provides main functionality for 3g Tx Buffer 
 *               Generator.
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 07/01/2016	        Ashutosh Samal              File Creation
 *############################################################################
 */
#ifndef _BUFFER_GEN_H_
#define _BUFFER_GEN_H_

#define     cOCT_SLOTSIZE          (2560*2)
#define     cNUMSLOT               (15)
#define     cRADIOFRAME_SIZE       (cNUMSLOT*cOCT_SLOTSIZE) 


/*

f_Chips		        (o) Full UMTS radio frame , starting at slot 0 ( 38400chips @ 16bits complex, right justified 11 bits ). Resulting buffer size is 153600 bytes
f_TxPowerdBm		(i) Transmission power in step of 0.1 dBm From 0 : 0.1 : 10 dBm Minimum value is:0 Maximum value is:100
f_CpichdBm		    (i) Primary CPICH power in dBm From -10.0 : 0.1 :+50.0 dBm Minimum value is:-100 Maximum value is:500
f_PSchPowerdB		(i) P-SCH power level relative to CPICH (dB) From -35.0 : 0.1 : +10.0 dB Minimum value is:-350 Maximum value is:100
f_SSchPowerdB		(i) S-SCH power level relative to CPICH (dB) From -35.0 : 0.1 : +10.0 dB Minimum value is:-350 Maximum value is:100
f_ScrCodePrimary	(i) Primary scrambling code From 0 : 1 : 511 Minimum value is:0 Maximum value is:511

*/

int GenerateUsgBuffer(   short * f_Chips,        //size: cRADIOFRAME_SIZE
                         short f_TxPowerdBm, 
                         short f_CpichdBm, 
                         short f_PSchPowerdB, 
                         short f_SSchPowerdB, 
                         unsigned f_ScrCodePrimary
                     );

#endif //_BUFFER_GEN_H_
