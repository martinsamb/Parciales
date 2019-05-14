#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED

#define TEXT_SIZE 31

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char name[TEXT_SIZE];
    char phone[16];
    char mail[31];
    char sexo;
    char lastName[TEXT_SIZE];

}Socios;


#endif // SOCIOS_H_INCLUDED

int socios_Inicializar(Socios array[], int size);                                    //cambiar socioss
int socios_buscarEmpty(Socios array[], int size, int* posicion);                    //cambiar socioss
int socios_buscarID(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socioss
int socios_buscarInt(Socios array[], int size, int valorBuscado, int* posicion);                    //cambiar socioss
int socios_buscarString(Socios array[], int size, char* valorBuscado, int* indice);                    //cambiar socioss
int socios_alta(Socios array[], int size, int* contadorID);                          //cambiar socioss
int socios_baja(Socios array[], int sizeArray);                                      //cambiar socioss
int socios_bajaValorRepetidoInt(Socios array[], int sizeArray, int valorBuscado);
int socios_modificar(Socios array[], int sizeArray);                                //cambiar socioss
int socios_ordenarPorDobleCriterio(Socios array[],int size, int orderFirst, int orderSecond);                                  //cambiar socioss
int socios_listar(Socios array[], int size);                      //cambiar socioss


