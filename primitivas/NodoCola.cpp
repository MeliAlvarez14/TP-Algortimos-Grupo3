#include "NodoCola.h"

NodoCola::NodoCola(std::string d) {
    this->dato = d;            // 'this->dato' hace referencia al atributo privado de la clase
    this->siguiente = nullptr;  // Inicializamos en puntero nulo (sin siguiente)
}

void NodoCola::cambiarDato(std::string d) {
    this->dato = d;
}

void NodoCola::cambiarSiguiente(NodoCola* s) {
    this->siguiente = s;       // Guarda la dirección de memoria del siguiente nodo
}

std::string NodoCola::obtenerDato() {
    return this->dato;
}

NodoCola* NodoCola::obtenerSiguiente() {
    return this->siguiente;    // Retorna la dirección del siguiente nodo
}