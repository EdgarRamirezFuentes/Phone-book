#ifndef __APLICACION_H__
#define __APLICACION_H__

#include <ctype.h> // Incluida para utilizar isdigit(). 
#include <stdio.h>
#include <stdlib.h> // Incluida para utilizar system().
#include <unistd.h> // Incluida para utilizar sleep().
#include "arbolAVL.h"

struct Agenda *agenda;

void IniciarAplicacion();
void MostrarMenuPrincipal(char *);
void SeleccionarOpcion(char *);
int ValidarOpcion(char *);
void IrHaciaOpcion(char *, char *);
void AgregarContacto(char *);
void BuscarContacto(char *);
void EliminarContacto(char *);
void ModificarContacto(char *);
void MostrarContactos();
void EstablecerNombre(struct Contacto *);
void EstablecerNumeroCasa(struct Contacto *);
void EstablecerNumeroCelular(struct Contacto *);
void EstablecerCorreo(struct Contacto *);
#endif 