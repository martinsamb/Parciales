#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

typedef struct
{
	int idPrestamo;//Autoincremental
	int idLibro;
	int idSocio;
	int fechaPrestamo; //
}Prestamos;

int pre_init(Prestamos *arrayPrestamos, int cantidad);
int pre_findFree(Prestamos *arrayPrestamos, int cantidad, int *devuelve);
int pre_addPre(Prestamos *arrayPrestamos, int cantidad, int posicionLibre, int id);
int pre_findArrayForId(Prestamos *arrayPrestamos, int cantidad,int *prestamoEncontrado, char *textoAMostrar);
int pre_removePre(Prestamos *arrayPrestamos,int cantidad);
int pre_alterPre(Prestamos *arrayPrestamos, int cantidad);
void pre_showArray(Prestamos *arrayPrestamos, int cantidad);


#endif // PRESTAMOS_H_INCLUDED
