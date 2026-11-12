#include "SistemaBicicletas.h"
#include <iostream>
#include <fstream>

using namespace std;

SistemaBicicletas::SistemaBicicletas() {
    // Los constructores de ABB y demás estructuras se ejecutan automáticamente
}

void SistemaBicicletas::inicializarSistema() {
    // cargarEstaciones("estaciones.txt");
    cargarBicicletas("bicicletas.txt");
    // cargarViajes("viajes.txt");
    // cargarCiclovias("ciclovias.txt");
}

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
        arbolBicicletas.insertar(id, nuevaBici);

        // CONEXIÓN CON MÓDULO B.5 (Taller / Min-Heap):
        // if (estado == "Averiada") {
        //     int prioridad = (tipo == "Electrica") ? 1 : 2; // o la que corresponda
        //     tallerReparaciones.insertar(nuevaBici, prioridad);
        // }
    }

    archivo.close();
    cout << "Bicicletas cargadas correctamente desde " << rutaArchivo << "." << endl;
}

void SistemaBicicletas::registrarBicicleta(int id, string estacion, string tipo, string estado, int km) {
    if (arbolBicicletas.buscar(id) != nullptr) {
        cout << "Error: Ya existe una bicicleta con el ID " << id << "." << endl;
        return;
    }

    Bicicleta* nueva = new Bicicleta(id, estacion, tipo, estado, km);
    arbolBicicletas.insertar(id, nueva);
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

    arbolBicicletas.eliminar(id);
    delete bici; // Liberamos la instancia si ya no se va a usar en ningún otro lado
    cout << "Bicicleta " << id << " eliminada del sistema." << endl;
}

void SistemaBicicletas::listarBicicletasConMasDeKm(int minKm) {
    cout << "\n--- Bicicletas con mas de " << minKm << " km (Para revision) ---" << endl;
    // Tip: Agregar en ABB un método público listarConMasDeKm(int minKm)
    // que recorra recursivamente e imprima si nodo->obtenerBicicleta()->obtenerKilometros() > minKm
    // arbolBicicletas.listarConMasDeKm(minKm);
}