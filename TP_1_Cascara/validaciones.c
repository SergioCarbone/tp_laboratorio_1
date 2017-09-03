#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"

/** \brief valida que el usuario haya ingresado un valor y que este sea entero positivo
 *
 * \param valor ingresado
 * \param flag = 0 no ingreso ningun valor
 * \param mensaje pide al usuario que ingrese un valor
 * \param mensaje2 le indica al usuario que el valor ingresado es un numero negativo
 * \return retorno = -1 la validacion resulto fallida o retorno = 0 la validacion se logro
 *
 */
int validarFactorial (float* valorA, int* flagA, char mensaje[], char mensaje2[])
{
    int retorno = -1;

    if(*flagA == 0)
    {
        printf("%s", mensaje);
    }

    if(*valorA < 0)
    {
        printf("%s", mensaje2);
    }
    else
    {
        int entero = (int)*valorA;
        if(*valorA - entero == 0)
        {
            retorno = 0;
        }
        else
        {
            printf("%s", mensaje2);
        }
    }
    return retorno;
}

/** \brief valida que se hayan activado las 2 banderas (se ingresaron los 2 operando)
 *
 * \param flagA = 1 si se ingreso el primer operando
 * \param flagB = 1 si se ingreso el segundo operando
 * \param mensaje1 le avisa al usuario que el primer valor no fue ingresado
 * \param mensaje2 le avisa al usuario que el segundo valor no fue ingresado
 * \return
 *
 */
int validarFlag (int* flagA, int* flagB, char mensaje1[], char mensaje2[])
{
    int retorno = -1;

    if(*flagA == 1 && *flagB == 1)
    {
        retorno = 0;
    }

    if(*flagA == 0)
    {
        printf("%s", mensaje1);
    }
    else if(*flagB == 0)
    {
        printf("%s", mensaje2);
    }
    return retorno;
}
