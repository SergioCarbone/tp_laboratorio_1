#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"


/**
 * Solicita la carga de datos
 * \param arrayPersona es el array pasado por parametro
 * @param longitud es la cantidad de posiciones que tiene el array
 * \return 0 si se logro hacer la validacion o -1 si no se pudo
 */
int persona_cargarPersona (EPersona* arrayPersona,int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bDni[10];
    char bEdad[4];
    int idAux;

    if(arrayPersona != NULL && longitud >= 0)
    {
        idAux = persona_obtenerEspacioLibre(arrayPersona,longitud);
        if(idAux != -1)
        {
            if(val_getString(bNombre,"\nIngrese el nombre: ","\nError, solo puede ingresar letras\n",3,51)==0)
            {
                if(val_getDNI(bDni,"\nIngrese el DNI: ","\nError, solo puede ingresar con este formato XX.XXX.XXX: ",2,10)== 0)
                {
                    if(val_getEdad(bEdad,"\nIngrese la edad: ","\nError, Ingrese una edad correcta: ",2,4)== 0)
                    {
                        strncpy(arrayPersona[idAux].nombre,bNombre,51);
                        strncpy(arrayPersona[idAux].dni,bDni,10);
                        arrayPersona[idAux].edad = atoi(bEdad);
                        arrayPersona[idAux].estado = ESTADO_OCUPADO;
                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}


/**
 * Inicia a todos los elementos del array colocando un 0 (libre) en el estado
 * \param array que va a ser inicializado
 * \param longitud es la cantidad de posiciones que tiene el array
 * \return 0 si se logro hacer la validacion o -1 si no se pudo
 *
 */
int persona_initArray (EPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPersona[i].estado = ESTADO_LIBRE;
        }
        retorno = 0;

    }
    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param arayPersona el array se pasa como parametro.
 * @param longitud es la cantidad de posiciones que tiene el array
 * @return el primer indice disponible
 */
int persona_obtenerEspacioLibre (EPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int i;
    int idMax = -1;

    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersona[i].estado == ESTADO_LIBRE)
            {
                if(idMax < i)
                {
                    idMax = i;
                    break;
                }
            }
        }
        retorno = idMax;
    }
    return retorno;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param longitud es la cantidad de posiciones que tiene el array
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int persona_borrarPersona (EPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    char bDni[10];
    int i;

    if(val_getDNI(bDni,"\nIngrese el DNI para dar de baja: ","\nError, solo puede ingresar con este formato XX.XXX.XXX: ",2,10)==0)
    {
        for(i=0; i<longitud; i++)
        {
            if(strncmp(arrayPersona[i].dni,bDni,10)==0)
            {
                arrayPersona[i].estado = ESTADO_LIBRE;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * Ordena el array por nombre
 * \param array pasado por parametro
 * @param longitud es la cantidad de posiciones que tiene el array
 * \return 0 si se logro hacer alguna modificacion o -1 si no se pudo
 *
 */
int persona_ordenarPorInsercion (EPersona* arrayPersona,int longitud)
{
    int i,j;
    int retorno = -1;
    char auxNombre[51];
    char auxDni[10];
    int auxEdad;

    for(i=1; i<longitud; i++)
    {
        if(arrayPersona[i].estado == ESTADO_OCUPADO)
        {
            strncpy(auxNombre,arrayPersona[i].nombre,51);
            strncpy(auxDni,arrayPersona[i].dni,10);
            auxEdad = arrayPersona[i].edad;
            j=i-1;

            if((strcmp(auxNombre,arrayPersona[j].nombre)<0) && j>=0)
            {
                strcpy(arrayPersona[j+1].nombre,arrayPersona[j].nombre);
                strcpy(arrayPersona[j+1].dni,arrayPersona[j].dni);
                arrayPersona[j+1].edad = arrayPersona[j].edad;
                j--;
            }
            strcpy(arrayPersona[j+1].nombre,auxNombre);
            strcpy(arrayPersona[j+1].dni,auxDni);
            arrayPersona[j+1].edad = auxEdad;
            retorno = 0;
        }
    }

    for(i=0; i<longitud ; i++)
    {
        if(arrayPersona[i].estado == ESTADO_OCUPADO)
        {

            printf("\n%d\t%s\t\t%d\t\t%s",i,arrayPersona[i].nombre,arrayPersona[i].edad,arrayPersona[i].dni);
        }
    }
    return retorno;
}



void imprimirGraficoEdades(EPersona* arrayPersona,int longitud)
{
    int contMenos18 = 0;
    int contEntre18_35 = 0;
    int contMas35 = 0;
    int i,listaA,listaB,listaC;
    char menos18[] = "Menos de 18";
    char entre18y35[] = "Entre 18 y 35";
    char mayores35[] = "Mayores de 35";

    for(i=0; i<longitud; i++)
    {
        if(arrayPersona[i].estado == 1)
        {
            if(arrayPersona[i].edad < 18)
            {
                contMenos18++;
            }
            else if(arrayPersona[i].edad <35)
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


    for( ; i>0; i--)
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
