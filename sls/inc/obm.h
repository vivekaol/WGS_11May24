/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\

File: obm.h

$Octasic_Copyright: $

Description:

Command-line utility to interface with obmd, the obm daemon.

$Octasic_Confidentiality: $

$Octasic_Release: $

$Revision: $

\*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

#ifndef __OBM_H__
#define __OBM_H__


/***************************  INCLUDES  ******************************/
#include "oct_common_getopt.h"

#include "octvc1/pkt_api/octvc1_pkt_api.h"
#include "octvc1/pkt_api/octvc1_pkt_api_default.h"

#include "octvc1/obm/octvc1_obm_api.h"
#include "octvc1/obm/octvc1_obm_evt.h"
#include "octvc1_macro.h"

#if 0
/* Octvc1 API header files */
#pragma pack(push,1)
#include "main/octvc1_main_api.h"
#include "main/octvc1_main_default.h"
#include "main/octvc1_main_api_swap.h"
#include "obm/octvc1_obm_default.h"
#include "obm/octvc1_obm_api_swap.h"
#include "obm/octvc1_obm_evt_swap.h"
#include "obm/octvc1_obm_version.h"
#pragma pack(pop)
#endif

/***************************  MACROS  ******************************/
#define STR2(_x)	#_x
#define STR(_x)	STR2(_x)
#define mCOUNTOF(_x)	(sizeof(_x)/sizeof(_x[0]))
#define mMIN(_a, _b)	((_a) < (_b) ? (_a) : (_b))
#define mBUILD_IP(a,b,c,d)	( (((a)&0xff)<<24) | (((b)&0xff)<<16) |(((c)&0xff)<<8) |(((d)&0xff)<<0))

/***************************  TYPES  ******************************/
typedef struct _OBM_CONTEXT_
{

	tPOCTVC1_PKT_API_SESS		pPktApiSession;
	tPOCTVC1_PKT_API_CNCT		pPktApiConnection;
	tOCTTRANSAPI_HANDLE			hTransport;
	tOCTTRANSAPI_TCP_ADDRESS	RemoteTcpAddress;
	tPOCTVC1_PKT_API_INST		pPktApiInstance;
	tOCT_UINT32					ulBoardId;

} tOBM_CONTEXT, *tPOBM_CONTEXT;

typedef struct _OBM_COMMAND_DESCRIPTOR_
{
	tOCT_UINT32 (*pfctCallBack)( int , char* argv[] );
	char * szCommand;
	char * szShorthand;
	char * szSyntax;
	char * szDesc;
	char * szHelp;

} tOBM_COMMAND_DESCRIPTOR, *tPOBM_COMMAND_DESCRIPTOR;

/***************************  PROTOTYPES ******************************/
#define cCOMMON_OPTIONS "b:r:"
extern int ProcessCommonOptions( void );
extern tOCT_UINT32 InitPktApi(void);
extern void ClosePktApi(void);


/***************************  EXTERNALS ******************************/

extern tOBM_CONTEXT g_Context;

/* Command descriptors */
extern tOBM_COMMAND_DESCRIPTOR g_InfoCmd;
extern tOBM_COMMAND_DESCRIPTOR g_BoardInfoCmd;
extern tOBM_COMMAND_DESCRIPTOR g_BoardModifyCmd;
extern tOBM_COMMAND_DESCRIPTOR g_BoardStopCmd;
extern tOBM_COMMAND_DESCRIPTOR g_BoardDetachCmd;
extern tOBM_COMMAND_DESCRIPTOR g_BoardAttachCmd;
extern tOBM_COMMAND_DESCRIPTOR g_BoardUpdateCmd;
extern tOBM_COMMAND_DESCRIPTOR g_RefClkInCmd;
extern tOBM_COMMAND_DESCRIPTOR g_RefClkOutCmd;
extern tOBM_COMMAND_DESCRIPTOR g_DspInfoCmd;
extern tOBM_COMMAND_DESCRIPTOR g_DspResetCmd;
extern tOBM_COMMAND_DESCRIPTOR g_GpsResetCmd;
extern tOBM_COMMAND_DESCRIPTOR g_GpsInfoCmd;
extern tOBM_COMMAND_DESCRIPTOR g_GpsStatsCmd;
extern tOBM_COMMAND_DESCRIPTOR g_GpsModifyCmd;
extern tOBM_COMMAND_DESCRIPTOR g_PowerSwitchCmd;
extern tOBM_COMMAND_DESCRIPTOR g_RfAmplifierCmd;
extern tOBM_COMMAND_DESCRIPTOR g_RfFrequencyCmd;
extern tOBM_COMMAND_DESCRIPTOR g_RfInfoCmd;
extern tOBM_COMMAND_DESCRIPTOR g_RfModifyCmd;
extern tOBM_COMMAND_DESCRIPTOR g_RfStatsCmd;
extern tOBM_COMMAND_DESCRIPTOR g_ReadI2cCmd;
extern tOBM_COMMAND_DESCRIPTOR g_WriteI2cCmd;
extern tOBM_COMMAND_DESCRIPTOR g_ConfigWriteCmd;
extern tOBM_COMMAND_DESCRIPTOR g_BatteryStatsCmd;
extern tOBM_COMMAND_DESCRIPTOR g_GpsAntennaCmd;
extern tOBM_COMMAND_DESCRIPTOR g_SystemInfoCmd;
extern tOBM_COMMAND_DESCRIPTOR g_SystemModifyCmd;
extern tOBM_COMMAND_DESCRIPTOR g_DspModifyCmd;
extern tOBM_COMMAND_DESCRIPTOR g_EthSwitchStatsCmd;
extern tOBM_COMMAND_DESCRIPTOR g_EthSwitchModifyCmd;
extern tOBM_COMMAND_DESCRIPTOR g_EthSwitchInfoCmd;

#endif /* __OBM_H__ */
