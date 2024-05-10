/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: l1capi_datastruct.h

Copyright (c) 2017 Octasic Technologies Private Limited. All rights reserved.

Description:

   Layer1 Control API Datastruct

This source code is Octasic Technologies Confidential. Use of and access to this code
is covered by the Octasic Technologies Device Enabling Software License Agreement.
Acknowledgement of the Octasic Technologies Device Enabling Software License was
required for access to this code. A copy was also provided with the release.

Release: OCTSDR Software Development Kit OCTSDR-SR_3G-03.01.00-B476 (2017/09/26)

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef _L1CAPI_DATASTRUCT_H_
#define _L1CAPI_DATASTRUCT_H_
#include "l1IntEnums.h"
#include "l1MsgStatus.h"

/*L1CAPI Constraint Marco*/
#define L1CAPI_MAX_NR_OF_CELL		 			(1)
#define L1CAPI_MAX_RL				 			(1)
#define L1CAPI_MAX_USERS			 			(32)
#define L1CAPI_MAX_NR_OF_COORDDCH    			(4)
#define L1CAPI_MAX_TRCH_COUNT		 			(6)
#define L1CAPI_MAX_TGPS				 			(6)
#define L1CAPI_MAX_NR_OF_SCPICH		 			(0)
#define L1CAPI_MAX_NR_OF_DCHS	     			(6)
#define L1CAPI_MAX_NR_OF_FACH	     			(2)
#define L1CAPI_MAX_NR_OF_TFCS_CTFC   			(36)
#define L1CAPI_MAX_NR_OF_TFS         			(8)
#define L1CAPI_MAX_NR_OF_TB       				(12)
#define L1CAPI_MAX_NR_OF_HS_MACD_FLOWS			(8)
#define L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS		(8)
#define L1CAPI_MAX_NR_OF_PRIORITY_Q				(4)
#define L1CAPI_MAX_NR_OF_MACDPDU_IDX			(8)
#define L1CAPI_MAX_NR_OF_EDPCCH_PO_QUANTSTEPS   (8)
#define L1CAPI_MAX_NR_OF_REF_ETFCIS				(4)
#define L1CAPI_MAX_NR_OF_BITS_MAX_E_PDU_NON_SCEDULED (19982)
#define L1CAPI_MAX_NR_OF_TFS					(8)
#define L1CAPI_MAX_NR_OF_EDCH_MACD_FLOWS		(8)
#define L1CAPI_TOAWS_MAX						(1279)
#define L1CAPI_TOA_MAX							(2559)
#define L1CAPI_MAX_NR_OF_E_AGCH					(8)
#define L1CAPI_MAX_NR_OF_E_RGCH_HICH			(8)
#define L1CAPI_MANR_OF_DL_CODEDS				(1)
#define L1CAPI_MAX_REF_ETFCI_COUNT				(8) 
#define L1CAPI_MAX_NUM_LOGICAL_CHANS			(8)

/*EDCH MACROS*/
#define L1CAPI_MAX_EDCH_SUBFRAMES_PER_FRAME (5)//16
#define L1CAPI_MAX_MAC_ES_PDUS_PER_SUBFRAME (4)//15
#define L1CAPI_MAX_FRAME_SEQ_NUM                        15
#define L1CAPI_MAX_CFN_NUM                                    255
#define MAX_NUM_SUB_FRAMES                                    15
/*************************************************/
/******  data structure type definition  ************************/
/*************************************************/
/*Cell Id*/
typedef uint16_t  L1CAPI_Cell_ID;
/*Local Cell Id*/
typedef uint8_t   L1CAPI_Local_Cell_ID;
/*Cell timing offset*/
typedef enum L1CAPI_T_Cell {
    L1CAPI_T_CELL_V0 = 0,
    L1CAPI_T_CELL_V1 = 1,
    L1CAPI_T_CELL_V2 = 2,
    L1CAPI_T_CELL_V3 = 3,
    L1CAPI_T_CELL_V4 = 4,
    L1CAPI_T_CELL_V5 = 5,
    L1CAPI_T_CELL_V6 = 6,
    L1CAPI_T_CELL_V7 = 7,
    L1CAPI_T_CELL_V8 = 8,
    L1CAPI_T_CELL_V9 = 9
} L1CAPI_T_Cell;

/*Absolute frequency channel number*/
typedef uint16_t L1CAPI_UARFCN;
/*Max transmit power*/
typedef uint16_t L1CAPI_MaximumTransmissionPower;
/*Primary scrambling code*/
typedef uint16_t  L1CAPI_PrimScramCode;
/*DL TPC pattern 01 count*/
/* Unit seconds, Range 0s .. 25.5s, Step 0.1s */
typedef uint8_t  L1CAPI_DL_TPC_Pattern01Count;
/* Number of in-sync events before radio link is synchronized */
typedef uint8_t  L1CAPI_N_INSYNC_IND;
/* Number of out-sync events before radio link is out-of-sync */
typedef uint8_t  L1CAPI_N_OUTSYNC_IND;
/* Time (in 100ms steps) to elapse before radio link failure is signalled */
typedef uint8_t L1CAPI_T_RLFAILURE;
/*DL Power raise limit*/
typedef uint8_t  L1CAPI_PowerRaiseLimit;
/* DL power averaging window size */
typedef uint8_t  L1CAPI_DLPowerAveragingWindowSize;
/*Common physical channel ID*/
typedef uint8_t  L1CAPI_CommonPhyChannelID;
/*Common transport channel ID*/
typedef uint8_t  L1CAPI_CommonTranspChannelID;

/*Dl Power*/
typedef sint16_t  L1CAPI_DL_Power;
/*scrambling code index*/
typedef uint8_t   L1CAPI_ScramCodeNumber;
/*UL Scarmbling code number,0..16777215*/
typedef uint32_t  L1CAPI_UL_ScramCode;
/*PICH Power-- Unit dB, Range -10dB .. +5dB, Step +1dB*/
typedef sint8_t   L1CAPI_PICH_Power; 
/*SCCPCH chip offset
S-CCPCH-Offset ::= INTEGER (0..149)
-- 0: 0 chip, 1: 256 chip, 2: 512 chip, .. ,149: 38144 chip [7] --
*/
typedef uint8_t                          L1CAPI_SCCPCHChipOffset;
/* second CCPCH slot format*/
typedef uint8_t                          L1CAPI_SCCPCHSlotFormat;

/*CTFC value*/
typedef uint8_t   L1CAPI_TFCS_CTFC;
/*Reference TFC number*/
typedef uint8_t L1CAPI_RefTFCNumber;
/*BetaC or BetaD*/
typedef uint8_t   L1CAPI_BetaCD;
/*rate matching attribute from 1..256*/
typedef uint16_t  L1CAPI_TFS_RateMatchingAttribute;
/*number of transport block*/
typedef uint8_t  L1CAPI_TFS_NrOfTransportBlocks;
/*transport block size*/
typedef uint16_t  L1CAPI_TFS_TransportBlockSize;
/*Channelisation code number*/
typedef uint16_t  L1CAPI_DL_ChannelCodeNumber;
/*Power offset*/
typedef uint8_t   L1CAPI_PowerOffset;
/*to AWS*/
typedef uint16_t  L1CAPI_ToAWS;
/*to AWE*/
typedef uint16_t  L1CAPI_ToAWE;
/*Puncture limte
-- 0: 40%; 1: 44%; ... 14: 96%; 15: 100%
-- 0 is not applicable for E-DPCH
*/
typedef uint8_t  L1CAPI_PunctureLimit;

/* Prach preamble threshold
-- 0= -36.0dB, 1= -35.5dB, ... , 72= 0.0dB
*/
typedef uint8_t    L1CAPI_PreambleThreshold;

/*NodeB Context*/
typedef uint8_t   L1CAPI_NodeB_Com_Context;
/*Radiolink ID*/
typedef uint8_t   L1CAPI_Radiolink_ID;
/*Radiolink Set ID*/
typedef uint8_t   L1CAPI_Radiolink_Set_ID;
/*Frame Offset 0..255*/
typedef uint8_t   L1CAPI_FrameOffset;
/*Chip Offset 0..38399*/
typedef uint16_t  L1CAPI_ChipOffset;
/*PropagationDelay from 255..1023*/
typedef uint16_t  L1CAPI_PropagationDelay;
/*system frame number*/
typedef uint16_t   L1CAPI_SFN;
/*Counter frame number*/
typedef uint8_t   L1CAPI_CFN;
/*DCH ID*/
typedef uint8_t   L1CAPI_DCH_ID;
/*DL DPCH Slot format*/
typedef uint8_t   L1CAPI_DL_DPCH_SlotFormat;
/*UL DPCH Slot format*/
typedef uint8_t   L1CAPI_UL_DPCCH_SlotFormat;
/*MAX number of UL DPDCH*/
typedef uint8_t   L1CAPI_MaxNrOfUL_DPDCHs;
/*UL SIR target vaule  -82..173*/
typedef sint16_t  L1CAPI_UL_SIR;
/*TGPS ID 0..6*/
typedef uint8_t   L1CAPI_TGPSID;
/*TGPRC 0..511*/
typedef uint16_t   L1CAPI_TGPRC;

/*TGSN 0..14*/
typedef uint8_t   L1CAPI_TGSN;
/*Gap Lenght 1..14 slot*/
typedef uint8_t   L1CAPI_GapLength;
/*TGD*/
typedef uint16_t  L1CAPI_TGD;
/*Gap Duration 1..144 frame*/
typedef uint8_t   L1CAPI_GapDuration;
/*DeltaSIR                ::= INTEGER (0..30)
-- Unit dB, Step 0.1 dB, Range 0..3 dB.
*/
typedef uint8_t   L1CAPI_DeltaSIR;
/*MaxAdjustmentStep            ::= INTEGER(1..10)
-- Unit Slot*/
typedef uint8_t   L1CAPI_MaxAdjustmentStep;
/*AdjustmentPeriod            ::= INTEGER(1..256)
-- Unit Frame*/
typedef uint16_t  L1CAPI_AdjustmentPeriod;
/*ScaledAdjustmentRatio            ::= INTEGER(0..100)
-- AdjustmentRatio  = ScaledAdjustmentRatio / 100*/
typedef uint8_t   L1CAPI_ScaledAdjustmentRatio;
/*HSDSCH Reordering buffer*/
typedef uint16_t  L1CAPI_MAChsReorderBufferSize_RLC_UM;
/*CQI reperition factor 1..4*/
typedef uint8_t   L1CAPI_CQI_RepetitionFactor;
/*Ack Nack repetition factor*/
typedef uint8_t   L1CAPI_AckNack_RepetitionFactor;
/*CQI power offset 0..8*/
typedef uint8_t   L1CAPI_CQI_Power_Offset;
/*ACK power offset 0..8*/
typedef uint8_t   L1CAPI_Ack_Power_Offset;
/*NACK power offset 0..8*/
typedef uint8_t   L1CAPI_Nack_Power_Offset;
/*
-- PowerOffset = -32 + offset * 0.25
-- Unit dB, Range -32dB .. +31.75dB, Step +0.25dB
0..255
*/
typedef uint8_t   L1CAPI_HSSCCH_PowerOffset;
/*-12 .. 26
-- Actual value = IE value * 0.5
*/
typedef sint8_t   L1CAPI_Measurement_Power_Offset;
/*MacD Flow ID*/
typedef uint8_t   L1CAPI_HSDSCH_MACdFlow_ID;
/*Priority queue ID 0..7*/
typedef uint8_t   L1CAPI_PriorityQueue_Id;
/*Scheduling Priority Indicator 0..15*/
typedef uint8_t   L1CAPI_SchedulingPriorityIndicator;
/*HS-RNTI 0..65535*/
typedef uint16_t  L1CAPI_HSDSCH_RNTI;
/*E-RNTI 0..65535*/
typedef uint16_t  L1CAPI_E_RNTI;
/*1..15*/
typedef uint8_t   L1CAPI_HSPDSCH_Start_code_number;
/*E-TFCI*/
typedef uint8_t   L1CAPI_E_TFCI;
/*EDCH MacD Flow ID*/
typedef uint8_t   L1CAPI_E_DCH_MACdFlow_ID;

typedef uint32_t L1CAPI_E_DCH_Maximum_Bitrate;
typedef uint8_t  L1CAPI_E_DCH_Processing_Overload_Level;
typedef uint8_t  L1CAPI_E_DCH_Reference_Power_Offset;
typedef uint8_t  L1CAPI_Max_Nr_of_ReTx_E_DCH;
typedef uint8_t  L1CAPI_E_DCH_HARQ_PO;
/*EDCH Logical channel ID*/
typedef uint8_t L1CAPI_LogicalChannelID;
/*MAC-E Guarantee rate*/
typedef uint32_t L1CAPI_MACEsGuaranteedBitRate;
/*DDI value*/
typedef uint8_t  L1CAPI_E_DCH_DDI_Value;
typedef uint8_t  L1CAPI_E_DCH_TFCI_Table_Index;
typedef uint8_t  L1CAPI_Reference_E_TFCI_PO;
typedef uint8_t  L1CAPI_E_DPCCH_PO;
/*RGCH threshold 0..37*/
typedef uint8_t  L1CAPI_E_RGCH_2_IndexStepThreshold;
typedef uint8_t  L1CAPI_E_RGCH_3_IndexStepThreshold;

/*Total wide band power*/
typedef uint16_t L1CAPI_Max_Target_RcvedTotalWideBandPwr;

typedef uint16_t L1CAPI_Ref_RcvedTotalWideBandPwr;

typedef uint8_t  L1CAPI_E_DCH_HarqProc_Alloc_2ms_tti;

typedef uint8_t  L1CAPI_E_RGCH_Signature_Sequence;

typedef uint8_t  L1CAPI_E_HICH_Signature_Sequence;
/* value from 0..255   PowerOffset = -32 + offset * 0.25 */
/* Unit dB, Range -32dB .. +31.75dB, Step +0.25dB */
typedef uint8_t  L1CAPI_E_AGCH_PowerOffset;
typedef uint8_t  L1CAPI_E_RGCH_PowerOffset;
typedef uint8_t  L1CAPI_E_HICH_PowerOffset;
/*EDCH serving grant 0..38*/
typedef uint8_t  L1CAPI_E_Serving_Grant_Value;
typedef uint32_t L1CAPI_MAChsGuaranteedBitRate;
typedef uint8_t  L1CAPI_SID;
typedef uint16_t L1CAPI_MACdPDU_Size;
typedef uint16_t  L1CAPI_Max_Bits_MACe_PDU_non_scheduled;

typedef uint16_t L1CAPI_BCCH_SIB_Pos;

/*Binding ID for channels*/
typedef uint32_t L1CAPI_BINDING_ID;

/*Measurement ID 0..(2^20)-1 */
typedef uint32_t L1CAPI_Meas_ID;
/*Measurement Value*/
typedef uint16_t L1CAPI_MeasValue;
/*Measurement Filter Coefficient*/
typedef uint8_t L1CAPI_MeasFilterCoeff;

typedef enum {
	/*Common Measurements*/
	L1CAPI_MEAS_RTWP=0,
	L1CAPI_MEAS_ACK_PRACH_PREAMBLES,
	L1CAPI_MEAS_TX_CARRIER_PWR,
	/*Dedicated Measurements*/
	L1CAPI_MEAS_SIR,
	L1CAPI_MEAS_SIR_ERROR,
	L1CAPI_MEAS_TX_CODE_PWR,
	L1CAPI_MEAS_RTT,
	L1CAPI_MEAS_RSCP,
	L1CAPI_MEAS_TOTAL ///END. ADD any Enums before this
} L1CAPI_MeasType;

typedef enum {
	L1CAPI_FN_REPORT_REQD=0,
	L1CAPI_FN_REPORT_NOT_REQD
} L1CAPI_FnReportInd;

typedef enum {
	L1CAPI_MEAS_ON_DEMAND = 0,
	L1CAPI_MEAS_PERIODIC,
	L1CAPI_MEAS_EVENT_A,
	L1CAPI_MEAS_EVENT_B,
	L1CAPI_MEAS_EVENT_C,
	L1CAPI_MEAS_EVENT_D,
	L1CAPI_MEAS_EVENT_E,
	L1CAPI_MEAS_EVENT_F
}L1CAPI_MeasRepMode;

typedef enum {
    L1CAPI_SIGNALLED_GF,
    L1CAPI_COMPUTED_GF
} L1CAPI_TFC_GainFactorMode;

typedef struct L1CAPI_TFC_Beta {
    L1CAPI_TFC_GainFactorMode               gainFactor; 
    L1CAPI_BetaCD                           betaC;
    L1CAPI_BetaCD                           betaD;
    L1CAPI_RefTFCNumber                     refTFCNumber;
} L1CAPI_TFC_Beta;

typedef struct L1CAPI_TFCS_Info_Item {
    uint8_t                                 bit_mask;
#define      tFC_Beta_present 0x80
    L1CAPI_TFCS_CTFC                        cTFC;
    /* optional; set in bit_mask tFC_Beta_present if present */
    /*Only applied for UL */
    L1CAPI_TFC_Beta                         *ptrTFCBeta;  
} L1CAPI_TFCS_Info_Item;

typedef struct L1CAPI_TFCS_Info {
	uint8_t 								tfcsSize;
	L1CAPI_TFCS_Info_Item                   *ptrCctrchTfc;
} L1CAPI_TFCS_Info;

typedef enum L1CAPI_TFS_TTISemiStatic {
    L1CAPI_MSEC_10 = 10,
    L1CAPI_MSEC_20 = 20,
    L1CAPI_MSEC_40 = 40,
    L1CAPI_MSEC_80 = 80
} L1CAPI_TFS_TTISemiStatic;

