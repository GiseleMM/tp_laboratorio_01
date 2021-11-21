/*
 * utn.h
 *
 *  Created on: 20 nov. 2021
 *      Author: 1
 */

#ifndef UTN_H_
#define UTN_H_

int pedirName(char name[],char mensaje[],char mensajeError[], int len);
int validarName(char name[],int len);
int pedirEntero(int* entero,char mensaje[],char mensajeError[],int limSup,int limInf);
int validarRangoEntero(int num,  int limSuperior,int limInferior);

#endif /* UTN_H_ */
