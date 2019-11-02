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
extern GObject *ventanaAgregarLibro;
extern GObject *ventanaBuscarLibro;
extern GObject *ventanaEliminarLibro;
extern GObject *ventanaModificarLibro;
extern GObject *ventanaAgregarPrestamo;
extern GObject *ventanaBuscarPrestamo;
extern GObject *ventanaEliminarPrestamo;
extern GObject *ventanaModificarPrestamo;


int iniciarAplicacion(int argc, char *argv[]);

/* Ventanas Principales */

void abrirVentanaUsuarios(GtkWidget *, gpointer);
void abrirVentanaPrincipalDesdeUsuarios(GtkWidget *, gpointer);

void abrirVentanaLibros(GtkWidget *, gpointer);
void abrirVentanaPrincipalDesdeLibros(GtkWidget *, gpointer);

void abrirVentanaPrestamos(GtkWidget *, gpointer);
void abrirVentanaPrincipalDesdePrestamos(GtkWidget *, gpointer);

/* Ventanas de usuarios */

void abrirVentanaAgregarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeAgregarUsuario(GtkWidget *, gpointer);

void abrirVentanaBuscarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeBuscarUsuario(GtkWidget *, gpointer);

void abrirVentanaEliminarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeEliminarUsuario(GtkWidget *, gpointer);

void abrirVentanaModificarUsuario(GtkWidget *, gpointer);
void abrirVentanaUsuariosDesdeModificarUsuario(GtkWidget *, gpointer);

/* Ventanas de libros */

void abrirVentanaAgregarLibro(GtkWidget *, gpointer);
void abrirVentanaLibrosDesdeAgregarLibro(GtkWidget *, gpointer);

void abrirVentanaBuscarLibro(GtkWidget *, gpointer);
void abrirVentanaLibrosDesdeBuscarLibro(GtkWidget *, gpointer);

void abrirVentanaModificarLibro(GtkWidget *, gpointer);
void abrirVentanaLibrosDesdeModificarLibro(GtkWidget *, gpointer);

void abrirVentanaEliminarLibro(GtkWidget *, gpointer);
void abrirVentanaLibrosDesdeEliminarLibro(GtkWidget *, gpointer);

/* Ventanas de préstamos */

void abrirVentanaAgregarPrestamo(GtkWidget *, gpointer);
void abrirVentanaPrestamosDesdeAgregarPrestamo(GtkWidget *, gpointer);

void abrirVentanaBuscarPrestamo(GtkWidget *, gpointer);
void abrirVentanaPrestamosDesdeBuscarPrestamo(GtkWidget *, gpointer);

void abrirVentanaEliminarPrestamo(GtkWidget *, gpointer);
void abrirVentanaPrestamosDesdeEliminarPrestamo(GtkWidget *, gpointer);

void abrirVentanaModificarPrestamo(GtkWidget *, gpointer);
void abrirVentanaPrestamosDesdeModificarPrestamo(GtkWidget *, gpointer);

#endif
