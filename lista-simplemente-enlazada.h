#ifndef __LISTASIMPLEMENTEENLAZADA_H__
#define __LISTASIMPLEMENTEENLAZADA_H__

#include <stdio.h>
#include <stdlib.h>
#include "arbolAVL.h"

struct NodoLista {
	struct Nodo *contacto;
	struct NodoLista *siguiente;
};

struct NodoLista* AgregarNodoAlInicio(struct NodoLista *, struct Nodo *);
struct NodoLista* AgregarNodoAlFinal(struct NodoLista *, struct Nodo *);
struct NodoLista* EliminarNodoAlInicio(struct NodoLista *);

#endif