typedef enum L1CAPI_TFS_CRC_Size {
    L1CAPI_TFS_CRC_SIZE_V0 = 0,
    L1CAPI_TFS_CRC_SIZE_V8 = 8,
    L1CAPI_TFS_CRC_SIZE_V12 = 12,
    L1CAPI_TFS_CRC_SIZE_V16 = 16,
    L1CAPI_TFS_CRC_SIZE_V24 = 24
} L1CAPI_TFS_CRC_Size;

typedef enum L1CAPI_TFS_ChannelCodingType {
    L1CAPI_CONV_CODING = 0,
    L1CAPI_TURBO_CODING = 1,
    L1CAPI_NO_CODING = 2    
} L1CAPI_TFS_ChannelCodingType;

typedef enum L1CAPI_TFS_CodingRate {
    L1CAPI_HALF_RATE = 2,
    L1CAPI_ONETHIRD_RATE = 3
} L1CAPI_TFS_CodingRate;

typedef struct L1CAPI_TFS_DynamicPartListItem {
    L1CAPI_TFS_NrOfTransportBlocks          nrOfTransportBlocks;
    L1CAPI_TFS_TransportBlockSize           transportBlockSize;
} L1CAPI_TFS_DynamicPartListItem;

typedef struct L1CAPI_TransportFormatSet {
    uint8_t                                 tfCount;
    L1CAPI_TFS_TTISemiStatic                tti;
    L1CAPI_TFS_CRC_Size                     crcType;
    L1CAPI_TFS_ChannelCodingType            codingType;
    L1CAPI_TFS_CodingRate                   codingRate; 
    L1CAPI_TFS_RateMatchingAttribute        rmAttrib;
    L1CAPI_TFS_DynamicPartListItem          *ptrTransFormat;
} L1CAPI_TransportFormatSet;

typedef enum L1CAPI_MultiplexingPosition {
    L1CAPI_FIXED = 0,
    L1CAPI_FLEXIBLE = 1
} L1CAPI_MultiplexingPosition;


typedef struct L1CAPI_Sync_Config {
    L1CAPI_N_INSYNC_IND                     nInSyncInd;
    L1CAPI_N_OUTSYNC_IND                    nOutSyncInd;
    L1CAPI_T_RLFAILURE                      tRlFailure;
} L1CAPI_Sync_Config;

typedef enum L1CAPI_Closedlooptimingadjustmentmode {
    L1CAPI_ADJ_1_SLOT = 0,
    L1CAPI_ADJ_2_SLOT = 1,
    L1CAPI_ADJ_NOT_DEFINED = 2
} L1CAPI_Closedlooptimingadjustmentmode;

typedef enum L1CAPI_IPDL_Indicator {
    L1CAPI_IPDL_INDICATOR_ACTIVE = 0,
    L1CAPI_IPDL_INDICATOR_INACTIVE = 1
} L1CAPI_IPDL_Indicator;

typedef enum L1CAPI_IP_SpaceingFDD {
    L1CAPI_IP_SP5 = 0,
    L1CAPI_IP_SP7 = 1,
    L1CAPI_IP_SP10 = 2,
    L1CAPI_IP_SP15 = 3,
    L1CAPI_IP_SP20 = 4,
    L1CAPI_IP_SP30 = 5,
    L1CAPI_IP_SP40 = 6,
    L1CAPI_IP_SP50 = 7
} L1CAPI_IP_SpaceingFDD;

typedef enum L1CAPI_IP_Length {
    L1CAPI_IPLEN5 = 0,
    L1CAPI_IPLEN10 = 1
} L1CAPI_IP_Length;

typedef enum L1CAPI_BCCH_SIB_Rep {
	L1CAPI_SIB_INVAL=0,		/*Invalid - SIB Absent*/
	L1CAPI_SIB_REP4,        /*SIBPos=0..1*/
	L1CAPI_SIB_REP8,		/*SIBPos=0..3*/
	L1CAPI_SIB_REP16,		/*SIBPos=0..7*/
	L1CAPI_SIB_REP32,		/*SIBPos=0..15*/
	L1CAPI_SIB_REP64,		/* ... */
	L1CAPI_SIB_REP128,
	L1CAPI_SIB_REP256,
	L1CAPI_SIB_REP512,
	L1CAPI_SIB_REP1024,
	L1CAPI_SIB_REP2048,		/*SIBPos=0..1023*/
	L1CAPI_SIB_REP4096		/*SIBPos=0..2047*/	
}L1CAPI_BCCH_SIB_Rep;

typedef struct L1CAPI_BurstModeParams {
    uint8_t                                 burstStart;
    uint8_t                                 burstLength;
    uint8_t                                 burstFreq;
} L1CAPI_BurstModeParams;

typedef struct L1CAPI_IPDL_Parameters {
    uint8_t                                 bit_mask;
#define    ipdl_burstModeParams_present 0x80
    L1CAPI_IP_SpaceingFDD                   iP_SpacingFDD;
    L1CAPI_IP_Length                        iP_Length;
    uint8_t                                 seed;
    /* optional; set in bit_mask ipdl_burstModeParams_present if present */
    L1CAPI_BurstModeParams                  *ptrBurstModeParams;  
} L1CAPI_IPDL_Parameters;

typedef struct L1CAPI_IPDLParameter_Info{
    L1CAPI_IPDL_Indicator                   iPDL_Indicator;
    L1CAPI_IPDL_Parameters                  iPDL_Parameters;
} L1CAPI_IPDLParameter_Info;

typedef enum L1CAPI_TSTD_Indicator {
    L1CAPI_TSTD_INDICATOR_ACTIVE = 0,
    L1CAPI_TSTD_INDICATOR_INACTIVE = 1
} L1CAPI_TSTD_Indicator;

typedef struct L1CAPI_CellInfo {
    uint8_t                                 bit_mask;
#define      clLoopTimingAdjMode_present 0x80
#define      ipdlParams_present 0x40
    L1CAPI_Cell_ID                          cId;
    L1CAPI_Local_Cell_ID                    localCellId;
    L1CAPI_T_Cell                           tCell;
    L1CAPI_UARFCN                           uarfcnUl;
    L1CAPI_UARFCN                           uarfcnDl;
    L1CAPI_MaximumTransmissionPower         maxTxPower;
    L1CAPI_PrimScramCode                    priScramCode;
    L1CAPI_Sync_Config                      syncConfig;
    L1CAPI_DL_TPC_Pattern01Count            dlTpc01Count;
    /* optional; set in bit_mask clLoopTimingAdjMode_present  if present */
    L1CAPI_Closedlooptimingadjustmentmode   *ptrClLoopTimingAdjMode;  
    /* optional; set in bit_mask ipdlParams_present if present */
    L1CAPI_IPDLParameter_Info               *ptrIpdlParams;  
    L1CAPI_PowerRaiseLimit                  pwrRaiseLimit;
    L1CAPI_DLPowerAveragingWindowSize       dlPwrAvrgWinSize;
} L1CAPI_CellInfo;

typedef struct L1CAPI_SCH_Info{
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_DL_Power                         sch_Power;
    L1CAPI_TSTD_Indicator                   tSTD_Indicator;
} L1CAPI_SCH_Info;

typedef struct L1CAPI_Primary_CPICH_Info{
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_DL_Power                         cpich_Power;
    L1CAPI_TSTD_Indicator                   tSTD_Indicator;
} L1CAPI_Primary_CPICH_Info;

typedef struct L1CAPI_Secondary_CPICH_Info {
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_DL_Power                         cpich_Power;
    L1CAPI_TSTD_Indicator                   tSTD_Indicator;
    L1CAPI_DL_ChannelCodeNumber             dL_ChannelisationCodeNumber;
    L1CAPI_ScramCodeNumber                  dl_ScramblingCode;
} L1CAPI_Secondary_CPICH_Info;

typedef enum L1CAPI_STTD_Indicator {
    L1CAPI_STTD_INDICATOR_ACTIVE = 0,
    L1CAPI_STTD_INDICATOR_INACTIVE = 1
} L1CAPI_STTD_Indicator;

typedef struct L1CAPI_PrimCCPCH_Info{
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_STTD_Indicator                   sTTD_Indicator;
} L1CAPI_PrimCCPCH_Info;

typedef struct L1CAPI_BCH_Info{
    L1CAPI_CommonTranspChannelID            commonTransportChannelID;
    L1CAPI_DL_Power                         bCH_Power;
} L1CAPI_BCH_Info;

typedef struct L1CAPI_CellChReconf_Info{
	L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
	L1CAPI_DL_Power                         channel_Power;
}L1CAPI_CellChReconf_Info;

typedef struct L1CAPI_CellChannelsReconf{
	#define cellreconf_physDlPSch_present      0x80
	#define cellreconf_physDlSSch_present      0x40
	#define cellreconf_physDlPCpich_present    0x20
	uint8_t	bit_mask;
	/* optional; set in bit_mask cellreconf_physDlPSch_present if present */
    L1CAPI_CellChReconf_Info                physDlPSch;
    /* optional; set in bit_mask cellreconf_physDlSSch_present if present */
    L1CAPI_CellChReconf_Info                physDlSSch;
    /* optional; set in bit_mask cellreconf_physDlPCpich_present if present */
    L1CAPI_CellChReconf_Info                physDlPCpich;
    uint8_t                                 nSCPich;
    /* optional; present if nSCPich!=0. Currently not supported*/
    L1CAPI_CellChReconf_Info                *ptrPhysDlSCpich;
}L1CAPI_CellChannelsReconf;

typedef struct L1CAPI_CellReconfPsc_Info{
    /*Primary scrambling code*/
	L1CAPI_PrimScramCode priScramCode;
    L1CAPI_DL_Power                         bCH_Power;
} L1CAPI_CellReconfPsc_Info;

typedef struct L1CAPI_CommonInfo {
    L1CAPI_Cell_ID                          cId;
} L1CAPI_CommonInfo;

typedef uint16_t L1CAPI_PreambleSignatures;
#define                     L1CAPI_Signature15 (0x8000)
#define                     L1CAPI_Signature14 (0x4000)
#define                     L1CAPI_Signature13 (0x2000)
#define                     L1CAPI_Signature12 (0x1000)
#define                     L1CAPI_Signature11 (0x0800)
#define                     L1CAPI_Signature10 (0x0400)
#define                     L1CAPI_Signature9 (0x0200)
#define                     L1CAPI_Signature8 (0x0100)
#define                     L1CAPI_Signature7 (0x0080)
#define                     L1CAPI_Signature6 (0x0040)
#define                     L1CAPI_Signature5 (0x0020)
#define                     L1CAPI_Signature4 (0x0010)
#define                     L1CAPI_Signature3 (0x0008)
#define                     L1CAPI_Signature2 (0x0004)
#define                     L1CAPI_Signature1 (0x0002)
#define                     L1CAPI_Signature0 (0x0001)

typedef uint16_t L1CAPI_RACH_SubChannelNumbers;
#define                     L1CAPI_SubCh11 (0x800)
#define                     L1CAPI_SubCh10 (0x400)
#define                     L1CAPI_SubCh9  (0x200)
#define                     L1CAPI_SubCh8  (0x100)
#define                     L1CAPI_SubCh7  (0x080)
#define                     L1CAPI_SubCh6  (0x040)
#define                     L1CAPI_SubCh5  (0x020)
#define                     L1CAPI_SubCh4  (0x010)
#define                     L1CAPI_SubCh3  (0x008)
#define                     L1CAPI_SubCh2  (0x004)
#define                     L1CAPI_SubCh1  (0x002)
#define                     L1CAPI_SubCh0  (0x001)

typedef uint8_t L1CAPI_Allowed_RACH_SlotFormat;
#define    L1CAPI_RACH_SlotFormat_v0 (0)
#define    L1CAPI_RACH_SlotFormat_v1 (1)
#define    L1CAPI_RACH_SlotFormat_v2 (2)
#define    L1CAPI_RACH_SlotFormat_v3 (3)

typedef struct L1CAPI_Prach_Phy_Info {
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_ScramCodeNumber                  scramblingCodeNumber;
    L1CAPI_PreambleSignatures               preambleSignatures;
    uint8_t                                 allowedSFCount; /*(1..4) */
    L1CAPI_Allowed_RACH_SlotFormat          allowedSlotFormatInfo[4];
    L1CAPI_RACH_SubChannelNumbers           rACH_SubChannelNumbers;
    L1CAPI_PunctureLimit                    ul_punctureLimit;
    L1CAPI_PreambleThreshold                preambleThreshold;
} L1CAPI_Prach_Phy_Info;

typedef enum L1CAPI_AICH_TransmissionTiming {
    L1CAPI_AICH_TRANSTIMING_V0 = 0,
    L1CAPI_AICH_TRANSTIMING_V1 = 1
} L1CAPI_AICH_TransmissionTiming;

typedef struct L1CAPI_AICH_Phy_Info {
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_AICH_TransmissionTiming          aICH_TransmissionTiming;
    L1CAPI_DL_ChannelCodeNumber             dl_ChannelisationCodeNumber;
    L1CAPI_DL_Power                         aICH_Power;
    L1CAPI_STTD_Indicator                   sTTD_Indicator;
} L1CAPI_AICH_Phy_Info;

typedef struct L1CAPI_Prach_Trch_Info {
    L1CAPI_CommonTranspChannelID            commonTransportChannelID;
    L1CAPI_TransportFormatSet               tfsUL;
} L1CAPI_Prach_Trch_Info;

typedef struct L1CAPI_SCCPCH_Phy_Info {
    uint8_t                                 bit_mask;
#define      dl_ScramblingCode_present 0x80
#define      sccpch_tFCI_present 0x40
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_SCCPCHChipOffset                 sCCPCH_Chip_Offset;
    /* optional; set in bit_mask dl_ScramblingCode_present if present */
    L1CAPI_ScramCodeNumber                  dl_ScramblingCode;
    L1CAPI_DL_ChannelCodeNumber             dL_ChannelisationCodeNumber;
    L1CAPI_SCCPCHSlotFormat                 sCCPCH_SlotFormat;
    /* optional; set in bit_mask sccpch_tFCI_present if present */    
    uint8_t                                 tFCI_Presence;  
    L1CAPI_MultiplexingPosition             multiplexingPosition;
    L1CAPI_PowerOffset                      pO1_ForTFCI_Bits;
    L1CAPI_PowerOffset                      pO3_ForPilotBits;
    L1CAPI_STTD_Indicator                   sTTD_Indicator;
} L1CAPI_SCCPCH_Phy_Info;

typedef struct L1CAPI_SCCPCH_Trch_Info {
    L1CAPI_CommonTranspChannelID            commonTransportChannelID;
    L1CAPI_DL_Power                         maxFACH_PCH_Power;
    L1CAPI_ToAWS                            toAWS;
    L1CAPI_ToAWE                            toAWE;
    L1CAPI_TransportFormatSet               tfsDL;
} L1CAPI_SCCPCH_Trch_Info;

typedef enum L1CAPI_PICH_Mode {
    L1CAPI_PichMode_v18 = 0,
    L1CAPI_PichMode_v36 = 1,
    L1CAPI_PichMode_v72 = 2,
    L1CAPI_PichMode_v144 = 3
} L1CAPI_PICH_Mode;

typedef struct L1CAPI_PICH_Params {
    L1CAPI_CommonPhyChannelID               commonPhysicalChannelID;
    L1CAPI_DL_ChannelCodeNumber             dl_ChannelisationCodeNumber;
    L1CAPI_PICH_Power                       pICH_Power;
    L1CAPI_PICH_Mode                        pICH_Mode;
    L1CAPI_STTD_Indicator                   sTTD_Indicator;
} L1CAPI_PICH_Params;

typedef struct L1CAPI_PCH_Info{
    L1CAPI_SCCPCH_Trch_Info commonParameters;
    L1CAPI_PICH_Params pichPhys;
} L1CAPI_PCH_Info;

typedef struct L1CAPI_RadioLink_CmnContextInfo {
    uint8_t                                 rlCount;
    uint8_t                                 coordTrchCount;
    uint8_t                                 tgpsCount;
} L1CAPI_RadioLink_CmnContextInfo;

typedef enum L1CAPI_DiversityControlField {
    L1CAPI_DIV_MAY_COMBINE = 0,
    L1CAPI_DIV_MUST_COMBINE = 1,
    L1CAPI_DIV_MUST_NOT_COMBINE = 2
} L1CAPI_DiversityControlField;

typedef enum L1CAPI_TxGapPatternSeqCodeInfo {
    L1CAPI_TX_GAP_CODE_CHANGE = 0,
    L1CAPI_TX_GAP_NO_CODE_CHANGE = 1
} L1CAPI_TxGapPatternSeqCodeInfo;

typedef struct L1CAPI_DL_CodeInfo{
    L1CAPI_ScramCodeNumber                  dl_ScramblingCode;
    L1CAPI_DL_ChannelCodeNumber             dL_ChannelisationCodeNumber;
    L1CAPI_TxGapPatternSeqCodeInfo          TransGapPatternSequenceCodeInfo;
} L1CAPI_DL_CodeInfo;

typedef enum {
        cfn_indication = 0,
        separate_indication = 1

} L1CAPI_DelayedActivation_TypeEnum;

typedef struct L1CAPI_DelayedActivation {
	L1CAPI_DelayedActivation_TypeEnum		delayedActivationType;
    L1CAPI_CFN                              cfn;  
} L1CAPI_DelayedActivation;



typedef enum L1CAPI_EDCH_RL_Indication{
        L1CAPI_RL_EDCH = 0,
        L1CAPI_RL_NON_EDCH = 1
} L1CAPI_EDCH_RL_Indication;

