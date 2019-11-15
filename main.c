#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct datos {
 int a[23];
 char b[235];
 char nombre[123];
 int x;
 float j;
};

int main(void) {
 FILE *fp = NULL;
 struct datos unPrestamo;

 fp = fopen("prestamos.dat","a+");

 strcpy(unPrestamo.nombre, "Estructuras de datos");

 fwrite(&unPrestamo, sizeof(struct datos), 1, fp);

 fclose(fp);
 
 
 return 0;
}
