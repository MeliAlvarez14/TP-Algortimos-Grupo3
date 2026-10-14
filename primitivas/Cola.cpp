#include "Cola.h"
#include <iostream>

Cola::Cola() {
    this->primero = nullptr; // Inicialmente no hay nodos
    this->ultimo = nullptr;
    this->cantidad = 0;
}

bool Cola::vacia() {
    return (this->cantidad == 0);
}

int Cola::obtenerCantidad() {
    return this->cantidad;
}

void Cola::encolar(std::string d) {
    NodoCola* nuevo = new NodoCola(d); // Solicitamos memoria dinámica para el nuevo nodo
    if (vacia()) {
        this->primero = nuevo;         // Si está vacía, el nuevo nodo es tanto el primero como el último
    } else {
        this->ultimo->cambiarSiguiente(nuevo); // Conectamos el último nodo actual con el nuevo
    }
    this->ultimo = nuevo;              // El nuevo nodo pasa a ser el último
    this->cantidad++;                  // Incrementamos el contador de elementos
}

std::string Cola::desencolar() {
    if (vacia()) {
        return ""; // Si está vacía, no se puede desencolar
    }
    NodoCola* aBorrar = this->primero;            // Guardamos la dirección del nodo del frente
    std::string datoRetorno = aBorrar->obtenerDato(); // Obtenemos el valor almacenado

    this->primero = aBorrar->obtenerSiguiente();  // El frente ahora pasa al siguiente nodo
    if (this->primero == nullptr) {
        this->ultimo = nullptr;                   // Si no quedan elementos, el último también apunta a nulo
    }

    delete aBorrar; // Liberamos la memoria dinámica para evitar fugas (memory leaks)
    this->cantidad--;
    return datoRetorno;
}

Cola::~Cola() {
    while (!vacia()) {
        desencolar(); // Se desencola y elimina cada nodo uno por uno
    }
}