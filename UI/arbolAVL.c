#include "arbolAVL.h"

struct Nodo*
AgregarNuevoNodo (struct Nodo *raiz, struct Contacto *contacto, char *operacionExitosa)
{
    struct Nodo *nuevoContacto = NULL;
    if (raiz == NULL)
    {
      nuevoContacto = (struct Nodo *) malloc (sizeof (struct Nodo));
      if (nuevoContacto == NULL){
          *operacionExitosa = 'f';
          return NULL;
      }
      nuevoContacto -> contacto = contacto;
      nuevoContacto -> izquierda = NULL;
      nuevoContacto -> derecha = NULL;
      return nuevoContacto;
    }
    if (strcmp(contacto -> nombre, raiz -> contacto -> nombre) == 0)
    {
      return raiz;
    }
    if(strcmp(contacto -> nombre, raiz -> contacto -> nombre) < 0)
    {
      raiz -> izquierda = AgregarNuevoNodo (raiz -> izquierda, contacto, operacionExitosa);
    }
    else
    {
      raiz -> derecha = AgregarNuevoNodo (raiz -> derecha, contacto, operacionExitosa);
    }
    return raiz;
}

void
MostrarNodos (struct Nodo *raiz)
{
  if (raiz == NULL)
    {
      return;
    }

  MostrarNodos(raiz -> izquierda);
  puts("\n************************************************************************\n");
  printf("Nombre: \t%s\n", raiz -> contacto -> nombre);
  printf("Número de casa: \t%s\n", raiz -> contacto -> numeroCasa);
  printf("Número de celular: \t%s\n", raiz -> contacto -> numeroCelular);
  printf("Correo: \t%s\n", raiz -> contacto -> correo);
  puts("\n*************************************************************************\n");
  MostrarNodos(raiz -> derecha);
}

int
BuscarNodo (struct Nodo *raiz, char contacto[])
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (strcmp(raiz -> contacto -> nombre , contacto) == 0)
  {
    puts("\n************************************************************************\n");
    printf("Nombre: \t%s\n", raiz -> contacto -> nombre);
    printf("Número de casa: \t%s\n", raiz -> contacto -> numeroCasa);
    printf("Número de celular: \t%s\n", raiz -> contacto -> numeroCelular);
    printf("Correo: \t%s\n", raiz -> contacto -> correo);
    puts("\n*************************************************************************\n");
    return 1;
  }
  if (strcmp(contacto, raiz -> contacto -> nombre) < 0)
  {
    return BuscarNodo (raiz -> izquierda, contacto);
  }
  return BuscarNodo (raiz -> derecha, contacto);
}