#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	FILE* f=NULL;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path,"r");
		if(f!=NULL)
		{
			 if(parser_EmployeeFromText(f,pArrayListEmployee))
			 {
				 printf("se cargo con exito");
				 todoOk=1;
			 }
		}
		else
		{
			printf("Error al leer archivo\n");

		}

		fclose(f);
	}
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* f=NULL;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		f=fopen(path,"rb");
		if(f!=NULL)
		{
			if(parser_EmployeeFromBinary(f,pArrayListEmployee))
			{
				printf("se cargo con exito\n");
				todoOk=1;
			}
			fclose(f);
		}
		else
		{
			printf("Error al abrir archivo\n");
		}
	}

	return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char name[128];
    int horasTrabajadas;
    int sueldo;
    int id;
    int retornodeSetterId;
    int retornodeSetterNombre;
    int retornodeSetterSueldo;
    int retornodeSetterHoras;
    Employee* auxiliar;
    if(pArrayListEmployee!=NULL)
    {
    	printf("***Alta Employee***\n");

    	auxiliar=newEmployee();
    	id=employee_mayorId(pArrayListEmployee);
    	if(id!=-1)
    	{
    		id=id+1;//Asigno el siguiente
    		pedirName(name,"Ingrese nombre","Error Reingrese Nombre",128);
    		pedirEntero(&horasTrabajadas,"Ingrese horas trabajadas (valor positivo)","Error Reingrese horas ",3000,4);
    		pedirEntero(&sueldo,"Ingrese sueldo","Error Reingrese sueldo",0,100000);

    		//llamo a los setter
    		retornodeSetterId=employee_setId(auxiliar,id);
    		retornodeSetterNombre=employee_setNombre(auxiliar,name);
    		retornodeSetterHoras=employee_setHoras(auxiliar,horasTrabajadas);
    		retornodeSetterSueldo=employee_setSueldo(auxiliar,sueldo);
    		if(retornodeSetterId && retornodeSetterNombre && retornodeSetterHoras && retornodeSetterSueldo)
    		{
    			ll_add(pArrayListEmployee,auxiliar);
    			printf("Empleado cargado\n");
    			todoOk=1;
    		}
    		else
    		{
    			employee_delete(auxiliar);
    		}
    	}
    }

	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	if(pArrayListEmployee!=NULL)
	{

	}


	return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* auxiliar=NULL;
    if(pArrayListEmployee!=NULL)
    {
    	printf("Lista Empleados \n");
    	printf("id 		nombre		horasTrabajadas		sueldo\n");
    	for(int i=0;i<ll_len(pArrayListEmployee);i++)
    	{
    		auxiliar=(Employee*)ll_get(pArrayListEmployee,i);
    		employee_mostrarUnEmpleado(auxiliar);

    	}
    	todoOk=1;
    }

	return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

