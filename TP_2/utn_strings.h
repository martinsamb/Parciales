#ifndef UTN_STRINGS_H_INCLUDED
#define UTN_STRINGS_H_INCLUDED

int getName(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getString(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getInt(char* msg, char* msgError, int minimo, int maximo, int reintentos, int* resultado);
int getEdad(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getDireccion(char* msg, char* msgError, int minimo, int maximo, int reintentos, char* resultado);
int getCuil(char* msg, char* msgError,int reintentos, char* resultado);


#endif // UTN_STRINGS_H_INCLUDED
