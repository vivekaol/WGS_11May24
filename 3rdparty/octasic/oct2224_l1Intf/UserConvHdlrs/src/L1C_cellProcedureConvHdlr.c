/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: L1C_cellProcedureConvHdlr.c

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description: 

   Layer1 Control Cell Procedure Conversion Handler

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include "L1C_cellProcedureConvHdlr.h"
#include "l1capi_datastruct.h"

void cellInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                             L1CAPI_CellInfo *pL1CCellInfo,
                             l1api_cell_params_t * pOpCellInfo)
{
    pL1CCellInfo->bit_mask = 0; /*not present*/
    if(pOpCellInfo->closed_loop_timing_mode != L1CAPI_ADJ_NOT_DEFINED)
    {
      pL1CCellInfo->bit_mask |= clLoopTimingAdjMode_present; 
    }
    pL1CCellInfo->cId = pOpCellInfo->cell_id;
    pL1CCellInfo->localCellId =  pOpCellInfo->local_cell_id;
    pL1CCellInfo->tCell = pOpCellInfo->t_cell;
    pL1CCellInfo->uarfcnUl = pOpCellInfo->ul_uarfcn;
    pL1CCellInfo->uarfcnDl = pOpCellInfo->dl_uarfcn;
    pL1CCellInfo->maxTxPower = pOpCellInfo->max_tx_power;
    pL1CCellInfo->priScramCode = pOpCellInfo->primary_scram_code;
    pL1CCellInfo->syncConfig.nInSyncInd = pOpCellInfo->n_insync;
    pL1CCellInfo->syncConfig.nOutSyncInd = pOpCellInfo->n_outsync;
    pL1CCellInfo->syncConfig.tRlFailure = pOpCellInfo->t_rlfailure;
    pL1CCellInfo->dlTpc01Count = pOpCellInfo->dl_tpc_01_count;
    pL1CCellInfo->pwrRaiseLimit = pOpCellInfo->power_raise_limit;
    pL1CCellInfo->dlPwrAvrgWinSize = pOpCellInfo->dl_power_averaging_window_size;
}


void schInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_SCH_Info *pL1CSchInfo,
                              l1api_sch_params_t * pOpSchInfo)
{
    pL1CSchInfo->commonPhysicalChannelID = pOpSchInfo->id;    
    pL1CSchInfo->sch_Power = pOpSchInfo->sch_power - 350;
    pL1CSchInfo->tSTD_Indicator = pOpSchInfo->tstd_indicator;
}

void pCpichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                        L1CAPI_Primary_CPICH_Info *pL1CPCPichInfo,
                                        l1api_cpich_params_t * pOpPCpichInfo)
{
    pL1CPCPichInfo->commonPhysicalChannelID = pOpPCpichInfo->id;
    pL1CPCPichInfo->cpich_Power = pOpPCpichInfo->cpich_power - 100;
    pL1CPCPichInfo->tSTD_Indicator = pOpPCpichInfo->diversity_indicator;
}

void sCpichInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                                 L1CAPI_Secondary_CPICH_Info *pL1CPCPichInfo,
                                 l1api_cpich_params_t * pOpPCpichInfo)
{
     pL1CPCPichInfo->commonPhysicalChannelID = pOpPCpichInfo->id;
    pL1CPCPichInfo->cpich_Power = pOpPCpichInfo->cpich_power - 350;
    pL1CPCPichInfo->tSTD_Indicator = pOpPCpichInfo->diversity_indicator;
    pL1CPCPichInfo->dL_ChannelisationCodeNumber = pOpPCpichInfo->chan_code;
    pL1CPCPichInfo->dl_ScramblingCode = pOpPCpichInfo->scram_code;
}

void pCcpchInfoConvHdlr(L1CAPI_Msg_Status *msgStatus,
                             L1CAPI_PrimCCPCH_Info * pL1CPccpchInfo,
                             l1api_pccpch_params_t * pOpPccpchInfo)
{
    pL1CPccpchInfo->commonPhysicalChannelID = pOpPccpchInfo->id;
    pL1CPccpchInfo->sTTD_Indicator = pOpPccpchInfo->sttd_indicator;
}

void bchInfoProcConvHdlr(L1CAPI_Msg_Status *msgStatus,
                              L1CAPI_BCH_Info *pL1CBchInfo,
                              l1api_common_trch_dlbasic_t * pOpBchInfo)
{
    pL1CBchInfo->commonTransportChannelID = pOpBchInfo->id;
    pL1CBchInfo->bCH_Power= pOpBchInfo->pwr - 350;
}

