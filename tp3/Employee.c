#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "MiBiblioteca.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>



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
	    if(idStr!=NULL &&  nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	    {

	    	unEmpleado=employee_new();
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
	//int auxId;
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
	//char auxNombre[128];
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk=1;
	}
	//strcpy(nombre,auxNombre);
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
	int auxHoras=0;
	if(this!=NULL && horasTrabajadas!=NULL)
	{

		auxHoras=this->horasTrabajadas;
		todoOk=1;
	}
	*horasTrabajadas=auxHoras;

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
	int auxSueldo;
	if(this!=NULL && sueldo!=NULL)
	{
		auxSueldo= this->sueldo;
		todoOk=1;
	}
	*sueldo=auxSueldo;

return todoOk;
}

int employee_buscarMayorId(LinkedList* pArrayListEmployee)
{
	Employee* auxiliar=NULL;
	int idMayor=0;
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
			auxiliar=(Employee*)ll_get(pArrayListEmployee,i);//NO OLVIDAR ll_GET

			/* NO>>>employee_getId(pArrayListEmployee,&auxId);

			if(auxId==id)
			{
				index=i;
			}
			*/
			if(employee_getId(auxiliar,&auxId) &&  auxId==id)
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
			printf("%d		%-20s		%d		%d\n",id,name,horas,sueldo);


		}
	}


	return todoOk;

}
int employee_modificar(LinkedList* pArrayListEmployee)
{

	    int todoOk=0;
	    int auxId;
	    char auxName[128];
	    int auxSueldo;
	    int auxHoras;
	    int index;
	    int opcion;
	    Employee* auxiliarEmpleado;
	    int seRealizoModificacion=0;
	    char confirma;//confirma modificacion
	    if(pArrayListEmployee!=NULL)
	    {
			printf("Modificar datos empleado\n");
			controller_ListEmployee(pArrayListEmployee);//muestro
			fflush(stdin);
			printf("ingrese id\n:");
			while(!scanf("%d",&auxId))
			{
				fflush(stdin);
				printf("Error reingrese id\n");
			}

			index=employee_buscarPorId(pArrayListEmployee,auxId);
			if(index==-1)
			{
				printf("id no registrado en el sistema\n");

			}
			else
			{
				auxiliarEmpleado=(Employee*)ll_get(pArrayListEmployee,index);
				employee_mostrarUnEmpleado(auxiliarEmpleado);
				fflush(stdin);
				printf("confirma la modificacion sobre este empleado\n");
	            scanf("%c",&confirma);
	            confirma=tolower(confirma);

	            while(!validarCaracter(confirma,'s','n'))
	            {
	            	fflush(stdin);
	                printf("ERROR Confirma modificacion S/N: \n");
	                scanf("%c",&confirma);
	                confirma=tolower(confirma);
	            }

	            if(confirma=='n')
	            {

	                printf("Modificacion cancelada  por el usuario\n");
	            }
	            else
	            {

	            	do{
	                	switch(menuModificacion())
	                	{
	                		case 1:
	                			pedirName(auxName,"Ingrese nuevo Nombre","ERROR reingrese nombre",128);
	                			puts(auxName);
	                			if(!employee_setNombre(auxiliarEmpleado,auxName))
	                			{
	                				printf("Error al modificar nombre\n");
	                			}
	                			else
	                			{
	                				printf("modificacion exitosa\n");
	                				seRealizoModificacion=1;
	                			}

	                    break;

	                	case 2:
	                    pedirEntero(&auxHoras,"Ingrese nuevas horas trbajadas","ERROR reingrese hoara",5000,1);
	                    printf("%d\n",auxHoras);
	                    		if(!employee_setHorasTrabajadas(auxiliarEmpleado,auxHoras))
	                    		{
	                    			printf("error al modificar horas\n");
	                    		}
	                    		else
	                    			{
	                    			printf("modificacion exitosa\n");
	                    			seRealizoModificacion=1;
	                    			}
	                    break;

	                	case 3:

	                    pedirEntero(&auxSueldo,"Ingrese nuevo sueldo","Error Reingrese suelso",100000,1);
	                    printf("%d\n",auxSueldo);
	                    if(!employee_setSueldo(auxiliarEmpleado,auxSueldo))
	                    {
	                    	printf("error al modificar Sueldo\n");
	                    }
	                    else
						{
	                    	printf("modificacion exitosa\n");
	                    	seRealizoModificacion=1;
						}
	                    break;

	                	case 4:

	                    fflush(stdin);
	                	printf("Ingreso a salir, confirma salida S/N: \n");
	                	scanf("%c",&confirma);
	                	confirma=tolower(confirma);
	                	while(!validarCaracter(confirma,'s','n'))
	                	{
	                		fflush(stdin);
	                		printf("error, desea salir s o n: ");
	                		scanf("%c",&confirma);
	                		confirma=tolower(confirma);
	                	}

	                    if(confirma =='s')
	                    {
	                    	opcion=5;
	                    	if(seRealizoModificacion==1)
	                    	{
	                    		todoOk=1;
	                    	}
	                    }
	                    break;
	                	}//FIN DEL SWITCH
	                	system("pause");
	                }while(opcion!=5);
	            }

	        }

	    }
	    //MUESTRO MODIFICACION
	    if(todoOk==1)
	    {
	        employee_mostrarUnEmpleado(auxiliarEmpleado);
	    }
	    return todoOk;
}

