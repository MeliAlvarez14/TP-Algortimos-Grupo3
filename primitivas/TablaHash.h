#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <string>

template <typename TClave, typename TValor>
class NodoHash {
    private:
        TClave clave;
        TValor valor;
        NodoHash<TClave, TValor>* siguiente;

    public:
        NodoHash(TClave c, TValor v) : clave(c), valor(v), siguiente(nullptr) {}

        TClave obtenerClave() const { 
            return clave; 
        }
        
        TValor& obtenerValor() { 
            return valor; 
        }
        
        const TValor& obtenerValor() const { 
            return valor; 
        }

        NodoHash<TClave, TValor>* obtenerSiguiente() const { 
            return siguiente; 
        }
        
        void cambiarSiguiente(NodoHash<TClave, TValor>* sig) { 
            siguiente = sig; 
        }
};

template <typename TClave, typename TValor>
class TablaHash {
    private:
        NodoHash<TClave, TValor>** tabla; 
        int capacidad;                  
        int cantidad;                   

    public:
        TablaHash(int capInicial = 101) {
            capacidad = capInicial;
            cantidad = 0;
            tabla = new NodoHash<TClave, TValor>*[capacidad];
            for (int i = 0; i < capacidad; i++) {
                tabla[i] = nullptr;
            }
        }

        unsigned int funcionHash(std::string clave) {
            unsigned int valorNumerico = 0;
            
            for (size_t i = 0; i < clave.length(); i++) {
                valorNumerico = (valorNumerico * 128) + clave[i];
            }
        return valorNumerico % capacidad;
        }

        ~TablaHash() {
            for (int i = 0; i < capacidad; i++) {
                NodoHash<TClave, TValor>* actual = tabla[i];
                while (actual != nullptr) {
                    NodoHash<TClave, TValor>* temp = actual;
                    actual = actual->obtenerSiguiente();
                    delete temp;
                }
            }
            delete[] tabla;
        }

        void insertarClave(TClave clave, TValor valor) {
            unsigned int indice = funcionHash(clave);
            NodoHash<TClave, TValor>* actual = tabla[indice];

            while (actual != nullptr) {
                if (actual->obtenerClave() == clave) {
                    actual->obtenerValor() = valor;
                    return;
                }
                actual = actual->obtenerSiguiente();
            }

            NodoHash<TClave, TValor>* nuevoNodo = new NodoHash<TClave, TValor>(clave, valor);
            nuevoNodo->cambiarSiguiente(tabla[indice]);
            tabla[indice] = nuevoNodo;
            cantidad++;
        }

        TValor* buscarClave(TClave clave) {
            unsigned int indice = funcionHash(clave);
            NodoHash<TClave, TValor>* actual = tabla[indice];

            while (actual != nullptr) {
                if (actual->obtenerClave() == clave) {
                    return &(actual->obtenerValor());
                }
                actual = actual->obtenerSiguiente();
            }

            return nullptr; 
        }

        void eliminarClave(TClave clave) {
            unsigned int indice = funcionHash(clave);
            NodoHash<TClave, TValor>* actual = tabla[indice];
            NodoHash<TClave, TValor>* anterior = nullptr;

            while (actual != nullptr) {
                if (actual->obtenerClave() == clave) {
                    if (anterior == nullptr) {
                        tabla[indice] = actual->obtenerSiguiente();
                    } else {
                        anterior->cambiarSiguiente(actual->obtenerSiguiente());
                    }
                    delete actual;
                    cantidad--;
                    return;
                }
                anterior = actual;
                actual = actual->obtenerSiguiente();
            }
        }

        int obtenerCantidad() {
            return cantidad;
        }

        bool estaVacia() {
            return cantidad == 0;
        }
};

#endif