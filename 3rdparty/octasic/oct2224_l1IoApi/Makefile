###############################################################################
#
# File: Makefile
#
# Copyright (c) 2017 Octasic Inc. All rights reserved.
#
# Description: 
#
#   Layer1 Control I/O Library Makefile
#
# Octasic_Release: OCTSDR-SR-UMTS-GEN-02.01.01-B26-ALPHA (2017/05/02)
#
# $Revision: $
#
###############################################################################
## Initially compile for x86 whilst coding

ifndef CROSS_CC_PREFIX
  CROSS_CC_PREFIX=$(CROSS_COMPILE)
endif

CC=$(CROSS_CC_PREFIX)gcc
AR=$(CROSS_CC_PREFIX)ar
LD=$(CROSS_CC_PREFIX)ld
RANLIB=$(CROSS_CC_PREFIX)ranlib
#CFLAGS=-Wall -g -O2
CFLAGS=-Wall -O2

all: default

## Include path
INCLUDE = -Iinc \
          -I../oct_l1Intf/StructDefs/inc \
          -I../oct_l1Intf/Serilization/inc

ifndef DEBUG
  DEBUG=0
endif
                                                                                
## Extend CFLAGS
CFLAGS += $(INCLUDE) -DDEBUG=$(DEBUG)

OBJS = src/oct_etherApi.o src/oct_l1cIoApi.o src/oct_l1cIoDebug.o src/oct_l1cIoInit.o 

## Our build target
TARGET := liboctl1cioapi.a

default: $(TARGET)

## Targets
$(TARGET): $(OBJS)
	$(AR) -cr $@ $(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJS) $(TARGET)
