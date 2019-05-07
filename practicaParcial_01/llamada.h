#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
 typedef struct
 {
     char estado[10];
     int idAsociado;
     char motivo;

 }Llamada;

 int lla_init(Llamada *arrayLlamada, int cantidad);
 int lla_findFree(Llamada *arrayLlamada,int cantidad, int *devuelve);
 int lla_addLla(Llamada *arrayLlamada, int cantidad,int posicionLibre, int id);

#endif // LLAMADA_H_INCLUDED
