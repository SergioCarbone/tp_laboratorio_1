#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"

int main()

{
    float valorA = 0, valorB  = 0, resultadoDiv, resultadoSum, resultadoRes, resultadoMult;
    int opcion = 0, respuestaA, flagA = 0, flagB = 0, resp;
    char seguir='s';

    printf("\n1- Ingresar 1er operando (A=x)\n");
    printf("2- Ingresar 2do operando (B=y)\n");
    printf("3- Calcular la suma (A+B)\n");
    printf("4- Calcular la resta (A-B)\n");
    printf("5- Calcular la division (A/B)\n");
    printf("6- Calcular la multiplicacion (A*B)\n");
    printf("7- Calcular el factorial (A!)\n");
    printf("8- Calcular todas las operaciones\n");

    printf("\nIngrese una opcion: ");
    scanf("%d",&opcion);

    while (opcion < 0 || opcion > 8)
    {
        printf("Error, elija entre las opiones del menu: ");
        scanf("%d", &opcion);
    }

    do
    {

        switch(opcion)
        {
        case 1:
            printf("Ingrese el primer operando: ");
            scanf("%f", &valorA);
            flagA = 1;
            break;
        case 2:
            printf("Ingrese el segundo operando: ");
            scanf("%f", &valorB);
            flagB = 1;
            break;
        case 3:
            resp = validarOperaciones(flagA,flagB);
            switch (resp)
            {
            case 1:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);
                break;

            case 2:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);
                break;

            case 3:
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);
                break;
            case 4:
                resultadoSum = suma(valorA, valorB);
                printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);
                break;
            }
            break;
        case 4:
            resp = validarOperaciones(flagA,flagB);
            switch (resp)
            {
            case 1:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n",valorA, valorB, resultadoRes);
                break;

            case 2:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n",valorA, valorB, resultadoRes);
                break;

            case 3:
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n",valorA, valorB, resultadoRes);
                break;
            case 4:
                resultadoRes = resta(valorA, valorB);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n",valorA, valorB, resultadoRes);
                break;
            }
            break;
        case 5:
            resp = validarOperaciones(flagA,flagB);
            switch (resp)
            {
            case 1:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                    break;
                }
                else
                {
                    resultadoDiv = dividir(valorA, valorB);
                    printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                    break;
                }
            case 2:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                    break;
                }
                else
                {
                    resultadoDiv = dividir(valorA, valorB);
                    printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                    break;
                }
            case 3:
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                    break;
                }
                else
                {
                    resultadoDiv = dividir(valorA, valorB);
                    printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                    break;
                }
            case 4:
                if(valorB == 0)
                {
                    printf("No se puede dividir entre 0\n");
                    break;
                }
                else
                {
                    resultadoDiv = dividir(valorA, valorB);
                    printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
                    break;
                }
            }
            break;
        case 6:
            resp = validarOperaciones(flagA,flagB);
            switch (resp)
            {
            case 1:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                resultadoMult = multiplicar(valorA, valorB);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoMult);
                break;
            case 2:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                resultadoMult = multiplicar(valorA, valorB);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoMult);
                break;
            case 3:
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                resultadoMult = multiplicar(valorA, valorB);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoMult);
                break;
            case 4:
                resultadoMult = multiplicar(valorA, valorB);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoMult);
                break;
            }
            break;
        case 7:
            if ( flagA == 0)
            {
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
            }
            if (validacionFactorial(valorA)==1)
            {
                respuestaA = factorial(valorA);
                printf("El factorial de %.0f es: %d \n", valorA, respuestaA);
                break;
            }
            else
            {
                printf("Error, introduzca un valor entero mayor o igual a 0 \n");
                printf("El factorial solo se puede sacar con numeros enteros!\n");
                break;
            }
        case 8:
            resp = validarOperaciones(flagA,flagB);
            switch (resp)
            {
            case 1:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            case 2:
                printf("Falta ingresar el primer operando, por favor ingreselo: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            case 3:
                printf("Falta ingresar el segundo operando, por favor ingreselo: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            }
            resultadoSum = suma(valorA, valorB);
            printf("El resultado de la suma entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoSum);

            resultadoRes = resta(valorA, valorB);
            printf("El resultado de la resta entre %.2f y %.2f es: %.2f \n",valorA, valorB, resultadoRes);

            if(valorB == 0)
            {
                printf("No se puede dividir entre 0\n");
            }
            else
            {
                resultadoDiv = dividir(valorA, valorB);
                printf("El resultado de la division entre %.2f y %.2f es: %.2f\n",valorA, valorB, resultadoDiv);
            }

            resultadoMult = multiplicar(valorA, valorB);
            printf("El resultado de la multiplicacion entre %.2f y %.2f es : %.2f \n",valorA, valorB, resultadoMult);

            if (validacionFactorial(valorA)==1)
            {
                respuestaA = factorial(valorA);
                printf("El factorial de %.0f es: %d \n", valorA, respuestaA);
            }
            else
            {
                printf("Error, introduzca un valor entero mayor o igual a 0 \n");
                printf("El factorial solo se puede sacar con numeros enteros!\n");
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }
        do
        {
            printf("\n1- Ingresar 1er operando (A= %.2f)\n", valorA);
            printf("2- Ingresar 2do operando (B= %.2f)\n", valorB);
            printf("3- Calcular la suma (%.2f + %.2f)\n",valorA, valorB);
            printf("4- Calcular la resta (%.2f - %.2f)\n",valorA, valorB);
            printf("5- Calcular la division (%.2f / %.2f)\n",valorA, valorB);
            printf("6- Calcular la multiplicacion (%.2f * %.2f)\n",valorA, valorB);
            printf("7- Calcular el factorial (%.2f!)\n", valorA);
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");

            printf("\nIngrese una opcion: ");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                printf("Ingrese el nuevo valor para el primer operando: ");
                scanf("%f", &valorA);
                flagA = 1;
                break;
            case 2:
                printf("Ingrese el nuevo valor para el segundo operando: ");
                scanf("%f", &valorB);
                flagB = 1;
                break;
            case 9:
                seguir = 'n';
                break;
            }

        }
        while (opcion == 1 || opcion == 2);


    }
    while(seguir=='s');


    return 0;
}
