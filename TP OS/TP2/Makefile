CC = gcc

all: Programme

Programme: listChaine.o main.o
	$(CC) main.o listChaine.o -o Programme

main.o: main.c
	$(CC) -c main.c

listChaine.o: listChaine.c
	$(CC) -c listChaine.c

clear:
	@rm *.o main

mrproper:
	@rm -rf listChaine
