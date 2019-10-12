#!/bin/bash 

if [ "$#" -ne 1 ]; then
	text="Hi"
else
	text="$1"
fi

counter=0
while true
do 
	echo "$text, $counter   `date +"%A %F %R"`"
	#date +"%A %F %R"
	sleep 1
	counter=$((counter+1))
done
