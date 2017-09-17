#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"

#define MAX_INPUT_BUFFER 4096


/** Recibe una string y coloca en la ultima posicion un '\0'
 *
 * \param buffer es el string que recibe
 * \param limite el tamaño del string
 * \param archivo
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

/** recibe un string y valida que no sea NULL, que no sobrepase el tamaño maximo, que este dentro
 *  de las condiciones que se le pide al usuario
 * \param destino es el string recibido por parametro
 * \param mensaje pidiendo el dato al usuario
 * \param mensajeError si lo que ingreso no cumple con las condiciones necesarias.
 * \param intentos, cantidad de intentos para que vuelva a ingresar el dato
 * \param limite, tamaño maximo del string
 * \return 0 si se logro ingresar el dato o -1 si no se pudo
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

/** recibe un string y valida que no sea NULL, que no sobrepase el tamaño maximo, que este dentro
 *  de las condiciones que se le pide al usuario
 * \param destino es el string recibido por parametro
 * \param mensaje pidiendo el dato al usuario
 * \param mensajeError si lo que ingreso no cumple con las condiciones necesarias.
 * \param intentos, cantidad de intentos para que vuelva a ingresar el dato
 * \param limite, tamaño maximo del string
 * \return 0 si se logro ingresar el dato o -1 si no se pudo
 */
int val_getDNI(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(destino, limite,stdin);

            if(val_validarDni(destino) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** recibe un string y valida que cumpla con los requisitos para ser un DNI
 * \param buffer es el string recibido
 * \return 0 si se logro ingresar el dato o -1 si no se pudo
 */
int val_validarDni(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.')
        {
            retorno = -1;
            break;
        }
        else
        {
            if((buffer[i] == '.' && i == 2 ) || (buffer[i] == '.' && i == 6))
            {
                flagPunto++;
            }
        }
        i++;
    }
    if(flagPunto != 2)
    {
        retorno = -1;
    }
    return retorno;
}


/** recibe un string y valida que solo se ingresen letras o un ' '
 * \param buffer es el string recibido
 * \return 0 si se logro ingresar el dato o -1 si no se pudo
 */
int val_validarString(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] > ' '))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}



/** recibe un string y valida que no sea NULL, que no sobrepase el tamaño maximo, que este dentro
 *  de las condiciones que se le pide al usuario
 * \param destino es el string recibido por parametro
 * \param mensaje pidiendo el dato al usuario
 * \param mensajeError si lo que ingreso no cumple con las condiciones necesarias.
 * \param intentos, cantidad de intentos para que vuelva a ingresar el dato
 * \param limite, tamaño maximo del string
 * \return 0 si se logro ingresar el dato o -1 si no se pudo
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



/** recibe un string y valida que solo se ingresen numeros
 * \param buffer es el string recibido
 * \return 0 si se logro ingresar el dato o -1 si no se pudo
 */
int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


/** recibe un string y valida que no sea NULL, que no sobrepase el tamaño maximo, que este dentro
 *  una edad valida
 * \param destino es el string recibido por parametro
 * \param mensaje pidiendo el dato al usuario
 * \param mensajeError si lo que ingreso no cumple con las condiciones necesarias.
 * \param intentos, cantidad de intentos para que vuelva a ingresar el dato
 * \param limite, tamaño maximo del string
 * \return 0 si se logro ingresar el dato o -1 si no se pudo
 */
int val_getEdad(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = 0;

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos>0; intentos--)
        {

            myFgets(destino,limite,stdin);

            if(val_validarUnsignedInt(destino) == -1)
            {
                printf(mensajeError);
                retorno = -1;
                continue;
            }
            if(atoi(destino) < 0 || atoi(destino) > 110)
            {
                printf(mensajeError);
                retorno = -1;
                continue;
            }
            break;
        }
    }
    return retorno;
}


