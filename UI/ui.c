#include "ui.h"
GObject *ventanaPrincipal = NULL;
GObject *ventanaUsuarios = NULL;
GObject *ventanaLibros = NULL;
GObject *ventanaPrestamos = NULL;
GObject *ventanaAgregarUsuario = NULL;
GObject *ventanaBuscarUsuario = NULL;
GObject *ventanaEliminarUsuario = NULL;
GObject *ventanaModificarUsuario = NULL;

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

	/* Connect signal handlers to the constructed widgets. */

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


	gtk_main();

	return 0;
}

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

