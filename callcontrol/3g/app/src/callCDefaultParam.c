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
 * File Name   : callCDefaultParam.c 
 *
 * Description : This is the default configuration files used at app
 *
 * History     :
 *
 * Date			Author		            Details
 * ---------------------------------------------------------------------------
 * 05/09/2014	Roshan Kumar Singh      File Creation
 *############################################################################
 */
 
/* -----------------------------------------------------
 *                 Include Files
 * -----------------------------------------------------
*/
#include "l1capi_datastruct.h"

const int   DEF_SRB_MaxDAT                    = 0xF;  
const int   DEF_SRB_TimerPollPeriodic         = 0x0;  
const int   DEF_SRB_LastTransmissionPDU       = 0x1; 
const int   DEF_SRB_LastRetransmissionPDU     = 0x1;                  
const int   DEF_SRB_TimerEPC                  = 0xa;  
const int   DEF_SRB_MissingPDUIndicator       = 0x1;                  
const int   DEF_SRB_PollSDU                   = 0x0;

const int   DEF_Timer_T300                    = 0xc;
const int   DEF_Counter_N300                  = 0x7;
const int   DEF_Timer_T_301                   = 0xa;
const int   DEF_Counter_N_301                 = 0x2;
const int   DEF_Timer_T_302                   = 0xc;
const int   DEF_Timer_T_304                   = 0x4;
const int   DEF_Counter_N_304                 = 0x2;
const int   DEF_Timer_T_305                   = 0x3;
const int   DEF_Timer_T_307                   = 0x4;
const int   DEF_Timer_T_308                   = 0x2;
const int   DEF_Timer_T_309                   = 0x5;
const int   DEF_Timer_T_310                   = 0x3;
const int   DEF_Counter_N_310                 = 0x4;
const int   DEF_Timer_T_311                   = 0x7;
const int   DEF_Timer_T_312                   = 0xf;
const int   DEF_Counter_N_312                 = 0x1;
const int   DEF_Timer_T_313                   = 0x3;
const int   DEF_Counter_N_313                 = 0x3;
const int   DEF_Timer_T_314                   = 0x2;
const int   DEF_Timer_T_315                   = 0x1;
const int   DEF_Counter_N_315                 = 0x0;
const int   DEF_Timer_T_316                   = 0x3;
const int   DEF_Timer_T_317                   = 0x4;


const int   DEF_LocalCellId                   = 0;
const int   DEF_TCell                         = 0x0;

const int   DEF_ClosedLoopTimingMode          = 0;
const int   DEF_DLTPC01                       = 5;
const int   DEF_PrimaryScramblingCode         = 240;
const int   DEF_PowerRaiseLimit               = 3;
const int   DEF_DLAveragingWindowSize         = 27;
const int   DEF_ULInterference                = -102 ; 
const int   DEF_NumInSyncEvnt                 = 1;
const int   DEF_NumOutSyncEvnt                = 2;
const int   DEF_TimeRlFailure                 = 10;

const int   DEF_RACH_TTI                      = 20; 
const int   DEF_RACH_CRCSize                  = 16; 
const int   DEF_RACH_CodingType               = 1;
const int   DEF_RACH_CodingRate               = 2;
const int   DEF_RACH_RateMatchingAttribute    = 150;
const int   DEF_RACH_NumberOfTFS              = 0x1;
const int   DEF_RACH_NumberOfBlocks[2]        = {0x1,0x1};
const int   DEF_RACH_BlockSize[2]             = {360,360};

const int   DEF_PRACH_SpreadingFactor         = 0x01;
const int   DEF_SCCPCH_SpreadingFactor        = 0x04;
const int   DEF_SCCPCH_PilotSymbolExistence   = 0x00;

const int   DEF_PCH_TTI                       = 0x0;
const int   DEF_PCH_CRCSize                   = 0x3;
const int   DEF_PCH_ChannelCoding             = 0x1;
const int   DEF_PCH_RateMatchingAttribute     = 0xe5;
const int   DEF_PCH_NumberOfTFS               = 0x2;
const int   DEF_PCH_NumberOfBlocks[2]         = {0,1};
const int   DEF_PCH_BlockSize[2]              = {240,240};

const int   DEF_SRB_DL_BlockSize[2]           = {148,148};

const int   DEF_FACH_PCH_NumberOfTFCS             = 6;
const int   DEF_FACH_PCH_CTFC[6]                  = {0,1,2,3,4,6};
const int   DEF_FACH_PCH_GainType[6]              = {0,0,0,0,0,0};
const int   DEF_FACH_PCH_ReferenceID[6]           = {0,0,0,0,0,0};