int menuModificacion()
{
	int opcion=0;
	system("cls");
	printf("Menu Modificar\n");
    printf("1- Modificar nombre\n");
    printf("2- Modificar horas \n");
    printf("3- Modificar sueldo\n");

    printf("4- Salir\n");
    printf("Ingrese opcion: \n ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);
        //scanf("%d",&opcion);//si lo coloco adentro me pide 2 veces la opcion
    }


	return opcion;

}
int employee_baja(LinkedList* pArrayListEmployee)
{
	int todoOk=0;
	char confirma;
	Employee* auxiliarEmpleado=NULL;//NO OLVIDAR Q APUNTE a NULL
	int index;
	int id;
	if(pArrayListEmployee!=NULL)
	{
//MUESTRO
		controller_ListEmployee(pArrayListEmployee);
//PIDO ID
		pedirEntero(&id,"Ingrese id empleado","Error reingrese id", 100000,1);
//BUSCO PERSONA ID
		index=employee_buscarPorId(pArrayListEmployee,id);
		if(index==-1)
		{
			printf("Id no registrado en el sistema\n");
		}
		else
		{
//TRAIGO EMPLEADO CON LL_GET
			auxiliarEmpleado=(Employee*)ll_get(pArrayListEmployee,index);
			employee_mostrarUnEmpleado(auxiliarEmpleado);
//CONFIRMO BAJA
			fflush(stdin);
			printf("Confirma baja logica del empleado s/n:  \n");
			scanf("%c",&confirma);
			confirma=tolower(confirma);
			while(!validarCaracter(confirma,'s','n'))
			{
				fflush(stdin);
				printf("error Reingrese respuesta s o n:\n");
				scanf("%c",&confirma);
				confirma=tolower(confirma);
			}

			if(confirma=='s')
			{
				ll_remove(pArrayListEmployee,index);
				todoOk=1;
			}
			else
			{
				printf("Baja cancelada por el usuario\n");
			}

		}


	}


	return todoOk;
}
int employee_alta(LinkedList* pArrayListEmployee)
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
        system("pause");
    	system("cls");
    	printf("***Alta Empleado***\n");

    	auxiliar=employee_new();
    	id=employee_buscarMayorId(pArrayListEmployee);

    	//printf("id mayor %d",id);

    		id=id+1;//Asigno el siguiente
    		fflush(stdin);

            pedirName(name,"Ingrese nuevo Nombre","ERROR reingrese nombre",128);
            puts(name);
    		fflush(stdin);
    		printf("\n ingrese horas trabajadas ");
    		while(!scanf("%d",&horasTrabajadas))
            {
                fflush(stdin);
                printf("Error ingrese horas\n");
            }
            printf("\ningrese sueldo\n");
            while(!scanf("%d)",&sueldo))
            {
                fflush(stdin);
                printf("ERROR reingrese sueldo\n");
            }

    		//llamo a los setters
    		retornodeSetterId=employee_setId(auxiliar,id);
    		retornodeSetterNombre=employee_setNombre(auxiliar,name);
    		retornodeSetterHoras=employee_setHorasTrabajadas(auxiliar,horasTrabajadas);
    		retornodeSetterSueldo=employee_setSueldo(auxiliar,sueldo);
    		if(retornodeSetterId && retornodeSetterNombre && retornodeSetterHoras && retornodeSetterSueldo)
    		{
    			ll_add(pArrayListEmployee,auxiliar);
    			printf("Empleado cargado con exito\n");
    			todoOk=1;
    		}
    		else
    		{
    			employee_delete(auxiliar);
    		}
    	}
    	printf("retorno de alta %d\n",todoOk);

	return todoOk;

}




