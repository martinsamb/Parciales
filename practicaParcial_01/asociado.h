#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    char nombre[20];
    char apellido[20];
    int isEmpty;//Activo = 0, Vacio = 1
    int idAsociado;//Autoincremental
    int edad;
    int dni;

}Asociado;

int aso_init(Asociado *arrayAsociado, int cantidad);
int aso_findFree(Asociado *arrayAsociado, int cantidad, int *devuelve);
int aso_addAso(Asociado *arrayAsociado, int cantidad, int posicionLibre, int id);
int getInt(char *mensaje, char *mensajeError,long minimo, long maximo,int reintentos, int *resultado);
int isValidInt(int numero, int maximo, int minimo);
int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);
int isValidAlphaNum(char *sAlphaNum);
int getStringD(char *pResult, char *pMsg, char *pMsgError,int minimo, int maximo, int intentos);
int getStringf(float *pResult,char *pMsg, char *pMsgError,int minimo, int maximo, int intentos);
int aso_findArrayForId(Asociado *arrayAsociado, int cantidad,int *asociadoEncontrado, char *textoAMostrar);
int aso_removeAso(Asociado *arrayAsociado,int cantidad);
int aso_alterAso(Asociado *arrayAsociado, int cantidad);
int getString(char *pResult, char *pMsg, char *PMsgError, int minimo, int maximo, int intentos);
int isValidChar(char letra, char maximo, char minimo);
int validLetter(char letras[]);
void aso_showArray(Asociado *arrayAsociado, int cantidad);


#endif // ASOCIADO_H_INCLUDED
