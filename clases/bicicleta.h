#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include <string>
using namespace std;

class Bicicleta {
private:
    int biciId;                  // Identificador único de la bici
    string codigoEstacion;  // Código de la estación en la que se ubica
    string tipo;            // "Mecanica" o "Electrica"
    string estado;          // "OK" o "Averiada"
    int kilometros;              // Kilómetros acumulados de uso

public:
    Bicicleta(int id, string estacion, string tipo, string estado, int km);

    int obtenerId();
    string obtenerEstacion();
    string obtenerTipo();
    string obtenerEstado();
    int obtenerKilometros();

    void cambiarEstacion(string nuevaEstacion);
    void cambiarEstado(string nuevoEstado);
    void sumarKilometros(int km);
    void mostrarDatos();
};

#endif