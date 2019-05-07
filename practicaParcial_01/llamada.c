#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "asociado.h"
#include "llamada.h"

/** \brief
 *
 * \param arrayLlamada Llamada*
 * \param cantidad int
 * \return int
 *
 */
int lla_init(Llamada *arrayLlamada, int cantidad)
{
    int retorno =-1;
    int i;

    for(i = 0; i < cantidad; i++)
    {
        strncpy(arrayLlamada[i].estado,"1",10);
        retorno = 0;
    }
    return retorno;
}

int lla_findFree(Llamada *arrayLlamada, int cantidad, int *devuelve)
{
    int retorno =-1;
    int i;
    for(i = 0; i<cantidad;i++)
    {
        if(strcmp(arrayLlamada[i].estado, "1") == 0)
        {
            *devuelve = i;
            retorno = 0;
            break;
        }
        retorno = 1;

    }
    return retorno;
}

int lla_addLla(Llamada *arrayLlamada, int cantidad, int posicionLibre, int id)
{
    int retorno = -1;
    if(getInt("Ingrese el id del asociado: ","Error, vuelva a ingresar\n\n",2,20,2,&arrayLlamada[posicionLibre].idAsociado) == 0 &&
       getString(&arrayLlamada[posicionLibre].motivo, "Ingrese el motivo: \n 1-ACV\n2-INFARTO\n3-GRIPE\n", "Error, vuelva a ingresar\n\n",3,7,2) == 0)
    {
        arrayLlamada[posicionLibre].idAsociado = id;
        strncpy(arrayLlamada[posicionLibre].estado,"PENDIENTE",10);
        retorno = 0;
    }
    else
    {
        retorno = 1;
    }
    return retorno;
}

