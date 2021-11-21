#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int cant;//para feof
	int todoOk=0;
	char id[128];//TIene que ser todo char por que employee_newParametros recibe todo char
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
	Employee* auxiliar;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{

		fscanf(pFile,"%s",nombre);

		do{
			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],",id,nombre,horasTrabajadas,sueldo);
			if(cant<4)//elimino la repeticion del ultimo por feof
			{
				break;
			}
			auxiliar=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			if(auxiliar!=NULL)
			{
				ll_add(pArrayListEmployee,auxiliar);//pElement es auxiliar
				todoOk=1;
			}
			else
			{
				employee_delete(auxiliar);
			}
			printf("%s-  %s - %s  - %s",id,nombre,horasTrabajadas,sueldo);
		}while(!feof(pFile));
	}

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int todoOk=0;
	int cant;//retorno de fread
	Employee* auxiliar;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do{
			auxiliar= employee_new();
			if(auxiliar!=NULL)
			{
				fread(auxiliar,sizeof(Employee),1,pFile);
				if(cant==1)
				{
					ll_add(pArrayListEmployee,auxiliar);
					printf("lectura exitosa de una estructura\n");
					todoOk=1;
				}
				else
				{
					break;
				}
			}
			else
			{
				employee_delete(auxiliar);
			}
		}while(!feos(pFile));
	}

    return todoOk;
}
