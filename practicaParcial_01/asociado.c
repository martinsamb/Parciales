#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "asociado.h"

int aso_init(Asociado *arrayAsociado, int cantidad)
{
    int retorno = -1;
    int i;

    for(i = 0; i <cantidad; i++)
    {
        arrayAsociado[i].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

int aso_findFree(Asociado *arrayAsociado, int cantidad, int *devuelve)
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

int aso_addAso(Asociado *arrayAsociado, int cantidad, int posicionLibre, int id)
{
    int retorno = -1;
    if(getString(arrayAsociado[posicionLibre].nombre,"Ingrese el nombre: ", "Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
       getString(arrayAsociado[posicionLibre].apellido,"Ingrese el apellido: ","Error, vuelva a ingresar\n\n",2,20,2) == 0 &&
       getInt("ingrese la edad: ","Error, vuelva a ingresar\n\n",18,99,2,&arrayAsociado[posicionLibre].edad) == 0 &&
       getInt("Ingrese el nro. de DNI: ","Error, vuelva a ingresar\n\n",1,999999,2,&arrayAsociado[posicionLibre].dni) == 0)
    {
        arrayAsociado[posicionLibre].idAsociado = id;
        arrayAsociado[posicionLibre].isEmpty = 0;
        retorno = 0;
    }
    else
    {
        retorno = 1;
    }
    return retorno;
}

int getInt(char *mensaje,char *mensajeError,long minimo, long maximo, int reintentos, int *resultado)
{
    int buffer; // Variable que no estan validadas = buffer
    int retorno = -1;
    int i;

    if(mensaje !=NULL && mensajeError !=NULL && resultado !=NULL && maximo >= minimo && reintentos >=0)
    {
        for(i = 0; i <= reintentos; i++)
        {
            printf("%s",mensaje);//imprimir mensaje
            fflush(stdin);
            scanf("%d",&buffer);
            if(isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
            }
        }
    }
    return retorno;
}

int isValidInt(int numero, int maximo, int minimo)//las funciones con is devuelve "TRUE" o "FALSE"
{
    if(numero >= minimo && numero<= maximo)
    {
        return 1;
    }
        return 0;
}

int aso_findArrayForId(Asociado *arrayAsociado, int cantidad, int *asociadoEncontrado, char *textoAMostrar)
{
    int i;
    int retorno = -1;
    Asociado auxAsociado;

    if(getInt(textoAMostrar,"Ingreso incorrecto\n",0,100,2,&auxAsociado.idAsociado) == 0)
    {
        for(i = 0; i<cantidad; i++)
        {
            if(arrayAsociado[i].idAsociado == auxAsociado.idAsociado)
            {
                retorno = 0;
                *asociadoEncontrado = i;
                break;
            }
        }
    }
    return retorno;
}

int getStringf(float *pResult,char *pMsg, char *pMsgError, int minimo, int maximo, int intentos)
{
    int retorno = -1;
    float arrayAuxiliar;
    while(intentos>0)
    {
        printf("%s",pMsg);
        fflush(stdin);
        //__fpurge(stdin); // Limpia buffer Linux
        scanf("%f",&arrayAuxiliar);//Limpia buffer Windows
        if(pResult !=NULL && arrayAuxiliar >= minimo && arrayAuxiliar <= maximo)
        {
            *pResult = arrayAuxiliar;
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

int getStringD(char *pResult,char *pMsg, char *pMsgError, int minimo, int maximo, int intentos)
{
    int retorno = -1;
    char arrayAuxiliar[50];
    while(intentos > 0)
    {
        printf("%s",pMsg);
        fflush(stdin);
        //__fpurge(stdin); // Limpia buffer Linux
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if(pResult !=NULL && strlen(arrayAuxiliar) >= minimo && strlen(arrayAuxiliar) <= maximo && !(isValidAlphaNum(arrayAuxiliar))== 0)
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

int isValidAlphaNum(char *sAlphaNum)
{
    int i;
    int retorno = 1;

    for(i = 0; *(sAlphaNum+i) !='\0';i++)
    {
        if((*(sAlphaNum+i) != '.')&&(*(sAlphaNum+i) != ' ')&&(*(sAlphaNum+i) < 'a' || *(sAlphaNum+i) > 'z')
        &&(*(sAlphaNum+i) < 'A' || *(sAlphaNum+i) > 'Z') && (*(sAlphaNum+i) < '0' || *(sAlphaNum+i) > '9'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;

    if(mensaje !=NULL && mensajeError !=NULL && resultado !=NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            //__fpurge(stdin); // Limpia buffer Linux
            scanf("%c",&buffer);
            if(isValidChar(buffer,maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }while(reintentos--);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra >= minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

void aso_showArray(Asociado *arrayAsociado, int cantidad)
{
    int i;
    printf("\n\n\t\t\t || Lista de Asociado ||\n\n");
    for(i = 0;i<cantidad; i++)
    {
        if(arrayAsociado[i].isEmpty == 0)
        {
            printf("Id Asociado: %d\n",arrayAsociado[i].idAsociado);
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
