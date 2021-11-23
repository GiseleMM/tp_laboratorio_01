#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int menuModificacion();

#endif // employee_H_INCLUDED

int employee_mayorId( LinkedList* pArrayListEmployee);
int employee_buscarPorId( LinkedList* pArrayListEmployee, int id);
int employee_alta(LinkedList* pArrayListEmployee);
int employee_mostrarUnEmpleado(Employee* p);
int employee_baja( LinkedList* pArrayListEmployee);

int employee_modificar( LinkedList* pArrayListEmployee);
int employee_mostrarEmpleados( LinkedList* pArrayListEmployee);
int menu();
int menuOrdenar();
int employee_ordenarPorHora(void* horaA, void* horaB);
int employee_ordenarPorSueldo(void* sueldoA, void* sueldoB);
int employee_ordenar(LinkedList* pArrayListEmployee);

