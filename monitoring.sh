
archi=$(uname -a)

CPU=$(lscpu | grep "Socket(s)")

vCPU=$(lscpu | grep "CPU(s):")

memuse=$()

diskuse=$()

CPUL=$()

lastb=$()

LVM=$()

CTCP=$()

userlog=$()

netw=$()

Sud=$()

wall "	#Architecture: $archi
		#CPU physical :
		#vCPU : 
		#Memory Usage:
		#Disk Usage :
		#CPU load:
		#Last boot:
		#LVM use:
		#Connections TCP :
		#User log:
		#Network:
		#Sudo : 
