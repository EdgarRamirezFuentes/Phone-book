#include "lista-simplemente-enlazada.h"

struct NodoLista*
AgregarNodoAlInicio(struct NodoLista *nodo, struct Nodo* contacto){ // Complejidad O(1)
	struct NodoLista *nuevoNodo = (struct NodoLista*)malloc(sizeof(struct NodoLista));// O(1);
	if(nuevoNodo != NULL){
		nuevoNodo -> contacto = contacto; // O(1)
		if(nodo != NULL){
			nuevoNodo -> siguiente = nodo; // O(1);
		}
		operacionExitosa = 't';
		return nuevoNodo; // O(1)
	}
	operacionExitosa = 'f';
	return nodo; // O(1)
}

struct NodoLista*
AgregarNodoAlFinal(struct NodoLista* nodo, struct Nodo *contacto){ // Complejidad O(n)
	struct NodoLista* tmp = NULL; // O(1)
	struct NodoLista* nuevoNodo = (struct NodoLista*)malloc(sizeof(struct NodoLista)); // O(1)
	if(nuevoNodo != NULL){
		nuevoNodo -> contacto = contacto; // O(1)
		if(nodo == NULL){
			return nuevoNodo; // O(1)
		}
		tmp = nodo; // O(1)
		while(tmp -> siguiente != NULL){ // O(n)
			tmp = tmp -> siguiente; // O(1)
		}
		tmp -> siguiente = nuevoNodo; //O(1)
		return nodo; // O(1)
	}
	return nodo; // O(1)
}

struct NodoLista* 
EliminarNodoAlInicio(struct NodoLista *nodo){ // Complejidad O(1)
	struct NodoLista *tmp = NULL; // O(1)
	if(nodo != NULL){
		tmp = nodo; //O(1) 
		nodo = nodo -> siguiente; //O(1)
		free(tmp); // O(1)
		operacionExitosa = 't';
		return nodo; // O(1)
	}
	operacionExitosa = 'f';
	return nodo; // O(1)
}
