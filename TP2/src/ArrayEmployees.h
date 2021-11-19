/*
 * ArrayEmployees.h
 *
 *  Created on: 18 nov. 2021
 *      Author: 1
 */
#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int menuModificacion();
int informeSalario(Employee list[],int len);
int menuInforme();
int pedirSector(int* sector,char mensaje[],char mensajeError[]);
int pedirSalario(float* salary,char mensaje[],char mensajeError[]);
int buscarLibre(Employee list[], int tam);
int pedirName(char name[],char mensaje[],char mensajeError[], int len);
int sortEmployees(Employee* list, int len, int order);
int modificarEmployee(Employee list[],int len);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int buscarLLeno(Employee list[], int tam);
int printEmployees(Employee* list, int length);
void mostrarEmpleado(Employee unEmpleado);
int addEmployee(Employee list[], int len, int* pId, char name[],char lastName[],float salary,int sector);
int initEmployees(Employee list[], int len);
int menu();

#endif // ARRAYEMPLOYEES_H_INCLUDED


