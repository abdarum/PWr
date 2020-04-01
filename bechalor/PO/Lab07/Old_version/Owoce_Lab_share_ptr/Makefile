FILE=owoc_fab

__start__: ${FILE}
	./${FILE}

${FILE}: ${FILE}.cpp
	g++ -pedantic -Wall -std=c++11 -o ${FILE} ${FILE}.cpp

clean:
	rm ${FILE}
