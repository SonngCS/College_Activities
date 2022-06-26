main: main.o dataset.o arvores.o
	gcc -o main main.o dataset.o arvores.o
main.o: main.c dataset.h arvores.h
	gcc -c main.c
dataset.o: dataset.c dataset.h arvores.h
	gcc -c dataset.c
arvores.o: arvores.c arvores.h
	gcc -c arvores.c