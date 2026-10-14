#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include <string>

class Viaje {
private:
    int idViaje;
    int idBici;
    std::string dniUsuario;
    std::string estacionOrigen;
    std::string estacionDestino;
    int fecha;          // Formato AAAAMMDD
    int duracionMin;    // Duracion del viaje en minutos

public:
    // Constructores
    Viaje();
    Viaje(int idViaje, int idBici, const std::string& dniUsuario, const std::string& estacionOrigen, const std::string& estacionDestino, int fecha, int duracionMin);

    // Getters del modelo UML
    int getIdViaje() const;
    int getIdBici() const;
    std::string getDniUsuario() const;
    std::string getEstacionOrigen() const;
    std::string getEstacionDestino() const;
    int getFecha() const;
    int getDuracionMin() const;

    // Metodos de consulta
    bool salioDeEstacionEnRango(const std::string& codigo, int fechaDesde, int fechaHasta) const;
    bool perteneceAUsuario(const std::string& dni) const;
    std::string mostrarInfo() const;
};

#endif
