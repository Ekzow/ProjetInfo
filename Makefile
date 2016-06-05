CC=gcc
CFLAGS=-c -g

all : Bellman

Bellman : LARC.o graphe.o Bellman.o
	$(CC) LARC.o graphe.o Bellman.o -o Bellman

LARC.o: LARC.c
	$(CC) $(CFLAGS) LARC.c

graphe.o: graphe.c
	$(CC) $(CFLAGS) graphe.c
	
Bellman.o : Bellman.c
	$(CC) $(CFLAGS) Bellman.c

clean :
	rm *o Bellman
