#include "ui.h"
#include "arbolB.h"
int main(int argc, char *argv[]){
	iniciarAplicacion(argc, argv);
	printf("Tamaño del struct Usuario: %d \n", sizeof(struct Usuario));	
	printf("Tamaño del struct Libro: %d \n", sizeof(struct Libro));	
	printf("Tamaño del struct Prestamo: %d \n", sizeof(struct Prestamo));	
	return 0;
}
