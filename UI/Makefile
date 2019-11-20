a.out: main.o aplicacion.o arbolAVL.o
	gcc main.o aplicacion.o
main.o: main.c
	gcc -c main.c
arbolAVL.o: arbolAVL.c
	gcc -c arbolAVL.c
aplicacion.o: aplicacion.c
	gcc -c aplicacion.c
run: a.out
	./a.out
clear:
	rm a.out aplicacion.o main.o 
