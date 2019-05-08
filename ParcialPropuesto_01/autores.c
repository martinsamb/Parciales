#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "autores.h"
static int aut_generarId(void);

static int aut_generarId(void);
{
    static int idAutor=0;
    return idAutor++;
}


int aut_listAut(Autores autor, int cantidad)
{
	int i;
	for(i=0;i < CANTIDAD_AUTORES; i++)
	{
		if(arrayAutores[i].status != 0)
		{
			printf("\n%d - %s - %d - %.2f",arrayAutores[i].nombre,arrayAutores[i].apellido,arrayAutores[i].idAutores);
		}
	}
}

int aut_init(Autores *arrayAutores, int cantidad)
{
    int retorno = -1;
    int i;

    for(i = 0; i <cantidad; i++)
    {
        arrayAutores[i].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int aut_findFree(Autores *arrayAutores, int cantidad, int *devuelve)
{
    int retorno = -1;
    int i;
    for(i = 0; i<cantidad;i++)
    {
        *devuelve = i;
        retorno = 0;
        break;
    }
    return retorno;
}

int aut_addAut(Autores *arrayAutores, int cantidad, int posicionLibre, int id)
{
    int retorno = -1;
    if(getString(arrayAutores[posicionLibre].nombre,"Ingrese el nombre: ", "Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
       getString(arrayAutores[posicionLibre].apellido,"Ingrese el apellido: ","Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
       getInt("Ingrese el id Autor: ","Error, vuelva a ingresar\n\n",1,10,2,&arrayAutores[posicionLibre].idAutor) == 0)
    {
        arrayAutores[posicionLibre].idAutor = autores_generarId(void);
        arrayAutores[posicionLibre].isEmpty = 0;
        retorno = 0;
    }
    else
    {
        retorno = 1;
    }
    return retorno;
}

int aut_findArrayForId(Autores *arrayAutores, int cantidad, int *autorEncontrado, char *textoAMostrar)
{
    int i;
    int retorno = -1;
    Autores auxAutores;

    if(getInt(textoAMostrar,"Ingreso incorrecto\n",0,100,2,&auxAutores.idAutor) == 0)
    {
        for(i = 0; i<cantidad; i++)
        {
            if(arrayAutores[i].idAutor == auxAutores.idAutor)
            {
                retorno = 0;
                *autorEncontrado = i;
                break;
            }
        }
    }
    return retorno;
}


void aut_showArray(Autores *arrayAutores, int cantidad)
{
    int i;
    printf("\n\n\t\t\t || Lista de Autores ||\n\n");
    for(i = 0;i<cantidad; i++)
    {
        if(arrayAutores[i].isEmpty == 0)
        {
            printf("Id Autor: %d\n",arrayAutores[i].idAutor);
            printf("Posicion: %d\n",i);
            printf("Estado: %d\n",arrayAsociado[i].isEmpty);
            printf("Nombre: %d\n",arrayAsociado[i].nombre);
            printf("Apellido: %d\n",arrayAsociado[i].apellido);
            printf("Edad: %d\n",arrayAsociado[i].edad);
            printf("DNI: %d\n",arrayAsociado[i].dni);
        }
    }
}

int aso_removeAso(Asociado *arrayAsociado, int cantidad)
{
    int posicionAsociado;

    aso_showArray(arrayAsociado,cantidad);
    switch(aso_findArrayForId(arrayAsociado,cantidad,&posicionAsociado,"Ingrese el Id del asociado a dar de baja: "))
    {
    case 0:
        if(arrayAsociado[posicionAsociado].isEmpty == 0)
        {
            printf("Hubo coincidencia\n\n");
            arrayAsociado[posicionAsociado].isEmpty == 2;
            printf("El asociado borrado es: %d\n\n",arrayAsociado[posicionAsociado].idAsociado);
        }
        break;
    case 1:
        printf("No se encontro el Id y no entro al fin \n\n");
        break;
    default:
        printf("Ingreso al if pero no encontro el ID");
        break;
    }
    return 1;
}

int aso_alterAso(Asociado *arrayAsociado, int cantidad)
{
    int retorno = -1;
    int opcion;
    int posicionAsociado;
    char seguir = 's';

    aso_showArray(arrayAsociado,cantidad);
    switch(aso_findArrayForId(arrayAsociado,cantidad,&posicionAsociado,"Ingrese el Id de la pantalla a modificar: "))
    {
    case 0:
        if(arrayAsociado[posicionAsociado].isEmpty == 0)
        {
            printf("Hubo coincidencia'n\n");
            system("cls");
            //systen("clear");
            while(seguir = 's')
            {
                printf("Elija el dato que desea modificar\n\n");

                printf("\n\n1-Nombre");
                printf("\n\n2-Apellido");
                printf("\n\n3-Salir");
                printf("\n\t\tIngrese opcion: ","Ingreso incorrecto\n",1,6,2,&opcion);

                system("cls");

                switch(opcion)
                {
                case 1:
                    if(getString(arrayAsociado[posicionAsociado].nombre,"Ingrese el nuevo nombre de la pantalla: ","Error,vuelva a ingresar\n\n",2,20,2) == 0)
                    {
                        printf("El dato fue modificado con exito\n\n");
                    }
                    break;
                case 2:
                    if(getString(arrayAsociado[posicionAsociado].apellido,"Ingrese el nuevo apellido: ","Error, vuelva a ingresar\n\n",2,20,2) == 0)
                    {
                        printf("El dato fue modificado\n\n");
                    }
                    break;
                case 3:
                    seguir ='n';
                    retorno = 0;
                    break;
                }
            }
        }
        break;

    case 1:
        printf("No se encontro el Id del asociado");
        break;
    }
    return retorno;
}

int getString(char *pResult,char *pMsg, char *pMsgError, int minimo, int maximo, int intentos)
{
    int retorno = -1;
    char arrayAuxiliar[50];
    while(intentos > 0 )
    {
        printf("%s",pMsg);
        fflush(stdin);
        //__fpurge(stdin); // Limpia buffer Linux
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        if(pResult !=NULL && strlen(arrayAuxiliar) >= minimo && strlen(arrayAuxiliar) <=maximo && validLetter(arrayAuxiliar)== 0)
        {
            strncpy(pResult,arrayAuxiliar,maximo);
            retorno = 0;
            break;
        }
        else
        {
            printf("%s",pMsgError);
        }
        intentos--;
    }
    return retorno;
}

int validLetter(char letras[])
{
    int retorno = 0;
    int i = 0;
    int cantidadLetras;
    cantidadLetras = strlen(letras);
    while(i < cantidadLetras && retorno == 0)
    {
        if(isalpha(letras[i])!=0)
        {
            i++;
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

