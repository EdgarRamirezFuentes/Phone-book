#include "ui.h"

int abrirVentanaPrincipal ()
{
	if(ventanaLibros != NULL)
		gtk_widget_hide( GTK_WIDGET(ventanaLibros) );
	if(ventanaPrestamos != NULL)
		gtk_widget_hide( GTK_WIDGET(ventanaPrestamos) );
	if(ventanaUsuarios != NULL)
		gtk_widget_hide( GTK_WIDGET(ventanaUsuarios) );
	GtkBuilder *builder = NULL;
	GObject *button = NULL;
	GError *error = NULL;

	builder = gtk_builder_new ();
	if (gtk_builder_add_from_file (builder, "ventanaPrincipal.ui", &error) == 0)
	{
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}
	/* Asignamos las plantillas de las ventanas a su respectiva variable global*/

	ventanaPrincipal = gtk_builder_get_object (builder, "ventanaPrincipal");
	g_signal_connect (ventanaPrincipal, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	ventanaUsuarios = gtk_builder_get_object (builder, "ventanaUsuarios");
	ventanaPrestamos = gtk_builder_get_object (builder, "ventanaPrestamos");
	ventanaLibros = gtk_builder_get_object (builder, "ventanaLibros");

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
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrincipal), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarLibros");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrincipal), NULL);

	button = gtk_builder_get_object (builder, "btn-regresarPrestamos");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrincipal), NULL);


	gtk_widget_hide( GTK_WIDGET(ventanaLibros) );
	gtk_widget_hide( GTK_WIDGET(ventanaPrestamos) );
	gtk_widget_hide( GTK_WIDGET(ventanaUsuarios) );

	gtk_widget_show(GTK_WIDGET(ventanaPrincipal));

	return 0;
}

void abrirVentanaUsuarios(GtkWidget *boton, gpointer data) {
	gtk_widget_hide(GTK_WIDGET(ventanaPrincipal));
	gtk_widget_show(GTK_WIDGET(ventanaUsuarios));
}
void abrirVentanaLibros(GtkWidget *boton, gpointer data) {
	gtk_widget_hide(GTK_WIDGET(ventanaPrincipal));
	gtk_widget_show(GTK_WIDGET(ventanaLibros));
}
void abrirVentanaPrestamos(GtkWidget *boton, gpointer data) {
	gtk_widget_hide(GTK_WIDGET(ventanaPrincipal));
	gtk_widget_show(GTK_WIDGET(ventanaPrestamos));
}


