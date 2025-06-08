#!/bin/bash

#Architecture
arch="$(uname -a)"

#Number of physical CPU
cpu_p="$(grep '^physical id' /proc/cpuinfo | wc -l)"

#Number of virtual CPU
cpu_v="$(grep '^processor' /proc/cpuinfo | wc -l)"

#Available RAM
mem_total="$(free --mega | grep '^Mem' | awk '{print $2}')"
mem_used="$(free --mega | grep '^Mem' | awk '{print $3}')"
mem_percent="$(free --mega | grep '^Mem' | awk '{printf "%.2f", $3*100/$2}')"

#Available storage on server
d_total="$(df -m | grep '/dev/' | grep -v '/boot' | awk '{sum+=$2} END {print sum}')"
d_used="$(df -m | grep '/dev/' | grep -v '/boot' | awk '{sum+=$3} END {print sum}')"
d_percent="$(df -m | grep '/dev/' | grep -v '/boot' | awk '{sum_t+=$2} {sum_u+=$3} END {printf "%d", sum_u*100/sum_t}')"

#CPU usage
cpu_u="$(top -bn 4 -d 0.01 | grep '^%Cpu' | tail -1 | awk '{printf "%.1f", $2+$4+$6}')"

#Last reboot
reboot="$(who -b | awk '{print $3 " " $4}')"

#LVM status
if [ $(lsblk | awk '{print $6}' | grep 'lvm' | wc -l) -gt 0 ]; then
	lvm_status="yes"
else
	lvm_status="no"
fi

#Number of active connections
tcp="$(ss -t | grep 'ESTAB' | wc -l)"

#Number of active users
users="$(users | wc -w)"

#IPv4 and MAC adress

#Number of sudo commands

wall "	#Architecture: $arch
	#CPU physical: $cpu_p
	#vCPU: $cpu_v
	#Memory Usage: $mem_used/${mem_total}MB ($mem_percent%)
	#Disk Usage: $d_used/$d_total (${d_percent}%)
	#CPU load: ${cpu_u}%
	#Last boot: $reboot
	#LVM use: $lvm_status
	#Connections TCP: $tcp
	#User log: $users
	#Network: 
	#Sudo: "

