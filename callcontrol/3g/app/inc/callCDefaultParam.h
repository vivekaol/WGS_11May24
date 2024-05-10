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
 * File Name   : callCDefaultParam.h 
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
 
/****************************************************************************  
****************************************************************************  
***************************************************************************/  
#ifndef _CALLC_DEFAULT_PARAM 
#define _CALLC_DEFAULT_PARAM 

#define DEF_L1_MAX_TGPS  6

extern const int DEDICTRANSCHTFSTTI_CHOICE;
extern const int OCTETMODERLC_SZINFOTYP2_TYPE;

extern const int DEF_CON_SETUP_DELTA_TIMER;

extern const int   DEF_DRX;
extern const int   DEF_URAIdentity;

extern const int   DEF_SRB_MaxDAT;  
extern const int   DEF_SRB_TimerPollPeriodic;  
extern const int   DEF_SRB_LastTransmissionPDU;
extern const int   DEF_SRB_LastRetransmissionPDU;                  
extern const int   DEF_SRB_TimerEPC;  
extern const int   DEF_SRB_MissingPDUIndicator;                  
extern const int   DEF_SRB_PollSDU;

extern const int   DEF_Timer_T300;
extern const int   DEF_Counter_N300;
extern const int   DEF_Timer_T_301;
extern const int   DEF_Counter_N_301;
extern const int   DEF_Timer_T_302;
extern const int   DEF_Timer_T_304;
extern const int   DEF_Counter_N_304;
extern const int   DEF_Timer_T_305;
extern const int   DEF_Timer_T_307;
extern const int   DEF_Timer_T_308;
extern const int   DEF_Timer_T_309;
extern const int   DEF_Timer_T_310;
extern const int   DEF_Counter_N_310;
extern const int   DEF_Timer_T_311;
extern const int   DEF_Timer_T_312;
extern const int   DEF_Counter_N_312;
extern const int   DEF_Timer_T_313;
extern const int   DEF_Counter_N_313;
extern const int   DEF_Timer_T_314;
extern const int   DEF_Timer_T_315;
extern const int   DEF_Counter_N_315;
extern const int   DEF_Timer_T_316;
extern const int   DEF_Timer_T_317;


extern const int   DEF_LocalCellId;
extern const int   DEF_TCell;

extern const unsigned int   DEF_MaxTxPower;
extern const int   DEF_ClosedLoopTimingMode;
extern const int   DEF_DLTPC01;
extern const int   DEF_PrimaryScramblingCode;
extern const int   DEF_PowerRaiseLimit;
extern const int   DEF_DLAveragingWindowSize;
extern const int   DEF_CPICHPower;
extern       int   DEF_ULInterference;
extern const int   DEF_NumInSyncEvnt;
extern const int   DEF_NumOutSyncEvnt;
extern const int   DEF_TimeRlFailure;

extern const int   DEF_RACH_TTI;
extern const int   DEF_RACH_CRCSize;
extern const int   DEF_RACH_CodingType;
extern const int   DEF_RACH_CodingRate;
extern const int   DEF_RACH_RateMatchingAttribute;
extern const int   DEF_RACH_NumberOfTFS;
extern const int   DEF_RACH_NumberOfBlocks[2];
extern const int   DEF_RACH_BlockSize[2];

extern const int   DEF_PRACH_SpreadingFactor;
extern const int   DEF_SCCPCH_SpreadingFactor;
extern const int   DEF_SCCPCH_PilotSymbolExistence;

extern const int   DEF_PCH_TTI;
extern const int   DEF_PCH_CRCSize;
extern const int   DEF_PCH_ChannelCoding;
extern const int   DEF_PCH_RateMatchingAttribute;
extern const int   DEF_PCH_NumberOfTFS;
extern const int   DEF_PCH_NumberOfBlocks[2];
extern const int   DEF_PCH_BlockSize[2];

extern const int   DEF_SRB_DL_BlockSize[2];

extern const int   DEF_FACH_PCH_NumberOfTFCS;
extern const int   DEF_FACH_PCH_CTFC[6];
extern const int   DEF_FACH_PCH_GainType[6];
extern const int   DEF_FACH_PCH_ReferenceID[6];

