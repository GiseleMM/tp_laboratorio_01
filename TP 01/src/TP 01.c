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
#include "calculadoraTP1.h"

int main()
{
	setbuf(stdout,NULL);
    int es;
    int banderaNumero2=0;
    int banderaNumero1=0;
    int retornoFactorialNumero1;
    int retornoFactorialNumero2;
    int retornoDivision;
    int banderaOperaciones=0;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoFactorialNumero1;
    int resultadoFactorialNumero2;
    float numero1;
    float numero2;

    int opcion;
    do{
            system("cls");
            printf("TP1 Calculadora\n\n");
            opcion=menu();
            switch(opcion)
        {
        case 1 :
        	fflush(stdin);
            printf("\nA= ");
            es=ingresarNumero(&numero1);
            if(es==1)
            {
              printf("\nA=%f\n\n",numero1);
              banderaNumero1=1;
            }
            else
            {
               printf("\n No ingresaste numeros");
            }
            break;
        case 2 :
        	fflush(stdin);
            printf("\nB= ");
            es=ingresarNumero(&numero2);
            if(es==1)
            {
              printf("\nB=%f\n\n",numero2);
              banderaNumero2=1;
            }
            else
            {
               printf("\nNo ingresaste numeros\n\n");
            }
            break;
        case 3:

            if(banderaNumero1==0 || banderaNumero2==0)
            {
                printf("Debes ingresar operandos\n\n");
            }
            else
            {   banderaOperaciones=1;
                printf("a) Calcular la suma ( %.2f +%.2f)\n", numero1,numero2);
                printf("b) Calcular la resta (%.2f- %.2f)\n", numero1,numero2);
                printf("c) Calcular la division (%.2f / %.2f)\n",numero1,numero2);
                printf("d) Calcular la multiplicacion (%.2f * %.2f)\n",numero1,numero2);
                printf("e) Calcular el factorial (%.2f!) y (%.2f!)\n", numero1, numero2);
                resultadoSuma= sumar(numero1,numero2);
                resultadoResta=restar(numero1,numero2);
                resultadoMultiplicacion=multiplicar(numero1,numero2);
                retornoDivision=dividir(numero1, numero2, &resultadoDivision);
                retornoFactorialNumero1=factorial(numero1,&resultadoFactorialNumero1);
                retornoFactorialNumero2=factorial(numero2,&resultadoFactorialNumero2);

                banderaNumero1=0;
                banderaNumero2=0;

            }
            break;
        case 4:
            if(banderaOperaciones==1)
            {
                banderaOperaciones=0;
                informarResultados(numero1,numero2,retornoDivision,resultadoDivision,retornoFactorialNumero1,retornoFactorialNumero2,resultadoFactorialNumero1, resultadoFactorialNumero2, resultadoMultiplicacion, resultadoResta, resultadoSuma);

            }
            else
            {
                printf("Antes de elegir esta opcion debe Ingresar operando y calcular todas las operaciones\n\n");

            }
            break;
        case 5:
            printf("Ingrese salir\n\n");
            break;
        default:
            printf("Opcion invalida\n\n");

            break;
        }
        system("pause");
    }while(opcion!= 5);
    return  EXIT_SUCCESS;
}
