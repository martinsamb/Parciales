#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"
#include "utn_valid.h"
#include "ArrayEmployees.h"
#define CANT_CARACTER 51
#define TRUE 1
#define FALSE 0

int initEmployee(Employee* arrayEmployees, int len)
{
    int i;
    int retorno = -1;
    if(arrayEmployees != NULL && len > 0)
    {
        for(i=0; i<=len; i++)
        {
            arrayEmployees[i].isEmpty = TRUE;
        }
        retorno = 0;
    }
    return retorno;
}

int findFreeEmp(Employee* arrayEmployees, int len, int* posF)
{
    int i;
    int retorno = -1;
    if(arrayEmployees != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(arrayEmployees[i].isEmpty == TRUE)
            {
                *posF = i;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int addEmployee(Employee* arrayEmployees,int len,char name,char lastName,float salary, int sector, int id)
{
    int retorno = -1;
    int posF = -1;
    if(arrayEmployees != NULL && len > 0 && name != NULL && lastName != NULL && salary>0 && sector != -1)
    {
        findFreeEmp(arrayEmployees, len, &posF);
        if(posF != -1)
        {
            strncpy(arrayEmployees[posF].name,name,51);
            strncpy(arrayEmployees[posF].lastName,lastName,51);
            arrayEmployees[posF].salary = salary;
            arrayEmployees[posF].sector = sector;
            arrayEmployees[posF].id = id;
            arrayEmployees[posF].isEmpty = 0;
            retorno =1;
        }
        else
        {
            printf("Array lleno");
        }
    }
    return retorno;
}

int findEmployeeById(Employee *arrayEmployees, int len, int id)
{
    int retorno = -1;
    int i;
    if(arrayEmployees != NULL && len>0 && id >=0)
    {
        for(i=0; i<=len; i++)
        {
            if(arrayEmployees[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int removeEmployee(Employee* arrayEmployees, int len, int id)
{
    int retorno = -1;
    int posId = -1;
    if(arrayEmployees != NULL && len>0 && id>=0)
    {
        posId = findEmployeeById(arrayEmployees, len, id);
        if(posId != -1)
        {
            arrayEmployees[posId].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

int sortEmployee(Employee* arrayEmployees, int len, int order)
{
    int retorno = -1;
    if((arrayEmployees != NULL && len > 0) && (order == 1 || order == 0))
    {
        if(order == 1)
        {
            orderHighLessLastNameSector(arrayEmployees,len);
        }
        else
        {
            orderLessHighLastNameSector(arrayEmployees, len);
        }
    }
    return retorno;
}

int orderHighLessLastNameSector(Employee* arrayEmployees,int len)
{
    int i;
    int j;
    Employee aux;
    int retorno = -1;
    if(arrayEmployees != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<=len; j++)
            {
                if(strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName)<0)
                {
                    aux = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = aux;
                }
                else if(strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName)==0)
                {
                    if(arrayEmployees[i].sector < arrayEmployees[j].sector)
                    {
                        aux = arrayEmployees[i];
                        arrayEmployees[i] = arrayEmployees[j];
                        arrayEmployees[j] = aux;
                    }
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}

int orderLessHighLastNameSector(Employee* arrayEmployees, int len)
{
    int i;
    int j;
    Employee aux;
    int retorno = -1;
    if(arrayEmployees != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            for(j=i+1; j<=len; j++)
            {
                if(strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName)>0)
                {
                    aux = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = aux;
                }
                else if(strcmp(arrayEmployees[i].lastName,arrayEmployees[j].lastName)==0)
                {
                    if(arrayEmployees[i].sector < arrayEmployees[j].sector)
                    {
                        aux = arrayEmployees[i];
                        arrayEmployees[i] = arrayEmployees[j];
                        arrayEmployees[j] = aux;
                    }
                }
                retorno = 0;
            }
        }
    }
    return retorno;
}
void printEmployee(Employee employee)
{
    printf("\nNombre: %s\nApellido: %s\nId: %d\nSector: %d\nSalario: %.2f\n",
           employee.name,employee.lastName,employee.id,employee.sector,employee.salary);
}

int printEmployees(Employee* arrayEmployees, int len)
{
    int retorno = -1;
    int i;
    if(arrayEmployees != NULL && len > 0)
    {
        for(i=0; i<=len; i++)
        {
            printEmployee(arrayEmployees[i]);
        }
        retorno = 0;
    }
    return retorno;
}

int sumAverageSalary(Employee* arrayEmployees, int len, float* promedio)
{
    int i;
    int retorno = -1;
    float salarioTotal=0;
    int cantEmpleados=0;

    if(arrayEmployees != NULL && len > 0)
    {
        for(i=0; i<=len; i++)
        {
            if(arrayEmployees[i].isEmpty == 0)
            {
                salarioTotal += arrayEmployees[i].salary;
                cantEmpleados++;
            }
        }
        *promedio = salarioTotal / cantEmpleados;
        retorno = 0;
    }
    return retorno;
}
int alterEmployee(Employee* arrayEmployees, int len, int id)
{
    int posE = -1;
    int retorno = -1;
    if(arrayEmployees != NULL && len > 0 && id >=0)
    {
        posE=findEmployeeById(arrayEmployees,len,id);
        if(posE != -1)
        {
            if(!getName("\nIngrese Nombre del Empleado: ","\nNombre Invalido",2,CANT_CARACTER,2,arrayEmployees[posE].name)&&
                    !getName("\nIngrese Apellido del Empleado: ","\nApellido Invalido",2,CANT_CARACTER,2,arrayEmployees[posE].lastName)&&
                    !getInt("\nIngrese el sector: ","\nSector Invalido", 1,6,2,&arrayEmployees[posE].sector))
            {
                //arrayEmpleado[idEcontrado].salario = salario;
                arrayEmployees[posE].id = id;
                arrayEmployees[posE].isEmpty = 0;
                printf("El Empleado se ha modificado correctamente! ");
                id++;
                retorno = 0;
            }
        }
        else
        {
            printf("Id no encontrado");
        }
    }
    return retorno;
}

