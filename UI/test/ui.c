#include <gtk/gtk.h>

	GObject *window1 = NULL;
	GObject *window2 = NULL;

void abrirVentanaEmergente(GtkWidget *boton, gpointer data) {

   gtk_widget_hide( GTK_WIDGET(window1) );
   gtk_widget_show( GTK_WIDGET(window2) );
}

void abrirVentanaPrincipal(GtkWidget *boton, gpointer data) {
   gtk_widget_hide( GTK_WIDGET(window2) );
   gtk_widget_show( GTK_WIDGET(window1) );
}

int main(int argc, char **argv)
{
	GObject *button = NULL;
	GError *error = NULL;
	GtkBuilder *builder = NULL;

        gtk_init(&argc, &argv);


	/* Construct a GtkBuilder instance and load our UI description */
	builder = gtk_builder_new ();
	if (gtk_builder_add_from_file (builder, "prueba.ui", &error) == 0)
	{
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}

	/* Connect signal handlers to the constructed widgets. */
	window1 = gtk_builder_get_object (builder, "ventanaPrincipal");
	g_signal_connect (window1, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	window2 = gtk_builder_get_object (builder, "ventanaEmergente");

	button = gtk_builder_get_object (builder, "botonAbrir");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaEmergente), NULL);

	button = gtk_builder_get_object (builder, "botonRegresar");
	g_signal_connect (button, "clicked", G_CALLBACK (abrirVentanaPrincipal), NULL);

         
       gtk_widget_show(GTK_WIDGET(window1));

        gtk_main();

	return 0;
}
