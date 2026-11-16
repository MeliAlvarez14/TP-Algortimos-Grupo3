#ifndef TALLER_HEAP_H_INCLUDED
#define TALLER_HEAP_H_INCLUDED

#include "Bicicleta.h"

struct ElementoHeap {
    Bicicleta* bici;
    int prioridad; // desde 1 más urgente, hasta 3
};

class TallerHeap {
private:
    ElementoHeap* arreglo;
    int capacidad;
    int tamano;

    void flotar(int indice);
    void hundir(int indice);
    void redimensionar();

public:
    TallerHeap(int capacidadInicial = 10);
    ~TallerHeap();

    void insertar(Bicicleta* bici, int prioridad);
    Bicicleta* extraerMasUrgente();
    bool estaVacio() const;
    int obtenerTamano() const;
};

#endif