#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int idLibro;
    int idSocio;

}Prestamo;


#endif //PRETAMOS_H_INCLUDED

int socio_Inicializar(Prestamo array[], int size);                                    //cambiar socio
int socio_buscarEmpty(Prestamo array[], int size, int* posicion);                    //cambiar socio
int socio_buscarID(Prestamo array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarInt(Prestamo array[], int size, int valorBuscado, int* posicion);                    //cambiar socio
int socio_buscarString(Prestamo array[], int size, char* valorBuscado, int* indice);                    //cambiar socio
int socio_alta(Prestamo array[], int size, int* contadorID);                          //cambiar socio
int socio_baja(Prestamo array[], int sizeArray);                                      //cambiar socio
int socio_bajaValorRepetidoInt(Prestamo array[], int sizeArray, int valorBuscado);
int socio_modificar(Prestamo array[], int sizeArray);                                //cambiar socio
int socio_ordenarPorDobleCriterio(Prestamo array[],int size, int orderFirst, int orderSecond);                                  //cambiar socio
int socio_listar(Prestamo array[], int size);                      //cambiar socio




