
all: mainmc.c mincuad.o leerarch.o
	gcc  -O3 mainmc.c mincuad.o leerarch.o -o MinCuad -lm

debug: mainmc.o mincuad.o leerarch.o
	gcc  -g -D DEBUG mainmc.c mincuad.o leerarch.o -o MinCuad -lm

mainmc.o: mainmc.c
	gcc  -pedantic -Wall -Wextra -g mainmc.c -c 

mincuad.o: mincuad.c
	gcc  -pedantic -Wall -Wextra -g mincuad.c -c

leerarch.o: leerarch.c
	gcc  -pedantic -Wall -Wextra -g leerarch.c -c 

rm:
	rm *.o *.exe