typedef struct L1CAPI_RL_Specific_EDCH_Info {
    uint8_t   bit_mask;
#define      e_AGCH_PowerOffset_present 0x80
#define      e_RGCH_PowerOffset_present 0x40
#define      e_HICH_PowerOffset_present 0x20
    /* optional; set in bit_mask e_AGCH_PowerOffset_present if present */
    L1CAPI_E_AGCH_PowerOffset               e_AGCH_PowerOffset;  
    /* optional; set in bit_mask e_RGCH_PowerOffset_present if present */
    L1CAPI_E_RGCH_PowerOffset               e_RGCH_PowerOffset;  
    /* optional; set in bit_mask e_HICH_PowerOffset_present if present */
    L1CAPI_E_HICH_PowerOffset               e_HICH_PowerOffset;  
} L1CAPI_RL_Specific_EDCH_Info;

typedef struct L1CAPI_EDCH_RL_InfoExtension {
    uint8_t                                 bit_mask;
#define      eDchRlInd_present 0x80
#define      rlSpecificEDchInfo_present 0x40
    /* optional; set in bit_mask eDchRlInd_present if present */
    L1CAPI_EDCH_RL_Indication               eDchRlInd;  
    /* optional; set in bit_mask rlSpecificEDchInfo_present if present */
    L1CAPI_RL_Specific_EDCH_Info            rlSpecificEDchInfo;  
} L1CAPI_EDCH_RL_InfoExtension;

typedef struct L1CAPI_RadioLink_Info {
    uint8_t                                 bit_mask;
#define      propagationDelay_present 0x80
#define      diversityControlField_present 0x40
#define      rl_info_transmitDiverIndicator_present 0x20
#define      delayedActivation_present 0x10
#define      eDchRlInfoExtension_present 0x08
    uint8_t                                 dlCodeCount;
    L1CAPI_Radiolink_ID                     rL_ID;
    L1CAPI_Cell_ID                          c_ID;
    uint8_t                                 firstRLS_indicator;
    L1CAPI_FrameOffset                      frameOffset;
    L1CAPI_ChipOffset                       chipOffset;
    /* optional; set in bit_mask propagationDelay_present if present */
    L1CAPI_PropagationDelay                 propagationDelay;
    /* optional; set in bit_mask diversityControlField_present if present */
    L1CAPI_DiversityControlField            diversityControlField;
    L1CAPI_DL_Power                         initialDL_transmissionPower;
    L1CAPI_DL_Power                         maximumDL_power;
    L1CAPI_DL_Power                         minimumDL_power;
    /* optional; set in bit_mask  rl_info_transmitDiverIndicator_present if present */
    L1CAPI_TSTD_Indicator                   transmitDiversityIndicator;  
    L1CAPI_DL_CodeInfo                      *ptrDlCodeInfo;
    /* optional; set in bit_mask delayedActivation_present if present */
    L1CAPI_DelayedActivation                delayedActivation;  
    /* optional; set in bit_mask eDchRlInfoExtension_present if present */
    L1CAPI_EDCH_RL_InfoExtension            *ptrEDchRlInfoExtension;  
} L1CAPI_RadioLink_Info;

typedef enum L1CAPI_PayloadCRC_Indicator {
    L1CAPI_CRC_INCLUDED = 0,
    L1CAPI_CRC_NOTINCLUDED = 1
} L1CAPI_PayloadCRC_Indicator;

typedef enum L1CAPI_UL_FP_Mode {
    L1CAPI_FPMODE_NORMAL = 0,
    L1CAPI_FPMODE_SILENT = 1
} L1CAPI_UL_FP_Mode;

typedef enum L1CAPI_Unidirectional_DCH_Indicator {    
    L1CAPI_Uplink_DCH_only = 0,
    L1CAPI_Dwonlink_DCH_only = 1    
} L1CAPI_Unidirectional_DCH_Indicator;

typedef enum L1CAPI_QE_Selector {
    L1CAPI_QE_SELECTED = 0,
    L1CAPI_QE_NON_SELECTED = 1
} L1CAPI_QE_Selector;

typedef struct L1CAPI_DCH_Info{
    uint8_t                                 bit_mask;
#define      tfsDL_present 0x80
#define      tfsUL_present 0x40
    L1CAPI_DCH_ID                           dCH_ID;
    L1CAPI_QE_Selector                      qE_Selector;
    /*L1CAPI_Unidirectional_DCH_Indicator     uniDirDchInd;*/
    /* optional; set in bit_mask tfsDL_present if present */    
    L1CAPI_TransportFormatSet               *ptrTfsDL;  
    /* optional; set in bit_mask tfsUL_present if present */    
    L1CAPI_TransportFormatSet               *ptrTfsUL;  
} L1CAPI_DCH_Info;

typedef struct L1CAPI_DCH_CoordTrchInfoListItem {
    uint8_t                                 bit_mask;
#define toAws_present       0x80
#define toAwe_present       0x40
#define payloadCRC_presenceIndicator_present 0x20
#define ulFpMode_present                     0x10
    uint8_t                                 dchCount;
    /*optional;set in bit_mask oAws_present if present */
    L1CAPI_ToAWS                            toAWS;
    /*optional;set in bit_mask toAwe_present if present */
    L1CAPI_ToAWE                            toAWE;    
    /*optional;set in bit_mask payloadCRC_presenceIndicator_present if present */
    L1CAPI_PayloadCRC_Indicator             payloadCRC_PresenceIndicator;    
    /*optional;set in bit_mask ulFpMode_present if present */
    L1CAPI_UL_FP_Mode                       ul_FP_Mode;
    L1CAPI_DCH_Info                         *ptrDCHSpecificInfo;
} L1CAPI_DCH_CoordTrchInfoListItem;

typedef struct L1CAPI_PowerOffsetInfo{
    L1CAPI_PowerOffset                      pO1_ForTFCI_Bits;
    L1CAPI_PowerOffset                      pO2_ForTPC_Bits;
    L1CAPI_PowerOffset                      pO3_ForPilotBits;
} L1CAPI_PowerOffsetInfo;

typedef enum L1CAPI_TPC_DownlinkStepSize {
    L1CAPI_TPC_STEP_SIZE0_5 = 0,
    L1CAPI_TPC_STEP_SIZE1 = 1,
    L1CAPI_TPC_STEP_SIZE1_5 = 2,
    L1CAPI_TPC_STEP_SIZE2 = 3
} L1CAPI_TPC_DownlinkStepSize;

typedef enum L1CAPI_LimitedPowerIncrease {
    L1CAPI_LIMITED_PWR_INC_USED = 0,
    L1CAPI_LIMITED_PWR_INC_NOT_USED = 1
} L1CAPI_LimitedPowerIncrease;

typedef enum L1CAPI_InnerLoopDLPCStatus {
    L1CAPI_INNERLOOPDLPC_ACTIVE = 0,
    L1CAPI_INNERLOOPDLPC_INACTIVE = 1
} L1CAPI_InnerLoopDLPCStatus;

typedef enum L1CAPI_MinUL_ChanneCodeLength {
    L1CAPI_MINUL_CHANNELCODE_LEN_v4 = 0,
    L1CAPI_MINUL_CHANNELCODE_LEN_v8 = 1,
    L1CAPI_MINUL_CHANNELCODE_LEN_v16 = 2,
    L1CAPI_MINUL_CHANNELCODE_LEN_v32 = 3,
    L1CAPI_MINUL_CHANNELCODE_LEN_v64 = 4,
    L1CAPI_MINUL_CHANNELCODE_LEN_v128 = 5,
    L1CAPI_MINUL_CHANNELCODE_LEN_v256 = 6
} L1CAPI_MinUL_ChanneCodeLength;

typedef struct L1CAPI_DL_DPCH_PhyInfo{
    uint8_t                                 bit_mask;
#define      DL_DPCH_RL_Setup_tFCI_present 0x80
    L1CAPI_DL_DPCH_SlotFormat               dl_DPCH_SlotFormat;
    /* optional; set in bit_mask DL_DPCH_If_RL_SRt_tFCI__present if present */
    uint8_t                                 tFCI_Presence;      
    L1CAPI_MultiplexingPosition             multiplexingPosition;
    L1CAPI_PowerOffsetInfo                  powerOffsetInformation;
    L1CAPI_TPC_DownlinkStepSize             tPC_DownlinkStepSize;
    L1CAPI_LimitedPowerIncrease             limitedPowerIncrease;
    L1CAPI_InnerLoopDLPCStatus              innerLoopDLPCStatus;
} L1CAPI_DL_DPCH_PhyInfo;

typedef struct L1CAPI_DL_DPCH_PhyInfo_Reconfig{
    uint8_t                                 bit_mask;
#define      DL_DPCH_RL_Reconfig_SlotFormat_present 0x80
#define      DL_DPCH_RL_Reconfig_tFCI_present 0x40
#define      DL_DPCH_RL_Reconfig_MuxPos_present 0x20
#define      DL_DPCH_RL_Reconfig_LimitedPwrInc_present 0x10
    /* optional; set in bit_mask DL_DPCH_RL_Reconfig_SlotFormat_present if present */
    L1CAPI_DL_DPCH_SlotFormat               dl_DPCH_SlotFormat;
    /* optional; set in bit_mask DL_DPCH_RL_Reconfig_tFCI_present if present */
    uint8_t                                 tFCI_Presence;      
    /* optional; set in bit_mask DL_DPCH_RL_Reconfig_MuxPos_present if present */
    L1CAPI_MultiplexingPosition             multiplexingPosition;
    /* optional; set in bit_mask DL_DPCH_RL_Reconfig_LimitedPwrInc_present if present */
    L1CAPI_LimitedPowerIncrease             limitedPowerIncrease;
} L1CAPI_DL_DPCH_PhyInfo_Reconfig;

typedef enum L1CAPI_DiversityMode {
    L1CAPI_DIV_NONE = 0,
    L1CAPI_DIV_STTD = 1,
    L1CAPI_DIV_CLOSED_LOOP_MODE1 = 2,
    L1CAPI_DIV_NOT_USE_CLOSED_LOOP_MODE2 = 3
} L1CAPI_DiversityMode;

typedef enum L1CAPI_DPC_Mode {
    L1CAPI_DPC_MODE0 = 0,
    L1CAPI_DPC_MODE1 = 1
} L1CAPI_DPC_Mode;

typedef enum L1CAPI_ULDPDCH_Ind_EDCH{
    L1CAPI_UL_DPDCH_PRESENT = 0,
    L1CAPI_UL_DPDCH_NOT_PRESENT = 1
} L1CAPI_ULDPDCH_Ind_EDCH;

typedef enum L1CAPI_UL_ScramblingCodeLength {
    L1CAPI_UL_SCRAMCODELENGTH_SHORT = 0,
    L1CAPI_UL_SCRAMCODELENGTH_LONG = 1
} L1CAPI_UL_ScramblingCodeLength;

typedef struct L1CAPI_UL_ScramCodeInfo {
    L1CAPI_UL_ScramCode                     uL_ScramblingCodeNumber;
    L1CAPI_UL_ScramblingCodeLength          uL_ScramblingCodeLength;
} L1CAPI_UL_ScramCodeInfo;

typedef struct L1CAPI_UL_DPCH_PhyInfo {
    uint8_t                                 bit_mask;
#define      UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present 0x80
#define      UL_DPCH_Setup_DpcMode_present 0x40
#define      UL_DPCH_Setup_IndEDch_present 0x20
    L1CAPI_UL_ScramCodeInfo                 ul_ScramblingCodeInfo;
    L1CAPI_MinUL_ChanneCodeLength           minUL_ChannelisationCodeLength;
    /* optional; set in bit_mask UL_DPCH_Setup_MaxNrOfUL_DPDCHs_present if present */    
    L1CAPI_MaxNrOfUL_DPDCHs                 maxNrOfUL_DPDCHs;  
    L1CAPI_PunctureLimit                    ul_PunctureLimit;
    L1CAPI_UL_DPCCH_SlotFormat              ul_DPCCH_SlotFormat;
    L1CAPI_UL_SIR                           ul_SIR_Target;
    L1CAPI_DiversityMode                    diversityMode;
    /* optional; set in bit_mask UL_DPCH_Setup_DpcMode_present if present */
    L1CAPI_DPC_Mode                         dpcMode;  
    /* optional; set in bit_mask UL_DPCH_Setup_IndEDch_present if present */    
    L1CAPI_ULDPDCH_Ind_EDCH                 ulDpdchIndEDch;  
} L1CAPI_UL_DPCH_PhyInfo;

typedef struct L1CAPI_UL_DPCH_PhyInfo_Reconfig {
    uint8_t                                 bit_mask;
#define      UL_DPCH_Reconfig_UlScramCodeInfo_present 0x80
#define      UL_DPCH_Reconfig_MinChanCodeLen_present 0x40
#define      UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present 0x20
#define      UL_DPCH_Reconfig_UlPuncLimit_present 0x10
#define      UL_DPCH_Reconfig_UlSlotFormat_present 0x08
#define      UL_DPCH_Reconfig_UlSIR_present 0x04
#define      UL_DPCH_Reconfig_DiversityMode_present 0x02
#define      UL_DPCH_Reconfig_IndEDch_present 0x01
    /* optional; set in bit_mask UL_DPCH_Reconfig_UlScramCode_present if present */    
    L1CAPI_UL_ScramCodeInfo                 ul_ScramblingCodeInfo;
    /* optional; set in bit_mask    UL_DPCH_Reconfig_MinChanCodeLen_present if present */    
    L1CAPI_MinUL_ChanneCodeLength           minUL_ChannelisationCodeLength;
    /* optional; set in bit_mask UL_DPCH_Reconfig_MaxNrOfUL_DPDCHs_present if present */    
    L1CAPI_MaxNrOfUL_DPDCHs                 maxNrOfUL_DPDCHs;  
    /* optional; set in bit_mask UL_DPCH_Reconfig_UlPuncLimit_present if present */    
    L1CAPI_PunctureLimit                    ul_PunctureLimit;
    /* optional; set in bit_mask UL_DPCH_Reconfig_UlSlotFormat_present if present */    
    L1CAPI_UL_DPCCH_SlotFormat              ul_DPCCH_SlotFormat;
    /* optional; set in bit_mask UL_DPCH_Reconfig_UlSIR_present if present */    
    L1CAPI_UL_SIR                           ul_SIR_Target;
    /* optional; set in bit_mask UL_DPCH_Reconfig_DiversityMode_present if present */    
    L1CAPI_DiversityMode                    diversityMode;
    /* optional; set in bit_mask UL_DPCH_Reconfig_IndEDch_present if present */    
    L1CAPI_ULDPDCH_Ind_EDCH                 ulDpdchIndEDch;  
} L1CAPI_UL_DPCH_PhyInfo_Reconfig;

typedef enum L1CAPI_GAP_ULDL_mode {
    L1CAPI_GAP_UL_ONLY = 0,
    L1CAPI_GAP_DL_ONLY = 1,
    L1CAPI_GAP_BOTH_ULDL = 2
} L1CAPI_GAP_ULDL_mode;

typedef enum L1CAPI_DL_CompressedMode_Method {
    L1CAPI_DL_CMPRSMOD_NO_PUNCTURING = 0,
    L1CAPI_DL_CMPRSMOD_SFDIV2 = 1,
    L1CAPI_DL_CMPRSMOD_HILAYER_SCHDU = 2
} L1CAPI_DL_CompressedMode_Method;

typedef enum L1CAPI_UL_CompressedMode_Method {
    L1CAPI_UL_CMPRSMOD_SFDIV2 = 0,
    L1CAPI_UL_CMPRSMOD_HILAYER_SCHDU = 1
} L1CAPI_UL_CompressedMode_Method;

typedef enum L1CAPI_DL_FrameType {
    L1CAPI_DL_FRAMETYPE_A = 0,
    L1CAPI_DL_FRAMETYPE_B = 1
} L1CAPI_DL_FrameType ;

typedef struct L1CAPI_TxGap_SeqInfo {
    uint8_t                                 bit_mask;
#define      tGL2_present 0x80
#define      downlink_Compressed_Mode_Method_present 0x40
#define      uplink_Compressed_Mode_Method_present 0x20
#define      delta_SIR2_present 0x10
#define      delta_SIR_after2_present 0x08
    L1CAPI_TGPSID                           tGPSID;
    L1CAPI_TGSN                             tGSN;
    L1CAPI_GapLength                        tGL1;
    /* optional; set in bit_mask tGL2_present if present */
    L1CAPI_GapLength                        tGL2;  
    L1CAPI_TGD                              tGD;
    L1CAPI_GapDuration                      tGPL1;
    L1CAPI_GAP_ULDL_mode                    uL_DL_mode;
    /* optional; set in bit_mask downlink_Compressed_Mode_Method_present if present */    
    L1CAPI_DL_CompressedMode_Method         downlink_Compressed_Mode_Method;
    /* optional; set in bit_mask uplink_Compressed_Mode_Method_present if present */    
    L1CAPI_UL_CompressedMode_Method         uplink_Compressed_Mode_Method;  
    L1CAPI_DL_FrameType                     dL_FrameType;
    L1CAPI_DeltaSIR                         delta_SIR1;
    L1CAPI_DeltaSIR                         delta_SIR_after1;
    /* optional; set in bit_mask delta_SIR2_present if present */    
    L1CAPI_DeltaSIR                         delta_SIR2;  
    /* optional; set in bit_mask delta_SIR_after2_present if present */    
    L1CAPI_DeltaSIR                         delta_SIR_after2;  
} L1CAPI_TxGap_SeqInfo;

typedef enum L1CAPI_PowerAdjustmentType {
    L1CAPI_PWRADJUST_TYPE_NONE = 0,
    L1CAPI_PWRADJUST_TYPE_COMMON = 1,
    L1CAPI_PWRADJUST_TYPE_INDIVIDUAL = 2
} L1CAPI_PowerAdjustmentType;

