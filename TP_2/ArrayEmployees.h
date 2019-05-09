#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

int initEmployee(Employee* arrayEmployees, int len);
int findFreeEmp(Employee* arrayEmployees, int len, int* posF);
int addEmployee(Employee* arrayEmployees,int len,char name,char lastName,float salary, int sector, int id);
int findEmployeeById(Employee* arrayEmployees, int len, int id);
int removeEmployee(Employee* arrayEmployees, int len, int id);
int sortEmployee(Employee* arrayEmployees, int len, int order);
int orderHighLessLastNameSector(Employee* arrayEmployees,int len);
int orderLessHighLastNameSector(Employee* arrayEmployees,int len);
void printEmployee(Employee arrayEmployees);
int printEmployees(Employee* arrayEmployees, int len);
int sumAverageSalary(Employee* arrayEmployees, int len, float* promedio);
int alterEmployee(Employee* arrayEmployees, int len, int id);



#endif // ARRAYEMPLOYEES_H_INCLUDED
