#include "pila.h"

void
push(struct Pila *pila, struct Nodo *contacto){
	pila -> contactos = AgregarNodoAlInicio(pila -> contactos, contacto);
	pila -> total = pila -> total + 1;
}

void pop(struct Pila *pila){
	pila -> contactos = EliminarNodoAlInicio(pila -> contactos);
	pila -> total = pila -> total - 1;
}

struct NodoLista* peek(struct Pila *pila){
	if(pila -> contactos == NULL){
		return NULL;
	}
	return pila -> contactos;
}

void MostrarDatosPila(struct Pila *pila){
	if(pila != NULL){
		struct Pila *tmp = NULL;
		tmp = pila;
		while(tmp -> contactos != NULL){
			puts(tmp ->contactos->contacto->contacto->nombre);
			tmp -> contactos = tmp -> contactos ->siguiente;
		}
	}
}