typedef enum L1CAPI_ClkSource {
    L1CAPI_CLKSRC_NONE        = 0,
    L1CAPI_CLKSRC_EXT_10MHZ   = 1,
    L1CAPI_CLKSRC_INVALID     = 2    
}L1CAPI_ClkSource;

typedef struct L1CAPI_DL_PowerAdjustInfo {
    uint8_t                                 bit_mask;
#define      maxAdjustmentStep_present 0x80
#define      adjustmentPeriod_present 0x40
#define      adjustmentRatio_present 0x20
    /* This IE shall be present if Power Adjustment Type IE equals to 'Common'    */
    /* optional; set in bit_mask maxAdjustmentStep_present if present */
    L1CAPI_MaxAdjustmentStep                maxAdjustmentStep;  
    /* This IE shall be present if Adjustment Type IE equals to 'Common' or 'Individual' */
    /* optional; set in bit_mask pwrAdj_adjustmentPeriod_present if present */    
    L1CAPI_AdjustmentPeriod                 adjustmentPeriod;  
    /* This IE shall be present if Power Adjustment Type IE equals to 'Common' or 'Individual' */
    /* optional; set in bit_mask adjustmentRatio_present if present */    
    L1CAPI_ScaledAdjustmentRatio            adjustmentRatio;  
} L1CAPI_DL_PowerAdjustInfo;

typedef struct L1CAPI_DL_PowerBalancing_Info_Common {
    L1CAPI_DL_Power                         dLReferencePower;
    L1CAPI_DL_PowerAdjustInfo               adjustInfo;
} L1CAPI_DL_PowerBalancing_Info_Common;

typedef struct DL_PC_RefPowerInfoItem {
    L1CAPI_Radiolink_ID                     rL_ID;
    L1CAPI_DL_Power                         dl_ReferencePower;
} DL_PC_RefPowerInfoItem;

typedef struct L1CAPI_DL_PowerBalancing_Info_Individual {
    uint8_t                                 rlCount;
    DL_PC_RefPowerInfoItem                  *ptrDlRefPwrInfo;
    L1CAPI_DL_PowerAdjustInfo               adjustInfo;
} L1CAPI_DL_PowerBalancing_Info_Individual;

typedef struct L1CAPI_DL_PowerBalancing_Info {
    uint8_t                                 bit_mask;
#define      powerAdjCommon_present 0x80
#define      powerAdjIndividual_present 0x40
    L1CAPI_PowerAdjustmentType              powerAdjustmentType;
    /* optional; set in bit_mask powerAdjCommon_present if present */
    L1CAPI_DL_PowerBalancing_Info_Common    *ptrPowerAdjCommon;
    /* optional; set in bit_mask powerAdjIndividual_present if present */    
    L1CAPI_DL_PowerBalancing_Info_Individual *ptrPowerAdjIndividual;  
} L1CAPI_DL_PowerBalancing_Info;

typedef enum L1CAPI_CQI_Feedback_Cycle {
    L1CAPI_CQI_FEEDBACK_CYCLE_V0 = 0,
    L1CAPI_CQI_FEEDBACK_CYCLE_V2 = 2,
    L1CAPI_CQI_FEEDBACK_CYCLE_V4 = 4,
    L1CAPI_CQI_FEEDBACK_CYCLE_V8 = 8,
    L1CAPI_CQI_FEEDBACK_CYCLE_V10 = 10,
    L1CAPI_CQI_FEEDBACK_CYCLE_V20 = 20,
    L1CAPI_CQI_FEEDBACK_CYCLE_V40 = 40,
    L1CAPI_CQI_FEEDBACK_CYCLE_V80 = 80,
    L1CAPI_CQI_FEEDBACK_CYCLE_V160 = 160,
    L1CAPI_CQI_FEEDBACK_CYCLE_V16 = 16,
    L1CAPI_CQI_FEEDBACK_CYCLE_V32 = 32,
    L1CAPI_CQI_FEEDBACK_CYCLE_V64 = 64
} L1CAPI_CQI_Feedback_Cycle;

typedef enum L1CAPI_T1 {
    L1CAPI_T1_V10 = 10,
    L1CAPI_T1_V20 = 20,
    L1CAPI_T1_V30 = 30,
    L1CAPI_T1_V40 = 40,
    L1CAPI_T1_V50 = 50,
    L1CAPI_T1_V60 = 60,
    L1CAPI_T1_V70 = 70,
    L1CAPI_T1_V80 = 80,
    L1CAPI_T1_V90 = 90,
    L1CAPI_T1_V100 = 100,
    L1CAPI_T1_V120 = 120,
    L1CAPI_T1_V140 = 140,
    L1CAPI_T1_V160 = 160,
    L1CAPI_T1_V200 = 200,
    L1CAPI_T1_V300 = 300,
    L1CAPI_T1_V400 = 400
} L1CAPI_T1;

typedef enum L1CAPI_DiscardTimer {
    L1CAPI_DISCARDTIMER_V20 = 20,
    L1CAPI_DISCARDTIMER_V40 = 40,
    L1CAPI_DISCARDTIMER_V60 = 60,
    L1CAPI_DISCARDTIMER_V80 = 80,
    L1CAPI_DISCARDTIMER_V100 = 100,
    L1CAPI_DISCARDTIMER_V120 = 120,
    L1CAPI_DISCARDTIMER_V140 = 140,
    L1CAPI_DISCARDTIMER_V160 = 160,
    L1CAPI_DISCARDTIMER_V180 = 180,
    L1CAPI_DISCARDTIMER_V200 = 200,
    L1CAPI_DISCARDTIMER_V250 = 250,
    L1CAPI_DISCARDTIMER_V300 = 300,
    L1CAPI_DISCARDTIMER_V400 = 400,
    L1CAPI_DISCARDTIMER_V500 = 500,
    L1CAPI_DISCARDTIMER_V750 = 750,
    L1CAPI_DISCARDTIMER_V1000 = 1000,
    L1CAPI_DISCARDTIMER_V1250 = 1250,
    L1CAPI_DISCARDTIMER_V1500 = 1500,
    L1CAPI_DISCARDTIMER_V1750 = 1750,
    L1CAPI_DISCARDTIMER_V2000 = 2000,
    L1CAPI_DISCARDTIMER_V2500 = 2500,
    L1CAPI_DISCARDTIMER_V3000 = 3000,
    L1CAPI_DISCARDTIMER_V3500 = 3500,
    L1CAPI_DISCARDTIMER_V4000 = 4000,
    L1CAPI_DISCARDTIMER_V4500 = 4500,
    L1CAPI_DISCARDTIMER_V5000 = 5000,
    L1CAPI_DISCARDTIMER_V7500 = 7500
} L1CAPI_DiscardTimer;

typedef enum L1CAPI_MAC_hsWindowSize {
    L1CAPI_MAC_HSWINDOWSIZE_V4 = 4,
    L1CAPI_MAC_HSWINDOWSIZE_V6 = 6,
    L1CAPI_MAC_HSWINDOWSIZE_V8 = 8,
    L1CAPI_MAC_HSWINDOWSIZE_V12 = 12,
    L1CAPI_MAC_HSWINDOWSIZE_V16 = 16,
    L1CAPI_MAC_HSWINDOWSIZE_V24 = 24,
    L1CAPI_MAC_HSWINDOWSIZE_V32 = 32
} L1CAPI_MAC_hsWindowSize;

typedef enum L1CAPI_RLC_Mode {
    L1CAPI_RLC_AM = 0,
    L1CAPI_RLC_UM = 1
} L1CAPI_RLC_Mode;

typedef enum L1CAPI_RLFailure_Cause {
    L1CAPI_RADIOLINK_FAILURE_SYNC_FAILURE=0,
    L1CAPI_RADIOLINK_FAILURE_INVALID_CM_SETTINGS
} L1CAPI_RLFailure_Cause;

typedef struct L1CAPI_MACDPDU_Size_IndexItem {
    L1CAPI_SID                              sID;
    L1CAPI_MACdPDU_Size                     macdPDU_Size;
} L1CAPI_MACDPDU_Size_IndexItem;

typedef struct L1CAPI_PriorityQueue_Info {
    uint8_t                                 bit_mask;
#define      t1_present 0x80
#define      discardTimer_present 0x40
#define      mac_hsWindowSz_present 0x20
#define      mAChsGuaranteedBitRate_present 0x10
#define      rlMode_present 0x08
#define      associatedHSDSCH_MACdFlow_present 0x04

    L1CAPI_PriorityQueue_Id                 priorityQueueId;
    L1CAPI_SchedulingPriorityIndicator      schedulingPriorityIndicator;
    /* optional; set in bit_mask t1_present if present */    
    L1CAPI_T1                               t1;
    /* optional; set in bit_mask discardTimer_present if present */    
    L1CAPI_DiscardTimer                     discardTimer;  
    /* optional; set in bit_mask mac_hsWindowSz_present if present */    
    L1CAPI_MAC_hsWindowSize                 mAC_hsWindowSize;
    /* optional; set in bit_mask mAChsGuaranteedBitRate_present if present */        
    L1CAPI_MAChsGuaranteedBitRate           mAChsGuaranteedBitRate;        
    /* optional; set in bit_mask rlMode_present if present */        
    L1CAPI_RLC_Mode                         rLC_Mode;
    /* optional; set in bit_mask associatedHSDSCH_MACdFlow_present if present */
    L1CAPI_HSDSCH_MACdFlow_ID               associatedHSDSCH_MACdFlow;
    uint8_t                                 macDPduIndexCount;
    L1CAPI_MACDPDU_Size_IndexItem           *ptrMacdPDU_Size_Index;
} L1CAPI_PriorityQueue_Info;

typedef enum L1CAPI_PriorityQueue_Adj_Type {
    L1CAPI_PRI_QUEUE_ADD,
    L1CAPI_PRI_QUEUE_MOD,
    L1CAPI_PRI_QUEUE_DEL
} L1CAPI_PriorityQueue_Adj_Type;

typedef struct L1CAPI_PriorityQueue_Reconfig_Info {
    L1CAPI_PriorityQueue_Adj_Type           priQueueAdjType;
    union{
        L1CAPI_PriorityQueue_Info           *ptrPriorityQueueAdd_Info;
        L1CAPI_PriorityQueue_Info           *ptrPriorityQueueMod_Info;
        L1CAPI_PriorityQueue_Id             priorityQueueDel_Info;
    }u;
} L1CAPI_PriorityQueue_Reconfig_Info;

typedef struct L1CAPI_HSDSCH_MACdFlows_Info {
    uint8_t                                 macDFlowCount;
    uint8_t                                 priorityQueueCount;
    L1CAPI_HSDSCH_MACdFlow_ID               *ptrHDSCH_MACdFlow_Info;
    L1CAPI_PriorityQueue_Info               *ptrPriorityQueue_Info;
} L1CAPI_HSDSCH_MACdFlows_Info;

typedef struct L1CAPI_HSDSCH_MACdFlows_Reconfig_Info {
    uint8_t                                 macDFlowCount;
    uint8_t                                 priorityQueueCount;
    L1CAPI_HSDSCH_MACdFlow_ID               *ptrHDSCH_MACdFlow_Info;
    L1CAPI_PriorityQueue_Reconfig_Info      *ptrPriorityQueue_Info;
} L1CAPI_HSDSCH_MACdFlows_Reconfig_Info;

typedef struct L1CAPI_HSDSCH_MACdFlows_Delete_Info {
    uint8_t                                 macDFlowCount;
    L1CAPI_HSDSCH_MACdFlow_ID               *ptrHDSCH_MACdFlow_Info;
} L1CAPI_HSDSCH_MACdFlows_Delete_Info;

typedef struct L1CAPI_RadioLink_HSDSCH_Info {
    uint8_t                                 bit_mask;
#define      hsscch_PowerOffset_present 0x80
#define      measurement_Power_Offset_present 0x40
    uint8_t                                 hsdcschPhysCat;
    L1CAPI_MAChsReorderBufferSize_RLC_UM    macHsReorderBuffSz;
    L1CAPI_CQI_Feedback_Cycle               cqiFeedback_CycleK;
    L1CAPI_CQI_RepetitionFactor             cqiRepetitionFactor;
    L1CAPI_AckNack_RepetitionFactor         ackNackRepetitionFactor;
    L1CAPI_CQI_Power_Offset                 cqiPowerOffset;
    L1CAPI_Ack_Power_Offset                 ackPowerOffset;
    L1CAPI_Nack_Power_Offset                nackPowerOffset;
    /* optional; set in bit_mask hsscch_PowerOffset_present if present */    
    L1CAPI_HSSCCH_PowerOffset               hsscch_PowerOffset;  
    /* optional; set in bit_mask measurement_Power_Offset_present if present */    
    L1CAPI_Measurement_Power_Offset         measurement_Power_Offset;
    L1CAPI_HSDSCH_MACdFlows_Info            hsdschMacDFlowInfo;
} L1CAPI_RadioLink_HSDSCH_Info;

typedef struct L1CAPI_RadioLink_HSDSCH_Reconfig_Info {
    uint16_t                                bit_mask;
#define      macHsReorderBufSz_present 0x8000
#define      cqiFeedbackCycle_present 0x4000
#define      cqiRepetitionFactor_present  0x2000
#define      ackNackRepetitionFactor_present  0x1000
#define      cqiPO_present            0x0800
#define      ackPO_present            0x0400
#define      nackPO_present           0x0200
#define      hsscchPO_present         0x0100
#define      measmentPO_present       0x0080
#define      hsdschMacDFlowReconfigInfo_present 0x0040    
    /* optional; set in bit_mask macHsReorderBufSz_present if present */    
    L1CAPI_MAChsReorderBufferSize_RLC_UM    macHsReorderBuffSz;
    /* optional; set in bit_mask cqiFeedbackCycle_present if present */    
    L1CAPI_CQI_Feedback_Cycle               cqiFeedback_CycleK;
    /* optional; set in bit_mask cqiRepetitionFactor_present if present */    
    L1CAPI_CQI_RepetitionFactor             cqiRepetitionFactor;
    /* optional; set in bit_mask ackNackRepetitionFactor_present if present */    
    L1CAPI_AckNack_RepetitionFactor         ackNackRepetitionFactor;
    /* optional; set in bit_mask cqiPO_present if present */    
    L1CAPI_CQI_Power_Offset                 cqiPowerOffset;
    /* optional; set in bit_mask ackPO_present if present */    
    L1CAPI_Ack_Power_Offset                 ackPowerOffset;
    /* optional; set in bit_mask nackPO_present if present */    
    L1CAPI_Nack_Power_Offset                nackPowerOffset;
    /* optional; set in bit_mask hsscchPO_present if present */    
    L1CAPI_HSSCCH_PowerOffset               hsscch_PowerOffset;  
    /* optional; set in bit_mask measmentPO_present if present */    
    L1CAPI_Measurement_Power_Offset         measurement_Power_Offset;
    /* optional; set in bit_mask hsdschMacDFlowReconfigInfo_present if present */    
    L1CAPI_HSDSCH_MACdFlows_Reconfig_Info   *ptrHsdschMacDFlowReconfigInfo;
} L1CAPI_RadioLink_HSDSCH_Reconfig_Info;

typedef struct L1CAPI_Radiolink_HSDSCH_Config{
    uint8_t                                 bit_mask;
#define HSDSCH_CONFIG_HsdschInfo_present   0x80
    L1CAPI_HSDSCH_RNTI                      hsDschRnti;
    L1CAPI_Radiolink_ID                     hsPschRlId;
    /* optional; set in bit_mask HSDSCH_CONFIG_HsdschInfo_present if present */    
    L1CAPI_RadioLink_HSDSCH_Info            *ptrHdschInfo;
} L1CAPI_Radiolink_HSDSCH_Config;

typedef struct L1CAPI_Radiolink_HSDSCH_Reconfig{
    uint8_t                                 bit_mask;
#define HSDSCH_RECONFIG_Rnti_present   0x80
#define HSDSCH_RECONFIG_Rlid_present   0x40
#define HSDSCH_RECONFIG_HsdschInfo_present   0x20
#define HSDSCH_RECONFIG_HsdschModify_present   0x10
#define HSDSCH_RECONFIG_HsdschMacDFlowAdd_present   0x08
#define HSDSCH_RECONFIG_HsdschMacDFlowDel_present   0x04
    /* optional; set in bit_mask HSDSCH_RECONFIG_Rnti_present if present */    
    L1CAPI_HSDSCH_RNTI                      hsDschRnti;
    /* optional; set in bit_mask HSDSCH_RECONFIG_Rlid_present if present */    
    L1CAPI_Radiolink_ID                     hsPschRlId;
    /* optional; set in bit_mask HSDSCH_RECONFIG_HsdschInfo_present if present */    
    L1CAPI_RadioLink_HSDSCH_Info            *ptrHdschInfo;
    /* optional; set in bit_mask HSDSCH_RECONFIG_HsdschModify_present if present */    
    L1CAPI_RadioLink_HSDSCH_Reconfig_Info   *ptrHsdschModify;/*Octasic Not Implement yet*/
    /* optional; set in bit_mask HSDSCH_RECONFIG_HsdschMacDFlowAdd_present if present */    
    L1CAPI_HSDSCH_MACdFlows_Info            *ptrHsdschMacDFlowAdd;
    /* optional; set in bit_mask HSDSCH_RECONFIG_HsdschMacDFlowDel_present if present */
    L1CAPI_HSDSCH_MACdFlows_Delete_Info     *ptrHsdschMacDFlowDel;	
} L1CAPI_Radiolink_HSDSCH_Reconfig;

