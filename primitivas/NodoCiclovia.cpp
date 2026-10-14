#include "NodoCiclovia.h"

NodoCiclovia::NodoCiclovia(Estacion* destino){
    this->destino = destino;
    siguienteEstacion = 0;
};

void NodoCiclovia::cambiarSiguiente(NodoCiclovia* nuevoSiguiente){
    this->siguienteEstacion = nuevoSiguiente;
};