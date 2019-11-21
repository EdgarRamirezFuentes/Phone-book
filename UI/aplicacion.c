#include "aplicacion.h"

void 
IniciarAplicacion()
{
    char opcion;
    char operacionExitosa = 't';
    char *apuntadorOpcion = NULL;
    char *apuntadorOperacionExitosa = NULL; 
    agenda = (struct Agenda*)malloc(sizeof(struct Agenda));
    if(agenda == NULL){
        system("clear");
        puts("No hay memoria para crear una agenda.");
        exit(-1);
    }
    agenda -> cantidadContactos = 0;
    apuntadorOpcion = &opcion;
    apuntadorOperacionExitosa = &operacionExitosa;
    do
    {
        MostrarMenuPrincipal(apuntadorOpcion);
        IrHaciaOpcion(apuntadorOpcion, apuntadorOperacionExitosa);
    }while(ReiniciarSistema(apuntadorOpcion) == 1);
}

void 
MostrarMenuPrincipal(char *opcion)
{
    do
    {
         do
        { 
            system("clear");
            __fpurge(stdin);
            puts("Sistema de gestión de contactos telefónicos\n\n");
            puts("¿Qué operación desea realizar?\n1.- Agregar contacto.\n2.- Buscar contacto.\n3.- Eliminar contacto.\n4.- Modificar contacto.\n5.- Mostrar contactos\n6.- Salir");
            SeleccionarOpcion(opcion);
        }while(isdigit(*opcion) == 0);
    } while (ValidarOpcionMenuPrincipal(opcion) == 0);
}

void 
SeleccionarOpcion(char *opcion)
{
    __fpurge(stdin);
    puts("\nIngrese el número de la operación que desea realizar: ");
    scanf("%c", opcion);
}

int 
ValidarOpcionMenuPrincipal(char *opcion)
{
    switch (*opcion)
    {
        case '1':
            system("clear");
            return 1;
        break;
        case '2':
            system("clear");
            return 1;
        break;
        case '3':
            system("clear");
            return 1;
        break;
        case '4':
            system("clear");
            return 1;
        break;
        case '5':
            system("clear");
            return 1;
        break;
        case '6':
            system("clear");
            return 1;
        break;
        default:
        system("clear");
            return 0;
        break;
    }
    return 1;
}

void 
IrHaciaOpcion(char *opcion, char *operacionExitosa)
{
    switch (*opcion)
    {
        case '1':
            AgregarContacto(operacionExitosa);
        break;
        case '2':
            BuscarContacto();
        break;
        case '3':
            EliminarContacto(operacionExitosa);
        break;
        case '4':
            ModificarContacto(operacionExitosa);
        break;
        case '5':
            MostrarContactos();
        break;
        case '6':
            puts("Hasta luego");
            exit(1);
        break;
        default:
        system("clear");
            puts("Se detectó un error, se detendrá la ejecución del programa.");
            exit (-1);
        break;
    }
}

void 
AgregarContacto( char *operacionExitosa)
{
    system("clear");
    __fpurge(stdin);
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
        agenda -> contactos = AgregarNuevoNodo (agenda -> contactos, nuevoContacto, operacionExitosa);
        if(*operacionExitosa == 't'){
            agenda -> cantidadContactos++;
            system("clear");
            puts("Contacto agregado correctamente.");
        }else{
            puts("Se agotó la memoria, por lo tanto no se pueden agregar más contactos");
            *operacionExitosa = 't'; 
        }
    }
}

void 
EstablecerNombre(struct Contacto *nuevoContacto)
{
    __fpurge(stdin);
    fgets(nuevoContacto -> nombre, 100, stdin);
    char *cadena = NULL;
    cadena = nuevoContacto -> nombre;
    ConvertirAMayus(cadena);
}

void ConvertirAMayus(char *cadena){
    for (int i = 0; cadena [i] !='\0'; i++) 
    {
        if(cadena[i] >= 'a' && cadena[i] <= 'z') 
        {
            cadena[i] = cadena[i] -32;
        }
    }
}

void 
EstablecerNumeroCasa(struct Contacto *nuevoContacto)
{
    __fpurge(stdin);
    fgets(nuevoContacto -> numeroCasa, 100, stdin);
}

void 
EstablecerNumeroCelular(struct Contacto *nuevoContacto){
    __fpurge(stdin);
    fgets(nuevoContacto -> numeroCelular, 100, stdin);
}

void 
EstablecerCorreo(struct Contacto *nuevoContacto){
    __fpurge(stdin);
    fgets(nuevoContacto -> correo, 100, stdin);
    char *cadena = NULL;
    cadena = nuevoContacto -> correo;
    ConvertirAMayus(cadena);
}

void 
BuscarContacto()
{
    char nombre[100];
    puts("Ingresa el contacto a buscar: ");
    __fpurge(stdin);
    fgets(nombre,100, stdin);
    char *cadena = NULL;
    cadena = &nombre;
    ConvertirAMayus(cadena);
    if(BuscarNodo(agenda -> contactos, nombre) == 0){
        system("clear");
        puts("El contacto no está registrado en la agenda");
        return;
    }
}

void 
EliminarContacto(char *operacionExitosa)
{

}

void 
ModificarContacto(char *operacionExitosa)
{

}

void 
MostrarContactos()
{
    system("clear");
    puts("Mostrar contactos\n\n");
    if(agenda -> cantidadContactos == 0){
        puts("No existen contactos en la agenda.");
        return;
    }
    MostrarNodos(agenda -> contactos);
}

int ReiniciarSistema(char *opcion){
    do
    {   
        puts("¿Qué deseas hacer?\n1.- Regresar al menú principal.\n2.-Salir del programa.");
        SeleccionarOpcion(opcion);
    }while(ValidarOpcionReiniciarSistema(opcion) == 0);
    return 1;
}

int ValidarOpcionReiniciarSistema(char *opcion){
    switch(*opcion){
        case '1':
            system("clear");
            puts("Abriendo el menú principal");
        break;
        case '2':
            system("clear");
            puts("Hasta luego.");
            exit(1);
        break;
        default:
            system("clear");
            puts("Ingresa una opción válida.");
            sleep(2);
            return 0;
        break;
        return 1;
    }

}