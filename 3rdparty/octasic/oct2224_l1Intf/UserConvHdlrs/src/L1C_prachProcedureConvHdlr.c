/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_prachProcedureConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control PRACH Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_prachProcedureConvHdlr.h"

void prachPhyInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                    L1CAPI_Prach_Phy_Info * pL1CPrachPhyInfo,
                                    l1api_prach_params_t * pOpPrachPhyInfo)
{
    uint8_t i;
    
    pL1CPrachPhyInfo->commonPhysicalChannelID = pOpPrachPhyInfo->common_phys_id;
    pL1CPrachPhyInfo->scramblingCodeNumber = pOpPrachPhyInfo->scram_code;
    pL1CPrachPhyInfo->preambleSignatures = pOpPrachPhyInfo->prach_preamble_signatures;
    pL1CPrachPhyInfo->allowedSFCount = pOpPrachPhyInfo->n_sf;
    for(i=0;i<pL1CPrachPhyInfo->allowedSFCount;i++)
    {
      pL1CPrachPhyInfo->allowedSlotFormatInfo[i] = pOpPrachPhyInfo->slot_format[i];
    }
    pL1CPrachPhyInfo->rACH_SubChannelNumbers = pOpPrachPhyInfo->prach_sub_chan_numbers;
    pL1CPrachPhyInfo->ul_punctureLimit = pOpPrachPhyInfo->puncture_limit;
    pL1CPrachPhyInfo->preambleThreshold = pOpPrachPhyInfo->prach_preamble_threshold;
}


void aichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_AICH_Phy_Info * pL1CAichInfo,
                              l1api_aich_params_t * pOpAichInfo)
{
    pL1CAichInfo->commonPhysicalChannelID = pOpAichInfo->common_phys_id;
    pL1CAichInfo->aICH_TransmissionTiming = pOpAichInfo->aich_timing;
    pL1CAichInfo->dl_ChannelisationCodeNumber = pOpAichInfo->chan_code;
    pL1CAichInfo->aICH_Power = pOpAichInfo->aich_power - 22;
    pL1CAichInfo->sTTD_Indicator = pOpAichInfo->sttd_indicator;
}


void prachTrchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                     L1CAPI_Prach_Trch_Info * pL1CPrachTrchInfo,
                                     l1api_trch_ul_params_t * pOpPrachTrchInfo)
{
    pL1CPrachTrchInfo->commonTransportChannelID = pOpPrachTrchInfo->common_trch_ul_id;
}


