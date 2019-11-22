#ifndef __PILA_H__
#define __PILA_H__

#include <stdio.h>
#include <stdlib.h>
#include "arbolAVL.h"
#include "lista-simplemente-enlazada.h"

struct Pila {
    int total;
    struct NodoLista *contactos;
};

void push(struct Pila *pila, struct Nodo *);
void pop(struct Pila *pila);
struct NodoLista* peek(struct Pila *);
#endif
