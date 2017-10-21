#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"

#define MAX_INPUT_BUFFER 4096

/** \brief recibe un buffer y en la ultima posicion coloca un \0
 *
 * \param buffer donde se carga el string
 * \param limite tamaño del string
 *
 */
void myFgets(char* buffer, int limite,FILE* archivo)
{
    int i=0;
    fflush(archivo);
    fgets(buffer, limite,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

/** \brief Valida que solo se ingresen letras
 *
 * \param destino donde se guarda el string
 * \param mensaje para el usuario
 * \param mensajeError para el usuario
 * \param intentos cantidad de intentos si no cumple con la validacion
 * \param limite tamaño del string
 * \return 0 ok -1 error
 *
 */
int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarString(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief valida que solo se ingresen letras
 *
 * \param buffer donde se guarda es string
 * \return 0 ok y -1 error
 */
int val_validarString(char* buffer)
{
    int i=0;
    int retorno = 0;

    if (buffer[i] == '\0')
        retorno = -1;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && buffer[i] != ' ' )
        {
            retorno = -1;
            break;
        }
        i++;
    }

    return retorno;
}



/** \brief Valida que solo se ingresen numeros enteros
 *
 * \param destino donde se guarda el string
 * \param mensaje para el usuario
 * \param mensajeError para el usuario
 * \param intentos cantidad de intentos si no cumple con la validacion
 * \param limite tamaño del string
 * \return 0 ok -1 error
 *
 */
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}



/** \brief valida que solo se ingresen numeros
 *
 * \param buffer donde se guarda es string
 * \return 0 ok y -1 error
 */
int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}


/** \brief Toma un string ingresado por el usuario
 *
 * \param destino donde se guarda el string
 * \param mensaje para el usuario
 * \param mensajeError para el usuario
 * \param intentos cantidad de intentos si no cumple con la validacion
 * \param limite tamaño del string
 * \return 0 ok -1 error
 *
 */
int val_getAlfanumerico(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(buffer, limite,stdin);

            if(val_validarAlfanumerico(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief valida que solo se ingresen numeros, letras o signos
 *
 * \param buffer donde se guarda es string
 * \return 0 ok y -1 error
 */
int val_validarAlfanumerico(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') &&
            (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != ' '))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


