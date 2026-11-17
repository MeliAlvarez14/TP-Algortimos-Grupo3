#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo.h"

template <typename T>
class Lista {
private:
    Nodo<T>* primero;
    int cantidad;

public:
    // Pos: Crea una lista vacía
    Lista() {
        this->primero = nullptr;
        this->cantidad = 0;
    }

    // Pos: Destructor. Desacopla y libera todos los nodos de la memoria dinámicamente (~Lista)
    ~Lista() {
        Nodo<T>* actual = this->primero;
        while (actual != nullptr) {
            Nodo<T>* siguienteNodo = actual->obtenerSiguiente();
            delete actual; // Libera el nodo de la memoria
            actual = siguienteNodo;
        }
    }

    // Pre: -
    // Pos: Devuelve true si la lista no tiene elementos, false en caso contrario
    bool estaVacia() const {
        return (this->cantidad == 0);
    }

    // Pre: -
    // Pos: Devuelve la cantidad actual de elementos en la lista
    int obtenerCantidad() const {
        return this->cantidad;
    }

    // Pre: -
    // Pos: Inserta un nuevo elemento al principio de la lista en O(1)
    void insertar(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->cambiarSiguiente(this->primero);
        this->primero = nuevoNodo;
        this->cantidad++;
    }

    // Pre: -
    // Pos: Devuelve el puntero al primer nodo para permitir recorridos externos
    Nodo<T>* obtenerPrimero() const {
        return this->primero;
    }
};

#endif