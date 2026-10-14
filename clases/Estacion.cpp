#include "Estacion.h"
#include <sstream>

// Constructor (la cola se inicializa sola llamando a su propio constructor por defecto)
Estacion::Estacion(std::string codigo, std::string nombre, std::string barrio, int capacidadAnclajes, int bicisDisponibles)
    : codigo(codigo), nombre(nombre), barrio(barrio), capacidadAnclajes(capacidadAnclajes), bicisDisponibles(bicisDisponibles) {}

// Getters y Setters
std::string Estacion::getCodigo(){ return codigo; }
std::string Estacion::getNombre(){ return nombre; }
std::string Estacion::getBarrio(){ return barrio; }
int Estacion::getCapacidadAnclajes(){ return capacidadAnclajes; }
int Estacion::getBicisDisponibles(){ return bicisDisponibles; }

void Estacion::setBicisDisponibles(int cantidad) {
    bicisDisponibles = cantidad;
}

// Métodos de la cola de espera utilizando la clase primitiva Cola
bool Estacion::estaColaVacia() {
    return colaEspera.vacia();
}

void Estacion::agregarAColaEspera(std::string dniUsuario) {
    colaEspera.encolar(dniUsuario);
}

std::string Estacion::atenderSiguienteEnEspera() {
    if (colaEspera.vacia()) {
        return "";
    }
    return colaEspera.desencolar();
}

// Mostrar información
std::string Estacion::mostrarInfo(){
    std::stringstream ss;
    ss << "Estación [" << codigo << "] " << nombre 
       << " (Barrio: " << barrio 
       << ") - Anclajes: " << capacidadAnclajes 
       << " - Bicis Disponibles: " << bicisDisponibles;
    return ss.str();
}