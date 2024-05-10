#!/bin/bash
sleep 30
ME=`whoami`

IPCS_S=`ipcs -s | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`
IPCS_M=`ipcs -m | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`
IPCS_Q=`ipcs -q | egrep "0x[0-9a-f]+ [0-9]+" | grep $ME | cut -f2 -d" "`


for id in $IPCS_M; do
  ipcrm -m $id;
done

for id in $IPCS_S; do
  ipcrm -s $id;
done

for id in $IPCS_Q; do
  ipcrm -q $id;
done
cd /home/wgs/scripts
setTREX.sh t 20
cd /usr/share/mrvl
uaputl.exe sys_config /usr/share/mrvl/config/uaputl.conf
uaputl.exe bss_start
sleep 5
ifconfig uap0 192.168.10.100
cd /home/wgs/bin
./wgsIdCatcher &
./wgsPvtNw &
exit 0

