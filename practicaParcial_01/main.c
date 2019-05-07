#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#include "asociado.h"
#include "llamada.h"
#define CANTIDAD_ASOCIADOS 10
#define CANTIDAD_LLAMADAS 100
#define MOTIVO_1 'ACV'
#define MOTIVO_2 'INFARTO'
#define MOTIVO_3 'GRIPE'


int main()
{
    int idGeneratorAsociado = 1;
    int idGeneratorLlamada = 1;
    char seguir = 's';
    int opcion;
    int valor1;
    int valor2;
    int posLibreAsociado;
    int posLibreLlamada;
    Asociado asociados[CANTIDAD_ASOCIADOS];
    Llamada llamadas[CANTIDAD_LLAMADAS];

    valor1 = aso_init(asociados, CANTIDAD_ASOCIADOS);
    valor2 = lla_init(llamadas, CANTIDAD_LLAMADAS);

    //-----------------INFORMES-------------------------
    strcpy(asociados[0].apellido,"Perez");
    strcpy(asociados[0].nombre,"Pablo");
    asociados[0].dni = 22456789;
    asociados[0].edad = 31;
    asociados[0].idAsociado = 1;

    strcpy(asociados[1].apellido,"Lopez");
    strcpy(asociados[1].nombre,"Lisandro");
    asociados[1].dni = 32456123;
    asociados[1].edad = 28;
    asociados[1].idAsociado = 2;

    strcpy(asociados[2].apellido,"Tevez");
    strcpy(asociados[2].nombre,"Carlos");
    asociados[2].dni = 28123456;
    asociados[2].edad = 32;
    asociados[2].idAsociado = 3;

    //---------------FIN DE INFORME --------------------

    if(valor1 == 0 && valor2 == 0)
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
        printf("\n\n1-Alta Asociado");
        printf("\n\n2-Baja Asociado");
        printf("\n\n3-Modificar Asociado");
        printf("\n\n4-Listar Asociado");
        printf("\n\n5-Nueva Llamada");
        printf("\n\n6-Salir");

        getInt("\n\t\tIngrese opcion: ","Ingreso incorrecto\n",1,10,2,&opcion);
        system("cls");

        switch(opcion)
        {
        case 1:
            if(aso_findFree(asociados,CANTIDAD_ASOCIADOS,&posLibreAsociado)!= 0)
            {
                printf("LLeno\n\n");
            }
            else
            {
                switch(aso_addAso(asociados,CANTIDAD_ASOCIADOS,posLibreAsociado,idGeneratorAsociado))
                {
                    case 0:
                        printf("Dato ingresado CORRECTAMENTE\n\n");
                        idGeneratorAsociado++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE");
                        break;
                }
            }
            break;
        case 2:
            if(aso_removeAso(asociados,CANTIDAD_ASOCIADOS) == 0)
            {
                printf("Exito");
            }
            break;
        case 3:
            if(aso_alterAso(asociados,CANTIDAD_ASOCIADOS)== 0)
            break;
        case 4:
            aso_showArray(asociados,CANTIDAD_ASOCIADOS);
            break;
        case 5:
            if(lla_findFree(llamadas,CANTIDAD_LLAMADAS,&posLibreLlamada)!= 0)
            {
                printf("Lleno\n");
            }
            else
            {
                switch(lla_addLla(llamadas,CANTIDAD_LLAMADAS,posLibreLlamada,idGeneratorLlamada))
                {
                    case 0:
                        printf("Dato ingresado CORRECTAMENTE\n\n");
                        idGeneratorLlamada++;
                        break;
                    case 1:
                        printf("Dato ingresado INCORRECTAMENTE\n\n");
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
