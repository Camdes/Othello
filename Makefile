#Makefile
Ohello:

	gcc -c board.c
	gcc -c main.c
	gcc -c OthelloConfig.c
	gcc -c OthelloRule.c
	gcc -o ex board.o main.o OthelloConfig.o OthelloRule.o
	ex.exe
