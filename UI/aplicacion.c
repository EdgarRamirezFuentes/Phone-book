#include "aplicacion.h"

void 
IniciarAplicacion()
{
    char opcion;
    char *apuntadorOpcion = NULL;
    agenda = (struct Agenda*)malloc(sizeof(struct Agenda));
    pila = (struct Pila*)malloc(sizeof(struct Pila));
    if(agenda == NULL){
        system("clear");
        puts("No hay memoria para crear una agenda.");
        exit(-1);
    }
    if(pila == NULL){
        system("clear");
        puts("No hay memoria para crear una pila.");
        exit(-1);
    }
    agenda -> cantidadContactos = 0;
    apuntadorOpcion = &opcion;
    do
    {
        MostrarMenuPrincipal(apuntadorOpcion);
        IrHaciaOpcion(apuntadorOpcion);
    }while(VolverAlMenuPrincipal(apuntadorOpcion) == 1);
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
            printf("Contactos registrados: %d.\n\n\n", agenda -> cantidadContactos);
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
            ModificarContacto(opcion);
        break;
        case '5':
            MostrarContactos();
        break;
        case '6':
            puts("Hasta luego");
            exit(EXIT_SUCCESS);
        break;
        default:
            system("clear");
            puts("Se detectó un error, se detendrá la ejecución del programa.");
            exit (EXIT_FAILURE);
        break;
    }
}

void 
AgregarContacto()
{
    system("clear");
    __fpurge(stdin);
    pila -> contactos = NULL;
    struct Nodo *busqueda = NULL;
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
        busqueda = BuscarNodo(agenda -> contactos, nuevoContacto -> nombre);
        if(busqueda != NULL){
            system("clear");
            puts("Este contacto ya está registrado en la agenda");
            ImprimirContacto(busqueda);
            return;
        }
        agenda -> contactos = AgregarNuevoNodo (agenda -> contactos, nuevoContacto);
        agenda -> cantidadContactos = agenda -> cantidadContactos + 1;
        system("clear");
        busqueda = BuscarNodo(agenda -> contactos, nuevoContacto -> nombre);
        if(busqueda)
        {
            BalancearArbol(busqueda);
        }
        puts("Contacto agregado correctamente.\n\n");
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
    puts("Ingresa el nombre del contacto a buscar: ");
    __fpurge(stdin);
    fgets(nombre,100, stdin);
    char *cadena = NULL;
    cadena = &nombre[0];
    ConvertirAMayus(cadena);
    struct Nodo *busqueda = NULL;
    busqueda =BuscarNodo(agenda -> contactos, nombre);
    if(busqueda == NULL){
        system("clear");
        puts("El contacto no está registrado en la agenda");
        return;
    }
    ImprimirContacto(busqueda);
}

void ImprimirContacto(struct Nodo *busqueda){
    puts("\n************************************************************************\n");
    printf("Nombre: \t%s\n", busqueda -> contacto -> nombre);
    printf("Número de casa: \t%s\n", busqueda -> contacto -> numeroCasa);
    printf("Número de celular: \t%s\n", busqueda -> contacto -> numeroCelular);
    printf("Correo electrónico: \t%s\n", busqueda -> contacto -> correo);
    puts("\n*************************************************************************\n");
}

void 
EliminarContacto()
{
    if(agenda -> contactos == NULL){
        system("clear");
        puts("No hay contactos registrados en la agenda");
        return;
    }
    struct Nodo *nodoAEliminar = NULL;
    struct Nodo *padreNodoAEliminar = NULL;
    char nombre[100];
    puts("Ingresa el nombre del contacto a eliminar: ");
    __fpurge(stdin);
    fgets(nombre,100, stdin);
    char *cadena = NULL;
    cadena = &nombre[0];
    ConvertirAMayus(cadena);
    nodoAEliminar = BuscarNodo(agenda -> contactos, cadena);
    if(nodoAEliminar == NULL){
        system("clear");
        puts("El contacto no está registrado en la agenda");
        return;
    }
    if(EsRaiz(nodoAEliminar) == 0)
    {
        padreNodoAEliminar = BuscarPadre(agenda -> contactos, nodoAEliminar);
    }
    agenda -> contactos = EliminarNodo(agenda -> contactos, nodoAEliminar);
    system("clear");
    if(agenda -> contactos != NULL && padreNodoAEliminar != NULL)
    {
        if(CalcularFactorDeBalance(padreNodoAEliminar -> izquierda) > 1 || CalcularFactorDeBalance(padreNodoAEliminar -> izquierda) < -1)
        {
            padreNodoAEliminar -> izquierda = Rotar(padreNodoAEliminar -> izquierda);
        }
        if(CalcularFactorDeBalance(padreNodoAEliminar -> derecha) > 1 || CalcularFactorDeBalance(padreNodoAEliminar -> derecha) < -1)
        {
            padreNodoAEliminar -> derecha = Rotar(padreNodoAEliminar -> derecha);
        }
        BalancearArbol(padreNodoAEliminar);
    }
    agenda -> cantidadContactos = agenda -> cantidadContactos - 1;
    puts("Contacto eliminado correctamente.");
}

