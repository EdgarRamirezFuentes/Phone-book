#include "arbolAVL.h"

struct Nodo*
AgregarNuevoNodo (struct Nodo *raiz, struct Contacto *contacto, char *operacionExitosa)
{
    struct Nodo *nuevoContacto = NULL;
    if (raiz == NULL)
    {
      nuevoContacto = (struct Nodo *) malloc (sizeof (struct Nodo));
      if(nuevoContacto == NULL){
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
      push(pila, raiz);
      raiz -> izquierda = AgregarNuevoNodo (raiz -> izquierda, contacto, operacionExitosa);
    }
    else
    {
      push(pila, raiz);
      raiz -> derecha = AgregarNuevoNodo (raiz -> derecha, contacto, operacionExitosa);
    }

    do
    {
      struct Nodo *contactoActual = peek(pila) -> contacto;
      contactoActual -> factorDeBalance = CalcularFactorDeBalance(contactoActual);
      if(pila -> contactos != NULL){
          pop(pila);
      }
      if(contactoActual -> factorDeBalance > 1 || contactoActual -> factorDeBalance < -1){
        return Rotar(contactoActual, contacto);
      }
      return raiz;
    }while(pila -> contactos != NULL);
}

struct Nodo*
Rotar(struct Nodo *nodoActual, struct Contacto *contacto)
{
    //Rotación a la izquierda.
    if(strcmp(contacto -> nombre, nodoActual -> contacto -> nombre) > 0){
      if(strcmp(contacto -> nombre, nodoActual -> derecha -> contacto -> nombre) > 0)
        return RotacionIzquierda(nodoActual);
    }
    //Rotación a la derecha.
    if(strcmp(contacto -> nombre, nodoActual -> contacto -> nombre) < 0){
      if(strcmp(contacto -> nombre, nodoActual -> izquierda -> contacto -> nombre) < 0)
        return RotacionDerecha(nodoActual);
    }
    //Rotación a la derecha-izquierda
    if(strcmp(contacto -> nombre, nodoActual -> contacto -> nombre) > 0){
      if(strcmp(contacto -> nombre, nodoActual -> derecha ->contacto -> nombre) < 0)
        return RotacionDerechaIzquierda(nodoActual);
    }
    //Rotación a la izquierda-derecha
    if(strcmp(contacto -> nombre, nodoActual -> contacto -> nombre) > 0){
      if(strcmp(contacto -> nombre, nodoActual -> derecha ->contacto -> nombre) < 0)
        return RotacionIzquierdaDerecha(nodoActual);
    }
}
struct Nodo* 
RotacionIzquierda(struct Nodo *nodoActual)
{
  struct Nodo *nuevaRaiz = NULL;
  nuevaRaiz = nodoActual -> derecha;
  nodoActual -> derecha = nuevaRaiz -> izquierda;
  nuevaRaiz -> izquierda = nodoActual;
  return nuevaRaiz;
}

struct Nodo* 
RotacionDerecha(struct Nodo *nodoActual)
{
  struct Nodo *nuevaRaiz = NULL;
  nuevaRaiz = nodoActual -> izquierda;
  nodoActual -> izquierda = nuevaRaiz -> derecha;
  nuevaRaiz -> derecha = nodoActual;
  return nuevaRaiz;
}

struct Nodo* 
RotacionDerechaIzquierda(struct Nodo *nodoActual)
{
  struct Nodo *nuevaRaiz = NULL;
  struct Nodo *nodoSecundario = NULL;
  nuevaRaiz = nodoActual -> derecha -> izquierda;
  nodoSecundario = nodoActual -> derecha;
  nodoActual -> derecha = nuevaRaiz -> izquierda;
  nodoSecundario -> izquierda = nuevaRaiz -> derecha;
  nuevaRaiz -> izquierda = nodoActual;
  nuevaRaiz -> derecha = nodoSecundario;
  return nuevaRaiz;
}

struct Nodo* 
RotacionIzquierdaDerecha(struct Nodo *nodoActual)
{
  struct Nodo *nuevaRaiz = NULL;
  struct Nodo *nodoSecundario = NULL;
  nuevaRaiz = nodoActual -> izquierda -> derecha;
  nodoSecundario = nodoActual -> izquierda;
  nodoActual -> izquierda = nuevaRaiz -> derecha;
  nodoSecundario -> derecha = nuevaRaiz -> izquierda;
  nuevaRaiz -> derecha = nodoActual;
  nuevaRaiz -> izquierda = nodoSecundario;
  return nuevaRaiz;
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

struct Nodo *
BuscarNodo (struct Nodo *raiz, char contacto[])
{
  if (raiz == NULL)
  {
    return NULL;
  }
  if (strcmp(raiz -> contacto -> nombre , contacto) == 0)
  {
    return raiz;
  }
  if (strcmp(contacto, raiz -> contacto -> nombre) < 0)
  {
    return BuscarNodo (raiz -> izquierda, contacto);
  }
  return BuscarNodo (raiz -> derecha, contacto);
}

int
CalcularFactorDeBalance(struct Nodo *raiz)
{
  int alturaDerecha = 0;
  int alturaIzquierda = 0;

  if (raiz == NULL)
  {
    return 0;
  }
  alturaIzquierda = CalcularAltura (raiz -> izquierda);
  alturaDerecha = CalcularAltura (raiz -> derecha);
  return alturaIzquierda - alturaDerecha;
}

int
CalcularAltura (struct Nodo *raiz)
{
    int alturaDerecha = 0;
    int alturaIzquierda = 0;
    if (raiz == NULL)
    {   
      return -1;
    }

    alturaIzquierda = CalcularAltura (raiz -> izquierda);
    alturaDerecha = CalcularAltura (raiz -> derecha);
    if (alturaIzquierda > alturaDerecha)
    {
        return alturaIzquierda + 1;
    }
    return alturaDerecha + 1;
}