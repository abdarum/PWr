#!/bin/bash

if [ $# -eq 3 ]
then
	maska_wyszukiwania=$1
	liczba_dni=$2
        nazwa_archiwum=$3
	lista=`find -name "$maska_wyszukiwania" -and \( -mtime "-$liczba_dni" -or -mtime "$liczba_dni" \)`
	echo $lista
	tar -cvf $nazwa_archiwum $lista

else
        echo "Nieprawidłowa liczba argumentów, powinno być 3, a jest: $#"
fi
