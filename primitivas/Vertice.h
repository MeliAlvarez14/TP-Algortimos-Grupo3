#ifndef VERTICE_H
#define VERTICE_H

#include "Nodo.h"

template <typename T, typename S>
class Vertice {

private:
    T dato;                         
    Nodo<S>* primero;   

public:

    Vertice(T d) {
        dato = d;
        primero = nullptr;
    }

    ~Vertice() {
        Nodo<S>* actual = primero;
        while (actual != nullptr) {
            Nodo<S>* temp = actual;
            actual = actual->obtenerSiguiente();
            delete temp;
        }
    }

    T obtenerDato() const {
        return dato;
    }

    Nodo<S>* obtenerPrimero() {
        return primero;
    }

    void agregarArista(S arista) {
        Nodo<S>* nuevoNodo = new Nodo<S>(arista);
        nuevoNodo->cambiarSiguiente(primero);
        primero = nuevoNodo;
    }

    void eliminarArista(S destino) {
        if(primero == nullptr){
            return;
        }

        if(primero->obtenerDato() == destino){
            Nodo<S>* actual = primero;
            primero = primero->obtenerSiguiente();
            delete actual;
            return;
        }

        Nodo<S>* actual = primero;
        while(actual->obtenerSiguiente() != nullptr && actual->obtenerSiguiente()->obtenerDato() != destino){
            actual = actual->obtenerSiguiente();
        }

        if(actual->obtenerSiguiente() != nullptr){
            Nodo<S>* nodoEliminar = actual->obtenerSiguiente();
            actual->cambiarSiguiente(nodoEliminar->obtenerSiguiente());
            delete nodoEliminar;
        }
    }
};

#endif