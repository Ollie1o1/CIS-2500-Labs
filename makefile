poetryL2: poetry.o
	gcc poetry.o -o poetry

poetry.o: poetry.c header.h 
	gcc -Wall -std=c99 -c poetry.c

clean:
	rm -f *.o poetry
