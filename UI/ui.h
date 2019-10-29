#ifndef __UI_H__
#define __UI_H__

#include <gtk/gtk.h>
GObject *ventanaPrincipal = NULL;
GObject *ventanaUsuarios = NULL;
GObject *ventanaLibros = NULL;
GObject *ventanaPrestamos = NULL;

int abrirVentanaPrincipal ();
void abrirVentanaUsuarios ( );
void abrirVentanaLibros ();
void abrirVentanaPrestamos ();

#endif
