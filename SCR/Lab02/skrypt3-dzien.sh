#!/bin/bash

dzien=`date +%u`

if [ $dzien -ge 1 ] && [ $dzien -le 5 ] ; then
	echo Nie ma to jak dobrze zacząć pracę
else
	echo Niech żyje weekend
fi

echo `date +"Aktualny czas to: %A %F %R"`

