#include "ui.h"
#include "arbolB.h"
int main(int argc, char *argv[]){
	iniciarAplicacion(argc, argv);
	printf("Tamaño del struct Usuario: %d \n", sizeof(struct Usuario));	
	printf("Tamaño del struct Libro: %d \n", sizeof(struct Libro));	
	printf("Tamaño del struct Prestamo: %d \n", sizeof(struct Prestamo));	
	printf("Tamaño del struct ArbolBUsuario %d \n", sizeof(struct ArbolBUsuario));
	printf("Tamaño del struct ArbolBLibro %d \n", sizeof(struct ArbolBLibro));
	printf("Tamaño del struct ArbolBPrestamo %d \n", sizeof(struct ArbolBPrestamo));
	return 0;
}
