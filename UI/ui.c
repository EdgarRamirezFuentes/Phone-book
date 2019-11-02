#include "ui.h"
GObject *ventanaPrincipal = NULL;
GObject *ventanaUsuarios = NULL;
GObject *ventanaLibros = NULL;
GObject *ventanaPrestamos = NULL;
GObject *ventanaAgregarUsuario = NULL;
GObject *ventanaBuscarUsuario = NULL;
GObject *ventanaEliminarUsuario = NULL;
GObject *ventanaModificarUsuario = NULL;
GObject *ventanaAgregarLibro = NULL;
GObject *ventanaBuscarLibro = NULL;
GObject *ventanaEliminarLibro = NULL;
GObject *ventanaModificarLibro = NULL;
GObject *ventanaAgregarPrestamo = NULL;
GObject *ventanaBuscarPrestamo = NULL;
GObject *ventanaEliminarPrestamo = NULL;
GObject *ventanaModificarPrestamo = NULL;


int iniciarAplicacion(int argc, char *argv[])
{
	GtkBuilder *builder = NULL;
	GObject *button = NULL;
	GError *error = NULL;
	gtk_init(&argc, &argv);
	builder = gtk_builder_new ();
	if (gtk_builder_add_from_file (builder, "ventanaPrincipal.ui", &error) == 0)
	{
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}
	/* Asignamos las plantillas de las ventanas a su respectiva variable global*/

	ventanaPrincipal = gtk_builder_get_object (builder, "ventanaPrincipal");
	ventanaUsuarios = gtk_builder_get_object (builder, "ventanaUsuarios");
	ventanaPrestamos = gtk_builder_get_object (builder, "ventanaPrestamos");
	ventanaLibros = gtk_builder_get_object (builder, "ventanaLibros");
	ventanaAgregarUsuario = gtk_builder_get_object (builder, "ventanaAgregarUsuario");
	ventanaBuscarUsuario = gtk_builder_get_object (builder, "ventanaBuscarUsuario");
	ventanaEliminarUsuario = gtk_builder_get_object (builder, "ventanaEliminarUsuario");
	ventanaModificarUsuario = gtk_builder_get_object(builder, "ventanaModificarUsuario");
	ventanaAgregarLibro = gtk_builder_get_object(builder, "ventanaAgregarLibro");
	ventanaBuscarLibro = gtk_builder_get_object(builder, "ventanaBuscarLibro");
	ventanaEliminarLibro = gtk_builder_get_object(builder, "ventanaEliminarLibro");
	ventanaModificarLibro = gtk_builder_get_object(builder, "ventanaModificarLibro");
	ventanaAgregarPrestamo = gtk_builder_get_object(builder, "ventanaAgregarPrestamo");
	ventanaBuscarPrestamo = gtk_builder_get_object(builder, "ventanaBuscarPrestamo");
	ventanaEliminarPrestamo = gtk_builder_get_object(builder, "ventanaEliminarPrestamo");
	ventanaModificarPrestamo = gtk_builder_get_object(builder, "ventanaModificarPrestamo");
	
	/* Connect signal handlers to the constructed widgets. */
	
	/* Callbacks de ventanas principales */

	button = gtk_builder_get_object (builder, "btn-usuarios");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaUsuarios), NULL);

	button = gtk_builder_get_object (builder, "btn-libros");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaLibros), NULL);

	button = gtk_builder_get_object (builder, "btn-prestamos");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrestamos), NULL);

	button = gtk_builder_get_object (builder, "btn-salir");
	g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarUsuarios");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrincipalDesdeUsuarios), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarLibros");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrincipalDesdeLibros), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarPrestamos");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrincipalDesdePrestamos), NULL);
	
	/* Callbacks de ventanas de usuarios */

	button = gtk_builder_get_object (builder, "btn-agregarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaAgregarUsuario), NULL);	

	button = gtk_builder_get_object (builder, "btn-regresarAgregarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaUsuariosDesdeAgregarUsuario), NULL);

	button = gtk_builder_get_object (builder, "btn-buscarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaBuscarUsuario), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarBuscarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaUsuariosDesdeBuscarUsuario), NULL);

	button = gtk_builder_get_object (builder, "btn-eliminarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaEliminarUsuario), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarEliminarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaUsuariosDesdeEliminarUsuario), NULL);

	button = gtk_builder_get_object (builder, "btn-modificarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaModificarUsuario), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarModificarUsuario");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaUsuariosDesdeModificarUsuario), NULL);

	/* Callbacks de ventanas de libros */
	
	button = gtk_builder_get_object (builder, "btn-agregarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaAgregarLibro), NULL);
       		
	button = gtk_builder_get_object (builder, "btn-regresarAgregarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaLibrosDesdeAgregarLibro), NULL);
	
	button = gtk_builder_get_object (builder, "btn-buscarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaBuscarLibro), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarBuscarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaLibrosDesdeBuscarLibro), NULL);

	button = gtk_builder_get_object (builder, "btn-eliminarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaEliminarLibro), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarEliminarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaLibrosDesdeEliminarLibro), NULL);

	button = gtk_builder_get_object (builder, "btn-modificarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaModificarLibro), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarModificarLibro");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaLibrosDesdeModificarLibro), NULL);
	
	/* Callbacks de ventanas de prestamos */

	button = gtk_builder_get_object (builder, "btn-agregarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaAgregarPrestamo), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarAgregarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrestamosDesdeAgregarPrestamo), NULL);

	button = gtk_builder_get_object (builder, "btn-buscarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaBuscarPrestamo), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarBuscarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrestamosDesdeBuscarPrestamo), NULL);

	button = gtk_builder_get_object (builder, "btn-eliminarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaEliminarPrestamo), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarEliminarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrestamosDesdeEliminarPrestamo), NULL);

	button = gtk_builder_get_object (builder, "btn-modificarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaModificarPrestamo), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarModificarPrestamo");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrestamosDesdeModificarPrestamo), NULL);

	gtk_main();

	return 0;
}

/* Ventanas principales */

void abrirVentanaUsuarios(GtkWidget *boton, gpointer data) {
	gtk_widget_hide(GTK_WIDGET(ventanaPrincipal));
	gtk_widget_show(GTK_WIDGET(ventanaUsuarios));
}

void abrirVentanaLibros(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaPrincipal));
	gtk_widget_show(GTK_WIDGET(ventanaLibros));
}

void abrirVentanaPrestamos(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaPrincipal));
	gtk_widget_show(GTK_WIDGET(ventanaPrestamos));
}

