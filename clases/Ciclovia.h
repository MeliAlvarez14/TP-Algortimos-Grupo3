#ifndef CICLOVIA_H_INCLUDED
#define CICLOVIA_H_INCLUDED

#include <string>

class Ciclovia {
private:
    std::string estacionA; // Codigo de la primera estacion en camelCase
    std::string estacionB; // Codigo de la segunda estacion en camelCase

public:
    // Constructores
    Ciclovia();
    Ciclovia(const std::string& estacionA, const std::string& estacionB);

    // Getters oficiales en estricto camelCase
    std::string getEstacionA() const;
    std::string getEstacionB() const;

    // Metodos de consulta para el grafo
    bool conectaCon(const std::string& codigoEstacion) const;
    std::string obtenerOtraEstacion(const std::string& codigoEstacion) const;

    // Mostrar informacion
    std::string mostrarInfo() const;

    // Alias inline por compatibilidad si el diagrama anterior tenia guion bajo
    std::string getEstacion_a() const { return getEstacionA(); }
    std::string getEstacion_b() const { return getEstacionB(); }
};

#endif
