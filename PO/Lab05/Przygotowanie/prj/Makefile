#
#  To sa opcje dla kompilacji
#


#CXXFLAGS=-g -Iinc -Wall $WNO -pedantic -std=c++0x
CPPTYPE=g++
WNOFLAGS= -Wno-unused-variable
CPPFLAGS= -c -g -Iinc -Wall ${WNOFLAGS} -pedantic -std=c++11


__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Bryla.o obj/Macierz3x3.o obj/Wektor3D.o\
           obj/lacze_do_gnuplota.o
	${CPPTYPE} -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor3D.o\
                        obj/Macierz3x3.o obj/Bryla.o obj/lacze_do_gnuplota.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	${CPPTYPE} ${CPPFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Bryla.hh inc/Macierz3x3.hh inc/Wektor3D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Bryla.o: src/Bryla.cpp inc/Bryla.hh  #inc/Macierz3x3.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Bryla.o src/Bryla.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh  #inc/Wektor3D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	${CPPTYPE} ${CPPFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

clean:
	rm -f obj/*.o obroty_3D
