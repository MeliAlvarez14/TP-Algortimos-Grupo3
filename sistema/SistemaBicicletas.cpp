#include "SistemaBicicletas.h"
#include <iostream>
#include <fstream>
#include "Estacion.h"
#include "Vertice.h"

using namespace std;

SistemaBicicletas::SistemaBicicletas() : estaciones(101) {
    // Los constructores de ABB y demás estructuras se ejecutan automáticamente
    primerViaje = nullptr;
    cantidadViajes = 0;
}

void SistemaBicicletas::inicializarSistema() {
    cargarEstaciones("estaciones.txt");
    cargarBicicletas("bicicletas.txt");
    cargarViajes("viajes.txt");
    cargarCiclovias("ciclovias.txt");
}

SistemaBicicletas::~SistemaBicicletas() {}

//Módulo A
void SistemaBicicletas::cargarEstaciones(string rutaArchivo) {
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << rutaArchivo << endl;
        return;
    }

    string codigo, nombre, barrio;
    int capacidad, bicisDisponibles;

    while (archivo >> codigo >> nombre >> barrio >> capacidad >> bicisDisponibles) {
        Estacion nuevaEstacion(codigo, nombre, barrio, capacidad, bicisDisponibles);
        
        estaciones.agregarVertice(codigo, nuevaEstacion);
    }

    archivo.close();
    cout << "Estaciones cargadas correctamente." << endl;
}

void SistemaBicicletas::cargarCiclovias(string rutaArchivo) {
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << rutaArchivo << endl;
        return;
    }

    string estacionA, estacionB;

    while (archivo >> estacionA >> estacionB) {
        estaciones.agregarArista(estacionA, estacionB);
    }

    archivo.close();
    cout << "Ciclovias cargadas correctamente." << endl;
}

void SistemaBicicletas::informacionDeEstacion(string codigo) {
    Vertice<Estacion, string>* verticeBuscado = estaciones.obtenerVertice(codigo);

    if (verticeBuscado != nullptr){
        Estacion estacionBuscada = verticeBuscado->obtenerDato();
        cout << estacionBuscada.mostrarInfo() << endl;
    } else {
        cout << "Error: No se encontro ninguna estacion con el codigo " << codigo << endl;
    }
}

void SistemaBicicletas::agregarEstacion(string codigo, string nombre, string barrio, int capacidadAnclajes, int bicisDisponibles) {
    if (estaciones.obtenerVertice(codigo) != nullptr) {
        cout << "Error: Ya existe una estacion con el codigo " << codigo << endl;
        return;
    }

    Estacion nuevaEstacion(codigo, nombre, barrio, capacidadAnclajes, bicisDisponibles);
    estaciones.agregarVertice(codigo, nuevaEstacion);

    cout << "¡Estacion agregada exitosamente al sistema!" << endl;
}

void SistemaBicicletas::eliminarEstacion(string codigo) {
    Vertice<Estacion, string>* verticeBuscado = estaciones.obtenerVertice(codigo);

    if (verticeBuscado != nullptr){
        estaciones.eliminarVertice(codigo);
        cout << "Estación (" << codigo << ") eliminada correctamente " << endl;
    } else {
        cout << "Error: No se encontro ninguna estacion con el codigo " << codigo << endl;
    }
}

