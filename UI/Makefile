a.out: main.o ui.o arbolB.o
	gcc `pkg-config --cflags --libs gtk+-3.0` main.o ui.o arbolB.o
main.o: main.c
	gcc -c `pkg-config --cflags --libs gtk+-3.0` main.c
ui.o: ui.c
	gcc -c `pkg-config --cflags --libs gtk+-3.0` ui.c
arbolB.o: arbolB.c
	gcc -c arbolB.c
run: a.out
	./a.out
clear:
	rm a.out ui.o main.o arbolB.o
