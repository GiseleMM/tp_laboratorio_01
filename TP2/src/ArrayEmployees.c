/*
 * ArrayEmployees.c
 *
 *  Created on: 18 nov. 2021
 *      Author: 1
 */

#include "ArrayEmployees.h"

/** \brief modifica empleado mostrando un menu de opciones  del campo a modificar
 * se le pedira un id y si se encuentra  se pedira que ingrese el nuevo dato
 * \param
 * \param
 * \param
 * \return int -1 si NO se logro 1 si se logro
 *
 */
int modificarEmployee(Employee list[],int len)
{
    int todoOk=-1;
    int auxId;
    char auxName[51];
    char auxLastName[51];
    int auxSector;
    float auxSalary;
    int index;
    char confirma;//confirma modificacion
    if(list!=NULL && len>0)
    {
        printEmployees(list,len);
        printf("Ingrese id:\n");
        while(!scanf("%d",&auxId))
        {
            fflush(stdin);
            printf("Dato no valido\n");
        }
        index=findEmployeeById(list,len,auxId);
        if(index==-1)
        {
            printf("id no registrado en el sistema\n");
        }
        else
        {
            mostrarEmpleado(list[index]);
            fflush(stdin);
            printf("Confirma modificacion S/N: \n");
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
                todoOk=-1;
                printf("Modificacion cancelada  por el usuario\n");
            }
            else
            {
                todoOk=0;
                switch(menuModificacion())
                {
                case 1:
                    pedirName(auxName,"Ingrese nuevo Nombre","ERROR reingrese nombre",len);
                    puts(auxName);
                    strcpy(list[index].name,auxName);
                    break;
                case 2:
                    pedirName(auxLastName,"Ingrese nuevo Apellido","ERROR reingrese apellido",len);
                    puts(auxLastName);
                    strcpy(list[index].lastName,auxLastName);
                    break;
                case 3:
                    pedirSalario(&auxSalary,"Ingrese nuevo salario","Error Reingrese salario");
                    printf("%6.2f\n",auxSalary);
                    list[index].salary=auxSalary;
                    break;
                case 4:
                    pedirSector(&auxSector,"Ingrese nuevo sector", "Error Reingrese salario");
                    printf("%d\n",auxSector);
                    list[index].sector=auxSector;
                    break;
                case 5:
                    printf("Ingreso a salir\n");
                    todoOk=-1;
                    break;
                }//FIN DEL SWITCH
            }

        }

    }
    if(todoOk==0)
    {
        mostrarEmpleado(list[index]);
    }
    return todoOk;
}
/** \brief menu de modificacion  de salari apellido nombre y sector
 *
 * \param
 * \param
 * \param
 * \return int opcion elegida
 *
 */
int menuModificacion()
{

    int opcion;
    system("cls");

    printf("1- Modificar nombre\n");
    printf("2- Modificar Apellido \n");
    printf("3- Modificar salario\n");
    printf("4- Modificar sector\n");
    printf("5- Salir\n");
    printf("Ingrese opcion: \n ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);
        //scanf("%d",&opcion);//si lo coloco adentro me pide 2 veces la opcion
    }


    return opcion;
}
/** \brief realiza un informe con el dato salario de las estructuras employee
 *	calcula el total, el promedio y cuantos empleados superan el promedio
 * \param list
 * \param len
 * \param
 * \return int - 1 si no lo logro 0 si lo logro
 *
 */
int informeSalario(Employee list[],int len)
{
    int todoOk=-1;
    float salarioTotal=0;
    int empleados=0;
    int empleadosSuperanSueldoPromedio=0;
    float promedioSalario;
    if(list!=NULL && len >0)
    {
        todoOk=0;
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {

                salarioTotal=salarioTotal+list[i].salary;
                empleados++;
                //printf("salarioTotal %f", salarioTotal);
            }

        }//FIN DEL FOR
        promedioSalario=salarioTotal/empleados;
        // printf("promedio salarios %f",promedioSalario);
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0 && (list[i].salary>promedioSalario))
            {
                empleadosSuperanSueldoPromedio++;
            }
        }
        printf("El Total de salarios es: %6.2f\n",salarioTotal);
        printf("El promedio de los salarios es: %6.2f\n",promedioSalario);
        printf("La cantidad de empleados que superan el salario promedio es %d\n",empleadosSuperanSueldoPromedio);

    }
    return todoOk;
}
/** \brief menu de informes
 *
 * \param
 * \param
 * \param
 * \return int opcion elegida por el usuario
 *
 */
