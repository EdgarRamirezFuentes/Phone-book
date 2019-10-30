#ifndef __UI_H__
#define __UI_H__

#include <gtk/gtk.h>

extern GObject *ventanaPrincipal ;
extern GObject *ventanaUsuarios ;
extern GObject *ventanaLibros ;
extern GObject *ventanaPrestamos ;
extern GObject *ventanaAgregarUsuario;
extern GObject *ventanaBuscarUsuario;
extern GObject *ventanaEliminarUsuario;
extern GObject *ventanaModificarUsuario;



int iniciarAplicacion(int argc, char *argv[]);
void abrirVentanaUsuarios(GtkWidget *, gpointer);
void abrirVentanaLibros(GtkWidget *, gpointer);
void abrirVentanaPrestamos(GtkWidget *, gpointer);
void abrirVentanaPrincipalDesdeUsuarios(GtkWidget *, gpointer);
void abrirVentanaPrincipalDesdeLibros(GtkWidget *, gpointer);
void abrirVentanaPrincipalDesdePrestamos(GtkWidget *, gpointer);
void abrirVentanaAgregarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeAgregarUsuario(GtkWidget *, gpointer);
void abrirVentanaBuscarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeBuscarUsuario(GtkWidget *, gpointer);
void abrirVentanaEliminarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeEliminarUsuario(GtkWidget *, gpointer);
void abrirVentanaModificarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeModificarUsuario(GtkWidget *, gpointer);
#endif
