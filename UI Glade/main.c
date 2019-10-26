#include <gtk/gtk.h>

	static void
print_hello (GtkWidget *widget,gpointer   data)
{
	g_print ("Hello World\n");
}


	int
main (int   argc, char *argv[])
{
	GtkBuilder *builder = NULL;
	GObject *window = NULL;
	GObject *button = NULL;
	GError *error = NULL;

	gtk_init (&argc, &argv);

	/* Construct a GtkBuilder instance and load our UI description */
	builder = gtk_builder_new ();
	if (gtk_builder_add_from_file (builder, "ventanaPrincipal.ui", &error) == 0)
	{
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}

	/* Connect signal handlers to the constructed widgets. */
	window = gtk_builder_get_object (builder, "ventanaPrincipal");
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	button = gtk_builder_get_object (builder, "btn-salir");
	g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);

	gtk_main ();

	return 0;
}
