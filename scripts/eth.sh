#!/bin/sh
echo 7 > /sys/devices/platform/enet.0/net/eth0/queues/rx-0/rps_cpus
sleep 1
echo 8 > /proc/irq/150/smp_affinity
sleep 1
chrt -pf 90 1135
sleep 1
taskset -p 8 1135
sleep 1
chrt -pf 89 25
