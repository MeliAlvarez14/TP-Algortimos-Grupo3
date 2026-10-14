#include <iostream>
#include "Estacion.h"
using namespace std;

class NodoCiclovia {

    private:
        Estacion* destino;
        NodoCiclovia* siguienteEstacion;

    public:
        NodoCiclovia(Estacion* destino);

        void cambiarSiguiente(NodoCiclovia* nuevoSiguiente);

};