#------------------------------- Relative utility path ---------------------------------#
#
# Specify the relative path ... where Makefile utilities are located
#
#---------------------------------------------------------------------------------------#
BUILD = ./
PLATFORM=Linux

#---------------------------------- Application type -----------------------------------#
#
# Specify the application type: Exe, archive (.a) or dynamic lib (.so)
#
# APP_TYPE= exe, lib or dll
# APP_EXT=	# Allow to specify application extension (not use for librarie)
#
#---------------------------------------------------------------------------------------#
#APP_EXT=
APP_TYPE = exe

#------------------------------ Application or lib name --------------------------------#
#
# Specify the target file base name
#
#---------------------------------------------------------------------------------------#
APP_NAME = oneBin

#----------------------------------- Makefile name -------------------------------------#
#
# Predefined in Makefile.pre 
# Default is $(APP_NAME).mak
# May be overrided
#
#---------------------------------------------------------------------------------------#
#MAKEFILENAME = Makefile

#------------------------------------ Config name --------------------------------------#
#
# To use when same application may have various configurations
# Affect object path directory name: (see OBJPath )
# 	
#---------------------------------------------------------------------------------------#
#CONFIGNAME = 

#------------------------------- Object path definition --------------------------------#
#
# Predefined in Makefile.pre
# May be overrided
# Default is OBJPATH = $(CONFIGNAME_)$(BUILD_DIR)$(OBJ_PATH_SUFFIX)
#
#---------------------------------------------------------------------------------------#
#OBJPATH = 

#---------------------------- Application or lib full name -----------------------------#
#
# Predefined in Makefile.pre
# May be overrided
#
# where $(APP_FULL_NAME) = $(FILE_PREFIX)$(APP_NAME)$(CONFIGNAME)$(TGT_SUFFIX)$(FILE_EXT)
#---------------------------------------------------------------------------------------#
#APP_FULL_NAME = 

#-------------------------- App compiler specific directive ----------------------------#
#
# Added to CCFLAGS
#
#---------------------------------------------------------------------------------------#
#APP_CC_FLAGS = -DSTDIO_INCLD -DWGS_LICENSING -UOCTVC1_OPT_DECLARE_DEFAULTS -D_OCT_ENDIAN_TYPE_LE_ -D__ARMEL__ -DOCTVC1_STRING2LIC_DECLARE -std=c99 -Wall -O2 -I.
APP_CC_FLAGS = -DSTDIO_INCLD -UOCTVC1_OPT_DECLARE_DEFAULTS -D_OCT_ENDIAN_TYPE_LE_ -D__ARMEL__ -DOCTVC1_STRING2LIC_DECLARE -std=c99 -Wall -O2 -I.

#-----------------------------------  Make utility -------------------------------------#
#
# Utility for target system and cross platform related utilities
#
#---------------------------------------------------------------------------------------#
include $(BUILD)/Makefile.pre

#----------------------------  Source file sub directory -------------------------------#
# 
# Directory where source file are located. (Related to this make file path )
#
#---------------------------------------------------------------------------------------#
SRC_DIR = ../sls/src ../callcontrol/3g/app/src ../callcontrol/3g/cmn/src ../callcontrol/3g/rrc/src \
		  ../callcontrol/2g/src ../callcontrol/4g/src ../3rdparty/octasic/oct2224_l1Intf/UserConvHdlrs/src ../3rdparty/octasic/oct2224_l1Intf/ParamsValidate/src ../3rdparty/octasic/oct2224_l1Intf/Serilization/src ../3rdparty/octasic/oct2224_l1Intf/MsgDecHdlrs/src ../3rdparty/octasic/oct2224_l1Intf/FpEncDecHdlrs/src ../3rdparty/octasic/oct2224_l1Intf/MsgEncHdlrs/src ../3rdparty/octasic/oct2224_l1IoApi/src
# ../3rdparty/octasic/dlimlib/src ../3rdparty/octasic/txbufgen/src

#-----------------------------------  Source files -------------------------------------#
# 
# List of source files.
#
#---------------------------------------------------------------------------------------#
      #  wnm.c \
      #
