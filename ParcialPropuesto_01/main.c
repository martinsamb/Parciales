#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include <stdio_ext.h>
#include "autores.h"
#include "libros.h"
#include "prestamos.h"
#include "socios.h"

#define CANTIDAD_AUTORES 10
#define CANTIDAD_LIBROS 10
#define CANTIDAD_PRESTAMOS 10
#define CANTIDAD_SOCIOS


int main()
{
    int idGeneratorAutores = 1;
    int idGeneratorLibros = 1;
    int idGeneratorPrestamos = 1;
    int idGeneratorSocios = 1;
    char seguir = 's';
    int opcion;
    int valor1, valo2, valo3, valor4;
    int posLibreAutores;
    int posLibreLibros;
    int posLibrePrestamos;
    int posLibreSocios;
    Autores autor[CANTIDAD_AUTORES];
	Libros libro[CANTIDAD_LIBROS];
	Prestamos prestamo[CANTIDAD_PRESTAMOS];
	Socios socio[CANTIDAD_SOCIOS];

	valor1 = aut_init(autor, CANTIDAD_AUTORES);
    valor2 = lib_init(libro, CANTIDAD_LIBROS);
    valor3 = pre_init(prestamo, CANTIDAD_PRESTAMOS);
    valor4 = soc_init(socio, CANTIDAD_SOCIOS);

    //-----------------INFORME------------------------

    //----------------FIN DE INFORME -----------------

        if(valor1 == 0 && valor2 == 0 && valor3 == 0 && valo4 == 0)
    {
        printf("Sistema inicializado correctamente\n\n\n");
    }
    else
    {
        printf("Error al inicializar");
    }

    while(seguir == 's')
    {
        printf("\t\tMENU");
        printf("\n\n1-Alta Autores");
        printf("\n\n2-Modificar Autores");
        printf("\n\n3-Baja Autores");
        printf("\n\n4-Listar Autores");
        printf("\n\n5-Alta Libros");
        printf("\n\n6-Modificar Libros");
        printf("\n\n7-Baja Libros");
        printf("\n\n8-Listar Libros");
        printf("\n\n9-Alta Socios");
        printf("\n\n10-Modificar Socios");
        printf("\n\n11-Baja Socios");
        printf("\n\n12-Listar Socios");
        printf("\n\n13-Prestamos");
		printf("\n\n14-Salir");

        getInt("\n\t\tIngrese opcion: ","Ingreso incorrecto\n",1,10,2,&opcion);
        system("cls");

        switch(opcion)
        {
        case 1:
            if(aut_findFree(autor,CANTIDAD_AUTORES,&posLibreAutores)!= 0)
            {
                printf("LLeno\n\n");
            }
            else
            {
                switch(aut_addAut(autor,CANTIDAD_AUTORES,posLibreAutores,idGeneratorAutores))
                {
                    case 0:
                        printf("Dato ingresado CORRECTAMENTE\n\n");
                        idGeneratorAutores++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE");
                        break;
                }
            }
            break;

        case 2:
            if(aut_alterAut(autor,CANTIDAD_AUTORES)== 0)
            break;

		case 3:
            if(aut_removeAut(autor,CANTIDAD_AUTORES) == 0)
            {
                printf("Exito");
            }
            break;
        case 4:
            int aut_listAut(autor, CANTIDAD_AUTORES);
            break;
		case 5:
            if(lib_findFree(libro,CANTIDAD_LIBROS,&posLibreLibros)!= 0)
            {
                printf("LLeno\n\n");
            }
            else
            {
                switch(lib_addLib(autor,CANTIDAD_AUTORESS,posLibreAutores,idGeneratorAutores))
                {
                    case 0:
                        printf("Dato ingresado CORRECTAMENTE\n\n");
                        idGeneratorAutores++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE");
                        break;
                }
            }
            break;

        case 6:
            seguir = 'f';
            break;
        }
    }



    return 0;
}
