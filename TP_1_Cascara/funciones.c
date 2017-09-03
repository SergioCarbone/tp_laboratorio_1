#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"

/** \brief Solicita al usuario una opcion del menu
 *
 * \param mensaje muestra el mensaje pidiendo el ingreso de un valor
 * \param mensajeError mensaje en caso de que la opcion no este en el menu
 * \param opcion puntero donde va a guardar el valor ingresado
 *
 */
int pedirOpcion (char mensaje[], char msjError[], int* opcion)
{
    int aux;

    printf("%s", mensaje);
    scanf("%d",&aux);
    while(aux <= 0 || aux > 9)
    {
        printf("%s", msjError);
        scanf("%d", &aux);
    }

    *opcion = aux;

    return 0;

}

/** \brief pide un valor al usuario
 *
 * \param mensaje mostrado
 * \param direccion donde se va a guardar el valor ingresado
 *
 */
int pedirDatos (char mensaje[], float* valor)
{
    printf("%s", mensaje);
    scanf("%f", valor);

    return 0;

}


/** \brief realiza la suma de dos valores ingresados por el usuario
 *
 * \param numA primer operando
 * \param numB segundo operando
 * \param resultado de la suma
 *
 */
int opSuma (float* numA, float* numB, float* resultado)
{

    *resultado = *numA + *numB;
    return 0;
}

/** \brief realiza la resta de dos valores ingresados por el usuario
 *
 * \param numA primer operando
 * \param numB segundo operando
 * \param resultado de la resta
 *
 */
int opResta (float* numA, float* numB, float* resultado)
{
    *resultado = *numA - *numB;
    return 0;
}


/** \brief realiza la division de dos valores ingresados por el usuario controlando que no se ingrese CERO como segundo operando
 *
 * \param numA primer operando
 * \param numB segundo operando
 * \param resultado de la division
 *
 */
int opDivision (float* numA, float* numB, float* resultado, char mensaje[])
{
    if(*numB == 0)
    {
        printf("%s",mensaje);
    }
    else
    {
         *resultado = *numA / *numB;
    }
    return 0;
}


/** \brief realiza la multiplicacion de dos valores ingresados por el usuario
 *
 * \param numA primer operando
 * \param numB segundo operando
 * \param resultado de la multiplicacion
 *
 */
int opMultiplicacion (float* numA, float* numB, float* resultado)
{
    *resultado = *numA * *numB;
    return 0;
}

/** \brief calcula el facturial de un valor ingresado por el usuario
 *
 * \param valor ingresado por el usuario
 * \param resultado de la operacion
 *
 */
int opFactorial (float* numA, int* resultFactorial)
{
    float valorA;
    int i, respuesta = 1;

    valorA = *numA;
    for(i=((int)valorA); i>1; i--)
    {
        respuesta = (respuesta * i);
    }
    *resultFactorial = respuesta;
    return 0;
}