int menuInforme()
{

    int opcion;
    system("cls");
    printf("***Informe***\n");

    printf("1-Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");//registrar un elelmento
    printf("2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");//eliminar

    printf("3 - Salir\n");
    printf("Ingrese opcion: \n ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);
        //scanf("%d",&opcion);//si lo coloco adentro me pide 2 veces la opcion
    }


    return opcion;
}
/** \brief pide el ingreso del campo sector de una estructura employee
 *
 * \param sector int* direccion de memoria donde se guardara el dato obtenido
 * \param
 * \param
 * \return int -1 si NO se logro 0 si se logro
 *
 */
int pedirSector(int* sector,char mensaje[],char mensajeError[])
{
    int todoOk=-1;
    // int retornoValidarRango;
    int auxSector;
    if(sector!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        todoOk=0;
        printf("%s\n",mensaje);
        while(!scanf("%d",&auxSector))
        {
            fflush(stdin);
            printf("%s\n",mensajeError);

        }

        //retornoValidarRango=validarRangoEntero(auxSector,10,0);
        //printf("%d",  retornoValidarRango);
        //system("pause");
        while(!validarRangoEntero(auxSector,10,0))
        {
            // printf("Ingrese a validar rango");

            fflush(stdin);
            printf("%s\n",mensajeError);
            scanf("%d",&auxSector);
        }
        *sector=auxSector;
    }
    return todoOk;
}
/** \brief pide el ingrese de un campo flotante de la estructura employee
 *
 * \param salary  direccionde memoria donde se guardara el valor obtenido
 * \param
 * \param
 * \return int -1 si no se logro 0 si se logro
 *
 */
int pedirSalario(float* salary,char mensaje[],char mensajeError[])
{
    int todoOk=-1;
    float auxSalario;
    if(salary!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        todoOk=0;
        printf("%s\n",mensaje);

        while(!scanf("%f",&auxSalario))
        {
            fflush(stdin);
            printf("%s\n",mensajeError);


        }
        while(!validarRangoFloat(auxSalario,100000,1))
        {
            // printf("Ingrese a validar rango");

            fflush(stdin);
            printf("%s\n",mensajeError);
            scanf("%f",&auxSalario);
        }

        *salary=auxSalario;
    }
    return todoOk;
}
/** \brief  pide y valida ingreso de uno de los campos de Employee y convierte en mayuscula la 1letra de las palabras ingresadas
 *
 * \param name[] char variable donde se guardara el dato obtenido por la funcion
 * \param mensaje
 * \param mensaje error
 * \param len tam del array
 * \return int -1 si no se logro 0 si se logro
 *
 */
