#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float valorA=0, valorB=0;
    int flagA = 0, flagB = 0;
    int resultFactorial;
    float resultSuma, resultResta,resultDivision, resultMultiplicacion;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando (A= %.2f)\n", valorA);
        printf("2- Ingresar 2do operando (B= %.2f)\n", valorB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");

        pedirOpcion("Ingrese una opcion del menu: ", "Error, el numero tiene que estar en el menu, reingrese: ", &opcion);

        system("cls");
        switch(opcion)
        {
        case 1:
            pedirDatos("\nIngrese el 1\247 valor: ",&valorA);
            flagA = 1;
            break;
        case 2:
            pedirDatos("\nIngrese el 2\247 valor: ", &valorB);
            flagB = 1;
            break;
        case 3:
            if(validarFlag(&flagA,&flagB,"\nFalta ingresar el 1\247 valor, opcion 1\n\n","\nFalta ingresar el 2\247 valor, opcion 2\n\n")==0)
            {
                opSuma(&valorA, &valorB, &resultSuma);
                printf("\nEl resultado de la suma es: %.2f\n\n", resultSuma);
            }
            break;
        case 4:
            if(validarFlag(&flagA,&flagB,"\nFalta ingresar el 1\247 valor, opcion 1\n\n","\nFalta ingresar el 2\247 valor, opcion 2\n\n")==0)
            {
                opResta(&valorA, &valorB, &resultResta);
                printf("\nEl resultado de la resta es: %.2f\n\n", resultResta);
            }
            break;
        case 5:
            if(validarFlag(&flagA,&flagB,"\nFalta ingresar el 1\247 valor, opcion 1\n\n","\nFalta ingresar el 2\247 valor, opcion 2\n\n")==0)
            {
                opDivision(&valorA, &valorB, &resultDivision,"\nError, no se puede dividir por CERO!!\n\n");
                printf("\nEl resultado de la division es: %.2f\n\n", resultDivision);
            }
            break;
        case 6:
            if(validarFlag(&flagA,&flagB,"\nFalta ingresar el 1\247 valor, opcion 1\n\n","\nFalta ingresar el 2\247 valor, opcion 2\n\n")==0)
            {
                opMultiplicacion(&valorA, &valorB, &resultMultiplicacion);
                printf("\nEl resultado de la multiplicacion es: %.2f\n\n", resultMultiplicacion);
            }
            break;
        case 7:
            if(validarFactorial(&valorA,&flagA,"\nFalta ingresar el 1\247 valor, opcion 1\n\n","\nError, debe ingresar un numero ENTERO mayor o igual a CERO!!\n\n")==0)
            {
                opFactorial(&valorA, &resultFactorial);
                printf("\nEl factorial de %.0f es: %d\n\n", valorA, resultFactorial);
            }
            break;
        case 8:
            if(validarFlag(&flagA,&flagB,"\nFalta ingresar el 1\247 valor, opcion 1\n\n","\nFalta ingresar el 2\247 valor, opcion 2\n\n")==0)
            {
                opSuma(&valorA, &valorB, &resultSuma);
                opResta(&valorA, &valorB, &resultResta);
                opMultiplicacion(&valorA, &valorB, &resultMultiplicacion);
                printf("\nEl resultado de la suma es: %.2f", resultSuma);
                printf("\nEl resultado de la resta es: %.2f", resultResta);
                printf("\nEl resultado de la multiplicacion es: %.2f", resultMultiplicacion);
                if(valorB == 0)
                {
                    printf("\nError, no se puede dividir por CERO!!");
                }
                else
                {
                    opDivision(&valorA, &valorB, &resultDivision,"\nError, no se puede dividir por CERO!!\n\n");;
                    printf("\nEl resultado de la division es: %.2f", resultDivision);
                }
                if(validarFactorial(&valorA,&flagA,"\nFalta ingresar el 1\247 valor, opcion 1\n\n","\nError, debe ingresar un numero ENTERO mayor o igual a CERO!!\n\n")==0)
                {
                    opFactorial(&valorA, &resultFactorial);
                    printf("\nEl factorial de %.0f es: %d\n", valorA, resultFactorial);
                }
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }
    }
    return 0;

}
