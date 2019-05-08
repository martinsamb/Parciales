#ifndef UTN_STRINGS_H_INCLUDED
#define UTN_STRINGS_H_INCLUDED

int getInt(char *mensaje, char *mensajeError,long minimo, long maximo,int reintentos, int *resultado);
int isValidInt(int numero, int maximo, int minimo);
int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);
int isValidAlphaNum(char *sAlphaNum);
int getStringD(char *pResult, char *pMsg, char *pMsgError,int minimo, int maximo, int intentos);
int getStringf(float *pResult,char *pMsg, char *pMsgError,int minimo, int maximo, int intentos);
int getString(char *pResult, char *pMsg, char *PMsgError, int minimo, int maximo, int intentos);
int isValidChar(char letra, char maximo, char minimo);
int validLetter(char letras[]);



#endif // UTN_STRINGS_H_INCLUDED
