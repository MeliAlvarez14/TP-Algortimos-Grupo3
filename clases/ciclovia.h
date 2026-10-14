#ifndef CICLOVIA_H_INCLUDED
#define CICLOVIA_H_INCLUDED

#include <string>

class Ciclovia {
private:
    std::string estacionA; // Código de la primera estación
    std::string estacionB; // Código de la segunda estación

public:
    // Constructores
    Ciclovia();
    Ciclovia(std::string estacionA, std::string estacionB);

    // Getters (compatibilidad con get y obtener)
    std::string getEstacionA();
    std::string getEstacionB();
    std::string obtenerEstacionA();
    std::string obtenerEstacionB();

    // Métodos útiles para el grafo y consultas
    bool conectaCon(std::string codigoEstacion);
    std::string obtenerOtraEstacion(std::string codigoEstacion);

    // Mostrar información
    std::string mostrarInfo();
};

#endif

