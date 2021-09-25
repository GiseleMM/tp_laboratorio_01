/*
 * calculadoraTP1.h
 *
 *  Created on: 25 sep. 2021
 *      Author: 1
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef CALCULADORATP1_H_
#define CALCULADORATP1_H_

int menu(void);
float sumar(float a, float b);
float restar(float a, float b);
float multiplicar(float a, float b);
int dividir(float a , float b, float* pResultado);
int factorial(float a, int* pResultado);
int ingresarNumero(float* pNumero);
void informarResultados(float a, float b, int retornoDivision, float resultadoDivision, int retornoFactorialNumero1, int retornoFactorialNumero2, int resultadoFactorialNumero1,int resultadoFactorialNumero2, float resultadoMultiplicacion, float resultadoResta, float resultadoSuma );


#endif /* CALCULADORATP1_H_ */