extern const int   DEF_RACH_NumberOfTFCS;
extern const int   DEF_RACH_CTFC[2];
extern const int   DEF_RACH_IncludePower[2];
extern const int   DEF_RACH_GainType[2];
extern const int   DEF_RACH_BetaC[2];
extern const int   DEF_RACH_BetaD[2];
extern const int   DEF_RACH_ReferenceID[2];
extern const int   DEF_RACH_IncludePowerOffsetPpm[2];
extern const int   DEF_RACH_PowerOffsetPpm[2];
extern const int   DEF_RACH_CommonTRCHId;

extern const int   DEF_BCHId;
extern const int   DEF_BCHPwr;

extern const int   DEF_NumSCPICH;
extern const int   DEF_SCPICHId[1];
extern const int   DEF_SCPICHDiversityIndicator[1];
extern const int   DEF_SCPCIHPower[1];
extern const int   DEF_SCPCIH_ScramblingCode[1];
extern const int   DEF_SCPICH_ChannelisationCode[1];

extern const int   DEF_PSCHId;

extern const int   DEF_PSCHPower;
extern const int   DEF_PSCHTSTD;

extern const int   DEF_SSCHId;
extern const int   DEF_SSCHPower;
extern const int   DEF_SSCHTSTD;

extern const int   DEF_PCPICHId;
extern const int   DEF_PCPICHDiversityIndicator;

extern const int   DEF_PCCPCHId;
extern const int   DEF_PCCPCHSTTD;

extern const int   DEF_AICH_Timing;
extern const int   DEF_AICH_CommonPhysId;
extern const int   DEF_AICHPower;
extern const int   DEF_AICH_STTD;
extern const int   DEF_AICH_ChannelisationCode;
extern const int   DEF_AICH_Power;

extern const int   DEF_PICH_CommonPhysId;
extern const int   DEF_PICH_Mode;
extern const int   DEF_PICH_STTD;
extern const int   DEF_PICHPower;
extern const int   DEF_PICH_ChannelisationCode;
extern const int   DEF_PICH_Power;

extern const int   DEF_PRACH_CommonPhysId;
extern const int   DEF_PRACH_ScramblingCode;
extern const int   DEF_PRACH_PreambleThreshold;
extern const int   DEF_PRACH_PreambleSignatures;
extern const int   DEF_PRACH_SubChannelNumbers;
extern const int   DEF_PRACH_PunctureLimit;
extern const int   DEF_PRACH_AllowedSFCount;
extern const int   DEF_PRACH_SlotFormats[1];
extern const int   DEF_PRACH_ConstantValue;
extern const int   DEF_PRACH_PowerRampStep;
extern const int   DEF_PRACH_PreambleRetransmitMax;
extern const int   DEF_PRACH_Nmax;
extern const int   DEF_PRACH_NB01Min;
extern const int   DEF_PRACH_NB01Max;
extern const int   DEF_PRACH_AssignedSubChannelNumber;
extern const int   DEF_PRACH_AvailableSignatureStartIndex;
extern const int   DEF_PRACH_AvailableSignatureEndIndex;

extern const int   DEF_SCCPCH_CommonPhysId;
extern const int   DEF_SCCPCH_Offset;
extern const int   DEF_SCCPCH_STTDIndicator;
extern const int   DEF_SCCPCH_SlotFormat;
extern const int   DEF_SCCPCH_TFCIPresence;
extern const int   DEF_SCCPCH_ChannelisationCode;
extern const int   DEF_SCCPCH_ScramblingCode;
extern const int   DEF_SCCPCH_MuxPosition;
extern const int   DEF_SCCPCH_PowerOffset1;
extern const int   DEF_SCCPCH_PowerOffset3;

extern const int   DEF_PCH_CommonTRCHId;
extern const int   DEF_PCH_DLTxPower;
extern const int   DEF_PCH_toAWS;
extern const int   DEF_PCH_toAWE;

extern const int   DEF_FACH_FACHCount;
extern const int   DEF_FACH_CommonTRCHId[2];
extern const int   DEF_FACH_DLTxPower[2];
extern const int   DEF_FACH_toAWS[2];
extern const int   DEF_FACH_toAWE[2];
extern const int   DEF_FACH_TTI[2];
extern const int   DEF_FACH_CRCSize[2];
extern const int   DEF_FACH_ChannelCoding[2];
extern const int   DEF_FACH_RateMatchingAttribute[2];
extern const int   DEF_FACH_NumberOfTFS[2];
extern const int   DEF_FACH_NumberOfBlocks[2][3];
extern const int   DEF_FACH_BlockSize[2][3];

extern const int   DEF_SFN;
extern const int   DEF_BCCHModSFN;
extern const int   DEF_IBOcId;

#endif
