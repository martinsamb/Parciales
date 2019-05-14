#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"
#include "autor.h"
#include "libros.h"
#include "prestamos.h"
#include "socio.h"


#define QTY_ARRAY_TIPO 10
#define QTY_ARRAY_AUTOR 10
#define QTY_ARRAY_SOCIO 10
#define QTY_ARRAY_LIBROS 10
#define QTY_ARRAY_PRESTAMOS 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int primerOpcion;

    int contadorIdautor=0;
    Autor arrayAutor[QTY_ARRAY_TIPO];
    autor_Inicializar(arrayAutor,QTY_ARRAY_TIPO);

    int contadorIdsocios=0;
    Socios arraySocios[QTY_ARRAY_SOCIO];
    socios_Inicializar(arraySocios,QTY_ARRAY_SOCIO);

    int contadorIdlibro=0;
    Libro arrayLibro[QTY_ARRAY_LIBROS];
    libro_Inicializar(arrayLibro,QTY_ARRAY_LIBROS);

    int contadorIdprestamo=0;
    Prestamo arrayPrestamo[QTY_ARRAY_PRESTAMOS];
    prestamo_Inicializar(arrayPrestamo,QTY_ARRAY_PRESTAMOS);

    //*******************************************************************
    /*
    arrayAutor[0].idUnico=0;
    arrayAutor[0].isEmpty=0;
    arrayAutor[0].varInt=0;
    arrayAutor[0].varFloat=0;
    strcpy(arrayAutor[0].varLongString,"CCCCC");
    strcpy(arrayAutor[0].varString,"CCCCC");
    contadorIdfantasma++;

    arrayAutor[1].idUnico=1;
    arrayAutor[1].isEmpty=0;
    arrayAutor[1].varInt=0;
    arrayAutor[1].varFloat=0;
    strcpy(arrayAutor[1].varLongString,"AAAAA");
    strcpy(arrayAutor[1].varString,"AAAAA");
    contadorIdfantasma++;

    arrayAutor[2].idUnico=0;
    arrayAutor[2].isEmpty=0;
    arrayAutor[2].varInt=0;
    arrayAutor[2].varFloat=20;
    strcpy(arrayAutor[2].varLongString,"BBBBB");
    strcpy(arrayAutor[2].varString,"BBBBBB");
    contadorIdfantasma++;

    arrayAutor[3].idUnico=0;
    arrayAutor[3].isEmpty=0;
    arrayAutor[3].varInt=0;
    arrayAutor[3].varFloat=10;
    strcpy(arrayAutor[3].varLongString,"BBBBB");
    strcpy(arrayAutor[3].varString,"BBBBBB");
    contadorIdfantasma++;
    */

    //********************************************************************

    do
    {
        utn_getUnsignedInt("\n\n1) Menu Autor \n2) Menu Socio \n3) Menu Prestamo \n4) Menu Libros \n5) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&primerOpcion);
        switch(primerOpcion)
        {
            case 1: //Alta
                do
                {
                    utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                                  "\nError",1,sizeof(int),1,11,1,&opcion);
                    switch(opcion)
                    {
                        case 1: //Alta
                            autor_alta(arrayAutor,QTY_ARRAY_AUTOR,&contadorIdautor);                   //cambiar
                            break;

                        case 2: //Modificar
                            autor_modificar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
                            break;

                        case 3: //Baja
                            autor_baja(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
                            break;

                        case 4://Listar
                            autor_listar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
                            break;

                        case 5://Ordenar
                            autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_AUTOR,SORT_UP,SORT_DOWN);                   //cambiar
                            break;

                        case 6://Salir
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }
                while(opcion!=6);
                break;

            case 2: //Modificar
                do
                {
                    utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                                  "\nError",1,sizeof(int),1,11,1,&opcion);
                    switch(opcion)
                    {
                        case 1: //Alta
                            socios_alta(arraySocios,QTY_ARRAY_SOCIO,&contadorIdsocios);                   //cambiar
                            break;

                        case 2: //Modificar
                            socios_modificar(arraySocios,QTY_ARRAY_SOCIO);                   //cambiar
                            break;

                        case 3: //Baja
                            socios_baja(arraySocios,QTY_ARRAY_SOCIO);                   //cambiar
                            break;

                        case 4://Listar
                            socios_listar(arraySocios,QTY_ARRAY_SOCIO);                   //cambiar
                            break;

                        case 5://Ordenar
                            socios_ordenarPorDobleCriterio(arraySocios,QTY_ARRAY_SOCIO,SORT_UP,SORT_DOWN);                   //cambiar
                            break;

                        case 6://Salir
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }
                while(opcion!=6);
                break;

            case 3: //Baja
                do
                {
                    utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                                  "\nError",1,sizeof(int),1,11,1,&opcion);
                    switch(opcion)
                    {
                        case 1: //Alta
                            prestamo_alta(arrayPrestamo,arraySocios,QTY_ARRAY_SOCIO,arrayLibro,QTY_ARRAY_LIBROS,QTY_ARRAY_PRESTAMOS,&contadorIdprestamo);                   //cambiar
                            break;

                        case 2: //Modificar
                            prestamo_modificar(arrayPrestamo,QTY_ARRAY_TIPO);                   //cambiar
                            break;

                        case 3: //Baja
                            prestamo_baja(arrayPrestamo,QTY_ARRAY_TIPO);                   //cambiar
                            break;

                        case 4://Listar
                            prestamo_listar(arrayPrestamo,QTY_ARRAY_TIPO);                   //cambiar
                            break;

                        case 5://Ordenar
                            prestamo_ordenarPorDobleCriterio(arrayPrestamo,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                            break;

                        case 6://Salir
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }
                while(opcion!=6);
                break;

            case 4://Listar
                do
                {
                    utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                                  "\nError",1,sizeof(int),1,11,1,&opcion);
                    switch(opcion)
                    {
                        case 1: //Alta
                            libro_alta(arrayLibro,QTY_ARRAY_TIPO,&contadorIdlibro);                   //cambiar
                            break;

                        case 2: //Modificar
                            libro_modificar(arrayLibro,QTY_ARRAY_TIPO);                   //cambiar
                            break;

                        case 3: //Baja
                            libro_baja(arrayLibro,QTY_ARRAY_TIPO);                   //cambiar
                            break;

                        case 4://Listar
                            libro_listar(arrayLibro,QTY_ARRAY_TIPO);                   //cambiar
                            break;

                        case 5://Ordenar
                            libro_ordenarPorDobleCriterio(arrayLibro,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                            break;

                        case 6://Salir
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }
                while(opcion!=6);
                break;

            case 5://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);


    return 0;
}