void abrirVentanaPrincipalDesdeUsuarios(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaUsuarios));
	gtk_widget_show(GTK_WIDGET(ventanaPrincipal));

}

void abrirVentanaPrincipalDesdeLibros(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaLibros));
	gtk_widget_show(GTK_WIDGET(ventanaPrincipal));
}

void abrirVentanaPrincipalDesdePrestamos(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaPrestamos));
	gtk_widget_show(GTK_WIDGET(ventanaPrincipal));

}

/* Ventanas de usuarios */

void abrirVentanaAgregarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaUsuarios));
	gtk_widget_show(GTK_WIDGET(ventanaAgregarUsuario));
}

void abrirVentanaUsuariosDesdeAgregarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaAgregarUsuario));
	gtk_widget_show(GTK_WIDGET(ventanaUsuarios));
}

void abrirVentanaBuscarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaUsuarios));
	gtk_widget_show(GTK_WIDGET(ventanaBuscarUsuario));
}

void abrirVentanaUsuariosDesdeBuscarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaBuscarUsuario));
	gtk_widget_show(GTK_WIDGET(ventanaUsuarios));
}

void abrirVentanaEliminarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaUsuarios));
	gtk_widget_show(GTK_WIDGET(ventanaEliminarUsuario));
}

void abrirVentanaUsuariosDesdeEliminarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaEliminarUsuario));
	gtk_widget_show(GTK_WIDGET(ventanaUsuarios));
}

void abrirVentanaModificarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaUsuarios));
	gtk_widget_show(GTK_WIDGET(ventanaModificarUsuario));
}

void abrirVentanaUsuariosDesdeModificarUsuario(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaModificarUsuario));
	gtk_widget_show(GTK_WIDGET(ventanaUsuarios));
}

/* Ventanas de libros */

void abrirVentanaAgregarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaLibros));
	gtk_widget_show(GTK_WIDGET(ventanaAgregarLibro));
}

void abrirVentanaLibrosDesdeAgregarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaAgregarLibro));
	gtk_widget_show(GTK_WIDGET(ventanaLibros));
}

void abrirVentanaBuscarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaLibros));
	gtk_widget_show(GTK_WIDGET(ventanaBuscarLibro));
}

void abrirVentanaLibrosDesdeBuscarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaBuscarLibro));
	gtk_widget_show(GTK_WIDGET(ventanaLibros));
}

void abrirVentanaEliminarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaLibros));
	gtk_widget_show(GTK_WIDGET(ventanaEliminarLibro));
}

void abrirVentanaLibrosDesdeEliminarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaEliminarLibro));
	gtk_widget_show(GTK_WIDGET(ventanaLibros));
}

void abrirVentanaModificarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaLibros));
	gtk_widget_show(GTK_WIDGET(ventanaModificarLibro));
}

void abrirVentanaLibrosDesdeModificarLibro(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaModificarLibro));
	gtk_widget_show(GTK_WIDGET(ventanaLibros));
}

/* Ventanas de prestamos */

void abrirVentanaAgregarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaPrestamos));
	gtk_widget_show(GTK_WIDGET(ventanaAgregarPrestamo));
}

void abrirVentanaPrestamosDesdeAgregarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaAgregarPrestamo));
	gtk_widget_show(GTK_WIDGET(ventanaPrestamos));
}

void abrirVentanaBuscarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaPrestamos));
	gtk_widget_show(GTK_WIDGET(ventanaBuscarPrestamo));
}

void abrirVentanaPrestamosDesdeBuscarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaBuscarPrestamo));
	gtk_widget_show(GTK_WIDGET(ventanaPrestamos));
}

void abrirVentanaEliminarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaPrestamos));
	gtk_widget_show(GTK_WIDGET(ventanaEliminarPrestamo));
}

void abrirVentanaPrestamosDesdeEliminarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaEliminarPrestamo));
	gtk_widget_show(GTK_WIDGET(ventanaPrestamos));
}

void abrirVentanaModificarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaPrestamos));
	gtk_widget_show(GTK_WIDGET(ventanaModificarPrestamo));
}

void abrirVentanaPrestamosDesdeModificarPrestamo(GtkWidget *boton, gpointer data){
	gtk_widget_hide(GTK_WIDGET(ventanaModificarPrestamo));
	gtk_widget_show(GTK_WIDGET(ventanaPrestamos));
}







