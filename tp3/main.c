#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    setbuf(stdout,NULL);
	int option = 0;
	char confirma='n';
	int seCargo=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	option=menu();
        switch(option)
        {
            case 1:

                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                	printf("error a cargar Archivo modo texto\n");
                }
                seCargo=1;

                break;
            case 2:
            	if(!controller_loadFromBinary("data.bin",listaEmpleados))
            	{
            			printf("error a cargar Archivo modo binario\n");
           		}
            	break;
            case 3:
            	if(seCargo==1)
            	{


            		if(!controller_addEmployee(listaEmpleados))
            		{
            			printf("error en alta de empleado\n");
            		}
            	}
            	else
            	{
            		printf("antes debe cargar archivo en el sistema\n ");
            	}
            	break;
            case 4:
	            if ( !controller_editEmployee(listaEmpleados) )
	            {
	                printf("error en modificacion de empleado\n");
	            }
            	break;
            case 5:
	            if ( !controller_removeEmployee(listaEmpleados) )
	            {
	                printf("error en baja de empleado\n");
	            }
            	break;
            case 6:
	            if ( !controller_ListEmployee(listaEmpleados) )
	            {
	                printf("error en listar empleados\n");
	            }
            	break;
            case 7:
	            if ( !controller_sortEmployee(listaEmpleados) )
	            {
	                printf("error en ordenamiento de empleados\n");
	            }
            	break;
            case 8:
	            if ( !controller_saveAsText("data.csv", listaEmpleados) )
	            {
	                printf("error al guardar en modo texto\n");
	            }
            	break;

            case 9:
	            if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
	            {
	                printf("error al guardar en modo binario\n");
	            }
            	break;
            case 10:
            	//option=11;
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
                	printf("Saliendo del progroma\n");
                	//option=11;
                }
                fflush(stdin);
            	break;
            //case 11:
            	//printf("Saliendo del progroma\n");
            	//break;
            default:
            	printf("opcion invalida\n");
            	break;

        }
        system("pause");
        system("cls");
    }while(confirma!='s');

    return 0;
}