void 
ModificarContacto(char *opcion)
{
    char nombre[100];
    puts("Ingresa el nombre del contacto a modificar: ");
    __fpurge(stdin);
    fgets(nombre,100, stdin);
    char *cadena = NULL;
    cadena = &nombre[0];
    ConvertirAMayus(cadena);
    struct Nodo *busqueda = NULL;
    busqueda = BuscarNodo(agenda -> contactos, nombre);
    if(busqueda == NULL)
    {
        system("clear");
        puts("El contacto no está registrado en la agenda");
        return;
    }
    do
    {
        system("clear");
        puts("Contacto encontrado:");
        ImprimirContacto(busqueda);
        puts("¿Qué dato deseas modificar?\n1.- Número de casa\n2.- Número de celular\n3.- Correo electrónico");
        SeleccionarOpcion(opcion);
    }while(ValidarOpcionModificarContacto(opcion) == 0);
    RealizarModifcacion(opcion, busqueda);
}

void ModificarTelefonoCasa(struct Nodo *busqueda){
    system("clear");
    __fpurge(stdin);
    printf("Número telefónico de casa actual: %s\n\n", busqueda -> contacto -> numeroCasa);
    puts("Ingresa el nuevonúmero telefónico de casa: ");
    fgets(busqueda -> contacto -> numeroCasa, 100, stdin);
    system("clear");
    puts("Número telefónico de casa actualizado correctamente.\n\n");
    ImprimirContacto(busqueda);
}

void ModificarTelefonoCelular(struct Nodo *busqueda){
    system("clear");
    __fpurge(stdin);
    printf("Número telefónico de celular actual: %s\n\n", busqueda -> contacto -> numeroCelular);
    puts("Ingresa el nuevo número telefónico de celular: ");
    fgets(busqueda -> contacto -> numeroCelular, 100, stdin);
    system("clear");
    puts("Número telefónico de celular actualizado correctamente.\n\n");
    ImprimirContacto(busqueda);
}

void ModificarCorreo(struct Nodo *busqueda){
    system("clear");
    __fpurge(stdin);
    printf("Correo electrónico actual: %s\n\n", busqueda -> contacto -> correo);
    puts("Ingresa el nuevo correo electrónico: ");
    fgets(busqueda -> contacto -> correo, 100, stdin);
    system("clear");
    puts("Correo electrónico actualizado correctamente.\n\n");
    ImprimirContacto(busqueda);
}

void RealizarModifcacion(char *opcion, struct Nodo *busqueda){
    switch (*opcion)
    {
        case '1':
            ModificarTelefonoCasa(busqueda);
        break;
        case '2':
            ModificarTelefonoCelular(busqueda);
        break;
        case '3':
            ModificarCorreo(busqueda);
        break;
        default:
            system("clear");
            puts("Se detectó un error, se detendrá la ejecución del programa.");
            exit (-1);
        break;
    }
}

int 
ValidarOpcionModificarContacto(char *opcion)
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
        default:
            system("clear");
            puts("Ingrese una opción válida.");
            return 0;
        break;
    }
    return 1;
}

void 
MostrarContactos()
{
    system("clear");
    if(agenda -> cantidadContactos == 0){
        puts("No existen contactos en la agenda.");
        return;
    }
    MostrarNodos(agenda -> contactos);
    puts("Orden en BFS");
    BFS(agenda -> contactos);
}

void
BFS(struct Nodo *nodoActual){
	printf("%s", nodoActual -> contacto -> nombre);
	if(nodoActual -> izquierda != NULL){
		lista = AgregarNodoAlFinal(lista, nodoActual -> izquierda);
	}	
	if(nodoActual -> derecha != NULL){
		lista = AgregarNodoAlFinal(lista, nodoActual -> derecha);
	}
	if(lista == NULL){
		printf("\n");
		return;
	}
	struct Nodo *nuevaRaiz = lista -> contacto;
	lista = EliminarNodoAlInicio(lista);
	BFS(nuevaRaiz);
}


int VolverAlMenuPrincipal(char *opcion){
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
