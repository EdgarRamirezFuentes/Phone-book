#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__

#include <string.h> // Incluida para el uso de strcmp().
#include <stdlib.h>
#include <stdio.h>

    struct Nodo{
        int factorDeBalance;
        struct Contacto *contacto;
        struct Nodo *izquierda;
        struct Nodo *derecha;
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

    struct Nodo* AgregarNuevoNodo(struct Nodo *, struct Contacto *, char *);
    void MostrarNodos(struct Nodo *);
    int BuscarNodo (struct Nodo *, char []);
    //struct Nodo* EliminarNodo(struct Nodo*, char[]);
    //int CalcularAltura (struct Nodo*);
    //int CalcularFactorDeBalance (struct Nodo*);

#endif