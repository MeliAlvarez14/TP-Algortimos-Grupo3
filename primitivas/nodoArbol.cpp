#include "NodoArbol.h"
#include "Bicicleta.h"

NodoArbol::NodoArbol(int claveNodo, Bicicleta* bici){
    clave = claveNodo;
    bicicleta = bici;
    izquierdo = nullptr;
    derecho = nullptr;
}

int NodoArbol::obtenerClave(){ 
    return clave; 
}

Bicicleta* NodoArbol::obtenerBicicleta(){ 
    return bicicleta; 
}

NodoArbol* NodoArbol::obtenerIzquierdo(){ 
    return izquierdo; 
}

NodoArbol* NodoArbol::obtenerDerecho(){ 
    return derecho; 
}

void NodoArbol::cambiarIzquierdo(NodoArbol* izq){ 
    izquierdo = izq; 
}

void NodoArbol::cambiarDerecho(NodoArbol* der){ 
    derecho = der; 
}
