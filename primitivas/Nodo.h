#ifndef NODO_H
#define NODO_H
template <typename T>

class Nodo {

    private:
        T dato;
        Nodo<T>* siguiente;

    public:
        Nodo(T d) {
            dato = d;
            siguiente = nullptr;
        };

        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {
            siguiente = nuevoSiguiente;
        };

        void cambiarDato(T d) {
            dato = d;
        };

        T obtenerDato() {
            return dato;
        };

        Nodo<T>* obtenerSiguiente() {
            return siguiente;
        };
};

#endif