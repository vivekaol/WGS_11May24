#!/bin/sh
cd /tftpboot
rm -rf UMTS_SLS.img
rm -rf pri.img
cp /home/wgs/l1images/UMTS_SLS.img .
mv UMTS_SLS.img pri.img
#systemctl stop dnsmasq.service
#sleep 5
dsp_rst.sh on
#sleep 5
dsp_rst.sh off
sleep 8
#systemctl start dnsmasq.service
#sleep 50
gps_rst.sh off
ref_clk_mux.sh gps
stty -F /dev/ttymxc2 115200 raw
sleep 30
echo "UMTS_SLS.img is loaded on Primary DSP"
