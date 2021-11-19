/*
 * utn.h
 *
 *  Created on: 18 nov. 2021
 *      Author: 1
 */
#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarCaracter(char auxChar, char a, char b);
int validarRangoEntero(int num,  int limSuperior,int limInferior);
int validarRangoFloat(float num,  float limSuperior,float limInferior);
int validarName(char name[],int len);
#endif // UTN_H_INCLUDED
