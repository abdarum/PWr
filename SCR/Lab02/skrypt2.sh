echo $0
if [ $1 == $2 ]
then
	echo $1 takie same
else
	echo $1 $2 rozne
fi
echo $3

if [ -r $3 ]
then
	echo cos
else
	echo inne cos
fi

for x in *.c
do
	echo $x
done


exec 3< dane.txt #tworzy strumień o indexie 3 i z niego czyta dane
read var <&3 #czyta pierwszą linijkę ze strumienia 3
echo $var

data=`date` # ` nazwa programu w rakich apostrofach wywołuje ten program w terminalu i wartość zwraca do zmiennej
echo $data
