#include "aplicacion.h"

void iniciarAplicacion()
{
    char opcion;
    char *apuntadorOpcion = NULL;
    apuntadorOpcion = &opcion;
    mostrarMenuPrincipal(apuntadorOpcion);
    irHaciaOpcion(opcion);
}

void mostrarMenuPrincipal(char *opcion)
{
    do
    {
         do
        { 
            system("clear");
            fflush(stdin);
            puts("Sistema de gestión de contactos telefónicos\n\n");
            puts("¿Qué operación desea realizar?\n1.- Agregar contacto.\n2.- Buscar contacto.\n3. Eliminar contacto.\n4. Modificar contacto.\n5.- Mostrar contactos");
            seleccionarOpcion(opcion);
        }while(isdigit(*opcion) == 0);
    } while (validarOpcion(opcion) == 0);
}

void seleccionarOpcion(char *opcion)
{
    puts("\nIngrese el número de la operación que desea realizar: ");
    *opcion = getchar();
}

int validarOpcion(char *opcion){
    switch (*opcion)
    {
        case '1':
            system("clear");
            puts("Abriendo la sección Agregar contacto...");
            sleep(2);
        break;
        case '2':
            system("clear");
            puts("Abriendo la sección Buscar contacto...");
            sleep(2);
        break;
        case '3':
            system("clear");
            puts("Abriendo la sección Eliminar contacto...");
            sleep(2);
        break;
        case '4':
            system("clear");
            puts("Abriendo la sección Modificar contacto...");
            sleep(2);
        break;
        case '5':
            system("clear");
            puts("Abriendo la sección Mostrar contacto...");
            sleep(2);
        break;
        default:
        system("clear");
            puts("Ingresa una opción válida.");
            sleep(2);
            return 0;
        break;
    }
    return 1;
}

void irHaciaOpcion(char *opcion){
    switch (*opcion)
    {
        case '1':
            agregarContacto();
        break;
        case '2':
            buscarContacto();
        break;
        case '3':
            eliminarContacto();
        break;
        case '4':
            modificarContacto();
        break;
        case '5':
            mostrarContactos();
        break;
        default:
        system("clear");
            puts("Se detectó un error, se detendrá la ejecución del programa.");
            exit (-1);
        break;
    }
}

void agregarContacto(){

}

void buscarContacto(){

}

void eliminarContacto(){

}

void modificarContacto(){

}

void mostrarContactos(){

}