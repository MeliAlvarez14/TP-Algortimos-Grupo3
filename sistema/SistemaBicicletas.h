#ifndef SISTEMA_BICICLETAS_H_INCLUDED
#define SISTEMA_BICICLETAS_H_INCLUDED

#include <string>
#include "ABB.h"
#include "Bicicleta.h"
#include "Viaje.h"
#include "Grafo.h"
#include "Nodo.h"

// A medida que avancemos, incluir los .h acá:
// #include "TablaHashEstaciones.h"
// #include "TallerHeap.h"

class SistemaBicicletas {
private:
    ABB arbolBicicletas;
    Grafo grafoEstaciones;
    // TallerHeap tallerReparaciones;

    Nodo<Viaje>* primerViaje;
    int cantidadViajes;

    void cargarBicicletas(std::string rutaArchivo);
    void cargarEstaciones(std::string rutaArchivo);
    void cargarViajes(std::string rutaArchivo);
    void cargarCiclovias(std::string rutaArchivo);

public:
    SistemaBicicletas();
    ~SistemaBicicletas(); //para liberar memo del heap
    void inicializarSistema();
    
    // --- Módulo A: Gestión de Estaciones
    void informacionDeEstacion(std::string codigo);
    void agregarEstacion(std::string codigo, std::string nombre, std::string barrio, int capacidadAnclajes, int bicisDisponibles);
    void eliminarEstacion(std::string codigo);
    void listarEstacionesPorCapacidadDeAnclaje();
    void listarEstacionesPorBicicletasDisponibles();
    void listarEstacionesConMenosOcupacion();
    void menorRecorridoPorCiclovia(std::string codOrigen, std::string codDestino);
    
    
    // --- Módulo B: Viajes
    void calcularViajesEstacionRango(std::string estacion, int fechaDesde, int fechaHasta);
    void buscarViajesUsuario(std::string dni);
    void listarBicicletasConMasDeKm(int minKm); //hacer metodo en el ABB
    void retirarBicicleta(std::string dni, std::string codigoEstacion); //descuenta una bici de bicisDisponibles de la Estación, si no hay se encola en colaEspera de Estación.
    void devolverBicicleta(Bicicleta* bici, std::string codigoEstacion); //Actualiza el códigoEstación de la Bicicleta, y se aumenta en 1 bicisDispoibles de esa estación. Y si hay colaEspera hace retirarBicicleta(dni, codEst)
    Bicicleta* buscarBicicletaPorId(int idBici); //método auxiliar para poder actualizar el códigoEstación al devolver una bici
    //B.5) PENDIENTE

    // --- Módulo C: Registro de Bicicletas (ABB) ---
    void registrarBicicleta(int id, std::string estacion, std::string tipo, std::string estado, int km);
    void buscarYMostrarBicicleta(int id);
    void listarBicicletasInOrder();
    void mostrarCantidadAveriadas();
    void mostrarAlturaArbol();
    void eliminarBicicletaDelArbol(int id);

};

#endif