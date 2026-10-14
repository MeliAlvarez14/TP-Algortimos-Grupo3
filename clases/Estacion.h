#ifndef ESTACION_H
#define ESTACION_H

#include <string>
#include "primitivas/Cola.h"

class Estacion {
private:
    std::string codigo;
    std::string nombre;
    std::string barrio;
    int capacidadAnclajes;
    int bicisDisponibles;

    Cola colaEspera; // La estación utiliza la clase primitiva Cola para gestionar la cola de espera

public:
    // Constructor
    Estacion(std::string codigo, std::string nombre, std::string barrio, int capacidadAnclajes, int bicisDisponibles);
    
    // Getters y Setters
    std::string getCodigo();
    std::string getNombre();
    std::string getBarrio();
    int getCapacidadAnclajes();
    int getBicisDisponibles();
    void setBicisDisponibles(int cantidad);

    // Métodos delegados a la Cola del equipo
    void agregarAColaEspera(std::string dniUsuario);
    bool estaColaVacia();
    std::string atenderSiguienteEnEspera();

    // Método auxiliar
    std::string mostrarInfo();
};

#endif