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
 * File Name   : buffergen.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffergen.h"
#include "dlimlib.h"

//Constant
#define     cCPICH_BIT             (20)
#define     cCPICH_SYMBOL          (10)
#define     cCPICH_SF              (256)

/*

f_Chips		        (o) Full UMTS radio frame , starting at slot 0 ( 38400chips @ 16bits complex, right justified 11 bits ). Resulting buffer size is 153600 bytes
f_TxPowerdBm		(i) Transmission power in step of 0.1 dBm From 0 : 0.1 : 10 dBm Minimum value is:0 Maximum value is:100
f_CpichdBm		    (i) Primary CPICH power in dBm From -10.0 : 0.1 :+50.0 dBm Minimum value is:-100 Maximum value is:500
f_PSchPowerdB		(i) P-SCH power level relative to CPICH (dB) From -35.0 : 0.1 : +10.0 dB Minimum value is:-350 Maximum value is:100
f_SSchPowerdB		(i) S-SCH power level relative to CPICH (dB) From -35.0 : 0.1 : +10.0 dB Minimum value is:-350 Maximum value is:100
f_ScrCodePrimary	//(i) Primary scrambling code From 0 : 1 : 511 Minimum value is:0 Maximum value is:511

*/

int GenerateUsgBuffer( short * f_Chips, 
                       short f_TxPowerdBm, 
                       short f_CpichdBm, 
                       short f_PSchPowerdB, 
                       short f_SSchPowerdB, 
                       unsigned f_ScrCodePrimary
                     )
{
    int         SlotIndx;
    int         i;
    short       powerWtPSch;               // Primary SCH Power (DL Power) 
    short       powerWtSSch;               // Secondary SCH Power (DL Power)  
    short       powerWtPcpich;             // Primary CPICH power 
    short       powerWtPccpch;
    unsigned    ScrSequence[cNUMSLOT*160];
    // Buffers specific for SCH
    short           PSCH[DL_SCH_CHIPS_IN_SLOT]={0}; 
    short           SSCH[DL_SCH_CHIPS_IN_SLOT]={0}; 
    short           PS_SC[DL_SCH_CHIPS_IN_SLOT]={0}; 
    short           PSCSSC[DL_SCH_CHIPS_IN_SLOT*cNUMSLOT]; 
    unsigned char   cpichbit[cCPICH_BIT];
    tCmplx16        cpichbitSymbol[cCPICH_SYMBOL];
    unsigned   ScrCodePrimary = f_ScrCodePrimary*16;

    memset(f_Chips,0,cNUMSLOT*cOCT_SLOTSIZE*sizeof(short));

    SetPcpichPower(f_CpichdBm, f_TxPowerdBm);
    powerWtPcpich = GetPcpichPowerWt();             //linear
    powerWtPccpch = 0*GetPowerWt_Rel2Pcpich(0);
    powerWtPSch   = GetPowerWt_Rel2Pcpich(f_PSchPowerdB);
    powerWtSSch   = GetPowerWt_Rel2Pcpich(f_SSchPowerdB);

    // Generate the scrambling code frame (38400chips)
    Dlim_GoldCodeGenerateFrame(ScrSequence, ScrCodePrimary );
    Dlim_CalculatePSC( powerWtPSch, PSCH );
    Dlim_CalculateSSC( SSCH  );

    for(i=0;i<cNUMSLOT;i++)
    {
        Dlim_GenerateSyncCH(&PSCSSC[i*DL_SCH_CHIPS_IN_SLOT],         
                            PSCH,                                           
                            PS_SC, 
                            SSCH,
                            powerWtSSch,
                            ScrCodePrimary,
                            i); 
    }

    //Generate CPICH
    for(i=0; i <cCPICH_BIT; i++)
      cpichbit[i] = 0;

    Dlim_QPSKModulate(cpichbit,cpichbitSymbol,powerWtPcpich,cCPICH_SYMBOL);

    //Generate full radio slots
    for(SlotIndx=0;  SlotIndx < cNUMSLOT; SlotIndx++)
    {
       //Add SCH + SSCH
       Dlim_AddSCH( (tCmplx16 *) &f_Chips[SlotIndx*cOCT_SLOTSIZE],&PSCSSC[SlotIndx*DL_SCH_CHIPS_IN_SLOT] );

       Dlim_SpreadScramble_Combine(cpichbitSymbol, 
                                   &ScrSequence[SlotIndx*160],
                                   (tCmplx16*)&f_Chips[SlotIndx*cOCT_SLOTSIZE],
                                   cCPICH_SF, 
                                   cCPICH_SYMBOL);
    }

    return(0);
}
