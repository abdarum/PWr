#!/bin/bash

while read p; do
	tresc="$tresc\n$p"
done <tresc.txt


while read email; do
	echo ----------------nowy email-----------------------
	echo *Adres email:
	echo "$email"

	echo *Tresc: 
	echo -e $tresc

	echo *Załączniki:
	ls spec*.pdf
done <adresy.txt

