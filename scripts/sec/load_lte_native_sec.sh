#!/bin/sh
cd /tftpboot
rm -rf LTE_NATIVE.img
rm -rf sec.img
cp /home/wgs/l1images/LTE_NATIVE.img .
mv LTE_NATIVE.img sec.img
#systemctl stop dnsmasq.service
#sleep 10
dsp_rst.sh on s
#sleep 10
dsp_rst.sh off s
sleep 10
#systemctl start dnsmasq.service
#sleep 10
gps_rst.sh off
ref_clk_mux.sh gps
stty -F /dev/ttymxc2 115200 raw
sleep 30
echo "LTE_NATIVE.img is loaded on Secondary DSP"
