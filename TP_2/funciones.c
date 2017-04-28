#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int buscarPosicion(EPersona persona[], int cantidad, int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if (persona[i].estado == valor)
        {
            return i;
        }
    }
    return -1;
}
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona persona[], int dni,int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(persona[i].dni == dni)
        {
            return i;
        }
    }
    return -1;
}
// FUNCIONES_H_INCLUDED

/**
* Devuelve el valor ingresado
* @param mensaje que tiene que imprimir
* @return valor ingresado por el usuario
*/
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

void getString(char mensaje[], char auxiliar[])
{
    printf(mensaje);
    scanf("%s", auxiliar);
}
/**
* Controla que solo se hayan ingresado letras
* @param mensaje para imprimir
* @param auxiliar texto que debe validar
* @return retorna 1 si se cumple la condicion o 0 si no
*/
int getStringLetras(char mensaje[], char auxiliar[])
{
    char aux[20];
    getString(mensaje,aux);
    if(Letras(aux))
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}
/***************
* Compara caracter por caracter
* @param char a comparar
* @return si se cumple o no la condicion
*/
int Letras(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
/***************
* Controla que solo se hayan ingresado numeros
* @param mensaje para imprimir
* @param auxiliar texto que debe validar
* @return retorna 1 si se cumple la condicion o 0 si no
*/
int getStringDni(char mensaje[], char auxiliar[])
{
    char aux[10];
    getString(mensaje, aux);
    if(Numerico(aux)&& strlen(aux)== 8)
    {
        strcpy(auxiliar, aux);
        return 1;
    }
    return 0;
}
/***************
* Compara caracter por caracter
* @param char a comparar
* @return si se cumple o no la condicion
*/
int Numerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/***************
* Controla que se ingrese una edad dentro de los parametros
* @param mensaje imprime el mensaje por consola
* @return -1 si esta fuera del parametro o la edad si se cumple o no la condicion
*/
int cargarEdad(char mensaje[])
{
    int edad;
    printf("%s",mensaje);
    scanf("%d", &edad);
    if (edad < 0 || edad > 100)
    {
        return -1;
    }
    return edad;
}

/***************
* Ordena el array por nombres
* @param persona recibe el array de persona
* @param cantidad recibe la cantidad de personas
*/
void ordenarPorNombre(EPersona persona[],int cantidad)
{

    int i,j;
    EPersona nombre;


    for(i=0; i< cantidad; i++)
    {
        for(j=i+1; j<cantidad; j++)
        {
            if(stricmp(persona[i].nombre,persona[j].nombre)>0)
            {
                nombre = persona[i];
                persona[i] = persona[j];
                persona[j] = nombre;

            }
        }
    }
    printf("\n\nNombre\tdni\tEdad\n");
    for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado == 1)
        {
            printf("%s   %d   %d\n",persona[i].nombre,persona[i].dni,persona[i].edad);
        }
    }
}



/***************
* Inicia el estado de cada una de las personas del array
* @param persona recibe el array de persona
* @param cantidad recibe la cantidad de posiciones
* @param valor indica que valor va a recibir cada estado
*/
void iniciarEstado(EPersona persona[],int cantidad,int valor)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        persona[i].estado=valor;
    }
}
/***************
* Imprime tres columnas con las cantidades de personas en cada una de ellas
* @param persona recibe el array de persona
* @param cantidad recibe la cantidad de posiciones
*/

void imprimirGraficoEdades(EPersona persona[],int cantidad)
{
    int contMenos18 = 0;
    int contEntre18_35 = 0;
    int contMas35 = 0;
    int i,listaA,listaB,listaC;
    char menos18[] = "Menos de 18";
    char entre18y35[] = "Entre 18 y 35";
    char mayores35[] = "Mayores de 35";

    for(i=0; i<cantidad; i++)
    {
        if(persona[i].estado == 1)
        {
            if(persona[i].edad < 18)
            {
                contMenos18++;
            }
            else if(persona[i].edad <35)
            {
                contEntre18_35++;
            }
            else
            {
                contMas35++;
            }
        }

    }
        listaA= contMenos18;
        listaB = contEntre18_35;
        listaC = contMas35;


    for(i=cantidad; i>0; i--)
    {

            if(i==listaA)
            {
                printf("\n  *\t\t");
                listaA--;
            }
            else
            {
                printf(" \t\t");
            }

            if(i==listaB)
            {
                printf("  *\t\t");
                listaB--;
            }
            else
            {
                printf(" \t\t");
            }
            if(i==listaC)
            {
                printf("  *\t\t");
                listaC--;
            }
            else
            {
                printf(" \t\n");
            }
    }
        printf("\n%s\t%s\t%s\n",menos18,entre18y35,mayores35);
}