void SistemaBicicletas::listarEstaciones(int opcion) {
    int cantidad = estaciones.obtenerCantidadVertices(); 
    if (cantidad == 0) {
        cout << "No hay estaciones registradas." << endl;
        return;
    }

    if (opcion != 1 && opcion != 2) {
        cout << "Opcion invalida.\n";
        return;
    }

    Estacion* datosEstaciones = new Estacion[cantidad];
    int indice = 0;

    estaciones.obtenerDatosVertices(datosEstaciones, indice);

    // Inserción
    for (int i = 1; i < cantidad; i++) {
        Estacion actual = datosEstaciones[i];
        int j = i - 1;

        if (opcion == 1) {
            while (j >= 0 && datosEstaciones[j].getCapacidadAnclajes() > actual.getCapacidadAnclajes()) {
                datosEstaciones[j + 1] = datosEstaciones[j];
                j--;
            }
        } else if (opcion == 2) {
            while (j >= 0 && datosEstaciones[j].getBicisDisponibles() > actual.getBicisDisponibles()) {
                datosEstaciones[j + 1] = datosEstaciones[j];
                j--;
            }
        }
        datosEstaciones[j + 1] = actual;
    }

    cout << "\n----------------------------------------------------\n";
    cout << "ESTACIONES ORDENADAS\n";
    cout << "----------------------------------------------------\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "Estación: " << datosEstaciones[i].getNombre()
             << " | Anclajes: " << datosEstaciones[i].getCapacidadAnclajes() 
             << " | Bicis disponibles: " << datosEstaciones[i].getBicisDisponibles() << "\n";
    }
    cout << "----------------------------------------------------\n";

    delete[] datosEstaciones;
}

void SistemaBicicletas::listarEstacionesConMenosOcupacion() {
    int cantidad = estaciones.obtenerCantidadVertices(); 
    if (cantidad == 0) {
        cout << "No hay estaciones registradas." << endl;
        return;
    }

    Estacion* datosEstaciones = new Estacion[cantidad];
    int indice = 0, cantBajaOcupacion = 0;

    estaciones.obtenerDatosVertices(datosEstaciones, indice);

    for (int i = 0; i < cantidad; i++) {
        int capacidad = datosEstaciones[i].getCapacidadAnclajes();
        int bicis = datosEstaciones[i].getBicisDisponibles();

        if (capacidad > 0) {
            if ((bicis * 1.0) / capacidad < 0.20) {
                cout << "Estación: " << datosEstaciones[i].getNombre()
                     << " | Anclajes: " << capacidad 
                     << " | Bicis disponibles: " << bicis << "\n";
                cantBajaOcupacion++;
            }
        }
    }

    if (cantBajaOcupacion == 0) {
        cout << "No hay estaciones con menos del 20% de ocupación.\n";
    }

    delete[] datosEstaciones;
}


void SistemaBicicletas::menorRecorridoPorCiclovia(string codOrigen, string codDestino) {
    Vertice<Estacion, string>* vOrigen = estaciones.obtenerVertice(codOrigen);
    if (vOrigen == nullptr) {
        cout << "Error: La estacion de origen con codigo '" << codOrigen << "' no existe." << endl;
        return;
    }

    Vertice<Estacion, string>* vDestino = estaciones.obtenerVertice(codDestino);
    if (vDestino == nullptr) {
        cout << "Error: La estacion de destino con codigo '" << codDestino << "' no existe." << endl;
        return;
    }

    estaciones.bfs(codOrigen, codDestino);
    cout << "\n";
}


//Módulo B
void SistemaBicicletas::cargarViajes(string rutaArchivo) {
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << rutaArchivo << endl;
        return;
    }

    int idViaje, idBici, fecha, duracionMin;
    string dniUsuario, estacionOrigen, estacionDestino;

    while (archivo >> idViaje >> idBici >> dniUsuario >> estacionOrigen >> estacionDestino >> fecha >> duracionMin) {
        Viaje nuevoViaje(idViaje, idBici, dniUsuario, estacionOrigen, estacionDestino, fecha, duracionMin);
        
        //Creacion nodo y se inserta al principio de la lista enlazada (manualmente)
        Nodo<Viaje>* nuevoNodo = new Nodo<Viaje>(nuevoViaje);
        nuevoNodo->cambiarSiguiente(primerViaje);
        primerViaje = nuevoNodo;
        cantidadViajes++;
    }

    archivo.close();
    cout << "Viajes cargados correctamente en lista enlazada. Total: " << cantidadViajes << endl;
}

