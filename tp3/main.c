#include <stdio.h>
#include <stdlib.h>
#include "MiBiblioteca.h"
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{



    setbuf(stdout,NULL);
    int option = 0;
    char confirma='n';
    int seCargo=0;
    int seCargoB=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option=menu();
        switch(option)
        {
        case 1:
            if(seCargo!=0)
            {
                ll_clear(listaEmpleados);

            }

            if(!controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("Error a cargar Archivo modo texto\n");
            }
            else
            {
                seCargo=1;
            }
            break;
        case 2:
            if(seCargoB!=0)
            {
                ll_clear(listaEmpleados);
            }
            if(!controller_loadFromBinary("data.bin",listaEmpleados))
            {
                printf("error a cargar Archivo modo binario\n");
            }
            else
            {
                seCargoB=1;
            }
            break;
        case 3:

            if(!controller_addEmployee(listaEmpleados))
            {
                printf("error en alta de empleado\n");
            }

            break;
        case 4:
            if(ll_isEmpty(listaEmpleados)==1)
            {
                printf("No hay empleados que modificar\n");
            }
            else
            {


                if ( !controller_editEmployee(listaEmpleados) )
                {
                    printf("error en modificacion de empleado\n");
                }
            }
            break;
        case 5:
            if(ll_isEmpty(listaEmpleados)==1)
            {
                printf("no hay empleados que mostrar\n");
            }
            else
            {


                if ( !controller_removeEmployee(listaEmpleados) )
                {
                    printf("error en baja de empleado\n");
                }
            }
            break;
        case 6:

            if ( !controller_ListEmployee(listaEmpleados) )
            {
                printf("error en listar empleados\n");
            }
            break;
        case 7:
            if(ll_isEmpty(listaEmpleados)==1)
            {
                printf("no hay empleados ingresados\n");
            }
            else
            {
                if ( !controller_sortEmployee(listaEmpleados) )
                {
                    printf("error en ordenamiento de empleados\n");
                }
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

        default:
            printf("opcion invalida\n");
            break;

        }
        system("pause");
        system("cls");
    }
    while(confirma!='s');

    return 0;
}


