/*
 * utn.c
 *
 *  Created on: 20 nov. 2021
 *      Author: 1
 */
#include <stdio.h>

int pedirName(char name[],char mensaje[],char mensajeError[], int len)
{
    int todoOk=-1;
    if(name!=NULL && len>0)
    {
        todoOk=0;
        fflush(stdin);
        printf("%s", mensaje);
        gets(name);


        while(validarName(name,len)==-1)
        {
            fflush(stdin);
            printf("%s",mensajeError);
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
int validarName(char name[],int len)
{
    int todoOk=0;
    if(name!=NULL  && len>0)
    {
        if(strlen(name)<len)
        {
            for(int i=0; i<len; i++)
            {

                if(isdigit(name[i]))
                {
                    todoOk=-1;
                    break;
                }
            }
        }
        else
        {
            todoOk=-1;
        }

    }

    return todoOk;
}

int pedirEntero(int* entero,char mensaje[],char mensajeError[],int limSup,int limInf)
{
    int todoOk=-1;
    // int retornoValidarRango;
    int auxEntero;
    if(entero!=NULL && mensaje!=NULL && mensajeError!=NULL && limInf<=limSup)
    {
        todoOk=0;
        printf("%s\n",mensaje);
        while(!scanf("%d",&auxEntero))
        {
            fflush(stdin);
            printf("%s\n",mensajeError);

        }

        //retornoValidarRango=validarRangoEntero(auxSector,10,0);
        //printf("%d",  retornoValidarRango);
        //system("pause");
        while(!validarRangoEntero(auxEntero,limSup,limInf))
        {
            // printf("Ingrese a validar rango");

            fflush(stdin);
            printf("%s",mensajeError);
            scanf("%d",&auxEntero);
        }
        *entero=auxEntero;
    }
    return todoOk;
}
int validarRangoEntero(int num,  int limSuperior,int limInferior)
{
    int todoOk=0;
    if(num<=limSuperior && num>=limInferior)
    {
        todoOk=1;
    }
    return todoOk;
}