int pedirName(char name[],char mensaje[],char mensajeError[], int len)
{
    int todoOk=-1;
    if(name!=NULL && len>0)
    {
        todoOk=0;
        fflush(stdin);
        printf("%s\n", mensaje);
        gets(name);


        while(validarName(name,len)==-1)
        {
            fflush(stdin);
            printf("%s\n",mensajeError);
            gets(name);

        }
        strlwr(name);
        name[0]=toupper(name[0]);
        int i=1;
        while(name[i]!='\0')
        {
            if(name[i]==' ')
            {
                name[i+1]=toupper(name[i+1]);
            }
            i++;

        }

    }

    return todoOk;


}
/** \brief ordena array de empleado por apellido y sector dependiendo de un criterio ingresado por el usuario
 *
 * \param list
 * \param len
 * \param orden 1 Ascendente 0 Descendente
 * \return int -1 No se logro ordenar 0 si se logro
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int todoOk=-1;
    Employee auxiliarSwap;
    if(list!=NULL && len>0 && (order==1 || order==0))
    {
        //printf("PASE LOS PARAMETROS\n");
        todoOk=0;
        for(int  i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                //printf("ENTRE AL 2 for\n");
                //ASCENDENTE 1
                if(order==1)
                {


                    if((strcmp(list[i].lastName,list[j].lastName)==0)&& (list[i].sector > list[j].sector))
                    {
                        //printf("NOMBRE  IGUALES");
                        auxiliarSwap=list[i];
                        list[i]=list[j];
                        list[j]=auxiliarSwap;

                    }
                    else
                    {
                        if(strcmp(list[i].lastName,list[j].lastName)>0)/*cad1 >cad2*/
                        {
                            //printf("NOMBRE DIFENTE");
                            auxiliarSwap=list[i];
                            list[i]=list[j];
                            list[j]=auxiliarSwap;
                        }
                    }
                }//FIN DE ORDER ASCENDENTE

                if(order==0)
                {
                    if((strcmp(list[i].lastName,list[j].lastName)==0)&& (list[i].sector < list[j].sector))
                    {
                        //printf("NOMBRE  IGUALES");
                        auxiliarSwap=list[i];
                        list[i]=list[j];
                        list[j]=auxiliarSwap;

                    }
                    else
                    {
                        if(strcmp(list[i].lastName,list[j].lastName)<0)/*cad1 >cad2*/
                        {
                            //printf("NOMBRE DIFENTE");
                            auxiliarSwap=list[i];
                            list[i]=list[j];
                            list[j]=auxiliarSwap;
                        }
                    }
                }//FIN DE ORDEN DESCENDENTE
            }
        }
    }
    //printf("RETORNO %d",todoOk);
    return todoOk;
}
/** \brief baja logica del empleado, cambiando el estado del campo isEmpty
 *
 * \param list
 * \param len int tamaño del array
 * \param id int id del empleado a realizar la baja
 * \return int -1 si no se logro 0 si se logro
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int todoOk=-1;
    if(list!=NULL && len>0 && id>=5000)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)
            {
                //printf("INGRESE AL IF DE ISEMPTY ==0");
                todoOk=0;
                list[i].isEmpty=1;/* LIBERO ESPACIO */
                break;
            }
        }
    }
    printf("%d",todoOk);
    return todoOk;
}
/** \brief encuentra un empleado a partir del id
 *
 * \param list employee se recorre en busca de un id coincidente
 * \param len int
 * \param id int id a buscar en el array
 * \return int el indice del array del id encontrado o -1 si no se encontro
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
    int index=-1;
    if(list!=NULL && len>0 && id>=5000)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==0)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}
/** \brief busca en el array de employee una estructura con campo isEmpty 0 LLENO
 *
 * \param list array
 * \param tam int tamaño del array
 * \param
 * \return int -1 si no hay 0 si hay
 *
 */
int buscarLLeno(Employee list[], int tam)//Al menos un empleado ingresado
{
    int todoOk=-1;

    if(list!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==0)//es lo mismo que (lista[i].isEmpty)
            {
                todoOk=0;
                break;//cuando la encontramos salimos por que si no estariamos devolviendo la ultima posicion LIBRE
                // acomodariamos gente desde el final del array al primero
                //error de rendimiento funciona igual
            }
        }

    }
    return todoOk;/*0 si hay almenos un empleado ingresado -1 si no */
}
/** \brief listas los empleados activos
 *
 * \param list  array de empleado
 * \param lenght int tamaño
 * \param
 * \return int 0 si se logro mostrar la lista -1 si no
 *
 */
int printEmployees(Employee* list, int length)
{
    int todoOk=-1;
    if(list!=NULL && length>0)
    {
        printf("\n***LISTAR EMPLEADO ACTIVOS***\n");
        printf("ID      NOMBRE      APELLIDO        SALARIO         SECTOR \n");
        for(int i=0; i<length; i++)
        {
            if(list[i].isEmpty==0)
            {
                todoOk=0;


                mostrarEmpleado(list[i]);
            }
        }

    }
    return todoOk;
}
/** \brief muestra un empleado
 *
 * \param unempleado employee
 * \param
 * \param
 * \return void
 *
 */
