#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "MiBiblioteca.h"
#include "parser.h"
// no exite crear #include "parser.h"


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

			printf("Archivo %s abierto modo lectura\n",path);
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
			printf("Archivo %s abierto modo lectura binaria\n",path);
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
	if(pArrayListEmployee!=NULL)
	{
		if(!employee_alta(pArrayListEmployee))
		{
			printf("No se pudo realizar el alta\n");
		}
		else
		{
			printf("alta exitosa\n");
			todoOk=1;
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
		if(!employee_modificar(pArrayListEmployee))
		{
			printf("No se pudo realizar la modificacion \n");

		}
		else
		{
			printf("Modificacion registrada\n");
			todoOk=1;
		}

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
    int todoOk=0;
    if(pArrayListEmployee!=NULL)
    {
    	if(!employee_baja(pArrayListEmployee))
    	{
    		printf("No se pudo realizar la Baja en el sistema\n");
    	}
    	else
    	{
    		todoOk=1;
    		printf("Baja exitosa\n");
    	}
    }
	return todoOk;
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
	int retornoDeMostrarEmpleado;
	if(pArrayListEmployee!=NULL)
	{
		retornoDeMostrarEmpleado=employee_mostrarEmpleados(pArrayListEmployee);
		if(retornoDeMostrarEmpleado==-1)
		{
			printf("No se puede listar Empleados, no hay empleados que mostrar\n");
		}
		else
		{
			if(retornoDeMostrarEmpleado==1)
			{
				printf("Se listo empleado correctamente\n");
				todoOk=1;
			}
			else
			{
				printf("No se pudo listar Empleado\n");
			}


		}

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
	int todoOk=0;

	if(pArrayListEmployee!=NULL)
	{
			if(!employee_ordenar(pArrayListEmployee))
			{
				printf("no se pudo Realizar el ordenamiento\n");
			}
			else
			{
				printf("Ordenamiento exitoso\n");
				todoOk=1;
			}

		}

	  return todoOk;
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
	int todoOk=0;
	FILE* f=NULL;
	int tam;
	int sueldo;
	int horas;
	char nombre[128];
	int id;
	int retornoGetNombre;
	int retornoGetSueldo;
	int retornoGetId;
	int retornoGetHoras;
	Employee* auxiliarEmpleado=NULL;
		if(path!=NULL && pArrayListEmployee!=NULL)
		{
				f=fopen(path,"w");
				if(f==NULL)
				{
					printf("Error al abrir archivo\n");
				}
				else
				{
					tam=ll_len(pArrayListEmployee);
					fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
					for(int i=0;i<tam;i++)
					{
						auxiliarEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
						if(auxiliarEmpleado!=NULL)
						{
							retornoGetId=employee_getId(auxiliarEmpleado,&id);
							retornoGetNombre=employee_getNombre(auxiliarEmpleado,nombre);
							retornoGetHoras=employee_getHorasTrabajadas(auxiliarEmpleado,&horas);
							retornoGetSueldo=employee_getSueldo(auxiliarEmpleado,&sueldo);

							if(retornoGetId && retornoGetNombre && retornoGetHoras && retornoGetSueldo)
							{
								 fprintf(f, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
								 todoOk = 1;
							}
							else
							{
								printf("no se pudo guardar el archivo\n");
							}


						}

					}
					fclose(f);

				}
		}

    return todoOk;
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
	int todoOk=0;
	FILE* f=NULL;
	Employee* auxiliarEmpleado=NULL;
	int tam;
	if(path!=NULL && pArrayListEmployee)
	{
		f=fopen(path,"wb");
		if(f==NULL)
		{
			printf("no se pudo abrir archivo\n");

		}
		else
		{

			tam=ll_len(pArrayListEmployee);
			for(int i=0;i<tam;i++)
			{
				auxiliarEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
				if(auxiliarEmpleado!=NULL)
				{
					fwrite(auxiliarEmpleado,sizeof(Employee),1,f);
					todoOk=1;
				}

			}


		}
		fclose(f);

	}
    return todoOk;
}

