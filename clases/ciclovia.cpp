#include "ciclovia.h"
#include <sstream>

Ciclovia::Ciclovia() {
    this->estacionA = "";
    this->estacionB = "";
}

Ciclovia::Ciclovia(std::string estacionA, std::string estacionB) {
    this->estacionA = estacionA;
    this->estacionB = estacionB;
}

std::string Ciclovia::getEstacionA() {
    return this->estacionA;
}

std::string Ciclovia::getEstacionB() {
    return this->estacionB;
}

std::string Ciclovia::obtenerEstacionA() {
    return this->estacionA;
}

std::string Ciclovia::obtenerEstacionB() {
    return this->estacionB;
}

bool Ciclovia::conectaCon(std::string codigoEstacion) {
    return (this->estacionA == codigoEstacion || this->estacionB == codigoEstacion);
}

std::string Ciclovia::obtenerOtraEstacion(std::string codigoEstacion) {
    if (this->estacionA == codigoEstacion) {
        return this->estacionB;
    } else if (this->estacionB == codigoEstacion) {
        return this->estacionA;
    }
    return "";
}

std::string Ciclovia::mostrarInfo() {
    std::stringstream ss;
    ss << "Ciclovía: " << this->estacionA << " <---> " << this->estacionB;
    return ss.str();
}