typedef enum L1CAPI_Max_Set_EDPDCHs {
    L1CAPI_MAX_SET_EDPDCH_VN256 = 0,
    L1CAPI_MAX_SET_EDPDCH_VN128 = 1,
    L1CAPI_MAX_SET_EDPDCH_VN64 = 2,
    L1CAPI_MAX_SET_EDPDCH_VN32 = 3,
    L1CAPI_MAX_SET_EDPDCH_VN16 = 4,
    L1CAPI_MAX_SET_EDPDCH_VN8 = 5,
    L1CAPI_MAX_SET_EDPDCH_VN4 = 6,
    L1CAPI_MAX_SET_EDPDCH_V2XN4 = 7,
    L1CAPI_MAX_SET_EDPDCH_VN2XN2 = 8,
    L1CAPI_MAX_SET_EDPDCH_VN2XN2_PLUS_2XN4 = 9,
    L1CAPI_MAX_SET_EDPDCH_VN2XM2_PLUS_2XM4 = 10
} L1CAPI_Max_Set_EDPDCHs;

typedef enum L1CAPI_E_TTI {
    L1CAPI_E_TTI_10MS,
	L1CAPI_E_TTI_2MS
} L1CAPI_E_TTI;

typedef enum L1CAPI_HARQ_Info_for_E_DCH {
    L1CAPI_HARQ_EDCH_RV0 = 0,
    L1CAPI_HARQ_EDCH_RVTABLE = 1
} L1CAPI_HARQ_Info_for_E_DCH;

typedef enum L1CAPI_HSDSCH_Configured_Indicator {
    L1CAPI_CONFIGURED_HS_DSCH = 0,
    L1CAPI_NO_CONFIGURED_HS_DSCH= 1
} L1CAPI_HSDSCH_Configured_Indicator;

typedef struct L1CAPI_Ref_E_TFCI_InfoItem {
    L1CAPI_E_TFCI                           reference_E_TFCI;
    L1CAPI_Reference_E_TFCI_PO              reference_E_TFCI_PO;
} L1CAPI_Ref_E_TFCI_InfoItem;

typedef struct L1CAPI_E_TFCS_Info {
    uint8_t                                 bit_mask;
#define      e_DCH_Min_Set_E_TFCI_present 0x80
    L1CAPI_E_DCH_TFCI_Table_Index           e_DCH_TFCI_Table_Index;
    /* optional; set in bit_mask e_DCH_Min_Set_E_TFCI_present if present */
    L1CAPI_E_TFCI                           e_DCH_Min_Set_E_TFCI;  
    uint8_t                                 refETfciCount;
    L1CAPI_Ref_E_TFCI_InfoItem              *ptrReference_E_TFCI_Information;
} L1CAPI_E_TFCS_Info;

typedef struct L1CAPI_Radiolink_EDpch_Info {
    L1CAPI_Max_Set_EDPDCHs                  maxSet_E_DPDCHs;
    L1CAPI_PunctureLimit                    ul_PunctureLimit;
    L1CAPI_E_TTI                            e_TTI;
    L1CAPI_E_DPCCH_PO                       e_DPCCH_PowerOFfset;
    L1CAPI_E_RGCH_2_IndexStepThreshold      e_RGCH_2_IndexStepThreshold;
    L1CAPI_E_RGCH_3_IndexStepThreshold      e_RGCH_3_IndexStepThreshold;
    L1CAPI_HARQ_Info_for_E_DCH              hARQ_Info_for_E_DCH;
    L1CAPI_HSDSCH_Configured_Indicator      hSDSCH_Configured_Indicator;
    L1CAPI_E_TFCS_Info                      e_TFCS_Information;
} L1CAPI_Radiolink_EDpch_Info;

typedef struct L1CAPI_Radiolink_EDpch_Reconfig_Info {
    uint16_t                                 bit_mask;
#define   Edpch_Reconfig_MaxSetEdpchs_present   0x8000
#define   Edpch_Reconfig_PuncLimit_present   0x4000
#define   Edpch_Reconfig_ETTI_present   0x2000
#define   Edpch_Reconfig_PwrOffset_present   0x1000
#define   Edpch_Reconfig_Rgch2Threshold_present   0x0800
#define   Edpch_Reconfig_Rgch3Threshold_present   0x0400
#define   Edpch_Reconfig_HarqInfo_present   0x0200
#define   Edpch_Reconfig_HsdschConfigInd_present   0x0100
#define   Edpch_Reconfig_ETfcsInfo_present   0x0080
    /* optional; set in bit_mask Edpch_Reconfig_MaxSetEdpchs_present if present */
    L1CAPI_Max_Set_EDPDCHs                  maxSet_E_DPDCHs;
    /* optional; set in bit_mask Edpch_Reconfig_PuncLimit_present if present */
    L1CAPI_PunctureLimit                    ul_PunctureLimit;
    /* optional; set in bit_mask Edpch_Reconfig_ETTI_present if present */
    L1CAPI_E_TTI                            e_TTI;
    /* optional; set in bit_mask Edpch_Reconfig_PwrOffset_present if present */
    L1CAPI_E_DPCCH_PO                       e_DPCCH_PowerOFfset;
    /* optional; set in bit_mask Edpch_Reconfig_Rgch2Threshold_present if present */
    L1CAPI_E_RGCH_2_IndexStepThreshold      e_RGCH_2_IndexStepThreshold;
    /* optional; set in bit_mask Edpch_Reconfig_Rgch3Threshold_present if present */
    L1CAPI_E_RGCH_3_IndexStepThreshold      e_RGCH_3_IndexStepThreshold;
    /* optional; set in bit_mask Edpch_Reconfig_HarqInfo_present if present */
    L1CAPI_HARQ_Info_for_E_DCH              hARQ_Info_for_E_DCH;
    /* optional; set in bit_mask Edpch_Reconfig_HsdschConfigInd_present if present */
    L1CAPI_HSDSCH_Configured_Indicator      hSDSCH_Configured_Indicator;
    /* optional; set in bit_mask Edpch_Reconfig_ETfcsInfo_present if present */
    L1CAPI_E_TFCS_Info                      *ptr_ETFCS_Information;
} L1CAPI_Radiolink_EDpch_Reconfig_Info;

typedef uint8_t L1CAPI_HARQ_Process_Alloc_2ms_EDCH;

typedef enum L1CAPI_E_DCH_Grant_Type {
    L1CAPI_EDCH_GRANTTYPE_NON_SCHEDULED = 0,
    L1CAPI_EDCH_GRANTTYPE_SCHEDULED= 1
} L1CAPI_E_DCH_Grant_Type;

typedef uint8_t L1CAPI_E_DCH_MACdFlow_Multiplexing;

typedef struct L1CAPI_E_DCH_NonScheduled_TxGrantItems {
    uint8_t                                 bit_mask;
#define      hARQ_Ps_An_NnSchd_2ms_present 0x80
    L1CAPI_Max_Bits_MACe_PDU_non_scheduled  maxBits_MACe_PDU_non_scheduled;
    /* optional; set in bit_mask hARQ_Ps_An_NnSchd_2ms_present if present */
    L1CAPI_HARQ_Process_Alloc_2ms_EDCH      hARQ_Prcss_Allctn_NonSched_2ms;  
} L1CAPI_E_DCH_NonScheduled_TxGrantItems;

typedef enum L1CAPI_BundlingModeIndicator {
    L1CAPI_EDCH_BUNDINGMODE = 0,
    L1CAPI_EDCH_NON_BUNDINGMODE= 1
} L1CAPI_BundlingModeIndicator;

typedef enum L1CAPI_EDCH_SchedulingInfo {
    L1CAPI_EDCH_SCHEDULING_INCLUDED = 0,
    L1CAPI_EDCH_SCHEDULING_NOT_INCLUDED = 1
} L1CAPI_EDCH_SchedulingInfo;

typedef struct L1CAPI_E_DCH_LogicalChannelInfo{
    uint8_t                                 bit_mask;
#define      schedulingPriorityIndicator_present 0x80
#define      schedulingInformation_present 0x40
#define      mACesGuaranteedBitRate_present 0x20
#define      eDCH_DDI_Value_present 0x10
    L1CAPI_LogicalChannelID                 logicalChannelId;
    /* optional; set in bit_mask schedulingPriorityIndicator_present if present */    
    L1CAPI_SchedulingPriorityIndicator      schedulingPriorityIndicator;
    /* optional; set in bit_mask schedulingInformation_present if present */    
    L1CAPI_EDCH_SchedulingInfo              schedulingInformation;
    /* optional; set in bit_mask mACesGuaranteedBitRate_present if present */    
    L1CAPI_MACEsGuaranteedBitRate           mACesGuaranteedBitRate;  
    /* optional; set in bit_mask eDCH_DDI_Value_present if present */    
    L1CAPI_E_DCH_DDI_Value                  e_DCH_DDI_Value;
    uint8_t                                 macD_PDU_Size_Count;
	L1CAPI_MACdPDU_Size 					*ptrMacDPduSize;
} L1CAPI_E_DCH_LogicalChannelInfo;

typedef struct L1CAPI_E_DCH_MACDFlow_Info{
    uint8_t                                 bit_mask;
#define      eDCH_MACdFlow_Multiplexing_present 0x80
#define      eDCH_MACdFlow_bundlingModeIndicator_present 0x40
#define      eDCH_MACdFlow_eDchNonSchedGrantInfo_present 0x20
    L1CAPI_E_DCH_MACdFlow_ID                e_DCH_MACdFlow_ID;
    L1CAPI_PayloadCRC_Indicator             payloadCRC_PresenceIndicator;
    L1CAPI_Max_Nr_of_ReTx_E_DCH             maxNrOfRetransmission_E_DCH;
    L1CAPI_E_DCH_HARQ_PO                    eDCH_HarqPowerOffset;
    /* optional; set in bit_mask eDCH_MACdFlow_Multiplexing_List_present if present */    
    L1CAPI_E_DCH_MACdFlow_Multiplexing      eDCH_MACdFlow_Multiplexing_List;
    L1CAPI_E_DCH_Grant_Type                 eDCH_Grant_Type;
    /* optional; set in bit_mask eDCH_MACdFlow_bundlingModeIndicator_present if present */
    L1CAPI_BundlingModeIndicator            bundlingModeIndicator;
    /* optional; set in bit_mask eDCH_MACdFlow_eDchNonSchedGrantInfo_present if present */    
    L1CAPI_E_DCH_NonScheduled_TxGrantItems  *ptrEDchNonSchedGrantInfo;  
    uint8_t                                 eDchNrOfLogicalChannels;
    L1CAPI_E_DCH_LogicalChannelInfo         *ptrEDCHLogicalChannelInformation;
} L1CAPI_E_DCH_MACDFlow_Info;

typedef struct L1CAPI_E_DCH_MACDFlow_Add_Info{
    uint8_t                                 e_DCH_MacDFlow_Count;
    L1CAPI_E_DCH_MACDFlow_Info              *ptrE_DCH_MACdFlows_Information;        
} L1CAPI_E_DCH_MACDFlow_Add_Info;

typedef struct L1CAPI_E_DCH_MACDFlow_Delete_Info{
    uint8_t                                 e_DCH_MacDFlow_Count;
    L1CAPI_E_DCH_MACdFlow_ID                *ptrE_DCH_MACdFlow_ID;
} L1CAPI_E_DCH_MACDFlow_Delete_Info;

typedef enum L1CAPI_ServingEdch_Radiolink_Location{
    L1CAPI_RL_IN_THIS_NODEB = 0,
    L1CAPI_RL_NOT_IN_THIS_NODEB = 1
} L1CAPI_ServingEdch_Radiolink_Location;

typedef struct L1CAPI_E_DCH_MACDFlow_Reconfig_Info{
    uint8_t                                 bit_mask;
#define      maxNrOfRetransmission_E_DCH_present 0x80
#define      eDCH_HarqPowerOffset_present 0x40
#define      eDCH_MACdFlow_Reconfig_Multiplexing_present 0x20
#define      eDCH_GrantType_present        0x10
#define      eDCH_MACdFlow_Reconfig_bundlingModeIndicator_present 0x08
#define      eDCH_MACdFlow_Reconfig_eDchNonSchedGrantInfo_present 0x04
    L1CAPI_E_DCH_MACdFlow_ID                e_DCH_MACdFlow_ID;
    /* optional; set in bit_mask maxNrOfRetransmission_E_DCH_present if present */    
    L1CAPI_Max_Nr_of_ReTx_E_DCH             maxNrOfRetransmission_E_DCH;
    /* optional; set in bit_mask eDCH_HarqPowerOffset_present if present */    
    L1CAPI_E_DCH_HARQ_PO                    eDCH_HarqPowerOffset;
    /* optional; set in bit_mask eDCH_MACdFlow_Reconfig_Multiplexing_List_present if present */    
    L1CAPI_E_DCH_MACdFlow_Multiplexing      eDCH_MACdFlow_Multiplexing_List;  
    /* optional; set in bit_mask eDCH_GrantType_present if present */    
    L1CAPI_E_DCH_Grant_Type                 eDCH_Grant_Type;
    /* optional; set in bit_mask eDCH_MACdFlow_Reconfig_bundlingModeIndicator_present if present */
    L1CAPI_BundlingModeIndicator            bundlingModeIndicator;
    /* optional; set in bit_mask eDCH_MACdFlow_Reconfig_eDchNonSchedGrantInfo_present if present */    
    L1CAPI_E_DCH_NonScheduled_TxGrantItems  *ptrEDchNonSchedGrantInfo;  
    uint8_t                                 eDchNrOfLogicalChannelsAdd;
    uint8_t                                 eDchNrOfLogicalChannelsMod;
    uint8_t                                 eDchNrOfLogicalChannelsDel;    
    L1CAPI_E_DCH_LogicalChannelInfo         *ptrEDCHLogicalChannelAdd;
    L1CAPI_E_DCH_LogicalChannelInfo         *ptrEDCHLogicalChannelMod;
    L1CAPI_LogicalChannelID                 *ptrEDCHLogicalChannelDel;
} L1CAPI_E_DCH_MACDFlow_Reconfig_Info;

typedef struct L1CAPI_E_DCH_FDD_Info {
    uint8_t                                 bit_mask;
#define      hARQ_Pc_Ac_Sd_2ms_EDCH_present 0x80
#define      e_DCH_Maximum_Bitrate_present 0x40
#define      e_DCH_Processing_Overload_Level_present 0x20
#define      e_DCH_Reference_Pwr_Offset_present 0x10
    /* optional; set in bit_mask hARQ_Pc_Ac_Sd_2ms_EDCH_present if present */
    L1CAPI_HARQ_Process_Alloc_2ms_EDCH      hARQ_Proc_Alloc_Sched_2ms_EDCH;  
    /* optional; set in bit_mask e_DCH_Maximum_Bitrate_present if present */
    L1CAPI_E_DCH_Maximum_Bitrate            e_DCH_Maximum_Bitrate;  
    /* optional; set in bit_mask e_DCH_Processing_Overload_Level_present if present */    
    L1CAPI_E_DCH_Processing_Overload_Level  e_DCH_Processing_Overload_Level;
    /* optional; set in bit_mask e_DCH_Reference_Pwr_Offset_present if present */    
    L1CAPI_E_DCH_Reference_Power_Offset     e_DCH_Reference_Power_Offset;  
    uint8_t                                 e_DCH_MacDFlow_Count;
    L1CAPI_E_DCH_MACDFlow_Info              *ptrE_DCH_MACdFlows_Information;
} L1CAPI_E_DCH_FDD_Info ;

typedef struct  L1CAPI_ServingEdch_Radiolink_Info{
    uint8_t                                 bit_mask;
#define serving_edch_rl_id_present        0x80    
    L1CAPI_ServingEdch_Radiolink_Location   serving_edch_rl_location;
    L1CAPI_Radiolink_ID                     serving_edch_rl_id;    
} L1CAPI_ServingEdch_Radiolink_Info;

typedef struct L1CAPI_E_DCH_FDD_Reconfig_Info {
    uint8_t                                 bit_mask;
#define      e_DCH_Reconfig_hARQ_Pc_Ac_Sd_2ms_EDCH_present 0x80
#define      e_DCH_Reconfig_Maximum_Bitrate_present 0x40
#define      e_DCH_Reconfig_Processing_Overload_Level_present 0x20
#define      e_DCH_Reconfig_Reference_Pwr_Offset_present 0x10
#define      macERestIndication_present     0x08
    /* optional; set in bit_mask hARQ_Pc_Ac_Sd_2ms_EDCH_present if present */
    L1CAPI_HARQ_Process_Alloc_2ms_EDCH      hARQ_Proc_Alloc_Sched_2ms_EDCH;  
    /* optional; set in bit_mask e_DCH_Reconfig_Maximum_Bitrate_present if present */
    L1CAPI_E_DCH_Maximum_Bitrate            e_DCH_Maximum_Bitrate;  
    /* optional; set in bit_mask e_DCH_Reconfig_Processing_Overload_Level_present if present */    
    L1CAPI_E_DCH_Processing_Overload_Level  e_DCH_Processing_Overload_Level;
    /* optional; set in bit_mask e_DCH_Reconfig_Reference_Pwr_Offset_present if present */    
    L1CAPI_E_DCH_Reference_Power_Offset     e_DCH_Reference_Power_Offset;  
    /* optional; set in bit_mask macERestIndication_present if present */    
    uint8_t                                 macERestIndication;
    uint8_t                                 e_DCH_MacDFlow_Count;
    L1CAPI_E_DCH_MACDFlow_Reconfig_Info     *ptrE_DCH_MACdFlows_Reconfig_Information;
} L1CAPI_E_DCH_FDD_Reconfig_Info ;

