#!/bin/bash

zmienna_bledu="ERROR_VAR"
maska_wyszukiwania=$zmienna_bledu # -m
liczba_dni=$zmienna_bledu # -n 
nazwa_archiwum=$zmienna_bledu # -a
lista=$zmienna_bledu

function disp_help {
	echo "    Skrypt: $0"
	echo "Wyszukiwanie plików o podanej masce, podanym czasie modyfikacji"
        echo "oraz możliwością pakowania ich do archiwum"
	echo
	echo "-m  - maska wyszukiwania"
	echo "-n  - liczba dni w ciągu których plik był modyfikowany"
	echo "-a  - nazwa archiwum do którego te pliki będą spakowane"
	echo "-h  - wyświetla dostępne opcje"
	exit
}


while getopts a:n:m:h name; do
	case $name in
		a)
			nazwa_archiwum=${OPTARG}
			;;
		n)
			liczba_dni=${OPTARG} 
			;;
		m)
			maska_wyszukiwania=${OPTARG} 
			;;
		h)
			disp_help
			;;
		*)
			echo Niepoprawna opcja
			disp_help

	esac
done

#echo $maska_wyszukiwania
#echo $liczba_dni
#echo $nazwa_archiwum

if [ "$maska_wyszukiwania" != "$zmienna_bledu" ]; then
	if [ "$liczba_dni" != "$zmienna_bledu" ]; then
		lista=`find -name "$maska_wyszukiwania" -and \( -mtime "-$liczba_dni" -or -mtime "$liczba_dni" \)`
	else
		lista=`find -name "$maska_wyszukiwania"`
	fi
	echo $lista
else
	if [ "$liczba_dni" != "$zmienna_bledu" ]; then
		lista=`find  -mtime "-$liczba_dni" -or -mtime "$liczba_dni" `
		echo $lista
	else
		echo Nie podano żadnych parametrów
		disp_help
	fi

fi

if [ "$nazwa_archiwum" != "$zmienna_bledu" ]; then
	if [ "$lista" != "$zmienna_bledu" ]; then
		tar -cvf $nazwa_archiwum $lista
	else
		echo Nie podano parametrów wyszukiwania. Archiwum nie zostało utworzone
	fi
fi
