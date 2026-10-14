#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "NodoCola.h"
#include <string>

class Cola {
private:
    NodoCola* primero; // Puntero al primer elemento (frente de la cola, por donde se desencola)
    NodoCola* ultimo;  // Puntero al último elemento (final de la cola, por donde se encola)
    int cantidad;      // Cantidad total de elementos presentes en la cola

public:
    // Pos: crea una cola vacía
    Cola();

    // Pos: desacopla y libera todos los nodos de la memoria
    ~Cola();

    // Pre: -
    // Pos: agrega un nuevo elemento al final de la cola (O(1))
    void encolar(std::string d);

    // Pre: la cola no debe estar vacía
    // Pos: remueve el elemento del frente de la cola y devuelve su valor (O(1))
    std::string desencolar();

    // Pre: -
    // Pos: devuelve true si no hay elementos en la cola, false en caso contrario
    bool vacia();

    // Pre: -
    // Pos: devuelve la cantidad actual de elementos
    int obtenerCantidad();
};

#endif