typedef struct L1CAPI_Radiolink_EDCH_Config_Ext {
    uint8_t                                 bit_mask;
#define  rl_Setup_servingEdchRlInfo_present  0x80 	
    L1CAPI_Radiolink_EDpch_Info             eDpchInfo;
    L1CAPI_E_DCH_FDD_Info                   eDchFddInfo;
    /* optional; set in bit_mask rl_Setup_servingEdchRlInfo_present if present */
    L1CAPI_ServingEdch_Radiolink_Info       *ptrServingEdchRlInfo;
} L1CAPI_Radiolink_EDCH_Config_Ext;

typedef struct L1CAPI_Radiolink_EDCH_Reconfig_Ext {
    uint8_t                                 bit_mask;
#define  rl_Reconfig_EdpchInfo_present  0x80 	
#define  rl_Reconfig_EdchFddInfo_present  0x40 	
#define  rl_Reconfig_EdchFddModifyInfo_present  0x20 	
#define  rl_Reconfig_EdchMacDFlowAdd_present  0x10 	
#define  rl_Reconfig_EdchMacDFlowDel_present  0x08 	
#define  rl_Reconfig_servingEdchRlInfo_present  0x04
    /* optional; set in bit_mask rl_Reconfig_EdpchInfo_present if present */
    L1CAPI_Radiolink_EDpch_Reconfig_Info    *ptrEDpchInfo;
    /* optional; set in bit_mask rl_Reconfig_EdchFddInfo_present if present */
    L1CAPI_E_DCH_FDD_Info                   *ptrEDchFddInfo;
    /* optional; set in bit_mask rl_Reconfig_EdchFddModifyInfo_present if present */
    L1CAPI_E_DCH_FDD_Reconfig_Info          *ptrEDchFddInfoModify;
    /* optional; set in bit_mask rl_Reconfig_EdchMacDFlowAdd_present if present */
    L1CAPI_E_DCH_MACDFlow_Add_Info          *ptrEdchMadDFlowsAdd;
    /* optional; set in bit_mask rl_Reconfig_EdchMacDFlowDel_present if present */
    L1CAPI_E_DCH_MACDFlow_Delete_Info       *ptrEdchMadDFlowsDel;
    /* optional; set in bit_mask rl_Reconfig_servingEdchRlInfo_present if present */
    L1CAPI_ServingEdch_Radiolink_Info       *ptrServingEdchRlInfo;
} L1CAPI_Radiolink_EDCH_Reconfig_Ext;

typedef struct L1CAPI_Active_Pattern_Seq4 {
    L1CAPI_TGPSID                           tGPSID;
    L1CAPI_TGPRC                            tGPRC;
    L1CAPI_CFN                              tGCFN;
} L1CAPI_Active_Pattern_Seq4;

typedef struct L1CAPI_Active_Pattern_Sequence_Info {
    L1CAPI_CFN                              cMConfigurationChangeCFN;
    // Only one active pattern is supported, tgpssCount =0,1
	uint8_t                                 tgpssCount;    
    L1CAPI_Active_Pattern_Seq4              *ptrTgpss; 
} L1CAPI_Active_Pattern_Sequence_Info;

typedef struct L1CAPI_Radiolink_Reconfig_CmnContextInfo{
    uint8_t                                 rlCount;
    uint8_t                                 coorTrchCountAdd;
    uint8_t                                 coorTrchCountModify;
    uint8_t                                 trchCountDelete;
    uint8_t                                 tgpsCount;
}L1CAPI_Radiolink_Reconfig_CmnContextInfo;

typedef struct L1CAPI_RadioLink_Fail_Info{
    L1CAPI_Radiolink_ID     rL_ID;
    L1CAPI_RLFailure_Cause  cause;
}L1CAPI_RadioLink_Fail_Info;

typedef struct L1CAPI_RadioLinkSet_Fail_Info{
    L1CAPI_Radiolink_Set_ID  rLS_ID;
    L1CAPI_RLFailure_Cause   cause;
}L1CAPI_RadioLinkSet_Fail_Info;

typedef enum L1CAPI_Dl_Dpch_Timing_Adj{
    L1CAPI_DL_DPCH_TIMING_ADJ_ADVANCE = 0,
    L1CAPI_DL_DPCH_TIMING_ADJ_DELAY = 1
}L1CAPI_Dl_Dpch_Timing_Adj;

typedef struct L1CAPI_Radiolink_Reconfig_params{
    uint8_t                                 bit_mask;
#define      maxDlPower_present      0x80    
#define      minDlPower_present      0x40    
#define      dlRefPower_present      0x20    
#define      rl_reconfig_transmitDiverIndicator_present      0x10    
#define      dlDpchTimingAdj_present      0x08
#define      eDchRlReconfigInfoExtension_present  0x04
    uint8_t                                 dlCodeCount;
    L1CAPI_Radiolink_ID                     rL_ID;
    /* optional; set in bit_mask maxDlPower_present if present */
    L1CAPI_DL_Power                         maximumDL_power;
    /* optional; set in bit_mask minDlPower_present if present */
    L1CAPI_DL_Power                         minimumDL_power;
    /* optional; set in bit_mask dlRefPower_present if present */
    L1CAPI_DL_Power                         dL_reference_power;
    /* optional; set in bit_mask rl_reconfig_transmitDiverIndicator_present if present */
    L1CAPI_TSTD_Indicator                   transmitDiversityIndicator;
    /* optional; set in bit_mask dlDpchTimingAdj_present if present */
    L1CAPI_Dl_Dpch_Timing_Adj               dl_dpch_timing_adj;
    L1CAPI_DL_CodeInfo                      *ptrDlCodeInfo;
    /* optional; set in bit_mask eDchRlReconfigInfoExtension_present if present */
    L1CAPI_EDCH_RL_InfoExtension            *ptrEDchRlInfoExtension;

}L1CAPI_Radiolink_Reconfig_params;

typedef struct L1CAPI_HS_PDSCH_Code_Info {
    uint8_t                                 number_of_HS_PDSCH_codes;
    L1CAPI_HSPDSCH_Start_code_number        hS_PDSCH_Start_code_number;  
} L1CAPI_HS_PDSCH_Code_Info;

typedef enum L1CAPI_HS_SCCH_AGCH_RGCH_Code_Choice {
    L1CAPI_CODE_CHOICE_REMOVE_NULL = 0,
    L1CAPI_CODE_CHOICE_REPLACE = 1
} L1CAPI_HS_SCCH_AGCH_RGCH_Code_Choice;

typedef struct L1CAPI_HS_SCCH_Code_Info {
    L1CAPI_HS_SCCH_AGCH_RGCH_Code_Choice    codeChoice;
    uint8_t                                 codeCount;
    L1CAPI_DL_ChannelCodeNumber             *ptrHsScchCodeNumberList;
} L1CAPI_HS_SCCH_Code_Info;

typedef struct L1CAPI_Rl_Cmn_Edch_info{
    uint8_t                                 bit_mask;    
#define  eAgchPwrOffset_present         0x80
#define  eRgchHichPwrOffset_present     0x40
    /* optional; set in bit_mask eAgchPwrOffset_present if present */
    uint8_t                                 eAgchPwrOffset;
    /* optional; set in bit_mask eRgchHichPwrOffset_present if present */
    uint8_t                                 eRgchHichPwrOffset;
} L1CAPI_Rl_Cmn_Edch_info;

typedef struct L1CAPI_E_AGCH_Code_Info {
    L1CAPI_HS_SCCH_AGCH_RGCH_Code_Choice    codeChoice;
    uint8_t                                 codeCount;
    L1CAPI_DL_ChannelCodeNumber             *ptrAgchcodeNumberList;  
} L1CAPI_E_AGCH_Code_Info;

typedef struct L1CAPI_E_RGCH_HICH_Code_Info {
    L1CAPI_HS_SCCH_AGCH_RGCH_Code_Choice    codeChoice;
    uint8_t                                 codeCount;
    L1CAPI_DL_ChannelCodeNumber             *ptrRgchHichcodeNumberList;  
} L1CAPI_E_RGCH_HICH_Code_Info;

typedef struct L1CAPI_Physical_SharedCH_Reconfig_Ext {
    uint8_t                                 bit_mask;
#define      hsScchCellPowerOffset_present 0x80
#define      eAgchRgchHichScramCode_present 0x40
#define      maxTargetRTWP_present 0x20
#define      refRTWP_present 0x10
#define      rlCommonEDchInfo_present 0x08
#define      eAgchCodeInfo_present 0x04
#define      eRgchHichCodeInfo_present 0x02
    /* optional; set in bit_mask hsScchCellPowerOffset_present if present */
    uint8_t                                 hsScchCellPowerOffset;  
    /* optional; set in bit_mask eAgchRgchHichScramCode_present if present */
    L1CAPI_ScramCodeNumber                  eAgchRgchHichScramCode;  
    /* optional; set in bit_mask maxTargetRTWP_present if present */    
    L1CAPI_Max_Target_RcvedTotalWideBandPwr maxTargetRTWP;  
    /* optional; set in bit_mask refRTWP_present if present */    
    L1CAPI_Ref_RcvedTotalWideBandPwr        refRTWP;
    /* optional; set in bit_mask rlCommonEDchInfo_present if present */
    L1CAPI_Rl_Cmn_Edch_info                 *ptrRlCommonEDchInfo;
    /* optional; set in bit_mask eAgchCodeInfo_present if present */    
    L1CAPI_E_AGCH_Code_Info                 *ptrEagchCodeInfo; 
    /* optional; set in bit_mask eRgchHichCodeInfo_present if present */    
    L1CAPI_E_RGCH_HICH_Code_Info            *ptrErgchHichCodeInfo;  
} L1CAPI_Physical_SharedCH_Reconfig_Ext;

typedef struct L1CAPI_CoordTrchRespItem
{
  L1CAPI_DCH_ID                             dchId;
  L1CAPI_BINDING_ID                         binding_id;
} L1CAPI_CoordTrchRespItem;

typedef struct L1CAPI_Edch_MacD_Flow_Info_resp {
    uint8_t                                 bit_mask;
#define edch_MacDFlow_harqProcAlloc2ms_SchedTxGrant_present   0x80    
    L1CAPI_E_DCH_MACdFlow_ID                e_DCH_MACdFlow_ID;
    L1CAPI_BINDING_ID                       binding_id;
    /* optional; set in bit_mask edch_MacDFlow_harqProcAlloc2ms_SchedTxGrant_present if present */
    L1CAPI_E_DCH_HarqProc_Alloc_2ms_tti     harqProcAlloc2ms_SchedTxGrant;
} L1CAPI_Edch_MacD_Flow_Info_resp;

typedef enum L1CAPI_Pri_Sec_Grant_Selector{
    L1CAPI_PRIMARY_E_RNTI,
    L1CAPI_SECONDARY_E_RNTI
} L1CAPI_Pri_Sec_Grant_Selector;

typedef enum L1CAPI_Ergch_Release_indicator{
    L1CAPI_E_RGCH_RELEASED,
    L1CAPI_E_RGCH_NOT_RELEASED
} L1CAPI_Ergch_Release_indicator;

typedef struct L1CAPI_Edch_Fdd_Ctrl_Channel_Info {
    uint16_t                                bit_mask;
#define eDch_Ch_Info_eAgchRgchHichScramCode_present 0x8000    
#define eDch_Ch_Info_eAgchChanCode_present     0x4000
#define eDch_Ch_Info_primaryErnti_present      0x2000
#define eDch_Ch_Info_secondaryErnti_present    0x1000
#define eDch_Ch_Info_eRgchHichChanCode_present 0x0800
#define eDch_Ch_Info_eRgchSignatureSeq_present 0x0400
#define eDch_Ch_Info_eHichSignatureSeq_present 0x0200
#define eDch_Ch_Info_servingGrantVal_present   0x0100
#define eDch_Ch_Info_priSecGrantSelector_present 0x0080
#define eDch_Ch_Info_eRgchReleaseInd_present  0x0040

    /* optional; set in bit_mask eDch_Ch_Info_eAgchRgchHichScramCode_present if present */
    L1CAPI_ScramCodeNumber                  eAgchRgchHichScramCode;
    /* optional; set in bit_mask eDch_Ch_Info_eAgchChanCode_present if present */
    L1CAPI_DL_ChannelCodeNumber             eAgchChanCode;
    /* optional; set in bit_mask eDch_Ch_Info_primaryErnti_present if present */
    L1CAPI_E_RNTI                           primaryErnti;
    /* optional; set in bit_mask eDch_Ch_Info_secondaryErnti_present if present */
    L1CAPI_E_RNTI                           secondaryErnti;
    /* optional; set in bit_mask eDch_Ch_Info_eRgchHichChanCode_present if present */
    L1CAPI_DL_ChannelCodeNumber             eRgchHichChanCode;
    /* optional; set in bit_mask eDch_Ch_Info_eRgchSignatureSeq_present if present */
    L1CAPI_E_HICH_Signature_Sequence        eRgchSignatureSeq;
    /* optional; set in bit_mask eDch_Ch_Info_eHichSignatureSeq_present if present */
    L1CAPI_E_HICH_Signature_Sequence        eHichSignatureSeq;
    /* optional; set in bit_mask eDch_Ch_Info_servingGrantVal_present if present */
    L1CAPI_E_Serving_Grant_Value            servingGrantVal;
    /* optional; set in bit_mask eDch_Ch_Info_priSecGrantSelector_present if present */
    L1CAPI_Pri_Sec_Grant_Selector           priSecGrantSelector;
    /* optional; set in bit_mask eDch_Ch_Info_eRgchReleaseInd_present if present */
    L1CAPI_Ergch_Release_indicator          eRgchReleaseInd;
} L1CAPI_Edch_Fdd_Ctrl_Channel_Info;

typedef struct L1CAPI_Edch_Fdd_Info_Resp {
    uint8_t                                 bit_mask;
#define edchRlSetId_present     0x80    
#define edch_FddInfo_harqProcAlloc2ms_SchedTxGrant_present   0x40
#define edchFddCtrlChanInfo_present    0x20
    /* optional; set in bit_mask edchRlSetId_present if present */
    L1CAPI_Radiolink_Set_ID                 edchRlSetId;
    /* optional; set in bit_mask edch_FddInfo_harqProcAlloc2ms_SchedTxGrant_present if present */
    L1CAPI_E_DCH_HarqProc_Alloc_2ms_tti     harqProcAlloc2ms_SchedTxGrant;
    uint8_t                                 mAcdFlowCount;    
    L1CAPI_Edch_MacD_Flow_Info_resp         *ptrEdchMacdFlowInfoResp;
    /* optional; set in bit_mask edchFddCtrlChanInfo_present if present */
    L1CAPI_Edch_Fdd_Ctrl_Channel_Info       *ptrEdchFddCtrlChanInfo;
} L1CAPI_Edch_Fdd_Info_Resp;

typedef struct L1CAPI_Radiolink_Info_Resp{
    uint8_t                                 bit_mask;
#define edchFddInfoRsp_present   0x80
    uint8_t                                 coordTrchCount;
    L1CAPI_Radiolink_ID                     rL_ID;
    L1CAPI_Radiolink_Set_ID                 rlSetId;
    L1CAPI_Radiolink_ID                     referenceRlId;
    L1CAPI_CoordTrchRespItem                *ptrCoordTrchRsp;  
    /* optional; set in bit_mask edchFddInfoRsp_present if present */
    L1CAPI_Edch_Fdd_Info_Resp               *ptrEdchFddInfoRsp;
} L1CAPI_Radiolink_Info_Resp;

typedef enum L1CAPI_HarqMem_Choice{
    L1CAPI_HARQ_MEM_IMPLICIT,
    L1CAPI_HARQ_MEM_EXPLICIT
} L1CAPI_HarqMem_Choice;

typedef struct L1CAPI_MacDFlow_Info_Resp {
    L1CAPI_HSDSCH_MACdFlow_ID               macDFlowId;
    L1CAPI_BINDING_ID                       bindingId;
} L1CAPI_MacDFlow_Info_Resp;

typedef struct L1CAPI_HarqMem_Partitioning_Implicit
{
    uint8_t                                 nrOfProcess;
}L1CAPI_HarqMem_Partitioning_Implicit;

typedef enum L1CAPI_Harq_Process_Memory_Size{
    L1CAPI_HMS800, 
    L1CAPI_HMS1600, 
    L1CAPI_HMS2400, 
    L1CAPI_HMS3200, 
    L1CAPI_HMS4000,
    L1CAPI_HMS4800, 
    L1CAPI_HMS5600, 
    L1CAPI_HMS6400, 
    L1CAPI_HMS7200, 
    L1CAPI_HMS8000,
    L1CAPI_HMS8800, 
    L1CAPI_HMS9600, 
    L1CAPI_HMS10400, 
    L1CAPI_HMS11200, 
    L1CAPI_HMS12000,
    L1CAPI_HMS12800, 
    L1CAPI_HMS13600, 
    L1CAPI_HMS14400, 
    L1CAPI_HMS15200, 
    L1CAPI_HMS16000,
    L1CAPI_HMS17600, 
    L1CAPI_HMS19200, 
    L1CAPI_HMS20800, 
    L1CAPI_HMS22400, 
    L1CAPI_HMS24000,
    L1CAPI_HMS25600, 
    L1CAPI_HMS27200,
    L1CAPI_HMS28800, 
    L1CAPI_HMS30400, 
    L1CAPI_HMS32000,
    L1CAPI_HMS36000, 
    L1CAPI_HMS40000,
    L1CAPI_HMS44000, 
    L1CAPI_HMS48000,
    L1CAPI_HMS52000,
    L1CAPI_HMS56000, 
    L1CAPI_HMS60000,
    L1CAPI_HMS64000,
    L1CAPI_HMS68000,
    L1CAPI_HMS72000,
    L1CAPI_HMS76000,
    L1CAPI_HMS80000,
    L1CAPI_HMS88000,
    L1CAPI_HMS96000,
    L1CAPI_HMS104000,
    L1CAPI_HMS112000,
    L1CAPI_HMS120000,
    L1CAPI_HMS128000, 
    L1CAPI_HMS136000, 
    L1CAPI_HMS144000,
    L1CAPI_HMS152000,
    L1CAPI_HMS160000, 
    L1CAPI_HMS176000, 
    L1CAPI_HMS192000, 
    L1CAPI_HMS208000,
    L1CAPI_HMS224000, 
    L1CAPI_HMS240000, 
    L1CAPI_HMS256000, 
    L1CAPI_HMS272000,
    L1CAPI_HMS288000,
    L1CAPI_HMS304000
}L1CAPI_Harq_Process_Memory_Size;

