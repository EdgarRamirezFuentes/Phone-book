#include "arbolAVL.h"

/* ADDS A NEW NODE IN THE TREE */
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
    return raiz;
}

/* BALANCES THE TREE */

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
  if(banderaPila == 2)
  {
    if(CalcularFactorDeBalance(nodoDePartida) > 1 || CalcularFactorDeBalance(nodoDePartida) < -1)
    {
      agenda -> contactos = Rotar(nodoDePartida);
    }
  }
  ChecarBalanceo();
}

/* CHECKS IF THE TREE IS BALANCED */

void 
ChecarBalanceo()
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

/* CHECKS WHICH ROTATION IS NEEDED TO BALANCE THE TREE */

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
    return nodoActual;
}

/* MAKES A LEFT ROTATION IN THE SPECIFIED NODE */

struct Nodo* 
RotacionIzquierda(struct Nodo *nodoActual)
{
  struct Nodo *nuevaRaiz = NULL;
  nuevaRaiz = nodoActual -> derecha;
  nodoActual -> derecha = nuevaRaiz -> izquierda;
  nuevaRaiz -> izquierda = nodoActual;
  return nuevaRaiz;
}

/* MAKES A RIGHT ROTATION IN THE SPECIFIED NODE */

struct Nodo* 
RotacionDerecha(struct Nodo *nodoActual)
{
  struct Nodo *nuevaRaiz = NULL;
  nuevaRaiz = nodoActual -> izquierda;
  nodoActual -> izquierda = nuevaRaiz -> derecha;
  nuevaRaiz -> derecha = nodoActual;
  return nuevaRaiz;
}

/* MAKES A RIGHT - LEFT ROTATION IN THE SPECIFIED NODE */

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

/* MAKES A LEFT - RIGHT ROTATION IN THE SPECIFIED NODE */

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

/* SHOW EVERY NODE IN THE TREE USING INORDER TRAVERSAL */

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

/* LOOKS FOR A CERTAIN NODE */

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

/* CALCULATES THE BALANCE FACTOR OF THE GIVEN NODE */

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

/* CALCULATES THE HEIGHT OF THE GIVEN NODE */

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

/* CHECKS IF THE GIVEN NODE IS A LEAF */
int 
EsHoja(struct Nodo *nodoActual)
{
  if(nodoActual -> derecha == NULL && nodoActual -> izquierda == NULL)
  {
    return 1;
  }
  return 0;
}

/* CHECKS IF THE GIVEN NODE ONLY HAS LEFT SON */

int 
SoloHijoIzquierdo(struct Nodo *nodoActual)
{ 
  if(nodoActual -> izquierda != NULL && nodoActual -> derecha == NULL)
  {
    return 1;
  }
  return 0;
}

/* CHECKS IF THE GIVEN NODE ONLY HAS RIGHT SON */

int 
SoloHijoDerecho(struct Nodo *nodoActual)
{ 
  if(nodoActual -> izquierda == NULL && nodoActual -> derecha != NULL)
  {
    return 1;
  }
  return 0;
}

/* CHECKS IF THE GIVEN NODE ONLY HAS BOTH CHILDREN */

int 
TieneDosHijos(struct Nodo *nodoActual)
{ 
  if(nodoActual -> izquierda != NULL && nodoActual -> derecha != NULL)
  {
    return 1;
  }
  return 0;
}

/* CHECKS IF THE GIVEN NODE IS THE ROOT OF THE TREE */
int 
EsRaiz(struct Nodo *nodoActual)
{
  if(nodoActual == agenda -> contactos)
  {
    return 1;
  }
  return 0;
}

/* GETS THE NODE WHICH IS THE SMALLEST ONE OF THE BIGGEST NODES */

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
  return nodoActual;
}

/* OBTAINS THE PATH TO GET INTO A CERTAIN NODE */

int 
ObtenerRecorrido(struct Nodo *nodoActual, struct Nodo *nodoABuscar) // 0 es nulo - 1 hay por lo menos un dato en la pila - 2 es raiz.
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
  return 0;
}

/*  DELETES A NODE OF THE TREE
    THIS THING NEEDS TO BE REFACTORED ASAP
 */


