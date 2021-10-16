/*
 ============================================================================
 Name        : TP.c
 Author      : gisele medina
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

#define TAM 1000
int initEmployees(Employee list[], int len);
int menu();

int main()
{
    Employee list[TAM];
    if(!initEmployees(list,TAM))
    {
        printf("problemas al inicializar\n!");
    }

    /*
    El sistema deberá tener el siguiente menú de opciones:
    1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
    de Id. El resto de los campos se le pedirá al usuario.
    2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
    o Salario o Sector
    3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
    4. INFORMAR:
    1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
    2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
    */
    //int nextId=20000;
    char seguir='s';
    do
    {
        switch(menu())
        {
        case 1:
            printf("ingrese a alta");
            break;
        case 2:
            printf("ingrese a modificar");
            break;
        case 3:
            printf("ingrese a baja");
            break;
        case 4:
            printf("ingrese a informar");
            break;
        case 5:
            printf("ingrese a salir");
            seguir='n';
            break;
        default:
            printf("opcion invalida");
            break;



        }

        system("pause");
    }
    while(seguir=='s');



    printf("Hello world!\n");
    return 0;
}
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
int addEmployee(Employee list [], int len, int* pId)
{
    int todoOk=0;
    int indice;
    Employee auxPersona;// me va permitir cargar todos los datos y validarlos ahi es  como un buffer


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
            //printf("Ingrese id: \n");// validar
            //scanf("%d", &auxPersona.id);
            Employee.id = *pId;//accedo al valor de la direccion de memoria con el operador de indireccion
            (*pId)++;//primero el valor y despues el incremento
            //no se reutilizan los id. nadie de baja de algo .Nosostros vamos a ser una baja logica pero en la vida real no
            printf("Ingrese nombre:\n");
            fflush(stdin);
            gets(auxPersona.name );

            printf("Ingrese Apellido \n");
            fflush(stdin);
            gets(auxPersona.lastName);

            printf("Ingrese salario:\n");
            scanf("%f", &auxPersona.salary);

            printf("ingrese sector:\n");
            scanf("%d", &auxPersona.sector);


            auxPersona.isEmpty=0;//indico que esta lleno el campo isEmpty
            list[indice] =auxPersona;//entre al else por que hay indice libre, enla posicion indice que es la que devolvio buscarLibre
            //esta funcion la usaria en el case 1
            todoOk=1; // si se pudo dar de alta

        }

    }
    return todoOk;
}


