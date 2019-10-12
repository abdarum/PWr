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
	echo
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

if [ "$maska_wyszukiwania" == "$zmienna_bledu" ] && [ "$liczba_dni" == "$zmienna_bledu" ] && [ "$nazwa_archiwum" == "$zmienna_bledu" ]; then
	disp_help
fi

if [ "$maska_wyszukiwania" == "$zmienna_bledu" ]; then
	echo "Podaj parametr maski wyszukiwania"
	maska_wyszukiwania=`line`
fi

if [ "$liczba_dni" == "$zmienna_bledu" ]; then
	echo "Podaj parametr liczby dni w ciągu których plik był modyfikowany"
	liczba_dni=`line`
fi

if [ "$nazwa_archiwum" == "$zmienna_bledu" ]; then
	echo "Podaj parametr nazwy archiwum do którego te pliki będą spakowane"
	nazwa_archiwum=`line`
fi


lista=`find -name "$maska_wyszukiwania" -and \( -mtime "-$liczba_dni" -or -mtime "$liczba_dni" \)`
echo "Znalezione pliki"
echo $lista
echo "Pliki spakowane do archiwum"
tar -cvf $nazwa_archiwum $lista
