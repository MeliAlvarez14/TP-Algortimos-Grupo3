#include "ABB.h"
#include "Bicicleta.h"
#include <iostream>
#include <algorithm>
using namespace std;


ABB::ABB() {
    raiz = nullptr;
}

void ABB::insertar(int clave, Bicicleta* bici){
    raiz = insertarRecursivo(raiz, clave, bici);
}

NodoArbol* ABB::insertarRecursivo(NodoArbol* nodo, int clave, Bicicleta* bici){
    if (nodo == nullptr) {
        return new NodoArbol(clave, bici);
    }
    if (clave < nodo->obtenerClave()) {
        nodo->cambiarIzquierdo(insertarRecursivo(nodo->obtenerIzquierdo(), clave, bici));
    } else if (clave > nodo->obtenerClave()) {
        nodo->cambiarDerecho(insertarRecursivo(nodo->obtenerDerecho(), clave, bici));
    }
    return nodo;
}

Bicicleta* ABB::buscar(int clave) {
    return buscarRecursivo(raiz, clave);
}

Bicicleta* ABB::buscarRecursivo(NodoArbol* nodo, int clave) {
    if (nodo == nullptr || nodo->obtenerClave() == clave) {
        return (nodo != nullptr) ? nodo->obtenerBicicleta() : nullptr;
    }
    if (clave < nodo->obtenerClave()) {
        return buscarRecursivo(nodo->obtenerIzquierdo(), clave);
    }
    return buscarRecursivo(nodo->obtenerDerecho(), clave);
}

void ABB::listarInOrder() {
    inOrderRecursivo(raiz);
}

void ABB::inOrderRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        inOrderRecursivo(nodo->obtenerIzquierdo()); // 1. Recorrer subarbol izquierdo
        cout << "Clave: " << nodo->obtenerClave() << ", Bicicleta: "; nodo->obtenerBicicleta()->mostrarDatos(); cout << endl; // 2. Procesar el nodo actual
        inOrderRecursivo(nodo->obtenerDerecho());   // 3. Recorrer subarbol derecho
    }
}

int ABB::contarAveriadas() {
    return contarAveriadasRecursivo(raiz);
}

int ABB::contarAveriadasRecursivo(NodoArbol* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int esAveriada = 0;
    if (nodo->obtenerBicicleta() != nullptr && nodo->obtenerBicicleta()->obtenerEstado() == "Averiada") {
        esAveriada = 1;
    }

    int averiadasIzq = contarAveriadasRecursivo(nodo->obtenerIzquierdo());

    int averiadasDer = contarAveriadasRecursivo(nodo->obtenerDerecho());

    return esAveriada + averiadasIzq + averiadasDer;
}

int ABB::obtenerAltura() {
    return calcularAlturaRecursivo(raiz);
}

int ABB::calcularAlturaRecursivo(NodoArbol* nodo) {
    if (nodo == nullptr) return -1;
    int altIzq = calcularAlturaRecursivo(nodo->obtenerIzquierdo());
    int altDer = calcularAlturaRecursivo(nodo->obtenerDerecho());
    return 1 + max(altIzq, altDer);
}

void ABB::liberarRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        liberarRecursivo(nodo->obtenerIzquierdo()); // 1. Liberar subarbol izquierdo
        liberarRecursivo(nodo->obtenerDerecho());   // 2. Liberar subarbol derecho
        delete nodo->obtenerBicicleta();            // Liberar la bicicleta asociada al nodo
        delete nodo;                               // 3. Borrar la raiz (Postorder)
    }
}

ABB::~ABB() {
    liberarRecursivo(raiz); // Destruccion del arbol al finalizar
}

// punto extra, eliminar una bicicleta del ABB:
void ABB::eliminar(int clave) {
    raiz = eliminarRecursivo(raiz, clave);
}

NodoArbol* ABB::obtenerMinimo(NodoArbol* nodo) {
    NodoArbol* actual = nodo;
    while (actual != nullptr && actual->obtenerIzquierdo() != nullptr) {
        actual = actual->obtenerIzquierdo();
    }
    return actual;
}

NodoArbol* ABB::eliminarRecursivo(NodoArbol* nodo, int clave) {
    if (nodo == nullptr) {
        return nullptr;
    }

    // 1. Buscamos el nodo
    if (clave < nodo->obtenerClave()) {
        nodo->cambiarIzquierdo(eliminarRecursivo(nodo->obtenerIzquierdo(), clave));
    } 
    else if (clave > nodo->obtenerClave()) {
        nodo->cambiarDerecho(eliminarRecursivo(nodo->obtenerDerecho(), clave));
    } 
    else {
        // Encontramos el nodo a eliminar. Evaluamos los 3 casos:

        // --- CASO 1: Nodo HOJA (sin hijos) ---
        if (nodo->obtenerIzquierdo() == nullptr && nodo->obtenerDerecho() == nullptr) {
            delete nodo;
            return nullptr; // Devuelve nullptr para actualizar la referencia en el padre
        }

        // --- CASO 2: Nodo con UN SOLO HIJO ---
        // Subcaso 2.1: Solo tiene hijo derecho
        else if (nodo->obtenerIzquierdo() == nullptr) {
            NodoArbol* temp = nodo->obtenerDerecho(); // Guardamos el subarbol derecho
            delete nodo; // Liberamos el nodo actual
            return temp; // El hijo derecho toma el lugar del nodo borrado
        }
        // Subcaso 2.2: Solo tiene hijo izquierdo
        else if (nodo->obtenerDerecho() == nullptr) {
            NodoArbol* temp = nodo->obtenerIzquierdo(); // Guardamos el subarbol izquierdo
            delete nodo; // Liberamos el nodo actual
            return temp; // El hijo izquierdo toma el lugar del nodo borrado
        }

        // --- CASO 3: Nodo con DOS HIJOS ---
        else {
            NodoArbol* sucesor = obtenerMinimo(nodo->obtenerDerecho());

            // Borramos el sucesor de su posición original
            NodoArbol* nuevoDerecho = eliminarRecursivo(nodo->obtenerDerecho(), sucesor->obtenerClave());

            // Le asignamos al sucesor los hijos del nodo que vamos a borrar
            sucesor->cambiarIzquierdo(nodo->obtenerIzquierdo());
            sucesor->cambiarDerecho(nuevoDerecho);

            delete nodo;
            return sucesor;
        }
    }
    return nodo;
}

//Módulo B.3
void ABB::listarConMasDeKm(int minKm) { //método publico que usa el recursivo privado
    listarConMasDeKmRecursivo(this->raiz, minKm);
}

void ABB::listarConMasDeKmRecursivo(NodoArbol* nodo, int minKm) {
    if (nodo != nullptr) {
        //recorrer subárbol izquierdo
        listarConMasDeKmRecursivo(nodo->obtenerIzquierdo(), minKm);

        //procesar nodo actual
        Bicicleta* bici = nodo->obtenerBicicleta();
        if (bici != nullptr && bici->obtenerKilometros() > minKm) {
            bici->mostrarDatos();
        }

        //recorrer subárbol derecho
        listarConMasDeKmRecursivo(nodo->obtenerDerecho(), minKm);
    }
}