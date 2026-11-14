#ifndef GRAFO_HASH_H
#define GRAFO_HASH_H

#include "Vertice.h"
#include "TablaHash.h" 
#include "Cola.h" 
#include <iostream>
using namespace std;

template <typename T, typename S>
class Grafo {

private:
    TablaHash<T, Vertice<S, T>> tablaVertices;
    int cantidadVertices;

public:
    Grafo(int capacidadInicial) 
        : tablaVertices(capacidadInicial), cantidadVertices(0) {}

    void agregarVertice(T codigo, S datoVertice) {
        if (tablaVertices.buscarClave(codigo) != nullptr) {
            return;
        }

        Vertice<S, T> nuevoVertice(datoVertice);
        tablaVertices.insertarClave(codigo, nuevoVertice);
        cantidadVertices++;
    }

    void agregarArista(T origen, T destino) {
        Vertice<S, T>* vOrigen = tablaVertices.buscarClave(origen);
        Vertice<S, T>* vDestino = tablaVertices.buscarClave(destino); 

        if (vOrigen != nullptr && vDestino != nullptr) {
            vOrigen->agregarArista(destino);
            vDestino->agregarArista(origen); 
        }
    }

    Vertice<S, T>* obtenerVertice(string clave) {
        return tablaVertices.buscarClave(clave);
    }

    int obtenerCantidadVertices() const {
        return cantidadVertices;
    }

    void eliminarVertice(string claveVertice){
        Vertice<S, T>* verticeAEliminar = tablaVertices.buscarClave(claveVertice);

        if(verticeAEliminar == nullptr){
            return;
        }

        Nodo<T>* actual = verticeAEliminar->obtenerPrimero();
        while(actual != nullptr){
            Vertice<S, T>* verticeVecino = tablaVertices.buscarClave(actual->obtenerDato());
            verticeVecino->eliminarArista(claveVertice);
            actual = actual->obtenerSiguiente();
        }

        tablaVertices.eliminarClave(claveVertice);
        cantidadVertices--;
    }

    void bfs(T origen, T destino) {
        Vertice<S, T>* vOrigen = tablaVertices.buscarClave(origen);
        Vertice<S, T>* vDestino = tablaVertices.buscarClave(destino);

        if (vOrigen == nullptr || vDestino == nullptr) {
            return; 
        }

        Cola cola;
        TablaHash<T, T> predecesores(101);    
        TablaHash<T, bool> visitados(101);    

        cola.encolar(origen);
        visitados.insertarClave(origen, true); 

        bool encontrado = false;

        while (!cola.vacia()) {
            T actualClave = cola.desencolar();
            if (actualClave == destino) {
                encontrado = true;
                break;
            }

            Vertice<S, T>* vActual = tablaVertices.buscarClave(actualClave);
            if (vActual != nullptr) {
                Nodo<T>* vecinoNodo = vActual->obtenerPrimero();
                
                while (vecinoNodo != nullptr) {
                    T vecinoClave = vecinoNodo->obtenerDato();
                    bool* yaVisitado = visitados.buscarClave(vecinoClave);

                    if (yaVisitado == nullptr) {
                        visitados.insertarClave(vecinoClave, true);
                        predecesores.insertarClave(vecinoClave, actualClave);
                        cola.encolar(vecinoClave);
                    }
                    vecinoNodo = vecinoNodo->obtenerSiguiente();
                }
            }
        }

        if (encontrado) {
            Nodo<T>* pilaCamino = nullptr; 
            T actual = destino;
            
            while (actual != origen) {
                Nodo<T>* nuevoNodo = new Nodo<T>(actual);
                nuevoNodo->cambiarSiguiente(pilaCamino);
                pilaCamino = nuevoNodo;

                T* predecesor = predecesores.buscarClave(actual);
                if (predecesor == nullptr) {
                    break; 
                }
                actual = *predecesor;
            }
            
            Nodo<T>* nodoOrigen = new Nodo<T>(origen);
            nodoOrigen->cambiarSiguiente(pilaCamino);
            pilaCamino = nodoOrigen;

            Nodo<T>* actualNodo = pilaCamino;
            while (actualNodo != nullptr) {
                cout << actualNodo->obtenerDato();
                if (actualNodo->obtenerSiguiente() != nullptr) {
                    cout << " -> ";
                }
                actualNodo = actualNodo->obtenerSiguiente();
            }

            while (pilaCamino != nullptr) {
                Nodo<T>* temp = pilaCamino;
                pilaCamino = pilaCamino->obtenerSiguiente();
                delete temp;
            }

        } else {
            cout << "No existe recorrido posible entre " << origen << " y " << destino << "." << endl;
        }
    }
};

#endif