const int   DEF_RACH_NumberOfTFCS                 = 1;
const int   DEF_RACH_CTFC[2]                      = {0,1};
const int   DEF_RACH_IncludePower[2]              = {1,1};
const int   DEF_RACH_BetaC[2]                     = {15,10};
const int   DEF_RACH_BetaD[2]                     = {10,15};
const int   DEF_RACH_ReferenceID[2]               = {0,0};
const int   DEF_RACH_IncludePowerOffsetPpm[2]     = {1,1};
const int   DEF_RACH_PowerOffsetPpm[2]            = {0,0};
const int   DEF_RACH_CommonTRCHId             = 4;

const int   DEF_BCHId                         = 4;
const int   DEF_NumSCPICH                     = 0;
const int   DEF_SCPICHId[1]                   = {10};
const int   DEF_SCPICHDiversityIndicator[1]   = {0};
const int   DEF_SCPCIHPower[1]                = {0};
const int   DEF_SCPCIH_ScramblingCode[1]      = {0};
const int   DEF_SCPICH_ChannelisationCode[1]  = {6};
const int   DEF_PSCHId                        = 0;
const int   DEF_PSCHTSTD                      = 0;

const int   DEF_SSCHId                        = 1;
const int   DEF_SSCHTSTD                      = 0;
const int   DEF_PCPICHId                      = 2;
const int   DEF_PCPICHDiversityIndicator      = 0;

const int   DEF_PCCPCHId                      = 3;
const int   DEF_PCCPCHSTTD                    = 0;

const int   DEF_AICH_Timing                   = 1;
const int   DEF_AICH_CommonPhysId             = 4;
const int   DEF_AICH_STTD                     = 1;
const int   DEF_AICH_ChannelisationCode       = 0x3;
const int   DEF_AICH_Power                    = -5;

const int   DEF_PICH_CommonPhysId             = 4;
const int   DEF_PICH_Mode                     = 0;
const int   DEF_PICH_STTD                     = 0;
const int   DEF_PICH_ChannelisationCode       = 2;
const int   DEF_PICH_Power                    = -5;

const int   DEF_PRACH_CommonPhysId            = 3;
const int   DEF_PRACH_ScramblingCode          = 0;
const int   DEF_PRACH_PreambleThreshold       = 36;

const int   DEF_PRACH_PreambleSignatures      = 0xFFFF;
const int   DEF_PRACH_SubChannelNumbers       = 0xFFF;
const int   DEF_PRACH_PunctureLimit           = 15;
const int   DEF_PRACH_AllowedSFCount          = 1;
const int   DEF_PRACH_SlotFormats[1]          = {2};
const int   DEF_PRACH_ConstantValue           = -11; 
const int   DEF_PRACH_PowerRampStep           = 1; 
const int   DEF_PRACH_PreambleRetransmitMax   = 30; 
const int   DEF_PRACH_Nmax                    = 10; 
const int   DEF_PRACH_NB01Min                 = 3;
const int   DEF_PRACH_NB01Max                 = 10;
const int   DEF_PRACH_AssignedSubChannelNumber= 0x7;
const int   DEF_PRACH_AvailableSignatureStartIndex = 0;
const int   DEF_PRACH_AvailableSignatureEndIndex = 2;

const int   DEF_SCCPCH_CommonPhysId           = 3;
const int   DEF_SCCPCH_Offset                 = 0;
const int   DEF_SCCPCH_STTDIndicator          = 0;
const int   DEF_SCCPCH_SlotFormat             = 8;
const int   DEF_SCCPCH_TFCIPresence           = 0;
const int   DEF_SCCPCH_ChannelisationCode     = 1;
const int   DEF_SCCPCH_ScramblingCode         = 0;
const int   DEF_SCCPCH_MuxPosition            = 1;
const int   DEF_SCCPCH_PowerOffset1           = 0;
const int   DEF_SCCPCH_PowerOffset3           = 0;

const int   DEF_PCH_CommonTRCHId              = 1;
const int   DEF_PCH_toAWS                     = 0xA0;
const int   DEF_PCH_toAWE                     = 0x28;

const int   DEF_FACH_CommonTRCHId[2]          = {2, 3};
const int   DEF_FACH_toAWS[2]                 = {60, 0xA0};
const int   DEF_FACH_toAWE[2]                 = {0, 0x28};
const int   DEF_FACH_TTI[2]                      = {0x0, 0x0};
const int   DEF_FACH_CRCSize[2]                  = {0x3, 0x3};
const int   DEF_FACH_ChannelCoding[2]            = {0x1, 0x3};
const int   DEF_FACH_RateMatchingAttribute[2]    = {0xdb, 0x81};
const int   DEF_FACH_NumberOfTFS[2]              = {3, 2};
const int   DEF_FACH_NumberOfBlocks[2][3]        = {{0,1,2}, {0,1,0}};
const int   DEF_FACH_BlockSize[2][3]             = {{0xa8,0xa8,0xa8}, {0x168,0x168,0}};

const int   DEF_SFN                                   = 0;
const int   DEF_BCCHModSFN                            = 0;
const int   DEF_IBOcId                                = 1;
