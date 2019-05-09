#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad
#include "autor.h"
#include "libros.h"
#include "socios.h"
#include "prestamos.h"

#define QTY_ARRAY_TIPO 10
#define QTY_ARRAY_AUTOR 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdfantasma=0;
                     //cambiar
    int contadorIdautor=0;
    Autor arrayAutor[QTY_ARRAY_TIPO];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
    autor_mock(arrayAutor, QTY_ARRAY_TIPO, &contadorIdautor) ;                     //cambiar fantasma

    int contadorIdlibro=0;
    Libro arrayLibro[QTY_ARRAY_TIPO];                   //cambiar
    libro_Inicializar(arrayLibro,QTY_ARRAY_TIPO);                   //cambiar
    libro_mock(arrayLibro, QTY_ARRAY_TIPO, &contadorIdlibro) ;                     //cambiar fantasma

    int contadorIdsocio=0;
    Socio arraySocio[QTY_ARRAY_TIPO];                   //cambiar
    socio_Inicializar(arraySocio,QTY_ARRAY_TIPO);                   //cambiar
    socio_mock(arraySocio, QTY_ARRAY_TIPO, &contadorIdsocio) ;                     //cambiar fantasma

    int contadorIdprestamo=0;
    Prestamo arrayPrestamo[QTY_ARRAY_TIPO];                   //cambiar
    prestamo_Inicializar(arrayPrestamo,QTY_ARRAY_TIPO);                   //cambiar
    prestamo_mock(arrayPrestamo, QTY_ARRAY_TIPO, &contadorIdprestamo) ;                     //cambiar fantasma



    do
    {
        utn_getUnsignedInt("\n\n1) Alta libro \n2) Modificar libro \n3) Baja libro \n4) Listar libro \n5) Ordenar libro \n\n 6) Alta autor \n7) Modificar autor \n8) Baja autor \n9) Listar autor \n10) Ordenar autor  \n\n11) Alta socio \n12) Modificar socio \n13) Baja socio \n14) Listar socio \n15) Ordenar socio \n\n 16) Alta prestamo \n17) Modificar prestamo \n18) Baja prestamo \n19) Listar prestamo \n20) Ordenar prestamo \n21) Salir\n",                   //cambiar
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
            case 6: //Alta
                autor_alta(arrayAutor,QTY_ARRAY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 7: //Modificar
                autor_modificar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                autor_baja(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 9://Listar
                autor_listar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 11: //Alta
                socio_alta(arraySocio,QTY_ARRAY_TIPO,&contadorIdsocio);                   //cambiar
                break;

            case 12: //Modificar
                socio_modificar(arraySocio,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 13: //Baja
                socio_baja(arraySocio,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 14://Listar
                socio_listar(arraySocio,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 15://Ordenar
                socio_ordenarPorDobleCriterio(arraySocio,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 16: //Alta
                prestamo_alta(arrayPrestamo,QTY_ARRAY_TIPO,&contadorIdprestamo);                   //cambiar
                break;

            case 17: //Modificar
                prestamo_modificar(arrayPrestamo,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 18: //Baja
                prestamo_baja(arrayPrestamo,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 19://Listar
                prestamo_listar(arrayPrestamo,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 20://Ordenar
                prestamo_ordenarPorDobleCriterio(arrayPrestamo,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 21://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
