/*
 ============================================================================
 Name        : TP2.c
 Author      : gisele medina
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define TAM_NAME 51
#define TAM 10


int main()
{
	setbuf(stdout,NULL);
    int nextId=5000;
    int id;
    int index;
    char confirma;// variable para confirmar baja
    int order;//criterio de ordenamiento
    Employee list[TAM];
    if(!initEmployees(list,TAM))
    {
        printf("problemas al inicializar\n!");
    }

    char seguir='s';
    do
    {
        switch(menu())
        {
        case 1:
            printf("ingrese a alta\n\n");

            char name[51];
            char lastName[51];
            float salary;
            int sector;
            int retorno;

            pedirName(name,"Ingrese name", "ERROR reIngrese name",TAM_NAME);
            puts(name);
            pedirName(lastName,"Ingrese Apellido","Error Reingrese Apellido",TAM_NAME);
            puts(lastName);


            pedirSalario(&salary,"Ingrese salario 1 a 100000","Error Reingrese salario");
            printf("%6.2f",salary);
            pedirSector(&sector,"Ingrese Sector de 0 a 10", "Error Reingrese sector");
            printf("%d\n",sector);


            retorno=addEmployee(list,TAM,&nextId,name,lastName,salary,sector);
            if(retorno==0)
            {
                printf("alta exitosa\n");
            }
            else
            {
                printf("no se pudo realizar el alta\n");
            }
            break;
        case 2:

            if(buscarLLeno(list,TAM)==0)
            {
                printf("Ingrese a modificar\n");
                if(modificarEmployee(list,TAM)==-1)
                {
                    printf("No se pudo realizar la modificacion\n");
                }
                else
                {
                    printf("Modificacion exitosa");
                }


            }
            else
            {
                printf("No hay ingresado empleados activos\n");
            }
            break;
        case 3:
            if(buscarLLeno(list,TAM)==0)
            {
                printf("***BAJA***\n");
                printEmployees(list,TAM);

                printf("ingrese Id:\n");
                scanf("%d",&id);
                index=findEmployeeById(list,TAM,id);
                if(index==-1)
                {
                    printf("Id no valido\n");
                }
                else
                {
                    mostrarEmpleado(list[index]);
                    fflush(stdin);
                    printf("confirma la baja S/N:\n");
                    scanf("%c",&confirma);
                    confirma=tolower(confirma);
                    while(!validarCaracter(confirma,'s','n'))
                    {
                        printf("Respuesta No valida. Confirma la baja S/N:\n");
                        fflush(stdin);
                        scanf("%c",&confirma);
                        confirma=tolower(confirma);
                    }
                    if(confirma=='s')
                    {
                        //printf("INDICE %d\n",index);
                        //system("pause");
                        if(removeEmployee(list,TAM,id)==0)//paso el id NO EL INDEX
                        {
                            printf("Baja exitosa\n");
                        }
                        else
                        {
                            printf("no se pudo realizar la baja\n");
                        }

                    }
                    else
                    {
                        printf("Baja cancelada por el usuario\n");
                    }


                }

            }
            else
            {
                printf("NO hay empleados ingresados\n");
            }

            break;
        case 4:
            if(buscarLLeno(list,TAM)==0)
            {
                printf("Ingrese a informar\n");

                switch(menuInforme())
                {
                case 1:
                    printf("Ingrese criterio de ordenamiento 1 ASCENDENTE 0 DECENDENTE:\n");
                    scanf("%d",&order);
                    while(!validarRangoEntero(order,1,0))
                    {
                        fflush(stdin);
                        printf("Valor no valido RE-ingrese criterio 1 o 0 :\n");
                        scanf("%d",&order);


                    }
                    sortEmployees(list,TAM,order);
                    if(printEmployees(list,TAM)==-1)
                    {
                        printf("error al mostrar empleado\n");
                    }
                    break;
                case 2:
                    informeSalario(list,TAM);

                    break;
                case 3:
                    printf("Ingrese a Salir\n");
                    break;
                default:
                    printf("opcion invalida\n");
                    break;


                }


            }
            else
            {
                printf("No hay empleados para mostrar\n");
            }

            break;
        case 5:
            printf("ingrese a salir\n");
            seguir='n';
            break;
        default:
            printf("opcion invalida");
            break;



        }

        system("pause");
    }
    while(seguir=='s');




    return 0;
}












