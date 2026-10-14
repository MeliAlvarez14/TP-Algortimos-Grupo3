#include "Ciclovia.h"
#include <sstream>

Ciclovia::Ciclovia()
    : estacionA(""), estacionB("") {}

Ciclovia::Ciclovia(const std::string& estacionA, const std::string& estacionB)
    : estacionA(estacionA), estacionB(estacionB) {}

std::string Ciclovia::getEstacionA() const {
    return this->estacionA;
}

std::string Ciclovia::getEstacionB() const {
    return this->estacionB;
}

bool Ciclovia::conectaCon(const std::string& codigoEstacion) const {
    return (this->estacionA == codigoEstacion || this->estacionB == codigoEstacion);
}

std::string Ciclovia::obtenerOtraEstacion(const std::string& codigoEstacion) const {
    if (this->estacionA == codigoEstacion) {
        return this->estacionB;
    } else if (this->estacionB == codigoEstacion) {
        return this->estacionA;
    }
    return "";
}

std::string Ciclovia::mostrarInfo() const {
    std::stringstream ss;
    ss << "Ciclovia: " << this->estacionA << " <---> " << this->estacionB;
    return ss.str();
}
