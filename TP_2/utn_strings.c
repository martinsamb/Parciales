#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_valid.h"
#include "utn_strings.h"
#define ERROR_VAL "Direccion Invalida"

int getString(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno =  0;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            printf("%s", msg);
            fgets(buffer,sizeof(buffer)-1, stdin);
            if(strlen(buffer)-1<=maximo && strlen(buffer)-1>=minimo)
            {
                retorno = 1;
                strcpy(&buffer[strlen(buffer)-1],"\0");
                strncpy(resultado,buffer,maximo);
                break;
            }
            else
            {
                printf("%s",msgError);
                reintentos--;
            }

        }
        while(reintentos>=0);
    }
    return retorno;
}

int getInt(char* msg, char* msgError, int minimo, int maximo, int reintentos, int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    int bufferInt;
    if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos>=0&&resultado!=NULL)
    {
        if(getString(msg,msgError,1,12,reintentos,buffer))
        {
            if(validInt(buffer,minimo,maximo))
            {
                bufferInt = atoi(buffer);
                *resultado = bufferInt;
                retorno = 0;
            }
        }
        else
        {
            printf(msgError);
        }
    }
    return retorno;
}
int getName(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[maximo];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(getString(msg,msgError,minimo,maximo,reintentos,buffer))
            {
                if(validName(buffer))
                {
                    strncpy(resultado,buffer,maximo);
                    retorno  = 0;
                    break;
                }
                else
                {
                    printf("%s", msgError);
                }
            }
        }while(reintentos--);
    }
    return retorno;
}

int getEdad(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[maximo];
    if(msg != NULL && msgError != NULL && minimo<maximo && reintentos>=0 && resultado != NULL)
    {
        do
        {
            if(getString(msg,msgError,1,3,reintentos,buffer))
            {
                if(validEdad(buffer, minimo, maximo))
                {
                    printf("%s", buffer);
                    retorno  = 0;
                    break;
                }
                else
                {
                    printf("%s", msgError);
                    reintentos--;
                }
            }
            else
            {
                printf("%s", msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getDireccion(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && minimo<=maximo && reintentos >= 0)
    {
        do
        {
            if(getString(msg, msgError, minimo, maximo, reintentos, buffer))
            {
                if(validDireccion(buffer))
                {
                    retorno = 0;
                    strncpy(resultado,buffer,maximo);
                    break;
                }
                else
                {
                    printf("%s",ERROR_VAL);
                    reintentos--;
                }
            }
            else
            {
                printf("%s",msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int getCuil(char* msg, char* msgError,int reintentos, char* resultado)
{
    int retorno = 0;
    char buffer[4096];
    if(msg != NULL && msgError != NULL && reintentos >= 0)
    {
        do
        {
            if(getString(msg, msgError, 10, 11, reintentos, buffer))
            {
                if(validCuil(buffer))
                {
                    retorno = 0;
                    strncpy(resultado,buffer,11);
                    break;
                }
                else
                {
                    printf("%s",ERROR_VAL);
                    reintentos--;
                }
            }
            else
            {
                printf("%s",msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;

}

