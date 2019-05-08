#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{
	char Titulo[51];
    int isEmpty;//Activo = 0, Vacio = 1
    int idLibro;//Autoincremental
}Libros;

int lib_init(Libros *arrayLibros, int cantidad);
int lib_findFree(Libros *arrayLibros, int cantidad, int *devuelve);
int lib_addLib(Libros *arrayLibros, int cantidad, int posicionLibre, int id);
int lib_findArrayForId(Libros *arrayLibros, int cantidad,int *libroEncontrado, char *textoAMostrar);
int lib_removeLib(Libros *arrayLibros,int cantidad);
int lib_alterLib(Libros *arrayLibros, int cantidad);
void lib_showArray(Libros *arrayLibros, int cantidad);




#endif // LIBROS_H_INCLUDED
