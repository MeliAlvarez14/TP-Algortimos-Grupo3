#include <iostream>
#include <string>
#include "SistemaBicicletas.h"

using namespace std;

void mostrarMenuBicicletas(SistemaBicicletas& sistema) {
    int opcion;
    do {
        cout << "\n=== MODULO C: REGISTRO DE BICICLETAS (ABB) ===" << endl;
        cout << "1. Insertar nueva bicicleta" << endl;
        cout << "2. Buscar bicicleta por ID" << endl;
        cout << "3. Listar todas las bicicletas (InOrder)" << endl;
        cout << "4. Contar bicicletas averiadas" << endl;
        cout << "5. Mostrar altura del arbol" << endl;
        cout << "6. Eliminar bicicleta por ID" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int id, km;
                string estacion, tipo, estado;
                cout << "ID de bicicleta: ";
                cin >> id;
                cout << "Codigo de estacion (ej. PLZ): ";
                cin >> estacion;
                cout << "Tipo (Mecanica / Electrica): ";
                cin >> tipo;
                cout << "Estado (OK / Averiada): ";
                cin >> estado;
                cout << "Kilometros iniciales: ";
                cin >> km;
                sistema.registrarBicicleta(id, estacion, tipo, estado, km);
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese el ID de la bicicleta a buscar: ";
                cin >> id;
                sistema.buscarYMostrarBicicleta(id);
                break;
            }
            case 3:
                sistema.listarBicicletasInOrder();
                break;
            case 4:
                sistema.mostrarCantidadAveriadas();
                break;
            case 5:
                sistema.mostrarAlturaArbol();
                break;
            case 6: {
                int id;
                cout << "Ingrese el ID de la bicicleta a eliminar: ";
                cin >> id;
                sistema.eliminarBicicletaDelArbol(id);
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
}

int main() {
    SistemaBicicletas sistema;
    sistema.inicializarSistema();

    int opcionPrincipal;
    do {
        cout << "\n=============================================" << endl;
        cout << "   SISTEMA DE BICICLETAS PUBLICAS - UNAHUR" << endl;
        cout << "=============================================" << endl;
        cout << "1. Gestion de Estaciones (Modulo A)" << endl;
        cout << "2. Viajes y Colas de Espera (Modulo B)" << endl;
        cout << "3. Registro de Bicicletas (Modulo C)" << endl;
        cout << "4. Redistribucion de Bicicletas (Modulo D)" << endl;
        cout << "0. Salir y liberar memoria" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1:
                cout << "[Pendiente de integracion - Modulo A]" << endl;
                break;
            case 2:
                cout << "[Pendiente de integracion - Modulo B]" << endl;
                break;
            case 3:
                mostrarMenuBicicletas(sistema);
                break;
            case 4:
                cout << "[Pendiente de integracion - Modulo D]" << endl;
                break;
            case 0:
                cout << "Cerrando sistema y liberando memoria..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcionPrincipal != 0);

    return 0; // Al salir del main se llama automaticamente a ~SistemaBicicletas() -> ~ABB()
}