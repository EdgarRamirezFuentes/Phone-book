#ifndef __APLICACION_H__
#define __APLICACION_H__

#include <ctype.h> // Incluida para utilizar isdigit(). 
#include <stdio.h>
#include <stdlib.h> // Incluida para utilizar system().
#include <unistd.h> // Incluida para utilizar sleep().

void iniciarAplicacion();
void mostrarMenuPrincipal(char*);
void seleccionarOpcion(char*);
int validarOpcion(char*);
#endif 