int employee_mostrarEmpleados(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int hayEmpleados=0;
    Employee* auxiliar=NULL;
    if(pArrayListEmployee!=NULL)
    {
//VERIFICO QUE HAYA EMPLEADOS QUE MOSTRAR CON LL_LEN
    	hayEmpleados=ll_len(pArrayListEmployee);

    	if(hayEmpleados>0)
    	{


    		printf("Lista Empleados \n");


    		printf("id 		nombre		horasTrabajadas		sueldo\n");
    		for(int i=0;i<hayEmpleados;i++)
    		{
    			auxiliar=(Employee*)ll_get(pArrayListEmployee,i);
    			if(auxiliar!=NULL)
    			{
    				employee_mostrarUnEmpleado(auxiliar);
    			}


    		}
    		todoOk=1;
    	}
    	else
    	{
    		todoOk=-1;/*no hay empleados ingresados*/
    	}
    }

	return todoOk;
}
int employee_ordenarPorNombre( void* nombreA, void* nombreB )
{//int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
	int resultadoComparacion=0;
	char nombre1[128];
	char nombre2[128];
	Employee* auxiliarEmpleado1=NULL;
	Employee* auxiliarEmpleado2=NULL;
	int retornoGetNombre1;
	int retornoGetNombre2;
	/*	 employee_getName(nombreA, nombre1);
	employee_getName(nombreB, nombre2);
	*/



	if(nombreA!=NULL && nombreB!=NULL)
	{
		auxiliarEmpleado1=(Employee*)nombreA;
		auxiliarEmpleado2=(Employee*)nombreB;

	}
	retornoGetNombre1=employee_getNombre(auxiliarEmpleado1, nombre1);
	retornoGetNombre2=employee_getNombre(auxiliarEmpleado2, nombre2);
	if(retornoGetNombre1 && retornoGetNombre2)
	{
		resultadoComparacion= strcmp(nombre1,nombre2);

	}
	/*0 iguales >0 nombre1 mayor <0 mayor nombre2*/
	return resultadoComparacion;
}
int employee_ordenarPorHora(void* horaA, void* horaB)
{
	int resultadoComparacion=0;
	int hora1;
	int hora2;
	Employee* auxiliarEmpleado1=NULL;
	Employee* auxiliarEmpleado2=NULL;
	int retornoGetHora1;
	int retornoGetHora2;

	if(horaA!=NULL &&  horaB!=NULL)
	{
		auxiliarEmpleado1=(Employee*)horaA;
		auxiliarEmpleado2=(Employee*)horaB;
		retornoGetHora1=employee_getHorasTrabajadas(auxiliarEmpleado1,&hora1);
		retornoGetHora2=employee_getHorasTrabajadas(auxiliarEmpleado2,&hora2);
		/*system("pause");
		printf("retorno de get hora 1 %d",retornoGetHora1);
		printf("retorno de get hora 2 %d",retornoGetHora2);*/
		if(retornoGetHora1 && retornoGetHora2)
		{
			if(hora1>hora2)
			{
				resultadoComparacion=1;
			}
			else
			{
				if(hora1<hora2)
				{
					resultadoComparacion=-1;
				}
			}
		}
	}
	//system("pause");
	//printf("resultado comparacion hora %d", resultadoComparacion);
	return resultadoComparacion;
}
int employee_ordenarPorSueldo(void* sueldoA, void* sueldoB)
{
	int sueldo1;
	int sueldo2;
	int resultadoComparacion=0;
	int retornoGetSueldo1;
	int retornoGetSueldo2;
	Employee* auxiliarEmpleado1=NULL;
	Employee* auxiliarEmpleado2=NULL;
	if(sueldoA!=NULL && sueldoB!=NULL)
	{
		auxiliarEmpleado1=(Employee*)sueldoA;
		auxiliarEmpleado2=(Employee*)sueldoB;

		retornoGetSueldo1=employee_getSueldo(auxiliarEmpleado1,&sueldo1);
		retornoGetSueldo2=employee_getSueldo(auxiliarEmpleado2,&sueldo2);
		if(retornoGetSueldo1 && retornoGetSueldo2)
		{
			if(sueldo1>sueldo2)
			{
				resultadoComparacion=1;
			}
			else
			{
				if(sueldo1<sueldo2)
				{
					resultadoComparacion=-1;
				}
			}

		}

	}
	return resultadoComparacion;
}
int employee_ordenar(LinkedList* pArrayListEmployee)
{
	int todoOk=0;

	int seOrdeno=0;
	//LinkedList* auxiliar=NULL;
	int opcion=0;
	if(pArrayListEmployee!=NULL)
	{
		//auxiliar=pArrayListEmployee;

	do{
            //LinkedList* auxLinkedList=ll_clone(pArrayListEmployee)
		switch(menuOrdenar())
		{
		case 1:
			printf("Ordenar por nombre\n");
			ll_sort(pArrayListEmployee,employee_ordenarPorNombre,1);
			controller_ListEmployee(pArrayListEmployee);
			seOrdeno=1;
			break;
		case 2:
			printf("Ordenar por horas\n");
			ll_sort(pArrayListEmployee,employee_ordenarPorHora,1);
			controller_ListEmployee(pArrayListEmployee);
			seOrdeno=1;
			break;
		case 3:
			printf("Ordenar por sueldo\n");
			ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,1);
			controller_ListEmployee(pArrayListEmployee);
			seOrdeno=1;
			break;
		case 4:
			printf("ingreso salir\n");
			opcion=5;
			break;
		default:
			printf("opcion invalida\n");
			break;
		}
		system("pause");
	}while(opcion!=5);
	if(seOrdeno)
    {
        todoOk=1;
    }

	}

	return todoOk;
}
int menuOrdenar()
{
	int opcion=0;
	system("cls");
	printf("Menu Ordenar\n");
    printf("1- Ordenar por nombre\n");
    printf("2- Ordenar por horas \n");
    printf("3- Ordenar por sueldo\n");

    printf("4- Salir\n");
    printf("Ingrese opcion: \n ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);
        //scanf("%d",&opcion);//si lo coloco adentro me pide 2 veces la opcion
    }


	return opcion;

}
int menu()
{

	    int opcion=0;
	    system("cls");
	    printf("     *** TP3 ***\n");
	    printf("  1- Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
	    printf("  2- Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
	    printf("  3- Alta de empleado\n");
	    printf("  4- Modificar datos de empleado\n");
	    printf("  5- Baja de empleado\n");
	    printf("  6- Listar empleados\n");
	    printf("  7- Ordenar empleados\n");
	    printf("  8- Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
	    printf("  9- Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
	    printf("  10- Salir\n");
	    printf("Ingrese opcion: ");

	    while(!(scanf("%d",&opcion)))
	    {

	        printf("Opcion no valida Reingrese opcion\n");
	        fflush(stdin);

	    }

	    return opcion;

}

