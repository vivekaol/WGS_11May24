/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: dlim_qpsk.c

$Octasic_Copyright: $

Description:


$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "octccs.h"
#include "dlimlib.h"


void FASTCALL Dlim_QPSKModulate(
                       uint8 *pSlotFormattedData,
                       tCmplx16 *pSymbolData,
                       uint16 powerWt,
                       uint16 numSymbolsPerSlot)
{
	REGISTER uint16 iSymbol;
	REGISTER uint16 iBit =0;
	REGISTER sint16 *pTempSymReal,*pTempSymImag;
	pTempSymReal =  (sint16*)&(pSymbolData[0].Real);
	pTempSymImag =  (sint16*)&(pSymbolData[0].Imag);
	for(iSymbol = 0 ; iSymbol < numSymbolsPerSlot ; iSymbol ++ )
	{
		
		*pTempSymReal = (sint16)(1- (pSlotFormattedData[iBit] << 1));
        if (*pTempSymReal==DL_DTX_BPSK)
        {
            *pTempSymReal=0;
        }
		*pTempSymReal = (*pTempSymReal)*powerWt;
		
		*pTempSymImag = (sint16)(1- (pSlotFormattedData[iBit+1] << 1));
        if (*pTempSymImag==DL_DTX_BPSK)
        {
            *pTempSymImag=0;
        }
		*pTempSymImag = (*pTempSymImag)*powerWt;	
		
		iBit=iBit+2;
		pTempSymReal = pTempSymReal+2;
		pTempSymImag = pTempSymImag+2;
	}
}