struct Nodo* EliminarNodo(struct Nodo *raiz, struct Nodo *nodoAEliminar){
	if(nodoAEliminar != NULL){
		if(nodoAEliminar != raiz){
			struct Nodo *padre = BuscarPadre(raiz, nodoAEliminar);
			// No hay nodos más grandes que el nodo a eliminar.
			if(EsHoja(nodoAEliminar) == 1){
				if(strcmp( nodoAEliminar -> contacto -> nombre, padre -> contacto -> nombre) > 0){
					free(nodoAEliminar);
					padre -> derecha = NULL;
					return raiz;
				}
				free(nodoAEliminar);
				padre -> izquierda = NULL;
				return raiz;
			}
			if(SoloHijoIzquierdo(nodoAEliminar)){
				if(strcmp( nodoAEliminar -> contacto -> nombre, padre -> contacto -> nombre) > 0){
					padre -> derecha = nodoAEliminar -> izquierda; 
					free(nodoAEliminar);
					return raiz;
				}
				padre -> izquierda = nodoAEliminar -> izquierda;
				free(nodoAEliminar);
				return raiz;
			}

			// Casos cuando hay nodos más grandes que el nodo a eliminar.

			// El nodo a la derecha del nodo a eliminar es el más chico de los grandes.
			if(SoloHijoDerecho(nodoAEliminar -> derecha) == 1){
				nodoAEliminar -> derecha -> izquierda = nodoAEliminar -> izquierda;
				if(strcmp(nodoAEliminar -> contacto -> nombre, padre -> contacto -> nombre) > 0){
					padre -> derecha = nodoAEliminar -> derecha;
					free(nodoAEliminar);
					return raiz;
				}
				padre -> izquierda = nodoAEliminar -> derecha;
				free(nodoAEliminar);
				return raiz;
			}
			// El nodo a la derecha del nodo a eliminar no es el más chico.
			struct Nodo *nodoMasChico = MasPequenioDeLosGrandes(nodoAEliminar -> derecha);
			struct Nodo *padreNodoMasChico = BuscarPadre(raiz, nodoMasChico);
			padreNodoMasChico -> izquierda = nodoMasChico -> derecha;
			if(strcmp( nodoAEliminar -> contacto -> nombre, padre -> contacto -> nombre) > 0){
				padre -> derecha = nodoMasChico;
			}else{
				padre -> izquierda = nodoMasChico;	
			}
			nodoMasChico -> derecha = nodoAEliminar-> derecha;
			free(nodoAEliminar);
			return raiz;
		}
		// Si el nodo a eliminar es raiz
		if(EsHoja(nodoAEliminar) == 1){
			free(nodoAEliminar);
			return NULL;
		}	
		if(SoloHijoIzquierdo(nodoAEliminar) == 1){
			struct Nodo *nuevaRaiz = nodoAEliminar -> izquierda;
			free(nodoAEliminar);
			return nuevaRaiz;
		}
		if(SoloHijoDerecho(nodoAEliminar -> derecha) == 1){
			struct Nodo *nuevaRaiz = nodoAEliminar -> derecha;
			nuevaRaiz -> izquierda = nodoAEliminar -> izquierda;
			free(nodoAEliminar);
			return nuevaRaiz;
		}
    
    // El nodo de la derecha de la raiz es el más pequeño.
		struct Nodo *nodoMasChico = MasPequenioDeLosGrandes(nodoAEliminar -> derecha);
    if(nodoMasChico == nodoAEliminar -> derecha)
    {
      nodoMasChico -> izquierda = nodoAEliminar -> izquierda;
      free(nodoAEliminar);
      return nodoMasChico;
    }
    
		struct Nodo *padreNodoMasChico = BuscarPadre(raiz, nodoMasChico);
		padreNodoMasChico -> izquierda = nodoMasChico -> derecha;
		nodoMasChico -> izquierda = nodoAEliminar -> izquierda;
		nodoMasChico -> derecha = nodoAEliminar -> derecha;
		free(nodoAEliminar);
		return nodoMasChico;
	}
	return raiz;
}

/* REPLACES THE NODE THAT IS GOING TO BE REPLACED WITH THE NEW ONE */

void 
ReemplazarNodoEnEliminacion(struct Nodo *nodoAEliminar, struct Nodo *nodoAReemplazador)
{
  struct Nodo *padreNodoAEliminar = NULL;
  struct Nodo *padreHijoNodoAEliminar = NULL;
  padreNodoAEliminar = BuscarPadre(agenda -> contactos, nodoAEliminar);
  padreHijoNodoAEliminar = BuscarPadre(agenda -> contactos, nodoAReemplazador);
  if(padreNodoAEliminar != NULL){
      if(padreNodoAEliminar -> izquierda == nodoAEliminar)
      {
        padreNodoAEliminar -> izquierda = nodoAReemplazador;
        free(padreHijoNodoAEliminar);
      }else{
        padreNodoAEliminar -> derecha = nodoAReemplazador;
        free(padreHijoNodoAEliminar);
      }
  }
}

/* LOOKS FOR THE GIVEN NODE'S PARENT */

struct Nodo* 
BuscarPadre(struct Nodo *raiz, struct Nodo *nodoHijo)
{
  if(nodoHijo == raiz)
  {
    return NULL;
  }
	if(nodoHijo != raiz){
		if(raiz -> derecha  == nodoHijo || raiz -> izquierda == nodoHijo){
			return raiz;
		}	
		if(strcmp(nodoHijo -> contacto -> nombre , raiz -> contacto -> nombre) > 0){
			return BuscarPadre(raiz -> derecha, nodoHijo);
		}
		return BuscarPadre(raiz -> izquierda, nodoHijo);
	}
  return raiz;
}