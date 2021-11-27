/*
 * MiBiblioteca.h
 *
 *  Created on: 26 nov. 2021
 *      Author: 1
 */

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_

int pedirName(char name[],char mensaje[],char mensajeError[], int len);
int validarName(char name[],int len);
int pedirEntero(int* entero,char mensaje[],char mensajeError[],int limSup,int limInf);
int validarRangoEntero(int num,  int limSuperior,int limInferior);
int validarCaracter(char auxChar, char a, char b);
float aplicarDescuento(float precio, int porcentajeDescuento);
float aplicarAumento(float precio, int porcentajeAumento);

#endif /* MIBIBLIOTECA_H_ */
