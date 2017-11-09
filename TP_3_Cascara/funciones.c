#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"

/** \brief Inicializa los campos del array
 *
 * \param array estructura recibida por referencia
 * \param longitud tamaño del array
 * \return 0 ok -1 error
 *
 */
int pelicula_initArray (sMovie* arrayMovie, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayMovie != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayMovie[i].estado = ESTADO_SIN_USO;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Genera un id autoincrementable
 *
 * \return id a utilizar
 *
 */
static int idAutoincrementable = -1;

int pelicula_generarProximoId (void)
{
    idAutoincrementable++;
    return idAutoincrementable;
}


/** \brief cargarPelicula realiza la carga de datos
 * \param arrayMovie array recibido por parametro
 * \param longitud del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo
 *
 */
int pelicula_cargarPelicula (sMovie* arrayMovie,int longitud)
{
    int retorno = -1;
    int i=0, indice;
    char bTitulo[20];
    char bGenero[10];
    char bDuracion[10];
    char bDescripcion[50];
    char bPuntaje[10];
    char bLink[50];
    int contadorIntentos =0;
    int flagTipo =0;

    if(arrayMovie != NULL && longitud > 0)
    {
        for(i=0; i<longitud; i++)
        {
            if(arrayMovie[i].estado == ESTADO_SIN_USO)
            {
                indice = i;
                break;
            }
        }
        if(val_getString(bTitulo,"\nIngrese el nombre de la pelicula: ","Error, solo ingrese letras: ",3,20)==0)
        {
            if(val_getAlfanumerico(bDescripcion, "\nIngrese la Descripcion: ", "\nError, no se pueden ingresar signos: ",3,50)== 0)
            {
                if(val_getUnsignedInt(bDuracion,"\nTiempo de la pelicula: ","Solo ingrese numeros",3,10)==0)
                {
                    if(val_getUnsignedInt(bPuntaje,"\nPuntaje de la pelicula: ", "Solo ingrese numeros",3,10)==0)
                    {
                        if(val_getAlfanumerico(bLink,"\nIngrese el link de la foto: ","Error",3,50)==0)
                        {
                            do
                            {
                                val_getUnsignedInt(bGenero,"\n1-Terror.\n2- Suspenso.\n3- Accion.\n4- Comedia. \n\nIngrese el genero: ","\nError, ingrese un numero dentro de las opciones ",3,10);
                                switch(atoi(bGenero))
                                {
                                case 1:
                                    arrayMovie[indice].genero = GENERO_TERROR;
                                    flagTipo = 1;
                                    break;
                                case 2:
                                    arrayMovie[indice].genero = GENERO_SUSPENSO;
                                    flagTipo = 1;
                                    break;
                                case 3:
                                    arrayMovie[indice].genero = GENERO_ACCION;
                                    flagTipo = 1;
                                    break;
                                case 4:
                                    arrayMovie[indice].genero = GENERO_COMEDIA;
                                    flagTipo = 1;
                                    break;
                                }
                                contadorIntentos ++;
                            }
                            while (flagTipo == 0 && contadorIntentos < 3);

                            if(flagTipo == 1)
                            {
                                strncpy(arrayMovie[indice].titulo,bTitulo,20);
                                strncpy(arrayMovie[indice].descripcion,bDescripcion,50);
                                arrayMovie[indice].duracion = atoi(bDuracion);
                                arrayMovie[indice].estado = ESTADO_USADO;
                                strncpy(arrayMovie[indice].linkImagen,bLink,50);
                                arrayMovie[indice].id = pelicula_generarProximoId();
                                arrayMovie[indice].puntaje = atoi(bPuntaje);
                                volcarArchivo(arrayMovie,longitud);
                                printf("id: %d",arrayMovie[indice].id);
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}


/** \brief recorre el array para modificar campos de la estructura
 *
 * \param array recibido por referencia
 * \param longitud del array
 * \return 0 ko o -1 error
 *
 */
int pelicula_modificarPelicula(sMovie* arrayMovie, int longitud, char* mensajeError)
{
    int retorno = -1;
    int indice;
    int idAux;
    char bTitulo[20];
    char bGenero[10];
    char bDuracion[10];
    char bDescripcion[50];
    char bPuntaje[10];
    char bLink[50];
    char buffer[10];
    int contadorIntentos =0;
    int flagTipo =0;

    if(arrayMovie != NULL && longitud > 0)
    {
        val_getUnsignedInt(buffer,"\n\nIngrese el ID a modificar: ", "Ingrese un numero",3,10);
        idAux = atoi(buffer);

        indice = pelicula_buscarIndicePorId(arrayMovie,longitud,idAux, "No se encontro el id");

        if(indice != -1)
        {
            if(val_getString(bTitulo,"\nIngrese el nombre de la pelicula: ","Error, solo ingrese letras: ",3,20)==0)
            {
                if(val_getAlfanumerico(bDescripcion, "\nIngrese la Descripcion: ", "\nError, no se pueden ingresar signos: ",3,50)== 0)
                {
                    if(val_getUnsignedInt(bDuracion,"Tiempo de la pelicula: ","Solo ingrese numeros",3,10)==0)
                    {
                        if(val_getUnsignedInt(bPuntaje,"Puntaje de la pelicula: ", "Solo ingrese numeros",3,10)==0)
                        {
                            if(val_getAlfanumerico(bLink,"Ingrese el link de la foto: ","Error",3,50)==0)
                            {
                                do
                                {
                                    val_getUnsignedInt(bGenero,"\n1-Terror.\n2- Suspenso.\n3- Accion.\n4- Comedia. \n\nIngrese el genero: ","\nError, ingrese un numero dentro de las opciones ",3,10);
                                    switch(atoi(bGenero))
                                    {
                                    case 1:
                                        arrayMovie[indice].genero = GENERO_TERROR;
                                        flagTipo = 1;
                                        break;
                                    case 2:
                                        arrayMovie[indice].genero = GENERO_SUSPENSO;
                                        flagTipo = 1;
                                        break;
                                    case 3:
                                        arrayMovie[indice].genero = GENERO_ACCION;
                                        flagTipo = 1;
                                        break;
                                    case 4:
                                        arrayMovie[indice].genero = GENERO_COMEDIA;
                                        flagTipo = 1;
                                        break;
                                    }
                                    contadorIntentos ++;
                                }
                                while (flagTipo == 0 && contadorIntentos < 3);

                                if(flagTipo == 1)
                                {
                                    strncpy(arrayMovie[indice].titulo,bTitulo,20);
                                    strncpy(arrayMovie[indice].descripcion,bDescripcion,50);
                                    arrayMovie[indice].duracion = atoi(bDuracion);
                                    strncpy(arrayMovie[indice].linkImagen,bLink,50);
                                    arrayMovie[indice].puntaje = atoi(bPuntaje);
                                    volcarArchivo(arrayMovie,longitud);
                                    retorno = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief recorre el array buscando un indice utilizando un id
 *
 * \param arrayMovie estructura recibida por referencia
 * \param longitud tamaño del array
 * \param id recibido por parametro para ser comparado al recorrer el array
 * \param mensaje para el usuario
 * \return 0 ok o -1 error
 *
 */
int pelicula_buscarIndicePorId (sMovie* arrayMovie, int longitud, int id, char* mensaje)
{
    int retorno = -1;
    int i;

    if(arrayMovie != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayMovie[i].estado == ESTADO_USADO)
            {
                if(id == arrayMovie[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
        if(retorno == -1)
        {
            printf("%s", mensaje);
        }
    }
    return retorno;
}



/** \brief recorre el array para hacer una baja logica
 *
 * \param arrayMovie recibido por referencia
 * \param longitud del array
 * \return 0 ko o -1 error
 *
 */
int pelicula_darDeBajaPelicula(sMovie* arrayMovie, int longitud, char* mensajeError)
{
    int retorno = -1;
    int idAux;
    char buffer[10];
    int indice;

    if(arrayMovie != NULL && longitud > 0)
    {
        val_getUnsignedInt(buffer,"\n\nIngrese el ID para dar de baja: ", "\n\nEl ID no se encontro",3,10);
        idAux = atoi(buffer);

        indice = pelicula_buscarIndicePorId(arrayMovie,longitud,idAux, "\n\nNo se encontro el id");

        if(indice != -1)
        {
            arrayMovie[indice].estado = ESTADO_SIN_USO;
            volcarArchivo(arrayMovie,longitud);
            retorno = 0;
        }
        if(retorno == -1)
        {
            printf("%s",mensajeError);
        }
    }
    return retorno;
}


/** \brief genera un archivo html
 *
 * \param arrayMovie array de la estructura recibida por referencia
 * \param longitud del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo
 *
 */
int generarArchivo (sMovie* arrayMovie, int longitud)
{
    FILE *pMovie;
    FILE *pCabecera;
    FILE *pContenido;
    char cabecera[1200];
    char contenido[2000];
    int i;

    pMovie = fopen("index.html","w");

    if(pMovie != NULL)
    {
        pCabecera = fopen("cabecera", "r");
        fscanf(pCabecera,"%s",cabecera);
        fclose(pCabecera);
        fprintf(pMovie,"%s",cabecera);

        pContenido = fopen("codigoPorPelicula", "r");
        fread(contenido,sizeof(char),2000,pContenido);
        fclose(pContenido);

        for(i=0; i<longitud; i++)
        {
            if(arrayMovie[i].estado == ESTADO_USADO)
            {
                fprintf(pMovie,contenido,(arrayMovie + i)->linkImagen,(arrayMovie + i)->titulo,(arrayMovie + i)->duracion,
                        (arrayMovie + i)->puntaje,(arrayMovie + i)->genero,(arrayMovie + i)->descripcion);
            }
        }
    }
    fclose(pMovie);
    return 0;
}


/** \brief escribe un archivo de datos
 *
 * \param arrayMovie array de la estructura recibida por referencia
 * \param longitud del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo
 *
 */
int volcarArchivo(sMovie* arrayMovie, int longitud)
{
    FILE *pMovie;
    int cantEscrita;

    pMovie = fopen("Datos.dat", "w");

    if(pMovie == NULL)
    {
        printf("No se pudo abrir el archivo");
    }
    else
    {
        cantEscrita = fwrite(arrayMovie,sizeof(sMovie),longitud,pMovie);
        if(cantEscrita<1)
        {
            printf("Error, en la escritura");
        }
    }
    fclose(pMovie);
    return 0;
}

/** \brief lee un archivo de datos
 *
 * \param arrayMovie array de la estructura recibida por referencia
 * \param longitud del array
 * \return 0 si se realizo la carga correctamente o -1 si no se pudo
 *
 */
int levantarArchivo (sMovie* arrayMovie, int longitud)
{
    FILE *pMovie;
    int cantLeida;

    pMovie = fopen("Datos.dat", "r");

    if(pMovie == NULL)
    {
        printf("El archivo no tiene informacion");
    }
    cantLeida = fread(arrayMovie,sizeof(sMovie),longitud,pMovie);
    if(cantLeida!=1)
    {
        printf("Error en la lectura");
    }
    fclose(pMovie);
    return 0;
}