typedef struct L1CAPI_HarqMem_Partitioning_Explicit
{
    uint8_t                                 nrOfProcess;
    L1CAPI_Harq_Process_Memory_Size         *ptrProcessMemSize;
}L1CAPI_HarqMem_Partitioning_Explicit;

typedef struct L1CAPI_HSDSCH_Info_Resp{
     L1CAPI_HarqMem_Choice                  harqMemChoice;
     uint8_t                                macDFlowCount;
     uint8_t                                hsscchCodeCount;
     L1CAPI_MacDFlow_Info_Resp              *ptrMacDFlowInfo;
     L1CAPI_DL_ChannelCodeNumber            *ptrHsscchInfoResp;
	 union{
       L1CAPI_HarqMem_Partitioning_Implicit   harqMemImplicit;
       L1CAPI_HarqMem_Partitioning_Explicit   HarqMemExplicit;
     }u;
}L1CAPI_HSDSCH_Info_Resp;

/*IE for Periodic Report*/
typedef struct L1CAPI_MeasPeriodicRepCfg
{
	uint8_t   scale;
	uint16_t  repFreq;
}L1CAPI_MeasPeriodicRepCfg;

/*IE for CELL Information (for Measurement)*/
typedef struct L1CAPI_CMeasCellObj_Info
{
	/* Cell Identifier */
	L1CAPI_Cell_ID cId;
	/* Neighbouring Cell Info */
	
}L1CAPI_CMeasCellObj_Info;

/*IE for RACH Information (for Measurement)*/
typedef struct L1CAPI_CMeasRachObj_Info
{
	/* Cell Identifier */
	L1CAPI_Cell_ID cId;
	/* Transport channel identifier for RACH */
	L1CAPI_CommonTranspChannelID commonTransportChannelID;
}L1CAPI_CMeasRachObj_Info;

/*IE for Reporting Information*/
typedef struct L1CAPI_MeasReportInf
{
	L1CAPI_MeasRepMode			reportMode;
	/* optional; IE for Periodic Report, present if 'reportMode' indicates periodic*/
	L1CAPI_MeasPeriodicRepCfg   periodicRepCfg;
}L1CAPI_MeasReportInf;

/*IE for Measurement Information*/
typedef struct L1CAPI_MeasInf
{
	L1CAPI_MeasType  measType;
	L1CAPI_MeasValue measValue;
}L1CAPI_MeasInf;

/* IE for Dedicated Measurement RL (or RLS) Info. Used for Dedicated Measurement
   Initiation Response and Dedicated Measurement Report. */
typedef struct L1CAPI_DMeasRl_Info {
		uint8_t                                 bit_mask;
#define dMeasRlInf_measInf_present   0x80
#define dMeasRlInf_cfn_present       0x40
		/* L1CAPI_Radiolink_ID is of same type as L1CAPI_Radiolink_Set_ID */
		L1CAPI_Radiolink_ID                     rL_ID;
		/* optional; set in bit_mask dMeasRlInf_measInf_present if present */
		L1CAPI_MeasInf                          measInf;
		/* optional; set in bit_mask dMeasRlInf_measInf_present and dMeasRlInf_cfn_present if present*/
		L1CAPI_CFN                              cfn;
}L1CAPI_DMeasRl_Info;

/**************************Modem Setup Request**************************************** */
typedef struct L1CAPI_Modem_Setup_Request
{	
	uint8_t                                 bit_mask;
#define mdmsetup_txattn_present      0x80
#define mdmsetup_rxgain_present      0x40
#define mdmsetup_rfport_present      0x20

    /* optional; set in bit_mask mdmsetup_txattn_present if present 
	 Range: 0-254. This corresponds to a range of 0 db to 63.5 db by step of 0.25 )*/
    uint8_t                                txAttn;
    /* NOT SUPPORTED */
    uint8_t                                rxGain;    
    /* optional: set in bit_mask mdmsetup_clksel_present if present 
       SDR-4000 Clock Selection Control                                            */

    /*optional: set mdmsetup_rfport_present if present */
    /*transmit antenna port: tx1/txa:1,tx2/txb:2               */
    /*receive  antenna port: rx1/rxa:1,rx2/rxb:2               */
    uint8_t                                txRfPort;  
    uint8_t                                rxRfPort;

}L1CAPI_Modem_Setup_Request;


/**************************Cell Setup Request**************************************** */
typedef struct L1CAPI_Cell_Setup_Request 
{
    L1CAPI_CellInfo                         cellInfo;
    L1CAPI_SCH_Info                         physDlPSch;
    L1CAPI_SCH_Info                         physDlSSch;
    L1CAPI_Primary_CPICH_Info               physDlPCpich;
    uint8_t                                 nSCPich;    
    L1CAPI_Secondary_CPICH_Info             *ptrPhysDlSCpich;
    L1CAPI_PrimCCPCH_Info                   physDlPCcpch;
    L1CAPI_BCH_Info                         trchCommonDlBch;
} L1CAPI_Cell_Setup_Request;

/**************************Cell Reconfig Request**************************************** */
typedef struct L1CAPI_Cell_Reconfig_Request 
{
    uint8_t                                 bit_mask;
#define cellreconf_maxTxPower_present      0x80
#define cellreconf_syncConfig_present      0x40
#define cellreconf_cellPhyCh_present	   0x20
#define cellreconf_activationCfn_present   0x10
#define cellreconf_psc_present			   0x08 		
#define cellreconf_trchCommonDlBch_present 0x04
#define cellreconf_txattn_present		   0x02
#define cellreconf_newCellId_present	   0x01


    L1CAPI_Cell_ID                          cId;
    /* optional; set in bit_mask cellreconf_maxTxPower_present if present */
    L1CAPI_MaximumTransmissionPower         maxTxPower;
    /* optional; set in bit_mask cellreconf_syncConfig_present if present */
    L1CAPI_Sync_Config                      syncConfig;
	/* optional; set in bit_mask cellreconf_cellPhyCh_present if present */
	L1CAPI_CellChannelsReconf				*ptrCellChReconfig;
    /* optional; set in bit_mask cellreconf_trchCommonDlBch_present if present */
    L1CAPI_BCH_Info                         trchCommonDlBch;
    /* optional; set in bit_mask cellreconf_txattn_present if present 
	 Range: 0-254. This corresponds to a range of 0 db to 63.5 db by step of 0.25 )*/
    uint8_t                                txAttn;
	/* optional; set in bit_mask cellreconf_activationCfn_present if present */
	L1CAPI_CFN                              cfn;  
	/* optional; set in bit_mask cellreconf_psc_present if present */
	L1CAPI_PrimScramCode                    priScramCode;
	/* optional; set in bit_mask cellreconf_newCid_present if present */
	L1CAPI_Cell_ID                          newCellId;
	
} L1CAPI_Cell_Reconfig_Request;

/**************************Cell Delete Request**************************************** */
typedef struct L1CAPI_Cell_Delete_Request 
{
    L1CAPI_Cell_ID                          cId;
} L1CAPI_Cell_Delete_Request;

/**************************Cell Physical Channel Reconfig Request ****************************** */
typedef struct L1CAPI_PhysicalChannel_Reconfig_Request {
		uint8_t                                bit_mask;
		L1CAPI_Cell_ID                         cId;          /*Cell Identifier */
		L1CAPI_CFN                             cfn;	         /*Activation cfn*/
		#define      uarfcnInfo_present        0x01          /*DL and UL UARFCN values will be modified*/
		L1CAPI_UARFCN                          uarfcnUl;     /*UL UARFCN*/ 
		L1CAPI_UARFCN                          uarfcnDl;     /*DL UARFCN*/
		uint8_t                                reserved[64]; /*reserved for future*/
}L1CAPI_PhysicalChannel_Reconfig_Request;

/**************************Common Transport (UL) Channel**************************************** */
typedef struct L1CAPI_Prach_Setup_Request {
    L1CAPI_CommonInfo                       cmnInfo;
    L1CAPI_Prach_Phy_Info                   physUlPrach;
    L1CAPI_AICH_Phy_Info                    physDlAich;
    L1CAPI_TFCS_Info                        cctrchUlTfc;
    L1CAPI_Prach_Trch_Info                  trchUlPrach;
} L1CAPI_Prach_Setup_Request;

/**************************Common Transport (DL) Channel**************************************** */
typedef struct L1CAPI_Sccpch_Setup_Request {
    uint8_t                                 bit_mask;
#define      trchCommonDlPch_present 0x80
    L1CAPI_CommonInfo                       cmnInfo;
	uint8_t 								nFach;
    L1CAPI_SCCPCH_Phy_Info                  physDlSCcpch;
    L1CAPI_TFCS_Info                        cctrchDlTfc;
    L1CAPI_SCCPCH_Trch_Info                 *ptrTrchDlFach;
    /* optional; set in bit_mask trchCommonDlPch_present if present */    
    L1CAPI_PCH_Info                         *ptrTrchDlPch;
} L1CAPI_Sccpch_Setup_Request;

/**************************Common Measurements Initiation**************************************** */
typedef struct L1CAPI_Common_Meas_Init_Request{
    uint8_t                                 bit_mask;
#define cMeasInitReq_cellObjInf_present  0x80
#define	cMeasInitReq_rachObjInf_present  0x40
#define cMeasInitReq_filterCoeff_present 0x20
#define cMeasInitReq_sfn_present         0x10
	L1CAPI_Meas_ID                          measureID;
	/* optional; set in bit_mask cMeasInitReq_cellObjInf_present if present */
	L1CAPI_CMeasCellObj_Info				cellObjInf;
	/* optional; set in bit_mask cMeasInitReq_rachObjInf_present if present */
	L1CAPI_CMeasRachObj_Info				rachObjInf;
	L1CAPI_MeasType                         measType;
	/* optional; set in bit_mask cMeasInitReq_filterCoeff_present if present */
	L1CAPI_MeasFilterCoeff                  filterCoeff;
	L1CAPI_MeasReportInf                    reportInf;
	L1CAPI_FnReportInd                      sfnReportInd;
	/* optional; set in bit_mask cMeasInitReq_sfn_present if present */
	L1CAPI_SFN                              sfn;
} L1CAPI_Common_Meas_Init_Request;

/**************************Common Measurements Initiation**************************************** */
typedef struct L1CAPI_Common_Meas_Term_Request{
    L1CAPI_Meas_ID                          measureID;
} L1CAPI_Common_Meas_Term_Request;


/**************************Radio Link Setup DCH**************************************** */
typedef struct L1CAPI_Radiolink_Setup_Request {
    uint8_t                                 bit_mask;
#define      rl_Setup_activePatternSeqInfo_present 0x80
#define      rl_Setup_dlPowerBalancingInfo_present 0x40
#define      rl_Setup_hsdsch_present 0x20
#define      rl_Setup_eDchRlSetupExtension_present 0x10
    L1CAPI_RadioLink_CmnContextInfo         comContextInfo;
    L1CAPI_RadioLink_Info                   *pRlInfo;    
    L1CAPI_DCH_CoordTrchInfoListItem        *ptrCoordTrchDchInfo;
    L1CAPI_DL_DPCH_PhyInfo                  physDlDpch;
    L1CAPI_TFCS_Info                        cctrchDlTfc;
    L1CAPI_UL_DPCH_PhyInfo                  physUlDpch;
    L1CAPI_TFCS_Info                        cctrchUlTfc;
    L1CAPI_TxGap_SeqInfo                    *ptrTransGapPattSeqInfo;
    /* optional; set in bit_mask rl_Setup_activePatternSeqInfo_present if present */    
	L1CAPI_Active_Pattern_Sequence_Info     *ptrActivePatternSeqInfo;
    /* optional; set in bit_mask rl_Setup_dlPowerBalancingInfo_present if present */
    L1CAPI_DL_PowerBalancing_Info           *ptrDlPowerBalancingInfo;  
    /* optional; set in bit_mask rl_Setup_hsdsch_present if present */    
    L1CAPI_Radiolink_HSDSCH_Config          *ptrHsdsch;  
    /* optional; set in bit_mask rl_Setup_eDchRlSetupExtension_present if present */
    L1CAPI_Radiolink_EDCH_Config_Ext        *ptrEDchRlSetupExtension; 
} L1CAPI_Radiolink_Setup_Request;

/**************************Radio Link Deletion DCH**************************************** */
typedef struct L1CAPI_Radiolink_DeletionRequest{
    L1CAPI_NodeB_Com_Context                NodeBComContext;
    uint8_t                                 rlCount;
    L1CAPI_Radiolink_ID                     *pRl_ID;
}L1CAPI_Radiolink_DeletionRequest;

/**************************Radio Link reconfigure Commit DCH**************************************** */
typedef struct L1CAPI_Radiolink_ReconfigCommit{
    uint8_t                                 bit_mask;
#define activePattSeqInfo_present  0x80    
    L1CAPI_NodeB_Com_Context                NodeBComContext;
    L1CAPI_CFN                              cfn;
    /* optional; set in bit_mask activePattSeqInfo_present if present*/       
    L1CAPI_Active_Pattern_Sequence_Info     *ptrActivePattSeqInfo;
}L1CAPI_Radiolink_ReconfigCommit;

/**************************Radio Link reconfigure Cancel DCH**************************************** */
typedef struct L1CAPI_Radiolink_ReconfigCancel{
    L1CAPI_NodeB_Com_Context                NodeBComContext;
}L1CAPI_Radiolink_ReconfigCancel;


/**************************Radio Link reconfigure prepare DCH**************************************** */
typedef struct L1CAPI_Radiolink_Reconfig_Prepare{    
    uint8_t                                bit_mask;
#define rl_Reconfig_physDlDpch_present           0x80
#define rl_Reconfig_physUlDpch_present           0x40
#define rl_Reconfig_hsdsch_present               0x20
#define rl_Reconfig_eDchRlSetupExtension_present 0x10

    L1CAPI_NodeB_Com_Context                NodeBComContext;
    L1CAPI_Radiolink_Reconfig_CmnContextInfo rl_reconfig_comContextInfo;
    L1CAPI_Radiolink_Reconfig_params        *ptrRlInfo;
    L1CAPI_DCH_ID                           *ptrTrchDchDelete;
    L1CAPI_DCH_CoordTrchInfoListItem        *ptrTrchDchAdd;
    L1CAPI_DCH_CoordTrchInfoListItem        *PtrTrchDchModify;
    /* optional; set in bit_mask rl_Reconfig_physDlDpch_present if present */    
    L1CAPI_DL_DPCH_PhyInfo_Reconfig         *ptrPhysDldpch;
    /* optional; set in bit_mask rl_Reconfig_physUlDpch_present if present */    
    L1CAPI_UL_DPCH_PhyInfo_Reconfig         *ptrPhysUldpch;
    L1CAPI_TFCS_Info                         cctrchDlTfc;
    L1CAPI_TFCS_Info                         cctrchUlTfc;
    L1CAPI_TxGap_SeqInfo                    *ptrTransGapPattSeqInfo;
    /* optional; set in bit_mask rl_Reconfig_hsdsch_present if present */    
    L1CAPI_Radiolink_HSDSCH_Reconfig        *ptrHsdsch;  
    /* optional; set in bit_mask rl_Reconfig_eDchRlSetupExtension_present if present */
    L1CAPI_Radiolink_EDCH_Reconfig_Ext      *ptrEDchRlExtension; 
}L1CAPI_Radiolink_Reconfig_Prepare;
/**************************Compressed Mode Command ************************************************* */
typedef struct L1CAPI_Compressed_Mode_Command{
	uint8_t                                 bit_mask; /*reserved for future*/
    L1CAPI_NodeB_Com_Context                NodeBComContext;
	L1CAPI_Active_Pattern_Sequence_Info     ActivePattSeqInfo;
	uint8_t									reserved[64]; /*reserved for future*/
}L1CAPI_Compressed_Mode_Command;
/**************************Radio Link Failure Indication DCH**************************************** */
typedef struct L1CAPI_Radiolink_Failure_Ind{
	uint8_t                                 rlCount;
    uint8_t                                 rlsCount;
    /*optional: present if rlCount!=0 */
    L1CAPI_RadioLink_Fail_Info              *pRlFailInf;
    /*optional: present if rlsCount!=0. Currently not supported */
    L1CAPI_RadioLinkSet_Fail_Info           *pRlsFailInf;
}L1CAPI_Radiolink_Failure_Ind;

/**************************Radio Link Restore Indication DCH**************************************** */
typedef struct L1CAPI_Radiolink_Restore_Ind{
	uint8_t                                 rlCount;
    uint8_t                                 rlsCount;
	/*optional: present if rlCount!=0 */
	L1CAPI_Radiolink_ID                     *pRl_ID;
	/*optional: present if rlsCount!=0. Currently not supported */
	L1CAPI_Radiolink_Set_ID                 *pRls_ID;

}L1CAPI_Radiolink_Restore_Ind;

