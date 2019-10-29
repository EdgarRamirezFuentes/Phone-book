#include <gtk/gtk.h>
int main(int argc, char *argv[]){
	gtk_init(&argc,&argv);
	abrirVentanaPrincipal();
	gtk_main();
	return 0;
}
