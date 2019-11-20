#include "aplicacion.h"

void iniciarAplicacion()
{
    char opcion;
    char *apuntadorOpcion = NULL;
    apuntadorOpcion = &opcion;
    mostrarMenuPrincipal(apuntadorOpcion);
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
            puts("¿Qué operación desea realizar?\n1.- Agregar contacto.\n2.- Buscar contacto.\n3. Eliminar contacto.\n4. Modificar contacto.\n5.- Mostrar Contactos");
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
            puts("Abriendo la sección Agregar usuario...");
            sleep(2);
        break;
        case '2':
            system("clear");
            puts("Abriendo la sección Buscar usuario...");
            sleep(2);
        break;
        case '3':
            system("clear");
            puts("Abriendo la sección Eliminar usuario...");
            sleep(2);
        break;
        case '4':
            system("clear");
            puts("Abriendo la sección Modificar usuario...");
            sleep(2);
        break;
        case '5':
            system("clear");
            puts("Abriendo la sección Mostrar usuarios...");
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