SRC_FILES = \
	L1C_cctrchConvHdlr.c \
	L1C_cellProcedureConvHdlr.c \
	L1C_commonMeasProcedureConvHdlr.c \
	L1C_phyShareCHProcedureConvHdlr.c \
	L1C_prachProcedureConvHdlr.c \
	L1C_radiolinkProcedureConvHdlr.c \
	L1C_radiolinkProcedureEdchConvHdlr.c \
	L1C_radiolinkProcedureHsDschConvHdlr.c \
	L1C_dedicatedMeasProcedureConvHdlr.c \
	L1C_sccpchProcedureConvHdlr.c \
	L1C_responseProcedureConvHdlr.c \
	L1C_tfsConvHdlr.c \
	L1C_cctrchParamValidate.c \
	L1C_cellProcedureParamValidate.c \
	L1C_commonMeasProcedureParamValidate.c \
	L1C_phyShareCHProcedureParamValidate.c \
	L1C_prachProcedureParamValidate.c \
	L1C_radiolinkProcedureEdchParamValidate.c \
	L1C_radiolinkProcedureHsDschParamValidate.c \
	L1C_radiolinkProcedureParamValidate.c \
	L1C_dedicatedMeasProcedureParamValidate.c \
	L1C_sccpchProcedureParamValidate.c \
	L1C_tfsParamValidate.c \
	L1C_tfsEncHdlr.c \
	L1C_FpDecHdlr.c \
	L1C_FpEncHdlr.c \
	msgGetPrimitives.c \
	msgPutPrimitives.c \
	msgPrimitives.c \
	msgHeaderCodec.c \
	L1C_responseProcDecHdlr.c \
	L1C_cctrchEncHdlr.c \
	L1C_modemSetupEncHdlr.c \
	L1C_cellProcedureEncHdlr.c \
	L1C_commonMeasProcedureEncHdlr.c \
	L1C_phyShareCHProcedureEncHdlr.c \
	L1C_prachProcedureEncHdlr.c \
	L1C_radiolinkProcedureEdchEncHdlr.c \
	L1C_radiolinkProcedureEncHdlr.c \
	L1C_radiolinkProcedureHsDschEncHdlr.c \
	L1C_dedicatedMeasProcedureEncHdlr.c \
	L1C_sccpchProcedureEncHdlr.c \
	L1C_sysInfoEncHdlr.c \
	oct_etherApi.c \
	oct_l1cIoApi.c \
	oct_l1cIoDebug.c \
	oct_l1cIoInit.c \
	oct_util_license.c \
	oct_util_config.c \
	octWgsLicense.c \
    sls.c \
	slsDecode2g.c \
	slsDecode3g.c \
	ratSocketItf.c \
	octsamples_pkt_api_session.c \
	octsamples_string_utils.c \
	oct_common_getopt.c \
    callCDefaultParam.c \
    clSendL1Msg.c \
	memAlloc.c \
    rlcUlDataHndlr.c \
    callCMain.c	\
    l2TaskHndlr.c \
	rlcAmData.c \
    rlcUmTx.c \
    callCMainUtil.c \
    macCfgHndlr.c \
	rlcCfgHndlr.c \
    rrcCellSetup.c \
    callCSysInfoUpdate.c  \
    macContext.c \
    rlcContext.c \
    rrcMsg.c \
    callCTaskHndlr.c \
    macDlDataHndlr.c \
    rlcDlDataIndHndlr.c \
    clL1RcvMsg.c \
    macUlDataHndlr.c \
	rlcDlSduHndlr.c \
    msgQue.c \
    cmnDebug.c \
    taskHndlr.c \
    timerApi.c \
    timer.c \
    rrcMain.c \
    rrcRcvMsg.c \
	cleanChannelSelectionManager.c \
	dataIndMsgHandler.c \
	gprsLlcSndcpMsgHandler.c \
	gprsRlcMacMsgHandler.c \
	gprsRlcMacEncDec.c \
	gsmCommon.c \
	l1InterfaceManager.c \
	l2Scheduler.c \
	lapdm.c \
	linkedlist.c \
	logManager.c \
	main.c \
	rtsTxMsgHandler.c \
	sysInfo.c \
	sms.c \
	transactionMemoryManager.c \
	userManager.c \
	lteCmn.c \
	lteAsn1IntfcHandler.c \
	lteBufferManager.c \
	lteL1IfApi.c \
	lteLayer1IfManager.c \
	lteMacEncDec.c \
	lteMacIntfcHandler.c \
	lteMacScheduler.c \
	lteUserManager.c \
	rawSocketApi.c \
	slsDecode4g.c \
	lteRrcIntfcHandler.c \
    lteRrcMain.c \
    lteRlcEncDec.c \
    lteRlcIntfcHandler.c \
    lteAutoConfigManager.c \
	obm_battery_stats.c \
	obm_board_info.c \
	obm_board_stop.c \
	obm_board_update.c \
	obm_dsp_info.c \
	obm_dsp_reset.c \
	obm_gps_info.c \
	obm_gps_reset.c \
	obm_gps_stats.c \
	obm_power_switch.c \
	obm_rf_amplifier.c \
	obm_rf_frequency.c \
	obm_rf_info.c \
	obm_refclk_in.c \
	obm_refclk_out.c \
	obm_target_info.c \
	obm_i2c_read.c \
	obm_i2c_write.c \
    obm_config_write.c \
	obm_gps_antenna.c \
	obm.c \
	obm_system_info.c \
	obm_system_modify.c \
	obm_board_attach.c \
	obm_board_detach.c \
	obm_board_modify.c \
	obm_dsp_modify.c \
	obm_eth_switch_info.c \
	obm_eth_switch_modify.c \
	obm_eth_switch_stats.c \
	obm_gps_modify.c \
	obm_rf_modify.c \
	obm_rf_stats.c \
