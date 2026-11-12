#ifndef SISTEMA_BICICLETAS_H_INCLUDED
#define SISTEMA_BICICLETAS_H_INCLUDED

#include <string>
#include "ABB.h"
#include "Bicicleta.h"

// A medida que tus compañeros terminen sus partes, incluyen sus .h acá:
// #include "TablaHashEstaciones.h"
// #include "TallerHeap.h"

class SistemaBicicletas {
private:
    ABB arbolBicicletas;
    // TablaHashEstaciones estaciones;
    // TallerHeap tallerReparaciones;

    void cargarBicicletas(std::string rutaArchivo);
    // void cargarEstaciones(std::string rutaArchivo);
    // void cargarViajes(std::string rutaArchivo);
    // void cargarCiclovias(std::string rutaArchivo);

public:
    SistemaBicicletas();
    void inicializarSistema();

    // --- Módulo C: Registro de Bicicletas (ABB) ---
    void registrarBicicleta(int id, std::string estacion, std::string tipo, std::string estado, int km);
    void buscarYMostrarBicicleta(int id);
    void listarBicicletasInOrder();
    void mostrarCantidadAveriadas();
    void mostrarAlturaArbol();
    void eliminarBicicletaDelArbol(int id);

    // --- Apoyo al Módulo B.3 (Bicicletas con más de X km) ---
    void listarBicicletasConMasDeKm(int minKm);
};

#endif