#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

typedef struct
{
	char nombre[31];
    char apellido[31];
    int isEmpty;//Activo = 0, Vacio = 1
    char sexo;
    int telefono;
    char eMail;
    int fechaAsociado;//Autoincremental
    int idSocio; // Auto Incremental

}Socios;

int soc_init(Socios *arraySocios, int cantidad);
int soc_findFree(Socios *arraySocios, int cantidad, int *devuelve);
int soc_addSoc(Socios *arraySocios, int cantidad, int posicionLibre, int id);
int soc_findArrayForId(Socios *arraySocios, int cantidad,int *libroEncontrado, char *textoAMostrar);
int soc_removeSoc(Socios *arraySocios,int cantidad);
int soc_alterSoc(Socios *arraySocios, int cantidad);
void soc_showArray(Socios *arraySocios, int cantidad);


#endif // SOCIOS_H_INCLUDED