void mostrarEmpleado(Employee unEmpleado)
{

    printf("%d      %-10s    %-10s      %6.2f     %d      \n",
           unEmpleado.id,
           unEmpleado.name,
           unEmpleado.lastName,
           unEmpleado.salary,
           unEmpleado.sector
          );
    //no muestro el isEmpty por que es una herramienta interna

}
/** \brief alta empleado
 *
 * \param list[] array de Employee
 * \param len int tamaño del array
 * \param pId int* puntero al id que incrementara una vez dado de alta el empleado
 * \param name[] dato del empleado
 * \param lastName[]
 * \param salary float
 * \param sector int
 * \return int  0 SI se pudo dar de alta -1 NO se pudo
 *
 */
int addEmployee(Employee list[], int len, int* pId, char name[],char lastName[],float salary,int sector)
{
    int todoOk=-1;
    int indice;


    if(list!=NULL && len>0)
    {
        system("cls");//una vez que valide limpio la patalla
        printf("*****Alta Persona****\n");

        indice=buscarLibre(list,len);
        if(indice==-1)
        {
            printf("No hay lugar\n");
        }
        else
        {


            list[indice].id=(*pId); // Employee.id = (*pId);//accedo al valor de la direccion de memoria con el operador de indireccion
            (*pId)++;//primero el valor y despues el incremento
            //no se reutilizan los id. nadie de baja de algo .Nosostros vamos a ser una baja logica pero en la vida real no


            strcpy( list[indice].name,name);
            strcpy(list[indice].lastName,lastName);
            list[indice].salary=salary;
            list[indice].sector=sector;


//ISEMPTY
            list[indice].isEmpty=0;

            todoOk=0; // si se pudo dar de alta

        }

    }
    return todoOk;
}
/** \brief busca en el array una estructura con campo isEmpty vacio 1
 *
 * \param list[] employee array
 * \param tam int tamaño del array de employee
 * \param
 * \return int indice donde hay una estructura vacia o -1 si NO encontro lugar
 *
 */
int buscarLibre(Employee list[], int tam)
{
    int indice=-1;//por si no encuentra ninguna posicion libre
    if(list!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty==1)//es lo mismo que (lista[i].isEmpty)
            {
                indice=i;
                break;//cuando la encontramos salimos por que si no estariamos devolviendo la ultima posicion LIBRE
                // acomodariamos gente desde el final del array al primero
                //error de rendimiento funciona igual
            }
        }

    }
    return indice;
}
/** \brief recorre el array de employees y coloca en el campo isEmpty 1 estructura Vacia
 *
 * \param list[] employee array de empleados
 * \param len int tamaño del array
 * \param
 * \return int 0 si NO se logro inicializar el array 1 SI
 *
 */
int initEmployees(Employee list[], int len)
{
//a un vector vacio recorre todo el array colocando en el campo isEmpty 1
    int todoOk=0;
    if(list!=NULL && len>0)
    {
        todoOk=1;
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty =1;//si coloco un defaine llevarlo a persona.h tambien rellevar el defaine
        }

    }
    return todoOk;
}

/** \brief menu principal de ABM
 *
 * \param
 * \param
 * \param
 * \return int opcion elegida del usuario
 *
 */
int menu()
{
    int opcion;
    system("cls");
    printf("***ABM Personas***\n");
    printf("1- Alta persona\n");//registrar un elelmento
    printf("2- Modificar persona\n");//eliminar
    printf("3- Baja persona\n");//modificar algunos de los campos
    printf("4- Informar\n");//ordenar en base a algun criterio en particular
    printf("5- Salir\n");
    printf("Ingrese opcion: \n ");

    while(!(scanf("%d",&opcion)))
    {

        printf("Opcion no valida Reingrese opcion\n");
        fflush(stdin);
        //scanf("%d",&opcion);//si lo coloco adentro me pide 2 veces la opcion
    }

    return opcion;
}

