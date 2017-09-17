
void myFgets(char* buffer, int limite ,FILE* archivo);

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);

int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarString(char* buffer);

int val_getDNI(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarDni(char* buffer);

int val_getEdad(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);