void SistemaBicicletas::calcularViajesEstacionRango(string estacionBuscada, int fechaDesde, int fechaHasta) {
    int contador = 0;
    Nodo<Viaje>* actual = primerViaje;

    while (actual != nullptr) {
        // Obtener Viaje guardado en el nodo
        Viaje viajeActual = actual->obtenerDato();
        
        // Usar el método ya hecho de Viaje
        if (viajeActual.salioDeEstacionEnRango(estacionBuscada, fechaDesde, fechaHasta)) {
            contador++;
        }
        actual = actual->obtenerSiguiente();
    }

    cout << "Cantidad de viajes desde " << estacionBuscada 
         << " entre " << fechaDesde << " y " << fechaHasta 
         << ": " << contador << endl;
}

void SistemaBicicletas::buscarViajesUsuario(std::string dni){
    int minutos = 0;
    Nodo<Viaje>* actual = primerViaje;

    while (actual != nullptr) {
        // Obtener Viaje guardado en el nodo
        Viaje viajeActual = actual->obtenerDato();
        
        if(viajeActual.perteneceAUsuario(dni)){
            minutos = minutos + viajeActual.getDuracionMin();
        }
        actual = actual->obtenerSiguiente();
    }

    cout << "La cantidad de minutos pedaleados por el usuario " << dni 
         << " fueron: " << minutos << endl;
}

void SistemaBicicletas::retirarBicicleta(std::string dni, std::string codigoEstacion) {
    // Buscamos la estación en la tabla hash de estaciones y verificamos existencia
    Vertice<Estacion, string>* estacionBuscada = estaciones.obtenerVertice(codigoEstacion);
    if (estacionBuscada == nullptr) {
        cout << "Error: La estacion con codigo " << codigoEstacion << " no existe." << endl;
        return;
    }

    Estacion& estacion = estacionBuscada->obtenerDato(); 

    // Si hay bicicletas disponibles, se descuenta una
    if (estacion.getBicisDisponibles() > 0) {
        estacion.setBicisDisponibles(estacion.getBicisDisponibles() - 1);
        cout << "Bicicleta retirada con exito de la estacion " << codigoEstacion 
             << " por el usuario (DNI: " << dni << ")." << endl;
    } else {
        // Si no hay disponibles, se encola al usuario en la cola de espera de la estación
        estacion.agregarAColaEspera(dni);
        cout << "No hay bicis disponibles en " << codigoEstacion 
             << ". El usuario DNI " << dni << " fue agregado a la cola de espera." << endl;
    }
}

void SistemaBicicletas::devolverBicicleta(Bicicleta* bici, std::string codigoEstacion) {
    if (bici == nullptr) {
        cout << "Error: Bicicleta invalida." << endl;
        return;
    }

    // Buscamos la estación
    Vertice<Estacion, string>* estacionBuscada = estaciones.obtenerVertice(codigoEstacion);
    if (estacionBuscada == nullptr) {
        cout << "Error: La estacion con codigo " << codigoEstacion << " no existe." << endl;
        return;
    }

    Estacion& estacion = estacionBuscada->obtenerDato(); 

    // Si existe actualizamos el código de estación de la bicicleta
    bici->cambiarEstacion(codigoEstacion);

    //Aumentamos en 1 las bicicletas disponibles de la estación
    estacion.setBicisDisponibles(estacion.getBicisDisponibles() + 1);
    cout << "Bicicleta devuelta en la estacion " << codigoEstacion << "." << endl;

    //Si hay gente en la cola de espera, se le asigna la bici al primero
    if (!estacion.estaColaVacia()) {
        std::string dniSiguiente = estacion.atenderSiguienteEnEspera();
        cout << "Habia un usuario en espera en esta estacion." << endl;
        //Llamamos a retirarBicicleta para asignársela al usuario que estaba esperando
        retirarBicicleta(dniSiguiente, codigoEstacion);
    }
}


//Módulo B-5
void SistemaBicicletas::enviarAlTaller(int idBici, int prioridad) {
    Bicicleta* bici = arbolBicicletas.buscar(idBici);
    if (bici == nullptr) {
        cout << "No se encontro la bicicleta." << endl;
        return;
    }
    bici->cambiarEstado("Averiada");
    //Se le pasa la prioridad configurable por parámetro, pero si es electrica se cambia automáticamente a 1
    int prioReal = (bici->obtenerTipo() == "Electrica") ? 1 : prioridad;
    tallerReparaciones.insertar(bici, prioReal);
    cout << "Bicicleta " << idBici << " enviada al taller con prioridad " << prioReal << "." << endl;
}

