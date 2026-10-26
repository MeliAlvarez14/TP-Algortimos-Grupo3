#ifndef GRAFO_HASH_H
#define GRAFO_HASH_H

#include "Vertice.h"
#include "TablaHash.h" 
#include "Cola.h" 

template <typename T, typename S>
class Grafo {

private:
    TablaHash<T, Vertice<T, S>> tablaVertices;
    int cantidadVertices;

public:
    Grafo(int capacidadInicial = 101) 
        : tablaVertices(capacidadInicial), cantidadVertices(0) {}

    void agregarVertice(T codigo, T datoVertice) {
        if (tablaVertices.buscarClave(codigo) != nullptr) {
            return;
        }

        Vertice<T, S> nuevoVertice(datoVertice);
        tablaVertices.insertarClave(codigo, nuevoVertice);
        cantidadVertices++;
    }

    void agregarArista(T origen, S destino) {
        Vertice<T, S>* vOrigen = tablaVertices.buscarClave(origen);
        Vertice<T, S>* vDestino = tablaVertices.buscarClave(destino); 

        if (vOrigen != nullptr && vDestino != nullptr) {
            vOrigen->agregarArista(destino);
            vDestino->agregarArista(origen); 
        }
    }

    Vertice<T, S>* obtenerVertice(T clave) {
        return tablaVertices.buscarClave(clave);
    }

    int obtenerCantidadVertices() const {
        return cantidadVertices;
    }

    void eliminarVertice(T claveVertice){
        Vertice<T, S>* verticeAEliminar = tablaVertices.buscarClave(claveVertice);

        if(verticeAEliminar == nullptr){
            return;
        }

        Nodo<S>* actual = verticeAEliminar.obtenerPrimero();
        while(actual != nullptr){
            Vertice<T, S>* verticeVecino = tablaVertices.buscarClave(actual->obtenerDato());
            verticeVecino->eliminarArista(claveVertice);
            actual = actual->obtenerSiguiente();
        }

        tablaVertices.eliminarClave(claveVertice);
        cantidadVertices--;
    }

    void bfs(T origen, T destino) {
        Vertice<T, S>* vOrigen = tablaVertices.buscarClave(origen);
        Vertice<T, S>* vDestino = tablaVertices.buscarClave(destino);

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

            Vertice<T, S>* vActual = tablaVertices.buscarClave(actualClave);
            if (vActual != nullptr) {
                Nodo<S>* vecinoNodo = vActual->obtenerPrimero();
                
                while (vecinoNodo != nullptr) {
                    S vecinoClave = vecinoNodo->obtenerDato();
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
            T actual = destino;
        
            while (actual != origen) {
                std::cout << actual << " <- "; 

                T* predecesor = predecesores.buscarClave(actual);
                if (predecesor == nullptr) {
                    break; 
                }
                actual = *predecesor;
            }

            std::cout << origen << std::endl;
            }
    }
};

#endif