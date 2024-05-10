/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_sccpchProcedureConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Secondary Common Control Physical Channel Procedure 
   Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_sccpchProcedureConvHdlr.h"


void sccpchPhyInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_SCCPCH_Phy_Info *pL1CSccpchPhyInfo,
                                    l1api_sccpch_params_t * pOpSccpchPhyInfo)
{
    pL1CSccpchPhyInfo->bit_mask = dl_ScramblingCode_present|sccpch_tFCI_present;
    pL1CSccpchPhyInfo->commonPhysicalChannelID = pOpSccpchPhyInfo->common_phys_id;
    pL1CSccpchPhyInfo->sCCPCH_Chip_Offset = pOpSccpchPhyInfo->sccpch_offset;    
    pL1CSccpchPhyInfo->dl_ScramblingCode = pOpSccpchPhyInfo->scram_code;
    pL1CSccpchPhyInfo->dL_ChannelisationCodeNumber = pOpSccpchPhyInfo->chan_code;
    pL1CSccpchPhyInfo->sCCPCH_SlotFormat = pOpSccpchPhyInfo->slot_format;
    pL1CSccpchPhyInfo->tFCI_Presence = (pOpSccpchPhyInfo->tfci_presence == L1API_TFCI_PRESENT)?1:0;
    pL1CSccpchPhyInfo->multiplexingPosition = pOpSccpchPhyInfo->mux_position;
    pL1CSccpchPhyInfo->pO1_ForTFCI_Bits = pOpSccpchPhyInfo->power_offset1;
    pL1CSccpchPhyInfo->pO3_ForPilotBits = pOpSccpchPhyInfo->power_offset3;
    pL1CSccpchPhyInfo->sTTD_Indicator = pOpSccpchPhyInfo->sttd_indicator;
}


void sccpchTrchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                       L1CAPI_SCCPCH_Trch_Info * pL1CTrchInfo,
                                       l1api_trch_dl_params_t * pOpTrchInfo)
{
    pL1CTrchInfo->commonTransportChannelID = pOpTrchInfo->common_trch_dl_id;
    pL1CTrchInfo->maxFACH_PCH_Power = pOpTrchInfo->channel_pwr - 350;
    pL1CTrchInfo->toAWS = pOpTrchInfo->toAWS;
    pL1CTrchInfo->toAWE = pOpTrchInfo->toAWE;
}

void pichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_PICH_Params *  pL1CPichInfo,
                              l1api_pich_params_t * pOpPichInfo)
{
    pL1CPichInfo->commonPhysicalChannelID = pOpPichInfo->common_phys_id;
    pL1CPichInfo->dl_ChannelisationCodeNumber = pOpPichInfo->chan_code;
    pL1CPichInfo->pICH_Power = pOpPichInfo->pich_power - 10;
    pL1CPichInfo->pICH_Mode = pOpPichInfo->pich_mode;
    pL1CPichInfo->sTTD_Indicator = pOpPichInfo->sttd_indicator;
}
