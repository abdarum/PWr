#!/bin/bash 

if [ "$#" -ne 1 ]; then
	text="Hi"
else
	text="$1"
fi

counter=0
while true
do 
	echo "$text, $counter"
	sleep 5
	counter=$((counter+1))
done
