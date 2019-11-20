#include "arbolAVL.h"

struct Nodo*
AgregarNuevoNodo (struct Nodo *raiz, struct Contacto *contacto)
{
    struct Nodo *nuevoContacto = NULL;
    if (raiz == NULL)
    {
      nuevoContacto = (struct Nodo *) malloc (sizeof (struct Nodo));
      if (nuevoContacto == NULL){
          operacionExistosa = 0;
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
    operacionExistosa = 1;
    return raiz;
}
