#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#endif // FUNCIONES_H_INCLUDED

int pedirOpcion (char mensaje[], char msjError[], int* opcion);
int pedirDatos (char mensaje[], float* valor);
int opSuma (float* numA, float* numB, float* resultado);
int opResta (float* numA, float* numB, float* resultado);
int opDivision (float* numA, float* numB, float* resultado, char mensaje[]);
int opMultiplicacion (float* numA, float* numB, float* resultado);
int opFactorial (float* numA, int* resultFactorial);
