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

void mostrarMenuViajes(SistemaBicicletas& sistema) {
    int opcion;
    do {
        cout << "\n=== MODULO B: VIAJES Y COLAS DE ESPERA ===" << endl;
        cout << "1. Calcular viajes de una estacion en rango de fechas" << endl;
        cout << "2. Buscar viajes y minutos de un usuario por DNI" << endl;
        cout << "3. Listar bicicletas con mas de X kilometros" << endl;
        cout << "4. Retirar bicicleta de una estacion (o entrar en espera)" << endl;
        cout << "5. Devolver bicicleta a una estacion" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string estacion;
                int fechaDesde, fechaHasta;
                cout << "Codigo de estacion (ej. PLZ): ";
                cin >> estacion;
                cout << "Fecha desde (AAAAMMDD): ";
                cin >> fechaDesde;
                cout << "Fecha hasta (AAAAMMDD): ";
                cin >> fechaHasta;
                sistema.calcularViajesEstacionRango(estacion, fechaDesde, fechaHasta);
                break;
            }
            case 2: {
                string dni;
                cout << "Ingrese el DNI del usuario: ";
                cin >> dni;
                sistema.buscarViajesUsuario(dni);
                break;
            }
            case 3: {
                int minKm;
                cout << "Ingrese el kilometraje minimo (X): ";
                cin >> minKm;
                sistema.listarBicicletasConMasDeKm(minKm);
                break;
            }
            case 4: {
                string dni, estacion;
                cout << "DNI del usuario: ";
                cin >> dni;
                cout << "Codigo de estacion: ";
                cin >> estacion;
                sistema.retirarBicicleta(dni, estacion);
                break;
            }
            case 5: {
                int idBici;
                string estacion;
                cout << "ID de la bicicleta a devolver: ";
                cin >> idBici;
                cout << "Codigo de estacion de destino: ";
                cin >> estacion;
                
                // Buscamos la bici en el arbol para pasarla por referencia/puntero
                Bicicleta* bici = sistema.bucarBicicletaPorId(idBici);
                if (bici != nullptr) {
                    sistema.devolverBicicleta(bici, estacion);
                } else {
                    cout << "Error: No se encontro la bicicleta con ID " << idBici << endl;
                }
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
                mostrarMenuViajes(sistema);
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