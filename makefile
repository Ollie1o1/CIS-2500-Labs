poetryL2: poetry.o
	gcc poetry.o -o poetryL2

poetry.o: poetry.c
	gcc -Wall -std=c99 -c poetry.c

clean:
	rm -f *.o poetryL2