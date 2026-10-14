#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include <string>

class Viaje {
private:
    int idViaje;
    int biciId;
    std::string dniUsuario;
    std::string estacionOrigen;
    std::string estacionDestino;
    int fecha;          // Formato AAAAMMDD (ej: 20260310)
    int duracionMin;    // Duración del viaje en minutos

public:
    // Constructores
    Viaje();
    Viaje(int idViaje, int biciId, std::string dniUsuario, std::string estacionOrigen, std::string estacionDestino, int fecha, int duracionMin);

    // Getters estilo get
    int getIdViaje();
    int getBiciId();
    std::string getDniUsuario();
    std::string getEstacionOrigen();
    std::string getEstacionDestino();
    int getFecha();
    int getDuracionMin();

    // Getters estilo obtener (compatibilidad con el equipo)
    int obtenerIdViaje();
    int obtenerBiciId();
    std::string obtenerDniUsuario();
    std::string obtenerEstacionOrigen();
    std::string obtenerEstacionDestino();
    int obtenerFecha();
    int obtenerDuracionMin();

    // Métodos de negocio y consulta
    bool salioDeEstacionEnRango(std::string codigo, int fechaDesde, int fechaHasta);
    bool perteneceAUsuario(std::string dni);
    std::string mostrarInfo();
};

#endif

