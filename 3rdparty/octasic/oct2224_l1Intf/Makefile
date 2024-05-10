#################################################################################
#
# File: Makefile
#
# Copyright (c) 2017 Octasic Inc. All rights reserved.
#
# Description: 
#
#   Layer1 Control Interface Library Makefile
#
# Octasic_Release: OCTSDR-SR-UMTS-GEN-02.01.01-B26-ALPHA (2017/05/02)
#
# $Revision: $
#
#################################################################################

## Initially compile for x86 whilst coding

ifndef CROSS_CC_PREFIX
  CROSS_CC_PREFIX=$(CROSS_COMPILE)
endif

CC=$(CROSS_CC_PREFIX)arm-cortexa9-linux-gnueabi-gcc
AR=$(CROSS_CC_PREFIX)ar
LD=$(CROSS_CC_PREFIX)ld
RANLIB=$(CROSS_CC_PREFIX)ranlib
#CFLAGS=-Wall -g -O2
CFLAGS=-Wall -O2

## Check for DEBUG environment
ifndef DEBUG
  DEBUG=0
endif

ifdef ARCH_PPC
  CFLAGS += -DARCH_PPC
endif

ifndef USER_PROC_DIR
  USER_PROC_DIR=.
endif
                                                                                
ifndef SA_DIR
  SA_DIR=../CCPU
endif

ifndef CMN_DIR
  CMN_DIR=../CCPU
endif

all: default

## Include path
INCLUDE = -IMsgDecHdlrs/inc \
          -IMsgEncHdlrs/inc \
          -IParamsValidate/inc \
          -ISerilization/inc \
          -IUserConvHdlrs/inc \
          -IStructDefs/inc \
          -IFpEncDecHdlrs/inc\
          -I$(SA_DIR)\
          -I$(CMN_DIR)

## Extend CFLAGS
CFLAGS += $(INCLUDE) -DDEBUG=$(DEBUG) -UADAPT_CCPU_L1IF -DSTDIO_INCLD -UL1C_TRACE_CONTENT -DPRINT_IO_CONSOLE

OBJS =  UserConvHdlrs/src/L1C_cctrchConvHdlr.o \
        UserConvHdlrs/src/L1C_cellProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_commonMeasProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_phyShareCHProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_prachProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_radiolinkProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_radiolinkProcedureEdchConvHdlr.o \
        UserConvHdlrs/src/L1C_radiolinkProcedureHsDschConvHdlr.o \
        UserConvHdlrs/src/L1C_dedicatedMeasProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_responseProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_sccpchProcedureConvHdlr.o \
        UserConvHdlrs/src/L1C_tfsConvHdlr.o \
        ParamsValidate/src/L1C_cctrchParamValidate.o \
        ParamsValidate/src/L1C_cellProcedureParamValidate.o \
        ParamsValidate/src/L1C_commonMeasProcedureParamValidate.o \
        ParamsValidate/src/L1C_phyShareCHProcedureParamValidate.o \
        ParamsValidate/src/L1C_prachProcedureParamValidate.o \
        ParamsValidate/src/L1C_radiolinkProcedureEdchParamValidate.o \
        ParamsValidate/src/L1C_radiolinkProcedureHsDschParamValidate.o \
        ParamsValidate/src/L1C_radiolinkProcedureParamValidate.o \
        ParamsValidate/src/L1C_dedicatedMeasProcedureParamValidate.o \
        ParamsValidate/src/L1C_sccpchProcedureParamValidate.o \
        ParamsValidate/src/L1C_tfsParamValidate.o \
        Serilization/src/msgGetPrimitives.o \
        Serilization/src/msgPutPrimitives.o \
        Serilization/src/msgPrimitives.o \
        Serilization/src/msgHeaderCodec.o \
        MsgDecHdlrs/src/L1C_responseProcDecHdlr.o \
        MsgEncHdlrs/src/L1C_cctrchEncHdlr.o \
        MsgEncHdlrs/src/L1C_modemSetupEncHdlr.o \
        MsgEncHdlrs/src/L1C_cellProcedureEncHdlr.o \
        MsgEncHdlrs/src/L1C_commonMeasProcedureEncHdlr.o \
        MsgEncHdlrs/src/L1C_phyShareCHProcedureEncHdlr.o \
        MsgEncHdlrs/src/L1C_prachProcedureEncHdlr.o \
        MsgEncHdlrs/src/L1C_radiolinkProcedureEdchEncHdlr.o \
        MsgEncHdlrs/src/L1C_radiolinkProcedureEncHdlr.o \
        MsgEncHdlrs/src/L1C_radiolinkProcedureHsDschEncHdlr.o \
        MsgEncHdlrs/src/L1C_dedicatedMeasProcedureEncHdlr.o \
        MsgEncHdlrs/src/L1C_sccpchProcedureEncHdlr.o \
        MsgEncHdlrs/src/L1C_sysInfoEncHdlr.o \
        MsgEncHdlrs/src/L1C_tfsEncHdlr.o \
        FpEncDecHdlrs/src/L1C_FpDecHdlr.o \
        FpEncDecHdlrs/src/L1C_FpEncHdlr.o 
        
        
## Our build target
TARGET := libl1cif.a

default: $(TARGET)

## Targets
$(TARGET): $(OBJS)
	$(AR) -cr $@ $(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJS) $(TARGET)
