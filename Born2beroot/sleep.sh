#!bin/bash

min_boot=$(uptime -s | awk  -F ":" '{print $2}')
sec_boot=$(uptime -s | awk  -F ":" '{print $3}')

delay=$(($min_boot%10*60+$sec_boot))

sleep "$delay"

#calculates the minutes from the nearest 10th mins
#$min_boot%10*60 minutes from the 10th min in seconds + seconds
#=delay to wait for to be 10 minutes after server startup
# (()) means arithmetic expansion

