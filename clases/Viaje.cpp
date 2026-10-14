#include "Viaje.h"
#include <sstream>

Viaje::Viaje()
    : idViaje(0), idBici(0), dniUsuario(""), estacionOrigen(""), estacionDestino(""), fecha(0), duracionMin(0) {}

Viaje::Viaje(int idViaje, int idBici, const std::string& dniUsuario, const std::string& estacionOrigen, const std::string& estacionDestino, int fecha, int duracionMin)
    : idViaje(idViaje), idBici(idBici), dniUsuario(dniUsuario), estacionOrigen(estacionOrigen), estacionDestino(estacionDestino), fecha(fecha), duracionMin(duracionMin) {}

int Viaje::getIdViaje() const {
    return this->idViaje;
}

int Viaje::getIdBici() const {
    return this->idBici;
}

std::string Viaje::getDniUsuario() const {
    return this->dniUsuario;
}

std::string Viaje::getEstacionOrigen() const {
    return this->estacionOrigen;
}

std::string Viaje::getEstacionDestino() const {
    return this->estacionDestino;
}

int Viaje::getFecha() const {
    return this->fecha;
}

int Viaje::getDuracionMin() const {
    return this->duracionMin;
}

bool Viaje::salioDeEstacionEnRango(const std::string& codigo, int fechaDesde, int fechaHasta) const {
    return (this->estacionOrigen == codigo && this->fecha >= fechaDesde && this->fecha <= fechaHasta);
}

bool Viaje::perteneceAUsuario(const std::string& dni) const {
    return (this->dniUsuario == dni);
}

std::string Viaje::mostrarInfo() const {
    std::stringstream ss;
    ss << "Viaje #" << this->idViaje 
       << " - Bici: " << this->idBici
       << " - Usuario: " << this->dniUsuario
       << " - Origen: " << this->estacionOrigen
       << " -> Destino: " << this->estacionDestino
       << " - Fecha: " << this->fecha
       << " - Duracion: " << this->duracionMin << " min";
    return ss.str();
}
