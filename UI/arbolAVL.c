#include "arbolAVL.h"

struct Nodo*
AgregarNuevoNodo (struct Nodo *raiz, struct Contacto *contacto)
{
    struct Nodo *nuevoContacto = NULL;
    if (raiz == NULL)
    {
      nuevoContacto = (struct Nodo *) malloc (sizeof (struct Nodo));
      if(nuevoContacto == NULL){
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
      raiz -> izquierda = AgregarNuevoNodo (raiz -> izquierda, contacto);
    }
    else
    {
      raiz -> derecha = AgregarNuevoNodo (raiz -> derecha, contacto);
    }
}

void BalancearArbol(struct Nodo *nodoDePartida)
{
  //NododePartida es el último nodo agregado o el nuevo nodo que reemplaza después de una eliminación.
  int banderaPila = 0;
  if(nodoDePartida == NULL)
  {
    return;
  }
  pila -> total = 0;
  pila -> contactos = NULL; // Limpia la pila.
  banderaPila = ObtenerRecorrido(agenda -> contactos, nodoDePartida);
  if(banderaPila == 0)
  {
    return;
  }
  if(banderaPila == 2){
        return;
  }
  ChecarBalanceo();
}
void ChecarBalanceo()
{
  struct Nodo *nodoActual = NULL;
  struct Nodo *padreNodoActual = NULL;
  if(pila -> contactos == NULL)
  {
    return;
  }
  nodoActual = peek(pila) -> contacto;
  pop(pila);
  if(EsRaiz(nodoActual) == 1)
  {
    if(CalcularFactorDeBalance(nodoActual) > 1 || CalcularFactorDeBalance(nodoActual) < -1)
    {
      agenda -> contactos = Rotar(nodoActual);
    }
    return;
  }
  padreNodoActual = peek(pila) -> contacto;
  if(strcmp(nodoActual -> contacto -> nombre, padreNodoActual -> contacto -> nombre) > 0) // Si el nodo es mayor al de su padre.
  {
    if(CalcularFactorDeBalance(nodoActual) > 1 || CalcularFactorDeBalance(nodoActual) < -1)
    {
      padreNodoActual -> derecha = Rotar(nodoActual);
    }
    ChecarBalanceo();
  }
  if(strcmp(nodoActual -> contacto -> nombre, padreNodoActual -> contacto -> nombre) < 0) // Si el nodo es mayor al de su padre.
  {
    if(CalcularFactorDeBalance(nodoActual) > 1 || CalcularFactorDeBalance(nodoActual) < -1)
    {
      padreNodoActual -> izquierda = Rotar(nodoActual);
    }
    padreNodoActual -> izquierda = nodoActual;
    ChecarBalanceo();
  }
}

struct Nodo*
Rotar(struct Nodo *nodoActual)
{
    //Rotación a la izquierda.
    if(nodoActual -> factorDeBalance > 1){
      if(CalcularFactorDeBalance(nodoActual -> derecha) == 1)
        return RotacionIzquierda(nodoActual);
    }
    //Rotación a la derecha.
    if(nodoActual -> factorDeBalance < -1){
      if(CalcularFactorDeBalance(nodoActual -> izquierda) == -1)
        return RotacionDerecha(nodoActual);
    }
    //Rotación a la derecha-izquierda
    if(nodoActual -> factorDeBalance > 1){
      if(CalcularFactorDeBalance(nodoActual -> derecha) == -1)
        return RotacionDerechaIzquierda(nodoActual);
    }
    //Rotación a la izquierda-derecha
    if(nodoActual -> factorDeBalance < -1){
      if(CalcularFactorDeBalance(nodoActual -> izquierda) == 1)
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
  raiz -> factorDeBalance = alturaDerecha - alturaIzquierda;
  return raiz -> factorDeBalance;
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

int EsHoja(struct Nodo *nodoActual)
{
  if(nodoActual -> derecha == NULL && nodoActual -> izquierda == NULL)
  {
    return 1;
  }
  return 0;
}
int SoloHijoIzquierdo(struct Nodo *nodoActual)
{ 
  if(nodoActual -> izquierda != NULL && nodoActual -> derecha == NULL)
  {
    return 1;
  }
  return 0;
}

int SoloHijoDerecho(struct Nodo *nodoActual)
{ 
  if(nodoActual -> izquierda == NULL && nodoActual -> derecha != NULL)
  {
    return 1;
  }
  return 0;
}

int TieneDosHijos(struct Nodo *nodoActual)
{ 
  if(nodoActual -> izquierda != NULL && nodoActual -> derecha != NULL)
  {
    return 1;
  }
  return 0;
}
int EsRaiz(struct Nodo *nodoActual)
{
  if(nodoActual == agenda -> contactos)
  {
    return 1;
  }
  return 0;
}

struct Nodo* 
MasPequenioDeLosGrandes(struct Nodo *nodoActual){
  if(nodoActual == NULL)
  {
    return NULL;
  }
  if(nodoActual -> izquierda != NULL)
  {
    return MasPequenioDeLosGrandes(nodoActual -> izquierda);
  }
  if(nodoActual -> izquierda == NULL)
  {
    return nodoActual;
  }
}

int ObtenerRecorrido(struct Nodo *nodoActual, struct Nodo *nodoABuscar) // 0 es nulo - 1 hay por lo menos un dato en la pila - 2 es raiz.
//NodoActual es la raiz de la agenda al inicio de la función.
{
  if(nodoABuscar == NULL){
    return 0;
  }
  if(EsRaiz(nodoABuscar) == 1){
    return 2;
  }
  if(strcmp(nodoABuscar -> contacto -> nombre, nodoActual -> contacto -> nombre) > 0)
  {
    push(pila, nodoActual);
    ObtenerRecorrido(nodoActual -> derecha, nodoABuscar);
    return 1;
  }
  if(strcmp(nodoABuscar -> contacto -> nombre, nodoActual -> contacto -> nombre) < 0)
  {
    push(pila, nodoActual);
    ObtenerRecorrido(nodoActual -> izquierda, nodoABuscar);
    return 1;
  }
  if(nodoActual == nodoABuscar)
  {
    push(pila, nodoActual);
    return 1;
  }

}

struct Nodo*
EliminarNodo(struct Nodo *nodoActual){
  struct Nodo *masPequenioDeLosGrandes = NULL;
  if(nodoActual == NULL)
  {
    return NULL;
  }
  if(TieneDosHijos(nodoActual) == 1)
  {
    masPequenioDeLosGrandes = MasPequenioDeLosGrandes(nodoActual -> derecha);
  }
}