#!/bin/sh

cd /tftpboot
rm -f GSM_SLS.img
rm -f sec.img
cp /home/wgs/l1images/GSM_SLS.img .
mv GSM_SLS.img sec.img
#systemctl stop dnsmasq.service
#sleep 1
dsp_rst.sh on s
#sleep 1
dsp_rst.sh off s
#sleep 1
#systemctl start dnsmasq.service
echo "Please wait, L1-Image is loading . . ."
sleep 10
gps_rst.sh off
ref_clk_mux.sh gps                                  
stty -F /dev/ttymxc2 115200 raw                     
sleep 30                                            
echo "Done!"
echo "GSM SCANNER is UP and RUNNING on SEC_DSP !"
