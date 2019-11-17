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
    char isbn[25];
    int existencia;
};

struct Prestamo
{
    int id;
    int id_usuario;
    char isbn[25];
    char fecha_prestamo[10];
    char fecha_entrega[10];
};


#endif