/**************************Dedicated Measurements Initiation**************************************** */
typedef struct L1CAPI_Dedicated_Meas_Init_Request{
    uint8_t                                bit_mask;
#define dMeasInitReq_pRl_ID_present	      0x80
#define dMeasInitReq_pRls_ID_present	  0x40
#define dMeasInitReq_allRl                0x20
#define dMeasInitReq_allRls               0x10
#define dMeasInitReq_filterCoeff_present  0x08
#define dMeasInitReq_cfn_present          0x04
    L1CAPI_NodeB_Com_Context                NodeBComContext;
	L1CAPI_Meas_ID                          measureID;
	uint8_t                                 rlCount;  
	uint8_t                                 rlsCount; 	
	/*optional: present if dMeasInitReq_pRl_ID_present set in bit_mask and rlCount!=0
	            Currently only pRl_ID is supported*/
	L1CAPI_Radiolink_ID                     *pRl_ID;
	/*optional: present if dMeasInitReq_pRls_ID_present set in bit_mask and rlsCount!=0. 
	            Currently NOT SUPPORTED*/
	L1CAPI_Radiolink_Set_ID                 *pRls_ID;
	L1CAPI_MeasType                         measType;
	/* optional; set in bit_mask dMeasInitReq_filterCoeff_present if present */
	L1CAPI_MeasFilterCoeff                  filterCoeff;
	L1CAPI_MeasReportInf                    reportInf;
	L1CAPI_FnReportInd                      cfnReportInd;
	/* optional; set in bit_mask dMeasInitReq_cfn_present if present */
	L1CAPI_CFN                              cfn;
} L1CAPI_Dedicated_Meas_Init_Request;

/**************************Dedicated Measurements Termination Request*********************************** */
typedef struct L1CAPI_Dedicated_Meas_Term_Request{
    L1CAPI_NodeB_Com_Context                NodeBComContext;
	L1CAPI_Meas_ID                          measureID;
} L1CAPI_Dedicated_Meas_Term_Request;

/**************************Physical Share Channel Reconfiguration**************************************** */
typedef struct L1CAPI_Physical_Share_CH_Reconfig_Request {
    uint8_t                                 bit_mask;
#define      sfn_present 0x80
#define      hsPdschSschTotalPower_present 0x40
#define      hsPdschSschScramCode_present 0x20
#define      hsPdschCodeInfo_present 0x10
#define      hsScchCodeInfo_present 0x08
#define      physShChRcfgExtensions_present 0x04
    L1CAPI_Cell_ID                          cId;
    /* optional; set in bit_mask sfn_present if present */
    L1CAPI_SFN                              sfn;  
    /* optional; set in bit_mask hsPdschSschTotalPower_present if present */    
    L1CAPI_MaximumTransmissionPower         hsPdschSschAgchRgchHichTotalPower; 
    /* optional; set in bit_mask hsPdschSschScramCode_present if present */    
    L1CAPI_ScramCodeNumber                  hsPdschSschScramCode;  
    /* optional; set in bit_mask hsPdschCodeInfo_present if present */    
    L1CAPI_HS_PDSCH_Code_Info               *ptrHsPdschCodeInfo; 
    /* optional; set in bit_mask hsScchCodeInfo_present if present */    
    L1CAPI_HS_SCCH_Code_Info                *ptrHsScchCodeInfo;  
    /* optional; set in bit_mask physShChRcfgExtensions_present if present */
    L1CAPI_Physical_SharedCH_Reconfig_Ext   *ptrPhysShChRcfgExtensions;  
} L1CAPI_Physical_Share_CH_Reconfig_Request;

/**************************BCH_SIM_DATA**************************************** */
typedef struct L1CAPI_BCCH_SIB7_Info
{
	L1CAPI_BCCH_SIB_Pos sibPos;	
	L1CAPI_BCCH_SIB_Rep sibRep; 
}L1CAPI_BCCH_SIB7_Info;

typedef struct L1CAPI_BCH_SIM_DATA
{
/*
   unsigned char partNr;
   unsigned char pad1[3];
   unsigned long long pad;
   unsigned char dataPerSim[512];
*/
    /* from 03.15.00 release,valid sizes are 2048,4096 and 8192 */
    uint8_t   data[2048];
    L1CAPI_BCCH_SIB7_Info sib7Info;

}L1CAPI_BCH_SIM_DATA;

/**************************Genetric Response**************************************** */
typedef struct L1CAPI_Generic_Response {
    L1CAPI_MsgId_e                          associatedMsg;    
    L1CAPI_Msg_Status                       msgStatus;
} L1CAPI_Generic_Response;

/**************************Sccpch Setup Response**************************************** */
typedef struct L1CAPI_Sccpch_Setup_Response
{
    uint8_t                                 bit_mask;
#define  pchBindingId_present      0x80
    uint8_t                                 n_FACH;
    L1CAPI_BINDING_ID                       *ptrFACH_binding_id;
    L1CAPI_BINDING_ID                       pCH_binding_id;
    L1CAPI_Msg_Status                       msgStatus;
}L1CAPI_Sccpch_Setup_Response;

/**************************Prach Setup Response **************************************** */
typedef struct L1CAPI_Prach_Setup_Response
{
    L1CAPI_BINDING_ID                       rAch_binding_id;
    L1CAPI_Msg_Status                       msgStatus;
}L1CAPI_Prach_Setup_Response;

/**************************Common Measurements Initiation Response******************************* */
typedef struct L1CAPI_Common_Meas_Init_Response{
	uint8_t                                 bit_mask;
#define  cMeasInitResp_cellObjMeasInf_present  0x80
#define  cMeasInitResp_rachObjMeasInf_present  0x40
#define  cMeasInitResp_sfn_present			   0x20
	L1CAPI_Meas_ID                          measureID;
	L1CAPI_Msg_Status                       msgStatus;
	/* optional; set in bit_mask cMeasInitResp_cellObjMeasInf_present if present */
	L1CAPI_MeasInf                          cellObjMeasInf;
	/* optional; set in bit_mask cMeasInitResp_rachObjMeasInf_present if present */
	L1CAPI_MeasInf                          rachObjMeasInf;
	/* optional; set in bit_mask cMeasInitResp_sfn_present if present */
	L1CAPI_SFN								sfn;
} L1CAPI_Common_Meas_Init_Response;

/**************************Common Measurements Report******************************* */
typedef struct L1CAPI_Common_Meas_Report{
    uint8_t                                 bit_mask;
#define  cMeasRep_cellObjMeasInf_present  0x80
#define  cMeasRep_rachObjMeasInf_present  0x40
#define  cMeasRep_sfn_present			 0x20
	L1CAPI_Meas_ID                          measureID;
	/* optional; set in bit_mask cMeasRep_cellObjMeasInf_present if present */
	L1CAPI_MeasInf                          cellObjMeasInf;
	/* optional; set in bit_mask cMeasRep_rachObjMeasInf_present if present */
	L1CAPI_MeasInf                          rachObjMeasInf;
	/* optional; set in bit_mask cMeasRep_sfn_present if present */
	L1CAPI_SFN								sfn;
} L1CAPI_Common_Meas_Report;

/**************************Common Measurements Failure Indication******************************** */
typedef struct L1CAPI_Common_Meas_Fail_Ind{
	L1CAPI_Meas_ID                          measureID;    
	L1CAPI_Msg_Status                       msgStatus;
} L1CAPI_Common_Meas_Fail_Ind;

/**************************Radiolink Setup Response Response**************************************** */

typedef struct L1CAPI_Radiolink_Setup_Response
{
    uint8_t                                 bit_mask;
#define rl_SetupResp_hsdschInfoResp_present   0x80
    L1CAPI_NodeB_Com_Context                NodeBComContext;
    uint8_t                                 rlCount;
    L1CAPI_Msg_Status                       msgStatus;
    L1CAPI_Radiolink_Info_Resp              *ptrRlInfoResp; 
    /* optional; set in bit_mask rl_SetupResp_hsdschInfoResp_present if present */
    L1CAPI_HSDSCH_Info_Resp                 *ptrHsdschInfoResp;
}L1CAPI_Radiolink_Setup_Response;

/**************************Radio Link reconfigure Ready DCH**************************************** */
typedef struct L1CAPI_Radiolink_Reconfigure_Ready{
        uint8_t                             bit_mask;
#define rl_ReconfigResp_hsdschInfoResp_present   0x80
        uint8_t                             rlCount;
        L1CAPI_Msg_Status                   msgStatus;
        L1CAPI_Radiolink_Info_Resp          *ptrRlInfoResp; 
        /* optional; set in bit_mask rl_ReconfigResp_hsdschInfoResp_present if present */
        L1CAPI_HSDSCH_Info_Resp             *ptrHsdschInfoResp;
}L1CAPI_Radiolink_Reconfigure_Ready;

/**************************Dedicated Measurements Initiation Response****************** */
typedef struct L1CAPI_Dedicated_Meas_Init_Response{
	L1CAPI_Meas_ID                          measureID;
	L1CAPI_Msg_Status                       msgStatus;
	uint8_t								    rlCount;
	uint8_t                                 rlsCount;
	/*optional; present if rlCount!=0 */
	L1CAPI_DMeasRl_Info                     *pRLInf;
	/*optional; present if rlsCount!=0. Currently NOT SUPPORTED, rlsCount should be 0 */
	L1CAPI_DMeasRl_Info                     *pRLSInf;
} L1CAPI_Dedicated_Meas_Init_Response;

/**************************Dedicated Measurements Report******************************* */
typedef struct L1CAPI_Dedicated_Meas_Report{
	L1CAPI_Meas_ID                          measureID;
	uint8_t								    rlCount;
	uint8_t                                 rlsCount;
	/*optional; present if rlCount!=0 */
	L1CAPI_DMeasRl_Info                     *pRLInf;
	/*optional; present if rlsCount!=0. Currently NOT SUPPORTED, rlsCount should be 0 */
	L1CAPI_DMeasRl_Info                     *pRLSInf;

} L1CAPI_Dedicated_Meas_Report;

/**************************Dedicated Measurements Failure Indication******************** */
typedef struct L1CAPI_Dedicated_Meas_Fail_Ind{
	L1CAPI_Meas_ID                          measureID;
	uint8_t								    rlCount;
	L1CAPI_Radiolink_ID                     *pRl_ID;
	L1CAPI_Msg_Status                       msgStatus;
} L1CAPI_Dedicated_Meas_Fail_Ind;

typedef struct L1CAPI_FP_DL_PICH_DATA
{
   uint8_t	len;
   uint8_t      piBmp[18];
} L1CAPI_FP_DL_PICH_DATA;

typedef struct L1CAPI_FP_UL_DATA_CMN
{
#define MAX_UL_CRCI_ARRAY_SIZE   12
   union {
		uint8_t  qEstimate;
		sint8_t  rachpPower;
	};
   uint8_t  crci[MAX_UL_CRCI_ARRAY_SIZE]; /* One for each TB */
} L1CAPI_FP_UL_DATA_CMN;

/*DCH 384 kbps*/
//#define DCH_SUPPORT_384_BITRATE_BUFSIZE    (504)
//#define MAX_DCH_BUFSIZE 		DCH_SUPPORT_384_BITRATE_BUFSIZE

typedef struct L1CAPI_OUTER_LOOP_PC_REQ
{
    uint8_t            ul_SIR_Target;
}L1CAPI_OUTER_LOOP_PC_REQ;

typedef struct L1CAPI_HS_CAP_REQUEST
{
    uint8_t	           cmChPi;
    uint16_t           userBufSize;
}L1CAPI_HS_CAP_REQUEST;

typedef enum L1CAPI_HSDSCH_ALLOC_TYPE
{
    L1C_HSDSCH_ALLOC_TYPE_ONE,
    L1C_HSDSCH_ALLOC_TYPE_TWO
}L1CAPI_HSDSCH_ALLOC_TYPE;

typedef struct L1CAPI_HS_CAP_ALLOCATION
{
    L1CAPI_HSDSCH_ALLOC_TYPE    allocType;
    L1CAPI_HSDSCH_MACdFlow_ID   macdFlowId;
    uint8_t                     cmChPi;
    uint16_t                    macDPduLen;
    uint8_t                     hsDschCredits; 
    uint8_t                     hsDschInterval;
    uint8_t                     hsDschRepPeriod;
    uint8_t                     resedualPduNumber;/*for L1C debug*/
    uint16_t                    genSfn; /*for L1C debug*/
    uint8_t                     optimizedCredit; /*for L1C debug*/
}L1CAPI_HS_CAP_ALLOCATION;

typedef enum L1CAPI_FP_CTRL_MSG_TYPE
{    
    L1CAPI_MSGTYPE_HS_CAP_REQ,
    L1CAPI_MSGTYPE_HS_CAP_ALLOC,
    L1CAPI_MSGTYPE_R4_OLPC_REQ
}L1CAPI_FP_CTRL_MSG_TYPE;

typedef struct L1CAPI_FP_CTRL_MSG
{
    L1CAPI_FP_CTRL_MSG_TYPE          ctrlMsgType;
    union{
      L1CAPI_OUTER_LOOP_PC_REQ       r4OLPCReq;
      L1CAPI_HS_CAP_REQUEST          hsCapReq;
      L1CAPI_HS_CAP_ALLOCATION       hsCapAlloc;
    }u;
} L1CAPI_FP_CTRL_MSG;

typedef enum L1CAPI_DATA_FRAME_DIRECTION
{
	L1CAPI_UL_DATA_FRAME,
	L1CAPI_DL_DATA_FRAME
}L1CAPI_DATA_FRAME_DIRECTION;

typedef struct L1CAPI_FP_R4_DATA_MSG_Hdr
{
    /* optional; present for FP PCH, High 4 bits of PCH CFN in low 4 bits of the byte*/
    L1CAPI_CFN                  pchCfnHi;
    L1CAPI_CFN                  cfn;
    uint8_t                     tfi;
    /* optional; present for FP FACH, FACH Transmit Power */
    uint8_t                     fachTxPwr;
    /* optional; present for FP RACH, PRACH Propagation Delay*/
    uint8_t                     propagationDelay;
	uint8_t                     numTb;
	uint16_t                    propagationDelayQchips;
    uint16_t                    payloadLen;
	L1CAPI_DATA_FRAME_DIRECTION   direction;
    union {
      L1CAPI_FP_DL_PICH_DATA    pichInfo;
      L1CAPI_FP_UL_DATA_CMN     ulTrchCommon;
    } u;
} L1CAPI_FP_R4_DATA_MSG_Hdr;

typedef struct L1CAPI_FP_HSDSCH_DATA_Hdr
{
    uint8_t                     flags;
#define L1CAPI_FP_HSDSCH_FLUSH 0x80
    uint8_t  	                cmChPi;
    uint16_t                    macDPduLen;
    uint8_t                     numPdu; 
    uint16_t                    usrBufSize;
} L1CAPI_FP_HSDSCH_DATA_Hdr;


typedef struct L1CAPI_EDCH_SubFrameHdr
{
uint8_t  cfn;
uint8_t  SubFrameNumber;
uint8_t  numOfHarqRetransmits;
uint8_t  numOfEsPDUs;
uint8_t  DDI [L1CAPI_MAX_MAC_ES_PDUS_PER_SUBFRAME];
uint8_t  N [L1CAPI_MAX_MAC_ES_PDUS_PER_SUBFRAME];
}L1CAPI_EDCH_SubFrameHdr;


typedef struct L1CAPI_FP_EDCH_DATA_MSG_Hdr
{
/*L1CAPI_FP_MSG_TYPE           fp_msg_type;*/
uint8_t                                  macDflowId;
uint8_t                                  numOfSubframes;
//uint16_t                    			 payloadLen;//Needed  Here??????
L1CAPI_EDCH_SubFrameHdr  subFrameHeader [L1CAPI_MAX_EDCH_SUBFRAMES_PER_FRAME];
/*uint8_t                                  macPDUData[3];*/  /*3 is not the correct value, its been added to remove complilation error*/
}L1CAPI_FP_EDCH_DATA_MSG_Hdr;

typedef struct L1CAPI_FP_DATA_MSG
{    
    union {
      L1CAPI_FP_R4_DATA_MSG_Hdr   r4DataHdr;
      L1CAPI_FP_HSDSCH_DATA_Hdr   hsDschDataHdr;
      L1CAPI_FP_EDCH_DATA_MSG_Hdr edchDataHdr;
    } fpDatahdr;                  
    uint8_t                       *payload;
} L1CAPI_FP_DATA_MSG;

typedef enum L1CAPI_FP_ERROR_ID
{
	L1CAPI_FP_ERROR_INVALID_MSG = 1,
	L1CAPI_FP_ERROR_UNSUPPORTED = 2,
	L1CAPI_FP_ERROR_CFN_MISSED = 3,
	L1CAPI_FP_ERROR_UNKNOWN_BINDING_ID = 4,
	L1CAPI_FP_ERROR_UNKNOWN_CMCH_PI = 5,
	L1CAPI_FP_ERROR_UNKNOWN_MACD_PDU_LEN = 6,

}L1CAPI_FP_ERRROR_ID;

typedef struct L1CAPI_FP_ERROR_MSG
{    
    L1CAPI_FP_ERRROR_ID			errorId;		              
    
} L1CAPI_FP_ERROR_MSG;

typedef enum L1CAPI_FP_MSG_TYPE
{
    L1CAPI_MSG_TYPE_FP_CTRL,
    L1CAPI_MSG_TYPE_FP_DATA,
    L1CAPI_MSG_TYPE_FP_ERROR,

}L1CAPI_FP_MSG_TYPE;

typedef struct L1CAPI_FP_MSG
{
    L1CAPI_BINDING_ID           bindingId;
    L1CAPI_FP_MSG_TYPE          fp_msg_type;
    union {
      L1CAPI_FP_CTRL_MSG        ctrl;
      L1CAPI_FP_DATA_MSG        data;
      L1CAPI_FP_ERROR_MSG       error;	
    } u;
}L1CAPI_FP_MSG;

#endif 
