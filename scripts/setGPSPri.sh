#!/bin/sh

sleep 5
#gps_rst.sh on
#ref_clk_mux.sh  ext
sleep 2
#oct2200cat w 0x9009c018 0x7ccc
#oct2200cat w 0x9009c018 < /home/wgs/scripts/gps_val.bin
sleep 2
echo "GPS set"
