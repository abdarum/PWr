#
#  To sa opcje dla kompilacji
#


#CXXFLAGS=-g -Iinc -Wall $WNO -pedantic -std=c++0x
CPPTYPE=g++
WNOFLAGS= -Wno-unused-variable
CPPFLAGS= -c -g -Iinc -Wall ${WNOFLAGS} -pedantic -std=c++11


__start__: obroty_2D
	./obroty_2D

obroty_2D: obj obj/main.o obj/Prostokat.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/lacze_do_gnuplota.o
	${CPPTYPE} -Wall -pedantic -std=c++0x -o obroty_2D obj/main.o obj/Wektor2D.o\
                        obj/Macierz2x2.o obj/Prostokat.o obj/lacze_do_gnuplota.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	${CPPTYPE} ${CPPFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostokat.hh inc/Macierz2x2.hh inc/Wektor2D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Prostokat.o: src/Prostokat.cpp inc/Prostokat.hh  #inc/Macierz2x2.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Prostokat.o src/Prostokat.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh  #inc/Wektor2D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp

clean:
	rm -f obj/*.o obroty_2D
