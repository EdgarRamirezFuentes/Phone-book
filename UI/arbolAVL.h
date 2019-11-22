#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__

#include <string.h> // Incluida para el uso de strcmp().
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"
    
    struct Nodo{
        int factorDeBalance;
        struct Contacto *contacto;
        struct Nodo *izquierda;
        struct Nodo *derecha;
    };
    struct NodoPila {
	    struct Nodo contacto;
	    struct NodoPila *siguiente;
    };
    
    struct Contacto{
        char nombre[100];
        char numeroCasa[25];
        char numeroCelular[25];
        char correo[100];
    };

    struct Agenda{
        int cantidadContactos;
        struct Nodo *contactos;
    };

    struct Pila *pila;
    char operacionExitosa;

    struct Nodo* AgregarNuevoNodo(struct Nodo *, struct Contacto *, char *);
    void MostrarNodos(struct Nodo *);
    struct Nodo* BuscarNodo (struct Nodo *, char []);
    int CalcularFactorDeBalance(struct Nodo *);
    int CalcularAltura (struct Nodo *);
    struct Nodo* Rotar(struct Nodo *);
    struct Nodo* RotacionIzquierda(struct Nodo *);
    struct Nodo* RotacionDerecha(struct Nodo *);
    struct Nodo* RotacionDerechaIzquierda(struct Nodo *);
    struct Nodo* RotacionIzquierdaDerecha(struct Nodo *);
    //struct Nodo* EliminarNodo(struct Nodo*, char[]);

#endif