void SistemaBicicletas::atenderSiguienteTaller() {
    Bicicleta* biciUrgente = tallerReparaciones.extraerMasUrgente();
    if (biciUrgente == nullptr) {
        cout << "El taller no tiene bicicletas en reparacion." << endl;
        return;
    }
    biciUrgente->cambiarEstado("OK");
    cout << "Bicicleta " << biciUrgente->obtenerId() << " reparada y devuelta al sistema con estado OK." << endl;
}

//Módulo C
void SistemaBicicletas::cargarBicicletas(string rutaArchivo) {
    ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << rutaArchivo << endl;
        return;
    }

    int id, km;
    string estacion, tipo, estado;

    while (archivo >> id >> estacion >> tipo >> estado >> km) {
        Bicicleta* nuevaBici = new Bicicleta(id, estacion, tipo, estado, km);
        if (arbolBicicletas.buscar(id) != nullptr) {
            continue;
        }
        arbolBicicletas.insertar(id, nuevaBici);

        // CONEXIÓN CON MÓDULO B.5 (Taller / Min-Heap):
        if (estado == "Averiada") {
            int prioridad = (tipo == "Electrica") ? 1 : 2;
            tallerReparaciones.insertar(nuevaBici, prioridad);
        }
    }

    archivo.close();
    cout << "Bicicletas cargadas correctamente desde " << rutaArchivo << "." << endl;
}

void SistemaBicicletas::registrarBicicleta(int id, string estacion, string tipo, string estado, int km) {
    // Validar ID (por si se llama al método desde otro lado fuera del menú)
    if (arbolBicicletas.buscar(id) != nullptr) {
        cout << "Error: Ya existe una bicicleta con el ID " << id << "." << endl;
        return;
    }

    // Validar existencia de la estación
    Vertice<Estacion, string>* verticeEstacion = estaciones.obtenerVertice(estacion);
    if (verticeEstacion == nullptr) {
        cout << "Error: La estacion '" << estacion << "' no existe." << endl;
        return;
    }

    // Validar capacidad de anclajes (referencia & para modificar la estación real en el grafo)
    Estacion& estacionBici = verticeEstacion->obtenerDato();
    if (estacionBici.getBicisDisponibles() >= estacionBici.getCapacidadAnclajes()) {
        cout << "Error: La estacion " << estacion << " no tiene anclajes libres ("
             << estacionBici.getBicisDisponibles() << "/" << estacionBici.getCapacidadAnclajes() << ")." << endl;
        return;
    }

    Bicicleta* nueva = new Bicicleta(id, estacion, tipo, estado, km);
    arbolBicicletas.insertar(id, nueva);
    estacionBici.setBicisDisponibles(estacionBici.getBicisDisponibles() + 1);

    if (estado == "Averiada") {
        int prioridad = (tipo == "Electrica") ? 1 : 2;
        tallerReparaciones.insertar(nueva, prioridad);
    }
    
    cout << "Bicicleta " << id << " registrada exitosamente." << endl;
}

void SistemaBicicletas::buscarYMostrarBicicleta(int id) {
    Bicicleta* encontrada = arbolBicicletas.buscar(id);

    if (encontrada != nullptr) {
        cout << "\n--- Datos de la Bicicleta ---" << endl;
        encontrada->mostrarDatos();
    } else {
        cout << "No se encontro ninguna bicicleta con el ID " << id << "." << endl;
    }
}

Bicicleta* SistemaBicicletas::buscarBicicletaPorId(int id){
    Bicicleta* unaBici = arbolBicicletas.buscar(id);
    return unaBici;
}

void SistemaBicicletas::listarBicicletasInOrder() {
    cout << "\n--- Listado de Bicicletas (Ordenadas por ID) ---" << endl;
    arbolBicicletas.listarInOrder();
}

