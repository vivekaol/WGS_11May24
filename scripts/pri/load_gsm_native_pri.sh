#!/bin/sh

cd /tftpboot
rm -f GSM_NATIVE.img
rm -f pri.img
cp /home/wgs/l1images/GSM_NATIVE.img .
mv GSM_NATIVE.img pri.img
#systemctl stop dnsmasq.service
#sleep 1
dsp_rst.sh on
sleep 1
dsp_rst.sh off
#sleep 1
#systemctl start dnsmasq.service
echo "Please wait, L1-Image is loading . . ."
sleep 10
gps_rst.sh off
ref_clk_mux.sh gps
stty -F /dev/ttymxc2 115200 raw
sleep 30
echo "Done!"
echo "GSM ID-Catcher is UP and RUNNING on PRI-DSP !"
