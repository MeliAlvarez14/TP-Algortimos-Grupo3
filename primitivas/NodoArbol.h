#ifndef NODO_ARBOL_H_INCLUDED
#define NODO_ARBOL_H_INCLUDED

class Bicicleta;

class NodoArbol {
private:
    int clave;
    Bicicleta* bicicleta;
    NodoArbol* izquierdo;
    NodoArbol* derecho;

public:
    NodoArbol(int clave, Bicicleta* bici);

    int obtenerClave();
    Bicicleta* obtenerBicicleta();
    NodoArbol* obtenerIzquierdo();
    NodoArbol* obtenerDerecho();

    void cambiarIzquierdo(NodoArbol* izq);
    void cambiarDerecho(NodoArbol* der);
};

#endif