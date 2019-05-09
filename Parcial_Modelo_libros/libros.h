#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char varString[TEXT_SIZE];
    int varInt;
    float varFloat;
    char varChar;
    char varLongString[TEXT_SIZE];

}Libro;


#endif // LIBROS_H_INCLUDED

int libro_Inicializar(Libro array[], int size);                                    //cambiar libro
int libro_buscarEmpty(Libro array[], int size, int* posicion);                    //cambiar libro
int libro_buscarID(Libro array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarInt(Libro array[], int size, int valorBuscado, int* posicion);                    //cambiar libro
int libro_buscarString(Libro array[], int size, char* valorBuscado, int* indice);                    //cambiar libro
int libro_alta(Libro array[], int size, int* contadorID);                          //cambiar libro
int libro_baja(Libro array[], int sizeArray);                                      //cambiar libro
int libro_bajaValorRepetidoInt(Libro array[], int sizeArray, int valorBuscado);
int libro_modificar(Libro array[], int sizeArray);                                //cambiar libro
int libro_ordenarPorDobleCriterio(Libro array[],int size, int orderFirst, int orderSecond);                                  //cambiar libro
int libro_listar(Libro array[], int size);                      //cambiar libro
void libro_mock(Libro arrayLibro[], int size,int *contadorId);                      //cambiar libro
