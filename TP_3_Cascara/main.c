#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validar.h"
#define CANTIDAD_PELICULAS 10
int main()
{
    sMovie listaPeliculas[CANTIDAD_PELICULAS];
    pelicula_initArray(listaPeliculas,CANTIDAD_PELICULAS);
    levantarArchivo(listaPeliculas,CANTIDAD_PELICULAS);
    char seguir='s';
    char opcion[10];

    do
    {
        val_getUnsignedInt(opcion,"\n\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar pelicula\n4- Generar pagina web\n5- Salir\n\nIngrese una opcion: ",
                           "Ingrese un numero",3,10);
        switch(atoi(opcion))
        {
        case 1:
            pelicula_cargarPelicula(listaPeliculas,CANTIDAD_PELICULAS);
            break;
        case 2:
            pelicula_darDeBajaPelicula(listaPeliculas,CANTIDAD_PELICULAS,"Error");
            break;
        case 3:
            pelicula_modificarPelicula(listaPeliculas,CANTIDAD_PELICULAS,"Error");
            break;
        case 4:
            generarArchivo (listaPeliculas,CANTIDAD_PELICULAS);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\n\nTiene que ingresar un numero que se encuentre en el menu");
            break;
        }
    }
    while(seguir == 's');
    return 0;
}
