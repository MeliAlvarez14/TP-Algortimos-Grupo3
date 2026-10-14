#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include "NodoArbol.h"

class ABB {
private:
    NodoArbol* raiz; // Puntero a la raiz del AB

    NodoArbol* insertarRecursivo(NodoArbol* nodo, int clave, Bicicleta* bici);
    NodoArbol* eliminarRecursivo(NodoArbol* nodo, int clave);
    NodoArbol* obtenerMinimo(NodoArbol* nodo);
    Bicicleta* buscarRecursivo(NodoArbol* nodo, int clave);
    void inOrderRecursivo(NodoArbol* nodo);
    void liberarRecursivo(NodoArbol* nodo); // Recorrido postorder para destruir nodos
    int contarAveriadasRecursivo(NodoArbol* nodo);
    int calcularAlturaRecursivo(NodoArbol* nodo);

public:
    ABB();
    ~ABB(); // Libera la memoria con recorrido postorder

    void insertar(int clave, Bicicleta* bici);
    Bicicleta* buscar(int clave);
    void listarInOrder();
    int contarAveriadas();
    int obtenerAltura();
    void eliminar(int clave);
    
};

#endif