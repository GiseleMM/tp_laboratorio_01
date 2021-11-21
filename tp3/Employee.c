#include "Employee.h"
#include "LinkedList.h"

#include <string.h>
#include <stdio.h>

Employee* employee_new()
{
  Employee* nuevoEmpleado=NULL;
  nuevoEmpleado=(Employee*)malloc(sizeof(Employee));
  if(nuevoEmpleado!=NULL)
  {
	  nuevoEmpleado->id=0;
	  strcpy(nuevoEmpleado->nombre," ");
	  nuevoEmpleado->horasTrabajadas=0;
	  nuevoEmpleado->sueldo=0;

  }
  return nuevoEmpleado;

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	   int retornoId;
	    int retornoNombre;
	    int retornoHorasTrabajadas;
	    int retornoSueldo;

	    Employee* unEmpleado;
	    unEmpleado=new_Empleado();
	    if(unEmpleado!=NULL)
	    {
	        /*SETTERS*/
	        retornoId=employee_setId(unEmpleado,atoi(idStr));
	        retornoNombre=employee_setNombre(unEmpleado,nombreStr);
	        retornoHorasTrabajadas=employee_setHorasTrabajadas(unEmpleado,atoi(horasTrabajadasStr));
	        retornoSueldo=employee_setSueldo(unEmpleado,atoi(sueldoStr));

	        if(!(retornoId && retornoNombre && retornoHorasTrabajadas && retornoSueldo))
	        {
	            //printf("ingrese a if de setter invalido\n");
	            free(unEmpleado);//si no se pudo cargar algun parametro libero la memoria que pedi porque tiene datos cargados y retorno null
	            unEmpleado=NULL;
	        }


	    }
	    return unEmpleado;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
	else
	{
		printf("error en delete employee\n");
	}
}

int employee_setId(Employee* this,int id)
{

	    int todoOk=0;
	    if(this!=NULL  && id>0 )
	    {
	        todoOk=1;
	        this->id=id;
	    }
	    else
	    {
	        printf("No se pudo cargar  id\n");
	    }

	//printf("return de id %d\n", todoOk);
	    return todoOk;

}

int employee_getId(Employee* this,int* id)
{
	int todoOk=0;
	if(this!=NULL && id!=NULL)
	{
		todoOk=1;
		*id=this->id;
	}

	return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int todoOk=0;
	char auxNombre[128];
	if(this!=NULL && nombre!=NULL && strlen(nombre)>0 && strlen(nombre)<128)
	{
		todoOk=1;
		strcpy(auxNombre,nombre);
		strlwr(auxNombre);
		auxNombre[0]=toupper(auxNombre[0]);
		        int i=1;
		        while(auxNombre[i]!='\0')
		        {
		            if(auxNombre[i]==' ')
		            {
		                auxNombre[i+1]=toupper(auxNombre[i+1]);
		            }
		            i++;

		        }
		strcpy(this->nombre,auxNombre);
	}
	else
	{
		printf("no se pudo  cargar nombre\n");

	}

	return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk=0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk=1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int todoOk=0;
	if(this!=NULL && horasTrabajadas >0)
	{
		todoOk=1;
		this->horasTrabajadas=horasTrabajadas;
	}
	else
	{
		printf("No se pudo cargar horas trabajadas\n");
	}
	return  todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int todoOk=0;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		horasTrabajadas=this->horasTrabajadas;
		todoOk=1;
	}

	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{

	    int todoOk=0;
	    if(this!=NULL && sueldo>0 )
	    {
	        todoOk=1;
	        this->sueldo=sueldo;
	    }
	    else
	    {
	        printf("No se pudo cargar  sueldo\n");
	    }

	    //printf("return de sueldo %d", todoOk);
	    return todoOk;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int todoOk=0;
	if(this!=NULL && sueldo!=NULL)
	{
		sueldo= this->sueldo;
		todoOk=1;
	}

return todoOk;
}

int employee_mayorId(LinkedList* pArrayListEmployee)
{
	Employee* auxiliar=NULL;
	int idMayor=-1;
	int id;
	if(pArrayListEmployee!=NULL)
	{

		for(int i=0; i<  ll_len(pArrayListEmployee);i++)
		{
			auxiliar=(Employee*)ll_get(pArrayListEmployee,i);//casteo el puntero void* que retorna get
					if(auxiliar!=NULL)
					{
						employee_getId(auxiliar,&id);
						if(i==0 || id>idMayor)
						{
							idMayor=id;

						}

					}
		}

	}
	/* si -1 no encontro el mayor si >0 es un id mayor*/
	return idMayor;
}
int employee_buscarPorId(LinkedList* pArrayListEmployee, int id)
{
	int index=-1;
	int auxId;
	Employee* auxiliar=NULL;
	if(pArrayListEmployee!=NULL && id>0)
	{

		for(int i=0; i< ll_len(pArrayListEmployee);i++ )
		{
			employee_getId(pArrayListEmployee,&auxId);
			if(auxId==id)
			{
				index=i;
			}
		}
	}
	return index;
}
int employee_mostrarUnEmpleado(Employee* p)
{
	int todoOk=0;
	int id;
	int sueldo;
	int horas;
	char name[128];
	int retornodeGetId;
	int retornodeGetSueldo;
	int retornodeGetName;
	int retornodeGetHoras;

	if(p!=NULL)
	{

		retornodeGetId=employee_getId(p,&id);
		retornodeGetName=employee_getNombre(p,name);
		retornodeGetHoras=employee_getHorasTrabajadas(p,&horas);
		retornodeGetSueldo=employee_getSueldo(p,&sueldo);

		if(retornodeGetId && retornodeGetName && retornodeGetHoras && retornodeGetSueldo)
		{
			todoOk=1;
			printf("%d		%-20s		%d		%d",id,name,horas,sueldo);


		}
	}


	return todoOk;

}
