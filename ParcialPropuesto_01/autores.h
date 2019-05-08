#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
	char nombre[31];
    char apellido[31];
    int isEmpty;//Activo = 0, Vacio = 1
    int idAutor;//Autoincremental
}Autores;

int aut_init(Autores *arrayAutores, int cantidad);
int aut_findFree(Autores *arrayAutores, int cantidad, int *devuelve);
int aut_addAut(Autores *arrayAutores, int cantidad, int posicionLibre, int id);
int aut_findArrayForId(Autores *arrayAutores, int cantidad,int *autorEncontrado, char *textoAMostrar);
int aut_removeAut(Autores *arrayAutores,int cantidad);
int aut_alterAut(Autores *arrayAutores, int cantidad);
void aut_showArray(Autores *arrayAutores, int cantidad);
static int aut_generarId(void);


#endif // AUTORES_H_INCLUDED
