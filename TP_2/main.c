#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "utn_strings.h"
#include "utn_valid.h"
#define CANT_EMPLOYEE 1000
#define CANT_CARACTER 51


int main()
{
    char seguir='s';
    int opcion=0;
    char name[CANT_CARACTER];
    char lastName[CANT_CARACTER];
    float promedio;
    float salary;
    int sector;
    int id = 0;
    int idBorrar;
    int len;
    int valor1;

    Employee arrayEmployees[CANT_EMPLOYEE];

    valor1 = initEmployee(arrayEmployees, CANT_EMPLOYEE);
    if(valor1 == 0)
    {
        printf("El sistema inicializado correctamente\n\n");
    }
    else
    {
        printf("Error al inicializar");
    }

    while(seguir=='s')
    {
        printf("1- Alta empleado\n");
        printf("2- Modificar empleado\n");
        printf("3- Baja empleado\n");
        printf("4- Informar\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(!getName("\nIngrese Nombre del Empleado: ","\nNombre Invalido",2,CANT_CARACTER,2,name)&&
                    !getName("\nIngrese Apellido del Empleado: ","\nApellido Invalido",2,CANT_CARACTER,2,lastName)&&
                    !getInt("\nIngrese el sector: ","\nSector Invalido", 1,6,2,&sector)&&
                    addEmployee(arrayEmployees,len,name,lastName,80000,sector,id))

                {
                    printf("El Empleado se ha cargado correctamente! ");
                    id++;
                }
                else
                {
                    printf("\nNo se ha podido dar de alta al empleado.\nPor favor, revise la informacion antes de ingresarla.");
                }

                break;
            case 2:
                if(!getInt("Ingrese ID a Modificar","ID invalido",0,560,2,&idBorrar)&&
                    alterEmployee(arrayEmployees,len,id))
                {
                    printf("Empleado modificado exitosamente");
                }
                break;
            case 3:
                if(!getInt("Ingrese ID a borrar: ","ID invalido ",0,1000,2,&idBorrar))
                {
                    if(!removeEmployee(arrayEmployees,len,idBorrar))
                    {
                        printf("Id borrado Exitosamente");
                    }
                    else
                    {
                        printf("Id no encontrado");
                    }
                }
                break;
            case 4:
                getInt("\n1-Ordenar de mayor a menor.\n2-Promediar salario de empleados.\n","Opcion Invalida",1,2,3,&opcion);
                switch(opcion)
                {
                case 1:
                    sortEmployee(arrayEmployees,len,1);
                    printEmployees(arrayEmployees,len);
                    break;
                case 2:

                    sumAverageSalary(arrayEmployees,len,&promedio);
                    printf("%.2f",promedio);
                    break;
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
