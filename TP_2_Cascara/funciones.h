#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    char dni[10];

}EPersona;


#endif // FUNCIONES_H_INCLUDED

#define ESTADO_LIBRE 0
#define ESTADO_OCUPADO 1


int persona_initArray (EPersona* arrayPersona, int longitud);
int persona_obtenerEspacioLibre (EPersona* arrayPersona, int longitud);
int persona_cargarPersona (EPersona* arrayPersona,int longitud);
int persona_borrarPersona (EPersona* arrayPersona, int longitud);
void persona_ordenarPorNombre(EPersona* arrayPersona,int longitud);
void imprimirGraficoEdades(EPersona* arrayPersona,int longitud);
