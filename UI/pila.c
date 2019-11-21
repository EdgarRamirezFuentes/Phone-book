#include "pila.h"

void
push(struct Pila *pila, struct Nodo *contacto){
	pila -> contactos = AgregarNodoAlInicio(pila -> contactos, contacto);
	if(operacionExitosa == 't'){
		pila -> total = pila -> total + 1;
	}
}

void pop(struct Pila *pila){
	if(pila -> contactos == NULL){
		operacionExitosa = 'f';
		return;
	}
	pila -> contactos = EliminarNodoAlInicio(pila -> contactos);
	if(operacionExitosa == 't'){
		pila -> total = pila -> total - 1;
	}
}

struct NodoPila* peek(struct Pila *pila){
	if(pila -> contactos == NULL){
		operacionExitosa = 'f';
		return;
	}
	return pila -> contactos;
}
