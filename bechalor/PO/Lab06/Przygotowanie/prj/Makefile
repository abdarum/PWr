#
#  To sa opcje dla kompilacji
#


#CXXFLAGS=-g -Iinc -Wall $WNO -pedantic -std=c++0x
CPPTYPE=g++
WNOFLAGS= -Wno-unused-variable
CPPFLAGS= -c -g -Iinc -Wall ${WNOFLAGS} -pedantic -std=c++11


__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Robot.o obj/Macierz2x2.o obj/Wektor2D.o\
           obj/lacze_do_gnuplota.o obj/Sciezka.o obj/Scena.o\
	   obj/Objekt_Graficzny.o obj/Prostokat.o
	${CPPTYPE} -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o\
	 obj/Wektor2D.o obj/Sciezka.o obj/Macierz2x2.o obj/Robot.o\
	 obj/lacze_do_gnuplota.o obj/Scena.o obj/Objekt_Graficzny.o\
	 obj/Prostokat.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	${CPPTYPE} ${CPPFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Robot.hh inc/Macierz2x2.hh inc/Wektor2D.hh inc/Sciezka.hh inc/Scena.hh inc/Objekt_Graficzny.hh inc/Prostokat.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh  #inc/Macierz2x2.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Robot.o src/Robot.cpp

obj/Macierz2x2.o: src/Macierz2x2.cpp inc/Macierz2x2.hh  #inc/Wektor2D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Macierz2x2.o src/Macierz2x2.cpp

obj/Wektor2D.o: src/Wektor2D.cpp inc/Wektor2D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Wektor2D.o src/Wektor2D.cpp

obj/Sciezka.o: src/Sciezka.cpp inc/Sciezka.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Sciezka.o src/Sciezka.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Objekt_Graficzny.o: src/Objekt_Graficzny.cpp inc/Objekt_Graficzny.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Objekt_Graficzny.o src/Objekt_Graficzny.cpp

obj/Prostokat.o: src/Prostokat.cpp inc/Prostokat.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Prostokat.o src/Prostokat.cpp



clean:
	rm -f obj/*.o obroty_3D
