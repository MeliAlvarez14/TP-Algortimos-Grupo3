#include <iostream>
#include "Estacion.h"
#include "NodoCiclovia.h"
using namespace std;

class NodoEstacion {

    private:
        Estacion estacion;
        NodoEstacion* siguienteEstacion;
        NodoCiclovia* listaCiclovias;

    public:
        NodoEstacion(Estacion estacion);

        NodoEstacion* obtenerSiguienteEstacion();

        NodoCiclovia* obtenerListaCiclovias();

        void agregarCiclovia(Estacion* destino);

};