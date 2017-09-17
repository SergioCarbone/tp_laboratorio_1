#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validar.h"

#define CANTIDAD 20


int main()
{
    EPersona arrayPersona[CANTIDAD];
    persona_initArray(arrayPersona,CANTIDAD);

    char seguir='s';
    char opcion[10];

    while(seguir=='s')
    {
        val_getUnsignedInt(opcion,"\n\n1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n4- Imprimir grafico de edades\n5- Salir\n\nIngrese una de las opciones: ","Error, Tiene que elegir entre las opciones del menu",3,10);

        switch(atoi(opcion))
        {
            case 1:
                persona_cargarPersona(arrayPersona,CANTIDAD);
                break;
            case 2:
                persona_borrarPersona(arrayPersona,CANTIDAD);
                break;
            case 3:
                persona_ordenarPorInsercion(arrayPersona,CANTIDAD);
                break;
            case 4:
                imprimirGraficoEdades(arrayPersona,CANTIDAD);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
