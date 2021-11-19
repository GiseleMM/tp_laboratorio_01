/*
 * utn.c
 *
 *  Created on: 18 nov. 2021
 *      Author: 1
 */
#include "utn.h"
/** \brief valida el ingreso de un caracter entre 2 opciones
 *
 * \param auxChar char dato a analizar
 * \param a char opcion 1
 * \param b char opcion 2
 * \return int 0 si NO es valido 1 si es valido
 *
 */
int validarCaracter(char auxChar, char a, char b)
{

    int todoOk=1;
    if(auxChar!=a && auxChar!=b)
    {

        todoOk=0;
    }

    return todoOk;
}
/** \brief valida que un numero este dentro de un rango
 *
 * \param num int dato a nalizar
 * \param limSuperior int limite superior del rango
 * \param limInferior int limite infererior del rango
 * \return int O si no es valido 1 si es valido
 *
 */
int validarRangoEntero(int num,  int limSuperior,int limInferior)
{
    int todoOk=0;
    if(num<=limSuperior && num>=limInferior)
    {
        todoOk=1;
    }
    return todoOk;
}
/** \brief recibe una palabra y verifica que no sean numeros
 *
 * \param  name char[] variable a analizar
 * \param len int tamaño del array
 * \param
 * \return int -1 si no es valido 0 si es valido
 *
 */
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
/** \brief valida un numero descimal dentro de rango
 *
 * \param limSuperior float
 * \param limInferior float
 * \param
 * \return int 0 si no esta en el rango 1 si lo esta
 *
 */
int validarRangoFloat(float num,  float limSuperior,float limInferior)
{
    int todoOk=0;
    if(num<=limSuperior && num>=limInferior)
    {
        todoOk=1;
    }
    return todoOk;
}



