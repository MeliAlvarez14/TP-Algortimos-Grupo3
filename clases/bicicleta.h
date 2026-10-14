#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

#include <string>

class Bicicleta {
private:
    int biciId;                  // Identificador único de la bici
    std::string codigoEstacion;  // Código de la estación en la que se ubica
    std::string tipo;            // "Mecanica" o "Electrica"
    std::string estado;          // "OK" o "Averiada"
    int kilometros;              // Kilómetros acumulados de uso

public:
    Bicicleta(int id, std::string estacion, std::string tipo, std::string estado, int km);

    int obtenerId();
    std::string obtenerEstacion();
    std::string obtenerTipo();
    std::string obtenerEstado();
    int obtenerKilometros();

    void cambiarEstacion(std::string nuevaEstacion);
    void cambiarEstado(std::string nuevoEstado);
    void sumarKilometros(int km);
};

#endif