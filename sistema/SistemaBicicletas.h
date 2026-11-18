#ifndef SISTEMA_BICICLETAS_H_INCLUDED
#define SISTEMA_BICICLETAS_H_INCLUDED

#include <string>
#include "ABB.h"
#include "Bicicleta.h"
#include "Viaje.h"
#include "Grafo.h"
#include "Estacion.h"
#include "Viaje.h"
#include "TallerHeap.h"
#include "Lista.h"

struct EstacionFaltante {
    std::string codigo;
    int faltante;
};

class SistemaBicicletas {
    private:
        ABB arbolBicicletas;
        Grafo<std::string, Estacion> estaciones;
        TallerHeap tallerReparaciones;
        Lista<Viaje> listaViajes;

        void cargarBicicletas(std::string rutaArchivo);
        void cargarEstaciones(std::string rutaArchivo);
        void cargarViajes(std::string rutaArchivo);
        void cargarCiclovias(std::string rutaArchivo);

        void imprimirSubconjunto(const std::string* actual, int tamActual) const;
        void backtrack(
            const EstacionFaltante* estaciones,
            int n,
            int indice,
            int capacidadObjetivo,
            int sumActual,
            std::string* actual,
            int tamActual,
            int& cantidadSoluciones
        ) const;

    public:
        SistemaBicicletas();
        ~SistemaBicicletas(); //para liberar memo del heap
        void inicializarSistema();
        
        // --- Módulo A: Gestión de Estaciones
        void informacionDeEstacion(std::string codigo);
        void agregarEstacion(std::string codigo, std::string nombre, std::string barrio, int capacidadAnclajes, int bicisDisponibles);
        void eliminarEstacion(std::string codigo);
        void listarEstaciones(int opcion);
        void listarEstacionesConMenosOcupacion();
        void menorRecorridoPorCiclovia(std::string codOrigen, std::string codDestino);
        
        // --- Módulo B: Viajes
        void calcularViajesEstacionRango(std::string estacion, int fechaDesde, int fechaHasta);
        void buscarViajesUsuario(std::string dni);
        void listarBicicletasConMasDeKm(int minKm); //hacer metodo en el ABB
        void retirarBicicleta(std::string dni, std::string codigoEstacion); //descuenta una bici de bicisDisponibles de la Estación, si no hay se encola en colaEspera de Estación.
        void devolverBicicleta(Bicicleta* bici, std::string codigoEstacion); //Actualiza el códigoEstación de la Bicicleta, y se aumenta en 1 bicisDispoibles de esa estación. Y si hay colaEspera hace retirarBicicleta(dni, codEst)
        Bicicleta* buscarBicicletaPorId(int idBici); //método auxiliar para poder actualizar el códigoEstación al devolver una bici
        // --- Métodos del Módulo B.5 (Taller / Min-Heap) ---
        void enviarAlTaller(int idBici, int prioridad);
        void atenderSiguienteTaller();

        // --- Módulo C: Registro de Bicicletas (ABB) ---
        void registrarBicicleta(int id, std::string estacion, std::string tipo, std::string estado, int km);
        void buscarYMostrarBicicleta(int id);
        void listarBicicletasInOrder();
        void mostrarCantidadAveriadas();
        void mostrarAlturaArbol();
        void eliminarBicicletaDelArbol(int id);

        //--- Módulo D: Redistribución de Bicicletas ---
        void redistribuirBicicletas(const EstacionFaltante* estaciones, int n, int capacidad) const;

};

#endif