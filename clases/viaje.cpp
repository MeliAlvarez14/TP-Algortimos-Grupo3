#include "viaje.h"
#include <sstream>

Viaje::Viaje() {
    this->idViaje = 0;
    this->biciId = 0;
    this->dniUsuario = "";
    this->estacionOrigen = "";
    this->estacionDestino = "";
    this->fecha = 0;
    this->duracionMin = 0;
}

Viaje::Viaje(int idViaje, int biciId, std::string dniUsuario, std::string estacionOrigen, std::string estacionDestino, int fecha, int duracionMin) {
    this->idViaje = idViaje;
    this->biciId = biciId;
    this->dniUsuario = dniUsuario;
    this->estacionOrigen = estacionOrigen;
    this->estacionDestino = estacionDestino;
    this->fecha = fecha;
    this->duracionMin = duracionMin;
}

int Viaje::getIdViaje() {
    return this->idViaje;
}

int Viaje::getBiciId() {
    return this->biciId;
}

std::string Viaje::getDniUsuario() {
    return this->dniUsuario;
}

std::string Viaje::getEstacionOrigen() {
    return this->estacionOrigen;
}

std::string Viaje::getEstacionDestino() {
    return this->estacionDestino;
}

int Viaje::getFecha() {
    return this->fecha;
}

int Viaje::getDuracionMin() {
    return this->duracionMin;
}

// Getters alternativos para compatibilidad
int Viaje::obtenerIdViaje() {
    return this->idViaje;
}

int Viaje::obtenerBiciId() {
    return this->biciId;
}

std::string Viaje::obtenerDniUsuario() {
    return this->dniUsuario;
}

std::string Viaje::obtenerEstacionOrigen() {
    return this->estacionOrigen;
}

std::string Viaje::obtenerEstacionDestino() {
    return this->estacionDestino;
}

int Viaje::obtenerFecha() {
    return this->fecha;
}

int Viaje::obtenerDuracionMin() {
    return this->duracionMin;
}

// Métodos de consulta
bool Viaje::salioDeEstacionEnRango(std::string codigo, int fechaDesde, int fechaHasta) {
    return (this->estacionOrigen == codigo && this->fecha >= fechaDesde && this->fecha <= fechaHasta);
}

bool Viaje::perteneceAUsuario(std::string dni) {
    return (this->dniUsuario == dni);
}

std::string Viaje::mostrarInfo() {
    std::stringstream ss;
    ss << "Viaje #" << this->idViaje 
       << " - Bici: " << this->biciId
       << " - Usuario: " << this->dniUsuario
       << " - Origen: " << this->estacionOrigen
       << " -> Destino: " << this->estacionDestino
       << " - Fecha: " << this->fecha
       << " - Duración: " << this->duracionMin << " min";
    return ss.str();
}

