


typedef struct
{

    char nombre[50];
    int edad;
    int estado;
    int dni;

} EPersona;

int buscarPosicion(EPersona persona[], int cantidad, int valor);
int buscarPorDni(EPersona persona[], int dni,int cantidad);
int getInt(char mensaje[]);
void getString(char mensaje[], char auxiliar[]);
int getStringLetras(char mensaje[], char auxiliar[]);
int Letras(char str[]);
int getStringDni(char mensaje[], char auxiliar[]);
int Numerico(char str[]);
int cargarEdad(char mensaje[]);
void ordenarPorNombre(EPersona persona[],int cantidad);
void iniciarEstado(EPersona persona[],int cantidad,int valor);
void imprimirGraficoEdades(EPersona persona[],int cantidad);


//#endif