void SistemaBicicletas::mostrarCantidadAveriadas() {
    int cant = arbolBicicletas.contarAveriadas();
    cout << "Cantidad total de bicicletas averiadas en la red: " << cant << endl;
}

void SistemaBicicletas::mostrarAlturaArbol() {
    int altura = arbolBicicletas.obtenerAltura();
    cout << "Altura actual del ABB de bicicletas: " << altura << endl;
}

void SistemaBicicletas::eliminarBicicletaDelArbol(int id) {
    Bicicleta* bici = arbolBicicletas.buscar(id);
    if (bici == nullptr) {
        cout << "No se encontro ninguna bicicleta con el ID " << id << " para eliminar." << endl;
        return;
    }

    if (bici->obtenerEstado() == "Averiada") {
        cout << "Error: No se puede eliminar la bicicleta " << id << " porque esta en el taller de reparaciones." << endl;
        return;
    }

    // Decrementar la cantidad de bicis en su estación actual (si la estación existe)
    string codEstacion = bici->obtenerEstacion();
    Vertice<Estacion, string>* verticeEstacion = estaciones.obtenerVertice(codEstacion);
    if (verticeEstacion != nullptr) {
        Estacion& estacion = verticeEstacion->obtenerDato();
        if (estacion.getBicisDisponibles() > 0) {
            estacion.setBicisDisponibles(estacion.getBicisDisponibles() - 1);
        }
    }

    arbolBicicletas.eliminar(id);
    cout << "Bicicleta " << id << " eliminada del sistema." << endl;
}

void SistemaBicicletas::listarBicicletasConMasDeKm(int minKm) {
    cout << "\n--- Bicicletas con mas de " << minKm << " km (Para revision) ---" << endl;
    arbolBicicletas.listarConMasDeKm(minKm);
}


// Módulo D
void SistemaBicicletas::imprimirSubconjunto(const std::string* actual, int tamActual) const {
    std::cout << "{";
    for (int i = 0; i < tamActual; ++i) {
        std::cout << actual[i];
        if (i + 1 < tamActual) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

void SistemaBicicletas::backtrack(
    const EstacionFaltante* estaciones,
    int n,
    int indice,
    int capacidadObjetivo,
    int sumActual,
    std::string* actual,
    int tamActual,
    int& cantidadSoluciones
    ) const{
        if (sumActual == capacidadObjetivo) {
            imprimirSubconjunto(actual, tamActual);
            cantidadSoluciones++;
            return;
        }

        if (sumActual > capacidadObjetivo || indice == n) {
            return;
        }

        if (estaciones[indice].faltante > 0 && sumActual + estaciones[indice].faltante <= capacidadObjetivo) {
            actual[tamActual] = estaciones[indice].codigo;
            backtrack(
                estaciones,
                n,
                indice + 1,
                capacidadObjetivo,
                sumActual + estaciones[indice].faltante,
                actual,
                tamActual + 1,
                cantidadSoluciones
            );
        }

        backtrack(
            estaciones,
            n,
            indice + 1,
            capacidadObjetivo,
            sumActual,
            actual,
            tamActual,
            cantidadSoluciones
        );
    }
    

void SistemaBicicletas::redistribuirBicicletas(const EstacionFaltante* estaciones, int n, int capacidad) const {
    if (estaciones == nullptr || n <= 0 || capacidad <= 0) {
        std::cout << "No existen subconjuntos de estaciones cuyos faltantes sumen exactamente " << capacidad << endl;
        return;
    }

    std::string* actual = new std::string[n];
    int cantidadSoluciones = 0;

    std::cout << "Soluciones para C = " << capacidad << ":\n";
    backtrack(estaciones, n, 0, capacidad, 0, actual, 0, cantidadSoluciones);

    if (cantidadSoluciones == 0) {
        std::cout << "No existen subconjuntos de estaciones cuyos faltantes sumen exactamente " << capacidad << endl;
    }

    delete[] actual;
}
