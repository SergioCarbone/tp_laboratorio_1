#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

#define MAX 20

int main()
{
    EPersona persona[MAX];

    char nombreAux[20];
    char dniAux[10];
    int edad;
    int dniInt;
    char seguir='s';
    int opcion;
    int lugarLibre;
    int resultadoBusqueda;

    iniciarEstado(persona,MAX,0);

    do
    {

        printf("\n\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        opcion = getInt("Ingrese una opcion: ");
        if(opcion <1 || opcion >5)
        {
            printf("Ingrese una opcion del menu!!\n\n");
        }

        switch(opcion)
        {
        case 1:
            lugarLibre = buscarPosicion(persona,MAX,0);
            if(lugarLibre==-1)
            {
                printf("error");
                break;
            }
            if(!getStringLetras("\nIngrese el Nombre: ",nombreAux))
            {
                printf("Solo puede ingresar letras!\n");
                break;
            }
            if(!getStringDni("Ingrese el DNI: ",dniAux))
            {
                printf("Solo puede ingresar 8 numeros!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorDni(persona, atoi(dniAux),MAX);
            if(resultadoBusqueda != -1)
            {
                printf("El dni ya existe!!\n\n");
                break;
            }

            edad = cargarEdad("Ingrese la edad: ");
            if(edad == -1)
            {
                printf("Ingrese una edad entre 0 y 100\n\n");
                break;
            }
            dniInt = atoi(dniAux);
            persona[lugarLibre].estado = 1;

            strcpy(persona[lugarLibre].nombre,nombreAux);
            persona[lugarLibre].dni = dniInt;
            persona[lugarLibre].edad = edad;
            break;

        case 2:
            if(!getStringDni("Ingrese el DNI: ",dniAux))
            {
                printf("Solo puede ingresar numeros!\n\n");
                break;
            }
            resultadoBusqueda = buscarPorDni(persona, atoi(dniAux),MAX);
            if(resultadoBusqueda == -1)
            {
                printf("El dni no existe!!\n\n");
                break;
            }
            persona[resultadoBusqueda].estado = 0;
            break;

        case 3:
            ordenarPorNombre(persona,MAX);
            break;

        case 4:
            imprimirGraficoEdades(persona,MAX);
            break;

        case 5:
            seguir = 'n';
            break;
        }
    }while(seguir=='s');
    return 0;
}














