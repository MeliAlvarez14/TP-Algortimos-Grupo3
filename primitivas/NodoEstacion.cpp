#include "NodoEstacion.h"
#include "Estacion.h"
#include "NodoCiclovia.h"

NodoEstacion::NodoEstacion(Estacion estacion) {
    this->estacion = estacion;
    siguienteEstacion = 0;
    listaCiclovias = 0;
}

NodoEstacion* NodoEstacion::obtenerSiguienteEstacion() {
    return this->siguienteEstacion;
};

NodoCiclovia* NodoEstacion::obtenerListaCiclovias(){
    return this->listaCiclovias;
};

void NodoEstacion::agregarCiclovia(Estacion* destino){
    NodoCiclovia* nuevaCiclovia = new NodoCiclovia(destino);

    if(listaCiclovias == 0){
        this->listaCiclovias = nuevaCiclovia;
    }
    else{
        nuevaCiclovia->cambiarSiguiente(this->listaCiclovias);
        this->listaCiclovias = nuevaCiclovia;
    }

};