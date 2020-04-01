#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: sprawdzenie_testu
	./sprawdzenie_testu

sprawdzenie_testu: obj/main.o obj/WyrazenieAlgeb.o obj/Statystyka.o
	g++ -Wall -pedantic -o sprawdzenie_testu obj/main.o\
                                  obj/WyrazenieAlgeb.o obj/Statystyka.o

obj/main.o: src/main.cpp inc/WyrazenieAlgeb.hh inc/Statystyka.hh inc/Symbol.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/WyrazenieAlgeb.o: src/WyrazenieAlgeb.cpp inc/WyrazenieAlgeb.hh inc/Symbol.hh
	g++ ${CPPFLAGS} -o obj/WyrazenieAlgeb.o src/WyrazenieAlgeb.cpp

obj/Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ ${CPPFLAGS} -o obj/Statystyka.o src/Statystyka.cpp

clean:
	rm -f obj/*.o sprawdzenie_testu