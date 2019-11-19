#ifndef __ARBOLB_H__
#define __ARBOLB_H__

struct Usuario
{
	int id;
	char nombre[100];
	char ap_materno[100];
	char ap_paterno[100];
	char curp[18];
	int prestamos[3];
};

struct Libro
{
	char titulo[100];
	char autor[100];
	char editorial[100];
	int isbn;
	int existencia;
};

struct Prestamo
{
	int id;
	int id_usuario;
	int isbn;
	char fecha_prestamo[10];
	char fecha_entrega[10];
};

struct ArbolBUsuario
{
	int llaves[1000];
	unsigned int hijos [1001];
	int esHoja;
	int tamanio;
};

struct ArbolBLibro
{
	int llaves[1000];
	unsigned int hijos [1001];
	int esHoja;
	int tamanio;
};

struct ArbolBPrestamo
{
	int llaves[1000];
	unsigned int hijos [1001];
	int esHoja;
	int tamanio;
};

#endif
