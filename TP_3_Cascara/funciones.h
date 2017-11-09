#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    unsigned char genero;
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    unsigned char estado;
    int id;
}sMovie;

#endif // FUNCIONES_H_INCLUDED

#define ESTADO_SIN_USO 0
#define ESTADO_USADO 1

#define GENERO_TERROR 0
#define GENERO_SUSPENSO 1
#define GENERO_ACCION 2
#define GENERO_COMEDIA 3


int pelicula_initArray (sMovie* arrayMovie, int longitud);
int pelicula_generarProximoId (void);
int pelicula_cargarPelicula (sMovie* arrayMovie,int longitud);
int pelicula_modificarPelicula(sMovie* arrayMovie, int longitud, char* mensajeError);
int pelicula_buscarIndicePorId (sMovie* arrayMovie, int longitud, int id, char* mensaje);
int pelicula_darDeBajaPelicula(sMovie* arrayMovie, int longitud, char* mensajeError);
int generarArchivo (sMovie *pMovie, int longitud);
int volcarArchivo(sMovie* arrayMovie, int longitud);
int levantarArchivo (sMovie* arrayMovie, int longitud);
