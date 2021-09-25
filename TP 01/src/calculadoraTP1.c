#include "calculadoraTP1.h"
/** \brief Menu de opciones que espera el ingreso por consola de una opcion del tipo char y la guarda en la variable opcion
 *
 * \param void  el menu no recibe ningun parametro
 * \return int la opcion del menu elegida en formato de tipo de dato int
 *
 */
int menu(void)
{
        int opcion;

        fflush(stdin);
        printf("1. Ingresar 1er operando (A=x)\n");
        printf("2. Ingresar 2do operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n");
        printf("a) Calcular la suma (A+B)\n");
        printf("b) Calcular la resta (A-B)\n");
        printf("c) Calcular la division (A/B)\n");
        printf("d) Calcular la multiplicacion (A*B)\n");
        printf("e) Calcular el factorial (A!)\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");
        printf("\nEliga opcion\n");
        scanf("%d", &opcion);


                return opcion;

}
/** \brief calcula la suma de dos numeros
 *
 * \param a float sumando 1
 * \param b float  sumando 2
 * \return float    resultado de la suma
 *
 */
float sumar(float a, float b)
{
    float retorno;
    retorno=a+b;

    return retorno;
}
/** \brief multiplica 2 numeros
 *
 * \param a float operando n1
 * \param b float operando n2
 * \return float    resultado de la multiplicacion
 *
 */
float multiplicar(float a, float b)
{
    float retorno;
    retorno=a*b;

    return retorno;
}
/** \brief resta de 2 numeros.
 *
 * \param a float Minuendo
 * \param b float Sustraendo
 * \return float difencia de la resta entre parametro a y parametro b
 *
 */
float restar(float a, float b)
{
    float retorno;
    retorno=a-b;

    return retorno;
}
/** \brief divide dos numeros y devuelve un flotante
 *
 * \param a float primer dividendo
 * \param b float   divisor
 * \param pResultado float*  resultado de la division
 * \return int  0 no se pudo realizar la division  1 se pudo realizar la division
 *
 */
int dividir(float a, float b, float* pResultado)
{
    int todoOk=0;
    float retorno;
    if(pResultado!=NULL && b!=0)
    {
        retorno=(float)a/b;
        *pResultado=retorno;
        todoOk=1;
    }
    return todoOk;
}
/** \brief      calcula el factorial de forma no recursiva de un entero mayor que cero
 *
 * \param a float   numero sobre el que se realiza el factorial
 * \param pResultado int* direccion de memoria donde devuelve el resultado del factorial
 * \return int 1 el factorial se pudo realizar. -1 el factorial no se pudo realizar por resultado fuera de rango de los enteros. 0 el factorial no se pudo realizar por no ser un entero mayor a cero
 *
 */
int factorial(float a, int* pResultado)
{
    int todoOk=0;
    int temp;

    temp=a;

    float descuento;
    descuento=a-temp;
    int i;
    long fact=1;
    if(a>12)
    {
        todoOk=-1;
    }
    else
    {
                if(descuento==0 && (a>=0) && pResultado!=NULL)
                {

                    if(a==0 || a== 1)
                    {
                        fact=1;
                        todoOk=1;
                    }
                    else
                    {
                        for(i=1;i<=a;i++)
                        {
                            fact= fact*i;
                            todoOk=1;
                        }
                    }
                    *pResultado=fact;
                }

    }

    return todoOk;
}

/** \brief la función espera el ingreso de un numero por consola, me dice si se ingreso o no un numero. En caso de ser un numero lo devuelve en la direccion de memoria de una variable flotante
 *
 * \param Pnumero float* direccion donde se escribirá el numero si se pudo comprobar que es un numero con scanf
 * \return int    o= NO ingreso numeros  1= Ingreso numero
 *
 */
int ingresarNumero(float* Pnumero)
{
        int es;
        float numero;
        int todoOk=1;

        es=scanf("%f",&numero);
        if(es!=1)
        {

            todoOk=0;//no ingresaste numero;
        }
        else
        {
            *Pnumero=numero;
        }
            return todoOk;

}
/** \brief informa el resultado de todas las operaciones
 *
 * \param a float  operando numero 1
 * \param b float   operando numero 2
 * \param retornoDivision int   lo que retorna la  funcion dividir
 * \param resultadoDivision float   lo que devuelve la funcion dividir
 * \param retornoFactorialNumero1 int   el retorno de la funcion factorial aplicada al operando n 1
 * \param retornoFactorialNumero2 int   el retorno de la funcion factorial aplicada al operando n2
 * \param resultadoFactorialNumero1 int     lo que devuelve la funcion factorial de n1
 * \param resultadoFactorialNumero2 int     lo que devuelve la funcion factorial de n2
 * \param resultadoMultiplicacion float     lo que devuelve la funcion multiplicar
 * \param resultadoResta float      lo que devuelve la funcion restar
 * \param resultadoSuma float   lo que devuelve la funcion Sumar
 * \return void
 *
 */
void informarResultados(float a, float b, int retornoDivision, float resultadoDivision, int retornoFactorialNumero1, int retornoFactorialNumero2, int resultadoFactorialNumero1,int resultadoFactorialNumero2, float resultadoMultiplicacion, float resultadoResta, float resultadoSuma )
{
    printf("a) El resultado de %.2f + %.2f es: %.2f\n", a, b, resultadoSuma);
    printf("b) El resultado de %.2f - %.2f es: %.2f\n", a, b, resultadoResta);

    if(retornoDivision==1)
    {
         printf("c) El resultado de %.2f / %.2f es: %.2f\n", a, b, resultadoDivision);
    }
    else
    {
        printf("c)No se puede dividir por 0\n");

    }


    printf("d) El resultado de %.2f * %.2f es: %.2f\n", a, b, resultadoMultiplicacion);

    if(retornoFactorialNumero1==1)
    {
         printf("e) El factorial de %.0f  es %d y ", a,resultadoFactorialNumero1);
    }
    else
    {
        if(retornoFactorialNumero1==-1)
        {
            printf("e) El factorial de %.0f no se pudo calcular, numero fuera de rango y ", a);
        }
        else
        {
            printf("e) El factorial de %f no se pudo calcular por no ser un numero entero mayor que O , y ",a);
        }
    }

    if(retornoFactorialNumero2==1)
    {
        printf("El factorial de %.0f es %d . \n\n", b, resultadoFactorialNumero2);
    }
    else
    {

        if(retornoFactorialNumero2==-1)
        {
            printf("El factorial de %.0f no se pudo calcular, numero fuera de rango.\n\n", b);
        }
        else
        {
            printf("El factorial de  %f no se pudo calcular por no ser un numero entero mayor que O .\n\n",b);
        }

    }


}
