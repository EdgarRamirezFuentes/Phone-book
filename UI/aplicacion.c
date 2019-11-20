#include "aplicacion.h"

void 
IniciarAplicacion()
{
    char opcion;
    char *apuntadorOpcion = NULL;
    agenda = (struct Agenda*)malloc(sizeof(struct Agenda));
    if(agenda == NULL){
        system("clear");
        puts("No hay memoria para crear una agenda.");
        exit(-1);
    }
    agenda -> cantidadContactos = 0;
    apuntadorOpcion = &opcion;
    MostrarMenuPrincipal(apuntadorOpcion);
    IrHaciaOpcion(apuntadorOpcion);
}

void 
MostrarMenuPrincipal(char *opcion)
{
    do
    {
         do
        { 
            system("clear");
            fflush(stdin);
            puts("Sistema de gestión de contactos telefónicos\n\n");
            puts("¿Qué operación desea realizar?\n1.- Agregar contacto.\n2.- Buscar contacto.\n3. Eliminar contacto.\n4. Modificar contacto.\n5.- Mostrar contactos");
            SeleccionarOpcion(opcion);
        }while(isdigit(*opcion) == 0);
    } while (ValidarOpcion(opcion) == 0);
}

void 
SeleccionarOpcion(char *opcion)
{
    puts("\nIngrese el número de la operación que desea realizar: ");
    scanf("%c", opcion);
}

int 
ValidarOpcion(char *opcion)
{
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

void 
IrHaciaOpcion(char *opcion)
{
    switch (*opcion)
    {
        case '1':
            AgregarContacto();
        break;
        case '2':
            BuscarContacto();
        break;
        case '3':
            EliminarContacto();
        break;
        case '4':
            ModificarContacto();
        break;
        case '5':
            MostrarContactos();
        break;
        default:
        system("clear");
            puts("Se detectó un error, se detendrá la ejecución del programa.");
            exit (-1);
        break;
    }
}

void 
AgregarContacto()
{
    system("clear");
    fflush(stdin);
    puts("Agregar contacto\n\n");
    struct Contacto *nuevoContacto = NULL;
    nuevoContacto = (struct Contacto*)malloc(sizeof(struct Contacto));
    if(nuevoContacto == NULL)
    {
        system("clear");
        puts("Se agotó la memoria, por lo tanto no se pueden agregar más contactos.");
        sleep(2);
    }else{
        puts("Ingresa el nombre del contacto:");
        EstablecerNombre(nuevoContacto);
        puts("Ingresa el número de casa: ");
        EstablecerNumeroCasa(nuevoContacto);
        puts("Ingresa el número de celular: ");
        EstablecerNumeroCelular(nuevoContacto);
        puts("Ingresa el correo: ");
        EstablecerCorreo(nuevoContacto);
        agenda -> contactos = AgregarNuevoNodo (agenda -> contactos, nuevoContacto);
        puts(agenda ->contactos->contacto->numeroCasa);
    }
}

void EstablecerNombre(struct Contacto *nuevoContacto){
    __fpurge(stdin);
    fgets(nuevoContacto -> nombre, 100, stdin);
}

void EstablecerNumeroCasa(struct Contacto *nuevoContacto){
    __fpurge(stdin);
    fgets(nuevoContacto -> numeroCasa, 100, stdin);
}

void EstablecerNumeroCelular(struct Contacto *nuevoContacto){
    __fpurge(stdin);
    fgets(nuevoContacto -> numeroCelular, 100, stdin);
}

void EstablecerCorreo(struct Contacto *nuevoContacto){
    __fpurge(stdin);
    fgets(nuevoContacto -> correo, 100, stdin);
}
void 
BuscarContacto()
{

}

void 
EliminarContacto()
{

}

void 
ModificarContacto()
{

}

void 
MostrarContactos()
{

}