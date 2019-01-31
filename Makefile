#Makefile
Ohello:

	gcc -c board.c
	gcc -c main.c
	gcc -o ex board.o main.o
	ex.exe
