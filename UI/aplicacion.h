#ifndef __APLICACION_H__
#define __APLICACION_H__

#include <ctype.h> // Incluida para utilizar isdigit(). 
#include <stdio.h>
#include <stdlib.h> // Incluida para utilizar system().
#include <unistd.h> // Incluida para utilizar sleep().
#include <stdio_ext.h> // Incluida para utilizar __fpurge():
#include "arbolAVL.h"

struct NodoLista *lista; // Utilizada para checar el árbol en BFS.

void IniciarAplicacion();
void MostrarMenuPrincipal(char *);
void SeleccionarOpcion(char *);
int ValidarOpcionMenuPrincipal(char *);
void IrHaciaOpcion(char *);
void AgregarContacto();
void BuscarContacto();
void EliminarContacto();
void ModificarContacto(char *);
void MostrarContactos();
void EstablecerNombre(struct Contacto *);
void EstablecerNumeroCasa(struct Contacto *);
void EstablecerNumeroCelular(struct Contacto *);
void EstablecerCorreo(struct Contacto *);
int ValidarOpcionReiniciarSistema(char *);
int VolverAlMenuPrincipal(char *);
void ConvertirAMayus(char *);
void ImprimirContacto(struct Nodo *);
void RealizarModifcacion(char *, struct Nodo *);
int ValidarOpcionModificarContacto(char *);
void ModificarTelefonoCasa(struct Nodo *);
void ModificarTelefonoCelular(struct Nodo *);
void ModificarCorreo(struct Nodo *);
void BFS(struct Nodo *);
#endif 