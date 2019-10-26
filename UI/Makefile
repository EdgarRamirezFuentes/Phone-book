a.out: main.o ui.o
	gcc `pkg-config --cflags --libs gtk+-3.0` main.o ui.o
main.o: main.c
	gcc -c `pkg-config --cflags --libs gtk+-3.0` main.c
ui.o: ui.c
	gcc -c `pkg-config --cflags --libs gtk+-3.0` ui.c
run: a.out
	./a.out
clear:
	rm a.out ui.o main.o
