#!/bin/sh

#This binary calls setTREX binary to control the CA-TREX amplifier
#
#Commands include:
# t (for tower scanning) or i (for ID catching)
# followed by the DL band number

cd /home/wgs/scripts/
./setTREX $1 $2
