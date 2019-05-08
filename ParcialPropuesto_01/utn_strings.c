#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "utn_strings.h"

int getById(Struct* pStruct, int len, int idS)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(pStruct[i].id==idS)
        {
            retorno=i;
            break;
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
