a.out: main.o aplicacion.o arbolAVL.o lista-simplemente-enlazada.o pila.o
	gcc main.o aplicacion.o arbolAVL.o lista-simplemente-enlazada.o pila.o -Wall
main.o: main.c
	gcc -c main.c -Wall
lista-simplemente-enlazada.o: lista-simplemente-enlazada.c
	gcc -c lista-simplemente-enlazada.c -Wall
pila.o: pila.c
	gcc -c pila.c -Wall
arbolAVL.o: arbolAVL.c
	gcc -c arbolAVL.c -Wall
aplicacion.o: aplicacion.c
	gcc -c aplicacion.c -Wall
run: a.out
	./a.out
clear:
	rm a.out aplicacion.o main.o arbolAVL.o
