#ifndef NODO_COLA_H_INCLUDED
#define NODO_COLA_H_INCLUDED

// Usamos std::string para almacenar el DNI o identificador del usuario en espera
#include <string>

class NodoCola {
private:
    std::string dato;      // Guarda el valor (ej: DNI del usuario)
    NodoCola* siguiente;   // Puntero al siguiente nodo en la cola

public:
    // Pre: recibe una cadena con el dato
    // Pos: crea el nodo inicializando 'siguiente' en nullptr
    NodoCola(std::string d);

    void cambiarDato(std::string d);
    void cambiarSiguiente(NodoCola* s);

    std::string obtenerDato();
    NodoCola* obtenerSiguiente();
};

#endif