#	dlim_addsch.c \
#	dlim_calculate_psc.c \
#	dlim_calculate_ssc.c \
#	dlim_generatesyncch.c \
#	dlim_goldgenframe_r4.c \
#	dlim_goldgenslot_r4.c \
#	dlim_pwrmgr.c \
#	dlim_pwrmgr_tables.c \
#	dlim_qpskmodulation.c \
#	dlim_sch_tables.c \
#	dlim_sprdscramblecombine.c
	
#	obm_board_stop.c \
#	obm_board_update.c \
#	obm_dsp_info.c \
#	obm_dsp_reset.c \
#	obm_gps_info.c \
#	obm_gps_reset.c \
#	obm_gps_stats.c \
#	obm_power_switch.c \
#	obm_rf_amplifier.c \
#	obm_rf_frequency.c \
#	obm_rf_info.c \
#	obm_refclk_in.c \
#	obm_refclk_out.c \
#	obm_target_info.c \
#	obm_i2c_read.c \
#	obm_i2c_write.c \
# 
# List of depended libraries ... automatically rebuild by make 'all' rules
#		(related $(BUILD) path )
#
#---------------------------------------------------------------------------------------#
OCTLIB_DEP = \
	../octvc1pktapi/octvc1pktapi.mak \
	../common/octtransapi/octtransapi/octtransapi.mak \
	../common/octtransapi/octtransapi_eth/octtransapi_eth.mak \
	../common/octtransapi/octtransapi_udp/octtransapi_udp.mak \
	../common/octtransapi/octtransapi_tcp/octtransapi_tcp.mak \
	../common/octosal/octosal.mak
	
#------------------------------------- Other libs --------------------------------------#
# 
# Other libs to link with
#
#---------------------------------------------------------------------------------------#
OCTLIBS +=../lib/arm/oneAsn1Lib.a ../lib/arm/runtime.a ../lib/arm/libGsmEnDec.a

#--------------------------------  Post build command ----------------------------------#
# 
# Normally use to copy and remove libs to default path $(BUILD)../lib
#
#---------------------------------------------------------------------------------------#
POSTBUILD = mv Debug32/oneBind ../bin/oneBin
POSTBUILD_CLEAN = rm -f -R ../bin/oneBin

#----------------------  List of application specific includes -------------------------#
# 
#---------------------------------------------------------------------------------------#
INC +=  -I../sls/inc  \
	-I../callcontrol/3g/rrc/inc  \
	-I../callcontrol/3g/app/inc  \
	-I../callcontrol/3g/cmn/inc  \
	-I../callcontrol/2g/inc  \
	-I../callcontrol/2g/endec/inc  \
	-I../callcontrol/4g/inc  \
	-I../3rdparty/octasic/oct2224_l1Intf/MsgDecHdlrs/inc \
	-I../3rdparty/octasic/oct2224_l1Intf/MsgEncHdlrs/inc \
	-I../3rdparty/octasic/oct2224_l1Intf/ParamsValidate/inc \
	-I../3rdparty/octasic/oct2224_l1Intf/Serilization/inc \
	-I../3rdparty/octasic/oct2224_l1Intf/UserConvHdlrs/inc \
	-I../3rdparty/octasic/oct2224_l1Intf/StructDefs/inc \
	-I../3rdparty/octasic/oct2224_l1Intf/FpEncDecHdlrs/inc \
	-I../3rdparty/octasic/FXLYNX \
	-I../3rdparty/octasic/oct2224_l1IoApi/inc \
        -I../common/octosal/include \
        -I../common/include \
        -I../sls/inc/octvc1 \
#        -I../3rdparty/octasic/dlimlib/inc \
#        -I../3rdparty/octasic/txbufgen/inc

#------------------------- List of application specific flags --------------------------#
# 
#---------------------------------------------------------------------------------------#
CCFLAGS +=

#-------------------------------- Defaults make rules ----------------------------------#
# 
#---------------------------------------------------------------------------------------#
include $(BUILD)/Makefile.rules

